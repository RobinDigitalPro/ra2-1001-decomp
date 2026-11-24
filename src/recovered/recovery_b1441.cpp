#include "recovered/recovery_b1441.hpp"
#include <stdexcept>

namespace ra2::recovered::b1441 {
std::uint32_t fun_004b2850(Memory& m,const Inputs& i) {
    // Finite original route: B2850 enters with mask 1, no prior focus, and a
    // coherent nonempty UTF-16 buffer. The constructor is fixture provenance,
    // not part of this root's recovered behavior.
    const auto self=i.cx;
    const auto requested=i.arg[0];
    if(requested!=1u || m.r32(self+0x44u)!=0u || m.r32(self+0x28u)!=0u)
        throw std::domain_error("B1441 selected initial-focus route");
    const auto vtable=m.r32(self);
    if(vtable!=0x78b7bcu || m.r32(vtable+0x50u)!=0x4b2c30u ||
       m.r32(vtable+0x48u)!=0x4cf180u)
        throw std::domain_error("B1441 original editor vtable slots");
    if(m.r32(0x84e328u)!=0u || m.r32(self+0x20u)!=1u ||
       m.r8(self+0x1cu)!=1u || m.r32(self+0x38u)!=640u)
        throw std::domain_error("B1441 post-constructor focus projection");

    // B2C30 (38 bytes) calls the actual 76EF45 UTF-16 length loop, stores the
    // count at self+3C, and then enters CF1C0. The finite buffer is terminated
    // within its declared 641 UTF-16 units.
    const auto text=m.r32(self+0x34u);
    if(!text)throw std::domain_error("B1441 nonnull text");
    std::uint32_t length=0;
    while(length<=640u && m.r16(text+2u*length)!=0u)++length;
    if(length==0u || length>640u || m.r32(self+0x3cu)!=length)
        throw std::domain_error("B1441 coherent positive UTF-16 length");
    m.w32(self+0x3cu,length);

    // CF1C0, with original global focus 84E328 == 0, skips its old-focus
    // virtual calls. Its OR AH,1 writes flags 1 -> 101 and publishes self.
    const auto flags=m.r32(self+0x20u);
    m.w32(self+0x20u,flags|0x100u);
    m.w32(0x84e328u,self);

    // The selected root then calls actual slot 48 (CF180), which marks +1C.
    m.w8(self+0x1cu,1u);

    // B2850 clears its handled low bit. BH is now zero, so the keyboard path
    // is skipped. It calls actual 83290 with EBX=0 and the caller's event
    // pointer. 83290 sees the genuine +28 null observer and calls CEE00 with
    // argument 0. CEE00's MOV EAX,[ESP+4] therefore returns that derived zero.
    const auto remaining=requested&~1u;
    if((remaining&0x100u)!=0u || m.r32(self+0x28u)!=0u)
        throw std::domain_error("B1441 zero-remaining-mask/no-observer path");
    const auto b83290_callback_arg0=remaining;
    const auto eax_from_cee00=b83290_callback_arg0;
    return eax_from_cee00;
}
}
