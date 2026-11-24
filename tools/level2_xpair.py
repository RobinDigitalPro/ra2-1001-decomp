"""level2_xpair.py: pair unmatched Yuri's Revenge 1.001 functions with RA2 1.001 functions.

Purpose
    For every YR function in a work list (default: the 103 functions gibbo101/ra2-decomp
    has not matched, analysis/level2/gibbo_unmatched.json) find the most similar function
    of RA2 1.001 GAME.EXE, say whether WE have it byte-identical (a level-2 claim in
    P/metadata/level2_functions.json), and cut our C++ source out for the good pairs.
    Re-run it after new claims are integrated: statuses, pairs and snippets follow the
    current claims and the current P source.

Usage
    python -I level2_xpair.py [--out STAGE_DIR] [--work WORK_DIR] [--snippet-min 0.60]
                              [--always-snippet 0x006BB9A0,0x00710AF0] [--top 12]
                              [--no-snippets] [--no-cache]

    --out   folder that receives pairs_unmatched.csv, pairs_summary.md and snippets/ (the
            upload folder).
            snippets/ is rebuilt from scratch on every run (only files this tool wrote,
            recognised by their first line, are removed).
    --work  folder for the token cache and pairs_summary.json (never uploaded).
    --snippet-min     a snippet is written for a matched pair at or above this similarity
    --always-snippet  YR addresses that get a snippet whenever their pair is matched
    --top   number of prefilter candidates that get the full comparison

Read-only inputs (nothing is executed from any checkout, neither game is started)
    P/RA2Original/GAME.EXE                    RA2 1.001 (SHA-256 checked)
    P/RA2SteamVersion/gamemd-spawn.exe        YR 1.001 retail build (MD5 checked)
    P/metadata/level2_functions.json          our byte-identical claims
    P/metadata/level2_symbols.json            names of bound, unclaimed function starts
    P/src/<tu>                                snippet source
    W/analysis/level2/function_map.json       every RA2 function start and size
    W/analysis/level2/reports/check_*.json    claim sizes (newest report that has the claim)
    W/analysis/level2/jobstation_up/targets*.json   near-miss work targets (names only)
    W/analysis/level2/gibbo_unmatched.json    the YR work list
    <gibbo checkout>/data/attempts.csv        their best percentage per address (CSV read)

Method (the same idea as the first package's pairs.csv)
    1. Both bodies are disassembled with capstone, trailing int3/nop padding dropped.
    2. Masked token = mnemonic + operands, with every number inside the image
       (0x401000 .. image end) replaced by A and with call/jump targets dropped.
       Neither executable has a .reloc section, so this mask is a heuristic, applied the
       same way on both sides.
    3. Shape token = the same with every number replaced by N (insensitive to field
       offsets and frame sizes).
    4. Prefilter: RA2 functions with a size ratio of 0.40 .. 2.50, ranked by the multiset
       overlap of shape 3-grams; the best --top go on.
    5. similarity = difflib ratio over masked tokens; shape_similarity = the same over
       shape tokens. The row lists the candidate with the highest similarity.
    6. our_status: matched (a claim), near-miss (unclaimed; a named work target with source
       in our tree that is not byte-identical yet), library (a library-identical CRT body
       from P/metadata/level2_library.json) or unmatched (unclaimed, no source).
       When the best candidate is not matched, a second row gives the best MATCHED
       candidate if its similarity is at least 0.50.

Output columns: see README.md in the stage folder.
"""
import argparse, collections, csv, difflib, glob, hashlib, json, os, pickle, re, struct, sys

P = r'D:\<project-folder>\Coding\RedAlert2'
W = r'D:\<work-root>\RedAlert2Temp'
sys.path.insert(0, os.path.join(W, 'tools', 'portable', 'capstone-5.0.6'))
import capstone  # noqa: E402

