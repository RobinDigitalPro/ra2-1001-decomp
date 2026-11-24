// Private Block183 proposal only; no shared-source mutation.
#include "recovery_b183.hpp"



#include <stdexcept>

namespace ra2::recovered::recovery_b183 {
namespace {
constexpr std::uint32_t kManager = 0x00ab8298u;
constexpr std::uint32_t kCount = 0x00ab82a8u;
constexpr std::uint32_t kListCell = 0x00ab829cu;
constexpr std::uint32_t kPinnedVptr = 0x0079981cu;
constexpr std::uint32_t kFindTarget = 0x00709b80u;



// Literal translation of the original 0x709b80 (38-byte) reached target.
// The constructor-proven vptr selects this body through slot +0x10; no test
// callback return is substituted.
std::uint32_t find_item(Memory& m, std::uint32_t item) {
    const auto count = m.r32(kCount);
    std::uint32_t index = 0;
    if (global_b26::s32(count) <= 0) return 0xffffffffu;
    auto cursor = m.r32(kListCell);
    while (global_b26::s32(index) < global_b26::s32(count)) {
        if (m.r32(cursor) == item) return index;
        ++index;
        cursor += 4u;
    }
    return 0xffffffffu;
}
} // namespace

std::uint32_t fun_00709420(Memory& m, const Inputs&, Heap& heap) {
    auto count = m.r32(kCount);
    if (global_b26::s32(count) <= 0) {
        // The bounded contract does not cover global linked-list teardown.
        if (m.r32(0x00ab82c4u) != 0)
            throw std::domain_error("Block183 excludes nonempty linked-list teardown");
        return 0;
    }
    if (count != 1u)
        throw std::domain_error("Block183 covers one positive manager entry");

    const auto table = m.r32(kListCell);
    const auto item = m.r32(table);
    const auto vptr = m.r32(kManager);
    if (vptr != kPinnedVptr || m.r32(vptr + 0x10u) != kFindTarget)
        throw std::domain_error("Block183 requires constructor-proven vptr and authentic +0x10 target");
    const auto found = find_item(m, item);
    if (found == 0xffffffffu || found >= count)
        throw std::domain_error("Block183 fixture must take actual positive lookup branch");

    // At VA 0x70945c, count is decremented before the last-item check. With
    // one entry, found index 0 is now >= new count 0, so the original skips
    // shifting and proceeds to release this actual live ordinary-heap block.
    --count;
    m.w32(kCount, count);
    (void)heap.release(item); // actual original ordinary CRT release path

    // Original reloads the now-zero count, skips the array loop, sees the
    // pinned-zero AB82C4 link, and returns with EAX=0 after restoring ECX.
    if (m.r32(kCount) != 0 || m.r32(0x00ab82c4u) != 0)
        throw std::domain_error("Block183 expected exhausted array and null linked-list head");
    return 0;
}
} // namespace ra2::recovered::recovery_b183
