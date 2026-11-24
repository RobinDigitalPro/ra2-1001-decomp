"""Level-2 check: compile src/ra2 translation units with VC6 and verify claimed byte matches.

Inputs (canonical):  P/metadata/level2_functions.json, P/metadata/level2_symbols.json, P/src/ra2/*.
Outputs (generated): W/build/level2/*.obj and W/analysis/level2/reports/check_<utc>.json.
Read-only on GAME.EXE.  A function is 'matched' only when every byte outside relocations is equal
and every relocation is bound to an address with verified evidence.  This never edits metadata.
"""
import hashlib, json, os, re, struct, subprocess, sys, time
P = r'D:\<project-folder>\Coding\RedAlert2'
W = r'D:\<work-root>\RedAlert2Temp'
sys.path.insert(0, os.path.join(W, 'analysis', 'level2'))
from coffmatch import Obj, match_function  # noqa: E402

VC6 = os.path.join(W, 'tools', 'portable', 'vc6')
FLAGS = ['-nologo', '-c', '-O2', '-Ob2', '-Gr', '-GR', '-DNDEBUG', '-Gy']
SHA = '7fe00ee313b38b22e68d6c05aede041018206e29b71f5db9cc1afacc61588c6e'
FUNCS = os.path.join(W, 'analysis', 'functions_%s.jsonl' % SHA)
RTTI = os.path.join(W, 'analysis', 'level2', 'rtti_catalog.json')
ORD = json.load(open(os.path.join(W, 'analysis', 'level2', 'import_ordinals.json')))['tables']
CRT = os.path.join(W, 'analysis', 'level2', 'crt_calibration.json')


def image():
    B = open(os.path.join(P, 'RA2Original', 'GAME.EXE'), 'rb').read()
    if hashlib.sha256(B).hexdigest() != SHA:
        raise SystemExit('GAME.EXE identity mismatch')
    pe = struct.unpack_from('<I', B, 0x3c)[0]; n = struct.unpack_from('<H', B, pe + 6)[0]; so = struct.unpack_from('<H', B, pe + 20)[0]
    secs = []
    for i in range(n):
        o = pe + 24 + so + 40 * i
        name = B[o:o + 8].rstrip(b'\0').decode()
        vs, va, rs, ra = struct.unpack_from('<IIII', B, o + 8)
        secs.append((name, va, vs, rs, ra))
    return B, secs


def _mapped(vs, rs):
    """Mapped extent of a section: the loader maps max(VirtualSize, RawSize) rounded up to the 4 KB page and zero-fills the slack
    (2026-11-21: the repack no-CD patch keeps a variable at 0xb11ee0 in the .data page slack)."""
    return (max(vs, rs) + 0xfff) & ~0xfff


def read(B, secs, va, size):
    rva = va - 0x400000
    for name, sva, vs, rs, ra in secs:
        if sva <= rva < sva + _mapped(vs, rs):
            raw = B[ra + rva - sva: ra + min(rva - sva + size, rs)]
            return raw + b'\0' * (size - len(raw))  # bss tail reads as zero
    return None


def section_of(secs, va):
    rva = va - 0x400000
    for name, sva, vs, rs, ra in secs:
        if sva <= rva < sva + _mapped(vs, rs):
            return name


def import_map(B, secs):
    pe = struct.unpack_from('<I', B, 0x3c)[0]
    imp = struct.unpack_from('<I', B, pe + 24 + 96 + 8)[0]
    def off(rva):
        for name, sva, vs, rs, ra in secs:
            if sva <= rva < sva + rs:
                return ra + rva - sva
    out = {}
    o = off(imp)
    while True:
        ilt, ts, fc, name, iat = struct.unpack_from('<IIIII', B, o)
        if name == 0:
            break
        dll = B[off(name):B.index(b'\0', off(name))].decode()
        k = 0
        while True:
            e = struct.unpack_from('<I', B, off(ilt or iat) + 4 * k)[0]
            if e == 0:
                break
            fn = ('#%d' % (e & 0xffff)) if e & 0x80000000 else B[off(e) + 2:B.index(b'\0', off(e) + 2)].decode()
            out[0x400000 + iat + 4 * k] = (dll, fn)
            k += 1
        o += 20
    return out


UASM = os.path.join(W, 'tools', 'portable', 'uasm-2.57r', 'uasm64.exe')   # MASM-compatible (user-approved 2026-11-19)
UASM_FLAGS = ['-q', '-coff', '-Zg', '-X']


