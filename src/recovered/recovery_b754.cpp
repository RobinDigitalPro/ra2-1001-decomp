#include "recovery_b754.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::heap754 {
namespace {
constexpr std::uint32_t kThreshold = 0x00817554u;
constexpr std::uint32_t kHeapHandle = 0x00b10e1cu;
constexpr std::uint32_t kBucketTable = 0x00b10e18u;
constexpr std::uint32_t kBucketCount = 0x00b10e14u;
constexpr std::uint32_t kLockSlot = 0x00817278u + 9u * 4u;

std::uint32_t checked_round(std::uint32_t bytes) {
    const std::uint64_t rounded = (std::uint64_t(bytes) + 15u) & ~std::uint64_t(15u);
    if (rounded > 0xfffffff0ull) throw std::domain_error("B754 request rounding overflow is outside the route");
    return static_cast<std::uint32_t>(rounded);
}

std::uint32_t find_bucket(Memory& m, const Inputs& i) {
    for (const auto& entry : ra2::recovered::global_b26::entries_c()) {
        if (entry.rva == 0x0037337du) return entry.function(m, i);
    }
    throw std::logic_error("B754 accepted 0x37337d helper is unavailable");
}
}

// Positive large-buffer resize route of original 0x00374b05. The finite
// contract starts with a live nonnull block from the supplied real heap, an
// initialized real lock in table slot 9, an empty small-bucket list, and a
// request above the initialized small-block threshold. Original 0x37337d is
// executed and returns zero for that empty list; the original root stores this
// value into caller word 1 at RVA 0x374b4e. With nonzero slot 9, accepted
// 0x3715b6 takes its direct real-EnterCriticalSection branch and skips its
// allocator/recursive initialization path. The root releases lock 9 and
// forwards HeapReAlloc(heap, 0, block, round16(request)); successful API
// identity and preserved old payload are verified by the platform observer.
// Null/zero requests, small buckets, HeapAlloc fallback, retries, allocation
// failure, and uninitialized lock/heap states are outside this contract.
std::uint32_t rva_00374b05(Memory& m, const Inputs& i, Operations& op) {
    const auto block = i.arg[0];
    const auto requested = i.arg[1];
    const auto heap = m.r32(kHeapHandle);
    const auto lock = m.r32(kLockSlot);

    if (!block || !requested || requested <= m.r32(kThreshold))
        throw std::domain_error("B754 requires a nonnull block and request above the small-block threshold");
    if (!heap || !lock) throw std::domain_error("B754 requires initialized ordinary heap and lock slot 9");
    if (m.r32(kBucketCount) != 0 || m.r32(kBucketTable) != 0)
        throw std::domain_error("B754 contract requires the original empty small-bucket table");

    op.enter_critical_section(lock);
    const auto found = find_bucket(m, i);
    i.arg[1] = found; // Original MOV [EBP+0x0c],EAX at RVA 0x374b4e.
    if (found != 0) {
        op.leave_critical_section(lock);
        throw std::domain_error("B754 empty-bucket lookup unexpectedly found a block");
    }
    op.leave_critical_section(lock);

    const auto rounded = checked_round(requested);
    const auto result = op.heap_realloc(heap, 0, block, rounded);
    if (!result) throw std::domain_error("B754 contract covers successful HeapReAlloc only");
    return result;
}
}
