#include "recovery_b179.hpp"

#include "recovered/ini_bulk.hpp"
#include "recovered/ini_lookup.hpp"
#include "recovered/name_hash.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace ra2::recovered::recovery_b179 {
namespace {
using namespace ra2::recovered;
using U = std::uint32_t;
constexpr U output_base = 0x008391d0u;
constexpr U terrain_name_table = 0x007d87d4u;
constexpr std::array<U, 7> float_key_vas{
    0x007beb40u, // Hover
    0x007beb58u, // Foot
    0x007beb50u, // Track
    0x007beb48u, // Wheel
    0x007beb30u, // Float
    0x007bca80u, // Amphibious
    0x007beb24u  // FloatBeach
};
constexpr U buildable_key_va = 0x007db628u;
constexpr std::uint64_t one_f64 = 0x3ff0000000000000ull;
constexpr U one_f32 = 0x3f800000u;

std::string read_z(Memory& m, U p, U limit = 128u) {
    if (!p) throw std::domain_error("Block179 requires nonnull NUL-terminated game strings");
    std::string out;
    for (U n = 0; n < limit; ++n) {
        const auto c = static_cast<char>(m.r8(p + n));
        if (!c) return out;
        out.push_back(c);
    }
    throw std::domain_error("Block179 string lacks NUL in bounded span");
}

std::int32_t signed_hash(std::uint32_t h) {
    return h <= 0x7fffffffu ? static_cast<std::int32_t>(h)
        : -1 - static_cast<std::int32_t>(0xffffffffu - h);
}
std::uint32_t hash_name(const std::uint8_t* bytes, std::size_t n, void*) {
    return ini_name_hash(bytes, n, nullptr);
}
void sort_forbidden(IniIndexEntry*, std::int32_t, IniIndexKind, void*) {
    throw std::domain_error("Block179 contract requires the original INI indexes pre-sorted");
}
std::int32_t upper_ascii(std::int32_t c, void*) {
    return c >= 'a' && c <= 'z' ? c - ('a' - 'A') : c;
}
IniOperations make_operations() {
    return IniOperations{hash_name, sort_forbidden, upper_ascii, nullptr, nullptr, nullptr};
}

IniIndexEntry* map_cache(Memory& m, U cache_va, U table_va, U count,
                         IniIndexEntry* host_rows) {
    const U raw = m.r32(cache_va);
    if (!raw) return nullptr;
    if (raw < table_va || ((raw - table_va) & 7u) != 0u ||
        (raw - table_va) / 8u >= count)
        throw std::domain_error("Block179 cache pointer is outside its supplied sorted table");
    return host_rows + (raw - table_va) / 8u;
}

struct SectionView {
    U guest{};
    IniSection section{};
    IniIndexEntry one_key{};
    IniValue value{};
    std::string value_text;
};

// Adapts the explicitly supplied raw guest32 INI table into the accepted
// logical views. The portable IniIndex structs are not original class layouts;
// all persistent pointers are translated back to their guest row addresses.
class IniGraph {
public:
    IniIndex root{};
    std::vector<IniIndexEntry> section_rows;
    std::vector<SectionView> sections;
    U root_guest{};
    U root_table_guest{};
    U root_count{};

