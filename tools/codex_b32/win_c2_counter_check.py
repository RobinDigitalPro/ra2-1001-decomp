"""Read VC6 RTM's PE only. Check the operations of its generated-ID allocator.
Reports addresses and operation classes, never compiler instruction bytes.
usage: python -I win_c2_counter_check.py KIT
"""
from pathlib import Path
import hashlib,json,struct,sys
kit=Path(sys.argv[1]);sys.path.insert(0,str(kit));import capstone
data=(kit/'vc6'/'VC98'/'BIN'/'C2.DLL').read_bytes()
digest=hashlib.sha256(data).hexdigest()
assert digest=='45187b0b6288240f73272a7c61e6329c50048a76e57db3bb87b6f0229e09e27d'
pe=struct.unpack_from('<I',data,60)[0]; n=struct.unpack_from('<H',data,pe+6)[0]
opt=struct.unpack_from('<H',data,pe+20)[0]; base=struct.unpack_from('<I',data,pe+52)[0]
def decode(va,nbytes):
    for i in range(n):
        sz,rva,rawsz,raw=struct.unpack_from('<IIII',data,pe+24+opt+40*i+8)
        if 0<=va-base-rva<rawsz:
            start=raw+va-base-rva
            md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);md.detail=True
            return list(md.disasm(data[start:start+nbytes],va))
    raise ValueError(hex(va))
ins=decode(0x10701193,45)
x,test,cond,save,inc,write,ret=ins[:7]
assert [i.mnemonic for i in ins[:7]]==['mov','test','je','mov','inc','mov','ret']
counter=x.operands[1].mem.disp
register=x.operands[0].reg
assert x.operands[1].type==capstone.x86.X86_OP_MEM and not x.operands[1].mem.base
assert test.operands[0].reg==register==test.operands[1].reg
assert save.operands[1].reg==register and save.operands[0].reg==capstone.x86.X86_REG_EAX
assert inc.operands[0].reg==register and write.operands[1].reg==register
assert write.operands[0].mem.disp==counter and not write.operands[0].mem.base
print(json.dumps(dict(dll_sha256=digest,allocator=hex(x.address),counter=hex(counter),read=hex(x.address),increment=hex(inc.address),write=hex(write.address),operand_width_bytes=x.operands[1].size),indent=2))

