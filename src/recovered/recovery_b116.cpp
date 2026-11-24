#include "recovery_b116.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b116 {
namespace {
void require(bool b){if(!b)throw std::domain_error("outside Block116 finite ordinary-heap contract");}
// Both original growth bodies clear the entire new request before copying the
// old live prefix. Their element widths and permitted counts are distinct.
std::uint32_t grow(Memory&m,const Inputs&i,Heap&h,unsigned stride,unsigned low,unsigned high){
 const auto count=m.r32(i.cx),capacity=m.r32(i.cx+4),old=m.r32(i.cx+8);
 require(!(i.arithmetic_flags&0x400)&&count==capacity&&count>=low&&count<=high&&old);
 const auto next=count*2,request=next*stride,fresh=h.allocate(request);require(fresh);
 for(unsigned k=0;k<request;++k)h.w8(fresh+k,0);
 for(unsigned k=0;k<count*stride;++k)h.w8(fresh+k,h.r8(old+k));
 const auto free_eax=h.release(old);m.w32(i.cx+4,next);m.w32(i.cx+8,fresh);
 return (free_eax&0xffffff00)|1;
}
}
// RVA1fa520, RET0, 4-byte elements.
std::uint32_t fun_005fa520(Memory&m,const Inputs&i,Heap&h){return grow(m,i,h,4,256,400);}
// RVA1fa5b0, RET0, 20-byte elements.
std::uint32_t fun_005fa5b0(Memory&m,const Inputs&i,Heap&h){return grow(m,i,h,20,52,80);}
// RVA359570, RET4. Different nonnull string holders; free precedes allocation.
std::uint32_t fun_00759570(Memory&m,const Inputs&i,Heap&h){
 require(!(i.arithmetic_flags&0x400));const auto old=m.r32(i.cx),source=m.r32(i.arg[0]);
 require(old&&source&&h.r8(old)=='A'&&m.r8(source)=='B');
 for(unsigned k=0;k<1017;++k)require(m.r8(source+k)!=0);require(m.r8(source+1017)==0);
 h.release(old);m.w32(i.cx,0);const auto fresh=h.allocate(1018);require(fresh);m.w32(i.cx,fresh);h.w8(fresh,0);
 for(unsigned k=0;k<1018;++k)h.w8(fresh+k,m.r8(source+k));return i.cx;
}
}
