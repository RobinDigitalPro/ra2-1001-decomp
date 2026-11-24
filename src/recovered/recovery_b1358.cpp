#include "recovery_b1358.hpp"
#include <stdexcept>
namespace ra2::recovered::b1358 {
namespace {
using U=std::uint32_t;
void require_route(bool valid, const char* reason) {
    if(!valid) throw std::domain_error(reason);
}
// Original 004068F0 consists of C3 only. Its physical return preserves EAX;
// the historical mask-zero portable leaf result is deliberately not composed.
// No arguments are dereferenced, and there are no memory or numeric FP effects.
U exact_ret_004068f0(U eax) noexcept { return eax; }
U low_byte(U eax, U byte) noexcept { return (eax&0xffffff00u)|(byte&255u); }
}
U fun_006686b0(Memory& m, const Inputs& i) {
    const U flags=m.r32(0xa255c0);
    require_route(m.r32(i.cx)==4 && m.r8(i.cx+0x638)==1 &&
                  (m.r32(flags)&0x400u)!=0 && m.r8(0xb0fcf4)==0,
                  "B1358 mode4 paired invalidation with initially set flags and empty configuration");
    m.w8(i.cx+0x638,0);                         // 6686BD
    U eax=flags;
    const U edx=m.r32(eax)&0xfffffbffu;         // AND DH,FB at 6686DB
    m.w32(eax,edx);
    eax=exact_ret_004068f0(eax);              // 6686E0; two private pushed pointers
    eax=exact_ret_004068f0(eax);              // 6686EF; two further private pointers
    // XOR EAX,EAX, then REPNE SCASB on the proved first NUL consumes one byte.
    // NOT/DEC of FFFFFFFE yields length zero and branches to the balanced RET.
    eax=0;
    return eax;
}
U fun_00711b80(Memory& m, const Inputs& i) {
    require_route(m.r8(i.cx+0x549)==1 && m.r8(i.cx+0x548)==0 &&
                  m.r8(i.cx+0x50c)==0 && m.r8(0xa28968)!=1 &&
                  m.r8(0xae0a9c)==0 && m.r8(i.arg[0])==1,
                  "B1358 one-time three-byte publication route");
    m.w8(i.arg[0],0);                          // 711B8B; outer arg0 pointer is unchanged
    U eax=low_byte(i.ax,m.r8(i.cx+0x549));
    eax=low_byte(eax,m.r8(0xae0a9c));
    eax=low_byte(eax,m.r8(i.cx+0x50c));
    m.w8(i.cx+0x548,1);                        // 711D33
    m.w8(0xae0a9c,1);                          // 711D3F
    eax=exact_ret_004068f0(eax);              // 711D46; actual C3 keeps high24
    return low_byte(eax,0);                    // XOR AL,AL; RET4
}
}
