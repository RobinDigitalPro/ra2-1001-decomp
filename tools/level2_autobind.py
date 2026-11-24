"""Propose evidence entries for code-address bindings reported as 'no evidence' in the latest check report.
Only addresses inside .text are considered; the entry kind is function_start (address in the Ghidra index or
the function map) or aligned_start otherwise.  level2_check.py verifies every entry independently."""
import glob, json, os
P = r'D:\<project-folder>\Coding\RedAlert2'
W = r'D:\<work-root>\RedAlert2Temp'
import sys
DATA = '--data' in sys.argv
rep = json.load(open(sorted(glob.glob(os.path.join(W, 'analysis', 'level2', 'reports', 'check_*.json')))[-1]))
SHA = '7fe00ee313b38b22e68d6c05aede041018206e29b71f5db9cc1afacc61588c6e'
starts = {int(json.loads(l)['rva'], 16) + 0x400000 for l in open(os.path.join(W, 'analysis', 'functions_%s.jsonl' % SHA))}
starts |= {int(f['rva'], 16) + 0x400000 for f in json.load(open(os.path.join(W, 'analysis', 'level2', 'function_map.json')))['map']}
sp = os.path.join(P, 'metadata', 'level2_symbols.json')
syms = json.load(open(sp, encoding='utf-8'))
added = 0
for f in rep['functions']:
    for b in f.get('bindings', []):
        if b['verified'] or b['evidence'] != 'no evidence' or b['symbol'] in syms or b['symbol'].startswith(('_$', '__imp__', '??_C@')):
            continue
        a = int(b['address'], 16)
        if 0x401000 <= a < 0x785000:
            syms[b['symbol']] = dict(address=hex(a), evidence='function_start' if a in starts else 'aligned_start',
                                     note='auto-bound call target (level2_autobind.py); verified by level2_check')
        elif DATA and b['symbol'].startswith(('?', '_')) and not b['symbol'].startswith('??_'):
            syms[b['symbol']] = dict(address=hex(a), evidence='data',
                                     note='auto-bound data address from the original operand (level2_autobind.py --data); section verified by level2_check, consistency by conflict detection')
        else:
            continue
        added += 1
json.dump(syms, open(sp, 'w', encoding='utf-8'), indent=1)
print('evidence entries added', added)
