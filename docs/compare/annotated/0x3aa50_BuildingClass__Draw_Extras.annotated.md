# 0x3aa50 · BuildingClass::Draw_Extras

## Diff 1, hunk 1 · Barrel-only voxel translation (old 127, new 127)

**DECISIVE.** Our old expression constructed `Vector3` from `Get_X_Translation()`, `Get_Y_Translation()` and `Get_Z_Translation()`. The replacement is `Vector3 origin = matrix.Get_Translation();`. Both feed `matrix.Translate(-origin)`. The difference is how VC6 receives the three components as a result object. It changes scheduling farther down this specific branch. At the draw site near +0x859, the two pixel-offset loads and the stack load for the argument now precede the second type-pointer load and push. The comment giving credit is cosmetic.

Meastes 1.006 uses the aggregate getter in both turret paths in `src/recovered/building.cpp`, recovered slot 284. The gibbo YR body supplied for diffs 2 and 3 also uses an aggregate getter in those paths. Our port applies it **only** under the `AuxVoxel2.VoxLib` and `AuxVoxel2.MotLib` guard. The other path keeps three component reads. The extensive YR tint, draw arguments and cache-key differences in the comparison are outside this hunk.

**Compile check.** With B26's submitted building.cpp and headers, VC6 8168, level-2 flags and the relocation-masked checker, the starting object missed 22 bytes in a 2,704-byte section, first at +0x85a. Applying this hunk alone gave 0/2,704. B26 records 2,693 bytes before padding, 57 ordered direct calls and identical section bytes and relocation targets for 362 sibling functions in its combined build. The target's relocation bindings remain open. The later historical TU required declarations missing from the B26 headers, so the fresh single-hunk test used B26's archived input pair.

## Why we did not find it

**No documented earlier trial of the branch-specific accessor.** The ledger's B15 entry lists `extras3.json` through `extras6.json`, ranked alternately by hunk and byte counts. B15 explored 46 source hashes and retained 22 differences. The search varied draw expressions, arguments and evaluation order near the first differing instructions. It did not generate the preceding matrix extraction as an independent switch at each of two similar sites. B26's initial and extended searches still favored the submitted code. Its focused 38-candidate search, seeded with the donor's getter, identified the barrel-only placement.

## How they found it

B26 explicitly credits the meastes 1.006 source. Its discovery trail for the getter is unavailable. Gibbo's YR attempt log for 9 November, VA 0x0043DA80, records a TibSun reconstruction with YR-specific drawing and a 3,362-byte, 99.7% result. A later entry that day pinpoints evaluation of position and `&xy` around the push in the auxiliary-voxel branch and notes different scheduling at a similar site. That documents localization of the YR residue. It does not establish how the getter itself was discovered. Evidence: supplied function diff 1 and diffs 2–3, B15 and B26 reports, B26 `building_draw_focus.json`, gibbo `data/attempts.csv` rows 3257 and 3295.
