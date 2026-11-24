#include "recovered/recovery_b1117.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include <stdexcept>
namespace ra2::recovered::b1117{
namespace fp=ra2::platform::x87;
static void need(bool b){if(!b)throw std::domain_error("1117 genuine positive slider page/drag domain");}
static unsigned integer(Memory&m,fp::State&f){f.load_control(m.r16(0x7c3a04u));return unsigned(f.pop_integer64());}
static void multiply_integer(fp::State&f,unsigned v){f.require_masked();fp::Image host;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfimull %[v]\n\tfnsave %[guest]\n\tfrstor %[host]" :[host]"=m"(host.bytes),[guest]"+m"(f.image.bytes):[v]"m"(v):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
static unsigned value(Memory&m,unsigned s,unsigned n,fp::State&f){const auto maximum=m.r32(s+0x30u)-m.r32(s+0x48u);if(std::int32_t(n)>=std::int32_t(maximum))n=maximum;if(std::int32_t(n)<0)n=0u;if(n==m.r32(s+0x34u))return 0u;m.w32(s+0x34u,n);m.w8(s+0x1cu,1u);const auto dimension=m.r32(s+(m.r8(s+0x2eu)?0x14u:0x18u));f.load_integer32(m.r32(s+0x30u));f.load_integer32(dimension);f.load_integer32(m.r32(s+0x48u));numeric_b88::detail::reg<0xd8f2>(f);numeric_b88::detail::reg<0xd8c9>(f);auto thumb=integer(m,f);if(std::int32_t(thumb)<=4)thumb=4;m.w32(s+0x4cu,thumb);f.load_integer32(n);numeric_b88::detail::reg<0xd8f2>(f);numeric_b88::detail::reg<0xd8c9>(f);auto offset=integer(m,f);if(std::int32_t(offset)>=std::int32_t(dimension-thumb))offset=dimension-thumb;m.w32(s+0x50u,offset);f.pop_st0();f.pop_st0();return 1u;}
static void sticky(Memory&m,unsigned s,unsigned flags){if(m.r8(s+0x1du)&&(flags&0x11u))m.w32(0x84e320u,s);if(m.r32(0x84e320u)==s&&(flags&0x44u))m.w32(0x84e320u,0u);}
unsigned run(Memory&m,const Inputs&i,unsigned root){const auto s=i.cx;need((root==0x27a240u||root==0xcffc0u)&&m.r32(s)==0x790734u&&m.r8(s+0x2du)==1u&&m.r32(s+0x30u)==32u&&m.r32(s+0x48u)==4u&&m.r32(s+0x34u)==8u&&m.r32(s+0x28u)==0u);const auto horizontal=m.r8(s+0x2eu)!=0u;const auto mouse=m.r32(0x821fa8u);need(m.r32(mouse)==0x79aa04u);const auto coordinate=m.r32(mouse+(horizontal?0x1cu:0x20u)),origin=m.r32(s+(horizontal?0xcu:0x10u)),dimension=m.r32(s+(horizontal?0x14u:0x18u));need(dimension==130u);auto f=i.fp;
 if(root==0x27a240u){need(i.arg[0]==1u);const auto first=origin+1u+m.r32(s+0x50u),last=first+m.r32(s+0x4cu);need(coordinate<first||coordinate>last);value(m,s,coordinate<first?m.r32(s+0x34u)-m.r32(s+0x48u):m.r32(s+0x34u)+m.r32(s+0x48u),f);sticky(m,s,0u);m.w32(i.arg[1],0u);}
 else{need(i.arg[0]==2u&&m.r32(0x84e320u)==s&&m.r32(s+0x38u)==4u);sticky(m,s,2u);auto relative=coordinate-m.r32(s+0x38u)-origin-1u;if(std::int32_t(relative)<0)relative=0u;if(relative>dimension-2u)relative=dimension-2u;f.load_integer32(relative);f.divide_integer32(dimension-2u);multiply_integer(f,m.r32(s+0x30u));const auto n=integer(m,f);need(value(m,s,n,f)==1u);need(m.r32(s+0x24u)!=0u);m.w32(i.arg[1],m.r32(s+0x24u)|0x8000u);m.w8(s+0x1cu,1u);sticky(m,s,2u);}
 i.fp=f;return 1u;
}
}
