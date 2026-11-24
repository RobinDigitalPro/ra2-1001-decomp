"""Update the read-only community reference checkouts and summarise what changed.

usage: python -I level2_refs_update.py [--base DIR] [--dry-run]
  --base  folder holding the git checkouts plus provenance.json (default W/analysis/references_gpl_20261118)

The user authorised regular updates on 2026-11-22. For every checkout listed in provenance.json:
  - git fetch --depth 1 of the remote's default branch, with hooks disabled (core.hooksPath -> an empty folder),
    LFS smudge skipped and no checkout-time filters;
  - the changed files (name-status) are listed;
  - the work tree is reset to the fetched commit;
  - provenance.json gets the new commit, the update time and a history entry (old -> new, number of changed files).
Matching-progress deltas, when the repository has them:
  - mischa85: config/ra2-1.006/functions.csv, the count of rows "code of src/..., matched";
  - gibbo101: data/manifest.csv, its row count.
The summary goes to P/docs/level2/refs_update_<utc>.md. Nothing inside the checkouts is ever executed.
"""
import argparse, csv, datetime, json, os, subprocess, sys
W = r'D:\<work-root>\RedAlert2Temp'
ap = argparse.ArgumentParser(); ap.add_argument('--base', default=os.path.join(W, 'analysis', 'references_gpl_20261118'))
ap.add_argument('--dry-run', action='store_true'); a = ap.parse_args()
nohooks = os.path.join(W, 'tools', 'portable', 'empty_hooks'); os.makedirs(nohooks, exist_ok=True)
env = dict(os.environ, GIT_LFS_SKIP_SMUDGE='1', GIT_TERMINAL_PROMPT='0')
G = ['git', '-c', 'core.hooksPath=' + nohooks, '-c', 'filter.lfs.smudge=', '-c', 'filter.lfs.process=', '-c', 'filter.lfs.required=false',
     '-c', 'core.fsmonitor=false', '-c', 'protocol.file.allow=never']


def git(repo, *args):
    r = subprocess.run(G + list(args), cwd=repo, capture_output=True, text=True, env=env, timeout=600)
    if r.returncode:
        raise RuntimeError('git %s: %s' % (' '.join(args), (r.stderr or r.stdout)[-400:]))
    return r.stdout.strip()


def progress(repo):
    p = os.path.join(repo, 'config', 'ra2-1.006', 'functions.csv')
    if os.path.exists(p):
        rows = list(csv.DictReader(open(p, encoding='utf-8')))
        return 'functions.csv: %d rows, %d "code of src" matched' % (len(rows), sum(1 for r in rows if r.get('evidence', '').startswith('code of src')))
    p = os.path.join(repo, 'data', 'manifest.csv')
    if os.path.exists(p):
        return 'manifest.csv: %d matched rows' % (sum(1 for _ in open(p, encoding='utf-8')) - 1)
    p = os.path.join(repo, 'README.md')     # meastes/redalert2-decomp: the headline table in its README (added 2026-11-23)
    if os.path.basename(repo).startswith('meastes') and os.path.exists(p):
        rows = [l.strip() for l in open(p, encoding='utf-8', errors='replace') if l.startswith('| Reproduced .text') or l.startswith('| In-scope functions matched exactly')]
        return '; '.join(r.strip('| ').replace(' | ', ': ') for r in rows)
    return ''


provf = os.path.join(a.base, 'provenance.json'); prov = json.load(open(provf, encoding='utf-8'))
now = datetime.datetime.utcnow().strftime('%Y-%m-%dT%H%MZ'); out = ['# Reference update %s' % now, '']
for name, meta in prov.items():
    repo = os.path.join(a.base, name)
    if not isinstance(meta, dict) or not os.path.isdir(os.path.join(repo, '.git')):
        continue
    try:
        old = git(repo, 'rev-parse', 'HEAD'); before = progress(repo)
        head = git(repo, 'ls-remote', '--symref', 'origin', 'HEAD').split('\n')[0]
        branch = head.split('refs/heads/')[1].split()[0] if 'refs/heads/' in head else 'main'
        git(repo, 'fetch', '--depth', '1', 'origin', branch)
        new = git(repo, 'rev-parse', 'FETCH_HEAD')
        if new == old:
            out += ['## %s: unchanged (%s)' % (name, old[:10]), '']; continue
        try:
            changed = git(repo, 'diff', '--name-status', old, new).split('\n')
        except RuntimeError:
            changed = ['(shallow history: diff not available)']
        if a.dry_run:
            out += ['## %s: %s -> %s, %d changed files (dry run, not applied)' % (name, old[:10], new[:10], len(changed)), ''] + changed[:40] + ['']
            continue
        git(repo, 'reset', '--hard', new)
        after = progress(repo)
        meta.setdefault('history', []).append({'utc': now, 'from': old, 'to': new, 'changed_files': len(changed)})
        meta['commit'] = new; meta['utc_updated'] = now
        out += ['## %s: %s -> %s, %d changed files' % (name, old[:10], new[:10], len(changed)),
                '- progress before: ' + before, '- progress after: ' + after, ''] + ['    ' + c for c in changed[:200]] + ['']
    except Exception as e:
        out += ['## %s: FAILED: %s' % (name, e), '']
if not a.dry_run:
    json.dump(prov, open(provf, 'w', encoding='utf-8'), indent=1)
rep = os.path.join(r'D:\<project-folder>\Coding\RedAlert2', 'docs', 'level2', 'refs_update_%s.md' % now); open(rep, 'w', encoding='utf-8').write('\n'.join(out) + '\n')
print('\n'.join(out[:60])); print('report:', rep)
