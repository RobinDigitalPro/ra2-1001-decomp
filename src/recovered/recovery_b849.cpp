#include "recovered/recovery_b849.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b849 {
static void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
static std::uint32_t lookup_one(Memory&m,std::uint32_t key){need(m.r32(0xab7eb8)==1&&m.r32(0xb10530)==0,"849 original one-row locale0 lookup");auto row=m.r32(0xab7ec0),values=m.r32(0xab7ec4);need(row&&values&&key,"849 lookup tables");unsigned length=0;for(;length<8;++length){unsigned a=m.r8(key+length),b=m.r8(row+length);if(a>='A'&&a<='Z')a+=32;if(b>='A'&&b<='Z')b+=32;need(a==b,"849 positive key match");if(!a)break;}need(length>0&&length<8&&m.r32(row+0x24)==0,"849 finite lookup key/index");return m.r32(values);}
std::uint32_t fun_006e1070(Memory&m,const Inputs&i){auto self=i.cx,current=m.r32(self+4);need(current&&m.r32(self)==0x7987dc&&m.r32(0x7987e0)==0x6e1040,"849 original base-manager callback");auto source=lookup_one(m,m.r32(current+0x14));need(source,"849 localized value");unsigned length=0;while(length<256&&m.r16(source+2*length))++length;need(length>0&&length<256,"849 bounded nonempty wide text");for(unsigned k=0;k<256;++k)m.w16(self+0x28+2*k,k<length?m.r16(source+2*k):0);m.w32(self+0x1c,m.r32(self+0x14));m.w32(self+0x18,m.r32(self+0x10));return 1;}
}
