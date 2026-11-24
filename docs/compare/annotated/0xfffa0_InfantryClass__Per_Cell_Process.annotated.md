# 0xfffa0 · InfantryClass::Per_Cell_Process

## Diff 1, hunk 1 · Limit the nav-target pointer to its own block (old 65, new 65)

**Coupled prerequisite for H2's landed form.** Before, a single `TechnoClass * tech;` was declared outside the navigation block and assigned inside it. After, the checked assignment declares its own `TechnoClass * tech = (TechnoClass *)NavCom;`. This ends the nav pointer's lifetime with that block and frees its name for a separately typed building pointer. Compiling H1 alone on the old TU leaves subsequent uses without a declaration. Independent sufficiency cannot be assigned to the scope change.

## Hunk 2 · Give the cell building its own static type (old 98, new 97)

**Coupled prerequisite.** `tech = cellptr->Cell_Building();` becomes `BuildingClass * tech = cellptr->Cell_Building();`. From this point the receiver has the type returned by the cell helper, permitting direct building-specific members and the later type accessor. H2 alone on the failed TU redeclares the outer `tech` with a different type. Diffs 2 and 3 contain no full YR function. The landed attribution cites gibbo `src/infantry.cpp` at `721d81e44f`, YR VA 0x00519630. Gibbo reports reusing one building pointer across end-of-move branches. Our earlier nav check still owns a **distinct** `TechnoClass *`.

## Hunk 3 · Move the accumulator and keep both cell sums as direct expressions (old 107, new 106)

**DECISIVE.** Before, `bool train = false` preceded the optional bridge-repair announcement. After, it follows the player-control test and `Queue_Speech`, immediately before the scan. The two old map subscripts also explicitly copied each sum with `(Cell)Cell(...)`. The new code uses `PositionCell + Cell(x, y)` for the tile type and `Cell(x, y) + PositionCell` for the overlay. Both operand orders and both lookups are preserved. Dropping the cast on the hut receiver is cosmetic after H2. So is the attribution comment.

Fresh reversions against the complete matched TU isolate the effects. Moving only the initialization back before the announcement gives **17** differing bytes, first at +0x584. Restoring only the two old cell wrappers gives **11**, first at +0x601. Restoring only the hut receiver cast gives **zero**. Reverting all of H3 gives **28** differences. All four builds retained the 4,560-byte section. The two apparently redundant cell constructions affect code generation even with identical operand order.

## Hunk 4 · Name the ally's type before reading its maximum strength (old 137, new 138)

**DECISIVE.** The old test read `tech->TClass->MaxStrength` directly. The new code evaluates `TechnoTypeClass const * ttype = tech->Techno_Type_Class();` before testing `ttype->MaxStrength`. The occupation test also drops a receiver cast made redundant by H2. Reverting the whole hunk gave 2,690 differences in a shortened 4,544-byte section, first at +0x41. Reverting only the named read to the old field did the same. Crucially, keeping the accessor but writing `tech->Techno_Type_Class()->MaxStrength` inline also gave 2,690/4,544. The named pointer changes how VC6 allocates values across the function, including code **before** the source edit.

## Hunk 5 · Captureability receiver (old 147, new 149)

**Cosmetic with H2, independently compiled.** `((BuildingClass *)tech)->Class->IsCaptureable` becomes `tech->Class->IsCaptureable`. Restoring the cast in the matched TU retained 0/4,560.

## Hunk 6 · Spy receiver (old 174, new 176)

**Cosmetic with H2, independently compiled.** `((BuildingClass *)tech)->Spied_By(House)` becomes `tech->Spied_By(House)`. Restoring this cast alone also retained 0/4,560. On the old shared-pointer baseline, removing these casts in isolation fails to compile because `TechnoClass` lacks the corresponding building members.

**Controls.** Fresh historical before and after TU builds under VC6 8168 and level-2 flags gave 17/4,560 and 0/4,560 respectively, with relocations masked and bindings open in the matched result. These count differing bytes rather than source lines. The direct ablations of H3 and H4 are conditional on the full matched context. H1 and H2 are structurally dependent, so the builds do not rank either independently. WORK_QUEUE C8/P5 recorded all 100 infantry controls passing at integration.

## Why we did not find it

**Partly tried.** The ledger's B17 entry is explicit about `infantry_4.json`: announcement first, checked building cast, sequenced tile load. Its diagnostic placed the store correctly but the checked cast added four instructions. The section grew to 4,576 bytes and missed 2,638. Across seven searches and 151 source hashes, B17 varied pointer lifetimes, references, guarded access, row helpers and earlier uses of the competing pointer. F12 diagnosed a register competition between `y` and `tech`. F22 examined cell helpers. Those searches concentrated on adding uses before the bridge scan or reworking that scan. The donor's later ally-branch named type provides a register-allocation change outside that window, while the announcement order and direct cell sums fix separate residue. C8/P5 retained the combination with the donor credit.

## How they found it

Gibbo's 23 November `data/attempts.csv` row 4049 reports that naming `ttype` in the ally branch changed allocation throughout the YR function. Reusing a building pointer in the occupy and `MISSION_EATEN` blocks brought the YR named-local count to seven. The November round notes repeat these two observations. Older YR attempts on 19–20 November had tracked a different register assignment for `&PositionCoord` and `cellptr` early in the function. The YR account explains the remote-local clue. It does not independently credit the YR match to the two RA2 cell-wrapper removals measured above. Sources: supplied diff 1 and attribution, B17 report, WORK_QUEUE F12/F22 and C8/P5, gibbo November round notes and attempt rows 3866, 3959 and 4049.
