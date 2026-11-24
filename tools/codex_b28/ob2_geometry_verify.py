"""Check independently compiled authentic geometry methods against explicit ordered graphs.

The integer costs represent one fit to the observed bands. A 20-unit representative
is used for free wrappers. The standalone fastmath::sqrt and conversion calls are
outside this three-decision model. All roots in this assay start at the floor.
"""
import argparse
import csv
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from level2_ob2model import simulate


def geometry_graph(minus=71, ctor=48, length=64):
    return {"wrap": {"size": 20, "sites": ["Distance_To"]},
            "Distance_To": {"size": 20, "sites": ["minus", "Length"]},
            "minus": {"size": minus, "sites": ["ctor"]},
            "ctor": {"size": ctor}, "Length": {"size": length}}


def verify(row):
    costs=geometry_graph()
    n, k = int(row["prefix_stores"]), int(row["waiting"])
    costs["wrap"]["sites"] = [row["method"]]
    costs["idle"] = dict(size=12)
    costs["prefix"] = dict(size=12+6*n)
    sites = (["prefix"] if n else []) + ["wrap"] + ["idle"]*k
    costs["root"] = dict(size=12+4*len(sites), sites=sites)
    rejections = {site["callee"] for site in simulate(costs, "root") if site["decision"]=="call"}
    checks = {"Length":"length_calls", "Distance_To":"distance_calls", "minus":"minus_calls", "ctor":"ctor_calls"}
    return {key: int(key in rejections) == int(row[field]) for key,field in checks.items()}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("csv", type=Path)
    args = parser.parse_args()
    with args.csv.open(encoding="utf-8",newline="") as stream:
        rows=list(csv.DictReader(stream))
    complete=sum(all(verify(r).values()) for r in rows)
    for method in ("Distance_To", "Length"):
        selected=[r for r in rows if r["method"]==method]
        print(method, sum(all(verify(r).values()) for r in selected), "/", len(selected))
    print("All four decisions correct:",complete,"/",len(rows))
    if complete != len(rows):
        for row in rows:
            if not all(verify(row).values()):
                print(row,verify(row))
        raise SystemExit(1)


if __name__=="__main__":
    main()