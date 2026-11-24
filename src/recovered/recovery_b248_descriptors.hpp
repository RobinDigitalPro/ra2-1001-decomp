#pragma once

#include "recovered/global_b26_memory.hpp"
#include "platform/small_crt_heap_win32.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovery_b248_detail {
using Memory = ra2::recovered::global_b26::Memory;
using Heap = ra2::platform::small_crt_heap::Heap;

// One row per real 0x76D957 call in 0x4838E0's selector-one arm.
// Pinned evidence: ctor_full.txt, VA 0x4838E0..0x483D40; each row's caller
// is the instruction immediately after its CALL (also recorded by the PE probe).
enum class Ref : std::uint8_t { Member174, Member178, Address17C };
struct DescriptorSpec {
    std::uint8_t request;
    std::uint16_t published_offset;
    std::uint32_t vptr;
    Ref word4;
    Ref word8;
};
inline constexpr std::array<DescriptorSpec, 25> selector_one_descriptors{{
    {8,0x008,0x0078951c,Ref::Member174,Ref::Member174},
    {8,0x00c,0x0078950c,Ref::Member174,Ref::Member174},
    {12,0x014,0x007894fc,Ref::Address17C,Ref::Member174},
    {8,0x010,0x007894ec,Ref::Member178,Ref::Member178},
    {12,0x018,0x007894dc,Ref::Member178,Ref::Member174},
    {12,0x01c,0x007894dc,Ref::Member178,Ref::Member174},
    {12,0x020,0x007894dc,Ref::Member178,Ref::Member174},
    {8,0x0d0,0x007894d0,Ref::Member174,Ref::Member174},
    {12,0x0d8,0x007894c4,Ref::Address17C,Ref::Member174},
    {8,0x0d4,0x007894b8,Ref::Member178,Ref::Member178},
    {12,0x0dc,0x007894ac,Ref::Member178,Ref::Member174},
    {12,0x0e0,0x007894ac,Ref::Member178,Ref::Member174},
    {12,0x0e4,0x007894ac,Ref::Member178,Ref::Member174},
    {8,0x0e8,0x007894a0,Ref::Member174,Ref::Member174},
    {12,0x0ec,0x00789494,Ref::Address17C,Ref::Member174},
    {8,0x0f0,0x00789488,Ref::Member178,Ref::Member178},
    {12,0x0f4,0x0078947c,Ref::Member178,Ref::Member174},
    {12,0x0f8,0x0078947c,Ref::Member178,Ref::Member174},
    {12,0x0fc,0x0078947c,Ref::Member178,Ref::Member174},
    {8,0x10c,0x00789470,Ref::Member174,Ref::Member174},
    {12,0x110,0x00789464,Ref::Address17C,Ref::Member174},
    {8,0x114,0x00789458,Ref::Member178,Ref::Member178},
    {12,0x118,0x0078944c,Ref::Member178,Ref::Member174},
    {12,0x11c,0x0078944c,Ref::Member178,Ref::Member174},
    {12,0x120,0x0078944c,Ref::Member178,Ref::Member174},
}};
inline constexpr std::array<std::uint32_t, 29> allocation_recipe{{
    0x300,0x188,0x100,0x100,
    8,8,12,8,12,12,12,8,12,8,12,12,12,8,12,8,12,12,12,8,12,8,12,12,12
}};

template<class HeapLike>
inline std::uint32_t resolve(HeapLike& heap, std::uint32_t object, Ref ref) {
    switch (ref) {
    case Ref::Member174: return heap.r32(object + 0x174u);
    case Ref::Member178: return heap.r32(object + 0x178u);
    case Ref::Address17C: return object + 0x17cu;
    }
    return 0;
}

// Exact positive-allocation selector-one arm. The caller supplies the real
// constructor object whose +174/+178/+17c fields have already been established.
// Stores and publication order match 0x4838F0..0x483D11; allocation failure is
// outside this positive finite contract.
template<class HeapLike>
inline void initialize_selector_one(HeapLike& heap, std::uint32_t object) {
    for (const auto& s : selector_one_descriptors) {
        const auto child = heap.allocate(s.request);
        if (!child) throw std::domain_error("Block248 excludes allocation failure");
        heap.w32(child, s.vptr);
        heap.w32(child + 4u, resolve(heap, object, s.word4));
        if (s.request == 12u)
            heap.w32(child + 8u, resolve(heap, object, s.word8));
        heap.w32(object + s.published_offset, child);
    }
}
} // namespace ra2::recovery_b248_detail