def split_asm_procs(data):
    """.asm TUs only: rewrite an assembler COFF object so that every PROC (function symbol) starts its own section,
    as CL /Gy does for C++, because match_function compares whole sections.  The code bytes are unchanged and
    relocations move with their PROC.  A relocation against the split code section's own section symbol is
    retargeted to the PROC that starts at its target, or else to a '$LA<n>' label (storage class 6) at the target
    inside the PROC that contains it (verified like a jump-table label only within the same PROC).  File-local
    (static) non-PROC labels in a split code section likewise become labels (storage class 6) of their PROC."""
    machine, nsec, ts, symptr, nsym, optsz, fchars = struct.unpack_from('<HHIIIHH', data, 0)
    strtab = data[symptr + 18 * nsym:]
    secs = []
    for i in range(nsec):
        o = 20 + optsz + 40 * i
        size, ptr, relptr, _, nrel, _, chars = struct.unpack_from('<IIIIHHI', data, o + 16)
        hdr = bytearray(data[o:o + 40])
        if hdr[0] == ord('/'):   # long name '/<offset>': UASM leaves stale bytes after the NUL; clear them
            hdr[0:8] = hdr[0:hdr.index(0, 0, 8) if 0 in hdr[0:8] else 8].ljust(8, b'\0')
        secs.append(dict(hdr=hdr, size=size, raw=bytearray(data[ptr:ptr + size]) if ptr else None,
                         rels=[list(struct.unpack_from('<IIH', data, relptr + 10 * k)) for k in range(nrel)], chars=chars))
    syms = []   # [record, [aux records], original index]
    i = 0
    while i < nsym:
        o = symptr + 18 * i
        syms.append([bytearray(data[o:o + 18]), [bytearray(data[o + 18 * (k + 1):o + 18 * (k + 2)]) for k in range(data[o + 17])], i])
        i += 1 + data[o + 17]

    def fields(rec):
        return struct.unpack_from('<IhHBB', rec, 8)   # value, section, type, storage class, aux count

    bounds = {}   # code section -> PROC start offsets
    for rec, aux, _ in syms:
        value, sec, typ, cls, _ = fields(rec)
        if sec > 0 and cls in (2, 3) and (typ >> 4) == 2 and secs[sec - 1]['chars'] & 0x20:
            bounds.setdefault(sec, {0}).add(value)
    newsecs, chunks = [], {}   # old section -> [(start, end, new section number)]
    for k, s in enumerate(secs, 1):
        if k not in bounds:
            newsecs.append(s); chunks[k] = [(0, s['size'], len(newsecs))]; continue
        b = sorted(bounds[k]) + [s['size']]
        chunks[k] = []
        for a, e in zip(b, b[1:]):
            if e > a:
                newsecs.append(dict(hdr=bytearray(s['hdr']), size=e - a, raw=bytearray(s['raw'][a:e]), chars=s['chars'],
                                    rels=[[r[0] - a, r[1], r[2]] for r in s['rels'] if a <= r[0] < e]))
                chunks[k].append((a, e, len(newsecs)))

    def locate(sec, value):
        for a, e, n in chunks[sec]:
            if a <= value < e:
                return n, value - a
        a, e, n = chunks[sec][-1]
        return n, value - a

    secsym = {}   # split old section -> original index of its section symbol
    for rec, aux, oi in syms:
        value, sec, typ, cls, _ = fields(rec)
        if sec > 0:
            if cls == 3 and value == 0 and not (typ >> 4) and sec in bounds and aux and sec not in secsym:
                secsym[sec] = oi; n = chunks[sec][0][2]
            else:
                n, value = locate(sec, value)
                if cls == 3 and not aux and (typ >> 4) != 2 and sec in bounds:
                    rec[16] = 6   # a file-local code label (e.g. a table after its PROC) becomes a label of its PROC
            struct.pack_into('<Ih', rec, 8, value, n)
    total = sum(1 + len(s[1]) for s in syms)
    extra = []
    for sec in bounds:
        for a, e, n in chunks[sec][1:]:
            rec = bytearray(next(s[0] for s in syms if s[2] == secsym[sec])) if sec in secsym else bytearray(b'.text\0\0\0' + bytes(10))
            struct.pack_into('<IhHBB', rec, 8, 0, n, 0, 3, 1)
            extra.append([rec, [bytearray(18)]])
    t = total + 2 * len(extra)
    funcs_at = {}
    for rec, aux, oi in syms:
        value, sec, typ, cls, _ = fields(rec)
        if sec > 0 and (typ >> 4) == 2 and value == 0:
            funcs_at.setdefault(sec, oi)
    labels = []
    for c in newsecs:
        for r in c['rels']:
            old = next((s for s, oi in secsym.items() if oi == r[1]), None)
            if old is None:
                continue
            rel32 = r[2] == 0x14
            target = struct.unpack_from('<i', c['raw'], r[0])[0] + (4 if rel32 else 0)
            m, off = locate(old, target)
            if off == 0 and m in funcs_at:
                r[1] = funcs_at[m]
            else:
                lab = bytearray(18); lab[0:8] = ('$LA%x' % len(labels)).encode().ljust(8, b'\0')
                struct.pack_into('<IhHBB', lab, 8, off, m, 0, 6, 0)
                r[1] = t; t += 1; labels.append([lab, []])
            struct.pack_into('<i', c['raw'], r[0], -4 if rel32 else 0)
    allsyms = [(s[0], s[1]) for s in syms] + [tuple(x) for x in extra] + [tuple(x) for x in labels]
    for rec, aux in allsyms:
        value, sec, typ, cls, na = fields(rec)
        if cls == 3 and value == 0 and aux and sec > 0 and not (typ >> 4):
            struct.pack_into('<IHH', aux[0], 0, newsecs[sec - 1]['size'], len(newsecs[sec - 1]['rels']), 0)
    head = bytearray(struct.pack('<HHIIIHH', machine, len(newsecs), ts, 0, 0, 0, fchars))
    pos = 20 + 40 * len(newsecs)
    body = bytearray()
    for c in newsecs:
        rawptr = pos + len(body) if c['raw'] is not None and c['size'] else 0
        if c['raw'] is not None:
            body += c['raw']
        relptr = pos + len(body) if c['rels'] else 0
        for r in c['rels']:
            body += struct.pack('<IIH', r[0], r[1], r[2])
        struct.pack_into('<IIIIHH', c['hdr'], 16, c['size'], rawptr, relptr, 0, len(c['rels']), 0)
        head += c['hdr']
    out = head + body
    symoff = len(out)
    for rec, aux in allsyms:
        out += rec + b''.join(aux)
    struct.pack_into('<II', out, 8, symoff, sum(1 + len(a) for _, a in allsyms))
    return bytes(out + strtab)


