#include "recovered/recovery_b927.hpp"
#include "platform/x87_scalar_b46.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b927{
std::uint32_t fun_0044B570(Memory&m,const Inputs&i){using U=std::uint32_t;const U o=i.cx,t=m.r32(o+0x418),g=m.r32(0x821b88),v=m.r32(o);if(v!=0x787bbc||m.r32(v+0x84)!=0x4538b0||!t||!g||m.r32(o+0x460)||m.r8(t+0xf7c)||m.r8(t+0xf8c))throw std::domain_error("927 authentic bounded receiver");
const U numerator=m.r32(o+0x6c),denominator=m.r32(t+0xa0);if(!numerator||!denominator||numerator>0x7fffffff||denominator>0x7fffffff)throw std::domain_error("927 positive signed ratio");
m.w32(o+0x5c8,i.arg[0]);m.w32(o+0x5d8,m.r32(t+0x1370));for(U k=0;k<3;++k)m.w32(o+0x5cc+4*k,m.r32(i.arg[1]+4*k));
i.fp.load_integer32(numerator);const auto x=i.fp.pop64();i.fp.load_integer32(denominator);ra2::platform::x87_scalar_b46::reverse_divide64(i.fp,x);const auto threshold=std::uint64_t(m.r32(g+0x1368))|(std::uint64_t(m.r32(g+0x136c))<<32);i.fp.compare_pop64(threshold);return t+((i.fp.status()&0x4100)?0xf8c:0xf7c);
}}
