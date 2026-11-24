#include "recovered/recovery_b157.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b157 {
namespace {

// This is the reached null-buffer route of the accepted original RVA 0x10a840.
// Its table target is checked at the real immutable slot before applying the
// callee's writes. With +4==0, the original conditional call to 0x36d67b is
// not reached. No synthetic callback result is supplied.
void run_actual_slot_clear(Memory& memory, std::uint32_t object) {
    const auto vtable = memory.r32(object);
    if (vtable != 0x0078eb5cu || memory.r32(vtable + 0x0cu) != 0x0050a840u)
        throw std::domain_error("Block157 requires the pinned 0x78eb5c table and its original +0xc target");
    if (memory.r32(object + 4u) != 0u)
        throw std::domain_error("Block157 clear route requires a null preexisting destination buffer");

    // Exact reached writes from 0x50a840 after its pointer-zero JZ at 0x50a84b.
    memory.w8(object + 0x0du, 0u);
    memory.w32(object + 8u, 0u);
}

std::uint32_t copy_vector4(Memory& memory, const Inputs& inputs, Heap& heap) {
    const auto destination = inputs.cx;
    const auto source = inputs.arg[0];
    if (!destination || !source || destination == source)
        throw std::domain_error("Block157 requires distinct nonnull source and destination records");

    // Both original roots have the same prologue/branch sequence. The source
    // argument is read before ESI receives ECX; JZ is excluded by this contract.
    run_actual_slot_clear(memory, destination);
    const auto count = memory.r32(source + 8u);
    if (count < 256u || count > 300u)
        throw std::domain_error("Block157 requires a positive count 256..300 for a real >1016-byte heap request");
    const auto source_data = memory.r32(source + 4u);
    if (!source_data)
        throw std::domain_error("Block157 requires a readable source dword array");

    memory.w32(destination + 8u, count);
    const auto request = count * 4u;
    const auto data = heap.allocate(request); // original direct helper RVA 0x36d957
    if (!data)
        throw std::runtime_error("Block157 is success-only; original copy loop cannot accept a null allocation");

    memory.w32(destination + 4u, data);
    memory.w8(destination + 0x0du, 1u);
    for (std::uint32_t index = 0; index < count; ++index)
        heap.w32(data + index * 4u, memory.r32(source_data + index * 4u));

    memory.w32(destination + 0x10u, memory.r32(source + 0x10u));
    memory.w32(destination + 0x14u, memory.r32(source + 0x14u));
    return destination; // Original MOV EAX,ESI; RET 4.
}

} // namespace

// Original RVA 0x10a5b0; see route_screen.json for the exact bounded contract.
std::uint32_t fun_0050a5b0(Memory& m, const Inputs& i, Heap& h) {
    return copy_vector4(m, i, h);
}

// Original RVA 0x249dc0; same behavior, but its original byte range is distinct.
std::uint32_t fun_00649dc0(Memory& m, const Inputs& i, Heap& h) {
    return copy_vector4(m, i, h);
}

} // namespace ra2::recovered::recovery_b157
