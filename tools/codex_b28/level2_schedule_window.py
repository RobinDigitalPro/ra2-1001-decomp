"""Inspect instruction placement inside a function-relative offset window.

Example (from a copied result folder):
  python -I tools/level2_schedule_window.py KIT missile.obj Projectile_Motion 0x190670 0x210 0x24a sub
Offsets are byte offsets from each function's entry, even if the two bodies differ in size.
"""
import argparse
import sys
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('kit', type=Path)
    parser.add_argument('obj', type=Path)
    parser.add_argument('symbol')
    parser.add_argument('rva', type=lambda x: int(x, 0))
    parser.add_argument('begin', type=lambda x: int(x, 0))
    parser.add_argument('end', type=lambda x: int(x, 0))
    parser.add_argument('mnemonic')
    args = parser.parse_args()
    if not 0 <= args.begin < args.end:
        parser.error('expected 0 <= begin < end')
    sys.path[:0] = [str(args.kit / 'tools'), str(args.kit)]
    import capstone
    import l2match
    from coffmatch import Obj

    obj = Obj(args.obj.read_bytes())
    matches = [name for name in obj.symbols if args.symbol in name]
    if len(matches) != 1:
        parser.error(f'{len(matches)} matching symbols')
    body = obj.function(matches[0])['raw']
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    for label, code in [('object', body), ('reference', l2match.orig(args.rva, args.end))]:
        instructions = list(decoder.disasm(code, 0))
        print(label)
        for index, instruction in enumerate(instructions):
            if args.begin <= instruction.address < args.end and instruction.mnemonic == args.mnemonic:
                for i in range(max(0, index - 1), min(len(instructions), index + 2)):
                    item = instructions[i]
                    print(f'  {item.address:#06x} {item.mnemonic} {item.op_str}')
                print()


if __name__ == '__main__':
    main()
