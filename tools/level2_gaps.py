"""Unmatched .text bytes grouped by the TUs of the matched neighbours.

usage: level2_gaps.py [top]  (merges all check reports like level2_coverage.py)
A gap is a run of non-padding bytes between matched functions. It is attributed to 'A' when both neighbours
belong to TU A (inside a TU), otherwise to 'A | B' (a TU boundary, where an unknown TU may sit).
"""
import collections, json, os, sys
W = r'D:\<work-root>\RedAlert2Temp'
sys.path.insert(0, os.path.join(W, 'analysis', 'level2')); sys.path.insert(0, os.path.join(W, 'tools'))
import level2_check as lc

import glob
P = r'D:\<project-folder>\Coding\RedAlert2'
top = int(sys.argv[1]) if len(sys.argv) > 1 else 40
latest = {}
for path in sorted(glob.glob(os.path.join(W, 'analysis', 'level2', 'reports', 'check_*.json'))):
    for f in json.load(open(path))['functions']:
        latest[f['rva']] = f
claims = {f['rva'] for f in json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))}
fl = [f for r, f in latest.items() if f.get('status') == 'matched' and r in claims]
seen = {f['rva'] for f in fl}
for f in json.load(open(os.path.join(P, 'metadata', 'level2_library.json')))['functions']:
    if f['rva'] not in seen:
        fl.append(dict(rva=f['rva'], size=f['size'], tu='<lib>', status='matched'))
B, secs = lc.image()
text = next(s for s in secs if s[0] == '.text')
tbase, tsize = 0x400000 + text[1], min(text[2], text[3])
tb = lc.read(B, secs, tbase, tsize)
m = sorted((int(f['rva'], 16) + 0x400000, f['size'], f['tu']) for f in fl)
agg = collections.Counter(); big = []
prev_end, prev_tu = tbase, '<start>'
for a, sz, tu in m + [(tbase + tsize, 0, '<end>')]:
    if a > prev_end:
        g = tb[prev_end - tbase:a - tbase]
        n = sum(1 for c in g if c not in (0xCC, 0x90, 0x00))
        if n >= 16:
            key = prev_tu if prev_tu == tu else prev_tu + ' | ' + tu
            agg[key] += n; big.append((n, hex(prev_end - 0x400000), hex(a - 0x400000), key))
    if a + sz > prev_end:
        prev_end, prev_tu = a + sz, tu
print('total unmatched non-pad bytes', sum(agg.values()))
for k, v in agg.most_common(top):
    print('%8d  %s' % (v, k))
print('--- largest single gaps')
for x in sorted(big, reverse=True)[:top]:
    print('%8d  %s..%s  %s' % x)
