# 0x1ded00 · Is_Owner_Tested_Control

## Diff 1 and the recovered winning edits

The supplied diff says `(identical)` and offers no donor body. Batch 24 preserves the input ownrdraw.cpp, its two replacements in `edits_ownrdraw_1ded00.json`, and the variant results in `od_control.results.jsonl`. Applying each replacement separately recovers the actual change.

| Recovered edit | Before → after | VC6 verdict |
|---|---|---|
| 1, function attribution | No attribution line → a source-credit comment above the function. | Cosmetic. The baseline and this edit each produce a 2,480-byte padded section with 1,108 positional differences. |
| 2, the two control kinds | `if (kind == 0x122 \|\| kind == 0x112)` with one `return id == 1 \|\| id == 2` → two successive equality tests, each with its own copy of the same return. | **DECISIVE**. This edit alone gives zero differences over 2,384 padded bytes. The first baseline difference is at +0x3e8. |

Both recognized control kinds still accept IDs 1 and 2. What changes is where the ID test is written relative to the kind dispatch. The old source wrote the two aliases into one branch. The new source duplicates the predicate under each comparison. Batch 24 verified 2,377 code bytes, 7 padding bytes and 5/5 relocations.

## Why we did not find it

**Yes, in batch 24.** The ledger identifies `od_control.json` as the successful search. Among 11 distinct candidates, the grouped baseline scored 18 disassembly hunks. A shared-label spelling still scored 17 and kept the 2,480-byte section. Two independent return sites matched with every other option at its default. The case export starts after this correction, which accounts for its empty diff.

## How they found it

The winning edit credits meastes/redalert2-decomp at 613e28e4e0, `src/recovered/unidentified/uncalled_copies/OwnerDraw_Control_Test_005e6860.cpp`. The recovered RA2 edit and trial are direct evidence of the form used. The donor text and an account of its author's discovery are absent from the supplied case, and the Gibbo round notes provide no method for this control test.
