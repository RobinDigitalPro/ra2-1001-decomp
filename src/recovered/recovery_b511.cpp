// Exact instruction-model selector bodies extracted from the existing cached translations.
// Private B511 entry adapters use +8!=0 so the original initialization call is unreachable.
#include "recovered/recovery_b239_machine.hpp"
#include "recovered/recovery_b238_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b239 {
namespace {
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t) {
 throw std::domain_error("B511 excluded selector initialization path");
}
void f_00085880(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00485880: { // 0x485880: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00485881: { // 0x485881: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00485883: { // 0x485883: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00485886: { // 0x485886: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00485888: { // 0x485888: 7505 JNZ 0x0048588f
    if(integer::condition("JNZ",flags)) goto L0048588f;
  }
  L0048588a: { // 0x48588a: e851e0ffff CALL 0x004838e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004838e0u,4741263u); flags=s.arithmetic_flags;
  }
  L0048588f: { // 0x48588f: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00485893: { // 0x485893: a810 TEST AL,0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L00485895: { // 0x485895: 744c JZ 0x004858e3
    if(integer::condition("JZ",flags)) goto L004858e3;
  }
  L00485897: { // 0x485897: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0048589a: { // 0x48589a: 7416 JZ 0x004858b2
    if(integer::condition("JZ",flags)) goto L004858b2;
  }
  L0048589c: { // 0x48589c: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L0048589f: { // 0x48589f: 740a JZ 0x004858ab
    if(integer::condition("JZ",flags)) goto L004858ab;
  }
  L004858a1: { // 0x4858a1: 8b86c0000000 MOV EAX,dword ptr [ESI + 0xc0]
    s.ax = m.r32((s.si+0x000000c0u));
  }
  L004858a7: { // 0x4858a7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004858a8: { // 0x4858a8: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004858ab: { // 0x4858ab: 8b4658 MOV EAX,dword ptr [ESI + 0x58]
    s.ax = m.r32((s.si+0x00000058u));
  }
  L004858ae: { // 0x4858ae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004858af: { // 0x4858af: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004858b2: { // 0x4858b2: 8505a8eb7b00 TEST dword ptr [0x007beba8],EAX
    (void)integer::logical((m.r32((0x007beba8u)))&(s.ax),32,flags);
  }
  L004858b8: { // 0x4858b8: 7416 JZ 0x004858d0
    if(integer::condition("JZ",flags)) goto L004858d0;
  }
  L004858ba: { // 0x4858ba: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L004858bd: { // 0x4858bd: 740a JZ 0x004858c9
    if(integer::condition("JZ",flags)) goto L004858c9;
  }
  L004858bf: { // 0x4858bf: 8b869c000000 MOV EAX,dword ptr [ESI + 0x9c]
    s.ax = m.r32((s.si+0x0000009cu));
  }
  L004858c5: { // 0x4858c5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004858c6: { // 0x4858c6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004858c9: { // 0x4858c9: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L004858cc: { // 0x4858cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004858cd: { // 0x4858cd: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004858d0: { // 0x4858d0: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L004858d3: { // 0x4858d3: 7407 JZ 0x004858dc
    if(integer::condition("JZ",flags)) goto L004858dc;
  }
  L004858d5: { // 0x4858d5: 8b4670 MOV EAX,dword ptr [ESI + 0x70]
    s.ax = m.r32((s.si+0x00000070u));
  }
  L004858d8: { // 0x4858d8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004858d9: { // 0x4858d9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004858dc: { // 0x4858dc: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L004858df: { // 0x4858df: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004858e0: { // 0x4858e0: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004858e3: { // 0x4858e3: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004858e5: { // 0x4858e5: 83e106 AND ECX,0x6
    s.cx = integer::logical((s.cx)&(0x00000006u),32,flags);
  }
  L004858e8: { // 0x4858e8: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L004858eb: { // 0x4858eb: 0f84e0010000 JZ 0x00485ad1
    if(integer::condition("JZ",flags)) goto L00485ad1;
  }
  L004858f1: { // 0x4858f1: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L004858f4: { // 0x4858f4: 0f844f010000 JZ 0x00485a49
    if(integer::condition("JZ",flags)) goto L00485a49;
  }
  L004858fa: { // 0x4858fa: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L004858fd: { // 0x4858fd: 0f84e0000000 JZ 0x004859e3
    if(integer::condition("JZ",flags)) goto L004859e3;
  }
  L00485903: { // 0x485903: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00485905: { // 0x485905: 7422 JZ 0x00485929
    if(integer::condition("JZ",flags)) goto L00485929;
  }
  L00485907: { // 0x485907: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0048590a: { // 0x48590a: 7407 JZ 0x00485913
    if(integer::condition("JZ",flags)) goto L00485913;
  }
  L0048590c: { // 0x48590c: 8b4654 MOV EAX,dword ptr [ESI + 0x54]
    s.ax = m.r32((s.si+0x00000054u));
  }
  L0048590f: { // 0x48590f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485910: { // 0x485910: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485913: { // 0x485913: 8505a8eb7b00 TEST dword ptr [0x007beba8],EAX
    (void)integer::logical((m.r32((0x007beba8u)))&(s.ax),32,flags);
  }
  L00485919: { // 0x485919: 7407 JZ 0x00485922
    if(integer::condition("JZ",flags)) goto L00485922;
  }
  L0048591b: { // 0x48591b: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  L0048591e: { // 0x48591e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0048591f: { // 0x48591f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485922: { // 0x485922: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00485925: { // 0x485925: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485926: { // 0x485926: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485929: { // 0x485929: a820 TEST AL,0x20
    (void)integer::logical(((s.ax & 0xffu))&(0x00000020u),8,flags);
  }
  L0048592b: { // 0x48592b: 743e JZ 0x0048596b
    if(integer::condition("JZ",flags)) goto L0048596b;
  }
  L0048592d: { // 0x48592d: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485930: { // 0x485930: 740f JZ 0x00485941
    if(integer::condition("JZ",flags)) goto L00485941;
  }
  L00485932: { // 0x485932: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485935: { // 0x485935: 7448 JZ 0x0048597f
    if(integer::condition("JZ",flags)) goto L0048597f;
  }
  L00485937: { // 0x485937: 8b86bc000000 MOV EAX,dword ptr [ESI + 0xbc]
    s.ax = m.r32((s.si+0x000000bcu));
  }
  L0048593d: { // 0x48593d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0048593e: { // 0x48593e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485941: { // 0x485941: 8505a8eb7b00 TEST dword ptr [0x007beba8],EAX
    (void)integer::logical((m.r32((0x007beba8u)))&(s.ax),32,flags);
  }
  L00485947: { // 0x485947: 740f JZ 0x00485958
    if(integer::condition("JZ",flags)) goto L00485958;
  }
  L00485949: { // 0x485949: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L0048594c: { // 0x48594c: 744f JZ 0x0048599d
    if(integer::condition("JZ",flags)) goto L0048599d;
  }
  L0048594e: { // 0x48594e: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L00485954: { // 0x485954: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485955: { // 0x485955: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485958: { // 0x485958: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L0048595b: { // 0x48595b: 7407 JZ 0x00485964
    if(integer::condition("JZ",flags)) goto L00485964;
  }
  L0048595d: { // 0x48595d: 8b4668 MOV EAX,dword ptr [ESI + 0x68]
    s.ax = m.r32((s.si+0x00000068u));
  }
  L00485960: { // 0x485960: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485961: { // 0x485961: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485964: { // 0x485964: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00485967: { // 0x485967: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485968: { // 0x485968: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0048596b: { // 0x48596b: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0048596e: { // 0x48596e: 7416 JZ 0x00485986
    if(integer::condition("JZ",flags)) goto L00485986;
  }
  L00485970: { // 0x485970: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485973: { // 0x485973: 740a JZ 0x0048597f
    if(integer::condition("JZ",flags)) goto L0048597f;
  }
  L00485975: { // 0x485975: 8b86bc000000 MOV EAX,dword ptr [ESI + 0xbc]
    s.ax = m.r32((s.si+0x000000bcu));
  }
  L0048597b: { // 0x48597b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0048597c: { // 0x48597c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0048597f: { // 0x48597f: 8b4650 MOV EAX,dword ptr [ESI + 0x50]
    s.ax = m.r32((s.si+0x00000050u));
  }
  L00485982: { // 0x485982: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485983: { // 0x485983: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485986: { // 0x485986: 8505a8eb7b00 TEST dword ptr [0x007beba8],EAX
    (void)integer::logical((m.r32((0x007beba8u)))&(s.ax),32,flags);
  }
  L0048598c: { // 0x48598c: 7416 JZ 0x004859a4
    if(integer::condition("JZ",flags)) goto L004859a4;
  }
  L0048598e: { // 0x48598e: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485991: { // 0x485991: 740a JZ 0x0048599d
    if(integer::condition("JZ",flags)) goto L0048599d;
  }
  L00485993: { // 0x485993: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L00485999: { // 0x485999: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0048599a: { // 0x48599a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0048599d: { // 0x48599d: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  L004859a0: { // 0x4859a0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004859a1: { // 0x4859a1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004859a4: { // 0x4859a4: f6c480 TEST AH,0x80
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000080u),8,flags);
  }
  L004859a7: { // 0x4859a7: 740a JZ 0x004859b3
    if(integer::condition("JZ",flags)) goto L004859b3;
  }
  L004859a9: { // 0x4859a9: 8b8680000000 MOV EAX,dword ptr [ESI + 0x80]
    s.ax = m.r32((s.si+0x00000080u));
  }
  L004859af: { // 0x4859af: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004859b0: { // 0x4859b0: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004859b3: { // 0x4859b3: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L004859b6: { // 0x4859b6: 740a JZ 0x004859c2
    if(integer::condition("JZ",flags)) goto L004859c2;
  }
  L004859b8: { // 0x4859b8: 8b8684000000 MOV EAX,dword ptr [ESI + 0x84]
    s.ax = m.r32((s.si+0x00000084u));
  }
  L004859be: { // 0x4859be: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004859bf: { // 0x4859bf: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004859c2: { // 0x4859c2: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L004859c4: { // 0x4859c4: 740a JZ 0x004859d0
    if(integer::condition("JZ",flags)) goto L004859d0;
  }
  L004859c6: { // 0x4859c6: 8b8688000000 MOV EAX,dword ptr [ESI + 0x88]
    s.ax = m.r32((s.si+0x00000088u));
  }
  L004859cc: { // 0x4859cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004859cd: { // 0x4859cd: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004859d0: { // 0x4859d0: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L004859d3: { // 0x4859d3: 7407 JZ 0x004859dc
    if(integer::condition("JZ",flags)) goto L004859dc;
  }
  L004859d5: { // 0x4859d5: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L004859d8: { // 0x4859d8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004859d9: { // 0x4859d9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004859dc: { // 0x4859dc: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L004859df: { // 0x4859df: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004859e0: { // 0x4859e0: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004859e3: { // 0x4859e3: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004859e6: { // 0x4859e6: 7416 JZ 0x004859fe
    if(integer::condition("JZ",flags)) goto L004859fe;
  }
  L004859e8: { // 0x4859e8: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L004859eb: { // 0x4859eb: 740a JZ 0x004859f7
    if(integer::condition("JZ",flags)) goto L004859f7;
  }
  L004859ed: { // 0x4859ed: 8b86c4000000 MOV EAX,dword ptr [ESI + 0xc4]
    s.ax = m.r32((s.si+0x000000c4u));
  }
  L004859f3: { // 0x4859f3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004859f4: { // 0x4859f4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004859f7: { // 0x4859f7: 8b465c MOV EAX,dword ptr [ESI + 0x5c]
    s.ax = m.r32((s.si+0x0000005cu));
  }
  L004859fa: { // 0x4859fa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004859fb: { // 0x4859fb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004859fe: { // 0x4859fe: 8505a8eb7b00 TEST dword ptr [0x007beba8],EAX
    (void)integer::logical((m.r32((0x007beba8u)))&(s.ax),32,flags);
  }
  L00485a04: { // 0x485a04: 7430 JZ 0x00485a36
    if(integer::condition("JZ",flags)) goto L00485a36;
  }
  L00485a06: { // 0x485a06: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a08: { // 0x485a08: 7416 JZ 0x00485a20
    if(integer::condition("JZ",flags)) goto L00485a20;
  }
  L00485a0a: { // 0x485a0a: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a0d: { // 0x485a0d: 740a JZ 0x00485a19
    if(integer::condition("JZ",flags)) goto L00485a19;
  }
  L00485a0f: { // 0x485a0f: 8b86ac000000 MOV EAX,dword ptr [ESI + 0xac]
    s.ax = m.r32((s.si+0x000000acu));
  }
  L00485a15: { // 0x485a15: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a16: { // 0x485a16: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a19: { // 0x485a19: 8b4640 MOV EAX,dword ptr [ESI + 0x40]
    s.ax = m.r32((s.si+0x00000040u));
  }
  L00485a1c: { // 0x485a1c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a1d: { // 0x485a1d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a20: { // 0x485a20: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a23: { // 0x485a23: 740a JZ 0x00485a2f
    if(integer::condition("JZ",flags)) goto L00485a2f;
  }
  L00485a25: { // 0x485a25: 8b86a0000000 MOV EAX,dword ptr [ESI + 0xa0]
    s.ax = m.r32((s.si+0x000000a0u));
  }
  L00485a2b: { // 0x485a2b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a2c: { // 0x485a2c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a2f: { // 0x485a2f: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  L00485a32: { // 0x485a32: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a33: { // 0x485a33: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a36: { // 0x485a36: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a39: { // 0x485a39: 7407 JZ 0x00485a42
    if(integer::condition("JZ",flags)) goto L00485a42;
  }
  L00485a3b: { // 0x485a3b: 8b4674 MOV EAX,dword ptr [ESI + 0x74]
    s.ax = m.r32((s.si+0x00000074u));
  }
  L00485a3e: { // 0x485a3e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a3f: { // 0x485a3f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a42: { // 0x485a42: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  L00485a45: { // 0x485a45: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a46: { // 0x485a46: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a49: { // 0x485a49: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485a4c: { // 0x485a4c: 7416 JZ 0x00485a64
    if(integer::condition("JZ",flags)) goto L00485a64;
  }
  L00485a4e: { // 0x485a4e: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a51: { // 0x485a51: 740a JZ 0x00485a5d
    if(integer::condition("JZ",flags)) goto L00485a5d;
  }
  L00485a53: { // 0x485a53: 8b86c8000000 MOV EAX,dword ptr [ESI + 0xc8]
    s.ax = m.r32((s.si+0x000000c8u));
  }
  L00485a59: { // 0x485a59: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a5a: { // 0x485a5a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a5d: { // 0x485a5d: 8b4660 MOV EAX,dword ptr [ESI + 0x60]
    s.ax = m.r32((s.si+0x00000060u));
  }
  L00485a60: { // 0x485a60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a61: { // 0x485a61: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a64: { // 0x485a64: 8505a8eb7b00 TEST dword ptr [0x007beba8],EAX
    (void)integer::logical((m.r32((0x007beba8u)))&(s.ax),32,flags);
  }
  L00485a6a: { // 0x485a6a: 7430 JZ 0x00485a9c
    if(integer::condition("JZ",flags)) goto L00485a9c;
  }
  L00485a6c: { // 0x485a6c: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a6e: { // 0x485a6e: 7416 JZ 0x00485a86
    if(integer::condition("JZ",flags)) goto L00485a86;
  }
  L00485a70: { // 0x485a70: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a73: { // 0x485a73: 740a JZ 0x00485a7f
    if(integer::condition("JZ",flags)) goto L00485a7f;
  }
  L00485a75: { // 0x485a75: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00485a7b: { // 0x485a7b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a7c: { // 0x485a7c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a7f: { // 0x485a7f: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  L00485a82: { // 0x485a82: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a83: { // 0x485a83: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a86: { // 0x485a86: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a89: { // 0x485a89: 740a JZ 0x00485a95
    if(integer::condition("JZ",flags)) goto L00485a95;
  }
  L00485a8b: { // 0x485a8b: 8b86a4000000 MOV EAX,dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  L00485a91: { // 0x485a91: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a92: { // 0x485a92: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a95: { // 0x485a95: 8b4638 MOV EAX,dword ptr [ESI + 0x38]
    s.ax = m.r32((s.si+0x00000038u));
  }
  L00485a98: { // 0x485a98: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485a99: { // 0x485a99: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485a9c: { // 0x485a9c: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485a9f: { // 0x485a9f: 7407 JZ 0x00485aa8
    if(integer::condition("JZ",flags)) goto L00485aa8;
  }
  L00485aa1: { // 0x485aa1: 8b4678 MOV EAX,dword ptr [ESI + 0x78]
    s.ax = m.r32((s.si+0x00000078u));
  }
  L00485aa4: { // 0x485aa4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485aa5: { // 0x485aa5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485aa8: { // 0x485aa8: a900000100 TEST EAX,0x10000
    (void)integer::logical((s.ax)&(0x00010000u),32,flags);
  }
  L00485aad: { // 0x485aad: 740a JZ 0x00485ab9
    if(integer::condition("JZ",flags)) goto L00485ab9;
  }
  L00485aaf: { // 0x485aaf: 8b8690000000 MOV EAX,dword ptr [ESI + 0x90]
    s.ax = m.r32((s.si+0x00000090u));
  }
  L00485ab5: { // 0x485ab5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ab6: { // 0x485ab6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ab9: { // 0x485ab9: a900000200 TEST EAX,0x20000
    (void)integer::logical((s.ax)&(0x00020000u),32,flags);
  }
  L00485abe: { // 0x485abe: 740a JZ 0x00485aca
    if(integer::condition("JZ",flags)) goto L00485aca;
  }
  L00485ac0: { // 0x485ac0: 8b868c000000 MOV EAX,dword ptr [ESI + 0x8c]
    s.ax = m.r32((s.si+0x0000008cu));
  }
  L00485ac6: { // 0x485ac6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ac7: { // 0x485ac7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485aca: { // 0x485aca: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  L00485acd: { // 0x485acd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ace: { // 0x485ace: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ad1: { // 0x485ad1: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485ad4: { // 0x485ad4: 7416 JZ 0x00485aec
    if(integer::condition("JZ",flags)) goto L00485aec;
  }
  L00485ad6: { // 0x485ad6: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485ad9: { // 0x485ad9: 740a JZ 0x00485ae5
    if(integer::condition("JZ",flags)) goto L00485ae5;
  }
  L00485adb: { // 0x485adb: 8b86cc000000 MOV EAX,dword ptr [ESI + 0xcc]
    s.ax = m.r32((s.si+0x000000ccu));
  }
  L00485ae1: { // 0x485ae1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ae2: { // 0x485ae2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ae5: { // 0x485ae5: 8b4664 MOV EAX,dword ptr [ESI + 0x64]
    s.ax = m.r32((s.si+0x00000064u));
  }
  L00485ae8: { // 0x485ae8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ae9: { // 0x485ae9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485aec: { // 0x485aec: 8505a8eb7b00 TEST dword ptr [0x007beba8],EAX
    (void)integer::logical((m.r32((0x007beba8u)))&(s.ax),32,flags);
  }
  L00485af2: { // 0x485af2: 7430 JZ 0x00485b24
    if(integer::condition("JZ",flags)) goto L00485b24;
  }
  L00485af4: { // 0x485af4: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485af6: { // 0x485af6: 7416 JZ 0x00485b0e
    if(integer::condition("JZ",flags)) goto L00485b0e;
  }
  L00485af8: { // 0x485af8: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485afb: { // 0x485afb: 740a JZ 0x00485b07
    if(integer::condition("JZ",flags)) goto L00485b07;
  }
  L00485afd: { // 0x485afd: 8b86b4000000 MOV EAX,dword ptr [ESI + 0xb4]
    s.ax = m.r32((s.si+0x000000b4u));
  }
  L00485b03: { // 0x485b03: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b04: { // 0x485b04: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b07: { // 0x485b07: 8b4648 MOV EAX,dword ptr [ESI + 0x48]
    s.ax = m.r32((s.si+0x00000048u));
  }
  L00485b0a: { // 0x485b0a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b0b: { // 0x485b0b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b0e: { // 0x485b0e: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485b11: { // 0x485b11: 740a JZ 0x00485b1d
    if(integer::condition("JZ",flags)) goto L00485b1d;
  }
  L00485b13: { // 0x485b13: 8b86a8000000 MOV EAX,dword ptr [ESI + 0xa8]
    s.ax = m.r32((s.si+0x000000a8u));
  }
  L00485b19: { // 0x485b19: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b1a: { // 0x485b1a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b1d: { // 0x485b1d: 8b463c MOV EAX,dword ptr [ESI + 0x3c]
    s.ax = m.r32((s.si+0x0000003cu));
  }
  L00485b20: { // 0x485b20: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b21: { // 0x485b21: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b24: { // 0x485b24: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485b27: { // 0x485b27: 7407 JZ 0x00485b30
    if(integer::condition("JZ",flags)) goto L00485b30;
  }
  L00485b29: { // 0x485b29: 8b467c MOV EAX,dword ptr [ESI + 0x7c]
    s.ax = m.r32((s.si+0x0000007cu));
  }
  L00485b2c: { // 0x485b2c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b2d: { // 0x485b2d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b30: { // 0x485b30: 8b4620 MOV EAX,dword ptr [ESI + 0x20]
    s.ax = m.r32((s.si+0x00000020u));
  }
  L00485b33: { // 0x485b33: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b34: { // 0x485b34: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
}
namespace selectors511 {
using namespace floating_b61;

template<class Function>
std::uint32_t run_selector(Memory& original, const Inputs& i, Function function) {
 std::array<std::uint8_t,0x8000> stack{};
 constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));
 Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};
 m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);
 function(m,s,f,op);
 for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);
 return s.ax;
}

