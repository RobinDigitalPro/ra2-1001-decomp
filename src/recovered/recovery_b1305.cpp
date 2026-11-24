#include "recovery_b1305.hpp"
#include <stdexcept>

namespace ra2::recovered::b1305 {
namespace {
void need(bool v,const char* why){if(!v)throw std::domain_error(why);}
}
U run(global_b26::Memory& m,const Inputs& i){
    // Bounded original action-15 route only: entry 0x418840, RET 12.
    constexpr U vtable=0x0078612cu;
    need(i.cx!=0u,"B1305 nonnull root receiver");
    const U action=i.arg[1];
    need(action==15u,"B1305 supports original selector index 7 only");
    need(m.r32(i.cx)==vtable,"B1305 root vptr from original constructor stores");
    
    need(m.r32(vtable+0x3cu)==0x006bca10u,"B1305 pinned +0x3c owner getter");
    const U mode=m.r32(i.cx+0x98u);
    need(mode<=25u&&mode!=4u,"B1305 original action dispatcher precondition");
    const U self=i.arg[0];
    need(self!=0u,"B1305 nonnull self argument");
    const U type=m.r32(i.cx+0x5acu);
    const U owner=m.r32(i.cx+0x1b4u);
    need(type!=0u&&owner!=0u,"B1305 nonnull type and owner read set");
    const U bound=m.r32(type+0x52cu);
    need(bound!=0u,"B1305 action-15 type bound nonzero");

    // Original 0x4E4C20: the target-argument's actual +0x3c virtual getter is
    // 0x6BCA10 (`mov eax,[ecx+1b4]; ret`). Its returned owner matches ECX.
    need(m.r32(self)==vtable,"B1305 self vptr uses same constructor-installed table");
    need(m.r32(vtable+0x3cu)==0x006bca10u,"B1305 exact original getter target");
    const U self_owner=m.r32(self+0x1b4u);
    need(self_owner==owner,"B1305 original 0x4E4C20 pointer-identity success branch");

    // At original VA 0x418C25, SETGE/DEC/AND-AL/ADD 10 returns 1 when F8 < +52c.
    need(global_b26::s32(m.r32(i.cx+0xf8u))<global_b26::s32(bound),"B1305 positive signed target-F8/type+52c comparison");
    return 1u;
}
}



