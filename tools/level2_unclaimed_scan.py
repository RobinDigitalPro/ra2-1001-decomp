"""Find functions that a TU already compiles byte-identically to GAME.EXE 1.001 but that nobody has claimed yet.

usage: python -I level2_unclaimed_scan.py <tu> [<tu> ...]       e.g. src/m85/src/ownrdraw.cpp
       python -I level2_unclaimed_scan.py --all [--gaps FILE] [--limit N] [--start K]
  <tu>        TU path relative to P, exactly as in P/metadata/level2_functions.json
  --all       every claimed TU, one at a time, in order of unmatched gap bytes (level2_gaps.py output; the TU of
              an 'A | B' boundary gap counts for both), then the remaining claimed TUs by claim count
  --gaps FILE saved `level2_gaps.py 400` output to order by (otherwise level2_gaps.py is run once, ~1 min)
  --hold A,B  TU basenames under src/m85/src whose candidates are marked deliver_later (default: the files other
              agents are editing on 2026-11-22: dropship, sidebar, map, cell, planmgr, wonline)

Per TU:
  1. Compile it once with level2_check.compile_tu (same VC6 flags) into OUT/obj (never W/build/level2).
  2. Every emitted COFF function (one /Gy section each) that is not claimed is a candidate: a static function or
     _$E initializer counts as claimed only by (tu, symbol); any other symbol by its name in any TU.
  3. Byte search: relocated operands masked, the compiled size must fit exactly.  Start addresses are the
     function_map starts plus 16-aligned .text addresses after padding/ret (unclaimed regions); claimed, library
     and claim-overlapping places are excluded.  The original must end there (padding, a known start or a
     16-byte boundary) and must not extend a function_map extent with more code.
  4. Identical copies are resolved by callers: the relocation targets that the TU's claimed functions (and, in
     later rounds, the newly placed candidates) require for the symbol, and the slots of this object's vtables
     that RTTI places exactly (lc.vtable_address; a weak-external ??_E slot counts for its ??_G default).  Without such evidence a byte match is taken only when it is
     unique, at least MIN_UNIQUE bytes, and no claimed function has the same bytes (GAME.EXE folds identical
     tiny functions: e.g. OwnerDraw::SimpleDialogControl::Is_Cancelled's vtable slot points at 0x1f8e40, which is
     claimed as XSurface::Is_Direct_Draw).  Contradictions and ambiguity are reported, never guessed.
  5. Scratch ci-style verification, in process, with level2_check.main itself: pass 0 (current claims), pass A
     (plus the candidates), level2_autobind-style evidence for the candidates' 'no evidence' bindings, pass B.
     A candidate is kept only when its status is 'matched', it is not part of a symbol conflict (the
     ci_verify rule), and no existing claim of the TU that matched in pass 0 stops matching.  Pass B is repeated
     without the dropped ones until stable.
Outputs (only under OUT = W/analysis/level2/agents/b11_scan):
  <name>.claims.json  verified candidates in the agent claims format (tu, functions, symbols) for
                      level2_integrate_agent.py <tu> <OUT> --claims <file> --no-append (written only if non-empty)
  <name>.scan.json    everything: candidates, rejections with reasons, ambiguous copies, pass summaries
  check/<name>_<pass>.json  the scratch level2_check reports;  summary.jsonl one line per scanned TU
Read-only on P (sources and metadata) and on W/analysis/level2/reports; one compile at a time.

B15 cross-TU mode (2026-11-22):  python -I level2_unclaimed_scan.py --xtu [--report R] [--prev DIR] [<tu> ...]
  Outputs go to OUT15 = W/analysis/level2/agents/b15_scan (xtu_survey.json, <name>.scan.json/.claims.json, check/,
  obj/, summary.jsonl).  Default hold list: dropship, sidebar, house, building, wonline (claims of held TUs are not
  written; their candidates stay in scan.json as deliver_later).
  Evidence (XEvidence): the newest full check report (newest file within 90% of the largest check_*.json) gives, for
  every claimed function that matched, the (symbol, original address) of each relocation site.  The W/build/level2
  object of each unit is read only if its sha256 equals the report's object_sha256 (otherwise that TU is skipped as
  stale).  Ties are expanded from those roots through (a) function copies that are byte-identical (no relocation
  problems) at an unclaimed tied address, taking their own relocations in turn, and (b) slots of vtables whose
  address the report verified, read from the object that defines the ??_7.  A claimed address is never expanded
  (it is a root in its own claiming TU).  A static function or _$E helper is tied only within its own TU; any other
  symbol by name in all TUs.
  Rule: an ambiguous candidate (TU, S) is accepted for verification only when all its ties name one address X, X is
  one of its admissible byte matches, X is not claimed, and no other symbol (claims, level2_symbols.json or another
  tie; ??_E counts as its ??_G) is bound to X: two names on one address are linker folding or a duplicate
  reconstruction and are reported, never claimed.  The unique-byte-match path is off in this mode.  Accepted
  candidates then go through the same scan_tu placement and scratch ci-style verification as above.
  --xtu without TUs surveys every ambiguous entry of --prev (default b11_scan) into xtu_survey.json and scans only the
  TUs that gained an acceptable tie.  'forward_only_report' entries (byte matches consistent with the candidate's own
  outgoing relocations: RTTI vtables, claims, bound symbols) are information only, not an acceptance rule.
  First run (report check_2026-11-22T185637Z, b11 ambiguous set of 561): 0 accepted, 3 contradictions (callers tie
  the symbol to an address claimed or bound under another name), 558 without any cross-TU tie, 10 forward-only.

B18 forward-evidence mode (coordinator decision 2026-11-22):  python -I level2_unclaimed_scan.py --forward [--survey-only]
  [--report R] [--hold A,B] [<tu> ...]
  Outputs only under OUT18 = W/analysis/level2/agents/b18_scan: forward_survey.json, <name>.scan.json, <name>.claims.json
  (not for held TUs), check/, obj/, summary.jsonl.  Default hold: building, techno, dropship, sidebar, house.
  Rule (the normal ci_verify binding evidence, applied to the candidate's OWN relocations):
    survey (no compile; W/build/level2 objects whose sha256 equals the newest full report, stale TUs compiled once into
    OUT18/obj): every unclaimed emitted function with >= 1 relocation; admissible byte matches as in scan_tu; per match
    each relocation is classified by XEvidence.known (claims, symbol map, RTTI vtable, a single cross-TU tie).  Exactly
    one match may have >= 1 confirming and no contradicting relocation; that address must be unclaimed, no other name
    may be claimed/bound/tied there (??_E = ??_G), the symbol itself must not be tied elsewhere, and no other candidate
    of a different name may choose it (an inline/template emitted by several TUs is delivered by one TU only).
    verify (fresh compile per TU, one at a time; in-process level2_check.main): pass 0 = current claims; pass A = the
    candidates at their address WITHOUT autobind, so every binding must verify with existing evidence (status
    'matched'), not through another new candidate, not in a symbol conflict, and no existing claim of the TU may stop
    matching; then each alternative byte match (up to MAX_ALT) is checked the same way: if all relocations also verify
    there, the candidate is not unique and is dropped; a final pass with exactly the delivered set.
  First run (2026-11-22, report check_2026-11-22T185637Z, 684 TUs): 3 survey candidates, 8 not unique (4 pairs of
  byte-identical functions whose relocations fit both addresses), 2 delivered (WDTSel ??_G rc_ptr<Conflict> 0x31c880,
  VECTOR_INSTANCES DynamicVectorClass<CellClass*> ctor 0x319290); ownrdraw _$E109 0x1d73b0 blocked by its atexit
  helper _$E107 (Control_Table destructor) which does not match at 0x1d7450.
"""
import argparse, bisect, builtins, contextlib, io, json, os, re, struct, subprocess, sys, time

