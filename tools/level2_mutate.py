"""Level-2 statement-level source mutator and probe minimizer for ONE target function of a TU.

Idea: a near miss (1-2 bytes, a register rotation, one frame slot) is usually a small source-shape difference. This tool applies
SMALL NATURAL edits inside the target function only (named temporaries, declaration moves, adjacent swaps, blocks, `a=b; if(a)` <->
`if((a=b))`, commutative operand swaps, early return <-> if/else, `!= NULL`, pointer <-> reference locals, member through a local
copy, ternary <-> if/else, split/merge declarations, hoisting declarations), compiles each mutant with VC6, and scores the target
against GAME.EXE 1.001 with the existing machinery (l2match / coffmatch / hunks scoring of level2_varsearch). A mutant that does not
compile, or that changes a CONTROL function, is rejected. One compile at a time (the disk is shared). Results are cached by source hash.

usage: python -I level2_mutate.py <spec.json> [--mode search|minimize] [--max N] [--beam B] [--per-state K] [--seed S]
                                  [--ops op1,op2,..] [--list-ops] [--window CHARS] [--depth D] [--no-verify] [--out DIR]
spec.json (paths relative to the spec file):
{
  "name": "techno_lz",                         // tag for the output files
  "base": "work/techno.cpp",                   // scratch COPY of the TU (never a file in P)
  "preset": "m85",                             // m85 (-I m85/src -I m85/include -DWIN32 -W0) or ra2 (-I src/ra2)
  "tu": "src/m85/src/techno.cpp",              // TU path as used in claims files
  "func": "TechnoClass::Laser_Zap",            // qualified name; the definition is found as `...func(` at line start
  "targets":  [["Laser_Zap@TechnoClass@@", "0x2bf3c0"]],   // [symbol substring or exact '?..' name, rva]
  "controls": [["Draw_Tiles", "0x29dba0"]],    // optional, must stay byte-identical (candidates changing them are rejected)
  "claims_check": true,                        // for a candidate that matches the target, ALSO require every claim of the TU
                                               // in metadata/level2_functions.json that matched in the base to still match
  "probe": "work/techno_probe.cpp"             // optional: a state in which the target already matches with dead probe statements
}
Modes:
  search    beam search from the base text. --beam keeps the B best states per round (ties keep neutral states), --per-state caps
            the neighbours compiled per state (random sample, --seed), --max is the TOTAL compile budget (default 300). Stops at the
            first byte-identical target (all controls and baseline claims kept).
  minimize  needs "probe". The probe hunks (lines differing from base inside the function) are removed one at a time: first the plain
            removal, else a beam search (depth --depth, default 2) over natural mutations of the state WITHOUT the probe, restricted to
            +-window characters around where the probe was. A state that matches with fewer probes replaces the current one.
Outputs in --out (default W/analysis/level2/agents/s1_mutate/<name>/): log.json (every compiled mutant: label, score, hash), edits.json
(exact [old,new] edit lists of the best states against base: key "best" = the best/winning state, "minimal" in minimize mode),
best.cpp (best state), claims.json (only for a verified byte-identical result), and a cache in ../_cache. A byte-identical result
is verified with the real level2_check in process on the scratch TU (read-only toward P; reports stay under --out/scheck_out) unless
--no-verify. The tool never writes into P and never runs the game. Heuristic safety: swaps and hoists use identifier-level dependency
checks; REVIEW every delivered edit for semantic faithfulness and readability before adopting it (dead probes are never final).
Operators: temp_intro temp_remove swap_adjacent decl_move decl_hoist decl_split decl_merge wrap_block unwrap_block assign_if
           comm_swap early_return ret_ternary assign_ternary null_cmp ptr_ref member_copy
"""
import argparse, builtins, collections, difflib, hashlib, json, os, random, re, shutil, subprocess, sys, time

W = r'D:\<work-root>\RedAlert2Temp'
P = r'D:\<project-folder>\Coding\RedAlert2'
VC6 = os.path.join(W, 'tools', 'portable', 'vc6')
M85 = os.path.join(P, 'src', 'm85'); RA2 = os.path.join(P, 'src', 'ra2')
OUT_ROOT = os.path.join(W, 'analysis', 'level2', 'agents', 's1_mutate')
sys.path.insert(0, os.path.join(W, 'analysis', 'level2')); sys.path.insert(0, os.path.join(W, 'tools', 'portable', 'capstone-5.0.6'))
sys.path.insert(1, os.path.join(W, 'tools'))

# ----------------------------------------------------------------------------------------------------------------- lexical helpers
def skip_lit(t, i):
    c = t[i]
    if c == '/' and t.startswith('//', i):
        j = t.find('\n', i); return len(t) if j < 0 else j
    if c == '/' and t.startswith('/*', i):
        j = t.find('*/', i + 2); return len(t) if j < 0 else j + 2
    if c == '"' or c == "'":
        j = i + 1
        while j < len(t) and t[j] != c:
            if t[j] == '\\': j += 1
            j += 1
        return j + 1
    return i


def skip_ws(t, i):
    n = len(t)
    while i < n:
        if t[i].isspace(): i += 1; continue
        j = skip_lit(t, i) if t[i] == '/' else i
        if j != i and t[i] == '/': i = j; continue
        break
    return i


def match(t, i):
    """index after the bracket that closes t[i] (one of ( [ {)"""
    d = 0; n = len(t)
    while i < n:
        j = skip_lit(t, i)
        if j != i: i = j; continue
        c = t[i]
        if c in '([{': d += 1
        elif c in ')]}':
            d -= 1
            if d == 0: return i + 1
        i += 1
    raise ValueError('unbalanced')


def stmt_end(t, i):
    """index after the ';' that ends the simple statement starting at i"""
    d = 0; n = len(t)
    while i < n:
        j = skip_lit(t, i)
        if j != i: i = j; continue
        c = t[i]
        if c in '([{': d += 1
        elif c in ')]}': d -= 1
        elif c == ';' and d <= 0: return i + 1
        i += 1
    raise ValueError('no statement end')


def word_at(t, i):
    m = re.compile(r'[A-Za-z_]\w*').match(t, i)
    return m.group(0) if m else ''


class Node:
    def __init__(s, kind, a, b): s.kind = kind; s.s = a; s.e = b; s.kids = []; s.then = s.els = s.body = None; s.hdr = None; s.kw = ''; s.elskw = None; s.parent = None


def parse_stmt(t, i):
    i = skip_ws(t, i); c = t[i]
    if c == '#':
        j = i
        while True:
            k = t.find('\n', j)
            if k < 0: k = len(t); break
            if t[k - 1] == '\\': j = k + 1; continue
            break
        return Node('pp', i, k), k
    if c == '{':
        e = match(t, i); nd = Node('block', i, e); nd.kids = parse_seq(t, i + 1, e - 1)
        for k in nd.kids: k.parent = nd
        return nd, e
    w = word_at(t, i)
    if w in ('if', 'while', 'for', 'switch'):
        j = skip_ws(t, i + len(w)); e = match(t, j)
        nd = Node(w, i, e); nd.kw = w; nd.hdr = (j + 1, e - 1)
        body, e = parse_stmt(t, e)
        if w == 'if':
            nd.then = body; body.parent = nd
            k = skip_ws(t, e)
            if word_at(t, k) == 'else':
                nd.elskw = k; els, e = parse_stmt(t, k + 4); nd.els = els; els.parent = nd
        else:
            nd.body = body; body.parent = nd
        nd.e = e; return nd, e
    if w == 'do':
        body, e = parse_stmt(t, i + 2); k = skip_ws(t, e)
        if word_at(t, k) != 'while': raise ValueError('do without while')
        k = skip_ws(t, k + 5); e = match(t, k); e = stmt_end(t, e)
        nd = Node('do', i, e); nd.body = body; body.parent = nd; return nd, e
    if w in ('case', 'default'):
        j = i; d = 0
        while True:
            jj = skip_lit(t, j)
            if jj != j: j = jj; continue
            if t[j] == ':' and t[j + 1:j + 2] != ':' and t[j - 1:j] != ':': break
            j += 1
        return Node('label', i, j + 1), j + 1
    m = re.compile(r'([A-Za-z_]\w*)\s*:(?!:)').match(t, i)
    if m and w not in ('default',) and not re.compile(r'\s*\?').search(t[max(0, i - 0):i]):
        return Node('label', i, m.end()), m.end()
    e = stmt_end(t, i)
    return Node('simple', i, e), e


def parse_seq(t, a, b):
    out = []; i = skip_ws(t, a)
    while i < b:
        nd, i = parse_stmt(t, i); out.append(nd); i = skip_ws(t, i)
    return out


def find_function(t, func):
    """-> (header_start, body_open, body_close_end) of the definition of func"""
    name = re.escape(func).replace(r'\:\:', '::')
    rx = re.compile(r'^[^\s#/*}][^\n;{]*?\b' + name + r'\s*\(', re.M)
    hits = []
    for m in rx.finditer(t):
        j = m.end() - 1
        try:
            e = match(t, j)
        except ValueError:
            continue
        k = skip_ws(t, e)
        while k < len(t) and t[k] != '{' and t[k] != ';':   # const, initializer list
            k = skip_lit(t, k) if t[k] in '/"\'' else k + 1
            if k < len(t) and t[k] == ':' and 0: break
        if k < len(t) and t[k] == '{': hits.append((m.start(), j, k))
    if len(hits) != 1:
        raise SystemExit('function %s: %d definitions found' % (func, len(hits)))
    hs, pj, bo = hits[0]
    return hs, pj, bo, match(t, bo)


