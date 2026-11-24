#include "recovered/text_b104.hpp"

#include "recovered/crt_b83.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_lookup.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/leaf_b16_a.hpp"
#include "recovered/leaf_b56_b.hpp"
#include "recovered/leaf_memory.hpp"
#include "recovered/rng_b70.hpp"
#include "recovered/rng_b77.hpp"
#include "recovered/text_bytes.hpp"
#include "recovered/text_trim.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace ra2::recovered::global_b26 {
std::uint32_t fun_006eedc0(Memory&,const Inputs&);
}
namespace ra2::recovered::text_b104_extra {
using global_b26::Inputs;
using global_b26::Memory;
std::uint32_t fun_005d0a20(Memory&,const Inputs&);
std::uint32_t fun_00658480(Memory&,const Inputs&);
std::uint32_t fun_006da720(Memory&,const Inputs&);
}

namespace ra2::recovered::text_b104 {
using namespace global_b26;
namespace {
constexpr std::uint32_t text_mode=0x00b10530u;

std::uint8_t fold_ascii(std::uint8_t c) {
    return c>='A'&&c<='Z'?static_cast<std::uint8_t>(c+0x20u):c;
}

// The first eight bytes use the already accepted original body. Its fixed
// eight-iteration bound is extended here only when neither string terminated.
std::int32_t compare_original_mode_zero(Memory& m,std::uint32_t a,std::uint32_t b) {
    if(m.r32(text_mode)!=0u)
        throw std::domain_error("Block104 nonzero CRT locale mode is excluded");
    Inputs first{};first.arg[0]=a;first.arg[1]=b;
    const auto prefix=crt_b83::fun_0076d860(m,first);
    if(prefix!=0u)return s32(prefix);
    for(std::uint32_t n=0;n<8u;++n)
        if(m.r8(a+n)==0u||m.r8(b+n)==0u)return 0;
    for(std::uint32_t n=8;n<36;++n){
        const auto x=static_cast<std::uint8_t>(m.r8(a+n));
        const auto y=static_cast<std::uint8_t>(m.r8(b+n));
        if(x==y){if(x==0)return 0;continue;}
        const auto fx=fold_ascii(x),fy=fold_ascii(y);
        if(fx!=fy)return fx<fy?-1:1;
        if(fx==0)return 0;
    }
    throw std::domain_error("Block104 text comparator strings exceed 36-byte domain");
}

std::uint32_t original_lookup(Memory& m,std::uint32_t key) {
    Inputs in{};in.cx=key;in.dx=0;
    const auto found=fun_006eeb60(m,in);
    if(found==0x007e2708u)
        throw std::domain_error("Block104 required real text-table hit was absent");
    return found;
}

std::uint32_t lookup_private_text(Memory& source,const std::uint8_t* key,std::uint32_t length) {
    if(length>35u)throw std::domain_error("Block104 private text key exceeds 36-byte comparator bound");
    const auto table=source.r32(0x00ab7ec0u),count=source.r32(0x00ab7eb8u);
    const auto values=source.r32(0x00ab7ec4u);
    if(!table||!values||count==0u||count>16u)
        throw std::domain_error("Block104 private lookup requires a bounded existing text table");
    std::array<std::uint8_t,4096> table_globals{},locale_globals{};
    for(std::uint32_t n=0;n<4096u;++n){
        table_globals[n]=static_cast<std::uint8_t>(source.r8(0x00ab7000u+n));
        locale_globals[n]=static_cast<std::uint8_t>(source.r8(0x00b10000u+n));
    }
    std::array<std::uint8_t,16u*0x28u> rows{};
    std::array<std::uint8_t,16u*4u> value_pointers{};
    std::array<std::uint8_t,36> query{};
    for(std::uint32_t n=0;n<count*0x28u;++n)rows[n]=static_cast<std::uint8_t>(source.r8(table+n));
    for(std::uint32_t n=0;n<count*4u;++n)value_pointers[n]=static_cast<std::uint8_t>(source.r8(values+n));
    for(std::uint32_t n=0;n<length;++n)query[n]=key[n];
    query[length]=0;
    constexpr std::uint32_t private_query=0x33000000u;
    leaf::Memory table_page(table_globals.data(),0x00ab7000u,4096u);
    leaf::Memory locale_page(locale_globals.data(),0x00b10000u,4096u);
    leaf::Memory table_span(rows.data(),table,count*0x28u);
    leaf::Memory values_span(value_pointers.data(),values,count*4u);
    leaf::Memory query_span(query.data(),private_query,length+1u);
    Memory local;local.add(table_page);local.add(locale_page);local.add(table_span);
    local.add(values_span);local.add(query_span);
    return original_lookup(local,private_query);
}

constexpr std::array<std::uint32_t,10> side_keys={
    0x007c36ecu,0x007c36d4u,0x007c36c0u,0x007c36a8u,0x007c3690u,
    0x007c3678u,0x007c3664u,0x007c3650u,0x007c363cu,0x007c3624u};
constexpr std::array<std::int32_t,10> side_selectors={-2,0,1,2,3,4,5,6,7,8};
constexpr std::array<std::uint32_t,9> color_keys={
    0x007c37d8u,0x007c37c4u,0x007c37b0u,0x007c379cu,0x007c3784u,
    0x007c376cu,0x007c3754u,0x007c373cu,0x007c3728u};
constexpr std::array<std::int32_t,9> color_selectors={-2,0,1,2,3,4,5,6,7};
constexpr std::array<std::uint32_t,8> abbrev_keys={
    0x007c386cu,0x007c385cu,0x007c384cu,0x007c383cu,
    0x007c3828u,0x007c3814u,0x007c3800u,0x007c37f0u};
constexpr std::array<std::uint32_t,6> player_keys={
    0x007d15b0u,0x007d159cu,0x007d1588u,
    0x007d1574u,0x007d1560u,0x007d1550u};
constexpr std::array<std::uint32_t,4> object_keys={
    0x007dfe4cu,0x007bc5a8u,0x007dfe5cu,0x007dd74cu};

template<class Selectors,class Keys>
std::uint32_t selector_lookup(Memory& m,std::uint32_t selector,
                              const Selectors& selectors,const Keys& keys) {
    const auto signed_selector=s32(selector);
    for(std::size_t n=0;n<selectors.size();++n)
        if(signed_selector==selectors[n])return original_lookup(m,keys[n]);
    throw std::domain_error("Block104 selector is outside the frozen positive route");
}

struct IniGraph {
    Memory& memory;
    std::uint32_t root_address{};
    std::uint32_t root_table{};
    std::uint32_t root_count{};
    IniIndex root{};
    std::vector<IniIndexEntry> root_nodes;
    IniSection sections[4]{};
    std::array<std::uint32_t,4> section_addresses{};
    std::array<std::uint32_t,4> section_key_tables{};
    std::array<std::uint32_t,4> section_key_counts{};
    std::array<std::vector<IniIndexEntry>,4> key_nodes;
    std::array<std::vector<IniValue>,4> values;
    std::array<std::vector<std::string>,4> texts;

