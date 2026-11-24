"""level2_weightlab.py - measure "weight-only" constructs for VC6's register allocator (level-2 work item F17).

A weight-only construct is a source reference of a variable that COUNTS in VC6's register weighting (it moves a
register tie) but emits no instruction of its own.  The lab inserts each catalogue construct for one variable at one
place, compiles with the level-2 flags (CL 12.00.8168, -O2 -Ob2 -Gr -GR -DNDEBUG -Gy) and classifies the result:

  IDENT   function bytes equal the base            -> removed before the count (no weight, no code)
  WEIGHT  instruction list equals the REAL-probe variant minus the probe's own instructions
                                                   -> counts and emits nothing: the wanted class
  REGS    same mnemonic sequence as the base, other registers/operands, but not the probe picture
  CODE    anything else (size delta and instruction-count delta are printed)

Usage:
  python -I level2_weightlab.py synth [lab ...] [--only name,...]
        built-in synthetic labs (see LABS): spill5 = five values across a call for four callee-saved registers,
        the insert variable is the spilled one; scratch = two block-local scratch candidates with equal counts.
  python -I level2_weightlab.py target <spec.json> [--only name,...] [--show name]
        spec = {"base": "x.cpp", "needle": "One_Time@IonBlastClass", "rva": "0x120fd0", "var": "row", "type": "int",
                "anchor": "<text occurring once>", "where": "before"|"after", "pre": [[old,new],...],
                "helper_anchor": "<text occurring once at file scope before the function>", "indent": "\t\t"}
        every construct is inserted at the anchor; prints size, masked hunks against the original and the class.
        --show prints the masked hunks of one construct.
  python -I level2_weightlab.py list
        print the construct catalogue (name, helper, statement).

Importable: CONSTRUCTS, compile_text(), fn_instrs(), classify().  Objects are cached by source hash in
W/analysis/level2/agents/f17_lab/work (never W/build/level2).  Nothing outside that folder is written.
"""
import sys, os, re, json, hashlib, subprocess, difflib
W = r'D:\<work-root>\RedAlert2Temp'
VC6 = os.path.join(W, 'tools', 'portable', 'vc6')
M85 = r'D:\<project-folder>\Coding\RedAlert2\src\m85'
WORK = os.path.join(W, 'analysis', 'level2', 'agents', 'f17_lab', 'work')
sys.path.insert(0, os.path.join(W, 'analysis', 'level2')); sys.path.insert(0, os.path.join(W, 'tools', 'portable', 'capstone-5.0.6'))
import capstone
from coffmatch import Obj

