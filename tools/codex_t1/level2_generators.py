"""Generate exact C++ edits for level2_varsearch.py (imported by its --generate-only mode).

The recognizers cover common VC6-era constructs. They mask comments and literals,
bound each rewrite to a selected definition, and attach header evidence to overload
options. A candidate expresses a source hypothesis. Inspect its semantics and use
the normal compiler, target and control checks to evaluate it.
"""
import re
from collections import defaultdict
from functools import lru_cache
from itertools import chain
from pathlib import Path

ID = r"[A-Za-z_]\w*"
VALUE = rf"{ID}(?:(?:->|\.){ID})*"
NO_CODE = re.compile(r"""//[^\n]*|/\*[\s\S]*?\*/|"(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*'""")
NAMES = ("overloads", "split_live", "branch_split_merge", "loop_family")


def masked(source):
    return NO_CODE.sub(lambda m: re.sub(r"[^\n]", " ", m[0]), source)


def closing(code, start, left="{", right="}"):
    depth = 0
    for m in re.finditer("[" + re.escape(left + right) + "]", code[start:]):
        depth += 1 if m[0] == left else -1
        if depth == 0:
            return start + m.start()
    return None


def definitions(code, name):
    parts = name.split("::")
    pattern = r"\b" + r"\s*::\s*".join(map(re.escape, parts)) + r"\s*\("
    for match in re.finditer(pattern, code):
        paren = closing(code, match.end() - 1, "(", ")")
        if paren is None:
            continue
        start = re.match(r"\s*(?:const\s*)?\{", code[paren + 1:])
        if start:
            brace = paren + start.end()
            end = closing(code, brace)
            if end is not None:
                yield brace + 1, end


def target_names(targets):
    for name, _rva in targets:
        if name.startswith("?"):
            parts = name[1:].partition("@@")[0].split("@")
            if parts[0].isidentifier():
                yield "::".join(reversed(parts))
        else:
            yield name


def line_indent(text, index):
    return re.match(r"[ \t]*", text[text.rfind("\n", 0, index) + 1:])[0]


def fresh(code, preferred):
    name = preferred
    i = 1
    while re.search(r"\b" + re.escape(name) + r"\b", code):
        name = preferred + str(i)
        i += 1
    return name


def unique_edit(text, left, right, new):
    # Preserve the two-string format even for identical expressions in two arms.
    # Widen by the minimum number of lines that make this site unique in the TU.
    start, end = left, right
    while text.count(text[start:end]) != 1:
        start = text.rfind("\n", 0, max(start - 1, 0)) + 1
        end = text.find("\n", end + 1)
        if end < 0:
            end = len(text)
    return [text[start:end], text[start:left] + new + text[right:end]]


class HeaderIndex:
    """Read only explicit headers and the TU's transitive local include closure."""

    def __init__(self, base_path, source, files, directories):
        roots = [base_path.parent] + list(directories)
        pending = []
        for path in files:
            if path.is_dir():
                pending.extend(p for p in sorted(path.rglob("*")) if p.suffix.lower() in (".h", ".hpp", ".inl"))
                roots.append(path)
            elif path.is_file():
                pending.append(path)
            else:
                raise ValueError(f"header path does not exist: {path}")

        @lru_cache(maxsize=None)
        def locate(directory, name):
            for root in (directory, *roots):
                path = root / name
                if path.is_file():
                    return path.resolve()
            return None

        def includes(directory, raw):
            for inc in re.finditer(r'^\s*#\s*include\s*[<"]([^>"]+)[>"]', raw, re.M):
                path = locate(directory, inc[1])
                if path:
                    pending.append(path)

        includes(base_path.parent, source)
        self.files = {}
        self.classes = defaultdict(list)
        self.bases = defaultdict(set)
        while pending:
            path = pending.pop().resolve()
            if path in self.files or path.suffix.lower() not in (".h", ".hpp", ".hxx", ".inl", ".hh"):
                continue
            raw = path.read_bytes().decode("latin-1").replace("\r\n", "\n")
            code = masked(raw)
            self.files[path] = code
            includes(path.parent, raw)
            for c in re.finditer(r"\b(?:class|struct)\s+(" + ID + r")\s*(?::[^;{}]*)?\{", code):
                end = closing(code, c.end() - 1)
                if end is not None:
                    self.classes[c[1]].append((path, code[c.end():end]))
                    if ':' in c[0]:
                        self.bases[c[1]].update(re.findall(ID, c[0].split(':', 1)[1]))

    def ancestors(self, name):
        pending, found = [name], set()
        while pending:
            ty = pending.pop()
            if ty in self.classes and ty not in found:
                found.add(ty)
                pending.extend(self.bases[ty])
        return found

    def member_text(self, name):
        return '\n'.join(body for ty in self.ancestors(name) for _, body in self.classes[ty])

    @lru_cache(maxsize=None)
    def types(self, name, local):
        decl = re.compile(r"\b(" + ID + r")\s+(?:const\s+)?[*&]?\s*" + re.escape(name) + r"\b(?=\s*[=;,(\[)])")
        found = {m[1] for m in decl.finditer(local) if m[1] in self.classes}
        if not found:
            for code in self.files.values():
                if name in code:
                    found.update(m[1] for m in decl.finditer(code) if m[1] in self.classes)
        return found

    def declarations(self, types, pattern):
        for ty in sorted(types):
            for path, body in self.classes[ty]:
                m = re.search(pattern, body)
                if m:
                    yield path, m

    @lru_cache(maxsize=None)
    def getters(self, ty):
        items = []
        pattern = re.compile(r'\b(' + ID + r')\s*\(\s*(?:void\s*)?\)\s*const\s*\{\s*return\s*\(?\s*(?:this\s*->\s*)?(' + ID + r')\s*\)?\s*;\s*\}')
        for ancestor in sorted(self.ancestors(ty)):
            for path, body in self.classes[ancestor]:
                pairs = [(m[1], m[2]) for m in pattern.finditer(body) if m[2] not in ('true', 'false', 'NULL', 'this')]
                if pairs:
                    items.append((path, pairs))
        return items


