# 0x166110 · MapClass::Can_Repair_Bridge

`gibbo8c1df2_map.cpp` supplies the high-bridge dispatch and walk. There is one diff-1 hunk replacing 185 lines with 168. The former three differing bytes are the displacements on three uses of the same high-bridge search cell (+0x342, +0x356, +0x3d9). Batch 54’s port experiments identify low-bridge adaptations that affect those high-bridge stack slots. It resolved 11 of 72 relocation sites independently; 61 remained open.

VC6 12.00.8168, level-2 flags, relocation operands masked. Counts are differing bytes / emitted padded section bytes. “Alone” applies one diff-1 hunk to the before body. “Reverted” restores the old hunk in the matched body. Each pair uses the same enclosing translation unit and headers. A shift can affect many downstream bytes. Controls: before **3/2,112**, matched **0/2,112**.

### H1 · `@@ -1,185 +1,168 @@` · **DECISIVE**

The complete hunk takes the native baseline from three differences to zero. The source regions below distinguish structural edits from properties already present.

- **Discovery loop.** `IsometricTileType ittype` becomes `int ittype`. `Cell(cell + Cell(x, y))` becomes `Cell(Cell(x, y) + cell)` at map lookups. Both forms explicitly copy the sum. Low-bridge tests move into the same else-if chain. Table values stay unchanged; comment removal and `second_low_bridge` → `concrete` are cosmetic.
- **Dispatch.** `switch (found)` with the low cases first becomes `if (found)` with the high path first and its own false return. A `cellptr == NULL` guard precedes the low path. This changes the branch structure and lifetime overlap of the two bridge families.
- **High walk.** `topleft + Cell(_x[offset], _y[offset])` becomes `Cell(_x[offset], _y[offset]) + topleft`. The old `while (true)` returned immediately on an impassable connection. The donor sets `bool broken`, gates remaining work with `if (!broken)`, then tests the flag after the loop. The passability lookup through `ZoneConnections[index]` before forming `con` already exists on both sides.
- **Endpoint update.** Old `next = (entry.*step)(...)` in each arm plus a common `search = next` becomes `search = Adjacent_Cell(entry, dir)` separately after `entry = con->To` or `con->From`. The artificial pointer to the addition operator and the shared `next` disappear. The fallback endpoint returns true.
- **Concrete low bridge.** Cursor-initializing `for` loops with explicit break tests become `while (Is_Low_Bridge2(...))` loops using `walk` and `scan` declared above direction selection, plus explicit false returns. These cursors can be shared across orientations in the concrete path.
- **Wooden low bridge.** Old `for (Cell walk/scan = …)` becomes `Cell west/east/south/north` beside each `while (Is_Low_Bridge(...))`. Both native versions already scope these four walks locally and separate horizontal from vertical by else. Those two properties were essential adaptations when moving from the literal donor, which shares cursors and exits the horizontal path before its separate vertical scans. Renaming cursor directions by itself has no causal evidence.

**Decisive evidence within H1.** Batch 54’s first port gave 177/2,144. Selecting native signed tile-count constants gave 175/2,144; direction-local wood cursors then gave 31/2,112; expressing wood orientation as if/else yielded 0/2,112. A grid over all three choices confirmed the successful interaction. The tests establish these adaptations on the donor base. They do not isolate every high-path subexpression on the original three-byte baseline.

Alone 0/2,112. Reverted 3/2,112.

## Why we did not find it

Batch 14 and later native grids were extensive. Batch 44 reached three bytes; later retained forms still tied. In batch 54, replay of 471 distinct archived native builds across 573 valid labels found 20 instruction-aligned hits at each of the two early residue sites and none at the final write. The transferred Repair_Bridge entry reference tied at three; transferring its adjacent-cell step alone gave 1,335/2,176. Twenty-four broad crosses between native and donor chunks still tied at three. The full donor body supplied all three correct stack-slot operands despite initially scoring much worse overall. That observation justified keeping its high path and changing cursor scopes in the physically distant low path. Sources: ATTEMPT_LEDGER batch 14, batch 54 `map_REPORT.md` and `map.md`.

## How they found it

Gibbo’s YR notes describe a constant-looking boolean retained as a compiler scratch value. The 22 November notes record a matching flag-bearing form; the 23 November flag-free rewrite was still 99.5%. The 24 November PR #426 credits dk8827 and links the flag pattern to house/map generation work. The note identifies version differences in the high bridge. Native signed bounds, four wood cursors and the explicit orientation else are documented by the RA2 batch 54 replay.
