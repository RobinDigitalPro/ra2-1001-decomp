#include "recovery_b1672.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1672 {
namespace {
using U=unsigned;
void require(bool b){if(!b)throw std::domain_error("B1672 outside finite normal queue maintenance contract");}
U select_480530(Memory&m,U table,U index){
    const U slot=m.r32(m.r32(table+0x40)+4*index);
    const U record=m.r32(table+0x34)+20*slot;
    return (m.r32(record)&1)?record:0;
}
// Exact4803E0 path with all four output pointers NULL, index in range.
// The two original output-copy branches are absent under that input condition.
U remove_4803e0(Memory&m,U table,U index){
    const U count=m.r32(table+0x38);if(!count)return 0;
    require(index<count);
    const U record=select_480530(m,table,index);if(!record)return 0;
    m.w32(record,m.r32(record)&~1u);
    m.w32(record,m.r32(record)&~2u);
    m.w32(record,m.r32(record)&~4u);
    m.w32(record+4,0);m.w32(record+12,0);
    const U indices=m.r32(table+0x40);
    for(U k=index+1;k<count;++k)m.w32(indices+4*(k-1),m.r32(indices+4*k));
    m.w32(indices+4*(count-1),0);m.w32(table+0x38,count-1);return 1;
}
U normal_table(Memory&m,U provider){
    require(provider&&m.r32(provider)==0x78f684);
    const U t=m.r32(provider+4);require(m.r32(t)==0x788db4);return t;
}
// 4815C0 invokes4815F0(+1C) then523990(+20), in that order.
U maintain_4815c0(Memory&m,U provider){
    const U table=normal_table(m,provider);
    // Empty outgoing queue: both4815F0 loops skip, returning full1.
    require(m.r32(table+0x28)==0);
    U index=0;
    while(global_b26::s32(index)<global_b26::s32(m.r32(table+0x38))){
        const U record=select_480530(m,table,index);require(record);
        if(m.r8(record)&2){(void)remove_4803e0(m,table,index);--index;}
        ++index;
    }
    return 1;
}
U poll_524890(Memory&m){
    constexpr U manager=0xa285c8;
    // 522950 produces a private10-byte FF descriptor; NULL821F90 branches
    // past every use of that temporary, without any unproduced-byte read.
    require(m.r32(0x821f90)==0);
    const U provider=m.r32(manager+0x48);
    if(provider){require(maintain_4815c0(m,provider)==1);}
    // These actual guards skip siblings/array/debug branches.
    require(m.r8(0xa27ed4)==0&&m.r32(manager+0x44)==0);
    m.w32(manager+0x9c,0xffffffffu);return 1;
}
}
unsigned fun_00524890(Memory&m,const Inputs&i){
    // Input provenance is established by genuine normal construction, insertion
    // and receive outside this observed Root. These guards limit the domain.
    constexpr U manager=0xa285c8;
    require(i.cx==manager&&m.r32(0xa255c8)==4);
    const U table=normal_table(m,m.r32(manager+0x48));
    require(m.r32(table+4)==1&&m.r32(table+8)==2&&m.r32(table+12)==71&&m.r32(table+16)==10);
    require(m.r32(table+0x28)==0&&m.r32(table+0x38)==1);
    const U record=select_480530(m,table,0);
    require(record&&(m.r8(record)&3)==3);
    return poll_524890(m);
}
}
