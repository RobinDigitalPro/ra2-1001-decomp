#include "recovered/recovery_b481.hpp"
#include "recovered/crt_b83.hpp"
#include "recovered/crt_classify.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_integer.hpp"
#include "recovered/ini_lookup.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/text_b104.hpp"
#include "recovered/leaf_text_rng.hpp"
#include "recovered/leaf_memory.hpp"

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

namespace ra2::recovered::recovery_b481 {
namespace {
using U=std::uint32_t;
using namespace global_b26;
[[noreturn]] void fail(const char* s){throw std::domain_error(s);}
void need(bool v,const char* s){if(!v)fail(s);}
std::string zstr(const Memory& m,U p,U limit=512u){
    need(p!=0,"B481 requires nonnull text");std::string s;s.reserve(24);
    for(U n=0;n<limit;++n){const auto c=static_cast<char>(m.r8(p+n));if(!c)return s;s.push_back(c);}
    fail("B481 text exceeds bounded input span");
}
std::int32_t signed_hash(U v){return v<=0x7fffffffu?static_cast<std::int32_t>(v):-1-static_cast<std::int32_t>(0xffffffffu-v);}
struct Graph {
    Memory& m;U ini{},object{},section{};IniIndex root{};IniSection sec{};
    std::array<IniIndexEntry,1> sections{};std::array<IniIndexEntry,7> keys{};
    std::array<IniValue,7> values{};std::array<std::string,7> strings{};
    IniOperations ops{};
    static U hash(const std::uint8_t* p,std::size_t n,void*){return ini_name_hash(p,n,nullptr);}
    static void no_sort(IniIndexEntry*,std::int32_t,IniIndexKind,void*){fail("B481 requires original sorted INI indices");}
    static std::int32_t upper(std::int32_t c,void*){return c>='a'&&c<='z'?c-('a'-'A'):c;}
    static IniIndexEntry* cached(Memory& m,U address,U table,IniIndexEntry* entries,U count){
        const U p=m.r32(address);if(!p)return nullptr;for(U n=0;n<count;++n)if(p==table+8u*n)return entries+n;
        fail("B481 cache pointer escaped its original index");
    }
    explicit Graph(Memory& mem,U p,U receiver):m(mem),ini(p),object(receiver){
        need(p,"B481 requires a nonnull INI object");const U root_addr=p+0x20u,rt=m.r32(root_addr);
        need(m.r32(root_addr+4u)==1u&&rt&&m.r8(root_addr+12u)==1u,"B481 requires one initialized sorted section");
        const U row=rt;section=m.r32(row+4u);need(section,"B481 section row must point to a section object");
        sections[0]={signed_hash(m.r32(row)),&sec};root={sections.data(),1,1,nullptr,1};
        root.cached=cached(m,root_addr+16u,rt,sections.data(),1);
        const U ki=section+0x2cu,kt=m.r32(ki);need(m.r32(ki+4u)==7u&&kt&&m.r8(ki+12u)==1u,"B481 requires seven initialized sorted keys");
        for(U n=0;n<7u;++n){const U kr=kt+8u*n,vp=m.r32(kr+4u),tp=m.r32(vp+0x10u);strings[n]=zstr(m,tp,128u);values[n].text=reinterpret_cast<const std::uint8_t*>(strings[n].c_str());keys[n]={signed_hash(m.r32(kr)),&values[n]};if(n)need(keys[n-1].key<keys[n].key,"B481 key hashes must be unique signed-sorted hits");}
        sec.keys={keys.data(),7,1,nullptr,7};sec.keys.cached=cached(m,ki+16u,kt,keys.data(),7);ops={hash,no_sort,upper,nullptr,nullptr,nullptr};
    }
    void flush(){
        const U ra=ini+0x20u,rt=m.r32(ra),ki=section+0x2cu,kt=m.r32(ki);U cache=0;
        if(root.cached){need(root.cached==sections.data(),"B481 root cache must remain in its sole row");cache=rt;}if(m.r32(ra+16u)!=cache)m.w32(ra+16u,cache);
        cache=0;if(sec.keys.cached){for(U n=0;n<7u;++n)if(sec.keys.cached==keys.data()+n){cache=kt+8u*n;break;}need(cache,"B481 key cache must remain in the seven-row table");}if(m.r32(ki+16u)!=cache)m.w32(ki+16u,cache);
    }
};
struct Ctx {std::array<std::uint16_t,257> flags{};CrtClassification ctype{};};
std::int32_t classify(std::uint8_t b,U mask,void* p){auto& c=*static_cast<Ctx*>(p);return static_cast<std::int32_t>(c.flags[static_cast<U>(b)+1u]&mask);}
Ctx init_context(Memory& m){Ctx c{};const U raw=m.r32(0x817560u);need(raw==0x81756au,"B481 requires warmed original single-byte CRT classification");for(U n=0;n<257u;++n)c.flags[n]=static_cast<std::uint16_t>(m.r16(raw-2u+n*2u));c.ctype={1,c.flags.data(),nullptr,nullptr};return c;}
IntegerReadOperations integer_ops(const IniOperations& ops,Ctx& ctx){return {ops,{classify,&ctx},[](std::int32_t c,void*){return c>='A'&&c<='Z'?c+('a'-'A'):c;},nullptr,nullptr};}
U read_int(Memory& m,Graph& g,Ctx& ctx,U key,U fallback){
    auto sec=zstr(m,g.object+0x24u),k=zstr(m,key);const U v=fun_0050cc40(&g.root,reinterpret_cast<const std::uint8_t*>(sec.c_str()),reinterpret_cast<const std::uint8_t*>(k.c_str()),fallback,integer_ops(g.ops,ctx));g.flush();return v;
}
U read_text(Memory& m,Graph& g,U key,U fallback,std::uint8_t* dst,U cap){
    auto sec=zstr(m,g.object+0x24u),k=zstr(m,key);std::string fb;if(fallback)fb=zstr(m,fallback);const U n=static_cast<U>(fun_0050ddf0(&g.root,reinterpret_cast<const std::uint8_t*>(sec.c_str()),reinterpret_cast<const std::uint8_t*>(k.c_str()),fallback?reinterpret_cast<const std::uint8_t*>(fb.c_str()):nullptr,dst,static_cast<std::int32_t>(cap),g.ops));g.flush();return n;
}
}

std::uint32_t fun_004651f0(Memory& m,const Inputs& in){
    const U object=in.cx,ini=in.arg[0];need(object&&ini,"B481 requires nonnull object and INI");
    Inputs prepare{};prepare.cx=object;prepare.arg[0]=ini;
    if((text_b104::fun_004107e0(m,prepare)&0xffu)==0u)return 0u;
    Graph graph(m,ini,object);
    auto ctx=init_context(m);
    m.w32(object+0x98u,read_int(m,graph,ctx,0x007bc40cu,m.r32(object+0x98u)));

    // 0x46a810 reads the present mode string through 0x50ddf0, then 0x82c00.
    // The fixture pins the global option count at zero, so the real helper's
    // terminal search result is -1 and it returns its caller-provided default.
    // Keep that helper's actual buffer write and INI cache effect in this model.
    std::array<std::uint8_t,0x80> mode{};
    const U mode_len=read_text(m,graph,0x007bc400u,0x008248a4u,mode.data(),0x80u);
    need(mode_len>0u,"B481 mode route requires a present nonempty value");
    constexpr U mode_guest=0x34000000u;leaf::Memory mode_span(mode.data(),mode_guest,static_cast<U>(mode.size()));Memory local=m;local.add(mode_span);
    Inputs compare{};compare.arg[0]=mode_guest;compare.arg[1]=0x007b8e5cu;
    need(m.r32(0x00a58c78u)==0u,"B481 pins empty global mode option table");
    (void)crt_b83::fun_0076d860(local,compare); // first comparison of original 0x82c00

    // The root updates a receiver string through 0x50ddf0 using its current
    // contents as fallback, then applies the in-place uppercase helper.
    std::array<std::uint8_t,0x200> display_name{};
    for(U n=0;n<display_name.size();++n)display_name[n]=static_cast<std::uint8_t>(m.r8(object+0x9cu+n));
    (void)read_text(m,graph,0x007bc3f4u,object+0x9cu,display_name.data(),static_cast<U>(display_name.size()));
    for(U n=0;n<display_name.size();++n)m.w8(object+0x9cu+n,display_name[n]);
    Inputs upper{};upper.arg[0]=object+0x9cu;(void)crt_b83::fun_00781b14(m,upper);

    // The positive branch reads a separate present key into a 0x400-byte
    // local buffer and appends the pinned prefix before calling 0x2eed60.
    const U text_key=0x007bc3dcu, bool_key=0x007bc3e8u;
    auto section=zstr(m,object+0x24u),bk=zstr(m,bool_key);const U boolean=fun_0050e860(&graph.root,reinterpret_cast<const std::uint8_t*>(section.c_str()),reinterpret_cast<const std::uint8_t*>(bk.c_str()),0u,graph.ops);graph.flush();
    need(boolean==1u,"B481 selected route requires the admitted true literal");
    std::array<std::uint8_t,0x400> text{};
    const U length=read_text(m,graph,text_key,0u,text.data(),static_cast<U>(text.size()));
    need(length>0u&&length<text.size(),"B481 selected text must be present and bounded");
    std::array<std::uint8_t,0x420> joined{};for(U n=0;n<length;++n)joined[n]=text[n];U prefix=0;while(prefix<32u&&m.r8(0x007bc3c4u+prefix)){joined[length+prefix]=static_cast<std::uint8_t>(m.r8(0x007bc3c4u+prefix));++prefix;}
    need(prefix<32u&&length+prefix<joined.size(),"B481 appended prefix exceeds bound");
    constexpr U convert_base=0x34001000u,source_off=0x100u,dest_off=0x600u;
    std::array<std::uint8_t,0x1000> convert{};for(U n=0;n<joined.size();++n)convert[source_off+n]=joined[n];
    for(U n=0;n<0x800u;++n)convert[dest_off+n]=static_cast<std::uint8_t>(m.r8(object+0x2a0u+n));
    leaf::Memory convert_memory(convert.data(),convert_base,static_cast<U>(convert.size()));leaf::Inputs copy{};copy.cx=convert_base+dest_off;copy.dx=convert_base+source_off;copy.arg[0]=0xffffffffu;(void)leaf::fun_006eed60(convert_memory,copy);
    for(U n=0;n<0x800u;++n)m.w8(object+0x2a0u+n,convert[dest_off+n]);
    return 1u;
}
}
