"""Forcing audit: find constructs in the landed level-2 source that may exist only to steer VC6 code generation.

usage: python -I level2_forcing_audit.py [--workers N] [--tu src/m85/src/x.cpp ...]

User decision 2026-11-23 (stocktake, step 1): audit all landed code for steering constructs. Claims stay;
flagged sites go on a REMATCH list until a natural form is found. Nothing in P is changed by this script.

Two kinds of evidence per claimed TU (every TU in P/metadata/level2_functions.json):
  1. Compiler warnings: CL.EXE -Zs -W4 (syntax check only, no object, same defines and include paths as level2_check):
     C4101 unreferenced local, C4189 local initialised but not referenced, C4702 unreachable code,
     C4127 constant condition (only when the line holds if/while with 0/false).
  2. Source patterns per line: if(0)/while(0), member-pointer locals, Ghidra-style names (uVar1, local_10, ...),
     numbered temporaries (tmp1, t2), volatile locals, (void)x; statements, inline asm in C++,
     bare blocks, empty if/else/loop blocks, the same statement directly before and after an `else`,
     and INFERRED helpers that are used at most once in their TU.
Each finding carries file, line, the enclosing function (heuristic) and the text.
Output: W/analysis/level2/forcing_audit/audit_<utc>.json and P/docs/level2/FORCING_AUDIT_<utc>.md (new files only).
Inspired by the forcing audit described in gibbo101/ra2-decomp's PLAN (docs only; no code taken).
"""
import argparse, collections, concurrent.futures as cf, datetime, json, os, re, subprocess
P = r'D:\<project-folder>\Coding\RedAlert2'; W = r'D:\<work-root>\RedAlert2Temp'
VC6 = os.path.join(W, 'tools', 'portable', 'vc6')
ap = argparse.ArgumentParser(); ap.add_argument('--workers', type=int, default=4); ap.add_argument('--tu', nargs='*'); a = ap.parse_args()

F = json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))
claims = collections.Counter(f['tu'] for f in F)
tus = sorted(t for t in claims if not t.lower().endswith('.asm')) if not a.tu else a.tu

env = dict(os.environ)
env['PATH'] = os.pathsep.join([os.path.join(VC6, 'VC98', 'BIN'), os.path.join(VC6, 'COMMON', 'MSDEV98', 'BIN'), env['PATH']])
env['INCLUDE'] = os.path.join(VC6, 'VC98', 'INCLUDE') + os.pathsep + os.path.join(VC6, 'VC98', 'ATL', 'INCLUDE')
WARN = re.compile(r'^(.*?)\((\d+)\)\s*:\s*warning (C4101|C4189|C4702|C4127):\s*(.*)$')


def warnings(tu):
    if tu.startswith('src/m85/'):
        inc = ['-DWIN32', '-I' + os.path.join(P, 'src', 'm85', 'src'), '-I' + os.path.join(P, 'src', 'm85', 'include')]
    else:
        inc = ['-I' + os.path.join(P, 'src', 'ra2')]
    cmd = [os.path.join(VC6, 'VC98', 'BIN', 'CL.EXE'), '-nologo', '-Zs', '-W4', '-O2', '-Ob2', '-Gr', '-GR', '-DNDEBUG', '-Gy'] + inc + [os.path.join(P, tu)]
    r = subprocess.run(cmd, env=env, capture_output=True, text=True, timeout=300)
    out = []
    for l in (r.stdout + r.stderr).splitlines():
        m = WARN.match(l.strip())
        if not m:
            continue
        path = os.path.normcase(os.path.abspath(m.group(1)))
        if os.path.normcase(VC6) in path:
            continue
        out.append((path, int(m.group(2)), m.group(3), m.group(4)))
    return r.returncode, out


PAT = [
    ('const-condition', re.compile(r'\b(if|while)\s*\(\s*(0|false|FALSE)\s*\)')),
    ('member-pointer-local', re.compile(r'\(\s*\w+\s*::\s*\*\s*\w+\s*\)\s*\(.*=\s*&\s*\w+\s*::')),
    ('ghidra-name', re.compile(r'\b(uVar|iVar|bVar|cVar|sVar|fVar|dVar|pvVar|puVar|piVar|ppVar|pcVar|local_|extraout_|unaff_|in_EAX|in_ECX|in_EDX)\w*')),
    ('numbered-temp', re.compile(r'\b(tmp|temp|_t|t|v)\d+\b')),
    ('volatile-local', re.compile(r'^\s+volatile\b')),
    ('void-cast-statement', re.compile(r'^\s*\(\s*void\s*\)\s*\w+\s*;')),
    ('inline-asm', re.compile(r'\b(__asm|_asm)\b')),
    ('empty-control-block', re.compile(r'\b(if|else|while|for)\b[^;{]*\{\s*\}')),
]
FUNC = re.compile(r'^[A-Za-z_][\w\s\*&:<>,~]*?\b([\w:~]+)\s*\([^;]*\)\s*(const)?\s*(//.*)?$')


def strip_comment(l):
    return re.sub(r'//.*$', '', l).rstrip()


