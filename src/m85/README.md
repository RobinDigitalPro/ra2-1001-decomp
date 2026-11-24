# Adopted upstream tree: mischa85/RedAlert2 (RA2 1.006 matching decompilation)

- Origin: https://github.com/mischa85/RedAlert2, commit 0132d217210700383427f6953722ca6cd133f8a1, downloaded on 2026-11-18. Per-file SHA-256 values are in W/analysis/references_gpl_20261118/provenance.json.
- License: GPL-3.0-or-later. Parts are derived from EA's Red Alert source, with EA's additional GPL section 7 terms (see LICENSE.md). The file headers are kept.
- Adopted with the user's decision of 2026-11-18 ("Ook code overnemen").
- Use in this project: our VC6 RTM (8168) compiles these files with -O2 -Ob2 -Gr -GR -DNDEBUG -Gy -DWIN32. A function counts as level-2 for OUR GAME.EXE 1.001 only when level2_check.py proves it byte-identical with verified bindings (claims tu = src/m85/src/<file>).
- Changes for 1.001 are made in place and recorded per file.

## Changes for 1.001 (level 2)
- __FILE__ string literals: "D:\Ra2\\" becomes "C:\RA2\\" in all src files, because the 1.001 binary holds C:\RA2\<File> (verified by content). The list is in W/analysis/level2/m85_path_changed.json.
- Per-module geometry constants: `#include "geoconst1.h"` / `"geoconst2.h"` were added to 53 modules whose functions reference their own copy in 1.001 (W/analysis/level2/m85_geoconst_changed.json; beacon.cpp reverted because it did not compile).
