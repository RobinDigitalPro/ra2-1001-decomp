"""Library-code identification for the level-2 tail of GAME.EXE 1.001: place whole COFF code sections of the VC6
static libraries (LIBCMT, LIBCPMT, COMSUPP by default) in the CRT tail, including the small ones our 16-byte
crt_calibrate.py threshold skips, and classify what is left (padding, import thunks, unmatched).  Read-only.

usage: python -I level2_libident.py [--out FILE] [--start 0xRVA] [--end 0xRVA] [--lib NAME.LIB ...] [--full-text]
  --out        result JSON (default W/analysis/level2/agents/t2_tools/libident.json)
  --start/end  tail RVA range (default: end of the first run of >= 100 import thunks .. end of .text)
  --lib        library basenames under W/tools/portable/vc6/VC98/LIB (repeatable)
  --full-text  search the whole .text instead of the tail (slow, more ambiguity)

Method (ported from gibbo101/ra2-decomp tools/exelink/crt_ident.py @bd6bc66711, itself from gagarin, MIT):
every code section of every archive member is compared with the image with its relocated fields wildcarded.
A section with one possible position is placed; sections with several are resolved by contiguity with placed
sections of the same member, then by preferring members that already have a placement, and last by member
section order for identical siblings ("inferred_by_order").  Added here from libmatch.py @bd6bc66711: a DIR32
field that names an __imp__X import must hold the IAT slot the exe imports X through.

The output lists, per placed section, how it relates to P/metadata/level2_library.json: "known" (inside an
existing entry), "new" (no overlap) or "conflict" (partial overlap).  It is CANDIDATE evidence only: nothing
here edits metadata, and relocation targets are not bound to symbols (same limit as level2_library.json).

Credit: algorithm from gibbo101/ra2-decomp (https://github.com/gibbo101/ra2-decomp, tools/ MIT licence, ported
from https://github.com/r-melvin/gagarin); this adaptation is part of the GPL-3.0-or-later level-2 tree.
"""
import json, os, re, struct, sys
W = r'D:\<work-root>\RedAlert2Temp'
P = r'D:\<project-folder>\Coding\RedAlert2'
sys.path.insert(0, os.path.join(W, 'tools')); sys.path.insert(0, os.path.join(W, 'analysis', 'level2'))
import level2_check as lc  # noqa: E402
from coffmatch import Obj  # noqa: E402

LIBDIR = os.path.join(W, 'tools', 'portable', 'vc6', 'VC98', 'LIB')
DEFAULT_LIBS = ['LIBCMT.LIB', 'LIBCPMT.LIB', 'COMSUPP.LIB']
SCN_CODE, SCN_COMDAT = 0x20, 0x1000
RELOC_SIZES = {0x06: 4, 0x07: 4, 0x14: 4, 0x0A: 2, 0x0B: 4, 0x09: 2}


def archive_members(path):
    data = open(path, 'rb').read()
    if not data.startswith(b'!<arch>\n'):
        raise ValueError(path + ' is not a COFF archive')
    pos, longnames, out = 8, b'', []
    while pos + 60 <= len(data):
        name = data[pos:pos + 16].decode('latin-1').rstrip()
        size = int(data[pos + 48:pos + 58])
        body = data[pos + 60:pos + 60 + size]
        pos += 60 + size + (size & 1)
        if name == '//':
            longnames = body
        elif name in ('/', ''):
            continue
        else:
            if name.startswith('/') and name[1:].isdigit():
                at = int(name[1:])
                end = longnames.find(b'\0', at)
                name = longnames[at:end if end >= 0 else longnames.index(b'\n', at)].decode('latin-1')
            out.append((name.rstrip('/'), body))
    return out


