"""Bidirectional, fixed-control ablation of two C++ translation units with VC6.

Usage: python -I level2_ablate.py spec.json --kit KIT --work WORK
Example spec (source and include paths are relative to the spec):
  {"failed":"failed.cpp", "donor":"best.cpp", "preset":"m85",
   "targets":[["?One_Time@IonBlastClass@@SIXXZ","0x120fd0",544]],
   "controls":[["?Clear_All@IonBlastClass@@SIXXZ","0x1211f0"]],
   "include_dirs":["headers/src","headers/include"]}
The donor may be a passing native adaptation or a near miss. Provide full TUs
with a common header environment. Each [symbol, RVA, optional padded byte size]
uses an exact decorated name or a unique substring. Without size, a contiguous
kit function-map body and up to 15 trailing 90/CC padding bytes are accepted.
Override ambiguous or incomplete map bounds with a verified section size.
Known symbol bindings can be supplied as an optional "bindings" name->VA map.
Otherwise a match establishes size and relocation-masked bytes only.

--context N controls line-diff grouping (default 2, as in the annotated cases).
Every hunk is tested in both directions. Unequal or unavailable gains trigger
both pair directions against every other hunk. All smaller cardinalities are
then searched without pruning. --search-limit N optionally caps extra subset
compiles *after* the mandatory probes; an unproven minimum is labeled as such.
The fresh run directory contains report.json, table.tsv, and matching.cpp if a
match exists. Costs are masked differences + 4 per out-of-range size byte +
known relocation problems, summed over targets, with controls required to pass.
"""
import argparse
import csv
import difflib
import itertools
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile


def number(value):
    return int(value, 0) if isinstance(value, str) else int(value)


def read_lines(path):
    # Keep all bytes except the line endings, including a missing final newline.
    data = path.read_bytes()
    return data.replace(b'\r\n', b'\n').splitlines(keepends=True), b'\r\n' in data


def changes(old, new, context):
    # Trim identical TU prefixes/suffixes before SequenceMatcher sees the body.
    start = 0
    end = min(len(old), len(new))
    while start < end and old[start] == new[start]:
        start += 1
    tail = 0
    while tail < end - start and old[-tail-1] == new[-tail-1]:
        tail += 1
    seq = difflib.SequenceMatcher(None, old[start:len(old)-tail],
                                  new[start:len(new)-tail], autojunk=False)
    groups = []
    for group in seq.get_grouped_opcodes(context):
        edits = [op for op in group if op[0] != 'equal']
        groups.append((start + edits[0][1], start + edits[-1][2],
                       start + edits[0][3], start + edits[-1][4]))
    return groups


def assemble(old, new, hunks, selected, crlf):
    chunks = []
    cursor = 0
    for i, (a, b, c, d) in enumerate(hunks, start=1):
        if i in selected:
            chunks.extend(old[cursor:a])
            chunks.extend(new[c:d])
            cursor = b
    chunks.extend(old[cursor:])
    data = b''.join(chunks)
    return data.replace(b'\n', b'\r\n') if crlf else data


def reference_bounds(spec, kit, orig):
    rows = None
    result = {}
    for row in spec['targets'] + spec['controls']:
        name, addr = row[:2]
        rva = number(addr)
        if len(row) == 3:
            lo = hi = number(row[2])
        elif len(row) == 2:
            if rows is None:
                raw = json.loads((kit/'meta/function_map.json').read_text(encoding='utf-8-sig'))
                rows = {number(r['rva']): r for r in raw['map']}
            ranges = rows.get(rva, {}).get('ranges', [])
            if len(ranges) != 1 or number(ranges[0][0]) != rva:
                raise ValueError(f'{name}: specify verified padded size for {rva:#x}')
            lo = hi = number(ranges[0][1]) - rva
            # Section padding stops before any other known function starts.
            for offset, byte in enumerate(orig(rva + lo, 15) or b''):
                if byte not in (0x90, 0xcc) or rva + lo + offset in rows:
                    break
                hi += 1
        else:
            raise ValueError(f'invalid target/control: {row}')
        if lo <= 0 or not orig(rva, hi) or len(orig(rva, hi)) != hi:
            raise ValueError(f'{name}: invalid reference window {rva:#x} + {hi}')
        result[name, rva] = (lo, hi)
    return result


