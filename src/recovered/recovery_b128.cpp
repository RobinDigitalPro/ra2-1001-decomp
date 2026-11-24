#include "recovered/recovery_b128.hpp"

#include "recovered/global_b26_memory.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b128 {
namespace {
std::uint32_t compare_names(Memory&,std::uint32_t,std::uint32_t);
bool same_type_name(Memory& m, std::uint32_t a, std::uint32_t b) {
    if (a == b) return true;
    return compare_names(m, a + 8u, b + 8u) == 0;
}

// 0x36f78c: with the original COL cdOffset of zero, its actual calculation is
// object - COL.offset. This vtable has both fields zero.
std::uint32_t top_offset(Memory& m, std::uint32_t object) {
    const auto vptr = m.r32(object);
    const auto col = m.r32(vptr - 4u);
    const auto offset = m.r32(col + 4u);
    const auto cd_offset = m.r32(col + 8u);
    if (cd_offset != 0)
        throw std::domain_error("B128 top-offset route requires zero COL offset/cdOffset");
    return object - offset;
}

// 0x36fa31: implement its PMD adjustment using the original record. The
// bounded chosen descriptors have pdisp=-1, so the virtual-base lookup is
// skipped and only mdisp contributes.
std::uint32_t pmd_adjustment(Memory& m, std::uint32_t bcd) {
    const auto mdisp = m.r32(bcd + 8u);
    const auto pdisp = global_b26::s32(m.r32(bcd + 12u));
    const auto vdisp = m.r32(bcd + 16u);
    if (pdisp != -1 || vdisp != 0)
        throw std::domain_error("B128 PMD route requires pdisp=-1 and vdisp=0");
    return mdisp;
}

// 0x371650: bytewise unsigned NUL-terminated decorated-name comparison.
// All reached original descriptors have short, file-backed names.
std::uint32_t compare_names(Memory& m, std::uint32_t left, std::uint32_t right) {
    for (std::uint32_t n = 0; n < 256u; ++n) {
        const auto a = m.r8(left + n), b = m.r8(right + n);
        if (a != b) return a < b ? 0xffffffffu : 1u;
        if (a == 0) return 0;
    }
    throw std::domain_error("B128 RTTI decorated name exceeded finite 256-byte bound");
}

// Bounded faithful route through the two original 0x36f800 passes. Pass one
// checks target candidates and the source's contained-base list; if that does
// not resolve the cast, pass two accepts a public target BCD. The caller then
// applies the selected BCD's PMD through 0x36fa31.
std::uint32_t hierarchy_target(Memory& m, std::uint32_t col,
                               std::uint32_t source_type,
                               std::uint32_t target_type,
                               std::uint32_t source_delta) {
    const auto chd = m.r32(col + 16u);
    const auto count = m.r32(chd + 8u);
    const auto bca = m.r32(chd + 12u);
    if (count == 0 || count > 64)
        throw std::domain_error("B128 RTTI hierarchy count outside finite bound");

    // 0x76f820..0x76f8a3: outer target search, then source walk in each
    // candidate's contained subtree.
    for (std::uint32_t n = 0; n < count; ++n) {
        const auto outer = m.r32(bca + 4u * n);
        const auto outer_type = m.r32(outer);
        if (!same_type_name(m, outer_type, target_type)) continue;
        const auto contained = m.r32(outer + 4u);
        if (contained == 0 || n + contained >= count)
            throw std::domain_error("B128 first-pass contained-base span is not mapped");
        for (std::uint32_t k = 0; k < contained; ++k) {
            const auto child = m.r32(bca + 4u * (n + 1u + k));
            if (!same_type_name(m, m.r32(child), source_type)) continue;
            if (pmd_adjustment(m, child) == source_delta) return outer;
        }
    }

    // 0x76f8a9..0x76f8f7: second target-only pass, including its actual
    // decorated-name comparisons and BCD public-attribute test.
    for (std::uint32_t n = 0; n < count; ++n) {
        const auto candidate = m.r32(bca + 4u * n);
        if (!same_type_name(m, m.r32(candidate), target_type)) continue;
        if ((m.r32(candidate + 20u) & 3u) == 0u) return candidate;
    }
    return 0;
}

// Restricted 0x36f624 no-throw path: isReference=0. Only the normal returned
// cast value is modeled; FS-chain and C++ exception machinery stay platform-
// local in the native harness.
std::uint32_t dynamic_cast_route(Memory& m, std::uint32_t object,
                                 std::uint32_t source_type,
                                 std::uint32_t target_type) {
    if (!object) return 0;
    const auto top = top_offset(m, object);
    const auto vptr = m.r32(object);
    const auto col = m.r32(vptr - 4u);
    const auto source_delta = object - top; // vfDelta is zero in this caller.
    const auto bcd = hierarchy_target(m, col, source_type, target_type, source_delta);
    if (!bcd) return 0;
    return top + pmd_adjustment(m, bcd);
}

std::uint32_t sorted_lookup(Memory& m, std::uint32_t table,
                            std::uint32_t count, std::uint32_t key) {
    // Faithful positive-count loop from 0x108d30. ESI is the remaining
    // element count; ECX is the current lower row. For rowKey < key, the
    // original advances ECX by mid+1 and sets remaining=count-mid-1.
    std::uint32_t lower = table;
    std::int32_t remaining = static_cast<std::int32_t>(count);
    const auto signed_key = global_b26::s32(key);
    while (remaining > 0) {
        const auto mid = static_cast<std::uint32_t>(remaining / 2);
        const auto row = lower + mid * 8u;
        const auto signed_row_key = global_b26::s32(m.r32(row));
        if (signed_row_key == signed_key) return row;
        if (signed_row_key > signed_key) {
            remaining = static_cast<std::int32_t>(mid);
        } else {
            lower = row + 8u;
            remaining -= static_cast<std::int32_t>(mid) + 1;
        }
    }
    return 0;
}
} // namespace

std::uint32_t fun_006aae60(Memory& m, const Inputs& i) {
    const auto receiver = i.cx;
    if (m.r8(receiver + 4u) != 0x34u)
        throw std::domain_error("B128 fixture contract requires tag 0x34");
    const auto key = m.r32(receiver);
    const auto count = m.r32(0x00aa7a64u);
    if (count == 0 || count > 7)
        throw std::domain_error("B128 sorted registry count exceeds selected fixture bound");

    const auto table = m.r32(0x00aa7a60u);
    auto row = m.r32(0x00aa7a70u);
    if (row && m.r32(row) != key) row = 0;
    if (!row) {
        if (m.r8(0x00aa7a6cu) == 0)
            throw std::domain_error("B128 route requires initialized registry flag");
        row = sorted_lookup(m, table, count, key);
        if (!row) throw std::domain_error("B128 selected fixtures require a positive sorted hit");
        m.w32(0x00aa7a70u, row);
    }

    const auto object = m.r32(row + 4u);
    return dynamic_cast_route(m, object, 0x7b91d0u, 0x7b91d0u);
}
} // namespace ra2::recovered::recovery_b128
