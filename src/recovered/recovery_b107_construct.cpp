#include "recovered/recovery_b107.hpp"

#include "recovered/records_b85.hpp"
#include "recovered/text_b104.hpp"
#include "recovered/leaf_b16_a.hpp"
#include "recovered/leaf_b17_init.hpp"

#include <array>
#include <stdexcept>

namespace ra2::recovered::global_b26 { std::uint32_t fun_00545490(Memory&,const Inputs&); }
namespace ra2::recovered::recovery_b107 {
using namespace global_b26;

std::uint32_t fun_005ce110(Memory& m,const Inputs& i) {
    const auto r=i.cx;
    if(m.r8(r+0x3du)!=0u)
        throw std::domain_error("Block107 0x1ce110 requires the observed zero +0x3d route");

    // Execute actual accepted 0xff60 writes in a checked local view. The
    // 0x106e0 stack argument is forwarded and ignored by that helper.
    std::array<std::uint8_t,16> init_bytes{};
    constexpr std::uint32_t init_base=0x35100000u;
    leaf::Memory init_memory(init_bytes.data(),init_base,static_cast<std::uint32_t>(init_bytes.size()));
    for(std::uint32_t k=0;k<4u;++k)init_memory.w32(init_base+k*4u,m.r32(r+k*4u));
    leaf::Inputs init{};init.cx=init_base;init.arg[0]=i.arg[0];
    (void)leaf::fun_0040ff60(init_memory,init);
    for(std::uint32_t k=0;k<4u;++k)m.w32(r+k*4u,init_memory.r32(init_base+k*4u));
    // 0x106e0 installs its own tags; with +0x3d still zero it stores the
    // fixed default pointer and skips the actual text lookup at 0x6eeb60.
    m.w32(r,0x00785e88u); m.w32(r+4u,0x00785e6cu);
    m.w32(r+8u,0x00785e64u);m.w32(r+0xcu,0x00785e5cu);
    m.w32(r+0x60u,0x0082208cu);

    m.w32(r+0xa4u,0);
    for(std::uint32_t k=0;k<15u;++k){m.w32(r+0xc8u+k*8u,0);m.w32(r+0xccu+k*8u,0);}
    for(std::uint32_t k=0;k<15u;++k){m.w32(r+0x140u+k*8u,0);m.w32(r+0x144u+k*8u,0);}
    constexpr std::array<std::uint32_t,16> zero_dwords={
        0x214u,0x218u,0x21cu,0x224u,0x228u,0x22cu,0x230u,0x238u,
        0x23cu,0x240u,0x244u,0x24cu,0x250u,0x254u,0x258u,0x260u};
    for(const auto off:zero_dwords)m.w32(r+off,0);
    for(const auto off:{0x220u,0x234u,0x248u,0x25cu})m.w8(r+off,0);
    m.w32(r,0x007926b8u);m.w32(r+4u,0x0079269cu);
    m.w32(r+8u,0x00792694u);m.w32(r+0xcu,0x0079268cu);
    return r;
}

std::uint32_t fun_00573d40(Memory& m,const Inputs& i) {
    const auto r=i.cx,embedded=r+0x20u,dest=r+0x78u;
    // 0x5392c0 initializes its embedded record before dispatching through
    // pinned vtable 0x790824. The observed slot is 0x53ac50; its freeing
    // path is unreachable after these zero stores.
    m.w32(embedded+4u,0);m.w32(embedded+8u,0);m.w8(embedded+0xcu,1);
    m.w8(embedded+0xdu,0);m.w32(embedded,0x00790824u);
    m.w32(embedded+0x14u,0xau);m.w32(embedded+0x10u,0);
    if(m.r32(0x00790830u)!=0x0053ac50u)
        throw std::domain_error("Block107 pinned embedded reset target differs from 0x53ac50");
    // Exact unconditional tail reset of the pinned target. Its release call
    // is skipped because the preceding constructor stores made +4 and +0xd 0.
    m.w32(embedded+0x10u,0);m.w8(embedded+0xdu,0);m.w32(embedded+8u,0);
    m.w32(r+4u,0);m.w32(r+0xcu,0);m.w32(r+0x14u,0);
    m.w32(r,0x007907fcu);m.w32(r+8u,0x007ca620u);m.w32(r+0x10u,0x800u);

    m.w32(r+0x38u,0);m.w32(r+0x3cu,1);m.w32(r+0x40u,1);m.w32(r+0x44u,0);
    m.w32(r+0x48u,1);m.w32(r+0x4cu,0);m.w32(r+0x50u,2);
    for(const auto off:{0x54u,0x58u,0x5cu,0x60u,0x64u,0x68u,0x6cu,0x70u})m.w32(r+off,0);
    m.w32(r+0x74u,0xffffffffu);m.w32(r,0x00790e04u);
    m.w32(r+8u,0x007cbfe4u);m.w16(dest,0);m.w32(r+0xcu,dest);

    // 0x6eecd0 is a direct load of [0xab7ecc]. A nonzero selector executes
    // the actual accepted dictionary lookup and 16-bit copy helper.
    if(m.r32(0x00ab7eccu)!=0u){
        Inputs lookup{};lookup.cx=0x007cbfb4u;lookup.dx=0;
        const auto source=text_b104::fun_006eeb60(m,lookup);
        std::array<std::uint8_t,0x200> copy_bytes{};
        constexpr std::uint32_t base=0x35000000u,local_source=base+0x20u,local_dest=base+0x120u;
        std::uint32_t units=0;
        for(;units<63u;++units){const auto ch=m.r16(source+units*2u);const auto offset=0x20u+units*2u;copy_bytes[offset]=static_cast<std::uint8_t>(ch);copy_bytes[offset+1u]=static_cast<std::uint8_t>(ch>>8);if(ch==0)break;}
        if(units==63u)throw std::domain_error("Block107 map description exceeds 63 UTF-16 units");
        leaf::Memory copy_memory(copy_bytes.data(),base,static_cast<std::uint32_t>(copy_bytes.size()));
        leaf::Inputs copy{};copy.arg[0]=local_dest;copy.arg[1]=local_source;
        (void)leaf::fun_0076efc9(copy_memory,copy);
        for(std::uint32_t k=0;k<=units;++k)m.w16(dest+k*2u,copy_memory.r16(local_dest+k*2u));
    }
    return r;
}

std::uint32_t fun_00423c70(Memory& m,const Inputs&) {
    const auto count=m.r32(0x00a285c0u);
    if(count==0u||count>4u)throw std::domain_error("Block107 0x23c70 requires object count 1..4");
    const auto object_array=m.r32(0x00a285b4u);
    if(!object_array)throw std::domain_error("Block107 0x23c70 object pointer array is null");
    for(std::uint32_t n=0;n<count;++n){
        const auto object=m.r32(object_array+n*4u),owner_state=m.r32(object+0xb0u);
        if(!object||!owner_state||m.r8(owner_state+0x31cu)==0u)
            throw std::domain_error("Block107 0x23c70 requires each object active");
        const auto coordinates=object+0x88u;
        if(m.r32(coordinates)!=0u||m.r32(coordinates+4u)!=0u)
            throw std::domain_error("Block107 0x23c70 requires zero x/y coordinates");
        Inputs map{};map.cx=0x0081a820u;map.arg[0]=coordinates;
        const auto cell=global_b26::fun_00545490(m,map);
        if(cell==0x00a57610u||cell==0u)
            throw std::domain_error("Block107 0x23c70 map cell lookup missed");

        // Actual 0x79e20 tail transition: ECX := [cell+0x44], then dispatch
        // to the accepted interval-hit body 0x1d4730.
        Inputs interval{};interval.cx=m.r32(cell+0x44u);
        const auto interval_index=records_b85::fun_005d4730(m,interval);
        if(interval_index==0xffffffffu)continue;
        const auto record=m.r32(m.r32(0x00aa863cu)+interval_index*4u);
        if(!record)continue;
        const auto owner_index=m.r32(record+0xc0u);
        const auto owner=m.r32(m.r32(0x00a9ea04u)+owner_index*4u);
        m.w32(object+0xbcu,m.r32(owner+0x30cu));
    }
    return count;
}
}
