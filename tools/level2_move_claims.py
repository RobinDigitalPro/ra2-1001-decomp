"""Apply a claim move or reattribution plan to P/metadata/level2_functions.json, record it, and verify the TUs.

usage: python -I level2_move_claims.py <plan.json> [--dry-run]
plan.json:
{
  "name": "unit_geoconst",                          // the record is written to W/analysis/level2/moved_<name>.json
  "reason": "why (evidence)",
  "remove": [{"tu": "src/ra2/unnamed/TU_6EEE80.cpp", "rva": "0x2eee80"}, ...],   // or {"tu": ..., "all": true}
  "add":    [{"rva": "0x2eee80", "tu": "src/m85/src/unit.cpp", "symbol": "_$E5", "name": "..."}, ...],
  "check":  ["src/m85/src/unit.cpp"]                // TUs to run level2_check on afterwards (default: every TU touched)
}
- A removed row must exist; an added RVA must not stay claimed by another row, unless that row is removed in the same plan.
- functions.json is backed up to W/analysis/level2/header_backups/level2_functions.before_<name>.json.
- If a check shows a not-matched claim among the ADDED rows, the tool prints it. Fix the plan and rerun, or restore the backup.
"""
import json, os, shutil, subprocess, sys
P = r'D:\<project-folder>\Coding\RedAlert2'; W = r'D:\<work-root>\RedAlert2Temp'; L = os.path.join(W, 'analysis', 'level2')
plan = json.load(open(sys.argv[1], encoding='utf-8')); dry = '--dry-run' in sys.argv
fp = os.path.join(P, 'metadata', 'level2_functions.json'); F = json.load(open(fp, encoding='utf-8'))
rm_all = {r['tu'] for r in plan.get('remove', []) if r.get('all')}
rm = {(r['tu'], r['rva']) for r in plan.get('remove', []) if not r.get('all')}
have = {(f['tu'], f['rva']) for f in F}
missing = [x for x in rm if x not in have]
if missing:
    sys.exit('rows to remove do not exist: %s' % missing[:5])
removed = [f for f in F if (f['tu'], f['rva']) in rm or f['tu'] in rm_all]
keep = [f for f in F if not ((f['tu'], f['rva']) in rm or f['tu'] in rm_all)]
taken = {f['rva']: f['tu'] for f in keep}
clash = [(a['rva'], taken[a['rva']]) for a in plan.get('add', []) if a['rva'] in taken]
if clash:
    sys.exit('added RVAs are still claimed by other rows (remove them in the plan): %s' % clash[:5])
added = [{'rva': a['rva'], 'tu': a['tu'], 'symbol': a['symbol'], 'name': a.get('name', a['symbol'])} for a in plan.get('add', [])]
print('remove %d rows, add %d rows' % (len(removed), len(added)))
if dry:
    sys.exit(0)
shutil.copyfile(fp, os.path.join(L, 'header_backups', 'level2_functions.before_%s.json' % plan['name']))
json.dump(keep + added, open(fp, 'w', encoding='utf-8'), indent=1)
json.dump({'name': plan['name'], 'reason': plan.get('reason', ''), 'removed': removed, 'added': added},
          open(os.path.join(L, 'moved_%s.json' % plan['name']), 'w', encoding='utf-8'), indent=1)
tus = plan.get('check') or sorted({f['tu'] for f in removed + added})
r = subprocess.run([sys.executable, '-I', os.path.join(W, 'tools', 'level2_check.py')] + tus, capture_output=True, text=True)
print('\n'.join(l for l in r.stdout.splitlines() if l.startswith('matched') or 'not_matched' in l or 'CONFLICT' in l)[-2000:])

try:
    import subprocess as _sp, sys as _sy
    _sp.run([_sy.executable, '-I', '<RA2_WORK>/tools/level2_journal.py', 'move', '%s: removed %d added %d; %s' % (plan['name'], len(removed), len(added), plan.get('reason','')[:200])], timeout=60)
except Exception:
    pass
