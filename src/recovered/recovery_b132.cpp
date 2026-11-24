#include "recovered/recovery_b132.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_lookup.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/text_bytes.hpp"
#include "recovered/text_trim.hpp"
#include "platform/current_crt_thread.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b132 {
namespace {
using namespace ra2::recovered;
constexpr std::uint32_t tls_slot_va=0x00817778u;
constexpr std::uint32_t ctype_width_va=0x0081776cu;
constexpr std::uint32_t ctype_table_va=0x00817560u;
constexpr std::uint32_t delimiter_va=0x007b9950u;
constexpr std::uint32_t fallback_va=0x008248a4u;
constexpr std::uint32_t buffer_bytes=0x200u;

std::vector<std::uint8_t> read_z(Memory& m,std::uint32_t p,std::uint32_t limit=512u) {
    if(!p) throw std::domain_error("0x6c480 positive route requires non-null strings");
    std::vector<std::uint8_t> out;out.reserve(32);
    for(std::uint32_t k=0;k<limit;++k){const auto c=static_cast<std::uint8_t>(m.r8(p+k));out.push_back(c);if(!c)return out;}
    throw std::domain_error("0x6c480 string exceeds bounded NUL span");
}
std::int32_t signed32(std::uint32_t v){return v<=0x7fffffffu?static_cast<std::int32_t>(v):-1-static_cast<std::int32_t>(0xffffffffu-v);}
std::uint32_t hash_name(const std::uint8_t* p,std::size_t n,void*){return ini_name_hash(p,n,nullptr);}
void sort_nodes(IniIndexEntry* p,std::int32_t n,IniIndexKind,void*){
    if(n<0)throw std::domain_error("negative bounded INI node count");
    std::sort(p,p+n,[](const auto&a,const auto&b){return a.key<b.key;});
}
std::int32_t uppercase(std::int32_t v,void*){return v>='A'&&v<='Z'?v+('a'-'A'):v;}

// A concrete bridge for the one-row guest graph in the fixture. It converts
// guest nodes to the already recovered logical INI views, then writes back the
// exact sorted/cache fields changed by 0x50ddf0's lookup closure.
struct OneRowGraph {
    Memory& m;
    std::uint32_t root_guest,root_table,section_guest,key_table,value_guest;
    std::uint32_t root_cache_before,key_cache_before;
    std::vector<std::uint8_t> text;
    IniValue value{};
    IniIndexEntry root_node{},key_node{};
    IniIndex root{};
    IniSection section{};
    OneRowGraph(Memory& memory,std::uint32_t guest):m(memory),root_guest(guest){
        root_table=m.r32(root_guest);if(m.r32(root_guest+4u)!=1u||m.r8(root_guest+12u)!=1u)throw std::domain_error("0x6c480 fixture requires one sorted section");
        root_cache_before=m.r32(root_guest+16u);
        if(root_cache_before && root_cache_before!=root_table)throw std::domain_error("section cache outside one-node table");
        root_node.key=signed32(m.r32(root_table));section_guest=m.r32(root_table+4u);
        const auto key_guest=section_guest+0x2cu;key_table=m.r32(key_guest);
        if(m.r32(key_guest+4u)!=1u||m.r8(key_guest+12u)!=1u)throw std::domain_error("0x6c480 fixture requires one sorted key");
        key_cache_before=m.r32(key_guest+16u);
        if(key_cache_before && key_cache_before!=key_table)throw std::domain_error("key cache outside one-node table");
        key_node.key=signed32(m.r32(key_table));value_guest=m.r32(key_table+4u);
        const auto text_guest=m.r32(value_guest+0x10u);text=read_z(m,text_guest);
        value.text=text.data();key_node.value=&value;
        root_node.value=&section;
        root.entries=&root_node;root.count=1;root.sorted=1;root.spare=m.r32(root_guest+8u);
        root.cached=root_cache_before?&root_node:nullptr;
        section.keys.entries=&key_node;section.keys.count=1;section.keys.sorted=1;
        section.keys.spare=m.r32(key_guest+8u);section.keys.cached=key_cache_before?&key_node:nullptr;
        section.first=nullptr;
    }
    void flush(){
        const auto root_cache=root.cached?root_table:0u;
        const auto key_cache=section.keys.cached?key_table:0u;
        if(root_cache!=root_cache_before)m.w32(root_guest+16u,root_cache);
        if(key_cache!=key_cache_before)m.w32(section_guest+0x3cu,key_cache);
        if(root.sorted!=1u||section.keys.sorted!=1u)throw std::domain_error("unexpected sort mutation outside fixture contract");
        if(root_node.value!=&section||key_node.value!=&value)throw std::domain_error("unexpected INI graph rewrite");
    }
};

struct Classifier { const CrtClassification* table; };
std::int32_t classify(std::uint8_t byte,std::uint32_t mask,void* opaque){
    const auto& c=*static_cast<Classifier*>(opaque);
    if(mask==8u)return static_cast<std::int32_t>(fun_0076e521(byte,*c.table));
    if(mask==4u)return static_cast<std::int32_t>(fun_0076e4cc(byte,*c.table));
    throw std::domain_error("0x6c480 parser requested an unobserved CRT mask");
}
std::uint32_t tls_state(Memory& m){return ra2::platform::current_crt_thread(m.r32(tls_slot_va));}

// Exact bounded effects of original RVA 0x36e802: build a delimiter bitmap,
// optional TLS continuation input, skip leading delimiters, split at one
// delimiter, and save the next cursor at real CRT thread-state +0x18.
std::uint32_t next_token(Memory& m,std::uint32_t input,std::uint32_t delims){
    std::array<std::uint8_t,32> bits{};
    for(std::uint32_t k=0;k<256u;++k){const auto c=m.r8(delims+k);if(c==0)break;bits[c>>3u]|=static_cast<std::uint8_t>(1u<<(c&7u));if(k==255u)throw std::domain_error("unbounded token delimiter string");}
    const auto state=tls_state(m);
    std::uint32_t p=input?input:m.r32(state+0x18u);
    if(!p)throw std::domain_error("token continuation is null");
    for(unsigned k=0;k<512u;++k){const auto c=m.r8(p);if(!c||!(bits[c>>3u]&(1u<<(c&7u))))break;++p;}
    const auto start=p;
    for(unsigned k=0;k<512u;++k){const auto c=m.r8(p);if(!c)break;if(bits[c>>3u]&(1u<<(c&7u))){m.w8(p,0);++p;break;}++p;}
    m.w32(state+0x18u,p);
    return start!=p?start:0u;
}
std::uint32_t parse_token(Memory& m,std::uint32_t p,const DecimalOperations& ops){
    const auto bytes=read_z(m,p,512u);
    return fun_0076e73d(bytes.data(),ops);
}
}

