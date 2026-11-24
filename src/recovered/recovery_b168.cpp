#include "recovered/recovery_b168.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b168 {
namespace {
constexpr std::uint32_t item_vtable=0x00790ab8u;
constexpr std::uint32_t clear_slot=0x00790ac4u;
constexpr std::uint32_t clear_target=0x00567860u; // RVA 0x167860

// Reached virtual target from the constructor-proven item's actual +0xc slot.
// The selected input has a null owned pointer, so original 0x167860 takes its
// no-release branch; this is the real target's instruction effect, not a stub.
void run_null_owned_item_clear(Memory& m,std::uint32_t item) {
    const auto table=m.r32(item);
    if(table!=item_vtable || m.r32(table+0x0cu)!=clear_target || m.r32(clear_slot)!=clear_target)
        throw std::domain_error("Block168 requires pinned vtable 0x790ab8 and original clear target 0x567860");
    if(m.r32(item+4u)!=0u)
        throw std::domain_error("Block168 covers the constructor-proven null-owned-buffer clear route only");
    m.w32(item+0x10u,0u); // 0x567869
    // The target tests old pointer and byte+0xd; old pointer is zero here.
    m.w8(item+0x0du,0u); // 0x567881
    m.w32(item+8u,0u);    // 0x567884
}
}

// Original RVA 0x1697a0; only finite positive counts using the actual
// ordinary-heap branch are in this proposed contract.
std::uint32_t fun_005697a0(Memory& m,const Inputs& i,Heap& h) {
    const auto destination=i.cx;
    const auto source=i.arg[0];
    if(!destination || !source || destination==source)
        throw std::domain_error("Block168 requires distinct nonnull source and destination records");
    run_null_owned_item_clear(m,destination);

    const auto capacity=m.r32(source+8u);
    if(capacity<128u || capacity>160u)
        throw std::domain_error("Block168 requires source capacity 128..160 (ordinary-heap request 1024..1280)");
    m.w32(destination+8u,capacity);                 // 0x5697ba
    const auto out=h.allocate(capacity*8u);         // original helper RVA 0x36d957
    if(!out)
        throw std::runtime_error("Block168 contract is success-only for the real ordinary-heap allocation");
    for(std::uint32_t k=0;k<capacity;++k) {         // original zero-init loop
        h.w32(out+k*8u,0u);                         // 0x5697dd
        h.w8(out+k*8u+4u,0u);                       // 0x5697df
    }
    m.w32(destination+4u,out); // 0x5697ee, after initialization
    m.w8(destination+0x0du,1u); // 0x5697fa
    const auto source_data=m.r32(source+4u);
    for(std::uint32_t k=0;k<capacity;++k) {         // original two-dword copy loop
        h.w32(out+k*8u,m.r32(source_data+k*8u));
        h.w32(out+k*8u+4u,m.r32(source_data+k*8u+4u));
    }
    m.w32(destination+0x10u,m.r32(source+0x10u));                 // 0x569828
    m.w32(destination+0x14u,m.r32(source+0x14u));                // 0x56982e
    return destination;                             // MOV EAX,ESI; RET 4
}
}
