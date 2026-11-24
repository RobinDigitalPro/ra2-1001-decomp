#include "recovered/recovery_b397.hpp"
namespace ra2::recovered::recovery_b397 {
namespace {
// Actual root supplies count=0 and storage=null to 569980/569a30/42d4a0.
// Those constructors still initialize every listed field; no allocation is reached.
void empty_vector(Memory&m,std::uint32_t p,std::uint32_t final_vptr){
 m.w32(p+4,0);m.w32(p+8,0);m.w8(p+12,1);m.w8(p+13,0);
 m.w32(p,final_vptr);m.w32(p+16,0);m.w32(p+20,10);
}
}
std::uint32_t fun_00544df0(Memory&m,const Inputs&i){
 const auto p=i.cx;
 // 4dff60 base initialization, with final vptr installed by this root.
 m.w32(p+4,0);m.w32(p+8,0);m.w32(p+12,2);
 empty_vector(m,p+0x4c,0x7909d8);
 for(unsigned n=0;n<3;++n)empty_vector(m,p+0x88+24*n,0x7909b8);
 empty_vector(m,p+0xd0,0x7875a0);
 m.w32(p+0x134,0x790998);m.w32(p+0x138,0);m.w32(p+0x13c,0);
 m.w8(p+0x140,1);m.w8(p+0x141,0);
 for(unsigned n=0;n<256;++n){m.w16(p+0x160+16*n,0);m.w16(p+0x162+16*n,0);}
 empty_vector(m,p+0x1158,0x7875a0);
 m.w32(p,0x79091c);m.w32(p+0x144,13);return p;
}
std::uint32_t fun_00498830(Memory&m,const Inputs&i){
 const auto p=i.cx;fun_00544df0(m,i);
 m.w32(p+0x1170,m.r32(0x83a940));m.w16(p+0x1174,0);m.w16(p+0x1176,0);
 m.w32(p+0x1178,0);m.w8(p+0x117c,0);m.w8(p+0x117d,0);
 m.w32(p+0x117e,m.r32(0x83a940));m.w16(p+0x1182,0);m.w16(p+0x1184,0);
 for(auto offset:{0x1188u,0x118cu,0x1190u,0x119cu,0x11a0u,0x11a4u,0x11b8u,0x11bcu,0x11c0u,0x11c4u,0x11d0u,0x11d4u,0x11d8u,0x11dcu})m.w32(p+offset,0);
 for(auto offset:{0x1194u,0x11a8u,0x11b4u})m.w32(p+offset,0xffffffffu);
 m.w8(p+0x1198,0);
 for(unsigned off=0x11ac;off<=0x11b0;++off)m.w8(p+off,0);
 for(unsigned off=0x11c8;off<=0x11cd;++off)m.w8(p+off,0);
 m.w32(p,0x78991c);m.w32(0x83ac68,0);m.w32(0x83a944,0);m.w32(0x83a960,0);return p;
}
}
