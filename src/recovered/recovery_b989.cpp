#define NOMINMAX
#include <windows.h>

#include "recovered/recovery_b989.hpp"
#include "recovered/name_hash.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <string_view>

namespace ra2::recovered::b989 {
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}

std::string read_z(Memory& m, std::uint32_t p) {
    need(p != 0, "B989 bounded route needs a non-null PE string");
    std::string out;
    for (std::uint32_t n = 0; n != 128; ++n) {
        const auto c = static_cast<unsigned char>(m.r8(p + n));
        if (!c) return out;
        out.push_back(static_cast<char>(c));
    }
    throw std::domain_error("B989 PE string exceeds bounded 128-byte scan");
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
                          std::uint32_t key_table, std::uint32_t section_table) {
    need(section && section_name && node && key_copy && value_copy && key_table && section_table,
         "B989 successful route requires the successful parsed allocation graph");

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
    // 50b7b3..7ef. Unused payload bytes retain the actual ordinary-heap ordinal seed.
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
    // the explicit ordinal-seeded actual ordinary allocation; they are not copied from a snapshot.
    const auto kh = hash_text("AutoLogin");
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
    h.w32(section_table, hash_text("Ask"));
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
                            std::uint32_t filename) {

    // Section cleanup at 50fca0 first clears/frees its name, then calls the
    // node's authentic 50fc10 virtual destructor, then releases its key index.
    h.release(h.r32(section + 0x0cu)); // section-name clone
    h.release(h.r32(node + 0x0cu));    // 50fc10 key clone
    h.w32(node + 0x0cu, 0u);           // 50fc29 clears the key field
    h.release(h.r32(node + 0x10u));    // 50fc10 value clone
    h.w32(node + 0x10u, 0u);           // 50fc39 clears the value field
    need(h.r32(node+0x18u)==0u,"B989 null child"); // h.release(h.r32(node + 0x18u));    // 50fc10 null owned-subobject field
    h.w32(node + 0x18u, 0u);           // 50fc71 clears the owned-subobject field
    // 6906b0 unlinks node from both embedded list sentinels; its actual store
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
    h.release(filename);
}

std::string read_bounded_ini_value(Heap& h, std::uint32_t buffer,
                                  std::uint32_t bytes) {
    static constexpr std::string_view prefix = "[Ask]\r\nAutoLogin=";
    need(bytes == 21u || bytes == 22u,
         "bounded INI fixture must have a two- or three-character value");
    for (std::uint32_t n = 0; n < prefix.size(); ++n)
        need(h.r8(buffer + n) == static_cast<std::uint8_t>(prefix[n]),
             "bounded INI section/key syntax changed");
    const auto value_size = bytes - static_cast<std::uint32_t>(prefix.size()) - 2u;
    need(value_size == 2u || value_size == 3u,
         "bounded INI value must contain two or three ASCII characters");
    std::string value;
    for (std::uint32_t n = 0; n < value_size; ++n)
        value.push_back(static_cast<char>(h.r8(buffer + prefix.size() + n)));
    const auto tail = buffer + static_cast<std::uint32_t>(prefix.size()) + value_size;
    need(h.r8(tail) == '\r' && h.r8(tail + 1u) == '\n',
         "bounded INI line ending changed");
    need(value == "yes" || value == "Yes" || value == "YES" ||
         value == "no" || value == "No" || value == "NO",
         "bounded INI value spelling is outside the fixture family");
    return value;
}
}

