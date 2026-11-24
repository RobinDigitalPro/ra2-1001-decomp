# 0xbe390 ?Nearing_Target@FlyLocomotionClass@@QAEH_NUCoordStruct@@@Z (src/m85/src/fly.cpp)

Origin: history: w291_x.claims.json. Community source: none found.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -47,5 +47,5 @@
 		if (flyctrl != NULL && flyctrl->Is_Strafe()) {
 			if (Distance(Point2D(LinkedTo->Center_Coord()), Point2D(Coord(coord))) <= CELL_LEPTON * 3) { // level-2 1.001: through Distance // RA2: within three cells of the destination
-				if (!dir.Is_Complete_Turn(LinkedTo->PrimaryFacing.Current(), DirType(0x2000))) { // RA2: the turn left is more than 45 degrees
+				if (!Fly_Is_Complete_Turn(dir, LinkedTo->PrimaryFacing.Current(), FlyTurnLimit(0x2000))) { // RA2: the turn left is more than 45 degrees
 					turn = false;
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
