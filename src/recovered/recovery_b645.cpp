#include "recovered/recovery_b645.hpp"
#include "recovered/recovery_b193.hpp"
#include "recovered/global_b26_memory.hpp"
#include "recovered/leaf_math.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b645 {
using floating_b61::Inputs; using floating_b61::Memory;
namespace {
enum class Root { r14f260, r14f630, r152750, r152b20 };
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
            "B645 bounded route requires in-range packed coordinates");
    const auto table=m.r32(0x0081a958u);
    const auto cell=m.r32(table+std::uint32_t(signed_index)*4u);
    require(cell!=0,"B645 bounded route requires a populated center cell");

    // This 964-byte family enters its dispatch block directly when the type
    // byte is below 9. Keep kind 3 so its special recursive mutation branch is
    // not reached; these four roots do not change the type byte on this route.
    require(m.r8(cell+0x11eu)<9u,"B645 bounded route requires center kind below 9");

    std::uint32_t base=0,first=0,alternate=0,unsupported=0;
    std::array<std::uint32_t,3> deltas{};
    switch(root){
    case Root::r14f260:
        base=0x00a547a0u; first=0x00a55c48u; alternate=0x00a3afc8u;
        unsupported=0x00a3aab0u; deltas={0u,2u,3u}; break;
    case Root::r14f630:
        base=0x00a547a0u; first=0x00a3afccu; alternate=0x00a3a1c0u;
        unsupported=0x00a3aab0u; deltas={0u,1u,3u}; break;
    case Root::r152750:
        base=0x00a3a8b0u; first=0x00a55c48u; alternate=0x00a3afc8u;
        unsupported=0x00a3aab0u; deltas={0u,2u,3u}; break;
    case Root::r152b20:
        base=0x00a3a8b0u; first=0x00a3afccu; alternate=0x00a3a1c0u;
        unsupported=0x00a3aab0u; deltas={0u,1u,3u}; break;
    }
    const auto dispatch=m.r32(cell+0x38u)-m.r32(base)+1u;
    require(dispatch==m.r32(first),"B645 requires exact original first dispatch to 0x14e340");
    require(dispatch!=m.r32(alternate),"B645 excludes alternate dispatch");
    for(const auto d:deltas)if(d)require(dispatch!=m.r32(unsupported)+d,
            "B645 excludes the original 0x14e530 dispatch alternatives");
    require(dispatch!=m.r32(unsupported),"B645 excludes the original 0x14e530 base dispatch");

    Inputs inner=i;
    inner.arg[0]=local_pair; inner.arg[1]=1u; inner.arg[2]=0u;
    const auto result=recovery_b193::fun_0054e340(local,inner);
    i.fp=inner.fp;
    return result;
}
}
std::uint32_t fun_0054f260(Memory&m,const Inputs&i){return run(m,i,Root::r14f260);}
std::uint32_t fun_0054f630(Memory&m,const Inputs&i){return run(m,i,Root::r14f630);}
std::uint32_t fun_00552750(Memory&m,const Inputs&i){return run(m,i,Root::r152750);}
std::uint32_t fun_00552b20(Memory&m,const Inputs&i){return run(m,i,Root::r152b20);}
} // namespace ra2::recovered::recovery_b645
