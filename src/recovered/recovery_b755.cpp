#include "recovery_b755.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_lookup.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/recovery_b142.hpp"
#include "recovered/lookup_b92.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::house_b755 {
namespace {
using namespace ra2::recovered;
std::int32_t signed32(std::uint32_t x) {
    return x <= 0x7fffffffu ? static_cast<std::int32_t>(x)
        : -1-static_cast<std::int32_t>(0xffffffffu-x);
}
std::uint32_t hash_name(const std::uint8_t* p,std::size_t n,void*) {
    return ini_name_hash(p,n,nullptr);
}
void sort_nodes(IniIndexEntry* p,std::int32_t n,IniIndexKind,void*) {
    if(n<0)throw std::domain_error("B755 excludes negative INI counts");
    std::sort(p,p+n,[](const auto&a,const auto&b){return a.key<b.key;});
}
std::int32_t uppercase(std::int32_t c,void*) {
    return c>='A'&&c<='Z'?c+('a'-'A'):c;
}
std::vector<std::uint8_t> read_z(Memory&m,std::uint32_t p) {
    if(!p)throw std::domain_error("B755 requires non-null bounded strings");
    std::vector<std::uint8_t> s;
    for(unsigned k=0;k<256;++k){auto c=std::uint8_t(m.r8(p+k));s.push_back(c);if(!c)return s;}
    throw std::domain_error("B755 string exceeds bounded 256-byte span");
}

// B142's existing positive contract uses this same logical view of the raw
// one-row fixture. The view is not an assertion about a native C++ class.
struct OneRow {
    Memory& m;
    std::uint32_t root_guest,root_table,section_guest,key_guest,key_table,value_guest;
    std::uint32_t root_cache,key_cache;
    std::vector<std::uint8_t> text;
    IniValue value{};
    IniIndexEntry root_node{},key_node{};
    IniIndex root{};
    IniSection section{};
    IniKeyNode first{},sentinel{};
    OneRow(Memory& mem,std::uint32_t receiver):m(mem),root_guest(receiver+0x20u){
        root_table=m.r32(root_guest);
        if(m.r32(root_guest+4u)!=1u||m.r8(root_guest+12u)!=1u)
            throw std::domain_error("B755 supports one sorted Colors section");
        root_cache=m.r32(root_guest+16u);
        if(root_cache!=root_table)throw std::domain_error("B755 requires warm section cache");
        root_node.key=signed32(m.r32(root_table));
        section_guest=m.r32(root_table+4u);
        key_guest=section_guest+0x2cu;
        key_table=m.r32(key_guest);
        if(m.r32(key_guest+4u)!=1u||m.r8(key_guest+12u)!=1u)
            throw std::domain_error("B755 supports one sorted key row");
        key_cache=m.r32(key_guest+16u);
        if(key_cache!=key_table)throw std::domain_error("B755 requires warm key cache");
        key_node.key=signed32(m.r32(key_table));value_guest=m.r32(key_table+4u);
        text=read_z(m,m.r32(value_guest+0x10u));value.text=text.data();key_node.value=&value;
        root_node.value=&section;root.entries=&root_node;root.count=1;root.sorted=1;
        root.cached=&root_node;root.spare=m.r32(root_guest+8u);
        section.keys.entries=&key_node;section.keys.count=1;section.keys.sorted=1;
        section.keys.cached=&key_node;section.keys.spare=m.r32(key_guest+8u);
        section.first=&first;
        // Match the existing B177 bridge's proven logical projection of the
        // original [spare,next,previous,name] linked node and sentinel.
        const auto node=m.r32(section_guest+0x18u);
        if(!node||!m.r32(node+4u)||!m.r32(node+8u))
            throw std::domain_error("B755 requires an initialized linked key and sentinel");
        const auto name_guest=m.r32(node+0xcu);
        link_name=read_z(m,name_guest);first.name=link_name.data();
        sentinel.next=nullptr;sentinel.previous=&first;sentinel.name=nullptr;
        first.next=&sentinel;first.previous=&sentinel;
    }
    std::vector<std::uint8_t> link_name;
    void flush(){
        if(root.sorted!=1||section.keys.sorted!=1||root.cached!=&root_node||section.keys.cached!=&key_node)
            throw std::domain_error("B755 warm cached indexes changed unexpectedly");
    }
};

}

