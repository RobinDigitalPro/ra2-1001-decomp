#include "recovered/recovery_b138.hpp"
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

namespace ra2::recovered::recovery_b138 {
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
std::uint32_t token_index(Memory&m,std::uint32_t token){
 for(unsigned k=0;k<11;++k){auto p=m.r32(0x7e0088+k*4);bool equal=true;
  for(unsigned j=0;j<512;++j){const auto a=m.r8(p+j),b=m.r8(token+j);if(a!=b){equal=false;break;}if(!a)break;if(j==511)throw std::domain_error("138 label exceeds bounded NUL span");}
  if(equal)return k;
 }return m.r32(0x7e0084);
}
}
std::uint32_t fun_00644e40(Memory&m,const Inputs&i,std::uint32_t entry_esp){
 OneRowGraph graph(m,i.arg[0]+0x20);
 const auto section=read_z(m,m.r32((i.arg[1]&255)?0x793f50:0x793f4c));
 IniOperations lookup{hash_name,sort_nodes,uppercase,nullptr,nullptr,nullptr};
 if(!fun_0050be00(&graph.root,section.data(),lookup))throw std::domain_error("138 requires real positive cached section");
 for(unsigned k=0;k<25;++k)m.w32(0xaa5dd0+k*4,m.r32(0x7e0084));
 const auto key=read_z(m,m.r32(0x793f54)),fallback=read_z(m,m.r32(0x793f58));
 std::array<std::uint8_t,512>buffer{};
 const auto length=fun_0050ddf0(&graph.root,section.data(),key.data(),fallback.data(),buffer.data(),512,lookup);
 graph.flush();if(length<=0)throw std::domain_error("138 requires nonempty positive key");
 ra2::recovered::leaf::Memory span(buffer.data(),entry_esp-512,512);Memory local=m;local.add(span);
 auto token=next_token(local,entry_esp-512,delimiter_va);std::uint32_t count=0;
 while(token){const auto index=token_index(local,token);if(index!=m.r32(0x7e0084))m.w32(0xaa5dd0+4*index,count);++count;token=next_token(local,0,delimiter_va);}
 const auto item=m.r32(0xaa8c9c);m.w32(0xaa5db4,count);const auto step=m.r32(item+8);
 const auto width=m.r32(m.r32(0xaa8ca0))-step*count;const auto boundptr=m.r32(0xaa8c94);const auto bound=m.r32(boundptr+8)+m.r32(boundptr);
 m.w32(0xaa5e84,width);if(signed32(width)<=signed32(bound))m.w32(0xaa5e84,bound);
 return (width&0xffffff00)|1;
}
}
