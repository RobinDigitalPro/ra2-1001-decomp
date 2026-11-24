#include "recovered/recovery_b1449.hpp"
#include "recovered/recovery_b1446.hpp"
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::b1449 {
namespace {
constexpr std::uint32_t kActorRegistry = 0x00a28738u;
constexpr std::uint32_t kActorBuffer = 0x00a2873cu;
constexpr std::uint32_t kActorCapacity = 0x00a28740u;
constexpr std::uint32_t kActorCount = 0x00a28748u;
constexpr std::uint32_t kChecksum = 0x00a5e7ccu;
constexpr std::uint32_t kOwnerGlobal = 0x00a255c0u;

std::uint32_t leaf_0062fde0_first_draw(Memory& m, std::uint32_t state) {
    // The selected original 81-byte leaf, on the already-seeded state only.
    if (m.r8(state) != 0u)
        throw std::domain_error("B1449 requires enabled original RNG state");
    const auto i = m.r32(state + 4u);
    const auto j = m.r32(state + 8u);
    if (i >= 250u || j >= 250u)
        throw std::domain_error("B1449 RNG cursors exceed the pinned seed-zero table");
    const auto table = state + 12u;
    const auto next = m.r32(table + 4u * i) ^ m.r32(table + 4u * j);
    m.w32(table + 4u * i, next);
    const auto ni = i + 1u;
    const auto nj = j + 1u;
    m.w32(state + 4u, ni >= 250u ? 0u : ni);
    m.w32(state + 8u, nj >= 250u ? 0u : nj);
    return next;
}

void getter_004b8850_rate_zero(Memory& m, std::uint32_t object, std::uint32_t& local_output) {
    // Exact selected branch of the pinned 153-byte getter. At signed WORD
    // rate/count +14 == 0, its complete behavior is output = DWORD [object].
    if (static_cast<std::int16_t>(m.r16(object + 0x14u)) != 0)
        throw std::domain_error("B1449 only models the original rate-zero getter branch");
    local_output = m.r32(object);
}

std::int32_t trunc_div10(std::uint32_t value) {
    return static_cast<std::int32_t>(value) / 10;
}
}

std::uint32_t fun_006217d0(Memory& m, const Inputs& input) {
    // Finite positive route: one authentic A28738 actor entry; the other
    // root-read registries and all five 83A8A8 layer counts are empty.
    if (m.r32(0x00a1e188u) != 0u || m.r32(0x0084e4d8u) != 0u ||
        m.r32(0x0081a7c0u) != 0u)
        throw std::domain_error("B1449 supports only the reviewed empty-root-registry projection");
    constexpr std::uint32_t layer_counts[]{0x0083a8b8u,0x0083a8d0u,0x0083a8e8u,0x0083a900u,0x0083a918u};
    for (const auto address : layer_counts)
        if (m.r32(address) != 0u)
            throw std::domain_error("B1449 requires all five original layer counts empty");

    if (m.r32(kActorRegistry) != 0x0078d364u ||
        m.r32(kActorBuffer) == 0u || m.r32(kActorCapacity) < 1u ||
        m.r8(kActorRegistry + 0x0cu) != 1u || m.r8(kActorRegistry + 0x0du) != 0u ||
        m.r32(kActorCount) != 1u || m.r32(kActorRegistry + 0x14u) != 10u)
        throw std::domain_error("B1449 requires one initialized A28738 registry entry");
    const auto actor_list = m.r32(kActorBuffer);
    const auto actor = m.r32(actor_list);
    if (actor == 0u || m.r32(actor) != 0x00787bbcu)
        throw std::domain_error("B1449 requires the reviewed primary actor record layout");
    const auto x = m.r32(actor + 0x88u);
    const auto y = m.r32(actor + 0x8cu);
    const auto z = m.r32(actor + 0x90u);
    if (x != 0u || y != 0u || z != 0u)
        throw std::domain_error("B1449 route is limited to the constructor-produced XYZ zero projection");

    // Genuine setters have already produced full current=0x4000 and rate=0
    // in the actor's +2E0 descriptor. The getter writes only its private local.
    const auto descriptor = actor + 0x2e0u;
    std::uint32_t getter_local = 0u;
    getter_004b8850_rate_zero(m, descriptor, getter_local);
    const auto current = getter_local;
    if (current != 0x00004000u)
        throw std::domain_error("B1449 requires the genuine orientation-64 current DWORD");

    m.w32(kChecksum, 0u); // exact original entry store at 0x6217D8
    const auto contribution = (((current >> 7u) + 1u) >> 1u) & 0xffu;
    const auto sum = (static_cast<std::uint32_t>(trunc_div10(y)) << 16u) +
                     static_cast<std::uint32_t>(trunc_div10(x)) + contribution;
    auto checksum = sum; // original recurrence is 2*old + term; old is zero here
    m.w32(kChecksum, checksum);

    const auto owner = m.r32(kOwnerGlobal);
    if (owner == 0u)
        throw std::domain_error("B1449 requires the genuine seed-zero owner projection");
    const auto state = owner + 0x218u;
    if (m.r8(state) != 0u || m.r32(state + 4u) != 1u || m.r32(state + 8u) != 104u)
        throw std::domain_error("B1449 requires exactly one original constructor draw after seed zero");
    const auto q1 = leaf_0062fde0_first_draw(m, state);
    checksum = checksum * 2u + q1;
    m.w32(kChecksum, checksum);

    // The unchanged accepted B1446 root performs the second draw and
    // publishes Q2 to A93838. Its returned full DWORD is B1449's EAX.
    return ra2::recovered::b1446::fun_00624770(m, input);
}
}

