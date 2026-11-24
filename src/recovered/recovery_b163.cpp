#include "recovered/recovery_b163.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b163 {
std::uint32_t fun_0059d7d0(Memory&m,const Inputs&,Heap&h){
 const auto count=m.r32(0xae0a68),array=m.r32(0xae0a5c);
 if(!array||count<1||count>32||!m.r8(0xae0a65)||m.r8(0xa58c34))
  throw std::domain_error("163 requires positive owned null vector and inactive audio");
 for(unsigned k=0;k<count;++k)if(h.r32(array+k*4))
  throw std::domain_error("163 nonnull element destructor outside recovered route");
 m.w32(0xae0a68,0);
 const auto result=h.release(array);
 m.w32(0xae0a5c,0);
 const auto flag=m.r8(0xa58c34);
 m.w8(0xae0a65,0);m.w32(0xae0a60,0);
 return (result&0xffffff00u)|flag;
}
}
