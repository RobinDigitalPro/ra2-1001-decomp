# 0x154520 · MapClass::Destroy_Low_Bridge_Near

Diff 2 reports identical extracted bodies for the matched code and meastes’ `meastes1006_map.cpp`. Batch 44 compiled the 1.006 body in both translation units, established all 51 bindings separately and localized all 12 incoming differences to the opposite-end walk at native RVAs `1549ca–154a82` (end exclusive). A baseline difference at that location does not imply the winning source edit was confined to that location.

VC6 12.00.8168, level-2 flags, relocation operands masked. Counts are differing bytes / emitted padded section bytes. “Alone” applies one diff-1 hunk to the before body. “Reverted” restores the old hunk in the matched body. Each pair uses the same enclosing translation unit and headers. A shift can affect many downstream bytes. Controls: before **12/1,552**, matched **0/1,552**.

### H1 · `@@ -10,18 +10,18 @@` · **Coupled types**

`int step` and `int facing = 0` become enum variables initialized with `FACING_N` for the scan. Three casts at adjacency calls disappear. `facing = (facing + 1) & 7` becomes `Facing_Add(facing, FACING_NE)`. H2 and H6 also have to produce compatible enums. These hybrids cannot isolate a register effect.

Alone compile error C2440. Reverted compile error C2664.

### H2 · `@@ -35,9 +35,10 @@` · **Coupled types; existing alias**

`step = 4` / `step = 2` become `FACING_S` / `FACING_E`. `Adjacent_Cell_L(from, FacingType(step))` becomes `Adjacent_Cell_L(from, step)`. Both versions already bind `Cell const & from = walk` and use the left-add helper. Splitting the alias onto its own line is cosmetic. The removal of the cast follows H1’s enum type.

Alone compile error C2664. Reverted compile error C2440.

### H3 · `@@ -47,9 +48,9 @@` · **Coupled types**

`(step - 4) & 7` becomes `Facing_Sub(step, FACING_180)`, and the numeric `6 : 0` selection becomes enum `FACING_W : FACING_N`. The compound `origin` expression is already present. H3 alone ties the old score; its reversal feeds an integer to H5’s call.

Alone 12/1,552. Reverted compile error C2665.

### H4 · `@@ -60,5 +61,5 @@` · **DECISIVE**

`Is_Valid(spancell)` becomes `Array[spancell.X + spancell.Y * MAP_CELL_W] != NULL`. The scan names the array slot test directly, influencing code generation even though the original baseline mismatch was later. Alone it worsens the old score; reverting it from the matched body loses 373 bytes and shrinks the section by 16.

Alone 1,324/1,568. Reverted 373/1,536.

### H5 · `@@ -68,5 +69,5 @@` · **Byte-neutral in matched context**

The first span loop replaces `Adjacent_Cell_L(spancell, FacingType(shared_direction))` with `Adjacent_Cell(spancell, shared_direction)`. The operand-order helper changes at this site. Reverting it alone in the matched body preserves every byte.

Alone compile error C2665. Reverted 0/1,552.

### H6 · `@@ -75,5 +76,5 @@` · **Coupled types**

`step = (shared_direction - 4) & 7` becomes `step = Facing_Sub(shared_direction, FACING_180)` before initializing the other-end cursor. Alone it ties the old count. The reverse cannot assign the raw integer expression to the new enum.

Alone 12/1,552. Reverted compile error C2440.

### H7 · `@@ -82,5 +83,5 @@` · **DECISIVE**

The opposite-end loop changes `Adjacent_Cell_L(end, FacingType(step))` to `Adjacent_Cell(end, step)`. Here the operand order matters: reverting it restores ten differences. Batch 44 locates the Y add at +0x4b4, where the target first loads the walking cell’s Y from the stack.

Alone compile error C2665. Reverted 10/1,552.

### H8 · `@@ -91,5 +92,5 @@` · **DECISIVE**

After the walk, `AdjacentCell[(step - 4) & 7] + end` becomes `end + AdjacentCell[(step - 4) & 7]`. Keeping the offset on the left breaks 124 bytes in the matched body. This adjustment sits outside the original 12-byte mismatch region. H7 and H8 must be considered separately from H5’s byte-neutral change.

Alone 136/1,552. Reverted 124/1,552.

## Why we did not find it

Batch 25 had already selected left-first additions inspired by bridge twins. Its bridge grid improved the close body from 15 to 12 differences. Batch 44’s `target05/destroy5.md` shows a single opposite-end transfer produced 15 differences, while the partial Repair_Bridge port of direction types and current-cell-first adjacency gave 370. Both looked worse despite targeting the right instruction family. Testing the complete 1.006 body restored the schedule, including the input predicate and final adjustment. Its first two greedy grids only reached hunk score 9. The successful grid used the ported body as its base. The batch 25 direct report identifies the bridge grids more precisely than the ledger’s target/spec indexing.

## How they found it

The native donor is meastes 1.006. Its discovery sequence is undocumented in the supplied material. Gibbo’s separate 9 November YR work on DestroyConcreteBridgeAt and DestroyWoodBridgeAt transferred a high-bridge sibling walk and found an origin-cell branch that corrected a 0x38 frame to 0x34. The wooden twin remained partial (62.2%). These explain where earlier sibling ideas came from; the measured native result comes from batch 44’s two-TU triangulation.