def make_evaluator(spec, specdir, kit, scratch, render):
    sys.dont_write_bytecode = True
    sys.path[:0] = [str(kit/'tools'), str(kit)]
    from coffmatch import Obj, match_function
    from l2match import orig

    vc = kit/'vc6'
    bindir = vc/'VC98/BIN'
    common = vc/'COMMON/MSDEV98/BIN'
    # Legacy cl loads its compiler passes and MSPDB60 by name. Stage the
    # compatible siblings together so a system-installed DLL cannot win.
    for name in ('CL.EXE', 'C1.DLL', 'C1XX.DLL', 'C2.DLL'):
        shutil.copyfile(bindir/name, scratch/name)
    shutil.copyfile(common/'MSPDB60.DLL', scratch/'MSPDB60.DLL')
    env = dict(os.environ, TEMP=str(scratch), TMP=str(scratch),
               INCLUDE=os.pathsep.join(map(str, [vc/'VC98/INCLUDE', vc/'VC98/ATL/INCLUDE'])),
               LIB=str(vc/'VC98/LIB'))
    env['PATH'] = os.pathsep.join([str(scratch), str(bindir), str(common), env.get('PATH', '')])
    for key in ('CL', '_CL_'):
        env.pop(key, None)
    inc = [(specdir/path).resolve() for path in spec.get('include_dirs', [])]
    inc.append((specdir/spec['failed']).resolve().parent)
    preset = spec.get('preset', 'm85')
    flags = ['-nologo', '-c', '-O2', '-Ob2', '-Gr', '-GR', '-DNDEBUG', '-Gy']
    if preset == 'm85':
        inc += [kit/'m85/src', kit/'m85/include']
        flags += ['-DWIN32', '-W0']
    elif preset == 'ra2':
        inc.append(kit/'ra2')
    else:
        raise ValueError(f'unknown preset {preset!r}')
    flags.extend('-I'+str(path) for path in inc)
    bounds = reference_bounds(spec, kit, orig)
    bindings = {key: number(value) for key, value in spec.get('bindings', {}).items()}

    def measure(obj, row):
        needle, rva = row[0], number(row[1])
        names = [needle] if needle in obj.symbols else [
            name for name in obj.symbols if not needle.startswith('?') and needle in name]
        if len(names) != 1:
            return dict(symbol=needle, rva=hex(rva), status='missing_or_ambiguous', score=None)
        name = names[0]
        size = len(obj.function(name)['raw'])
        original = orig(rva, size)
        if not original or len(original) != size:
            raise ValueError(f'{name}: original section window unavailable')
        result = match_function(obj, name, original, 0x400000+rva, bindings.get)
        low, high = bounds[needle, rva]
        delta = max(low - size, 0, size - high)
        problems = result['relocation_problems']
        score = result['byte_differences'] + 4*delta + len(problems)
        status = 'size_mismatch' if delta else result['status']
        return dict(symbol=name, rva=hex(rva), status=status, size=size,
                    expected_size=[low, high], differences=result['byte_differences'],
                    open_bindings=len(result['unresolved_bindings']),
                    relocation_problems=problems, score=score)

    def evaluate(selected):
        (scratch/'variant.cpp').write_bytes(render(selected))
        objpath = scratch/'variant.obj'
        objpath.unlink(missing_ok=True)
        proc = subprocess.run([str(scratch/'CL.EXE'), *flags, '-Fovariant.obj', 'variant.cpp'],
                              env=env, cwd=scratch, capture_output=True, timeout=600)
        if proc.returncode:
            message = (proc.stdout + proc.stderr).decode('latin1').strip()
            system_errors = ('error C1001', 'error C1060', 'error C1076', 'error C1083')
            if 'error C' not in message or any(code in message for code in system_errors):
                raise RuntimeError(f'compiler or input failure ({proc.returncode}): {message[-1200:]}')
            return dict(status='compile_error', error=message[-1200:], score=None)
        obj = Obj(objpath.read_bytes())
        targets = [measure(obj, row) for row in spec['targets']]
        controls = [measure(obj, row) for row in spec['controls']]
        if any(r['score'] != 0 for r in controls):
            status, score = 'control_failure', None
        elif any(r['score'] is None for r in targets):
            status, score = 'target_missing_or_ambiguous', None
        else:
            score = sum(r['score'] for r in targets)
            status = 'match' if score == 0 else 'mismatch'
        return dict(status=status, score=score, targets=targets, controls=controls)
    return evaluate


