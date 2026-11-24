"""Class layout and vtable evidence for the m85 headers against GAME.EXE 1.001 (RTTI), compiled by our VC6.

usage: python -I level2_classcheck.py <ClassName> [--header include/x.h] [--include-dir DIR] [--json OUT]
  --header       header under src/m85 to include (default: the first include/*.h that defines the class)
  --include-dir  an overlay include directory searched BEFORE src/m85/include (e.g. a header-batch proposal)
  --json         write the full result (default W/analysis/level2/agents/t2_tools/classcheck/<Class>.json)

What it measures (our side, by the compiler itself, through a probe TU that includes the header):
  - sizeof(Class) and the offset/size of every directly declared data member (offsetof that a member's own
    operator& cannot intercept), read back as folded constants from the probe .obj;
  - the vtables VC6 emits for a probe class derived from Class that overrides nothing: slot symbols per
    subobject offset (the complete object locator gives the offset).
What it compares with GAME.EXE (W/analysis/level2/rtti_catalog.json, RTTI-derived):
  - slot count of every vtable (primary and secondary, by subobject offset);
  - per primary slot: pure in ours -> the exe slot must be _purecall (the most common slot in all vtables);
    inherited-vs-overridden: in the exe a slot is inherited when it equals the primary base's slot k, in ours
    when the slot symbol's class is not Class;
  - where our slot symbol is claimed in P/metadata/level2_functions.json, the claimed RVA must equal the slot.
It does NOT compare member offsets with any external layout: YR/YRpp layouts are not 1.001 evidence.  sizeof and
offsets are printed so they can be checked against constructor sizes (operator new argument) and field accesses.
Exit 0 only when every vtable check passes.  Builds go under W/analysis/level2/agents/t2_tools/classcheck/.

Credit: ported from gibbo101/ra2-decomp tools/headercheck.py @bd6bc66711 (https://github.com/gibbo101/ra2-decomp,
tools/ MIT licence): probe construction, class-body parser and vtable extraction; the YRpp comparison is dropped
and the exe side uses our RTTI catalogue.  This adaptation is part of the GPL-3.0-or-later level-2 tree.
"""
import collections, hashlib, json, os, re, struct, subprocess, sys
W = r'D:\<work-root>\RedAlert2Temp'
P = r'D:\<project-folder>\Coding\RedAlert2'
sys.path.insert(0, os.path.join(W, 'analysis', 'level2'))
from coffmatch import Obj  # noqa: E402

VC6 = os.path.join(W, 'tools', 'portable', 'vc6')
FLAGS = ['-nologo', '-O2', '-Ob2', '-Gr', '-GR', '-DNDEBUG', '-DWIN32', '-W0']
M85 = os.path.join(P, 'src', 'm85')
PROBE = 'HeaderProbe'
UNINITIALIZED = 0x80
SCALARS = {"bool", "char", "short", "int", "long", "float", "double", "unsigned", "signed", "__int64", "wchar_t", "BYTE",
           "WORD", "DWORD", "LONG", "BOOL", "UINT", "ULONG", "HRESULT", "size_t"}


# --- parser, verbatim from headercheck.py @bd6bc66711 (MIT) ------------------------------------------------
def class_body(text, cls):
    m = re.search(rf"\b(?:class|struct)\s+{cls}\s*(?::[^;{{]*)?\{{", text)
    if not m:
        raise SystemExit(f"{cls}: definition not found in the preprocessed header")
    return text[m.end():matching(text, m.end() - 1)]


def matching(text, at):
    depth = 0
    for i in range(at, len(text)):
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
            if depth == 0:
                return i
    raise SystemExit("unbalanced braces in the preprocessed header")


def statements(body):
    out, cur, parens, i = [], "", 0, 0
    while i < len(body):
        c = body[i]
        if c == "{" and parens == 0:
            end = matching(body, i)
            if "(" in cur:
                out.append(cur + "{}"); cur = ""
            else:
                cur += body[i:end + 1]
            i = end + 1
            continue
        if c == "(":
            parens += 1
        elif c == ")":
            parens -= 1
        if c == ";" and parens == 0:
            out.append(cur); cur = ""
        elif c == ":" and cur.strip() in ("public", "protected", "private") and body[i + 1] != ":":
            cur = ""
        else:
            cur += c
        i += 1
    return [" ".join(s.split()) for s in out if s.strip()]


