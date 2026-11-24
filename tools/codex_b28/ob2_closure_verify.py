"""Test fitted marker ranges on the two authentic distance-expression calls.

Inputs are the ob2_blackbox sample CSVs and ob2_bullet_closure native-site CSV.
No native outcomes enter the fit. The marker has one more direct candidate than
the unmodified root. --slope converts this one-site difference into a budget
correction. A distance site's size is assumed to be free on entry. Predictions
are sets where fitted R and N are not unique. The two real source sites are
identified by the interval between Projectile_Motion and Get_Height_GL.
"""
import argparse
import csv
from pathlib import Path
import sys
sys.path.insert(0, str(Path(__file__).resolve().parent))
from ob2_frontier import read, fit
from ob2_geometry_verify import geometry_graph
from functools import lru_cache


@lru_cache(maxsize=None)
def nested(share):
    graph = geometry_graph()
    minus, ctor, length = [graph[x]["size"] for x in ("minus","ctor","Length")]
    charged = 0
    if share >= minus:
        charged = minus
        if (share-minus)//2 >= ctor:
            charged += ctor
    uses_call = int(share-charged < length)
    return uses_call, charged + (0 if uses_call else length)


def possibilities(ranges, k, slope):
    possible=set()
    for n,low,high in ranges:
        for budget in range(low,high+1):
            remaining = budget+slope*(k-1)
            pending = n+k-1
            count=0
            for i in range(2):
                spills,charge=nested(remaining//(pending-i))
                remaining-=charge
                count+=spills
            possible.add(count)
    return possible


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("--fit", type=Path, nargs="+", required=True)
    p.add_argument("--sites", type=Path, required=True)
    p.add_argument("--csv", type=Path, required=True)
    p.add_argument("--slope", type=int, default=8)
    args=p.parse_args()
    ranges=fit(list(read(args.fit)), args.slope)
    if not ranges:
        raise SystemExit("No feasible root for training data")
    with args.sites.open(newline="") as src, args.csv.open("w", newline="") as dst:
        out=csv.writer(dst)
        out.writerow(("k","predicted_closure_calls","observed","consistent"))
        for row in csv.DictReader(src):
            k=int(row["k"])
            possible = possibilities(ranges, k, args.slope)
            actual=int(row["closure_length_calls"])
            out.writerow((k,"|".join(map(str,sorted(possible))),actual,actual in possible))


if __name__=="__main__":
    main()