    IniGraph(Memory& m, U owner) : root_guest(owner + 0x20u) {
        root_table_guest = m.r32(root_guest);
        root_count = m.r32(root_guest + 4u);
        if (!root_count || root_count > 12u || m.r8(root_guest + 12u) == 0u || !root_table_guest)
            throw std::domain_error("Block179 requires 1..12 pre-sorted named sections");
        section_rows.resize(root_count);
        sections.resize(root_count);
        std::int32_t previous = 0;
        bool first = true;
        for (U n = 0; n < root_count; ++n) {
            const U row = root_table_guest + n * 8u;
            const auto key = signed_hash(m.r32(row));
            if (!first && key <= previous)
                throw std::domain_error("Block179 section hashes must be unique and signed-sorted");
            first = false;
            previous = key;
            auto& node = section_rows[n];
            auto& view = sections[n];
            node.key = key;
            view.guest = m.r32(row + 4u);
            if (!view.guest) throw std::domain_error("Block179 section row has null value");
            bool is_terrain_name = false;
            for (U name_index=0;name_index<12;++name_index) {
                const auto name = read_z(m, m.r32(terrain_name_table+4*name_index), 32u);
                const auto expected = signed_hash(ini_name_hash(
                    reinterpret_cast<const std::uint8_t*>(name.c_str()), name.size(), nullptr));
                if (key == expected) { is_terrain_name = true; break; }
            }
            if (!is_terrain_name)
                throw std::domain_error("Block179 root table contains a non-terrain section hash");
            node.value = &view.section;

            const U keys_guest = m.r32(view.guest + 0x2cu);
            const U key_count = m.r32(view.guest + 0x30u);
            if (key_count > 1u || m.r8(view.guest + 0x38u) == 0u)
                throw std::domain_error("Block179 section may have only zero keys or one sorted Buildable key");
            if (key_count == 0u) {
                if (m.r32(view.guest + 0x3cu) != 0u)
                    throw std::domain_error("Block179 empty-key sections must begin with a null key cache");
                view.section.keys = {nullptr, 0, 1, nullptr, m.r32(view.guest + 0x34u)};
            } else {
                if (!keys_guest) throw std::domain_error("Block179 Buildable index has a null row table");
                const U key_row = keys_guest;
                const auto key_hash = signed_hash(m.r32(key_row));
                const auto buildable_hash = signed_hash(ini_name_hash(
                    reinterpret_cast<const std::uint8_t*>("Buildable"), 9u, nullptr));
                if (key_hash != buildable_hash)
                    throw std::domain_error("Block179 permits no present float key; optional key must be Buildable");
                const U value_guest = m.r32(key_row + 4u);
                if (!value_guest) throw std::domain_error("Block179 Buildable row has null value");
                const U text_guest = m.r32(value_guest + 0x10u);
                view.value_text = read_z(m, text_guest, 32u);
                if (view.value_text.size() != 1u ||
                    (view.value_text[0] != '0' && view.value_text[0] != '1'))
                    throw std::domain_error("Block179 Buildable route is restricted to one-byte ASCII 0 or 1");
                view.value.text = reinterpret_cast<const std::uint8_t*>(view.value_text.c_str());
                view.one_key.key = key_hash;
                view.one_key.value = &view.value;
                view.section.keys = {&view.one_key, 1, 1, nullptr, m.r32(view.guest + 0x34u)};
                view.section.keys.cached = map_cache(m, view.guest + 0x3cu,
                                                     keys_guest, 1u, &view.one_key);
            }
            view.section.first = nullptr; // 0x10d7f0 / 0x10e860 do not use the linked list.
        }
        root = {section_rows.data(), static_cast<std::int32_t>(root_count), 1, nullptr,
                m.r32(root_guest + 8u)};
        root.cached = map_cache(m, root_guest + 16u, root_table_guest, root_count,
                                section_rows.data());
    }

