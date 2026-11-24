#include "recovery_b1386.hpp"
#include <stdexcept>
namespace ra2::recovered::b1386 {
namespace {
using U=std::uint32_t;using global_b26::s32;using global_b26::sx16;
void need(bool b,const char* why){if(!b)throw std::domain_error(why);}
// Model of only the private fields actually initialized/read by this path.
// This is not an original class/layout declaration or an allocator substitute.
struct PrivateVector {U vptr,pointer,capacity;std::uint8_t valid,owns;};
PrivateVector empty_0042d4a0(){return {0x7875e0u,0u,0u,1u,0u};}
U count_00428ac0(Memory& m){return (m.r32(0x81a914u)+4u)*m.r32(0x81a910u)*2u;}
U lookup_00545500(Memory& m,U packed){
    const U index=(sx16(packed>>16)<<9)+sx16(packed&0xffffu);
    need(s32(index)>=0&&index<0x40000u,"B1386 actual bounded map index");
    const U cell=m.r32(m.r32(0x81a958u)+4u*index);
    need(cell!=0u&&m.r32(cell)==0x788b04u&&m.r32(cell+0x24u)==packed,"B1386 populated real cell");
    return cell;
}
}
U fun_00706170(Memory& m,const Inputs& i){
    //42D4A0 receives two actual zero arguments and produces the null pointer;
    // its allocator arm and caller-argument rewrite are never reached.
    auto local=empty_0042d4a0();local.vptr=0x7875a0u;
    const U local_count=0u,local_growth=0x1388u;(void)local_growth;
    const U self=i.cx,heap=m.r32(self+0x9cu),old_count=m.r32(heap);
    need(old_count>=1u&&old_count<=7u&&m.r32(heap+4u)==200u,"B1386 nonempty constructor-consistent heap");
    need(m.r32(self+0x98u)==old_count&&m.r32(self+0xecu)>0u,"B1386 positive pending counters");
    need(m.r32(self+0xe0u)==0x140014u&&m.r32(0x81a910u)==20u&&m.r32(0x81a914u)==20u,"B1386 bounded20x20 rebuild center");
    m.w32(self+0x98u,0u);m.w32(self+0xecu,0u);
    U slot=0u;
    do {
        m.w32(m.r32(heap+8u)+4u*slot,0u);++slot;
    } while(s32(slot)<=s32(m.r32(heap)));
    m.w32(heap,0u);
    U remaining=count_00428ac0(m);
    while(remaining!=0u)m.w8(m.r32(self+0xb0u)+--remaining,0u);
    // Both WORDs of the original T+18 coordinate and then T+20 DWORD are
    // fully produced. No private padding or root caller word is observed.
    for(int dy=-2;dy<=2;++dy){
        for(int dx=-2;dx<=2;++dx){
            const U x=std::uint16_t(m.r16(self+0xe0u)+dx),y=std::uint16_t(m.r16(self+0xe2u)+dy);
            const U cell=lookup_00545500(m,x|(y<<16));
            need(m.r32(cell+0x44u)==0xffffffffu,"B1386 original constructor absent-cell field");
        }
    }
    need(local_count==0u&&local.pointer==0u&&local.owns==0u,"B1386 actual initialized empty private vector");
    local.vptr=0x7875e0u; // Destructor store remains private at T+28.
    return local.pointer; //706629 loads complete EAX from initialized T+2C.
}
}
