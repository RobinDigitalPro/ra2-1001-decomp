# src/ra2: level-2 readable source of GAME.EXE 1.001

This is byte-matching C++ for VC6 (CL 12.00.8168), compiled with `-O2 -Ob2 -Gr -GR -DNDEBUG -Gy`. The rules are in AGENTS.md (level-2 section) and the plan is in docs/LEVEL2_MATCHING_PLAN.md.

- The source file names follow the original `C:\RA2\*.cpp` names found in GAME.EXE.
- Class names come from RTTI. Other names (functions, globals, members) are provisional unless the binary proves them.
- A function counts as *matched* only when `tools/level2_check.py` reports equal bytes and every relocation is bound to verified evidence (`metadata/level2_symbols.json`). The list of claimed functions is in `metadata/level2_functions.json`.
- `#line` directives reproduce original `__FILE__`/`__LINE__` values where the binary contains them.
