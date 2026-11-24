"""Compile dated Level 2 REPORT.md files and optional agent notes into a long-form CSV.

Usage: python level2_ledger.py reports_directory --notes batch28_dsurface.md -o ledger.csv
Directories are searched recursively for *REPORT.md; files may be given explicitly.
Batch number comes from filename, containing directory, or the first heading mentioning
"batch N". Historical scopes are in ledger_scope.json. For a new batch, provide a
Markdown table with columns batch (optional), function, rva, TU, best differing bytes,
input differing bytes (optional), blocker class and last forms tried. Use that same
table in optional agent notes, or give a raw try.py log with --notes for an existing
batch. Unscoped raw logs require a target table to distinguish targets from controls.
One attempt means one documented target round per batch, across all notes for that batch.
A round with a known equal input counts as one unsuccessful round. A first observation
without input sets a baseline. Unknown scores do not consume a retry. Native and
diagnostic contexts are separate series. Counts are reported positional bytes, never
hunks. A report may omit trial byte scores; the minimum is over documented measurements.
"""
import argparse
import csv
import json
import re
from collections import defaultdict
from pathlib import Path

BATCH = re.compile(r'batch[\s_/-]*(\d+[a-z]?)\b', re.I)
MEASURE = re.compile(r'([?\w$@<>~]+)\s+(mismatch|not_matched|matched|bytes_match_bindings_open)\s+\d+\s+\d+\s+(\d+)\b')
RVA = re.compile(r'(?<![\w])(?:0x)?([0-9a-f]{5,6})(?![\w])', re.I)
SPEC = re.compile(r'[\w.-]+\.json\b', re.I)
VALUE = re.compile(r'\d[\d,]*')
BLOCKERS = [
    ('header context', r'diagnostic header|missing header|inferred header|authentic build'),
    ('declaration/symbol order', r'symbol[- ](?:order|number|hash)|hash[- ]order|period.?64'),
    ('stack slot packing', r'stack[- ]slot|frame[- ]slot|slot[- ]pack|frame allocation'),
    ('inline decision', r'inline decision|inlining|inline budget|out.of.line'),
    ('instruction ordering', r'load[- ]order|evaluation order|instruction order|scheduling'),
    ('register allocation', r'register|allocation tie|ESI.{0,15}EDI'),
    ('control flow', r'branch|epilogue|tail[- ]merg'),
    ('operand width', r'operand width|16.bit|8.bit'),
]
SPECIAL_NAMES = {'1c4330':'Show_Slot_Controls', '1c44c0':'Hide_Slot_Controls',
    '17eeb0':'Grow_Water_Region','16aef0':'Create_Region_From_Cell',
    '292ef0':'Place@SuperClass','12a490':'Draw_Tile@IsometricTileTypeClass',
    '339df0':'Create_Game_Channel','34e040':'OnUserList@CChatEventSink',
    '32f4c0':'_$E123','32f4f0':'_$E128','33fe10':'Start_Test_Game',
    '351030':'OnUserKick@CChatEventSink','ac360':'Draw_Depth_Antialiased_Line@DSurface'}
FIELDS = ['batch','function','rva','TU','context','attempts','best differing bytes per batch',
          'input differing bytes','delivered differing bytes','blocker class','last forms tried',
          'no gain rounds','retry budget left','status','evidence','form evidence']
# Ordered columns of the author-provided top-level outcome tables. The sidecar gives their
# reviewed row identities. Later group tables use explicit actual RVAs and matcher text.
SUMMARY = {'13c':(None,1),'14':(2,3),'15':(2,3),'16':(2,3),'17':(1,2),
           '18':(1,1),'19':(2,3),'21':(1,2),'22':(1,2),'23':(1,2)}
def number(value):
    match = VALUE.fullmatch(str(value).strip())
    return int(match[0].replace(',', '')) if match else None

def clean(s):
    return s.strip().strip('\x60* ').strip()

def cells(line):
    return [clean(c) for c in line.strip().strip('|').split('|')]

def normalized_name(name):
    if name.startswith('??'):
        return name.split('@@')[0] + '@@'
    return name.lstrip('?').split('@@')[0].strip('@')

def batch_sort(b):
    m = re.fullmatch(r'(\d+)([a-z]?)', b)
    return (int(m[1]),m[2])

