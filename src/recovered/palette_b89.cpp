#include "palette_b89.hpp"
#include "global_b62_a.hpp"
#include <algorithm>
#include <stdexcept>

namespace ra2::recovered::palette_b89 {
namespace {
std::uint32_t scale(std::uint32_t c,std::uint32_t k){return std::min((c*k)>>16u,255u);}
std::uint32_t pack(Memory&m,const Inputs&i,bool blue_six){
 if(m.r8(0x7e98e2)||m.r8(0x7e98e0))throw std::domain_error("Block89 scalar selectors required");
 m.w16(i.arg[1],0);std::uint32_t result=0;
 for(unsigned n=1;n<256;++n){
  const auto src=i.arg[0]+3*n;const bool mask=m.r8(i.arg[6]+n)!=0;
  const auto r=scale(m.r8(src),i.arg[mask?2:5]);
  const auto g=scale(m.r8(src+1),i.arg[mask?3:5]);
  const auto b=scale(m.r8(src+2),i.arg[mask?4:5]);
  result=blue_six?((r&0xf8)<<8)|((g&0xf8)<<3)|((b&0xfc)>>2):((r&0xf8)<<7)|((g&0xf8)<<2)|((b&0xf8)>>3);
  m.w16(i.arg[1]+2*n,result);
 }
 return result;
}
}
std::uint32_t fun_0041f110(Memory&m,const Inputs&){
 if(m.r8(0x8349cc)||m.r32(0x8249a0))throw std::domain_error("Block89 requires fresh lookup flag and zero callbacks");
 m.w8(0x8349cc,1);
 for(std::uint32_t n=0;n<65536;++n){
  const auto p=(n&255u)*(n>>8u);
  const auto product=std::int64_t(global_b26::s32(0x81020409u))*p;
  const auto hi=std::uint32_t(std::uint64_t(product)>>32u);
  auto q=global_b26::sar(hi+p,6);q+=q>>31u;
  m.w8(0x8249b8u+n,std::clamp(global_b26::s32(q),0,255));
 }
 return 0;
}
std::uint32_t fun_004b30c0(Memory&m,const Inputs&i){
 const auto count=i.arg[0],output=i.arg[1];
 if(!output||!count||count>8)throw std::domain_error("Block89 supplied palette output/count required");
 for(unsigned n=0;n<256;n+=4)m.w32(output+n,0xffffffffu);
 for(unsigned n=0;n<count;++n){
  const auto record=i.dx+4*n;m.w8(output+m.r8(record),n);
  Inputs h=i;h.dx=output+256*(n+1);h.arg[0]=m.r8(record+1);h.arg[1]=m.r8(record+2);
  global_b26::fun_004b2e70(m,h);
 }
 return output;
}
std::uint32_t fun_0078307a(Memory&m,const Inputs&i){return pack(m,i,false);}
std::uint32_t fun_007833ba(Memory&m,const Inputs&i){return pack(m,i,true);}
}