P = r'D:\<project-folder>\Coding\RedAlert2'
W = r'D:\<work-root>\RedAlert2Temp'
sys.path.insert(0, os.path.join(W, 'tools')); sys.path.insert(0, os.path.join(W, 'analysis', 'level2'))
import level2_check as lc  # noqa: E402
from coffmatch import Obj, match_function  # noqa: E402

OUT = os.path.join(W, 'analysis', 'level2', 'agents', 'b11_scan')
HOLD_DEFAULT = 'dropship.cpp,sidebar.cpp,map.cpp,cell.cpp,planmgr.cpp,wonline.cpp'
PAD = (0xCC, 0x90)
MIN_UNIQUE = 32   # a unique byte match without caller/vtable evidence counts only from this size, and only when no claimed copy has the same bytes

# ---------------------------------------------------------------- static inputs (loaded once)
_IMG = lc.image()
B, SECS = _IMG
TEXT = next(s for s in SECS if s[0] == '.text')
VA0 = 0x400000 + TEXT[1]
TB = lc.read(B, SECS, VA0, min(TEXT[2], TEXT[3]))
TEND = VA0 + len(TB)
FMAP = json.load(open(os.path.join(W, 'analysis', 'level2', 'function_map.json')))['map']
MAP_END = {}
for e in FMAP:
    a = int(e['rva'], 16) + 0x400000
    MAP_END[a] = max(int(r[1], 16) for r in e['ranges']) + 0x400000 if e.get('ranges') else a + e['size']
CATALOG = json.load(open(lc.RTTI))
LIB = {int(x['rva'], 16) + 0x400000: int(x['size']) for x in json.load(open(os.path.join(P, 'metadata', 'level2_library.json')))['functions']}


def demangle(s):
    """Readable name for the claims file (simple cases only; the symbol is authoritative)."""
    m = re.match(r'\?\?([01])((?:\w+@)+)@', s)
    if m:
        parts = m.group(2).rstrip('@').split('@'); cls = '::'.join(reversed(parts))
        return '%s::%s%s' % (cls, '~' if m.group(1) == '1' else '', parts[0])
    m = re.match(r'\?([A-Za-z_]\w*)@((?:\w+@)*)@', s)
    if m:
        return '::'.join(list(reversed(m.group(2).rstrip('@').split('@'))) + [m.group(1)]) if m.group(2) else m.group(1)
    return s


def tuname(tu):
    t = tu[4:] if tu.startswith('src/') else tu
    return os.path.splitext(t.replace('/', '_'))[0]


class Snapshot:
    """Claims and the derived search space, read once per TU (other agents may integrate meanwhile)."""

    def __init__(self):
        self.claims = json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))
        self.symmap = json.load(open(os.path.join(P, 'metadata', 'level2_symbols.json'), encoding='utf-8'))
        self.claimed_rva = {int(f['rva'], 16) + 0x400000 for f in self.claims}
        self.by_sym = {}
        self.by_tusym = set()
        for f in self.claims:
            self.by_sym.setdefault(f['symbol'], set()).add(int(f['rva'], 16) + 0x400000)
            self.by_tusym.add((f['tu'], f['symbol']))
        known = sorted(set(MAP_END) | self.claimed_rva | set(LIB))
        self.known = set(known)
        iv = []   # claimed / library extents
        for a in self.claimed_rva | set(LIB):
            if a in LIB:
                end = a + LIB[a]
            elif a in MAP_END:
                end = MAP_END[a]
            else:
                i = bisect.bisect_right(known, a); end = known[i] if i < len(known) else a + 1
            iv.append((a, max(end, a + 1)))
        iv.sort(); self.iv = iv; self.iv_starts = [x[0] for x in iv]
        starts = set(a for a in MAP_END if VA0 <= a < TEND)
        for a in range(((VA0 + 15) & ~15) + 16, TEND, 16):
            o = a - VA0
            p = TB[o - 1]
            if p in (0xCC, 0x90, 0xC3) or (TB[o - 3] == 0xC2 and TB[o - 1] == 0):
                starts.add(a)
        starts = {a for a in starts if a not in self.claimed_rva and not self.inside_claim(a)}
        self.starts = sorted(starts)
        self._idx = {}

    def index(self, k):
        """candidate starts keyed by the 4 original bytes at offset k (built on first use)"""
        if k not in self._idx:
            d = {}
            for a in self.starts:
                d.setdefault(TB[a - VA0 + k:a - VA0 + k + 4], []).append(a)
            self._idx[k] = d
        return self._idx[k]

    def inside_claim(self, a, end=None):
        """True when [a, end) (or the byte a) lies in or overlaps a claimed/library extent."""
        end = end or a + 1
        i = bisect.bisect_right(self.iv_starts, end - 1) - 1
        while i >= 0:
            s, e = self.iv[i]
            if e > a and s < end:
                return True
            if s < a - 0x20000:
                break
            i -= 1
        return False

    def is_claimed(self, tu, sym, storage):
        if storage == 3 or sym.startswith('_$E'):
            return (tu, sym) in self.by_tusym
        return sym in self.by_sym


def weak_aliases(obj):
    """name -> default symbol name for COFF weak externals (storage class 105), e.g. a vtable's ??_E vector
    deleting destructor that VC6 aliases to the emitted ??_G scalar deleting destructor"""
    data = obj.data
    _, _, _, symptr, nsym, _, _ = struct.unpack_from('<HHIIIHH', data, 0)
    out, i = {}, 0
    while i < nsym:
        o = symptr + 18 * i
        _, sec, _, cls, aux = struct.unpack_from('<IhHBB', data, o + 8)
        if cls == 105 and aux and i in obj.by_index:
            tag = struct.unpack_from('<I', data, o + 18)[0]
            if tag in obj.by_index:
                out[obj.by_index[i]['name']] = obj.by_index[tag]['name']
        i += 1 + aux
    return out


def masked(sec):
    raw = sec['raw']; m = bytearray(len(raw))
    for off, _, _ in sec['relocs']:
        for k in range(4):
            if off + k < len(raw):
                m[off + k] = 1
    segs, i = [], 0   # unmasked runs
    while i < len(raw):
        if m[i]:
            i += 1; continue
        j = i
        while j < len(raw) and not m[j]:
            j += 1
        segs.append((i, j)); i = j
    return raw, segs


def byte_hits(snap, raw, segs):
    n = len(raw)
    anchor = next((i for i, j in segs if j - i >= 4 and i < 64), None)
    cands = snap.index(anchor).get(bytes(raw[anchor:anchor + 4]), []) if anchor is not None else snap.starts
    out, claimed_copies = [], []
    for a in cands:
        o = a - VA0
        if o + n > len(TB):
            continue
        if all(TB[o + i:o + j] == raw[i:j] for i, j in segs):
            out.append(a)
    # identical bytes at a claimed RVA (copy of a claimed function): information only
    for a in snap.claimed_rva:
        if VA0 <= a < TEND - n and TB[a - VA0:a - VA0 + min(4, n)] == raw[:min(4, n)] and all(TB[a - VA0 + i:a - VA0 + j] == raw[i:j] for i, j in segs):
            claimed_copies.append(a)
    return out, claimed_copies


def end_ok(snap, a, n):
    e = a + n
    if snap.inside_claim(a, e):
        return False, 'overlaps a claimed/library extent'
    if a in MAP_END and MAP_END[a] > e:
        rest = TB[e - VA0:MAP_END[a] - VA0]
        if any(c not in PAD for c in rest):
            return False, 'function_map extent continues with code to %s' % hex(MAP_END[a] - 0x400000)
    if e in snap.known or e % 16 == 0 or (e < TEND and TB[e - VA0] in PAD):
        return True, ''
    return False, 'original continues after the compiled size'


