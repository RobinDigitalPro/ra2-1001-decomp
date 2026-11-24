"""Export the measured diff, full relocation-masked digest and actual offsets for each compile.
Usage: python -I export_win.py RAW_JSONL DIRECTORY
Run win_counter_probe.py with --start 0 --end 127 at the before-signature anchor first.
"""
import argparse
import json
from pathlib import Path

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("raw", type=Path)
parser.add_argument("out", type=Path)
args = parser.parse_args()
rows = sorted((json.loads(line) for line in args.raw.read_text().splitlines()), key=lambda r: r["k"])
if [r["k"] for r in rows] != list(range(128)):
    parser.error("expected one observation per k from 0 through 127")
args.out.mkdir(exist_ok=True, parents=True)
for name, portion in [("train", rows[:64]), ("test", rows[64:])]:
    with (args.out / ("winmain_" + name + ".jsonl")).open("w", encoding="utf8") as stream:
        for row in portion:
            assert row["kind"] == "tag" and row["where"] == "before"
            result = dict(k=row["k"], diff=row["masked_differences"], digest=row["code_sha256"],
                          offsets=row["offsets"], code_size=row["code_size"], placement=row["where"],
                          seh_id=row["seh_id"])
            print(json.dumps(result), file=stream)