def difference(a, b):
    if a is not None and b is not None:
        return a - b
    return None


def search(count, evaluate, limit):
    cache = {}
    def trial(subset):
        key = tuple(sorted(subset))
        if key not in cache:
            cache[key] = evaluate(key)
        return cache[key]['score']

    all_ids = frozenset(range(1, count + 1))
    failed, donor = trial(()), trial(all_ids)
    rows = []
    for i in sorted(all_ids):
        gain = difference(failed, trial([i]))
        cost = difference(trial(all_ids - {i}), donor)
        rows.append(dict(hunk=i, add_gain=gain, remove_cost=cost,
                         pair_required=gain is None or cost is None or gain != cost, pairs=[]))
    for i, j in itertools.combinations(sorted(all_ids), 2):
        if rows[i-1]['pair_required'] or rows[j-1]['pair_required']:
            pair = {i,j}
            add, remove = trial(pair), trial(all_ids - pair)
            for h, other in ((i,j), (j,i)):
                rows[h-1]['pairs'].append(dict(partner=other, add_score=add, remove_score=remove))

    # Known wins are upper bounds. Check *all* smaller combinations by size,
    # even when their singleton tests were neutral, adverse or did not compile.
    best = min((k for k,v in cache.items() if v['score'] == 0),
               key=lambda k: (len(k), k), default=None)
    ceiling = len(best) if best is not None else count+1
    extra = 0
    state = 'proven_minimum' if best is not None else 'no_matching_subset'
    for size in range(ceiling):
        for subset in itertools.combinations(sorted(all_ids), size):
            if subset not in cache:
                if limit is not None and extra >= limit:
                    return rows, cache, best, 'search_limit_reached'
                extra += 1
            if trial(subset) == 0:
                return rows, cache, subset, 'proven_minimum'
    return rows, cache, best, state


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('spec', type=Path)
    ap.add_argument('--kit', type=Path, required=True)
    ap.add_argument('--work', type=Path, required=True)
    ap.add_argument('--context', type=int, default=2)
    ap.add_argument('--search-limit', type=int)
    a = ap.parse_args()
    if a.context < 0 or (a.search_limit is not None and a.search_limit < 0):
        ap.error('context and search limit must be nonnegative')
    specdir = a.spec.resolve().parent
    spec = json.loads(a.spec.read_text(encoding='utf-8-sig'))
    if not spec.get('targets') or 'controls' not in spec:
        ap.error('provide targets and an explicit controls list')
    old, crlf = read_lines(specdir/spec['failed'])
    new, _ = read_lines(specdir/spec['donor'])
    hunks = changes(old, new, a.context)
    def render(subset):
        return assemble(old, new, hunks, subset, crlf)

    a.work.mkdir(exist_ok=True, parents=True)
    run = Path(tempfile.mkdtemp(prefix='ablate-', dir=a.work.resolve()))
    if os.name == 'nt':
        import ctypes
        ctypes.windll.kernel32.SetErrorMode(0x8003)
    with tempfile.TemporaryDirectory(dir=run) as temp:
        evaluate = make_evaluator(spec, specdir, a.kit.resolve(), Path(temp), render)
        rows, cache, best, state = search(len(hunks), evaluate, a.search_limit)
    for row, (a0, a1, b0, b1) in zip(rows, hunks):
        row.update(failed_span=[a0,a1], donor_span=[b0,b1])
    report = dict(outcome=state, matching_hunks=best, builds=len(cache), hunks=rows,
                  spec=spec, context=a.context, search_limit=a.search_limit,
                  span_convention='zero-based half-open lines',
                  trials=[dict(selected=k, **v) for k,v in cache.items()])
    (run/'report.json').write_text(json.dumps(report, indent=2)+'\n', encoding='utf-8')
    with (run/'table.tsv').open('w', newline='', encoding='utf-8') as f:
        table = csv.writer(f, delimiter='\t')
        table.writerow(['hunk','add_gain','remove_cost','pair_required','pairs (total scores)'])
        for r in rows:
            table.writerow([r['hunk'], r['add_gain'], r['remove_cost'], r['pair_required'],
                            json.dumps(r['pairs'])])
    if best is not None:
        (run/'matching.cpp').write_bytes(render(set(best)))
    print(json.dumps(dict(outcome=state, matching_hunks=best, builds=len(cache), directory=str(run))))


if __name__ == '__main__':
    main()

