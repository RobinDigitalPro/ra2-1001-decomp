# 0x120880 · IonBlastClass::AI

The native match uses the 1.006 forms credited to meastes in diff 1 and batch 24’s ion port. The supplied community comparison is a different source, `gibbo232414_ionblast.cpp` for YR. It corroborates direct coordinate conversion, a typed inner alias and vector math, while retaining YR-specific behavior. Its reference to the center and its cross-product helper differ from the final RA2 spelling.

VC6 12.00.8168, level-2 flags, relocation operands masked. Counts are differing bytes / emitted padded section bytes. “Alone” applies one diff-1 hunk to the before body. “Reverted” restores the old hunk in the matched body. Each pair uses the same enclosing translation unit and headers. A shift can affect many downstream bytes. Controls: before **1,444/1,808**, matched **0/1,840**.

### H1 · `@@ -19,8 +19,5 @@` · **DECISIVE**

`Coord coord` followed by X, Z and Y stores becomes `Coord(Position.X, Position.Y, IonBridgeLeptonHeight + Position.Z)`. The constructor takes coordinates in argument order. The height also moves from `BRIDGE_LEPTON_HEIGHT` to a translation-unit constant. The hunk alone recovers 579 differences. Reverting both edits together breaks a fully matched body. This experiment cannot split constructor and constant effects, and masking the relocation does not verify its destination.

Alone 865/1,808. Reverted 1,305/1,840.

### H2 · `@@ -30,10 +27,11 @@` · **Coupled**

`Cell center(Position)` becomes `Position.As_Cell()` directly, bypassing a conversion wrapper. `FootClass * occupier = (FootClass *)Map[...].Cell_Occupier()` becomes a named `CellClass & cell` and `ObjectClass * occupier`. The general type follows the list through all nodes. H3 supplies the downcast for the guarded work. Old and new users require different static types.

Alone compile error C2039. Reverted compile error C2440.

### H3 · `@@ -41,4 +39,5 @@` · **Dependent declaration**

The old RTTI guard goes straight to `Point2D occupier_point`. The new guard first declares `FootClass * foot = (FootClass *)occupier`. Its scope expresses exactly where the code has established unit or infantry type. Alone this is an unused alias with the baseline score. Removing it from the matched body leaves the receiver in H4, H5 and H8 undefined.

Alone 1,444/1,808. Reverted compile error C2065.

### H4 · `@@ -53,8 +52,8 @@` · **Dependent receiver**

`occupier->Set_Speed` and `occupier->IonBlastYDrawOffset` become `foot->Set_Speed` and `foot->IonBlastYDrawOffset`. These operations require the subtype introduced at H3. No independent byte result for the receiver substitution.

Alone compile error C2065. Reverted compile error C2039.

### H5 · `@@ -76,7 +75,8 @@` · **Coupled storage and receiver**

`occupier->PrimaryFacing` becomes `foot->PrimaryFacing`. A scalar `float facing_cos` becomes the X member of a `Vector3 facing`, with `facing_sin` still separate. H7 consumes this storage form. Both individual hybrids lack the matching producer or receiver type.

Alone compile error C2065. Reverted compile error C2039.

### H6 · `@@ -86,5 +86,5 @@` · **DECISIVE**

`flat.Y * flat.Y + flat.X * flat.X` becomes `flat.X * flat.X + flat.Y * flat.Y`. The input order of two commutative terms affects the generated floating-point instructions. Alone the total count stays flat. In the matched context the four differing bytes establish that this exact order matters.

Alone 1,444/1,808. Reverted 4/1,840.

### H7 · `@@ -95,11 +95,13 @@` · **Coupled vector temporary**

Three named cross-product components and their explicit square root become `Length_Of(Vector3(...))`. Rotation checks that previously reused sine and cosine now use `c2`, `s2`, `c3`, `s3`. This presents VC6 a constructed temporary and a fresh pair of operands at each check. YR uses `Ion_Vector_Length(Vector3::Cross_Product(...))`; RA2 spells out the components at construction. H5 supplies `facing.X`, so the single-hunk trials cannot isolate length-helper or copy effects.

Alone compile error C2065. Reverted compile error C2065.

### H8 · `@@ -110,6 +112,6 @@` · **Dependent receiver**

`occupier->AngleRotatedSideways` and `occupier->AngleRotatedForwards` change receiver to `foot`. Both stores remain after the slope calculation. This completes the guarded subtype accesses. The hybrids fail type checking.

Alone compile error C2065. Reverted compile error C2039.

### H9 · `@@ -117,5 +119,5 @@` · **Byte-neutral in matched context**

`occupier = (FootClass *)occupier->Next` becomes `occupier = occupier->Next`. With H2 the list cursor has its base type. Restoring the old up/downcast spelling still emits an exact section. Applying H9 first to the old derived cursor fails its assignment.

Alone compile error C2440. Reverted 0/1,840.

## Why we did not find it

The ledger identifies batch 24’s paired `ion_port1` / `ion_port2` forms. WORK_QUEUE M1 credits the 1.006 port, and the I3 follow-up records the bridge height binding. The earlier body already had the RTTI test, explicit vector arithmetic and separate angle terms. The retained attempts do not demonstrate a pre-port grid combining direct construction, the new occupant types and `Vector3` storage with X-first reduction. H6’s flat standalone score is a measured reason a greedy single-edit search could discard it. Whether someone independently tried these particular hunks is unknown.

## How they found it

The native source comments credit meastes; no discovery log for that 1.006 implementation was supplied. The independent YR attempts at VA `0x0053CBE0` on 28 October and 2 November discuss x87 operand order and aliasing around the blast coordinate and cross product. The 9 November round credits the landed AI work to the dk8827 PR group. Those notes explain the YR line of investigation. They do not establish the order of discovery of the native constructor or H6.
