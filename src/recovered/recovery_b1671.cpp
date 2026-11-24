#include "recovery_b1671.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b1671 {
namespace {
using U=unsigned;
void require(bool b){if(!b)throw std::domain_error("B1671 outside finite queued case33 contract");}
void copy(Memory&m,U dst,U src,U n){for(U k=0;k<n;++k)m.w8(dst+k,m.r8(src+k));}
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
U receive_523870(Memory&m,U provider,U payload,U length,U descriptor,U word){
    const U table=normal_table(m,provider);
    if(!m.r32(table+0x38))return 0;
    const U record=select_480530(m,table,0);
    if(!record||(m.r8(record)&2))return 0;
    m.w32(record,m.r32(record)|2);
    const U total=m.r32(record+4),buffer=m.r32(record+8);
    require(total==71); // Selected positive61-byte payload, no capacity guess.
    copy(m,payload,buffer+10,total-10);
    m.w32(length,total-10);m.w16(word,m.r16(buffer+8));
    copy(m,descriptor,m.r32(record+16),10);return 1;
}
U receive_5245e0(Memory&m){
    constexpr U manager=0xa285c8;
    if(!m.r8(manager+4)||!m.r8(manager+5))return 0;
    return receive_523870(m,m.r32(manager+0x48),0xa27966,0xa27b30,0xa27b34,0xa27b3e);
}
void context_5b29f0(Memory&m){require(m.r32(0xb0de50)==0);}
void case33_42e940(Memory&m,U a,U b){
    constexpr U context=0x836c18;
    require(m.r32(context+0x60)!=0&&a==0xffffffffu&&b==0xffffffffu);
    // The finite contract reaches the first group/first slot immediately;
    // later search iterations and their other routes are outside this scope.
    const U selected=m.r32(context);
    require(selected&&(m.r8(selected+12)&2));
    const U owner=m.r32(0xa1e0e4),id=m.r32(selected+0x110);
    require(id!=m.r32(owner+0x30));
    m.w8(selected+12,m.r8(selected+12)&0xfcu);
}
}
unsigned fun_00482440(Memory&m,const Inputs&){
    constexpr U manager=0xa285c8;
    require(m.r32(0xa255c8)==4&&m.r8(manager+4)==1&&m.r8(manager+5)==1);
    const U table=normal_table(m,m.r32(manager+0x48));
    require(m.r32(table+4)==1&&m.r32(table+8)==2&&m.r32(table+12)==71&&m.r32(table+16)==10);
    require(m.r32(table+0x28)==0&&m.r32(table+0x38)==1);
    context_5b29f0(m);(void)poll_524890(m);
    require(m.r8(0xa2793c)==0);
    U result=receive_5245e0(m);require(result==1);
    U messages=0;
    do{
        require(m.r16(0xa27b3e)==0xaa03);
        // Byte-bound map[33-10]=7 and jump[7]=48256D select case33.
        require(m.r32(0xa27966)==33&&messages==0);
        case33_42e940(m,global_b26::sx8(m.r8(0xa279a2)),global_b26::sx8(m.r8(0xa279a1)));
        ++messages;
        context_5b29f0(m);(void)poll_524890(m);result=receive_5245e0(m);
    }while(result);
    return result;
}
}
