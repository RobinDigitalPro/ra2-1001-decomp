#include "recovered/recovery_b1563.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1563 {namespace {
using U=std::uint32_t;using namespace floating_b61;namespace fp=ra2::platform::x87;namespace ext=ra2::platform::x87_extended;namespace b61=ra2::platform::x87_b61;
void need(bool x,const char*s){if(!x)throw std::domain_error(s);}
U convert(Memory&m,fp::State&s){need(s.control()==m.r32(0x7c3a04u),"B1563 exact truncating CW cache");return U(s.pop_integer64());}
U height(Memory&m,fp::State&s,U x,U y,U z){
 (void)z;const auto xx=static_cast<std::int32_t>(x)/256,yy=static_cast<std::int32_t>(y)/256;
 need(xx>=0&&yy>=0,"B1563 valid nonnegative157070 coordinates");const U index=U(yy)*512u+U(xx);
 need(index<m.r32(0x81a95cu),"B1563 valid157070 table index");const U cell=m.r32(m.r32(0x81a958u)+4u*index);need(cell!=0,"B1563 populated cell");
 need((m.r8(0x838f70u)&7u)==7u,"B1563 warm702C0 cache");
 const U v=U(static_cast<std::int32_t>(static_cast<std::int8_t>(m.r8(cell+0x11bu))))*m.r32(0x838f80u);
 s.load_integer32(v);s.add64(read64(m,0x785728u));const U result=convert(m,s);need(m.r8(cell+0x11cu)==0,"B1563 flat702C0 cell");return result;
}
U sine(Memory&m,fp::State&s,std::uint64_t arg){
 s.load64(arg);s.multiply32(m.r32(0x7c3138u));const U converted=convert(m,s);const U sign=static_cast<std::int32_t>(converted)<0?0xffffffffu:0u;
 U index=U(static_cast<std::int32_t>(converted-sign)>>1)&0x80001fffu;
 if(static_cast<std::int32_t>(index)<0){index=(index-1u)|0xffffe000u;++index;if(static_cast<std::int32_t>(index)<0)index+=0x2000u;}
 if((converted&1u)&&static_cast<std::int32_t>(index)<0x1fff)++index;
 need(index==0,"B1563 selected real sine table0");s.load32(m.r32(0x7ea104u+4u*index));return converted;
}
}
U run(Memory&m,const Inputs&i){
 auto&s=i.fp;const U outer=i.cx,nested=m.r32(outer+0xcu);need(m.r32(nested)==0x78612cu,"B1563 authentic Aircraft table");
 need(m.r8(nested+0x79u)==0,"B1563 no bridgeoffset79");
 U h=height(m,s,m.r32(nested+0x88u),m.r32(nested+0x8cu),m.r32(nested+0x90u));
 const U relative=m.r32(nested+0x90u)-h;
 need(m.r32(nested+0x4d0u)==0xffffffffu,"B1563 selected unsetdirection");const U comparison_height=relative;
 s.load_integer32(relative);s.add64(read64(m,outer+0x60u));const U adjusted=convert(m,s);
 need(m.r32(nested+4u)==0x786110u,"B1563 genuine Air secondary addresspoint");const U id=m.r32(nested+0x10u);need(id==1u,"B1563 finite public secondary ID1");
 const U cfg=m.r32(0x821b88u);s.load64(read64(m,0x785708u));s.multiply64(read64(m,cfg+0x4f0u));s.multiply64(read64(m,0x786608u));
 const U numerator=m.r32(0xa2896cu)+id*2u;s.load_st0();const U divisor=convert(m,s);need(divisor!=0&&static_cast<std::int32_t>(divisor)>0,"B1563 defined signed division");
 const U remainder=U(static_cast<std::int32_t>(numerator)%static_cast<std::int32_t>(divisor));
 s.load_integer32(remainder);s.multiply64(read64(m,0x7879b8u));b61::reg<0xd8f1>(s);const auto angle=s.pop64();s.pop_st0();
 sine(m,s,angle);b61::reg<0xdcc0>(s);ext::add_integer32(s,adjusted);U value=convert(m,s);
 if(static_cast<std::int32_t>(value)<0){write64(m,outer+0x60u,0u);value=0;}
 const U old74=m.r8(nested+0x74u);m.w8(nested+0x74u,0u);
 // Actual B602 5CCF0D sees the ROOT-PRODUCED zero. Its 5CCF64 branch
 // calls populated157070 and stores90, with neither notification11C call.
 h=height(m,s,m.r32(nested+0x88u),m.r32(nested+0x8cu),m.r32(nested+0x90u));m.w32(nested+0x90u,h+value);m.w8(nested+0x74u,old74);
 const U threshold=m.r32(cfg+0x4ecu);need(static_cast<std::int32_t>(comparison_height)<static_cast<std::int32_t>(threshold),"B1563 reached53B410");
 need(m.r8(outer+0x10u)==0,"B1563 actual53B410 byte false");const U quarter=U(static_cast<std::int32_t>(threshold)/4);
 need(static_cast<std::int32_t>(comparison_height)>=static_cast<std::int32_t>(quarter),"B1563 no additionalthird adjustment");
 s.load_integer32(m.r32(cfg+0x1320u));s.reverse_subtract64(read64(m,outer+0x60u));write64(m,outer+0x60u,s.store64());s.multiply64(read64(m,cfg+0x510u));write64(m,outer+0x60u,s.pop64());
 return quarter;
}
}
