#include "recovery_b1384.hpp"
#include "recovered/floating_b61_b.hpp"
#include "recovered/global_b58_c.hpp"
#include <stdexcept>
namespace ra2::recovered::b1384 {
namespace {
using U=std::uint32_t;using global_b26::s32;using global_b26::sx16;
void need(bool b,const char* why){if(!b)throw std::domain_error(why);}
constexpr U compass[]{0xffff0000u,0xffff0001u,1u,0x10001u,0x10000u,0x1ffffu,0xffffu,0xffffffffu};
U packed_add(U p,U q){return U(std::uint16_t(p+q))|(U(std::uint16_t((p>>16)+(q>>16)))<<16);}
// Actual62FDE0 enabled XOR recurrence, including exact store/read order.
U random_word(Memory& m,U state){
    need(m.r8(state)==0u,"B1384 enabled genuine RNG");
    U p=m.r32(state+4u),q=m.r32(state+8u);
    need(p<250u&&q<250u&&p!=q,"B1384 distinct valid RNG cursors");
    const U destination=state+12u+4u*p;
    m.w32(destination,m.r32(destination)^m.r32(state+12u+4u*q));
    p=m.r32(state+4u);q=m.r32(state+8u);
    const U result=m.r32(state+12u+4u*p);
    ++p;++q;m.w32(state+4u,p);m.w32(state+8u,q);
    if(s32(p)>=250)m.w32(state+4u,0u);
    if(s32(q)>=250)m.w32(state+8u,0u);
    return result;
}
// Actual545500 indexed nonnull branch, with the produced coordinate by value.
U lookup(Memory& m,U packed){
    const U index=(sx16(packed>>16)<<9)+sx16(packed&0xffffu);
    need(s32(index)>=0&&index<0x40000u,"B1384 bounded real Map lookup");
    const U cell=m.r32(m.r32(0x81a958u)+4u*index);
    need(cell!=0u&&m.r32(cell)==0x788b04u&&m.r32(cell+0x24u)==packed,"B1384 authentic populated cell");
    return cell;
}
U index_00428a90(Memory& m,U packed){
    const U x=sx16(packed&0xffffu),y=sx16(packed>>16),width=m.r32(0x81a910u);
    return (x-width+y-1u)*width+global_b26::sar(x-y+width-1u,1u);
}
U count_00428ac0(Memory& m){return (m.r32(0x81a914u)+4u)*m.r32(0x81a910u)*2u;}
U predicate_0047a270(Memory& m,U cell,U incoming_eax){
    need(m.r8(cell+0x11cu)>4u,"B1384 original unsigned classification exit");
    return incoming_eax&0xffffff00u; // Actual47A391 XOR AL,AL.
}
}
U fun_00705770(Memory& m,const Inputs& i){
    const U self=i.cx,heap=m.r32(self+0x9cu);
    need(heap!=0u,"B1384 actual pending heap");
    const U rules=m.r32(0x821b88u),limit=m.r32(rules+0xd4u);
    need(limit==200u&&m.r32(self+0x98u)==1u&&m.r32(self+0xecu)==0u,"B1384 selected original rule bounds");
    const U owner=m.r32(0xa255c0u);
    need(m.r8(owner+0x222bu)==1u,"B1384 active processing owner");
    for(U k=0;k<8u;++k)need(m.r32(0x839da0u+4u*k)==compass[k],"B1384 original491400 compass");
    need(m.r32(0x81a910u)==20u&&m.r32(0x81a914u)==20u&&m.r32(0x81a918u)==0u&&m.r32(0x81a91cu)==0u&&m.r32(0x81a920u)==20u&&m.r32(0x81a924u)==20u,"B1384 exact Map geometry");
    const U count=m.r32(heap),slots=m.r32(heap+8u),record=m.r32(slots+4u);
    need(count==1u&&m.r32(heap+4u)==limit&&record==m.r32(self+0xa0u)&&record!=0u&&m.r32(record)==0x140014u&&m.r32(record+4u)==0u&&m.r32(heap+12u)==record&&m.r32(heap+16u)==record,"B1384 constructor-consistent populated priority heap");
    const U draw=random_word(m,owner+0x218u);
    need(draw>0u&&draw<=0x7ffffffeu,"B1384 positive actual draw");
    const U sign=global_b26::sar(draw,31u),absolute=(draw^sign)-sign;
    const U request=global_b26::idiv_remainder(absolute,5u)+1u;
    // Original first pop: real slot1 is moved onto itself, then cleared.
    m.w32(slots+4u,m.r32(slots+4u*count));
    m.w32(m.r32(heap+8u)+4u*count,0u);m.w32(heap,m.r32(heap)-1u);
    Inputs sift{};sift.cx=heap;sift.ax=count;sift.arg[0]=1u;sift.fp=i.fp;
    (void)floating_b61::fun_0058be90(m,sift);i.fp=sift.fp;
    const U center=lookup(m,m.r32(record));
    need(m.r8(center+0x11eu)==48u&&m.r32(center+0x44u)==126u,"B1384 original center route");
    const U buffer=m.r32(self+0xb0u);
    U index=index_00428a90(m,m.r32(record));
    need(s32(index)>=0&&s32(index)<s32(count_00428ac0(m)),"B1384 valid center marker");
    m.w8(buffer+index,1u);
    for(U direction=0u;direction<8u;direction+=2u){
        const U point=packed_add(m.r32(record),m.r32(0x839da0u+4u*direction));
        const U cell=lookup(m,point);
        // Original fully produces T+14 before557450. The canonical helper
        // only reads this coordinate and never exports its address; matching
        // cell+24 is therefore an equivalent immutable input, no fake stack.
        global_b26::Inputs geometry{};geometry.cx=0x81a820u;geometry.arg[0]=cell+0x24u;geometry.arg[1]=1u;
        need((global_b26::fun_00557450(m,geometry)&255u)!=0u,"B1384 actual geometry membership");
        const U height_delta=global_b26::sx8(m.r8(cell+0x11bu))-global_b26::sx8(m.r8(center+0x11bu));
        const U height_sign=global_b26::sar(height_delta,31u);
        need(s32((height_delta^height_sign)-height_sign)<2,"B1384 actual height gate");
        index=index_00428a90(m,point);const U total=count_00428ac0(m);
        need(s32(index)>=0&&s32(index)<s32(total),"B1384 valid cardinal marker");
        need((predicate_0047a270(m,cell,total)&255u)==0u,"B1384 no enqueue from actual predicate");
        m.w8(m.r32(self+0xb0u)+index,1u);
    }
    const U processed=1u; //705A7A loads produced counter0,705A82 INC EAX.
    if(processed>=request)return processed;
    need(m.r32(m.r32(self+0x9cu))==0u,"B1384 next actual heap read is empty");
    //705A9B/9F zero the localrecord/EBP; no subsequent EAX write.
    return processed;
}
}
