"""List claims whose start lies INSIDE another claim's body (bogus duplicates, e.g. an empty `ret 8` body matching another
function's tail). usage: python -I level2_overlaps.py [--plan out.json]   (read-only unless --plan writes a level2_move_claims plan; uses the latest check report per RVA for sizes)"""
import glob, json, os, struct
P = r'D:\<project-folder>\Coding\RedAlert2'; W = r'D:\<work-root>\RedAlert2Temp'
latest = {}
for p in sorted(glob.glob(os.path.join(W, 'analysis', 'level2', 'reports', 'check_*.json'))):
    for f in json.load(open(p))['functions']:
        latest[f['rva']] = f
F = sorted(json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8')), key=lambda f: int(f['rva'], 16))
B = open(os.path.join(P, 'RA2Original', 'GAME.EXE'), 'rb').read()
pe = struct.unpack_from('<I', B, 0x3c)[0]; so = struct.unpack_from('<H', B, pe + 20)[0]
vs, va, rs, ra = struct.unpack_from('<IIII', B, pe + 24 + so + 8)
def body_end(r, sz):   # original body end with trailing NOP/INT3 padding removed
    e = r + sz
    while e > r and B[ra + e - 1 - va] in (0x90, 0xcc):
        e -= 1
    return e
import sys
prev = None
n = 0
bad = []
for f in F:
    r = int(f['rva'], 16); sz = (latest.get(f['rva']) or {}).get('size') or 0
    o = ra + r - va
    after_end = B[o - 1] in (0xc3, 0x90, 0xcc) or B[o - 3] == 0xc2 or B[o - 5] == 0xe9   # ret / padding / ret n / jmp before it
    if prev and r < body_end(prev[0], prev[1]) and not after_end:
        # trailing padding of the previous body is fine only if the bytes there are not this claim's own start
        bad.append({'tu': f['tu'], 'rva': f['rva']}); print('OVERLAP %s %s (%s) starts inside %s %s (+0x%x of %d), and the byte before it is mid-code' % (f['rva'], f['symbol'][:45], f['tu'], prev[2], prev[3][:40], r - prev[0], prev[1])); n += 1
    if not prev or r + sz > prev[0] + prev[1]:
        prev = (r, sz, f['rva'], f['symbol'])
print('overlaps:', n)
if '--plan' in sys.argv:
    json.dump({'name': 'drop_tail_overlaps', 'reason': 'claims of empty functions (ret / ret n bodies such as DebugString, Init_Theater) that sit on the LAST instruction of another claimed function (level2_overlaps.py); bogus coincidental matches',
               'remove': bad, 'add': []}, open(sys.argv[sys.argv.index('--plan') + 1], 'w'), indent=1)
