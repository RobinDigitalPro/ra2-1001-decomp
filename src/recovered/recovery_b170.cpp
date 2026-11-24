#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b170 {
using ra2::recovered::global_b26::Memory;
using ra2::recovered::global_b26::Inputs;
using ra2::platform::ordinary_heap::Heap;

// Bounded one-removal route of original RVA 0x233400. The vptr is the
// constructor-proven default 0x793d14; its authentic +0x10 target (RVA
// 0x233e80) performs the pointer-index scan represented below.
std::uint32_t fun_00633400(Memory& m,const Inputs&,Heap& heap) {
    const auto count=m.r32(0x00a9e318u);
    if(count<2u||count>8u)throw std::domain_error("Block170 count must be 2..8");
    const auto list=m.r32(0x00a9e30cu);
    if(!list||m.r32(0x00a9e308u)!=0x00793d14u||!m.r8(0x00a9e314u))
        throw std::domain_error("Block170 requires constructor-proven active default registry manager");
    if(m.r32(0x793d24u)!=0x633e80u)throw std::domain_error("Block170 exact original slot required");
    std::uint32_t eax=0;
    for(std::uint32_t cursor=count;cursor!=0;--cursor){
        const auto slot=cursor-1u;
        const auto object=m.r32(list+slot*4u);
        if(!object)throw std::domain_error("Block170 records must be nonnull");
        const auto read32=[&](unsigned offset){return slot==0u?heap.r32(object+offset):m.r32(object+offset);};
        if(read32(0x24u)!=0xffffffffu)throw std::domain_error("Block170 timestamp must take -1 expiry shortcut");
        const auto remaining=read32(0x2cu);
        if(slot!=0u){
            if(remaining==0u)throw std::domain_error("Block170 only index zero is eligible");
            continue; // Original TEST EAX at 633436 skips this record.
        }
        if(remaining!=0u||heap.r8(object+0x3cu)!=0u)
            throw std::domain_error("Block170 index-zero record must enter registry-removal route");
        // Original 0x633e80: compare *argument with each DWORD in [ECX+4],
        // returning its index or -1. Manager and outer list share this table.
        std::uint32_t found=0xffffffffu;
        for(std::uint32_t j=0;j<m.r32(0x00a9e318u);++j)
            if(m.r32(list+j*4u)==object){found=j;break;}
        if(found!=0xffffffffu&&found<m.r32(0x00a9e318u)){
            const auto new_count=m.r32(0x00a9e318u)-1u;
            m.w32(0x00a9e318u,new_count);
            for(std::uint32_t j=found;j<new_count;++j)m.w32(list+j*4u,m.r32(list+(j+1u)*4u));
        }
        eax=heap.release(object); // original 0x76d67b; last EAX write in this route
    }
    return eax;
}
}