# ---------------------------------------------------------------- scratch level2_check.main
class _Json:
    def __init__(self, extra_claims, extra_syms):
        self.extra_claims, self.extra_syms = extra_claims, extra_syms

    def __getattr__(self, k):
        return getattr(json, k)

    def load(self, fp, *a, **k):
        d = json.load(fp, *a, **k)
        name = getattr(fp, 'name', '')
        if name.endswith('level2_functions.json'):
            have = {f['rva'] for f in d}
            d = d + [f for f in self.extra_claims if f['rva'] not in have]
        elif name.endswith('level2_symbols.json'):
            d = dict(d); d.update({s: e for s, e in self.extra_syms.items() if s not in d})
        return d


def scratch_check(tu, obj_path, info, tag, extra_claims=(), extra_syms=None):
    rep_path = os.path.join(OUT, 'check', '%s_%s.json' % (tuname(tu), tag))
    os.makedirs(os.path.dirname(rep_path), exist_ok=True)

    def compile_tu(t, outdir):
        if t == tu:
            return obj_path, dict(info)
        return os.path.join(OUT, 'obj', '<not compiled>'), dict(command='not compiled (scan of %s only)' % tu, returncode=1, output='')

    def myopen(p, *a, **k):
        if isinstance(p, str):
            n = os.path.normcase(os.path.abspath(p))
            if n.startswith(os.path.normcase(P)) and a and ('w' in a[0] or 'a' in a[0] or '+' in a[0]):
                raise RuntimeError('refusing to write into P: %s' % p)
            if os.sep + 'reports' + os.sep in p and 'check_' in p:
                p = rep_path
        return builtins.open(p, *a, **k)
    saved = (lc.compile_tu, lc.json, getattr(lc, 'open', builtins.open), lc.image, sys.argv)
    lc.compile_tu, lc.json, lc.open, lc.image = compile_tu, _Json(list(extra_claims), extra_syms or {}), myopen, (lambda: _IMG)
    sys.argv = ['level2_check.py', tu]
    buf = io.StringIO()
    try:
        with contextlib.redirect_stdout(buf):
            lc.main()
    finally:
        lc.compile_tu, lc.json, lc.open, lc.image, sys.argv = saved
    rep = json.load(open(rep_path))
    rep['functions'] = [f for f in rep['functions'] if f.get('tu') == tu]
    return rep


def conflict_bad(rep, new):
    """ci_verify rule: a new claim that binds a symbol taking part in a conflict is dropped."""
    import ast
    bad = set()
    for c in rep['symbol_conflicts']:
        try:
            ctu, sym = ast.literal_eval(c['symbol'])
        except Exception:
            ctu, sym = None, c['symbol']
        for f in rep['functions']:
            if f['rva'] in new and (ctu is None or f.get('tu') == ctu) and any(b['symbol'] == sym and b['address'] in c['addresses'] for b in f.get('bindings', [])):
                bad.add(f['rva'])
    return bad


def autobind(rep, new, syms):
    """level2_autobind.py --data rules, applied only to the bindings of the new claims."""
    starts = {a for a in MAP_END}
    starts |= {int(json.loads(l)['rva'], 16) + 0x400000 for l in open(lc.FUNCS)}
    add = {}
    for f in rep['functions']:
        if f['rva'] not in new:
            continue
        for b in f.get('bindings', []):
            s = b['symbol']
            if b['verified'] or b['evidence'] != 'no evidence' or s in syms or s in add or s.startswith(('_$', '__imp__', '??_C@')):
                continue
            a = int(b['address'], 16)
            if 0x401000 <= a < 0x785000:
                add[s] = dict(address=hex(a), evidence='function_start' if a in starts else 'aligned_start',
                              note='call target of a b11 scan claim (level2_autobind rule); verified by level2_check')
            elif s.startswith(('?', '_')) and not s.startswith('??_'):
                add[s] = dict(address=hex(a), evidence='data',
                              note='data address of a b11 scan claim (level2_autobind --data rule); verified by level2_check')
    return add


