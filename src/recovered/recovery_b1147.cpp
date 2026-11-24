#include "recovered/recovery_b1147.hpp"
#include <stdexcept>
namespace ra2::recovered::b1147{
static void need(bool b){if(!b)throw std::domain_error("1147 reviewed positive numeric route");}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&,State&){
 if(root==0x2eb3d0u){const auto count=m.r32(0xa288b0u),data=m.r32(0xa288a4u);need(count>=2u&&count<=6u);unsigned value=0u;for(unsigned j=0;j<count;++j){const auto unit=m.r32(data+4u*j);need(unit!=0u&&(m.r8(unit+0x14u)&1u)&&m.r32(unit)==0x78e540u);const auto desc=m.r32(unit+0x5a8u);need(m.r32(desc)==0x78ea78u&&m.r32(desc+0x74cu)!=0u&&m.r8(desc+0x5e4u)==0u);value=(m.r32(desc+0x74cu)&0xffffff00u)|1u;}m.w8(0xaa8db8u,1u);return value;}
 need(root==0x156b70u&&i.cx==0x81a820u);const auto owner=i.arg[0];need(m.r32(owner)==0x7975a8u);const unsigned header=i.cx+0x1158u;auto count=m.r32(header+0x10u);const auto data=m.r32(header+4u);need(count==3u&&m.r32(header)==0x7875a0u);
 unsigned index=0u;while(index<m.r32(header+0x10u)){const auto q=m.r32(data+4u*index);const auto x=std::int32_t(std::int16_t(q&65535u)),y=std::int32_t(std::int16_t(q>>16u));const auto linear=unsigned(x+512*y);need(linear<0x40000u);const auto cell=m.r32(m.r32(i.cx+0x138u)+4u*linear);need(cell!=0u);
  if(m.r32(cell+0x3cu)==owner){m.w32(owner+0x2cu,m.r32(owner+0x2cu)-1u);m.w32(cell+0x3cu,0u);const auto coord=m.r32(cell+0x24u),n=m.r32(header+0x10u);unsigned found=0u;while(found<n&&m.r32(data+4u*found)!=coord)++found;need(found<n);m.w32(header+0x10u,n-1u);for(unsigned k=found;k+1u<n;++k)m.w32(data+4u*k,m.r32(data+4u*(k+1u)));}else ++index;
 }
 // Genuine79F40 on original70B10 sentinel poststate: owner differs from all
 // NULL fields; no resource/entity callback. Its fullEAX0 is overwritten below.
 need(m.r32(0xa57638u)==0u&&m.r32(0xa5763cu)==0u&&m.r32(0xa57640u)==0u&&m.r32(0xa5764cu)==0u);
 const auto reg=m.r32(0x84e56cu),n=m.r32(0x84e578u);need(m.r32(0x84e568u)==0x78dae4u&&n>=3u&&n<=6u);unsigned found=0u;while(found<n&&m.r32(reg+4u*found)!=owner)++found;need(found<n);m.w32(0x84e578u,n-1u);for(unsigned k=found;k+1u<n;++k)m.w32(reg+4u*k,m.r32(reg+4u*(k+1u)));return n-1u;
}
}
