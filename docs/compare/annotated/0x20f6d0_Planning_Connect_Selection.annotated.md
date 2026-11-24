# 0x20f6d0 · Planning_Connect_Selection

## Diff 1, hunk by hunk

| Hunk (old → matched lines) | Before → after, and what the donor supplied | VC6 verdict |
|---|---|---|
| H1 (8–16 → 8–12) | A conditional assignment to `bool techno` from `object->AbstractFlags & 1` and a second null test become `Planning_Is_Techno(object)`. The meastes 1.006 planmgr.cpp calls the member `object->Is_Techno()`. The port makes the null-safe test visible inline in this translation unit. | Byte-neutral. Applied alone, 42 differences. Reverted from the winner, zero. |
| H2 (20–24 → 16–20) | `last->PlanningMembers.Count()` becomes the donor accessor `last->Get_Count()`. This still obtains the member count once, before iterating owners. | Byte-neutral in both directions, with the same 42/0 results as H1. |
| H3 (42–46 → 38–43) | The direct `Planning_Help(4)` becomes `void (__fastcall *help)(int) = Planning_Help` followed by `help(4)`. The donor itself uses the old direct spelling. The typed local at this final call is an RA2 adaptation. | **DECISIVE**, isolated in both directions. H3 alone matches. Reverting H3 alone restores all 42 differences. |

VC6 8168 with the level-2 release flags produced an 800-byte padded old section and 768-byte matched section. The first difference was at +0x2da. The private comparison masked relocation operands. Batch 24 independently recorded 756 code bytes, 12 padding bytes and 24/24 verified relocations. The pointer declaration establishes the source-level call form. An indirect machine instruction is not required for that source change to affect optimization.

## Why we did not find it

**Yes, in batch 24.** The ledger records a byte match. The initial `plan_connect` and extended searches reached ten disassembly hunks. The tail grid recorded 288 combinations, 216 compiling with controls passing. Its retained `plan_connect_tail.results.jsonl` places the typed call at choice 3 with all other choices at zero and zero differences. The reference provided a credible function structure, but following its predicate and getter alone leaves the entire 42-byte residual.

## How they found it

The named reference is meastes1006_planmgr.cpp. Its direct help call is visible in diff 2. The matched TU also attributes its locally inlined techno predicate to gibbo101's abstract.h. I found no Gibbo round note tracing this final RA2 call-site change. The isolated result and the recorded search belong to the RA2 batch.
