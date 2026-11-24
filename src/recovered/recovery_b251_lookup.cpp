#include "recovery_b251_lookup.hpp"

#include "recovered/crt_classify.hpp"
#include "recovered/decimal_text.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_integer.hpp"
#include "recovered/name_hash.hpp"

#include <algorithm>
#include <array>
#include <stdexcept>
#include <string>

namespace ra2::recovered::recovery_b251_lookup {
namespace {
using namespace ra2::recovered;

void need(bool ok, const char* message) {
    if (!ok) throw std::domain_error(message);
}

std::int32_t signed32(std::uint32_t value) {
    return value <= 0x7fffffffu ? static_cast<std::int32_t>(value)
        : -1 - static_cast<std::int32_t>(0xffffffffu - value);
}

std::string read_z(Memory& m, std::uint32_t address, std::uint32_t limit=128u) {
    need(address != 0, "Block251 INI name must be a non-null guest pointer");
    std::string text;
    for (std::uint32_t n=0;n<limit;++n) {
        const auto byte=static_cast<std::uint8_t>(m.r8(address+n));
        if (!byte) return text;
        text.push_back(static_cast<char>(byte));
    }
    throw std::domain_error("Block251 INI name lacks a NUL in its bounded span");
}

std::uint32_t hash_name(const std::uint8_t* bytes, std::size_t length, void*) {
    return ini_name_hash(bytes,length,nullptr);
}

void sort_nodes(IniIndexEntry* entries, std::int32_t count,
                IniIndexKind, void*) {
    need(count >= 0, "negative INI index count is outside Block251 contract");
    std::sort(entries,entries+count,[](const auto& a,const auto& b){return a.key<b.key;});
}

std::int32_t lowercase_ascii(std::int32_t value, void*) {
    return value >= 'A' && value <= 'Z' ? value + ('a'-'A') : value;
}

struct Graph {
    Memory& m;
    std::uint32_t root_guest=0, root_table=0, root_sorted_before=0,
                  root_cache_before=0, section_guest=0, key_guest=0,
                  key_table=0, key_sorted_before=0, key_cache_before=0,
                  value_guest=0, value_text_guest=0;
    IniIndexEntry root_node{}, key_node{};
    IniValue value{};
    IniSection section{};
    IniIndex root{};
    std::string value_text;

    Graph(Memory& memory,std::uint32_t address):m(memory),root_guest(address) {
        root_table=m.r32(root_guest);
        const auto root_count=m.r32(root_guest+4u);
        const auto root_capacity=m.r32(root_guest+8u);
        root_sorted_before=m.r8(root_guest+12u);
        root_cache_before=m.r32(root_guest+16u);
        need(root_table && root_count==1u && root_capacity>=1u,
             "Block251 finite lookup requires one live root section row");
        need(root_sorted_before<=1u &&
             (!root_cache_before || root_cache_before==root_table),
             "root sorted/cache state is outside the one-row contract");

        root_node.key=signed32(m.r32(root_table));
        section_guest=m.r32(root_table+4u);
        need(section_guest!=0,"Intro section row has a null value");
        root_node.value=&section;
        root.entries=&root_node;root.count=1;
        root.spare=root_capacity;root.sorted=static_cast<std::uint8_t>(root_sorted_before);
        root.cached=root_cache_before?&root_node:nullptr;

        key_guest=section_guest+0x2cu;
        key_table=m.r32(key_guest);
        const auto key_count=m.r32(key_guest+4u);
        const auto key_capacity=m.r32(key_guest+8u);
        key_sorted_before=m.r8(key_guest+12u);
        key_cache_before=m.r32(key_guest+16u);
        need(key_table && key_count==1u && key_capacity>=1u,
             "Block251 finite lookup requires one live key row");
        need(key_sorted_before<=1u &&
             (!key_cache_before || key_cache_before==key_table),
             "key sorted/cache state is outside the one-row contract");

        key_node.key=signed32(m.r32(key_table));
        value_guest=m.r32(key_table+4u);
        need(value_guest!=0,"ItemMax row has a null value object");
        value_text_guest=m.r32(value_guest+0x10u);
        value_text=read_z(m,value_text_guest);
        value.text=reinterpret_cast<const std::uint8_t*>(value_text.c_str());
        key_node.value=&value;
        section.keys.entries=&key_node;
        section.keys.count=1;
        section.keys.spare=key_capacity;
        section.keys.sorted=static_cast<std::uint8_t>(key_sorted_before);
        section.keys.cached=key_cache_before?&key_node:nullptr;
        section.first=nullptr; // 50be00/50ce20 do not traverse the linked list.
    }

