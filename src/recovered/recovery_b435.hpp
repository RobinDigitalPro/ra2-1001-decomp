#pragma once
#include "recovered/global_b27_memory.hpp"
#include <cstdint>
namespace ra2::recovered::entry435 {
using Memory=global_b27::Memory;
using State=global_b27::State;
struct Ops { void* context{}; std::uint32_t (*is_bad_read_ptr)(void*,std::uint32_t,std::uint32_t){}; };
std::uint32_t fun_0076f545(Memory&,State&,const Ops&);
}
