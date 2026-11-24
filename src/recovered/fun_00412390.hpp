#pragma once

#include <cstdint>

namespace ra2::recovered {

// Dependency seam for the two original CRT-like callees, NOT an original type.
// Both callbacks receive a sign-extended input byte. classify_hex represents
// original RVA 0x36e4f4 (any nonzero result accepts); uppercase represents
// original RVA 0x36e313. Their locale/table/locking state belongs to the adapter.
struct HexCharacterOps {
    using Operation = std::int32_t (*)(std::int32_t character, void* context);
    Operation classify_hex;
    Operation uppercase;
    void* context;
};

// Original GAME.EXE RVA 0x12390, with the two callees made explicit.
// Original entry: ECX=input; EAX=32-bit result. Original C++ name/class/ABI
// spelling is unknown. This portable interface does not claim ABI compatibility.
// Null input returns zero without callbacks. Otherwise both callbacks must be
// valid, and input must remain readable through the first rejected byte.
// There is no whitespace/sign/0x-prefix handling; accumulation wraps modulo 2^32.
// Runtime state, high-bit bytes, and even NUL acceptance are governed by the
// supplied classifier, exactly as by the original helper. Pointer wraparound
// across the x86 address-space boundary is outside this portable interface.
std::uint32_t fun_00412390(const std::uint8_t* input, const HexCharacterOps& ops);

} // namespace ra2::recovered
