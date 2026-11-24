"""Add the 16-byte zero 'rectangle' static initializers that sit directly before (pre) or after (post) the
GAMECONST.H block of unnamed scaffold TUs, then re-map every _$E symbol of the TU to its original RVA by
byte content and rewrite that TU's initializer claims.  Only touches src/ra2/unnamed/*.cpp."""
import json, os, re, sys
P = r'D:\<project-folder>\Coding\RedAlert2'
W = r'D:\<work-root>\RedAlert2Temp'
sys.path.insert(0, os.path.join(W, 'analysis', 'level2')); sys.path.insert(0, os.path.join(W, 'tools'))
import l2match, level2_check
from coffmatch import Obj, match_function

blocks = json.load(open(os.path.join(W, 'analysis', 'level2', 'gameconst_blocks.json')))
table = [int(x, 16) - 0x400000 for x in json.load(open(os.path.join(W, 'analysis', 'level2', 'xcu_table.json')))['entries'] if int(x, 16)]
pos = {r: i for i, r in enumerate(table)}
ZERO4 = re.compile(rb'\x33\xc0\xa3....\xa3....\xa3....\xa3....\xc3', re.S)
def is_zero4(rva):
    return ZERO4.match(l2match.orig(rva, 0x18)) is not None

funcs = json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))
done = 0
for b in blocks:
    if b['names']:
        continue
    tu = 'src/ra2/unnamed/TU_%06X.cpp' % (int(b['start'], 16) + 0x400000)
    path = os.path.join(P, *tu.split('/'))
    if not os.path.exists(path):
        continue
    src = open(path).read()
    if 'ZeroRect' in src:
        continue
    e2 = int(b['rvas'][0], 16); e35 = int(b['rvas'][-1], 16)
    i, j = pos[e2], pos[e35]
    pre = table[i - 1] if i > 0 and 0 < e2 - table[i - 1] <= 0x30 and is_zero4(table[i - 1]) else None
    post = table[j + 1] if j + 1 < len(table) and 0 < table[j + 1] - e35 <= 0x30 and is_zero4(table[j + 1]) else None
    if pre is None and post is None:
        continue
    new = src.replace('#include "../GAMECONST.H"\n', ('#include "../RECT.H"\nstatic RectangleStruct const ZeroRectA(0, 0, 0, 0);\n' if pre else '') +
                      '#include "../GAMECONST.H"\n' + ('#include "../RECT.H"\nstatic RectangleStruct const ZeroRectB(0, 0, 0, 0);\n' if post else ''))
    open(path, 'w', newline='\r\n').write(new.replace('\r\n', '\n'))
    obj, info = level2_check.compile_tu(tu, os.path.join(W, 'build', 'level2'))
    if info['returncode'] != 0:
        open(path, 'w', newline='\r\n').write(src.replace('\r\n', '\n')); print('compile failed', tu); continue
    o = Obj(open(obj, 'rb').read())
    cands = ([pre] if pre else []) + [int(r, 16) for r in b['rvas']] + ([post] if post else [])
    es = sorted([k for k in o.symbols if k.startswith('_$E')], key=lambda k: int(k[3:]))
    mapping, used = {}, set()
    for e in es:
        code = o.function(e)['raw']
        for c in cands:
            if c in used:
                continue
            r = match_function(o, e, l2match.orig(c, len(code)), 0x400000 + c, lambda s: None)
            if r['byte_differences'] == 0 and not r['relocation_problems']:
                mapping[hex(c)] = e; used.add(c); break
    if len(mapping) != len(cands):
        open(path, 'w', newline='\r\n').write(src.replace('\r\n', '\n')); print('mapping incomplete', tu, len(mapping), len(cands)); continue
    funcs = [f for f in funcs if not (f['tu'] == tu and f['symbol'].startswith('_$E'))]
    for rva, sym in mapping.items():
        funcs.append(dict(rva=rva, tu=tu, symbol=sym, name='dynamic initializer (%s)' % ('ZeroRect' if int(rva, 16) in (pre, post) else 'GAMECONST.H static')))
    done += 1
funcs.sort(key=lambda x: int(x['rva'], 16))
json.dump(funcs, open(os.path.join(P, 'metadata', 'level2_functions.json'), 'w', encoding='utf-8'), indent=1)
print('TUs updated', done, 'claims', len(funcs))
