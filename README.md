# Red Alert 2 1.001: a readable, byte-matching C++ reconstruction

This project reconstructs the source code of **Command & Conquer: Red Alert 2, GAME.EXE 1.001** as readable C++ (plus the original's hand-written assembly modules). The source compiles back to the same machine code with Microsoft Visual C++ 6.0 (code generator `c2.dll` 12.00.8168, `/O2 /Ob2 /Gr /GR /DNDEBUG /Gy`).

**No game data and no executable are included.** You need your own legally owned copy of Red Alert 2 for any comparison or later build.

## Baseline: an old 1.001 repack

Our target binary is the GAME.EXE of an **old repack of Red Alert 2 1.001**, not a clean retail install. That repack contains no-CD patches. We reconstruct the whole executable as it is, so those patches are reconstructed as well, clearly labelled as repack deltas (for example the disk checks `Get_Disk_ID`/`Force_Available` and `VolumeCheck`). The rest of the code is the 1.001 game code. A retail 1.001 GAME.EXE differs from ours only in those patched places.

## Status (2026-11-25)

| Measure | Value |
|---|---|
| Byte-identical functions (claims) | 17,791 |
| Share of `.text` reproduced (including identified library code) | 95.46 % |
| Share of `.text` from our own source | 93.00 % |
| Functionally equivalent near misses (codegen-only residue, `metadata/level2_near_equal.json`) | 53 (129,976 bytes) |
| Matched with a documented repack patch (`metadata/level2_repack_patches.json`) | 2 |
| Identical empty bodies placed by source order (`metadata/level2_order_placed.json`) | 4 |
| Share of `.text` including the near-equal functions | 99.15 % |
| Strict whole-executable link check | every claimed function placed at its original address |

- A function counts as **matched** only when every byte outside relocations equals the original and every relocation is bound to the right target.
- **NEAR_EQUAL** functions differ only in register choice, instruction order or encoding. They are listed separately and do not count as matched.

## All source, finished and unfinished

The repository contains all our source, including functions that are **not byte-identical yet**. Only the functions listed in `metadata/level2_functions.json` are verified matches; everything else is work in progress. See `docs/WORK_IN_PROGRESS.md`.

## Layout

- `src/m85/`: the main C++ tree. It is adapted from mischa85/RedAlert2 (RA2 1.006) and reworked function by function to 1.001; their README and licence are kept there.
- `src/ra2/`: our own translation units for code not covered by that tree. `src/ra2/unnamed/TU_<address>.cpp` holds units whose original file name is unknown.
- `src/m85/src/asm/`: the original assembly modules, reassembled byte-identically with UASM.
- `src/recovered/` and `src/platform/`: an earlier, separate level-1 behavioural recovery (bounded, tested paths) and its test runtime. Not part of the readable byte-matching source.
- `metadata/level2_functions.json`: every claim (RVA, mangled symbol, translation unit).
- `metadata/level2_symbols.json`: the bound symbol map (symbol to original address, with evidence).
- `tools/`: our level-2 matching and checking tools (see `tools/README.md`).
- `docs/`:
  - `GUIDE.md`: the matching guide with the VC6 rules we use;
  - `compare/`: annotated comparisons of our code against community solutions;
  - `lessons/`: method studies;
  - `LINKCHECK_*.md`: the whole-executable link check;
  - `REMATCH.md` and `DEFERRED_TO_END.md`: open quality and end-phase items;
  - `SOURCES_CREDITS.md`: every source used.

## Licence

GPL-3.0-or-later (see `LICENSE.md`), including the additional terms Electronic Arts attached to its released Command & Conquer source code. Parts adopted from other projects keep their licence headers and are credited in `docs/SOURCES_CREDITS.md`.

## Credits

This work stands on the shoulders of the community. Thank you to:

- **mischa85/RedAlert2** (RA2 1.006), the base of `src/m85`;
- **gibbo101/ra2-decomp** (Yuri's Revenge 1.001), many function bodies and techniques;
- **meastes/redalert2-decomp** (RA2 1.006), function forms and VC6 matching notes;
- **OpenTS-Developers/TibSun**, **Vinifera-Developers/TSpp**, **r-melvin/gagarin**;
- **Electronic Arts**, for releasing the C&C, Red Alert and Renegade sources.

Reference-only projects (logic, never code): OpenRA, VERA20K and omarelarab/ra2-engine. Details are in `docs/SOURCES_CREDITS.md`.

## Not yet included

- Build files for a complete executable.

Red Alert 2 is a trademark of Electronic Arts. This is an unofficial, non-commercial preservation and research project.
