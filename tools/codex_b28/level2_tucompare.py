"""Compare every /Gy function's code, relocation kinds and target names in two objects."""
import argparse
import json
import sys
from pathlib import Path

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--kit", required=True, type=Path)
    parser.add_argument("before", type=Path)
    parser.add_argument("after", type=Path)
    args = parser.parse_args()
    sys.path.insert(0, str(args.kit / "tools"))
    from coffmatch import Obj
    a, b = (Obj(p.read_bytes()) for p in (args.before, args.after))
    def comparison(obj, name):
        fn = obj.function(name)
        def binding(index):
            sym = obj.by_index[index]
            if sym["storage"] == 6 and sym["section"] == obj.symbols[name]["section"]:
                return ("local offset", sym["value"])
            return sym["name"]
        return fn["raw"], [(off, kind, binding(index)) for off, index, kind in fn["relocs"]]
    shared = a.symbols.keys() & b.symbols.keys()
    different = sorted(name for name in shared if comparison(a,name) != comparison(b,name))
    print(json.dumps(dict(shared=len(shared), changed=different,
        removed=sorted(a.symbols.keys()-shared), added=sorted(b.symbols.keys()-shared)), indent=2))
if __name__ == "__main__":
    main()
