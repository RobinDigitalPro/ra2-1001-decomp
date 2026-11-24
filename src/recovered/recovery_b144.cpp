#include "recovered/recovery_b144.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b144 {
namespace {
constexpr std::uint32_t kRows=18;
constexpr std::uint32_t kStride=0x44;
constexpr std::uint32_t kTableFlag14=0xd14;
constexpr std::uint32_t kTableFlag15=0xd15;
constexpr std::uint32_t kChildren=0x454;
constexpr std::uint32_t kTargetByte=0x17e;
}
// Exact bounded d14-positive route from original RVA 0x4f420. d14 short-circuits
// its d15/special-item path. The original 0x422c20 body is the one-byte store
// translated inline here; it has no vtable call or other memory effects.
std::uint32_t fun_0044f420(Memory& m,const Inputs& in) {
    const auto root=in.cx;
    const auto table=m.r32(root+0x418u);
    if (!table) throw std::domain_error("4f420 bounded route requires non-null table");
    bool changed=false;
    for (std::uint32_t i=0;i<kRows;++i) {
        const auto step=i*kStride;
        const auto flag=m.r8(table+kTableFlag14+step);
        if (flag) {
            const auto child=m.r32(root+kChildren+4u*i);
            if (child) {
                if (flag!=1u || changed) throw std::domain_error("4f420 fixture must select one d14 row");
                m.w8(child+kTargetByte,0);
                changed=true;
            }
            continue;
        }
        if (m.r8(table+kTableFlag15+step))
            throw std::domain_error("4f420 d15/special path excluded by bounded fixture");
    }
    if (!changed) throw std::domain_error("4f420 fixture must select a non-null child row");
    return table; // EAX at the original final loop iteration.
}
// Exact bounded d14-positive route from original RVA 0x4f4f0. d14 short-circuits
// both 0x44ccc0 and the later special-item/0x4c750 path. The original 0x422c10
// body is the one-byte store translated inline here; it has no virtual call.
std::uint32_t fun_0044f4f0(Memory& m,const Inputs& in) {
    const auto root=in.cx;
    const auto table=m.r32(root+0x418u);
    if (!table) throw std::domain_error("4f4f0 bounded route requires non-null table");
    bool changed=false;
    std::uint32_t final_record=0;
    for (std::uint32_t i=0;i<kRows;++i) {
        const auto step=i*kStride;
        const auto record=table+step;
        final_record=record;
        const auto flag=m.r8(record+kTableFlag14);
        if (flag) {
            const auto child=m.r32(root+kChildren+4u*i);
            if (child) {
                if (flag!=1u || changed)
                    throw std::domain_error("4f4f0 fixture must select one d14 row");
                m.w8(child+kTargetByte,1);
                changed=true;
            }
            continue;
        }
        if (m.r8(record+kTableFlag15))
            throw std::domain_error("4f4f0 d15/removal/special path excluded by bounded fixture");
    }
    if (!changed) throw std::domain_error("4f4f0 fixture must select a non-null child row");
    return final_record; // EAX at the original final loop iteration.
}
}
