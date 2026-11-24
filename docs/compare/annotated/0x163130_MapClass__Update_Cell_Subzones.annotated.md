# 0x163130 · MapClass::Update_Cell_Subzones

`gibbo8c1df2_map.cpp` supplies the traversal and the two pointer-returning record lookups. The RA2 port preserves `Register_Zone_Connection_Entries(&connection, subzone)` where YR passes `connection`. Batch 49’s historical before was 1,865 differences with its own inputs. Using the supplied diff-1 before body in the matched translation unit and refreshed headers gives the separate control below. Batch 49 independently verified all 26 native relocations.

VC6 12.00.8168, level-2 flags, relocation operands masked. Counts are differing bytes / emitted padded section bytes. “Alone” applies one diff-1 hunk to the before body. “Reverted” restores the old hunk in the matched body. Each pair uses the same enclosing translation unit and headers. A shift can affect many downstream bytes. Controls: before **1,898/2,336**, matched **0/2,288**.

### H1 · `@@ -1,10 +1,9 @@` · **Byte-neutral in matched context**

`In_Local_Radar(cell)` becomes `In_Local_Radar(cell, true)`, the shared `Cell trycell` declaration disappears, and `2` becomes `SUBZONE_COUNT-1`. With local objects in H7/H8/H12, restoring the old declaration and spellings preserves the whole section. Removing the declaration alone leaves old users undefined.

Alone compile error C2065. Reverted 0/2,288.

### H2 · `@@ -12,10 +11,6 @@` · **DECISIVE**

Separate `Rect bounds` field writes for width, height, X and Y become a named power-of-two `size` and `Rect(Point2D(...), size, size)`. The rectangle constructor receives both aligned coordinates and both equal dimensions at once. Reverting the hunk keeps length but destroys agreement across most of the body.

Alone 2,010/2,320. Reverted 1,893/2,288.

### H3 · `@@ -24,7 +19,5 @@` · **Byte-neutral in matched context**

The explicit loop `set->Buckets[bucket].Clear()` becomes `set->Clear()` at the container boundary. It changes the old baseline by itself but reversing it after the port preserves every masked byte. Byte equality here applies to this compiled use of the container operation.

Alone 1,981/2,336. Reverted 0/2,288.

### H4 · `@@ -36,5 +29,5 @@` · **Cosmetic**

`Subzone_Of(this, Cell(x, y))` is exactly the same executable expression on both sides. Only the trailing comment changes from a partial-match explanation to the rationale for a separate temporary.

Alone 1,898/2,336. Reverted 0/2,288.

### H5 · `@@ -50,5 +43,5 @@` · **DECISIVE**

`Get_Cell_Zone_ID(Cell(x, y))` becomes `Zone_Of(this, Cell(x, y))->ZoneID`. The former returns a scalar ID. The latter finds the zone record and loads its member, using the same pointer-helper family as the later passability read. Applying this one lookup on the old body ties its score; reverting it on the matched body loses 1,698 bytes.

Alone 1,898/2,336. Reverted 1,698/2,288.

### H6 · `@@ -59,9 +52,9 @@` · **DECISIVE**

Descending loops declared `int idx` and `int i`. Their counters and subscript uses become the already declared `y` and `x`. This reuses existing function-scope objects across the spatial and connection passes. These are actual declaration/lifetime changes, not just two identifiers renamed globally. Undoing them produces 109 differences at identical length.

Alone 1,899/2,336. Reverted 109/2,288.

### H7 · `@@ -83,22 +76,20 @@` · **Coupled temporary and helper forms**

One `Cell cella` with X/Y field assignments was reused for radar, `Subzone_Of` and the zone-index array read. Now each call takes its own `Cell(x, y)`; `Zone_Of(...)->Passability` reads the zone record. `Subzone_Span` receives a separately named `Cell seed(x, y)` instead of the shared `trycell`. Parent selection also changes from default zero plus conditional override to an explicit if/else. Alone this changes the output; reverse requires the removed outer declaration. Individual necessity of these subedits is unmeasured.

Alone 2,001/2,352. Reverted compile error C2065.

### H8 · `@@ -106,5 +97,5 @@` · **Coupled temporary**

`Cell_Region(trycell)` becomes `Cell_Region(Cell(x, y))`. H7 gives the flood call its own writable seed; the region lookup reconstructs its coordinates independently. The inline region helper already existed. The reversal refers to the removed outer variable.

Alone 1,972/2,336. Reverted compile error C2065.

### H9 · `@@ -124,5 +115,6 @@` · **Cosmetic**

The same `bounds.Is_Point_Within(...) || bounds.Is_Point_Within(...)` predicate is split across lines and its comment removed. The nearby pointer call is unchanged across diff 1 and is the native adaptation in diff 2. Reversing H9 changes zero bytes.

Alone 1,898/2,336. Reverted 0/2,288.

### H10 · `@@ -136,7 +128,8 @@` · **DECISIVE**

Repeated `set->Buckets[bucket_index]` expressions become one `BucketType & bucket`. Both `Count()` calls and `&bucket[0]` share this reference. Alone it improves by 17 differences. In the matched body it is necessary for 674 bytes at unchanged length.

Alone 1,881/2,320. Reverted 674/2,288.

### H11 · `@@ -144,11 +137,9 @@` · **Byte-neutral in matched context**

`SubzoneConnectionStruct conn` plus `conn.SubzoneID = high` becomes `SubzoneConnectionStruct conn(high)`, likewise for `low`. The cross-block flag and the `Connections.Add` calls remain separate. Reversing these constructors preserves every byte.

Alone 1,898/2,336. Reverted 0/2,288.

### H12 · `@@ -164,13 +155,11 @@` · **Coupled rectangle and probe lifetimes**

`basex`, `basey` and a shared `trycell` become `Rect block(..., 8, 8)`, a named `Cell probe(x, y)` for the radar predicate and a fresh `Cell(x, y)` for `Subzone_Of`. The loop uses rectangle fields and the symbolic level count. Applied alone it changes section length and score. A clean reversal requires the removed declaration, so subedit necessity remains open.

Alone 1,966/2,320. Reverted compile error C2065.

## Why we did not find it

The ledger has no target-specific row. Batch 47’s before code already contains `Subzone_Of`, `Cell_Region` and the native pointer connection call. Batch 49’s `target05_map.md` records 2,182 differences for a fresh reconstruction, 1,907 for separate zone/subzone queries and a direct record read, and 1,865 for the input. Its helper-byte grid examined 144 cached rows without beating 1,865. The winner used the fuller sibling traversal and zone-pointer helper together. In the present tests H2 alone gets worse and H5 ties, yet each is required in the port. Testing the correct helpers without the matching rectangle construction, counter lifetimes and bucket reference gave little direction.

## How they found it

Gibbo’s November notes trace `Subzone_Of` to repeated lookups in two zone-reset functions. On 19 November the YR banked body was 60.1%, with matching length and all 25 calls but swapped registers; the 23 November notes still describe a partial result. The 24 November round records `Zone_Of` alongside the shared `Subzone_Of`. This supports a sibling-helper discovery. The supplied record does not identify an experiment isolating the bucket reference or rectangle construction on the YR build.
