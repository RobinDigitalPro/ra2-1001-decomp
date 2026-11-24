#include "recovered/recovery_b142.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_lookup.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/text_bytes.hpp"
#include "recovered/text_trim.hpp"
#include "recovered/ini_multi.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b142 {
namespace {
using namespace ra2::recovered;
constexpr std::uint32_t tls_slot_va=0x00817778u;
constexpr std::uint32_t delimiter_va=0x007b9950u;
constexpr std::uint32_t fallback_va=0x008248a4u;

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

std::size_t append_decimal(std::uint32_t value,std::uint8_t*dst,std::size_t at){
 std::array<std::uint8_t,3>digits{};unsigned n=0;do{digits[n++]=std::uint8_t('0'+value%10);value/=10;}while(value);while(n)dst[at++]=digits[--n];return at;
}
}
std::uint32_t fun_00469d50(Memory&m,const Inputs&i){
 if(m.r32(0x81776c)!=1||m.r32(0x817560)!=0x81756a)throw std::domain_error("142 initial singlebyte C classification required");
 std::array<std::uint8_t,12>fallback{};std::size_t at=0;
 for(unsigned k=0;k<3;++k){if(k)fallback[at++]=',';at=append_decimal(m.r8(i.arg[3]+k),fallback.data(),at);}fallback[at]=0;
 OneRowGraph graph(m,i.cx+0x20);const auto section=read_z(m,i.arg[1]),key=read_z(m,i.arg[2]);
 IniOperations lookup{hash_name,sort_nodes,uppercase,nullptr,nullptr,nullptr};std::array<std::uint8_t,64>text{};
 const auto length=fun_0050ddf0(&graph.root,section.data(),key.data(),fallback.data(),text.data(),64,lookup);graph.flush();
 if(length<=0)throw std::domain_error("142 requires positive nonempty key hit");
 std::array<std::uint16_t,257>flags{};for(unsigned k=0;k<flags.size();++k)flags[k]=std::uint16_t(m.r16(0x817568+2*k));
 const CrtClassification ctype{1,flags.data(),nullptr,nullptr};std::array<std::uint32_t,3>values{};
 ScannerBuffer stream{text.data(),fun_00775160(text.data()),text.data(),0x49,0,0,0};const DecimalFieldOutputs output{{&values[0],&values[1],&values[2],nullptr}};
 const auto assigned=scan_getter_decimal_fields(stream,GetterDecimalFormat::three_csv,output,ctype);
 if(assigned!=3)throw std::domain_error("142 requires three complete assignments");
 for(unsigned k=0;k<3;++k)m.w8(i.arg[0]+k,std::uint8_t(values[k]));return i.arg[0];
}
}
