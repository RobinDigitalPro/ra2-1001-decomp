# 0x281740 ?CacheBMP@SurfaceCacheClass@@QAE_NPBDPAXHH@Z (src/m85/src/srfcache.cpp)

Origin: recent port: batch_44g_*. Community source: gibbo232414_srfcache.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -1,9 +1,9 @@
 bool SurfaceCacheClass::CacheBMP(char const * name, void * bitmap, int bytes, int bpp)
 {
+	// level-2 1.001: body ported from gibbo101/ra2-decomp @232414dc36 src/srfcache.cpp
 	unsigned char *bitmap_palette_data;
 	unsigned char *bitmap_data;
 	BITMAPFILEHEADER filehead;
 	BITMAPINFO *bitmap_info_header;
-	int palette_bytes;
 	int bitmap_width;
 	int surface_width;
@@ -11,101 +11,57 @@
 	unsigned short *surface_data;
 	BITMAPINFOHEADER header;
+	SurfaceCacheEntry new_entry;
+
+	bitmap_palette_data = (unsigned char *)bitmap;
+	filehead = *(BITMAPFILEHEADER *)bitmap_palette_data;
+	bitmap_palette_data += sizeof(BITMAPFILEHEADER);
+	header = *(BITMAPINFOHEADER *)bitmap_palette_data;
+	bitmap_palette_data += sizeof(BITMAPINFOHEADER);
+
+	bitmap_info_header = (BITMAPINFO *)operator new(4 * (1 << header.biBitCount) + sizeof(BITMAPINFOHEADER));
+	bitmap_info_header->bmiHeader.biSize = header.biSize;
+	bitmap_info_header->bmiHeader.biWidth = header.biWidth;
+	bitmap_info_header->bmiHeader.biHeight = header.biHeight;
+	bitmap_info_header->bmiHeader.biPlanes = header.biPlanes;
+	bitmap_info_header->bmiHeader.biBitCount = header.biBitCount;
+	bitmap_info_header->bmiHeader.biCompression = header.biCompression;
+	bitmap_info_header->bmiHeader.biSizeImage = header.biSizeImage;
+	bitmap_info_header->bmiHeader.biXPelsPerMeter = header.biXPelsPerMeter;
+	bitmap_info_header->bmiHeader.biYPelsPerMeter = header.biYPelsPerMeter;
+	bitmap_info_header->bmiHeader.biClrUsed = header.biClrUsed;
+	bitmap_info_header->bmiHeader.biClrImportant = header.biClrImportant;
+	memcpy(bitmap_info_header->bmiColors, bitmap_palette_data, header.biClrUsed * sizeof(RGBQUAD));
+	bitmap_palette_data += header.biClrUsed * sizeof(RGBQUAD);
 
 	unsigned short pal16[256];
-	SurfaceCacheEntry new_entry;
-
-	((void)bytes);
-
-	/*
-	 * Pull the file and info headers out of the raw file image; the palette
-	 * follows the info header.
-	 */
-	bitmap_palette_data = (unsigned char *)bitmap;
-	filehead = *(BITMAPFILEHEADER *)bitmap_palette_data;
-	bitmap_palette_data += sizeof(filehead);
-	header = *(BITMAPINFOHEADER *)bitmap_palette_data;
-	bitmap_palette_data += sizeof(header);
-
-	/*
-	 * Build a working copy of the info header with room for the palette
-	 * behind it, then copy the palette in.
-	 */
-	bitmap_info_header = (BITMAPINFO *)operator new(4 * (1 << header.biBitCount) + sizeof(BITMAPINFOHEADER));
-	bitmap_info_header->bmiHeader.biHeight = header.biHeight;
-	bitmap_info_header->bmiHeader.biSize = header.biSize;
-	bitmap_info_header->bmiHeader.biCompression = header.biCompression;
-	bitmap_info_header->bmiHeader.biPlanes = header.biPlanes;
-	bitmap_info_header->bmiHeader.biYPelsPerMeter = header.biYPelsPerMeter;
-	bitmap_info_header->bmiHeader.biWidth = header.biWidth;
-	bitmap_info_header->bmiHeader.biSizeImage = header.biSizeImage;
-	bitmap_info_header->bmiHeader.biClrUsed = header.biClrUsed;
-	bitmap_info_header->bmiHeader.biBitCount = header.biBitCount;
-	palette_bytes = header.biClrUsed * sizeof(RGBQUAD);
-	bitmap_info_header->bmiHeader.biClrImportant = header.biClrImportant;
-	bitmap_info_header->bmiHeader.biXPelsPerMeter = header.biXPelsPerMeter;
-	memcpy(bitmap_info_header->bmiColors, bitmap_palette_data, palette_bytes);
-	bitmap_palette_data += palette_bytes;
-
-	/*
-	**	Convert the palette (RGBQUAD entries, stored blue-green-red-reserved)
-	**	into a table of ready-made 16-bit pixels.
-	*/
 	unsigned char *p = (unsigned char *)bitmap_info_header->bmiColors;
 	for (int i = 0; i < 256; i++) {
-		int blue = p[0];
-		int green = p[1];
-		p += 2;
-		int pixel = (blue >> DSurface::BlueLeft) << DSurface::BlueRight;
-		pixel |= (green >> DSurface::GreenLeft) << DSurface::GreenRight;
-		pixel |= (unsigned char)(*p >> DSurface::RedLeft) << DSurface::RedRight;
-		pal16[i] = pixel;
+		int blue = *p++;
+		int green = *p++;
+		pal16[i] = ((*p >> DSurface::RedLeft) << DSurface::RedRight) | ((green >> DSurface::GreenLeft) << DSurface::GreenRight) | ((blue >> DSurface::BlueLeft) << DSurface::BlueRight);
 		p += 2;
 	}
 
-	/*
-	 * Copy the pixel data out of the file image.
-	 */
 	bitmap_data = (unsigned char *)operator new(filehead.bfSize - filehead.bfOffBits);
 	memcpy(bitmap_data, bitmap_palette_data, filehead.bfSize - filehead.bfOffBits);
 
-	/*
-	 * Blit the bitmap into a new surface. BMP pixel data is stored bottom-up,
-	 * so source rows are walked from the last row backward. The source pitch
-	 * is the width rounded down to a dword boundary plus four, which over-pads
-	 * widths that are already dword-aligned.
-	 */
-	surface = new BSurface(header.biWidth, header.biHeight, bpp);
+	int width = header.biWidth;
+	int height = header.biHeight;
+	surface = new BSurface(width, height, bpp);
 	surface_data = (unsigned short *)surface->Lock();
 	surface_width = surface->Stride() / 2;
-	bitmap_width = header.biWidth - (header.biWidth & 3) + 4;
+	bitmap_width = width - (width & 3) + 4;
 
-	if (header.biHeight > 0) {
-		int offset = 0;
-		int row_step = -bitmap_width;
-		int row_offset = bitmap_width * (header.biHeight - 1);
-		int row_count = header.biHeight;
-		do {
-			int x = 0;
-			if (header.biWidth > 0) {
-				do {
-					int source_index = row_offset + x;
-
-					if (bpp == 2) {
-						surface_data[offset + x] = pal16[bitmap_data[source_index]];
-					} else {
-						surface_data[offset + x] = bitmap_data[source_index];
-					}
-					x++;
-				} while (x < header.biWidth);
+	for (int y = 0; y < height; y++) {
+		int source_row = (height - 1 - y) * bitmap_width;
+		for (int x = 0; x < width; x++) {
+			if (bpp == 2) {
+				surface_data[y * surface_width + x] = pal16[bitmap_data[source_row + x]];
+			} else {
+				surface_data[y * surface_width + x] = bitmap_data[source_row + x];
 			}
-			row_offset += row_step;
-			offset += surface_width;
-			row_count--;
-		} while (row_count);
+		}
 	}
 
-	/*
-	 * An 8-bit surface keeps its palette in the cache entry.
-	 */
 	if (bpp == 1) {
 		memcpy(new_entry.palette, bitmap_info_header->bmiColors, sizeof(new_entry.palette));
@@ -120,14 +76,8 @@
 	key.toLower();
 
-	/*
-	 * If an entry is already cached under this name, remove it and delete
-	 * its surface before adding the new one.
-	 */
 	SurfaceCacheEntry old_entry;
 	if (getValue(key, old_entry)) {
 		remove(key);
-		if (old_entry.surf != NULL) {
-			delete old_entry.surf;
-		}
+		delete old_entry.surf;
 	}
 
```

## 2. Our matched form against the community form

```diff
--- community
+++ ours matched
@@ -1,4 +1,5 @@
 bool SurfaceCacheClass::CacheBMP(char const * name, void * bitmap, int bytes, int bpp)
 {
+	// level-2 1.001: body ported from gibbo101/ra2-decomp @232414dc36 src/srfcache.cpp
 	unsigned char *bitmap_palette_data;
 	unsigned char *bitmap_data;
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -5,5 +5,4 @@
 	BITMAPFILEHEADER filehead;
 	BITMAPINFO *bitmap_info_header;
-	int palette_bytes;
 	int bitmap_width;
 	int surface_width;
@@ -11,101 +10,57 @@
 	unsigned short *surface_data;
 	BITMAPINFOHEADER header;
+	SurfaceCacheEntry new_entry;
+
+	bitmap_palette_data = (unsigned char *)bitmap;
+	filehead = *(BITMAPFILEHEADER *)bitmap_palette_data;
+	bitmap_palette_data += sizeof(BITMAPFILEHEADER);
+	header = *(BITMAPINFOHEADER *)bitmap_palette_data;
+	bitmap_palette_data += sizeof(BITMAPINFOHEADER);
+
+	bitmap_info_header = (BITMAPINFO *)operator new(4 * (1 << header.biBitCount) + sizeof(BITMAPINFOHEADER));
+	bitmap_info_header->bmiHeader.biSize = header.biSize;
+	bitmap_info_header->bmiHeader.biWidth = header.biWidth;
+	bitmap_info_header->bmiHeader.biHeight = header.biHeight;
+	bitmap_info_header->bmiHeader.biPlanes = header.biPlanes;
+	bitmap_info_header->bmiHeader.biBitCount = header.biBitCount;
+	bitmap_info_header->bmiHeader.biCompression = header.biCompression;
+	bitmap_info_header->bmiHeader.biSizeImage = header.biSizeImage;
+	bitmap_info_header->bmiHeader.biXPelsPerMeter = header.biXPelsPerMeter;
+	bitmap_info_header->bmiHeader.biYPelsPerMeter = header.biYPelsPerMeter;
+	bitmap_info_header->bmiHeader.biClrUsed = header.biClrUsed;
+	bitmap_info_header->bmiHeader.biClrImportant = header.biClrImportant;
+	memcpy(bitmap_info_header->bmiColors, bitmap_palette_data, header.biClrUsed * sizeof(RGBQUAD));
+	bitmap_palette_data += header.biClrUsed * sizeof(RGBQUAD);
 
 	unsigned short pal16[256];
-	SurfaceCacheEntry new_entry;
-
-	((void)bytes);
-
-	/*
-	 * Pull the file and info headers out of the raw file image; the palette
-	 * follows the info header.
-	 */
-	bitmap_palette_data = (unsigned char *)bitmap;
-	filehead = *(BITMAPFILEHEADER *)bitmap_palette_data;
-	bitmap_palette_data += sizeof(filehead);
-	header = *(BITMAPINFOHEADER *)bitmap_palette_data;
-	bitmap_palette_data += sizeof(header);
-
-	/*
-	 * Build a working copy of the info header with room for the palette
-	 * behind it, then copy the palette in.
-	 */
-	bitmap_info_header = (BITMAPINFO *)operator new(4 * (1 << header.biBitCount) + sizeof(BITMAPINFOHEADER));
-	bitmap_info_header->bmiHeader.biHeight = header.biHeight;
-	bitmap_info_header->bmiHeader.biSize = header.biSize;
-	bitmap_info_header->bmiHeader.biCompression = header.biCompression;
-	bitmap_info_header->bmiHeader.biPlanes = header.biPlanes;
-	bitmap_info_header->bmiHeader.biYPelsPerMeter = header.biYPelsPerMeter;
-	bitmap_info_header->bmiHeader.biWidth = header.biWidth;
-	bitmap_info_header->bmiHeader.biSizeImage = header.biSizeImage;
-	bitmap_info_header->bmiHeader.biClrUsed = header.biClrUsed;
-	bitmap_info_header->bmiHeader.biBitCount = header.biBitCount;
-	palette_bytes = header.biClrUsed * sizeof(RGBQUAD);
-	bitmap_info_header->bmiHeader.biClrImportant = header.biClrImportant;
-	bitmap_info_header->bmiHeader.biXPelsPerMeter = header.biXPelsPerMeter;
-	memcpy(bitmap_info_header->bmiColors, bitmap_palette_data, palette_bytes);
-	bitmap_palette_data += palette_bytes;
-
-	/*
-	**	Convert the palette (RGBQUAD entries, stored blue-green-red-reserved)
-	**	into a table of ready-made 16-bit pixels.
-	*/
 	unsigned char *p = (unsigned char *)bitmap_info_header->bmiColors;
 	for (int i = 0; i < 256; i++) {
-		int blue = p[0];
-		int green = p[1];
-		p += 2;
-		int pixel = (blue >> DSurface::BlueLeft) << DSurface::BlueRight;
-		pixel |= (green >> DSurface::GreenLeft) << DSurface::GreenRight;
-		pixel |= (unsigned char)(*p >> DSurface::RedLeft) << DSurface::RedRight;
-		pal16[i] = pixel;
+		int blue = *p++;
+		int green = *p++;
+		pal16[i] = ((*p >> DSurface::RedLeft) << DSurface::RedRight) | ((green >> DSurface::GreenLeft) << DSurface::GreenRight) | ((blue >> DSurface::BlueLeft) << DSurface::BlueRight);
 		p += 2;
 	}
 
-	/*
-	 * Copy the pixel data out of the file image.
-	 */
 	bitmap_data = (unsigned char *)operator new(filehead.bfSize - filehead.bfOffBits);
 	memcpy(bitmap_data, bitmap_palette_data, filehead.bfSize - filehead.bfOffBits);
 
-	/*
-	 * Blit the bitmap into a new surface. BMP pixel data is stored bottom-up,
-	 * so source rows are walked from the last row backward. The source pitch
-	 * is the width rounded down to a dword boundary plus four, which over-pads
-	 * widths that are already dword-aligned.
-	 */
-	surface = new BSurface(header.biWidth, header.biHeight, bpp);
+	int width = header.biWidth;
+	int height = header.biHeight;
+	surface = new BSurface(width, height, bpp);
 	surface_data = (unsigned short *)surface->Lock();
 	surface_width = surface->Stride() / 2;
-	bitmap_width = header.biWidth - (header.biWidth & 3) + 4;
+	bitmap_width = width - (width & 3) + 4;
 
-	if (header.biHeight > 0) {
-		int offset = 0;
-		int row_step = -bitmap_width;
-		int row_offset = bitmap_width * (header.biHeight - 1);
-		int row_count = header.biHeight;
-		do {
-			int x = 0;
-			if (header.biWidth > 0) {
-				do {
-					int source_index = row_offset + x;
-
-					if (bpp == 2) {
-						surface_data[offset + x] = pal16[bitmap_data[source_index]];
-					} else {
-						surface_data[offset + x] = bitmap_data[source_index];
-					}
-					x++;
-				} while (x < header.biWidth);
+	for (int y = 0; y < height; y++) {
+		int source_row = (height - 1 - y) * bitmap_width;
+		for (int x = 0; x < width; x++) {
+			if (bpp == 2) {
+				surface_data[y * surface_width + x] = pal16[bitmap_data[source_row + x]];
+			} else {
+				surface_data[y * surface_width + x] = bitmap_data[source_row + x];
 			}
-			row_offset += row_step;
-			offset += surface_width;
-			row_count--;
-		} while (row_count);
+		}
 	}
 
-	/*
-	 * An 8-bit surface keeps its palette in the cache entry.
-	 */
 	if (bpp == 1) {
 		memcpy(new_entry.palette, bitmap_info_header->bmiColors, sizeof(new_entry.palette));
@@ -120,14 +75,8 @@
 	key.toLower();
 
-	/*
-	 * If an entry is already cached under this name, remove it and delete
-	 * its surface before adding the new one.
-	 */
 	SurfaceCacheEntry old_entry;
 	if (getValue(key, old_entry)) {
 		remove(key);
-		if (old_entry.surf != NULL) {
-			delete old_entry.surf;
-		}
+		delete old_entry.surf;
 	}
 
```
