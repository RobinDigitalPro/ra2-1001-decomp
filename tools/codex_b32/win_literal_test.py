"""Test early interning of the first new string at the measured statement boundary.
Run from the reservation, with arguments KIT SOURCE TEMP OUTPUT and optional probe path.
Writes only local synthetic TU copies and JSONL measurements. The dead expression is diagnostic.
"""
import subprocess,sys,json
from pathlib import Path
kit,src,tmp,out=map(Path,sys.argv[1:5])
probe=Path(sys.argv[5]) if len(sys.argv)>5 else Path(__file__).with_name('win_counter_probe.py')
body=src.read_bytes(); anchor=b'Message_Box_Wide(MainWindow, StringTable::LoadString("TXT_VIDEO_ERROR",'
assert body.count(anchor)==2
with out.open('w') as sink:
    for label,insert in [('new','(void)"TXT_VIDEO_ERROR"; '),('old','(void)"TXT_SHORT_TITLE"; '),('none','(void)0; ')]:
        for side in ['before','after']:
            tag=' '.join('struct WinProbe%d;'%i for i in range(int(sys.argv[6]) if len(sys.argv)>6 else 4))
            text=insert+tag+' ' if side=='before' else tag+' '+insert
            cpp=tmp/('intern_'+label+'_'+side+'.cpp')
            cpp.write_bytes(body.replace(anchor,text.encode()+anchor,1))
            target=tmp/('intern_'+label+'_'+side+'.jsonl')
            subprocess.run([sys.executable,'-I','-B',str(probe),'--kit',str(kit),'--source',str(cpp),'--temp',str(tmp),'--counts','0','--out',str(target)],check=True)
            r=json.loads(target.read_text()); r.update(seed=label,when=side)
            print(json.dumps(r),file=sink,flush=True)