def compile_tu(tu, outdir):
    if tu.endswith('.asm'):   # hand-written assembly (MASM 6.13 objects in GAME.EXE), assembled with UASM
        base = os.path.splitext(os.path.basename(tu))[0]
        obj, raw = os.path.join(outdir, 'asm_' + base + '.obj'), os.path.join(outdir, 'asm_' + base + '.uasm.obj')
        for x in (obj, raw):
            if os.path.exists(x):
                os.remove(x)
        cmd = [UASM] + UASM_FLAGS + ['-I' + os.path.dirname(os.path.join(P, tu)), '-Fo' + raw, os.path.join(P, tu)]
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=300)
        rc = r.returncode
        if rc == 0 and os.path.exists(raw):
            open(obj, 'wb').write(split_asm_procs(open(raw, 'rb').read()))
        else:
            rc = rc or 1
        return obj, dict(command=' '.join(cmd[1:]) + ' (then one section per PROC)', returncode=rc, output=(r.stdout + r.stderr)[-4000:])
    env = dict(os.environ)
    env['PATH'] = os.pathsep.join([os.path.join(VC6, 'VC98', 'BIN'), os.path.join(VC6, 'COMMON', 'MSDEV98', 'BIN'), env['PATH']])
    env['INCLUDE'] = os.path.join(VC6, 'VC98', 'INCLUDE') + os.pathsep + os.path.join(VC6, 'VC98', 'ATL', 'INCLUDE')
    env['LIB'] = os.path.join(VC6, 'VC98', 'LIB')
    if tu.startswith('src/m85/'):   # adopted upstream tree (mischa85 RA2 1.006, GPL-3.0-or-later)
        obj = os.path.join(outdir, 'm85_' + os.path.splitext(os.path.basename(tu))[0] + '.obj')
        inc = ['-DWIN32', '-W0', '-I' + os.path.join(P, 'src', 'm85', 'src'), '-I' + os.path.join(P, 'src', 'm85', 'include')]
    else:
        obj = os.path.join(outdir, os.path.splitext(os.path.basename(tu))[0] + '.obj')
        inc = ['-I' + os.path.join(P, 'src', 'ra2')]
    if os.path.exists(obj):
        os.remove(obj)
    cmd = [os.path.join(VC6, 'VC98', 'BIN', 'CL.EXE')] + FLAGS + inc + ['-Fo' + obj, os.path.join(P, tu)]
    r = subprocess.run(cmd, env=env, capture_output=True, text=True, timeout=300)
    return obj, dict(command=' '.join(cmd[1:]), returncode=r.returncode, output=(r.stdout + r.stderr)[-4000:])


_LIBORD = {}


