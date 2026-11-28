# Deferred to the end (user, 2026-11-21: "Maybe leave them as last ... if all the rest is done, it might give us clues")

These cases depend on the rest of their TU, or on context that is not available yet. Do not spend agent time on them until the surrounding code is complete; then revisit in this order.

| Item | Why deferred | Where the state is |
|---|---|---|
| startup WinMain 0x283970 (10070 bytes) | 1.001 `__LINE__` values show ~100 more source lines between TXT_DLL_INVALID (1904/1905) and TXT_VIDEO_ERROR (2048/2049); no reference has them. About 20 zero-code inline sites after Init_Keys are missing, ten Rect objects behave like named block locals, and the fileptr reload is merged once | w61_startup.claims.json, m85fix_startup.claims.json |
| queue Print_CRCs 0x221b90 (11223 bytes, hash order 1/16) + the faithful queue copy | matches by symbol-numbering coincidence; the faithful Wait_For_Players/Process_Receive_Packet break it | parked/queue_r6, KEY "VC6 symbol numbering" |
| HEADER_BATCH #14 (houstype CountryName) and #16 (ownertalk Port) | both faithful, but they cost Print_CRCs; apply together with the faithful queue copy | HEADER_BATCH.md |
| sidebar SelectClass::Action 0x2761a0 (3003 bytes, hash order) | one swapped reload pair once the geoconst includes are in; #14 happens to fix it | OPEN_PATTERNS sidebar note |
| planmgr Planning_Update 0x20bbf0 (4 bytes, hash order) | symgauge: 1 bit | w62_planmgr.claims.json |
| wonline Pick_Lobby, ownrdraw Trackbar_Proc | header-count / hash victims (dropped_w5c.json, dropped_trackbar.json) | dropped_*.json |
| palette SchemeNode names (0x1fae20 / 0x1faf00 swapped) | the faithful form is 2 bytes off (base/index order in the inlined Clear) | parked/palette_schemenode |
| the GAMECONST middle-5 initializers (sidebar, bounce, findpath) | not placeable by content; claim them by order once the TU is otherwise complete | TU_REATTRIBUTION.md |
| ownrdraw Focus_Next_Tab_Item 0x1d75d0 as `(HWND, bool)` | faithful (callers `setne dl`, callee `and esi,0xff`; 48/48 either way), but the changed mangled name costs Trackbar_Proc 0x1f30a0 (hash order, 8 offsets). wonline/mainopt/netdlg2 already call it with bool; apply together with the other hash-order fixes | header_backups/ownrdraw.cpp.before_focusbool_20261122 (the bool form is a 2-line change at lines 150/583) |
| wonline near misses confirmed hard by two independent agents (Claude + Codex batch 2, 53 variants): WOL_Game_Setup_Dialog_Proc 0x33d030 (57, tail placement), Create_Game_Channel 0x339df0 (3, operand order), Locale_Dialog_Proc 0x33f8e0 (4, slot), Handle_User_Leave 0x335d80 (2, edi/ebp), WOL_Buddy_Dialog_Proc 0x346940 (1 instr, inline cut), OnFind 0x350070 (1 inline site), OnUserList 0x34e040 (1 byte, lea operand order; near-miss body in parked/wol_v_wonline), Connect_To_Server 0x336a80 (inline gauge 5..12, parked/wol_v_wonline) | likely hash order (swaps) or a construct that is only visible once the TU is complete; revisit with symgauge when wonline is otherwise done | aistation_up/batch2_out/result/REPORT.md, agents/wol_*_wonline.claims.json "open", parked/wol_t_wonline |

Rule: when a TU reaches "everything else matched", re-run `tools/level2_symgauge.py` on its hash-order functions. A faithful complete TU should then either match, or show by its gauge offset how many declarations are still missing or extra.

