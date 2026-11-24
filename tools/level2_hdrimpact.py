"""Header impact for level-2 header checks: which claimed TUs can see a header (conservative include closure).

usage: python -I level2_hdrimpact.py <header> [<header> ...] [--all-tus] [--json OUT]
       python -I level2_hdrimpact.py --keys [--json OUT]
  <header>   a basename such as face.h (matched case-insensitively, as VC6 on Windows does)
  --all-tus  consider every src/m85/src/*.cpp and src/ra2/**/*.cpp, not only TUs with claims
  --keys     print a dependency key per claimed TU: sha256 over the contents of every file in its
             conservative closure (plus the compiler flags).  Two snapshots with the same key for a TU
             compile that TU from identical inputs, so its baseline object can be reused (saved-object
             caching for level2_hdrcheck variants).

Conservative by construction (ported from gibbo101/ra2-decomp tools/header_inputs.py @bd6bc66711):
  - every #include in every conditional branch counts, whether or not the branch is compiled;
  - an include name is resolved to EVERY indexed file with that basename (src/m85/include, src/m85/src,
    src/ra2 and the VC6 INCLUDE trees), so a shadowing header never hides a dependency;
  - a file whose include syntax cannot be read literally (macro includes, trigraph/digraph directives,
    include_alias, NUL bytes, a BOM) makes the TU "unknown", which is reported as affected.
Overestimating is safe: a TU outside the list cannot see the header; a TU inside it MAY.  Use the list
to restrict a level2_hdrcheck variant build, then still run the full check before applying a header.
Read-only; nothing under P is modified.

Credit: include scanner from gibbo101/ra2-decomp (https://github.com/gibbo101/ra2-decomp, tools/ MIT licence);
this adaptation is part of the GPL-3.0-or-later level-2 tree.
"""
from collections import defaultdict
import glob, hashlib, json, os, re, sys

P = r'D:\<project-folder>\Coding\RedAlert2'
W = r'D:\<work-root>\RedAlert2Temp'
VC6INC = [os.path.join(W, 'tools', 'portable', 'vc6', 'VC98', 'INCLUDE'),
          os.path.join(W, 'tools', 'portable', 'vc6', 'VC98', 'ATL', 'INCLUDE')]
FLAGS = '-nologo -c -O2 -Ob2 -Gr -GR -DNDEBUG -Gy | m85: -DWIN32 -W0'

# --- verbatim from header_inputs.py @bd6bc66711 (MIT) ---------------------------------------------
TOKENS = re.compile(rb'''//[^\n]*|/\*[\s\S]*?(?:\*/|\Z)|"(?:\\.|[^"\\\n])*"|'(?:\\.|[^'\\\n])*' ''', re.X)
DIRECTIVE = re.compile(rb"(?m)^[^\S\n]*#[^\S\n]*(include(?:_next)?|import)\b(.*)", re.I)
LITERAL = re.compile(rb'\s*(?:"([^"]+)"|<([^>]+)>)\s*$')


def includes(data):
    data = data.replace(b"\r\n", b"\n").replace(b"\r", b"\n").replace(b"\\\n", b"")
    if data.startswith(b"\xef\xbb\xbf") or any(s in data for s in (b"%:", b"??=", b"??/", b"\x00", b"include_alias")):
        return None

    def strip(m):
        return b" " if m[0].startswith(b"/") else m[0]
    collapsed = TOKENS.sub(strip, data)
    directives = DIRECTIVE.findall(collapsed)
    if collapsed.count(b"\n") != data.count(b"\n"):
        kept = TOKENS.sub(lambda m: strip(m) + (b"\n" * m[0].count(b"\n") if m[0].startswith(b"/") else b""), data)
        directives.extend(DIRECTIVE.findall(kept))
    edges = set()
    for directive, operand in directives:
        m = LITERAL.fullmatch(operand)
        if directive.lower() != b"include" or not m:
            return None
        path = (m[1] or m[2]).decode("latin-1").replace("\\", "/")
        # Deviation from upstream: our src/ra2 TUs include "../RECT.H"; a relative ".." path still resolves by
        # basename to every indexed file of that name, which stays conservative.  Absolute paths stay unknown.
        if path.startswith("/") or ":" in path:
            return None
        edges.add(path.rsplit("/", 1)[-1].casefold())
    return edges
