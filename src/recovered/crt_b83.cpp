#include "recovered/crt_b83.hpp"

#include "recovered/text_bytes.hpp"
#include "recovered/text_scan.hpp"

#include <array>
#include <cstdint>

namespace ra2::recovered::crt_b83 {
namespace {
constexpr std::uint32_t mode = 0x00b10530u;

std::uint8_t lower(std::uint8_t c) {
    return c >= 'A' && c <= 'Z' ? static_cast<std::uint8_t>(c + 0x20u) : c;
}
std::uint8_t upper(std::uint8_t c) {
    return c >= 'a' && c <= 'z' ? static_cast<std::uint8_t>(c - 0x20u) : c;
}
std::uint16_t lower16(std::uint16_t c) {
    return c >= 'A' && c <= 'Z' ? static_cast<std::uint16_t>(c + 0x20u) : c;
}
std::uint16_t upper16(std::uint16_t c) {
    return c >= 'a' && c <= 'z' ? static_cast<std::uint16_t>(c - 0x20u) : c;
}
std::int32_t signed32(std::uint32_t v) { return global_b26::s32(v); }

} // namespace

std::uint32_t fun_0076d860(Memory& m, const Inputs& i) {
    (void)m.r32(mode); // The finite contract selects the local mode-zero route.
    std::uint32_t a = i.arg[0], b = i.arg[1];
    for (unsigned n = 0; n < 8; ++n) {
        const auto x = static_cast<std::uint8_t>(m.r8(a++));
        const auto y = static_cast<std::uint8_t>(m.r8(b++));
        if (x == y) {
            if (!x) return 0;
            continue;
        }
        const auto lx = lower(x), ly = lower(y);
        if (lx != ly) return lx < ly ? 0xffffffffu : 1u;
        if (!lx) return 0;
    }
    return 0;
}

std::uint32_t fun_0076e382(Memory& m, const Inputs& i) {
    if (m.r32(mode) == 0) {
        const auto c = signed32(i.arg[0]);
        return (c >= 'a' && c <= 'z') ? i.arg[0] - 32u : i.arg[0];
    }
    return i.arg[0];
}

std::uint32_t fun_0076fba3(Memory& m, const Inputs& i) {
    if (m.r32(mode) == 0) {
        const auto c = signed32(i.arg[0]);
        return (c >= 'A' && c <= 'Z') ? i.arg[0] + 32u : i.arg[0];
    }
    return i.arg[0];
}

std::uint32_t fun_00770d09(Memory& m, const Inputs& i) {
    (void)m.r32(mode);
    const auto dst = i.arg[0], src = i.arg[1], count = i.arg[2];
    std::uint32_t n = 0;
    for (; n < count; ++n) {
        const auto c = m.r8(src + n);
        m.w16(dst + n * 2u, c);
        if (!c) return n;
    }
    return count;
}

std::uint32_t fun_007711d0(Memory& m, const Inputs& i) {
    (void)m.r32(mode);
    auto a = i.arg[0], b = i.arg[1];
    const auto count = i.arg[2];
    std::uint8_t x = 0, y = 0;
    for (std::uint32_t n = 0; n < count; ++n) {
        x = static_cast<std::uint8_t>(m.r8(a++));
        y = static_cast<std::uint8_t>(m.r8(b++));
        const auto lx = lower(x), ly = lower(y);
        if (lx != ly) return lx < ly ? 0xffffffffu : 1u;
        if (!x || !y) return 0;
    }
    // The original final AL comparison is reached after count exhaustion.
    const auto lx = lower(x), ly = lower(y);
    return lx == ly ? 0u : (lx < ly ? 0xffffffffu : 1u);
}

std::uint32_t fun_00777446(Memory& m, const Inputs& i) {
    (void)m.r32(0x00b10adcu);
    const auto dst = i.arg[0], src = i.arg[1], count = i.arg[2];
    std::array<std::uint8_t, 64> source{}, destination{};
    for (std::uint32_t n = 0; n < count; ++n) source[n] = static_cast<std::uint8_t>(m.r8(src + n));
    (void)ra2::recovered::fun_0076dd10(destination.data(), source.data(), count);
    for (std::uint32_t n = 0; n < count; ++n) m.w8(dst + n, destination[n]);
    i.arg[0] = dst;
    return dst;
}

std::uint32_t fun_0077dc62(Memory& m, const Inputs& i) {
    (void)m.r32(mode);
    const auto value = m.r8(i.arg[1]);
    m.w16(i.arg[0], value);
    return 1;
}

std::uint32_t fun_0077e9a4(Memory& m, const Inputs& i) {
    (void)m.r32(mode);
    const auto dst = i.arg[0], src = i.arg[1], count = i.arg[2];
    std::uint32_t n = 0;
    for (; n < count; ++n) {
        const auto c = m.r16(src + 2u * n);
        m.w8(dst + n, c & 0xffu);
        if (!c) return n;
    }
    return count;
}

std::uint32_t fun_00780eca(Memory& m, const Inputs& i) {
    (void)m.r32(0x00b10adcu);
    const auto text = i.arg[0];
    std::array<std::uint8_t, 69> bytes{};
    for (unsigned n = 0; n < 69; ++n) bytes[n] = static_cast<std::uint8_t>(m.r8(text + n));
    const auto* found = ra2::recovered::fun_0076fa70(bytes.data(), static_cast<std::int32_t>(i.arg[1]));
    return found ? text + static_cast<std::uint32_t>(found - bytes.data()) : 0u;
}

std::uint32_t fun_00781b14(Memory& m, const Inputs& i) {
    (void)m.r32(mode);
    const auto original = i.arg[0];
    auto p = original;
    for (unsigned n = 0; n < 65; ++n) {
        const auto c = static_cast<std::uint8_t>(m.r8(p));
        if(upper(c)!=c) m.w8(p, upper(c));
        ++p;
        if (!c) break;
    }
    return original;
}

std::uint32_t fun_00781c48(Memory& m, const Inputs& i) {
    (void)m.r32(mode);
    auto a = i.arg[0], b = i.arg[1];
    const auto high = i.ax & 0xffff0000u;
    for (unsigned n = 0; n < 33; ++n) {
        const auto first = lower16(static_cast<std::uint16_t>(m.r16(a)));
        const auto first_eax = high | first;
        i.arg[1] = first_eax;
        const auto second = lower16(static_cast<std::uint16_t>(m.r16(b)));
        const auto second_eax = high | second;
        i.arg[0] = second_eax;
        ++a; ++b; ++a; ++b;
        if (first != second) return std::uint32_t(first) - std::uint32_t(second);
        if (!first) return 0;
    }
    return 0;
}

std::uint32_t fun_00782826(Memory& m, const Inputs& i) {
    (void)m.r32(mode);
    const auto original = i.arg[0];
    auto p = original;
    for (unsigned n = 0; n < 33; ++n) {
        const auto c = static_cast<std::uint16_t>(m.r16(p));
        const auto converted = upper16(c);
        if (converted != c) m.w16(p, converted);
        p += 2;
        if (!c) break;
    }
    return original;
}

std::uint32_t fun_007829d0(Memory& m, const Inputs& i) {
    (void)m.r32(mode);
    auto a = i.arg[0], b = i.arg[1];
    auto count = i.arg[2];
    std::uint16_t first = 0, second = 0;
    while (count) {
        first = lower16(static_cast<std::uint16_t>(m.r16(a)));
        i.arg[1] = first;
        second = lower16(static_cast<std::uint16_t>(m.r16(b)));
        i.arg[0] = second;
        ++a; ++b; ++a; ++b;
        --count;
        i.arg[2] = count;
        if (!count || !first || first != second) break;
    }
    return std::uint32_t(first) - std::uint32_t(second);
}

} // namespace ra2::recovered::crt_b83
