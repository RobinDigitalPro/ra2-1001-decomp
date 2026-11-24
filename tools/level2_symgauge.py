"""level2_symgauge.py -- MEASURING INSTRUMENT for VC6 TU-history dependence (never a fix).

For a target function it inserts N probe items of a chosen KIND at a chosen place in a SCRATCH COPY of a TU,
compiles each variant with VC6 and reports, per N, the byte differences against GAME.EXE and a digest of the
relocation-masked code.  The digest classes show WHICH counter drives the target's code and with which period;
the matching N says how many items of that kind 1.001 had more (or, with --remove-lines, fewer) at that place.

Dead probe items are NEVER acceptable as source.  The result only tells where earlier code is unfaithful.

Measured facts (2026-11-21, OPEN_PATTERNS "KEY: VC6 symbol numbering and allocation order"):
  * the dependence has period 64 in the compiler's TU-wide sequence number, so sweep --n 0-63 once;
  * units per probe item: extern/static/typedef/local/string literal = 1, prototype = 2, empty function = 3, struct{int} = 9;
  * most functions are INSENSITIVE (one code variant for all N): then numbering is ruled out as the cause;
  * a sensitive function with V variants matches by chance for 64/V values of N, so one function proves little.

usage:
  python -I level2_symgauge.py --src <tu.cpp> --at <regex> [--after] --kind <kind> --n 0-16
         --target "<symbol substring> <rva hex>" [--target ...] [--inc <dir> ...] [--jobs 3] [--tag name]
         [--also "<needle>" ...]        (extra functions whose digest is tracked without an RVA)

  --at     regex of the source line where the probe text is inserted (first match; before it, or after it with --after)
  --in     regex of the FUNCTION HEADER line (must match exactly one line): --at is then searched from that line
           on, so a body line that also occurs in earlier functions is safe.  Example:
             --in "Slide_Dialog\(HWND" --at "^\{" --after      (the first `{` line of that function)
           Without --in, anchor --at on the header line itself, or pick the k-th file match with --occ k;
           --plus N moves the insertion point N lines further down.  The tool prints the line it uses.
  --src and --inc may be relative paths (resolved against the current directory).
  kinds (text inserted for a given N; all names are __sg*):
    locals     N dead `int` locals (one declaration statement) -- use INSIDE a function body (--after on its `{` line)
    ulocals    N used locals `volatile int __sgK = K;`               (inside a function)
    blocks     N nested-scope blocks `{ int __sgK = K; __sg_sink(__sgK); }` (inside a function)
    calls      N calls `__sg_sink(K);`                               (inside a function; adds temporaries/calls only)
    func       ONE new function with N int locals that are used     (file scope)
    funcs      N new empty functions                                (file scope)
    funcargs   ONE new function with N int parameters               (file scope)
    strings    ONE new function that uses N distinct string literals (file scope)
    statics    N file-scope `static int` definitions                (file scope)
    externs    N `extern int` declarations                          (file scope)
    protos     N function prototypes                                (file scope)
    typedefs   N typedefs                                           (file scope)
    structs    N struct definitions                                 (file scope)
Work files go to W/build/level2/symlab/<tag>/ .
"""
import sys, os, re, argparse, hashlib, subprocess, json
from concurrent.futures import ThreadPoolExecutor
W = r'D:\<work-root>\RedAlert2Temp'
sys.path.insert(0, W + r'\analysis\level2')
VC6 = '<RA2_WORK>/analysis/level2/cal/vc6.sh'
FLAGS = ['-O2', '-Ob2', '-Gr', '-GR', '-DNDEBUG', '-Gy', '-DWIN32', '-W0']
M85 = '<RA2_PROJECT>/src/m85'
def _bash():
    for c in (os.environ.get('L2_BASH'), 'C:/Program Files/Git/usr/bin/bash.exe', 'C:/Program Files/Git/bin/bash.exe'):
        if c and os.path.exists(c):
            return c
    return 'bash'


BASH = _bash()
SINK = 'extern void __fastcall __sg_sink(int);\n'


