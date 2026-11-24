#include "recovery_b478.hpp"
#include <algorithm>
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b478 {
namespace {
using U=std::uint32_t;
void need(bool b){if(!b)throw std::domain_error("478 bounded buffered stream contract");}
void open_buffer(Memory&m,U self){
 need(m.r32(self)==0x78773c&&m.r32(0x787754)==0x42f600);
 need(m.r8(self+0x21)&&m.r8(self+0x25)&&m.r8(self+0x23));
}
U write(Memory&m,U self,U source,U size){
 open_buffer(m,self);need(m.r32(self+0x28)!=1&&size>0);
 const auto pos=m.r32(self+0x34),cap=m.r32(self+0x30),buffer=m.r32(self+0x2c);
 need(pos<cap&&size<cap-pos&&cap<=4096);
 need(source+size<=buffer+pos||buffer+pos+size<=source);
 for(U k=0;k<size;++k)m.w8(buffer+pos+k,m.r8(source+k));
 m.w8(self+0x24,1);
 auto low=m.r32(self+0x3c),high=m.r32(self+0x40);
 if(low==0xffffffffu){low=pos;high=pos;}else if(static_cast<std::int32_t>(low)>static_cast<std::int32_t>(pos))low=pos;
 const auto end=pos+size;
 m.w32(self+0x3c,low);m.w32(self+0x40,std::max(high,end));m.w32(self+0x34,end);
 const auto absolute=m.r32(self+0x38)+end;m.w32(self+0x48,absolute);
 if(static_cast<std::int32_t>(m.r32(self+0x44))<static_cast<std::int32_t>(absolute))m.w32(self+0x44,absolute);
 return size;
}
}
std::uint32_t fun_0042f730(Memory&m,const Inputs&i){return write(m,i.cx,i.arg[0],i.arg[1]);}
std::uint32_t fun_0042f980(Memory&m,const Inputs&i){
 const auto self=i.cx;open_buffer(m,self);need(m.r32(self+0x28)!=2);
 const auto pos=m.r32(self+0x34),cap=m.r32(self+0x30),size=i.arg[1],buffer=m.r32(self+0x2c),dest=i.arg[0];
 need(size>0&&pos<cap&&size<cap-pos&&cap<=4096);
 need(dest+size<=buffer+pos||buffer+pos+size<=dest);
 for(U k=0;k<size;++k)m.w8(dest+k,m.r8(buffer+pos+k));
 m.w32(self+0x34,pos+size);m.w32(self+0x48,m.r32(self+0x38)+pos+size);return size;
}
std::uint32_t fun_0042fb90(Memory&m,const Inputs&i){
 const auto self=i.cx;need(m.r8(self+0x25)!=0&&i.arg[1]<=2);
 const auto length=m.r32(self+0x44),capacity=m.r32(self+0x30),base=m.r32(self+0x38),bias=m.r32(self+0x4c);
 auto position=m.r32(self+0x48);if(i.arg[1]==0)position=0;else if(i.arg[1]==2)position=length;
 auto offset=i.arg[0];bool biased=bias&&static_cast<std::int32_t>(offset)>=static_cast<std::int32_t>(bias);
 if(biased)offset-=bias;
 position+=offset;if(static_cast<std::int32_t>(position)<0)position=0;
 if(static_cast<std::int32_t>(position)>static_cast<std::int32_t>(length))position=length;
 m.w32(self+0x48,position);
 if(length<=capacity)m.w32(self+0x34,position);
 else{need(position>=base&&position<base+capacity);m.w32(self+0x34,position-base);}
 return position+(biased?bias:0);
}
std::uint32_t fun_00621700(Memory&m,const Inputs&i){
 (void)i;need(m.r32(0xa2896c)!=0&&m.r32(0xa278c4+0x54)==0);
 const U count=m.r32(0x84e5a0),head=m.r32(0x84e5a4),time=m.r32(0xa2896c);need(count>0&&count<=6&&head<16);
 auto event=[&](U j){return 0x84e5acu+111*((head+j)&0x3fffu);};
 auto eligible=[&](U j){const auto p=event(j);return m.r32(p+3)==time&&(m.r8(p+1)&1)==0;};
 U selected=0;for(U j=0;j<count;++j)if(eligible(j))++selected;
 std::array<std::uint8_t,4>tmp{};leaf::Memory span(tmp.data(),0x7f100000,4);Memory local=m;local.add(span);local.w32(0x7f100000,selected);
 write(local,0xa278c4,0x7f100000,4);
 for(U j=0;j<count;++j)if(eligible(j))write(local,0xa278c4,event(j),111);
 return count;
}
}
