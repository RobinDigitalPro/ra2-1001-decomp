# smap.py obj asm funcname rva origframe(hex) : per-symbol mapping ours rel -> orig rel (frame-top relative)
import sys,re,difflib,collections
sys.path.insert(0,r'D:\<work-root>\RedAlert2Temp\analysis\level2');sys.path.insert(0,r'D:\<work-root>\RedAlert2Temp\tools\portable\capstone-5.0.6')
import capstone,l2match
from coffmatch import Obj
objf,asmf,name,rva,ofr=sys.argv[1],sys.argv[2],sys.argv[3],int(sys.argv[4],16),int(sys.argv[5],16)
o=Obj(open(objf,'rb').read());sec=o.function(name);code=sec['raw']
orig=l2match.orig(rva,len(code)+0x40)
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
a=list(md.disasm(code,0)); b=list(md.disasm(orig,0))
t=open(asmf,errors='replace').read()
j=t.find(name+' PROC'); e=t.find(name+' ENDP',j)
hdr=t[t.rfind('_TEXT\tSEGMENT',0,j):j]
syms={m.group(1):int(m.group(2)) for m in re.finditer(r'^(\S+) = (-?\d+)$',hdr,re.M)}
ins=[]
for l in t[j:e].split('\n')[1:]:
    s=l.strip()
    if not s or s.startswith(';') or s.endswith(':') or re.match(r'^\$L\d+:',s) or s.startswith('npad') : continue
    if l.startswith('\t') and not s.startswith(('ORG','ALIGN','DD','DB')): ins.append(s)
# frame size from first sub esp
fr=None
for x in a:
    if x.mnemonic=='sub' and x.op_str.startswith('esp'): fr=int(x.op_str.split(',')[1],0);break
    if x.mnemonic=='mov' and x.op_str.startswith('eax, 0x') and x.address==0: fr=int(x.op_str.split(',')[1],0);break
def mask(i):
    s=i.mnemonic+' '+i.op_str
    s=re.sub(r'esp \+ 0x[0-9a-f]+','esp+S',s); s=re.sub(r'esp\]','esp+S]',s)
    s=re.sub(r'0x[0-9a-f]{3,}','X',s)
    if i.mnemonic.startswith('j') or i.mnemonic=='call': s=i.mnemonic
    return s
sm=difflib.SequenceMatcher(None,[mask(x) for x in a],[mask(x) for x in b],autojunk=False)
res=collections.defaultdict(collections.Counter)
nalign=0
for tag,i1,i2,j1,j2 in sm.get_opcodes():
    if tag!='equal' and not (tag=='replace' and i2-i1==j2-j1): continue
    for k in range(i2-i1):
        x=a[i1+k]; y=b[j1+k]
        if mask(x)!=mask(y) and tag=='equal': continue
        if i1+k>=len(ins): continue
        al=ins[i1+k]
        m=re.search(r'(\$T\d+|_\w+\$\d*)\[esp\+(\d+)\]',al)
        mx=re.findall(r'esp \+ (0x[0-9a-f]+)\]',x.op_str); my=re.findall(r'esp \+ (0x[0-9a-f]+)\]',y.op_str)
        if not m or len(mx)!=1 or len(my)!=1: continue
        sym=m.group(1); base=int(m.group(2))
        if sym not in syms: continue
        Xo=int(mx[0],16); Yo=int(my[0],16)
        field=base-(fr+16)  # depth+field
        # rel of accessed byte: syms+field ; depth unknown but X = fr+16+d+syms+fieldoff ; asm base = fr+16+d+fieldoff
        d_plus_field=base-(fr+16)
        orel=Yo-(ofr+16)-d_plus_field   # orig rel of symbol start (assuming same depth/field)
        res[sym][orel]+=1; nalign+=1
for s in sorted(res,key=lambda s:syms[s]):
    print('%5d %-22s -> %s'%(syms[s],s,dict(res[s])))
print('ours frame',hex(fr),'aligned refs',nalign, 'asm ins',len(ins),'obj ins',len(a))
