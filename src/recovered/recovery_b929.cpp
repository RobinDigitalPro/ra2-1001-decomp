#include "recovered/recovery_b929.hpp"
#include "recovered/recovery_b929_constants.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovery_b929 {
namespace {
using U=std::uint32_t;
bool equal_original_string(Memory&m,U left,U right) {
    // Reproduce the original pairwise ANSI-byte comparisons, including its
    // low-byte-first NUL decision. The pinned literals are byte strings with
    // ordinary single-byte characters and terminating NUL bytes.
    for(U n=0;n<128u;++n) {
        const U ll=m.r8(left),rl=m.r8(right);
        if(ll!=rl)return false;
        if(!ll)return true;
        const U lh=m.r8(left+1u),rh=m.r8(right+1u);
        if(lh!=rh)return false;
        left+=2u;right+=2u;
        if(!lh)return true;
    }
    throw std::domain_error("B929 fixed-string compare exceeded 128 two-byte iterations");
}
void set_mapping(Memory&m,U literal,U output) {
    const U fallback=m.r32(recovery_b929_cases::table_fallback);
    U value=fallback;
    for(U index=0;index<recovery_b929_cases::table_count;++index) {
        const U candidate=m.r32(recovery_b929_cases::table_begin+4u*index);
        if(equal_original_string(m,candidate,literal)){value=index;break;}
    }
    m.w32(output,value);
}
}

U fun_00295d30(Memory&m,MixedHeap&heap,TickClock&clock,EntryState&entry) {
    const U self=entry.ecx;
    // Reuse the accepted 0x271080 composition and its real small/ordinary
    // mixed-heap requests plus three observed timeGetTime calls.
    ra2::recovery_b319::fun_00671080(m,heap,clock,entry);

    // Exact 0x4942F0 child initializer at self+0x4eec.
    m.w32(self+0x4ee8u,0x00785e44u);
    const U child=self+0x4eecu;
    m.w32(child,0);m.w32(child+4u,0);
    m.w8(child+8u,0);m.w8(child+9u,0);m.w8(child+10u,0);m.w32(child+12u,0);

    const U clock_value=m.r32(recovery_b929_cases::clock_global);
    m.w32(self+0x4efcu,clock_value);m.w32(self+0x4f04u,0);
    m.w32(self+0x4f10u,0);m.w32(self+0x4f08u,clock_value);
    m.w32(self+0x4ee8u,0x007914c4u);
    m.w8(self+0x4f14u,1);m.w8(self+0x4f15u,1);m.w8(self+0x4f16u,1);
    m.w32(self,0x007914ccu);

    for(unsigned k=0;k<recovery_b929_cases::lookup_literals.size();++k)
        set_mapping(m,recovery_b929_cases::lookup_literals[k],recovery_b929_cases::output_globals[k]);

    // Original 0x60B9E0 helper stores its ECX receiver to the single global.
    m.w32(recovery_b929_cases::published_child,self+0x4ee8u);
    entry.eax=self;
    return self;
}
}
