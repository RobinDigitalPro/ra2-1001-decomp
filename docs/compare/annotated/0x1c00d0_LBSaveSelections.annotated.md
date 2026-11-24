# 0x1c00d0 · LBSaveSelections

## Diff 1, H1 (old 1–35 → matched 1–42)

**DECISIVE.** The multi-selection loop writes the row fetch in full, while the single-selection path exits on a negative index. In the matched translation-unit context VC6 8168 produces 159 positional differences with the old body (768 padded bytes) and zero with the new body (800 padded bytes). The following reversions each start from the matched body.

| Within H1 | Before → after | Independent observation |
|---|---|---|
| Multi-selection text fetch | `Get_List_Row_Text(listbox, i, wide, buffer)` → inline the mode probe, wide message or narrow message and `Char_To_Wide`. The same dictionary insertion follows each successful fetch. | Reinstating the old helper here gives 54 differences and only 640 padded bytes. **DECISIVE in the matched context.** |
| Single-selection guard | `if (index >= 0) { … }` → `if (index < 0) return` followed by the scope containing the same row handling. | Reinstating the positive guard gives 15 differences at the same 800-byte section size. **DECISIVE in the matched context.** |
| Single-selection row fetch | The raw mode probe becomes `List_Row_Is_Wide`. The wide arm still sends OD_GETTEXTW directly. The narrow arm now calls `List_Row_Wide_Text`, which sends OD_GETTEXTA and converts the result. | Expanding either the probe or the narrow conversion separately still gives zero. Their individual spellings are byte-neutral under these conditions. |
| Declarations and formatting | The key is still WideWstring. Both text buffers still hold 1,024 elements. Clearing the single-select wide buffer, inserting true and checking the selection flags retain their order. Comments and indentation change. | No new key type, buffer size or insertion algorithm. |

The attached Gibbo donor, gibbo1b47a1_netshare.cpp, also writes out the multi-select fetch. Its early exit handles a zero item count, its single path tests `index >= 0` and its single fetch uses LBGetText. The RA2 port's negative index guard and finer helper split distinguish it from that snapshot. Its source credit instead names meastes' Save_List_Selection_005c5ff0 at 613e28e4e0. Both references matter when assigning credit.

## Why we did not find it

**Partly before the batch-25 match.** Batch 18 had the right pair of dictionary expansions in a diagnostic. Fifteen stack displacements remained, with key and spill at 0x10/0x14 interchanged. That trial also lost the standalone keyHash symbol, so the retained source stayed at 159 differences. Batch 25's `netshare_lb.json` greedy search stopped at 17 disassembly hunks, while its grid reached zero. It used the separate m85 TU, placed the function after Change_Slot_Type and preserved the standalone wide-key/bool keyHash with a specialization. The result retained 173 sibling sections. The function had 793 code bytes, 7 padding bytes and 17 open relocation bindings in that batch.

## How they found it

Gibbo's data/attempts.csv for YR 0x005E5F10, November 2–3, records 79.6% with the loop expanded and the single path through LBGetText. Both paths through the helper scored 76.8%. Expanding the single path too scored 20.3%. Their diagnosis tracked which branch inlined Dictionary::expand and its keyHash. The November 10 entry records a one-use Save_Selected_Text helper that yielded a match but was banked as steering. The November 20 round revisited those banked near-matches. Those notes explain the YR helper search. The measured negative-index guard above is specific evidence for our RA2 build.
