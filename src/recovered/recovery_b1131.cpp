#include "recovered/recovery_b1131.hpp"
#include <stdexcept>
namespace ra2::recovered::b1131 {
unsigned dirty0(Memory&m,Observation&z){if(m.r32(0x821cacu))throw std::domain_error("1131 inactive auxiliary dirty route");++z.dirty_routes;return 0u;}
unsigned run(Memory&m,Inputs&i,Heap&,unsigned root,unsigned base,Observation&z){
 const unsigned p=i.cx,group=m.r32(0x81f6f8u),n=m.r32(p+0x50u),row=m.r32(p+0x40u),scenario=m.r32(0xa255c0u),flag=m.r8(scenario+0x2239u);
 if(root!=0x2747f0u||group>=4u||p!=base+0x2540u+group*0xe64u||n<13u||n>18u||row<1u||row>(n+1u)/2u-6u||m.r8(p+0x39u)||m.r8(p+0x3bu)||m.r32(p+0x44u)!=0xfffffffau||m.r32(p+0x3cu)!=0xffffffffu||m.r32(0xaa486cu)!=227u||m.r32(0xaa4874u)!=50u||m.r32(0xaa4888u)!=50u||m.r32(0x821964u)!=0u||m.r32(0x82196cu)!=600u||flag>1u||m.r32(0x821cacu)!=0u)throw std::domain_error("1131 positive original last-page scroll-up request/count/geometry/row producer scope");
 for(unsigned k=0;k<n;++k)if(m.r32(p+0x64u+k*48u)!=0u||m.r32(p+0x60u+k*48u)!=0u)throw std::domain_error("1131 actual positive inactive inserted records; no observable timerrestart use of S-120 or object event callback");
 m.w32(p+0x44u,0xfffffffbu);m.w8(p+0x3au,0u);m.w8(p+0x3bu,1u);m.w32(p+0x40u,row-1u);m.w32(p+0x48u,0u);
 m.w32(p+0x48u,50u);m.w8(p+0x3bu,0u);m.w32(p+0x48u,0u);
 m.w8(0x81f702u,1u);m.w8(0x81bd98u+group*0xe64u,1u);dirty0(m,z);m.w8(p+0x38u,1u);const auto eax=dirty0(m,z);m.w8(0x81f703u,1u);m.w8(0xaa488cu,1u);
 return (eax&0xffffff00u)|1u;
}
}
