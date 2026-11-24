"""Survey compiler register choices for copies of one static object in matching TU claims.

Example: python -I level2_copyregisters.py --kit KIT --obj foot.obj --tu src/m85/src/foot.cpp
         --symbol '?CELL_NONE@@3VCell@@B' --output foot28_copyregisters.json
Only relocation-backed 32-bit MOV loads followed by a first use storing the same complete
register to memory in the same basic block are called copies. Output offsets are relative
to each function. Claims are validated using the kit's relocation-masked matcher.
"""
import argparse
from collections import Counter
import json
from pathlib import Path
import sys

def main():
    p = argparse.ArgumentParser(description=__doc__)
    for name, kind in (("kit", Path), ("obj", Path), ("tu", str), ("symbol", str), ("output", Path)):
        p.add_argument("--" + name, type=kind, required=True)
    args = p.parse_args()
    sys.path[:0] = [str(args.kit / "tools"), str(args.kit)]
    import capstone as cs
    from capstone import x86_const as x86
    import l2match
    from coffmatch import Obj, match_function

    obj = Obj(args.obj.read_bytes())
    claims = json.loads((args.kit / "meta" / "level2_functions.json").read_text(encoding="utf-8"))
    claims = [c for c in claims if c.get("tu", "").replace("\\", "/").lower() == args.tu.lower()]
    md = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_32)
    md.detail = True
    states = Counter()
    copies = []
    registers = Counter()
    sources = Counter()
    for claim in claims:
        symbol, rva = claim["symbol"], int(claim["rva"], 16)
        if symbol not in obj.symbols:
            states["missing"] += 1
            continue
        section = obj.function(symbol)
        original = l2match.orig(rva, len(section["raw"]))
        check = match_function(obj, symbol, original, 0x400000 + rva, lambda _: None)
        states[check["status"]] += 1
        if check["status"] not in ("matched", "bytes_match_bindings_open"):
            continue
        offsets = {off for off, index, typ in section["relocs"]
                   if typ == 6 and obj.by_index[index]["name"] == args.symbol}
        if not offsets:
            continue
        insns = list(md.disasm(original, 0))
        entries = {ins.operands[0].imm for ins in insns if ins.group(cs.CS_GRP_JUMP)
                   and ins.operands[0].type == x86.X86_OP_IMM}
        for i, load in enumerate(insns):
            if load.address + load.disp_offset not in offsets or load.mnemonic != "mov":
                continue
            dst, src = load.operands
            if (dst.type != x86.X86_OP_REG or dst.size != 4 or src.type != x86.X86_OP_MEM
                    or src.mem.base or src.mem.index):
                continue
            reg = dst.reg
            register = load.reg_name(reg)
            # A partial-register read or write ends a candidate as well.
            families = {"eax": {"eax", "ax", "al", "ah"}, "ecx": {"ecx", "cx", "cl", "ch"},
                        "edx": {"edx", "dx", "dl", "dh"}, "ebx": {"ebx", "bx", "bl", "bh"},
                        "esi": {"esi", "si"}, "edi": {"edi", "di"}, "ebp": {"ebp", "bp"},
                        "esp": {"esp", "sp"}}
            aliases = families[register]
            for use in insns[i + 1:]:
                if use.address in entries or any(use.group(g) for g in
                        (cs.CS_GRP_JUMP, cs.CS_GRP_CALL, cs.CS_GRP_RET)):
                    break
                operands = use.operands
                if (use.mnemonic == "mov" and operands[0].type == x86.X86_OP_MEM
                        and operands[0].size == 4 and operands[1].type == x86.X86_OP_REG
                        and operands[1].reg == reg):
                    address = hex(src.mem.disp & 0xffffffff)
                    copies.append(dict(function=symbol, rva=hex(rva), load=hex(load.address),
                                       store=hex(use.address), register=register, address=address))
                    registers[register] += 1
                    sources[address] += 1
                    break
                reads, writes = use.regs_access()
                if any(use.reg_name(v) in aliases for v in (*reads, *writes)):
                    break
    result = dict(tu=args.tu, static_symbol=args.symbol, claims=len(claims), states=states,
                  copies=len(copies), registers=registers, addresses=sources, sites=copies)
    args.output.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({k:v for k,v in result.items() if k != "sites"}, indent=2))

if __name__ == "__main__":
    main()

