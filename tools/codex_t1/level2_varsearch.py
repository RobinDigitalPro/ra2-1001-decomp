"""Level-2 variant search: compile many source variants of one TU and score them against GAME.EXE 1.001.

An agent describes CHOICE POINTS in a JSON spec. Each choice point has a few alternative spellings, given as exact
[old, new] replacements. The tool builds combinations, compiles each with VC6, and scores the TARGET functions.
It requires the CONTROL functions to stay byte-identical. Results are cached by source hash, so a search can be
stopped and resumed, or extended with new choice points, without recompiling known variants.

usage: python -I level2_varsearch.py <spec.json> [--mode grid|greedy|random] [--max N] [--workers K] [--kit ROOT]

spec.json:
{
  "base": "D:/.../src/m85/src/wonline.cpp",     // the source to vary; relative paths resolve against the spec file
  "preset": "m85",                              // m85 (-I m85/src -I m85/include -DWIN32 -W0) or ra2 (-I src/ra2)
  "targets":  [["?Match_Start_Game@@YI_NXZ", "0x3497e0"]],      // symbol (exact if it starts with '?') or substring
  "controls": [["Draw_Player_List", "0x334590"]],                 // must stay byte-identical, else the variant is rejected
  "choices": [
    {"name": "loop", "options": [
        {"label": "while", "edits": []},                          // option 0 is normally the current text
        {"label": "for",   "edits": [["while (attempt++ < 30) {", "for (; attempt++ < 30; ) {"]]}]},
    // an edit may be [old, new, anchor]: replace the first old after the unique anchor text (e.g. the function header line)
    ...
  ]
}
Opt in with "generators": ["overloads", "split_live", "branch_split_merge", "loop_family"].
They use target symbol names to locate function definitions. To work inside an inlined helper
or select the first differing expression from a compile listing, use an explicit function and
optionally its 1-based line in the full base TU, e.g.
  "generators": [{"name":"overloads","function":"BuildingClass::Draw_Extras","line":123}]
Omit line to enumerate supported sites in the named functions. The generator does not infer
a C++ expression from an instruction offset. "headers" accepts extra header files or directories,
"include_dirs" adds compiler and discovery roots, and "compiler" overrides the VC6 executable.
Paths resolve relative to the spec. Include closure follows literal includes.
--generate-only prints JSON choices, their evidence, and skipped-site diagnostics without a build.
Keep level2_generators.py beside this script. Options are exact [old,new] source hypotheses.
The search compares target and control objects and reports direct-call relocation names.
Cache identity includes target and control mappings, flags and paths. Set a new "cache_epoch"
after overwriting kit headers, compiler, or reference binaries in place.
Modes:
  grid    every combination, in order, up to --max (default 200)
  greedy  coordinate descent from the all-zero combination: per choice try every option, keep the best, repeat until stable
  random  --max random combinations
Score per variant: the sum over targets of byte_differences + 4*|size - original_size|; 0 means all targets match.
Output, next to the spec: <spec>.results.jsonl (one line per compiled variant) and <spec>.best.cpp (the best source).
"""
from pathlib import Path
import argparse, concurrent.futures as cf, hashlib, itertools, json, os, random, subprocess, sys, tempfile, threading

ap = argparse.ArgumentParser()
ap.add_argument('spec'); ap.add_argument('--mode', default='greedy', choices=['grid', 'greedy', 'random'])
ap.add_argument('--max', type=int, default=200); ap.add_argument('--workers', type=int, default=3); ap.add_argument('--kit')
ap.add_argument('--seed', type=int, default=1)
ap.add_argument('--score', default='bytes', choices=['bytes', 'hunks'],
                help='bytes: byte differences + 4*size delta; hunks: relocation-masked instruction diff groups (better when size shifts early)')
ap.add_argument('--generate-only', action='store_true', help='print manual and generated choices as JSON, without compiling')
a = ap.parse_args()
if min(a.workers, a.max) < 1:
    ap.error('--workers and --max must be positive')
sys.dont_write_bytecode = True  # kit is read-only
sys.path.insert(0, str(Path(__file__).resolve().parent))  # also works under python -I
from level2_generators import generate

if a.kit:   # the Codex station kit layout (vc6/, m85/, tools/, orig/)
    K = os.path.abspath(a.kit); VC6 = os.path.join(K, 'vc6'); M85 = os.path.join(K, 'm85'); RA2 = os.path.join(K, 'ra2')
    sys.path.insert(0, os.path.join(K, 'tools')); sys.path.insert(0, K)