# ---- catalogue: (name, file-scope helper text, statement text).  {V} = variable, {T} = its type ----------------
HELP = """
#include <stdlib.h>
extern int WL_G; extern int WL_G2; extern void WL_Ext(int);
inline void WL_Empty({T}) {}
inline void WL_EmptyNamed({T} v) {}
inline void WL_EmptyRef({T} &) {}
inline void WL_EmptyCRef({T} const &) {}
inline void WL_EmptyPtr({T} *) {}
inline {T} WL_Id({T} v) { return v; }
inline {T} const & WL_IdRef({T} const & v) { return v; }
inline void WL_Void({T} v) { (void)v; }
inline bool WL_Valid({T} v) { return v != 0; }
inline void WL_Assert(bool) {}
inline void WL_Assert2(bool c) { if (!c) {} }
inline {T} WL_Max({T} a, {T} b) { return a > b ? a : b; }
struct WL_S { {T} m; int n; };
struct WL_W { {T} m; WL_W({T} v) : m(v) {} {T} Get() const { return m; } operator {T}() const { return m; } };
struct WL_P { {T} m; };
inline void WL_TakeW(WL_W) {}
inline WL_W WL_Make({T} v) { return WL_W(v); }
inline WL_P WL_MakeP({T} v) { WL_P p; p.m = v; return p; }
inline {T} WL_Chk({T} v) { if (v == 0) { } return v; }
#define WL_ASSERT(c) do { if (!(c)) { } } while (0)
#define WL_ASSERTV(c) ((void)(c))
"""
CONSTRUCTS = [
    ('real_store',        'WL_G = (int){V};'),                       # control: a real reference
    ('expr_stmt',         '{V};'),
    ('void_cast',         '(void){V};'),
    ('inl_byval',         'WL_Empty({V});'),
    ('inl_byval_named',   'WL_EmptyNamed({V});'),
    ('inl_byref',         'WL_EmptyRef({V});'),
    ('inl_bycref',        'WL_EmptyCRef({V});'),
    ('inl_byptr',         'WL_EmptyPtr(&{V});'),
    ('inl_id_dropped',    'WL_Id({V});'),
    ('inl_id_reassign',   '{V} = WL_Id({V});'),
    ('inl_idref_dropped', 'WL_IdRef({V});'),
    ('inl_idref_reassign','{V} = WL_IdRef({V});'),
    ('inl_void_helper',   'WL_Void({V});'),
    ('inl_chk_reassign',  '{V} = WL_Chk({V});'),
    ('inl_max_self',      '{V} = WL_Max({V}, {V});'),
    ('cmp_and_0',         'if (({V} != 0) && 0) { WL_Ext(0); }'),
    ('cmp_or_1',          'if (({V} != 0) || 1) { }'),
    ('cmp_self',          'if ({V} == {V}) { }'),
    ('cmp_empty_if',      'if ({V} != 0) { }'),
    ('cmp_empty_ifelse',  'if ({V} != 0) { } else { }'),
    ('cmp_bool_dead',     '{ bool wl_c = ({V} != 0); wl_c = false; }'),
    ('dead_struct_member','{ WL_S wl_s; wl_s.m = {V}; }'),
    ('dead_struct_copy',  '{ WL_P wl_p; wl_p.m = {V}; WL_P wl_q = wl_p; }'),
    ('sizeof',            '{ int wl_n = sizeof({V}); (void)wl_n; }'),
    ('assert_macro',      'WL_ASSERT({V} != 0);'),
    ('assert_void_macro', 'WL_ASSERTV({V} != 0);'),
    ('assert_inline',     'WL_Assert({V} != 0);'),
    ('assert_inline_if',  'WL_Assert2({V} != 0);'),
    ('valid_inline',      'WL_Valid({V});'),
    ('ternary_const0',    '{ int wl_t = 0 ? (int){V} : 0; (void)wl_t; }'),
    ('ternary_const1',    '{ int wl_t = 1 ? 0 : (int){V}; (void)wl_t; }'),
    ('ternary_same',      '{V} = 1 ? {V} : ({T})0;'),
    ('dead_branch_if0',   'if (0) { WL_G = (int){V}; }'),
    ('dead_loop',         'for (int wl_k = 0; wl_k < 0; wl_k++) { WL_G = (int){V}; }'),
    ('dead_while0',       'while (0) { WL_G = (int){V}; }'),
    ('ref_bound',         '{ {T} & wl_r = {V}; }'),
    ('cref_bound',        '{ {T} const & wl_r = {V}; (void)wl_r; }'),
    ('addr_dropped',      '&{V};'),
    ('addr_local',        '{ {T} * wl_a = &{V}; }'),
    ('deref_addr',        '*&{V};'),
    ('tmp_member',        'WL_W({V}).Get();'),
    ('tmp_named',         '{ WL_W wl_w({V}); }'),
    ('tmp_roundtrip',     '{V} = WL_W({V}).Get();'),
    ('tmp_conv_roundtrip','{V} = WL_W({V});'),
    ('tmp_byval_param',   'WL_TakeW(WL_W({V}));'),
    ('tmp_inl_return',    'WL_Make({V});'),
    ('tmp_inl_ret_rt',    '{V} = WL_Make({V}).Get();'),
    ('pod_inl_ret_rt',    '{V} = WL_MakeP({V}).m;'),
    ('dead_accumulate',   '{ int wl_acc = 0; wl_acc += (int){V}; }'),
    ('dead_copy',         '{ {T} wl_c = {V}; }'),
    ('copy_back',         '{ {T} wl_c = {V}; {V} = wl_c; }'),
    ('assume',            '__assume({V} != 0);'),
    ('switch_default',    'switch ((int){V}) { default: break; }'),
    ('switch_case',       'switch ((int){V}) { case 0: break; default: break; }'),
    ('self_assign',       '{V} = {V};'),
    ('cast_roundtrip',    '{V} = ({T})(int){V};'),
    ('comma',             '({V}, 0);'),
    ('times_zero',        'WL_G2 = WL_G2 + ((int){V} - (int){V});'),
    ('ternary_null',      '{V} = {V} ? {V} : ({T})0;'),
    ('if_null_assign',    'if (!{V}) { {V} = ({T})0; }'),
    ('ternary_same_arms', 'WL_G2 = {V} ? WL_G2 : WL_G2;'),
    ('if_same_arms',      'if ({V}) { WL_G2 = 0; } else { WL_G2 = 0; }'),     # reference store WL_G2 = 0 is real code; compare with next
    ('plain_g2_store',    'WL_G2 = 0;'),                                      # control for if_same_arms
    ('empty_for_self',    'for ({T} wl_k = {V}; wl_k < {V}; wl_k++) { }'),
    ('while_ne_self',     'while ({V} != {V}) { }'),
    ('do_while_and0',     'do { } while ({V} && 0);'),
    ('dead_array_store',  '{ {T} wl_arr[1]; wl_arr[0] = {V}; }'),
    ('dead_bitfield',     '{ struct { int a : 8; int b : 24; } wl_bf; wl_bf.a = (int){V}; }'),
    ('dead_union',        '{ union { {T} a; int b; } wl_u; wl_u.a = {V}; }'),
    ('dead_double',       '{ double wl_d = (double)(int){V}; }'),
    ('dead_char',         '{ char wl_ch = (char)(int){V}; }'),
    ('eq_self_value',     'WL_G2 += ((int){V} == (int){V}) - 1;'),
    ('and_zero_value',    'WL_G2 += (int){V} & 0;'),
    ('mul_zero_value',    'WL_G2 += (int){V} * 0;'),
    ('swap_twice',        '{ {T} wl_a = {V}, wl_b = ({T})0; {T} wl_t = wl_a; wl_a = wl_b; wl_b = wl_t; wl_t = wl_a; wl_a = wl_b; wl_b = wl_t; {V} = wl_a; }'),
    ('cond_copy_back',    '{ {T} wl_c = {V}; if (wl_c != {V}) { {V} = wl_c; } }'),
    ('inl_nested_struct', 'WL_TakeW(WL_Make({V}));'),
    ('inl_ptr_deref',     'WL_EmptyPtr(&{V}); *&{V} = {V};'),
]
ARITH = [  # only meaningful for arithmetic (non-pointer) variables
    ('plus_zero',         '{V} += 0;'),
    ('plus_minus',        '{V} = {V} + 1 - 1;'),
    ('xor_zero',          '{V} ^= 0;'),
    ('shift_zero',        '{V} <<= 0;'),
    ('neg_neg',           '{V} = -(-{V});'),
    ('not_not',           '{V} = ~~{V};'),
    ('mul_one',           '{V} *= 1;'),
    ('div_one',           '{V} /= 1;'),
    ('or_zero',           '{V} |= 0;'),
    ('and_ones',          '{V} &= -1;'),
    ('sub_self_add',      '{V} = {V} - {V} + {V};'),
    ('abs_dropped',       'abs({V});'),
    ('rotl_zero',         '{V} = _rotl({V}, 0);'),
]

