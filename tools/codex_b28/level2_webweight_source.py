"""Produce a transparent source-level web model for level2_webweight.py.

Example:
  python -I level2_webweight_source.py isotype.cpp --function IsometricTileTypeClass::Draw_Tile --web cliprect.X cliprect.Y cliprect.Width cliprect.Height --aggregate cliprect --out clip.json

Works on brace-delimited C++ functions. Qualified fields and bare identifiers
are supported. --aggregate treats whole-object occurrences as one use of each
selected field (e.g. passing a rectangle by value). Each brace / control-flow
header splits a lexical region. This estimates source counts; optimization,
macro expansion, IR liveness, split webs, and inlining need explicit corrections
in the JSON. Only simultaneous selected webs compete in this prediction.
"""
import argparse
from collections import Counter
import json
from pathlib import Path
import re

TOKEN = re.compile(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|\w+|::|->|[^\s]', re.S)


def body_tokens(source, function):
    tokens = [m[0] for m in TOKEN.finditer(source)
              if not m[0].startswith(("//","/*","\"", "'"))]
    spelling = TOKEN.findall(function) + ["("]
    for start in range(len(tokens)-len(spelling)):
        if tokens[start:start+len(spelling)] != spelling:
            continue
        end = start+len(spelling)
        depth=1
        while end < len(tokens) and depth:
            depth+=(tokens[end]=="(")-(tokens[end]==")")
            end+=1
        while end < len(tokens) and tokens[end] not in ("{",";"):
            end+=1
        if end == len(tokens) or tokens[end]!="{":
            continue
        result=[]
        depth=1
        for token in tokens[end+1:]:
            depth+=(token=="{")-(token=="}")
            if not depth:
                return result
            result.append(token)
    raise ValueError("braced function definition not found: "+function)


def feature_blocks(tokens, names, aggregate):
    regions=[]
    context=[]
    buf=[]
    parens=0
    spell={w:TOKEN.findall(w) for w in names}
    aggregates=set(aggregate)
    def flush(extra=None):
        if not buf:
            return
        refs=Counter()
        for i, token in enumerate(buf):
            for name,t in spell.items():
                if buf[i:i+len(t)]==t:
                    refs[name]+=1
                elif token in aggregates and t[0]==token and len(t)>1 and buf[i+1:i+2] not in (["."],["->"]):
                    refs[name]+=1
        ctx=context+[extra]
        regions.append(dict(name=f"region {len(regions)+1}", refs=dict(refs), depth=min(3,ctx.count("loop")),
                            conditional="arm" in ctx))
        buf.clear()
    for token in tokens:
        if token=="{":
            ctl=next((x for x in buf if x in ("for","do","while","if","else","switch")),None)
            role="loop" if ctl in ("for","do","while") else "arm" if ctl in ("if","else","switch") else None
            flush()
            context.append(role)
        elif token=="}":
            flush()
            context.pop()
        else:
            parens+=(token=="(")-(token==")")
            buf.append(token)
            if token==";" and parens==0:
                # Keep the segment straight through consecutive statements.
                if any(x in buf for x in ("return","goto","break","continue","while","if","for")):
                    flush()
    flush()
    hits={n:[i for i,r in enumerate(regions) if n in r["refs"]] for n in names}
    for n,inds in hits.items():
        if not inds:
            raise ValueError("no references for "+n)
    for i,r in enumerate(regions):
        r["live"]=[n for n in names if hits[n][0]<=i<=hits[n][-1]]
    return [r for r in regions if r["live"]]


def main():
    p=argparse.ArgumentParser(description=__doc__,formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("source",type=Path)
    p.add_argument("--function",required=True)
    p.add_argument("--web",nargs="+",required=True)
    p.add_argument("--aggregate",nargs="*",default=[])
    p.add_argument("--out",type=Path,required=True)
    a=p.parse_args()
    toks=body_tokens(a.source.read_text(encoding="latin1"),a.function)
    data=dict(function=a.function,webs=a.web,blocks=feature_blocks(toks,a.web,a.aggregate))
    a.out.write_text(json.dumps(data,indent=2)+"\n",encoding="utf-8")
if __name__=="__main__":
    main()

