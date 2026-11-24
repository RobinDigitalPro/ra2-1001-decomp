# 0x18e7a0 ?Movement_AI@MechLocomotionClass@@AAEX_N@Z (src/m85/src/mech.cpp)

Origin: history: w333_x.claims.json. Community source: gibbo232414_mech.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -1,6 +1,4 @@
-void MechLocomotionClass::Movement_AI(bool continue_moving) // RA2: defined here, between Force_Immediate_Destination and Mark_Head_To
+void MechLocomotionClass::Movement_AI(bool continue_moving)
 {
-	Cell old_cell;
-	Coord head_coord;
 	if (LinkedTo->PrimaryFacing.Is_Rotating()) {
 		return;
@@ -10,8 +8,4 @@
 		if (DestinationCoord != COORD_NONE) {
 
-			/*
-			 * A destination exists. If there is no current path then try to build
-			 * one. If a path already exists, fall through to dispatch the next leg.
-			 */
 			if (LinkedTo->Path[0] == FACING_NONE) {
 
@@ -25,48 +19,47 @@
 				if (!LinkedTo->Basic_Path(DestinationCoord.As_Cell(), 0, 0)) {
 
-					if (LinkedTo->Is_In_Same_Zone(DestinationCoord)) {
-
-						int dist = LinkedTo->Distance(DestinationCoord); // level-2 1.001: lead only, the member form is closer to the 1.001 inlining than the free Distance
-
-						if (dist < (int)Rule->CloseEnoughDistance && !LinkedTo->IsTethered) {
-							LinkedTo->Assign_Destination(NULL);
+					if (!LinkedTo->Is_In_Same_Zone(DestinationCoord)) {
+						LinkedTo->Assign_Destination(NULL);
+						return;
+					}
+
+					int dist = Distance(LinkedTo->Center_Coord(), DestinationCoord);
+
+					if (dist < (int)Rule->CloseEnoughDistance && !LinkedTo->IsTethered) {
+						LinkedTo->Assign_Destination(NULL);
+					} else {
+
+						if (LinkedTo->TryTryAgain != 0) {
+							LinkedTo->TryTryAgain--;
 						} else {
 
-							if (LinkedTo->TryTryAgain != 0) {
-								LinkedTo->TryTryAgain--;
-							} else {
-
-								if (LinkedTo->IsNewNavCom) {
-									Sound_Effect(Rule->ScoldSound);
-								}
-								LinkedTo->IsNewNavCom = false;
-
-								Cell dest_cell = DestinationCoord;
+							if (LinkedTo->IsNewNavCom) {
+								Sound_Effect(Rule->ScoldSound);
+							}
+							LinkedTo->IsNewNavCom = false;
+
+							Cell dest_cell = DestinationCoord;
+							if (LinkedTo->IsLocked) {
+								Cell src_cell = LinkedTo->Destination_Coord().As_Cell();
+								if (!Map.Is_Same_Cell_Zone(src_cell, dest_cell, LinkedTo->TClass->MZone, LinkedTo->Is_Moving_Onto_Bridge(), Map[dest_cell].IsUnderBridge, LinkedTo->Is_Allowed_To_Leave_Map())) {
+									LinkedTo->Assign_Destination(NULL);
+								}
+							}
+
+							if (LinkedTo->TarCom != NULL) {
+								Cell tar_cell = LinkedTo->TarCom->Destination_Coord(LinkedTo).As_Cell();
 								if (LinkedTo->IsLocked) {
-									Cell src_cell = LinkedTo->Destination_Coord().As_Cell();
-									if (!Map.Is_Same_Cell_Zone(src_cell, dest_cell, LinkedTo->TClass->MZone, LinkedTo->Is_Moving_Onto_Bridge(), Map[dest_cell].IsUnderBridge, LinkedTo->Is_Allowed_To_Leave_Map())) {
-										LinkedTo->Assign_Destination(NULL);
+									Cell src_cell = LinkedTo->Destination_Coord(LinkedTo).As_Cell();
+									if (!Map.Is_Same_Cell_Zone(src_cell, tar_cell, LinkedTo->TClass->MZone, LinkedTo->Is_Moving_Onto_Bridge(LinkedTo), Map[tar_cell].IsUnderBridge, LinkedTo->Is_Allowed_To_Leave_Map())) {
+										LinkedTo->Assign_Target(NULL);
 									}
 								}
-
-								if (LinkedTo->TarCom != NULL) {
-									Cell tar_cell = LinkedTo->TarCom->Destination_Coord(LinkedTo).As_Cell(); // level-2 1.001: the unit is passed as the docker here
-									if (LinkedTo->IsLocked) {
-										Cell src_cell = LinkedTo->Destination_Coord(LinkedTo).As_Cell();
-										if (!Map.Is_Same_Cell_Zone(src_cell, tar_cell, LinkedTo->TClass->MZone, LinkedTo->Is_Moving_Onto_Bridge(LinkedTo), Map[tar_cell].IsUnderBridge, LinkedTo->Is_Allowed_To_Leave_Map())) {
-											LinkedTo->Assign_Target(NULL);
-										}
-									}
-								}
-							}
-						}
-
-						LinkedTo->Set_Speed(0);
-						Stop_Moving();
-						IsMoving = false;
-						return;
-					}
-
-					LinkedTo->Assign_Destination(NULL);
+							}
+						}
+					}
+
+					LinkedTo->Set_Speed(0);
+					Stop_Moving();
+					IsMoving = false;
 					return;
 				}
@@ -75,8 +68,4 @@
 			}
 
-			/*
-			 * Dispatch the next leg of the path. A path entry of FACING_COUNT is
-			 * a special tunnel transition.
-			 */
 			FacingType dir = LinkedTo->Path[0];
 			if (dir == FACING_COUNT) {
@@ -89,18 +78,18 @@
 					TubeClass * tubeptr = Tubes[tube];
 
-					HeadToCoord = Coord(Cell(tubeptr->Exit), 0);
-
-					memcpy(&LinkedTo->Path[0], &LinkedTo->Path[1], 92);
-					LinkedTo->Path[23] = FACING_NONE;
+					HeadToCoord = Coord(Cell(tubeptr->Exit), 0); // level-2 1.001: STEERING keep a separate exit cell for the coordinate conversion
+
+					memcpy(&LinkedTo->Path[0], &LinkedTo->Path[1], sizeof(LinkedTo->Path[0]) * (CONQUER_PATH_MAX - 1));
+					LinkedTo->Path[CONQUER_PATH_MAX - 1] = FACING_NONE;
 
 					LinkedTo->CurrentTube = tube;
-					TPoint2D<short> const & enter = tubeptr->Enter;
+					TPoint2D<short> const & enter = tubeptr->Enter; // level-2 1.001: STEERING use the entrance point to construct the two cell operands
 					LinkedTo->CurrentTubeDir = FACING_FIRST;
 
-					Coord offset = Map[Adjacent_Cell(Cell(enter), tubeptr->Dirs[0])].Cell_Coord() - Coord(Cell(enter)); // level-2 1.001: the offset into the tube is formed first (hover.cpp form)
-					LinkedTo->LastTubeCoord = offset + LinkedTo->Get_Coord(); // level-2 1.001: as above
+					Coord offset = Map[Adjacent_Cell(Cell(enter), tubeptr->Dirs[0])].Cell_Coord() - Coord(Cell(enter)); // level-2 1.001: STEERING form the entrance offset before adding the unit position
+					LinkedTo->LastTubeCoord = offset + LinkedTo->Get_Coord();
 
 					int start_h = Map.Get_Height_GL(LinkedTo->Get_Coord());
-					LinkedTo->LastTubeCoord.Z = start_h + Tube_Height_Step(Cell(tubeptr->Exit), tubeptr->Count, start_h);
+					LinkedTo->LastTubeCoord.Z = start_h + Tube_Height_Step(Cell(tubeptr->Exit), tubeptr->Count, start_h); // level-2 1.001: STEERING preserve the exit cell temporary at the height call
 					return;
 				}
@@ -111,111 +100,91 @@
 				LinkedTo->Assign_Destination(NULL);
 				return;
-			} else { // level-2 1.001: the dispatch is a sibling block of the tube block ('what' shares its slot with 'tube' and the path temporaries)
-
-			Cell origin = LinkedTo->Get_Coord().As_Cell();
-			Cell what = Adjacent_Cell(origin, dir);
-
-			head_coord = Coord(what, 0);
-			head_coord.Z = Map.Get_Height_GL(head_coord);
-
-			CellClass * what_cell = &Map[what];
-
-			/*
-			 * If the bridge status of the cell being moved into differs from this
-			 * unit's bridge status, force a fresh look scan next time.
-			 */
-			if (LinkedTo->IsOnBridge ^ what_cell->IsUnderBridge) {
-				LinkedTo->IsPlanningToLook = true;
-			}
-
-			MoveType can_enter = LinkedTo->Can_Enter_Cell(&Map[what], dir, LinkedTo->Get_Cell_Height(), 0, true);
-
-			/*
-			 * A crusher driving into an occupied destroyable cell that has crushable
-			 * overlay just crushes through it -- treat as a normal (clear) move.
-			 */
-			if (((can_enter != MOVE_DESTROYABLE && can_enter != MOVE_FRIENDLY_DESTROYABLE) || !LinkedTo->TClass->IsCrusher || what_cell->Overlay != OVERLAY_FIRST) && can_enter != MOVE_OK) {
-
-				LinkedTo->Stop_Movement_Animation();
-
-				if (can_enter == MOVE_TEMP) {
-
-					CellClass * cellptr = &Map[what];
-
-					if (continue_moving) {
-						LinkedTo->Path[0] = FACING_NONE;
-						HeadToCoord = COORD_NONE;
-						LinkedTo->PathDelay = 0;
-						Movement_AI(false);
-						return;
-					}
-
-					bool close_enough = LinkedTo->Distance(DestinationCoord) < Rule->CloseEnoughDistance && !LinkedTo->HasAnyLink() // level-2 1.001: any radio link, called out of line; distance tested directly (hover.cpp form)
-						&& abs(DestinationCoord.Z - LinkedTo->Get_Coord().Z) < 2 * LEVEL_LEPTON_H
-						&& Map[LinkedTo->Get_Coord()].Land_Type() != LAND_TUNNEL; // level-2 1.001: the test is stored in a bool (one full expression; gives the exact 1.001 frame 0x5c)
-					if (close_enough) {
-
-						LinkedTo->Set_Speed(0);
-						LinkedTo->Assign_Destination(NULL);
-						LinkedTo->Path[0] = FACING_NONE;
-						Stop_Moving();
-						IsMoving = false;
-					} else {
-
-						bool bridge;
-						if (cellptr->IsUnderBridge) {
-							Coord coord = LinkedTo->Get_Coord();
-							int z = coord.Z;
-							bridge = true;
-							if (abs(z / LEVEL_LEPTON_H - cellptr->Height) <= 2) {
-								bridge = false;
-							}
+			} else {
+				Cell what = Adjacent_Cell(LinkedTo->Get_Coord().As_Cell(), dir);
+
+				Coord head_coord = Coord(what, 0);
+				head_coord.Z = Map.Get_Height_GL(head_coord);
+
+				CellClass * what_cell = &Map[what];
+
+				if (LinkedTo->IsOnBridge ^ what_cell->IsUnderBridge) {
+					LinkedTo->IsPlanningToLook = true;
+				}
+
+				MoveType can_enter = LinkedTo->Can_Enter_Cell(&Map[what], dir, LinkedTo->Get_Cell_Height(), 0, true);
+
+				if (((can_enter != MOVE_DESTROYABLE && can_enter != MOVE_FRIENDLY_DESTROYABLE) || !LinkedTo->TClass->IsCrusher || what_cell->Overlay != OVERLAY_FIRST) && can_enter != MOVE_OK) {
+
+					LinkedTo->Stop_Movement_Animation();
+
+					if (can_enter == MOVE_TEMP) {
+
+						CellClass * cellptr = &Map[what];
+
+						if (continue_moving) {
+							LinkedTo->Path[0] = FACING_NONE;
+							HeadToCoord = COORD_NONE;
+							LinkedTo->PathDelay = 0;
+							Movement_AI(false);
+							return;
+						}
+
+						int dist = LinkedTo->Distance(DestinationCoord);
+
+						if (dist < (int)Rule->CloseEnoughDistance && !LinkedTo->HasAnyLink()
+							&& abs(DestinationCoord.Z - LinkedTo->Get_Coord().Z) < 2 * LEVEL_LEPTON_H
+							&& Map[LinkedTo->Get_Coord()].Land_Type() != LAND_TUNNEL) {
+
+							LinkedTo->Set_Speed(0);
+							LinkedTo->Assign_Destination(NULL);
+							LinkedTo->Path[0] = FACING_NONE;
+							Stop_Moving();
+							IsMoving = false;
 						} else {
-							bridge = false;
-						}
-						cellptr->Incoming(COORD_NONE, true, true, bridge);
-					}
-					return;
-				}
-
-				if (can_enter == MOVE_MOVING_BLOCK) {
-
-					if (!LinkedTo->IsToPathAroundBlockage) {
-						LinkedTo->IsToPathAroundBlockage = true;
-						LinkedTo->BlockagePathDelay = Rule->BlockagePathDelay;
-					}
-
-					if (LinkedTo->PathDelay == 0) {
-
-						bool blockage_expired = LinkedTo->IsToPathAroundBlockage && LinkedTo->BlockagePathDelay == 0;
-
-						bool path_ok = LinkedTo->Basic_Path(DestinationCoord.As_Cell(), 0, blockage_expired ? 2 : 1);
-						LinkedTo->PathDelay = Rule->PathDelay * TICKS_PER_MINUTE;
-
-						if (!path_ok) {
-							if (!LinkedTo->Is_In_Same_Zone(DestinationCoord)) {
-								LinkedTo->Assign_Destination(NULL);
+
+							bool bridge = cellptr->IsUnderBridge && abs(LinkedTo->Get_Coord().Z / LEVEL_LEPTON_H - cellptr->Height) > 2;
+							cellptr->Incoming(COORD_NONE, true, true, bridge);
+						}
+						return;
+					}
+
+					if (can_enter == MOVE_MOVING_BLOCK) {
+
+						if (!LinkedTo->IsToPathAroundBlockage) {
+							LinkedTo->IsToPathAroundBlockage = true;
+							LinkedTo->BlockagePathDelay = Rule->BlockagePathDelay;
+						}
+
+						if (LinkedTo->PathDelay == 0) {
+
+							bool blockage_expired = LinkedTo->IsToPathAroundBlockage && LinkedTo->BlockagePathDelay == 0;
+
+							bool path_ok = LinkedTo->Basic_Path(DestinationCoord.As_Cell(), 0, blockage_expired ? 2 : 1);
+							LinkedTo->PathDelay = Rule->PathDelay * TICKS_PER_MINUTE;
+
+							if (!path_ok) {
+								if (!LinkedTo->Is_In_Same_Zone(DestinationCoord)) {
+									LinkedTo->Assign_Destination(NULL);
+								} else {
+									LinkedTo->On_Movement_Blocked();
+								}
 							} else {
-								LinkedTo->On_Movement_Blocked();
-							}
-						} else {
-							LinkedTo->JumpJet_To_Walk();
-						}
-						return;
-					}
-
-					DirStruct face = (DirStruct &)::Direction(LinkedTo->Center_Coord(), head_coord);
-					Do_Turn(face);
-					return;
-				}
-
-				if (can_enter == MOVE_CLOSED_GATE) {
-					Map.Try_Open_Gate(LinkedTo, what);
-					LinkedTo->TryTryAgain = FootClass::PATH_RETRY;
-					return;
-				}
-
-				if (can_enter != MOVE_CLOAK) {
-					if (can_enter != MOVE_NO) {
+								LinkedTo->JumpJet_To_Walk();
+							}
+							return;
+						}
+
+						DirStruct face = (DirStruct &)::Direction(LinkedTo->Center_Coord(), head_coord);
+						Do_Turn(face);
+						return;
+					}
+
+					if (can_enter == MOVE_CLOSED_GATE) {
+						Map.Try_Open_Gate(LinkedTo, what);
+						LinkedTo->TryTryAgain = FootClass::PATH_RETRY;
+						return;
+					}
+
+					if (can_enter != MOVE_CLOAK && can_enter != MOVE_NO) {
 						if (can_enter == MOVE_DESTROYABLE || can_enter == MOVE_FRIENDLY_DESTROYABLE) {
 
@@ -245,68 +214,55 @@
 						Stop_Moving();
 						LinkedTo->IsNewNavCom = false;
-						LinkedTo->IsNewNavCom = false;
+					} else {
+						if (can_enter == MOVE_CLOAK) {
+							Map[what].Shimmer();
+						}
+
+						if (!continue_moving) return;
+
+						LinkedTo->Path[0] = FACING_NONE;
+						HeadToCoord = COORD_NONE;
+						LinkedTo->PathDelay = 0;
+						Movement_AI(false);
 						return;
 					}
 				} else {
-					Map[what].Shimmer();
-				}
-
-				if (!continue_moving) return;
-
-				LinkedTo->Path[0] = FACING_NONE;
-				HeadToCoord = COORD_NONE;
-				LinkedTo->PathDelay = 0;
-				Movement_AI(false);
-				return;
-			}
-
-			if (Mark_Head_To(head_coord)) {
-
-				FacingType next_dir = LinkedTo->Path[0];
-				if (next_dir != FACING_NONE && next_dir != FACING_COUNT) {
-					Cell cell = LinkedTo->Get_Cell() + AdjacentCell[(int)next_dir & 7];
-					OverlayType overlay = Map[cell].Overlay;
-					if (overlay != OVERLAY_NONE) {
-						OverlayTypeClass * otype = OverlayTypes[overlay];
-						if ((LinkedTo->TClass->IsCrusher || LinkedTo->Has_Ability(ABILITY_CRUSHER)) && otype->HeapID == OVERLAY_SANDBAG_WALL) {
-							LinkedTo->IsCrushing = true;
-							if (LinkedTo->TClass->IsTiltsWhenCrushes) {
-								LinkedTo->RockingForwardsPerFrame = -0.01f;
-							}
-						}
-					}
-				}
-
-				if (LinkedTo->IsActive) {
-
-					DirStruct face = (DirStruct &)::Direction(LinkedTo->Center_Coord(), HeadToCoord);
-					Do_Turn(face);
-
-					bool turning = LinkedTo->PrimaryFacing.Is_Rotating();
-					if (!turning) {
+
+					if (Mark_Head_To(head_coord)) {
+
+						if (LinkedTo->Path[0] != FACING_NONE && LinkedTo->Path[0] != FACING_COUNT) {
+							Cell cell = Adjacent_Cell(LinkedTo->Get_Cell(), LinkedTo->Path[0]);
+							CellClass * cellptr = &Map[cell];
+							if (cellptr->Overlay != OVERLAY_NONE) {
+								OverlayTypeClass * otype = OverlayTypes[cellptr->Overlay];
+								if ((LinkedTo->TClass->IsCrusher || LinkedTo->Has_Ability(ABILITY_CRUSHER)) && otype->HeapID == OVERLAY_SANDBAG_WALL) {
+									LinkedTo->IsCrushing = true;
+									if (LinkedTo->TClass->IsTiltsWhenCrushes) {
+										LinkedTo->RockingForwardsPerFrame = -0.01f;
+									}
+								}
+							}
+						}
+
+						if (!LinkedTo->IsActive) return;
+
+						DirStruct face = (DirStruct &)::Direction(LinkedTo->Center_Coord(), HeadToCoord);
+						Do_Turn(face);
+
+						if (LinkedTo->PrimaryFacing.Is_Rotating()) return;
+
 						LinkedTo->Set_Speed(1.0);
-						LinkedTo->IsNewNavCom = false;
-					}
-				}
-			} else {
-				LinkedTo->Set_Speed(0);
-				LinkedTo->IsNewNavCom = false;
-			}
-			}
-			return;
+					} else {
+						LinkedTo->Set_Speed(0);
+					}
+				}
+			}
 
 		} else {
 
-			/*
-			 * With no immediate destination and no overall destination, just stop
-			 * moving (if the unit is still rolling) and bail out.
-			 */
 			if (LinkedTo->Speed > 0.0) {
 				LinkedTo->Set_Speed(0.0);
-				goto clear_new_nav;
-			}
-			LinkedTo->IsNewNavCom = false;
-			return;
-		} // level-2 1.001: a stopped unit falls into the common final IsNewNavCom store (1.001 jumps to the one after Trigger_Veins)
+			}
+		}
 	} else {
 
@@ -319,6 +275,6 @@
 			}
 
