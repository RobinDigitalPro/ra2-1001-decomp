#include "recovered/recovery_b1439.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include <stdexcept>
namespace ra2::recovered::b1439 {
namespace {void need(bool b,const char* why){if(!b)throw std::domain_error(why);}}
std::uint32_t fun_004fd4d0(Memory&m,const Inputs&i){
 using namespace numeric_b88::detail;
 const auto self=i.cx,owner=m.r32(self+0xcu);
 need(m.r32(self)==0x78e2b4u&&m.r32(self+4u)==0x78e1ecu&&m.r32(0x78e1fcu)==0x4fbd80u,"1439 actual component slot10");
 need(m.r32(self+8u)==owner&&m.r32(owner+0x564u)==self+4u,"1439 configured owner/component relationship");
 // Actual4FBD80 tests the two XYZ triples against originalA28CC0 sentinel.
 bool active=false;for(unsigned k=0;k<6u;++k)active|=m.r32(self+0x18u+4u*k)!=m.r32(0xa28cc0u+4u*(k%3u));
 need(active&&m.r32(owner+0x4d0u)!=0xffffffffu,"1439 configured destination and nonempty direction path");
 const auto target=m.r32(owner+0x494u);
 need(target&&m.r32(target)==0x798c88u&&m.r32(0x798cb4u)==0x6fee90u,"1439 genuine target type1 provider");
 need(m.r32(owner)==0x798c88u&&m.r32(0x798cd0u)==0x5cd4d0u,"1439 genuine owner coordinate-copy provider");
 const auto dx=m.r32(owner+0x88u)-m.r32(self+0x18u),dy=m.r32(owner+0x8cu)-m.r32(self+0x1cu),dz=m.r32(owner+0x90u)-m.r32(self+0x20u);
 need(dx>=256u&&dx<=23u*256u&&!(dx&255u)&&dy==0u&&dz==0u,"1439 finite nonzero axial distance");
 auto&f=i.fp;need(f.image.word(8)==0xffffu,"1439 empty numeric entry");
 f.load_integer32(dz);f.load_integer32(dy);f.load_integer32(dx);
 reg<0xd9c0>(f);reg<0xd8c9>(f);reg<0xd9c2>(f);reg<0xd8cb>(f);reg<0xdec1>(f);
 reg<0xd9c3>(f);reg<0xd8cc>(f);reg<0xdec1>(f);
 const auto squared=f.pop64();f.pop_st0();f.pop_st0();f.pop_st0();
 root(m,f,squared);const auto distance=integer(m,f),cell=div256(distance);
 need(cell<24u,"1439 original positive distance route");
 m.w32(owner+0x4d0u+4u*cell,0xffffffffu);
 return (cell&0xffffff00u)|1u;
}
}
