"""Check positional differences and all non-target functions for varsearch finalists.

python -I level2_webweight_finalists.py SPEC --kit KIT --work PRIVATE_DIR --out assessment.json
Chooses one source per distinct (hunk score, emitted size) among at most 24
candidates. This is a secondary check, not a full positional search.
"""
import argparse
import json
import os
from pathlib import Path
import subprocess
import sys


def signatures(obj):
    rows={}
    for name in obj.symbols:
        s=obj.function(name)
        rows[name]=(s["raw"],[(off,obj.by_index[idx]["name"],kind) for off,idx,kind in s["relocs"]])
    return rows


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("spec",type=Path)
    p.add_argument("--kit",type=Path,required=True)
    p.add_argument("--work",type=Path,required=True)
    p.add_argument("--out",type=Path,required=True)
    p.add_argument("--combo",help="check baseline and an explicit binary combination from the hunk cache")
    p.add_argument("--extent",type=int,help="independently established reference extent including alignment")
    args=p.parse_args()
    kit,work,specpath=args.kit.resolve(),args.work.resolve(),args.spec.resolve()
    spec=json.loads(specpath.read_text())
    source=(specpath.parent/spec["base"]).read_bytes()
    text=source.decode("latin1").replace("\r\n","\n")
    rows=[json.loads(x) for x in specpath.with_suffix(".results.jsonl").read_text().splitlines()]
    zero=[0]*len(spec["choices"])
    baseline=next(r for r in rows if not any(r["combo"]))
    baseline=dict(baseline,combo=zero)
    size=baseline["targets"][0]["size"]
    seen=set()
    keep=[baseline]
    for r in sorted(rows,key=lambda r:(r["score"],abs(r["targets"][0]["size"]-size))):
        marker=(r["score"],r["targets"][0]["size"])
        if marker not in seen and r["controls_ok"]:
            seen.add(marker)
            if any(r["combo"]):
                keep.append(r)
        if len(keep)==24:
            break
    if args.combo:
        wanted=[int(c) for c in args.combo]
        if len(wanted)!=len(zero) or set(wanted)-{0,1}:
            p.error("--combo must supply one binary digit per choice")
        selected=next(r for r in rows if r["combo"]==wanted)
        keep=[baseline,selected]
    sys.path[:0]=[str(kit/"tools"),str(kit)]
    import l2match
    from coffmatch import Obj
    vc=kit/"vc6"
    env=os.environ.copy()
    env["PATH"]=os.pathsep.join([str(vc/"VC98/BIN"),str(vc/"COMMON/MSDEV98/BIN"),env["PATH"]])
    env["INCLUDE"]=os.pathsep.join([str(vc/"VC98/INCLUDE"),str(vc/"VC98/ATL/INCLUDE")])
    env["TMP"]=env["TEMP"]=str(work)
    work.mkdir(parents=True,exist_ok=True)
    assessment=[]
    base_signatures=None
    for idx,row in enumerate(keep):
        combo=row["combo"]+[0]*(len(zero)-len(row["combo"]))
        variant=text
        for choice,option in zip(spec["choices"],combo):
            for old,new in choice["options"][option]["edits"]:
                if variant.count(old)!=1:
                    raise ValueError(old)
                variant=variant.replace(old,new)
        folder=work/str(idx)
        folder.mkdir(exist_ok=True)
        cpp=folder/"isotype.cpp"
        objfile=folder/"isotype.obj"
        cpp.write_bytes((variant.replace("\n","\r\n") if b"\r\n" in source else variant).encode("latin1"))
        flags=["-nologo","-c","-O2","-Ob2","-Gr","-GR","-DNDEBUG","-Gy","-DWIN32","-W0","-I"+str(kit/"m85/src"),"-I"+str(kit/"m85/include")]
        subprocess.run([str(vc/"VC98/BIN/CL.EXE"),*flags,"-Fo"+str(objfile),str(cpp)],env=env,cwd=folder,check=True,capture_output=True)
        obj=Obj(objfile.read_bytes())
        sig=signatures(obj)
        needle,address=spec["targets"][0]
        sym,=[n for n in sig if needle in n]
        if base_signatures is None:
            base_signatures=sig
        changed=[n for n in (set(sig)|set(base_signatures)) if n!=sym and sig.get(n)!=base_signatures.get(n)]
        target=l2match.run(str(objfile),needle,int(address,16),{})
        controls=[l2match.run(str(objfile),n,int(addr,16),{})["byte_differences"] for n,addr in spec["controls"]]
        assessment.append(dict(row=idx,combo=combo,hunks=row["score"],raw=target["byte_differences"],size=target["size"],
                               other_functions=len(base_signatures)-1,changed=sorted(changed),control_bytes=controls))
        if args.extent is not None:
            if args.extent<target["size"]:
                p.error("--extent is shorter than an emitted section")
            assessment[-1]["difference_including_missing_tail"]=target["byte_differences"]+args.extent-target["size"]
        args.out.write_text(json.dumps(assessment,indent=2)+"\n")
if __name__=="__main__":
    main()

