#include "recovery_b1192.hpp"
#include <algorithm>
#include <stdexcept>
#include <utility>
namespace ra2::recovered::b1192{
namespace{
void need(bool x){if(!x)throw std::domain_error("1192 finite positive actual DirectDraw enumeration");}
unsigned word(const Descriptor&d,unsigned k){return unsigned(d[k])|(unsigned(d[k+1])<<8u)|(unsigned(d[k+2])<<16u)|(unsigned(d[k+3])<<24u);}
struct Collector:Sink{
 Heap&h;Observation&seen;std::vector<unsigned>owned;unsigned data=0,capacity=0;
 Collector(Heap&heap,Observation&o):h(heap),seen(o){}
 unsigned row(const Descriptor&d)override{
  need(word(d,0u)==108u&&owned.size()<64u);
  // Original495FD0 allocates/copies the descriptor BEFORE growing its vector.
  const unsigned copy=h.allocate(108u);need(copy!=0u);
  for(unsigned k=0;k<108u;++k)h.w8(copy+k,d[k]);
  if(owned.size()==capacity){
   const unsigned next=capacity+10u,storage=h.allocate(next*4u);need(storage!=0u);
   for(unsigned k=0;k<capacity*4u;++k)h.w8(storage+k,h.r8(data+k));
   if(data)need(h.release(data)!=0u);
   data=storage;capacity=next;
  }
  h.w32(data+4u*unsigned(owned.size()),copy);owned.push_back(copy);
  seen.descriptors.push_back(d);++seen.callbacks;return 1u;
 }
};
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h,Api&api,Observation&seen,State&){
 need(root==0x96080u&&i.cx==640u&&i.dx==480u&&i.arg[2]==16u);
 need((i.arg[0]==1024u&&i.arg[1]==768u)||(i.arg[0]==4096u&&i.arg[1]==4096u));
 const unsigned object=m.r32(0x83a6fcu);need(object!=0u&&seen.callbacks==0u&&seen.descriptors.empty());
 Collector c(h,seen);seen.hresult=api.enumerate(object,0u,0u,c);
 need(seen.hresult==0u&&c.owned.size()==18u);seen.capacity=c.capacity;seen.backing=c.data;
 const unsigned bytes=8u*unsigned(c.owned.size())+4u,result=h.allocate(bytes);need(result!=0u);
 for(unsigned k=0;k<bytes;++k)h.w8(result+k,0u);
 std::vector<std::pair<unsigned,unsigned>>resolutions;
 for(unsigned p:c.owned){const unsigned width=h.r32(p+12u),height=h.r32(p+8u),bpp=h.r32(p+84u);need(bpp==32u);
  if(width<=i.arg[0]&&height<=i.arg[1]&&width>=i.cx&&height>=i.dx&&bpp==i.arg[2])resolutions.push_back({width,height});
  need(h.release(p)!=0u);
 }
 need(resolutions.empty());
 // Actual496199 frees the rejected output, then4961BB frees the final vector.
 // This finite real32bpp-provider/actual16bpp-caller route never invokes qsort.
 seen.result=result;need(h.release(result)!=0u);need(h.release(c.data)!=0u);return 0u;
}
}
