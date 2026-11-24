#include "recovered/recovery_b158.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b158 {
namespace {
constexpr std::uint32_t kSelectorBase=0x007c0e18u;
constexpr std::uint32_t kArrayPointerBase=0x0083a8acu;
constexpr std::uint32_t kArrayCountBase=0x0083a8b8u;
constexpr std::uint32_t kArrayStride=0x18u;
constexpr std::uint32_t kVtable=0x00785ef8u;
constexpr std::uint32_t kTarget=0x004112f0u;

std::uint32_t invoke_004112f0(Memory& m,std::uint32_t object) {
    // Exact accepted 0x112f0 leaf instructions: EAX=[ECX+0xc]; DEC EAX;
    // [ECX+0xc]=EAX; AL=1; RET. Root consumes only AL, but preserve its
    // full helper return in this translation so the branch behavior is clear.
    const auto value=m.r32(object+0x0cu)-1u;
    m.w32(object+0x0cu,value);
    return (value&0xffffff00u)|1u;
}
}

std::uint32_t fun_0049a450(Memory& m,const Inputs& i) {
    const auto requested=i.arg[0];
    std::uint32_t first=0;
    bool stop_on_next=(requested==0u); // original BL=1 when arg0 is NULL
    for(std::uint32_t bucket=0;bucket<3u;++bucket) {
        const auto selector=m.r32(kSelectorBase+bucket*4u);
        const auto count=m.r32(kArrayCountBase+selector*kArrayStride);
        if(count==0u) continue; // original DEC count makes the signed index negative
        if(count>8u) throw std::domain_error("158 list count outside the bounded 1..8 route");
        const auto vector=m.r32(kArrayPointerBase+selector*kArrayStride);
        for(std::uint32_t remaining=count;remaining>0;--remaining) {
            const auto object=m.r32(vector+(remaining-1u)*4u); // original walks high index to zero
            if(!object) continue;
            const auto vtable=m.r32(object);
            if(vtable!=kVtable || m.r32(vtable+0x60u)!=kTarget)
                throw std::domain_error("158 requires constructor-observed vtable 0x785ef8 and its original slot target");
            const auto helper_eax=invoke_004112f0(m,object);
            if((helper_eax&0xffu)==0u) continue; // exact root tests AL only
            if(!first) first=object;
            if(stop_on_next) return object;
            if(requested==object) stop_on_next=true;
        }
    }
    return first;
}
}
