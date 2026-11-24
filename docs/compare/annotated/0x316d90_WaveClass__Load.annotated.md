# 0x316d90 · WaveClass::Load

## Diff 1, hunk 1 of 2 — **DECISIVE jointly with hunk 2**

**Before** · `int index; int count;` and a direct `stream->Read(&count, sizeof(count), NULL)`. **After** · `WaveCellReader reader(stream);` is constructed between the locals, then `reader.Read(count)` reads the count. The definition outside the printed function wraps the existing stream and exposes a const `Read(T&)` member template. It forwards the address and sizeof its argument to the original virtual Read. Native code marks this helper as inferred. The serialized field and the HRESULT check are unchanged.

## Hunk 2 of 2 — **DECISIVE jointly with hunk 1**

**Before** · direct read of the local cell pointer, `stream->Read(&obj, sizeof(obj), NULL)`. **After** · `reader.Read(obj)` instantiates the same member template for a pointer lvalue. This is a second static inline site even though it appears inside a runtime loop. Hunk 2 depends on the reader declaration in hunk 1; failure handling and subsequent cell handling stay in place.

**Controlled rebuild.** Starting with the archived failed TU, all five builds used identical VC6 8168 level-2 settings. Counts are relocation-masked differing bytes.

| Applied to the failed TU | Emitted section | Differences |
|---|---:|---:|
| Baseline | 384 | 259 |
| Reader definition and local construction only | 384 | 259 |
| Definition/construction plus count read only | 384 | 259 |
| Definition/construction plus pointer read only | 384 | 259 |
| Definition/construction plus both typed reads | 352 | 0 |

The sites form a joint requirement in these tests. Each single-site trial has the same score as the baseline, so a search that keeps only individual improvements discards both. Batch 24's `wave` report attributes the result to the VC6 inline budget: the reader constructor and two instantiations contribute three sites, changing the constructor boundary emitted during load from the base VectorClass path to the 93-byte DynamicVectorClass constructor. The report resolves 14 bindings. The byte test confirms the combination; it does not prove this exact helper appeared in Westwood's source.

## Why we did not find it

**Partly.** `DEFERRED_TO_END.md` records the three-inline-site diagnosis from m85fix/fable11 and A6's difficulty finding a natural way to supply them. Earlier reasoning considered swizzle helpers. The raw community form also failed in native testing. The ledger's batch 24 row and its `restore_io` variants document the eventual count-and-pointer reader together after earlier variants scored 7. The search knew the size of the inlining shift before it knew which two operations shared an abstraction.

## How they found it

`meastes1006_wave.cpp` supplied the load sequence: reconstruct without initialization, restore wave shape, swizzle, then read count and cells. Diff 3 shows its reads are the same direct virtual calls as our failed body. Its `&ActiveWave.StartMiddle` corresponds to the native separate `&ActiveWaveStartMiddle` symbol. The typed reader is a native batch 24 adaptation; assigning its discovery to meastes or Gibbo would misidentify the source. There is no donor discovery note for that reader.
