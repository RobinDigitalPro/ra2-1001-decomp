"""Integrate one agent's (or Codex job's) deliverables into a TU and verify them, in one step.

usage: python -I level2_integrate_agent.py <tu> <deliverable dir> [--claims FILE] [--append FILE ...] [--no-append]
                                           [--extra RVA=SYMBOL=NAME ...] [--dry-run]
  <tu>               TU path relative to P, e.g. src/m85/src/wonline.cpp
  <deliverable dir>  folder with any of: edits.py (EDITS = [(old, new), ...]), edits*.json ([[old, new], ...]),
                     proposal.cpp (appended to the TU), *.claims.json (or give --claims)
  --append FILE      append these files instead of proposal.cpp (relative to the deliverable dir)
  --extra            extra claims for the same TU, e.g. 0x352d70=?add@?$ArrayList@UChannel@@@@QAEDAAUChannel@@H@Z=ArrayList<Channel>::add

Steps:
  1. Back up the TU (W/analysis/level2/header_backups/<name>.before_<prefix>).
  2. Apply the exact edits. Each old string must occur exactly once at that moment, else stop without writing.
  3. Normalise appended code to the TU's line endings. Auto-fix single-backslash "C:\\RA2\\..." path literals.
     Drop `extern` lines for globals the TU already defines (a late extern makes VC6 emit the initializer twice).
  4. Copy the claims to agents/<prefix>_<x>.claims.json and run level2_ci_verify.py <prefix>.
  5. Print every dropped claim with its reason (byte differences or unverified bindings).
     If the TU's final check shows a lost EXISTING claim, restore the backup and say so.
"""
import argparse, glob, json, os, re, shutil, subprocess, sys
P = r'D:\OneDrive - RDI\Coding\RedAlert2'; W = r'D:\CodexTemp\RedAlert2Temp'; L = os.path.join(W, 'analysis', 'level2')
ap = argparse.ArgumentParser()
ap.add_argument('tu'); ap.add_argument('dir'); ap.add_argument('--claims'); ap.add_argument('--append', nargs='*')
ap.add_argument('--no-append', action='store_true'); ap.add_argument('--extra', nargs='*', default=[]); ap.add_argument('--dry-run', action='store_true')
a = ap.parse_args()
tu_path = os.path.join(P, a.tu.replace('/', os.sep)); D = a.dir
BS = chr(92)

# a fresh prefix wNN that no claims or dropped file uses yet
used = [int(m.group(1)) for f in glob.glob(os.path.join(L, 'agents', 'w*_*.claims.json')) + glob.glob(os.path.join(L, 'dropped_w*.json'))
        for m in [re.match(r'w(\d+)', os.path.basename(f).replace('dropped_', ''))] if m]
prefix = 'w%d' % (max(used + [0]) + 1)

raw = open(tu_path, 'rb').read(); crlf = raw.count(b'\r\n') > raw.count(b'\n') // 2
text = raw.decode('latin-1').replace('\r\n', '\n')

edits = []
if os.path.exists(os.path.join(D, 'edits.py')):
    ns = {}; exec(compile(open(os.path.join(D, 'edits.py'), encoding='utf-8').read(), 'edits.py', 'exec'), ns); edits += list(ns['EDITS'])
seen_sets = []
for f in sorted(glob.glob(os.path.join(D, 'edits*.json'))):
    es = [((e['old'], e['new']) if isinstance(e, dict) else tuple(e)) for e in json.load(open(f, encoding='utf-8'))]  # [old, new] pairs or {"old","new"} objects
    norm = [(o.replace('\r\n', '\n'), n.replace('\r\n', '\n')) for o, n in es]
    if norm in seen_sets:      # agents sometimes leave an LF/CRLF copy of the same set (edits_lf.json); apply it once
        print('skip duplicate edit set:', os.path.basename(f)); continue
    seen_sets.append(norm); edits += es
# 2026-11-28 guard: a deliverable dir without any edits.py / edits*.json / append file and without extra claims used to
# rewrite the TU unchanged and report "matched", which hid two integrations whose edits.json sat one folder higher.
if not edits and not a.extra and not glob.glob(os.path.join(D, 'proposal.cpp')) and not a.append \
        and not (a.claims or glob.glob(os.path.join(D, '*claims*.json'))):
    sys.exit('no edits.py, edits*.json, proposal.cpp, --append, --extra or claims found in %s: nothing to integrate (is edits.json in another folder?)' % D)
