# Sources and credits (level-2 reconstruction of RA2 GAME.EXE 1.001)

Every external source used. Credit them in the final release, and notify their authors about our result afterwards, with the user's go-ahead (user decision 2026-11-22).

| Source | License | Used for | Commits used |
|---|---|---|---|
| mischa85/RedAlert2 (RA2 1.006 matching decompilation), https://github.com/mischa85/RedAlert2 | GPL-3.0-or-later (+ EA section 7) | the adopted m85 source tree (P/src/m85), adapted to 1.001 | 0132d21 (2026-11-18), 8f715e2 (2026-11-22) |
| gibbo101/ra2-decomp (Yuri's Revenge 1.001 matching decompilation), https://github.com/gibbo101/ra2-decomp | GPL-3.0-or-later src/include (+ EA section 7); MIT tooling/data | function bodies adopted with byte-identical proof (Goodie_Check, BulletClass::Detonate, many WOL dialogs and handlers, ...) | f891632 (2026-11-18), 719fcc7 (2026-11-22) |
| OpenRA | GPL-3.0 | logic aid only (user policy 2026-10-22), no code | — |
| OpenTS-Developers/TibSun, https://github.com/OpenTS-Developers/TibSun | GPL-3.0-or-later (+EA s.7) | TS 2.03 matching source; donor for inherited TS code | dbfbfbf (2026-11-22) |
| electronicarts/CnC_Red_Alert, https://github.com/electronicarts/CnC_Red_Alert | GPL-3.0 + EA terms | original names / class lineage (no code generation) | 0dc09bb (2026-11-22) |
| electronicarts/CnC_Renegade, https://github.com/electronicarts/CnC_Renegade | GPL-3.0 + EA terms | Westwood VC6 project flags, wwlib | 3e00c3a (2026-11-22) |
| Vinifera-Developers/TSpp, https://github.com/Vinifera-Developers/TSpp | GPL-3.0 | TS 2.03 layout cross-check | 99d5216 (2026-11-22) |

## Detail: mischa85 8f715e2 port (2026-11-22, refs_m85 agent)
- mischa85/RedAlert2 @8f715e2685: src/ownrdraw.cpp (the name Session.Suspended for the modal-box counter in Dialog_Message_Handler and Prompt_Dialog), include/wolapi.h (the name RequestPageWide for COM slot 62), include/session.h (the Suspended field comment), and src/wonline.cpp (the TU-local DynamicVectorClass<NodeNameType *>::Add specialisation device of Host_Game, used in a changed form in a parked near miss). Proposals in W/analysis/level2/parked/refs_mischa85_RedAlert2_ownrdraw and ..._wonline; no new function credit.

## Detail: gibbo101 719fcc7 port (2026-11-22, refs_gibbo agent)
- gibbo101/ra2-decomp @719fcc7c6e (new manifest rows since f891632): function bodies or source forms from src/map.cpp (MapClass::Zone_Span, Pick_Random_Tile_Variant, Reset_Subzone; the named from_cell/to_cell locals of Region_Threat), src/mapgen.cpp (MapRegionClass::Build_Corner_Ramp_SE; the stepwise score and declaration order of Generate_Starting_Points), src/building.cpp (the scaled As_Dir32 return of BuildingClass::Fire_Direction), src/display.cpp (DisplayClass::Set_Cursor_Pos), src/isotype.cpp (IsometricTileTypeClass::Preview_Tile), src/pcx.cpp (Read_PCX_File), src/wave.cpp (WaveClass::Draw_Sonic), src/srfcache.cpp (SurfaceCacheClass::Draw); leads only (not adopted) from src/techno.cpp Railgun_Beam_Damage + include/vectornorm.h, src/netshare.cpp LBSaveSelections, src/mapgen.cpp Grow_Water_Region; lessons from docs/AGENTS.md. Proposals in W/analysis/level2/parked/refs_gibbo101_ra2-decomp_<tu>.

## Detail: OpenTS TibSun dbfbfbf consulted (2026-11-22, refs_tibsun agent)
- OpenTS-Developers/TibSun @dbfbfbfaac40364ce7e1cd8fad7bcade5c6fb0d4 (read-only checkout W/analysis/references_gpl_20261118/opents_TibSun): code/map.cpp (Set_Map_Dimensions, Repair_Bridge, Collapse_Cliff, Reset_Subzone, Subzone_Span, Update_Cell_Subzones), code/house.cpp (AI, Random_Cell_In_Zone, Where_To_Place_Building, AI_Build_Defense, AI_Build_Wall), code/unit.cpp (Tunnel_AI, Plan_Route), code/building.cpp (Exit_Object, Do_MISSION_ATTACK), code/zone.hh and code/{inline,point,rect,coord,vector}.h compared with ours. Finding: the m85 tree is itself derived from this source (verbatim comments and forms), so TS mostly confirms forms we already compile. Its statement forms were tested as variants; none gave a new 1.001 match, so no TS code was adopted. Records in W/analysis/level2/parked/refs_tibsun_<tu>.
- 2026-11-22: EA CnC_Red_Alert CODE/STARTUP.CPP `Read_Setup_Options` was the model for RA2 1.001 WinMain's inlined setup helper. WinMain went from 4609 to 689 differing bytes (frame now equal).

## Additions after the 2026-11-22 incident (the full list above needs a restore)
- gibbo101/ra2-decomp @719fcc7: YR FUN_00639040 goto-fail form and abstract.h Is_Techno body -> planmgr Is_Planning_Selection_Valid 0x20d9c0 (A4, 2026-11-22).
- gibbo101/ra2-decomp @719fcc7: YR src/dropship.cpp Point2D screen_origin and Random_Pick forms -> Dropship_Screen 0xa68a0 layout (A7, 2026-11-22; near miss, 10 instructions left).
- gibbo101/ra2-decomp @719fcc7: YR src/mapgen.cpp Grow_Water_Region 0x5A08D0 body and the Random_Fraction form of Get_Angle_Score -> Grow_Water_Region 0x17eeb0 near miss (A10, 2026-11-22; parked at 4 hunks).
- gibbo101/ra2-decomp updated 719fcc7c6e -> 94adbad041 (2026-11-22 17:55 UTC): +5 matched YR rows in building, foot, ownrdraw, planmgr and queue; port agent running (agents/port_gibbo_94adbad).

## Detail: gibbo101 94adbad port (2026-11-22, port_gibbo_94adbad agent)
- gibbo101/ra2-decomp @94adbad041 (5 new manifest rows since 719fcc7c6e), consulted read-only; no code adopted, no new function credit:
  - src/building.cpp BuildingClass::Captured (YR 0x448260) -> our 0x443f0: its statement forms are code-identical to ours (near miss unchanged).
  - src/foot.cpp FootClass::Search_For_Tiberium_Weighted (YR 0x4DD2F0) -> our 0xcb740: its max/MAX forms are neutral or worse (still 2 bytes).
  - src/planmgr.cpp FUN_00637E00 (YR 0x637E00) -> our Planning_Execute 0x20c780: a named token local in the delete branch (43 -> 34 masked hunks), reported as a lead for Codex batch 12.
  - src/queue.cpp FUN_00650A90 (YR 0x650A90) -> our Fill_Sync_State 0x224770, already claimed.
  - src/ownrdraw.cpp OwnerDraw::NewEditHandler (YR 0x614B30) -> our New_Edit_Proc 0x1ea360, already claimed.
  - Records: W/analysis/level2/agents/port_gibbo_94adbad/<tu>/<tu>.claims.json.
- gibbo101/ra2-decomp @94adbad041: src/map.cpp, the non-inline HashTableClass<unsigned,SubzoneConnectionStruct>::Add_Object at the end of the TU, and the explicit TPoint2D<short> instantiation -> map 0x1689f0 and 0x167810 (B2, 2026-11-22).
- gibbo101/ra2-decomp @94adbad041: include/cast.h As_Foot (house AI 0xe37a0), the AI_Build_Wall while loop (0xf1850), the AI_Build_Defense if/else (near miss), the direct anim stores in Recalc_Attributes (cell 0x72140), the ~WinData named-node loop (ownrdraw) (B1/B3/B4, 2026-11-22).
- mischa85/RedAlert2 (1.006): the Run_Lobby_Session second-loop tail form -> wonline 0x337c50 (B5, 2026-11-22).
- gibbo101/ra2-decomp @94adbad041: src/planmgr.cpp, the Lead_At, Planning_Find_Node (Coord parameter, nested if) and delete-branch token forms -> Planning_Execute 0x20c780 (B7, 2026-11-22).
- gibbo101/ra2-decomp @94adbad041: the YR Sample form with the inner return(NULL) (as a TU-local specialization) and the named values quadrant/total/index/context -> house AI_Build_Defense 0xf0690 (B10, 2026-11-22).

## Authors informed (2026-11-22, with the user's go-ahead)
- gibbo101/ra2-decomp: issue #408, linking to https://github.com/RobinDigitalPro/ra2-decomp-help (pairs, snippets, leads, VC6 rules).
- mischa85/RedAlert2: issue #8, linking to the same repository (fixes, missing names, 1.006 leads, VC6 rules).
- Codex (gpt-6.2-astra) batch 13c: mapgen Grow_Water_Region 0x17eeb0 (on the gibbo YR body from A10) and Create_Region_From_Cell 0x16aef0; netshare Show_Slot_Controls 0x1c4330 and Hide_Slot_Controls 0x1c44c0 (2026-11-22).
- gibbo101/ra2-decomp @94adbad041: src/srfcache.cpp CachePCX (same 1046-byte size) -> it emits Dictionary<Wstring,SurfaceCacheEntry>::remove 0x282c30 as in 1.001 (B27, 2026-11-22); include/targetcell.h Target_Cell -> the atracker near miss.
- gibbo101/ra2-decomp @94adbad041: YR Shrapnel body and the flat velocity.h Set_Speed (as a TU-local specialization) -> bullet Shrapnel 0x62880 (F2 Fable, 2026-11-22).
- gibbo101/ra2-decomp @94adbad041: src/foot.cpp move-sound pick with a named random local -> FootClass::AI 0xc8bf0 (F6 Fable, 2026-11-22). Also the aircraft Fire_At forms, flat TVelocity3D ctor and copy-init -> AircraftClass::Fire_At 0x15790 (B35).
- gibbo101/ra2-decomp updated 94adbad041 -> 94fbaceabc (2026-11-22 21:18 UTC): +6 matched YR rows (ending.cpp new, ipxmgr, ownrdraw, unit, vanim); port agent started (agents/port_gibbo_94fbace).
- gibbo101/ra2-decomp @94adbad041: src/srfcache.cpp YR DrawTrans 0x6BA5C0 indexed-loop body (YR NULL early returns removed) -> srfcache DrawTrans 0x282580 (F15 Fable, 2026-11-22).
- Codex (gpt-6.2-astra) batch 14: building Captured 0x443f0 (a TU-local Record_Building_Capture helper, INFERRED, plus the B12/B16 natural edits); ship While_Moving and Build_Wave_Shape near-miss working copies (2026-11-22).
- gibbo101/ra2-decomp @94fbaceabc (port_gibbo_94fbace, 2026-11-22): src/vanim.cpp YR VoxelAnimClass ctor 0x7493B0 (one Vector3 filled by Set in both branches) -> vanim ctor 0x3013c0; src/ownrdraw.cpp SysTabHandler 0x6137D0 structure plus the unsigned-bitfield ODColorBits magenta key -> ownrdraw Tab_Proc 0x1e9010; src/ending.cpp GDI_Ending/Nod_Ending -> new TU src/ra2/Ending.cpp 0x4b5520/0x4b5530 (whole file adopted with its GPL/EA header).
- gibbo101/ra2-decomp @bd6bc66711 (port agent P3, 2026-11-22): src/techno.cpp YR TechnoClass::Draw_Health_Bar 0x006F64A0 forms (unnamed `dim / 2`, `bar` point, pip points as Draw_Shape argument temporaries, `adjust` points) -> techno Draw_Health_Bar 0x2b9570 (proposal agents/p3_techno); include/tube.h Get_Exit/Get_Count and tools/flipsweep.py, tools/inlinebudget.py read as leads only (not adopted).
- gibbo101/ra2-decomp @bd6bc66711 (tool review T1, 2026-11-22): tools/flipsweep.py with the tools/inlineprobe.py helpers (GPL-3.0-or-later) -> adapted as W/tools/level2_flipsweep.py (our VC6 kit and coffmatch; review in COMMUNITY_TOOLS_REVIEW.md).
- gibbo101/ra2-decomp @bd6bc66711 (tool review T1, 2026-11-22): tools/inlinebudget.py (GPL-3.0-or-later) -> adapted as W/tools/level2_inlinebudget.py; first use located B21's ownrdraw _$E107 0x1d7450 decision and measured its slack (2 inline sites).
- gibbo101/ra2-decomp @bd6bc66711 (tool review T2, 2026-11-22; tools/ are MIT, exelink ported from r-melvin/gagarin, MIT). The hashed reference copies are in W/tools/community/gibbo101_ra2-decomp@bd6bc66711 (PROVENANCE.md, SHA256SUMS). Four files were adapted:
  - tools/exelink/crt_ident.py, with the IAT check from tools/libmatch.py, became W/tools/level2_libident.py;
  - tools/header_inputs.py became W/tools/level2_hdrimpact.py;
  - tools/modules.py file_anchors() became W/tools/level2_fileanchors.py;
  - tools/headercheck.py became W/tools/level2_classcheck.py.
  The review is in COMMUNITY_TOOLS_REVIEW.md, section T2.
- Licence correction (2026-11-22, from review T2): gibbo101/ra2-decomp tools/ (flipsweep.py, inlineprobe.py, inlinebudget.py and the other tools adopted by T1/T2) are MIT-licensed (Copyright (c) 2026 ra2-decomp contributors; upstream LICENSE: MIT covers everything outside src/ and include/), not GPL-3.0-or-later as written in the two T1 lines above. The MIT notice is kept in the adapted tools level2_flipsweep.py and level2_inlinebudget.py.
- gibbo101/ra2-decomp @184ff3d2d6 (port agent P4, 2026-11-23; GPL-3.0-or-later game source): src/wdtsel.cpp + include/wdtnet.h forms (HoveredTerritoryID >= 0 test with an unsigned member, Handle_Click without the auto_inline pragma, Hover_At inline removed) -> our wdtsel.cpp/wdtnet.h (apply_p4_wdtsel); src/hover.cpp Draw_Matrix plain temporary -> our hover.cpp 0xfb0f0; src/ownrdraw.cpp ComboDropWindowHandler version facts as leads for the ownrdraw procs (agents/p4_ownrdraw_leads.md); data/attempts.csv and docs/rounds/2026-11.md read as notes.
- gibbo101/ra2-decomp @721d81e44f (port agent P5, 2026-11-23; GPL-3.0-or-later game source): src/infantry.cpp YR InfantryClass::Per_Cell_Process 0x00519630 forms (named ttype, train after the announcement, the hut as its own BuildingClass pointer) -> infantry 0xfffa0; src/team.cpp two-call TMission_GOTO_SHROUD (YR TeamClass::AI 0x006E9140) -> team AI 0x2ad120; src/map.cpp YR MapClass::Repair_Bridge 0x00573540 body -> map 0x152ef0 (proposals agents/p5_infantry, p5_team, p5_map); src/wdtsel.cpp Selection constructor read as a lead only.
- meastes/redalert2-decomp (https://github.com/meastes/redalert2-decomp, GPL-3.0-or-later), cloned read-only 2026-11-23 at 613e28e4e0: matching decompilation of base Red Alert 2 1.006 with VC6 (93.5% of .text, 17,889 of 17,985 functions). Found through gibbo101's credits. Reference for porting to our 1.001 (and later for our 1.006 step); nothing adopted yet.
- gibbo101/ra2-decomp @721d81e44f (port agent M2, 2026-11-23, GPL-3.0-or-later): src/cell.cpp CellClass::Reduce_Tiberium forms (int reducer = 0 first with a single return; Adjacent_Cell without the (Cell) cast) -> our cell.cpp 0x759b0; planmgr planning-event forms (Owner_Is_Mission, one-expression Planning_Current_Order, file-scope frame declarations) -> our planmgr.cpp Planning_Draw_Techno near miss.
- meastes/redalert2-decomp @613e28e4e0 (port agents M1/M3, 2026-11-23, GPL-3.0-or-later): src/recovered/unittype.cpp (UnitTypeClass::Read_INI block-scoped turret/weapon pairs) -> our unittype 0x2ff700; src/recovered/vanim.cpp (VoxelAnimClass::AI Adjacent_Cell form) -> vanim 0x301f40; src/recovered/ahandle2.cpp (Append_Radius_Bins with Object_Cell) -> atracker 0x128a0; src/recovered/uicmnds2.cpp (StringTable::LoadFile Open_File/Close_File helpers) -> strtable 0x2edad0; src/recovered/init.cpp (Allocate_Surfaces Memory_Flag, near miss) -> init 0x118a70; ionblast AI form -> ionblast 0x120880 (source only, claim pending I3).
- r-melvin/gagarin (https://github.com/r-melvin/gagarin, GPL-3.0, archived), cloned read-only 2026-11-23 at ebbd7d6b0c: matching decompilation of YR gamemd.exe 1.001 (MSVC 6.0), 52% of functions. Reference only; nothing adopted yet.
- Given back 2026-11-23: gibbo101 update 2 and a first package for meastes (8 functions), see WORK_QUEUE "HELP PACKAGES".
- 2026-11-23 gibbo101 tools/exelink @308c005 (MIT, after r-melvin/gagarin): the stub-link and mapcheck design and coffgen/mapcheck code, adapted by Codex as level2_exelink (P9 link check, LINKCHECK_20261123.md). The forcing-audit idea (W/tools/level2_forcing_audit.py, our own code) comes from their PLAN.
- 2026-11-24 gibbo101/ra2-decomp @232414dc36: bodies ported with byte-identical proof on RA2 1.001 (batch 44g): CellClass::Place_Veins, MechLocomotionClass::Movement_AI, SurfaceCacheClass::CacheBMP, UnVQ1_4x2_Table, IonBlastClass::One_Time, Tactical::Draw_Pixel_Effects (their Draw_Sparkles). Earlier the same day: their Compute_Zone_Connections form informed batch 43.
- 2026-11-24 YuriPlanet/vera20k (VERA20K, Rust YR reimplementation, GPLv3 + LEGAL.md additional terms): reference only (docs, Ghidra notes, native oracle), no code adopted; https://github.com/YuriPlanet/vera20k @b3f9cb2.
- 2026-11-24 omarelarab/ra2-engine (0BSD, C++17 RA2/YR reimplementation): reference only (docs/re behaviour notes, docs/gap); https://github.com/omarelarab/ra2-engine @a8cfdcc.
- 2026-11-24 gibbo101/ra2-decomp @8c1df26fac: MapClass::Can_Repair_Bridge and Quaternion::Make_Closest ported with byte-identical proof on RA2 1.001 (batch 54).

## Detail: gibbo101 ed881f6 port (2026-11-25, Codex batch 60g)
- gibbo101/ra2-decomp @ed881f68a4: source forms of MapClass::Subzone_Span (src/map.cpp) and OwnerDraw::StaticHandler (src/ownrdraw.cpp; our OwnerDraw::Static_Proc) adopted with byte-identical proof on our 1.001; ParticleClass::Spark_Behavior_AI (src/particle.cpp) adopted as a near miss (3 bytes left).
- gibbo101/ra2-decomp @1ed93a9026 (2026-11-25, batch 64g): the form of Join_WOL_Lobby adopted for our Run_Online_Menu (near miss 223 -> 25); BUGS.md note on Spread_Units_Around_Cell kept as an original-behaviour note.

## Claude agent ports, 2026-11-28 (gibbo101/ra2-decomp @cb43f59, read-only; GPL-3.0-or-later, upstream headers kept in the TUs)
- src/xsurface.cpp XSurface::Plot_Line diagonal branch (29081fa) -> Plot_Line 0x35f840 (matched, agent plot1).
- src/tactical.cpp Tactical::Draw_Tiles(Cell, Rect) (cb43f59) -> 0x29dba0 (matched, agent tiles1).
- src/building.cpp FUN_0043B150 + include/cast.h As_Techno + file-local Is_Cell + the members' Coord(a - b).Length() distance form -> Psychic_Detector_Covers_Techno 0x38570 (matched, agent own2).
- src/multiplayer.cpp Fill_Game_Mode_List 0x5D6000 / FUN_005D6130 accessor form -> Fill_Game_Mode_Combo 0x1b3bc0 / Fill_Game_Mode_List 0x1b3cf0 (matched, agent own1; found afterwards, the accessor form agrees).
- src/building.cpp Exit_Object (29081fa) -> 0x402b0 (lead, 1291 -> 10 bytes, agent exit1); src/bullet.cpp BulletClass::AI + Ballistic_Move (cb43f59) -> 0x5f380 (lead, 4760 -> 1939, agent bullet1); src/dropship.cpp Dropship_Screen (lead, no gain from the twin; 4026 -> 5 by own work, agent drop1).
- Fire_At 0x2bfe50 (matched, agent fire1): gibbo101 src/techno.cpp:3530 (YR twin) and meastes/redalert2-decomp src/techno.cpp:4577 @d2a9ed2 (RA2 1.006 distance, flak and muzzle forms).
- meastes/redalert2-decomp @8ec3839cd3 (GPL-3.0-or-later): FootClass::Search_For_Tiberium_Weighted with the include/ddist.h accessors (lane F113) and WalkLocomotionClass::Movement_AI (lane F116), ported to 1.001 0xcb740 / 0x312de0 byte-identically (Claude agent mst2, 2026-11-28). Their earlier Search_For_Tiberium_Weighted text was based on our public repo.
- gibbo101/ra2-decomp @cb43f59: palette.cpp Set_Mode/Replace/~SchemeLibrary/caller and source order -> Set_Scheme_Table_Theater 0x1fb330, SchemeLibrary::Set_Mode 0x1fc6b0; matrix3d.h/vector4.h implicit copy assignment -> Init_Voxel_Matrices 0x30cc20 (Claude agent gib4); astar.h RegularOpenNode comparisons + astar.cpp Find_Path_Regular 0x27370, partsys.cpp Smoke_AI 0x203750 (Claude agent gib3).
