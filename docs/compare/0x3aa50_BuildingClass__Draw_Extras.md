# 0x3aa50 ?Draw_Extras@BuildingClass@@UAEXAAVPoint2D@@AAV?$TRect@H@@@Z (src/m85/src/building.cpp)

Origin: history: w293_x.claims.json. Community source: gibbo1b47a1_building.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -127,5 +127,5 @@
 			} else if (Class->AuxVoxel2.VoxLib != NULL && Class->AuxVoxel2.MotLib != NULL) {
 
-				Vector3 origin = Vector3(matrix.Get_X_Translation(), matrix.Get_Y_Translation(), matrix.Get_Z_Translation()); // RA2: as above
+				Vector3 origin = matrix.Get_Translation(); // meastes/redalert2-decomp, unknown_slot284 (1.006, GPL-3.0-or-later)
 				matrix.Translate(-origin); // RA2: as above
 
```

## 2. Our matched form against the community form

```diff
--- community
+++ ours matched
@@ -1,245 +1,178 @@
-void BuildingClass::Draw_Extras(Point2D & xy, Rect & rect)
-{
-	Cell cell = PositionCell;
-
-	// Draw a vehicle exiting through the factory door opening.
-	if (Mission == MISSION_UNLOAD
-		&& (Door.Is_Door_Opening() || Door.Is_Door_Open()
-			|| Door.Is_Door_Closed() || Door.Is_Door_Closing())
-		&& IsTethered) {
-
-		for (int index = 0; index < RadioLinks.Length(); index++) {
-			TechnoClass * techno = FUN_0065AD40(index);
-			if (techno != NULL && !techno->IsInLimbo
-				&& techno->RTTI != RTTI_BUILDING) {
-				Coord coord = techno->Destination_Coord();
-				coord.Z = techno->PositionCoord.Z;
-				if (!MainWindow || Debug_Map || !Scen->Special.IsFogOfWar
-					|| (!Map.IsLocationFogged(techno->PositionCoord)
-						&& !Map.IsLocationFogged(coord))) {
-					Point2D point;
-					TacticalMap->Coord_To_Pixel(techno->Render_Coord(), point);
-					techno->Draw_It(point, rect);
-				}
-			}
-		}
-	}
-
-	WORD tint = 0;
-	if (Airstrike != NULL) {
-		BYTE red = Rule->ColorAdd[Rule->LaserTargetColor].Get_Red();
-		BYTE green = Rule->ColorAdd[Rule->LaserTargetColor].Get_Green();
-		BYTE blue = Rule->ColorAdd[Rule->LaserTargetColor].Get_Blue();
-		switch (DSurface::Get_Primary_Color_Mode()) {
-		case 2:
-			tint = (((red << 6) | green) << 5) | blue;
-		case 1:
-			tint |= (((green >> 1) | (red << 5)) << 6) | blue;
-		default:
-			tint |= (((green >> 1) | (red << 5)) << 5) | blue;
-		}
-	}
-	if (IsIronCurtained() && ForceShielded == 1) {
-		BYTE red = Rule->ColorAdd[Rule->ForceShieldColor].Get_Red();
-		BYTE green = Rule->ColorAdd[Rule->ForceShieldColor].Get_Green();
-		BYTE blue = Rule->ColorAdd[Rule->ForceShieldColor].Get_Blue();
-		switch (DSurface::Get_Primary_Color_Mode()) {
-		case 2:
-			tint |= (((red << 6) | green) << 5) | blue;
-		case 1:
-			tint |= (((green >> 1) | (red << 5)) << 6) | blue;
-		default:
-			tint |= (((green >> 1) | (red << 5)) << 5) | blue;
-		}
-	}
-	if (Map[Center_Coord().As_Cell()].Is_Shrouded()) tint = 0;
-
-	// Draw the factory door animation.
-	if (Mission == MISSION_UNLOAD && Class->DoorAnim != NULL) {
-		if (Door.Is_Door_Closed() || Door.Is_Door_Opening()
-			|| Door.Is_Door_Closing() || Door.Is_Door_Open()) {
-
-			int shapenum = (int)(Door.Percent_Complete() * Class->DoorStages);
-			if (Door.Is_Door_Closing()) {
-				shapenum = Class->DoorStages - shapenum;
-			}
-			if (Door.Is_Door_Closed()) {
-				shapenum = 0;
-			}
-			if (shapenum >= Class->DoorStages) {
-				shapenum = Class->DoorStages - 1;
-			}
-			if (shapenum < 0) {
-				shapenum = 0;
-			}
-
-			if (HealthRatio <= Rule->ConditionYellow && Class->IsDamagedDoor) {
-				shapenum += Class->DoorStages;
-			}
-
-			int zadjust = -5 - Tactical::Z_Lepton_To_Pixel(Height);
-			Techno_Draw_Object(Class->DoorAnim, shapenum, xy, rect, DIR_N,
-				256, zadjust, ZGRAD_GROUND, false, Map[cell].Brightness);
-
-			if (Door.Is_Door_Closing() && shapenum == 0) {
-				IsToDisplay = true;
-			}
-		}
-	}
-
-	if (Class->IsTurretAnimAVoxel) {
-		bool construction = false;
-		if ((CurrentMission == MISSION_CONSTRUCTION
-				|| MissionQueue == MISSION_CONSTRUCTION)
-			&& Animation.Fetch_Stage()
-				< Class->Anims[BSTATE_CONSTRUCTION].Count
-					+ Class->Anims[BSTATE_CONSTRUCTION].Start - 1) {
-			construction = true;
-		}
-
-		if ((CurrentMission != MISSION_DECONSTRUCTION
-				|| Animation.Fetch_Stage() <= 0)
-			&& !construction || Class->IsArtillary) {
-
-			int key;
-			int barrel_key;
-			if (UseVoxelCache) {
-				key = PrimaryFacing.Current().As_Dir32();
-				barrel_key = PrimaryFacing.Current().As_Dir32();
-			} else {
-				key = -1;
-				barrel_key = -1;
-			}
-			int turret_frame = 0;
-			int barrel_frame = 0;
-			if (Class->AuxVoxel.MotLib != NULL) {
-				turret_frame =
-					TurretAnimFrame % Class->AuxVoxel.MotLib->Get_Frame_Count();
-			}
-			if (Class->AuxVoxel2.MotLib != NULL) {
-				barrel_frame =
-					TurretAnimFrame % Class->AuxVoxel2.MotLib->Get_Frame_Count();
-			}
-			key |= (turret_frame & 0xFF) << 16;
-			barrel_key |= (barrel_frame & 0xFF) << 16;
-			Matrix3D matrix;
-			matrix.Make_Identity();
-
-			if (Class->AuxVoxel.VoxLib != NULL) {
-				matrix.Rotate_Z(PrimaryFacing.Current().As_Radian32());
-				matrix.Translate_X(Class->TurretOffset / 8);
-
-				Matrix3D barrel_matrix;
-				barrel_matrix = matrix;
-				Vector3 vec2 = matrix.Get_Translation();
-				barrel_matrix.Translate(-vec2);
-				if (TurretRecoil.State != 0) {
-					matrix.Translate_X(-TurretRecoil.TravelSoFar);
-					key = -1;
-				}
-				if (BarrelRecoil.State != 0) {
-					barrel_matrix.Translate_X(-BarrelRecoil.TravelSoFar);
-					key = -1;
-				}
-				barrel_matrix.Rotate_Y(-(BarrelPitch.Current().As_Radian32()));
-				barrel_matrix.Translate(vec2);
-
-				Point2D drawpoint = xy + Point2D(
-					Class->AnimData[BANIM_TURRET].Location.X,
-					Class->AnimData[BANIM_TURRET].Location.Y);
-
-				VoxelDataStruct * voxl;
-				bool draw_barrel = Is_Barrel_Ahead(PrimaryFacing);
-				if (!draw_barrel) {
-					voxl = &Class->AuxVoxel2;
-					if (voxl->VoxLib != NULL && voxl->MotLib != NULL) {
-						Draw_Voxel(Class->AuxVoxel2, 0, key,
-							&Class->AuxVoxel2Index, rect, drawpoint,
-							Get_Isometric_View_Matrix() * barrel_matrix,
-							Map[cell].Brightness, tint, SHAPE_NORMAL);
-					}
-				}
-
-				Draw_Voxel(Class->AuxVoxel, turret_frame, key,
-					&Class->AuxVoxelIndex, rect, drawpoint,
-					Get_Isometric_View_Matrix() * matrix,
-					Map[cell].Brightness, tint, SHAPE_NORMAL);
-
-				if (draw_barrel) {
-					voxl = &Class->AuxVoxel2;
-					if (voxl->VoxLib != NULL && voxl->MotLib != NULL) {
-						Draw_Voxel(Class->AuxVoxel2, 0, key,
-							&Class->AuxVoxel2Index, rect, drawpoint,
-							Get_Isometric_View_Matrix() * barrel_matrix,
-							Map[cell].Brightness, tint, SHAPE_NORMAL);
-					}
-				}
-
-			} else if (Class->AuxVoxel2.VoxLib != NULL
-				&& Class->AuxVoxel2.MotLib != NULL) {
-				Vector3 vec2 = matrix.Get_Translation();
-				matrix.Translate(-vec2);
-				matrix.Rotate_Z(PrimaryFacing.Current().As_Radian32());
-				matrix.Rotate_Y(-(BarrelPitch.Current().As_Radian32()));
-				matrix.Translate(vec2);
-				Draw_Voxel(Class->AuxVoxel2, barrel_frame, barrel_key,
-					&Class->AuxVoxel2Index, rect,
-					xy + Point2D(Class->AnimData[BANIM_TURRET].Location.X,
-						Class->AnimData[BANIM_TURRET].Location.Y),
-					Get_Isometric_View_Matrix() * matrix,
-					Map[cell].Brightness, tint, SHAPE_NORMAL);
-			}
-		}
-
-	} else if (Class->IsBarrelAnimAVoxel) {
-		bool construction = false;
-		if ((CurrentMission == MISSION_CONSTRUCTION
-				|| MissionQueue == MISSION_CONSTRUCTION)
-			&& Animation.Fetch_Stage()
-				< Class->Anims[BSTATE_CONSTRUCTION].Count
-					+ Class->Anims[BSTATE_CONSTRUCTION].Start - 1) {
-			construction = true;
-		}
-
-		if ((CurrentMission != MISSION_DECONSTRUCTION
-				|| Animation.Fetch_Stage() <= 0)
-			&& !construction) {
-
-			static int _dir_adjust = 28;
-			static bool _make_visible = true;
-
-			Matrix3D matrix = Get_Barrel_Matrix();
-
-			int dir = (_dir_adjust + PrimaryFacing.Current().As_Dir32())
-				% (FACING_COUNT * 4);
-			bool in_front = (dir <= 16);
-			AnimClass * anim = Anims[BANIM_TURRET];
-
-			if (in_front) {
-				if (anim != NULL) {
-					if (_make_visible) {
-						anim->Make_Visible();
-					}
-					anim->Render(TacticalRect, true, false);
-					anim->Make_Invisible();
-				}
-			}
-
-			Draw_Voxel(Class->AuxVoxel2, 0, -1, &Class->VoxelIndex, rect,
-				xy + Point2D(Class->AnimData[BANIM_TURRET].Location.X,
-					Class->AnimData[BANIM_TURRET].Location.Y),
-				Get_Isometric_View_Matrix() * matrix,
-				Map[cell].Brightness, tint, SHAPE_NORMAL);
-
-			if (!in_front) {
-				if (anim != NULL) {
-					if (_make_visible) {
-						anim->Make_Visible();
-					}
-					anim->Render(TacticalRect, true, false);
-					anim->Make_Invisible();
-				}
-			}
-		}
-	}
+void BuildingClass::Draw_Extras(Point2D & xy, Rect & rect)
+{
+	Cell cell = Get_Cell(); // RA2: Get_Cell
+
+	/*
+	 * If a vehicle is currently exiting through the factory door, draw it through
+	 * the door opening.
+	 */
+	if (Get_Mission() == MISSION_UNLOAD // RA2: Get_Mission
+		&& (Door.Is_Door_Opening() || Door.Is_Door_Open() || Door.Is_Door_Closed() || Door.Is_Door_Closing())
+		&& IsTethered) {
+
+		for (int index = 0; index < RadioLinks.Length(); index++) { // RA2: every radio link, not just the first
+			TechnoClass * techno = ((BuildingClass const *)this)->Radio_Link(index); // RA2: the executable calls the const Radio_Link overload here
+			if (techno && !techno->IsInLimbo && techno->Fetch_RTTI() != RTTI_BUILDING) { // RA2: Fetch_RTTI
+
+				Coord coord = techno->Destination_Coord(NULL); // RA2: Destination_Coord takes the docker
+				coord.Z = techno->Get_Coord().Z; // RA2: Get_Coord
+
+				if (!MainWindow || Debug_Map || !Scen->Special.IsFogOfWar || (!Map.Is_Fogged(techno->Get_Coord()) && !Map.Is_Fogged(coord))) { // RA2: as above
+					Point2D point; // RA2: as above
+					TacticalMap->Coord_To_Pixel(techno->Render_Coord(), point); // RA2: as above
+					techno->Draw_It(point, rect); // RA2: as above
+				}
+			}
+		}
+	}
+
+	/*
+	 * Draw the factory door animation.
+	 */
+	if (Get_Mission() == MISSION_UNLOAD && Class->DoorAnim != NULL) { // RA2: as above
+
+		if (Door.Is_Door_Closed() || Door.Is_Door_Opening() || Door.Is_Door_Closing() || Door.Is_Door_Open()) {
+
+			int shapenum = (int)(Door.Percent_Complete() * Class->DoorStages);
+			if (Door.Is_Door_Closing()) {
+				shapenum = Class->DoorStages - shapenum;
+			}
+			if (Door.Is_Door_Closed()) {
+				shapenum = 0;
+			}
+			if (shapenum >= Class->DoorStages) {
+				shapenum = Class->DoorStages - 1;
+			}
+			if (shapenum < 0) {
+				shapenum = 0;
+			}
+
+			if (HealthRatio <= Rule->ConditionYellow && Class->IsDamagedDoor) {
+				shapenum += Class->DoorStages;
+			}
+
+			int zadjust = -5 - Tactical::Z_Lepton_To_Pixel(Get_Height()); // RA2: Get_Height
+			Techno_Draw_Object(Class->DoorAnim, shapenum, xy, rect, DIR_N, 256, zadjust, ZGRAD_GROUND, false, Map[cell].Brightness);
+
+			if (Door.Is_Door_Closing() && shapenum == 0) {
+				IsToDisplay = true;
+			}
+		}
+	}
+
+	if (Class->IsTurretAnimAVoxel) {
+
+		bool construction = false;
+		if ((CurrentMission == MISSION_CONSTRUCTION || MissionQueue == MISSION_CONSTRUCTION) && Fetch_Stage() < Class->Anims[BSTATE_CONSTRUCTION].Start + Class->Anims[BSTATE_CONSTRUCTION].Count - 1) { // RA2: Start first
+			construction = true;
+		}
+
+		if (((CurrentMission != MISSION_DECONSTRUCTION || Fetch_Stage() <= 0) && !construction) || Class->IsArtillary) { // RA2: as above
+
+			int key; // RA2: as above
+			if (UseVoxelCache) { // RA2: the key is the facing in 32 steps
+				key = PrimaryFacing.Current().As_Dir32(); // RA2: as above
+			} else {
+				key = -1; // RA2: as above
+			}
+
+			Matrix3D matrix;
+			matrix.Make_Identity();
+
+			if (Class->AuxVoxel.VoxLib != NULL) {
+
+				matrix.Rotate_Z(PrimaryFacing.Current().As_Radian32());
+				matrix.Translate_X(Class->TurretOffset / 8);
+
+				Matrix3D barrel_matrix = matrix; // RA2: no IsInRecoilState (not in RA2's layout)
+				Vector3 origin = Vector3(matrix.Get_X_Translation(), matrix.Get_Y_Translation(), matrix.Get_Z_Translation()); // RA2: as above
+				barrel_matrix.Translate(-origin); // RA2: as above
+
+				/*
+				**	A recoiling turret or barrel moves "backward" and takes the voxels out of the cache.
+				*/
+				if (TurretRecoil.State != 0) { // RA2: TurretRecoil
+					matrix.Translate_X(-TurretRecoil.TravelSoFar); // RA2: as above
+					key = -1; // RA2: as above
+				}
+				if (BarrelRecoil.State != 0) { // RA2: BarrelRecoil
+					barrel_matrix.Translate_X(-BarrelRecoil.TravelSoFar); // RA2: as above
+					key = -1; // RA2: as above
+				}
+
+				barrel_matrix.Rotate_Y(-(BarrelPitch.Current().As_Radian32()));
+				barrel_matrix.Translate(origin); // RA2: as above
+
+				Point2D drawpoint = xy + Point2D(Class->AnimData[BANIM_TURRET].Location.X, Class->AnimData[BANIM_TURRET].Location.Y); // RA2: the offset is rebuilt from its two components
+
+				VoxelDataStruct * voxl;
+				FacingClass & facing = PrimaryFacing; // level-2 1.001: the facing is held by reference for the barrel test (keeps the address out of the drawpoint statement)
+				bool draw_barrel = facing.Current().As_Dir4() > 0 && facing.Current().As_Dir4() < 3; // level-2 1.001: one full expression stored in the bool (gives the 1.001 frame slots)
+				if (!draw_barrel) {
+					voxl = &Class->AuxVoxel2;
+					if (voxl->VoxLib != NULL && voxl->MotLib != NULL) {
+						Draw_Voxel(Class->AuxVoxel2, 0, key, &Class->AuxVoxel2Index, rect, drawpoint, Get_Isometric_View_Matrix() * barrel_matrix, Map[cell].Brightness, SHAPE_NORMAL); // RA2: as above
+					}
+				}
+
+				Draw_Voxel(Class->AuxVoxel, 0, key, &Class->AuxVoxelIndex, rect, drawpoint, Get_Isometric_View_Matrix() * matrix, Map[cell].Brightness, SHAPE_NORMAL); // RA2: as above
+
+				if (draw_barrel) {
+					voxl = &Class->AuxVoxel2;
+					if (voxl->VoxLib != NULL && voxl->MotLib != NULL) {
+						Draw_Voxel(Class->AuxVoxel2, 0, key, &Class->AuxVoxel2Index, rect, drawpoint, Get_Isometric_View_Matrix() * barrel_matrix, Map[cell].Brightness, SHAPE_NORMAL); // RA2: as above
+					}
+				}
+
+			} else if (Class->AuxVoxel2.VoxLib != NULL && Class->AuxVoxel2.MotLib != NULL) {
+
+				Vector3 origin = matrix.Get_Translation(); // meastes/redalert2-decomp, unknown_slot284 (1.006, GPL-3.0-or-later)
+				matrix.Translate(-origin); // RA2: as above
+
+				matrix.Rotate_Z(PrimaryFacing.Current().As_Radian32());
+				matrix.Rotate_Y(-(BarrelPitch.Current().As_Radian32()));
+				matrix.Translate(origin); // RA2: as above
+
+				Point2D drawpoint = xy + Point2D(Class->AnimData[BANIM_TURRET].Location.X, Class->AnimData[BANIM_TURRET].Location.Y); // RA2: as above
+				Draw_Voxel(Class->AuxVoxel2, 0, key, &Class->AuxVoxel2Index, rect, drawpoint, Get_Isometric_View_Matrix() * matrix, Map[cell].Brightness, SHAPE_NORMAL); // RA2: as above
+			}
+		}
+
+	} else if (Class->IsBarrelAnimAVoxel) {
+
+		bool construction = false;
+		if ((CurrentMission == MISSION_CONSTRUCTION || MissionQueue == MISSION_CONSTRUCTION) && Fetch_Stage() < Class->Anims[BSTATE_CONSTRUCTION].Start + Class->Anims[BSTATE_CONSTRUCTION].Count - 1) { // RA2: as above
+			construction = true;
+		}
+
+		if ((CurrentMission != MISSION_DECONSTRUCTION || Fetch_Stage() <= 0) && !construction) {
+
+			static int _dir_adjust = 28;
+			static bool _make_visible = true;
+
+			Matrix3D matrix = Get_Barrel_Matrix();
+
+			int dir = (_dir_adjust + PrimaryFacing.Current().As_Dir32()) % (FACING_COUNT * 4);
+			bool in_front = (dir <= 16);
+			AnimClass * anim = Anims[BANIM_TURRET];
+
+			if (in_front && anim != NULL) { // RA2: as above
+				if (_make_visible) { // RA2: as above
+					anim->Make_Visible(); // RA2: as above
+				}
+				anim->Render(TacticalRect, true, false); // RA2: as above
+				anim->Make_Invisible(); // RA2: as above
+			}
+
+			Draw_Voxel(Class->AuxVoxel2, 0, -1, &Class->VoxelIndex, rect, xy + Point2D(Class->AnimData[BANIM_TURRET].Location.X, Class->AnimData[BANIM_TURRET].Location.Y), Get_Isometric_View_Matrix() * matrix, Map[cell].Brightness, SHAPE_NORMAL); // RA2: as above
+
+			if (!in_front && anim != NULL) { // RA2: as above
+				if (_make_visible) { // RA2: as above
+					anim->Make_Visible(); // RA2: as above
+				}
+				anim->Render(TacticalRect, true, false); // RA2: as above
+				anim->Make_Invisible(); // RA2: as above
+			}
+		}
+	}
 }
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -1,178 +1,245 @@
-void BuildingClass::Draw_Extras(Point2D & xy, Rect & rect)
-{
-	Cell cell = Get_Cell(); // RA2: Get_Cell
-
-	/*
-	 * If a vehicle is currently exiting through the factory door, draw it through
-	 * the door opening.
-	 */
-	if (Get_Mission() == MISSION_UNLOAD // RA2: Get_Mission
-		&& (Door.Is_Door_Opening() || Door.Is_Door_Open() || Door.Is_Door_Closed() || Door.Is_Door_Closing())
-		&& IsTethered) {
-
-		for (int index = 0; index < RadioLinks.Length(); index++) { // RA2: every radio link, not just the first
-			TechnoClass * techno = ((BuildingClass const *)this)->Radio_Link(index); // RA2: the executable calls the const Radio_Link overload here
-			if (techno && !techno->IsInLimbo && techno->Fetch_RTTI() != RTTI_BUILDING) { // RA2: Fetch_RTTI
-
-				Coord coord = techno->Destination_Coord(NULL); // RA2: Destination_Coord takes the docker
-				coord.Z = techno->Get_Coord().Z; // RA2: Get_Coord
-
-				if (!MainWindow || Debug_Map || !Scen->Special.IsFogOfWar || (!Map.Is_Fogged(techno->Get_Coord()) && !Map.Is_Fogged(coord))) { // RA2: as above
-					Point2D point; // RA2: as above
-					TacticalMap->Coord_To_Pixel(techno->Render_Coord(), point); // RA2: as above
-					techno->Draw_It(point, rect); // RA2: as above
-				}
-			}
-		}
-	}
-
-	/*
-	 * Draw the factory door animation.
-	 */
-	if (Get_Mission() == MISSION_UNLOAD && Class->DoorAnim != NULL) { // RA2: as above
-
-		if (Door.Is_Door_Closed() || Door.Is_Door_Opening() || Door.Is_Door_Closing() || Door.Is_Door_Open()) {
-
-			int shapenum = (int)(Door.Percent_Complete() * Class->DoorStages);
-			if (Door.Is_Door_Closing()) {
-				shapenum = Class->DoorStages - shapenum;
-			}
-			if (Door.Is_Door_Closed()) {
-				shapenum = 0;
-			}
-			if (shapenum >= Class->DoorStages) {
-				shapenum = Class->DoorStages - 1;
-			}
-			if (shapenum < 0) {
-				shapenum = 0;
-			}
-
-			if (HealthRatio <= Rule->ConditionYellow && Class->IsDamagedDoor) {
-				shapenum += Class->DoorStages;
-			}
-
-			int zadjust = -5 - Tactical::Z_Lepton_To_Pixel(Get_Height()); // RA2: Get_Height
-			Techno_Draw_Object(Class->DoorAnim, shapenum, xy, rect, DIR_N, 256, zadjust, ZGRAD_GROUND, false, Map[cell].Brightness);
-
-			if (Door.Is_Door_Closing() && shapenum == 0) {
-				IsToDisplay = true;
-			}
-		}
-	}
-
-	if (Class->IsTurretAnimAVoxel) {
-
-		bool construction = false;
-		if ((CurrentMission == MISSION_CONSTRUCTION || MissionQueue == MISSION_CONSTRUCTION) && Fetch_Stage() < Class->Anims[BSTATE_CONSTRUCTION].Start + Class->Anims[BSTATE_CONSTRUCTION].Count - 1) { // RA2: Start first
-			construction = true;
-		}
-
-		if (((CurrentMission != MISSION_DECONSTRUCTION || Fetch_Stage() <= 0) && !construction) || Class->IsArtillary) { // RA2: as above
-
-			int key; // RA2: as above
-			if (UseVoxelCache) { // RA2: the key is the facing in 32 steps
-				key = PrimaryFacing.Current().As_Dir32(); // RA2: as above
-			} else {
-				key = -1; // RA2: as above
-			}
-
-			Matrix3D matrix;
-			matrix.Make_Identity();
-
-			if (Class->AuxVoxel.VoxLib != NULL) {
-
-				matrix.Rotate_Z(PrimaryFacing.Current().As_Radian32());
-				matrix.Translate_X(Class->TurretOffset / 8);
-
-				Matrix3D barrel_matrix = matrix; // RA2: no IsInRecoilState (not in RA2's layout)
-				Vector3 origin = Vector3(matrix.Get_X_Translation(), matrix.Get_Y_Translation(), matrix.Get_Z_Translation()); // RA2: as above
-				barrel_matrix.Translate(-origin); // RA2: as above
-
-				/*
-				**	A recoiling turret or barrel moves "backward" and takes the voxels out of the cache.
-				*/
-				if (TurretRecoil.State != 0) { // RA2: TurretRecoil
-					matrix.Translate_X(-TurretRecoil.TravelSoFar); // RA2: as above
-					key = -1; // RA2: as above
-				}
-				if (BarrelRecoil.State != 0) { // RA2: BarrelRecoil
-					barrel_matrix.Translate_X(-BarrelRecoil.TravelSoFar); // RA2: as above
-					key = -1; // RA2: as above
-				}
-
-				barrel_matrix.Rotate_Y(-(BarrelPitch.Current().As_Radian32()));
-				barrel_matrix.Translate(origin); // RA2: as above
-
-				Point2D drawpoint = xy + Point2D(Class->AnimData[BANIM_TURRET].Location.X, Class->AnimData[BANIM_TURRET].Location.Y); // RA2: the offset is rebuilt from its two components
-
-				VoxelDataStruct * voxl;
-				FacingClass & facing = PrimaryFacing; // level-2 1.001: the facing is held by reference for the barrel test (keeps the address out of the drawpoint statement)
-				bool draw_barrel = facing.Current().As_Dir4() > 0 && facing.Current().As_Dir4() < 3; // level-2 1.001: one full expression stored in the bool (gives the 1.001 frame slots)
-				if (!draw_barrel) {
-					voxl = &Class->AuxVoxel2;
-					if (voxl->VoxLib != NULL && voxl->MotLib != NULL) {
-						Draw_Voxel(Class->AuxVoxel2, 0, key, &Class->AuxVoxel2Index, rect, drawpoint, Get_Isometric_View_Matrix() * barrel_matrix, Map[cell].Brightness, SHAPE_NORMAL); // RA2: as above
-					}
-				}
-
-				Draw_Voxel(Class->AuxVoxel, 0, key, &Class->AuxVoxelIndex, rect, drawpoint, Get_Isometric_View_Matrix() * matrix, Map[cell].Brightness, SHAPE_NORMAL); // RA2: as above
-
-				if (draw_barrel) {
-					voxl = &Class->AuxVoxel2;
-					if (voxl->VoxLib != NULL && voxl->MotLib != NULL) {
-						Draw_Voxel(Class->AuxVoxel2, 0, key, &Class->AuxVoxel2Index, rect, drawpoint, Get_Isometric_View_Matrix() * barrel_matrix, Map[cell].Brightness, SHAPE_NORMAL); // RA2: as above
-					}
-				}
-
-			} else if (Class->AuxVoxel2.VoxLib != NULL && Class->AuxVoxel2.MotLib != NULL) {
-
-				Vector3 origin = Vector3(matrix.Get_X_Translation(), matrix.Get_Y_Translation(), matrix.Get_Z_Translation()); // RA2: as above
-				matrix.Translate(-origin); // RA2: as above
-
-				matrix.Rotate_Z(PrimaryFacing.Current().As_Radian32());
-				matrix.Rotate_Y(-(BarrelPitch.Current().As_Radian32()));
-				matrix.Translate(origin); // RA2: as above
-
-				Point2D drawpoint = xy + Point2D(Class->AnimData[BANIM_TURRET].Location.X, Class->AnimData[BANIM_TURRET].Location.Y); // RA2: as above
-				Draw_Voxel(Class->AuxVoxel2, 0, key, &Class->AuxVoxel2Index, rect, drawpoint, Get_Isometric_View_Matrix() * matrix, Map[cell].Brightness, SHAPE_NORMAL); // RA2: as above
-			}
-		}
-
-	} else if (Class->IsBarrelAnimAVoxel) {
-
-		bool construction = false;
-		if ((CurrentMission == MISSION_CONSTRUCTION || MissionQueue == MISSION_CONSTRUCTION) && Fetch_Stage() < Class->Anims[BSTATE_CONSTRUCTION].Start + Class->Anims[BSTATE_CONSTRUCTION].Count - 1) { // RA2: as above
-			construction = true;
-		}
-
-		if ((CurrentMission != MISSION_DECONSTRUCTION || Fetch_Stage() <= 0) && !construction) {
-
-			static int _dir_adjust = 28;
-			static bool _make_visible = true;
-
-			Matrix3D matrix = Get_Barrel_Matrix();
-
-			int dir = (_dir_adjust + PrimaryFacing.Current().As_Dir32()) % (FACING_COUNT * 4);
-			bool in_front = (dir <= 16);
-			AnimClass * anim = Anims[BANIM_TURRET];
-
-			if (in_front && anim != NULL) { // RA2: as above
-				if (_make_visible) { // RA2: as above
-					anim->Make_Visible(); // RA2: as above
-				}
-				anim->Render(TacticalRect, true, false); // RA2: as above
-				anim->Make_Invisible(); // RA2: as above
-			}
-
-			Draw_Voxel(Class->AuxVoxel2, 0, -1, &Class->VoxelIndex, rect, xy + Point2D(Class->AnimData[BANIM_TURRET].Location.X, Class->AnimData[BANIM_TURRET].Location.Y), Get_Isometric_View_Matrix() * matrix, Map[cell].Brightness, SHAPE_NORMAL); // RA2: as above
-
-			if (!in_front && anim != NULL) { // RA2: as above
-				if (_make_visible) { // RA2: as above
-					anim->Make_Visible(); // RA2: as above
-				}
-				anim->Render(TacticalRect, true, false); // RA2: as above
-				anim->Make_Invisible(); // RA2: as above
-			}
-		}
-	}
+void BuildingClass::Draw_Extras(Point2D & xy, Rect & rect)
+{
+	Cell cell = PositionCell;
+
+	// Draw a vehicle exiting through the factory door opening.
+	if (Mission == MISSION_UNLOAD
+		&& (Door.Is_Door_Opening() || Door.Is_Door_Open()
+			|| Door.Is_Door_Closed() || Door.Is_Door_Closing())
+		&& IsTethered) {
+
+		for (int index = 0; index < RadioLinks.Length(); index++) {
+			TechnoClass * techno = FUN_0065AD40(index);
+			if (techno != NULL && !techno->IsInLimbo
+				&& techno->RTTI != RTTI_BUILDING) {
+				Coord coord = techno->Destination_Coord();
+				coord.Z = techno->PositionCoord.Z;
+				if (!MainWindow || Debug_Map || !Scen->Special.IsFogOfWar
+					|| (!Map.IsLocationFogged(techno->PositionCoord)
+						&& !Map.IsLocationFogged(coord))) {
+					Point2D point;
+					TacticalMap->Coord_To_Pixel(techno->Render_Coord(), point);
+					techno->Draw_It(point, rect);
+				}
+			}
+		}
+	}
+
+	WORD tint = 0;
+	if (Airstrike != NULL) {
+		BYTE red = Rule->ColorAdd[Rule->LaserTargetColor].Get_Red();
+		BYTE green = Rule->ColorAdd[Rule->LaserTargetColor].Get_Green();
+		BYTE blue = Rule->ColorAdd[Rule->LaserTargetColor].Get_Blue();
+		switch (DSurface::Get_Primary_Color_Mode()) {
+		case 2:
+			tint = (((red << 6) | green) << 5) | blue;
+		case 1:
+			tint |= (((green >> 1) | (red << 5)) << 6) | blue;
+		default:
+			tint |= (((green >> 1) | (red << 5)) << 5) | blue;
+		}
+	}
+	if (IsIronCurtained() && ForceShielded == 1) {
+		BYTE red = Rule->ColorAdd[Rule->ForceShieldColor].Get_Red();
+		BYTE green = Rule->ColorAdd[Rule->ForceShieldColor].Get_Green();
+		BYTE blue = Rule->ColorAdd[Rule->ForceShieldColor].Get_Blue();
+		switch (DSurface::Get_Primary_Color_Mode()) {
+		case 2:
+			tint |= (((red << 6) | green) << 5) | blue;
+		case 1:
+			tint |= (((green >> 1) | (red << 5)) << 6) | blue;
+		default:
+			tint |= (((green >> 1) | (red << 5)) << 5) | blue;
+		}
+	}
+	if (Map[Center_Coord().As_Cell()].Is_Shrouded()) tint = 0;
+
+	// Draw the factory door animation.
+	if (Mission == MISSION_UNLOAD && Class->DoorAnim != NULL) {
+		if (Door.Is_Door_Closed() || Door.Is_Door_Opening()
+			|| Door.Is_Door_Closing() || Door.Is_Door_Open()) {
+
+			int shapenum = (int)(Door.Percent_Complete() * Class->DoorStages);
+			if (Door.Is_Door_Closing()) {
+				shapenum = Class->DoorStages - shapenum;
+			}
+			if (Door.Is_Door_Closed()) {
+				shapenum = 0;
+			}
+			if (shapenum >= Class->DoorStages) {
+				shapenum = Class->DoorStages - 1;
+			}
+			if (shapenum < 0) {
+				shapenum = 0;
+			}
+
+			if (HealthRatio <= Rule->ConditionYellow && Class->IsDamagedDoor) {
+				shapenum += Class->DoorStages;
+			}
+
+			int zadjust = -5 - Tactical::Z_Lepton_To_Pixel(Height);
+			Techno_Draw_Object(Class->DoorAnim, shapenum, xy, rect, DIR_N,
+				256, zadjust, ZGRAD_GROUND, false, Map[cell].Brightness);
+
+			if (Door.Is_Door_Closing() && shapenum == 0) {
+				IsToDisplay = true;
+			}
+		}
+	}
+
+	if (Class->IsTurretAnimAVoxel) {
+		bool construction = false;
+		if ((CurrentMission == MISSION_CONSTRUCTION
+				|| MissionQueue == MISSION_CONSTRUCTION)
+			&& Animation.Fetch_Stage()
+				< Class->Anims[BSTATE_CONSTRUCTION].Count
+					+ Class->Anims[BSTATE_CONSTRUCTION].Start - 1) {
+			construction = true;
+		}
+
+		if ((CurrentMission != MISSION_DECONSTRUCTION
+				|| Animation.Fetch_Stage() <= 0)
+			&& !construction || Class->IsArtillary) {
+
+			int key;
+			int barrel_key;
+			if (UseVoxelCache) {
+				key = PrimaryFacing.Current().As_Dir32();
+				barrel_key = PrimaryFacing.Current().As_Dir32();
+			} else {
+				key = -1;
+				barrel_key = -1;
+			}
+			int turret_frame = 0;
+			int barrel_frame = 0;
+			if (Class->AuxVoxel.MotLib != NULL) {
+				turret_frame =
+					TurretAnimFrame % Class->AuxVoxel.MotLib->Get_Frame_Count();
+			}
+			if (Class->AuxVoxel2.MotLib != NULL) {
+				barrel_frame =
+					TurretAnimFrame % Class->AuxVoxel2.MotLib->Get_Frame_Count();
+			}
+			key |= (turret_frame & 0xFF) << 16;
+			barrel_key |= (barrel_frame & 0xFF) << 16;
+			Matrix3D matrix;
+			matrix.Make_Identity();
+
+			if (Class->AuxVoxel.VoxLib != NULL) {
+				matrix.Rotate_Z(PrimaryFacing.Current().As_Radian32());
+				matrix.Translate_X(Class->TurretOffset / 8);
+
+				Matrix3D barrel_matrix;
+				barrel_matrix = matrix;
+				Vector3 vec2 = matrix.Get_Translation();
+				barrel_matrix.Translate(-vec2);
+				if (TurretRecoil.State != 0) {
+					matrix.Translate_X(-TurretRecoil.TravelSoFar);
+					key = -1;
+				}
+				if (BarrelRecoil.State != 0) {
+					barrel_matrix.Translate_X(-BarrelRecoil.TravelSoFar);
+					key = -1;
+				}
+				barrel_matrix.Rotate_Y(-(BarrelPitch.Current().As_Radian32()));
+				barrel_matrix.Translate(vec2);
+
+				Point2D drawpoint = xy + Point2D(
+					Class->AnimData[BANIM_TURRET].Location.X,
+					Class->AnimData[BANIM_TURRET].Location.Y);
+
+				VoxelDataStruct * voxl;
+				bool draw_barrel = Is_Barrel_Ahead(PrimaryFacing);
+				if (!draw_barrel) {
+					voxl = &Class->AuxVoxel2;
+					if (voxl->VoxLib != NULL && voxl->MotLib != NULL) {
+						Draw_Voxel(Class->AuxVoxel2, 0, key,
+							&Class->AuxVoxel2Index, rect, drawpoint,
+							Get_Isometric_View_Matrix() * barrel_matrix,
+							Map[cell].Brightness, tint, SHAPE_NORMAL);
+					}
+				}
+
+				Draw_Voxel(Class->AuxVoxel, turret_frame, key,
+					&Class->AuxVoxelIndex, rect, drawpoint,
+					Get_Isometric_View_Matrix() * matrix,
+					Map[cell].Brightness, tint, SHAPE_NORMAL);
+
+				if (draw_barrel) {
+					voxl = &Class->AuxVoxel2;
+					if (voxl->VoxLib != NULL && voxl->MotLib != NULL) {
+						Draw_Voxel(Class->AuxVoxel2, 0, key,
+							&Class->AuxVoxel2Index, rect, drawpoint,
+							Get_Isometric_View_Matrix() * barrel_matrix,
+							Map[cell].Brightness, tint, SHAPE_NORMAL);
+					}
+				}
+
+			} else if (Class->AuxVoxel2.VoxLib != NULL
+				&& Class->AuxVoxel2.MotLib != NULL) {
+				Vector3 vec2 = matrix.Get_Translation();
+				matrix.Translate(-vec2);
+				matrix.Rotate_Z(PrimaryFacing.Current().As_Radian32());
+				matrix.Rotate_Y(-(BarrelPitch.Current().As_Radian32()));
+				matrix.Translate(vec2);
+				Draw_Voxel(Class->AuxVoxel2, barrel_frame, barrel_key,
+					&Class->AuxVoxel2Index, rect,
+					xy + Point2D(Class->AnimData[BANIM_TURRET].Location.X,
+						Class->AnimData[BANIM_TURRET].Location.Y),
+					Get_Isometric_View_Matrix() * matrix,
+					Map[cell].Brightness, tint, SHAPE_NORMAL);
+			}
+		}
+
+	} else if (Class->IsBarrelAnimAVoxel) {
+		bool construction = false;
+		if ((CurrentMission == MISSION_CONSTRUCTION
+				|| MissionQueue == MISSION_CONSTRUCTION)
+			&& Animation.Fetch_Stage()
+				< Class->Anims[BSTATE_CONSTRUCTION].Count
+					+ Class->Anims[BSTATE_CONSTRUCTION].Start - 1) {
+			construction = true;
+		}
+
+		if ((CurrentMission != MISSION_DECONSTRUCTION
+				|| Animation.Fetch_Stage() <= 0)
+			&& !construction) {
+
+			static int _dir_adjust = 28;
+			static bool _make_visible = true;
+
+			Matrix3D matrix = Get_Barrel_Matrix();
+
+			int dir = (_dir_adjust + PrimaryFacing.Current().As_Dir32())
+				% (FACING_COUNT * 4);
+			bool in_front = (dir <= 16);
+			AnimClass * anim = Anims[BANIM_TURRET];
+
+			if (in_front) {
+				if (anim != NULL) {
+					if (_make_visible) {
+						anim->Make_Visible();
+					}
+					anim->Render(TacticalRect, true, false);
+					anim->Make_Invisible();
+				}
+			}
+
+			Draw_Voxel(Class->AuxVoxel2, 0, -1, &Class->VoxelIndex, rect,
+				xy + Point2D(Class->AnimData[BANIM_TURRET].Location.X,
+					Class->AnimData[BANIM_TURRET].Location.Y),
+				Get_Isometric_View_Matrix() * matrix,
+				Map[cell].Brightness, tint, SHAPE_NORMAL);
+
+			if (!in_front) {
+				if (anim != NULL) {
+					if (_make_visible) {
+						anim->Make_Visible();
+					}
+					anim->Render(TacticalRect, true, false);
+					anim->Make_Invisible();
+				}
+			}
+		}
+	}
 }
```
