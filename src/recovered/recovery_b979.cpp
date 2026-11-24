#define NOMINMAX
#include <windows.h>

#include "recovered/recovery_b979.hpp"
#include "recovered/name_hash.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <string_view>

namespace ra2::recovered::b979 {
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
                            std::uint32_t filename) {

    // Section cleanup at 50fca0 first clears/frees its name, then calls the
    // node's authentic 50fc10 virtual destructor, then releases its key index.
    h.release(h.r32(section + 0x0cu)); // section-name clone
    h.release(h.r32(node + 0x0cu));    // 50fc10 key clone
    h.w32(node + 0x0cu, 0u);           // 50fc29 clears the key field
    h.release(h.r32(node + 0x10u));    // 50fc10 value clone
    h.w32(node + 0x10u, 0u);           // 50fc39 clears the value field
    need(h.r32(node+0x18u)==0u,"979 null owned child"); // h.release(h.r32(node + 0x18u));    // 50fc10 null owned-subobject field
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


}

std::uint32_t run(Memory& m, const Inputs& in, Heap& h, FileApi& api,std::uint32_t root_rva) {
    need(root_rva==0x32dc70u||root_rva==0x32def0u,"979 selected roots");
    need(m.r32(in.cx)==0u,"979 receiver begins unowned");
    need(m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u,"979 ordinary CRT route");
    const auto filename_text=read_z(m,0x7e6a70u);
    const auto section_text=read_z(m,0x7e6aecu);
    const auto key_text=read_z(m,root_rva==0x32dc70u?0x7e6ad0u:0x7e6afcu);
    need(filename_text=="wolinfo.ini"&&section_text=="DefaultPersona","979 pinned text");
    const auto filename=h.allocate(12u);write_z(h,filename,filename_text);
    const auto path=reinterpret_cast<const char*>(std::uintptr_t(filename));
    for(unsigned n=0;n<2;++n){const HANDLE probe=api.create_file_a(path,GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);need(probe!=INVALID_HANDLE_VALUE,"979 actual existence probe");need(api.close_handle(probe)!=FALSE,"979 actual probe close");}
    const HANDLE input=api.create_file_a(path,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr);need(input!=INVALID_HANDLE_VALUE,"979 actual input open");
    const auto buffer=h.allocate_reader();DWORD got=0,eof=0;
    need(api.read_file(input,reinterpret_cast<void*>(std::uintptr_t(buffer)),4096u,&got,nullptr)!=FALSE,"979 real read");
    need(got==40u,"979 finite file size");
    need(api.read_file(input,reinterpret_cast<void*>(std::uintptr_t(buffer+got)),4096u-got,&eof,nullptr)!=FALSE&&eof==0u,"979 actual EOF1");
    need(api.read_file(input,reinterpret_cast<void*>(std::uintptr_t(buffer)),4096u,&eof,nullptr)!=FALSE&&eof==0u,"979 actual EOF2");
    const auto parsed=std::string(reinterpret_cast<const char*>(std::uintptr_t(buffer)),got);
    const auto prefix=std::string("[DefaultPersona]\r\n");
    need(parsed.compare(0,prefix.size(),prefix)==0,"979 section syntax");
    const auto equal=parsed.find('=',prefix.size());need(equal!=std::string::npos,"979 key syntax");
    const auto parsed_key=parsed.substr(prefix.size(),equal-prefix.size());
    need(parsed_key==key_text,"979 exact byte-sensitive hashed key");
    const auto value_text=parsed.substr(equal+1u,10u);need(value_text.size()==10u&&parsed.substr(equal+11u)=="\r\n","979 ten-byte value and CRLF");
    for(const auto c:value_text)need(c>32&&c<127&&c!=';'&&c!='=',"979 finite nonspace ASCII token");
    const auto section=h.allocate(68u),section_name=h.allocate(15u),node=h.allocate(40u),value_copy=h.allocate(11u),key_copy=h.allocate(10u),key_table=h.allocate(80u),section_table=h.allocate(80u);
    write_z(h,section_name,section_text);write_z(h,value_copy,value_text);write_z(h,key_copy,parsed_key);
    build_single_section(h,h,section,section_name,node,key_copy,value_copy,key_table,section_table,section_text,parsed_key);
    h.free_reader(buffer);need(api.close_handle(input)!=FALSE,"979 actual parser close");
    // 759260 constructs key and section temporary holders only after parsing.
    const auto key_temporary=h.allocate(10u);write_z(h,key_temporary,key_text);
    const auto section_temporary=h.allocate(15u);write_z(h,section_temporary,section_text);
    // Fresh parsed section and key indexes start sorted=0/cache=0. The original
    // 5106D0/5105A0 qsort count1 leaves rows untouched and sets sorted=1/cache=0;
    // 50DF90 then publishes each found row;510440/510220 hit that same cache.
    need(h.r32(section_table)==hash_text(section_text)&&h.r32(section_table+4u)==section,"979 positive section row");
    need(h.r8(section+0x38u)==0u&&h.r32(section+0x3cu)==0u,"979 fresh key index");
    h.w32(section+0x3cu,0u);h.w8(section+0x38u,1u);h.w32(section+0x3cu,key_table);
    need(h.r32(key_table)==hash_text(key_text)&&h.r32(key_table+4u)==node,"979 positive key row");
    // 76DD10 bounded copy and6E41D0 trim are identities on this finite
    // ten-byte printable token;759500 allocates and copies all11 bytes.
    const auto found_section=h.r32(section_table+4u);
    const auto found_node=h.r32(h.r32(found_section+0x2cu)+4u);
    const auto found_value=h.r32(found_node+0x10u);
    std::string looked_up;for(unsigned k=0;k<11u;++k){const auto c=h.r8(found_value+k);if(!c)break;looked_up.push_back(char(c));}
    need(looked_up.size()==10u&&h.r8(found_value+10u)==0u,"979 actual parsed value node");
    const auto output=h.allocate(11u);write_z(h,output,looked_up);
    h.release(section_temporary);h.release(key_temporary);
    const auto receiver_value=h.allocate(11u);for(unsigned k=0;k<11u;++k)h.w8(receiver_value+k,h.r8(output+k));m.w32(in.cx,receiver_value);
    h.release(output);
    destroy_single_section(h,section,node,section_table,filename);
    return in.cx;
}
std::uint32_t fun_0072dc70(Memory&m,const Inputs&i,Heap&h,FileApi&a){return run(m,i,h,a,0x32dc70u);}
std::uint32_t fun_0072def0(Memory&m,const Inputs&i,Heap&h,FileApi&a){return run(m,i,h,a,0x32def0u);}
}
