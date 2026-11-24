#include "recovered/recovery_b135.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b135 {
namespace {
constexpr std::uint32_t manager_array = 0x00a5e1acu;
constexpr std::uint32_t manager_capacity = 0x00a5e1b0u;
constexpr std::uint32_t manager_flag = 0x00a5e1b5u;
constexpr std::uint32_t manager_count = 0x00a5e1b8u;
constexpr std::uint32_t manager_increment = 0x00a5e1bcu;
constexpr std::uint32_t copied_bytes = 111u;
}

// Mirrors the bounded original route at VA 0x60bf34..0x60bfba. The allocation
// is the real 111-byte first-small-block route. On allocation failure, the
// original continues into REP MOVS through a null destination; that faulting
// behavior is excluded by requiring a successful real allocation here.
std::uint32_t fun_0060bf30(Memory& m, const Inputs& i, Heap& heap) {
    const auto object = heap.allocate(copied_bytes); // original CALL VA 0x76d957
    if (object == 0)
        throw std::domain_error("0x20bf30 bounded route requires successful original small allocation");

    heap.w8(object, 0u); // MOV byte ptr [EAX],0 before the 111-byte copy
    for (std::uint32_t offset = 0; offset < copied_bytes; ++offset)
        heap.w8(object + offset, static_cast<std::uint8_t>(m.r8(i.cx + offset)));

    if (heap.r8(object) == 4u)
        heap.w8(object + 0x1du, 2u);

    const auto capacity = m.r32(manager_capacity);
    const auto count = m.r32(manager_count);
    if (static_cast<std::int32_t>(count) < static_cast<std::int32_t>(capacity)) {
        // The original JL at VA 0x60bf70 takes this branch without reading or
        // dispatching through the manager vtable.
        m.w32(manager_count, count + 1u);
        const auto array = m.r32(manager_array);
        m.w32(array + count * 4u, object);
        return count; // original full EAX is the old count; RET 0
    }

    // The second supported state is the actual zeroed BSS. EAX retains the
    // capacity (zero) through the flag/capacity/increment guards, so the body
    // performs its allocation/copy but does not publish it and returns zero.
    if (capacity == 0u && count == 0u && m.r8(manager_flag) == 0u &&
        m.r32(manager_increment) == 0u)
        return capacity;

    // Other full-capacity states can reach the original indirect call at
    // VA 0x60bf99. They are outside this contract rather than mocked here.
    throw std::domain_error("0x20bf30 state outside zero-BSS and spare-capacity routes");
}
}
