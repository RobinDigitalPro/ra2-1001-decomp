# 0x300c60 · UnVQ1_4x2_Table

## Diff 1, hunk 1 of 1 — **DECISIVE**

**Before** · nested tests on `type` and a second switch implemented the command decoder. The short and extended runs reached shared labels by `goto label_scatter_copy` or `goto label_extended_count`. **After** · a single `switch (command)` dispatches on the high three bits. A command-local `count = 0` distinguishes the entry paths: case 0x2000 sets the short count and low-byte index, then falls through to 0xA000. Direct entry to 0xA000 reads one count byte and takes its index from the original low 13 bits. Both then scatter the same pair of packed values. The failed body already shared this operation and already used the winning shift/mask count arithmetic. The difference is how the control flow and lifetimes express that sharing.

The other arms explain why swapping dispatch keywords alone would be an incomplete experiment:

| Command | What the port expresses |
|---|---|
| 0x0000 | Skips the low-byte block count times eight destination bytes. |
| 0x4000 | Reads the first codebook index from the command byte and subsequent indices from a byte cursor. Separate packed-copy loops advance by four or eight times the local stride. The old repeated-copy loop counted down. |
| 0x6000 | Builds two 32-bit values per row from pairs of 16-bit loads through a const byte cursor. The old form kept four word temporaries and indexed a word pointer. |
| 0x8000 | Tests the transparent high bit while walking typed 16-bit pixels with ascending row/column indices; the former loops decremented remaining counts. |
| 0xC000 | Reads the extended count, caches the 16-bit pixel and repeats each visible pixel across blocks. The typed pointers and per-case locals constrain their scope. |

The enclosing loop names the doubled width, a four-row stride, current destination, row base and row end. On reaching the end it advances the row base, assigns the destination from it and recalculates the end. Function parameter spelling changes are cosmetic, and the removed assertions are disabled under the level-2 `NDEBUG` build. Diff 2 agrees with the supplied `gibbo232414_unvqtblc.cpp` body.

**Rebuild.** The failed TU emitted 912 bytes with 854 differences. The single-hunk replacement emitted an exact 928-byte section with no relocations. Batch 44g's `unvqtblc_search2.json` tested changing the short-count expression alone on the winner to the algebraically equivalent shift-by-eight, mask-five-bits, double-and-add form. It scored 37; four other probes still matched. That test establishes sensitivity to the count expression *within* the winning context. The switch fallthrough and per-arm rewrites were tested together in the native hunk; their independent contributions are unmeasured.

## Why we did not find it

**Partly.** There is no row for this target in the supplied attempt ledger. `DEFERRED_TO_END.md` records the g2 body at about 32 masked instruction hunks and a prior Gibbo form at 77.1%. A6 explicitly deferred further work pending symgauge. The source shows that shared scatter and the packed-count expression were already known. The nested dispatch and countdown-copy baseline nevertheless remained in place; the record has no native pre-port trial of the later complete switch with its per-arm lifetimes.

## How they found it

Gibbo's attempts 4076 and 4098 progressed through 91.8% and 92.5%. Their 23 November round notes record that a plain switch reproduced the target's compare-tree dispatch, then describe tracking register exchanges involving count and codebook; an address-taken dummy was rejected. The archived source at `232414dc36` supplies the final fallthrough and copy loops. Those upstream percentages describe their build, independently of the native byte comparison above.
