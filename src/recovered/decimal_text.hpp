#pragma once
#include <cstdint>
namespace ra2::recovered {
// Explicit unresolved CRT classification dependency: mask 8 for whitespace,
// mask 4 for decimal digits, with zero/nonzero results. The input is readable
// and classifications must eventually terminate scanning within that input.
// Callbacks may not mutate the input or classification rules during a call.
// Native evidence covers only the initial PE single-byte table, not CRT locale
// initialization or the alternate multibyte helper. No original ABI is claimed.
struct DecimalOperations {
    std::int32_t (*classify)(std::uint8_t, std::uint32_t, void*);
    void* context;
};
// Original RVAs 0x36e6b2 and 0x36e73d. Return the full 32-bit result bits;
// arithmetic, including sign negation, wraps modulo 2^32.
std::uint32_t fun_0076e6b2(const std::uint8_t*, const DecimalOperations&);
std::uint32_t fun_0076e73d(const std::uint8_t*, const DecimalOperations&);
}
