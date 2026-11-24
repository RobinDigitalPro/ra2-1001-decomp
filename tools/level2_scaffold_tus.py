"""Create level-2 translation-unit files for every GAMECONST.H initializer block and claim the 12
header initializers per TU.  Named TUs use the original C:/RA2 file name (anchor evidence);
the others get provisional names unnamed/TU_<block rva>.cpp until identified.  Existing files are kept."""
import json, os
P = r'D:\<project-folder>\Coding\RedAlert2'
W = r'D:\<work-root>\RedAlert2Temp'
blocks = json.load(open(os.path.join(W, 'analysis', 'level2', 'gameconst_blocks.json')))
known = {'0xfd20': 'Abstract.cpp', '0x103b0': 'AbsType.cpp'}   # already reconstructed TUs
funcs = json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))
have = {f['rva'] for f in funcs}
names = ['CellDiagonal', 'A2', 'A3', 'Rad45', 'Rad60', 'Rad90', 'I7', 'A8', 'A9', 'I10', 'EmptyCell', 'EmptyCoord']
created = 0; added = 0
for b in blocks:
    if b['start'] in known:
        continue
    if b['names']:
        rel = 'src/ra2/' + b['names'][0]
        title = 'C:' + chr(92) + 'RA2' + chr(92) + b['names'][0]
    else:
        rel = 'src/ra2/unnamed/TU_%06X.cpp' % (int(b['start'], 16) + 0x400000)
        title = 'unidentified translation unit (GAMECONST.H initializers at %s)' % b['start']
    path = os.path.join(P, *rel.split('/'))
    os.makedirs(os.path.dirname(path), exist_ok=True)
    if not os.path.exists(path):
        inc = '"GAMECONST.H"' if not rel.startswith('src/ra2/unnamed/') else '"../GAMECONST.H"'
        open(path, 'w', newline='\r\n').write('// %s (level-2 reconstruction of GAME.EXE 1.001)\n'
            '// Only the shared header initializers are reconstructed so far.\n#include %s\n' % (title, inc))
        created += 1
    for k, rva in enumerate(b['rvas']):
        if rva in have:
            continue
        funcs.append(dict(rva=rva, tu=rel, symbol='_$E%d' % (2 + 3 * k), name='dynamic initializer of GAMECONST.H static %s' % names[k]))
        added += 1
funcs.sort(key=lambda x: int(x['rva'], 16))
json.dump(funcs, open(os.path.join(P, 'metadata', 'level2_functions.json'), 'w', encoding='utf-8'), indent=1)
print('created files', created, 'added claims', added, 'total claims', len(funcs))
