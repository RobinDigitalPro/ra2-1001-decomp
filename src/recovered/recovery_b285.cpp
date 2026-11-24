#include "recovery_b285.hpp"
#include "recovered/crt_b83.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b285 {
namespace {
constexpr std::uint32_t registry_count = 0x0084e4f0u;
constexpr std::uint32_t registry_table = 0x0084e4e4u;
constexpr std::uint32_t registry_gate = 0x00a283c4u;
constexpr std::uint32_t conflict_gate = 0x00a255c8u;
constexpr std::uint32_t scan_count = 0x00a1a5d8u;
constexpr std::uint32_t scan_table = 0x00a1a5ccu;
constexpr std::uint32_t mode = 0x00b10530u;
constexpr std::uint32_t key = 0x007b9ac0u;

void require(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}
}

std::uint32_t fun_004eba00(Memory& m, const Inputs& i) {
    const auto owner = i.cx;
    const auto first = i.arg[0];
    require(owner && first && first != owner, "Block285 route requires distinct nonnull owner and candidate");
    require(m.r32(mode) == 0u, "Block285 route requires the comparator's original local ASCII mode");
    require(m.r32(registry_gate) == 0u && m.r32(conflict_gate) == 0u,
            "Block285 route requires both original global bypass gates clear");
    require(m.r8(owner + 0x13du) == 0u,
            "Block285 positive route requires owner +0x13d clear to enter registry and scan logic");

    // Original CALL 0x670910 searches counted entries by the inline bytes at
    // record+0x24. Its sole executed helper is accepted 0x76d860 in local
    // mode zero. This fixture has exactly one matching table entry.
    const auto names = m.r32(registry_count);
    require(names == 1u, "Block285 route bounds the registry search to one readable entry");
    const auto table = m.r32(registry_table);
    require(table, "Block285 route requires the registry pointer array");
    const auto name_record = m.r32(table);
    Inputs compare{};
    compare.arg[0] = name_record + 0x24u;
    compare.arg[1] = key;
    const auto compare_result = ra2::recovered::crt_b83::fun_0076d860(m, compare);
    require(compare_result == 0u, "Block285 route requires exact folded equality with original key Civilian");
    const std::uint32_t found_index = 0u;

    // The caller's candidate must satisfy the target's nested-index gate.
    const auto first_class = m.r32(first + 0x30u);
    const auto owner_class = m.r32(owner + 0x30u);
    require(first_class != owner_class && first_class != 0xffffffffu && first_class < 32u,
            "Block285 first candidate must pass class checks and a defined x86 shift");
    require((m.r32(owner + 0x5674u) & (1u << first_class)) == 0u,
            "Block285 first candidate's owner mode bit must be clear to enter helper path");
    const auto first_nested = m.r32(first + 0x34u);
    require(first_nested && m.r32(first_nested + 0xbcu) == found_index,
            "Block285 route requires candidate nested +0xbc to equal helper index zero");

    const auto count = m.r32(scan_count);
    require(count >= 1u && count <= 4u, "Block285 route bounds the live counted scan to one through four records");
    const auto objects = m.r32(scan_table);
    require(objects, "Block285 route requires a nonnull counted scan array");

    std::uint32_t eligible = 0u;
    std::uint32_t conflicts = 0u;
    std::uint32_t last_bit = 0u;
    for (std::uint32_t index = 0; index < count; ++index) {
        const auto object = m.r32(objects + index * 4u);
        require(object && object != owner, "Block285 route uses distinct nonnull scan objects");
        if (m.r8(object + 0x13du) != 0u) continue;
        const auto nested = m.r32(object + 0x34u);
        require(nested, "Block285 eligible records require a valid nested record");
        if (m.r8(nested + 0x1a6u) != 0u) continue;
        ++eligible;
        const auto object_class = m.r32(object + 0x30u);
        const auto owner_class = m.r32(owner + 0x30u);
        require(object_class != owner_class && object_class != 0xffffffffu,
                "Block285 scan rows must take the original caller-word-store route");
        i.arg[0] = 1u; // Original stack store at VA 0x4ebace targets entry [ESP+4].
        require(object_class >= 2u && object_class <= 5u,
                "Block285 route bounds mode-bit shifts to fixture classes two through five");
        last_bit = 1u << object_class;
        if (m.r32(owner + 0x5674u) & last_bit) ++conflicts;
    }
    require(eligible == count, "Block285 cases keep every counted record eligible");

    // The target unconditionally INCs EBP once after the scan, compares EDI
    // (eligible records) with EBP (conflicts plus that sentinel), and writes
    // only AL. Classes 2..5 keep the complete EAX result equal to 0 or 1.
    const auto final_counter = conflicts + 1u;
    return (last_bit & 0xffffff00u) | (eligible != final_counter ? 1u : 0u);
}
} // namespace ra2::recovered::recovery_b285



