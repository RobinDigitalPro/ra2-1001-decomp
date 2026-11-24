"""level2_flipsweep.py -- find the count of ONE diagnostic statement at which a function's near miss flips (never source).

Adapted from gibbo101/ra2-decomp tools/flipsweep.py at commit bd6bc66711 (MIT License, Copyright (c) 2026 ra2-decomp contributors; tools/ is MIT per the upstream LICENSE, only src/ and include/ are GPL), with its
tools/inlineprobe.py helpers (body_span, insertion); reviewed in P/docs/level2/COMMUNITY_TOOLS_REVIEW.md (T1).
This version uses our native VC6 kit (W/tools/portable/vc6), our COFF matcher (W/analysis/level2/coffmatch.py)
and GAME.EXE 1.001 through l2match; it never runs anything from the reference checkout.

It reads SRC (for example a P TU), writes every variant ONLY to a scratch folder (--out, default
W/analysis/level2/agents/flipsweep/<tag>/), and for k = 0..K inserts k numbered copies of one probe statement at
one place of the target's body.  Per k it prints the matcher status, byte differences, the number of
relocation-masked instruction hunks and a LETTER for the multiset of differing normalised lines.  The first k
whose letter differs from k = 0 is the flip point.  Counts that are thresholds (named locals, distinct
expressions, inline sites, statements in a block) stay flat until the flip, so one run finds it.  --kind2 sweeps a
second probe kind against the first as a grid.  The declarations a kind needs are present at EVERY k (k = 0
included), so the declaration count before the target stays fixed; the extra `source` row is the unmodified file.

A flip is a TARGET, not a fix: the probes never land (CREATIVE_BRIEF: no dead probes in source).  Find natural
source that changes the same count.

usage:
  python -I level2_flipsweep.py --src <tu.cpp> --anchor "<unique text, e.g. the function header>"
         --target "<symbol substring or exact ?symbol> <rva hex>"
         [--kind local|store|call|expr|stmt] [--stmt TEXT] [--decl TEXT ...] [--at POS] [--max K]
         [--kind2 KIND --stmt2 TEXT --at2 POS --max2 K2] [--decl-at REGEX] [--ignore REGEX]
         [--preset m85|ra2] [--inc DIR ...] [--out DIR] [--jobs 2] [--keep]

kinds ({k} is replaced by the copy's index):
  local  a dead named, initialised local          int flip_local_{k} = {k};
  store  a one-instruction store to an extern int  Flip_Probe_Store_[{k}] = 0x7F00 + {k};
  call   a call of a trivial inline that folds     Inline_Probe_({k});
  expr   a dead distinct expression term           (void)(Flip_Probe_Value_ * ({k} + 3));
  stmt   --stmt TEXT, with the declarations it needs from --decl
positions: start, end (before the body's last return), line:N (SRC line N), before:REGEX / after:REGEX (first line
  of the target's body that matches).  Declarations go above the anchor's line (or above the first line matching
  --decl-at).  Added lines matching the kind's own constants (store: 0x7Fxx) or --ignore are left out of the sets.
paths: --src, --out and --inc may be relative; they are resolved against the current directory at start (the
  compiler runs with the scratch folder as its working directory, so a relative path used to fail with C1083).
"""
import argparse, concurrent.futures as cf, difflib, hashlib, itertools, json, os, re, subprocess, sys
from collections import Counter
from dataclasses import dataclass

P = r'D:\<project-folder>\Coding\RedAlert2'
W = r'D:\<work-root>\RedAlert2Temp'
VC6 = os.path.join(W, 'tools', 'portable', 'vc6')
sys.path.insert(0, os.path.join(W, 'analysis', 'level2'))
sys.path.insert(0, os.path.join(W, 'tools', 'portable', 'capstone-5.0.6'))
import capstone  # noqa: E402
import l2match  # noqa: E402
from coffmatch import Obj, match_function, REL_REL32, REL_DIR32, REL_DIR32NB  # noqa: E402

FLAGS = ['-nologo', '-c', '-O2', '-Ob2', '-Gr', '-GR', '-DNDEBUG', '-Gy']
BASE = 0x400000