    void flush() {
        const auto root_cache=root.cached?root_table:0u;
        const auto key_cache=section.keys.cached?key_table:0u;
        if (root.sorted!=root_sorted_before)
            m.w8(root_guest+12u,root.sorted);
        if (root_cache!=root_cache_before)
            m.w32(root_guest+16u,root_cache);
        if (section.keys.sorted!=key_sorted_before)
            m.w8(key_guest+12u,section.keys.sorted);
        if (key_cache!=key_cache_before)
            m.w32(key_guest+16u,key_cache);
    }
};

IniOperations lookup_ops() {
    return {hash_name,sort_nodes,lowercase_ascii,nullptr,nullptr,nullptr};
}

std::array<std::uint16_t,257> c_locale_flags(Memory& m) {
    constexpr std::uint32_t width_va=0x0081776cu;
    constexpr std::uint32_t table_pointer_va=0x00817560u;
    need(m.r32(width_va)==1u && m.r32(table_pointer_va)==0x0081756au,
         "Block251 decimal route requires the pinned initial single-byte C locale");
    const auto table=m.r32(table_pointer_va)-2u;
    std::array<std::uint16_t,257> flags{};
    for (std::uint32_t k=0;k<flags.size();++k)
        flags[k]=static_cast<std::uint16_t>(m.r16(table+k*2u));
    return flags;
}

std::int32_t classify(std::uint8_t byte,std::uint32_t mask,void* context) {
    const auto& ctype=*static_cast<const CrtClassification*>(context);
    if (mask==4u)
        return static_cast<std::int32_t>(fun_0076e4cc(byte,ctype));
    if (mask==8u)
        return static_cast<std::int32_t>(fun_0076e521(byte,ctype));
    throw std::domain_error("Block251 ItemMax=-1 path requested unsupported CRT classification mask");
}

std::int32_t unsupported_scan(ScannerBuffer&,const std::uint8_t*,void*,void*) {
    throw std::domain_error("Block251 ItemMax=-1 route must not enter hexadecimal scanf");
}

} // namespace

std::uint32_t query_section(Memory& m,std::uint32_t root_index,
                            std::uint32_t section_name_z) {
    auto graph=Graph(m,root_index);
    const auto section_text=read_z(m,section_name_z);
    const auto* found=fun_0050be00(&graph.root,
        reinterpret_cast<const std::uint8_t*>(section_text.c_str()),lookup_ops());
    graph.flush();
    if (!found) return 0u;
    need(found==&graph.section,"one-row query returned an unmodeled section view");
    return graph.section_guest;
}

std::uint32_t read_integer(Memory& m,std::uint32_t root_index,
                           std::uint32_t section_name_z,
                           std::uint32_t key_name_z,
                           std::uint32_t fallback) {
    auto graph=Graph(m,root_index);
    const auto section_text=read_z(m,section_name_z);
    const auto key_text=read_z(m,key_name_z);
    need(section_text=="Intro" && key_text=="ItemMax" && graph.value_text=="-1",
         "Block251 integer adapter is bounded to the retained [Intro] ItemMax=-1 value");

    auto flags=c_locale_flags(m);
    CrtClassification ctype{1,flags.data(),nullptr,nullptr};
    DecimalOperations decimal{classify,&ctype};
    IntegerReadOperations operations{
        lookup_ops(),decimal,lowercase_ascii,unsupported_scan,nullptr};
    IniByteString section{reinterpret_cast<const std::uint8_t*>(section_text.c_str())};
    IniByteString key{reinterpret_cast<const std::uint8_t*>(key_text.c_str())};
    const auto result=fun_0050ce20(&graph.root,section,key,fallback,operations);
    graph.flush();
    return result;
}

} // namespace ra2::recovered::recovery_b251_lookup