RA2_EXE = os.path.join(P, 'RA2Original', 'GAME.EXE')
RA2_SHA256 = '7fe00ee313b38b22e68d6c05aede041018206e29b71f5db9cc1afacc61588c6e'
YR_EXE = os.path.join(P, 'RA2SteamVersion', 'gamemd-spawn.exe')
YR_MD5 = '937b14db32f07ee47e92a8114ebdbdde'
L2 = os.path.join(W, 'analysis', 'level2')
GIBBO = os.path.join(W, 'analysis', 'references_gpl_20261118', 'gibbo101_ra2-decomp')
DEF_OUT = os.path.join(L2, 'publish_20261123', 'stage', 'for-gibbo101-ra2-decomp', 'update_2026-11-23')
DEF_WORK = os.path.join(L2, 'publish_20261123', 'work')
SNIPPET_MARK = '// ra2-decomp help snippet, update 2026-11-23'
FLAGS = '-O2 -Ob2 -Gr -GR -DNDEBUG -Gy'
# Helpers a snippet needs to make sense: yr_address -> [(project-relative file, kind, name)].
COMPANIONS = {
    '0x006BB9A0': [('src/m85/src/startup.cpp', 'function', 'Read_Setup_Options')],
    '0x00710AF0': [('src/m85/include/techtype.h', 'struct', 'TechnoUnused2')],
}
COLUMNS = ['yr_address', 'yr_size', 'gibbo_status', 'ra2_rva', 'ra2_symbol', 'ra2_name', 'our_tu',
           'similarity', 'class', 'shape_similarity', 'resolution', 'ties', 'gibbo_name', 'also_named',
           'snippet', 'our_status']


class Image:
    def __init__(self, path):
        self.data = open(path, 'rb').read()
        pe = struct.unpack_from('<I', self.data, 0x3c)[0]
        nsec = struct.unpack_from('<H', self.data, pe + 6)[0]
        opt = struct.unpack_from('<H', self.data, pe + 20)[0]
        self.base = struct.unpack_from('<I', self.data, pe + 24 + 28)[0]
        self.size = struct.unpack_from('<I', self.data, pe + 24 + 56)[0]
        self.sections = []
        for i in range(nsec):
            o = pe + 24 + opt + 40 * i
            vs, va, rs, ra = struct.unpack_from('<IIII', self.data, o + 8)
            self.sections.append((va, max(vs, rs), ra, rs))

    def read(self, rva, size):
        for va, vs, ra, rs in self.sections:
            if va <= rva < va + vs:
                off = ra + rva - va
                return self.data[off:off + min(size, rs - (rva - va))]
        return b''


MD = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
NUM = re.compile(r'0x[0-9a-f]+|\b\d+\b')


def tokens(code, lo, hi):
    """(masked tokens, shape tokens) of one body; lo/hi bound the image for the address mask."""
    end = len(code)
    while end and code[end - 1] in (0x90, 0xcc):
        end -= 1
    masked, shape = [], []

    def mask(m):
        t = m.group(0)
        v = int(t, 16) if t.startswith('0x') else int(t)
        return 'A' if lo <= v < hi else t

    for ins in MD.disasm(code[:end], 0):
        m, ops = ins.mnemonic, ins.op_str
        if m == 'nop' or m == 'int3':
            continue
        if (m == 'call' or m[0] == 'j' or m.startswith('loop')) and (ops.startswith('0x') or ops.isdigit()):
            masked.append(m)
            shape.append(m)
            continue
        masked.append(m + ' ' + NUM.sub(mask, ops))
        shape.append(m + ' ' + NUM.sub('N', ops))
    return masked, shape, end


def grams(shape):
    return collections.Counter(zip(shape, shape[1:], shape[2:])) if len(shape) >= 3 else collections.Counter((s,) for s in shape)


def overlap(a, b):
    na, nb = sum(a.values()), sum(b.values())
    if not na or not nb:
        return 0.0
    small, big = (a, b) if len(a) <= len(b) else (b, a)
    return 2.0 * sum(min(c, big[g]) for g, c in small.items() if g in big) / (na + nb)


def ratio(a, b):
    if a == b:
        return 1.0
    return difflib.SequenceMatcher(None, a, b, autojunk=False).ratio()


def classify(sim, exact):
    if exact:
        return 'exact-masked'
    if sim >= 0.95:
        return 'very-similar'
    if sim >= 0.85:
        return 'similar'
    if sim >= 0.60:
        return 'partial'
    return 'weak'


# ---------------------------------------------------------------- our side