# --------------------------------------------------------------------------------------------------------------- expression parser
TOK = re.compile(r'''\s+|//[^\n]*|/\*.*?\*/|(?P<num>0[xX][0-9a-fA-F]+[uUlL]*|\d+\.?\d*(?:[eE][-+]?\d+)?[fFuUlL]*|\.\d+[fF]?)|(?P<id>[A-Za-z_]\w*)|(?P<str>"(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*')|(?P<op>>>=|<<=|->|\+\+|--|<<|>>|<=|>=|==|!=|&&|\|\||\+=|-=|\*=|/=|%=|&=|\|=|\^=|::|[-+*/%&|^~!<>=?:.,()\[\]{};])''', re.S)
LEVEL = {'*': 12, '/': 12, '%': 12, '+': 11, '-': 11, '<<': 10, '>>': 10, '<': 9, '>': 9, '<=': 9, '>=': 9, '==': 8, '!=': 8, '&': 7, '^': 6, '|': 5, '&&': 4, '||': 3}
ASSIGN = {'=', '+=', '-=', '*=', '/=', '%=', '&=', '|=', '^=', '<<=', '>>='}
BUILTIN = {'int', 'char', 'short', 'long', 'float', 'double', 'unsigned', 'signed', 'bool', 'void', 'const', 'struct', 'class', 'enum'}


class EN:
    __slots__ = ('kind', 's', 'e', 'op', 'ch', 'text')
    def __init__(s, kind, a, b, op='', ch=()): s.kind = kind; s.s = a; s.e = b; s.op = op; s.ch = list(ch)


class ExprParser:
    def __init__(s, text):
        s.text = text; s.toks = []
        for m in TOK.finditer(text):
            k = m.lastgroup
            if k: s.toks.append((k, m.group(0), m.start(), m.end()))
        if sum(m.end() - m.start() for m in TOK.finditer(text)) < len(text.rstrip()) - 1:
            pass
        s.i = 0

    def pk(s, o=0):
        return s.toks[s.i + o] if s.i + o < len(s.toks) else ('eof', '', len(s.text), len(s.text))

    def is_op(s, v, o=0):
        k = s.pk(o); return k[0] == 'op' and k[1] == v

    def eat(s, v):
        if not s.is_op(v): raise ValueError('expected ' + v)
        s.i += 1

    def parse(s):
        e = s.assign()
        if s.i != len(s.toks): raise ValueError('trailing')
        return e

    def assign(s):
        l = s.ternary(); k = s.pk()
        if k[0] == 'op' and k[1] in ASSIGN:
            s.i += 1; r = s.assign(); return EN('assign', l.s, r.e, k[1], (l, r))
        return l

    def ternary(s):
        c = s.binary(0)
        if s.is_op('?'):
            s.i += 1; a = s.assign(); s.eat(':'); b = s.assign(); return EN('tern', c.s, b.e, '?', (c, a, b))
        return c

    def binary(s, minl):
        l = s.unary()
        while True:
            k = s.pk()
            if k[0] == 'op' and k[1] in LEVEL and LEVEL[k[1]] >= minl:
                s.i += 1; r = s.binary(LEVEL[k[1]] + 1); l = EN('bin', l.s, r.e, k[1], (l, r))
            else:
                return l

    def unary(s):
        k = s.pk()
        if k[0] == 'op' and k[1] in ('!', '~', '-', '+', '*', '&', '++', '--'):
            s.i += 1; o = s.unary(); return EN('un', k[2], o.e, k[1], (o,))
        if k[0] == 'id' and k[1] == 'sizeof':
            s.i += 1
            if s.is_op('('):
                a = s.pk()[2]; s.i += 1; d = 1
                while d:
                    t2 = s.pk()
                    if t2[0] == 'eof': raise ValueError('sizeof')
                    if t2[0] == 'op' and t2[1] == '(': d += 1
                    elif t2[0] == 'op' and t2[1] == ')': d -= 1
                    s.i += 1
                return EN('leaf', k[2], s.toks[s.i - 1][3])
            o = s.unary(); return EN('un', k[2], o.e, 'sizeof', (o,))
        if k[0] == 'op' and k[1] == '(':
            # cast? ( builtin-type-ish ) operand
            j = s.i + 1; d = 1; inner = []
            while d and j < len(s.toks):
                t2 = s.toks[j]
                if t2[0] == 'op' and t2[1] == '(': d += 1
                elif t2[0] == 'op' and t2[1] == ')': d -= 1
                if d: inner.append(t2[1])
                j += 1
            nxt = s.toks[j] if j < len(s.toks) else ('eof', '', 0, 0)
            castish = inner and all(x in BUILTIN or x in ('*', '&') for x in inner) or (inner and inner[-1] == '*' and all(re.match(r'\w+$|\*|::', x) for x in inner))
            if castish and nxt[0] in ('id', 'num', 'str') or (castish and nxt[0] == 'op' and nxt[1] in ('(', '-', '&', '*', '!', '~')):
                s.i = j; o = s.unary(); return EN('cast', k[2], o.e, '(cast)', (o,))
        return s.postfix()

    def postfix(s):
        p = s.primary()
        while True:
            k = s.pk()
            if k[0] == 'op' and k[1] == '(':
                s.i += 1; args = []
                if not s.is_op(')'):
                    while True:
                        args.append(s.assign())
                        if s.is_op(','): s.i += 1; continue
                        break
                e = s.pk()[3]; s.eat(')'); p = EN('call', p.s, e, '()', [p] + args)
            elif k[0] == 'op' and k[1] == '[':
                s.i += 1; ix = s.assign(); e = s.pk()[3]; s.eat(']'); p = EN('index', p.s, e, '[]', (p, ix))
            elif k[0] == 'op' and k[1] in ('.', '->'):
                s.i += 1; m = s.pk()
                if m[0] != 'id': raise ValueError('member')
                s.i += 1; p = EN('member', p.s, m[3], k[1], (p,))
            elif k[0] == 'op' and k[1] in ('++', '--'):
                s.i += 1; p = EN('post', p.s, k[3], k[1], (p,))
            else:
                return p

    def primary(s):
        k = s.pk()
        if k[0] in ('num', 'str'):
            s.i += 1; return EN('leaf', k[2], k[3])
        if k[0] == 'id':
            if k[1] in ('new', 'delete', 'throw', 'typeid', 'operator'): raise ValueError('unsupported ' + k[1])
            s.i += 1; e = k[3]
            while s.is_op('::') and s.pk(1)[0] == 'id':
                e = s.pk(1)[3]; s.i += 2
            return EN('leaf', k[2], e)
        if k[0] == 'op' and k[1] == '(':
            s.i += 1; x = s.assign(); e = s.pk()[3]; s.eat(')'); return EN('group', k[2], e, '()', (x,))
        raise ValueError('primary')


def parse_expr(text):
    try:
        return ExprParser(text).parse()
    except (ValueError, IndexError):
        return None


def walk_expr(n, path=()):
    yield n, path
    for c in n.ch: yield from walk_expr(c, path + (n,))


# --------------------------------------------------------------------------------------------------------------------- text analysis
KEYW = {'if', 'else', 'for', 'while', 'do', 'return', 'break', 'continue', 'goto', 'switch', 'case', 'default', 'new', 'delete', 'sizeof',
        'int', 'char', 'short', 'long', 'float', 'double', 'unsigned', 'signed', 'bool', 'void', 'const', 'static', 'struct', 'class', 'enum',
        'true', 'false', 'NULL', 'this', 'volatile', 'register', 'typedef', 'union', 'throw'}


def strip_lits(x):
    out = []; i = 0
    while i < len(x):
        j = skip_lit(x, i)
        out.append(' ' if j != i else x[i]); i = j if j != i else i + 1
    return ''.join(out)


def idents(x):
    return set(re.findall(r'[A-Za-z_]\w*', strip_lits(x))) - KEYW


def has_call(x):
    return bool(re.search(r'[A-Za-z_]\w*\s*\(', strip_lits(x)) and any(m.group(1) not in KEYW for m in re.finditer(r'([A-Za-z_]\w*)\s*\(', strip_lits(x)))) or '->*' in x


def has_effect(x):
    return has_call(x) or bool(re.search(r'\+\+|--|[^=!<>]=[^=]', strip_lits(x)))


def written(x):
    """identifiers possibly written by statement text x (heuristic: assigned lvalue roots, ++/--, &name, declared names)"""
    s = strip_lits(x); out = set()
    d0 = parse_decl(x)
    if d0 is not None and d0['init'] is not None:
        out.add(d0['name']); s = strip_lits(d0['init'])
    for m in re.finditer(r'(?<![=!<>])(?:=|\+=|-=|\*=|/=|%=|&=|\|=|\^=|<<=|>>=)(?!=)', s):
        j = m.start() - 1
        while j >= 0 and s[j].isspace(): j -= 1
        while j >= 0 and s[j] in ')]':    # skip balanced brackets backwards
            close = s[j]; open_ = '(' if close == ')' else '['; d = 0
            while j >= 0:
                if s[j] == close: d += 1
                elif s[j] == open_:
                    d -= 1
                    if d == 0: break
                j -= 1
            j -= 1
            while j >= 0 and s[j].isspace(): j -= 1
            while j >= 0 and (s[j].isalnum() or s[j] in '_.>-'): j -= 1;
            j2 = j
            break
        # collect the chain of the lvalue: scan left over identifier / . / -> characters and index groups
        k = m.start() - 1
        while k >= 0 and s[k].isspace(): k -= 1
        depth = 0; lo = k
        while lo >= 0:
            c = s[lo]
            if c in ')]': depth += 1
            elif c in '([':
                if depth == 0: break
                depth -= 1
            elif depth == 0 and not (c.isalnum() or c in '_.>-:' or c.isspace()): break
            elif depth == 0 and c.isspace():
                q = lo - 1
                while q >= 0 and s[q].isspace(): q -= 1
                if q >= 0 and (s[q].isalnum() or s[q] == '_') and (s[lo + 1:k + 1].lstrip()[:1].isalnum() or s[lo + 1:k + 1].lstrip()[:1] == '_'): break   # `Type name`: stop at the declared name
            lo -= 1
        chain = s[lo + 1:k + 1]
        r = re.match(r'\s*\**\s*([A-Za-z_]\w*)', chain)
        if r: out.add(r.group(1))
        for r in re.finditer(r'[A-Za-z_]\w*', chain): out.add(r.group(0))
    for m in re.finditer(r'([A-Za-z_]\w*)\s*(?:\+\+|--)|(?:\+\+|--)\s*([A-Za-z_]\w*)', s): out.add(m.group(1) or m.group(2))
    for m in re.finditer(r'&\s*([A-Za-z_]\w*)', s): out.add(m.group(1))
    d = parse_decl(x)
    if d: out.add(d['name'])
    return out - KEYW


