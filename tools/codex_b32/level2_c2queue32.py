"""Model C2 8168's initial bucket scan and ordered insertion from measured records.

Input JSON array in bucket-insertion order. Each record needs a unique name,
allocator id, signed/unsigned integer primary and secondary rank fields.
Supply eligible=false to exclude a record already filtered by the caller. This
models one scan of the initial list; subsequent removals, rescores, recycling
and region splits require a new event stream. --verify runs the licensed
routine on disposable synthetic data, with the reference DLL pinned by hash.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess

DIGEST='45187b0b6288240f73272a7c61e6329c50048a76e57db3bb87b6f0229e09e27d'

def scan(nodes):
    buckets = [[] for _ in range(1024)]
    for row in nodes:
        if row.get('eligible', True):
            buckets[row['id'] & 1023].append(row)
    visit = [row for bucket in buckets for row in reversed(bucket)]
    def key(item):
        index, row = item
        unsigned = row['primary'] & 0xffffffff
        signed = unsigned if unsigned < 0x80000000 else unsigned - 0x100000000
        return signed, row['secondary'] & 0xffffffff, index
    ordered = sorted(enumerate(visit), key=key, reverse=True)
    return [row['name'] for _, row in ordered]

def verify(kit, work):
    vc = kit.resolve()/'vc6/VC98'
    dll = vc/'BIN/C2.DLL'
    if hashlib.sha256(dll.read_bytes()).hexdigest() != DIGEST:
        raise SystemExit('Unknown compiler build')
    work = work.resolve()
    work.mkdir(exist_ok=True,parents=True)
    env = os.environ.copy()
    env['PATH'] = os.pathsep.join([str(vc/'BIN'),str(vc.parent/'COMMON/MSDEV98/BIN'),env['PATH']])
    env['INCLUDE'] = str(vc/'INCLUDE')
    env['LIB'] = str(vc/'LIB')
    env['TMP'] = env['TEMP'] = str(work)
    source = Path(__file__).resolve().with_name('tile32_queuecheck.cpp')
    subprocess.run([str(vc/'BIN/CL.EXE'),'-nologo','-O2','-W3',
        '-Fotile32_queuecheck.obj','-Fetile32_queuecheck.exe',str(source),'kernel32.lib'],
        cwd=work,env=env,check=True)
    subprocess.run([str(work/'tile32_queuecheck.exe'),str(dll)],cwd=work,env=env,check=True)

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('nodes',type=Path,nargs='?')
    parser.add_argument('--verify',action='store_true')
    parser.add_argument('--kit',type=Path)
    parser.add_argument('--work',type=Path)
    args=parser.parse_args()
    if args.nodes:
        print(json.dumps(scan(json.loads(args.nodes.read_text()))))
    if args.verify:
        if not args.kit or not args.work:
            parser.error('--verify requires --kit and --work')
        verify(args.kit,args.work)

