#include "recovered/recovery_b1461.hpp"
#include <stdexcept>
namespace ra2::recovered::b1461 {
namespace {
using U=std::uint32_t;
void need(bool v,const char*s){if(!v)throw std::domain_error(s);}
// Exact reached nonnull operations of75A0E0/75A030/5BD730/7593B0.
// B1162's B0E890 and17..79-byte root guards are not imported or extended.
U length(Heap&h,U p){need(p!=0,"1461 real nonnull string owner");U n=0;while(h.r8(p+n)){need(n<3,"1461 three-byte managed key");++n;}need(n==3,"1461 nonempty exact three-byte key");return n;}
U hash(Heap&h,U p){U sum=length(h,p);for(U k=0;k<length(h,p);++k){const auto byte=static_cast<std::int8_t>(h.r8(p+k));sum+=static_cast<U>(static_cast<std::int32_t>(byte))+k;sum=(sum<<8)^(sum>>24);}return sum;}
bool equal(Heap&h,U a,U b){for(U k=0;k<4;++k){const U x=h.r8(a+k),y=h.r8(b+k);if(x!=y)return false;if(x==0)return true;}throw std::domain_error("1461 managed strings lack bounded NUL");}
}
std::uint32_t configure_crt(Memory&m,const Inputs&i){need(i.arg[0]==0,"1461 actual CRTsetter argument");m.w32(0x817554,0);return 1;}
std::uint32_t fun_007440d0(Memory&m,const Inputs&,Heap&h){
 const U count=m.r32(0xb0ed2c),query=m.r32(0xb0f1b4);
 need(count>=2&&count<=3&&m.r32(0xb0ed30)==128&&m.r32(0xb0ed34)==7&&m.r32(0xb0ed38)==0&&m.r8(0xb0ed3c)==0&&m.r32(0xb0ed40)==0x5bd730&&m.r32(0xb0ed58)==128,"1461 actual registered scalar-map header");
 need(m.r32(0xb0ed48)==0x9999999a&&m.r32(0xb0ed4c)==0x3fc99999&&m.r32(0xb0ed50)==0x9999999a&&m.r32(0xb0ed54)==0x3fe99999,"1461 actual map threshold words");
 length(h,query);const U index=hash(h,query)&((1u<<m.r32(0xb0ed34))-1u);U node=h.r32(m.r32(0xb0ed28)+4*index);
 for(U visited=0;visited<count&&node;++visited){const U key=h.r32(node);length(h,key);if(equal(h,key,query)){const U type=h.r32(node+4);need(type<=4,"1461 excludes second-map type5 route");return type==4?1u:0u;}node=h.r32(node+8);}
 throw std::domain_error("1461 requires a genuine matched nonempty collision chain");
}
}
