"""Measure real TPoint3D<int>::Distance_To and Length decisions on VC6 in Bullet's header context.

python -B -I ob2_geometry.py --kit KIT --work TEMP --src bullet.cpp --csv geometry.csv
Each generated root is below the 500-unit root floor. Optional volatile-store prefix
has independently calibrated charge. The helper sampled at the first non-prefix site
is a genuine game-header method. The output share is before charging that method.
"""
import argparse
import csv
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from ob2_blackbox import build, callee_name, references, store_code


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for opt in ("kit", "work", "src", "csv"):
        parser.add_argument("--"+opt, type=Path, required=True)
    args = parser.parse_args()
    args.kit = args.kit.resolve()
    args.work = args.work.resolve()
    sys.path.insert(0, str(args.kit / "tools"))
    src = args.src.read_bytes().decode("latin-1").replace("\r\n", "\n")
    code = ["extern volatile int ModelMarks[];",
            "extern Coord model_a, model_b;",
            "inline void model_idle() {}"]
    cases = []
    for n in (0, 5, 9, 13, 17, 21, 25, 29, 33):
        if n:
            code.append(f"inline void model_prefix_{n}() {{ {store_code(n)} }}")
        for k in (3,4,5,6,7,8,10,12,15,20,26,40):
            for method in ("Distance_To", "Length"):
                name = f"model_geom_{method}_{n}_{k}"
                call = f"model_prefix_{n}(); " if n else ""
                args_expr = "model_b" if method == "Distance_To" else ""
                # One free parent for measuring the numeric leaf's decision at a controlled R.
                wrap = "model_wrap_"+name
                code.append(f"inline void {wrap}() {{ ModelMarks[99] = model_a.{method}({args_expr}); }}")
                code.append(f"void {name}() {{ {call}{wrap}(); " + "model_idle(); "*k + "}")
                cases.append((name, wrap, method, n, k))
    obj = build(args, src+"\n"+"\n".join(code), "geometry")
    rows = []
    for name, wrap, method, n, k in cases:
        refs = references(obj, callee_name(obj, name))
        spill = lambda prefix: sum(s.startswith(prefix) for s in refs)
        rows.append(dict(method=method, prefix_stores=n, waiting=k,
                         parent_share=(1000-(12+6*n if n else 0))//(1+k),
                         wrapper_calls=spill("?"+wrap+"@@"),
                         distance_calls=spill("?Distance_To@?$TPoint3D@H@@"),
                         minus_calls=spill("??G?$TPoint3D@H@@"),
                         ctor_calls=spill("??0?$TPoint3D@H@@"),
                         length_calls=spill("?Length@?$TPoint3D@H@@")))
    with args.csv.open("w", newline="", encoding="utf-8") as stream:
        writer = csv.DictWriter(stream, fieldnames=list(rows[0]))
        writer.writeheader()
        writer.writerows(rows)


if __name__ == "__main__":
    main()