#include "recovered/recovery_b994.hpp"
#include <stdexcept>
namespace ra2::recovered::b994 {
namespace {void need(bool b,const char*s){if(!b)throw std::domain_error(s);}}
std::uint32_t fun_0050fca0(Memory&m,const Inputs&i,Heap&h){
 const auto s=i.cx,head=s+0x14u,tail=s+0x20u,node=m.r32(s+0x18u);
 need(s&&m.r32(s+4u)==0u&&m.r32(s+8u)==0u,"B994 isolated section parent links");
 need(m.r32(0xb10e14u)==0u&&m.r32(0x817554u)==0u,"B994 genuine ordinary CRT route");
 need(m.r32(s)==0x78eba4u&&m.r32(s+0x10u)==0x78ebacu&&m.r32(head)==0x785afcu&&m.r32(tail)==0x785afcu,"B994 original section/sentinel tables");
 need(node&&h.r32(node)==0x78eb9cu&&m.r32(0x78eb9cu)==0x50fe00u,"B994 authentic inlined deleting virtual target");
 need(h.r32(node+4u)==tail&&h.r32(node+8u)==head&&m.r32(head+8u)==0u&&m.r32(tail+4u)==0u&&m.r32(tail+8u)==node,"B994 exact populated one-node ring");
 need(h.r32(node+0x14u)==0u&&h.r32(node+0x18u)==0u&&m.r32(s+0x40u)==0u,"B994 no extra owned chains");
 const auto name=m.r32(s+0xcu),key=h.r32(node+0xcu),value=h.r32(node+0x10u),table=m.r32(s+0x2cu);
 need(name&&key&&value&&table&&m.r32(s+0x30u)==1u&&m.r32(s+0x34u)==10u&&h.r32(table+4u)==node,"B994 positive owned allocations/one-row index");
 // Root50FCA0 first frees its owned name, then invokes the original node's
 // deleting destructor with flag1. NULLfree calls produce no OS heap events.
 m.w32(s,0x78eba4u);h.release(name);m.w32(s+0xcu,0u);
 h.w32(node,0x78eb9cu);h.release(key);h.w32(node+0xcu,0u);h.release(value);h.w32(node+0x10u,0u);h.w32(node+0x18u,0u);h.w32(node,0x785afcu);
 // Exact unlink stores50FE7A..89; both neighbors are arena sentinels.
 m.w32(head+4u,tail);m.w32(tail+8u,head);h.w32(node+8u,0u);h.w32(node+4u,0u);h.release(node);
 // The loop next sees tail.next0. It releases and clears the key index;
 // the second index cleanup later sees NULL, with no actual HeapFree call.
 h.release(table);m.w32(s+0x2cu,0u);m.w32(s+0x30u,0u);m.w32(s+0x34u,0u);m.w8(s+0x38u,0u);m.w32(s+0x3cu,0u);
 m.w32(s+0x2cu,0u);m.w32(s+0x30u,0u);m.w32(s+0x34u,0u);m.w8(s+0x38u,0u);m.w32(s+0x3cu,0u);
 m.w32(s+0x10u,0x785af4u);m.w32(tail,0x785afcu);m.w32(head,0x785afcu);m.w32(s,0x785afcu);
 return head;
}
}
