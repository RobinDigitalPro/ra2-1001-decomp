#include "recovery_b344.hpp"

#include "recovered/crt_b83.hpp"
#include "recovered/global_b27_memory.hpp"
#include "recovered/leaf_b21_a.hpp"

#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b344 {
namespace {
constexpr std::uint32_t result_flag = 0x00b10708u;
constexpr std::uint32_t selected_locale = 0x00b1070cu;
constexpr std::uint32_t current_locale = 0x00b106f0u;
constexpr std::uint32_t comparison_text = 0x00b10704u;
constexpr std::uint32_t locale_info_type = 0x00b106f4u;

std::uint32_t is_excluded_locale(Memory& m, std::uint32_t lcid) {
    for (const auto& entry : global_b27::entries_c()) {
        if (entry.rva == 0x37b41au && entry.function) {
            global_b27::State state{};
            state.arg[0] = lcid;
            entry.function(m, state);
            return state.ax;
        }
    }
    throw std::logic_error("accepted 0x37b41a helper is not linked");
}

std::uint32_t parse_lcid_hex(Memory& m, std::uint32_t p) {
    // Adapt the multi-span read interface to the accepted single-span helper.
    // This draft's finite inputs are short NUL-terminated hex strings; the
    // copy preserves every byte that 0x77b5b7 reads and does not mutate input.
    std::array<std::uint8_t,256> bytes{};
    std::uint32_t size=0;
    for (;size<bytes.size();++size) {
        bytes[size]=static_cast<std::uint8_t>(m.r8(p+size));
        if (!bytes[size]) { ++size; break; }
    }
    if (!size || (size==bytes.size() && bytes.back()!=0))
        throw std::domain_error("finite draft input must be a NUL-terminated hex string under 256 bytes");
    leaf::Memory copy(bytes.data(),p,size);
    leaf::Inputs input{};input.arg[0]=p;
    return leaf::fun_0077b5b7(copy,input);
}
}

void fun_0077b314(Memory& m, State& s, const LocaleInfoAForwarder& api) {
    if (!api.call) throw std::invalid_argument("actual GetLocaleInfoA forwarder required");

    const auto saved_si = s.si;
    s.si = parse_lcid_hex(m, s.arg[0]);

    // Original NEG/SBB yields 0 or FFFFFFFF; AND modifies AX only, retaining
    // the upper half, then the 32-bit add wraps FFFFF005+1002 to 7.
    const auto source = m.r32(locale_info_type);
    std::uint32_t eax = source ? 0xffffffffu : 0u;
    eax = (eax & 0xffff0000u) | ((eax & 0xffffu) & 0xf005u);
    const auto lctype = eax + 0x1002u;

    const auto buffer = s.bp - 0x78u;
    s.ax = api.call(api.context, s.si, lctype, buffer, 0x78u);
    if (!s.ax) {
        m.w32(result_flag, 0);
        s.ax = 1;
    } else {
        global_b26::Inputs compare{};
        compare.arg[0] = buffer;
        compare.arg[1] = m.r32(comparison_text);
        if (crt_b83::fun_0076d860(m, compare) == 0u &&
            is_excluded_locale(m, s.si)) {
            m.w32(result_flag, m.r32(result_flag) | 4u);
            m.w32(selected_locale, s.si);
            m.w32(current_locale, s.si);
        }
        s.ax = ((~m.r32(result_flag)) >> 2) & 1u;
    }
    s.si = saved_si;
}
}