# ---------------------------------------------------------------- one TU
def scan_tu(tu, hold, xev=None):
    """xev: XEvidence (B15 mode): cross-TU ties count as caller evidence, folding guard, caller evidence only"""
    t0 = time.time()
    snap = Snapshot()
    name = tuname(tu)
    objdir = os.path.join(OUT, 'obj'); os.makedirs(objdir, exist_ok=True)
    obj_path, info = lc.compile_tu(tu, objdir)
    info['source_sha256'] = __import__('hashlib').sha256(open(os.path.join(P, tu), 'rb').read()).hexdigest()
    res = dict(tu=tu, deliver_later=os.path.basename(tu).lower() in hold and tu.startswith('src/m85/src/'),
               compile=dict(returncode=info['returncode'], command=info['command']), candidates=[], rejected=[], ambiguous=[])
    if info['returncode'] != 0 or not os.path.exists(obj_path):
        res['error'] = 'compile failed: ' + info.get('output', '')[-800:]
        return finish(res, t0)
    obj = Obj(open(obj_path, 'rb').read())
    # emitted functions
    emitted = {}
    for sym, s in obj.symbols.items():
        if s['value'] != 0:
            continue
        emitted[sym] = s
    mine = [f for f in snap.claims if f['tu'] == tu]
    unclaimed = {s: x for s, x in emitted.items() if not snap.is_claimed(tu, s, x['storage'])}
    res['emitted'] = len(emitted); res['claimed_here'] = len(mine); res['unclaimed'] = len(unclaimed)

    # caller requirements from the TU's claimed functions
    req = {}

    def add_req(sym, va, frm):
        if sym not in obj.symbols:
            return
        sec = obj.function(sym)
        r = match_function(obj, sym, lc.read(B, SECS, va, len(sec['raw'])), va, lambda s: None)
        if r.get('byte_differences') != 0:
            return
        for b in r['unresolved_bindings']:
            if b['symbol'] in unclaimed:
                req.setdefault(b['symbol'], {}).setdefault(int(b['required_address'], 16), set()).add(frm)
    for f in mine:
        add_req(f['symbol'], int(f['rva'], 16) + 0x400000, f['rva'])
    alias = weak_aliases(obj)
    # vtables this object defines and RTTI places exactly: each slot relocation names the original slot address
    for x in obj.by_index.values():
        if not x['name'].startswith('??_7') or x['section'] <= 0:
            continue
        v = lc.vtable_address(CATALOG, x['name'])
        if v is None:
            continue
        vsec = obj.sections[x['section'] - 1]
        for off, si, typ in vsec['relocs']:
            t = obj.by_index[si]['name']
            t = alias.get(t, t)
            if typ != 6 or off < x['value'] or t not in unclaimed:
                continue
            raw = lc.read(B, SECS, v + off - x['value'], 4)
            if raw:
                req.setdefault(t, {}).setdefault(int.from_bytes(raw, 'little'), set()).add('vtable %s+0x%x' % (hex(v - 0x400000), off - x['value']))

    hits = {}
    for sym, x in unclaimed.items():
        sec = obj.function(sym)
        raw, segs = masked(sec)
        if not raw:
            continue
        cand, copies = byte_hits(snap, raw, segs)
        good, why = [], {}
        for a in cand:
            ok, w = end_ok(snap, a, len(raw))
            (good.append(a) if ok else why.__setitem__(hex(a - 0x400000), w))
        if good or why or copies:
            hits[sym] = dict(size=len(raw), good=good, end_rejected=why, claimed_copies=[hex(a - 0x400000) for a in copies])

    xinfo = {}
    if xev is not None:   # B15: cross-TU caller evidence, merged into the same-TU requirements
        for sym, h in hits.items():
            c, a, info = xev.classify(tu, sym, [hex(x - 0x400000) for x in h['good']])
            if c != 'none':
                xinfo[sym] = dict(cross_tu=c, rva=hex(a - 0x400000) if a else None, evidence=info)
            if c == 'accept':
                req.setdefault(sym, {}).setdefault(a, set()).update('xtu ' + x for x in info[:3])
    res['cross_tu'] = xinfo
    placed = {}   # sym -> (va, how)
    for _ in range(6):   # placed candidates contribute caller requirements in turn
        changed = False
        for sym, h in hits.items():
            if sym in placed:
                continue
            r = req.get(sym, {})
            if r:
                if len(r) == 1 and next(iter(r)) in h['good']:
                    a = next(iter(r))
                    if xev is not None and (xev.others_at(a, sym) or a in snap.claimed_rva):
                        xinfo.setdefault(sym, {})['folding'] = xev.others_at(a, sym)[:8] or ['<claimed RVA>']; continue
                    placed[sym] = (a, 'caller ' + ','.join(sorted(r[a])))
                    add_req(sym, a, hex(a - 0x400000)); changed = True
            elif xev is None and len(h['good']) == 1 and h['size'] >= MIN_UNIQUE and not h['claimed_copies']:
                a = h['good'][0]; placed[sym] = (a, 'unique byte match (no caller evidence)')
                add_req(sym, a, hex(a - 0x400000)); changed = True
        if not changed:
            break
    # one RVA, several symbols: keep only a single caller-resolved one
    by_va = {}
    for sym, (a, how) in placed.items():
        by_va.setdefault(a, []).append(sym)
    for a, syms in by_va.items():
        if len(syms) > 1:
            callers = [s for s in syms if placed[s][1].startswith('caller')]
            keep = callers[0] if len(callers) == 1 else None
            for s in syms:
                if s != keep:
                    res['ambiguous'].append(dict(symbol=s, rva=hex(a - 0x400000), reason='several symbols match the same RVA: %s' % [y[:50] for y in syms]))
                    del placed[s]
    for sym, h in hits.items():
        if sym in placed:
            continue
        r = req.get(sym, {})
        entry = dict(symbol=sym, size=h['size'], byte_matches=[hex(a - 0x400000) for a in h['good']], end_rejected=h['end_rejected'],
                     claimed_copies=h['claimed_copies'], caller_required={hex(a - 0x400000): sorted(v) for a, v in r.items()})
        if not h['good']:
            entry['reason'] = 'no admissible byte match'; res['rejected'].append(entry)
        elif r:
            entry['reason'] = 'callers require an address without an admissible byte match, or several addresses'; res['rejected'].append(entry)
        elif len(h['good']) > 1:
            entry['reason'] = '%d identical copies and no claimed caller' % len(h['good']); res['ambiguous'].append(entry)
        else:
            entry['reason'] = ('identical copies at claimed RVAs and no caller evidence' if h['claimed_copies'] else
                               'unique match of a function under %d bytes without caller evidence' % MIN_UNIQUE); res['ambiguous'].append(entry)
    new = [dict(rva=hex(a - 0x400000), tu=tu, symbol=s, name=demangle(s)) for s, (a, how) in sorted(placed.items(), key=lambda kv: kv[1][0])]
    res['candidates'] = [dict(rva=hex(a - 0x400000), symbol=s, size=hits[s]['size'], resolved_by=how) for s, (a, how) in sorted(placed.items(), key=lambda kv: kv[1][0])]
    if not new:
        return finish(res, t0)

    # scratch ci-style verification with level2_check.main
    base = scratch_check(tu, obj_path, info, 'pass0')
    base_ok = {f['rva'] for f in base['functions'] if f['status'] == 'matched'}
    res['pass0'] = '%d/%d existing claims matched' % (len(base_ok), len(base['functions']))
    newrva = {c['rva'] for c in new}
    ra = scratch_check(tu, obj_path, info, 'passA', new)
    syms = autobind(ra, newrva, snap.symmap)
    keep = list(new); dropped = {}
    for rnd in range(4):
        rb = scratch_check(tu, obj_path, info, 'passB%d' % rnd, keep, syms)
        kr = {c['rva'] for c in keep}
        bad = conflict_bad(rb, kr)
        for f in rb['functions']:
            if f['rva'] in kr and f['status'] != 'matched':
                bad.add(f['rva'])
                dropped[f['rva']] = dict(symbol=f['symbol'], status=f['status'], byte_differences=f.get('byte_differences'),
                                         unverified=[(b['symbol'][:70], b['address'], b['evidence'][:90]) for b in f.get('bindings', []) if not b['verified']][:6])
        for r in bad - set(dropped):
            dropped[r] = dict(reason='binds a symbol in a symbol conflict')
        lost = [f['rva'] for f in rb['functions'] if f['rva'] in base_ok and f['status'] != 'matched']
        if lost:
            res['lost_existing'] = lost
            res['verification'] = 'existing claims stop matching with the candidates; nothing delivered'
            keep = []; break
        if not bad:
            res['verification'] = 'pass B round %d: %d/%d candidates matched, no conflicts, %d existing claims unchanged' % (rnd, len(keep), len(new), len(base_ok))
            break
        keep = [c for c in keep if c['rva'] not in bad]
        if not keep:
            res['verification'] = 'no candidate survived'; break
    else:
        keep = []; res['verification'] = 'did not converge'
    res['dropped_by_check'] = dropped
    used = set()
    for f in (rb['functions'] if keep else []):
        if f['rva'] in {c['rva'] for c in keep}:
            used |= {b['symbol'] for b in f.get('bindings', [])}
    res['verified'] = [dict(c, size=hits[c['symbol']]['size'], resolved_by=placed[c['symbol']][1]) for c in keep]
    if keep and not (xev is not None and res['deliver_later']):   # B15: held TUs are listed in scan.json only
        claims = dict(tu=tu, source='level2_unclaimed_scan.py (%s): already emitted, unclaimed, byte-identical; scratch ci-style check passed' % ('B15 cross-TU' if xev is not None else 'B11'),
                      deliver_later=res['deliver_later'],
                      functions=[dict(rva=c['rva'], symbol=c['symbol'], name=c['name'], status='matched',
                                      size=hits[c['symbol']]['size'], resolved_by=placed[c['symbol']][1]) for c in keep],
                      symbols={s: e for s, e in syms.items() if s in used})
        json.dump(claims, open(os.path.join(OUT, name + '.claims.json'), 'w', encoding='utf-8'), indent=1)
    return finish(res, t0)


def finish(res, t0):
    res['seconds'] = round(time.time() - t0, 1)
    name = tuname(res['tu'])
    json.dump(res, open(os.path.join(OUT, name + '.scan.json'), 'w', encoding='utf-8'), indent=1)
    line = dict(tu=res['tu'], unclaimed=res.get('unclaimed'), candidates=len(res['candidates']), verified=len(res.get('verified', [])),
                ambiguous=len(res['ambiguous']), deliver_later=res['deliver_later'], seconds=res['seconds'], error=res.get('error', '')[:200])
    with open(os.path.join(OUT, 'summary.jsonl'), 'a', encoding='utf-8') as fp:
        fp.write(json.dumps(line) + '\n')
    print('%-45s unclaimed %4s cand %3d verified %3d ambiguous %3d %s%.0fs' % (res['tu'][-45:], res.get('unclaimed'), len(res['candidates']),
          len(res.get('verified', [])), len(res['ambiguous']), 'HOLD ' if res['deliver_later'] else '', res['seconds']), flush=True)
    for v in res.get('verified', []):
        print('    %s %5d  %s  (%s)' % (v['rva'], v['size'], v['symbol'][:80], v['resolved_by'][:40]), flush=True)
    return res


# ---------------------------------------------------------------- B15: cross-TU caller evidence
OUT15 = os.path.join(W, 'analysis', 'level2', 'agents', 'b15_scan')
HOLD15 = 'dropship.cpp,sidebar.cpp,house.cpp,building.cpp,wonline.cpp'
REPORTS = os.path.join(W, 'analysis', 'level2', 'reports')
BUILD = os.path.join(W, 'build', 'level2')