else:       # the main workstation layout (W and P)
    VC6 = r'D:\<work-root>\RedAlert2Temp\tools\portable\vc6'
    M85 = r'D:\<project-folder>\Coding\RedAlert2\src\m85'; RA2 = r'D:\<project-folder>\Coding\RedAlert2\src\ra2'
    sys.path.insert(0, r'D:\<work-root>\RedAlert2Temp\analysis\level2'); sys.path.insert(0, r'D:\<work-root>\RedAlert2Temp\tools\portable\capstone-5.0.6')

specfile = os.path.abspath(a.spec); spec = json.load(open(specfile, encoding='utf-8'))
sdir = os.path.dirname(specfile)
base_path = spec['base'] if os.path.isabs(spec['base']) else os.path.join(sdir, spec['base'])
base = open(base_path, 'rb').read().decode('latin-1')
crlf = '\r\n' in base
base = base.replace('\r\n', '\n')
include_dirs = [str((Path(sdir) / d).resolve()) for d in spec.get('include_dirs', [])]
kit_dirs = [os.path.join(M85, 'src'), os.path.join(M85, 'include')] if spec.get('preset', 'm85') == 'm85' else [RA2]
try:
    generated, diagnostics = generate(base, base_path, spec, sdir, kit_dirs)
except (OSError, ValueError, KeyError, TypeError) as exc:
    ap.error(str(exc))
choices = list(spec.get('choices', [])) + generated
if a.generate_only:
    print(json.dumps(dict(choices=choices, diagnostics=diagnostics), indent=2))
    sys.exit(0)
for message in diagnostics:
    print(message, file=sys.stderr)
import l2match
from coffmatch import Obj

FLAGS = ['-O2', '-Ob2', '-Gr', '-GR', '-DNDEBUG', '-Gy']
FLAGS += ['-I' + d for d in include_dirs] + ['-I' + os.path.dirname(base_path)]
if spec.get('preset', 'm85') == 'm85':
    FLAGS += ['-DWIN32', '-W0', '-I' + os.path.join(M85, 'src'), '-I' + os.path.join(M85, 'include')]
else:
    FLAGS += ['-I' + RA2]
compiler = str((Path(sdir) / spec.get('compiler', os.path.join(VC6, 'VC98', 'BIN', 'CL.EXE'))).resolve())
ENV = dict(os.environ)
ENV['PATH'] = os.pathsep.join([os.path.join(VC6, 'VC98', 'BIN'), os.path.join(VC6, 'COMMON', 'MSDEV98', 'BIN'), ENV.get('PATH', '')])
ENV['INCLUDE'] = os.path.join(VC6, 'VC98', 'INCLUDE') + ';' + os.path.join(VC6, 'VC98', 'ATL', 'INCLUDE')
ENV['LIB'] = os.path.join(VC6, 'VC98', 'LIB')
work = os.path.join(sdir, os.path.splitext(os.path.basename(specfile))[0] + '_work'); os.makedirs(work, exist_ok=True)
resfile = os.path.splitext(specfile)[0] + '.results.jsonl'
ENV['TMP'] = ENV['TEMP'] = work
context = [a.score, FLAGS, compiler, VC6, M85, RA2, spec.get('cache_epoch'), spec['targets'], spec.get('controls', [])]
SCORE_VERSION = '2026-11-gen3:' + hashlib.sha256(json.dumps(context).encode()).hexdigest()[:24]
cache = {}; errors = []
if os.path.exists(resfile):
    for line in open(resfile, encoding='utf-8'):
        r = json.loads(line)
        if r.get('hash') and r.get('sv') == SCORE_VERSION:   # results scored by an older scorer are recompiled
            cache[r['hash']] = r
lock = threading.Lock()
hash_locks = {}


def build_text(combo):
    t = base
    for ci, oi in enumerate(combo):
        for e in choices[ci]['options'][oi]['edits']:
            old, new = e[0], e[1]
            if len(e) > 2:      # [old, new, anchor]: the first old after the unique anchor (e.g. the function header)
                if t.count(e[2]) != 1:
                    return None, 'choice %s option %s: anchor occurs %d times' % (choices[ci]['name'], oi, t.count(e[2]))
                i = t.find(old, t.find(e[2]))
                if i < 0:
                    return None, 'choice %s option %s: old text not found after anchor' % (choices[ci]['name'], oi)
                t = t[:i] + new + t[i + len(old):]
                continue
            n = t.count(old)
            if n != 1:
                return None, 'choice %s option %s: old text occurs %d times' % (choices[ci]['name'], oi, n)
            t = t.replace(old, new)
    return t, None


