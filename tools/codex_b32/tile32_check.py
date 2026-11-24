"""Check the submitted edit and rescore the observed register fixtures."""
import argparse
import csv
import json
from pathlib import Path
from level2_nested32 import forecast

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("original", type=Path)
parser.add_argument("result", type=Path)
parser.add_argument("--write-edit", action="store_true")
args = parser.parse_args()
original = args.original.read_bytes()
final = (args.result / "isotype.cpp").read_bytes()
before = original.decode("latin1").splitlines(keepends=True)
after = final.decode("latin1").splitlines(keepends=True)
first = next(i for i, (a, b) in enumerate(zip(before, after)) if a != b)
last = next(i for i, (a, b) in enumerate(zip(reversed(before), reversed(after))) if a != b)
old = "".join(before[first:len(before) - last])
new = "".join(after[first:len(after) - last])
edit = args.result / "edits_isotype_1.json"
if args.write_edit:
    edit.write_text(json.dumps([[old, new]], indent=2) + "\n")
[[old, new]] = json.loads(edit.read_text())
assert original.count(old.encode("latin1")) == 1
assert original.replace(old.encode("latin1"), new.encode("latin1"), 1) == final
for name in ("tile32_nested.csv", "tile32_boundary.csv"):
    with (args.result / name).open(newline="") as handle:
        rows = list(csv.DictReader(handle))
    hits = 0
    for row in rows:
        pred = forecast(int(row["left"]), int(row["right"]), bool(int(row["reverse"])))
        hits += all(v == row["actual_" + k] for k, v in pred.items())
    print(name, hits, "/", len(rows))
    assert hits == len(rows)
print("Exact replacement verified")
