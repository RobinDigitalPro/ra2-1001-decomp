#include "recovered/recovery_b1154.hpp"
#include <stdexcept>
namespace ra2::recovered::b1154 {
namespace {
unsigned pending(Memory&m,unsigned actor){const auto start=m.r32(actor+0x58cu);auto left=m.r32(actor+0x594u);if(start!=0xffffffffu){const auto elapsed=m.r32(0xa2896cu)-start;if(std::int32_t(elapsed)>=std::int32_t(left))left=0u;else left-=elapsed;}return(left&0xffffff00u)|unsigned(left!=0u);}
unsigned lookup(Memory&m,unsigned x,unsigned y){const auto sx=std::int32_t(x),sy=std::int32_t(y);const unsigned column=unsigned(sx/256),row=unsigned(sy/256),index=(row<<9u)+column;if(std::int32_t(index)<0||std::int32_t(index)>=std::int32_t(m.r32(0x81a95cu)))throw std::domain_error("1154 excluded missing map coordinate");const auto cell=m.r32(m.r32(0x81a958u)+index*4u);if(!cell)throw std::domain_error("1154 excluded sentinel lookup");return cell;}
}
unsigned run(unsigned root,Memory&m,const Inputs&i,State&){if(root!=0x18e660u)throw std::domain_error("1154 selectedroot");const auto self=i.arg[0],actor=m.r32(self+8u);if(m.r32(self)!=0x791094u||m.r32(actor)!=0x78e540u)throw std::domain_error("1154 actual interface/actor publishers");unsigned eax=unsigned(std::int32_t(m.r32(actor+0x3fcu))>0);if(eax&255u)return eax;eax=pending(m,actor);if(eax&255u)return eax;eax=(eax&0xffffff00u)|m.r8(actor+0x204u);if(eax&255u)return eax;eax=(eax&0xffffff00u)|m.r8(actor+0x205u);if(eax&255u)return eax;for(unsigned k=0;k<3u;++k)m.w32(self+0x14u+4u*k,i.arg[k+1u]);eax=lookup(m,i.arg[1],i.arg[2]);if(m.r32(eax+0x140u)&0x100u)throw std::domain_error("1154 bridge height helper outside contract");m.w8(self+0x2cu,1u);return eax;}
}