def overloads(text, code, headers, local):
    # Vector(v.Get_X_Foo(), v.Get_Y_Foo(), v.Get_Z_Foo()) -> v.Get_Foo().
    axes = re.compile(rf"\b({ID})\s*\(\s*({ID})(\.|->)({ID})_X_({ID})\s*\(\s*\)\s*,\s*\2\3\4_Y_\5\s*\(\s*\)\s*,\s*\2\3\4_Z_\5\s*\(\s*\)\s*\)")
    for m in axes.finditer(code):
        aggregate = m[4] + "_" + m[5]
        decl = rf"\b{m[1]}\s+{aggregate}\s*\(\s*(?:void\s*)?\)"
        for path, _ in headers.declarations(headers.types(m[2], local), decl):
            yield m.start(), m.end(), m[2] + m[3] + aggregate + "()", "aggregate getter", str(path)

    # A callable object may implement conversion by forwarding to operator()().
    calls = re.compile(rf"\b({VALUE})\s*\(\s*\)(?=\s*(?:[%&|+*/-]|[),;]))")
    for m in calls.finditer(code):
        name = re.split(r"->|\.", m[1])[-1]
        types = headers.types(name, local)
        for ty in sorted(types):
            for path, body in headers.classes[ty]:
                if re.search(r"\boperator\s*\(\s*\)\s*\(\s*(?:void\s*)?\)", body):
                    for conv in re.finditer(r"\boperator\s+((?:unsigned\s+)?(?:int|long|short|bool|float|double))\s*\(\s*(?:void\s*)?\)", body):
                        yield m.start(), m.end(), m[1], f"implicit {conv[1]} conversion", str(path)
                        yield m.start(), m.end(), f"{m[1]}.operator {conv[1]}()", "explicit conversion", str(path)

    # Constrain inverse/product -> division to declared overloads for these operands.
    for m in re.finditer(rf"\b({ID})\s*\*\s*Inverse\s*\(\s*({ID})\s*\)", code):
        lhs, rhs = m[1], m[2]
        for ty in sorted(headers.types(lhs, local) & headers.types(rhs, local)):
            pattern = rf"\boperator\s*/\s*\(\s*(?:const\s+)?{ty}\b[^(),]*,\s*(?:const\s+)?{ty}\b"
            for path, header in headers.files.items():
                if re.search(pattern, header) or any(re.search(rf"\boperator\s*/\s*\(\s*(?:const\s+)?{ty}\b[^,()]*\)", b) for p, b in headers.classes[ty] if p == path):
                    yield m.start(), m.end(), f"{lhs} / {rhs}", "overloaded division", str(path)


def binary_operators(text, code, headers, local, translation):
    """Match a simple binary inline body against the first differing expression.

    Only operands that occur exactly once in a single return expression can be
    substituted. Resolve their declared types before proposing an overload.
    """
    param = rf"(?:const\s+)?({ID})(?:\s+const)?\s*&?\s*({ID})"
    operators = r"(==|!=|<=|>=|<<|>>|[+*/%&|^\-])"
    definition = re.compile(rf"\boperator\s*{operators}\s*\(\s*{param}\s*,\s*{param}\s*\)\s*\{{\s*return\s*([^;{{}}]+)\s*;\s*\}}")
    seen = set()
    for path, data in [*headers.files.items(), (None, translation)]:
        if "operator" not in data:
            continue
        for fn in definition.finditer(data):
            op, left_ty, left_name, right_ty, right_name, expr = fn.groups()
            if left_ty not in headers.classes and right_ty not in headers.classes:
                continue
            if left_name == right_name or (op,left_ty,right_ty,expr) in seen:
                continue
            if path is None:
                # A separate TU definition must also have a declaration in a
                # header; a same-named overload for another type is insufficient.
                signature = rf"\boperator\s*{re.escape(op)}\s*\(\s*(?:const\s+)?{left_ty}\b[^,()]*,\s*(?:const\s+)?{right_ty}\b"
                matches = [p for p,h in headers.files.items() if "operator" in h and re.search(signature, h)]
                if not matches:
                    continue
                evidence = matches[0]
            else:
                evidence = path
            seen.add((op,left_ty,right_ty,expr))
            expr = expr.strip()
            if expr.startswith("(") and closing(expr,0,"(",")") == len(expr)-1:
                expr = expr[1:-1]
            tokens = re.findall(r"[A-Za-z_]\w*|\d+|::|->|&&|\|\||==|!=|<<|>>|[^\s]", expr)
            if tokens.count(left_name) != 1 or tokens.count(right_name) != 1:
                continue
            if len(tokens) > 35 or any(t in ("?", "=", "++", "--", "new", "delete") for t in tokens):
                continue
            slots = {left_name: "lhs", right_name: "rhs"}
            chunks = [(rf"(?P<{slots[t]}>{ID})" if t in slots else re.escape(t)) for t in tokens]
            pattern = r"(?<!\w)" + r"\s*".join(chunks) + r"(?!\w)"
            for hit in re.finditer(pattern, code):
                lhs,rhs = hit["lhs"],hit["rhs"]
                if left_ty not in headers.types(lhs, local) or right_ty not in headers.types(rhs, local):
                    continue
                # Parenthesize compound replacement when used as a subexpression.
                new = f"({lhs} {op} {rhs})"
                if re.sub(r"\s+", "", new[1:-1]) != re.sub(r"\s+", "", hit[0]):
                    yield hit.start(), hit.end(), new, "call declared binary operator " + op, str(evidence)



