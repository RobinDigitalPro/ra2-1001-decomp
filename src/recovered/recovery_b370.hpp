#pragma once
#include "global_b26_memory.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b370 {
using Memory = ra2::recovered::global_b26::Memory;
using Inputs = ra2::recovered::global_b26::Inputs;

namespace detail {
inline void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}
inline constexpr std::array<std::uint32_t, 8> kChannelGlobals{
    0x00819794u, 0x00819798u, 0x00819790u, 0x0081978cu,
    0x008197a4u, 0x008197a8u, 0x008197a0u, 0x0081979cu
};

// RVA 0x1080 -> 0x70f0 for the branch selected here. Each of the three
// 12-byte vector records has bit 0 set and unequal current/end words, so the
// original takes the no-allocation state-advance branch and sets bit 1.
inline void advance_triplet(Memory& m, std::uint32_t object) {
    for (const auto offset : {0u, 0x28u, 0x50u}) {
        const auto base = object + offset;
        const auto flags = m.r32(base);
        const auto current = m.r32(base + 4u);
        const auto end = m.r32(base + 8u);
        need((flags & 1u) != 0u && current != end,
             "370 route requires the original bit-0/nonempty vector branch");
        m.w32(base + 4u, end);
        m.w32(base, flags | 2u);
    }
}
inline void clear_triplet_pending(Memory& m, std::uint32_t object) {
    for (const auto offset : {0u, 0x28u, 0x50u}) {
        const auto base = object + offset;
        m.w32(base, m.r32(base) & 0xfffffffdu);
    }
}
inline bool has_pending_triplet(const Memory& m, std::uint32_t object) {
    for (const auto offset : {0u, 0x28u, 0x50u})
        if ((m.r8(object + offset) & 2u) != 0u) return true;
    return false;
}

// RVA 0x402f60 callback, only the finite timestamp/empty-queue branch. The
// external 0x4092d0 clock shim is closed by its exact zero-global fallback.
inline void callback_tick(Memory& m, std::uint32_t manager) {
    need(m.r32(manager + 0x104u) == 0u, "370 callback requires no in-flight callback");
    need(m.r32(manager + 0x0e8u) == 0u, "370 callback requires optional channel null");
    need(m.r32(manager + 0x0f8u) == manager + 0x0f8u,
         "370 callback requires the initialized empty queue sentinel");
    need(m.r32(manager + 0x110u) == 0u && m.r32(manager + 0x114u) == 0u &&
         m.r32(manager + 0x118u) == 0xa5u && m.r32(manager + 0x11cu) == 0u &&
         m.r32(manager + 0x128u) == 0u && m.r32(manager + 0x12cu) == 0u &&
         m.r32(manager + 0x130u) == 0xa5u && m.r32(manager + 0x134u) == 0u &&
         m.r32(manager + 0x138u) == 0u && m.r32(manager + 0x13cu) == 0u &&
         m.r32(manager + 0x140u) == 0u && m.r32(manager + 0x144u) == 0u,
         "370 callback requires zero clock thresholds/history for the equal-time route");
    need(m.r32(0x00819898u) == 0u,
         "370 callback requires exact 0x4092d0 zero-global fallback");

    // The original callback updates its elapsed time, tick count, and last
    // timestamp after the equal-time 64-bit comparisons.
    m.w32(manager + 0x120u, 0u);
    m.w32(manager + 0x124u, 0u);
    m.w32(manager + 0x158u, m.r32(manager + 0x158u) + 1u);
    m.w32(manager + 0x138u, 0u);
    m.w32(manager + 0x13cu, 0u);

    const auto inline_channel = manager + 0x68u;
    advance_triplet(m, inline_channel);
    // RVA 0x10a0 reads the three one-byte flags and returns one. With the
    // initialized empty queue this saved result is not consumed by an item.
    need(has_pending_triplet(m, inline_channel),
         "370 callback requires the original 0x10a0 pending-flag result");
    // The finite caller state supplies a null optional channel and a self-linked
    // queue sentinel. The callback therefore reaches its real cleanup call.
    clear_triplet_pending(m, inline_channel);
}
} // namespace detail

// RVA 0x00a8c0. Positive receiver path only. Full EAX is 0xfffffffd, left by
// the last original 0x1170 call; the function has no caller stack arguments.
inline std::uint32_t fun_0040a8c0(Memory& m, const Inputs& in) {
    const auto manager = in.cx;
    detail::need(manager != 0u, "370 excludes the original null-receiver early return");
    detail::need(m.r32(manager + 0x10cu) == 0x00402f60u,
                 "370 requires the callback installed by original constructor RVA 0x2c70");

    std::array<std::uint32_t, 8> channels{};
    for (std::size_t i = 0; i != detail::kChannelGlobals.size(); ++i) {
        channels[i] = m.r32(detail::kChannelGlobals[i]);
        detail::need(channels[i] != 0u, "370 requires eight initialized global channel objects");
        detail::advance_triplet(m, channels[i]);
    }

    detail::callback_tick(m, manager);
    for (const auto channel : channels)
        detail::clear_triplet_pending(m, channel);
    return 0xfffffffdu;
}
} // namespace ra2::recovered::recovery_b370
