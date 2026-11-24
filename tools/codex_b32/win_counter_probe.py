"""Build scratch TU probes and measure WinMain's COFF SEH ID and masked code.
Run with a refreshed batch-32 kit. For a calibration use 0..63 at 'before',
then test new declaration counts, spelling, kind, position and combinations.
All temporary sources and objects are per-run. Only scalar measurements are saved.
"""
import argparse, concurrent.futures, hashlib, json, os, re, subprocess, sys, tempfile
from pathlib import Path

def main():
    p = argparse.ArgumentParser(description=__doc__)
    for name in ['kit', 'source', 'temp', 'out']:
        p.add_argument('--'+name, type=Path, required=True)
    p.add_argument('--start', type=int, default=0)
    p.add_argument('--end', type=int, default=64)
    p.add_argument('--counts', help='Comma-separated list; overrides start and end')
    p.add_argument('--kind', choices=['tag','extern','repeat','member','method','alias','local','tagname','enum'], default='tag')
    p.add_argument('--where', choices=['before','first','last','inner'], default='before')
    p.add_argument('--lines',help='Comma-separated 1-based line numbers at which to insert k full-line declarations; use with a single --counts value')
    p.add_argument('--keep', type=int, nargs='*', default=[])
    p.add_argument('--workers', type=int, default=3)
    a = p.parse_args()
    kit, tmp = a.kit.resolve(), a.temp.resolve()
    tmp.mkdir(exist_ok=True, parents=True)
    sys.path[:0] = [str(kit/'tools'), str(kit)]
    from coffmatch import Obj
    import l2match
    src = a.source.read_bytes()
    signature = b'int CALLBACK WinMain (' if b'int CALLBACK WinMain (' in src else b'int __stdcall WinMain ('
    where = {'first':0,'last':len(src), 'before':src.index(signature),
             'inner':src.index(b'int\t\targc;',src.index(signature))}[a.where]
    if a.kind == 'local' and a.where != 'inner':
        p.error('local variables require --where inner')
    vc = kit/'vc6'/'VC98'; bin = vc/'BIN'
    f = ['-nologo','-c','-O2','-Ob2','-Gr','-GR','-DNDEBUG','-Gy','-DWIN32','-W0',
         '-I'+str(kit/'m85'/'src'),'-I'+str(kit/'m85'/'include')]
    original = l2match.orig(0x283970, 10080)
    counts = list(map(int, a.counts.split(','))) if a.counts else range(a.start, a.end+1)
    tasks=[(k,where,a.where) for k in counts]
    if a.lines:
        lines=src.splitlines(keepends=True)
        tasks=[(k,sum(map(len,lines[:n-1])),str(n)) for n in map(int,a.lines.split(',')) for k in counts]
    def measure(task):
        k,where,position=task
        names = [str(i) for i in range(k)]
        statements = {'tag':'struct WinProbe{};', 'extern':'extern int WinProbe{};',
          'repeat':'struct WinProbe;', 'method':'void method{}();', 'alias':'typedef int ProbeType{};',
          'member':'int field{};', 'local':'int localProbe{};', 'tagname':'struct DifferentIdentifier{};',
          'enum':'enum EnumProbe{} {{ EnumValue{} }};'}[a.kind]
        decl = ' '.join(statements.replace('{}',i).replace('{{','{').replace('}}','}') for i in names)
        if a.kind in ('member','method'):
            decl = 'struct WinProbeContainer { '+decl+' };'
        before = src[:where]; after = src[where:]
        text = before + decl.encode('ascii') + (b'\r\n#line '+position.encode()+b'\r\n' if a.lines else b' ') + after
        with tempfile.TemporaryDirectory(dir=tmp, prefix='winprobe') as wd:
            wd = Path(wd); cpp = wd/'startup.cpp'; obj = wd/'startup.obj'
            cpp.write_bytes(text)
            env = dict(os.environ, TEMP=str(wd), TMP=str(wd),
                       INCLUDE=str(vc/'INCLUDE')+';'+str(vc/'ATL'/'INCLUDE'),
                       LIB=str(vc/'LIB'), PATH=str(bin)+';'+str(kit/'vc6'/'COMMON'/'MSDEV98'/'BIN')+';'+os.environ.get('PATH',''))
            proc=subprocess.run([str(bin/'CL.EXE'), *f, '-Fo'+str(obj), str(cpp)],
                       cwd=wd,env=env,capture_output=True,timeout=240)
            if proc.returncode: raise RuntimeError((proc.stdout+proc.stderr)[-1500:])
            o = Obj(obj.read_bytes()); sec=o.function('_WinMain@16'); code=bytearray(sec['raw'])
            mask=set()
            for off, idx, typ in sec['relocs']:
                mask.update(range(off,off+4))
            if len(original)!=len(code): raise ValueError('unexpected target extent')
            offsets=[i for i,(c,v) in enumerate(zip(code,original)) if c!=v and i not in mask]
            count=len(offsets)
            for i in mask: code[i]=0
            off, idx, ty=next(r for r in sec['relocs'] if r[0]==6)
            seh=o.by_index[idx]['name']; m=re.fullmatch(r'\$T(\d+)',seh)
            if not m: raise ValueError('unrecognized SEH table '+seh)
            if k in a.keep:
                stem='probe_%s_%s_%d' % (a.kind,position,k)
                (tmp/(stem+'.obj')).write_bytes(obj.read_bytes())
                (tmp/(stem+'.cpp')).write_bytes(text)
            return dict(kind=a.kind,where=position,k=k,seh_id=int(m[1]),masked_differences=count,
                        code_sha256=hashlib.sha256(code).hexdigest(), offsets=offsets, code_size=len(code))
    with concurrent.futures.ThreadPoolExecutor(a.workers) as pool, a.out.open('w',encoding='utf8') as out:
        for row in pool.map(measure,tasks):
            print(json.dumps(row),file=out,flush=True)

if __name__=='__main__':
    main()
