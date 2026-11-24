"""Compare the two WinMain objects' direct-call vectors by their COFF references.
Usage: python -I win_callcheck.py KIT BASELINE_OBJ SPLIT_OBJ
"""
import sys, json
from pathlib import Path
kit = Path(sys.argv[1])
sys.path[:0] = [str(kit/'tools'), str(kit)]
import capstone, l2match
from coffmatch import Obj

def summarize(path):
    obj=Obj(Path(path).read_bytes())
    sec=obj.function('_WinMain@16')
    rel={off:obj.by_index[index]['name'] for off,index,typ in sec['relocs'] if typ==0x14}
    dis=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    direct=[]
    other=[]
    instructions=list(dis.disasm(sec['raw'],0))
    for inst in instructions:
        if inst.address+1 in rel and inst.bytes[0] in (0xe8,0xe9):
            if inst.mnemonic=='call':
                direct.append(rel[inst.address+1])
            else:
                other.append({'offset':hex(inst.address),'instruction':inst.mnemonic})
    return direct, other, len(rel)
a,b=[summarize(path) for path in sys.argv[2:4]]
ref=l2match.orig(0x283970,10080)
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
refcount=sum(i.mnemonic=='call' and i.bytes[0]==0xe8 for i in md.disasm(ref,0))
print(json.dumps(dict(reference_direct_calls=refcount,baseline_direct_calls=len(a[0]),
    split_direct_calls=len(b[0]),identical_ordered_direct_call_symbols=a[0]==b[0],
    baseline_rel32=a[2],split_rel32=b[2],baseline_other_rel32=a[1],split_other_rel32=b[1]),indent=2))

