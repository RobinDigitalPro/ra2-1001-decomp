#pragma once
#include "recovered/recovery42_strings.hpp"
#include <cstdint>
namespace ra2::recovered::recovery_b296 {
using recovery42_strings::Heap;
using recovery42_strings::Inputs;
using recovery42_strings::Memory;
std::uint32_t rva_001ad3d0(Memory&, const Inputs&, Heap&);
}
