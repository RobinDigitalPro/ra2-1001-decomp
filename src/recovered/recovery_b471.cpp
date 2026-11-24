#include "recovery_b471.hpp"
#include "platform/observed_ticks152.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b471 {
namespace {void need(bool b){if(!b)throw std::domain_error("471 positive cell action contract");}}
std::uint32_t fun_0060c680(Memory&m,const Inputs&i){
 const auto descriptor=m.r32(m.r32(m.r32(i.cx+4))+4);
 const unsigned off=m.r8(descriptor+0x12)?0xe:m.r8(descriptor+0x1c)?0x18:0x13;
 need(m.r8(descriptor+off+4)==11);
 const auto packed=m.r32(descriptor+off);need(packed<32000000);
 const unsigned x=packed%1000,y=packed/1000;need(x<512&&y<512);
 const auto table=m.r32(0x81a958);
 const auto cell=m.r32(table+4*(512*y+x));need(cell!=0);
 // Exact constructor 470B10 writes this primary vptr. Its +2C slot is
 // original 47CB80: MOV EAX,11 / RET, rather than a substituted callback.
 need(m.r32(cell)==0x788b04&&m.r32(0x788b30)==0x47cb80);
 const auto coords=m.r32(cell+0x24);
 const auto cx=static_cast<std::int16_t>(coords&0xffff),cy=static_cast<std::int16_t>(coords>>16);
 const auto reference=std::uint32_t(std::int32_t(cx)+1000*std::int32_t(cy));
 const auto owner=m.r32(m.r32(0xa1e0e4)+0x30);need(std::int32_t(owner)>=0);
 (void)m.r32(0x7c17ac); // Original action44 name-table read before no-op68F0.
 const auto count=m.r32(0xa1a668),tail=m.r32(0xa1a670);need(count<128&&tail<128);
 std::array<std::uint8_t,111> event;
 for(unsigned k=0;k<event.size();++k)event[k]=std::uint8_t(i.stack_minus8>>(8*(k%4)));
 event[0]=44;event[2]=std::uint8_t(owner);event[11]=11;
 const auto timer=m.r32(0xa2896c);
 for(unsigned k=0;k<4;++k){event[3+k]=std::uint8_t(timer>>(8*k));event[7+k]=std::uint8_t(reference>>(8*k));}
 for(unsigned k=0;k<111;++k)m.w8(0xa1a674+111*tail+k,event[k]);
 m.w32(0xa1ddf4+4*tail,ra2::platform::ticks152::Tick::get());
 m.w32(0xa1a670,(tail+1)&127);m.w32(0xa1a668,count+1);
 return ((count+1)&0xffffff00u)|1u;
}
}
