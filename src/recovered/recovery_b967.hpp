#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <array>
#include <vector>
namespace ra2::recovered::recovery_b967 {
using ra2::recovered::global_b26::Memory;using ra2::recovered::global_b26::Inputs;using ra2::platform::ordinary_heap::Heap;
struct TokenObservation{std::uint32_t entry_esp=0,buffer=0,cursor=0;std::array<std::uint8_t,128>bytes{};std::vector<unsigned>token_offsets;};
std::uint32_t run(Memory&,const Inputs&,Heap&,std::uint32_t root,std::uint32_t entry_esp,TokenObservation&);
std::uint32_t fun_0064ac70(Memory&,const Inputs&,Heap&,std::uint32_t,TokenObservation&);
std::uint32_t fun_0064af30(Memory&,const Inputs&,Heap&,std::uint32_t,TokenObservation&);
std::uint32_t fun_0064b1f0(Memory&,const Inputs&,Heap&,std::uint32_t,TokenObservation&);
}
