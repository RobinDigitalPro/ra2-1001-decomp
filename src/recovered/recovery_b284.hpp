#pragma once

#include "recovered/recovery42_strings.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b284 {
using recovery42_strings::Heap;
using recovery42_strings::Inputs;
using recovery42_strings::Memory;

// Bounded successful ordinary-heap insertion route for RVA 0x35bf20.
// This declaration does not assert an original class or source-level prototype.
std::uint32_t rva_0035bf20(Memory&, const Inputs&, Heap&);
}
