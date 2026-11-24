#include "recovered/recovery_b133.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b133 {
namespace {
void require(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}
}

// The original computes new capacity as old_capacity + signed N, allocates
// eight bytes per capacity slot, copies old_count entries, releases old storage,
// publishes the new pointer/capacity, clears +0x10, then returns with MOV AL,1.
// This supported state starts empty, so the copy loop and nonnull free path are
// unreachable. N>=128 forces a request >=1024, above the unimplemented CRT
// small-block route and inside the real ordinary-heap adapter's domain.
std::uint32_t fun_0041b900(Memory& m, const Inputs& i, Heap& heap) {
    const auto receiver = i.cx;
    const auto requested = i.arg[0]; // caller stack [entryESP+4]
    require(receiver != 0, "0x1b900 requires a mapped caller-owned vector header");
    require(requested >= 128u && requested <= 191u,
            "0x1b900 finite reserve requires 128..191 slots");
    require(m.r32(receiver) == 0 && m.r32(receiver + 4u) == 0 &&
            m.r32(receiver + 8u) == 0,
            "0x1b900 finite reserve requires null pointer, zero count and capacity");

    const auto new_capacity = requested;
    const auto request_bytes = new_capacity * 8u;
    const auto allocation = heap.allocate(request_bytes);
    if (allocation == 0)
        throw std::domain_error("0x1b900 bounded route requires successful allocation");

    i.arg[0] = new_capacity - 1u; // original caller-visible store at VA41b92f

    // The original's release wrapper receives the prior null pointer. Its exact
    // CRT helper takes the null guard and performs no OS free; Heap::release
    // deliberately only accepts tracked nonnull allocations, so there is no
    // observable Heap operation to issue here.
    m.w32(receiver, allocation);
    m.w32(receiver + 8u, new_capacity);
    m.w32(receiver + 0x10u, 0u);

    // Capacity is at most 191 in the finite route. This preserves all EAX bits
    // after the original ADD and low-byte-only MOV AL,1 sequence.
    return (new_capacity & 0xffffff00u) | 1u;
}

} // namespace ra2::recovered::recovery_b133
