#include "recovered/recovery_b919.hpp"
#include "recovered/recovery_b917.hpp"
#include <array>
#include <stdexcept>
#include <string>
namespace ra2::recovered::recovery_b919{using U=std::uint32_t;
U fun_0077fa39(Memory&m,const Inputs&i){if(m.r32(0xb10e20)||!i.arg[4])throw std::domain_error("919 interlocked-only locale route");std::string format;for(U k=0;k<32;++k){U c=m.r8(i.arg[2]+k);if(!c)break;format.push_back(char(c));}if(format!="%H:%M:%S"&&format!="%Y-%m-%d"&&format!="%d/%m/%Y"&&format!="%I:%M"&&format!="%y.%m.%d")throw std::domain_error("919 finite numericformats");const U capacity=i.arg[1];if(capacity<32||capacity>95)throw std::domain_error("919 amplecapacity");std::array<std::uint8_t,8>cells{};leaf::Memory local(cells.data(),0xf0000000u,8);Memory view=m;view.add(local);local.w32(0xf0000000u,i.arg[0]);local.w32(0xf0000004u,capacity);m.w32(0xb10e24,m.r32(0xb10e24)+1);for(U at=0;at<format.size();++at){U c=std::uint8_t(format[at]);if(c=='%'){m.w32(0xb10ac0,0);Inputs field=i;field.arg[0]=std::uint8_t(format[++at]);field.arg[1]=i.arg[3];field.arg[2]=0xf0000000u;field.arg[3]=0xf0000004u;(void)recovery_b917::fun_0077fb33(view,field);}else{if(m.r16(m.r32(0x817560)+2*c)&0x8000)throw std::domain_error("919 ASCIIseparator");U p=local.r32(0xf0000000u);m.w8(p,c);local.w32(0xf0000000u,p+1);local.w32(0xf0000004u,local.r32(0xf0000004u)-1);}}m.w32(0xb10e24,m.r32(0xb10e24)-1);i.arg[0]=local.r32(0xf0000000u);i.arg[4]=local.r32(0xf0000004u);m.w8(i.arg[0],0);return capacity-i.arg[4];}
}
