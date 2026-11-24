# 0x300c60 ?UnVQ1_4x2_Table@@YAXPAE00KKK@Z (src/m85/src/unvqtblc.cpp)

Origin: recent port: batch_44g_*. Community source: gibbo232414_unvqtblc.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -1,215 +1,147 @@
-void __cdecl UnVQ1_4x2_Table(unsigned char * codebook, unsigned char * pointers, unsigned char * buffer, unsigned long blocksperrow, unsigned long numrows, unsigned long bufwidth)
+void __cdecl UnVQ1_4x2_Table(unsigned char *codebook, unsigned char *pointers, unsigned char *buffer,
+                             unsigned long blocks_per_row, unsigned long rows, unsigned long width)
 {
-	assert(codebook != 0);
-	assert(pointers != 0);
-	assert(buffer != 0);
-	assert(blocksperrow != 0);
-	assert(numrows != 0);
-	assert(bufwidth != 0);
-
-	bufwidth = 2 * bufwidth;
-	unsigned char * data_end = buffer + (numrows * bufwidth * 4);
-	unsigned char * last_buf_pos = buffer + 8 * blocksperrow;
-	unsigned char * row_ptr = buffer;
-	unsigned short * src = (unsigned short *)pointers;
-
-	unsigned long i;
-	unsigned short index;
-	unsigned long type;
-	unsigned int cb_idx;
-	unsigned int scatter_count;
-	unsigned int code;
-
-	while (buffer < data_end) {
-		type = (*src & 0xE000);
-		index = (*src & 0x1FFF);
-		src++;
-
-		if (type <= 0x6000) {
-			if (type != 0x6000) {
-				if (type) {
-					if (type != 0x2000) {
-						if (type == 0x4000) {
-							unsigned char primary_idx = *((unsigned char *)src - 2);
-							unsigned int count = (((unsigned short)index >> 7) & 0x3E) + 2;
-							unsigned short * cb = (unsigned short *)&codebook[32 * primary_idx];
-							unsigned int stride = bufwidth >> 2;
-							unsigned int w0;
-							unsigned int w1;
-							unsigned int w2;
-							unsigned int w3;
-							unsigned char * dstb = buffer;
-							int n;
-							for (n = 0; n < 2; n++) {
-								w0 = cb[0];
-								w1 = cb[1];
-								cb += 2;
-								((unsigned int *)dstb)[0] = w0 | (w1 << 16);
-								w2 = cb[0];
-								w3 = cb[1];
-								cb += 6;
-								((unsigned int *)dstb)[1] = w2 | (w3 << 16);
-								dstb += 4 * stride;
-							}
-							buffer += 8;
-							unsigned char * byte_src = (unsigned char *)src;
-
-							unsigned int full_stride = 8 * stride;
-							unsigned int remaining = count;
-							do {
-								unsigned char * d2 = buffer;
-								unsigned char * next_byte = byte_src + 1;
-								unsigned short * cb2 = (unsigned short *)&codebook[32 * *byte_src];
-								int n2;
-								for (n2 = 0; n2 < 2; n2++) {
-									w0 = cb2[0];
-									w1 = cb2[1];
-									cb2 += 2;
-									((unsigned int *)d2)[0] = w0 | (w1 << 16);
-									w2 = cb2[0];
-									w3 = cb2[1];
-									cb2 += 6;
-									((unsigned int *)d2)[1] = w2 | (w3 << 16);
-									d2 += full_stride;
-								}
-								byte_src = next_byte;
-								buffer += 8;
-								--remaining;
-							} while (remaining);
-							src = (unsigned short *)byte_src;
+	width *= 2;
+	unsigned int block_row_stride = width * 4;
+	unsigned char *end = buffer + rows * width * 4;
+	unsigned char *dst = buffer;
+	unsigned char *row_base = buffer;
+	unsigned char *row_end = row_base + blocks_per_row * 8;
+	unsigned short *src = (unsigned short *)pointers;
+	while (dst < end) {
+		unsigned int count = 0;
+		unsigned int index;
+		unsigned int command = (*src & 0xE000);
+		unsigned short cb_index = (*src & 0x1FFF);
+		src += 1;
+		switch (command) {
+		case 0x0000: {
+			dst += (cb_index & 0xFF) * 8;
+		} break;
+		case 0x2000: {
+			unsigned int code = cb_index;
+			count = ((code >> 7) & 0x3E) + 2;
+			index = code & 0xFF;
+		}
+		// A run with no count in its command word reads the count and index from the stream.
+		case 0xA000: {
+			if (count == 0) {
+				count = *(unsigned char *)src;
+				index = cb_index;
+				src = (unsigned short *)((unsigned char *)src + 1);
+			}
+			unsigned char const *cb = codebook + (index << 5);
+			for (unsigned int r = 0; r < 2; r++) {
+				unsigned int lo = ((unsigned int)*(unsigned short const *)(cb + 2) << 16) | *(unsigned short const *)(cb + 0);
+				cb += 4;
+				unsigned char *p = dst;
+				for (unsigned int n = 0; n < count; n++) {
+					*(unsigned int *)p = lo;
+					p += 8;
+				}
+				unsigned int hi = ((unsigned int)*(unsigned short const *)(cb + 2) << 16) | *(unsigned short const *)(cb + 0);
+				cb += 12;
+				p = dst + 4;
+				for (unsigned int n2 = 0; n2 < count; n2++) {
+					*(unsigned int *)p = hi;
+					p += 8;
+				}
+				dst += width * 2;
+			}
+			dst += 8 * count - block_row_stride;
+		} break;
+		case 0x4000: {
+			count = ((cb_index >> 7) & 0x3E) + 2;
+			unsigned char const *cb = codebook + (*((unsigned char *)src - 2) << 5);
+			unsigned int stride = width >> 2;
+			unsigned char *p = dst;
+			for (unsigned int r = 0; r < 2; r++) {
+				unsigned int lo = ((unsigned int)*(unsigned short const *)(cb + 2) << 16) | *(unsigned short const *)(cb + 0);
+				cb += 4;
+				*(unsigned int *)(p + 0) = lo;
+				unsigned int hi = ((unsigned int)*(unsigned short const *)(cb + 2) << 16) | *(unsigned short const *)(cb + 0);
+				cb += 12;
+				*(unsigned int *)(p + 4) = hi;
+				p += stride * 4;
+			}
+			dst += 8;
+			unsigned char *bytes = (unsigned char *)src;
+			for (unsigned int n = 0; n < count; n++) {
+				unsigned int next = *bytes;
+				bytes++;
+				unsigned char const *cb2 = codebook + (next << 5);
+				unsigned char *q = dst;
+				for (unsigned int r2 = 0; r2 < 2; r2++) {
+					unsigned int lo = ((unsigned int)*(unsigned short const *)(cb2 + 2) << 16) | *(unsigned short const *)(cb2 + 0);
+					cb2 += 4;
+					*(unsigned int *)(q + 0) = lo;
+					unsigned int hi = ((unsigned int)*(unsigned short const *)(cb2 + 2) << 16) | *(unsigned short const *)(cb2 + 0);
+					cb2 += 12;
+					*(unsigned int *)(q + 4) = hi;
+					q += stride * 8;
+				}
+				dst += 8;
+			}
+			src = (unsigned short *)bytes;
+		} break;
+		case 0x6000: {
+			unsigned char const *cb = codebook + (cb_index << 5);
+			for (unsigned int r = 0; r < 4; r++) {
+				unsigned int lo = ((unsigned int)*(unsigned short const *)(cb + 2) << 16) | *(unsigned short const *)(cb + 0);
+				cb += 4;
+				*(unsigned int *)(dst + 0) = lo;
+				unsigned int hi = ((unsigned int)*(unsigned short const *)(cb + 2) << 16) | *(unsigned short const *)(cb + 0);
+				cb += 12;
+				*(unsigned int *)(dst + 4) = hi;
+				dst += width * 2;
+			}
+			dst += 8 - block_row_stride;
+		} break;
+		case 0x8000: {
+			unsigned short const *cb = (unsigned short const *)(codebook + (cb_index << 5));
+			for (unsigned int r = 0; r < 4; r++) {
+				unsigned short *p = (unsigned short *)dst;
+				for (unsigned int c = 0; c < 4; c++) {
+					if (!(*cb & 0x8000))
+						*p = *cb;
+					p++;
+					cb++;
+				}
+				cb += 4;
+				dst += width * 2;
+			}
+			dst += 8 - block_row_stride;
+		} break;
+		case 0xC000: {
+			count = *(unsigned char *)src;
+			index = cb_index;
+			src = (unsigned short *)((unsigned char *)src + 1);
+			unsigned short const *cb = (unsigned short const *)(codebook + (index << 5));
+			for (unsigned int r = 0; r < 2; r++) {
+				unsigned short *p = (unsigned short *)dst;
+				for (unsigned int c = 0; c < 4; c++) {
+					unsigned short pixel = *cb;
+					if (!(*cb & 0x8000)) {
+						unsigned short *q = p;
+						for (unsigned int n = 0; n < count; n++) {
+							*q = pixel;
+							q += 4;
 						}
-					} else {
-						code = index;
-						code &= 0xFFFF;
-						cb_idx = code & 0xFF;
-						scatter_count = ((code >> 7) & 0x3E) + 2;
-						if (scatter_count == 0) {
-							goto label_extended_count;
-						}
-
-					label_scatter_copy: {
-						unsigned int len = 2;
-						unsigned short * cb = (unsigned short *)&codebook[32 * cb_idx];
-						do {
-							unsigned int w0 = cb[0];
-							unsigned int w1 = cb[1];
-							unsigned int value = w0 | (w1 << 16);
-							cb += 2;
-							unsigned char * dstb = buffer;
-							if (scatter_count > 0) {
-								unsigned int remain = scatter_count;
-								do {
-									*(unsigned int *)dstb = value;
-									dstb += 8;
-									--remain;
-								} while (remain);
-							}
-							unsigned int w2 = cb[0];
-							unsigned int w3 = cb[1];
-							value = w2 | (w3 << 16);
-							cb += 6;
-							unsigned char * d2 = buffer + 4;
-							if (scatter_count > 0) {
-								unsigned int remain = scatter_count;
-								do {
-									*(unsigned int *)d2 = value;
-									d2 += 8;
-									--remain;
-								} while (remain);
-							}
-							buffer += 2 * bufwidth;
-							--len;
-						} while (len);
-						buffer += 8 * scatter_count - (int)(bufwidth << 2);
 					}
-					}
-				} else {
-					buffer += 8 * (unsigned char)index;
+					p++;
+					cb++;
 				}
-			} else {
-				unsigned short * cb = (unsigned short *)&codebook[32 * index];
-				unsigned int w0;
-				unsigned int w1;
-				unsigned int w2;
-				unsigned int w3;
-				for (i = 0; i != 4; i++) {
-					w0 = cb[0];
-					w1 = cb[1];
-					((unsigned int *)buffer)[0] = w0 | (w1 << 16);
-					cb += 2;
-					w2 = cb[0];
-					w3 = cb[1];
-					((unsigned int *)buffer)[1] = w2 | (w3 << 16);
-					cb += 6;
-					buffer += 2 * bufwidth;
-				}
-				buffer += 8 - (int)(bufwidth << 2);
+				cb += 4;
+				dst += width * 2;
 			}
-		} else {
-			switch (type) {
-			case 0x8000: {
-				unsigned short * cb = (unsigned short *)&codebook[32 * index];
-				int len = 4;
-				do {
-					unsigned short * dstw = (unsigned short *)buffer;
-					int c2 = 4;
-					do {
-						if ((*cb & 0x8000) == 0) {
-							*dstw = *cb;
-						}
-						dstw++;
-						cb++;
-						--c2;
-					} while (c2);
-					cb += 4;
-					buffer += 2 * bufwidth;
-					--len;
-				} while (len);
-				buffer += 8 - (int)(bufwidth << 2);
-				break;
-			}
-
-			case 0xA000: {
-			label_extended_count:
-				scatter_count = *(unsigned char *)src;
-				cb_idx = (unsigned short)index;
-				src = (unsigned short *)((unsigned char *)src + 1);
-				goto label_scatter_copy;
-			}
-
-			case 0xC000: {
-				unsigned int count = *(unsigned char *)src;
-				src = (unsigned short *)((unsigned char *)src + 1);
-				unsigned short * cb = (unsigned short *)&codebook[32 * index];
-				unsigned int len;
-				for (len = 0; len < 2; len++) {
-					unsigned short * dstw = (unsigned short *)buffer;
-					unsigned int c2;
-					for (c2 = 0; c2 < 4; c2++) {
-						unsigned short cbval = *cb;
-						if ((*cb & 0x8000) == 0) {
-							unsigned short * d2 = dstw;
-							unsigned int c3;
-							for (c3 = 0; c3 < count; c3++) {
-								*d2 = cbval;
-								d2 += 4;
-							}
-						}
-						dstw++;
-						cb++;
-					}
-					cb += 4;
-					buffer += 2 * bufwidth;
-				}
-
-				buffer += 8 * count - (int)(bufwidth << 2);
-				break;
-			}
-			}
+			dst += 8 * count - block_row_stride;
+		} break;
+		default:
+			break;
 		}
-		if (buffer == last_buf_pos) {
-			buffer = row_ptr + (bufwidth << 2);
-			row_ptr = buffer;
-			last_buf_pos = buffer + 8 * blocksperrow;
+		if (dst == row_end) {
+			row_base += block_row_stride;
+			dst = row_base;
+			row_end = row_base + blocks_per_row * 8;
 		}
 	}
```

## 2. Our matched form against the community form

```diff
(identical)
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -1,215 +1,147 @@
-void __cdecl UnVQ1_4x2_Table(unsigned char * codebook, unsigned char * pointers, unsigned char * buffer, unsigned long blocksperrow, unsigned long numrows, unsigned long bufwidth)
+void __cdecl UnVQ1_4x2_Table(unsigned char *codebook, unsigned char *pointers, unsigned char *buffer,
+                             unsigned long blocks_per_row, unsigned long rows, unsigned long width)
 {
-	assert(codebook != 0);
-	assert(pointers != 0);
-	assert(buffer != 0);
-	assert(blocksperrow != 0);
-	assert(numrows != 0);
-	assert(bufwidth != 0);
-
-	bufwidth = 2 * bufwidth;
-	unsigned char * data_end = buffer + (numrows * bufwidth * 4);
-	unsigned char * last_buf_pos = buffer + 8 * blocksperrow;
-	unsigned char * row_ptr = buffer;
-	unsigned short * src = (unsigned short *)pointers;
-
-	unsigned long i;
-	unsigned short index;
-	unsigned long type;
-	unsigned int cb_idx;
-	unsigned int scatter_count;
-	unsigned int code;
-
-	while (buffer < data_end) {
-		type = (*src & 0xE000);
-		index = (*src & 0x1FFF);
-		src++;
-
-		if (type <= 0x6000) {
-			if (type != 0x6000) {
-				if (type) {
-					if (type != 0x2000) {
-						if (type == 0x4000) {
-							unsigned char primary_idx = *((unsigned char *)src - 2);
-							unsigned int count = (((unsigned short)index >> 7) & 0x3E) + 2;
-							unsigned short * cb = (unsigned short *)&codebook[32 * primary_idx];
-							unsigned int stride = bufwidth >> 2;
-							unsigned int w0;
-							unsigned int w1;
-							unsigned int w2;
-							unsigned int w3;
-							unsigned char * dstb = buffer;
-							int n;
-							for (n = 0; n < 2; n++) {
-								w0 = cb[0];
-								w1 = cb[1];
-								cb += 2;
-								((unsigned int *)dstb)[0] = w0 | (w1 << 16);
-								w2 = cb[0];
-								w3 = cb[1];
-								cb += 6;
-								((unsigned int *)dstb)[1] = w2 | (w3 << 16);
-								dstb += 4 * stride;
-							}
-							buffer += 8;
-							unsigned char * byte_src = (unsigned char *)src;
-
-							unsigned int full_stride = 8 * stride;
-							unsigned int remaining = count;
-							do {
-								unsigned char * d2 = buffer;
-								unsigned char * next_byte = byte_src + 1;
-								unsigned short * cb2 = (unsigned short *)&codebook[32 * *byte_src];
-								int n2;
-								for (n2 = 0; n2 < 2; n2++) {
-									w0 = cb2[0];
-									w1 = cb2[1];
-									cb2 += 2;
-									((unsigned int *)d2)[0] = w0 | (w1 << 16);
-									w2 = cb2[0];
-									w3 = cb2[1];
-									cb2 += 6;
-									((unsigned int *)d2)[1] = w2 | (w3 << 16);
-									d2 += full_stride;
-								}
-								byte_src = next_byte;
-								buffer += 8;
-								--remaining;
-							} while (remaining);
-							src = (unsigned short *)byte_src;
+	width *= 2;
+	unsigned int block_row_stride = width * 4;
+	unsigned char *end = buffer + rows * width * 4;
+	unsigned char *dst = buffer;
+	unsigned char *row_base = buffer;
+	unsigned char *row_end = row_base + blocks_per_row * 8;
+	unsigned short *src = (unsigned short *)pointers;
+	while (dst < end) {
+		unsigned int count = 0;
+		unsigned int index;
+		unsigned int command = (*src & 0xE000);
+		unsigned short cb_index = (*src & 0x1FFF);
+		src += 1;
+		switch (command) {
+		case 0x0000: {
+			dst += (cb_index & 0xFF) * 8;
+		} break;
+		case 0x2000: {
+			unsigned int code = cb_index;
+			count = ((code >> 7) & 0x3E) + 2;
+			index = code & 0xFF;
+		}
+		// A run with no count in its command word reads the count and index from the stream.
+		case 0xA000: {
+			if (count == 0) {
+				count = *(unsigned char *)src;
+				index = cb_index;
+				src = (unsigned short *)((unsigned char *)src + 1);
+			}
+			unsigned char const *cb = codebook + (index << 5);
+			for (unsigned int r = 0; r < 2; r++) {
+				unsigned int lo = ((unsigned int)*(unsigned short const *)(cb + 2) << 16) | *(unsigned short const *)(cb + 0);
+				cb += 4;
+				unsigned char *p = dst;
+				for (unsigned int n = 0; n < count; n++) {
+					*(unsigned int *)p = lo;
+					p += 8;
+				}
+				unsigned int hi = ((unsigned int)*(unsigned short const *)(cb + 2) << 16) | *(unsigned short const *)(cb + 0);
+				cb += 12;
+				p = dst + 4;
+				for (unsigned int n2 = 0; n2 < count; n2++) {
+					*(unsigned int *)p = hi;
+					p += 8;
+				}
+				dst += width * 2;
+			}
+			dst += 8 * count - block_row_stride;
+		} break;
+		case 0x4000: {
+			count = ((cb_index >> 7) & 0x3E) + 2;
+			unsigned char const *cb = codebook + (*((unsigned char *)src - 2) << 5);
+			unsigned int stride = width >> 2;
+			unsigned char *p = dst;
+			for (unsigned int r = 0; r < 2; r++) {
+				unsigned int lo = ((unsigned int)*(unsigned short const *)(cb + 2) << 16) | *(unsigned short const *)(cb + 0);
+				cb += 4;
+				*(unsigned int *)(p + 0) = lo;
+				unsigned int hi = ((unsigned int)*(unsigned short const *)(cb + 2) << 16) | *(unsigned short const *)(cb + 0);
+				cb += 12;
+				*(unsigned int *)(p + 4) = hi;
+				p += stride * 4;
+			}
+			dst += 8;
+			unsigned char *bytes = (unsigned char *)src;
+			for (unsigned int n = 0; n < count; n++) {
+				unsigned int next = *bytes;
+				bytes++;
+				unsigned char const *cb2 = codebook + (next << 5);
+				unsigned char *q = dst;
+				for (unsigned int r2 = 0; r2 < 2; r2++) {
+					unsigned int lo = ((unsigned int)*(unsigned short const *)(cb2 + 2) << 16) | *(unsigned short const *)(cb2 + 0);
+					cb2 += 4;
+					*(unsigned int *)(q + 0) = lo;
+					unsigned int hi = ((unsigned int)*(unsigned short const *)(cb2 + 2) << 16) | *(unsigned short const *)(cb2 + 0);
+					cb2 += 12;
+					*(unsigned int *)(q + 4) = hi;
+					q += stride * 8;
+				}
+				dst += 8;
+			}
+			src = (unsigned short *)bytes;
+		} break;
+		case 0x6000: {
+			unsigned char const *cb = codebook + (cb_index << 5);
+			for (unsigned int r = 0; r < 4; r++) {
+				unsigned int lo = ((unsigned int)*(unsigned short const *)(cb + 2) << 16) | *(unsigned short const *)(cb + 0);
+				cb += 4;
+				*(unsigned int *)(dst + 0) = lo;
+				unsigned int hi = ((unsigned int)*(unsigned short const *)(cb + 2) << 16) | *(unsigned short const *)(cb + 0);
+				cb += 12;
+				*(unsigned int *)(dst + 4) = hi;
+				dst += width * 2;
+			}
+			dst += 8 - block_row_stride;
+		} break;
+		case 0x8000: {
+			unsigned short const *cb = (unsigned short const *)(codebook + (cb_index << 5));
+			for (unsigned int r = 0; r < 4; r++) {
+				unsigned short *p = (unsigned short *)dst;
+				for (unsigned int c = 0; c < 4; c++) {
+					if (!(*cb & 0x8000))
+						*p = *cb;
+					p++;
+					cb++;
+				}
+				cb += 4;
+				dst += width * 2;
+			}
+			dst += 8 - block_row_stride;
+		} break;
+		case 0xC000: {
+			count = *(unsigned char *)src;
+			index = cb_index;
+			src = (unsigned short *)((unsigned char *)src + 1);
+			unsigned short const *cb = (unsigned short const *)(codebook + (index << 5));
+			for (unsigned int r = 0; r < 2; r++) {
+				unsigned short *p = (unsigned short *)dst;
+				for (unsigned int c = 0; c < 4; c++) {
+					unsigned short pixel = *cb;
+					if (!(*cb & 0x8000)) {
+						unsigned short *q = p;
+						for (unsigned int n = 0; n < count; n++) {
+							*q = pixel;
+							q += 4;
 						}
-					} else {
-						code = index;
-						code &= 0xFFFF;
-						cb_idx = code & 0xFF;
-						scatter_count = ((code >> 7) & 0x3E) + 2;
-						if (scatter_count == 0) {
-							goto label_extended_count;
-						}
-
-					label_scatter_copy: {
-						unsigned int len = 2;
-						unsigned short * cb = (unsigned short *)&codebook[32 * cb_idx];
-						do {
-							unsigned int w0 = cb[0];
-							unsigned int w1 = cb[1];
-							unsigned int value = w0 | (w1 << 16);
-							cb += 2;
-							unsigned char * dstb = buffer;
-							if (scatter_count > 0) {
-								unsigned int remain = scatter_count;
-								do {
-									*(unsigned int *)dstb = value;
-									dstb += 8;
-									--remain;
-								} while (remain);
-							}
-							unsigned int w2 = cb[0];
-							unsigned int w3 = cb[1];
-							value = w2 | (w3 << 16);
-							cb += 6;
-							unsigned char * d2 = buffer + 4;
-							if (scatter_count > 0) {
-								unsigned int remain = scatter_count;
-								do {
-									*(unsigned int *)d2 = value;
-									d2 += 8;
-									--remain;
-								} while (remain);
-							}
-							buffer += 2 * bufwidth;
-							--len;
-						} while (len);
-						buffer += 8 * scatter_count - (int)(bufwidth << 2);
 					}
-					}
-				} else {
-					buffer += 8 * (unsigned char)index;
+					p++;
+					cb++;
 				}
-			} else {
-				unsigned short * cb = (unsigned short *)&codebook[32 * index];
-				unsigned int w0;
-				unsigned int w1;
-				unsigned int w2;
-				unsigned int w3;
-				for (i = 0; i != 4; i++) {
-					w0 = cb[0];
-					w1 = cb[1];
-					((unsigned int *)buffer)[0] = w0 | (w1 << 16);
-					cb += 2;
-					w2 = cb[0];
-					w3 = cb[1];
-					((unsigned int *)buffer)[1] = w2 | (w3 << 16);
-					cb += 6;
-					buffer += 2 * bufwidth;
-				}
-				buffer += 8 - (int)(bufwidth << 2);
+				cb += 4;
+				dst += width * 2;
 			}
-		} else {
-			switch (type) {
-			case 0x8000: {
-				unsigned short * cb = (unsigned short *)&codebook[32 * index];
-				int len = 4;
-				do {
-					unsigned short * dstw = (unsigned short *)buffer;
-					int c2 = 4;
-					do {
-						if ((*cb & 0x8000) == 0) {
-							*dstw = *cb;
-						}
-						dstw++;
-						cb++;
-						--c2;
-					} while (c2);
-					cb += 4;
-					buffer += 2 * bufwidth;
-					--len;
-				} while (len);
-				buffer += 8 - (int)(bufwidth << 2);
-				break;
-			}
-
-			case 0xA000: {
-			label_extended_count:
-				scatter_count = *(unsigned char *)src;
-				cb_idx = (unsigned short)index;
-				src = (unsigned short *)((unsigned char *)src + 1);
-				goto label_scatter_copy;
-			}
-
-			case 0xC000: {
-				unsigned int count = *(unsigned char *)src;
-				src = (unsigned short *)((unsigned char *)src + 1);
-				unsigned short * cb = (unsigned short *)&codebook[32 * index];
-				unsigned int len;
-				for (len = 0; len < 2; len++) {
-					unsigned short * dstw = (unsigned short *)buffer;
-					unsigned int c2;
-					for (c2 = 0; c2 < 4; c2++) {
-						unsigned short cbval = *cb;
-						if ((*cb & 0x8000) == 0) {
-							unsigned short * d2 = dstw;
-							unsigned int c3;
-							for (c3 = 0; c3 < count; c3++) {
-								*d2 = cbval;
-								d2 += 4;
-							}
-						}
-						dstw++;
-						cb++;
-					}
-					cb += 4;
-					buffer += 2 * bufwidth;
-				}
-
-				buffer += 8 * count - (int)(bufwidth << 2);
-				break;
-			}
-			}
+			dst += 8 * count - block_row_stride;
+		} break;
+		default:
+			break;
 		}
-		if (buffer == last_buf_pos) {
-			buffer = row_ptr + (bufwidth << 2);
-			row_ptr = buffer;
-			last_buf_pos = buffer + 8 * blocksperrow;
+		if (dst == row_end) {
+			row_base += block_row_stride;
+			dst = row_base;
+			row_end = row_base + blocks_per_row * 8;
 		}
 	}
```
