"""Header-regression lab for the level-2 byte-matching project (m85 tree).

Usage (always with -I):
  python -I level2_hdrcheck.py snapshot <name>
      Copies the CURRENT P/src/m85/src/* (top-level files), the P/src/m85/include tree and
      P/metadata/level2_functions.json into W/build/level2/hdrlab/<name>/ and builds + scores a
      baseline over every flat m85 TU (src/m85/src/<tu>.cpp, no asm/) that has claims.
      Output: <name>/base_result.json, <name>/obj_base/*.obj, <name>/base_log.txt.
  python -I level2_hdrcheck.py variant <snapshot> <tag> <patch.json> [<patch.json> ...]
      Builds all TUs against a copy of the snapshot include tree with the patches applied,
      compares every claim with the baseline, lists LOST and GAINED claims per TU, checks the
      patch "targets" (and the watched hash-order functions) before/after.
      Output: <snapshot>/<tag>/result.json (+ include/, obj/).
  Patch JSON: {"file": "include/abstype.h",
               "edits": [[old, new], ...],            # each old must occur exactly once
               "targets": [["symbol substring", "0xRVA"], ...]}   # optional extra RVAs
  "file" is relative to the snapshot dir ("include/..." or "src/<tu>.cpp"). A patch file may also
  hold a list of such objects. Line endings of the patched file are kept (CRLF/LF).
Builds run one TU at a time, sequentially, with the batch5.sh VC6 flags
(-O2 -Ob2 -Gr -GR -DNDEBUG -Gy -DWIN32 -W0). Nothing under P is modified.
Known tool limitation: "_$E..." claims are symbol_not_unique in baseline and variants alike.
"""
import sys, os, json, shutil, subprocess, time

W = r'D:\<work-root>\RedAlert2Temp'
P = r'D:\<project-folder>\Coding\RedAlert2'
H = W + r'\build\level2\hdrlab'
V6 = W + r'\tools\portable\vc6'
sys.path.insert(0, W + r'\analysis\level2')
OK = ('matched', 'bytes_match_bindings_open')
# hash-order-sensitive functions (reported for every variant)
WATCH = {'0x1f30a0': 'ownrdraw Trackbar_Proc', '0x221b90': 'queue Print_CRCs',
         '0x334590': 'wonline Draw_Player_List', '0x2f5af0': 'unit Draw_It', '0x183940': 'mapgen 0x183940'}


def env():
    e = dict(os.environ)
    e['PATH'] = V6 + r'\VC98\BIN;' + V6 + r'\COMMON\MSDEV98\BIN;' + e['PATH']
    e['INCLUDE'] = V6 + r'\VC98\INCLUDE;' + V6 + r'\VC98\ATL\INCLUDE'
    e['LIB'] = V6 + r'\VC98\LIB'
    return e


def compile_tu(tu, src, srcdir, inc, objdir, e):
    obj = os.path.join(objdir, tu + '.obj')
    if os.path.exists(obj):
        os.remove(obj)
    try:
        p = subprocess.run([V6 + r'\VC98\BIN\CL.EXE', '-nologo', '-c', '-O2', '-Ob2', '-Gr', '-GR', '-DNDEBUG', '-Gy',
                            '-DWIN32', '-W0', '-I' + srcdir, '-I' + inc, '-Fo' + obj, src],
                           capture_output=True, env=e, timeout=900)
        msg = p.stdout.decode('latin1')[-600:]
    except subprocess.TimeoutExpired:
        msg = 'TIMEOUT'
    return obj, msg


def check(l2match, obj, sym, rva):
    try:
        r = l2match.run(obj, sym, rva, {})
        return [r.get('status'), r.get('byte_differences'), r.get('size'), r.get('original_size')]
    except Exception as ex:
        return ['ERROR', str(ex)[:80], None, None]


