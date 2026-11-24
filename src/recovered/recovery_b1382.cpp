#include "recovery_b1382.hpp"
#include <stdexcept>
namespace ra2::recovered::b1382 {
namespace {
using U=std::uint32_t;
void need(bool b,const char* s){if(!b)throw std::domain_error(s);}
U kind_00463ac0(){return 8u;} // Actual six-byte MOV EAX,8 / RET leaf.
}
U fun_006ba1e0(Memory& m,const Inputs& i){
    need(i.arg[1]!=0u&&i.arg[2]!=0u,"B1382 nonnull target and descriptor");
    const U range=m.r32(i.arg[2]+0xb4u);
    need(range==0xfffffe00u,"B1382 original Range=-2 scaled sentinel");
    // No EAX write precedes MOV AL,1 on this original path.
    return (i.ax&0xffffff00u)|1u;
}
U fun_004bf560(Memory& m,const Inputs& i){
    const U actor=m.r32(i.cx+0xcu);
    need(actor!=0u,"B1382 attached nonnull actor");
    const U vtable=m.r32(actor);
    need(vtable==0x788374u&&m.r32(vtable+0x2cu)==0x463ac0u,"B1382 original kind provider");
    const U kind=kind_00463ac0();
    need(kind!=2u,"B1382 non-kind2 route");
    need(m.r8(i.cx+0x51u)==0u&&m.r8(i.cx+0x5cu)==0u,"B1382 original constructor flag state");
    // The actual provider fully wrote EAX=8; the final byte write yields 1.
    return (kind&0xffffff00u)|1u;
}
}
