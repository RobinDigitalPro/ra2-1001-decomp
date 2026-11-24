#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1684 {
using Memory=global_b26::Memory;
using Inputs=global_b26::Inputs;
using Heap=platform::ordinary_heap::Heap;
struct Observation { unsigned stage{},releases{}; };
// Finite caller-owned112-byte, field-compatible producer-component fixture.
// No factory/constructor history is claimed. Three surfaces are caller-owned;
// Root releases only strings+50,+4C and numeric backing+self10, in that order.
unsigned run(Memory&,const Inputs&,Heap&,Observation&);
unsigned run(Memory&,const Inputs&,Heap&);
}
