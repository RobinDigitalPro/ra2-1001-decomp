# 0x120fd0 ?One_Time@IonBlastClass@@SIXXZ (src/m85/src/ionblast.cpp)

Origin: history: w336_x.claims.json. Community source: gibbo232414_ionblast.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -13,15 +13,14 @@
 		BlastSurfaces[frame]->Fill(-1);
 
-		/*
-		 * Rasterize this frame's ripple band into the displacement surface.
-		 * The surface is 256x128 with the blast center in the middle; only one
-		 * quadrant is computed and the result is mirrored into the other three.
-		 * The vertical axis counts double toward the distance because the
-		 * shockwave ellipse is half as tall as it is wide.
-		 */
-		char * center = (char *)BlastSurfaces[frame]->Lock() + 0x4080;
-		for (int y = 63; y >= 0; y--) {
+		// The blast centre is the middle of the surface.
+		int x = 128;
+		int y = 64;
+		char * center = (char *)BlastSurfaces[frame]->Lock() + (y << 8) + x;
+
+		// One quadrant is computed and mirrored into the other three; rows count double.
+		for (y = 63; y >= 0; y--) {
 			int y_dist_sq = y * y * 4;
-			for (int x = 127; x >= 0; x--) {
+			for (int i = 0; i <= 127; i++) {
+				x = 127 - i;
 				double dist = fastmath::sqrt(x * x + y_dist_sq);
 				if (dist >= min_dist && dist <= max_dist) {
@@ -29,9 +28,8 @@
 					char spiral_index = Point_To_Spiral_Index(Point2D(0, wave_height));
 					int row = y << 8;
-					center[row + x] = spiral_index;  /// Quadrant I
-					center[row - x] = spiral_index;  /// Quadrant II
-					char * mirror = center - row;
-					mirror[x] = spiral_index;        /// Quadrant IV
-					mirror[-x] = spiral_index;       /// Quadrant III
+					center[row + x] = spiral_index;
+					center[row - x] = spiral_index;
+					center[-row + x] = spiral_index;
+					center[-row - x] = spiral_index;
 				}
 			}
```

## 2. Our matched form against the community form

```diff
--- community
+++ ours matched
@@ -10,22 +10,22 @@
 
 	for (int frame = 0; frame < ARRAY_SIZE(BlastSurfaces); frame++) {
-		BlastSurfaces[frame] = new BSurface(512, 256, 1);
+		BlastSurfaces[frame] = new BSurface(256, 128, 1);
 		BlastSurfaces[frame]->Fill(-1);
 
 		// The blast centre is the middle of the surface.
-		int x = 256;
-		int y = 128;
-		char * center = (char *)BlastSurfaces[frame]->Lock() + (y << 9) + x;
+		int x = 128;
+		int y = 64;
+		char * center = (char *)BlastSurfaces[frame]->Lock() + (y << 8) + x;
 
 		// One quadrant is computed and mirrored into the other three; rows count double.
-		for (y = 127; y >= 0; y--) {
+		for (y = 63; y >= 0; y--) {
 			int y_dist_sq = y * y * 4;
-			for (int i = 0; i <= 255; i++) {
-				x = 255 - i;
+			for (int i = 0; i <= 127; i++) {
+				x = 127 - i;
 				double dist = fastmath::sqrt(x * x + y_dist_sq);
 				if (dist >= min_dist && dist <= max_dist) {
 					double wave_height = (fastmath::sin((dist - frame * WavePhaseSpeed + 38.0) * WaveFrequency) * 3.5 + 3.0) / (dist / WaveAmplitudeFalloff + 1.0) + 0.5;
 					char spiral_index = Point_To_Spiral_Index(Point2D(0, wave_height));
-					int row = y << 9;
+					int row = y << 8;
 					center[row + x] = spiral_index;
 					center[row - x] = spiral_index;
@@ -36,5 +36,5 @@
 		}
 
-		if (256.0 - WaveSpeed > max_dist) {
+		if (128.0 - WaveSpeed > max_dist) {
 			max_dist += WaveSpeed;
 		}
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -10,33 +10,31 @@
 
 	for (int frame = 0; frame < ARRAY_SIZE(BlastSurfaces); frame++) {
-		BlastSurfaces[frame] = new BSurface(256, 128, 1);
+		BlastSurfaces[frame] = new BSurface(512, 256, 1);
 		BlastSurfaces[frame]->Fill(-1);
 
-		/*
-		 * Rasterize this frame's ripple band into the displacement surface.
-		 * The surface is 256x128 with the blast center in the middle; only one
-		 * quadrant is computed and the result is mirrored into the other three.
-		 * The vertical axis counts double toward the distance because the
-		 * shockwave ellipse is half as tall as it is wide.
-		 */
-		char * center = (char *)BlastSurfaces[frame]->Lock() + 0x4080;
-		for (int y = 63; y >= 0; y--) {
+		// The blast centre is the middle of the surface.
+		int x = 256;
+		int y = 128;
+		char * center = (char *)BlastSurfaces[frame]->Lock() + (y << 9) + x;
+
+		// One quadrant is computed and mirrored into the other three; rows count double.
+		for (y = 127; y >= 0; y--) {
 			int y_dist_sq = y * y * 4;
-			for (int x = 127; x >= 0; x--) {
+			for (int i = 0; i <= 255; i++) {
+				x = 255 - i;
 				double dist = fastmath::sqrt(x * x + y_dist_sq);
 				if (dist >= min_dist && dist <= max_dist) {
 					double wave_height = (fastmath::sin((dist - frame * WavePhaseSpeed + 38.0) * WaveFrequency) * 3.5 + 3.0) / (dist / WaveAmplitudeFalloff + 1.0) + 0.5;
 					char spiral_index = Point_To_Spiral_Index(Point2D(0, wave_height));
-					int row = y << 8;
-					center[row + x] = spiral_index;  /// Quadrant I
-					center[row - x] = spiral_index;  /// Quadrant II
-					char * mirror = center - row;
-					mirror[x] = spiral_index;        /// Quadrant IV
-					mirror[-x] = spiral_index;       /// Quadrant III
+					int row = y << 9;
+					center[row + x] = spiral_index;
+					center[row - x] = spiral_index;
+					center[-row + x] = spiral_index;
+					center[-row - x] = spiral_index;
 				}
 			}
 		}
 
-		if (128.0 - WaveSpeed > max_dist) {
+		if (256.0 - WaveSpeed > max_dist) {
 			max_dist += WaveSpeed;
 		}
```
