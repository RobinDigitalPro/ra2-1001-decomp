#pragma once
#include "recovered/recovery42_strings.hpp"
#include <cstdint>
namespace ra2::recovered::recovery_b329 {
using Memory = ra2::recovered::recovery42_strings::Memory;
using Inputs = ra2::recovered::recovery42_strings::Inputs;
using Heap = ra2::recovered::recovery42_strings::Heap;
std::uint32_t rva_00344960(Memory&, const Inputs&, Heap&);
}
