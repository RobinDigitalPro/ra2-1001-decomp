"""Compare two /Gy i386 COFF objects with named relocations and one allowed target.

python -I level2_sibling_compare.py --kit KIT input.obj candidate.obj Draw_Depth_Antialiased_Line@DSurface
"""
import argparse
import json
import re
import sys
from pathlib import Path

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--kit',type=Path,required=True)
    p.add_argument('baseline',type=Path)
    p.add_argument('candidate',type=Path)
    p.add_argument('target')
    args=p.parse_args()
    sys.path.insert(0,str(args.kit/'tools'))
    from coffmatch import Obj
    before,after=[Obj(path.read_bytes()) for path in (args.baseline,args.candidate)]
    names=set(before.symbols)
    targets=[n for n in names if args.target in n]
    if len(targets)!=1: raise ValueError(f'Expected one target, saw {targets}')
    def relocation_dest(obj,symbol):
        target=obj.by_index[symbol]
        name=target['name']
        if re.fullmatch(r'\$L\d+',name):
            owners=sorted(n for n,t in obj.symbols.items() if t['section']==target['section'])
            if len(owners)==1: return (owners[0],target['value'])
        return name
    def signature(obj,n):
        sec=obj.function(n)
        return (sec['raw'],[(off,kind,relocation_dest(obj,idx)) for off,idx,kind in sec['relocs']])
    sibling_names=(names & set(after.symbols)) - set(targets)
    changed=[n for n in sorted(sibling_names) if signature(before,n)!=signature(after,n)]
    added=sorted(set(after.symbols)-names); removed=sorted(names-set(after.symbols))
    report=dict(target=targets[0],siblings_compared=len(sibling_names),siblings_changed=changed,
                added_functions=added,removed_functions=removed,
                target_changed=targets[0] in after.symbols and signature(before,targets[0])!=signature(after,targets[0]))
    print(json.dumps(report,indent=2))
    return int(bool(added or removed or changed))
if __name__=='__main__':
    sys.exit(main())

