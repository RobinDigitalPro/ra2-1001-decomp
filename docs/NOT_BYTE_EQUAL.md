# Functions not yet byte-equal (2026-11-27)

All are functionally equal (near-equal). Size = function bytes; diff = latest known differing bytes.

## Game code (gameplay)

| # | Function | RVA | Size | Diff |
|---:|---|---|---:|---:|
| 1 | Dropship_Screen | 0xa68a0 | 10797 | 2 |
| 2 | BuildingClass::Exit_Object | 0x402b0 | 6515 | 10 |
| 3 | BulletClass::AI | 0x5f380 | 6382 | 1939 |
| 5 | MapClass::Set_Map_Dimensions | 0x145970 | 5335 | 590 |
| 8 | MapRegionClass::Split_Region | 0x16bd10 | 4012 | 1354 |
| 9 | Spread_Units_Around_Cell | 0x220ac0 | 3048 | 4 |
| 10 | BuildingClass::Do_MISSION_MISSILE | 0x480f0 | 3036 | 10 |
| 12 | MapGeneratorClass::Read_RMG_INI | 0x176750 | 1897 | 97 |
| 14 | Extract_Compressed_Events | 0x21fa40 | 1455 | 6 |
| 15 | HouseClass::Random_Cell_In_Zone | 0xebf50 | 1276 | 664 |
| 20 | SyncState::SyncState | 0x21ad30 | 69 | 0 |
| 21 | SyncState::~SyncState | 0x21ad80 | 18 | 0 |

## Other code (UI, network, render, platform), largest first

| # | Function | RVA | Domain | Size | Diff |
|---:|---|---|---|---:|---:|
| 1 | OwnerDraw::List_Proc | 0x1ee640 | UI/network/platform | 14526 | 11812 |
| 2 | OwnerDraw::Control_Proc | 0x1e6550 | UI/network/platform | 7269 | 3634 |
| 3 | IsometricTileTypeClass::Draw_Tile | 0x12a490 | render | 6967 | 3483 |
| 4 | OwnerDraw::Combo_Proc | 0x1ecc60 | UI/network/platform | 6618 | ? |
| 5 | DSurface::Draw_Depth_Antialiased_Line | 0xac360 | render | 6064 | 6 |
| 6 | Net2DecodeGameopt | 0x1beaf0 | UI/network/platform | 5591 | 509 |
| 7 | Send_Statistics_Packet | 0x28e3f0 | UI/network/platform | 5051 | 2 (kind-3 read removed) |
| 8 | LoadProgressManager::Draw | 0x133e50 | UI/network/platform | 3848 | 1238 |
| 10 | Tactical::Render | 0x299be0 | render | 3288 | 1860 |
| 12 | Run_Online_Menu | 0x3474e0 | UI/network/platform | 2539 | 25 |
| 13 | Create_Game_Channel | 0x339df0 | UI/network/platform | 2181 | 3 |
| 15 | CChatEventSink::OnUserList | 0x34e040 | UI/network/platform | 1989 | 1345 |
| 16 | OwnerDraw::Adjust_Control_Position | 0x1e1760 | UI/network/platform | 1919 | 1 |
| 17 | SidebarClass::StripClass::Recalc | 0x275a60 | UI/network/platform | 1762 | 3 |
| 18 | WDT_Write_Map_Ini | 0x31f440 | UI/network/platform | 1652 | 0 (bindings open) |
| 19 | WorldDominationTour::Selection::Show_State | 0x323340 | UI/network/platform | 1531 | 12 |
| 20 | XSurface::Draw_Ellipse | 0x360000 | render | 1478 | 1198 |
| 21 | Read_Text_File | 0x2ee430 | UI/network/platform | 1469 | 6 |
| 22 | Standard_Dialog_Proc | 0x1f77c0 | UI/network/platform | 1450 | 707 |
| 23 | SidebarClass::Reposition_Sidebar | 0x2770d0 | UI/network/platform | 1314 | 1 |
| 26 | ProgressScreenClass::Draw_Player | 0x2177c0 | UI/network/platform | 1048 | 132 |
| 27 | SurfaceCacheClass::CachePCX | 0x281d00 | render | 1046 | 9 |
| 28 | OwnerDraw::Init_Control_Animation | 0x1e04d0 | UI/network/platform | 1021 | 687 |
| 29 | Tactical::Draw_Radial_Indicators | 0x2a1a70 | render | 893 | 250 |

Plus, parked for the end phase (code ready or count effect): InfantryClass 0x1089d0, UnitClass::Deploy/Undeploy 0x2f3270/0x2f3280, SyncState ctor/dtor 0x21ad30/0x21ad80 (in the list above), and SuperClass::Place 0x292ef0 (0 bytes, claim waits for per-TU constant bindings).
