#include "recovery_b1177.hpp"
#include <stdexcept>
namespace ra2::recovered::b1177{
static void need(bool b){if(!b)throw std::domain_error("1177 actual nullable intrusive-reference cookiearray copy");}
static unsigned clear(Memory&m,unsigned self,Heap&h){need(m.r32(self)==0x79a1a8u&&m.r8(self+12u)==1u&&m.r8(self+13u)==1u&&m.r32(self+16u)==0u);m.w32(self+16u,0u);const unsigned data=m.r32(self+4u),base=data-4u,n=m.r32(self+8u);need(data&&n>0u&&h.r32(base)==n);
 // Actual7215E0 -> element78F52C slot0=51DB40 flags3. It destroys all
 // capacity slots backwards, even though logical dynamic-vector count is0.
 for(unsigned j=n;j>0u;--j){const unsigned slot=data+8u*(j-1u);need(h.r32(slot)==0x78f52cu&&h.r32(slot+4u)==0u);h.w32(slot,0x793cccu);}
 need(h.release(base)!=0u);m.w32(self+4u,0u);m.w8(self+13u,0u);m.w32(self+8u,0u);return base;
}
unsigned run(Memory&m,Inputs&i,Heap&h,unsigned root,unsigned arena,Observation&z){const unsigned self=i.cx,source=i.arg[0];need(root==0x321680u&&self==arena+0x1000u&&source==arena+0x4000u&&self!=source&&m.r32(0x79a1b4u)==0x7215e0u&&m.r32(0x78f52cu)==0x51db40u&&m.r32(source)==0x79a1a8u&&m.r32(source+16u)==0u&&m.r8(source+12u)==1u&&m.r8(source+13u)==1u);
 const unsigned n=m.r32(source+8u),src=m.r32(source+4u);need(n>=2u&&n<=6u&&src&&h.r32(src-4u)==n);clear(m,self,h);++z.frees;z.virtual_callbacks+=2u;m.w32(self+8u,n);
 const unsigned array=h.allocate(8u*n+4u);++z.allocations;need(array!=0u);h.w32(array,n);const unsigned data=array+4u;
 // Exact630A80 then78F52C publication for every newly allocated slot.
 for(unsigned j=0;j<n;++j){h.w32(data+8u*j,0x78f52cu);h.w32(data+8u*j+4u,0u);}m.w32(self+4u,data);m.w8(self+13u,1u);
 // Actual630AD0 compares eachnewNULL against sourceNULL; it returns directly.
 // This is not IUnknown::AddRef and no pointee/provider result is fabricated.
 for(unsigned j=0;j<n;++j)need(h.r32(src+8u*j)==0x78f52cu&&h.r32(src+8u*j+4u)==0u);return self;
}
unsigned cleanup(Memory&m,unsigned self,Heap&h){return clear(m,self,h);}
}
