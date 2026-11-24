#include "recovered/recovery_b393.hpp"
#include "recovered/decimal_text.hpp"
#include "recovered/global_b26_memory.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_integer.hpp"
#include "recovered/ini_lookup.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/recovery_b381.hpp"
#include <array>
#include <memory>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b393 {
namespace {
using U = std::uint32_t;
using namespace floating_b61;
[[noreturn]] void reject(const char* why) { throw std::domain_error(why); }
std::vector<std::uint8_t> text(const Memory& m, U p) {
    if (!p) reject("INI393 requires a nonnull string");
    std::vector<std::uint8_t> out;
    for (unsigned n = 0; n != 64; ++n) {
        const auto b = static_cast<std::uint8_t>(m.r8(p + n)); out.push_back(b);
        if (!b) return out;
    }
    reject("INI393 strings are bounded to 64 readable bytes");
}
std::uint32_t hash_z(const std::vector<std::uint8_t>& s) {
    unsigned n = 0; while (n < s.size() && s[n]) ++n;
    return ini_name_hash(s.data(), n, nullptr);
}
std::int32_t signed_hash(U h) { return global_b26::s32(h); }
void no_sort(IniIndexEntry*, std::int32_t, IniIndexKind, void*) {
    reject("INI393 uses initialized signed-sorted indexes only");
}
std::uint32_t hash_cb(const std::uint8_t* p, std::size_t n, void*) { return ini_name_hash(p, n, nullptr); }
std::int32_t upper_cb(std::int32_t c, void*) { return c >= 'a' && c <= 'z' ? c - ('a' - 'A') : c; }

struct Section { IniSection view{}; std::vector<IniIndexEntry> rows; std::vector<std::unique_ptr<IniValue>> values; std::vector<std::vector<std::uint8_t>> strings; };
class Projection {
    Memory& m_; U receiver_, section_guest_; IniIndex root_{}; std::array<IniIndexEntry, 1> root_row_{}; Section section_{};
    IniOperations ops_{};
    void refresh_index(U index, IniIndex& logical, IniIndexEntry* rows, unsigned count) {
        logical.cached = nullptr; const U raw = m_.r32(index + 16), table = m_.r32(index);
        if (!raw) return;
        if (raw < table || ((raw - table) & 7u) || (raw - table) / 8u >= count)
            reject("INI393 cache escaped its bounded table");
        logical.cached = rows + (raw - table) / 8u;
    }
    void flush_index(U index, const IniIndex& logical, const IniIndexEntry* rows, unsigned count) {
        U raw = 0;
        if (logical.cached) {
            if (logical.cached < rows || logical.cached >= rows + count) reject("INI393 logical cache escaped table");
            raw = m_.r32(index) + 8u * static_cast<U>(logical.cached - rows);
        }
        m_.w32(index + 16, raw);
    }
public:
    Projection(Memory& m, U receiver, U section_name, unsigned key_count) : m_(m), receiver_(receiver), section_guest_(0) {
        if (!receiver_) reject("INI393 null INI receiver");
        const U index = receiver_ + 0x20u, table = m_.r32(index), count = m_.r32(index + 4);
        if (count != 1 || !table || !m_.r8(index + 12) || !m_.r32(table + 4))
            reject("INI393 requires the exact one-section positive fixture graph");
        section_guest_ = m_.r32(table + 4);
        const U root_hash = m_.r32(table), query_hash = hash_z(text(m, section_name));
        if (root_hash != query_hash) reject("INI393 section index does not match original section string");
        root_row_[0] = {signed_hash(root_hash), &section_.view};
        root_ = {root_row_.data(), 1, 1, nullptr, 1};
        refresh_index(index, root_, root_row_.data(), 1);
        const U ki = section_guest_ + 0x2c, kt = m_.r32(ki), kc = m_.r32(ki + 4);
        if (kc != key_count || !kt || !m_.r8(ki + 12) || m_.r32(ki + 8) < kc)
            reject("INI393 requires the complete initialized key table");
        section_.rows.resize(kc); section_.values.reserve(kc); section_.strings.reserve(kc);
        for (U k = 0; k != kc; ++k) {
            const U row = kt + 8u * k, value = m_.r32(row + 4), value_text = m_.r32(value + 0x10);
            section_.strings.push_back(text(m_, value_text));
            auto v = std::make_unique<IniValue>(); v->text = section_.strings.back().data();
            section_.rows[k] = {signed_hash(m_.r32(row)), v.get()}; section_.values.push_back(std::move(v));
            if (k && section_.rows[k - 1].key >= section_.rows[k].key) reject("INI393 keys are unique signed-sorted hashes");
        }
        section_.view.keys = {section_.rows.data(), static_cast<std::int32_t>(kc), 1, nullptr, kc};
        refresh_index(ki, section_.view.keys, section_.rows.data(), kc);
        ops_ = {hash_cb, no_sort, upper_cb, nullptr, nullptr, nullptr};
    }
    IniIndex& root() { return root_; }
    IniOperations ops() const { return ops_; }
    void refresh() {
        refresh_index(receiver_ + 0x20u, root_, root_row_.data(), 1);
        refresh_index(section_guest_ + 0x2cu, section_.view.keys, section_.rows.data(), static_cast<unsigned>(section_.rows.size()));
    }
    void flush() {
        flush_index(receiver_ + 0x20u, root_, root_row_.data(), 1);
        flush_index(section_guest_ + 0x2cu, section_.view.keys, section_.rows.data(), static_cast<unsigned>(section_.rows.size()));
    }
};
struct Ctx { std::array<std::uint16_t,257> flags{}; CrtClassification ctype{}; GetterHexContext hex{}; };
std::int32_t classify(std::uint8_t b, U mask, void* p) {
    return static_cast<std::int32_t>(static_cast<Ctx*>(p)->ctype.flags_from_minus_one[b + 1] & mask);
}
std::int32_t lower(std::int32_t c, void*) { return c >= 'A' && c <= 'Z' ? c + ('a' - 'A') : c; }
void init_context(Memory& m, Ctx& c) {
    const U table = m.r32(0x817560u) - 2u;
    for (unsigned n = 0; n != 257; ++n) c.flags[n] = static_cast<std::uint16_t>(m.r16(table + 2u*n));
    c.ctype = {1, c.flags.data(), nullptr, nullptr}; c.hex = {&c.ctype};
}
IntegerReadOperations int_ops(const IniOperations& lookup, Ctx& c) {
    return {lookup, {classify, &c}, lower, scan_getter_hex32_callback, &c.hex};
}
U integer(Memory& m, Projection& g, Ctx& c, U section, U key, U fallback) {
    auto s = text(m, section), k = text(m, key);
    const U result = fun_0050cc40(&g.root(), s.data(), k.data(), fallback, int_ops(g.ops(), c));
    g.flush(); return result;
}
std::uint8_t boolean(Memory& m, Projection& g, U section, U key, std::uint8_t fallback) {
    auto s = text(m, section), k = text(m, key);
    const U result = fun_0050e860(&g.root(), s.data(), k.data(), fallback, g.ops());
    g.flush(); return static_cast<std::uint8_t>(result);
}
U float_field(Memory& m, Projection& g, const Inputs& outer, U ini, U section, U key,
              U dst, U fallback_lo, U fallback_hi, U compare_address = 0) {
    Inputs nested = outer; nested.cx = ini; nested.arg[0] = section; nested.arg[1] = key;
    nested.arg[2] = fallback_lo; nested.arg[3] = fallback_hi;
    const U eax = recovery_b381::fun_0050d7f0(m, nested);
    outer.fp = nested.fp; g.refresh();
    write64(m, dst, compare_address ? outer.fp.store64() : outer.fp.pop64());
    if (compare_address) outer.fp.compare_pop64(read64(m, compare_address));
    return eax;
}
}

