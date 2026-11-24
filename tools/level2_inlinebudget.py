"""level2_inlinebudget.py -- list where one function's out-of-line calls differ from 1.001's, and measure the inline-budget
slack at each such site with dead probes in SCRATCH copies (diagnostic only; probes never land in source).

Adapted from gibbo101/ra2-decomp tools/inlinebudget.py at commit bd6bc66711 (MIT License, Copyright (c) 2026 ra2-decomp contributors; tools/ is MIT per the upstream LICENSE, only src/ and include/ are GPL), with the helpers of
its tools/inlineprobe.py (callee_spans, insertion) and tools/flipsweep.py (probe kinds); reviewed in
P/docs/level2/COMMUNITY_TOOLS_REVIEW.md (T1).  Runs on our native VC6 kit, coffmatch/l2match and GAME.EXE 1.001
through level2_flipsweep.py; it never runs anything from the reference checkout and never writes into P.

It compiles SRC (scratch copy) and lines up 1.001's and our direct calls / tail jumps out of the target.  Our calls
are keyed by the VA of their relocation symbol (P/metadata/level2_symbols.json + level2 claims) or, when unknown, by
the 1.001 target they line up with one-to-one.  A callee called a different number of times on the two sides at an
unmatched call is a differing INLINE DECISION: 1.001 calls it where ours inlines it, or the reverse (ours only
counts for a function the object defines: an extern has no body to inline).  Each is tied to the statement of the
target's body it expands under, from the VC6 /FAcs listing (--site-line N overrides with SRC line N).

For each site, scratch copies add probes until that decision flips:
  1.001 calls, ours inlines:  k trivial inline calls after the statement (k more inline sites to the end of the
    body), k at the end of each body in SRC that the statement calls, and j "spend" probes (an inline of S one-unit
    extern calls) just before the statement: the slack is (j-1)*S .. j*S units of the pool left at the site;
  ours calls, 1.001 inlines:  k trivial inline calls before the statement, each one unit of own size: the
    shortfall is 2(k-1) .. 2k units while the pool is above its floor (upstream measured a 166-unit floor on YR;
    not re-measured for RA2 1.001).
Every probe is also a site for the calls before it, so a count at which other decisions changed too is a rough
measure.  Compare OPEN_PATTERNS "inline budget is a COUNT rule" and F7/F13 before reading meaning into a number.

usage:
  python -I level2_inlinebudget.py --src <tu.cpp> --anchor "<unique text before the body>"
         --target "<symbol substring or exact ?symbol> <rva hex>" [--body-anchor TEXT] [--preset m85|ra2] [--inc DIR ...]
         [--max 12] [--spend 8] [--site-line N] [--no-measure] [--out DIR] [--jobs 2] [--keep]
"""
import argparse, concurrent.futures as cf, difflib, os, re, sys
from collections import Counter
from dataclasses import dataclass, replace

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import level2_flipsweep as fs  # noqa: E402

PROBE = 'Inline_Probe'
LISTING_LINE = re.compile(r'^; (\d+)\s*:')
LISTING_CODE = re.compile(r'^\s{2}([0-9a-fA-F]{5,8})\s')
KEYWORDS = {'if', 'for', 'while', 'switch', 'return', 'sizeof', 'catch', 'delete', 'new'}
ESP_SLOT = re.compile(r'\[esp(?: [+-] (?:0x[0-9a-f]+|\d+))?\]')
EBP_SLOT = re.compile(r'\[ebp(?: [+-] (?:0x[0-9a-f]+|\d+))?\]')


def spend_kind(units):
    """A call of an inline whose body is `units` one-unit calls of an extern (upstream spend_kind)."""
    body = ' '.join('Inline_Probe_Sink_(1);' for _ in range(units))
    return fs.Kind('Inline_Probe_Spend_({k});',
                   ('void Inline_Probe_Sink_(int a);', 'static inline void Inline_Probe_Spend_(int a) { %s }' % body))


@dataclass(frozen=True)
class Call:
    index: int
    at: int
    key: object
    text: str
    defined: bool = False


@dataclass(frozen=True)
class Site:
    side: str
    callee: object
    call: Call
    anchor: object

    @property
    def ident(self):
        return (self.side, self.call.at) if self.side == 'exe' else (self.side, self.callee, self.anchor)


def paired(theirs, ours):
    """ours with each unresolved callee keyed by the exe target it lines up with one to one."""
    sm = difflib.SequenceMatcher(None, [c.key for c in theirs], [c.key for c in ours], autojunk=False)
    mapping = {}
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == 'replace' and i2 - i1 == j2 - j1:
            for e, o in zip(theirs[i1:i2], ours[j1:j2]):
                if isinstance(o.key, str) and isinstance(e.key, int):
                    mapping.setdefault(o.key, e.key)
    return [replace(c, key=mapping.get(c.key, c.key)) for c in ours]


