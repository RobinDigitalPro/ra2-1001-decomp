"""mh.py obj needle rva [show] : real instruction hunks, ignoring relocated absolute operands and branch targets"""
import sys,re,difflib
sys.path.insert(0,r'D:\<work-root>\RedAlert2Temp\analysis\level2');sys.path.insert(0,r'D:\<work-root>\RedAlert2Temp\tools\portable\capstone-5.0.6')
import capstone,l2match
from coffmatch import Obj
o=Obj(open(sys.argv[1],'rb').read());names=[k for k in o.symbols if sys.argv[2] in k];sec=o.function(names[0])
rva=int(sys.argv[3],16);code=sec['raw'];orig=l2match.orig(rva,len(code)+32)
rel=set()
for off,si,typ in sec['relocs']: rel.update(range(off,off+4))
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);md.detail=False
def dis(c,mask):
    out=[]
    for i in md.disasm(c,0):
        s=i.mnemonic+' '+i.op_str
        if i.mnemonic.startswith('j') or i.mnemonic=='call': n=i.mnemonic
        else:
            n=re.sub(r'\[(0x[0-9a-f]+)\]','[A]',s) ; n=re.sub(r', 0x[0-9a-f]{5,}$',', A',n); n=re.sub(r'^(push|mov e..,) 0x[0-9a-f]{5,}$',r'\1 A',n)
            if mask and any(a in rel for a in range(i.address,i.address+i.size)):
                n=re.sub(r'\b0x[0-9a-f]+\b|\b\d+\b','A',n)
        if i.mnemonic=='nop' or s.startswith('int3'): continue
        out.append((i.address,s,n))
    return out
a=dis(code,True);b=dis(orig,False)
# trim orig to our instruction count region (stop at first ret beyond end)
b=b[:len(a)+40]
sm=difflib.SequenceMatcher(None,[x[2] for x in a],[x[2] for x in b],autojunk=False)
ops=[op for op in sm.get_opcodes() if op[0]!='equal']
# drop trailing hunk that is just orig continuing past end
if ops and ops[-1][1]==len(a): ops=ops[:-1]
n=sum(max(i2-i1,j2-j1) for t,i1,i2,j1,j2 in ops)
print('hunks',len(ops),'instrs',n,'len',len(a))
if len(sys.argv)>4:
    for t,i1,i2,j1,j2 in ops:
        print('---',t)
        for x in a[i1:i2]: print('  < %04x %s'%(x[0],x[1]))
        for x in b[j1:j2]: print('  > %04x %s'%(x[0],x[1]))
