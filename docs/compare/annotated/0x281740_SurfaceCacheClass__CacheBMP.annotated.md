# 0x281740 · SurfaceCacheClass::CacheBMP

## Diff 1, hunk 1 of 3 · declaration cleanup

**Before** · `unsigned palette_bytes;`. **After** · the declaration disappears and an attribution comment is added. Hunk 2 eliminates both uses of the variable. Applying hunk 1 alone to the failed translation unit therefore raises VC6 C2065. Keeping the old, now-unused declaration while applying hunk 2 yields an exact byte match. Neither line is required in the winning context.

## Hunk 2 of 3 — **DECISIVE**

**Before** · header members were copied in a shuffled order, including height before size; `palette_bytes` held the computed length. **After** · the code copies the bitmap header in field-declaration order, from `biSize`, width and height through `biClrImportant`. It recomputes `header.biClrUsed * sizeof(RGBQUAD)` for the palette copy and cursor advance. Header sizes are spelled using the corresponding types. The cache entry is declared before parsing; the 256-entry 16-bit palette is declared near its first use. Deleted commentary and the unused-argument cast add no executable operations.

**Before** · `blue = p[0]` and `green = p[1]` preceded a separate advance and staged channel ORs. **After** · two post-increment reads and one red/green/blue OR expression change the order in which intermediate values are available. The cursor still advances past red and the reserved byte. Width and height are cached and reused in construction, row addressing and loop bounds. The failed source maintained row counters and offsets with nested `do` loops. The port uses ascending `y` and `x` and computes the bottom-up source row from `(height - 1 - y) * bitmap_width`; destination indexing uses `y * surface_width + x`. The original pitch calculation, including its floor-plus-four behavior, is preserved. Thus this hunk affects register lifetimes from header parsing through pixel conversion. Its success does not establish separate necessity for every expression.

**Rebuild.** The batch 44g failed TU gave 858 differing bytes in 1,472. Applying only hunk 2 gave zero in the same section. The complete patch also gave zero; batch 44g independently resolved all 30 relocations. Its controls found the width/height declaration swap, regrouped row expression and alternative tested palette-element `sizeof` neutral on the winner. The tested alternate pitch bit-mask scored 2.

## Hunk 3 of 3 · cleanup on replacement

**Before** · `if (old_entry.surf != NULL)` guarded deletion. **After** · `delete old_entry.surf;` stands alone; comments and whitespace disappear. Null deletion is defined. Applying only this hunk left the failed object's 858 differing bytes unchanged, and hunk 2 matched with the guard retained. It is cosmetic for this target.

## Why we did not find it

**Partly.** The supplied ledger has no CacheBMP row; CachePCX is a separate function. Batch 33's `targets/srfcache/REPORT.md` and `srfcache_bmp_loops.json` document 540 candidates and a best improvement from 942 to 858 differing bytes. They include a declaration-order header copy, cursor variants, palette access/accumulation, and pixel-loop recurrences. They vary pieces of an inexact 1.006-derived body; they do not document the complete setup, palette expression, and indexed two-dimensional loop in one candidate. The older YR source used then supplied CachePCX. The later port changed that common context in one step.

## How they found it

Gibbo's 23 November round notes and attempt 4135 describe using the sibling CachePCX for palette construction and restoring header declaration order. Their TS comparison supplied corresponding assembly, but the tested OpenTS source itself reached only 39.8%. The notes call out the input cursor, header-load schedule and allocation/constructor sequence. The matched RA2 port credits `gibbo232414_srfcache.cpp` at `232414dc36`. Diff 2 adds only native attribution.
