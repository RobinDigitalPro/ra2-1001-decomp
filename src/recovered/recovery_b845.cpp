#include "recovered/recovery_b845.hpp"

#include "recovered/ini_bulk.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/leaf_memory.hpp"
#include "recovered/name_hash.hpp"

#include <algorithm>
#include <array>
#include <stdexcept>
#include <string>
#include <vector>

namespace ra2::recovered::recovery_b845 {
namespace {
using U = std::uint32_t;
using namespace ra2::recovered;

void require(bool v, const char* why) {
    if (!v) throw std::domain_error(why);
}

std::string read_z(const Memory& m, U p, U limit = 256u) {
    require(p != 0u, "845 null INI string");
    std::string out;
    for (U n = 0; n < limit; ++n) {
        const auto c = static_cast<char>(m.r8(p + n));
        if (!c) return out;
        out.push_back(c);
    }
    throw std::domain_error("845 INI string exceeds finite fixture bound");
}

std::int32_t signed_hash(U h) {
    return h <= 0x7fffffffu ? static_cast<std::int32_t>(h)
        : -1 - static_cast<std::int32_t>(0xffffffffu - h);
}

U hash_name(const std::uint8_t* p, std::size_t n, void*) {
    return ini_name_hash(p, n, nullptr);
}

void sort_nodes(IniIndexEntry* p, std::int32_t n, IniIndexKind, void*) {
    if (n < 0) throw std::domain_error("845 negative INI index count");
    std::sort(p, p + n, [](const auto& a, const auto& b) { return a.key < b.key; });
}

std::int32_t uppercase(std::int32_t c, void*) {
    return c >= 'a' && c <= 'z' ? c - ('a' - 'A') : c;
}

bool same_full_ascii_casefold(const Memory& memory, const Heap& heap, U candidate, U prior) {
    // 0x82c00 calls original 0x36d860. With [0xb10530]=0 that helper compares
    // complete NUL-terminated byte strings using its inline ASCII fold.
    for (U n = 0; n != 256u; ++n) {
        const auto a = memory.r8(candidate + n) & 0xffu;
        const auto b = heap.r8(prior + n) & 0xffu;
        const auto fold = [](U c) { return c >= 'a' && c <= 'z' ? c - ('a' - 'A') : c; };
        if (fold(a) != fold(b)) return false;
        if (!a || !b) return a == b;
    }
    throw std::domain_error("845 candidate string exceeds 255-byte fixture bound");
}

// Bounded logical projection of the already initialized guest INI graph.
// Guest addresses remain the evidence; these host views are adapter objects,
// not original class declarations or ABI-compatible objects.
struct IniView {
    Memory& m;
    U root_guest{}, root_table{}, section_guest{}, key_guest{}, key_table{};
    std::vector<IniIndexEntry> root_rows, key_rows;
    std::vector<IniValue> values;
    std::vector<std::string> value_texts;
    std::vector<std::string> names;
    std::vector<IniKeyNode> nodes;
    IniKeyNode sentinel{};
    IniSection section{};
    IniIndex root{};
    IniOperations ops{};

    IniView(Memory& memory, U ini) : m(memory), root_guest(ini + 0x20u) {
        root_table = m.r32(root_guest);
        const U root_count = m.r32(root_guest + 4u);
        require(root_count == 1u && m.r8(root_guest + 12u) == 1u,
                "845 contract requires one sorted cached section row");
        require(m.r32(root_guest + 16u) == root_table,
                "845 contract requires warm original section cache");

        section_guest = m.r32(root_table + 4u);
        key_guest = section_guest + 0x2cu;
        key_table = m.r32(key_guest);
        const U key_count = m.r32(key_guest + 4u);
        require(key_count == 2u && m.r8(key_guest + 12u) == 1u,
                "845 contract requires two sorted Movies entries");
        require(m.r32(key_guest + 16u) == key_table,
                "845 contract requires warm original key cache");

        root_rows.resize(1u);
        root_rows[0].key = signed_hash(m.r32(root_table));
        root_rows[0].value = &section;
        root = {root_rows.data(), 1, 1, &root_rows[0], m.r32(root_guest + 8u)};

        key_rows.resize(key_count);
        values.resize(key_count);
        value_texts.resize(key_count);
        names.reserve(key_count);
        for (U n = 0; n < key_count; ++n) {
            const U row = key_table + n * 8u;
            key_rows[n].key = signed_hash(m.r32(row));
            const U guest_value = m.r32(row + 4u);
            const U text = m.r32(guest_value + 0x10u);
            value_texts[n] = read_z(m, text);
            values[n].text = reinterpret_cast<const std::uint8_t*>(value_texts[n].c_str());
            key_rows[n].value = &values[n];
        }
        section.keys = {key_rows.data(), static_cast<std::int32_t>(key_count),
                        1u, &key_rows[0], m.r32(key_guest + 8u)};

        const U head = m.r32(section_guest + 0x18u);
        require(head != 0u, "845 Movies section has no linked key entries");
        names.resize(key_count);
        nodes.resize(key_count);
        U node = head;
        for (U n = 0; n < key_count; ++n) {
            require(node != 0u && m.r32(node + 4u) != 0u &&
                    m.r32(node + 8u) != 0u,
                    "845 linked key chain is not initialized");
            names[n] = read_z(m, m.r32(node + 0x0cu));
            nodes[n].name = reinterpret_cast<const std::uint8_t*>(names[n].c_str());
            if (n) nodes[n - 1u].next = &nodes[n];
            nodes[n].previous = n ? &nodes[n - 1u] : &sentinel;
            node = m.r32(node + 4u);
        }
        nodes.back().next = &sentinel;
        sentinel.next = &nodes.front();
        sentinel.previous = &nodes.back();
        section.first = &nodes.front();
        ops = {hash_name, sort_nodes, uppercase, nullptr, nullptr, nullptr};
    }

