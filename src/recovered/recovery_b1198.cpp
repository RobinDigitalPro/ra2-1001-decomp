#include "recovery_b1198.hpp"
#include <stdexcept>
namespace ra2::recovered::b1198{
static void need(bool x){if(!x)throw std::domain_error("1198 bounded actualnonlost surface lock/unlock");}
unsigned run(Memory&m,const Inputs&i,Api&api,unsigned root,Observation&o){
 const unsigned self=i.cx,surface=m.r32(self+0x1cu),descriptor=m.r32(self+0x20u);need(m.r8(0x839fe0u)==1u&&m.r32(self)==0x78bbe4u&&surface&&descriptor);o.lost_hresult=api.is_lost(surface);++o.calls;need(o.lost_hresult==0u);
 if(root==0xaa990u){need(i.arg[0]<m.r32(self+4u)&&i.arg[1]<m.r32(self+8u)&&m.r32(self+0xcu)==0u&&m.r32(self+0x14u)==0u);alignas(4) Descriptor d{};d[0]=108u;o.operation_hresult=api.lock(surface,d);++o.calls;need(o.operation_hresult==0u);o.descriptor=d;for(unsigned k=0;k<108u;++k)m.w8(descriptor+k,d[k]);m.w32(self+0x10u,(m.r32(descriptor+0x54u)+7u)>>3u);m.w8(self+0x19u,(m.r32(descriptor+0x68u)>>14u)&1u);m.w32(self+0x14u,m.r32(descriptor+0x24u));m.w32(self+0xcu,1u);need(m.r32(0x78bc54u)==0x4aa970u&&m.r32(0x78bc58u)==0x4aa980u);return m.r32(self+0x14u)+m.r32(descriptor+0x10u)*i.arg[1]+m.r32(self+0x10u)*i.arg[0];}
 need(root==0xaab50u&&m.r32(self+0xcu)==1u&&m.r32(self+0x14u)!=0u);m.w32(self+0xcu,0u);o.operation_hresult=api.unlock(surface,m.r32(self+0x14u));++o.calls;need(o.operation_hresult==0u);m.w32(self+0x14u,0u);return(o.operation_hresult&0xffffff00u)|1u;
}
}