def split_top(text):
    parts, cur, depth = [], "", 0
    for c in text:
        depth += c in "([{<"
        depth -= c in ")]}>"
        if c == "," and depth == 0:
            parts.append(cur); cur = ""
        else:
            cur += c
    return parts + [cur]


def data_members(body):
    members, bitfields = [], []
    for s in statements(body):
        s = re.sub(r"^(mutable|volatile)\s+", "", s)
        first = s.split()[0]
        if first in ("static", "typedef", "enum", "friend", "using", "template", "virtual"):
            continue
        if "__declspec" in s and "property" in s:
            continue
        if re.fullmatch(r"(class|struct|union)\s+\w+(\s*\{.*\})?", s):
            continue
        if "(" in s:
            fp = re.match(r"[^(]*\(\s*(?:__\w+\s+)?(?:\w+\s*::\s*)*\*\s*(\w+)\s*\)\s*\(", s)
            if fp:
                members.append((fp.group(1), False))
            continue
        s = re.sub(r"\{.*\}", "", s)
        if ":" in s.replace("::", ""):
            bitfields.append(s)
            continue
        pieces = split_top(s)
        base_type = re.sub(r"\w+\s*(\[[^\]]*\]\s*)*$", "", pieces[0]).strip()
        aggregate = base_type.split()[-1] not in SCALARS if base_type else False
        for piece in pieces:
            m = re.search(r"(\w+)\s*((?:\[[^\]]*\]\s*)*)$", piece.strip())
            if m:
                pointer = "*" in piece or "&" in piece
                members.append((m.group(1), bool(m.group(2)) or (aggregate and not pointer)))
    return members, bitfields


def noinit_ctor(body, cls):
    return re.search(rf"\b{cls}\s*\(\s*(?:const\s+)?NoInitClass\b", body) is not None


def probe_definitions(cls, members, noinit):
    lines = ["#define PROBE_OFFSET(c, m) ((unsigned int)&reinterpret_cast<char const volatile &>(((c *)0)->m))",
             f'extern "C" unsigned int probe_size = sizeof({cls});']
    for k, (name, _) in enumerate(members):
        lines.append(f'extern "C" unsigned int probe_{k}_at = PROBE_OFFSET({cls}, {name});')
        lines.append(f'extern "C" unsigned int probe_{k}_size = sizeof((({cls} *)0)->{name});')
    init = f"{cls}(NoInitClass())" if noinit else f"{cls}()"
    lines.append(f"class {PROBE} : public {cls} {{ public: {PROBE}(); }};")
    lines.append(f"{PROBE}::{PROBE}() : {init} {{}}")
    return "\n".join(lines) + "\n"
# -----------------------------------------------------------------------------------------------------------


def scope_of(sym):
    if sym.startswith(("??_E", "??_G")):
        return sym[4:].split("@", 1)[0]
    if sym.startswith("??"):
        return sym[3:].split("@", 1)[0]
    if sym.startswith("?"):
        parts = sym[1:].split("@@", 1)[0].split("@")
        return parts[1] if len(parts) > 1 else ""
    return ""


def cl(args, cwd, overlay):
    env = dict(os.environ)
    env['PATH'] = os.pathsep.join([os.path.join(VC6, 'VC98', 'BIN'), os.path.join(VC6, 'COMMON', 'MSDEV98', 'BIN'), env['PATH']])
    env['INCLUDE'] = os.path.join(VC6, 'VC98', 'INCLUDE') + os.pathsep + os.path.join(VC6, 'VC98', 'ATL', 'INCLUDE')
    inc = (['-I' + overlay] if overlay else []) + ['-I' + os.path.join(M85, 'src'), '-I' + os.path.join(M85, 'include')]
    return subprocess.run([os.path.join(VC6, 'VC98', 'BIN', 'CL.EXE')] + FLAGS + inc + args, cwd=cwd, env=env,
                          capture_output=True, text=True, errors='replace', timeout=300)


