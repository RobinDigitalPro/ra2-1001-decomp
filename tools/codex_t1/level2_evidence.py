"""Write a local HTML evidence report for one function (GUIDE L6).

In the work folder run:
  python -I level2_evidence.py failed.cpp donor.cpp delivered.cpp --template notes.json
  python -I level2_evidence.py failed.cpp donor.cpp delivered.cpp --notes notes.json -o report.html

Use three corresponding function bodies or excerpts, with parallel scopes. Inputs
may be read-only. Source text defaults to UTF-8 (with optional BOM); --encoding
can select e.g. cp1252. Line endings are normalized. The first command writes
evidence.html and a blank ledger. Fill each ledger entry's reason, experiment,
call_targets, and bindings from actual tests, giving the command or log locator,
result, and applicable controls. Use 'unmeasured' or explain inapplicability
when a check has no result. The tool records supplied evidence. Source alignment
cannot establish byte equality, call destinations, or relocation bindings.

Each contiguous three-way change gets three source columns. Every distinct
donor-to-delivered change gets its own reason slot, even inside a larger change
to the failed body. Changes common to donor and delivered get one hunk slot.
The ledger is bound to all three sources. Output paths are in the current work
folder. A new template requires a fresh path to protect existing notes.
"""

import argparse
from dataclasses import dataclass
from difflib import SequenceMatcher
from hashlib import sha256
from html import escape
import json
from pathlib import Path


@dataclass(frozen=True)
class Edit:
    column: int
    start: int
    end: int
    other_start: int
    other_end: int

    @property
    def growth(self):
        return (self.other_end - self.other_start) - (self.end - self.start)


def aligned_hunks(lines):
    """Align edits on donor coordinates. Empty ranges are insertion boundaries."""
    donor = lines[1]
    edits = []
    for column in (0, 2):
        opcodes = SequenceMatcher(None, donor, lines[column], autojunk=False).get_opcodes()
        edits.extend(Edit(column, a, b, x, y) for kind, a, b, x, y in opcodes if kind != "equal")
    edits.sort(key=lambda edit: (edit.start, edit.end))
    shift = [0, 0, 0]
    i = 0
    while i < len(edits):
        start = end = edits[i].start
        group = []
        offsets = [0, 0, 0]
        while i < len(edits) and edits[i].start <= end:
            edit = edits[i]
            group.append(edit)
            end = max(end, edit.end)
            offsets[edit.column] += edit.growth
            i += 1
        ranges = [(start + n, end + n + d) for n, d in zip(shift, offsets)]
        yield ranges, [edit for edit in group if edit.column == 2]
        shift = [n + d for n, d in zip(shift, offsets)]


def location(start, end):
    if start == end:
        return f"after line {start}" if start else "before line 1"
    return f"line {end}" if end == start + 1 else f"lines {start + 1}–{end}"


FIELDS = ("reason", "experiment", "call_targets", "bindings")
LABELS = ("Tested reason", "Experiment and result", "Call-target check", "Binding check")
COLUMNS = ("Failed native", "Donor", "Delivered native")


def load_notes(path, digest, rows):
    notes = {key: dict.fromkeys(FIELDS, "") for _, entries in rows for key, _ in entries}
    if path is None:
        return notes
    data = json.loads(path.read_text(encoding="utf-8-sig"))
    if not isinstance(data, dict) or data.get("source_sha256") != digest:
        raise ValueError("ledger source hashes do not match these three inputs")
    entries = data.get("entries")
    if not isinstance(entries, dict) or entries.keys() != notes.keys():
        raise ValueError("ledger entry IDs must match the report template")
    for key, entry in entries.items():
        if not isinstance(entry, dict) or entry.keys() != set(FIELDS):
            raise ValueError(f"{key}: expected fields {', '.join(FIELDS)}")
        if any(not isinstance(value, str) for value in entry.values()):
            raise ValueError(f"{key}: each field must contain text")
    return entries


