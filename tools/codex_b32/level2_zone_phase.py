"""Measure VC6 map declaration-order and header interactions without changing the kit.

Run against the submitted map.cpp in the refreshed kit. Uses a private temporary
directory, a stock preprocessor capture and isolated compiler output per trial.
The public ledger contains measurements only. Calibrate on copies of this TU.
"""
import argparse
import concurrent.futures
import csv
import hashlib
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import tempfile

TARGET = '?Zone_Reset@MapClass@@QAEHXZ'
CONTROLS = [('?Close_Object@MapClass@@QBEPAVObjectClass@@ABVCoord@@@Z', 0x14bd60),
            ('?SubzoneHash@@YIHABI@Z', 0x14c6d0), ('?Validate@MapClass@@QAEHXZ', 0x14bd50),
            ('?Get_Cell_Zone@MapClass@@QAEHABVCell@@W4MZoneType@@_N@Z', 0x14cd80)]
OPTIONS = ['-nologo', '-O2', '-Ob2', '-Gr', '-GR', '-DNDEBUG', '-Gy', '-DWIN32', '-W0']
ENTRY = 'int MapClass::Zone_Reset(void)\n{'
CTORS = '\n\t\t\tCountryName() {}\n\t\t\texplicit CountryName(char const * source);'
FACE = 'return abs(Facing) >= abs(rvalue.Facing);'
NAMED = 'int a = abs(Facing); int b = abs(rvalue.Facing); return a >= b;'

def once(source, old, new):
    if source.count(old) != 1:
        raise ValueError(f'expected one occurrence of {old!r}, got {source.count(old)}')
    return source.replace(old, new)

def variant(source, header, position, placement, count):
    if header in ('old', 'old_face') and CTORS in source:
        source = once(source, CTORS, '')
    if 'face' in header and FACE in source:
        source = once(source, FACE, NAMED)
    if position == 'allocation':
        source = once(source, ENTRY + '\n\tunsigned short * zone_degree;', ENTRY)
        source = once(source, '\tzone_degree = new unsigned short[ZoneCount];',
                      '\tunsigned short * zone_degree = new unsigned short[ZoneCount];')
    if count:
        externs = ''.join(f'extern int zone_phase_probe_{i};\n' for i in range(count))
        if placement == 'top':
            source = externs + source
        elif placement == 'before':
            source = once(source, ENTRY, externs + ENTRY)
        elif placement == 'inside':
            locals_ = ''.join(f'\n\tint zone_phase_probe_{i};' for i in range(count))
            source = once(source, ENTRY, ENTRY + locals_)
    return source

