#include "recovered/recovery_b143.hpp"
#include "recovered/name_hash.hpp"

#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b143 {
namespace {
void require(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}

std::string read_z(Memory& m, std::uint32_t p) {
    require(p != 0, "0x6a3c0 insert requires non-null text");
    std::string out;
    for (std::uint32_t n = 0; n != 128; ++n) {
        const auto c = static_cast<unsigned char>(m.r8(p + n));
        if (c == 0) return out;
        out.push_back(static_cast<char>(c));
    }
    throw std::domain_error("0x6a3c0 bounded string has no NUL within 128 bytes");
}

std::uint32_t name_hash(const std::string& s) {
    return ini_name_hash(reinterpret_cast<const std::uint8_t*>(s.data()), s.size(), nullptr);
}

void write_z(Heap& h, std::uint32_t p, const std::string& s) {
    for (std::uint32_t n = 0; n < s.size(); ++n)
        h.w8(p + n, static_cast<std::uint8_t>(s[n]));
    h.w8(p + static_cast<std::uint32_t>(s.size()), 0);
}

// Selected positive path through original RVA 0x10da40. The one-row cached
// section hit and sorted key miss avoid every graph-growth, replacement, and
// destructor branch. Heap allocations remain real small-CRT requests.
std::uint32_t insert_new_value(Memory& m, Heap& h, std::uint32_t receiver,
                               std::uint32_t section_name,
                               std::uint32_t key_name,
                               const std::string& value_text) {
    const auto section_text = read_z(m, section_name);
    const auto key_text = read_z(m, key_name);
    require(!section_text.empty() && !key_text.empty() && !value_text.empty(),
            "bounded 0x10da40 route requires nonempty section/key/value");

    const auto section_root = receiver + 0x20u;
    const auto section_table = m.r32(section_root);
    require(m.r32(section_root + 4u) == 1u && m.r8(section_root + 12u) == 1u,
            "bounded route requires one sorted section row");
    const auto section_hash = name_hash(section_text);
    require(m.r32(section_table) == section_hash,
            "the one cached section row must match the original section hash");
    const auto section = m.r32(section_table + 4u);
    require(section != 0 && m.r32(section_root + 16u) == section_table,
            "section cache must already name the sole matching row");

    const auto key_root = section + 0x2cu;
    const auto key_table = m.r32(key_root);
    require(m.r32(key_root + 4u) == 1u && m.r32(key_root + 8u) >= 2u &&
            m.r8(key_root + 12u) == 1u && m.r32(key_root + 16u) == 0u,
            "bounded route requires one sorted prior key, spare capacity, and null cache");
    const auto key_hash = name_hash(key_text);
    require(m.r32(key_table) != key_hash,
            "the sole existing key must not match the inserted key");

    const auto node = h.allocate(0x28u);                 // VA 0x50dcc8
    require(node != 0, "original small-CRT allocation of 40 bytes must succeed");
    const auto value_copy = h.allocate(static_cast<std::uint32_t>(value_text.size() + 1u));
    require(value_copy != 0, "original value clone allocation must succeed");
    write_z(h, value_copy, value_text);                  // 0x779146 copies before next clone
    const auto key_copy = h.allocate(static_cast<std::uint32_t>(key_text.size() + 1u));
    require(key_copy != 0, "original key clone allocation must succeed");
    write_z(h, key_copy, key_text);

    // Reached stores from RVA 0x10ffb0: original link tag, null next link,
    // key/value owned strings, then original EBP/remaining cleared words.
    h.w32(node, 0x0078eb9cu);
    h.w32(node + 4u, 0u);
    h.w32(node + 8u, 0u);
    h.w32(node + 0x0cu, key_copy);
    h.w32(node + 0x10u, value_copy);
    h.w32(node + 0x14u, 0u); // original EBP is zero on the absent-key branch
    for (std::uint32_t off = 0x18u; off <= 0x24u; off += 4u) h.w32(node + off, 0u);

    // Original RVA 0xe180 inserts the new node after the section's existing
    // list position. The fixture supplies an empty readable position.
    const auto position = m.r32(section + 0x28u);
    require(position != 0 && h.r32(position + 4u) == 0,
            "section list position must be an empty one-node insertion point");
    const auto next = h.r32(position + 4u);
    h.w32(node + 4u, next);
    h.w32(node + 8u, position);
    if (next != 0) h.w32(next + 8u, node);
    h.w32(position + 4u, node);

    // Original RVA 0x110150 takes its in-capacity append branch (1+1 <= 2).
    // Store order is key hash, value pointer, sorted=0, count=2; cache remains 0.
    m.w32(key_table + 8u, key_hash);
    m.w32(key_table + 12u, node);
    m.w8(key_root + 12u, 0u);
    m.w32(key_root + 4u, 2u);
    return 1u;                                           // exact bounded full EAX
}
}

std::uint32_t fun_0046a3c0(Memory& m, const Inputs& i, Heap& h) {
    constexpr std::uint32_t category_count_va = 0x00a1a5d8u;
    constexpr std::uint32_t category_table_va = 0x00a1a5ccu;
    const auto section_name = i.arg[0];
    const auto key_name = i.arg[1];
    const auto mask = i.arg[2];
    const auto count = m.r32(category_count_va);
    require(count == 1u && m.r32(category_table_va) != 0u && mask == 1u,
            "bounded root route requires one category row and mask bit 0");
    const auto row = m.r32(m.r32(category_table_va));
    require(row != 0 && m.r32(row + 0x30u) == 0u,
            "supplied category row must have original bit index 0");
    const auto value = read_z(m, row + 0x15ee0u); // original inline LEA target
    require(!value.empty(), "the selected category text must be nonempty");
    return insert_new_value(m, h, i.cx, section_name, key_name, value);
}
}
