#pragma once

#include "recovered/recovery42_strings.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b278 {
using recovery42_strings::Heap;
using recovery42_strings::Inputs;
using recovery42_strings::Memory;

// Bounded successful ordinary-heap projections only. Names are RVA labels;
// they make no source-class or original prototype claim.
std::uint32_t rva_0035cbc0(Memory&, const Inputs&, Heap&);
std::uint32_t rva_0035a9a0(Memory&, const Inputs&, Heap&);
}
