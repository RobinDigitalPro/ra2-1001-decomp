"""Recreate all five DSurface varsearch JSON specs from the fresh batch input."""
import argparse
import json
import os
from pathlib import Path

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('source', type=Path)
parser.add_argument('output', type=Path)
args = parser.parse_args()
output = args.output
output.mkdir(parents=True, exist_ok=True)
source = args.source.read_bytes().decode('latin1').replace('\r\n', '\n')
relative_base = Path(os.path.relpath(args.source.resolve(), output.resolve())).as_posix()
body = source[source.index("bool DSurface::Draw_Depth_Antialiased_Line"):source.index("bool DSurface::Draw_RGB_Multiplying_Line")]
sections = body.split("int cov = *abuffer;")
choices = []
for i in range(4):
    # Include the prefix starting at the last unique line and ending at the current do loop.
    prior = sections[i]
    lines = prior.splitlines(keepends=True)
    for j in range(2, len(lines)):
        anchor = "".join(lines[-j:]).strip()
        if source.count(anchor) == 1:
            break
    indentation = "\t" * 5
    old = "int cov = *abuffer;\n" + indentation + "if (z < *zbuffer) {"
    point = {"name": "coverage_loop_" + str(i + 1), "options": [{"label": "int before depth", "edits": []}]}
    for label, new in [
        ("narrow before depth", old.replace("int cov", "unsigned short cov")),
        ("int after depth", "if (z < *zbuffer) {\n" + indentation + "\tint cov = *abuffer;"),
        ("narrow after depth", "if (z < *zbuffer) {\n" + indentation + "\tunsigned short cov = *abuffer;"),
    ]:
        point["options"].append({"label": label, "edits": [[old, new, anchor]]})
    choices.append(point)
def save(name):
    spec = dict(base=relative_base, preset="m85", targets=[["Draw_Depth_Antialiased_Line@DSurface","0xac360"]], controls=[[name + "@DSurface", rva] for name, rva in [("Draw_Depth_Glow_Line","0xab8b0"), ("Draw_RGB_Multiplying_Line","0xadb10"), ("GetDC","0xaa900"), ("ReleaseDC","0xaa940")]], choices=choices)
    (output / (name + ".json")).write_text(json.dumps(spec, indent=2), encoding="utf-8")
save("surface28_cov")
for name in ["line", "neighbor"]:
    old = f"RGBClass {name} = Deconstruct_Hicolor_Pixel"
    options = [{"label":"value","edits":[]}]
    anchors = [p["options"][1]["edits"][0][2] for p in choices[:4]]
    for label, indexes in [("first two by const reference",[0,1]), ("last two by const reference",[2,3]), ("all by const reference",range(4))]:
        options.append({"label":label,"edits":[[old, old.replace("RGBClass ", "RGBClass const & "), anchors[i]] for i in indexes]})
    choices.append({"name":name+"_lifetime","options":options})
save("surface28_extended")


spec = json.loads((output/'surface28_cov.json').read_text(encoding='utf-8'))
for choice in spec['choices']:
    choice['options'] = [choice['options'][0], choice['options'][2]]
(output/'surface28_depth_grid.json').write_text(json.dumps(spec, indent=2), encoding='utf-8')
spec['choices']=[spec['choices'][1],spec['choices'][3]]
start='bool DSurface::Draw_Depth_Antialiased_Line'
depth='\tif (DepthBuffer == NULL) {\n\t\tUnlock();\n\t\treturn(false);\n\t}'
buffer='\tif (buffer != NULL) { // level-2 1.001: the failure path shares the final Unlock'
end='\tUnlock();\n\treturn(true);\n\n\t}\n\n\tUnlock();\n\treturn(false);\n\n\t}\n\n\treturn(false);\n}'
positive='\tif (DepthBuffer != NULL) {'
early='\tif (buffer == NULL) {\n\t\tUnlock();\n\t\treturn(false);\n\t}'
def option(label, changes):
    return {'label':label,'edits':[[a,b,start] for a,b in changes]}
spec['choices'].append({'name':'guard scopes','options':[
    option('baseline',[]),
    option('depth encloses buffer',[(depth,positive),(end,end.replace('\n\n\tUnlock();\n\treturn(false);','\n\t}\n\n\tUnlock();\n\treturn(false);',1))]),
    option('early null buffer',[(buffer,early),(end,'\tUnlock();\n\treturn(true);\n\n\t}\n\n\treturn(false);\n}')]),
    option('positive depth and early null buffer',[(depth,positive),(buffer,early)])]})
for label,old,new in [('raster extent','dx == 0 && abs_dy == 0','(dx | abs_dy) == 0'),('clip extent','clip.Width == 0 && clip.Height == 0','(clip.Width | clip.Height) == 0')]:
    spec['choices'].append({'name':label,'options':[option('separate',[]),option('combined',[(old,new)])]})

for filename in ['surface28_flow_grid.json', 'surface28_flow_bytes.json']:
    (output/filename).write_text(json.dumps(spec, indent=2), encoding='utf-8')
