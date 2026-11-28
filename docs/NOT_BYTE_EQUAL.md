# Functions not yet byte-equal (2026-11-27)

All are functionally equal (near-equal). Size = function bytes; diff = latest known differing bytes.

## Game code (gameplay)

| # | Function | RVA | Size | Diff |
|---:|---|---|---:|---:|
| 1 | Dropship_Screen | 0xa68a0 | 10797 | 5 |
| 2 | BuildingClass::Exit_Object | 0x402b0 | 6515 | 10 |
| 3 | BulletClass::AI | 0x5f380 | 6382 | 1939 |
| 4 | TechnoClass::Fire_At | 0x2bfe50 | 6002 | 2869 |
| 5 | MapClass::Set_Map_Dimensions | 0x145970 | 5335 | 590 |
| 6 | WalkLocomotionClass::Movement_AI | 0x312de0 | 4967 | 858 |
| 7 | SuperClass::Place | 0x292ef0 | 4332 | 0 |
| 8 | MapRegionClass::Split_Region | 0x16bd10 | 4012 | 1354 |
| 9 | Spread_Units_Around_Cell | 0x220ac0 | 3048 | 4 |
| 10 | BuildingClass::Do_MISSION_MISSILE | 0x480f0 | 3036 | 10 |
| 11 | AStarClass::Find_Path_Regular | 0x27370 | 2506 | 426 |
| 12 | MapGeneratorClass::Read_RMG_INI | 0x176750 | 1897 | 97 |
| 13 | FootClass::Search_For_Tiberium_Weighted | 0xcb740 | 1467 | 2 |
| 14 | Extract_Compressed_Events | 0x21fa40 | 1455 | 580 |
| 15 | HouseClass::Random_Cell_In_Zone | 0xebf50 | 1276 | 664 |
| 16 | ParticleSystemClass::Smoke_AI | 0x203750 | 1240 | 625 |
| 17 | Psychic_Detector_Covers_Techno | 0x38570 | 865 | ? |
| 20 | SyncState::SyncState | 0x21ad30 | 69 | 0 |
| 21 | SyncState::~SyncState | 0x21ad80 | 18 | 0 |

## Other code (UI, network, render, platform), largest first

| # | Function | RVA | Domain | Size | Diff |
|---:|---|---|---|---:|---:|
| 1 | OwnerDraw::List_Proc | 0x1ee640 | UI/network/platform | 14526 | 11812 |
| 2 | OwnerDraw::Control_Proc | 0x1e6550 | UI/network/platform | 7269 | 3634 |
| 3 | IsometricTileTypeClass::Draw_Tile | 0x12a490 | render | 6967 | 3483 |
| 4 | OwnerDraw::Combo_Proc | 0x1ecc60 | UI/network/platform | 6618 | ? |
| 5 | DSurface::Draw_Depth_Antialiased_Line | 0xac360 | render | 6064 | 4421 |
| 6 | Net2DecodeGameopt | 0x1beaf0 | UI/network/platform | 5591 | 509 |
| 7 | Send_Statistics_Packet | 0x28e3f0 | UI/network/platform | 5051 | 1 |
| 8 | LoadProgressManager::Draw | 0x133e50 | UI/network/platform | 3848 | 1665 |
| 9 | Init_Voxel_Matrices | 0x30cc20 | render | 3290 | 25 |
| 10 | Tactical::Render | 0x299be0 | render | 3288 | 1860 |
| 11 | SidebarClass::StripClass::Draw_It | 0x274f90 | UI/network/platform | 2760 | 2 |
| 12 | Run_Online_Menu | 0x3474e0 | UI/network/platform | 2539 | 25 |
| 13 | Create_Game_Channel | 0x339df0 | UI/network/platform | 2181 | 3 |
| 14 | Main_Options_Dialog_Proc | 0x13fc70 | UI/network/platform | 1996 | 9 |
| 15 | CChatEventSink::OnUserList | 0x34e040 | UI/network/platform | 1989 | 1345 |
| 16 | OwnerDraw::Adjust_Control_Position | 0x1e1760 | UI/network/platform | 1919 | 1 |
| 17 | SidebarClass::StripClass::Recalc | 0x275a60 | UI/network/platform | 1762 | 184 |
| 18 | WDT_Write_Map_Ini | 0x31f440 | UI/network/platform | 1652 | 1 |
| 19 | WorldDominationTour::Selection::Show_State | 0x323340 | UI/network/platform | 1531 | 183 |
| 20 | XSurface::Draw_Ellipse | 0x360000 | render | 1478 | 1198 |
| 21 | Read_Text_File | 0x2ee430 | UI/network/platform | 1469 | 6 |
| 22 | Standard_Dialog_Proc | 0x1f77c0 | UI/network/platform | 1450 | 707 |
| 23 | SidebarClass::Reposition_Sidebar | 0x2770d0 | UI/network/platform | 1314 | 1 |
| 24 | Load_Lobby_Options | 0x1c5350 | UI/network/platform | 1270 | 441 |
| 25 | WorldDominationTour::Selection::Selection | 0x322120 | UI/network/platform | 1072 | 450 |
| 26 | ProgressScreenClass::Draw_Player | 0x2177c0 | UI/network/platform | 1048 | 132 |
| 27 | SurfaceCacheClass::CachePCX | 0x281d00 | render | 1046 | 9 |
| 28 | OwnerDraw::Init_Control_Animation | 0x1e04d0 | UI/network/platform | 1021 | 687 |
| 29 | Tactical::Draw_Radial_Indicators | 0x2a1a70 | render | 893 | 250 |
| 31 | Combatant_Select_Command | 0x2ebb60 | UI/network/platform | 718 | 521 |
| 32 | Type_Select_Command | 0x2ec1b0 | UI/network/platform | 669 | 638 |
| 33 | Veterancy_Nav_Command | 0x2eccf0 | UI/network/platform | 618 | 313 |
| 34 | Health_Nav_Command | 0x2ec9c0 | UI/network/platform | 608 | 568 |
| 35 | SchemeLibrary::Set_Mode | 0x1fc6b0 | render | 511 | 104 |
| 37 | Set_Scheme_Table_Theater | 0x1fb330 | render | 504 | 488 |
| 38 | Fill_Color_List | 0xd18c0 | UI/network/platform | 437 | 128 |

Plus, parked for the end phase (code ready or count effect): InfantryClass 0x1089d0, UnitClass::Deploy/Undeploy 0x2f3270/0x2f3280, SyncState ctor/dtor 0x21ad30/0x21ad80 (in the list above), and SuperClass::Place 0x292ef0 (0 bytes, claim waits for per-TU constant bindings).
