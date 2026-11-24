"""Compile isolated batch sources and audit all registered claims and target RVAs."""
import argparse
import json
import os
from pathlib import Path
import subprocess
import sys

parser = argparse.ArgumentParser(description=__doc__)
for key in ("kit", "context", "source", "out"):
    parser.add_argument(key, type=lambda p: Path(p).resolve())
a = parser.parse_args()
a.out.mkdir(parents=True, exist_ok=True)
vc = a.kit / "vc6"
env = dict(os.environ)
env.update(PATH=os.pathsep.join([str(vc / "VC98/BIN"), str(vc / "COMMON/MSDEV98/BIN"), env["PATH"]]),
           INCLUDE=os.pathsep.join(str(vc / x) for x in ("VC98/INCLUDE", "VC98/ATL/INCLUDE")),
           LIB=str(vc / "VC98/LIB"))
obj_path = a.out / (a.source.stem + ".obj")
cmd = [str(vc / "VC98/BIN/CL.EXE"), "-nologo", "-c", "-O2", "-Ob2", "-Gr",
       "-GR", "-DNDEBUG", "-Gy", "-DWIN32", "-W0", "-I" + str(a.context / "src"),
       "-I" + str(a.context / "include"), "-Fo" + str(obj_path), str(a.source)]
subprocess.run(cmd, env=env, cwd=a.out, check=True, timeout=90)
sys.path[:0] = [str(a.kit / "tools"), str(a.kit)]
import l2match
from coffmatch import Obj, match_function

claims = json.loads((a.kit / "meta/level2_functions.json").read_bytes())
symbols = json.loads((a.kit / "meta/level2_symbols.json").read_bytes())
bound = {name: int(row["address"], 0) for name, row in symbols.items() if row.get("address")}
for row in claims:
    if row.get("symbol"):
        bound.setdefault(row["symbol"], 0x400000 + int(row["rva"], 0))
rows = {int(row["rva"], 0): row["symbol"] for row in claims
        if row.get("symbol") and Path(row["tu"]).name.lower() == a.source.name.lower()}
targets = {
    "queue": [(0x221b90,"?Print_CRCs@")],
    "startup": [(0x283970,"_WinMain@16")],
    "ownrdraw": [(0x1f30a0,"?Trackbar_Proc@")],
    "map": [(0x14c060,"?Zone_Reset@MapClass")],
    "bullet": [(0x5f380,"?AI@BulletClass")],
    "isotype": [(0x12a490,"?Draw_Tile@")],
}
obj = Obj(obj_path.read_bytes())
for rva, needle in targets[a.source.stem]:
    if rva not in rows:
        names = [name for name in obj.symbols if needle in name]
        if len(names) != 1:
            raise ValueError((needle,names))
        rows[rva] = names[0]
results = {}
for addr, name in sorted(rows.items()):
    if name not in obj.symbols:
        results[hex(addr)] = {"status": "missing", "symbol": name}
        continue
    size = len(obj.function(name)["raw"])
    results[hex(addr)] = match_function(obj, name, l2match.orig(addr, size), 0x400000 + addr, bound.get)
(a.out / (a.source.stem + ".json")).write_text(json.dumps(results, indent=2))
for rva, needle in targets[a.source.stem]:
    t = results[hex(rva)]
    print(hex(rva), needle, t.get("status"), t.get("byte_differences"), "audited",len(rows))