def differing(theirs, ours):
    """Unmatched calls whose callee the two sides call a different number of times (upstream rule)."""
    ours = paired(theirs, [c for c in ours if PROBE not in str(c.key)])
    ce, co = Counter(c.key for c in theirs), Counter(c.key for c in ours)
    sm = difflib.SequenceMatcher(None, [c.key for c in theirs], [c.key for c in ours], autojunk=False)
    sites, anchor = [], None
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == 'equal':
            anchor = theirs[i2 - 1].at
            continue
        for c in theirs[i1:i2]:
            if ce[c.key] > co[c.key]:
                sites.append(Site('exe', c.key, c, anchor))
        for c in ours[j1:j2]:
            if c.defined and co[c.key] > ce[c.key]:
                sites.append(Site('ours', c.key, c, anchor))
    return sites


def listing_lines(text, symbol):
    """Instruction offset -> the source line the VC6 /FAcs listing shows above it, for one function."""
    out, line, active = {}, None, False
    for row in text.splitlines():
        if not active:
            active = bool(re.match(re.escape(symbol) + r'\s+PROC\b', row))
            continue
        if re.match(re.escape(symbol) + r'\s+ENDP\b', row):
            break
        m = LISTING_LINE.match(row)
        if m:
            line = int(m[1])
            continue
        m = LISTING_CODE.match(row)
        if m and line is not None:
            out[int(m[1], 16)] = line
    return out


def line_at(lines, offset):
    before = [o for o in lines if o <= offset]
    return lines[max(before)] if before else None


def statement_end(lines, start):
    """Index of the last line of the statement that starts on line `start`."""
    paren = brace = 0
    opened = False
    for i in range(start, len(lines)):
        for ch in fs._code(lines[i]):
            paren += {'(': 1, ')': -1}.get(ch, 0)
            if ch == '{':
                brace += 1
                opened = True
            elif ch == '}':
                brace -= 1
                if brace <= 0 and opened:
                    return i
            elif ch == ';' and paren == 0 and brace == 0:
                return i
    return start


def callee_spans(lines, body, target):
    """Bodies of functions defined in the file whose name the target's statement calls (upstream inlineprobe)."""
    names = {n for n in re.findall(r'\b([A-Za-z_]\w*)\s*\(', '\n'.join(body)) if n not in KEYWORDS}
    spans = {}
    for name in sorted(names):
        pat = re.compile(r'(?:^|[\s:*&])' + re.escape(name) + r'\s*\([^;]*\)\s*(?:const)?\s*(?:\{|$)')
        for i, line in enumerate(lines):
            if pat.search(line) and not line.rstrip().endswith(';') and not line.lstrip().startswith('//'):
                try:
                    o, c = fs.body_span(lines, i)
                except SystemExit:
                    continue
                if o - i > 3 or target[0] <= o <= target[1]:
                    continue
                spans[name] = (o, c)
                break
    return spans


def mask_stack(texts, frame):
    ebp = EBP_SLOT if frame else re.compile(r'\[ebp - (?:0x[0-9a-f]+|\d+)\]')
    return [ebp.sub('[ebp+N]', ESP_SLOT.sub('[esp+N]', t)) for t in texts]


class Analysis:
    """The differing decisions of one compiled copy."""

    def __init__(self, obj, needle, rva):
        self.res, d = fs.analyse(obj, needle, rva)
        o, sec, code, theirs_raw = d['obj'], d['sec'], d['code'], d['theirs_raw']
        va = fs.BASE + rva
        self.va, self.symbol = va, d['name']
        self.ours, self.theirs = d['ours'], d['theirs']        # [(address, normalised text)]
        rel = {off: o.by_index[si]['name'] for off, si, typ in sec['relocs'] if typ == fs.REL_REL32}
        defined = set(o.symbols)
        oi = {a: n for n, (a, _) in enumerate(self.ours)}
        ti = {a: n for n, (a, _) in enumerate(self.theirs)}
        self.exe_calls, self.our_calls = [], []
        for ins in fs.MD.disasm(theirs_raw, va):
            off = ins.address - va
            if ins.mnemonic in ('call', 'jmp') and ins.size == 5 and theirs_raw[off] in (0xe8, 0xe9):
                t = int(ins.op_str, 16)
                inside = va < t < va + len(theirs_raw) or (t == va and ins.mnemonic == 'jmp')
                if not inside and ins.address in ti:     # a call of its own start is a recursion, kept on both sides
                    self.exe_calls.append(Call(ti[ins.address], ins.address, t, '%s 0x%08x' % (ins.mnemonic, t)))
        for ins in fs.MD.disasm(code, va):
            off = ins.address - va
            if ins.mnemonic in ('call', 'jmp') and ins.size == 5 and code[off] in (0xe8, 0xe9) and off + 1 in rel:
                sym = rel[off + 1]
                key = fs.resolve(sym)
                self.our_calls.append(Call(oi.get(ins.address, 0), ins.address, key if key is not None else sym,
                                           '%s %s' % (ins.mnemonic, sym), sym in defined))
        self.sites = differing(self.exe_calls, self.our_calls)
        self.probe_calls = sum(1 for c in self.our_calls if PROBE in c.text and 'Sink' not in c.text)