def read_file(path):
    lines = path.read_text(encoding='utf-8-sig').splitlines()
    # An underscore immediately following a numerical batch ID is a separator in filenames.
    for hint in (path.stem.replace('_',' '),path.parent.name.replace('_',' '),
                 '\n'.join(lines[:12])):
        m = BATCH.search(hint)
        if m:
            return m[1].lower(), lines
    raise ValueError(f'Cannot determine batch for {path}')

def group_text(lines, index):
    starts = [i for i,l in enumerate(lines) if re.match(r'^#{1,2} ',l) or l.startswith('<!-- target ')]
    start=max((i for i in starts if i<=index),default=0)
    end=next((i for i in starts if i>index),len(lines))
    return start,end

def init(target):
    return dict(target=target, scores=[], inputs=[], outputs=[], forms=[], form_ref=[],
                name=SPECIAL_NAMES.get(target,''),tu='',block='',context='project',extra=set())

def score(row, val, ref, field='scores'):
    if val is not None:
        row[field].append((val,ref))
        if field != 'scores':
            row['scores'].append((val,ref))

def add_table_notes(lines, rows, ref):
    header=[]
    for i,l in enumerate(lines):
        if not l.startswith('|'):
            header=[]
            continue
        vals=cells(l)
        if 'function' in [x.lower() for x in vals] and 'rva' in [x.lower() for x in vals]:
            header=[x.lower() for x in vals]
            continue
        if not header or len(vals)!=len(header):
            continue
        entry=dict(zip(header,vals))
        best_key=next((k for k in ('best differing bytes','best differing bytes per batch') if k in entry),None)
        if not best_key:
            continue
        m=RVA.fullmatch(entry['rva'])
        if not m:
            continue
        key=m[1].lower()
        row=rows.setdefault(key,init(key))
        row['name']=entry['function']
        if entry.get('tu'): row['tu']=entry['tu']
        if entry.get('context'): row['context']=entry['context']
        if entry.get('blocker class'): row['block']=entry['blocker class']
        if entry.get('last forms tried'):
            row['forms'].append(entry['last forms tried'])
            row['form_ref'].append(ref(i))
        score(row,number(entry[best_key]),ref(i))
        score(row,number(entry.get('input differing bytes','')),ref(i),'inputs')
        score(row,number(entry.get('delivered differing bytes','')),ref(i),'outputs')

def top_summary(batch,lines,rows,ids,ref):
    if batch not in SUMMARY: return
    # Reports 19 and 22 have other tables. Locate the scored table by its actual headers.
    header=next((i for i,l in enumerate(lines) if l.startswith('|') and re.search(
        r'Input (?:byte |differing bytes|differences)|Initial differing bytes|before → delivered|Final comparison',l,re.I)),None)
    if header is None: return
    data=[]
    for i in range(header+2,len(lines)):
        if not lines[i].startswith('|'): break
        vals=cells(lines[i])
        if batch=='14' and '$E109' in vals[0]: continue
        data.append((i,vals))
    if batch=='22':
        # Mouse row is a combined summary, not an individual target measurement.
        ids=[r for r in ids if r!='35e710']
    for target,(i,vals) in zip(ids,data):
        row=rows[target]
        if batch=='22' and target=='35e400': continue
        a,b=SUMMARY[batch]
        if batch=='13c':
            n=VALUE.search(vals[b])
            v=number(n[0]) if n else None
            score(row,v,ref(i),'outputs')
        elif batch=='18':
            values=VALUE.findall(vals[b].split(' in retained')[0])
            if len(values)==2:
                score(row,number(values[0]),ref(i),'inputs')
                score(row,number(values[1]),ref(i),'outputs')
        else:
            score(row,number(vals[a]),ref(i),'inputs')
            score(row,number(vals[b]),ref(i),'outputs')

