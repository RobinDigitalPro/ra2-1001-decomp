#include "recovered/recovery_b177.hpp"

#include "recovered/construct_b102.hpp"
#include "recovered/crt_b83.hpp"
#include "recovered/crt_classify.hpp"
#include "recovered/fun_00412390.hpp"
#include "recovered/indirect_b31_memory.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_lookup.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/name_hash.hpp"

#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b177 {
namespace {
using namespace ra2::recovered;

constexpr std::uint32_t scratch_va=0x35010000u;
constexpr std::uint32_t stack_va=0x35011000u;
constexpr std::uint32_t stack_size=0x100u;
constexpr std::uint32_t stack_sp=stack_va+0x80u;
constexpr std::uint32_t append_return=0xb177f00du;
constexpr std::uint32_t append_call_return=0xb177cafeu;
constexpr std::uint32_t task_forces_va=0x007e0630u;
constexpr std::uint32_t row_va=0x35010020u;

std::uint32_t hash_name(const std::uint8_t* p,std::size_t n,void*) {
    return ini_name_hash(p,n,nullptr);
}
void must_not_sort(IniIndexEntry*,std::int32_t,IniIndexKind,void*) {
    throw std::domain_error("Block177 requires already-sorted INI indexes");
}
std::int32_t c_upper(std::int32_t v,void*) {
    return v>='A'&&v<='Z'?v+('a'-'A'):v;
}
std::int32_t signed32(std::uint32_t v) {
    return v<=0x7fffffffu?static_cast<std::int32_t>(v)
        :-1-static_cast<std::int32_t>(0xffffffffu-v);
}

// A logical view of the declared one-section/one-key guest INI graph. The
// accepted lookup helpers operate on these views; flush writes back only the
// two cache cells those helpers can change. This is a bridge, not a class ABI.
struct IniBridge {
    Memory& m;
    std::uint32_t root_guest{},root_table{},section_guest{},key_guest{},value_guest{};
    std::uint32_t root_cache_before{},key_cache_before{};
    std::array<std::uint8_t,16> key_name{},text{};
    IniValue value{};
    IniIndexEntry root_node{},key_node{};
    IniIndex root{};
    IniSection section{};
    IniKeyNode first{},sentinel{};
    IniOperations ops{};

    static std::array<std::uint8_t,16> read_string(Memory& m,std::uint32_t p) {
        std::array<std::uint8_t,16> out{};
        for(unsigned n=0;n<out.size();++n){out[n]=static_cast<std::uint8_t>(m.r8(p+n));if(!out[n])return out;}
        throw std::domain_error("Block177 INI string exceeds its finite NUL span");
    }
    IniBridge(Memory& memory,std::uint32_t guest):m(memory),root_guest(guest) {
        root_table=m.r32(root_guest);
        if(m.r32(root_guest+4u)!=1u || m.r8(root_guest+12u)!=1u)
            throw std::domain_error("Block177 requires one sorted TaskForces section");
        root_cache_before=m.r32(root_guest+16u);
        if(root_cache_before && root_cache_before!=root_table)
            throw std::domain_error("Block177 section cache is outside the single-node table");
        root_node.key=signed32(m.r32(root_table));
        section_guest=m.r32(root_table+4u);
        key_guest=section_guest+0x2cu;
        const auto key_table=m.r32(key_guest);
        if(m.r32(key_guest+4u)!=1u || m.r8(key_guest+12u)!=1u)
            throw std::domain_error("Block177 requires one sorted key in TaskForces");
        key_cache_before=m.r32(key_guest+16u);
        if(key_cache_before && key_cache_before!=key_table)
            throw std::domain_error("Block177 key cache is outside the single-node table");
        key_node.key=signed32(m.r32(key_table));
        value_guest=m.r32(key_table+4u);
        const auto text_guest=m.r32(value_guest+0x10u);
        text=read_string(m,text_guest);
        value.text=text.data(); key_node.value=&value; root_node.value=&section;
        root.entries=&root_node; root.count=1; root.sorted=1;
        root.cached=root_cache_before?&root_node:nullptr;
        section.keys.entries=&key_node; section.keys.count=1; section.keys.sorted=1;
        section.keys.cached=key_cache_before?&key_node:nullptr;
        section.first=&first;
        // The section linked chain is a distinct original enumeration path.
        // Find its first name through the original nodes and give the logical
        // 0x50c250 adapter an equivalent finite sentinel-terminated chain.
        const auto node=m.r32(section_guest+0x18u);
        if(!node || !m.r32(node+4u) || !m.r32(node+8u))
            throw std::domain_error("Block177 requires the initialized first key node and sentinels");
        const auto name_guest=m.r32(node+0xcu);
        key_name=read_string(m,name_guest);
        sentinel.next=nullptr; sentinel.previous=&first; sentinel.name=nullptr;
        first.next=&sentinel; first.previous=&sentinel; first.name=key_name.data();
        ops={hash_name,must_not_sort,c_upper,nullptr,nullptr,nullptr};
        // The selected route has exactly one key named "0" and one value "1".
        if(key_name[0]!='0' || key_name[1]!=0 || text[0]<'1' || text[0]>'9' || text[1]!=0)
            throw std::domain_error("Block177 bounded fixture requires TaskForces/0 -> one decimal digit");
    }
    void flush() {
        const auto root_cache=root.cached?root_table:0u;
        const auto key_table=m.r32(key_guest);
        const auto key_cache=section.keys.cached?key_table:0u;
        if(root_cache!=root_cache_before)m.w32(root_guest+16u,root_cache);
        if(key_cache!=key_cache_before)m.w32(section_guest+0x3cu,key_cache);
    }
};

std::uint32_t compare_ci(Memory& m,std::uint32_t a,std::uint32_t b) {
    Inputs q{};q.arg[0]=a;q.arg[1]=b;
    return crt_b83::fun_0076d860(m,q);
}
std::int32_t no_upper(std::int32_t,void*) {
    throw std::domain_error("Block177 digit-only row unexpectedly reached alphabetic conversion");
}
}

