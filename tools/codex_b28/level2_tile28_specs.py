"""Build the two incremental searches from the present batch input."""
import json
from pathlib import Path
import os
import argparse

p=argparse.ArgumentParser(description=__doc__)
p.add_argument("input",type=Path,help="path to original batch isotype.cpp")
p.add_argument("--out",type=Path,required=True)
args=p.parse_args()
args.out.mkdir(parents=True,exist_ok=True)
base=os.path.relpath(args.input.resolve(),args.out.resolve()).replace(os.sep,"/")
source=args.input.read_text(encoding='latin1')
def choice(name, old, new):
    if source.count(old)!=1:
        raise ValueError((name, source.count(old)))
    return dict(name=name,options=[dict(label='base',edits=[]),dict(label=name,edits=[[old,new]])])
choices=[
choice('extra-x-then-y','int ex = record->ExtraX - record->X + x;\n\t\t\t\t\t\tint ey = record->ExtraY - record->Y + y;', 'int ey = record->ExtraY - record->Y + y;\n\t\t\t\t\t\tint ex = record->ExtraX - record->X + x;'),
choice('clip-right-uses-bound','int overhang = spanw - cliprect.Width - cliprect.X + work_x;', 'int overhang = work_x + spanw - clip_right;'),
choice('left-uses-measured-displacement','spanw = x - cliprect.X + IsoDrawData.SpanWidth;\n\t\t\t\t\tIsoDrawData.ClipLeft = cliprect.X - x;', 'int clipped = cliprect.X - x;\n\t\t\t\t\tspanw = IsoDrawData.SpanWidth - clipped;\n\t\t\t\t\tIsoDrawData.ClipLeft = clipped;'),
choice('top-uses-measured-displacement','spanh = y - cliprect.Y + IsoDrawData.SpanHeight;\n\t\t\t\t\tIsoDrawData.ClipTop = cliprect.Y - y;', 'int clipped = cliprect.Y - y;\n\t\t\t\t\tspanh = IsoDrawData.SpanHeight - clipped;\n\t\t\t\t\tIsoDrawData.ClipTop = clipped;')]
def save(name):
    out=args.out/(name+'.json')
    spec={'base':base,'targets':[['Draw_Tile@IsometricTileTypeClass','0x12a490']],'controls':[['Shadow_Caster_List@IsometricTileTypeClass','0x129b10'],['Get_Tile_Image@IsometricTileTypeClass','0x12bfd0'],['Ramp_Type@IsometricTileTypeClass','0x129950'],['Is_Randomized@IsometricTileTypeClass','0x129990']],'choices':choices}
    out.write_text(json.dumps(spec,indent=2))
save('tile28_clipping')
choices.extend([
choice('extra-right-reuse','IsoDrawData.SpanWidth = cliprect.Width - ex + cliprect.X;', 'IsoDrawData.SpanWidth = clip_right - ex;'),
choice('extra-bottom-reuse','IsoDrawData.SpanHeight = cliprect.Height - ey + cliprect.Y;', 'IsoDrawData.SpanHeight = clip_bottom - ey;'),
choice('clip-bottom-reuse','IsoDrawData.SpanHeight = cliprect.Height - work_y + cliprect.Y;', 'IsoDrawData.SpanHeight = clip_bottom - work_y;'),
choice('diamond-offset-first','int col = 0;\n\t\t\t\t\tunsigned short * shortp = &_iso_row_offsets[cell_offset];\n\t\t\t\t\tint base = *lut;\n\t\t\t\t\tint startcol = first_col;',
'int startcol = first_col;\n\t\t\t\t\tint base = *lut;\n\t\t\t\t\tunsigned short * shortp = &_iso_row_offsets[cell_offset];\n\t\t\t\t\tint col = 0;')])
save('tile28_webs')


save('tile28_bytes')
