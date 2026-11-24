#include "recovery_b498.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b498 {
namespace {
using U=std::uint32_t;
U lookup(Memory&m,U packed){
 const auto index=std::int32_t(std::int16_t(packed))+512*std::int32_t(std::int16_t(packed>>16));
 if(index<0||index>=0x40000)throw std::domain_error("498 interior cells");
 const U p=m.r32(m.r32(0x81a958)+4*U(index));
 if(!p)throw std::domain_error("498 populated neighborhood");
 return p;
}
void enqueue(Memory&m,U cell){
 const U owner=0x81a820,array=m.r32(owner+0x1224),count=m.r32(owner+0x1230);
 if(count>64)throw std::domain_error("498 bounded update queue");
 const U packed=m.r32(cell+0x24);
 for(U k=count;k;k--)if(m.r32(array+4*(k-1))==packed)return;
 if(count>=m.r32(owner+0x1228))throw std::domain_error("498 spare queue capacity");
 m.w32(array+4*count,packed);m.w32(owner+0x1230,count+1);m.w8(owner+0x14d5,1);
}
U visit(Memory&m,U packed,U desired,unsigned depth,U*root_args){
 if(depth>32)throw std::domain_error("498 bounded connected component");
 const U cell=lookup(m,packed),flags=m.r32(cell+0x140);
 U eax=(flags>>13)&0xffffff01u;
 if((desired&255)==(eax&255))return eax;
 const U type=m.r32(cell+0x38);
 m.w32(cell+0x140,(flags&~0x2000u)|((desired&1)<<13));
 enqueue(m,cell);
 if(root_args)root_args[0]=type;
 for(U k=0;k<8;++k){
  const U delta=m.r32(0x839da0+4*k);
  const U xy=U(std::uint16_t(packed+delta))|(U(std::uint16_t((packed>>16)+(delta>>16)))<<16);
  if(root_args)root_args[1]=root_args[2]=xy;
  eax=lookup(m,xy);
  if(m.r32(eax+0x38)==type)eax=visit(m,xy,desired,depth+1,nullptr);
 }
 return eax;
}
}
std::uint32_t fun_0054e340(Memory&m,const Inputs&i){
 if(!(i.arg[2]&255))throw std::domain_error("498 propagation entry excludes redraw");
 return visit(m,m.r32(i.arg[0]),i.arg[1],0,i.arg.data());
}
}
