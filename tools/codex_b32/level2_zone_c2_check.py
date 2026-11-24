"""Read-only consistency check on the licensed 8168 backend. Emits observations only."""
import argparse
import hashlib
from pathlib import Path
import struct
import sys


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('kit', type=Path)
    args = parser.parse_args()
    kit = args.kit.resolve()
    sys.path.insert(0, str(kit))
    import capstone
    from capstone import x86_const as x86
    data = (kit/'vc6/VC98/BIN/C2.DLL').read_bytes()
    digest = hashlib.sha256(data).hexdigest()
    if digest != '45187b0b6288240f73272a7c61e6329c50048a76e57db3bb87b6f0229e09e27d':
        parser.error('expected the calibrated 8168 DLL')
    pe = struct.unpack_from('<I', data, 60)[0]
    base = struct.unpack_from('<I', data, pe+52)[0]
    sections = pe + 24 + struct.unpack_from('<H', data, pe+20)[0]
    ranges = [struct.unpack_from('<IIII', data, sections+40*i+8)
              for i in range(struct.unpack_from('<H', data, pe+6)[0])]

    def raw(rva):
        return next(offset+rva-start for _,start,size,offset in ranges if start <= rva < start+size)

    diagnostic = 0xa9110
    name = data[raw(diagnostic):].split(b'\0', 1)[0]
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    decoder.detail = True
    for rva in [0x839df, 0x83a3c]:
        block = list(decoder.disasm(data[raw(rva):raw(rva)+40], base+rva))
        wrap = any(i.mnemonic=='and' and i.operands[0].reg==x86.X86_REG_EDI and
                   i.operands[1].type==x86.X86_OP_IMM and i.operands[1].imm==127 for i in block)
        tag = any(op.type==x86.X86_OP_IMM and op.imm==base+diagnostic for i in block for op in i.operands)
        table = any(op.type==x86.X86_OP_MEM and op.mem.index==x86.X86_REG_EDI and
                    op.mem.scale==4 and op.mem.disp==base+0x9ba18 for i in block for op in i.operands)
        if not (name.endswith(b'p2symtab.c') and wrap and tag and table):
            parser.error(f'expected feature missing at {rva:#x}')
        print(f'RVA {rva:#x}: p2symtab.c diagnostic, 128-value wrap, shared four-byte table at RVA 0x9ba18')
    print(f'File SHA-256 {digest}')


if __name__ == '__main__':
    main()
