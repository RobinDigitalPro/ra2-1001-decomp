#include "recovered/recovery_b1140.hpp"
#include <stdexcept>
namespace ra2::recovered::b1140 {
static void need(bool x){if(!x)throw std::domain_error("1140 cold original8x8 R250 cache");}
static unsigned draw(Memory&m){constexpr unsigned r=0x821558u;need(m.r8(r)==0u);const auto i=m.r32(r+4u),j=m.r32(r+8u);need(i<250u&&j<250u);const auto v=m.r32(r+12u+4u*i)^m.r32(r+12u+4u*j);m.w32(r+12u+4u*i,v);m.w32(r+4u,i==249u?0u:i+1u);m.w32(r+8u,j==249u?0u:j+1u);return v;}
unsigned run(unsigned root,Memory&m,const Inputs&i,State&f){(void)f;need(root==0x763a0u&&m.r8(0x838f87u)==0u&&m.r8(i.cx+0x11au)==0u);m.w8(0x838f87u,1u);for(unsigned k=0;k<64u;++k)m.w32(0x838df0u+4u*k,0xffffffffu);
 for(unsigned k=0;k<64u;++k){unsigned tries=0u,value;for(;;){value=draw(m)&7u;bool conflict=false;for(unsigned d=0;d<8u;++d){int q=int(k)+int(m.r32(0x7bdb68u+8u*d))+8*int(m.r32(0x7bdb6cu+8u*d));if(q<0)q+=64;if(q>=64)q-=64;need(q>=0&&q<64);if(m.r32(0x838df0u+4u*unsigned(q))==value){conflict=true;break;}}if(!conflict||++tries>=64u)break;}m.w32(0x838df0u+4u*k,value);}
 const auto p=m.r32(i.cx+0x24u),x=p&65535u,y=p>>16u;if(std::int32_t(i.arg[1])<=4)return m.r32(0x7bdb28u+4u*((x&3u)|((y&3u)<<2u)));return m.r32(0x838df0u+4u*((x&7u)+8u*(y&7u)));
}
}