# ---------------------------------------------------------------- probe kinds (upstream KINDS, unchanged texts)
@dataclass(frozen=True)
class Kind:
    stmt: str
    decls: tuple = ()
    ignore: str = ''


def helper(spend=0):
    """The probe inline: a body that folds away, or one of `spend` terms VC6 must expand (upstream inlineprobe.helper)."""
    body = 'a & 0' if spend <= 0 else ' + '.join('(a ^ %d)' % (k + 1) for k in range(spend))
    return 'static inline int Inline_Probe_(int a) { return %s; }' % body


KINDS = {
    'local': Kind('int flip_local_{k} = {k};'),
    'store': Kind('Flip_Probe_Store_[{k}] = 0x7F00 + {k};', ('extern int Flip_Probe_Store_[];',), r'\b0x7f[0-9a-f]{2}\b'),
    'call': Kind('Inline_Probe_({k});', (helper(0),)),
    'expr': Kind('(void)(Flip_Probe_Value_ * ({k} + 3));', ('extern int Flip_Probe_Value_;',)),
}


def kind_of(name, stmt=None, decls=()):
    if name == 'stmt':
        if not stmt:
            raise SystemExit('--kind stmt needs --stmt TEXT')
        return Kind(stmt, tuple(decls))
    return KINDS[name]


def copies(kind, n, indent='\t'):
    return [indent + kind.stmt.replace('{k}', str(k)) for k in range(n)]


# ---------------------------------------------------------------- source positions (upstream inlineprobe/flipsweep)
def _code(line):
    return re.sub(r'//.*|"(?:\\.|[^"])*"|\'(?:\\.|[^\'])*\'', '', line)


def body_span(lines, start):
    """(open, close) line indexes of the first brace-delimited body at or after `start`."""
    depth, first = 0, None
    for i in range(start, len(lines)):
        for ch in _code(lines[i]):
            if ch == '{':
                depth += 1
                if first is None:
                    first = i
            elif ch == '}':
                depth -= 1
                if first is not None and depth == 0:
                    return first, i
    raise SystemExit('unbalanced braces after line %d' % (start + 1))


def anchor_line(lines, anchor):
    text = '\n'.join(lines)
    if text.count(anchor) != 1:
        raise SystemExit('anchor occurs %d times (must be exactly once): %r' % (text.count(anchor), anchor[:80]))
    return text[:text.index(anchor)].count('\n')


def insertion(lines, span, where):
    """Line index to insert before: just inside the body, or before its last return / closing brace."""
    o, c = span
    if where == 'start':
        return o + 1
    for i in range(c - 1, o, -1):
        if re.match(r'\s*return\b', lines[i]):
            return i
        if lines[i].strip():
            break
    return c


def position(lines, span, pos, shift_of=lambda n: 0):
    o, c = span
    if pos in ('start', 'end'):
        return insertion(lines, span, pos)
    if pos.startswith('line:'):
        n = int(pos[5:]) - 1
        return n + shift_of(n)
    where, _, pattern = pos.partition(':')
    if where in ('before', 'after') and pattern:
        for i in range(o + 1, c):
            if re.search(pattern, lines[i]):
                return i if where == 'before' else i + 1
        raise SystemExit("no line of the target's body matches %r" % pattern)
    raise SystemExit('unknown position %r' % pos)


def insert_all(lines, blocks):
    """lines with each (index, block) inserted; equal indexes keep the blocks' order."""
    out = list(lines)
    for at, _, block in sorted(((at, n, block) for n, (at, block) in enumerate(blocks)), reverse=True):
        out[at:at] = block
    return out


# ---------------------------------------------------------------- symbols, original size, normalised listings
_symmap = None


def symmap():
    """Decorated symbol -> VA from P/metadata/level2_symbols.json and the level-2 claims (read only)."""
    global _symmap
    if _symmap is None:
        m = {}
        try:
            for k, v in json.load(open(os.path.join(P, 'metadata', 'level2_symbols.json'), encoding='utf-8')).items():
                if isinstance(v, dict) and v.get('address'):
                    m[k] = int(v['address'], 16)
        except (OSError, ValueError):
            pass
        try:
            for e in json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8')):
                if e.get('symbol') and e.get('rva'):
                    m.setdefault(e['symbol'], BASE + int(e['rva'], 16))
        except (OSError, ValueError):
            pass
        _symmap = m
    return _symmap


