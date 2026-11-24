#include "recovered/recovery_b1068.hpp"
#include <stdexcept>
namespace ra2::recovered::b1068 {
static void need(bool x){if(!x)throw std::domain_error("1068 outside positive vertical contiguous scroll contract");}
static std::uint32_t scroll(Memory&m,const Inputs&i){
 const auto p=i.cx,width=m.r32(p+0x28u),height=m.r32(p+0x2cu),old=m.r32(p+0x10u),base=m.r32(p+0x18u),rows=i.arg[1],pixel=i.arg[2]&65535u;
 need(i.arg[0]==0u&&width>=4u&&width<=31u&&height>=4u&&height<=23u&&rows>=1u&&rows<height&&old<width*height*2u&&(old&1u)==0u);
 const auto row=(old/2u)/width;need((base&1u)==0u&&row+rows<height&&m.r32(p+0x20u)==width*height*2u&&m.r32(p+0x1cu)==base+width*height*2u);
 const auto next=old+2u*width*rows;m.w32(p+0x24u,m.r32(p+0x24u)-rows);m.w32(p+0x10u,next);i.arg[2]=row+rows;
 // Actual no-wrap vertical route emits an optional aligned WORD, repeated
 // DWORD pairs, then an optional final WORD. EAX is the last pair-end address.
 auto destination=base+old;unsigned count=width*rows;
 if((destination&2u)&&count){m.w16(destination,std::uint16_t(pixel));destination+=2u;--count;}
 const auto pairs=count/2u;unsigned eax=0u;
 if(pairs){for(unsigned j=0;j<pairs;++j)m.w32(destination+4u*j,pixel|(pixel<<16u));eax=destination+4u*pairs;}
 if((count&1u)&&eax)m.w16(eax,std::uint16_t(pixel));
 return eax;
}
std::uint32_t fun_00410c50(Memory&m,const Inputs&i){return scroll(m,i);}
std::uint32_t fun_007616a0(Memory&m,const Inputs&i){return scroll(m,i);}
}
