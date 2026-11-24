"""level2_cv.py <base.cpp> <edits.json|-> <needle> <rva> [start end]  : compile a variant (edits = [[old,new],...]) with VC6 and
print the AI window of ours vs orig (only lines that differ unless start/end given)."""
import sys, os, json, subprocess, hashlib
VC6 = r'D:\<work-root>\RedAlert2Temp\tools\portable\vc6'
M85 = r'D:\<project-folder>\Coding\RedAlert2\src\m85'
sys.path.insert(0, r'D:\<work-root>\RedAlert2Temp\analysis\level2'); sys.path.insert(0, r'D:\<work-root>\RedAlert2Temp\tools\portable\capstone-5.0.6')
import capstone, l2match
from coffmatch import Obj
def compile_variant(base, edits, tag=None, extra=()):
    t = open(base, 'rb').read().decode('latin-1')
    crlf = '\r\n' in t; t = t.replace('\r\n', '\n')
    for e in edits:
        if t.count(e[0]) != 1: raise SystemExit('edit old occurs %d times: %r' % (t.count(e[0]), e[0][:60]))
        t = t.replace(e[0], e[1])
    if crlf: t = t.replace('\n', '\r\n')
    h = tag or hashlib.sha1(t.encode('latin-1')).hexdigest()[:12]
    d = os.path.join(os.path.dirname(os.path.abspath(base)), 'cv_work'); os.makedirs(d, exist_ok=True)
    src = os.path.join(d, h + '.cpp'); obj = os.path.join(d, h + '.obj')
    if not os.path.exists(obj):
        open(src, 'wb').write(t.encode('latin-1'))
        env = dict(os.environ)
        env['PATH'] = os.pathsep.join([os.path.join(VC6, 'VC98', 'BIN'), os.path.join(VC6, 'COMMON', 'MSDEV98', 'BIN'), env.get('PATH', '')])
        env['INCLUDE'] = os.path.join(VC6, 'VC98', 'INCLUDE') + ';' + os.path.join(VC6, 'VC98', 'ATL', 'INCLUDE')
        r = subprocess.run([os.path.join(VC6, 'VC98', 'BIN', 'CL.EXE'), '-nologo', '-c', '-O2', '-Ob2', '-Gr', '-GR', '-DNDEBUG', '-Gy', '-DWIN32', '-W0', '-I' + os.path.join(M85, 'src'), '-I' + os.path.join(M85, 'include'), *extra, '-Fo' + obj, src], env=env, capture_output=True, text=True, cwd=d)
        if not os.path.exists(obj): raise SystemExit(r.stdout[-2000:] + r.stderr[-500:])
    return obj
def show(obj, needle, rva, s=0, e=1 << 30, onlydiff=False):
    o = Obj(open(obj, 'rb').read()); names = [k for k in o.symbols if needle in k]; sec = o.function(names[0])
    code = sec['raw']; orig = l2match.orig(rva, len(code) + 32)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    d = lambda c: ['%04x %s %s' % (i.address, i.mnemonic, i.op_str) for i in md.disasm(c, 0) if s <= i.address < e]
    a = d(code); b = d(orig)
    for i in range(max(len(a), len(b))):
        x = a[i] if i < len(a) else ''; y = b[i] if i < len(b) else ''
        print('%-46s | %s' % (x, y))
if __name__ == '__main__':
    ed = [] if sys.argv[2] == '-' else json.load(open(sys.argv[2]))
    obj = compile_variant(sys.argv[1], ed)
    show(obj, sys.argv[3], int(sys.argv[4], 16), *(int(x, 16) for x in sys.argv[5:7]))
