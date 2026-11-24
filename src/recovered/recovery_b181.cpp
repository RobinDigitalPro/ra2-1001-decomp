#include "recovery_b181.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b181 {
namespace {
using global_b26::Inputs;
using global_b26::Memory;

struct Registry {
    std::uint32_t object;
    std::uint32_t count;
    std::uint32_t table;
    std::uint32_t initialized_vptr;
    std::uint32_t expected_method_va;
};

// The original vtable targets 0x40cdf0 and 0x4cde40 have identical bounded
// code: read count at this+0x10 and table at this+4, compare *arg0 against
// table[0..count), return the first index or -1, RET 4. This models those
// instructions directly; it does not substitute a callback return.
std::int32_t original_pointer_search(Memory& m, const Registry& r,
                                     std::uint32_t needle) {
    const auto vptr=m.r32(r.object);
    if (vptr != r.initialized_vptr)
        throw std::domain_error("Block181 manager vptr is not initializer-proven");
    const auto method=m.r32(vptr+0x10u);
    if (method != r.expected_method_va ||
        (method != 0x0040cdf0u && method != 0x004cde40u))
        throw std::domain_error("Block181 vtable slot +0x10 is outside the proven methods");
    const auto count = m.r32(r.count);
    if (static_cast<std::int32_t>(count) <= 0) return -1;
    if (count > 8u) throw std::domain_error("Block181 search count exceeds fixture bound");
    const auto table = m.r32(r.table);
    if (!table) throw std::domain_error("Block181 nonempty manager has null table");
    for (std::uint32_t i = 0; i < count; ++i)
        if (m.r32(table + i * 4u) == needle)
            return static_cast<std::int32_t>(i);
    return -1;
}

void original_remove_first(Memory& m, const Registry& r, std::uint32_t receiver) {
    const auto index = original_pointer_search(m, r, receiver);
    if (index == -1) return;
    const auto old_count = m.r32(r.count);
    if (static_cast<std::uint32_t>(index) >= old_count) return;
    const auto new_count = old_count - 1u;
    // Original order: decrement/store count first; then shift only if index is
    // before new last index. The now-unused last slot remains stale and visible.
    m.w32(r.count, new_count);
    if (static_cast<std::uint32_t>(index) < new_count) {
        const auto table=m.r32(r.table);
        for (auto i = static_cast<std::uint32_t>(index); i < new_count; ++i)
            m.w32(table + i * 4u, m.r32(table + (i + 1u) * 4u));
    }
}

void clear_embedded_405d50_early(Memory& m, std::uint32_t object) {
    // In this contract [0x8192f8]==0, so original 0x405d50 takes JZ 0x405e81.
    // Its only store on that path is [object+8]=0; [object] is preserved.
    if (m.r32(0x008192f8u) != 0)
        throw std::domain_error("Block181 requires the verified 0x405d50 early route");
    // Kept local instead of calling the historical accepted C++ adapter: its
    // prior scope did not model this zero-global early branch's +8 store.
    m.w32(object + 8u, 0);
}

void clear_embedded_405c10_early(Memory& m, std::uint32_t object) {
    // In this contract [0x8192f8]==0, so original 0x405c10 takes JZ 0x405d41.
    // It writes +8 and +0xc, preserving [object].
    if (m.r32(0x008192f8u) != 0)
        throw std::domain_error("Block181 requires the verified 0x405c10 early route");
    m.w32(object + 8u, 0);
    m.w32(object + 0xcu, 0);
}

void remove_from_manager_registries(Memory& m, std::uint32_t receiver) {
    // Authentic object vptrs are those written by their original initializer
    // functions. The manager-array contents are bounded synthetic state.
    constexpr std::array<Registry, 5> registries{{
        {0x00aa87e0u, 0x00aa87f0u, 0x00aa87e4u, 0x0078c77cu, 0x004cde40u},
        {0x00a27fb8u, 0x00a27fc8u, 0x00a27fbcu, 0x00788b7cu, 0x0040cdf0u},
        {0x00aa8868u, 0x00aa8878u, 0x00aa886cu, 0x0078c77cu, 0x004cde40u},
        {0x00aa87b8u, 0x00aa87c8u, 0x00aa87bcu, 0x0078c77cu, 0x004cde40u},
        {0x00aa8760u, 0x00aa8770u, 0x00aa8764u, 0x0078c77cu, 0x004cde40u},
    }};
    for (const auto& registry : registries)
        original_remove_first(m, registry, receiver);
}

void fun_005cabc0(Memory& m, std::uint32_t receiver) {
    // Direct receiver-vtable writes before five authentic manager lookups.
    m.w32(receiver + 0x00u, 0x00792458u);
    m.w32(receiver + 0x04u, 0x0079243cu);
    m.w32(receiver + 0x08u, 0x00792434u);
    m.w32(receiver + 0x0cu, 0x0079242cu);
    remove_from_manager_registries(m, receiver);

    m.w32(receiver + 0x30u, 0);
    m.w8(receiver + 0x7du, 0);
    clear_embedded_405d50_early(m, receiver + 0x3cu);
    clear_embedded_405d50_early(m, receiver + 0x50u);
    clear_embedded_405c10_early(m, receiver + 0x3cu);
    clear_embedded_405c10_early(m, receiver + 0x50u);

    // The optional 0x5376d0 release is unreachable for +0x94 == 0.
    if (m.r32(receiver + 0x94u) != 0)
        throw std::domain_error("Block181 requires receiver+0x94 zero to skip release");
    m.w32(receiver + 0x00u, 0x00785dd8u);
    m.w32(receiver + 0x04u, 0x00785dbcu);
    m.w32(receiver + 0x08u, 0x00785db4u);
    m.w32(receiver + 0x0cu, 0x00785dacu);
}
}

std::uint32_t fun_0062e530(Memory& m, const Inputs& i) {
    const auto receiver = i.cx;
    // Original conditionals select a route with neither free reachable:
    // receiver+0xcc is zero, caller arg0 is even, and optional +0x94 is zero.
    if (m.r32(receiver + 0xccu) != 0 || (i.arg[0] & 1u) != 0 ||
        m.r32(receiver + 0x94u) != 0 || m.r32(0x008192f8u) != 0)
        throw std::domain_error("Block181 input is outside the bounded no-free route");

    // Exact root store order, including the intermediate vptr generation that
    // is subsequently replaced by 0x62e592 and then by 0x5cabc0 / 0x40ff90.
    m.w32(receiver + 0x00u, 0x007938a8u);
    m.w32(receiver + 0x04u, 0x0079388cu);
    m.w32(receiver + 0x08u, 0x00793884u);
    m.w32(receiver + 0x0cu, 0x0079387cu);
    m.w32(receiver + 0xc8u, 0x007857fcu);
    m.w8(receiver + 0xd5u, 0);
    m.w32(receiver + 0xd0u, 0);
    m.w32(receiver + 0x00u, 0x007911e8u);
    m.w32(receiver + 0x04u, 0x007911ccu);
    m.w32(receiver + 0x08u, 0x007911c4u);
    m.w32(receiver + 0x0cu, 0x007911bcu);
    fun_005cabc0(m, receiver);
    return receiver; // MOV EAX,ESI; POP ESI; RET 4
}
}
