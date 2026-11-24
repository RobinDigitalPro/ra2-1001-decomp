# Guide sources

Section titles and line numbers refer to the supplied OPEN_PATTERNS.md snapshot. Ledger entries and audit verdicts are identified separately. A measured diagnostic can explain a residue even when the example remains open.

## Workflow

- **W1** OPEN_PATTERNS.md L1201, “P5: gibbo 721d81e44f port; three stubborn near misses closed by upstream FORMS, none by a gauge (2026-11-23, port agent P5; infantry Per_Cell_Process 0xfffa0, team AI 0x2ad120, map Repair_Bridge 0x152ef0 all byte-identical)” · OPEN_PATTERNS.md L1209, “Synthesis of the P5 ports (2026-11-23, coordinator)”.

- **W2** OPEN_PATTERNS.md L1121, “BB1 notes (2026-11-23, ownrdraw big blocks: Slide_Dialog 0x1dd5e0 and Default_Dialog_Proc 0x1f77c0, neither matched)” · OPEN_PATTERNS.md L1150, “BB2: a walked save buffer was an indexed one; a "reused" Cell was a second variable; a tied pair of out-of-line += is a nested inline (2026-11-23, map Set_Map_Dimensions 0x145970, 183 -> 67 masked hunks, not matched)”.

- **W3** OPEN_PATTERNS.md L1216, “M1: meastes/redalert2-decomp (RA2 1.006, VC6) as a port source; pairing by order anchors; one inline level less sets a sum's operand order (2026-11-23, port agent M1; ionblast AI 0x120880 byte-identical, one binding open)”.

- **W4** OPEN_PATTERNS.md L1276, “Wrong symbol-map entries can hide wrong source (P9 link check, 2026-11-23)” · REMATCH.md § Label audit.

- **W5** OPEN_PATTERNS.md L165, “KEY: VC6 register choice for temporaries (2026-11-21)” · ATTEMPT_LEDGER.csv · Place_Veins@CellClass, status ‘needs new method’.

## Compiler rules

- **C1** OPEN_PATTERNS.md L121, “The "inline budget" is a COUNT rule (Fable, 2026-11-19, measured on wave Load and strtable LoadFile)” · OPEN_PATTERNS.md L1209, “Synthesis of the P5 ports (2026-11-23, coordinator)” · OPEN_PATTERNS.md L1266, “C2.DLL 8168 rules (Codex batch 32, 2026-11-23): evaluation”.

- **C2** OPEN_PATTERNS.md L786, “F6: a function-wide address web is cut by ONE block that needs all callee-saved registers; an operand loaded before a call is the lever (2026-11-22, foot FootClass::AI matched; team AI not matched)” · OPEN_PATTERNS.md L1201, “P5: gibbo 721d81e44f port; three stubborn near misses closed by upstream FORMS, none by a gauge (2026-11-23, port agent P5; infantry Per_Cell_Process 0xfffa0, team AI 0x2ad120, map Repair_Bridge 0x152ef0 all byte-identical)” · OPEN_PATTERNS.md L1266, “C2.DLL 8168 rules (Codex batch 32, 2026-11-23): evaluation”.

- **C3** OPEN_PATTERNS.md L845, “F14 notes (2026-11-22, queue Print_CRCs 0x221b90 hash order: mechanism and the package that keeps it)” · OPEN_PATTERNS.md L1140, “H5: queue Print_CRCs has a two-wide declaration window, and today's P sits on its lower edge (2026-11-23, header agent H5, snapshot snapH5)” · OPEN_PATTERNS.md L1266, “C2.DLL 8168 rules (Codex batch 32, 2026-11-23): evaluation”.

- **C4** OPEN_PATTERNS.md L1253, “P6: gibbo f522351dd2 / meastes 7c68e23b61 port; the out-of-line DirType::operator>= is cut by its ASSIGNMENT COUNT, with no gauge, but the same header form cuts it in hover Process too (2026-11-23, port agent P6, snapshot snapP6; fly Nearing_Target 0xbe390 byte-identical and bound, parked)” · OPEN_PATTERNS.md L1266, “C2.DLL 8168 rules (Codex batch 32, 2026-11-23): evaluation”.

- **C5** OPEN_PATTERNS.md L374, “Checker: SEH evidence (2026-11-22, WinMain)” · OPEN_PATTERNS.md L1266, “C2.DLL 8168 rules (Codex batch 32, 2026-11-23): evaluation”.

- **C6** OPEN_PATTERNS.md L894, “gibbo 94fbaceabc port (2026-11-22)” · OPEN_PATTERNS.md L1266, “C2.DLL 8168 rules (Codex batch 32, 2026-11-23): evaluation”.

