#include "recovered/recovery_b573.hpp"

#include <stdexcept>

namespace ra2::recovered::recovery_b573 {
namespace {
constexpr std::uint32_t kHashCallback = 0x006814e0u;

// Bounded exact behavior of the actual original callback at VA 0x6814e0,
// independently accepted in B395. The key domain is NUL-terminated ASCII of
// length <= 8; signed byte extension follows MOVSX in the original.
std::uint32_t hash_6814e0(const Memory& m, std::uint32_t node) {
    const auto key = m.r32(node);
    if (!key) return 0;
    std::uint32_t length = 0;
    while (m.r8(key + length) != 0u) {
        if (++length > 8u) throw std::domain_error("B573 key exceeds the accepted callback domain");
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

std::uint32_t resize(Memory& m, const Inputs& in, Heap& heap,
                     std::uint32_t node_next, bool grow) {
    const auto table = in.cx;
    const auto old_count = m.r32(table + 8u);
    const auto old_shift = m.r32(table + 0x0cu);
    const auto old_buckets = m.r32(table);
    if (!old_buckets || m.r32(table + 0x18u) != kHashCallback ||
        m.r8(table + 0x14u) == 1u)
        throw std::domain_error("B573 requires a positive initialized table and authentic callback");
    if (grow) {
        if (old_count != 256u || old_shift != 8u)
            throw std::domain_error("B573 growth requires the initialized 256-bucket state");
    } else if (old_count != 512u || old_shift != 9u || old_count <= m.r32(table + 0x30u)) {
        throw std::domain_error("B573 shrink requires 512 buckets above the table threshold");
    }

    const auto new_count = grow ? old_count * 2u : old_count / 2u;
    const auto new_shift = grow ? old_shift + 1u : old_shift - 1u;
    m.w32(table + 8u, new_count);
    m.w32(table + 0x0cu, new_shift);
    const auto new_buckets = heap.allocate(new_count * 4u);
    if (!new_buckets) throw std::domain_error("B573 success-only fixture excludes allocation failure");
    m.w32(table, new_buckets);
    for (std::uint32_t i = 0; i < new_count; ++i) heap.w32(new_buckets + i * 4u, 0u);

    for (std::uint32_t i = 0; i < old_count; ++i) {
        auto node = heap.r32(old_buckets + i * 4u);
        while (node) {
            const auto next = m.r32(node + node_next);
            const auto bucket = hash_6814e0(m, node) & (new_count - 1u);
            const auto prior_head = heap.r32(new_buckets + bucket * 4u);
            heap.w32(new_buckets + bucket * 4u, node);
            m.w32(node + node_next, prior_head);
            node = next;
        }
    }
    return heap.release(old_buckets);
}
}

std::uint32_t fun_005c60e0(Memory& m,const Inputs& i,Heap& h){return resize(m,i,h,0x8u,true);}
std::uint32_t fun_005c6030(Memory& m,const Inputs& i,Heap& h){return resize(m,i,h,0x8u,false);}
}