DECL = re.compile(r'^\s*(?P<type>(?:(?:const|unsigned|signed|static|struct|class|enum|volatile|register)\s+)*[A-Za-z_]\w*(?:::\w+)*(?:\s*<[^;()=]*>)?(?:\s+const)?)(?P<ptr>(?:\s*[*&])*)(?:\s+|(?<=[*&]))(?P<name>[A-Za-z_]\w*)\s*(?P<rest>(?:=.*|\(.*\)|\[.*\])?)\s*;?\s*$', re.S)
NOTDECL = {'return', 'delete', 'else', 'goto', 'case', 'new', 'throw', 'sizeof', 'typedef', 'break', 'continue', 'default', 'do'}


def parse_decl(x):
    x = x.strip()
    m = DECL.match(strip_lits(x)) if x else None
    if not m: return None
    first = m.group('type').split()[0]
    if first in NOTDECL or m.group('name') in KEYW: return None
    if m.group('type').strip() in ('else', 'return'): return None
    # the original (non-stripped) pieces
    rest = x[m.start('rest'):m.end('rest')].strip().rstrip(';').strip()
    return dict(type=x[m.start('type'):m.end('type')].strip(), ptr=m.group('ptr').replace(' ', ''), name=m.group('name'), rest=rest,
                init=rest[1:].strip() if rest.startswith('=') else None)


def builtinish(typ, ptr):
    toks = typ.replace('const', ' ').split()
    return bool(ptr and '*' in ptr and '&' not in ptr) or (all(t in ('int', 'unsigned', 'signed', 'char', 'short', 'long', 'float', 'double', 'bool') for t in toks) and '&' not in (ptr or ''))


def uses(name, x):
    return re.search(r'(?<![\w.])' + re.escape(name) + r'\b', strip_lits(x)) is not None


def independent(a, b):
    """heuristic: may the two simple statements be exchanged"""
    for x in (a, b):
        if re.search(r'\b(return|goto|break|continue|delete|throw)\b', x): return False
    if has_call(a) and has_call(b): return False
    wa, wb = written(a), written(b)
    ia, ib = idents(a), idents(b)
    if (wa & ib) or (wb & ia): return False
    da, db = parse_decl(a), parse_decl(b)
    if da and db and da['name'] == db['name']: return False
    return True


class Ctx:
    def __init__(c, t, bo, be, region=None):
        c.t = t; c.bo = bo; c.be = be; c.region = region
        c.root = parse_seq(t, bo + 1, be - 1)
        for n in c.root: n.parent = None
        c.seqs = []; c.nodes = []
        c._collect(c.root, None, 0)
        names = set()
        for m in re.finditer(r'\b[A-Za-z_]\w*\b\s*\*+\s*([A-Za-z_]\w*)', t[c.hs():be] if hasattr(c, 'hs') else t[bo:be]): names.add(m.group(1))
        c.ptrnames = names

    def hs(c): return c.bo

    def _collect(c, seq, owner, depth):
        c.seqs.append((seq, owner, depth))
        for n in seq:
            c._walk(n, depth)

    def _walk(c, n, depth):
        c.nodes.append(n)
        if n.kind == 'block':
            c._collect(n.kids, n, depth + 1)
        for ch in (n.then, n.els, n.body):
            if ch is not None: c._walk(ch, depth + 1)

    def txt(c, n): return c.t[n.s:n.e]

    def ok(c, a, b):
        return c.region is None or (a < c.region[1] and b > c.region[0])

    def line_span(c, n):
        t = c.t; a = n.s; b = n.e
        la = t.rfind('\n', 0, a) + 1
        if t[la:a].strip() == '': a = la
        lb = t.find('\n', b); lb = len(t) if lb < 0 else lb
        if t[b:lb].strip() == '': b = min(len(t), lb + 1)
        return a, b

    def indent(c, n):
        la = c.t.rfind('\n', 0, n.s) + 1
        m = re.match(r'[ \t]*', c.t[la:n.s]); return m.group(0) if c.t[la:n.s].strip() == '' else ''


def apply_splices(t, sp):
    sp = sorted(sp, key=lambda x: (x[0], x[1]), reverse=True)
    for a, b, new in sp: t = t[:a] + new + t[b:]
    return t


def overlaps(sp):
    s = sorted(sp)
    return any(s[i][1] > s[i + 1][0] for i in range(len(s) - 1))


# ------------------------------------------------------------------------------------------------------------------------- operators
OPS = {}
def op(f): OPS[f.__name__[3:]] = f; return f


def stmt_exprs(c, n):
    """expression spans (absolute) of a node: list of (kind, a, b); simple: init / rhs / whole; if/switch: condition; return: operand"""
    t = c.t; out = []
    if n.kind in ('if', 'switch'):
        out.append(('cond', n.hdr[0], n.hdr[1]))
    elif n.kind == 'simple':
        x = c.txt(n); body = x[:-1] if x.endswith(';') else x
        d = parse_decl(x)
        if d and d['init'] is not None:
            a = n.s + body.index('=', body.find(d['name'])) + 1; out.append(('init', a, n.s + len(body)))
        elif d is None:
            m = re.match(r'\s*return\b', body)
            if m: out.append(('ret', n.s + m.end(), n.s + len(body)))
            else:
                p = parse_expr(body)
                if p is not None and p.kind == 'assign' and p.op == '=':
                    out.append(('rhs', n.s + p.ch[1].s, n.s + p.ch[1].e))
                elif p is not None:
                    out.append(('expr', n.s + p.s, n.s + p.e))
    return out


@op
def op_comm_swap(c):
    for n in c.nodes:
        for kind, a, b in stmt_exprs(c, n):
            if not c.ok(a, b): continue
            x = c.t[a:b]; e = parse_expr(x)
            if e is None: continue
            for node, path in walk_expr(e):
                if node.kind == 'bin' and node.op in ('+', '*', '==', '!='):
                    L, R = node.ch
                    if has_effect(x[L.s:L.e]) and has_effect(x[R.s:R.e]): continue
                    lt, rt = x[L.s:L.e], x[R.s:R.e]
                    if L.kind == 'bin' and LEVEL[L.op] <= LEVEL[node.op]: lt = '(' + lt + ')'
                    new = rt + x[L.e:R.s] + lt
                    yield 'comm_swap %s: %s' % (node.op, (x[node.s:node.e])[:50].replace('\n', ' ')), [(a + node.s, a + node.e, new)]


@op
def op_swap_adjacent(c):
    for seq, owner, depth in c.seqs:
        for p, q in zip(seq, seq[1:]):
            if p.kind == 'simple' and q.kind == 'simple' and c.ok(p.s, q.e) and independent(c.txt(p), c.txt(q)):
                yield 'swap_adjacent: %s <-> %s' % (c.txt(p)[:30].replace('\n', ' '), c.txt(q)[:30].replace('\n', ' ')), [(p.s, p.e, c.txt(q)), (q.s, q.e, c.txt(p))]


def _move_edit(c, n, before):
    """splices moving simple node n to just before node `before` (same or other seq)"""
    a, b = c.line_span(n)
    ind = c.indent(before)
    return [(a, b, ''), (before.s - len(ind) if c.t[before.s - len(ind):before.s] == ind else before.s, before.s - len(ind) if c.t[before.s - len(ind):before.s] == ind else before.s, ind + c.txt(n) + '\n')]


@op
def op_decl_move(c):
    """move a declaration to just before its first use, or to the start of its scope"""
    for seq, owner, depth in c.seqs:
        for i, n in enumerate(seq):
            if n.kind != 'simple' or not c.ok(n.s, n.e): continue
            d = parse_decl(c.txt(n))
            if not d: continue
            first = next((k for k in range(i + 1, len(seq)) if uses(d['name'], c.t[seq[k].s:seq[k].e])), None)
            if first is not None and first > i + 1 and all(seq[k].kind == 'simple' and independent(c.txt(n), c.txt(seq[k])) for k in range(i + 1, first)):
                yield 'decl_move %s later (before %s)' % (d['name'], c.txt(seq[first])[:30].replace('\n', ' ')), _ins_before(c, n, seq[first])
            if i > 0:
                k0 = 0
                if all(seq[k].kind == 'simple' and independent(c.txt(n), c.txt(seq[k])) for k in range(k0, i)):
                    if i - k0 > 1: yield 'decl_move %s to scope start' % d['name'], _ins_before(c, n, seq[k0])


def _ins_before(c, n, before):
    a, b = c.line_span(n); ind = c.indent(before)
    pos = before.s - len(ind) if c.t[before.s - len(ind):before.s] == ind and ind != '' or c.t[c.t.rfind('\n', 0, before.s) + 1:before.s].strip() == '' else before.s
    pos = c.t.rfind('\n', 0, before.s) + 1 if c.t[c.t.rfind('\n', 0, before.s) + 1:before.s].strip() == '' else before.s
    return [(a, b, ''), (pos, pos, (ind if pos != before.s else '') + c.txt(n) + '\n' + ('' if pos != before.s else ind))]


