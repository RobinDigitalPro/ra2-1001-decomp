"""Measure symbol-number sensitivity in scratch builds; emit no patched game or compiler data.

Usage: level2_orderprobe.py --kit K --source queue.cpp --anchor "int Extract_..." --scratch TMP
  --counts 0:64 --out rows.jsonl --target Print_CRCs --rva 0x221b90 [--flag=-G5]
The anchor must occur exactly once. The unchanged function is compared to GAME.EXE at each count.
"""
import argparse
import concurrent.futures
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile

def main():
    ap = argparse.ArgumentParser(description=__doc__)
    for arg in ("kit", "source", "scratch", "out"):
        ap.add_argument("--" + arg, required=True, type=Path)
    for arg in ("anchor", "target", "counts"):
        ap.add_argument("--" + arg, required=True)
    ap.add_argument("--rva", required=True, type=lambda x: int(x, 0))
    ap.add_argument("--workers", type=int, default=3)
    ap.add_argument("--flag", action="append", default=[])
    args = ap.parse_args()
    kit = args.kit.resolve()
    sys.path[:0] = [str(kit / "tools"), str(kit)]
    from coffmatch import Obj
    import l2match
    raw = args.source.read_bytes()
    anchor = args.anchor.encode("latin-1")
    if raw.count(anchor) != 1:
        raise ValueError("anchor must occur exactly once")
    pos = raw.rfind(b"\n", 0, raw.index(anchor)) + 1
    counts = []
    for piece in args.counts.split(","):
        ends = [int(x) for x in piece.split(":")]
        counts.extend(range(ends[0], ends[-1] + 1))
    bindir = kit / "vc6/VC98/BIN"
    env = os.environ.copy()
    env["PATH"] = os.pathsep.join([str(bindir), str(kit / "vc6/COMMON/MSDEV98/BIN"), env["PATH"]])
    env["INCLUDE"] = os.pathsep.join(str(kit / "vc6/VC98" / name) for name in ("INCLUDE", "ATL/INCLUDE"))
    args.scratch.mkdir(parents=True, exist_ok=True)
    def compile_one(n):
        with tempfile.TemporaryDirectory(dir=args.scratch) as d:
            directory = Path(d).resolve()
            src = directory / "probe.cpp"
            obj = directory / "probe.obj"
            extra = b"".join(f"struct QueueOrderGauge{i}; ".encode() for i in range(n))
            src.write_bytes(raw[:pos] + extra + raw[pos:])
            cmd = [str(bindir / "CL.EXE"), "-nologo","-c","-O2","-Ob2","-Gr","-GR","-DNDEBUG","-Gy","-DWIN32","-W0",
                   "-I" + str(kit / "m85/src"), "-I" + str(kit / "m85/include"), *args.flag, "-Fo" + str(obj), str(src)]
            job = subprocess.run(cmd, cwd=directory, env=dict(env,TEMP=d,TMP=d), capture_output=True, timeout=180)
            if job.returncode:
                raise RuntimeError(job.stdout.decode("latin-1") + job.stderr.decode("latin-1"))
            target = Obj(obj.read_bytes())
            names = [s for s in target.symbols if args.target in s]
            if len(names) != 1:
                raise ValueError(names)
            fn = target.function(names[0])
            buf = bytearray(fn["raw"])
            orig = bytearray(l2match.orig(args.rva,len(buf)))
            for off,_,_ in fn["relocs"]:
                buf[off:off+4] = orig[off:off+4] = bytes(4)
            offsets = [i for i,(a,b) in enumerate(zip(buf,orig)) if a!=b]
            return dict(k=n, diff=len(offsets), offsets=offsets, code_size=len(buf), digest=hashlib.sha256(buf).hexdigest())
    with concurrent.futures.ThreadPoolExecutor(args.workers) as pool, args.out.open("w", encoding="utf-8") as f:
        for entry in pool.map(compile_one, counts):
            f.write(json.dumps(entry) + "\n")
            f.flush()
            print(entry["k"], entry["diff"], flush=True)
if __name__ == "__main__":
    main()
