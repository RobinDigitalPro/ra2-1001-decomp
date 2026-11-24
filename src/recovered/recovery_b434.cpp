#include "recovered/recovery_b434.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b434 {
namespace {
constexpr std::uint32_t kNodeNext = 0x308u;
constexpr std::uint32_t kHashCallback = 0x006814e0u;

// Exact positive closure for the original callback. Its original body calls
// original strlen (0x35a0e0) and data() (0x35a030); the node's first dword is
// the bounded key pointer. MOVSX makes bytes signed in the accumulation.
std::uint32_t hash_6814e0(const Memory& m, std::uint32_t node) {
    const auto key = m.r32(node);
    if (!key) return 0;
    std::uint32_t length = 0;
    while (m.r8(key + length) != 0u) {
        if (++length > 8u)
            throw std::domain_error("B434 key exceeds the accepted eight-byte string domain");
    }
    std::uint32_t value = length;
    for (std::uint32_t i = 0; i < length; ++i) {
        const auto byte = m.r8(key + i);
        const auto signed_byte = (byte & 0x80u) ? byte | 0xffffff00u : byte;
        value += signed_byte + i;
        value = (value << 8u) ^ (value >> 24u);
    }
    return value;
}
}

std::uint32_t fun_00682ee0(Memory& m, const Inputs& in, Heap& heap) {
    const auto table = in.cx;
    const auto old_count = m.r32(table + 8u);
    const auto high_water = m.r32(table + 0x30u);
    if (old_count <= high_water)
        throw std::domain_error("B434 positive shrink fixture requires count above constructor high-water");
    if (m.r8(table + 0x14u) == 1u)
        throw std::domain_error("B434 positive shrink route excludes status-byte==1 shortcut");
    if (m.r32(table + 0x18u) != kHashCallback)
        throw std::domain_error("B434 requires constructor-proven callback 0x6814e0");

    const auto old_buckets = m.r32(table);
    const auto old_shift = m.r32(table + 0x0cu);
    if (!old_buckets || old_count != 512u || old_shift != 9u)
        throw std::domain_error("B434 requires initialized 512-bucket shift-9 prestate");

    const auto new_count = old_count / 2u;
    const auto new_shift = old_shift - 1u;
    m.w32(table + 8u, new_count);
    m.w32(table + 0x0cu, new_shift);
    const auto new_buckets = heap.allocate(new_count * 4u); // original 0x76d957
    if (!new_buckets)
        throw std::domain_error("B434 success-only fixture excludes failed HeapAlloc");
    m.w32(table, new_buckets);
    for (std::uint32_t i = 0; i < new_count; ++i)
        heap.w32(new_buckets + i * 4u, 0u); // original REP STOSD

    for (std::uint32_t i = 0; i < old_count; ++i) {
        auto node = heap.r32(old_buckets + i * 4u);
        while (node) {
            const auto next = m.r32(node + kNodeNext);
            const auto bucket = hash_6814e0(m, node) & (new_count - 1u);
            const auto prior_head = heap.r32(new_buckets + bucket * 4u);
            heap.w32(new_buckets + bucket * 4u, node);
            m.w32(node + kNodeNext, prior_head);
            node = next;
        }
    }
    return heap.release(old_buckets); // exact original HeapFree BOOL in EAX
}
} // namespace ra2::recovered::recovery_b434