def hunks(o, name, rva):
    """Relocation-masked instruction diff: number of non-equal opcode groups (difflib) plus 2 per call-count difference.
    Normalisation follows level2_maskhunks.py: nop/int3 padding ignored, branch/call targets dropped, relocated operands
    (ours) and absolute addresses >= 0x400000 (original) masked. The original window is our size + 32 bytes, because
    function_map/claims can hold a bogus next start inside or past the body (dialog procs with jump tables, page-aligned
    entries); ref_len() is used only when it is plausible (within 0.75x..1.5x of our size). Trailing original code past
    our end is not counted as a hunk."""
    import difflib, re, capstone
    f = o.function(name); code = f['raw']; rel = set()
    for r in f['relocs']:
        rel.update(range(r[0], r[0] + 4))
    n = ref_len(rva, len(code))
    if not (0.75 * len(code) <= n <= 1.5 * len(code)):
        n = len(code) + 32
    orig = l2match.orig(rva, n)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    def dis(c, mask):
        out = []
        for i in md.disasm(c, 0):      # capstone stops at the first undecodable byte (e.g. jump-table data)
            s = '%s %s' % (i.mnemonic, i.op_str)
            if i.mnemonic == 'nop' or s.startswith('int3'):
                continue
            if i.mnemonic.startswith('j') or i.mnemonic == 'call':
                out.append(i.mnemonic); continue
            m = re.sub(r'\[(0x[0-9a-f]+)\]', '[A]', s)
            m = re.sub(r', 0x[0-9a-f]{5,}$', ', A', m)
            m = re.sub(r'^(push|mov e..,) 0x[0-9a-f]{5,}$', r'\1 A', m)
            if mask and any(x in rel for x in range(i.address, i.address + i.size)):
                m = re.sub(r'\b0x[0-9a-f]+\b|\b\d+\b', 'A', m)
            out.append(m)
        return out
    a = dis(code, True); b = dis(orig, False)[:len(a) + 40]
    sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
    ops = [op for op in sm.get_opcodes() if op[0] != 'equal']
    if ops and ops[-1][1] == len(a):     # a trailing hunk that is just the original continuing past our end
        ops = ops[:-1]
    calls = abs(sum(1 for x in a if x.startswith('call')) - sum(1 for x in b if x.startswith('call')))
    return len(ops) + 2 * calls


_starts = None
def ref_len(rva, fallback):
    """Length of the original function body: up to the next known function start (function map + claims), padding trimmed."""
    global _starts
    if _starts is None:
        import bisect
        s = set()
        fm = os.path.join(K, 'meta', 'function_map.json') if a.kit else r'D:\<work-root>\RedAlert2Temp\analysis\level2\function_map.json'
        fc = os.path.join(K, 'meta', 'level2_functions.json') if a.kit else r'D:\<project-folder>\Coding\RedAlert2\metadata\level2_functions.json'
        try:
            s |= {int(x['rva'], 16) for x in json.load(open(fm))['map']}
        except Exception:
            pass
        try:
            s |= {int(x['rva'], 16) for x in json.load(open(fc, encoding='utf-8'))}
        except Exception:
            pass
        _starts = sorted(s)
    import bisect
    i = bisect.bisect_right(_starts, rva)
    if i >= len(_starts):
        return fallback + 64
    n = _starts[i] - rva
    raw = l2match.orig(rva, n)
    while n > 0 and raw[n - 1] in (0x90, 0xcc):
        n -= 1
    return n if n > 16 else fallback + 64


def score_obj(obj, pairs):
    o = Obj(open(obj, 'rb').read()); out = []
    for needle, rva in pairs:
        names = [k for k in o.symbols if (k == needle if needle.startswith('?') else needle in k)]
        if len(names) != 1:
            out.append(dict(sym=needle, status='symbol_not_unique' if names else 'symbol_missing', bytes=10 ** 6)); continue
        r = l2match.run(obj, names[0], int(rva, 16), {})
        diff = (r.get('byte_differences') or 0) + 4 * abs((r.get('size') or 0) - (r.get('original_size') or 0))
        if r.get('status') in ('matched', 'bytes_match_bindings_open'):
            diff = 0
        elif a.score == 'hunks':
            diff = 1 + hunks(o, names[0], int(rva, 16))   # >= 1 for any mismatch, so 0 still means byte-identical
        status = r.get('status')
        if status not in ('matched', 'bytes_match_bindings_open'):
            diff = max(1, diff)
        section = o.function(names[0])
        calls = [o.by_index[symbol]['name'] for offset, symbol, kind in section['relocs']
                 if kind == 0x14 and offset > 0 and section['raw'][offset-1:offset] == b'\xe8']
        out.append(dict(sym=names[0], status=status, bytes=diff, size=r.get('size'),
                        orig=r.get('original_size'), call_relocations=calls))
    return out


