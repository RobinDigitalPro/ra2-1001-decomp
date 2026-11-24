"""Check the retry streak, unknown scores, context isolation and control filtering."""
import csv
import json
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path


class LedgerTest(unittest.TestCase):
    def test_retry_budget(self):
        with tempfile.TemporaryDirectory() as directory:
            base = Path(directory)
            scope = base / 'scope.json'
            scope.write_text(json.dumps({'translation_units': {}, 'batches': {}}))
            for batch, context, first, best in [
                (90, 'project', '7', '7'), (91, 'project', '', '7'),
                (92, 'project', '', ''), (93, 'project', '', '7'),
                (94, 'diagnostic headers', '', '0'), (95, 'project', '', '5'),
            ]:
                table = (
                    '| function | rva | TU | context | input differing bytes | best differing bytes |\n'
                    '| --- | --- | --- | --- | --- | --- |\n'
                    f'| Sample | 0xa1234 | sample.cpp | {context} | {first} | {best} |\n'
                    'bad12 UnrelatedControl matched 16 16 0 []\n'
                )
                (base / f'batch{batch}_REPORT.md').write_text(table, encoding='utf-8')
            result = base / 'result.csv'
            subprocess.run([sys.executable, '-I', str(Path(__file__).with_name('level2_ledger.py')),
                            str(base), '--scope', str(scope), '-o', str(result)], check=True)
            with result.open(encoding='utf-8-sig', newline='') as source:
                rows = list(csv.DictReader(source))
            self.assertEqual([r['no gain rounds'] for r in rows], ['1', '2', '2', '3', '0', '0'])
            self.assertEqual([r['status'] for r in rows], [
                'open', 'open', 'unmeasured', 'needs new method', 'diagnostic only', 'open'])
            self.assertEqual([r['attempts'] for r in rows], ['1', '2', '3', '4', '1', '5'])
            self.assertEqual(set(r['rva'] for r in rows), {'0xa1234'})


if __name__ == '__main__':
    unittest.main()

