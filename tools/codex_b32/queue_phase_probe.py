"""Compile a private queue.cpp (or its /P translation) and measure independent reloads.
Only report numerical metadata and SHA256s; no objects or compiler listings are returned.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import tempfile

OFFSETS = (0x639,0x9a9,0xb9f,0xd90)
FLAGS = ['-O2','-Ob2','-Gr','-GR','-DNDEBUG','-Gy','-DWIN32','-W0']

def main():
    ap = argparse.ArgumentParser(description=__doc__)
    for name in ('kit','source','scratch','output'):
        ap.add_argument('--'+name, type=Path, required=True)
    ap.add_argument('--plan', choices=['headers','native-headers','flags','phase','prep','residues'], required=True)
    a = ap.parse_args()
    kit, scratch = a.kit.resolve(), a.scratch.resolve()
    scratch.mkdir(parents=True,exist_ok=True)
    src = a.source.read_bytes()
    bindir = kit/'vc6/VC98/BIN'
    cl = str(bindir/'CL.EXE')
    env = os.environ.copy()
    env.update(PATH=os.pathsep.join([str(bindir), str(kit/'vc6/COMMON/MSDEV98/BIN'),env['PATH']]), INCLUDE=os.pathsep.join(str(kit/'vc6/VC98'/x) for x in ['INCLUDE','ATL/INCLUDE']))
    sys.path[:0]=[str(kit/'tools'),str(kit)]
    from coffmatch import Obj
    import l2match
    incl=['-I'+str(kit/'m85/src'),'-I'+str(kit/'m85/include')]
    if a.plan=='prep':
        cmd = [cl,'-nologo','-P',*FLAGS,*incl,str(a.source.resolve())]
        p = subprocess.run(cmd,cwd=scratch,env=dict(env,TEMP=str(scratch),TMP=str(scratch)),capture_output=True,timeout=120)
        if p.returncode:
            raise RuntimeError(str(p.stderr+p.stdout))
        return
    def edit(where, kind, k):
        if where=='before':
            at=src.index(b'int Extract_Compressed_Events(void *buf, int bufsize) //')
        elif where=='head':
            at=0
        elif where=='tail':
            at=len(src)
        elif where=='body':
            marker=b'static void Print_CRCs(EventClass *ev)'
            at=src.index(b'{',src.rindex(marker))+1
        else:
            marker=b'class '+where.encode()
            matches=list(re.finditer(re.escape(marker)+rb'\s*(?::[^;{}]*)?\{',src))
            if len(matches)!=1:
                raise ValueError((where,len(matches)))
            at=matches[0].end()
        form={'tag':'struct Q32Probe{};', 'extern':'extern int Q32Probe{};', 'method':'void Q32Probe{}();',
              'inline':'void Q32Probe{}() {{}}','local':'int Q32Probe{} = 0;'}[kind]
        if a.plan == 'residues':
            form = 'struct QueueOrderGauge{};'
        extra=b'\r\n'+b' '.join(form.format(i).encode() for i in range(k))+b'\r\n'
        return src[:at]+extra+src[at:] if k else src
    def run(item):
        where,kind,k,flag=item
        with tempfile.TemporaryDirectory(dir=scratch) as d:
            tmp=Path(d)
            native=a.plan=='native-headers'
            changed=src if native else edit(where,kind,k)
            include_flags=list(incl)
            if native:
                # An independent header tree preserves quoted-include search order.
                hdr=tmp/'include'
                shutil.copytree(kit/'m85/include',hdr)
                include_flags[-1]='-I'+str(hdr)
                name={'MissionClass':'mission.h','TechnoClass':'techno.h'}[where]
                path=hdr/name
                data=path.read_bytes()
                marker=re.search(rb'class '+where.encode()+rb'\s*:[^;{}]*\{',data)
                if not marker:
                    raise ValueError(where)
                form={'method':'void Q32Probe{}();', 'inline':'void Q32Probe{}() {{}}',
                      'convert':None}[kind]
                if kind=='convert':
                    # Replace existing class bodies by declarations; both are in this release.
                    patterns=[b'CanCheer(void) const {return(false);}', b'Cheer(void) {}']
                    for old in patterns[:k]:
                        if data.count(old)!=1:
                            raise ValueError(old)
                        data=data.replace(old,old.split(b' {')[0]+b';')
                    # A negative change is measured as a count removed, e.g. k=2.
                elif k:
                    added=b'\r\n'+b' '.join(form.format(i).encode() for i in range(k))+b'\r\n'
                    data=data[:marker.end()]+added+data[marker.end():]
                path.write_bytes(data)
            path=tmp/'q.cpp'
            path.write_bytes(changed)
            obj=tmp/'q.obj'
            listing=tmp/'q.asm'
            cmd=[cl,'-nologo','-c',*FLAGS,*include_flags,*([flag] if flag else []),'-FAs','-Fa'+str(listing),'-Fo'+str(obj),str(path)]
            p=subprocess.run(cmd,cwd=tmp,env=dict(env,TEMP=d,TMP=d),capture_output=True,timeout=150)
            if p.returncode:
                raise RuntimeError(str(p.stdout[-900:]+p.stderr[-900:]))
            o=Obj(obj.read_bytes())
            name=next(n for n in o.symbols if 'Print_CRCs@@' in n)
            f=o.function(name)
            buf=bytearray(f['raw'])
            ref=bytearray(l2match.orig(0x221b90,len(buf)))
            for off,*_ in f['relocs']:
                buf[off:off+4]=ref[off:off+4]=bytes(4)
            diffs=[i for i,(x,y) in enumerate(zip(buf,ref)) if x!=y]
            asm=listing.read_bytes()
            decl=asm.index(b'?Print_CRCs@@YIXPAVEventClass@@@Z PROC')
            # /FAs lists frame slot names and lexical IDs before this function's PROC.
            start=asm.rfind(b'_TEXT\tSEGMENT',0,decl)
            pre=asm[max(start,decl-18000):decl]
            ids=sorted({int(n) for n in re.findall(rb'\$([0-9]{4,})(?=[\t =\r\n])',pre)})
            named=[(s.decode('ascii'),int(n)) for s,n in re.findall(rb'(_[A-Za-z][\w]*?)\$([0-9]{4,})\s*=',pre)]
            return dict(where=where, kind=kind,k=k,flag=flag,diff=len(diffs),size=len(buf),digest=hashlib.sha256(buf).hexdigest(),
                        offsets=diffs if len(diffs)<=16 else None, function_ids=ids, named_ids=named)
    plan=[]
    if a.plan=='residues':
        plan = [('before', 'tag', k, '') for k in [*range(64),65,67,73,78,94,105,120,126,131,137]]
    elif a.plan=='flags':
        for flag in ['', '-G5','-G6','-G3','-Og-','-d2noblend','-d2nodlp']:
            for k in [0,1,3]:
                plan.append(('before','tag',k,flag))
    elif a.plan=='phase':
        for where,kind in [('before','tag'),('before','extern'),('head','tag'),('body','local'),('tail','tag')]:
            for k in [0,1,3,5,13,64,65]:
                plan.append((where,kind,k,''))
    elif a.plan=='headers':
        for where,kind in [('MissionClass','method'),('TechnoClass','method'),('MissionClass','inline'),('TechnoClass','inline')]:
            for k in [0,1,2,3,5,7,64,65]:
                plan.append((where,kind,k,''))
    else:
        for where in ['MissionClass','TechnoClass']:
            for kind in ['method','inline']:
                for k in [0,1,2,3,5,64,65]:
                    plan.append((where,kind,k,''))
        plan += [('TechnoClass','convert',k,'') for k in (0,1,2)]
    with a.output.open('w',encoding='utf8') as output, ThreadPoolExecutor(3) as ex:
        for row in ex.map(run,plan):
            print(json.dumps(row),file=output,flush=True)

if __name__=='__main__':
    main()

