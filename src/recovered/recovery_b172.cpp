#include "recovered/recovery_b172.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b172 {

namespace {
constexpr std::uint32_t counter2=0x00a5e214u;

// Exact reached path through 0x6eeb60/0x2eeb60: its real fallback branch
// reads [0xab7ec0], writes no optional output (root supplies EDX=0), and
// returns the pinned literal pointer 0x7e2708 when the global is zero.
std::uint32_t fallback_key(Memory& m) {
    if(m.r32(0x00ab7ec0u)!=0u)
        throw std::domain_error("Block172 is limited to the original null-manager fallback branch");
    return 0x007e2708u;
}

// Root calls 0x2ea8d0 with EDX=0x1e0 and ECX=the fallback pointer. The actual
// wrapper sees [0xa1e0e4]==0, supplies EAX=3, then calls 0x1b1980. That body
// calls accepted RVA 0x97830 (VA 0x497830), which returns [0x836d30]. For its zero result and
// nonnull key pointer the reached original 0x1b1980 prefix returns at
// VA 0x5b19c4 before any later allocation, import, or indirect dispatch.
std::uint32_t lookup_through_actual_early_return(Memory& m,std::uint32_t key) {
    if(key==0u) throw std::domain_error("Block172 fallback key must be nonnull");
    if(m.r32(0x00a1e0e4u)!=0u)
        throw std::domain_error("Block172 is limited to the original null-global 0x2ea8d0 branch");
    const std::uint32_t supplied_selector=3u;
    (void)supplied_selector; // MOV EAX,3 at VA 0x6ea8e3; helper ignores ECX.
    const auto actual_global_result=m.r32(0x00836d30u); // reached RVA 0x97830 / VA 0x497830
    if(actual_global_result==0u)
        return 0u; // actual 0x1b1980 early XOR EAX,EAX; RET 0x1c at 0x5b19c4
    throw std::domain_error("Block172 excludes the nonzero 0x1b1980 continuation");
}
}

// Finite useful route of original RVA 0x20eaa0. The root's actual INC [counter2]
// is retained; helper-zero results are derived from the reached original
// branches rather than injected callbacks.
std::uint32_t fun_0060eaa0(Memory& m,const Inputs& i) {
    if((i.dx&0xffu)!=0u || (i.cx&0xffu)!=1u)
        throw std::domain_error("Block172 requires DL=0 and CL=1");
    const auto old_count=m.r32(counter2);
    if(old_count>0x7ffffffeu)
        throw std::domain_error("Block172 counter bounded to avoid signed CMP/INC overflow");

    // Root 0x20eaa0 calls accepted 0x2eeb60 with ECX=0x7d5e24, EDX=0, and
    // stack literals 0x7d5d64/0xc9f. Fallback does not dereference them.
    const auto key=fallback_key(m);
    // Root next calls accepted 0x2ea8d0 with ECX=key, EDX=0x1e0. Its reached
    // 0x1b1980 prefix returns zero from the actual RVA 0x97830 / VA 0x497830 accessor.
    const auto helper_result=lookup_through_actual_early_return(m,key);
    if(helper_result!=0u) throw std::domain_error("Block172 route requires the original zero lookup result");

    // INC dword ptr [ESI*4+0xa5e20c] at VA 0x60eb1b; EAX remains the prior
    // zero returned by 0x2ea8d0 through the root's RET at VA 0x60eb23.
    m.w32(counter2,old_count+1u);
    return 0u;
}

}
