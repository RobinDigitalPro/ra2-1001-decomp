"""Probe all selected natural source combinations, measuring true constructor sites, frame and raw match as independent metrics.
Run python -IB walk28_matrix.py KIT SPEC BUILD_DIR CSV [--workers N]. Use the input TU next to SPEC.
"""
import argparse
import concurrent.futures
import csv
import hashlib
import itertools
import json
import os
from pathlib import Path
import subprocess
import sys

parser = argparse.ArgumentParser(description=__doc__)
for name in ("kit","spec","work","csv"):
    parser.add_argument(name, type=Path)
parser.add_argument("--workers", type=int, default=3)
args = parser.parse_args()
args.work.mkdir(parents=True,exist_ok=True)
kit = args.kit.resolve()
sys.path[:0] = [str(kit), str(kit / "tools")]
import capstone
import l2match
from coffmatch import Obj
spec = json.loads(args.spec.read_text())
source = (args.spec.parent / spec["base"]).read_bytes().decode("latin-1").replace("\r\n","\n")
vc = kit / "vc6"
env = dict(os.environ)
env.update(PATH=os.pathsep.join([str(vc/"VC98/BIN"),str(vc/"COMMON/MSDEV98/BIN"),env["PATH"]]),
           INCLUDE=os.pathsep.join([str(vc/"VC98/INCLUDE"),str(vc/"VC98/ATL/INCLUDE")]),LIB=str(vc/"VC98/LIB"))
compiler = [str(vc/"VC98/BIN/CL.EXE"),"-nologo","-c","-O2","-Ob2","-Gr","-GR","-DNDEBUG","-Gy","-DWIN32","-W0","-I"+str(kit/"m85/src"),"-I"+str(kit/"m85/include")]
def evaluate(combo):
    text = source
    for choice, index in zip(spec["choices"],combo):
        for old,new in choice["options"][index]["edits"]:
            if text.count(old)!=1:
                raise ValueError(choice["name"])
            text=text.replace(old,new)
    digest=hashlib.sha256(text.encode("latin-1")).hexdigest()[:20]
    src=args.work/(digest+".cpp")
    obj=src.with_suffix(".obj")
    src.write_bytes(text.replace("\n","\r\n").encode("latin-1"))
    try:
        run=subprocess.run(compiler+["-Fo"+str(obj),str(src)],env=env,cwd=args.work,capture_output=True,timeout=120)
        if run.returncode:
            return [str(combo),digest,run.stdout.decode("latin-1")[-400:],"","","","","","",""]
        o=Obj(obj.read_bytes())
        name,=[n for n in o.symbols if "Movement_AI@Walk" in n]
        f=o.function(name)
        ctors=[hex(off-1) for off,idx,ty in f["relocs"] if ty==0x14 and "??0?$TPoint3D@H" in o.by_index[idx]["name"]]
        cs=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
        ins=list(cs.disasm(f["raw"],0))
        speed=sum(i.mnemonic=="call" and "+ 0x4c8]" in i.op_str for i in ins)
        frame=f"{ins[0].mnemonic} {ins[0].op_str}"
        match=l2match.run(obj,name,0x312de0,{})
        controls=all(l2match.run(obj,k,int(rva,16),{})["status"] in ("matched","bytes_match_bindings_open") for k,rva in spec["controls"])
        return [str(combo),digest,"",match["byte_differences"],len(f["raw"]),frame,len(ctors)," ".join(ctors),speed,controls]
    finally:
        src.unlink(missing_ok=True)
        obj.unlink(missing_ok=True)
combos=itertools.product(*(range(len(c["options"])) for c in spec["choices"]))
with args.csv.open("w",newline="",encoding="utf-8") as out, concurrent.futures.ThreadPoolExecutor(max_workers=args.workers) as pool:
    writer=csv.writer(out)
    writer.writerow(["combo","hash","error","bytes","size","prologue","ctor_count","ctor_offsets","speed_count","controls_ok"])
    for row in pool.map(evaluate,combos):
        writer.writerow(row)
        out.flush()
