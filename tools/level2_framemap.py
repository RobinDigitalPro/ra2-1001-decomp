# emap.py obj [bprel-obj] : map our ebp offsets to 1.001 ebp offsets via aligned instructions
import sys,re,difflib,collections,subprocess
sys.path.insert(0,r'D:\<work-root>\RedAlert2Temp\analysis\level2');sys.path.insert(0,r'D:\<work-root>\RedAlert2Temp\tools\portable\capstone-5.0.6')
import capstone,l2match
from coffmatch import Obj
o=Obj(open(sys.argv[1],'rb').read());names=[k for k in o.symbols if 'WinMain' in k];sec=o.function(names[0])
code=sec['raw'];orig=l2match.orig(0x283970,0x2756)
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
a=list(md.disasm(code,0));b=list(md.disasm(orig,0))
def norm(i):
    s=i.mnemonic+' '+i.op_str
    if i.mnemonic.startswith('j') or i.mnemonic=='call': return i.mnemonic
    s=re.sub(r'ebp( \+ e..)? - 0x[0-9a-f]+','ebp\1-F',s)
    s=re.sub(r'0x[0-9a-f]{5,}','A',s)
    return s
def offs(i):
    return [int(m.group(2),16) for m in re.finditer(r'ebp( \+ e..)? - (0x[0-9a-f]+)',i.op_str)]
sm=difflib.SequenceMatcher(None,[norm(x) for x in a],[norm(x) for x in b],autojunk=False)
m=collections.defaultdict(collections.Counter)
for t,i1,i2,j1,j2 in sm.get_opcodes():
    if t=='equal':
        for k in range(i2-i1):
            for p,q in zip(offs(a[i1+k]),offs(b[j1+k])): m[p][q]+=1
names={}
if len(sys.argv)>2:
    for l in open(sys.argv[2]):
        f=l.split()
        if len(f)==2 and f[0].startswith('-0x'): names[int(f[0],16)]=f[1]
print('ours    -> 1.001  (delta) name')
for p in sorted(m):
    q=m[p].most_common(1)[0][0]
    print('-%-6x -> -%-6x (%+d) %s %s'%(p,q,q-p,names.get(p,''),'' if len(m[p])==1 else dict(m[p])))
print('unmatched orig offsets:',sorted(set(o2 for i in b for o2 in offs(i))-set(q for p in m for q in m[p])))
