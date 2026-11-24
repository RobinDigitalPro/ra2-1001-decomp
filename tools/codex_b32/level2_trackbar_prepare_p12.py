"""Prepare the archived, exact two-edit ODTooltip move as a diagnostic only."""
import json
from pathlib import Path
import sys
source, patch, destination = map(Path, sys.argv[1:])
t = source.read_bytes().replace(b"\r\n", b"\n")
for old,new in json.loads(patch.read_text())[0]["edits"]:
    assert t.count(old.encode("latin-1")) == 1
    t = t.replace(old.encode("latin-1"), new.encode("latin-1"))
destination.write_bytes(t)

