# 0x219e20 · Quaternion::Make_Closest

## Diff 1, hunk 1 of 1 — **DECISIVE**

**Before** · `Quaternion t = *this`, then `t * Inverse(qto)`. The negative candidate was constructed from four negated members and multiplied by another explicit inverse. **After** · `Quaternion(*this) / qto` and `-*this / qto`. The first expression forces a temporary copy; the second invokes unary minus. Both put the inverse/product operations behind overloaded division. The two relative orientations and the strict hemisphere comparison survive the port.

The rest of the hunk spells both squared norms as four indexed terms in component order, changes four named-member negations to indexed stores, and corrects the address comment. Diff 2 shows that only the address comment distinguishes the port from `gibbo8c1df2_quat.cpp`. Batch 54's controls show which differences matter. Starting from the winner, expanding the positive or negative division separately scores 28 or 31 in that batch's instruction-hunk metric (zero is exact). Removing the positive copy scores 5; constructing the negative quaternion directly scores 16. Restoring either `Length2()`, switching the final stores back to named members, or using the tested `Invert` form still scores zero. The call expressions and temporary boundaries carry the match; the component spellings and comment are optional in the tested contexts.

**Rebuild.** Applying this sole hunk to the failed translation unit with VC6 8168 and the level-2 options reduced 445 relocation-masked differing bytes in a 480-byte section to zero in 368 bytes. Batch 54 bound the five resulting call relocations, in order, to inverse, multiply, the four-float constructor, inverse, and multiply. The failed object emitted only two calls.

## Why we did not find it

**Partly.** There is no row for this target in the supplied attempt ledger. Batch 54's sibling reconstruction moved the inverse/product into the caller and retained 470 differing bytes. A fresh reconstruction also named the inverse/product and negative construction explicitly. Those searches got the arithmetic right, but put the expression boundary on the other side of overloaded division. There is no recorded pre-port candidate containing both division expressions with these operands. See batch 54 `output/result/quat.md` and its fresh-reconstruction notes.

## How they found it

Gibbo's attempt log (records 2011 and 3596) identifies the out-of-line calls that their compiler kept inlining and records a weaker named-`t` form at 89.6%. The latter entry already lists a parked 100% form. The 24 November round notes cite dk8827's quaternion sibling work (PR #369) and cross-version helper checks. The archive supports that sequence and the winning source at `8c1df26`; it does not identify the first trial that produced the positive copy and unary-minus pairing.
