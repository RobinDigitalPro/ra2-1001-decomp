#define NOMINMAX
#include <windows.h>

#include "recovered/recovery_b999.hpp"
#include "recovered/name_hash.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <string_view>

namespace ra2::recovered::b999 {
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}

std::string read_z(Memory& m, std::uint32_t p) {
    need(p != 0, "B979 bounded route needs a non-null PE string");
    std::string out;
    for (std::uint32_t n = 0; n != 128; ++n) {
        const auto c = static_cast<unsigned char>(m.r8(p + n));
        if (!c) return out;
        out.push_back(static_cast<char>(c));
    }
    throw std::domain_error("B979 PE string exceeds bounded 128-byte scan");
}

void write_z(Heap& h, std::uint32_t dst, std::string_view text) {
    for (std::uint32_t n = 0; n < text.size(); ++n)
        h.w8(dst + n, static_cast<std::uint8_t>(text[n]));
    h.w8(dst + static_cast<std::uint32_t>(text.size()), 0);
}

void init_list_490c60(Heap& m, std::uint32_t self) {
    // Actual stores from RVA 0x90c60, called with ECX=section+0x10.
    const auto esi = self + 4u;
    const auto edx = self + 0x10u;
    m.w32(esi + 4u, 0u);
    m.w32(esi + 8u, 0u);
    m.w32(esi, 0x00785afcu);
    m.w32(edx + 4u, 0u);
    m.w32(edx + 8u, 0u);
    m.w32(edx, 0x00785afcu);
    m.w32(self, 0x00785af4u);
    // The bounded constructor starts with both rings empty, so the original
    // 490c60 insertion takes its JZ path and writes only these three links.
    m.w32(edx + 8u, esi);
    m.w32(edx + 4u, m.r32(esi + 4u));
    m.w32(esi + 4u, edx);
}

void init_index_510130(Heap& m, std::uint32_t self) {
    // All five writes in the exact 19-byte initializer at RVA 0x110130.
    m.w32(self, 0u);
    m.w32(self + 4u, 0u);
    m.w32(self + 8u, 0u);
    m.w8(self + 0x0cu, 0u);
    m.w32(self + 0x10u, 0u);
}

std::uint32_t hash_text(const std::string& text) {
    return ra2::recovered::ini_name_hash(
        reinterpret_cast<const std::uint8_t*>(text.data()), text.size(), nullptr);
}

// Exact final object fields from the reached inline insertion path in RVA
// 0x10b080. The two embedded list sentinels were created by 0x90c60 above.
void build_single_section(Heap& m, Heap& h, std::uint32_t section,
                          std::uint32_t section_name, std::uint32_t node,
                          std::uint32_t key_copy, std::uint32_t value_copy,
                          std::uint32_t key_table, std::uint32_t section_table,
                          const std::string& section_text,const std::string& key_text) {
    need(section && section_name && node && key_copy && value_copy && key_table && section_table,
         "B979 successful route requires all eight parsed graph allocations");

    // The direct section path at 50b42a..45a: base link fields, vtables,
    // inline ring initializer, zeroed key index, and null active-record.
    h.w32(section + 4u, 0u);
    h.w32(section + 8u, 0u);
    h.w32(section, 0x0078ebb4u);
    h.w32(section + 0x0cu, section_name);
    init_list_490c60(m, section + 0x10u);
    h.w32(section + 0x10u, 0x0078ebacu);
    init_index_510130(m, section + 0x2cu);
    h.w32(section, 0x0078eba4u);
    h.w32(section + 0x40u, 0u);

    // The original creates the key node before either index table. Its fields
    // are the exact 50b663..6c9 stores; section list insertion follows at
    // 50b7b3..7ef. Unused payload bytes retain the explicit ordinal-seeded actual heap fixture.
    h.w32(node + 0x0cu, key_copy);
    h.w32(node + 0x10u, value_copy);
    h.w32(node + 0x14u, 0u);
    h.w32(node + 0x18u, 0u);
    h.w32(node + 0x1cu, 0u);
    h.w32(node + 0x20u, 0u);
    h.w32(node + 0x24u, 0u);
    h.w32(node + 4u, 0u);
    h.w32(node + 8u, 0u);
    h.w32(node, 0x0078eb9cu);

    // 50b6ef..b786 grows the section key index from 0 to 10 entries and
    // stores the signed-hash/pointer pair. The table's remaining bytes retain
    // the ordinal-seeded genuine CRT allocation; they are not copied from a snapshot.
    const auto kh = hash_text(key_text);
    h.w32(section + 0x2cu, key_table);
    h.w32(section + 0x30u, 1u);
    h.w32(section + 0x34u, 10u);
    h.w8(section + 0x38u, 0u);
    h.w32(section + 0x3cu, 0u);
    h.w32(key_table, kh);
    h.w32(key_table + 4u, node);

    // 50b888..940 appends the new section to the parser's one-row index. That
    // stack-local index header is intentionally not persisted in guest memory;
    // only its allocated pair table survives in the heap image.
    h.w32(section_table, hash_text(section_text));
    h.w32(section_table + 4u, section);

    // 50b947..97d inserts the key node into the list whose head is section+28.
    const auto head = m.r32(section + 0x28u);
    need(head == section + 0x14u, "490c60 list sentinel provenance drift");
    const auto next = m.r32(head + 4u);
    h.w32(node + 4u, next);
    h.w32(node + 8u, head);
    if (next) h.w32(next + 8u, node);
    h.w32(head + 4u, node);
}

