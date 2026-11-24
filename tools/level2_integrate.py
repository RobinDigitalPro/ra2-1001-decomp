"""Integrate an agent claims file into P/metadata/level2_*.json (single writer).

usage: level2_integrate.py <claims.json> [...]
- adds claimed functions whose RVA is not yet claimed (status is re-established by level2_check)
- adds symbol evidence entries that do not exist yet; 'crt' without crt_symbol becomes 'function_start';
  symbols that are claimed level-2 functions are skipped (verified by the claim itself)
"""
import json, os, sys
P = r'D:\<project-folder>\Coding\RedAlert2'
fp = os.path.join(P, 'metadata', 'level2_functions.json')
sp = os.path.join(P, 'metadata', 'level2_symbols.json')
funcs = json.load(open(fp, encoding='utf-8'))
syms = json.load(open(sp, encoding='utf-8'))
have = {f['rva'] for f in funcs}
for path in sys.argv[1:]:
    c = json.load(open(path, encoding='utf-8'))
    tu = c['tu']
    newsyms = {f['symbol'] for f in c['functions']}
    added = 0
    for f in c['functions']:
        if f.get('status') not in ('matched', 'bytes_match_bindings_open'):
            continue
        rva = hex(int(f['rva'], 16))
        if rva in have:
            for x in funcs:   # same TU re-claims (e.g. renumbered _$E symbols) replace the old symbol
                if x['rva'] == rva and x['tu'] == tu and x['symbol'] != f['symbol']:
                    x['symbol'] = f['symbol']; x['name'] = f.get('name', x['name']); added += 1
            continue
        funcs.append(dict(rva=rva, tu=tu, symbol=f['symbol'], name=f.get('name', '')))
        have.add(rva); added += 1
    sadded = 0
    for s, e in c.get('symbols', {}).items():
        if s.startswith(('__imp__', '??_C@', '??_7', '__real@')) or s in syms or s in newsyms or any(s == f['symbol'] for f in funcs):
            continue
        e = dict(e)
        if e.get('evidence') == 'crt' and 'crt_symbol' not in e:
            e['evidence'] = 'function_start'
        if e.get('evidence') not in ('function_start', 'crt', 'data', 'guid', 'aligned_start'):
            continue
        e['address'] = hex(int(e['address'], 16) + (0x400000 if int(e['address'], 16) < 0x400000 else 0))   # agents sometimes give RVAs
        e['source'] = os.path.basename(path)
        syms[s] = e; sadded += 1
    print(os.path.basename(path), 'functions added', added, 'symbols added', sadded)
funcs.sort(key=lambda x: int(x['rva'], 16))
json.dump(funcs, open(fp, 'w', encoding='utf-8'), indent=1)
json.dump(syms, open(sp, 'w', encoding='utf-8'), indent=1)
