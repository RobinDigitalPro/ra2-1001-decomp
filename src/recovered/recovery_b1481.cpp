#include "recovered/recovery_b1481.hpp"
namespace ra2::recovered::b1481 {
std::uint32_t fun_00411d80(Memory&m,const Inputs&i,platform::critical1481::Observer&api){
 using U=std::uint32_t;namespace fp=platform::x87;using platform::critical1481::need;
 const U receiver=i.arg[0],buffer=i.arg[1],length=i.arg[2];
 need(buffer&&length&&m.r32(receiver+0x34u)==0u,"1481 sole initialized channel/nonempty buffer");
 constexpr U channel=0x8220d0u;
 need(m.r32(channel+0x8cu)==0u&&m.r32(channel+0x40u)<2u,"1481 postinit nullDS/index domain");
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 try{
  api.enter(channel+0xa0u);
  const U index=m.r32(channel+0x40u);need(m.r32(channel+0x48u+4u*index)!=1u,"1481 available ring slot");
  m.w32(channel+0x50u+4u*index,buffer);m.w32(channel+0x58u+4u*index,length);m.w32(channel+0x48u+4u*index,1u);
  //411E6B reselects the sole channel; nullDS skips playback, not these publications.
  need(m.r32(receiver+0x34u)==0u&&m.r32(channel+0x8cu)==0u,"1481 stable actual selected channel");
  m.w32(channel+0x40u,index+1u>=2u?0u:index+1u);
  api.leave(channel+0xa0u);
  i.fp.image=fp::capture_host();fp::restore_host(host);return 0xffffffffu;
 }catch(...){fp::restore_host(host);throw;}
}
}
