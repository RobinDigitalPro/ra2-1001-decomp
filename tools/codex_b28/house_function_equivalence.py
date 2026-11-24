import sys,re,json
from pathlib import Path
kit=Path(sys.argv[1])
sys.path.insert(0,str(kit/'tools'))
from coffmatch import Obj
def content(path):
    o=Obj(Path(path).read_bytes())
    def rel(i,section):
        v=o.by_index[i]
        if v['section']==section and v['storage'] in [3,6] and v['name'].startswith('$'):
            return ('label',v['value'])
        return v['name']
    return {n:(f['raw'],[(off,typ,rel(i,s['section'])) for off,i,typ in f['relocs']]) for n,s in o.symbols.items() for f in [o.function(n)]}
a,b=[content(p) for p in sys.argv[2:4]]
print('Function sets',len(a),len(b),'symmetric difference',set(a)^set(b))
diff=[n for n in sorted(set(a)&set(b)) if a[n]!=b[n]]
print('Different sections or normalized relocs',len(diff))
for n in diff[:20]:print(n)
