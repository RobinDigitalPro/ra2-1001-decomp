"""Measure declaration sensitivity on ownrdraw.cpp in private scratch directories.

Use --cases extern:0,extern:1,struct:3,method:1,... . The calibration family is
extern data declarations before the module's first function declaration. The
other families test transfer. The assembly listing supplies independent label
numbers in function emission order. No listing or binary is retained.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import tempfile

FIRST = b"// RA2: the module's functions, declared before their first use"
TRACK = b"LRESULT __stdcall Trackbar_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) //"
CHECKS = (("Trackbar_Proc", 0x1f30a0), ("Progress_Proc", 0x1f2e30),
          ("Group_Box_Proc", 0x1f3e40), ("Scroll_Bar_Proc", 0x1f1f00), ("Hotkey_Proc", 0x1f4150))


def make_source(raw, family, count):
    if family == "method":
        member = b"\tint Window; // RA2: as above\n\tbool operator =="
        normalized = raw.replace(b"\r\n", b"\n")
        assert normalized.count(member) == 1
        decls = "".join(f"    void TBGauge{i}();\n" for i in range(count)).encode()
        return normalized.replace(member, decls + member)
    if family == "trailing":
        return raw + "".join(f"\nextern int TBGauge{i};" for i in range(count)).encode()
    anchor = TRACK if family == "near" else FIRST
    assert raw.count(anchor) == 1
    forms = {"extern": "extern int TBGauge{};", "near": "extern int TBGauge{};",
             "struct": "struct TBGauge{};", "proto": "void TBGauge{}();",
             "typedef": "typedef int TBGauge{};"}
    return raw.replace(anchor, b"".join((forms[family].format(i) + "\n").encode() for i in range(count)) + anchor)


def listing_data(listing):
    start = re.search(r"^\?Trackbar_Proc@OwnerDraw[^\n]* PROC\b", listing, re.M)
    if start is None:
        start = re.search(r"^\?Trackbar_Proc@OwnerDraw[^\n]*\bPROC\b", listing, re.M)
    if start is None:
        raise ValueError("cannot identify Trackbar function in /FA listing")
    section = listing[start.start():].split(" ENDP", 1)[0]
    section = re.split(r"^\?Trackbar_Proc@OwnerDraw[^\n]*\bENDP\b", section, maxsplit=1, flags=re.M)[0]
    groups = {}
    for kind, number in re.findall(r"\$([A-Z]+)(\d+)\b", section):
        groups.setdefault(kind, []).append(int(number))
    return {kind: [min(values), max(values), values[0]] for kind, values in groups.items()}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    for key in ("kit", "source", "scratch", "out"):
        ap.add_argument("--" + key, required=True, type=Path)
    ap.add_argument("--cases", required=True)
    ap.add_argument("--workers", type=int, default=3)
    ap.add_argument("--frame-audit", action="store_true", help="record the named operands from a /FAc listing")
    ap.add_argument("--include-root", type=Path, help="private copy of the m85/include tree for header experiments")
    args = ap.parse_args()
    kit = args.kit.resolve()
    include = args.include_root.resolve() if args.include_root else kit / "m85/include"
    sys.path[:0] = [str(kit / "tools"), str(kit)]
    if args.frame_audit:
        sys.path.insert(0, str(Path(__file__).resolve().parent))
        from level2_trackbar_frames import inspect
    from coffmatch import Obj
    import l2match
    raw = args.source.read_bytes()
    env = os.environ.copy()
    vc = kit / "vc6"
    env["PATH"] = os.pathsep.join([str(vc / "VC98/BIN"), str(vc / "COMMON/MSDEV98/BIN"), env["PATH"]])
    env["INCLUDE"] = os.pathsep.join([str(vc / "VC98/INCLUDE"), str(vc / "VC98/ATL/INCLUDE")])
    args.scratch.mkdir(parents=True, exist_ok=True)
    def build(case):
        family, n = case.split(":")
        n = int(n)
        with tempfile.TemporaryDirectory(dir=args.scratch) as d:
            tmp = Path(d)
            src, obj, asm = (tmp / ("probe." + ext) for ext in ("cpp", "obj", "asm"))
            src.write_bytes(make_source(raw, family, n))
            cmd = [str(vc / "VC98/BIN/CL.EXE"), "-nologo", "-c", "-O2", "-Ob2", "-Gr", "-GR", "-DNDEBUG",
                   "-Gy", "-DWIN32", "-W0", "-I" + str(kit / "m85/src"), "-I" + str(include),
                   "-FAc" if args.frame_audit else "-FA", "-Fa" + str(asm), "-Fo" + str(obj), str(src)]
            p = subprocess.run(cmd, cwd=d, env=dict(env, TMP=d, TEMP=d), capture_output=True, timeout=180)
            if p.returncode:
                raise RuntimeError((p.stderr + p.stdout).decode("latin-1")[-500:])
            labels = listing_data(asm.read_text("latin-1"))
            o = Obj(obj.read_bytes())
            results = {}
            for needle, rva in CHECKS:
                name, = (s for s in o.symbols if needle in s)
                section = o.function(name)
                code = bytearray(section["raw"])
                original = bytearray(l2match.orig(rva, len(code)))
                for off, _, _ in section["relocs"]:
                    code[off:off + 4] = original[off:off + 4] = bytes(4)
                offsets = [i for i, (a,b) in enumerate(zip(code,original)) if a != b]
                if needle == "Trackbar_Proc":
                    target = dict(size=len(code), digest=hashlib.sha256(code).hexdigest(), offsets=offsets,
                                  changes=[[i, code[i], original[i]] for i in offsets])
                else:
                    results[needle] = len(offsets)
            result = dict(family=family, n=n, labels=labels, controls=results, **target)
            if args.frame_audit:
                result["frame"] = inspect(asm)
            return result
    done = set()
    if args.out.exists():
        done = {(r["family"], r["n"]) for r in (json.loads(x) for x in args.out.read_text().splitlines())}
    cases = [c for c in args.cases.split(",") if (c.split(":")[0],int(c.split(":")[1])) not in done]
    with ThreadPoolExecutor(args.workers) as pool, args.out.open("a", encoding="utf-8") as out:
        for r in pool.map(build, cases):
            out.write(json.dumps(r) + "\n")
            out.flush()
            print(r["family"], r["n"], len(r["offsets"]), r["labels"], flush=True)

if __name__ == "__main__":
    main()
