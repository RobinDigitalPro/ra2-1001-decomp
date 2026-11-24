"""Compile controlled /Ob2 cases or probe one source anchor with the user's VC6 kit.
Usage: python -I ob2_blackbox.py --kit KIT --work WRITABLE lab --csv lab.csv
       python -I ob2_blackbox.py --kit KIT --work WRITABLE sample --src TU.cpp
         --function "void BulletClass::AI(void)" --target "?AI@BulletClass@@UAEXXZ"
         --anchor "int delta = ..." --csv observations.csv --stores 8,12 --waits 0,5
Only scratch .cpp/.obj files are built, never linked or executed. On Windows
the flags match the m85 preset. Markers are compiler-observable extern storage.
"""
import argparse
import csv
import os
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from level2_ob2model import simulate


def store_code(n, start=1):
    return "".join(f"ModelMarks[{start+j}] = {j+1};\n" for j in range(n))


def build(args, text, name):
    from coffmatch import Obj
    args.work.mkdir(parents=True, exist_ok=True)
    src = args.work / (name + ".cpp")
    obj = args.work / (name + ".obj")
    src.write_bytes(text.replace("\r\n", "\n").replace("\n", "\r\n").encode("latin-1"))
    vc = args.kit / "vc6"
    env = os.environ.copy()
    env["PATH"] = os.pathsep.join([str(vc / "VC98/BIN"), str(vc / "COMMON/MSDEV98/BIN"), env["PATH"]])
    env["INCLUDE"] = os.pathsep.join(map(str, [vc/"VC98/INCLUDE", vc/"VC98/ATL/INCLUDE"]))
    env["TEMP"] = env["TMP"] = str(args.work)
    cmd = [str(vc/"VC98/BIN/CL.EXE"), "-nologo", "-c", "-O2", "-Ob2", "-Gr", "-GR",
           "-DNDEBUG", "-Gy", "-DWIN32", "-W0", "-I"+str(args.kit/"m85/src"),
           "-I"+str(args.kit/"m85/include"), "-Fo"+str(obj), str(src)]
    subprocess.run(cmd, cwd=args.work, env=env, capture_output=True, check=True)
    return Obj(obj.read_bytes())


def references(obj, sym):
    relocs = obj.function(sym)["relocs"]
    return [obj.by_index[idx]["name"] for _, idx, typ in relocs if typ == 0x14]


def callee_name(obj, stem):
    return next(name for name in obj.symbols if name.startswith("?"+stem+"@@"))


