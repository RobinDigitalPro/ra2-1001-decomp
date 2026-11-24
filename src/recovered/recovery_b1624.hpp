#pragma once
#include "recovered/recovery_b979.hpp"
#include "recovered/floating_b61_memory.hpp"
namespace ra2::recovered::b1624 {
using U=std::uint32_t;using b979::Memory;using b979::Heap;using b979::FileApi;using Inputs=floating_b61::Inputs;
U run(U root,Memory&,const Inputs&,Heap&,FileApi&);
void cleanup(Memory&,U self,Heap&);
}