for i, (old, new) in enumerate(edits):
    old = old.replace('\r\n', '\n'); new = new.replace('\r\n', '\n'); n = text.count(old)
    if n != 1:
        sys.exit('edit %d: old text occurs %d times; nothing written. Start: %r' % (i, n, old[:120]))
    text = text.replace(old, new)
print('edits applied:', len(edits))

appends = [] if a.no_append else ([os.path.join(D, f) for f in a.append] if a.append else
                                  [p for p in [os.path.join(D, 'proposal.cpp')] if os.path.exists(p)])
for f in appends:
    s = open(f, 'rb').read().decode('latin-1').replace('\r\n', '\n')
    if not s.strip() or all(l.strip().startswith('//') or not l.strip() for l in s.split('\n')):
        print('skip (comments only):', os.path.basename(f)); continue
    bad = re.findall(r'"C:' + re.escape(BS) + r'RA2' + re.escape(BS) + r'(\w+\.(?:cpp|CPP|h))"', s)
    if bad:
        s = re.sub(r'"C:' + re.escape(BS) + r'RA2' + re.escape(BS) + r'(\w+\.(?:cpp|CPP|h))"', lambda m: '"C:' + BS * 2 + 'RA2' + BS * 2 + m.group(1) + '"', s)
        print('fixed single-backslash path literals:', len(bad))
    out = []
    for line in s.split('\n'):
        m = re.match(r'\s*extern\s+[^;(]*?\b([A-Za-z_]\w*)\s*(\[[^\]]*\])?\s*;', line)
        if m and re.search(r'^(?!\s*(extern|//|#|typedef|return|static inline))[A-Za-z_][\w:<>,\s\*&]*\b' + re.escape(m.group(1)) + r'\s*(\[[^\]]*\])?\s*(=[^;]*|\([^;]*\))?;', text, re.M):
            print('dropped late extern for an already defined global:', m.group(1)); continue
        out.append(line)
    text = text.rstrip('\n') + '\n\n' + '\n'.join(out).rstrip('\n') + '\n'
    print('appended:', os.path.basename(f))
lit = re.findall(r'"C:' + re.escape(BS) + r'RA2' + re.escape(BS) + r'[^"\n]*"', text)
if lit:
    print('WARNING: single-backslash path literals remain in the TU:', lit[:3])

cl = a.claims or next(iter(sorted(glob.glob(os.path.join(D, '*.claims.json')) + glob.glob(os.path.join(D, 'claims.json')))), None)   # some agents name it plain claims.json
if not a.claims and cl is None and glob.glob(os.path.join(D, '*claims*.json')):
    sys.exit('claims-like file found but not picked up; pass it with --claims: %s' % glob.glob(os.path.join(D, '*claims*.json'))[:3])
claims = json.load(open(cl, encoding='utf-8')) if cl else {'tu': a.tu, 'functions': [], 'symbols': {}, 'open': []}
if isinstance(claims.get('symbols'), list):     # some agents write [] or a list of {name: ...}; ci_verify needs a dict
    sl = claims['symbols']; claims['symbols'] = {}
    for x in sl:
        if isinstance(x, dict) and ('symbol' in x or 'name' in x):
            k = x.get('symbol') or x.get('name'); claims['symbols'][k] = {kk: vv for kk, vv in x.items() if kk not in ('symbol', 'name')}
    print('normalised symbols list -> dict (%d entries)' % len(claims['symbols']))
if isinstance(claims.get('symbols'), dict):     # some agents write {"symbol": "0xaddress"}; ci_verify needs {"symbol": {"address": ..}}
    for k, v in list(claims['symbols'].items()):
        if isinstance(v, str):
            claims['symbols'][k] = {'address': v, 'evidence': 'data', 'note': 'agent proposal (normalised by integrate_agent)'}
            print('normalised symbol entry', k[:50], '->', v)
for f in claims.get('functions', []):       # agents sometimes write "matched (scratch check ...)"; the checker decides anyway
    st = str(f.get('status', ''))
    if st not in ('matched', 'bytes_match_bindings_open'):
        f['status'] = 'matched' if st.startswith('matched') else 'bytes_match_bindings_open'
        print('normalised status %r -> %s for %s' % (st[:40], f['status'], f['rva']))
have = {c['rva'] for c in claims['functions']}
for e in a.extra:
    rva, sym, name = e.split('=', 2)
    if rva not in have:
        claims['functions'].append({'rva': rva, 'symbol': sym, 'name': name, 'status': 'bytes_match_bindings_open'})
if a.dry_run:
    print('dry run: %d claims, prefix %s; nothing written' % (len(claims['functions']), prefix)); sys.exit(0)

