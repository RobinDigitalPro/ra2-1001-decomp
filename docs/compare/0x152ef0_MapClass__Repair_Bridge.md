# 0x152ef0 ?Repair_Bridge@MapClass@@QAEXABVCell@@@Z (src/m85/src/map.cpp)

Origin: history: w267_x.claims.json. Community source: gibbo8c1df2_map.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -20,11 +20,14 @@
 	 * eight facings until a bridge cell is found.
 	 */
+	// level-2: the forms of the rest of this function are adopted from gibbo101/ra2-decomp src/map.cpp @721d81e44f
+	// (GPL-3.0-or-later; YR 0x00573540): FacingType facing and step, the walk on its own Cell through Adjacent_Cell_L,
+	// advance by if/else, a char zone flag, a while loop with the step at its bottom and the next span as an argument temporary.
 	CellClass * cellptr = &Map[cell];
-
-	int facing = FACING_FIRST; // level-2 1.001: int, as in Destroy_High_Bridge_Connections
+	FacingType step;
+	FacingType facing = FACING_N;
 	if (!cellptr->IsUnderBridge && !cellptr->WasUnderBridge) {
 		for (int index = 0; index < FACING_COUNT; index++) {
 
-			Cell adjacent = Adjacent_Cell(cell, Facing_Add(facing, FACING_0));
+			Cell adjacent = Adjacent_Cell(cell, facing);
 			cellptr = &Map[adjacent];
 			if (cellptr->IsUnderBridge || cellptr->WasUnderBridge) {
@@ -32,5 +35,5 @@
 			}
 
-			adjacent = Adjacent_Cell(adjacent, Facing_Add(facing, FACING_0));
+			adjacent = Adjacent_Cell(adjacent, facing);
 			cellptr = &Map[adjacent];
 			if (cellptr->IsUnderBridge || cellptr->WasUnderBridge) {
@@ -38,5 +41,5 @@
 			}
 
-			adjacent = Adjacent_Cell(adjacent, Facing_Add(facing, FACING_0));
+			adjacent = Adjacent_Cell(adjacent, facing);
 			cellptr = &Map[adjacent];
 			if (cellptr->IsUnderBridge || cellptr->WasUnderBridge) {
@@ -74,22 +77,24 @@
 		 * end.
 		 */
-		origin = cellptr->Fetch_CellID(); // level-2 1.001: walk form of Destroy_High_Bridge_Connections
+		Cell walk = cellptr->Fetch_CellID();
 		int count = 0;
-		int step = cellptr->IsBridgeEastWest ? FACING_S : FACING_E;
+		if (cellptr->IsBridgeEastWest)
+			step = FACING_S;
+		else
+			step = FACING_E;
 		CellClass * walkptr;
 		while (true) {
-			origin = Adjacent_Cell(origin, FacingType(step));
-			walkptr = &Map[origin];
-			if (walkptr->WasUnderBridge) { // level-2 1.001: as above
-				if (++count >= 4) {
+			Cell const & from = walk;
+			walk = Adjacent_Cell_L(from, step);
+			walkptr = &Map[walk];
+			if (walkptr->WasUnderBridge) {
+				if (++count >= 4)
 					return;
-				}
 			} else {
 				break;
 			}
 		}
-
 		FacingType back = Facing_Sub(step, FACING_180);
-		origin = Adjacent_Cell(Adjacent_Cell(origin, back), back);
+		origin = Adjacent_Cell(Adjacent_Cell(walk, back), back);
 	}
 
@@ -97,12 +102,16 @@
 	 * Walk the span looking for the end or middle tiles, repairing as we go.
 	 */
+	FacingType advance;
+	if (cellptr->IsBridgeEastWest) {
+		advance = FACING_W;
+	} else {
+		advance = FACING_N;
+	}
 	Cell spancell = origin;
-	int advance = cellptr->IsBridgeEastWest ? FACING_W : FACING_N;
-
-	int zonechanged = 0;
-	IsometricTileType ittype = ISOTILE_CLEAR;
 
 	DynamicVectorClass<Cell> cells;
 
+	char zonechanged = 0;
+
 	Rect dirty;
 
@@ -110,6 +119,5 @@
 	 * Bail the moment the span steps outside the map rectangle.
 	 */
-	for (; spancell.X >= MapRect.X; // level-2 1.001: for loop with the step as increment
-		 spancell = Adjacent_Cell(spancell, FacingType(advance))) {
+	while (spancell.X >= MapRect.X) {
 
 		if (spancell.X > MapRect.X + MapRect.Width) {
@@ -123,5 +131,5 @@
 
 			CellClass * spanptr = &Map[spancell];
-			ittype = IsometricTileType(spanptr->ITType - IsometricTileTypeClass::BridgeSet + 1);
+			IsometricTileType ittype = IsometricTileType(spanptr->ITType - IsometricTileTypeClass::BridgeSet + 1);
 
 			/*
@@ -129,5 +137,5 @@
 			 */
 			if ((ittype == IsometricTileTypeClass::BridgeTopLeft1
-					|| ittype == IsometricTileTypeClass::BridgeTopLeft2) && spanptr->SubTile == 8) {
+					|| ittype == IsometricTileTypeClass::BridgeTopLeft2) && 8 == spanptr->SubTile) {
 				Set_Bridge_End_State(spancell, false, false);
 				Repair_High_Bridge_Span(&Map[spancell], FACING_E, &dirty);
@@ -167,6 +175,5 @@
 				}
 
-				Cell next = spancell + Cell(-2, 0);
-				Repair_Bridge(next);
+				Repair_Bridge(spancell + Cell(-2, 0));
 				Repair_High_Bridge_Span(&Map[spancell], FACING_E, &dirty);
 				TacticalMap->Register_Dirty_Area(dirty, false);
@@ -212,6 +219,5 @@
 				}
 
-				Cell next = spancell + Cell(0, -2);
-				Repair_Bridge(next);
+				Repair_Bridge(spancell + Cell(0, -2));
 				Repair_High_Bridge_Span(&Map[spancell], FACING_S, &dirty);
 				TacticalMap->Register_Dirty_Area(dirty, false);
@@ -220,4 +226,5 @@
 		}
 
+		spancell = Adjacent_Cell(spancell, advance);
 	}
 
```

## 2. Our matched form against the community form

```diff
--- community
+++ ours matched
@@ -1,8 +1,13 @@
 void MapClass::Repair_Bridge(Cell const & cell)
 {
+	/*
+	 * Scan the 5x5 block of cells around the supplied cell looking for a low
+	 * bridge overlay. If one is found, hand off to the low bridge repair routine
+	 * and exit.
+	 */
 	for (int x = -2; x < 3; x++) {
 		for (int y = -2; y < 3; y++) {
-			if (Is_Low_Bridge2(cell + Cell(x, y))) {
-				FUN_0057F440(cell + Cell(x, y));
+			if (Is_Low_Bridge2(cell + Cell(x, y))) { // level-2 1.001: second low bridge kind (overlays 0xCD-0xE8)
+				Repair_Low_Bridge2_Span(cell + Cell(x, y)); // level-2 1.001: as above
 				return;
 			}
@@ -10,4 +15,12 @@
 	}
 
+	/*
+	 * Locate a cell that is part of a bridge. Start at the supplied cell and, if it
+	 * is not itself bridge related, walk up to three cells out along each of the
+	 * eight facings until a bridge cell is found.
+	 */
+	// level-2: the forms of the rest of this function are adopted from gibbo101/ra2-decomp src/map.cpp @721d81e44f
+	// (GPL-3.0-or-later; YR 0x00573540): FacingType facing and step, the walk on its own Cell through Adjacent_Cell_L,
+	// advance by if/else, a char zone flag, a while loop with the step at its bottom and the next span as an argument temporary.
 	CellClass * cellptr = &Map[cell];
 	FacingType step;
@@ -38,15 +51,30 @@
 	}
 
+	/*
+	 * Nothing bridge related found nearby - there is nothing to repair.
+	 */
 	if (!cellptr->IsUnderBridge && !cellptr->WasUnderBridge) {
 		return;
 	}
 
+	/*
+	 * Resolve the span anchor cell.
+	 */
 	Cell origin;
 	if (cellptr->IsUnderBridge) {
 
+		/*
+		 * A live bridge cell points at the bridge owner (or is the owner).
+		 */
 		origin = cellptr->Get_Bridge_Deck_Cell();
 
 	} else {
 
+		/*
+		 * An already damaged ("was under") bridge cell. Walk along the bridge body
+		 * until a cell that is no longer marked as a former bridge cell is found,
+		 * giving up after four steps, then step back two cells to recover the span
+		 * end.
+		 */
 		Cell walk = cellptr->Fetch_CellID();
 		int count = 0;
@@ -71,4 +99,7 @@
 	}
 
+	/*
+	 * Walk the span looking for the end or middle tiles, repairing as we go.
+	 */
 	FacingType advance;
 	if (cellptr->IsBridgeEastWest) {
@@ -85,4 +116,7 @@
 	Rect dirty;
 
+	/*
+	 * Bail the moment the span steps outside the map rectangle.
+	 */
 	while (spancell.X >= MapRect.X) {
 
@@ -99,4 +133,7 @@
 			IsometricTileType ittype = IsometricTileType(spanptr->ITType - IsometricTileTypeClass::BridgeSet + 1);
 
+			/*
+			 * East/west bridge head - restore it and register the dirty area.
+			 */
 			if ((ittype == IsometricTileTypeClass::BridgeTopLeft1
 					|| ittype == IsometricTileTypeClass::BridgeTopLeft2) && 8 == spanptr->SubTile) {
@@ -107,4 +144,7 @@
 			}
 
+			/*
+			 * East/west bridge middle piece.
+			 */
 			if ((ittype == IsometricTileTypeClass::BridgeMiddle1
 					|| ittype == IsometricTileTypeClass::BridgeMiddle1 + 3
@@ -115,4 +155,8 @@
 				if (ittype == IsometricTileTypeClass::BridgeMiddle1 + 4) {
 
+					/*
+					 * A fully destroyed middle - raise the three affected cells back
+					 * to bridge height and queue them for recalculation.
+					 */
 					Set_Bridge_Middle_State(spancell, IsometricTileType(IsometricTileTypeClass::BridgeMiddle1 + IsometricTileTypeClass::BridgeSet - 1), ISOTILE_INVALID, -1, false);
 
@@ -137,4 +181,7 @@
 			}
 
+			/*
+			 * North/south bridge head - restore it and register the dirty area.
+			 */
 			if ((ittype == IsometricTileTypeClass::BridgeTopRight1
 					|| ittype == IsometricTileTypeClass::BridgeTopRight2) && spanptr->SubTile == 12) {
@@ -145,4 +192,7 @@
 			}
 
+			/*
+			 * North/south bridge middle piece.
+			 */
 			if ((ittype == IsometricTileTypeClass::BridgeMiddle2
 					|| ittype == IsometricTileTypeClass::BridgeMiddle2 + 3
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -1,13 +1,8 @@
 void MapClass::Repair_Bridge(Cell const & cell)
 {
-	/*
-	 * Scan the 5x5 block of cells around the supplied cell looking for a low
-	 * bridge overlay. If one is found, hand off to the low bridge repair routine
-	 * and exit.
-	 */
 	for (int x = -2; x < 3; x++) {
 		for (int y = -2; y < 3; y++) {
-			if (Is_Low_Bridge2(cell + Cell(x, y))) { // level-2 1.001: second low bridge kind (overlays 0xCD-0xE8)
-				Repair_Low_Bridge2_Span(cell + Cell(x, y)); // level-2 1.001: as above
+			if (Is_Low_Bridge2(cell + Cell(x, y))) {
+				FUN_0057F440(cell + Cell(x, y));
 				return;
 			}
@@ -15,16 +10,11 @@
 	}
 
-	/*
-	 * Locate a cell that is part of a bridge. Start at the supplied cell and, if it
-	 * is not itself bridge related, walk up to three cells out along each of the
-	 * eight facings until a bridge cell is found.
-	 */
 	CellClass * cellptr = &Map[cell];
-
-	int facing = FACING_FIRST; // level-2 1.001: int, as in Destroy_High_Bridge_Connections
+	FacingType step;
+	FacingType facing = FACING_N;
 	if (!cellptr->IsUnderBridge && !cellptr->WasUnderBridge) {
 		for (int index = 0; index < FACING_COUNT; index++) {
 
-			Cell adjacent = Adjacent_Cell(cell, Facing_Add(facing, FACING_0));
+			Cell adjacent = Adjacent_Cell(cell, facing);
 			cellptr = &Map[adjacent];
 			if (cellptr->IsUnderBridge || cellptr->WasUnderBridge) {
@@ -32,5 +22,5 @@
 			}
 
-			adjacent = Adjacent_Cell(adjacent, Facing_Add(facing, FACING_0));
+			adjacent = Adjacent_Cell(adjacent, facing);
 			cellptr = &Map[adjacent];
 			if (cellptr->IsUnderBridge || cellptr->WasUnderBridge) {
@@ -38,5 +28,5 @@
 			}
 
-			adjacent = Adjacent_Cell(adjacent, Facing_Add(facing, FACING_0));
+			adjacent = Adjacent_Cell(adjacent, facing);
 			cellptr = &Map[adjacent];
 			if (cellptr->IsUnderBridge || cellptr->WasUnderBridge) {
@@ -48,68 +38,52 @@
 	}
 
-	/*
-	 * Nothing bridge related found nearby - there is nothing to repair.
-	 */
 	if (!cellptr->IsUnderBridge && !cellptr->WasUnderBridge) {
 		return;
 	}
 
-	/*
-	 * Resolve the span anchor cell.
-	 */
 	Cell origin;
 	if (cellptr->IsUnderBridge) {
 
-		/*
-		 * A live bridge cell points at the bridge owner (or is the owner).
-		 */
 		origin = cellptr->Get_Bridge_Deck_Cell();
 
 	} else {
 
-		/*
-		 * An already damaged ("was under") bridge cell. Walk along the bridge body
-		 * until a cell that is no longer marked as a former bridge cell is found,
-		 * giving up after four steps, then step back two cells to recover the span
-		 * end.
-		 */
-		origin = cellptr->Fetch_CellID(); // level-2 1.001: walk form of Destroy_High_Bridge_Connections
+		Cell walk = cellptr->Fetch_CellID();
 		int count = 0;
-		int step = cellptr->IsBridgeEastWest ? FACING_S : FACING_E;
+		if (cellptr->IsBridgeEastWest)
+			step = FACING_S;
+		else
+			step = FACING_E;
 		CellClass * walkptr;
 		while (true) {
-			origin = Adjacent_Cell(origin, FacingType(step));
-			walkptr = &Map[origin];
-			if (walkptr->WasUnderBridge) { // level-2 1.001: as above
-				if (++count >= 4) {
+			Cell const & from = walk;
+			walk = Adjacent_Cell_L(from, step);
+			walkptr = &Map[walk];
+			if (walkptr->WasUnderBridge) {
+				if (++count >= 4)
 					return;
-				}
 			} else {
 				break;
 			}
 		}
-
 		FacingType back = Facing_Sub(step, FACING_180);
-		origin = Adjacent_Cell(Adjacent_Cell(origin, back), back);
+		origin = Adjacent_Cell(Adjacent_Cell(walk, back), back);
 	}
 
-	/*
-	 * Walk the span looking for the end or middle tiles, repairing as we go.
-	 */
+	FacingType advance;
+	if (cellptr->IsBridgeEastWest) {
+		advance = FACING_W;
+	} else {
+		advance = FACING_N;
+	}
 	Cell spancell = origin;
-	int advance = cellptr->IsBridgeEastWest ? FACING_W : FACING_N;
-
-	int zonechanged = 0;
-	IsometricTileType ittype = ISOTILE_CLEAR;
 
 	DynamicVectorClass<Cell> cells;
 
+	char zonechanged = 0;
+
 	Rect dirty;
 
-	/*
-	 * Bail the moment the span steps outside the map rectangle.
-	 */
-	for (; spancell.X >= MapRect.X; // level-2 1.001: for loop with the step as increment
-		 spancell = Adjacent_Cell(spancell, FacingType(advance))) {
+	while (spancell.X >= MapRect.X) {
 
 		if (spancell.X > MapRect.X + MapRect.Width) {
@@ -123,11 +97,8 @@
 
 			CellClass * spanptr = &Map[spancell];
-			ittype = IsometricTileType(spanptr->ITType - IsometricTileTypeClass::BridgeSet + 1);
+			IsometricTileType ittype = IsometricTileType(spanptr->ITType - IsometricTileTypeClass::BridgeSet + 1);
 
-			/*
-			 * East/west bridge head - restore it and register the dirty area.
-			 */
 			if ((ittype == IsometricTileTypeClass::BridgeTopLeft1
-					|| ittype == IsometricTileTypeClass::BridgeTopLeft2) && spanptr->SubTile == 8) {
+					|| ittype == IsometricTileTypeClass::BridgeTopLeft2) && 8 == spanptr->SubTile) {
 				Set_Bridge_End_State(spancell, false, false);
 				Repair_High_Bridge_Span(&Map[spancell], FACING_E, &dirty);
@@ -136,7 +107,4 @@
 			}
 
-			/*
-			 * East/west bridge middle piece.
-			 */
 			if ((ittype == IsometricTileTypeClass::BridgeMiddle1
 					|| ittype == IsometricTileTypeClass::BridgeMiddle1 + 3
@@ -147,8 +115,4 @@
 				if (ittype == IsometricTileTypeClass::BridgeMiddle1 + 4) {
 
-					/*
-					 * A fully destroyed middle - raise the three affected cells back
-					 * to bridge height and queue them for recalculation.
-					 */
 					Set_Bridge_Middle_State(spancell, IsometricTileType(IsometricTileTypeClass::BridgeMiddle1 + IsometricTileTypeClass::BridgeSet - 1), ISOTILE_INVALID, -1, false);
 
@@ -167,6 +131,5 @@
 				}
 
-				Cell next = spancell + Cell(-2, 0);
-				Repair_Bridge(next);
+				Repair_Bridge(spancell + Cell(-2, 0));
 				Repair_High_Bridge_Span(&Map[spancell], FACING_E, &dirty);
 				TacticalMap->Register_Dirty_Area(dirty, false);
@@ -174,7 +137,4 @@
 			}
 
-			/*
-			 * North/south bridge head - restore it and register the dirty area.
-			 */
 			if ((ittype == IsometricTileTypeClass::BridgeTopRight1
 					|| ittype == IsometricTileTypeClass::BridgeTopRight2) && spanptr->SubTile == 12) {
@@ -185,7 +145,4 @@
 			}
 
-			/*
-			 * North/south bridge middle piece.
-			 */
 			if ((ittype == IsometricTileTypeClass::BridgeMiddle2
 					|| ittype == IsometricTileTypeClass::BridgeMiddle2 + 3
@@ -212,6 +169,5 @@
 				}
 
-				Cell next = spancell + Cell(0, -2);
-				Repair_Bridge(next);
+				Repair_Bridge(spancell + Cell(0, -2));
 				Repair_High_Bridge_Span(&Map[spancell], FACING_S, &dirty);
 				TacticalMap->Register_Dirty_Area(dirty, false);
@@ -220,4 +176,5 @@
 		}
 
+		spancell = Adjacent_Cell(spancell, advance);
 	}
 
```
