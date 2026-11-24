#include "recovered/recovery_b848.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b848 {
static void need(bool ok,const char*why){if(!ok)throw std::domain_error(why);}
std::uint32_t fun_006c4930(Memory&m,const Inputs&i){using U=std::uint32_t;U self=i.cx,vptr=m.r32(self);need(vptr==0x798c88&&m.r32(vptr+0x80)==0x6b6910&&m.r32(vptr+0x84)==0x6f9c70&&m.r32(vptr+0x2c)==0x6fee90,"848 original virtual dispatch");
 U type=m.r32(self+0x5ac);need(type&&m.r8(type+0xaa6)==0&&m.r8(0xa28953)==0&&m.r32(self+0x1b8)==1,"848 transitioning unit route");U progress=m.r32(self+0x1bc),rules=m.r32(0x821b88);need(progress>0&&progress<=1024,"848 bounded positive progress");U duration=m.r32(rules+0x548);need(duration==128||duration==256||duration==512,"848 exact dyadic duration");i.arg[1]=progress;
 auto&fp=i.fp;need(fp.control()==m.r32(0x7c3a04),"848 original conversion CW");fp.load_integer32(progress);fp.divide_integer32(duration);fp.multiply64(std::uint64_t(m.r32(0x785700))|(std::uint64_t(m.r32(0x785704))<<32));U opacity=U(fp.pop_integer64());
 if(opacity<64)return 1;if(opacity<128)return 2;if(opacity<192)return 3;if((i.arg[0]&255)==0&&m.r8(self+0x372))return 3;return opacity>=255?5:4;
}
}
