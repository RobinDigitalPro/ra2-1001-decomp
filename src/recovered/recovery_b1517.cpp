#include "recovered/recovery_b1517.hpp"
#include <stdexcept>
namespace ra2::recovered::b1517 {
using U=std::uint32_t;
std::uint32_t fun_00496dc0(Memory& m,const Inputs& i) {
 const U receiver=i.cx,flags=i.arg[0],output=i.arg[1];
 if(m.r32(receiver)!=0x00789794u)throw std::domain_error("B1517 requires constructor-pinned vptr 0x789794");
 if(m.r32(receiver+0x28u)!=0u)throw std::domain_error("B1517 excludes nonzero receiver+0x28 owner path");
 if(m.r8(receiver+0x1du)>1u)throw std::domain_error("B1517 requires receiver+0x1d in {0,1}");
 if(flags!=4u&&flags!=0x44u)throw std::domain_error("B1517 supports only flags 4 or 0x44");
 if(!output)throw std::domain_error("B1517 requires mapped nonnull output DWORD");
 if(!m.r32(output))throw std::domain_error("B1517 requires initially nonzero output DWORD");
 const auto overlaps=[](U a,U an,U b,U bn){return std::uint64_t(a)<std::uint64_t(b)+bn&&std::uint64_t(b)<std::uint64_t(a)+an;};
 if(overlaps(output,4u,receiver,0x1d4u)||overlaps(output,4u,0x0084e320u,4u)||overlaps(output,4u,0x0083a7a8u,4u))throw std::domain_error("B1517 requires output disjoint from receiver and globals");
 if(m.r32(0x0084e320u)!=receiver)throw std::domain_error("B1517 requires active receiver at 0x84e320");
 if(!m.r32(0x0083a7a8u))throw std::domain_error("B1517 requires initially nonzero 0x83a7a8");
 // Actual +0x78 clears 84E320 for flags 4/44. The bounded root clears
 // output and 83A7A8, then actual 83290(flags=0)->CEE00 returns full EAX0.
 m.w32(0x0084e320u,0u);m.w32(output,0u);m.w32(0x0083a7a8u,0u);return 0u;
}
}
