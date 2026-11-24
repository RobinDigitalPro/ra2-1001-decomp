#include "recovery_b761.hpp"
#include "recovered/lookup_b67.hpp"

#include <array>
#include <cstdio>
#include <cstdint>
#include <stdexcept>
#include <string>

namespace ra2::recovered::format_b761 {
namespace {
constexpr std::uint32_t kFormat = 0x007e0444u;
constexpr char kFormatText[] = "%d,%d,%d,%d,%d,%d,%d,%d";

std::string read_bounded_z(Memory& m, std::uint32_t address, unsigned limit) {
    if (!address) throw std::domain_error("B761 requires a nonnull output buffer");
    std::string text;
    for (unsigned n = 0; n < limit; ++n) {
        const auto byte = m.r8(address + n);
        if (!byte) return text;
        text.push_back(static_cast<char>(byte));
    }
    throw std::domain_error("B761 output prefix must terminate within 64 bytes");
}

std::int32_t signed32(std::uint32_t value) {
    if (value <= 0x7fffffffu) return static_cast<std::int32_t>(value);
    return -1 - static_cast<std::int32_t>(0xffffffffu - value);
}
}

std::uint32_t fun_006a2c90(Memory& m, const Inputs& input) {
    const auto receiver = input.cx;
    const auto selector = m.r32(receiver + 0x2cu);
    Inputs lookup{};
    lookup.cx = selector;
    if (lookup_b67::fun_006a8100(m, lookup) != 0x2bu)
        throw std::domain_error("B761 supports only the original selector route that yields type 0x2b");

    // The root scans its stack arg0 to the existing NUL, then formats at that
    // exact terminator. The PE literal is checked so this model cannot silently
    // drift to a different format string.
    for (unsigned n = 0; n < sizeof(kFormatText); ++n)
        if (m.r8(kFormat + n) != static_cast<std::uint8_t>(kFormatText[n]))
            throw std::domain_error("B761 pinned format literal mismatch");
    const auto prefix = read_bounded_z(m, input.arg[0], 64u);
    const std::array<std::int32_t, 8> values{{
        signed32(m.r32(receiver + 0x2cu)),
        9,
        signed32(m.r32(receiver + 0x74u)),
        signed32(m.r32(receiver + 0x34u)),
        signed32(m.r32(receiver + 0x38u)),
        signed32(m.r32(receiver + 0x3cu)),
        signed32(m.r32(receiver + 0x40u)),
        signed32(m.r32(receiver + 0x48u)),
    }};
    std::array<char, 128> formatted{};
    const auto count = std::snprintf(formatted.data(), formatted.size(), kFormatText,
        values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7]);
    if (count < 0 || static_cast<std::size_t>(count) >= formatted.size())
        throw std::domain_error("B761 formatted output exceeds the bounded buffer");
    const auto output = input.arg[0] + static_cast<std::uint32_t>(prefix.size());
    input.arg[0]=output; // Original 6A2DC0 callerword store.
    for (int n = 0; n <= count; ++n)
        m.w8(output + static_cast<std::uint32_t>(n), static_cast<std::uint8_t>(formatted[static_cast<std::size_t>(n)]));
    return static_cast<std::uint32_t>(count);
}
}
