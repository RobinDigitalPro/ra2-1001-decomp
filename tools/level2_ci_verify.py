"""Integrate <prefix>_*.claims.json, check their TUs, drop NEW claims that fail or take part in a symbol conflict.
usage: level2_ci_verify.py <prefix>"""
import ast, glob, json, os, subprocess, sys
P = r'D:\<project-folder>\Coding\RedAlert2'; W = r'D:\<work-root>\RedAlert2Temp'
pre = sys.argv[1]; fp = os.path.join(P, 'metadata', 'level2_functions.json')
files = sorted(glob.glob(os.path.join(W, 'analysis', 'level2', 'agents', pre + '_*.claims.json')))
new = set(); tus = []
for f in files:
    c = json.load(open(f)); tus.append(c['tu'])
    for x in c['functions']: new.add((c['tu'], x['rva']))
py = sys.executable
subprocess.run([py, '-I', os.path.join(W, 'tools', 'level2_integrate.py')] + files, check=True, stdout=subprocess.DEVNULL)
subprocess.run([py, '-I', os.path.join(W, 'tools', 'level2_check.py')] + tus, capture_output=True, text=True)
subprocess.run([py, '-I', os.path.join(W, 'tools', 'level2_autobind.py'), '--data'], stdout=subprocess.DEVNULL)   # evidence for new call/data targets
out = subprocess.run([py, '-I', os.path.join(W, 'tools', 'level2_check.py')] + tus, capture_output=True, text=True).stdout
rep = out.strip().splitlines()
line = [l for l in rep if l.startswith('matched ')][-1]; print(line)
d = json.load(open(line.split('report ')[1].strip()))
bad = set()
for c in d['symbol_conflicts']:
    try:
        tu, sym = ast.literal_eval(c['symbol'])
    except Exception:
        tu, sym = None, c['symbol']   # global symbol conflict (not TU-local)
    for f in d['functions']:
        if tu is None and (f.get('tu'), f['rva']) in new and any(b['symbol'] == sym and b['address'] in c['addresses'] for b in f['bindings']):
            bad.add((f['tu'], f['rva'])); continue
        if f.get('tu') == tu and (tu, f['rva']) in new and any(b['symbol'] == sym and b['address'] in c['addresses'] for b in f['bindings']):
            bad.add((tu, f['rva']))
for f in d['functions']:
    if f['status'] != 'matched' and (f.get('tu'), f['rva']) in new: bad.add((f.get('tu'), f['rva']))
funcs = json.load(open(fp, encoding='utf-8'))
keep = [f for f in funcs if (f['tu'], f['rva']) not in bad]
json.dump(keep, open(fp, 'w', encoding='utf-8'), indent=1, ensure_ascii=False)
json.dump(sorted(bad), open(os.path.join(W, 'analysis', 'level2', 'dropped_%s.json' % pre), 'w'), indent=0)
print('new', len(new), 'dropped', len(bad))
if bad:
    out = subprocess.run([py, '-I', os.path.join(W, 'tools', 'level2_check.py')] + sorted({t for t, _ in bad}), capture_output=True, text=True).stdout
    print([l for l in out.splitlines() if l.startswith('matched ')][-1])
