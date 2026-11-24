"""COFF (i386) object matcher for level-2 byte matching.  Read-only on all inputs.

match_function(obj, symbol, original, va, resolve) compares one compiled function
(COMDAT section from /Gy) with the original bytes.  Relocated operands are masked
for the byte comparison and then checked separately: the original operand must
encode the address of the relocation's target symbol, as given by resolve(name).
Unknown targets (resolve returns None) are reported as required bindings; they
are never counted as verified.
"""
import struct

REL_DIR32, REL_DIR32NB, REL_REL32 = 0x06, 0x07, 0x14


class Obj:
    def __init__(self, data):
        self.data = data
        machine, nsec, _, symptr, nsym, optsz, _ = struct.unpack_from('<HHIIIHH', data, 0)
        if machine != 0x14c:
            raise ValueError('not an i386 COFF object')
        strtab = symptr + 18 * nsym
        self._strtab = strtab
        self.sections = []
        for i in range(nsec):
            o = 20 + optsz + 40 * i
            name = data[o:o + 8].rstrip(b'\0').decode('latin1')
            if name.startswith('/'):
                name = self._str(int(name[1:]))
            size, ptr, relptr, _, nrel, _, chars = struct.unpack_from('<IIIIHHI', data, o + 16)
            rels = [struct.unpack_from('<IIH', data, relptr + 10 * k) for k in range(nrel)]
            self.sections.append(dict(name=name, size=size, raw=data[ptr:ptr + size] if ptr else b'\0' * size,
                                      relocs=rels, chars=chars))
        self.symbols = {}
        self.by_index = {}
        i = 0
        while i < nsym:
            o = symptr + 18 * i
            raw = data[o:o + 8]
            name = self._str(struct.unpack_from('<I', raw, 4)[0]) if raw[:4] == b'\0\0\0\0' else raw.rstrip(b'\0').decode('latin1')
            value, secnum, typ, cls, aux = struct.unpack_from('<IhHBB', data, o + 8)
            sym = dict(name=name, value=value, section=secnum, type=typ, storage=cls)
            self.by_index[i] = sym
            if secnum > 0 and cls in (2, 3) and (typ >> 4) == 2:  # function symbols
                self.symbols.setdefault(name, sym)
            i += 1 + aux

    def _str(self, off):
        e = self.data.index(b'\0', self._strtab + off)
        return self.data[self._strtab + off:e].decode('latin1')

    def function(self, name):
        sym = self.symbols[name]
        sec = self.sections[sym['section'] - 1]
        if sym['value'] != 0:
            raise ValueError('function does not start its section; compile with /Gy')
        return sec


def match_function(obj, name, original, va, resolve):
    sec = obj.function(name)
    code = sec['raw']
    report = dict(function=name, va=hex(va), size=len(code), original_size=len(original))
    if len(code) != len(original):
        report.update(status='size_mismatch')
        return report
    masked = bytearray(len(code))
    bindings, problems = [], []
    for off, symidx, typ in sec['relocs']:
        target = obj.by_index[symidx]['name']
        if typ not in (REL_DIR32, REL_DIR32NB, REL_REL32):
            problems.append(dict(offset=off, error=f'unsupported relocation type {typ:#x}'))
            continue
        for k in range(4):
            masked[off + k] = 1
        addend = struct.unpack_from('<i', code, off)[0]
        value = struct.unpack_from('<I', original, off)[0]
        actual = (va + off + 4 + value) & 0xffffffff if typ == REL_REL32 else value
        expected_base = resolve(target)
        if expected_base is None:
            bindings.append(dict(offset=off, symbol=target, required_address=hex((actual - addend) & 0xffffffff)))
        elif (expected_base + addend) & 0xffffffff != actual:
            problems.append(dict(offset=off, symbol=target, expected=hex(expected_base + addend), original=hex(actual)))
    diffs = [i for i in range(len(code)) if not masked[i] and code[i] != original[i]]
    report.update(byte_differences=len(diffs), first_differences=[hex(i) for i in diffs[:16]],
                  relocations=len(sec['relocs']), unresolved_bindings=bindings, relocation_problems=problems)
    report['status'] = ('matched' if not diffs and not problems and not bindings else
                        'bytes_match_bindings_open' if not diffs and not problems else 'mismatch')
    return report
