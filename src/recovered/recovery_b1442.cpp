#include "recovered/recovery_b1442.hpp"
#include "recovered/recovery_b517.hpp"
#include "recovered/leaf_memory.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1442 {
namespace {using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
U lookup(Memory&m,U xy){const auto x=std::int32_t(std::int16_t(xy));const auto y=std::int32_t(std::int16_t(xy>>16));const U index=U(y)*512u+U(x);
 if(index<0x40000u){const U p=m.r32(m.r32(0x81a958u)+index*4u);if(p)return p;}
 m.w32(0xa57634u,xy);return 0xa57610u;
}}
std::uint32_t run(U rva,Memory&m,const Inputs&i,Heap&heap){
 need(rva==0x14ba10u&&i.cx==0x81a820u&&i.arg[0]==0x00050005u&&i.arg[1]==0u,"1442 selected real Map5,5 caller contract");
 need(m.r32(lookup(m,i.arg[0])+0xecu)!=2u,"1442 original selector1 branch");
 // T=S-14h after SUB8 and three saves. Only actual produced/consumed
 // root locals and caller words live in this private frame.
 constexpr U base=0x7db00000u,T=base+0x800u;
 std::array<std::uint8_t,0x1000> bytes;bytes.fill(0xcdu);
 leaf::Memory frame(bytes.data(),base,unsigned(bytes.size()));auto local=m;local.add(frame);
 for(U k=0;k<16u;++k)local.w32(T+0x18u+4u*k,i.arg[k]);
 local.w16(T+0xcu,0u);local.w16(T+0xeu,0u);
 recovery_b517::Inputs search{};search.ax=1u;search.cx=i.cx;search.dx=T+0xcu;search.fp=i.fp;
 // Two trailing carrier words are outside the fourteen-argument contract;
 // the reached original body never reads them. No unproduced word is used.
 search.arg={T+0x10u,T+0x18u,1u,0xffffffffu,0u,0u,1u,1u,0u,0u,0u,1u,T+0xcu,0u,0u,0u};
 const U output=recovery_b517::fun_0054d770(local,search);
 need(output==T+0x10u,"1442 actual search output address");
 local.w32(T+0x18u,local.r32(output));
 const U sentinel=local.r32(0xa56e5cu);U slot=0u;
 for(;slot<256u;++slot)if(local.r32(i.cx+0x160u+16u*slot)==sentinel)break;
 need(slot<256u,"1442 original free timer slot");
 Inputs child{};child.cx=i.cx+0x154u+16u*slot;child.arg[0]=T+0x18u;child.fp=search.fp;
 const U owned=b1303::run(0x93780u,local,child,heap);
 need((owned&255u)!=0u,"1442 original owned construction success");
 // 493780 writes its own nested argument0, below T. It does not rewrite
 // *arg0; only54BAC5 above changes this root's outer caller word.
 const U cell=lookup(local,local.r32(T+0x18u));
 local.w8(cell+0x11eu,U(i.arg[1])&255u);
 i.arg[0]=local.r32(T+0x18u);i.fp=child.fp;
 return (cell&0xffffff00u)|1u;
}
}
