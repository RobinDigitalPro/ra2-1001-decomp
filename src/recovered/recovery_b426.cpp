#include "recovery_b426.hpp"
#include <stdexcept>
namespace ra2::recovered::game426 {
std::uint32_t fun_00671be0(Memory&m,const Inputs&i){
 const auto type=i.arg[1],id=i.arg[2];unsigned category;
 if(type==15||type==16)category=2;
 else if(type==1||type==40||type==2||type==3)category=3;
 else if(type==57||type==32||type==31)category=1;
 else throw std::domain_error("426 selected direct categories only");
 const auto owner=i.cx+0x1540+0xe64*category,count=m.r32(owner+0x50);
 if(count<1||count>8)throw std::domain_error("426 positive bounded list");
 for(unsigned k=0;k<count;++k){const auto record=owner+0x54+48*k;
  if(m.r32(record)==id&&m.r32(record+4)==type){
   m.w32(owner+0x60+48*k,i.arg[0]);m.w8(owner+0x39,1);m.w8(owner+0x38,1);
   // Accepted4e0030's arg0==0 branch marks the current object dirty.
   const auto current=m.r32(0x821cac);if(!current)throw std::domain_error("426 positive current-object dirty mark");
   m.w8(current+0xd7d,1);return 1;
  }
 }
 throw std::domain_error("426 selected present record only");
}
std::uint32_t fun_004ef7e0(Memory&m,const Inputs&i){
 if(i.arg[1]!=0xffffffffu)throw std::domain_error("426 explicit direction-independent mode only");
 const auto x=static_cast<std::uint32_t>(static_cast<std::int16_t>(m.r16(i.dx)));
 const auto y=static_cast<std::uint32_t>(static_cast<std::int16_t>(m.r16(i.dx+2)));
 const auto index=(y-m.r32(i.cx+0x5648))*m.r32(i.cx+0x564c)+x-m.r32(i.cx+0x5644);
 const auto value=m.r32(m.r32(i.cx+0x15f44)+index*4);
 return i.arg[0]+((value<<7)*1000u);
}
}
