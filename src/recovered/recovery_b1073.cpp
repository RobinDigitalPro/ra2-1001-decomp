#include "recovered/recovery_b1073.hpp"
#include "recovered/recovery_b1065.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::b1073{
static void need(bool v){if(!v)throw std::domain_error("1073 outside positive final-light removal redraw");}
// Exact NULL-target extension of478CF0: recompute through immutable79040,
// retain a matching current color record or transfer to a real existing cache
// entry. Local initialized cells model output values, not original stack bytes.
static void recompute(Memory&m,const Inputs&i,unsigned cell){
 std::array<unsigned char,32>bytes{};leaf::Memory local(bytes.data(),0x20000u,unsigned(bytes.size()));auto memory=m;memory.add(local);Inputs call{};call.cx=cell;call.fp=i.fp;for(unsigned k=0;k<8u;++k)call.arg[k]=0x20000u+4u*k;b1067::fun_00479040(memory,call);i.fp=call.fp;
 std::array<unsigned,8>a{};for(unsigned k=0;k<8u;++k)a[k]=memory.r32(0x20000u+4u*k);auto current=m.r32(cell+0x34u);need(m.r32(0xa2876cu)==2u);
 if(current){bool equal=true;for(unsigned k=0;k<3u;++k)equal&=m.r32(current+0x198u+4u*k)==(std::min(1000u,a[k+5u])&~31u);if(!equal){if(m.r8(0xa285a8u))m.w32(current+0x194u,m.r32(current+0x194u)-1u);current=0u;m.w32(cell+0x34u,0u);}}
 if(!current){b1065::Inputs lookup{};lookup.cx=a[5];lookup.dx=a[6];lookup.arg[0]=a[7];current=b1065::fun_005277f0(m,lookup);need(current!=0u);m.w32(cell+0x34u,current);m.w32(current+0x194u,m.r32(current+0x194u)+1u);}
 m.w32(cell+0x104u,a[0]);for(unsigned k=0;k<4u;++k)m.w16(cell+0x108u+2u*k,a[k+1u]);for(unsigned k=0;k<3u;++k)m.w16(cell+0x110u+2u*k,a[k+5u]);
}
unsigned fun_005357b0(Memory&m,const Inputs&i){const auto p=i.cx;need((i.arg[0]&255u)==0u&&m.r8(0x7ca268u)==1u&&m.r32(p+0x34u)==2u&&m.r32(0xa2876cu)==2u&&m.r32(0xa56458u)==0u&&m.r8(p+0x48u)==0u);const auto radius=m.r32(p+0x44u);need(radius>=1u&&radius<=127u);const auto x=m.r32(p+0x38u),y=m.r32(p+0x3cu);need((x&255u)==128u&&(y&255u)==128u);const auto cx=x>>8u,cy=y>>8u;need(cx>=8u&&cx<=23u&&cy>=8u&&cy<=23u);const auto table=m.r32(0x81a958u);
 for(int dy=-1;dy<=1;++dy)for(int dx=-1;dx<=1;++dx){const auto px=cx+dx,py=cy+dy,cell=m.r32(table+4u*(512u*py+px));need(cell!=0u);const auto xx=unsigned(dx*256),yy=unsigned(dy*256),square=xx*xx+yy*yy;i.fp.load_integer32(square);const auto value=i.fp.pop64();numeric_b88::detail::root(m,i.fp,value);const auto distance=numeric_b88::detail::integer(m,i.fp);if(distance<=radius)recompute(m,i,cell);}
 const auto screen=m.r32(0x821cacu);if(screen)m.w8(screen+0xd7du,1u);if(m.r32(0x81a82cu)!=2u)m.w32(0x81a82cu,1u);m.w8(0x81b974u,m.r8(0x81b974u)+1u);return 1u;
}
}
