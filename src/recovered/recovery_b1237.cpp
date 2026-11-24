#include "recovery_b1237.hpp"
#include <stdexcept>
namespace ra2::recovered::b1237 {
static void need(bool x){if(!x)throw std::domain_error("1237 finite plain Clear zone producer contract");}
static unsigned r16(Heap&h,unsigned p){return h.r8(p)|(h.r8(p+1u)<<8u);}
static void w16(Heap&h,unsigned p,unsigned x){h.w8(p,x);h.w8(p+1u,x>>8u);}
struct Fill {unsigned count,skip,upper;};
// The reached class0/height0 path of54C6E0. Actual scanline recursion and
// caller scratch slots remain separate from the geometry-based test oracle.
static Fill fill(Memory&m,Heap&h,unsigned self,unsigned p,unsigned label){
 const unsigned stride=4u*(m.r32(self+0xf0u)+m.r32(self+0xf4u)+1u),kind=h.r8(p);
 need(kind==0u&&h.r8(p+1u)==0u&&label==1u);
 unsigned left=p,right=p;
 do {need(h.r8(left+1u)==0u);w16(h,left+2u,label);left-=4u;}while(h.r8(left)==kind);
 // In this proven flat domain both original height thresholds admit all rows.
 while(h.r8(right)==kind){need(h.r8(right+1u)==0u);w16(h,right+2u,label);right+=4u;}
 need(r16(h,left+2u)==0u&&r16(h,right+2u)==0u);
 const unsigned first=left+4u,last=right-4u,upper=last-stride+4u;
 unsigned count=(right-left)/4u-1u;
 for(unsigned q=first-stride-4u;q<=upper;){
  const auto old=r16(h,q+2u);need(old==0u||old==label);
  if(old==0u&&h.r8(q)==kind){need(h.r8(q+1u)==0u);const auto z=fill(m,h,self,q,label);count+=z.count;q+=4u*z.skip;}
  else q+=4u;
 }
 for(unsigned q=first+stride-4u;q<=last+stride+4u;){
  const auto old=r16(h,q+2u);need(old==0u||old==label);
  if(old==0u&&h.r8(q)==kind){need(h.r8(q+1u)==0u);const auto z=fill(m,h,self,q,label);count+=z.count;q+=4u*z.skip;}
  else q+=4u;
 }
 return {count,(right-p)/4u-1u,upper};
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h){
 need(root==0x14c6e0u);const auto self=i.cx;
 need(m.r32(self)==0x79091cu&&m.r32(self+0xf0u)==7u&&m.r32(self+0xf4u)==11u&&m.r32(self+0x68u)==361u);
 const auto cache=m.r32(self+0x64u);need(cache!=0u&&m.r32(0xa5784cu)==0u);
 need(i.arg[0]==cache+408u&&i.arg[1]==1u);const auto out=i.arg[2];const auto z=fill(m,h,self,i.arg[0],i.arg[1]);m.w32(out,z.skip);i.arg[0]=76u;i.arg[2]=z.upper;return z.count;
}
}
