#pragma once
#include "recovered/recovery42_strings.hpp"
#include <cstdint>
namespace ra2::recovered::recovery_b292 {
using recovery42_strings::Heap;
using recovery42_strings::Inputs;
using recovery42_strings::Memory;
std::uint32_t rva_00359c50(Memory&, const Inputs&, Heap&);
std::uint32_t rva_0035ccc0(Memory&, const Inputs&, Heap&);
}
