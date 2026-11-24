import json, os, runpy, sys
from pathlib import Path
k=Path(sys.argv.pop(1))
sys.path[:0]=[str(k/"tools"),str(k)]
name=sys.argv.pop(1)
sys.argv[0]=str(k/"tools"/(name+".py"))
if name=="level2_inlinebudget":
    import level2_flipsweep as fs
    fs.VC6=str(k/"vc6")
    meta=k/"meta"
    funcs=json.loads((meta/"level2_functions.json").read_text(encoding="utf-8"))
    syms=json.loads((meta/"level2_symbols.json").read_text(encoding="utf-8"))
    fs._symmap={key:int(v["address"],16) for key,v in syms.items() if isinstance(v,dict) and v.get("address")}
    for v in funcs:
        if v.get("symbol") and v.get("rva"):
            fs._symmap.setdefault(v["symbol"],fs.BASE+int(v["rva"],16))
    starts={int(v["rva"],16) for v in funcs if v.get("rva")}
    starts.update(int(v["rva"],16) for v in json.loads((meta/"function_map.json").read_text())["map"])
    fs._starts=sorted(starts)
    sys.argv.extend(["--inc",str(k/"m85/src"),"--inc",str(k/"m85/include")])
runpy.run_path(sys.argv[0], run_name="__main__")