def code_sections(raw):
    if len(raw) < 20 or struct.unpack_from('<H', raw, 0)[0] != 0x14C:
        return []
    try:
        obj = Obj(raw)
    except Exception:
        return []
    syms = {}
    for s in obj.by_index.values():
        if s['section'] > 0 and s['storage'] in (2, 3) and not s['name'].startswith('.'):
            syms.setdefault(s['section'], []).append((s['name'], s['value'], s['storage'] == 2))
    out = []
    for i, sec in enumerate(obj.sections):
        flags = sec['chars']
        if not flags & SCN_CODE or sec['size'] == 0:
            continue
        data = sec['raw']
        mask = bytearray(len(data))
        imports = []
        for roff, symidx, rtype in sec['relocs']:
            for k in range(RELOC_SIZES.get(rtype, 0)):
                if roff + k < len(data):
                    mask[roff + k] = 1
            name = obj.by_index[symidx]['name']
            if rtype == 0x06 and name.startswith('__imp__'):
                imports.append((roff, name[7:].split('@', 1)[0], struct.unpack_from('<i', data, roff)[0]))
        align = 1 << (((flags >> 20) & 0xF) - 1) if (flags >> 20) & 0xF else 16
        out.append({'index': i + 1, 'size': len(data), 'align': align, 'data': data, 'mask': bytes(mask),
                    'comdat': bool(flags & SCN_COMDAT), 'symbols': syms.get(i + 1, []), 'imports': imports})
    return out


def runs(sec):
    data, mask, out, i = sec['data'], sec['mask'], [], 0
    while i < len(data):
        if mask[i]:
            i += 1
            continue
        j = i
        while j < len(data) and not mask[j]:
            j += 1
        out.append((i, data[i:j]))
        i = j
    return out


def matches_at(sec, tail, pos):
    if pos < 0 or pos + sec['size'] > len(tail):
        return False
    return all(tail[pos + o:pos + o + len(b)] == b for o, b in sec['runs'])


def candidates(sec, tail, base, iat):
    if not sec['runs']:
        return []
    off, run = max(sec['runs'], key=lambda r: len(r[1]))
    probe = run[:16]
    found, at = [], tail.find(probe)
    while at >= 0:
        pos = at - off
        if matches_at(sec, tail, pos) and all(
                iat.get((struct.unpack_from('<I', tail, pos + o)[0] - add) & 0xFFFFFFFF, (None, None))[1] == name
                for o, name, add in sec['imports']):
            found.append(pos)
        at = tail.find(probe, at + 1)
    return found


def align_up(value, align):
    return (value + align - 1) // align * align


def identify(sections, tail):
    """Verbatim algorithm of crt_ident.identify (gibbo101 @bd6bc66711)."""
    placed, taken = {}, []
    alive = {s['id']: set(s['cands']) for s in sections if s['cands']}
    by_id = {s['id']: s for s in sections}
    member_placed, inferred = set(), set()

    def overlaps(a, b):
        return any(a < e and s < b for s, e in taken)

    def place(sid, pos):
        s = by_id[sid]
        placed[sid] = pos
        taken.append((pos, pos + s['size'])); taken.sort()
        member_placed.add(s['member_key'])
        del alive[sid]
        for other, cs in list(alive.items()):
            o = by_id[other]
            cs.difference_update([c for c in cs if c < pos + s['size'] and pos < c + o['size']])
            if not cs:
                del alive[other]

    progress = True
    while progress:
        progress = False
        claims = {}
        for sid, cs in alive.items():
            for c in cs:
                claims.setdefault((c, by_id[sid]['size']), []).append(sid)
        for sid in sorted(alive, key=lambda i: len(alive[i])):
            if sid not in alive or len(alive[sid]) != 1:
                continue
            (c,) = alive[sid]
            rivals = [r for r in claims.get((c, by_id[sid]['size']), []) if r != sid and r in alive]
            if not rivals:
                place(sid, c); progress = True
        if progress:
            continue
        ends, starts = {}, {}
        for pid, ppos in placed.items():
            ends.setdefault(ppos + by_id[pid]['size'], set()).add(by_id[pid]['member_key'])
            starts.setdefault(ppos, set()).add(by_id[pid]['member_key'])

        def adjacent(sid, c):
            s = by_id[sid]; keys = set()
            for e, ks in ends.items():
                if align_up(e, s['align']) == c:
                    keys |= ks
            for st, ks in starts.items():
                if c + s['size'] <= st <= align_up(c + s['size'], 16):
                    keys |= ks
            return keys

        for sid in sorted(alive):
            if sid not in alive:
                continue
            s = by_id[sid]
            adj = {c: adjacent(sid, c) for c in alive[sid]}
            same = [c for c, ks in adj.items() if s['member_key'] in ks]
            near = same if len(same) == 1 else [c for c, ks in adj.items() if ks] if not same else []
            if len(near) == 1:
                rivals = [r for r in claims.get((near[0], s['size']), []) if r != sid and r in alive
                          and by_id[r]['member_key'] in member_placed]
                if s['member_key'] in member_placed or not rivals:
                    place(sid, near[0]); progress = True
        if progress:
            continue
        for (c, size), sids in sorted(claims.items()):
            live = [x for x in sids if x in alive and c in alive[x]]
            known = [x for x in live if by_id[x]['member_key'] in member_placed]
            if len(live) > 1 and len(known) == 1 and not overlaps(c, c + size):
                place(known[0], c); progress = True
                break
        if progress:
            continue
        groups = {}
        for sid, cs in alive.items():
            groups.setdefault((by_id[sid]['member_key'], by_id[sid]['size'], tuple(sorted(cs))), []).append(sid)
        for (_, _, cs), sids in sorted(groups.items()):
            if len(sids) == len(cs) > 1 and by_id[sids[0]]['member_key'] in member_placed:
                for sid, c in zip(sorted(sids, key=lambda i: by_id[i]['order']), cs):
                    if sid in alive and c in alive[sid]:
                        place(sid, c); inferred.add(sid)
                progress = True
                break
    return placed, alive, inferred


