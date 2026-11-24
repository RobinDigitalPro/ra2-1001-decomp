"""Make a varsearch spec that probes how a function reacts to K extra named, initialised locals (diagnostic only).

usage: python -I level2_localprobe.py <out spec.json> <base cpp> <anchor> <after-text> '<targets json>' '<controls json>' [kmax=9]
  anchor      a unique text before the function body (e.g. its header line)
  after-text  the first occurrence of this text after the anchor gets K lines `int lcprobeN = N+3;` appended
Then run: python -I level2_varsearch.py <out spec.json> --mode grid --score hunks
A FLAT curve over K rules out gibbo101's local-count tie as the cause of a register or slot swap. A curve that
changes at one threshold or periodically (mod 8) shows the tie; then look for a REAL named value to add or remove.
Never leave lcprobe locals in source (they are dead probes)."""
# diagnostic: spec with K dead named initialised int locals inserted after `after` (first occurrence after anchor)
import json, sys
out, base, anchor, after, targets, controls = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], json.loads(sys.argv[5]), json.loads(sys.argv[6])
kmax = int(sys.argv[7]) if len(sys.argv) > 7 else 9
opts = [{"label": "k0", "edits": []}]
for k in range(1, kmax + 1):
    ins = ''.join('\tint lcprobe%d = %d;\n' % (i, i + 3) for i in range(k))
    opts.append({"label": "k%d" % k, "edits": [[after, after + ins, anchor]]})
json.dump({"base": base, "preset": "m85", "targets": targets, "controls": controls,
           "choices": [{"name": "probe", "options": opts}]}, open(out, 'w'), indent=1)
