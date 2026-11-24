#pragma once
#include "recovered/floating_b61_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1605 {
using floating_b61::Memory;
using floating_b61::Inputs;
using U=std::uint32_t;
U run(U root,Memory&,const Inputs&,ra2::platform::ordinary_heap::Heap&);
}
