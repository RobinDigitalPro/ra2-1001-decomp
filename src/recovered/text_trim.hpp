#pragma once

#include <cstdint>

namespace ra2::recovered {

// Original GAME.EXE RVA 0x2e41d0 (VA 0x6e41d0).
// For a valid NUL-terminated byte string, removes leading and trailing bytes
// in [1, 0x20] in place and returns the original pointer. Null returns null.
// The leading shift is a forward overlapping copy including NUL. During the
// backward pass, the original leading-skip pointer is re-read on every
// iteration; this preserves the observed alias-sensitive early exit.
// Inputs must be valid NUL-terminated buffers shorter than INT_MAX. Pointer
// wraparound, concurrent mutation, and invalid strings are outside the scope.
std::uint8_t* fun_006e41d0(std::uint8_t* text);

} // namespace ra2::recovered
