#include "recovered/recovery_b1566_machine.hpp"
namespace ra2::recovered::recovery_b1566 {std::uint32_t run(Memory&m,const Inputs&i){if(!i.arg[0]||i.arg[0]!=m.r32(i.cx+0x228u))throw std::domain_error("1566 equal nonnull target");return std::uint32_t(0u-query_capacity(m,i.cx));}}
