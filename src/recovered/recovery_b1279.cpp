#include "recovery_b1279.hpp"
#include <stdexcept>
#include <vector>
namespace ra2::recovered::b1279 {
static void need(bool x){if(!x)throw std::domain_error("1279 finite plain Clear zone producer contract");}
static unsigned r16(Heap&h,unsigned p){return h.r8(p)|(h.r8(p+1u)<<8u);}
static void w16(Heap&h,unsigned p,unsigned x){h.w8(p,x);h.w8(p+1u,x>>8u);}
// Preserve the caller request exactly. A zero request enters the original
// small CRT branch at threshold zero; the mixed adapter owns that route.
static unsigned allocate(Heap&h,unsigned n){const auto p=h.allocate(n);need(p!=0u);return p;}
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
 need(root==0x14c060u);const auto self=i.cx;
 need(m.r32(self)==0x79091cu&&m.r32(self+0xf0u)==7u&&m.r32(self+0xf4u)==11u&&m.r32(self+0x68u)==361u);
 const auto cache=m.r32(self+0x64u);need(cache!=0u&&m.r32(0xa5784cu)==0u);
 const auto header=m.r32(self+0x14u);need(h.r32(header+8u)==256u&&h.r32(header+12u)==20u);
 const auto vectors=h.r32(header);need(h.r32(vectors-4u)==256u&&m.r32(0x790a64u)==0x567b30u);
 for(unsigned j=0;j<256u;++j){const auto v=vectors+24u*j;need(h.r32(v)==0x790a58u&&h.r32(v+4u)==0u&&h.r32(v+8u)==0u&&h.r8(v+12u)==1u&&h.r8(v+13u)==0u&&h.r32(v+16u)==0u&&h.r32(v+20u)==20u);h.w32(v+16u,0u);h.w8(v+13u,0u);h.w32(v+8u,0u);}
 for(unsigned j=0;j<12u;++j)need(m.r32(self+0x18u+4u*j)==0u);
 for(unsigned j=0;j<361u;++j)w16(h,cache+4u*j+2u,0u);
 need(m.r32(0x790aa0u)==0x568c00u&&m.r32(self+0x5cu)==0u);
 const auto classes=allocate(h,1200u);h.w32(classes,7u);unsigned regions=1u,largest=0u,best=0u;
 for(unsigned p=cache;p<cache+1444u;){const auto kind=h.r8(p);if(kind!=7u&&r16(h,p+2u)==0u){m.w32(0xa5784cu,0u);const auto z=fill(m,h,self,p,regions);if(z.count>largest){largest=z.count;best=regions;}h.w32(classes+4u*regions,kind);++regions;p+=4u*z.skip;}else p+=4u;}
 need(regions==2u);m.w32(self+0x48u,regions);
 // All edge buckets are genuinely empty after the no-bridge/no-Tube producer.
 for(unsigned j=0;j<256u;++j)need(h.r32(vectors+24u*j+16u)==0u);
 const auto counts=allocate(h,2u*regions);for(unsigned j=0;j<regions;++j)w16(h,counts+2u*j,0u);
 const auto lists=allocate(h,4u*regions);std::vector<unsigned>adjacent;
 for(unsigned j=0;j<regions;++j){const auto p=allocate(h,2u*r16(h,counts+2u*j));h.w32(lists+4u*j,p);adjacent.push_back(p);}
 for(unsigned j=0;j<regions;++j)w16(h,counts+2u*j,0u);
 const auto kinds=allocate(h,regions);for(unsigned j=0;j<regions;++j)h.w8(kinds+j,h.r8(classes+4u*j));
 const auto queue=allocate(h,2u*regions);
 for(unsigned table=0;table<12u;++table){const auto literals=0x7cab9cu+32u*table,out=allocate(h,2u*regions);m.w32(self+0x18u+4u*table,out);
  for(unsigned j=0;j<regions;++j)w16(h,out+2u*j,m.r32(literals+4u*h.r8(kinds+j))==1u?0u:1u);
  unsigned next=2u;for(unsigned j=0;j<regions;++j)if(r16(h,out+2u*j)==0u){w16(h,queue,j);w16(h,out+2u*j,next++);need(r16(h,counts+2u*j)==0u);}
  w16(h,out,0xffffu);
 }
 for(const auto p:adjacent)h.release(p);h.release(kinds);h.release(lists);h.release(counts);h.release(queue);h.release(classes);
 return best;
}
}