def run():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('kit', type=Path)
    parser.add_argument('source', type=Path)
    parser.add_argument('ledger', type=Path)
    parser.add_argument('--temp', type=Path, required=True)
    parser.add_argument('--experiment', choices=['matrix', 'sweep','cross'], default='matrix')
    parser.add_argument('--workers', type=int, default=3)
    parser.add_argument('--sites', default='before,top,inside')
    parser.add_argument('--include', type=Path, help='alternate full m85/include tree for historical replay')
    parser.add_argument('--direct', action='store_true', help='compile normal TU and private header trees instead of a /P capture')
    parser.add_argument('--counts', help='comma-separated counts or inclusive lo-hi ranges')
    args = parser.parse_args()
    kit = args.kit.resolve()
    temp = args.temp.resolve()
    source = args.source.resolve()
    temp.mkdir(exist_ok=True, parents=True)
    sys.path[:0] = [str(kit/'tools'), str(kit)]
    from coffmatch import Obj, match_function
    from l2match import orig
    vc = kit/'vc6'
    compiler = vc/'VC98/BIN/CL.EXE'
    env = dict(os.environ, TEMP=str(temp), TMP=str(temp), PATH=os.pathsep.join(
        [str(compiler.parent), str(vc/'COMMON/MSDEV98/BIN'), os.environ['PATH']]),
        INCLUDE=os.pathsep.join([str(vc/'VC98/INCLUDE'), str(vc/'VC98/ATL/INCLUDE')]))
    with tempfile.TemporaryDirectory(dir=temp) as folder:
        scratch = Path(folder)
        preprocess = [str(compiler), *OPTIONS, '-P', '-I'+str(kit/'m85/src'),
                      '-I'+str(args.include.resolve() if args.include else kit/'m85/include'), str(source)]
        headers = {}
        if args.direct:
            base = source.read_text(encoding='latin1')
            for header in ('current','old','face','old_face'):
                tree = scratch/('headers_'+header)
                shutil.copytree(args.include or kit/'m85/include', tree)
                headers[header] = ['-I'+str(kit/'m85/src'), '-I'+str(tree)]
                for filename, original, replacement in [('houstype.h', CTORS, ''), ('face.h', FACE, NAMED)]:
                    path = tree/filename
                    content = path.read_text(encoding='latin1')
                    if filename == 'houstype.h':
                        if CTORS not in content:
                            content = once(content, 'char Buffer[25];', 'char Buffer[25];'+CTORS)
                        if header in ('old','old_face'):
                            content = once(content, CTORS, '')
                    elif 'face' in header:
                        content = once(content, original, replacement)
                    path.write_bytes(content.replace('\n','\r\n').encode('latin1'))
        else:
            subprocess.run(preprocess, env=env, cwd=scratch, check=True, capture_output=True)
            base = (scratch/(source.stem+'.i')).read_text(encoding='latin1')
        if not args.direct and CTORS not in base:
            base = once(base, 'char Buffer[25];\n\t\t};',
                        'char Buffer[25];' + CTORS + '\n\t\t};')
        def trial(case):
            header, position, placement, count = case
            label = f'{header}_{position}_{placement}_{count}'
            here = scratch/label
            here.mkdir()
            (here/'sample.cpp').write_bytes(variant(base, *case).replace('\n','\r\n').encode('latin1'))
            command = [str(compiler), *OPTIONS, *headers.get(header,[]), '-c', '-FA', '-Falisting.asm', '-Fosample.obj', 'sample.cpp']
            build = subprocess.run(command, cwd=here, env=env, capture_output=True)
            if build.returncode:
                raise ValueError(build.stdout.decode('latin1')[-1200:])
            obj = Obj((here/'sample.obj').read_bytes())
            code = obj.function(TARGET)
            def compare(symbol, rva):
                section = obj.function(symbol)
                return match_function(obj, symbol, orig(rva,len(section['raw'])), 0x400000+rva, lambda _: None)
            result = compare(TARGET, 0x14c060)
            listing = (here/'listing.asm').read_text(encoding='latin1')
            decl = listing.split('\n'+TARGET+' PROC ',1)[0].rsplit('_TEXT\tSEGMENT',1)[-1]
            def number(pattern):
                match = re.search(pattern, decl, re.MULTILINE)
                return int(match[1]) if match else None
            off = [i for i,(x,y) in enumerate(zip(code['raw'], orig(0x14c060,len(code['raw'])))) if x!=y and
                   not any(p<=i<p+4 for p,_,_ in code['relocs'])]
            row = dict(header=header, position=position, placement=placement, count=count,
                       pass_id=number(r'^_pass\$(\d+) ='), this_home=number(r'^_this\$ = (-?\d+)'),
                       degree_home=number(r'^_zone_degree\$ = (-?\d+)'), status=result['status'],
                       differences=result['byte_differences'], offsets=','.join(f'{i:x}' for i in off),
                       control_differences=','.join(str(compare(s,r)['byte_differences']) for s,r in CONTROLS),
                       section_hash=hashlib.sha256(code['raw']).hexdigest())
            for file in here.iterdir():
                file.unlink()
            here.rmdir()
            return row
        def counts(value):
            for group in value.split(','):
                span = [int(x) for x in group.split('-')]
                yield from range(span[0],span[-1]+1)
        if args.experiment == 'matrix':
            cases = [(h,p,'before',0) for h in ('current','old','face','old_face')
                     for p in ('entry','allocation')]
        elif args.experiment == 'sweep':
            cases = [('current','entry',site,n) for n in counts(args.counts or '0-64')
                     for site in args.sites.split(',')]
        else:
            cases = [(h,p,'before',n) for n in counts(args.counts or '0,1,3,7,16,32,48,62,64')
                     for h in ('current','old','face','old_face') for p in ('entry','allocation')]
        with args.ledger.open('w', encoding='utf8',newline='') as f, concurrent.futures.ThreadPoolExecutor(args.workers) as pool:
            writer = None
            for row in pool.map(trial,cases):
                if writer is None:
                    writer = csv.DictWriter(f,fieldnames=row)
                    writer.writeheader()
                writer.writerow(row)
                f.flush()
if __name__ == '__main__':
    run()