def find_header(cls, overlay):
    pat = re.compile(rf"^\s*(?:class|struct)\s+{cls}\s*(?::[^;{{]*)?\{{", re.M)
    for d in ([overlay] if overlay else []) + [os.path.join(M85, 'include')]:
        for f in sorted(os.listdir(d)):
            if f.lower().endswith('.h') and pat.search(open(os.path.join(d, f), errors='replace').read()):
                return f
    raise SystemExit(f"{cls}: no header defines it")


def compile_probe(cls, header, overlay, work):
    pre = f'#define private public\n#define protected public\n#include "always.h"\n#include "{header}"\n'
    src = os.path.join(work, 'probe.cpp')
    open(src, 'w').write(pre)
    r = cl(['-E', src], work, overlay)
    if r.returncode != 0:
        raise SystemExit(r.stdout[-3000:] + r.stderr[-3000:])
    body = class_body(r.stdout, cls)
    members, bitfields = data_members(body)
    open(src, 'w').write(pre + probe_definitions(cls, members, noinit_ctor(body, cls)))
    obj = os.path.join(work, 'probe.obj')
    if os.path.exists(obj):
        os.remove(obj)
    r = cl(['-c', '-Fo' + obj, src], work, overlay)
    if r.returncode != 0 or not os.path.exists(obj):
        raise SystemExit((r.stdout + r.stderr)[-4000:])
    o = Obj(open(obj, 'rb').read())
    written = {idx for sec in o.sections if sec['chars'] & 0x20 for _, idx, _ in sec['relocs']}
    values = {}
    for idx, s in o.by_index.items():
        if s['name'].startswith('_probe_') and s['section'] > 0:
            if idx in written:
                raise SystemExit(f"{s['name'][1:]}: the compiler did not fold it to a constant")
            sec = o.sections[s['section'] - 1]
            values[s['name'][1:]] = 0 if sec['chars'] & UNINITIALIZED else struct.unpack_from('<I', sec['raw'], s['value'])[0]
    placed = [(name, values[f'probe_{k}_at'], values[f'probe_{k}_size'], agg) for k, (name, agg) in enumerate(members)]
    vt = {}
    for idx, s in o.by_index.items():
        if not s['name'].startswith(f'??_7{PROBE}@@6B') or s['section'] <= 0:
            continue
        sec = o.sections[s['section'] - 1]
        relocs = {off: o.by_index[si]['name'] for off, si, _ in sec['relocs']}
        loc = next(x for x in o.by_index.values() if x['name'] == relocs[s['value'] - 4] and x['section'] > 0)
        offset = struct.unpack_from('<I', o.sections[loc['section'] - 1]['raw'], loc['value'] + 4)[0]
        slots = [relocs[off] for off in range(s['value'], sec['size'], 4) if off in relocs]
        vt[offset] = [x.replace(f'{PROBE}@@', f'{cls}@@') for x in slots]
    return values['probe_size'], placed, bitfields, vt


def exe_side(cls):
    cat = json.load(open(os.path.join(W, 'analysis', 'level2', 'rtti_catalog.json')))
    by_type = {c['type']: c for c in cat['classes']}
    me = by_type.get('.?AV' + cls + '@@') or by_type.get('.?AU' + cls + '@@')
    counts = collections.Counter(s for c in cat['classes'] for v in c.get('vtables', []) for s in v['slots'])
    purecall = counts.most_common(1)[0][0] if counts else None
    if not me:
        return None, None, None, purecall
    vts = {v['subobject_offset']: [int(x, 16) for x in v['slots']] for v in me.get('vtables', [])}
    bases = me.get('hierarchy', {}).get('bases', [])
    parent = bases[1]['type'] if len(bases) > 1 and bases[1].get('mdisp') == 0 else None
    pvt = None
    if parent and parent in by_type:
        pv = {v['subobject_offset']: [int(x, 16) for x in v['slots']] for v in by_type[parent].get('vtables', [])}
        pvt = pv.get(0)
    return vts, parent, pvt, int(purecall, 16) if purecall else None


