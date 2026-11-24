# 0x120fd0 · IonBlastClass::One_Time

The native ripple surface is 256 × 128. `gibbo232414_ionblast.cpp` uses a 512 × 256 YR surface. The port adapts center coordinates, stride and limits while keeping the community’s expression of all four addresses relative to one center.

VC6 12.00.8168, level-2 flags, relocation operands masked. Counts are differing bytes / emitted padded section bytes. “Alone” applies one diff-1 hunk to the before body. “Reverted” restores the old hunk in the matched body. Each pair uses the same enclosing translation unit and headers. A shift can affect many downstream bytes. Controls: before **17/544**, matched **0/544**.

### H1 · `@@ -13,15 +13,14 @@` · **DECISIVE**

`Lock() + 0x4080`, descending local `y` and descending `x` become `int x = 128`, `int y = 64` before `Lock() + (y << 8) + x`, reuse of `y`, and ascending `i` with `x = 127 - i`. This couples the center coordinates and the induction variables. With H2 reverted the score returns to 17. With H1 reverted the indexed-store form in H2 is 128 bytes away. Batch 44g’s hunk-scored variants include a constant-center winner, so the entire set of H1 spellings is not individually required.

Alone 17/544. Reverted 128/560.

### H2 · `@@ -29,9 +28,8 @@` · **DECISIVE**

`char * mirror = center - row`, `mirror[x]`, `mirror[-x]` become `center[-row + x]`, `center[-row - x]`. Both upper stores already used the center. All four stores now express their addresses using that same base. H2 alone increases differences and padded length. Only the combined two-hunk patch gives zero. This identifies an addressing/induction interaction without inferring that every naming change is required.

Alone 128/560. Reverted 17/544.

## Why we did not find it

Batch 17 recorded 26 unique candidates. Reusing a row value in five places recovered ECX but expanded the frame from 0x28 to 0x30. The prior F12 family already used a derived x, and F17/F22 tried address trees and register choices. The retained close body still used descending x and a named mirror pointer. Batch 44g’s reruns distinguish a descending-x variant (hunk score 6), a mirror-pointer variant (7) and multiplication (24). These scores count grouped differences and cannot be compared numerically to the byte tests above. The two one-hunk measurements show why accepting improvements one change at a time misses this pair.

## How they found it

The 12 November YR round records 6,016 permuter/fuzzy attempts without the raw match. The 23 November notes and attempts entry credit RobinDigitalPro with the winning form: name center coordinates and index all four pixels from the same pointer. The native port keeps its own resolution and `y << 8` row pitch. Sources are the YR rounds/attempts archive, batch 17 REPORT and batch 44g `ionblast.md`.
