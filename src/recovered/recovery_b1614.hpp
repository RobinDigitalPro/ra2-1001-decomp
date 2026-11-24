#pragma once
#include "platform/ordinary_heap979.hpp"
#include "recovered/floating_b61_memory.hpp"
namespace ra2::recovered::b1614 {
using U=std::uint32_t;
using b979::Memory;
using b979::Heap;
using Inputs=floating_b61::Inputs;
U run(U root,Memory&,const Inputs&,Heap&);
}
