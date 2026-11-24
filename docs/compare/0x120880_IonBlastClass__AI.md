# 0x120880 ?AI@IonBlastClass@@QAEXXZ (src/m85/src/ionblast.cpp)

Origin: history: w271_x.claims.json. Community source: gibbo232414_ionblast.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -19,8 +19,5 @@
 
 			if (Map[Position].IsUnderBridge) { // RA2: as above
-				Coord coord; // RA2: declared where it is used
-				coord.X = Position.X; // RA2: as above
-				coord.Z = BRIDGE_LEPTON_HEIGHT + Position.Z; // RA2: as above
-				coord.Y = Position.Y; // RA2: as above
+				Coord coord = Coord(Position.X, Position.Y, IonBridgeLeptonHeight + Position.Z); // level-2 1.001: the constructor form (meastes)
 				Explosion_Damage(coord, Rule->IonCannonDamage, NULL, Rule->IonCannonWarhead, true); // RA2: as above
 			}
@@ -30,10 +27,11 @@
 		}
 
-		Cell center(Position); // RA2: as above
+		Cell center = Position.As_Cell(); // level-2 1.001: the conversion called directly, one inline level less than Cell(Coord) (meastes)
 
 		for (int x_offset = -3; x_offset < 4; x_offset++) { // RA2: as above
 			for (int y_offset = -3; y_offset < 4; y_offset++) { // RA2: as above
 
-				FootClass * occupier = (FootClass *)Map[center + Cell(x_offset, y_offset)].Cell_Occupier(); // RA2: as above
+				CellClass & cell = Map[center + Cell(x_offset, y_offset)]; // level-2 1.001: a named cell reference (meastes)
+				ObjectClass * occupier = cell.Cell_Occupier(); // RA2: as above
 
 				while (occupier != NULL) { // RA2: as above
@@ -41,4 +39,5 @@
 					if (occupier->Fetch_RTTI() == RTTI_INFANTRY || occupier->Fetch_RTTI() == RTTI_UNIT) { // RA2: the exe tests the RTTI (15 then 1), not dynamic_cast
 
+						FootClass * foot = (FootClass *)occupier; // level-2 1.001: the typed pointer is a second variable (meastes)
 						Point2D occupier_point; // RA2: as above
 						TacticalMap->Coord_To_Pixel(occupier->Get_Coord(), occupier_point); // RA2: as above
@@ -53,8 +52,8 @@
 							if (*displacement > 0) { // RA2: as above
 
-								occupier->Set_Speed(0.0); // RA2: no weapons factory exemption; the blast always stops the unit
+								foot->Set_Speed(0.0); // RA2: no weapons factory exemption; the blast always stops the unit
 
 								int draw_offset = Spiral_Index_To_Point(*displacement).Y; // RA2: as above
-								occupier->IonBlastYDrawOffset = 2 * draw_offset; // RA2: as above
+								foot->IonBlastYDrawOffset = 2 * draw_offset; // RA2: as above
 							}
 
@@ -76,7 +75,8 @@
 								Vector3 flat = to_blast; // RA2: as above
 
-								double facing_rad = occupier->PrimaryFacing.Current().As_Radian(); // RA2: as above
+								double facing_rad = foot->PrimaryFacing.Current().As_Radian(); // RA2: as above
 								float facing_sin = (float)fastmath::sin(facing_rad); // RA2: as above
-								float facing_cos = (float)fastmath::cos(facing_rad); // RA2: as above
+								Vector3 facing; // level-2 1.001: the cosine lives in a Vector3 (meastes)
+								facing.X = (float)fastmath::cos(facing_rad); // RA2: as above
 
 								float blast_dist = fastmath::sqrt((double)to_blast.X * to_blast.X + (double)to_blast.Y * to_blast.Y + (double)to_blast.Z * to_blast.Z); // RA2: written out instead of Vector3::Length
@@ -86,5 +86,5 @@
 									flat.Z = 0.0; // RA2: as above
 
-									double flat_len = fastmath::sqrt(flat.Y * flat.Y + flat.X * flat.X); // RA2: as above
+									double flat_len = fastmath::sqrt(flat.X * flat.X + flat.Y * flat.Y); // RA2: as above
 
 									Vector3 normal; // RA2: as above
@@ -95,11 +95,13 @@
 									}
 
-									float forwards = normal.X * facing_cos + normal.Y * facing_sin; // RA2: as above
-									float sideways_zsin = -(normal.Z * facing_sin); // RA2: as above
-									float sideways_zcos = normal.Z * facing_cos; // level-2 1.001: float (1.006: double)
-									float sideways_y = normal.X * facing_sin - normal.Y * facing_cos; // level-2 1.001: float (1.006: double)
-									float sideways = (float)fastmath::sqrt(sideways_zsin * sideways_zsin + sideways_zcos * sideways_zcos + sideways_y * sideways_y); // RA2: as above
-									if (fabs(facing_cos * forwards - facing_sin * sideways - normal.X) > 0.0002 // RA2: as above
-										|| fabs(facing_cos * sideways + facing_sin * forwards - normal.Y) > 0.0002) { // RA2: as above
+									float forwards = normal.X * facing.X + normal.Y * facing_sin; // RA2: as above
+									float sideways = Length_Of(Vector3(-(normal.Z * facing_sin), normal.Z * facing.X, normal.X * facing_sin - normal.Y * facing.X)); // level-2 1.001: the length helper on a Vector3 temporary (meastes)
+
+									float c2 = facing.X; // level-2 1.001: the rotation terms are copied to locals (meastes)
+									float s2 = facing_sin;
+									float c3 = facing.X;
+									float s3 = facing_sin;
+									if (fabs(c2 * forwards - s2 * sideways - normal.X) > 0.0002 // RA2: as above
+										|| fabs(c3 * sideways + s3 * forwards - normal.Y) > 0.0002) { // RA2: as above
 										sideways = -sideways; // RA2: as above
 									}
@@ -110,6 +112,6 @@
 									double slope = ((phase_cos * WaveFrequency * WaveAmplitudeFalloff * 3.5) * decay - height) / (decay * decay); // RA2: as above
 
-									occupier->AngleRotatedSideways = (float)(sideways * slope * WaveRockScale); // RA2: as above
-									occupier->AngleRotatedForwards = (float)(-(forwards * slope * WaveRockScale)); // RA2: as above
+									foot->AngleRotatedSideways = (float)(sideways * slope * WaveRockScale); // RA2: as above
+									foot->AngleRotatedForwards = (float)(-(forwards * slope * WaveRockScale)); // RA2: as above
 								}
 							}
@@ -117,5 +119,5 @@
 					}
 
-					occupier = (FootClass *)occupier->Next; // RA2: as above
+					occupier = occupier->Next; // RA2: as above
 				}
 			}