@op
def op_decl_hoist(c):
    """block-local declaration -> function scope (declaration without initializer; with one: `T x;` at the top + assignment in place)"""
    top = c.root
    if not top: return
    names_all = collections.Counter()
    for nn in c.nodes:
        if nn.kind == 'simple':
            d = parse_decl(c.txt(nn))
            if d: names_all[d['name']] += 1
    for seq, owner, depth in c.seqs:
        if depth == 0: continue
        for n in seq:
            if n.kind != 'simple' or not c.ok(n.s, n.e): continue
            d = parse_decl(c.txt(n))
            if not d or names_all[d['name']] != 1 or d['rest'].startswith('(') or d['rest'].startswith('['): continue
            if d['init'] is None:
                a, b = c.line_span(n); ind = c.indent(top[0])
                pos = c.t.rfind('\n', 0, top[0].s) + 1
                yield 'decl_hoist %s to function scope' % d['name'], [(a, b, ''), (pos, pos, ind + c.txt(n) + '\n')]
            elif builtinish(d['type'], d['ptr']):
                ind = c.indent(top[0]); pos = c.t.rfind('\n', 0, top[0].s) + 1
                head = d['type'] + (' ' if not d['ptr'] else ' ' + d['ptr']) + d['name'] + ';'
                yield 'decl_hoist %s to function scope (split)' % d['name'], [(n.s, n.e, d['name'] + ' = ' + d['init'] + ';'), (pos, pos, ind + head + '\n')]


@op
def op_decl_split(c):
    for n in c.nodes:
        if n.kind != 'simple' or not c.ok(n.s, n.e): continue
        d = parse_decl(c.txt(n))
        if d and d['init'] is not None and builtinish(d['type'], d['ptr']) and '&' not in d['ptr']:
            ind = c.indent(n)
            yield 'decl_split %s' % d['name'], [(n.s, n.e, d['type'] + (' ' + d['ptr'] if d['ptr'] else ' ') + d['name'] + ';\n' + ind + d['name'] + ' = ' + d['init'] + ';')]


@op
def op_decl_merge(c):
    for seq, owner, depth in c.seqs:
        for p, q in zip(seq, seq[1:]):
            if p.kind == 'simple' and q.kind == 'simple' and c.ok(p.s, q.e):
                d = parse_decl(c.txt(p))
                if d and d['rest'] == '':
                    m = re.match(r'\s*' + re.escape(d['name']) + r'\s*=(?!=)\s*(.*);\s*$', c.txt(q), re.S)
                    if m:
                        yield 'decl_merge %s' % d['name'], [(p.s, q.e, d['type'] + (' ' + d['ptr'] if d['ptr'] else ' ') + d['name'] + ' = ' + m.group(1) + ';')]


@op
def op_wrap_block(c):
    for seq, owner, depth in c.seqs:
        for i, n in enumerate(seq):
            if not c.ok(n.s, n.e): continue
            # a run of 1..2 non-declaration simple statements
            for k in (1, 2):
                run = seq[i:i + k]
                if len(run) == k and all(x.kind == 'simple' and not parse_decl(c.txt(x)) for x in run):
                    ind = c.indent(n)
                    yield 'wrap_block %d stmt(s) at %s' % (k, c.txt(n)[:30].replace('\n', ' ')), [(run[0].s, run[0].s, '{\n' + ind + '\t'), (run[-1].e, run[-1].e, '\n' + ind + '}')]
            # a declaration plus the statements up to its last use, when later statements do not use it
            if n.kind == 'simple':
                d = parse_decl(c.txt(n))
                if d:
                    last = max([k for k in range(i + 1, len(seq)) if uses(d['name'], c.t[seq[k].s:seq[k].e])] or [i])
                    if last > i and last < len(seq) - 1 or (last > i and owner is None and False):
                        ind = c.indent(n)
                        yield 'wrap_block scope of %s' % d['name'], [(n.s, n.s, '{\n' + ind + '\t'), (seq[last].e, seq[last].e, '\n' + ind + '}')]


@op
def op_unwrap_block(c):
    for seq, owner, depth in c.seqs:
        for n in seq:
            if n.kind == 'block' and c.ok(n.s, n.e):
                inner = c.t[n.s + 1:n.e - 1]
                if any(parse_decl(c.txt(k)) for k in n.kids if k.kind == 'simple') and False: continue
                yield 'unwrap_block', [(n.s, n.e, inner.strip('\n').replace('\n\t', '\n', 1) if False else inner.strip())]


@op
def op_assign_if(c):
    for seq, owner, depth in c.seqs:
        for p, q in zip(seq, seq[1:]):
            if not c.ok(p.s, q.e): continue
            if p.kind == 'simple' and q.kind == 'if':
                m = re.match(r'\s*([A-Za-z_][\w.>\-\[\]]*)\s*=(?!=)\s*([^;]+?)\s*;\s*$', c.txt(p), re.S)
                if not m or parse_decl(c.txt(p)): continue
                L, R = m.group(1), m.group(2)
                cs, ce = q.hdr; cond = c.t[cs:ce]
                m2 = re.match(r'(\s*!?\s*)' + re.escape(L) + r'(?![\w.>\[(\-])(.*)$', cond, re.S)
                if m2:
                    pre, rest = m2.group(1), m2.group(2)
                    yield 'assign_if: fold `%s = ...;` into the if' % L, [(*c.line_span(p), ''), (cs, ce, pre + '(' + L + ' = ' + R + ')' + rest)]
            if q.kind == 'if' and False: pass
    for n in c.nodes:
        if n.kind == 'if' and c.ok(n.s, n.e) and n.parent is not None or n.kind == 'if' and n.parent is None and c.ok(n.s, n.e):
            if n.parent is not None and n.parent.kind == 'if' and n.parent.els is n: continue
            if n.parent is not None and n.parent.kind not in ('block',) and n.parent.kind != 'if': pass
            cs, ce = n.hdr; cond = c.t[cs:ce]
            m = re.match(r'\s*(!?)\s*\(', cond)
            if not m: continue
            g0 = m.end() - 1
            try: g1 = match(cond, g0)
            except ValueError: continue
            inner = cond[g0 + 1:g1 - 1]; rest = cond[g1:]
            m3 = re.match(r'\s*([A-Za-z_][\w.>\-\[\]]*)\s*=(?!=)\s*(.+)$', inner, re.S)
            if not m3 or has_call(m3.group(1)): continue
            L, R = m3.group(1), m3.group(2).strip()
            if n.parent is not None and n.parent.kind == 'block' or n.parent is None or n.parent.kind in ('if', 'while', 'for', 'do', 'switch'):
                if n.parent is not None and n.parent.kind in ('while', 'for', 'do'): continue
                ind = c.indent(n)
                a = c.t.rfind('\n', 0, n.s) + 1
                yield 'assign_if: unfold `if ((%s = ...))`' % L, [(cs, ce, m.group(1) + L + rest), (n.s, n.s, L + ' = ' + R + ';\n' + ind)] if c.t[a:n.s].strip() == '' else []


@op
def op_early_return(c):
    for seq, owner, depth in c.seqs:
        for i, n in enumerate(seq):
            if n.kind != 'if' or not c.ok(n.s, n.e): continue
            then = n.then
            tl = then.kids[-1] if then.kind == 'block' and then.kids else then
            ends_ret = tl.kind == 'simple' and re.match(r'\s*return\b', c.txt(tl))
            ends_jump = tl.kind == 'simple' and re.match(r'\s*(return|goto|break|continue)\b', c.txt(tl))
            if n.els is None and ends_ret and i + 1 < len(seq) and all(k.kind != 'label' and k.kind != 'pp' for k in seq[i + 1:]) and depth >= 0:
                ind = c.indent(n)
                yield 'early_return -> if/else: %s' % c.t[n.hdr[0]:n.hdr[1]][:40], [(n.e, n.e, ' else {'), (seq[-1].e, seq[-1].e, '\n' + ind + '}')]
            if n.els is not None and n.els.kind == 'block' and ends_jump:
                inner = c.t[n.els.s + 1:n.els.e - 1].strip('\n')
                yield 'if/else -> early return: %s' % c.t[n.hdr[0]:n.hdr[1]][:40], [(n.elskw, n.e, inner.strip())]


@op
def op_ret_ternary(c):
    for seq, owner, depth in c.seqs:
        for p, q in zip(seq, seq[1:]):
            if p.kind == 'if' and p.els is None and q.kind == 'simple' and c.ok(p.s, q.e):
                tl = p.then.kids[0] if p.then.kind == 'block' and len(p.then.kids) == 1 else (p.then if p.then.kind == 'simple' else None)
                mq = re.match(r'\s*return\b\s*(.+);\s*$', c.txt(q), re.S)
                mt = re.match(r'\s*return\b\s*(.+);\s*$', c.txt(tl), re.S) if tl is not None else None
                if mq and mt:
                    yield 'ret_ternary fold', [(p.s, q.e, 'return((%s) ? %s : %s);' % (c.t[p.hdr[0]:p.hdr[1]], mt.group(1), mq.group(1)))]
    for n in c.nodes:
        if n.kind == 'simple' and c.ok(n.s, n.e):
            m = re.match(r'\s*return\b\s*(.+);\s*$', c.txt(n), re.S)
            if not m: continue
            x = m.group(1).strip(); e = parse_expr(x)
            if e is not None and e.kind == 'group': x = x[e.ch[0].s:e.ch[0].e]; e = parse_expr(x)
            if e is None or e.kind != 'tern': continue
            c0, a0, b0 = e.ch; ind = c.indent(n)
            cond = x[c0.ch[0].s:c0.ch[0].e] if c0.kind == 'group' else x[c0.s:c0.e]
            yield 'ret_ternary unfold', [(n.s, n.e, 'if (%s) {\n%s\treturn(%s);\n%s}\n%sreturn(%s);' % (cond, ind, x[a0.s:a0.e], ind, ind, x[b0.s:b0.e]))]