    static std::string read_string(Memory& m,std::uint32_t p,std::uint32_t limit=256u) {
        std::string out;out.reserve(32);
        for(std::uint32_t n=0;n<limit;++n){const auto c=static_cast<char>(m.r8(p+n));if(!c)return out;out.push_back(c);}
        throw std::domain_error("Block104 INI string exceeds bounded span");
    }
    static std::int32_t signed_key(std::uint32_t x){return s32(x);}
    static std::uint32_t hash_callback(const std::uint8_t* p,std::size_t n,void*){
        return ini_name_hash(p,n,nullptr);
    }
    static void no_sort(IniIndexEntry*,std::int32_t,IniIndexKind,void*){
        throw std::domain_error("Block104 INI sorted precondition was violated");
    }
    static std::int32_t no_upper(std::int32_t c,void*){return c;}
    IniOperations operations{hash_callback,no_sort,no_upper,nullptr,nullptr,nullptr};

    explicit IniGraph(Memory& m,std::uint32_t object):memory(m),root_address(object+0x20u){
        root_table=m.r32(root_address);root_count=m.r32(root_address+4u);
        if(root_count==0||root_count>4||m.r8(root_address+12u)==0)
            throw std::domain_error("Block104 positive INI route requires 1..4 sorted sections");
        root_nodes.resize(root_count);
        for(std::uint32_t n=0;n<root_count;++n){
            const auto entry=root_table+n*8u,section_address=m.r32(entry+4u);
            if(!section_address)throw std::domain_error("Block104 section object is null");
            root_nodes[n].key=s32(m.r32(entry));root_nodes[n].value=&sections[n];
            section_addresses[n]=section_address;
            const auto keys_index=section_address+0x2cu,table=m.r32(keys_index),count=m.r32(keys_index+4u);
            if(count==0||count>4||m.r8(keys_index+12u)==0)
                throw std::domain_error("Block104 positive INI route requires 1..4 sorted keys");
            section_key_tables[n]=table;section_key_counts[n]=count;
            key_nodes[n].resize(count);values[n].resize(count);texts[n].resize(count);
            for(std::uint32_t k=0;k<count;++k){
                const auto key_entry=table+k*8u,value=m.r32(key_entry+4u);
                auto& node=key_nodes[n][k];node.key=s32(m.r32(key_entry));
                if(value){const auto string_address=m.r32(value+0x10u);if(string_address){
                    texts[n][k]=read_string(m,string_address);
                    values[n][k].text=reinterpret_cast<const std::uint8_t*>(texts[n][k].c_str());
                    node.value=&values[n][k];
                }}
            }
            sections[n].keys={key_nodes[n].data(),static_cast<std::int32_t>(count),1,nullptr,0};
            sections[n].first=nullptr;
        }
        root={root_nodes.data(),static_cast<std::int32_t>(root_count),1,nullptr,0};
        root.cached=map_cache(m,root_address+16u,root_table,root_nodes.data(),root_count);
        for(std::uint32_t n=0;n<root_count;++n)
            sections[n].keys.cached=map_cache(m,section_addresses[n]+0x3cu,
                section_key_tables[n],key_nodes[n].data(),section_key_counts[n]);
    }

