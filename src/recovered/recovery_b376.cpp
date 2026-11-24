#include "recovery_b376.hpp"
#include "platform/audio376.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b376 {
namespace {void require(bool x,const char*s){if(!x)throw std::domain_error(s);}}
void buffer_null_timer_callback(Memory&m,std::uint32_t receiver){
 require(m.r32(receiver+0x34u)==0,"B376 callback sole channel");
 constexpr std::uint32_t channel=0x8220d0u;auto&host=ra2::platform::audio376::host();
 const auto count=host.increment(channel+0xb8u);
 if(count==1 && !(m.r8(channel+0x28u)&1u)){
  host.enter(channel+0xa0u);
  require(m.r32(channel+0x8cu)==0,"B376 excludes populated playback buffer callback");
  host.leave(channel+0xa0u);
 }
 host.decrement(channel+0xb8u);
}
std::uint32_t fun_00761cc0(Memory&m,const Inputs&i){
 const auto receiver=i.cx;constexpr std::uint32_t channel=0x8220d0u;
 require(m.r32(receiver+0x78cu)!=0 && m.r32(receiver+0x58u)==0x4115a0u,"B376 requires original positive callback2 receiver");
 require(m.r32(0x819778u)!=0 && m.r32(0x8198ecu)!=0 && m.r8(channel)==0,"B376 requires real device and free sole channel");
 m.w32(receiver+0x7a0u,0);m.w32(receiver+0x7a4u,0xffffffffu);m.w32(receiver+0x7c4u,0);m.w32(receiver+0x38u,0);
 auto&host=ra2::platform::audio376::host();host.current_thread_id();
 m.w32(receiver+0x34u,0);
 for(unsigned k=0;k<0xbcu;++k)m.w8(channel+k,0);
 m.w8(channel,1);m.w32(channel+4u,m.r32(receiver+0xa4u));
 host.initialize_cs(channel+0xa0u);
 auto rate=m.r32(receiver+0xa0u);
 if(rate==0xffffffffu){
  const auto numerator=m.r32(receiver+0x70u),denominator=m.r16(receiver+0xeu);
  rate=m.r16(receiver+0x3cu);
  if(numerator!=denominator){require(denominator!=0,"B376 excludes DIVzero");rate=(rate*numerator)/denominator;}
 }
 m.w16(channel+8u,rate);
 const auto flags=host.get_caps_flags(m.r32(0x8198ecu));
 if(!(flags&0x20u))m.w32(receiver+0xc4u,0);
 m.w8(channel+0xau,m.r8(receiver+0x3eu));m.w8(channel+0xbu,m.r8(receiver+0x3fu));
 // Descriptor+4 is untouched by the original root. Preserve its explicit raw
 // entryESP-12 prestate rather than silently inventing a zero field.
 m.w32(channel+0x24u,i.stack_minus8);
 m.w32(0x8220c4u,0x761fc0u);m.w32(0x8220c8u,0x762110u);
 const auto period=host.begin_period16();require(period==0,"B376 successful real timeBeginPeriod route only");
 const auto timer=host.set_timer(0x412120u,receiver);require(timer!=0,"B376 successful real timer route only");
 m.w32(channel+0x60u,timer);
 m.w32(receiver+0x7bcu,m.r32(receiver+0x7bcu)|0x80000000u);
 return 0xffffffffu;
}
}
