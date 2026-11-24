#include "recovery_b288.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b288 {
namespace {
void need(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
// Exact selected path in accepted 0x359260: source 0x8248a4 is a single NUL.
void assign_empty_string(Memory& m,std::uint32_t slot,Heap& heap){
 m.w32(slot,0u);
 constexpr std::uint32_t source=0x008248a4u;
 need(m.r8(source)==0u,"original empty C-string literal required");
 const auto user=heap.allocate(1u);
 need(user!=0u,"successful request-1 small-CRT allocation required");
 m.w32(slot,user);heap.w8(user,0u);
}
// 0x3206d0 sees both forwarded words as zero. Its ESI-zero branch returns
// after these writes and never calls 0x36d957 or 0x630a80.
void init_empty_child(Memory& m,std::uint32_t child){
 m.w32(child+4u,0u);m.w32(child+8u,0u);
 m.w8(child+0x0cu,1u);m.w8(child+0x0du,0u);m.w32(child,0x0079a0ccu);
}
}
std::uint32_t fun_0071def0(Memory& m,Inputs& i,Heap& heap){
 const auto self=i.cx,a1=i.arg[0],a2=i.arg[1],a3=i.arg[2];
 need(self!=0u,"mapped constructor receiver required");
 m.w32(self+0x0cu,a2);m.w32(self+4u,0u);m.w32(self,0x00793cd4u);
 m.w32(self+8u,a1);m.w32(self+0x10u,a3);
 m.w32(self+0x14u,0u);m.w32(self+0x18u,0u);m.w32(self+0x1cu,0u);
 m.w32(self+0x20u,0u);m.w32(self+0x24u,0u);
 assign_empty_string(m,self+0x28u,heap);        // sole allocation request is 1
 const auto child=self+0x2cu;
 init_empty_child(m,child);                     // 0x3206d0 zero-count path
 m.w32(child,0x0079a0acu);m.w32(child+0x10u,0u);m.w32(child+0x14u,10u);
 m.w32(self+0x44u,0u);m.w32(self+0x48u,0u);
 m.w32(self+0x64u,0u);m.w8(self+0x68u,0u);m.w32(self+0x6cu,0u);m.w32(self+0x70u,0u);
 m.w8(self+0x74u,0u);m.w32(self+0x78u,0u);
 m.w32(self+0xc0u,0u);m.w32(self+0xc4u,0u);m.w8(self+0xc8u,1u);m.w8(self+0xc9u,0u);
 m.w32(self+0xbcu,0x0079a08cu);m.w32(self+0xd0u,10u);m.w32(self+0xccu,0u);
 m.w32(self,0x0079a07cu);
 return self;                                     // EAX=this, RET 0xc
}
}