@op
def op_assign_ternary(c):
    for n in c.nodes:
        if n.kind == 'if' and n.els is not None and c.ok(n.s, n.e):
            def single(x):
                if x.kind == 'block' and len(x.kids) == 1: x = x.kids[0]
                return x if x.kind == 'simple' else None
            a, b = single(n.then), single(n.els)
            if a is None or b is None: continue
            ma = re.match(r'\s*([A-Za-z_][\w.>\-\[\]]*)\s*=(?!=)\s*([^;]+);\s*$', c.txt(a), re.S)
            mb = re.match(r'\s*([A-Za-z_][\w.>\-\[\]]*)\s*=(?!=)\s*([^;]+);\s*$', c.txt(b), re.S)
            if ma and mb and ma.group(1) == mb.group(1) and not parse_decl(c.txt(a)):
                yield 'assign_ternary fold %s' % ma.group(1), [(n.s, n.e, '%s = (%s) ? %s : %s;' % (ma.group(1), c.t[n.hdr[0]:n.hdr[1]], ma.group(2).strip(), mb.group(2).strip()))]
    for seq, owner, depth in c.seqs:
        for p, q in zip(seq, seq[1:]):
            if p.kind == 'simple' and q.kind == 'if' and q.els is None and c.ok(p.s, q.e):
                d = parse_decl(p and c.txt(p))
                if not d or d['init'] is None or has_effect(d['init']): continue
                tl = q.then.kids[0] if q.then.kind == 'block' and len(q.then.kids) == 1 else (q.then if q.then.kind == 'simple' else None)
                if tl is None: continue
                m = re.match(r'\s*' + re.escape(d['name']) + r'\s*=(?!=)\s*([^;]+);\s*$', c.txt(tl), re.S)
                if m:
                    yield 'assign_ternary decl %s' % d['name'], [(p.s, q.e, '%s %s%s = (%s) ? %s : %s;' % (d['type'], d['ptr'] + ' ' if d['ptr'] else '', d['name'], c.t[q.hdr[0]:q.hdr[1]], m.group(1).strip(), d['init']))]
    for n in c.nodes:
        if n.kind == 'simple' and c.ok(n.s, n.e):
            d = parse_decl(c.txt(n))
            tgt = None
            if d and d['init'] is not None:
                e = parse_expr(d['init']); lhs = d['name']
                if e is not None and e.kind == 'tern' and builtinish(d['type'], d['ptr']):
                    c0, a0, b0 = e.ch; ind = c.indent(n); x = d['init']
                    yield 'assign_ternary unfold decl %s' % d['name'], [(n.s, n.e, '%s %s%s;\n%sif (%s) {\n%s\t%s = %s;\n%s} else {\n%s\t%s = %s;\n%s}' % (d['type'], d['ptr'] + ' ' if d['ptr'] else '', d['name'], ind, x[c0.s:c0.e].strip().strip('()') if c0.kind == 'group' else x[c0.s:c0.e], ind, d['name'], x[a0.s:a0.e], ind, ind, d['name'], x[b0.s:b0.e], ind))]
            elif not d:
                m = re.match(r'(\s*)([A-Za-z_][\w.>\-\[\]]*)\s*=(?!=)\s*(.+);\s*$', c.txt(n), re.S)
                if m:
                    e = parse_expr(m.group(3))
                    if e is not None and e.kind == 'tern':
                        c0, a0, b0 = e.ch; ind = c.indent(n); x = m.group(3)
                        cond = x[c0.s:c0.e]
                        if c0.kind == 'group': cond = x[c0.ch[0].s:c0.ch[0].e]
                        yield 'assign_ternary unfold %s' % m.group(2), [(n.s, n.e, 'if (%s) {\n%s\t%s = %s;\n%s} else {\n%s\t%s = %s;\n%s}' % (cond, ind, m.group(2), x[a0.s:a0.e], ind, ind, m.group(2), x[b0.s:b0.e], ind))]


@op
def op_null_cmp(c):
    for n in c.nodes:
        if n.kind in ('if', 'while') and c.ok(n.s, n.e):
            cs, ce = n.hdr; cond = c.t[cs:ce]
            # top-level && / || operand split
            parts = []; d = 0; last = 0; i = 0
            while i < len(cond):
                j = skip_lit(cond, i)
                if j != i: i = j; continue
                ch = cond[i]
                if ch in '([': d += 1
                elif ch in ')]': d -= 1
                elif d == 0 and cond.startswith(('&&', '||'), i):
                    parts.append((last, i)); last = i + 2; i += 2; continue
                i += 1
            parts.append((last, len(cond)))
            for a, b in parts:
                o = cond[a:b]; st = o.strip(); lead = a + (len(o) - len(o.lstrip()))
                if not st: continue
                m = re.match(r'^(.+?)\s*!=\s*(NULL|0)$', st, re.S)
                if m and re.match(r'^[\w.>\-\[\]]+$', m.group(1)): yield 'null_cmp: drop != %s' % m.group(2), [(cs + lead, cs + lead + len(st), m.group(1))]
                m = re.match(r'^(.+?)\s*==\s*(NULL|0)$', st, re.S)
                if m and re.match(r'^[\w.>\-\[\]]+$', m.group(1)): yield 'null_cmp: == %s -> !' % m.group(2), [(cs + lead, cs + lead + len(st), '!' + m.group(1))]
                m = re.match(r'^!\s*([\w.>\-\[\]]+)$', st)
                if m:
                    root = re.match(r'\w+', m.group(1)).group(0)
                    yield 'null_cmp: ! -> == %s' % ('NULL' if root in c.ptrnames or '->' in m.group(1) else '0'), [(cs + lead, cs + lead + len(st), m.group(1) + ' == ' + ('NULL' if root in c.ptrnames or '->' in m.group(1) else '0'))]
                m = re.match(r'^([\w.>\-\[\]]+)$', st)
                if m and not re.match(r'^\d', st):
                    root = re.match(r'\w+', st).group(0)
                    yield 'null_cmp: x -> x != %s' % ('NULL' if root in c.ptrnames else '0'), [(cs + lead, cs + lead + len(st), st + ' != ' + ('NULL' if root in c.ptrnames else '0'))]


@op
def op_ptr_ref(c):
    for seq, owner, depth in c.seqs:
        for i, n in enumerate(seq):
            if n.kind != 'simple' or not c.ok(n.s, n.e): continue
            d = parse_decl(c.txt(n))
            if not d or d['init'] is None: continue
            rest_end = seq[-1].e; rest = c.t[n.e:rest_end]
            if d['ptr'] == '*' and d['init'].startswith('&'):
                init = d['init'][1:].strip()
                if re.search(r'(?<![\w.])' + re.escape(d['name']) + r'\b(?!\s*->)', rest) : continue
                if not uses(d['name'], rest): continue
                new_rest = re.sub(r'(?<![\w.])' + re.escape(d['name']) + r'\s*->', d['name'] + '.', rest)
                yield 'ptr_ref: %s* -> %s&' % (d['type'], d['name']), [(n.s, n.e, '%s & %s = %s;' % (d['type'], d['name'], init)), (n.e, rest_end, new_rest)]
            elif d['ptr'] == '&':
                if re.search(r'(?<![\w.])' + re.escape(d['name']) + r'\b(?!\s*\.)', rest): continue
                if not uses(d['name'], rest): continue
                new_rest = re.sub(r'(?<![\w.])' + re.escape(d['name']) + r'\s*\.', d['name'] + '->', rest)
                yield 'ptr_ref: %s& -> %s*' % (d['type'], d['name']), [(n.s, n.e, '%s * %s = &%s;' % (d['type'], d['name'], d['init'].rstrip())), (n.e, rest_end, new_rest)]


@op
def op_temp_remove(c):
    for seq, owner, depth in c.seqs:
        for i, n in enumerate(seq):
            if n.kind != 'simple' or not c.ok(n.s, n.e): continue
            d = parse_decl(c.txt(n))
            if not d or d['init'] is None or d['ptr'] == '&' or d['rest'].startswith('('): continue
            rest = c.t[n.e:seq[-1].e]
            if len(re.findall(r'(?<![\w.])' + re.escape(d['name']) + r'\b', strip_lits(rest))) != 1: continue
            if d['name'] in written(rest) or re.search(r'&\s*' + re.escape(d['name']) + r'\b', rest): continue
            k = next((k for k in range(i + 1, len(seq)) if uses(d['name'], c.t[seq[k].s:seq[k].e])), None)
            if k is None: continue
            tgt = seq[k]
            # no loop between the declaration and the use, evaluation order must be kept
            if tgt.kind in ('for', 'while', 'do'): continue
            m = re.search(r'(?<![\w.])' + re.escape(d['name']) + r'\b', c.t[tgt.s:tgt.e])
            pos = tgt.s + m.start()
            if any(l.s <= pos < l.e for l in c.nodes if l.kind in ('for', 'while', 'do') and l.s >= tgt.s and l.s <= pos): continue
            mid = [seq[x] for x in range(i + 1, k)]
            if any(has_effect(c.txt(x)) or (written(c.txt(x)) & idents(d['init'])) for x in mid if x.kind == 'simple') or any(x.kind != 'simple' for x in mid): continue
            if has_effect(d['init']) and has_call(c.t[tgt.s:pos]): continue
            e = parse_expr(d['init']); init = d['init'].strip()
            if e is not None and e.kind in ('bin', 'tern', 'assign', 'cast', 'un'): init = '(' + init + ')'
            a, b = c.line_span(n)
            yield 'temp_remove %s' % d['name'], [(a, b, ''), (pos, pos + len(d['name']), init)]


_typemem = {}
_typeprobe = None   # set by main: function(text_with_probes_builder)


def infer_types(c, cands):
    """cands: list of (stmt_node, expr_text); -> {expr_text: type or None} using one -Zs compile with `char * p = (expr);` probes"""
    need = [(n, e) for n, e in cands if e not in _typemem]
    seen = set(); need = [(n, e) for n, e in need if not (e in seen or seen.add(e))]
    for k in range(0, len(need), 40):
        chunk = need[k:k + 40]; sp = []; lines = {}
        for idx, (n, e) in enumerate(chunk):
            sp.append((n.s, n.s, 'char * l2probe%d_ = (%s); ' % (idx, e)))
        text = apply_splices(c.t, sp)
        errs = _typeprobe(text)
        for idx, (n, e) in enumerate(chunk):
            m = re.search(r'l2probe%d_\b' % idx, text)
            ln = text.count('\n', 0, m.start()) + 1 if m else -1
            ty = None
            for el, msg in errs:
                if el == ln:
                    mm = re.search(r"cannot convert from '([^']+)' to 'char \*'", msg)
                    if mm: ty = mm.group(1)
                    break
            if ty is None and not any(el == ln for el, _ in errs): ty = 'char *'
            if ty:
                ty = re.sub(r'\b(class|struct|union|enum)\s+', '', ty).strip()
                if ty in ('void',) or '(' in ty: ty = None
            _typemem[e] = ty
    return {e: _typemem.get(e) for n, e in cands}


