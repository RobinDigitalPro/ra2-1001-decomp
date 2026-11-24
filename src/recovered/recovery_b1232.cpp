#include "recovered/recovery_b1232.hpp"
#include <stdexcept>
namespace ra2::recovered::b1232 {namespace{
void need(bool x){if(!x)throw std::domain_error("1232 finite fresh Building initialization");}
}
unsigned run(Memory&m,Inputs&i,Heap&h,unsigned root,unsigned base,platform::x87::State&fp,Observation&o){
 const unsigned self=base+0x1000u,house=base+0x4000u,type=base+0xb000u,country=base+0xc800u;
 need(root==0x3f5d0u&&i.cx==self&&m.r32(self)==0x787bbcu&&m.r32(self+0x418u)==type&&m.r32(self+0x1b4u)==house&&m.r32(type)==0x7881f8u&&m.r32(house+0x34u)==country);
 need(m.r32(type+0x540u)==0u&&m.r32(type+0xb08u)==0u&&m.r8(type+0xaf7u)==0u&&m.r8(self+0x5c6u)==0u&&m.r32(type+0x74cu)==0u&&m.r32(self+0x118u)==0u&&m.r32(self+0x11cu)==0u);
 m.w8(self+0x372u,house==m.r32(0xa1e0e4u)?1u:0u);
 // Genuine Building+39C44D670 ->6CDAB0 ->707FE0 reaches two zero-vs-two comparisons.
 // Kind6 excludes the middle weapon block of Aircraft1048. Guest numeric state is explicit.
 const auto two=std::uint64_t(m.r32(0x7856f8u))|(std::uint64_t(m.r32(0x7856fcu))<<32u);
 for(unsigned k=0;k<2u;++k){fp.load64(0ull);fp.compare_pop64(two);++o.fp_comparisons;}
 for(unsigned k=0;k<4u;++k){m.w32(self+0x330u+4u*k,m.r32(type+0xab0u+4u*k));m.w32(self+0x350u+4u*k,m.r32(type+0xac4u+4u*k));}m.w32(self+0x3ecu,1u);m.w32(self+0x3f0u,0u);
 m.w32(self+0x434u,m.r32(country+0xb8u));m.w8(self+0x324u,1u);
 need(m.r32(type+0x3ccu)==0u&&m.r8(type+0x202u)==0u&&m.r32(type+0xb90u)==0u&&m.r32(house+0x5420u)==0x7895acu&&m.r32(house+0x5424u)==0u&&m.r32(house+0x5428u)==0u&&m.r8(house+0x542cu)==1u&&m.r8(house+0x542du)==0u);
 m.w32(house+0x230u,m.r32(house+0x230u)+1u);
 m.w8(house+0x542cu,0u);const unsigned back=h.allocate(40u);++o.allocations;m.w8(house+0x542cu,1u);need(back!=0u);m.w32(house+0x5424u,back);m.w32(house+0x5428u,10u);m.w8(house+0x542du,1u);for(unsigned k=0;k<10u;++k)h.w32(back+4u*k,0u);h.w32(back,1u);++o.counter_lookups;
 need(m.r32(house+0x2280u)==1u);m.w32(house+0x1a80u,m.r32(house+0x1a80u)+1u);need(m.r8(type+0xadau)==0u);
 const unsigned strength=m.r32(type+0xa0u);need(strength>=1u&&strength<=500u);m.w32(self+0x6cu,strength);m.w32(self+0x70u,strength);
 const unsigned primary=m.r32(type+0x5a8u);m.w32(self+0x254u,primary==0xffffffffu?m.r32(type+0x5acu):primary);
 need(primary==0xffffffffu&&m.r32(type+0x5acu)==0xffffffffu&&m.r32(type+0x638u)==0u);const auto rot=global_b26::s32(m.r32(type+0x638u));const unsigned bounded=rot<127?unsigned(rot):127u;m.w8(self+0x2f4u,0u);m.w8(self+0x2f5u,bounded);
 need(m.r32(type+0xb98u)==0u&&m.r8(type+0x13e1u)==0u);m.w8(self+0x5acu,0u);++o.stat_initializations;o.virtual_callbacks=28u;
 return 0u; // Actual final Type+C0 returns full0 from B98 before bypassing file/45E590 branch. RET0.
}
}