## WinMain lead (2026-11-22): the "missing ~100 lines"
- 1.001 `__LINE__`: TXT_DLL_INVALID 1904, TXT_VIDEO_ERROR 2048, so 144 source lines lie between them.
- m85 1.006 startup.cpp: TXT_DLL_INVALID at line 743, TXT_VIDEO_ERROR at line 897, so 154 lines. The IPX "Network/DestNet" parser block (netbuf, strtok, BridgeNet, lines 809..) sits BETWEEN them.
- Our reconstruction: DLL_INVALID at 982 and VIDEO_ERROR at 1020 (38 lines), with the DestNet block BEFORE DLL_INVALID (lines 895-928). So the ~100 "missing" lines are most likely this IPX block and its neighbours, which in the 1.001 source come after the comctl32 DLL check, as in 1.006.
  - Check the 1.001 code ORDER of the DLL check against the DestNet parse.
  - If 1.001 also runs it before, the block may sit in a single-caller `static` helper that VC6 inlines. That keeps the code earlier while the source lines stay in WinMain's span, e.g. a helper defined in the middle.
- gibbo101 (YR 1.001 WinMain, attempts.csv 2026-11-21, 92.5% natural, forced match via dk8827's PR #306):
  - the frame slots match only when an inlined single-caller static `Read_Setup_Options` holds the netbuf/node/net/x/IPX locals beside RegisterClasses' inlined locals;
  - about 3 more named 4-byte locals in the surface and mouse setup.
  - Their WinMain source is not in the repository; only the notes are, in data/attempts.csv rows 2611/2804/3207/3944/3986 and docs/AGENTS.md:281. BUGS.md: the DestNet parser writes the node without a length check.
- 2026-11-22 WinMain agent result:
  - The IPX-order explanation is REFUTED: the 1.001 DestNet parse runs before the DLL check, and CRITICALLY_LOW is at 1830 < 1904.
  - A Read_Setup_Options static helper (modelled on EA RA1 STARTUP.CPP; INFERRED) gives 1.001's inline cuts and slots. WinMain went from 4609 to 689 bytes, and its frame is now equal (0xe0c).
  - Still open:
    - the fileptr reload around `new ZBuffer`;
    - one more named 4-byte local in the Parse block (fileptr..netptr);
    - about 106 source lines after the DLL check with no code (comments or disabled code).
  - Notes: agents/m85fix_startup_winmain.claims.json.
- 2026-11-22 WinMain round 2:
  - 486 bytes / 22 masked hunks (from 4609 / 219). The frame is EXACT: every ebp offset maps +0, size 0xe0c.
  - The only difference left is the order of `mov edi,[ebp-0x70c]` against `xor esi,esi` in the ZBuffer and ABuffer arms. This is a HASH-ORDER case: symgauge matches fully with N=59 dead externs before WinMain (or N=26/46/59 after `HANDLE AppMutex;`).
  - Meaning: the original startup.cpp has more declarations before WinMain than ours. Revisit when startup.cpp is otherwise complete. Do not add probes.
  - The ~106 extra source lines after the DLL check are still unexplained (no byte effect); the `#line` workaround stays.
  - Notes: agents/m85fix_startup_winmain2.claims.json; sweeps in W/build/level2/symlab/wm2_*.
- **2026-11-22 14:18 UTC: WinMain MATCHED and CLAIMED** (`_WinMain@16`, 10080 bytes, all bindings verified; startup.cpp 90/90).
  - The last bit was symbol-numbering order. The Read_Setup_Options prototype moved to the RA1 STARTUP.CPP position (before VideoBackBufferAllowed). This is weak evidence: 11 of 12 natural placements match. If a later edit flips it, re-run symgauge rather than tuning with dead declarations.
  - Also needed: sun.h CONFIG_FILE_NAME became "RA2.INI", and checker support for SEH (VC6 library functions from level2_library.json, the absolute __except_list = 0, and $L code labels inside claimed functions).
  - Still open, with no byte effect: the ~106 lines after the DLL check and ~950 lines before RegisterClasses (`#line` workaround).
- 2026-11-22 queue g3: Queue_AI_Multiplayer is MATCHED (TS order in Generate_Real_Timing_Event).
  - The faithful combined copy parked/queue_g2/queue_g2_faithful.cpp also matches Wait_For_Players (5307), Process_Receive_Packet (1117) and Draw_Sync_Bars (741), +7165 bytes in all. But Print_CRCs goes 8 bytes off (hash order). symgauge just before Print_CRCs matches at N = 17 and 47.
  - Draw_Sync_Bars needs an extern `RGBClass const` RedColor (255,0,0) at 0xa9e351, defined by the rgb.cpp initializer 0x233fb0: a header proposal for rgb.h. Applying it removes one queue initializer, so 6 `_$E` renames follow (map in notes.json).
  - Apply all of this together, as the Print_CRCs item, once the rest of queue.cpp is complete.

## A6 media round (gap agent, 2026-11-22): no match; proposed as deferred / matched-asm candidates
Counts unchanged: wave.cpp 31/31, voxel.cpp 21/21, unvqtblc.cpp 6/6; no P source edits. All four are stuck in BOTH our rounds (m85fix, fable11/13, m85fix11, g2, A6) and gibbo101's YR counterparts (attempts.csv up to 2026-11-20).
- wave Build_Wave_Shape 0x318470 (2368 bytes, same size, ~27 bytes): early `push esi` (&WaveStartMiddle, +0x431) and the start_right copy (+0x597) are scheduling-only. A6 varsearch (W/analysis/level2/parked/wave_g2/bws1.json, bws2.json, with results): statement orders of StartCoord/PositionCoord/EndCoord/Count/Vertices, distance2d_f position/type, dz position, ctor-form start vectors, a named WaveStartMiddle reference: all neutral or worse. Same two spots unsolved in gibbo YR Draw_NonMagnetic.
- voxel Init_Voxel_Matrices 0x30cc20 (3290 bytes, same size, 25 bytes): esi/edi swap of the zero/i*12 web against &LightDirectionVectors[i]. A6 (parked/voxel_g2/vox1.json): references at the loop top, `Matrix3D(true)`, `i < 256`, inline theta, indexed tilt_matrix operand: all identical code. gibbo: TibSun's all-reference loop has the right registers but a 3-byte-short `[esi+4]` load.
- wave Load 0x316d90 (349 bytes): gauge unchanged (needs +3 inline call sites after the placement new; m85fix11/fable11). gibbo's matched YR Load has the same 5 sites plus only the YR Type==3 branch; no natural +3 construct found. Would also emit 0x319290 (DVC<CellClass*> ctor, 93 bytes).
- unvqtblc UnVQ1_4x2_Table 0x300c60 (923 bytes): parked/unvqtblc_g2 (~32 masked hunks) and gibbo's 77.1% bank (constant 2 hoisted into ebp) remain best; not re-run.
- Notes: W/analysis/level2/agents/m85fix_{wave,voxel,unvqtblc}_g2.claims.json "open" (A6 entries). Suggest: no further Claude rounds; revisit with symgauge when the TUs are otherwise complete, then consider the matched-asm fallback.

## A6 media (2026-11-22): no match in 2 rounds (g2 and A6) plus gibbo101; deferred, a Codex candidate
- wave Build_Wave_Shape 0x318470: same size, about 27 bytes off at two spots.
  - At +0x431, the early `lea esi`/`push esi` of &WaveStartMiddle comes before the EndCoord stores.
  - At +0x597, the start_right copy is scheduled against the dz integer work.
  - Neutral variants: Count order, constructor-form vectors, a named Point2D&.
  - Worse: an early distance2d_f (34), dz moved earlier (76), EndCoord before PositionCoord (39).
  - gibbo101 has the same two spots unsolved in YR Draw_NonMagnetic.
  - Specs: W/analysis/level2/parked/wave_g2/bws1.json and bws2.json.
- voxel Init_Voxel_Matrices 0x30cc20: same size, 25 bytes off, with an esi/edi swap in the light-vector loop.
  - Reordering the quaternion identities scores 16 hunks, but it is wrong against 1.001.
  - gibbo101 has the mirror problem: the registers are right, but one load is 3 bytes short.
  - Spec: parked/voxel_g2/vox1.json.
- wave Load 0x316d90: 1.001 behaves as if there were 3 more inline call sites after the placement new, and no natural construct for that was found. gibbo101's YR Load is the same apart from the Type==3 branch. The Swizzle_Pointer form is unknown.
- unvqtblc UnVQ1_4x2_Table 0x300c60: the best is about 32 masked hunks (the parked g2 bodies); the gibbo101 bank reaches 77.1%.

## building Captured 0x443f0 (2026-11-22, three rounds: B6, B12, B16): deferred, a Codex candidate
- 1.001 is 3312 bytes. With 6 natural edits and 1 dead probe in the window between Power_On and the Distance condition, it has 0 byte differences. One natural inline unit in that window is still missing.
- Window rules (B16):
  - Any top-level inline call counts as a unit. Asserts and named locals do not.
  - The real Production_Status_Changed member is one unit lighter than the free stand-in.
  - Sites inside Adjust_House_Power break Power_On/Do_MISSION_DECONSTRUCTION.
- Notes: agents/m85fix_building_b16.claims.json, b12_building/parked_captured_gauge.json.

## house Random_Cell_In_Zone 0xebf50 and Where_To_Place_Building 0xef8c0 (B3 and B20, 2026-11-22): deferred
- Random_Cell_In_Zone, 1280 bytes with a 20-byte jump table, best 22 hunks. 1.001 stores the masked dir and reads the fraction back from memory; VC6 always forwards it from eax. About 450 helper variants were tried. Next: caller-side forms or the declaration of the caller's dir.
- Where_To_Place_Building, best 42 hunks. The static-table Cell temporaries are packed into one slot group in a different order. That order is neither by $T number nor by first use; it looks like an A3-type weight effect.
- Notes: agents/m85fix_house_b20.claims.json.

## ownrdraw _$E107 0x1d7450 (Control_Table Dictionary destructor) and _$E109 (B1, B21, 2026-11-22): deferred, a hash-order area
- The only difference: 1.001 calls ??_GWideWstring out of line inside the inlined ~WinData. 1.001 spends more inline budget in the ~Dictionary -> clear -> DNode -> ~WinData chain.
- Only probes match (asserts or dead calls in a TU-local specialization of ~Dictionary/clear). Trackbar_Proc 0x1f30a0 breaks or holds depending on the count.
- Untested lead: gibbo's HWND key type for the control table, a large edit that renames the claimed Dictionary symbols.
- _$E109 0x1d73b0 passes the forward rule once _$E107 matches.
- Notes: agents/b21_ownrdraw/parked_e107_gauges.json.

## End-phase hash-order package: header changes that only lose queue Print_CRCs 0x221b90 (2026-11-22)
Print_CRCs (and WinMain in one case) breaks with almost any header change that adds symbols, because of the hash or symbol-numbering coincidence. These changes each unlock real matches and wait for the moment Print_CRCs is solved as part of the package:
- **techtype.h, Unused2 as a class-typed member** `TechnoUnused2 { TechnoUnused2(void) : Value(0) {} }` (F7, INFERRED; evidence: the NoInit ctor 0x2cfc50 also zeroes +0x390). It unlocks the TechnoTypeClass main ctor 0x2cf0b0 (2976 bytes) and loses Print_CRCs (4 bytes).
  - Files: agents/f7_techtype/ (edits.json, header_patch.json, hdrcheck result).
- **script.h, the ScriptTypeClass::Detach override** (B31). It unlocks script 0x260150 and loses Print_CRCs plus WinMain (486 bytes).
  - Files: agents/b31_script/.

## team TeamClass::AI 0x2ad120 (B26, F1, F6, F10; 2026-11-22): deferred
- 10 hunks, the scratch-register rotation only. 1.001 has X=edx at the inlined MOVECELL, which needs +1 or +2 single-use temps between DESTROY_MEMBERS and MOVECELL. Nothing outside the window can move it, because From_Name resyncs the pointer.
- The remaining leads are type-level:
  - the `mov ecx,offset Map` this-load of Find_Nearby_Shroud as a rotation temp in 1.001 (the global Map declaration);
  - the Zone load as a single-use temp.
- Both need a header test with hdrcheck, so they belong with the hash-order package if they touch shared headers.
- Notes: agents/f10_team, f1_team, f6_team.
- **2026-11-22 (user): "If more functions work if we break print_crc, then the others might be correct and print_crc wrong."** Adopted as the working hypothesis.
  - The techtype.h change has independent evidence, so Print_CRCs' current match (11,232 bytes, only 4 bytes affected) is probably the coincidence.
  - F14 now looks for the faithful Print_CRCs source UNDER the techtype.h change. Everything is applied together once the combined hdrcheck loses nothing, so coverage never drops: dropping Print_CRCs now would trade 11.2 KB of matched code for 3 KB.
  - The script.h change also breaks WinMain (486 bytes) and stays a second stage.
- **2026-11-22 (user): "Test the 2 paths independently before making conclusions."** PATH A (F16): Print_CRCs is right, so find a techtype form that loses nothing. PATH B (F14): techtype.h is right, so re-match Print_CRCs under it. Each writes agents/<folder>/verdict.json. Decide only after comparing the two.
- **PATH B result (F14, 21:20 UTC): inconclusive, but a strong package.**
  - techtype.h + script.h + the faithful queue copy (parked/queue_g2/queue_g2_faithful.cpp: the 1.001 forms of Wait_For_Players, Process_Receive_Packet and Draw_Sync_Bars, extern SyncBarOutlineColor, the 1.006-only functions removed) together give 0 differences for Print_CRCs and WinMain.
  - It adds byte-identical TechnoTypeClass ctor (2976), ScriptTypeClass::Detach (144), Process_Receive_Packet (1120), Draw_Sync_Bars (752), and probably Wait_For_Players (5307).
  - hdrcheck snap11/f14_comb2: lost 7, all queue `_$E` renames (byte-identical under new names; the map is in agents/f14_printcrcs/notes.json).
  - techtype.h ALONE does not match naturally.
  - Mechanism: two adjacent spill reloads (i/housep) after fprintf at 4 loop bottoms, driven by a TU-wide declaration hash (period 64).
  - Files: agents/f14_printcrcs (combined_patch.json, edits.json, verdict.json).
  - Waiting for PATH A (F16) before deciding.
- **PATH A result (F16, 21:30 UTC): NOT SUPPORTED.**
  - No loss-free form exists in the current headers: any change in declaration count or layout breaks Print_CRCs, and no existing 4-byte type with an inline dword-storing ctor exists.
  - The ctor body form is refuted (the store lands at the wrong place).
  - So Print_CRCs' current match depends on our exact declaration set, i.e. on TU history.
- **COMPARISON (coordinator):**
  - A has no natural solution. B gives a consistent package of independently derived natural edits: techtype.h class member, script.h Detach, the 1.001 forms of three queue functions. Under the package Print_CRCs and WinMain are both 0, there are 4-5 new matches (about 10 KB), and hdrcheck only renames 7 queue `_$E` initializers.
  - RECOMMENDATION: apply the B package. Waiting for the user's go-ahead.
- **APPLIED 2026-11-22 21:33 UTC (user: "Use path B"):**
  - What went in: techtype.h (TechnoUnused2 class member), techtype.cpp, script.h (Detach override), script.cpp, and the faithful queue.cpp (24 edits). The 7 queue `_$E` initializers were renamed by move plan pathB_queue_E_renames. Backups are in W/analysis/level2/pathB_backup_20261122.
  - New claims: TechnoTypeClass ctor 0x2cf0b0, ScriptTypeClass::Detach 0x260150, Wait_For_Players 0x21c680, Draw_Sync_Bars 0x21e510. Print_CRCs and WinMain still match.
  - Process_Receive_Packet 0x21df30 is byte-identical but waits for its callee Extract_Compressed_Events (an unverified binding).
  - Full check: 17,592/17,592, 0 conflicts, 0 overlaps, coverage 90.07%.

## Parked changes that each cost one or a few existing claims (user question 2026-11-22; re-test after path B)
Several of these cost Print_CRCs, whose hash state changed with path B, so all are re-tested now (F21):
1. **HEADER_BATCH #16, ownertalk.h:** remove `unsigned short Port` (1.001's entry is 40 bytes). Unlocks 8 ownertalk functions (2406 bytes). Cost: Print_CRCs (before path B).
2. **HEADER_BATCH #25, voc.h:** the TS Sound_Effect inline (replaces mech's INFERRED Scold_Sound). Gains 0 (faithfulness only). Cost: Print_CRCs.
3. **HEADER_BATCH #23, abstype.h:** `int operator == (char const *) const`. Cost: Is_Type_Named 0x1cae60. Gain: a bullet near miss.
4. **HEADER_BATCH #20, abstract.h/object.h:** a Center_Cell class inline. Gains 0, 4 hash-order losses.
5. **HEADER_BATCH #26:** costs base Read_INI, uicmnds Is_Techno, unit Draw_It (the TU-local helpers stay).
6. **H2 parked velocity.h** (the body-form copy ctor, the converting ctor, the missile line). Missile goes 327->66 bytes. Cost: house AI_Build_Defense (4 bytes) + Print_CRCs (12), both two adjacent spill reloads swapped (the hash class).
7. **ownrdraw _$E107 for-loop candidate** (Codex batch 14). Unlocks _$E107 and then _$E109. Cost: 2 other functions (which ones: see batch14_out).
8. **F11:** the do/while(0) SetWindowLong form in all 11 dialog procs (only Locale_Dialog_Proc has it now). Cost: OnChannelJoin 4 bytes, no extra gain.
Not this pattern: #15 ownrdraw.h (lost 69), the B3 ddist.h form (lost about 20), #4 timer.h (needs a claim move).
More of the same pattern (added 2026-11-22 after the user's follow-up question):
9. **ownrdraw Focus_Next_Tab_Item (HWND, bool):** faithful, but costs Trackbar_Proc (hash order).
10. **HEADER_BATCH #14 houstype.h CountryName ctors:** unlocks the HouseTypeClass ctor 0xf85f0 (600 bytes), reportedly also fixes sidebar SelectClass::Action (3003 bytes), adds declarations; never fully hdrchecked.
11. **wonline unclaimed near-miss bodies OnFind/OnGameStart:** left out because they turn OnChannelJoin (5.3 KB) into an esi/edi swap.
12. **ownrdraw _$E116:** at the TU end instead of its faithful place, to protect Trackbar_Proc.
Recurring hash-order victims: Print_CRCs, Trackbar_Proc, OnChannelJoin, Pick_Lobby, Draw_Player_List, unit Draw_It, mapgen 0x183940, SelectClass::Action. F21 re-tests all 12 grouped by victim.

## F21 re-test of the parked changes on snap12, after path B (2026-11-22)
Each item was run alone (full level2_hdrcheck for header items, a TU rebuild for TU-local items), then all 64 subsets of the six header items over the victim TUs. Files: W/analysis/level2/agents/f21_retest (summary.json, patches/, sweep1_table.txt, log_*.txt).

| # | Change | Lost on snap12 | Gained | Verdict |
|---|---|---|---|---|
| 1 | #16 ownertalk.h Port removal | none | 6 ownertalk functions (the other 2 are already claimed) | **loss-free, ready** (01_ownertalk_port/) |
| 2 | #25 voc.h Sound_Effect | WinMain (486) | none | parked; Print_CRCs now holds |
| 3 | #23 abstype.h int operator== | Is_Type_Named (9, real code) | none | **closed: refuted**. Every 1.001 caller of 0x4107c0 and of 0x5cae60 tests `al`, so operator== returns bool |
| 4 | #20 Center_Cell inline | mapgen 0x183940, Trackbar_Proc, Print_CRCs, WinMain, Draw_Player_List | none | rejected |
| 5 | #26 Is_Techno inline | Trackbar_Proc, Print_CRCs, OnChannelJoin, uicmnds Is_Techno (4, real) | none | parked. With `bool flag` (p26b) the uicmnds copy matches and only the three hash-order victims remain |
| 6 | H2 velocity.h (rebased) | none alone | no claim (missile 327 -> 66 bytes) | parked: together with #16 it costs Print_CRCs (4) |
| 7 | ownrdraw ~WinData for-loop | ~WinData 0x1f7ff0 (31), DNode ??_G 0x1fa1a0 (55): real code, not hash order | _$E107, _$E109 | parked |
| 8 | F11 do/while(0) in all dialog procs | OnChannelJoin (4) | none | parked; holds only together with #25 or #20 |
| 9 | Focus_Next_Tab_Item (HWND, bool) | none (Trackbar_Proc holds) | faithful signature; the claim moves to `?Focus_Next_Tab_Item@@YI_NPAUHWND__@@_N@Z` | **loss-free, ready** (09_focus_bool/) |
| 10 | #14 houstype.h CountryName | AI_Build_Defense (4), Print_CRCs (8), WinMain (486) | HouseTypeClass ctor 0xf85f0 (608 bytes). SelectClass::Action 0x2761a0 is not fixed | parked; best subset #25+#14 loses only Print_CRCs (8) |
| 11 | wonline OnFind/OnGameStart bodies | none (OnChannelJoin holds) | none | neutral; apply when the bodies match |
| 12 | ODTooltip at its faithful place (_$E116) | Trackbar_Proc (8) | placement only | parked; no tested partner keeps Trackbar except #20 |

- Verified package: #16 + item 9, full hdrcheck f21_pkgA: 0 real losses (the one listed loss is the renamed Focus_Next_Tab_Item claim). Adding item 11 and the b21 ~WinData move (f21_pkgB) changes nothing.
- Victim classes: Print_CRCs, AI_Build_Defense, OnChannelJoin and Trackbar_Proc are swaps of two adjacent loads or stack slots; WinMain is one 486-byte numbering shift, the same under #25, #14 and #20, and #25+#14 or #25+#26 cancel it.
- Loss-free alone does not add up: #16 and H2 each lose nothing, and together they lose Print_CRCs. Run hdrcheck on the exact set that is applied.
- Trackbar_Proc under item 12 (symgauge, externs at ownrdraw.cpp line 148): 2 code variants; it matches for N = 7, 10, 11, 13-18, 27-46, 51-61, and not for 0-6.
- No faithful change to a victim's own TU was found for Print_CRCs, WinMain or Trackbar_Proc beyond the queue copy already applied in path B.

## face.h DirType operator>= conflict (P6, 2026-11-23)
fly Nearing_Target 0xbe390 and the COMDAT 0xbf7a0 match with the assignment-count body `{ int a = As_Int(); int b = rvalue.As_Int(); a = abs(a); b = abs(b); return(a >= b); }` (gibbo101 include/face.h @f522351dd2 as the lead), but hover Process 0xfb4c0 then also cuts the comparison (1750 bytes), and Zone_Reset, Print_CRCs and SelectClass::Action move by hash order. Every body that cuts in fly without gauge sites also cuts in hover (6 bodies gridded). Needs either a hover form that keeps its inline expansion under that body, or an end-phase hash-order package. Files: W/analysis/level2/agents/p6_fly/.

## houstype.h CountryName constructors (Codex batch 25, 2026-11-23)
HouseTypeClass::HouseTypeClass(char const *) 0xf85f0 (608 bytes) matches with two CountryName constructors in houstype.h (`CountryName() {}` and `explicit CountryName(char const *)`, meastes houstype.cpp as reference) plus edits_houstype_1.json, but the header change costs three hash-order victims: map Zone_Reset 0x14c060 (4 bytes), one sidebar claim and one startup claim (46 users checked; queue/Print_CRCs kept). Reverted (apply_b25_houstype_h). Same class as the face.h case above: solve together in the end-phase hash-order package. Files: W/analysis/level2/aistation_up/batch25_out/.
- UPDATE 2026-11-23 11:55 UTC: the face.h DirType conflict above is RESOLVED differently: Codex batch 26 matched fly Nearing_Target and 0xbf7a0 with a fly-local tolerance type and a stand-alone comparison in fly.cpp (no face.h change). The houstype.h case remains (Codex batch 27 victim rematch).
- UPDATE 2026-11-23 12:55 UTC: the houstype.h case above is RESOLVED by the victim rule: Codex batch 27 found forms of Zone_Reset, SelectClass::Action and WinMain that match under the new header; the package is applied and the HouseTypeClass constructor is claimed.
- 2026-11-23 count-type, end phase: queue.cpp SyncState ctor/dtor 0x21ad30/0x21ad80 (batch 38): matches only with a dummy local `enum { LayerCount }` (kind 2, AGENTS.md rule 9).
- 2026-11-24 count-type end phase (batch 48, several rounds without gain; Can_Repair_Bridge was later closed by the gibbo 8c1df26 port, batch 54): Spread_Units_Around_Cell 0x220ac0 (4), Do_MISSION_MISSILE 0x480f0 (10), Can_Repair_Bridge 0x166110 (3), Read_RMG_INI 0x176750 (97), Init_Voxel_Matrices 0x30cc20 (25), Projectile_Motion 0x190670 (51), Reposition_Sidebar 0x2770d0 (1), Send_Statistics_Packet 0x28e3f0 (1), Search_For_Tiberium_Weighted 0xcb740 (2), StripClass::Draw_It 0x274f90 (2). Revisit with kind-2 declarations or matched-asm at the final-exe stage.

## 2026-11-25 deep_p1 result (job 7ee55e10): the hash-order package is APPLIED
The techtype.h Unused2 member, the script.h Detach override and the faithful queue forms are already in the tree; Print_CRCs (batch 63 form: Frame read directly, house iterator at first traversal) and WinMain are exact under them (A = B; 5,336 claims in 97 TUs, 1,753,501 bytes). Decision A, no integration change. Print_CRCs still loses 4 bytes when real declarations are added to queue.h (removals are safe): after any change in this closure, rerun the A/B/C comparison (GUIDE V5). 300 of 814 Print_CRCs relocation targets are still open bindings (not byte differences). Report: batch_reports/deep_p1_REPORT.md.
- **SyncState ctor/dtor 0x21ad30/0x21ad80 (2026-11-25, batch 67):** byte-exact as separate out-of-line definitions (80/80, 32/32), but emitting them shifts 4 bytes in Print_CRCs (TU count effect, GUIDE V5/L22). End phase, together with the Print_CRCs count fix.
- **3 member stubs (2026-11-25, batch 76):** InfantryClass 0x1089d0 (ret 4) and UnitClass::Deploy/Undeploy 0x2f3270/0x2f3280 (ret) are exact as sources, but their two new member declarations in infantry.h/unit.h cost Print_CRCs and WinMain (count effect, GUIDE V5). Count-type, END PHASE: apply together with the Print_CRCs count fix. Sources and patches parked in W/analysis/level2/parked/b76_member_stubs.

## BulletClass::AI 0x5f380 (2026-11-28, Claude agent bullet1)
- Register-weight tie, non-count: every form reproducing 1.001's X/Y hold across __ftol (+0x1043) moves bridge_height from EDI to EBX in the ballistic step; count probes flat. Retry with a real-use source search once the full TU and headers are final.
- Header candidate: `TVelocity3D(BASECLASS const & planar, T z) : BASECLASS(planar), Z(z) {}` in velocity.h (gibbo has it) would remove the `double z` steering line; deferred because of V10 (count effect on Print_CRCs/WinMain).
