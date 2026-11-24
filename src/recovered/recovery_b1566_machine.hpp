#pragma once
#include "recovered/recovery_b1566.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1566 {
inline std::uint32_t query_capacity(Memory&m,std::uint32_t s){if(m.r32(s)!=0x78612cu||m.r32(0x786158u)!=0x41b580u||m.r32(0x7861acu)!=0x6b6910u||m.r32(0x7861b0u)!=0x41b600u||m.r32(0x7863ccu)!=0x6c93c0u)throw std::domain_error("1566 authentic Air vptr/slots");const auto t=m.r32(s+0x5acu);if(!t)throw std::domain_error("1566 nonnull Type");const auto c=m.r32(t+0x598u);if(!c||c>0x7fffffffu)throw std::domain_error("1566 finite positive capacity");return c;}
}
