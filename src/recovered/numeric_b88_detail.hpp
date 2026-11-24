#pragma once
#include "numeric_b88.hpp"
#include "platform/x87_integer_subtract_b42.hpp"
// Local exact helper adaptations from accepted numeric_b80_extra.cpp.
namespace ra2::recovered::numeric_b88::detail {
using namespace floating_b61;
using global_b26::imul_high;
namespace fp=ra2::platform::x87;
namespace ext=ra2::platform::x87_extended;
namespace sub=ra2::platform::x87_integer_subtract;
// Each operation restores host state; temporaries are host locals. No invented
// guest stack or writes outside the original input/output fields are introduced.
template<unsigned Code> inline void reg(fp::State&f){
 f.require_masked();fp::Image host;
 asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t.byte %c[a],%c[b]\n\tfnsave %[guest]\n\tfrstor %[host]" :[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes):[a]"i"(Code>>8),[b]"i"(Code&255):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");
}
inline void reverse_divide64(fp::State&f,std::uint64_t v){f.require_masked();fp::Image host;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfdivrl %[v]\n\tfnsave %[guest]\n\tfrstor %[host]" :[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes):[v]"m"(v):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
inline std::uint32_t integer(Memory&m,fp::State&f){const auto c=m.r32(0x7c3a04u);if(f.control()!=c)f.load_control(std::uint16_t(c));return std::uint32_t(f.pop_integer64());}
// Original ba080 table approximation, including its two compares and single
// precision intermediate. This deliberately does not substitute std::sqrt.
inline void root(Memory&m,fp::State&f,std::uint64_t v){f.load64(v);f.compare32(m.r32(0x785738u));if(f.status()&0x4000u){f.pop_st0();f.load32(m.r32(0x785738u));return;}f.compare32(m.r32(0x785738u));if(f.status()&0x4100u)f.multiply64(read64(m,0x788578u));const auto bits=f.pop32();auto e=(bits>>23)-127u,man=bits&0x7fffffu;if(e&1u)man|=0x800000u;e=sx16(sar(sx16(e),1));f.load32(m.r32(0x80013cu+(man>>10)*4u)+((e+127u)<<23));}
inline std::uint32_t trig(Memory&m,fp::State&f,std::uint64_t v,bool cosine){f.load64(v);f.multiply32(m.r32(cosine?0x7c313cu:0x7c3138u));const auto integral=integer(m,f),odd=integral&1u;auto index=sar(integral-(s32(integral)<0?0xffffffffu:0u),1)&0x80001fffu;if(s32(index)<0){--index;index|=0xffffe000u;++index;if(s32(index)<0)index+=cosine?0x2800u:0x2000u;}else if(cosine)index+=0x800u;if(odd&&s32(index)<(cosine?0x27ff:0x1fff))++index;f.load32(m.r32(0x7ea104u+index*4u));return index;}
inline void acos_table(Memory&m,fp::State&f,std::uint64_t v){f.load64(v);f.add32(m.r32(0x7867f8u));f.multiply32(m.r32(0x78bf88u));const auto offset=integer(m,f)*4u;f.load32(m.r32(0x7f4114u-offset));f.reverse_subtract64(read64(m,0x786630u));}
// Exact ba270 numeric stack contract: two doubles rounded to float; ratio is
// converted through 76aa50, then its original table/quadrant adjustments.
inline void angle(Memory&m,fp::State&f,std::uint64_t a,std::uint64_t b){f.load64(b);const auto bf=f.pop32();f.load64(a);const auto af=f.pop32();f.load32(bf);f.compare_pop32(m.r32(0x785738u));f.load32(af);if(f.status()&0x4000u){f.compare_pop32(m.r32(0x785738u));if(f.status()&0x4000u){f.load32(m.r32(0x785738u));return;}f.load32(af);f.compare_pop32(m.r32(0x785738u));f.load32(m.r32((f.status()&0x4100u)?0x78bf90u:0x78bf8cu));return;}
 ext::divide32(f,bf);ext::divide32(f,m.r32(0x800138u));auto n=integer(m,f);if(s32(n)<0)n=0u-n;f.load32(m.r32(s32(n)>=4097?0x78bf8cu:0x7fc134u+n*4u));f.load32(bf);f.compare_pop32(m.r32(0x785738u));if(f.status()&0x100u)f.reverse_subtract64(read64(m,0x788158u));f.load32(af);f.compare_pop32(m.r32(0x785738u));if(f.status()&0x100u)f.change_sign();}
inline std::uint32_t half_toward_zero(std::uint32_t n){return sar(n-(s32(n)<0?0xffffffffu:0u),1);}
inline std::uint32_t div256(std::uint32_t n){return sar(n+(s32(n)<0?255u:0u),8);}
}
