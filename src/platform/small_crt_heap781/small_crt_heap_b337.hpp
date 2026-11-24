#pragma once
#include "platform/small_crt_heap781/small_crt_heap_algorithm.hpp"
#include <algorithm>
#include <stdexcept>
#include <vector>

namespace ra2::platform::small_crt_heap781::b337 {
inline const std::vector<unsigned>& requests() {
    static const std::vector<unsigned> r{40,2,13,40,2,10,40,7,4};
    return r;
}
inline bool valid_recipe(const std::vector<unsigned>& r) { return r == requests(); }
inline unsigned span(unsigned request) { return (request + 23u) & ~15u; }
inline unsigned offset(unsigned ordinal) {
    const auto& r=requests();
    if(ordinal>=r.size())throw std::domain_error("337 exact nine-allocation recipe ordinal");
    unsigned at=0x1000u;
    for(unsigned n=0;n<=ordinal;++n)at-=span(r[n]);
    return at;
}
inline std::vector<unsigned> pointer_offsets() {
    std::vector<unsigned> out;
    for(unsigned k=0;k<3;++k) {
        const auto node=offset(3*k);
        if(k)out.push_back(node+4);
        if(k<2)out.push_back(node+8);
        out.push_back(node+12);out.push_back(node+16);
    }
    std::sort(out.begin(),out.end());
    return out;
}
inline std::uint32_t allocate_existing_first_chunk(X86Memory& m,unsigned request,
    unsigned entry_esp,unsigned ordinal,const std::vector<unsigned>& recipe) {
    const auto need=[](bool ok,const char*why){if(!ok)throw std::domain_error(why);};
    need(valid_recipe(recipe)&&ordinal>=1&&ordinal<recipe.size()&&request==recipe[ordinal],
         "337 exact nine-allocation request order");
    const auto record=m.r32(0xb10e18),metadata=m.r32(record+16),arena=m.r32(record+12);
    need(m.r32(0xb10e14)==1&&m.r32(0xb10e0c)==record&&m.r32(record)==0&&m.r32(record+4)==1,
         "337 sole first region/class63 state");
    need(m.r32(metadata)==0&&m.r32(metadata+0x44)==0&&m.r32(metadata+0xc4)==1&&m.r32(metadata+0x144)==ordinal,
         "337 exact allocation count and empty lower classes");
    unsigned consumed=0;for(unsigned k=0;k<ordinal;++k)consumed+=span(recipe[k]);
    const auto node=m.r32(metadata+0x340),previous=0xff0u-consumed,rounded=span(request);
    need(node==arena+12&&m.r32(node)==previous&&previous>=rounded+0x400,
         "337 exact first-page residual remains class63");
    const auto residual=previous-rounded,allocated=node+residual;
    m.w32(entry_esp+4,record);m.w32(0xb10e0c,record);
    m.w32(node,residual);m.w32(node+residual-4,residual);
    m.w32(allocated,rounded+1);m.w32(allocated+rounded-4,rounded+1);
    m.w32(metadata+0x144,ordinal+1);m.w32(metadata,0);
    return allocated+4;
}
}
