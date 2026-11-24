import sys, struct,re
from pathlib import Path
kit=Path(sys.argv[1]); sys.path.insert(0,str(kit)); import capstone
p=(kit/"vc6/VC98/BIN/C2.DLL").read_bytes()
u16=lambda o:struct.unpack_from("<H",p,o)[0]
u32=lambda o:struct.unpack_from("<I",p,o)[0]
pe=u32(0x3c); base=u32(pe+52)
sects=[]
for i in range(u16(pe+6)):
    o=pe+24+u16(pe+20)+40*i
    n=p[o:o+8].rstrip(b'\0').decode();v,va,l,f=struct.unpack_from("<IIII",p,o+8)
    sects.append((n,base+va,l,f))
def addr(f):
    return next(v+f-o for _,v,l,o in sects if o<=f<o+l)
def off(a):
    return next(o+a-v for _,v,l,o in sects if v<=a<v+l)
def xref(a):
    return [addr(m.start()) for m in re.finditer(re.escape(struct.pack('<I',a)),p[:max(s[3]+s[2] for s in sects)])]
def incoming(a):
    _,v,l,o=next(s for s in sects if s[0]=='.text'); return [hex(v+m.start()) for m in re.finditer(b'\xe8',p[o:o+l-4]) if (v+m.start()+5+struct.unpack_from('<i',p,o+m.start()+1)[0])&0xffffffff==a]
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
if sys.argv[2]=='paths':
    print(sects)
    for m in re.finditer(rb'E:\\[^\x00]+?\\(?:color|regasg|list|globdf)\.c\x00',p,re.I):
        print(m.group()[-40:],hex(addr(m.start())),[hex(a) for a in xref(addr(m.start()))])
elif sys.argv[2]=='calls':
    for s in sys.argv[3:]:print(s,incoming(int(s,16)))
elif sys.argv[2]=='refs':
    for s in sys.argv[3:]:print(s,[hex(x) for x in xref(int(s,16))])
else:
    a=int(sys.argv[2],16); lim=int(sys.argv[3],16)
    for i in md.disasm(p[off(a):off(a)+lim],a):
        print('%08x %-8s %s'%(i.address,i.mnemonic,i.op_str))

