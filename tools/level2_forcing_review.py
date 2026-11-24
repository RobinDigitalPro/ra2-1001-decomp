"""Classify a forcing-audit result: which findings are OUR constructs inside CLAIMED functions.

usage: python -I level2_forcing_review.py <audit_<utc>.json>

User decision 2026-11-23 (stocktake, step 1). For each finding of level2_forcing_audit.py:
  - origin 'upstream' when the same stripped source line occurs in the upstream file of that name
    (mischa85 RA2 1.006 checkout, src/<name> or include/<name>), otherwise 'ours' (every src/ra2 finding is ours);
  - claimed when the enclosing function (heuristic name, Class::Name or Name) belongs to a claim of that TU;
  - C4127 is kept only when its source line holds a constant 0/false condition (while (1)/for (;;) loops are normal);
  - strength: 'strong' (const-condition, member-pointer-local, ghidra-name, volatile-local, void-cast-statement,
    C4101, C4189, empty-control-block, inferred-helper-single-use, same-statement-both-arms, inline-asm, C4702),
    'weak' (bare-block, numbered-temp).
Writes W/analysis/level2/forcing_audit/rematch_<utc>.json (ours + claimed, the REMATCH list) and prints counts.
Read-only on P.
"""
import collections, json, os, re, sys
P = r'D:\<project-folder>\Coding\RedAlert2'; W = r'D:\<work-root>\RedAlert2Temp'
UP = os.path.join(W, 'analysis', 'references_gpl_20261118', 'mischa85_RedAlert2')
A = json.load(open(sys.argv[1], encoding='utf-8'))
F = json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))
STRONG = {'const-condition', 'member-pointer-local', 'ghidra-name', 'volatile-local', 'void-cast-statement', 'C4101', 'C4189',
          'empty-control-block', 'inferred-helper-single-use', 'same-statement-both-arms', 'inline-asm', 'C4702', 'C4127'}
byname = collections.defaultdict(set)
for f in F:
    s = f['symbol']
    m = re.match(r'^\?\?[01]([^@]+)@', s)
    if m:
        byname[f['tu']].update({'%s::%s' % (m.group(1), m.group(1)), '%s::~%s' % (m.group(1), m.group(1))})
        continue
    m = re.match(r'^\?([^@?]+)@([^@]*)@', s)
    if m:
        byname[f['tu']].add('%s::%s' % (m.group(2), m.group(1)) if m.group(2) else m.group(1))
        byname[f['tu']].add(m.group(1))
upcache = {}


def upstream_lines(tu):
    name = os.path.basename(tu)
    if name in upcache:
        return upcache[name]
    s = set()
    if tu.startswith('src/m85/'):
        for d in ('src', 'include'):
            p = os.path.join(UP, d, name)
            if os.path.exists(p):
                s = {re.sub(r'\s+', ' ', l.strip()) for l in open(p, encoding='latin-1')}
                break
    upcache[name] = s
    return s


rows, c = [], collections.Counter()
for tu, r in A['tus'].items():
    src = open(os.path.join(P, tu.replace('/', os.sep)), encoding='latin-1').read().split('\n')
    ups = upstream_lines(tu)
    items = [dict(line=w['line'], kind=w['code'], function=None, text=src[w['line'] - 1].strip()[:160] if w['line'] <= len(src) else '') for w in r['warnings']]
    items += r['patterns']
    for it in items:
        if it['kind'] == 'C4127' and not re.search(r'\b(if|while)\s*\(\s*(0|false|FALSE)\s*\)', it['text']):
            continue
        fn = it.get('function') or '?'
        if fn == '?':   # warnings carry no function: find the enclosing definition the same way the audit does
            for j in range(it['line'] - 1, -1, -1):
                m = re.match(r'^[A-Za-z_][\w\s\*&:<>,~]*?\b([\w:~]+)\s*\([^;]*\)\s*(const)?\s*(//.*)?$', src[j])
                if m and j + 1 < len(src) and src[j + 1].strip().startswith('{'):
                    fn = m.group(1); break
        origin = 'upstream' if re.sub(r'\s+', ' ', src[it['line'] - 1].strip()) in ups else 'ours'
        claimed = fn in byname[tu] or fn.split('::')[-1] in byname[tu]
        strength = 'strong' if it['kind'] in STRONG else 'weak'
        c[(origin, claimed, strength)] += 1
        if origin == 'ours' and claimed:
            rows.append(dict(tu=tu, line=it['line'], kind=it['kind'], function=fn, strength=strength, text=it['text']))
out = sys.argv[1].replace('audit_', 'rematch_')
json.dump(rows, open(out, 'w', encoding='utf-8'), indent=1)
for k, v in sorted(c.items()):
    print('%-8s claimed=%-5s %-6s %d' % (k[0], k[1], k[2], v))
k2 = collections.Counter((r['strength'], r['kind']) for r in rows)
print('REMATCH (ours, claimed):', len(rows), '| strong', sum(1 for r in rows if r['strength'] == 'strong'))
for (s, k), v in k2.most_common():
    print('  %s %s %d' % (s, k, v))
print('functions:', len({(r['tu'], r['function']) for r in rows if r['strength'] == 'strong'}), 'with strong findings')
print('json:', out)
