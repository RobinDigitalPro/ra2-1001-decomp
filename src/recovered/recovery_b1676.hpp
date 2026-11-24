#pragma once
#include "recovered/recovery_b1676_profile.hpp"
#include <array>
namespace ra2::recovered::b1676 {
using U=std::uint32_t;using Memory=ra2::recovered::profile1676::Memory;using Inputs=ra2::recovered::profile1676::Inputs;
inline void need(bool value,const char*why){if(!value)throw std::domain_error(why);}
inline U count(Memory&m){const U p=m.r32(0xa285c8+0x48);need(p!=0,"real primary provider");const U q=m.r32(p+4);need(q!=0,"real constructor-produced queue");return m.r32(q+0x1c);}
inline U settings(Memory&m,U a,U b,U c){const U p=m.r32(0xa285c8+0x48);need(p!=0,"settings real provider");m.w32(p+0x28,a);m.w32(p+0x2c,b);m.w32(p+0x30,c);return p;}
inline U configure(Memory&m,U a,U b,U c){constexpr U self=0xa285c8;need(m.r32(self)==0x78f6d4&&m.r32(0x78f70c)==0x524210,"authentic normal manager and exact slot38 leaf");need(m.r32(self+0x44)==0&&m.r32(self+0x50)==0,"factory empty side array and no auxiliary provider");m.w32(self+0x58,a);m.w32(self+0x5c,b);m.w32(self+0x60,c);(void)settings(m,a,b,c);return 0;}
template<class Heap,class Api>
inline U fun_005b9740(Memory&m,const Inputs&in,Heap&heap,Api&api,U entry_s,ra2::recovered::profile1676::Observation&observed){
 constexpr U self=0xa285c8;
 need(m.r8(self+4)==0&&m.r8(self+5)==0,"finite offline manager input, not missing provider");
 need(m.r8(0xa25e48)==0&&m.r32(0xa25e44)==40,"actual caller scalar file parameters");
 U first=count(m)+2;if(first<=30)first=30;else first=count(m)+2;
 const U configured=configure(m,first,~0u,1000);
 Inputs child=in;child.cx=0xa25c20;child.dx=m.r32(0xa25e44);child.arg[0]=0xa25e22;child.arg[1]=(configured&0xffffff00u)|m.r8(0xa25e48);child.arg[2]=1;
 const U result=ra2::recovered::profile1676::fun_00663180(m,child,heap,api,entry_s-0x1e4,observed);
 need((result&255)==1,"finite valid existing profile route");
 std::array<unsigned char,455> packet{};packet[0]=13;
 // Original524560 and524CE0 each test the two offline bytes before provider
 // dispatch/count reads. The actual455-byte provider and all queues stay live.
 need(m.r8(self+4)==0&&m.r8(self+5)==0,"actual offline send/count guards");
 const U session=m.r32(0xa255c0);need(session!=0,"owned session filename projection");
 U k=0;for(;;++k){need(k<10,"finite9-character profile name");const U ch=m.r8(0xa25c20+k);m.w8(session+0x83c+k,ch);if(ch==0)break;}
 U slots=count(m);if(static_cast<std::int32_t>(slots)<20)slots=20;
 U interval=slots*8;if(static_cast<std::int32_t>(interval)<120)interval=120;
 (void)configure(m,slots,~0u,interval);
 const U provider=settings(m,60,~0u,600);
 return(provider&0xffffff00u)|1u;
}
}
