#include "recovered/scanner_input.hpp"
#include "recovered/text_bytes.hpp"

namespace ra2::recovered {
std::uint32_t fun_007742c3(ScannerBuffer& s, const ScannerInputOperations& ops) {
    const auto flags = s.flags;
    if (!(flags & 0x83u) || (flags & 0x40u)) return 0xffffffffu;
    if (flags & 2u) { s.flags = flags | 0x20u; return 0xffffffffu; }
    s.flags = flags | 1u;
    if (!(flags & 0x10cu)) ops.allocate(s, ops.context);
    else s.cursor = s.base;
    const auto count = ops.read(s.descriptor, s.base, s.capacity, ops.context);
    s.remaining = count;
    if (count == 0 || count == 0xffffffffu) {
        s.flags |= count == 0 ? 0x10u : 0x20u;
        s.remaining = 0;
        return 0xffffffffu;
    }
    if (!(s.flags & 0x82u) && (ops.descriptor_flags(s.descriptor, ops.context) & 0x82u) == 0x82u)
        s.flags |= 0x2000u;
    if (s.capacity == 0x200u && (s.flags & 8u) && !(s.flags & 0x400u)) s.capacity = 0x1000u;
    s.remaining = count - 1u;
    return *s.cursor++;
}
std::uint32_t fun_00775d29(ScannerBuffer& s, const ScannerInputOperations& ops) {
    --s.remaining;
    if (!(s.remaining & 0x80000000u)) return *s.cursor++;
    return fun_007742c3(s, ops);
}
std::uint32_t fun_0077dd78(std::uint32_t value, ScannerBuffer& s, const ScannerInputOperations& ops) {
    if (value == 0xffffffffu || (!(s.flags & 1u) && (!(s.flags & 0x80u) || (s.flags & 2u))))
        return 0xffffffffu;
    if (!s.base) ops.allocate(s, ops.context);
    if (s.cursor == s.base) {
        if (s.remaining) return 0xffffffffu;
        ++s.cursor;
    }
    --s.cursor;
    if (!(s.flags & 0x40u)) *s.cursor = static_cast<std::uint8_t>(value);
    else if (*s.cursor != static_cast<std::uint8_t>(value)) {
        ++s.cursor;
        return 0xffffffffu;
    }
    ++s.remaining;
    s.flags = (s.flags & 0xffffffefu) | 1u;
    return value & 0xffu;
}
void fun_00775d43(std::uint32_t value, ScannerBuffer& s, const ScannerInputOperations& ops) {
    if (value != 0xffffffffu) (void)fun_0077dd78(value, s, ops);
}
std::uint32_t fun_00775d5a(std::uint32_t& consumed, ScannerBuffer& s,
                         const ScannerInputOperations& ops, const CrtClassification& ctype) {
    std::uint32_t value;
    do {
        ++consumed;
        value = fun_00775d29(s, ops);
    } while (fun_0076e521(value == 0xffffffffu ? -1 : static_cast<std::int32_t>(value), ctype));
    return value;
}
std::int32_t fun_0076f070(const std::uint8_t* text, const std::uint8_t* format,
                        void* arguments, ScannerCallback scan, void* context) {
    auto* buffer = const_cast<std::uint8_t*>(text);
    ScannerBuffer state{buffer, fun_00775160(text), buffer, 0x49u, 0, 0, 0};
    return scan(state, format, arguments, context);
}
}
