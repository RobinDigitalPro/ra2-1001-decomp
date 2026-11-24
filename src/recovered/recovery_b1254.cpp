#include "recovery_b1254.hpp"
#include <stdexcept>
namespace ra2::recovered::b1254 {namespace {
void need(bool x){if(!x)throw std::domain_error("1254 trueRadSite registryunpublication/RTTIabsence");}
bool same_name(Memory&m,unsigned a,unsigned b){for(unsigned k=0;k<128u;++k){const auto x=m.r8(a+k),y=m.r8(b+k);if(x!=y)return false;if(!x)return true;}throw std::domain_error("1254 bounded original RTTI names");}
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Observation&o){
 need(root==0x22e950u&&m.r32(i.cx)==0x793b90u&&m.r32(i.cx+0x24u)==0u&&m.r32(i.cx+0x40u)==0u&&(m.r8(i.cx+0x14u)&7u)==0u);
 constexpr unsigned derived[]{0x793b90u,0x793b74u,0x793b6cu,0x793b64u};for(unsigned k=0;k<4u;++k)m.w32(i.cx+4u*k,derived[k]);
 const unsigned table=m.r32(0x81a958u),cell=m.r32(table);need(cell&&m.r32(cell)==0x788b04u&&m.r32(cell+0x24u)==0u&&m.r32(cell+0xf8u)==0u);++o.cell_queries;m.w32(cell+0xf8u,0u);++o.zero_cell_stores;
 need(m.r32(0x793bbcu)==0x62ea20u&&m.r32(0x81b9c0u)==0u&&m.r32(0x81b9c4u)==0u);++o.kind_callbacks;
 // Original CRT chooses its two-pass flags5 hierarchy path. Neither pass
 // can find AbstractTypeClass; every comparison is against actual readonly names.
 const unsigned col=m.r32(0x793b8cu);need(col==0x7ab610u&&m.r32(col+4u)==0u&&m.r32(col+8u)==0u);const unsigned h=m.r32(col+16u);need(h==0x7ab600u&&m.r32(h+4u)==5u&&m.r32(h+8u)==9u);const unsigned bases=m.r32(h+12u);
 for(unsigned pass=0;pass<2u;++pass)for(unsigned k=0;k<9u;++k){const unsigned b=m.r32(bases+4u*k),td=m.r32(b);need(td!=0x7b91f0u&&!same_name(m,td+8u,0x7b91f8u));++o.rtti_strings;}
 need(m.r32(0xa9e168u)==0x793b24u&&m.r32(0x793b34u)==0x62f7e0u&&m.r32(0xa9e170u)==10u);const unsigned n=m.r32(0xa9e178u),p=m.r32(0xa9e16cu);need(n>=1u&&n<=6u&&p);unsigned index=0u;while(index<n){++o.find_comparisons;if(m.r32(p+4u*index)==i.cx)break;++index;}need(index<n);m.w32(0xa9e178u,n-1u);++o.registry_removals;for(unsigned k=index;k+1u<n;++k){m.w32(p+4u*k,m.r32(p+4u*k+4u));++o.shifts;}
 constexpr unsigned base[]{0x785dd8u,0x785dbcu,0x785db4u,0x785dacu};for(unsigned k=0;k<4u;++k){m.w32(i.cx+4u*k,base[k]);++o.base_vptr_writes;}
 return n-1u;
}
}
