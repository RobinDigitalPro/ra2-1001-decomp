#include "recovered/recovery_b996.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b996 {
namespace {void need(bool b,const char*s){if(!b)throw std::domain_error(s);}}
std::uint32_t fun_00537990(Memory&m,const Inputs&,Heap&h){
 need(m.r32(0xa565a0u)==0x7905e4u&&m.r32(0xa565a8u)==10u&&m.r8(0xa565adu)==1u,"B996 authentic owned original vector");
 need(m.r32(0xb10e14u)==0u&&m.r32(0x817554u)==0u,"B996 actual ordinary CRT route");
 const auto data=m.r32(0xa565a4u),initial=m.r32(0xa565b0u);need(data&&initial>=1u&&initial<=4u,"B996 populated1..4");
 for(unsigned index=0;index<m.r32(0xa565b0u);++index){
  const auto item=h.r32(data+4u*index);need(item!=0u,"B996 nonnull positive items");const auto parent=h.r32(item+4u);if(parent){m.w32(parent+0x94u,0u);h.w32(item+4u,0u);}
  // Exact537CE0 authentic vtable+10 index-of semantics. It receives the
  // address of a local pointer, compares values, and performs no mutation.
  const auto count=m.r32(0xa565b0u);unsigned found=0xffffffffu;for(unsigned j=0;j<count;++j)if(h.r32(data+4u*j)==item){found=j;break;}
  if(found!=0xffffffffu&&found<count){const auto reduced=count-1u;m.w32(0xa565b0u,reduced);for(unsigned j=found;j<reduced;++j)h.w32(data+4u*j,h.r32(data+4u*(j+1u)));}
  h.release(item);
  // Preserve the original forward-index skip after erase: do not decrement
  // index or free the objects shifted behind the next iteration.
 }
 m.w32(0xa565b0u,0u);const auto result=h.release(data);m.w32(0xa565a4u,0u);m.w8(0xa565adu,0u);m.w32(0xa565a8u,0u);return result;
}
}
