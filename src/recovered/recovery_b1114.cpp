#include "recovered/recovery_b1114.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include <stdexcept>
namespace ra2::recovered::b1114{
static void need(bool b){if(!b)throw std::domain_error("1114 original populated list scrollbar activation");}
static void geometry(Memory&m,unsigned s,ra2::platform::x87::State&f){
 const auto total=m.r32(s+0x30u),dimension=m.r32(s+0x18u);
 f.load_integer32(total);f.load_integer32(dimension);f.load_integer32(m.r32(s+0x48u));numeric_b88::detail::reg<0xd8f2>(f);numeric_b88::detail::reg<0xd8c9>(f);
 f.load_control(m.r16(0x7c3a04u));const auto inset=unsigned(f.pop_integer64());m.w32(s+0x4cu,inset>4u?inset:4u);
 f.load_integer32(m.r32(s+0x34u));numeric_b88::detail::reg<0xd8f2>(f);numeric_b88::detail::reg<0xd8c9>(f);const auto offset=unsigned(f.pop_integer64());const auto max=dimension-m.r32(s+0x4cu);m.w32(s+0x50u,offset<max?offset:max);f.pop_st0();f.pop_st0();
}
unsigned run(Memory&m,const Inputs&i){const auto p=i.cx,s=p+0x118u,n=m.r32(p+0x44u),v=m.r32(p+0x50u);need(m.r32(p)==0x790624u&&m.r8(p+0x54u)==0u&&n==v+1u&&n>=17u&&n<=129u&&m.r32(p+0x170u)==0u&&m.r32(s)==0x790734u&&m.r32(s+0x30u)==255u&&m.r32(s+0x48u)==1u&&m.r32(s+0x34u)==0u&&m.r8(s+0x2eu)==0u&&m.r32(s+0x18u)==n);
 m.w8(p+0x54u,1u);m.w8(p+0x1cu,1u);for(unsigned q:{p+0x58u,p+0xb8u,s}){need(m.r32(q)==(q==s?0x790734u:0x78b6a0u));m.w8(q+0x1cu,1u);}m.w32(p+0x14u,m.r32(p+0x14u)-m.r32(p+0x12cu));
 for(unsigned q:{p+0x58u,p+0xb8u,s})m.w32(q+0x28u,p);
 // Exact537280 insertion and537220 previous-chain traversal; pure original nodes.
 for(unsigned q:{p+0x58u,p+0xb8u,s}){const auto next=m.r32(p+4u);m.w32(p+4u,q);m.w32(q+8u,p);m.w32(q+4u,next);if(next)m.w32(next+8u,q);}
 auto f=i.fp;m.w32(s+0x30u,n);m.w8(s+0x1cu,1u);geometry(m,s,f);m.w32(s+0x48u,v);m.w8(s+0x1cu,1u);geometry(m,s,f);
 // Final67A140 clamps top0, then actual4CFD30 sees unchanged position0.
 need(m.r32(s+0x34u)==0u);i.fp=f;return 1u;
}
}
