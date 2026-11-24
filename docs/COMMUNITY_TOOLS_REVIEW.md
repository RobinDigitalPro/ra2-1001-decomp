# Community tools review

Procedure: AGENTS.md "Community tools: review, then use (2026-11-22)". One section per review agent; append only.

## gibbo101 matching tools (T1)

Reviewer: agent T1, 2026-11-22. Checkout: W/analysis/references_gpl_20261118/gibbo101_ra2-decomp @ bd6bc6671116658b949e288fea05074d49a7df01 (provenance.json). Nothing was executed inside the checkout. No upstream file was copied to W/tools/community, because the adopted tools are adapted rewrites that import no upstream code.

Read completely: flipsweep, inlinebudget, inlineprobe, declprobe, stackslots, localprobe, permute, similar, callees, crosscheck, emitted, functions, check, coff, checkall, ctx, compid, plus the imports exeindex, exebuild and rtti, and test_flipsweep / test_inlinebudget. permute_mutate.py (3822 lines) was not read line by line, because it is not adopted. It was reviewed by its header, licence, full import list, a scan of every identifier that can touch files, processes or the network, and its mutation catalogue. savedobj, tier0, reference_baseline, xmanifest and wcl/wml (imported by emitted, checkall, crosscheck and check) are T2's scope; only their imports were scanned.

