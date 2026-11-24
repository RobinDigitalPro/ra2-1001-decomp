import json, shutil
from pathlib import Path
src=Path('source/startup.cpp')
out=Path('output'); out.mkdir(exist_ok=True)
shutil.copyfile(src,out/'startup.cpp')
controls=[['?Top_Level_Exception_Filter@@YIJPAU_EXCEPTION_POINTERS@@@Z','0x283960'],['?Prog_End@@YAXXZ','0x2860d0'],['?SetRegKeyValue@@YI_NQBD00@Z','0x2832b0'],['?Reset_Surfaces@@YIXXZ','0x2838b0']]
spec=dict(base='startup.cpp',preset='m85',controls=controls,targets=[['_WinMain@16','0x283970']],choices=[])
# The anchor is retained by every option, so independent choices may be combined.
anchor='int CALLBACK WinMain ('
for idx,k in enumerate((1,2,4,8,16,32)):
    decl=' '.join('struct WinCounter_%d_%d;'%(idx,i) for i in range(k))
    spec['choices'].append(dict(name='prefix_tags_'+str(k),options=[dict(label='current',edits=[]),dict(label='add_'+str(k),edits=[[anchor,decl+' '+anchor]])]))
    if idx in (2,5): (out/('startup32_%s.json'%('first' if idx==2 else 'extended'))).write_text(json.dumps(spec,indent=2),encoding='utf8')
(out/'edits_startup_1.json').write_text('[]\n',encoding='utf8')

