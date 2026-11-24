"""Test a modulo-64 calibration against separately compiled higher counts."""
import argparse
import json
from pathlib import Path

from level2_symhash import fit, verify


def check(path):
    data = json.loads(path.read_bytes())["trials"]
    reports = {}
    for tu in ("sidebar", "wonline", "mapgen"):
        rows = [
            {"k": row["count"], "digest": row["raw_body_sha256"],
             "size": row["size"], "diff": row["differences"]}
            for row in data if row["tu"] == tu and row["prefix"] == "probe"
        ]
        profile = fit([r for r in rows if r["k"] < 64], 64, tu)
        reports[tu] = verify(profile, [r for r in rows if r["k"] >= 64])
    return reports


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("measurements", type=Path)
    results = check(parser.parse_args().measurements)
    print(json.dumps(results, indent=2))
    if any(r["failed"] or r["uncalibrated"] or not r["passed"] for r in results.values()):
        raise SystemExit(1)
