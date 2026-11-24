#include "recovered/shading1091.hpp"
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::shading1091 {
namespace {
void need(bool x){if(!x)throw std::domain_error("1091 private general-mask extension outside positive producer-derived general-format shading domain");}
unsigned convert(Memory&m,const Inputs&i,unsigned value){i.fp.load_integer32(value*1000u);i.fp.multiply64(floating_b61::read64(m,0x7905c8u));const auto control=std::uint16_t(m.r32(0x7c3a04u));if(i.fp.control()!=control)i.fp.load_control(control);return unsigned(i.fp.pop_integer64());}
}
std::uint32_t fun_00536c80(Memory&m,const Inputs&i){
 const auto p=i.cx,n=m.r32(p+0x16cu),output=m.r32(p+0x170u),source=m.r32(p+0x188u);const auto mask=m.r32(p+0x190u);need((n==1u||n==53u)&&output&&source!=0u&&(mask==0x7ca3a0u||mask==0x7dc238u));need(m.r32(0x7ca4a0u)==0xffffffffu&&m.r32(0x7c13c0u)==0xffffffffu);
 const unsigned shift_addresses[]{0x83b2e8u,0x83b2ecu,0x83b2f8u,0x83b2fcu,0x83b2f0u,0x83b2f4u};unsigned shifts[6]{};for(unsigned k=0;k<6u;++k)shifts[k]=m.r32(shift_addresses[k]);const bool first=shifts[0]==0u&&shifts[1]==3u&&shifts[2]==5u&&shifts[3]==2u&&shifts[4]==11u&&shifts[5]==3u;const bool second=shifts[0]==8u&&shifts[1]==4u&&shifts[2]==4u&&shifts[3]==4u&&shifts[4]==0u&&shifts[5]==4u;need(first||second);
 const bool overlay=(i.arg[3]&255u)!=0u;std::array<unsigned,3>color{};
 if(i.arg[0]==0xffffffffu){for(unsigned k=0;k<3u;++k)color[k]=m.r32(p+(overlay?0x1a4u:0x198u)+4u*k);}
 else{for(unsigned k=0;k<3u;++k){color[k]=unsigned(std::max(0,std::min(2000,global_b26::s32(i.arg[k]))));m.w32(p+(overlay?0x1a4u:0x198u)+4u*k,color[k]);}}
 m.w8(p+0x1b0u,overlay?1u:0u);std::array<unsigned,3>scale{};for(unsigned k=0;k<3u;++k){need(color[k]>=1u&&color[k]<=2000u);i.arg[3]=color[k]*1000u;scale[k]=convert(m,i,color[k]);}
 for(unsigned row=0;row<n;++row){std::array<unsigned,3>factor{};for(unsigned k=0;k<3u;++k)factor[k]=n==1u?scale[k]:(2u*scale[k]*row)/(n-1u);i.arg[1]=factor[1];i.arg[2]=factor[0];i.arg[3]=factor[2];const auto dest=output+512u*row;m.w16(dest,0u);for(unsigned pixel=1;pixel<256u;++pixel){need(m.r8(mask+pixel)<=1u);unsigned packed=0u;for(unsigned k=0;k<3u;++k){const auto channel=std::min(255u,(m.r8(source+3u*pixel+k)*(m.r8(mask+pixel)?factor[k]:(n==1u||row>6u?65536u:(row*65536u)/6u)))>>16u);packed|=(channel>>shifts[2u*k+1u])<<shifts[2u*k];}m.w16(dest+2u*pixel,packed);}i.arg[0]=dest+512u;}
 return 2u*scale[2];
}
}
