#include "recovered/recovery_b1603.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1603{namespace{void need(bool v){if(!v)throw std::domain_error("B1603 finite borrowed Anim-kind shutdown");}}
U fun_005cbd90(Memory&m,const Inputs&i){const U self=i.cx,type=m.r32(self+0xb0);need(self&&m.r32(self)==0x787084);constexpr U slots[]={0x144,0xd8,0x11c,0x84,0x114,0x3c,0x2c},targets[]={0x5cb480,0x5cc2a0,0x421500,0x422ec0,0x5cb310,0x410240,0x423ec0};for(U k=0;k<7;++k)need(m.r32(0x787084+slots[k])==targets[k]);
need(m.r8(0xa285a8)!=0&&m.r8(self+0x76)==0&&m.r8(self+0x74)!=0&&m.r8(self+0x75)!=0&&m.r8(self+0x77)==0&&m.r32(self+0x80)==0xffffffff&&m.r32(self+0x94)==0&&m.r32(0x8192f8)==0&&m.r8(0x81b9b8)==0&&m.r32(0x81b9c4)==0&&m.r32(0xaa8710)==0&&m.r8(type+0x204)==0&&m.r32(type+0xac)==0);
struct Span{U a,n;};const std::array<Span,7>spans{{{self,0x1a8},{type,0x400},{0x787000,4096},{0x819000,4096},{0x81b000,4096},{0xa28000,4096},{0xaa8000,4096}}};for(U j=0;j<spans.size();++j){const auto&a=spans[j];need(a.a&&std::uint64_t(a.a)+a.n<=0x100000000ull);(void)m.r8(a.a);(void)m.r8(a.a+a.n-1);for(U k=0;k<j;++k)need(std::uint64_t(a.a)+a.n<=spans[k].a||std::uint64_t(spans[k].a)+spans[k].n<=a.a);}
// Actual144 is the77-zero guard. D8(1) has no child94, genuine3C
// returns0, repeats144, then actual6E1E50 kind4 uses an empty notification list.
if(m.r32(0x81b9c0)==self)m.w32(0x81b9c0,0);
// Actual11C(0)->21500->5CC7F0 and genuinekind4/DC20-default clear74.
m.w8(self+0x74,0);
// Actual99870 observes80=-1; both wrapper helpers observe disabled8192F8
// and still perform their unconditional wrapper+8 stores.
m.w32(self+0x44,0);m.w32(self+0x58,0);
// Authentic84 returnsType;204zero/ACzero exclude rendering.114 is RET.
m.w8(self+0x76,1);m.w8(self+0x75,0);return(type&0xffffff00u)|1u;
}}
