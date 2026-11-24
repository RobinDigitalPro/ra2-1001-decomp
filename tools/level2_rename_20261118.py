"""One-off: apply the name corrections proven by the m85 layout review (W/analysis/level2/agents/m85_layout_report.json)
to our own src/ra2 sources. Backups go to W/analysis/level2/header_backups/rename_20261118."""
import glob, json, os, re, shutil
os.chdir(r'D:\<project-folder>\Coding\RedAlert2\src\ra2')
bk = r'D:\<work-root>\RedAlert2Temp\analysis\level2\header_backups\rename_20261118'
os.makedirs(bk, exist_ok=True)
files = [f for pat in ('*.cpp', '*.CPP', '*.H', 'unnamed/*.cpp', 'templates/*.cpp') for f in glob.glob(pat)]


def backup(f):
    dst = os.path.join(bk, re.sub(r'[\\/]', '__', f))
    if not os.path.exists(dst):
        shutil.copy(f, dst)


def sub_all(pairs, only=None):
    changed = []
    for f in files:
        if only and os.path.basename(f) not in only:
            continue
        s = open(f, encoding='latin1').read(); t = s
        for a, b in pairs:
            t = re.sub(r'\b' + re.escape(a) + r'\b', b, t)
        if t != s:
            backup(f); open(f, 'w', encoding='latin1', newline='').write(t); changed.append(f)
    return changed


log = {}
log['surfaces'] = sub_all([('HiddenSurface', 'ZZVIS'), ('PrimarySurface', 'ZZHID'), ('CompositeSurface', 'ZZALT'), ('TempSurface', 'ZZLOG')])
log['surfaces2'] = sub_all([('ZZVIS', 'VisibleSurface'), ('ZZHID', 'HiddenSurface'), ('ZZALT', 'AlternateSurface'), ('ZZLOG', 'LogicalSurface')])
log['callback'] = sub_all([('Call_Back', 'Windows_Message_Handler')])
log['callback2'] = sub_all([('Func_4821E0', 'Call_Back')])
log['mainloop'] = sub_all([('Main_Loop', 'Func_53D940')], {'Conquer.CPP'})
log['mainloop2'] = sub_all([('Func_53DC10', 'Main_Loop')], {'Conquer.CPP'})
log['wcs'] = sub_all([('wcschr', 'wcsrchr')], {'Beacon.CPP'})
log['vet'] = sub_all([('Set_Veteran', 'Set_Elite')], {'Multiplayer.cpp'})
log['power'] = sub_all([('Power_Off', 'Turn_Off')], {'Event.CPP'})
log['crc'] = []
for f in files:
    s = open(f, encoding='latin1').read()
    if 'crc((char)' in s:
        backup(f); open(f, 'w', encoding='latin1', newline='').write(s.replace('crc((char)', 'crc((bool)')); log['crc'].append(f)
s = open('CRC.H', encoding='latin1').read()
if 'operator() (bool datum)' not in s:
    backup('CRC.H')
    s = s.replace('    void operator() (char datum);',
                  '    void operator() (char datum);                // 0x493bd0\n    void operator() (bool datum);                // 0x493c60 (normalises with setne)')
    open('CRC.H', 'w', encoding='latin1', newline='').write(s)
json.dump(log, open(os.path.join(bk, 'log.json'), 'w'), indent=0)
print({k: len(v) for k, v in log.items()})
