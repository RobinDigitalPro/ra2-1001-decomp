#include "recovered/recovery_b164.hpp"
#include "platform/observed_ticks152.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b164 {
using Scratch=std::array<std::uint8_t,112>;
std::uint32_t fun_006eac40(Memory&m,const Inputs&i,const Scratch&entry_stack) {
    const auto frame=m.r32(0x00a2896cu);
    const auto threshold=m.r32(0x00aa8dc8u);
    if(static_cast<std::int32_t>(frame)<static_cast<std::int32_t>(threshold)||m.r32(0xa1a668)>127||m.r32(0xa1a670)>127)throw std::domain_error("164 positive bounded ring route required");
    {
        const auto object=m.r32(0x00a1e0e4u);
        const auto value=m.r32(object+0x30u);
        // RVA 0xb5ce0 reads the table word and calls exact RVA 0x68f0 (a
        // one-byte RET); that call changes no registers or memory.
        const auto lookup=m.r32(0x007c16fcu+4u*0x2du);(void)lookup;
        auto record=entry_stack;
        if(static_cast<std::int32_t>(value)>=0){record[0]=0x2d;record[2]=std::uint8_t(value);}
        else {record[0]=0;record[2]=0xff;}
        record[3]=std::uint8_t(frame);record[4]=std::uint8_t(frame>>8);
        record[5]=std::uint8_t(frame>>16);record[6]=std::uint8_t(frame>>24);
        const auto count=m.r32(0x00a1a668u);
        if(static_cast<std::int32_t>(count)<0x80) {
            const auto index=m.r32(0x00a1a670u);
            const auto destination=0x00a1a674u+111u*index;
            for(unsigned k=0;k<111;++k)m.w8(destination+k,record[k]);
            const auto tick=ra2::platform::ticks152::Tick::get();
            m.w32(0x00a1ddf4u+4u*index,tick);
            m.w32(0x00a1a670u,(index+1u)&0x7fu);
            m.w32(0x00a1a668u,count+1u);
        }
    }
    const auto timer_object=m.r32(0x00821b88u);
    const auto result=m.r32(0x00a2896cu);
    m.w32(0x00aa8dc8u,m.r32(timer_object+0x4a0u)+result);
    (void)i; // original root does not consume its entry registers or arguments.
    return result;
}
}

