#include "recovered/recovery_b948.hpp"
namespace ra2::recovered::recovery_b948 {
std::uint32_t fun_006b16c0(Memory&m,const Inputs&i){if(m.r32(i.cx+0x54)||m.r8(i.cx+0x80))throw std::domain_error("948 empty chain pending completion");m.w8(i.cx+0x80,1);return i.ax;}
}
