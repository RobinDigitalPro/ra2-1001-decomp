"""Measure declaration-count sensitivity for three independently retained m85 sources.

The diagnostic locals are inserted only in private temporary copies. Predict the
held-out n+64 cases using the compiled n body before reading the held-out result.
"""
import argparse
import concurrent.futures
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys

TARGETS = {
    "sidebar": ("int SidebarClass::StripClass::SelectClass::Action(", "?Action@SelectClass@", "0x2761a0"),
    "wonline": ("STDMETHODIMP CChatEventSink::OnChannelJoin(", "?OnChannelJoin@CChatEventSink@", "0x34cb20"),
    "mapgen": ("DynamicVectorClass<Cell> * MapGeneratorClass::Create_Urban_Area(", "?Create_Urban_Area@MapGeneratorClass@", "0x183940"),
}

def digest(data):
    return hashlib.sha256(data).hexdigest()

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for key in ("kit", "scratch", "report"):
        parser.add_argument(key, type=Path)
    parser.add_argument("--extend-current-run", action="store_true", help="Reuse verified objects from this scratch directory with the same compiler and headers.")
    args = parser.parse_args()
    kit = args.kit.resolve()
    sys.path.insert(0, str(kit / "tools"))
    from coffmatch import Obj
    history = {}
    if args.extend_current_run:
        history = {(r["tu"],r["count"],r["prefix"]):r for r in json.loads(args.report.read_bytes())["trials"]}
    trials = [(tu,n,prefix) for tu in TARGETS for prefix,counts in
              [("probe", (0,1,2,3,7,16,31,63,64,65,66,67,71,80,95,127)),
               ("alternate", (1,7,64,65)), ("members_before", (0,1,7,64,65)),
               ("members_after", (0,1,7,64,65))] for n in counts]
    def measure(trial):
        tu, n, prefix = trial
        anchor, symbol, rva = TARGETS[tu]
        src = kit / "m85/src" / (tu + ".cpp")
        data = src.read_bytes()
        code = data.decode("latin1")
        assert code.count(anchor) == 1
        body = code.index("{", code.index("\n", code.index(anchor))) + 1
        if prefix.startswith("members_"):
            body = code.index(anchor) if prefix=="members_before" else len(code)
            decls = "\nclass Batch32DeclarationProbe {\n" + "".join(
                "    void f%d();\n" % i for i in range(n)) + "};\n"
        else:
            decls = "".join("\n    int %s_%d;" % (prefix,i) for i in range(n))
        work = (args.scratch / tu / (prefix + str(n))).resolve()
        work.mkdir(parents=True, exist_ok=True)
        private = work / src.name
        trial_data = (code[:body] + decls + code[body:]).encode("latin1")
        saved = history.get(trial)
        if saved and private.is_file() and private.read_bytes()==trial_data and saved["input_sha256"]==digest(data):
            obj = Obj(private.with_suffix(".obj").read_bytes())
            name, = [name for name in obj.symbols if symbol in name]
            if digest(obj.function(name)["raw"])==saved["raw_body_sha256"]:
                return saved
        private.write_bytes(trial_data)
        run = subprocess.run([sys.executable, "-I", str(kit / "tools/try.py"), str(private), symbol+" "+rva],
                             cwd=work, capture_output=True, text=True, timeout=240)
        line = next((x for x in run.stdout.splitlines() if x.startswith(rva+" ")), "")
        m = re.search(r" (\w+) (\d+) (\d+) (\d+) \[", line)
        if run.returncode or not m:
            raise RuntimeError((tu,n,run.stdout[-800:],run.stderr[-800:]))
        obj = Obj(private.with_suffix(".obj").read_bytes())
        name, = [name for name in obj.symbols if symbol in name]
        return dict(tu=tu, count=n, prefix=prefix, input_sha256=digest(data),
                    raw_body_sha256=digest(obj.function(name)["raw"]),
                    size=int(m[2]), differences=int(m[4]), compare=line)
    with concurrent.futures.ThreadPoolExecutor(max_workers=2) as pool:
        rows = list(pool.map(measure, trials))
    by_key = {(r["tu"],r["prefix"],r["count"]): r["raw_body_sha256"] for r in rows}
    tests = []
    for tu in TARGETS:
        for n in (0,1,2,3,7,16,31,63):
            tests.append(dict(tu=tu, test="period64", n=n, same=by_key[tu,"probe",n]==by_key[tu,"probe",n+64]))
        for n in (1,7,64,65):
            tests.append(dict(tu=tu, test="name_invariance", n=n, same=by_key[tu,"probe",n]==by_key[tu,"alternate",n]))
        for n in (0,1,7,64,65):
            tests.append(dict(tu=tu, test="member_position", n=n,
                              same=by_key[tu,"members_before",n]==by_key[tu,"members_after",n]))
    args.report.write_text(json.dumps(dict(trials=rows,tests=tests),indent=2))
    for tu in TARGETS:
        print(tu, "states", len({r["raw_body_sha256"] for r in rows if r["tu"]==tu}),
              "period64", sum(t["same"] for t in tests if t["tu"]==tu and t["test"]=="period64"), "/8")

if __name__ == "__main__":
    main()