# ---- synthetic labs --------------------------------------------------------------------------------------------
LABS = {
 'spill5': dict(needle='WL_Spill5', type='int', doc='five ints live across a call, four callee-saved registers', text="""
extern int WL_Call(int); extern int WL_Tab[];
int WL_Spill5(int i, int j)
{
	int a = WL_Tab[i]; int b = WL_Tab[j]; int c = WL_Tab[i + j]; int d = WL_Tab[i - j]; int e = WL_Tab[i * 2];
	/*USE*/
	int r = WL_Call(i);
	return ((r ^ a) * b + c) * d - e;
}
"""),
 'scratch': dict(needle='WL_Scratch', type='int', doc='ionblast-like store block: row and mirror compete for the scratch registers', text="""
extern double WL_F(int);
void WL_Scratch(char * center, int n)
{
	for (int y = 63; y >= 0; y--) {
		for (int i = 0; i <= 127; i++) {
			int x = 127 - i;
			if (WL_F(x * x + y) >= 1.0) {
				char v = (char)WL_F(y);
				int row = y << 8;
				/*USE*/
				center[row + x] = v;
				center[row - x] = v;
				char * mirror = center - row;
				mirror[x] = v;
				mirror[-x] = v;
			}
		}
	}
}
"""),
 'loop2': dict(needle='WL_Loop2', type='int *', doc='two pointers and a loop counter across a call in a loop', text="""
extern int WL_Call(int);
int WL_Loop2(int * p, int * q, int * s, int * t, int n)
{
	int sum = 0;
	/*USE*/
	for (int k = 0; k < n; k++) {
		sum += WL_Call(k) + p[k] + q[k] + s[k] + t[k];
	}
	return sum + WL_Call(*p + *q + *s + *t);
}
"""),
}

