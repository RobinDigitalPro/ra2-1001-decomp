"""Rename scaffold TUs whose GAMECONST block was wrongly named (other TU initializers lie between the block
and the file-name anchor). Edited files are skipped. Updates claims and gameconst_blocks.json."""
import json, os
P = r'D:\<project-folder>\Coding\RedAlert2'
W = r'D:\<work-root>\RedAlert2Temp'
BS = chr(92)
sus = {'Display.CPP': '0x98560', 'Ini.CPP': '0x108d80', 'Ion.cpp': '0x11e450', 'MapGen.cpp': '0x16a0c0',
       'MSChoice.cpp': '0x1a8d20', 'ownrdraw.cpp': '0x1d6d00', 'PlanMgr.cpp': '0x207d90', 'Queue.CPP': '0x21ab40',
       'Radar.CPP': '0x2261b0', 'Scenario.CPP': '0x252350', 'Sidebar.CPP': '0x270c60', 'Tactical.CPP': '0x297720',
       'TAction.CPP': '0x2a2750', 'wonline.cpp': '0x32f2b0', 'wwmous.cpp': '0x357f30'}
f = json.load(open(os.path.join(P, 'metadata', 'level2_functions.json'), encoding='utf-8'))
b = json.load(open(os.path.join(W, 'analysis', 'level2', 'gameconst_blocks.json')))
moved = 0
for name, start in sus.items():
    old = 'src/ra2/' + name
    new = 'src/ra2/unnamed/TU_%06X.cpp' % (int(start, 16) + 0x400000)
    op = os.path.join(P, *old.split('/')); np = os.path.join(P, *new.split('/'))
    if not os.path.exists(op):
        print('missing', name); continue
    src = open(op, encoding='latin1').read()
    if src.count('\n') > 4:
        print('skip (edited):', name); continue
    src = src.replace('// C:' + BS + 'RA2' + BS + name, '// unidentified translation unit (GAMECONST.H initializers at %s; previously misnamed %s)' % (start, name))
    src = src.replace('#include "GAMECONST.H"', '#include "../GAMECONST.H"')
    open(np, 'w', encoding='latin1', newline='').write(src)
    os.remove(op)
    for x in f:
        if x['tu'] == old:
            x['tu'] = new; moved += 1
    for x in b:
        if x['start'] == start:
            x['names'] = []; x['note'] = 'name %s was wrong: other TU initializers lie between this block and the anchor' % name
json.dump(f, open(os.path.join(P, 'metadata', 'level2_functions.json'), 'w', encoding='utf-8'), indent=1)
json.dump(b, open(os.path.join(W, 'analysis', 'level2', 'gameconst_blocks.json'), 'w'), indent=0)
print('claims moved', moved)
