"""Diagnose an i386 VC6 caller from an actual failed native translation unit.

  python -I level2_callee_first.py case.json --kit K --work W > report.json

  {"base":"before/team.cpp","targets":[["?AI@TeamClass@@UAEXXZ","0x2ad120"]],
   "controls":[["?Other@TeamClass@@QAEXXZ","0x1234"]]}

Paths in the spec are relative to it. 'targets' must contain exactly one caller.
Optional: 'reference' is a compatible native TU (for example a proposed repair)
compiled separately; 'objects' lists other failed-build /Gy .obj files to score
external callees; 'bindings' maps exact COFF symbols to original RVAs.
'preset' is m85 (default) or ra2. Override a bad function_map boundary using
'original_size' (unpadded instruction span). --near N sets call proximity in
instructions (default 3). Temporary compiler files stay under W and are removed.

The normal /O2 /Ob2 object supplies all match states. /Od /Ob0 is an observation
probe: a call seen there but absent on the same optimized source line may have
been inlined, folded or removed. Its standalone match is independent of the
inlined copy. The caller comparison masks addresses and branch destinations.
Unresolved binding, missing body, unknown RVA, and exact match are distinct.
Compare the ranked evidence and controls before editing any shared header.
"""
import argparse
from collections import defaultdict
import ctypes
import difflib
import json
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess
import sys
import tempfile


def number(value):
    return int(value, 0) if isinstance(value, str) else int(value)


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8-sig"))


def load_bindings(kit, overrides):
    candidates = defaultdict(set)
    for row in read_json(kit / "meta/level2_functions.json"):
        if row.get("symbol"):
            candidates[row["symbol"]].add(number(row["rva"]))
    for sym, row in read_json(kit / "meta/level2_symbols.json").items():
        if row.get("address"):
            candidates[sym].add(number(row["address"]) - 0x400000)
    known = {name: next(iter(rvas)) for name, rvas in candidates.items() if len(rvas) == 1}
    known.update({name: number(rva) for name, rva in overrides.items()})
    return known


def compile_tu(src, kit, folder, cl, preset, probe):
    label = "noinline" if probe else "optimized"
    folder.mkdir(exist_ok=True)
    obj, listing = folder / (label + ".obj"), folder / (label + ".asm")
    vc = kit / "vc6/VC98"
    env = dict(os.environ, INCLUDE=os.pathsep.join(str(vc / p) for p in ("INCLUDE", "ATL/INCLUDE")),
               TMP=str(folder), TEMP=str(folder))
    flags = ["-Od", "-Ob0"] if probe else ["-O2", "-Ob2"]
    if preset == "m85":
        flags += ["-DWIN32", "-W0", "-I" + str(kit / "m85/src"), "-I" + str(kit / "m85/include")]
    elif preset == "ra2":
        flags += ["-I" + str(kit / "ra2")]
    else:
        raise ValueError("unrecognized preset " + preset)
    run = subprocess.run([str(cl), "-nologo", "-c", *flags, "-Gr", "-GR", "-DNDEBUG", "-Gy",
                          "-FAcs", "-Fa" + str(listing), "-Fo" + str(obj), str(src)],
                         cwd=folder, env=env, capture_output=True, timeout=600)
    if run.returncode:
        raise ValueError(f"{src.name} {label} VC6 exit {run.returncode:#x}: " +
                         (run.stdout + run.stderr).decode("latin-1")[-1500:])
    return Obj(obj.read_bytes()), listing


def resolve_name(obj, needle):
    if needle in obj.symbols:
        return needle
    matches = [s for s in obj.symbols if not needle.startswith("?") and needle in s]
    if len(matches) != 1:
        raise ValueError(f"caller/control {needle!r} resolves to {len(matches)} symbols")
    return matches[0]


def locations(listing, symbol, source):
    """Map offsets to VC6's file and line. The listing also contains literal data."""
    active, filename, line = False, "", None
    out = {}
    native_lines = source.read_text(encoding="latin-1").splitlines()
    site = ("", None)
    for row in listing.read_text(encoding="latin-1").splitlines():
        if row.startswith("; File "):
            filename, line = row[7:].strip(), None
        if row.startswith(symbol + " "):
            if " ENDP" in row:
                break
            active = " PROC " in row
        if not active:
            continue
        line_no = re.match(r";\s*(\d+)\s*:(.*)", row)
        if line_no:
            line = int(line_no[1])
            # /FAcs can retain a previous header's File marker across PROC.
            from_tu = 0 < line <= len(native_lines) and native_lines[line-1].strip() == line_no[2].strip()
            site = (str(source) if from_tu else filename, line)
        opcode = re.match(r"^  ([0-9a-f]{5,8})\t[0-9a-f]{2}\b", row, re.I)
        if opcode and not re.search(r"\t\s*(?:DD|DB|DW|DQ)\s", row, re.I):
            out.setdefault(int(opcode[1], 16), site)
    return out


