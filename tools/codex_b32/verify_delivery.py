"""Verify replayable batch 32 source edits and report uncached search evidence."""
import argparse
import hashlib
import json
from pathlib import Path


def read_text(path):
    return path.read_bytes().decode("latin1").replace("\r\n", "\n")


def cached_hash(base, choices, combo):
    source = base
    if len(combo) > len(choices):
        raise ValueError("Cache refers to more choices than this spec contains")
    # An extended spec can retain records from its shorter parent.
    for choice, index in zip(choices, combo):
        for old, new, *anchor in choice["options"][index]["edits"]:
            if anchor and source.count(anchor[0]) == 1:
                pos = source.find(old, source.index(anchor[0]))
            elif not anchor and source.count(old) == 1:
                pos = source.index(old)
            else:
                raise ValueError("Invalid search edit")
            if pos < 0:
                raise ValueError("Missing search edit")
            source = source[:pos] + new + source[pos + len(old):]
    return hashlib.sha256(source.encode("latin1")).hexdigest()[:20]


def verify(inputs, result):
    summary = {"sources": {}, "searches": {}}
    for tu in ("queue", "startup", "ownrdraw", "map", "bullet", "isotype"):
        name = tu + ".cpp"
        original = read_text(inputs / name)
        final = read_text(result / name)
        edits = result / ("edits_" + tu + "_1.json")
        if edits.exists():
            replayed = original
            for old, new in json.loads(edits.read_bytes()):
                if replayed.count(old) != 1:
                    raise ValueError(f"{tu}: ambiguous replacement")
                replayed = replayed.replace(old, new, 1)
            if replayed != final:
                raise ValueError(f"{tu}: edits failed to reproduce submission")
        elif tu in ("queue", "startup", "ownrdraw", "map"):
            raise ValueError(f"{tu}: missing edits")
        summary["sources"][name] = {
            "sha256": hashlib.sha256((result / name).read_bytes()).hexdigest(),
            "changed": original != final,
            "edits_verified": edits.exists(),
        }
    for cache in sorted(result.glob("*.results.jsonl")):
        spec = result / (cache.name.removesuffix(".results.jsonl") + ".json")
        settings = json.loads(spec.read_bytes())
        base = result / settings["base"]
        if not base.is_file():
            raise ValueError(f"{spec.name}: missing base {base}")
        records = [json.loads(line) for line in cache.read_bytes().splitlines() if line.strip()]
        accepted = [row["score"] for row in records if row.get("controls_ok") and row.get("score") is not None]
        if not accepted:
            raise ValueError(f"{spec.name}: no usable scores")
        original = read_text(base)
        checked = 0
        for row in records:
            if row.get("hash"):
                if cached_hash(original, settings["choices"], row["combo"]) != row["hash"]:
                    raise ValueError(f"{spec.name}: cache hash mismatch for {row['combo']}")
                checked += 1
        summary["searches"][spec.name] = {"records": len(records), "hashes_verified": checked,
                                          "best_passing_score": min(accepted)}
    return summary


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("inputs", type=Path)
    parser.add_argument("result", type=Path)
    args = parser.parse_args()
    print(json.dumps(verify(args.inputs, args.result), indent=2))
