# 0x2ad120 · TeamClass::AI

## Diff 1 has no caller hunk · recovered helper edit — **DECISIVE**

The packet reports identical `TeamClass::AI` bodies and no donor body. The paired `before/0x2ad120__team.cpp` and `after/0x2ad120__team.cpp` from `history_before_after.zip` expose the operative change in `TeamClass::TMission_GOTO_SHROUD`. The matched TU credits gibbo101 `src/team.cpp` at `721d81e44f` for that form.

**Before** · `FootClass *unit = (FootClass *)Zone;`, followed by a null fallback to `Member` and one expression `Assign_Mission_Target(Map.Find_Nearby_Shroud(unit))`. **After** · `if (Zone != NULL)` chooses two complete search-and-assign expressions. The true branch passes the cast Zone; the other passes `Member` directly. The first-time guard still encloses the choice; `Coordinate_Move()` remains below the guard. VC6 can merge the two branch tails after inlining without carrying the explicitly selected pointer to a common source-level call. The source's two calls do not imply two search calls execute per visit. The added attribution is cosmetic.

**Isolated rebuild.** Using VC6 8168, the archived failed TU produced 1,703 relocation-masked differences in the 3,472-byte AI section. Replacing just this helper body, while leaving the caller unchanged, gave zero in the same section. The old standalone helper already matched, so checking that symbol in isolation would miss the change that mattered to AI.

## Why we did not find it

**Partly, in the wrong place.** Batch 16's `team16_dispatch.json` contains a shroud-selection variant duplicating both operations, but it expands a dispatch macro in the AI caller and takes the fallback from `Get_Member()`. Other candidates merge the target first. `team16_depth` varied helper boundaries and the batch recorded a 32-hash candidate search; the ledger retained a 1,703-byte residual. An initial decorated-symbol probe also needed correction. None of those records identifies the branch-duplicated edit *inside the existing helper* with direct `Member`. The queue subsequently parked a no-gain pass. The separate standalone match gave the search no signal to revisit this helper's spelling.

## How they found it

Gibbo's `data__attempts.csv` entry 4051 reports taking YR Team AI from 89.7% to 100%. They tracked one scratch-register rotation in the inlined shroud mission; writing both operations inside the branches let the compiler tail-merge the calls. The archived native TU explicitly credits their two-call solution and identifies the same scratch cost. The isolated native rebuild confirms the source dependency without assuming the percentage or byte metrics transfer between versions.
