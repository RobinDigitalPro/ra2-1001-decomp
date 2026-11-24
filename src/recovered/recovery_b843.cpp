// Private draft: bounded ordinary-owned destructor-compatible entries only.
#include "recovered/global_b26_memory.hpp"
#include "platform/ordinary_heap.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b843 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;
using Heap = ra2::platform::ordinary_heap::Heap;

namespace {
constexpr std::uint32_t kEntryVptr = 0x78f644u;
constexpr std::uint32_t kEntryBaseVptr = 0x788dccu;

void require(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}

// Exact supported slot-0 route when the nested fields read by 0x481140 are null.
void destroy_entry(Memory& m, Heap& heap, std::uint32_t entry) {
    require(entry != 0u, "0x1243c0 draft excludes null matched entries");
    require(heap.r32(entry) == kEntryVptr, "0x1243c0 draft requires original entry vptr");
    require(heap.r32(entry + 0x20u) == 0u && heap.r32(entry + 4u) == 0u,
            "0x1243c0 draft excludes nested 0x481140 destructor/free paths");

    // 0x523260 installs its own vptr and calls 0x481140, which installs 0x788dcc.
    // The helper calls 0x76d67b with null +0x20; pinned 0x36df28 returns before
    // lock/heap access on null. Its +0x04 child dispatch is likewise skipped.
    // The outer bit-0 delete dispatch then reaches the real ordinary HeapFree.
    require(m.r32(kEntryVptr)==0x523260u,"843 exact original destructor slot");
    heap.w32(entry, kEntryVptr);
    heap.w32(entry, kEntryBaseVptr);
    require(heap.release(entry) != 0u, "0x1243c0 draft requires successful real heap release");
}
} // namespace

std::uint32_t fun_005243c0(Memory& m, const Inputs& i, Heap& heap) {
    const auto manager = i.cx;
    if (m.r8(manager + 4u) == 0u) return 0u;

    const auto count = m.r32(manager + 0x44u);
    require(count <= 7u, "0x1243c0 draft bounds manager count to seven entries");
    if (count == 0u) return 0u;

    const auto wanted = i.arg[0];
    std::uint32_t index = 0u;
    for (; index < count; ++index) {
        const auto entry = m.r32(manager + 0x28u + index * 4u);
        require(entry != 0u, "0x1243c0 draft excludes null array entries");
        if (heap.r32(entry + 0x60u) == wanted) break;
    }
    if (index == count) return 0u;

    const auto slot = manager + 0x28u + index * 4u;
    const auto entry = m.r32(slot);
    destroy_entry(m, heap, entry);

    const auto new_count = count - 1u;
    for (auto n = index; n < new_count; ++n)
        m.w32(manager + 0x28u + n * 4u, m.r32(manager + 0x2cu + n * 4u));
    m.w32(manager + 0x44u, new_count);
    if (m.r32(manager + 0x54u) >= new_count)
        m.w32(manager + 0x54u, 0u);
    return 1u;
}
} // namespace ra2::recovered::recovery_b843
