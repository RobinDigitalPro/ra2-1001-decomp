#include "recovered/recovery_b146.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b146 {
std::uint32_t fun_007319f0(Memory&m,const Inputs&){
 if(m.r32(0xa5a874)!=0||m.r8(0xa28858)==0||m.r32(0x819778)==0||m.r8(0xa2894c)!=0)throw std::domain_error("146 stopped-state enabled preconditions");
 const bool active=m.r32(0xb0eca8)!=0;
 if(active){
  // 2dd590: null object -> AL0. 2dd460: current -1 -> already stopped.
  if(m.r32(0xa1e0d4)!=0||m.r32(0xa1e0a8)!=0xffffffff)throw std::domain_error("146 absentobject already-stopped contract");
 }else if(m.r32(0xa1e0ac)!=0xfffffffd)throw std::domain_error("146 same-current -3 branch required");
 const auto request=active?0xfffffffeu:0xfffffffdu;
 // Original 2dd0e0 writes +8 before the -2 / current-equality return.
 m.w32(0xa1e0b0,request);return request;
}
}