def main():
    a = sys.argv[1:]
    def opt(name):
        if name in a:
            k = a.index(name); v = a[k + 1]; del a[k:k + 2]; return v
    header, overlay, out = opt('--header'), opt('--include-dir'), opt('--json')
    if len(a) != 1:
        raise SystemExit(__doc__)
    cls = a[0]
    header = os.path.basename(header) if header else find_header(cls, overlay)
    work = os.path.join(W, 'analysis', 'level2', 'agents', 't2_tools', 'classcheck', cls + '_' + hashlib.sha256(str(os.getpid()).encode()).hexdigest()[:6])
    os.makedirs(work, exist_ok=True)
    size, members, bitfields, ours = compile_probe(cls, header, overlay, work)
    theirs, parent, pvt, purecall = exe_side(cls)
    claims = {}
    for f in json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8')):
        claims.setdefault(f.get('symbol'), set()).add(int(f['rva'], 16))
    print(f'{cls} ({header}): sizeof {size} (0x{size:X})')
    for name, at, sz, agg in members:
        print(f'  +0x{at:04X} {sz:6}  {name}')
    for b in bitfields:
        print('  (bitfield, not measured)', b)
    problems, rows = 0, []
    if theirs is None:
        print(f'exe: no RTTI type for {cls} (no vtable in 1.001, or another name)')
        problems += bool(ours)
    else:
        prim_o, prim_e = ours.get(0, []), theirs.get(0, [])
        print(f'\nprimary vtable: ours {len(prim_o)} slots, exe {len(prim_e)}; primary base {parent}: {len(pvt) if pvt else "-"}')
        for k in range(max(len(prim_o), len(prim_e))):
            sym = prim_o[k] if k < len(prim_o) else ''
            addr = prim_e[k] if k < len(prim_e) else None
            if not sym:
                v = 'MISMATCH: we have no slot'
            elif addr is None:
                v = 'MISMATCH: the exe has no slot'
            elif sym == '__purecall':
                v = 'ok' if addr == purecall else 'MISMATCH: pure in ours, not in the exe'
            else:
                known = claims.get(sym)
                exe_inh = pvt is not None and k < len(pvt) and pvt[k] == addr
                our_inh = scope_of(sym) != cls
                if known and addr not in known:   # catalogue slots and claims are both RVAs
                    v = 'MISMATCH: claimed at ' + ','.join(hex(x) for x in sorted(known))
                elif exe_inh != our_inh:
                    v = 'MISMATCH: ' + ('inherited in the exe, overridden in ours' if exe_inh else 'overridden in the exe, inherited in ours')
                else:
                    v = 'ok' + (' (claimed)' if known else '')
            problems += not v.startswith('ok')
            rows.append({'slot': k, 'ours': sym, 'exe_rva': hex(addr) if addr is not None else None, 'verdict': v})
            print(f'  {k:3} +0x{4 * k:03X} {sym[:60]:60} {hex(addr) if addr is not None else "-":10} {v}')
        for off in sorted((set(ours) | set(theirs)) - {0}):
            no, ne = len(ours.get(off, [])), len(theirs.get(off, []))
            problems += no != ne
            print(f'vtable at +0x{off:X}: ours {no} slots, exe {ne}' + ('' if no == ne else '  MISMATCH'))
    res = {'class': cls, 'header': header, 'overlay': overlay, 'sizeof': size,
           'members': [{'name': n, 'offset': at, 'size': sz} for n, at, sz, _ in members], 'bitfields': bitfields,
           'our_vtables': {str(k): v for k, v in ours.items()}, 'exe_vtables': {str(k): [hex(x) for x in v] for k, v in (theirs or {}).items()},
           'primary_base': parent, 'primary_slots': rows, 'problems': problems}
    out = out or os.path.join(W, 'analysis', 'level2', 'agents', 't2_tools', 'classcheck', cls + '.json')
    json.dump(res, open(out, 'w'), indent=1)
    print(f'\n{cls}: PASS' if not problems else f'\n{cls}: FAIL ({problems} problems)', '->', out)
    raise SystemExit(1 if problems else 0)


if __name__ == '__main__':
    main()