def ingest(batch,path,lines,rows,ids,notes):
    ref=lambda i:f'{path.name}:{i+1}'
    add_table_notes(lines,rows,ref)
    if not notes: top_summary(batch,lines,rows,ids,ref)
    evidence=defaultdict(list)
    for i,line in enumerate(lines):
        ids_here=[m[1].lower() for m in RVA.finditer(line) if m[1].lower() in rows]
        matches=list(MEASURE.finditer(line))
        if len(set(ids_here))==1 and len(matches)==1:
            key=ids_here[0]; row=rows[key]; m=matches[0]
            if batch=='20' and key in ('35e400','35e710') and m[2]!='mismatch':
                continue  # The zero occurred with a private shared-header edit, outside scope.
            score(row,int(m[3]),ref(i))
            if not row['name']:row['name']=normalized_name(m[1])
            evidence[key].append(i)
        elif len(set(ids_here))==1 and batch=='26' and line.startswith('|'):
            m=re.search(r'(\d[\d,]*) differing bytes in ',line)
            if m:
                key=ids_here[0]
                score(rows[key],number(m[1]),ref(i),'outputs')
                evidence[key].append(i)
        if batch=='20':
            if line.startswith('| 35e') and len(ids_here)==1:
                table=cells(line)
                if table[1]=='mismatch':
                    score(rows[ids_here[0]],number(table[-1]),ref(i),'outputs')
                    if not rows[ids_here[0]]['name']:
                        rows[ids_here[0]]['name']=table[0].split()[1]+'@WWMouseClass'
                    evidence[ids_here[0]].append(i)
            for key,pattern in [('5f380',r'input scored 140 hunks and ([\d,]+) positional'),
                                ('402b0',r'baseline raw difference was ([\d,]+) bytes'),
                                ('ac360',r'differing-byte count from ([\d,]+) to'),
                                ('145970',r'from ([\d,]+) to [\d,]+ for Set_Map_Dimensions'),
                                ('152ef0',r'([\d,]+) to [\d,]+ for Repair_Bridge'),
                                ('15fd40',r'([\d,]+) to [\d,]+ for Collapse_Cliff'),
                                ('12a490',r'Draw_Tile improves from ([\d,]+) to')]:
                m=re.search(pattern,line,re.I)
                if m:score(rows[key],number(m[1]),ref(i),'inputs')
        if batch=='22' and line.startswith('| STL_Score_Dialog_Proc |'):
            score(rows['28fe70'],number(cells(line)[-1]),ref(i),'outputs')
        if batch=='22' and 'Flow combination [3, 2, 2]' in line:
            m=re.search(r'reduced differences to ([\d,]+) bytes',line)
            if m:score(rows['ac360'],number(m[1]),ref(i))
        if batch=='25' and 'Fire_At improved from' in line:
            m=re.search(r'byte differences increased from ([\d,]+) to ([\d,]+)',line)
            if m:
                score(rows['2bfe50'],number(m[1]),ref(i),'inputs')
                score(rows['2bfe50'],number(m[2]),ref(i),'outputs')
    for key,row in rows.items():
        if notes or row['forms']:continue
        name=row['name'].split('@')[0].lower()
        heading_indices=[i for i,l in enumerate(lines) if l.startswith('#') and (
            key in [m[1].lower() for m in RVA.finditer(l)] or (len(name)>3 and name in l.lower()))]
        probes=heading_indices or evidence[key]
        if not probes:continue
        # For grouped findings, explicitly identify the scope and retain source lines.
        ix=probes[-1]
        lo,hi=group_text(lines,ix)
        lineset=list(enumerate(lines[lo:hi],lo))
        forms=[]
        for i,line in lineset:
            if SPEC.search(line) and (line.startswith('|') or re.search(r'spec|greedy|round|hunk',line,re.I)):
                for s in SPEC.findall(line):
                    if not re.search(r'edit|audit|validat|verif|scores|manifest|binding|summary|index|\.results',s,re.I):
                        forms.append((s,i))
        if forms:
            chosen=list(dict((s,i) for s,i in forms).items())[-4:]
            labels=[]
            for s,i in chosen:
                columns=cells(lines[i]) if lines[i].startswith('|') else []
                descriptor=next((c for c in columns if s not in c and re.search(r'[a-zA-Z]{3,}',c)
                                 and not SPEC.search(c) and len(c)<150), '')
                labels.append(s+(' ('+descriptor+')' if descriptor else ''))
            row['forms'].append('section specs: '+', '.join(labels))
            row['form_ref']+=[ref(i) for s,i in chosen]
        else:
            hits=[(i,line.strip()) for i,line in lineset if len(line)>35 and not line.lstrip().startswith(('#','0x')) and
                  re.search(r'\b(?:tried|explored|variants?|helpers?|swapped|lookups?|search|specs?|already present|changes? the order|tested|greedy|retains?|segmented distances)\b',line,re.I)]
            if name and len(name)>3:
                local_hits=[(i,l) for i,l in hits if name in l.lower()]
                if local_hits: hits=local_hits
            if hits:
                i,line=hits[-1]; row['forms'].append('section: '+line[:230]);row['form_ref'].append(ref(i))
        text=' '.join(l for _,l in lineset)
        if not row['block']:
            classes=[c for c,pattern in BLOCKERS if re.search(pattern,text,re.I)]
            if classes:
                row['block']='section evidence: '+', '.join(classes[:2])
    if not notes:
        if batch=='18' and '133e50' in rows:rows['133e50']['context']='diagnostic headers'
        if batch in ('20','22') and '28fe70' in rows:rows['28fe70']['context']='diagnostic headers'
        if batch=='25' and '292ef0' in rows:rows['292ef0']['context']='native ra2'
        if batch=='24' and '292ef0' in rows:
            rows['292ef0']['forms']=['donor-context port, radar-event/virtual-call removal and register-allocation searches A/B/C/D']
            rows['292ef0']['form_ref']=[ref(i) for i,l in enumerate(lines) if 'Searches A/B/C/D' in l]
        if batch=='22' and 'ac360' in rows:
            rows['ac360']['forms']=['channel-guard permutations, saturation, endpoint/buffer forms, failure scopes and extent tests']
            rows['ac360']['form_ref']=[ref(i) for i,l in enumerate(lines) if 'Greedy channel-guard' in l or 'failure scopes and extent' in l]