def resolve(sym):
    return symmap().get(sym)


_starts = None


def ref_len(rva, fallback):
    """1.001 body length: up to the next known start (function map + claims), padding trimmed; as level2_varsearch."""
    global _starts
    import bisect
    if _starts is None:
        s = set()
        try:
            s |= {int(x['rva'], 16) for x in json.load(open(os.path.join(W, 'analysis', 'level2', 'function_map.json')))['map']}
        except (OSError, ValueError, KeyError):
            pass
        try:
            s |= {int(x['rva'], 16) for x in json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))}
        except (OSError, ValueError):
            pass
        _starts = sorted(s)
    i = bisect.bisect_right(_starts, rva)
    if i >= len(_starts):
        return fallback + 64
    n = _starts[i] - rva
    raw = l2match.orig(rva, n)
    while n > 0 and raw[n - 1] in (0x90, 0xcc):
        n -= 1
    return n if n > 16 else fallback + 64


MD = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
ABS = re.compile(r'0x[0-9a-f]{6,8}\b')


def _absmask(s):
    return ABS.sub(lambda m: '<addr>' if int(m.group(), 16) >= BASE else m.group(), s)


def listing(code, va, relocs=None, obj=None):
    """Normalised listing [(address, text)]: data addresses as <addr>, internal jumps by mnemonic, calls by target
    (ours: the resolved VA of the relocation's symbol, else <symbol>).  Stack displacements stay visible."""
    rel = {}
    if relocs is not None:
        code = bytearray(code)
        for off, symidx, typ in relocs:
            rel[off] = (obj.by_index[symidx]['name'], typ)
            if typ in (REL_DIR32, REL_DIR32NB) and off + 4 <= len(code):
                code[off:off + 4] = (BASE + 0x1000).to_bytes(4, 'little')   # placeholder image address -> <addr>
        code = bytes(code)
    out = []
    for i in MD.disasm(code, va):
        s = ('%s %s' % (i.mnemonic, i.op_str)).strip()
        if i.mnemonic == 'nop' or s.startswith('int3'):
            continue
        off = i.address - va
        if i.mnemonic in ('call', 'jmp') and i.size == 5 and code[off] in (0xe8, 0xe9):
            if relocs is not None and off + 1 in rel:
                sym = rel[off + 1][0]
                t = resolve(sym)
                out.append((i.address, '%s %s' % (i.mnemonic, '0x%08x' % t if t is not None else '<%s>' % sym)))
                continue
            t = int(i.op_str, 16)
            if va <= t < va + len(code):
                out.append((i.address, i.mnemonic + ' <local>'))
            else:
                out.append((i.address, '%s 0x%08x' % (i.mnemonic, t)))
            continue
        if i.mnemonic.startswith('j') or i.mnemonic.startswith('loop'):
            out.append((i.address, i.mnemonic + ' <local>'))
            continue
        out.append((i.address, _absmask(s)))
    return out


@dataclass
class Outcome:
    status: str
    diffs: int = 0
    size: int = 0
    orig: int = 0
    hunks: int = 0
    lines: tuple = ()
    note: str = ''

    def __str__(self):
        if self.status == 'FAIL':
            return 'build failed: ' + self.note[-160:]
        n = sum(c for _, c in self.lines)
        return '%-26s bytes %5s  size %d/%d  hunks %3d  %d lines differ' % (
            self.status, self.diffs, self.size, self.orig, self.hunks, n)