- **C7** OPEN_PATTERNS.md L142, “KEY: VC6 stack-slot assignment (2026-11-21)” · OPEN_PATTERNS.md L176, “KEY: TU symbol-history dependence (2026-11-21, queue Print_CRCs)”.

- **C8** OPEN_PATTERNS.md L277, “KEY: spilled-scalar slot order (w73, 2026-11-21, techno Fire_At)”.

- **C9** OPEN_PATTERNS.md L431, “Hand-flattened DirType conversions change x87/argument scheduling (2026-11-22, A10 bullet Unlimbo)”.

- **C10** OPEN_PATTERNS.md L681, “B26: an exact +1 register-temp window that is not the mod-3 rotation (2026-11-22, team TeamClass::AI / foot FootClass::AI, not matched)” · OPEN_PATTERNS.md L1201, “P5: gibbo 721d81e44f port; three stubborn near misses closed by upstream FORMS, none by a gauge (2026-11-23, port agent P5; infantry Per_Cell_Process 0xfffa0, team AI 0x2ad120, map Repair_Bridge 0x152ef0 all byte-identical)”.

- **C11** OPEN_PATTERNS.md L1015, “G1: cheap breadth lives in the real gaps, not in the unclaimed-symbol lists (2026-11-22, 48 claims in 25 folders agents/g1_*)”.

- **C12** OPEN_PATTERNS.md L1201, “P5: gibbo 721d81e44f port; three stubborn near misses closed by upstream FORMS, none by a gauge (2026-11-23, port agent P5; infantry Per_Cell_Process 0xfffa0, team AI 0x2ad120, map Repair_Bridge 0x152ef0 all byte-identical)”.

- **C13** OPEN_PATTERNS.md L1001, “F26: sibling return tails form a small discrete state set chosen by the local symbol count mod 8; identical machine tails can stay unmerged (2026-11-22, building Fire_Coord 0x4e720 / Draw_Extras / Do_MISSION_MISSILE, not matched)” · OPEN_PATTERNS.md L1060, “F30: which sibling return tail survives a cross-jump follows the SOURCE ORDER of the returns; a short tail merges only when it is source-first (2026-11-22, building Fire_Coord 0x4e720 / Do_MISSION_MISSILE, not matched)”.

- **C14** OPEN_PATTERNS.md L939, “F19: a "spilled result variable + constant returns" picture is `break` to ONE return after the switch (2026-11-22, hover While_Moving 0xfc0c0, 2555 -> 65 bytes, not matched)” · OPEN_PATTERNS.md L984, “F23b: a spilled scalar that shares the slot of a class temporary read just before it is a PARAMETER of an inline whose `const &` argument made that temporary (2026-11-22, hover While_Moving 0xfc0c0 matched)”.

- **C15** OPEN_PATTERNS.md L339, “Lessons from gibbo101/ra2-decomp docs/AGENTS.md (@719fcc7, 2026-11-22; credited in SOURCES_CREDITS.md)” · OPEN_PATTERNS.md L946, “F20: the named-local count lever is a symbol-index THRESHOLD per inlined copy, not a hash (2026-11-22, sidebar Activate 0x2739b0 byte-identical; Reposition_Sidebar 0x2770d0 at 1 byte, not matched)”.

- **C16** OPEN_PATTERNS.md L1216, “M1: meastes/redalert2-decomp (RA2 1.006, VC6) as a port source; pairing by order anchors; one inline level less sets a sum's operand order (2026-11-23, port agent M1; ionblast AI 0x120880 byte-identical, one binding open)”.

- **C17** OPEN_PATTERNS.md L502, “Out-of-line template COMDATs and walk-decrement forms (2026-11-22, B2 map)”.

- **C18** OPEN_PATTERNS.md L303, “level2_remap_inits.py and identical atexit destructors (2026-11-22)” · OPEN_PATTERNS.md L1276, “Wrong symbol-map entries can hide wrong source (P9 link check, 2026-11-23)” · REMATCH.md § Label audit.

## Victims

- **V1** OPEN_PATTERNS.md L1260, “Victim rule (coordinator, 2026-11-23)” · OPEN_PATTERNS.md L1263, “Victim rule confirmed (Codex batch 27, 2026-11-23)”.

- **V2** OPEN_PATTERNS.md L229, “KEY: VC6 symbol numbering and allocation order (2026-11-21)” · OPEN_PATTERNS.md L1263, “Victim rule confirmed (Codex batch 27, 2026-11-23)”.

- **V3** OPEN_PATTERNS.md L374, “Checker: SEH evidence (2026-11-22, WinMain)” · OPEN_PATTERNS.md L1263, “Victim rule confirmed (Codex batch 27, 2026-11-23)” · OPEN_PATTERNS.md L1266, “C2.DLL 8168 rules (Codex batch 32, 2026-11-23): evaluation”.

