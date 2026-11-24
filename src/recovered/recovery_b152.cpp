#include "recovered/recovery_b152.hpp"
#include "platform/observed_ticks152.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b152 {
std::uint32_t fun_00625f10(Memory&m,const Inputs&i){
 const auto frame=m.r32(0xa2896c),mode=m.r32(0xa255dc),count=m.r32(0x84e5a0),oldhead=m.r32(0x84e5a4);
 if(count>=0x4000||oldhead>32)throw std::domain_error("152 sparecapacity boundedringhead");
 auto next=frame+1;
 if(mode==2){const auto period=m.r32(0xa25894);if(period<1||period>32)throw std::domain_error("152 nonzero finiteperiod");next=((period+frame)/period)*period;}
 m.w32(i.cx+3,next);const auto head=oldhead?oldhead-1:0x3fff;m.w32(0x84e5a4,head);
 const auto destination=0x84e5ac+111*head;
 for(unsigned k=0;k<27;++k)m.w32(destination+k*4,m.r32(i.cx+k*4));
 m.w16(destination+108,m.r16(i.cx+108));m.w8(destination+110,m.r8(i.cx+110));
 const auto ticks=ra2::platform::ticks152::Tick::get();m.w32(0xa0a5ac+head*4,ticks);
 const auto result=m.r32(0x84e5a0)+1;m.w32(0x84e5a0,result);return result;
}
}
