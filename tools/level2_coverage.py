"""Level-2 coverage summary from the latest check report (read-only).

Counts code bytes (excluding trailing NOP/INT3 padding) of matched functions and of
library-identical CRT functions, against all non-padding bytes of GAME.EXE .text."""
import glob, json, os, struct
P = r'D:\<project-folder>\Coding\RedAlert2'
W = r'D:\<work-root>\RedAlert2Temp'
B = open(os.path.join(P, 'RA2Original', 'GAME.EXE'), 'rb').read()
pe = struct.unpack_from('<I', B, 0x3c)[0]; so = struct.unpack_from('<H', B, pe + 20)[0]
vs, va, rs, ra = struct.unpack_from('<IIII', B, pe + 24 + so + 8)
T = B[ra:ra + rs]
nonpad = sum(1 for x in T if x not in (0x90, 0xcc))


def body(rva, size):
    off = rva - va; end = off + size
    while end > off and T[end - 1] in (0x90, 0xcc):
        end -= 1
    return end - off


reports = sorted(glob.glob(os.path.join(W, 'analysis', 'level2', 'reports', 'check_*.json')))
report = reports[-1]
latest = {}
for path in reports:
    for f in json.load(open(path))['functions']:
        latest[f['rva']] = f
claims = {f['rva'] for f in json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))}
matched = [f for r, f in latest.items() if f['status'] == 'matched' and r in claims]
mbytes = sum(body(int(f['rva'], 16), f['size']) for f in matched)
init = [f for f in matched if f['symbol'].startswith('_$E')]
ibytes = sum(body(int(f['rva'], 16), f['size']) for f in init)
lib = json.load(open(os.path.join(P, 'metadata', 'level2_library.json')))
seen = {int(f['rva'], 16) for f in matched}
lbytes = sum(body(int(f['rva'], 16), f['size']) for f in lib['functions'] if int(f['rva'], 16) not in seen)
out = dict(report=os.path.basename(report), text_nonpad_bytes=nonpad,
           matched_functions=len(matched), matched_bytes=mbytes,
           of_which_static_initializers=len(init), initializer_bytes=ibytes,
           library_functions=lib['count'], library_bytes=lbytes,
           matched_share=round(100.0 * mbytes / nonpad, 2), with_library_share=round(100.0 * (mbytes + lbytes) / nonpad, 2))
json.dump(out, open(os.path.join(W, 'analysis', 'level2', 'reports', 'coverage_latest.json'), 'w'), indent=1)
print(json.dumps(out, indent=1))