def diff_set(theirs, ours, ignore=''):
    """Multiset of differing normalised lines ('-' original, '+' ours); added lines matching `ignore` dropped.
    A trailing hunk that is only the original continuing past our end is not counted (as level2_varsearch.hunks)."""
    pat = re.compile(ignore, re.I) if ignore else None
    sm = difflib.SequenceMatcher(None, theirs, ours, autojunk=False)
    ops = [op for op in sm.get_opcodes() if op[0] != 'equal']
    if ops and ops[-1][3] == len(ours) and ops[-1][4] == len(ours):
        ops = ops[:-1]
    c = Counter()
    for _, i1, i2, j1, j2 in ops:
        for x in theirs[i1:i2]:
            c['-' + x] += 1
        for y in ours[j1:j2]:
            if pat and pat.search(y):
                continue
            c['+' + y] += 1
    return len(ops), tuple(sorted(c.items()))


# ---------------------------------------------------------------- compile and score in a scratch folder
class Builder:
    def __init__(self, out, preset='m85', inc=(), keep=False):
        out = os.path.abspath(out)           # CL runs with cwd = out: a relative folder would be resolved twice
        inc = [os.path.abspath(d) for d in inc]
        self.out, self.keep = out, keep
        self.serial = itertools.count()      # unique scratch names: equal texts may compile concurrently
        os.makedirs(out, exist_ok=True)
        if os.path.abspath(out).lower().startswith(P.lower()):
            raise SystemExit('--out must not be inside P: %s' % out)
        if preset == 'm85':
            self.inc = ['-DWIN32', '-W0', '-I' + os.path.join(P, 'src', 'm85', 'src'), '-I' + os.path.join(P, 'src', 'm85', 'include')]
        else:
            self.inc = ['-I' + os.path.join(P, 'src', 'ra2')]
        self.inc = ['-I' + d for d in inc] + self.inc   # an overlay dir is searched first
        env = dict(os.environ)
        env['PATH'] = os.pathsep.join([os.path.join(VC6, 'VC98', 'BIN'), os.path.join(VC6, 'COMMON', 'MSDEV98', 'BIN'), env.get('PATH', '')])
        env['INCLUDE'] = os.path.join(VC6, 'VC98', 'INCLUDE') + ';' + os.path.join(VC6, 'VC98', 'ATL', 'INCLUDE')
        env['LIB'] = os.path.join(VC6, 'VC98', 'LIB')
        self.env = env

    def compile(self, text, crlf, extra=(), suffix=''):
        """Compile `text` as a scratch .cpp; returns (obj path or None, log, listing path or None)."""
        h = '%04d_%s%s' % (next(self.serial), hashlib.sha256((text + repr(extra)).encode('latin-1', 'replace')).hexdigest()[:12], suffix)
        src = os.path.join(self.out, 'v_%s.cpp' % h)
        obj = src[:-4] + '.obj'
        asm = src[:-4] + '.asm' if extra else None
        open(src, 'wb').write((text.replace('\n', '\r\n') if crlf else text).encode('latin-1', 'replace'))
        args = list(extra)
        if asm:
            args = [a if a != '/Fa' else '/Fa' + asm for a in args]
        p = subprocess.run([os.path.join(VC6, 'VC98', 'BIN', 'CL.EXE')] + FLAGS + self.inc + args + ['-Fo' + obj, src],
                           env=self.env, capture_output=True, text=True, timeout=900, cwd=self.out)
        if not self.keep:
            os.remove(src)
        if not os.path.exists(obj):
            return None, p.stdout + p.stderr, None
        return obj, p.stdout, asm

    def done(self, *paths):
        if not self.keep:
            for x in paths:
                if x and os.path.exists(x):
                    os.remove(x)


def pick(o, needle):
    names = [needle] if needle in o.symbols else [k for k in o.symbols if needle in k]   # exact first, else a unique substring
    if len(names) != 1:
        raise LookupError('symbol %r: %s' % (needle, 'not unique: ' + ', '.join(names[:5]) if names else 'missing'))
    return names[0]


