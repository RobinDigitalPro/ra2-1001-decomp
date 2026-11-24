"""Measure the two native distance expressions with k empty diagnostic suffix sites.

The unmodified k=0 function is compiled first. Each higher k appends calls to a
fresh empty inline in the diagnostic copy. All measurements use real COFF relocations.
"""
import argparse
import csv
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from ob2_blackbox import build, references


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for opt in ("kit", "work", "src", "csv"):
        parser.add_argument("--"+opt, type=Path, required=True)
    parser.add_argument("--waits", default="0,1,2,3,4,5,6,7,8,10,12,16,20,24,28,32")
    args = parser.parse_args()
    args.kit = args.kit.resolve()
    args.work = args.work.resolve()
    sys.path.insert(0, str(args.kit/"tools"))
    src = args.src.read_bytes().decode("latin-1").replace("\r\n","\n")
    anchor = "int delta = old_coord.Distance_To(target_coord) - coord.Distance_To(target_coord);"
    root = "void BulletClass::AI(void)"
    assert src.count(anchor) == 1 and src.count(root) == 1
    with args.csv.open("w", newline="", encoding="utf-8") as stream:
        writer = csv.writer(stream)
        writer.writerow(("k","closure_length_calls","Length_calls","point_minus_calls","point_ctor_calls","direct_calls"))
        for k in map(int, args.waits.split(",")):
            text = src
            if k:
                text = text.replace(root, "static inline void model_idle() {}\n"+root)
                text = text.replace(anchor, anchor+"\n"+"model_idle();\n"*k)
            obj = build(args, text, f"original_site_{k}")
            refs = references(obj, "?AI@BulletClass@@UAEXXZ")
            count = lambda prefix: sum(s.startswith(prefix) for s in refs)
            start = next(i for i,sym in enumerate(refs) if sym.startswith("?Projectile_Motion@@"))
            end = next(i for i,sym in enumerate(refs[start:], start) if sym.startswith("?Get_Height_GL@MapClass@@"))
            closure = sum(sym.startswith("?Length@?$TPoint3D@H@@") for sym in refs[start:end])
            writer.writerow((k,closure,count("?Length@?$TPoint3D@H@@"),count("??G?$TPoint3D@H@@"),
                             count("??0?$TPoint3D@H@@"),len(refs)))
            stream.flush()


if __name__ == "__main__":
    main()