std::uint32_t fun_0046b460(Memory& m,const Inputs& i,std::uint32_t entry_esp){
    if(m.r32(ctype_width_va)!=1u||m.r32(ctype_table_va)!=0x81756au)throw std::domain_error("132 requires original C locale");
    std::array<std::uint8_t,0x20c> frame{};
    ra2::recovered::leaf::Memory stack_span(frame.data(),entry_esp-0x20c,0x20c);
    Memory local=m;local.add(stack_span);
    for(unsigned k=0;k<3;++k)local.w32(entry_esp-0x20c+4*k,m.r32(i.arg[3]+4*k));
    OneRowGraph graph(m,i.cx+0x20);
    const auto section=read_z(m,i.arg[1]),key=read_z(m,i.arg[2]),fallback=read_z(m,fallback_va);
    IniOperations lookup{hash_name,sort_nodes,uppercase,nullptr,nullptr,nullptr};
    const auto length=fun_0050ddf0(&graph.root,section.data(),key.data(),fallback.data(),frame.data()+12,512,lookup);
    graph.flush();if(length<=0)throw std::domain_error("132 requires positive INI hit");
    std::array<std::uint16_t,257> flags{};const auto table=m.r32(ctype_table_va)-2;
    for(unsigned k=0;k<flags.size();++k)flags[k]=static_cast<std::uint16_t>(m.r16(table+2*k));
    const CrtClassification classification{1,flags.data(),nullptr,nullptr};Classifier classifier{&classification};
    const DecimalOperations decimal{classify,&classifier};
    std::array<std::uint32_t,3> values{};
    for(unsigned k=0;k<3;++k){const auto token=next_token(local,k?0:entry_esp-512,delimiter_va);if(!token)throw std::domain_error("132 requires three nonempty tokens");values[k]=parse_token(local,token,decimal);}
    for(unsigned k=0;k<3;++k)m.w32(i.arg[0]+4*k,values[k]);
    return i.arg[0];
}
}
