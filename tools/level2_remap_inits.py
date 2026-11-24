"""Re-map the _$E initializer claims of given TUs to their compiled symbols by byte content.
usage: level2_remap_inits.py <tu path relative to P> ...   (e.g. src/ra2/WorldDom.cpp)"""
import json, os, sys
P = r'D:\<project-folder>\Coding\RedAlert2'
W = r'D:\<work-root>\RedAlert2Temp'
sys.path.insert(0, os.path.join(W, 'analysis', 'level2')); sys.path.insert(0, os.path.join(W, 'tools'))
import l2match, level2_check
from coffmatch import Obj, match_function
fp = os.path.join(P, 'metadata', 'level2_functions.json')
funcs = json.load(open(fp, encoding='utf-8'))
for tu in sys.argv[1:]:
    claims = [f for f in funcs if f['tu'] == tu and f['symbol'].startswith('_$E')]
    agentfile = os.path.join(W, 'analysis', 'level2', 'agents', os.path.splitext(os.path.basename(tu))[0] + '.claims.json')
    fixed = {}
    if os.path.exists(agentfile):
        fixed = {hex(int(c['rva'], 16)): c['symbol'] for c in json.load(open(agentfile))['functions'] if c['symbol'].startswith('_$E')}
    for f in claims:
        if f['rva'] in fixed:
            f['symbol'] = fixed[f['rva']]
    claims_fixed = [f for f in claims if f['rva'] in fixed]
    claims = [f for f in claims if f['rva'] not in fixed]
    obj, info = level2_check.compile_tu(tu, os.path.join(W, 'build', 'level2'))
    if info['returncode'] != 0:
        print('compile failed', tu); continue
    o = Obj(open(obj, 'rb').read())
    es = sorted([k for k in o.symbols if k.startswith('_$E')], key=lambda k: int(k[3:]))
    used, changed, missing = set(f['symbol'] for f in claims_fixed), 0, 0
    for f in sorted(claims, key=lambda f: int(f['rva'], 16)):
        rva = int(f['rva'], 16); hit = None
        for e in es:
            if e in used:
                continue
            code = o.function(e)['raw']
            r = match_function(o, e, l2match.orig(rva, len(code)), 0x400000 + rva, lambda s: None)
            if r['byte_differences'] == 0 and not r['relocation_problems']:
                hit = e; break
        if hit is None:
            missing += 1; continue
        used.add(hit)
        if f['symbol'] != hit:
            f['symbol'] = hit; changed += 1
    print(tu, 'claims', len(claims), 'remapped', changed, 'unmatched', missing)
json.dump(funcs, open(fp, 'w', encoding='utf-8'), indent=1)
