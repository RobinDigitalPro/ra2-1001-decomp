#include "recovered/recovery_b890.hpp"
#include <cstdint>
#include <initializer_list>
#include <stdexcept>

namespace ra2::recovered::global_b26 {
std::uint32_t fun_006eee20(Memory&, const Inputs&);
}

namespace ra2::recovered::recovery_b890 {
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}

constexpr std::uint32_t original_multicast = 0x007c8e70u;

std::uint32_t initialize_nested_child(Memory& m, Heap& heap,
                                      std::uint32_t child,
                                      std::uint32_t a4,
                                      std::uint32_t a5,
                                      std::uint32_t a6,
                                      std::uint32_t a7) {
    need(a5 != 0u, "non-null ten-byte source object required");
    need(a6 == 0xffffffffu, "exact A6 sentinel required");

    const auto unused = heap.allocate(8u);
    const auto object = heap.allocate(0x58u);
    need(unused && object, "successful nested 8/88-byte allocations required");

    heap.w32(child, 0x00788dccu);
    heap.w32(child + 0x1cu, 8u);
    heap.w32(child + 0x20u, unused);
    heap.w8(child + 0x24u, std::uint8_t(a4));
    heap.w8(child + 0x25u, std::uint8_t(a4 >> 8u));
    heap.w32(child + 0x28u, 2u);
    heap.w32(child + 0x2cu, 0xffffffffu);
    heap.w32(child + 0x30u, 60u);

    const auto rows32 = heap.allocate(32u);
    const auto rows20 = heap.allocate(20u);
    const auto ptrs32 = heap.allocate(4u);
    const auto ptrs20 = heap.allocate(4u);
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

    const auto row32 = heap.allocate(8u);
    const auto row20 = heap.allocate(8u);
    need(row32 && row20, "successful nested row payload allocations required");
    heap.w32(rows32 + 0x14u, row32);
    heap.w32(rows32 + 0x1cu, 0u);
    heap.w32(rows20 + 8u, row20);
    heap.w32(rows20 + 0x10u, 0u);

    // First pass through original 0x47fea0; allocated arrays stay live.
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

    // Original 0x522F75..85 copies ten source bytes into child+0x4c. The authentic
    // 0x122a60 helper sends bytes 0..3 to its caller-local A8 and bytes 4..9
    // to its local six-byte field; 0x522f30 copies those six bytes to +0x56.
    for (unsigned k = 0; k < 10u; ++k)
        heap.w8(child + 0x4cu + k, m.r8(a5 + k));
    heap.w32(child + 0x60u, a6);
    for (std::uint32_t k = 0;; k += 2u) {
        const auto ch = m.r16(a7 + k);
        heap.w8(child + 0x64u + k, std::uint8_t(ch));
        heap.w8(child + 0x65u + k, std::uint8_t(ch >> 8u));
        if (ch == 0u) break;
        need(k < 0x100u, "bounded selected UTF-16 input required");
    }
    heap.w32(child + 0x56u, m.r32(a5 + 4u));
    heap.w8(child + 0x5au, m.r8(a5 + 8u));
    heap.w8(child + 0x5bu, m.r8(a5 + 9u));
    heap.w32(child + 0x5cu, 0u);
    heap.w32(child, 0x0078f644u);
    heap.w32(child + 4u, object);
    return child;
}

void reset_nested_again(Heap& heap, std::uint32_t object,
                        std::uint32_t rows32, std::uint32_t rows20,
                        std::uint32_t ptrs32, std::uint32_t ptrs20) {
    // Original slot +4 thunk: 0x522fe0 -> 0x481170 -> 0x47fea0.
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

std::uint32_t fun_00524330(Memory& m, Inputs& i, Heap& heap) {
    need(m.r32(0x78f648)==0x522fe0,"890 authenticreset target");
    const auto self = i.cx;
    need(self != 0u && m.r8(self + 4u) != 0u,
         "mapped enabled receiver required");
    need(m.r32(self + 0x14u) == 1u && m.r32(self + 0x10u) == 0u,
         "exact positive nested 0x522f30 count recipe required");
    need(m.r32(0xab7ee0u) < 8u, "valid UTF-16 conversion ring index required");
    constexpr char literal[] = "Multicast";
    for (unsigned k = 0; k < sizeof(literal); ++k)
        need(m.r8(original_multicast + k) ==
                 static_cast<std::uint8_t>(literal[k]),
             "authoritative original Multicast literal required");

    // Root's first request is the outer 0xb4 child allocation.
    const auto child = heap.allocate(0xb4u);
    need(child != 0u, "successful 0xb4 outer-child allocation required");

    // Original 0x2eee20 is called on the immutable literal. It writes a
    // nine-character UTF-16 string plus terminator in the selected ring slot
    // and advances [0xab7ee0] modulo eight.
    Inputs conversion{};
    conversion.cx = original_multicast;
    const auto wide = global_b26::fun_006eee20(m, conversion);
    need(wide != 0u, "original UTF-16 ring conversion result required");

    const auto a5 = m.r32(m.r32(0xa27dacu) + 0u) + 0x28u;
    const auto a4 = m.r16(self + 0x20u);
    const auto nested_result =
        initialize_nested_child(m, heap, child, a4, a5, 0xffffffffu, wide);
    need(nested_result == child,
         "0x522f30 receiver return required for parent publication");

    // 0x52438a publishes the nested constructor result at parent+0x50 before
    // dispatching the authentic +4 reset slot. This root does not append to
    // the separate table used by 0x124280.
    m.w32(self + 0x50u, nested_result);
    for (const auto off : {8u, 0x0cu, 0x10u, 0x14u, 0x18u,
                           0x34u, 0x38u, 0x3cu, 0x40u})
        heap.w32(child + off, 0u);
    heap.w32(child + 0x44u, 0xffffffffu);
    heap.w32(child + 0x48u, 0xffffffffu);

    const auto object = heap.r32(child + 4u);
    need(object != 0u, "nested-object pointer must survive outer reset");
    const auto rows32 = heap.r32(object + 0x24u);
    const auto rows20 = heap.r32(object + 0x34u);
    const auto ptrs32 = heap.r32(object + 0x30u);
    const auto ptrs20 = heap.r32(object + 0x40u);
    need(rows32 && rows20 && ptrs32 && ptrs20,
         "nested backing pointers must survive reset; no free is performed");
    reset_nested_again(heap, object, rows32, rows20, ptrs32, ptrs20);

    // Exact post-vcall assignments at 0x52439b..0x5243bb.
    heap.w32(child + 0x28u, m.r32(self + 0x58u));
    heap.w32(child + 0x2cu, m.r32(self + 0x5cu));
    heap.w32(child + 0x30u, m.r32(self + 0x60u));
    return 1u; // original EAX=1; callee pops 0x20 bytes at nested call
}
}