def field_accessors(text, code, headers, local):
    """Replace a field read by a real zero-argument inline getter, or expand it."""
    use = re.compile(rf"\b({ID})(->|\.)({ID})(\s*\(\s*\))?")
    for m in use.finditer(code):
        receiver, access, name, call = m.groups()
        # Restrict this fast path to simple receivers and read contexts. A field
        # can be an lvalue even when a getter returning by value cannot.
        before = code[:m.start()].rstrip()
        if before.endswith((".", "->", "&")) or re.match(r"\s*(?:=(?!=)|\+=|-=|\+\+|--)", code[m.end():]):
            continue
        for ty in sorted(headers.types(receiver, local)):
            for path, pairs in headers.getters(ty):
                for getter, field in pairs:
                    if call and name == getter:
                        yield m.start(), m.end(), receiver+access+field, "expand inline getter", str(path)
                    elif not call and name == field:
                        yield m.start(), m.end(), receiver+access+getter+"()", "call inline getter", str(path)


def arithmetic_members(text, code, headers, local, translation, producers):
    """Expand simple const arithmetic members, preserving operator order.

    Use indexed access only when operator[](i) returns (&first_field)[i]
    and the header declares all referenced fields consecutively.
    """
    sites = []
    for call in re.finditer(rf"\b({ID})\.({ID})\s*\(\s*\)", code):
        receiver, method = call.groups()
        for ty in sorted(headers.types(receiver, local)):
            for path, cls in headers.classes[ty]:
                decl = re.search(rf"\b{method}\s*\(\s*(?:void\s*)?\)\s*const\s*\{{\s*return\s*([^;{{}}]+);\s*\}}", cls)
                if not decl:
                    continue
                expr = decl[1].strip()
                if expr.startswith("(") and closing(expr, 0, "(", ")") == len(expr)-1:
                    expr = expr[1:-1]
                if not re.fullmatch(rf"{ID}(?:\s*[-+*/]\s*{ID})+", expr):
                    continue
                fields = set(re.findall(ID, expr))
                scalar = r"(?:float|double|int|long|short)"
                if not all(re.search(rf"\b{scalar}\s+{f}\s*;", cls) for f in fields):
                    continue
                literal = re.sub(ID, lambda m: receiver + "." + m[0], expr)
                yield call.start(), call.end(), "(" + literal + ")", "expand arithmetic member", str(path)
                indexer = rf"\b{ty}\s*::\s*operator\s*\[\s*\]\s*\(\s*int\s+({ID})\s*\)\s*(?:const\s*)?\{{\s*return\s*\(\s*&\s*({ID})\s*\)\s*\[\s*\1\s*\]\s*;\s*\}}"
                definition = re.search(indexer, translation) or re.search(indexer, headers.files[path])
                if not definition:
                    continue
                run = re.search(rf"\b({scalar})\s+{definition[2]}\s*;(?:\s*\1\s+{ID}\s*;)*", cls)
                if not run:
                    continue
                order = re.findall(rf"\b{run[1]}\s+({ID})\s*;", run[0])
                if not fields.issubset(order):
                    continue
                indexed = "(" + re.sub(ID, lambda m: f"{receiver}[{order.index(m[0])}]", expr) + ")"
                yield call.start(), call.end(), indexed, "expand arithmetic member through subscript", str(path)
                sites.append((call.start(), call.end(), indexed, method, receiver, str(path)))
    # Pair neighboring calls of the same helper whose results are declared in
    # adjacent statements. Include their producers if these feed both receivers.
    for left, right in zip(sites, sites[1:]):
        gap = code[left[1]:right[0]]
        if left[3] != right[3] or not re.fullmatch(rf"\s*;\s*{ID}\s+{ID}\s*=\s*", gap):
            continue
        pair = left[2] + text[left[1]:right[0]] + right[2]
        yield left[0], right[1], pair, "expand paired arithmetic members through subscript", left[5]
        for start, stop, replacement, label, evidence in producers:
            if not label.startswith("paired ") or stop > left[0]:
                continue
            if not re.fullmatch(rf"\s*{ID}\s+{ID}\s*=\s*", code[stop:left[0]]):
                continue
            if all(re.search(rf"\b{v}\s*=(?!=)", replacement) for v in (left[4],right[4])):
                yield start, right[1], replacement+text[stop:left[0]]+pair, "paired operators and indexed member expansions", evidence