def direct(obj, symbol, loc):
    """Only E8 REL32 relocations at instruction boundaries are direct calls."""
    sec = obj.function(symbol)
    found = {}
    for off, index, typ in sec["relocs"]:
        if typ == 0x14 and off - 1 in loc and sec["raw"][off - 1] == 0xe8:
            found[off - 1] = obj.by_index[index]["name"]
    return found


def signature(obj, name):
    if name not in obj.symbols:
        return None
    sec = obj.function(name)
    return sec["raw"], [(off, obj.by_index[i]["name"], typ) for off, i, typ in sec["relocs"]]


def inline_sites(objs, lines, edges):
    """Pair a lost source-line call with any calls it exposes on that line."""
    optimized = defaultdict(set)
    for off, sym in edges[0].items():
        optimized[lines[0][off]].add(sym)
    nested = {}
    for off, sym in edges[1].items():
        site = lines[1][off]
        if sym in optimized[site]:
            continue
        if sym not in nested:
            nested[sym] = set()
            if sym in objs[1].symbols:
                sec = objs[1].function(sym)
                _, calls, _ = disassemble(sec["raw"], 0)
                nested[sym] = set(direct(objs[1], sym, calls).values())
        yield sym, site, sorted(nested[sym] & optimized[site])


def match_state(name, objects, rva, known):
    definitions = [o for o in objects if name in o.symbols]
    if not definitions:
        return {"status": "no_body_in_supplied_objects"}
    if rva is None:
        return {"status": "emitted_rva_unknown"}
    def address(sym):
        return 0x400000 + known[sym] if sym in known else None
    states = []
    for obj in definitions:
        size = len(obj.function(name)["raw"])
        original = l2match.orig(rva, size)
        if original is None:
            raise ValueError(f"RVA {rva:#x} outside the original image")
        m = match_function(obj, name, original, 0x400000 + rva, address)
        states.append({"status": m["status"], "size": size, "byte_differences": m.get("byte_differences"),
                       "open_bindings": len(m.get("unresolved_bindings", [])),
                       "binding_problems": len(m.get("relocation_problems", []))})
    if any(s != states[0] for s in states):
        return {"status": "conflicting_object_bodies", "alternatives": states}
    return states[0]


def disassemble(raw, at, relocs=(), locations=None):
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    image_end = 0x400000 + struct.unpack_from("<I", l2match.B, l2match.pe + 24 + 56)[0]
    seq, direct_calls, decoded_end = [], {}, 0
    for ins in md.disasm(raw, at):
        off = ins.address - at
        decoded_end = off + ins.size
        if locations is not None and off not in locations:
            continue
        if ins.mnemonic in ("nop", "int3"):
            continue
        ops = []
        for operand in ins.operands:
            typ = operand.type
            if typ == capstone.CS_OP_MEM:
                m = operand.mem
                disp = m.disp & 0xffffffff
                if off + ins.disp_offset in relocs or 0x400000 <= disp < image_end:
                    disp = "addr"
                ops.append(("mem", m.segment, m.base, m.index, m.scale, disp, operand.size))
            elif typ == capstone.CS_OP_IMM:
                val = operand.imm & 0xffffffff
                if ins.mnemonic == "call" and ins.bytes[0] == 0xe8:
                    direct_calls[off] = val
                if ins.group(capstone.CS_GRP_JUMP) or ins.group(capstone.CS_GRP_CALL):
                    val = "target"
                elif off + ins.imm_offset in relocs or 0x400000 <= val < image_end:
                    val = "addr"
                ops.append(("imm", val))
            elif typ == capstone.CS_OP_REG:
                ops.append(("reg", operand.reg))
            else:
                ops.append(("other", ins.op_str))
        seq.append((off, (ins.mnemonic, tuple(ops))))
    return seq, direct_calls, decoded_end


def diff_evidence(native, original, near):
    a = [x[1] for x in native]
    b = [x[1] for x in original]
    call_ix = {i for i, token in enumerate(a) if token[0] == "call"}
    ref_ix = {i for i, token in enumerate(b) if token[0] == "call"}
    changed, hunks = set(), []
    for tag, i, j, k, l in difflib.SequenceMatcher(None, a, b, autojunk=False).get_opcodes():
        if tag == "equal":
            continue
        # At an insertion/deletion use the neighboring instruction on the empty side.
        # Every changed instruction must be near a call; one call inside a big hunk
        # is insufficient to classify the entire caller as call-local.
        ranges = [(range(i, j), call_ix), (range(k, l), ref_ix)]
        local = all(any(abs(pos - c) <= near for c in indices)
                    for positions, indices in ranges for pos in positions)
        end = max(i + 1, j)
        changed.update(offset for offset, _ in native[i:end])
        hunks.append({"native": [hex(native[p][0]) for p in (i, j - 1) if i < j],
                      "original": [hex(original[p][0]) for p in (k, l - 1) if k < l],
                      "near_calls": local})
    return changed, hunks


