#include "recovered/recovery_b1440.hpp"
#include <stdexcept>
namespace ra2::recovered::b1440 {
std::uint32_t fun_004b2ae0(Memory&m,const Inputs&i){
 if(i.arg[0]!=8u)throw std::domain_error("1440 positive backspace contract");
 // 497830 is the actual MOV EAX,[836D30]/RET accessor. Its result is
 // preserved in EBX by the caller but is unused on the selected branch.
 (void)m.r32(0x836d30u);
 const auto length=m.r32(i.cx+0x3cu),buffer=m.r32(i.cx+0x34u);
 if(length==0u||length>640u||m.r32(i.cx)!=0x78b7bcu)
  throw std::domain_error("1440 coherent original editor projection");
 const auto next=length-1u;
 m.w32(i.cx+0x3cu,next);m.w16(buffer+2u*next,0u);
 // The constructor-installed table's +48 slot is the original five-byte
 // 4CF180 body. It writes the dirty byte and preserves EAX=next.
 if(m.r32(m.r32(i.cx)+0x48u)!=0x4cf180u)
  throw std::domain_error("1440 original mark-dirty provider");
 m.w8(i.cx+0x1cu,1u);
 return (next&0xffffff00u)|1u;
}
}