    void flush_caches() {
        m.w32(root_guest + 16u, root.cached ? root_table : 0u);
        if (!section.keys.cached) {
            m.w32(key_guest + 16u, 0u);
            return;
        }
        for (std::size_t n = 0; n < key_rows.size(); ++n) {
            if (section.keys.cached == &key_rows[n]) {
                m.w32(key_guest + 16u, key_table + static_cast<U>(n) * 8u);
                return;
            }
        }
        throw std::domain_error("845 INI cache points outside projected rows");
    }
};

}

std::uint32_t fun_00644d40(Memory& original, const Inputs& in, Heap& heap) {
    const U ini = in.arg[0];
    require(ini != 0u, "845 requires a valid INI input object");
    require(original.r32(0x00817554u) == 0u,
            "845 requires explicit threshold-zero ordinary CRT route");

    const U section_name = original.r32(0x00793f48u);
    const auto section_storage = read_z(original, section_name);
    require(section_storage == "Movies",
            "845 pins original Movies section string");
    IniView graph(original, ini);
    const auto* section_bytes = reinterpret_cast<const std::uint8_t*>(
        section_storage.c_str());
    if (!fun_0050be00(&graph.root, section_bytes, graph.ops)) return 0u;
    const auto count = fun_0050bf50(&graph.root, section_bytes, graph.ops);
    require(count == 2, "845 finite route requires exactly two movie entries");

    std::array<std::uint8_t, 0x20u> output{};
    leaf::Memory output_span(output.data(), 0x35010000u,
                             static_cast<U>(output.size()));
    Memory m = original;
    m.add(output_span);
    static constexpr std::uint8_t empty[] = {0};
    U list_count = original.r32(0x00a58c78u);
    const U list_items = original.r32(0x00a58c6cu);
    const U list_capacity = original.r32(0x00a58c70u);
    require(list_count == 0u && list_capacity >= 2u && list_items != 0u,
            "845 requires empty preallocated list with two spare cells");

    for (std::int32_t n = 0; n < count; ++n) {
        const auto* key = fun_0050c250(&graph.root, section_bytes, n, graph.ops);
        require(key != nullptr, "845 linked Movie key lookup failed");
        (void)fun_0050ddf0(&graph.root, section_bytes, key, empty,
                           output.data(), static_cast<std::int32_t>(output.size()),
                           graph.ops);
        graph.flush_caches();
        const std::string value(reinterpret_cast<const char*>(output.data()));
        require(!value.empty() && value.size() < output.size(),
                "845 requires two bounded nonempty filename values");
        const U value_guest = 0x35010000u;
        // The fixture starts empty, but later iterations must still scan
        // strings appended earlier, matching the original second-iteration
        // duplicate check rather than assuming the list remains empty.
        bool duplicate = false;
        for (U prior = 0; prior < list_count; ++prior) {
            if (same_full_ascii_casefold(m, heap, value_guest,
                                 original.r32(list_items + prior * 4u))) {
                duplicate = true;
                break;
            }
        }
        if (duplicate) continue;
        require(list_count < list_capacity,
                "845 excludes original indirect list-growth branch");
        const U copied = heap.allocate(static_cast<U>(value.size() + 1u));
        require(copied != 0u, "845 threshold-zero string clone allocation failed");
        for (U j = 0; j <= value.size(); ++j)
            heap.w8(copied + j, m.r8(value_guest + j));
        original.w32(list_items + list_count * 4u, copied);
        ++list_count;
        original.w32(0x00a58c78u, list_count);
    }
    graph.flush_caches();
    return 1u; // Only AL is claimed by this draft.
}
}
