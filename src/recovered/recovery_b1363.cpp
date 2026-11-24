#include "recovery_b1363.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1363 {
namespace {
using U=std::uint32_t;
constexpr U map=0x81a820u;
void need(bool x,const char* message){if(!x)throw std::domain_error(message);}
void map_prestate(Memory& m){
    need(m.r32(map)==0x785954u&&m.r32(map+0xf0u)==4u&&m.r32(map+0xf4u)==4u,"B1363 borrowed width4 height4 Map layout");
    need(m.r32(map+0x138u)!=0u,"B1363 valid borrowed slot table");
}
U original_557340(Memory& m){
    const U width=m.r32(map+0xf0u),table=m.r32(map+0x138u);
    m.w32(map+0x108u,1u);m.w32(map+0x10cu,width);m.w32(map+0x110u,width-1u);
    const U cursor=table+(width<<11u)+4u;m.w32(map+0x114u,cursor);return cursor;
}
U original_557280_nonzero_remaining(Memory& m){
    const U remaining=m.r32(map+0x110u),cursor=m.r32(map+0x114u);
    need(remaining>=1u&&remaining<=3u,"B1363 actual iterator nonzero-remaining branch");
    const U x=m.r32(map+0x108u),y=m.r32(map+0x10cu);
    m.w32(map+0x108u,x+1u);m.w32(map+0x10cu,y-1u);m.w32(map+0x110u,remaining-1u);
    m.w32(map+0x114u,cursor-0x7fcu);
    return m.r32(cursor);
}
U original_498cf0_null(Memory& m){
    need(m.r32(map+0x1178u)==0u,"B1363 original null Map context branch");
    m.w32(map+0x1174u,m.r32(0x83a940u));m.w32(map+0x1178u,0u);return 0u;
}
U original_56a9b0(Memory& m,U index){return m.r32(0xa5863cu)+((index+index*4u)<<4u);}
U original_58a950(Memory& m,U record,const std::array<std::uint16_t,2>& local){
    if(m.r16(record)!=local[0])return 1u;
    return m.r16(record+2u)!=local[1]?1u:0u;
}
U matrix_prestate(Memory& m,U eligibility){
    const U n=m.r32(0x836b4cu),records=m.r32(0xa5863cu);
    need(n>=2u&&n<=3u&&records!=0u,"B1363 nonempty borrowed record matrix");
    for(U k=0;k<n*n;++k){const U r=records+80u*k;
        need(m.r16(r)==0u&&m.r16(r+2u)==0u,"B1363 constructor-default packed coordinate");
        for(U o=8u;o<=0x3cu;o+=4u)need(m.r32(r+o)==0u,"B1363 constructor-default record fields");
        need(m.r32(r+0x40u)==0xffffffffu,"B1363 constructor-default record sentinel");
        for(U o=0x44u;o<=0x49u;++o)need(m.r8(r+o)==0u,"B1363 constructor-default record bytes");
        need(m.r8(r+0x4au)==eligibility&&m.r8(r+0x4bu)==0u,"B1363 declared record eligibility state");
    }
    return n*n;
}
U original_428ac0(Memory& m){return ((m.r32(0x81a914u)+4u)*m.r32(0x81a910u))<<1u;}
U original_428a90(Memory& m,U coordinate){
    const U x=floating_b61::sx16(m.r16(coordinate)),y=floating_b61::sx16(m.r16(coordinate+2u)),width=m.r32(0x81a910u);
    return (x-width+y-1u)*width+floating_b61::sar(x-y+width-1u,1u);
}
}
U fun_00557e50(Memory& m,const Inputs& i){
    map_prestate(m);const U count=matrix_prestate(m,0u);
    need(m.r32(m.r32(map+0x138u)+8196u)==0u,"B1363 genuine null first Map slot");
    need(m.r32(0x81b9c0u)==0u&&m.r32(0x81b9c4u)==0u,"B1363 coherent empty auxiliary context");
    for(U k=0;k<count;++k)m.w8(original_56a9b0(m,k)+0x4au,1u);
    (void)original_498cf0_null(m);
    // Root has two identical inline initializers, followed by actual iterator calls.
    (void)original_557340(m);U eax=original_557280_nonzero_remaining(m);
    const U caller_arg1=i.arg[1];(void)caller_arg1;
    need(eax==0u,"B1363 first null-slot traversal");
    (void)original_557340(m);eax=original_557280_nonzero_remaining(m);
    need(eax==0u,"B1363 second null-slot traversal");
    m.w32(0x81b9c4u,0u);
    // Actual local allocation flag is explicitly0; BL stays1. No allocation/free.
    eax=(eax&0xffffff00u)|0u;
    return (eax&0xffffff00u)|1u;
}
U fun_0056d600(Memory& m,const Inputs&){
    map_prestate(m);const U count=matrix_prestate(m,1u),records=m.r32(0xa5863cu);
    need(m.r32(m.r32(map+0x138u)+8196u)==0u,"B1363 genuine null first Map slot");
    need(m.r32(0xa57950u)==0u&&m.r32(0xa58640u)==0u,"B1363 empty registry and coherent zero auxiliary state");
    (void)original_498cf0_null(m);(void)original_557340(m);
    U eax=original_557280_nonzero_remaining(m);need(eax==0u,"B1363 no Map cell adjustment");
    for(U k=0;k<count;++k){m.w32(records+80u*k+0x38u,0xffffffffu);m.w32(records+80u*k+0x3cu,0xffffffffu);}
    m.w32(0xa58640u,0u);
    for(U k=0;k<count;++k){
        const U record=records+80u*k;
        // Actual root produces both WORDs in its private stack local before calling58A950.
        const std::array<std::uint16_t,2> local{{0u,0u}};
        eax=original_58a950(m,record,local);need(eax==0u,"B1363 actual equal packed-coordinate branch");
    }
    // Registry count remains0; all three subsequent registry phases naturally have no entries.
    eax=(eax&0xffffff00u)|1u;return (eax&0xffffff00u)|1u;
}
U fun_00705e40(Memory& m,const Inputs& i){
    map_prestate(m);need((i.cx&255u)==0u,"B1363 borrowed-buffer entry CL0");
    const U count=original_428ac0(m),buffer=m.r32(0xab8220u),table=m.r32(map+0x138u);
    need(count==64u&&buffer!=0u&&m.r32(0xab81d8u)==0u,"B1363 existing64-byte buffer and empty object registry");
    const U cell=m.r32(table+8196u);
    need(cell!=0u&&m.r32(table+6152u)==0u,"B1363 real first cell and genuine null next slot");
    need(m.r16(cell+0x24u)==1u&&m.r16(cell+0x26u)==4u&&m.r32(cell+0x44u)==0x7eu,"B1363 cell matches table coordinate and marker");
    (void)original_557340(m);U eax=original_557280_nonzero_remaining(m);
    m.w32(eax+0x140u,m.r32(eax+0x140u)&0xffff7fffu);
    eax=original_557280_nonzero_remaining(m);need(eax==0u,"B1363 first normal iterator termination");
    // Actual REP STOSD count16, remainder STOSB count0, DF clear.
    for(U o=0;o<count;o+=4u)m.w32(buffer+o,0u);
    (void)original_557340(m);eax=original_557280_nonzero_remaining(m);
    const U index=original_428a90(m,eax+0x24u);need(index<count,"B1363 actual map index within existing buffer");
    if(m.r8(buffer+index)==0u)m.w32(eax+0x44u,0xffffffffu);
    m.w32(eax+0x140u,m.r32(eax+0x140u)&0xffff7fffu);
    eax=original_557280_nonzero_remaining(m);need(eax==0u,"B1363 second normal iterator termination");
    return eax;
}
}
