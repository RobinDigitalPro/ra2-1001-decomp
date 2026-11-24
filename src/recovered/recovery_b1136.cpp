#include "recovered/recovery_b1136.hpp"
#include <stdexcept>
namespace ra2::recovered::b1136 {
static void need(bool x){if(!x)throw std::domain_error("1136 positive original Cell/vector/tag numeric graph");}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&heap,State&fp){(void)heap;(void)fp;const auto s=i.cx;need(root==0x72c00u||root==0x79f40u);
 if(root==0x72c00u){need(m.r8(0xa28953u)==0u&&m.r32(s+0xe4u)==0u&&m.r32(s+0xe8u)==0u);const auto count=m.r32(0x81a900u),capacity=m.r32(0x81a8f8u),data=m.r32(0x81a8f4u);need(count==3u&&capacity==10u&&data!=0u);m.w32(0x81a900u,count+1u);m.w32(data+4u*count,m.r32(s+0x24u));const auto rules=m.r32(0x821b88u);need(m.r32(rules+0x160u)==0u);return rules;}
 const auto arg=i.arg[0];if(m.r32(s+0x3cu)==arg){if(arg)m.w32(arg+0x2cu,m.r32(arg+0x2cu)-1u);m.w32(s+0x3cu,0u);const auto count=m.r32(0x81b988u),data=m.r32(0x81b97cu),coord=m.r32(s+0x24u);need(m.r32(0x81b978u)==0x7875a0u);unsigned index=0u;while(index<count&&m.r32(data+4u*index)!=coord)++index;need(index<count&&count==3u);m.w32(0x81b988u,count-1u);for(unsigned k=index;k<count-1u;++k)m.w32(data+4u*k,m.r32(data+4u*(k+1u)));}
 if(m.r32(s+0x2cu)==arg)m.w32(s+0x2cu,0u);if(m.r32(s+0x30u)==arg)m.w32(s+0x30u,0u);need(m.r32(s+0x28u)==0u);return 0u;
}
}
