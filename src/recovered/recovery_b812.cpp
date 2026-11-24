#include "recovered/recovery_b812.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b812 {
namespace {
constexpr std::array<std::uint32_t, 6> source_slots{
    0x00a5a884u, 0x00a5a888u, 0x00a5a88cu,
    0x00a5a890u, 0x00a5a894u, 0x00a5a898u};
constexpr std::array<std::uint32_t, 6> destination_slots{
    0x00a5a89cu, 0x00a5a8a0u, 0x00a5a8a4u,
    0x00a5a8a8u, 0x00a5a8acu, 0x00a5a8b0u};
constexpr std::uint32_t request_bytes = 0x71u;
void need(bool value, const char* reason) {
    if (!value) throw std::domain_error(reason);
}

std::uint32_t terminated_utf16_bytes(const Memory& m, std::uint32_t source) {
    need(source != 0u, "B812 requires six nonnull source strings");
    for (std::uint32_t n = 0; n < 40u; ++n) {
        const auto low = m.r8(source + 2u * n);
        const auto high = m.r8(source + 2u * n + 1u);
        if (low == 0u && high == 0u) return 2u * (n + 1u);
    }
    throw std::domain_error("B812 UTF-16 source exceeds the bounded 40-unit copy region");
}

void initialize_sentinel(Heap& heap, std::uint32_t destination) {
    // Exact straight-line 0x522950 effect (34 bytes): MOV EAX,ECX; MOV CL,FF;
    // ten byte stores at ECX..ECX+9; RET. Use the heap abstraction rather
    // than converting the original guest address to a host pointer.
    for (std::uint32_t k = 0; k < 10u; ++k) heap.w8(destination + 0x28u + k, 0xffu);
}

void copy_utf16(Memory& m, Heap& heap, std::uint32_t destination,
                std::uint32_t source, std::uint32_t bytes) {
    // The accepted 0x76EFC9 routine takes a single contiguous Memory span,
    // while the original source and real heap destination are separate guest
    // regions. Use an instruction-equivalent local composition: the helper's
    // body is a byte-for-byte terminated UTF-16 copy (MOV/INC/MOV/JNZ loop).
    // Bounded source length and destination extent are checked above.
    need(bytes <= 0x28u, "B812 UTF-16 copy would overlap the 0x522950 sentinel field");
    for (std::uint32_t offset = 0; offset < bytes; ++offset)
        heap.w8(destination + offset, m.r8(source + offset));
}
}

std::uint32_t run(Memory& original, const Inputs&, Heap& heap) {
    Memory m = original;
    for (unsigned n = 0; n != source_slots.size(); ++n) {
        need(m.r32(source_slots[n]) != 0u,
             "B812 requires all six preinitialized UTF-16 source pointers");
        need(m.r32(destination_slots[n]) == 0u,
             "B812 success route requires all six destination globals initially null");
        (void)terminated_utf16_bytes(m, m.r32(source_slots[n]));
    }
    need(original.r32(0x00817554u) == 0u,
         "B812 actual ordinary-heap route requires threshold 0 at 0x817554");

    std::uint32_t eax = 0u;
    for (unsigned n = 0; n != destination_slots.size(); ++n) {
        const auto destination = heap.allocate(request_bytes); // original 0x76D957, size 0x71
        need(destination != 0u, "B812 success-only route requires six successful allocations");
        initialize_sentinel(heap, destination);                  // original 0x522950 precedes publication
        m.w32(destination_slots[n], destination);
        const auto source = m.r32(source_slots[n]);
        const auto bytes = terminated_utf16_bytes(m, source);
        copy_utf16(m, heap, destination, source, bytes);
        eax = destination;                                       // final 0x76EFC9 return
    }
    return eax; // original full EAX is the sixth destination pointer; RET 0
}
}
