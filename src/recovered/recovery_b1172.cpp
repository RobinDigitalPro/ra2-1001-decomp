#include "recovered/recovery_b1172.hpp"
#include <stdexcept>
namespace ra2::recovered::b1172 {namespace {
unsigned lookup(Memory&m,unsigned x,unsigned y){const auto sx=std::int32_t(x),sy=std::int32_t(y);const unsigned column=unsigned(sx/256),row=unsigned(sy/256),index=(row<<9u)+column;if(std::int32_t(index)<0||std::int32_t(index)>=std::int32_t(m.r32(0x81a95cu)))throw std::domain_error("1172 excluded missing map coordinate");const auto cell=m.r32(m.r32(0x81a958u)+index*4u);if(!cell)throw std::domain_error("1172 excluded sentinel lookup");return cell;}
}
unsigned run(unsigned root,Memory&m,const Inputs&i,State&){if(root!=0x312be0u)throw std::domain_error("1172 selectedroot");const auto self=i.arg[0],actor=m.r32(self+8u);if(m.r32(self)!=0x799968u||m.r32(self+0x14u)!=0x799944u||m.r32(actor)!=0x78e540u)throw std::domain_error("1172 actual interface/third-interface/actor publishers");unsigned eax=unsigned(std::int32_t(m.r32(actor+0x3fcu))>0);if(eax&255u)return eax;eax=(eax&0xffffff00u)|m.r8(actor+0x204u);if(eax&255u)return eax;eax=(eax&0xffffff00u)|m.r8(actor+0x205u);if(eax&255u)return eax;
for(unsigned k=0;k<3u;++k)m.w32(self+0x18u+4u*k,i.arg[k+1u]);if(i.arg[1]==m.r32(0xae0ae0u)&&i.arg[2]==m.r32(0xae0ae4u)&&i.arg[3]==m.r32(0xae0ae8u))throw std::domain_error("1172 excluded sentinel coordinate route");eax=lookup(m,i.arg[1],i.arg[2]);if(m.r32(eax+0x140u)&0x100u)throw std::domain_error("1172 bridge height helper outside contract");m.w8(self+0x30u,1u);return eax;}
}
