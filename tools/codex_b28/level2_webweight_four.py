"""Compare a four-web allocation prediction with 48 VC6 endpoint measurements.

Use --kit KIT --work PRIVATE_DIR --csv output.csv. Each probe has four int
definitions, an opaque barrier, observed calls and four volatile endpoints.
The two families vary use order or tied assignment order independently.
"""
import argparse
import csv
import itertools
import os
from pathlib import Path
import subprocess
import sys

sys.path.insert(0,str(Path(__file__).resolve().parent))
from level2_webweight import rank


def probe(index, family, order):
    names = list("abcd")
    defs = names if family == "uses" else order
    uses = dict(zip(order,(4,3,2,1))) if family == "uses" else dict.fromkeys(names,2)
    source = [f'extern "C" void __cdecl probe{index}() {{']
    source += [f"int {w}=get_{w}();" for w in defs]
    source += ["barrier();"]
    for w in names:
        source += [f"use_{w}({w});"] * uses[w]
    source += [f"obs_{w}={w};" for w in names] + ["}"]
    case = dict(webs=list(defs), blocks=[dict(name="complete interference", live=names,
                                               refs={w:uses[w]+2 for w in names})])
    return "\n".join(source), case


def main():
    p=argparse.ArgumentParser(description=__doc__)
    for arg in ("kit","work","csv"):
        p.add_argument("--"+arg, required=True, type=Path)
    args=p.parse_args()
    kit,work=args.kit.resolve(),args.work.resolve()
    work.mkdir(parents=True,exist_ok=True)
    sys.path[:0]=[str(kit/"tools"),str(kit)]
    from coffmatch import Obj
    import capstone
    decoder=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    names=list("abcd")
    groups=[(family,order) for family in ("uses","ties") for order in itertools.permutations(names)]
    probes=[probe(i,*group) for i,group in enumerate(groups)]
    header=['extern "C" {', "void __cdecl barrier();"]
    for w in names:
        header.append(f"int __cdecl get_{w}(); void __cdecl use_{w}(int); extern volatile int obs_{w};")
    (work/"four.cpp").write_text("\n".join(header+["}"]+[src for src,_ in probes]))
    env=os.environ.copy()
    vc=kit/"vc6"
    env["PATH"]=os.pathsep.join([str(vc/"VC98/BIN"),str(vc/"COMMON/MSDEV98/BIN"),env["PATH"]])
    env["TMP"]=env["TEMP"]=str(work)
    subprocess.run([str(vc/"VC98/BIN/CL.EXE"),"-nologo","-c","-O2","-Ob2","-Gr","-GR","-DNDEBUG","-Gy","-W0","four.cpp"],cwd=work,env=env,check=True)
    obj=Obj((work/"four.obj").read_bytes())
    with args.csv.open("w",newline="",encoding="utf-8") as f:
        out=csv.writer(f)
        out.writerow(["family","order","pred_a_b_c_d","obs_a_b_c_d","exact"])
        for i,((family,order),(_,case)) in enumerate(zip(groups,probes)):
            predicted={r["web"]:r["reg"] for r in rank(case)}
            sec=obj.function(f"_probe{i}")
            refs={off:obj.by_index[idx]["name"] for off,idx,_ in sec["relocs"]}
            obs={}
            for ins in decoder.disasm(sec["raw"],0):
                for off in range(ins.address,ins.address+ins.size):
                    ref=refs.get(off,"")
                    if ref.startswith("_obs_"):
                        dst,src=ins.op_str.split(", ")
                        if ins.mnemonic!="mov" or "[" not in dst:
                            raise ValueError((i, dst,src))
                        obs[ref[-1]]=src
            out.writerow([family,"".join(order)," ".join(predicted[w] for w in names),
                          " ".join(obs[w] for w in names),int(predicted==obs)])


if __name__=="__main__":
    main()

