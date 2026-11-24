#include "recovery_b1181.hpp"
#include <stdexcept>
namespace ra2::recovered::b1181{
static void need(bool x){if(!x)throw std::domain_error("1181 genuine spatialbucket move");}
unsigned run(Memory&m,Inputs&i,Heap&h,unsigned root,unsigned arena,Observation&z){need(root==0x13600u&&i.cx==0x8221e0u&&i.arg[1]==0u&&i.arg[2]==1u);const unsigned actor=i.arg[0];need(actor>=arena+0x1000u&&actor<arena+0x9000u&&m.r32(actor)==0x78e540u&&m.r32(actor+0x458u)==0u&&m.r32(0x78e80cu)==0x41b560u&&m.r32(0x7857acu)==0x40baa0u&&m.r32(0x81a948u)==39u&&m.r32(0x81a94cu)==39u);m.w32(actor+0x458u,1u);z.virtual_callbacks=2u;
 const unsigned old=0x8221e0u,now=old+24u,a=m.r32(old+4u),b=m.r32(now+4u),n=m.r32(old+16u),k=m.r32(now+16u);need(m.r32(old)==0x78579cu&&m.r32(now)==0x78579cu&&m.r32(old+8u)==10u&&m.r32(now+8u)==10u&&n>=2u&&n<=4u&&k>=1u&&k<=3u&&m.r8(old+12u)==1u&&m.r8(now+12u)==1u&&m.r8(old+13u)==1u&&m.r8(now+13u)==1u&&m.r32(old+20u)==10u&&m.r32(now+20u)==10u);unsigned j=0u;while(j<n&&h.r32(a+4u*j)!=actor)++j;need(j<n);m.w32(old+16u,n-1u);for(unsigned x=j+1u;x<n;++x)h.w32(a+4u*(x-1u),h.r32(a+4u*x));m.w32(now+16u,k+1u);h.w32(b+4u*k,actor);z.removals=z.insertions=1u;return k;}
unsigned cleanup(Memory&m,unsigned self,Heap&h){need(m.r32(self)==0x78579cu&&m.r8(self+13u)==1u);m.w32(self+16u,0u);const unsigned a=m.r32(self+4u);need(a);const unsigned result=h.release(a);need(result!=0u);m.w32(self+4u,0u);m.w8(self+13u,0u);m.w32(self+8u,0u);return result;}
}
