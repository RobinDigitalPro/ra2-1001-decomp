#pragma once
#include "recovered/recovery42_strings.hpp"
#include <cstdint>

namespace ra2::recovered::recovery_b269 {
using recovery42_strings::Heap;
using recovery42_strings::Inputs;
using recovery42_strings::Memory;

// Bounded successful ordinary-heap route only. ECX is treated as the observed
// receiver cell; arg[0] points to a distinct output pointer cell. No class or
// source-level ABI claim is made by these adapter names.
std::uint32_t rva_003599d0(Memory&, const Inputs&, Heap&);
std::uint32_t rva_00359b00(Memory&, const Inputs&, Heap&);
}