std::uint32_t run(Memory& m, const Inputs&, Heap& h, FileApi& api,std::uint32_t root_rva) {
    need(root_rva==0x32d870u,"B989 selected root");
    need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u,"B989 genuine ordinary CRT route");
    constexpr std::uint32_t kFileNameVa = 0x007e6a70u;
    constexpr std::uint32_t kSectionVa = 0x007e6accu;
    constexpr std::uint32_t kKeyVa = 0x007e6ad0u;
    const auto filename_text = read_z(m, kFileNameVa);
    need(filename_text == "wolinfo.ini", "B989 is limited to literal wolinfo.ini");

    // 46f930/46fd50's cloned filename buffer (first 0x0c request).
    const auto filename = h.allocate(0x0cu);
    need(filename != 0, "filename clone allocation failed");
    write_z(h, filename, filename_text);

    const auto path = reinterpret_cast<const char*>(std::uintptr_t(filename));
    // Actual 630060 existence probes and reader open: no API return is mocked.
    for (unsigned n = 0; n != 2; ++n) {
        const HANDLE probe = api.create_file_a(path, GENERIC_READ, FILE_SHARE_READ, nullptr,
                                                OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
        need(probe != INVALID_HANDLE_VALUE, "real file existence probe failed");
        need(api.close_handle(probe) != FALSE, "real existence-probe CloseHandle failed");
    }
    const HANDLE input = api.create_file_a(path, GENERIC_READ,
        FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, nullptr);
    need(input != INVALID_HANDLE_VALUE, "real parser CreateFileA failed");

    // Original 50b080 reader uses an ordinary malloc4096 buffer (flags0 at CRT threshold0).
    const auto line_buffer = h.allocate_reader();
    need(line_buffer != 0, "real ordinary HeapAlloc(0x1000) failed");
    DWORD got = 0;
    need(api.read_file(input, reinterpret_cast<void*>(std::uintptr_t(line_buffer)),
                       0x1000u, &got, nullptr) != FALSE && (got == 21u || got == 22u),
         "real first parser ReadFile must return the bounded fixture bytes");
    DWORD got_eof = 0;
    need(api.read_file(input, reinterpret_cast<void*>(std::uintptr_t(line_buffer + got)),
                       0x1000u - got, &got_eof, nullptr) != FALSE && got_eof == 0u,
         "real parser second ReadFile must observe EOF at the fixture length");
    need(api.read_file(input, reinterpret_cast<void*>(std::uintptr_t(line_buffer)),
                       0x1000u, &got_eof, nullptr) != FALSE && got_eof == 0u,
         "real parser final ReadFile must observe EOF at the fixture length");
    const auto value_text = read_bounded_ini_value(h, line_buffer, got);

    const auto section_text = read_z(m, kSectionVa);
    const auto key_text = read_z(m, kKeyVa);
    need(section_text == "Ask" && key_text == "AutoLogin",
         "bounded section/key literals changed");

    // Exact parser allocations after the line reader: section, its name,
    // key node, value clone, key clone, section-index table, key-index table.
    const auto section = h.allocate(0x44u);
    const auto section_name = h.allocate(4u);
    const auto node = h.allocate(0x28u);
    const auto value_copy = h.allocate(static_cast<std::uint32_t>(value_text.size() + 1u));
    const auto key_copy = h.allocate(0x0au);
    const auto key_table = h.allocate(0x50u);
    const auto section_table = h.allocate(0x50u);
    write_z(h, section_name, section_text);
    write_z(h, value_copy, value_text);
    write_z(h, key_copy, key_text);
    build_single_section(h, h, section, section_name, node, key_copy,
                         value_copy, key_table, section_table);

    // The parser frees its ordinary input buffer before returning. The root
    // closes its reader only after that parser cleanup, then performs lookup.
    h.free_reader(line_buffer);

    // Root closes the file after parser EOF, then resolves Ask/AutoLogin
    // and interprets the real stored value's first byte through 76e313.
    need(api.close_handle(input) != FALSE, "real parser CloseHandle failed");
    const auto name_hash = hash_text(section_text);
    const auto key_hash = hash_text(key_text);
    need(h.r32(section_table) == name_hash && h.r32(section_table + 4u) == section,
         "one-row original section lookup failed");
    need(h.r32(key_table) == key_hash && h.r32(key_table + 4u) == node,
         "one-row original key lookup failed");
    //50E860's fresh singleton section5106D0 sorts count1 (no row move),
    //sets sorted/cache, then its second sectionquery hits that cache.
    //The sectionindex header lives only on the original root stack.
    //The keyheader is real heap storage and its5105A0 writes remain observable
    //until the authentic destructor clears them.
    need(h.r8(section+0x38u)==0u&&h.r32(section+0x3cu)==0u,"B989 fresh keyindex");
    h.w32(section+0x3cu,0u);h.w8(section+0x38u,1u);h.w32(section+0x3cu,key_table);
    const auto first = static_cast<unsigned char>(h.r8(h.r32(h.r32(key_table+4u)+0x10u)));
    need(first == 'y' || first == 'Y' || first == 'n' || first == 'N',
         "bounded truth selector only supports the observed Y/N dispatch entries");

    destroy_single_section(h, section, node, section_table, filename);
    // 42F250 calls630060. That restores793C84 and calls authentic slot18h
    // [793C9C]=630A70. Its XOREAX,EAX/SETNEAL returns zero for the already
    // closed handleFFFFFFFF. The owned-buffer byte1Ch iszero. Thus cleanup
    // leaves fullEAX0 before72D954 restores just the positive truthAL.
    return first == 'y' || first == 'Y' ? 1u : 0u;
}
std::uint32_t fun_0072d870(Memory&m,const Inputs&i,Heap&h,FileApi&a){return ra2::recovered::b989::run(m,i,h,a,0x32d870u);}
}
