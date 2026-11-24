# 0x154520 ?Destroy_Low_Bridge_Near@MapClass@@QAEXABVCell@@@Z (src/m85/src/map.cpp)

Origin: history: w339_x.claims.json. Community source: meastes1006_map.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -10,18 +10,18 @@
 	}
 	CellClass *cellptr = &Map[cell];
-	int step; // RA2: as above
-	int facing = 0; // RA2: as above
+	FacingType step; // RA2: as above
+	FacingType facing = FACING_N; // RA2: as above
 	if (!cellptr->IsUnderBridge && !cellptr->WasUnderBridge) {
 		for (int index = 0; index < 8; ++index) { // RA2: as above
-			Cell adjacent = Adjacent_Cell(cell, FacingType(facing)); // RA2: as above
+			Cell adjacent = Adjacent_Cell(cell, facing); // RA2: as above
 			cellptr = &Map[adjacent];
 			if (cellptr->IsUnderBridge || cellptr->WasUnderBridge) break; // RA2: as above
-			Cell adjacent2 = Adjacent_Cell(adjacent, FacingType(facing)); // RA2: as above
+			Cell adjacent2 = Adjacent_Cell(adjacent, facing); // RA2: as above
 			cellptr = &Map[adjacent2]; // RA2: as above
 			if (cellptr->IsUnderBridge || cellptr->WasUnderBridge) break; // RA2: as above
-			adjacent = Adjacent_Cell(adjacent2, FacingType(facing)); // RA2: as above
+			adjacent = Adjacent_Cell(adjacent2, facing); // RA2: as above
 			cellptr = &Map[adjacent];
 			if (cellptr->IsUnderBridge || cellptr->WasUnderBridge) break; // RA2: as above
-			facing = (facing + 1) & 7; // RA2: as above
+			facing = Facing_Add(facing, FACING_NE); // RA2: as above
 		}
 	}
@@ -35,9 +35,10 @@
 		int count = 0;
 		
-		if (cellptr->IsBridgeEastWest) step = 4; // RA2: as above
-		else step = 2; // RA2: as above
+		if (cellptr->IsBridgeEastWest) step = FACING_S; // RA2: as above
+		else step = FACING_E; // RA2: as above
 		CellClass *walkptr; // RA2: as above
 		while (true) {
-			Cell const &from = walk; walk = Adjacent_Cell_L(from, FacingType(step)); // RA2: as above
+			Cell const & from = walk; // RA2: as above
+			walk = Adjacent_Cell_L(from, step); // RA2: the twin's statement (ra2-decomp DestroyConcreteBridgeAt, DestroyWoodBridgeAt): the table entry is the left operand
 			walkptr = &Map[walk];
 			if (walkptr->WasUnderBridge) { // RA2: as above
@@ -47,9 +48,9 @@
 			}
 		}
-		int back = (step - 4) & 7; // RA2: as above
+		FacingType back = Facing_Sub(step, FACING_180); // RA2: as above
 		origin = (AdjacentCell[back & 7] + walk) + AdjacentCell[back & 7]; // RA2: as above
 	}
 	
-	int shared_direction = cellptr->IsBridgeEastWest ? 6 : 0; // RA2: as above
+	FacingType shared_direction = cellptr->IsBridgeEastWest ? FACING_W : FACING_N; // RA2: as above
 	Cell spancell = origin;
 	DynamicVectorClass<Cell> cells;
@@ -60,5 +61,5 @@
 			if (spancell.X > MapRect.X + MapRect.Width) break; // RA2: as above
 			if (spancell.Y < MapRect.Y || spancell.Y > MapRect.Y + MapRect.Height) break; // RA2: as above
-			if (Is_Valid(spancell)) { // RA2: as above
+			if (Array[spancell.X + spancell.Y * MAP_CELL_W] != NULL) { // RA2: as above
 				spanptr = &Map[spancell]; // RA2: as above
 				tile = spanptr->ITType - IsometricTileTypeClass::TrainBridgeSet + 1; // RA2: as above
@@ -68,5 +69,5 @@
 				}
 			}
-			spancell = Adjacent_Cell_L(spancell, FacingType(shared_direction)); // level-2 1.001: offset + cell
+			spancell = Adjacent_Cell(spancell, shared_direction); // RA2: as above
 		}
 	}
