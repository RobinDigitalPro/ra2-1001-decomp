"""Predict a VC6 victim's body for a measured declaration family and placement.

Measurements are JSONL. Each row contains integer k, diff (optional if state or
digest exists), and optional digest, state, offsets, size or code_size. IDs and
phase are build-specific. Use separate profiles for distinct insertion points,
header trees, declaration kinds and compiler flags unless tested together.
Fit on an independent calibration set and pass only withheld builds to verify.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re


def load_rows(path):
    with Path(path).open(encoding='utf-8-sig') as file:
        return [json.loads(line) for line in file if line.strip()]


def observation(row):
    data = {key: row[key] for key in ('diff', 'digest', 'state', 'offsets') if key in row}
    if 'size' in row or 'code_size' in row:
        data['size'] = row.get('size', row.get('code_size'))
    if not any(k in data for k in ('digest', 'state', 'diff')):
        raise ValueError('Each observation needs digest, state or diff.')
    return data


def fit(rows, period, context):
    if period <= 0 or not rows or not context:
        raise ValueError('Fit needs a positive period, observations and a named context.')
    states = {}
    residues = {}
    for row in rows:
        k = row['k']
        if type(k) is not int:
            raise ValueError('k must be an integer')
        observed = observation(row)
        state = json.dumps(observed, sort_keys=True, separators=(',', ':'))
        if state not in states:
            states[state] = len(states)
        residue = str(k % period)
        index = states[state]
        if residue in residues and residues[residue] != index:
            raise ValueError(f'Contradiction in {context} at residue {residue} (k={k})')
        residues[residue] = index
    return dict(format=1, context=context, period=period, calibration_rows=len(rows),
                states=[json.loads(s) for s in states], residues=residues)


def predict(profile, k):
    if profile['format'] != 1:
        raise ValueError('Unknown profile format')
    idx = profile['residues'].get(str(k % profile['period']))
    return None if idx is None else profile['states'][idx]


def source_count(profile, baseline, candidate):
    """Accept one contiguous run of fresh forward tags at a registered anchor."""
    rule = profile.get('source_rule')
    if not rule:
        raise ValueError('This profile has no registered source anchor.')
    original = baseline.read_bytes()
    if hashlib.sha256(original).hexdigest() != rule['baseline_sha256']:
        raise ValueError('Baseline content differs from calibration.')
    anchor = rule['anchor'].encode('utf8')
    if original.count(anchor) != 1:
        raise ValueError('Source anchor must occur exactly once.')
    edited = candidate.read_bytes()
    at = original.index(anchor)
    prefix, suffix = original[:at], original[at:]
    if not edited.startswith(prefix) or not edited.endswith(suffix) or len(edited) < len(original):
        raise ValueError('Changes extend beyond the calibrated insertion point.')
    inserted = edited[at:len(edited)-len(suffix)]
    if not re.fullmatch(rb'(?:\s*struct\s+[A-Za-z_]\w*\s*;)*\s*', inserted):
        raise ValueError('Insertion must contain only independent forward tag declarations.')
    tags = re.findall(rb'struct\s+([A-Za-z_]\w*)', inserted)
    if len(set(tags)) != len(tags) or set(tags).intersection(re.findall(rb'\b[A-Za-z_]\w*\b', original)):
        raise ValueError('New tag names must be unique and absent from the baseline.')
    # Freshness relative to included headers is a caller precondition.
    return len(tags)


def verify(profile, rows):
    passed, missed, unknown = [], [], []
    for row in rows:
        expected = predict(profile, row['k'])
        measured = observation(row)
        if expected is None:
            unknown.append(row['k'])
        elif expected == measured:
            passed.append(row['k'])
        else:
            missed.append(dict(k=row['k'], expected=expected, observed=measured))
    return dict(context=profile['context'], passed=passed, failed=missed, uncalibrated=unknown)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest='command', required=True)
    training = commands.add_parser('fit')
    training.add_argument('rows', type=Path)
    training.add_argument('output', type=Path)
    training.add_argument('--context', required=True)
    training.add_argument('--period', type=int, default=64)
    training.add_argument('--baseline', type=Path)
    training.add_argument('--anchor')
    src = commands.add_parser('source', help='Predict from two source files with a registered tag insertion.')
    src.add_argument('profile', type=Path)
    src.add_argument('baseline', type=Path)
    src.add_argument('candidate', type=Path)
    for name in ('predict','verify'):
        part=commands.add_parser(name)
        part.add_argument('profile', type=Path)
        if name=='predict':
            part.add_argument('k', type=int, nargs='+')
        else:
            part.add_argument('rows', type=Path)
    args = parser.parse_args()
    if args.command=='fit':
        profile=fit(load_rows(args.rows), args.period, args.context)
        if bool(args.baseline) != bool(args.anchor):
            parser.error('Provide both --baseline and --anchor.')
        if args.baseline:
            raw = args.baseline.read_bytes()
            if raw.count(args.anchor.encode('utf8')) != 1:
                parser.error('Anchor must occur exactly once in baseline.')
            profile['source_rule'] = dict(anchor=args.anchor, baseline_sha256=hashlib.sha256(raw).hexdigest())
        args.output.write_text(json.dumps(profile, indent=2)+'\n',encoding='utf8')
        return
    profile=json.loads(args.profile.read_text(encoding='utf8'))
    if args.command=='source':
        try:
            k = source_count(profile,args.baseline,args.candidate)
        except ValueError as exc:
            parser.error(str(exc))
        result = dict(k=k, context=profile['context'], prediction=predict(profile,k))
    elif args.command=='predict':
        result=[dict(k=k, context=profile['context'], prediction=predict(profile,k)) for k in args.k]
    else:
        result=verify(profile,load_rows(args.rows))
    print(json.dumps(result,indent=2))
    if args.command=='verify' and (result['failed'] or result['uncalibrated']):
        raise SystemExit(1)


if __name__=='__main__':
    main()

