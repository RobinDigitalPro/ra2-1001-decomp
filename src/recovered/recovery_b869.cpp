#include "recovered/recovery_b869.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b869 {
namespace {using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
U list(platform::ordinary_heap::Heap&h,U count,U stride){const U p=h.allocate(count*stride+8);need(p,"869 successful list allocation");h.w32(p,p+8);for(U k=0;k<count;++k)h.w32(p+8+k*stride,k+1<count?p+8+(k+1)*stride:0);return p;}
void timer(Memory&m,U p,U extent,U rate){need(m.r32(p+4)==0,"869 zero currenttimer prestate");const U endpoint=extent<<16;m.w32(p,3);m.w32(p+4,endpoint);m.w32(p+8,endpoint);m.w32(p+12,(rate<<16)/1000);m.w32(p+16,1000);for(U off:{20u,24u,28u})m.w32(p+off,0);}
}
std::uint32_t fun_00403eb0(Memory&m,const Inputs&i,platform::ordinary_heap::Heap&h){
 need(i.cx&&i.dx&&m.r32(0x819898)==0,"869 positive startup and nulltimer callback");
 for(U p:{0x8191e0u,0x8192b0u})for(U off:{0u,4u,8u})m.w32(p+off,p);
 m.w32(0x8192ec,i.dx);m.w32(0x8192f4,i.cx);
 timer(m,0x819218,0x4000,0x4000);timer(m,0x819240,100,10);timer(m,0x819268,0x2000,0x4000);
 m.w32(0x8192e8,0);m.w32(0x8192e4,0);m.w32(0x8192f8,1);m.w32(0x7b7b68,1);
 const auto owner=h.allocate(232);need(owner,"869 successfulowner allocation");for(U off=0;off<232;off+=4)h.w32(owner+off,0);h.w32(owner,m.r32(0x8192ec));h.w32(owner+24,8192);
 h.w32(owner+4,list(h,0x100000/(8192+28),8192+36));h.w32(owner+8,list(h,200,108));for(U off:{12u,16u,20u})h.w32(owner+off,owner+12);m.w32(0x8192f0,owner);
 m.w32(0x819300,list(h,100,648));m.w32(0x8192fc,1);return 1;
}
}
