#include "recovery_b276.hpp"

#include "recovered/crt_b83.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b276 {
namespace {
constexpr std::uint32_t kRegistryArray = 0x00a1e03cu;
constexpr std::uint32_t kRegistryCount = 0x00a1e048u;
constexpr std::uint32_t kGlobalGate = 0x00a255f3u;
constexpr std::uint32_t kCompareMode = 0x00b10530u;
constexpr std::uint32_t kRandomName = 0x007bceb0u;

std::uint32_t compare(Memory& m, std::uint32_t a, std::uint32_t b) {
    ra2::recovered::global_b26::Inputs args{};
    args.arg[0] = a;
    args.arg[1] = b;
    return ra2::recovered::crt_b83::fun_0076d860(m, args);
}

std::uint32_t house_index(Memory& m, std::uint32_t query) {
    // Direct finite transcription of 0x4f89d0..0x4f8a43. Its comparer call is
    // the already accepted 0x36d860 mode-zero route; no callback substitutes.
    if (compare(m, query, kRandomName) == 0) return 0xfffffffeu;
    if (!query) return 0xffffffffu;
    const auto count = m.r32(kRegistryCount);
    if (ra2::recovered::global_b26::s32(count) <= 0) return 0xffffffffu;
    const auto registry = m.r32(kRegistryArray);
    for (std::uint32_t n = 0; n < count; ++n) {
        const auto house = m.r32(registry + n * 4u);
        if (compare(m, query, house + 0x64u) == 0 ||
            compare(m, query, house + 0x24u) == 0)
            return m.r32(house + 0xb8u);
    }
    return 0xffffffffu;
}

bool bit_set(std::uint32_t word, std::uint32_t shift) {
    // x86 variable shifts mask CL to five bits.
    return (word & (1u << (shift & 31u))) != 0;
}
}

std::uint32_t fun_004eeb00(Memory& m, const Inputs& i) {
    const auto receiver = i.cx;
    const auto manager = m.r32(receiver + 0x34u);
    const auto name = manager + 0x98u;
    const auto house_bit = house_index(m, name);
    const auto candidate_bit = 1u << (house_bit & 31u);

    const auto view = i.arg[0];
    const auto count = m.r32(view + 0x10u);
    // The original stores this count over its saved ECX slot and restores that
    // slot as ECX at epilogue, even for the nonpositive-count branch.
    if (ra2::recovered::global_b26::s32(count) <= 0) return 0u;

    auto cursor = m.r32(view + 4u);
    i.arg[0] = cursor;
    const auto manager_bit_shift = m.r32(manager + 0xb8u);
    const auto manager_id = m.r32(manager + 0xbcu);
    for (std::uint32_t n = 0; n < count; ++n) {
        const auto item = m.r32(cursor);
        bool eligible = (m.r32(item + 0x5e8u) & candidate_bit) != 0;

        const auto first_mask = m.r32(item + 0xb50u);
        if (eligible && first_mask != 0xffffffffu)
            eligible = bit_set(first_mask, manager_bit_shift);

        const auto second_mask = m.r32(item + 0xb54u);
        if (eligible && second_mask != 0xffffffffu)
            eligible = !bit_set(second_mask, manager_bit_shift);

        const auto item_id = m.r32(item + 0x5ecu);
        if (eligible && item_id != 0xffffffffu) eligible = item_id == manager_id;

        if (eligible && m.r8(kGlobalGate) == 0) {
            const auto table_index = m.r32(item + 0x1374u);
            if (table_index != 0xffffffffu) {
                const auto table = m.r32(receiver + 0x1a0u);
                const auto entity = m.r32(table + table_index * 4u);
                const auto descriptor = m.r32(entity + 0x24u);
                eligible = m.r8(descriptor + 0xdfu) == 0;
            }
        }

        if (eligible) return item;
        cursor += 4u;
        i.arg[0] = cursor;
    }
    return 0u;
}
}
