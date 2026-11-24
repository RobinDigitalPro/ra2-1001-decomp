"""Scan .text of GAME.EXE for plausible function starts that function_map.json and the claims do not know.

usage: level2_scan_starts.py [<out json>]     (default W/analysis/level2/extra_starts.json)

A candidate address A is reported when
  * A is not a start in function_map.json or the level-1 Ghidra index, not a claimed RVA, and not inside a
    claimed function [rva, rva+size) (sizes from the check report covering the most claims);
  * A is 16-aligned and preceded by 1..15 bytes of 0x90/0xCC fill which follow a flow terminator
    (ret / ret N / jmp rel32 / jmp rel8 / jmp [mem] / jmp reg)  -> reason 'pad_after_<terminator>',
    or A is exactly the end of a claimed function (aligned or not) -> reason 'after_claimed_end'
    (both reasons are listed when both hold);
  * the byte at A is not fill, the first dword is not a .text pointer (jump/data tables after a ret), and the
    first instructions decode as ordinary code (capstone from tools/portable when available).
Read-only on GAME.EXE and the metadata.  These are candidate starts only; level2_check.py stays the authority.
"""
import glob, json, os, struct, sys
P = r'D:\<project-folder>\Coding\RedAlert2'
W = r'D:\<work-root>\RedAlert2Temp'
sys.path.insert(0, os.path.join(W, 'tools'))
import level2_check as lc

OUT = sys.argv[1] if len(sys.argv) > 1 else os.path.join(W, 'analysis', 'level2', 'extra_starts.json')
B, secs = lc.image()
text = next(s for s in secs if s[0] == '.text')
tbase, tsize = 0x400000 + text[1], min(text[2], text[3])
T = lc.read(B, secs, tbase, tsize)
trva = text[1]

# ---- known starts
fmap = json.load(open(os.path.join(W, 'analysis', 'level2', 'function_map.json')))['map']
known = {int(f['rva'], 16) for f in fmap}
known |= {int(json.loads(l)['rva'], 16) for l in open(lc.FUNCS)}
franges = sorted((int(a, 16), int(b, 16)) for f in fmap for a, b in f.get('ranges', []))
funcs = json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))
claimed = {int(x['rva'], 16) for x in funcs}

# ---- claimed extents: the check report that covers the most claims (newest on ties)
best, bestn = None, -1
for rp in sorted(glob.glob(os.path.join(W, 'analysis', 'level2', 'reports', 'check_*.json')))[-12:]:
    try:
        n = len(json.load(open(rp))['functions'])
    except Exception:
        continue
    if n >= bestn:
        best, bestn = rp, n
size_of = {}
if best:
    for f in json.load(open(best))['functions']:
        if f.get('size'):
            size_of[int(f['rva'], 16)] = max(size_of.get(int(f['rva'], 16), 0), int(f['size']))
inside = bytearray(tsize)          # 1 = covered by a claimed function body
ends = set()
for r in claimed:
    s = size_of.get(r, 1)
    lo, hi = max(r - trva, 0), min(r - trva + s, tsize)
    inside[lo:hi] = b'\1' * max(hi - lo, 0)
    if r in size_of:
        ends.add(r + s)

try:
    sys.path.insert(0, os.path.join(W, 'tools', 'portable', 'capstone-5.0.6'))
    import capstone
    MD = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
except Exception:
    MD = None
BAD = {'hlt', 'in', 'out', 'insb', 'insd', 'outsb', 'outsd', 'les', 'lds', 'into', 'arpl', 'bound', 'aaa', 'aas',
       'aam', 'aad', 'daa', 'das', 'salc', 'int1', 'int3', 'iretd', 'retf', 'sti', 'cli', 'lock', 'wait', 'fwait',
       'sahf', 'lahf', 'cmc', 'std', 'xlatb'}
FILL = (0x90, 0xCC)
TLO, THI = tbase, tbase + tsize


def terminator(o):
    """kind of flow terminator ending exactly at text offset o (exclusive), or None"""
    if o >= 1 and T[o - 1] == 0xC3:
        return 'ret'
    if o >= 3 and T[o - 3] == 0xC2 and T[o - 1] == 0 and T[o - 2] % 4 == 0:
        return 'retn'
    if o >= 5 and T[o - 5] == 0xE9 and TLO <= tbase + o + struct.unpack_from('<i', T, o - 4)[0] < THI:
        return 'jmp'
    if o >= 2 and T[o - 2] == 0xEB:
        return 'jmp_short'
    if (o >= 6 and T[o - 6] == 0xFF and T[o - 5] == 0x25) or (o >= 7 and T[o - 7] == 0xFF and T[o - 6] == 0x24) \
            or (o >= 2 and T[o - 2] == 0xFF and 0xE0 <= T[o - 1] <= 0xE7):
        return 'jmp_indirect'   # jmp [mem32] / jmp [table+reg*4] / jmp reg
    return None


def sane(o):
    """first instructions look like ordinary code; returns (ok, text of the first instructions)"""
    b = T[o:o + 32]
    if b[0] in FILL or b[:2] == b'\0\0':
        return False, 'fill/zero'
    if TLO <= struct.unpack_from('<I', b, 0)[0] < THI + 0x200000:
        return False, 'pointer'
    if MD is None:
        return True, ''
    ins = []
    n = 0
    for i in MD.disasm(b, tbase + o):
        if i.mnemonic in BAD or i.mnemonic.startswith('rep') and i.mnemonic not in ('rep movsd', 'rep movsb', 'rep stosd', 'rep stosb', 'repne scasb', 'repe cmpsb', 'repe cmpsd'):
            return False, i.mnemonic
        ins.append('%s %s' % (i.mnemonic, i.op_str))
        n += i.size
        if i.mnemonic in ('ret', 'jmp') or len(ins) >= 3:
            break
    if not ins or (len(ins) < 3 and ins[-1].split()[0] not in ('ret', 'jmp')):
        return False, 'decode'
    return True, '; '.join(ins)


out, rej = [], {}
for o in range(0, tsize):
    a = trva + o
    aligned = a % 16 == 0
    if not aligned and a not in ends:
        continue
    if a in known or a in claimed or inside[o] or T[o] in FILL:
        continue
    why = []
    if aligned:
        p = o
        while p > 0 and o - p < 16 and T[p - 1] in FILL:
            p -= 1
        if 1 <= o - p <= 15:
            t = terminator(p)
            if t:
                why.append('pad_after_' + t)
    if a in ends:
        why.append('after_claimed_end')
    if not why:
        continue
    ok, dis = sane(o)
    if not ok:
        rej[dis] = rej.get(dis, 0) + 1
        continue
    e = dict(rva=hex(a), reason='+'.join(why), first=dis)
    if any(lo < a < hi for lo, hi in franges):
        e['inside_fmap_range'] = True   # Ghidra put this address inside another function's range: check by hand
    out.append(e)

json.dump(dict(schema='level2_extra_starts_v1', binary_sha256=lc.SHA, size_report=os.path.basename(best or ''),
               decoder='capstone' if MD else 'simple', count=len(out), rejected=rej, starts=out),
          open(OUT, 'w'), indent=0)
by = {}
for x in out:
    by[x['reason']] = by.get(x['reason'], 0) + 1
print('extra starts', len(out), by, 'rejected', rej)
