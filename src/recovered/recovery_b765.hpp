#pragma once
#include "recovered/global_b26_memory.hpp"
#include <cstdint>

namespace b765 {
using Memory = ra2::recovered::global_b26::Memory;
struct Inputs { std::uint32_t cx=0, dx=0; std::uint32_t arg[16]{}; };
std::uint32_t query_3520a0(Memory&, const Inputs&);
std::uint32_t query_352210(Memory&, const Inputs&);
std::uint32_t query_352c70(Memory&, const Inputs&);
}
