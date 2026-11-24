#include "recovered/recovery_b1000.hpp"
#include <stdexcept>
namespace ra2::recovered::b1000 {
namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
LPCRITICAL_SECTION cs(unsigned p){need(p!=0u,"1000 genuine initialized critical section");return reinterpret_cast<LPCRITICAL_SECTION>(std::uintptr_t(p));}
void outer(Memory&m,Api&a,unsigned index,bool enter){const auto p=m.r32(0x817278u+index*4u);if(enter)a.enter(cs(p));else a.leave(cs(p));}
}
std::uint32_t fun_0077d227(Memory&m,const Inputs&,Api&a){
 need(m.r32(0xb10d00u)!=0u&&m.r32(0xb10e00u)==32u,"1000 existing first32 descriptorblock");outer(m,a,18u,true);const auto block=m.r32(0xb10d00u);
 for(unsigned index=0;index<32u;++index){const auto p=block+36u*index;if(m.r8(p+4u)&1u)continue;need(m.r32(p+8u)!=0u,"1000 descriptor CS already initialized");a.enter(cs(p+12u));need((m.r8(p+4u)&1u)==0u,"1000 stable free descriptor after lock");m.w32(p,0xffffffffu);outer(m,a,18u,false);return index;}
 throw std::domain_error("1000 positive free descriptor required");
}
std::uint32_t fun_00776966(Memory&m,const Inputs&,Api&a){
 const auto count=m.r32(0xb11e40u),table=m.r32(0xb10e3cu);need(count>20u&&count<=32u&&table!=0u,"1000 existing FILE pointertable");outer(m,a,2u,true);
 for(unsigned index=0;index<count;++index){const auto p=m.r32(table+index*4u);need(p!=0u,"1000 all FILE slots preallocated");if(m.r8(p+12u)&0x83u)continue;need(index>=20u,"1000 per-FILE realCS route");a.enter(cs(p+32u));need((m.r8(p+12u)&0x83u)==0u,"1000 stable free FILE after lock");m.w32(p+16u,0xffffffffu);for(unsigned off:{0u,4u,8u,12u,28u})m.w32(p+off,0u);outer(m,a,2u,false);return p;}
 throw std::domain_error("1000 positive free FILE required");
}
std::uint32_t fun_0077d487(Memory&m,const Inputs&i,Api&a){
 unsigned flags=0;if(i.arg[1]&8u)flags|=0x20u;if(i.arg[1]&0x4000u)flags|=0x80u;if(i.arg[1]&0x80u)flags|=0x10u;
 need(a.file_type(reinterpret_cast<HANDLE>(std::uintptr_t(i.arg[0])))==FILE_TYPE_DISK,"1000 genuine disk handle");const auto fd=fun_0077d227(m,i,a);need(fd>=3u&&fd<32u,"1000 nonstandard descriptor avoids SetStdHandle");const auto p=m.r32(0xb10d00u)+36u*fd;need(m.r32(p)==0xffffffffu&&fd<m.r32(0xb10e00u),"1000 exact preallocated sethandle route");m.w32(p,i.arg[0]);m.w8(p+4u,flags|1u);a.leave(cs(p+12u));return fd;
}
}
