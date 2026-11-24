# 0xbf7a0 · FlyTurnLimit::Magnitude_At_Least

## Diff 1 has no hunk · Standalone comparator recovered from the full TU

**DECISIVE structural addition.** All three supplied body diffs say “not available.” In `history_before_after.zip`, the before fly.cpp lacks an out-of-line member with this name. The after TU adds `class FlyTurnLimit : public DirType`, an explicit angle constructor and a const member taking `DirType const &other`. Its out-of-class body returns `abs(Facing) >= abs(other.Facing)`. A paired `#pragma auto_inline(off)` / `on` surrounds the definition. The inline caller computes a direction difference and invokes the member on the tolerance. These are source additions established from the historic TUs, with no invented deletion or hunk coordinate.

The 1.006 donor is meastes' `src/recovered/classes/UnknownFacingDir/Magnitude_At_Least.cpp`, VA 0x004bfb30. Its body compares `abs((short)Raw)` against the other angle's signed magnitude using inclusive comparison. Our `Facing` members are already signed 16-bit quantities promoted for `abs`. The donor's fly.cpp passes the difference by reference with `by` as receiver. The 1.001 subclass and method name are hypotheses. The behavior, the separate callable body and its caller are independently testable.

**Compile check.** Rebuilding the historical before TU found no matching symbol for this method. The after TU emitted a stand-alone 48-byte section, 0 differing bytes, checker status `matched`. B26 gives the original body as 36 bytes plus alignment. It also checked the original call from RVA 0xbe5ed to 0xbf7a0. The emission result verifies the landed declaration/body and caller context as a unit. The private test does not show that every spelling, or the pragma by itself, is uniquely necessary. Comments crediting the donor generate no code.

## Why we did not find it

**Partly tried, with an earlier exact but unintegrable alternative.** F28 targeted the caller's inline budget. C9/P6 matched the comparator and caller by assigning `As_Int()` results to two ints, overwriting each with its absolute value and comparing them inside shared `DirType::operator>=`. The shared edit regressed hover `Process`, `Zone_Reset`, `Print_CRCs` and `SelectClass::Action`. It was parked. In B26 the native and nesting candidates scored a million-point penalty for absence of a separate comparator, even where caller code improved. The meastes-derived local type gave VC6 a new callable body without altering shared heading operations. B26 distributed it as two replayable edit lists covering the helper/call and type/definition together.

## How they found it

Meastes supplies the arithmetic and member boundary under a recovered name and marks its original spelling uncertain. No discovery log accompanies that source. Gibbo's YR attempts for VA 0x004D03D0 document a different route: taking the address of `DirType::operator>=` forced VC6 to emit its 36 bytes so they could be compared. The 11 November entry records identical comparison bytes across two header forms and identifies the pending caller as the condition for real emission. This was evidence for a standalone target before B26's 1.001 implementation. Sources: B26 report and donor files, historical fly.cpp pair, WORK_QUEUE C9/P6, gibbo `data/attempts.csv` rows 3101 and 3321.
