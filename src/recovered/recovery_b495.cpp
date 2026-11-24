#include "recovered/recovery_b495.hpp"
#include <cstdio>
#include <stdexcept>

namespace ra2::recovered::recovery_b495 {
namespace {
using U=std::uint32_t;
void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
}
U fun_00707a90(Memory&m,const Inputs&in){
 const U self=in.cx;need(self,"B495 requires a nonnull receiver");
 U flags=m.r32(self+0x44u);need(flags&8u,"B495 warm receiver flag required; cold file-read path is excluded");
 U local_value;
 if(flags&4u)local_value=m.r16(self+0x0au);
 else {local_value=1u;m.w16(self+0x0au,1u);flags|=4u;m.w32(self+0x44u,flags);}
 for(unsigned n=0;n<4u&&((local_value&0x0fu)==0);++n)local_value>>=4u;
 U global_flags=m.r32(0x00a2890cu);
 need(global_flags&8u,"B495 warm global flag required; cold file-cache path is excluded");
 U global_value;
 if(global_flags&2u)global_value=m.r32(0x00a288d0u);
 else {global_value=1u;m.w16(0x00a288d0u,1u);m.w32(0x00a2890cu,global_flags|2u);}
 char text[32]{};
 const int length=std::snprintf(text,sizeof(text),"%d.%3.3d",int(global_value&0xffffu),int(local_value&0xffffu));
 need(length>=0&&unsigned(length)<sizeof(text),"B495 finite integer formatting");
 for(unsigned k=0;k<=unsigned(length);++k)m.w8(self+0x0cu+k,std::uint8_t(text[k]));
 return self+0x0cu;
}
}
