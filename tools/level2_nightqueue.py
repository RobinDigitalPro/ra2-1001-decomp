"""Token-light background search queue: run level2_mutate.py on a list of near-miss targets, one after another, and
write ONE summary line per target, so the coordinator only has to read a short file.

usage: python -I level2_nightqueue.py <queue.json> [--max N] [--beam B] [--per-state K]
queue.json: {"name": "q1", "targets": [
   {"tu": "src/m85/src/foot.cpp", "func": "FootClass::Search_For_Tiberium_Weighted",
    "symbol": "Search_For_Tiberium_Weighted@FootClass", "rva": "0xcb740",
    "controls": [["Search_For_Tiberium@FootClass", "0xcb1d0"]]}, ...]}
For each target:
- copies the CURRENT P TU to W/analysis/level2/nightqueue/<name>/<n>_<tu>/work/ (never edits P);
- writes a level2_mutate spec (claims_check on, so a match must keep every claim of the TU) and runs a beam search;
- appends one line to W/analysis/level2/nightqueue/<name>/SUMMARY.txt:
  "<time> <tu> <rva> base=<score> best=<score> MATCH|open compiles=<n> out=<dir>".
A MATCH line means: byte-identical target, all controls and TU claims kept, verified by level2_check. Its edits.json and
claims.json are in the out dir, ready for tools/level2_integrate_agent.py. REVIEW the edits for readability first.
Skips a target whose TU changed in P since the queue started (prints "skipped: TU changed").
"""
import argparse, datetime, hashlib, json, os, re, shutil, subprocess, sys
P = r'D:\<project-folder>\Coding\RedAlert2'; W = r'D:\<work-root>\RedAlert2Temp'
ap = argparse.ArgumentParser(); ap.add_argument('queue'); ap.add_argument('--max', type=int, default=400)
ap.add_argument('--beam', type=int, default=4); ap.add_argument('--per-state', type=int, default=24)
a = ap.parse_args()
q = json.load(open(a.queue, encoding='utf-8'))
root = os.path.join(W, 'analysis', 'level2', 'nightqueue', q['name']); os.makedirs(root, exist_ok=True)
summ = os.path.join(root, 'SUMMARY.txt')
sha = lambda p: hashlib.sha256(open(p, 'rb').read()).hexdigest()
start = {t['tu']: sha(os.path.join(P, t['tu'].replace('/', os.sep))) for t in q['targets']}


def line(s):
    with open(summ, 'a', encoding='utf-8') as f:
        f.write(datetime.datetime.utcnow().strftime('%Y-%m-%dT%H:%MZ ') + s + '\n')


for n, t in enumerate(q['targets']):
    src = os.path.join(P, t['tu'].replace('/', os.sep))
    if sha(src) != start[t['tu']]:
        line('%s %s skipped: TU changed in P since the queue started' % (t['tu'], t['rva'])); continue
    d = os.path.join(root, '%02d_%s' % (n, os.path.splitext(os.path.basename(t['tu']))[0])); work = os.path.join(d, 'work')
    os.makedirs(work, exist_ok=True); base = os.path.join(work, os.path.basename(src)); shutil.copyfile(src, base)
    spec = {'name': '%s_%s' % (q['name'], n), 'base': os.path.relpath(base, d), 'preset': 'ra2' if t['tu'].startswith('src/ra2/') else 'm85',
            'tu': t['tu'], 'func': t['func'], 'targets': [[t['symbol'], t['rva']]], 'controls': t.get('controls', []), 'claims_check': True}
    sp = os.path.join(d, 'spec.json'); json.dump(spec, open(sp, 'w', encoding='utf-8'), indent=1)
    out = os.path.join(d, 'out')
    r = subprocess.run([sys.executable, '-I', os.path.join(W, 'tools', 'level2_mutate.py'), sp, '--mode', 'search', '--max', str(a.max),
                        '--beam', str(a.beam), '--per-state', str(a.per_state), '--out', out], capture_output=True, text=True)
    open(os.path.join(d, 'run.log'), 'w', encoding='utf-8').write(r.stdout[-20000:] + '\n--- stderr\n' + r.stderr[-5000:])
    log = os.path.join(out, 'log.json'); res = {}
    if os.path.exists(log):
        try:
            L = json.load(open(log, encoding='utf-8'))
            res = L.get('result', {}) if isinstance(L, dict) else {}
        except Exception:
            pass
    m = re.search(r'base: score (\S+) hunks (\S+)', r.stdout)
    match = os.path.exists(os.path.join(out, 'claims.json')) or res.get('matched') is True
    line('%s %s base=%s/%sh best=%s/%sh %s compiles=%s rc=%d out=%s' % (t['tu'], t['rva'], m.group(1) if m else '?', m.group(2) if m else '?',
         res.get('best_score', '?'), res.get('best_hunks', '?'), 'MATCH' if match else 'open', res.get('compiles', '?'), r.returncode, out))
line('queue %s finished' % q['name'])
