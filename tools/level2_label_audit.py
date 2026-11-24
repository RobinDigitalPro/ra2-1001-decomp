"""Label audit: addresses that the project knows under two different function names.

usage: python -I level2_label_audit.py

User decision 2026-11-23 (stocktake, step 1). For every claimed function in P/metadata/level2_functions.json
(rva, symbol, tu) this lists the P/metadata/level2_symbols.json entries that point to the same address
(VA = 0x400000 + rva) under a symbol with a different class or function name. Such a pair is either a
legitimate alias (one body under two names, for example identical-COMDAT folding, or a call through a
declaration in another TU) or a wrong label/binding.
Also listed: claimed rvas that occur twice in level2_functions.json, and symbol entries whose address is
claimed while their own claimed address differs (one symbol, two addresses).
Read-only. Output: W/analysis/level2/forcing_audit/labels_<utc>.json and a summary on stdout.
"""
import collections, datetime, json, os, re
P = r'D:\<project-folder>\Coding\RedAlert2'; W = r'D:\<work-root>\RedAlert2Temp'
F = json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))
S = json.load(open(os.path.join(P, 'metadata', 'level2_symbols.json'), encoding='utf-8'))


def parts(sym):
    """(class, name) from an MSVC mangled name, roughly; None for compiler-generated names."""
    if sym.startswith(('_$E', '$')) or not sym.startswith('?'):
        return None
    m = re.match(r'^\?\?([0-9A-Z_])([^@]+)@', sym)        # ??0X ctor, ??1X dtor, ??_G/??_E deleting dtors, operators
    if m:
        cls = re.match(r'^\?\?[0-9A-Z_]{1,2}([^@]+)@', sym)
        return (cls.group(1) if cls else '', '??' + m.group(1))
    m = re.match(r'^\?([^@?]+)@([^@]*)@', sym)
    if m:
        return (m.group(2) if not sym.startswith('?%s@@' % m.group(1)) else '', m.group(1))
    m = re.match(r'^\?([^@?]+)@@', sym)
    return ('', m.group(1)) if m else None


byva = collections.defaultdict(list)
for k, v in S.items():
    if isinstance(v, dict) and 'address' in v:
        try:
            byva[int(v['address'], 16)].append(k)
        except ValueError:
            pass
claimed_rva = collections.Counter(int(f['rva'], 16) for f in F)
claim_of = {}
for f in F:
    claim_of.setdefault(f['symbol'], []).append(int(f['rva'], 16))
pairs, dup, twoaddr = [], [], []
for f in F:
    r = int(f['rva'], 16); va = 0x400000 + r
    if claimed_rva[r] > 1:
        dup.append(f)
    me = parts(f['symbol'])
    for other in byva.get(va, []):
        if other == f['symbol']:
            continue
        op = parts(other)
        if me and op and me != op:
            pairs.append({'rva': f['rva'], 'claimed': f['symbol'], 'tu': f['tu'], 'also': other,
                          'same_name': me[1] == op[1], 'same_class': me[0] == op[0]})
for k, v in S.items():
    if isinstance(v, dict) and k in claim_of:
        try:
            a = int(v['address'], 16) - 0x400000
        except (ValueError, KeyError):
            continue
        if a not in claim_of[k]:
            twoaddr.append({'symbol': k, 'symbol_map': v['address'], 'claimed_rvas': [hex(x) for x in claim_of[k]]})
now = datetime.datetime.utcnow().strftime('%Y-%m-%dT%H%MZ')
out = os.path.join(W, 'analysis', 'level2', 'forcing_audit'); os.makedirs(out, exist_ok=True)
J = os.path.join(out, 'labels_%s.json' % now)
json.dump({'utc': now, 'different_name_same_address': pairs, 'duplicate_claimed_rvas': dup, 'symbol_two_addresses': twoaddr}, open(J, 'w', encoding='utf-8'), indent=1)
c = collections.Counter('both differ' if not (p['same_name'] or p['same_class']) else ('class differs' if p['same_name'] else 'name differs') for p in pairs)
print('claims', len(F), '| symbol entries', len(S))
print('same address, other name:', len(pairs), dict(c))
print('duplicate claimed rvas:', len(dup), '| symbol with an address other than its claim:', len(twoaddr))
for p in [p for p in pairs if not (p['same_name'] or p['same_class'])][:25]:
    print('  %s %s (%s) ALSO %s' % (p['rva'], p['claimed'], p['tu'].split('/')[-1], p['also']))
for t in twoaddr[:10]:
    print('  TWO-ADDR', t)
print('json:', J)
