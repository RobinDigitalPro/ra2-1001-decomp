# 0x7a900 ?Place_Veins@CellClass@@QAEXXZ (src/m85/src/cell.cpp)

Origin: history: w332_x.claims.json. Community source: gibbo232414_cell.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -13,11 +13,7 @@
 			OverlayData = abs(Scen->RandomNumber()) % 3 + OVERLAYDATA_FIRST_SOLID_VEIN;
 
-			for (FacingType dir = FACING_N; dir < FACING_COUNT; dir = FacingType(dir + FACING_90)) {
-				CellClass & adjacent = Adjacent_Cell(dir);
+			for (int dir = FACING_N; dir < FACING_COUNT; dir += FACING_90) {
+				CellClass & adjacent = Adjacent_Cell(FacingType(dir));
 
-				/*
-				 * Skip neighbors that are already solid veins, or that carry some other
-				 * vein-type overlay.
-				 */
 				if (adjacent.Overlay == OVERLAY_VEINS && adjacent.OverlayData >= OVERLAYDATA_FIRST_SOLID_VEIN) {
 					continue;
@@ -28,12 +24,13 @@
 
 				if (adjacent.Ramp == RAMP_NONE) {
-					int frame = _Vein_Frame_B(&adjacent); // level-2 1.001: Get_Vein_Frame is called out of line here
+					int frame = _Vein_Frame_B(&adjacent); // level-2 1.001: STEERING retain the out-of-line Get_Vein_Frame call.
 					if (adjacent.Overlay == OVERLAY_NONE || (frame <= 15 && adjacent.OverlayData / 3 != frame)) {
 						Rect adjrect(0, 0, 0, 0);
 						adjrect = Union(adjrect, Union(adjacent.Overlay_Render_Rect(), adjacent.Overlay_Shadow_Render_Rect()));
 						adjacent.Overlay = OVERLAY_VEINS;
-						adjacent.OverlayData = 3 * frame + abs(Scen->RandomNumber() % 3);
+						adjacent.OverlayData = 3 * frame + abs(Scen->RandomNumber % 3);
 						adjacent.Recalc_Attributes();
-						adjrect = Union(adjrect, Union(adjacent.Overlay_Render_Rect(), adjacent.Overlay_Shadow_Render_Rect())) - TacticalRect.Top_Left(); // level-2 1.001: Top_Left() in all three places; this first one is inlined, and it spends the inline budget so that the later Top_Left calls and the ramp branch's Rect constructor are called out of line as in 1.001
+						Point2D origin = TacticalRect.TopLeft;
+						adjrect = Union(adjrect, Union(adjacent.Overlay_Render_Rect(), adjacent.Overlay_Shadow_Render_Rect())) - origin;
 						TacticalMap->Register_Dirty_Area(adjrect);
 					}
@@ -43,5 +40,5 @@
 					adjacent.Overlay = OVERLAY_VEINS;
 					adjacent.OverlayData = 2 * adjacent.Ramp + (abs(Scen->RandomNumber()) & 1) + OVERLAYDATA_FIRST_RAMP_VEIN;
-					adjrect = Union(adjrect, Union(adjacent.Overlay_Render_Rect(), adjacent.Overlay_Shadow_Render_Rect())) - TacticalRect.Top_Left(); // level-2 1.001: as above
+					adjrect = Union(adjrect, Union(adjacent.Overlay_Render_Rect(), adjacent.Overlay_Shadow_Render_Rect())) - TacticalRect.TopLeft;
 					TacticalMap->Register_Dirty_Area(adjrect);
 				}
@@ -55,5 +52,5 @@
 		}
 
-		rect = Union(rect, Union(Overlay_Render_Rect(), Overlay_Shadow_Render_Rect())) - TacticalRect.Top_Left(); // level-2 1.001: as above
+		rect = Union(rect, Union(Overlay_Render_Rect(), Overlay_Shadow_Render_Rect())) - TacticalRect.TopLeft;
 		TacticalMap->Register_Dirty_Area(rect);
 		Recalc_Attributes();
```

## 2. Our matched form against the community form

```diff
--- community
+++ ours matched
@@ -24,5 +24,5 @@
 
 				if (adjacent.Ramp == RAMP_NONE) {
-					int frame = adjacent.Get_Vein_Frame();
+					int frame = _Vein_Frame_B(&adjacent); // level-2 1.001: STEERING retain the out-of-line Get_Vein_Frame call.
 					if (adjacent.Overlay == OVERLAY_NONE || (frame <= 15 && adjacent.OverlayData / 3 != frame)) {
 						Rect adjrect(0, 0, 0, 0);
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -13,11 +13,7 @@
 			OverlayData = abs(Scen->RandomNumber()) % 3 + OVERLAYDATA_FIRST_SOLID_VEIN;
 
-			for (FacingType dir = FACING_N; dir < FACING_COUNT; dir = FacingType(dir + FACING_90)) {
-				CellClass & adjacent = Adjacent_Cell(dir);
+			for (int dir = FACING_N; dir < FACING_COUNT; dir += FACING_90) {
+				CellClass & adjacent = Adjacent_Cell(FacingType(dir));
 
-				/*
-				 * Skip neighbors that are already solid veins, or that carry some other
-				 * vein-type overlay.
-				 */
 				if (adjacent.Overlay == OVERLAY_VEINS && adjacent.OverlayData >= OVERLAYDATA_FIRST_SOLID_VEIN) {
 					continue;
@@ -28,12 +24,13 @@
 
 				if (adjacent.Ramp == RAMP_NONE) {
-					int frame = _Vein_Frame_B(&adjacent); // level-2 1.001: Get_Vein_Frame is called out of line here
+					int frame = adjacent.Get_Vein_Frame();
 					if (adjacent.Overlay == OVERLAY_NONE || (frame <= 15 && adjacent.OverlayData / 3 != frame)) {
 						Rect adjrect(0, 0, 0, 0);
 						adjrect = Union(adjrect, Union(adjacent.Overlay_Render_Rect(), adjacent.Overlay_Shadow_Render_Rect()));
 						adjacent.Overlay = OVERLAY_VEINS;
-						adjacent.OverlayData = 3 * frame + abs(Scen->RandomNumber() % 3);
+						adjacent.OverlayData = 3 * frame + abs(Scen->RandomNumber % 3);
 						adjacent.Recalc_Attributes();
-						adjrect = Union(adjrect, Union(adjacent.Overlay_Render_Rect(), adjacent.Overlay_Shadow_Render_Rect())) - TacticalRect.Top_Left(); // level-2 1.001: Top_Left() in all three places; this first one is inlined, and it spends the inline budget so that the later Top_Left calls and the ramp branch's Rect constructor are called out of line as in 1.001
+						Point2D origin = TacticalRect.TopLeft;
+						adjrect = Union(adjrect, Union(adjacent.Overlay_Render_Rect(), adjacent.Overlay_Shadow_Render_Rect())) - origin;
 						TacticalMap->Register_Dirty_Area(adjrect);
 					}
@@ -43,5 +40,5 @@
 					adjacent.Overlay = OVERLAY_VEINS;
 					adjacent.OverlayData = 2 * adjacent.Ramp + (abs(Scen->RandomNumber()) & 1) + OVERLAYDATA_FIRST_RAMP_VEIN;
-					adjrect = Union(adjrect, Union(adjacent.Overlay_Render_Rect(), adjacent.Overlay_Shadow_Render_Rect())) - TacticalRect.Top_Left(); // level-2 1.001: as above
+					adjrect = Union(adjrect, Union(adjacent.Overlay_Render_Rect(), adjacent.Overlay_Shadow_Render_Rect())) - TacticalRect.TopLeft;
 					TacticalMap->Register_Dirty_Area(adjrect);
 				}
@@ -55,5 +52,5 @@
 		}
 
-		rect = Union(rect, Union(Overlay_Render_Rect(), Overlay_Shadow_Render_Rect())) - TacticalRect.Top_Left(); // level-2 1.001: as above
+		rect = Union(rect, Union(Overlay_Render_Rect(), Overlay_Shadow_Render_Rect())) - TacticalRect.TopLeft;
 		TacticalMap->Register_Dirty_Area(rect);
 		Recalc_Attributes();
```
