# RA2 Level 2 unmatched function inventory

1,130 entries total 275,096 bytes. The JSON contains 1,055 proposed declarations. A null signature means the evidence does not establish a prototype.

## Totals by source_status

| Category | Entries | Bytes |
|---|---:|---:|
| none | 7 | 13 |
| near_miss | 65 | 162,442 |
| near_equal | 10 | 22,676 |
| inline_only | 0 | 0 |
| library_or_thunk | 1,048 | 89,965 |

## Totals by domain

| Category | Entries | Bytes |
|---|---:|---:|
| gameplay | 57 | 73,308 |
| render | 15 | 26,864 |
| UI/network/platform | 40 | 85,463 |
| library | 1,018 | 89,461 |

## Identification limits

100 entries (3,053 bytes) have low confidence and no recovered identity. Address-based labels remain in that count. Direct calls and strings are contextual evidence for later identification.

## Largest entries with no identified project source

Showing 7 of 7 qualifying entries.

| RVA | Bytes | Name | Translation unit |
|---|---:|---|---|
| 0x1089d0 | 3 | infantry_return_pop_4_1089D0 | src/m85/src/infantry.cpp |
| 0x230f00 | 3 | TU_630D30_routine_230F00 | src/ra2/unnamed/TU_630D30.cpp \| src/m85/src/reinf.cpp |
| 0x293fe0 | 3 | Super_return_pop_8_293FE0 | src/ra2/Super.CPP |
| 0x967f0 | 1 | TU_496620_immediate_return_0967F0 | src/ra2/unnamed/TU_496620.cpp \| src/m85/src/delay.cpp |
| 0x130380 | 1 | TU_5301B0_immediate_return_130380 | src/ra2/unnamed/TU_5301B0.cpp \| src/m85/src/keyboard.cpp |
| 0x2f3270 | 1 | unit_immediate_return_2F3270 | src/m85/src/unit.cpp |
| 0x2f3280 | 1 | unit_immediate_return_2F3280 | src/m85/src/unit.cpp |

## Evidence and interpretation

The original belongs to RA2 1.001. Every RVA is image-relative. The current claim set comes from the supplied source archive. The strict-link map is an older snapshot. The matching retained plan supplies the original slot layout.

The 93 intervals in gap_domains.json occupy 188,670 physical bytes. Excluding every byte valued 00, 90 or CC gives exactly the supplied count in every interval, totalling 159,079. This also removes operand and instruction bytes. Use the boundary accounting for the denominator of this inventory.

An attribution between different neighbouring translation units is a candidate range. A vertical bar preserves both candidates. A domain assigned by elimination is provisional. No community file means no body could be verified in the local corpus. Historical masked difference counts describe the cited build and comparison range. Blank cells mean the quantity was not established.

A 1.006 or YR address is never used as the target 1.001 RVA solely because the numbers coincide. For example, Remove_Audio_File_Window appears at 0x522B80 in the 1.006 evidence and at 0x5220C0 in the target evidence. A matched caller relocation, a verified slot, or an independent body fingerprint can establish the correspondence.

## Suggested prompts for the next runs

1. **Replay the strongest historical results.** Start with the seven unclaimed entries with a recorded zero-difference comparison in the source evidence index. Check inventory membership. Reproduce the comparison with the retained toolchain, record the exact comparison span and relocation mask, and verify the caller binds to that same entry before proposing promotion.
2. **Resolve an identity before searching compiler settings.** Choose one of the seven short application routines with no identified project source. For each, give two plausible identities from the local corpus. Test them against a relocation in an already matched caller and one independent clue such as a vtable slot or a distinctive data reference. Return the exact evidence that excludes one candidate. Preserve ambiguous alternatives.
3. **Challenge a disputed boundary.** Pick an unresolved interval. Trace incoming calls, switch-table entries and independent exits. Give the competing interval partitions, the evidence supporting each, and the observation that would rule one out. Keep any unassigned bytes explicit. Use Combo_Proc and List_Proc as a two-function positive control and the embedded table in BuildingClass::Exit_Object as a false-start control.
4. **Separate behavioral and compiler progress.** On SuperClass::Place case 4, take the smallest differing block with a potential observable effect. Predict one input for which the two interpretations would produce different state or events. Report the behavioral finding separately from the masked byte score, and recheck all seven entries and the 46 sibling functions before promoting a source change.

## Reconciliation with the strict-link plan

Contiguous bytes from the entry through the next independently established entry, source contribution, or exact archive section end, excluding terminal NOP/INT3 fill. Embedded switch tables, operands, internal padding, and shared labels within a body remain in its physical span. Import thunks are six bytes.

| Byte assignment | Inside 93 historical intervals | Outside those intervals |
|---|---:|---:|
| alignment | 716 | 1,379 |
| claimed body | 0 | 49,156 |
| literal | 0 | 8 |
| out-of-line instructions | 22 | 0 |
| source/outside | 0 | 3,359,716 |
| unclaimed function | 187,932 | 87,164 |
| unresolved | 0 | 0 |

The source/outside figure includes the rest of the inspected section. See the machine-readable accounting for individual excluded spans and exact slot totals.

