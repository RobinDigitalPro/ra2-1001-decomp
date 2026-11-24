# Tools

Our level-2 matching and checking tools (Python 3, standard library; `capstone` for some analysis scripts).

## Setup

- `RA2_PROJECT`: the folder with this repository (`src/`, `metadata/`, `docs/`) and `RA2Original/GAME.EXE`, your own copy of the 1.001 repack executable (see the main README). The default is the current folder.
- `RA2_WORK`: a work folder for build products and caches. The default is `work`. Build products contain bytes of the original exe: keep them out of version control.
- Your own Visual C++ 6.0 with code generator `c2.dll` 12.00.8168, at `RA2_WORK/tools/portable/vc6` (VC98/BIN, VC98/INCLUDE, VC98/LIB). Not included; never redistribute it.
- UASM 2.57 for the assembly modules, at `RA2_WORK/tools/portable/uasm-2.57r/uasm64.exe`.

## Main entry points

- `level2_check.py`: compiles the translation units that hold claims and verifies every claim byte for byte, with relocation masking and symbol binding. Writes a report under `RA2_WORK/analysis/level2/reports/`.
- `level2_coverage.py` and `level2_overlaps.py`: coverage share and overlap check.
- `level2_varsearch.py`: the greedy variant search over explicit [old, new] choice points.
- `level2_integrate_agent.py`: applies a set of edits to one TU behind a final gate (all claims of the TU must keep matching).
- `level2_apply_patch.py`: header and TU patches with backups and `revert`.
- `level2_forcing_audit.py`, `level2_label_audit.py`, `level2_gap_domains.py`, `level2_compare_versions.py`: quality and planning audits.
- `codex_t1/`: the extra techniques of `docs/GUIDE.md` L1-L7 (`level2_ablate.py`, `level2_callee_first.py`, `level2_evidence.py`, `level2_generators.py`, and an opt-in generator version of `level2_varsearch.py`).
- `codex_b28/`, `codex_b32/`: compiler-model studies (the /Ob2 inline model, register-web weights, C2.DLL rules).

Several tools started as private working scripts. Paths inside their docstrings are placeholders (`<RA2_PROJECT>`, `<RA2_WORK>`).
