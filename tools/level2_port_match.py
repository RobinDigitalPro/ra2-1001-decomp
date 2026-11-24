"""Find where functions compiled from an upstream decompilation (e.g. mischa85 RA2 1.006) sit in OUR GAME.EXE 1.001.

usage: level2_port_match.py <obj dir> <out json> [--extra-starts[=<json>]]
       (or env L2_EXTRA_STARTS=1 / =<json>; default json W/analysis/level2/extra_starts.json from level2_scan_starts.py)

For every function COMDAT in every object, candidate addresses are our known or aligned function starts whose
first bytes agree with the compiled bytes at positions not covered by relocations.  A candidate is a byte match
when match_function reports no byte differences and no relocation-shape problems.  Bindings are NOT verified
here; level2_check.py verifies them after integration.  Functions matching at more than one address are listed
as ambiguous and are not proposed.

With --extra-starts (off by default; default behaviour is unchanged) the padding-bounded starts of
level2_scan_starts.py are added as candidates (this adds the few non-16-aligned ones), and small functions
(L2_SMALL_MIN=4 .. 7 bytes, skipped by default) are matched too, but only at evidence starts (Ghidra index,
function_map, claims, extra starts) whose original next byte is fill or another start.  Small matches carry
"small": true; small ones with more than 16 addresses are only counted under "small_ambiguous".  Entries with
a hit at an extra start list it under "via_extra".
"""
import collections, glob, json, os, struct, sys
W = r'D:\<work-root>\RedAlert2Temp'
sys.path.insert(0, os.path.join(W, 'analysis', 'level2')); sys.path.insert(0, os.path.join(W, 'tools'))
import level2_check
from coffmatch import Obj, match_function

B, secs = level2_check.image()
text = next(s for s in secs if s[0] == '.text')
tbase, tsize = 0x400000 + text[1], min(text[2], text[3])
tbytes = level2_check.read(B, secs, tbase, tsize)
SHA = level2_check.SHA
starts = {int(json.loads(l)['rva'], 16) + 0x400000 for l in open(level2_check.FUNCS)}
starts |= {int(f['rva'], 16) + 0x400000 for f in json.load(open(os.path.join(W, 'analysis', 'level2', 'function_map.json')))['map']}
for off in range(0, tsize, 16):   # every 16-byte aligned address (function_map misses starts; VC6/-Gy COMDATs are 16-aligned)
    starts.add(tbase + off)
EXTRA = None
for i, x in enumerate(sys.argv[3:]):
    if x.startswith('--extra-starts'):
        EXTRA = x.split('=', 1)[1] if '=' in x else ''
if EXTRA is None and os.environ.get('L2_EXTRA_STARTS'):
    EXTRA = '' if os.environ['L2_EXTRA_STARTS'] == '1' else os.environ['L2_EXTRA_STARTS']
extra = set()
if EXTRA is not None:
    ej = EXTRA or os.path.join(W, 'analysis', 'level2', 'extra_starts.json')
    extra = {int(x['rva'], 16) + 0x400000 for x in json.load(open(ej))['starts']}
    evid = {int(json.loads(l)['rva'], 16) + 0x400000 for l in open(level2_check.FUNCS)}
    evid |= {int(f['rva'], 16) + 0x400000 for f in json.load(open(os.path.join(W, 'analysis', 'level2', 'function_map.json')))['map']}
    evid |= {int(x['rva'], 16) + 0x400000 for x in json.load(open(os.path.join(level2_check.P, 'metadata', 'level2_functions.json'), encoding='utf-8'))}
    evid |= extra
    evid = sorted(a for a in evid if tbase <= a < tbase + tsize)
    starts |= extra
    SMALL_MIN = int(os.environ.get('L2_SMALL_MIN', '4'))
    print('extra starts', len(extra), 'from', ej, flush=True)
starts = sorted(a for a in starts if tbase <= a < tbase + tsize)
K = 4
index = {L: collections.defaultdict(list) for L in (4, 2, 1)}
for a in starts:
    for L in (4, 2, 1):
        index[L][tbytes[a - tbase:a - tbase + L]].append(a)

def candidates(raw, relocs):
    masked = set(o + k for o, _, _ in relocs for k in range(4))
    for L in (4, 2, 1):
        if len(raw) >= L and all(i not in masked for i in range(L)):
            pool = index[L].get(bytes(raw[:L]), [])
            return [a for a in pool if all(tbytes[a - tbase + i] == raw[i] for i in range(min(16, len(raw))) if i not in masked and a - tbase + i < tsize)]
    return [a for a in starts if all(tbytes[a - tbase + i] == raw[i] for i in range(min(16, len(raw))) if i not in masked and a - tbase + i < tsize)]

def small_candidates(raw, relocs):
    """small functions: evidence starts only, full non-relocation byte equality, original ends at fill/start"""
    masked = set(o + k for o, _, _ in relocs for k in range(4))
    n = len(raw); res = []
    pool = evid2.get(bytes(raw[:2]), []) if 0 not in masked and 1 not in masked else evid
    for a in pool:
        o = a - tbase
        if o + n >= tsize or any(tbytes[o + i] != raw[i] for i in range(n) if i not in masked):
            continue
        if tbytes[o + n] in (0x90, 0xCC) or (a + n) % 16 == 0 or (a + n) in evidset:
            res.append(a)
    return res


evidset = set(evid) if EXTRA is not None else set()
evid2 = collections.defaultdict(list)
for a in sorted(evidset):
    evid2[tbytes[a - tbase:a - tbase + 2]].append(a)
out = dict(schema='level2_port_match_v1', binary_sha256=SHA, objects={})
if EXTRA is not None:
    out['extra_starts'] = len(extra)
for objpath in sorted(glob.glob(os.path.join(sys.argv[1], '*.obj'))):
    try:
        o = Obj(open(objpath, 'rb').read())
    except Exception as e:
        out['objects'][os.path.basename(objpath)] = dict(error=str(e)); continue
    res = []
    for name, sym in o.symbols.items():
        if sym['value'] != 0:
            continue
        sec = o.sections[sym['section'] - 1]
        raw = sec['raw']
        small = len(raw) < 8
        if small and (EXTRA is None or len(raw) < SMALL_MIN):   # too small to place uniquely by bytes alone
            continue
        hits = []
        for a in (small_candidates(raw, sec['relocs']) if small else candidates(raw, sec['relocs'])):
            if a - tbase + len(raw) > tsize:
                continue
            r = match_function(o, name, tbytes[a - tbase:a - tbase + len(raw)], a, lambda s: None)
            if r['byte_differences'] == 0 and not r['relocation_problems']:
                hits.append(a)
        if hits:
            e = dict(symbol=name, size=len(raw), rvas=[hex(a - 0x400000) for a in hits])
            if small:
                e['small'] = True
                if len(hits) > 16:
                    out.setdefault('small_ambiguous', {})[os.path.basename(objpath) + ':' + name] = len(hits)
                    continue
            if extra & set(hits):
                e['via_extra'] = [hex(a - 0x400000) for a in hits if a in extra]
            res.append(e)
    out['objects'][os.path.basename(objpath)] = dict(functions=res)
    print(os.path.basename(objpath), len(res), sum(1 for x in res if len(x['rvas']) == 1), flush=True)
json.dump(out, open(sys.argv[2], 'w'), indent=0)
u = [x for v in out['objects'].values() for x in v.get('functions', []) if len(x['rvas']) == 1]
print('unique matches', len(u), 'bytes', sum(x['size'] for x in u))