def load_ra2():
    """rva -> dict(size, symbol, name, tu, status) for every known RA2 function."""
    funcs = {}
    for f in json.load(open(os.path.join(L2, 'function_map.json')))['map']:
        funcs[int(f['rva'], 16)] = dict(size=int(f['size']), symbol='', name='', tu='', status='unmatched')
    claims = json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))
    want = {int(c['rva'], 16) for c in claims}
    sizes = {}
    for path in sorted(glob.glob(os.path.join(L2, 'reports', 'check_*.json')), reverse=True):
        if not (want - sizes.keys()):
            break
        try:
            rep = json.load(open(path))
        except (ValueError, OSError):
            continue
        for f in rep.get('functions', []):
            r = int(f['rva'], 16)
            if r in want and r not in sizes and f.get('status') == 'matched':
                sizes[r] = int(f['size'])
    nosize = 0
    for c in claims:
        r = int(c['rva'], 16)
        if c['symbol'].startswith('_$E'):
            funcs.pop(r, None)      # static initialisers: numbering differs per TU, never a twin lead
            continue
        size = sizes.get(r) or funcs.get(r, {}).get('size')
        if not size:
            nosize += 1
            continue
        funcs[r] = dict(size=size, symbol=c['symbol'], name=c.get('name') or c['symbol'], tu=c['tu'], status='matched')
    # names for unclaimed starts: bound symbols, then near-miss work targets
    try:
        for sym, rec in json.load(open(os.path.join(P, 'metadata', 'level2_symbols.json'), encoding='utf-8')).items():
            if isinstance(rec, dict) and rec.get('evidence') == 'function_start':
                r = int(rec['address'], 16) - 0x400000
                if r in funcs and funcs[r]['status'] != 'matched' and not funcs[r]['symbol']:
                    funcs[r]['symbol'] = funcs[r]['name'] = sym
    except (OSError, ValueError):
        pass
    # Near-miss work targets. The map misses some of these starts and splits large switch
    # procedures at jump-table labels, so a target's extent is the size its work note
    # states ("1.001 ~N bytes") or, for a start the map misses, the distance to the next
    # verified start (a claim or another target). Map entries inside that extent are dropped.
    targets = {}
    for path in sorted(glob.glob(os.path.join(L2, 'jobstation_up', 'targets*.json'))):
        try:
            for t in json.load(open(path, encoding='utf-8')).get('targets', []):
                name = t.get('symbol', '')
                if t.get('tu') and not name.startswith(('GAP', 'function 0x')):
                    targets[int(t['rva'], 16)] = t
        except (OSError, ValueError, KeyError):
            continue
    solid = sorted({r for r, f in funcs.items() if f['status'] == 'matched'} | set(targets))
    for r, t in sorted(targets.items()):
        if funcs.get(r, {}).get('status') == 'matched':
            continue
        m = re.search(r'1\.001 ~?(\d+) bytes', t.get('diff', ''))
        size = int(m.group(1)) if m else funcs.get(r, {}).get('size')
        if not size:
            later = [x for x in solid if x > r]
            if not later or later[0] - r > 0x8000:
                continue
            size = later[0] - r
        for inner in [x for x in funcs if r < x < r + size and funcs[x]['status'] != 'matched']:
            del funcs[inner]
        funcs[r] = dict(size=size, symbol='', name=t.get('symbol', ''), tu=t['tu'], status='near-miss')
    try:                                                    # library-identical CRT bodies (not our C++)
        lib = json.load(open(os.path.join(P, 'metadata', 'level2_library.json'), encoding='utf-8'))
        for x in lib['functions']:
            r = int(x['rva'], 16)
            if funcs.get(r, {}).get('status') == 'matched':
                continue
            sym = (x.get('symbols') or [''])[0]
            funcs[r] = dict(size=int(x['size']), symbol=sym, name=sym, status='library',
                            tu='%s:%s' % (x.get('library', ''), re.split(r'[\\/]', x.get('member', ''))[-1]))
    except (OSError, ValueError, KeyError):
        pass
    return funcs, len(claims), nosize


