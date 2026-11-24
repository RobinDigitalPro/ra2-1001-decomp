#include "recovery_b1685.hpp"
#include <stdexcept>
namespace ra2::recovered::b1685 {
namespace {
void require(bool ok){if(!ok)throw std::invalid_argument("32A3A0 excluded finite owned-window contract");}
void normal_empty_registry(Memory&m){
    require(m.r32(0xa59518u)==0x7920b4u);
    require(m.r32(0xa5951cu)==0u&&m.r32(0xa59520u)==0u);
    require(m.r8(0xa59524u)==1u&&m.r8(0xa59525u)==0u);
    require(m.r32(0xa59528u)==0u&&m.r32(0xa5952cu)==10u);
    require(m.r32(0x7920c4u)==0x5b3020u);
}
}
unsigned run(Memory&m,const Inputs&in,Api&api,Observation&out){
    out={};
    require(m.r32(0xb0d858u)==1u);
    const unsigned hwnd=m.r32(0xb0d630u);
    require(hwnd!=0u&&(in.cx==0u||in.cx==hwnd));
    require(m.r32(0xb0de50u)==0u);
    // Real 1DE430 calls accepted byte getter669140 with ECX=A255C8.
    // A27F64=1 selects5DE60A: restore private frame and return AL0;
    // neither helper nor getter writes this flag or any global.
    require(m.r8(0xa27f64u)==1u);
    normal_empty_registry(m);
    out.hwnd=hwnd;out.stage=1u;
    // Index0 is the sole positive Root search hit. 5B2B70 reaches the
    // authentic normal-registry slot+10 Find5B3020; count0 returns full
    // FFFFFFFF with RET4 and skips removal, backing reads and registry writes.
    // SDK adapter must observe that HWND is process-owned before forwarding.
    out.destroy_result=api.destroy_window(hwnd);out.stage=2u;
    m.w32(0xa28974u,m.r32(0xa28974u)-1u);
    m.w32(0xb0d858u,0u);out.stage=3u;
    // EDI=index0 selects the empty-stack branch, bypassing every foreground,
    // visible-window and other UI path. The entry table itself is retained.
    const unsigned focus_target=m.r32(0xb0de50u);
    m.w32(0xb0d84cu,0u);
    m.w32(0xb0d850u,0u);
    out.focus_result=api.set_focus(focus_target);out.stage=4u;
    // MOV AL,1 preserves the actual SetFocus EAX upper24 bits. The following
    // ECX reload gets the original input EDX saved in Root private[S-4].
    const unsigned result=(out.focus_result&0xffffff00u)|1u;
    m.w32(0xb0d854u,in.dx);out.stage=5u;
    return result;
}
unsigned run(Memory&m,const Inputs&in,Api&api){Observation out;return run(m,in,api,out);}
}
