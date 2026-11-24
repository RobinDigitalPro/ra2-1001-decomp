#include "recovery_b911.hpp"
#include "recovered/ini_lookup.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/recovery_b399.hpp"
#include <array>
#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b911 {
namespace {
using U = std::uint32_t;
using namespace floating_b61;
[[noreturn]] void reject(const char* why) { throw std::domain_error(why); }

std::string read_z(const Memory& m, U p, U limit = 128u) {
    if (!p) reject("B911 null string pointer");
    std::string out;
    for (U n = 0; n < limit; ++n) {
        const auto c = static_cast<char>(m.r8(p + n));
        if (!c) return out;
        out.push_back(c);
    }
    reject("B911 bounded string exceeded");
}
U hash(const std::string& s) {
    return ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()), s.size(), nullptr);
}
std::int32_t signed_bits(U v) { return global_b26::s32(v); }
U sorted_lookup(Memory& m, U index, U key) {
    const U table = m.r32(index), count = m.r32(index + 4u), capacity = m.r32(index + 8u);
    if (!table || !count || count > 8u || capacity < count || !m.r8(index + 12u))
        reject("B911 finite positive route requires a small initialized sorted index");
    const U cached = m.r32(index + 16u);
    if (cached >= table && ((cached - table) & 7u) == 0u &&
        (cached - table) / 8u < count && m.r32(cached) == key)
        return m.r32(cached + 4u);
    U lo = 0, hi = count;
    while (lo < hi) {
        const U mid = lo + (hi - lo) / 2u, row = table + 8u * mid;
        const U found = m.r32(row);
        if (found == key) { m.w32(index + 16u, row); return m.r32(row + 4u); }
        if (signed_bits(found) < signed_bits(key)) lo = mid + 1u;
        else hi = mid;
    }
    reject("B911 fixture unexpectedly missed an INI index key");
}
bool equal_ascii(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) return false;
    for (std::size_t n = 0; n < a.size(); ++n) {
        auto x = static_cast<unsigned char>(a[n]), y = static_cast<unsigned char>(b[n]);
        if (x >= 'a' && x <= 'z') x = static_cast<unsigned char>(x - ('a' - 'A'));
        if (y >= 'a' && y <= 'z') y = static_cast<unsigned char>(y - ('a' - 'A'));
        if (x != y) return false;
    }
    return true;
}

// Model adapter for B399's already accepted one-section property reader.
// It borrows the real two-row root table only for this child call; all temporary
// guest bytes are restored and the actual root cache is translated back to its
// real Video row before returning.
U call_existing_record_reader(Memory& m, const Inputs& original, U ini, U record,
                              U video_row, U video_section, U temporary_row) {
    const U index = ini + 0x20u;
    const std::array<U, 4> saved{{m.r32(index), m.r32(index + 4u),
                                  m.r32(index + 8u), m.r32(index + 16u)}};
    const U saved_sorted = m.r8(index + 12u);
    const std::array<U, 2> saved_row{{m.r32(temporary_row), m.r32(temporary_row + 4u)}};
    const U record_section = hash(read_z(m, record));
    m.w32(temporary_row, record_section);
    m.w32(temporary_row + 4u, video_section);
    m.w32(index, temporary_row);
    m.w32(index + 4u, 1u);
    m.w32(index + 8u, 1u);
    m.w8(index + 12u, 1u);
    m.w32(index + 16u, temporary_row);

    Inputs child = original;
    child.cx = record;
    child.arg[0] = ini;
    const U result = recovery_b399::fun_0070ada0(m, child);

    m.w32(index, saved[0]);
    m.w32(index + 4u, saved[1]);
    m.w32(index + 8u, saved[2]);
    m.w8(index + 12u, saved_sorted);
    m.w32(index + 16u, video_row);
    m.w32(temporary_row, saved_row[0]);
    m.w32(temporary_row + 4u, saved_row[1]);
    original.fp = child.fp;
    return result;
}
}

U fun_0070afb0(Memory& m, const Inputs& i) {
    const U ini = i.cx;
    if (!ini) reject("B911 requires the original nonnull INI receiver in ECX");
    const std::string outer_name = read_z(m, 0x7e35dcu);
    if (outer_name != "DialogList") reject("B911 literal at 0x7e35dc changed");
    const U root_index = ini + 0x20u;
    const U root_table = m.r32(root_index), root_count = m.r32(root_index + 4u);
    if (!root_table || root_count != 2u) reject("B911 needs exactly two sorted section rows");
    const U outer_section = sorted_lookup(m, root_index, hash(outer_name));
    const U outer_keys = outer_section + 0x2cu;
    const U key_count = m.r32(outer_keys + 4u);
    if (key_count != 1u) reject("B911 finite route requires one DialogList entry");

    U node = m.r32(outer_section + 0x18u);
    if (!node) reject("B911 DialogList linked-key head is absent");
    const U key_name_ptr = m.r32(node + 0x0cu);
    const std::string key_name = read_z(m, key_name_ptr);
    const U value = sorted_lookup(m, outer_keys, hash(key_name));
    const U record_name_ptr = m.r32(value + 0x10u);
    const std::string record_name = read_z(m, record_name_ptr);

    const U registry_count = m.r32(0x00ab83c0u);
    const U registry_table = m.r32(0x00ab83b4u);
    if (registry_count != 1u || !registry_table)
        reject("B911 finite route requires the existing one-record registry");
    const U record = m.r32(registry_table);
    if (!record || !equal_ascii(record_name, read_z(m, record)))
        reject("B911 finite route requires the DialogList value to match the existing record");

    // Resolve the actual Video row before projecting it for B399. This is the
    // same signed-hash ordering used by the original binary-search helper.
    const std::string property_name = read_z(m, record);
    const U wanted = hash(property_name);
    U video_row = 0;
    for (U n = 0; n < root_count; ++n) {
        const U row = root_table + 8u * n;
        if (m.r32(row) == wanted) { video_row = row; break; }
    }
    if (!video_row || m.r32(video_row + 4u) == 0u)
        reject("B911 existing record has no matching populated property section");
    const U temporary_row = ini + 0x60000u;
    return call_existing_record_reader(m, i, ini, record,
                                       video_row, m.r32(video_row + 4u), temporary_row);
}
}