std::uint32_t select_85880(Memory& m,const Inputs& i) {
 return run_selector(m,i,[](Memory& mm,State& s,Frame& f,const Operations& op){f_00085880(mm,s,f,op);});
}
}
}

namespace ra2::recovered::recovery_b238 {
namespace {
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t) {
 throw std::domain_error("B511 excluded selector initialization path");
}
void f_00085b40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00485b40: { // 0x485b40: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00485b41: { // 0x485b41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00485b43: { // 0x485b43: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00485b46: { // 0x485b46: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00485b48: { // 0x485b48: 7505 JNZ 0x00485b4f
    if(integer::condition("JNZ",flags)) goto L00485b4f;
  }
  L00485b4a: { // 0x485b4a: e891ddffff CALL 0x004838e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004838e0u,4741967u); flags=s.arithmetic_flags;
  }
  L00485b4f: { // 0x485b4f: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00485b53: { // 0x485b53: a810 TEST AL,0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L00485b55: { // 0x485b55: 7458 JZ 0x00485baf
    if(integer::condition("JZ",flags)) goto L00485baf;
  }
  L00485b57: { // 0x485b57: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485b5a: { // 0x485b5a: 7419 JZ 0x00485b75
    if(integer::condition("JZ",flags)) goto L00485b75;
  }
  L00485b5c: { // 0x485b5c: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485b5f: { // 0x485b5f: 740a JZ 0x00485b6b
    if(integer::condition("JZ",flags)) goto L00485b6b;
  }
  L00485b61: { // 0x485b61: 8b865c010000 MOV EAX,dword ptr [ESI + 0x15c]
    s.ax = m.r32((s.si+0x0000015cu));
  }
  L00485b67: { // 0x485b67: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b68: { // 0x485b68: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b6b: { // 0x485b6b: 8b8610010000 MOV EAX,dword ptr [ESI + 0x110]
    s.ax = m.r32((s.si+0x00000110u));
  }
  L00485b71: { // 0x485b71: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b72: { // 0x485b72: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b75: { // 0x485b75: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485b7b: { // 0x485b7b: 7419 JZ 0x00485b96
    if(integer::condition("JZ",flags)) goto L00485b96;
  }
  L00485b7d: { // 0x485b7d: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485b80: { // 0x485b80: 740a JZ 0x00485b8c
    if(integer::condition("JZ",flags)) goto L00485b8c;
  }
  L00485b82: { // 0x485b82: 8b863c010000 MOV EAX,dword ptr [ESI + 0x13c]
    s.ax = m.r32((s.si+0x0000013cu));
  }
  L00485b88: { // 0x485b88: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b89: { // 0x485b89: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b8c: { // 0x485b8c: 8b86ec000000 MOV EAX,dword ptr [ESI + 0xec]
    s.ax = m.r32((s.si+0x000000ecu));
  }
  L00485b92: { // 0x485b92: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b93: { // 0x485b93: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b96: { // 0x485b96: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485b99: { // 0x485b99: 740a JZ 0x00485ba5
    if(integer::condition("JZ",flags)) goto L00485ba5;
  }
  L00485b9b: { // 0x485b9b: 8b8628010000 MOV EAX,dword ptr [ESI + 0x128]
    s.ax = m.r32((s.si+0x00000128u));
  }
  L00485ba1: { // 0x485ba1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ba2: { // 0x485ba2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ba5: { // 0x485ba5: 8b86d8000000 MOV EAX,dword ptr [ESI + 0xd8]
    s.ax = m.r32((s.si+0x000000d8u));
  }
  L00485bab: { // 0x485bab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485bac: { // 0x485bac: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485baf: { // 0x485baf: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00485bb1: { // 0x485bb1: 83e106 AND ECX,0x6
    s.cx = integer::logical((s.cx)&(0x00000006u),32,flags);
  }
  L00485bb4: { // 0x485bb4: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00485bb7: { // 0x485bb7: 0f84b2010000 JZ 0x00485d6f
    if(integer::condition("JZ",flags)) goto L00485d6f;
  }
  L00485bbd: { // 0x485bbd: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00485bc0: { // 0x485bc0: 0f8434010000 JZ 0x00485cfa
    if(integer::condition("JZ",flags)) goto L00485cfa;
  }
  L00485bc6: { // 0x485bc6: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00485bc9: { // 0x485bc9: 0f84b6000000 JZ 0x00485c85
    if(integer::condition("JZ",flags)) goto L00485c85;
  }
  L00485bcf: { // 0x485bcf: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00485bd1: { // 0x485bd1: 742b JZ 0x00485bfe
    if(integer::condition("JZ",flags)) goto L00485bfe;
  }
  L00485bd3: { // 0x485bd3: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485bd6: { // 0x485bd6: 740a JZ 0x00485be2
    if(integer::condition("JZ",flags)) goto L00485be2;
  }
  L00485bd8: { // 0x485bd8: 8b8614010000 MOV EAX,dword ptr [ESI + 0x114]
    s.ax = m.r32((s.si+0x00000114u));
  }
  L00485bde: { // 0x485bde: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485bdf: { // 0x485bdf: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485be2: { // 0x485be2: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485be8: { // 0x485be8: 740a JZ 0x00485bf4
    if(integer::condition("JZ",flags)) goto L00485bf4;
  }
  L00485bea: { // 0x485bea: 8b86f0000000 MOV EAX,dword ptr [ESI + 0xf0]
    s.ax = m.r32((s.si+0x000000f0u));
  }
  L00485bf0: { // 0x485bf0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485bf1: { // 0x485bf1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485bf4: { // 0x485bf4: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  L00485bfa: { // 0x485bfa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485bfb: { // 0x485bfb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485bfe: { // 0x485bfe: a820 TEST AL,0x20
    (void)integer::logical(((s.ax & 0xffu))&(0x00000020u),8,flags);
  }
  L00485c00: { // 0x485c00: 742b JZ 0x00485c2d
    if(integer::condition("JZ",flags)) goto L00485c2d;
  }
  L00485c02: { // 0x485c02: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485c05: { // 0x485c05: 740f JZ 0x00485c16
    if(integer::condition("JZ",flags)) goto L00485c16;
  }
  L00485c07: { // 0x485c07: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c0a: { // 0x485c0a: 7435 JZ 0x00485c41
    if(integer::condition("JZ",flags)) goto L00485c41;
  }
  L00485c0c: { // 0x485c0c: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    s.ax = m.r32((s.si+0x00000158u));
  }
  L00485c12: { // 0x485c12: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c13: { // 0x485c13: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c16: { // 0x485c16: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485c1c: { // 0x485c1c: 744e JZ 0x00485c6c
    if(integer::condition("JZ",flags)) goto L00485c6c;
  }
  L00485c1e: { // 0x485c1e: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c21: { // 0x485c21: 743f JZ 0x00485c62
    if(integer::condition("JZ",flags)) goto L00485c62;
  }
  L00485c23: { // 0x485c23: 8b8638010000 MOV EAX,dword ptr [ESI + 0x138]
    s.ax = m.r32((s.si+0x00000138u));
  }
  L00485c29: { // 0x485c29: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c2a: { // 0x485c2a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c2d: { // 0x485c2d: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485c30: { // 0x485c30: 7419 JZ 0x00485c4b
    if(integer::condition("JZ",flags)) goto L00485c4b;
  }
  L00485c32: { // 0x485c32: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c35: { // 0x485c35: 740a JZ 0x00485c41
    if(integer::condition("JZ",flags)) goto L00485c41;
  }
  L00485c37: { // 0x485c37: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    s.ax = m.r32((s.si+0x00000158u));
  }
  L00485c3d: { // 0x485c3d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c3e: { // 0x485c3e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c41: { // 0x485c41: 8b860c010000 MOV EAX,dword ptr [ESI + 0x10c]
    s.ax = m.r32((s.si+0x0000010cu));
  }
  L00485c47: { // 0x485c47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c48: { // 0x485c48: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c4b: { // 0x485c4b: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485c51: { // 0x485c51: 7419 JZ 0x00485c6c
    if(integer::condition("JZ",flags)) goto L00485c6c;
  }
  L00485c53: { // 0x485c53: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c56: { // 0x485c56: 740a JZ 0x00485c62
    if(integer::condition("JZ",flags)) goto L00485c62;
  }
  L00485c58: { // 0x485c58: 8b8638010000 MOV EAX,dword ptr [ESI + 0x138]
    s.ax = m.r32((s.si+0x00000138u));
  }
  L00485c5e: { // 0x485c5e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c5f: { // 0x485c5f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c62: { // 0x485c62: 8b86e8000000 MOV EAX,dword ptr [ESI + 0xe8]
    s.ax = m.r32((s.si+0x000000e8u));
  }
  L00485c68: { // 0x485c68: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c69: { // 0x485c69: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c6c: { // 0x485c6c: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c6f: { // 0x485c6f: 740a JZ 0x00485c7b
    if(integer::condition("JZ",flags)) goto L00485c7b;
  }
  L00485c71: { // 0x485c71: 8b8624010000 MOV EAX,dword ptr [ESI + 0x124]
    s.ax = m.r32((s.si+0x00000124u));
  }
  L00485c77: { // 0x485c77: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c78: { // 0x485c78: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c7b: { // 0x485c7b: 8b86d0000000 MOV EAX,dword ptr [ESI + 0xd0]
    s.ax = m.r32((s.si+0x000000d0u));
  }
  L00485c81: { // 0x485c81: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c82: { // 0x485c82: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c85: { // 0x485c85: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485c88: { // 0x485c88: 7419 JZ 0x00485ca3
    if(integer::condition("JZ",flags)) goto L00485ca3;
  }
  L00485c8a: { // 0x485c8a: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c8d: { // 0x485c8d: 740a JZ 0x00485c99
    if(integer::condition("JZ",flags)) goto L00485c99;
  }
  L00485c8f: { // 0x485c8f: 8b8660010000 MOV EAX,dword ptr [ESI + 0x160]
    s.ax = m.r32((s.si+0x00000160u));
  }
  L00485c95: { // 0x485c95: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c96: { // 0x485c96: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c99: { // 0x485c99: 8b8618010000 MOV EAX,dword ptr [ESI + 0x118]
    s.ax = m.r32((s.si+0x00000118u));
  }
  L00485c9f: { // 0x485c9f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ca0: { // 0x485ca0: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ca3: { // 0x485ca3: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485ca9: { // 0x485ca9: 7436 JZ 0x00485ce1
    if(integer::condition("JZ",flags)) goto L00485ce1;
  }
  L00485cab: { // 0x485cab: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485cad: { // 0x485cad: 7419 JZ 0x00485cc8
    if(integer::condition("JZ",flags)) goto L00485cc8;
  }
  L00485caf: { // 0x485caf: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485cb2: { // 0x485cb2: 740a JZ 0x00485cbe
    if(integer::condition("JZ",flags)) goto L00485cbe;
  }
  L00485cb4: { // 0x485cb4: 8b864c010000 MOV EAX,dword ptr [ESI + 0x14c]
    s.ax = m.r32((s.si+0x0000014cu));
  }
  L00485cba: { // 0x485cba: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485cbb: { // 0x485cbb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cbe: { // 0x485cbe: 8b8600010000 MOV EAX,dword ptr [ESI + 0x100]
    s.ax = m.r32((s.si+0x00000100u));
  }
  L00485cc4: { // 0x485cc4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485cc5: { // 0x485cc5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cc8: { // 0x485cc8: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485ccb: { // 0x485ccb: 740a JZ 0x00485cd7
    if(integer::condition("JZ",flags)) goto L00485cd7;
  }
  L00485ccd: { // 0x485ccd: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L00485cd3: { // 0x485cd3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485cd4: { // 0x485cd4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cd7: { // 0x485cd7: 8b86f4000000 MOV EAX,dword ptr [ESI + 0xf4]
    s.ax = m.r32((s.si+0x000000f4u));
  }
  L00485cdd: { // 0x485cdd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485cde: { // 0x485cde: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ce1: { // 0x485ce1: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485ce4: { // 0x485ce4: 740a JZ 0x00485cf0
    if(integer::condition("JZ",flags)) goto L00485cf0;
  }
  L00485ce6: { // 0x485ce6: 8b862c010000 MOV EAX,dword ptr [ESI + 0x12c]
    s.ax = m.r32((s.si+0x0000012cu));
  }
  L00485cec: { // 0x485cec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ced: { // 0x485ced: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cf0: { // 0x485cf0: 8b86dc000000 MOV EAX,dword ptr [ESI + 0xdc]
    s.ax = m.r32((s.si+0x000000dcu));
  }
  L00485cf6: { // 0x485cf6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485cf7: { // 0x485cf7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cfa: { // 0x485cfa: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485cfd: { // 0x485cfd: 7419 JZ 0x00485d18
    if(integer::condition("JZ",flags)) goto L00485d18;
  }
  L00485cff: { // 0x485cff: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d02: { // 0x485d02: 740a JZ 0x00485d0e
    if(integer::condition("JZ",flags)) goto L00485d0e;
  }
  L00485d04: { // 0x485d04: 8b8664010000 MOV EAX,dword ptr [ESI + 0x164]
    s.ax = m.r32((s.si+0x00000164u));
  }
  L00485d0a: { // 0x485d0a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d0b: { // 0x485d0b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d0e: { // 0x485d0e: 8b861c010000 MOV EAX,dword ptr [ESI + 0x11c]
    s.ax = m.r32((s.si+0x0000011cu));
  }
  L00485d14: { // 0x485d14: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d15: { // 0x485d15: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d18: { // 0x485d18: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485d1e: { // 0x485d1e: 7436 JZ 0x00485d56
    if(integer::condition("JZ",flags)) goto L00485d56;
  }
  L00485d20: { // 0x485d20: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d22: { // 0x485d22: 7419 JZ 0x00485d3d
    if(integer::condition("JZ",flags)) goto L00485d3d;
  }
  L00485d24: { // 0x485d24: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d27: { // 0x485d27: 740a JZ 0x00485d33
    if(integer::condition("JZ",flags)) goto L00485d33;
  }
  L00485d29: { // 0x485d29: 8b8650010000 MOV EAX,dword ptr [ESI + 0x150]
    s.ax = m.r32((s.si+0x00000150u));
  }
  L00485d2f: { // 0x485d2f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d30: { // 0x485d30: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d33: { // 0x485d33: 8b8604010000 MOV EAX,dword ptr [ESI + 0x104]
    s.ax = m.r32((s.si+0x00000104u));
  }
  L00485d39: { // 0x485d39: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d3a: { // 0x485d3a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d3d: { // 0x485d3d: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d40: { // 0x485d40: 740a JZ 0x00485d4c
    if(integer::condition("JZ",flags)) goto L00485d4c;
  }
  L00485d42: { // 0x485d42: 8b8644010000 MOV EAX,dword ptr [ESI + 0x144]
    s.ax = m.r32((s.si+0x00000144u));
  }
  L00485d48: { // 0x485d48: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d49: { // 0x485d49: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d4c: { // 0x485d4c: 8b86f8000000 MOV EAX,dword ptr [ESI + 0xf8]
    s.ax = m.r32((s.si+0x000000f8u));
  }
  L00485d52: { // 0x485d52: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d53: { // 0x485d53: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d56: { // 0x485d56: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d59: { // 0x485d59: 740a JZ 0x00485d65
    if(integer::condition("JZ",flags)) goto L00485d65;
  }
  L00485d5b: { // 0x485d5b: 8b8630010000 MOV EAX,dword ptr [ESI + 0x130]
    s.ax = m.r32((s.si+0x00000130u));
  }
  L00485d61: { // 0x485d61: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d62: { // 0x485d62: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d65: { // 0x485d65: 8b86e0000000 MOV EAX,dword ptr [ESI + 0xe0]
    s.ax = m.r32((s.si+0x000000e0u));
  }
  L00485d6b: { // 0x485d6b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d6c: { // 0x485d6c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d6f: { // 0x485d6f: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485d72: { // 0x485d72: 7419 JZ 0x00485d8d
    if(integer::condition("JZ",flags)) goto L00485d8d;
  }
  L00485d74: { // 0x485d74: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d77: { // 0x485d77: 740a JZ 0x00485d83
    if(integer::condition("JZ",flags)) goto L00485d83;
  }
  L00485d79: { // 0x485d79: 8b8668010000 MOV EAX,dword ptr [ESI + 0x168]
    s.ax = m.r32((s.si+0x00000168u));
  }
  L00485d7f: { // 0x485d7f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d80: { // 0x485d80: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d83: { // 0x485d83: 8b8620010000 MOV EAX,dword ptr [ESI + 0x120]
    s.ax = m.r32((s.si+0x00000120u));
  }
  L00485d89: { // 0x485d89: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d8a: { // 0x485d8a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d8d: { // 0x485d8d: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485d93: { // 0x485d93: 7436 JZ 0x00485dcb
    if(integer::condition("JZ",flags)) goto L00485dcb;
  }
  L00485d95: { // 0x485d95: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d97: { // 0x485d97: 7419 JZ 0x00485db2
    if(integer::condition("JZ",flags)) goto L00485db2;
  }
  L00485d99: { // 0x485d99: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d9c: { // 0x485d9c: 740a JZ 0x00485da8
    if(integer::condition("JZ",flags)) goto L00485da8;
  }
  L00485d9e: { // 0x485d9e: 8b8654010000 MOV EAX,dword ptr [ESI + 0x154]
    s.ax = m.r32((s.si+0x00000154u));
  }
  L00485da4: { // 0x485da4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485da5: { // 0x485da5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485da8: { // 0x485da8: 8b8608010000 MOV EAX,dword ptr [ESI + 0x108]
    s.ax = m.r32((s.si+0x00000108u));
  }
  L00485dae: { // 0x485dae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485daf: { // 0x485daf: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485db2: { // 0x485db2: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485db5: { // 0x485db5: 740a JZ 0x00485dc1
    if(integer::condition("JZ",flags)) goto L00485dc1;
  }
  L00485db7: { // 0x485db7: 8b8648010000 MOV EAX,dword ptr [ESI + 0x148]
    s.ax = m.r32((s.si+0x00000148u));
  }
  L00485dbd: { // 0x485dbd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485dbe: { // 0x485dbe: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485dc1: { // 0x485dc1: 8b86fc000000 MOV EAX,dword ptr [ESI + 0xfc]
    s.ax = m.r32((s.si+0x000000fcu));
  }
  L00485dc7: { // 0x485dc7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485dc8: { // 0x485dc8: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485dcb: { // 0x485dcb: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485dce: { // 0x485dce: 740a JZ 0x00485dda
    if(integer::condition("JZ",flags)) goto L00485dda;
  }
  L00485dd0: { // 0x485dd0: 8b8634010000 MOV EAX,dword ptr [ESI + 0x134]
    s.ax = m.r32((s.si+0x00000134u));
  }
  L00485dd6: { // 0x485dd6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485dd7: { // 0x485dd7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485dda: { // 0x485dda: 8b86e4000000 MOV EAX,dword ptr [ESI + 0xe4]
    s.ax = m.r32((s.si+0x000000e4u));
  }
  L00485de0: { // 0x485de0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485de1: { // 0x485de1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
}
namespace selectors511 {
using namespace floating_b61;

template<class Function>
std::uint32_t run_selector(Memory& original, const Inputs& i, Function function) {
 std::array<std::uint8_t,0x8000> stack{};
 constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));
 Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};
 m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);
 function(m,s,f,op);
 for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);
 return s.ax;
}

std::uint32_t select_85b40(Memory& m,const Inputs& i) {
 return run_selector(m,i,[](Memory& mm,State& s,Frame& f,const Operations& op){f_00085b40(mm,s,f,op);});
}
}
}
