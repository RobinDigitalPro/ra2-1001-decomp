#pragma once
#include "recovered/recovery42_strings.hpp"
#include <cstdint>
namespace ra2::recovered::recovery_b290 {
using recovery42_strings::Heap;
using recovery42_strings::Inputs;
using recovery42_strings::Memory;
std::uint32_t rva_0035a8d0(Memory&, const Inputs&, Heap&);
std::uint32_t rva_00359e60(Memory&, const Inputs&, Heap&);
std::uint32_t rva_0035c5b0(Memory&, const Inputs&, Heap&);
}
