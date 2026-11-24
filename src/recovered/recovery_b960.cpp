#include "recovered/recovery_b960.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::recovery_b960 {
namespace {
struct Pair { std::uint32_t key; std::uint32_t value; };
void sort_pairs(Memory& m, std::uint32_t data, std::uint32_t count) {
    std::array<Pair, 8> items{};
    for (std::uint32_t i=0; i<count; ++i) {
        items[i].key=m.r32(data+i*8u);
        items[i].value=m.r32(data+i*8u+4u);
    }
    std::sort(items.begin(),items.begin()+count,[](const Pair& a,const Pair& b) {
        return global_b26::s32(a.key)<global_b26::s32(b.key);
    });
    for (std::uint32_t i=0; i<count; ++i) {
        m.w32(data+i*8u,items[i].key);
        m.w32(data+i*8u+4u,items[i].value);
    }
}
void clear_nonowning_vector(Memory& m, std::uint32_t subobject) {
    // Exact resolved target 0x695420: count at +0x10 is cleared; with owner flag
    // byte +0x0d == 0, storage is retained, and capacity at +0x08 is cleared.
    m.w32(subobject+0x10u,0);
    if (m.r32(subobject+4u)!=0 && m.r8(subobject+0x0du)!=0) {
        // This branch is outside the finite route and is deliberately unsupported.
        throw std::domain_error("B960 route requires the original nonowning flag to be zero");
    }
    m.w8(subobject+0x0du,0);
    m.w32(subobject+8u,0);
}
}
std::uint32_t fun_00695280(Memory& m,const Inputs& i) {
    const auto receiver=i.cx;
    const auto first_data=m.r32(receiver+8u);
    const auto first_count=m.r32(receiver+0x14u);
    const auto second_data=m.r32(receiver+0x20u);
    const auto second_count=m.r32(receiver+0x2cu);
    if(first_count<1||first_count>8||second_count!=first_count||m.r32(receiver+4)!=0x797204||m.r32(receiver+0x1c)!=0x797204||m.r8(receiver+0x11)||m.r8(receiver+0x29))throw std::domain_error("960 finite matching nonowning vectors");
    sort_pairs(m,second_data,second_count);
    sort_pairs(m,first_data,first_count);
    std::uint32_t j=0;
    for (std::uint32_t i0=0;i0<first_count;++i0) {
        const auto a=first_data+i0*8u;
        const auto key=m.r32(a);
        while (j<second_count && global_b26::s32(key)>global_b26::s32(m.r32(second_data+j*8u))) ++j;
        if (j<second_count && key==m.r32(second_data+j*8u)) {
            const auto slot=m.r32(a+4u);
            const auto value=m.r32(second_data+j*8u+4u);
            m.w32(slot,value);
        }
    }
    clear_nonowning_vector(m,receiver+4u);
    clear_nonowning_vector(m,receiver+0x1cu);
    return second_data;
}
}