def newest_full_report():
    """the newest of the full check reports (files within 90% of the largest size; single-TU reports are tiny)"""
    import glob
    fs = [(os.path.getsize(f), os.path.getmtime(f), f) for f in glob.glob(os.path.join(REPORTS, 'check_*.json'))]
    big = max(s for s, _, _ in fs)
    return max((m, f) for s, m, f in fs if s >= 0.9 * big)[1]


def build_obj_path(tu):
    """object that level2_check.compile_tu writes into W/build/level2 for this TU (read only here)"""
    base = os.path.splitext(os.path.basename(tu))[0]
    if tu.endswith('.asm'):
        return os.path.join(BUILD, 'asm_' + base + '.obj')
    return os.path.join(BUILD, ('m85_' if tu.startswith('src/m85/') else '') + base + '.obj')


def gname(s):
    """symbol identity for folding checks: a vtable's ??_E slot aliases the ??_G default (same function)"""
    return '??_G' + s[4:] if s.startswith('??_E') else s


class XEvidence:
    """Cross-TU caller evidence (B15).  Edges are (context TU, symbol, original address) ties, each made at a verified
    site: a relocation of a claimed function that matched in the full check report (its bindings), a relocation of a
    function copy that is itself byte-identical at an address reached that way, or a slot of a vtable whose address
    was verified (RTTI) and whose defining object we have.  The context TU decides TU-local identity: a static
    function or _$E helper is tied only within its own TU, any other symbol by name in every TU."""

    def __init__(self, report_path, snap, max_depth=8):
        t0 = time.time()
        self.report_path = report_path
        rep = json.load(open(report_path))
        self.objs, self.stale, self.alias = {}, [], {}
        for tu, info in rep['units'].items():
            p = build_obj_path(tu)
            try:
                data = open(p, 'rb').read()
            except OSError:
                self.stale.append((tu, 'object missing')); continue
            if __import__('hashlib').sha256(data).hexdigest() != info.get('object_sha256'):
                self.stale.append((tu, 'object rebuilt after the report')); continue   # bindings no longer describe it
            self.objs[tu] = Obj(data)
        self.defs, self.vdefs = {}, {}
        for tu, o in self.objs.items():
            for n, s in o.symbols.items():
                if s['storage'] == 2:
                    self.defs.setdefault(n, []).append(tu)
            for x in o.by_index.values():
                if x['name'].startswith('??_7') and x['section'] > 0:
                    self.vdefs.setdefault(x['name'], []).append(tu)
        self.ties = {}       # (tu or None, symbol) -> {address: set(source)}
        self.verified_copies = {}   # (key, address) -> source tu of the bytes
        self.claim_at = {}
        for f in snap.claims:
            self.claim_at.setdefault(int(f['rva'], 16) + 0x400000, set()).add(gname(f['symbol']))
        self.sym_at = {}
        for s, e in snap.symmap.items():
            try:
                self.sym_at.setdefault(int(e['address'], 16), set()).add(gname(s))
            except (KeyError, ValueError):
                pass
        self.snap = snap
        q, seen = [], set()
        roots = 0
        for f in rep['functions']:
            if f.get('status') != 'matched' or f.get('byte_differences') != 0 or f['tu'] not in self.objs:
                continue
            for b in {(b['symbol'], b['address'], b['verified']) for b in f.get('bindings', [])}:
                s, a, ver = b[0], int(b[1], 16), b[2]
                if s.startswith('??_7') and not ver:
                    continue
                q.append((f['tu'], s, a, 'claimed %s %s (%s)' % (f['rva'], f['symbol'][:48], f['tu'].split('/')[-1]), 0)); roots += 1
        while q:
            tu, s, a, src, depth = q.pop()
            o = self.objs[tu]
            if not self.is_code_symbol(o, s):
                continue
            k = self.key(tu, s)
            self.ties.setdefault(k, {}).setdefault(a, set()).add(src)
            if (k, a) in seen or depth >= max_depth:
                continue
            seen.add((k, a))
            if s.startswith('??_7'):
                q += self.vtable_edges(tu, s, a, depth)
            elif a not in snap.claimed_rva:
                # a claimed address is a root already, in the context of the TU that claims it: expanding another
                # TU's identical copy there would tie that TU's statics to the claim's helpers (netdlg2: src/ra2 and
                # src/m85 both define Send_Join_Queries; its _$E atexit helpers belong to the claiming src/ra2 TU)
                q += self.copy_edges(tu, s, a, depth)
        self.stats = dict(report=report_path, objects=len(self.objs), stale_objects=self.stale, root_edges=roots,
                          tied_symbols=len(self.ties), verified_copies=len(self.verified_copies), seconds=round(time.time() - t0, 1))

    @staticmethod
    def is_code_symbol(o, s):
        if s.startswith('??_7'):
            return True
        if s.startswith(('$', '__imp_', '??_C@', '__real@', '??_R')):
            return False
        if s in o.symbols:
            return True
        x = next((x for x in o.by_index.values() if x['name'] == s), None)
        return x is not None and x['section'] == 0 and (x['type'] >> 4) == 2   # undefined external function

    def key(self, tu, s):
        x = self.objs[tu].symbols.get(s)
        if s.startswith('_$E') or (x is not None and x['storage'] == 3):
            return (tu, s)
        return (None, s)

    def owners(self, tu, s, table):
        o = self.objs[tu]
        here = s in o.symbols if table is self.defs else any(x['name'] == s and x['section'] > 0 for x in o.by_index.values())
        return [tu] if here else [t for t in table.get(s, []) if t != tu]

    def copy_edges(self, tu, s, a, depth):
        if lc.section_of(SECS, a) != '.text':
            return []
        for d in self.owners(tu, s, self.defs)[:8]:
            o = self.objs[d]
            n = len(o.function(s)['raw'])
            r = match_function(o, s, lc.read(B, SECS, a, n), a, lambda _: None)
            if r.get('byte_differences') != 0 or r.get('relocation_problems'):
                continue
            self.verified_copies[(self.key(tu, s), a)] = d
            out = []
            for b in r['unresolved_bindings']:
                t = b['symbol']; ta = int(b['required_address'], 16)
                if t.startswith('??_7') and lc.vtable_address(CATALOG, t) != ta:
                    continue
                out.append((d, t, ta, 'via %s@%s (%s)' % (s[:48], hex(a - 0x400000), d.split('/')[-1]), depth + 1))
            return out
        return []

    def vtable_edges(self, tu, s, v, depth):
        own = self.owners(tu, s, self.vdefs)
        if not own:
            return []
        d = own[0]; o = self.objs[d]
        if d not in self.alias:
            self.alias[d] = weak_aliases(o)
        x = next(x for x in o.by_index.values() if x['name'] == s and x['section'] > 0)
        sec = o.sections[x['section'] - 1]
        later = sorted(y['value'] for y in o.by_index.values() if y['section'] == x['section'] and y['value'] > x['value'])
        end = later[0] if later else len(sec['raw'])
        out = []
        for off, si, typ in sec['relocs']:
            if typ != 6 or not (x['value'] <= off < end):
                continue
            t = o.by_index[si]['name']; t = self.alias[d].get(t, t)
            raw = lc.read(B, SECS, v + off - x['value'], 4)
            if raw:
                out.append((d, t, int.from_bytes(raw, 'little') - int.from_bytes(sec['raw'][off:off + 4], 'little'),
                            'vtable %s %s+0x%x' % (s[:48], hex(v - 0x400000), off - x['value']), depth + 1))
        return out

    def others_at(self, a, s):
        """different symbols already tied/claimed/bound at address a (linker folding or a duplicate reconstruction)"""
        names = set(self.claim_at.get(a, ())) | set(self.sym_at.get(a, ()))
        for (t, n), m in self.ties_by_addr().get(a, {}).items():
            names.add(gname(n))
        names.discard(gname(s))
        return sorted(names)

    def ties_by_addr(self):
        if not hasattr(self, '_tba'):
            self._tba = {}
            for k, m in self.ties.items():
                for a, src in m.items():
                    self._tba.setdefault(a, {})[k] = src
        return self._tba

    def classify(self, tu, sym, byte_matches):
        """('accept', va, sources) | ('folding', va, info) | ('contradiction', None, info) | ('none', None, None)"""
        k = (tu, sym) if (tu in self.objs and self.key(tu, sym)[0]) or sym.startswith('_$E') else (None, sym)
        m = self.ties.get(k, {})
        if not m:
            return 'none', None, None
        good = {int(x, 16) + 0x400000 for x in byte_matches}
        if len(m) != 1:
            return 'contradiction', None, dict(tied_addresses={hex(a - 0x400000): sorted(v)[:3] for a, v in m.items()})
        a, src = next(iter(m.items()))
        if a not in good:
            return 'contradiction', None, dict(tied_address=hex(a - 0x400000), sources=sorted(src)[:4], note='not an admissible byte match of our copy')
        oth = self.others_at(a, sym)
        if oth:
            return 'folding', a, dict(other_symbols=oth[:8], sources=sorted(src)[:4])
        if a in self.snap.claimed_rva:
            return 'folding', a, dict(other_symbols=['<claimed RVA>'], sources=sorted(src)[:4])
        return 'accept', a, sorted(src)

    def known(self, tu, s, a):
        """True / False / None: is (s, a) consistent with an established address (claims, symbol map, RTTI vtable,
        a single cross-TU tie)?  Used only for the report-only forward evidence."""
        if s.startswith('??_7'):
            v = lc.vtable_address(CATALOG, s)
            return None if v is None else v == a
        k = self.key(tu, s) if tu in self.objs else (None, s)
        if k[0] is not None:
            if (k[0], s) in self.snap.by_tusym:
                return a in {int(f['rva'], 16) + 0x400000 for f in self.snap.claims if f['tu'] == k[0] and f['symbol'] == s}
        elif s in self.snap.by_sym:
            return a in self.snap.by_sym[s]
        if k[0] is None and s in self.snap.symmap:
            try:
                return int(self.snap.symmap[s]['address'], 16) == a
            except (KeyError, ValueError):
                return None
        m = self.ties.get(k, {})
        return (a in m) if len(m) == 1 else None

    def forward(self, tu, sym, byte_matches):
        """REPORT ONLY (not an acceptance rule): which byte matches are consistent with the candidate's own outgoing
        relocations (vtable, callee and data addresses already established)."""
        o = self.objs.get(tu)
        if o is None or sym not in o.symbols:
            return None
        n = len(o.function(sym)['raw']); per = {}
        for x in byte_matches:
            a = int(x, 16) + 0x400000
            r = match_function(o, sym, lc.read(B, SECS, a, n), a, lambda _: None)
            ok = bad = 0
            for b in r.get('unresolved_bindings', []):
                v = self.known(tu, b['symbol'], int(b['required_address'], 16))
                ok += v is True; bad += v is False
            per[x] = (ok, bad)
        fit = [x for x, (ok, bad) in per.items() if ok and not bad]
        return dict(consistent=fit, per_match={x: dict(known_ok=v[0], known_contradicting=v[1]) for x, v in per.items()} if len(per) <= 8 else
                    dict(matches=len(per), contradicted=sum(1 for v in per.values() if v[1])))


