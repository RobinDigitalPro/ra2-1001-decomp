#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <array>
namespace ra2::recovered::recovery_b943 {using global_b26::Memory;using global_b26::Inputs;using U=std::uint32_t;
struct ModulePath {virtual ~ModulePath()=default;virtual U current(std::array<std::uint8_t,260>&)=0;};
U fun_00779bb7(Memory&,const Inputs&,platform::ordinary_heap::Heap&,ModulePath&);
}
