#include "recovered/recovery_b884.hpp"
namespace ra2::recovered::recovery_b884 {using U=std::uint32_t;
U fun_005acaf0(Memory&m,const Inputs&i){if(!i.cx||m.r32(0x791ec8)!=0x5ae3f0||m.r32(0x791ea8)!=0x5ae450)throw std::domain_error("884 actualinstalledvirtualtargets");const U offsets[]={0,0x2c,0x44},vtables[]={0x791ebc,0x791e9c,0x791e7c};for(U k=0;k<3;++k){U p=i.cx+offsets[k];m.w32(p,vtables[k]);m.w32(p+4,0);m.w32(p+8,0);m.w8(p+12,1);m.w8(p+13,0);m.w32(p+16,0);m.w32(p+20,10);}m.w32(i.cx+0x28,0);return i.cx;}
}