def xtu_survey(prev_dir, xev, hold):
    """Classify every ambiguous candidate of the earlier scan (prev_dir/*.scan.json) by cross-TU evidence.
    Returns {tu: [entries]} and writes OUT15/xtu_survey.json."""
    import glob
    out = {}
    folding = {}
    for fn in sorted(glob.glob(os.path.join(prev_dir, '*.scan.json'))):
        d = json.load(open(fn))
        for e in d.get('ambiguous', []):
            c, a, info = xev.classify(d['tu'], e['symbol'], e['byte_matches'])
            ent = dict(symbol=e['symbol'], size=e.get('size'), byte_matches=len(e['byte_matches']), cross_tu=c,
                       rva=hex(a - 0x400000) if a else None, evidence=info,
                       deliver_later=os.path.basename(d['tu']).lower() in hold and d['tu'].startswith('src/m85/src/'))
            fw = xev.forward(d['tu'], e['symbol'], e['byte_matches'])
            if fw and fw['consistent']:
                ent['forward_only_report'] = fw   # not a claim: caller evidence is required
            out.setdefault(d['tu'], []).append(ent)
            if c == 'folding':
                folding.setdefault(hex(a - 0x400000), []).append((d['tu'], e['symbol']))
    # different symbols that the cross-TU ties alone bind to one address
    tie_folds = {}
    for a, km in xev.ties_by_addr().items():
        names = sorted({gname(k[1]) for k in km} | xev.claim_at.get(a, set()))
        if len(names) > 1 and lc.section_of(SECS, a) == '.text':
            tie_folds[hex(a - 0x400000)] = names[:6]
    cnt = {}
    for v in out.values():
        for e in v:
            cnt[e['cross_tu']] = cnt.get(e['cross_tu'], 0) + 1
    rep = dict(stats=dict(xev.stats, stale_objects=len(xev.stale)), counts=cnt,
               forward_only_consistent=sum(1 for v in out.values() for e in v if 'forward_only_report' in e),
               folding=folding, tie_folding=tie_folds, tus=out)
    json.dump(rep, open(os.path.join(OUT15, 'xtu_survey.json'), 'w', encoding='utf-8'), indent=1)
    return rep


# ---------------------------------------------------------------- B18: forward evidence (the candidate's own relocations)
OUT18 = os.path.join(W, 'analysis', 'level2', 'agents', 'b18_scan')
HOLD18 = 'building.cpp,techno.cpp,dropship.cpp,sidebar.cpp,house.cpp'
MAX_ALT = 6   # alternative byte matches that are also tried with the real check (more: contradiction by the survey only)


def fast_hits(snap, raw, segs):
    """byte_hits without the (slow) claimed-copy scan"""
    n = len(raw)
    anchor = next((i for i, j in segs if j - i >= 4 and i < 64), None)
    cands = snap.index(anchor).get(bytes(raw[anchor:anchor + 4]), []) if anchor is not None else snap.starts
    return [a for a in cands if a - VA0 + n <= len(TB) and all(TB[a - VA0 + i:a - VA0 + j] == raw[i:j] for i, j in segs)]


