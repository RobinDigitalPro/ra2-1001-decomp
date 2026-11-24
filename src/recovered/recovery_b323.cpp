#include "recovery_b323.hpp"


#include <stdexcept>

namespace ra2::recovery_b323 {
namespace {
using platform::x87::State;
constexpr std::uint32_t g_pool_enabled=0x007b7b68u;
constexpr std::uint32_t g_generation=0x007b7b6cu;
constexpr std::uint32_t g_head=0x008191e0u;
constexpr std::uint32_t g_count=0x008192e4u;
constexpr std::uint32_t g_capacity=0x008192e8u;
constexpr std::uint32_t g_ready=0x008192fcu;
constexpr std::uint32_t g_pool_cell=0x00819300u;
constexpr std::uint32_t g_types=0x00ab829cu;
constexpr std::uint32_t g_type_count=0x00ab82a8u;

void need(bool value,const char* message){if(!value)throw std::domain_error(message);}
std::uint32_t clamp_4000(std::uint32_t v){return v>0x4000u?0x4000u:v;}

// Exact reached 0x7030/0x70f0 effects from Block191's reviewed helper route.
std::uint32_t control_update(Memory& m,std::uint32_t p){
    const auto end=m.r32(p+8u),cur=m.r32(p+4u);
    if(end==cur)return 0;
    need((m.r8(p)&1u)!=0,"323 selected 0x70f0 only on its enabled direct-update branch");
    m.w32(p+4u,end);m.w32(p,m.r32(p)|2u);return 1;
}
void control_init(Memory& m,std::uint32_t p,std::uint32_t scale){need(m.r32(0x819898)==0,"323 actual92d0nullcallbackroute");
    m.w32(p,0);m.w32(p+0x18u,0);m.w32(p+0x10u,0x3e8u);m.w32(p,1u);
    m.w32(p+8u,scale<<16u);m.w32(p+0x1cu,0);m.w32(p+0x0cu,0x0010624du);m.w32(p+0x14u,0);
    (void)control_update(m,p);
}
void control_rate(Memory& m,std::uint32_t p,std::uint32_t rate){
    m.w32(p+0x10u,1000u);m.w32(p+0x0cu,(rate<<16u)/1000u);m.w32(p+0x14u,0);
}
void control_position(Memory& m,std::uint32_t p,std::uint32_t rate){
    m.w32(p,m.r32(p)|1u);m.w32(p+8u,rate<<16u);
}
void audio_controls_init(Memory& m,std::uint32_t p){
    control_init(m,p,0x4000u);control_init(m,p+0x28u,0x64u);control_init(m,p+0x50u,0x2000u);
    control_rate(m,p+0x28u,0xau);control_rate(m,p,0x4000u);control_rate(m,p+0x50u,0x4000u);
    control_position(m,p,0x4000u);
}

std::uint32_t manager_from_pool(Memory& m,std::uint32_t type){
    need(m.r32(g_pool_enabled)!=0&&m.r32(g_ready)!=0&&m.r32(type+0x0cu)!=0,
         "323 requires original manager gates and a nonzero type-record +0xc field");
    const auto cell=m.r32(g_pool_cell);need(cell!=0,"323 requires the original pool-head cell");
    const auto node=m.r32(cell);need(node!=0,"323 route requires one available original 0x280 pool node");
    m.w32(cell,m.r32(node));
    const auto object=node+8u;
    auto count=m.r32(g_count)+1u;const auto capacity=m.r32(g_capacity);
    m.w32(g_count,count);if(static_cast<std::int32_t>(count)>static_cast<std::int32_t>(capacity))m.w32(g_capacity,count);
    for(std::uint32_t n=0;n<0xa0u;++n)m.w32(object+n*4u,0);
    m.w32(object+0x24u,type);
    m.w32(object,object);m.w32(object+4u,object);m.w32(object+8u,0);
    m.w32(object+0x1cu,0);m.w32(object+0x154u,0);m.w32(object+0x268u,0);
    m.w32(object+0x1e0u,0);m.w32(object+0xa8u,0);
    audio_controls_init(m,object+0xb8u);
    m.w32(object+0x158u,0);
    const auto tail=m.r32(g_head+4u);
    m.w32(object,g_head);m.w32(object+4u,tail);m.w32(g_head+4u,object);
    const auto old_tail=m.r32(object+4u);m.w32(old_tail,object);
    const auto generation=m.r32(g_generation);m.w32(object+0x138u,generation);m.w32(g_generation,generation+1u);
    return object;
}

void scalar_set_target_update(Memory& m,std::uint32_t p,std::uint32_t value){
    // Mode 0 takes 0x4061e0's 0x407080 then 0x4070f0 route. The selected
    // control is enabled, so the unequal end/current branch updates current
    // directly and never reaches 0x4092d0.
    m.w32(p,m.r32(p)|1u);m.w32(p+8u,value<<16u);
    (void)control_update(m,p);
}
void scalar_set_fixed(Memory& m,std::uint32_t p,std::uint32_t value){
    // 0x407080, reached from 0x406280's manager-mode-zero route.
    m.w32(p,m.r32(p)|1u);m.w32(p+8u,value<<16u);
}
}

std::uint32_t fun_00405170(Memory&m,const Inputs&i){return manager_from_pool(m,i.cx);}

std::uint32_t fun_00708970(Memory& m,EntryState& entry,State& fp){
    const auto& i=entry.input;
    need(i.cx==0&&m.r32(g_type_count)==1u,"323 uses the single valid registry index 0");
    need(entry.ecx==i.cx&&entry.edx==i.dx,"323 entry register state must match the original register inputs");
    need(i.arg[0]==0x3f800000u&&i.arg[1]==0u&&i.dx==0x2000u,
         "323 route fixes the actual cdecl arguments and entry EDX");
    const auto table=m.r32(g_types);need(table!=0,"323 requires a mapped original type-pointer table");
    const auto table_entry=m.r32(table+i.cx*4u);need(table_entry!=0,"323 requires the first real registry table entry");
    const auto type=m.r32(table_entry);need(type!=0,"323 requires a nonnull type record");
    const auto factor=m.r32(type+0x1cu)>>16u;
    need(factor>=0x100u&&factor<=0x200u,"323 bounds the descriptor's reached 16.16 factor");

    // After all four saved-register pushes, the root overwrites [ESP+0x0c],
    // which is its saved ECX slot, with entry EDX. A later FLD reads caller
    // arg0 at entry ESP+4, then FMULs [0x79276c] and calls
    // the actual 0x76aa50 x87 conversion. The pinned multiplier is 16384.0f;
    // caller arg0 is exact 1.0f, so this product is exact.
    fp.load32(i.arg[0]);fp.multiply32(m.r32(0x0079276cu));
    const auto target_cw=static_cast<std::uint16_t>(m.r32(0x007c3a04u));
    if(fp.control()!=target_cw)fp.load_control(target_cw);
    const auto converted=static_cast<std::uint32_t>(fp.pop_integer64());
    const auto amount=clamp_4000(converted);
    need(amount==0x4000u,"323 exact event scalar converts to 0x4000");

    // ESI is zero on entry to this branch (arg1==0), so the original call at
    // 0x7089e4 creates a manager through the actual 0x405170 pool route.
    const auto object=manager_from_pool(m,type);
    const auto position_factor=m.r32(m.r32(object+0x24u)+0x1cu)>>16u;
    const auto scaled=static_cast<std::uint32_t>((std::uint64_t(position_factor)*amount)>>14u);
    scalar_set_target_update(m,object+0xb8u,clamp_4000(scaled));
    // After PUSH ECX/EBX/EBP/ESI/EDI, the root's [ESP+0x10] read is the
    // overwritten saved-ECX slot, which contains entry EDX.
    scalar_set_fixed(m,object+0x108u,clamp_4000(i.dx));
    entry.eax=object;
    // POP ECX returns the entry EDX written into the saved-ECX slot. Caller
    // arguments themselves are unchanged before RET 8 discards them.
    entry.ecx=i.dx;
    return object;
}
}
