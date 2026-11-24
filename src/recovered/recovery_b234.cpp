#include "recovered/recovery_b234.hpp"

#include "recovered/name_hash.hpp"

#include <algorithm>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace ra2::recovered::recovery_b234 {
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}

std::uint32_t u32at(Memory& m, std::uint32_t p) { return m.r32(p); }

std::int32_t signed32(std::uint32_t raw) {
    const auto wide = (raw & 0x80000000u)
        ? static_cast<std::int64_t>(raw) - 0x100000000ll
        : static_cast<std::int64_t>(raw);
    return static_cast<std::int32_t>(wide);
}

std::string decimal32(std::int32_t value) {
    std::uint32_t magnitude = static_cast<std::uint32_t>(value);
    const bool negative = value < 0;
    if (negative) magnitude = 0u - magnitude;
    char reverse[12]{};
    unsigned count = 0;
    do {
        reverse[count++] = static_cast<char>('0' + magnitude % 10u);
        magnitude /= 10u;
    } while (magnitude != 0);
    std::string out;
    if (negative) out.push_back('-');
    while (count) out.push_back(reverse[--count]);
    return out;
}

std::string read_z(Memory& m, std::uint32_t p) {
    need(p != 0, "0x266c60 bounded route requires non-null section name");
    std::string out;
    for (unsigned n = 0; n != 128; ++n) {
        const auto c = m.r8(p + n);
        if (c == 0) return out;
        out.push_back(static_cast<char>(c));
    }
    throw std::domain_error("0x266c60 section name is not NUL-terminated in 128 bytes");
}

std::uint32_t hash_text(const std::string& text) {
    return ini_name_hash(reinterpret_cast<const std::uint8_t*>(text.data()),
                         text.size(), nullptr);
}

std::uint32_t hash_text(Memory& m, std::uint32_t p) {
    return hash_text(read_z(m, p));
}

void write_z(Heap& h, std::uint32_t p, const std::string& text) {
    for (std::uint32_t n = 0; n < text.size(); ++n)
        h.w8(p + n, static_cast<std::uint8_t>(text[n]));
    h.w8(p + static_cast<std::uint32_t>(text.size()), 0);
}

// Exact final-memory effect of 0x76d686 + 0x510750 for this unique-hash
// domain: signed-32-bit ascending order. The original side must execute the
// pinned qsort body and its real comparator; this is only the portable result
// projection on the recovered C++ side.
void sort_existing_key_pairs(Memory& m, std::uint32_t index) {
    const auto count = m.r32(index + 4u);
    const auto table = m.r32(index);
    std::vector<std::pair<std::int32_t, std::uint32_t>> pairs;
    pairs.reserve(count);
    for (std::uint32_t n = 0; n < count; ++n)
        pairs.emplace_back(signed32(m.r32(table + n * 8u)),
                           m.r32(table + n * 8u + 4u));
    std::sort(pairs.begin(), pairs.end(),
              [](const auto& a, const auto& b) { return a.first < b.first; });
    for (std::uint32_t n = 0; n < count; ++n) {
        m.w32(table + n * 8u, static_cast<std::uint32_t>(pairs[n].first));
        m.w32(table + n * 8u + 4u, pairs[n].second);
    }
    m.w32(index + 16u, 0u);
    m.w8(index + 12u, 1u);
}

void insert_absent_value(Memory& m, Heap& h, std::uint32_t manager,
                         std::uint32_t section, const std::string& key,
                         const std::string& value) {
    need(!key.empty() && !value.empty(), "bounded insert requires nonempty key/value");
    const auto section_root = manager + 0x20u;
    const auto key_root = section + 0x2cu;
    const auto table = m.r32(key_root);
    const auto count = m.r32(key_root + 4u);
    const auto capacity = m.r32(key_root + 8u);
    need(count < capacity && capacity >= 17u,
         "bounded route requires spare capacity for all 17 key entries");
    need(m.r32(key_root + 16u) == 0u,
         "bounded absent-key route requires an initially empty key cache");

    if (count != 0u && m.r8(key_root + 12u) == 0u)
        sort_existing_key_pairs(m, key_root);

    const auto key_hash = hash_text(key);
    for (std::uint32_t n = 0; n < count; ++n)
        need(m.r32(table + n * 8u) != key_hash,
             "all fixed 0x266c60 keys must be absent before insertion");

    // Original absent-key order: request 0x28 node, clone value, clone key.
    const auto node = h.allocate(0x28u);
    need(node != 0u, "real small-CRT node allocation failed");
    const auto value_copy = h.allocate(static_cast<std::uint32_t>(value.size() + 1u));
    need(value_copy != 0u, "real small-CRT value clone allocation failed");
    write_z(h, value_copy, value);
    const auto key_copy = h.allocate(static_cast<std::uint32_t>(key.size() + 1u));
    need(key_copy != 0u, "real small-CRT key clone allocation failed");
    write_z(h, key_copy, key);

    // Stores from 0x50ffb0 on the absent-key path (EBP=0).
    h.w32(node, 0x0078eb9cu);
    h.w32(node + 4u, 0u);
    h.w32(node + 8u, 0u);
    h.w32(node + 0x0cu, key_copy);
    h.w32(node + 0x10u, value_copy);
    for (std::uint32_t off = 0x14u; off <= 0x24u; off += 4u)
        h.w32(node + off, 0u);

    // Original 0x40e180 inserts immediately after section+0x28's list head.
    const auto head = m.r32(section + 0x28u);
    need(head != 0u, "bounded section needs its existing list head");
    const auto next = m.r32(head + 4u);
    h.w32(node + 4u, next);
    h.w32(node + 8u, head);
    if (next != 0u) h.w32(next + 8u, node);
    m.w32(head + 4u, node);

    // Original 0x510150's in-capacity append branch.
    m.w32(table + count * 8u, key_hash);
    m.w32(table + count * 8u + 4u, node);
    m.w8(key_root + 12u, 0u);
    m.w32(key_root + 4u, count + 1u);
}