def analyse(obj, needle, rva, ignore=''):
    """Score one compiled object for the target: an Outcome plus the raw listings for callers that need them."""
    o = Obj(open(obj, 'rb').read())
    name = pick(o, needle)
    sec = o.function(name)
    code = sec['raw']
    while code and code[-1] in (0x90, 0xcc):
        code = code[:-1]
    n = ref_len(rva, len(code))
    if not (0.75 * len(code) <= n <= 1.5 * len(code)):
        n = len(code) + 32
    theirs_raw = l2match.orig(rva, n)
    r = match_function(o, name, l2match.orig(rva, len(sec['raw'])), BASE + rva, resolve)
    st = r.get('status')
    if st == 'mismatch' and len(code) != n:
        st = 'mismatch(size)'
    if r.get('status') in ('matched', 'bytes_match_bindings_open') and len(code) != n:
        st = r['status'] + '?size'      # equal over our extent, but the map says 1.001 is longer
    ours = listing(sec['raw'][:len(code)], BASE + rva, sec['relocs'], o)
    theirs = listing(theirs_raw, BASE + rva)
    hunks, lines = diff_set([t for _, t in theirs], [t for _, t in ours], ignore)
    if r.get('status') in ('matched', 'bytes_match_bindings_open'):
        hunks, lines = 0, ()
    res = Outcome(st, r.get('byte_differences', '-') if r.get('byte_differences') is not None else '-', len(code), n, hunks, lines)
    return res, dict(obj=o, name=name, sec=sec, code=sec['raw'][:len(code)], theirs_raw=theirs_raw, ours=ours, theirs=theirs)


def letters(sets):
    names = {}
    for v in sets.values():
        names.setdefault(v, chr(ord('A') + len(names)) if len(names) < 26 else '#%d' % len(names))
    return {k: names[v] for k, v in sets.items()}


def read_src(path):
    path = os.path.abspath(path)
    t = open(path, 'rb').read().decode('latin-1')
    crlf = '\r\n' in t
    return t.replace('\r\n', '\n').split('\n'), crlf


def target_arg(s):
    needle, rva = s.rsplit(None, 1)
    return needle, int(rva, 16)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--src', required=True)
    ap.add_argument('--anchor', required=True)
    ap.add_argument('--target', required=True, type=target_arg)
    ap.add_argument('--kind', default='local', choices=[*KINDS, 'stmt'])
    ap.add_argument('--stmt')
    ap.add_argument('--at', default='start')
    ap.add_argument('--max', type=int, default=16)
    ap.add_argument('--kind2', choices=[*KINDS, 'stmt'])
    ap.add_argument('--stmt2')
    ap.add_argument('--at2')
    ap.add_argument('--max2', type=int, default=8)
    ap.add_argument('--decl', action='append', default=[])
    ap.add_argument('--decl-at', help='regex of the line the declarations go above (default: the anchor line)')
    ap.add_argument('--ignore', default='')
    ap.add_argument('--preset', default='m85', choices=['m85', 'ra2'])
    ap.add_argument('--inc', action='append', default=[], help='extra include dir searched first (scratch header overlay)')
    ap.add_argument('--out')
    ap.add_argument('--jobs', type=int, default=2)
    ap.add_argument('--keep', action='store_true', help='keep the scratch .cpp/.obj files')
    a = ap.parse_args()
    needle, rva = a.target
    out = a.out or os.path.join(W, 'analysis', 'level2', 'agents', 'flipsweep', '%s_%x' % (re.sub(r'\W+', '_', needle)[:40], rva))
    first = kind_of(a.kind, a.stmt, a.decl)
    second = kind_of(a.kind2, a.stmt2, a.decl) if a.kind2 else None
    ignore = '|'.join(x for x in (first.ignore, second.ignore if second else '', a.ignore) if x)

    plain, crlf = read_src(a.src)
    at_anchor = anchor_line(plain, a.anchor)
    dat = at_anchor
    if a.decl_at:
        dat = next((i for i, l in enumerate(plain) if re.search(a.decl_at, l)), None)
        if dat is None:
            raise SystemExit('--decl-at matches no line')
    decls = list(dict.fromkeys(first.decls + (second.decls if second else ())))
    lines = plain[:dat] + decls + plain[dat:]
    shift_of = lambda n: len(decls) if n >= dat else 0  # noqa: E731
    span = body_span(lines, at_anchor + shift_of(at_anchor))
    at1 = position(lines, span, a.at, shift_of)
    at2 = position(lines, span, a.at2 or a.at, shift_of) if second else None
    b = Builder(out, a.preset, a.inc, a.keep)
    grid = [(k1, k2) for k1 in range(a.max + 1) for k2 in (range(a.max2 + 1) if second else [None])]

    def one(text):
        obj, log, _ = b.compile(text, crlf)
        if obj is None:
            return Outcome('FAIL', note=log)
        try:
            return analyse(obj, needle, rva, ignore)[0]
        except LookupError as e:
            return Outcome('FAIL', note=str(e))
        finally:
            b.done(obj)

    print('target %s 0x%x in %s; probes %r at %s (line %d)%s; scratch %s' % (
        needle, rva, a.src, first.stmt, a.at, at1 + 1, ' x %r at %s' % (second.stmt, a.at2 or a.at) if second else '', out), flush=True)
    texts = {'source': '\n'.join(plain)}
    for k1, k2 in grid:
        blocks = [(at1, copies(first, k1))] + ([(at2, copies(second, k2))] if second else [])
        texts[(k1, k2)] = '\n'.join(insert_all(lines, blocks))
    results = {}
    with cf.ThreadPoolExecutor(max(1, a.jobs)) as ex:
        futs = {key: ex.submit(one, t) for key, t in texts.items()}
        for key in texts:
            results[key] = futs[key].result()
            label = 'source' if key == 'source' else ('k=%2d' % key[0] if not second else 'k=%2d k2=%2d' % key)
            print('%-12s %s' % (label, results[key]), flush=True)
    src_row = results.pop('source')
    report(results, second is not None, src_row)
    json.dump({'src': a.src, 'target': [needle, hex(rva)], 'kind': first.stmt, 'at': a.at,
               'rows': [{'k': list(k), 'status': o.status, 'bytes': o.diffs, 'size': o.size, 'orig': o.orig,
                         'hunks': o.hunks, 'lines': [list(x) for x in o.lines]} for k, o in results.items()]},
              open(os.path.join(out, 'flipsweep_result.json'), 'w'), indent=1)


