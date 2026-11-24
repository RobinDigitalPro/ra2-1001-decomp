from pathlib import Path
import argparse
import json

parser = argparse.ArgumentParser(description='Recreate the two queue.cpp search specs.')
parser.add_argument('--out-dir', type=Path, default=Path.cwd())
root = parser.parse_args().out_dir
root.mkdir(parents=True, exist_ok=True)
hdr = 'static void Print_CRCs(EventClass *ev)\n{'
controls = [['?Add_CRC@@YIXPAII@Z','0x221b70'], ['?Fill_Sync_State@@YIXH@Z','0x224770'], ['Clean_DoList','0x2216b0'], ['Queue_Record','0x221700']]
def one(name, old, new):
    return {'name':name, 'options':[{'label':'input','edits':[]},{'label':'alternative','edits':[[old,new,hdr]]}]}
choices = [one('separate_indices','int i,j;', 'int i;\n\tint j;'),
           one('filename_before_file','FILE *fp;', 'char filename[512];\n\tFILE *fp;'),
           one('builder_number_order','char builder[128];\n\tchar number[128];','char number[128];\n\tchar builder[128];')]
choices[1]['options'][1]['edits'].insert(0,['char filename[512];\n\tsprintf(filename,','sprintf(filename,',hdr])
for count in [3,5]:
    if count==5:
        choices += [one('mmx_first','int cpu_type = PROC_PENTIUM_PRO;\n\tbool mmx = false;', 'bool mmx = false;\n\tint cpu_type = PROC_PENTIUM_PRO;'),
                    one('platform_data_first','NetNumType net;\n\t\t\tNetNodeType node;', 'NetNodeType node;\n\t\t\tNetNumType net;')]
    (root / ('queue32_%d.json'%count)).write_text(json.dumps(dict(base='queue.cpp', targets=[['Print_CRCs','0x221b90']], controls=controls, choices=choices),indent=2)+'\n')

