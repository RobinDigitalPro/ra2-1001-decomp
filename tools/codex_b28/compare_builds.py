"""Compare registered RVA results and all emitted functions between two VC6 builds."""
import argparse
import json
import sys
from pathlib import Path


def signatures(obj):
    result = {}
    for name, sym in obj.symbols.items():
        if sym["value"] != 0:
            continue
        section = obj.function(name)
        relocations = []
        for offset, index, kind in section["relocs"]:
            target = obj.by_index[index]
            label = target["name"]
            if (target["section"] == sym["section"] and target["storage"] in (3, 6)
                    and label.startswith("$")):
                label = f"local-at-{target['value']}"
            relocations.append((offset, label, kind))
        relocations.sort()
        result[name] = section["raw"], relocations
    return result


def audit(before, after, obj_type):
    initial = json.loads(before.read_bytes())
    final = json.loads(after.read_bytes())
    if initial.keys() != final.keys():
        raise ValueError(f"Different audited RVA sets for {before.stem}")
    before_code, after_code = (signatures(obj_type(p.with_suffix(".obj").read_bytes()))
                               for p in (before, after))
    all_symbols = before_code.keys() | after_code.keys()
    changes = sorted(n for n in all_symbols if before_code.get(n) != after_code.get(n))
    changed_claims = {}
    lost = []
    for rva, old in initial.items():
        new = final[rva]
        if old == new:
            continue
        if (old.get("function") in before_code and old.get("function") not in changes
                and old.get("status") == new.get("status")
                and old.get("byte_differences") == new.get("byte_differences")):
            # COFF may renumber a private jump label in an otherwise identical section.
            # signatures() already compared its section-relative destination.
            continue
        changed_claims[rva] = {label: {k: row.get(k) for k in ("status", "byte_differences", "size")}
                               for label, row in (("before", old), ("after", new))}
        if old.get("byte_differences") == 0 and (new.get("byte_differences") != 0
                or new.get("relocation_problems") != old.get("relocation_problems")
                or new.get("unresolved_bindings") != old.get("unresolved_bindings")):
            lost.append(rva)
    return dict(rvas_checked=len(initial), functions_compared=len(all_symbols),
                changed_functions=changes, changed_rvas=changed_claims, lost_claims=lost)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ("kit", "before", "after", "output"):
        parser.add_argument(name, type=Path)
    args = parser.parse_args()
    sys.path.insert(0, str(args.kit.resolve() / "tools"))
    from coffmatch import Obj
    result = {}
    for before in sorted(args.before.glob("*/*.json")):
        result[before.stem] = audit(before, args.after / before.relative_to(args.before), Obj)
    if len(result) != 12:
        raise ValueError(f"Expected 12 translation units, received {len(result)}")
    args.output.write_text(json.dumps(result, indent=2), encoding="utf-8")
    print(sum(r["rvas_checked"] for r in result.values()), "RVAs checked;",
          sum(len(r["lost_claims"]) for r in result.values()), "claims lost")


if __name__ == "__main__":
    main()
