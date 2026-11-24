"""Measure integer-budget inline frontiers for genuine Point3D methods and two calibrants.

Build with the supplied input Bullet TU and licensed VC6 headers. The generated
caller first spends a calibrated 12+6*n units, then calls a wrapper and N-1 empty
functions. N counts the wrapper. Each R has two independent spend/site settings.
Read the direct COFF references without executing any generated code.
"""
import argparse
import csv
import os
import subprocess
import sys
from pathlib import Path


def compile_object(kit, work, name, text):
    from coffmatch import Obj
    work.mkdir(parents=True, exist_ok=True)
    src = work / (name + ".cpp")
    obj = work / (name + ".obj")
    src.write_bytes(text.replace("\r\n", "\n").replace("\n", "\r\n").encode("latin-1"))
    vc = kit / "vc6"
    env = os.environ.copy()
    env["PATH"] = os.pathsep.join([str(vc / "VC98/BIN"), str(vc / "COMMON/MSDEV98/BIN"), env["PATH"]])
    env["INCLUDE"] = os.pathsep.join(str(vc / p) for p in ("VC98/INCLUDE", "VC98/ATL/INCLUDE"))
    env["TEMP"] = env["TMP"] = str(work)
    cmd = [str(vc/"VC98/BIN/CL.EXE"), "-nologo", "-c", "-O2", "-Ob2", "-Gr", "-GR", "-DNDEBUG",
           "-Gy", "-DWIN32", "-W0", "-I"+str(kit/"m85/src"), "-I"+str(kit/"m85/include"),
           "-Fo"+str(obj), str(src)]
    run = subprocess.run(cmd, cwd=work, env=env, capture_output=True, timeout=240)
    if run.returncode:
        raise RuntimeError((run.stdout + run.stderr).decode("latin-1")[-2000:])
    return Obj(obj.read_bytes())


def references(obj, name):
    return [obj.by_index[idx]["name"] for _, idx, typ in obj.function(name)["relocs"] if typ == 0x14]


def stores(n):
    return " ".join(f"RulerMarks[{j+1}]={j+1};" for j in range(n))


def settings(share):
    candidates = [(n, count) for count in range(2, 21) for n in range(5, 135)
                  if (988 - 6*n)//count == share]
    if not candidates:
        return []
    return list(dict.fromkeys([candidates[0], candidates[-1]]))


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    for name in ("kit", "src", "work", "csv"):
        ap.add_argument("--"+name, type=Path, required=True)
    args = ap.parse_args()
    kit, work = args.kit.resolve(), args.work.resolve()
    sys.path.insert(0, str(kit/"tools"))
    source = args.src.read_bytes().decode("latin-1")
    methods = {"Length": "RulerMarks[0]=RulerA.Length();",
               "Distance": "RulerMarks[0]=RulerA.Distance_To(RulerB);",
               "Minus": "ConsumeRuler(RulerA-RulerB);",
               "Ctor": "ConsumeRuler(TPoint3D<int>(1,2,3));",
               "Mark54": "RulerMark54();", "Mark72": "RulerMark72();"}
    symbols = {"Length": "?Length@?$TPoint3D@H@@", "Distance": "?Distance_To@?$TPoint3D@H@@",
               "Minus": "??G?$TPoint3D@H@@", "Ctor": "??0?$TPoint3D@H@@",
               "Mark54": "?RulerMark54@@", "Mark72": "?RulerMark72@@"}
    with args.csv.open("w", newline="", encoding="utf-8") as file:
        writer = csv.writer(file)
        writer.writerow(["method", "share", "prefix_stores", "pending", "prefix_calls",
                         "wrapper_calls", *symbols])
        for start in range(40, 153, 20):
            generated = ["extern Coord RulerA, RulerB;", "extern volatile int RulerMarks[];",
                         "extern void ConsumeRuler(const TPoint3D<int>&);", "inline void RulerIdle(){}",
                         "inline void RulerMark54(){"+stores(7)+"}", "inline void RulerMark72(){"+stores(10)+"}"]
            for m, body in methods.items():
                generated.append(f"inline void Wrap{m}(){{{body}}}")
            prefixes, cases = set(), []
            for share in range(start, min(start+20, 153)):
                for n, count in settings(share):
                    if n not in prefixes:
                        generated.append(f"inline void Prefix{n}(){{{stores(n)}}}")
                        prefixes.add(n)
                    for m in methods:
                        name = f"Ruler_{m}_{share}_{n}_{count}"
                        generated.append(f"void {name}(){{Prefix{n}(); Wrap{m}();"
                                         + "RulerIdle(); "*(count-1)+"}")
                        cases.append((m, share, n, count, name))
            obj = compile_object(kit, work, "ruler_"+str(start), source+"\n"+"\n".join(generated))
            roots = {name.split("@@")[0][1:]: name for name in obj.symbols if name.startswith("?Ruler_")}
            for m, share, n, count, name in cases:
                refs = references(obj, roots[name])
                direct = lambda prefix: sum(x.startswith(prefix) for x in refs)
                writer.writerow([m, share, n, count, direct(f"?Prefix{n}@@"),
                                 direct(f"?Wrap{m}@@"), *(direct(prefix) for prefix in symbols.values())])
            file.flush()


if __name__ == "__main__":
    main()
