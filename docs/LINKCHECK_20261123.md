# Link check P9, first run (2026-11-23)

This is step 2 of the stocktake plan ("Yes do 1, 2, 3 in order").

- **Codex job:** 85e0d2d0. It reviewed gibbo101's exelink @308c005 (MIT) and built an adapted stub link with LINK 6 `/ORDER` plus a mapcheck.
- **Results:** in <work>/jobs/exelink_out/result: REPORT.md, REVIEW.md, mapcheck.json (one row per claim) and level2_exelink/ (the adapted tool, 1,232 lines).
- **Image:** the stub image and objects stay in the station kit's build folder, because they contain original bytes.

## What it measured

| Measure | Value |
|---|---|
| Claims | 17,741 |
| Exact address after linking | 2,459 |
| Different address (drifted) | 12,642 |
| Not independently placeable | 2,640 |
| Objects linked | 705 of 718 TUs |

- The 13 assembly TUs (62 claims) did not build, because the station has no UASM.
- A strict link fails with LNK1169 (duplicate definitions). The run used `/FORCE:MULTIPLE` as a diagnostic, which gave 823 LNK4006 duplicate warnings.
- The planner verified all 17,679 compiled claims against the retail bytes, which confirms level2_check independently.
- All 15,101 attributed addresses in the map were verified again.

## What it means

- **The drift is a cascade, not 12,642 wrong claims.**
  - The ordered layout has only about 30 delta transitions.
  - The first is at 0x80650. LINK took `CommBufferClass::Mono_Debug_Print` from combuf.cpp (736 bytes, not claimed) instead of the claimed 656-byte copy in TU_47FCC0.cpp, which pushes everything after it by +80. More such provider choices follow.
- **Our source is not one program yet.** The src/m85 tree (1.006 upstream) and the src/ra2 tree (our own TUs) define many of the same functions. When both are linked, the linker keeps one at random.
  - 2,567 claims are "LINK selected a different object".
  - 88 claims give 39 public names more than one address. Many of these are template and inline copies that the retail exe kept per module, which gibbo's tool handles by pinning per object.
- **The four label cases of REMATCH.md are decided:**
  - **0x169ed0 ZeroRect initializer:** keep TU_569D00 `_$E41`, retire the TU_569EF0 `_$E2` claim (it emits its own copy elsewhere). Applied.
  - **`??1BufferClass@@QAE@XZ`:** the symbol map had 0x438290, which is `Buffer::~Buffer` (buff.cpp); BufferClass is at 0x438360. Map corrected.
  - **`??RRandomClass@@QAEHHH@Z`:** the map had 0x62fe40, which is `Random2Class::operator()`; RandomClass is at 0x62fcc0. Map corrected, and `??RRandom2Class@@QAEHHH@Z` = 0x62fe40 added.
  - **`CDTimerClass<FrameTimerClass>` `??B`/`??R`:** the claims were swapped. The callers prove `??B` = 0x453b30 (FactoryClass::AI) and `??R` = 0x4a4a30 (Update_Iron_Tint, Tunnel Process). Claim symbols swapped. The two bodies are identical.
  - Backups: header_backups/level2_functions.json.before_p9fix and level2_symbols.json.before_p9fix.

## Next link iteration (after batch 40)

1. **One provider per function.** For every duplicate public name, keep the claimed definition and keep the other copy out of the link. Do this by build-side retirement of the unclaimed copy in a private object copy, as upstream does for archive objects. Never by deleting source from P.
2. **Per-object pinning** for the template and inline copies that the retail exe keeps per module (upstream pindata idea).
3. **UASM for the 13 assembly TUs** (ship our portable UASM to the station kit).
4. **Rerun mapcheck.** Real drift points then show missing functions and wrong order, so cheap gap wins become visible.
5. **Local use of level2_exelink** only after Claude has read it completely (community-tools rule). Codex's REVIEW.md covers the upstream files only.

## Follow-up of the label corrections (applied the same day)

- **After the symbol-map corrections, 12 src/ra2 claims stopped matching.** They called the wrong class, which the wrong map entries had hidden:
  - `RandomClass` used where the original calls `Random2Class::operator()` 0x62fe40 (coopcamp, Ion, MPCoop, MPScore, Multiplayer, netdlg2);
  - `BufferClass` used for the class whose destructor is `Buffer::~Buffer` 0x438290 (BUFFER.H, SURFACE.H, Init.CPP, Egos.CPP).
- **Renamed to the real classes:** patch apply_p9_names. WDTSel.cpp and WorldDom.cpp already declared that class as `Buffer` locally; those duplicate declarations were removed and BUFFER.H got their default arguments (patch apply_p9_names2).
- **Timer operators:** the `??B` claim (0x53b30) moved to building.cpp and the `??R` claim (0xa4a30) to drive.cpp, which emit them.
- **Full check:** 17,745/17,745, conflicts 0.

## Iteration 2 (job 300560ea, same evening): clean strict link

| Run | Exact | Displaced | Not independently placed |
|---|---:|---:|---:|
| First diagnostic link (`/FORCE:MULTIPLE`, 823 duplicate warnings) | 2,459 | 12,642 | 2,640 |
| Strict link before the assembly alignment correction | 17,676 | 57 | 13 |
| **Final strict link + fresh replay** | **17,733** | **0** | **13** |

- **Link:** all 718 units built (705 C/C++ with VC6, 13 asm with UASM). LINK accepted 722 inputs and 38,859 public definitions with one provider each; exit 0 with an empty diagnostic log. A fresh replay reproduced it.
- **Duplicates:** 27,078 duplicate copies were retired, as "localize definition in private object" in private build copies only (retired_copies.json). Most are inline and template COMDAT copies. P is unchanged.
- **The 13 unplaced claims** are 13 template and inline functions that the retail exe keeps twice (two RVAs each; per_object_pins.json, repeated_claims.json). Both copies are genuine retail per-module copies.
- **Meaning:** every claim sits at its own address when everything is linked. The drift of the first run came only from the competing duplicate providers. What the link cannot establish: the retail source order, identical bodies, and masked relocation targets. Those stay with level2_check and the symbol audit.
- **Near misses that fit their slot (12, at most 8 bytes off)** are candidates for the end phase or the permuter:

  | Function | RVA | Bytes off |
  |---|---|---:|
  | CheckProtectedData | 0x917f0 | 3 |
  | Get_Draw_Rect | 0x5df00 | 5 |
  | Damage_Low_Bridge (4 variants) | | 5 each |
  | Reposition_Sidebar | 0x2770d0 | 1 |
  | Pick_Lobby | | 4 |
  | Search_For_Tiberium_Weighted | 0xcb740 | 2 |
  | Adjust_Control_Position | | 1 |
  | Spread_Units_Around_Cell | 0x220ac0 | 4 |
  | Send_Statistics_Packet | 0x28e3f0 | 1 |

- **Gaps:** 106 unclaimed slots lie between two claims of the same TU, which says where missing functions sit.
- **Tool:** level2_exelink v2 is in jobs/exelink2_out/result/level2_exelink (local use only after Claude's full read).
- **Next level (not started):** the hybrid image (retail bytes for gaps, data and resources) plus the section compare. That is the step towards baseline testing.
