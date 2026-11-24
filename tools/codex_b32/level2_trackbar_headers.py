"""Replay two archived header edits independently against the supplied ownrdraw source and its P12 variant."""
import argparse
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile


def replace_exact(raw, patch):
    for old, new in patch:
        old = old.encode("latin-1")
        if raw.count(old) != 1:
            raise ValueError("patch requires one occurrence: " + old[:80].decode("latin-1"))
        raw = raw.replace(old, new.encode("latin-1"))
    return raw


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for flag in ("kit", "source", "archive", "out", "scratch"):
        parser.add_argument("--" + flag, type=Path, required=True)
    args = parser.parse_args()
    args.out.mkdir(parents=True, exist_ok=True)
    probe = Path(__file__).with_name("level2_trackbar_probe.py")
    def read_edits(name):
        return json.loads((args.archive / name).read_text())[0]["edits"]
    with tempfile.TemporaryDirectory(dir=args.scratch) as folder:
        work = Path(folder)
        p12 = work / "p12.cpp"
        source = args.source.read_bytes().replace(b"\r\n", b"\n")
        p12.write_bytes(replace_exact(source, read_edits("p12_e116.json")))
        include = work / "include"
        shutil.copytree(args.kit / "m85/include", include)
        header = include / "abstract.h"
        original = header.read_bytes().replace(b"\r\n", b"\n")
        for tag, archive in (("p20", "p20_centercell.json"), ("p26", "p26b_istechno_bool.json")):
            header.write_bytes(replace_exact(original, read_edits(archive)))
            for tu_name, tu in (("baseline", args.source), ("p12", p12)):
                dest = args.out / f"trackbar32_{tu_name}_{tag}.jsonl"
                subprocess.run([sys.executable, "-I", "-B", str(probe), "--kit", str(args.kit),
                                "--source", str(tu), "--scratch", str(args.scratch),
                                "--include-root", str(include), "--out", str(dest),
                                "--cases", "extern:0,extern:1,extern:3,extern:10,extern:17,extern:45"],
                               check=True)


if __name__ == "__main__":
    main()
