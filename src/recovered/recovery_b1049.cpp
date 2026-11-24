#include "recovery_b1049.hpp"
#include <stdexcept>
namespace ra2::recovered::b1049 {
std::uint32_t fun_0077cdd7(Memory&,const Inputs&i){
 const auto input=std::uint64_t(i.arg[0])|(std::uint64_t(i.arg[1])<<32u);
 const auto biased=unsigned((input>>52u)&2047u);
 if(!biased||biased==2047u||i.fp.image.word(8)!=0xffffu||(i.fp.image.word(4)&0x7fffu))throw std::domain_error("1049 finite normal input and empty clear x87");
 auto&fp=i.fp;const auto saved=fp.waiting_control();fp.load_control(0x133fu);
 fp.load64(input);fp.compare_pop64(0u);
 fp.load64(input);const auto argument=fp.pop64();
 // Genuine778EB7 normal path, including the reached778DD0 exponent replacement.
 fp.load64(argument);fp.compare_pop64(0u);
 fp.load64(argument);const auto temporary=fp.pop64();
 fp.load64(temporary);auto mantissa=fp.pop64();
 mantissa=(mantissa&0x800fffffffffffffull)|(std::uint64_t(0x3feu)<<52u);
 fp.load64(mantissa);const auto local=fp.pop64();fp.load64(local);
 fp.pop_st0();
 const auto exponent=biased-1023u;fp.load_integer32(exponent);
 const auto output=fp.pop64();i.arg[0]=unsigned(output);i.arg[1]=unsigned(output>>32u);
 const auto old=fp.waiting_control();fp.load_control(saved);fp.load64(output);
 return unsigned(std::int32_t(std::int16_t(old)));
}
}