def operand_boundaries(text, code, headers, local):
    """Fold adjacent single-use operands into declared overload calls.

    The unary fold requires a literal match to the inline operator's return
    expression in the receiver's header. Also try adjacent folds together.
    """
    pattern = re.compile(rf"\b({ID})\s+({ID})\s*=\s*([^;{{}}]+?)\s*;\s*(\1\s+{ID}\s*=\s*)\2\s*\*\s*Inverse\s*\(\s*({ID})\s*\)\s*;")
    folds = []
    for m in pattern.finditer(code):
        ty, name, init, decl, rhs = m.groups()
        if len(re.findall(rf"\b{name}\b", code)) != 2 or ty not in headers.types(rhs, local):
            continue
        op = rf"\boperator\s*/\s*\(\s*(?:const\s+)?{ty}\b[^(),]*,\s*(?:const\s+)?{ty}\b"
        paths = [p for p,h in headers.files.items() if re.search(op,h)]
        if not paths:
            continue
        if re.fullmatch(rf"(?:\*\s*(?:this|{ID})|{ID})", init):
            operand = ty + "(" + init + ")"
        else:
            operand = None
            for _, h in headers.classes[ty]:
                for unary in re.finditer(r"\boperator\s*-\s*\(\s*(?:void\s*)?\)\s*(?:const\s*)?\{\s*return\s*(.*?)\s*;", h, re.S):
                    ret = unary[1].strip()
                    if ret.startswith("(") and closing(ret, 0, "(", ")") == len(ret)-1:
                        ret = ret[1:-1]
                    if re.sub(r"\s+", "", ret) == re.sub(r"\s+", "", init) and re.search(rf"\b{ty}\s*::", local[:local.find("{")]):
                        operand = "-*this"
                        break
            if operand is None:
                continue
        new = decl + operand + " / " + rhs + ";"
        yield m.start(), m.end(), new, "inline operand at division", str(paths[0])
        folds.append((m.start(), m.end(), new, paths[0]))
    for a,b in zip(folds, folds[1:]):
        if not code[a[1]:b[0]].strip():
            yield a[0], b[1], a[2]+text[a[1]:b[0]]+b[2], "paired inline operands at division", str(a[3])



def split_live(text, code):
    # A computed local is initially read, later replaced, then used again.
    # Keep the stable value for earlier consumers and a rolling copy for all
    # uses from the first assignment onward (including a conditional assignment).
    decls = re.compile(rf"(?m)^([ \t]*)([A-Za-z_]\w*(?:\s+(?:const|long|int))?\s*[*&]?)\s*?\b({ID})\s*=\s*([^;{{}}\n]+);")
    for m in decls.finditer(code):
        indent, ty, name = m[1], m[2].strip(), m[3]
        if ty in ("return", "else", "case", "if") or "&" in ty:
            continue
        block = enclosing_end(code, m.start())
        uses = list(re.finditer(rf"\b{re.escape(name)}\b", code[m.end():block]))
        assignments = [u for u in uses if re.match(r"\s*=(?!=)", code[m.end()+u.end():block])]
        if not assignments or not uses or assignments[0] == uses[0] or uses[-1] == assignments[0]:
            continue
        cut = m.end() + assignments[0].start()
        prefix_code = code[m.end():cut]
        if re.search(r"\bgoto\b", code[m.start():block]) or re.search(
            rf"\b{re.escape(name)}\s*(?:(?:\.|->){ID}\s*)?(?:\+\+|--|[+\-*/|&^]=|=(?!=))", prefix_code):
            continue
        # Text before a loop back edge can execute AFTER the assignment on a
        # later iteration. Such reads must continue to use the rolling value.
        repeats = False
        for loop in re.finditer(r"\b(?:for|while|do)\b", code[m.end():cut]):
            head = m.end() + loop.end()
            if loop[0] != "do":
                par = re.match(r"\s*\(", code[head:])
                if not par:
                    continue
                close = closing(code, head + par.end()-1, "(", ")")
                if close is None:
                    continue
                head = close+1
            brace = re.match(r"\s*\{", code[head:])
            stop = closing(code, head+brace.end()-1) if brace else code.find(";", head)
            if stop is not None and stop >= cut:
                repeats = True
                break
        if repeats:
            continue
        stable = fresh(code, name + "_initial")
        # Replace the initializer and the initial consumers with a stable name.
        # In paths skipping the assignment the rolling copy still holds the initial value.
        prefix = text[m.start():m.start(3)] + stable + text[m.end(3):m.end()]
        middle = text[m.end():cut]
        for u in reversed([u for u in uses if m.end()+u.start() < cut]):
            middle = middle[:u.start()] + stable + middle[u.end():]
        for label, init in (("copy initialization", f"{ty} {name} = {stable};"),
                            ("whole-value assignment", f"{ty} {name};\n{indent}{name} = {stable};")):
            yield m.start(), cut, prefix + "\n" + indent + init + middle, "stable and rolling values, " + label, None

    # Introduce an actually used typed value at a cast; group repeated same-block
    # uses only up to a write to the source. Also keep the single-site option.
    cast = re.compile(rf"\(\s*\(\s*({ID}(?:\s+const)?\s*[*&])\s*\)\s*({ID})\s*\)")
    for m in cast.finditer(code):
        start = code.rfind("\n", 0, m.start()) + 1
        line = code[start:m.start()].strip()
        if line.startswith(("else", "while", "for", "do", "case", "}")) or "{" in line or ";" in line:
            continue
        # Avoid splitting an unbraced controlled statement into two statements.
        prev = code[:start].rstrip()
        if prev and prev[-1] not in ";{}:":
            continue
        end = enclosing_end(code, m.start())
        write = re.search(rf"\b{m[2]}\s*(?:=(?!=)|[+\-]{{2}})", code[m.end():end])
        if write:
            end = m.end() + write.start()
        hits = [n for n in cast.finditer(code, m.start(), end) if n.groups() == m.groups()]
        name = fresh(code, m[2] + "_typed")
        for subset in [hits[:1], hits] if len(hits) > 1 else [hits]:
            stop = subset[-1].end()
            body = text[start:stop]
            for n in reversed(subset):
                body = body[:n.start()-start] + name + body[n.end()-start:]
            indent = line_indent(text, m.start())
            decl = f"{indent}{m[1]} {name} = ({m[1]}){m[2]};\n"
            yield start, stop, decl + body, "named cast for grouped uses", None


