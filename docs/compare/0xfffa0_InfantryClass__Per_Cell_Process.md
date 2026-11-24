# 0xfffa0 ?Per_Cell_Process@InfantryClass@@UAEXW4PCPType@@@Z (src/m85/src/infantry.cpp)

Origin: history: w269_x.claims.json. Community source: none found.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -65,9 +65,8 @@
 		*/
 		if (Mission == MISSION_CAPTURE || Mission == MISSION_GUARD_AREA || Mission == MISSION_PATROL) {
-			TechnoClass * tech;
 			if (NavCom != NULL) {
 				bool const & techno = (NavCom->AbstractFlags & 1); // level-2 1.001: the Is_Techno test is read into a byte temporary
 				if (techno && ((TechnoClass*)NavCom)->Considered_Vehicle()) {
-					tech = (TechnoClass *)NavCom;
+					TechnoClass * tech = (TechnoClass *)NavCom;
 					if (tech != NULL && tech->Fetch_RTTI() == RTTI_BUILDING) { // level-2 1.001: only buildings
 						if (PositionCell == tech->PositionCell) {
@@ -98,5 +97,5 @@
 			}
 
-			tech = cellptr->Cell_Building();
+			BuildingClass * tech = cellptr->Cell_Building();
 
 			if (tech != NULL && (tech == NavCom || tech == TarCom)) {
@@ -107,12 +106,14 @@
 				if (Class->IsEngineer) {
 					// are we trying to repair a bridge?
-					if (tech->RTTI == RTTI_BUILDING && ((BuildingClass*)tech)->Class->IsBridgeRepairHut) {
-						bool train = false; // level-2 1.001: initialised before the announcement (closest register allocation; 1.001 stores it after the call)
+					if (tech->RTTI == RTTI_BUILDING && tech->Class->IsBridgeRepairHut) {
 						if (House->Is_Player_Control()) Queue_Speech("EVA_BridgeRepaired", -1, -1); // level-2 1.001
 
+						// level-2: forms of this block adopted from gibbo101/ra2-decomp src/infantry.cpp @721d81e44f (GPL-3.0-or-later; YR 0x00519630):
+						// train initialised after the announcement, the hut as its own BuildingClass pointer and the named type pointer below.
+						bool train = false;
 						for (int y = -2; y < 3; y++) {
 							for (int x = -2; x < 3; x++) {
-								IsometricTileType ittype = Map[(Cell)Cell(PositionCell + Cell(x, y))].ITType;
-								OverlayType overlay = Map[(Cell)Cell(Cell(x, y) + PositionCell)].Overlay; // level-2 1.001: low bridges count as well
+								IsometricTileType ittype = Map[PositionCell + Cell(x, y)].ITType;
+								OverlayType overlay = Map[Cell(x, y) + PositionCell].Overlay; // level-2 1.001: low bridges count as well
 								if (ittype >= IsometricTileTypeClass::TrainBridgeSet && ittype < IsometricTileTypeClass::TrainBridgeSet + TRAIN_BRIDGE_COUNT || overlay >= OVERLAY_LOWBRIDGE_01 && overlay <= OVERLAY_LOWBRIDGE_28) {
 									train = true;
@@ -137,6 +138,7 @@
 					**	enemy building is.
 					*/
-					else if (House->Is_Ally(tech) || tech->House->Class->IsMultiplayPassive && ((BuildingClass*)tech)->Class->CanBeOccupied) {
-						if (tech->Strength == tech->TClass->MaxStrength) { // level-2 1.001: a healthy building turns the engineer away
+					else if (House->Is_Ally(tech) || tech->House->Class->IsMultiplayPassive && tech->Class->CanBeOccupied) {
+						TechnoTypeClass const * ttype = tech->Techno_Type_Class();
+						if (tech->Strength == ttype->MaxStrength) { // level-2 1.001: a healthy building turns the engineer away
 							Assign_Destination(NULL);
 							Scatter(tech->Center_Coord(), true, true);
@@ -147,5 +149,5 @@
 						bool iscapturable = false;
 						if (tech->RTTI == RTTI_BUILDING) {
-							iscapturable = ((BuildingClass *)tech)->Class->IsCaptureable;
+							iscapturable = tech->Class->IsCaptureable;
 						}
 
@@ -174,5 +176,5 @@
 				} else {
 					if (Class->IsAgent) {
-						((BuildingClass *)tech)->Spied_By(House); // level-2 1.001: no announcement
+						tech->Spied_By(House); // level-2 1.001: no announcement
 					}
 				}
```

## 2. Our matched form against the community form

```diff
(not available)
```

## 3. Our failed form against the community form

```diff
(not available)
```
