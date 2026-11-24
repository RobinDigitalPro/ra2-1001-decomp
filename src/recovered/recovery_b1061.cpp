#include "recovered/recovery_b1061.hpp"
#include <stdexcept>
namespace ra2::recovered::b1061 {
static void need(bool x){if(!x)throw std::domain_error("1061 outside populated uncompressed event ring contract");}
// Original table at7C16CC, all46 bytes pinned and checked during integration.
static constexpr unsigned char lengths[]{0,5,5,4,23,24,5,5,0,5,5,16,0,4,12,12,12,5,8,0,16,5,5,4,4,0,0,1,7,0,10,4,5,2,0,4,4,104,48,0,4,5,10,0,5,4};
std::uint32_t fun_0061f2d0(Memory&m,const Inputs&i){
 need(m.r32(0xa1a668u)>=1u&&m.r32(0xa1a668u)<=7u&&m.r32(0xa1a66cu)<128u&&m.r32(0x84e5a8u)<16384u&&i.arg[2]>=1u&&i.arg[2]<=7u);
 unsigned done=0;
 while(m.r32(0xa1a668u)&&done<i.arg[2]){
  const unsigned head=m.r32(0xa1a66cu),row=0xa1a674u+111u*head,type=m.r8(row);
  need(type<46u&&type!=4u&&type!=31u&&lengths[type]>0u);
  const unsigned bytes=lengths[type];if(i.arg[1]+bytes+1u>i.dx)break;
  unsigned frame=m.r32(0xa2896cu)+i.arg[0];
  if(m.r32(0xa255dcu)==2u){const auto step=m.r32(0xa25894u);need(step>=1u&&step<=7u);frame=((frame+step-1u)/step)*step;}
  m.w32(row+3u,frame);m.w8(row+2u,m.r8(m.r32(0xa1e0e4u)+0x30u));m.w8(row+1u,m.r8(row+1u)&0xfeu);
  need(m.r32(0x84e5a0u)<16384u);
  const auto tail=m.r32(0x84e5a8u),dst=0x84e5acu+111u*tail;
  for(unsigned k=0;k<111u;++k)m.w8(dst+k,m.r8(row+k));
  m.w32(0xa0a5acu+4u*tail,m.r32(0xa1ddf4u+4u*head));m.w32(0x84e5a8u,(tail+1u)&16383u);m.w32(0x84e5a0u,m.r32(0x84e5a0u)+1u);
  const auto out=i.cx+i.arg[1];m.w8(out,type);const auto payload=row+(type==27u?13u:7u);
  for(unsigned k=0;k<bytes;++k)m.w8(out+1u+k,m.r8(payload+k));
  i.arg[1]+=bytes+1u;++done;m.w32(0xa1a66cu,(head+1u)&127u);m.w32(0xa1a668u,m.r32(0xa1a668u)-1u);
 }
 m.w32(i.arg[3],done);return i.arg[1];
}
}