def split_gap(tail, a, b):
    out, i = [], a
    thunks = re.compile(rb'(?:\xff\x25[\x00-\xff]{4}){2,}')
    thunk2 = re.compile(rb'\xff\x25[\x00-\xff]{4}\xff\x25')
    while i < b:
        j = i
        if tail[i] == 0xCC or tail[i] == 0x90 and (i + 1 == b or tail[i + 1] in (0x90, 0xCC)):
            while j < b and tail[j] in (0xCC, 0x90):
                j += 1
            kind = 'padding'
        else:
            m = thunks.match(tail, i, b)
            if m:
                j, kind = m.end(), 'import_thunks'
            else:
                j = i + 1
                while j < b and tail[j] != 0xCC and not thunk2.match(tail, j, b):
                    j += 1
                kind = 'unmatched'
        if out and out[-1][0] == kind and out[-1][2] == i:
            out[-1] = (kind, out[-1][1], j)
        else:
            out.append((kind, i, j))
        i = j
    return out


def main():
    a = sys.argv[1:]
    def opt(name, default=None):
        if name in a:
            k = a.index(name); v = a[k + 1]; del a[k:k + 2]; return v
        return default
    out = opt('--out', os.path.join(W, 'analysis', 'level2', 'agents', 't2_tools', 'libident.json'))
    libs = []
    while '--lib' in a:
        libs.append(opt('--lib'))
    libs = libs or DEFAULT_LIBS
    start, end = opt('--start'), opt('--end')
    full = '--full-text' in a
    B, secs = lc.image()
    t = next(s for s in secs if s[0] == '.text')
    T = B[t[4]:t[4] + min(t[2], t[3])]
    if full:
        s0 = t[1]
    elif start:
        s0 = int(start, 16)
    else:
        m = re.search(rb'(?:\xff\x25[\x00-\xff]{4}){100,}', T)
        s0 = t[1] + m.end()
    e0 = int(end, 16) if end else t[1] + len(T)
    tail = T[s0 - t[1]:e0 - t[1]]
    iat = lc.import_map(B, secs)
    base_va = 0x400000 + s0
    sections = []
    for lib in libs:
        for mi, (member, raw) in enumerate(archive_members(os.path.join(LIBDIR, lib))):
            for sec in code_sections(raw):
                sec['runs'] = runs(sec)
                sec['library'], sec['member'], sec['member_key'] = lib, member, (lib, mi)
                sec['id'] = len(sections); sec['order'] = (libs.index(lib), mi, sec['index'])
                sections.append(sec)
    for s in sections:
        s['cands'] = candidates(s, tail, base_va, iat)
    placed, alive, inferred = identify(sections, tail)
    known = sorted((int(f['rva'], 16), int(f['rva'], 16) + f['size'], f['symbols'][0] if f.get('symbols') else '')
                   for f in json.load(open(os.path.join(P, 'metadata', 'level2_library.json')))['functions'])
    records, covered = [], []
    for sid, pos in placed.items():
        s = sections[sid]
        ext = [(n, v) for n, v, e in s['symbols'] if e] or [(n, v) for n, v, e in s['symbols']]
        lo, hi = s0 + pos, s0 + pos + s['size']
        ov = [k for k in known if k[0] < hi and lo < k[1]]
        rel = 'new' if not ov else 'known' if all(k[0] <= lo and hi <= k[1] or lo <= k[0] and k[1] <= hi for k in ov) else 'conflict'
        records.append({'rva': hex(lo), 'size': s['size'], 'library': s['library'], 'member': s['member'],
                        'section': s['index'], 'comdat': s['comdat'],
                        'symbols': [{'name': n, 'rva': hex(lo + v)} for n, v in ext],
                        'inferred_by_order': sid in inferred, 'masked_bytes': sum(s['mask']),
                        'vs_level2_library': rel, 'overlapping_known': [hex(k[0]) for k in ov]})
        covered.append((pos, pos + s['size']))
    records.sort(key=lambda r: int(r['rva'], 16))
    covered.sort()
    gaps, cursor = [], 0
    for x, y in covered:
        if x > cursor:
            gaps.append((cursor, x))
        cursor = max(cursor, y)
    if cursor < len(tail):
        gaps.append((cursor, len(tail)))
    gap_records = [{'rva': hex(s0 + x), 'len': y - x, 'kind': k} for g in gaps for k, x, y in split_gap(tail, *g)]
    groups = {}
    for sid, cs in alive.items():
        s = sections[sid]
        groups.setdefault((tuple(sorted(cs)), s['size']), []).append('%s:%s:%s' % (s['library'], s['member'], s['symbols'][0][0] if s['symbols'] else s['index']))
    ambiguous = [{'rvas': [hex(s0 + c) for c in cs], 'len': n, 'sections': sorted(m)} for (cs, n), m in sorted(groups.items())]
    new = [r for r in records if r['vs_level2_library'] == 'new']
    known_bytes = sum(k[1] - k[0] for k in known if s0 <= k[0] < e0)
    stats = {'tail_rva': [hex(s0), hex(e0)], 'tail_len': len(tail), 'libraries': libs,
             'sections_total': len(sections), 'sections_placed': len(placed), 'sections_inferred_by_order': len(inferred),
             'bytes_placed': sum(y - x for x, y in covered),
             'placed_known': sum(r['vs_level2_library'] == 'known' for r in records),
             'placed_new': len(new), 'placed_new_bytes': sum(r['size'] for r in new),
             'placed_new_excluding_inferred': sum(1 for r in new if not r['inferred_by_order']),
             'placed_conflict': sum(r['vs_level2_library'] == 'conflict' for r in records),
             'level2_library_bytes_in_range': known_bytes,
             'gap_bytes': {k: sum(g['len'] for g in gap_records if g['kind'] == k) for k in ('padding', 'import_thunks', 'unmatched')}}
    os.makedirs(os.path.dirname(out), exist_ok=True)
    json.dump({'schema': 'level2_libident_v1', 'binary_sha256': lc.SHA, 'evidence_level': 'candidate (masked bytes + IAT names; relocation targets not bound)',
               'stats': stats, 'sections': records, 'gaps': gap_records, 'ambiguous': ambiguous}, open(out, 'w'), indent=1)
    print(json.dumps(stats, indent=1))
    print('->', out)


if __name__ == '__main__':
    main()
