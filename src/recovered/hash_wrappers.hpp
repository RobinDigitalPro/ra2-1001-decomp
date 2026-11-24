#pragma once

#include "recovered/name_hash.hpp"

#include <cstdint>
#include <optional>

namespace ra2::recovered {

// Thin portable views of original hash call-site adapters. The integers are
// raw bits serialized explicitly in little-endian order; these declarations do
// not claim an original class layout, C++ type, or calling convention.

// RVA 0x93cf0: append the low 16 bits of raw_bits.
std::uint32_t fun_00493cf0(NameHashState& state, std::uint32_t raw_bits);

// RVAs 0x93d10 and 0x93d30: append all 32 bits of raw_bits.
std::uint32_t fun_00493d10(NameHashState& state, std::uint32_t raw_bits);
std::uint32_t fun_00493d30(NameHashState& state, std::uint32_t raw_bits);

// RVA 0x93d50: append all 64 bits of raw_bits.
std::uint32_t fun_00493d50(NameHashState& state, std::uint64_t raw_bits);

// RVA 0x93d70: append bytes up to (but not including) NUL. A null pointer
// leaves state unchanged; its original return register is undefined, so the
// portable view represents that case with nullopt.
std::optional<std::uint32_t> fun_00493d70(NameHashState& state, const char* text);

} // namespace ra2::recovered