def scan(path):
    try:
        L = open(path, encoding='latin-1').read().split('\n')
    except OSError:
        return [], []
    found, func, fnames = [], ['?'] * len(L), '?'
    for i, l in enumerate(L):
        if FUNC.match(l) and i + 1 < len(L) and L[i + 1].strip().startswith('{'):
            fnames = FUNC.match(l).group(1)
        func[i] = fnames
    code = [strip_comment(l) for l in L]
    for i, c in enumerate(code):
        for name, rx in PAT:
            if rx.search(c):
                found.append((i + 1, name, func[i], L[i].strip()[:160]))
        s = c.strip()
        if s == '{' and i > 0:
            j = i - 1
            while j >= 0 and not code[j].strip():
                j -= 1
            p = code[j].strip() if j >= 0 else ''
            if p.endswith((';', '{', '}')) and not re.match(r'^(else|do|try)\b', p):
                found.append((i + 1, 'bare-block', func[i], L[i].strip()))
        if re.match(r'^\}?\s*else\s*\{?$', s):
            j = i - 1
            while j >= 0 and code[j].strip() in ('', '}'):
                j -= 1
            k = i + 1
            while k < len(code) and code[k].strip() in ('', '{'):
                k += 1
            if j >= 0 and k < len(code) and code[j].strip().endswith(';') and code[j].strip() == code[k].strip() and not code[j].strip().startswith(('break', 'return', 'continue')):
                found.append((k + 1, 'same-statement-both-arms', func[k], code[k].strip()[:160]))
    inferred = []
    text = '\n'.join(code)
    for i, l in enumerate(L):
        if 'INFERRED' in l:
            m = FUNC.match(l.split('//')[0].rstrip()) or re.search(r'\b(\w+)\s*\(', l.split('//')[0])
            if m:
                name = m.group(1).split('::')[-1]
                uses = len(re.findall(r'\b%s\s*\(' % re.escape(name), text)) - 1
                if uses <= 1:
                    inferred.append((i + 1, 'inferred-helper-single-use', name, l.strip()[:160]))
    return found, inferred


def audit(tu):
    rc, ws = warnings(tu)
    path = os.path.join(P, tu.replace('/', os.sep))
    f, inf = scan(path)
    return tu, rc, ws, f + inf


now = datetime.datetime.utcnow().strftime('%Y-%m-%dT%H%MZ')
res, hdr_warn = {}, collections.Counter()
with cf.ThreadPoolExecutor(a.workers) as ex:
    for tu, rc, ws, fs in ex.map(audit, tus):
        own = os.path.normcase(os.path.join(P, tu.replace('/', os.sep)))
        res[tu] = {'claims': claims[tu], 'cl_rc': rc,
                   'warnings': [dict(line=l, code=c, text=t) for p, l, c, t in ws if p == own],
                   'patterns': [dict(line=l, kind=k, function=fn, text=t) for l, k, fn, t in fs]}
        for p, l, c, t in ws:
            if p != own:
                try:
                    rp = os.path.relpath(p, P)
                except ValueError:   # a header on another drive (for example a system SDK header)
                    rp = p
                hdr_warn[(rp, l, c, t)] += 1
out = os.path.join(W, 'analysis', 'level2', 'forcing_audit'); os.makedirs(out, exist_ok=True)
J = os.path.join(out, 'audit_%s.json' % now)
json.dump({'utc': now, 'tus': res, 'header_warnings': [dict(file=f, line=l, code=c, text=t, tus=n) for (f, l, c, t), n in hdr_warn.most_common()]},
          open(J, 'w', encoding='utf-8'), indent=1)
kinds = collections.Counter(); wk = collections.Counter()
for r in res.values():
    kinds.update(p['kind'] for p in r['patterns']); wk.update(w['code'] for w in r['warnings'])
M = ['# Forcing audit %s' % now, '', 'Generated by W/tools/level2_forcing_audit.py; full data in %s.' % J, '',
     '%d TUs scanned; compile failures (cl rc != 0): %d.' % (len(res), sum(1 for r in res.values() if r['cl_rc'])), '',
     '## Totals', '', '| Kind | Sites |', '|---|---:|'] + ['| %s | %d |' % kv for kv in (wk + kinds).most_common()] + \
    ['', '| Header warnings (distinct sites) | %d |' % len(hdr_warn), '', '## Per TU (sites)', '']
for tu, r in sorted(res.items(), key=lambda x: -(len(x[1]['warnings']) + len(x[1]['patterns']))):
    n = len(r['warnings']) + len(r['patterns'])
    if n:
        M.append('- %s: %d (%s)' % (tu, n, ', '.join('%s %d' % kv for kv in collections.Counter([w['code'] for w in r['warnings']] + [p['kind'] for p in r['patterns']]).most_common())))
md = os.path.join(P, 'docs', 'level2', 'FORCING_AUDIT_%s.md' % now)
if os.path.exists(md):
    raise SystemExit('refusing to overwrite ' + md)
open(md, 'w', encoding='utf-8').write('\n'.join(M) + '\n')
print('\n'.join(M[:30])); print('json:', J); print('md:', md)
