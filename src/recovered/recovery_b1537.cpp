#include "recovered/recovery_b1537_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1537 {
namespace {
void f_002ba8a0(Memory&,State&,Frame&,const Operations&);
void f_002cdb10(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_0001b600(Memory&,State&,Frame&,const Operations&);
void f_002d4bf0(Memory&,State&,Frame&,const Operations&);
void f_002cdab0(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void f_00307fe0(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_000713b0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_002ba8a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006ba8a0: { // 0x6ba8a0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006ba8a1: { // 0x6ba8a1: 8bec MOV EBP, ESP
    s.bp = f.sp;
  }
  L006ba8a3: { // 0x6ba8a3: 83e4f8 AND ESP, 0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L006ba8a6: { // 0x6ba8a6: 83ec34 SUB ESP, 0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L006ba8a9: { // 0x6ba8a9: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006ba8ab: { // 0x6ba8ab: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006ba8ac: { // 0x6ba8ac: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006ba8ad: { // 0x6ba8ad: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006ba8ae: { // 0x6ba8ae: 894c240c MOV dword ptr [ESP + 0xc], ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L006ba8b2: { // 0x6ba8b2: ff9098030000 CALL dword ptr [EAX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000398u)),7055544u); flags=s.arithmetic_flags;
  }
  L006ba8b8: { // 0x6ba8b8: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006ba8ba: { // 0x6ba8ba: 0f84ca020000 JZ 0x6bab8a
    if(integer::condition("JZ",flags)) goto L006bab8a;
  }
  L006ba8c0: { // 0x6ba8c0: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006ba8c2: { // 0x6ba8c2: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006ba8c4: { // 0x6ba8c4: 0f84c0020000 JZ 0x6bab8a
    if(integer::condition("JZ",flags)) goto L006bab8a;
  }
  L006ba8ca: { // 0x6ba8ca: 8a881e010000 MOV CL, byte ptr [EAX + 0x11e]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000011eu)));
  }
  L006ba8d0: { // 0x6ba8d0: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006ba8d2: { // 0x6ba8d2: 0f84b2020000 JZ 0x6bab8a
    if(integer::condition("JZ",flags)) goto L006bab8a;
  }
  L006ba8d8: { // 0x6ba8d8: 8b0d881b8200 MOV ECX, dword ptr [0x821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L006ba8de: { // 0x6ba8de: be01000000 MOV ESI, 1
    s.si = 1u;
  }
  L006ba8e3: { // 0x6ba8e3: c744243800000000 MOV dword ptr [ESP + 0x38], 0
    m.w32((f.sp+0x00000038u), 0u);
  }
  L006ba8eb: { // 0x6ba8eb: c744243c0000f03f MOV dword ptr [ESP + 0x3c], 0x3ff00000
    m.w32((f.sp+0x0000003cu), 0x3ff00000u);
  }
  L006ba8f3: { // 0x6ba8f3: 8b8198100000 MOV EAX, dword ptr [ECX + 0x1098]
    s.ax = m.r32((s.cx+0x00001098u));
  }
  L006ba8f9: { // 0x6ba8f9: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006ba8fa: { // 0x6ba8fa: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006ba900: { // 0x6ba900: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006ba902: { // 0x6ba902: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L006ba905: { // 0x6ba905: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L006ba907: { // 0x6ba907: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L006ba90b: { // 0x6ba90b: 0f8e6c020000 JLE 0x6bab7d
    if(integer::condition("JLE",flags)) goto L006bab7d;
  }
  L006ba911: { // 0x6ba911: 83c9ff OR ECX, 0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L006ba914: { // 0x6ba914: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L006ba918: { // 0x6ba918: 3bce CMP ECX, ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L006ba91a: { // 0x6ba91a: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L006ba91c: { // 0x6ba91c: 0f8f21010000 JG 0x6baa43
    if(integer::condition("JG",flags)) goto L006baa43;
  }
  L006ba922: { // 0x6ba922: 8b5508 MOV EDX, dword ptr [EBP + 8]
    s.dx = m.r32((s.bp+8u));
  }
  L006ba925: { // 0x6ba925: 668b0a MOV CX, word ptr [EDX]
    s.cx = with_ax(s.cx, m.r16((s.dx)));
  }
  L006ba928: { // 0x6ba928: 8b1540a98100 MOV EDX, dword ptr [0x81a940]
    s.dx = m.r32((0x0081a940u));
  }
  L006ba92e: { // 0x6ba92e: 0fbfc1 MOVSX EAX, CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L006ba931: { // 0x6ba931: 03c7 ADD EAX, EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L006ba933: { // 0x6ba933: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L006ba935: { // 0x6ba935: 0f8cf7000000 JL 0x6baa32
    if(integer::condition("JL",flags)) goto L006baa32;
  }
  L006ba93b: { // 0x6ba93b: 8b1d48a98100 MOV EBX, dword ptr [0x81a948]
    s.bx = m.r32((0x0081a948u));
  }
  L006ba941: { // 0x6ba941: 03da ADD EBX, EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L006ba943: { // 0x6ba943: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006ba945: { // 0x6ba945: 0f8de7000000 JGE 0x6baa32
    if(integer::condition("JGE",flags)) goto L006baa32;
  }
  L006ba94b: { // 0x6ba94b: 8b5d08 MOV EBX, dword ptr [EBP + 8]
    s.bx = m.r32((s.bp+8u));
  }
  L006ba94e: { // 0x6ba94e: 668b4302 MOV AX, word ptr [EBX + 2]
    s.ax = with_ax(s.ax, m.r16((s.bx+2u)));
  }
  L006ba952: { // 0x6ba952: 0fbfd0 MOVSX EDX, AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L006ba955: { // 0x6ba955: 2bd6 SUB EDX, ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L006ba957: { // 0x6ba957: 3b1544a98100 CMP EDX, dword ptr [0x81a944]
    (void)integer::sub(s.dx,m.r32((0x0081a944u)),32,flags);
  }
  L006ba95d: { // 0x6ba95d: 7c5f JL 0x6ba9be
    if(integer::condition("JL",flags)) goto L006ba9be;
  }
  L006ba95f: { // 0x6ba95f: 8bd6 MOV EDX, ESI
    s.dx = s.si;
  }
  L006ba961: { // 0x6ba961: 03cf ADD ECX, EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L006ba963: { // 0x6ba963: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L006ba965: { // 0x6ba965: 6689542432 MOV word ptr [ESP + 0x32], DX
    m.w16((f.sp+0x00000032u), (s.dx & 0xffffu));
  }
  L006ba96a: { // 0x6ba96a: 66894c2418 MOV word ptr [ESP + 0x18], CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L006ba96f: { // 0x6ba96f: 8b4c2432 MOV ECX, dword ptr [ESP + 0x32]
    s.cx = m.r32((f.sp+0x00000032u));
  }
  L006ba973: { // 0x6ba973: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006ba975: { // 0x6ba975: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L006ba97a: { // 0x6ba97a: 668944241a MOV word ptr [ESP + 0x1a], AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L006ba97f: { // 0x6ba97f: 8b542418 MOV EDX, dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L006ba983: { // 0x6ba983: 8d442410 LEA EAX, [ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L006ba987: { // 0x6ba987: 89542410 MOV dword ptr [ESP + 0x10], EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L006ba98b: { // 0x6ba98b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006ba98c: { // 0x6ba98c: e86fabe8ff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7055761u); flags=s.arithmetic_flags;
  }
  L006ba991: { // 0x6ba991: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006ba993: { // 0x6ba993: e8186adbff CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,7055768u); flags=s.arithmetic_flags;
  }
  L006ba998: { // 0x6ba998: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006ba99a: { // 0x6ba99a: 7422 JZ 0x6ba9be
    if(integer::condition("JZ",flags)) goto L006ba9be;
  }
  L006ba99c: { // 0x6ba99c: 8b4c240c MOV ECX, dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L006ba9a0: { // 0x6ba9a0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006ba9a1: { // 0x6ba9a1: 8b89b4010000 MOV ECX, dword ptr [ECX + 0x1b4]
    s.cx = m.r32((s.cx+0x000001b4u));
  }
  L006ba9a7: { // 0x6ba9a7: e874a2e2ff CALL 0x4e4c20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4c20u,7055788u); flags=s.arithmetic_flags;
  }
  L006ba9ac: { // 0x6ba9ac: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ba9ae: { // 0x6ba9ae: 740e JZ 0x6ba9be
    if(integer::condition("JZ",flags)) goto L006ba9be;
  }
  L006ba9b0: { // 0x6ba9b0: dd442438 FLD qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L006ba9b4: { // 0x6ba9b4: dc0d28577800 FMUL qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L006ba9ba: { // 0x6ba9ba: dd5c2438 FSTP qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006ba9be: { // 0x6ba9be: 668b4302 MOV AX, word ptr [EBX + 2]
    s.ax = with_ax(s.ax, m.r16((s.bx+2u)));
  }
  L006ba9c2: { // 0x6ba9c2: 8b0d4ca98100 MOV ECX, dword ptr [0x81a94c]
    s.cx = m.r32((0x0081a94cu));
  }
  L006ba9c8: { // 0x6ba9c8: 8b1d44a98100 MOV EBX, dword ptr [0x81a944]
    s.bx = m.r32((0x0081a944u));
  }
  L006ba9ce: { // 0x6ba9ce: 0fbfd0 MOVSX EDX, AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L006ba9d1: { // 0x6ba9d1: 03d6 ADD EDX, ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L006ba9d3: { // 0x6ba9d3: 03cb ADD ECX, EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L006ba9d5: { // 0x6ba9d5: 3bd1 CMP EDX, ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L006ba9d7: { // 0x6ba9d7: 7d59 JGE 0x6baa32
    if(integer::condition("JGE",flags)) goto L006baa32;
  }
  L006ba9d9: { // 0x6ba9d9: 8b5508 MOV EDX, dword ptr [EBP + 8]
    s.dx = m.r32((s.bp+8u));
  }
  L006ba9dc: { // 0x6ba9dc: 03c6 ADD EAX, ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L006ba9de: { // 0x6ba9de: 668944241e MOV word ptr [ESP + 0x1e], AX
    m.w16((f.sp+0x0000001eu), (s.ax & 0xffffu));
  }
  L006ba9e3: { // 0x6ba9e3: 8d442410 LEA EAX, [ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L006ba9e7: { // 0x6ba9e7: 668b0a MOV CX, word ptr [EDX]
    s.cx = with_ax(s.cx, m.r16((s.dx)));
  }
  L006ba9ea: { // 0x6ba9ea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006ba9eb: { // 0x6ba9eb: 6603cf ADD CX, DI
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  L006ba9ee: { // 0x6ba9ee: 66894c2420 MOV word ptr [ESP + 0x20], CX
    m.w16((f.sp+0x00000020u), (s.cx & 0xffffu));
  }
  L006ba9f3: { // 0x6ba9f3: 8b542420 MOV EDX, dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L006ba9f7: { // 0x6ba9f7: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L006ba9fc: { // 0x6ba9fc: 89542414 MOV dword ptr [ESP + 0x14], EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L006baa00: { // 0x6baa00: e8fbaae8ff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7055877u); flags=s.arithmetic_flags;
  }
  L006baa05: { // 0x6baa05: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006baa07: { // 0x6baa07: e8a469dbff CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,7055884u); flags=s.arithmetic_flags;
  }
  L006baa0c: { // 0x6baa0c: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006baa0e: { // 0x6baa0e: 7422 JZ 0x6baa32
    if(integer::condition("JZ",flags)) goto L006baa32;
  }
  L006baa10: { // 0x6baa10: 8b4c240c MOV ECX, dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L006baa14: { // 0x6baa14: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006baa15: { // 0x6baa15: 8b89b4010000 MOV ECX, dword ptr [ECX + 0x1b4]
    s.cx = m.r32((s.cx+0x000001b4u));
  }
  L006baa1b: { // 0x6baa1b: e800a2e2ff CALL 0x4e4c20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4c20u,7055904u); flags=s.arithmetic_flags;
  }
  L006baa20: { // 0x6baa20: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006baa22: { // 0x6baa22: 740e JZ 0x6baa32
    if(integer::condition("JZ",flags)) goto L006baa32;
  }
  L006baa24: { // 0x6baa24: dd442438 FLD qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L006baa28: { // 0x6baa28: dc0d28577800 FMUL qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L006baa2e: { // 0x6baa2e: dd5c2438 FSTP qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006baa32: { // 0x6baa32: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L006baa33: { // 0x6baa33: 3bfe CMP EDI, ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L006baa35: { // 0x6baa35: 0f8ee7feffff JLE 0x6ba922
    if(integer::condition("JLE",flags)) goto L006ba922;
  }
  L006baa3b: { // 0x6baa3b: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L006baa3f: { // 0x6baa3f: 8b442428 MOV EAX, dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L006baa43: { // 0x6baa43: 8d7901 LEA EDI, [ECX + 1]
    s.di = (s.cx+1u);
  }
  L006baa46: { // 0x6baa46: 3bfe CMP EDI, ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L006baa48: { // 0x6baa48: 0f8d21010000 JGE 0x6bab6f
    if(integer::condition("JGE",flags)) goto L006bab6f;
  }
  L006baa4e: { // 0x6baa4e: 8b5508 MOV EDX, dword ptr [EBP + 8]
    s.dx = m.r32((s.bp+8u));
  }
  L006baa51: { // 0x6baa51: 668b4a02 MOV CX, word ptr [EDX + 2]
    s.cx = with_ax(s.cx, m.r16((s.dx+2u)));
  }
  L006baa55: { // 0x6baa55: 8b1544a98100 MOV EDX, dword ptr [0x81a944]
    s.dx = m.r32((0x0081a944u));
  }
  L006baa5b: { // 0x6baa5b: 0fbfc1 MOVSX EAX, CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L006baa5e: { // 0x6baa5e: 03c7 ADD EAX, EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L006baa60: { // 0x6baa60: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L006baa62: { // 0x6baa62: 0f8cf6000000 JL 0x6bab5e
    if(integer::condition("JL",flags)) goto L006bab5e;
  }
  L006baa68: { // 0x6baa68: 8b1d4ca98100 MOV EBX, dword ptr [0x81a94c]
    s.bx = m.r32((0x0081a94cu));
  }
  L006baa6e: { // 0x6baa6e: 03da ADD EBX, EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L006baa70: { // 0x6baa70: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006baa72: { // 0x6baa72: 0f8de6000000 JGE 0x6bab5e
    if(integer::condition("JGE",flags)) goto L006bab5e;
  }
  L006baa78: { // 0x6baa78: 8b5d08 MOV EBX, dword ptr [EBP + 8]
    s.bx = m.r32((s.bp+8u));
  }
  L006baa7b: { // 0x6baa7b: 668b03 MOV AX, word ptr [EBX]
    s.ax = with_ax(s.ax, m.r16((s.bx)));
  }
  L006baa7e: { // 0x6baa7e: 0fbfd0 MOVSX EDX, AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L006baa81: { // 0x6baa81: 2bd6 SUB EDX, ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L006baa83: { // 0x6baa83: 3b1540a98100 CMP EDX, dword ptr [0x81a940]
    (void)integer::sub(s.dx,m.r32((0x0081a940u)),32,flags);
  }
  L006baa89: { // 0x6baa89: 7c5f JL 0x6baaea
    if(integer::condition("JL",flags)) goto L006baaea;
  }
  L006baa8b: { // 0x6baa8b: 8bd6 MOV EDX, ESI
    s.dx = s.si;
  }
  L006baa8d: { // 0x6baa8d: 03cf ADD ECX, EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L006baa8f: { // 0x6baa8f: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L006baa91: { // 0x6baa91: 668954242c MOV word ptr [ESP + 0x2c], DX
    m.w16((f.sp+0x0000002cu), (s.dx & 0xffffu));
  }
  L006baa96: { // 0x6baa96: 8b54242c MOV EDX, dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L006baa9a: { // 0x6baa9a: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006baa9c: { // 0x6baa9c: 66894c2422 MOV word ptr [ESP + 0x22], CX
    m.w16((f.sp+0x00000022u), (s.cx & 0xffffu));
  }
  L006baaa1: { // 0x6baaa1: 8d4c2410 LEA ECX, [ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L006baaa5: { // 0x6baaa5: 6689442420 MOV word ptr [ESP + 0x20], AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  L006baaaa: { // 0x6baaaa: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L006baaae: { // 0x6baaae: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006baaaf: { // 0x6baaaf: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L006baab4: { // 0x6baab4: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006baab8: { // 0x6baab8: e843aae8ff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7056061u); flags=s.arithmetic_flags;
  }
  L006baabd: { // 0x6baabd: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006baabf: { // 0x6baabf: e8ec68dbff CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,7056068u); flags=s.arithmetic_flags;
  }
  L006baac4: { // 0x6baac4: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006baac6: { // 0x6baac6: 7422 JZ 0x6baaea
    if(integer::condition("JZ",flags)) goto L006baaea;
  }
  L006baac8: { // 0x6baac8: 8b54240c MOV EDX, dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L006baacc: { // 0x6baacc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006baacd: { // 0x6baacd: 8b8ab4010000 MOV ECX, dword ptr [EDX + 0x1b4]
    s.cx = m.r32((s.dx+0x000001b4u));
  }
  L006baad3: { // 0x6baad3: e848a1e2ff CALL 0x4e4c20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4c20u,7056088u); flags=s.arithmetic_flags;
  }
  L006baad8: { // 0x6baad8: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006baada: { // 0x6baada: 740e JZ 0x6baaea
    if(integer::condition("JZ",flags)) goto L006baaea;
  }
  L006baadc: { // 0x6baadc: dd442438 FLD qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L006baae0: { // 0x6baae0: dc0d28577800 FMUL qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L006baae6: { // 0x6baae6: dd5c2438 FSTP qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006baaea: { // 0x6baaea: 668b03 MOV AX, word ptr [EBX]
    s.ax = with_ax(s.ax, m.r16((s.bx)));
  }
  L006baaed: { // 0x6baaed: 8b1548a98100 MOV EDX, dword ptr [0x81a948]
    s.dx = m.r32((0x0081a948u));
  }
  L006baaf3: { // 0x6baaf3: 8b1d40a98100 MOV EBX, dword ptr [0x81a940]
    s.bx = m.r32((0x0081a940u));
  }
  L006baaf9: { // 0x6baaf9: 0fbfc8 MOVSX ECX, AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L006baafc: { // 0x6baafc: 03ce ADD ECX, ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L006baafe: { // 0x6baafe: 03d3 ADD EDX, EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L006bab00: { // 0x6bab00: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L006bab02: { // 0x6bab02: 7d5a JGE 0x6bab5e
    if(integer::condition("JGE",flags)) goto L006bab5e;
  }
  L006bab04: { // 0x6bab04: 8b4d08 MOV ECX, dword ptr [EBP + 8]
    s.cx = m.r32((s.bp+8u));
  }
  L006bab07: { // 0x6bab07: 03c6 ADD EAX, ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L006bab09: { // 0x6bab09: 6689442424 MOV word ptr [ESP + 0x24], AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L006bab0e: { // 0x6bab0e: 668bc7 MOV AX, DI
    s.ax = with_ax(s.ax, (s.di & 0xffffu));
  }
  L006bab11: { // 0x6bab11: 66034102 ADD AX, word ptr [ECX + 2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.cx+2u)),16,flags));
  }
  L006bab15: { // 0x6bab15: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L006bab1a: { // 0x6bab1a: 6689442426 MOV word ptr [ESP + 0x26], AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L006bab1f: { // 0x6bab1f: 8b542424 MOV EDX, dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L006bab23: { // 0x6bab23: 8d442410 LEA EAX, [ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L006bab27: { // 0x6bab27: 89542410 MOV dword ptr [ESP + 0x10], EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L006bab2b: { // 0x6bab2b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006bab2c: { // 0x6bab2c: e8cfa9e8ff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7056177u); flags=s.arithmetic_flags;
  }
  L006bab31: { // 0x6bab31: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006bab33: { // 0x6bab33: e87868dbff CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,7056184u); flags=s.arithmetic_flags;
  }
  L006bab38: { // 0x6bab38: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006bab3a: { // 0x6bab3a: 7422 JZ 0x6bab5e
    if(integer::condition("JZ",flags)) goto L006bab5e;
  }
  L006bab3c: { // 0x6bab3c: 8b4c240c MOV ECX, dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L006bab40: { // 0x6bab40: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006bab41: { // 0x6bab41: 8b89b4010000 MOV ECX, dword ptr [ECX + 0x1b4]
    s.cx = m.r32((s.cx+0x000001b4u));
  }
  L006bab47: { // 0x6bab47: e8d4a0e2ff CALL 0x4e4c20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4c20u,7056204u); flags=s.arithmetic_flags;
  }
  L006bab4c: { // 0x6bab4c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bab4e: { // 0x6bab4e: 740e JZ 0x6bab5e
    if(integer::condition("JZ",flags)) goto L006bab5e;
  }
  L006bab50: { // 0x6bab50: dd442438 FLD qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L006bab54: { // 0x6bab54: dc0d28577800 FMUL qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L006bab5a: { // 0x6bab5a: dd5c2438 FSTP qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006bab5e: { // 0x6bab5e: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L006bab5f: { // 0x6bab5f: 3bfe CMP EDI, ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L006bab61: { // 0x6bab61: 0f8ce7feffff JL 0x6baa4e
    if(integer::condition("JL",flags)) goto L006baa4e;
  }
  L006bab67: { // 0x6bab67: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L006bab6b: { // 0x6bab6b: 8b442428 MOV EAX, dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L006bab6f: { // 0x6bab6f: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L006bab70: { // 0x6bab70: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L006bab71: { // 0x6bab71: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L006bab73: { // 0x6bab73: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L006bab77: { // 0x6bab77: 0f8c9bfdffff JL 0x6ba918
    if(integer::condition("JL",flags)) goto L006ba918;
  }
  L006bab7d: { // 0x6bab7d: dd442438 FLD qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L006bab81: { // 0x6bab81: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006bab82: { // 0x6bab82: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006bab83: { // 0x6bab83: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006bab84: { // 0x6bab84: 8be5 MOV ESP, EBP
    f.sp = s.bp;
  }
  L006bab86: { // 0x6bab86: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006bab87: { // 0x6bab87: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006bab8a: { // 0x6bab8a: dd0508577800 FLD qword ptr [0x785708]
    const auto address=(0x00785708u);
    s.fp.load64(read64(m,address));
  }
  L006bab90: { // 0x6bab90: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006bab91: { // 0x6bab91: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006bab92: { // 0x6bab92: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006bab93: { // 0x6bab93: 8be5 MOV ESP, EBP
    f.sp = s.bp;
  }
  L006bab95: { // 0x6bab95: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006bab96: { // 0x6bab96: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002cdb10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cdb10: { // 0x6cdb10: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cdb11: { // 0x6cdb11: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L006cdb13: { // 0x6cdb13: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cdb15: { // 0x6cdb15: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7133979u); flags=s.arithmetic_flags;
  }
  L006cdb1b: { // 0x6cdb1b: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006cdb1d: { // 0x6cdb1d: e8ce700000 CALL 0x6d4bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4bf0u,7133986u); flags=s.arithmetic_flags;
  }
  L006cdb22: { // 0x6cdb22: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cdb24: { // 0x6cdb24: 7413 JZ 0x6cdb39
    if(integer::condition("JZ",flags)) goto L006cdb39;
  }
  L006cdb26: { // 0x6cdb26: 8b860c010000 MOV EAX, dword ptr [ESI + 0x10c]
    s.ax = m.r32((s.si+0x0000010cu));
  }
  L006cdb2c: { // 0x6cdb2c: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cdb2e: { // 0x6cdb2e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cdb2f: { // 0x6cdb2f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdb31: { // 0x6cdb31: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7134007u); flags=s.arithmetic_flags;
  }
  L006cdb37: { // 0x6cdb37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdb38: { // 0x6cdb38: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006cdb39: { // 0x6cdb39: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cdb3b: { // 0x6cdb3b: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cdb3d: { // 0x6cdb3d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cdb3e: { // 0x6cdb3e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdb40: { // 0x6cdb40: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7134022u); flags=s.arithmetic_flags;
  }
  L006cdb46: { // 0x6cdb46: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdb47: { // 0x6cdb47: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: { // 0x6b6912: ffa084000000 JMP dword ptr [EAX + 0x84]
    switch(m.r32((s.ax+0x00000084u))){
    case 0x006b6910u: goto L006b6910;
    case 0x006b6912u: goto L006b6912;
    default:s.arithmetic_flags=flags; tail(m,s,f,m.r32((s.ax+0x00000084u))); return;}
  }
}
void f_0001b600(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b600: { // 0x41b600: 8b81ac050000 MOV EAX, dword ptr [ECX + 0x5ac]
    s.ax = m.r32((s.cx+0x000005acu));
  }
  L0041b606: { // 0x41b606: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002d4bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4bf0: { // 0x6d4bf0: 8b9104070000 MOV EDX, dword ptr [ECX + 0x704]
    s.dx = m.r32((s.cx+0x00000704u));
  }
  L006d4bf6: { // 0x6d4bf6: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006d4bf8: { // 0x6d4bf8: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006d4bfa: { // 0x6d4bfa: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L006d4bfd: { // 0x6d4bfd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002cdab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cdab0: { // 0x6cdab0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cdab1: { // 0x6cdab1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdab2: { // 0x6cdab2: 8b7c240c MOV EDI, dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L006cdab6: { // 0x6cdab6: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L006cdab8: { // 0x6cdab8: 83ffff CMP EDI, -1
    (void)integer::sub(s.di,4294967295u,32,flags);
  }
  L006cdabb: { // 0x6cdabb: 7507 JNZ 0x6cdac4
    if(integer::condition("JNZ",flags)) goto L006cdac4;
  }
  L006cdabd: { // 0x6cdabd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cdabe: { // 0x6cdabe: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cdac0: { // 0x6cdac0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdac1: { // 0x6cdac1: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006cdac4: { // 0x6cdac4: 8d8e18010000 LEA ECX, [ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  L006cdaca: { // 0x6cdaca: e811a50300 CALL 0x707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7133903u); flags=s.arithmetic_flags;
  }
  L006cdacf: { // 0x6cdacf: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cdad1: { // 0x6cdad1: 741b JZ 0x6cdaee
    if(integer::condition("JZ",flags)) goto L006cdaee;
  }
  L006cdad3: { // 0x6cdad3: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cdad5: { // 0x6cdad5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdad6: { // 0x6cdad6: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdad8: { // 0x6cdad8: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7133918u); flags=s.arithmetic_flags;
  }
  L006cdade: { // 0x6cdade: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006cdae0: { // 0x6cdae0: e86b700000 CALL 0x6d4b50
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b50u,7133925u); flags=s.arithmetic_flags;
  }
  L006cdae5: { // 0x6cdae5: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006cdae7: { // 0x6cdae7: 7405 JZ 0x6cdaee
    if(integer::condition("JZ",flags)) goto L006cdaee;
  }
  L006cdae9: { // 0x6cdae9: 833800 CMP dword ptr [EAX], 0
    (void)integer::sub(m.r32((s.ax)),0u,32,flags);
  }
  L006cdaec: { // 0x6cdaec: 7512 JNZ 0x6cdb00
    if(integer::condition("JNZ",flags)) goto L006cdb00;
  }
  L006cdaee: { // 0x6cdaee: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cdaf0: { // 0x6cdaf0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdaf1: { // 0x6cdaf1: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdaf3: { // 0x6cdaf3: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7133945u); flags=s.arithmetic_flags;
  }
  L006cdaf9: { // 0x6cdaf9: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006cdafb: { // 0x6cdafb: e830700000 CALL 0x6d4b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b30u,7133952u); flags=s.arithmetic_flags;
  }
  L006cdb00: { // 0x6cdb00: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cdb01: { // 0x6cdb01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdb02: { // 0x6cdb02: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d4b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4b30: { // 0x6d4b30: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L006d4b34: { // 0x6d4b34: 8d14c500000000 LEA EDX, [EAX*8]
    s.dx = ((s.ax * 8u));
  }
  L006d4b3b: { // 0x6d4b3b: 2bd0 SUB EDX, EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006d4b3d: { // 0x6d4b3d: 8d84914c070000 LEA EAX, [ECX + EDX*4 + 0x74c]
    s.ax = (s.cx+(s.dx * 4u)+0x0000074cu);
  }
  L006d4b44: { // 0x6d4b44: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00307fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00707fe0: { // 0x707fe0: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707fe2: { // 0x707fe2: dc1df8567800 FCOMP qword ptr [0x7856f8]
    const auto address=(0x007856f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707fe8: { // 0x707fe8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707fea: { // 0x707fea: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00707fed: { // 0x707fed: 7506 JNZ 0x707ff5
    if(integer::condition("JNZ",flags)) goto L00707ff5;
  }
  L00707fef: { // 0x707fef: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L00707ff4: { // 0x707ff4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707ff5: { // 0x707ff5: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00707ff7: { // 0x707ff7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX, dword ptr [ESP + 4]
    s.dx = m.r32((f.sp+4u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX, word ptr [EDX + 2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+2u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI, word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX, 9
    s.ax = integer::shift(s.ax,9u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX, ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX, 0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX, dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX, dword ptr [ECX + EAX*4]
    s.ax = m.r32((s.cx+(s.ax * 4u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX, dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX, 0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000713b0(Memory& m,State& s,Frame& f,const Operations& op) { if(m.r8(0xa285a8u)!=1u||m.r32(s.cx+0xe4u)!=0u)throw std::domain_error("B1537 actualenabledempty713B0");
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004713b0: { // 0x4713b0: a0a885a200 MOV AL, byte ptr [0xa285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L004713b5: { // 0x4713b5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004713b6: { // 0x4713b6: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004713b8: { // 0x4713b8: 741d JZ 0x4713d7
    if(integer::condition("JZ",flags)) goto L004713d7;
  }
  L004713ba: { // 0x4713ba: 8bb1e4000000 MOV ESI, dword ptr [ECX + 0xe4]
    s.si = m.r32((s.cx+0x000000e4u));
  }
  L004713c0: { // 0x4713c0: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004713c2: { // 0x4713c2: 7413 JZ 0x4713d7
    if(integer::condition("JZ",flags)) goto L004713d7;
  }
  L004713c4: { // 0x4713c4: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004713c6: { // 0x4713c6: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004713c8: { // 0x4713c8: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4658123u); flags=s.arithmetic_flags;
  }
  L004713cb: { // 0x4713cb: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L004713ce: { // 0x4713ce: 740b JZ 0x4713db
    if(integer::condition("JZ",flags)) goto L004713db;
  }
  L004713d0: { // 0x4713d0: 8b7630 MOV ESI, dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L004713d3: { // 0x4713d3: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004713d5: { // 0x4713d5: 75ed JNZ 0x4713c4
    if(integer::condition("JNZ",flags)) goto L004713c4;
  }
  L004713d7: { // 0x4713d7: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004713d9: { // 0x4713d9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004713da: { // 0x4713da: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004713db: { // 0x4713db: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L004713dd: { // 0x4713dd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004713de: { // 0x4713de: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7055520u:f_002ba8a0(m,s,child,{});break;
case 7133968u:f_002cdb10(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 4306432u:f_0001b600(m,s,child,{});break;
case 7162864u:f_002d4bf0(m,s,child,{});break;
case 7133872u:f_002cdab0(m,s,child,{});break;
case 7162672u:f_002d4b30(m,s,child,{});break;
case 7372768u:f_00307fe0(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4658096u:f_000713b0(m,s,child,{});break;
default:throw std::domain_error("recovery1537 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ if(target!=0x41b600u)throw std::domain_error("B1537 unknown tail");f_0001b600(m,s,f,{}); } }

std::uint32_t fun_006ba8a0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006ba8a0: { // 0x6ba8a0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006ba8a1: { // 0x6ba8a1: 8bec MOV EBP, ESP
    s.bp = f.sp;
  }
  L006ba8a3: { // 0x6ba8a3: 83e4f8 AND ESP, 0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L006ba8a6: { // 0x6ba8a6: 83ec34 SUB ESP, 0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L006ba8a9: { // 0x6ba8a9: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006ba8ab: { // 0x6ba8ab: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006ba8ac: { // 0x6ba8ac: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006ba8ad: { // 0x6ba8ad: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006ba8ae: { // 0x6ba8ae: 894c240c MOV dword ptr [ESP + 0xc], ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L006ba8b2: { // 0x6ba8b2: ff9098030000 CALL dword ptr [EAX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000398u)),7055544u); flags=s.arithmetic_flags;
  }
  L006ba8b8: { // 0x6ba8b8: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006ba8ba: { // 0x6ba8ba: 0f84ca020000 JZ 0x6bab8a
    if(integer::condition("JZ",flags)) goto L006bab8a;
  }
  L006ba8c0: { // 0x6ba8c0: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006ba8c2: { // 0x6ba8c2: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006ba8c4: { // 0x6ba8c4: 0f84c0020000 JZ 0x6bab8a
    if(integer::condition("JZ",flags)) goto L006bab8a;
  }
  L006ba8ca: { // 0x6ba8ca: 8a881e010000 MOV CL, byte ptr [EAX + 0x11e]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000011eu)));
  }
  L006ba8d0: { // 0x6ba8d0: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006ba8d2: { // 0x6ba8d2: 0f84b2020000 JZ 0x6bab8a
    if(integer::condition("JZ",flags)) goto L006bab8a;
  }
  L006ba8d8: { // 0x6ba8d8: 8b0d881b8200 MOV ECX, dword ptr [0x821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L006ba8de: { // 0x6ba8de: be01000000 MOV ESI, 1
    s.si = 1u;
  }
  L006ba8e3: { // 0x6ba8e3: c744243800000000 MOV dword ptr [ESP + 0x38], 0
    m.w32((f.sp+0x00000038u), 0u);
  }
  L006ba8eb: { // 0x6ba8eb: c744243c0000f03f MOV dword ptr [ESP + 0x3c], 0x3ff00000
    m.w32((f.sp+0x0000003cu), 0x3ff00000u);
  }
  L006ba8f3: { // 0x6ba8f3: 8b8198100000 MOV EAX, dword ptr [ECX + 0x1098]
    s.ax = m.r32((s.cx+0x00001098u));
  }
  L006ba8f9: { // 0x6ba8f9: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006ba8fa: { // 0x6ba8fa: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006ba900: { // 0x6ba900: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006ba902: { // 0x6ba902: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L006ba905: { // 0x6ba905: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L006ba907: { // 0x6ba907: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L006ba90b: { // 0x6ba90b: 0f8e6c020000 JLE 0x6bab7d
    if(integer::condition("JLE",flags)) goto L006bab7d;
  }
  L006ba911: { // 0x6ba911: 83c9ff OR ECX, 0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L006ba914: { // 0x6ba914: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L006ba918: { // 0x6ba918: 3bce CMP ECX, ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L006ba91a: { // 0x6ba91a: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L006ba91c: { // 0x6ba91c: 0f8f21010000 JG 0x6baa43
    if(integer::condition("JG",flags)) goto L006baa43;
  }
  L006ba922: { // 0x6ba922: 8b5508 MOV EDX, dword ptr [EBP + 8]
    s.dx = m.r32((s.bp+8u));
  }
  L006ba925: { // 0x6ba925: 668b0a MOV CX, word ptr [EDX]
    s.cx = with_ax(s.cx, m.r16((s.dx)));
  }
  L006ba928: { // 0x6ba928: 8b1540a98100 MOV EDX, dword ptr [0x81a940]
    s.dx = m.r32((0x0081a940u));
  }
  L006ba92e: { // 0x6ba92e: 0fbfc1 MOVSX EAX, CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L006ba931: { // 0x6ba931: 03c7 ADD EAX, EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L006ba933: { // 0x6ba933: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L006ba935: { // 0x6ba935: 0f8cf7000000 JL 0x6baa32
    if(integer::condition("JL",flags)) goto L006baa32;
  }
  L006ba93b: { // 0x6ba93b: 8b1d48a98100 MOV EBX, dword ptr [0x81a948]
    s.bx = m.r32((0x0081a948u));
  }
  L006ba941: { // 0x6ba941: 03da ADD EBX, EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L006ba943: { // 0x6ba943: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006ba945: { // 0x6ba945: 0f8de7000000 JGE 0x6baa32
    if(integer::condition("JGE",flags)) goto L006baa32;
  }
  L006ba94b: { // 0x6ba94b: 8b5d08 MOV EBX, dword ptr [EBP + 8]
    s.bx = m.r32((s.bp+8u));
  }
  L006ba94e: { // 0x6ba94e: 668b4302 MOV AX, word ptr [EBX + 2]
    s.ax = with_ax(s.ax, m.r16((s.bx+2u)));
  }
  L006ba952: { // 0x6ba952: 0fbfd0 MOVSX EDX, AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L006ba955: { // 0x6ba955: 2bd6 SUB EDX, ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L006ba957: { // 0x6ba957: 3b1544a98100 CMP EDX, dword ptr [0x81a944]
    (void)integer::sub(s.dx,m.r32((0x0081a944u)),32,flags);
  }
  L006ba95d: { // 0x6ba95d: 7c5f JL 0x6ba9be
    if(integer::condition("JL",flags)) goto L006ba9be;
  }
  L006ba95f: { // 0x6ba95f: 8bd6 MOV EDX, ESI
    s.dx = s.si;
  }
  L006ba961: { // 0x6ba961: 03cf ADD ECX, EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L006ba963: { // 0x6ba963: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L006ba965: { // 0x6ba965: 6689542432 MOV word ptr [ESP + 0x32], DX
    m.w16((f.sp+0x00000032u), (s.dx & 0xffffu));
  }
  L006ba96a: { // 0x6ba96a: 66894c2418 MOV word ptr [ESP + 0x18], CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L006ba96f: { // 0x6ba96f: 8b4c2432 MOV ECX, dword ptr [ESP + 0x32]
    s.cx = m.r32((f.sp+0x00000032u));
  }
  L006ba973: { // 0x6ba973: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006ba975: { // 0x6ba975: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L006ba97a: { // 0x6ba97a: 668944241a MOV word ptr [ESP + 0x1a], AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L006ba97f: { // 0x6ba97f: 8b542418 MOV EDX, dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L006ba983: { // 0x6ba983: 8d442410 LEA EAX, [ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L006ba987: { // 0x6ba987: 89542410 MOV dword ptr [ESP + 0x10], EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L006ba98b: { // 0x6ba98b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006ba98c: { // 0x6ba98c: e86fabe8ff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7055761u); flags=s.arithmetic_flags;
  }
  L006ba991: { // 0x6ba991: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006ba993: { // 0x6ba993: e8186adbff CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,7055768u); flags=s.arithmetic_flags;
  }
  L006ba998: { // 0x6ba998: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006ba99a: { // 0x6ba99a: 7422 JZ 0x6ba9be
    if(integer::condition("JZ",flags)) goto L006ba9be;
  }
  L006ba99c: { // 0x6ba99c: 8b4c240c MOV ECX, dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L006ba9a0: { // 0x6ba9a0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006ba9a1: { // 0x6ba9a1: 8b89b4010000 MOV ECX, dword ptr [ECX + 0x1b4]
    s.cx = m.r32((s.cx+0x000001b4u));
  }
  L006ba9a7: { // 0x6ba9a7: e874a2e2ff CALL 0x4e4c20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4c20u,7055788u); flags=s.arithmetic_flags;
  }
  L006ba9ac: { // 0x6ba9ac: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ba9ae: { // 0x6ba9ae: 740e JZ 0x6ba9be
    if(integer::condition("JZ",flags)) goto L006ba9be;
  }
  L006ba9b0: { // 0x6ba9b0: dd442438 FLD qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L006ba9b4: { // 0x6ba9b4: dc0d28577800 FMUL qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L006ba9ba: { // 0x6ba9ba: dd5c2438 FSTP qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006ba9be: { // 0x6ba9be: 668b4302 MOV AX, word ptr [EBX + 2]
    s.ax = with_ax(s.ax, m.r16((s.bx+2u)));
  }
  L006ba9c2: { // 0x6ba9c2: 8b0d4ca98100 MOV ECX, dword ptr [0x81a94c]
    s.cx = m.r32((0x0081a94cu));
  }
  L006ba9c8: { // 0x6ba9c8: 8b1d44a98100 MOV EBX, dword ptr [0x81a944]
    s.bx = m.r32((0x0081a944u));
  }
  L006ba9ce: { // 0x6ba9ce: 0fbfd0 MOVSX EDX, AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L006ba9d1: { // 0x6ba9d1: 03d6 ADD EDX, ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L006ba9d3: { // 0x6ba9d3: 03cb ADD ECX, EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L006ba9d5: { // 0x6ba9d5: 3bd1 CMP EDX, ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L006ba9d7: { // 0x6ba9d7: 7d59 JGE 0x6baa32
    if(integer::condition("JGE",flags)) goto L006baa32;
  }
  L006ba9d9: { // 0x6ba9d9: 8b5508 MOV EDX, dword ptr [EBP + 8]
    s.dx = m.r32((s.bp+8u));
  }
  L006ba9dc: { // 0x6ba9dc: 03c6 ADD EAX, ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L006ba9de: { // 0x6ba9de: 668944241e MOV word ptr [ESP + 0x1e], AX
    m.w16((f.sp+0x0000001eu), (s.ax & 0xffffu));
  }
  L006ba9e3: { // 0x6ba9e3: 8d442410 LEA EAX, [ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L006ba9e7: { // 0x6ba9e7: 668b0a MOV CX, word ptr [EDX]
    s.cx = with_ax(s.cx, m.r16((s.dx)));
  }
  L006ba9ea: { // 0x6ba9ea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006ba9eb: { // 0x6ba9eb: 6603cf ADD CX, DI
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.di & 0xffffu),16,flags));
  }
  L006ba9ee: { // 0x6ba9ee: 66894c2420 MOV word ptr [ESP + 0x20], CX
    m.w16((f.sp+0x00000020u), (s.cx & 0xffffu));
  }
  L006ba9f3: { // 0x6ba9f3: 8b542420 MOV EDX, dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L006ba9f7: { // 0x6ba9f7: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L006ba9fc: { // 0x6ba9fc: 89542414 MOV dword ptr [ESP + 0x14], EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L006baa00: { // 0x6baa00: e8fbaae8ff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7055877u); flags=s.arithmetic_flags;
  }
  L006baa05: { // 0x6baa05: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006baa07: { // 0x6baa07: e8a469dbff CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,7055884u); flags=s.arithmetic_flags;
  }
  L006baa0c: { // 0x6baa0c: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006baa0e: { // 0x6baa0e: 7422 JZ 0x6baa32
    if(integer::condition("JZ",flags)) goto L006baa32;
  }
  L006baa10: { // 0x6baa10: 8b4c240c MOV ECX, dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L006baa14: { // 0x6baa14: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006baa15: { // 0x6baa15: 8b89b4010000 MOV ECX, dword ptr [ECX + 0x1b4]
    s.cx = m.r32((s.cx+0x000001b4u));
  }
  L006baa1b: { // 0x6baa1b: e800a2e2ff CALL 0x4e4c20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4c20u,7055904u); flags=s.arithmetic_flags;
  }
  L006baa20: { // 0x6baa20: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006baa22: { // 0x6baa22: 740e JZ 0x6baa32
    if(integer::condition("JZ",flags)) goto L006baa32;
  }
  L006baa24: { // 0x6baa24: dd442438 FLD qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L006baa28: { // 0x6baa28: dc0d28577800 FMUL qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L006baa2e: { // 0x6baa2e: dd5c2438 FSTP qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006baa32: { // 0x6baa32: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L006baa33: { // 0x6baa33: 3bfe CMP EDI, ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L006baa35: { // 0x6baa35: 0f8ee7feffff JLE 0x6ba922
    if(integer::condition("JLE",flags)) goto L006ba922;
  }
  L006baa3b: { // 0x6baa3b: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L006baa3f: { // 0x6baa3f: 8b442428 MOV EAX, dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L006baa43: { // 0x6baa43: 8d7901 LEA EDI, [ECX + 1]
    s.di = (s.cx+1u);
  }
  L006baa46: { // 0x6baa46: 3bfe CMP EDI, ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L006baa48: { // 0x6baa48: 0f8d21010000 JGE 0x6bab6f
    if(integer::condition("JGE",flags)) goto L006bab6f;
  }
  L006baa4e: { // 0x6baa4e: 8b5508 MOV EDX, dword ptr [EBP + 8]
    s.dx = m.r32((s.bp+8u));
  }
  L006baa51: { // 0x6baa51: 668b4a02 MOV CX, word ptr [EDX + 2]
    s.cx = with_ax(s.cx, m.r16((s.dx+2u)));
  }
  L006baa55: { // 0x6baa55: 8b1544a98100 MOV EDX, dword ptr [0x81a944]
    s.dx = m.r32((0x0081a944u));
  }
  L006baa5b: { // 0x6baa5b: 0fbfc1 MOVSX EAX, CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L006baa5e: { // 0x6baa5e: 03c7 ADD EAX, EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L006baa60: { // 0x6baa60: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L006baa62: { // 0x6baa62: 0f8cf6000000 JL 0x6bab5e
    if(integer::condition("JL",flags)) goto L006bab5e;
  }
  L006baa68: { // 0x6baa68: 8b1d4ca98100 MOV EBX, dword ptr [0x81a94c]
    s.bx = m.r32((0x0081a94cu));
  }
  L006baa6e: { // 0x6baa6e: 03da ADD EBX, EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L006baa70: { // 0x6baa70: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006baa72: { // 0x6baa72: 0f8de6000000 JGE 0x6bab5e
    if(integer::condition("JGE",flags)) goto L006bab5e;
  }
  L006baa78: { // 0x6baa78: 8b5d08 MOV EBX, dword ptr [EBP + 8]
    s.bx = m.r32((s.bp+8u));
  }
  L006baa7b: { // 0x6baa7b: 668b03 MOV AX, word ptr [EBX]
    s.ax = with_ax(s.ax, m.r16((s.bx)));
  }
  L006baa7e: { // 0x6baa7e: 0fbfd0 MOVSX EDX, AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L006baa81: { // 0x6baa81: 2bd6 SUB EDX, ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L006baa83: { // 0x6baa83: 3b1540a98100 CMP EDX, dword ptr [0x81a940]
    (void)integer::sub(s.dx,m.r32((0x0081a940u)),32,flags);
  }
  L006baa89: { // 0x6baa89: 7c5f JL 0x6baaea
    if(integer::condition("JL",flags)) goto L006baaea;
  }
  L006baa8b: { // 0x6baa8b: 8bd6 MOV EDX, ESI
    s.dx = s.si;
  }
  L006baa8d: { // 0x6baa8d: 03cf ADD ECX, EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L006baa8f: { // 0x6baa8f: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L006baa91: { // 0x6baa91: 668954242c MOV word ptr [ESP + 0x2c], DX
    m.w16((f.sp+0x0000002cu), (s.dx & 0xffffu));
  }
  L006baa96: { // 0x6baa96: 8b54242c MOV EDX, dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L006baa9a: { // 0x6baa9a: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006baa9c: { // 0x6baa9c: 66894c2422 MOV word ptr [ESP + 0x22], CX
    m.w16((f.sp+0x00000022u), (s.cx & 0xffffu));
  }
  L006baaa1: { // 0x6baaa1: 8d4c2410 LEA ECX, [ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L006baaa5: { // 0x6baaa5: 6689442420 MOV word ptr [ESP + 0x20], AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  L006baaaa: { // 0x6baaaa: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L006baaae: { // 0x6baaae: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006baaaf: { // 0x6baaaf: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L006baab4: { // 0x6baab4: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006baab8: { // 0x6baab8: e843aae8ff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7056061u); flags=s.arithmetic_flags;
  }
  L006baabd: { // 0x6baabd: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006baabf: { // 0x6baabf: e8ec68dbff CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,7056068u); flags=s.arithmetic_flags;
  }
  L006baac4: { // 0x6baac4: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006baac6: { // 0x6baac6: 7422 JZ 0x6baaea
    if(integer::condition("JZ",flags)) goto L006baaea;
  }
  L006baac8: { // 0x6baac8: 8b54240c MOV EDX, dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L006baacc: { // 0x6baacc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006baacd: { // 0x6baacd: 8b8ab4010000 MOV ECX, dword ptr [EDX + 0x1b4]
    s.cx = m.r32((s.dx+0x000001b4u));
  }
  L006baad3: { // 0x6baad3: e848a1e2ff CALL 0x4e4c20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4c20u,7056088u); flags=s.arithmetic_flags;
  }
  L006baad8: { // 0x6baad8: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006baada: { // 0x6baada: 740e JZ 0x6baaea
    if(integer::condition("JZ",flags)) goto L006baaea;
  }
  L006baadc: { // 0x6baadc: dd442438 FLD qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L006baae0: { // 0x6baae0: dc0d28577800 FMUL qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L006baae6: { // 0x6baae6: dd5c2438 FSTP qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006baaea: { // 0x6baaea: 668b03 MOV AX, word ptr [EBX]
    s.ax = with_ax(s.ax, m.r16((s.bx)));
  }
  L006baaed: { // 0x6baaed: 8b1548a98100 MOV EDX, dword ptr [0x81a948]
    s.dx = m.r32((0x0081a948u));
  }
  L006baaf3: { // 0x6baaf3: 8b1d40a98100 MOV EBX, dword ptr [0x81a940]
    s.bx = m.r32((0x0081a940u));
  }
  L006baaf9: { // 0x6baaf9: 0fbfc8 MOVSX ECX, AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L006baafc: { // 0x6baafc: 03ce ADD ECX, ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L006baafe: { // 0x6baafe: 03d3 ADD EDX, EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L006bab00: { // 0x6bab00: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L006bab02: { // 0x6bab02: 7d5a JGE 0x6bab5e
    if(integer::condition("JGE",flags)) goto L006bab5e;
  }
  L006bab04: { // 0x6bab04: 8b4d08 MOV ECX, dword ptr [EBP + 8]
    s.cx = m.r32((s.bp+8u));
  }
  L006bab07: { // 0x6bab07: 03c6 ADD EAX, ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L006bab09: { // 0x6bab09: 6689442424 MOV word ptr [ESP + 0x24], AX
    m.w16((f.sp+0x00000024u), (s.ax & 0xffffu));
  }
  L006bab0e: { // 0x6bab0e: 668bc7 MOV AX, DI
    s.ax = with_ax(s.ax, (s.di & 0xffffu));
  }
  L006bab11: { // 0x6bab11: 66034102 ADD AX, word ptr [ECX + 2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.cx+2u)),16,flags));
  }
  L006bab15: { // 0x6bab15: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L006bab1a: { // 0x6bab1a: 6689442426 MOV word ptr [ESP + 0x26], AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L006bab1f: { // 0x6bab1f: 8b542424 MOV EDX, dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L006bab23: { // 0x6bab23: 8d442410 LEA EAX, [ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L006bab27: { // 0x6bab27: 89542410 MOV dword ptr [ESP + 0x10], EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L006bab2b: { // 0x6bab2b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006bab2c: { // 0x6bab2c: e8cfa9e8ff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7056177u); flags=s.arithmetic_flags;
  }
  L006bab31: { // 0x6bab31: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006bab33: { // 0x6bab33: e87868dbff CALL 0x4713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,7056184u); flags=s.arithmetic_flags;
  }
  L006bab38: { // 0x6bab38: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006bab3a: { // 0x6bab3a: 7422 JZ 0x6bab5e
    if(integer::condition("JZ",flags)) goto L006bab5e;
  }
  L006bab3c: { // 0x6bab3c: 8b4c240c MOV ECX, dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L006bab40: { // 0x6bab40: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006bab41: { // 0x6bab41: 8b89b4010000 MOV ECX, dword ptr [ECX + 0x1b4]
    s.cx = m.r32((s.cx+0x000001b4u));
  }
  L006bab47: { // 0x6bab47: e8d4a0e2ff CALL 0x4e4c20
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4c20u,7056204u); flags=s.arithmetic_flags;
  }
  L006bab4c: { // 0x6bab4c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bab4e: { // 0x6bab4e: 740e JZ 0x6bab5e
    if(integer::condition("JZ",flags)) goto L006bab5e;
  }
  L006bab50: { // 0x6bab50: dd442438 FLD qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L006bab54: { // 0x6bab54: dc0d28577800 FMUL qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L006bab5a: { // 0x6bab5a: dd5c2438 FSTP qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006bab5e: { // 0x6bab5e: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L006bab5f: { // 0x6bab5f: 3bfe CMP EDI, ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L006bab61: { // 0x6bab61: 0f8ce7feffff JL 0x6baa4e
    if(integer::condition("JL",flags)) goto L006baa4e;
  }
  L006bab67: { // 0x6bab67: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L006bab6b: { // 0x6bab6b: 8b442428 MOV EAX, dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L006bab6f: { // 0x6bab6f: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L006bab70: { // 0x6bab70: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L006bab71: { // 0x6bab71: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L006bab73: { // 0x6bab73: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L006bab77: { // 0x6bab77: 0f8c9bfdffff JL 0x6ba918
    if(integer::condition("JL",flags)) goto L006ba918;
  }
  L006bab7d: { // 0x6bab7d: dd442438 FLD qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L006bab81: { // 0x6bab81: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006bab82: { // 0x6bab82: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006bab83: { // 0x6bab83: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006bab84: { // 0x6bab84: 8be5 MOV ESP, EBP
    f.sp = s.bp;
  }
  L006bab86: { // 0x6bab86: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006bab87: { // 0x6bab87: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006bab8a: { // 0x6bab8a: dd0508577800 FLD qword ptr [0x785708]
    const auto address=(0x00785708u);
    s.fp.load64(read64(m,address));
  }
  L006bab90: { // 0x6bab90: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006bab91: { // 0x6bab91: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006bab92: { // 0x6bab92: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006bab93: { // 0x6bab93: 8be5 MOV ESP, EBP
    f.sp = s.bp;
  }
  L006bab95: { // 0x6bab95: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006bab96: { // 0x6bab96: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
