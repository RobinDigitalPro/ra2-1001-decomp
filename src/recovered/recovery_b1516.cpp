#include "recovered/recovery_b1516.hpp"
#include <stdexcept>
namespace ra2::recovered::b1516 {
std::uint32_t fun_004079c0(Memory& m,const Inputs& i,Heap& heap){
 const auto p=i.cx;
 if(heap.r32(p)!=p || heap.r32(p+4u)!=p || heap.r32(p+0x14u)!=0u || heap.r32(p+0x30u)!=0u || heap.r32(p+0x38u)!=0u || heap.r32(p+0x7cu)!=0u || heap.r32(p+0x88u)==0u)
  throw std::domain_error("1516 supports the reviewed selflinked one-reference ordinary-heap route");
 const auto node=heap.r32(p+0x34u);
 if(!node)throw std::domain_error("1516 requires positive borrowed child reference");
 // Exact accepted00408D90: ordered decrements and signed-negative clamps.
 auto count=m.r32(node+0x1cu)-1u;m.w32(node+0x1cu,count);
 if(static_cast<std::int32_t>(count)<0)m.w32(node+0x1cu,0u);
 const auto owner=m.r32(node);count=m.r32(owner+0x98u)-1u;m.w32(owner+0x98u,count);
 if(static_cast<std::int32_t>(count)<0)m.w32(owner+0x98u,0u);
 heap.w32(p+0x34u,0u);
 // Actual ordinaryCRT release: lock9, empty-small-registry, unlock, HeapFree.
 // HeapAdapter forwards to real verified OS APIs and captures all pre-free bytes.
 return heap.release(p);
}
}