def temp_candidates(c, only_member=False):
    """(stmt node, expression text, span a, b, use-kind) of subexpressions that could become a named local"""
    out = []
    for n in c.nodes:
        if not c.ok(n.s, n.e) or n.kind not in ('simple', 'if', 'switch'): continue
        if n.kind == 'simple' and parse_decl(c.txt(n)) and parse_decl(c.txt(n))['init'] is None: continue
        if n.parent is not None and n.parent.kind == 'if' and n.parent.els is n: continue
        if n.parent is not None and n.parent.kind in ('while', 'for', 'do') and n.kind != 'simple': continue
        for kind, a, b in stmt_exprs(c, n):
            x = c.t[a:b]; e = parse_expr(x)
            if e is None: continue
            calls_before = lambda pos: bool(re.search(r'[A-Za-z_]\w*\s*\(', strip_lits(x[:pos]))) and has_effect(x[:pos])
            for node, path in walk_expr(e):
                if node is e and kind in ('expr',): continue
                if any(p.kind == 'bin' and p.op in ('&&', '||') and p.ch[1] is (path[i + 1] if i + 1 < len(path) else node) for i, p in enumerate(path)): continue
                if any(p.kind == 'tern' and (p.ch[1] is (path[i + 1] if i + 1 < len(path) else node) or p.ch[2] is (path[i + 1] if i + 1 < len(path) else node)) for i, p in enumerate(path)): continue
                if any(p.kind in ('un',) and p.op in ('&', '++', '--', 'sizeof') for p in path) or any(p.kind == 'post' for p in path): continue
                if any(p.kind == 'assign' and p.ch[0] is (path[i + 1] if i + 1 < len(path) else node) for i, p in enumerate(path)): continue
                if any(p.kind == 'member' and p.op == '.' for p in path) and node.kind == 'call': pass
                if node.kind not in (('member',) if only_member else ('call', 'bin', 'member', 'group')): continue
                if only_member and node.op not in ('->', '.'): continue
                if node.kind == 'bin' and node.op in LEVEL and LEVEL[node.op] < 9: continue
                if node.kind == 'call' and node.ch[0].kind not in ('leaf', 'member'): continue
                if node.kind == 'group' and node.ch[0].kind not in ('bin',): continue
                if node.kind == 'bin' and path and path[-1].kind == 'group' and False: continue
                if node.kind == 'bin' and path and path[-1].kind == 'group': continue
                if calls_before(node.s) and has_effect(x[node.s:node.e]): continue
                sub = x[node.s:node.e]
                if node.kind == 'group': sub = sub[1:-1].strip() if False else sub
                if kind == 'rhs' and node.s == 0 and node.e == len(x.rstrip()) and False: continue
                out.append((n, sub, a + node.s, a + node.e, node.kind))
    return out


def _temp_name(c):
    k = 1
    while re.search(r'\bl2tmp%d\b' % k, c.t): k += 1
    return 'l2tmp%d' % k


@op
def op_temp_intro(c):
    cands = temp_candidates(c)
    if not cands: return
    types = infer_types(c, [(n, s) for n, s, a, b, k in cands])
    name = _temp_name(c)
    for n, sub, a, b, kind in cands:
        ty = types.get(sub)
        if not ty: continue
        ind = c.indent(n); pos = c.t.rfind('\n', 0, n.s) + 1
        if c.t[pos:n.s].strip() == '': line = (pos, ind)
        else: line = (n.s, '')
        d = '%s %s = %s;' % (ty, name, sub)
        newsub = name
        yield 'temp_intro %s %s = %s' % (ty, name, sub[:50].replace('\n', ' ')), [(a, b, newsub), (line[0], line[0], (ind if line[0] == pos else '') + d + ('\n' if line[0] == pos else ' ') + ('' if line[0] != pos else ''))]


@op
def op_member_copy(c):
    cands = temp_candidates(c, only_member=True)
    if not cands: return
    types = infer_types(c, [(n, s) for n, s, a, b, k in cands])
    name = _temp_name(c)
    for n, sub, a, b, kind in cands:
        ty = types.get(sub)
        if not ty: continue
        ind = c.indent(n); pos = c.t.rfind('\n', 0, n.s) + 1
        line = pos if c.t[pos:n.s].strip() == '' else n.s
        # all uses of the same expression text in this statement
        occ = [(n.s + m.start(), n.s + m.end()) for m in re.finditer(re.escape(sub) + r'(?![\w>])', c.t[n.s:n.e])]
        sp = [(x, y, name) for x, y in occ]
        # and in following sibling statements up to the first with a call or a write of the root identifier
        parent = n.parent.kids if n.parent is not None and n.parent.kind == 'block' else (c.root if n.parent is None else None)
        root = re.match(r'[A-Za-z_]\w*', sub)
        if parent is not None and root and n in parent and len(occ) >= 1:
            i = parent.index(n); extra = []
            for q in parent[i + 1:]:
                if q.kind != 'simple': break
                qt = c.txt(q)
                if has_call(qt) or root.group(0) in written(qt) or re.search(r'\w\s*=(?!=)', qt.split(';')[0]) and sub in qt.split('=')[0]: break
                extra += [(q.s + m.start(), q.s + m.end(), name) for m in re.finditer(re.escape(sub) + r'(?![\w>])', qt)]
            if extra:
                yield 'member_copy (scope) %s %s = %s' % (ty, name, sub[:50]), sp + extra + [(line, line, (ind if line == pos else '') + '%s %s = %s;' % (ty, name, sub) + ('\n' if line == pos else ' '))]
        yield 'member_copy %s %s = %s' % (ty, name, sub[:50]), sp + [(line, line, (ind if line == pos else '') + '%s %s = %s;' % (ty, name, sub) + ('\n' if line == pos else ' '))]


def neighbors(text, bo, be, ops, region=None):
    """-> list of (label, new_text); invalid (overlapping / unchanged / unparsable) edits are dropped"""
    try:
        c = Ctx(text, bo, be, region)
    except (ValueError, IndexError):
        return []
    out = []; seen = set()
    for name in ops:
        try:
            for label, sp in OPS[name](c):
                if not sp or overlaps([(a, b) for a, b, _ in sp]): continue
                nt = apply_splices(text, sp)
                if nt == text or nt in seen: continue
                seen.add(nt); out.append((name + ': ' + label.split(': ', 1)[-1] if label.startswith(name) is False else label, nt))
        except (ValueError, IndexError, KeyError, AttributeError, re.error):
            continue
    return out


# ---------------------------------------------------------------------------------------------------------------------- scoring
import l2match
from coffmatch import Obj, match_function


