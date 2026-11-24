# 0xbe390 · FlyLocomotionClass::Nearing_Target

## Diff 1, hunk 1 · The turn tolerance becomes a receiver (old 47, new 47)

**DECISIVE with the companion helper in fly.cpp.** Before, the caller used `dir.Is_Complete_Turn(..., DirType(0x2000))`. After, it uses `Fly_Is_Complete_Turn(dir, ..., FlyTurnLimit(0x2000))`. The surrounding strafe test, distance limit, negation, primary facing and angle are the same. The new inline helper takes const references, creates `DirType difference(dir - towards)`, and tests `by.Magnitude_At_Least(difference)` through explicit true/false returns. The tolerance becomes the receiver of a separately emitted member. This changes the call boundary and how the difference temporary is passed.

Diffs 2 and 3 lack a named block, but B26's supplied meastes 1.006 `src/recovered/fly.cpp`, lines 837–845 and the strafe test near line 880, show an `UnknownFacingDir` difference and a call on `by` with that difference. The donor uses a helper for subtracting two raw angles and constructs an `UnknownFacingDir` from the tolerance. Our 1.001 port uses existing `DirType` subtraction and an inferred fly-specific derived type, `FlyTurnLimit`. See the separate 0xbf7a0 case for the callee.

**Compile check.** In the archived matched TU with the companion helper available, reverting only this caller hunk gave 956 differing bytes and a 1,632-byte compiled section. Restoring it gave 0/1,648 under VC6 8168 and the level-2 checker. The original body is 1,633 bytes before padding. B26 additionally verified that the original rel32 at RVA 0xbe5ed resolves to 0xbf7a0 and that the candidate calls the comparator there. Other caller bindings remain open. B26's combined object preserved all 98 other pre-existing functions.

## Why we did not find it

**Partly tried before.** F28 got five natural caller changes down to 48 hunks. A shared `face.h` comparison plus two dummy cell constructions produced zero locally, so the gauge was parked. M2 never reached this port. M3 recorded the upstream caller as unreachable with its then-current forms. C9/P6 subsequently **did** match caller and callee with a shared `DirType::operator>=` statement body. Header-wide checking lost hover `Process` and three other functions. The problem by that point was where to put the comparator so surrounding code kept its byte shapes. B26's native and nesting grids still omitted the separate comparison, incurring the missing-function penalty. Its seven-case turn-helper search reached zero with a fly-specific receiver and the out-of-line body.

## How they found it

The landed decomposition comes from meastes. The supplied donor source shows the call graph, but gives no search diary. Gibbo independently identified the YR `DirType::operator>=` target at VA 0x004D03D0 and the second `Direction` call in YR `Nearing_Target` (0x004CEFB0). Its 9–20 November attempts use fillers as an inline-budget gauge. The 23 November round notes credit a TU-local TibSun planar-distance helper for the two distances in the final YR caller. The archive supports those observations and the meastes helper structure separately. Evidence: B26 report and recovered fly.cpp, WORK_QUEUE F28, M2, M3 and C9/P6, gibbo `data/attempts.csv` rows 3231 and 3918 and November round notes.
