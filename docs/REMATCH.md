# REMATCH list (quality audit, 2026-11-23)

The user decided "do 1, 2, 3 in order" (stocktake STOCKTAKE_20261123.md): step 1 is this quality audit.

Claims stay while their functions are listed here; an entry is closed when a natural form is found (or the construct is shown to be original).

## How it was made

- `W/tools/level2_forcing_audit.py` scanned all 673 claimed C++ TUs.
  - Compiler warnings: CL -Zs -W4 with the real defines and include paths, for unused locals, unreferenced initialised locals and constant conditions.
  - Source patterns: if/while(0), member-pointer locals, Ghidra names, numbered temporaries, volatile locals, inline asm, bare blocks, empty blocks, the same statement before and after an else, single-use INFERRED helpers.
  - Output: audit_2026-11-23T2004Z.json; summary in FORCING_AUDIT_2026-11-23T2004Z.md.
- `W/tools/level2_forcing_review.py` then splits the findings:
  - *upstream*: the identical line is in the mischa85 1.006 source;
  - *ours*: our own edits;
  - *claimed*: inside a claimed function.
  - Output: rematch_2026-11-23T2004Z.json.
- `W/tools/level2_label_audit.py` lists addresses known under two names. Output: labels_2026-11-23T2003Z.json.

## Totals

| Origin | Claimed | Strong | Weak |
|---|---|---:|---:|
| ours | yes | 27 | 26 |
| ours | no | 30 | 1 |
| upstream | yes | 173 | 237 |
| upstream | no | 82 | 49 |

- The *upstream* findings are forms of the mischa85 1.006 decompilation that matched 1.001 unchanged; mostly C4127 constant conditions and C4189 initialised-but-unused locals. They are not ours to change now; they go to the rework phase.
- *ours, not claimed* is unfinished near-miss work.

## Ours, inside claimed functions: verdicts

1. **wonline.cpp: 11 dialog procs with `do SetWindowLong(window, 8, ...); while (0);`.**
   - CLOSED 2026-11-23: replaced by one INFERRED macro `Set_Dialog_Init_Param` (the do/while(0) shape is a macro expansion; DWL_USER instead of 8).
   - The preprocessor gives identical code: integrator w320, wonline 359/359.
2. **Same statement in both arms (6), to review:**
   - tactical.cpp Tactical::Pixel_To_Cell (2085, the bridge height adjust);
   - tactical.cpp Tactical::Flag_Cell (3690, Coord_To_Pixel);
   - techno.cpp TechnoClass::Get_Z_Adjust (7014, `ramp = true`);
   - ToolTip.cpp ToolTipManager::Update (681, Clear_Info);
   - TU_42EFA0.cpp Benchmark::End (99, `Average += value`);
   - TU_5A4120.cpp XMP_Signed_Mult_Int (748).

   Some may be original (a duplicated call in both arms is normal C). Each needs a look at the disassembly: if the original has two separate copies, the form is faithful.
3. **Inline asm in C++ (8 sites), to confirm as original:**
   - MPSiegeTeam.cpp Read_Time_Stamp / Get_RDTSC_CPU_Speed (RDTSC, which VC6 cannot emit from C);
   - BLIT_INSTANCES.cpp BlitForward (3 blocks);
   - Conquer.CPP Main_Game;
   - cell.cpp CellClass::Draw_Shroud_Or_Fog_Shape.

   An instruction VC6 cannot generate from C is evidence that the original had inline asm. Record that evidence per site; this is not the matched-asm fallback.
4. **Scope blocks (weak, 11):**
   - 7 are the remains of a removed 1.006 condition (`{ // level-2 1.001: no ... check`). They are faithful to 1.001 when the braces are needed for the frame; otherwise drop the braces.
   - unit.cpp:1119 Visceroid_AI says "own scope gives the 1.001 frame": a scope used for frame layout is legitimate C, but check whether a natural local placement gives the same frame.
   - MapSel.CPP:252 and Skirmish.cpp:462/466 (bare scopes) are to review.
5. **False positives:**
   - motlib.cpp Debug_Window_Current_Page / Debug_Window_Get_Page are real functions at their own addresses, not steering helpers;
   - the t0/t1/t2 names in MPSiegeTeam.cpp and the XMP code are normal timer and bignum names.

## Label audit

- **One rva claimed twice:** 0x169ed0, the ZeroRect initializer.
  - Claimed as TU_569D00 `_$E41` (the last of 14 initialisers there) and as TU_569EF0 `_$E2` (the first of 13).
  - Both bodies are identical, so both pass level2_check. Only one object can own the address; the link check (P9) decides by object order. Then remove the wrong one (rule 8).
- **Four symbols whose symbol-map address differs from their claimed address:**
  - `??RRandomClass@@QAEHHH@Z` (map 0x62fe40, claim 0x22fcc0);
  - `??1BufferClass@@QAE@XZ` (map 0x438290, claim 0x38360);
  - `??B` / `??R` of `CDTimerClass<FrameTimerClass>`: map and claims are swapped, 0x453b30 versus 0x4a4a30.

  Either two copies of the same inline exist (per-module COMDAT copies, legitimate), or one label is wrong. Tiny bodies such as `return x` match anywhere, so the link check decides.
- **850 claims whose address the symbol map also knows under another name:**
  - 541 differ in the function name only, 119 in the class only, 190 in both;
  - 129 involve provisional names (Func_XXXXXX, Object_XXXXXX).
  - Most are the two naming trees (src/ra2 provisional names against m85 names). No byte effect; naming unification is rework-phase work.
  - Concrete case: 0x524560 `IPXManagerClass::Send_Global_Message` (ipxmgr.cpp) is called in Init.CPP as `ConnectionManagerClass::Send_Private_Message`.