def enclosing_end(code, pos):
    depth = 0
    for m in re.finditer("[{}]", code[pos:]):
        if m[0] == "}" and depth == 0:
            return pos + m.start()
        depth += 1 if m[0] == "{" else -1
    return len(code)

def traversal_splits(text, code, headers):
    """Retain the producer's declared pointer type and narrow only derived uses."""
    decl = re.compile(rf"\b({ID})\s*\*\s*({ID})\s*=\s*\(\s*\1\s*\*\s*\)\s*([^;{{}}]+?(?:\.|->)({ID})\s*\([^;{{}}]*\))\s*;")
    for m in decl.finditer(code):
        derived, var, _producer, method = m.groups()
        returns = set()
        for header in headers.files.values():
            if method in header:
                returns.update(re.findall(rf"\b({ID})\s*\*\s*{method}\s*\(", header))
        if len(returns) != 1:
            continue
        base_type = returns.pop()
        if base_type == derived or base_type not in headers.ancestors(derived):
            continue
        base_members = headers.member_text(base_type)
        derived_members = headers.member_text(derived)
        end = enclosing_end(code, m.end())
        uses = list(re.finditer(rf"\b{var}\s*->\s*({ID})", code[m.end():end]))
        narrowed = [m.end()+u.start() for u in uses if not re.search(rf"\b{u[1]}\b", base_members) and re.search(rf"\b{u[1]}\b", derived_members)]
        if not narrowed:
            continue
        # Deepest enclosing block containing all derived uses without a write to
        # the traversal pointer. The narrowed value is refreshed on each visit.
        braces = [b.start() for b in re.finditer(r"\{", code[m.end():narrowed[0]])]
        for offset in reversed(braces):
            opening = m.end() + offset
            stop = closing(code, opening)
            if stop is None or stop < narrowed[-1] or re.search(rf"\b{var}\s*=(?!=)", code[opening:stop]):
                continue
            typed = fresh(code, var + "_typed")
            body = text[m.end():end]
            # Restore ordinary traversal assignments when they cast to the old type.
            edits = [(at, at+len(var), typed) for at in narrowed]
            for update in re.finditer(rf"\b{var}\s*=\s*(\(\s*{derived}\s*\*\s*\))\s*{var}\s*->", code[m.end():end]):
                edits.append((m.end()+update.start(1), m.end()+update.end(1), ""))
            # Insert after the brace's trailing comment, if present.
            insert = opening+1
            rest = text[insert:text.find("\n", insert) if "\n" in text[insert:] else len(text)]
            if not masked(rest).strip() and "\n" in text[insert:]:
                insert = text.index("\n", insert)+1
            indent = line_indent(text, opening)+"\t"
            edits.append((insert, insert, f"\n{indent}{derived} * {typed} = ({derived} *){var};\n"))
            for lft,rgt,replacement in sorted(edits, reverse=True):
                body = body[:lft-m.end()] + replacement + body[rgt-m.end():]
            new = f"{base_type} * {var} = {text[m.start(3):m.end(3)]};" + body
            yield m.start(), end, new, "base traversal with narrowed member uses", None
            break