def lib_import_ordinal(dll, impsym):
    """Ordinal by which the VC6 import library of `dll` imports `impsym` (for example COMCTL32.LIB imports
    __imp__InitCommonControls@0 by ordinal 17), or None.  Only the library named after the DLL is read, and the
    member must define exactly this __imp_ symbol for this DLL's import descriptor."""
    key = (dll.upper(), impsym)
    if key in _LIBORD:
        return _LIBORD[key]
    base = os.path.splitext(dll)[0].upper()
    path = os.path.join(VC6, 'VC98', 'LIB', base + '.LIB')
    res = None
    if os.path.exists(path):
        A = open(path, 'rb').read()
        pos = 8
        while pos + 60 <= len(A) and res is None:
            size = int(A[pos + 48:pos + 58]); body = A[pos + 60:pos + 60 + size]
            if body[:4] == b'\0\0\xff\xff':          # short import format
                ordhint, typ = struct.unpack_from('<HH', body, 16)
                nm = body[20:body.index(b'\0', 20)].decode('latin-1')
                dl = body[21 + len(nm):body.index(b'\0', 21 + len(nm))].decode('latin-1')
                if '__imp_' + nm == impsym and dl.upper() == dll.upper() and (typ >> 2) & 7 == 0:
                    res = ordhint
            elif body[:2] == b'\x4c\x01' and impsym.encode() + b'\0' in body:   # long format (.idata$5 entry)
                o = Obj(body)
                names = {x['name'].upper() for x in o.by_index.values()}
                s = next((x for x in o.by_index.values() if x['name'] == impsym and x['section'] > 0), None)
                if s is not None and '__IMPORT_DESCRIPTOR_' + base in names:
                    raw = o.sections[s['section'] - 1]['raw'][s['value']:s['value'] + 4]
                    v = int.from_bytes(raw, 'little')
                    if len(raw) == 4 and v & 0x80000000:
                        res = v & 0xffff
            pos += 60 + size + (size & 1)
    _LIBORD[key] = res
    return res


_CLASSKEY = re.compile(r'(?:(?<=[@$])|(?<=PA)|(?<=PB)|(?<=QA)|(?<=QB)|(?<=AA)|(?<=AB))[UV](?=[A-Za-z_?])')


def vtable_entry(catalog, symbol):
    """(RTTI class entry, subobject offset) that a ??_7 vtable symbol names, or (None, None)."""
    if symbol.startswith('??_7?$') and symbol.endswith('@6B@'):
        part = symbol[4:-3]
        entry = next((c for c in catalog['classes'] if c['type'] in ('.?AV' + part, '.?AU' + part)), None)
        if entry is None:
            # class-key spelling only (struct vs class, mangled U vs V) of a template argument: the same C++ type.
            # Accept only a single RTTI class whose name equals ours up to those class-key letters.
            want = _CLASSKEY.sub('#', '.?AV' + part)
            cand = [c for c in catalog['classes'] if c['type'].startswith(('.?AV?$', '.?AU?$')) and _CLASSKEY.sub('#', '.?AV' + c['type'][4:]) == want]
            entry = cand[0] if len(cand) == 1 else None
        return (entry, 0) if entry else (None, None)
    m = re.match(r'\?\?_7(\w+(?:@\w+)*)@@6B(?:(\w+(?:@\w+)*)@@)?@$', symbol)   # nested class names: A@B@C
    if not m:
        return None, None
    cls, base = m.group(1), m.group(2)
    entry = next((c for c in catalog['classes'] if c['type'] in ('.?AV%s@@' % cls, '.?AU%s@@' % cls)), None)
    if not entry:
        return None, None
    offset = 0
    if base:
        b = next((b for b in entry['hierarchy']['bases'][1:] if b['type'] in ('.?AV%s@@' % base, '.?AU%s@@' % base)), None)
        if b is None:
            return None, None
        offset = b['mdisp']
    return entry, offset


def vtable_address(catalog, symbol):
    entry, offset = vtable_entry(catalog, symbol)
    if entry is None:
        return None
    v = next((v for v in entry['vtables'] if v['subobject_offset'] == offset), None)
    return int(v['vtable'], 16) if v else None


def comdat_any_sections(obj):
    """Section numbers that are COMDATs with selection ANY (2): inline, template and compiler-generated code,
    which every TU emits for itself.  Ordinary -Gy functions are NODUPLICATES (1)."""
    data = obj.data
    _, nsec, _, symptr, nsym, _, _ = struct.unpack_from('<HHIIIHH', data, 0)
    out = set()
    i = 0
    while i < nsym:
        o = symptr + 18 * i
        value, secnum, typ, cls, aux = struct.unpack_from('<IhHBB', data, o + 8)
        if cls == 3 and value == 0 and aux >= 1 and secnum > 0 and obj.sections[secnum - 1]['chars'] & 0x1000:
            sel = data[o + 18 + 14]
            if sel == 2:
                out.add(secnum)
        i += 1 + aux
    return out


