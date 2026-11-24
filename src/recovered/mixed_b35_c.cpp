#include "recovered/mixed_b35_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::mixed_b35 {
namespace {
void f_0025a170(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x65a170: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x65a174: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x65a177: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x65a178: 8d8c8132060000 LEA ECX,[ECX + EAX*0x4 + 0x632]
    s.cx = (s.cx+(s.ax * 0x00000004u)+0x00000632u);
  }
  { // 0x65a17f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x65a180: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x65a181: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x65a186: e875b3eeff CALL 0x00545500
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x65a18b: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x65a18d: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  { // 0x65a191: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x65a192: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x65a194: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x65a196: ff5248 CALL dword ptr [EDX + 0x48]
    const std::uint32_t call_target=m.r32((s.dx+0x00000048u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x65a199: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x65a19b: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  { // 0x65a19e: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  { // 0x65a1a1: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  { // 0x65a1a7: f6c405 TEST AH,0x5
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000005u),8,flags);
  }
  { // 0x65a1aa: 7406 JZ 0x0065a1b2
    if(integer::condition("JZ",flags)) goto L0065a1b2;
  }
  { // 0x65a1ac: 030de8e9a900 ADD ECX,dword ptr [0x00a9e9e8]
    s.cx = integer::add(s.cx,m.r32((0x00a9e9e8u)),32,flags);
  }
  L0065a1b2: { // 0x65a1b2: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x65a1b6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x65a1b8: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  { // 0x65a1ba: 897e04 MOV dword ptr [ESI + 0x4],EDI
    m.w32((s.si+0x00000004u), s.di);
  }
  { // 0x65a1bd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x65a1be: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  { // 0x65a1c1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65a1c2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x65a1c5: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0025a540(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x65a540: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x65a541: 8b6c2408 MOV EBP,dword ptr [ESP + 0x8]
    s.bp = m.r32((f.sp+0x00000008u));
  }
  { // 0x65a545: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x65a546: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x65a548: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x65a54a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x65a54b: 7467 JZ 0x0065a5b4
    if(integer::condition("JZ",flags)) goto L0065a5b4;
  }
  { // 0x65a54d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x65a54f: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x65a552: 8b7d08 MOV EDI,dword ptr [EBP + 0x8]
    s.di = m.r32((s.bp+0x00000008u));
  }
  { // 0x65a555: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x65a557: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  { // 0x65a55a: 744d JZ 0x0065a5a9
    if(integer::condition("JZ",flags)) goto L0065a5a9;
  }
  { // 0x65a55c: 8d0cbd00000000 LEA ECX,[EDI*0x4 + 0x0]
    s.cx = ((s.di * 0x00000004u)+0x00000000u);
  }
  { // 0x65a563: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x65a564: e8ee331100 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x65a569: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x65a56c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65a56e: 7407 JZ 0x0065a577
    if(integer::condition("JZ",flags)) goto L0065a577;
  }
  { // 0x65a570: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x65a571: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  { // 0x65a575: eb02 JMP 0x0065a579
    goto L0065a579;
  }
  L0065a577: { // 0x65a577: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0065a579: { // 0x65a579: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65a57b: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x65a57e: 7434 JZ 0x0065a5b4
    if(integer::condition("JZ",flags)) goto L0065a5b4;
  }
  { // 0x65a580: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x65a583: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x65a585: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x65a587: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x65a58b: 7e27 JLE 0x0065a5b4
    if(integer::condition("JLE",flags)) goto L0065a5b4;
  }
  L0065a58d: { // 0x65a58d: 8b5504 MOV EDX,dword ptr [EBP + 0x4]
    s.dx = m.r32((s.bp+0x00000004u));
  }
  { // 0x65a590: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x65a593: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x65a596: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  { // 0x65a599: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x65a59c: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x65a59d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x65a59f: 7cec JL 0x0065a58d
    if(integer::condition("JL",flags)) goto L0065a58d;
  }
  { // 0x65a5a1: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x65a5a3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x65a5a4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65a5a5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x65a5a6: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0065a5a9: { // 0x65a5a9: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x65a5b0: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L0065a5b4: { // 0x65a5b4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x65a5b6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x65a5b7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65a5b8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x65a5b9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0025aaf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x65aaf0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x65aaf1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x65aaf3: 8b8e0c030000 MOV ECX,dword ptr [ESI + 0x30c]
    s.cx = m.r32((s.si+0x0000030cu));
  }
  { // 0x65aaf9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x65aafb: 7410 JZ 0x0065ab0d
    if(integer::condition("JZ",flags)) goto L0065ab0d;
  }
  { // 0x65aafd: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x65aaff: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x65ab01: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x65ab03: c7860c03000000000000 MOV dword ptr [ESI + 0x30c],0x0
    m.w32((s.si+0x0000030cu), 0x00000000u);
  }
  L0065ab0d: { // 0x65ab0d: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x65ab11: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x65ab15: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x65ab19: 6838c27d00 PUSH 0x7dc238
    f.push(m,0x007dc238u);
  }
  { // 0x65ab1e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x65ab1f: 8b8e10030000 MOV ECX,dword ptr [ESI + 0x310]
    s.cx = m.r32((s.si+0x00000310u));
  }
  { // 0x65ab25: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x65ab26: 8b15901c8200 MOV EDX,dword ptr [0x00821c90]
    s.dx = m.r32((0x00821c90u));
  }
  { // 0x65ab2c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x65ab2d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x65ab2e: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  { // 0x65ab32: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  { // 0x65ab35: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x65ab36: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  { // 0x65ab3a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x65ab3b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x65ab3c: 8d8e08030000 LEA ECX,[ESI + 0x308]
    s.cx = (s.si+0x00000308u);
  }
  { // 0x65ab42: e8f9faffff CALL 0x0065a640
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x65ab47: 89860c030000 MOV dword ptr [ESI + 0x30c],EAX
    m.w32((s.si+0x0000030cu), s.ax);
  }
  { // 0x65ab4d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65ab4e: c21400 RET 0x14
    finish(m,s,f,20u); return;
  }
}
void f_00261b50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x661b50: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x661b51: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x661b53: 8a86284f0000 MOV AL,byte ptr [ESI + 0x4f28]
    s.ax = with_al(s.ax, m.r8((s.si+0x00004f28u)));
  }
  { // 0x661b59: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x661b5b: 741b JZ 0x00661b78
    if(integer::condition("JZ",flags)) goto L00661b78;
  }
  { // 0x661b5d: 8a0d4cf78100 MOV CL,byte ptr [0x0081f74c]
    s.cx = with_al(s.cx, m.r8((0x0081f74cu)));
  }
  { // 0x661b63: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x661b65: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x661b66: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x661b68: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x661b6a: ff5048 CALL dword ptr [EAX + 0x48]
    const std::uint32_t call_target=m.r32((s.ax+0x00000048u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x661b6d: c686284f000000 MOV byte ptr [ESI + 0x4f28],0x0
    m.w8((s.si+0x00004f28u), 0x00000000u);
  }
  { // 0x661b74: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x661b75: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00661b78: { // 0x661b78: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x661b7c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x661b7e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x661b7f: e8ec91e3ff CALL 0x0049ad70
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x661b84: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x661b85: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00261bd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x661bd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x661bd1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x661bd3: e848cde3ff CALL 0x0049e920
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x661bd8: c6862a4f000000 MOV byte ptr [ESI + 0x4f2a],0x0
    m.w8((s.si+0x00004f2au), 0x00000000u);
  }
  { // 0x661bdf: ff15ec537800 CALL dword ptr [0x007853ec]
    const std::uint32_t call_target=m.r32((0x007853ecu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x661be5: 8b0d50deb000 MOV ECX,dword ptr [0x00b0de50]
    s.cx = m.r32((0x00b0de50u));
  }
  { // 0x661beb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x661bec: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x661bee: 7506 JNZ 0x00661bf6
    if(integer::condition("JNZ",flags)) goto L00661bf6;
  }
  { // 0x661bf0: ff15e8537800 CALL dword ptr [0x007853e8]
    const std::uint32_t call_target=m.r32((0x007853e8u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00661bf6: { // 0x661bf6: 6858c87d00 PUSH 0x7dc858
    f.push(m,0x007dc858u);
  }
  { // 0x661bfb: e8f04cdaff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x661c00: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x661c01: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00264660(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x664660: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x664661: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x664662: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x664663: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x664665: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x664666: 8b3d9c547800 MOV EDI,dword ptr [0x0078549c]
    s.di = m.r32((0x0078549cu));
  }
  { // 0x66466c: 8b9e94000000 MOV EBX,dword ptr [ESI + 0x94]
    s.bx = m.r32((s.si+0x00000094u));
  }
  { // 0x664672: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x664674: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x664676: 685c060000 PUSH 0x65c
    f.push(m,0x0000065cu);
  }
  { // 0x66467b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x66467c: 0f94c3 SETZ BL
    s.bx = with_al(s.bx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x66467f: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x664681: 8b2da0547800 MOV EBP,dword ptr [0x007854a0]
    s.bp = m.r32((0x007854a0u));
  }
  { // 0x664687: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x664689: 7413 JZ 0x0066469e
    if(integer::condition("JZ",flags)) goto L0066469e;
  }
  { // 0x66468b: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x66468d: 80fb01 CMP BL,0x1
    (void)integer::sub((s.bx & 0xffu),0x00000001u,8,flags);
  }
  { // 0x664690: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x664693: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x664695: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x664696: 68f1000000 PUSH 0xf1
    f.push(m,0x000000f1u);
  }
  { // 0x66469b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x66469c: ffd5 CALL EBP
    const std::uint32_t call_target=s.bp;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0066469e: { // 0x66469e: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6646a0: 685b060000 PUSH 0x65b
    f.push(m,0x0000065bu);
  }
  { // 0x6646a5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6646a6: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6646a8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6646aa: 7412 JZ 0x006646be
    if(integer::condition("JZ",flags)) goto L006646be;
  }
  { // 0x6646ac: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x6646ae: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6646b0: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x6646b2: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x6646b5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6646b6: 68f1000000 PUSH 0xf1
    f.push(m,0x000000f1u);
  }
  { // 0x6646bb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6646bc: ffd5 CALL EBP
    const std::uint32_t call_target=s.bp;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L006646be: { // 0x6646be: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6646bf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6646c0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6646c1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6646c2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00268aa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x668aa0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x668aa1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x668aa5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x668aa6: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x668aa8: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x668aaa: 7434 JZ 0x00668ae0
    if(integer::condition("JZ",flags)) goto L00668ae0;
  }
  { // 0x668aac: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x668aae: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x668ab0: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x668ab4: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x668ab6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x668ab7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x668ab8: c744241cec000000 MOV dword ptr [ESP + 0x1c],0xec
    m.w32((f.sp+0x0000001cu), 0x000000ecu);
  }
  { // 0x668ac0: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x668ac3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x668ac5: 7c19 JL 0x00668ae0
    if(integer::condition("JL",flags)) goto L00668ae0;
  }
  { // 0x668ac7: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x668acb: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x668acd: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x668acf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x668ad0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x668ad1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x668ad2: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x668ad5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x668ad7: 7c07 JL 0x00668ae0
    if(integer::condition("JL",flags)) goto L00668ae0;
  }
  { // 0x668ad9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x668ada: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x668adc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x668add: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00668ae0: { // 0x668ae0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x668ae1: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x668ae3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x668ae4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00268af0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x668af0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x668af1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x668af5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x668af6: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x668af8: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x668afa: 743d JZ 0x00668b39
    if(integer::condition("JZ",flags)) goto L00668b39;
  }
  { // 0x668afc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x668afe: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x668b00: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x668b04: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x668b06: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x668b07: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x668b08: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x668b0b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x668b0d: 7c2a JL 0x00668b39
    if(integer::condition("JL",flags)) goto L00668b39;
  }
  { // 0x668b0f: 817c240cec000000 CMP dword ptr [ESP + 0xc],0xec
    (void)integer::sub(m.r32((f.sp+0x0000000cu)),0x000000ecu,32,flags);
  }
  { // 0x668b17: 7520 JNZ 0x00668b39
    if(integer::condition("JNZ",flags)) goto L00668b39;
  }
  { // 0x668b19: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x668b1b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x668b1d: 68ec000000 PUSH 0xec
    f.push(m,0x000000ecu);
  }
  { // 0x668b22: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x668b23: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x668b24: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x668b27: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x668b29: c74704ffffffff MOV dword ptr [EDI + 0x4],0xffffffff
    m.w32((s.di+0x00000004u), 0xffffffffu);
  }
  { // 0x668b30: 7c07 JL 0x00668b39
    if(integer::condition("JL",flags)) goto L00668b39;
  }
  { // 0x668b32: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x668b33: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x668b35: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x668b36: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00668b39: { // 0x668b39: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x668b3a: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x668b3c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x668b3d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0026b020(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x66b020: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x66b021: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x66b023: c706ac607900 MOV dword ptr [ESI],0x7960ac
    m.w32((s.si), 0x007960acu);
  }
  { // 0x66b029: c74604e45f7900 MOV dword ptr [ESI + 0x4],0x795fe4
    m.w32((s.si+0x00000004u), 0x00795fe4u);
  }
  { // 0x66b030: c74618c05f7900 MOV dword ptr [ESI + 0x18],0x795fc0
    m.w32((s.si+0x00000018u), 0x00795fc0u);
  }
  { // 0x66b037: 8b4668 MOV EAX,dword ptr [ESI + 0x68]
    s.ax = m.r32((s.si+0x00000068u));
  }
  { // 0x66b03a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x66b03c: 7406 JZ 0x0066b044
    if(integer::condition("JZ",flags)) goto L0066b044;
  }
  { // 0x66b03e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x66b040: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x66b041: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0066b044: { // 0x66b044: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x66b046: e88501edff CALL 0x0053b1d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x66b04b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x66b04c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0026b650(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x66b650: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x66b651: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x66b655: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x66b658: 81c1e0020000 ADD ECX,0x2e0
    s.cx = integer::add(s.cx,0x000002e0u,32,flags);
  }
  { // 0x66b65e: e89dd2e4ff CALL 0x004b8900
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x66b663: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x66b665: 7406 JZ 0x0066b66d
    if(integer::condition("JZ",flags)) goto L0066b66d;
  }
  { // 0x66b667: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x66b669: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x66b66a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0066b66d: { // 0x66b66d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x66b66f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x66b670: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x66b673: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x66b675: 743a JZ 0x0066b6b1
    if(integer::condition("JZ",flags)) goto L0066b6b1;
  }
  { // 0x66b677: 8b4e3c MOV ECX,dword ptr [ESI + 0x3c]
    s.cx = m.r32((s.si+0x0000003cu));
  }
  { // 0x66b67a: a1c80caa00 MOV EAX,[0x00aa0cc8]
    s.ax = m.r32((0x00aa0cc8u));
  }
  { // 0x66b67f: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x66b681: 7519 JNZ 0x0066b69c
    if(integer::condition("JNZ",flags)) goto L0066b69c;
  }
  { // 0x66b683: 8b5640 MOV EDX,dword ptr [ESI + 0x40]
    s.dx = m.r32((s.si+0x00000040u));
  }
  { // 0x66b686: a1cc0caa00 MOV EAX,[0x00aa0ccc]
    s.ax = m.r32((0x00aa0cccu));
  }
  { // 0x66b68b: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x66b68d: 750d JNZ 0x0066b69c
    if(integer::condition("JNZ",flags)) goto L0066b69c;
  }
  { // 0x66b68f: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  { // 0x66b692: 8b0dd00caa00 MOV ECX,dword ptr [0x00aa0cd0]
    s.cx = m.r32((0x00aa0cd0u));
  }
  { // 0x66b698: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x66b69a: 7415 JZ 0x0066b6b1
    if(integer::condition("JZ",flags)) goto L0066b6b1;
  }
  L0066b69c: { // 0x66b69c: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x66b69f: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x66b6a1: ff92bc040000 CALL dword ptr [EDX + 0x4bc]
    const std::uint32_t call_target=m.r32((s.dx+0x000004bcu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x66b6a7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x66b6a9: 7e06 JLE 0x0066b6b1
    if(integer::condition("JLE",flags)) goto L0066b6b1;
  }
  { // 0x66b6ab: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x66b6ad: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x66b6ae: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0066b6b1: { // 0x66b6b1: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x66b6b3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x66b6b4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0026bf00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x66bf00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x66bf01: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x66bf05: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x66bf06: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x66bf09: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x66bf0b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x66bf0d: ff90a4010000 CALL dword ptr [EAX + 0x1a4]
    const std::uint32_t call_target=m.r32((s.ax+0x000001a4u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x66bf13: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x66bf15: 8a881c010000 MOV CL,byte ptr [EAX + 0x11c]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000011cu)));
  }
  { // 0x66bf1b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x66bf1c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x66bf1d: ff577c CALL dword ptr [EDI + 0x7c]
    const std::uint32_t call_target=m.r32((s.di+0x0000007cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x66bf20: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x66bf21: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x66bf22: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00270120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x670120: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x670121: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x670123: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x670126: 8b8188040000 MOV EAX,dword ptr [ECX + 0x488]
    s.ax = m.r32((s.cx+0x00000488u));
  }
  { // 0x67012c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x67012e: 7510 JNZ 0x00670140
    if(integer::condition("JNZ",flags)) goto L00670140;
  }
  { // 0x670130: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x670132: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x670134: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x670136: ff9010040000 CALL dword ptr [EAX + 0x410]
    const std::uint32_t call_target=m.r32((s.ax+0x00000410u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x67013c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x67013e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x67013f: c3 RET
    finish(m,s,f,0u); return;
  }
  L00670140: { // 0x670140: e86bd4e5ff CALL 0x004cd5b0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x670145: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x670148: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x67014a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x67014c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x67014e: ff9214040000 CALL dword ptr [EDX + 0x414]
    const std::uint32_t call_target=m.r32((s.dx+0x00000414u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x670154: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x670155: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00270510(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x670510: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x670511: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x670513: c706ac607900 MOV dword ptr [ESI],0x7960ac
    m.w32((s.si), 0x007960acu);
  }
  { // 0x670519: c74604e45f7900 MOV dword ptr [ESI + 0x4],0x795fe4
    m.w32((s.si+0x00000004u), 0x00795fe4u);
  }
  { // 0x670520: c74618c05f7900 MOV dword ptr [ESI + 0x18],0x795fc0
    m.w32((s.si+0x00000018u), 0x00795fc0u);
  }
  { // 0x670527: 8b4668 MOV EAX,dword ptr [ESI + 0x68]
    s.ax = m.r32((s.si+0x00000068u));
  }
  { // 0x67052a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x67052c: 7406 JZ 0x00670534
    if(integer::condition("JZ",flags)) goto L00670534;
  }
  { // 0x67052e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x670530: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x670531: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00670534: { // 0x670534: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x670536: e895acecff CALL 0x0053b1d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x67053b: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x670540: 7409 JZ 0x0067054b
    if(integer::condition("JZ",flags)) goto L0067054b;
  }
  { // 0x670542: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x670543: e833d10f00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x670548: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0067054b: { // 0x67054b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x67054d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x67054e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00278de0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x678de0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x678de1: 8b1d84547800 MOV EBX,dword ptr [0x00785484]
    s.bx = m.r32((0x00785484u));
  }
  { // 0x678de7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x678de8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x678de9: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x678deb: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x678ded: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x678def: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x678df1: 6847010000 PUSH 0x147
    f.push(m,0x00000147u);
  }
  { // 0x678df6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x678df7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x678df8: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x678dfa: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x678dfc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x678dfd: 6850010000 PUSH 0x150
    f.push(m,0x00000150u);
  }
  { // 0x678e02: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x678e03: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x678e04: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x678e06: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x678e08: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x678e09: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x678e0a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x678e0b: 740d JZ 0x00678e1a
    if(integer::condition("JZ",flags)) goto L00678e1a;
  }
  { // 0x678e0d: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x678e10: 7408 JZ 0x00678e1a
    if(integer::condition("JZ",flags)) goto L00678e1a;
  }
  { // 0x678e12: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x678e15: 7403 JZ 0x00678e1a
    if(integer::condition("JZ",flags)) goto L00678e1a;
  }
  { // 0x678e17: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x678e19: c3 RET
    finish(m,s,f,0u); return;
  }
  L00678e1a: { // 0x678e1a: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x678e1f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00279ff0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x679ff0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x679ff1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x679ff3: 8b4e3c MOV ECX,dword ptr [ESI + 0x3c]
    s.cx = m.r32((s.si+0x0000003cu));
  }
  { // 0x679ff6: c70634077900 MOV dword ptr [ESI],0x790734
    m.w32((s.si), 0x00790734u);
  }
  { // 0x679ffc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x679ffe: 740d JZ 0x0067a00d
    if(integer::condition("JZ",flags)) goto L0067a00d;
  }
  { // 0x67a000: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x67a002: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x67a004: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x67a006: c7463c00000000 MOV dword ptr [ESI + 0x3c],0x0
    m.w32((s.si+0x0000003cu), 0x00000000u);
  }
  L0067a00d: { // 0x67a00d: 8b4e40 MOV ECX,dword ptr [ESI + 0x40]
    s.cx = m.r32((s.si+0x00000040u));
  }
  { // 0x67a010: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x67a012: 740d JZ 0x0067a021
    if(integer::condition("JZ",flags)) goto L0067a021;
  }
  { // 0x67a014: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x67a016: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x67a018: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x67a01a: c7464000000000 MOV dword ptr [ESI + 0x40],0x0
    m.w32((s.si+0x00000040u), 0x00000000u);
  }
  L0067a021: { // 0x67a021: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x67a023: e8384ce5ff CALL 0x004cec60
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x67a028: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x67a029: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00290d20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x690d20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x690d21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x690d23: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x690d27: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x690d29: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  { // 0x690d2b: 898604080000 MOV dword ptr [ESI + 0x804],EAX
    m.w32((s.si+0x00000804u), s.ax);
  }
  { // 0x690d31: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  { // 0x690d35: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x690d37: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x690d3b: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x690d3d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x690d3e: ff5008 CALL dword ptr [EAX + 0x8]
    const std::uint32_t call_target=m.r32((s.ax+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x690d41: 66817c2408fffe CMP word ptr [ESP + 0x8],0xfeff
    (void)integer::sub(m.r16((f.sp+0x00000008u)),0x0000feffu,16,flags);
  }
  { // 0x690d48: 740d JZ 0x00690d57
    if(integer::condition("JZ",flags)) goto L00690d57;
  }
  { // 0x690d4a: 6844fc7d00 PUSH 0x7dfc44
    f.push(m,0x007dfc44u);
  }
  { // 0x690d4f: e89c5bd7ff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x690d54: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00690d57: { // 0x690d57: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x690d59: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x690d5a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00296d50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x696d50: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  { // 0x696d53: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x696d55: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x696d56: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x696d58: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x696d59: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x696d5a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x696d5b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x696d5c: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  { // 0x696d61: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x696d62: 8b359c8baa00 MOV ESI,dword ptr [0x00aa8b9c]
    s.si = m.r32((0x00aa8b9cu));
  }
  { // 0x696d68: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x696d69: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x696d6a: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  { // 0x696d6e: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  { // 0x696d72: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x696d73: 8b0d881c8200 MOV ECX,dword ptr [0x00821c88]
    s.cx = m.r32((0x00821c88u));
  }
  { // 0x696d79: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  { // 0x696d7d: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x696d7f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x696d80: ff5078 CALL dword ptr [EAX + 0x78]
    const std::uint32_t call_target=m.r32((s.ax+0x00000078u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x696d83: 8b150ca78100 MOV EDX,dword ptr [0x0081a70c]
    s.dx = m.r32((0x0081a70cu));
  }
  { // 0x696d89: 8b0d881c8200 MOV ECX,dword ptr [0x00821c88]
    s.cx = m.r32((0x00821c88u));
  }
  { // 0x696d8f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x696d90: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  { // 0x696d94: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x696d95: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x696d97: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x696d98: e8337ee0ff CALL 0x0049ebd0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x696d9d: c6058c48aa0001 MOV byte ptr [0x00aa488c],0x1
    m.w8((0x00aa488cu), 0x00000001u);
  }
  { // 0x696da4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x696da5: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  { // 0x696da8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00297500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x697500: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x697501: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x697503: 8a86144f0000 MOV AL,byte ptr [ESI + 0x4f14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00004f14u)));
  }
  { // 0x697509: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x69750b: 7538 JNZ 0x00697545
    if(integer::condition("JNZ",flags)) goto L00697545;
  }
  { // 0x69750d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x69750f: 68985eaa00 PUSH 0xaa5e98
    f.push(m,0x00aa5e98u);
  }
  { // 0x697514: ff5034 CALL dword ptr [EAX + 0x34]
    const std::uint32_t call_target=m.r32((s.ax+0x00000034u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x697517: 8b0df01c8200 MOV ECX,dword ptr [0x00821cf0]
    s.cx = m.r32((0x00821cf0u));
  }
  { // 0x69751d: 68f1000000 PUSH 0xf1
    f.push(m,0x000000f1u);
  }
  { // 0x697522: e8a9970400 CALL 0x006e0cd0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x697527: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x697529: c686144f000001 MOV byte ptr [ESI + 0x4f14],0x1
    m.w8((s.si+0x00004f14u), 0x00000001u);
  }
  { // 0x697530: e8bbfbffff CALL 0x006970f0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x697535: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x697537: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x697539: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x69753b: c686154f000001 MOV byte ptr [ESI + 0x4f15],0x1
    m.w8((s.si+0x00004f15u), 0x00000001u);
  }
  { // 0x697542: ff5238 CALL dword ptr [EDX + 0x38]
    const std::uint32_t call_target=m.r32((s.dx+0x00000038u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00697545: { // 0x697545: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x697546: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002a03b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a03b0: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  { // 0x6a03b5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a03b6: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x6a03b9: 7548 JNZ 0x006a0403
    if(integer::condition("JNZ",flags)) goto L006a0403;
  }
  { // 0x6a03bb: a1a488a200 MOV EAX,[0x00a288a4]
    s.ax = m.r32((0x00a288a4u));
  }
  { // 0x6a03c0: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  { // 0x6a03c2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6a03c4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6a03c6: ff523c CALL dword ptr [EDX + 0x3c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000003cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6a03c9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a03cb: 7436 JZ 0x006a0403
    if(integer::condition("JZ",flags)) goto L006a0403;
  }
  { // 0x6a03cd: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  { // 0x6a03d2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6a03d4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a03d6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6a03d8: 750d JNZ 0x006a03e7
    if(integer::condition("JNZ",flags)) goto L006a03e7;
  }
  { // 0x6a03da: ff503c CALL dword ptr [EAX + 0x3c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000003cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6a03dd: 8a8835010000 MOV CL,byte ptr [EAX + 0x135]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000135u)));
  }
  { // 0x6a03e3: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x6a03e5: eb0c JMP 0x006a03f3
    goto L006a03f3;
  }
  L006a03e7: { // 0x6a03e7: ff503c CALL dword ptr [EAX + 0x3c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000003cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6a03ea: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6a03ec: e8bf43e5ff CALL 0x004f47b0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6a03f1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006a03f3: { // 0x6a03f3: 750e JNZ 0x006a0403
    if(integer::condition("JNZ",flags)) goto L006a0403;
  }
  { // 0x6a03f5: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6a03f7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6a03f9: ff9244010000 CALL dword ptr [EDX + 0x144]
    const std::uint32_t call_target=m.r32((s.dx+0x00000144u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x6a03ff: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a0401: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a0402: c3 RET
    finish(m,s,f,0u); return;
  }
  L006a0403: { // 0x6a0403: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6a0405: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a0406: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002aaaf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6aaaf0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6aaaf1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6aaaf2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6aaaf6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6aaaf8: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6aaafa: 7449 JZ 0x006aab45
    if(integer::condition("JZ",flags)) goto L006aab45;
  }
  { // 0x6aaafc: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x6aaafe: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6aab00: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6aab03: 83f80b CMP EAX,0xb
    (void)integer::sub(s.ax,0x0000000bu,32,flags);
  }
  { // 0x6aab06: 7527 JNZ 0x006aab2f
    if(integer::condition("JNZ",flags)) goto L006aab2f;
  }
  { // 0x6aab08: 884604 MOV byte ptr [ESI + 0x4],AL
    m.w8((s.si+0x00000004u), (s.ax & 0xffu));
  }
  { // 0x6aab0b: 8b7f24 MOV EDI,dword ptr [EDI + 0x24]
    s.di = m.r32((s.di+0x00000024u));
  }
  { // 0x6aab0e: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  { // 0x6aab12: 0fbf44240e MOVSX EAX,word ptr [ESP + 0xe]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000000eu)),16));
  }
  { // 0x6aab17: 0fbfd7 MOVSX EDX,DI
    s.dx = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  { // 0x6aab1a: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  { // 0x6aab1d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6aab1e: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  { // 0x6aab21: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  { // 0x6aab24: 8d04ca LEA EAX,[EDX + ECX*0x8]
    s.ax = (s.dx+(s.cx * 0x00000008u));
  }
  { // 0x6aab27: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x6aab29: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6aab2b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6aab2c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006aab2f: { // 0x6aab2f: 8d4704 LEA EAX,[EDI + 0x4]
    s.ax = (s.di+0x00000004u);
  }
  { // 0x6aab32: c6460434 MOV byte ptr [ESI + 0x4],0x34
    m.w8((s.si+0x00000004u), 0x00000034u);
  }
  { // 0x6aab36: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6aab37: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x6aab39: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6aab3c: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x6aab3e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6aab40: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6aab41: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6aab42: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006aab45: { // 0x6aab45: c6460400 MOV byte ptr [ESI + 0x4],0x0
    m.w8((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x6aab49: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x6aab4f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6aab51: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6aab52: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6aab53: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002b0a70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b0a70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b0a71: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6b0a73: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  { // 0x6b0a76: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6b0a78: 7407 JZ 0x006b0a81
    if(integer::condition("JZ",flags)) goto L006b0a81;
  }
  { // 0x6b0a7a: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x6b0a7c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6b0a7e: ff5020 CALL dword ptr [EAX + 0x20]
    const std::uint32_t call_target=m.r32((s.ax+0x00000020u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L006b0a81: { // 0x6b0a81: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  { // 0x6b0a83: e8cfce0b00 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6b0a88: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6b0a8b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6b0a8d: 7426 JZ 0x006b0ab5
    if(integer::condition("JZ",flags)) goto L006b0ab5;
  }
  { // 0x6b0a8f: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x6b0a93: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  { // 0x6b0a96: 8b0d8ce58400 MOV ECX,dword ptr [0x0084e58c]
    s.cx = m.r32((0x0084e58cu));
  }
  { // 0x6b0a9c: 8b1491 MOV EDX,dword ptr [ECX + EDX*0x4]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  { // 0x6b0a9f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6b0aa1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6b0aa2: e839ecfaff CALL 0x0065f6e0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6b0aa7: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6b0aa9: 894628 MOV dword ptr [ESI + 0x28],EAX
    m.w32((s.si+0x00000028u), s.ax);
  }
  { // 0x6b0aac: e8ffedfaff CALL 0x0065f8b0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6b0ab1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b0ab2: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L006b0ab5: { // 0x6b0ab5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6b0ab7: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6b0ab9: 894628 MOV dword ptr [ESI + 0x28],EAX
    m.w32((s.si+0x00000028u), s.ax);
  }
  { // 0x6b0abc: e8efedfaff CALL 0x0065f8b0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x6b0ac1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b0ac2: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002b6920(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b6920: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b6921: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6b6923: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6b6925: ff906c010000 CALL dword ptr [EAX + 0x16c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000016cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6b692b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6b692d: 7436 JZ 0x006b6965
    if(integer::condition("JZ",flags)) goto L006b6965;
  }
  { // 0x6b692f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6b6931: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6b6933: ff926c010000 CALL dword ptr [EDX + 0x16c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000016cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6b6939: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  { // 0x6b693c: 7427 JZ 0x006b6965
    if(integer::condition("JZ",flags)) goto L006b6965;
  }
  { // 0x6b693e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6b6940: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6b6942: ff906c010000 CALL dword ptr [EAX + 0x16c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000016cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6b6948: 83f810 CMP EAX,0x10
    (void)integer::sub(s.ax,0x00000010u,32,flags);
  }
  { // 0x6b694b: 7418 JZ 0x006b6965
    if(integer::condition("JZ",flags)) goto L006b6965;
  }
  { // 0x6b694d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6b694f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6b6951: ff9280000000 CALL dword ptr [EDX + 0x80]
    const std::uint32_t call_target=m.r32((s.dx+0x00000080u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6b6957: 8a88a00a0000 MOV CL,byte ptr [EAX + 0xaa0]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000aa0u)));
  }
  { // 0x6b695d: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x6b695f: 7504 JNZ 0x006b6965
    if(integer::condition("JNZ",flags)) goto L006b6965;
  }
  { // 0x6b6961: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6b6963: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b6964: c3 RET
    finish(m,s,f,0u); return;
  }
  L006b6965: { // 0x6b6965: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6b6967: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b6968: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002b6970(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b6970: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b6971: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6b6973: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  { // 0x6b6976: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6b6978: 7e4b JLE 0x006b69c5
    if(integer::condition("JLE",flags)) goto L006b69c5;
  }
  { // 0x6b697a: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  { // 0x6b697d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6b697f: 7544 JNZ 0x006b69c5
    if(integer::condition("JNZ",flags)) goto L006b69c5;
  }
  { // 0x6b6981: 8a862d030000 MOV AL,byte ptr [ESI + 0x32d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000032du)));
  }
  { // 0x6b6987: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6b6989: 743a JZ 0x006b69c5
    if(integer::condition("JZ",flags)) goto L006b69c5;
  }
  { // 0x6b698b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6b698d: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6b6990: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  { // 0x6b6993: 7430 JZ 0x006b69c5
    if(integer::condition("JZ",flags)) goto L006b69c5;
  }
  { // 0x6b6995: 8a8673030000 MOV AL,byte ptr [ESI + 0x373]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000373u)));
  }
  { // 0x6b699b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6b699d: 7426 JZ 0x006b69c5
    if(integer::condition("JZ",flags)) goto L006b69c5;
  }
  { // 0x6b699f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6b69a1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6b69a3: ff9280000000 CALL dword ptr [EDX + 0x80]
    const std::uint32_t call_target=m.r32((s.dx+0x00000080u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6b69a9: 8a8800020000 MOV CL,byte ptr [EAX + 0x200]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000200u)));
  }
  { // 0x6b69af: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x6b69b1: 7412 JZ 0x006b69c5
    if(integer::condition("JZ",flags)) goto L006b69c5;
  }
  { // 0x6b69b3: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x6b69b9: e8f2dde3ff CALL 0x004f47b0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6b69be: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6b69c0: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x6b69c3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b69c4: c3 RET
    finish(m,s,f,0u); return;
  }
  L006b69c5: { // 0x6b69c5: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6b69c7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b69c8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002b7bc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b7bc0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x6b7bc4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b7bc5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6b7bc7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6b7bc8: e8234cf1ff CALL 0x005cc7f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6b7bcd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6b7bcf: 741c JZ 0x006b7bed
    if(integer::condition("JZ",flags)) goto L006b7bed;
  }
  { // 0x6b7bd1: 8a8670030000 MOV AL,byte ptr [ESI + 0x370]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000370u)));
  }
  { // 0x6b7bd7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6b7bd9: 740c JZ 0x006b7be7
    if(integer::condition("JZ",flags)) goto L006b7be7;
  }
  { // 0x6b7bdb: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6b7bdd: 6a0d PUSH 0xd
    f.push(m,0x0000000du);
  }
  { // 0x6b7bdf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6b7be1: ff9254020000 CALL dword ptr [EDX + 0x254]
    const std::uint32_t call_target=m.r32((s.dx+0x00000254u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L006b7be7: { // 0x6b7be7: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6b7be9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b7bea: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006b7bed: { // 0x6b7bed: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6b7bef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b7bf0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002ba6a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ba6a0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6ba6a1: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x6ba6a5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ba6a6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6ba6a8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ba6a9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6ba6aa: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x6ba6ac: ff97b8020000 CALL dword ptr [EDI + 0x2b8]
    const std::uint32_t call_target=m.r32((s.di+0x000002b8u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6ba6b2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6ba6b3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6ba6b4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6ba6b6: ff9750030000 CALL dword ptr [EDI + 0x350]
    const std::uint32_t call_target=m.r32((s.di+0x00000350u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6ba6bc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ba6bd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ba6be: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6ba6bf: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002ba7d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ba7d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ba7d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6ba7d3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ba7d4: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6ba7d6: ff908c030000 CALL dword ptr [EAX + 0x38c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000038cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6ba7dc: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6ba7de: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x6ba7e0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ba7e1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6ba7e3: ff929c030000 CALL dword ptr [EDX + 0x39c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000039cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6ba7e9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6ba7eb: 7425 JZ 0x006ba812
    if(integer::condition("JZ",flags)) goto L006ba812;
  }
  { // 0x6ba7ed: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x6ba7ef: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6ba7f1: 741f JZ 0x006ba812
    if(integer::condition("JZ",flags)) goto L006ba812;
  }
  { // 0x6ba7f3: 8a8812010000 MOV CL,byte ptr [EAX + 0x112]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000112u)));
  }
  { // 0x6ba7f9: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x6ba7fb: 7415 JZ 0x006ba812
    if(integer::condition("JZ",flags)) goto L006ba812;
  }
  { // 0x6ba7fd: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6ba801: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6ba803: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ba804: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6ba805: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6ba807: ff9050030000 CALL dword ptr [EAX + 0x350]
    const std::uint32_t call_target=m.r32((s.ax+0x00000350u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6ba80d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ba80e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ba80f: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006ba812: { // 0x6ba812: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6ba816: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6ba818: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6ba819: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6ba81b: ff9254030000 CALL dword ptr [EDX + 0x354]
    const std::uint32_t call_target=m.r32((s.dx+0x00000354u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6ba821: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ba822: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ba823: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002bca20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6bca20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6bca21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6bca23: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  { // 0x6bca29: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6bca2b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6bca2c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6bca2e: ff90c4000000 CALL dword ptr [EAX + 0xc4]
    const std::uint32_t call_target=m.r32((s.ax+0x000000c4u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6bca34: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6bca36: 7410 JZ 0x006bca48
    if(integer::condition("JZ",flags)) goto L006bca48;
  }
  { // 0x6bca38: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6bca3a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6bca3c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6bca3e: ff92cc000000 CALL dword ptr [EDX + 0xcc]
    const std::uint32_t call_target=m.r32((s.dx+0x000000ccu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6bca44: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6bca46: 740a JZ 0x006bca52
    if(integer::condition("JZ",flags)) goto L006bca52;
  }
  L006bca48: { // 0x6bca48: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x6bca4c: 8986d8000000 MOV dword ptr [ESI + 0xd8],EAX
    m.w32((s.si+0x000000d8u), s.ax);
  }
  L006bca52: { // 0x6bca52: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6bca53: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002bca60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6bca60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6bca61: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6bca63: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6bca65: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6bca6b: 8b88b0000000 MOV ECX,dword ptr [EAX + 0xb0]
    s.cx = m.r32((s.ax+0x000000b0u));
  }
  { // 0x6bca71: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6bca73: 7504 JNZ 0x006bca79
    if(integer::condition("JNZ",flags)) goto L006bca79;
  }
  { // 0x6bca75: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6bca77: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6bca78: c3 RET
    finish(m,s,f,0u); return;
  }
  L006bca79: { // 0x6bca79: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6bca7b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6bca7d: ff9280000000 CALL dword ptr [EDX + 0x80]
    const std::uint32_t call_target=m.r32((s.dx+0x00000080u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6bca83: 8b80b0000000 MOV EAX,dword ptr [EAX + 0xb0]
    s.ax = m.r32((s.ax+0x000000b0u));
  }
  { // 0x6bca89: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6bca8a: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  { // 0x6bca8d: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x6bca90: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002bd870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6bd870: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6bd871: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6bd873: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6bd874: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6bd876: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6bd87c: 8b80ac050000 MOV EAX,dword ptr [EAX + 0x5ac]
    s.ax = m.r32((s.ax+0x000005acu));
  }
  { // 0x6bd882: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x6bd885: 7447 JZ 0x006bd8ce
    if(integer::condition("JZ",flags)) goto L006bd8ce;
  }
  { // 0x6bd887: 8bbe54020000 MOV EDI,dword ptr [ESI + 0x254]
    s.di = m.r32((s.si+0x00000254u));
  }
  { // 0x6bd88d: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x6bd88f: 7d3d JGE 0x006bd8ce
    if(integer::condition("JGE",flags)) goto L006bd8ce;
  }
  { // 0x6bd891: 8b9694010000 MOV EDX,dword ptr [ESI + 0x194]
    s.dx = m.r32((s.si+0x00000194u));
  }
  { // 0x6bd897: 8b869c010000 MOV EAX,dword ptr [ESI + 0x19c]
    s.ax = m.r32((s.si+0x0000019cu));
  }
  { // 0x6bd89d: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  { // 0x6bd8a0: 740e JZ 0x006bd8b0
    if(integer::condition("JZ",flags)) goto L006bd8b0;
  }
  { // 0x6bd8a2: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x6bd8a8: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x6bd8aa: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x6bd8ac: 7d06 JGE 0x006bd8b4
    if(integer::condition("JGE",flags)) goto L006bd8b4;
  }
  { // 0x6bd8ae: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006bd8b0: { // 0x6bd8b0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6bd8b2: 751a JNZ 0x006bd8ce
    if(integer::condition("JNZ",flags)) goto L006bd8ce;
  }
  L006bd8b4: { // 0x6bd8b4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6bd8b6: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x6bd8b7: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x6bd8b9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6bd8bb: 89be54020000 MOV dword ptr [ESI + 0x254],EDI
    m.w32((s.si+0x00000254u), s.di);
  }
  { // 0x6bd8c1: ff921c010000 CALL dword ptr [EDX + 0x11c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000011cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6bd8c7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6bd8c9: e812000000 CALL 0x006bd8e0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L006bd8ce: { // 0x6bd8ce: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6bd8cf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6bd8d0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002be7a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6be7a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6be7a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6be7a3: 8a8673030000 MOV AL,byte ptr [ESI + 0x373]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000373u)));
  }
  { // 0x6be7a9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6be7ab: 7518 JNZ 0x006be7c5
    if(integer::condition("JNZ",flags)) goto L006be7c5;
  }
  { // 0x6be7ad: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x6be7b3: e8f85fe3ff CALL 0x004f47b0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6be7b8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6be7ba: 7509 JNZ 0x006be7c5
    if(integer::condition("JNZ",flags)) goto L006be7c5;
  }
  { // 0x6be7bc: a150deb000 MOV EAX,[0x00b0de50]
    s.ax = m.r32((0x00b0de50u));
  }
  { // 0x6be7c1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6be7c3: 7551 JNZ 0x006be816
    if(integer::condition("JNZ",flags)) goto L006be816;
  }
  L006be7c5: { // 0x6be7c5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6be7c7: e834cdf0ff CALL 0x005cb500
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6be7cc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6be7ce: 7446 JZ 0x006be816
    if(integer::condition("JZ",flags)) goto L006be816;
  }
  { // 0x6be7d0: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  { // 0x6be7d3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6be7d5: 7412 JZ 0x006be7e9
    if(integer::condition("JZ",flags)) goto L006be7e9;
  }
  { // 0x6be7d7: a1507caa00 MOV EAX,[0x00aa7c50]
    s.ax = m.r32((0x00aa7c50u));
  }
  { // 0x6be7dc: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6be7de: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6be7e0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6be7e1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6be7e2: 6a21 PUSH 0x21
    f.push(m,0x00000021u);
  }
  { // 0x6be7e4: e857acfeff CALL 0x006a9440
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L006be7e9: { // 0x6be7e9: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x6be7ef: e8bc5fe3ff CALL 0x004f47b0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6be7f4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6be7f6: 7413 JZ 0x006be80b
    if(integer::condition("JZ",flags)) goto L006be80b;
  }
  { // 0x6be7f8: a076397c00 MOV AL,[0x007c3976]
    s.ax = with_al(s.ax, m.r8((0x007c3976u)));
  }
  { // 0x6be7fd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6be7ff: 740a JZ 0x006be80b
    if(integer::condition("JZ",flags)) goto L006be80b;
  }
  { // 0x6be801: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6be803: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6be805: ff9210030000 CALL dword ptr [EDX + 0x310]
    const std::uint32_t call_target=m.r32((s.dx+0x00000310u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L006be80b: { // 0x6be80b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6be80d: e8aed9f4ff CALL 0x0060c1c0
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x6be812: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6be814: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6be815: c3 RET
    finish(m,s,f,0u); return;
  }
  L006be816: { // 0x6be816: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6be818: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6be819: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002bf060(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6bf060: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6bf061: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6bf063: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6bf065: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6bf067: ff9070030000 CALL dword ptr [EAX + 0x370]
    const std::uint32_t call_target=m.r32((s.ax+0x00000370u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6bf06d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6bf06f: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6bf071: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6bf073: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6bf075: ff9210040000 CALL dword ptr [EDX + 0x410]
    const std::uint32_t call_target=m.r32((s.dx+0x00000410u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6bf07b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6bf07d: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x6bf07f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6bf081: ff9060020000 CALL dword ptr [EAX + 0x260]
    const std::uint32_t call_target=m.r32((s.ax+0x00000260u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6bf087: 8b8e38020000 MOV ECX,dword ptr [ESI + 0x238]
    s.cx = m.r32((s.si+0x00000238u));
  }
  { // 0x6bf08d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6bf08f: 7410 JZ 0x006bf0a1
    if(integer::condition("JZ",flags)) goto L006bf0a1;
  }
  { // 0x6bf091: e8da01fcff CALL 0x0067f270
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6bf096: 8b8e38020000 MOV ECX,dword ptr [ESI + 0x238]
    s.cx = m.r32((s.si+0x00000238u));
  }
  { // 0x6bf09c: e80f0bfcff CALL 0x0067fbb0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L006bf0a1: { // 0x6bf0a1: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6bf0a3: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6bf0a5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6bf0a7: ff92d8000000 CALL dword ptr [EDX + 0xd8]
    const std::uint32_t call_target=m.r32((s.dx+0x000000d8u));
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x6bf0ad: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6bf0af: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6bf0b1: ff9044010000 CALL dword ptr [EAX + 0x144]
    const std::uint32_t call_target=m.r32((s.ax+0x00000144u));
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  { // 0x6bf0b7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6bf0b8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002c2840(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6c2840: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6c2841: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6c2843: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x6c2849: e8621fe3ff CALL 0x004f47b0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6c284e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6c2850: 7502 JNZ 0x006c2854
    if(integer::condition("JNZ",flags)) goto L006c2854;
  }
  { // 0x6c2852: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c2853: c3 RET
    finish(m,s,f,0u); return;
  }
  L006c2854: { // 0x6c2854: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6c2856: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c2858: ff9024030000 CALL dword ptr [EAX + 0x324]
    const std::uint32_t call_target=m.r32((s.ax+0x00000324u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6c285e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6c2860: 7404 JZ 0x006c2866
    if(integer::condition("JZ",flags)) goto L006c2866;
  }
  { // 0x6c2862: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6c2864: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c2865: c3 RET
    finish(m,s,f,0u); return;
  }
  L006c2866: { // 0x6c2866: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6c2868: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c286a: ff9280000000 CALL dword ptr [EDX + 0x80]
    const std::uint32_t call_target=m.r32((s.dx+0x00000080u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6c2870: 8a88040b0000 MOV CL,byte ptr [EAX + 0xb04]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000b04u)));
  }
  { // 0x6c2876: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x6c2878: 7404 JZ 0x006c287e
    if(integer::condition("JZ",flags)) goto L006c287e;
  }
  { // 0x6c287a: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6c287c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c287d: c3 RET
    finish(m,s,f,0u); return;
  }
  L006c287e: { // 0x6c287e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6c2880: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c2882: ff9028030000 CALL dword ptr [EAX + 0x328]
    const std::uint32_t call_target=m.r32((s.ax+0x00000328u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6c2888: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6c288a: 7404 JZ 0x006c2890
    if(integer::condition("JZ",flags)) goto L006c2890;
  }
  { // 0x6c288c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6c288e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c288f: c3 RET
    finish(m,s,f,0u); return;
  }
  L006c2890: { // 0x6c2890: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6c2892: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c2894: ff92c8010000 CALL dword ptr [EDX + 0x1c8]
    const std::uint32_t call_target=m.r32((s.dx+0x000001c8u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x6c289a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6c289c: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x6c289f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c28a0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002c28b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6c28b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6c28b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6c28b3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6c28b5: 7434 JZ 0x006c28eb
    if(integer::condition("JZ",flags)) goto L006c28eb;
  }
  { // 0x6c28b7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6c28b9: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6c28bc: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x6c28bf: 752a JNZ 0x006c28eb
    if(integer::condition("JNZ",flags)) goto L006c28eb;
  }
  { // 0x6c28c1: 8a8674050000 MOV AL,byte ptr [ESI + 0x574]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000574u)));
  }
  { // 0x6c28c7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6c28c9: 7c0e JL 0x006c28d9
    if(integer::condition("JL",flags)) goto L006c28d9;
  }
  { // 0x6c28cb: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6c28cd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c28cf: ff9270040000 CALL dword ptr [EDX + 0x470]
    const std::uint32_t call_target=m.r32((s.dx+0x00000470u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6c28d5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6c28d7: 750e JNZ 0x006c28e7
    if(integer::condition("JNZ",flags)) goto L006c28e7;
  }
  L006c28d9: { // 0x6c28d9: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6c28db: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c28dd: ff9024030000 CALL dword ptr [EAX + 0x324]
    const std::uint32_t call_target=m.r32((s.ax+0x00000324u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6c28e3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6c28e5: 7404 JZ 0x006c28eb
    if(integer::condition("JZ",flags)) goto L006c28eb;
  }
  L006c28e7: { // 0x6c28e7: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6c28e9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c28ea: c3 RET
    finish(m,s,f,0u); return;
  }
  L006c28eb: { // 0x6c28eb: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6c28ed: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c28ee: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002c2ba0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6c2ba0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6c2ba1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6c2ba3: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x6c2ba9: e8021ce3ff CALL 0x004f47b0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6c2bae: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6c2bb0: 7425 JZ 0x006c2bd7
    if(integer::condition("JZ",flags)) goto L006c2bd7;
  }
  { // 0x6c2bb2: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6c2bb4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c2bb6: ff9098030000 CALL dword ptr [EAX + 0x398]
    const std::uint32_t call_target=m.r32((s.ax+0x00000398u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6c2bbc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6c2bbe: 7417 JZ 0x006c2bd7
    if(integer::condition("JZ",flags)) goto L006c2bd7;
  }
  { // 0x6c2bc0: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  { // 0x6c2bc3: 7412 JZ 0x006c2bd7
    if(integer::condition("JZ",flags)) goto L006c2bd7;
  }
  { // 0x6c2bc5: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6c2bc7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c2bc9: ff9224030000 CALL dword ptr [EDX + 0x324]
    const std::uint32_t call_target=m.r32((s.dx+0x00000324u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6c2bcf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6c2bd1: 7504 JNZ 0x006c2bd7
    if(integer::condition("JNZ",flags)) goto L006c2bd7;
  }
  { // 0x6c2bd3: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6c2bd5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c2bd6: c3 RET
    finish(m,s,f,0u); return;
  }
  L006c2bd7: { // 0x6c2bd7: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6c2bd9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c2bda: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002c2c00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6c2c00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6c2c01: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6c2c03: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6c2c05: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6c2c08: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  { // 0x6c2c0b: 7404 JZ 0x006c2c11
    if(integer::condition("JZ",flags)) goto L006c2c11;
  }
  { // 0x6c2c0d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6c2c0f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c2c10: c3 RET
    finish(m,s,f,0u); return;
  }
  L006c2c11: { // 0x6c2c11: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6c2c13: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c2c15: ff9280000000 CALL dword ptr [EDX + 0x80]
    const std::uint32_t call_target=m.r32((s.dx+0x00000080u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6c2c1b: 8a88d80a0000 MOV CL,byte ptr [EAX + 0xad8]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000ad8u)));
  }
  { // 0x6c2c21: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x6c2c23: 741e JZ 0x006c2c43
    if(integer::condition("JZ",flags)) goto L006c2c43;
  }
  { // 0x6c2c25: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6c2c27: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c2c29: ff9084000000 CALL dword ptr [EAX + 0x84]
    const std::uint32_t call_target=m.r32((s.ax+0x00000084u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6c2c2f: 8b4e6c MOV ECX,dword ptr [ESI + 0x6c]
    s.cx = m.r32((s.si+0x0000006cu));
  }
  { // 0x6c2c32: 8b90a0000000 MOV EDX,dword ptr [EAX + 0xa0]
    s.dx = m.r32((s.ax+0x000000a0u));
  }
  { // 0x6c2c38: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x6c2c3a: 7407 JZ 0x006c2c43
    if(integer::condition("JZ",flags)) goto L006c2c43;
  }
  { // 0x6c2c3c: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x6c2c41: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c2c42: c3 RET
    finish(m,s,f,0u); return;
  }
  L006c2c43: { // 0x6c2c43: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6c2c45: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c2c46: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002c2db0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6c2db0: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x6c2db4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6c2db5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6c2db7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6c2db8: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x6c2dbc: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x6c2dc0: 8b8628020000 MOV EAX,dword ptr [ESI + 0x228]
    s.ax = m.r32((s.si+0x00000228u));
  }
  { // 0x6c2dc6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6c2dc7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6c2dc8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6c2dc9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c2dcb: 89862c020000 MOV dword ptr [ESI + 0x22c],EAX
    m.w32((s.si+0x0000022cu), s.ax);
  }
  { // 0x6c2dd1: e84aedecff CALL 0x00591b20
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6c2dd6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6c2dd8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6c2dd9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c2ddb: ff9070030000 CALL dword ptr [EAX + 0x370]
    const std::uint32_t call_target=m.r32((s.ax+0x00000370u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6c2de1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6c2de2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c2de3: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_002c2df0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6c2df0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6c2df1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6c2df3: e888edecff CALL 0x00591b80
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6c2df8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6c2dfa: 7415 JZ 0x006c2e11
    if(integer::condition("JZ",flags)) goto L006c2e11;
  }
  { // 0x6c2dfc: 8b8e2c020000 MOV ECX,dword ptr [ESI + 0x22c]
    s.cx = m.r32((s.si+0x0000022cu));
  }
  { // 0x6c2e02: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6c2e04: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6c2e05: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c2e07: ff9070030000 CALL dword ptr [EAX + 0x370]
    const std::uint32_t call_target=m.r32((s.ax+0x00000370u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6c2e0d: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6c2e0f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c2e10: c3 RET
    finish(m,s,f,0u); return;
  }
  L006c2e11: { // 0x6c2e11: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6c2e13: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c2e14: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002c6920(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6c6920: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x6c6923: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6c6924: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6c6926: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6c6928: ff906c010000 CALL dword ptr [EAX + 0x16c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000016cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6c692e: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x6c6931: 7533 JNZ 0x006c6966
    if(integer::condition("JNZ",flags)) goto L006c6966;
  }
  { // 0x6c6933: 8b8e28020000 MOV ECX,dword ptr [ESI + 0x228]
    s.cx = m.r32((s.si+0x00000228u));
  }
  { // 0x6c6939: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6c693b: 7429 JZ 0x006c6966
    if(integer::condition("JZ",flags)) goto L006c6966;
  }
  { // 0x6c693d: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x6c693f: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x6c6943: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6c6944: ff5258 CALL dword ptr [EDX + 0x58]
    const std::uint32_t call_target=m.r32((s.dx+0x00000058u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6c6947: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6c6949: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x6c694d: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x6c694f: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  { // 0x6c6951: 8932 MOV dword ptr [EDX],ESI
    m.w32((s.dx), s.si);
  }
  { // 0x6c6953: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  { // 0x6c6956: 897204 MOV dword ptr [EDX + 0x4],ESI
    m.w32((s.dx+0x00000004u), s.si);
  }
  { // 0x6c6959: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c695a: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  { // 0x6c695d: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  { // 0x6c6960: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x6c6963: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006c6966: { // 0x6c6966: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x6c696a: 81c688000000 ADD ESI,0x88
    s.si = integer::add(s.si,0x00000088u,32,flags);
  }
  { // 0x6c6970: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x6c6972: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x6c6974: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  { // 0x6c6976: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x6c6979: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  { // 0x6c697c: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x6c697f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c6980: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  { // 0x6c6983: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x6c6986: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002c93c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6c93c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6c93c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6c93c3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6c93c4: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6c93c6: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6c93cc: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x6c93ce: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6c93d0: 7438 JZ 0x006c940a
    if(integer::condition("JZ",flags)) goto L006c940a;
  }
  { // 0x6c93d2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6c93d4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c93d6: ff522c CALL dword ptr [EDX + 0x2c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000002cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6c93d9: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  { // 0x6c93dc: 7523 JNZ 0x006c9401
    if(integer::condition("JNZ",flags)) goto L006c9401;
  }
  { // 0x6c93de: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c93e0: e87b9bd8ff CALL 0x00452f60
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6c93e5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6c93e7: 7e18 JLE 0x006c9401
    if(integer::condition("JLE",flags)) goto L006c9401;
  }
  { // 0x6c93e9: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  { // 0x6c93ee: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c93f0: 8bb8e80b0000 MOV EDI,dword ptr [EAX + 0xbe8]
    s.di = m.r32((s.ax+0x00000be8u));
  }
  { // 0x6c93f6: e8659bd8ff CALL 0x00452f60
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6c93fb: 0fafc7 IMUL EAX,EDI
    s.ax = integer::imul(s.ax,s.di,32,flags);
  }
  { // 0x6c93fe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6c93ff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c9400: c3 RET
    finish(m,s,f,0u); return;
  }
  L006c9401: { // 0x6c9401: 8b8798050000 MOV EAX,dword ptr [EDI + 0x598]
    s.ax = m.r32((s.di+0x00000598u));
  }
  { // 0x6c9407: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6c9408: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c9409: c3 RET
    finish(m,s,f,0u); return;
  }
  L006c940a: { // 0x6c940a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6c940b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6c940d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c940e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002c9880(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6c9880: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x6c9883: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6c9884: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6c9885: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6c9886: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6c9888: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  { // 0x6c988a: e861feffff CALL 0x006c96f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6c988f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6c9891: 7456 JZ 0x006c98e9
    if(integer::condition("JZ",flags)) goto L006c98e9;
  }
  { // 0x6c9893: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  { // 0x6c9898: 8d8e88000000 LEA ECX,[ESI + 0x88]
    s.cx = (s.si+0x00000088u);
  }
  { // 0x6c989e: 8986f4030000 MOV dword ptr [ESI + 0x3f4],EAX
    m.w32((s.si+0x000003f4u), s.ax);
  }
  { // 0x6c98a4: 8bbe28020000 MOV EDI,dword ptr [ESI + 0x228]
    s.di = m.r32((s.si+0x00000228u));
  }
  { // 0x6c98aa: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x6c98ac: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6c98ae: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  { // 0x6c98b2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6c98b4: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  { // 0x6c98b7: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  { // 0x6c98bb: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  { // 0x6c98bf: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  { // 0x6c98c2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6c98c3: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  { // 0x6c98c7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c98c9: ff9244030000 CALL dword ptr [EDX + 0x344]
    const std::uint32_t call_target=m.r32((s.dx+0x00000344u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6c98cf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6c98d1: 7418 JZ 0x006c98eb
    if(integer::condition("JZ",flags)) goto L006c98eb;
  }
  { // 0x6c98d3: 39be28020000 CMP dword ptr [ESI + 0x228],EDI
    (void)integer::sub(m.r32((s.si+0x00000228u)),s.di,32,flags);
  }
  { // 0x6c98d9: 7410 JZ 0x006c98eb
    if(integer::condition("JZ",flags)) goto L006c98eb;
  }
  { // 0x6c98db: c6860404000001 MOV byte ptr [ESI + 0x404],0x1
    m.w8((s.si+0x00000404u), 0x00000001u);
  }
  { // 0x6c98e2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6c98e3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c98e4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6c98e5: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x6c98e8: c3 RET
    finish(m,s,f,0u); return;
  }
  L006c98e9: { // 0x6c98e9: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L006c98eb: { // 0x6c98eb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6c98ec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c98ed: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6c98ee: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x6c98f1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002c9e60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6c9e60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6c9e61: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6c9e63: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6c9e65: ff905c040000 CALL dword ptr [EAX + 0x45c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000045cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6c9e6b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6c9e6d: 7515 JNZ 0x006c9e84
    if(integer::condition("JNZ",flags)) goto L006c9e84;
  }
  { // 0x6c9e6f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6c9e71: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c9e73: ff92c8030000 CALL dword ptr [EDX + 0x3c8]
    const std::uint32_t call_target=m.r32((s.dx+0x000003c8u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6c9e79: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6c9e7b: 7407 JZ 0x006c9e84
    if(integer::condition("JZ",flags)) goto L006c9e84;
  }
  { // 0x6c9e7d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6c9e7f: e8bc30f4ff CALL 0x0060cf40
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L006c9e84: { // 0x6c9e84: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6c9e86: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6c9e87: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002cadc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6cadc0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6cadc1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6cadc3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6cadc5: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6cadcb: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x6cadd1: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x6cadd3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6cadd5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6cadd6: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6cadd8: ff92b8000000 CALL dword ptr [EDX + 0xb8]
    const std::uint32_t call_target=m.r32((s.dx+0x000000b8u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6cadde: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6caddf: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002cce80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6cce80: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6cce81: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6cce82: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6cce84: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6cce85: 8dbe18010000 LEA EDI,[ESI + 0x118]
    s.di = (s.si+0x00000118u);
  }
  { // 0x6cce8b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6cce8d: e8ceb00300 CALL 0x00707f60
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6cce92: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6cce94: 750b JNZ 0x006ccea1
    if(integer::condition("JNZ",flags)) goto L006ccea1;
  }
  { // 0x6cce96: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6cce98: e843b10300 CALL 0x00707fe0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6cce9d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6cce9f: 7457 JZ 0x006ccef8
    if(integer::condition("JZ",flags)) goto L006ccef8;
  }
  L006ccea1: { // 0x6ccea1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6ccea3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6ccea5: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6cceab: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6ccead: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x6cceaf: e8acb00300 CALL 0x00707f60
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6cceb4: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  { // 0x6cceb8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6cceba: 7413 JZ 0x006ccecf
    if(integer::condition("JZ",flags)) goto L006ccecf;
  }
  { // 0x6ccebc: 8a841e6c020000 MOV AL,byte ptr [ESI + EBX*0x1 + 0x26c]
    s.ax = with_al(s.ax, m.r8((s.si+(s.bx * 0x00000001u)+0x0000026cu)));
  }
  { // 0x6ccec3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ccec5: 7408 JZ 0x006ccecf
    if(integer::condition("JZ",flags)) goto L006ccecf;
  }
  { // 0x6ccec7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ccec8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ccec9: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6ccecb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6ccecc: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006ccecf: { // 0x6ccecf: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6cced1: e80ab10300 CALL 0x00707fe0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x6cced6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6cced8: 741e JZ 0x006ccef8
    if(integer::condition("JZ",flags)) goto L006ccef8;
  }
  { // 0x6cceda: 8a841e6c020000 MOV AL,byte ptr [ESI + EBX*0x1 + 0x26c]
    s.ax = with_al(s.ax, m.r8((s.si+(s.bx * 0x00000001u)+0x0000026cu)));
  }
  { // 0x6ccee1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ccee3: 750b JNZ 0x006ccef0
    if(integer::condition("JNZ",flags)) goto L006ccef0;
  }
  { // 0x6ccee5: 8a841e7e020000 MOV AL,byte ptr [ESI + EBX*0x1 + 0x27e]
    s.ax = with_al(s.ax, m.r8((s.si+(s.bx * 0x00000001u)+0x0000027eu)));
  }
  { // 0x6cceec: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6cceee: 7408 JZ 0x006ccef8
    if(integer::condition("JZ",flags)) goto L006ccef8;
  }
  L006ccef0: { // 0x6ccef0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ccef1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ccef2: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6ccef4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6ccef5: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006ccef8: { // 0x6ccef8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ccef9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ccefa: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6ccefc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6ccefd: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002cd960(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6cd960: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6cd961: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6cd963: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6cd964: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6cd966: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6cd96c: 8a880c070000 MOV CL,byte ptr [EAX + 0x70c]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000070cu)));
  }
  { // 0x6cd972: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x6cd974: 7553 JNZ 0x006cd9c9
    if(integer::condition("JNZ",flags)) goto L006cd9c9;
  }
  { // 0x6cd976: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6cd97a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6cd97c: 7c28 JL 0x006cd9a6
    if(integer::condition("JL",flags)) goto L006cd9a6;
  }
  { // 0x6cd97e: 83ff0f CMP EDI,0xf
    (void)integer::sub(s.di,0x0000000fu,32,flags);
  }
  { // 0x6cd981: 7d23 JGE 0x006cd9a6
    if(integer::condition("JGE",flags)) goto L006cd9a6;
  }
  { // 0x6cd983: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6cd985: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6cd986: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6cd988: ff9280000000 CALL dword ptr [EDX + 0x80]
    const std::uint32_t call_target=m.r32((s.dx+0x00000080u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6cd98e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6cd990: e88b720000 CALL 0x006d4c20
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6cd995: 89be0c010000 MOV dword ptr [ESI + 0x10c],EDI
    m.w32((s.si+0x0000010cu), s.di);
  }
  { // 0x6cd99b: 898600010000 MOV dword ptr [ESI + 0x100],EAX
    m.w32((s.si+0x00000100u), s.ax);
  }
  { // 0x6cd9a1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6cd9a2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cd9a3: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006cd9a6: { // 0x6cd9a6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6cd9a8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6cd9aa: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6cd9ac: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6cd9b2: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6cd9b4: e867720000 CALL 0x006d4c20
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x6cd9b9: 898600010000 MOV dword ptr [ESI + 0x100],EAX
    m.w32((s.si+0x00000100u), s.ax);
  }
  { // 0x6cd9bf: c7860c01000000000000 MOV dword ptr [ESI + 0x10c],0x0
    m.w32((s.si+0x0000010cu), 0x00000000u);
  }
  L006cd9c9: { // 0x6cd9c9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6cd9ca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cd9cb: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002cda10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6cda10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6cda11: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6cda13: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6cda15: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6cda1b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6cda1d: e8ce710000 CALL 0x006d4bf0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6cda22: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6cda24: 7408 JZ 0x006cda2e
    if(integer::condition("JZ",flags)) goto L006cda2e;
  }
  { // 0x6cda26: 8b860c010000 MOV EAX,dword ptr [ESI + 0x10c]
    s.ax = m.r32((s.si+0x0000010cu));
  }
  { // 0x6cda2c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cda2d: c3 RET
    finish(m,s,f,0u); return;
  }
  L006cda2e: { // 0x6cda2e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6cda30: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cda31: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002cda90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6cda90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6cda91: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6cda93: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6cda94: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x6cda96: ff9788030000 CALL dword ptr [EDI + 0x388]
    const std::uint32_t call_target=m.r32((s.di+0x00000388u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6cda9c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6cda9d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6cda9f: ff979c030000 CALL dword ptr [EDI + 0x39c]
    const std::uint32_t call_target=m.r32((s.di+0x0000039cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6cdaa5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6cdaa6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cdaa7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002cdab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6cdab0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6cdab1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6cdab2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6cdab6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6cdab8: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  { // 0x6cdabb: 7507 JNZ 0x006cdac4
    if(integer::condition("JNZ",flags)) goto L006cdac4;
  }
  { // 0x6cdabd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6cdabe: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6cdac0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cdac1: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006cdac4: { // 0x6cdac4: 8d8e18010000 LEA ECX,[ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  { // 0x6cdaca: e811a50300 CALL 0x00707fe0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6cdacf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6cdad1: 741b JZ 0x006cdaee
    if(integer::condition("JZ",flags)) goto L006cdaee;
  }
  { // 0x6cdad3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6cdad5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6cdad6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6cdad8: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6cdade: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6cdae0: e86b700000 CALL 0x006d4b50
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6cdae5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6cdae7: 7405 JZ 0x006cdaee
    if(integer::condition("JZ",flags)) goto L006cdaee;
  }
  { // 0x6cdae9: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  { // 0x6cdaec: 7512 JNZ 0x006cdb00
    if(integer::condition("JNZ",flags)) goto L006cdb00;
  }
  L006cdaee: { // 0x6cdaee: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6cdaf0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6cdaf1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6cdaf3: ff9280000000 CALL dword ptr [EDX + 0x80]
    const std::uint32_t call_target=m.r32((s.dx+0x00000080u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6cdaf9: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6cdafb: e830700000 CALL 0x006d4b30
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L006cdb00: { // 0x6cdb00: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6cdb01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cdb02: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002cdb10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6cdb10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6cdb11: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6cdb13: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6cdb15: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6cdb1b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6cdb1d: e8ce700000 CALL 0x006d4bf0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6cdb22: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6cdb24: 7413 JZ 0x006cdb39
    if(integer::condition("JZ",flags)) goto L006cdb39;
  }
  { // 0x6cdb26: 8b860c010000 MOV EAX,dword ptr [ESI + 0x10c]
    s.ax = m.r32((s.si+0x0000010cu));
  }
  { // 0x6cdb2c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6cdb2e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6cdb2f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6cdb31: ff929c030000 CALL dword ptr [EDX + 0x39c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000039cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6cdb37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cdb38: c3 RET
    finish(m,s,f,0u); return;
  }
  L006cdb39: { // 0x6cdb39: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6cdb3b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6cdb3d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6cdb3e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6cdb40: ff929c030000 CALL dword ptr [EDX + 0x39c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000039cu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6cdb46: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cdb47: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002ceb10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ceb10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ceb11: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ceb12: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6ceb16: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6ceb18: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6ceb1a: 741e JZ 0x006ceb3a
    if(integer::condition("JZ",flags)) goto L006ceb3a;
  }
  { // 0x6ceb1c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6ceb1e: ff90a0020000 CALL dword ptr [EAX + 0x2a0]
    const std::uint32_t call_target=m.r32((s.ax+0x000002a0u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6ceb24: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6ceb26: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6ceb27: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6ceb29: 898600040000 MOV dword ptr [ESI + 0x400],EAX
    m.w32((s.si+0x00000400u), s.ax);
  }
  { // 0x6ceb2f: ff5238 CALL dword ptr [EDX + 0x38]
    const std::uint32_t call_target=m.r32((s.dx+0x00000038u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6ceb32: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6ceb33: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6ceb35: e8e67bdaff CALL 0x00476720
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L006ceb3a: { // 0x6ceb3a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ceb3b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ceb3c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002ceb40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ceb40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ceb41: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ceb42: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6ceb46: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6ceb48: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6ceb4a: 7420 JZ 0x006ceb6c
    if(integer::condition("JZ",flags)) goto L006ceb6c;
  }
  { // 0x6ceb4c: 8b8600040000 MOV EAX,dword ptr [ESI + 0x400]
    s.ax = m.r32((s.si+0x00000400u));
  }
  { // 0x6ceb52: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6ceb54: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x6ceb56: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6ceb57: ff5238 CALL dword ptr [EDX + 0x38]
    const std::uint32_t call_target=m.r32((s.dx+0x00000038u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6ceb5a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6ceb5b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6ceb5d: e8be7bdaff CALL 0x00476720
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6ceb62: c7860004000000000000 MOV dword ptr [ESI + 0x400],0x0
    m.w32((s.si+0x00000400u), 0x00000000u);
  }
  L006ceb6c: { // 0x6ceb6c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ceb6d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ceb6e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002ceb80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ceb80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ceb81: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ceb82: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6ceb86: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6ceb88: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6ceb8a: 7440 JZ 0x006cebcc
    if(integer::condition("JZ",flags)) goto L006cebcc;
  }
  { // 0x6ceb8c: 8b8600040000 MOV EAX,dword ptr [ESI + 0x400]
    s.ax = m.r32((s.si+0x00000400u));
  }
  { // 0x6ceb92: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6ceb94: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x6ceb96: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6ceb97: ff5238 CALL dword ptr [EDX + 0x38]
    const std::uint32_t call_target=m.r32((s.dx+0x00000038u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6ceb9a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6ceb9b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6ceb9d: e87e7bdaff CALL 0x00476720
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6ceba2: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6ceba4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6ceba6: c7860004000000000000 MOV dword ptr [ESI + 0x400],0x0
    m.w32((s.si+0x00000400u), 0x00000000u);
  }
  { // 0x6cebb0: ff90a0020000 CALL dword ptr [EAX + 0x2a0]
    const std::uint32_t call_target=m.r32((s.ax+0x000002a0u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6cebb6: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6cebb8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6cebb9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6cebbb: 898600040000 MOV dword ptr [ESI + 0x400],EAX
    m.w32((s.si+0x00000400u), s.ax);
  }
  { // 0x6cebc1: ff5238 CALL dword ptr [EDX + 0x38]
    const std::uint32_t call_target=m.r32((s.dx+0x00000038u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6cebc4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6cebc5: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6cebc7: e8547bdaff CALL 0x00476720
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L006cebcc: { // 0x6cebcc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6cebcd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cebce: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002d4e30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6d4e30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6d4e31: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6d4e32: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6d4e36: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6d4e38: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x6d4e3a: 7459 JZ 0x006d4e95
    if(integer::condition("JZ",flags)) goto L006d4e95;
  }
  { // 0x6d4e3c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6d4e3e: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6d4e41: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x6d4e44: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6d4e46: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x6d4e49: 743f JZ 0x006d4e8a
    if(integer::condition("JZ",flags)) goto L006d4e8a;
  }
  { // 0x6d4e4b: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  { // 0x6d4e52: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6d4e53: e8ff8a0900 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6d4e58: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6d4e5b: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x6d4e5e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6d4e60: 7433 JZ 0x006d4e95
    if(integer::condition("JZ",flags)) goto L006d4e95;
  }
  { // 0x6d4e62: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x6d4e65: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6d4e67: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6d4e69: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x6d4e6d: 7e26 JLE 0x006d4e95
    if(integer::condition("JLE",flags)) goto L006d4e95;
  }
  L006d4e6f: { // 0x6d4e6f: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x6d4e72: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x6d4e75: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x6d4e78: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  { // 0x6d4e7b: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x6d4e7e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x6d4e7f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x6d4e81: 7cec JL 0x006d4e6f
    if(integer::condition("JL",flags)) goto L006d4e6f;
  }
  { // 0x6d4e83: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6d4e85: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6d4e86: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6d4e87: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006d4e8a: { // 0x6d4e8a: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x6d4e91: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L006d4e95: { // 0x6d4e95: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6d4e97: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6d4e98: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6d4e99: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002d7040(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6d7040: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6d7041: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6d7043: 8b4648 MOV EAX,dword ptr [ESI + 0x48]
    s.ax = m.r32((s.si+0x00000048u));
  }
  { // 0x6d7046: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6d7048: 7406 JZ 0x006d7050
    if(integer::condition("JZ",flags)) goto L006d7050;
  }
  { // 0x6d704a: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x6d704c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6d704d: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L006d7050: { // 0x6d7050: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6d7052: e87941e6ff CALL 0x0053b1d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6d7057: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x6d705c: 7409 JZ 0x006d7067
    if(integer::condition("JZ",flags)) goto L006d7067;
  }
  { // 0x6d705e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6d705f: e817660900 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6d7064: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006d7067: { // 0x6d7067: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6d7069: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6d706a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002d79e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6d79e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6d79e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6d79e3: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x6d79e5: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x6d79e8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x6d79ea: 744f JZ 0x006d7a3b
    if(integer::condition("JZ",flags)) goto L006d7a3b;
  }
  { // 0x6d79ec: 89880c020000 MOV dword ptr [EAX + 0x20c],ECX
    m.w32((s.ax+0x0000020cu), s.cx);
  }
  { // 0x6d79f2: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x6d79f5: 888804020000 MOV byte ptr [EAX + 0x204],CL
    m.w8((s.ax+0x00000204u), (s.cx & 0xffu));
  }
  { // 0x6d79fb: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  { // 0x6d79fe: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x6d7a00: ff522c CALL dword ptr [EDX + 0x2c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000002cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6d7a03: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  { // 0x6d7a06: 7526 JNZ 0x006d7a2e
    if(integer::condition("JNZ",flags)) goto L006d7a2e;
  }
  { // 0x6d7a08: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6d7a09: 8b7e28 MOV EDI,dword ptr [ESI + 0x28]
    s.di = m.r32((s.si+0x00000028u));
  }
  { // 0x6d7a0c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6d7a0e: 8b87b4010000 MOV EAX,dword ptr [EDI + 0x1b4]
    s.ax = m.r32((s.di+0x000001b4u));
  }
  { // 0x6d7a14: c6806856000001 MOV byte ptr [EAX + 0x5668],0x1
    m.w8((s.ax+0x00005668u), 0x00000001u);
  }
  { // 0x6d7a1b: e85056d7ff CALL 0x0044d070
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6d7a20: 8b8fb4010000 MOV ECX,dword ptr [EDI + 0x1b4]
    s.cx = m.r32((s.di+0x000001b4u));
  }
  { // 0x6d7a26: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6d7a27: c6814401000001 MOV byte ptr [ECX + 0x144],0x1
    m.w8((s.cx+0x00000144u), 0x00000001u);
  }
  L006d7a2e: { // 0x6d7a2e: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  { // 0x6d7a31: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x6d7a33: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x6d7a35: ff921c010000 CALL dword ptr [EDX + 0x11c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000011cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L006d7a3b: { // 0x6d7a3b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6d7a3c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002dd5d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6dd5d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6dd5d1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x6dd5d5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6dd5d6: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6dd5d8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6dd5da: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6dd5dc: 8d4f04 LEA ECX,[EDI + 0x4]
    s.cx = (s.di+0x00000004u);
  }
  { // 0x6dd5df: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x6dd5e1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6dd5e2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6dd5e3: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6dd5e6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6dd5e8: 7c0e JL 0x006dd5f8
    if(integer::condition("JL",flags)) goto L006dd5f8;
  }
  { // 0x6dd5ea: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6dd5ec: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6dd5ee: 83c708 ADD EDI,0x8
    s.di = integer::add(s.di,0x00000008u,32,flags);
  }
  { // 0x6dd5f1: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x6dd5f3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6dd5f4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6dd5f5: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L006dd5f8: { // 0x6dd5f8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6dd5f9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6dd5fa: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002e0740(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e0740: 8a442404 MOV AL,byte ptr [ESP + 0x4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000004u)));
  }
  { // 0x6e0744: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e0745: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e0747: 38460c CMP byte ptr [ESI + 0xc],AL
    (void)integer::sub(m.r8((s.si+0x0000000cu)),(s.ax & 0xffu),8,flags);
  }
  { // 0x6e074a: 7447 JZ 0x006e0793
    if(integer::condition("JZ",flags)) goto L006e0793;
  }
  { // 0x6e074c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e074e: 88460c MOV byte ptr [ESI + 0xc],AL
    m.w8((s.si+0x0000000cu), (s.ax & 0xffu));
  }
  { // 0x6e0751: 7521 JNZ 0x006e0774
    if(integer::condition("JNZ",flags)) goto L006e0774;
  }
  { // 0x6e0753: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x6e0756: 6850495454 PUSH 0x54544950
    f.push(m,0x54544950u);
  }
  { // 0x6e075b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e075c: ff15c4547800 CALL dword ptr [0x007854c4]
    const std::uint32_t call_target=m.r32((0x007854c4u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6e0762: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x6e0765: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e0767: 740b JZ 0x006e0774
    if(integer::condition("JZ",flags)) goto L006e0774;
  }
  { // 0x6e0769: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6e076b: 8d4618 LEA EAX,[ESI + 0x18]
    s.ax = (s.si+0x00000018u);
  }
  { // 0x6e076e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e076f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6e0771: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L006e0774: { // 0x6e0774: 8a460c MOV AL,byte ptr [ESI + 0xc]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000cu)));
  }
  { // 0x6e0777: 3c01 CMP AL,0x1
    (void)integer::sub((s.ax & 0xffu),0x00000001u,8,flags);
  }
  { // 0x6e0779: b8e4807d00 MOV EAX,0x7d80e4
    s.ax = 0x007d80e4u;
  }
  { // 0x6e077e: 7405 JZ 0x006e0785
    if(integer::condition("JZ",flags)) goto L006e0785;
  }
  { // 0x6e0780: b8e0807d00 MOV EAX,0x7d80e0
    s.ax = 0x007d80e0u;
  }
  L006e0785: { // 0x6e0785: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e0786: 68001e7e00 PUSH 0x7e1e00
    f.push(m,0x007e1e00u);
  }
  { // 0x6e078b: e86061d2ff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6e0790: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L006e0793: { // 0x6e0793: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e0794: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002e1120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e1120: 8a442404 MOV AL,byte ptr [ESP + 0x4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000004u)));
  }
  { // 0x6e1124: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e1125: 3c01 CMP AL,0x1
    (void)integer::sub((s.ax & 0xffu),0x00000001u,8,flags);
  }
  { // 0x6e1127: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e1129: 7505 JNZ 0x006e1130
    if(integer::condition("JNZ",flags)) goto L006e1130;
  }
  { // 0x6e112b: e840ffffff CALL 0x006e1070
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L006e1130: { // 0x6e1130: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x6e1133: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e1135: 740b JZ 0x006e1142
    if(integer::condition("JZ",flags)) goto L006e1142;
  }
  { // 0x6e1137: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6e1139: 8d4e18 LEA ECX,[ESI + 0x18]
    s.cx = (s.si+0x00000018u);
  }
  { // 0x6e113c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e113d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6e113f: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L006e1142: { // 0x6e1142: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e1143: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002e76c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e76c0: a1e88baa00 MOV EAX,[0x00aa8be8]
    s.ax = m.r32((0x00aa8be8u));
  }
  { // 0x6e76c5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e76c7: 7413 JZ 0x006e76dc
    if(integer::condition("JZ",flags)) goto L006e76dc;
  }
  { // 0x6e76c9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e76ca: e8ac5f0800 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6e76cf: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6e76d2: c705e88baa0000000000 MOV dword ptr [0x00aa8be8],0x0
    m.w32((0x00aa8be8u), 0x00000000u);
  }
  L006e76dc: { // 0x6e76dc: 8b0dec8baa00 MOV ECX,dword ptr [0x00aa8bec]
    s.cx = m.r32((0x00aa8becu));
  }
  { // 0x6e76e2: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6e76e4: 7410 JZ 0x006e76f6
    if(integer::condition("JZ",flags)) goto L006e76f6;
  }
  { // 0x6e76e6: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x6e76e8: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6e76ea: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6e76ec: c705ec8baa0000000000 MOV dword ptr [0x00aa8bec],0x0
    m.w32((0x00aa8becu), 0x00000000u);
  }
  L006e76f6: { // 0x6e76f6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e7aa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e7aa0: a0048caa00 MOV AL,[0x00aa8c04]
    s.ax = with_al(s.ax, m.r8((0x00aa8c04u)));
  }
  { // 0x6e7aa5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6e7aa6: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x6e7aa8: 3ac3 CMP AL,BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  { // 0x6e7aaa: 7457 JZ 0x006e7b03
    if(integer::condition("JZ",flags)) goto L006e7b03;
  }
  { // 0x6e7aac: a0a78caa00 MOV AL,[0x00aa8ca7]
    s.ax = with_al(s.ax, m.r8((0x00aa8ca7u)));
  }
  { // 0x6e7ab1: 881d048caa00 MOV byte ptr [0x00aa8c04],BL
    m.w8((0x00aa8c04u), (s.bx & 0xffu));
  }
  { // 0x6e7ab7: 3ac3 CMP AL,BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  { // 0x6e7ab9: 7414 JZ 0x006e7acf
    if(integer::condition("JZ",flags)) goto L006e7acf;
  }
  { // 0x6e7abb: a1a88baa00 MOV EAX,[0x00aa8ba8]
    s.ax = m.r32((0x00aa8ba8u));
  }
  { // 0x6e7ac0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e7ac1: e8b55b0800 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6e7ac6: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6e7ac9: 881da78caa00 MOV byte ptr [0x00aa8ca7],BL
    m.w8((0x00aa8ca7u), (s.bx & 0xffu));
  }
  L006e7acf: { // 0x6e7acf: a1fc8baa00 MOV EAX,[0x00aa8bfc]
    s.ax = m.r32((0x00aa8bfcu));
  }
  { // 0x6e7ad4: 891da88baa00 MOV dword ptr [0x00aa8ba8],EBX
    m.w32((0x00aa8ba8u), s.bx);
  }
  { // 0x6e7ada: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x6e7adc: 740f JZ 0x006e7aed
    if(integer::condition("JZ",flags)) goto L006e7aed;
  }
  { // 0x6e7ade: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e7adf: e8975b0800 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6e7ae4: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6e7ae7: 891dfc8baa00 MOV dword ptr [0x00aa8bfc],EBX
    m.w32((0x00aa8bfcu), s.bx);
  }
  L006e7aed: { // 0x6e7aed: 8b0d008caa00 MOV ECX,dword ptr [0x00aa8c00]
    s.cx = m.r32((0x00aa8c00u));
  }
  { // 0x6e7af3: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  { // 0x6e7af5: 740c JZ 0x006e7b03
    if(integer::condition("JZ",flags)) goto L006e7b03;
  }
  { // 0x6e7af7: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x6e7af9: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6e7afb: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6e7afd: 891d008caa00 MOV dword ptr [0x00aa8c00],EBX
    m.w32((0x00aa8c00u), s.bx);
  }
  L006e7b03: { // 0x6e7b03: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6e7b04: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002ec4b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ec4b0: a0ba8daa00 MOV AL,[0x00aa8dba]
    s.ax = with_al(s.ax, m.r8((0x00aa8dbau)));
  }
  { // 0x6ec4b5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ec4b7: 7430 JZ 0x006ec4e9
    if(integer::condition("JZ",flags)) goto L006ec4e9;
  }
  { // 0x6ec4b9: c605ba8daa0000 MOV byte ptr [0x00aa8dba],0x0
    m.w8((0x00aa8dbau), 0x00000000u);
  }
  { // 0x6ec4c0: ff1524557800 CALL dword ptr [0x00785524]
    const std::uint32_t call_target=m.r32((0x00785524u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6ec4c6: 2b05bc8daa00 SUB EAX,dword ptr [0x00aa8dbc]
    s.ax = integer::sub(s.ax,m.r32((0x00aa8dbcu)),32,flags);
  }
  { // 0x6ec4cc: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x6ec4cd: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  { // 0x6ec4cf: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x6ec4d1: 3df4010000 CMP EAX,0x1f4
    (void)integer::sub(s.ax,0x000001f4u,32,flags);
  }
  { // 0x6ec4d6: 7f11 JG 0x006ec4e9
    if(integer::condition("JG",flags)) goto L006ec4e9;
  }
  { // 0x6ec4d8: e8d3fcffff CALL 0x006ec1b0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6ec4dd: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6ec4e2: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6ec4e4: e8473bdfff CALL 0x004e0030
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L006ec4e9: { // 0x6ec4e9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002ecc20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ecc20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ecc21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6ecc23: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6ecc25: 7440 JZ 0x006ecc67
    if(integer::condition("JZ",flags)) goto L006ecc67;
  }
  { // 0x6ecc27: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  { // 0x6ecc2a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ecc2c: 7439 JZ 0x006ecc67
    if(integer::condition("JZ",flags)) goto L006ecc67;
  }
  { // 0x6ecc2e: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  { // 0x6ecc33: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6ecc35: 750e JNZ 0x006ecc45
    if(integer::condition("JNZ",flags)) goto L006ecc45;
  }
  { // 0x6ecc37: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  { // 0x6ecc3d: 8a8035010000 MOV AL,byte ptr [EAX + 0x135]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000135u)));
  }
  { // 0x6ecc43: eb0b JMP 0x006ecc50
    goto L006ecc50;
  }
  L006ecc45: { // 0x6ecc45: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x6ecc4b: e8607be0ff CALL 0x004f47b0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L006ecc50: { // 0x6ecc50: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ecc52: 7413 JZ 0x006ecc67
    if(integer::condition("JZ",flags)) goto L006ecc67;
  }
  { // 0x6ecc54: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6ecc56: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6ecc58: ff522c CALL dword ptr [EDX + 0x2c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000002cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6ecc5b: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  { // 0x6ecc5e: 7407 JZ 0x006ecc67
    if(integer::condition("JZ",flags)) goto L006ecc67;
  }
  { // 0x6ecc60: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x6ecc65: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ecc66: c3 RET
    finish(m,s,f,0u); return;
  }
  L006ecc67: { // 0x6ecc67: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6ecc69: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ecc6a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002eece0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6eece0: b8001c0000 MOV EAX,0x1c00
    s.ax = 0x00001c00u;
  }
  { // 0x6eece5: e8a6040800 CALL 0x0076f190
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6eecea: 8d842400080000 LEA EAX,[ESP + 0x800]
    s.ax = (f.sp+0x00000800u);
  }
  { // 0x6eecf1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6eecf2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6eecf3: 8b3d3c527800 MOV EDI,dword ptr [0x0078523c]
    s.di = m.r32((0x0078523cu));
  }
  { // 0x6eecf9: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6eecfb: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6eecfd: 6800140000 PUSH 0x1400
    f.push(m,0x00001400u);
  }
  { // 0x6eed02: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6eed03: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x6eed05: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6eed06: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6eed08: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6eed0a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6eed0c: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6eed0e: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x6eed12: 8b94240c1c0000 MOV EDX,dword ptr [ESP + 0x1c0c]
    s.dx = m.r32((f.sp+0x00001c0cu));
  }
  { // 0x6eed19: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6eed1b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6eed1d: 6800080000 PUSH 0x800
    f.push(m,0x00000800u);
  }
  { // 0x6eed22: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6eed23: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x6eed25: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6eed26: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6eed28: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6eed2a: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6eed2c: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x6eed30: 8d942408080000 LEA EDX,[ESP + 0x808]
    s.dx = (f.sp+0x00000808u);
  }
  { // 0x6eed37: 8b8424101c0000 MOV EAX,dword ptr [ESP + 0x1c10]
    s.ax = m.r32((f.sp+0x00001c10u));
  }
  { // 0x6eed3e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6eed3f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6eed40: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6eed41: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6eed42: ff157c547800 CALL dword ptr [0x0078547c]
    const std::uint32_t call_target=m.r32((0x0078547cu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6eed48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6eed49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6eed4a: 81c4001c0000 ADD ESP,0x1c00
    f.sp = integer::add(f.sp,0x00001c00u,32,flags);
  }
  { // 0x6eed50: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002f2230(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6f2230: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6f2231: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  { // 0x6f2235: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6f2236: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6f2238: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6f2239: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x6f223d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6f223f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6f2240: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6f2241: ff5070 CALL dword ptr [EAX + 0x70]
    const std::uint32_t call_target=m.r32((s.ax+0x00000070u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6f2244: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x6f2248: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x6f224a: 741a JZ 0x006f2266
    if(integer::condition("JZ",flags)) goto L006f2266;
  }
  { // 0x6f224c: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x6f224f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6f2251: 740c JZ 0x006f225f
    if(integer::condition("JZ",flags)) goto L006f225f;
  }
  { // 0x6f2253: 83f809 CMP EAX,0x9
    (void)integer::sub(s.ax,0x00000009u,32,flags);
  }
  { // 0x6f2256: 7418 JZ 0x006f2270
    if(integer::condition("JZ",flags)) goto L006f2270;
  }
  { // 0x6f2258: 83f810 CMP EAX,0x10
    (void)integer::sub(s.ax,0x00000010u,32,flags);
  }
  { // 0x6f225b: 7509 JNZ 0x006f2266
    if(integer::condition("JNZ",flags)) goto L006f2266;
  }
  { // 0x6f225d: eb11 JMP 0x006f2270
    goto L006f2270;
  }
  L006f225f: { // 0x6f225f: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  { // 0x6f2264: eb0f JMP 0x006f2275
    goto L006f2275;
  }
  L006f2266: { // 0x6f2266: 83f91b CMP ECX,0x1b
    (void)integer::sub(s.cx,0x0000001bu,32,flags);
  }
  { // 0x6f2269: 7405 JZ 0x006f2270
    if(integer::condition("JZ",flags)) goto L006f2270;
  }
  { // 0x6f226b: 83f91d CMP ECX,0x1d
    (void)integer::sub(s.cx,0x0000001du,32,flags);
  }
  { // 0x6f226e: 7505 JNZ 0x006f2275
    if(integer::condition("JNZ",flags)) goto L006f2275;
  }
  L006f2270: { // 0x6f2270: b905000000 MOV ECX,0x5
    s.cx = 0x00000005u;
  }
  L006f2275: { // 0x6f2275: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  { // 0x6f2277: 7512 JNZ 0x006f228b
    if(integer::condition("JNZ",flags)) goto L006f228b;
  }
  { // 0x6f2279: 83f902 CMP ECX,0x2
    (void)integer::sub(s.cx,0x00000002u,32,flags);
  }
  { // 0x6f227c: 7405 JZ 0x006f2283
    if(integer::condition("JZ",flags)) goto L006f2283;
  }
  { // 0x6f227e: 83f905 CMP ECX,0x5
    (void)integer::sub(s.cx,0x00000005u,32,flags);
  }
  { // 0x6f2281: 7508 JNZ 0x006f228b
    if(integer::condition("JNZ",flags)) goto L006f228b;
  }
  L006f2283: { // 0x6f2283: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6f2284: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6f2285: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6f2287: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6f2288: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L006f228b: { // 0x6f228b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6f228c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6f228d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6f228e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6f2290: e86b3bddff CALL 0x004c5e00
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6f2295: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6f2296: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6f2297: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6f2298: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_002f9300(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6f9300: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6f9301: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6f9303: 8a86c8050000 MOV AL,byte ptr [ESI + 0x5c8]
    s.ax = with_al(s.ax, m.r8((s.si+0x000005c8u)));
  }
  { // 0x6f9309: c686ba05000000 MOV byte ptr [ESI + 0x5ba],0x0
    m.w8((s.si+0x000005bau), 0x00000000u);
  }
  { // 0x6f9310: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6f9312: 7413 JZ 0x006f9327
    if(integer::condition("JZ",flags)) goto L006f9327;
  }
  { // 0x6f9314: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6f9316: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6f9318: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  { // 0x6f931a: ff90d0010000 CALL dword ptr [EAX + 0x1d0]
    const std::uint32_t call_target=m.r32((s.ax+0x000001d0u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6f9320: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x6f9325: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6f9326: c3 RET
    finish(m,s,f,0u); return;
  }
  L006f9327: { // 0x6f9327: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6f9328: 8dbea8020000 LEA EDI,[ESI + 0x2a8]
    s.di = (s.si+0x000002a8u);
  }
  { // 0x6f932e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6f9330: e8fbd5d9ff CALL 0x00496930
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6f9335: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6f9337: 751b JNZ 0x006f9354
    if(integer::condition("JNZ",flags)) goto L006f9354;
  }
  { // 0x6f9339: 8b8eac050000 MOV ECX,dword ptr [ESI + 0x5ac]
    s.cx = m.r32((s.si+0x000005acu));
  }
  { // 0x6f933f: 8b919c030000 MOV EDX,dword ptr [ECX + 0x39c]
    s.dx = m.r32((s.cx+0x0000039cu));
  }
  { // 0x6f9345: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6f9346: 8b8198030000 MOV EAX,dword ptr [ECX + 0x398]
    s.ax = m.r32((s.cx+0x00000398u));
  }
  { // 0x6f934c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6f934e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6f934f: e84cd6d9ff CALL 0x004969a0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L006f9354: { // 0x6f9354: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6f9356: e8e5a1dcff CALL 0x004c3540
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6f935b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6f935c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6f935d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002f9720(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6f9720: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6f9721: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6f9723: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x6f9729: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6f972b: 750a JNZ 0x006f9737
    if(integer::condition("JNZ",flags)) goto L006f9737;
  }
  { // 0x6f972d: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x6f9732: e8397b0800 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L006f9737: { // 0x6f9737: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x6f973d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6f973e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x6f9740: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6f9743: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6f9745: 7529 JNZ 0x006f9770
    if(integer::condition("JNZ",flags)) goto L006f9770;
  }
  { // 0x6f9747: 8a8699050000 MOV AL,byte ptr [ESI + 0x599]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000599u)));
  }
  { // 0x6f974d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6f974f: 751f JNZ 0x006f9770
    if(integer::condition("JNZ",flags)) goto L006f9770;
  }
  { // 0x6f9751: 8b96ac050000 MOV EDX,dword ptr [ESI + 0x5ac]
    s.dx = m.r32((s.si+0x000005acu));
  }
  { // 0x6f9757: 8b829c030000 MOV EAX,dword ptr [EDX + 0x39c]
    s.ax = m.r32((s.dx+0x0000039cu));
  }
  { // 0x6f975d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6f975e: 8b8a98030000 MOV ECX,dword ptr [EDX + 0x398]
    s.cx = m.r32((s.dx+0x00000398u));
  }
  { // 0x6f9764: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6f9765: 8d8ea8020000 LEA ECX,[ESI + 0x2a8]
    s.cx = (s.si+0x000002a8u);
  }
  { // 0x6f976b: e8e0d1d9ff CALL 0x00496950
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L006f9770: { // 0x6f9770: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6f9771: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002fe580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6fe580: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6fe581: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x6fe585: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6fe586: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6fe588: 3b9fb4010000 CMP EBX,dword ptr [EDI + 0x1b4]
    (void)integer::sub(s.bx,m.r32((s.di+0x000001b4u)),32,flags);
  }
  { // 0x6fe58e: 743c JZ 0x006fe5cc
    if(integer::condition("JZ",flags)) goto L006fe5cc;
  }
  { // 0x6fe590: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6fe591: 8bb7b0050000 MOV ESI,dword ptr [EDI + 0x5b0]
    s.si = m.r32((s.di+0x000005b0u));
  }
  { // 0x6fe597: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6fe599: c687b805000000 MOV byte ptr [EDI + 0x5b8],0x0
    m.w8((s.di+0x000005b8u), 0x00000000u);
  }
  { // 0x6fe5a0: 741a JZ 0x006fe5bc
    if(integer::condition("JZ",flags)) goto L006fe5bc;
  }
  { // 0x6fe5a2: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6fe5a4: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6fe5a6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6fe5a7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6fe5a9: ff9078030000 CALL dword ptr [EAX + 0x378]
    const std::uint32_t call_target=m.r32((s.ax+0x00000378u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6fe5af: 89b7b0050000 MOV dword ptr [EDI + 0x5b0],ESI
    m.w32((s.di+0x000005b0u), s.si);
  }
  { // 0x6fe5b5: c686b805000001 MOV byte ptr [ESI + 0x5b8],0x1
    m.w8((s.si+0x000005b8u), 0x00000001u);
  }
  L006fe5bc: { // 0x6fe5bc: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6fe5be: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6fe5bf: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6fe5c1: e80abedcff CALL 0x004ca3d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6fe5c6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6fe5c7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6fe5c8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6fe5c9: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L006fe5cc: { // 0x6fe5cc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6fe5cd: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6fe5cf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6fe5d0: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00303d30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x703d30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x703d31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x703d33: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x703d34: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  { // 0x703d37: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x703d39: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x703d3b: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x703d3d: 7203 JC 0x00703d42
    if(integer::condition("JC",flags)) goto L00703d42;
  }
  { // 0x703d3f: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L00703d42: { // 0x703d42: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  { // 0x703d44: 7428 JZ 0x00703d6e
    if(integer::condition("JZ",flags)) goto L00703d6e;
  }
  { // 0x703d46: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  { // 0x703d49: 740e JZ 0x00703d59
    if(integer::condition("JZ",flags)) goto L00703d59;
  }
  { // 0x703d4b: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x703d4e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x703d50: 8a4604 MOV AL,byte ptr [ESI + 0x4]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000004u)));
  }
  { // 0x703d53: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x703d54: e84793e2ff CALL 0x0052d0a0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00703d59: { // 0x703d59: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  { // 0x703d5c: 740d JZ 0x00703d6b
    if(integer::condition("JZ",flags)) goto L00703d6b;
  }
  { // 0x703d5e: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x703d61: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  { // 0x703d63: e88893e2ff CALL 0x0052d0f0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x703d68: 884604 MOV byte ptr [ESI + 0x4],AL
    m.w8((s.si+0x00000004u), (s.ax & 0xffu));
  }
  L00703d6b: { // 0x703d6b: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L00703d6e: { // 0x703d6e: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x703d72: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x703d74: 3b08 CMP ECX,dword ptr [EAX]
    (void)integer::sub(s.cx,m.r32((s.ax)),32,flags);
  }
  { // 0x703d76: 751b JNZ 0x00703d93
    if(integer::condition("JNZ",flags)) goto L00703d93;
  }
  { // 0x703d78: 8b560c MOV EDX,dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  { // 0x703d7b: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x703d7e: 83c00c ADD EAX,0xc
    s.ax = integer::add(s.ax,0x0000000cu,32,flags);
  }
  { // 0x703d81: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x703d82: ff5204 CALL dword ptr [EDX + 0x4]
    const std::uint32_t call_target=m.r32((s.dx+0x00000004u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x703d85: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x703d87: 740a JZ 0x00703d93
    if(integer::condition("JZ",flags)) goto L00703d93;
  }
  { // 0x703d89: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x703d8a: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x703d8f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x703d90: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00703d93: { // 0x703d93: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x703d94: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x703d96: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x703d97: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00303e80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x703e80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x703e81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x703e83: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  { // 0x703e86: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  { // 0x703e89: 7415 JZ 0x00703ea0
    if(integer::condition("JZ",flags)) goto L00703ea0;
  }
  { // 0x703e8b: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x703e8e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x703e90: 8a4604 MOV AL,byte ptr [ESI + 0x4]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000004u)));
  }
  { // 0x703e93: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x703e94: e80792e2ff CALL 0x0052d0a0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x703e99: c74608ffffffff MOV dword ptr [ESI + 0x8],0xffffffff
    m.w32((s.si+0x00000008u), 0xffffffffu);
  }
  L00703ea0: { // 0x703ea0: 8b560c MOV EDX,dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  { // 0x703ea3: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x703ea6: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x703eac: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x703eaf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x703eb0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003083d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7083d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7083d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x7083d3: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x7083d9: a1a082ab00 MOV EAX,[0x00ab82a0]
    s.ax = m.r32((0x00ab82a0u));
  }
  { // 0x7083de: 3905a882ab00 CMP dword ptr [0x00ab82a8],EAX
    (void)integer::sub(m.r32((0x00ab82a8u)),s.ax,32,flags);
  }
  { // 0x7083e4: 7c2e JL 0x00708414
    if(integer::condition("JL",flags)) goto L00708414;
  }
  { // 0x7083e6: 8a0da582ab00 MOV CL,byte ptr [0x00ab82a5]
    s.cx = with_al(s.cx, m.r8((0x00ab82a5u)));
  }
  { // 0x7083ec: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x7083ee: 7504 JNZ 0x007083f4
    if(integer::condition("JNZ",flags)) goto L007083f4;
  }
  { // 0x7083f0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7083f2: 7538 JNZ 0x0070842c
    if(integer::condition("JNZ",flags)) goto L0070842c;
  }
  L007083f4: { // 0x7083f4: 8b0dac82ab00 MOV ECX,dword ptr [0x00ab82ac]
    s.cx = m.r32((0x00ab82acu));
  }
  { // 0x7083fa: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x7083fc: 7e2e JLE 0x0070842c
    if(integer::condition("JLE",flags)) goto L0070842c;
  }
  { // 0x7083fe: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x708400: a19882ab00 MOV EAX,[0x00ab8298]
    s.ax = m.r32((0x00ab8298u));
  }
  { // 0x708405: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x708407: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x708408: b99882ab00 MOV ECX,0xab8298
    s.cx = 0x00ab8298u;
  }
  { // 0x70840d: ff5008 CALL dword ptr [EAX + 0x8]
    const std::uint32_t call_target=m.r32((s.ax+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x708410: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x708412: 7418 JZ 0x0070842c
    if(integer::condition("JZ",flags)) goto L0070842c;
  }
  L00708414: { // 0x708414: 8b0da882ab00 MOV ECX,dword ptr [0x00ab82a8]
    s.cx = m.r32((0x00ab82a8u));
  }
  { // 0x70841a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x70841c: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x70841d: 890da882ab00 MOV dword ptr [0x00ab82a8],ECX
    m.w32((0x00ab82a8u), s.cx);
  }
  { // 0x708423: 8b0d9c82ab00 MOV ECX,dword ptr [0x00ab829c]
    s.cx = m.r32((0x00ab829cu));
  }
  { // 0x708429: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L0070842c: { // 0x70842c: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x708430: e88bdfcfff CALL 0x004063c0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x708435: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x708437: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x708439: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70843a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0030b350(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70b350: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x70b351: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x70b352: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x70b354: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x70b356: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x70b35a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x70b35c: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x70b35e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x70b35f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x70b360: c744241453786f56 MOV dword ptr [ESP + 0x14],0x566f7853
    m.w32((f.sp+0x00000014u), 0x566f7853u);
  }
  { // 0x70b368: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x70b36b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70b36d: 7c17 JL 0x0070b386
    if(integer::condition("JL",flags)) goto L0070b386;
  }
  { // 0x70b36f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x70b371: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x70b373: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  { // 0x70b377: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x70b379: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x70b37a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x70b37b: c744241445786f56 MOV dword ptr [ESP + 0x14],0x566f7845
    m.w32((f.sp+0x00000014u), 0x566f7845u);
  }
  { // 0x70b383: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0070b386: { // 0x70b386: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70b387: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x70b388: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00312a30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x712a30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x712a31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x712a33: c706309a7900 MOV dword ptr [ESI],0x799a30
    m.w32((s.si), 0x00799a30u);
  }
  { // 0x712a39: c7460468997900 MOV dword ptr [ESI + 0x4],0x799968
    m.w32((s.si+0x00000004u), 0x00799968u);
  }
  { // 0x712a40: c7461844997900 MOV dword ptr [ESI + 0x18],0x799944
    m.w32((s.si+0x00000018u), 0x00799944u);
  }
  { // 0x712a47: 8b4638 MOV EAX,dword ptr [ESI + 0x38]
    s.ax = m.r32((s.si+0x00000038u));
  }
  { // 0x712a4a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x712a4c: 7406 JZ 0x00712a54
    if(integer::condition("JZ",flags)) goto L00712a54;
  }
  { // 0x712a4e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x712a50: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x712a51: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00712a54: { // 0x712a54: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x712a56: e87587e2ff CALL 0x0053b1d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x712a5b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x712a5c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00312bb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x712bb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x712bb1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x712bb5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x712bb7: 8d4efc LEA ECX,[ESI + -0x4]
    s.cx = (s.si-0x00000004u);
  }
  { // 0x712bba: c6463101 MOV byte ptr [ESI + 0x31],0x1
    m.w8((s.si+0x00000031u), 0x00000001u);
  }
  { // 0x712bbe: e81d020000 CALL 0x00712de0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x712bc3: c6463100 MOV byte ptr [ESI + 0x31],0x0
    m.w8((s.si+0x00000031u), 0x00000000u);
  }
  { // 0x712bc7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x712bc9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x712bca: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x712bcd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x712bce: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00314a00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x714a00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x714a01: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x714a03: c706309a7900 MOV dword ptr [ESI],0x799a30
    m.w32((s.si), 0x00799a30u);
  }
  { // 0x714a09: c7460468997900 MOV dword ptr [ESI + 0x4],0x799968
    m.w32((s.si+0x00000004u), 0x00799968u);
  }
  { // 0x714a10: c7461844997900 MOV dword ptr [ESI + 0x18],0x799944
    m.w32((s.si+0x00000018u), 0x00799944u);
  }
  { // 0x714a17: 8b4638 MOV EAX,dword ptr [ESI + 0x38]
    s.ax = m.r32((s.si+0x00000038u));
  }
  { // 0x714a1a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x714a1c: 7406 JZ 0x00714a24
    if(integer::condition("JZ",flags)) goto L00714a24;
  }
  { // 0x714a1e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x714a20: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x714a21: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00714a24: { // 0x714a24: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x714a26: e8a567e2ff CALL 0x0053b1d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x714a2b: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x714a30: 7409 JZ 0x00714a3b
    if(integer::condition("JZ",flags)) goto L00714a3b;
  }
  { // 0x714a32: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x714a33: e8438c0500 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x714a38: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00714a3b: { // 0x714a3b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x714a3d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x714a3e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00316c00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x716c00: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x716c04: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x716c05: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x716c07: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x716c08: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x716c0d: e8eee8e2ff CALL 0x00545500
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x716c12: 8b96b8010000 MOV EDX,dword ptr [ESI + 0x1b8]
    s.dx = m.r32((s.si+0x000001b8u));
  }
  { // 0x716c18: 81c6b8010000 ADD ESI,0x1b8
    s.si = integer::add(s.si,0x000001b8u,32,flags);
  }
  { // 0x716c1e: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  { // 0x716c22: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  { // 0x716c26: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x716c27: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x716c29: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x716c2c: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x716c2f: 753f JNZ 0x00716c70
    if(integer::condition("JNZ",flags)) goto L00716c70;
  }
  { // 0x716c31: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x716c34: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x716c37: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x716c39: 7c22 JL 0x00716c5d
    if(integer::condition("JL",flags)) goto L00716c5d;
  }
  { // 0x716c3b: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x716c3e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x716c40: 7504 JNZ 0x00716c46
    if(integer::condition("JNZ",flags)) goto L00716c46;
  }
  { // 0x716c42: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x716c44: 752a JNZ 0x00716c70
    if(integer::condition("JNZ",flags)) goto L00716c70;
  }
  L00716c46: { // 0x716c46: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x716c49: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x716c4b: 7e23 JLE 0x00716c70
    if(integer::condition("JLE",flags)) goto L00716c70;
  }
  { // 0x716c4d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x716c4f: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x716c51: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x716c53: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x716c54: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x716c56: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x716c59: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x716c5b: 7413 JZ 0x00716c70
    if(integer::condition("JZ",flags)) goto L00716c70;
  }
  L00716c5d: { // 0x716c5d: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x716c60: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x716c63: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  { // 0x716c66: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x716c69: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x716c6d: 890c82 MOV dword ptr [EDX + EAX*0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.cx);
  }
  L00716c70: { // 0x716c70: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x716c71: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_003195b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7195b0: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  { // 0x7195b3: 750d JNZ 0x007195c2
    if(integer::condition("JNZ",flags)) goto L007195c2;
  }
  { // 0x7195b5: c60548d0b00000 MOV byte ptr [0x00b0d048],0x0
    m.w8((0x00b0d048u), 0x00000000u);
  }
  { // 0x7195bc: b848d0b000 MOV EAX,0xb0d048
    s.ax = 0x00b0d048u;
  }
  { // 0x7195c1: c3 RET
    finish(m,s,f,0u); return;
  }
  L007195c2: { // 0x7195c2: 83f91a CMP ECX,0x1a
    (void)integer::sub(s.cx,0x0000001au,32,flags);
  }
  { // 0x7195c5: 7d1d JGE 0x007195e4
    if(integer::condition("JGE",flags)) goto L007195e4;
  }
  { // 0x7195c7: 83c141 ADD ECX,0x41
    s.cx = integer::add(s.cx,0x00000041u,32,flags);
  }
  { // 0x7195ca: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7195cb: 68044d7e00 PUSH 0x7e4d04
    f.push(m,0x007e4d04u);
  }
  { // 0x7195d0: 6848d0b000 PUSH 0xb0d048
    f.push(m,0x00b0d048u);
  }
  { // 0x7195d5: ff15a4547800 CALL dword ptr [0x007854a4]
    const std::uint32_t call_target=m.r32((0x007854a4u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x7195db: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x7195de: b848d0b000 MOV EAX,0xb0d048
    s.ax = 0x00b0d048u;
  }
  { // 0x7195e3: c3 RET
    finish(m,s,f,0u); return;
  }
  L007195e4: { // 0x7195e4: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x7195e6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7195e7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x7195e8: be1a000000 MOV ESI,0x1a
    s.si = 0x0000001au;
  }
  { // 0x7195ed: f7fe IDIV ESI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.si,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  { // 0x7195ef: b84fecc44e MOV EAX,0x4ec4ec4f
    s.ax = 0x4ec4ec4fu;
  }
  { // 0x7195f4: 83c241 ADD EDX,0x41
    s.dx = integer::add(s.dx,0x00000041u,32,flags);
  }
  { // 0x7195f7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x7195f8: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  { // 0x7195fa: c1fa03 SAR EDX,0x3
    s.dx = integer::shift(s.dx,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x7195fd: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x7195ff: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  { // 0x719602: 8d4c0240 LEA ECX,[EDX + EAX*0x1 + 0x40]
    s.cx = (s.dx+(s.ax * 0x00000001u)+0x00000040u);
  }
  { // 0x719606: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x719607: 68fc4c7e00 PUSH 0x7e4cfc
    f.push(m,0x007e4cfcu);
  }
  { // 0x71960c: 6848d0b000 PUSH 0xb0d048
    f.push(m,0x00b0d048u);
  }
  { // 0x719611: ff15a4547800 CALL dword ptr [0x007854a4]
    const std::uint32_t call_target=m.r32((0x007854a4u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x719617: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x71961a: b848d0b000 MOV EAX,0xb0d048
    s.ax = 0x00b0d048u;
  }
  { // 0x71961f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x719620: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0031aea0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71aea0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71aea1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71aea3: 8d4e48 LEA ECX,[ESI + 0x48]
    s.cx = (s.si+0x00000048u);
  }
  { // 0x71aea6: c706849e7900 MOV dword ptr [ESI],0x799e84
    m.w32((s.si), 0x00799e84u);
  }
  { // 0x71aeac: e86fe40300 CALL 0x00759320
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x71aeb1: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  { // 0x71aeb4: c74618c49e7900 MOV dword ptr [ESI + 0x18],0x799ec4
    m.w32((s.si+0x00000018u), 0x00799ec4u);
  }
  { // 0x71aebb: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x71aebd: 7418 JZ 0x0071aed7
    if(integer::condition("JZ",flags)) goto L0071aed7;
  }
  { // 0x71aebf: 8a4625 MOV AL,byte ptr [ESI + 0x25]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000025u)));
  }
  { // 0x71aec2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x71aec4: 7411 JZ 0x0071aed7
    if(integer::condition("JZ",flags)) goto L0071aed7;
  }
  { // 0x71aec6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x71aec8: 7406 JZ 0x0071aed0
    if(integer::condition("JZ",flags)) goto L0071aed0;
  }
  { // 0x71aeca: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x71aecc: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x71aece: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0071aed0: { // 0x71aed0: c7461c00000000 MOV dword ptr [ESI + 0x1c],0x0
    m.w32((s.si+0x0000001cu), 0x00000000u);
  }
  L0071aed7: { // 0x71aed7: 8d4e10 LEA ECX,[ESI + 0x10]
    s.cx = (s.si+0x00000010u);
  }
  { // 0x71aeda: c6462500 MOV byte ptr [ESI + 0x25],0x0
    m.w8((s.si+0x00000025u), 0x00000000u);
  }
  { // 0x71aede: c7462000000000 MOV dword ptr [ESI + 0x20],0x0
    m.w32((s.si+0x00000020u), 0x00000000u);
  }
  { // 0x71aee5: c701bc9e7900 MOV dword ptr [ECX],0x799ebc
    m.w32((s.cx), 0x00799ebcu);
  }
  { // 0x71aeeb: e8c05bf1ff CALL 0x00630ab0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x71aef0: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x71aef3: c701b49e7900 MOV dword ptr [ECX],0x799eb4
    m.w32((s.cx), 0x00799eb4u);
  }
  { // 0x71aef9: e8b25bf1ff CALL 0x00630ab0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x71aefe: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71af00: e8ab5df1ff CALL 0x00630cb0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x71af05: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71af06: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0031b570(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71b570: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71b571: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71b573: 8d4e48 LEA ECX,[ESI + 0x48]
    s.cx = (s.si+0x00000048u);
  }
  { // 0x71b576: c706849e7900 MOV dword ptr [ESI],0x799e84
    m.w32((s.si), 0x00799e84u);
  }
  { // 0x71b57c: e89fdd0300 CALL 0x00759320
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x71b581: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  { // 0x71b584: c74618c49e7900 MOV dword ptr [ESI + 0x18],0x799ec4
    m.w32((s.si+0x00000018u), 0x00799ec4u);
  }
  { // 0x71b58b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x71b58d: 7418 JZ 0x0071b5a7
    if(integer::condition("JZ",flags)) goto L0071b5a7;
  }
  { // 0x71b58f: 8a4625 MOV AL,byte ptr [ESI + 0x25]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000025u)));
  }
  { // 0x71b592: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x71b594: 7411 JZ 0x0071b5a7
    if(integer::condition("JZ",flags)) goto L0071b5a7;
  }
  { // 0x71b596: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x71b598: 7406 JZ 0x0071b5a0
    if(integer::condition("JZ",flags)) goto L0071b5a0;
  }
  { // 0x71b59a: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x71b59c: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x71b59e: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0071b5a0: { // 0x71b5a0: c7461c00000000 MOV dword ptr [ESI + 0x1c],0x0
    m.w32((s.si+0x0000001cu), 0x00000000u);
  }
  L0071b5a7: { // 0x71b5a7: 8d4e10 LEA ECX,[ESI + 0x10]
    s.cx = (s.si+0x00000010u);
  }
  { // 0x71b5aa: c6462500 MOV byte ptr [ESI + 0x25],0x0
    m.w8((s.si+0x00000025u), 0x00000000u);
  }
  { // 0x71b5ae: c7462000000000 MOV dword ptr [ESI + 0x20],0x0
    m.w32((s.si+0x00000020u), 0x00000000u);
  }
  { // 0x71b5b5: c701bc9e7900 MOV dword ptr [ECX],0x799ebc
    m.w32((s.cx), 0x00799ebcu);
  }
  { // 0x71b5bb: e8f054f1ff CALL 0x00630ab0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x71b5c0: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x71b5c3: c701b49e7900 MOV dword ptr [ECX],0x799eb4
    m.w32((s.cx), 0x00799eb4u);
  }
  { // 0x71b5c9: e8e254f1ff CALL 0x00630ab0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x71b5ce: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71b5d0: e8db56f1ff CALL 0x00630cb0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x71b5d5: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x71b5da: 7409 JZ 0x0071b5e5
    if(integer::condition("JZ",flags)) goto L0071b5e5;
  }
  { // 0x71b5dc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71b5dd: e899200500 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x71b5e2: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0071b5e5: { // 0x71b5e5: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71b5e7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71b5e8: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0031bad0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71bad0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71bad1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71bad3: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x71bad6: c706c49e7900 MOV dword ptr [ESI],0x799ec4
    m.w32((s.si), 0x00799ec4u);
  }
  { // 0x71badc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x71bade: 7418 JZ 0x0071baf8
    if(integer::condition("JZ",flags)) goto L0071baf8;
  }
  { // 0x71bae0: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x71bae3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x71bae5: 7411 JZ 0x0071baf8
    if(integer::condition("JZ",flags)) goto L0071baf8;
  }
  { // 0x71bae7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x71bae9: 7406 JZ 0x0071baf1
    if(integer::condition("JZ",flags)) goto L0071baf1;
  }
  { // 0x71baeb: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x71baed: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x71baef: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0071baf1: { // 0x71baf1: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L0071baf8: { // 0x71baf8: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x71bafc: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  { // 0x71bb00: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x71bb02: c7460800000000 MOV dword ptr [ESI + 0x8],0x0
    m.w32((s.si+0x00000008u), 0x00000000u);
  }
  { // 0x71bb09: 7409 JZ 0x0071bb14
    if(integer::condition("JZ",flags)) goto L0071bb14;
  }
  { // 0x71bb0b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71bb0c: e86a1b0500 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x71bb11: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0071bb14: { // 0x71bb14: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71bb16: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71bb17: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0031bb90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71bb90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71bb91: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71bb93: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x71bb96: c706c49e7900 MOV dword ptr [ESI],0x799ec4
    m.w32((s.si), 0x00799ec4u);
  }
  { // 0x71bb9c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x71bb9e: 7418 JZ 0x0071bbb8
    if(integer::condition("JZ",flags)) goto L0071bbb8;
  }
  { // 0x71bba0: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x71bba3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x71bba5: 7411 JZ 0x0071bbb8
    if(integer::condition("JZ",flags)) goto L0071bbb8;
  }
  { // 0x71bba7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x71bba9: 7406 JZ 0x0071bbb1
    if(integer::condition("JZ",flags)) goto L0071bbb1;
  }
  { // 0x71bbab: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x71bbad: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x71bbaf: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0071bbb1: { // 0x71bbb1: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L0071bbb8: { // 0x71bbb8: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x71bbbc: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  { // 0x71bbc0: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x71bbc2: c7460800000000 MOV dword ptr [ESI + 0x8],0x0
    m.w32((s.si+0x00000008u), 0x00000000u);
  }
  { // 0x71bbc9: 7409 JZ 0x0071bbd4
    if(integer::condition("JZ",flags)) goto L0071bbd4;
  }
  { // 0x71bbcb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71bbcc: e8aa1a0500 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x71bbd1: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0071bbd4: { // 0x71bbd4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71bbd6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71bbd7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0031ce30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71ce30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71ce31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71ce33: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x71ce36: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x71ce39: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x71ce3b: 7c28 JL 0x0071ce65
    if(integer::condition("JL",flags)) goto L0071ce65;
  }
  { // 0x71ce3d: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x71ce40: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x71ce42: 7504 JNZ 0x0071ce48
    if(integer::condition("JNZ",flags)) goto L0071ce48;
  }
  { // 0x71ce44: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x71ce46: 7517 JNZ 0x0071ce5f
    if(integer::condition("JNZ",flags)) goto L0071ce5f;
  }
  L0071ce48: { // 0x71ce48: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x71ce4b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x71ce4d: 7e10 JLE 0x0071ce5f
    if(integer::condition("JLE",flags)) goto L0071ce5f;
  }
  { // 0x71ce4f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x71ce51: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x71ce53: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x71ce55: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x71ce56: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71ce58: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x71ce5b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x71ce5d: 7506 JNZ 0x0071ce65
    if(integer::condition("JNZ",flags)) goto L0071ce65;
  }
  L0071ce5f: { // 0x71ce5f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x71ce61: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71ce62: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0071ce65: { // 0x71ce65: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x71ce68: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x71ce6c: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  { // 0x71ce6f: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x71ce72: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  { // 0x71ce75: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x71ce78: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x71ce79: 8d0cc2 LEA ECX,[EDX + EAX*0x8]
    s.cx = (s.dx+(s.ax * 0x00000008u));
  }
  { // 0x71ce7c: e84f3cf1ff CALL 0x00630ad0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x71ce81: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x71ce83: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71ce84: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0031cf10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71cf10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71cf11: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71cf13: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x71cf16: c7063c9f7900 MOV dword ptr [ESI],0x799f3c
    m.w32((s.si), 0x00799f3cu);
  }
  { // 0x71cf1c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x71cf1e: 7418 JZ 0x0071cf38
    if(integer::condition("JZ",flags)) goto L0071cf38;
  }
  { // 0x71cf20: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x71cf23: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x71cf25: 7411 JZ 0x0071cf38
    if(integer::condition("JZ",flags)) goto L0071cf38;
  }
  { // 0x71cf27: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x71cf29: 7406 JZ 0x0071cf31
    if(integer::condition("JZ",flags)) goto L0071cf31;
  }
  { // 0x71cf2b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x71cf2d: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x71cf2f: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0071cf31: { // 0x71cf31: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L0071cf38: { // 0x71cf38: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x71cf3c: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  { // 0x71cf40: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x71cf42: c7460800000000 MOV dword ptr [ESI + 0x8],0x0
    m.w32((s.si+0x00000008u), 0x00000000u);
  }
  { // 0x71cf49: 7409 JZ 0x0071cf54
    if(integer::condition("JZ",flags)) goto L0071cf54;
  }
  { // 0x71cf4b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71cf4c: e82a070500 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x71cf51: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0071cf54: { // 0x71cf54: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71cf56: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71cf57: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0031cfd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71cfd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71cfd1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71cfd3: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x71cfd6: c7063c9f7900 MOV dword ptr [ESI],0x799f3c
    m.w32((s.si), 0x00799f3cu);
  }
  { // 0x71cfdc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x71cfde: 7418 JZ 0x0071cff8
    if(integer::condition("JZ",flags)) goto L0071cff8;
  }
  { // 0x71cfe0: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x71cfe3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x71cfe5: 7411 JZ 0x0071cff8
    if(integer::condition("JZ",flags)) goto L0071cff8;
  }
  { // 0x71cfe7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x71cfe9: 7406 JZ 0x0071cff1
    if(integer::condition("JZ",flags)) goto L0071cff1;
  }
  { // 0x71cfeb: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x71cfed: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x71cfef: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0071cff1: { // 0x71cff1: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L0071cff8: { // 0x71cff8: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x71cffc: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  { // 0x71d000: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x71d002: c7460800000000 MOV dword ptr [ESI + 0x8],0x0
    m.w32((s.si+0x00000008u), 0x00000000u);
  }
  { // 0x71d009: 7409 JZ 0x0071d014
    if(integer::condition("JZ",flags)) goto L0071d014;
  }
  { // 0x71d00b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71d00c: e86a060500 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x71d011: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0071d014: { // 0x71d014: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71d016: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71d017: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0031f1c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71f1c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71f1c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71f1c3: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x71f1c6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x71f1c8: 7406 JZ 0x0071f1d0
    if(integer::condition("JZ",flags)) goto L0071f1d0;
  }
  { // 0x71f1ca: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x71f1cc: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x71f1ce: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0071f1d0: { // 0x71f1d0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71f1d2: e849a10300 CALL 0x00759320
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x71f1d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71f1d8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0031f1e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71f1e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71f1e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71f1e3: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  { // 0x71f1e6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x71f1e8: 7421 JZ 0x0071f20b
    if(integer::condition("JZ",flags)) goto L0071f20b;
  }
  { // 0x71f1ea: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x71f1ee: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x71f1f0: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x71f1f2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x71f1f4: e8c7800000 CALL 0x007272c0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x71f1f9: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  { // 0x71f1fc: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x71f200: 68e0930400 PUSH 0x493e0
    f.push(m,0x000493e0u);
  }
  { // 0x71f205: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x71f206: e80509e9ff CALL 0x005afb10
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0071f20b: { // 0x71f20b: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  { // 0x71f20e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71f20f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x71f211: 7407 JZ 0x0071f21a
    if(integer::condition("JZ",flags)) goto L0071f21a;
  }
  { // 0x71f213: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x71f215: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x71f217: ff5204 CALL dword ptr [EDX + 0x4]
    const std::uint32_t call_target=m.r32((s.dx+0x00000004u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L0071f21a: { // 0x71f21a: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0031f220(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71f220: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x71f223: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71f224: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71f226: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x71f22a: 8b5644 MOV EDX,dword ptr [ESI + 0x44]
    s.dx = m.r32((s.si+0x00000044u));
  }
  { // 0x71f22d: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x71f22f: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  { // 0x71f232: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x71f234: 8b5648 MOV EDX,dword ptr [ESI + 0x48]
    s.dx = m.r32((s.si+0x00000048u));
  }
  { // 0x71f237: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x71f239: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  { // 0x71f23d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x71f23f: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  { // 0x71f243: 7c3b JL 0x0071f280
    if(integer::condition("JL",flags)) goto L0071f280;
  }
  { // 0x71f245: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x71f248: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x71f24a: ff507c CALL dword ptr [EAX + 0x7c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000007cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x71f24d: 39442404 CMP dword ptr [ESP + 0x4],EAX
    (void)integer::sub(m.r32((f.sp+0x00000004u)),s.ax,32,flags);
  }
  { // 0x71f251: 7d2d JGE 0x0071f280
    if(integer::condition("JGE",flags)) goto L0071f280;
  }
  { // 0x71f253: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x71f257: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x71f259: 7c25 JL 0x0071f280
    if(integer::condition("JL",flags)) goto L0071f280;
  }
  { // 0x71f25b: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x71f25e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x71f260: ff9280000000 CALL dword ptr [EDX + 0x80]
    const std::uint32_t call_target=m.r32((s.dx+0x00000080u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x71f266: 39442408 CMP dword ptr [ESP + 0x8],EAX
    (void)integer::sub(m.r32((f.sp+0x00000008u)),s.ax,32,flags);
  }
  { // 0x71f26a: 7d14 JGE 0x0071f280
    if(integer::condition("JGE",flags)) goto L0071f280;
  }
  { // 0x71f26c: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x71f26f: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  { // 0x71f273: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x71f274: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x71f276: ff5028 CALL dword ptr [EAX + 0x28]
    const std::uint32_t call_target=m.r32((s.ax+0x00000028u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x71f279: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71f27a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x71f27d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0071f280: { // 0x71f280: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x71f283: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71f284: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x71f287: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_003204b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7204b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7204b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x7204b3: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x7204b6: c706cca07900 MOV dword ptr [ESI],0x79a0cc
    m.w32((s.si), 0x0079a0ccu);
  }
  { // 0x7204bc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x7204be: 7418 JZ 0x007204d8
    if(integer::condition("JZ",flags)) goto L007204d8;
  }
  { // 0x7204c0: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x7204c3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x7204c5: 7411 JZ 0x007204d8
    if(integer::condition("JZ",flags)) goto L007204d8;
  }
  { // 0x7204c7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x7204c9: 7406 JZ 0x007204d1
    if(integer::condition("JZ",flags)) goto L007204d1;
  }
  { // 0x7204cb: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x7204cd: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x7204cf: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L007204d1: { // 0x7204d1: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L007204d8: { // 0x7204d8: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x7204dc: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  { // 0x7204e0: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x7204e2: c7460800000000 MOV dword ptr [ESI + 0x8],0x0
    m.w32((s.si+0x00000008u), 0x00000000u);
  }
  { // 0x7204e9: 7409 JZ 0x007204f4
    if(integer::condition("JZ",flags)) goto L007204f4;
  }
  { // 0x7204eb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7204ec: e88ad10400 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x7204f1: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L007204f4: { // 0x7204f4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x7204f6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7204f7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00320570(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x720570: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x720571: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x720573: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x720576: c706cca07900 MOV dword ptr [ESI],0x79a0cc
    m.w32((s.si), 0x0079a0ccu);
  }
  { // 0x72057c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x72057e: 7418 JZ 0x00720598
    if(integer::condition("JZ",flags)) goto L00720598;
  }
  { // 0x720580: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x720583: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x720585: 7411 JZ 0x00720598
    if(integer::condition("JZ",flags)) goto L00720598;
  }
  { // 0x720587: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x720589: 7406 JZ 0x00720591
    if(integer::condition("JZ",flags)) goto L00720591;
  }
  { // 0x72058b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x72058d: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x72058f: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00720591: { // 0x720591: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L00720598: { // 0x720598: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x72059c: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  { // 0x7205a0: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x7205a2: c7460800000000 MOV dword ptr [ESI + 0x8],0x0
    m.w32((s.si+0x00000008u), 0x00000000u);
  }
  { // 0x7205a9: 7409 JZ 0x007205b4
    if(integer::condition("JZ",flags)) goto L007205b4;
  }
  { // 0x7205ab: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7205ac: e8cad00400 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x7205b1: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L007205b4: { // 0x7205b4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x7205b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7205b7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00321a90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x721a90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x721a91: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x721a93: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x721a96: c70678a17900 MOV dword ptr [ESI],0x79a178
    m.w32((s.si), 0x0079a178u);
  }
  { // 0x721a9c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x721a9e: 7418 JZ 0x00721ab8
    if(integer::condition("JZ",flags)) goto L00721ab8;
  }
  { // 0x721aa0: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x721aa3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x721aa5: 7411 JZ 0x00721ab8
    if(integer::condition("JZ",flags)) goto L00721ab8;
  }
  { // 0x721aa7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x721aa9: 7406 JZ 0x00721ab1
    if(integer::condition("JZ",flags)) goto L00721ab1;
  }
  { // 0x721aab: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x721aad: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x721aaf: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00721ab1: { // 0x721ab1: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L00721ab8: { // 0x721ab8: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x721abc: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  { // 0x721ac0: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x721ac2: c7460800000000 MOV dword ptr [ESI + 0x8],0x0
    m.w32((s.si+0x00000008u), 0x00000000u);
  }
  { // 0x721ac9: 7409 JZ 0x00721ad4
    if(integer::condition("JZ",flags)) goto L00721ad4;
  }
  { // 0x721acb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x721acc: e8aabb0400 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x721ad1: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00721ad4: { // 0x721ad4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x721ad6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x721ad7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00321ae0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x721ae0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x721ae1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x721ae3: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x721ae6: c70678a17900 MOV dword ptr [ESI],0x79a178
    m.w32((s.si), 0x0079a178u);
  }
  { // 0x721aec: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x721aee: 7418 JZ 0x00721b08
    if(integer::condition("JZ",flags)) goto L00721b08;
  }
  { // 0x721af0: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x721af3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x721af5: 7411 JZ 0x00721b08
    if(integer::condition("JZ",flags)) goto L00721b08;
  }
  { // 0x721af7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x721af9: 7406 JZ 0x00721b01
    if(integer::condition("JZ",flags)) goto L00721b01;
  }
  { // 0x721afb: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x721afd: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x721aff: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00721b01: { // 0x721b01: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L00721b08: { // 0x721b08: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x721b0c: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  { // 0x721b10: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x721b12: c7460800000000 MOV dword ptr [ESI + 0x8],0x0
    m.w32((s.si+0x00000008u), 0x00000000u);
  }
  { // 0x721b19: 7409 JZ 0x00721b24
    if(integer::condition("JZ",flags)) goto L00721b24;
  }
  { // 0x721b1b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x721b1c: e85abb0400 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x721b21: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00721b24: { // 0x721b24: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x721b26: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x721b27: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00325ce0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x725ce0: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x725ce3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x725ce4: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x725ce6: 8b4f28 MOV ECX,dword ptr [EDI + 0x28]
    s.cx = m.r32((s.di+0x00000028u));
  }
  { // 0x725ce9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x725ceb: 745b JZ 0x00725d48
    if(integer::condition("JZ",flags)) goto L00725d48;
  }
  { // 0x725ced: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  { // 0x725cf1: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x725cf3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x725cf4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x725cf5: ff5004 CALL dword ptr [EAX + 0x4]
    const std::uint32_t call_target=m.r32((s.ax+0x00000004u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x725cf8: 8b4f28 MOV ECX,dword ptr [EDI + 0x28]
    s.cx = m.r32((s.di+0x00000028u));
  }
  { // 0x725cfb: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  { // 0x725cff: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x725d00: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x725d02: ff5018 CALL dword ptr [EAX + 0x18]
    const std::uint32_t call_target=m.r32((s.ax+0x00000018u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x725d05: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x725d07: 8b742430 MOV ESI,dword ptr [ESP + 0x30]
    s.si = m.r32((f.sp+0x00000030u));
  }
  { // 0x725d0b: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  { // 0x725d0f: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x725d12: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  { // 0x725d16: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  { // 0x725d19: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  { // 0x725d1d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x725d1f: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  { // 0x725d22: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  { // 0x725d26: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x725d27: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  { // 0x725d2b: e8b0a6e8ff CALL 0x005b03e0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x725d30: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x725d32: e8399ee8ff CALL 0x005afb70
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x725d37: 8b4f28 MOV ECX,dword ptr [EDI + 0x28]
    s.cx = m.r32((s.di+0x00000028u));
  }
  { // 0x725d3a: 68e0930400 PUSH 0x493e0
    f.push(m,0x000493e0u);
  }
  { // 0x725d3f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x725d40: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x725d42: e8c99de8ff CALL 0x005afb10
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x725d47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00725d48: { // 0x725d48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x725d49: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x725d4c: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00328d30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x728d30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x728d31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x728d33: 8b465c MOV EAX,dword ptr [ESI + 0x5c]
    s.ax = m.r32((s.si+0x0000005cu));
  }
  { // 0x728d36: c70670a37900 MOV dword ptr [ESI],0x79a370
    m.w32((s.si), 0x0079a370u);
  }
  { // 0x728d3c: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x728d3f: 741e JZ 0x00728d5f
    if(integer::condition("JZ",flags)) goto L00728d5f;
  }
  { // 0x728d41: 6874627e00 PUSH 0x7e6274
    f.push(m,0x007e6274u);
  }
  { // 0x728d46: e8a5dbcdff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x728d4b: 8b465c MOV EAX,dword ptr [ESI + 0x5c]
    s.ax = m.r32((s.si+0x0000005cu));
  }
  { // 0x728d4e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x728d51: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x728d52: ff15d4517800 CALL dword ptr [0x007851d4]
    const std::uint32_t call_target=m.r32((0x007851d4u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x728d58: c7465cffffffff MOV dword ptr [ESI + 0x5c],0xffffffff
    m.w32((s.si+0x0000005cu), 0xffffffffu);
  }
  L00728d5f: { // 0x728d5f: 8b7624 MOV ESI,dword ptr [ESI + 0x24]
    s.si = m.r32((s.si+0x00000024u));
  }
  { // 0x728d62: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x728d64: 7409 JZ 0x00728d6f
    if(integer::condition("JZ",flags)) goto L00728d6f;
  }
  { // 0x728d66: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x728d67: e80f490400 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x728d6c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00728d6f: { // 0x728d6f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x728d70: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00329510(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x729510: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x729511: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x729513: 837e5cff CMP dword ptr [ESI + 0x5c],-0x1
    (void)integer::sub(m.r32((s.si+0x0000005cu)),0xffffffffu,32,flags);
  }
  { // 0x729517: 741e JZ 0x00729537
    if(integer::condition("JZ",flags)) goto L00729537;
  }
  { // 0x729519: 6874627e00 PUSH 0x7e6274
    f.push(m,0x007e6274u);
  }
  { // 0x72951e: e8cdd3cdff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x729523: 8b465c MOV EAX,dword ptr [ESI + 0x5c]
    s.ax = m.r32((s.si+0x0000005cu));
  }
  { // 0x729526: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x729529: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72952a: ff15d4517800 CALL dword ptr [0x007851d4]
    const std::uint32_t call_target=m.r32((0x007851d4u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x729530: c7465cffffffff MOV dword ptr [ESI + 0x5c],0xffffffff
    m.w32((s.si+0x0000005cu), 0xffffffffu);
  }
  L00729537: { // 0x729537: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x729538: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00329830(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x729830: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x729831: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x729832: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x729834: e847ffffff CALL 0x00729780
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x729839: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x72983d: 8d463c LEA EAX,[ESI + 0x3c]
    s.ax = (s.si+0x0000003cu);
  }
  { // 0x729840: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x729844: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x729845: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x729849: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x72984a: 8b4e5c MOV ECX,dword ptr [ESI + 0x5c]
    s.cx = m.r32((s.si+0x0000005cu));
  }
  { // 0x72984d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x72984e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72984f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x729850: ff152c517800 CALL dword ptr [0x0078512c]
    const std::uint32_t call_target=m.r32((0x0078512cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x729856: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x729858: 7525 JNZ 0x0072987f
    if(integer::condition("JNZ",flags)) goto L0072987f;
  }
  { // 0x72985a: ff15f4517800 CALL dword ptr [0x007851f4]
    const std::uint32_t call_target=m.r32((0x007851f4u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x729860: 3de5030000 CMP EAX,0x3e5
    (void)integer::sub(s.ax,0x000003e5u,32,flags);
  }
  { // 0x729865: 7509 JNZ 0x00729870
    if(integer::condition("JNZ",flags)) goto L00729870;
  }
  { // 0x729867: c6465101 MOV byte ptr [ESI + 0x51],0x1
    m.w8((s.si+0x00000051u), 0x00000001u);
  }
  { // 0x72986b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72986c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x72986d: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00729870: { // 0x729870: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x729872: 6874657e00 PUSH 0x7e6574
    f.push(m,0x007e6574u);
  }
  { // 0x729877: e874d0cdff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x72987c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0072987f: { // 0x72987f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x729880: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x729881: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0032a1d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72a1d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72a1d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x72a1d3: 8b465c MOV EAX,dword ptr [ESI + 0x5c]
    s.ax = m.r32((s.si+0x0000005cu));
  }
  { // 0x72a1d6: c70670a37900 MOV dword ptr [ESI],0x79a370
    m.w32((s.si), 0x0079a370u);
  }
  { // 0x72a1dc: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x72a1df: 741e JZ 0x0072a1ff
    if(integer::condition("JZ",flags)) goto L0072a1ff;
  }
  { // 0x72a1e1: 6874627e00 PUSH 0x7e6274
    f.push(m,0x007e6274u);
  }
  { // 0x72a1e6: e805c7cdff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x72a1eb: 8b465c MOV EAX,dword ptr [ESI + 0x5c]
    s.ax = m.r32((s.si+0x0000005cu));
  }
  { // 0x72a1ee: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x72a1f1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72a1f2: ff15d4517800 CALL dword ptr [0x007851d4]
    const std::uint32_t call_target=m.r32((0x007851d4u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x72a1f8: c7465cffffffff MOV dword ptr [ESI + 0x5c],0xffffffff
    m.w32((s.si+0x0000005cu), 0xffffffffu);
  }
  L0072a1ff: { // 0x72a1ff: 8b4624 MOV EAX,dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  { // 0x72a202: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x72a204: 7409 JZ 0x0072a20f
    if(integer::condition("JZ",flags)) goto L0072a20f;
  }
  { // 0x72a206: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72a207: e86f340400 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x72a20c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0072a20f: { // 0x72a20f: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x72a214: 7409 JZ 0x0072a21f
    if(integer::condition("JZ",flags)) goto L0072a21f;
  }
  { // 0x72a216: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72a217: e85f340400 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x72a21c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0072a21f: { // 0x72a21f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x72a221: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72a222: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0032a250(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72a250: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x72a253: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72a254: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x72a256: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x72a257: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72a258: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x72a259: ff1598537800 CALL dword ptr [0x00785398]
    const std::uint32_t call_target=m.r32((0x00785398u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x72a25f: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x72a261: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x72a263: 7506 JNZ 0x0072a26b
    if(integer::condition("JNZ",flags)) goto L0072a26b;
  }
  { // 0x72a265: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x72a266: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72a267: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x72a26a: c3 RET
    finish(m,s,f,0u); return;
  }
  L0072a26b: { // 0x72a26b: 8b0d50deb000 MOV ECX,dword ptr [0x00b0de50]
    s.cx = m.r32((0x00b0de50u));
  }
  { // 0x72a271: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  { // 0x72a275: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72a276: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x72a277: ff15b8547800 CALL dword ptr [0x007854b8]
    const std::uint32_t call_target=m.r32((0x007854b8u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x72a27d: a150deb000 MOV EAX,[0x00b0de50]
    s.ax = m.r32((0x00b0de50u));
  }
  { // 0x72a282: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x72a286: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x72a287: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72a288: ff15ac547800 CALL dword ptr [0x007854ac]
    const std::uint32_t call_target=m.r32((0x007854acu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x72a28e: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x72a290: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x72a293: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x72a297: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x72a299: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x72a29b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x72a29f: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  { // 0x72a2a1: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x72a2a4: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  { // 0x72a2a7: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x72a2aa: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x72a2ac: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x72a2ae: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x72a2b0: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  { // 0x72a2b3: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  { // 0x72a2b6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x72a2b7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72a2b8: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x72a2bb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0032a760(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72a760: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72a761: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x72a763: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x72a765: 6880a77200 PUSH 0x72a780
    f.push(m,0x0072a780u);
  }
  { // 0x72a76a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72a76b: ff15dc547800 CALL dword ptr [0x007854dc]
    const std::uint32_t call_target=m.r32((0x007854dcu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x72a771: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x72a773: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72a774: e807000000 CALL 0x0072a780
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x72a779: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72a77a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0032b440(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72b440: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72b441: 8b710c MOV ESI,dword ptr [ECX + 0xc]
    s.si = m.r32((s.cx+0x0000000cu));
  }
  { // 0x72b444: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72b445: ff1528547800 CALL dword ptr [0x00785428]
    const std::uint32_t call_target=m.r32((0x00785428u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x72b44b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72b44c: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x72b44e: 68fc687e00 PUSH 0x7e68fc
    f.push(m,0x007e68fcu);
  }
  { // 0x72b453: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72b454: ff152c547800 CALL dword ptr [0x0078542c]
    const std::uint32_t call_target=m.r32((0x0078542cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x72b45a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72b45b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0032b460(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72b460: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x72b463: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72b464: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x72b466: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x72b468: 6af4 PUSH -0xc
    f.push(m,0xfffffff4u);
  }
  { // 0x72b46a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72b46b: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  { // 0x72b46f: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  { // 0x72b473: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  { // 0x72b477: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  { // 0x72b47b: ff158c547800 CALL dword ptr [0x0078548c]
    const std::uint32_t call_target=m.r32((0x0078548cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x72b481: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72b482: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  { // 0x72b486: ff1528547800 CALL dword ptr [0x00785428]
    const std::uint32_t call_target=m.r32((0x00785428u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x72b48c: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  { // 0x72b490: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x72b494: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72b495: 6a0a PUSH 0xa
    f.push(m,0x0000000au);
  }
  { // 0x72b497: 68fc687e00 PUSH 0x7e68fc
    f.push(m,0x007e68fcu);
  }
  { // 0x72b49c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72b49d: ff152c547800 CALL dword ptr [0x0078542c]
    const std::uint32_t call_target=m.r32((0x0078542cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x72b4a3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72b4a4: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x72b4a7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0032ba30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72ba30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72ba31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x72ba33: 8b0da81f8200 MOV ECX,dword ptr [0x00821fa8]
    s.cx = m.r32((0x00821fa8u));
  }
  { // 0x72ba39: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x72ba3b: 7421 JZ 0x0072ba5e
    if(integer::condition("JZ",flags)) goto L0072ba5e;
  }
  { // 0x72ba3d: 6685d2 TEST DX,DX
    (void)integer::logical(((s.dx & 0xffffu))&((s.dx & 0xffffu)),16,flags);
  }
  { // 0x72ba40: 7507 JNZ 0x0072ba49
    if(integer::condition("JNZ",flags)) goto L0072ba49;
  }
  { // 0x72ba42: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x72ba44: ff5018 CALL dword ptr [EAX + 0x18]
    const std::uint32_t call_target=m.r32((s.ax+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x72ba47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72ba48: c3 RET
    finish(m,s,f,0u); return;
  }
  L0072ba49: { // 0x72ba49: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x72ba4b: ff5214 CALL dword ptr [EDX + 0x14]
    const std::uint32_t call_target=m.r32((s.dx+0x00000014u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x72ba4e: 6887050000 PUSH 0x587
    f.push(m,0x00000587u);
  }
  { // 0x72ba53: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x72ba55: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x72ba57: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72ba58: ff1524547800 CALL dword ptr [0x00785424]
    const std::uint32_t call_target=m.r32((0x00785424u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L0072ba5e: { // 0x72ba5e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72ba5f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0032bc20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72bc20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72bc21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x72bc23: 6af8 PUSH -0x8
    f.push(m,0xfffffff8u);
  }
  { // 0x72bc25: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72bc26: ff158c547800 CALL dword ptr [0x0078548c]
    const std::uint32_t call_target=m.r32((0x0078548cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x72bc2c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x72bc2e: 7409 JZ 0x0072bc39
    if(integer::condition("JZ",flags)) goto L0072bc39;
  }
  { // 0x72bc30: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x72bc32: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x72bc34: e807000000 CALL 0x0072bc40
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0072bc39: { // 0x72bc39: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72bc3a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0032c620(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72c620: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x72c623: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x72c627: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72c628: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72c629: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x72c62b: 68e0397c00 PUSH 0x7c39e0
    f.push(m,0x007c39e0u);
  }
  { // 0x72c630: ff15e8507800 CALL dword ptr [0x007850e8]
    const std::uint32_t call_target=m.r32((0x007850e8u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x72c636: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x72c638: 744e JZ 0x0072c688
    if(integer::condition("JZ",flags)) goto L0072c688;
  }
  { // 0x72c63a: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x72c63e: 8b54240e MOV EDX,dword ptr [ESP + 0xe]
    s.dx = m.r32((f.sp+0x0000000eu));
  }
  { // 0x72c642: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x72c646: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  { // 0x72c64c: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  { // 0x72c652: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x72c653: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x72c657: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  { // 0x72c65c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x72c65d: 8b542412 MOV EDX,dword ptr [ESP + 0x12]
    s.dx = m.r32((f.sp+0x00000012u));
  }
  { // 0x72c661: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72c662: 8b442412 MOV EAX,dword ptr [ESP + 0x12]
    s.ax = m.r32((f.sp+0x00000012u));
  }
  { // 0x72c666: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  { // 0x72c66c: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  { // 0x72c672: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x72c673: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  { // 0x72c678: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x72c679: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72c67a: 68006a7e00 PUSH 0x7e6a00
    f.push(m,0x007e6a00u);
  }
  { // 0x72c67f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72c680: e8af130400 CALL 0x0076da34
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x72c685: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0072c688: { // 0x72c688: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72c689: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x72c68c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00330d00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x730d00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x730d01: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x730d03: bae0b67300 MOV EDX,0x73b6e0
    s.dx = 0x0073b6e0u;
  }
  { // 0x730d08: b9cf000000 MOV ECX,0xcf
    s.cx = 0x000000cfu;
  }
  { // 0x730d0d: e8be65ecff CALL 0x005f72d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x730d12: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  { // 0x730d18: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x730d1a: c6058489a20001 MOV byte ptr [0x00a28984],0x1
    m.w8((0x00a28984u), 0x00000001u);
  }
  { // 0x730d21: e82affdfff CALL 0x00530c50
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x730d26: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x730d28: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x730d29: ff1598547800 CALL dword ptr [0x00785498]
    const std::uint32_t call_target=m.r32((0x00785498u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x730d2f: ba707d5f00 MOV EDX,0x5f7d70
    s.dx = 0x005f7d70u;
  }
  { // 0x730d34: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x730d36: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x730d38: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x730d3a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x730d3c: e85f98ffff CALL 0x0072a5a0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x730d41: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  { // 0x730d47: e804ffdfff CALL 0x00530c50
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x730d4c: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x730d51: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x730d53: 8a8806230000 MOV CL,byte ptr [EAX + 0x2306]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00002306u)));
  }
  { // 0x730d59: 880d8489a200 MOV byte ptr [0x00a28984],CL
    m.w8((0x00a28984u), (s.cx & 0xffu));
  }
  { // 0x730d5f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x730d64: e8c7f2daff CALL 0x004e0030
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x730d69: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x730d6a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0033ee50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x73ee50: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x73ee51: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x73ee53: b9c4000000 MOV ECX,0xc4
    s.cx = 0x000000c4u;
  }
  { // 0x73ee58: e8a3b6feff CALL 0x0072a500
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x73ee5d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x73ee5f: 7414 JZ 0x0073ee75
    if(integer::condition("JZ",flags)) goto L0073ee75;
  }
  { // 0x73ee61: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x73ee62: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x73ee64: 68b2040000 PUSH 0x4b2
    f.push(m,0x000004b2u);
  }
  { // 0x73ee69: 68b2050000 PUSH 0x5b2
    f.push(m,0x000005b2u);
  }
  { // 0x73ee6e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x73ee6f: ff1584547800 CALL dword ptr [0x00785484]
    const std::uint32_t call_target=m.r32((0x00785484u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0073ee75: { // 0x73ee75: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x73ee76: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0034a170(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x74a170: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x74a171: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x74a172: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x74a173: e85805feff CALL 0x0072a6d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x74a178: 689f050000 PUSH 0x59f
    f.push(m,0x0000059fu);
  }
  { // 0x74a17d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x74a17e: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x74a184: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x74a188: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x74a18a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x74a18c: e8cff00000 CALL 0x00759260
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x74a191: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x74a195: e89681feff CALL 0x00732330
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x74a19a: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x74a19d: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x74a1a1: 0f95c3 SETNZ BL
    s.bx = with_al(s.bx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x74a1a4: e877f10000 CALL 0x00759320
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x74a1a9: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x74a1ab: 7431 JZ 0x0074a1de
    if(integer::condition("JZ",flags)) goto L0074a1de;
  }
  { // 0x74a1ad: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x74a1af: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x74a1b1: 68dc040000 PUSH 0x4dc
    f.push(m,0x000004dcu);
  }
  { // 0x74a1b6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x74a1b7: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x74a1bd: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x74a1bf: b960117d00 MOV ECX,0x7d1160
    s.cx = 0x007d1160u;
  }
  { // 0x74a1c4: 68f34d0000 PUSH 0x4df3
    f.push(m,0x00004df3u);
  }
  { // 0x74a1c9: 68bc6c7e00 PUSH 0x7e6cbc
    f.push(m,0x007e6cbcu);
  }
  { // 0x74a1ce: e88d49faff CALL 0x006eeb60
    const std::uint32_t call_target=f.boundaries[6u].target;
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  { // 0x74a1d3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x74a1d4: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x74a1d6: e83536e7ff CALL 0x005bd810
    const std::uint32_t call_target=f.boundaries[7u].target;
    invoke(m,s,f,op,7u,call_target); flags=0x202u;
  }
  { // 0x74a1db: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0074a1de: { // 0x74a1de: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x74a1df: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x74a1e0: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x74a1e1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0034a1f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x74a1f0: e8db04feff CALL 0x0072a6d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x74a1f5: 689f050000 PUSH 0x59f
    f.push(m,0x0000059fu);
  }
  { // 0x74a1fa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x74a1fb: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x74a201: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x74a203: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x74a205: 68dc040000 PUSH 0x4dc
    f.push(m,0x000004dcu);
  }
  { // 0x74a20a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x74a20b: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x74a211: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003529f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7529f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7529f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x7529f3: 8d4608 LEA EAX,[ESI + 0x8]
    s.ax = (s.si+0x00000008u);
  }
  { // 0x7529f6: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x7529fd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7529fe: ff15e8517800 CALL dword ptr [0x007851e8]
    const std::uint32_t call_target=m.r32((0x007851e8u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x752a04: 68fce7b000 PUSH 0xb0e7fc
    f.push(m,0x00b0e7fcu);
  }
  { // 0x752a09: c706dca77900 MOV dword ptr [ESI],0x79a7dc
    m.w32((s.si), 0x0079a7dcu);
  }
  { // 0x752a0f: ff15bc517800 CALL dword ptr [0x007851bc]
    const std::uint32_t call_target=m.r32((0x007851bcu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x752a15: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x752a17: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x752a18: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_003549a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7549a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7549a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x7549a3: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x7549a6: c70614a87900 MOV dword ptr [ESI],0x79a814
    m.w32((s.si), 0x0079a814u);
  }
  { // 0x7549ac: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x7549ae: 7406 JZ 0x007549b6
    if(integer::condition("JZ",flags)) goto L007549b6;
  }
  { // 0x7549b0: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x7549b2: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x7549b4: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L007549b6: { // 0x7549b6: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x7549b9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x7549bb: 7406 JZ 0x007549c3
    if(integer::condition("JZ",flags)) goto L007549c3;
  }
  { // 0x7549bd: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x7549bf: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x7549c1: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L007549c3: { // 0x7549c3: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  { // 0x7549c6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x7549c8: 7406 JZ 0x007549d0
    if(integer::condition("JZ",flags)) goto L007549d0;
  }
  { // 0x7549ca: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x7549cc: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x7549ce: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L007549d0: { // 0x7549d0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x7549d2: e8b943eaff CALL 0x005f8d90
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x7549d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7549d8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003558e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7558e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7558e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x7558e3: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x7558e6: c70614a87900 MOV dword ptr [ESI],0x79a814
    m.w32((s.si), 0x0079a814u);
  }
  { // 0x7558ec: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x7558ee: 7406 JZ 0x007558f6
    if(integer::condition("JZ",flags)) goto L007558f6;
  }
  { // 0x7558f0: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x7558f2: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x7558f4: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L007558f6: { // 0x7558f6: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x7558f9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x7558fb: 7406 JZ 0x00755903
    if(integer::condition("JZ",flags)) goto L00755903;
  }
  { // 0x7558fd: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x7558ff: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x755901: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00755903: { // 0x755903: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  { // 0x755906: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x755908: 7406 JZ 0x00755910
    if(integer::condition("JZ",flags)) goto L00755910;
  }
  { // 0x75590a: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x75590c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x75590e: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00755910: { // 0x755910: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x755912: e87934eaff CALL 0x005f8d90
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x755917: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x75591c: 7409 JZ 0x00755927
    if(integer::condition("JZ",flags)) goto L00755927;
  }
  { // 0x75591e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75591f: e8577d0100 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x755924: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00755927: { // 0x755927: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x755929: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75592a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00356f40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x756f40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x756f41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x756f43: 8a8668380400 MOV AL,byte ptr [ESI + 0x43868]
    s.ax = with_al(s.ax, m.r8((s.si+0x00043868u)));
  }
  { // 0x756f49: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x756f4b: 7418 JZ 0x00756f65
    if(integer::condition("JZ",flags)) goto L00756f65;
  }
  { // 0x756f4d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x756f4f: ff5020 CALL dword ptr [EAX + 0x20]
    const std::uint32_t call_target=m.r32((s.ax+0x00000020u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x756f52: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x756f54: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x756f56: ff5204 CALL dword ptr [EDX + 0x4]
    const std::uint32_t call_target=m.r32((s.dx+0x00000004u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x756f59: e896650100 CALL 0x0076d4f4
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x756f5e: c6866838040000 MOV byte ptr [ESI + 0x43868],0x0
    m.w8((s.si+0x00043868u), 0x00000000u);
  }
  L00756f65: { // 0x756f65: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x756f66: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00356fb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x756fb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x756fb1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x756fb3: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x756fb5: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x756fb7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x756fb9: ff5038 CALL dword ptr [EAX + 0x38]
    const std::uint32_t call_target=m.r32((s.ax+0x00000038u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x756fbc: 8b0d50deb000 MOV ECX,dword ptr [0x00b0de50]
    s.cx = m.r32((0x00b0de50u));
  }
  { // 0x756fc2: 8b966c380400 MOV EDX,dword ptr [ESI + 0x4386c]
    s.dx = m.r32((s.si+0x0004386cu));
  }
  { // 0x756fc8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x756fc9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x756fca: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x756fcb: e82a650100 CALL 0x0076d4fa
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x756fd0: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x756fd3: 7511 JNZ 0x00756fe6
    if(integer::condition("JNZ",flags)) goto L00756fe6;
  }
  { // 0x756fd5: 685c917e00 PUSH 0x7e915c
    f.push(m,0x007e915cu);
  }
  { // 0x756fda: e811f9caff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x756fdf: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x756fe2: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x756fe4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x756fe5: c3 RET
    finish(m,s,f,0u); return;
  }
  L00756fe6: { // 0x756fe6: 8b8670380400 MOV EAX,dword ptr [ESI + 0x43870]
    s.ax = m.r32((s.si+0x00043870u));
  }
  { // 0x756fec: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x756fef: 7433 JZ 0x00757024
    if(integer::condition("JZ",flags)) goto L00757024;
  }
  { // 0x756ff1: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x756ff3: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x756ff5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x756ff6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x756ff8: ff5238 CALL dword ptr [EDX + 0x38]
    const std::uint32_t call_target=m.r32((s.dx+0x00000038u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x756ffb: 8b8e70380400 MOV ECX,dword ptr [ESI + 0x43870]
    s.cx = m.r32((s.si+0x00043870u));
  }
  { // 0x757001: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x757002: a150deb000 MOV EAX,[0x00b0de50]
    s.ax = m.r32((0x00b0de50u));
  }
  { // 0x757007: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x757008: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x757009: e8ec640100 CALL 0x0076d4fa
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x75700e: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x757011: 7511 JNZ 0x00757024
    if(integer::condition("JNZ",flags)) goto L00757024;
  }
  { // 0x757013: 6830917e00 PUSH 0x7e9130
    f.push(m,0x007e9130u);
  }
  { // 0x757018: e8d3f8caff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x75701d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x757020: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x757022: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x757023: c3 RET
    finish(m,s,f,0u); return;
  }
  L00757024: { // 0x757024: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x757026: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x757027: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0035ef70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75ef70: a1f803b100 MOV EAX,[0x00b103f8]
    s.ax = m.r32((0x00b103f8u));
  }
  { // 0x75ef75: 6810270000 PUSH 0x2710
    f.push(m,0x00002710u);
  }
  { // 0x75ef7a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75ef7b: ff15d0517800 CALL dword ptr [0x007851d0]
    const std::uint32_t call_target=m.r32((0x007851d0u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75ef81: 3d02010000 CMP EAX,0x102
    (void)integer::sub(s.ax,0x00000102u,32,flags);
  }
  { // 0x75ef86: 7517 JNZ 0x0075ef9f
    if(integer::condition("JNZ",flags)) goto L0075ef9f;
  }
  { // 0x75ef88: 68fd040000 PUSH 0x4fd
    f.push(m,0x000004fdu);
  }
  { // 0x75ef8d: 689c967e00 PUSH 0x7e969c
    f.push(m,0x007e969cu);
  }
  { // 0x75ef92: 685c967e00 PUSH 0x7e965c
    f.push(m,0x007e965cu);
  }
  { // 0x75ef97: e85479caff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x75ef9c: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0075ef9f: { // 0x75ef9f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0035f0d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75f0d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75f0d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75f0d3: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x75f0d6: c706bc897800 MOV dword ptr [ESI],0x7889bc
    m.w32((s.si), 0x007889bcu);
  }
  { // 0x75f0dc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x75f0de: 7417 JZ 0x0075f0f7
    if(integer::condition("JZ",flags)) goto L0075f0f7;
  }
  { // 0x75f0e0: 8a4610 MOV AL,byte ptr [ESI + 0x10]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000010u)));
  }
  { // 0x75f0e3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x75f0e5: 7410 JZ 0x0075f0f7
    if(integer::condition("JZ",flags)) goto L0075f0f7;
  }
  { // 0x75f0e7: c6461000 MOV byte ptr [ESI + 0x10],0x0
    m.w8((s.si+0x00000010u), 0x00000000u);
  }
  { // 0x75f0eb: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x75f0ed: ff5034 CALL dword ptr [EAX + 0x34]
    const std::uint32_t call_target=m.r32((s.ax+0x00000034u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75f0f0: c7460c00000000 MOV dword ptr [ESI + 0xc],0x0
    m.w32((s.si+0x0000000cu), 0x00000000u);
  }
  L0075f0f7: { // 0x75f0f7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x75f0f9: e84275eaff CALL 0x00606640
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x75f0fe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75f0ff: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0035f100(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75f100: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75f101: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75f103: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75f104: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x75f106: ff5004 CALL dword ptr [EAX + 0x4]
    const std::uint32_t call_target=m.r32((s.ax+0x00000004u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75f109: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x75f10c: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x75f10e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x75f110: 7410 JZ 0x0075f122
    if(integer::condition("JZ",flags)) goto L0075f122;
  }
  { // 0x75f112: 8a4610 MOV AL,byte ptr [ESI + 0x10]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000010u)));
  }
  { // 0x75f115: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x75f117: 7409 JZ 0x0075f122
    if(integer::condition("JZ",flags)) goto L0075f122;
  }
  { // 0x75f119: c6461000 MOV byte ptr [ESI + 0x10],0x0
    m.w8((s.si+0x00000010u), 0x00000000u);
  }
  { // 0x75f11d: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x75f11f: ff5234 CALL dword ptr [EDX + 0x34]
    const std::uint32_t call_target=m.r32((s.dx+0x00000034u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0075f122: { // 0x75f122: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x75f124: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75f125: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75f126: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0035f130(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75f130: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75f131: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75f132: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75f134: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75f135: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x75f138: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x75f13a: 7437 JZ 0x0075f173
    if(integer::condition("JZ",flags)) goto L0075f173;
  }
  { // 0x75f13c: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  { // 0x75f140: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x75f142: 742f JZ 0x0075f173
    if(integer::condition("JZ",flags)) goto L0075f173;
  }
  { // 0x75f144: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x75f148: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x75f14a: 7e27 JLE 0x0075f173
    if(integer::condition("JLE",flags)) goto L0075f173;
  }
  { // 0x75f14c: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x75f14e: ff5018 CALL dword ptr [EAX + 0x18]
    const std::uint32_t call_target=m.r32((s.ax+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75f151: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x75f153: 750e JNZ 0x0075f163
    if(integer::condition("JNZ",flags)) goto L0075f163;
  }
  { // 0x75f155: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x75f158: c6461001 MOV byte ptr [ESI + 0x10],0x1
    m.w8((s.si+0x00000010u), 0x00000001u);
  }
  { // 0x75f15c: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x75f15e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x75f160: ff521c CALL dword ptr [EDX + 0x1c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000001cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0075f163: { // 0x75f163: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x75f166: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75f167: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75f168: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x75f16a: ff5030 CALL dword ptr [EAX + 0x30]
    const std::uint32_t call_target=m.r32((s.ax+0x00000030u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x75f16d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75f16e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75f16f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75f170: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0075f173: { // 0x75f173: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75f174: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75f175: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x75f177: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75f178: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0035f1e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75f1e0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75f1e1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75f1e2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75f1e4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75f1e5: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x75f1e8: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x75f1ea: 7449 JZ 0x0075f235
    if(integer::condition("JZ",flags)) goto L0075f235;
  }
  { // 0x75f1ec: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  { // 0x75f1f0: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x75f1f2: 7441 JZ 0x0075f235
    if(integer::condition("JZ",flags)) goto L0075f235;
  }
  { // 0x75f1f4: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x75f1f8: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x75f1fa: 7e39 JLE 0x0075f235
    if(integer::condition("JLE",flags)) goto L0075f235;
  }
  { // 0x75f1fc: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x75f1fe: ff5018 CALL dword ptr [EAX + 0x18]
    const std::uint32_t call_target=m.r32((s.ax+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75f201: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x75f203: 7520 JNZ 0x0075f225
    if(integer::condition("JNZ",flags)) goto L0075f225;
  }
  { // 0x75f205: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x75f208: c6461001 MOV byte ptr [ESI + 0x10],0x1
    m.w8((s.si+0x00000010u), 0x00000001u);
  }
  { // 0x75f20c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x75f20e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x75f210: ff5214 CALL dword ptr [EDX + 0x14]
    const std::uint32_t call_target=m.r32((s.dx+0x00000014u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x75f213: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x75f215: 741e JZ 0x0075f235
    if(integer::condition("JZ",flags)) goto L0075f235;
  }
  { // 0x75f217: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x75f21a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x75f21c: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x75f21e: ff501c CALL dword ptr [EAX + 0x1c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000001cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x75f221: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75f223: 7410 JZ 0x0075f235
    if(integer::condition("JZ",flags)) goto L0075f235;
  }
  L0075f225: { // 0x75f225: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x75f228: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75f229: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75f22a: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x75f22c: ff5224 CALL dword ptr [EDX + 0x24]
    const std::uint32_t call_target=m.r32((s.dx+0x00000024u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x75f22f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75f230: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75f231: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75f232: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0075f235: { // 0x75f235: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75f236: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75f237: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x75f239: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75f23a: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0035f240(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75f240: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75f241: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75f243: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x75f246: c706ac897800 MOV dword ptr [ESI],0x7889ac
    m.w32((s.si), 0x007889acu);
  }
  { // 0x75f24c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x75f24e: 7417 JZ 0x0075f267
    if(integer::condition("JZ",flags)) goto L0075f267;
  }
  { // 0x75f250: 8a4610 MOV AL,byte ptr [ESI + 0x10]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000010u)));
  }
  { // 0x75f253: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x75f255: 7410 JZ 0x0075f267
    if(integer::condition("JZ",flags)) goto L0075f267;
  }
  { // 0x75f257: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x75f259: ff5034 CALL dword ptr [EAX + 0x34]
    const std::uint32_t call_target=m.r32((s.ax+0x00000034u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75f25c: c6461000 MOV byte ptr [ESI + 0x10],0x0
    m.w8((s.si+0x00000010u), 0x00000000u);
  }
  { // 0x75f260: c7460c00000000 MOV dword ptr [ESI + 0xc],0x0
    m.w32((s.si+0x0000000cu), 0x00000000u);
  }
  L0075f267: { // 0x75f267: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x75f269: e84214f3ff CALL 0x006906b0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x75f26e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75f26f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0035fb10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75fb10: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x75fb14: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75fb15: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75fb16: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75fb18: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x75fb1b: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x75fb1d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x75fb1f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75fb20: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75fb21: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75fb22: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x75fb24: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x75fb26: ff525c CALL dword ptr [EDX + 0x5c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000005cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75fb29: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x75fb2b: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x75fb2d: 7429 JZ 0x0075fb58
    if(integer::condition("JZ",flags)) goto L0075fb58;
  }
  { // 0x75fb2f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x75fb31: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x75fb33: ff5270 CALL dword ptr [EDX + 0x70]
    const std::uint32_t call_target=m.r32((s.dx+0x00000070u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x75fb36: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x75fb39: 7512 JNZ 0x0075fb4d
    if(integer::condition("JNZ",flags)) goto L0075fb4d;
  }
  { // 0x75fb3b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x75fb3d: 668b1f MOV BX,word ptr [EDI]
    s.bx = with_ax(s.bx, m.r16((s.di)));
  }
  { // 0x75fb40: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x75fb42: ff5060 CALL dword ptr [EAX + 0x60]
    const std::uint32_t call_target=m.r32((s.ax+0x00000060u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x75fb45: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75fb46: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x75fb48: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75fb49: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75fb4a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0075fb4d: { // 0x75fb4d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x75fb4f: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x75fb51: 8a1f MOV BL,byte ptr [EDI]
    s.bx = with_al(s.bx, m.r8((s.di)));
  }
  { // 0x75fb53: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x75fb55: ff5060 CALL dword ptr [EAX + 0x60]
    const std::uint32_t call_target=m.r32((s.ax+0x00000060u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L0075fb58: { // 0x75fb58: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75fb59: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x75fb5b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75fb5c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75fb5d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035fb60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75fb60: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x75fb64: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75fb65: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75fb67: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75fb68: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x75fb6b: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x75fb6d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x75fb6f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75fb70: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75fb71: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x75fb73: ff525c CALL dword ptr [EDX + 0x5c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000005cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75fb76: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x75fb78: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x75fb7a: 7436 JZ 0x0075fbb2
    if(integer::condition("JZ",flags)) goto L0075fbb2;
  }
  { // 0x75fb7c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x75fb7e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x75fb80: ff5270 CALL dword ptr [EDX + 0x70]
    const std::uint32_t call_target=m.r32((s.dx+0x00000070u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x75fb83: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x75fb86: 7516 JNZ 0x0075fb9e
    if(integer::condition("JNZ",flags)) goto L0075fb9e;
  }
  { // 0x75fb88: 668b442410 MOV AX,word ptr [ESP + 0x10]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000010u)));
  }
  { // 0x75fb8d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x75fb8f: 668907 MOV word ptr [EDI],AX
    m.w16((s.di), (s.ax & 0xffffu));
  }
  { // 0x75fb92: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x75fb94: ff5260 CALL dword ptr [EDX + 0x60]
    const std::uint32_t call_target=m.r32((s.dx+0x00000060u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x75fb97: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75fb98: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x75fb9a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75fb9b: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0075fb9e: { // 0x75fb9e: 8a4c2410 MOV CL,byte ptr [ESP + 0x10]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000010u)));
  }
  { // 0x75fba2: 880f MOV byte ptr [EDI],CL
    m.w8((s.di), (s.cx & 0xffu));
  }
  { // 0x75fba4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x75fba6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x75fba8: ff5260 CALL dword ptr [EDX + 0x60]
    const std::uint32_t call_target=m.r32((s.dx+0x00000060u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x75fbab: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75fbac: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x75fbae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75fbaf: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0075fbb2: { // 0x75fbb2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75fbb3: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x75fbb5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75fbb6: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0035fcd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75fcd0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x75fcd4: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x75fcd7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75fcd8: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75fcda: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75fcdb: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  { // 0x75fcdf: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x75fce1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75fce2: ff5278 CALL dword ptr [EDX + 0x78]
    const std::uint32_t call_target=m.r32((s.dx+0x00000078u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75fce5: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x75fce9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75fcea: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75fceb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x75fced: e80e000000 CALL 0x0075fd00
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x75fcf2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75fcf3: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x75fcf6: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00360760(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x760760: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x760764: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x760767: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x760768: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x76076a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76076b: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x76076f: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x760771: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x760772: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x760773: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x760775: ff5778 CALL dword ptr [EDI + 0x78]
    const std::uint32_t call_target=m.r32((s.di+0x00000078u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x760778: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x76077a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76077b: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  { // 0x76077f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x760781: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x760782: ff5278 CALL dword ptr [EDX + 0x78]
    const std::uint32_t call_target=m.r32((s.dx+0x00000078u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x760785: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x760786: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x760788: ff5710 CALL dword ptr [EDI + 0x10]
    const std::uint32_t call_target=m.r32((s.di+0x00000010u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x76078b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x76078c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76078d: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x760790: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00361c80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x761c80: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x761c84: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x761c85: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x761c87: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x761c88: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x761c89: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x761c8d: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x761c90: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x761c91: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x761c93: ff505c CALL dword ptr [EAX + 0x5c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000005cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x761c96: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x761c99: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x761c9b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x761c9d: ff5060 CALL dword ptr [EAX + 0x60]
    const std::uint32_t call_target=m.r32((s.ax+0x00000060u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x761ca0: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x761ca3: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  { // 0x761ca6: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x761ca8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x761caa: 7203 JC 0x00761caf
    if(integer::condition("JC",flags)) goto L00761caf;
  }
  { // 0x761cac: 2b4620 SUB EAX,dword ptr [ESI + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x00000020u)),32,flags);
  }
  L00761caf: { // 0x761caf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x761cb0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x761cb1: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00361d60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x761d60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x761d61: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x761d63: f686bc07000040 TEST byte ptr [ESI + 0x7bc],0x40
    (void)integer::logical((m.r8((s.si+0x000007bcu)))&(0x00000040u),8,flags);
  }
  { // 0x761d6a: 741b JZ 0x00761d87
    if(integer::condition("JZ",flags)) goto L00761d87;
  }
  { // 0x761d6c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x761d6e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x761d70: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  { // 0x761d72: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x761d73: ff5658 CALL dword ptr [ESI + 0x58]
    const std::uint32_t call_target=m.r32((s.si+0x00000058u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x761d76: 8b86bc070000 MOV EAX,dword ptr [ESI + 0x7bc]
    s.ax = m.r32((s.si+0x000007bcu));
  }
  { // 0x761d7c: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x761d7f: 24bf AND AL,0xbf
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000bfu),8,flags));
  }
  { // 0x761d81: 8986bc070000 MOV dword ptr [ESI + 0x7bc],EAX
    m.w32((s.si+0x000007bcu), s.ax);
  }
  L00761d87: { // 0x761d87: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x761d89: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x761d8b: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x761d8d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x761d8e: ff5658 CALL dword ptr [ESI + 0x58]
    const std::uint32_t call_target=m.r32((s.si+0x00000058u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x761d91: 8b86bc070000 MOV EAX,dword ptr [ESI + 0x7bc]
    s.ax = m.r32((s.si+0x000007bcu));
  }
  { // 0x761d97: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x761d9a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x761d9c: 81e100000080 AND ECX,0x80000000
    s.cx = integer::logical((s.cx)&(0x80000000u),32,flags);
  }
  { // 0x761da2: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  { // 0x761da5: 750b JNZ 0x00761db2
    if(integer::condition("JNZ",flags)) goto L00761db2;
  }
  { // 0x761da7: 25ffffff7f AND EAX,0x7fffffff
    s.ax = integer::logical((s.ax)&(0x7fffffffu),32,flags);
  }
  { // 0x761dac: 8986bc070000 MOV dword ptr [ESI + 0x7bc],EAX
    m.w32((s.si+0x000007bcu), s.ax);
  }
  L00761db2: { // 0x761db2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x761db3: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00366890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x766890: 8b8164070000 MOV EAX,dword ptr [ECX + 0x764]
    s.ax = m.r32((s.cx+0x00000764u));
  }
  { // 0x766896: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x766898: 7419 JZ 0x007668b3
    if(integer::condition("JZ",flags)) goto L007668b3;
  }
  { // 0x76689a: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  { // 0x76689b: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  { // 0x76689e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x76689f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7668a0: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  { // 0x7668a2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7668a3: ff5140 CALL dword ptr [ECX + 0x40]
    const std::uint32_t call_target=m.r32((s.cx+0x00000040u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x7668a6: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x7668a9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7668ab: 7420 JZ 0x007668cd
    if(integer::condition("JZ",flags)) goto L007668cd;
  }
  { // 0x7668ad: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  { // 0x7668b2: c3 RET
    finish(m,s,f,0u); return;
  }
  L007668b3: { // 0x7668b3: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  { // 0x7668b4: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  { // 0x7668b7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x7668b8: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x7668ba: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  { // 0x7668bc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7668bd: ff5140 CALL dword ptr [ECX + 0x40]
    const std::uint32_t call_target=m.r32((s.cx+0x00000040u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x7668c0: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x7668c3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7668c5: 7406 JZ 0x007668cd
    if(integer::condition("JZ",flags)) goto L007668cd;
  }
  { // 0x7668c7: b8faffffff MOV EAX,0xfffffffa
    s.ax = 0xfffffffau;
  }
  { // 0x7668cc: c3 RET
    finish(m,s,f,0u); return;
  }
  L007668cd: { // 0x7668cd: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x7668d0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036df28(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76df28: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76df29: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x76df2d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x76df2f: 743d JZ 0x0076df6e
    if(integer::condition("JZ",flags)) goto L0076df6e;
  }
  { // 0x76df31: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  { // 0x76df33: e87e360000 CALL 0x007715b6
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x76df38: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76df39: e83f540000 CALL 0x0077337d
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x76df3e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76df3f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x76df41: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76df42: 7413 JZ 0x0076df57
    if(integer::condition("JZ",flags)) goto L0076df57;
  }
  { // 0x76df44: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76df45: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76df46: e85d540000 CALL 0x007733a8
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x76df4b: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  { // 0x76df4d: e8c5360000 CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x76df52: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x76df55: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76df56: c3 RET
    finish(m,s,f,0u); return;
  }
  L0076df57: { // 0x76df57: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  { // 0x76df59: e8b9360000 CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x76df5e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76df5f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76df60: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x76df62: ff351c0eb100 PUSH dword ptr [0x00b10e1c]
    f.push(m,m.r32((0x00b10e1cu)));
  }
  { // 0x76df68: ff1568527800 CALL dword ptr [0x00785268]
    const std::uint32_t call_target=m.r32((0x00785268u));
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  L0076df6e: { // 0x76df6e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76df6f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036dfae(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76dfae: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76dfaf: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x76dfb3: 3b3554758100 CMP ESI,dword ptr [0x00817554]
    (void)integer::sub(s.si,m.r32((0x00817554u)),32,flags);
  }
  { // 0x76dfb9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76dfba: 7721 JA 0x0076dfdd
    if(integer::condition("JA",flags)) goto L0076dfdd;
  }
  { // 0x76dfbc: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  { // 0x76dfbe: e8f3350000 CALL 0x007715b6
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x76dfc3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76dfc4: e80a570000 CALL 0x007736d3
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x76dfc9: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  { // 0x76dfcb: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x76dfcd: e845360000 CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x76dfd2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x76dfd5: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x76dfd7: 7404 JZ 0x0076dfdd
    if(integer::condition("JZ",flags)) goto L0076dfdd;
  }
  { // 0x76dfd9: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x76dfdb: eb1c JMP 0x0076dff9
    goto L0076dff9;
  }
  L0076dfdd: { // 0x76dfdd: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x76dfdf: 7503 JNZ 0x0076dfe4
    if(integer::condition("JNZ",flags)) goto L0076dfe4;
  }
  { // 0x76dfe1: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x76dfe3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076dfe4: { // 0x76dfe4: 83c60f ADD ESI,0xf
    s.si = integer::add(s.si,0x0000000fu,32,flags);
  }
  { // 0x76dfe7: 83e6f0 AND ESI,0xfffffff0
    s.si = integer::logical((s.si)&(0xfffffff0u),32,flags);
  }
  { // 0x76dfea: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76dfeb: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x76dfed: ff351c0eb100 PUSH dword ptr [0x00b10e1c]
    f.push(m,m.r32((0x00b10e1cu)));
  }
  { // 0x76dff3: ff1570527800 CALL dword ptr [0x00785270]
    const std::uint32_t call_target=m.r32((0x00785270u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L0076dff9: { // 0x76dff9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x76dffa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76dffb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036e313(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76e313: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x76e314: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x76e316: 391d3005b100 CMP dword ptr [0x00b10530],EBX
    (void)integer::sub(m.r32((0x00b10530u)),s.bx,32,flags);
  }
  { // 0x76e31c: 7513 JNZ 0x0076e331
    if(integer::condition("JNZ",flags)) goto L0076e331;
  }
  { // 0x76e31e: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x76e322: 83f861 CMP EAX,0x61
    (void)integer::sub(s.ax,0x00000061u,32,flags);
  }
  { // 0x76e325: 7c59 JL 0x0076e380
    if(integer::condition("JL",flags)) goto L0076e380;
  }
  { // 0x76e327: 83f87a CMP EAX,0x7a
    (void)integer::sub(s.ax,0x0000007au,32,flags);
  }
  { // 0x76e32a: 7f54 JG 0x0076e380
    if(integer::condition("JG",flags)) goto L0076e380;
  }
  { // 0x76e32c: 83e820 SUB EAX,0x20
    s.ax = integer::sub(s.ax,0x00000020u,32,flags);
  }
  { // 0x76e32f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x76e330: c3 RET
    finish(m,s,f,0u); return;
  }
  L0076e331: { // 0x76e331: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76e332: be240eb100 MOV ESI,0xb10e24
    s.si = 0x00b10e24u;
  }
  { // 0x76e337: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76e338: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76e339: ff15bc517800 CALL dword ptr [0x007851bc]
    const std::uint32_t call_target=m.r32((0x007851bcu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x76e33f: 391d200eb100 CMP dword ptr [0x00b10e20],EBX
    (void)integer::sub(m.r32((0x00b10e20u)),s.bx,32,flags);
  }
  { // 0x76e345: 8b3dc0517800 MOV EDI,dword ptr [0x007851c0]
    s.di = m.r32((0x007851c0u));
  }
  { // 0x76e34b: 740e JZ 0x0076e35b
    if(integer::condition("JZ",flags)) goto L0076e35b;
  }
  { // 0x76e34d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76e34e: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x76e350: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  { // 0x76e352: e85f320000 CALL 0x007715b6
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x76e357: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76e358: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x76e35a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076e35b: { // 0x76e35b: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x76e35f: e81e000000 CALL 0x0076e382
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x76e364: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x76e366: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76e367: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  { // 0x76e36b: 740a JZ 0x0076e377
    if(integer::condition("JZ",flags)) goto L0076e377;
  }
  { // 0x76e36d: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  { // 0x76e36f: e8a3320000 CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x76e374: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76e375: eb03 JMP 0x0076e37a
    goto L0076e37a;
  }
  L0076e377: { // 0x76e377: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76e378: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  L0076e37a: { // 0x76e37a: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x76e37e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x76e37f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076e380: { // 0x76e380: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x76e381: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036fb34(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76fb34: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x76fb35: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x76fb37: 391d3005b100 CMP dword ptr [0x00b10530],EBX
    (void)integer::sub(m.r32((0x00b10530u)),s.bx,32,flags);
  }
  { // 0x76fb3d: 7513 JNZ 0x0076fb52
    if(integer::condition("JNZ",flags)) goto L0076fb52;
  }
  { // 0x76fb3f: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x76fb43: 83f841 CMP EAX,0x41
    (void)integer::sub(s.ax,0x00000041u,32,flags);
  }
  { // 0x76fb46: 7c59 JL 0x0076fba1
    if(integer::condition("JL",flags)) goto L0076fba1;
  }
  { // 0x76fb48: 83f85a CMP EAX,0x5a
    (void)integer::sub(s.ax,0x0000005au,32,flags);
  }
  { // 0x76fb4b: 7f54 JG 0x0076fba1
    if(integer::condition("JG",flags)) goto L0076fba1;
  }
  { // 0x76fb4d: 83c020 ADD EAX,0x20
    s.ax = integer::add(s.ax,0x00000020u,32,flags);
  }
  { // 0x76fb50: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x76fb51: c3 RET
    finish(m,s,f,0u); return;
  }
  L0076fb52: { // 0x76fb52: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fb53: be240eb100 MOV ESI,0xb10e24
    s.si = 0x00b10e24u;
  }
  { // 0x76fb58: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76fb59: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fb5a: ff15bc517800 CALL dword ptr [0x007851bc]
    const std::uint32_t call_target=m.r32((0x007851bcu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x76fb60: 391d200eb100 CMP dword ptr [0x00b10e20],EBX
    (void)integer::sub(m.r32((0x00b10e20u)),s.bx,32,flags);
  }
  { // 0x76fb66: 8b3dc0517800 MOV EDI,dword ptr [0x007851c0]
    s.di = m.r32((0x007851c0u));
  }
  { // 0x76fb6c: 740e JZ 0x0076fb7c
    if(integer::condition("JZ",flags)) goto L0076fb7c;
  }
  { // 0x76fb6e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fb6f: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x76fb71: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  { // 0x76fb73: e83e1a0000 CALL 0x007715b6
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x76fb78: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76fb79: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x76fb7b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076fb7c: { // 0x76fb7c: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x76fb80: e81e000000 CALL 0x0076fba3
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x76fb85: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x76fb87: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76fb88: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  { // 0x76fb8c: 740a JZ 0x0076fb98
    if(integer::condition("JZ",flags)) goto L0076fb98;
  }
  { // 0x76fb8e: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  { // 0x76fb90: e8821a0000 CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x76fb95: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76fb96: eb03 JMP 0x0076fb9b
    goto L0076fb9b;
  }
  L0076fb98: { // 0x76fb98: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fb99: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  L0076fb9b: { // 0x76fb9b: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x76fb9f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x76fba0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076fba1: { // 0x76fba1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x76fba2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036ff39(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76ff39: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x76ff3d: b9d06f8100 MOV ECX,0x816fd0
    s.cx = 0x00816fd0u;
  }
  { // 0x76ff42: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x76ff44: 7217 JC 0x0076ff5d
    if(integer::condition("JC",flags)) goto L0076ff5d;
  }
  { // 0x76ff46: 3d30728100 CMP EAX,0x817230
    (void)integer::sub(s.ax,0x00817230u,32,flags);
  }
  { // 0x76ff4b: 7710 JA 0x0076ff5d
    if(integer::condition("JA",flags)) goto L0076ff5d;
  }
  { // 0x76ff4d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x76ff4f: c1f805 SAR EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x76ff52: 83c01c ADD EAX,0x1c
    s.ax = integer::add(s.ax,0x0000001cu,32,flags);
  }
  { // 0x76ff55: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76ff56: e85b160000 CALL 0x007715b6
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x76ff5b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76ff5c: c3 RET
    finish(m,s,f,0u); return;
  }
  L0076ff5d: { // 0x76ff5d: 83c020 ADD EAX,0x20
    s.ax = integer::add(s.ax,0x00000020u,32,flags);
  }
  { // 0x76ff60: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76ff61: ff15dc517800 CALL dword ptr [0x007851dc]
    const std::uint32_t call_target=m.r32((0x007851dcu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x76ff67: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036ff68(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76ff68: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x76ff6c: 83f814 CMP EAX,0x14
    (void)integer::sub(s.ax,0x00000014u,32,flags);
  }
  { // 0x76ff6f: 7d0b JGE 0x0076ff7c
    if(integer::condition("JGE",flags)) goto L0076ff7c;
  }
  { // 0x76ff71: 83c01c ADD EAX,0x1c
    s.ax = integer::add(s.ax,0x0000001cu,32,flags);
  }
  { // 0x76ff74: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76ff75: e83c160000 CALL 0x007715b6
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x76ff7a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76ff7b: c3 RET
    finish(m,s,f,0u); return;
  }
  L0076ff7c: { // 0x76ff7c: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x76ff80: 83c020 ADD EAX,0x20
    s.ax = integer::add(s.ax,0x00000020u,32,flags);
  }
  { // 0x76ff83: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76ff84: ff15dc517800 CALL dword ptr [0x007851dc]
    const std::uint32_t call_target=m.r32((0x007851dcu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x76ff8a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036ff8b(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76ff8b: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x76ff8f: b9d06f8100 MOV ECX,0x816fd0
    s.cx = 0x00816fd0u;
  }
  { // 0x76ff94: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x76ff96: 7217 JC 0x0076ffaf
    if(integer::condition("JC",flags)) goto L0076ffaf;
  }
  { // 0x76ff98: 3d30728100 CMP EAX,0x817230
    (void)integer::sub(s.ax,0x00817230u,32,flags);
  }
  { // 0x76ff9d: 7710 JA 0x0076ffaf
    if(integer::condition("JA",flags)) goto L0076ffaf;
  }
  { // 0x76ff9f: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x76ffa1: c1f805 SAR EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x76ffa4: 83c01c ADD EAX,0x1c
    s.ax = integer::add(s.ax,0x0000001cu,32,flags);
  }
  { // 0x76ffa7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76ffa8: e86a160000 CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x76ffad: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76ffae: c3 RET
    finish(m,s,f,0u); return;
  }
  L0076ffaf: { // 0x76ffaf: 83c020 ADD EAX,0x20
    s.ax = integer::add(s.ax,0x00000020u,32,flags);
  }
  { // 0x76ffb2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76ffb3: ff15e0517800 CALL dword ptr [0x007851e0]
    const std::uint32_t call_target=m.r32((0x007851e0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x76ffb9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036ffba(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76ffba: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x76ffbe: 83f814 CMP EAX,0x14
    (void)integer::sub(s.ax,0x00000014u,32,flags);
  }
  { // 0x76ffc1: 7d0b JGE 0x0076ffce
    if(integer::condition("JGE",flags)) goto L0076ffce;
  }
  { // 0x76ffc3: 83c01c ADD EAX,0x1c
    s.ax = integer::add(s.ax,0x0000001cu,32,flags);
  }
  { // 0x76ffc6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76ffc7: e84b160000 CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x76ffcc: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76ffcd: c3 RET
    finish(m,s,f,0u); return;
  }
  L0076ffce: { // 0x76ffce: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x76ffd2: 83c020 ADD EAX,0x20
    s.ax = integer::add(s.ax,0x00000020u,32,flags);
  }
  { // 0x76ffd5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76ffd6: ff15e0517800 CALL dword ptr [0x007851e0]
    const std::uint32_t call_target=m.r32((0x007851e0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x76ffdc: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003707af(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7707af: a1386f8100 MOV EAX,[0x00816f38]
    s.ax = m.r32((0x00816f38u));
  }
  { // 0x7707b4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7707b6: 7402 JZ 0x007707ba
    if(integer::condition("JZ",flags)) goto L007707ba;
  }
  { // 0x7707b8: ffd0 CALL EAX
    const std::uint32_t call_target=s.ax;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L007707ba: { // 0x7707ba: 6814787b00 PUSH 0x7b7814
    f.push(m,0x007b7814u);
  }
  { // 0x7707bf: 6800787b00 PUSH 0x7b7800
    f.push(m,0x007b7800u);
  }
  { // 0x7707c4: e80a010000 CALL 0x007708d3
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x7707c9: 68fc777b00 PUSH 0x7b77fc
    f.push(m,0x007b77fcu);
  }
  { // 0x7707ce: 6800407b00 PUSH 0x7b4000
    f.push(m,0x007b4000u);
  }
  { // 0x7707d3: e8fb000000 CALL 0x007708d3
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x7707d8: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x7707db: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00370cac(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x770cac: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x770cad: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x770caf: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x770cb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770cb1: be240eb100 MOV ESI,0xb10e24
    s.si = 0x00b10e24u;
  }
  { // 0x770cb6: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x770cb7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770cb8: ff15bc517800 CALL dword ptr [0x007851bc]
    const std::uint32_t call_target=m.r32((0x007851bcu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x770cbe: 8b3dc0517800 MOV EDI,dword ptr [0x007851c0]
    s.di = m.r32((0x007851c0u));
  }
  { // 0x770cc4: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x770cc6: 391d200eb100 CMP dword ptr [0x00b10e20],EBX
    (void)integer::sub(m.r32((0x00b10e20u)),s.bx,32,flags);
  }
  { // 0x770ccc: 740e JZ 0x00770cdc
    if(integer::condition("JZ",flags)) goto L00770cdc;
  }
  { // 0x770cce: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770ccf: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x770cd1: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  { // 0x770cd3: e8de080000 CALL 0x007715b6
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x770cd8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770cd9: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x770cdb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00770cdc: { // 0x770cdc: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x770cdf: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x770ce2: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x770ce5: e81f000000 CALL 0x00770d09
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x770cea: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x770ced: 894510 MOV dword ptr [EBP + 0x10],EAX
    m.w32((s.bp+0x00000010u), s.ax);
  }
  { // 0x770cf0: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x770cf2: 740a JZ 0x00770cfe
    if(integer::condition("JZ",flags)) goto L00770cfe;
  }
  { // 0x770cf4: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  { // 0x770cf6: e81c090000 CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x770cfb: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770cfc: eb03 JMP 0x00770d01
    goto L00770d01;
  }
  L00770cfe: { // 0x770cfe: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770cff: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  L00770d01: { // 0x770d01: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  { // 0x770d04: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x770d05: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x770d06: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x770d07: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x770d08: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00370f78(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x770f78: ff742404 PUSH dword ptr [ESP + 0x4]
    f.push(m,m.r32((f.sp+0x00000004u)));
  }
  { // 0x770f7c: ff15cc507800 CALL dword ptr [0x007850cc]
    const std::uint32_t call_target=m.r32((0x007850ccu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x770f82: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x770f84: 7508 JNZ 0x00770f8e
    if(integer::condition("JNZ",flags)) goto L00770f8e;
  }
  { // 0x770f86: ff15f4517800 CALL dword ptr [0x007851f4]
    const std::uint32_t call_target=m.r32((0x007851f4u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x770f8c: eb02 JMP 0x00770f90
    goto L00770f90;
  }
  L00770f8e: { // 0x770f8e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00770f90: { // 0x770f90: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x770f92: 740b JZ 0x00770f9f
    if(integer::condition("JZ",flags)) goto L00770f9f;
  }
  { // 0x770f94: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x770f95: e841420000 CALL 0x007751db
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x770f9a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770f9b: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x770f9e: c3 RET
    finish(m,s,f,0u); return;
  }
  L00770f9f: { // 0x770f9f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x770fa1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00371521(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x771521: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x771522: 8b35e8517800 MOV ESI,dword ptr [0x007851e8]
    s.si = m.r32((0x007851e8u));
  }
  { // 0x771528: ff35bc728100 PUSH dword ptr [0x008172bc]
    f.push(m,m.r32((0x008172bcu)));
  }
  { // 0x77152e: ffd6 CALL ESI
    const std::uint32_t call_target=s.si;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x771530: ff35ac728100 PUSH dword ptr [0x008172ac]
    f.push(m,m.r32((0x008172acu)));
  }
  { // 0x771536: ffd6 CALL ESI
    const std::uint32_t call_target=s.si;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x771538: ff359c728100 PUSH dword ptr [0x0081729c]
    f.push(m,m.r32((0x0081729cu)));
  }
  { // 0x77153e: ffd6 CALL ESI
    const std::uint32_t call_target=s.si;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x771540: ff357c728100 PUSH dword ptr [0x0081727c]
    f.push(m,m.r32((0x0081727cu)));
  }
  { // 0x771546: ffd6 CALL ESI
    const std::uint32_t call_target=s.si;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x771548: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x771549: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00373271(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x773271: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x773273: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x773275: 39442408 CMP dword ptr [ESP + 0x8],EAX
    (void)integer::sub(m.r32((f.sp+0x00000008u)),s.ax,32,flags);
  }
  { // 0x773279: 6800100000 PUSH 0x1000
    f.push(m,0x00001000u);
  }
  { // 0x77327e: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x773281: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x773282: ff1578527800 CALL dword ptr [0x00785278]
    const std::uint32_t call_target=m.r32((0x00785278u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x773288: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77328a: a31c0eb100 MOV [0x00b10e1c],EAX
    m.w32((0x00b10e1cu), s.ax);
  }
  { // 0x77328f: 7415 JZ 0x007732a6
    if(integer::condition("JZ",flags)) goto L007732a6;
  }
  { // 0x773291: e8a9000000 CALL 0x0077333f
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x773296: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x773298: 750f JNZ 0x007732a9
    if(integer::condition("JNZ",flags)) goto L007732a9;
  }
  { // 0x77329a: ff351c0eb100 PUSH dword ptr [0x00b10e1c]
    f.push(m,m.r32((0x00b10e1cu)));
  }
  { // 0x7732a0: ff1588517800 CALL dword ptr [0x00785188]
    const std::uint32_t call_target=m.r32((0x00785188u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L007732a6: { // 0x7732a6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x7732a8: c3 RET
    finish(m,s,f,0u); return;
  }
  L007732a9: { // 0x7732a9: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x7732ab: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  { // 0x7732ac: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00374c3d(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x774c3d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x774c3e: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  { // 0x774c40: e871c9ffff CALL 0x007715b6
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x774c45: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x774c49: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x774c4a: e82ee7ffff CALL 0x0077337d
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x774c4f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x774c50: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x774c52: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x774c53: 7410 JZ 0x00774c65
    if(integer::condition("JZ",flags)) goto L00774c65;
  }
  { // 0x774c55: 8b76fc MOV ESI,dword ptr [ESI + -0x4]
    s.si = m.r32((s.si-0x00000004u));
  }
  { // 0x774c58: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  { // 0x774c5a: 83ee09 SUB ESI,0x9
    s.si = integer::sub(s.si,0x00000009u,32,flags);
  }
  { // 0x774c5d: e8b5c9ffff CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x774c62: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x774c63: eb19 JMP 0x00774c7e
    goto L00774c7e;
  }
  L00774c65: { // 0x774c65: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  { // 0x774c67: e8abc9ffff CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x774c6c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x774c6d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x774c6e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x774c70: ff351c0eb100 PUSH dword ptr [0x00b10e1c]
    f.push(m,m.r32((0x00b10e1cu)));
  }
  { // 0x774c76: ff159c527800 CALL dword ptr [0x0078529c]
    const std::uint32_t call_target=m.r32((0x0078529cu));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x774c7c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00774c7e: { // 0x774c7e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x774c80: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x774c81: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00374f46(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x774f46: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x774f47: e8d5c5ffff CALL 0x00771521
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x774f4c: ff15ac527800 CALL dword ptr [0x007852ac]
    const std::uint32_t call_target=m.r32((0x007852acu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x774f52: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x774f55: a378778100 MOV [0x00817778],EAX
    m.w32((0x00817778u), s.ax);
  }
  { // 0x774f5a: 743a JZ 0x00774f96
    if(integer::condition("JZ",flags)) goto L00774f96;
  }
  { // 0x774f5c: 6a74 PUSH 0x74
    f.push(m,0x00000074u);
  }
  { // 0x774f5e: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x774f60: e8cf1f0000 CALL 0x00776f34
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x774f65: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x774f67: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x774f68: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x774f6a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x774f6b: 7429 JZ 0x00774f96
    if(integer::condition("JZ",flags)) goto L00774f96;
  }
  { // 0x774f6d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x774f6e: ff3578778100 PUSH dword ptr [0x00817778]
    f.push(m,m.r32((0x00817778u)));
  }
  { // 0x774f74: ff15a8527800 CALL dword ptr [0x007852a8]
    const std::uint32_t call_target=m.r32((0x007852a8u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x774f7a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x774f7c: 7418 JZ 0x00774f96
    if(integer::condition("JZ",flags)) goto L00774f96;
  }
  { // 0x774f7e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x774f7f: e834000000 CALL 0x00774fb8
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x774f84: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x774f85: ff15c4517800 CALL dword ptr [0x007851c4]
    const std::uint32_t call_target=m.r32((0x007851c4u));
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x774f8b: 834e04ff OR dword ptr [ESI + 0x4],0xffffffff
    m.w32((s.si+0x00000004u), integer::logical((m.r32((s.si+0x00000004u)))|(0xffffffffu),32,flags));
  }
  { // 0x774f8f: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x774f91: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x774f93: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  { // 0x774f94: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x774f95: c3 RET
    finish(m,s,f,0u); return;
  }
  L00774f96: { // 0x774f96: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x774f98: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x774f99: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00374fcb(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x774fcb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x774fcc: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x774fcd: ff15f4517800 CALL dword ptr [0x007851f4]
    const std::uint32_t call_target=m.r32((0x007851f4u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x774fd3: ff3578778100 PUSH dword ptr [0x00817778]
    f.push(m,m.r32((0x00817778u)));
  }
  { // 0x774fd9: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x774fdb: ff15b0527800 CALL dword ptr [0x007852b0]
    const std::uint32_t call_target=m.r32((0x007852b0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x774fe1: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x774fe3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x774fe5: 753f JNZ 0x00775026
    if(integer::condition("JNZ",flags)) goto L00775026;
  }
  { // 0x774fe7: 6a74 PUSH 0x74
    f.push(m,0x00000074u);
  }
  { // 0x774fe9: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x774feb: e8441f0000 CALL 0x00776f34
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x774ff0: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x774ff2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x774ff3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x774ff5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x774ff6: 7426 JZ 0x0077501e
    if(integer::condition("JZ",flags)) goto L0077501e;
  }
  { // 0x774ff8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x774ff9: ff3578778100 PUSH dword ptr [0x00817778]
    f.push(m,m.r32((0x00817778u)));
  }
  { // 0x774fff: ff15a8527800 CALL dword ptr [0x007852a8]
    const std::uint32_t call_target=m.r32((0x007852a8u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x775005: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x775007: 7415 JZ 0x0077501e
    if(integer::condition("JZ",flags)) goto L0077501e;
  }
  { // 0x775009: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77500a: e8a9ffffff CALL 0x00774fb8
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x77500f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x775010: ff15c4517800 CALL dword ptr [0x007851c4]
    const std::uint32_t call_target=m.r32((0x007851c4u));
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x775016: 834e04ff OR dword ptr [ESI + 0x4],0xffffffff
    m.w32((s.si+0x00000004u), integer::logical((m.r32((s.si+0x00000004u)))|(0xffffffffu),32,flags));
  }
  { // 0x77501a: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x77501c: eb08 JMP 0x00775026
    goto L00775026;
  }
  L0077501e: { // 0x77501e: 6a10 PUSH 0x10
    f.push(m,0x00000010u);
  }
  { // 0x775020: e8b3c4ffff CALL 0x007714d8
    const std::uint32_t call_target=f.boundaries[6u].target;
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  { // 0x775025: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00775026: { // 0x775026: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x775027: ff15b8527800 CALL dword ptr [0x007852b8]
    const std::uint32_t call_target=m.r32((0x007852b8u));
    invoke(m,s,f,op,7u,call_target); flags=0x202u;
  }
  { // 0x77502d: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x77502f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x775030: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x775031: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00377542(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x777542: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x777543: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x777545: 391d3005b100 CMP dword ptr [0x00b10530],EBX
    (void)integer::sub(m.r32((0x00b10530u)),s.bx,32,flags);
  }
  { // 0x77754b: 7517 JNZ 0x00777564
    if(integer::condition("JNZ",flags)) goto L00777564;
  }
  { // 0x77754d: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x777551: 663d6100 CMP AX,0x61
    (void)integer::sub((s.ax & 0xffffu),0x00000061u,16,flags);
  }
  { // 0x777555: 725d JC 0x007775b4
    if(integer::condition("JC",flags)) goto L007775b4;
  }
  { // 0x777557: 663d7a00 CMP AX,0x7a
    (void)integer::sub((s.ax & 0xffffu),0x0000007au,16,flags);
  }
  { // 0x77755b: 7757 JA 0x007775b4
    if(integer::condition("JA",flags)) goto L007775b4;
  }
  { // 0x77755d: 05e0ff0000 ADD EAX,0xffe0
    s.ax = integer::add(s.ax,0x0000ffe0u,32,flags);
  }
  { // 0x777562: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x777563: c3 RET
    finish(m,s,f,0u); return;
  }
  L00777564: { // 0x777564: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x777565: be240eb100 MOV ESI,0xb10e24
    s.si = 0x00b10e24u;
  }
  { // 0x77756a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77756b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77756c: ff15bc517800 CALL dword ptr [0x007851bc]
    const std::uint32_t call_target=m.r32((0x007851bcu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x777572: 391d200eb100 CMP dword ptr [0x00b10e20],EBX
    (void)integer::sub(m.r32((0x00b10e20u)),s.bx,32,flags);
  }
  { // 0x777578: 8b3dc0517800 MOV EDI,dword ptr [0x007851c0]
    s.di = m.r32((0x007851c0u));
  }
  { // 0x77757e: 740e JZ 0x0077758e
    if(integer::condition("JZ",flags)) goto L0077758e;
  }
  { // 0x777580: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x777581: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x777583: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  { // 0x777585: e82ca0ffff CALL 0x007715b6
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x77758a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77758b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77758d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0077758e: { // 0x77758e: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x777592: e81f000000 CALL 0x007775b6
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x777597: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x777599: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77759a: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  { // 0x77759e: 740a JZ 0x007775aa
    if(integer::condition("JZ",flags)) goto L007775aa;
  }
  { // 0x7775a0: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  { // 0x7775a2: e870a0ffff CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x7775a7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7775a8: eb03 JMP 0x007775ad
    goto L007775ad;
  }
  L007775aa: { // 0x7775aa: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7775ab: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  L007775ad: { // 0x7775ad: 668b442410 MOV AX,word ptr [ESP + 0x10]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000010u)));
  }
  { // 0x7775b2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7775b3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007775b4: { // 0x7775b4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x7775b5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00379100(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x779100: ff742404 PUSH dword ptr [ESP + 0x4]
    f.push(m,m.r32((f.sp+0x00000004u)));
  }
  { // 0x779104: ff15dc527800 CALL dword ptr [0x007852dc]
    const std::uint32_t call_target=m.r32((0x007852dcu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77910a: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x77910d: 7511 JNZ 0x00779120
    if(integer::condition("JNZ",flags)) goto L00779120;
  }
  { // 0x77910f: ff15f4517800 CALL dword ptr [0x007851f4]
    const std::uint32_t call_target=m.r32((0x007851f4u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x779115: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x779116: e8c0c0ffff CALL 0x007751db
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x77911b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077911c: { // 0x77911c: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x77911f: c3 RET
    finish(m,s,f,0u); return;
  }
  L00779120: { // 0x779120: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x779122: 741f JZ 0x00779143
    if(integer::condition("JZ",flags)) goto L00779143;
  }
  { // 0x779124: f644240802 TEST byte ptr [ESP + 0x8],0x2
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000002u),8,flags);
  }
  { // 0x779129: 7418 JZ 0x00779143
    if(integer::condition("JZ",flags)) goto L00779143;
  }
  { // 0x77912b: e81ec1ffff CALL 0x0077524e
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x779130: c7000d000000 MOV dword ptr [EAX],0xd
    m.w32((s.ax), 0x0000000du);
  }
  { // 0x779136: e81cc1ffff CALL 0x00775257
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x77913b: c70005000000 MOV dword ptr [EAX],0x5
    m.w32((s.ax), 0x00000005u);
  }
  { // 0x779141: ebd9 JMP 0x0077911c
    goto L0077911c;
  }
  L00779143: { // 0x779143: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x779145: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00379f36(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x779f36: a1c004b100 MOV EAX,[0x00b104c0]
    s.ax = m.r32((0x00b104c0u));
  }
  { // 0x779f3b: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x779f3e: 740d JZ 0x00779f4d
    if(integer::condition("JZ",flags)) goto L00779f4d;
  }
  { // 0x779f40: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x779f42: 752a JNZ 0x00779f6e
    if(integer::condition("JNZ",flags)) goto L00779f6e;
  }
  { // 0x779f44: 833d7472810001 CMP dword ptr [0x00817274],0x1
    (void)integer::sub(m.r32((0x00817274u)),0x00000001u,32,flags);
  }
  { // 0x779f4b: 7521 JNZ 0x00779f6e
    if(integer::condition("JNZ",flags)) goto L00779f6e;
  }
  L00779f4d: { // 0x779f4d: 68fc000000 PUSH 0xfc
    f.push(m,0x000000fcu);
  }
  { // 0x779f52: e818000000 CALL 0x00779f6f
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x779f57: a1ac06b100 MOV EAX,[0x00b106ac]
    s.ax = m.r32((0x00b106acu));
  }
  { // 0x779f5c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x779f5d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x779f5f: 7402 JZ 0x00779f63
    if(integer::condition("JZ",flags)) goto L00779f63;
  }
  { // 0x779f61: ffd0 CALL EAX
    const std::uint32_t call_target=s.ax;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00779f63: { // 0x779f63: 68ff000000 PUSH 0xff
    f.push(m,0x000000ffu);
  }
  { // 0x779f68: e802000000 CALL 0x00779f6f
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x779f6d: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00779f6e: { // 0x779f6e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037b1ca(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77b1ca: ff350007b100 PUSH dword ptr [0x00b10700]
    f.push(m,m.r32((0x00b10700u)));
  }
  { // 0x77b1d0: e88b9fffff CALL 0x00775160
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77b1d5: 83e803 SUB EAX,0x3
    s.ax = integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x77b1d8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b1d9: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x77b1db: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x77b1dd: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x77b1de: a3fc06b100 MOV [0x00b106fc],EAX
    m.w32((0x00b106fcu), s.ax);
  }
  { // 0x77b1e3: 740c JZ 0x0077b1f1
    if(integer::condition("JZ",flags)) goto L0077b1f1;
  }
  { // 0x77b1e5: c705f806b10002000000 MOV dword ptr [0x00b106f8],0x2
    m.w32((0x00b106f8u), 0x00000002u);
  }
  { // 0x77b1ef: eb11 JMP 0x0077b202
    goto L0077b202;
  }
  L0077b1f1: { // 0x77b1f1: ff350007b100 PUSH dword ptr [0x00b10700]
    f.push(m,m.r32((0x00b10700u)));
  }
  { // 0x77b1f7: e8f4030000 CALL 0x0077b5f0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x77b1fc: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b1fd: a3f806b100 MOV [0x00b106f8],EAX
    m.w32((0x00b106f8u), s.ax);
  }
  L0077b202: { // 0x77b202: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77b204: 6820b27700 PUSH 0x77b220
    f.push(m,0x0077b220u);
  }
  { // 0x77b209: ff1508537800 CALL dword ptr [0x00785308]
    const std::uint32_t call_target=m.r32((0x00785308u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x77b20f: f6050807b10004 TEST byte ptr [0x00b10708],0x4
    (void)integer::logical((m.r8((0x00b10708u)))&(0x00000004u),8,flags);
  }
  { // 0x77b216: 7507 JNZ 0x0077b21f
    if(integer::condition("JNZ",flags)) goto L0077b21f;
  }
  { // 0x77b218: 83250807b10000 AND dword ptr [0x00b10708],0x0
    m.w32((0x00b10708u), integer::logical((m.r32((0x00b10708u)))&(0x00000000u),32,flags));
  }
  L0077b21f: { // 0x77b21f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037b2dd(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77b2dd: ff350407b100 PUSH dword ptr [0x00b10704]
    f.push(m,m.r32((0x00b10704u)));
  }
  { // 0x77b2e3: e8789effff CALL 0x00775160
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77b2e8: 83e803 SUB EAX,0x3
    s.ax = integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x77b2eb: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b2ec: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x77b2ee: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x77b2f0: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77b2f2: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x77b2f3: 6814b37700 PUSH 0x77b314
    f.push(m,0x0077b314u);
  }
  { // 0x77b2f8: a3f406b100 MOV [0x00b106f4],EAX
    m.w32((0x00b106f4u), s.ax);
  }
  { // 0x77b2fd: ff1508537800 CALL dword ptr [0x00785308]
    const std::uint32_t call_target=m.r32((0x00785308u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x77b303: f6050807b10004 TEST byte ptr [0x00b10708],0x4
    (void)integer::logical((m.r8((0x00b10708u)))&(0x00000004u),8,flags);
  }
  { // 0x77b30a: 7507 JNZ 0x0077b313
    if(integer::condition("JNZ",flags)) goto L0077b313;
  }
  { // 0x77b30c: 83250807b10000 AND dword ptr [0x00b10708],0x0
    m.w32((0x00b10708u), integer::logical((m.r32((0x00b10708u)))&(0x00000000u),32,flags));
  }
  L0077b313: { // 0x77b313: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037b3b4(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77b3b4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77b3b5: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77b3b7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x77b3b8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x77b3b9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77b3ba: 8b7508 MOV ESI,dword ptr [EBP + 0x8]
    s.si = m.r32((s.bp+0x00000008u));
  }
  { // 0x77b3bd: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x77b3bf: 7431 JZ 0x0077b3f2
    if(integer::condition("JZ",flags)) goto L0077b3f2;
  }
  { // 0x77b3c1: 803e00 CMP byte ptr [ESI],0x0
    (void)integer::sub(m.r8((s.si)),0x00000000u,8,flags);
  }
  { // 0x77b3c4: 742c JZ 0x0077b3f2
    if(integer::condition("JZ",flags)) goto L0077b3f2;
  }
  { // 0x77b3c6: 6858d27900 PUSH 0x79d258
    f.push(m,0x0079d258u);
  }
  { // 0x77b3cb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77b3cc: e87f62ffff CALL 0x00771650
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77b3d1: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b3d2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77b3d4: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b3d5: 741b JZ 0x0077b3f2
    if(integer::condition("JZ",flags)) goto L0077b3f2;
  }
  { // 0x77b3d7: 6854d27900 PUSH 0x79d254
    f.push(m,0x0079d254u);
  }
  { // 0x77b3dc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77b3dd: e86e62ffff CALL 0x00771650
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x77b3e2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b3e3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77b3e5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b3e6: 7528 JNZ 0x0077b410
    if(integer::condition("JNZ",flags)) goto L0077b410;
  }
  { // 0x77b3e8: 8d45f8 LEA EAX,[EBP + -0x8]
    s.ax = (s.bp-0x00000008u);
  }
  { // 0x77b3eb: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x77b3ed: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77b3ee: 6a0b PUSH 0xb
    f.push(m,0x0000000bu);
  }
  { // 0x77b3f0: eb0b JMP 0x0077b3fd
    goto L0077b3fd;
  }
  L0077b3f2: { // 0x77b3f2: 8d45f8 LEA EAX,[EBP + -0x8]
    s.ax = (s.bp-0x00000008u);
  }
  { // 0x77b3f5: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x77b3f7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77b3f8: 6804100000 PUSH 0x1004
    f.push(m,0x00001004u);
  }
  L0077b3fd: { // 0x77b3fd: ff350c07b100 PUSH dword ptr [0x00b1070c]
    f.push(m,m.r32((0x00b1070cu)));
  }
  { // 0x77b403: ff151007b100 CALL dword ptr [0x00b10710]
    const std::uint32_t call_target=m.r32((0x00b10710u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x77b409: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77b40b: 740a JZ 0x0077b417
    if(integer::condition("JZ",flags)) goto L0077b417;
  }
  { // 0x77b40d: 8d75f8 LEA ESI,[EBP + -0x8]
    s.si = (s.bp-0x00000008u);
  }
  L0077b410: { // 0x77b410: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77b411: e89c32ffff CALL 0x0076e6b2
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x77b416: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077b417: { // 0x77b417: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77b418: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77b419: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037b439(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77b439: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77b43a: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77b43c: 83ec78 SUB ESP,0x78
    f.sp = integer::sub(f.sp,0x00000078u,32,flags);
  }
  { // 0x77b43f: 8d4588 LEA EAX,[EBP + -0x78]
    s.ax = (s.bp-0x00000078u);
  }
  { // 0x77b442: 6a78 PUSH 0x78
    f.push(m,0x00000078u);
  }
  { // 0x77b444: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77b445: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x77b448: 25ff030000 AND EAX,0x3ff
    s.ax = integer::logical((s.ax)&(0x000003ffu),32,flags);
  }
  { // 0x77b44d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77b44f: 80cc04 OR AH,0x4
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))|(0x00000004u),8,flags)) & 0xffu) << 8);
  }
  { // 0x77b452: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77b453: ff151007b100 CALL dword ptr [0x00b10710]
    const std::uint32_t call_target=m.r32((0x00b10710u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77b459: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77b45b: 7435 JZ 0x0077b492
    if(integer::condition("JZ",flags)) goto L0077b492;
  }
  { // 0x77b45d: 8d4588 LEA EAX,[EBP + -0x78]
    s.ax = (s.bp-0x00000078u);
  }
  { // 0x77b460: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77b461: e851010000 CALL 0x0077b5b7
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x77b466: 394508 CMP dword ptr [EBP + 0x8],EAX
    (void)integer::sub(m.r32((s.bp+0x00000008u)),s.ax,32,flags);
  }
  { // 0x77b469: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b46a: 742a JZ 0x0077b496
    if(integer::condition("JZ",flags)) goto L0077b496;
  }
  { // 0x77b46c: 837d0c00 CMP dword ptr [EBP + 0xc],0x0
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),0x00000000u,32,flags);
  }
  { // 0x77b470: 7424 JZ 0x0077b496
    if(integer::condition("JZ",flags)) goto L0077b496;
  }
  { // 0x77b472: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77b473: ff350007b100 PUSH dword ptr [0x00b10700]
    f.push(m,m.r32((0x00b10700u)));
  }
  { // 0x77b479: e872010000 CALL 0x0077b5f0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x77b47e: ff350007b100 PUSH dword ptr [0x00b10700]
    f.push(m,m.r32((0x00b10700u)));
  }
  { // 0x77b484: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x77b486: e8d59cffff CALL 0x00775160
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x77b48b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b48c: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x77b48e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b48f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77b490: 7504 JNZ 0x0077b496
    if(integer::condition("JNZ",flags)) goto L0077b496;
  }
  L0077b492: { // 0x77b492: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x77b494: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77b495: c3 RET
    finish(m,s,f,0u); return;
  }
  L0077b496: { // 0x77b496: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77b498: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  { // 0x77b499: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77b49a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037b6dd(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77b6dd: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77b6de: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x77b6e2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77b6e3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77b6e4: e85c1d0000 CALL 0x0077d445
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77b6e9: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x77b6ec: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b6ed: 750d JNZ 0x0077b6fc
    if(integer::condition("JNZ",flags)) goto L0077b6fc;
  }
  { // 0x77b6ef: e85a9bffff CALL 0x0077524e
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x77b6f4: c70009000000 MOV dword ptr [EAX],0x9
    m.w32((s.ax), 0x00000009u);
  }
  { // 0x77b6fa: eb2d JMP 0x0077b729
    goto L0077b729;
  }
  L0077b6fc: { // 0x77b6fc: ff742414 PUSH dword ptr [ESP + 0x14]
    f.push(m,m.r32((f.sp+0x00000014u)));
  }
  { // 0x77b700: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x77b702: ff742418 PUSH dword ptr [ESP + 0x18]
    f.push(m,m.r32((f.sp+0x00000018u)));
  }
  { // 0x77b706: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77b707: ff15b4517800 CALL dword ptr [0x007851b4]
    const std::uint32_t call_target=m.r32((0x007851b4u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x77b70d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x77b70f: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  { // 0x77b712: 7508 JNZ 0x0077b71c
    if(integer::condition("JNZ",flags)) goto L0077b71c;
  }
  { // 0x77b714: ff15f4517800 CALL dword ptr [0x007851f4]
    const std::uint32_t call_target=m.r32((0x007851f4u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x77b71a: eb02 JMP 0x0077b71e
    goto L0077b71e;
  }
  L0077b71c: { // 0x77b71c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0077b71e: { // 0x77b71e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77b720: 740c JZ 0x0077b72e
    if(integer::condition("JZ",flags)) goto L0077b72e;
  }
  { // 0x77b722: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77b723: e8b39affff CALL 0x007751db
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x77b728: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077b729: { // 0x77b729: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x77b72c: eb1f JMP 0x0077b74d
    goto L0077b74d;
  }
  L0077b72e: { // 0x77b72e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x77b730: 83e61f AND ESI,0x1f
    s.si = integer::logical((s.si)&(0x0000001fu),32,flags);
  }
  { // 0x77b733: c1f905 SAR ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x77b736: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x77b738: 8b0c8d000db100 MOV ECX,dword ptr [ECX*0x4 + 0xb10d00]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x00b10d00u));
  }
  { // 0x77b73f: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x77b742: 80648104fd AND byte ptr [ECX + EAX*0x4 + 0x4],0xfd
    m.w8((s.cx+(s.ax * 0x00000004u)+0x00000004u), integer::logical((m.r8((s.cx+(s.ax * 0x00000004u)+0x00000004u)))&(0x000000fdu),8,flags));
  }
  { // 0x77b747: 8d448104 LEA EAX,[ECX + EAX*0x4 + 0x4]
    s.ax = (s.cx+(s.ax * 0x00000004u)+0x00000004u);
  }
  { // 0x77b74b: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0077b74d: { // 0x77b74d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77b74e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77b74f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037b7bd(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77b7bd: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77b7be: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77b7c0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77b7c1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77b7c2: be240eb100 MOV ESI,0xb10e24
    s.si = 0x00b10e24u;
  }
  { // 0x77b7c7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77b7c8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77b7c9: ff15bc517800 CALL dword ptr [0x007851bc]
    const std::uint32_t call_target=m.r32((0x007851bcu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77b7cf: 8b3dc0517800 MOV EDI,dword ptr [0x007851c0]
    s.di = m.r32((0x007851c0u));
  }
  { // 0x77b7d5: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x77b7d7: 391d200eb100 CMP dword ptr [0x00b10e20],EBX
    (void)integer::sub(m.r32((0x00b10e20u)),s.bx,32,flags);
  }
  { // 0x77b7dd: 740e JZ 0x0077b7ed
    if(integer::condition("JZ",flags)) goto L0077b7ed;
  }
  { // 0x77b7df: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77b7e0: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x77b7e2: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  { // 0x77b7e4: e8cd5dffff CALL 0x007715b6
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x77b7e9: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b7ea: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77b7ec: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0077b7ed: { // 0x77b7ed: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x77b7f0: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x77b7f3: e81e000000 CALL 0x0077b816
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x77b7f8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b7f9: 89450c MOV dword ptr [EBP + 0xc],EAX
    m.w32((s.bp+0x0000000cu), s.ax);
  }
  { // 0x77b7fc: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x77b7fe: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b7ff: 740a JZ 0x0077b80b
    if(integer::condition("JZ",flags)) goto L0077b80b;
  }
  { // 0x77b801: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  { // 0x77b803: e80f5effff CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x77b808: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b809: eb03 JMP 0x0077b80e
    goto L0077b80e;
  }
  L0077b80b: { // 0x77b80b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77b80c: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  L0077b80e: { // 0x77b80e: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x77b811: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77b812: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77b813: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x77b814: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x77b815: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037b816(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77b816: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77b817: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77b819: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x77b81c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77b81e: 7502 JNZ 0x0077b822
    if(integer::condition("JNZ",flags)) goto L0077b822;
  }
  { // 0x77b820: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x77b821: c3 RET
    finish(m,s,f,0u); return;
  }
  L0077b822: { // 0x77b822: 833d3005b10000 CMP dword ptr [0x00b10530],0x0
    (void)integer::sub(m.r32((0x00b10530u)),0x00000000u,32,flags);
  }
  { // 0x77b829: 7512 JNZ 0x0077b83d
    if(integer::condition("JNZ",flags)) goto L0077b83d;
  }
  { // 0x77b82b: 668b4d0c MOV CX,word ptr [EBP + 0xc]
    s.cx = with_ax(s.cx, m.r16((s.bp+0x0000000cu)));
  }
  { // 0x77b82f: 6681f9ff00 CMP CX,0xff
    (void)integer::sub((s.cx & 0xffffu),0x000000ffu,16,flags);
  }
  { // 0x77b834: 7739 JA 0x0077b86f
    if(integer::condition("JA",flags)) goto L0077b86f;
  }
  { // 0x77b836: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77b838: 8808 MOV byte ptr [EAX],CL
    m.w8((s.ax), (s.cx & 0xffu));
  }
  { // 0x77b83a: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  { // 0x77b83b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x77b83c: c3 RET
    finish(m,s,f,0u); return;
  }
  L0077b83d: { // 0x77b83d: 8d4d08 LEA ECX,[EBP + 0x8]
    s.cx = (s.bp+0x00000008u);
  }
  { // 0x77b840: 83650800 AND dword ptr [EBP + 0x8],0x0
    m.w32((s.bp+0x00000008u), integer::logical((m.r32((s.bp+0x00000008u)))&(0x00000000u),32,flags));
  }
  { // 0x77b844: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x77b845: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x77b847: ff356c778100 PUSH dword ptr [0x0081776c]
    f.push(m,m.r32((0x0081776cu)));
  }
  { // 0x77b84d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77b84e: 8d450c LEA EAX,[EBP + 0xc]
    s.ax = (s.bp+0x0000000cu);
  }
  { // 0x77b851: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77b853: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77b854: 6820020000 PUSH 0x220
    f.push(m,0x00000220u);
  }
  { // 0x77b859: ff354005b100 PUSH dword ptr [0x00b10540]
    f.push(m,m.r32((0x00b10540u)));
  }
  { // 0x77b85f: ff153c527800 CALL dword ptr [0x0078523c]
    const std::uint32_t call_target=m.r32((0x0078523cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77b865: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77b867: 7406 JZ 0x0077b86f
    if(integer::condition("JZ",flags)) goto L0077b86f;
  }
  { // 0x77b869: 837d0800 CMP dword ptr [EBP + 0x8],0x0
    (void)integer::sub(m.r32((s.bp+0x00000008u)),0x00000000u,32,flags);
  }
  { // 0x77b86d: 740e JZ 0x0077b87d
    if(integer::condition("JZ",flags)) goto L0077b87d;
  }
  L0077b86f: { // 0x77b86f: e8da99ffff CALL 0x0077524e
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x77b874: c7002a000000 MOV dword ptr [EAX],0x2a
    m.w32((s.ax), 0x0000002au);
  }
  { // 0x77b87a: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0077b87d: { // 0x77b87d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x77b87e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037d34a(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77d34a: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x77d34e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77d34f: 3b0d000eb100 CMP ECX,dword ptr [0x00b10e00]
    (void)integer::sub(s.cx,m.r32((0x00b10e00u)),32,flags);
  }
  { // 0x77d355: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77d356: 7355 JNC 0x0077d3ad
    if(integer::condition("JNC",flags)) goto L0077d3ad;
  }
  { // 0x77d358: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x77d35a: c1f805 SAR EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x77d35d: 8d3c85000db100 LEA EDI,[EAX*0x4 + 0xb10d00]
    s.di = ((s.ax * 0x00000004u)+0x00b10d00u);
  }
  { // 0x77d364: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x77d366: 83e01f AND EAX,0x1f
    s.ax = integer::logical((s.ax)&(0x0000001fu),32,flags);
  }
  { // 0x77d369: 8d34c0 LEA ESI,[EAX + EAX*0x8]
    s.si = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x77d36c: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x77d36e: c1e602 SHL ESI,0x2
    s.si = integer::shift(s.si,0x00000002u,32,flags,integer::Shift::left);
  }
  { // 0x77d371: 833c30ff CMP dword ptr [EAX + ESI*0x1],-0x1
    (void)integer::sub(m.r32((s.ax+(s.si * 0x00000001u))),0xffffffffu,32,flags);
  }
  { // 0x77d375: 7536 JNZ 0x0077d3ad
    if(integer::condition("JNZ",flags)) goto L0077d3ad;
  }
  { // 0x77d377: 833d7472810001 CMP dword ptr [0x00817274],0x1
    (void)integer::sub(m.r32((0x00817274u)),0x00000001u,32,flags);
  }
  { // 0x77d37e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77d37f: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  { // 0x77d383: 751e JNZ 0x0077d3a3
    if(integer::condition("JNZ",flags)) goto L0077d3a3;
  }
  { // 0x77d385: 83e900 SUB ECX,0x0
    s.cx = integer::sub(s.cx,0x00000000u,32,flags);
  }
  { // 0x77d388: 7410 JZ 0x0077d39a
    if(integer::condition("JZ",flags)) goto L0077d39a;
  }
  { // 0x77d38a: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x77d38b: 7408 JZ 0x0077d395
    if(integer::condition("JZ",flags)) goto L0077d395;
  }
  { // 0x77d38d: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x77d38e: 7513 JNZ 0x0077d3a3
    if(integer::condition("JNZ",flags)) goto L0077d3a3;
  }
  { // 0x77d390: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77d391: 6af4 PUSH -0xc
    f.push(m,0xfffffff4u);
  }
  { // 0x77d393: eb08 JMP 0x0077d39d
    goto L0077d39d;
  }
  L0077d395: { // 0x77d395: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77d396: 6af5 PUSH -0xb
    f.push(m,0xfffffff5u);
  }
  { // 0x77d398: eb03 JMP 0x0077d39d
    goto L0077d39d;
  }
  L0077d39a: { // 0x77d39a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77d39b: 6af6 PUSH -0xa
    f.push(m,0xfffffff6u);
  }
  L0077d39d: { // 0x77d39d: ff1510537800 CALL dword ptr [0x00785310]
    const std::uint32_t call_target=m.r32((0x00785310u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0077d3a3: { // 0x77d3a3: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x77d3a5: 891c30 MOV dword ptr [EAX + ESI*0x1],EBX
    m.w32((s.ax+(s.si * 0x00000001u)), s.bx);
  }
  { // 0x77d3a8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x77d3aa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x77d3ab: eb16 JMP 0x0077d3c3
    goto L0077d3c3;
  }
  L0077d3ad: { // 0x77d3ad: e89c7effff CALL 0x0077524e
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x77d3b2: c70009000000 MOV dword ptr [EAX],0x9
    m.w32((s.ax), 0x00000009u);
  }
  { // 0x77d3b8: e89a7effff CALL 0x00775257
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x77d3bd: 832000 AND dword ptr [EAX],0x0
    m.w32((s.ax), integer::logical((m.r32((s.ax)))&(0x00000000u),32,flags));
  }
  { // 0x77d3c0: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0077d3c3: { // 0x77d3c3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77d3c4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77d3c5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037d3c6(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77d3c6: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x77d3ca: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77d3cb: 3b0d000eb100 CMP ECX,dword ptr [0x00b10e00]
    (void)integer::sub(s.cx,m.r32((0x00b10e00u)),32,flags);
  }
  { // 0x77d3d1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77d3d2: 7358 JNC 0x0077d42c
    if(integer::condition("JNC",flags)) goto L0077d42c;
  }
  { // 0x77d3d4: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x77d3d6: c1f805 SAR EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x77d3d9: 8d3c85000db100 LEA EDI,[EAX*0x4 + 0xb10d00]
    s.di = ((s.ax * 0x00000004u)+0x00b10d00u);
  }
  { // 0x77d3e0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x77d3e2: 83e01f AND EAX,0x1f
    s.ax = integer::logical((s.ax)&(0x0000001fu),32,flags);
  }
  { // 0x77d3e5: 8d34c0 LEA ESI,[EAX + EAX*0x8]
    s.si = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x77d3e8: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x77d3ea: c1e602 SHL ESI,0x2
    s.si = integer::shift(s.si,0x00000002u,32,flags,integer::Shift::left);
  }
  { // 0x77d3ed: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  { // 0x77d3ef: f6400401 TEST byte ptr [EAX + 0x4],0x1
    (void)integer::logical((m.r8((s.ax+0x00000004u)))&(0x00000001u),8,flags);
  }
  { // 0x77d3f3: 7437 JZ 0x0077d42c
    if(integer::condition("JZ",flags)) goto L0077d42c;
  }
  { // 0x77d3f5: 8338ff CMP dword ptr [EAX],-0x1
    (void)integer::sub(m.r32((s.ax)),0xffffffffu,32,flags);
  }
  { // 0x77d3f8: 7432 JZ 0x0077d42c
    if(integer::condition("JZ",flags)) goto L0077d42c;
  }
  { // 0x77d3fa: 833d7472810001 CMP dword ptr [0x00817274],0x1
    (void)integer::sub(m.r32((0x00817274u)),0x00000001u,32,flags);
  }
  { // 0x77d401: 751f JNZ 0x0077d422
    if(integer::condition("JNZ",flags)) goto L0077d422;
  }
  { // 0x77d403: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x77d405: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x77d407: 7410 JZ 0x0077d419
    if(integer::condition("JZ",flags)) goto L0077d419;
  }
  { // 0x77d409: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x77d40a: 7408 JZ 0x0077d414
    if(integer::condition("JZ",flags)) goto L0077d414;
  }
  { // 0x77d40c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x77d40d: 7513 JNZ 0x0077d422
    if(integer::condition("JNZ",flags)) goto L0077d422;
  }
  { // 0x77d40f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77d410: 6af4 PUSH -0xc
    f.push(m,0xfffffff4u);
  }
  { // 0x77d412: eb08 JMP 0x0077d41c
    goto L0077d41c;
  }
  L0077d414: { // 0x77d414: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77d415: 6af5 PUSH -0xb
    f.push(m,0xfffffff5u);
  }
  { // 0x77d417: eb03 JMP 0x0077d41c
    goto L0077d41c;
  }
  L0077d419: { // 0x77d419: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77d41a: 6af6 PUSH -0xa
    f.push(m,0xfffffff6u);
  }
  L0077d41c: { // 0x77d41c: ff1510537800 CALL dword ptr [0x00785310]
    const std::uint32_t call_target=m.r32((0x00785310u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0077d422: { // 0x77d422: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x77d424: 830c30ff OR dword ptr [EAX + ESI*0x1],0xffffffff
    m.w32((s.ax+(s.si * 0x00000001u)), integer::logical((m.r32((s.ax+(s.si * 0x00000001u))))|(0xffffffffu),32,flags));
  }
  { // 0x77d428: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x77d42a: eb16 JMP 0x0077d442
    goto L0077d442;
  }
  L0077d42c: { // 0x77d42c: e81d7effff CALL 0x0077524e
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x77d431: c70009000000 MOV dword ptr [EAX],0x9
    m.w32((s.ax), 0x00000009u);
  }
  { // 0x77d437: e81b7effff CALL 0x00775257
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x77d43c: 832000 AND dword ptr [EAX],0x0
    m.w32((s.ax), integer::logical((m.r32((s.ax)))&(0x00000000u),32,flags));
  }
  { // 0x77d43f: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0077d442: { // 0x77d442: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77d443: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77d444: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037d52e(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77d52e: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x77d532: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77d533: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x77d535: 83e01f AND EAX,0x1f
    s.ax = integer::logical((s.ax)&(0x0000001fu),32,flags);
  }
  { // 0x77d538: c1f905 SAR ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x77d53b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77d53c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77d53d: 8b348d000db100 MOV ESI,dword ptr [ECX*0x4 + 0xb10d00]
    s.si = m.r32(((s.cx * 0x00000004u)+0x00b10d00u));
  }
  { // 0x77d544: 8d1c8d000db100 LEA EBX,[ECX*0x4 + 0xb10d00]
    s.bx = ((s.cx * 0x00000004u)+0x00b10d00u);
  }
  { // 0x77d54b: 8d3cc0 LEA EDI,[EAX + EAX*0x8]
    s.di = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x77d54e: c1e702 SHL EDI,0x2
    s.di = integer::shift(s.di,0x00000002u,32,flags,integer::Shift::left);
  }
  { // 0x77d551: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  { // 0x77d553: 837e0800 CMP dword ptr [ESI + 0x8],0x0
    (void)integer::sub(m.r32((s.si+0x00000008u)),0x00000000u,32,flags);
  }
  { // 0x77d557: 7523 JNZ 0x0077d57c
    if(integer::condition("JNZ",flags)) goto L0077d57c;
  }
  { // 0x77d559: 6a11 PUSH 0x11
    f.push(m,0x00000011u);
  }
  { // 0x77d55b: e85640ffff CALL 0x007715b6
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77d560: 837e0800 CMP dword ptr [ESI + 0x8],0x0
    (void)integer::sub(m.r32((s.si+0x00000008u)),0x00000000u,32,flags);
  }
  { // 0x77d564: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77d565: 750d JNZ 0x0077d574
    if(integer::condition("JNZ",flags)) goto L0077d574;
  }
  { // 0x77d567: 8d460c LEA EAX,[ESI + 0xc]
    s.ax = (s.si+0x0000000cu);
  }
  { // 0x77d56a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77d56b: ff15e8517800 CALL dword ptr [0x007851e8]
    const std::uint32_t call_target=m.r32((0x007851e8u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x77d571: ff4608 INC dword ptr [ESI + 0x8]
    m.w32((s.si+0x00000008u), integer::increment(m.r32((s.si+0x00000008u)),32,flags));
  }
  L0077d574: { // 0x77d574: 6a11 PUSH 0x11
    f.push(m,0x00000011u);
  }
  { // 0x77d576: e89c40ffff CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x77d57b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077d57c: { // 0x77d57c: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  { // 0x77d57e: 8d44380c LEA EAX,[EAX + EDI*0x1 + 0xc]
    s.ax = (s.ax+(s.di * 0x00000001u)+0x0000000cu);
  }
  { // 0x77d582: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77d583: ff15dc517800 CALL dword ptr [0x007851dc]
    const std::uint32_t call_target=m.r32((0x007851dcu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x77d589: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77d58a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77d58b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x77d58c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037dc05(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77dc05: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77dc06: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77dc08: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77dc09: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77dc0a: be240eb100 MOV ESI,0xb10e24
    s.si = 0x00b10e24u;
  }
  { // 0x77dc0f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77dc10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77dc11: ff15bc517800 CALL dword ptr [0x007851bc]
    const std::uint32_t call_target=m.r32((0x007851bcu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77dc17: 8b3dc0517800 MOV EDI,dword ptr [0x007851c0]
    s.di = m.r32((0x007851c0u));
  }
  { // 0x77dc1d: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x77dc1f: 391d200eb100 CMP dword ptr [0x00b10e20],EBX
    (void)integer::sub(m.r32((0x00b10e20u)),s.bx,32,flags);
  }
  { // 0x77dc25: 740e JZ 0x0077dc35
    if(integer::condition("JZ",flags)) goto L0077dc35;
  }
  { // 0x77dc27: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77dc28: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x77dc2a: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  { // 0x77dc2c: e88539ffff CALL 0x007715b6
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x77dc31: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77dc32: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77dc34: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0077dc35: { // 0x77dc35: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x77dc38: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x77dc3b: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x77dc3e: e81f000000 CALL 0x0077dc62
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x77dc43: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77dc46: 894510 MOV dword ptr [EBP + 0x10],EAX
    m.w32((s.bp+0x00000010u), s.ax);
  }
  { // 0x77dc49: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x77dc4b: 740a JZ 0x0077dc57
    if(integer::condition("JZ",flags)) goto L0077dc57;
  }
  { // 0x77dc4d: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  { // 0x77dc4f: e8c339ffff CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x77dc54: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77dc55: eb03 JMP 0x0077dc5a
    goto L0077dc5a;
  }
  L0077dc57: { // 0x77dc57: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77dc58: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  L0077dc5a: { // 0x77dc5a: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  { // 0x77dc5d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77dc5e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77dc5f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x77dc60: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x77dc61: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037e947(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77e947: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77e948: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77e94a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77e94b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77e94c: be240eb100 MOV ESI,0xb10e24
    s.si = 0x00b10e24u;
  }
  { // 0x77e951: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77e952: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77e953: ff15bc517800 CALL dword ptr [0x007851bc]
    const std::uint32_t call_target=m.r32((0x007851bcu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77e959: 8b3dc0517800 MOV EDI,dword ptr [0x007851c0]
    s.di = m.r32((0x007851c0u));
  }
  { // 0x77e95f: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x77e961: 391d200eb100 CMP dword ptr [0x00b10e20],EBX
    (void)integer::sub(m.r32((0x00b10e20u)),s.bx,32,flags);
  }
  { // 0x77e967: 740e JZ 0x0077e977
    if(integer::condition("JZ",flags)) goto L0077e977;
  }
  { // 0x77e969: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77e96a: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x77e96c: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  { // 0x77e96e: e8432cffff CALL 0x007715b6
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x77e973: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77e974: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77e976: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0077e977: { // 0x77e977: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x77e97a: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x77e97d: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x77e980: e81f000000 CALL 0x0077e9a4
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x77e985: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77e988: 894510 MOV dword ptr [EBP + 0x10],EAX
    m.w32((s.bp+0x00000010u), s.ax);
  }
  { // 0x77e98b: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x77e98d: 740a JZ 0x0077e999
    if(integer::condition("JZ",flags)) goto L0077e999;
  }
  { // 0x77e98f: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  { // 0x77e991: e8812cffff CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x77e996: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77e997: eb03 JMP 0x0077e99c
    goto L0077e99c;
  }
  L0077e999: { // 0x77e999: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77e99a: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  L0077e99c: { // 0x77e99c: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  { // 0x77e99f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77e9a0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77e9a1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x77e9a2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x77e9a3: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0038127e(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x78127e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x78127f: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x781281: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x781282: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x781285: 8365fc00 AND dword ptr [EBP + -0x4],0x0
    m.w32((s.bp-0x00000004u), integer::logical((m.r32((s.bp-0x00000004u)))&(0x00000000u),32,flags));
  }
  { // 0x781289: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x78128b: 7443 JZ 0x007812d0
    if(integer::condition("JZ",flags)) goto L007812d0;
  }
  { // 0x78128d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x78128f: 8d550c LEA EDX,[EBP + 0xc]
    s.dx = (s.bp+0x0000000cu);
  }
  { // 0x781292: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x781293: 68488a8100 PUSH 0x818a48
    f.push(m,0x00818a48u);
  }
  { // 0x781298: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x781299: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x78129b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x78129d: 7c31 JL 0x007812d0
    if(integer::condition("JL",flags)) goto L007812d0;
  }
  { // 0x78129f: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x7812a2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7812a3: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x7812a6: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x7812a8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7812a9: ff510c CALL dword ptr [ECX + 0xc]
    const std::uint32_t call_target=m.r32((s.cx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x7812ac: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x7812ae: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x7812b1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7812b2: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x7812b4: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x7812b7: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x7812b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7812ba: 7514 JNZ 0x007812d0
    if(integer::condition("JNZ",flags)) goto L007812d0;
  }
  { // 0x7812bc: 8d45fc LEA EAX,[EBP + -0x4]
    s.ax = (s.bp-0x00000004u);
  }
  { // 0x7812bf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7812c0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x7812c2: ff1550537800 CALL dword ptr [0x00785350]
    const std::uint32_t call_target=m.r32((0x00785350u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x7812c8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7812ca: 7404 JZ 0x007812d0
    if(integer::condition("JZ",flags)) goto L007812d0;
  }
  { // 0x7812cc: 8365fc00 AND dword ptr [EBP + -0x4],0x0
    m.w32((s.bp-0x00000004u), integer::logical((m.r32((s.bp-0x00000004u)))&(0x00000000u),32,flags));
  }
  L007812d0: { // 0x7812d0: ff75fc PUSH dword ptr [EBP + -0x4]
    f.push(m,m.r32((s.bp-0x00000004u)));
  }
  { // 0x7812d3: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x7812d6: e811060000 CALL 0x007818ec
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x7812db: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x7812dc: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_003812df(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7812df: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7812e0: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7812e2: 8d4518 LEA EAX,[EBP + 0x18]
    s.ax = (s.bp+0x00000018u);
  }
  { // 0x7812e5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7812e6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7812e7: 8d4520 LEA EAX,[EBP + 0x20]
    s.ax = (s.bp+0x00000020u);
  }
  { // 0x7812ea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7812eb: ff751c PUSH dword ptr [EBP + 0x1c]
    f.push(m,m.r32((s.bp+0x0000001cu)));
  }
  { // 0x7812ee: ff7518 PUSH dword ptr [EBP + 0x18]
    f.push(m,m.r32((s.bp+0x00000018u)));
  }
  { // 0x7812f1: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x7812f4: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x7812f7: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x7812fa: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x7812fd: e819000000 CALL 0x0078131b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x781302: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x781304: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x781307: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x781309: 7d0b JGE 0x00781316
    if(integer::condition("JGE",flags)) goto L00781316;
  }
  { // 0x78130b: ff7518 PUSH dword ptr [EBP + 0x18]
    f.push(m,m.r32((s.bp+0x00000018u)));
  }
  { // 0x78130e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x781310: ff1568537800 CALL dword ptr [0x00785368]
    const std::uint32_t call_target=m.r32((0x00785368u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00781316: { // 0x781316: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x781318: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x781319: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x78131a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0038183c(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x78183c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x78183d: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x78183f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x781840: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  { // 0x781843: 668365fe00 AND word ptr [EBP + -0x2],0x0
    m.w16((s.bp-0x00000002u), integer::logical((m.r16((s.bp-0x00000002u)))&(0x00000000u),16,flags));
  }
  { // 0x781848: 663d0900 CMP AX,0x9
    (void)integer::sub((s.ax & 0xffffu),0x00000009u,16,flags);
  }
  { // 0x78184c: 668945fc MOV word ptr [EBP + -0x4],AX
    m.w16((s.bp-0x00000004u), (s.ax & 0xffffu));
  }
  { // 0x781850: 740a JZ 0x0078185c
    if(integer::condition("JZ",flags)) goto L0078185c;
  }
  { // 0x781852: 663d0d00 CMP AX,0xd
    (void)integer::sub((s.ax & 0xffffu),0x0000000du,16,flags);
  }
  { // 0x781856: 7404 JZ 0x0078185c
    if(integer::condition("JZ",flags)) goto L0078185c;
  }
  { // 0x781858: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x78185a: eb02 JMP 0x0078185e
    goto L0078185e;
  }
  L0078185c: { // 0x78185c: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L0078185e: { // 0x78185e: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  { // 0x78185f: 8d4d0c LEA ECX,[EBP + 0xc]
    s.cx = (s.bp+0x0000000cu);
  }
  { // 0x781862: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x781863: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x781864: 8d4d14 LEA ECX,[EBP + 0x14]
    s.cx = (s.bp+0x00000014u);
  }
  { // 0x781867: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x781868: 8d4dfc LEA ECX,[EBP + -0x4]
    s.cx = (s.bp-0x00000004u);
  }
  { // 0x78186b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x78186c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x78186e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x781870: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x781871: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x781874: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x781877: e89ffaffff CALL 0x0078131b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x78187c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x78187e: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x781881: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x781883: 7d0b JGE 0x00781890
    if(integer::condition("JGE",flags)) goto L00781890;
  }
  { // 0x781885: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x781888: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x78188a: ff1568537800 CALL dword ptr [0x00785368]
    const std::uint32_t call_target=m.r32((0x00785368u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00781890: { // 0x781890: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x781892: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x781893: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x781894: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0038198b(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x78198b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x78198c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x78198e: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x781991: c706d8d47900 MOV dword ptr [ESI],0x79d4d8
    m.w32((s.si), 0x0079d4d8u);
  }
  { // 0x781997: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x781999: 7406 JZ 0x007819a1
    if(integer::condition("JZ",flags)) goto L007819a1;
  }
  { // 0x78199b: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x78199d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x78199e: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L007819a1: { // 0x7819a1: 8b760c MOV ESI,dword ptr [ESI + 0xc]
    s.si = m.r32((s.si+0x0000000cu));
  }
  { // 0x7819a4: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x7819a6: 7407 JZ 0x007819af
    if(integer::condition("JZ",flags)) goto L007819af;
  }
  { // 0x7819a8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7819a9: ff1528537800 CALL dword ptr [0x00785328]
    const std::uint32_t call_target=m.r32((0x00785328u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L007819af: { // 0x7819af: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7819b0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00382b52(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x782b52: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x782b53: 8b6c2408 MOV EBP,dword ptr [ESP + 0x8]
    s.bp = m.r32((f.sp+0x00000008u));
  }
  { // 0x782b57: b8ffff0000 MOV EAX,0xffff
    s.ax = 0x0000ffffu;
  }
  { // 0x782b5c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x782b5d: 663be8 CMP BP,AX
    (void)integer::sub((s.bp & 0xffffu),(s.ax & 0xffffu),16,flags);
  }
  { // 0x782b60: 7467 JZ 0x00782bc9
    if(integer::condition("JZ",flags)) goto L00782bc9;
  }
  { // 0x782b62: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x782b64: 393d3005b100 CMP dword ptr [0x00b10530],EDI
    (void)integer::sub(m.r32((0x00b10530u)),s.di,32,flags);
  }
  { // 0x782b6a: 7514 JNZ 0x00782b80
    if(integer::condition("JNZ",flags)) goto L00782b80;
  }
  { // 0x782b6c: 6683fd41 CMP BP,0x41
    (void)integer::sub((s.bp & 0xffffu),0x00000041u,16,flags);
  }
  { // 0x782b70: 7209 JC 0x00782b7b
    if(integer::condition("JC",flags)) goto L00782b7b;
  }
  { // 0x782b72: 6683fd5a CMP BP,0x5a
    (void)integer::sub((s.bp & 0xffffu),0x0000005au,16,flags);
  }
  { // 0x782b76: 7703 JA 0x00782b7b
    if(integer::condition("JA",flags)) goto L00782b7b;
  }
  { // 0x782b78: 83c520 ADD EBP,0x20
    s.bp = integer::add(s.bp,0x00000020u,32,flags);
  }
  L00782b7b: { // 0x782b7b: 668bc5 MOV AX,BP
    s.ax = with_ax(s.ax, (s.bp & 0xffffu));
  }
  { // 0x782b7e: eb49 JMP 0x00782bc9
    goto L00782bc9;
  }
  L00782b80: { // 0x782b80: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x782b81: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x782b82: be240eb100 MOV ESI,0xb10e24
    s.si = 0x00b10e24u;
  }
  { // 0x782b87: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x782b88: ff15bc517800 CALL dword ptr [0x007851bc]
    const std::uint32_t call_target=m.r32((0x007851bcu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x782b8e: 393d200eb100 CMP dword ptr [0x00b10e20],EDI
    (void)integer::sub(m.r32((0x00b10e20u)),s.di,32,flags);
  }
  { // 0x782b94: 8b1dc0517800 MOV EBX,dword ptr [0x007851c0]
    s.bx = m.r32((0x007851c0u));
  }
  { // 0x782b9a: 740e JZ 0x00782baa
    if(integer::condition("JZ",flags)) goto L00782baa;
  }
  { // 0x782b9c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x782b9d: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x782b9f: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  { // 0x782ba1: e810eafeff CALL 0x007715b6
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x782ba6: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x782ba7: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x782ba9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00782baa: { // 0x782baa: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x782bab: e81c000000 CALL 0x00782bcc
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x782bb0: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x782bb2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x782bb3: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  { // 0x782bb5: 740a JZ 0x00782bc1
    if(integer::condition("JZ",flags)) goto L00782bc1;
  }
  { // 0x782bb7: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  { // 0x782bb9: e859eafeff CALL 0x00771617
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x782bbe: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x782bbf: eb03 JMP 0x00782bc4
    goto L00782bc4;
  }
  L00782bc1: { // 0x782bc1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x782bc2: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  L00782bc4: { // 0x782bc4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x782bc5: 668bc5 MOV AX,BP
    s.ax = with_ax(s.ax, (s.bp & 0xffffu));
  }
  { // 0x782bc8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00782bc9: { // 0x782bc9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x782bca: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x782bcb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00382ccd(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x782ccd: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x782cce: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x782cd0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x782cd1: 8a4508 MOV AL,byte ptr [EBP + 0x8]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000008u)));
  }
  { // 0x782cd4: 833de48d8100fe CMP dword ptr [0x00818de4],-0x2
    (void)integer::sub(m.r32((0x00818de4u)),0xfffffffeu,32,flags);
  }
  { // 0x782cdb: 88450b MOV byte ptr [EBP + 0xb],AL
    m.w8((s.bp+0x0000000bu), (s.ax & 0xffu));
  }
  { // 0x782cde: 7505 JNZ 0x00782ce5
    if(integer::condition("JNZ",flags)) goto L00782ce5;
  }
  { // 0x782ce0: e87bffffff CALL 0x00782c60
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00782ce5: { // 0x782ce5: a1e48d8100 MOV EAX,[0x00818de4]
    s.ax = m.r32((0x00818de4u));
  }
  { // 0x782cea: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x782ced: 741d JZ 0x00782d0c
    if(integer::condition("JZ",flags)) goto L00782d0c;
  }
  { // 0x782cef: 8d4dfc LEA ECX,[EBP + -0x4]
    s.cx = (s.bp-0x00000004u);
  }
  { // 0x782cf2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x782cf4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x782cf5: 8d4d0b LEA ECX,[EBP + 0xb]
    s.cx = (s.bp+0x0000000bu);
  }
  { // 0x782cf8: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x782cfa: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x782cfb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x782cfc: ff1548537800 CALL dword ptr [0x00785348]
    const std::uint32_t call_target=m.r32((0x00785348u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x782d02: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x782d04: 7406 JZ 0x00782d0c
    if(integer::condition("JZ",flags)) goto L00782d0c;
  }
  { // 0x782d06: 0fb6450b MOVZX EAX,byte ptr [EBP + 0xb]
    s.ax = (m.r8((s.bp+0x0000000bu))&integer::mask(8));
  }
  { // 0x782d0a: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x782d0b: c3 RET
    finish(m,s,f,0u); return;
  }
  L00782d0c: { // 0x782d0c: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x782d0f: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x782d10: c3 RET
    finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,160>& entries_c() {
  static const std::array<Entry,160> entries{{
    {0x25a170u,f_0025a170},
    {0x25a540u,f_0025a540},
    {0x25aaf0u,f_0025aaf0},
    {0x261b50u,f_00261b50},
    {0x261bd0u,f_00261bd0},
    {0x264660u,f_00264660},
    {0x268aa0u,f_00268aa0},
    {0x268af0u,f_00268af0},
    {0x26b020u,f_0026b020},
    {0x26b650u,f_0026b650},
    {0x26bf00u,f_0026bf00},
    {0x270120u,f_00270120},
    {0x270510u,f_00270510},
    {0x278de0u,f_00278de0},
    {0x279ff0u,f_00279ff0},
    {0x290d20u,f_00290d20},
    {0x296d50u,f_00296d50},
    {0x297500u,f_00297500},
    {0x2a03b0u,f_002a03b0},
    {0x2aaaf0u,f_002aaaf0},
    {0x2b0a70u,f_002b0a70},
    {0x2b6920u,f_002b6920},
    {0x2b6970u,f_002b6970},
    {0x2b7bc0u,f_002b7bc0},
    {0x2ba6a0u,f_002ba6a0},
    {0x2ba7d0u,f_002ba7d0},
    {0x2bca20u,f_002bca20},
    {0x2bca60u,f_002bca60},
    {0x2bd870u,f_002bd870},
    {0x2be7a0u,f_002be7a0},
    {0x2bf060u,f_002bf060},
    {0x2c2840u,f_002c2840},
    {0x2c28b0u,f_002c28b0},
    {0x2c2ba0u,f_002c2ba0},
    {0x2c2c00u,f_002c2c00},
    {0x2c2db0u,f_002c2db0},
    {0x2c2df0u,f_002c2df0},
    {0x2c6920u,f_002c6920},
    {0x2c93c0u,f_002c93c0},
    {0x2c9880u,f_002c9880},
    {0x2c9e60u,f_002c9e60},
    {0x2cadc0u,f_002cadc0},
    {0x2cce80u,f_002cce80},
    {0x2cd960u,f_002cd960},
    {0x2cda10u,f_002cda10},
    {0x2cda90u,f_002cda90},
    {0x2cdab0u,f_002cdab0},
    {0x2cdb10u,f_002cdb10},
    {0x2ceb10u,f_002ceb10},
    {0x2ceb40u,f_002ceb40},
    {0x2ceb80u,f_002ceb80},
    {0x2d4e30u,f_002d4e30},
    {0x2d7040u,f_002d7040},
    {0x2d79e0u,f_002d79e0},
    {0x2dd5d0u,f_002dd5d0},
    {0x2e0740u,f_002e0740},
    {0x2e1120u,f_002e1120},
    {0x2e76c0u,f_002e76c0},
    {0x2e7aa0u,f_002e7aa0},
    {0x2ec4b0u,f_002ec4b0},
    {0x2ecc20u,f_002ecc20},
    {0x2eece0u,f_002eece0},
    {0x2f2230u,f_002f2230},
    {0x2f9300u,f_002f9300},
    {0x2f9720u,f_002f9720},
    {0x2fe580u,f_002fe580},
    {0x303d30u,f_00303d30},
    {0x303e80u,f_00303e80},
    {0x3083d0u,f_003083d0},
    {0x30b350u,f_0030b350},
    {0x312a30u,f_00312a30},
    {0x312bb0u,f_00312bb0},
    {0x314a00u,f_00314a00},
    {0x316c00u,f_00316c00},
    {0x3195b0u,f_003195b0},
    {0x31aea0u,f_0031aea0},
    {0x31b570u,f_0031b570},
    {0x31bad0u,f_0031bad0},
    {0x31bb90u,f_0031bb90},
    {0x31ce30u,f_0031ce30},
    {0x31cf10u,f_0031cf10},
    {0x31cfd0u,f_0031cfd0},
    {0x31f1c0u,f_0031f1c0},
    {0x31f1e0u,f_0031f1e0},
    {0x31f220u,f_0031f220},
    {0x3204b0u,f_003204b0},
    {0x320570u,f_00320570},
    {0x321a90u,f_00321a90},
    {0x321ae0u,f_00321ae0},
    {0x325ce0u,f_00325ce0},
    {0x328d30u,f_00328d30},
    {0x329510u,f_00329510},
    {0x329830u,f_00329830},
    {0x32a1d0u,f_0032a1d0},
    {0x32a250u,f_0032a250},
    {0x32a760u,f_0032a760},
    {0x32b440u,f_0032b440},
    {0x32b460u,f_0032b460},
    {0x32ba30u,f_0032ba30},
    {0x32bc20u,f_0032bc20},
    {0x32c620u,f_0032c620},
    {0x330d00u,f_00330d00},
    {0x33ee50u,f_0033ee50},
    {0x34a170u,f_0034a170},
    {0x34a1f0u,f_0034a1f0},
    {0x3529f0u,f_003529f0},
    {0x3549a0u,f_003549a0},
    {0x3558e0u,f_003558e0},
    {0x356f40u,f_00356f40},
    {0x356fb0u,f_00356fb0},
    {0x35ef70u,f_0035ef70},
    {0x35f0d0u,f_0035f0d0},
    {0x35f100u,f_0035f100},
    {0x35f130u,f_0035f130},
    {0x35f1e0u,f_0035f1e0},
    {0x35f240u,f_0035f240},
    {0x35fb10u,f_0035fb10},
    {0x35fb60u,f_0035fb60},
    {0x35fcd0u,f_0035fcd0},
    {0x360760u,f_00360760},
    {0x361c80u,f_00361c80},
    {0x361d60u,f_00361d60},
    {0x366890u,f_00366890},
    {0x36df28u,f_0036df28},
    {0x36dfaeu,f_0036dfae},
    {0x36e313u,f_0036e313},
    {0x36fb34u,f_0036fb34},
    {0x36ff39u,f_0036ff39},
    {0x36ff68u,f_0036ff68},
    {0x36ff8bu,f_0036ff8b},
    {0x36ffbau,f_0036ffba},
    {0x3707afu,f_003707af},
    {0x370cacu,f_00370cac},
    {0x370f78u,f_00370f78},
    {0x371521u,f_00371521},
    {0x373271u,f_00373271},
    {0x374c3du,f_00374c3d},
    {0x374f46u,f_00374f46},
    {0x374fcbu,f_00374fcb},
    {0x377542u,f_00377542},
    {0x379100u,f_00379100},
    {0x379f36u,f_00379f36},
    {0x37b1cau,f_0037b1ca},
    {0x37b2ddu,f_0037b2dd},
    {0x37b3b4u,f_0037b3b4},
    {0x37b439u,f_0037b439},
    {0x37b6ddu,f_0037b6dd},
    {0x37b7bdu,f_0037b7bd},
    {0x37b816u,f_0037b816},
    {0x37d34au,f_0037d34a},
    {0x37d3c6u,f_0037d3c6},
    {0x37d52eu,f_0037d52e},
    {0x37dc05u,f_0037dc05},
    {0x37e947u,f_0037e947},
    {0x38127eu,f_0038127e},
    {0x3812dfu,f_003812df},
    {0x38183cu,f_0038183c},
    {0x38198bu,f_0038198b},
    {0x382b52u,f_00382b52},
    {0x382ccdu,f_00382ccd},
  }}; return entries;
}
} // namespace ra2::recovered::mixed_b35
