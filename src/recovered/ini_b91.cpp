#include "recovered/ini_b91.hpp"

#include "recovered/ini_lookup.hpp"
#include "recovered/mixed_b35_memory.hpp"
#include "recovered/name_hash.hpp"

#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace ra2::recovered::ini_b91 {
namespace {
using U = std::uint32_t;
using namespace ra2::recovered;

constexpr std::array<U,13> key_addresses{
    0x007d96fcu,0x007ddd2cu,0x007ddd1cu,0x007ddce8u,0x007ddcdcu,
    0x007ddcd0u,0x007db1a4u,0x007ddd4cu,0x007ddd38u,0x007ddd0cu,
    0x007db120u,0x007ddcf4u,0x007ddcfcu};
constexpr std::array<unsigned,13> bit_positions{14,8,9,17,16,18,6,7,15,10,12,5,11};

std::string read_z(Memory& m,U p,U limit=128u) {
    std::string text;
    text.reserve(32);
    for(U n=0;n<limit;++n){const auto c=static_cast<char>(m.r8(p+n));if(!c)return text;text.push_back(c);}
    throw std::domain_error("Block91 INI string exceeds its bounded NUL span");
}

struct Graph {
    U root_guest{},root_table{},section_guest{},key_table{};
    IniIndex root{};
    IniIndexEntry root_node{};
    IniSection section{};
    std::vector<IniIndexEntry> key_nodes;
    std::vector<IniValue> values;
    std::vector<std::string> strings;

    Graph(Memory& m,U object) {
        root_guest=object+0x20u;
        root_table=m.r32(root_guest);
        const U root_count=m.r32(root_guest+4u);
        if(root_count!=1u||m.r8(root_guest+12u)==0u)
            throw std::domain_error("Block91 route requires one sorted prepared section");
        section_guest=m.r32(root_table+4u);
        if(!section_guest)throw std::domain_error("Block91 section pointer is null");
        key_table=m.r32(section_guest+0x2cu);
        const U key_count=m.r32(section_guest+0x30u);
        if(key_count==0u||key_count>13u||m.r8(section_guest+0x38u)==0u)
            throw std::domain_error("Block91 route requires 1..13 sorted prepared keys");
        root_node={global_b26::s32(m.r32(root_table)),&section};
        root={&root_node,1,1,nullptr,0};
        key_nodes.resize(key_count);values.resize(key_count);strings.resize(key_count);
        std::int32_t previous=0;bool first=true;
        for(U n=0;n<key_count;++n){
            const U entry=key_table+n*8u,value_guest=m.r32(entry+4u);
            const auto key=global_b26::s32(m.r32(entry));
            if(!first&&key<=previous)throw std::domain_error("Block91 keys are not unique signed-sorted hashes");
            first=false;previous=key;
            key_nodes[n].key=key;
            if(value_guest){const U text_guest=m.r32(value_guest+0x10u);if(text_guest){strings[n]=read_z(m,text_guest);values[n].text=reinterpret_cast<const std::uint8_t*>(strings[n].c_str());key_nodes[n].value=&values[n];}}
        }
        section.keys={key_nodes.data(),static_cast<std::int32_t>(key_count),1,nullptr,0};
        section.first=nullptr;
        root.cached=map_cache(m,root_guest+16u,root_table,1u,&root_node);
        section.keys.cached=map_cache(m,section_guest+0x3cu,key_table,key_count,key_nodes.data());
    }

    static IniIndexEntry* map_cache(Memory& m,U cache_at,U table,U count,IniIndexEntry* nodes) {
        const U raw=m.r32(cache_at);
        if(!raw)return nullptr;
        for(U k=0;k<count;++k)if(raw==table+k*8u)return nodes+k;
        throw std::domain_error("Block91 cached INI node is outside its sorted table");
    }

    void flush(Memory& m) const {
        U root_cache=0;
        if(root.cached==&root_node)root_cache=root_table;
        else if(root.cached)throw std::domain_error("Block91 root cache escaped its one-node graph");
        if(m.r32(root_guest+16u)!=root_cache)m.w32(root_guest+16u,root_cache);
        U key_cache=0;
        for(U n=0;n<key_nodes.size();++n)if(section.keys.cached==&key_nodes[n]){key_cache=key_table+n*8u;break;}
        if(section.keys.cached&&key_cache==0)throw std::domain_error("Block91 key cache escaped its sorted graph");
        if(m.r32(section_guest+0x3cu)!=key_cache)m.w32(section_guest+0x3cu,key_cache);
    }
};

std::uint32_t hash_name(const std::uint8_t* text,std::size_t length,void*) {
    return ini_name_hash(text,length,nullptr);
}

void sorted_graph_only(IniIndexEntry*,std::int32_t,IniIndexKind,void*) {
    throw std::domain_error("Block91 fixture unexpectedly requested excluded INI sort");
}

struct UppercaseContext { Memory* memory{}; U stack{}; };
std::int32_t uppercase_initial_state(std::int32_t character,void* opaque) {
    auto& context=*static_cast<UppercaseContext*>(opaque);
    auto& m=*context.memory;
    if(m.r32(0x00b10530u)!=0u)throw std::domain_error("Block91 locale uppercase route is excluded");
    const U sp=context.stack,ret=0xb91ca11u;
    std::array<std::uint8_t,36> saved{};
    for(U n=0;n<saved.size();++n)saved[n]=static_cast<std::uint8_t>(m.r8(sp-4u+n));
    m.w32(sp,ret);m.w32(sp+4u,static_cast<U>(character));
    mixed_b35::State state{};mixed_b35::Frame frame{};
    frame.entry_sp=sp;frame.sp=sp;frame.outer_return=ret;
    const auto& entries=mixed_b35::entries_c();
    const auto it=std::find_if(entries.begin(),entries.end(),[](const auto& entry){return entry.rva==0x36e313u;});
    if(it==entries.end()||!it->function)throw std::logic_error("Block91 original uppercase implementation is unavailable");
    it->function(m,state,frame,mixed_b35::Operations{nullptr,nullptr});
    for(U n=0;n<saved.size();++n)m.w8(sp-4u+n,saved[n]);
    return global_b26::s32(state.ax);
}

} // namespace

std::uint32_t fun_00680ca0(Memory& m,const Inputs& i) {
    Graph graph(m,i.arg[0]);
    const auto section_name=read_z(m,m.r32(0x007ddc8cu),128u);
    UppercaseContext uppercase_context{&m,i.cx+0x000e0000u};
    IniOperations operations{hash_name,sorted_graph_only,uppercase_initial_state,&uppercase_context,nullptr,nullptr};
    U receiver=m.r32(i.cx);
    const U gate_word=m.r32(0x00a255c8u),gate_byte=m.r8(0x00a28953u);
    const U calls=(gate_word==0u||gate_byte!=0u)?13u:6u;
    for(U n=0;n<calls;++n){
        const auto key=read_z(m,key_addresses[n],128u);
        const U bit=bit_positions[n],prior=(receiver>>bit)&1u;
        const U value=fun_0050e860(&graph.root,
            reinterpret_cast<const std::uint8_t*>(section_name.c_str()),
            reinterpret_cast<const std::uint8_t*>(key.c_str()),
            static_cast<std::uint8_t>(prior),operations)&1u;
        receiver=(receiver&~(1u<<bit))|(value<<bit);
        m.w32(i.cx,receiver);
        graph.flush(m);
    }
    return receiver;
}

} // namespace ra2::recovered::ini_b91