def compile_text(text, tag=None, includes=False):
    os.makedirs(WORK, exist_ok=True)
    h = hashlib.sha1(text.encode('latin-1')).hexdigest()[:14]
    src = os.path.join(WORK, 'w' + h + '.cpp'); obj = os.path.join(WORK, 'w' + h + '.obj')
    if not os.path.exists(obj):
        open(src, 'wb').write(text.encode('latin-1'))
        env = dict(os.environ)
        env['PATH'] = os.pathsep.join([os.path.join(VC6, 'VC98', 'BIN'), os.path.join(VC6, 'COMMON', 'MSDEV98', 'BIN'), env.get('PATH', '')])
        env['INCLUDE'] = os.path.join(VC6, 'VC98', 'INCLUDE') + ';' + os.path.join(VC6, 'VC98', 'ATL', 'INCLUDE')
        cmd = [os.path.join(VC6, 'VC98', 'BIN', 'CL.EXE'), '-nologo', '-c', '-O2', '-Ob2', '-Gr', '-GR', '-DNDEBUG', '-Gy', '-DWIN32', '-W0']
        if includes: cmd += ['-I' + os.path.join(M85, 'src'), '-I' + os.path.join(M85, 'include')]
        r = subprocess.run(cmd + ['-Fo' + obj, src], env=env, capture_output=True, text=True, cwd=WORK)
        if not os.path.exists(obj): return None, (r.stdout + r.stderr)[-400:]
    return obj, ''

_md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
def fn_instrs(obj, needle):
    """-> (raw bytes, [(text, is_probe)]) with branch targets masked; is_probe marks instructions relocated to WL_G."""
    o = Obj(open(obj, 'rb').read()); names = [k for k in o.symbols if needle in k]; sec = o.function(names[0])
    code = sec['raw']; probe = set()
    for off, si, typ in sec['relocs']:
        if 'WL_G' in o.by_index.get(si, {}).get('name', ''): probe.update(range(off, off + 4))
    rel = set()
    for off, si, typ in sec['relocs']: rel.update(range(off, off + 4))
    out = []
    for i in _md.disasm(code, 0):
        s = i.mnemonic + ' ' + i.op_str
        if i.mnemonic.startswith('j') or i.mnemonic == 'call': s = i.mnemonic
        elif any(a in rel for a in range(i.address, i.address + i.size)): s = re.sub(r'0x[0-9a-f]+|\b\d+\b', 'A', s)
        if i.mnemonic in ('nop', 'int3'): continue
        out.append((s, any(a in probe for a in range(i.address, i.address + i.size))))
    return code, out

def classify(base, probe, var):
    """base/probe/var = fn_instrs() results.  -> class string."""
    if var[0] == base[0]: return 'IDENT'
    v = [s for s, p in var[1]]; b = [s for s, p in base[1]]
    pr = [s for s, p in probe[1] if not p] if probe else None
    if pr is not None and v == pr and pr != b: return 'WEIGHT'
    if [s.split()[0] for s in v] == [s.split()[0] for s in b]: return 'REGS'
    return 'CODE %+d bytes %+d instrs' % (len(var[0]) - len(base[0]), len(v) - len(b))

def stmt(c, V, T): return c.replace('{V}', V).replace('{T}', T)

def catalogue(T): return CONSTRUCTS + ([] if '*' in T else ARITH)