def branch_split_merge(text, code):
    # if (a || b) return r; -> if (a) return r; if (b) return r; and inverse.
    predicate = re.compile(r"\bif\s*\(")
    sites = []
    for h in predicate.finditer(code):
        end = closing(code, h.end() - 1, "(", ")")
        if end is None:
            continue
        body = re.match(r"\s*(?:\{\s*(return\b[^;{}]*;)\s*\}|(return\b[^;{}]*;))", code[end+1:])
        if not body:
            continue
        stop = end + 1 + body.end()
        condition = text[h.end():end].strip()
        group = 1 if body[1] else 2
        result = text[end+1+body.start(group):end+1+body.end(group)].strip()
        sites.append((h.start(), stop, condition, result))
        # Parenthesized compound/nested conditions can be handled at another site.
        terms = re.fullmatch(r"([^(){}|&?]+?)\s*\|\|\s*([^(){}|&?]+)", condition) if masked(condition) == condition else None
        if terms:
            a, b = terms[1].strip(), terms[2].strip()
            indent = line_indent(text, h.start())
            # Preserve else association and the extent of unbraced enclosing statements.
            prev = code[:h.start()].rstrip()
            if re.match(r"\s*else\b", code[stop:]) or (prev and prev[-1] not in ";{}:"):
                continue
            new = f"if ({a}) {{\n{indent}\t{result}\n{indent}}}\n{indent}if ({b}) {{\n{indent}\t{result}\n{indent}}}"
            yield h.start(), stop, new, "split shared return", None
    for first, second in zip(sites, sites[1:]):
        if not code[first[1]:second[0]].strip() and first[3] == second[3]:
            prev = code[:first[0]].rstrip()
            if (prev and prev[-1] not in ";{}:") or re.match(r"\s*else\b", code[second[1]:]):
                continue
            def term(expr):
                return expr if re.fullmatch(r"[\w\s!.:<>=-]+", expr) else "(" + expr + ")"
            new = f"if ({term(first[2])} || {term(second[2])}) {{ {first[3]} }}"
            yield first[0], second[1], new, "merge identical returns", None

    # Select a pointer then call once -> make the decision around both complete
    # call expressions. Only inline a stable fallback/receiver, never repeat a call.
    selected = re.compile(rf"\b({ID})\s*\*\s*({ID})\s*=\s*(\(\s*\1\s*\*\s*\)\s*)?({ID})\s*;\s*"
                          rf"if\s*\(\s*\2\s*==\s*(NULL|0|nullptr)\s*\)\s*\{{\s*\2\s*=\s*({VALUE})\s*;\s*\}}\s*"
                          rf"({ID}\s*\([^;{{}}]*\b\2\b[^;{{}}]*\)\s*;)")
    for m in selected.finditer(code):
        if re.search(rf"\b{m[2]}\b", code[m.end():enclosing_end(code, m.end())]):
            continue
        indent = line_indent(text, m.start())
        expr = text[m.start(7):m.end(7)].strip()
        lhs = (m[3] or "") + m[4]
        left = re.sub(rf"\b{m[2]}\b", lambda _: lhs, expr)
        right = re.sub(rf"\b{m[2]}\b", lambda _: m[6], expr)
        yield m.start(), m.end(), (f"if ({m[4]} != {m[5]}) {{\n{indent}\t{left}\n"
                                   f"{indent}}} else {{\n{indent}\t{right}\n{indent}}}"), "split selected call", None

    # Merge common trailing statements of braced if/else arms into one tail.
    arms = re.compile(r"\bif\s*\([^;{}]*\)\s*\{([^{}]*)\}\s*else\s*\{([^{}]*)\}")
    for m in arms.finditer(code):
        left = re.search(r"(?:^|;)\s*([A-Za-z_][^;{}]*;)\s*$", m[1])
        right = re.search(r"(?:^|;)\s*([A-Za-z_][^;{}]*;)\s*$", m[2])
        if not left or not right or left[1].strip() != right[1].strip():
            continue
        if re.match(r"\s*else\b", code[m.end():]):
            continue
        start1 = m.start(1) + left.start(1)
        start2 = m.start(2) + right.start(1)
        common = text[start1:m.start(1) + left.end(1)]
        if common != text[start2:m.start(2) + right.end(1)]:
            continue
        # Braces keep an outer unbraced control around the entire arrangement.
        middle = text[m.start():start1] + text[m.start(1)+left.end(1):start2] + text[m.start(2)+right.end(1):m.end()]
        yield m.start(), m.end(), "{\n" + middle + "\n" + common + "\n}", "merge common branch tail", None


def fold_pointer(text):
    code = masked(text)
    sets = re.compile(rf"\b{ID}\s*\*\s*({ID})\s*=\s*({ID})\s*([-+])\s*({ID})\s*;")
    for m in sets.finditer(code):
        ptr, base, sign, disp = m.groups()
        stop = enclosing_end(code, m.end())
        tail = code[m.end():stop]
        refs = list(re.finditer(rf"\b{ptr}\b", tail))
        subs = list(re.finditer(rf"\b{ptr}\s*\[\s*(-?{ID})\s*\]", tail))
        if not refs or len(refs) != len(subs) or re.search(rf"\b(?:{base}|{disp})\s*(?:=(?!=)|\+\+|--|\+=|-=)", tail):
            continue
        new = text[m.end():]
        for s in reversed(subs):
            ix = s[1]
            offset = ("-" if sign == "-" else "") + disp
            op = " - " if ix.startswith("-") else " + "
            idx = f"{base}[{offset}{op}{ix.lstrip('-')}]"
            new = new[:s.start()] + idx + new[s.end():]
        yield text[:m.start()] + new


def centered_loops(text, code):
    """Recover a 2-D origin and share its coordinate variables with the walk."""
    pointer = re.compile(rf"\b(?:unsigned\s+|signed\s+)?(?:char|short|int|{ID})\s*\*\s*({ID})\s*=\s*([^;{{}}]+?)\s*\+\s*(0[xX][\da-fA-F]+|\d+)\s*;")
    countdown = re.compile(rf"\bfor\s*\(\s*int\s+({ID})\s*=\s*(\d+)\s*;\s*\1\s*>=\s*0\s*;\s*(?:\1--|--\1)\s*\)\s*\{{")
    for ptr in pointer.finditer(code):
        outer = countdown.match(code, re.compile(r"\s*").match(code, ptr.end()).end())
        if not outer:
            continue
        stop = closing(code, outer.end()-1)
        if stop is None:
            continue
        for inner in countdown.finditer(code, outer.end(), stop):
            end = closing(code, inner.end()-1)
            if end is None or end >= stop:
                continue
            y, x = outer[1], inner[1]
            x0, y0 = int(inner[2])+1, int(outer[2])+1
            shifts = re.findall(rf"\b{y}\s*<<\s*(\d+)", code[inner.end():end])
            shift = next((int(v) for v in shifts if int(v) < 31 and (y0 << int(v))+x0 == int(ptr[3],0)), None)
            if shift is None:
                continue
            # Both origin variables feed the pointer initializer, then act as
            # the visible offsets; never create a weight-only initializer.
            i = fresh(code, "i")
            indent = line_indent(text, ptr.start())
            inner_indent = line_indent(text, inner.start()) + "\t"
            prefix = f"int {x} = {x0};\n{indent}int {y} = {y0};\n{indent}"
            prefix += text[ptr.start():ptr.start(3)] + f"({y} << {shift}) + {x}"
            prefix += text[ptr.end(3):outer.start()]
            prefix += re.sub(r"\bint\s+(?=" + re.escape(y) + r"\b)", "", text[outer.start():outer.end()], count=1)
            prefix += text[outer.end():inner.start()]
            prefix += f"for (int {i} = 0; {i} <= {inner[2]}; {i}++) {{\n{inner_indent}{x} = {inner[2]} - {i};"
            body = text[inner.end():end]
            for label, choice in [("reuse origin indices", body), *(("reuse origin indices and fold mirror cursor", b) for b in fold_pointer(body))]:
                yield ptr.start(), stop+1, prefix + choice + text[end:stop+1], label, None


