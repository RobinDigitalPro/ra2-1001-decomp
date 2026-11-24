#include "recovered/recovery_b1157.hpp"
#include "platform/stream1157_provider.hpp"
#include <stdexcept>
namespace ra2::recovered::b1157 {
unsigned run(unsigned root,Memory&m,const Inputs&i,State&){if(root!=0x94870u)throw std::domain_error("1157 selectedroot");const auto self=i.arg[0];if(m.r32(self)!=0x7896ecu||m.r8(self+0xdu)!=0u||i.arg[1]==0u)throw std::domain_error("1157 cleanwrapper positiveoutput");auto raw=m.r32(self+4u);if(!raw)throw std::domain_error("1157 real ownedQI reference required");auto&provider=ra2::platform::stream1157::Stream::current();provider.add_ref(raw);m.w32(i.arg[1],m.r32(self+4u));raw=m.r32(self+4u);const auto result=provider.commit(raw,0u);if(std::int32_t(result)<0)return result;raw=m.r32(self+4u);provider.release(raw);m.w32(self+4u,0u);return 0u;}
}