def run_synth(labs, only):
    for lab in labs:
        L = LABS[lab]; T = L['type']
        print('== lab %s: %s' % (lab, L['doc']))
        mk = lambda use: HELP.replace('{T}', T) + L['text'].replace('/*USE*/', use)
        obj, err = compile_text(mk('')); base = fn_instrs(obj, L['needle'])
        vars_ = re.findall(r'\b(?:int|char \*|int \*) \*?\s*(\w+)\s*=', L['text']) if 'vars' not in L else L['vars']
        if lab == 'loop2': vars_ = ['p', 'q', 's', 't']
        if lab == 'scratch': vars_ = ['row']
        if lab == 'spill5': vars_ = ['a', 'b', 'c', 'd', 'e']
        for V in vars_:
            pobj, err = compile_text(mk(stmt('WL_G = (int){V};', V, T))); probe = fn_instrs(pobj, L['needle'])
            moved = [s for s, p in probe[1] if not p] != [s for s, p in base[1]]
            print('  var %-4s real probe %s' % (V, 'MOVES the allocation' if moved else 'does not move it'))
            if not moved: continue
            for name, c in catalogue(T):
                if only and name not in only: continue
                obj, err = compile_text(mk(stmt(c, V, T)))
                if not obj: print('    %-20s COMPILE ERROR %s' % (name, err.strip().splitlines()[-1][:90] if err.strip() else '')); continue
                print('    %-20s %s' % (name, classify(base, probe, fn_instrs(obj, L['needle']))))

def hunks(obj, needle, rva, show=False):
    r = subprocess.run([sys.executable, '-I', os.path.join(W, 'tools', 'level2_maskhunks.py'), obj, needle, rva] + (['show'] if show else []), capture_output=True, text=True)
    m = re.search(r'hunks (\d+) instrs (\d+)', r.stdout)
    return (int(m.group(1)), int(m.group(2))) if m else (-1, -1), r.stdout

def apply(t, edits):
    for a, b in edits:
        if t.count(a) != 1: raise SystemExit('edit old occurs %d times: %r' % (t.count(a), a[:70]))
        t = t.replace(a, b)
    return t

def run_target(specpath, only, show):
    S = json.load(open(specpath)); d = os.path.dirname(os.path.abspath(specpath))
    t = open(os.path.join(d, S['base']), 'rb').read().decode('latin-1').replace('\r\n', '\n')
    t = apply(t, S.get('pre', []))
    V, T, ind = S['var'], S['type'], S.get('indent', '\t')
    ha = S['helper_anchor']; assert t.count(ha) == 1 and t.count(S['anchor']) == 1, 'anchor not unique'
    def mk(use):
        x = t.replace(ha, HELP.replace('{T}', T) + ha)
        if not use: return x
        ins = ind + use + '\n'
        return x.replace(S['anchor'], ins + S['anchor'] if S.get('where', 'before') == 'before' else S['anchor'] + ins)
    obj, err = compile_text(mk(''), includes=True)
    if not obj: raise SystemExit(err)
    base = fn_instrs(obj, S['needle']); print('base   size %d hunks %s' % (len(base[0]), hunks(obj, S['needle'], S['rva'])[0]))
    pobj, err = compile_text(mk(stmt('WL_G = (int){V};', V, T)), includes=True); probe = fn_instrs(pobj, S['needle'])
    for name, c in catalogue(T):
        if only and name not in only: continue
        obj, err = compile_text(mk(stmt(c, V, T)), includes=True)
        if not obj: print('%-20s COMPILE ERROR %s' % (name, (err.strip().splitlines() or [''])[-1][:100])); continue
        var = fn_instrs(obj, S['needle']); h, out = hunks(obj, S['needle'], S['rva'], name == show)
        print('%-20s size %d hunks %s  %s' % (name, len(var[0]), h, classify(base, probe, var)))
        if name == show: print(out)

if __name__ == '__main__':
    a = sys.argv[1:]; only = None; show = None
    if '--only' in a: k = a.index('--only'); only = a[k + 1].split(','); del a[k:k + 2]
    if '--show' in a: k = a.index('--show'); show = a[k + 1]; del a[k:k + 2]
    if not a or a[0] == 'list':
        for n, c in CONSTRUCTS + ARITH: print('%-20s %s' % (n, c))
    elif a[0] == 'synth': run_synth(a[1:] or list(LABS), only)
    elif a[0] == 'target': run_target(a[1], only, show)
    else: print(__doc__)