## Accepted kind-1 matches (STEERING label, AGENTS.md rule 9)

- scenario.cpp `ScenarioClass::ScenarioClass(NoInitClass const &)` 0x252810 (batch 38). The INFERRED one-line wrapper `Lookup_Scenario_String` is used at 1 of 10 identical LoadString sites. Integrated 2026-11-23 (scenario 68/68).
- techno.cpp `TechnoClass::Rock` 0x2cb4b0 (batch 37 form; batch 39 found no cleaner form, best 7 bytes): two copies each of the cosine and sine values. Integrated (techno 252/252).
- bomb.cpp `BombListClass::Update` 0x360b0 (batch 37 form; batch 39 got worse): a member-pointer local keeps Point3D::Length out of line. Integrated (bomb 26/26).
- map.cpp `MapClass::Register_Zone_Connection_Entries` 0x161950 (batch 36): the same assignment `tile = cell1ptr->ITType;` in both arms. Integrated (map 286/286).
- queue.cpp Print_CRCs 0x221b90, sidebar.cpp SelectClass::Action 0x2761a0, startup.cpp WinMain 0x283970 (batch 43v, victims of the building.h Do_MISSION_CAPTURE override line): snapshot locals, a declaration order comment with a direct Build_Rate call, and an INFERRED Intro_Section() helper. Integrated 2026-11-24.
- super.cpp SuperClass::Place 0x292ef0 (2026-11-26, Codex job f7dcf95d): kind-1 STEERING one-line inline wrapper Adjacent_Coordinate for Cell addition (chrono cell), plus named const locals for the Create_Bullet arguments and a TVelocity2D reference instead of a cast. Rework: inline the wrapper if it still matches.
- particle.cpp ParticleClass::Spark_Behavior_AI 0x201120 (2026-11-26, deep s1 job 94e31c4d): kind-1 STEERING: file-local helper Spark_Ballistic_Step with a caller-owned 'blocked' result, the bridge-crossing test order swapped, the obstruction result kept through both building checks. Rework: simplify if it still matches.
- missile.cpp Projectile_Motion 0x190670 (2026-11-26, deep p1 job 679c51bc): kind-1 STEERING in an anonymous namespace: MotionVector (homing velocity snapshot from planar base + height), MotionMagnitude (own magnitude expansion for the speed return), named turn differences at the yaw and low-altitude pitch sites; all four hunks necessary (16 subsets tested).
- building.cpp BuildingClass::Exit_Object 0x402b0 (2026-11-28, Claude agent exit1; 1291 -> 10 bytes, NEAR_EQUAL, not a claim yet): kind-1 STEERING labels: refinery `exitcell = Center_Coord().As_Cell() + AdjacentCell[FACING_SW]` (direct sum, store to slot 0x18), vehicle-arm `Coord const & exitcellcoord` (keeps $S/$E static names in Find_Unit_Repair_Facility and Draw_Radial_Indicator), clone `nav` local, shipyard facing. Two obsolete labels removed. Rework: re-test once the 10-byte `add ecx,edx`/`add edx,ecx` residue is closed.
- bullet.cpp BulletClass::AI 0x5f380 (2026-11-28, Claude agent bullet1; 4760 -> 1939 bytes, NEAR_EQUAL, not a claim): kind-1 STEERING: Ballistic_Move's speed limit `if (max_velocity > 0.0 && velocity.Speed() > max_velocity) velocity *= max_velocity / velocity.Speed();`, unused by bullets (0.0) but real code (ruled kind 1, not kind 2), which sends operator+= and Coord(int,int,int) out of line as in 1.001; `double z = previous.Z;` standing in for a (planar, z) velocity constructor. Rework: replace the second with the constructor once headers are final.
- Multiplayer.cpp MultiplayerGameMode::Fill_Game_Mode_Combo 0x1b3bc0 and Fill_Game_Mode_List 0x1b3cf0 (2026-11-28, Claude agent own1): kind-1 STEERING file-local one-line accessors Game_Mode_Name and Game_Mode_ID (gibbo YR twin form) that, with the restored placement-new VectorClass constructor, keep both Game_Modes() constructor calls out of line as in 1.001. Rework: inline the accessors once the shared VECTOR.H replaces the TU-local copy, if it still matches.
- dropship.cpp Dropship_Screen 0xa68a0 (2026-11-28, Claude agent drop1; 4026 -> 5 bytes, NEAR_EQUAL, not a claim): kind-1 STEERING six named locals with real uses (house, cost, slot_count, candidate_count, candidate_index, cameo_index) before the first CrossDissolveEffect. FRAGILE / COUNT-SENSITIVE: they fix one instruction length at +0x16ec by local count; any change before that point can undo them (re-gauge with drop1/linegauge.py). Rework: re-test after the unsigned VectorClass index header check (C-item).
- ra2 UICmnds.cpp Type_Select_Command 0x2ec1b0 (2026-11-28, Claude agent own3): kind-1 STEERING `TechnoFilterFunc test = Is_Own_Active;` local function pointer keeps the test a call inside the inlined collectors (replaces the former `#pragma auto_inline(off)`, byte-identical). Rework: once the ra2/m85 uicmnds ownership is merged, re-test the plain call.
- techno.cpp TechnoClass::Fire_At 0x2bfe50 (2026-11-28, Claude agent fire1, MATCHED): kind-1 STEERING file-local `Fire_Flak_Length` with explicit parentheses `(Y*Y + Z*Z) + X*X` (1.001 sum order), and a dead first `velocity.Z = 0.0` store that sets VC6's first-field-reference order for the inlined Speed() sums. Three older Fire_At STEERING sites removed. Rework: re-test `vec.Length()` and plain zero stores if headers change.