def report(results, is_grid, src_row=None):
    tags = letters({key: (o.status == 'FAIL', o.lines) for key, o in results.items()})
    clean = [key for key, o in results.items()
             if o.status != 'FAIL' and not o.status.startswith(('matched', 'bytes_match')) and not o.lines]
    if clean:
        print("only the probe's own lines differ at " + ', '.join(
            'k=%d' % k1 + (' k2=%d' % k2 if is_grid else '') for k1, k2 in clean))
    if not is_grid:
        print('sets: ' + ' '.join('%d%s' % (k, tags[(k, None)]) for k, _ in results))
        base = tags[(0, None)]
        flip = next((k for k, _ in results if tags[(k, None)] != base), None)
        print('flip point: k=%d (%s -> %s)' % (flip, base, tags[(flip, None)]) if flip is not None
              else "no flip: every k gives k=0's set")
        print("k with k=0's set: " + ', '.join(str(k) for k, _ in results if tags[(k, None)] == base))
        period = None
        seq = [tags[(k, None)] for k, _ in sorted(results)]
        for p in range(1, len(seq) // 2 + 1):
            if all(seq[i] == seq[i + p] for i in range(len(seq) - p)) and len(set(seq)) > 1:
                period = p
                break
        if period:
            print('the letter sequence repeats with period %d over k = 0..%d' % (period, len(seq) - 1))
        return
    cols = sorted({k2 for _, k2 in results})
    print('sets   ' + ' '.join('k2=%-3d' % c for c in cols))
    for k1 in sorted({k1 for k1, _ in results}):
        print('k=%-4d ' % k1 + ' '.join('%-6s' % tags[(k1, c)] for c in cols))
    base = tags[(0, 0)]
    flips = [key for key in sorted(results) if tags[key] != base]
    print('first change from (0,0): k=%d k2=%d (%s -> %s)' % (flips[0][0], flips[0][1], base, tags[flips[0]])
          if flips else "no flip: every cell gives (0,0)'s set")


if __name__ == '__main__':
    sys.exit(main())