def build(snap, inc, srcdir_over, objdir, tag, log):
    """Compile every TU of the snapshot sequentially and score its claims. Returns {tu: {rva: [...]}|None}."""
    import l2match
    claims = json.load(open(os.path.join(snap, 'claims.json')))
    by_tu = {}
    for c in claims:
        t = c['tu']
        if t.startswith('src/m85/src/') and t.count('/') == 3 and t.endswith('.cpp'):
            by_tu.setdefault(t.split('/')[-1][:-4], []).append(c)
    os.makedirs(objdir, exist_ok=True)
    e = env()
    out = {}
    snapsrc = os.path.join(snap, 'src')
    for i, tu in enumerate(sorted(by_tu)):
        src = os.path.join(srcdir_over, tu + '.cpp') if srcdir_over and os.path.exists(os.path.join(srcdir_over, tu + '.cpp')) \
            else os.path.join(snapsrc, tu + '.cpp')
        t0 = time.time()
        obj, msg = compile_tu(tu, src, snapsrc, inc, objdir, e)
        if not os.path.exists(obj):
            line = f'{tu} COMPILE FAILED {msg!r}'
            out[tu] = None
        else:
            res = {c['rva']: [c['symbol']] + check(l2match, obj, c['symbol'], int(c['rva'], 16)) for c in by_tu[tu]}
            ok = sum(1 for v in res.values() if v[1] in OK)
            line = f'{tu} {time.time() - t0:.0f}s claims {len(res)} equal {ok}'
            out[tu] = res
        print(f'[{tag} {i + 1}/{len(by_tu)}] {line}', flush=True)
        log.write(line + '\n'); log.flush()
    return out


def patch_bytes(path, old, new):
    t = open(path, 'rb').read()
    crlf = b'\r\n' in t
    o = old.encode('latin1').replace(b'\r\n', b'\n')
    n = new.encode('latin1').replace(b'\r\n', b'\n')
    if crlf:
        o = o.replace(b'\n', b'\r\n'); n = n.replace(b'\n', b'\r\n')
    c = t.count(o)
    if c != 1:
        raise SystemExit(f'patch error: {path}: old text occurs {c} times (need exactly 1): {old[:70]!r}')
    open(path, 'wb').write(t.replace(o, n))


def find_targets(snap, objdir, targets, tus):
    """targets: [(needle, rva)] -> {'needle|rva': {'tu':..., 'res': [...]}} searching all objs for a unique symbol."""
    import l2match
    from coffmatch import Obj
    found = {}
    for needle, rva in targets:
        key = f'{needle}|{rva}'
        found[key] = None
    for tu in tus:
        p = os.path.join(objdir, tu + '.obj')
        if not os.path.exists(p):
            continue
        o = Obj(open(p, 'rb').read())
        for needle, rva in targets:
            key = f'{needle}|{rva}'
            names = [k for k in o.symbols if needle in k]
            if len(names) == 1:
                try:
                    names2 = [n for n in names if o.function(n)]
                except Exception:
                    names2 = []
                if names2:
                    found[key] = {'tu': tu, 'res': check(l2match, p, names2[0], int(rva, 16))}
    return found


def cmd_snapshot(name):
    snap = os.path.join(H, name)
    if os.path.exists(snap):
        raise SystemExit(f'{snap} exists; choose a new snapshot name')
    os.makedirs(snap)
    srcd = os.path.join(snap, 'src')
    os.makedirs(srcd)
    msrc = P + r'\src\m85\src'
    for f in os.listdir(msrc):
        fp = os.path.join(msrc, f)
        if os.path.isfile(fp):
            shutil.copy2(fp, srcd)
    shutil.copytree(P + r'\src\m85\include', os.path.join(snap, 'include'))
    shutil.copy2(P + r'\metadata\level2_functions.json', os.path.join(snap, 'claims.json'))
    with open(os.path.join(snap, 'base_log.txt'), 'w') as log:
        res = build(snap, os.path.join(snap, 'include'), None, os.path.join(snap, 'obj_base'), 'base', log)
    json.dump(res, open(os.path.join(snap, 'base_result.json'), 'w'))
    tot = eq = fail = 0
    ne = []
    for tu, r in res.items():
        if r is None:
            fail += 1; continue
        for rva, v in r.items():
            tot += 1
            if v[1] in OK: eq += 1
            else: ne.append((tu, rva, v[0][:50], v[1]))
    notuniq = [x for x in ne if x[2].startswith('_$E') and x[3] == 'symbol_not_unique']
    print(f'BASELINE {name}: {tot} claims checked, {eq} equal, {len(ne)} not equal '
          f'({len(notuniq)} are _$E symbol_not_unique), {fail} compile failures')
    for x in ne:
        if x not in notuniq: print('  NOT EQUAL', x)
    for rva, nm in WATCH.items():
        for tu, r in res.items():
            if r and rva in r: print('  watch', nm, rva, tu, r[rva][1], r[rva][2])


