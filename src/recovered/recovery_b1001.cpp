#include "recovered/recovery_b1001.hpp"
#include <stdexcept>
namespace ra2::recovered::b1001 {
std::uint32_t fun_00781d5f(Memory&m,const Inputs&){
 const auto pending=m.r32(0x818dd8u);
 if(pending>255u)throw std::domain_error("1001 pending original byte required");
 m.w32(0x818dd8u,0xffffffffu);
 return pending;
}
}