# ---------------------------------------------------------------------------------------------------


def index():
    """{casefolded basename: [paths]} and {path: include edges or None} over every searchable header."""
    roots = [os.path.join(P, 'src', 'm85', 'include'), os.path.join(P, 'src', 'm85', 'src'), os.path.join(P, 'src', 'ra2')] + VC6INC
    by_name, edges = defaultdict(list), {}
    for root in roots:
        for dirpath, dirs, files in os.walk(root):
            for f in files:
                if os.path.splitext(f)[1].lower() in ('.h', '.hh', '.hpp', '.inl', '.inc', '.cpp', '.c'):
                    p = os.path.join(dirpath, f)
                    by_name[f.casefold()].append(p)
    return by_name, edges


def closure(src, by_name, edges):
    todo, seen, unknown = [src], set(), []
    while todo:
        path = todo.pop()
        if path in seen:
            continue
        seen.add(path)
        if path not in edges:
            edges[path] = includes(open(path, 'rb').read())
        names = edges[path]
        if names is None:
            unknown.append(path)
            continue
        for n in names:
            todo.extend(by_name.get(n, ()))
    return seen, unknown


def tus(all_tus):
    if all_tus:
        out = sorted(os.path.relpath(p, P).replace('\\', '/') for p in glob.glob(os.path.join(P, 'src', 'm85', 'src', '*.cpp')))
        out += sorted(os.path.relpath(p, P).replace('\\', '/') for p in glob.glob(os.path.join(P, 'src', 'ra2', '**', '*.cpp'), recursive=True))
        return out
    return sorted({f['tu'] for f in json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))
                   if f.get('tu', '').endswith(('.cpp', '.c'))})


def main():
    a = sys.argv[1:]
    out = None
    if '--json' in a:
        k = a.index('--json'); out = a[k + 1]; del a[k:k + 2]
    all_tus = '--all-tus' in a
    keys = '--keys' in a
    wanted = {x.casefold() for x in a if not x.startswith('--')}
    if not wanted and not keys:
        raise SystemExit(__doc__)
    by_name, edges = index()
    missing = sorted(w for w in wanted if w not in by_name)
    result = {'headers': sorted(wanted), 'not_indexed': missing, 'affected': [], 'unknown': [], 'unaffected': 0, 'keys': {}}
    for tu in tus(all_tus):
        src = os.path.join(P, tu.replace('/', os.sep))
        if not os.path.exists(src):
            continue
        seen, unknown = closure(src, by_name, edges)
        if keys:
            h = hashlib.sha256(FLAGS.encode())
            for p in sorted(seen):
                h.update(os.path.relpath(p, P).replace('\\', '/').encode('latin-1', 'replace') + b'\0' + hashlib.sha256(open(p, 'rb').read()).digest())
            result['keys'][tu] = None if unknown else h.hexdigest()
        if wanted:
            hit = sorted({os.path.basename(p) for p in seen if os.path.basename(p).casefold() in wanted})
            if hit:
                result['affected'].append({'tu': tu, 'via': hit})
            elif unknown:
                result['unknown'].append({'tu': tu, 'unparsed': [os.path.relpath(u, P) if u.startswith(P) else u for u in unknown[:3]]})
            else:
                result['unaffected'] += 1
    if wanted:
        print('headers %s: %d TUs affected, %d unknown (treat as affected), %d unaffected%s' % (
            ', '.join(sorted(wanted)), len(result['affected']), len(result['unknown']), result['unaffected'],
            ('; NOT INDEXED: ' + ', '.join(missing)) if missing else ''))
        for r in result['affected']:
            print('  ', r['tu'])
        for r in result['unknown']:
            print('  ? ', r['tu'], r['unparsed'])
    if keys:
        print('%d TU keys (%d unknown)' % (len(result['keys']), sum(v is None for v in result['keys'].values())))
    if out:
        os.makedirs(os.path.dirname(os.path.abspath(out)), exist_ok=True)
        json.dump(result, open(out, 'w'), indent=1)
        print('->', out)


if __name__ == '__main__':
    main()
