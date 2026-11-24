#include "recovered/ini_multi.hpp"
#include "recovered/ini_text.hpp"

namespace ra2::recovered {
std::int32_t scan_getter_decimal_fields(ScannerBuffer& state, GetterDecimalFormat format,
    const DecimalFieldOutputs& output, const CrtClassification& ctype) {
    const ScannerInputOperations memory_ops{};
    const bool time = format == GetterDecimalFormat::time_hms;
    const unsigned fields = format == GetterDecimalFormat::two_csv ? 2
        : format == GetterDecimalFormat::four_csv ? 4 : 3;
    std::int32_t assigned = 0;
    for (unsigned field = 0; field < fields; ++field) {
        std::uint32_t consumed = 0;
        auto current = fun_00775d5a(consumed, state, memory_ops, ctype);
        unsigned width = time ? 2u : 0u;
        const bool negative = current == '-';
        if (negative || current == '+') {
            if (time) --width; // Sign counts toward the original %02d width.
            current = fun_00775d29(state, memory_ops);
        }
        std::uint32_t value = 0;
        bool digits = false, width_exhausted = false;
        while (fun_0076e4cc(current == 0xffffffffu ? -1 : static_cast<std::int32_t>(current), ctype)) {
            digits = true;
            value = value * 10u + current - '0';
            if (time && --width == 0) { width_exhausted = true; break; }
            current = fun_00775d29(state, memory_ops);
        }
        // A width stop has already consumed its last digit, with no lookahead.
        if (!width_exhausted) fun_00775d43(current, state, memory_ops);
        if (!digits) return assigned == 0 && current == 0xffffffffu ? -1 : assigned;
        *output.fields[field] = negative ? 0u - value : value;
        ++assigned;
        if (current == 0xffffffffu || field + 1 == fields) return assigned;
        const auto literal = fun_00775d29(state, memory_ops);
        if (literal != static_cast<std::uint32_t>(time ? ':' : ',')) {
            fun_00775d43(literal, state, memory_ops);
            return assigned;
        }
    }
    return assigned;
}
std::int32_t scan_getter_decimal_callback(ScannerBuffer& state, const std::uint8_t* format,
                                        void* arguments, void* context) {
    const auto kind = format[1] == '0' ? GetterDecimalFormat::time_hms
        : format[5] == 0 ? GetterDecimalFormat::two_csv
        : format[8] == 0 ? GetterDecimalFormat::three_csv : GetterDecimalFormat::four_csv;
    return scan_getter_decimal_fields(state, kind, *static_cast<DecimalFieldOutputs*>(arguments),
        *static_cast<GetterDecimalContext*>(context)->classification);
}
std::uint32_t fun_0050f8b0(IniIndex* index, const std::uint8_t* section,
    const std::uint8_t* key, std::uint32_t fallback, const MultiIntegerReadOperations& ops) {
    if (!section || !key) return fallback;
    auto* found_section = fun_0050be00(index, section, ops.lookup);
    if (!found_section) return fallback;
    auto* value = fun_0050f620(&found_section->keys, key, ops.lookup);
    if (!value || !value->text) return fallback;
    std::uint32_t hours = 0, minutes = 0, seconds = 0;
    DecimalFieldOutputs fields{{&hours, &minutes, &seconds, nullptr}};
    static constexpr std::uint8_t format[] = "%02d:%02d:%02d";
    (void)fun_0076f070(value->text, format, &fields, ops.scan, ops.context);
    return ((hours * 60u + minutes) * 60u + seconds) * 60u;
}
namespace {
bool four_text(IniIndex* index, const std::uint8_t* section, const std::uint8_t* key,
               std::uint8_t (&text)[64], const MultiIntegerReadOperations& ops) {
    static constexpr std::uint8_t missing[] = "0,0,0,0";
    return fun_0050ddf0(index, section, key, missing, text, 64, ops.lookup) != 0;
}
void scan_four(std::uint8_t* text, std::uint32_t (&words)[4], const MultiIntegerReadOperations& ops) {
    DecimalFieldOutputs fields{{words, words+1, words+2, words+3}};
    static constexpr std::uint8_t format[] = "%d,%d,%d,%d";
    (void)fun_0076f070(text, format, &fields, ops.scan, ops.context);
}
}
std::uint32_t* fun_0050d1a0(IniIndex* index, std::uint32_t* output,
    const std::uint8_t* section, const std::uint8_t* key, const std::uint32_t* fallback,
    const MultiIntegerReadOperations& ops) {
    std::uint8_t text[64];
    if (four_text(index, section, key, text, ops)) {
        std::uint32_t words[4]{fallback[0],fallback[1],fallback[2],fallback[3]};
        scan_four(text, words, ops);
        for (unsigned i=0; i<4; ++i) output[i]=words[i];
    } else {
        for (unsigned i=0; i<4; ++i) output[i]=fallback[i];
    }
    return output;
}
std::uint32_t* fun_0050d3c0(IniIndex* index, std::uint32_t* output,
    const IniByteString& section, const IniByteString& key, const std::uint32_t* fallback,
    const MultiIntegerReadOperations& ops) {
    const auto* key_text = fun_0075a070(key);
    const auto* section_text = fun_0075a070(section);
    std::uint8_t text[64];
    const bool have_text = four_text(index, section_text, key_text, text, ops);
    std::uint32_t words[4]{fallback[0],fallback[1],fallback[2],fallback[3]};
    if (have_text) scan_four(text, words, ops);
    for (unsigned i=0; i<4; ++i) output[i]=words[i];
    return output;
}
}
