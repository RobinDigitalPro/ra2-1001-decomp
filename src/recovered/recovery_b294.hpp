#pragma once
#include "recovered/recovery42_strings.hpp"
#include <cstdint>
namespace ra2::recovered::recovery_b294 {
using recovery42_strings::Heap;
using recovery42_strings::Inputs;
using recovery42_strings::Memory;
std::uint32_t rva_0035be00(Memory&,const Inputs&,Heap&);
std::uint32_t rva_0035c370(Memory&,const Inputs&,Heap&);
}