def ra2_tokens(funcs, img, work, use_cache):
    cache_path = os.path.join(work, 'ra2_tokens.pickle')
    cache = {}
    if use_cache and os.path.exists(cache_path):
        try:
            cache = pickle.load(open(cache_path, 'rb'))
            if cache.get('sha') != RA2_SHA256:
                cache = {}
        except Exception:
            cache = {}
    toks = cache.get('toks', {})
    new = 0
    lo, hi = img.base + 0x1000, img.base + img.size
    for r, f in funcs.items():
        key = (r, f['size'])
        if key not in toks:
            m, s, body = tokens(img.read(r, f['size']), lo, hi)
            toks[key] = (m, s, body)
            new += 1
    if new and use_cache:
        os.makedirs(work, exist_ok=True)
        pickle.dump(dict(sha=RA2_SHA256, toks=toks), open(cache_path, 'wb'), protocol=4)
    return {r: toks[(r, f['size'])] for r, f in funcs.items()}, new


# ---------------------------------------------------------------- snippets

def simple_name(symbol, name):
    """(class or '', method) for the definition search."""
    if symbol.startswith('_') and '@' in symbol and not symbol.startswith('__'):
        return '', symbol[1:].split('@')[0]                 # _WinMain@16
    m = re.match(r'\?\?([01])(\w+)@@', symbol)
    if m:
        cls = m.group(2)
        return cls, ('~' if m.group(1) == '1' else '') + cls
    m = re.match(r'\?(\w+)@\?\$(\w+)@', symbol)
    if m:
        return m.group(2), m.group(1)                       # member of a class template
    m = re.match(r'\?(\w+)@(?:(\w+)@)?@', symbol)
    if m:
        return m.group(2) or '', m.group(1)
    if '::' in name:
        head = name.split('(')[0].strip().split('::')
        return head[-2], head[-1]
    return '', name.split('(')[0].strip()


def param_count(text):
    text = text.strip()
    if text in ('', 'void'):
        return 0
    depth, n = 0, 1
    for ch in text:
        if ch in '(<[':
            depth += 1
        elif ch in ')>]':
            depth -= 1
        elif ch == ',' and depth == 0:
            n += 1
    return n


def find_definitions(src, cls, method, inclass=False):
    """[(start_line, end_line)] of top-level definitions named cls::method (or method)."""
    lines = src.split('\n')
    offs, pos = [], 0
    for ln in lines:
        offs.append(pos)
        pos += len(ln) + 1
    pats = []
    if cls:
        pats.append(re.compile(r'^(?![\s#/])[^;={}]*\b%s(?:<[^<>;]*>)?::%s\s*\(' % (re.escape(cls), re.escape(method))))
    if not inclass:
        pats.append(re.compile(r'^(?![\s#/])[^;={}]*(?<![:\w~])%s\s*\(' % re.escape(method)))
    else:                                                   # a member defined inside its class body (headers)
        pats.append(re.compile(r'^\s+(?!(?:if|while|for|return|switch|else|case|delete|new)\b)(?![#/*])[^;={}().]*(?<![:\w~.>])%s\s*\(' % re.escape(method)))
    for pat in pats:
        found = []
        for i, ln in enumerate(lines):
            m = pat.match(ln)
            if not m:
                continue
            p = offs[i] + m.end() - 1                       # the '('
            depth, q = 0, p
            while q < len(src):
                if src[q] == '(':
                    depth += 1
                elif src[q] == ')':
                    depth -= 1
                    if depth == 0:
                        break
                q += 1
            params = src[p + 1:q]
            q += 1
            brace = None
            while q < len(src):                             # initialiser list allowed, ';' ends a prototype
                c = src[q]
                if src.startswith('//', q):
                    q = src.find('\n', q)
                    if q < 0:
                        break
                    continue
                if src.startswith('/*', q):
                    q = src.find('*/', q) + 2
                    continue
                if c == ';':
                    break
                if c == '(':                                # member initialiser arguments
                    d = 0
                    while q < len(src):
                        if src[q] == '(':
                            d += 1
                        elif src[q] == ')':
                            d -= 1
                            if d == 0:
                                break
                        q += 1
                if c == '{':
                    brace = q
                    break
                q += 1
            if brace is None:
                continue
            depth, q = 0, brace
            while q < len(src):
                c = src[q]
                if src.startswith('//', q):
                    q = src.find('\n', q)
                    if q < 0:
                        q = len(src)
                    continue
                if src.startswith('/*', q):
                    q = src.find('*/', q) + 2
                    continue
                if c in '"\'':
                    e = q + 1
                    while e < len(src) and src[e] != c:
                        e += 2 if src[e] == '\\' else 1
                    q = e + 1
                    continue
                if c == '{':
                    depth += 1
                elif c == '}':
                    depth -= 1
                    if depth == 0:
                        break
                q += 1
            end_line = src.count('\n', 0, q)
            start = i
            while start > 0:                                # comment block directly above
                prev = lines[start - 1].strip()
                if prev.startswith(('//', '*', '/*', 'template')) or prev.endswith('*/'):
                    start -= 1
                else:
                    break
            found.append((start, end_line, param_count(params)))
        if found:
            return lines, found
    return lines, []