std::uint32_t fun_00591c30(Memory& m, const Inputs& i) {
    const U out = i.cx, ini = i.arg[0], selector = m.r32(out);
    const U section = selector == 0xffffffffu ? 0x7b8e5cu : m.r32(0x7b8704u + selector * 4u);
    Projection g(m, ini, section, 8);
    auto section_name = text(m, section);
    if (!fun_0050be00(&g.root(), section_name.data(), g.ops())) { g.flush(); return 0; }
    g.flush();
    for (const U key : {0x7cc848u, 0x7cc840u, 0x7cc834u, 0x7cc828u, 0x7cc81cu, 0x7cc814u}) {
        const U offset = key == 0x7cc848u ? 4u : key == 0x7cc840u ? 5u : key == 0x7cc834u ? 6u : key == 0x7cc828u ? 7u : key == 0x7cc81cu ? 8u : 9u;
        const auto value = boolean(m, g, section, key, static_cast<std::uint8_t>(m.r8(out + offset)));
        m.w8(out + offset, value);
    }
    const U rate = out + 0x10u;
    U eax = float_field(m, g, i, ini, section, 0x7b9eecu, rate, m.r32(rate), m.r32(rate + 4u));
    const U aa = out + 0x18u;
    eax = float_field(m, g, i, ini, section, 0x7cc80cu, aa, 0, 0, 0x786610u);
    // For the positive finite literals below, AARate is strictly above the
    // pinned zero comparison constant, so the original conditional copy is not taken.
    const U status = i.fp.status(); // Original FNSTSW AX writes only the low 16 bits.
    eax = (eax & 0xffff0000u) | status;
    if (status & 0x4000u) write64(m, aa, read64(m, rate));
    return (eax & 0xffffff00u) | 1u; // Original MOV AL,1 preserves AX[15:8].
}
std::uint32_t fun_00642740(Memory& m, const Inputs& i) {
    const U out = i.cx, ini = i.arg[0], section = m.r32(0x793f04u);
    Projection g(m, ini, section, 26); auto section_name = text(m, section);
    if (!fun_0050be00(&g.root(), section_name.data(), g.ops())) { g.flush(); return 0; }
    g.flush(); Ctx ctx{}; init_context(m, ctx);
    constexpr U int_keys[]{0x7db248u,0x7be9a4u,0x7db23cu,0x7db22cu,0x7db21cu,0x7db210u,0x7db200u,0x7c5944u,0x7d2b28u,0x7db1f0u,0x7db1e4u};
    constexpr U int_offsets[]{0x10e8u,0x10ecu,0x10f0u,0x10f4u,0x10f8u,0x10fcu,0x1100u,0x1104u,0x1108u,0x110cu,0x1110u};
    for (unsigned n = 0; n != 11; ++n) m.w32(out + int_offsets[n], integer(m, g, ctx, section, int_keys[n], m.r32(out + int_offsets[n])));
    constexpr U bool_keys[]{0x7db1d0u,0x7db1c4u,0x7db1bcu,0x7db1b4u,0x7db1a4u,0x7db19cu,0x7db18cu,0x7db17cu,0x7db16cu,0x7db15cu,0x7db150u,0x7db13cu,0x7db12cu,0x7db120u,0x7db110u};
    constexpr U bool_offsets[]{0x1114u,0x1115u,0x1116u,0x1117u,0x1118u,0x1119u,0x111au,0x111bu,0x111cu,0x111du,0x111eu,0x1121u,0x1122u,0x111fu,0x1120u};
    for (unsigned n = 0; n != 15; ++n) m.w8(out + bool_offsets[n], boolean(m, g, section, bool_keys[n], static_cast<std::uint8_t>(m.r8(out + bool_offsets[n]))));
    return 1;
}
}
