#include "recovered/recovery_b1580.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1580 {
namespace {using U=std::uint32_t;void need(bool ok){if(!ok)throw std::domain_error("B1580 finite genuineUnit publicflag statusquery");}
// Actual6CC370defines AL only. This typed projection exposes only that observed byte.
std::uint8_t public_flag(Memory&m,U self){return static_cast<std::uint8_t>(m.r8(self+0x205));}}
std::uint32_t run(Memory&m,const Inputs&i){need(m.r32(i.cx)==0x798c88u&&i.arg[0]!=0&&i.arg[1]==1&&i.arg[2]==1);const auto flag=public_flag(m,i.cx);if(flag!=0)return 3u; // OriginalMOV EAX,3definesall32bitsaftertheALtest.
throw std::domain_error("B1580 self205zero continuation unreviewed");}
}