```

## 2. Our matched form against the community form

```diff
--- community
+++ ours matched
@@ -1,3 +1,3 @@
-void IonBlastClass::AI()
+void IonBlastClass::AI(void)
 {
 	if (Lifetime >= 79) {
@@ -6,155 +6,118 @@
 	}
 
-	if (DisableIonBeam != 1) {
-		Point2D point;
-		TacticalMap->Coord_To_Pixel(Position, point);
+	if (DisableIonBeam != 1) { // RA2: a blast with the word at +0x10 set only ages; the body below sits one level deeper
+		Point2D point; // RA2: as above
+		TacticalMap->Coord_To_Pixel(Position, point); // RA2: the result is not tested and Map.ScreenY is not touched
 
-		if (Lifetime == 0) {
-			if (Map[Position].Land_Type() == 2) {
-				new AnimClass(
-					Rule->SplashList[Rule->SplashList.Count() - 1],
-					Position + Coord(0, 0, 5), 0, 1,
-					ShapeFlags_Type(SHAPE_CENTER | SHAPE_WIN_REL), 0);
+		if (Lifetime == 0) { // RA2: as above
+			if (Map[Position].Land_Type() == LAND_WATER) { // RA2: as above
+				new AnimClass(Rule->SplashList[Rule->SplashList.Count() - 1], Position + Coord(0,0,5), 0, 1, (ShapeFlags_Type)(SHAPE_CENTER|SHAPE_WIN_REL), 0); // RA2: as above
 			} else {
-				new AnimClass(
-					Rule->IonBlast, Position + Coord(0, 0, 5), 0, 1,
-					ShapeFlags_Type(SHAPE_CENTER | SHAPE_WIN_REL), 0);
+				new AnimClass(Rule->IonBlast, Position + Coord(0,0,5), 0, 1, (ShapeFlags_Type)(SHAPE_CENTER|SHAPE_WIN_REL), 0); // RA2: as above
+			}
+			new AnimClass(Rule->IonBeam, Position + Coord(0,0,5), 0, 1, (ShapeFlags_Type)(SHAPE_CENTER|SHAPE_WIN_REL), 0); // RA2: as above
+
+			if (Map[Position].IsUnderBridge) { // RA2: as above
+				Coord coord = Coord(Position.X, Position.Y, IonBridgeLeptonHeight + Position.Z); // level-2 1.001: the constructor form (meastes)
+				Explosion_Damage(coord, Rule->IonCannonDamage, NULL, Rule->IonCannonWarhead, true); // RA2: as above
 			}
 
-			new AnimClass(
-				Rule->IonBeam, Position + Coord(0, 0, 5), 0, 1,
-				ShapeFlags_Type(SHAPE_CENTER | SHAPE_WIN_REL), 0);
-
-			if (Map[Position].IsUnderBridge) {
-				Coord coord = Coord(
-					Position.X, Position.Y,
-					BRIDGE_LEPTON_HEIGHT + Position.Z);
-				Explosion_Damage(
-					coord, Rule->IonCannonDamage, 0,
-					Rule->IonCannonWarhead, 1);
-			}
-
-			Explosion_Damage(
-				Position, Rule->IonCannonDamage, 0,
-				Rule->IonCannonWarhead, 1);
-			Combat_Lighting(
-				Position, Rule->IonCannonDamage,
-				Rule->IonCannonWarhead, 0, 0);
+			Explosion_Damage(Position, Rule->IonCannonDamage, NULL, Rule->IonCannonWarhead, true); // RA2: as above
+			Combat_Lighting(Position, Rule->IonCannonDamage, Rule->IonCannonWarhead, 0, 0); // RA2: the five argument form
 		}
 
-		Cell const &center = Position.As_Cell();
+		Cell center = Position.As_Cell(); // level-2 1.001: the conversion called directly, one inline level less than Cell(Coord) (meastes)
 
-		for (int x_offset = -3; x_offset < 4; x_offset++) {
-			for (int y_offset = -3; y_offset < 4; y_offset++) {
-				CellClass &cell = Map[center + Cell(x_offset, y_offset)];
-				ObjectClass *occupier = cell.Cell_Occupier();
+		for (int x_offset = -3; x_offset < 4; x_offset++) { // RA2: as above
+			for (int y_offset = -3; y_offset < 4; y_offset++) { // RA2: as above
 
-				while (occupier != 0) {
-					if (occupier->Fetch_RTTI() == RTTI_INFANTRY ||
-						occupier->Fetch_RTTI() == RTTI_UNIT) {
-						FootClass *foot = (FootClass *)occupier;
-						Point2D occupier_point;
-						TacticalMap->Coord_To_Pixel(
-							occupier->Get_Coord(), occupier_point);
+				CellClass & cell = Map[center + Cell(x_offset, y_offset)]; // level-2 1.001: a named cell reference (meastes)
+				ObjectClass * occupier = cell.Cell_Occupier(); // RA2: as above
 
-						Point2D diff = occupier_point - point;
-						int screen_dist = (int)fastmath::sqrt(
-							(double)diff.Y * diff.Y +
-							(double)diff.X * diff.X) + 8;
+				while (occupier != NULL) { // RA2: as above
 
-						if (screen_dist < 256) {
-							char *displacement =
-								(char *)BlastSurfaces[Lifetime]->Lock(
-									Point2D(screen_dist + 256, 128));
+					if (occupier->Fetch_RTTI() == RTTI_INFANTRY || occupier->Fetch_RTTI() == RTTI_UNIT) { // RA2: the exe tests the RTTI (15 then 1), not dynamic_cast
 
-							if (*displacement > 0) {
-								foot->Set_Speed(0.0);
-								int draw_offset =
-									Spiral_Index_To_Point(*displacement).Y;
-								foot->IonBlastYDrawOffset = 2 * draw_offset;
+						FootClass * foot = (FootClass *)occupier; // level-2 1.001: the typed pointer is a second variable (meastes)
+						Point2D occupier_point; // RA2: as above
+						TacticalMap->Coord_To_Pixel(occupier->Get_Coord(), occupier_point); // RA2: as above
+
+						Point2D diff = occupier_point - point; // RA2: as above
+						int screen_dist = (int)fastmath::sqrt((double)diff.Y * diff.Y + (double)diff.X * diff.X) + 8; // RA2: Y squared first, written out instead of Point2D::Length
+
+						if (screen_dist < 128) { // RA2: as above
+
+							char * displacement = (char *)BlastSurfaces[Lifetime]->Lock(Point2D(screen_dist + 128, 64)); // RA2: as above
+
+							if (*displacement > 0) { // RA2: as above
+
+								foot->Set_Speed(0.0); // RA2: no weapons factory exemption; the blast always stops the unit
+
+								int draw_offset = Spiral_Index_To_Point(*displacement).Y; // RA2: as above
+								foot->IonBlastYDrawOffset = 2 * draw_offset; // RA2: as above
 							}
 
-							VoxelLibrary *voxel;
-							if (foot->Techno_Type_Class()->Voxel.VoxLib != NULL &&
-								(voxel = foot->Techno_Type_Class()->Voxel.VoxLib,
-								 !voxel->Load_Failed()) &&
-								*displacement >= 0) {
-								Coord blast_coord = Position;
-								Coord occupier_coord = occupier->Get_Coord();
+							if (occupier->Techno_Type_Class()->Voxel.VoxLib != NULL // RA2: as above
+								&& !occupier->Techno_Type_Class()->Voxel.VoxLib->Load_Failed() // RA2: as above
+								&& *displacement >= 0) { // RA2: as above
 
-								Vector3 to_blast;
-								to_blast.X =
-									(float)(blast_coord.X - occupier_coord.X);
-								to_blast.Y =
-									(float)(occupier_coord.Y - blast_coord.Y);
-								to_blast.Z =
-									(float)(blast_coord.Z - occupier_coord.Z);
-								Vector3 flat = to_blast;
+								/*
+								 * Rock the voxel unit away from the blast: build the vector
+								 * from the unit to the blast center, rotate it into the unit's
+								 * facing frame, and scale it by the slope of the ripple at the
+								 * unit's distance from the blast. The wave height there is
+								 * height/decay, so its slope comes out by the quotient rule.
+								 */
+								Coord blast_coord = Position; // RA2: as above
+								Coord occupier_coord = occupier->Get_Coord(); // RA2: as above
 
-								double facing_rad =
-									foot->PrimaryFacing.Current().As_Radian();
-								float facing_sin =
-									(float)fastmath::sin(facing_rad);
-								Vector3 facing(
-									(float)fastmath::cos(facing_rad),
-									facing_sin, 0.0f);
+								Vector3 to_blast((float)(blast_coord.X - occupier_coord.X), (float)(occupier_coord.Y - blast_coord.Y), (float)(blast_coord.Z - occupier_coord.Z)); // RA2: as above
+								Vector3 flat = to_blast; // RA2: as above
 
-								float blast_dist = Ion_Vector_Length(to_blast);
+								double facing_rad = foot->PrimaryFacing.Current().As_Radian(); // RA2: as above
+								float facing_sin = (float)fastmath::sin(facing_rad); // RA2: as above
+								Vector3 facing; // level-2 1.001: the cosine lives in a Vector3 (meastes)
+								facing.X = (float)fastmath::cos(facing_rad); // RA2: as above
 
-								if (fabs(blast_dist) > 0.00002) {
-									flat.Z = 0.0;
-									double flat_len = fastmath::sqrt(
-										flat.X * flat.X + flat.Y * flat.Y);
+								float blast_dist = fastmath::sqrt((double)to_blast.X * to_blast.X + (double)to_blast.Y * to_blast.Y + (double)to_blast.Z * to_blast.Z); // RA2: written out instead of Vector3::Length
 
-									Vector3 normal;
-									if (flat_len != 0.0) {
-										normal = flat / flat_len;
+								if (fabs(blast_dist) > 0.00002) { // RA2: as above
+
+									flat.Z = 0.0; // RA2: as above
+
+									double flat_len = fastmath::sqrt(flat.X * flat.X + flat.Y * flat.Y); // RA2: as above
+
+									Vector3 normal; // RA2: as above
+									if (flat_len != 0.0) { // RA2: as above
+										normal = flat / flat_len; // RA2: as above
 									} else {
-										normal = flat;
+										normal = flat; // RA2: as above
 									}
 
-									float forwards = normal * facing;
-									float sideways = Ion_Vector_Length(
-										Vector3::Cross_Product(normal, facing));
+									float forwards = normal.X * facing.X + normal.Y * facing_sin; // RA2: as above
+									float sideways = Length_Of(Vector3(-(normal.Z * facing_sin), normal.Z * facing.X, normal.X * facing_sin - normal.Y * facing.X)); // level-2 1.001: the length helper on a Vector3 temporary (meastes)
 
-									float c2 = facing.X;
+									float c2 = facing.X; // level-2 1.001: the rotation terms are copied to locals (meastes)
 									float s2 = facing_sin;
 									float c3 = facing.X;
 									float s3 = facing_sin;
-									if (fabs(c2 * forwards - s2 * sideways -
-											 normal.X) > 0.0002 ||
-										fabs(c3 * sideways + s3 * forwards -
-											 normal.Y) > 0.0002) {
-										sideways = -sideways;
+									if (fabs(c2 * forwards - s2 * sideways - normal.X) > 0.0002 // RA2: as above
+										|| fabs(c3 * sideways + s3 * forwards - normal.Y) > 0.0002) { // RA2: as above
+										sideways = -sideways; // RA2: as above
 									}
 
-									double decay =
-										blast_dist + WaveAmplitudeFalloff;
-									double height =
-										(fastmath::sin(
-											(blast_dist -
-											 (double)Lifetime * WavePhaseSpeed +
-											 38.0) * WaveFrequency) * 3.5 + 3.0) *
-										WaveAmplitudeFalloff;
-									double slope =
-										((fastmath::cos(
-											(blast_dist -
-											 (double)Lifetime * WavePhaseSpeed +
-											 38.0) * WaveFrequency) *
-										  WaveFrequency *
-										  WaveAmplitudeFalloff * 3.5) *
-										 decay - height) /
-										(decay * decay);
+									double decay = blast_dist + WaveAmplitudeFalloff; // RA2: as above
+									double height = (fastmath::sin((blast_dist - (double)Lifetime * WavePhaseSpeed + 38.0) * WaveFrequency) * 3.5 + 3.0) * WaveAmplitudeFalloff; // RA2: as above
+									double phase_cos = fastmath::cos((blast_dist - (double)Lifetime * WavePhaseSpeed + 38.0) * WaveFrequency); // RA2: as above
+									double slope = ((phase_cos * WaveFrequency * WaveAmplitudeFalloff * 3.5) * decay - height) / (decay * decay); // RA2: as above
 
-									foot->AngleRotatedSideways =
-										(float)(sideways * slope * WaveRockScale);
-									foot->AngleRotatedForwards =
-										(float)(-(forwards * slope *
-												  WaveRockScale));
+									foot->AngleRotatedSideways = (float)(sideways * slope * WaveRockScale); // RA2: as above
+									foot->AngleRotatedForwards = (float)(-(forwards * slope * WaveRockScale)); // RA2: as above
 								}
 							}
 						}
 					}
-					occupier = occupier->Next;
+
+					occupier = occupier->Next; // RA2: as above
 				}
 			}
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -1,3 +1,3 @@
-void IonBlastClass::AI(void)
+void IonBlastClass::AI()
 {
 	if (Lifetime >= 79) {
@@ -6,116 +6,155 @@
 	}
 
-	if (DisableIonBeam != 1) { // RA2: a blast with the word at +0x10 set only ages; the body below sits one level deeper
-		Point2D point; // RA2: as above
-		TacticalMap->Coord_To_Pixel(Position, point); // RA2: the result is not tested and Map.ScreenY is not touched
+	if (DisableIonBeam != 1) {
+		Point2D point;
+		TacticalMap->Coord_To_Pixel(Position, point);
 
-		if (Lifetime == 0) { // RA2: as above
-			if (Map[Position].Land_Type() == LAND_WATER) { // RA2: as above
-				new AnimClass(Rule->SplashList[Rule->SplashList.Count() - 1], Position + Coord(0,0,5), 0, 1, (ShapeFlags_Type)(SHAPE_CENTER|SHAPE_WIN_REL), 0); // RA2: as above
+		if (Lifetime == 0) {
+			if (Map[Position].Land_Type() == 2) {
+				new AnimClass(
+					Rule->SplashList[Rule->SplashList.Count() - 1],
+					Position + Coord(0, 0, 5), 0, 1,
+					ShapeFlags_Type(SHAPE_CENTER | SHAPE_WIN_REL), 0);
 			} else {
-				new AnimClass(Rule->IonBlast, Position + Coord(0,0,5), 0, 1, (ShapeFlags_Type)(SHAPE_CENTER|SHAPE_WIN_REL), 0); // RA2: as above
-			}
-			new AnimClass(Rule->IonBeam, Position + Coord(0,0,5), 0, 1, (ShapeFlags_Type)(SHAPE_CENTER|SHAPE_WIN_REL), 0); // RA2: as above
-
-			if (Map[Position].IsUnderBridge) { // RA2: as above
-				Coord coord; // RA2: declared where it is used
-				coord.X = Position.X; // RA2: as above
-				coord.Z = BRIDGE_LEPTON_HEIGHT + Position.Z; // RA2: as above
-				coord.Y = Position.Y; // RA2: as above
-				Explosion_Damage(coord, Rule->IonCannonDamage, NULL, Rule->IonCannonWarhead, true); // RA2: as above
+				new AnimClass(
+					Rule->IonBlast, Position + Coord(0, 0, 5), 0, 1,
+					ShapeFlags_Type(SHAPE_CENTER | SHAPE_WIN_REL), 0);
 			}
 
-			Explosion_Damage(Position, Rule->IonCannonDamage, NULL, Rule->IonCannonWarhead, true); // RA2: as above
-			Combat_Lighting(Position, Rule->IonCannonDamage, Rule->IonCannonWarhead, 0, 0); // RA2: the five argument form
+			new AnimClass(
+				Rule->IonBeam, Position + Coord(0, 0, 5), 0, 1,
+				ShapeFlags_Type(SHAPE_CENTER | SHAPE_WIN_REL), 0);
+
+			if (Map[Position].IsUnderBridge) {
+				Coord coord = Coord(
+					Position.X, Position.Y,
+					BRIDGE_LEPTON_HEIGHT + Position.Z);
+				Explosion_Damage(
+					coord, Rule->IonCannonDamage, 0,
+					Rule->IonCannonWarhead, 1);
+			}
+
+			Explosion_Damage(
+				Position, Rule->IonCannonDamage, 0,
+				Rule->IonCannonWarhead, 1);
+			Combat_Lighting(
+				Position, Rule->IonCannonDamage,
+				Rule->IonCannonWarhead, 0, 0);
 		}
 
-		Cell center(Position); // RA2: as above
+		Cell const &center = Position.As_Cell();
 
-		for (int x_offset = -3; x_offset < 4; x_offset++) { // RA2: as above
-			for (int y_offset = -3; y_offset < 4; y_offset++) { // RA2: as above
+		for (int x_offset = -3; x_offset < 4; x_offset++) {
+			for (int y_offset = -3; y_offset < 4; y_offset++) {
+				CellClass &cell = Map[center + Cell(x_offset, y_offset)];
+				ObjectClass *occupier = cell.Cell_Occupier();
 
-				FootClass * occupier = (FootClass *)Map[center + Cell(x_offset, y_offset)].Cell_Occupier(); // RA2: as above
+				while (occupier != 0) {
+					if (occupier->Fetch_RTTI() == RTTI_INFANTRY ||
+						occupier->Fetch_RTTI() == RTTI_UNIT) {
+						FootClass *foot = (FootClass *)occupier;
+						Point2D occupier_point;
+						TacticalMap->Coord_To_Pixel(
+							occupier->Get_Coord(), occupier_point);
 
-				while (occupier != NULL) { // RA2: as above
+						Point2D diff = occupier_point - point;
+						int screen_dist = (int)fastmath::sqrt(
+							(double)diff.Y * diff.Y +
+							(double)diff.X * diff.X) + 8;
 
-					if (occupier->Fetch_RTTI() == RTTI_INFANTRY || occupier->Fetch_RTTI() == RTTI_UNIT) { // RA2: the exe tests the RTTI (15 then 1), not dynamic_cast
+						if (screen_dist < 256) {
+							char *displacement =
+								(char *)BlastSurfaces[Lifetime]->Lock(
+									Point2D(screen_dist + 256, 128));
 
-						Point2D occupier_point; // RA2: as above
-						TacticalMap->Coord_To_Pixel(occupier->Get_Coord(), occupier_point); // RA2: as above
-
-						Point2D diff = occupier_point - point; // RA2: as above
-						int screen_dist = (int)fastmath::sqrt((double)diff.Y * diff.Y + (double)diff.X * diff.X) + 8; // RA2: Y squared first, written out instead of Point2D::Length
-
-						if (screen_dist < 128) { // RA2: as above
-
-							char * displacement = (char *)BlastSurfaces[Lifetime]->Lock(Point2D(screen_dist + 128, 64)); // RA2: as above
-
-							if (*displacement > 0) { // RA2: as above
-
-								occupier->Set_Speed(0.0); // RA2: no weapons factory exemption; the blast always stops the unit
-
-								int draw_offset = Spiral_Index_To_Point(*displacement).Y; // RA2: as above
-								occupier->IonBlastYDrawOffset = 2 * draw_offset; // RA2: as above
+							if (*displacement > 0) {
+								foot->Set_Speed(0.0);
+								int draw_offset =
+									Spiral_Index_To_Point(*displacement).Y;
+								foot->IonBlastYDrawOffset = 2 * draw_offset;
 							}
 
-							if (occupier->Techno_Type_Class()->Voxel.VoxLib != NULL // RA2: as above
-								&& !occupier->Techno_Type_Class()->Voxel.VoxLib->Load_Failed() // RA2: as above
-								&& *displacement >= 0) { // RA2: as above
+							VoxelLibrary *voxel;
+							if (foot->Techno_Type_Class()->Voxel.VoxLib != NULL &&
+								(voxel = foot->Techno_Type_Class()->Voxel.VoxLib,
+								 !voxel->Load_Failed()) &&
+								*displacement >= 0) {
+								Coord blast_coord = Position;
+								Coord occupier_coord = occupier->Get_Coord();
 
-								/*
-								 * Rock the voxel unit away from the blast: build the vector
-								 * from the unit to the blast center, rotate it into the unit's
-								 * facing frame, and scale it by the slope of the ripple at the
-								 * unit's distance from the blast. The wave height there is
-								 * height/decay, so its slope comes out by the quotient rule.
-								 */
-								Coord blast_coord = Position; // RA2: as above
-								Coord occupier_coord = occupier->Get_Coord(); // RA2: as above
+								Vector3 to_blast;
+								to_blast.X =
+									(float)(blast_coord.X - occupier_coord.X);
+								to_blast.Y =
+									(float)(occupier_coord.Y - blast_coord.Y);
+								to_blast.Z =
+									(float)(blast_coord.Z - occupier_coord.Z);
+								Vector3 flat = to_blast;
 
-								Vector3 to_blast((float)(blast_coord.X - occupier_coord.X), (float)(occupier_coord.Y - blast_coord.Y), (float)(blast_coord.Z - occupier_coord.Z)); // RA2: as above
-								Vector3 flat = to_blast; // RA2: as above
+								double facing_rad =
+									foot->PrimaryFacing.Current().As_Radian();
+								float facing_sin =
+									(float)fastmath::sin(facing_rad);
+								Vector3 facing(
+									(float)fastmath::cos(facing_rad),
+									facing_sin, 0.0f);
 
-								double facing_rad = occupier->PrimaryFacing.Current().As_Radian(); // RA2: as above
-								float facing_sin = (float)fastmath::sin(facing_rad); // RA2: as above
-								float facing_cos = (float)fastmath::cos(facing_rad); // RA2: as above
+								float blast_dist = Ion_Vector_Length(to_blast);
 
-								float blast_dist = fastmath::sqrt((double)to_blast.X * to_blast.X + (double)to_blast.Y * to_blast.Y + (double)to_blast.Z * to_blast.Z); // RA2: written out instead of Vector3::Length
+								if (fabs(blast_dist) > 0.00002) {
+									flat.Z = 0.0;
+									double flat_len = fastmath::sqrt(
+										flat.X * flat.X + flat.Y * flat.Y);
 
-								if (fabs(blast_dist) > 0.00002) { // RA2: as above
-
-									flat.Z = 0.0; // RA2: as above
-
-									double flat_len = fastmath::sqrt(flat.Y * flat.Y + flat.X * flat.X); // RA2: as above
-
-									Vector3 normal; // RA2: as above
-									if (flat_len != 0.0) { // RA2: as above
-										normal = flat / flat_len; // RA2: as above
+									Vector3 normal;
+									if (flat_len != 0.0) {
+										normal = flat / flat_len;
 									} else {
-										normal = flat; // RA2: as above
+										normal = flat;
 									}
 
-									float forwards = normal.X * facing_cos + normal.Y * facing_sin; // RA2: as above
-									float sideways_zsin = -(normal.Z * facing_sin); // RA2: as above
-									float sideways_zcos = normal.Z * facing_cos; // level-2 1.001: float (1.006: double)
-									float sideways_y = normal.X * facing_sin - normal.Y * facing_cos; // level-2 1.001: float (1.006: double)
-									float sideways = (float)fastmath::sqrt(sideways_zsin * sideways_zsin + sideways_zcos * sideways_zcos + sideways_y * sideways_y); // RA2: as above
-									if (fabs(facing_cos * forwards - facing_sin * sideways - normal.X) > 0.0002 // RA2: as above
-										|| fabs(facing_cos * sideways + facing_sin * forwards - normal.Y) > 0.0002) { // RA2: as above
-										sideways = -sideways; // RA2: as above
+									float forwards = normal * facing;
+									float sideways = Ion_Vector_Length(
+										Vector3::Cross_Product(normal, facing));
+
+									float c2 = facing.X;
+									float s2 = facing_sin;
+									float c3 = facing.X;
+									float s3 = facing_sin;
+									if (fabs(c2 * forwards - s2 * sideways -
+											 normal.X) > 0.0002 ||
+										fabs(c3 * sideways + s3 * forwards -
+											 normal.Y) > 0.0002) {
+										sideways = -sideways;
 									}
 
-									double decay = blast_dist + WaveAmplitudeFalloff; // RA2: as above
-									double height = (fastmath::sin((blast_dist - (double)Lifetime * WavePhaseSpeed + 38.0) * WaveFrequency) * 3.5 + 3.0) * WaveAmplitudeFalloff; // RA2: as above
-									double phase_cos = fastmath::cos((blast_dist - (double)Lifetime * WavePhaseSpeed + 38.0) * WaveFrequency); // RA2: as above
-									double slope = ((phase_cos * WaveFrequency * WaveAmplitudeFalloff * 3.5) * decay - height) / (decay * decay); // RA2: as above
+									double decay =
+										blast_dist + WaveAmplitudeFalloff;
+									double height =
+										(fastmath::sin(
+											(blast_dist -
+											 (double)Lifetime * WavePhaseSpeed +
+											 38.0) * WaveFrequency) * 3.5 + 3.0) *
+										WaveAmplitudeFalloff;
+									double slope =
+										((fastmath::cos(
+											(blast_dist -
+											 (double)Lifetime * WavePhaseSpeed +
+											 38.0) * WaveFrequency) *
+										  WaveFrequency *
+										  WaveAmplitudeFalloff * 3.5) *
+										 decay - height) /
+										(decay * decay);
 
-									occupier->AngleRotatedSideways = (float)(sideways * slope * WaveRockScale); // RA2: as above
-									occupier->AngleRotatedForwards = (float)(-(forwards * slope * WaveRockScale)); // RA2: as above
+									foot->AngleRotatedSideways =
+										(float)(sideways * slope * WaveRockScale);
+									foot->AngleRotatedForwards =
+										(float)(-(forwards * slope *
+												  WaveRockScale));
 								}
 							}
 						}
 					}
-
-					occupier = (FootClass *)occupier->Next; // RA2: as above
+					occupier = occupier->Next;
 				}
 			}
```
