# 0x163130 ?Update_Cell_Subzones@MapClass@@QAEXABVCell@@@Z (src/m85/src/map.cpp)

Origin: recent port: batch_47_*. Community source: gibbo8c1df2_map.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -1,10 +1,9 @@
 void MapClass::Update_Cell_Subzones(Cell const & cell)
 {
-	if (In_Local_Radar(cell)) {
+	if (In_Local_Radar(cell, true)) {
 
 		int y;
 		int x;
-		Cell trycell;
-		for (int subzone = 2; subzone >= 0; subzone--) {
+		for (int subzone = SUBZONE_COUNT-1; subzone >= 0; subzone--) {
 
 			/*
@@ -12,10 +11,6 @@
 			 * that surrounds the changed cell for this coarseness level.
 			 */
-			int var = subzone + 1;
-			Rect bounds;
-			bounds.Width = 1 << var;
-			bounds.Height = bounds.Width;
-			bounds.X = cell.X - cell.X % bounds.Width;
-			bounds.Y = cell.Y - cell.Y % bounds.Height;
+			int size = 1 << (subzone + 1);
+			Rect bounds = Rect(Point2D(cell.X - cell.X % size, cell.Y - cell.Y % size), size, size);
 
 			/*
@@ -24,7 +19,5 @@
 			DynamicVectorClass<unsigned short> collected;
 			SUBZONE_CONNECTION_HASH_SET * set = SubzoneConnectionHashTable[subzone];
-			for (int bucket = 0; bucket < set->NumBuckets; bucket++) {
-				set->Buckets[bucket].Clear();
-			}
+			set->Clear();
 
 			DynamicVectorClass<SubzoneTrackingStruct> * track = &SubzoneTracking[subzone];
@@ -36,5 +29,5 @@
 			for (y = bounds.Y; y < bounds.Y + bounds.Height; y++) {
 				for (x = bounds.X; x < bounds.Width + bounds.X; x++) {
-					CellSubzoneStruct * subptr = Subzone_Of(this, Cell(x, y)); // level-2 1.001 (partial): lookups through Get_Cell_Zone_Index
+					CellSubzoneStruct * subptr = Subzone_Of(this, Cell(x, y)); // level-2 1.001: STEERING retain a separate Cell temporary for this lookup
 					unsigned short subid = subptr->SubzoneID[subzone];
 					if (subid != 0) {
@@ -50,5 +43,5 @@
 					}
 					subptr->SubzoneID[subzone] = 0;
-					subptr->ZoneID = Get_Cell_Zone_ID(Cell(x, y));
+					subptr->ZoneID = Zone_Of(this, Cell(x, y))->ZoneID;
 				}
 			}
@@ -59,9 +52,9 @@
 			 * then clear its own connection list.
 			 */
-			for (int idx = collected.Count() - 1; idx >= 0; idx--) {
-				unsigned short subid = collected[idx];
+			for (y = collected.Count() - 1; y >= 0; y--) {
+				unsigned short subid = collected[y];
 				SubzoneTrackingStruct * entry = &SubzoneTracking[subzone][subid];
-				for (int i = entry->Connections.Count() - 1; i >= 0; i--) {
-					SubzoneTrackingStruct * neighbor = &SubzoneTracking[subzone][entry->Connections[i].SubzoneID];
+				for (x = entry->Connections.Count() - 1; x >= 0; x--) {
+					SubzoneTrackingStruct * neighbor = &SubzoneTracking[subzone][entry->Connections[x].SubzoneID];
 					int j;
 					for (j = neighbor->Connections.Count() - 1; j >= 0; j--) {
@@ -83,22 +76,20 @@
 				for (x = bounds.X; x < bounds.Width + bounds.X; x++) {
 
-					Cell cella;
-					cella.X = x;
-					cella.Y = y;
-					if (In_Local_Radar(cella)) {
+					if (In_Local_Radar(Cell(x, y), true)) {
 
-						CellSubzoneStruct * subptr = Subzone_Of(this, cella);
-						int passability = CellZones[Get_Cell_Zone_Index(cella)].Passability;
+						CellSubzoneStruct * subptr = Subzone_Of(this, Cell(x, y)); // level-2 1.001: STEERING retain a separate Cell temporary for this lookup
+						int passability = Zone_Of(this, Cell(x, y))->Passability;
 						if (passability != PASSABLE_OUTSIDE && subptr->SubzoneID[subzone] == 0) {
 
-							trycell.Y = y;
-							trycell.X = x;
-							Subzone_Span(subptr, subzone, entry_count, bounds, trycell);
+							Cell seed(x, y);
+							Subzone_Span(subptr, subzone, entry_count, bounds, seed);
 
 							track->Add(SubzoneTrackingStruct());
 
 							SubzoneTrackingStruct * added = &(*track)[entry_count];
-							int parent = 0;
-							if (subzone != 2) {
+							int parent;
+							if (subzone == SUBZONE_COUNT-1) {
+								parent = 0;
+							} else {
 								parent = subptr->SubzoneID[subzone + 1];
 							}
@@ -106,5 +97,5 @@
 							added->Passability = (PassabilityType)passability;
 							added->Connections.Set_Growth_Step(16);
-							added->ThreatRegion = Cell_Region(trycell); // level-2 1.001 (partial): inline Cell_Region restored
+							added->ThreatRegion = Cell_Region(Cell(x, y));
 
 							entry_count++;
@@ -124,5 +115,6 @@
 			for (int connection_index = ZoneConnections.Count() - 1; connection_index >= 0; connection_index--) {
 				ZoneConnectionClass & connection = ZoneConnections[connection_index];
-				if (bounds.Is_Point_Within(Point2D(connection.From.X, connection.From.Y)) || bounds.Is_Point_Within(Point2D(connection.To.X, connection.To.Y))) { // level-2 1.001 (partial): inline rect test restored
+				if (bounds.Is_Point_Within(Point2D(connection.From.X, connection.From.Y))
+					|| bounds.Is_Point_Within(Point2D(connection.To.X, connection.To.Y))) {
 					if (connection.IsPassable) {
 						Register_Zone_Connection_Entries(&connection, subzone); // RA2: by pointer
@@ -136,7 +128,8 @@
 			 */
 			for (int bucket_index = 0; bucket_index < 256; bucket_index++) {
-				if (set->Buckets[bucket_index].Count() > 0) {
-					SUBZONE_CONNECTION_HASH_SET::ObjectType * object = &set->Buckets[bucket_index][0];
-					for (int index = set->Buckets[bucket_index].Count(); index > 0; index--) {
+				SUBZONE_CONNECTION_HASH_SET::BucketType & bucket = set->Buckets[bucket_index];
+				if (bucket.Count() > 0) {
+					SUBZONE_CONNECTION_HASH_SET::ObjectType * object = &bucket[0];
+					for (int index = bucket.Count(); index > 0; index--) {
 						unsigned packed = object->Value.SubzoneID;
 						WORD low = LOWORD(packed);
@@ -144,11 +137,9 @@
 						bool costly = object->Value.IsCrossBlock;
 
-						SubzoneConnectionStruct conn;
-						conn.SubzoneID = high;
+						SubzoneConnectionStruct conn(high);
 						conn.IsCrossBlock = costly;
 						(*track)[low].Connections.Add(conn);
 
-						SubzoneConnectionStruct conn2;
-						conn2.SubzoneID = low;
+						SubzoneConnectionStruct conn2(low);
 						conn2.IsCrossBlock = costly;
 						(*track)[high].Connections.Add(conn2);
@@ -164,13 +155,11 @@
 		 * for the finest (8 cell) window around the changed cell.
 		 */
-		int basex = cell.X - cell.X % 8;
-		int basey = cell.Y - cell.Y % 8;
-		for (y = basey; y < basey + 8; y++) {
-			for (x = basex; x < basex + 8; x++) {
-				trycell.X = x;
-				trycell.Y = y;
-				if (In_Local_Radar(trycell)) {
-					CellSubzoneStruct * subptr = Subzone_Of(this, trycell);
-					for (int level = 0; level < 2; level++) {
+		Rect block(cell.X - cell.X % 8, cell.Y - cell.Y % 8, 8, 8);
+		for (y = block.Y; y < block.Y + block.Height; y++) {
+			for (x = block.X; x < block.Width + block.X; x++) {
+				Cell probe(x, y);
+				if (In_Local_Radar(probe, true)) {
+					CellSubzoneStruct * subptr = Subzone_Of(this, Cell(x, y)); // level-2 1.001: STEERING retain a separate Cell temporary for this lookup
+					for (int level = 0; level < SUBZONE_COUNT-1; level++) {
 						SubzoneTracking[level][subptr->SubzoneID[level]].ParentSubzoneID = subptr->SubzoneID[level + 1];
 					}
```

## 2. Our matched form against the community form

```diff
--- community
+++ ours matched
@@ -7,7 +7,14 @@
 		for (int subzone = SUBZONE_COUNT-1; subzone >= 0; subzone--) {
 
+			/*
+			 * Compute the square window of cells (aligned to the level's grid size)
+			 * that surrounds the changed cell for this coarseness level.
+			 */
 			int size = 1 << (subzone + 1);
 			Rect bounds = Rect(Point2D(cell.X - cell.X % size, cell.Y - cell.Y % size), size, size);
 
+			/*
+			 * Clear out every bucket of the connection hash set for this level.
+			 */
 			DynamicVectorClass<unsigned short> collected;
 			SUBZONE_CONNECTION_HASH_SET * set = SubzoneConnectionHashTable[subzone];
@@ -16,7 +23,11 @@
 			DynamicVectorClass<SubzoneTrackingStruct> * track = &SubzoneTracking[subzone];
 
+			/*
+			 * Collect the distinct subzone ids that currently occupy the window and
+			 * clear each cell's subzone id for this level (refreshing its zone id).
+			 */
 			for (y = bounds.Y; y < bounds.Y + bounds.Height; y++) {
 				for (x = bounds.X; x < bounds.Width + bounds.X; x++) {
-					CellSubzoneStruct * subptr = Subzone_Of(this, Cell(x, y));
+					CellSubzoneStruct * subptr = Subzone_Of(this, Cell(x, y)); // level-2 1.001: STEERING retain a separate Cell temporary for this lookup
 					unsigned short subid = subptr->SubzoneID[subzone];
 					if (subid != 0) {
@@ -36,4 +47,9 @@
 			}
 
+			/*
+			 * Remove the collected subzones from the tracking graph. For each one,
+			 * delete the mirror connection entry from every neighbor it connected to,
+			 * then clear its own connection list.
+			 */
 			for (y = collected.Count() - 1; y >= 0; y--) {
 				unsigned short subid = collected[y];
@@ -52,4 +68,8 @@
 			}
 
+			/*
+			 * Flood fill fresh subzones for the now unassigned passable cells in the
+			 * window, recording a tracking entry for each new subzone.
+			 */
 			int entry_count = SubzoneTrackingEntryCount[subzone];
 			for (y = bounds.Y; y < bounds.Y + bounds.Height; y++) {
@@ -58,5 +78,5 @@
 					if (In_Local_Radar(Cell(x, y), true)) {
 
-						CellSubzoneStruct * subptr = Subzone_Of(this, Cell(x, y));
+						CellSubzoneStruct * subptr = Subzone_Of(this, Cell(x, y)); // level-2 1.001: STEERING retain a separate Cell temporary for this lookup
 						int passability = Zone_Of(this, Cell(x, y))->Passability;
 						if (passability != PASSABLE_OUTSIDE && subptr->SubzoneID[subzone] == 0) {
@@ -90,4 +110,7 @@
 			SubzoneTrackingEntryCount[subzone] = entry_count;
 
+			/*
+			 * Re-register any zone connections whose endpoints fall inside the window.
+			 */
 			for (int connection_index = ZoneConnections.Count() - 1; connection_index >= 0; connection_index--) {
 				ZoneConnectionClass & connection = ZoneConnections[connection_index];
@@ -95,9 +118,13 @@
 					|| bounds.Is_Point_Within(Point2D(connection.To.X, connection.To.Y))) {
 					if (connection.IsPassable) {
-						Register_Zone_Connection_Entries(connection, subzone);
+						Register_Zone_Connection_Entries(&connection, subzone); // RA2: by pointer
 					}
 				}
 			}
 
+			/*
+			 * Walk every bucket of the connection hash set and register both endpoints
+			 * of each recorded connection into the subzone tracking list.
+			 */
 			for (int bucket_index = 0; bucket_index < 256; bucket_index++) {
 				SUBZONE_CONNECTION_HASH_SET::BucketType & bucket = set->Buckets[bucket_index];
@@ -124,4 +151,8 @@
 		}
 
+		/*
+		 * Propagate the parent subzone identifiers down through the coarser levels
+		 * for the finest (8 cell) window around the changed cell.
+		 */
 		Rect block(cell.X - cell.X % 8, cell.Y - cell.Y % 8, 8, 8);
 		for (y = block.Y; y < block.Y + block.Height; y++) {
@@ -129,5 +160,5 @@
 				Cell probe(x, y);
 				if (In_Local_Radar(probe, true)) {
-					CellSubzoneStruct * subptr = Subzone_Of(this, Cell(x, y));
+					CellSubzoneStruct * subptr = Subzone_Of(this, Cell(x, y)); // level-2 1.001: STEERING retain a separate Cell temporary for this lookup
 					for (int level = 0; level < SUBZONE_COUNT-1; level++) {
 						SubzoneTracking[level][subptr->SubzoneID[level]].ParentSubzoneID = subptr->SubzoneID[level + 1];
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -1,40 +1,22 @@
 void MapClass::Update_Cell_Subzones(Cell const & cell)
 {
-	if (In_Local_Radar(cell)) {
+	if (In_Local_Radar(cell, true)) {
 
 		int y;
 		int x;
-		Cell trycell;
-		for (int subzone = 2; subzone >= 0; subzone--) {
+		for (int subzone = SUBZONE_COUNT-1; subzone >= 0; subzone--) {
 
-			/*
-			 * Compute the square window of cells (aligned to the level's grid size)
-			 * that surrounds the changed cell for this coarseness level.
-			 */
-			int var = subzone + 1;
-			Rect bounds;
-			bounds.Width = 1 << var;
-			bounds.Height = bounds.Width;
-			bounds.X = cell.X - cell.X % bounds.Width;
-			bounds.Y = cell.Y - cell.Y % bounds.Height;
+			int size = 1 << (subzone + 1);
+			Rect bounds = Rect(Point2D(cell.X - cell.X % size, cell.Y - cell.Y % size), size, size);
 
-			/*
-			 * Clear out every bucket of the connection hash set for this level.
-			 */
 			DynamicVectorClass<unsigned short> collected;
 			SUBZONE_CONNECTION_HASH_SET * set = SubzoneConnectionHashTable[subzone];
-			for (int bucket = 0; bucket < set->NumBuckets; bucket++) {
-				set->Buckets[bucket].Clear();
-			}
+			set->Clear();
 
 			DynamicVectorClass<SubzoneTrackingStruct> * track = &SubzoneTracking[subzone];
 
-			/*
-			 * Collect the distinct subzone ids that currently occupy the window and
-			 * clear each cell's subzone id for this level (refreshing its zone id).
-			 */
 			for (y = bounds.Y; y < bounds.Y + bounds.Height; y++) {
 				for (x = bounds.X; x < bounds.Width + bounds.X; x++) {
-					CellSubzoneStruct * subptr = Subzone_Of(this, Cell(x, y)); // level-2 1.001 (partial): lookups through Get_Cell_Zone_Index
+					CellSubzoneStruct * subptr = Subzone_Of(this, Cell(x, y));
 					unsigned short subid = subptr->SubzoneID[subzone];
 					if (subid != 0) {
@@ -50,18 +32,13 @@
 					}
 					subptr->SubzoneID[subzone] = 0;
-					subptr->ZoneID = Get_Cell_Zone_ID(Cell(x, y));
+					subptr->ZoneID = Zone_Of(this, Cell(x, y))->ZoneID;
 				}
 			}
 
-			/*
-			 * Remove the collected subzones from the tracking graph. For each one,
-			 * delete the mirror connection entry from every neighbor it connected to,
-			 * then clear its own connection list.
-			 */
-			for (int idx = collected.Count() - 1; idx >= 0; idx--) {
-				unsigned short subid = collected[idx];
+			for (y = collected.Count() - 1; y >= 0; y--) {
+				unsigned short subid = collected[y];
 				SubzoneTrackingStruct * entry = &SubzoneTracking[subzone][subid];
-				for (int i = entry->Connections.Count() - 1; i >= 0; i--) {
-					SubzoneTrackingStruct * neighbor = &SubzoneTracking[subzone][entry->Connections[i].SubzoneID];
+				for (x = entry->Connections.Count() - 1; x >= 0; x--) {
+					SubzoneTrackingStruct * neighbor = &SubzoneTracking[subzone][entry->Connections[x].SubzoneID];
 					int j;
 					for (j = neighbor->Connections.Count() - 1; j >= 0; j--) {
@@ -75,30 +52,24 @@
 			}
 
-			/*
-			 * Flood fill fresh subzones for the now unassigned passable cells in the
-			 * window, recording a tracking entry for each new subzone.
-			 */
 			int entry_count = SubzoneTrackingEntryCount[subzone];
 			for (y = bounds.Y; y < bounds.Y + bounds.Height; y++) {
 				for (x = bounds.X; x < bounds.Width + bounds.X; x++) {
 
-					Cell cella;
-					cella.X = x;
-					cella.Y = y;
-					if (In_Local_Radar(cella)) {
+					if (In_Local_Radar(Cell(x, y), true)) {
 
-						CellSubzoneStruct * subptr = Subzone_Of(this, cella);
-						int passability = CellZones[Get_Cell_Zone_Index(cella)].Passability;
+						CellSubzoneStruct * subptr = Subzone_Of(this, Cell(x, y));
+						int passability = Zone_Of(this, Cell(x, y))->Passability;
 						if (passability != PASSABLE_OUTSIDE && subptr->SubzoneID[subzone] == 0) {
 
-							trycell.Y = y;
-							trycell.X = x;
-							Subzone_Span(subptr, subzone, entry_count, bounds, trycell);
+							Cell seed(x, y);
+							Subzone_Span(subptr, subzone, entry_count, bounds, seed);
 
 							track->Add(SubzoneTrackingStruct());
 
 							SubzoneTrackingStruct * added = &(*track)[entry_count];
-							int parent = 0;
-							if (subzone != 2) {
+							int parent;
+							if (subzone == SUBZONE_COUNT-1) {
+								parent = 0;
+							} else {
 								parent = subptr->SubzoneID[subzone + 1];
 							}
@@ -106,5 +77,5 @@
 							added->Passability = (PassabilityType)passability;
 							added->Connections.Set_Growth_Step(16);
-							added->ThreatRegion = Cell_Region(trycell); // level-2 1.001 (partial): inline Cell_Region restored
+							added->ThreatRegion = Cell_Region(Cell(x, y));
 
 							entry_count++;
@@ -119,24 +90,19 @@
 			SubzoneTrackingEntryCount[subzone] = entry_count;
 
-			/*
-			 * Re-register any zone connections whose endpoints fall inside the window.
-			 */
 			for (int connection_index = ZoneConnections.Count() - 1; connection_index >= 0; connection_index--) {
 				ZoneConnectionClass & connection = ZoneConnections[connection_index];
-				if (bounds.Is_Point_Within(Point2D(connection.From.X, connection.From.Y)) || bounds.Is_Point_Within(Point2D(connection.To.X, connection.To.Y))) { // level-2 1.001 (partial): inline rect test restored
+				if (bounds.Is_Point_Within(Point2D(connection.From.X, connection.From.Y))
+					|| bounds.Is_Point_Within(Point2D(connection.To.X, connection.To.Y))) {
 					if (connection.IsPassable) {
-						Register_Zone_Connection_Entries(&connection, subzone); // RA2: by pointer
+						Register_Zone_Connection_Entries(connection, subzone);
 					}
 				}
 			}
 
-			/*
-			 * Walk every bucket of the connection hash set and register both endpoints
-			 * of each recorded connection into the subzone tracking list.
-			 */
 			for (int bucket_index = 0; bucket_index < 256; bucket_index++) {
-				if (set->Buckets[bucket_index].Count() > 0) {
-					SUBZONE_CONNECTION_HASH_SET::ObjectType * object = &set->Buckets[bucket_index][0];
-					for (int index = set->Buckets[bucket_index].Count(); index > 0; index--) {
+				SUBZONE_CONNECTION_HASH_SET::BucketType & bucket = set->Buckets[bucket_index];
+				if (bucket.Count() > 0) {
+					SUBZONE_CONNECTION_HASH_SET::ObjectType * object = &bucket[0];
+					for (int index = bucket.Count(); index > 0; index--) {
 						unsigned packed = object->Value.SubzoneID;
 						WORD low = LOWORD(packed);
@@ -144,11 +110,9 @@
 						bool costly = object->Value.IsCrossBlock;
 
-						SubzoneConnectionStruct conn;
-						conn.SubzoneID = high;
+						SubzoneConnectionStruct conn(high);
 						conn.IsCrossBlock = costly;
 						(*track)[low].Connections.Add(conn);
 
-						SubzoneConnectionStruct conn2;
-						conn2.SubzoneID = low;
+						SubzoneConnectionStruct conn2(low);
 						conn2.IsCrossBlock = costly;
 						(*track)[high].Connections.Add(conn2);
@@ -160,17 +124,11 @@
 		}
 
-		/*
-		 * Propagate the parent subzone identifiers down through the coarser levels
-		 * for the finest (8 cell) window around the changed cell.
-		 */
-		int basex = cell.X - cell.X % 8;
-		int basey = cell.Y - cell.Y % 8;
-		for (y = basey; y < basey + 8; y++) {
-			for (x = basex; x < basex + 8; x++) {
-				trycell.X = x;
-				trycell.Y = y;
-				if (In_Local_Radar(trycell)) {
-					CellSubzoneStruct * subptr = Subzone_Of(this, trycell);
-					for (int level = 0; level < 2; level++) {
+		Rect block(cell.X - cell.X % 8, cell.Y - cell.Y % 8, 8, 8);
+		for (y = block.Y; y < block.Y + block.Height; y++) {
+			for (x = block.X; x < block.Width + block.X; x++) {
+				Cell probe(x, y);
+				if (In_Local_Radar(probe, true)) {
+					CellSubzoneStruct * subptr = Subzone_Of(this, Cell(x, y));
+					for (int level = 0; level < SUBZONE_COUNT-1; level++) {
 						SubzoneTracking[level][subptr->SubzoneID[level]].ParentSubzoneID = subptr->SubzoneID[level + 1];
 					}
```
