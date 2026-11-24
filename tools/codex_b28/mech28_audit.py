"""Compare all named /Gy functions by section bytes and relocation bindings.

Usage: python -I mech28_audit.py KIT baseline.obj candidate.obj
"""
from pathlib import Path
import sys

kit, base, final = map(Path, sys.argv[1:])
sys.path.insert(0, str(kit / "tools"))
from coffmatch import Obj


def signatures(path):
    obj = Obj(path.read_bytes())
    result = {}
    for name in obj.symbols:
        section = obj.function(name)
        bindings = tuple((offset, obj.by_index[index]["name"], kind)
                         for offset, index, kind in section["relocs"])
        result[name] = (section["raw"], bindings)
    return result


before, after = signatures(base), signatures(final)
different = sorted(name for name in before.keys() | after.keys()
                   if before.get(name) != after.get(name))
print("Baseline functions", len(before))
print("Candidate functions", len(after))
print("Changed", len(different))
print(*different, sep="\n")

