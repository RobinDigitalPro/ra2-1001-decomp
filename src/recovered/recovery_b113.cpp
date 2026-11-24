#include "recovery_b113.hpp"

#include <cstdint>
#include <stdexcept>

// Recovered finite ordinary-heap routes. Heap must operate on live ordinary-heap
// storage: allocate(bytes)->guest pointer, release(pointer)->actual EAX/BOOL,
// and r8/w8/r32/w32(pointer) against that allocation. No helper return is mocked.
namespace ra2::recovered::recovery_b113 {

static std::uint32_t low_byte(std::uint32_t eax, std::uint8_t al) {
    return (eax & 0xffffff00u) | al;
}

static void copy_forward(Heap& heap, std::uint32_t destination,
                         std::uint32_t source, std::uint32_t bytes) {
    // Matches REP MOVSD followed by REP MOVSB with DF clear.
    const auto dwords = bytes >> 2;
    for (std::uint32_t n = 0; n < dwords; ++n)
        heap.w32(destination + 4u*n, heap.r32(source + 4u*n));
    for (std::uint32_t n = dwords*4u; n < bytes; ++n)
        heap.w8(destination + n, heap.r8(source + n));
}

// RVA 0x1fcc00 (VA 0x5fcc00). The original has three stack arguments and
// RET 0xc. For the finite request family: arg[1] is element count (43..106),
// arg[2] initializes object+4, arg[0] initializes object+0xc.
std::uint32_t fun_005fcc00(Memory& m, const Inputs& i, Heap& heap) {
    const auto object = i.cx;
    const auto count = i.arg[1];
    if (count < 43u || count > 106u)
        throw std::domain_error("0x1fcc00 requires constructor count 43..106");

    // Preserve original descriptor store order before the allocation call.
    m.w32(object + 4u, i.arg[2]);
    m.w32(object + 8u, count);
    m.w32(object + 0x0cu, i.arg[0]);

    const std::uint32_t request = count*24u + 4u;
    const auto raw = heap.allocate(request); // original 0x36d957
    if (!raw)
        throw std::domain_error("0x1fcc00 allocation failure enters an unsafe original write path");

    heap.w32(raw, count);
    const auto first = raw + 4u;
    for (std::uint32_t n = 0; n < count; ++n) {
        const auto record = first + n*0x18u;
        heap.w32(record + 4u, 0u);
        heap.w32(record + 8u, 0u);
        heap.w8(record + 0x0cu, 1u);
        heap.w8(record + 0x0du, 0u);
        heap.w32(record, 0x00792b98u); // original first vtable store
        heap.w32(record, 0x00792b38u); // immediately overwrites the same word
        heap.w32(record + 0x14u, 10u);
        heap.w32(record + 0x10u, 0u);
        // record+0x0e/+0x0f and any other untouched bytes remain allocator bytes.
    }

    m.w32(object, first);
    // After PUSH EBP, [ESP+0x14] resolves to original stack arg[0].
    // Preserve that second-pass overwrite distinctly from the earlier +0x14=10.
    for (std::uint32_t n = 0; n < count; ++n)
        heap.w32(first + n*0x18u + 0x14u, i.arg[0]);
    return object; // full EAX = ECX/this; RET 0xc
}

// RVA 0x1fa110 (VA 0x5fa110). Descriptor is [count,capacity,data] at
// object offsets 0,+4,+8. The finite parent request band uses capacity 104..200,
// giving new capacity=floor(capacity/2) and allocation size > 1016.
std::uint32_t fun_005fa110(Memory& m, const Inputs& i, Heap& heap) {
    const auto object = i.cx;
    const auto count = m.r32(object);
    const auto capacity = m.r32(object + 4u);
    if (capacity < 104u || capacity > 200u || count == 0u || count > capacity)
        throw std::domain_error("0x1fa110 requires capacity 104..200 and positive bounded count");
    if (i.arithmetic_flags & 0x400u)
        throw std::domain_error("0x1fa110 REP copy requires DF clear");
    const auto triple = count*3u;

    // CMP triple,capacity; JLE is the resize branch. On the other side XOR AL,AL
    // preserves EAX[31:8] from the LEA and clears only AL.
    if (static_cast<std::int32_t>(triple) > static_cast<std::int32_t>(capacity))
        return low_byte(triple, 0u);

    const auto old_capacity_calc = capacity; // capacity is positive in this contract; CDQ/SUB is a no-op.
    auto new_capacity = old_capacity_calc >> 1;
    if (new_capacity < 10u) new_capacity = 10u;
    if (new_capacity >= capacity)
        return low_byte(old_capacity_calc, 0u); // CMP/JL failure; XOR AL,AL only.

    const auto request = new_capacity*20u;
    const auto new_data = heap.allocate(request); // original 0x36d957
    if (!new_data)
        throw std::domain_error("0x1fa110 allocation failure with an owned old buffer reaches an unsafe copy");

    const auto old_data = m.r32(object + 8u);
    if (!old_data)
        throw std::domain_error("0x1fa110 selected heap route requires a live owned old buffer");
    copy_forward(heap, new_data, old_data, count*20u);
    const auto free_eax = heap.release(old_data); // original 0x36d67b; call result survives in upper EAX
    m.w32(object + 8u, new_data);
    m.w32(object + 4u, new_capacity);
    return low_byte(free_eax, 1u); // MOV AL,1 preserves EAX[31:8] from real HeapFree result.
}

// RVA 0x353bc0 (VA 0x753bc0). Same descriptor and branch guards as 0x1fa110;
// this clone resizes 4-byte elements and requests four bytes per new-capacity unit.
std::uint32_t fun_00753bc0(Memory& m, const Inputs& i, Heap& heap) {
    const auto object = i.cx;
    const auto count = m.r32(object);
    const auto capacity = m.r32(object + 4u);
    if (capacity < 600u || capacity > 800u || count == 0u || count > capacity)
        throw std::domain_error("0x353bc0 requires capacity 600..800 and positive bounded count");
    if (i.arithmetic_flags & 0x400u)
        throw std::domain_error("0x353bc0 REP copy requires DF clear");
    const auto triple = count*3u;

    if (static_cast<std::int32_t>(triple) > static_cast<std::int32_t>(capacity))
        return low_byte(triple, 0u);

    const auto old_capacity_calc = capacity; // positive finite capacity; CDQ/SUB leaves EAX unchanged.
    auto new_capacity = old_capacity_calc >> 1;
    if (new_capacity < 10u) new_capacity = 10u;
    if (new_capacity >= capacity)
        return low_byte(old_capacity_calc, 0u);

    const auto request = new_capacity*4u;
    const auto new_data = heap.allocate(request); // original 0x36d957
    if (!new_data)
        throw std::domain_error("0x353bc0 allocation failure with an owned old buffer reaches an unsafe copy");

    const auto old_data = m.r32(object + 8u);
    if (!old_data)
        throw std::domain_error("0x353bc0 selected heap route requires a live owned old buffer");
    copy_forward(heap, new_data, old_data, count*4u);
    const auto free_eax = heap.release(old_data); // original 0x36d67b
    m.w32(object + 8u, new_data);
    m.w32(object + 4u, new_capacity);
    return low_byte(free_eax, 1u);
}
} // namespace ra2::recovered::recovery_b113


