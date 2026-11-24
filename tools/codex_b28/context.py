"""Read the local compiler only; inventory decoded instructions matching a pattern."""
import argparse
import collections
import re
import runpy
import sys
from pathlib import Path
kit, pattern = sys.argv[1:3]
before, after = (int(x) for x in sys.argv[3:5])
sys.argv = ["", kit, "asm", "a^"]
env = runpy.run_path(str(Path(__file__).with_name("inspect_backend.py")))
ins = list(env["md"].disasm_lite(env["code"], env["tv"]))
for i, (a, n, m, o) in enumerate(ins):
    if re.search(pattern, m + " " + o):
        print("%08x | " % a + " / ".join(f"{m} {o}" for a,n,m,o in ins[max(0,i-before):i+after+1]))