bak = os.path.join(L, 'header_backups', '%s.before_%s' % (os.path.basename(tu_path), prefix))
shutil.copyfile(tu_path, bak)
open(tu_path, 'wb').write((text.replace('\n', '\r\n') if crlf else text).encode('latin-1'))
print('TU written; backup', bak)
if not claims['functions']:
    # source-only change (readability, near-miss progress): the TU's existing claims must all still match
    r = subprocess.run([sys.executable, '-I', os.path.join(W, 'tools', 'level2_check.py'), a.tu], capture_output=True, text=True)
    line = [l for l in r.stdout.splitlines() if l.startswith('matched ')]
    print(line[-1] if line else r.stdout[-500:])
    m = re.match(r'matched (\d+)/(\d+); conflicts (\d+)', line[-1]) if line else None
    if not m or m.group(1) != m.group(2) or m.group(3) != '0':
        shutil.copyfile(bak, tu_path); print('EXISTING CLAIMS LOST -> TU restored from backup')
    sys.exit(0)
cf = os.path.join(L, 'agents', '%s_x.claims.json' % prefix); json.dump(claims, open(cf, 'w', encoding='utf-8'), indent=1)
meta_bak = {}
for mf in ('level2_functions.json', 'level2_symbols.json'):     # so a failed integration can be undone completely
    mp = os.path.join(P, 'metadata', mf); meta_bak[mp] = os.path.join(L, 'header_backups', '%s.before_%s' % (mf, prefix)); shutil.copyfile(mp, meta_bak[mp])
r = subprocess.run([sys.executable, '-I', os.path.join(W, 'tools', 'level2_ci_verify.py'), prefix], capture_output=True, text=True)
print(r.stdout.strip()[-1500:])
if r.returncode:
    print('ci_verify FAILED (exit %d); the TU is written but the claims are NOT integrated:\n%s' % (r.returncode, r.stderr.strip()[-1500:]))
reps = re.findall(r'report (\S+\.json)', r.stdout)
dropf = os.path.join(L, 'dropped_%s.json' % prefix)
dropped = json.load(open(dropf)) if os.path.exists(dropf) else []
if dropped and reps:
    first = json.load(open(reps[0]))
    for tu, rva in dropped:
        f = next((x for x in first['functions'] if x['rva'] == rva and x.get('tu') == tu), None)
        if f:
            ub = [(b['symbol'][:60], b['address'], b['evidence'][:60]) for b in f.get('bindings', []) if not b['verified']]
            print('DROPPED %s %s: %s bytes differ %s; unverified %s' % (rva, f['symbol'][:50], f.get('status'), f.get('byte_differences'), ub[:4]))
if reps:
    last = json.load(open(reps[-1]))
    lost = [x for x in last['functions'] if x.get('tu') == a.tu and x.get('status') != 'matched']
    if lost:
        shutil.copyfile(bak, tu_path)
        print('LOST EXISTING CLAIMS -> TU restored from backup:', [(x['rva'], x['symbol'][:40]) for x in lost][:8])
        print('NOTE: the integrated claims of this prefix are still in metadata; drop them with the dropped list or rerun.')
# Independent final gate (added 2026-11-23 after a whole-TU compile failure, 0/17, slipped through the check above):
# every claim of the TU must match, otherwise restore the TU AND the metadata to their state before this run.
chk = subprocess.run([sys.executable, '-I', os.path.join(W, 'tools', 'level2_check.py'), a.tu], capture_output=True, text=True)
ml = [l for l in chk.stdout.splitlines() if l.startswith('matched ')]
mm = re.match(r'matched (\d+)/(\d+); conflicts (\d+)', ml[-1]) if ml else None
if not mm or mm.group(1) != mm.group(2) or mm.group(3) != '0':
    shutil.copyfile(bak, tu_path)
    for mp, mb in meta_bak.items():
        shutil.copyfile(mb, mp)
    print('FINAL GATE FAILED (%s) -> TU and metadata restored to the state before this run' % (ml[-1] if ml else 'no matched line'))
else:
    print('final gate:', ml[-1])

try:
    import subprocess as _sp, sys as _sy
    _sp.run([_sy.executable, '-I', 'D:/CodexTemp/RedAlert2Temp/tools/level2_journal.py', 'integrate', '%s from %s: %s' % (a.tu, a.dir, (r.stdout.strip().splitlines() or [''])[-1] if 'r' in dir() else 'no claims')], timeout=60)
except Exception:
    pass
