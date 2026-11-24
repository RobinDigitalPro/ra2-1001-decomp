#include "recovered/recovery_b1550.hpp"
#include <stdexcept>
namespace ra2::recovered::b1550 {
static void need(bool x){if(!x)throw std::domain_error("1550 finite genuine nonmatch queue route");}
std::uint32_t fun_00748eb0(Memory&m,const Inputs&,Heap&h){
 need(m.r32(0xb0ee60u)==1u&&m.r32(0xb0ed08u)<10u&&m.r32(0xb0ee64u)==10u);
 const auto list=m.r32(0xb0ee68u),initial=m.r32(list);
 need(initial&&h.r8(initial)=='Z'&&h.r8(initial+1u)==0u);
 // Actual 759250/759570 clone one string while the queue still owns initial.
 const auto first=h.allocate(2u);need(first);h.w8(first,h.r8(initial));h.w8(first+1u,h.r8(initial+1u));
 // Actual 752660 calls 759320/76D67B, memmoves zero bytes and keeps capacity ten.
 need(h.release(initial)!=0u);m.w32(list,0u);m.w32(0xb0ee60u,0u);
 // Actual 759260 creates the comparison clone.
 const auto second=h.allocate(2u);need(second);h.w8(second,h.r8(first));h.w8(second+1u,h.r8(first+1u));
 need(m.r32(0xb0fc00u)==1u);const auto records=m.r32(0xb0fc08u);need(records);
 need(m.r8(records+0x24u)=='Y'&&m.r8(records+0x25u)==0u&&h.r8(second)=='Z'&&h.r8(second+1u)==0u);
 // Real 76D860 strcmp(Z,Y) is nonzero; selected branch has no provider call.
 need(h.release(second)!=0u);
 // Actual 4068F0 is a one-byte RET. Final 759320 destroys first clone.
 need(h.release(first)!=0u);
 return m.r32(0xb0ee60u);
}
}
