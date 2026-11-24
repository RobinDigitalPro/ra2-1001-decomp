#include "recovery_b374.hpp"
#include <stdexcept>

namespace ra2::recovered::recovery_b374 {
namespace {
constexpr std::uint32_t kOwner = 0x00a285c8u;
constexpr std::uint32_t kMode = 0x00a255c8u;
constexpr std::uint32_t kTimestampMode = 0x00a255dcu;
constexpr std::uint32_t kMessageObject = 0x00a1e0e4u;
constexpr std::uint32_t kCounter = 0x00a25890u;
constexpr std::uint32_t kTime = 0x00a2896cu;
constexpr std::uint32_t kValue = 0x00a283c0u;
constexpr std::uint32_t kSendCount = 0x00a9de40u;

void copy_bytes(Memory& m, std::uint32_t dst, const std::uint8_t* src, std::uint32_t n) {
    for (std::uint32_t j = 0; j < n; ++j) m.w8(dst + j, src[j]);
}

std::uint32_t enqueue(Memory& m, std::uint32_t queue,
                      const std::uint8_t* record, std::uint32_t length) {
    const auto capacity = m.r32(queue + 4u);
    const auto used = m.r32(queue + 0x28u);
    if (used >= capacity || length > m.r32(queue + 0x0cu)) return 0;
    const auto slots = m.r32(queue + 0x24u);
    std::uint32_t index = 0;
    while (index < capacity && (m.r8(slots + index * 0x20u) & 1u)) ++index;
    if (index >= capacity) return 0;

    const auto slot = slots + index * 0x20u;
    const auto flags = m.r32(slot);
    m.w32(slot, (flags | 1u) & ~6u);
    m.w32(slot + 4u, 0u);
    m.w32(slot + 8u, 0u);
    m.w32(slot + 0x0cu, 0u);
    m.w32(slot + 0x10u, length);
    const auto payload = m.r32(slot + 0x14u);
    copy_bytes(m, payload, record, length);
    m.w32(slot + 0x18u, 0u);

    const auto indices = m.r32(queue + 0x30u);
    m.w32(indices + used * 4u, index);
    m.w32(queue + 0x2cu, m.r32(queue + 0x2cu) + 1u);
    m.w32(queue + 0x28u, used + 1u);
    return 1u;
}

std::uint32_t peer_append(Memory& m, std::uint32_t peer,
                          const std::uint8_t* packet, std::uint32_t length) {
    if (m.r32(peer + 0x1cu) < length) return 0;
    const auto buffer = m.r32(peer + 0x20u);
    m.w16(buffer, m.r16(peer + 0x24u));
    m.w8(buffer + 2u, 1u);
    m.w32(buffer + 4u, m.r32(peer + 0x3cu));
    // The selected root call supplies optional arg2=0, so byte +3 is retained.
    copy_bytes(m, buffer + 8u, packet, length);
    std::uint8_t framed[22]{};
    for (unsigned j = 0; j != 22; ++j) framed[j] = std::uint8_t(m.r8(buffer + j));
    const auto result = enqueue(m, m.r32(peer + 4u), framed, length + 8u);
    if (result) m.w32(peer + 0x3cu, m.r32(peer + 0x3cu) + 1u);
    return result;
}

std::uint32_t owner_broadcast(Memory& m, std::uint32_t owner,
                              const std::uint8_t* packet, std::uint32_t length,
                              std::uint32_t selector) {
    if (!m.r8(owner + 4u) || !m.r8(owner + 5u)) return 0;
    const auto count = m.r32(owner + 0x44u);
    if (!count) return 0;
    // The recovered path is the original -1 selector plus mode != 4 branch.
    if (selector != 0xffffffffu || m.r32(kMode) == 4u || count != 1u)
        throw std::domain_error("Block374 input outside the finite one-peer route");
    const auto peer = m.r32(owner + 0x28u);
    if (m.r32(peer) != 0x0078f644u)
        throw std::domain_error("Block374 requires the pinned peer vtable");
    const auto queue = m.r32(peer + 4u);
    if (m.r32(queue) != 0x00788db4u)
        throw std::domain_error("Block374 requires the pinned queue layout");
    if (m.r32(queue + 0x28u) >= m.r32(queue + 4u)) return 0;
    (void)peer_append(m, peer, packet, length);
    return 1u;
}
}

std::uint32_t fun_0061de70(Memory& m, const Inputs& i) {
    if (m.r32(kTimestampMode) == 2u)
        throw std::domain_error("Block374 excludes the timestamp-alignment branch");
    if (i.cx != kOwner)
        throw std::domain_error("Block374 requires the pinned A285C8 receiver");
    if (m.r32(i.cx) != 0x0078f6d4u)
        throw std::domain_error("Block374 requires the pinned owner vtable");

    // Original root zeroes the private packet area before filling these fields.
    std::uint8_t packet[14]{};
    packet[0] = 0x19u;
    packet[2] = static_cast<std::uint8_t>(m.r8(m.r32(kMessageObject) + 0x30u));
    const auto timestamp = m.r32(kCounter) + m.r32(kTime);
    for (unsigned j = 0; j != 4; ++j) packet[3u + j] = std::uint8_t(timestamp >> (8u * j));
    const auto value = m.r32(kValue);
    for (unsigned j = 0; j != 4; ++j) packet[7u + j] = std::uint8_t(value >> (8u * j));
    packet[11] = std::uint8_t(i.dx);
    packet[12] = std::uint8_t(i.dx >> 8u);
    packet[13] = std::uint8_t(m.r32(kCounter));

    // The original packet lives on the private caller stack; it is not a guest
    // arena/global write in the externally observed memory image.
    const auto result = owner_broadcast(m, i.cx, packet, 14u, 0xffffffffu);
    (void)result;

    const auto updated = m.r32(kSendCount) + 1u;
    m.w32(kSendCount, updated);
    return updated;
}
}
