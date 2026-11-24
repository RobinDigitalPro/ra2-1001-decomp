"""Replay the ordinary VC6 8168 inliner on an ordered intermediate call graph.

Each function maps to {size, sites, flags?}. A site is a callee string or an
object with callee and optional eligible, size_ceiling, arity_ok, max_depth.
The input records the lowered candidate order and site decisions preceding
budget admission. size_ceiling, when provided, is a strict pre-list bound.
Depth is one at the root. Duplicate calls remain distinct.
"""
import argparse
import csv
import json
import sys


def simulate(nodes, root):
    initial = nodes[root]["size"]
    growth = initial
    trace = []

    def visit(name, budget, stack):
        nonlocal growth
        pending = []
        for item in nodes[name].get("sites", []):
            site = item if isinstance(item, dict) else {"callee": item}
            callee = site["callee"]
            if callee not in nodes or callee in stack or not site.get("eligible", True):
                continue
            body = nodes[callee]
            ceiling = site.get("size_ceiling")
            if body.get("eligible", True) and (ceiling is None or body["size"] < ceiling):
                pending.append(site)
        for index, site in enumerate(pending):
            count = len(pending) - index
            callee = site["callee"]
            body = nodes[callee]
            size = body["size"]
            special = bool(body.get("flags", 0) & 0x2000)
            row = dict(caller=name, depth=len(stack), callee=callee, size=size,
                       available=budget, pending=count, growth=growth, child_share="", after=budget)
            trace.append(row)
            if not site.get("arity_ok", True):
                row["decision"] = "arity"
            elif len(stack) > site.get("max_depth", 255):
                row["decision"] = "depth"
            elif not special and growth > 35000:
                row["decision"] = "growth"
            elif not special and size > 40 and size > budget:
                row["decision"] = "budget"
            else:
                row["decision"] = "inline"
                if not special:
                    growth += size
                    if size > 40:
                        budget -= size
                share = budget // count
                row["child_share"] = share
                spent = share - visit(callee, share, stack+(callee,))
                if not special:
                    budget -= spent
                    growth += spent
                row["after"] = budget
        return budget

    visit(root, min(35000, max(1000, 2*initial)), (root,))
    return trace


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("graph", type=argparse.FileType("r", encoding="utf-8"))
    p.add_argument("root")
    args = p.parse_args()
    rows = simulate(json.load(args.graph), args.root)
    if rows:
        writer = csv.DictWriter(sys.stdout, list(rows[0]))
        writer.writeheader()
        writer.writerows(rows)


if __name__ == "__main__":
    main()
