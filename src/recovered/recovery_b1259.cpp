#include "recovered/recovery_b1259.hpp"
#include <stdexcept>
namespace ra2::recovered::b1259{namespace{
void need(bool b){if(!b)throw std::domain_error("1259 positive true BufferStraw terrainrestore");}
unsigned get(Memory&m,unsigned s,unsigned dst,unsigned n){const auto p=m.r32(s+24u),length=m.r32(s+16u);need(m.r32(s)==0x7899e8u&&m.r32(s+12u)&&p<=length&&n<=length-p);for(unsigned j=0;j<n;++j)m.w8(dst+j,m.r8(m.r32(s+12u)+p+j));m.w32(s+24u,p+n);return n;}
unsigned coordinate(Memory&m,unsigned s){const auto p=m.r32(s+24u);need(p+4u<=m.r32(s+16u));const auto v=m.r32(m.r32(s+12u)+p);m.w32(s+24u,p+4u);return v;}
void reset(Memory&m){const unsigned c=0xa57610u;
 // Exact40FF10 followed by470B10; all stores retained, including preserved flag bits.
 m.w32(c+8u,0x785e44u);m.w32(c+12u,0x785e3cu);m.w32(c+24u,0u);m.w32(c+28u,0u);m.w8(c+32u,0u);const auto flags=m.r8(c+20u)&0xf8u;m.w32(c+16u,0xffffffffu);m.w32(c,0x785dd8u);m.w32(c+4u,0x785dbcu);m.w32(c+8u,0x785db4u);m.w32(c+12u,0x785dacu);m.w8(c+20u,flags);
 m.w32(c+0x24u,m.r32(0x838f18u));for(unsigned o:{0x28u,0x2cu,0x30u,0x34u,0x3cu,0x40u,0x4cu})m.w32(c+o,0u);m.w32(c+0x38u,0xffffu);for(unsigned o:{0x44u,0x48u,0x50u,0x54u,0x58u,0x5cu,0x60u,0x64u})m.w32(c+o,0xffffffffu);for(unsigned o=0x68u;o<=0x78u;o+=4u)m.w32(c+o,0u);m.w16(c+0x116u,0xffffu);m.w32(c+0x12cu,m.r32(c+0x12cu)&0xffffffe0u);m.w16(c+0x108u,0u);for(unsigned o=0xdcu;o<=0x100u;o+=4u)m.w32(c+o,0u);for(unsigned o=0x10au;o<=0x114u;o+=2u)m.w16(c+o,1000u);m.w32(c+0x104u,0x10000u);m.w8(c+0x118u,0xffu);for(unsigned o=0x119u;o<=0x11fu;++o)m.w8(c+o,0u);m.w8(c+0x120u,0xfeu);m.w8(c+0x121u,0xfeu);m.w8(c+0x122u,0u);m.w32(c+0x130u,1u);m.w32(c+0x134u,0u);m.w8(c+0x138u,0u);m.w32(c+0x13cu,0u);m.w32(c+0x140u,m.r32(c+0x140u)&0xff800000u);m.w32(c,0x788b04u);m.w32(c+4u,0x788ae8u);m.w32(c+8u,0x788ae0u);m.w32(c+12u,0x788ad8u);for(unsigned o=0x7cu;o<0xdcu;++o)m.w8(c+o,0u);
 const auto scenario=m.r32(0xa255c0u);need(scenario);const auto id=m.r32(scenario+0x214u)+1u;m.w32(scenario+0x214u,id);m.w32(c+0x10u,id);m.w8(c+0x124u,0u);m.w8(c+0x128u,0u);
}}
unsigned run(unsigned root,Memory&m,const Inputs&i){need(root==0x14b450u&&m.r32(0xa56e5cu)==0u&&m.r32(0xa3ab10u)==0u);const auto s=i.arg[0];unsigned n=0u;for(;;){const auto xy=coordinate(m,s);i.arg[0]=xy;if(xy==0u)break;need(xy==0x140014u&&++n<=4u);const auto c=m.r32(m.r32(i.cx+0x138u)+10260u*4u);need(c&&c!=0xa57610u);m.w32(c+0x38u,0xffffu);get(m,s,c+0x38u,4u);/* True5277B0 count0 preserves loaded type literally. */get(m,s,c+0x11au,1u);get(m,s,c+0x11bu,1u);i.arg[0]=0u;}need(n>0u);reset(m);return 0xa57601u;}
}
