"""Inspect call-site changes for selected CachePCX variants of a level2_varsearch spec.

Usage: python -I srfcache_inline_sites.py KIT SPEC SCRATCH 0,0,0,0,0 0,1,1,0,0
Run with the kit's try.py, l2match, coffmatch and capstone. Writes only into SCRATCH.
"""
import argparse
import json
import pathlib
import subprocess
import sys
import tempfile

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("kit", type=pathlib.Path)
parser.add_argument("spec", type=pathlib.Path)
parser.add_argument("scratch", type=pathlib.Path)
parser.add_argument("combos", nargs="+")
args = parser.parse_args()
kit = args.kit.resolve()
sys.path[:0] = [str(kit), str(kit / "tools")]
import l2match
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from coffmatch import Obj

spec = json.loads(args.spec.read_text(encoding="utf-8"))
base = (args.spec.parent / spec["base"]).read_text(encoding="latin-1")
needle, rva = spec["targets"][0]
decoder = Cs(CS_ARCH_X86, CS_MODE_32)
args.scratch.mkdir(parents=True, exist_ok=True)
records = []
for requested in args.combos:
    indices = list(map(int, requested.split(",")))
    if len(indices) != len(spec["choices"]):
        raise ValueError(f"Expected {len(spec['choices'])} choices in {requested}")
    text = base
    for index, choice in zip(indices, spec["choices"]):
        for old, new, *anchor in choice["options"][index]["edits"]:
            if anchor and text.count(anchor[0]) != 1:
                raise ValueError(f"Invalid anchor {anchor[0]!r}")
            if not anchor and text.count(old) != 1:
                raise ValueError(f"Ambiguous old value {old!r}")
            start = text.index(anchor[0]) if anchor else 0
            pos = text.index(old, start)
            text = text[:pos] + new + text[pos + len(old):]
    with tempfile.TemporaryDirectory(dir=args.scratch.resolve()) as tmp:
        src = pathlib.Path(tmp) / "srfcache.cpp"
        src.write_text(text, encoding="latin-1")
        proc = subprocess.run([sys.executable, "-B", "-I", str(kit / "tools" / "try.py"),
                               str(src), f"{needle} {rva}"], cwd=tmp,
                              capture_output=True, text=True, timeout=150)
        if proc.returncode:
            raise RuntimeError(proc.stdout + proc.stderr)
        objpath = src.with_suffix(".obj")
        obj = Obj(objpath.read_bytes())
        [symbol] = [sym for sym in obj.symbols if needle in sym]
        frame = obj.function(symbol)
        reloc = {ofs: obj.by_index[idx]["name"] for ofs, idx, kind in frame["relocs"] if kind == 0x14}
        instructions = list(decoder.disasm(frame["raw"], 0))
        calls = []
        reloads = []
        for i, ins in enumerate(instructions):
            if ins.mnemonic == "call" and ins.address + 1 in reloc:
                calls.append({"offset": hex(ins.address), "callee": reloc[ins.address + 1]})
            group = instructions[i:i + 4]
            if [item.mnemonic for item in group] == ["call", "mov", "mov", "jmp"]:
                if all("[esp" in item.op_str for item in group[1:3]):
                    reloads.append({"offset": hex(group[1].address), "operands": [item.op_str for item in group[1:3]]})
        scored = l2match.run(str(objpath), symbol, int(rva, 16), {})
        records.append({"combo": indices, "differing_bytes": scored["byte_differences"],
                        "size": scored["size"], "direct_calls": calls, "reload_pairs": reloads})
print(json.dumps(records, indent=2))

