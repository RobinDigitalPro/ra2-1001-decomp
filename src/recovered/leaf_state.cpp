#include "leaf_state.hpp"
#include <initializer_list>

namespace ra2::recovered::leaf {

std::uint32_t fun_00406580(Memory& m, const Inputs& in) {
    const auto flags = in.dx;
    m.w32(in.cx + 0x10u, flags);
    if ((flags & 0x20u) != 0) {
        if (m.r32(in.cx + 0x138u) == 0) m.w32(in.cx + 0x138u, 1);
    } else {
        m.w32(in.cx + 0x138u, 0);
    }
    if ((flags & 0x40u) != 0) {
        if (m.r32(in.cx + 0x13cu) == 0) m.w32(in.cx + 0x13cu, 1);
    } else {
        m.w32(in.cx + 0x13cu, 0);
    }
    return 1;
}

std::uint32_t fun_00406630(Memory& m, const Inputs& in) {
    const auto value = s32(in.dx);
    if (value > 100) m.w32(in.cx + 0x68u, 100);
    else if (value < 0) m.w32(in.cx + 0x68u, 0);
    else m.w32(in.cx + 0x68u, in.dx);
    return 0;
}

std::uint32_t fun_0062a820(Memory& m, const Inputs& in) {
    return m.r32(in.cx + 0x14acu) == 2 && m.r32(in.cx + 0x14a8u) == 1 ? 1u : 0u;
}

std::uint32_t fun_00508520(Memory& m, const Inputs& in) {
    const auto value = m.r32(in.cx + 0x5acu);
    return value >= 0x1bu && value <= 0x1eu ? 1u : 0u;
}

std::uint32_t fun_0047b190(Memory& m, const Inputs& in) {
    const auto value = m.r32(in.cx + 0x38u);
    return value == 0 || value == 0xffffu ? 1u : 0u;
}

std::uint32_t fun_006dc010(Memory& m, const Inputs& in) {
    const auto value = m.r32(in.cx + 0x2cu);
    return value == 1 || value == 6 || value == 44 ? 0u : 1u;
}

std::uint32_t fun_00401f90(Memory& m, const Inputs& in) {
    const auto decremented = m.r32(in.cx + 0x0cu) - 1u;
    m.w32(in.cx + 0x0cu, s32(decremented) < 0 ? 0u : decremented);
    return decremented;
}

std::uint32_t fun_00591b80(Memory& m, const Inputs& in) {
    const auto value = m.r32(in.cx + 0x9cu);
    if (value == 0xffffffffu) return 0;
    m.w32(in.cx + 0x98u, value);
    m.w32(in.cx + 0x9cu, 0xffffffffu);
    m.w8(in.cx + 0xa4u, 0);
    return 1;
}

std::uint32_t fun_004e4ae0(Memory& m, const Inputs& in) {
    const auto previous = m.r32(in.cx + 0x24cu);
    const auto result = previous + in.arg[0];
    m.w32(in.cx + 0x24cu, result);
    return in.arg[0];
}

std::uint32_t fun_00401170(Memory& m, const Inputs& in) {
    for (const auto offset : {0u, 0x50u, 0x28u})
        m.w32(in.cx + offset, m.r32(in.cx + offset) & 0xfffffffdu);
    return 0xfffffffdu;
}

std::uint32_t fun_00664ea0(Memory& m, const Inputs& in) {
    if (m.r32(in.cx + 0x55u) != 0xfffffffeu) return m.r32(in.cx + 0x51u);
    const auto value = m.r32(in.cx + 0x51u);
    return value == 0xffffffffu ? 0xfffffffeu : value;
}

std::uint32_t fun_00664e80(Memory& m, const Inputs& in) {
    return m.r32(in.cx + 0x4du) == 0xfffffffeu ? 0xfffffffeu : m.r32(in.cx + 0x49u);
}

std::uint32_t fun_00664ec0(Memory& m, const Inputs& in) {
    const auto value = in.arg[0];
    if (value == 0xfffffffeu) {
        m.w32(in.cx + 0x49u, 0);
        m.w32(in.cx + 0x4du, value);
    } else {
        m.w32(in.cx + 0x49u, value);
        m.w32(in.cx + 0x4du, 0xffffffffu);
    }
    return value;
}

std::uint32_t fun_00530c00(Memory& m, const Inputs& in) {
    return (m.r32(in.cx + 0x314u) == m.r32(in.cx + 0x318u)) ? 1u : 0u;
}

std::uint32_t fun_004084d0(Memory& m, const Inputs& in) {
    auto product = m.r32(in.cx + 0x10u) * m.r32(in.cx + 0x0cu);
    product *= m.r32(in.cx + 0x08u);
    if (m.r32(in.cx + 0x04u) == 1 || m.r32(in.cx + 0x04u) == 2) product = sar(product, 2);
    m.w32(in.cx + 0x14u, product);
    return product;
}

std::uint32_t fun_0047bec0(Memory& m, const Inputs& in) {
    const auto shift = in.arg[0] & 31u;
    const auto bit = std::uint32_t{1} << shift;
    return (m.r32(in.cx + 0x78u) & bit) != 0 ? 1u : 0u;
}

std::uint32_t fun_0047bf20(Memory& m, const Inputs& in) {
    const auto bit = std::uint32_t{1} << (in.arg[0] & 31u);
    m.w32(in.cx + 0x78u, m.r32(in.cx + 0x78u) | bit);
    return in.cx;
}

std::uint32_t fun_0047bf40(Memory& m, const Inputs& in) {
    const auto bit = std::uint32_t{1} << (in.arg[0] & 31u);
    m.w32(in.cx + 0x78u, m.r32(in.cx + 0x78u) & ~bit);
    return in.cx;
}

std::uint32_t fun_00680af0(Memory& m, const Inputs& in) {
    const auto difference = m.r32(in.arg[0]) ^ m.r32(in.cx);
    return (difference & 0x0007ffffu) == 0 ? 1u : 0u;
}

std::uint32_t fun_006068a0(Memory& m, const Inputs& in) {
    const auto difference = m.r32(in.cx + 0x38u) - in.arg[0];
    m.w32(in.cx + 0x38u, s32(difference) > 0 ? difference : 0u);
    return s32(difference) > 0 ? 0u : 1u;
}

std::uint32_t fun_004b9570(Memory& m, const Inputs& in) {
    if (m.r32(in.cx + 0x54u) != 0 && m.r32(in.cx + 0x24u) == 0x36u) return 1;
    if (m.r32(in.cx + 0x64u) != 0xffffffffu && m.r32(in.cx + 0x24u) == 0x36u) return 1;
    return 0;
}

std::uint32_t fun_007080a0(Memory& m, const Inputs& in) {
    const auto value = in.arg[0] & 0xffu;
    m.w32(in.cx, 0);
    m.w32(in.cx + 0x04u, value != 0 ? 0xbfd00000u : 0u);
    return value;
}

std::uint32_t fun_00406660(Memory& m, const Inputs& in) {
    return ((m.r8(in.cx + 0x10u) & 1u) != 0 && m.r32(in.cx + 0x4cu) == 0) ? 1u : 0u;
}

std::uint32_t fun_0062a860(Memory& m, const Inputs& in) {
    const auto old = m.r8(in.cx + 0x14d6u);
    m.w8(in.cx + 0x14d5u, 1);
    const auto value = old != 0 ? 1u : (in.arg[0] & 0xffu) != 0 ? 1u : 0u;
    m.w8(in.cx + 0x14d6u, value);
    return value;
}

std::uint32_t fun_0053b1a0(Memory& m, const Inputs& in) {
    m.w32(in.cx + 0x08u, 0);
    m.w32(in.cx + 0x0cu, 0);
    m.w8(in.cx + 0x10u, 1);
    m.w8(in.cx + 0x11u, 1);
    m.w32(in.cx + 0x14u, 0);
    m.w32(in.cx, 0x78e3b4u);
    m.w32(in.cx + 0x04u, 0x78e2ecu);
    return in.cx;
}

std::uint32_t fun_0048de20(Memory& m, const Inputs& in) {
    m.w32(in.cx + 0x14u, 0xfffffffeu);
    m.w32(in.cx + 0x30u, 0xfffffffeu);
    m.w32(in.cx + 0x18u, 0xfffffffeu);
    m.w32(in.cx + 0x34u, 0xfffffffeu);
    m.w8(in.cx, 0);
    m.w8(in.cx + 0x1cu, 0);
    m.w32(in.cx + 0x3cu, 0);
    m.w32(in.cx + 0x44u, 0xffffffffu);
    m.w8(in.cx + 0x6cu, 0);
    m.w32(in.cx + 0x40u, 0);
    m.w32(in.cx + 0x38u, 0xffffffffu);
    for (const auto offset : {0x48u, 0x4cu, 0x50u, 0x54u, 0x58u, 0x5cu, 0x68u, 0x60u, 0x64u})
        m.w32(in.cx + offset, 0);
    return in.cx;
}

std::uint32_t fun_00690440(Memory& m, const Inputs& in) {
    m.w32(in.cx, 0);
    m.w32(in.cx + 0x04u, 0);
    m.w32(in.cx + 0x08u, 0);
    m.w32(in.cx + 0x0cu, 0);
    return in.cx;
}

std::uint32_t fun_0047c500(Memory& m, const Inputs& in) {
    auto result = m.r32(in.cx + 0x12cu) | 0x18u;
    m.w32(in.cx + 0x12cu, result);
    result = m.r32(in.cx + 0x130u);
    if (s32(result) > 0) {
        result = m.r32(in.cx + 0x140u) | 0x20u;
        m.w32(in.cx + 0x140u, result);
    }
    return result;
}

std::uint32_t fun_00407080(Memory& m, const Inputs& in) {
    const auto value = m.r32(in.cx) | 1u;
    m.w32(in.cx, value);
    m.w32(in.cx + 0x08u, in.dx << 16);
    return value;
}

std::uint32_t fun_006300e0(Memory& m, const Inputs& in) {
    m.w32(in.cx + 0x0cu, 0xffffffffu);
    m.w32(in.cx + 0x10u, 0xffffffffu);
    m.w32(in.cx + 0x04u, 0);
    m.w32(in.cx + 0x08u, 0);
    m.w32(in.cx + 0x14u, in.arg[0]);
    m.w16(in.cx + 0x18u, 0);
    m.w16(in.cx + 0x1au, 0);
    m.w8(in.cx + 0x1cu, 0);
    m.w32(in.cx, 0x793c84u);
    return in.cx;
}

}
