# 0x152ef0 · MapClass::Repair_Bridge

The native source credits gibbo101’s `src/map.cpp` at `721d81e44f`, YR VA `0x00573540`. The supplied comparison is `gibbo8c1df2_map.cpp`. The transplant keeps the native bridge operations around the donor’s direction variables, walk, span loop and recursive calls.

VC6 12.00.8168, level-2 flags, relocation operands masked. Counts are differing bytes / emitted padded section bytes. “Alone” applies one diff-1 hunk to the before body. “Reverted” restores the old hunk in the matched body. Each pair uses the same enclosing translation unit and headers. A shift can affect many downstream bytes. Controls: before **1,813/2,784**, matched **0/2,752**.

### H1 · `@@ -20,11 +20,14 @@` · **Coupled declaration**

`int facing = FACING_FIRST` becomes `FacingType step` and `FacingType facing = FACING_N` at function scope. The first scan calls `Adjacent_Cell(cell, facing)` directly in place of `Facing_Add(facing, FACING_0)`. This removes the helper’s mask at the first use and supplies the types for H2–H4. The single-hunk edit leaves the before difference count unchanged.

Alone 1,813/2,784. Reverted compile error C2665.

### H2 · `@@ -32,5 +35,5 @@` · **DECISIVE**

For the second candidate cell, `Adjacent_Cell(adjacent, Facing_Add(facing, FACING_0))` becomes `Adjacent_Cell(adjacent, facing)`. The enum is already available in the matched context. Restoring the normalized argument here expands the section by 16 and breaks the match.

Alone compile error C2665. Reverted 1,520/2,768.

### H3 · `@@ -38,5 +41,5 @@` · **DECISIVE**

The third candidate repeats the same old `Facing_Add(facing, FACING_0)` wrapper. The new invocation passes `facing` directly. H2’s result does not cover this later use; reversing H3 alone also expands the section by 16.

Alone compile error C2665. Reverted 1,520/2,768.

### H4 · `@@ -74,22 +77,24 @@` · **DECISIVE**

`origin = cellptr->Fetch_CellID()` becomes a separate `Cell walk`. An integer ternary and `Adjacent_Cell(origin, FacingType(step))` become an if/else on the outer enum and `Cell const & from = walk` followed by `Adjacent_Cell_L(from, step)`. Only the final backsteps write `origin`. This separates the output cell from the induction object and puts the table term on the left inside the walk helper. The complete hunk is necessary; these tests cannot identify one individual line as sufficient.

Alone compile error C2065. Reverted 1,819/2,784.

### H5 · `@@ -97,12 +102,16 @@` · **Coupled direction and lifetimes**

`int advance = ... ? FACING_W : FACING_N` becomes a `FacingType advance` assigned by if/else before `spancell`; `int zonechanged` becomes `char` after the vector. The outer initialized `ittype` goes away for H7. The YR round independently identifies the advance selection as consequential. The native single-hunk hybrids fail on the missing tile variable or the old integer passed as an enum.

Alone compile error C2065. Reverted compile error C2665.

### H6 · `@@ -110,6 +119,5 @@` · **Paired loop edit**

`for (...; spancell = Adjacent_Cell(...))` becomes `while (spancell.X >= MapRect.X)`. H11 supplies the update at the bottom. Applying H6 alone drops the step; undoing H6 alone takes two steps. Their mismatch counts describe invalid walk variants and cannot establish whether `for` versus `while` alone matters.

Alone 1,814/2,656. Reverted 1,297/2,768.

### H7 · `@@ -123,5 +131,5 @@` · **Dependent lifetime**

An assignment to outer `ittype` becomes `IsometricTileType ittype = ...` at the tile read. This limits the value’s lifetime to the validity branch. Applied alone it shadows the old variable, adding one count; reverting it on top of H5 has no declaration to assign to.

Alone 1,814/2,784. Reverted compile error C2065.

### H8 · `@@ -129,5 +137,5 @@` · **Cosmetic for the match**

`spanptr->SubTile == 8` becomes `8 == spanptr->SubTile` in the same predicate. Reversal on the matched body emits identical bytes.

Alone 1,813/2,784. Reverted 0/2,752.

### H9 · `@@ -167,6 +175,5 @@` · **DECISIVE**

`Cell next = spancell + Cell(-2, 0)` and `Repair_Bridge(next)` become `Repair_Bridge(spancell + Cell(-2, 0))`. The recursive call binds its reference argument to the expression result. Reintroducing the named cell changes two bytes.

Alone 1,815/2,784. Reverted 2/2,752.

### H10 · `@@ -212,6 +219,5 @@` · **DECISIVE**

The vertical counterpart, `Cell next = spancell + Cell(0, -2)`, likewise becomes `Repair_Bridge(spancell + Cell(0, -2))`. Restoring this one named argument independently changes two bytes.

Alone 1,814/2,784. Reverted 2/2,752.

### H11 · `@@ -220,4 +226,5 @@` · **Paired loop edit**

The old loop closes immediately; the new body ends with `spancell = Adjacent_Cell(spancell, advance)`. Read with H6. Restoring the old end without the old increment removes advancement; the 2,210 differences from that experiment cannot be attributed to a valid alternative loop spelling.

Alone compile error C2665. Reverted 2,210/2,704.

## Why we did not find it

Batch 20 and its ledger entry already cover scan and direction forms, recursive arguments, flag width, tile-type lifetime and origin reuse. Its report gives 344 successful compiles including duplicates, with two 144-way grids. It moved the baseline from 1,818 differences / 28 calls to 1,813 / 29. A seemingly better 80-hunk candidate had only 24 calls; the selection kept 94 hunks and 29 calls. The native sibling used to guide the search reused `origin`. The donor gave the separate aliased walker and direct enum uses at all scan sites. On the old baseline, H9 and H10 individually score worse even though each is needed in the matched body.

## How they found it

Gibbo’s 16 November YR round transferred the walk and reference alias from a bridge twin and reports 48.8% → 79.9%. The 23 November round describes the last direction selection: assign `advance` by if/else like `step`. A permuter alternative with a do/while altered a distant add/register choice and helped locate the sensitivity. The YR result covers 2,743 unpadded bytes; the measured native section here is 2,752 padded bytes. Sources are `gibbo.zip` November round notes, batch 20 REPORT and the ledger entry for this RVA.