-			memcpy(&LinkedTo->Path[0], &LinkedTo->Path[1], 92);
-			LinkedTo->Path[23] = FACING_NONE;
+			memcpy(&LinkedTo->Path[0], &LinkedTo->Path[1], sizeof(LinkedTo->Path[0]) * (CONQUER_PATH_MAX - 1));
+			LinkedTo->Path[CONQUER_PATH_MAX - 1] = FACING_NONE;
 
 			LinkedTo->Set_Coord(HeadToCoord);
@@ -336,12 +292,7 @@
 			LinkedTo->IsToPathAroundBlockage = false;
 
-			/*
-			 * The walk is over when there is no destination left to reach, or when
-			 * this cell is the destination cell and the two are close in height.
-			 */
-			bool arrived = DestinationCoord == COORD_NONE
+			if (DestinationCoord == COORD_NONE
 				|| (LinkedTo->Get_Cell() == DestinationCoord.As_Cell()
-					&& abs(LinkedTo->Destination_Coord().Z - DestinationCoord.Z) < 2 * LEVEL_LEPTON_H);
-			if (arrived) {
+					&& abs(LinkedTo->Destination_Coord().Z - DestinationCoord.Z) < 2 * LEVEL_LEPTON_H)) {
 
 				LinkedTo->Assign_Destination(NULL);
@@ -353,87 +304,80 @@
 			LinkedTo->Per_Cell_Process(PCP_END);
 
-			if (LinkedTo->IsActive) { // level-2 1.001: no NULL test of LinkedTo
-				if (!LinkedTo->IsInLimbo && !LinkedTo->IsFalling) {
-					if (LinkedTo->Path[0] != FACING_NONE && LinkedTo->Path[0] != FACING_COUNT) {
-						FacingType next_move = LinkedTo->Path[0];
-						old_cell = LinkedTo->Get_Cell();
-						Cell check_coord = Adjacent_Cell(old_cell, next_move);
-
-						OverlayType overlay = Map[check_coord].Overlay;
-						if (overlay != OVERLAY_NONE) {
-							OverlayTypeClass * otype = OverlayTypes[overlay];
-							if ((LinkedTo->TClass->IsCrusher || LinkedTo->Has_Ability(ABILITY_CRUSHER)) && otype->HeapID == OVERLAY_SANDBAG_WALL) {
-								LinkedTo->IsCrushing = true;
-
-								if (LinkedTo->TClass->IsTiltsWhenCrushes) {
-									LinkedTo->RockingForwardsPerFrame = -0.01f;
-								}
-							}
-						}
-					}
-
-					if (LinkedTo->IsActive && !LinkedTo->IsInLimbo) {
-						LinkedTo->Mark(MARK_DOWN);
-						LinkedTo->IsNewNavCom = false;
-					}
-				}
-			}
-			return;
-		}
-
-		LinkedTo->Set_Speed(1.0);
-
-		int speed = LinkedTo->Current_Speed();
-
-		DirType desired_facing = ::Direction(LinkedTo->Center_Coord(), HeadToCoord);
-		Do_Turn((DirStruct &)desired_facing);
-
-		if (LinkedTo->PrimaryFacing.Is_Rotating()) {
-			return;
-		}
-
-		if (LinkedTo->Occupies_Cells()) {
-			LinkedTo->Clear_Occupy_Bit(LinkedTo->Get_Coord());
-			LinkedTo->IsOccupyingCell = false;
-
-			LinkedTo->IsToPathAroundBlockage = false;
-
-		}
-
-		old_cell = LinkedTo->Get_Cell();
-
-		Coord new_coord = Move_Coord(LinkedTo->Get_Coord(), desired_facing, speed);
-		Cell new_cell = new_coord;
-
-		if (old_cell != new_cell) {
-
-			LinkedTo->Mark(MARK_UP);
-			LinkedTo->Set_Coord(new_coord);
-
-			CellClass * old_cellptr = &Map[old_cell];
-			CellClass * new_cellptr = &Map[new_cell];
-
-			if (new_cellptr->Height == old_cellptr->Height - BRIDGE_CELL_HEIGHT && new_cellptr->IsUnderBridge) {
-				LinkedTo->IsOnBridge = true;
-			}
-			if (!new_cellptr->IsUnderBridge && old_cellptr->IsUnderBridge) {
-				LinkedTo->IsOnBridge = false;
-			}
-
-			LinkedTo->HeightAGL = 0;
+			if (!LinkedTo->IsActive) return;
+			if (LinkedTo->IsInLimbo || LinkedTo->IsFalling) return;
+
+			if (LinkedTo->Path[0] != FACING_NONE && LinkedTo->Path[0] != FACING_COUNT) {
+				Cell check_coord = Adjacent_Cell(LinkedTo->Get_Cell(), LinkedTo->Path[0]);
+
+				CellClass * cellptr = &Map[check_coord];
+				if (cellptr->Overlay != OVERLAY_NONE) {
+					OverlayTypeClass * otype = OverlayTypes[cellptr->Overlay];
+					if ((LinkedTo->TClass->IsCrusher || LinkedTo->Has_Ability(ABILITY_CRUSHER)) && otype->HeapID == OVERLAY_SANDBAG_WALL) {
+						LinkedTo->IsCrushing = true;
+
+						if (LinkedTo->TClass->IsTiltsWhenCrushes) {
+							LinkedTo->RockingForwardsPerFrame = -0.01f;
+						}
+					}
+				}
+			}
+
+			if (!LinkedTo->IsActive || LinkedTo->IsInLimbo) return;
+
 			LinkedTo->Mark(MARK_DOWN);
-
-			Map[LinkedTo->Get_Coord()].Trigger_Veins();
 		} else {
-			bool was_down = LinkedTo->IsDown;
-			LinkedTo->IsDown = false;
-			LinkedTo->Set_Coord(new_coord);
-			LinkedTo->HeightAGL = 0;
-			LinkedTo->IsDown = was_down;
-			LinkedTo->IsNewNavCom = false;
-			return;
+
+			LinkedTo->Set_Speed(1.0);
+
+			int speed = LinkedTo->Current_Speed();
+
+			DirType desired_facing = ::Direction(LinkedTo->Center_Coord(), HeadToCoord);
+			Do_Turn((DirStruct &)desired_facing);
+
+			if (LinkedTo->PrimaryFacing.Is_Rotating()) {
+				return;
+			}
+
+			if (LinkedTo->Occupies_Cells()) {
+				LinkedTo->Clear_Occupy_Bit(LinkedTo->Get_Coord());
+				LinkedTo->IsOccupyingCell = false;
+				LinkedTo->IsToPathAroundBlockage = false;
+			}
+
+			Cell old_cell = LinkedTo->Get_Cell();
+
+			Coord new_coord = Move_Coord(LinkedTo->Get_Coord(), desired_facing, speed);
+			Cell new_cell = new_coord;
+
+			bool moved = (old_cell != new_cell);
+			if (moved) {
+				LinkedTo->Mark(MARK_UP);
+				LinkedTo->Set_Coord(new_coord);
+
+				CellClass * old_cellptr = &Map[old_cell];
+				CellClass * new_cellptr = &Map[new_cell];
+
+				if (new_cellptr->Height == old_cellptr->Height - BRIDGE_CELL_HEIGHT && new_cellptr->IsUnderBridge) {
+					LinkedTo->IsOnBridge = true;
+				}
+				if (!new_cellptr->IsUnderBridge && old_cellptr->IsUnderBridge) {
+					LinkedTo->IsOnBridge = false;
+				}
+
+				LinkedTo->HeightAGL = 0;
+				LinkedTo->Mark(MARK_DOWN);
+			} else {
+				bool was_down = LinkedTo->IsDown;
+				LinkedTo->IsDown = false;
+				LinkedTo->Set_Coord(new_coord);
+				LinkedTo->HeightAGL = 0;
+				LinkedTo->IsDown = was_down;
+			}
+
+			if (moved) {
+				Map[LinkedTo->Get_Coord()].Trigger_Veins();
+			}
 		}
 	}