Common facts:
- All tools target YR gamemd.exe through `uv run`, wine (tools/wcl, tools/wml) and their own data/*.csv. None uses the network directly, none reads credentials or tokens, none installs anything.
- Concern 1: `uv run` can resolve and DOWNLOAD Python packages. It is used by the subprocess calls in inlineprobe, declprobe and localprobe, and permute.py has a PEP 723 dependency header. We never use uv; the adapted versions call our VC6 CL.EXE directly.
- Concern 2: declprobe.py edits SRC (or a header via --into) IN PLACE and restores it in a `finally`. A hard kill leaves probes in the tracked file. Not acceptable for P.
- Upstream compile flags (check.py FLAGS): `/c /O2 /Ob2 /Gr /GR /MT /DWIN32`, with no /Gy and no /DNDEBUG; their include/ never mentions NDEBUG. Ours: `-O2 -Ob2 -Gr -GR -DNDEBUG -Gy`. Keep this in mind before transferring an assert-based observation from their notes.
- permute.py and permute_mutate.py are MIT (Byte Tactics, Copyright 2026 Hector Bailey), adapted by gibbo101. The rest is GPL-3.0-or-later.

| tool | purpose | safety verdict and reasons | useful for us | route |
|---|---|---|---|---|
| flipsweep.py | k = 0..K copies of one probe statement (dead local, extern store, folded inline call, dead expression, free statement) at one place; a letter per differing-line set; the flip point; a second kind as a grid; probe declarations present at every k | SAFE: compiles via check.compile_source and writes only build/flipsweep (its own probe copy and objects, unlinked at the end); no network, git or installs | HIGH: a one-run threshold finder for F25/F26/F27/P3-type count effects | ADAPTED: W/tools/level2_flipsweep.py |
| inlinebudget.py | lines up the exe's and our out-of-line calls, finds the differing inline decisions, ties each to a statement through the /FAcs listing, and measures the slack (trivial inline calls after / spend probes before / calls at callee ends; or calls before for "ours calls") | SAFE: as flipsweep, plus exeindex (reads the exe and csv); deletes only its own .asm/.obj in build/inlinebudget | HIGH: per-site slack is the missing companion of symgauge/varsearch for inline-budget near misses | ADAPTED: W/tools/level2_inlinebudget.py |
| inlineprobe.py | N unused trivial-inline calls at the start/end of the target and of its TU callees; prints the score and the differing call lines | SAFE in itself (writes build/inlineprobe, unlinks its copy), but shells out to `uv run tools/check.py` (Concern 1) | MEDIUM; superseded by inlinebudget | helpers (body_span, insertion, callee_spans, helper()) ported into the two adapted tools; not used standalone |
| declprobe.py | sweeps unused declarations of one kind (weights 0/1/2/3/8 per kind) before or after a function, with an MD5 fingerprint per diff | edits SRC/header IN PLACE (Concern 2) and uses `uv run` | LOW-MEDIUM: our level2_symgauge.py already sweeps declaration kinds on scratch copies (our measured units 1/2/3/9, period 64); their weight table is a cross-check | NOT USED |
| stackslots.py | names our locals from the /FAcs listing (`_name$[esp]`) and reports per-local frame-offset differences against retail, tracking ESP through calls (callee cleanup from `ret N`) | SAFE: compiles into a tempfile dir under build/; read-only otherwise | MEDIUM: overlaps level2_slotmap/framemap; its callee-cleanup ESP tracking and listing-name join are worth porting later | NOT USED now (lead) |
| localprobe.py | n = 0..15 dead initialised int locals at the body start | SAFE except for `uv run` (Concern 1) | already covered by our level2_localprobe.py (varsearch spec) and level2_flipsweep --kind local | NOT USED |
| permute.py | parallel hill climb over meaning-preserving rewrites; decomp-permuter style score (reg 5, operand 10, move 60, ins/del 100, byte 2, slot 0.01); /Zd line focus; cleanup pass; guards for matched neighbours | SAFE locally: ProcessPoolExecutor and os.nice; writes <src>.best.cpp/.json next to its input (refuses src/include) and build/permute logs; rmtree only of its own header dirs; MIT | MEDIUM: needs tree-sitter, which is not installed (no installs allowed); our level2_mutate.py (S1) is the counterpart. Ideas: the score weights, the guard set, the /Zd hot-line focus | NOT USED |
| permute_mutate.py | 40 tree-sitter rewrites (move_stmt, move_decl, decl_scope, swap_commutative, flip_compare, negate_if, loop_form, temp_intro/inline, compound_assign, incdec, do_while0, ternary, nested_if, zero_compare, cast, sign, copy_to_ptr, ptr_to_copy, return_var, extract_helper, inline_helper, subscript_form, ...) | SAFE: a pure text transform; imports only random, re, dataclasses and tree_sitter; no file, process or network use | MEDIUM as a catalogue for level2_mutate; not runnable here | NOT USED |
| similar.py | ranks matched functions against a target by mnemonic 4-gram / callee / data-ref Jaccard | SAFE: reads the exe and csv, writes build/similar_cache.json | MEDIUM: a "start from this sibling" finder over our claims | NOT USED now (candidate adapter) |
| callees.py | a function's out-of-line callees with match state and source line; its callers | SAFE: read-only | LOW-MEDIUM | NOT USED |
| crosscheck.py | ra2-decomp MATCH rows against gagarin's manifest; writes data/crosscheck/* | SAFE: runs the external `llvm-undname-18` (local) and reads reference/gagarin; YR-specific | LOW | NOT USED |
| emitted.py | lists unrecorded functions already emitted byte-identically in their owning module | SAFE: read-only (imports savedobj/tier0, T2 scope; tier0 itself runs check.py subprocesses) | covered by our level2_unclaimed_scan.py (B11/B15/B18) | NOT USED |
| functions.py | builds the function map with evidence letters P/C/V/Y/G/L/A/F (padding, call, data pointer, YRpp, Ghidra, library, archived asm, unreachable aligned code) | SAFE: writes data/functions.csv or a given path; assembles archive .asm with MASM into a tempdir under build/ | MEDIUM-HIGH idea: our function_map next-start sizes are often bogus (G1; here E107 0x1d7450 has a map size of 290 against a real 369) | NOT USED now (recommended adapter later) |
| check.py | their checker: annotations, relocation-target proofs, RTTI vtable-class checks, normalised diff | SAFE: compiles through wcl (wine); rmtree only of build/hdr/<own tag>; its FORBIDDEN rule refuses __asm/_emit/#pragma optimize/code_seg | reference only: our level2_check.py is canonical. The RTTI "stores another class's vftable" check and encoding_diff are ideas | NOT USED (logic re-expressed in the adapted tools) |
| coff.py | COFF reader | SAFE: a pure parser | equivalent to our coffmatch.Obj | NOT USED |
| checkall.py | merge gate over all of src/; --record rewrites data/progress.csv; --baseline reads a commit's table with `git rev-parse`/`git show` | SAFE: read-only git, subprocess check.py; writes only its progress table | LOW (YR gate) | NOT USED |
| ctx.py | everything about one exe function: disassembly with names, callers, YRpp lines, TS file | SAFE: read-only | LOW (Ghidra and our tools cover it) | NOT USED |
| compid.py | prints the @comp.id product/build of a COFF object | SAFE: pure, 30 lines | LOW-MEDIUM: a quick check that our objects carry 12.00.8168 | NOT USED (trivial to re-implement if needed) |
| exeindex.py / exebuild.py / rtti.py (imports) | exe extents, names and calls; YR build identification and patch restore; RTTI vtable discovery | SAFE: read-only parsers | rtti.py's COL/vtable walk could cross-check rtti_catalog.json | NOT USED |

Nothing malicious or hidden was found: no obfuscated code, no encoded payloads, no network or credential access, and no git push or hooks in these files.

Adopted (adapted rewrites, with a GPL-3.0-or-later credit in each docstring):
- W/tools/level2_flipsweep.py <- tools/flipsweep.py + the tools/inlineprobe.py helpers @ bd6bc66711 (upstream sha256 e66ff596aa3c83c02f6fe48442c6599b12e595623a8659db546fd859f7e81702 and 3b3197086338e0bc2b21d22e98ebbed1a1c38701c82044b93e0a78d8fa9fa249).
- W/tools/level2_inlinebudget.py <- tools/inlinebudget.py @ bd6bc66711 (sha256 452701542810033f576e1b68c093c70d7c4816ab5d1053ac291e9a219ee38c5b); it imports level2_flipsweep.
- Differences from upstream:
  - The target is located by a unique --anchor text instead of `// FUNCTION: GAMEMD` markers. Probe declarations go above the anchor line (or --decl-at).
  - Scoring goes through coffmatch.match_function on GAME.EXE 1.001: status, byte differences, masked hunks and the differing-line multiset.
  - Our calls are keyed by relocation symbol -> VA, from level2_symbols.json plus the level-2 claims.
  - A call of the function's own start counts as a recursion on both sides. Without this, self-calls looked like inline decisions.
  - --body-anchor handles synthetic _$E targets whose site sits in an inline destructor.
  - The scratch folder must lie outside P; the tools refuse otherwise.
  - Variants compile in parallel with --jobs (default 2).
- The upstream unit-test expectations (test_flipsweep / test_inlinebudget: positions, insert_all, letters, copies, differing, pairing, listing_lines, statement_end) hold for the adapted helpers. This was checked with our own copy of the assertions, not by running the upstream tests.

Proofs (scratch outputs: W/analysis/level2/agents/t1_tools/):
- flipsweep on building Fire_Coord 0x4e720, kind local at the body start, k = 0..16: letters 0A 1B 2C 3C 4C 5C 6D 7C 8A 9B 10C 11C 12C 13C 14D 15D 16A.
  - The current 17-byte state recurs at k = 0, 8 and 16 (period 8), and four states exist (17 bytes at the same size; sizes 411, 491, and 491 with extra hunks). This reproduces F26.
  - The sequence is not strictly periodic (k = 7 gives C, k = 15 gives D), consistent with F26's "hash-like".
- inlinebudget discovery: queue Extract_Compressed_Events 0x21fa40 and mech Movement_AI 0x18e7a0 have NO differing inline decisions in the current P source (8/8 and 63/63 calls line up). Their near misses are therefore not inline-budget cases.
- inlinebudget on ownrdraw _$E107 0x1d7450 (B21's open case) finds exactly B21's decision: ??_GWideWstring 0x5f90e0, which 1.001 calls and ours inlines.
  - With --body-anchor ~WinData and --site-line 571 (`delete WideText;`), 2 trivial inline calls after that statement flip the decision, with no other decision left.
  - Spend probes of 2 units flip it at j = 2 (slack 2..4 units). Spend probes of 8 units do not expand at all.
  - flipsweep --kind call --at "after:delete WideText" confirms: k = 0..1 give 272 differing bytes, k >= 2 is byte-identical over our 369 bytes. This is diagnostic only; probes are never source.
  - This is consistent with B21's gauges (3 dead getSize(); about 15 asserts in clear; 5..8 asserts in ~WinData).

## Other community tools (T2)

Reviewer: agent T2, 2026-11-22. Checkouts under W/analysis/references_gpl_20261118: gibbo101_ra2-decomp @ bd6bc6671116658b949e288fea05074d49a7df01, mischa85_RedAlert2 @ 8f715e2685918028a093a57998fb567f11826eec, opents_TibSun, vinifera_TSpp, ea_CnC_Renegade, ea_CnC_Red_Alert. Nothing was executed inside a checkout. Only the adapted tools in W/tools ran, with their outputs under W/analysis/level2/agents/t2_tools.

Licence note: the upstream gibbo101 LICENSE puts everything outside src/ and include/ under MIT. tools/exelink states MIT and is ported from r-melvin/gagarin. None of the T2-scope tool files carries a GPL SPDX header. MIT is compatible with our GPL-3.0-or-later tree.

How the files were read:
- Read completely: headercheck, header_inputs, savedobj, adopt_header, landing_inputs, reference_baseline, manifest, gamecode, rtti, libmatch, library_identified, assembly_anchors, yrpp_layouts, yrpp_symbols, yrppnames, exeindex, exebuild, refaudit, xmanifest, build_receipt, agentcost, attempt, bytematch_report, wcl, exelink/crt_ident, coord/vtowner, coord/vtname, coord/stale, coord/land.sh, coord/landscan.sh, coord/README, ghidra/ExportFunctions.java, hooks/*, and from mischa85 build.py, compile.py, references.py and hooks/*. The wlib/wlink/wml files contain only the text "wcl".
- Read in part:
  - modules.py: header doc, constants, initialiser_statics, module_starts, file_anchors, rtti_virtuals, vtable_slots, the function list and every file write.
  - tier0.py: header doc, function list, and every subprocess, write and unlink site.
  - mischa85 configure.py: header doc, function list, and its rmtree and write sites.
- Screened only, by docstring plus a scan of every identifier that touches processes, files or the network; none is adopted:
  - the other coord/ scripts;
  - the other exelink/ modules (docstrings and imports of all of them; crt_ident was read in full);
  - the test_*.py files.
- A screened file must be read completely before anyone runs or adapts it.

| tool | purpose | safety verdict and reasons | useful for us | route |
|---|---|---|---|---|
| exelink/crt_ident.py (+ libmatch.py import check) | places every code SECTION of LIBCMT/COMSUPP/LIBCPMT in the CRT tail. A section with one masked match is placed first; the rest are resolved by contiguity with placed sections of the same member, then by members already placed, then by section order of identical siblings. What is left is split into padding, import thunks and unmatched bytes | SAFE: reads the exe and the .LIB files, writes one JSON under build/exelink; no network, no deletes | HIGH: our crt_calibrate.py takes only unique bodies of >= 16 bytes; this resolves the small and the duplicated ones | ADAPTED: W/tools/level2_libident.py, plus the IAT-slot agreement from libmatch. Proof below |
| libmatch.py | whole-.text library search: IAT-name agreement for __imp__ fields, local-call anchoring of ambiguous hits, import-thunk runs named from the import libraries; merges library_identified.json | SAFE: read-only except data/library.csv | MEDIUM: the IAT check is now in level2_libident; thunk naming could later name the 362 thunks | PARTLY ADAPTED (into level2_libident) |
| library_identified.py | proves small library identities by full relocation linking: incoming references, globals, RTTI deleting-dtor chains, complete object blocks with >= 4 anchors, data tables | SAFE (read-only); needs check.py's ref_checks and their name tables | MEDIUM-HIGH later: it is the step that turns level2_libident candidates into bound evidence | LEAD: port the object-block and RTTI rules when the library entries get relocation binding |
| header_inputs.py | conservative include closure per TU: every branch, every file with the same basename, SDK included; unknown syntax gives the whole-tree key | SAFE: pure parsing | HIGH: an hdrlab variant can build only the TUs that can see a header, and the per-TU input keys allow object reuse | ADAPTED: W/tools/level2_hdrimpact.py. Proof below |
| build_receipt.py + savedobj.py | cold gate capture/recheck: reuses a verified .obj when its header-closure key, flags and environment agree; sha256 receipt per object | SAFE (writes build/gates only); needs check/checkall | MEDIUM: level2_hdrimpact --keys covers the caching idea; hdrcheck could reuse snapshot objects for unaffected TUs | IDEA: keys implemented, reuse not yet wired into level2_hdrcheck |
| headercheck.py | builds a probe TU (private -> public, an offsetof that operator& cannot intercept, a derived probe class that makes the compiler emit the vtables). It gets sizeof, member offsets and vtable slots, and compares them with YRpp layouts.csv and the exe's RTTI vtables (slot count, pure, inherited/overridden, known addresses) | SAFE: compiles into build/headercheck/<hash> and removes only that directory | HIGH for the vtable half, which is 1.001 binary evidence; the YRpp half is YR, not 1.001 evidence | ADAPTED without YRpp: W/tools/level2_classcheck.py. Proof below |
| modules.py | assigns functions to modules from __FILE__ anchors, static-initialiser header markers, alphabetical link order and OpenTS/YRpp/TibSun evidence | SAFE: read-only, writes data/modules.csv | file_anchors() is HIGH and cheap; the rest is YR-specific (marker byte patterns, the ATEXIT address, OpenTS lists) | ADAPTED file_anchors: W/tools/level2_fileanchors.py. Initialiser-marker segmentation is a LEAD (gameconst_blocks and level2_fix_misnamed already do part of it) |
| rtti.py | RTTI walk: complete object locators, base sets, vtables, slot owner, class of a decorated symbol, virtual verdict, deleting-dtor detection | SAFE (needs capstone) | MEDIUM: rtti_catalog.json already holds this; the owner() and virtual_verdict rules could cross-check claims | NOT USED (idea for a claim audit) |
| coord/vtowner.py, vtname.py | which vtables hold an address; the RTTI name of a vtable | SAFE; vtname exec()s vtowner's source text (a style issue only) | LOW: rtti_catalog and level2_classcheck cover this | NOT USED |
| refaudit.py | ranks unverified relocation symbols by how many TUs bind them to one address | SAFE (read-only) | MEDIUM: a corroboration ranking for level2_autobind proposals | LEAD |
| mischa85 references.py | pairs every relocation symbol of matched code with its target address; each name must have one address and each address one name | SAFE, except that it compiles through Wine (and deletes only its own failed .obj) | MEDIUM: the same consistency audit is a cheap check over our check reports | LEAD (no copy) |
| mischa85 build.py | writes every matched compiled function into a copy of the exe and requires the original SHA-256 | SAFE (writes build/VERSION/game.exe) | LOW now: level2_check already proves each body; relevant for a final whole-image check | NOT USED |
| mischa85 compile.py, configure.py | Wine CL driver; objdiff target objects and objdiff.json | SAFE (configure rmtree's only its own build/VERSION/target) | LOW: we do not use objdiff | NOT USED |
| exelink/ (link, stubgen, pindata, hybrid, datasource, rttimap, taillink, tail_layout, mapcheck, compare_image, verify_vtable, verify_relocations, coffgen, comdatize, implib, link_diag, coff_equivalence) | whole-executable link with LINK 6 /ORDER at the original addresses, giving stub, hybrid and source-data images and a section comparison | SAFE by design (writes only build/exelink and refuses --out elsewhere), but runs LINK through Wine | HIGH for the end phase (checks that every claim still sits at its address when everything is linked), not now | LEAD for the end phase; review completely before use |
| tier0.py | compiles TibSun sources, finds byte-identical functions, writes them INTO src/ and keeps them only when check.py prints MATCH | NOT ACCEPTABLE as-is: it writes and unlinks tracked source files, which would touch P | level2_port_match and level2_unclaimed_scan cover the idea | NOT USED |
| attempt.py | saves and replays a candidate as a git diff with pinned input hashes | NOT USED: runs `git diff/apply` and pins a git commit; our W tree has no git route | LOW | NOT USED |
| xmanifest.py, manifest.py, gamecode.py, bytematch_report.py, yrppnames.py | cross-project manifest (raw and reloc-zeroed hashes per match); progress and report tables | SAFE (read-only; they write their own data/ or build/ files) | LOW-MEDIUM: a reloc-zeroed hash per matched function would make our claims comparable with gibbo's manifest | IDEA |
| yrpp_layouts.py, yrpp_symbols.py | clang record-layout dump and address extraction from the YRpp headers | yrpp_layouts needs clang and the MinGW headers, which are not installed (it rmtree's only its own build/layouts) | NOT USEFUL: YR layouts and addresses are not 1.001 evidence | NOT USED |
| adopt_header.py | copies TibSun headers into include/ with a licence header and the comments stripped | SAFE | LOW: header adoption is already done by hand, with provenance | NOT USED |
| assembly_anchors.py, landing_inputs.py, reference_baseline.py, exebuild.py, exeindex.py, agentcost.py | asm data bindings from two agreeing C++ anchors; a git-HEAD input fingerprint; a relocation baseline; YR build identification; an exe index; agent token costs | SAFE (landing_inputs runs only `git rev-parse`) | LOW; assembly_anchors' rule of two independent agreeing anchors is a good evidence rule for data bindings | NOT USED |
| coord/ (claims, land, landing_gate, tally, comments, mkround, mknear, choices, attempts_rows, stale, batchT.js, nearT.js, ...) | round coordination for their agent workflows | EXCLUDED: claims.py calls `gh` (GitHub, network); land, tally, comments and landing_inputs run git; stale.py deletes files; attempts_rows uses POSIX fcntl | LOW: choices.py, a bounded product of explicit source alternatives, overlaps level2_varsearch and level2_mutate | EXCLUDED |
| wcl/wlib/wlink/wml, setup_toolchain.sh, wineenv.sh, ghidra.sh | Wine wrappers and the toolchain download | EXCLUDED (downloads, Wine) | - | EXCLUDED |
| hooks/ (gibbo: commit-msg, pre-commit, pre-push, guard.sh, tool-tests.sh; mischa85: pre-commit, pre-push) | git hooks | EXCLUDED; the mischa85 pre-push hook uploads a report to bytematch.dev with a token (network and a credential) | - | EXCLUDED |
| ghidra/ExportFunctions.java | Ghidra script that writes a function CSV | SAFE | LOW: our function index already exists | NOT USED |
| opents_TibSun | only code/ (sources, .hh, .rc, .cur, .ico); no tools or scripts | - | source reference only | - |
| vinifera_TSpp | cmake/modules (GitWatcher.cmake runs git; GlobUtil, ProjectFilters); edb/GAME.EDB (a text database of exception addresses); pdb/GAME.pdb (TS symbols made with FakePDB) | GitWatcher EXCLUDED (git); the rest is data | the TS PDB is a naming lead for code shared with TS (TS addresses, not 1.001 evidence) | NOT USED |
| ea_CnC_Renegade | Code/Tools holds C++ editor and viewer projects (W3DView, LevelEdit, ...), not analysis scripts; wolapi/register.bat registers a COM DLL (a system change) | register.bat EXCLUDED | none for the pipeline | NOT USED |
| ea_CnC_Red_Alert/TOOLS | old DOS .EXE binaries (ANIMATE, AUDIOMAK, MIXFILE, ...), plus Borland/Watcom makefiles across CODE/IPX/WIN32LIB | EXCLUDED: binaries are not reviewable, and the DOS makefiles do not apply | - | EXCLUDED |

Proofs (outputs in W/analysis/level2/agents/t2_tools):
- level2_libident.py (libident.json, 18 s):
  - It placed 578 of the 2356 library code sections (85847 bytes) in the CRT tail 0x36d5cc..0x384ecd. All 527 level2_library.json entries lie inside placed sections, with no conflict and none missed.
  - 133 sections are NEW: 5012 bytes, +6.2% library bytes; 117 of them were placed without order inference. Examples:
    - small CRT bodies such as type_info::raw_name, operator delete, __fpclear and the iswXXX family;
    - duplicated bodies placed by member contiguity: memcpy/memmove (821 bytes each) and the output/woutput _write_multi_char.
  - None overlaps a level2 claim. 9939 tail bytes stay unmatched.
  - Limits: this is candidate evidence only. Relocation targets are not bound, and the NAME of a byte-identical twin (memcpy vs memmove) comes from contiguity, not from proof.
- level2_hdrimpact.py (hdrimpact_*.json/txt, 3 s):
  - face.h reaches 195 of the 638 claimed TUs; velocity.h reaches 18.
  - Ground truth with the VC6 preprocessor (pp_check.py/txt) agrees: missile.cpp opens velocity.h and face.h and is listed for both. ownrdraw.cpp and power.cpp open face.h but not velocity.h, and are listed for face.h only. cdfile.cpp opens neither and is listed for neither.
  - `--keys` gives 638 dependency keys, none unknown.
- level2_fileanchors.py (fileanchors.json/txt, 72 s):
  - 73 path strings are referenced from code; 452 functions are anchored.
  - 20 claims disagree with their anchor:
    - 16 are wwmouse.cpp against wwmous.cpp (the m85 file name);
    - MPSiege and STLScore are already in TU_REATTRIBUTION;
    - wdtconflict 0x31c9b0 has a wdtgameoptions.h anchor (a header inline);
    - nullconn.cpp 0x1c6360 has a NullDlg.CPP anchor, a new re-attribution lead.
  - 21 anchored functions in 14 files are unclaimed, among them wonline (5), UICmnds (3), PlanMgr (2), Tactical Render 0x299be0, Sidebar, Dropship and Egos Show_Credits 0xb34d0.
- level2_classcheck.py (classcheck/AbstractTypeClass.json/txt):
  - sizeof is 152; the members are IniName +0x24, UINameLabel +0x3D, UIName +0x60 and GivenName +0x64.
  - The primary vtable has 27 slots in both ours and the exe, and the 3 secondary vtables (6/1/1 slots) agree. Pure and inherited/overridden status agree in 26 slots.
  - One FAIL, at slot 24, which is `ret 4` at 0x109a0:
    - our claims name 0x109a0 AbstractTypeClass::Load_Theater_Art (src/ra2/AbsType.cpp);
    - abstype.h puts Init_Theater in slot 24;
    - houstype.cpp claims Init_Theater at 0xf9330, a byte-identical `ret 4`.
  - This is a naming/placement lead of the G1 "check thunk families against their vtable" kind, not yet resolved.

## exelink (gibbo101 @308c005, MIT), 2026-11-23

- Codex reviewed the upstream exelink files completely and adapted a stub link + mapcheck as level2_exelink (job 85e0d2d0, REVIEW.md in jobs/exelink_out/result).
- **Upstream verdicts:**
  - SAFE: coffgen, mapcheck, compare_image, crt_ident, datasource, hybrid, coff_equivalence.
  - UNSAFE as supplied: build.py (removes a staged header tree), link.py and link_diag.py (Wine), and the comdatize CLI (replaces its input).
- **The adapted tool:** 7 files, 1,232 lines; subprocess only to CL, UASM and LINK; deletes only its own build files.
- It ran on the station only. Claude must read it completely before any local run.
- Credit: SOURCES_CREDITS.md (gibbo101 tools are MIT; the upstream README credits r-melvin/gagarin).
