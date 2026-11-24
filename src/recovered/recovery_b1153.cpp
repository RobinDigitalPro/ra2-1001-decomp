#include "recovery_b1153.hpp"
#include <stdexcept>
namespace ra2::recovered::b1153{
namespace{
void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
void bounded_copy(Memory&m,unsigned to,unsigned from,unsigned count,unsigned width){bool ended=false;for(unsigned n=0;n<count;++n){unsigned value=0u;if(!ended){value=m.r8(from+n*width);if(width==2u)value|=m.r8(from+n*width+1u)<<8u;ended=value==0u;}m.w8(to+n*width,value&255u);if(width==2u)m.w8(to+n*width+1u,value>>8u);}}
void vector_zero(Memory&m,unsigned p,unsigned tag){m.w32(p+4u,0u);m.w32(p+8u,0u);m.w8(p+12u,1u);m.w8(p+13u,0u);m.w32(p,tag);}
}
unsigned run(Memory&m,const Inputs&i,Heap&heap){
 need(i.arg[0]&&i.arg[1]&&i.arg[2],"1153 explicit nonnull input route");need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u,"1153 exact ordinary-heap fixture");const unsigned self=i.cx,numbers=self+0x188u,strings=self+0x1a4u;
 // Genuine zero-count member construction precedes bounded text copies.
 vector_zero(m,numbers,0x7944ccu);m.w32(numbers+20u,10u);m.w32(numbers+16u,0u);m.w32(numbers,0x79452cu);vector_zero(m,strings,0x7944ecu);m.w32(strings,0x79450cu);m.w32(strings+20u,10u);m.w32(strings+16u,0u);
 bounded_copy(m,self+0x58u,i.arg[0],260u,1u);m.w8(self+0x15bu,0u);bounded_copy(m,self,i.arg[1],44u,2u);m.w8(self+0x56u,0u);m.w8(self+0x57u,0u);bounded_copy(m,self+0x15cu,i.arg[2],32u,1u);m.w8(self+0x17bu,0u);m.w8(self+0x17cu,i.arg[3]&255u);m.w32(self+0x180u,2u);m.w32(self+0x184u,4u);
 // Actual 79452C+C target 669150 clears the freshly produced empty vector.
 m.w32(numbers+16u,0u);m.w8(numbers+13u,0u);m.w32(numbers+8u,0u);
 // Actual 79452C+8 target 669540(10,null): raw plain-DWORD storage,
 // no cookie and no invented initialization of the nine spare elements.
 m.w8(numbers+12u,0u);const auto backing=heap.allocate(40u);m.w8(numbers+12u,1u);need(backing,"1153 positive genuine reserve10 allocation");m.w32(numbers+4u,backing);m.w32(numbers+8u,10u);m.w8(numbers+13u,1u);m.w32(numbers+16u,1u);heap.w32(backing,0xfffffffeu);return self;
}
unsigned clear(Memory&m,unsigned self,Heap&heap){const unsigned numbers=self+0x188u;need(m.r32(numbers)==0x79452cu&&m.r32(numbers+4u)&&m.r32(numbers+8u)==10u&&m.r8(numbers+13u)==1u&&m.r32(numbers+16u)==1u,"1153 exact retained owned vector clear");m.w32(numbers+16u,0u);const auto result=heap.release(m.r32(numbers+4u));need(result!=0u,"1153 raw successful backing release");m.w32(numbers+4u,0u);m.w8(numbers+13u,0u);m.w32(numbers+8u,0u);return result;}
}