def forward_survey(xev, snap, objs, hold):
    """For every unclaimed emitted function with relocations: the admissible byte matches (placement rules of
    scan_tu) and, per match, each relocation's verdict by XEvidence.known (claims, symbol map, RTTI vtable, a single
    cross-TU tie).  A candidate survives when exactly one match has no contradicting and at least one confirming
    relocation; the address must be unclaimed and no other name may be bound or tied there (folding guard)."""
    out, by_x = {}, {}
    for tu in sorted(objs):
        o = objs[tu]
        for sym, x in o.symbols.items():
            if x['value'] != 0 or snap.is_claimed(tu, sym, x['storage']):
                continue
            sec = o.function(sym)
            if not sec['relocs'] or not sec['raw']:
                continue
            raw, segs = masked(sec)
            good = [a for a in fast_hits(snap, raw, segs) if end_ok(snap, a, len(raw))[0]]
            if not good:
                continue
            per = {}
            for a in good[:64]:
                r = match_function(o, sym, lc.read(B, SECS, a, len(raw)), a, lambda _: None)
                if r.get('byte_differences') != 0 or r.get('relocation_problems'):
                    continue
                v = [xev.known(tu, b['symbol'], int(b['required_address'], 16)) for b in r['unresolved_bindings']]
                per[a] = (sum(1 for y in v if y is True), sum(1 for y in v if y is False), len(v))
            fit = [a for a, (ok, bad, n) in per.items() if ok and not bad]
            if len(fit) != 1:
                if len(fit) > 1:
                    out.setdefault(tu, []).append(dict(symbol=sym, size=len(raw), state='not_unique', byte_matches=len(good),
                                                       consistent=[hex(a - 0x400000) for a in fit][:8]))
                continue
            a = fit[0]
            ent = dict(symbol=sym, size=len(raw), rva=hex(a - 0x400000), byte_matches=len(good),
                       alternatives=[hex(b - 0x400000) for b in good if b != a], survey=dict(zip(('known_ok', 'known_contradicting', 'relocations'), per[a])),
                       deliver_later=os.path.basename(tu).lower() in hold and tu.startswith('src/m85/src/'))
            oth = xev.others_at(a, sym)
            back = xev.classify(tu, sym, [ent['rva']])
            if a in snap.claimed_rva or oth:
                ent.update(state='folding', other_symbols=oth[:8] or ['<claimed RVA>'])
            elif back[0] == 'contradiction':   # callers/vtable slots tie this very symbol to another address
                ent.update(state='contradiction', backward=back[2])
            else:
                ent['state'] = 'candidate'
                by_x.setdefault(a, []).append((tu, sym))
            out.setdefault(tu, []).append(ent)
    # one address, several different names among the candidates themselves: folding, never claimed
    for a, lst in by_x.items():
        names = {gname(s) for _, s in lst}
        if len(names) > 1:
            for tu, s in lst:
                for e in out[tu]:
                    if e['symbol'] == s and e['state'] == 'candidate':
                        e.update(state='folding', other_symbols=sorted(names - {gname(s)})[:8])
        elif len(lst) > 1:   # the same inline/template symbol emitted by several TUs: deliver it once (first TU not held)
            lst = sorted(lst, key=lambda t: (os.path.basename(t[0]).lower() in hold, t[0]))
            for tu, s in lst[1:]:
                for e in out[tu]:
                    if e['symbol'] == s and e['state'] == 'candidate':
                        e.update(state='duplicate_tu', delivered_by=lst[0][0])
    return out


def forward_verify(tu, ents, hold):
    """Fresh compile (one at a time) and the in-process level2_check: pass 0 (current claims), pass A (candidates at
    their forward address, NO autobind: every binding needs existing evidence), then each alternative byte match in
    rounds: a candidate whose relocations also all verify at another address is not unique and is dropped.  A binding
    whose symbol is another new candidate does not count (no circular evidence)."""
    t0 = time.time()
    name = tuname(tu)
    objdir = os.path.join(OUT, 'obj'); os.makedirs(objdir, exist_ok=True)
    obj_path, info = lc.compile_tu(tu, objdir)
    info['source_sha256'] = __import__('hashlib').sha256(open(os.path.join(P, tu), 'rb').read()).hexdigest()
    res = dict(tu=tu, deliver_later=any(e['deliver_later'] for e in ents), compile=dict(returncode=info['returncode'], command=info['command']),
               survey=ents, verified=[], dropped={})
    if info['returncode'] != 0 or not os.path.exists(obj_path):
        res['error'] = 'compile failed: ' + info.get('output', '')[-800:]
        return ffinish(res, t0)
    o = Obj(open(obj_path, 'rb').read())
    snap = Snapshot()   # claims may have changed while other TUs were verified
    new = []
    for e in ents:
        a = int(e['rva'], 16) + 0x400000
        x = o.symbols.get(e['symbol'])
        if x is None or snap.is_claimed(tu, e['symbol'], x['storage']) or a in snap.claimed_rva or snap.inside_claim(a, a + e['size']):
            res['dropped'][e['rva']] = dict(symbol=e['symbol'], reason='symbol no longer emitted, or claimed meanwhile'); continue
        r = match_function(o, e['symbol'], lc.read(B, SECS, a, len(o.function(e['symbol'])['raw'])), a, lambda _: None)
        if r.get('byte_differences') != 0 or r.get('relocation_problems'):
            res['dropped'][e['rva']] = dict(symbol=e['symbol'], reason='fresh object no longer byte-identical'); continue
        new.append(dict(rva=e['rva'], tu=tu, symbol=e['symbol'], name=demangle(e['symbol'])))
    if not new:
        return ffinish(res, t0)
    newsyms = {c['symbol'] for c in new}

    def judge(rep, placed):
        """(rva, symbol) -> (ok, reason) for the placed candidates"""
        out = {}
        bad = conflict_bad(rep, {c['rva'] for c in placed})
        for c in placed:
            f = next((f for f in rep['functions'] if f['rva'] == c['rva'] and f.get('symbol') == c['symbol']), None)
            if f is None:
                out[(c['rva'], c['symbol'])] = (False, 'not in the check report'); continue
            circ = [b['symbol'][:60] for b in f.get('bindings', []) if b['symbol'] in newsyms and b['symbol'] != c['symbol']]
            unv = [(b['symbol'][:60], b['address'], b['evidence'][:80]) for b in f.get('bindings', []) if not b['verified']]
            if f['status'] != 'matched':
                out[(c['rva'], c['symbol'])] = (False, dict(status=f['status'], byte_differences=f.get('byte_differences'), unverified=unv[:6]))
            elif circ:
                out[(c['rva'], c['symbol'])] = (False, dict(reason='evidence through another new candidate', symbols=circ[:4]))
            elif c['rva'] in bad:
                out[(c['rva'], c['symbol'])] = (False, 'binds a symbol in a symbol conflict')
            elif not f.get('bindings'):
                out[(c['rva'], c['symbol'])] = (False, 'no relocation: not forward evidence')
            else:
                out[(c['rva'], c['symbol'])] = (True, '%d binding(s) verified: %s' % (len(f['bindings']), sorted({b['evidence'][:40] for b in f['bindings']})[:6]))
        return out

    base = scratch_check(tu, obj_path, info, 'pass0')
    base_ok = {f['rva'] for f in base['functions'] if f['status'] == 'matched'}
    res['pass0'] = '%d/%d existing claims matched' % (len(base_ok), len(base['functions']))
    keep = list(new)
    for rnd in range(4):
        ra = scratch_check(tu, obj_path, info, 'passA%d' % rnd, keep)
        lost = [f['rva'] for f in ra['functions'] if f['rva'] in base_ok and f['status'] != 'matched']
        if lost:
            res['lost_existing'] = lost; res['verification'] = 'existing claims stop matching with the candidates; nothing delivered'
            keep = []; break
        j = judge(ra, keep)
        for (r, sy), (ok, why) in j.items():
            if not ok:
                res['dropped'][r] = dict(symbol=sy, reason=why)
        k2 = [c for c in keep if j[(c['rva'], c['symbol'])][0]]
        if len(k2) == len(keep):
            res['passA'] = {c['rva']: j[(c['rva'], c['symbol'])][1] for c in keep}; break
        keep = k2
        if not keep:
            break
    # uniqueness with the real check: each alternative byte match, one candidate per round position
    alts = {c['rva']: next(e['alternatives'] for e in ents if e['rva'] == c['rva']) for c in keep}
    res['alternatives_checked'] = {}
    for k in range(MAX_ALT):
        placed = [dict(c, rva=alts[c['rva']][k]) for c in keep if len(alts[c['rva']]) > k]
        if not placed:
            break
        ra = scratch_check(tu, obj_path, info, 'alt%d' % k, placed)
        for (p, sy), (ok, why) in judge(ra, placed).items():
            orig = next(c for c in keep if c['symbol'] == sy)
            res['alternatives_checked'].setdefault(orig['rva'], []).append(dict(rva=p, all_verified=ok, detail=why if not ok else ''))
            if ok:
                res['dropped'][orig['rva']] = dict(symbol=orig['symbol'], reason='relocations also all verify at %s: not unique' % p)
    keep = [c for c in keep if c['rva'] not in res['dropped']]
    for c in keep:
        if len(alts[c['rva']]) > MAX_ALT:
            res.setdefault('notes', []).append('%s: %d alternatives beyond %d excluded by the survey contradiction only' % (c['rva'], len(alts[c['rva']]) - MAX_ALT, MAX_ALT))
    if keep:   # final confirmation with exactly the delivered set
        rf = scratch_check(tu, obj_path, info, 'final', keep)
        lost = [f['rva'] for f in rf['functions'] if f['rva'] in base_ok and f['status'] != 'matched']
        j = judge(rf, keep)
        if lost or not all(j[(c['rva'], c['symbol'])][0] for c in keep):
            res['verification'] = 'final check failed: lost %s, failing %s' % (lost, [r for r in j if not j[r][0]]); keep = []
        else:
            res['verification'] = 'final: %d/%d candidates matched with existing evidence only, unique, %d existing claims unchanged' % (len(keep), len(new), len(base_ok))
    sizes = {e['rva']: e['size'] for e in ents}
    res['verified'] = [dict(c, size=sizes[c['rva']]) for c in keep]
    if keep and not res['deliver_later']:
        claims = dict(tu=tu, source='level2_unclaimed_scan.py --forward (B18): already emitted, unclaimed, byte-identical; unique byte match once '
                      'the own relocations are checked; all relocations verified with existing evidence; scratch ci-style check passed',
                      deliver_later=False,
                      functions=[dict(rva=c['rva'], symbol=c['symbol'], name=c['name'], status='matched', size=sizes[c['rva']],
                                      resolved_by='forward: own relocations (%s)' % res['passA'].get(c['rva'], '')[:160]) for c in keep],
                      symbols={})
        json.dump(claims, open(os.path.join(OUT, name + '.claims.json'), 'w', encoding='utf-8'), indent=1)
    return ffinish(res, t0)


