#include "recovered/recovery_b1554.hpp"
#include <stdexcept>
namespace ra2::recovered::b1554 {
static void need(bool x){if(!x)throw std::domain_error("1554 finite nonempty unmatched queue route");}
std::uint32_t fun_007491b0(Memory&m,const Inputs&,Heap&h){
 need(m.r32(0xb0ed08u)==1u&&m.r32(0xb0ed0cu)==10u&&m.r32(0xb0ee60u)==0u);
 const auto list=m.r32(0xb0ed10u),initial=m.r32(list);
 need(initial&&h.r8(initial)=='Z'&&h.r8(initial+1u)==0u);
 // Authentic759260 construction from original seven byte Pings literal.
 constexpr unsigned char text[]{'P','i','n','g','s',' ',0};
 const auto pings=h.allocate(7u);need(pings);for(unsigned k=0;k<7;++k)h.w8(pings+k,text[k]);
 // Actual759250/759570 clone last queued item;752660 consumes it.
 const auto first=h.allocate(2u);need(first);h.w8(first,h.r8(initial));h.w8(first+1u,0u);
 need(h.release(initial)!=0u);m.w32(list,0u);m.w32(0xb0ed08u,0u);
 const auto second=h.allocate(2u);need(second);h.w8(second,h.r8(first));h.w8(second+1u,0u);
 need(m.r32(0xb0fc00u)==1u);const auto registry=m.r32(0xb0fc08u);need(registry);
 need(m.r8(registry+0x24u)=='Y'&&m.r8(registry+0x25u)==0u&&h.r8(second)=='Z'&&h.r8(second+1u)==0u);
 // Genuine strcmp mismatch preserves root-produced zero local record.
 need(h.release(second)!=0u);need(h.release(first)!=0u);
 // Zero successes bypass both providers. Mandatory348EB0 sees empty tail.
 need(m.r32(0xb0ee60u)==0u);
 // Actual759320/76D67B propagate final real HeapFree BOOL, full EAX.
 return h.release(pings);
}
}
