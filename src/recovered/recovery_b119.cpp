#include "recovery_b119.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b119 {
// RVA372847, cdecl. Bounded exponent suffix after a caller-supplied prefix.
std::uint32_t fun_00772847(Memory&m,const Inputs&i){
 const auto destination=i.arg[0],state=i.arg[3];const auto q=m.r32(state+12);
 if(i.arg[1]||i.arg[4]||m.r32(state)==45||(m.r8(q)!='0'&&m.r8(q)!='1'))throw std::domain_error("outside119formattercontract");
 // Actual379010/379081 copies this original static terminated literal.
 m.w32(destination+1,m.r32(0x79c7a0));m.w16(destination+5,m.r16(0x79c7a4));
 if(i.arg[2])m.w8(destination+1,'E');
 if(m.r8(q)!='0'){
  int exponent=static_cast<int>(m.r32(state+4))-1;if(exponent < -256||exponent>255)throw std::domain_error("outside119exponentrange");
  if(exponent<0){exponent=-exponent;m.w8(destination+2,'-');}
  if(exponent>=100){m.w8(destination+3,m.r8(destination+3)+exponent/100);exponent%=100;}
  if(exponent>=10){m.w8(destination+4,m.r8(destination+4)+exponent/10);exponent%=10;}
  m.w8(destination+5,m.r8(destination+5)+exponent);
 }
 return destination;
}
}