def ffinish(res, t0):
    res['seconds'] = round(time.time() - t0, 1)
    json.dump(res, open(os.path.join(OUT, tuname(res['tu']) + '.scan.json'), 'w', encoding='utf-8'), indent=1)
    with open(os.path.join(OUT, 'summary.jsonl'), 'a', encoding='utf-8') as fp:
        fp.write(json.dumps(dict(tu=res['tu'], candidates=len(res['survey']), verified=len(res['verified']), deliver_later=res['deliver_later'],
                                 seconds=res['seconds'], error=res.get('error', '')[:200])) + '\n')
    print('%-45s cand %2d verified %2d %s%.0fs' % (res['tu'][-45:], len(res['survey']), len(res['verified']), 'HOLD ' if res['deliver_later'] else '', res['seconds']), flush=True)
    for v in res['verified']:
        print('    %s %5d  %s' % (v['rva'], v['size'], v['symbol'][:90]), flush=True)
    for r, d in res['dropped'].items():
        print('    dropped %s %s: %s' % (r, d.get('symbol', '')[:60], str(d.get('reason'))[:160]), flush=True)
    return res


def forward_main(a, hold):
    global OUT
    OUT = OUT18
    os.makedirs(OUT, exist_ok=True)
    snap = Snapshot()
    xev = XEvidence(a.report or newest_full_report(), snap)
    objs = dict(xev.objs)
    stale = [t for t, _ in xev.stale]
    want = [t.strip() for t in a.tus if t.strip()]
    if want:
        objs = {t: o for t, o in objs.items() if t in want}
        stale = [t for t in stale if t in want]
    # TUs whose W/build/level2 object changed after the report: compiled once here (one at a time) for the survey
    os.makedirs(os.path.join(OUT, 'obj'), exist_ok=True)
    for tu in stale:
        p, info = lc.compile_tu(tu, os.path.join(OUT, 'obj'))
        print('survey compile %s: rc %s' % (tu, info['returncode']), flush=True)
        if info['returncode'] == 0 and os.path.exists(p):
            objs[tu] = Obj(open(p, 'rb').read())
    t0 = time.time()
    sv = forward_survey(xev, snap, objs, hold)
    cnt = {}
    for v in sv.values():
        for e in v:
            cnt[e['state']] = cnt.get(e['state'], 0) + 1
    json.dump(dict(stats=dict(xev.stats, stale_objects=stale, surveyed_tus=len(objs), seconds=round(time.time() - t0, 1)), counts=cnt, tus=sv),
              open(os.path.join(OUT, 'forward_survey.json'), 'w', encoding='utf-8'), indent=1)
    print('forward survey:', json.dumps(cnt), flush=True)
    if a.survey_only:
        return
    for tu in sorted(sv):
        ents = [e for e in sv[tu] if e['state'] == 'candidate']
        if ents:
            try:
                forward_verify(tu, ents, hold)
            except Exception as e:
                import traceback
                ffinish(dict(tu=tu, deliver_later=False, survey=ents, verified=[], dropped={}, error='%s: %s' % (type(e).__name__, traceback.format_exc()[-1500:])), time.time())


def gap_order(path):
    txt = open(path).read() if path else subprocess.run([sys.executable, '-I', os.path.join(W, 'tools', 'level2_gaps.py'), '400'],
                                                         capture_output=True, text=True).stdout
    score = {}
    for line in txt.split('--- largest')[0].splitlines():
        m = re.match(r'\s*(\d+)\s+(.+)$', line)
        if m:
            for t in m.group(2).split(' | '):
                score[t.strip()] = score.get(t.strip(), 0) + int(m.group(1))
    return score


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('tus', nargs='*'); ap.add_argument('--all', action='store_true'); ap.add_argument('--gaps')
    ap.add_argument('--limit', type=int, default=0); ap.add_argument('--start', type=int, default=0)
    ap.add_argument('--hold', default=None)
    ap.add_argument('--xtu', action='store_true', help='B15 cross-TU caller evidence mode (outputs under b15_scan)')
    ap.add_argument('--report', help='full check report for --xtu (default: newest full report)')
    ap.add_argument('--forward', action='store_true', help='B18 forward-evidence mode (outputs under b18_scan)')
    ap.add_argument('--survey-only', action='store_true', help='--forward: write forward_survey.json only, no compile/check')
    ap.add_argument('--prev', default=os.path.join(W, 'analysis', 'level2', 'agents', 'b11_scan'),
                    help='earlier scan whose ambiguous candidates --xtu surveys')
    a = ap.parse_args()
    hold = {x.strip().lower() for x in (a.hold or (HOLD15 if a.xtu else HOLD_DEFAULT)).split(',') if x.strip()}
    if a.forward:
        return forward_main(a, {x.strip().lower() for x in (a.hold or HOLD18).split(',') if x.strip()})
    tus = [t.strip() for t in a.tus if t.strip()]
    xev = None
    if a.xtu:
        global OUT
        OUT = OUT15
        os.makedirs(OUT, exist_ok=True)
        xev = XEvidence(a.report or newest_full_report(), Snapshot())
        if not tus and not a.all:   # survey the ambiguous set, then verify only the TUs that gained evidence
            rep = xtu_survey(a.prev, xev, hold)
            print('cross-TU survey:', json.dumps(rep['counts']), 'forward-only consistent (report only):', rep['forward_only_consistent'], flush=True)
            tus = sorted(t for t, v in rep['tus'].items() if any(e['cross_tu'] == 'accept' for e in v))
    os.makedirs(OUT, exist_ok=True)
    if a.all:
        claims = json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))
        cnt = {}
        for f in claims:
            cnt[f['tu']] = cnt.get(f['tu'], 0) + 1
        score = gap_order(a.gaps)
        tus = sorted(cnt, key=lambda t: (-score.get(t, 0), -cnt[t], t))
        tus = tus[a.start:]
        if a.limit:
            tus = tus[:a.limit]
    for tu in tus:
        try:
            scan_tu(tu, hold, xev)
        except Exception as e:   # keep going; record the failure
            import traceback
            finish(dict(tu=tu, deliver_later=False, candidates=[], rejected=[], ambiguous=[], error='%s: %s' % (type(e).__name__, traceback.format_exc()[-1500:])), time.time())


if __name__ == '__main__':
    main()
