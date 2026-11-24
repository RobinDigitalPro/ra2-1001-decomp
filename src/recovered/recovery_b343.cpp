#include "recovery_b343.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b343 {
static void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
unsigned fun_0060dab0(Memory&m,const Inputs&){
 need(m.r8(0xa5e2fc)!=0,"343 enabled predicate");const auto descriptor=m.r32(0xa1e0e4),index=m.r32(descriptor+0x30);
 need(index<8,"343 valid base-count index");auto aggregate=m.r32(0xa5e1dc+4*index);need(aggregate<=129,"343 bounded positive base count");
 const auto count=m.r32(0xa288b0);need(count<=3,"343 bounded object list");auto eax=descriptor;
 for(unsigned n=0;n<count;++n){const auto object=m.r32(m.r32(0xa288a4)+4*n);if(!object||(m.r8(object+0x14)&1)==0)continue;
  eax=m.r32(object+0x408); // Exact seven-byte6c69a0 getter across explicit spans.
  if(!eax||m.r32(eax+0x14)==0)++aggregate;
 }
 if(aggregate>128)need(m.r8(0xa5e220)!=0,"343 already-warned state excludes UI construction");
 return (eax&0xffffff00)|unsigned(aggregate<=128);
}
}
