#include "recovered/recovery_b1582.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1582 {
namespace {using U=std::uint32_t;void need(bool ok){if(!ok)throw std::domain_error("B1582 finite Building numeric output query");}
U record_address(Memory&m,U self,U index){const auto count=global_b26::s32(global_b26::sx8(m.r8(self+0x5c6)));need(count==1&&index<static_cast<U>(count));const U q=m.r32(self+0x4c0+4*index);need(q!=0);const U address=q+28u*index+0x74c;need(m.r32(address)!=0);return address;}
U interpolate(Memory&m,U f){const U current=m.r32(f),old=m.r16(f+4),start=m.r32(f+8),duration=m.r32(f+0x10);const auto step=global_b26::s32(global_b26::sx16(m.r16(f+0x14)));const U frame=m.r32(0xa2896c);need(current==0xabcd5000u&&old==0x1000&&start==0xffffffffu&&duration==8&&step==0x400);U remaining=duration;if(start!=0xffffffffu){const U elapsed=frame-start;need(global_b26::s32(elapsed)<global_b26::s32(duration));remaining-=elapsed;}need(remaining!=0);const auto delta=global_b26::s32(global_b26::sx16((current-old)&65535u));const U magnitude=delta<0?0u-static_cast<U>(delta):static_cast<U>(delta);const auto steps=global_b26::s32(magnitude)/step;need(global_b26::s32(global_b26::sx16(static_cast<U>(steps)))>0);const auto divided=delta/global_b26::s32(global_b26::sx16(static_cast<U>(steps)));const U product=static_cast<U>(divided)*remaining;const U low=((current&65535u)-product)&65535u;return (current&0xffff0000u)|low;}
}
std::uint32_t run(Memory&m,const Inputs&i){const U self=i.cx,out=i.arg[0];need(m.r32(self)==0x787bbcu&&out!=0&&i.arg[1]==0);const U r=record_address(m,self,0u),w=m.r32(r);need(w!=0&&m.r8(w+0x121)==1);const U actual_building_type=m.r32(self+0x418);need(actual_building_type!=0);(void)actual_building_type; // Actual80/84->4538B0(self418), discarded; never Actor505DA0.
const U produced=interpolate(m,self+0x2c8);m.w32(out,produced);return out;}
}
