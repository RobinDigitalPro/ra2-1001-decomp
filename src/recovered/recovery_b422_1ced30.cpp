#include "recovery_b422_1ced30.hpp"
#include <stdexcept>
#include <utility>

namespace ra2::recovered::lifecycle_b422_1ced30 {

namespace {
std::uint32_t release_three_slot_object(Heap& heap,std::uint32_t object) {
    std::uint32_t eax=0;
    for(unsigned slot=0;slot<3;++slot) {
        const auto p=heap.r32(object+0x10u+4u*slot);
        if(slot!=0) heap.w32(object+0x0cu+4u*slot,0u);
        if(p) eax=heap.release(p);
    }
    heap.w32(object+0x18u,0u);
    return eax;
}
std::uint32_t release_one_slot_object(Heap& heap,std::uint32_t object) {
    const auto p=heap.r32(object+0x0cu);
    auto eax=p?heap.release(p):0u;
    heap.w32(object+0x0cu,0u);
    return eax;
}
}

std::uint32_t fun_005ced30(Memory& m,const Inputs& in,Heap& heap) {
    std::uint32_t row=in.cx+0xccu;
    std::uint32_t eax=0;
    for(unsigned i=0;i<15;++i,row+=8u) {
        for(const auto [field,kind]:{std::pair<std::uint32_t,unsigned>{0xfffffffcu,0u},
                                     std::pair<std::uint32_t,unsigned>{0u,1u},
                                     std::pair<std::uint32_t,unsigned>{0x74u,0u},
                                     std::pair<std::uint32_t,unsigned>{0x78u,1u}}) {
            const auto owner=m.r32(row+field);
            if(!owner) continue;
            if(kind==0u) (void)release_three_slot_object(heap,owner);
            else (void)release_one_slot_object(heap,owner);
            eax=heap.release(owner);
            m.w32(row+field,0u);
        }
    }
    return eax;
}

}
