#pragma once
#include "platform/small_crt_heap_algorithm.hpp"
#include <algorithm>
#include <stdexcept>
#include <vector>

namespace ra2::platform::small_crt_heap::ini234 {
inline bool valid_recipe(const std::vector<unsigned>& r) {
    constexpr unsigned keys[]{9,10,10,8,10,10,20,13,11,13,7,7,7,7,7,7,7};
    if(r.size()!=51)return false;
    for(unsigned k=0;k<17;++k) {
        const unsigned lo=k<5?2:k<10?3:6, hi=k<5?4:k<10?4:9;
        if(r[3*k]!=40||r[3*k+1]<lo||r[3*k+1]>hi||r[3*k+2]!=keys[k])return false;
    }
    return true;
}
inline unsigned offset(const std::vector<unsigned>& r,unsigned ordinal) {
    unsigned off=0x1000;for(unsigned k=0;k<=ordinal;++k)off-=(r[k]+23)&~15u;return off;
}
inline std::vector<unsigned> pointer_offsets(const std::vector<unsigned>& r) {
    if(!valid_recipe(r))throw std::domain_error("234 exact17-key insert recipe required");
    std::vector<unsigned> out;
    for(unsigned k=0;k<17;++k) {
        const auto node=offset(r,3*k);
        if(k)out.push_back(node+4);
        if(k<16)out.push_back(node+8);
        out.push_back(node+12);out.push_back(node+16);
    }
    std::sort(out.begin(),out.end());return out;
}
inline std::uint32_t allocate_existing_first_chunk(X86Memory& m,unsigned request,
    unsigned entry_esp,unsigned ordinal,const std::vector<unsigned>& recipe) {
    const auto need=[](bool ok,const char*why){if(!ok)throw std::domain_error(why);};
    need(valid_recipe(recipe)&&ordinal>=1&&ordinal<51&&request==recipe[ordinal],
         "234 bounded original request order");
    const auto record=m.r32(0xb10e18),metadata=m.r32(record+16),arena=m.r32(record+12);
    need(m.r32(0xb10e14)==1&&m.r32(0xb10e0c)==record&&m.r32(record)==0&&m.r32(record+4)==1,
         "234 sole first region/class63 state");
    need(m.r32(metadata)==0&&m.r32(metadata+0x44)==0&&m.r32(metadata+0xc4)==1&&m.r32(metadata+0x144)==ordinal,
         "234 exact allocation count and empty lower classes");
    unsigned consumed=0;for(unsigned k=0;k<ordinal;++k)consumed+=(recipe[k]+23)&~15u;
    const auto node=m.r32(metadata+0x340),previous=0xff0-consumed,span=(request+23)&~15u;
    need(node==arena+12&&m.r32(node)==previous&&previous>=span+0x400,
         "234 exact first-page residual remains class63");
    const auto residual=previous-span,allocated=node+residual;
    m.w32(entry_esp+4,record);m.w32(0xb10e0c,record);
    m.w32(node,residual);m.w32(node+residual-4,residual);
    m.w32(allocated,span+1);m.w32(allocated+span-4,span+1);
    m.w32(metadata+0x144,ordinal+1);m.w32(metadata,0);
    return allocated+4;
}
}
