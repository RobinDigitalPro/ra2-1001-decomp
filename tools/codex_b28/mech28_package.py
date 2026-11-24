from pathlib import Path
import json, sys, hashlib, shutil
src=Path(sys.argv[1])/"source"
out=src.parent/"output"
kit=Path(sys.argv[2])
inp=src.parents[2]/"input"/"mech.cpp"
assert inp.exists()
sys.path[:0]=[str(kit/"tools"),str(kit)]
from l2match import orig
from coffmatch import Obj, match_function
sy="?Movement_AI@MechLocomotionClass@@AAEX_N@Z"
def diff(sec):
    raw=sec["raw"]
    reference=orig(0x18e7a0,len(raw))
    mask={x for off,_,kind in sec["relocs"] for x in range(off,off+4)}
    return {i for i,c in enumerate(raw) if i not in mask and c!=reference[i]}
objs=[Obj((src.parent/"temp"/name).read_bytes()) for name in ("confirmed.obj","candidate.obj")]
lost, gain = [diff(obj.function(sy)) for obj in objs]
print("Recovered offsets",list(map(hex,sorted(lost-gain))),"new differences",list(map(hex,sorted(gain-lost))))
meta=json.loads((kit/"meta"/"level2_functions.json").read_text())
rows=[r for r in meta if r.get("tu")=="src/m85/src/mech.cpp"]
print("TU metadata rows",len(rows))
for obj in objs:
    from collections import Counter
    stats=Counter()
    for row in rows:
        sym=row["symbol"]
        if sym not in obj.symbols:
            stats["absent"]+=1
            continue
        rv=row["rva"]
        rv=int(rv,0) if isinstance(rv,str) else rv
        sec=obj.function(sym)
        stats[match_function(obj,sym,orig(rv,len(sec["raw"])),0x400000+rv,lambda s:None)["status"]]+=1
    print("metadata",stats)
shutil.copyfile(src/"mech28_slots.best.cpp",out/"mech.cpp")
print("output sha256",hashlib.sha256((out/"mech.cpp").read_bytes()).hexdigest())
shutil.copyfile(src/"kitrun.py",out/"tools"/"mech28_kitrun.py")
for sp in sorted(src.glob("mech28_*.json")):
    dat=json.loads(sp.read_text())
    dat["base"]=str(inp)
    (out/sp.name).write_text(json.dumps(dat,indent=2)+"\n",encoding="utf-8")
    results=sp.with_suffix(".results.jsonl")
    shutil.copyfile(results,out/results.name)
    logs=[json.loads(s) for s in results.read_text().splitlines() if s.strip()]
    usable=[r for r in logs if r.get("controls_ok") and isinstance(r.get("score"),int)]
    print(sp.stem, len(logs),len(usable),min(r["score"] for r in usable),len(set(r["hash"] for r in logs)),[entry["name"] for entry in dat["choices"]])

