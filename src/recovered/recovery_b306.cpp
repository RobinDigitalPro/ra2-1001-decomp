#include "recovery_b306.hpp"

#include <stdexcept>

namespace ra2::recovery_b306 {
namespace {
void require(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}
}

std::uint32_t fun_00629300(Memory& memory, MixedHeap& heap,
                           EntryState& entry) {
    const auto receiver = entry.cx;
    require(receiver != 0, "229300 positive route requires a mapped receiver");
    require(std::uint64_t(receiver) + 0x1258u <= 0x100000000ull,
            "229300 fixture receiver span must not wrap");

    // 0x629306..0x629315: first call through the original operator new.
    const auto child = heap.allocate(0x10u);
    require(child != 0, "229300 positive route excludes first-allocation failure");

    // 0x62932b..0x629339: the child header is initialized before request two.
    heap.w32(child + 0x04u, 0x006292e0u);
    heap.w32(child + 0x08u, 0x00000100u);
    heap.w32(child + 0x0cu, 0x0000000au);

    // 0x629326 / 0x62933c: original operator new receives 0x1804. The
    // accepted allocator sees the 1016-byte cutoff and calls HeapAlloc(1810h).
    const auto ordinary = heap.allocate(0x1804u);
    require(ordinary != 0, "229300 positive route excludes second-allocation failure");
    require(std::uint64_t(ordinary) + 0x1810u <= 0x100000000ull,
            "229300 ordinary allocation extent must not wrap");

    // 0x629348..0x62937c: raw base header then exactly 256 records, stride 24.
    heap.w32(ordinary, 0x00000100u);
    const auto rows = ordinary + 4u;
    for (std::uint32_t index = 0; index != 0x100u; ++index) {
        const auto row = rows + index * 0x18u;
        heap.w32(row + 0x04u, 0u);
        heap.w32(row + 0x08u, 0u);
        heap.w8(row + 0x0cu, 1u);
        heap.w8(row + 0x0du, 0u);
        heap.w32(row + 0x00u, 0x007937e4u);
        heap.w32(row + 0x00u, 0x007937c4u);
        heap.w32(row + 0x14u, 0x0au);
        heap.w32(row + 0x10u, 0u);
    }

    // 0x629388..0x6293a4 publishes rows at child+0 and repeats +0x14=10
    // for all records. Preserve the original second write pass explicitly.
    heap.w32(child + 0x00u, rows);
    for (std::uint32_t index = 0; index != 0x100u; ++index)
        heap.w32(rows + index * 0x18u + 0x14u, 0x0au);

    // 0x6293a4 is the only receiver write. The target has no stack arguments,
    // does not change caller words, restores its pushed registers and returns
    // the loop's complete EAX value 0x100 with RET 0.
    memory.w32(receiver + 0x1254u, child);
    entry.ax = 0x00000100u;
    // Volatile ECX/EDX and arithmetic flags are outside this finite output contract.
    return entry.ax;
}

} // namespace ra2::recovery_b306
