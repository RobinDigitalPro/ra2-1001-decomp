#include "recovery_b1345.hpp"
#include <stdexcept>
namespace ra2::recovered::global_b26 {
std::uint32_t fun_004a4a30(Memory&, const Inputs&);
}
namespace ra2::recovered::b1345 {
namespace {
using U=std::uint32_t;
constexpr U kEpoch=0x00a2896cu;
constexpr U kVtable=0x0078612cu;
constexpr U kTimerPredicate=0x0041b390u;
constexpr U kTimerRemaining=0x000a4a30u;
void need(bool ok,const char* text){if(!ok)throw std::domain_error(text);}
U active_predicate_41b390(Memory& m,U actor){
    const U start=m.r32(actor+0x154u), amount=m.r32(actor+0x15cu);
    U eax=amount;
    if(start!=0xffffffffu){
        const U elapsed=m.r32(kEpoch)-start;
        eax=ra2::recovered::global_b26::s32(elapsed)>=ra2::recovered::global_b26::s32(amount)
            ?0u:amount-elapsed;
    }
    return eax>0u?1u:0u;
}
bool expired_secondary(Memory& m,U actor){
    const U start=m.r32(actor+0x160u),amount=m.r32(actor+0x168u);
    if(start==0xffffffffu)return amount==0u;
    return ra2::recovered::global_b26::s32(m.r32(kEpoch)-start)>=
           ra2::recovered::global_b26::s32(amount);
}
}
U fun_006cdd90(Memory& m,const Inputs& i){
    const U actor=i.cx;
    need(actor!=0u,"B1345 finite route requires a mapped actor");
    const U vtable=m.r32(actor);
    need(vtable==kVtable,"B1345 finite route requires the original actor vtable");
    need(m.r32(vtable+0x32cu)==kTimerPredicate,
         "B1345 finite route requires original vtable slot 0x32C -> 0x41B390");
    need(active_predicate_41b390(m,actor)==1u,
         "B1345 finite route requires the original active-timer predicate to pass");
    const U phase=m.r32(actor+0x16cu);
    if(phase==5u){
        need(expired_secondary(m,actor),"B1345 phase-5 route requires the secondary timer to have expired");
        Inputs child{};child.cx=actor+0x154u;
        const U remaining=ra2::recovered::global_b26::fun_004a4a30(m,child);
        need(remaining<54u,"B1345 phase-5 route requires the actual remaining timer below 54");
        m.w32(actor+0x16cu,6u);
        return remaining;
    }
    if(phase==9u){
        const U duration=m.r32(actor+0x168u);
        need(duration>=1u&&duration<=63u&&expired_secondary(m,actor),
             "B1345 phase-9 route requires the selected expired positive secondary timer");
        m.w32(actor+0x16cu,10u);
        return duration;
    }
    throw std::domain_error("B1345 finite route models only actor phases 5 and 9");
}
}