#include "recovery_b115.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b115 {
namespace {

std::uint32_t set_al(std::uint32_t eax, std::uint32_t al) {
    return (eax & 0xffffff00u) | (al & 0xffu);
}

void copy_bytes(Heap& heap, std::uint32_t destination,
                std::uint32_t source, std::uint32_t bytes) {
    // The source bodies use REP MOVSD followed by REP MOVSB; DF must be clear.
    for (std::uint32_t offset = 0; offset < bytes; ++offset)
        heap.w8(destination + offset, heap.r8(source + offset));
}

void zero_bytes(Heap& heap, std::uint32_t destination, std::uint32_t bytes) {
    // The source body uses REP STOSD then REP STOSB with EAX=0 and DF clear.
    for (std::uint32_t offset = 0; offset < bytes; ++offset)
        heap.w8(destination + offset, 0u);
}

} // namespace

// RVA 0x1fa080 / VA 0x5fa080. Descriptor: [count, capacity, data].
// JLE at VA 0x5fa090 enters the resize path, so require 3*count <= capacity.
std::uint32_t fun_005fa080(Memory& memory, const Inputs& inputs, Heap& heap) {
    if (inputs.arithmetic_flags & 0x400u)
        throw std::domain_error("0x1fa080 REP copy requires DF clear");
    const auto object = inputs.cx;
    const auto count = memory.r32(object);
    const auto capacity = memory.r32(object + 4u);
    if (capacity < 600u || capacity > 800u || count == 0u || count > capacity / 3u)
        throw std::domain_error("0x1fa080 contract requires capacity 600..800 and 1<=count<=capacity/3");

    auto new_capacity = capacity >> 1; // positive signed CDQ/SUB leaves capacity unchanged
    if (new_capacity < 10u) new_capacity = 10u;
    if (new_capacity >= capacity)
        throw std::domain_error("0x1fa080 contract must take JL allocation path");
    const auto request = new_capacity * 4u;
    const auto new_data = heap.allocate(request); // original helper 0x36d957
    if (!new_data)
        throw std::runtime_error("0x1fa080 allocation failure makes original copy destination invalid");

    const auto old_data = memory.r32(object + 8u);
    if (!old_data)
        throw std::domain_error("0x1fa080 contract requires a live old allocation");
    copy_bytes(heap, new_data, old_data, count * 4u);
    const auto free_eax = heap.release(old_data); // original helper 0x36d67b
    memory.w32(object + 8u, new_data);
    memory.w32(object + 4u, new_capacity);
    return set_al(free_eax, 1u); // MOV AL,1 preserves release EAX[31:8].
}

// RVA 0x352f10 / VA 0x752f10. Descriptor: [count, capacity, data].
// JLE at VA 0x752f20 enters the resize path. Elements are 268 bytes.
std::uint32_t fun_00752f10(Memory& memory, const Inputs& inputs, Heap& heap) {
    if (inputs.arithmetic_flags & 0x400u)
        throw std::domain_error("0x352f10 REP copy requires DF clear");
    const auto object = inputs.cx;
    const auto count = memory.r32(object);
    const auto capacity = memory.r32(object + 4u);
    if (capacity < 20u || capacity > 60u || count == 0u || count > capacity / 3u)
        throw std::domain_error("0x352f10 contract requires capacity 20..60 and 1<=count<=capacity/3");

    auto new_capacity = capacity >> 1; // positive signed CDQ/SUB leaves capacity unchanged
    if (new_capacity < 10u) new_capacity = 10u;
    if (new_capacity >= capacity)
        throw std::domain_error("0x352f10 contract must take JL allocation path");
    const auto request = new_capacity * 268u; // 32n+n -> 67n -> 268n
    const auto new_data = heap.allocate(request); // original helper 0x36d957
    if (!new_data)
        throw std::runtime_error("0x352f10 allocation failure makes original copy destination invalid");

    const auto old_data = memory.r32(object + 8u);
    if (!old_data)
        throw std::domain_error("0x352f10 contract requires a live old allocation");
    copy_bytes(heap, new_data, old_data, count * 268u);
    const auto free_eax = heap.release(old_data); // original helper 0x36d67b
    memory.w32(object + 8u, new_data);
    memory.w32(object + 4u, new_capacity);
    return set_al(free_eax, 1u);
}

// RVA 0x3542b0 / VA 0x7542b0. Descriptor: [count, capacity, data].
// Unlike the shrinkers, JGE at VA 0x7542bb selects growth; a full array is a
// meaningful resize route. Elements are 248 bytes; new capacity is 2*count.
std::uint32_t fun_007542b0(Memory& memory, const Inputs& inputs, Heap& heap) {
    if (inputs.arithmetic_flags & 0x400u)
        throw std::domain_error("0x3542b0 REP operations require DF clear");
    const auto object = inputs.cx;
    const auto count = memory.r32(object);
    const auto capacity = memory.r32(object + 4u);
    if (count < 6u || count > 20u || capacity != count)
        throw std::domain_error("0x3542b0 contract requires a full array with count=capacity in 6..20");

    const auto new_capacity = count * 2u;
    const auto request = new_capacity * 248u; // (2n*32-2n)*8 = 496n = 248*new_capacity
    const auto new_data = heap.allocate(request); // original helper 0x36d957
    if (!new_data)
        throw std::runtime_error("0x3542b0 allocation failure makes original zero-fill destination invalid");
    zero_bytes(heap, new_data, request); // REP STOSD/STOSB clears the entire new capacity

    const auto old_data = memory.r32(object + 8u);
    if (!old_data)
        throw std::domain_error("0x3542b0 contract requires a live old allocation");
    copy_bytes(heap, new_data, old_data, count * 248u);
    const auto free_eax = heap.release(old_data); // original helper 0x36d67b
    memory.w32(object + 4u, new_capacity);
    memory.w32(object + 8u, new_data);
    return set_al(free_eax, 1u);
}

} // namespace ra2::recovered::recovery_b115