def main():
    B, secs = image()
    funcs = json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))
    allfuncs = funcs
    only = sys.argv[1:]
    if only:
        funcs = [f for f in funcs if any(o in f['tu'] for o in only)]
    symmap = json.load(open(os.path.join(P, 'metadata', 'level2_symbols.json'), encoding='utf-8'))
    catalog = json.load(open(RTTI))
    starts = {int(json.loads(l)['rva'], 16) + 0x400000 for l in open(FUNCS)}
    mapstarts = {int(f['rva'], 16) + 0x400000 for f in json.load(open(os.path.join(W, 'analysis', 'level2', 'function_map.json')))['map']}
    crt = {(r['symbol'], int(r['rva'], 16) + 0x400000) for r in json.load(open(CRT))['results']}
    imports = import_map(B, secs)
    outdir = os.path.join(W, 'build', 'level2'); os.makedirs(outdir, exist_ok=True)
    report = dict(schema='level2_check_v1', utc=time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime()), binary_sha256=SHA,
                  compiler=dict(flags=' '.join(FLAGS)), units={}, functions=[], symbol_conflicts=[])
    objs = {}
    for tu in sorted({f['tu'] for f in funcs}):
        obj, info = compile_tu(tu, outdir)
        info['source_sha256'] = hashlib.sha256(open(os.path.join(P, tu), 'rb').read()).hexdigest()
        if info['returncode'] == 0 and os.path.exists(obj):
            data = open(obj, 'rb').read(); info['object_sha256'] = hashlib.sha256(data).hexdigest(); objs[tu] = Obj(data)
        report['units'][tu] = info
    bound = {}
    claimed, claimed_global = {}, {}   # (tu, symbol) -> addresses; symbol -> addresses (all TUs)
    for f in allfuncs:
        claimed.setdefault((f['tu'], f['symbol']), set()).add(int(f['rva'], 16) + 0x400000)
        if not f['symbol'].startswith('_$E'):
            claimed_global.setdefault(f['symbol'], set()).add(int(f['rva'], 16) + 0x400000)
    libsyms = {}    # (symbol, VA) -> 'LIB member' for the VC6 library functions identified in level2_library.json
    for x in json.load(open(os.path.join(P, 'metadata', 'level2_library.json')))['functions']:
        for s in x.get('symbols', []):
            libsyms[(s, int(x['rva'], 16) + 0x400000)] = '%s %s' % (x.get('library', ''), os.path.basename(x.get('member', '').replace('\\', '/')))
    vt_owner = {}   # catalogued vtable address -> {(class type, subobject offset)}
    for c in catalog['classes']:
        for x in c['vtables']:
            vt_owner.setdefault(int(x['vtable'], 16), set()).add((c['type'], x['subobject_offset']))
    any_secs = {}

    def local_copy(obj, symbol):
        # a function this object emits for itself: inline/template/compiler-generated (COMDAT ANY) or static
        x = obj.symbols.get(symbol)
        if x is None:
            return False
        if id(obj) not in any_secs:
            any_secs[id(obj)] = comdat_any_sections(obj)
        return x['storage'] == 3 or x['section'] in any_secs[id(obj)]

    vt_stack = []
    copy_stack = set()

    def verify_copy(obj, symbol, address, tu):
        # bytes of this TU's own copy at the referenced address, and every relocation of it verified in turn
        if (symbol, address) in copy_stack:
            return True, 'recursive reference to %s under verification' % symbol
        if len(copy_stack) > 24 or section_of(secs, address) != '.text':
            return False, 'TU-local copy %s: not verifiable at %s' % (symbol, hex(address))
        hs = obj.function(symbol)['raw']
        hr = match_function(obj, symbol, read(B, secs, address, len(hs)), address, lambda s: None)
        if hr.get('byte_differences') != 0 or hr.get('relocation_problems'):
            return False, 'TU-local copy %s differs at %s' % (symbol, hex(address))
        hsec = obj.symbols[symbol]['section']
        copy_stack.add((symbol, address))
        try:
            for b in hr['unresolved_bindings']:
                a = int(b['required_address'], 16)
                lab = next((x for x in obj.by_index.values() if x['name'] == b['symbol'] and x['storage'] == 6), None)
                if lab is not None and lab['section'] == hsec:
                    ok, why = a == address + lab['value'], 'label'
                else:
                    ok, why = verify(obj, b['symbol'], a, tu)
                if not ok:
                    return False, 'TU-local copy %s at %s: %s not verified (%s)' % (symbol, hex(address), b['symbol'][:50], why)
        finally:
            copy_stack.discard((symbol, address))
        return True, 'TU-local copy %s byte-identical at the referenced address, %d binding(s) verified' % (symbol, len(hr['unresolved_bindings']))

    def check_import(symbol, address):
        want = symbol[7:].split('@')[0]
        got = imports.get(address)
        ok = bool(got) and (got[1] in (want, '_' + symbol[7:]) or ORD.get(got[0].upper(), {}).get(got[1][1:]) == want.lstrip('_')
                            or (got[1].startswith('#') and lib_import_ordinal(got[0], symbol) == int(got[1][1:])))
        return ok, 'import address table entry %s' % (got,)

    def verify(obj, symbol, address, tu=None):
        if symbol.startswith('__imp__'):
            return check_import(symbol, address)
        # 2026-11-22 (SEH in WinMain): three evidence kinds the __try/__except code needs
        if (symbol, address) in libsyms:
            return True, 'VC6 library function %s (%s)' % (symbol, libsyms[(symbol, address)])
        if symbol == '__except_list':   # LIBCMT defines it as the absolute 0: fs:[0], the SEH registration list head
            return address == 0, 'LIBCMT absolute __except_list = 0 (fs:[0])'
        aidx = next((x for x in obj.by_index.values() if x['name'] == symbol and x['section'] == -1), None)   # IMAGE_SYM_ABSOLUTE
        if aidx is not None:
            return (aidx['value'] & 0xffffffff) == address, 'absolute symbol value %s (e.g. __except_list = fs:[0])' % hex(aidx['value'])
        if symbol.startswith('$L') and tu is not None:
            lab = next((x for x in obj.by_index.values() if x['name'] == symbol and x['section'] > 0), None)
            if lab is not None and obj.sections[lab['section'] - 1]['chars'] & 0x20:
                owners = [x['name'] for x in obj.by_index.values() if x['section'] == lab['section'] and x['value'] == 0
                          and x['storage'] == 2 and not x['name'].startswith('$')]
                for fn in owners:
                    if (tu, fn) in claimed and (address - lab['value']) in claimed[(tu, fn)]:
                        return True, 'code label %s = %s + 0x%x (claimed function of this TU)' % (symbol, fn[:40], lab['value'])
                return False, 'code label %s: its function %s is not claimed at %s - 0x%x' % (symbol, owners[:1], hex(address), lab['value'])
        sidx = next((i for i, x in obj.by_index.items() if x['name'] == symbol and x['section'] > 0 and x['storage'] in (2, 3)
                     and not symbol.startswith('??_7') and not (obj.sections[x['section'] - 1]['chars'] & 0x20)), None)   # DATA defined here is checked by content first (vtables via RTTI/map)
        if symbol in symmap and sidx is None and not symbol.startswith(('??_C@', '__real@')):
            e = symmap[symbol]
            if int(e['address'], 16) != address:
                return False, 'symbol map address %s differs' % e['address']
            kind = e['evidence']
            if kind == 'function_start':
                if address in starts:
                    return True, 'indexed function start'
                return address in mapstarts, 'function_map start (recursive descent)'
            if kind == 'crt':
                return (e.get('crt_symbol'), address) in crt, 'CRT calibration match'
            if kind == 'data':
                return section_of(secs, address) in ('.data', '.rdata'), 'data section address'
            if kind == 'aligned_start':
                prev = read(B, secs, address - 1, 1)
                prev3 = read(B, secs, address - 3, 3)
                ok = address % 16 == 0 and section_of(secs, address) == '.text' and prev is not None and (prev[0] in (0x90, 0xcc, 0xc3) or (prev3 is not None and prev3[0] == 0xc2 and prev3[2] == 0))
                return ok, 'aligned code start after padding/ret (not in either function map)'
            if kind == 'import_thunk':
                # linker import thunk `jmp dword ptr [IAT]` (FF 25 imm32); the IAT slot must import this symbol
                raw = read(B, secs, address, 6)
                if raw is None or raw[:2] != b'\xff\x25' or section_of(secs, address) != '.text':
                    return False, 'import thunk: no jmp [IAT] at the address'
                iat = int.from_bytes(raw[2:6], 'little')
                ok, why = check_import('__imp_' + symbol, iat)
                return ok, 'import thunk jmp [%s]: %s' % (hex(iat), why)
            if kind == 'guid':
                import uuid
                return read(B, secs, address, 16) == uuid.UUID(e['guid']).bytes_le, 'GUID bytes %s' % e['guid']
            return False, 'unknown evidence kind'
        idx = next((i for i, s in obj.by_index.items() if s['name'] == symbol and s['section'] > 0), None)
        if idx is not None and not symbol.startswith('??_7') and not (obj.sections[obj.by_index[idx]['section'] - 1]['chars'] & 0x20):
            secno = obj.by_index[idx]['section']
            sec = obj.sections[secno - 1]
            start = obj.by_index[idx]['value']
            later = sorted(x['value'] for x in obj.by_index.values() if x['section'] == secno and x['value'] > start)
            end = later[0] if later else len(sec['raw'])
            data = sec['raw'][start:end]
            overlap = any(start <= r[0] + k < end for r in sec['relocs'] for k in range(4))
            if not overlap and data:
                static = obj.by_index[idx]['storage'] == 3
                ok = read(B, secs, address, len(data)) == data and section_of(secs, address) in ('.data', '.rdata')
                pad = 0
                if not ok and section_of(secs, address) in ('.data', '.rdata'):
                    # the span up to the next symbol may end in alignment padding (zeros) that the original layout
                    # does not have; compare only up to the last 4-byte word that is non-zero, if <= 15 bytes are dropped
                    core = len(data.rstrip(bytes(1))); core = (core + 3) & ~3
                    if 0 < core < len(data) and len(data) - core <= 15 and read(B, secs, address, core) == data[:core]:
                        ok, pad = True, len(data) - core
                return ok, ('TU-static ' if static else '') + 'object-defined data content (%d bytes%s)' % (len(data) - pad, ', %d trailing zero padding bytes not compared' % pad if pad else '')
            rin = [r for r in sec['relocs'] if start <= r[0] < end]
            if overlap and data and rin and all(r[2] == 6 and r[0] + 4 <= end for r in rin) and len(rin) == sum(1 for r in sec['relocs'] if any(start <= r[0] + k < end for k in range(4))):
                # initialised data with DIR32 pointers: non-pointer bytes must equal the original, and every
                # pointer target must itself be verified (e.g. a string literal by content)
                orig = read(B, secs, address, len(data))
                if orig is None or section_of(secs, address) not in ('.data', '.rdata'):
                    return False, 'object-defined data with pointers: not in a data section'
                masked = set(r[0] - start + k for r in rin for k in range(4))
                if any(orig[i] != data[i] for i in range(len(data)) if i not in masked):
                    return False, 'object-defined data with pointers: non-pointer bytes differ'
                for r in rin:
                    o = r[0] - start
                    addend = int.from_bytes(data[o:o + 4], 'little')
                    target = int.from_bytes(orig[o:o + 4], 'little') - addend
                    tname = obj.by_index[r[1]]['name']
                    ok, why = verify(obj, tname, target, tu)
                    if not ok:
                        return False, 'pointer to %s at %s not verified (%s)' % (tname, hex(target), why)
                return True, ('TU-static ' if obj.by_index[idx]['storage'] == 3 else '') + 'object-defined data with %d verified pointer(s)' % len(rin)
        if (symbol.startswith('_$E') or 'search_compfunc@' in symbol) and symbol in obj.symbols and tu is not None:
            # this TU's own static-initializer/atexit helper: verify its compiled bytes at the referenced address
            hs = obj.function(symbol)['raw']
            hr = match_function(obj, symbol, read(B, secs, address, len(hs)), address, lambda s: None)
            if section_of(secs, address) == '.text' and hr['byte_differences'] == 0 and not hr['relocation_problems']:
                return True, 'TU-local helper %s byte-identical at the referenced address' % symbol
        if (tu, symbol) in claimed:
            hit = address in claimed[(tu, symbol)]
            return hit, 'level-2 claim of this TU at %s' % ','.join(hex(a) for a in sorted(claimed[(tu, symbol)]))
        addrs = claimed_global.get(symbol, set())
        if len(addrs) == 1 and address in addrs:
            return True, 'level-2 claimed function at %s' % hex(address)
        if tu is not None and local_copy(obj, symbol):
            return verify_copy(obj, symbol, address, tu)
        if len(addrs) > 1:
            return False, 'symbol claimed at several RVAs %s (not a TU-local copy): conflict' % ','.join(hex(a) for a in sorted(addrs))
        if addrs:
            return False, 'level-2 claimed function at %s' % hex(next(iter(addrs)))
        if symbol.startswith('??_7'):
            v = vtable_address(catalog, symbol)
            ent, off = vtable_entry(catalog, symbol)
            if ent is not None and any(int(x['vtable'], 16) == address and x['subobject_offset'] == off for x in ent['vtables']):
                return True, 'RTTI vtable %s (%s subobject %d)' % (hex(address), ent['type'], off)
            mq = re.match(r'\?\?_7(\w+(?:@\w+)*)@@6B@$', symbol)
            if mq and ent is not None:
                # an unqualified name denotes the class's own vfptr; with multiple inheritance that is the one subobject
                # whose vtable no qualified name (??_7Class@@6BBase@@@) of this object takes
                taken = {vtable_entry(catalog, x['name'])[1] for x in obj.by_index.values()
                         if x['name'].startswith('??_7%s@@6B' % mq.group(1)) and x['name'] != symbol and x['section'] > 0}
                rest = {x['subobject_offset'] for x in ent['vtables']} - taken
                if None not in taken and len(rest) == 1 and any(int(x['vtable'], 16) == address and x['subobject_offset'] in rest for x in ent['vtables']):
                    return True, 'RTTI vtable %s: own vfptr of %s at subobject %d (the qualified names take %s)' % (hex(address), ent['type'], min(rest), sorted(taken))
            if address in vt_owner:
                # the catalogue assigns this table to another class, or to another subobject than the name says
                return False, 'RTTI assigns %s to %s' % (hex(address), sorted(vt_owner[address])[:2])
            # fallback: a vtable COMDAT defined in this object (template vtables exist in several copies in GAME.EXE);
            # every slot of the original table at this address must be a verified address of the compiled slot symbol
            vi = next((i for i, x in obj.by_index.items() if x['name'] == symbol and x['section'] > 0), None)
            if vi is not None and section_of(secs, address) in ('.data', '.rdata') and not vt_stack:
                vs = obj.by_index[vi]; vsec = obj.sections[vs['section'] - 1]
                rel = sorted((r for r in vsec['relocs'] if r[0] >= vs['value'] and r[2] == 6), key=lambda r: r[0])
                if rel:
                    vt_stack.append(symbol)
                    try:
                        for off, si, _ in rel:
                            raw = read(B, secs, address + off - vs['value'], 4)
                            if raw is None:
                                return False, 'vtable slot unreadable'
                            tgt = int.from_bytes(raw, 'little')
                            ok, why = verify(obj, obj.by_index[si]['name'], tgt, tu)
                            if not ok:
                                return False, 'RTTI vtable %s; slot +0x%x (%s) not verified: %s' % (hex(v) if v else 'not found', off - vs['value'], obj.by_index[si]['name'][:40], why)
                    finally:
                        vt_stack.pop()
                    return True, 'vtable copy with %d verified slots' % len(rel)
            return False, 'RTTI vtable %s' % (hex(v) if v else 'not found')
        if symbol.startswith('??_C@'):
            idx = next((i for i, s in obj.by_index.items() if s['name'] == symbol and s['section'] > 0), None)
            if idx is None:
                return False, 'literal not defined in object'
            lit = obj.sections[obj.by_index[idx]['section'] - 1]['raw']
            return read(B, secs, address, len(lit)) == lit, 'string literal content (%d bytes)' % len(lit)
        return False, 'no evidence'

    for f in funcs:
        obj = objs.get(f['tu'])
        if obj is None:
            report['functions'].append(dict(rva=f['rva'], status='compile_failed')); continue
        va = int(f['rva'], 16) + 0x400000
        if f['symbol'] not in obj.symbols and not any(x['name'] == f['symbol'] for x in obj.by_index.values()):
            report['functions'].append(dict(rva=f['rva'], status='symbol_missing', symbol=f['symbol'])); continue
        size = len(obj.function(f['symbol'])['raw'])
        r = match_function(obj, f['symbol'], read(B, secs, va, size), va, lambda s: None)
        checks = []
        fsec = obj.symbols[f['symbol']]['section'] if f['symbol'] in obj.symbols else None
        for b in r['unresolved_bindings']:
            a = int(b['required_address'], 16)
            lab = next((x for x in obj.by_index.values() if x['name'] == b['symbol'] and x['storage'] == 6), None)
            if lab is not None and lab['section'] == fsec:
                ok, why = (a == va + lab['value']), 'jump-table label inside the same function (+0x%x)' % lab['value']
            else:
                ok, why = verify(obj, b['symbol'], a, f['tu'])
            checks.append(dict(symbol=b['symbol'], address=hex(a), verified=ok, evidence=why))
            sidx = next((i for i, x in obj.by_index.items() if x['name'] == b['symbol']), None)
            dsec = obj.by_index[sidx]['section'] if sidx is not None else 0
            perdef = dsec > 0 and not (obj.sections[dsec - 1]['chars'] & 0x20)   # data defined in this object: per-TU copy
            key = (f['tu'], b['symbol']) if (sidx is not None and obj.by_index[sidx]['storage'] in (3, 6)) or perdef or local_copy(obj, b['symbol']) or b['symbol'].startswith(('??_C@', '$L', '_$E')) or 'search_compfunc@' in b['symbol'] else b['symbol']
            prev = bound.setdefault(key, a)
            if prev != a:
                report['symbol_conflicts'].append(dict(symbol=str(key), addresses=[hex(prev), hex(a)]))
        allok = r['byte_differences'] == 0 and not r['relocation_problems'] and all(c['verified'] for c in checks)
        dup = None
        if not f['symbol'].startswith('_$E') and len(claimed_global.get(f['symbol'], ())) > 1 and not local_copy(obj, f['symbol']):
            # one ordinary (non-inline, non-static) function cannot live at two addresses: every such claim is unproven
            dup = sorted(hex(a) for a in claimed_global[f['symbol']])
            report.setdefault('duplicate_claims', []).append(dict(rva=f['rva'], tu=f['tu'], symbol=f['symbol'], addresses=dup))
        report['functions'].append(dict(rva=f['rva'], tu=f['tu'], symbol=f['symbol'], size=size,
                                        byte_differences=r['byte_differences'], first_differences=r['first_differences'],
                                        bindings=checks, status='duplicate_claim' if (dup and allok) else 'matched' if allok else 'not_matched'))
    rev = {}
    for s, a in bound.items():
        rev.setdefault(a, set()).add(str(s))
    report['shared_addresses'] = {hex(a): sorted(s) for a, s in rev.items() if len(s) > 1}
    os.makedirs(os.path.join(W, 'analysis', 'level2', 'reports'), exist_ok=True)
    out = os.path.join(W, 'analysis', 'level2', 'reports', 'check_%s.json' % report['utc'].replace(':', ''))
    json.dump(report, open(out, 'w'), indent=1)
    m = sum(1 for f in report['functions'] if f['status'] == 'matched')
    print('matched %d/%d; conflicts %d; report %s' % (m, len(report['functions']), len(report['symbol_conflicts']), out))
    for f in report['functions']:
        if f['status'] != 'matched':
            print(' ', f['rva'], f['status'], [c for c in f.get('bindings', []) if not c['verified']][:4], f.get('first_differences'))


if __name__ == '__main__':
    main()
