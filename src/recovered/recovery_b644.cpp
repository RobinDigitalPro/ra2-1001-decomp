#include "recovered/recovery_b644.hpp"
#include "recovered/recovery_b193.hpp"
#include "recovered/global_b26_memory.hpp"
#include "recovered/leaf_math.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b644 {
using floating_b61::Inputs; using floating_b61::Memory;
namespace {
enum class Root { r14e900, r14eca0, r151df0, r152190 };
void require(bool v,const char* why){if(!v)throw std::domain_error(why);}

std::uint32_t run(Memory& m,const Inputs& i,Root root){
    const auto index=i.arg[1]&7u;
    constexpr std::uint32_t local_pair=0x7e220000u;
    constexpr std::uint32_t local_coord=0x7e220100u;
    constexpr std::uint32_t local_direction=0x7e220200u;
    std::array<std::uint8_t,4> pair_bytes{};
    std::array<std::uint8_t,0x204> local_bytes{};
    const auto coord=m.r32(i.arg[0]);
    const auto direction=m.r32(0x00839da0u+index*4u);
    // The accepted leaf helper reads the coordinate and direction pair and
    // writes its output pair; keep those exact three locations in one bounded
    // adapter span without making the synthetic stack word part of the fixture.
    constexpr std::uint32_t local_base=0x7e220000u;
    leaf::Memory local_space(local_bytes.data(),local_base,local_bytes.size());
    leaf::Memory pair_span(pair_bytes.data(),local_pair,4u);
    Memory local=m;
    local.add(pair_span);
    const auto put32=[&](std::uint32_t address,std::uint32_t value){
        for(unsigned k=0;k<4;++k)local_space.w8(address+k,value>>(8u*k));
    };
    put32(local_coord,coord);put32(local_direction,direction);

    // Original instruction sequence calls accepted 0x42add0 with ECX=input
    // coordinate pointer, arg1=the selected direction pair and arg0=&caller
    // arg1. The temporary span models that caller stack slot; the visible
    // caller-word write is copied back exactly after the real helper model.
    leaf::Inputs direction_call{};
    direction_call.cx=local_coord;
    direction_call.arg[0]=local_pair;
    direction_call.arg[1]=local_direction;
    (void)leaf::fun_0042add0(local_space,direction_call);
    const auto packed=local_space.r32(local_pair);
    local.w32(local_pair,packed);
    i.arg[1]=packed;
    const auto xw=packed&0xffffu, yw=packed>>16u;
    const auto x=global_b26::s32(global_b26::sx16(xw));
    const auto y=global_b26::s32(global_b26::sx16(yw));
    const auto signed_index=y*0x200+x;
    require(signed_index>=0&&signed_index<0x40000,
            "B644 bounded route requires in-range packed coordinates");
    const auto table=m.r32(0x0081a958u);
    const auto cell=m.r32(table+std::uint32_t(signed_index)*4u);
    require(cell!=0,"B644 bounded route requires a populated center cell");

    // Each original wrapper has its own small type-byte transition. Choose
    // input kind 3 and bit 7 set, selecting only the ordinary transition and
    // excluding its recursive same-root and virtual callback branches.
    if((m.r8(cell+0x140u)&0x80u)!=0u){
        const auto kind=m.r8(cell+0x11eu);
        if(kind<=6u)m.w8(cell+0x11eu,
            (root==Root::r14eca0||root==Root::r152190)?8u:7u);
    }

    std::uint32_t base=0,first=0,alternate=0,unsupported=0;
    std::array<std::uint32_t,3> deltas{};
    switch(root){
    case Root::r14e900:
        base=0x00a547a0u; first=0x00a55c60u; alternate=0x00a3a8c0u;
        unsupported=0x00a547b4u; deltas={0u,2u,3u}; break;
    case Root::r14eca0:
        base=0x00a547a0u; first=0x00a55d1cu; alternate=0x00a3abb8u;
        unsupported=0x00a547b4u; deltas={0u,1u,3u}; break;
    case Root::r151df0:
        base=0x00a3a8b0u; first=0x00a55c60u; alternate=0x00a3a8c0u;
        unsupported=0x00a547b4u; deltas={0u,2u,3u}; break;
    case Root::r152190:
        base=0x00a3a8b0u; first=0x00a55d1cu; alternate=0x00a3abb8u;
        unsupported=0x00a547b4u; deltas={0u,1u,3u}; break;
    }
    const auto dispatch=m.r32(cell+0x38u)-m.r32(base)+1u;
    require(dispatch==m.r32(first),"B644 requires exact original first dispatch to 0x14e340");
    require(dispatch!=m.r32(alternate),"B644 excludes alternate dispatch");
    for(const auto d:deltas)if(d)require(dispatch!=m.r32(unsupported)+d,
            "B644 excludes the original 0x14e530 dispatch alternatives");
    require(dispatch!=m.r32(unsupported),"B644 excludes the original 0x14e530 base dispatch");

    Inputs inner=i;
    inner.arg[0]=local_pair; inner.arg[1]=1u; inner.arg[2]=0u;
    const auto result=recovery_b193::fun_0054e340(local,inner);
    i.fp=inner.fp;
    return result;
}
}
std::uint32_t fun_0054e900(Memory&m,const Inputs&i){return run(m,i,Root::r14e900);}
std::uint32_t fun_0054eca0(Memory&m,const Inputs&i){return run(m,i,Root::r14eca0);}
std::uint32_t fun_00551df0(Memory&m,const Inputs&i){return run(m,i,Root::r151df0);}
std::uint32_t fun_00552190(Memory&m,const Inputs&i){return run(m,i,Root::r152190);}
} // namespace ra2::recovered::recovery_b644