def probe(kind, n):
    r = range(n)
    if kind == 'locals':
        return ('int ' + ', '.join('__sg%d' % k for k in r) + ';\n') if n else ''
    if kind == 'ulocals':
        return ''.join('volatile int __sg%d = %d;\n' % (k, k) for k in r)
    if kind == 'blocks':
        return ''.join('{ int __sg%d = %d; __sg_sink(__sg%d); }\n' % (k, k, k) for k in r)
    if kind == 'calls':
        return ''.join('__sg_sink(%d);\n' % k for k in r)
    if kind == 'func':
        return 'void __sg_func(void)\n{\n' + ''.join('\tint __sg%d = %d; __sg_sink(__sg%d);\n' % (k, k, k) for k in r) + '}\n'
    if kind == 'funcs':
        return ''.join('void __sg_f%d(void) { }\n' % k for k in r)
    if kind == 'funcargs':
        return 'void __sg_fa(' + (', '.join('int __sg%d' % k for k in r) or 'void') + ') { }\n'
    if kind == 'strings':
        return 'extern void __fastcall __sg_ssink(char const *);\nvoid __sg_strs(void)\n{\n' + ''.join('\t__sg_ssink("__sg string %d");\n' % k for k in r) + '}\n'
    if kind == 'statics':
        return ''.join('static int __sg_s%d = %d;\n' % (k, k) for k in r)
    if kind == 'externs':
        return ''.join('extern int __sg_e%d;\n' % k for k in r)
    if kind == 'protos':
        return ''.join('void __sg_p%d(int);\n' % k for k in r)
    if kind == 'typedefs':
        return ''.join('typedef int __sg_t%d;\n' % k for k in r)
    if kind == 'structs':
        return ''.join('struct __sg_st%d { int a; };\n' % k for k in r)
    raise SystemExit('unknown kind ' + kind)


def nrange(s):
    out = []
    for p in s.split(','):
        if '-' in p:
            a, b = p.split('-'); out += range(int(a), int(b) + 1)
        else:
            out.append(int(p))
    return out