std::uint32_t require_section(Memory& m, std::uint32_t manager,
                              std::uint32_t section_name) {
    const auto text = read_z(m, section_name);
    const auto root = manager + 0x20u;
    need(m.r32(root + 4u) == 1u && m.r32(root + 8u) >= 1u &&
         m.r8(root + 12u) == 1u,
         "bounded root requires one sorted existing section row");
    const auto table = m.r32(root);
    const auto hash = hash_text(text);
    need(table != 0u && m.r32(root + 16u) == table &&
         m.r32(table) == hash,
         "bounded root requires its single matching cached section");
    const auto section = m.r32(table + 4u);
    need(section != 0u && m.r32(section + 0x2cu) != 0u,
         "existing section and key-index storage must be readable");
    const auto key_root = section + 0x2cu;
    need(m.r32(key_root + 4u) == 0u && m.r32(key_root + 8u) == 32u &&
         m.r32(key_root + 16u) == 0u,
         "bounded route requires an empty, uncached 32-entry key index");
    const auto head = m.r32(section + 0x28u);
    need(head != 0u && m.r32(head + 4u) == 0u && m.r32(head + 8u) == 0u,
         "bounded route requires an empty initialized section-list head");
    return section;
}

std::string key_from_pe(Memory& m, std::uint32_t p) { return read_z(m, p); }
}

std::uint32_t fun_00666c60(Memory& m, const Inputs& i, Heap& h) {
    const auto receiver = i.cx;
    const auto manager = i.arg[0];
    const auto section_name = i.arg[1];
    need(receiver != 0u && manager != 0u, "bounded root requires receiver and INI receiver");
    const auto section = require_section(m, manager, section_name);

    struct IntField { std::uint32_t offset; std::uint32_t key; };
    constexpr IntField ints[] = {
        {0x00u, 0x007dcfc4u}, {0x04u, 0x007dcfb8u},
        {0x08u, 0x007d2b28u}, {0x0cu, 0x007c593cu},
        {0x10u, 0x007db210u},
    };
    for (const auto& field : ints) {
        const auto key = key_from_pe(m, field.key);
        const auto numeric = signed32(u32at(m, receiver + field.offset));
        need(numeric >= -99 && numeric <= 99,
             "bounded root domain limits the five signed inputs to [-99,99]");
        const auto value = decimal32(numeric);
        insert_absent_value(m, h, manager, section, key, value);
    }

    struct FlagField { std::uint32_t offset; std::uint32_t key; };
    constexpr FlagField flags[] = {
        {0x14u, 0x007db150u}, {0x15u, 0x007db13cu},
        {0x16u, 0x007db12cu}, {0x17u, 0x007dcfacu},
        {0x18u, 0x007dcf9cu},
    };
    for (const auto& field : flags) {
        const auto key = key_from_pe(m, field.key);
        const auto value = m.r8(receiver + field.offset) ? "yes" : "no";
        insert_absent_value(m, h, manager, section, key, value);
    }

    for (std::uint32_t slot = 0; slot != 7u; ++slot) {
        char keybuf[7] = {'S','l','o','t',
            static_cast<char>('0' + (slot + 1u) / 10u),
            static_cast<char>('0' + (slot + 1u) % 10u), '\0'};
        const std::string key(keybuf);
        const auto record = receiver + 0x28u + slot * 12u;
        const auto av = signed32(m.r32(record));
        const auto bv = signed32(m.r32(record + 4u));
        const auto cv = signed32(m.r32(record + 8u));
        need(av >= -9 && av <= 9 && bv >= -9 && bv <= 9 &&
             cv >= -9 && cv <= 9,
             "bounded root domain limits each slot triple to [-9,9]");
        const auto a = decimal32(av);
        const auto b = decimal32(bv);
        const auto c = decimal32(cv);
        const auto value = a + "," + b + "," + c;
        insert_absent_value(m, h, manager, section, key, value);
    }
    return 1u;
}
}
