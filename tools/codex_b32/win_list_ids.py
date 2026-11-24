"""Extract numbered labels from listing emitted for WinMain. Retain only numerical metadata."""
import os, sys, subprocess, re, json
from pathlib import Path
kit=Path(sys.argv[1]).resolve(); tmp=Path(sys.argv[2]).resolve()
vc=kit/'vc6'/'VC98'; env=dict(os.environ,TMP=str(tmp),TEMP=str(tmp),INCLUDE=str(vc/'INCLUDE')+';'+str(vc/'ATL'/'INCLUDE'),PATH=str(vc/'BIN')+';'+str(kit/'vc6'/'COMMON'/'MSDEV98'/'BIN')+';'+os.environ['PATH'])
src=Path(sys.argv[3]).resolve()
stem=tmp/src.stem
subprocess.run([str(vc/'BIN'/'CL.EXE'),'/nologo','/c','/O2','/Ob2','/Gr','/GR','/DNDEBUG','/Gy','/DWIN32','/W0','/I'+str(kit/'m85'/'src'),'/I'+str(kit/'m85'/'include'),'/Fa'+str(stem)+'.asm','/FAs','/Fo'+str(stem)+'.lst.obj',str(src)],cwd=tmp,env=env,check=True)
asm=Path(str(stem)+'.asm').read_bytes().decode('latin1'); fn=asm.split('_WinMain@16 PROC',1)[1].split('_WinMain@16 ENDP',1)[0]
match = re.search(r'^_fileptr\$(\d+)\s*=\s*(-?\d+)', asm, re.M)
if match is None:
    raise ValueError('fileptr not found in listing')
print(json.dumps(dict(fileptr_id=int(match.group(1)), frame_offset=int(match.group(2)),
    first_numbered_labels=re.findall(r'^(\$[A-Za-z]+[0-9]+):',fn,re.M)[:40]),indent=2))