def masked_digest(o, name):
    sec = o.function(name)
    b = bytearray(sec['raw'])
    for off, _, _ in sec['relocs']:
        b[off:off + 4] = b'\0\0\0\0'
    return hashlib.sha1(bytes(b)).hexdigest()[:6], len(b)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--src', required=True); ap.add_argument('--at', required=True); ap.add_argument('--after', action='store_true')
    ap.add_argument('--kind', required=True); ap.add_argument('--n', default='0-16')
    ap.add_argument('--target', action='append', default=[]); ap.add_argument('--also', action='append', default=[])
    ap.add_argument('--inc', action='append', default=[]); ap.add_argument('--jobs', type=int, default=3)
    ap.add_argument('--tag', default=None); ap.add_argument('--claims', default=None, help='tu name in P/metadata/level2_functions.json: also count its claimed functions that still match'); ap.add_argument('--plus', type=int, default=0, help='move the insertion point this many lines further down'); ap.add_argument('--occ', type=int, default=1, help='use the k-th match of --at')
    ap.add_argument('--in', dest='within', default=None, help='regex of the function header line (exactly one match); --at is searched from that line on')
    a = ap.parse_args()
    a.src = os.path.abspath(a.src); a.inc = [os.path.abspath(i) for i in a.inc]
    import l2match
    from coffmatch import Obj, match_function
    src = open(a.src, encoding='latin1', newline='').read()
    lines = src.split('\n')
    rx = re.compile(a.at)
    first = 0
    if a.within:
        hdr = [i for i, l in enumerate(lines) if re.search(a.within, l)]
        if len(hdr) != 1:
            raise SystemExit('--in matches %d lines (must be exactly one): %s' % (len(hdr), [h + 1 for h in hdr[:8]]))
        first = hdr[0]
    hits = [i for i, l in enumerate(lines) if i >= first and rx.search(l)]
    if len(hits) < a.occ:
        raise SystemExit('--at matches %d lines' % len(hits))
    at = hits[a.occ - 1] + (1 if a.after else 0) + a.plus
    base = os.path.splitext(os.path.basename(a.src))[0]
    tag = a.tag or '%s_%s' % (base, a.kind)
    wd = os.path.join(W, 'build', 'level2', 'symlab', tag); os.makedirs(wd, exist_ok=True)
    incs = ['-I' + os.path.dirname(os.path.abspath(a.src)).replace('\\', '/'), '-I' + M85 + '/src', '-I' + M85 + '/include'] + ['-I' + i for i in a.inc]
    print('insert at line %d (%s) : %s' % (at + 1, 'after match' if a.after else 'before match', lines[hits[a.occ - 1]].strip()[:70]))
    targets = [(t.rsplit(' ', 1)[0], int(t.rsplit(' ', 1)[1], 16)) for t in a.target]

    claims = []
    if a.claims:
        fs = json.load(open(r'<RA2_PROJECT>/metadata/level2_functions.json'))
        claims = [(f['symbol'], int(f['rva'], 16)) for f in fs if f['tu'] == a.claims]

    def one(n):
        d = os.path.join(wd, 'n%03d' % n); os.makedirs(d, exist_ok=True)
        cpp = os.path.join(d, base + '.cpp'); obj = os.path.join(d, base + '.obj')
        text = probe(a.kind, n)
        if a.kind in ('blocks', 'calls', 'func') and n:
            # the sink prototype goes to the top of the file so it is the same single extra symbol for every N>0
            body = [SINK.rstrip('\n')] + lines[:at] + text.rstrip('\n').split('\n') + lines[at:]
        else:
            body = lines[:at] + (text.rstrip('\n').split('\n') if text else []) + lines[at:]
        open(cpp, 'w', encoding='latin1', newline='').write('\n'.join(body))
        if os.path.exists(obj):
            os.remove(obj)
        p = subprocess.run([BASH, VC6, cpp.replace('\\', '/'), obj.replace('\\', '/')] + FLAGS + incs, capture_output=True, text=True)
        if not os.path.exists(obj):
            return n, None, (p.stdout + p.stderr)[-300:]
        o = Obj(open(obj, 'rb').read()); res = []
        for needle, rva in targets:
            names = [k for k in o.symbols if needle in k]
            r = match_function(o, names[0], l2match.orig(rva, len(o.function(names[0])['raw'])), 0x400000 + rva, lambda s: None) if len(names) == 1 else dict(status='symbol_not_unique')
            dg = masked_digest(o, names[0]) if len(names) == 1 else ('?', 0)
            st = r.get('status')
            res.append((needle, 'MATCH' if st in ('matched', 'bytes_match_bindings_open') else st, r.get('byte_differences'), dg))
        for needle in a.also:
            names = [k for k in o.symbols if needle in k]
            res.append((needle, '-', None, masked_digest(o, names[0]) if len(names) == 1 else ('?', 0)))
        if claims:
            bad = []
            for sym, rva in claims:
                try:
                    st = match_function(o, sym, l2match.orig(rva, len(o.function(sym)['raw'])), 0x400000 + rva, lambda s: None).get('status')
                except Exception:
                    st = 'ERR'
                if st not in ('matched', 'bytes_match_bindings_open'):
                    bad.append('%x' % rva)
            res.append(('claims', 'ok %d/%d' % (len(claims) - len(bad), len(claims)), None, (','.join(bad[:12]) or 'none', 0)))
        return n, res, ''

    ns = nrange(a.n)
    with ThreadPoolExecutor(max_workers=min(a.jobs, 3)) as ex:
        results = list(ex.map(one, ns))
    classes = {}
    for n, res, err in results:
        if res is None:
            print('N=%3d COMPILE FAILED %s' % (n, err.replace('\n', ' | '))); continue
        print('N=%3d ' % n + '  '.join('%s:%s diff=%s size=%d dg=%s' % (nd[:24], st, bd, dg[1], dg[0]) for nd, st, bd, dg in res))
        for nd, st, bd, dg in res:
            classes.setdefault(nd, {}).setdefault(dg[0], []).append(n)
    print('--- summary (%s at line %d) ---' % (a.kind, at + 1))
    out = {}
    for n, res, err in results:
        for nd, st, bd, dg in (res or []):
            if st == 'MATCH':
                out.setdefault(nd, []).append(n)
    for nd, cl in classes.items():
        print('%s: %d distinct code variants over %d N values; matching N: %s' % (nd[:40], len(cl), len(ns), out.get(nd, 'none')))
        for dg, l in cl.items():
            print('   dg %s : N = %s' % (dg, l))
        if nd != 'claims':
            if len(cl) == 1:
                print('   => INSENSITIVE: the code does not depend on symbol numbering at this insertion point; look for the cause inside the function')
            else:
                import math
                print('   => %d variants = about %.1f bits; a chance match is expected for about %.1f of every 64 N.  A matching N is evidence'
                      ' of a symbol-count difference only if several sensitive functions agree on the same N (mod 64).' % (len(cl), math.log2(len(cl)), 64.0 / len(cl)))
    json.dump(dict(args=vars(a), classes=classes, matching=out), open(os.path.join(wd, 'result.json'), 'w'), indent=1)


if __name__ == '__main__':
    main()
