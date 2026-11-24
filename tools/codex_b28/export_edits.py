"""Export small, unique replacements and replay each against the submitted source."""
import argparse
import difflib
import json
from pathlib import Path


def read(path):
    return path.read_bytes().decode("latin1").replace("\r\n", "\n")


def replacements(original, final):
    left, right = (s.splitlines(keepends=True) for s in (original, final))
    edits = []
    current = original
    matcher = difflib.SequenceMatcher(None, left, right, autojunk=False)
    for group in reversed(list(matcher.get_grouped_opcodes(3))):
        i, k = group[0][1], group[0][3]
        j, end = group[-1][2], group[-1][4]
        old, new = "".join(left[i:j]), "".join(right[k:end])
        if original.count(old) != 1 or current.count(old) != 1:
            raise ValueError(f"Ambiguous edit at original line {i + 1}")
        current = current.replace(old, new, 1)
        edits.append([old, new])
    if current != final:
        raise ValueError("Final source replay mismatch")
    return edits


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("inputs", type=Path)
    parser.add_argument("result", type=Path)
    args = parser.parse_args()
    for path in sorted(args.inputs.glob("*.cpp")):
        edits = replacements(read(path), read(args.result / path.name))
        if edits:
            dest = args.result / f"edits_{path.stem}_1.json"
            dest.write_text(json.dumps(edits, indent=2) + "\n", encoding="utf-8")
            print(path.name, len(edits))


if __name__ == "__main__":
    main()
