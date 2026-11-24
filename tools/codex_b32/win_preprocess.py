from pathlib import Path
import os,sys,subprocess
kit=Path(sys.argv[1]).resolve(); tmp=Path(sys.argv[2]).resolve()
vc=kit/'vc6'/'VC98'; env=dict(os.environ,TMP=str(tmp),TEMP=str(tmp),INCLUDE=str(vc/'INCLUDE')+';'+str(vc/'ATL'/'INCLUDE'),PATH=str(vc/'BIN')+';'+str(kit/'vc6'/'COMMON'/'MSDEV98'/'BIN')+';'+os.environ['PATH'])
src=Path(sys.argv[3]).resolve()
with (tmp/'startup_pp.cpp').open('wb') as out:
 subprocess.run([str(vc/'BIN'/'CL.EXE'),'/nologo','/E','/O2','/Ob2','/Gr','/GR','/DNDEBUG','/Gy','/DWIN32','/W0','/I'+str(kit/'m85'/'src'),'/I'+str(kit/'m85'/'include'),str(src)],stdout=out,cwd=tmp,env=env,check=True)

