# 0x29d4c0 · Tactical::Draw_Pixel_Effects

## Diff 1, hunk 1 of 1 — **DECISIVE**

**Before** · three early rejection returns, a byte-pointer lock, then a null return. The inner loop derived late scalar `x` and `y` values, tested four bounds explicitly and addressed the pixel by byte pitch plus twice x. **After** · one positive detail/frame-rate/format guard encloses the lock; a non-null block contains the work and unlock. A zero-initialized `Point2DStruct pixel = {0, 0};` precedes the guards, pitch fetch and loops. The loop writes the center into its fields, then adds the effect offsets in a second stage. `cliprect.Is_Point_Within(Point2D(pixel))` consumes that aggregate. The 16-bit buffer is advanced by the byte row pitch and indexed by pixel x. This gives VC6 a live aggregate and an explicit conversion at the bounds test.

The hunk also constructs the base cell directly from the converted lepton, changes the inner cell advance from a temporary `Cell(1,-1)` addition to individual component updates, and nests the effect alternatives. Renaming the timer/effect locals and adding attribution are cosmetic. The inherited address comment is stale; RVA 0x29d4c0 corresponds to VA 0x69d4c0. Batch 44g checked the Render caller and both TacticalRect arguments to associate the YR `Draw_Sparkles` body with this native function.

**Evidence.** Applying the sole hunk turned 166 relocation-masked differences into zero at 960 emitted bytes in both builds. Batch 44g's `tactical44_a.json` and `tactical44_b.json` distinguish the constituent edits. Substituting a default-constructed class `Point2D` for the aggregate scored 14 on the winner. The tested buffer typing, origin cell temporary, clip-helper conversion and cell-component step alternatives independently scored zero. This isolates sensitivity to the aggregate's representation/initialization. The hunk test does not isolate the contribution of the outer guard, nested effect branches or center/offset assignment schedule.

## Why we did not find it

**Partly.** Batch 16's `pixel16_c` trials include separated center/offset expressions, temporary render objects or references, and byte/row store forms. Batch 17's width trials changed operand selection. The ledger records remaining differences through later work; batch 23 still reported 17 differing instruction hunks. The variants already covered several symptoms, but they retained the old surrounding draw body or treated x/y as scalars. There is no pre-port evidence of the early plain aggregate combined with the staged field writes and port's scope. Grouping this routine with neighboring rendering work in batch 30 did not produce that body.

## How they found it

The packet compares the result with `meastes1006_tactical.cpp`. The credit in the matched hunk and batch 44g instead identify `gibbo232414_tactical.cpp`, function `Draw_Sparkles`, commit `232414dc36`, as the direct donor. Gibbo's attempts 4043 and 4165 and the 23 November round notes track an in-place multiply versus a pitch load in the reference and describe initializing the plain X/Y aggregate before the pitch. That instruction-schedule clue led upstream to the representation that the native perturbation also distinguishes.
