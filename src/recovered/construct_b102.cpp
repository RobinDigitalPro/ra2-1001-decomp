#include "recovered/construct_b102.hpp"

#include "recovered/construct_b94.hpp"
#include "recovered/allocation_families.hpp"
#include "recovered/allocation_wrappers.hpp"
#include "recovered/global_b58_c.hpp"
#include "recovered/global_b27_memory.hpp"
#include "recovered/heap_b29_memory.hpp"
#include "recovered/leaf_b21_c.hpp"
#include "recovered/leaf_b16_a.hpp"
#include "recovered/leaf_state.hpp"
#include "recovered/preallocated_b66.hpp"
#include "recovered/release_families.hpp"
#include "recovered/state_b93.hpp"
#include "recovered/text_bytes.hpp"

#include <array>
#include <initializer_list>
#include <stdexcept>
#include <utility>

namespace ra2::recovered::heap_b29 {
void fun_0042d430(global_b27::Memory&,global_b27::State&,const Operations&);
void fun_0042d4a0(global_b27::Memory&,global_b27::State&,const Operations&);
}
namespace ra2::recovered::global_b27 {
void fun_004070d0(Memory&,State&);
}
namespace ra2::recovered::state_b93 {
std::uint32_t fun_004070f0(global_b26::Memory&,const global_b26::Inputs&);
}
namespace ra2::recovered::global_b26 {
std::uint32_t fun_004b8660(Memory&,const Inputs&);
}

