#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/locale991.hpp"
namespace ra2::recovered::recovery_b991 {
using global_b26::Memory;using global_b26::Inputs;using ra2::platform::locale991::Buffer;using ra2::platform::locale991::Boundary;
struct Observation{Buffer bytes{};std::uintptr_t pointer=0;};
std::uint32_t fun_0077b220(Memory&,const Inputs&,Boundary&,Observation&);
}
