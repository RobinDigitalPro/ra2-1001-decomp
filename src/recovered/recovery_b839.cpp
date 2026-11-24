#include "recovered/recovery_b839.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b839 {
std::uint32_t fun_004c87b0(Memory& m,const Inputs& in) {
    const auto self=in.cx, target=in.arg[0], count=m.r32(self+0x4ac);
    const auto active=m.r32(self+0x494);
    if(!target || !active || count>7) throw std::domain_error("839 outside reviewed navigation route");
    if(target==self && count>0) {
        m.w8(self+0x59b,1);
    } else {
        if(count>=m.r32(self+0x4a4)) throw std::domain_error("839 queue growth not recovered");
        if(count==0) m.w8(self+0x59b,0);
        m.w32(self+0x4ac,count+1);
        m.w32(m.r32(self+0x4a0)+count*4,target);
    }
    return active;
}
}
