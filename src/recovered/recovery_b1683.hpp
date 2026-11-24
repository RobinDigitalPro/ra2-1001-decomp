#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
namespace ra2::recovered::b1683 {
using Memory=global_b26::Memory;
using Inputs=global_b26::Inputs;
using Heap=platform::ordinary_heap::Heap;
struct Observation {
    unsigned slot{}, object{}, buffer{}, releases{}, stage{};
};
// Finite proposal: flags 83B307/AA4F95 and authentic BSS 83A6FC are zero.
// Exactly one listed global slot owns a real 32-byte allocation, with a
// field-compatible 785EF8 header; +14 owns a separate real 16-byte allocation.
// Width/height=1, lock=0, bpp=2, nominal buffer size +18=2, owner byte +1C=1.
// No constructor execution or nominal original class allocation size is claimed.
unsigned run(Memory&,const Inputs&,Heap&,Observation&);
unsigned run(Memory&,const Inputs&,Heap&);
}
