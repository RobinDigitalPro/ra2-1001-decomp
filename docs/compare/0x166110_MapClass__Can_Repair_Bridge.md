# 0x166110 ?Can_Repair_Bridge@MapClass@@QAE_NABVCell@@@Z (src/m85/src/map.cpp)

Origin: recent port: batch_54_*. Community source: gibbo8c1df2_map.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -1,185 +1,168 @@
-bool MapClass::Can_Repair_Bridge(Cell const & cell) // RA2: as above
+bool MapClass::Can_Repair_Bridge(Cell const & cell)
 {
-	static short _x[] = { // RA2: as above
-		1, 1, 0, 2, 2, 2, 0, 0, // RA2: as above
-		0, 0, 0, 2, 2, 2, 2, 2 // RA2: as above
+	static short _x[] = {
+		1, 1, 0, 2, 2, 2, 0, 0,
+		0, 0, 0, 2, 2, 2, 2, 2
 	};
-	static short _y[] = { // RA2: as above
-		2, 2, 2, 1, 1, 0, 2, 2, // RA2: as above
-		2, 2, 2, 0, 0, 0, 0, 0 // RA2: as above
+	static short _y[] = {
+		2, 2, 2, 1, 1, 0, 2, 2,
+		2, 2, 2, 0, 0, 0, 0, 0
 	};
-	static FacingType _facings[] = { // RA2: as above
-		FACING_E,       FACING_E,    FACING_W,    FACING_S,    FACING_S,    FACING_N, FACING_NONE, FACING_NONE, // RA2: as above
-		FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE // RA2: as above
+	static FacingType _facings[] = {
+		FACING_E,    FACING_E,    FACING_W,    FACING_S,    FACING_S,    FACING_N,    FACING_NONE, FACING_NONE,
+		FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE
 	};
 
-	bool found = false; // RA2: as above
-	bool second_low_bridge = false; // RA2: the second low bridge kind (overlays 0xCD-0xE8) is searched as well
-	CellClass * cellptr = NULL; // RA2: as above
-	int offset = -1; // RA2: as above
+	bool found = false;
+	bool concrete = false;
+	CellClass * cellptr = NULL;
+	int offset = -1;
 
-	for (int y = -2; y < 3; y++) { // RA2: as above
-		for (int x = -2; x < 3; x++) { // RA2: as above
+	for (int y = -2; y < 3; y++) {
+		for (int x = -2; x < 3; x++) {
+			int ittype = Map[Cell(Cell(x, y) + cell)].ITType;
 
-			IsometricTileType ittype = Map[Cell(cell + Cell(x, y))].ITType; // RA2: as above
-
-			if (ittype >= IsometricTileTypeClass::TrainBridgeSet && ittype < IsometricTileTypeClass::TrainBridgeSet + TRAIN_BRIDGE_COUNT) { // RA2: as above
-				found = true; // RA2: as above
-				cellptr = &Map[Cell(cell + Cell(x, y))]; // RA2: as above
-				offset = ittype - IsometricTileTypeClass::TrainBridgeSet; // RA2: as above
-			} else if (ittype >= IsometricTileTypeClass::BridgeSet && ittype < IsometricTileTypeClass::BridgeSet + BRIDGE_COUNT) { // RA2: as above
-				found = true; // RA2: as above
-				cellptr = &Map[Cell(cell + Cell(x, y))]; // RA2: as above
-				offset = ittype - IsometricTileTypeClass::BridgeSet; // RA2: as above
-			} else {
-				if (Is_Low_Bridge(Cell(x, y) + cell)) { // RA2: the sum is written offset first
-					found = false; // RA2: as above
-					second_low_bridge = false; // RA2: as above
-					cellptr = &Map[Cell(cell + Cell(x, y))]; // RA2: as above
-				} else if (Is_Low_Bridge2(Cell(x, y) + cell)) { // RA2: the second low bridge kind
-					found = false; // RA2: as above
-					second_low_bridge = true; // RA2: as above
-					cellptr = &Map[Cell(cell + Cell(x, y))]; // RA2: as above
-				}
+			if (ittype >= IsometricTileTypeClass::TrainBridgeSet && ittype < IsometricTileTypeClass::TrainBridgeSet + TRAIN_BRIDGE_COUNT) {
+				found = true;
+				cellptr = &Map[Cell(Cell(x, y) + cell)];
+				offset = ittype - IsometricTileTypeClass::TrainBridgeSet;
+			} else if (ittype >= IsometricTileTypeClass::BridgeSet && ittype < IsometricTileTypeClass::BridgeSet + BRIDGE_COUNT) {
+				found = true;
+				cellptr = &Map[Cell(Cell(x, y) + cell)];
+				offset = ittype - IsometricTileTypeClass::BridgeSet;
+			} else if (Is_Low_Bridge(Cell(x, y) + cell)) {
+				found = false;
+				concrete = false;
+				cellptr = &Map[Cell(Cell(x, y) + cell)];
+			} else if (Is_Low_Bridge2(Cell(x, y) + cell)) {
+				found = false;
+				concrete = true;
+				cellptr = &Map[Cell(Cell(x, y) + cell)];
 			}
 		}
 	}
 
-	switch (found) { // RA2: a switch on the flag (an if/else keeps the flag in a register, the executable keeps it in memory)
-		case false: // RA2: as above
-			if (cellptr != NULL) { // RA2: as above
+	if (found) {
+		IsometricTileTypeClass * isotype = IsometricTileTypes[cellptr->ITType];
+		Cell topleft = cellptr->CellID - Cell(cellptr->SubTile % isotype->Width, cellptr->SubTile / isotype->Width);
+		Cell search = Cell(_x[offset], _y[offset]) + topleft;
+		FacingType dir = _facings[offset];
 
-				if (second_low_bridge) { // RA2: the second low bridge kind uses overlays 0xCD-0xE8 and huts 0xE7/0xE8
-					int overlay = cellptr->Overlay; // RA2: as above
-
-					if (overlay >= 0xcd && overlay <= 0xd5 || overlay >= 0xdf && overlay <= 0xe2 || overlay == 0xe7) { // RA2: as above
-						for (Cell walk = cellptr->CellID; ; walk -= Cell(1, 0)) { // RA2: as above
-							if (!Is_Low_Bridge2(walk)) { // RA2: as above
-								break; // RA2: as above
-							}
-							int hut = Map[walk].Overlay; // RA2: as above
-							if (hut == 0xe7 || hut == 0xe8) { // RA2: as above
-								return(true); // RA2: as above
-							}
-						}
-
-						for (Cell scan = cellptr->CellID; ; scan.X++) { // RA2: as above
-							if (!Is_Low_Bridge2(scan)) { // RA2: as above
-								break; // RA2: as above
-							}
-							int hut = Map[scan].Overlay; // RA2: as above
-							if (hut == 0xe7 || hut == 0xe8) { // RA2: as above
-								return(true); // RA2: as above
-							}
-						}
-
-					} else { // RA2: as above
-
-						for (Cell scan = cellptr->CellID; ; scan.Y++) { // RA2: as above
-							if (!Is_Low_Bridge2(scan)) { // RA2: as above
-								break; // RA2: as above
-							}
-							int hut = Map[scan].Overlay; // RA2: as above
-							if (hut == 0xe7 || hut == 0xe8) { // RA2: as above
-								return(true); // RA2: as above
-							}
-						}
-
-						for (Cell walk = cellptr->CellID; ; walk -= Cell(0, 1)) { // RA2: as above
-							if (!Is_Low_Bridge2(walk)) { // RA2: as above
-								break; // RA2: as above
-							}
-							int hut = Map[walk].Overlay; // RA2: as above
-							if (hut == 0xe7 || hut == 0xe8) { // RA2: as above
-								return(true); // RA2: as above
-							}
-						}
-					}
-				} else if (cellptr->Overlay >= OVERLAY_LOWBRIDGE_01 && cellptr->Overlay <= OVERLAY_LOWBRIDGE_09 || // RA2: as above
-					cellptr->Overlay >= OVERLAY_LOWBRIDGE_19 && cellptr->Overlay <= OVERLAY_LOWBRIDGE_22 || // RA2: as above
-					cellptr->Overlay == OVERLAY_LOWBRIDGE_27) { // RA2: as above
-
-					for (Cell walk = cellptr->CellID; ; walk -= Cell(1, 0)) { // RA2: as above
-						if (!Is_Low_Bridge(walk)) { // RA2: as above
-							break; // RA2: as above
-						}
-						OverlayType overlay = Map[walk].Overlay; // RA2: as above
-						if (overlay == OVERLAY_LOWBRIDGE_27 || overlay == OVERLAY_LOWBRIDGE_28) { // RA2: as above
-							return(true); // RA2: as above
-						}
-					}
-
-					for (Cell scan = cellptr->CellID; ; scan.X++) { // RA2: as above
-						if (!Is_Low_Bridge(scan)) { // RA2: as above
-							break; // RA2: as above
-						}
-						OverlayType overlay = Map[scan].Overlay; // RA2: as above
-						if (overlay == OVERLAY_LOWBRIDGE_27 || overlay == OVERLAY_LOWBRIDGE_28) { // RA2: as above
-							return(true); // RA2: as above
-						}
-					}
-
-				} else { // RA2: as above
-
-					for (Cell scan = cellptr->CellID; ; scan.Y++) { // RA2: as above
-						if (!Is_Low_Bridge(scan)) { // RA2: as above
-							break; // RA2: as above
-						}
-						OverlayType overlay = Map[scan].Overlay; // RA2: as above
-						if (overlay == OVERLAY_LOWBRIDGE_27 || overlay == OVERLAY_LOWBRIDGE_28) { // RA2: as above
-							return(true); // RA2: as above
-						}
-					}
-
-					for (Cell walk = cellptr->CellID; ; walk -= Cell(0, 1)) { // RA2: as above
-						if (!Is_Low_Bridge(walk)) { // RA2: as above
-							break; // RA2: as above
-						}
-						OverlayType overlay = Map[walk].Overlay; // RA2: as above
-						if (overlay == OVERLAY_LOWBRIDGE_27 || overlay == OVERLAY_LOWBRIDGE_28) { // RA2: as above
-							return(true); // RA2: as above
-						}
+		if (dir != FACING_NONE) {
+			Cell entry = search;
+			bool broken = false;
+			while (!broken) {
+				int index = Zone_Connection_Index(search, 3, 0);
+				if (index < 0) {
+					break;
+				}
+				if (!ZoneConnections[index].IsPassable) {
+					broken = true;
+				}
+				if (!broken) {
+					ZoneConnectionClass * con = &ZoneConnections[index];
+					if (con->From == entry) {
+						entry = con->To;
+						search = Adjacent_Cell(entry, dir);
+					} else if (con->To == entry) {
+						entry = con->From;
+						search = Adjacent_Cell(entry, dir);
+					} else {
+						return(true);
 					}
 				}
 			}
-			break; // RA2: as above
-
-		default: { // RA2: as above
-			IsometricTileTypeClass * type = IsometricTileTypes[cellptr->ITType];
-			Cell topleft = cellptr->CellID - Cell(cellptr->SubTile % type->Width, cellptr->SubTile / type->Width); // RA2: as above
-
-			Cell search = topleft + Cell(_x[offset], _y[offset]); // RA2: the probe cell is the variable and the walked entry a copy of it
-			FacingType dir = _facings[offset]; // RA2: as above
-
-			if (dir != FACING_NONE) { // RA2: as above
-				Cell entry = search; // RA2: as above
-				while (true) { // RA2: as above
-					int index = Zone_Connection_Index(search, 3, 0); // RA2: as above
-					if (index < 0) { // RA2: as above
-						break; // RA2: as above
-					}
-					if (!ZoneConnections[index].IsPassable) {
-						return(true);
-					}
-					ZoneConnectionClass * con = &ZoneConnections[index];
-					TPoint2D<short> const (TPoint2D<short>::*step)(TPoint2D<short> const &) const = &TPoint2D<short>::operator +; // level-2 1.001: STEERING keep the point addition as a member call.
-					Cell next; // RA2: the next probe cell is built in a temporary
-					if (con->From == entry) { // RA2: as above
-						entry = con->To; // RA2: as above
-						next = (entry.*step)(AdjacentCell[(int)dir & 7]); // level-2 1.001: STEERING preserve the out-of-line point addition.
-					} else { // RA2: as above
-						if (con->To != entry) { // RA2: as above
-							return(true); // RA2: as above
-						}
-						entry = con->From; // RA2: as above
-						next = (entry.*step)(AdjacentCell[(int)dir & 7]); // level-2 1.001: STEERING preserve the out-of-line point addition.
-					}
-					search = next; // RA2: as above
-				}
+			if (broken) {
+				return(true);
 			}
-			break; // RA2: as above
 		}
+		return(false);
 	}
 
-	return(false); // RA2: as above
+	if (cellptr == NULL) {
+		return(false);
+	}
+
+	if (concrete) {
+		int overlay = cellptr->Overlay;
+		Cell walk;
+		Cell scan;
+		if ((overlay >= 0xcd && overlay <= 0xd5) || (overlay >= 0xdf && overlay <= 0xe2) || overlay == 0xe7) {
+			walk = cellptr->CellID;
+			while (Is_Low_Bridge2(walk)) {
+				int end = Map[walk].Overlay;
+				if (end == 0xe7 || end == 0xe8) {
+					return(true);
+				}
+				walk -= Cell(1, 0);
+			}
+			scan = cellptr->CellID;
+			while (Is_Low_Bridge2(scan)) {
+				int end = Map[scan].Overlay;
+				if (end == 0xe7 || end == 0xe8) {
+					return(true);
+				}
+				scan.X++;
+			}
+			return(false);
+		}
+		scan = cellptr->CellID;
+		while (Is_Low_Bridge2(scan)) {
+			int end = Map[scan].Overlay;
+			if (end == 0xe7 || end == 0xe8) {
+				return(true);
+			}
+			scan.Y++;
+		}
+		walk = cellptr->CellID;
+		while (Is_Low_Bridge2(walk)) {
+			int end = Map[walk].Overlay;
+			if (end == 0xe7 || end == 0xe8) {
+				return(true);
+			}
+			walk -= Cell(0, 1);
+		}
+		return(false);
+	} else {
+		int overlay = cellptr->Overlay;
+		if ((overlay >= OVERLAY_LOWBRIDGE_01 && overlay <= OVERLAY_LOWBRIDGE_09) ||
+				(overlay >= OVERLAY_LOWBRIDGE_19 && overlay <= OVERLAY_LOWBRIDGE_22) || overlay == OVERLAY_LOWBRIDGE_27) {
+			Cell west = cellptr->CellID;
+			while (Is_Low_Bridge(west)) {
+				int end = Map[west].Overlay;
+				if (end == OVERLAY_LOWBRIDGE_27 || end == OVERLAY_LOWBRIDGE_28) {
+					return(true);
+				}
+				west -= Cell(1, 0);
+			}
+
+			Cell east = cellptr->CellID;
+			while (Is_Low_Bridge(east)) {
+				int end = Map[east].Overlay;
+				if (end == OVERLAY_LOWBRIDGE_27 || end == OVERLAY_LOWBRIDGE_28) {
+					return(true);
+				}
+				east.X++;
+			}
+		} else {
+			Cell south = cellptr->CellID;
+			while (Is_Low_Bridge(south)) {
+				int end = Map[south].Overlay;
+				if (end == OVERLAY_LOWBRIDGE_27 || end == OVERLAY_LOWBRIDGE_28) {
+					return(true);
+				}
+				south.Y++;
+			}
+
+			Cell north = cellptr->CellID;
+			while (Is_Low_Bridge(north)) {
+				int end = Map[north].Overlay;
+				if (end == OVERLAY_LOWBRIDGE_27 || end == OVERLAY_LOWBRIDGE_28) {
+					return(true);
+				}
+				north -= Cell(0, 1);
+			}
+		}
+		return(false);
+	}
 }
```

## 2. Our matched form against the community form

```diff
--- community
+++ ours matched
@@ -1,13 +1,13 @@
 bool MapClass::Can_Repair_Bridge(Cell const & cell)
 {
-	static short _entry_x[] = {
+	static short _x[] = {
 		1, 1, 0, 2, 2, 2, 0, 0,
 		0, 0, 0, 2, 2, 2, 2, 2
 	};
-	static short _entry_y[] = {
+	static short _y[] = {
 		2, 2, 2, 1, 1, 0, 2, 2,
 		2, 2, 2, 0, 0, 0, 0, 0
 	};
-	static FacingType _entry_facings[] = {
+	static FacingType _facings[] = {
 		FACING_E,    FACING_E,    FACING_W,    FACING_S,    FACING_S,    FACING_N,    FACING_NONE, FACING_NONE,
 		FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE
@@ -23,9 +23,9 @@
 			int ittype = Map[Cell(Cell(x, y) + cell)].ITType;
 
-			if (ittype >= IsometricTileTypeClass::TrainBridgeSet && ittype < IsometricTileTypeClass::TrainBridgeSet + ARRAY_SIZE(_entry_facings)) {
+			if (ittype >= IsometricTileTypeClass::TrainBridgeSet && ittype < IsometricTileTypeClass::TrainBridgeSet + TRAIN_BRIDGE_COUNT) {
 				found = true;
 				cellptr = &Map[Cell(Cell(x, y) + cell)];
 				offset = ittype - IsometricTileTypeClass::TrainBridgeSet;
-			} else if (ittype >= IsometricTileTypeClass::BridgeSet && ittype < IsometricTileTypeClass::BridgeSet + ARRAY_SIZE(_entry_facings)) {
+			} else if (ittype >= IsometricTileTypeClass::BridgeSet && ittype < IsometricTileTypeClass::BridgeSet + BRIDGE_COUNT) {
 				found = true;
 				cellptr = &Map[Cell(Cell(x, y) + cell)];
@@ -46,6 +46,6 @@
 		IsometricTileTypeClass * isotype = IsometricTileTypes[cellptr->ITType];
 		Cell topleft = cellptr->CellID - Cell(cellptr->SubTile % isotype->Width, cellptr->SubTile / isotype->Width);
-		Cell search = Cell(_entry_x[offset], _entry_y[offset]) + topleft;
-		FacingType dir = _entry_facings[offset];
+		Cell search = Cell(_x[offset], _y[offset]) + topleft;
+		FacingType dir = _facings[offset];
 
 		if (dir != FACING_NONE) {
@@ -88,9 +88,9 @@
 		Cell walk;
 		Cell scan;
-		if (overlay >= LB2(1) && overlay <= LB2(9) || overlay >= LB2(19) && overlay <= LB2(22) || overlay == LB2(27)) {
+		if ((overlay >= 0xcd && overlay <= 0xd5) || (overlay >= 0xdf && overlay <= 0xe2) || overlay == 0xe7) {
 			walk = cellptr->CellID;
 			while (Is_Low_Bridge2(walk)) {
 				int end = Map[walk].Overlay;
-				if (end == LB2(27) || end == LB2(28)) {
+				if (end == 0xe7 || end == 0xe8) {
 					return(true);
 				}
@@ -100,5 +100,5 @@
 			while (Is_Low_Bridge2(scan)) {
 				int end = Map[scan].Overlay;
-				if (end == LB2(27) || end == LB2(28)) {
+				if (end == 0xe7 || end == 0xe8) {
 					return(true);
 				}
@@ -110,5 +110,5 @@
 		while (Is_Low_Bridge2(scan)) {
 			int end = Map[scan].Overlay;
-			if (end == LB2(27) || end == LB2(28)) {
+			if (end == 0xe7 || end == 0xe8) {
 				return(true);
 			}
@@ -118,5 +118,5 @@
 		while (Is_Low_Bridge2(walk)) {
 			int end = Map[walk].Overlay;
-			if (end == LB2(27) || end == LB2(28)) {
+			if (end == 0xe7 || end == 0xe8) {
 				return(true);
 			}
@@ -126,40 +126,41 @@
 	} else {
 		int overlay = cellptr->Overlay;
-		Cell walk;
-		Cell scan;
-		if (overlay >= OVERLAY_LOWBRIDGE_01 && overlay <= OVERLAY_LOWBRIDGE_09 || overlay >= OVERLAY_LOWBRIDGE_19 && overlay <= OVERLAY_LOWBRIDGE_22 || overlay == OVERLAY_LOWBRIDGE_27) {
-			walk = cellptr->CellID;
-			while (Is_Low_Bridge(walk)) {
-				int end = Map[walk].Overlay;
+		if ((overlay >= OVERLAY_LOWBRIDGE_01 && overlay <= OVERLAY_LOWBRIDGE_09) ||
+				(overlay >= OVERLAY_LOWBRIDGE_19 && overlay <= OVERLAY_LOWBRIDGE_22) || overlay == OVERLAY_LOWBRIDGE_27) {
+			Cell west = cellptr->CellID;
+			while (Is_Low_Bridge(west)) {
+				int end = Map[west].Overlay;
 				if (end == OVERLAY_LOWBRIDGE_27 || end == OVERLAY_LOWBRIDGE_28) {
 					return(true);
 				}
-				walk -= Cell(1, 0);
+				west -= Cell(1, 0);
 			}
-			scan = cellptr->CellID;
-			while (Is_Low_Bridge(scan)) {
-				int end = Map[scan].Overlay;
+
+			Cell east = cellptr->CellID;
+			while (Is_Low_Bridge(east)) {
+				int end = Map[east].Overlay;
 				if (end == OVERLAY_LOWBRIDGE_27 || end == OVERLAY_LOWBRIDGE_28) {
 					return(true);
 				}
-				scan.X++;
+				east.X++;
 			}
-			return(false);
-		}
-		scan = cellptr->CellID;
-		while (Is_Low_Bridge(scan)) {
-			int end = Map[scan].Overlay;
-			if (end == OVERLAY_LOWBRIDGE_27 || end == OVERLAY_LOWBRIDGE_28) {
-				return(true);
+		} else {
+			Cell south = cellptr->CellID;
+			while (Is_Low_Bridge(south)) {
+				int end = Map[south].Overlay;
+				if (end == OVERLAY_LOWBRIDGE_27 || end == OVERLAY_LOWBRIDGE_28) {
+					return(true);
+				}
+				south.Y++;
 			}
-			scan.Y++;
-		}
-		walk = cellptr->CellID;
-		while (Is_Low_Bridge(walk)) {
-			int end = Map[walk].Overlay;
-			if (end == OVERLAY_LOWBRIDGE_27 || end == OVERLAY_LOWBRIDGE_28) {
-				return(true);
+
+			Cell north = cellptr->CellID;
+			while (Is_Low_Bridge(north)) {
+				int end = Map[north].Overlay;
+				if (end == OVERLAY_LOWBRIDGE_27 || end == OVERLAY_LOWBRIDGE_28) {
+					return(true);
+				}
+				north -= Cell(0, 1);
 			}
-			walk -= Cell(0, 1);
 		}
 		return(false);
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -1,185 +1,167 @@
-bool MapClass::Can_Repair_Bridge(Cell const & cell) // RA2: as above
+bool MapClass::Can_Repair_Bridge(Cell const & cell)
 {
-	static short _x[] = { // RA2: as above
-		1, 1, 0, 2, 2, 2, 0, 0, // RA2: as above
-		0, 0, 0, 2, 2, 2, 2, 2 // RA2: as above
+	static short _entry_x[] = {
+		1, 1, 0, 2, 2, 2, 0, 0,
+		0, 0, 0, 2, 2, 2, 2, 2
 	};
-	static short _y[] = { // RA2: as above
-		2, 2, 2, 1, 1, 0, 2, 2, // RA2: as above
-		2, 2, 2, 0, 0, 0, 0, 0 // RA2: as above
+	static short _entry_y[] = {
+		2, 2, 2, 1, 1, 0, 2, 2,
+		2, 2, 2, 0, 0, 0, 0, 0
 	};
-	static FacingType _facings[] = { // RA2: as above
-		FACING_E,       FACING_E,    FACING_W,    FACING_S,    FACING_S,    FACING_N, FACING_NONE, FACING_NONE, // RA2: as above
-		FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE // RA2: as above
+	static FacingType _entry_facings[] = {
+		FACING_E,    FACING_E,    FACING_W,    FACING_S,    FACING_S,    FACING_N,    FACING_NONE, FACING_NONE,
+		FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE, FACING_NONE
 	};
 
-	bool found = false; // RA2: as above
-	bool second_low_bridge = false; // RA2: the second low bridge kind (overlays 0xCD-0xE8) is searched as well
-	CellClass * cellptr = NULL; // RA2: as above
-	int offset = -1; // RA2: as above
+	bool found = false;
+	bool concrete = false;
+	CellClass * cellptr = NULL;
+	int offset = -1;
 
-	for (int y = -2; y < 3; y++) { // RA2: as above
-		for (int x = -2; x < 3; x++) { // RA2: as above
+	for (int y = -2; y < 3; y++) {
+		for (int x = -2; x < 3; x++) {
+			int ittype = Map[Cell(Cell(x, y) + cell)].ITType;
 
-			IsometricTileType ittype = Map[Cell(cell + Cell(x, y))].ITType; // RA2: as above
-
-			if (ittype >= IsometricTileTypeClass::TrainBridgeSet && ittype < IsometricTileTypeClass::TrainBridgeSet + TRAIN_BRIDGE_COUNT) { // RA2: as above
-				found = true; // RA2: as above
-				cellptr = &Map[Cell(cell + Cell(x, y))]; // RA2: as above
-				offset = ittype - IsometricTileTypeClass::TrainBridgeSet; // RA2: as above
-			} else if (ittype >= IsometricTileTypeClass::BridgeSet && ittype < IsometricTileTypeClass::BridgeSet + BRIDGE_COUNT) { // RA2: as above
-				found = true; // RA2: as above
-				cellptr = &Map[Cell(cell + Cell(x, y))]; // RA2: as above
-				offset = ittype - IsometricTileTypeClass::BridgeSet; // RA2: as above
-			} else {
-				if (Is_Low_Bridge(Cell(x, y) + cell)) { // RA2: the sum is written offset first
-					found = false; // RA2: as above
-					second_low_bridge = false; // RA2: as above
-					cellptr = &Map[Cell(cell + Cell(x, y))]; // RA2: as above
-				} else if (Is_Low_Bridge2(Cell(x, y) + cell)) { // RA2: the second low bridge kind
-					found = false; // RA2: as above
-					second_low_bridge = true; // RA2: as above
-					cellptr = &Map[Cell(cell + Cell(x, y))]; // RA2: as above
-				}
+			if (ittype >= IsometricTileTypeClass::TrainBridgeSet && ittype < IsometricTileTypeClass::TrainBridgeSet + ARRAY_SIZE(_entry_facings)) {
+				found = true;
+				cellptr = &Map[Cell(Cell(x, y) + cell)];
+				offset = ittype - IsometricTileTypeClass::TrainBridgeSet;
+			} else if (ittype >= IsometricTileTypeClass::BridgeSet && ittype < IsometricTileTypeClass::BridgeSet + ARRAY_SIZE(_entry_facings)) {
+				found = true;
+				cellptr = &Map[Cell(Cell(x, y) + cell)];
+				offset = ittype - IsometricTileTypeClass::BridgeSet;
+			} else if (Is_Low_Bridge(Cell(x, y) + cell)) {
+				found = false;
+				concrete = false;
+				cellptr = &Map[Cell(Cell(x, y) + cell)];
+			} else if (Is_Low_Bridge2(Cell(x, y) + cell)) {
+				found = false;
+				concrete = true;
+				cellptr = &Map[Cell(Cell(x, y) + cell)];
 			}
 		}
 	}
 
-	switch (found) { // RA2: a switch on the flag (an if/else keeps the flag in a register, the executable keeps it in memory)
-		case false: // RA2: as above
-			if (cellptr != NULL) { // RA2: as above
+	if (found) {
+		IsometricTileTypeClass * isotype = IsometricTileTypes[cellptr->ITType];
+		Cell topleft = cellptr->CellID - Cell(cellptr->SubTile % isotype->Width, cellptr->SubTile / isotype->Width);
+		Cell search = Cell(_entry_x[offset], _entry_y[offset]) + topleft;
+		FacingType dir = _entry_facings[offset];
 
-				if (second_low_bridge) { // RA2: the second low bridge kind uses overlays 0xCD-0xE8 and huts 0xE7/0xE8
-					int overlay = cellptr->Overlay; // RA2: as above
-
-					if (overlay >= 0xcd && overlay <= 0xd5 || overlay >= 0xdf && overlay <= 0xe2 || overlay == 0xe7) { // RA2: as above
-						for (Cell walk = cellptr->CellID; ; walk -= Cell(1, 0)) { // RA2: as above
-							if (!Is_Low_Bridge2(walk)) { // RA2: as above
-								break; // RA2: as above
-							}
-							int hut = Map[walk].Overlay; // RA2: as above
-							if (hut == 0xe7 || hut == 0xe8) { // RA2: as above
-								return(true); // RA2: as above
-							}
-						}
-
-						for (Cell scan = cellptr->CellID; ; scan.X++) { // RA2: as above
-							if (!Is_Low_Bridge2(scan)) { // RA2: as above
-								break; // RA2: as above
-							}
-							int hut = Map[scan].Overlay; // RA2: as above
-							if (hut == 0xe7 || hut == 0xe8) { // RA2: as above
-								return(true); // RA2: as above
-							}
-						}
-
-					} else { // RA2: as above
-
-						for (Cell scan = cellptr->CellID; ; scan.Y++) { // RA2: as above
-							if (!Is_Low_Bridge2(scan)) { // RA2: as above
-								break; // RA2: as above
-							}
-							int hut = Map[scan].Overlay; // RA2: as above
-							if (hut == 0xe7 || hut == 0xe8) { // RA2: as above
-								return(true); // RA2: as above
-							}
-						}
-
-						for (Cell walk = cellptr->CellID; ; walk -= Cell(0, 1)) { // RA2: as above
-							if (!Is_Low_Bridge2(walk)) { // RA2: as above
-								break; // RA2: as above
-							}
-							int hut = Map[walk].Overlay; // RA2: as above
-							if (hut == 0xe7 || hut == 0xe8) { // RA2: as above
-								return(true); // RA2: as above
-							}
-						}
-					}
-				} else if (cellptr->Overlay >= OVERLAY_LOWBRIDGE_01 && cellptr->Overlay <= OVERLAY_LOWBRIDGE_09 || // RA2: as above
-					cellptr->Overlay >= OVERLAY_LOWBRIDGE_19 && cellptr->Overlay <= OVERLAY_LOWBRIDGE_22 || // RA2: as above
-					cellptr->Overlay == OVERLAY_LOWBRIDGE_27) { // RA2: as above
-
-					for (Cell walk = cellptr->CellID; ; walk -= Cell(1, 0)) { // RA2: as above
-						if (!Is_Low_Bridge(walk)) { // RA2: as above
-							break; // RA2: as above
-						}
-						OverlayType overlay = Map[walk].Overlay; // RA2: as above
-						if (overlay == OVERLAY_LOWBRIDGE_27 || overlay == OVERLAY_LOWBRIDGE_28) { // RA2: as above
-							return(true); // RA2: as above
-						}
-					}
-
-					for (Cell scan = cellptr->CellID; ; scan.X++) { // RA2: as above
-						if (!Is_Low_Bridge(scan)) { // RA2: as above
-							break; // RA2: as above
-						}
-						OverlayType overlay = Map[scan].Overlay; // RA2: as above
-						if (overlay == OVERLAY_LOWBRIDGE_27 || overlay == OVERLAY_LOWBRIDGE_28) { // RA2: as above
-							return(true); // RA2: as above
-						}
-					}
-
-				} else { // RA2: as above
-
-					for (Cell scan = cellptr->CellID; ; scan.Y++) { // RA2: as above
-						if (!Is_Low_Bridge(scan)) { // RA2: as above
-							break; // RA2: as above
-						}
-						OverlayType overlay = Map[scan].Overlay; // RA2: as above
-						if (overlay == OVERLAY_LOWBRIDGE_27 || overlay == OVERLAY_LOWBRIDGE_28) { // RA2: as above
-							return(true); // RA2: as above
-						}
-					}
-
-					for (Cell walk = cellptr->CellID; ; walk -= Cell(0, 1)) { // RA2: as above
-						if (!Is_Low_Bridge(walk)) { // RA2: as above
-							break; // RA2: as above
-						}
-						OverlayType overlay = Map[walk].Overlay; // RA2: as above
-						if (overlay == OVERLAY_LOWBRIDGE_27 || overlay == OVERLAY_LOWBRIDGE_28) { // RA2: as above
-							return(true); // RA2: as above
-						}
+		if (dir != FACING_NONE) {
+			Cell entry = search;
+			bool broken = false;
+			while (!broken) {
+				int index = Zone_Connection_Index(search, 3, 0);
+				if (index < 0) {
+					break;
+				}
+				if (!ZoneConnections[index].IsPassable) {
+					broken = true;
+				}
+				if (!broken) {
+					ZoneConnectionClass * con = &ZoneConnections[index];
+					if (con->From == entry) {
+						entry = con->To;
+						search = Adjacent_Cell(entry, dir);
+					} else if (con->To == entry) {
+						entry = con->From;
+						search = Adjacent_Cell(entry, dir);
+					} else {
+						return(true);
 					}
 				}
 			}
-			break; // RA2: as above
-
-		default: { // RA2: as above
-			IsometricTileTypeClass * type = IsometricTileTypes[cellptr->ITType];
-			Cell topleft = cellptr->CellID - Cell(cellptr->SubTile % type->Width, cellptr->SubTile / type->Width); // RA2: as above
-
-			Cell search = topleft + Cell(_x[offset], _y[offset]); // RA2: the probe cell is the variable and the walked entry a copy of it
-			FacingType dir = _facings[offset]; // RA2: as above
-
-			if (dir != FACING_NONE) { // RA2: as above
-				Cell entry = search; // RA2: as above
-				while (true) { // RA2: as above
-					int index = Zone_Connection_Index(search, 3, 0); // RA2: as above
-					if (index < 0) { // RA2: as above
-						break; // RA2: as above
-					}
-					if (!ZoneConnections[index].IsPassable) {
-						return(true);
-					}
-					ZoneConnectionClass * con = &ZoneConnections[index];
-					TPoint2D<short> const (TPoint2D<short>::*step)(TPoint2D<short> const &) const = &TPoint2D<short>::operator +; // level-2 1.001: STEERING keep the point addition as a member call.
-					Cell next; // RA2: the next probe cell is built in a temporary
-					if (con->From == entry) { // RA2: as above
-						entry = con->To; // RA2: as above
-						next = (entry.*step)(AdjacentCell[(int)dir & 7]); // level-2 1.001: STEERING preserve the out-of-line point addition.
-					} else { // RA2: as above
-						if (con->To != entry) { // RA2: as above
-							return(true); // RA2: as above
-						}
-						entry = con->From; // RA2: as above
-						next = (entry.*step)(AdjacentCell[(int)dir & 7]); // level-2 1.001: STEERING preserve the out-of-line point addition.
-					}
-					search = next; // RA2: as above
-				}
+			if (broken) {
+				return(true);
 			}
-			break; // RA2: as above
 		}
+		return(false);
 	}
 
-	return(false); // RA2: as above
+	if (cellptr == NULL) {
+		return(false);
+	}
+
+	if (concrete) {
+		int overlay = cellptr->Overlay;
+		Cell walk;
+		Cell scan;
+		if (overlay >= LB2(1) && overlay <= LB2(9) || overlay >= LB2(19) && overlay <= LB2(22) || overlay == LB2(27)) {
+			walk = cellptr->CellID;
+			while (Is_Low_Bridge2(walk)) {
+				int end = Map[walk].Overlay;
+				if (end == LB2(27) || end == LB2(28)) {
+					return(true);
+				}
+				walk -= Cell(1, 0);
+			}
+			scan = cellptr->CellID;
+			while (Is_Low_Bridge2(scan)) {
+				int end = Map[scan].Overlay;
+				if (end == LB2(27) || end == LB2(28)) {
+					return(true);
+				}
+				scan.X++;
+			}
+			return(false);
+		}
+		scan = cellptr->CellID;
+		while (Is_Low_Bridge2(scan)) {
+			int end = Map[scan].Overlay;
+			if (end == LB2(27) || end == LB2(28)) {
+				return(true);
+			}
+			scan.Y++;
+		}
+		walk = cellptr->CellID;
+		while (Is_Low_Bridge2(walk)) {
+			int end = Map[walk].Overlay;
+			if (end == LB2(27) || end == LB2(28)) {
+				return(true);
+			}
+			walk -= Cell(0, 1);
+		}
+		return(false);
+	} else {
+		int overlay = cellptr->Overlay;
+		Cell walk;
+		Cell scan;
+		if (overlay >= OVERLAY_LOWBRIDGE_01 && overlay <= OVERLAY_LOWBRIDGE_09 || overlay >= OVERLAY_LOWBRIDGE_19 && overlay <= OVERLAY_LOWBRIDGE_22 || overlay == OVERLAY_LOWBRIDGE_27) {
+			walk = cellptr->CellID;
+			while (Is_Low_Bridge(walk)) {
+				int end = Map[walk].Overlay;
+				if (end == OVERLAY_LOWBRIDGE_27 || end == OVERLAY_LOWBRIDGE_28) {
+					return(true);
+				}
+				walk -= Cell(1, 0);
+			}
+			scan = cellptr->CellID;
+			while (Is_Low_Bridge(scan)) {
+				int end = Map[scan].Overlay;
+				if (end == OVERLAY_LOWBRIDGE_27 || end == OVERLAY_LOWBRIDGE_28) {
+					return(true);
+				}
+				scan.X++;
+			}
+			return(false);
+		}
+		scan = cellptr->CellID;
+		while (Is_Low_Bridge(scan)) {
+			int end = Map[scan].Overlay;
+			if (end == OVERLAY_LOWBRIDGE_27 || end == OVERLAY_LOWBRIDGE_28) {
+				return(true);
+			}
+			scan.Y++;
+		}
+		walk = cellptr->CellID;
+		while (Is_Low_Bridge(walk)) {
+			int end = Map[walk].Overlay;
+			if (end == OVERLAY_LOWBRIDGE_27 || end == OVERLAY_LOWBRIDGE_28) {
+				return(true);
+			}
+			walk -= Cell(0, 1);
+		}
+		return(false);
+	}
 }
```
