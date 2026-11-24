#pragma once
#include "recovered/global_b27_memory.hpp"
#include <cstdint>
namespace ra2::recovered::keyboard433 {
using Memory=global_b27::Memory;
using State=global_b27::State;
struct Ops {
 void* context{};
 std::uint32_t (*map_virtual_key_a)(void*,std::uint32_t,std::uint32_t){};
 std::int32_t (*to_ascii)(void*,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t){};
};
std::uint32_t fun_00530980(Memory&,State&,std::uint32_t scratch, const Ops&);
}
