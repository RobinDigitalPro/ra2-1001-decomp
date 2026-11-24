#include "recovered/recovery_b757.hpp"
#include "platform/observed_frequency757.hpp"
#include "platform/x87_scalar_b46.hpp"
namespace ra2::recovered::recovery_b757 {
// Original RVA190330; finite successful-QPF route, exact helper1A8B00.
std::uint32_t fun_00590330(Memory&m,const Inputs&i){
 m.w32(i.cx,0);m.w32(i.cx+4,0x3ff00000u);
 LARGE_INTEGER value{};ra2::platform::frequency757::query(&value);
 const auto bits=std::uint64_t(value.QuadPart);
 auto fp=i.fp;
 ra2::platform::x87_scalar_b46::load_integer64(fp,std::uint32_t(bits>>32));
 const auto high=fp.pop64();fp.load64(high);
 fp.multiply64(std::uint64_t(m.r32(0x788e10))|(std::uint64_t(m.r32(0x788e14))<<32));
 ra2::platform::x87_scalar_b46::load_integer64(fp,std::uint32_t(bits));
 fp.add_pop();fp.multiply64(std::uint64_t(m.r32(0x787528))|(std::uint64_t(m.r32(0x78752c))<<32));
 const auto output=fp.pop64();m.w32(i.cx,std::uint32_t(output));m.w32(i.cx+4,std::uint32_t(output>>32));
 i.fp=fp;return i.cx;
}
}