def evidence_rows(lines):
    rows = []
    for n, (ranges, changes) in enumerate(aligned_hunks(lines), 1):
        key = f"H{n}"
        entries = []
        for k, edit in enumerate(changes, 1):
            label = (f"Donor {location(edit.start, edit.end)} → delivered "
                     f"{location(edit.other_start, edit.other_end)}")
            entries.append((f"{key}.D{k}", label))
        if not entries:
            entries.append((key, "Donor and delivered agree here"))
        rows.append((ranges, entries))
    return rows


def render(lines, paths, rows, notes):
    result = ['<!doctype html><html lang="en"><meta charset="utf-8">',
              '<title>Three-column source evidence</title><style>',
              'body{font:16px system-ui;margin:1.5rem;color:#20242a}table{border-collapse:collapse;',
              'table-layout:fixed;width:100%}th,td{padding:.6rem;border:1px solid #bbb;',
              'vertical-align:top;text-align:left;overflow-wrap:anywhere}th{background:#edf1f6}',
              'pre{white-space:pre-wrap;tab-size:4;overflow-wrap:anywhere;font-size:.84rem}',
              'dt{font-weight:bold}dd{margin:.2rem 0 .7rem;white-space:pre-wrap}',
              '@media print{pre{font-size:8pt}}</style><h1>Three-column source evidence</h1>']
    if not rows:
        result.append("<p>All three sources agree line for line.</p>")
    for n, (ranges, entries) in enumerate(rows, 1):
        result.append(f"<section><h2>H{n}</h2><table><thead><tr>")
        for name, path, span in zip(COLUMNS, paths, ranges):
            result.append(f'<th scope="col">{name}<br>{escape(path.name)} · {location(*span)}</th>')
        result.append("</tr></thead><tbody><tr>")
        for source, (start, end) in zip(lines, ranges):
            code = escape("\n".join(source[start:end]))
            result.append(f"<td><pre>{code}</pre></td>" if start != end else "<td><em>No lines</em></td>")
        result.append("</tr></tbody></table>")
        for key, label in entries:
            result.append(f"<h3>{key} · {label}</h3><dl>")
            for field, title in zip(FIELDS, LABELS):
                value = notes[key][field].strip() or "Unmeasured"
                result.append(f"<dt>{title}</dt><dd>{escape(value)}</dd>")
            result.append("</dl>")
        result.append("</section>")
    return "\n".join(result) + "</html>\n"


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    for name in ("failed", "donor", "delivered"):
        parser.add_argument(name, type=Path)
    parser.add_argument("--encoding", default="utf-8-sig")
    parser.add_argument("-o", "--output", default=Path("evidence.html"), type=Path)
    ledger = parser.add_mutually_exclusive_group()
    ledger.add_argument("--notes", type=Path)
    ledger.add_argument("--template", type=Path)
    args = parser.parse_args()
    paths = [args.failed, args.donor, args.delivered]
    inputs = paths + ([args.notes] if args.notes else [])
    outputs = [args.output] + ([args.template] if args.template else [])
    resolved = [p.resolve() for p in outputs]
    if any(not p.is_relative_to(Path.cwd().resolve()) for p in resolved):
        parser.error("output files must be in the current work folder")
    if len(set(resolved)) != len(outputs) or set(resolved).intersection(p.resolve() for p in inputs):
        parser.error("each output must be distinct from the inputs and other outputs")
    try:
        sources = [p.read_text(encoding=args.encoding) for p in paths]
        digest = [sha256(text.encode("utf-8")).hexdigest() for text in sources]
        lines = [text.splitlines() for text in sources]
        rows = evidence_rows(lines)
        notes = load_notes(args.notes, digest, rows)
        html = render(lines, paths, rows, notes)
        if args.template:
            with args.template.open("x", encoding="utf-8") as fp:
                json.dump({"source_sha256": digest, "entries": notes}, fp, indent=2)
                fp.write("\n")
        args.output.write_text(html, encoding="utf-8")
    except (LookupError, OSError, ValueError) as err:
        parser.exit(1, f"evidence: {err}\n")
    print(f"{len(rows)} hunks, {len(notes)} evidence entries. Report: {args.output}")


if __name__ == "__main__":
    main()