class Scorer:
    def __init__(self, spec, specdir, tag, cachedir):
        self.spec = spec
        self.preset = spec.get('preset', 'm85')
        self.flags = ['-O2', '-Ob2', '-Gr', '-GR', '-DNDEBUG', '-Gy']
        base_dir = os.path.dirname(os.path.join(specdir, spec['base']))
        if self.preset == 'm85': self.flags += ['-DWIN32', '-W0', '-I' + os.path.join(M85, 'src'), '-I' + os.path.join(M85, 'include')]
        else: self.flags += ['-I' + RA2, '-I' + base_dir]
        self.env = dict(os.environ)
        self.env['PATH'] = os.pathsep.join([os.path.join(VC6, 'VC98', 'BIN'), os.path.join(VC6, 'COMMON', 'MSDEV98', 'BIN'), self.env.get('PATH', '')])
        self.env['INCLUDE'] = os.path.join(VC6, 'VC98', 'INCLUDE') + ';' + os.path.join(VC6, 'VC98', 'ATL', 'INCLUDE')
        self.env['LIB'] = os.path.join(VC6, 'VC98', 'LIB')
        self.work = os.path.join(OUT_ROOT, tag, 'work'); os.makedirs(self.work, exist_ok=True)
        self.src = os.path.join(self.work, 'cand.cpp'); self.obj = os.path.join(self.work, 'cand.obj')
        self.targets = spec['targets']; self.controls = spec.get('controls', [])
        self.sv = 'mut2:' + hashlib.sha1(json.dumps([self.targets, self.controls, self.flags, spec['base']]).encode()).hexdigest()[:10]
        os.makedirs(cachedir, exist_ok=True)
        self.cachefile = os.path.join(cachedir, '%s_%s.jsonl' % (tag, self.sv.split(':')[1]))
        self.cache = {}
        if os.path.exists(self.cachefile):
            for line in open(self.cachefile, encoding='utf-8'):
                try: r = json.loads(line); self.cache[r['hash']] = r
                except ValueError: pass
        self.compiles = 0; self.crlf = False; self.claims = None; self.base_ok = None
        cf = os.path.join(P, 'metadata', 'level2_functions.json')
        if spec.get('claims_check'):
            self.claims = [x for x in json.load(open(cf, encoding='utf-8')) if x['tu'] == spec['tu']]

    def cl(self, src, obj, extra=()):
        lock = os.path.join(os.path.dirname(self.cachefile), 'compile.lock'); t0 = time.time()
        while True:      # one compile at a time across all runs of this tool (the disk is shared)
            try:
                fd = os.open(lock, os.O_CREAT | os.O_EXCL | os.O_WRONLY); os.close(fd); break
            except OSError:
                try:
                    if time.time() - os.path.getmtime(lock) > 900: os.remove(lock)      # stale lock of a dead run
                except OSError:
                    pass
                time.sleep(0.2)
        try:
            return self._cl(src, obj, extra)
        finally:
            try: os.remove(lock)
            except OSError: pass

    def _cl(self, src, obj, extra=()):
        return subprocess.run([os.path.join(VC6, 'VC98', 'BIN', 'CL.EXE'), '-nologo', '-c'] + self.flags + list(extra) + ['-Fo' + obj, src], env=self.env, capture_output=True, text=True, timeout=600)

    def write(self, text, path=None):
        open(path or self.src, 'wb').write((text.replace('\n', '\r\n') if self.crlf else text).encode('latin-1'))

    def syntax_errors(self, text):
        self.write(text, os.path.join(self.work, 'probe.cpp'))
        p = self.cl(os.path.join(self.work, 'probe.cpp'), os.path.join(self.work, 'probe.obj'), ['-Zs'])
        return [(int(m.group(1)), m.group(2)) for m in re.finditer(r'\((\d+)\) : error C\d+: (.*)', p.stdout + p.stderr)]

    def score_syms(self, o, pairs):
        out = []
        for needle, rva in pairs:
            names = [k for k in o.symbols if (k == needle if needle.startswith('?') else needle in k)]
            if len(names) != 1:
                out.append(dict(sym=needle, status='symbol_not_unique' if names else 'symbol_missing', bytes=10 ** 6)); continue
            rv = int(rva, 16); sec = o.function(names[0]); size = len(sec['raw'])
            r = match_function(o, names[0], l2match.orig(rv, size), 0x400000 + rv, lambda s: None)
            osz = r.get('original_size') or size
            diff = (r.get('byte_differences') or 0) + 4 * abs((r.get('size') or size) - osz)
            if r.get('status') in ('matched', 'bytes_match_bindings_open'): diff = 0
            out.append(dict(sym=names[0], status=r.get('status'), bytes=diff, size=r.get('size'), orig=osz))
        return out

    def hunks(self, o, name, rva):
        import difflib, capstone
        f = o.function(name); code = f['raw']; rel = set()
        for r in f['relocs']: rel.update(range(r[0], r[0] + 4))
        orig = l2match.orig(rva, len(code) + 32)
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        def dis(cb, mask):
            out = []
            for i in md.disasm(cb, 0):
                s = '%s %s' % (i.mnemonic, i.op_str)
                if i.mnemonic == 'nop' or s.startswith('int3'): continue
                if i.mnemonic.startswith('j') or i.mnemonic == 'call': out.append(i.mnemonic); continue
                m = re.sub(r'\[(0x[0-9a-f]+)\]', '[A]', s); m = re.sub(r', 0x[0-9a-f]{5,}$', ', A', m); m = re.sub(r'^(push|mov e..,) 0x[0-9a-f]{5,}$', r'\1 A', m)
                if mask and any(x in rel for x in range(i.address, i.address + i.size)): m = re.sub(r'\b0x[0-9a-f]+\b|\b\d+\b', 'A', m)
                out.append(m)
            return out
        a = dis(code, True); b = dis(orig, False)[:len(a) + 40]
        ops = [x for x in difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes() if x[0] != 'equal']
        if ops and ops[-1][1] == len(a): ops = ops[:-1]
        return len(ops)

    def claims_ok(self, o):
        """set of rvas of this TU's claims whose bytes match (relocation bindings are not checked here; the final verify does)"""
        ok = set()
        for f in self.claims or []:
            sym = f['symbol']
            if sym not in o.symbols and not any(x['name'] == sym for x in o.by_index.values()): continue
            try:
                rv = int(f['rva'], 16); size = len(o.function(sym)['raw'])
                r = match_function(o, sym, l2match.orig(rv, size), 0x400000 + rv, lambda s: None)
                if r['byte_differences'] == 0 and not r['relocation_problems'] and r.get('size') == r.get('original_size', r.get('size')): ok.add(f['rva'])
            except Exception:
                pass
        return ok

    def evaluate(self, text):
        h = hashlib.sha256(text.encode('latin-1')).hexdigest()[:20]
        if h in self.cache: return dict(self.cache[h], cached=True)
        self.write(text)
        if os.path.exists(self.obj): os.remove(self.obj)
        self.compiles += 1
        p = self.cl(self.src, self.obj)
        if not os.path.exists(self.obj):
            r = dict(hash=h, error='compile failed', msg=(p.stdout + p.stderr)[-300:], score=10 ** 9, hunks=10 ** 6)
        else:
            o = Obj(open(self.obj, 'rb').read())
            t = self.score_syms(o, self.targets); cc = self.score_syms(o, self.controls)
            ctl_ok = all(x['bytes'] == 0 for x in cc)
            bsc = sum(x['bytes'] for x in t)
            hn = 0
            if bsc:
                hn = sum(self.hunks(o, x['sym'], int(rv, 16)) for x, (nd, rv) in zip(t, self.targets) if x['bytes'] and x['sym'] in o.symbols)
            code = hashlib.sha1(b''.join(o.function(x['sym'])['raw'] for x in t if x['sym'] in o.symbols)).hexdigest()[:12]
            r = dict(hash=h, targets=t, controls_ok=ctl_ok, score=bsc if ctl_ok else 10 ** 8 + bsc, hunks=hn, code=code)
            if bsc == 0 and ctl_ok and self.claims is not None:
                okset = self.claims_ok(o)
                r['claims_ok'] = sorted(okset)
        r['sv'] = self.sv
        self.cache[h] = r
        open(self.cachefile, 'a', encoding='utf-8').write(json.dumps(r) + '\n')
        return r


# ------------------------------------------------------------------------------------------------------------------------ edits
def make_edits(base, new, ctx=1):
    """exact [old,new] pairs (LF text) transforming base into new, unique old strings, applied in order"""
    bl = base.split('\n'); nl = new.split('\n')
    sm = difflib.SequenceMatcher(None, bl, nl, autojunk=False)
    ops = [o for o in sm.get_opcodes() if o[0] != 'equal']
    edits = []
    for tag, i1, i2, j1, j2 in ops:
        lo, hi = i1, i2
        while True:
            a = max(0, lo - ctx if i1 == lo else lo); b = min(len(bl), hi + ctx if i2 == hi else hi)
            old = '\n'.join(bl[a:b]) if b > a else ''
            nw = '\n'.join(bl[a:i1] + nl[j1:j2] + bl[i2:b])
            if old and base.count(old) == 1: break
            if lo == 0 and hi == len(bl): break
            ctx += 1
            lo = max(0, i1 - ctx); hi = min(len(bl), i2 + ctx)
        edits.append([old, nw]); ctx = 1
    t = base
    for old, nw in edits:
        if t.count(old) != 1: return None
        t = t.replace(old, nw)
    return edits if t == new else None


def func_span(text, func):
    hs, pj, bo, be = find_function(text, func); return hs, bo, be


# ------------------------------------------------------------------------------------------------------------------------- search
def skey(r):
    """ordering: byte-identical first, then fewer masked instruction hunks (robust against size shifts), then fewer byte differences"""
    return (0 if r['score'] == 0 else 1, r.get('hunks', 0) if r['score'] else 0, r['score'])


class State:
    def __init__(s, text, res, hist, parent=None): s.text = text; s.res = res; s.hist = hist; s.key = skey(res) + (len(hist),)


def beam_search(sc, base_text, func, ops, beam, per_state, budget, rnd, log, region_fn=None, winners=None, depth=None, stop_at=1, label=''):
    t0 = sc.compiles
    r0 = sc.evaluate(base_text)
    frontier = [State(base_text, r0, [])]; seen = {r0['hash']}; best = frontier[0]; winners = winners if winners is not None else []
    if r0['score'] == 0: winners.append(frontier[0]); return best, winners
    rounds = 0
    while frontier and sc.compiles - t0 < budget and (depth is None or rounds < depth) and len(winners) < stop_at:
        rounds += 1; cand = []
        for st in frontier:
            hs, bo, be = func_span(st.text, func)
            reg = region_fn(st) if region_fn else None
            nb = neighbors(st.text, bo, be, ops, reg)
            rnd.shuffle(nb)
            for lab, nt in nb[:per_state]:
                if sc.compiles - t0 >= budget: break
                h = hashlib.sha256(nt.encode('latin-1')).hexdigest()[:20]
                if h in seen: continue
                seen.add(h)
                r = sc.evaluate(nt)
                log.append(dict(label=lab, parent=st.hist[-1] if st.hist else None, depth=len(st.hist) + 1, hash=r['hash'], score=r['score'], hunks=r.get('hunks'), err=r.get('error'), claims=len(r['claims_ok']) if 'claims_ok' in r else None))
                if r.get('error'): continue
                ns = State(nt, r, st.hist + [lab], st); cand.append(ns)
                if skey(r) < skey(best.res):
                    best = ns; print('best score %s hunks %s  (%d compiles)  %s' % (r['score'], r.get('hunks'), sc.compiles - t0, ' | '.join(ns.hist)), flush=True)
                if r['score'] == 0 and good_claims(sc, r):
                    winners.append(ns); print('MATCH after %d compiles: %s' % (sc.compiles - t0, ' | '.join(ns.hist)), flush=True)
                    if len(winners) >= stop_at: break
            if len(winners) >= stop_at: break
        if not cand: break
        rnd.shuffle(cand)
        cand.sort(key=lambda s: skey(s.res))
        frontier = []; codes = set()      # diversity: states with identical generated code are equivalent, keep the best of each first
        for st_ in cand:
            if st_.res.get('code') not in codes:
                codes.add(st_.res.get('code')); frontier.append(st_)
                if len(frontier) >= beam: break
        for st_ in cand:
            if len(frontier) >= beam: break
            if st_ not in frontier: frontier.append(st_)
        print('round %d: %d evaluated, frontier scores %s' % (rounds, len(cand), [(s.res['score'], s.res.get('hunks')) for s in frontier][:6]), flush=True)
    return best, winners


def good_claims(sc, r):
    if sc.claims is None: return True
    if sc.base_ok is None: return True
    return not (sc.base_ok - set(r.get('claims_ok', [])))


