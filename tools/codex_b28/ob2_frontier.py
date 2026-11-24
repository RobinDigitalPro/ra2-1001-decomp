"""Fit a bounded site-share model to a real translation unit using ob2_blackbox.py sample.

Use --fit on one or more measured wait-count sweeps. --test takes unseen wait
counts. The default below assumes the unclamped root gets eight extra budget
units per added empty no-argument call and earlier nested spending is unchanged.
An empty feasible set rejects that assumption. A range crossing the threshold
is explicitly reported as ambiguous. Model predictions refer to this marker only.
"""
import argparse
import csv
from pathlib import Path


def read(paths):
    for path in paths:
        with path.open(encoding="utf-8", newline="") as stream:
            for row in csv.DictReader(stream):
                yield (int(row["waiting"]), int(row["s"]), row["leaf_inline"] == "True",
                       int(row["length_calls"]) if "length_calls" in row else
                       sum(call.startswith("?Length@?$TPoint3D@H@@") for call in row["other_calls"].split("|")))


def fit(samples, slope):
    intervals = []
    for pending in range(1, 35001):
        low, high = 0, 35000
        for k, size, accepted, _ in samples:
            if size <= 40:
                if not accepted:
                    return []
                continue
            boundary = size * (pending+k) - slope*k
            if accepted:
                low = max(low, boundary)
            else:
                high = min(high, boundary-1)
            if low > high:
                break
        if low <= high:
            intervals.append((pending, low, high))
    return intervals


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--fit", type=Path, nargs="+", required=True)
    parser.add_argument("--test", type=Path, nargs="+", default=[])
    parser.add_argument("--slope", type=int, default=8)
    parser.add_argument("--csv", type=Path, required=True)
    args = parser.parse_args()
    train = list(read(args.fit))
    tests = list(read(args.test))
    intervals = fit(train, args.slope)
    if not intervals:
        raise SystemExit("No feasible ordered-site model under the requested growth slope.")
    print("Possible N:", [entry[0] for entry in intervals])
    print("Feasible R bounds:", min(x[1] for x in intervals), max(x[2] for x in intervals))
    with args.csv.open("w", newline="", encoding="utf-8") as stream:
        writer = csv.writer(stream)
        writer.writerow(("partition","k","s","min_share","max_share","forecast","observed","length_calls"))
        for label, samples in (("fit", train), ("held out", tests)):
            for k, size, accepted, length_calls in samples:
                low = min((entry[1]+args.slope*k)//(entry[0]+k) for entry in intervals)
                high = max((entry[2]+args.slope*k)//(entry[0]+k) for entry in intervals)
                prediction = "inline" if size <= 40 or size <= low else "call" if size > high else "ambiguous"
                writer.writerow((label,k,size,low,high,prediction,"inline" if accepted else "call",length_calls))


if __name__ == "__main__":
    main()