def bottom_up_rows(text, code):
    """Convert guarded row-count/stride recurrences to a 2-D indexed walk."""
    head = re.compile(rf"\bif\s*\(\s*(?P<h>{VALUE})\s*>\s*0\s*\)\s*\{{\s*"
                      rf"int\s+(?P<dest>{ID})\s*=\s*0\s*;\s*int\s+(?P<step>{ID})\s*=\s*-\s*(?P<pitch>{ID})\s*;\s*"
                      rf"int\s+(?P<src>{ID})\s*=\s*(?P=pitch)\s*\*\s*\(\s*(?P=h)\s*-\s*1\s*\)\s*;\s*"
                      rf"int\s+(?P<count>{ID})\s*=\s*(?P=h)\s*;\s*do\s*\{{\s*int\s+(?P<x>{ID})\s*=\s*0\s*;\s*"
                      rf"if\s*\(\s*(?P<w>{VALUE})\s*>\s*0\s*\)\s*\{{\s*do\s*\{{")
    for m in head.finditer(code):
        p = m.groupdict()
        end = closing(code, m.end()-1)
        if end is None:
            continue
        x, w, h = p["x"], p["w"], p["h"]
        tail = re.compile(rf"\}}\s*while\s*\(\s*{x}\s*<\s*{re.escape(w)}\s*\)\s*;\s*\}}\s*"
                          rf"{p['src']}\s*\+=\s*{p['step']}\s*;\s*{p['dest']}\s*\+=\s*({ID})\s*;\s*"
                          rf"{p['count']}\s*--\s*;\s*\}}\s*while\s*\(\s*{p['count']}\s*\)\s*;\s*\}}").match(code, end)
        update = re.search(rf"\b{x}\s*\+\+\s*;\s*$", code[m.end():end])
        if not tail or not update:
            continue
        body = text[m.end():m.end()+update.start()]
        bcode = masked(body)
        if not all(re.search(rf"\b{p[k]}\b", bcode) for k in ("src", "dest")):
            continue
        # Convert uses only inside the preserved body; reject unexpected writes,
        # escapes, transfers of control, and additional references to the counters.
        if re.search(rf"\b(?:{p['count']}|{p['step']}|goto|continue|break)\b", bcode):
            continue
        if re.search(rf"\b(?:{p['src']}|{p['dest']}|{x})\s*(?:[+\-*/]?=(?!=)|\+\+|--)", bcode):
            continue
        y = fresh(code, "y")
        row = fresh(code, "source_row")
        tmp = re.match(rf"\s*int\s+({ID})\s*=\s*{p['src']}\s*\+\s*{x}\s*;", bcode)
        if tmp and re.search(rf"\b{tmp[1]}\s*=(?!=)", bcode[tmp.end():]) is None:
            body = body[tmp.end():]
            body = replace_tokens(body, {tmp[1]: row+" + "+x})
        body = replace_tokens(body, {p["src"]: row, p["dest"]: y+" * "+tail[1]})
        indent = line_indent(text, m.start())
        first = f"for (int {y} = 0; {y} < {h}; {y}++) {{\n{indent}\tint {row} = ({h} - 1 - {y}) * {p['pitch']};"
        next_line = f"\n{indent}\tfor (int {x} = 0; {x} < {w}; {x}++) {{"
        new = first + next_line + body.rstrip() + f"\n{indent}\t}}\n{indent}}}"
        yield m.start(), tail.end(), new, "ascending rows and columns with derived bottom-up index", None


def replace_tokens(text, mapping):
    code = masked(text)
    names = re.compile(r"\b(?:" + "|".join(map(re.escape, mapping)) + r")\b")
    for m in reversed(list(names.finditer(code))):
        text = text[:m.start()] + mapping[m[0]] + text[m.end():]
    return text