def cases():
    for stores in (3,4,5):
        for waiting in (32,40):
            yield "tiny_edge", stores, waiting, 0, 0, 0
    for stores in [3,4,5,6,7,8,10,12,16,24,32,50]:
        for waiting in sorted({0, 12, 28, 32, *(max(0,1000//(12+6*stores)+x) for x in [-2,-1,0,1])}):
            yield "nested", stores, waiting, 0, 0, 0
    for stores in [5,8,12,18]:
        for waiting in [2,7,12,20]:
            for cost in [4,12]:
                yield "prefix", stores, waiting, 0, cost, 0
    for stores in [8,16,24]:
        for waiting in [5,10,14]:
            for extra in [70,140]:
                yield "above_floor", stores, waiting, extra, 0, 0
    for stores in range(22,32):
        yield "auto_cap", stores, 0, 0, 0, 0
    for stores in [5,8,16]:
        for waiting in [3,8,12]:
            for nested in [1,3]:
                yield "depth3", stores, waiting, 0, 0, nested


def laboratory(args):
    rows = []
    cases_all = list(cases())
    for start in range(0, len(cases_all), 20):
        code = ["extern volatile int ModelMarks[];\ninline void model_idle() {}\n"]
        group = []
        for number, case in enumerate(cases_all[start:start+20], start):
            family, count, waiting, padding, spend, nested = case
            leaf, wrap, root = [f"model_{s}_{number}" for s in ("leaf","wrap","root")]
            spending, mid = f"model_spend_{number}",f"model_mid_{number}"
            is_auto = family == "auto_cap"
            adds_site = family == "tiny_edge"
            leaf_size = 12+6*count+4*adds_site
            graph = {leaf:dict(size=leaf_size,declared_inline=not is_auto,
                               sites=["model_idle"] if adds_site else []),
                     "model_idle":dict(size=12)}
            prefix = "" if is_auto else "inline "
            extra = "model_idle();" if adds_site else ""
            code.append(f"{prefix}void {leaf}() {{\n{store_code(count)} {extra} }}\n")
            if spend:
                graph[spending]=dict(size=12+6*spend)
                code.append(f"inline void {spending}() {{\n{store_code(spend,100)} }}\n")
            inner = [leaf]
            if nested:
                inner += ["model_idle"] * nested
                graph[mid] = dict(size=12+4*len(inner),sites=inner)
                code.append(f"inline void {mid}() {{ {''.join(n+'(); ' for n in inner)} }}\n")
                inner = [mid]
            if is_auto:
                site = leaf
            else:
                graph[wrap] = dict(size=12+4*len(inner),sites=inner)
                code.append(f"inline void {wrap}() {{ {''.join(n+'(); ' for n in inner)} }}\n")
                site = wrap
            sites = ([spending] if spend else []) + [site] + ["model_idle"] * waiting
            graph[root] = dict(size=12+6*padding+4*len(sites),sites=sites)
            code.append(f"void {root}() {{\n{store_code(padding,200)}{''.join(n+'(); ' for n in sites)} }}\n")
            predictions=simulate(graph,root)
            row = next((row for row in predictions if row["callee"]==leaf), None)
            group.append((number, case, root, leaf, wrap, mid, row))
        obj=build(args,''.join(code),f"group_{start}")
        for number, case, root, leaf, wrap, mid, row in group:
            refs=references(obj,callee_name(obj,root))
            accepted=not any(x.startswith(tuple("?"+name+"@@" for name in [leaf,wrap,mid])) for x in refs)
            expected=row is not None and row["decision"]=="inline"
            family,n,k,p,q,t=case
            rows.append(dict(test=number,family=family,stores=n,waiting=k,root_stores=p,
                             prefix_stores=q,inner_wait=t,s=(row or {}).get("s",12+6*n),
                             R=(row or {}).get("R",""),predicted=expected,observed=accepted,agree=expected==accepted))
    return rows


def sample(args):
    src = args.src.read_bytes().decode("latin-1").replace("\r\n","\n")
    if src.count(args.function)!=1 or src.count(args.anchor)!=1:
        raise ValueError("function and statement anchor must each occur exactly once")
    if src.index(args.function)>=src.index(args.anchor):
        raise ValueError("statement anchor must be inside the specified function")
    rows=[]
    for n in args.stores:
        for k in args.waits:
            head=("extern volatile int ModelMarks[];\n"
                  "static inline void model_idle() {}\n"
                  "static inline void model_leaf() {\n"+store_code(n)+"}\n"
                  "static inline void model_wrap() { model_leaf(); }\n")
            text=src.replace(args.function,head+args.function)
            lines="model_wrap();\n"+"model_idle();\n"*k
            text=text.replace(args.anchor,lines+args.anchor)
            obj=build(args,text,f"site_{n}_{k}")
            refs=references(obj,args.target)
            leaf_call=any(x.startswith("?model_leaf@@") for x in refs)
            wrap_call=any(x.startswith("?model_wrap@@") for x in refs)
            rows.append(dict(stores=n,waiting=k,s=12+6*n,leaf_inline=not leaf_call and not wrap_call,
                             wrapper_inline=not wrap_call,other_calls="|".join(x for x in refs if "model_" not in x)))
    return rows


def ints(s):
    return [int(x) for x in s.split(",")]


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("--kit",type=Path,required=True)
    p.add_argument("--work",type=Path,required=True)
    subs=p.add_subparsers(dest="command",required=True)
    lab=subs.add_parser("lab")
    site=subs.add_parser("sample")
    for sub in (lab,site):
        sub.add_argument("--csv",type=Path,required=True)
    site.add_argument("--src",type=Path,required=True)
    site.add_argument("--function",required=True)
    site.add_argument("--target",required=True)
    site.add_argument("--anchor",required=True)
    site.add_argument("--stores",type=ints,default=[4,5,8,12,20])
    site.add_argument("--waits",type=ints,default=[0,8,16])
    args=p.parse_args()
    args.kit=args.kit.resolve()
    args.work=args.work.resolve()
    sys.path.insert(0,str(args.kit/"tools"))
    rows=laboratory(args) if args.command=="lab" else sample(args)
    with args.csv.open("w",newline="",encoding="utf-8") as f:
        w=csv.DictWriter(f,fieldnames=list(rows[0]))
        w.writeheader()
        w.writerows(rows)
    print(f"{len(rows)} measurements in {args.csv}")
    if args.command=="lab":
        print(f"{sum(r['agree'] for r in rows)} predicted correctly")


if __name__=="__main__":
    main()
