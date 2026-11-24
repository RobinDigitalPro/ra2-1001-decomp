"""Measure the shortest repeating digest across two or more complete cycles.

Usage: level2_ordercycle.py rows.jsonl [more_rows.jsonl ...]
Each JSONL is output from level2_orderprobe.py on the same source and victim.
"""
import argparse
import json
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rows", type=Path, nargs="+")
    args = parser.parse_args()
    by_k = {}
    for path in args.rows:
        for line in path.read_text(encoding="utf-8-sig").splitlines():
            row = json.loads(line)
            k = row["k"]
            if k in by_k and row != by_k[k]:
                raise ValueError(f"conflicting rows for k={k}")
            by_k[k] = row
    rows = [by_k[k] for k in range(len(by_k))]
    if not rows:
        raise ValueError("no observations")
    periods = [p for p in range(1, len(rows) // 2 + 1)
               if all(r["digest"] == rows[i % p]["digest"] for i, r in enumerate(rows))]
    if not periods:
        print(json.dumps(dict(observations=len(rows), shortest_period=None)))
        return
    p = periods[0]
    offsets = sorted({off for r in rows[:p] for off in r["offsets"]})
    groups = {}
    for off in offsets:
        mask = sum(1 << i for i, r in enumerate(rows[:p]) if off in r["offsets"])
        groups.setdefault(hex(mask), []).append(hex(off))
    print(json.dumps(dict(observations=len(rows), shortest_period=p,
                          equal_digest_pairs=len(rows)-p,
                          exact_residues=[i for i, r in enumerate(rows[:p]) if r["diff"] == 0],
                          offset_masks=groups), indent=2))

if __name__ == "__main__":
    main()
