# 0x7a900 · CellClass::Place_Veins

## Diff 1, hunk 1 · Keep the induction variable an int (old 13, new 13)

**DECISIVE together with hunk 2.** Before, `FacingType dir` was converted back to the enum at each increment and passed directly to `Adjacent_Cell(dir)`. Gibbo's loop increments an `int` by `FACING_90` and converts at the consumer, `Adjacent_Cell(FacingType(dir))`. The direction sequence is the same. It changes where the enum conversion enters the compiler's representation. The removed neighbor-skip comment is cosmetic. Alone, H1 retained the starting 1,335 differences. Removing it from the complete match produced 1,697 differences and enlarged the section to 2,208 bytes.

## Hunk 2 · Select the random conversion and materialize the first origin (old 28, new 24)

**DECISIVE together with hunk 1.** In the flat-neighbor branch, `abs(Scen->RandomNumber() % 3)` became `abs(Scen->RandomNumber % 3)`. The object now uses its integer conversion in the modulo expression. The explicit call operator remains in the center-cell and ramp paths. The order of modulo and absolute value in this branch is unchanged. The other change takes a point value before the final rectangle union: the old inline subtraction of `TacticalRect.Top_Left()` became a named `Point2D origin = TacticalRect.TopLeft` followed by subtraction of `origin`. The updated comment on `_Vein_Frame_B(&adjacent)` is cosmetic.

B44g's `cell44_port_b.results.jsonl` separates those two source choices in the landed context. Restoring the explicit random call scored 66 mismatching hunks. Inlining the direct origin member scored 3, using a const-reference origin scored 42, and moving construction into the expression scored 17. Initializing the **named value** with the getter scored zero as well. The timing and value category of that first snapshot matter. Either accessor spelling works in the named-value form.

## Hunk 3 · Ramp rectangle origin (old 43, new 40)

**Cosmetic in the matched context, independently compiled.** The ramp dirty rectangle subtracts `TacticalRect.TopLeft` where our original used `TacticalRect.Top_Left()`. This site takes the direct member without introducing a local. Reverting H3 alone retained 0/2,192.

## Hunk 4 · Final rectangle origin (old 55, new 52)

**Cosmetic in the matched context, independently compiled.** The outer dirty rectangle makes the same getter-to-member change after the neighbor loop. Reverting H4 alone retained 0/2,192. Applying only H1+H2 to the archived before TU was also exact, so the two later access changes can both be omitted.

**Compile controls and donor boundary.** Fresh VC6 8168 level-2 results, in differing unmasked bytes / compiled section bytes: baseline 1,335/2,192; H1 alone 1,335/2,192; H2 alone 1,697/2,208; H3 or H4 alone 1,335/2,192; H1+H2 and full after 0/2,192. The matcher reports open bindings. In diff 2 the sole functional donor-to-landed difference is `adjacent.Get_Vein_Frame()` in gibbo's body versus our already-present wrapper. B44g's literal-donor test got 40 of 42 expected calls. Retaining an out-of-line frame call via the wrapper gave an exact body. Diff 3 thus includes a tempting frame-call edit which diff 1 correctly leaves alone.

## Why we did not find it

**Partly tried.** The ledger records B14 gates, B19 loop/random variants, B21 dirty-area and frame variants and B23 further register/stack probes, all ending at 1,335 differences. B19 examined 151 distinct hashes. Its “named random frame” retained `RandomNumber()`, and its integer loop introduced a separately named `FacingType` value in the body. Neither is the community pair of implicit conversion at the flat call site and a cast only at the adjacency call. B21 and B23 worked on the first rectangle's scratch register and temporary lifetime, generally treating the RNG as fixed. The fresh single-hunk results explain why ranking edits independently concealed the solution: H1 gives no gain on the old baseline, and H2 in isolation scores worse.

## How they found it

Gibbo's 23 November “Place_Veins” round says they started with the TibSun body and neighbor step, then recognized the `Random2Class` integer-conversion idiom in TibSun aircraft, unit and vanim code. They credit that spelling with the executable's register allocation. The round notes do not recount a separate discovery path for the named origin. The submitted donor body is `gibbo232414_cell.cpp`. Other evidence: B14/B19/B21/B23 reports, B19 `cell11_search_b.json`, B44g cached port variants and archived before/after cell.cpp.
