"""Generate two reproducible Foot search specs against its supplied translation unit."""
import argparse
import json
from pathlib import Path

arg = argparse.ArgumentParser()
arg.add_argument("base", type=Path)
arg.add_argument("destination", type=Path)
args = arg.parse_args()
text = args.base.read_bytes().decode("latin1").replace("\r\n", "\n")
declaration = "Cell FootClass::Search_For_Tiberium_Weighted(int rad)"
start = text.rindex("/// <summary>", 0, text.index(declaration))
end = text.index("\n}", text.index(declaration)) + 2
definition = text[start:end]
fallback = "\tCellClass *cellptr = celldist.Sample();\n\tif (cellptr != NULL) {\n\t\treturn(cellptr->Fetch_CellID());\n\t}\n\treturn(CELL_NONE);"
assert fallback in definition
def options(name, variants):
    return {"name": name, "options": [{"label": "input", "edits": []}] + [
        {"label": label, "edits": edits} for label, edits in variants]}
def comment_anchor(label, signature):
    at = text.index(signature)
    begin = max(text.rfind("/// <summary>", 0, at), text.rfind("/*********", 0, at))
    # Decorative comment lines can begin with many stars. Anchor through the signature.
    return label, [[definition, ""], [text[begin:at+len(signature)], definition + "\n\n\n" + text[begin:at+len(signature)]]]
order = options("definition position", [
    comment_anchor("before plain search", "Cell FootClass::Search_For_Tiberium(int rad, bool allow_weighted)"),
    comment_anchor("before weed check", "bool FootClass::Weed_Check(Cell & center, int x, int y)"),
    comment_anchor("before Goto_Tiberium", "bool FootClass::Goto_Tiberium(int rad, bool allow_weighted)"),
])
scope = options("sample pointer lifetime", [
    ("condition scope", [[fallback, fallback.replace("CellClass *cellptr = celldist.Sample();\n\tif (cellptr != NULL)", "if (CellClass *cellptr = celldist.Sample())"), declaration]]),
    ("declare before rings", [["\tfor (int radius", "\tCellClass *cellptr;\n\tfor (int radius", declaration], ["\tCellClass *cellptr = celldist.Sample();", "\tcellptr = celldist.Sample();", declaration]]),
])
center = "Cell center = Center_Coord().As_Cell();"
aggregate = options("center conversion", [
    ("Coord converting constructor", [[center, "Cell center(Center_Coord());", declaration]]),
    ("assign after default construction", [[center, "Cell center;\n\tcenter = Center_Coord().As_Cell();", declaration]]),
])
spec = {"base": "foot.cpp", "preset":"m85",
    "targets":[["Search_For_Tiberium_Weighted","0xcb740"]],
    "controls":[["?Search_For_Tiberium@FootClass@@QAE?AVCell@@H_N@Z","0xcb4f0"],
                ["?Search_For_Weed@FootClass@@QAE?AVCell@@H@Z","0xcbd00"],
                ["?Weed_Check@FootClass@@QAE_NAAVCell@@HH@Z","0xcbe60"],
                ["?Goto_Weed@FootClass@@QAE_NH@Z","0xcc000"]],
    "choices":[order,scope,aggregate]}
def save(name):
    (args.destination / name).write_text(json.dumps(spec, indent=2) + "\n", encoding="utf-8")
save("foot28_a.json")
def helper(option, body, call):
    helper = "// level-2 1.001: INFERRED selected cell or the empty search result.\n" + body + "\n\n"
    return option, [[declaration, helper + declaration],
                    [fallback, "\treturn(" + call + ");", declaration]]
scope["options"].extend(options("sample and return", [
    helper("sampled pointer argument",
           "static inline Cell Selected_Tiberium_Cell(CellClass *sample)\n{\n\tif (sample) return(sample->Fetch_CellID());\n\treturn(CELL_NONE);\n}",
           "Selected_Tiberium_Cell(celldist.Sample())"),
    helper("distribution reference argument",
           "static inline Cell Selected_Tiberium_Cell(DiscreteDistributionClass<CellClass> &distribution)\n{\n\tCellClass *sample = distribution.Sample();\n\tif (sample) return(sample->Fetch_CellID());\n\treturn(CELL_NONE);\n}",
           "Selected_Tiberium_Cell(celldist)"),
])["options"][1:])
def compose(side):
    coordinate = "Cell(" + side + ")"
    old = "cell = " + coordinate + " + center;"
    return [old, "cell = " + coordinate + ";\n\t\t\tcell = cell + center;", declaration]
spec["choices"].append(options("ring-cell aggregate lifetime", [
    ("east temporary assigned before offset", [compose("+radius, x")]),
    ("all edge temporaries assigned before offset", [compose(side) for side in
        ("x, -radius", "x, +radius", "-radius, x", "+radius, x")]),
]))
save("foot28_b.json")

