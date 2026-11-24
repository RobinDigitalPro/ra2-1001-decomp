#pragma once
#include "platform/small_crt_heap781/small_crt_heap_algorithm.hpp"
#include <cstdint>
#include <stdexcept>
#include <vector>

// Private exact recipe for the two request-16 allocations reached by 0x1fa680.
namespace ra2::recovery_b546::constructor546 {
inline void require(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
inline const std::vector<unsigned>& requests(){static const std::vector<unsigned> v{16,16};return v;}
inline const std::vector<unsigned>& pointer_offsets(){static const std::vector<unsigned> v{0xfe8};return v;}
inline std::uint32_t allocate_second(ra2::platform::small_crt_heap781::X86Memory& m,
                                     std::uint32_t entry_esp,unsigned ordinal){
 using namespace ra2::platform::small_crt_heap781;
 require(ordinal==1u,"B546 supports only the second request-16 allocation");
 const auto record=m.r32(0x00b10e18u);
 require(m.r32(0x00b10e14u)==1u&&m.r32(0x00b10e0cu)==record,
         "B546 requires the initialized first CRT region/current cursor");
 require(m.r32(record)==0u&&m.r32(record+4u)==1u,
         "B546 region must contain only the class-63 residual extent");
 const auto metadata=m.r32(record+0x10u),arena=m.r32(record+0x0cu);
 require(m.r32(metadata)==0u&&m.r32(metadata+0x44u)==0u&&m.r32(metadata+0xc4u)==1u,
         "B546 requires only committed chunk zero and no lower free classes");
 require(m.r32(metadata+0x144u)==1u,"B546 requires exactly one preceding live block");
 const auto head=metadata+0x33cu,node=m.r32(head+4u);
 require(node==arena+0x0cu&&m.r32(head+8u)==arena+0x700cu,
         "B546 class-63 circular-list endpoints changed");
 require(m.r32(node)==0x0fd0u,"B546 second split requires the 0xfd0 residual");
 // Original same-class split at 0x77398a: 16 rounds to 0x20, leaving 0xfb0.
 const auto residual=0x0fb0u;
 require(((residual>>4u)-1u)>=63u,"B546 split must remain in class 63");
 m.w32(entry_esp+4u,record);m.w32(0x00b10e0cu,record);
 m.w32(node,residual);m.w32(node+residual-4u,residual);
 const auto allocated=node+residual;
 m.w32(allocated,0x21u);m.w32(allocated+0x1cu,0x21u);
 m.w32(metadata+0x144u,2u);m.w32(metadata,0u);
 return allocated+4u;
}
}
