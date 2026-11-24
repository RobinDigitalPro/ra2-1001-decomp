#include "recovered/recovery_b889.hpp"
#include <cstdint>
#include <initializer_list>
#include <stdexcept>

namespace ra2::recovered::recovery_b889 {
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}

constexpr std::uint32_t empty_wide = 0x008248a4u;

// Heap-only adaptation of the accepted B291 nested-constructor model. The
// child is itself the first allocation, so all fields that B291 wrote through
// Memory::self are written through Heap here. The eight subsequent requests,
// nested offsets, and reset writes follow recovery_b291.cpp exactly.
std::uint32_t initialize_nested_child(Memory& m, Heap& heap,
                                      std::uint32_t child,
                                      std::uint32_t a4,
                                      std::uint32_t a6,
                                      std::uint32_t a7) {
    need(a7 == empty_wide && m.r16(a7) == 0u,
         "selected empty UTF-16 constructor input required");

    const auto unused = heap.allocate(8u);  // nested request #1
    need(unused != 0, "successful nested 8-byte allocation required");
    const auto object = heap.allocate(0x58u);  // nested request #2
    need(object != 0, "successful nested 88-byte allocation required");

    heap.w32(child, 0x00788dccu);
    heap.w32(child + 0x1cu, 8u);
    heap.w32(child + 0x20u, unused);
    heap.w8(child + 0x24u, std::uint8_t(a4));
    heap.w8(child + 0x25u, std::uint8_t(a4 >> 8u));
    heap.w32(child + 0x28u, 2u);
    heap.w32(child + 0x2cu, 0xffffffffu);
    heap.w32(child + 0x30u, 60u);

    const auto rows32 = heap.allocate(32u);  // nested request #3
    const auto rows20 = heap.allocate(20u);  // nested request #4
    const auto ptrs32 = heap.allocate(4u);   // nested request #5
    const auto ptrs20 = heap.allocate(4u);   // nested request #6
    need(rows32 && rows20 && ptrs32 && ptrs20,
         "successful nested array allocations required");

    heap.w32(object, 0x00788db4u);
    heap.w32(object + 4u, 1u);
    heap.w32(object + 8u, 1u);
    heap.w32(object + 0x0cu, 8u);
    heap.w32(object + 0x10u, 0u);
    heap.w32(object + 0x24u, rows32);
    heap.w32(object + 0x34u, rows20);
    heap.w32(object + 0x30u, ptrs32);
    heap.w32(object + 0x40u, ptrs20);

    const auto row32 = heap.allocate(8u);    // nested request #7
    const auto row20 = heap.allocate(8u);    // nested request #8
    need(row32 && row20, "successful nested row payloads required");
    heap.w32(rows32 + 0x14u, row32);
    heap.w32(rows32 + 0x1cu, 0u);
    heap.w32(rows20 + 8u, row20);
    heap.w32(rows20 + 0x10u, 0u);

    // Original 0x47fea0 reset called by B291's constructor. These writes leave
    // all nested allocations and backing pointers live.
    heap.w32(object + 0x2cu, 0u);
    heap.w32(object + 0x3cu, 0u);
    for (const auto off : {0x14u, 0x18u, 0x1cu, 0x20u, 0x28u, 0x38u,
                           0x44u, 0x48u, 0x4cu, 0x54u})
        heap.w32(object + off, 0u);
    heap.w32(rows32, heap.r32(rows32) & ~7u);
    for (const auto off : {4u, 8u, 0x0cu, 0x10u, 0x18u})
        heap.w32(rows32 + off, 0u);
    heap.w32(ptrs32, 0u);
    heap.w32(rows20, heap.r32(rows20) & ~7u);
    heap.w32(rows20 + 4u, 0u);
    heap.w32(rows20 + 0x0cu, 0u);
    heap.w32(ptrs20, 0u);

    // Final 0x522f30 field writes before returning to 0x124280.
    heap.w32(child, 0x0078f644u);
    for (unsigned k = 0; k < 10u; ++k) heap.w8(child + 0x4cu + k, 0xffu);
    heap.w32(child + 0x60u, a6);
    for (std::uint32_t k = 0;; k += 2u) {
        const auto ch = m.r16(a7 + k);
        heap.w8(child + 0x64u + k, std::uint8_t(ch));
        heap.w8(child + 0x65u + k, std::uint8_t(ch >> 8u));
        if (ch == 0u) break;
        need(k < 0x100u, "bounded selected UTF-16 input required");
    }
    heap.w32(child + 0x56u, 0xffffffffu);
    heap.w8(child + 0x5au, 0xffu);
    heap.w8(child + 0x5bu, 0xffu);
    heap.w32(child + 0x5cu, 0u);
    heap.w32(child + 4u, object);
    return child; // original 0x522f30 EAX is its receiver
}

