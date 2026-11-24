#pragma once
#include "recovered/floating_b61_memory.hpp"
#include <cstdint>
#include <vector>

namespace ra2::recovered::recovery_b390 {
using Memory=ra2::recovered::global_b26::Memory;
using Inputs=ra2::recovered::floating_b61::Inputs;
struct Feed {std::uint32_t source_offset;std::uint32_t kind;std::uint32_t width;std::uint64_t raw;std::uint32_t returned;};
using Trace=std::vector<Feed>;
std::uint32_t rva_00315790(Memory&,const Inputs&);
std::uint32_t rva_002d4540(Memory&,const Inputs&);
std::uint32_t run_00315790(Memory&,const Inputs&,Trace*);
std::uint32_t run_002d4540(Memory&,const Inputs&,Trace*);
}