def licence_block(src):
    """The TU's leading comment block, when it carries the licence / copyright notice."""
    s = src.lstrip('\ufeff \t\r\n')
    if s.startswith('/*'):
        e = s.find('*/')
        blk = s[:e + 2] if e > 0 else ''
        if re.search(r'SPDX|Copyright|GPL|License', blk):
            return blk
    elif s.startswith('//'):
        out = []
        for ln in s.split('\n'):
            if ln.startswith('//'):
                out.append(ln)
            else:
                break
        blk = '\n'.join(out)
        if re.search(r'SPDX|Copyright|GPL|License', blk):
            return blk
    return ''


def write_snippet(row, f, yr, out_dir):
    path = os.path.join(P, f['tu'].replace('/', os.sep))
    if not os.path.isfile(path) or not f['tu'].lower().endswith(('.cpp', '.c', '.h')):
        return 'no C++ source (%s)' % os.path.basename(f['tu'])
    src = open(path, encoding='utf-8', errors='replace').read().replace('\r\n', '\n')
    cls, method = simple_name(f['symbol'], f['name'])
    lines, defs = find_definitions(src, cls, method)
    note = ''
    if not defs and cls:                                    # inline or template member: look in the TU's own headers
        dirs = [os.path.dirname(path)] + [os.path.join(P, 'src', d) for d in ('m85/include', 'm85/src', 'ra2')]
        for inc in re.findall(r'^\s*#\s*include\s*"([^"]+)"', src, re.M):
            for d in dirs:
                hp = os.path.join(d, inc.replace('/', os.sep))
                if os.path.isfile(hp):
                    hsrc = open(hp, encoding='utf-8', errors='replace').read().replace('\r\n', '\n')
                    if re.search(r'\b(class|struct)\s+%s\b' % re.escape(cls), hsrc):
                        lines, defs = find_definitions(hsrc, cls, method, inclass=True)
                        if defs:
                            src = hsrc
                            note = '// defined in : %s (an inline or template member, emitted in this TU)\n' % os.path.relpath(hp, P).replace(os.sep, '/')
                    break
            if defs:
                break
    if not defs:
        return 'definition not found automatically'
    if len(defs) > 1:
        want = param_count(f['name'].split('(', 1)[1].rsplit(')', 1)[0]) if '(' in f['name'] else None
        pick = [d for d in defs if d[2] == want] if want is not None else []
        if len(pick) == 1:
            defs = pick
        else:
            note = '// NOTE       : %d definitions with this name were found; all are included\n' % len(defs)
    rva = int(row['ra2_rva'], 16)
    head = [SNIPPET_MARK + ' (RA2 1.001 level-2 reconstruction; NOT verified on gamemd.exe)',
            '// YR address : %s (%s bytes; gibbo101/ra2-decomp name: %s)' % (yr['address'], yr['size'], yr['name'] or 'none'),
            '// RA2 address: RVA 0x%x (VA 0x%08X, %d bytes without padding)' % (rva, rva + 0x400000, row['_body']),
            '// RA2 symbol : %s' % f['symbol'],
            '// similarity : %s (%s, masked instruction tokens; shape %s)' % (row['similarity'], row['class'], row['shape_similarity']),
            '// evidence   : byte-identical in RA2 1.001 under VC6 12.00.8168 %s' % FLAGS,
            '// source TU  : %s' % f['tu'],
            '// License    : GPL-3.0-or-later. Our source is GPL and contains EA GPL code (section 7 terms)',
            '//              and code adapted from mischa85/RedAlert2 and gibbo101/ra2-decomp; their',
            '//              credits are kept. The notice of the source file follows. See ../README.md.',
            '// Use        : a read-only lead. RA2 layouts and names; port it and match it on your own checker.']
    body = []
    for a, b, _ in defs:
        body.append('\n'.join(lines[a:b + 1]))
    for rel, kind, cname in COMPANIONS.get(yr['address'].upper().replace('0X', '0x'), []):
        cpath = os.path.join(P, rel.replace('/', os.sep))
        if not os.path.isfile(cpath):
            continue
        csrc = open(cpath, encoding='utf-8', errors='replace').read().replace('\r\n', '\n')
        text_c = ''
        if kind == 'function':
            clines, cdefs = find_definitions(csrc, '', cname)
            text_c = '\n\n'.join('\n'.join(clines[x:y + 1]) for x, y, _ in cdefs)
        else:
            m = re.search(r'^(?:struct|class)\s+%s\b[^;{]*\{' % re.escape(cname), csrc, re.M)
            if m:
                depth, q = 0, m.end() - 1
                while q < len(csrc):
                    depth += (csrc[q] == '{') - (csrc[q] == '}')
                    if depth == 0:
                        break
                    q += 1
                text_c = csrc[m.start():csrc.find(';', q) + 1]
        if text_c:
            body.append('// ---- companion (%s %s, from %s): the function above depends on it ----\n%s' % (kind, cname, rel, text_c))
    lic = licence_block(src)
    text = '\n'.join(head) + '\n' + note + '\n' + (lic + '\n\n' if lic else '') + '\n\n'.join(body) + '\n'
    name = yr['address'] + '.cpp'
    os.makedirs(out_dir, exist_ok=True)
    open(os.path.join(out_dir, name), 'w', encoding='utf-8', newline='\n').write(text)
    return 'snippets/' + name


