#include "recovered/recovery_b1348.hpp"
#include "recovered/numeric_b88.hpp"
#include "recovered/numeric_b105.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1348 {
namespace {using U=std::uint32_t;void need(bool v,const char*why){if(!v)throw std::domain_error(why);}}
U fun_004b1f20(Memory&outer,const Inputs&i){
 need(outer.r32(0x83b390u)==1u,"B1348 nonempty one-record registry");
 need(i.fp.image.word(8)==0xffffu&&(i.fp.image.word(4)&0x3800u)==0u,"B1348 actual clipper needs eight free registers");
 constexpr U base=0x7dc00000u,T=base+0x8000u;std::array<std::uint8_t,0x10000> bytes{};
 leaf::Memory local(bytes.data(),base,U(bytes.size()));Memory m=outer;m.add(local);U result=i.ax;
 for(int index=int(m.r32(0x83b390u))-1;index>=0;--index){
  const U object=m.r32(m.r32(0x83b384u)+4u*U(index));
  need(m.r32(object+0x20u)==0u,"B1348 legitimate unattached stored-endpoint record");
  const U lifetime=m.r32(object+0x28u);need(lifetime>=4u&&lifetime<=1024u,"B1348 retained positive lifetime excludes deletion");
  Inputs projection{};projection.cx=m.r32(0x821cacu);projection.arg[0]=object;projection.arg[1]=T+0x1cu;projection.fp=i.fp;
  numeric_b88::fun_00698010(m,projection);i.fp=projection.fp;
  projection.arg[0]=object+12u;projection.arg[1]=T+0x14u;projection.fp=i.fp;
  numeric_b88::fun_00698010(m,projection);i.fp=projection.fp;
  // These are actual produced coordinates. Both endpoints are outside
  // the real clip rectangle; the real clipper still executes its numeric
  // outcode computation, before lifetime progression continues in root.
  need(m.r32(T+0x1cu)>=300u&&m.r32(T+0x14u)==m.r32(T+0x1cu)+30u&&
   m.r32(T+0x18u)==m.r32(T+0x20u)+15u,"B1348 finite offscreen nondegenerate segment");
  Inputs clip{};clip.cx=T+0x1cu;clip.dx=T+0x14u;clip.arg[0]=0x821970u;clip.fp=i.fp;
  const U clipped=numeric_b105::fun_00760f60(m,clip);i.fp=clip.fp;
  need((clipped&255u)==0u,"B1348 actual rejected clip excludes visible B1610 drawing");
  m.w32(object+0x1cu,m.r32(object+0x1cu)+1u);
  m.w32(object+0x28u,floating_b61::sar(m.r32(object+0x28u),1u));
  result=m.r32(object+0x28u);need(result!=0u,"B1348 original nonzero-duration retention");
 }
 // Original4B2033 supplies fullEAX; DECEDI/JNS do not change it. No outer
 // caller word is written; projection flag and clipping args stay private.
 return result;
}
}
