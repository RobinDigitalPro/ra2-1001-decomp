#include "recovered/recovery_b1628.hpp"
#include <array>
#include "platform/observed_ticks1628.hpp"
#include <stdexcept>
namespace ra2::recovered::b1628 {
namespace {
void need(bool v){if(!v)throw std::domain_error("1628 finite positive single-cell loaded-Type domain");}
constexpr U map=0x81a820u;
void iterator_begin(Memory&m){const U width=m.r32(map+0xf0u);m.w32(map+0x108u,1);m.w32(map+0x10cu,width);m.w32(map+0x110u,width-1u);m.w32(map+0x114u,(width<<11u)+m.r32(map+0x138u)+4u);}
// Exact integer semantics of accepted557280; no old fixture/guard changed.
U iterator_next(Memory&m){const U count=m.r32(map+0x110u),old=m.r32(map+0x114u);if(count){m.w32(map+0x108u,m.r32(map+0x108u)+1u);m.w32(map+0x10cu,m.r32(map+0x10cu)-1u);m.w32(map+0x110u,count-1u);m.w32(map+0x114u,old-0x7fcu);}else{U end=m.r32(map+0x10cu),begin=m.r32(map+0x108u),row=m.r32(map+0xf0u);m.w32(map+0x108u,end);m.w32(map+0x10cu,begin);const U parity=end-row+begin-1u;if(parity&1u){++begin;--row;m.w32(map+0x10cu,begin);}else{++end;row-=2u;m.w32(map+0x108u,end);}m.w32(map+0x110u,row);m.w32(map+0x114u,m.r32(map+0x138u)+(((m.r32(map+0x10cu)<<9u)+m.r32(map+0x108u))<<2u));}return m.r32(old);}
U idle_pump(Memory&m){need(m.r32(0x8197acu)==0u&&m.r32(0x819778u)==0u); //406EA0/406EB3->406F1D: no writes/QPC.
const U mode=m.r32(0xa255c8u);need(mode==1u&&(m.r8(0xa27decu)&1u)==0u);return mode;}
void guards(Memory&m,const Inputs&i){need((i.cx&255u)==0u&&m.r32(map+0xf0u)==1u&&m.r32(map+0x13cu)==8192u&&m.r32(0xa28920u)==1u);const U table=m.r32(map+0x138u),registry=m.r32(0xa28914u),actor=m.r32(table+0x804u),type=m.r32(registry),cache=m.r32(type+0xa4u);std::array<std::array<U,2>,5>ext{{{table,32768u},{registry,4u},{actor,0x150u},{type,0x2dcu},{cache,72u}}};for(U k=0;k<ext.size();++k){const auto lo=std::uint64_t(ext[k][0]),end=lo+ext[k][1];need(lo>=0x10000000u&&end<=0x70000000u);(void)m.r8(ext[k][0]);(void)m.r8(U(end-1u));for(U j=0;j<k;++j)need(end<=ext[j][0]||std::uint64_t(ext[j][0])+ext[j][1]<=lo);}need(m.r32(actor)==0x788b04u&&m.r32(actor+0x38u)==0u&&m.r32(type)==0x790188u&&m.r32(type+0x264u)==0u&&m.r32(type+0x2c0u)==1u&&m.r32(type+0x2d8u)==0u&&m.r32(type+0x28cu)==0u&&m.r8(type+0x2c4u)==1u);bool ended=false;for(U k=0;k<14u;++k){const U c=m.r8(type+0x2c5u+k);if(!c){need(k>0);ended=true;break;}}need(ended);for(U k=0;k<8192u;++k)need(m.r32(table+4u*k)==(k==513u?actor:0u));need(m.r32(0x819778u)==0u&&m.r32(0x8197acu)==0u&&m.r32(0xa255c8u)==1u&&(m.r8(0xa27decu)&1u)==0u);}
}
U fun_00529540(Memory&m,const Inputs&i){guards(m,i);(void)(ra2::platform::ticks1628::Trace::get()>>4u); // Initial timestamp is replaced before its next use.
iterator_begin(m);for(U actor=iterator_next(m);actor;actor=iterator_next(m)){const U index=m.r32(actor+0x38u);need(index<m.r32(0xa28920u));U type=m.r32(m.r32(0xa28914u)+index*4u);const U variants=m.r32(type+0x2c0u);need(variants==1u);U selected=0u; //52958F; JLE529621 excludes virtual getter and class reassignment.
if(selected>variants-1u)selected%=variants;while(selected){--selected;type=m.r32(type+0x28cu);need(type!=0u);}m.w32(type+0x2d8u,m.r32(type+0x2d8u)+1u);}
U start=ra2::platform::ticks1628::Trace::get()>>4u;U budget=1u;const U count=m.r32(0xa28920u);U loaded=0,total=0;
for(U index=0;index<count;++index){U remaining=budget;const U now=ra2::platform::ticks1628::Trace::get()>>4u;const U elapsed=now-start;if(global_b26::s32(elapsed)>=global_b26::s32(remaining)){(void)idle_pump(m);start=ra2::platform::ticks1628::Trace::get()>>4u;budget=4u;}else{remaining-=elapsed;need(remaining!=0u);}
for(U type=m.r32(m.r32(0xa28914u)+4u*index);type;type=m.r32(type+0x28cu)){if(!m.r8(type+0x2c4u))continue;U length=0;while(m.r8(type+0x2c5u+length))++length;if(!length)continue;need(m.r32(type+0x2d8u)!=0u&&m.r32(type+0xa4u)!=0u); //529724/529768 skip both unload and load.
}}
(void)loaded; //4068F0 is authentic bare RET, so its three outgoing logwords have no side effects.
return total/1024u; //EBP=0, no loading path: full EAX0; all16 inputs and FP untouched.
}
}
