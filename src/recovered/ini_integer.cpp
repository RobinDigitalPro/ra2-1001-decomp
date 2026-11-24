#include "recovered/ini_integer.hpp"
#include "recovered/text_bytes.hpp"

namespace ra2::recovered {
namespace {
std::int32_t char_input(std::uint32_t v) {
    return v == 0xffffffffu ? -1 : static_cast<std::int32_t>(v);
}
}
std::int32_t scan_getter_hex32(ScannerBuffer& state, GetterHexFormat format,
                             std::uint32_t& output, const CrtClassification& ctype) {
    // The fixed memory flag takes the original refill's immediate-EOF branch;
    // the existing base prevents the pushback allocator branch.
    const ScannerInputOperations memory_ops{};
    if (format == GetterHexFormat::dollar_prefix) {
        const auto literal = fun_00775d29(state, memory_ops);
        if (literal != '$') {
            fun_00775d43(literal, state, memory_ops);
            return literal == 0xffffffffu ? -1 : 0;
        }
    }
    std::uint32_t consumed = 0;
    auto current = fun_00775d5a(consumed, state, memory_ops, ctype);
    const bool negative = current == '-';
    if (negative || current == '+') current = fun_00775d29(state, memory_ops);
    if (current == '0') {
        current = fun_00775d29(state, memory_ops);
        if (current == 'x' || current == 'X') current = fun_00775d29(state, memory_ops);
        else {
            fun_00775d43(current, state, memory_ops);
            current = '0';
        }
    }
    std::uint32_t value = 0;
    bool assigned = false;
    while (fun_0076e4f4(char_input(current), ctype)) {
        assigned = true;
        value = (value << 4) + fun_00775cf2(char_input(current), ctype) - 0x30u;
        current = fun_00775d29(state, memory_ops);
    }
    fun_00775d43(current, state, memory_ops);
    if (!assigned) return current == 0xffffffffu ? -1 : 0;
    output = negative ? 0u - value : value;
    if (format == GetterHexFormat::h_suffix && current != 0xffffffffu) {
        const auto literal = fun_00775d29(state, memory_ops);
        if (literal != 'h') fun_00775d43(literal, state, memory_ops);
    }
    return 1;
}
std::int32_t scan_getter_hex32_callback(ScannerBuffer& state, const std::uint8_t* format,
                                     void* output, void* context) {
    const auto& ctype = *static_cast<GetterHexContext*>(context)->classification;
    return scan_getter_hex32(state, format[0] == '$' ? GetterHexFormat::dollar_prefix
        : GetterHexFormat::h_suffix, *static_cast<std::uint32_t*>(output), ctype);
}
std::uint32_t fun_0050cc40(IniIndex* index, const std::uint8_t* section,
                         const std::uint8_t* key, std::uint32_t fallback,
                         const IntegerReadOperations& ops) {
    if (!section || !key) return fallback;
    auto* found_section = fun_0050be00(index, section, ops.lookup);
    if (!found_section) return fallback;
    auto* value = fun_0050f620(&found_section->keys, key, ops.lookup);
    if (!value || !value->text) return fallback;
    const auto* text = value->text;
    static constexpr std::uint8_t dollar[] = "$%x";
    static constexpr std::uint8_t suffix[] = "%xh";
    if (*text == '$') {
        (void)fun_0076f070(text, dollar, &fallback, ops.scan, ops.context);
        return fallback;
    }
    const auto length = fun_00775160(text);
    const auto last = *(text + length - 1); // Requires the documented prefix for empty text.
    const auto signed_last = last < 128 ? static_cast<std::int32_t>(last)
        : static_cast<std::int32_t>(last) - 256;
    if (ops.lowercase(signed_last, ops.context) == 'h') {
        (void)fun_0076f070(value->text, suffix, &fallback, ops.scan, ops.context);
        return fallback;
    }
    return fun_0076e73d(value->text, ops.decimal);
}
std::uint32_t fun_0050ce20(IniIndex* index, const IniByteString& section,
                         const IniByteString& key, std::uint32_t fallback,
                         const IntegerReadOperations& ops) {
    const auto* key_text = fun_0075a070(key);
    const auto* section_text = fun_0075a070(section);
    return fun_0050cc40(index, section_text, key_text, fallback, ops);
}
}
