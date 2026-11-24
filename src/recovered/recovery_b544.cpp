#include "recovery_b544.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b544{
std::uint32_t fun_0070a590(Memory&m,const Inputs&i,Heap&h){
 if(i.dx!=3||m.r32(0xab82e8)!=0xab82e8||m.r32(0xab82ec)!=0xab82e8||m.r32(0xab83d0)>0x7ffffffe)throw std::domain_error("544 kind3 empty list positive serial");
 //70A598-70A5A6: actual new32 and7200 self-linked initializer.
 const auto node=h.allocate(32);h.w32(node,node);h.w32(node+4,node);h.w32(node+8,0);
 h.w32(node+12,i.cx);h.w32(node+20,i.arg[0]);h.w32(node+24,i.dx);
 //70A5B8-70A5D8: CDQ/IDIV100, increment serial and mark parent.
 const auto serial=m.r32(0xab83d0);h.w32(node+28,serial%100);m.w32(0xab83d0,serial+1);m.w32(i.cx+0x48,1);
 //70A5E8 invokes original7350 insertion protocol; EAX is old next.
 const auto old=m.r32(0xab82ec);h.w32(node,0xab82e8);h.w32(node+4,old);m.w32(0xab82ec,node);m.w32(old,node);
 return old;
}}