void destroy_single_section(Heap& h, std::uint32_t section,
                            std::uint32_t node, std::uint32_t section_table,
                            std::uint32_t unused_filename) {

    // Section cleanup at 50fca0 first clears/frees its name, then calls the
    // node's authentic 50fe00 virtual destructor, then releases its key index.
    h.release(h.r32(section + 0x0cu)); // section-name clone
    h.release(h.r32(node + 0x0cu));    // 50fe00 key clone
    h.w32(node + 0x0cu, 0u);           // 50fe19 clears the key field
    h.release(h.r32(node + 0x10u));    // 50fe00 value clone
    h.w32(node + 0x10u, 0u);           // 50fe29 clears the value field
    need(h.r32(node+0x18u)==0u,"979 null owned child"); // h.release(h.r32(node + 0x18u));    // 50fe00 null owned-subobject field
    h.w32(node + 0x18u, 0u);           // 50fe61 clears the owned-subobject field
    // 50fe6c..50fe89 inline stores unlink node from both embedded list sentinels; its actual store
    // order clears the node links and restores the ring to the constructor state.
    h.w32(section + 0x18u, section + 0x20u);
    h.w32(section + 0x28u, section + 0x14u);
    h.w32(node + 4u, 0u);
    h.w32(node + 8u, 0u);
    h.w32(node, 0x00785afcu);
    h.release(node);

    h.release(h.r32(section + 0x2cu));
    h.w32(section + 0x2cu, 0u);
    h.w32(section + 0x30u, 0u);
    h.w32(section + 0x34u, 0u);
    h.w8(section + 0x38u, 0u);
    h.w32(section + 0x3cu, 0u);
    /* original free(NULL) has no IAT event */ // h.release(0u); // exact second 50fca0 null-free call

    // Final list/vtable state from the tail of 50fca0 and the section's
    // containing 50adf0 call; stack-only parent links have been unlinked.
    h.w32(section, 0x00785afcu);
    h.w32(section + 4u, 0u);
    h.w32(section + 8u, 0u);
    h.w32(section + 0x0cu, 0u);
    h.w32(section + 0x10u, 0x00785af4u);
    h.w32(section + 0x14u, 0x00785afcu);
    h.w32(section + 0x18u, section + 0x20u);
    h.w32(section + 0x1cu, 0u);
    h.w32(section + 0x20u, 0x00785afcu);
    h.w32(section + 0x24u, 0u);
    h.w32(section + 0x28u, section + 0x14u);
    h.w32(section + 0x2cu, 0u);
    h.w32(section + 0x30u, 0u);
    h.w32(section + 0x34u, 0u);
    h.w8(section + 0x38u, 0u);
    h.w32(section + 0x3cu, 0u);
    h.w32(section + 0x40u, 0u);
    h.release(section);

    h.release(section_table);
    /* original free(NULL) has no IAT event */ // h.release(0u); // exact null free between parser and filename teardown
    (void)unused_filename;
}


}

