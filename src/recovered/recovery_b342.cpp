#include "recovered/global_b26_memory.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/scanner_input.hpp"
#include "recovered/text_b104.hpp"
#include "recovered/text_bytes.hpp"
#include "recovered/text_trim.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

// Finite positive single-pair INI route; see Block342 contract.
namespace ra2::recovered::recovery_b342 {
using namespace global_b26;
namespace {
void need(bool ok,const char* why){if(!ok)throw std::domain_error(why);}
std::string read_string(const Memory& m,std::uint32_t p,std::uint32_t cap=64u){
    need(p!=0,"B342 string pointer is nonnull");std::string s;s.reserve(24);
    for(std::uint32_t n=0;n<cap;++n){const auto c=static_cast<char>(m.r8(p+n));if(!c)return s;s.push_back(c);}
    throw std::domain_error("B342 string exceeds its bounded span");
}
std::int32_t signed_hash(std::uint32_t v){return v<=0x7fffffffu?static_cast<std::int32_t>(v):-1-static_cast<std::int32_t>(0xffffffffu-v);}
struct IniGraph {
    Memory& m;std::uint32_t address{},table{},count{};IniIndex root{};std::vector<IniIndexEntry> sections;
    IniSection section_views[4]{};std::uint32_t section_addr[4]{},key_table[4]{},key_count[4]{};
    std::vector<IniIndexEntry> keys[4];std::vector<IniValue> vals[4];std::vector<std::string> text[4];
    static std::uint32_t hash(const std::uint8_t*p,std::size_t n,void*){return ini_name_hash(p,n,nullptr);}
    static void no_sort(IniIndexEntry*,std::int32_t,IniIndexKind,void*){throw std::domain_error("B342 sorted-table precondition violated");}
    static std::int32_t no_upper(std::int32_t c,void*){return c;}
    IniOperations ops{hash,no_sort,no_upper,nullptr,nullptr,nullptr};
    static IniIndexEntry* cached(Memory&m,std::uint32_t cache,std::uint32_t base,IniIndexEntry*nodes,std::uint32_t n){
        const auto p=m.r32(cache);if(!p)return nullptr;for(std::uint32_t k=0;k<n;++k)if(p==base+8u*k)return nodes+k;
        throw std::domain_error("B342 cache pointer is outside its original table");
    }
    explicit IniGraph(Memory&mem,std::uint32_t obj):m(mem),address(obj+0x20u){
        table=m.r32(address);count=m.r32(address+4u);
        need(count==1u&&table&&m.r8(address+12u)==1u,"B342 fixture has one sorted INI section");
        sections.resize(count);const auto entry=table,section=m.r32(entry+4u);need(section,"B342 section pointer is nonnull");
        sections[0].key=signed_hash(m.r32(entry));sections[0].value=&section_views[0];section_addr[0]=section;
        const auto ki=section+0x2cu;key_table[0]=m.r32(ki);key_count[0]=m.r32(ki+4u);
        need(key_count[0]==3u&&key_table[0]&&m.r8(ki+12u)==1u,"B342 fixture has three sorted INI keys");
        keys[0].resize(3);vals[0].resize(3);text[0].resize(3);
        for(std::uint32_t k=0;k<3u;++k){const auto row=key_table[0]+8u*k,v=m.r32(row+4u);need(v,"B342 value pointer is nonnull");
            const auto str=m.r32(v+0x10u);text[0][k]=read_string(m,str,128u);vals[0][k].text=reinterpret_cast<const std::uint8_t*>(text[0][k].c_str());
            keys[0][k]={signed_hash(m.r32(row)),&vals[0][k]};}
        section_views[0].keys={keys[0].data(),3,1,nullptr,0};section_views[0].first=nullptr;
        root={sections.data(),1,1,nullptr,0};root.cached=cached(m,address+16u,table,sections.data(),1);
        section_views[0].keys.cached=cached(m,ki+16u,key_table[0],keys[0].data(),3);
    }
    void flush(){std::uint32_t raw=0;
        if(root.cached){need(root.cached==sections.data(),"B342 section cache remains within sole row");raw=table;}if(m.r32(address+16u)!=raw)m.w32(address+16u,raw);
        raw=0;if(section_views[0].keys.cached){bool found=false;for(unsigned k=0;k<3;++k)if(section_views[0].keys.cached==keys[0].data()+k){raw=key_table[0]+8u*k;found=true;break;}need(found,"B342 key cache remains within three rows");}
        const auto p=section_addr[0]+0x3cu;if(m.r32(p)!=raw)m.w32(p,raw);
    }
};
struct Pair {std::uint32_t first,second;};
std::int32_t scan_two_positive(ScannerBuffer&s,const std::uint8_t*f,void*va,void*){
    need(f[0]=='%'&&f[1]=='d'&&f[2]==','&&f[3]=='%'&&f[4]=='d'&&f[5]==0,"B342 original format is %d,%d");
    auto&out=*static_cast<Pair*>(va);auto*p=s.cursor;std::uint32_t value[2]{};
    for(unsigned field=0;field<2;++field){unsigned digits=0;while(*p>='0'&&*p<='9'){value[field]=value[field]*10u+unsigned(*p-'0');++p;++digits;need(digits<=3,"B342 decimal is bounded to three digits");}need(digits,"B342 selected value contains two decimal fields");if(field==0)need(*p++==',',"B342 selected value is comma separated");}
    need(*p==0,"B342 selected value ends after two fields");out.first=value[0];out.second=value[1];s.cursor=p;s.remaining=0;return 2;
}
void decimal_key(unsigned n,std::array<std::uint8_t,16>&out){
    if(n>=10u){out[0]=static_cast<std::uint8_t>('0'+n/10u);out[1]=static_cast<std::uint8_t>('0'+n%10u);out[2]=0;}
    else {out[0]=static_cast<std::uint8_t>('0'+n);out[1]=0;}
}
}

std::uint32_t fun_0065fbc0(Memory&m,const Inputs&i){
    const auto receiver=i.cx,ini=i.arg[0];need(receiver&&ini,"B342 requires nonnull receiver and INI object");
    need(m.r8(0x007b994cu)=='%'&&m.r8(0x007b994du)=='d'&&m.r8(0x007b994eu)==0u,
         "B342 loop requires the pinned original %d format literal");
    Inputs prepare{};prepare.cx=receiver;prepare.arg[0]=ini;
    if((text_b104::fun_004107e0(m,prepare)&0xffu)==0u)return 0u;
    need(read_string(m,receiver+0x64u,49u)=="Tank"&&read_string(m,receiver+0x3du,32u)=="TXT_X",
         "B342 selected route requires real Name=Tank and UIName=TXT_X reads");
    IniGraph graph(m,ini);const auto section=read_string(m,receiver+0x24u,64u);
    m.w32(receiver+0xa0u,0u);const std::uint8_t empty[]={static_cast<std::uint8_t>(m.r8(0x008248a4u))};
    need(empty[0]==0u,"B342 fallback bytes match the original empty literal at 0x8248a4");
    for(unsigned n=0;n<50u;++n){
        std::array<std::uint8_t,16> key{};decimal_key(n,key);(void)fun_006e41d0(key.data());
        std::array<std::uint8_t,0x80> output{};
        const auto length=fun_0050ddf0(&graph.root,reinterpret_cast<const std::uint8_t*>(section.c_str()),key.data(),empty,output.data(),0x80,graph.ops);
        if(length<=0)continue;
        // The cached 0x6e0220 body directly calls 0x76f070 with its pinned format;
        // for this route both output words are assigned by the accepted scanner.
        std::array<std::uint8_t,6> format{};for(unsigned k=0;k<format.size();++k)format[k]=static_cast<std::uint8_t>(m.r8(0x007bcea8u+k));
        Pair parsed{};const auto assigned=fun_0076f070(output.data(),format.data(),&parsed,scan_two_positive,nullptr);
        need(assigned==2,"B342 positive value reaches both actual scanner conversions");
        const auto count=m.r32(receiver+0xa0u);need(count<50u,"B342 receiver count remains in original 50-row bound");
        m.w32(receiver+0xa4u+count*8u,parsed.first);m.w32(receiver+0xa8u+count*8u,parsed.second);m.w32(receiver+0xa0u,count+1u);
    }
    graph.flush();need(m.r32(receiver+0xa0u)==1u,"B342 selected fixture must contain exactly one positive pair");return 1u;
}
}
