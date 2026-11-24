#include "recovery_b1135.hpp"
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::b1135{
static void need(bool x){if(!x)throw std::domain_error("1135 finite positive owned string/coordinate resize");}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h){need(root==0x269870u||root==0x31a280u);const bool strings=root==0x269870u;const unsigned stride=strings?4u:12u,owner=i.cx,n=i.arg[0],old=m.r32(owner+4u),oldn=m.r32(owner+8u),used=m.r32(owner+16u);need(n>=1u&&n<=269u&&!i.arg[1]&&old&&oldn>=2u&&oldn<=8u&&used>=1u&&used<=oldn&&m.r8(owner+12u)==1u&&m.r8(owner+13u)==1u&&m.r32(owner)==(strings?0x79450cu:0x799e1cu)&&h.r32(old-4u)==oldn);m.w8(owner+12u,0u);const auto raw=h.allocate(n*stride+4u);need(raw);h.w32(raw,n);for(unsigned k=0;k<n;++k)for(unsigned q=0;q<stride;q+=4u)h.w32(raw+4u+stride*k+q,0u);m.w8(owner+12u,1u);const unsigned keep=std::min(n,oldn);
 if(strings){for(unsigned k=0;k<keep;++k){const auto source=h.r32(old+4u*k);need(source);unsigned length=0u;while(length<80u&&h.r8(source+length))++length;need(length>=17u&&length<80u);const auto p=h.allocate(length+1u);need(p);h.w32(raw+4u+4u*k,p);h.w8(p,0u);for(unsigned q=0;q<=length;++q)h.w8(p+q,h.r8(source+q));}for(unsigned k=oldn;k;--k){const unsigned holder=old+4u*(k-1u);need(h.release(h.r32(holder))!=0u);h.w32(holder,0u);}}
 else for(unsigned k=0;k<keep;++k)for(unsigned q=0;q<12u;q+=4u)h.w32(raw+4u+12u*k+q,h.r32(old+12u*k+q));
 need(h.release(old-4u)!=0u);m.w32(owner+4u,0u);m.w32(owner+4u,raw+4u);m.w32(owner+8u,n);m.w8(owner+13u,1u);if(n<used)m.w32(owner+16u,n);return(n&0xffffff00u)|1u;}
unsigned cleanup(unsigned root,Memory&m,unsigned owner,Heap&h){need(root==0x269870u||root==0x31a280u);const bool strings=root==0x269870u;const auto data=m.r32(owner+4u),n=m.r32(owner+8u);need(data&&m.r8(owner+13u)==1u&&h.r32(data-4u)==n);m.w32(owner+16u,0u);if(strings)for(unsigned k=n;k;--k){const unsigned holder=data+4u*(k-1u),p=h.r32(holder);if(p)need(h.release(p)!=0u);h.w32(holder,0u);}const auto eax=h.release(data-4u);need(eax!=0u);m.w32(owner+4u,0u);m.w8(owner+13u,0u);m.w32(owner+8u,0u);return eax;}
}
