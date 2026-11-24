"""Read-only audit of selected /Ob2 rule anchors in the licensed VC6 RTM C2.

Run: python -B -I level2_ob2audit.py --kit PATH
Only rule names, parameters, and pass/fail results are printed.
"""

import argparse
import hashlib
import struct
import sys
from pathlib import Path


EXPECTED_SHA256 = "45187b0b6288240f73272a7c61e6329c50048a76e57db3bb87b6f0229e09e27d"


def text_section(image):
    pe = struct.unpack_from("<I", image, 0x3C)[0]
    optional = pe + 24
    base = struct.unpack_from("<I", image, optional + 28)[0]
    count = struct.unpack_from("<H", image, pe + 6)[0]
    table = optional + struct.unpack_from("<H", image, pe + 20)[0]
    for index in range(count):
        pos = table + 40 * index
        if image[pos:pos + 8].rstrip(b"\0") == b".text":
            rva, length, offset = struct.unpack_from("<III", image, pos + 12)
            return base + rva, memoryview(image)[offset:offset + length]
    raise ValueError("Missing PE text section")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--kit", required=True, type=Path)
    args = parser.parse_args()
    kit = args.kit.resolve()
    image = (kit / "vc6/VC98/BIN/C2.DLL").read_bytes()
    if hashlib.sha256(image).hexdigest() != EXPECTED_SHA256:
        parser.exit(2, "Unsupported C2.DLL build. This audit is for VC6 RTM 12.00.8168.\n")
    sys.path.insert(0, str(kit))
    import capstone
    from capstone import x86_const

    address, code = text_section(image)
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    decoder.detail = True

    def instruction(va):
        index = va - address
        return next(decoder.disasm(bytes(code[index:index + 15]), va, count=1))

    def immediate(va):
        return next(op.imm for op in instruction(va).operands if op.type == x86_const.X86_OP_IMM)

    def field(va):
        return next((op.size, op.mem.disp) for op in instruction(va).operands if op.type == x86_const.X86_OP_MEM)

    def operation(va):
        return instruction(va).mnemonic

    checks = {
        "Front-end record provides two-byte size at offset 109":
            field(0x10742344) == (2, 109) and field(0x1072E80A) == (2, 109),
        "Signed size is doubled, root budget clamped to 1000..35000":
            operation(0x1072E80A) == "movsx" and instruction(0x1072E813).op_str == "eax, eax"
            and operation(0x1072E813) == "add" and immediate(0x1072E81C) == 1000
            and immediate(0x1072E815) == 1000 and immediate(0x1072E886) == 35000
            and immediate(0x10793B6D) == 35000,
        "Candidate counter increments on first and later insertions and drops on pop":
            operation(0x1072DF39) == operation(0x1072DDDE) == "inc"
            and operation(0x1072D745) == "dec",
        "Small-size budget exemption includes size 40":
            immediate(0x1072D318) == immediate(0x1072D868) == 40
            and operation(0x1072D31C) == "jle" and operation(0x1072D86C) == "jg",
        "Growth gate rejects strictly above 35000":
            immediate(0x1072D82D) == 35000 and operation(0x1072D837) == "jg",
        "Child budget uses signed division before recursive call":
            operation(0x1072D95E) == "cdq" and operation(0x1072D95F) == "idiv"
            and immediate(0x1072D96B) == 0x1072D288,
        "Parent budget debits recursive consumption and growth adds it":
            operation(0x1072D990) == "sub" and operation(0x1072D992) == "add"
            and field(0x1072D998) == field(0x1072D87A),
    }
    for description, passed in checks.items():
        print(f"{'PASS' if passed else 'FAIL'}  {description}")
    return 0 if all(checks.values()) else 1


if __name__ == "__main__":
    raise SystemExit(main())
