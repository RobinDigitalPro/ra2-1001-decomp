#include "recovered/recovery_b940.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b940 {
namespace {
constexpr std::uint32_t kCpGlobal = 0x00b10ac8u;
constexpr std::uint32_t kLcidGlobal = 0x00b10ce4u;
constexpr std::uint32_t kTypeMode = 0x00b10714u;
constexpr std::uint32_t kMapMode = 0x00b1055cu;
constexpr std::uint32_t kMapTable = 0x00b10ae0u;
constexpr std::uint32_t kClassTable = 0x00b10be1u;
constexpr std::uint32_t kCount = 0x100u;

void require(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}
}

std::uint32_t fun_00777295(Memory& m, State& s, const Ops& op,
                           std::uint32_t frame_bp) {
    require(op.get_cp_info && op.locale.string_type_a && op.locale.map_a,
            "377295 requires GetCPInfo, GetStringTypeA and LCMapStringA forwarders");
    const auto codepage = m.r32(kCpGlobal);
    const auto lcid = m.r32(kLcidGlobal);
    require(codepage == 1252u,
            "377295 bounded route is current-host CP1252 only");
    require(lcid != 0u,
            "377295 requires nonzero explicit LCID");
    require(m.r32(kTypeMode) == 2u && m.r32(kMapMode) == 2u,
            "377295 requires the initialized B427 ANSI helper modes");
    for (std::uint32_t i = 0; i < kCount; ++i) {
        require(m.r8(kMapTable + i) == 0u,
                "377295 bounded route requires a fresh zero mapping table");
        require(m.r8(kClassTable + i) == 0u,
                "377295 bounded route requires a fresh zero classification table");
    }

    const auto cpinfo = frame_bp - 0x14u;
    const auto cpinfo_ok = op.get_cp_info(op.context, codepage, cpinfo);
    require(cpinfo_ok == 1u,
            "377295 excludes GetCPInfo failure");
    require(m.r32(cpinfo) == 1u,
            "377295 bounded route requires CPINFO.MaxCharSize=1");
    for (std::uint32_t i = 0; i < 12u; ++i)
        require(m.r8(cpinfo + 6u + i) == 0u,
                "377295 excludes multibyte LeadByte ranges");

    const auto source = frame_bp - 0x114u;
    const auto type_out = frame_bp - 0x514u;
    const auto lower_out = frame_bp - 0x214u;
    const auto upper_out = frame_bp - 0x314u;
    for (std::uint32_t i = 0; i < kCount; ++i)
        m.w8(source + i, i);
    m.w8(source, 0x20u);

    ra2::recovered::recovery_b427::State type{};
    type.arg[0] = 1u; // GetStringTypeA: CT_CTYPE1
    type.arg[1] = source;
    type.arg[2] = kCount;
    type.arg[3] = type_out;
    type.arg[4] = codepage; // original helper's extra caller word
    type.arg[5] = lcid;
    ra2::recovered::recovery_b427::fun_0077d5af(m, type, op.locale);

    ra2::recovered::recovery_b427::State lower{};
    lower.arg[0] = lcid;
    lower.arg[1] = 0x100u; // LCMAP_LOWERCASE
    lower.arg[2] = source;
    lower.arg[3] = kCount;
    lower.arg[4] = lower_out;
    lower.arg[5] = kCount; // original cchDest is ESI=256; codepage is helper arg6
    ra2::recovered::recovery_b427::fun_00774c82(m, lower, op.locale);

    auto upper = lower;
    upper.arg[1] = 0x200u; // LCMAP_UPPERCASE
    upper.arg[4] = upper_out;
    ra2::recovered::recovery_b427::fun_00774c82(m, upper, op.locale);

    // Original 0x77738b..0x7773ca tests C1_UPPER before C1_LOWER. The first
    // test maps uppercase input to lowercase output; the second maps lowercase
    // input to uppercase output. The fresh output flags array starts at zero.
    for (std::uint32_t ch = 0; ch < kCount; ++ch) {
        const auto ctype = m.r16(type_out + 2u * ch);
        if ((ctype & 0x0001u) != 0u) {
            m.w8(kClassTable + ch, m.r8(kClassTable + ch) | 0x10u);
            m.w8(kMapTable + ch, m.r8(lower_out + ch));
        } else if ((ctype & 0x0002u) != 0u) {
            m.w8(kClassTable + ch, m.r8(kClassTable + ch) | 0x20u);
            m.w8(kMapTable + ch, m.r8(upper_out + ch));
        } else {
            m.w8(kMapTable + ch, 0u);
        }
    }

    s.ax = 0x100u;
    return s.ax;
}
}
