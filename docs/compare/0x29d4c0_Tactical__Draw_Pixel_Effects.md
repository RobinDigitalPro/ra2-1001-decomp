# 0x29d4c0 ?Draw_Pixel_Effects@Tactical@@QAEXABV?$TRect@H@@0@Z (src/m85/src/tactical.cpp)

Origin: history: w337_x.claims.json. Community source: meastes1006_tactical.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -1,62 +1,66 @@
 void Tactical::Draw_Pixel_Effects(Rect const & area, Rect const & cliprect) // RA2: not in TibSun, at 0x6A7E80
 {
-	static unsigned LastTime;
+	// level-2 1.001: body ported from gibbo101/ra2-decomp @232414dc36 src/tactical.cpp (GPL-3.0-or-later)
+	static unsigned _lasttime;
+	Point2DStruct pixel = {0, 0};
 
-	if (FPSCounter::CurrentFrameRate < Detail::GetMinFrameRate()) return;
-	if (LogicalSurface->Bytes_Per_Pixel() != 2) return;
-	if (!Options.DetailLevel) return;
+	if (FPSCounter::CurrentFrameRate >= Detail::GetMinFrameRate() && LogicalSurface->Bytes_Per_Pixel() == 2 && Options.DetailLevel != 0) {
+		unsigned short * buffer = (unsigned short *)LogicalSurface->Lock();
+		if (buffer != NULL) {
+			unsigned now = timeGetTime();
+			unsigned elapsed = now - _lasttime;
+			_lasttime = now;
+			if (elapsed > 1000) {
+				elapsed = 1000;
+			}
+			int pitch = LogicalSurface->Stride();
 
-	char * buffer = (char *)LogicalSurface->Lock();
-	if (buffer == NULL) return;
+			Point2D lepton = Pixel_To_Lepton(area.Top_Left() + Point2D(TacPixelX, TacPixelY) - TacticalRect.Top_Left());
+			Cell base = Cell(lepton.X / CELL_LEPTON_W, lepton.Y / CELL_LEPTON_H);
 
-	unsigned now = timeGetTime();
-	unsigned elapsed = now - LastTime;
-	LastTime = now;
-	if (elapsed > 1000) {
-		elapsed = 1000;
-	}
-	int pitch = LogicalSurface->Stride();
+			int ycount = area.Height / (ISO_TILE_PIXEL_H / 2) + 17;
+			int xcount = area.Width / ISO_TILE_PIXEL_W + 4;
 
-	Point2D point = Pixel_To_Lepton(area.Top_Left() + Point2D(TacPixelX, TacPixelY) - TacticalRect.Top_Left());
-	Cell origin(point.X / CELL_LEPTON_W, point.Y / CELL_LEPTON_H);
-	Cell base = origin;
+			base.X -= 2;
+			Cell cell;
+			int ix, iy;
+			for (iy = 0; iy < ycount; iy++) {
+				Cell step(iy / 2, (iy + 1) / 2);
+				cell = base + step;
 
-	int ycount = area.Height / (ISO_TILE_PIXEL_H / 2) + 17;
-	int xcount = area.Width / ISO_TILE_PIXEL_W + 4;
-
-	base.X -= 2;
-	int ix, iy;
-	Cell cell;
-	for (iy = 0; iy < ycount; iy++) {
-		Cell step(iy / 2, (iy + 1) / 2);
-		cell = base + step;
-
-		for (ix = xcount; ix > 0; ix--) {
-			if (Map.In_Radar(cell)) {
-				CellClass * cellptr = &Map[cell];
-				int value = cellptr->Tiberium_Value();
-				if (cellptr->IsVisible && !cellptr->Is_Shrouded() && (cellptr->Land_Type() == LAND_WATER || value != 0) && cellptr->Cell_Occupier() == NULL && !cellptr->IsBridgeSurface) {
-					PixelFXClass * effect = cellptr->PixelFX;
-					int type = (value != 0);
-					if (effect == NULL) {
-						effect = new PixelFXClass(type);
-						cellptr->PixelFX = effect;
-					} else if (effect->Phase >= 0x2000) {
-						effect->Init(type);
-					}
-					if (effect != NULL && effect->Expire(elapsed)) {
-						Rect render = cellptr->Cell_Render_Rect();
-						int x = render.X + render.Width / 2 + effect->OffsetX;
-						int y = render.Y + render.Height / 2 + effect->OffsetY;
-						if (x >= cliprect.X && x < cliprect.X + cliprect.Width && y >= cliprect.Y && y < cliprect.Y + cliprect.Height) {
-							effect->Update(elapsed);
-							*(unsigned short *)(buffer + pitch * y + x * 2) = DSurface::Build_Hicolor_Pixel(effect->Current[0], effect->Current[1], effect->Current[2]);
+				for (ix = xcount; ix > 0; ix--) {
+					if (Map.In_Radar(cell)) {
+						CellClass * cellptr = &Map[cell];
+						int value = cellptr->Tiberium_Value();
+						if (cellptr->IsVisible && !cellptr->Is_Shrouded() && (cellptr->Land_Type() == LAND_WATER || value != 0) && cellptr->Cell_Occupier() == NULL && !cellptr->IsBridgeSurface) {
+							PixelFXClass * fx = cellptr->PixelFX;
+							int type = (value != 0);
+							if (fx == NULL) {
+								fx = new PixelFXClass(type);
+								cellptr->PixelFX = fx;
+							} else {
+								if (fx->Phase >= 0x2000) {
+									fx->Init(type);
+								}
+							}
+							if (fx != NULL && fx->Expire(elapsed)) {
+								Rect render = cellptr->Cell_Render_Rect();
+								pixel.X = render.X + render.Width / 2;
+								pixel.Y = render.Y + render.Height / 2;
+								pixel.X += fx->OffsetX;
+								pixel.Y += fx->OffsetY;
+								if (cliprect.Is_Point_Within(Point2D(pixel))) {
+									fx->Update(elapsed);
+									((unsigned short *)((char *)buffer + pixel.Y * pitch))[pixel.X] = DSurface::Build_Hicolor_Pixel(fx->Current[0], fx->Current[1], fx->Current[2]);
+								}
+							}
 						}
 					}
+					++cell.X;
+					--cell.Y;
 				}
 			}
-			cell += Cell(1, -1);
+			LogicalSurface->Unlock();
 		}
 	}
-	LogicalSurface->Unlock();
 }
```

## 2. Our matched form against the community form

```diff
--- community
+++ ours matched
@@ -1,65 +1,66 @@
-void Tactical::Draw_Pixel_Effects(Rect const & area, Rect const & cliprect) // RA2: not in TibSun, at 0x6A7E80
-{
-	static unsigned LastTime;
-
-	if (FPSCounter::CurrentFrameRate < Detail::GetMinFrameRate()) return;
-	if (LogicalSurface->Bytes_Per_Pixel() != 2) return;
-	if (!Options.DetailLevel) return;
-
-	char * buffer = (char *)LogicalSurface->Lock();
-	if (buffer == NULL) return;
-
-	unsigned now = timeGetTime();
-	unsigned elapsed = now - LastTime;
-	LastTime = now;
-	if (elapsed > 1000) {
-		elapsed = 1000;
-	}
-	int pitch = LogicalSurface->Stride();
-
-	Point2D point = Pixel_To_Lepton(area.Top_Left() + Point2D(TacPixelX, TacPixelY) - TacticalRect.Top_Left());
-	Cell origin(point.X / CELL_LEPTON_W, point.Y / CELL_LEPTON_H);
-	Cell base = origin;
-
-	int ycount = area.Height / (ISO_TILE_PIXEL_H / 2) + 17;
-	int xcount = area.Width / ISO_TILE_PIXEL_W + 4;
-
-	base.X -= 2;
-	int ix, iy;
-	Cell cell;
-	for (iy = 0; iy < ycount; iy++) {
-		Cell step(iy / 2, (iy + 1) / 2);
-		cell = base + step;
-
-		for (ix = xcount; ix > 0; ix--) {
-			if (Map.In_Radar(cell)) {
-				CellClass * cellptr = &Map[cell];
-				int value = cellptr->Tiberium_Value();
-				if (cellptr->IsVisible && !cellptr->Is_Shrouded() && (cellptr->Land_Type() == LAND_WATER || value != 0) && cellptr->Cell_Occupier() == NULL && !cellptr->IsBridgeSurface) {
-					PixelFXClass * effect = cellptr->PixelFX;
-					int type = (value != 0);
-					if (effect == NULL) {
-						effect = new PixelFXClass(type);
-						cellptr->PixelFX = effect;
-					} else if (effect->Phase >= 0x2000) {
-						effect->Init(type);
-					}
-					if (effect != NULL && effect->Expire(elapsed)) {
-						Rect render = cellptr->Cell_Render_Rect();
-						Point2D point(render.Width / 2, render.Height / 2);
-						point.X += render.X;
-						point.Y += render.Y;
-						point.X += effect->OffsetX;
-						point.Y += effect->OffsetY;
-						if (point.X >= cliprect.X && point.X < cliprect.X + cliprect.Width && point.Y >= cliprect.Y && point.Y < cliprect.Y + cliprect.Height) {
-							effect->Update(elapsed);
-							*(unsigned short *)(buffer + pitch * point.Y + point.X * 2) = DSurface::Build_Hicolor_Pixel(effect->Current[0], effect->Current[1], effect->Current[2]);
-						}
-					}
-				}
-			}
-			cell += Cell(1, -1);
-		}
-	}
-	LogicalSurface->Unlock();
+void Tactical::Draw_Pixel_Effects(Rect const & area, Rect const & cliprect) // RA2: not in TibSun, at 0x6A7E80
+{
+	// level-2 1.001: body ported from gibbo101/ra2-decomp @232414dc36 src/tactical.cpp (GPL-3.0-or-later)
+	static unsigned _lasttime;
+	Point2DStruct pixel = {0, 0};
+
+	if (FPSCounter::CurrentFrameRate >= Detail::GetMinFrameRate() && LogicalSurface->Bytes_Per_Pixel() == 2 && Options.DetailLevel != 0) {
+		unsigned short * buffer = (unsigned short *)LogicalSurface->Lock();
+		if (buffer != NULL) {
+			unsigned now = timeGetTime();
+			unsigned elapsed = now - _lasttime;
+			_lasttime = now;
+			if (elapsed > 1000) {
+				elapsed = 1000;
+			}
+			int pitch = LogicalSurface->Stride();
+
+			Point2D lepton = Pixel_To_Lepton(area.Top_Left() + Point2D(TacPixelX, TacPixelY) - TacticalRect.Top_Left());
+			Cell base = Cell(lepton.X / CELL_LEPTON_W, lepton.Y / CELL_LEPTON_H);
+
+			int ycount = area.Height / (ISO_TILE_PIXEL_H / 2) + 17;
+			int xcount = area.Width / ISO_TILE_PIXEL_W + 4;
+
+			base.X -= 2;
+			Cell cell;
+			int ix, iy;
+			for (iy = 0; iy < ycount; iy++) {
+				Cell step(iy / 2, (iy + 1) / 2);
+				cell = base + step;
+
+				for (ix = xcount; ix > 0; ix--) {
+					if (Map.In_Radar(cell)) {
+						CellClass * cellptr = &Map[cell];
+						int value = cellptr->Tiberium_Value();
+						if (cellptr->IsVisible && !cellptr->Is_Shrouded() && (cellptr->Land_Type() == LAND_WATER || value != 0) && cellptr->Cell_Occupier() == NULL && !cellptr->IsBridgeSurface) {
+							PixelFXClass * fx = cellptr->PixelFX;
+							int type = (value != 0);
+							if (fx == NULL) {
+								fx = new PixelFXClass(type);
+								cellptr->PixelFX = fx;
+							} else {
+								if (fx->Phase >= 0x2000) {
+									fx->Init(type);
+								}
+							}
+							if (fx != NULL && fx->Expire(elapsed)) {
+								Rect render = cellptr->Cell_Render_Rect();
+								pixel.X = render.X + render.Width / 2;
+								pixel.Y = render.Y + render.Height / 2;
+								pixel.X += fx->OffsetX;
+								pixel.Y += fx->OffsetY;
+								if (cliprect.Is_Point_Within(Point2D(pixel))) {
+									fx->Update(elapsed);
+									((unsigned short *)((char *)buffer + pixel.Y * pitch))[pixel.X] = DSurface::Build_Hicolor_Pixel(fx->Current[0], fx->Current[1], fx->Current[2]);
+								}
+							}
+						}
+					}
+					++cell.X;
+					--cell.Y;
+				}
+			}
+			LogicalSurface->Unlock();
+		}
+	}
 }
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -1,62 +1,65 @@
-void Tactical::Draw_Pixel_Effects(Rect const & area, Rect const & cliprect) // RA2: not in TibSun, at 0x6A7E80
-{
-	static unsigned LastTime;
-
-	if (FPSCounter::CurrentFrameRate < Detail::GetMinFrameRate()) return;
-	if (LogicalSurface->Bytes_Per_Pixel() != 2) return;
-	if (!Options.DetailLevel) return;
-
-	char * buffer = (char *)LogicalSurface->Lock();
-	if (buffer == NULL) return;
-
-	unsigned now = timeGetTime();
-	unsigned elapsed = now - LastTime;
-	LastTime = now;
-	if (elapsed > 1000) {
-		elapsed = 1000;
-	}
-	int pitch = LogicalSurface->Stride();
-
-	Point2D point = Pixel_To_Lepton(area.Top_Left() + Point2D(TacPixelX, TacPixelY) - TacticalRect.Top_Left());
-	Cell origin(point.X / CELL_LEPTON_W, point.Y / CELL_LEPTON_H);
-	Cell base = origin;
-
-	int ycount = area.Height / (ISO_TILE_PIXEL_H / 2) + 17;
-	int xcount = area.Width / ISO_TILE_PIXEL_W + 4;
-
-	base.X -= 2;
-	int ix, iy;
-	Cell cell;
-	for (iy = 0; iy < ycount; iy++) {
-		Cell step(iy / 2, (iy + 1) / 2);
-		cell = base + step;
-
-		for (ix = xcount; ix > 0; ix--) {
-			if (Map.In_Radar(cell)) {
-				CellClass * cellptr = &Map[cell];
-				int value = cellptr->Tiberium_Value();
-				if (cellptr->IsVisible && !cellptr->Is_Shrouded() && (cellptr->Land_Type() == LAND_WATER || value != 0) && cellptr->Cell_Occupier() == NULL && !cellptr->IsBridgeSurface) {
-					PixelFXClass * effect = cellptr->PixelFX;
-					int type = (value != 0);
-					if (effect == NULL) {
-						effect = new PixelFXClass(type);
-						cellptr->PixelFX = effect;
-					} else if (effect->Phase >= 0x2000) {
-						effect->Init(type);
-					}
-					if (effect != NULL && effect->Expire(elapsed)) {
-						Rect render = cellptr->Cell_Render_Rect();
-						int x = render.X + render.Width / 2 + effect->OffsetX;
-						int y = render.Y + render.Height / 2 + effect->OffsetY;
-						if (x >= cliprect.X && x < cliprect.X + cliprect.Width && y >= cliprect.Y && y < cliprect.Y + cliprect.Height) {
-							effect->Update(elapsed);
-							*(unsigned short *)(buffer + pitch * y + x * 2) = DSurface::Build_Hicolor_Pixel(effect->Current[0], effect->Current[1], effect->Current[2]);
-						}
-					}
-				}
-			}
-			cell += Cell(1, -1);
-		}
-	}
-	LogicalSurface->Unlock();
+void Tactical::Draw_Pixel_Effects(Rect const & area, Rect const & cliprect) // RA2: not in TibSun, at 0x6A7E80
+{
+	static unsigned LastTime;
+
+	if (FPSCounter::CurrentFrameRate < Detail::GetMinFrameRate()) return;
+	if (LogicalSurface->Bytes_Per_Pixel() != 2) return;
+	if (!Options.DetailLevel) return;
+
+	char * buffer = (char *)LogicalSurface->Lock();
+	if (buffer == NULL) return;
+
+	unsigned now = timeGetTime();
+	unsigned elapsed = now - LastTime;
+	LastTime = now;
+	if (elapsed > 1000) {
+		elapsed = 1000;
+	}
+	int pitch = LogicalSurface->Stride();
+
+	Point2D point = Pixel_To_Lepton(area.Top_Left() + Point2D(TacPixelX, TacPixelY) - TacticalRect.Top_Left());
+	Cell origin(point.X / CELL_LEPTON_W, point.Y / CELL_LEPTON_H);
+	Cell base = origin;
+
+	int ycount = area.Height / (ISO_TILE_PIXEL_H / 2) + 17;
+	int xcount = area.Width / ISO_TILE_PIXEL_W + 4;
+
+	base.X -= 2;
+	int ix, iy;
+	Cell cell;
+	for (iy = 0; iy < ycount; iy++) {
+		Cell step(iy / 2, (iy + 1) / 2);
+		cell = base + step;
+
+		for (ix = xcount; ix > 0; ix--) {
+			if (Map.In_Radar(cell)) {
+				CellClass * cellptr = &Map[cell];
+				int value = cellptr->Tiberium_Value();
+				if (cellptr->IsVisible && !cellptr->Is_Shrouded() && (cellptr->Land_Type() == LAND_WATER || value != 0) && cellptr->Cell_Occupier() == NULL && !cellptr->IsBridgeSurface) {
+					PixelFXClass * effect = cellptr->PixelFX;
+					int type = (value != 0);
+					if (effect == NULL) {
+						effect = new PixelFXClass(type);
+						cellptr->PixelFX = effect;
+					} else if (effect->Phase >= 0x2000) {
+						effect->Init(type);
+					}
+					if (effect != NULL && effect->Expire(elapsed)) {
+						Rect render = cellptr->Cell_Render_Rect();
+						Point2D point(render.Width / 2, render.Height / 2);
+						point.X += render.X;
+						point.Y += render.Y;
+						point.X += effect->OffsetX;
+						point.Y += effect->OffsetY;
+						if (point.X >= cliprect.X && point.X < cliprect.X + cliprect.Width && point.Y >= cliprect.Y && point.Y < cliprect.Y + cliprect.Height) {
+							effect->Update(elapsed);
+							*(unsigned short *)(buffer + pitch * point.Y + point.X * 2) = DSurface::Build_Hicolor_Pixel(effect->Current[0], effect->Current[1], effect->Current[2]);
+						}
+					}
+				}
+			}
+			cell += Cell(1, -1);
+		}
+	}
+	LogicalSurface->Unlock();
 }
```
