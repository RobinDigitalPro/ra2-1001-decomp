#include "recovery_b1683.hpp"
#include <stdexcept>
namespace ra2::recovered::b1683 {
namespace {
constexpr unsigned slots[]={0x821c94u,0x821c98u,0x821c84u,
                            0x821c88u,0x821ca4u,0x821c90u};
}
unsigned run(Memory& m,const Inputs& in,Heap& heap,Observation& out) {
    (void)in;
    out={};
    // These exceptions exclude paths outside the finite proposal. They are
    // not substitutes for allocator/provenance checks in the test adapter.
    if(m.r8(0x83b307u)!=0u || m.r8(0xaa4f95u)!=0u)
        throw std::invalid_argument("2838B0 excluded public flags");
    for(const unsigned slot:slots) {
        const unsigned self=m.r32(slot);
        if(self==0u) continue;
        if(out.releases!=0u)
            throw std::invalid_argument("2838B0 requires exactly one owner");
        out.slot=slot; out.object=self; out.stage=1u;
        const unsigned vptr=heap.r32(self);
        if(vptr!=0x785ef8u || m.r32(vptr)!=0x4113d0u)
            throw std::invalid_argument("2838B0 excluded virtual receiver");
        // Actual virtual target 4113D0, flags=1. Its first call is
        // 438290(self+14): free buffer BEFORE changing any object field.
        if(heap.r8(self+0x1cu)!=1u)
            throw std::invalid_argument("2838B0 excluded buffer ownership");
        out.buffer=heap.r32(self+0x14u); out.stage=2u;
        (void)heap.release(out.buffer);
        out.releases=1u;
        heap.w32(self+0x14u,0u);
        heap.w32(self+0x18u,0u);
        heap.w8(self+0x1cu,0u);
        heap.w32(self,0x786020u);
        out.stage=3u;
        (void)heap.release(self);
        out.releases=2u;
        // The deleting method returns self, but the root discards it.
        m.w32(slot,0u);
        out.stage=4u;
    }
    if(out.releases!=2u)
        throw std::invalid_argument("2838B0 requires one nonnull slot");
    // 495C70: authentic BSS-null path loads full EAX=0, skips all COM
    // calls/writes, and restores EDI/private frame. Dependency only.
    const unsigned result=m.r32(0x83a6fcu);
    if(result!=0u)
        throw std::invalid_argument("2838B0 excluded live COM branch");
    m.w8(0xaa4f95u,1u);
    out.stage=5u;
    return result;
}
unsigned run(Memory& m,const Inputs& in,Heap& heap) {
    Observation out;
    return run(m,in,heap,out);
}
}
