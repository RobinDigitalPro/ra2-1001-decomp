#include "recovered/recovery_b467.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b467 {
namespace {
void require(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}

std::uint32_t quarter_binary32(std::uint32_t numerator, bool negative) {
    require(numerator >= 1 && numerator <= 1023, "B467 quarter numerator outside 1..1023");
    unsigned top = 0;
    for (auto n = numerator; n > 1; n >>= 1) ++top;
    require(top <= 9, "B467 quarter exponent outside normal output range");
    const auto exponent = top + 125u; // (floor(log2(numerator))-2)+127
    const auto fraction = (numerator << (23u - top)) & 0x7fffffu;
    return (negative ? 0x80000000u : 0u) | (exponent << 23) | fraction;
}
}

std::uint32_t fun_0077baef(Memory& m, const Inputs& i) {
    const auto source = i.arg[0];
    const auto destination = i.arg[1];
    const auto format = i.arg[2];
    require(source != 0 && destination != 0 && format != 0, "B467 nonnull input and output pointers required");
    require(m.r32(format + 0) == 128u && m.r32(format + 4) == 0xffffff81u &&
            m.r32(format + 8) == 24u && m.r32(format + 12) == 8u &&
            m.r32(format + 16) == 32u && m.r32(format + 20) == 127u,
            "B467 requires the original 0x8183f8 binary32 descriptor");

    const auto guard = m.r16(source);
    const auto significand = std::uint64_t(m.r32(source + 2)) |
                            (std::uint64_t(m.r32(source + 6)) << 32);
    require(guard == 0, "B467 requires zero discarded guard word");
    const auto sign_exponent = m.r16(source + 10);
    const bool negative = (sign_exponent & 0x8000u) != 0;
    const auto exponent = sign_exponent & 0x7fffu;
    require(exponent >= 0x3ffdu && exponent <= 0x4006u,
            "B467 requires finite quarter values in 0.25..255.75");
    const auto top = unsigned(exponent - 0x3ffdu);
    const auto numerator = std::uint32_t(significand >> (63u - top));
    require(numerator >= 1 && numerator <= 1023 &&
            significand == (std::uint64_t(numerator) << (63u - top)),
            "B467 input must be one of the exact quarter values in the declared range");
    // The restricted exponent interval [-2,7] is strictly within the pinned
    // descriptor's normal finite range [-151,128).
    i.arg[0] = negative ? 0x8000u : 0u; // Original writes the sign mask over caller word 0.
    m.w32(destination, quarter_binary32(numerator, negative));
    return 0; // The original normal finite branch clears EAX before the common epilogue.
}
}

