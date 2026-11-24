#include "recovered/recovery_b1504.hpp"
#include "platform/observed_qpc1504.hpp"
#include "recovered/special_b63.hpp"
#include <stdexcept>
namespace ra2::recovered::b1504 {namespace {
void need(bool x,const char*s){if(!x)throw std::domain_error(s);}
Q current_time(Memory&m){
 need(m.r32(0x819898)==0x4092e0&&m.r32(0x7851c8)==platform::qpc1504::Six::address(),"1504 actual initialized4092D0/QPC observer");
 LARGE_INTEGER value{};need(platform::qpc1504::Six::counter(&value)!=0&&value.QuadPart>0,"1504 actual successful QPC");const Q d=floating_b61::read64(m,0x819878);need(d>0&&(d>>63)==0,"1504 real QPF/1000 divisor");
 special_b63::Inputs in{};in.arg[0]=U(value.QuadPart);in.arg[1]=U(Q(value.QuadPart)>>32);in.arg[2]=U(d);in.arg[3]=U(d>>32);return special_b63::fun_0076de10(m,in);
}
void control(Memory&m,Heap&h,U p,U value){
 h.w32(p,0);const Q now=current_time(m);h.w32(p+0x18,U(now));h.w32(p+0x1c,U(now>>32));h.w32(p,1);h.w32(p+8,value<<16);h.w32(p+0xc,0x10624d);h.w32(p+0x10,1000);h.w32(p+0x14,0);
 // Actual70F0: nonzero target minus initiallyzero current, bit0 alreadyset.
 need(value!=0&&h.r32(p+4)==0,"1504 constructor immediate fastleg");h.w32(p+4,h.r32(p+8));h.w32(p,h.r32(p)|2);
}
void gains(Memory&m,Heap&h,U p){
 control(m,h,p,0x4000);control(m,h,p+0x28,100);control(m,h,p+0x50,0x2000);
 // Actual70D0 unsigned division, duration1000/highword0; final7080 retains4000.
 h.w32(p+0x28+0xc,(10u<<16)/1000);h.w32(p+0xc,(0x4000u<<16)/1000);h.w32(p+0x50+0xc,(0x4000u<<16)/1000);h.w32(p,h.r32(p)|1);h.w32(p+8,0x40000000);
}
U callback_40a180(Memory&m,Heap&h,U owner,U device){
 const U nested=h.allocate(224);need(nested!=0,"1504 actual224 allocation");for(U k=0;k<224;k+=4)h.w32(nested+k,0);h.w32(owner+0x158,nested);h.w32(nested,owner);h.w32(owner+0x1a8,0x108);h.w32(owner+0x1b0,0x420);
 // Original402800 compares all8 formatDWORDs, equalbranch leaves19C=0.
 for(U k=0;k<8;++k)need(h.r32(owner+0x17c+4*k)==m.r32(device+0x44+4*k),"1504 actual copied format equalbranch");h.w32(owner+0x19c,0);return 0;
}
}
U fun_00402040(Memory&m,const Inputs&i,Heap&h){
 const U device=i.cx;need(m.r32(device+0x1d0)==0x7b7d80&&m.r32(0x7b7d84)==0x40a180,"1504 genuine configureddevice channel table+4");constexpr U format[]{4,0,22050,2,2,88200,0,0};for(U k=0;k<8;++k)need(m.r32(device+0x44+4*k)==format[k],"1504 original22050Hz32B format projection");need(m.r32(0x818e90)==0x818e08,"1504 actual manager+20 ringpublication");
 const U owner=h.allocate(448);need(owner!=0,"1504 actual448 allocation");for(U k=0;k<448;k+=4)h.w32(owner+k,0);
 // Actual407200 produces TWO selflinks. They are rawpointerbytes, neverzeroed.
 h.w32(owner,owner);h.w32(owner+4,owner);h.w32(owner+8,0);gains(m,h,owner+0xd8);
 h.w32(owner+0x15c,0x4022c0);h.w32(owner+0x160,0x402330);h.w32(owner+0x164,0x4023f0);h.w32(owner+0xc,1);h.w32(owner+0x94,m.r32(0x818e90));gains(m,h,owner+0x10);
 h.w32(owner+0xac,device);h.w32(owner+0xd4,m.r32(device+0x1d0));for(U k=0;k<8;++k)h.w32(owner+0x17c+4*k,m.r32(device+0x44+4*k));
 need(callback_40a180(m,h,owner,device)==0,"1504 genuine callback success fullEAX0");return owner;
}
}