std::uint32_t fun_0063ef10(Memory&m,Inputs&i,alloc735::Heap&heap){
    const auto colors=m.r32(0x00793efcu);
    if(colors!=0x007d88bcu)throw std::domain_error("B755 pins the original Colors global pointer");
    const auto receiver=i.arg[0];
    OneRow graph(m,receiver);
    IniOperations ops{hash_name,sort_nodes,uppercase,nullptr,nullptr,nullptr};
    auto section=read_z(m,colors);
    if(!fun_0050be00(&graph.root,section.data(),ops))
        throw std::domain_error("B755 positive contract requires Colors section");
    const auto count=fun_0050bf50(&graph.root,section.data(),ops);
    if(count!=1)throw std::domain_error("B755 positive contract is exactly one key");
    std::array<std::uint8_t,0x100> scratch_bytes{};
    leaf::Memory scratch_span(scratch_bytes.data(),0x35010000u,scratch_bytes.size());
    Memory local=m;local.add(scratch_span);
    std::uint32_t eax=0;
    for(std::int32_t n=0;n<count;++n){
        const auto* keyp=fun_0050c250(&graph.root,section.data(),n,ops);
        if(!keyp)throw std::domain_error("B755 linked key enumeration failed");
        // The logical view points at a temporary host copy; recover its raw
        // guest string from the original linked node for reached helpers.
        const auto link_guest=m.r32(graph.section_guest+0x18u);
        const auto key_guest=m.r32(link_guest+0xcu);
        const auto fallback=0x35010020u;
        const auto triple_addr=0x35010040u;
        local.w8(triple_addr,0);local.w8(triple_addr+1u,0);local.w8(triple_addr+2u,0);
        floating_b61::Inputs read{};
        static_cast<global_b26::Inputs&>(read)=static_cast<const global_b26::Inputs&>(i);
        read.fp=i.fp;read.cx=receiver;read.arg[0]=triple_addr;read.arg[1]=colors;
        read.arg[2]=key_guest;read.arg[3]=fallback;
        local.w8(fallback,0);local.w8(fallback+1u,0);local.w8(fallback+2u,0);
        eax=recovery_b142::fun_00469d50(local,read);i.fp=read.fp;
        // The original caller frame is reused for the three parsed bytes:
        // word [entry ESP+4] receives red/green and byte [entry ESP+6]
        // receives blue. Preserve the original high byte of arg0.
        i.arg[0]=(i.arg[0]&0xff000000u)|local.r8(triple_addr)|
            (std::uint32_t(local.r8(triple_addr+1u))<<8)|
            (std::uint32_t(local.r8(triple_addr+2u))<<16);

        global_b26::Inputs append{};
        static_cast<global_b26::Inputs&>(append)=static_cast<const global_b26::Inputs&>(i);
        append.cx=key_guest;append.dx=triple_addr;
        eax=alloc735::fun_005fb640(local,append,heap);i.ax=eax;

        global_b26::Inputs lookup{};
        static_cast<global_b26::Inputs&>(lookup)=static_cast<const global_b26::Inputs&>(i);
        lookup.cx=key_guest;lookup.arg[2]=1;
        eax=lookup_b92::fun_0065ac50(local,lookup);
        lookup.arg[2]=0x35;
        eax=lookup_b92::fun_0065ac50(local,lookup);
        if(eax==0)throw std::domain_error("B755 second positive palette record missing");
    }
    graph.flush();
    i.ax=(eax&0xffffff00u)|1u;
    return i.ax;
}
}
