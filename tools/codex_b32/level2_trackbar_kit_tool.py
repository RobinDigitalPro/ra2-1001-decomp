"""Run the unmodified kit utilities with kit imports available in isolated Python."""
import runpy
import sys
from pathlib import Path

kit = Path(sys.argv.pop(1))
tool = kit / "tools" / sys.argv[1]
sys.path[:0] = [str(kit), str(tool.parent)]
sys.argv = [str(tool)] + sys.argv[2:]
runpy.run_path(str(tool), run_name="__main__")