void reset_nested_again(Heap& heap, std::uint32_t object,
                        std::uint32_t rows32, std::uint32_t rows20,
                        std::uint32_t ptrs32, std::uint32_t ptrs20) {
    // Original vtable slot +4 reaches 0x522fe0 -> 0x481170 -> 0x47fea0.
    // Its second 0x47fea0 pass is idempotent in this one-row contract.
    for (const auto off : {0x2cu, 0x3cu, 0x14u, 0x18u, 0x1cu, 0x20u,
                           0x28u, 0x38u, 0x44u, 0x48u, 0x4cu, 0x54u})
        heap.w32(object + off, 0u);
    heap.w32(rows32, heap.r32(rows32) & ~7u);
    for (const auto off : {4u, 8u, 0x0cu, 0x10u, 0x18u})
        heap.w32(rows32 + off, 0u);
    heap.w32(ptrs32, 0u);
    heap.w32(rows20, heap.r32(rows20) & ~7u);
    heap.w32(rows20 + 4u, 0u);
    heap.w32(rows20 + 0x0cu, 0u);
    heap.w32(ptrs20, 0u);
}
}

std::uint32_t fun_00524280(Memory& m, Inputs& i, Heap& heap) {
    const auto self = i.cx;
    need(m.r32(0x78f648)==0x522fe0,"889 authenticchildreset target");
    need(self != 0u, "mapped nonnull parent required");
    need(m.r8(self + 4u) != 0u, "enabled parent required");
    const auto count = m.r32(self + 0x44u);
    need(count < 7u, "positive bounded parent table slot required");
    need(m.r32(self + 0x14u) == 1u && m.r32(self + 0x10u) == 0u,
         "exact nested 0x122f30 count recipe required");
    need(i.arg[0] == 0u && i.arg[1] == empty_wide && i.arg[2] == 0u,
         "exact null/null/empty-wide root arguments required");
    need(m.r16(empty_wide) == 0u,
         "original empty UTF-16 source must be mapped and terminated");

    // 0x52429c..0x5242a9: outer child allocation is request ordinal 0.
    const auto child = heap.allocate(0xb4u);
    need(child != 0u, "successful 0xb4 outer-child allocation required");

    // Exact stack-derived arguments to 0x522f30:
    // A1=A2=1, A3=0, A4=word[parent+0x20], A5=root arg2,
    // A6=root arg0, A7=root arg1, A8=0.
    const auto a4 = m.r16(self + 0x20u);
    const auto nested_result =
        initialize_nested_child(m, heap, child, a4, i.arg[0], i.arg[1]);
    need(nested_result == child,
         "0x522f30 receiver return required for parent publication");

    // Parent table publication occurs before the authentic child reset call.
    m.w32(self + 0x28u + count * 4u, nested_result);

    // Outer writes in original 0x81170 (slot+4 thunk): only +8,+c,+10,+14,
    // +18,+34,+38,+3c,+40 clear; +0x1c/+0x20/+0x24 and the +0x4c payload
    // survive. It writes sentinels at +0x44/+0x48, then resets nested +4.
    for (const auto off : {8u, 0x0cu, 0x10u, 0x14u, 0x18u,
                           0x34u, 0x38u, 0x3cu, 0x40u})
        heap.w32(child + off, 0u);
    heap.w32(child + 0x44u, 0xffffffffu);
    heap.w32(child + 0x48u, 0xffffffffu);

    const auto object = heap.r32(child + 4u);
    need(object != 0u, "child nested-object pointer must survive slot+4 reset");
    const auto rows32 = heap.r32(object + 0x24u);
    const auto rows20 = heap.r32(object + 0x34u);
    const auto ptrs32 = heap.r32(object + 0x30u);
    const auto ptrs20 = heap.r32(object + 0x40u);
    need(rows32 && rows20 && ptrs32 && ptrs20,
         "nested backing pointers must survive reset; no free is performed");
    reset_nested_again(heap, object, rows32, rows20, ptrs32, ptrs20);

    // Original post-vcall stores and count publication.
    heap.w32(child + 0x28u, m.r32(self + 0x58u));
    heap.w32(child + 0x2cu, m.r32(self + 0x5cu));
    heap.w32(child + 0x30u, m.r32(self + 0x60u));
    m.w32(self + 0x44u, count + 1u);
    return 1u; // original EAX=1; ABI cleanup is RET 0x0c
}
}