def verify_full(sc, spec, text, tag, outdir):
    """the real level2_check in process on the scratch TU (as W/analysis/level2/agents/b27_srfcache/scheck.py); read-only toward P"""
    import level2_unclaimed_scan as us, level2_check as lc
    us.OUT = os.path.join(outdir, 'scheck_out'); os.makedirs(os.path.join(us.OUT, 'obj'), exist_ok=True)
    src = os.path.join(outdir, 'verify_%s.cpp' % tag); sc.write(text, src)
    obj = os.path.join(us.OUT, 'obj', tag + '.obj')
    if os.path.exists(obj): os.remove(obj)
    p = sc.cl(src, obj)
    if p.returncode: return dict(error=(p.stdout + p.stderr)[-500:])
    o = Obj(open(obj, 'rb').read())
    extra = []
    for nd, rv in sc.targets:
        names = [k for k in o.symbols if (k == nd if nd.startswith('?') else nd in k)]
        if len(names) == 1: extra.append(dict(rva=rv, tu=spec['tu'], symbol=names[0], name=names[0]))
    info = dict(command='cl ' + ' '.join(sc.flags), returncode=0, output='')
    rep = us.scratch_check(spec['tu'], obj, info, tag, extra_claims=extra)
    bad = [f for f in rep['functions'] if f.get('status') != 'matched']
    new = [f for f in rep['functions'] if f['rva'] in {e['rva'] for e in extra}]
    return dict(matched=len(rep['functions']) - len(bad), total=len(rep['functions']), not_matched=[(f['rva'], f.get('symbol', '')[:60], f.get('status')) for f in bad][:12],
                targets=[(f['rva'], f.get('status'), f.get('byte_differences')) for f in new], conflicts=len(rep.get('symbol_conflicts') or []), extra=extra)


def main():
    ap = argparse.ArgumentParser(description='level-2 statement mutator / probe minimizer')
    ap.add_argument('spec'); ap.add_argument('--mode', default='search', choices=['search', 'minimize'])
    ap.add_argument('--max', type=int, default=300); ap.add_argument('--beam', type=int, default=4); ap.add_argument('--per-state', type=int, default=60)
    ap.add_argument('--seed', type=int, default=1); ap.add_argument('--ops'); ap.add_argument('--list-ops', action='store_true')
    ap.add_argument('--window', type=int, default=700); ap.add_argument('--depth', type=int, default=2)
    ap.add_argument('--no-verify', action='store_true'); ap.add_argument('--out'); ap.add_argument('--stop-at', type=int, default=1)
    a = ap.parse_args()
    if a.list_ops:
        print(' '.join(OPS)); return
    specfile = os.path.abspath(a.spec); spec = json.load(open(specfile, encoding='utf-8')); sdir = os.path.dirname(specfile)
    absp = lambda p: p if os.path.isabs(p) else os.path.join(sdir, p)
    tag = spec.get('name') or os.path.splitext(os.path.basename(specfile))[0]
    outdir = os.path.abspath(a.out) if a.out else os.path.join(OUT_ROOT, tag); os.makedirs(outdir, exist_ok=True)
    nP = os.path.normcase(P)
    for q in (absp(spec['base']), outdir):
        if os.path.normcase(os.path.abspath(q)).startswith(nP): raise SystemExit('refusing: %s lies inside P (use a scratch copy)' % q)
    base_raw = open(absp(spec['base']), 'rb').read().decode('latin-1')
    crlf = '\r\n' in base_raw; base = base_raw.replace('\r\n', '\n')
    sc = Scorer(spec, sdir, tag, os.path.join(OUT_ROOT, '_cache')); sc.crlf = crlf
    global _typeprobe; _typeprobe = sc.syntax_errors
    ops = a.ops.split(',') if a.ops else list(OPS)
    rnd = random.Random(a.seed); log = []; func = spec['func']
    func_span(base, func)    # fail early
    r0 = sc.evaluate(base)
    print('base: score %s hunks %s targets %s' % (r0['score'], r0.get('hunks'), [(x['status'], x['bytes']) for x in r0.get('targets', [])]), flush=True)
    if sc.claims is not None:
        sc.write(base); sc.cl(sc.src, sc.obj)
        sc.base_ok = sc.claims_ok(Obj(open(sc.obj, 'rb').read())); print('baseline claims matching: %d/%d' % (len(sc.base_ok), len(sc.claims)), flush=True)
    t0 = time.time(); result = dict(mode=a.mode, spec=specfile, base_score=r0['score'], args=vars(a)); winners = []
    if a.mode == 'search':
        best, winners = beam_search(sc, base, func, ops, a.beam, a.per_state, a.max, rnd, log, winners=[], stop_at=a.stop_at)
        final = winners[0] if winners else best; minimal = None
    else:
        probe = open(absp(spec['probe']), 'rb').read().decode('latin-1').replace('\r\n', '\n')
        rp = sc.evaluate(probe)
        print('probe state: score %s' % rp['score'], flush=True)
        if rp['score'] != 0: print('WARNING: the probe state does not match; minimizing anyway from it')
        cur = probe; cur_res = rp
        bl = base.split('\n')
        hs, bo, be = func_span(probe, func)
        # probe hunks = line opcodes between the base function text and the probe function text
        _, bbo, bbe = func_span(base, func)
        bfl = base[bbo:bbe].split('\n'); pfl = probe[bo:be].split('\n')
        hunks = []
        for o in difflib.SequenceMatcher(None, bfl, pfl, autojunk=False).get_opcodes():
            if o[0] == 'equal': continue
            if hunks and o[1] - hunks[-1][2] <= 2:     # neighbouring hunks (<= 2 unchanged lines apart) form one probe
                h = hunks[-1]; hunks[-1] = ('replace', h[1], o[2], h[3], o[4])
            else:
                hunks.append(o)
        print('%d probe hunk(s): %s' % (len(hunks), [(o[0], '\n'.join(pfl[o[3]:o[4]])[:50]) for o in hunks]), flush=True)
        probes_left = len(hunks); per = max(10, a.max // max(1, len(hunks)))
        removed = []
        for hi, (tag_, i1, i2, j1, j2) in enumerate(hunks):
            # current text of this hunk: locate by its probe lines in the current state
            hs, bo, be = func_span(cur, func); cfl = cur[bo:be].split('\n')
            ph = pfl[j1:j2]
            pos = next((k for k in range(len(cfl) - len(ph) + 1) if cfl[k:k + len(ph)] == ph), None) if ph else None
            if pos is None: print('hunk %d no longer present (already replaced); skipped' % (hi + 1)); continue
            rev_lines = cfl[:pos] + bfl[i1:i2] + cfl[pos + len(ph):]
            rev = cur[:bo] + '\n'.join(rev_lines) + cur[be:]
            rr = sc.evaluate(rev)
            print('hunk %d: plain removal -> score %s' % (hi + 1, rr['score']), flush=True)
            if rr['score'] == 0 and good_claims(sc, rr):
                cur, cur_res = rev, rr; removed.append(dict(hunk=hi + 1, how='plain removal (the probe was not needed)')); continue
            # natural replacements near the original position of the probe
            hs2, bo2, be2 = func_span(rev, func); loc = bo2 + len('\n'.join(rev_lines[:pos])) + 1
            win = (max(0, loc - a.window), loc + a.window)
            ws = []
            b2, ws = beam_search(sc, rev, func, ops, a.beam, a.per_state, per, rnd, log, region_fn=lambda st, w=win: w, winners=[], depth=a.depth, stop_at=3)
            if ws:
                ws.sort(key=lambda s: len(s.hist)); cur, cur_res = ws[0].text, ws[0].res
                removed.append(dict(hunk=hi + 1, how='replaced by natural mutation(s): ' + ' | '.join(ws[0].hist), alternatives=[' | '.join(w.hist) for w in ws[1:]]))
                print('hunk %d replaced: %s' % (hi + 1, ' | '.join(ws[0].hist)), flush=True)
            else:
                print('hunk %d: no natural replacement found (best %s)' % (hi + 1, b2.res['score']), flush=True)
        final = State(cur, cur_res, [r['how'] for r in removed]); minimal = cur
        result['removed'] = removed; winners = [final] if cur_res['score'] == 0 else []
        best = final
    result.update(compiles=sc.compiles, seconds=round(time.time() - t0, 1), best_score=final.res['score'], best_hunks=final.res.get('hunks'),
                  best_history=final.hist, matched=bool(winners), targets=final.res.get('targets'))
    edits = make_edits(base, final.text)
    json.dump(dict(best=edits, tu=spec['tu'], func=func, note='apply in order to the base TU text (LF); each old occurs exactly once'), open(os.path.join(outdir, 'edits.json'), 'w'), indent=1)
    open(os.path.join(outdir, 'best.cpp'), 'wb').write((final.text.replace('\n', '\r\n') if crlf else final.text).encode('latin-1'))
    if winners and not a.no_verify:
        v = verify_full(sc, spec, final.text, tag, outdir); result['verify'] = v
        print('full verify:', json.dumps(v)[:600], flush=True)
        if 'error' not in v and v['targets'] and all(t[1] == 'matched' for t in v['targets']) and not any(x[2] == 'not_matched' for x in v['not_matched']) and not v['conflicts']:
            extra = v['extra']
            json.dump(dict(tu=spec['tu'], functions=[dict(rva=e['rva'], symbol=e['symbol'], name=spec.get('func', e['name']), status='matched') for e in extra], symbols={},
                           open=['S1 level2_mutate (%s): %s' % (a.mode, ' | '.join(final.hist))]), open(os.path.join(outdir, 'claims.json'), 'w'), indent=1)
    json.dump(dict(result=result, mutants=log), open(os.path.join(outdir, 'log.json'), 'w'), indent=1)
    print(json.dumps({k: result[k] for k in ('compiles', 'seconds', 'best_score', 'best_hunks', 'matched', 'best_history')}, indent=1))
    print('outputs:', outdir)


if __name__ == '__main__':
    main()