def site_line(site, a, lines):
    """The source line our code for a site sits under: the call itself, or the code ours has where 1.001's call is."""
    if site.side == 'ours':
        return line_at(lines, site.call.at - a.va)
    th = [t for _, t in a.theirs]
    ou = [t for _, t in a.ours]
    frame = th[:2] == ['push ebp', 'mov ebp, esp']
    matched = {}
    for x, y, n in difflib.SequenceMatcher(None, mask_stack(th, frame), mask_stack(ou, frame), autojunk=False).get_matching_blocks():
        matched.update({x + k: y + k for k in range(n)})
    i = site.call.index
    prev = max((e for e in matched if e < i), default=None)
    nxt = min((e for e in matched if e > i), default=None)
    lo = matched[prev] + 1 if prev is not None else 0
    hi = matched[nxt] if nxt is not None else len(ou)
    j = lo if lo < hi else max(lo - 1, 0)
    return line_at(lines, a.ours[j][0] - a.va) if a.ours else None


def describe(key):
    if isinstance(key, int):
        names = [k for k, v in fs.symmap().items() if v == key]
        return '0x%08x %s' % (key, names[0] if names else '(unnamed)')
    return str(key)


def direction(site):
    return 'exe calls, ours inlines' if site.side == 'exe' else 'ours calls, exe inlines'


def plural(n, noun):
    return '%d %s%s' % (n, noun, '' if n == 1 else 's')