# ---------------------------------------------------------------- main

def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('--out', default=DEF_OUT)
    ap.add_argument('--work', default=DEF_WORK)
    ap.add_argument('--list', default=os.path.join(L2, 'gibbo_unmatched.json'))
    ap.add_argument('--snippet-min', type=float, default=0.60)
    ap.add_argument('--always-snippet', default='0x006BB9A0,0x00710AF0')
    ap.add_argument('--top', type=int, default=12)
    ap.add_argument('--no-snippets', action='store_true')
    ap.add_argument('--no-cache', action='store_true')
    a = ap.parse_args()
    for d in (a.out, a.work):
        full = os.path.abspath(d).lower()
        if 'onedrive' in full or not full.startswith(os.path.abspath(W).lower()):
            sys.exit('refusing to write outside the W work tree: ' + d)
    ra2, yr = Image(RA2_EXE), Image(YR_EXE)
    if hashlib.sha256(ra2.data).hexdigest() != RA2_SHA256:
        sys.exit('GAME.EXE is not the 1.001 baseline')
    if hashlib.md5(yr.data).hexdigest() != YR_MD5:
        sys.exit('gamemd-spawn.exe is not the YR 1.001 retail build')
    os.makedirs(a.out, exist_ok=True)
    os.makedirs(a.work, exist_ok=True)
    funcs, nclaims, nosize = load_ra2()
    toks, new = ra2_tokens(funcs, ra2, a.work, not a.no_cache)
    sys.stderr.write('RA2: %d functions (%d claims, %d without a size), %d newly disassembled\n' % (len(funcs), nclaims, nosize, new))
    rgram = {r: grams(t[1]) for r, t in toks.items()}
    best_attempt = {}
    try:
        for r in csv.DictReader(open(os.path.join(GIBBO, 'data', 'attempts.csv'), encoding='utf-8', errors='replace')):
            try:
                pct = float(r['best'])
            except (ValueError, TypeError):
                continue
            adr = r['address'].upper().replace('0X', '0x')
            best_attempt[adr] = max(best_attempt.get(adr, 0.0), pct)
    except OSError:
        pass
    always = {x.strip().upper().replace('0X', '0x') for x in a.always_snippet.split(',') if x.strip()}
    snip_dir = os.path.join(a.out, 'snippets')
    if os.path.isdir(snip_dir) and not a.no_snippets:
        for n in os.listdir(snip_dir):                      # remove only our own earlier output
            p = os.path.join(snip_dir, n)
            if n.endswith('.cpp') and open(p, encoding='utf-8', errors='replace').readline().startswith(SNIPPET_MARK):
                os.remove(p)
    ylo, yhi = yr.base + 0x1000, yr.base + yr.size
    rows, summary = [], []
    work = json.load(open(a.list, encoding='utf-8'))
    for y in work:
        adr = int(y['address'], 16)
        ysize = int(y['size'])
        ym, ys, ybody = tokens(yr.read(adr - yr.base, ysize), ylo, yhi)
        yg = grams(ys)
        cands = []
        for r, f in funcs.items():
            body = toks[r][2]
            if not body or not (0.40 <= body / max(ybody, 1) <= 2.50):
                continue
            cands.append((overlap(yg, rgram[r]), r))
        cands.sort(reverse=True)
        keep = cands[:a.top]
        seen = {r for _, r in keep}
        extra = [(o, r) for o, r in cands if funcs[r]['status'] == 'matched' and r not in seen][:max(3, a.top // 3)]
        scored = []
        for _, r in keep + extra:
            sim = ratio(ym, toks[r][0])
            scored.append((sim, ratio(ys, toks[r][1]), r))
        scored.sort(key=lambda t: (-t[0], -t[1], t[2]))
        attempt = best_attempt.get(y['address'].upper().replace('0X', '0x'))
        gstatus = 'attempted-partial %g%%' % attempt if attempt else 'unmatched'
        picks = []
        if scored:
            picks.append(scored[0])
            if funcs[scored[0][2]]['status'] != 'matched':
                m = [s for s in scored if funcs[s[2]]['status'] == 'matched' and s[0] >= 0.50]
                if m:
                    picks.append(m[0])
        if not picks:
            rows.append(dict(yr_address=y['address'], yr_size=ysize, gibbo_status=gstatus, ra2_rva='', ra2_symbol='',
                             ra2_name='', our_tu='', similarity='', shape_similarity='', resolution='none', ties=0,
                             gibbo_name=y['name'], also_named='', snippet='no candidate in the size window',
                             our_status='', **{'class': 'none'}))
            continue
        for sim, shp, r in picks:
            f = funcs[r]
            ties = len({s[2] for s in scored if s[0] >= sim - 0.002}) if picks[0][2] == r else 1
            row = dict(yr_address=y['address'], yr_size=ysize, gibbo_status=gstatus, ra2_rva='0x%x' % r,
                       ra2_symbol=f['symbol'], ra2_name=f['name'], our_tu=f['tu'], similarity='%.4f' % sim,
                       shape_similarity='%.4f' % shp, resolution='unique' if ties == 1 else 'ambiguous', ties=ties,
                       gibbo_name=y['name'], also_named='', snippet='', our_status=f['status'], _body=toks[r][2])
            row['class'] = classify(sim, ym == toks[r][0])
            if f['status'] == 'matched':
                if a.no_snippets:
                    row['snippet'] = ''
                elif ybody < 16 or ties > 1:
                    row['snippet'] = 'too small or ambiguous to pair reliably'
                elif sim >= a.snippet_min or y['address'].upper().replace('0X', '0x') in always:
                    row['snippet'] = write_snippet(row, f, y, snip_dir)
                else:
                    row['snippet'] = 'below the snippet threshold'
            elif f['status'] == 'library':
                row['snippet'] = 'library code (%s), no source of ours' % f['tu']
            else:
                row['snippet'] = 'not byte-identical on our side yet'
            rows.append(row)
        summary.append(dict(yr=y['address'], size=ysize, name=y['name'],
                            top=[dict(rva='0x%x' % r, sim=round(s, 4), shape=round(h, 4), status=funcs[r]['status'],
                                      name=funcs[r]['name']) for s, h, r in scored[:5]]))
    with open(os.path.join(a.out, 'pairs_unmatched.csv'), 'w', encoding='utf-8', newline='') as fh:
        w = csv.DictWriter(fh, COLUMNS, extrasaction='ignore', lineterminator='\n')
        w.writeheader()
        w.writerows(rows)
    first = {}
    for r in rows:
        first.setdefault(r['yr_address'], r)
    stat = collections.Counter(r['our_status'] or 'none' for r in first.values())
    cls = collections.Counter(r['class'] for r in first.values())
    nsnip = sum(1 for r in rows if r['snippet'].startswith('snippets/'))
    counts = dict(yr_functions=len(work), rows=len(rows), best_status=dict(stat), best_class=dict(cls), snippets=nsnip,
                  matched_rows=sum(1 for r in rows if r['our_status'] == 'matched'),
                  matched_rows_ge_060=sum(1 for r in rows if r['our_status'] == 'matched' and float(r['similarity']) >= 0.60),
                  claims=nclaims)
    counts['names_offered'] = sum(1 for r in first.values() if not r['gibbo_name'] and r['ra2_name'] and r['similarity']
                                  and float(r['similarity']) >= 0.85 and r['resolution'] == 'unique')
    json.dump(dict(counts=counts, pairs=summary), open(os.path.join(a.work, 'pairs_summary.json'), 'w'), indent=1)
    print(json.dumps(counts, indent=1))
    # pairs_summary.md: the generated numbers of this run (README.md refers to it)
    order = ['matched', 'near-miss', 'unmatched', 'library', 'none']
    corder = ['exact-masked', 'very-similar', 'similar', 'partial', 'weak', 'none']
    md = ['# pairs_unmatched.csv: summary of this run', '',
          'Generated by our pairing script from the claims of the RA2 1.001 level-2 reconstruction project',
          '(%d byte-identical claims at the time of the run). Work list: %d YR functions, %d rows.' % (nclaims, len(work), len(rows)), '',
          '## Best RA2 candidate per YR function, by our status', '',
          '| our_status | YR functions | meaning |', '|---|---|---|']
    meaning = {'matched': 'byte-identical C++ in our tree', 'near-miss': 'we have source, not byte-identical yet',
               'unmatched': 'located in RA2 1.001, no source of ours', 'library': 'a CRT library body in RA2 1.001',
               'none': 'no candidate in the size window'}
    md += ['| %s | %d | %s |' % (k, stat[k], meaning[k]) for k in order if stat.get(k)]
    md += ['', '## Best RA2 candidate per YR function, by similarity class', '', '| class | YR functions |', '|---|---|']
    md += ['| %s | %d |' % (k, cls[k]) for k in corder if cls.get(k)]
    md += ['', 'Rows with our_status matched: %d (%d of them at similarity 0.60 or higher). Snippets written: %d.' % (
        counts['matched_rows'], counts['matched_rows_ge_060'], nsnip), '',
           'YR functions without a name in the work list whose best RA2 candidate has a name of ours at similarity 0.85 or higher: %d.' % counts['names_offered'], '',
           '## Matched pairs (our byte-identical source exists), by similarity', '',
           '| YR address | YR size | similarity | shape | our function (RA2 RVA) | their name | snippet |', '|---|---|---|---|---|---|---|']
    for r in sorted((r for r in rows if r['our_status'] == 'matched'), key=lambda r: (-float(r['similarity']), r['yr_address'])):
        md.append('| %s | %s | %s | %s | `%s` (%s) | %s | %s |' % (
            r['yr_address'], r['yr_size'], r['similarity'], r['shape_similarity'], r['ra2_name'].replace('|', '\|'), r['ra2_rva'],
            r['gibbo_name'] or '-', r['snippet'] if r['snippet'].startswith('snippets/') else '-'))
    md += ['', '## Near-miss pairs (both projects are still working on these)', '',
           '| YR address | YR size | similarity | shape | our function (RA2 RVA) | their name | their best |', '|---|---|---|---|---|---|---|']
    for r in sorted((r for r in rows if r['our_status'] == 'near-miss'), key=lambda r: (-float(r['similarity']), r['yr_address'])):
        md.append('| %s | %s | %s | %s | `%s` (%s) | %s | %s |' % (
            r['yr_address'], r['yr_size'], r['similarity'], r['shape_similarity'], r['ra2_name'], r['ra2_rva'],
            r['gibbo_name'] or '-', r['gibbo_status'].replace('attempted-partial ', '')))
    open(os.path.join(a.out, 'pairs_summary.md'), 'w', encoding='utf-8', newline='\n').write('\n'.join(md) + '\n')
    top = sorted((r for r in rows if r['similarity']), key=lambda r: -float(r['similarity']))[:15]
    for r in top:
        print('%s %6s  %-9s %-12s %s  %s <- %s' % (r['yr_address'], r['yr_size'], r['our_status'], r['class'],
                                                  r['similarity'], r['ra2_name'] or r['ra2_rva'], r['gibbo_name'] or '(unnamed)'))


if __name__ == '__main__':
    main()