namespace ra2::recovered::construct_b102 {
using namespace global_b26;
namespace {
void append(Memory& m, std::uint32_t count_at, std::uint32_t capacity_at,
            std::uint32_t table_at, std::uint32_t object, const char* route) {
    const auto count=m.r32(count_at), capacity=m.r32(capacity_at);
    if (s32(count)<0 || s32(capacity)<0 || s32(count)>=s32(capacity))
        throw std::domain_error(route);
    m.w32(count_at,count+1u);
    m.w32(m.r32(table_at)+count*4u,object);
}
void append_registry(Memory& m, std::uint32_t count, std::uint32_t capacity,
                     std::uint32_t table, std::uint32_t object) {
    append(m,count,capacity,table,object,"Block102 registry growth route excluded");
}
void init_ff10(Memory& m,std::uint32_t object) {
    (void)fun_0040ff10_composed(m,object);
}
void init_2807e0_zero_slice(Memory& m,std::uint32_t object) {
    // Exact 0x6807e0 size-zero instruction slice; no allocator path is reached.
    m.w32(object+4u,0); m.w32(object+8u,0); m.w8(object+0xcu,1);
    m.w8(object+0xdu,0); m.w32(object,0x007967f4u);
}
void zero_rate_b8780(Memory& m,std::uint32_t object,const Inputs& in,std::uint32_t target_low) {
    if (m.r16(object+0x14u)!=0 || m.r16(object)!=target_low)
        throw std::domain_error("Block102 0xb8780 adapter is limited to original zero-rate/equal-direction route");
    // Original 0xb8780 equal-direction/zero-rate route (0x4b8829 onward).
    m.w32(object+8u,m.r32(0x00a2896cu));
    m.w32(object+0xcu,in.stack_minus8); // Batch102 maps this field to entry ESP-32 for 0x12d3c0.
    m.w32(object+0x10u,0);
}
void b4b40_predicate_slice(Memory& m,std::uint32_t object,std::uint32_t threshold) {
    // Exact reached entry 0x4b4b40..0x4b4b59 and epilogue 0x4b4f0b..12.
    // Under the declared duration=0 route, the first signed compare returns directly.
    const auto sum=m.r32(object+0x2cu)+m.r32(object+0x30u);
    if (sum<m.r32(object+0x2cu) || s32(sum)>s32(threshold))
        throw std::domain_error("Block102 0xb4b40 reached predicate outside selected route");
}
void name_ctor(Memory& m,std::uint32_t object,std::uint32_t name) {
    Inputs init{}; init.cx=object; init.arg[0]=name;
    (void)construct_b94::fun_00410580(m,init);
}
void copy_name_tail(Memory& m,std::uint32_t object) {
    std::array<std::uint8_t,49> tmp{};
    for (unsigned n=0;n<tmp.size();++n) tmp[n]=static_cast<std::uint8_t>(m.r8(object+0x24u+n));
    std::array<std::uint8_t,49> copied{};
    (void)ra2::recovered::fun_0076dd10(copied.data(),tmp.data(),48u);
    copied[48]=0;
    for (unsigned n=0;n<copied.size();++n) m.w8(object+0x64u+n,copied[n]);
}
}

std::uint32_t fun_0042bf70(Memory& m,const Inputs& i) {
    const auto c=i.cx;
    heap_b29::State s{}; s.cx=c+4u; s.arg[0]=0; s.arg[1]=0;
    const heap_b29::Operations no_heap{nullptr,nullptr};
    heap_b29::fun_0042d430(m,s,no_heap);
    s={}; s.cx=c+0x20u; s.arg[0]=0; s.arg[1]=0; heap_b29::fun_0042d4a0(m,s,no_heap);
    s={}; s.cx=c+0x38u; s.arg[0]=0; s.arg[1]=0; heap_b29::fun_0042d4a0(m,s,no_heap);
    m.w32(c+4u,0x007875c0u); m.w32(c+0x20u,0x007875a0u); m.w32(c+0x38u,0x007875a0u);
    m.w32(c+0x14u,0);m.w32(c+0x18u,0xau);
    m.w32(c+0x30u,0);m.w32(c+0x34u,0xau);
    m.w32(c+0x48u,0);m.w32(c+0x4cu,0xau);
    for (auto o:{0x1cu,0x54u,0x58u,0x5cu,0x60u,0x64u,0x68u,0x6cu,0x70u,0x74u}) m.w32(c+o,0);
    m.w16(c+0x50u,0); m.w16(c+0x52u,0); m.w32(c,0x00787590u);
    return c;
}

std::uint32_t fun_006db0a0(Memory& m,const Inputs& i) {
    const auto c=i.cx; init_ff10(m,c);
    m.w32(c+0x24u,0xffffffffu); for(auto o:{0x28u,0x2cu,0x30u})m.w32(c+o,0);
    m.w32(c,0x007985a8u);m.w32(c+4u,0x0079858cu);m.w32(c+8u,0x00798584u);m.w32(c+0xcu,0x0079857cu);
    append_registry(m,0x00aa8320u,0x00aa8318u,0x00aa8314u,c);
    const auto count=m.r32(0x00aa8320u),table=m.r32(0x00aa8314u);std::uint32_t index=0xffffffffu;
    for(std::uint32_t n=0;n<count;++n)if(m.r32(table+n*4u)==c){index=n;break;}
    m.w32(c+0x24u,index);
    append_registry(m,0x00aa87b0u,0x00aa87a8u,0x00aa87a4u,c);
    append_registry(m,0x00aa87c8u,0x00aa87c0u,0x00aa87bcu,c);
    m.w32(c+0x34u,0);return c;
}

std::uint32_t fun_0041ed70(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_ff10(m,c);
    for(auto o:{0x24u,0x28u,0x2cu,0x30u,0x34u,0x38u})m.w32(c+o,0);m.w8(c+0x3cu,0);
    m.w32(c,0x00786fd4u);m.w32(c+4u,0x00786fb8u);m.w32(c+8u,0x00786fb0u);m.w32(c+0xcu,0x00786fa8u);
    append_registry(m,0x008249a0u,0x00824998u,0x00824994u,c);
    append_registry(m,0x00aa8878u,0x00aa8870u,0x00aa886cu,c);
    m.w8(0x008349ccu,1u);return c;
}

std::uint32_t fun_0067ee10(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_ff10(m,c);init_2807e0_zero_slice(m,c+0x38u);
    m.w32(c+0x38u,0x007967d4u);m.w32(c+0x4cu,0xau);m.w32(c+0x48u,0);
    m.w32(c+0x24u,i.arg[0]);m.w32(c+0x28u,i.arg[1]);m.w32(c+0x2cu,i.arg[2]);
    m.w32(c+0x30u,i.arg[3]);m.w32(c+0x34u,i.arg[4]);
    m.w32(c,0x00796770u);m.w32(c+4u,0x00796754u);m.w32(c+8u,0x0079674cu);m.w32(c+0xcu,0x00796744u);
    i.arg[0]=0; // The native bridge exposes [entry ESP+4] as this mutable input word.
    m.w32(c+0x50u,m.r32(0x00a2896cu));m.w32(c+0x54u,i.stack_minus8);m.w32(c+0x58u,0x14u);
    m.w32(c+0x5cu,m.r32(0x00a2896cu));m.w32(c+0x60u,i.stack_minus8);
    m.w32(c+0x64u,0);m.w32(c+0x68u,0);m.w32(c+0x6cu,0);m.w32(c+0x70u,0);
    append_registry(m,0x00aa4b40u,0x00aa4b38u,0x00aa4b34u,c);return c;
}

std::uint32_t fun_0067f010(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_ff10(m,c);init_2807e0_zero_slice(m,c+0x38u);
    m.w32(c+0x38u,0x007967d4u);m.w32(c+0x4cu,0xau);m.w32(c+0x48u,0);
    m.w32(c+0x50u,m.r32(0x00a2896cu));m.w32(c+0x54u,i.stack_minus8);m.w32(c+0x58u,0);
    m.w32(c,0x00796770u);m.w32(c+4u,0x00796754u);m.w32(c+8u,0x0079674cu);m.w32(c+0xcu,0x00796744u);
    for(auto o:{0x24u,0x28u,0x2cu})m.w32(c+o,0);
    m.w32(c+0x50u,m.r32(0x00a2896cu));m.w32(c+0x54u,i.stack_minus8);m.w32(c+0x58u,0);
    m.w32(c+0x68u,0);m.w32(c+0x6cu,0);m.w32(c+0x70u,0);m.w32(c+0x5cu,m.r32(0x00a2896cu));m.w32(c+0x60u,i.stack_minus8);m.w32(c+0x64u,0);
    append_registry(m,0x00aa4b40u,0x00aa4b38u,0x00aa4b34u,c);return c;
}

std::uint32_t fun_004b4910(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_ff10(m,c);m.w32(c+0x24u,i.arg[0]);m.w32(c+0x28u,i.arg[1]);m.w32(c+0x30u,i.arg[2]);m.w32(c+0x2cu,m.r32(0x00a2896cu));
    m.w32(c,0x0078bdb8u);m.w32(c+4u,0x0078bd9cu);m.w32(c+8u,0x0078bd94u);m.w32(c+0xcu,0x0078bd8cu);
    (void)fun_0040ffd0_zero_global_composed(m,c+4u);
    append_registry(m,0x0083dd68u,0x0083dd60u,0x0083dd5cu,c);
    b4b40_predicate_slice(m,c,m.r32(0x00a2896cu));return c;
}

std::uint32_t fun_004b8d10(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_ff10(m,c);m.w32(c+0x24u,0);m.w32(c+0x28u,m.r32(0x00a2896cu));m.w32(c+0x30u,0);m.w32(c+0x34u,0);m.w32(c+0x38u,1);
    m.w32(c+0x40u,0);m.w32(c+0x44u,0);m.w8(c+0x48u,1);m.w8(c+0x49u,0);m.w32(c+0x3cu,0x0078bf44u);
    m.w32(c+0x50u,0xau);m.w32(c+0x4cu,0);m.w8(c+0x6du,1);m.w32(c+0x54u,0);m.w8(c+0x58u,0);m.w8(c+0x59u,0);m.w32(c+0x5cu,0);m.w32(c+0x60u,0);m.w32(c+0x64u,0xffffffffu);m.w32(c+0x68u,0);m.w8(c+0x6cu,0);
    m.w32(c,0x0078bee0u);m.w32(c+4u,0x0078bec4u);m.w32(c+8u,0x0078bebcu);m.w32(c+0xcu,0x0078beb4u);(void)fun_0040ffd0_zero_global_composed(m,c+4u);
    append_registry(m,0x00a1e1d0u,0x00a1e1c8u,0x00a1e1c4u,c);
    m.w32(c+0x34u,0);m.w32(c+0x28u,m.r32(0x00a2896cu));m.w32(c+0x2cu,i.stack_minus8);m.w32(c+0x30u,0);
    append_registry(m,0x00aa8878u,0x00aa8870u,0x00aa886cu,c);return c;
}

std::uint32_t fun_0052d3c0(Memory& m,const Inputs& i) {
    const auto c=i.cx;std::array<std::uint8_t,0x20> bytes{};
    for(unsigned n=0;n<bytes.size();++n)bytes[n]=static_cast<std::uint8_t>(m.r8(c+n));
    leaf::Memory base(bytes.data(),c,static_cast<std::uint32_t>(bytes.size()));leaf::Inputs base_in{};base_in.cx=c;(void)leaf::fun_0053b1a0(base,base_in);
    for(unsigned n=0;n<bytes.size();++n)m.w8(c+n,bytes[n]);
    for(auto [src,dst]:std::array<std::pair<std::uint32_t,std::uint32_t>,3>{{{0x00a56010u,c+0x3cu},{0x00a56014u,c+0x40u},{0x00a56018u,c+0x44u}}})m.w32(dst,m.r32(src));
    const auto config=m.r32(0x00821b88u),duration=m.r32(config+0x368u);
    if(duration!=0)throw std::domain_error("Block102 0x12d3c0 selected zero-duration route only");
    Inputs timer{};timer.cx=c+0x50u;timer.arg[0]=duration;(void)global_b26::fun_004b8660(m,timer);
    m.w8(c+0x48u,0);m.w32(c+0x4cu,0);
    m.w32(c+0x68u,0);m.w32(c+0x70u,0);m.w32(c+0x80u,0);m.w32(c+0x6cu,0);m.w32(c+0x74u,0);m.w32(c+0x78u,0);m.w32(c+0x84u,0);m.w8(c+0x88u,0);
    m.w32(c,0x0079034cu);m.w32(c+4u,0x00790284u);
    const auto target_address=0x7f004000u,target=(c&0xffff0000u)|0x4000u;
    std::array<std::uint8_t,4> stack_local{};
    leaf::Memory stack_span(stack_local.data(),target_address,static_cast<std::uint32_t>(stack_local.size()));
    auto stack_memory=m;stack_memory.add(stack_span);stack_memory.w32(target_address,target);
    Inputs move{};move.cx=c+0x50u;move.arg[0]=target_address;(void)global_b26::fun_004b86a0(stack_memory,move);
    zero_rate_b8780(m,c+0x50u,i,stack_memory.r16(target_address));return c;
}

std::uint32_t fun_006a9bc0(Memory& m,const Inputs& i) {
    const auto c=i.cx;name_ctor(m,c,i.arg[0]);
    m.w32(c+0x98u,m.r32(0x00aa79b8u));m.w32(c+0x9cu,0);m.w32(c+0xa0u,0);
    m.w32(c,0x0079768cu);m.w32(c+4u,0x00797670u);m.w32(c+8u,0x00797668u);m.w32(c+0xcu,0x00797660u);
    copy_name_tail(m,c);
    append_registry(m,0x00aa79b8u,0x00aa79b0u,0x00aa79acu,c);append_registry(m,0x00aa87c8u,0x00aa87c0u,0x00aa87bcu,c);return c;
}

std::uint32_t fun_006abea0(Memory& m,const Inputs& i) {
    const auto c=i.cx;name_ctor(m,c,i.arg[0]);m.w32(c+0x98u,0xffffffffu);m.w32(c+0x9cu,0);m.w32(c+0xa0u,0);
    m.w32(c,0x00797748u);m.w32(c+4u,0x0079772cu);m.w32(c+8u,0x00797724u);m.w32(c+0xcu,0x0079771cu);
    append_registry(m,0x00a284f0u,0x00a284e8u,0x00a284e4u,c);
    for(unsigned n=0;n<6;++n){m.w32(c+0xa4u+n*8u,0);m.w32(c+0xa8u+n*8u,0);}return c;
}

std::uint32_t fun_006aca80(Memory& m,const Inputs& i) {
    const auto c=i.cx;init_ff10(m,c);const auto a0=i.arg[0],a1=i.arg[1],a2=i.arg[2];
    m.w32(c+0x24u,a0);m.w32(c+0x28u,0);m.w32(c+0x2cu,a1);m.w32(c+0x30u,0);m.w32(c+0x34u,0);m.w32(c+0x38u,0);m.w32(c+0x3cu,0);m.w32(c+0x40u,0);m.w32(c+0x44u,a2);m.w32(c+0x48u,0);m.w32(c+0x4cu,0);
    for(auto off:{0x50u,0x58u,0x64u})m.w32(c+off,m.r32(0x00a2896cu));m.w32(c+0x54u,0);m.w32(c+0x60u,0);
    for(auto off:{0x6cu,0x70u})m.w32(c+off,0);
    for(auto off:{0x74u,0x75u,0x76u,0x77u,0x78u,0x79u,0x7bu,0x7cu,0x7eu,0x7fu,0x81u,0x82u,0x83u})m.w8(c+off,0);
    for(auto off:{0x7au,0x7du,0x80u})m.w8(c+off,1);
    m.w32(c,0x007977f8u);m.w32(c+4u,0x007977dcu);m.w32(c+8u,0x007977d4u);m.w32(c+0xcu,0x007977ccu);
    append_registry(m,0x0084e4b8u,0x0084e4b0u,0x0084e4acu,c);append_registry(m,0x00aa87c8u,0x00aa87c0u,0x00aa87bcu,c);append_registry(m,0x00aa8770u,0x00aa8768u,0x00aa8764u,c);append_registry(m,0x00aa8878u,0x00aa8870u,0x00aa886cu,c);append_registry(m,0x00aa8848u,0x00aa8840u,0x00aa883cu,c);
    for(unsigned n=0;n<6;++n)m.w32(c+0x84u+n*4u,0);
    return c;
}

std::uint32_t fun_006ddc60(Memory& m,const Inputs& i) {
    const auto c=i.cx;Inputs named{};named.cx=c;named.arg[0]=i.arg[0];(void)construct_b94::fun_00410580(m,named);
    for(auto [o,v]:std::array<std::pair<std::uint32_t,std::uint32_t>,11>{{{0xa0u,0x9999999au},{0xb0u,0x9999999au},{0x98u,0xffffffffu},{0x9cu,0},{0xa4u,0x3fb99999u},{0xa8u,0},{0xb4u,0x3fb99999u},{0xb8u,0},{0xbcu,0},{0xc0u,0},{0xe0u,0}}})m.w32(c+o,v);
    for(auto o:{0xe4u,0xe8u,0xecu,0xf0u,0xf4u,0xf8u,0xfcu,0x108u,0x10cu,0x110u,0x114u,0x118u,0x124u})m.w32(c+o,0);
    m.w32(c+0x100u,m.r32(0x00a2896cu));m.w32(c+0x11cu,m.r32(0x00a2896cu));
    const auto embedded=c+0xc4u;
    std::array<std::uint8_t,0x18> embedded_bytes{};for(unsigned n=0;n<embedded_bytes.size();++n)embedded_bytes[n]=static_cast<std::uint8_t>(m.r8(embedded+n));
    leaf::Memory embedded_memory(embedded_bytes.data(),embedded,static_cast<std::uint32_t>(embedded_bytes.size()));leaf::Inputs embedded_input{};embedded_input.cx=embedded;
    const AllocationWrapperOperations no_allocation{nullptr,nullptr,nullptr};
    (void)ra2::recovered::fun_0050acb0(embedded_memory,embedded_input,no_allocation);
    for(unsigned n=0;n<embedded_bytes.size();++n)m.w8(embedded+n,embedded_bytes[n]);
    m.w32(embedded+0x14u,0xau);m.w32(embedded+0x10u,0);m.w32(embedded,0x0078eb3cu);
    m.w32(c,0x00798758u);m.w32(c+4u,0x0079873cu);m.w32(c+8u,0x00798734u);m.w32(c+0xcu,0x0079872cu);
    m.w32(c+0x98u,m.r32(0x00aa8648u));append_registry(m,0x00aa8648u,0x00aa8640u,0x00aa863cu,c);
    // Original vtable slot+0xc at 0x78eb48 is accepted 0x50a560. Its null,
    // unowned route is composed directly; neither allocation boundary is reached.
    for(unsigned n=0;n<embedded_bytes.size();++n)embedded_bytes[n]=static_cast<std::uint8_t>(m.r8(embedded+n));
    leaf::Inputs release_input{};release_input.cx=embedded;
    (void)ra2::recovered::fun_0050a560(embedded_memory,release_input,no_allocation);
    for(unsigned n=0;n<embedded_bytes.size();++n)m.w8(embedded+n,embedded_bytes[n]);
    append_registry(m,0x00aa87c8u,0x00aa87c0u,0x00aa87bcu,c);
    return c;
}

std::uint32_t fun_00465080(Memory& m,const Inputs& i) {
    const auto c=i.cx;name_ctor(m,c,i.arg[0]);
    m.w32(c,0x007886a0u);m.w32(c+0x98u,0xffffffffu);m.w32(c+0x29cu,0xffffffffu);
    m.w32(c+4u,0x00788684u);m.w32(c+8u,0x0078867cu);m.w32(c+0xcu,0x00788674u);
    append_registry(m,0x00a1e0a0u,0x00a1e098u,0x00a1e094u,c);
    m.w8(c+0x9cu,0);
    // Accepted 0x36efc9 text route copies the original empty UTF-16 string.
    std::array<std::uint8_t,4> text_bytes{};
    text_bytes[0]=static_cast<std::uint8_t>(m.r8(0x0082208cu));
    text_bytes[1]=static_cast<std::uint8_t>(m.r8(0x0082208du));
    leaf::Memory text_memory(text_bytes.data(),0x1000u,static_cast<std::uint32_t>(text_bytes.size()));
    leaf::Inputs text_input{};text_input.arg[0]=0x1002u;text_input.arg[1]=0x1000u;
    (void)leaf::fun_0076efc9(text_memory,text_input);
    for(unsigned n=0;n<2;++n)m.w8(c+0x2a0u+n,text_bytes[2u+n]);return c;
}

std::uint32_t fun_0065f9d0(Memory& m,const Inputs& i) {
    const auto c=i.cx;name_ctor(m,c,i.arg[0]);m.w32(c+0x9cu,0);m.w32(c+0xa0u,0);
    m.w32(c,0x00794260u);m.w32(c+4u,0x00794244u);m.w32(c+8u,0x0079423cu);m.w32(c+0xcu,0x00794234u);
    append_registry(m,0x0084e598u,0x0084e590u,0x0084e58cu,c);
    const auto count=m.r32(0x0084e598u),table=m.r32(0x0084e58cu);std::uint32_t index=0xffffffffu;
    for(std::uint32_t n=0;n<count;++n)if(m.r32(table+n*4u)==c){index=n;break;}
    m.w32(c+0x98u,index);return c;
}

std::uint32_t fun_0066a9e0(Memory& m,const Inputs& i) {
    const auto c=i.cx;const auto a0=i.arg[0],a1=i.arg[1],a2=i.arg[2],a3=i.arg[3],a4=i.arg[4],a5=i.arg[5],a6=i.arg[6];
    // Exact closed path through 0x6e03e0 -> 0x83210 -> 0xcebc0, with no indirect call.
    m.w32(c+4u,0);m.w32(c+8u,0);m.w32(c+0x0cu,a2);m.w32(c+0x10u,a3);m.w32(c+0x14u,a3);m.w32(c+0x18u,0);m.w16(c+0x1cu,0);m.w8(c+0x1du,1);m.w8(c+0x1eu,0);m.w32(c+0x20u,5);
    m.w32(c+0x24u,a0);m.w32(c+0x28u,0);m.w8(c+0x2cu,0);m.w8(c+0x2du,0);m.w32(c+0x30u,0);
    m.w8(c+0x34u,0);m.w32(c+0x38u,0);m.w8(c+0x40u,0);m.w32(c+0x44u,0);m.w32(c+0x48u,0);m.w8(c+0x4cu,0);m.w32(c+0x50u,m.r32(0x0081a704u));m.w8(c+0x55u,static_cast<std::uint8_t>(a6));m.w8(c+0x5cu,0);m.w32(c,0x0078b6a0u);m.w32(c+0x58u,i.arg[1]);
    if(a1){m.w32(c+0x14u,sx16(m.r16(a1+2u)));m.w32(c+0x18u,sx16(m.r16(a1+4u)));}else{m.w32(c+0x14u,0);m.w32(c+0x18u,0);}
    if(a4)m.w32(c+0x14u,a4);if(a5)m.w32(c+0x18u,a5);return c;
}

std::uint32_t fun_00402190(Memory& m,const Inputs& i) {
    const auto c=i.cx;
    m.w32(c+0x15cu,0x004022c0u);m.w32(c+0x160u,0x00402330u);m.w32(c+0x164u,0x004023f0u);
    for(auto o:{0xb0u,0xb4u,0xb8u,0xbcu,0xc0u,0xa8u,0xa4u,0xa0u,0x90u,0x98u,0x9cu,0x168u})m.w32(c+o,0);
    m.w32(c+0xcu,1u);m.w32(c+0x94u,m.r32(0x00818e90u));
    if(m.r32(0x00819898u)!=0)throw std::domain_error("Block102 0x401000 requires original null-dispatch state at 0x819898");
    const std::array<std::uint32_t,3> objects={c+0x10u,c+0x38u,c+0x60u};
    const std::array<std::uint32_t,3> targets={0x4000u,0x64u,0x2000u};
    const std::array<std::uint32_t,3> rates={0x4000u,0xau,0x4000u};
    for(unsigned n=0;n<objects.size();++n){
        const auto p=objects[n];
        m.w32(p,0);m.w32(p+0x18u,0);m.w32(p,1u);m.w32(p+0x10u,0x3e8u);
        m.w32(p+8u,targets[n]<<16);m.w32(p+0x1cu,0);m.w32(p+0xcu,0x0010624du);m.w32(p+0x14u,0);
        Inputs update{};update.cx=p;(void)state_b93::fun_004070f0(m,update);
        global_b27::State rate{};rate.cx=p;rate.dx=rates[n];rate.arg[0]=0x3e8u;rate.arg[1]=0;
        global_b27::fun_004070d0(m,rate);
    }
    std::array<std::uint8_t,12> finish_bytes{};for(unsigned n=0;n<finish_bytes.size();++n)finish_bytes[n]=static_cast<std::uint8_t>(m.r8(c+0x10u+n));
    leaf::Memory finish_memory(finish_bytes.data(),c+0x10u,static_cast<std::uint32_t>(finish_bytes.size()));
    leaf::Inputs finish{};finish.cx=c+0x10u;finish.dx=0x4000u;const auto result=leaf::fun_00407080(finish_memory,finish);
    for(unsigned n=0;n<finish_bytes.size();++n)m.w8(c+0x10u+n,finish_bytes[n]);
    m.w32(c+0x168u,0);return result;
}
}
