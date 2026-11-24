#pragma once
#include "platform/small_crt_heap_algorithm.hpp"
#include <cstdint>
#include <stdexcept>
#include <vector>

// Exact B442 seven-allocation protocol; value string is nine bytes.
namespace ra2::platform::small_crt_heap::insertion442 {
inline const std::vector<unsigned>& requests(){
 static const std::vector<unsigned> r{68,3,80,40,10,3,80}; return r;
}
inline const std::vector<unsigned>& pointer_offsets(){
 // Internal live pointers inside the eight real allocation payloads.
 static const std::vector<unsigned> p{0xe84,0xf14,0xf18,0xf1c,0xf20,0xf44,0xfbc,0xfc8,0xfd8,0xfdc}; return p;
}
[[noreturn]] inline void fail(const char* why){throw std::domain_error(why);}
inline void need(bool ok,const char* why){if(!ok)fail(why);}
inline std::uint32_t allocate_existing_first_chunk(X86Memory& m,unsigned request,
        std::uint32_t entry_esp,unsigned ordinal,const std::vector<unsigned>& recipe){
 const auto& exact=requests();
 need(recipe==exact&&ordinal>=1u&&ordinal<exact.size(),"305 exact request recipe/ordinal required");
 need(request==exact[ordinal],"305 exact allocator request order required");
 const auto record=m.r32(0xb10e18u);
 need(m.r32(0xb10e14u)==1u&&m.r32(0xb10e0cu)==record,"305 one initialized region/current cursor required");
 need(m.r32(record)==0u&&m.r32(record+4u)==1u,"305 region must contain only class-63 free extents");
 const auto metadata=m.r32(record+0x10u),arena=m.r32(record+0x0cu);
 need(m.r32(metadata)==0u&&m.r32(metadata+0x44u)==0u&&m.r32(metadata+0xc4u)==1u,
      "305 first committed chunk zero with no lower-class extents required");
 need(m.r32(metadata+0x144u)==ordinal,"305 exact prior live-allocation count required");
 const auto class63=metadata+0x33cu,node=m.r32(class63+4u);
 need(node==arena+0x0cu&&m.r32(class63+8u)==arena+0x700cu,"305 unchanged class-63 list endpoints required");
 std::uint32_t consumed=0;
 for(unsigned n=0;n<ordinal;++n)consumed+=(exact[n]+0x17u)&~0x0fu;
 const auto previous=0x0ff0u-consumed;
 need(m.r32(node)==previous,"305 exact previous page-zero residual required");
 const auto rounded=(request+0x17u)&~0x0fu,residual=previous-rounded;
 need(residual==0x0ff0u-consumed-rounded&&residual>=0x400u&&((residual>>4u)-1u)>=63u,
      "305 residual must remain the unchanged class-63 extent");
 // Same-class branch 0x773877 -> 0x77398a: no class list relink or count change.
 m.w32(entry_esp+4u,record);m.w32(0xb10e0cu,record);
 m.w32(node,residual);m.w32(node+residual-4u,residual);
 const auto allocated=node+residual;
 m.w32(allocated,rounded+1u);m.w32(allocated+rounded-4u,rounded+1u);
 m.w32(metadata+0x144u,ordinal+1u);m.w32(metadata,0u);
 return allocated+4u;
}
} // namespace ra2::platform::small_crt_heap::insertion442