def load_patches(files):
    out = []
    for f in files:
        d = json.load(open(f, encoding='utf-8'))
        out += d if isinstance(d, list) else [d]
    return out


def cmd_variant(snapname, tag, pfiles):
    snap = os.path.join(H, snapname)
    vdir = os.path.join(snap, tag)
    if os.path.exists(vdir):
        shutil.rmtree(vdir)
    os.makedirs(vdir)
    inc = os.path.join(vdir, 'include')
    shutil.copytree(os.path.join(snap, 'include'), inc)
    vsrc = os.path.join(vdir, 'src')
    os.makedirs(vsrc)
    patches = load_patches(pfiles)
    targets = []
    for pt in patches:
        f = pt['file'].replace('\\', '/')
        if f.startswith('include/'):
            p = os.path.join(vdir, f)
        elif f.startswith('src/'):
            p = os.path.join(vsrc, f[4:])
            if not os.path.exists(p):
                shutil.copy2(os.path.join(snap, f), p)
        else:
            raise SystemExit('patch file must start with include/ or src/: ' + f)
        for old, new in pt['edits']:
            patch_bytes(p, old, new)
        targets += [tuple(t) for t in pt.get('targets', [])]
    base = json.load(open(os.path.join(snap, 'base_result.json')))
    with open(os.path.join(vdir, 'log.txt'), 'w') as log:
        var = build(snap, inc, vsrc, os.path.join(vdir, 'obj'), tag, log)
    result = {'snapshot': snapname, 'tag': tag, 'patches': pfiles, 'lost': [], 'gained': [], 'changed': [],
              'compile_failed': [], 'targets': {}, 'watch': {}}
    for tu in var:
        b, v = base.get(tu), var[tu]
        if v is None:
            result['compile_failed'].append(tu)
            if b:
                for rva, x in b.items():
                    if x[1] in OK: result['lost'].append([tu, rva, x[0], 'COMPILE FAILED'])
            continue
        if b is None: continue
        for rva, x in v.items():
            y = b.get(rva)
            if not y: continue
            if y[1] in OK and x[1] not in OK: result['lost'].append([tu, rva, x[0], x[1], x[2]])
            elif y[1] not in OK and x[1] in OK: result['gained'].append([tu, rva, x[0], x[1]])
            elif y[1:] != x[1:]: result['changed'].append([tu, rva, x[0], y[1:], x[1:]])
    if targets:
        tus = sorted(var)
        before = find_targets(snap, os.path.join(snap, 'obj_base'), targets, tus)
        after = find_targets(snap, os.path.join(vdir, 'obj'), targets, tus)
        for k in before:
            result['targets'][k] = {'before': before[k], 'after': after[k]}
    for rva, nm in WATCH.items():
        for tu in var:
            if var[tu] and rva in var[tu] and base.get(tu) and rva in base[tu]:
                result['watch'][rva] = {'name': nm, 'tu': tu, 'before': base[tu][rva][1:], 'after': var[tu][rva][1:]}
    json.dump(result, open(os.path.join(vdir, 'result.json'), 'w'), indent=1)
    print(f'VARIANT {tag} on {snapname}: lost {len(result["lost"])}, gained {len(result["gained"])}, '
          f'status/bytes changed {len(result["changed"])}, compile failures {len(result["compile_failed"])}')
    for k in ('lost', 'gained', 'changed'):
        for x in result[k]: print(' ', k.upper(), x)
    for k, v in result['targets'].items():
        print('  TARGET', k, 'before', v['before'], 'after', v['after'])
    for rva, w in result['watch'].items():
        print('  watch', w['name'], rva, w['tu'], w['before'][0], w['before'][1], '->', w['after'][0], w['after'][1])


def main():
    a = sys.argv[1:]
    if len(a) == 2 and a[0] == 'snapshot':
        cmd_snapshot(a[1])
    elif len(a) >= 4 and a[0] == 'variant':
        cmd_variant(a[1], a[2], a[3:])
    else:
        print(__doc__); sys.exit(2)


if __name__ == '__main__':
    main()
