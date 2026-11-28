"""List near-equal functions that have a community twin body (gibbo101 YR 1.001, meastes RA2 1.006).

usage: python -I level2_twin_sweep.py [out.md]

Second table (2026-11-28, own2 proposal 1): same-size candidates. For every near-equal entry, community functions
whose size is within 8 bytes of ours: gibbo101 data/progress.csv MATCH rows (YR 1.001) and meastes
manifests/function_map.csv rows flagged exact (RA2 1.006), closest first, at most 6. Size alone proves nothing;
confirm by a distinctive field/global the body reads, then port and check.

Proposal of Claude agents plot1/tiles1 (2026-11-28): three near-equal functions closed in minutes by porting a
matched same-version community twin whole (GUIDE W1, L45, L47). This lists, for every entry in
P/metadata/level2_near_equal.json, which community files contain a body for the same Class::Name, with the body
size in lines, gibbo101's own result for that name (data/progress.csv, e.g. MATCH) and whether the body carries a GAMEMD/YR address marker (a hint for a same-version twin).
Read-only; no compiles. A twin's existence does not prove a match: the port is still checked by level2_check.
Community files: W/analysis/level2/ctx44g/gibbo*.cpp, ctx42/meastes1006_*.cpp, plus the current read-only checkouts in
W/analysis/references_gpl_20261118 (named src folders only, see GIBBO_DIRS/MEASTES_DIRS below).
"""
import glob, json, os, re, sys
P = r'D:\OneDrive - RDI\Coding\RedAlert2'
W = r'D:\CodexTemp\RedAlert2Temp'
L = os.path.join(W, 'analysis', 'level2')
sys.path.insert(0, os.path.join(W, 'tools'))


def parts(sym):
    m = re.match(r'^\?\?([01])([^@]+)@', sym)
    if m:
        return m.group(2), ('~' if m.group(1) == '1' else '') + m.group(2)
    m = re.match(r'^\?([^@?]+)@([^@]*)@', sym)
    if m:
        return m.group(2) or None, m.group(1)
    if '::' in sym:
        c, n = sym.rsplit('::', 1)
        return c.split('::')[-1], n
    return None, sym


def bodies(src, cls, name):
    pat = (re.escape(cls) + r'\s*::\s*' if cls else r'(?<![:\w~])') + re.escape(name) + r'\s*\([^;{]*\)\s*(const)?\s*(//[^\n]*)?\s*\{'
    out = []
    for m in re.finditer(pat, src):
        s = src.rfind('\n', 0, m.start()) + 1
        i, d = m.end(), 1
        while d and i < len(src):
            d += {'{': 1, '}': -1}.get(src[i], 0); i += 1
        pre = src[max(0, s - 400):s]
        out.append((src[s:i], bool(re.search(r'0x00[4-7][0-9A-Fa-f]{5}', pre + src[s:min(i, s + 300)]))))
    return out


def files():
    fs = sorted(glob.glob(os.path.join(L, 'ctx44g', 'gibbo*.cpp'))) + sorted(glob.glob(os.path.join(L, 'ctx42', 'meastes1006_*.cpp')))
    ref = os.path.join(W, 'analysis', 'references_gpl_20261118')
    for sub in ('gibbo101_ra2-decomp/src', 'meastes_redalert2-decomp/src'):
        d = os.path.join(ref, *sub.split('/'))
        if os.path.isdir(d):
            for root, _, names in os.walk(d):  # bounded: two named src folders inside W
                fs += [os.path.join(root, n) for n in names if n.lower().endswith('.cpp')]
    return fs


def gibbo_status():
    # gibbo101 data/progress.csv: address,name,result,size,source,symbol (YR addresses; matched by name only)
    f = os.path.join(W, 'analysis', 'references_gpl_20261118', 'gibbo101_ra2-decomp', 'data', 'progress.csv')
    st = {}
    if os.path.exists(f):
        import csv
        for r in csv.DictReader(open(f, encoding='utf-8', errors='replace')):
            st.setdefault(r.get('name') or '', r.get('result') or '')
    return st


def by_size(ne):
    import csv
    sha = '7fe00ee313b38b22e68d6c05aede041018206e29b71f5db9cc1afacc61588c6e'
    size = {}
    for line in open(os.path.join(W, 'analysis', 'functions_%s.jsonl' % sha), encoding='utf-8'):
        r = json.loads(line); size[int(r['rva'], 16)] = r['size']
    ref = os.path.join(W, 'analysis', 'references_gpl_20261118')
    com = []
    f = os.path.join(ref, 'gibbo101_ra2-decomp', 'data', 'progress.csv')
    if os.path.exists(f):
        for r in csv.DictReader(open(f, encoding='utf-8', errors='replace')):
            if (r.get('result') or '') == 'MATCH' and (r.get('size') or '').isdigit():
                com.append((int(r['size']), 'gibbo %s %s' % (r['address'], r.get('name') or r.get('symbol') or '?')))
    f = os.path.join(ref, 'meastes_redalert2-decomp', 'manifests', 'function_map.csv')
    if os.path.exists(f):
        for r in csv.DictReader(open(f, encoding='utf-8', errors='replace')):
            if (r.get('flags') or '').split()[:1] == ['exact'] and (r.get('size') or '').isdigit():
                com.append((int(r['size']), 'meastes %s %s' % (r['address'], r.get('symbol') or '?')))
    rows = ['', '## Same-size community candidates (within 8 bytes; size alone proves nothing)', '',
            '| RVA | Function | Our size | Candidates (size: source address name) |', '|---|---|---:|---|']
    for e in sorted(ne, key=lambda e: -int(e.get('diff_bytes') or 0)):
        n = size.get(int(e['rva'], 16))
        if not n:
            continue
        c = sorted((abs(cs - n), cs, t) for cs, t in com if abs(cs - n) <= 8)[:6]
        rows.append('| %s | %s | %d | %s |' % (e['rva'], e['symbol'][:50], n, '; '.join('%d: %s' % (cs, t) for _, cs, t in c) or '-'))
    return rows


def main():
    out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(L, 'twin_sweep.md')
    ne = json.load(open(os.path.join(P, 'metadata', 'level2_near_equal.json'), encoding='utf-8'))['functions']
    srcs = [(f, open(f, encoding='latin-1').read()) for f in files()]
    rows = ['# Twin sweep of near-equal functions', '', 'Generated by W/tools/level2_twin_sweep.py (read-only, no compiles).', '',
            '| RVA | Function | Diff | gibbo status | Twins (file: lines, marker) |', '|---|---|---:|---|---|']
    gs = gibbo_status()
    hits = 0
    for e in sorted(ne, key=lambda e: -int(e.get('diff_bytes') or 0)):
        cls, name = parts(e['symbol'])
        tw = []
        for f, s in srcs:
            for b, mk in bodies(s, cls, name):
                tw.append('%s: %d%s' % (os.path.relpath(f, W).replace('\\', '/'), b.count('\n') + 1, ', marker' if mk else ''))
        hits += bool(tw)
        fn = (cls + '::' if cls else '') + (name or '?')
        rows.append('| %s | %s | %s | %s | %s |' % (e['rva'], fn, e.get('diff_bytes'), gs.get(fn, '-'), '; '.join(tw) or '-'))
    rows += by_size(ne)
    open(out, 'w', encoding='utf-8').write('\n'.join(rows) + '\n')
    print('%d near-equal, %d with a community body -> %s' % (len(ne), hits, out))


if __name__ == '__main__':
    main()
