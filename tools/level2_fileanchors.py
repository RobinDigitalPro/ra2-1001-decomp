"""__FILE__ anchors: which functions of GAME.EXE 1.001 reference a source-path string ("C:\\RA2\\X.cpp"), and does
the claimed TU agree?  Read-only.

usage: python -I level2_fileanchors.py [--json OUT] [--show N]
Output (default W/analysis/level2/agents/t2_tools/fileanchors.json):
  anchors      every path string in the image with the functions whose code holds its address
  disagree     claimed functions whose TU basename differs from the file their __FILE__ anchor names
               (a lead for TU re-attribution, see P/docs/level2/TU_REATTRIBUTION.md; inlined helpers from a header
               legitimately carry another file's __FILE__, so each line needs review, not a mechanical move)
  unclaimed    anchored functions nobody claims, grouped by file: the TU they most likely belong to
Containing function: the latest check-report extent of a claim when it covers the reference, otherwise the
Ghidra index start before it (functions_<sha>.jsonl).

Credit: idea and string scan from gibbo101/ra2-decomp tools/modules.py file_anchors() @bd6bc66711 (MIT); this
adaptation is part of the GPL-3.0-or-later level-2 tree.
"""
import bisect, collections, glob, json, os, re, struct, sys
W = r'D:\<work-root>\RedAlert2Temp'
P = r'D:\<project-folder>\Coding\RedAlert2'
sys.path.insert(0, os.path.join(W, 'tools')); sys.path.insert(0, os.path.join(W, 'analysis', 'level2'))
import level2_check as lc  # noqa: E402

PATH = re.compile(rb'[A-Za-z]:\\[\x20-\x7e]{1,120}?\.(?:cpp|c|asm|h)\x00', re.I)


def stem(p):
    return re.split(r'[\\/]', p)[-1].rsplit('.', 1)[0].casefold()


def main():
    a = sys.argv[1:]
    out = os.path.join(W, 'analysis', 'level2', 'agents', 't2_tools', 'fileanchors.json')
    show = 30
    if '--json' in a:
        out = a[a.index('--json') + 1]
    if '--show' in a:
        show = int(a[a.index('--show') + 1])
    B, secs = lc.image()
    t = next(s for s in secs if s[0] == '.text')
    T = B[t[4]:t[4] + min(t[2], t[3])]
    starts = sorted(int(json.loads(l)['rva'], 16) for l in open(lc.FUNCS))
    latest = {}
    for path in sorted(glob.glob(os.path.join(W, 'analysis', 'level2', 'reports', 'check_*.json'))):
        for f in json.load(open(path))['functions']:
            latest[f['rva']] = f
    claims = {int(f['rva'], 16): f for f in json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))}
    cstarts = sorted(claims)

    def owner(rva):
        k = bisect.bisect_right(cstarts, rva) - 1
        if k >= 0:
            c = cstarts[k]; sz = (latest.get(hex(c)) or {}).get('size') or 0
            if c <= rva < c + sz:
                return c
        k = bisect.bisect_right(starts, rva) - 1
        return starts[k] if k >= 0 else None

    anchors, disagree, unclaimed = [], [], collections.defaultdict(set)
    for name, sva, vs, rs, ra in secs:
        if name == '.text':
            continue
        for m in PATH.finditer(B[ra:ra + rs]):
            text = m.group()[:-1].decode('latin-1')
            va = 0x400000 + sva + m.start()
            fns = set()
            for ref in re.finditer(re.escape(struct.pack('<I', va)), T):
                fn = owner(t[1] + ref.start())
                if fn is not None:
                    fns.add(fn)
            if not fns:
                continue
            rec = {'string_va': hex(va), 'path': text, 'functions': []}
            for fn in sorted(fns):
                c = claims.get(fn)
                tu = c['tu'] if c else None
                status = (latest.get(hex(fn)) or {}).get('status') if c else None
                rec['functions'].append({'rva': hex(fn), 'tu': tu, 'status': status})
                if c is None:
                    unclaimed[text].add(hex(fn))
                elif stem(tu) != stem(text):
                    disagree.append({'rva': hex(fn), 'claimed_tu': tu, 'symbol': c.get('symbol'), 'anchor': text, 'status': status})
            anchors.append(rec)
    res = {'schema': 'level2_fileanchors_v1', 'binary_sha256': lc.SHA, 'anchor_strings': len(anchors),
           'anchored_functions': len({f['rva'] for r in anchors for f in r['functions']}),
           'disagree': disagree, 'unclaimed': {k: sorted(v) for k, v in sorted(unclaimed.items())}, 'anchors': anchors}
    os.makedirs(os.path.dirname(out), exist_ok=True)
    json.dump(res, open(out, 'w'), indent=1)
    print('%d path strings referenced from code, %d anchored functions, %d claims disagree with their anchor, '
          '%d unclaimed anchored functions in %d files' % (res['anchor_strings'], res['anchored_functions'], len(disagree),
                                                           sum(len(v) for v in unclaimed.values()), len(unclaimed)))
    for d in disagree[:show]:
        print('  DISAGREE %s %-34s anchor %s (%s)' % (d['rva'], d['claimed_tu'], d['anchor'], d['status']))
    for k, v in list(res['unclaimed'].items())[:show]:
        print('  UNCLAIMED %-28s %d: %s' % (k, len(v), ' '.join(v[:6])))
    print('->', out)


if __name__ == '__main__':
    main()
