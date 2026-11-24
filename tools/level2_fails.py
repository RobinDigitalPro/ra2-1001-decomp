"""Print EVERY non-matched claim and every symbol conflict of the newest (or given) check report.
usage: level2_fails.py [report.json]   (use after each full check; never read only the last line)"""
import glob, json, os, sys
W = r'D:\<work-root>\RedAlert2Temp'
p = sys.argv[1] if len(sys.argv) > 1 else max(glob.glob(os.path.join(W, 'analysis', 'level2', 'reports', 'check_*.json')), key=os.path.getmtime)
d = json.load(open(p))
bad = [f for f in d['functions'] if f['status'] != 'matched']
print(os.path.basename(p), 'claims', len(d['functions']), 'not matched', len(bad), 'conflicts', len(d['symbol_conflicts']))
for f in bad: print('  FAIL', f['rva'], f.get('tu'), f.get('symbol', '')[:60], f.get('byte_differences'))
for c in d['symbol_conflicts']: print('  CONFLICT', c['symbol'][:80], c['addresses'])
