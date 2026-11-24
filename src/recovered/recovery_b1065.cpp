#include "recovered/recovery_b1065.hpp"
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::b1065 {
static void need(bool x){if(!x)throw std::domain_error("1065 outside positive existing-record contract");}
static unsigned channel(unsigned x,unsigned mode){const auto v=std::int32_t(x);const unsigned clamped=unsigned(std::max(0,std::min(1000,v)));return clamped& (mode==0u?0xffffff80u:mode==1u?0xffffffc0u:mode==2u?0xffffffe0u:0xffffffffu);}
std::uint32_t fun_005277f0(Memory&m,const Inputs&i){
 need(m.r32(0x821c90u)!=0u);const auto count=m.r32(0x81a6e8u),table=m.r32(0x81a6dcu);need(count>=2u&&count<=8u);
 if(i.cx==1000u&&i.dx==1000u&&i.arg[0]==1000u)return m.r32(table);
 const auto mode=m.r32(0xa2876cu);need(mode<=2u);const auto red=channel(i.cx,mode),green=channel(i.dx,mode),blue=channel(i.arg[0],mode);i.arg[0]=blue;
 for(unsigned j=1;j<count;++j){const auto p=m.r32(table+4u*j);if(m.r32(p+0x198u)==red&&m.r32(p+0x19cu)==green&&m.r32(p+0x1a0u)==blue)return p;}
 throw std::domain_error("1065 missing record allocation excluded");
}
std::uint32_t fun_00478cf0(Memory&m,const Inputs&i){
 const auto p=i.cx,next=i.arg[0];need(next!=0u);const auto old=m.r32(p+0x34u);
 if(old&&m.r8(0xa285a8u))m.w32(old+0x194u,m.r32(old+0x194u)-1u);
 m.w32(p+0x34u,next);m.w32(next+0x194u,m.r32(next+0x194u)+1u);
 const auto red=m.r32(next+0x198u),green=m.r32(next+0x19cu),blue=m.r32(next+0x1a0u);i.arg[0]=red;
 m.w32(p+0x104u,i.arg[1]);for(unsigned k=0;k<4u;++k)m.w16(p+0x108u+2u*k,std::uint16_t(i.arg[2u+k]));
 m.w16(p+0x110u,std::uint16_t(red));m.w16(p+0x112u,std::uint16_t(green));m.w16(p+0x114u,std::uint16_t(blue));
 return(i.arg[1]&0xffff0000u)|(green&0xffffu);
}
}