-clear_new_nav:
-	LinkedTo->IsNewNavCom = false; // level-2 1.001: the common final store (see above)
+	LinkedTo->IsNewNavCom = false;
 }
```

## 2. Our matched form against the community form

```diff
--- community
+++ ours matched
@@ -35,10 +35,10 @@
 
 							if (LinkedTo->IsNewNavCom) {
-								VocClass::PlayGlobal(Rule->ScoldSound, 1.0f, 0x2000);
+								Sound_Effect(Rule->ScoldSound);
 							}
 							LinkedTo->IsNewNavCom = false;
 
 							Cell dest_cell = DestinationCoord;
-							if (LinkedTo->IsInPlayfield) {
+							if (LinkedTo->IsLocked) {
 								Cell src_cell = LinkedTo->Destination_Coord().As_Cell();
 								if (!Map.Is_Same_Cell_Zone(src_cell, dest_cell, LinkedTo->TClass->MZone, LinkedTo->Is_Moving_Onto_Bridge(), Map[dest_cell].IsUnderBridge, LinkedTo->Is_Allowed_To_Leave_Map())) {
@@ -49,5 +49,5 @@
 							if (LinkedTo->TarCom != NULL) {
 								Cell tar_cell = LinkedTo->TarCom->Destination_Coord(LinkedTo).As_Cell();
-								if (LinkedTo->IsInPlayfield) {
+								if (LinkedTo->IsLocked) {
 									Cell src_cell = LinkedTo->Destination_Coord(LinkedTo).As_Cell();
 									if (!Map.Is_Same_Cell_Zone(src_cell, tar_cell, LinkedTo->TClass->MZone, LinkedTo->Is_Moving_Onto_Bridge(LinkedTo), Map[tar_cell].IsUnderBridge, LinkedTo->Is_Allowed_To_Leave_Map())) {
@@ -78,6 +78,5 @@
 					TubeClass * tubeptr = Tubes[tube];
 
-					Cell exit = tubeptr->Get_Exit();
-					HeadToCoord = exit.As_Coord();
+					HeadToCoord = Coord(Cell(tubeptr->Exit), 0); // level-2 1.001: STEERING keep a separate exit cell for the coordinate conversion
 
 					memcpy(&LinkedTo->Path[0], &LinkedTo->Path[1], sizeof(LinkedTo->Path[0]) * (CONQUER_PATH_MAX - 1));
@@ -85,12 +84,12 @@
 
 					LinkedTo->CurrentTube = tube;
+					TPoint2D<short> const & enter = tubeptr->Enter; // level-2 1.001: STEERING use the entrance point to construct the two cell operands
 					LinkedTo->CurrentTubeDir = FACING_FIRST;
 
-					Coord enter = (Cell)tubeptr->Enter;
-					Coord offset = Map[Adjacent_Cell((Cell)tubeptr->Enter, tubeptr->Dirs[0])].Cell_Coord() - enter;
-					LinkedTo->LastTubeCoord = LinkedTo->PositionCoord + offset;
-
-					int start_h = Map.Get_Height_GL(LinkedTo->PositionCoord);
-					LinkedTo->LastTubeCoord.Z = start_h + (Map.Get_Height_GL(tubeptr->Get_Exit()) - start_h) / tubeptr->Get_Count();
+					Coord offset = Map[Adjacent_Cell(Cell(enter), tubeptr->Dirs[0])].Cell_Coord() - Coord(Cell(enter)); // level-2 1.001: STEERING form the entrance offset before adding the unit position
+					LinkedTo->LastTubeCoord = offset + LinkedTo->Get_Coord();
+
+					int start_h = Map.Get_Height_GL(LinkedTo->Get_Coord());
+					LinkedTo->LastTubeCoord.Z = start_h + Tube_Height_Step(Cell(tubeptr->Exit), tubeptr->Count, start_h); // level-2 1.001: STEERING preserve the exit cell temporary at the height call
 					return;
 				}
@@ -294,5 +293,5 @@
 
 			if (DestinationCoord == COORD_NONE
-				|| (LinkedTo->Get_Cell() == DestinationCoord
+				|| (LinkedTo->Get_Cell() == DestinationCoord.As_Cell()
 					&& abs(LinkedTo->Destination_Coord().Z - DestinationCoord.Z) < 2 * LEVEL_LEPTON_H)) {
 
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -1,6 +1,4 @@
-void MechLocomotionClass::Movement_AI(bool continue_moving) // RA2: defined here, between Force_Immediate_Destination and Mark_Head_To
+void MechLocomotionClass::Movement_AI(bool continue_moving)
 {
-	Cell old_cell;
-	Coord head_coord;
 	if (LinkedTo->PrimaryFacing.Is_Rotating()) {
 		return;
@@ -10,8 +8,4 @@
 		if (DestinationCoord != COORD_NONE) {
 
-			/*
-			 * A destination exists. If there is no current path then try to build
-			 * one. If a path already exists, fall through to dispatch the next leg.
-			 */
 			if (LinkedTo->Path[0] == FACING_NONE) {
 
@@ -25,48 +19,47 @@
 				if (!LinkedTo->Basic_Path(DestinationCoord.As_Cell(), 0, 0)) {
 
-					if (LinkedTo->Is_In_Same_Zone(DestinationCoord)) {
-
-						int dist = LinkedTo->Distance(DestinationCoord); // level-2 1.001: lead only, the member form is closer to the 1.001 inlining than the free Distance
-
-						if (dist < (int)Rule->CloseEnoughDistance && !LinkedTo->IsTethered) {
-							LinkedTo->Assign_Destination(NULL);
+					if (!LinkedTo->Is_In_Same_Zone(DestinationCoord)) {
+						LinkedTo->Assign_Destination(NULL);
+						return;
+					}
+
+					int dist = Distance(LinkedTo->Center_Coord(), DestinationCoord);
+
+					if (dist < (int)Rule->CloseEnoughDistance && !LinkedTo->IsTethered) {
+						LinkedTo->Assign_Destination(NULL);
+					} else {
+
+						if (LinkedTo->TryTryAgain != 0) {
+							LinkedTo->TryTryAgain--;
 						} else {
 
-							if (LinkedTo->TryTryAgain != 0) {
-								LinkedTo->TryTryAgain--;
-							} else {
-
-								if (LinkedTo->IsNewNavCom) {
-									Sound_Effect(Rule->ScoldSound);
-								}
-								LinkedTo->IsNewNavCom = false;
-
-								Cell dest_cell = DestinationCoord;
-								if (LinkedTo->IsLocked) {
-									Cell src_cell = LinkedTo->Destination_Coord().As_Cell();
-									if (!Map.Is_Same_Cell_Zone(src_cell, dest_cell, LinkedTo->TClass->MZone, LinkedTo->Is_Moving_Onto_Bridge(), Map[dest_cell].IsUnderBridge, LinkedTo->Is_Allowed_To_Leave_Map())) {
-										LinkedTo->Assign_Destination(NULL);
+							if (LinkedTo->IsNewNavCom) {
+								VocClass::PlayGlobal(Rule->ScoldSound, 1.0f, 0x2000);
+							}
+							LinkedTo->IsNewNavCom = false;
+
+							Cell dest_cell = DestinationCoord;
+							if (LinkedTo->IsInPlayfield) {
+								Cell src_cell = LinkedTo->Destination_Coord().As_Cell();
+								if (!Map.Is_Same_Cell_Zone(src_cell, dest_cell, LinkedTo->TClass->MZone, LinkedTo->Is_Moving_Onto_Bridge(), Map[dest_cell].IsUnderBridge, LinkedTo->Is_Allowed_To_Leave_Map())) {
+									LinkedTo->Assign_Destination(NULL);
+								}
+							}
+
+							if (LinkedTo->TarCom != NULL) {
+								Cell tar_cell = LinkedTo->TarCom->Destination_Coord(LinkedTo).As_Cell();
+								if (LinkedTo->IsInPlayfield) {
+									Cell src_cell = LinkedTo->Destination_Coord(LinkedTo).As_Cell();
+									if (!Map.Is_Same_Cell_Zone(src_cell, tar_cell, LinkedTo->TClass->MZone, LinkedTo->Is_Moving_Onto_Bridge(LinkedTo), Map[tar_cell].IsUnderBridge, LinkedTo->Is_Allowed_To_Leave_Map())) {
+										LinkedTo->Assign_Target(NULL);
 									}
 								}
-
-								if (LinkedTo->TarCom != NULL) {
-									Cell tar_cell = LinkedTo->TarCom->Destination_Coord(LinkedTo).As_Cell(); // level-2 1.001: the unit is passed as the docker here
-									if (LinkedTo->IsLocked) {
-										Cell src_cell = LinkedTo->Destination_Coord(LinkedTo).As_Cell();
-										if (!Map.Is_Same_Cell_Zone(src_cell, tar_cell, LinkedTo->TClass->MZone, LinkedTo->Is_Moving_Onto_Bridge(LinkedTo), Map[tar_cell].IsUnderBridge, LinkedTo->Is_Allowed_To_Leave_Map())) {
-											LinkedTo->Assign_Target(NULL);
-										}
-									}
-								}
-							}
-						}
-
-						LinkedTo->Set_Speed(0);
-						Stop_Moving();
-						IsMoving = false;
-						return;
-					}
-
-					LinkedTo->Assign_Destination(NULL);
+							}
+						}
+					}
+
+					LinkedTo->Set_Speed(0);
+					Stop_Moving();
+					IsMoving = false;
 					return;
 				}
@@ -75,8 +68,4 @@
 			}
 
-			/*
-			 * Dispatch the next leg of the path. A path entry of FACING_COUNT is
-			 * a special tunnel transition.
-			 */
 			FacingType dir = LinkedTo->Path[0];
 			if (dir == FACING_COUNT) {
@@ -89,18 +78,19 @@
 					TubeClass * tubeptr = Tubes[tube];
 
-					HeadToCoord = Coord(Cell(tubeptr->Exit), 0);
-
-					memcpy(&LinkedTo->Path[0], &LinkedTo->Path[1], 92);
-					LinkedTo->Path[23] = FACING_NONE;
+					Cell exit = tubeptr->Get_Exit();
+					HeadToCoord = exit.As_Coord();
+
+					memcpy(&LinkedTo->Path[0], &LinkedTo->Path[1], sizeof(LinkedTo->Path[0]) * (CONQUER_PATH_MAX - 1));
+					LinkedTo->Path[CONQUER_PATH_MAX - 1] = FACING_NONE;
 
 					LinkedTo->CurrentTube = tube;
-					TPoint2D<short> const & enter = tubeptr->Enter;
 					LinkedTo->CurrentTubeDir = FACING_FIRST;
 
-					Coord offset = Map[Adjacent_Cell(Cell(enter), tubeptr->Dirs[0])].Cell_Coord() - Coord(Cell(enter)); // level-2 1.001: the offset into the tube is formed first (hover.cpp form)
-					LinkedTo->LastTubeCoord = offset + LinkedTo->Get_Coord(); // level-2 1.001: as above
-
-					int start_h = Map.Get_Height_GL(LinkedTo->Get_Coord());
-					LinkedTo->LastTubeCoord.Z = start_h + Tube_Height_Step(Cell(tubeptr->Exit), tubeptr->Count, start_h);
+					Coord enter = (Cell)tubeptr->Enter;
+					Coord offset = Map[Adjacent_Cell((Cell)tubeptr->Enter, tubeptr->Dirs[0])].Cell_Coord() - enter;
+					LinkedTo->LastTubeCoord = LinkedTo->PositionCoord + offset;
+
+					int start_h = Map.Get_Height_GL(LinkedTo->PositionCoord);
+					LinkedTo->LastTubeCoord.Z = start_h + (Map.Get_Height_GL(tubeptr->Get_Exit()) - start_h) / tubeptr->Get_Count();
 					return;
 				}
@@ -111,111 +101,91 @@
 				LinkedTo->Assign_Destination(NULL);
 				return;
-			} else { // level-2 1.001: the dispatch is a sibling block of the tube block ('what' shares its slot with 'tube' and the path temporaries)
-
-			Cell origin = LinkedTo->Get_Coord().As_Cell();
-			Cell what = Adjacent_Cell(origin, dir);
-
-			head_coord = Coord(what, 0);
-			head_coord.Z = Map.Get_Height_GL(head_coord);
-
-			CellClass * what_cell = &Map[what];
-
-			/*
-			 * If the bridge status of the cell being moved into differs from this
-			 * unit's bridge status, force a fresh look scan next time.
-			 */
-			if (LinkedTo->IsOnBridge ^ what_cell->IsUnderBridge) {
-				LinkedTo->IsPlanningToLook = true;
-			}
-
-			MoveType can_enter = LinkedTo->Can_Enter_Cell(&Map[what], dir, LinkedTo->Get_Cell_Height(), 0, true);
-
-			/*
-			 * A crusher driving into an occupied destroyable cell that has crushable
-			 * overlay just crushes through it -- treat as a normal (clear) move.
-			 */
-			if (((can_enter != MOVE_DESTROYABLE && can_enter != MOVE_FRIENDLY_DESTROYABLE) || !LinkedTo->TClass->IsCrusher || what_cell->Overlay != OVERLAY_FIRST) && can_enter != MOVE_OK) {
-
-				LinkedTo->Stop_Movement_Animation();
-
-				if (can_enter == MOVE_TEMP) {
-
-					CellClass * cellptr = &Map[what];
-
-					if (continue_moving) {
-						LinkedTo->Path[0] = FACING_NONE;
-						HeadToCoord = COORD_NONE;
-						LinkedTo->PathDelay = 0;
-						Movement_AI(false);
-						return;
-					}
-
-					bool close_enough = LinkedTo->Distance(DestinationCoord) < Rule->CloseEnoughDistance && !LinkedTo->HasAnyLink() // level-2 1.001: any radio link, called out of line; distance tested directly (hover.cpp form)
-						&& abs(DestinationCoord.Z - LinkedTo->Get_Coord().Z) < 2 * LEVEL_LEPTON_H
-						&& Map[LinkedTo->Get_Coord()].Land_Type() != LAND_TUNNEL; // level-2 1.001: the test is stored in a bool (one full expression; gives the exact 1.001 frame 0x5c)
-					if (close_enough) {
-
-						LinkedTo->Set_Speed(0);
-						LinkedTo->Assign_Destination(NULL);
-						LinkedTo->Path[0] = FACING_NONE;
-						Stop_Moving();
-						IsMoving = false;
-					} else {
-
-						bool bridge;
-						if (cellptr->IsUnderBridge) {
-							Coord coord = LinkedTo->Get_Coord();
-							int z = coord.Z;
-							bridge = true;
-							if (abs(z / LEVEL_LEPTON_H - cellptr->Height) <= 2) {
-								bridge = false;
-							}
+			} else {
+				Cell what = Adjacent_Cell(LinkedTo->Get_Coord().As_Cell(), dir);
+
+				Coord head_coord = Coord(what, 0);
+				head_coord.Z = Map.Get_Height_GL(head_coord);
+
+				CellClass * what_cell = &Map[what];
+
+				if (LinkedTo->IsOnBridge ^ what_cell->IsUnderBridge) {
+					LinkedTo->IsPlanningToLook = true;
+				}
+
+				MoveType can_enter = LinkedTo->Can_Enter_Cell(&Map[what], dir, LinkedTo->Get_Cell_Height(), 0, true);
+
+				if (((can_enter != MOVE_DESTROYABLE && can_enter != MOVE_FRIENDLY_DESTROYABLE) || !LinkedTo->TClass->IsCrusher || what_cell->Overlay != OVERLAY_FIRST) && can_enter != MOVE_OK) {
+
+					LinkedTo->Stop_Movement_Animation();
+
+					if (can_enter == MOVE_TEMP) {
+
+						CellClass * cellptr = &Map[what];
+
+						if (continue_moving) {
+							LinkedTo->Path[0] = FACING_NONE;
+							HeadToCoord = COORD_NONE;
+							LinkedTo->PathDelay = 0;
+							Movement_AI(false);
+							return;
+						}
+
+						int dist = LinkedTo->Distance(DestinationCoord);
+
+						if (dist < (int)Rule->CloseEnoughDistance && !LinkedTo->HasAnyLink()
+							&& abs(DestinationCoord.Z - LinkedTo->Get_Coord().Z) < 2 * LEVEL_LEPTON_H
+							&& Map[LinkedTo->Get_Coord()].Land_Type() != LAND_TUNNEL) {
+
+							LinkedTo->Set_Speed(0);
+							LinkedTo->Assign_Destination(NULL);
+							LinkedTo->Path[0] = FACING_NONE;
+							Stop_Moving();
+							IsMoving = false;
 						} else {
-							bridge = false;
-						}
-						cellptr->Incoming(COORD_NONE, true, true, bridge);
-					}
-					return;
-				}
-
-				if (can_enter == MOVE_MOVING_BLOCK) {
-
-					if (!LinkedTo->IsToPathAroundBlockage) {
-						LinkedTo->IsToPathAroundBlockage = true;
-						LinkedTo->BlockagePathDelay = Rule->BlockagePathDelay;
-					}
-
-					if (LinkedTo->PathDelay == 0) {
-
-						bool blockage_expired = LinkedTo->IsToPathAroundBlockage && LinkedTo->BlockagePathDelay == 0;
-
-						bool path_ok = LinkedTo->Basic_Path(DestinationCoord.As_Cell(), 0, blockage_expired ? 2 : 1);
-						LinkedTo->PathDelay = Rule->PathDelay * TICKS_PER_MINUTE;
-
-						if (!path_ok) {
-							if (!LinkedTo->Is_In_Same_Zone(DestinationCoord)) {
-								LinkedTo->Assign_Destination(NULL);
+
+							bool bridge = cellptr->IsUnderBridge && abs(LinkedTo->Get_Coord().Z / LEVEL_LEPTON_H - cellptr->Height) > 2;
+							cellptr->Incoming(COORD_NONE, true, true, bridge);
+						}
+						return;
+					}
+
+					if (can_enter == MOVE_MOVING_BLOCK) {
+
+						if (!LinkedTo->IsToPathAroundBlockage) {
+							LinkedTo->IsToPathAroundBlockage = true;
+							LinkedTo->BlockagePathDelay = Rule->BlockagePathDelay;
+						}
+
+						if (LinkedTo->PathDelay == 0) {
+
+							bool blockage_expired = LinkedTo->IsToPathAroundBlockage && LinkedTo->BlockagePathDelay == 0;
+
+							bool path_ok = LinkedTo->Basic_Path(DestinationCoord.As_Cell(), 0, blockage_expired ? 2 : 1);
+							LinkedTo->PathDelay = Rule->PathDelay * TICKS_PER_MINUTE;
+
+							if (!path_ok) {
+								if (!LinkedTo->Is_In_Same_Zone(DestinationCoord)) {
+									LinkedTo->Assign_Destination(NULL);
+								} else {
+									LinkedTo->On_Movement_Blocked();
+								}
 							} else {
-								LinkedTo->On_Movement_Blocked();
-							}
-						} else {
-							LinkedTo->JumpJet_To_Walk();
-						}
-						return;
-					}
-
-					DirStruct face = (DirStruct &)::Direction(LinkedTo->Center_Coord(), head_coord);
-					Do_Turn(face);
-					return;
-				}
-
-				if (can_enter == MOVE_CLOSED_GATE) {
-					Map.Try_Open_Gate(LinkedTo, what);
-					LinkedTo->TryTryAgain = FootClass::PATH_RETRY;
-					return;
-				}
-
-				if (can_enter != MOVE_CLOAK) {
-					if (can_enter != MOVE_NO) {
+								LinkedTo->JumpJet_To_Walk();
+							}
+							return;
+						}
+
+						DirStruct face = (DirStruct &)::Direction(LinkedTo->Center_Coord(), head_coord);
+						Do_Turn(face);
+						return;
+					}
+
+					if (can_enter == MOVE_CLOSED_GATE) {
+						Map.Try_Open_Gate(LinkedTo, what);
+						LinkedTo->TryTryAgain = FootClass::PATH_RETRY;
+						return;
+					}
+
+					if (can_enter != MOVE_CLOAK && can_enter != MOVE_NO) {
 						if (can_enter == MOVE_DESTROYABLE || can_enter == MOVE_FRIENDLY_DESTROYABLE) {
 
@@ -245,68 +215,55 @@
 						Stop_Moving();
 						LinkedTo->IsNewNavCom = false;
-						LinkedTo->IsNewNavCom = false;
+					} else {
+						if (can_enter == MOVE_CLOAK) {
+							Map[what].Shimmer();
+						}
+
+						if (!continue_moving) return;
+
+						LinkedTo->Path[0] = FACING_NONE;
+						HeadToCoord = COORD_NONE;
+						LinkedTo->PathDelay = 0;
+						Movement_AI(false);
 						return;
 					}
 				} else {
-					Map[what].Shimmer();
-				}
-
-				if (!continue_moving) return;
-
-				LinkedTo->Path[0] = FACING_NONE;
-				HeadToCoord = COORD_NONE;
-				LinkedTo->PathDelay = 0;
-				Movement_AI(false);
-				return;
-			}
-
-			if (Mark_Head_To(head_coord)) {
-
-				FacingType next_dir = LinkedTo->Path[0];
-				if (next_dir != FACING_NONE && next_dir != FACING_COUNT) {
-					Cell cell = LinkedTo->Get_Cell() + AdjacentCell[(int)next_dir & 7];
-					OverlayType overlay = Map[cell].Overlay;
-					if (overlay != OVERLAY_NONE) {
-						OverlayTypeClass * otype = OverlayTypes[overlay];
-						if ((LinkedTo->TClass->IsCrusher || LinkedTo->Has_Ability(ABILITY_CRUSHER)) && otype->HeapID == OVERLAY_SANDBAG_WALL) {
-							LinkedTo->IsCrushing = true;
-							if (LinkedTo->TClass->IsTiltsWhenCrushes) {
-								LinkedTo->RockingForwardsPerFrame = -0.01f;
-							}
-						}
-					}
-				}
-
-				if (LinkedTo->IsActive) {
-
-					DirStruct face = (DirStruct &)::Direction(LinkedTo->Center_Coord(), HeadToCoord);
-					Do_Turn(face);
-
-					bool turning = LinkedTo->PrimaryFacing.Is_Rotating();
-					if (!turning) {
+
+					if (Mark_Head_To(head_coord)) {
+
+						if (LinkedTo->Path[0] != FACING_NONE && LinkedTo->Path[0] != FACING_COUNT) {
+							Cell cell = Adjacent_Cell(LinkedTo->Get_Cell(), LinkedTo->Path[0]);
+							CellClass * cellptr = &Map[cell];
+							if (cellptr->Overlay != OVERLAY_NONE) {
+								OverlayTypeClass * otype = OverlayTypes[cellptr->Overlay];
+								if ((LinkedTo->TClass->IsCrusher || LinkedTo->Has_Ability(ABILITY_CRUSHER)) && otype->HeapID == OVERLAY_SANDBAG_WALL) {
+									LinkedTo->IsCrushing = true;
+									if (LinkedTo->TClass->IsTiltsWhenCrushes) {
+										LinkedTo->RockingForwardsPerFrame = -0.01f;
+									}
+								}
+							}
+						}
+
+						if (!LinkedTo->IsActive) return;
+
+						DirStruct face = (DirStruct &)::Direction(LinkedTo->Center_Coord(), HeadToCoord);
+						Do_Turn(face);
+
+						if (LinkedTo->PrimaryFacing.Is_Rotating()) return;
+
 						LinkedTo->Set_Speed(1.0);
-						LinkedTo->IsNewNavCom = false;
-					}
-				}
-			} else {
-				LinkedTo->Set_Speed(0);
-				LinkedTo->IsNewNavCom = false;
-			}
-			}
-			return;
+					} else {
+						LinkedTo->Set_Speed(0);
+					}
+				}
+			}
 
 		} else {
 
-			/*
-			 * With no immediate destination and no overall destination, just stop
-			 * moving (if the unit is still rolling) and bail out.
-			 */
 			if (LinkedTo->Speed > 0.0) {
 				LinkedTo->Set_Speed(0.0);
-				goto clear_new_nav;
-			}
-			LinkedTo->IsNewNavCom = false;
-			return;
-		} // level-2 1.001: a stopped unit falls into the common final IsNewNavCom store (1.001 jumps to the one after Trigger_Veins)
+			}
+		}
 	} else {
 
@@ -319,6 +276,6 @@
 			}
 
-			memcpy(&LinkedTo->Path[0], &LinkedTo->Path[1], 92);
-			LinkedTo->Path[23] = FACING_NONE;
+			memcpy(&LinkedTo->Path[0], &LinkedTo->Path[1], sizeof(LinkedTo->Path[0]) * (CONQUER_PATH_MAX - 1));
+			LinkedTo->Path[CONQUER_PATH_MAX - 1] = FACING_NONE;
 
 			LinkedTo->Set_Coord(HeadToCoord);
@@ -336,12 +293,7 @@
 			LinkedTo->IsToPathAroundBlockage = false;
 
-			/*
-			 * The walk is over when there is no destination left to reach, or when
-			 * this cell is the destination cell and the two are close in height.
-			 */
-			bool arrived = DestinationCoord == COORD_NONE
-				|| (LinkedTo->Get_Cell() == DestinationCoord.As_Cell()
-					&& abs(LinkedTo->Destination_Coord().Z - DestinationCoord.Z) < 2 * LEVEL_LEPTON_H);
-			if (arrived) {
+			if (DestinationCoord == COORD_NONE
+				|| (LinkedTo->Get_Cell() == DestinationCoord
+					&& abs(LinkedTo->Destination_Coord().Z - DestinationCoord.Z) < 2 * LEVEL_LEPTON_H)) {
 
 				LinkedTo->Assign_Destination(NULL);
@@ -353,87 +305,80 @@
 			LinkedTo->Per_Cell_Process(PCP_END);
 
-			if (LinkedTo->IsActive) { // level-2 1.001: no NULL test of LinkedTo
-				if (!LinkedTo->IsInLimbo && !LinkedTo->IsFalling) {
-					if (LinkedTo->Path[0] != FACING_NONE && LinkedTo->Path[0] != FACING_COUNT) {
-						FacingType next_move = LinkedTo->Path[0];
-						old_cell = LinkedTo->Get_Cell();
-						Cell check_coord = Adjacent_Cell(old_cell, next_move);
-
-						OverlayType overlay = Map[check_coord].Overlay;
-						if (overlay != OVERLAY_NONE) {
-							OverlayTypeClass * otype = OverlayTypes[overlay];
-							if ((LinkedTo->TClass->IsCrusher || LinkedTo->Has_Ability(ABILITY_CRUSHER)) && otype->HeapID == OVERLAY_SANDBAG_WALL) {
-								LinkedTo->IsCrushing = true;
-
-								if (LinkedTo->TClass->IsTiltsWhenCrushes) {
-									LinkedTo->RockingForwardsPerFrame = -0.01f;
-								}
-							}
-						}
-					}
-
-					if (LinkedTo->IsActive && !LinkedTo->IsInLimbo) {
-						LinkedTo->Mark(MARK_DOWN);
-						LinkedTo->IsNewNavCom = false;
-					}
-				}
-			}
-			return;
-		}
-
-		LinkedTo->Set_Speed(1.0);
-
-		int speed = LinkedTo->Current_Speed();
-
-		DirType desired_facing = ::Direction(LinkedTo->Center_Coord(), HeadToCoord);
-		Do_Turn((DirStruct &)desired_facing);
-
-		if (LinkedTo->PrimaryFacing.Is_Rotating()) {
-			return;
-		}
-
-		if (LinkedTo->Occupies_Cells()) {
-			LinkedTo->Clear_Occupy_Bit(LinkedTo->Get_Coord());
-			LinkedTo->IsOccupyingCell = false;
-
-			LinkedTo->IsToPathAroundBlockage = false;
-
-		}
-
-		old_cell = LinkedTo->Get_Cell();
-
-		Coord new_coord = Move_Coord(LinkedTo->Get_Coord(), desired_facing, speed);
-		Cell new_cell = new_coord;
-
-		if (old_cell != new_cell) {
-
-			LinkedTo->Mark(MARK_UP);
-			LinkedTo->Set_Coord(new_coord);
-
-			CellClass * old_cellptr = &Map[old_cell];
-			CellClass * new_cellptr = &Map[new_cell];
-
-			if (new_cellptr->Height == old_cellptr->Height - BRIDGE_CELL_HEIGHT && new_cellptr->IsUnderBridge) {
-				LinkedTo->IsOnBridge = true;
-			}
-			if (!new_cellptr->IsUnderBridge && old_cellptr->IsUnderBridge) {
-				LinkedTo->IsOnBridge = false;
-			}
-
-			LinkedTo->HeightAGL = 0;
+			if (!LinkedTo->IsActive) return;
+			if (LinkedTo->IsInLimbo || LinkedTo->IsFalling) return;
+
+			if (LinkedTo->Path[0] != FACING_NONE && LinkedTo->Path[0] != FACING_COUNT) {
+				Cell check_coord = Adjacent_Cell(LinkedTo->Get_Cell(), LinkedTo->Path[0]);
+
+				CellClass * cellptr = &Map[check_coord];
+				if (cellptr->Overlay != OVERLAY_NONE) {
+					OverlayTypeClass * otype = OverlayTypes[cellptr->Overlay];
+					if ((LinkedTo->TClass->IsCrusher || LinkedTo->Has_Ability(ABILITY_CRUSHER)) && otype->HeapID == OVERLAY_SANDBAG_WALL) {
+						LinkedTo->IsCrushing = true;
+
+						if (LinkedTo->TClass->IsTiltsWhenCrushes) {
+							LinkedTo->RockingForwardsPerFrame = -0.01f;
+						}
+					}
+				}
+			}
+
+			if (!LinkedTo->IsActive || LinkedTo->IsInLimbo) return;
+
 			LinkedTo->Mark(MARK_DOWN);
-
-			Map[LinkedTo->Get_Coord()].Trigger_Veins();
 		} else {
-			bool was_down = LinkedTo->IsDown;
-			LinkedTo->IsDown = false;
-			LinkedTo->Set_Coord(new_coord);
-			LinkedTo->HeightAGL = 0;
-			LinkedTo->IsDown = was_down;
-			LinkedTo->IsNewNavCom = false;
-			return;
+
+			LinkedTo->Set_Speed(1.0);
+
+			int speed = LinkedTo->Current_Speed();
+
+			DirType desired_facing = ::Direction(LinkedTo->Center_Coord(), HeadToCoord);
+			Do_Turn((DirStruct &)desired_facing);
+
+			if (LinkedTo->PrimaryFacing.Is_Rotating()) {
+				return;
+			}
+
+			if (LinkedTo->Occupies_Cells()) {
+				LinkedTo->Clear_Occupy_Bit(LinkedTo->Get_Coord());
+				LinkedTo->IsOccupyingCell = false;
+				LinkedTo->IsToPathAroundBlockage = false;
+			}
+
+			Cell old_cell = LinkedTo->Get_Cell();
+
+			Coord new_coord = Move_Coord(LinkedTo->Get_Coord(), desired_facing, speed);
+			Cell new_cell = new_coord;
+
+			bool moved = (old_cell != new_cell);
+			if (moved) {
+				LinkedTo->Mark(MARK_UP);
+				LinkedTo->Set_Coord(new_coord);
+
+				CellClass * old_cellptr = &Map[old_cell];
+				CellClass * new_cellptr = &Map[new_cell];
+
+				if (new_cellptr->Height == old_cellptr->Height - BRIDGE_CELL_HEIGHT && new_cellptr->IsUnderBridge) {
+					LinkedTo->IsOnBridge = true;
+				}
+				if (!new_cellptr->IsUnderBridge && old_cellptr->IsUnderBridge) {
+					LinkedTo->IsOnBridge = false;
+				}
+
+				LinkedTo->HeightAGL = 0;
+				LinkedTo->Mark(MARK_DOWN);
+			} else {
+				bool was_down = LinkedTo->IsDown;
+				LinkedTo->IsDown = false;
+				LinkedTo->Set_Coord(new_coord);
+				LinkedTo->HeightAGL = 0;
+				LinkedTo->IsDown = was_down;
+			}
+
+			if (moved) {
+				Map[LinkedTo->Get_Coord()].Trigger_Veins();
+			}
 		}
 	}
-clear_new_nav:
-	LinkedTo->IsNewNavCom = false; // level-2 1.001: the common final store (see above)
+	LinkedTo->IsNewNavCom = false;
 }
```
