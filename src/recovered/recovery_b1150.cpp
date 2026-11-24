#include "recovered/recovery_b1150.hpp"
#include <stdexcept>
namespace ra2::recovered::b1150 {
unsigned run(unsigned root,Memory&m,const Inputs&i,State&){if(root!=0x22d3a0u||m.r8(i.cx)!=1u||m.r8(i.cx+1u)!=0u||m.r32(i.cx+8u)!=2u)throw std::domain_error("1150 initialized caller-suppressed type2 lifetime");const auto old=m.r32(i.cx+0x6cu),duration=m.r32(i.cx+0x34u);if(duration<5u||duration>20u||old<1u||old>=duration)throw std::domain_error("1150 authentic duration/current producer range");const auto next=old+1u;m.w32(i.cx+0x6cu,next);return(next&0xffffff00u)|unsigned(std::int32_t(next)>=std::int32_t(duration));}
}
