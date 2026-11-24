#include "recovered/recovery_b1574.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1574 {
namespace {
using U=std::uint32_t;
void need(bool ok){if(!ok)throw std::domain_error("B1574 selected mission10 public projection");}
// Selected ordinary queue branch: the zero flag skips optional callbacks.
void queue(Memory&m,U self,U request,U flag){need(request==10&&flag==0&&m.r32(self+0x98)==0&&m.r32(self+0xa0)==0xffffffffu);m.w32(self+0xa0,request);m.w8(self+0xa4,flag);}
void activate(Memory&m,U self,U frame){const U request=m.r32(self+0xa0);need(request==10);m.w32(self+0x98,request);m.w32(self+0xa0,0xffffffffu);m.w32(self+0xa8,0);m.w32(self+0xb0,frame);
// This derived mission call-site value is ordinary game-object B4 data.
// It is never stored through an execution-stack pointer or used as a live address.
m.w32(self+0xb4,0x004c5788u);m.w32(self+0xb8,0);m.w32(self+0xac,frame);m.w8(self+0xa4,0);}
U random_range(Memory&m,U generator,U lo,U hi){need(lo==1&&hi==10&&m.r8(generator)==0);const U span=hi-lo;U bit=31;while(bit>0&&!(span&(1u<<bit)))--bit;const U mask=bit==31?0xffffffffu:((1u<<(bit+1))-1u);U draw;
do{const U first=m.r32(generator+4),second=m.r32(generator+8);need(first<250&&second<250);const U raw=m.r32(generator+12+4*first)^m.r32(generator+12+4*second);m.w32(generator+12+4*first,raw);m.w32(generator+4,first+1<250?first+1:0);m.w32(generator+8,second+1<250?second+1:0);draw=raw&mask;}while(draw>span);return lo+draw;}
}
std::uint32_t run(Memory&m,const Inputs&i){const U self=i.cx;need(m.r32(self)==0x798c88u);need(m.r32(0x798cb4u)==0x6fee90u&&m.r32(0x798e58u)==0x591ab0u&&m.r32(0x798e5cu)==0x591a50u);const U owner=m.r32(self+0x1b4),type=m.r32(self+0x5ac);need(owner!=0&&type!=0);need(m.r8(owner+0x134)==0&&m.r8(owner+0x135)==0&&m.r32(0xa255c8u)==0);need(m.r32(self+0x4ac)==0&&m.r32(self+0x1b0)==0&&m.r8(type+0xba6)==1);need(m.r32(self+0x98)==0&&m.r32(self+0xa0)==0xffffffffu);
// The genuine selected Unit kind leaf returns1; this projection takes mission10.
queue(m,self,10,0);activate(m,self,m.r32(0xa2896cu));const U scenario=m.r32(0xa255c0u);need(scenario!=0);return random_range(m,scenario+0x218,1,10)+1u;
}
}