    template<class Nodes> static IniIndexEntry* map_cache(Memory& m,std::uint32_t cache,
            std::uint32_t table,Nodes nodes,std::uint32_t count){
        const auto raw=m.r32(cache);if(!raw)return nullptr;
        for(std::uint32_t k=0;k<count;++k)if(raw==table+k*8u)return nodes+k;
        throw std::domain_error("Block104 INI cache outside prepared sorted table");
    }
    void flush(){
        std::uint32_t raw=0;
        for(std::uint32_t n=0;n<root_count;++n)if(root.cached==&root_nodes[n])raw=root_table+n*8u;
        if(root.cached&&raw==0)throw std::domain_error("Block104 root cache escaped prepared table");
        if(memory.r32(root_address+16u)!=raw)memory.w32(root_address+16u,raw);
        for(std::uint32_t n=0;n<root_count;++n){
            raw=0;
            for(std::uint32_t k=0;k<section_key_counts[n];++k)
                if(sections[n].keys.cached==&key_nodes[n][k])raw=section_key_tables[n]+k*8u;
            if(sections[n].keys.cached&&raw==0)throw std::domain_error("Block104 key cache escaped prepared table");
            const auto cache=section_addresses[n]+0x3cu;
            if(memory.r32(cache)!=raw)memory.w32(cache,raw);
        }
    }
};

}

std::uint32_t fun_0076d965(Memory& m,const Inputs& i){
    auto key=i.arg[0],low=i.arg[1],count=i.arg[2];
    const auto stride=i.arg[3],comparator=i.arg[4];
    if(count==0||count>16||stride!=0x28u||comparator!=0x0076d860u)
        throw std::domain_error("Block104 0x76d965 bounded search domain violated");
    auto end=low+(count-1u)*stride;
    if(low>end)return 0;
    i.arg[1]=low;
    if(count==1)return compare_original_mode_zero(m,key,low)==0?low:0u;
    while(count>0){
        const auto half=count>>1;
        if(half==0)return compare_original_mode_zero(m,key,low)==0?low:0u;
        const auto even=(count&1u)==0u;
        i.arg[2]=count&1u;
        const auto mid=low+(half-(even?1u:0u))*stride;
        const auto relation=compare_original_mode_zero(m,key,mid);
        if(relation==0)return mid;
        if(relation<0){
            const auto upper=mid-stride;
            count=even?half-1u:half;
            end=upper;
        }else{
            low=mid+stride;i.arg[1]=low;count=half;
        }
        if(low>end)return 0;
    }
    return 0;
}

std::uint32_t fun_006eeb60(Memory& m,const Inputs& i){
    const auto key=i.cx,output=i.dx;
    if(output)m.w32(output,0);
    const auto table=m.r32(0x00ab7ec0u);
    if(table==0)return 0x007e2708u;
    const auto count=m.r32(0x00ab7eb8u);
    Inputs search{};search.arg[0]=key;search.arg[1]=table;search.arg[2]=count;
    search.arg[3]=0x28u;search.arg[4]=0x0076d860u;
    const auto found=fun_0076d965(m,search);
    if(found==0)throw std::domain_error("Block104 missing text key route is excluded");
    const auto index=m.r32(found+0x24u);
    if(index>15u)throw std::domain_error("Block104 text value index outside 0..15");
    if(output)m.w32(output,m.r32(m.r32(0x00ab7ec8u)+index*4u));
    return m.r32(m.r32(0x00ab7ec4u)+index*4u);
}

std::uint32_t fun_004d0e40(Memory& m,const Inputs& i){return selector_lookup(m,i.cx,side_selectors,side_keys);}
std::uint32_t fun_004d1600(Memory& m,const Inputs& i){return selector_lookup(m,i.cx,color_selectors,color_keys);}

std::uint32_t fun_004d1700(Memory& m,const Inputs&){
    for(std::uint32_t n=0;n<8;++n){
        const auto value=original_lookup(m,abbrev_keys[n]);
        m.w32(0x0084e408u+n*12u,value);
        m.w32(0x0084e40cu+n*12u,m.r32(0x007d1178u+n*4u));
        m.w32(0x0084e410u+n*12u,0xffffffffu);
    }
    return 0x007d1198u;
}

std::uint32_t fun_005bb2a0(Memory& m,const Inputs& i){
    const auto receiver=i.cx;
    if(m.r32(receiver)!=0 || m.r8(0x00a2793au)!=0)return 0;
    std::uint32_t units=0;while(units<512u&&m.r16(0x00a2793eu+units*2u)!=0)++units;
    if(units==0)return 1;
    if(units==512u)throw std::domain_error("Block104 configured UTF16 name exceeds ring route");
    if(m.r8(0x00a2793cu)==0)throw std::domain_error("Block104 locale comparison flag is outside the selected route");
    Inputs narrow{};narrow.cx=0x00a2793eu;const auto converted=global_b26::fun_006eedc0(m,narrow);
    Inputs compare{};compare.arg[0]=0x00a256d0u;compare.arg[1]=converted;
    if(crt_b83::fun_0076d860(m,compare)!=0)return 1u;
    throw std::domain_error("Block104 equal configured name enters unresolved dispatch");
}

std::uint32_t fun_005c3190(Memory& m,const Inputs& i){
    const auto selector=i.cx;
    constexpr std::array<std::uint32_t,5> ids={0x00a5a89cu,0x00a5a8a0u,0x00a5a8a4u,0x00a5a8a8u,0x00a5a8acu};
    unsigned selected=5;
    for(unsigned n=0;n<ids.size();++n)if(selector==m.r32(ids[n])){selected=n;break;}
    return original_lookup(m,player_keys[selected]);
}

std::uint32_t fun_00692e10(Memory& m,const Inputs& i){
    const auto c=i.cx;std::uint32_t key=0;
    if(m.r8(c+0x58u)!=0)key=object_keys[3];
    else{
        const auto child=m.r32(c+0x24u);
        if(m.r8(child+0xddu)==0)throw std::domain_error("Block104 excluded object-ready branch");
        const auto state=m.r32(c+0x60u);
        if(state>2u)throw std::domain_error("Block104 object state outside 0..2");
        key=object_keys[state];
    }
    return original_lookup(m,key);
}

std::uint32_t fun_0050c0f0(Memory& m,const Inputs& i){
    IniGraph graph(m,i.cx);
    const auto section_name=IniGraph::read_string(m,i.arg[0],8u);
    const auto key_name=IniGraph::read_string(m,i.arg[1],8u);
    const auto section_hash=s32(ini_name_hash(
        reinterpret_cast<const std::uint8_t*>(section_name.data()),section_name.size(),nullptr));
    const auto key_hash=s32(ini_name_hash(
        reinterpret_cast<const std::uint8_t*>(key_name.data()),key_name.size(),nullptr));
    auto* section_entry=fun_005106d0(graph.root,&section_hash,graph.operations);
    if(!section_entry)throw std::domain_error("Block104 INI section miss is excluded");
    graph.root.cached=section_entry;
    auto* section=static_cast<IniSection*>(section_entry->value);
    auto* key_entry=fun_005105a0(section->keys,&key_hash,graph.operations);
    if(!key_entry)throw std::domain_error("Block104 INI key miss is excluded");
    const auto section_index=static_cast<std::uint32_t>(section-graph.sections);
    graph.sections[section_index].keys.cached=key_entry;
    const auto key_index=static_cast<std::uint32_t>(key_entry-graph.key_nodes[section_index].data());
    const auto key_table=graph.section_key_tables[section_index];
    graph.flush();
    return m.r32(key_table+key_index*8u+4u);
}

std::uint32_t fun_00575900(Memory& m,const Inputs& i){
    const auto receiver=i.cx;
    auto draw=[&](std::uint32_t low,std::uint32_t high){
        rng_b70::B70Inputs call{};call.cx=0x00821558u;call.arg[0]=low;call.arg[1]=high;
        return rng_b70::fun_0062fe40(m,call);
    };
    m.w32(receiver+0x38u,draw(0,100)>=50u?1u:0u);
    m.w32(receiver+0x3cu,draw(1,4));
    m.w32(receiver+0x48u,draw(0,3));
    m.w32(receiver+0x40u,draw(0,3));
    const auto index=m.r32(receiver+0x3cu);
    m.w32(receiver+0x64u,draw(0,3));m.w32(receiver+0x68u,m.r32(receiver+0x64u));
    Inputs row{};row.cx=receiver;row.arg[0]=index;(void)global_b26::fun_005757e0(m,row);
    Inputs lookup{};lookup.cx=0x007cbfb4u;lookup.dx=0;
    const auto wide=fun_006eeb60(m,lookup);
    constexpr std::uint32_t local_base=0x34000000u,local_dest=local_base+0x100u,local_src=local_base+0x200u;
    std::array<std::uint8_t,0x400> local_bytes{};
    leaf::Memory local(local_bytes.data(),local_base,static_cast<std::uint32_t>(local_bytes.size()));
    std::uint32_t n=0;for(;n<64u;++n){const auto unit=m.r16(wide+n*2u);local.w16(local_src+n*2u,unit);if(!unit)break;}
    if(n==64u)throw std::domain_error("Block104 RNG display string exceeds bounded copy route");
    leaf::Inputs copy{};copy.arg[0]=local_dest;copy.arg[1]=local_src;(void)leaf::fun_0076efc9(local,copy);
    for(std::uint32_t k=0;k<=n;++k)m.w16(receiver+0x78u+k*2u,local.r16(local_dest+k*2u));
    rng_b70::B70Inputs final{};final.cx=0x00821558u;final.arg[0]=0;final.arg[1]=0xffffu;
    m.w32(receiver+0x74u,rng_b70::fun_0062fe40(m,final));
    std::array<std::uint8_t,0x80> clamp_bytes{};constexpr std::uint32_t clamp_base=0x34100000u;
    leaf::Memory clamp_memory(clamp_bytes.data(),clamp_base,static_cast<std::uint32_t>(clamp_bytes.size()));
    for(std::uint32_t k=0;k<0x80u;++k)clamp_memory.w8(clamp_base+k,m.r8(receiver+k));
    leaf::Inputs clamp{};clamp.cx=clamp_base;(void)leaf::fun_00575b70(clamp_memory,clamp);
    for(std::uint32_t k=0;k<0x80u;++k)m.w8(receiver+k,clamp_memory.r8(clamp_base+k));
    return m.r32(receiver+0x74u);
}

std::uint32_t fun_004107e0(Memory& m,const Inputs& i){
    const auto c=i.cx;IniGraph graph(m,i.arg[0]);
    const auto section=IniGraph::read_string(m,c+0x24u,64u);
    const auto key_name=IniGraph::read_string(m,0x007b9234u,16u);
    const auto key_ui=IniGraph::read_string(m,0x007b922cu,16u);
    auto fallback_name=IniGraph::read_string(m,c+0x64u,49u);
    auto fallback_ui=IniGraph::read_string(m,c+0x3du,32u);
    std::array<std::uint8_t,49> name_out{};std::array<std::uint8_t,32> ui_out{};
    (void)fun_0050ddf0(&graph.root,
        reinterpret_cast<const std::uint8_t*>(section.c_str()),
        reinterpret_cast<const std::uint8_t*>(key_name.c_str()),
        reinterpret_cast<const std::uint8_t*>(fallback_name.c_str()),
        name_out.data(),49,graph.operations);
    for(std::uint32_t n=0;n<49;++n)m.w8(c+0x64u+n,name_out[n]);
    (void)fun_0050ddf0(&graph.root,
        reinterpret_cast<const std::uint8_t*>(section.c_str()),
        reinterpret_cast<const std::uint8_t*>(key_ui.c_str()),
        reinterpret_cast<const std::uint8_t*>(fallback_ui.c_str()),
        ui_out.data(),32,graph.operations);
    for(std::uint32_t n=0;n<32;++n)m.w8(c+0x3du+n,ui_out[n]);
    graph.flush();
    const auto text=original_lookup(m,c+0x3du);
    m.w32(c+0x60u,text);
    return (text&0xffffff00u)|1u;
}

std::uint32_t fun_0050e460(Memory& m,const Inputs& i){
    const auto object=i.cx,output=i.arg[2],count=i.arg[3];
    if(count<3u||count>8u)throw std::domain_error("Block104 UTF16 output count outside 3..8");
    IniGraph graph(m,object);
    const auto section=IniGraph::read_string(m,i.arg[0],8u),key=IniGraph::read_string(m,i.arg[1],8u);
    static constexpr std::uint8_t empty_fallback[]={0};
    std::array<std::uint8_t,1024> private_text{};
    (void)fun_0050ddf0(&graph.root,reinterpret_cast<const std::uint8_t*>(section.c_str()),
        reinterpret_cast<const std::uint8_t*>(key.c_str()),empty_fallback,private_text.data(),1024,graph.operations);
    private_text[1023]=0;
    fun_006e41d0(private_text.data());
    graph.flush();
    std::uint32_t key_length=0;
    while(key_length<64u&&private_text[key_length])++key_length;
    if(key_length==64u)throw std::domain_error("Block104 trimmed text key exceeds private lookup buffer");
    const auto value=lookup_private_text(m,private_text.data(),key_length);
    std::array<std::uint16_t,8> source{};
    for(std::uint32_t n=0;n<count;++n)source[n]=static_cast<std::uint16_t>(m.r16(value+n*2u));
    std::array<std::uint16_t,8> copied{};
    (void)fun_0076ef62(copied.data(),source.data(),count);
    copied[count-1u]=0;
    for(std::uint32_t n=0;n<count;++n)m.w16(output+n*2u,copied[n]);
    return fun_0076ef45(copied.data());
}

std::uint32_t fun_005d0a20(Memory& m,const Inputs& i){return text_b104_extra::fun_005d0a20(m,i);}
std::uint32_t fun_00658480(Memory& m,const Inputs& i){return text_b104_extra::fun_00658480(m,i);}
std::uint32_t fun_006da720(Memory& m,const Inputs& i){return text_b104_extra::fun_006da720(m,i);}

}
