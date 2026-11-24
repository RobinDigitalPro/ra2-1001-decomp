"""Predict the calibrated Zone_Reset frame-home tie on VC6 12.00.8168."""
import argparse
import csv
from pathlib import Path
import re
import sys


def prediction(pass_id, file_top=False):
    residue = pass_id % 64
    reverse = 23 <= residue <= 27 or (file_top and 1 <= residue <= 19)
    return (4, -28, -32) if reverse else (0, -32, -28)


def from_listing(path):
    text = path.read_text(encoding='latin1')
    marker = '\n?Zone_Reset@MapClass@@QAEHXZ PROC '
    if text.count(marker) != 1:
        raise ValueError('expected exactly one Zone_Reset symbol in the assembly listing')
    declarations = text.split(marker)[0].rsplit('_TEXT\tSEGMENT', 1)[-1]
    match = re.search(r'^_pass\$(\d+) =', declarations, re.MULTILINE)
    if not match:
        raise ValueError('missing decorated pass local in Zone_Reset declaration block')
    return int(match[1])


def score(paths, direct32_top):
    failures = 0
    for path in paths:
        correct = unsupported = total = 0
        with path.open(newline='', encoding='utf8') as ledger:
            for row in csv.DictReader(ledger):
                total += 1
                file_top = row['placement'] == 'top'
                if file_top and not (direct32_top and row['header'] == 'current' and row['position'] == 'entry'):
                    unsupported += 1
                    continue
                expected = prediction(int(row['pass_id']), file_top)
                actual = tuple(int(row[field]) for field in ('differences', 'this_home', 'degree_home'))
                if expected == actual:
                    correct += 1
                else:
                    failures += 1
                    print(f"miss {path.name} {row['placement']} {row['count']} {expected} {actual}")
        print(f'{path.name}: {correct}/{total-unsupported} supported rows correct, {unsupported} file-top rows excluded')
    return int(failures != 0)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('--pass-id', type=int)
    group.add_argument('--listing', type=Path)
    group.add_argument('--snapshot', choices=['27', '32'], help='predict without compiling')
    group.add_argument('--score', nargs='+', type=Path)
    parser.add_argument('--direct32-top', action='store_true',
                        help='enable file-top calibration only for normal-include batch 32 current/entry builds')
    parser.add_argument('--header', choices=['current','old','face','old_face'], default='current',
                        help='current includes CountryName constructors; face adds two named locals')
    parser.add_argument('--position', choices=['entry','allocation'], default='entry')
    parser.add_argument('--count', type=int, default=0, help='extra declarations counted before Zone_Reset')
    parser.add_argument('--placement', choices=['before','inside','top'], default='before')
    args = parser.parse_args()
    if args.score:
        return score(args.score, args.direct32_top)
    if args.placement == 'top' and not (
            (args.snapshot == '32' or (args.snapshot is None and args.direct32_top)) and
            args.header == 'current' and args.position == 'entry'):
        parser.error('file-top rule calibrated only for the direct batch 32 current/entry build family')
    if args.count < 0:
        parser.error('--count must be nonnegative')
    if not args.snapshot and (args.count or args.header != 'current' or args.position != 'entry'):
        parser.error('--count, --header and --position describe source changes with --snapshot')
    if args.snapshot:
        pass_id = (88412 if args.snapshot == '27' else 88415) + args.count
        if args.header in ('old', 'old_face'):
            pass_id -= 5
        if args.header in ('face', 'old_face'):
            pass_id += 2
        if args.position == 'allocation':
            pass_id -= 1
    else:
        pass_id = from_listing(args.listing) if args.listing else args.pass_id
    differences, this_home, degree_home = prediction(pass_id, args.placement == 'top')
    print(f'pass_id={pass_id} residue={pass_id % 64} differences={differences} '
          f'this_home={this_home} degree_home={degree_home}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