@@ -75,5 +76,5 @@
 destroy_span: // RA2: as above
 	{
-		step = (shared_direction - 4) & 7; // RA2: as above
+	step = Facing_Sub(shared_direction, FACING_180); // RA2: as above
 		Cell end = spancell; // RA2: as above
 		int hits; // RA2: as above
@@ -82,5 +83,5 @@
 		}
 		while (true) {
-			end = Adjacent_Cell_L(end, FacingType(step)); // RA2: as above
+			end = Adjacent_Cell(end, step); // RA2: as above
 			spanptr = &Map[end]; // RA2: as above
 			if (end.X < MapRect.X || end.X > MapRect.X + MapRect.Width || // RA2: as above
@@ -91,5 +92,5 @@
 		}
 		if (tile != -1) { // RA2: as above
-			end = AdjacentCell[(step - 4) & 7] + end; // level-2 1.001: offset + cell
+			end = end + AdjacentCell[(step - 4) & 7]; // RA2: as above
 			for (hits = 0; hits < 3; ++hits) { // RA2: as above
 				if (Damage_Bridge(end)) break; // RA2: as above
```

## 2. Our matched form against the community form

```diff
(identical)
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -10,18 +10,18 @@
 	}
 	CellClass *cellptr = &Map[cell];
-	int step; // RA2: as above
-	int facing = 0; // RA2: as above
+	FacingType step; // RA2: as above
+	FacingType facing = FACING_N; // RA2: as above
 	if (!cellptr->IsUnderBridge && !cellptr->WasUnderBridge) {
 		for (int index = 0; index < 8; ++index) { // RA2: as above
-			Cell adjacent = Adjacent_Cell(cell, FacingType(facing)); // RA2: as above
+			Cell adjacent = Adjacent_Cell(cell, facing); // RA2: as above
 			cellptr = &Map[adjacent];
 			if (cellptr->IsUnderBridge || cellptr->WasUnderBridge) break; // RA2: as above
-			Cell adjacent2 = Adjacent_Cell(adjacent, FacingType(facing)); // RA2: as above
+			Cell adjacent2 = Adjacent_Cell(adjacent, facing); // RA2: as above
 			cellptr = &Map[adjacent2]; // RA2: as above
 			if (cellptr->IsUnderBridge || cellptr->WasUnderBridge) break; // RA2: as above
-			adjacent = Adjacent_Cell(adjacent2, FacingType(facing)); // RA2: as above
+			adjacent = Adjacent_Cell(adjacent2, facing); // RA2: as above
 			cellptr = &Map[adjacent];
 			if (cellptr->IsUnderBridge || cellptr->WasUnderBridge) break; // RA2: as above
-			facing = (facing + 1) & 7; // RA2: as above
+			facing = Facing_Add(facing, FACING_NE); // RA2: as above
 		}
 	}
@@ -35,9 +35,10 @@
 		int count = 0;
 		
-		if (cellptr->IsBridgeEastWest) step = 4; // RA2: as above
-		else step = 2; // RA2: as above
+		if (cellptr->IsBridgeEastWest) step = FACING_S; // RA2: as above
+		else step = FACING_E; // RA2: as above
 		CellClass *walkptr; // RA2: as above
 		while (true) {
-			Cell const &from = walk; walk = Adjacent_Cell_L(from, FacingType(step)); // RA2: as above
+			Cell const & from = walk; // RA2: as above
+			walk = Adjacent_Cell_L(from, step); // RA2: the twin's statement (ra2-decomp DestroyConcreteBridgeAt, DestroyWoodBridgeAt): the table entry is the left operand
 			walkptr = &Map[walk];
 			if (walkptr->WasUnderBridge) { // RA2: as above
@@ -47,9 +48,9 @@
 			}
 		}
-		int back = (step - 4) & 7; // RA2: as above
+		FacingType back = Facing_Sub(step, FACING_180); // RA2: as above
 		origin = (AdjacentCell[back & 7] + walk) + AdjacentCell[back & 7]; // RA2: as above
 	}
 	
-	int shared_direction = cellptr->IsBridgeEastWest ? 6 : 0; // RA2: as above
+	FacingType shared_direction = cellptr->IsBridgeEastWest ? FACING_W : FACING_N; // RA2: as above
 	Cell spancell = origin;
 	DynamicVectorClass<Cell> cells;
@@ -60,5 +61,5 @@
 			if (spancell.X > MapRect.X + MapRect.Width) break; // RA2: as above
 			if (spancell.Y < MapRect.Y || spancell.Y > MapRect.Y + MapRect.Height) break; // RA2: as above
-			if (Is_Valid(spancell)) { // RA2: as above
+			if (Array[spancell.X + spancell.Y * MAP_CELL_W] != NULL) { // RA2: as above
 				spanptr = &Map[spancell]; // RA2: as above
 				tile = spanptr->ITType - IsometricTileTypeClass::TrainBridgeSet + 1; // RA2: as above
@@ -68,5 +69,5 @@
 				}
 			}
-			spancell = Adjacent_Cell_L(spancell, FacingType(shared_direction)); // level-2 1.001: offset + cell
+			spancell = Adjacent_Cell(spancell, shared_direction); // RA2: as above
 		}
 	}
@@ -75,5 +76,5 @@
 destroy_span: // RA2: as above
 	{
-		step = (shared_direction - 4) & 7; // RA2: as above
+	step = Facing_Sub(shared_direction, FACING_180); // RA2: as above
 		Cell end = spancell; // RA2: as above
 		int hits; // RA2: as above
@@ -82,5 +83,5 @@
 		}
 		while (true) {
-			end = Adjacent_Cell_L(end, FacingType(step)); // RA2: as above
+			end = Adjacent_Cell(end, step); // RA2: as above
 			spanptr = &Map[end]; // RA2: as above
 			if (end.X < MapRect.X || end.X > MapRect.X + MapRect.Width || // RA2: as above
@@ -91,5 +92,5 @@
 		}
 		if (tile != -1) { // RA2: as above
-			end = AdjacentCell[(step - 4) & 7] + end; // level-2 1.001: offset + cell
+			end = end + AdjacentCell[(step - 4) & 7]; // RA2: as above
 			for (hits = 0; hits < 3; ++hits) { // RA2: as above
 				if (Damage_Bridge(end)) break; // RA2: as above
```
