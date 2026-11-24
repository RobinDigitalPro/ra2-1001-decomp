"""Inspect source-file xrefs and potential 64-bucket tables in a private VC6 backend."""
import argparse
import collections
import re
import struct
import sys
from pathlib import Path

parser = argparse.ArgumentParser()
parser.add_argument("kit", type=Path)
parser.add_argument("command", choices=["scan", "dis", "refs", "file", "imm", "asm"])
parser.add_argument("arg", nargs="?", default="")
parser.add_argument("size", type=lambda x: int(x, 0), nargs="?", default=120)
args = parser.parse_args()
sys.path.insert(0, str(args.kit))
import capstone
data = (args.kit / "vc6/VC98/BIN/C2.DLL").read_bytes()
u16 = lambda p: struct.unpack_from("<H", data, p)[0]
u32 = lambda p: struct.unpack_from("<I", data, p)[0]
pe = u32(0x3c)
base = u32(pe + 52)
sections = []
for i in range(u16(pe + 6)):
    s = pe + 24 + u16(pe + 20) + 40*i
    sections.append((data[s:s+8].rstrip(b"\0"), base + u32(s+12), u32(s+20), u32(s+16)))
def offset(addr):
    return next(o + addr-v for _,v,o,n in sections if v <= addr < v+n)
def va(off):
    return next(v + off-o for _,v,o,n in sections if o <= off < o+n)
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.skipdata = True
_, tv, to, ts = next(s for s in sections if s[0] == b".text")
code = data[to:to+ts]
def refs(key):
    return [tv + m.start() for m in re.finditer(re.escape(struct.pack("<I",key)),code)]
def instructions(addr,n):
    p = offset(addr)
    return md.disasm_lite(data[p:p+n],addr)
if args.command == "file":
    for hit in re.finditer(rb"[A-Za-z]:\\[^\0]{1,180}\\([^\\\0]+)\x00",data,re.I):
        if args.arg.lower() in hit.group(1).decode('ascii','replace').lower():
            a = va(hit.start())
            print(hit.group(1),hex(a),[hex(x) for x in refs(a)])
elif args.command == "dis":
    for a,n,m,o in instructions(int(args.arg,16), args.size):
        print(f"{a:08x}  {m:7} {o}")
elif args.command == "refs":
    key = int(args.arg,16)
    print("absolute", [hex(x) for x in refs(key)])
    print("relative", [hex(tv+i) for i in range(len(code)-5) if code[i] in (0xe8,0xe9) and tv+i+5+struct.unpack_from("<i",code,i+1)[0]==key])
elif args.command == "asm":
    for a,n,m,o in md.disasm_lite(code,tv):
        if re.search(args.arg, m+" "+o):
            print(f"{a:08x} {m} {o}")
else:
    print("Image sections", sections)
    for a,n,m,o in md.disasm_lite(code,tv):
        if m == "and" and o.endswith(", 0x3f") and args.command == "scan" or args.command=="imm" and o.endswith(", "+args.arg):
            nxt = list(instructions(a+n,35))[:7]
            print(f"{a:08x} {m} {o} | "+"; ".join(m+" "+o for a,n,m,o in nxt))
