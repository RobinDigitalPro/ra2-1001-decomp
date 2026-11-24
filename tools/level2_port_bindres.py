"""Resolve ambiguous port matches (same bytes at several addresses) by what their relocations point to.

usage: level2_port_bindres.py <port json> <obj dir> <claims prefix> <tu dir relative to P> [--consistency[=<check report>]]

For each candidate address the relocation targets implied by the original operands are checked with cheap,
content-based tests: string literals by content, RTTI type descriptors (??_R0) by their decorated name, and
symbols that already have an address (claimed functions or the symbol map) by equality. A candidate with a
contradiction is dropped; if exactly one candidate remains and it has at least one positive test, it is
proposed. level2_check.py then verifies everything as usual.

--consistency (off by default; default behaviour unchanged): a symbol that the matched functions of the SAME
module (tu) bind, with verified evidence, to exactly one address in the check report (default: the largest
reports/check_*.json, as level2_auto_round.sh uses) also counts as confirming (+1) or contradicting (-1).  In
this mode the "taken" rule is strict: no claim for a symbol that is already claimed at another RVA, and no claim
at all when two proposals (other symbols or objects) name the same RVA or one symbol is proposed at several RVAs.
"""
import json, os, sys
P = r'D:\<project-folder>\Coding\RedAlert2'
W = r'D:\<work-root>\RedAlert2Temp'
sys.path.insert(0, os.path.join(W, 'analysis', 'level2')); sys.path.insert(0, os.path.join(W, 'tools'))
import level2_check as lc
from coffmatch import Obj, match_function

CONS = None
for x in sys.argv[5:]:
    if x.startswith('--consistency'):
        CONS = x.split('=', 1)[1] if '=' in x else ''
d = json.load(open(sys.argv[1])); objdir, prefix, tudir = sys.argv[2], sys.argv[3], sys.argv[4]
B, secs = lc.image()
funcs = json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))
claimed_at = {int(x['rva'], 16) + 0x400000 for x in funcs}
by_sym = {}
for x in funcs:
    if not x['symbol'].startswith('_$E'):
        by_sym.setdefault(x['symbol'], set()).add(int(x['rva'], 16) + 0x400000)
symmap = json.load(open(os.path.join(P, 'metadata', 'level2_symbols.json'), encoding='utf-8'))
files = {os.path.splitext(n)[0].lower(): n for n in os.listdir(os.path.join(P, *tudir.split('/')))}
tubind = {}   # tu (lower) -> symbol -> set of verified bound addresses (consistency mode only)
if CONS is not None:
    import glob
    rp = CONS or max(glob.glob(os.path.join(W, 'analysis', 'level2', 'reports', 'check_*.json')), key=os.path.getsize)
    nb = 0
    for f in json.load(open(rp))['functions']:
        if f.get('status') != 'matched' or not isinstance(f.get('bindings'), list):
            continue
        for b in f['bindings']:
            if b.get('verified'):
                tubind.setdefault(f['tu'].lower(), {}).setdefault(b['symbol'], set()).add(int(b['address'], 16)); nb += 1
    print('consistency report', os.path.basename(rp), 'tus', len(tubind), 'bindings', nb)


def test(obj, name, addr, tu=None):
    """+1 verified, -1 contradicted, 0 unknown"""
    if name.startswith('??_C@'):
        idx = next((i for i, s in obj.by_index.items() if s['name'] == name and s['section'] > 0), None)
        if idx is None:
            return 0
        lit = obj.sections[obj.by_index[idx]['section'] - 1]['raw']
        return 1 if lc.read(B, secs, addr, len(lit)) == lit else -1
    if name.startswith('??_R0'):
        want = name[5:].rsplit('@8', 1)[0].encode('latin1')   # ??_R0?AVFoo@@@8 -> ?AVFoo@@
        got = lc.read(B, secs, addr + 8, len(want) + 1)
        return 1 if got == b'.' + want else -1
    if name in by_sym:
        return 1 if addr in by_sym[name] else -1
    if name in symmap and not name.startswith('__imp__'):
        return 1 if int(symmap[name]['address'], 16) == addr else -1
    if CONS is not None and tu:
        seen = tubind.get(tu.lower(), {}).get(name)
        if seen and len(seen) == 1:
            return 1 if addr in seen else -1
    return 0


out = {}; taken = set(); total = 0
for o in sorted(d['objects'], key=str.lower):
    amb = [x for x in d['objects'][o].get('functions', []) if len(x['rvas']) > 1 and not x['symbol'].startswith('_$E')]
    if not amb:
        continue
    try:
        obj = Obj(open(os.path.join(objdir, o), 'rb').read())
    except Exception:
        continue
    src0 = files.get(os.path.splitext(o)[0].lower())
    tu = tudir + '/' + src0 if src0 else None
    for x in amb:
        if CONS is not None and x['symbol'] in by_sym:
            continue   # strict taken rule: this symbol is already claimed at another RVA
        good = []
        for r in x['rvas']:
            va = int(r, 16) + 0x400000
            if va in claimed_at or (va in taken and CONS is None):   # consistency mode: duplicates are dropped afterwards
                continue
            raw = obj.function(x['symbol'])['raw']
            m = match_function(obj, x['symbol'], lc.read(B, secs, va, len(raw)), va, lambda s: None)
            score, bad = 0, False
            for b in m['unresolved_bindings']:
                t = test(obj, b['symbol'], int(b['required_address'], 16), tu)
                if t < 0:
                    bad = True; break
                score += t
            if not bad:
                good.append((score, va))
        pos = [g for g in good if g[0] > 0]
        if len(good) == 1 and pos or (len(pos) == 1 and len(good) == 1):
            va = good[0][1]; taken.add(va)
            out.setdefault(o, []).append(dict(rva=hex(va - 0x400000), symbol=x['symbol'], name=x['symbol'], status='bytes_match_bindings_open'))
            total += 1
if CONS is not None:   # strict taken rule: drop RVAs named twice and symbols proposed at several RVAs
    import collections
    byrva = collections.Counter(e['rva'] for fl in out.values() for e in fl)
    bysym = collections.defaultdict(set)
    for fl in out.values():
        for e in fl:
            bysym[e['symbol']].add(e['rva'])
    before = total
    out = {o: [e for e in fl if byrva[e['rva']] == 1 and len(bysym[e['symbol']]) == 1] for o, fl in out.items()}
    out = {o: fl for o, fl in out.items() if fl}
    total = sum(len(fl) for fl in out.values())
    print('strict taken rule dropped', before - total)
n = 0
for o, fl in out.items():
    src = files.get(os.path.splitext(o)[0].lower())
    if not src:
        continue
    json.dump(dict(tu=tudir + '/' + src, functions=fl, symbols={},
                   open=['generated by level2_port_bindres.py (ambiguous byte match resolved by relocation-target content'
                         + (', with same-module binding consistency)' if CONS is not None else ')')]),
              open(os.path.join(W, 'analysis', 'level2', 'agents', '%s_%s.claims.json' % (prefix, os.path.splitext(o)[0])), 'w'), indent=0)
    n += 1
print('resolved', total, 'in', n, 'objects')