- **V4** OPEN_PATTERNS.md L845, “F14 notes (2026-11-22, queue Print_CRCs 0x221b90 hash order: mechanism and the package that keeps it)” · OPEN_PATTERNS.md L1140, “H5: queue Print_CRCs has a two-wide declaration window, and today's P sits on its lower edge (2026-11-23, header agent H5, snapshot snapH5)” · OPEN_PATTERNS.md L1260, “Victim rule (coordinator, 2026-11-23)”.

## Steering policy

- **S1** OPEN_PATTERNS.md L1209, “Synthesis of the P5 ports (2026-11-23, coordinator)” · REMATCH.md § Accepted kind-1 matches ·  TASK.md § Steering policy (primary).

- **S2** OPEN_PATTERNS.md L793, “S1 notes (2026-11-22, tool: W/tools/level2_mutate.py, automatic statement mutator + probe minimizer)” · TASK.md § Steering policy (primary) ·  REMATCH.md § Accepted kind-1 matches (comparison only).

- **S3** OPEN_PATTERNS.md L1060, “F30: which sibling return tail survives a cross-jump follows the SOURCE ORDER of the returns; a short tail merges only when it is source-first (2026-11-22, building Fire_Coord 0x4e720 / Do_MISSION_MISSILE, not matched)” · OPEN_PATTERNS.md L1266, “C2.DLL 8168 rules (Codex batch 32, 2026-11-23): evaluation” · TASK.md § Steering policy (primary).

## Dead ends

- **D1** OPEN_PATTERNS.md L793, “S1 notes (2026-11-22, tool: W/tools/level2_mutate.py, automatic statement mutator + probe minimizer)”.

- **D2** OPEN_PATTERNS.md L1121, “BB1 notes (2026-11-23, ownrdraw big blocks: Slide_Dialog 0x1dd5e0 and Default_Dialog_Proc 0x1f77c0, neither matched)”.

- **D3** OPEN_PATTERNS.md L977, “F24: a "1-byte operand order" near miss can be two swapped LOADS; check the masked addends (2026-11-22, sidebar Reposition_Sidebar 0x2770d0 and ownrdraw Adjust_Control_Position 0x1e1760, neither matched)”.

- **D4** OPEN_PATTERNS.md L900, “F17 weight-only constructs: none found; VC6 takes its reference count AFTER every no-code reference is gone (2026-11-22, catalogue + harness, no match)” · OPEN_PATTERNS.md L1209, “Synthesis of the P5 ports (2026-11-23, coordinator)”.

## Where to find more

- **R1** OPEN_PATTERNS.md L1209, “Synthesis of the P5 ports (2026-11-23, coordinator)” · OPEN_PATTERNS.md L1216, “M1: meastes/redalert2-decomp (RA2 1.006, VC6) as a port source; pairing by order anchors; one inline level less sets a sum's operand order (2026-11-23, port agent M1; ionblast AI 0x120880 byte-identical, one binding open)”.

- **R2** OPEN_PATTERNS.md L142, “KEY: VC6 stack-slot assignment (2026-11-21)” · OPEN_PATTERNS.md L946, “F20: the named-local count lever is a symbol-index THRESHOLD per inlined copy, not a hash (2026-11-22, sidebar Activate 0x2739b0 byte-identical; Reposition_Sidebar 0x2770d0 at 1 byte, not matched)” · OPEN_PATTERNS.md L1266, “C2.DLL 8168 rules (Codex batch 32, 2026-11-23): evaluation”.

- **R3** OPEN_PATTERNS.md L1263, “Victim rule confirmed (Codex batch 27, 2026-11-23)” · OPEN_PATTERNS.md L1276, “Wrong symbol-map entries can hide wrong source (P9 link check, 2026-11-23)” · REMATCH.md § Label audit.

## Later findings retained

P5 supersedes the F10 type-level explanation for TeamClass::AI. The missing unit came from the inlined callee. F30 revises F26: textual return order determines the merge topology and the local-count residue affects allocation. P6 narrows H5: a header-body change can disturb the hash when it introduces named locals. Batch 27 supersedes the earlier advice to park SelectClass::Action for final tuning in the tested CountryName configuration. Batch 32 supports measured inline thresholds while leaving a general caller-budget formula unresolved.

TASK.md supplies the names “skeleton/chunk” and “triangulation”. W2 and W3 condense the concrete procedures evidenced in BB1, BB2 and M1. TASK.md also supplies the kind-2 and kind-3 decisions. REMATCH.md names accepted kind-1 examples only.
