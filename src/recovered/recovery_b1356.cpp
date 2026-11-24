#include "recovery_b1356.hpp"
#include <stdexcept>
namespace ra2::recovered::b1356 {
namespace {
using U=std::uint32_t;
void need(bool value,const char* why){if(!value)throw std::domain_error(why);}
}
U fun_00626c10(Memory& m,const Inputs& i){
    const U mode=m.r8(0xa28953u);
    need(mode==1u,"B1356 explicit disabled-mode reset");
    m.w8(i.cx+0x14d6u,0u);m.w8(i.cx+0x14d5u,0u);
    return (i.ax&0xffffff00u)|mode;
}
U fun_006b3000(Memory& m,const Inputs& i){
    // 6B300E loads the complete request word before the optional-work flag.
    const U request=m.r32(i.arg[0]+4u);
    need((i.arg[1]&0xffu)==0u,"B1356 optional visual work disabled");
    m.w8(i.cx+0x80u,1u);
    return request;
}
U fun_006afc50(Memory& m,const Inputs& i){
    need(m.r8(i.cx+0x7cu)==1u,"B1356 pending state must be present");
    U actor=m.r32(i.cx+0x54u);
    need(actor!=0u,"B1356 requires a nonempty actor list");
    // Original aligned local BYTE[ESP+13] is produced as zero at6AFC69,
    // then loaded as a BYTE at6AFE0E; no unproduced DWORD is copied.
    unsigned visited=0;
    do {
        need(++visited<=3u,"B1356 finite one-to-three actor list");
        need(m.r8(actor+0x7du)==0u,"B1356 inactive actor branch");
        actor=m.r32(actor+0x4c8u);
    } while(actor!=0u);
    m.w8(i.cx+0x7cu,0u);
    return i.ax&0xffffff00u;
}
U fun_00481a90(Memory& m,const Inputs& i){
    (void)i;
    need(m.r32(0xa28988u)==1u&&m.r32(0xa255c8u)==1u,"B1356 actual pending command cancellation");
    const U house=m.r32(0xa1e0e4u);
    need(house!=0u&&m.r8(house+0x140u)==1u,"B1356 borrowed current-house cancellation state");
    m.w32(0xa28988u,0u);
    return house;
}
U fun_0061fff0(Memory& m,const Inputs& i){
    (void)i;
    const U houses=m.r32(0xa1a5d8u),count=m.r32(0x84e5a0u);
    need(houses==0u&&count==1u,"B1356 one actual ring record and no house dispatch");
    const U previous_bound=m.r32(0xa2556cu);(void)previous_bound;
    for(U k=0;k<count;++k){
        const U cursor=m.r32(0x84e5a4u);
        need(cursor==0u,"B1356 first physical ring record");
        const U record=0x84e5acu+111u*((cursor+k)&0x3fffu);
        need(m.r8(record)==0x1cu,"B1356 actual first-pass type1C exemption");
    }
    need(m.r32(0xa27f2cu)!=0u,"B1356 active timer start");
    const U deadline=m.r32(0xa27f30u);
    need(deadline!=0u&&m.r32(0xa27f34u)==0u,"B1356 active timer deadline and owner");
    for(U k=0;k<count;++k){
        const U cursor=m.r32(0x84e5a4u);
        need(cursor==0u,"B1356 stable ring cursor");
        const U record=0x84e5acu+111u*((cursor+k)&0x3fffu);
        need(m.r8(record)==0x1cu,"B1356 actual second-pass non13 record");
    }
    need(floating_b61::s32(m.r32(0xa2896cu))>floating_b61::s32(deadline),"B1356 signed timer expiry");
    m.w32(0xa27f2cu,0u);m.w32(0xa27f30u,0u);m.w32(0xa27f34u,0xffffffffu);
    return 1u;
}
}
