import argparse, csv, difflib, importlib, json, os, runpy, subprocess, sys
from pathlib import Path
p=argparse.ArgumentParser()
p.add_argument('kit',type=Path)
p.add_argument('root',type=Path)
p.add_argument('mode',choices=['inspect','select','diagnostics'])
o=p.parse_args()
root=o.root.resolve(); kit=o.kit.resolve()
sys.path[:0]=[str(kit/'tools'),str(kit)]
out=root/'output'; temp=root/'temp'
if o.mode=='inspect':
 rows=list(csv.DictReader((out/'tile32_nested.csv').open()))
 for r in rows:
  if r['four_exact']=='0' and r['reverse']=='0':
   print('failed',*[r[k] for k in ['left','right','pred_a','pred_b','actual_a','actual_b','actual_inner','actual_outer']])
 sys.exit()
if o.mode=='diagnostics':
 for name,args in [('sdiff',['isotype.obj','Draw_Tile@IsometricTileTypeClass','12a490','80']),('calls_hist',['isotype.obj','Draw_Tile@IsometricTileTypeClass','12a490','1b40']),('l2dis',['12a490','c0'])]:
  os.chdir(temp/'final')
  script=kit/'tools'/(name+'.py')
  sys.argv=[str(script)]+args
  with (temp/(name+'.private.txt')).open('w') as f:
   saved=sys.stdout;sys.stdout=f
   try:runpy.run_path(str(script),run_name='__main__')
   finally:sys.stdout=saved
 sys.exit()
import l2match
from coffmatch import Obj
spec=json.loads((out/'tile32_b.json').read_text())
rows=[json.loads(l) for l in (out/'tile32_b.results.jsonl').read_text().splitlines()]
source=(root/'input/isotype.cpp').read_bytes(); text=source.decode('latin1').replace('\r\n','\n')
vc=kit/'vc6'; env=os.environ.copy()
env['PATH']=os.pathsep.join([str(vc/'VC98/BIN'),str(vc/'COMMON/MSDEV98/BIN'),env['PATH']])
env['INCLUDE']=os.pathsep.join([str(vc/'VC98/INCLUDE'),str(vc/'VC98/ATL/INCLUDE')]);env['TMP']=env['TEMP']=str(temp)
folder=temp/'final';folder.mkdir(exist_ok=True)
def compileone(cpp):
 path=folder/'isotype.cpp';objpath=folder/'isotype.obj'
 path.write_bytes((cpp.replace('\n','\r\n') if b'\r\n' in source else cpp).encode('latin1'))
 flags=['-nologo','-c','-O2','-Ob2','-Gr','-GR','-DNDEBUG','-Gy','-DWIN32','-W0','-I'+str(kit/'m85/src'),'-I'+str(kit/'m85/include')]
 subprocess.run([str(vc/'VC98/BIN/CL.EXE'),*flags,'-Fo'+str(objpath),str(path)],cwd=folder,env=env,capture_output=True,check=True)
 obj=Obj(objpath.read_bytes())
 sig={}
 for n in obj.symbols:
  s=obj.function(n);sig[n]=(s['raw'],[(off,obj.by_index[i]['name'],typ) for off,i,typ in s['relocs']])
 t,=spec['targets'];result=l2match.run(str(objpath),t[0],int(t[1],16),{})
 ctrls=[l2match.run(str(objpath),n,int(a,16),{})['byte_differences'] for n,a in spec['controls']]
 return (sig,dict(size=result['size'],positional=result['byte_differences'],full=result['byte_differences']+6976-result['size'],controls=ctrls))
def variant(combo):
 cpp=text
 for c,opt in zip(spec['choices'],combo):
  for old,new,anchor in c['options'][opt]['edits']:
   idx=cpp.index(anchor);a,b=cpp[:idx],cpp[idx:]
   if old not in b:raise ValueError(old)
   cpp=a+b.replace(old,new,1)
 return cpp
def tidy(cpp):
 if 'int & variation = cell_variation;' in cpp:
  i=cpp.index('int & variation = cell_variation;')
  j=cpp.index('next->Draw_Tile',i)
  import re
  s=cpp[i:j].replace('int & variation = cell_variation;\n','')
  s=re.sub(r'\bvariation\b','cell_variation',s)
  s=s.replace('\t\t\t\t\t\tcell_variation =','\t\t\tcell_variation =',1)
  s=s.replace('cell_variation = cell_variation > num - 1 ? cell_variation % num : cell_variation;', 'if (cell_variation > num - 1) {\n\t\t\t\tcell_variation %= num;\n\t\t\t}')
  cpp=cpp[:i]+s+cpp[j:]
 cpp=cpp.replace('\t\t\t\t\t\t\t}\n\t\t\t\t\t\tspan_count = scan', '\t\t\t\t\t\t}\n\t\t\t\t\t\tspan_count = scan')
 return cpp
baseline,b=compileone(text)
sym,=[n for n in baseline if spec['targets'][0][0] in n]
rows=[r for r in rows if r.get('controls_ok') and r['score'] is not None]
best=[]; seen=set()
for r in sorted(rows,key=lambda r:(r['score'],abs(r['targets'][0]['size']-6976))):
 key=(r['score'],r['targets'][0]['size'])
 if key in seen:continue
 seen.add(key);best.append(r)
 if len(best)==16:break
assessment=[dict(combo=[0]*8,hunks=344,siblings=len(baseline)-1,changed=[],**b)]
kept=None
byte_rows=[json.loads(l) for l in (out/'tile32_bytes.results.jsonl').read_text().splitlines()]
byte_rows.sort(key=lambda r:(r['score']+6976-r['targets'][0]['size'],sum(r['combo'])))
by_hash={r['hash']:r for r in rows}
best.insert(0,by_hash[byte_rows[0]['hash']])
for r in best:
 combo=(r['combo']+[0]*8)[:8]
 cpp=variant(combo)
 sig,b=compileone(cpp)
 changed=[n for n in (set(sig)|set(baseline)) if n!=sym and sig.get(n)!=baseline.get(n)]
 row=dict(combo=combo,hunks=r['score'],siblings=len(baseline)-1,changed=changed,**b)
 assessment.append(row)
 rank=(row['full'],row['hunks'])
 if row['full']<4160 and row['hunks']<344 and not changed and not any(row['controls']) and (kept is None or rank<kept[0]):kept=(rank,cpp,row)
 (out/'tile32_finalists.json').write_text(json.dumps(assessment,indent=2)+'\n')
if kept is None:raise SystemExit('No dual improvement, inspect report')
_,cpp,row=kept
import re
sig,b=compileone(cpp)
left=cpp.index('\t\t\tint & variation = cell_variation;')
right=cpp.index('next->Draw_Tile',left)
region=cpp[left:right].split('\n',1)[1]
region=re.sub(r'\bvariation\b','cell_variation',region)
direct=cpp[:left]+region+cpp[right:]
clean=direct.replace('cell_variation = cell_variation > num - 1 ? cell_variation % num : cell_variation;', 'if (cell_variation > num - 1) {\n\t\t\t\tcell_variation %= num;\n\t\t\t}')
for candidate,kind in ((clean,'direct-conditional'),(direct,'direct-ternary'),(cpp,'search-spelling')):
 ts,cb=compileone(candidate)
 if ts==sig:break
row['selected']=True;row['final_spelling']=kind;row['all_functions_identical_to_search_spelling']=ts==sig
(out/'tile32_finalists.json').write_text(json.dumps(assessment,indent=2)+'\n')
(out/'isotype.cpp').write_bytes((folder/'isotype.cpp').read_bytes())
print(row)