def run(args):
    scope=json.loads(args.scope.read_text(encoding='utf-8'))
    tus={key:tu for tu,keys in scope['translation_units'].items() for key in keys}
    paths=[]
    for path in args.reports:
        paths.extend(sorted(path.rglob('*REPORT.md')) if path.is_dir() else [path])
    if not paths: raise ValueError('No reports found')
    batches=defaultdict(list)
    for p in dict.fromkeys(paths):
        b,lines=read_file(p);batches[b].append((False,p,lines))
    for p in args.notes:
        b,lines=read_file(p);batches[b].append((True,p,lines))
    series={}; names={}; all_rows=[]
    for b,files in sorted(batches.items(),key=lambda item:batch_sort(item[0])):
        ids=scope['batches'].get(b,[])
        rows={key:init(key) for key in ids}
        for note,p,lines in files:ingest(b,p,lines,rows,ids,note)
        if not rows: raise ValueError(f'Batch {b} has no target table or reviewed target scope')
        for key,r in rows.items():
            if r['name']:names[key]=max([names.get(key,''),r['name']],key=len)
            values=r['scores']; baseline=min((n for n,_ in r['inputs']),default=None)
            best=min((n for n,_ in values),default=None)
            delivered=r['outputs'][-1][0] if r['outputs'] else None
            context=r['context']; history=(key,context)
            count,record,streak=series.get(history,(0,None,0))
            count+=1
            threshold=record if record is not None else baseline
            if best is not None:
                if threshold is not None:streak=0 if best<threshold else streak+1
                record=best if record is None else min(best,record)
            series[history]=(count,record,streak)
            status=('diagnostic only' if 'diagnostic' in context else
                    'byte match' if best==0 else 'unmeasured' if best is None else
                    'needs new method' if streak>=args.retry_budget else 'open')
            ev=[where for n,where in values if n==best]
            all_rows.append([b,key,('0x'+key) if not key.startswith('#') else '',
                r['tu'] or tus.get(key,'unknown'),context,count,best,baseline,delivered,
                'none (bytes)' if best==0 else r['block'] or 'unclassified',
                ' | '.join(r['forms']) or 'not specified',streak,
                '' if best==0 else max(0,args.retry_budget-streak),status,
                ' | '.join(dict.fromkeys(ev)),' | '.join(dict.fromkeys(r['form_ref']))])
    with args.output.open('w',newline='',encoding='utf-8-sig') as out:
        writer=csv.writer(out);writer.writerow(FIELDS)
        for row in all_rows:
            row[1]=names.get(row[1],row[1]);writer.writerow(row)
    return len(all_rows)

if __name__=='__main__':
    par=argparse.ArgumentParser(description=__doc__,formatter_class=argparse.RawDescriptionHelpFormatter)
    par.add_argument('reports',type=Path,nargs='+')
    par.add_argument('--notes',type=Path,nargs='*',default=[])
    par.add_argument('--scope',type=Path,default=Path(__file__).with_name('ledger_scope.json'))
    par.add_argument('--retry-budget',type=int,default=3)
    par.add_argument('-o','--output',type=Path,required=True)
    args=par.parse_args()
    if args.retry_budget<1:par.error('retry budget must be positive')
    print(f'{run(args)} target rounds written to {args.output}')