    void flush(Memory& m) const {
        U root_cache = 0;
        for (U n = 0; n < root_count; ++n) {
            if (root.cached == &section_rows[n]) root_cache = root_table_guest + n * 8u;
        }
        if (root.cached && !root_cache)
            throw std::domain_error("Block179 root cache escaped supplied section table");
        if (m.r32(root_guest + 16u) != root_cache) m.w32(root_guest + 16u, root_cache);

        for (U n = 0; n < root_count; ++n) {
            const auto& section = sections[n];
            U cache = 0;
            if (section.section.keys.count != 0 && section.section.keys.cached == &section.one_key)
                cache = m.r32(section.guest + 0x2cu);
            if (section.section.keys.cached && !cache)
                throw std::domain_error("Block179 key cache escaped its optional Buildable row");
            if (m.r32(section.guest + 0x3cu) != cache) m.w32(section.guest + 0x3cu, cache);
        }
    }
};

std::uint64_t missing_float_default(Memory& m, IniGraph& graph, const IniOperations& ops,
                                    const std::string& section_name, U key_va) {
    const auto section_hash = signed_hash(ops.hash_name(
        reinterpret_cast<const std::uint8_t*>(section_name.c_str()), section_name.size(), ops.context));
    if (!graph.root.cached || graph.root.cached->key != section_hash)
        throw std::domain_error("Block179 expects the root's immediately preceding section lookup cached");

    const auto key_name = read_z(m, key_va);
    const auto key_hash = signed_hash(ops.hash_name(
        reinterpret_cast<const std::uint8_t*>(key_name.c_str()), key_name.size(), ops.context));
    auto* section = static_cast<IniSection*>(graph.root.cached->value);
    // Exact 0x10d7f0 missing-key path: zero key count takes its direct fallback;
    // a one-node Buildable-only table calls VA 0x5105a0 and misses before 0x510220,
    // value dereference, 0x36f070, or the float converter callback.
    if (section->keys.count != 0 && fun_005105a0(section->keys, &key_hash, ops) != nullptr)
        throw std::domain_error("Block179 float key unexpectedly exists and would enter the scanner path");
    return one_f64;
}

U store_default_float(Memory& m, const Inputs& i, IniGraph& graph,
                      const IniOperations& ops, const std::string& section,
                      U key_va, U output_va) {
    i.fp.load64(missing_float_default(m, graph, ops, section, key_va));
    i.fp.compare_pop64(one_f64); // FCOMP qword [0x785708], then FNSTSW AX.
    // FCOMP against the same 1.0 sets C0=0; TEST AH,1 therefore falls through
    // the root's 0x644723 branch to FLD qword [0x785708].
    i.fp.load64(one_f64);
    const U bits = i.fp.pop32(); // FSTP dword destination.
    if (bits != one_f32)
        throw std::domain_error("Block179 exact double-1.0 path must store binary32 1.0");
    m.w32(output_va, bits);
    return bits;
}
}

std::uint32_t fun_006446c0(Memory& m, const Inputs& i) {
    constexpr U bss_missing_section = 0x00000000u;
    constexpr U bss_missing_value = 0x00000000u;
    if (m.r32(0x00b10aacu) != bss_missing_section || m.r32(0x00b10ab0u) != bss_missing_value)
        throw std::domain_error("Block179 requires the pinned zero missing-section/value globals");
    if (m.r32(0x00b10530u) != 0u)
        throw std::domain_error("Block179 requires the original direct ASCII uppercase branch");
    if (floating_b61::read64(m, 0x00785708u) != one_f64)
        throw std::domain_error("Block179 requires the pinned binary64 comparison value 1.0");

    IniGraph graph(m, i.arg[0]);
    const auto ops = make_operations();
    for (U n = 0; n < 12u; ++n) {
        const U section_va = m.r32(terrain_name_table + n * 4u);
        const auto section_name = read_z(m, section_va, 32u);
        auto* section = fun_0050be00(&graph.root,
            reinterpret_cast<const std::uint8_t*>(section_name.c_str()), ops);
        graph.flush(m);
        if (!section) continue; // This record remains exactly as supplied.

        const U record = output_base + n * 0x24u;
        const std::array<U, 4> first_keys{float_key_vas[0], float_key_vas[1],
                                          float_key_vas[2], float_key_vas[3]};
        const std::array<U, 4> first_outputs{0x0cu, 0x00u, 0x04u, 0x08u};
        for (U k = 0; k < first_keys.size(); ++k)
            (void)store_default_float(m, i, graph, ops, section_name,
                                      first_keys[k], record + first_outputs[k]);

        m.w32(record + 0x10u, one_f32); // Exact root literal store before Float lookup.
        for (U k = 4u; k < float_key_vas.size(); ++k) {
            const std::array<U, 3> outputs{0x14u, 0x18u, 0x1cu};
            (void)store_default_float(m, i, graph, ops, section_name,
                                      float_key_vas[k], record + outputs[k - 4u]);
        }

        const auto buildable_name = read_z(m, buildable_key_va, 32u);
        const auto buildable = fun_0050e860(&graph.root,
            reinterpret_cast<const std::uint8_t*>(section_name.c_str()),
            reinterpret_cast<const std::uint8_t*>(buildable_name.c_str()), 0u, ops);
        graph.flush(m);
        m.w8(record + 0x20u, buildable);
    }
    // The root's final instruction is MOV AL,1; only AL is claimed. When the
    // final Weeds section exists, 0x50e860's upper EAX bits are outside this
    // recovered route's observable contract.
    return 1u;
}
}
