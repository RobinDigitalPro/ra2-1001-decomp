#include "recovery_b422_1fa1a0.hpp"
#include <stdexcept>
namespace ra2::recovered::lifecycle_b422_1fa1a0 {
std::uint32_t fun_005fa1a0(Memory& m,const Inputs& in,Heap& heap) {
 const auto self=in.cx;
 const auto separate=m.r32(self+0x2cu);
 if(separate==0u) throw std::domain_error("bounded route requires a non-null separately-owned +0x2c allocation");
 heap.release(separate);
 m.w32(self+0x2cu,0u);
 auto current=m.r32(self+0x38u);
 unsigned nodes=0;
 while(current!=0u) {
  if(++nodes>3u) throw std::domain_error("bounded route requires exactly three acyclic owned nodes");
  const auto next=heap.r32(current);
  m.w32(self+0x38u,next);
  heap.release(current);
  current=next;
 }
 const auto auxiliary=m.r32(self+0x40u);
 if(auxiliary!=0u) {
  const auto payload=heap.r32(auxiliary);
  if(payload!=0u)heap.release(payload);
  heap.w32(auxiliary,0u); // Exact accepted 0x35b390 pointer-slot effect.
  heap.release(auxiliary);
 }
 if((in.arg[0]&1u)!=0u) throw std::domain_error("bounded route excludes optional receiver self-free");
 return self;
}
}




