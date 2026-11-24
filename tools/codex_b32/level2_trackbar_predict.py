"""Predict Trackbar frame layout for the Batch 32 ownrdraw context, without reading target bytes."""
import argparse
import collections
import json
from pathlib import Path
import re

# F21's independent list of matching declaration-count residues.
F21 = {7, 10, 11, *range(13, 19), *range(27, 47), *range(51, 62)}
BASE_L = 81373
PHASE = 16
GOOD = "55bf28c492d7070de3ba0b1280e177f239dcbdbdd3108f56d26048ec24f79e8f"
SWAPPED = "bb621b1a639107e1f05cbb7ebde674aec0d4de50bcf85af47487573ba5b26390"


def predict(min_l):
    residue = (min_l - BASE_L + PHASE) % 64
    return residue, residue in F21


def listing_min_l(path):
    text = path.read_text(encoding="latin-1")
    section = re.search(
        r"^\?Trackbar_Proc@OwnerDraw[^\n]*\bPROC\b.*?^\?Trackbar_Proc@OwnerDraw[^\n]*\bENDP\b",
        text, re.M | re.S)
    # Only the procedure header line may consume non-newline characters.
    if section is None:
        raise ValueError("Trackbar PROC/ENDP pair missing")
    values = re.findall(r"\$L(\d+)\b", section[0])
    return min(map(int, values))


def audit(path):
    groups = collections.defaultdict(collections.Counter)
    errors = []
    for line in path.read_text().splitlines():
        r = json.loads(line)
        residue, match = predict(r["labels"]["L"][0])
        stats = groups[r["family"]]
        stats["cases"] += 1
        stats["exact"] += int(not r["offsets"])
        stats["correct"] += int((GOOD if match else SWAPPED) == r["digest"])
        stats["bad_controls"] += sum(bool(x) for x in r["controls"].values())
        if (GOOD if match else SWAPPED) != r["digest"]:
            errors.append((r["family"], r["n"], residue))
    return dict(file=path.name, groups=groups, errors=errors)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    g = parser.add_mutually_exclusive_group(required=True)
    g.add_argument("--min-l", type=int)
    g.add_argument("--listing", type=Path)
    g.add_argument("--audit", type=Path, nargs="+")
    args = parser.parse_args()
    if args.audit:
        reports = [audit(path) for path in args.audit]
        print(json.dumps(reports, indent=2))
        return int(any(r["errors"] or any(g["bad_controls"] for g in r["groups"].values()) for r in reports))
    minimum = args.min_l if args.listing is None else listing_min_l(args.listing)
    residue, match = predict(minimum)
    print(json.dumps(dict(min_L=minimum, f21_residue=residue, exact=match,
                          range_slot=-200 if match else -208,
                          minimum_slot=-208 if match else -200)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
