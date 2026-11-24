"""Validate the rule against a saved ruler or forecast both native Bullet closure calls.

Use 'ruler FILE' to check every observed relocation. Use 'closure CALIBRATION
NATIVE --csv OUT' to fit only the marker rows, then forecast the native COFF rows.
"""
import argparse
import csv
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from level2_ob2_8168 import simulate


def data(path):
    with path.open(newline="", encoding="utf-8") as f:
        return list(csv.DictReader(f))


def geometry():
    return {"Length": {"size": 64}, "Minus": {"size": 71, "sites": ["Ctor"]},
            "Ctor": {"size": 48}, "Distance": {"size": 20, "sites": ["Minus", "Length"]},
            "Mark54": {"size":54}, "Mark72":{"size":72}}


def ruler(rows):
    bad = []
    for row in rows:
        n, count = int(row["prefix_stores"]), int(row["pending"])
        nodes = geometry()
        names = list(nodes)
        nodes.update(prefix={"size":12+6*n}, idle={"size":12},
                     wrap={"size":20,"sites":[row["method"]]},
                     root={"size":12+4*(1+count),"sites":["prefix","wrap"]+["idle"]*(count-1)})
        trace = simulate(nodes, "root")
        called = {t["callee"] for t in trace if t["decision"] != "inline"}
        if any(int(row[name]) != int(name in called) for name in names) or int(row["prefix_calls"]) or int(row["wrapper_calls"]):
            bad.append((row["method"], row["share"], n, count))
    print(f"{len(rows)-len(bad)} of {len(rows)} complete root call profiles agree")
    if bad:
        print("First failures:", bad[:12])
    return not bad


def feasible(cal):
    # Adding an empty call contributes 4 to S, hence 8 to the unclamped root budget.
    ranges = []
    for pending in range(2, 35001):
        lo, hi = 0, 35000
        for row in cal:
            size, k = int(row["size"]), int(row["k"])
            if size <= 40:
                if row["leaf_inline"] != "1":
                    return []
                continue
            boundary = size*(pending+k)-8*k
            if row["leaf_inline"] == "1":
                lo = max(lo, boundary)
            else:
                hi = min(hi, boundary-1)
            if lo > hi:
                break
        if lo <= hi:
            ranges.append((pending,lo,hi))
    return ranges


def delta(share):
    # Descendants are the ordered [Minus(Ctor), Length] inside the free Distance wrapper.
    minus = 71 if share >= 71 else 0
    ctor = 48 if minus and (share-minus)//2 >= 48 else 0
    length = 64 if share-minus-ctor >= 64 else 0
    return int(length == 0), minus+ctor+length


def closure(cal, rows, destination):
    ranges = feasible(cal)
    if not ranges:
        raise ValueError("Marker data reject the constant earlier spend / eight-unit slope assumption")
    print("Fitted (pending, min budget, max budget):", ranges)
    correct = single = 0
    with destination.open("w", newline="", encoding="utf-8") as f:
        out = csv.writer(f)
        out.writerow(("k","possible_closure_calls","observed","consistent"))
        for row in rows:
            k = int(row["k"])
            possible = set()
            for pending, lo, hi in ranges:
                for budget in range(lo, hi+1):
                    remaining = budget + 8*(k-1)
                    sites = pending+k-1
                    if sites < 2:
                        continue
                    spills1, spent = delta(remaining//sites)
                    spills2, _ = delta((remaining-spent)//(sites-1))
                    possible.add(spills1+spills2)
            observed = int(row["closure_Length_calls"])
            agrees = observed in possible
            single += len(possible) == 1
            correct += agrees
            out.writerow((k,"|".join(map(str,sorted(possible))),observed,int(agrees)))
    print(f"{correct}/{len(rows)} consistent; {single} single-valued forecasts")
    return correct == len(rows)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    modes = ap.add_subparsers(dest="mode", required=True)
    r = modes.add_parser("ruler")
    r.add_argument("observations",type=Path)
    c = modes.add_parser("closure")
    c.add_argument("calibration",type=Path)
    c.add_argument("native",type=Path)
    c.add_argument("--csv",type=Path,required=True)
    args=ap.parse_args()
    ok = (ruler(data(args.observations)) if args.mode=="ruler"
          else closure(data(args.calibration),data(args.native),args.csv))
    raise SystemExit(0 if ok else 1)


if __name__ == "__main__":
    main()
