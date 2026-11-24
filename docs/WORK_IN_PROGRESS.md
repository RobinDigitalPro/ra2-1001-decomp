# Work in progress

This repository holds ALL our source, finished and unfinished. How to tell them apart:

| Status | Meaning | Where it is listed |
|---|---|---|
| **matched** | byte-identical with the original after relocation masking, with every relocation bound to the right target | `metadata/level2_functions.json` (17,779 functions) |
| **near-equal** | not byte-identical yet, but every remaining difference is code generation only (register choice, instruction order, encoding, stack slot); functionally equivalent | `metadata/level2_near_equal.json` |
| **work in progress** | every other function body in `src/m85` and `src/ra2`: written, compiling, but not yet byte-identical (a near miss), or still being written | not listed as a claim; see below |
| **level 1** | `src/recovered`: an earlier, separate behavioural recovery (bounded paths tested against the original over 512 cases each, written as explicit memory operations). Not part of the readable byte-matching source. | `src/recovered`, with its test runtime in `src/platform` |

- A function in `src/m85` or `src/ra2` that does **not** appear in `metadata/level2_functions.json` is work in progress. It may differ from the original in code shape and, in some cases, in behaviour. Do not treat it as verified.
- Known open items:
  - near misses waiting for the complete-file link stage: `docs/DEFERRED_TO_END.md`;
  - quality items in matched code (kind-1 "steering" forms): `docs/REMATCH.md`.
- The exact per-function inventory of all unmatched code is in `docs/INVENTORY.md` and `docs/inventory.csv`: 65 near misses (162 KB), 10 near-equal (23 KB), 7 tiny entries without source (13 bytes) and 1,048 library or thunk entries (90 KB).
