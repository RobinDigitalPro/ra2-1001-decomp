import argparse
import sys
from collections import Counter
from pathlib import Path

parser = argparse.ArgumentParser(description="Compare VC6 walk movement frame, direct constructors and virtual speed sites.")
parser.add_argument("kit", type=Path)
parser.add_argument("object", type=Path)
parser.add_argument("--baseline", type=Path, help="Optional input object for every named COFF function and relocation check")
args = parser.parse_args()
sys.path[:0] = [str(args.kit), str(args.kit / "tools")]
import capstone
from coffmatch import Obj
import l2match

obj = Obj(args.object.read_bytes())
needle = "Movement_AI@Walk"
name, = [n for n in obj.symbols if needle in n]
section = obj.function(name)
cs = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)

def show(label, raw, start, names):
    instructions = list(cs.disasm(raw, start))
    ctors = []
    sites = []
    direct = 0
    for i in instructions:
        if i.mnemonic == "call" and i.op_str.startswith("0x"):
            direct += 1
            target = names.get(i.address + 1 - start, i.op_str)
            if "??0?$TPoint3D@H" in target or target == "0x41b630":
                ctors.append(hex(i.address - start))
        if i.mnemonic == "call" and "+ 0x4c8]" in i.op_str:
            sites.append(hex(i.address - start))
    print(label, "direct", direct, "constructors", ctors, "Set_Speed sites", sites,
          "frame", [(i.mnemonic, i.op_str) for i in instructions[:4]])

syms = {offset:obj.by_index[index]["name"] for offset,index,typ in section["relocs"] if typ == 0x14}
show("compiled", section["raw"], 0, syms)
show("1.001", l2match.orig(0x312de0, 0x1370), 0x712de0, {})

def sections(o):
    values = {}
    for symbol in o.symbols:
        try:
            f = o.function(symbol)
        except (KeyError, ValueError, IndexError, TypeError):
            continue
        if not f or not f.get("raw"):
            continue
        values[symbol] = (f["raw"], tuple((at, o.by_index[si]["name"], ty) for at,si,ty in f["relocs"]))
    return values

if args.baseline:
    before = sections(Obj(args.baseline.read_bytes()))
    after = sections(obj)
    changed = sorted(k for k in before.keys() | after.keys() if before.get(k) != after.get(k))
    print("COFF COREDATA baseline", len(before), "candidate",len(after),"changes",changed)
