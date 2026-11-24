#include "recovered/index_b74.hpp"

#include "recovered/text_b68.hpp"

#include <array>
#include <stdexcept>

namespace ra2::recovered::global_b26 {
namespace {
constexpr std::uint32_t arena=0x18000000u;
void unsupported(const char* s){throw std::domain_error(s);}
std::uint32_t set_al(std::uint32_t eax,std::uint8_t al){return (eax&0xffffff00u)|al;}

// Match the original positive-count signed midpoint search. The selected
// fixtures use distinct sorted keys, so duplicate tie choice is not claimed.
struct Search { bool hit; std::uint32_t index; std::uint32_t last_eax; };
Search search_signed(Memory& m,std::uint32_t data,std::uint32_t count,std::int32_t key,std::uint32_t initial){
    std::uint32_t base_index=0,remaining=count,eax=initial;
    while(s32(remaining)>0){
        // Mirrors MOV EAX,remaining / CDQ / SUB EAX,EDX / SAR EAX,1.
        eax=remaining/2u;
        const auto absolute=base_index+eax;
        const auto value=s32(m.r32(data+absolute*8u));
        if(key==value)return {true,absolute,eax};
        if(key<value)remaining=eax;
        else {base_index=absolute+1u;remaining=remaining-eax-1u;}
    }
    return {false,0,eax};
}
void move(Memory& m,std::uint32_t dst,std::uint32_t src,std::uint32_t n){
    Inputs in{};in.arg[0]=dst;in.arg[1]=src;in.arg[2]=n;(void)fun_0076ebd0(m,in);
}
void require_vector(std::uint32_t count,std::uint32_t capacity,std::uint32_t max,const char* why){
    if(count>max||capacity>max||count>=capacity)unsupported(why);
}
}

std::uint32_t fun_0051d8f0(Memory& m,const Inputs& i){
    const auto d=i.cx,table=m.r32(d),count=m.r32(d+4),capacity=m.r32(d+8);
    require_vector(count,capacity,128u,"Block74 0x11d8f0 requires spare preallocated capacity");
    const auto kptr=i.arg[0],vptr=i.arg[1];
    m.w32(table+count*8u,m.r32(kptr));
    m.w32(table+count*8u+4u,m.r32(vptr));
    const auto next=count+1u;
    m.w8(d+0x0c,0u);m.w32(d+4,next);
    return set_al(next,1u);
}

std::uint32_t fun_0051d9c0(Memory& m,const Inputs& i){
    const auto d=i.cx,table=m.r32(d),count=m.r32(d+4);
    const auto key=s32(m.r32(i.arg[0]));
    if(count==0u||count>128u)unsupported("Block74 0x11d9c0 count outside finite nonempty bound");
    if(count&&m.r8(d+0x0c)==0u)unsupported("Block74 0x11d9c0 unsorted qsort path excluded");
    const auto sr=search_signed(m,table,count,key,i.ax);
    if(!sr.hit)return set_al(sr.last_eax,0u);
    const auto after=sr.index+1u;
    if(after<count)move(m,table+sr.index*8u,table+after*8u,(count-after)*8u);
    const auto next=count-1u;
    m.w32(d+4,next);m.w32(table+next*8u,0u);m.w32(table+next*8u+4u,0u);m.w32(d+0x10,0u);
    return set_al(next,1u);
}

namespace {
std::uint32_t cached_lookup(Memory& m,const Inputs& i){
    const auto d=i.cx,count=m.r32(d+4),table=m.r32(d),query=m.r32(i.arg[0]);
    if(count>128u)unsupported("Block74 sorted lookup count exceeds finite bound");
    if(count==0u)return set_al(i.ax,0u);
    auto cache=m.r32(d+0x10);
    if(cache&&m.r32(cache)==query)return set_al(query,1u);
    if(m.r8(d+0x0c)==0u)unsupported("Block74 sorted lookup unsorted qsort path excluded");
    const auto r=search_signed(m,table,count,s32(query),i.ax);
    if(!r.hit)return set_al(r.last_eax,0u);
    cache=table+r.index*8u;m.w32(d+0x10,cache);
    return set_al(r.index,1u);
}
}
std::uint32_t fun_0051daa0(Memory& m,const Inputs& i){return cached_lookup(m,i);}
std::uint32_t fun_006fef10(Memory& m,const Inputs& i){return cached_lookup(m,i);}

std::uint32_t fun_00752340(Memory& m,const Inputs& i){
    const auto d=i.cx,count=m.r32(d),capacity=m.r32(d+4),data=m.r32(d+8),raw_index=i.arg[1];
    require_vector(count,capacity,512u,"Block74 0x352340 requires spare preallocated capacity");
    const auto index=raw_index>count?count:raw_index;
    const auto source=i.arg[0];
    if(index<count)move(m,data+(index+1u)*108u,data+index*108u,(count-index)*108u);
    for(std::uint32_t n=0;n<108u;++n)m.w8(data+index*108u+n,m.r8(source+n));
    const auto next=count+1u;m.w32(d,next);return set_al(next,1u);
}

std::uint32_t fun_00752660(Memory& m,const Inputs& i){
    const auto d=i.cx,count=m.r32(d),capacity=m.r32(d+4),data=m.r32(d+8),index=i.arg[0];
    if(count<2u||count>512u||capacity>512u||capacity<count||capacity>=3u*(count-1u)||index>=count)
        unsupported("Block74 0x352660 requires bounded spare-capacity removal route");
    const auto slot=data+index*4u;
    if(m.r32(slot)!=0u)unsupported("Block74 0x352660 owned-slot dependency is limited to null values");
    // Exact null branch of accepted 0x359320: clear the slot, with no release call.
    m.w32(slot,0u);
    const auto remaining=count-index-1u;
    if(remaining)move(m,slot,slot+4u,remaining*4u);
    const auto next=count-1u;m.w32(d,next);return set_al(next,1u);
}

std::uint32_t fun_00752d70(Memory& m,const Inputs& i){
    const auto d=i.cx,count=m.r32(d),capacity=m.r32(d+4),data=m.r32(d+8),raw_index=i.arg[1];
    require_vector(count,capacity,128u,"Block74 0x352d70 requires spare preallocated capacity");
    const auto index=raw_index>count?count:raw_index,source=i.arg[0];
    if(index<count)move(m,data+(index+1u)*268u,data+index*268u,(count-index)*268u);
    for(std::uint32_t n=0;n<268u;++n)m.w8(data+index*268u+n,m.r8(source+n));
    const auto next=count+1u;m.w32(d,next);return set_al(next,1u);
}

std::uint32_t fun_00753050(Memory& m,const Inputs& i){
    const auto d=i.cx,count=m.r32(d),capacity=m.r32(d+4),data=m.r32(d+8),raw_index=i.arg[1];
    require_vector(count,capacity,128u,"Block74 0x353050 requires spare preallocated capacity");
    const auto index=raw_index>count?count:raw_index,source=i.arg[0];
    if(index<count)move(m,data+(index+1u)*4u,data+index*4u,(count-index)*4u);
    m.w32(data+index*4u,m.r32(source));
    const auto next=count+1u;m.w32(d,next);return set_al(next,1u);
}

std::uint32_t fun_00753a60(Memory& m,const Inputs& i){
    const auto d=i.cx,count=m.r32(d),capacity=m.r32(d+4),data=m.r32(d+8),index=i.arg[1];
    if(count<1u||count>=capacity||capacity>512u||index>=count)
        unsupported("Block74 0x353a60 requires nonempty bounded spare-capacity vector");
    const auto source=i.arg[0];
    if(m.r32(source)!=0u)unsupported("Block74 0x353a60 0x3592c0 dependency limited to null source");
    if(index<count)move(m,data+(index+1u)*4u,data+index*4u,(count-index)*4u);
    // Exact null-source branch of 0x3592c0 zeroes the destination before its
    // source check and performs no allocation.
    m.w32(data+index*4u,0u);
    const auto next=count+1u;m.w32(d,next);return set_al(next,1u);
}

std::uint32_t fun_00754340(Memory& m,const Inputs& i){
    const auto d=i.cx,count=m.r32(d),capacity=m.r32(d+4),data=m.r32(d+8),index=i.arg[0];
    if(count<2u||count>512u||capacity>512u||capacity<count||capacity>=3u*(count-1u)||index>=count)
        unsupported("Block74 0x354340 requires bounded spare-capacity removal route");
    const auto remaining=count-index-1u;
    if(remaining)move(m,data+index*4u,data+(index+1u)*4u,remaining*4u);
    const auto next=count-1u;m.w32(d,next);return set_al(next,1u);
}

const std::array<Entry,10>& index_b74_entries(){
    static const std::array<Entry,10> e{{
        {0x11d8f0u,fun_0051d8f0},{0x11d9c0u,fun_0051d9c0},
        {0x11daa0u,fun_0051daa0},{0x2fef10u,fun_006fef10},
        {0x352340u,fun_00752340},{0x352660u,fun_00752660},
        {0x352d70u,fun_00752d70},{0x353050u,fun_00753050},
        {0x353a60u,fun_00753a60},{0x354340u,fun_00754340}
    }};
    return e;
}
}