class Budget:
    def __init__(self, args):
        self.a = args
        self.needle, self.rva = args.target
        out = args.out or os.path.join(fs.W, 'analysis', 'level2', 'agents', 'inlinebudget',
                                       '%s_%x' % (re.sub(r'\W+', '_', self.needle)[:40], self.rva))
        out = os.path.abspath(out)           # relative --src/--out/--inc are resolved here and in fs.Builder
        args.src = os.path.abspath(args.src)
        self.b = fs.Builder(out, args.preset, args.inc, args.keep)
        self.fold, self.spend = fs.KINDS['call'], spend_kind(args.spend)
        self.plain, self.crlf = fs.read_src(args.src)
        self.anchor = fs.anchor_line(self.plain, args.anchor)
        body = fs.anchor_line(self.plain, args.body_anchor) if args.body_anchor else self.anchor
        decls = list(dict.fromkeys(self.fold.decls + self.spend.decls))
        self.shift_of = lambda n: len(decls) if n >= self.anchor else 0   # SRC line index -> shift in self.lines
        self.body = body + self.shift_of(body)
        self.lines = self.plain[:self.anchor] + decls + self.plain[self.anchor:]

    def analyse(self, lines, listing=False):
        obj, log, asm = self.b.compile('\n'.join(lines), self.crlf, ('/FAcs', '/Fa') if listing else ())
        if obj is None:
            return None, log
        try:
            an = Analysis(obj, self.needle, self.rva)
            if listing:
                an.asm_text = open(asm, encoding='latin-1').read()
            return an, ''
        except LookupError as e:
            return None, str(e)
        finally:
            self.b.done(obj, asm)

    def run(self):
        base, log = self.analyse(self.plain)
        if base is None:
            raise SystemExit('the source does not compile:\n' + log[-2000:])
        ours = len([c for c in base.our_calls if PROBE not in c.text])
        print('0x%x %s: %s, %d exe calls, %d ours' % (self.rva, base.symbol, base.res, len(base.exe_calls), ours))
        if not base.sites:
            print('no differing inlining decisions')
            return
        print('%s:' % plural(len(base.sites), 'differing decision'))
        for s in base.sites:
            where = 'exe 0x%08x' % s.call.at if s.side == 'exe' else 'ours +0x%x' % (s.call.at - base.va)
            print('  %s at %s: %s' % (describe(s.callee), where, direction(s)))
        if self.a.no_measure:
            return
        ref, log = self.analyse(self.lines)
        listed, log2 = self.analyse(self.lines, listing=True)
        if ref is None or listed is None:
            raise SystemExit("the source does not compile with the probes' declarations:\n" + (log or log2)[-2000:])
        if listed.res.size != ref.res.size or listed.res.lines != ref.res.lines:
            print("note: the listing build's code differs, so its line numbers may be off")
        if [s.ident for s in ref.sites] != [s.ident for s in base.sites]:
            print("note: with the probes' declarations added, the differing decisions are:"
                  + ''.join('\n  %s' % describe(s.callee) for s in ref.sites))
        offsets = listing_lines(listed.asm_text, ref.symbol)
        if not offsets:
            print('note: no source lines found in the listing for %s; pass --site-line' % ref.symbol)
        for s in ref.sites:
            self.measure(s, ref, offsets)

    def sweep(self, site, label, kind, at):
        """The fewest copies of `kind` at line index `at` that flip the site's decision (batches of --jobs)."""
        ks = list(range(1, self.a.max + 1))
        jobs = max(1, self.a.jobs)
        for i in range(0, len(ks), jobs):
            batch = ks[i:i + jobs]
            with cf.ThreadPoolExecutor(jobs) as ex:
                res = list(ex.map(lambda k: self.analyse(fs.insert_all(self.lines, [(at, fs.copies(kind, k))])), batch))
            for k, (now, log) in zip(batch, res):
                if now is None:
                    print('  %s: build failed at %d (%s)' % (label, k, log.strip().splitlines()[-1][:120] if log.strip() else ''))
                    return None
                if kind is self.spend and now.probe_calls:
                    print('  %s: the probes stopped expanding at %d, before the decision flipped' % (label, k))
                    return None
                if site.ident not in {s.ident for s in now.sites}:
                    left = len(now.sites)
                    print('  %s: flips at %d (%s still differ%s)' % (label, k, plural(left, 'decision'), 's' if left == 1 else ''))
                    return k
        print('  %s: no flip up to %d' % (label, self.a.max))
        return None

    def measure(self, site, ref, offsets):
        lines, a = self.lines, self.a
        print('\n%s (%s):' % (describe(site.callee), direction(site)))
        number = (a.site_line + self.shift_of(a.site_line - 1)) if a.site_line else site_line(site, ref, offsets)
        tgt = fs.body_span(lines, self.body)
        if number is None or not tgt[0] < number - 1 < tgt[1]:
            print("  its statement (listing line %s) is not inside the target's body: pass --site-line" % number)
            return
        start = number - 1
        end = statement_end(lines, start)
        src_line = start + 1 - (self.shift_of(start) if start >= self.anchor else 0)
        print('  under SRC line %d: %s' % (src_line, lines[start].strip()))
        if site.side == 'ours':
            k = self.sweep(site, 'trivial inline calls before it', self.fold, start)
            if k:
                print('    = shortfall %d..%d units of pool (above the floor)' % (2 * (k - 1), 2 * k))
            return
        k = self.sweep(site, 'trivial inline calls after it', self.fold, end + 1)
        if k:
            print('    = %s to the end of the body' % plural(k, 'more inline site'))
        j = self.sweep(site, 'spend probes (%d units each) before it' % a.spend, self.spend, start)
        if j:
            print('    = slack %d..%d units of the pool left at the site' % ((j - 1) * a.spend, j * a.spend))
        for name, span in callee_spans(lines, lines[start:end + 1], tgt).items():
            k = self.sweep(site, 'trivial inline calls at the end of %s' % name, self.fold, fs.insertion(lines, span, 'end'))
            if k:
                print("    = %s in %s's body" % (plural(k, 'more inline site'), name))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--src', required=True)
    ap.add_argument('--anchor', required=True)
    ap.add_argument('--body-anchor', help='unique text before the body that holds the site, when it is not the '
                    "target's own (a synthetic _$E initializer/destructor: the inline destructor it expands)")
    ap.add_argument('--target', required=True, type=fs.target_arg)
    ap.add_argument('--preset', default='m85', choices=['m85', 'ra2'])
    ap.add_argument('--inc', action='append', default=[])
    ap.add_argument('--max', type=int, default=12)
    ap.add_argument('--spend', type=int, default=8)
    ap.add_argument('--site-line', type=int)
    ap.add_argument('--no-measure', action='store_true')
    ap.add_argument('--out')
    ap.add_argument('--jobs', type=int, default=2)
    ap.add_argument('--keep', action='store_true')
    Budget(ap.parse_args()).run()


if __name__ == '__main__':
    sys.exit(main())
