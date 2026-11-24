"""Apply level2_hdrcheck-format patches (headers and/or TUs) to P, with backups, or revert them.

usage: python -I level2_apply_patch.py apply <name> <patch.json> [<patch.json> ...]
       python -I level2_apply_patch.py revert <name>
Patch JSON (as level2_hdrcheck.py): {"file": "include/x.h" | "src/<tu>.cpp", "edits": [[old, new], ...], "targets": [...]}
or a list of such objects. "include/..." maps to P/src/m85/include/..., "src/<x>.cpp" to P/src/m85/src/<x>.cpp,
and a path that already starts with "src/m85/" or "src/ra2/" is taken relative to P.
- Every old string must occur exactly once (after CRLF->LF normalisation) or NOTHING is written.
- Line endings of each file are kept. Backups go to W/analysis/level2/header_backups/apply_<name>/ with a manifest.json.
- apply refuses to run twice with the same name; revert restores the backed-up files exactly.
Run a check afterwards (level2_check.py for the affected TUs, see level2_hdrimpact.py, or the full check).
"""
import json, os, shutil, sys
P = r'D:\<project-folder>\Coding\RedAlert2'; W = r'D:\<work-root>\RedAlert2Temp'
BK = os.path.join(W, 'analysis', 'level2', 'header_backups')


def target(f):
    f = f.replace('\\', '/')
    if f.startswith(('src/m85/', 'src/ra2/')):
        return os.path.join(P, f.replace('/', os.sep))
    if f.startswith('include/'):
        return os.path.join(P, 'src', 'm85', f.replace('/', os.sep))
    if f.startswith('src/'):
        return os.path.join(P, 'src', 'm85', f.replace('/', os.sep))
    sys.exit('unknown patch file path: ' + f)


cmd, name = sys.argv[1], sys.argv[2]
d = os.path.join(BK, 'apply_' + name)
if cmd == 'revert':
    m = json.load(open(os.path.join(d, 'manifest.json'), encoding='utf-8'))
    for path, bak in m['files'].items():
        shutil.copyfile(bak, path); print('restored', path)
    sys.exit(0)
if cmd != 'apply':
    sys.exit(__doc__)
if os.path.exists(d):
    sys.exit('apply %s was already run (backup folder exists); use another name or revert first' % name)
patches = []
for pf in sys.argv[3:]:
    x = json.load(open(pf, encoding='utf-8'))
    patches += x if isinstance(x, list) else [x]
texts = {}
for p in patches:
    path = target(p['file'])
    if path not in texts:
        raw = open(path, 'rb').read()
        texts[path] = [raw, b'\r\n' in raw, raw.decode('latin-1').replace('\r\n', '\n')]
    t = texts[path][2]
    for i, (o, n) in enumerate(p['edits']):
        o = o.replace('\r\n', '\n'); n = n.replace('\r\n', '\n'); c = t.count(o)
        if c != 1:
            sys.exit('%s edit %d: old text occurs %d times; nothing written. Start: %r' % (p['file'], i, c, o[:100]))
        t = t.replace(o, n)
    texts[path][2] = t
os.makedirs(d)
man = {'name': name, 'patches': sys.argv[3:], 'files': {}}
for k, (path, (raw, crlf, t)) in enumerate(texts.items()):
    bak = os.path.join(d, '%02d_%s' % (k, os.path.basename(path)))
    open(bak, 'wb').write(raw); man['files'][path] = bak
    open(path, 'wb').write((t.replace('\n', '\r\n') if crlf else t).encode('latin-1'))
    print('patched', path)
json.dump(man, open(os.path.join(d, 'manifest.json'), 'w', encoding='utf-8'), indent=1)
print('backup', d)
