#pragma once
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"

namespace ra2::recovered::recovery_b1693 {
using U=std::uint32_t;
using Memory=global_b26::Memory;
using Inputs=global_b26::Inputs;
// A platform view of the actual live owner, never a copy or behavior callback.
class Heap:public ra2::platform::ordinary_heap::Heap {
public:
 //Returned view object/reference stays stable across later allocations until release.
 virtual leaf::Memory& owner_span(U pointer,U exact_extent)=0;
};
struct Projection {
 U self{},borrowed{},color{};
 std::array<U,16> caller{};
};
// Read-only supplied-domain checks, outside the observed guest boundary.
Projection preflight(U root,Memory&,const Inputs&);
// Only133E50:32x24/RGB565, successful32+1536 allocation, empty borrowed field.
// Heap owns both outputs; views must alias real bytes through their lifetimes.
U run(U root,Memory&,const Inputs&,Heap&,const Projection&);
}
