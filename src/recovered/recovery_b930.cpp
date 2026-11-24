#include "recovered/recovery_b930.hpp"
#include "recovered/recovery_b928.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b930{
namespace{
void multiply_log2(ra2::platform::x87::State&fp){fp.require_masked();ra2::platform::x87::Image host;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfyl2x\n\tfnsave %[guest]\n\tfrstor %[host]" : [host]"=m"(host.bytes),[guest]"+m"(fp.image.bytes) : : "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
}
std::uint32_t fun_0076DB12(Memory&m,const Inputs&i){using U=std::uint32_t;const auto b=std::uint64_t(i.arg[0])|(std::uint64_t(i.arg[1])<<32);if(i.fp.image.word(0)!=0x027f||m.r32(0xb1042c)||i.ax!=i.arg[3]||i.arg[0]||(i.arg[1]&0x800fffffu)||i.arg[1]<0x3ef00000u||i.arg[1]>0x40e00000u)throw std::domain_error("930 finite pow2 entry");
i.fp.load64(b);multiply_log2(i.fp);i.fp.load_st0();i.fp.round_integer();i.fp.reverse_subtract_st1_st0();i.fp.exchange_st1();i.fp.change_sign();i.fp.two_to_x_minus_one();i.fp.load_one();i.fp.add_pop();i.fp.scale();i.fp.pop_st1();Inputs nested=i;nested.arg[0]=0x027f;const U eax=recovery_b928::fun_00773039(m,nested);i.fp=nested.fp;return eax;
}}
