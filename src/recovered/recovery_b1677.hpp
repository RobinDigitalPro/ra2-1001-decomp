#pragma once
#include "recovered/recovery_b1676_profile.hpp"
#include <array>
namespace ra2::recovered::b1677 {
using U=std::uint32_t;using Memory=ra2::recovered::profile1676::Memory;using Inputs=ra2::recovered::profile1676::Inputs;
inline void need(bool value,const char*why){if(!value)throw std::domain_error(why);}
inline U count(Memory&m){const U p=m.r32(0xa285c8+0x48);need(p!=0,"real primary provider");const U q=m.r32(p+4);need(q!=0,"real constructor-produced queue");return m.r32(q+0x1c);}
inline U settings(Memory&m,U a,U b,U c){const U p=m.r32(0xa285c8+0x48);need(p!=0,"settings real provider");m.w32(p+0x28,a);m.w32(p+0x2c,b);m.w32(p+0x30,c);return p;}
inline U configure(Memory&m,U a,U b,U c){constexpr U self=0xa285c8;need(m.r32(self)==0x78f6d4&&m.r32(0x78f70c)==0x524210,"authentic normal manager and exact slot38 leaf");need(m.r32(self+0x44)==0&&m.r32(self+0x50)==0,"factory empty side array and no auxiliary provider");m.w32(self+0x58,a);m.w32(self+0x5c,b);m.w32(self+0x60,c);(void)settings(m,a,b,c);return 0;}

template<class Heap,class Api,class Clock>
inline U fun_0073f1c0(Memory&m,const Inputs&in,Heap&heap,Api&api,Clock&clock,U entry_s,ra2::recovered::profile1676::Observation&observed){
 constexpr U self=0xa285c8;
 need(m.r8(self+4)==0&&m.r8(self+5)==0,"finite offline manager with genuine providers");
 need(m.r32(0xb0fc00)==0,"actual73F170 empty registry route; no fabricated callback");
 need(m.r8(0xa25e48)==0&&m.r32(0xa25e44)==40,"actual file caller inputs");
 (void)configure(m,50,~0u,5000);
 // Empty73F170 returns EAX0 and preserves ECX=A285C8. MOV CL,0
 // therefore supplies the real unused child arg1=A28500, not zero.
 Inputs child=in;child.cx=0xa25c20;child.dx=40;child.arg[0]=0xa25e22;child.arg[1]=0xa28500;child.arg[2]=1;
 const U valid=ra2::recovered::profile1676::fun_00663180(m,child,heap,api,entry_s-0x21c,observed);
 need((valid&255)==1,"real nonempty valid profile path");
 // The offline send/count guards return before dispatch. The455-byte
 // provider is retained; two genuine winmm timeGetTime calls still occur.
 need(m.r8(self+4)==0&&m.r8(self+5)==0,"actual offline send and drain guards");
 const U first=clock.read()>>4,second=clock.read()>>4;(void)first;(void)second;
 const U session=m.r32(0xa255c0);need(session!=0,"owned session projection");
 for(U k=0;;++k){need(k<10,"finite profile filename");const U ch=m.r8(0xa25c20+k);m.w8(session+0x83c+k,ch);if(!ch)break;}
 U interval=count(m)*8;if(interval<120)interval=120;else interval=count(m)*8;
 return configure(m,count(m)+2,~0u,interval);
}
}
