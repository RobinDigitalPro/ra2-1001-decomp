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


def winmain_scope(obj):
    """Normalize the private SEH descriptor referenced at WinMain+6 by its contents."""
    import struct
    name = "_WinMain@16"
    body = obj.function(name)
    off, idx, kind = next(rel for rel in body["relocs"] if rel[0] == 6)
    sym = obj.by_index[idx]
    if kind != 6 or not sym["name"].startswith("$T") or sym["section"] <= 0:
        return None
    section = obj.sections[sym["section"]-1]
    pos = sym["value"]
    record = section["raw"][pos:pos+12]
    entries = []
    for loc, idx, typ in section["relocs"]:
        if pos <= loc < pos+12:
            target = obj.by_index[idx]
            if target["section"] != obj.symbols[name]["section"] or typ != 6:
                return None
            entries.append((loc-pos,target["value"]+struct.unpack_from("<I",record,loc-pos)[0]))
    if len(record)!=12 or sorted(entries)!=[(4,0x260b),(8,0x2618)] or record[:4]!=b"\xff"*4:
        return None
    raw, relocs = signatures(obj)[name]
    return raw, [(offset,"verified WinMain scope record" if offset==6 else label,typ)
                 for offset,label,typ in relocs], sorted(entries)


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
    seh_remaps = []
    if before.stem == "startup" and "0x283970" in lost:
        pair = [winmain_scope(obj_type(p.with_suffix(".obj").read_bytes())) for p in (before,after)]
        if pair[0] is not None and pair[0] == pair[1]:
            lost.remove("0x283970")
            seh_remaps.append("0x283970")
    return dict(rvas_checked=len(initial), functions_compared=len(all_symbols), verified_scope_records=seh_remaps,
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
    if len(result) != 6:
        raise ValueError(f"Expected 6 translation units, received {len(result)}")
    args.output.write_text(json.dumps(result, indent=2), encoding="utf-8")
    print(sum(r["rvas_checked"] for r in result.values()), "RVAs checked;",
          sum(len(r["lost_claims"]) for r in result.values()), "claims lost")


if __name__ == "__main__":
    main()