def run(spec, base_dir, kit, tmp, near):
    if len(spec["targets"]) != 1:
        raise ValueError("supply exactly one caller in targets")
    cl = tmp / "cl.exe"
    for file in ["CL.EXE", "C1.DLL", "C1XX.DLL", "C2.DLL"]:
        shutil.copyfile(kit / "vc6/VC98/BIN" / file, tmp / file.lower())
    shutil.copyfile(kit / "vc6/COMMON/MSDEV98/BIN/MSPDB60.DLL", tmp / "mspdb60.dll")
    known = load_bindings(kit, spec.get("bindings", {}))
    all_objects = [Obj((base_dir / p).read_bytes()) for p in spec.get("objects", [])]
    needle, value = spec["targets"][0]
    rva = number(value)
    variants = {}
    for key in ("base", "reference"):
        if key not in spec:
            continue
        src = base_dir / spec[key]
        objs, lines, edges = [], [], []
        for probe in (False, True):
            obj, listing = compile_tu(src, kit, tmp / key, cl, spec.get("preset", "m85"), probe)
            name = resolve_name(obj, needle)
            loc = locations(listing, name, src)
            if not loc:
                raise ValueError("cannot map caller in VC6 listing: " + name)
            objs.append(obj)
            lines.append(loc)
            edges.append(direct(obj, name, loc))
        variants[key] = (objs, lines, edges)
    (obj, probe), (loc, _), (edges, _) = variants["base"]
    name = resolve_name(obj, needle)
    known[name] = rva
    originals = read_json(kit / "meta/function_map.json")["map"]
    span = spec.get("original_size")
    if span is None:
        item = next((x for x in originals if number(x["rva"]) == rva), None)
        if not item or len(item.get("ranges", [])) != 1 or number(item["ranges"][0][0]) != rva:
            raise ValueError("missing or discontiguous original range; specify original_size")
        span = number(item["ranges"][0][1]) - rva
    span = number(span)
    if span <= 0:
        raise ValueError("original_size must be positive")
    reference_bytes = l2match.orig(rva, span)
    if not reference_bytes or len(reference_bytes) != span:
        raise ValueError("original caller range outside image")
    original, native_calls, original_end = disassemble(reference_bytes, rva)
    sec = obj.function(name)
    native, _, native_end = disassemble(sec["raw"], 0, {x[0] for x in sec["relocs"]}, loc)
    covered = native_end > max(loc) and original_end == len(reference_bytes)
    changed, hunks = diff_evidence(native, original, near)
    rows = {}
    def row(sym):
        return rows.setdefault(sym, {"edges": set(), "native_offsets": [], "original_offsets": [],
                                    "probe_sites": [], "changed_probe_sites": [], "priority": 0, "reason": []})
    states = {}
    reference = variants.get("reference")
    inferred = defaultdict(set)
    for key, (objs, locations_, calls) in variants.items():
        caller_name = resolve_name(objs[0], needle)
        states[key] = match_state(caller_name, [objs[0]], rva, known)
        if states[key]["byte_differences"] == 0:
            for off, sym in calls[0].items():
                # Resolve symbol at a verified E8 site only for a zero-addend call.
                raw = objs[0].function(caller_name)["raw"]
                if off in native_calls and raw[off+1:off+5] == bytes(4):
                    inferred[sym].add(native_calls[off])
    inferred = {s: next(iter(v)) for s, v in inferred.items() if len(v) == 1 and s not in known}
    known.update(inferred)
    names_by_rva = defaultdict(set)
    for s, address in known.items():
        names_by_rva[address].add(s)
    for off, sym in edges.items():
        r = row(sym)
        r["edges"].add("optimized_direct")
        r["native_offsets"].append(hex(off))
    changed_lines = {loc[o] for o in changed if o in loc}
    for sym, site, nested in inline_sites(*variants["base"]):
        r = row(sym)
        r["edges"].add("possible_inline")
        if site not in r["probe_sites"]:
            r["probe_sites"].append(site)
        if site in changed_lines and site not in r["changed_probe_sites"]:
            r["changed_probe_sites"].append(site)
        if nested:
            r.setdefault("optimized_nested_calls_at_site", []).append({"site": site, "calls": nested})
    if reference:
        for sym in reference[2][0].values():
            row(sym)["edges"].add("reference_direct")
        for sym, site, nested in inline_sites(*reference):
            r = row(sym)
            r["edges"].add("reference_possible_inline")
            if nested:
                r.setdefault("reference_nested_calls_at_site", []).append({"site": site, "calls": nested})
    for off, target in native_calls.items():
        aliases = names_by_rva[target]
        linked = aliases.intersection(rows)
        if reference:
            linked |= aliases.intersection(reference[2][0].values())
        # For address aliases without edge evidence retain the ambiguity.
        selected = linked or (aliases if len(aliases) == 1 else {f"RVA_{target:#x}"})
        for sym in selected:
            r = row(sym)
            r["edges"].add("original_direct")
            r["original_offsets"].append(hex(off))
            r["rva"] = hex(target)
            if len(aliases) > 1:
                r["aliases"] = sorted(aliases)
    for sym, r in rows.items():
        address = known.get(sym, number(r["rva"]) if "rva" in r else None)
        r["rva"] = hex(address) if address is not None else None
        r["state"] = ({"status": "symbol_unknown"} if sym.startswith("RVA_") else
                      match_state(sym, [obj, *all_objects], address, known))
        if sym in inferred:
            r["binding_source"] = "aligned_rel32_in_byte_matching_caller"
        if reference:
            ref_obj, ref_probe = reference[0]
            r["reference_state"] = match_state(sym, [ref_obj], address, known)
            changed_probe = sym in probe.symbols and sym in ref_probe.symbols and signature(probe, sym) != signature(ref_probe, sym)
        else:
            changed_probe = False
        def rank(priority, reason):
            r["priority"] = max(r["priority"], priority)
            r["reason"].append(reason)
        if "original_direct" in r["edges"] and "optimized_direct" not in r["edges"]:
            rank(60, "original E8 target has no identified optimized call")
            if reference and sym in reference[2][0].values() and sym not in obj.symbols and sym in ref_obj.symbols:
                rank(95, "reference TU emits and calls the missing body")
        if "possible_inline" in r["edges"]:
            if r["changed_probe_sites"]:
                rank(50, "no-inline call maps to a changed optimized source line")
            if changed_probe:
                rank(80, "same helper's no-inline body changes in the reference TU")
        if "optimized_direct" in r["edges"] and r["state"]["status"] == "mismatch":
            rank(45, "standalone direct callee mismatches")
        r["edges"] = sorted(r["edges"])
        r["symbol"] = sym
    ranked = sorted(rows.values(), key=lambda r: (-r["priority"], r["symbol"]))
    first = [r["symbol"] for r in ranked if r["priority"] and r["priority"] == ranked[0]["priority"]]
    if states["base"]["status"] == "matched":
        first = []
    controls = {}
    for n, addr in spec.get("controls", []):
        controls[n] = {}
        for key, (objs, _, _) in variants.items():
            try:
                ctrl_name = resolve_name(objs[0], n)
            except ValueError as e:
                controls[n][key] = {"status": "unavailable", "detail": str(e)}
                continue
            controls[n][key] = match_state(ctrl_name, [objs[0]], number(addr), known)
    return {"caller": name, "caller_state": states, "controls": controls, "original_span": span,
            "masked_hunks": hunks, "near_instructions": near,
            "coverage": {"original_bytes_decoded": original_end, "native_bytes_decoded": native_end,
                         "last_native_instruction_start": max(loc), "whole_comparison": covered},
            "all_masked_differences_near_calls": all(h["near_calls"] for h in hunks) if covered else None,
            "work_first": first, "callees": ranked}


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("spec", type=Path)
    ap.add_argument("--kit", type=Path, required=True)
    ap.add_argument("--work", type=Path, required=True)
    ap.add_argument("--near", type=int, default=3)
    args = ap.parse_args()
    if args.near < 0:
        ap.error("--near must be nonnegative")
    kit = args.kit.resolve()
    sys.dont_write_bytecode = True
    sys.path[:0] = [str(kit / "tools"), str(kit)]
    global Obj, match_function, l2match, capstone
    from coffmatch import Obj, match_function
    import l2match, capstone
    ctypes.windll.kernel32.SetErrorMode(0x8003)
    args.work.mkdir(parents=True, exist_ok=True)
    try:
        with tempfile.TemporaryDirectory(dir=args.work.resolve()) as tmp:
            out = run(read_json(args.spec), args.spec.resolve().parent, kit, Path(tmp), args.near)
        print(json.dumps(out, indent=2))
    except (ValueError, OSError, KeyError, subprocess.TimeoutExpired) as exc:
        ap.exit(2, f"callee-first: {exc}\n")


if __name__ == "__main__":
    main()
