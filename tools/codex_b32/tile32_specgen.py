from pathlib import Path
import json
import argparse
parser=argparse.ArgumentParser(description='Regenerate the Draw_Tile varsearch specs')
parser.add_argument('output',type=Path)
out=parser.parse_args().output
a="void IsometricTileTypeClass::Draw_Tile("
def choice(name, edits):
    return dict(name=name,options=[dict(label="input",edits=[]),dict(label=name,edits=[[*e,a] for e in edits])])
choices=[
choice("advance-with-for", [("do { // RA2: through the set\n\t\t\t\t\tnext = next->NextTileTypeInSet; // RA2: to the variant\n\t\t\t\t} while (--variation != 0); // RA2: cell_variation steps","for (; variation != 0; --variation) {\n\t\t\t\t\tnext = next->NextTileTypeInSet;\n\t\t\t\t}")]),
choice("own-cell-variation",[("int variation = cell_variation; // level-2 1.001: the reduced variation is its own local (mov edx,eax at 0x52a4cd)","int & variation = cell_variation;")]),
choice("guard-variation-modulus",[("if (cell_variation > num - 1) {\n\t\t\t\tvariation = cell_variation % num;\n\t\t\t}","variation = cell_variation > num - 1 ? cell_variation % num : cell_variation;")]),
choice("scan-by-subscript",[("const unsigned char * pixel = &_tilemask[cell_offset + first_col + 1];","const unsigned char * maskrow = &_tilemask[cell_offset];"),("++scan, ++pixel","++scan"),("if (*pixel == 32)","if (maskrow[scan] == 32)")]),
choice("incrementing-rowcount",[("for (int rowcount = ISO_DRAW_WIDTH; rowcount != 0; --rowcount)","for (int rowcount = 0; rowcount < ISO_DRAW_WIDTH; ++rowcount)")]),
choice("edge-row-invariant",[("for (int i = 0; i < ISO_DRAW_WIDTH; ++i) {\n\t\t\t\t\t\t\tint run = span_count - max(0, i - first_col) - max(0, left_clip);","int row_span = span_count - max(0, left_clip);\n\t\t\t\t\t\tfor (int i = 0; i < ISO_DRAW_WIDTH; ++i) {\n\t\t\t\t\t\t\tint run = row_span - max(0, i - first_col);")]),
choice("count-span-by-endpoint",[("span_count = 1;",""),("for (int scan = first_col + 1; scan < ISO_DRAW_WIDTH; ++scan","int scan;\n\t\t\t\t\t\tfor (scan = first_col + 1; scan < ISO_DRAW_WIDTH; ++scan"),("++span_count;\n\t\t\t\t\t\t}","}\n\t\t\t\t\t\tspan_count = scan - first_col;")]),
choice("offset-row-pointer",[("int startcol = first_col;","unsigned char * starts = &_iso_start_cols[cell_offset];\n\t\t\t\t\tint startcol = first_col;"),("_iso_start_cols[cell_offset + col] =","starts[col] =")])
]
for n,tag in [(4,"a"),(8,"b")]:
    spec=dict(base="../input/isotype.cpp",preset="m85",targets=[["Draw_Tile@IsometricTileTypeClass","0x12a490"]],controls=[["?Shadow_Caster_List@IsometricTileTypeClass@@QBEPBVCell@@XZ","0x129b10"],["?Get_Tile_Image@IsometricTileTypeClass@@QAE_NHPAPAEHH@Z","0x12bfd0"],["Ramp_Type@IsometricTileTypeClass","0x129950"],["Is_Randomized@IsometricTileTypeClass","0x129990"]],choices=choices[:n])
    (out/("tile32_"+tag+".json")).write_text(json.dumps(spec,indent=2)+"\n")
    if tag == 'b':
        (out/'tile32_bytes.json').write_text(json.dumps(spec,indent=2)+'\n')

