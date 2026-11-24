import sys,runpy
from pathlib import Path
k=Path(sys.argv.pop(1))
sys.path[:0]=[str(k/'tools'), str(k)]
tool=k/'tools'/sys.argv.pop(1)
sys.argv[0]=str(tool)
runpy.run_path(str(tool),run_name='__main__')