def loop_family(text, code):
    yield from centered_loops(text, code)
    yield from bottom_up_rows(text, code)
    counted = re.compile(rf"\bfor\s*\(\s*int\s+({ID})\s*=\s*([^;]+?)\s*;\s*\1\s*(>=|<=|<)\s*([^;]+?)\s*;\s*(?:\1(\+\+|--)|(\+\+|--)\1)\s*\)\s*\{{")
    for m in counted.finditer(code):
        stop = closing(code, m.end()-1)
        if stop is None:
            continue
        name, initial, op, limit = m.groups()[:4]
        step = m[5] or m[6]
        if not re.fullmatch(r"\d+|[A-Za-z_]\w*", initial) or not re.fullmatch(r"\d+|[A-Za-z_]\w*", limit):
            continue
        if op == ">=" and limit == "0" and step == "--":
            top = initial
            counter = fresh(code, "i")
            header = f"int {counter} = 0; {counter} <= {top}; "
            dist = f"{top} - {counter}"
            advance = counter + "++"
        elif op in ("<", "<=") and initial == "0" and step == "++":
            top = limit if op == "<=" else f"{limit} - 1"
            counter = fresh(code, "remaining")
            header = f"int {counter} = {top}; {counter} >= 0; "
            dist = f"{top} - {counter}"
            advance = counter + "--"
        else:
            continue
        original = text[m.end():stop]
        bodycode = code[m.end():stop]
        if not re.search(rf"\b{name}\b", bodycode):
            continue
        if re.search(rf"\b{name}\s*(?:[+\-]{{2}}|[+\-*/]?=(?!=))", bodycode):
            continue
        if (not initial.isdecimal() and re.search(rf"\b{initial}\s*[+\-=]", bodycode)) or (not limit.isdecimal() and re.search(rf"\b{limit}\s*[+\-=]", bodycode)):
            continue
        indent = line_indent(text, m.start())
        inner = indent + "\t"
        for folded, body in [("", original), *((" + indexed cursor", t) for t in fold_pointer(original))]:
            for outer in (False, True):
                declaration = (f"int {name};\n{indent}" if outer else "")
                assignment = ("" if outer else "int ") + name + " = " + dist + ";"
                for update_in_body in (False, True):
                    if update_in_body and re.search(r"\b(?:continue|goto)\b", bodycode):
                        continue
                    update = "" if update_in_body else advance
                    tail = f"\n{inner}{advance};\n{indent}" if update_in_body else ""
                    new = declaration + f"for ({header}{update}) {{\n{inner}{assignment}" + body + tail + "}"
                    if outer:
                        new = "{\n" + indent + new + "\n" + indent + "}"
                    label = ("outer index" if outer else "loop-local index") + (", bottom update" if update_in_body else ", header update")
                    yield m.start(), stop+1, new, label + folded, None

    # A compact indexed-load sequence with an explicit cursor bump. Rewrite the
    # whole sequence in a loop, preserving the read order and net displacement.
    loads = re.compile(rf"\b({ID}\s+{ID}\s*=\s*)({ID})\s*\[\s*0\s*\]\s*;\s*({ID}\s+{ID}\s*=\s*)\2\s*\[\s*1\s*\]\s*;\s*\2\s*\+=\s*2\s*;")
    for m in loads.finditer(code):
        before = code[:m.start()]
        if not any(h.end() <= m.start() < (closing(code, h.end()-1) or 0) for h in counted.finditer(before)):
            continue
        new = m[1] + "*" + m[2] + "++;\n" + line_indent(text, m.start()) + m[3] + "*" + m[2] + "++;"
        yield m.start(), m.end(), new, "postincrement paired cursor reads", None


def generate(source, base_path, spec, spec_dir, include_dirs):
    code = masked(source)
    choices, diagnostics = [], []
    headers = None
    for item in spec.get("generators", []):
        cfg = {"name": item} if isinstance(item, str) else item
        name = cfg["name"]
        if name not in NAMES:
            raise ValueError("unknown generator: " + str(name))
        if name in ("overloads", "split_live") and headers is None:
            files = [Path(spec_dir) / f for f in spec.get("headers", [])]
            roots = [Path(spec_dir) / f for f in spec.get("include_dirs", [])]
            headers = HeaderIndex(Path(base_path), source, files, roots + list(map(Path, include_dirs)))
        names = [cfg["function"]] if "function" in cfg else list(dict.fromkeys(target_names(spec.get("targets", []))))
        if not names:
            raise ValueError(f"{name}: provide a function name or targets")
        line = cfg.get("line")
        if line is not None and (not isinstance(line, int) or line < 1 or line > code.count("\n") + 1):
            raise ValueError(f"{name}: invalid 1-based TU line {line}")
        for func in names:
            defs = list(definitions(code, func))
            if line is not None:
                defs = [(a,b) for a,b in defs if code.count("\n",0,a)+1 <= line <= code.count("\n",0,b)+1]
            if len(defs) != 1:
                diagnostics.append(f"{name}: {func} has {len(defs)} qualifying definitions; supply a unique name and line.")
                continue
            a,b = defs[0]
            body, clean = source[a:b], code[a:b]
            sites = defaultdict(dict)
            if name == "overloads":
                signature = code.rfind("}", 0, a)
                local = code[signature+1:b]
                producers = list(operand_boundaries(body, clean, headers, local))
                variants = chain(overloads(body, clean, headers, local), producers, arithmetic_members(body, clean, headers, local, code, producers),
                                 field_accessors(body, clean, headers, local), binary_operators(body, clean, headers, local, code))
            elif name == "split_live":
                variants = chain(traversal_splits(body, clean, headers), split_live(body, clean))
            elif name == "branch_split_merge":
                variants = branch_split_merge(body, clean)
            else:
                variants = loop_family(body, clean)
            for start, stop, replacement, label, evidence in variants:
                left, right = a + start, a + stop
                first = code.count("\n", 0, left) + 1
                last = code.count("\n", 0, right-1) + 1
                if line is not None and not first <= line <= last:
                    continue
                if replacement == source[left:right]:
                    continue
                option = {"label": label, "edits": [unique_edit(source, left, right, replacement)]}
                if evidence:
                    option["header"] = evidence
                sites[(first, left, right)][replacement] = option
            for (first, left, _), opts in sorted(sites.items()):
                column = left - source.rfind("\n", 0, left)
                choices.append({"name": f"{name}:{func}:{first}:{column}", "options": [{"label": "unchanged", "edits": []}, *opts.values()]})
            if not sites:
                diagnostics.append(f"{name}: no supported site in {func}" + (f" at line {line}" if line else ""))
    return choices, diagnostics