std::uint32_t fun_006ac240(Memory& m,const Inputs& i,ra2::platform::small_crt_heap::Heap& heap) {
    // Keep all temporary guest spans alive in this local span registry. It
    // shares the original mapped pages with m but does not retain dangling
    // pointers to stack-owned leaf::Memory objects after this function ends.
    Memory work=m;
    if(work.r32(0xb10530u)!=0)throw std::domain_error("Block177 requires pinned C-locale string mode");
    std::array<std::uint8_t,11> task_forces{};
    for(unsigned k=0;k<task_forces.size();++k)task_forces[k]=static_cast<std::uint8_t>(work.r8(task_forces_va+k));
    IniBridge graph(work,i.cx+0x20u);
    const auto count=fun_0050bf50(&graph.root,task_forces.data(),graph.ops);
    if(count!=1)throw std::domain_error("Block177 route is exactly one TaskForces row");
    const auto* key=fun_0050c250(&graph.root,task_forces.data(),0,graph.ops);
    if(!key)throw std::domain_error("Block177 one-row key enumeration unexpectedly failed");
    std::array<std::uint8_t,24> row{};
    static constexpr std::uint8_t fallback[]={0};
    const auto copied=fun_0050ddf0(&graph.root,task_forces.data(),key,fallback,row.data(),24,graph.ops);
    graph.flush();
    if(copied!=1 || row[0]<'1' || row[0]>'9' || row[1]!=0)
        throw std::domain_error("Block177 row text must be one nonzero decimal digit");
    std::array<std::uint8_t,24> row_guest{};
    std::copy(row.begin(),row.end(),row_guest.begin());
    leaf::Memory row_span(row_guest.data(),row_va,static_cast<std::uint32_t>(row_guest.size()));
    work.add(row_span);
    if(compare_ci(work,0x007b8e5cu,row_va)==0 || compare_ci(work,0x007b907cu,row_va)==0)
        throw std::domain_error("Block177 special row token is outside selected route");

    if(work.r32(0x00a284f0u)!=0 || work.r32(0x00a284e8u)<1u || !work.r32(0x00a284e4u))
        throw std::domain_error("Block177 requires empty registry with one spare slot");
    if(work.r32(0x00aa5370u+0x2cu)!=0 || work.r32(0x00aa5370u+0x24u)<1u ||
       !work.r32(0x00aa5370u+0x20u) || work.r32(0xb10aac)!=0)
        throw std::domain_error("Block177 requires spare append capacity and the pinned null missing-section value");
    const auto object=heap.allocate(0xd4u);
    if(!object)throw std::domain_error("Block177 request-212 allocation failed");

    // The returned user address is real process memory. Add exactly its
    // bounded object span to the local address registry so accepted recovered
    // constructors access the same live heap bytes as the platform adapter.
    static_assert(sizeof(void*)==4,"Block177 uses the pinned x86 guest address space");
    leaf::Memory object_span(reinterpret_cast<std::uint8_t*>(object),object,0xd4u);
    work.add(object_span);

    // Make the original constructor's name argument a real guest-readable span.
    std::array<std::uint8_t,24> name_bytes{};name_bytes[0]=row[0];
    leaf::Memory name_span(name_bytes.data(),scratch_va,static_cast<std::uint32_t>(name_bytes.size()));
    work.add(name_span);
    Inputs ctor{};ctor.cx=object;ctor.arg[0]=scratch_va;
    (void)construct_b102::fun_006abea0(work,ctor);
    if(work.r32(object)!=0x00797748u || work.r32(work.r32(object)+0x64u)!=0x006ac440u)
        throw std::domain_error("Block177 constructor did not install proven RVA 0x2ac440 at slot +0x64");

    if(work.r32(0x81776cu)!=1u || work.r32(0x817560u)!=0x81756au)
        throw std::domain_error("Block177 requires original initialized single-byte C classification");
    std::array<std::uint16_t,257> flags{};
    for(unsigned k=0;k<flags.size();++k)flags[k]=static_cast<std::uint16_t>(work.r16(0x817568u+2u*k));
    const CrtClassification classifier{1,flags.data(),nullptr,nullptr};
    const HexCharacterOps hex{[](std::int32_t c,void* p)->std::int32_t {
        return fun_0076e4f4(c,*static_cast<const CrtClassification*>(p));
    },no_upper,const_cast<CrtClassification*>(&classifier)};
    const auto identifier=fun_00412390(row_guest.data(),hex);

    // Original instruction order is append first, then vtable call, then the
    // unconditional owner store. The direct spare-capacity helper route is
    // executed as recovered code; its growth callback is unreachable.
    std::array<std::uint8_t,stack_size> stack{};
    leaf::Memory stack_span(stack.data(),stack_va,stack_size);work.add(stack_span);
    work.w32(stack_sp,append_return);work.w32(stack_sp+4u,0x00aa5370u);
    work.w32(stack_sp+8u,identifier);work.w32(stack_sp+12u,object);
    ra2::recovered::indirect_b31::State state{};
    state.ax=identifier;state.cx=0x00aa5370u;state.dx=object;
    ra2::recovered::indirect_b31::Frame frame{};
    frame.entry_sp=stack_sp;frame.sp=stack_sp;frame.outer_return=append_return;
    frame.call_return=append_call_return;
    const ra2::recovered::indirect_b31::Operations no_callback{nullptr,nullptr};
    const auto& append_entries=indirect_b31::entries_c();
    const auto entry=std::find_if(append_entries.begin(),append_entries.end(),[](const auto& e){return e.rva==0x2951f0;});
    if(entry==append_entries.end())throw std::domain_error("177 accepted append helper absent");
    entry->function(work,state,frame,no_callback);

    // Exact selected 0x2ac440 false path: the accepted 0x50be00 lookup makes
    // the real sorted miss for the object's inline name. It yields the pinned
    // null missing-section value; 0x107e0 then exits with AL=0 before text,
    // parser, or group-field writes. The root ignores that AL and stores EDX.
    const std::array<std::uint8_t,2> absent_type{
        static_cast<std::uint8_t>(work.r8(object+0x24u)),
        static_cast<std::uint8_t>(work.r8(object+0x25u))};
    if(absent_type[0]!=row[0] || absent_type[1]!=0)
        throw std::domain_error("Block177 constructor name bytes differ from the actual parsed row");
    if(fun_0050be00(&graph.root,absent_type.data(),graph.ops)!=nullptr)
        throw std::domain_error("Block177 typed section must be a real absent-name lookup");
    graph.flush();
    work.w32(object+0xa0u,i.dx);

    // Authentic +0x64 dispatch has a genuine false helper result, but the
    // caller unconditionally writes its EDX owner token immediately afterward.
    return 0u;
}

void normalize_published_refs(Memory& m,const ra2::platform::small_crt_heap::Heap& heap) {
    const auto base_registry=m.r32(0x00a2857cu);
    m.w32(base_registry,heap.normalize_user_pointer(m.r32(base_registry)));
    const auto registry=m.r32(0x00a284e4u);
    const auto vector_data=m.r32(0x00aa5370u+0x20u);
    m.w32(registry,heap.normalize_user_pointer(m.r32(registry)));
    m.w32(vector_data+4u,heap.normalize_user_pointer(m.r32(vector_data+4u)));
}
}
