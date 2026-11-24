"""Read two named slots and the eight affected instruction operands from a VC6 /FAc Trackbar listing."""
import argparse
import json
from pathlib import Path
import re

OFFSETS = (225, 232, 473, 480, 516, 2341, 2504, 2511)


def inspect(path):
    text = path.read_text(encoding="latin-1")
    header = re.search(r"^\?Trackbar_Proc@OwnerDraw[^\n]*\bPROC\b", text, re.M)
    end = re.search(r"^\?Trackbar_Proc@OwnerDraw[^\n]*\bENDP\b", text[header.end():], re.M)
    body = text[header.start():header.end() + end.start()]
    prior = text[:header.start()]
    slots = {name: int(re.findall(r"^_" + name + r"\$\s*=\s*(-?\d+)\s*$", prior, re.M)[-1])
             for name in ("range", "minimum")}
    blocks = list(re.finditer(r"^  ([a-fA-F\d]{5})\s+([^\n]+)(?:\n\t([^\n]+))?", body, re.M))
    uses = []
    for offset in OFFSETS:
        block = max((row for row in blocks if int(row[1], 16) <= offset), key=lambda row: int(row[1], 16))
        name = re.search(r"_(range|minimum)\$", block[0])
        if name is None:
            raise ValueError(f"missing named frame operand at +{offset:x}")
        uses.append(dict(offset=offset, instruction_offset=int(block[1], 16), slot=name[1]))
    return dict(file=path.name, slots=slots, uses=uses)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("listing", nargs="+", type=Path)
    print(json.dumps([inspect(path) for path in parser.parse_args().listing], indent=2))
