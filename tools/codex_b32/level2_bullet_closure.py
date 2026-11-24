"""Measure genuine Bullet AI Length calls under a diagnostic suffix, using a licensed kit.
Optional marker frontier measurements use independent volatile-array stores before both distance calls.
"""
import argparse
import csv
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from level2_ob2_ruler import compile_object, references, stores


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    for name in ("kit", "src", "work", "csv"):
        ap.add_argument("--"+name, type=Path, required=True)
    ap.add_argument("--waits", default="0,1,2,3,4,5,6,7,8,10,12,16,20,24,28,32")
    ap.add_argument("--sizes", help="comma-separated array store counts for calibration")
    args = ap.parse_args()
    kit, work = args.kit.resolve(), args.work.resolve()
    sys.path.insert(0, str(kit/"tools"))
    source = args.src.read_bytes().decode("latin-1").replace("\r\n", "\n")
    root = "void BulletClass::AI(void)"
    anchor = "int delta = old_coord.Distance_To(target_coord) - coord.Distance_To(target_coord);"
    assert source.count(root) == source.count(anchor) == 1
    sizes = list(map(int, args.sizes.split(","))) if args.sizes else [None]
    with args.csv.open("w", newline="", encoding="utf-8") as file:
        writer = csv.writer(file)
        writer.writerow(["k", "size", "leaf_inline", "closure_Length_calls", "direct_calls"])
        for n in sizes:
            for k in map(int, args.waits.split(",")):
                decl = "inline void RulerIdle(){}\n" if k else ""
                prefix = ""
                if n is not None:
                    decl += ("extern volatile int RulerMarks[];\ninline void RulerMarker(){"+stores(n)+"}\n"
                             "inline void RulerWrap(){RulerMarker();}\n")
                    prefix = "RulerWrap();\n"+"RulerIdle();\n"*k
                suffix = "\n"+"RulerIdle();\n"*k if n is None else ""
                text = source.replace(root, decl+root).replace(anchor, prefix+anchor+suffix)
                obj = compile_object(kit, work, "closure", text)
                refs = references(obj, "?AI@BulletClass@@UAEXXZ")
                lo = next(i for i, sym in enumerate(refs) if sym.startswith("?Projectile_Motion@@"))
                hi = next(i for i, sym in enumerate(refs[lo:],lo) if sym.startswith("?Get_Height_GL@MapClass@@"))
                calls = sum(s.startswith("?Length@?$TPoint3D@H@@") for s in refs[lo:hi])
                fits = not any(s.startswith(("?RulerMarker@@", "?RulerWrap@@")) for s in refs)
                writer.writerow([k, 12+6*n if n is not None else "", int(fits) if n is not None else "", calls, len(refs)])
                file.flush()


if __name__ == "__main__":
    main()