def evaluate(combo):
    text, err = build_text(combo)
    labels = [choices[i]['options'][o]['label'] for i, o in enumerate(combo)]
    if err:
        r = dict(combo=list(combo), labels=labels, error=err, score=10 ** 9, hash=None)
        with lock:
            errors.append(err)
            open(resfile, 'a', encoding='utf-8').write(json.dumps(r) + '\n')
        return r
    h = hashlib.sha256(text.encode('latin-1')).hexdigest()[:20]
    with lock:
        guard = hash_locks.setdefault(h, threading.Lock())
    with guard:
        return evaluate_source(combo, labels, text, h)


def evaluate_source(combo, labels, text, h):
    with lock:
        if h in cache:
            r = dict(cache[h]); r['combo'] = list(combo); r['labels'] = labels; return r
    src = os.path.join(work, 'v_%s.cpp' % h); obj = src[:-4] + '.obj'
    open(src, 'wb').write((text.replace('\n', '\r\n') if crlf else text).encode('latin-1'))
    try:
        p = subprocess.run([compiler, '-nologo', '-c'] + FLAGS + ['-Fo' + obj, src],
                           env=ENV, cwd=work, capture_output=True, text=True, errors='replace', timeout=600)
        if p.returncode or not os.path.exists(obj):
            r = dict(combo=list(combo), labels=labels, hash=h, error='compile failed: ' + (p.stdout + p.stderr)[-400:], score=10 ** 9)
        else:
            t = score_obj(obj, spec['targets']); c = score_obj(obj, spec.get('controls', []))
            ok = all(x['bytes'] == 0 for x in c)
            r = dict(combo=list(combo), labels=labels, hash=h, sv=SCORE_VERSION, targets=t, controls_ok=ok,
                     score=sum(x['bytes'] for x in t) if ok else 10 ** 8 + sum(x['bytes'] for x in t))
    except subprocess.TimeoutExpired:
        r = dict(combo=list(combo), labels=labels, hash=h, error='compiler timed out after 600 seconds', score=10 ** 9)
    finally:
        for path in (obj, src):
            if os.path.exists(path):
                os.remove(path)
    with lock:
        cache[h] = r
        open(resfile, 'a', encoding='utf-8').write(json.dumps(r) + '\n')
    return r


def run_batch(combos):
    with cf.ThreadPoolExecutor(a.workers) as ex:
        return list(ex.map(evaluate, combos))


best = None
def note(rs):
    global best
    for r in rs:
        if best is None or r['score'] < best['score']:
            best = r
            print('best %s  %s' % (r['score'], ' | '.join('%s=%s' % (choices[i]['name'], l) for i, l in enumerate(r['labels']))), flush=True)


dims = [len(c['options']) for c in choices]
if a.mode == 'grid':
    note(run_batch(list(itertools.islice(itertools.product(*[range(d) for d in dims]), a.max))))
elif a.mode == 'random':
    rnd = random.Random(a.seed)
    note(run_batch([tuple(rnd.randrange(d) for d in dims) for _ in range(a.max)]))
else:
    cur = tuple(0 for _ in dims); note(run_batch([cur])); budget = a.max - 1; changed = True
    while changed and budget > 0:
        changed = False
        for ci, d in enumerate(dims):
            cands = [cur[:ci] + (oi,) + cur[ci + 1:] for oi in range(d) if oi != cur[ci]][:budget]
            if not cands:
                continue
            budget -= len(cands); rs = run_batch(cands); note(rs)
            top = min(rs, key=lambda r: r['score'])
            if top['score'] < best['score'] or (top is best and tuple(top['combo']) != cur):
                pass
            if tuple(best['combo']) != cur and best['score'] < 10 ** 8:
                cur = tuple(best['combo']); changed = True
if best and best.get('hash'):
    text, _ = build_text(best['combo'])
    open(os.path.splitext(specfile)[0] + '.best.cpp', 'wb').write((text.replace('\n', '\r\n') if crlf else text).encode('latin-1'))
print(json.dumps({k: best[k] for k in ('score', 'labels', 'targets', 'controls_ok') if k in best}, indent=1))
if errors:
    print('INVALID variants (edit text not found exactly once): %d, e.g. %s' % (len(errors), sorted(set(errors))[:3]))
print('results:', resfile)
