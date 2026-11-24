"""Compile and measure an independent VC6 register-priority experiment.

python -I level2_webweight_lab.py --kit KIT --work PRIVATE_DIR --csv output.csv
One private /Gy object holds all probes. Only generated source is compiled.
The final volatile observations are decoded from COFF relocations, independent
of a listing's variable comments. They measure endpoint registers only.
"""
import argparse
import csv
import itertools
import os
from pathlib import Path
import subprocess
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
from level2_webweight import rank


def cases():
    for left, right in itertools.product(range(1, 5), repeat=2):
        for reverse in (False, True):
            yield ("straight", left, right, reverse)
    for kind in ("if", "loop", "nested", "byte", "byte-store", "pressure"):
        for left, right in itertools.product(range(1, 5), range(1, 5)):
            yield kind, left, right, False
    for arms in (0, 1, 2, 4, 8):
        for left in range(1, 8):
            yield f"span-{arms}", left, 2, False


def make_case(kind, left, right, reverse, index):
    names = ["b", "a"] if reverse else ["a", "b"]
    types = {"a": "unsigned char" if kind.startswith("byte") else "int", "b": "int"}
    desc = [dict(name=w, width=8 if types[w] == "unsigned char" else 32) for w in names]
    function = "probe%03d" % index
    lines = ["extern \"C\" void __cdecl " + function + "() {"]
    blocks = []
    # Both observable endpoint writes and both opaque definitions count. Calls
    # keep the observations from being propagated back to the definition.
    for w in names:
        lines.append("  %s %s = (%s) get_%s();" % (types[w],w,types[w],w))
    lines.append("  barrier();")
    def block(name, refs, **extra):
        blocks.append(dict(name=name, refs=refs, live=list(names), **extra))
    block("endpoints and definitions", {"a":2,"b":2})
    if kind == "byte-store":
        lines.extend(["  byte_sink=a; barrier();"] * left)
    else:
        lines.extend(["  use_a(a);"] * left)
    block("straight a", {"a":left})
    if kind == "pressure" or kind.startswith("span-"):
        # B is not yet defined in these branch blocks. Distinct candidate t
        # survives a barrier in each arm. Measure differential pressure.
        second = lines.pop(2)
        assert ' b =' in second
        prefix = []
        for j in range(right if kind == "pressure" else int(kind[5:])):
            prefix.append("  if (gate) { int t=get_t(); barrier(); use_t(t); }")
            blocks.append(dict(name=f"candidate {j}",live=["a"],refs={},conditional=True,through={"a":1}))
        lines[2:2] = prefix + [second]
    depth = {"loop":1,"nested":2}.get(kind, 0)
    if kind == "if":
        lines.append("  if (gate) {")
    for d in range(depth):
        lines.append("  for (int n%d=gate; n%d>0; --n%d) {" % (d,d,d))
    lines.extend(["  use_b(b);"] * right)
    lines.extend(["  }"] * (depth + (kind == "if")))
    block("b uses", {"b":right},depth=depth,conditional=kind == "if")
    endpoint = "  obs_char=a;" if kind == "byte-store" else "  obs_a=a;"
    lines.extend([endpoint, "  obs_b=b;", "}"])
    return function, "\n".join(lines), dict(webs=desc, blocks=blocks)


def observe(obj, symbol, decoder):
    sec = obj.function(symbol)
    refs = {off: obj.by_index[idx]["name"] for off, idx, _ in sec["relocs"]}
    result = {}
    for instruction in decoder.disasm(sec["raw"], 0):
        hits = [refs.get(n) for n in range(instruction.address,instruction.address+instruction.size)]
        for name in ("a", "b"):
            if "_obs_"+name in hits or (name == "a" and "_obs_char" in hits):
                ops = instruction.op_str.split(", ")
                if instruction.mnemonic != "mov" or len(ops)!=2 or "[" not in ops[0]:
                    raise ValueError((symbol, instruction.mnemonic, ops))
                register = ops[1]
                result[name] = {"al":"eax","bl":"ebx","cl":"ecx","dl":"edx"}.get(register,register)
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--kit", type=Path, required=True)
    parser.add_argument("--work", type=Path, required=True)
    parser.add_argument("--csv", type=Path, required=True)
    args = parser.parse_args()
    kit, work = args.kit.resolve(), args.work.resolve()
    work.mkdir(parents=True,exist_ok=True)
    sys.path[:0]=[str(kit),str(kit/"tools")]
    from coffmatch import Obj
    import capstone
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    prelude = """extern "C" {
    int __cdecl get_a(); int __cdecl get_b(); int __cdecl get_t();
    void __cdecl use_a(int); void __cdecl use_b(int); void __cdecl use_t(int);
    void __cdecl barrier();
    extern volatile int gate, obs_a, obs_b;
    extern volatile unsigned char byte_sink, obs_char;
    }"""
    probes = [(c, make_case(*c,idx)) for idx,c in enumerate(cases())]
    (work/"probes.cpp").write_text(prelude+"\n"+"\n".join(f[1] for c,f in probes))
    vc = kit/"vc6"
    env = os.environ.copy()
    env["PATH"]=os.pathsep.join([str(vc/"VC98/BIN"),str(vc/"COMMON/MSDEV98/BIN"),env["PATH"]])
    env["TMP"]=env["TEMP"]=str(work)
    subprocess.run([str(vc/"VC98/BIN/CL.EXE"),"-nologo","-c","-O2","-Ob2","-Gr","-GR","-DNDEBUG","-Gy","-W0","-Foprobes.obj","probes.cpp"],env=env,cwd=work,check=True)
    obj=Obj((work/"probes.obj").read_bytes())
    with args.csv.open("w",newline="",encoding="utf-8") as file:
        fields = ["function","family","uses_a","uses_b","reverse","score_a","score_b","pred_a","pred_b","obs_a","obs_b","pair_exact"]
        writer=csv.DictWriter(file,fieldnames=fields)
        writer.writeheader()
        for (kind,left,right,reverse),(fn,_,model) in probes:
            predicted={r["web"]:r for r in rank(model)}
            observed=observe(obj,"_"+fn,decoder)
            writer.writerow(dict(function=fn,family=kind,uses_a=left,uses_b=right,reverse=int(reverse),
                score_a=predicted["a"]["score"],score_b=predicted["b"]["score"],
                pred_a=predicted["a"]["reg"],pred_b=predicted["b"]["reg"],
                obs_a=observed["a"],obs_b=observed["b"],
                pair_exact=int(all(observed[w]==predicted[w]["reg"] for w in observed))))
if __name__=="__main__":
    main()

