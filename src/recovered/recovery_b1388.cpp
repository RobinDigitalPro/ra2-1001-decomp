#include "recovery_b1388.hpp"
#include "recovered/recovery_b792.hpp"
#include <stdexcept>
namespace ra2::recovered::b1388 {
namespace {
using U=std::uint32_t;using global_b26::s32;
void need(bool ok,const char* message){if(!ok)throw std::domain_error(message);}
// Exact valid-index arm of70B250. The existing B26 adapter uses a different
// Memory type; this typed adapter preserves its actual XOR EAX/SETZ result.
U completed_0070b250(Memory& m,U index){
    const U count=m.r32(0xab83c0u);
    need(s32(index)>=0&&s32(index)<s32(count),"B1388 actual valid completed-record index");
    const U record=m.r32(m.r32(0xab83b4u)+4u*index);
    need(record!=0u,"B1388 nonnull request record");
    return m.r32(record+0x48u)==2u?1u:0u;
}
// Original unindexed79160C providers, never counted as new roots. The
// paused arm does not enter711B80 or invoke an invented codec callback.
U poll_0059e650(Memory& m,U wrapper){
    need(m.r32(wrapper)==0x79160cu&&m.r32(0x791610u)==0x59e650u,"B1388 genuine poll vtable slot");
    const U video=m.r32(wrapper+0x10u);
    need(video!=0u,"B1388 real borrowed video record");
    const U decoder=m.r32(video);
    need(decoder!=0u&&m.r8(decoder+0x548u)==1u,"B1388 actual paused decoder producer state");
    return video&0xffffff00u; //59E68D XOR AL,AL preserves full upperEAX.
}
U done_0059e640(Memory& m,U wrapper,U eax){
    need(m.r32(wrapper)==0x79160cu&&m.r32(0x79161cu)==0x59e640u,"B1388 genuine completion vtable slot");
    return (eax&0xffffff00u)|m.r8(wrapper+0x14u);
}
}
U fun_0062b2c0(Memory& m,const Inputs& i){
    const U self=i.cx;
    need(m.r32(self+0x14b4u)==1u,"B1388 waiting request stage");
    const U ready=completed_0070b250(m,m.r32(self+0x14d0u));
    need(ready==1u,"B1388 producer-completed real request");
    const U queued=m.r32(0xae0a68u);
    need(queued==0u,"B1388 independent video queue is empty");
    m.w32(self+0x14b4u,2u); //62B370 persistent stage publication.
    return queued; //62B362 fullEAX overwritten by the exact queue count.
}
U fun_0062b3b0(Memory& m,const Inputs& i){
    const U self=i.cx,queued=m.r32(0xae0a68u);
    need(queued==1u&&m.r8(self+0x14b9u)==1u&&m.r8(self+0x14d6u)==0u,"B1388 existing queued event without new-event or drawing arm");
    need(m.r8(self+0x14b8u)==1u&&m.r8(self+0x14d5u)==1u,"B1388 prior blocking and pending publication");
    const U wrapper=m.r32(m.r32(0xae0a5cu));
    need(wrapper!=0u,"B1388 nonnull queued wrapper");
    U eax=poll_0059e650(m,wrapper);
    need((eax&0xffu)==0u,"B1388 paused poll does not draw");
    eax=done_0059e640(m,wrapper,eax);
    const U done=eax&0xffu,blocking=m.r8(wrapper+4u);
    need(done==0u&&blocking==0u,"B1388 unfinished nonblocking event remains queued");
    const U owner=m.r32(0xa255c0u),old_count=m.r32(owner+0x62cu);
    need(owner!=0u&&old_count>=2u&&old_count<=8u,"B1388 positive nested pause count");
    m.w8(self+0x14d5u,0u);
    m.w8(self+0x14b9u,std::uint8_t(done==0u));
    //62B694 calls the unchanged accepted653380 implementation. Its selected
    // decrement leaves count>=1, therefore no resume/timer/provider calls.
    Inputs child=i;child.ax=eax;child.cx=(wrapper&0xffffff00u)|1u;
    eax=recovery_b792::fun_00653380(m,child);
    i.fp=child.fp;
    m.w8(self+0x14b8u,0u);
    return eax; //65339B owner pointer, not a Boolean or low-byte mask.
}
}
