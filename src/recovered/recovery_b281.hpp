#pragma once

#include "recovered/recovery42_strings.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b281 {
using recovery42_strings::Heap;
using recovery42_strings::Inputs;
using recovery42_strings::Memory;

// Bounded successful owned UTF-16 replacement projection for RVA 0x35c500.
std::uint32_t rva_0035c500(Memory&, const Inputs&, Heap&);
}
