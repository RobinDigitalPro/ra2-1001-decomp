#include "recovered/recovery_b1551_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1551 {
namespace {
void f_0001a080(Memory&,State&,Frame&,const Operations&);
void f_002d4b70(Memory&,State&,Frame&,const Operations&);
void f_001ccea0(Memory&,State&,Frame&,const Operations&);
void f_00157070(Memory&,State&,Frame&,const Operations&);
void f_000702c0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_0001a080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041a080: { // 0x41a080: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041a081: { // 0x41a081: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L0041a083: { // 0x41a083: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0041a084: { // 0x41a084: 8b8eac050000 MOV ECX, dword ptr [ESI + 0x5ac]
    s.cx = m.r32((s.si+0x000005acu));
  }
  L0041a08a: { // 0x41a08a: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0041a08c: { // 0x41a08c: ff90bc000000 CALL dword ptr [EAX + 0xbc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000bcu)),4300946u); flags=s.arithmetic_flags;
  }
  L0041a092: { // 0x41a092: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0041a094: { // 0x41a094: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0041a096: { // 0x41a096: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0041a098: { // 0x41a098: ff92b0010000 CALL dword ptr [EDX + 0x1b0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001b0u)),4300958u); flags=s.arithmetic_flags;
  }
  L0041a09e: { // 0x41a09e: 3bc7 CMP EAX, EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0041a0a0: { // 0x41a0a0: 7520 JNZ 0x41a0c2
    if(integer::condition("JNZ",flags)) goto L0041a0c2;
  }
  L0041a0a2: { // 0x41a0a2: 8b86c4040000 MOV EAX, dword ptr [ESI + 0x4c4]
    s.ax = m.r32((s.si+0x000004c4u));
  }
  L0041a0a8: { // 0x41a0a8: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041a0aa: { // 0x41a0aa: 750e JNZ 0x41a0ba
    if(integer::condition("JNZ",flags)) goto L0041a0ba;
  }
  L0041a0ac: { // 0x41a0ac: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0041a0ae: { // 0x41a0ae: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0041a0b0: { // 0x41a0b0: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0041a0b2: { // 0x41a0b2: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0041a0b4: { // 0x41a0b4: ff9014040000 CALL dword ptr [EAX + 0x414]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000414u)),4300986u); flags=s.arithmetic_flags;
  }
  L0041a0ba: { // 0x41a0ba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041a0bb: { // 0x41a0bb: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L0041a0c0: { // 0x41a0c0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041a0c1: { // 0x41a0c1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0041a0c2: { // 0x41a0c2: 8b8654020000 MOV EAX, dword ptr [ESI + 0x254]
    s.ax = m.r32((s.si+0x00000254u));
  }
  L0041a0c8: { // 0x41a0c8: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041a0ca: { // 0x41a0ca: 7527 JNZ 0x41a0f3
    if(integer::condition("JNZ",flags)) goto L0041a0f3;
  }
  L0041a0cc: { // 0x41a0cc: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0041a0ce: { // 0x41a0ce: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0041a0d0: { // 0x41a0d0: ff928c020000 CALL dword ptr [EDX + 0x28c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000028cu)),4301014u); flags=s.arithmetic_flags;
  }
  L0041a0d6: { // 0x41a0d6: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041a0d8: { // 0x41a0d8: 7419 JZ 0x41a0f3
    if(integer::condition("JZ",flags)) goto L0041a0f3;
  }
  L0041a0da: { // 0x41a0da: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0041a0dc: { // 0x41a0dc: e8cf432100 CALL 0x62e4b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062e4b0u,4301025u); flags=s.arithmetic_flags;
  }
  L0041a0e1: { // 0x41a0e1: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041a0e3: { // 0x41a0e3: 750e JNZ 0x41a0f3
    if(integer::condition("JNZ",flags)) goto L0041a0f3;
  }
  L0041a0e5: { // 0x41a0e5: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0041a0e7: { // 0x41a0e7: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0041a0e9: { // 0x41a0e9: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0041a0eb: { // 0x41a0eb: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0041a0ed: { // 0x41a0ed: ff9014040000 CALL dword ptr [EAX + 0x414]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000414u)),4301043u); flags=s.arithmetic_flags;
  }
  L0041a0f3: { // 0x41a0f3: 8b8628020000 MOV EAX, dword ptr [ESI + 0x228]
    s.ax = m.r32((s.si+0x00000228u));
  }
  L0041a0f9: { // 0x41a0f9: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041a0fb: { // 0x41a0fb: 7416 JZ 0x41a113
    if(integer::condition("JZ",flags)) goto L0041a113;
  }
  L0041a0fd: { // 0x41a0fd: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0041a0ff: { // 0x41a0ff: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0041a101: { // 0x41a101: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0041a103: { // 0x41a103: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0041a105: { // 0x41a105: ff92d0010000 CALL dword ptr [EDX + 0x1d0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001d0u)),4301067u); flags=s.arithmetic_flags;
  }
  L0041a10b: { // 0x41a10b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041a10c: { // 0x41a10c: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L0041a111: { // 0x41a111: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041a112: { // 0x41a112: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0041a113: { // 0x41a113: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0041a115: { // 0x41a115: e846b40a00 CALL 0x4c5560
    s.arithmetic_flags=flags; invoke(m,s,f,0x004c5560u,4301082u); flags=s.arithmetic_flags;
  }
  L0041a11a: { // 0x41a11a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041a11b: { // 0x41a11b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041a11c: { // 0x41a11c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002d4b70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4b70: { // 0x6d4b70: 8b8158050000 MOV EAX, dword ptr [ECX + 0x558]
    s.ax = m.r32((s.cx+0x00000558u));
  }
  L006d4b76: { // 0x6d4b76: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L006d4b79: { // 0x6d4b79: 750b JNZ 0x6d4b86
    if(integer::condition("JNZ",flags)) goto L006d4b86;
  }
  L006d4b7b: { // 0x6d4b7b: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006d4b80: { // 0x6d4b80: 8b80dc060000 MOV EAX, dword ptr [EAX + 0x6dc]
    s.ax = m.r32((s.ax+0x000006dcu));
  }
  L006d4b86: { // 0x6d4b86: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001ccea0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005ccea0: { // 0x5ccea0: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L005ccea3: { // 0x5ccea3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005ccea4: { // 0x5ccea4: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L005ccea6: { // 0x5ccea6: 8d8688000000 LEA EAX, [ESI + 0x88]
    s.ax = (s.si+0x00000088u);
  }
  L005cceac: { // 0x5cceac: 8b8e88000000 MOV ECX, dword ptr [ESI + 0x88]
    s.cx = m.r32((s.si+0x00000088u));
  }
  L005cceb2: { // 0x5cceb2: 894c2404 MOV dword ptr [ESP + 4], ECX
    m.w32((f.sp+4u), s.cx);
  }
  L005cceb6: { // 0x5cceb6: 8d4c2404 LEA ECX, [ESP + 4]
    s.cx = (f.sp+4u);
  }
  L005cceba: { // 0x5cceba: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L005ccebd: { // 0x5ccebd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005ccebe: { // 0x5ccebe: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L005ccec3: { // 0x5ccec3: 8954240c MOV dword ptr [ESP + 0xc], EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L005ccec7: { // 0x5ccec7: 8b4008 MOV EAX, dword ptr [EAX + 8]
    s.ax = m.r32((s.ax+8u));
  }
  L005cceca: { // 0x5cceca: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005ccece: { // 0x5ccece: e89da1f8ff CALL 0x557070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557070u,6082259u); flags=s.arithmetic_flags;
  }
  L005cced3: { // 0x5cced3: 8b8e90000000 MOV ECX, dword ptr [ESI + 0x90]
    s.cx = m.r32((s.si+0x00000090u));
  }
  L005cced9: { // 0x5cced9: 2bc8 SUB ECX, EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L005ccedb: { // 0x5ccedb: 8a4679 MOV AL, byte ptr [ESI + 0x79]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000079u)));
  }
  L005ccede: { // 0x5ccede: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ccee0: { // 0x5ccee0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ccee1: { // 0x5ccee1: 7406 JZ 0x5ccee9
    if(integer::condition("JZ",flags)) goto L005ccee9;
  }
  L005ccee3: { // 0x5ccee3: 2b0d98aaa500 SUB ECX, dword ptr [0xa5aa98]
    s.cx = integer::sub(s.cx,m.r32((0x00a5aa98u)),32,flags);
  }
  L005ccee9: { // 0x5ccee9: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L005cceeb: { // 0x5cceeb: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005cceee: { // 0x5cceee: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00157070(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557070: { // 0x557070: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L00557073: { // 0x557073: 8b4c240c MOV ECX, dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00557077: { // 0x557077: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00557078: { // 0x557078: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0055707a: { // 0x55707a: 8b5104 MOV EDX, dword ptr [ECX + 4]
    s.dx = m.r32((s.cx+4u));
  }
  L0055707d: { // 0x55707d: 89442404 MOV dword ptr [ESP + 4], EAX
    m.w32((f.sp+4u), s.ax);
  }
  L00557081: { // 0x557081: 89542408 MOV dword ptr [ESP + 8], EDX
    m.w32((f.sp+8u), s.dx);
  }
  L00557085: { // 0x557085: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00557086: { // 0x557086: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055708c: { // 0x55708c: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055708e: { // 0x55708e: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L00557090: { // 0x557090: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L00557093: { // 0x557093: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00557094: { // 0x557094: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055709a: { // 0x55709a: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055709c: { // 0x55709c: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0055709f: { // 0x55709f: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L005570a1: { // 0x5570a1: c1fe08 SAR ESI, 8
    s.si = integer::shift(s.si,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005570a4: { // 0x5570a4: c1e109 SHL ECX, 9
    s.cx = integer::shift(s.cx,9u,32,flags,integer::Shift::left);
  }
  L005570a7: { // 0x5570a7: 03ce ADD ECX, ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L005570a9: { // 0x5570a9: 7815 JS 0x5570c0
    if(integer::condition("JS",flags)) goto L005570c0;
  }
  L005570ab: { // 0x5570ab: 3b0d5ca98100 CMP ECX, dword ptr [0x81a95c]
    (void)integer::sub(s.cx,m.r32((0x0081a95cu)),32,flags);
  }
  L005570b1: { // 0x5570b1: 7d0d JGE 0x5570c0
    if(integer::condition("JGE",flags)) goto L005570c0;
  }
  L005570b3: { // 0x5570b3: 8b1558a98100 MOV EDX, dword ptr [0x81a958]
    s.dx = m.r32((0x0081a958u));
  }
  L005570b9: { // 0x5570b9: 8b0c8a MOV ECX, dword ptr [EDX + ECX*4]
    s.cx = m.r32((s.dx+(s.cx * 4u)));
  }
  L005570bc: { // 0x5570bc: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005570be: { // 0x5570be: 7518 JNZ 0x5570d8
    if(integer::condition("JNZ",flags)) goto L005570d8;
  }
  L005570c0: { // 0x5570c0: 6689742410 MOV word ptr [ESP + 0x10], SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L005570c5: { // 0x5570c5: 6689442412 MOV word ptr [ESP + 0x12], AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L005570ca: { // 0x5570ca: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005570ce: { // 0x5570ce: b91076a500 MOV ECX, 0xa57610
    s.cx = 0x00a57610u;
  }
  L005570d3: { // 0x5570d3: a33476a500 MOV dword ptr [0xa57634], EAX
    m.w32((0x00a57634u), s.ax);
  }
  L005570d8: { // 0x5570d8: 8d542404 LEA EDX, [ESP + 4]
    s.dx = (f.sp+4u);
  }
  L005570dc: { // 0x5570dc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005570dd: { // 0x5570dd: e8de91f1ff CALL 0x4702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,5599458u); flags=s.arithmetic_flags;
  }
  L005570e2: { // 0x5570e2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005570e3: { // 0x5570e3: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L005570e6: { // 0x5570e6: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000702c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004702c0: { // 0x4702c0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004702c1: { // 0x4702c1: 8bec MOV EBP, ESP
    s.bp = f.sp;
  }
  L004702c3: { // 0x4702c3: 83e4f8 AND ESP, 0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L004702c6: { // 0x4702c6: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004702c9: { // 0x4702c9: a0708f8300 MOV AL, byte ptr [0x838f70]
    s.ax = with_al(s.ax, m.r8((0x00838f70u)));
  }
  L004702ce: { // 0x4702ce: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004702cf: { // 0x4702cf: a801 TEST AL, 1
    (void)integer::logical(((s.ax & 0xffu))&(1u),8,flags);
  }
  L004702d1: { // 0x4702d1: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004702d3: { // 0x4702d3: 7513 JNZ 0x4702e8
    if(integer::condition("JNZ",flags)) goto L004702e8;
  }
  L004702d5: { // 0x4702d5: db05808f8300 FILD dword ptr [0x838f80]
    const auto address=(0x00838f80u);
    s.fp.load_integer32(m.r32(address));
  }
  L004702db: { // 0x4702db: 0c01 OR AL, 1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(1u),8,flags));
  }
  L004702dd: { // 0x4702dd: a2708f8300 MOV byte ptr [0x838f70], AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L004702e2: { // 0x4702e2: dd1df08e8300 FSTP qword ptr [0x838ef0]
    const auto address=(0x00838ef0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004702e8: { // 0x4702e8: a802 TEST AL, 2
    (void)integer::logical(((s.ax & 0xffu))&(2u),8,flags);
  }
  L004702ea: { // 0x4702ea: 7519 JNZ 0x470305
    if(integer::condition("JNZ",flags)) goto L00470305;
  }
  L004702ec: { // 0x4702ec: dd05f08e8300 FLD qword ptr [0x838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004702f2: { // 0x4702f2: dc0d30577800 FMUL qword ptr [0x785730]
    const auto address=(0x00785730u);
    s.fp.multiply64(read64(m,address));
  }
  L004702f8: { // 0x4702f8: 0c02 OR AL, 2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(2u),8,flags));
  }
  L004702fa: { // 0x4702fa: a2708f8300 MOV byte ptr [0x838f70], AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L004702ff: { // 0x4702ff: dd1d108f8300 FSTP qword ptr [0x838f10]
    const auto address=(0x00838f10u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00470305: { // 0x470305: a804 TEST AL, 4
    (void)integer::logical(((s.ax & 0xffu))&(4u),8,flags);
  }
  L00470307: { // 0x470307: 0f85a7060000 JNZ 0x4709b4
    if(integer::condition("JNZ",flags)) goto L004709b4;
  }
  L0047030d: { // 0x47030d: 8b0df48e8300 MOV ECX, dword ptr [0x838ef4]
    s.cx = m.r32((0x00838ef4u));
  }
  L00470313: { // 0x470313: 0c04 OR AL, 4
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(4u),8,flags));
  }
  L00470315: { // 0x470315: a2708f8300 MOV byte ptr [0x838f70], AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L0047031a: { // 0x47031a: a1f08e8300 MOV EAX, dword ptr [0x838ef0]
    s.ax = m.r32((0x00838ef0u));
  }
  L0047031f: { // 0x47031f: a398d77b00 MOV dword ptr [0x7bd798], EAX
    m.w32((0x007bd798u), s.ax);
  }
  L00470324: { // 0x470324: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00470326: { // 0x470326: 890d9cd77b00 MOV dword ptr [0x7bd79c], ECX
    m.w32((0x007bd79cu), s.cx);
  }
  L0047032c: { // 0x47032c: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0047032e: { // 0x47032e: 8915c0d77b00 MOV dword ptr [0x7bd7c0], EDX
    m.w32((0x007bd7c0u), s.dx);
  }
  L00470334: { // 0x470334: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00470336: { // 0x470336: a3c4d77b00 MOV dword ptr [0x7bd7c4], EAX
    m.w32((0x007bd7c4u), s.ax);
  }
  L0047033b: { // 0x47033b: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L0047033d: { // 0x47033d: 890de0d77b00 MOV dword ptr [0x7bd7e0], ECX
    m.w32((0x007bd7e0u), s.cx);
  }
  L00470343: { // 0x470343: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00470345: { // 0x470345: 8915e4d77b00 MOV dword ptr [0x7bd7e4], EDX
    m.w32((0x007bd7e4u), s.dx);
  }
  L0047034b: { // 0x47034b: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L0047034d: { // 0x47034d: dd05f08e8300 FLD qword ptr [0x838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L00470353: { // 0x470353: a3e8d77b00 MOV dword ptr [0x7bd7e8], EAX
    m.w32((0x007bd7e8u), s.ax);
  }
  L00470358: { // 0x470358: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L0047035a: { // 0x47035a: 890decd77b00 MOV dword ptr [0x7bd7ec], ECX
    m.w32((0x007bd7ecu), s.cx);
  }
  L00470360: { // 0x470360: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00470362: { // 0x470362: 891508d87b00 MOV dword ptr [0x7bd808], EDX
    m.w32((0x007bd808u), s.dx);
  }
  L00470368: { // 0x470368: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L0047036a: { // 0x47036a: a30cd87b00 MOV dword ptr [0x7bd80c], EAX
    m.w32((0x007bd80cu), s.ax);
  }
  L0047036f: { // 0x47036f: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00470371: { // 0x470371: 890d10d87b00 MOV dword ptr [0x7bd810], ECX
    m.w32((0x007bd810u), s.cx);
  }
  L00470377: { // 0x470377: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00470379: { // 0x470379: 891514d87b00 MOV dword ptr [0x7bd814], EDX
    m.w32((0x007bd814u), s.dx);
  }
  L0047037f: { // 0x47037f: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00470381: { // 0x470381: a338d87b00 MOV dword ptr [0x7bd838], EAX
    m.w32((0x007bd838u), s.ax);
  }
  L00470386: { // 0x470386: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00470388: { // 0x470388: 890d3cd87b00 MOV dword ptr [0x7bd83c], ECX
    m.w32((0x007bd83cu), s.cx);
  }
  L0047038e: { // 0x47038e: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00470390: { // 0x470390: 891560d87b00 MOV dword ptr [0x7bd860], EDX
    m.w32((0x007bd860u), s.dx);
  }
  L00470396: { // 0x470396: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00470398: { // 0x470398: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L0047039a: { // 0x47039a: dd1d30d87b00 FSTP qword ptr [0x7bd830]
    const auto address=(0x007bd830u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004703a0: { // 0x4703a0: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L004703a2: { // 0x4703a2: c705a0d77b0000000000 MOV dword ptr [0x7bd7a0], 0
    m.w32((0x007bd7a0u), 0u);
  }
  L004703ac: { // 0x4703ac: c705a4d77b0000000000 MOV dword ptr [0x7bd7a4], 0
    m.w32((0x007bd7a4u), 0u);
  }
  L004703b6: { // 0x4703b6: c705a8d77b0000000000 MOV dword ptr [0x7bd7a8], 0
    m.w32((0x007bd7a8u), 0u);
  }
  L004703c0: { // 0x4703c0: c705acd77b0000000000 MOV dword ptr [0x7bd7ac], 0
    m.w32((0x007bd7acu), 0u);
  }
  L004703ca: { // 0x4703ca: c705b0d77b0000000000 MOV dword ptr [0x7bd7b0], 0
    m.w32((0x007bd7b0u), 0u);
  }
  L004703d4: { // 0x4703d4: c705b4d77b000000f03f MOV dword ptr [0x7bd7b4], 0x3ff00000
    m.w32((0x007bd7b4u), 0x3ff00000u);
  }
  L004703de: { // 0x4703de: c705b8d77b0000000000 MOV dword ptr [0x7bd7b8], 0
    m.w32((0x007bd7b8u), 0u);
  }
  L004703e8: { // 0x4703e8: c705bcd77b0000000000 MOV dword ptr [0x7bd7bc], 0
    m.w32((0x007bd7bcu), 0u);
  }
  L004703f2: { // 0x4703f2: c705c8d77b0000000000 MOV dword ptr [0x7bd7c8], 0
    m.w32((0x007bd7c8u), 0u);
  }
  L004703fc: { // 0x4703fc: c705ccd77b0000000000 MOV dword ptr [0x7bd7cc], 0
    m.w32((0x007bd7ccu), 0u);
  }
  L00470406: { // 0x470406: c705d0d77b0000000000 MOV dword ptr [0x7bd7d0], 0
    m.w32((0x007bd7d0u), 0u);
  }
  L00470410: { // 0x470410: c705d4d77b000000f0bf MOV dword ptr [0x7bd7d4], 0xbff00000
    m.w32((0x007bd7d4u), 0xbff00000u);
  }
  L0047041a: { // 0x47041a: c705d8d77b0000000000 MOV dword ptr [0x7bd7d8], 0
    m.w32((0x007bd7d8u), 0u);
  }
  L00470424: { // 0x470424: c705dcd77b0000000000 MOV dword ptr [0x7bd7dc], 0
    m.w32((0x007bd7dcu), 0u);
  }
  L0047042e: { // 0x47042e: c705f0d77b0000000000 MOV dword ptr [0x7bd7f0], 0
    m.w32((0x007bd7f0u), 0u);
  }
  L00470438: { // 0x470438: c705f4d77b0000000000 MOV dword ptr [0x7bd7f4], 0
    m.w32((0x007bd7f4u), 0u);
  }
  L00470442: { // 0x470442: c705f8d77b0000000000 MOV dword ptr [0x7bd7f8], 0
    m.w32((0x007bd7f8u), 0u);
  }
  L0047044c: { // 0x47044c: c705fcd77b0000000000 MOV dword ptr [0x7bd7fc], 0
    m.w32((0x007bd7fcu), 0u);
  }
  L00470456: { // 0x470456: c70500d87b0000000000 MOV dword ptr [0x7bd800], 0
    m.w32((0x007bd800u), 0u);
  }
  L00470460: { // 0x470460: c70504d87b000000f0bf MOV dword ptr [0x7bd804], 0xbff00000
    m.w32((0x007bd804u), 0xbff00000u);
  }
  L0047046a: { // 0x47046a: c70518d87b0000000000 MOV dword ptr [0x7bd818], 0
    m.w32((0x007bd818u), 0u);
  }
  L00470474: { // 0x470474: c7051cd87b0000000000 MOV dword ptr [0x7bd81c], 0
    m.w32((0x007bd81cu), 0u);
  }
  L0047047e: { // 0x47047e: c70520d87b0000000000 MOV dword ptr [0x7bd820], 0
    m.w32((0x007bd820u), 0u);
  }
  L00470488: { // 0x470488: c70524d87b000000f03f MOV dword ptr [0x7bd824], 0x3ff00000
    m.w32((0x007bd824u), 0x3ff00000u);
  }
  L00470492: { // 0x470492: c70528d87b0000000000 MOV dword ptr [0x7bd828], 0
    m.w32((0x007bd828u), 0u);
  }
  L0047049c: { // 0x47049c: c7052cd87b000000f03f MOV dword ptr [0x7bd82c], 0x3ff00000
    m.w32((0x007bd82cu), 0x3ff00000u);
  }
  L004704a6: { // 0x4704a6: c70540d87b0000000000 MOV dword ptr [0x7bd840], 0
    m.w32((0x007bd840u), 0u);
  }
  L004704b0: { // 0x4704b0: c70544d87b0000000000 MOV dword ptr [0x7bd844], 0
    m.w32((0x007bd844u), 0u);
  }
  L004704ba: { // 0x4704ba: c70548d87b0000000000 MOV dword ptr [0x7bd848], 0
    m.w32((0x007bd848u), 0u);
  }
  L004704c4: { // 0x4704c4: c7054cd87b000000f0bf MOV dword ptr [0x7bd84c], 0xbff00000
    m.w32((0x007bd84cu), 0xbff00000u);
  }
  L004704ce: { // 0x4704ce: c70550d87b0000000000 MOV dword ptr [0x7bd850], 0
    m.w32((0x007bd850u), 0u);
  }
  L004704d8: { // 0x4704d8: c70554d87b000000f03f MOV dword ptr [0x7bd854], 0x3ff00000
    m.w32((0x007bd854u), 0x3ff00000u);
  }
  L004704e2: { // 0x4704e2: c70558d87b0000000000 MOV dword ptr [0x7bd858], 0
    m.w32((0x007bd858u), 0u);
  }
  L004704ec: { // 0x4704ec: c7055cd87b0000000000 MOV dword ptr [0x7bd85c], 0
    m.w32((0x007bd85cu), 0u);
  }
  L004704f6: { // 0x4704f6: a364d87b00 MOV dword ptr [0x7bd864], EAX
    m.w32((0x007bd864u), s.ax);
  }
  L004704fb: { // 0x4704fb: c70568d87b0000000000 MOV dword ptr [0x7bd868], 0
    m.w32((0x007bd868u), 0u);
  }
  L00470505: { // 0x470505: c7056cd87b0000000000 MOV dword ptr [0x7bd86c], 0
    m.w32((0x007bd86cu), 0u);
  }
  L0047050f: { // 0x47050f: c70570d87b0000000000 MOV dword ptr [0x7bd870], 0
    m.w32((0x007bd870u), 0u);
  }
  L00470519: { // 0x470519: c70574d87b000000f0bf MOV dword ptr [0x7bd874], 0xbff00000
    m.w32((0x007bd874u), 0xbff00000u);
  }
  L00470523: { // 0x470523: c70578d87b0000000000 MOV dword ptr [0x7bd878], 0
    m.w32((0x007bd878u), 0u);
  }
  L0047052d: { // 0x47052d: c7057cd87b000000f0bf MOV dword ptr [0x7bd87c], 0xbff00000
    m.w32((0x007bd87cu), 0xbff00000u);
  }
  L00470537: { // 0x470537: 890d80d87b00 MOV dword ptr [0x7bd880], ECX
    m.w32((0x007bd880u), s.cx);
  }
  L0047053d: { // 0x47053d: 891584d87b00 MOV dword ptr [0x7bd884], EDX
    m.w32((0x007bd884u), s.dx);
  }
  L00470543: { // 0x470543: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00470545: { // 0x470545: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00470547: { // 0x470547: a388d87b00 MOV dword ptr [0x7bd888], EAX
    m.w32((0x007bd888u), s.ax);
  }
  L0047054c: { // 0x47054c: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L0047054e: { // 0x47054e: dd05f08e8300 FLD qword ptr [0x838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L00470554: { // 0x470554: 890d8cd87b00 MOV dword ptr [0x7bd88c], ECX
    m.w32((0x007bd88cu), s.cx);
  }
  L0047055a: { // 0x47055a: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0047055c: { // 0x47055c: 8915b0d87b00 MOV dword ptr [0x7bd8b0], EDX
    m.w32((0x007bd8b0u), s.dx);
  }
  L00470562: { // 0x470562: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00470564: { // 0x470564: a3b4d87b00 MOV dword ptr [0x7bd8b4], EAX
    m.w32((0x007bd8b4u), s.ax);
  }
  L00470569: { // 0x470569: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L0047056b: { // 0x47056b: 890dd8d87b00 MOV dword ptr [0x7bd8d8], ECX
    m.w32((0x007bd8d8u), s.cx);
  }
  L00470571: { // 0x470571: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00470573: { // 0x470573: 8915dcd87b00 MOV dword ptr [0x7bd8dc], EDX
    m.w32((0x007bd8dcu), s.dx);
  }
  L00470579: { // 0x470579: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L0047057b: { // 0x47057b: a3f8d87b00 MOV dword ptr [0x7bd8f8], EAX
    m.w32((0x007bd8f8u), s.ax);
  }
  L00470580: { // 0x470580: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00470582: { // 0x470582: 890dfcd87b00 MOV dword ptr [0x7bd8fc], ECX
    m.w32((0x007bd8fcu), s.cx);
  }
  L00470588: { // 0x470588: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0047058a: { // 0x47058a: 891500d97b00 MOV dword ptr [0x7bd900], EDX
    m.w32((0x007bd900u), s.dx);
  }
  L00470590: { // 0x470590: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00470592: { // 0x470592: a304d97b00 MOV dword ptr [0x7bd904], EAX
    m.w32((0x007bd904u), s.ax);
  }
  L00470597: { // 0x470597: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00470599: { // 0x470599: dcc0 FADD st(0), st(0)
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L0047059b: { // 0x47059b: 890d28d97b00 MOV dword ptr [0x7bd928], ECX
    m.w32((0x007bd928u), s.cx);
  }
  L004705a1: { // 0x4705a1: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L004705a3: { // 0x4705a3: 89152cd97b00 MOV dword ptr [0x7bd92c], EDX
    m.w32((0x007bd92cu), s.dx);
  }
  L004705a9: { // 0x4705a9: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L004705ab: { // 0x4705ab: a348d97b00 MOV dword ptr [0x7bd948], EAX
    m.w32((0x007bd948u), s.ax);
  }
  L004705b0: { // 0x4705b0: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L004705b2: { // 0x4705b2: dd1520d97b00 FST qword ptr [0x7bd920]
    const auto address=(0x007bd920u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004705b8: { // 0x4705b8: dd1578d97b00 FST qword ptr [0x7bd978]
    const auto address=(0x007bd978u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004705be: { // 0x4705be: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L004705c0: { // 0x4705c0: c70590d87b0000000000 MOV dword ptr [0x7bd890], 0
    m.w32((0x007bd890u), 0u);
  }
  L004705ca: { // 0x4705ca: c70594d87b0000000000 MOV dword ptr [0x7bd894], 0
    m.w32((0x007bd894u), 0u);
  }
  L004705d4: { // 0x4705d4: c70598d87b0000000000 MOV dword ptr [0x7bd898], 0
    m.w32((0x007bd898u), 0u);
  }
  L004705de: { // 0x4705de: c7059cd87b000000f03f MOV dword ptr [0x7bd89c], 0x3ff00000
    m.w32((0x007bd89cu), 0x3ff00000u);
  }
  L004705e8: { // 0x4705e8: c705a0d87b0000000000 MOV dword ptr [0x7bd8a0], 0
    m.w32((0x007bd8a0u), 0u);
  }
  L004705f2: { // 0x4705f2: c705a4d87b000000f0bf MOV dword ptr [0x7bd8a4], 0xbff00000
    m.w32((0x007bd8a4u), 0xbff00000u);
  }
  L004705fc: { // 0x4705fc: c705a8d87b0000000000 MOV dword ptr [0x7bd8a8], 0
    m.w32((0x007bd8a8u), 0u);
  }
  L00470606: { // 0x470606: c705acd87b0000000000 MOV dword ptr [0x7bd8ac], 0
    m.w32((0x007bd8acu), 0u);
  }
  L00470610: { // 0x470610: c705b8d87b0000000000 MOV dword ptr [0x7bd8b8], 0
    m.w32((0x007bd8b8u), 0u);
  }
  L0047061a: { // 0x47061a: c705bcd87b0000000000 MOV dword ptr [0x7bd8bc], 0
    m.w32((0x007bd8bcu), 0u);
  }
  L00470624: { // 0x470624: c705c0d87b0000000000 MOV dword ptr [0x7bd8c0], 0
    m.w32((0x007bd8c0u), 0u);
  }
  L0047062e: { // 0x47062e: c705c4d87b000000f03f MOV dword ptr [0x7bd8c4], 0x3ff00000
    m.w32((0x007bd8c4u), 0x3ff00000u);
  }
  L00470638: { // 0x470638: c705c8d87b0000000000 MOV dword ptr [0x7bd8c8], 0
    m.w32((0x007bd8c8u), 0u);
  }
  L00470642: { // 0x470642: c705ccd87b000000f03f MOV dword ptr [0x7bd8cc], 0x3ff00000
    m.w32((0x007bd8ccu), 0x3ff00000u);
  }
  L0047064c: { // 0x47064c: c705d0d87b0000000000 MOV dword ptr [0x7bd8d0], 0
    m.w32((0x007bd8d0u), 0u);
  }
  L00470656: { // 0x470656: c705d4d87b0000000000 MOV dword ptr [0x7bd8d4], 0
    m.w32((0x007bd8d4u), 0u);
  }
  L00470660: { // 0x470660: c705e0d87b0000000000 MOV dword ptr [0x7bd8e0], 0
    m.w32((0x007bd8e0u), 0u);
  }
  L0047066a: { // 0x47066a: c705e4d87b0000000000 MOV dword ptr [0x7bd8e4], 0
    m.w32((0x007bd8e4u), 0u);
  }
  L00470674: { // 0x470674: c705e8d87b0000000000 MOV dword ptr [0x7bd8e8], 0
    m.w32((0x007bd8e8u), 0u);
  }
  L0047067e: { // 0x47067e: c705ecd87b000000f0bf MOV dword ptr [0x7bd8ec], 0xbff00000
    m.w32((0x007bd8ecu), 0xbff00000u);
  }
  L00470688: { // 0x470688: c705f0d87b0000000000 MOV dword ptr [0x7bd8f0], 0
    m.w32((0x007bd8f0u), 0u);
  }
  L00470692: { // 0x470692: c705f4d87b000000f03f MOV dword ptr [0x7bd8f4], 0x3ff00000
    m.w32((0x007bd8f4u), 0x3ff00000u);
  }
  L0047069c: { // 0x47069c: c70508d97b0000000000 MOV dword ptr [0x7bd908], 0
    m.w32((0x007bd908u), 0u);
  }
  L004706a6: { // 0x4706a6: c7050cd97b0000000000 MOV dword ptr [0x7bd90c], 0
    m.w32((0x007bd90cu), 0u);
  }
  L004706b0: { // 0x4706b0: c70510d97b0000000000 MOV dword ptr [0x7bd910], 0
    m.w32((0x007bd910u), 0u);
  }
  L004706ba: { // 0x4706ba: c70514d97b000000f0bf MOV dword ptr [0x7bd914], 0xbff00000
    m.w32((0x007bd914u), 0xbff00000u);
  }
  L004706c4: { // 0x4706c4: c70518d97b0000000000 MOV dword ptr [0x7bd918], 0
    m.w32((0x007bd918u), 0u);
  }
  L004706ce: { // 0x4706ce: c7051cd97b000000f0bf MOV dword ptr [0x7bd91c], 0xbff00000
    m.w32((0x007bd91cu), 0xbff00000u);
  }
  L004706d8: { // 0x4706d8: c70530d97b0000000000 MOV dword ptr [0x7bd930], 0
    m.w32((0x007bd930u), 0u);
  }
  L004706e2: { // 0x4706e2: c70534d97b0000000000 MOV dword ptr [0x7bd934], 0
    m.w32((0x007bd934u), 0u);
  }
  L004706ec: { // 0x4706ec: c70538d97b0000000000 MOV dword ptr [0x7bd938], 0
    m.w32((0x007bd938u), 0u);
  }
  L004706f6: { // 0x4706f6: c7053cd97b000000f03f MOV dword ptr [0x7bd93c], 0x3ff00000
    m.w32((0x007bd93cu), 0x3ff00000u);
  }
  L00470700: { // 0x470700: c70540d97b0000000000 MOV dword ptr [0x7bd940], 0
    m.w32((0x007bd940u), 0u);
  }
  L0047070a: { // 0x47070a: c70544d97b000000f0bf MOV dword ptr [0x7bd944], 0xbff00000
    m.w32((0x007bd944u), 0xbff00000u);
  }
  L00470714: { // 0x470714: 890d4cd97b00 MOV dword ptr [0x7bd94c], ECX
    m.w32((0x007bd94cu), s.cx);
  }
  L0047071a: { // 0x47071a: 891550d97b00 MOV dword ptr [0x7bd950], EDX
    m.w32((0x007bd950u), s.dx);
  }
  L00470720: { // 0x470720: a354d97b00 MOV dword ptr [0x7bd954], EAX
    m.w32((0x007bd954u), s.ax);
  }
  L00470725: { // 0x470725: c70558d97b0000000000 MOV dword ptr [0x7bd958], 0
    m.w32((0x007bd958u), 0u);
  }
  L0047072f: { // 0x47072f: c7055cd97b0000000000 MOV dword ptr [0x7bd95c], 0
    m.w32((0x007bd95cu), 0u);
  }
  L00470739: { // 0x470739: c70560d97b0000000000 MOV dword ptr [0x7bd960], 0
    m.w32((0x007bd960u), 0u);
  }
  L00470743: { // 0x470743: c70564d97b000000f03f MOV dword ptr [0x7bd964], 0x3ff00000
    m.w32((0x007bd964u), 0x3ff00000u);
  }
  L0047074d: { // 0x47074d: c70568d97b0000000000 MOV dword ptr [0x7bd968], 0
    m.w32((0x007bd968u), 0u);
  }
  L00470757: { // 0x470757: c7056cd97b000000f03f MOV dword ptr [0x7bd96c], 0x3ff00000
    m.w32((0x007bd96cu), 0x3ff00000u);
  }
  L00470761: { // 0x470761: c70570d97b0000000000 MOV dword ptr [0x7bd970], 0
    m.w32((0x007bd970u), 0u);
  }
  L0047076b: { // 0x47076b: c70574d97b0000000000 MOV dword ptr [0x7bd974], 0
    m.w32((0x007bd974u), 0u);
  }
  L00470775: { // 0x470775: c70580d97b0000000000 MOV dword ptr [0x7bd980], 0
    m.w32((0x007bd980u), 0u);
  }
  L0047077f: { // 0x47077f: c70584d97b0000000000 MOV dword ptr [0x7bd984], 0
    m.w32((0x007bd984u), 0u);
  }
  L00470789: { // 0x470789: c70588d97b0000000000 MOV dword ptr [0x7bd988], 0
    m.w32((0x007bd988u), 0u);
  }
  L00470793: { // 0x470793: dd15a0d97b00 FST qword ptr [0x7bd9a0]
    const auto address=(0x007bd9a0u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470799: { // 0x470799: dd15c0d97b00 FST qword ptr [0x7bd9c0]
    const auto address=(0x007bd9c0u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047079f: { // 0x47079f: dd15c8d97b00 FST qword ptr [0x7bd9c8]
    const auto address=(0x007bd9c8u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707a5: { // 0x4707a5: dd1df0d97b00 FSTP qword ptr [0x7bd9f0]
    const auto address=(0x007bd9f0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004707ab: { // 0x4707ab: dd05f08e8300 FLD qword ptr [0x838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004707b1: { // 0x4707b1: dc0d28577800 FMUL qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L004707b7: { // 0x4707b7: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L004707b9: { // 0x4707b9: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L004707bb: { // 0x4707bb: 890d98d97b00 MOV dword ptr [0x7bd998], ECX
    m.w32((0x007bd998u), s.cx);
  }
  L004707c1: { // 0x4707c1: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L004707c3: { // 0x4707c3: 89159cd97b00 MOV dword ptr [0x7bd99c], EDX
    m.w32((0x007bd99cu), s.dx);
  }
  L004707c9: { // 0x4707c9: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L004707cb: { // 0x4707cb: dd1518da7b00 FST qword ptr [0x7bda18]
    const auto address=(0x007bda18u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707d1: { // 0x4707d1: dd1520da7b00 FST qword ptr [0x7bda20]
    const auto address=(0x007bda20u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707d7: { // 0x4707d7: dd1540da7b00 FST qword ptr [0x7bda40]
    const auto address=(0x007bda40u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707dd: { // 0x4707dd: dd05f08e8300 FLD qword ptr [0x838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004707e3: { // 0x4707e3: dc0db0797800 FMUL qword ptr [0x7879b0]
    const auto address=(0x007879b0u);
    s.fp.multiply64(read64(m,address));
  }
  L004707e9: { // 0x4707e9: a3e8d97b00 MOV dword ptr [0x7bd9e8], EAX
    m.w32((0x007bd9e8u), s.ax);
  }
  L004707ee: { // 0x4707ee: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L004707f0: { // 0x4707f0: 890decd97b00 MOV dword ptr [0x7bd9ec], ECX
    m.w32((0x007bd9ecu), s.cx);
  }
  L004707f6: { // 0x4707f6: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L004707f8: { // 0x4707f8: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L004707fa: { // 0x4707fa: 891538da7b00 MOV dword ptr [0x7bda38], EDX
    m.w32((0x007bda38u), s.dx);
  }
  L00470800: { // 0x470800: dd542408 FST qword ptr [ESP + 8]
    const auto address=(f.sp+8u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470804: { // 0x470804: dd1d48da7b00 FSTP qword ptr [0x7bda48]
    const auto address=(0x007bda48u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047080a: { // 0x47080a: a33cda7b00 MOV dword ptr [0x7bda3c], EAX
    m.w32((0x007bda3cu), s.ax);
  }
  L0047080f: { // 0x47080f: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00470811: { // 0x470811: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L00470815: { // 0x470815: 890d88da7b00 MOV dword ptr [0x7bda88], ECX
    m.w32((0x007bda88u), s.cx);
  }
  L0047081b: { // 0x47081b: 8b4c240c MOV ECX, dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0047081f: { // 0x47081f: c7058cd97b000000f0bf MOV dword ptr [0x7bd98c], 0xbff00000
    m.w32((0x007bd98cu), 0xbff00000u);
  }
  L00470829: { // 0x470829: dd1568da7b00 FST qword ptr [0x7bda68]
    const auto address=(0x007bda68u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047082f: { // 0x47082f: dd1570da7b00 FST qword ptr [0x7bda70]
    const auto address=(0x007bda70u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470835: { // 0x470835: dd1d90da7b00 FSTP qword ptr [0x7bda90]
    const auto address=(0x007bda90u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047083b: { // 0x47083b: c70590d97b0000000000 MOV dword ptr [0x7bd990], 0
    m.w32((0x007bd990u), 0u);
  }
  L00470845: { // 0x470845: c70594d97b000000f03f MOV dword ptr [0x7bd994], 0x3ff00000
    m.w32((0x007bd994u), 0x3ff00000u);
  }
  L0047084f: { // 0x47084f: c705a8d97b0000000000 MOV dword ptr [0x7bd9a8], 0
    m.w32((0x007bd9a8u), 0u);
  }
  L00470859: { // 0x470859: c705acd97b0000000000 MOV dword ptr [0x7bd9ac], 0
    m.w32((0x007bd9acu), 0u);
  }
  L00470863: { // 0x470863: c705b0d97b0000000000 MOV dword ptr [0x7bd9b0], 0
    m.w32((0x007bd9b0u), 0u);
  }
  L0047086d: { // 0x47086d: c705b4d97b000000f0bf MOV dword ptr [0x7bd9b4], 0xbff00000
    m.w32((0x007bd9b4u), 0xbff00000u);
  }
  L00470877: { // 0x470877: c705b8d97b0000000000 MOV dword ptr [0x7bd9b8], 0
    m.w32((0x007bd9b8u), 0u);
  }
  L00470881: { // 0x470881: c705bcd97b000000f0bf MOV dword ptr [0x7bd9bc], 0xbff00000
    m.w32((0x007bd9bcu), 0xbff00000u);
  }
  L0047088b: { // 0x47088b: c705d0d97b0000000000 MOV dword ptr [0x7bd9d0], 0
    m.w32((0x007bd9d0u), 0u);
  }
  L00470895: { // 0x470895: c705d4d97b0000000000 MOV dword ptr [0x7bd9d4], 0
    m.w32((0x007bd9d4u), 0u);
  }
  L0047089f: { // 0x47089f: c705d8d97b0000000000 MOV dword ptr [0x7bd9d8], 0
    m.w32((0x007bd9d8u), 0u);
  }
  L004708a9: { // 0x4708a9: c705dcd97b000000f03f MOV dword ptr [0x7bd9dc], 0x3ff00000
    m.w32((0x007bd9dcu), 0x3ff00000u);
  }
  L004708b3: { // 0x4708b3: c705e0d97b0000000000 MOV dword ptr [0x7bd9e0], 0
    m.w32((0x007bd9e0u), 0u);
  }
  L004708bd: { // 0x4708bd: c705e4d97b000000f0bf MOV dword ptr [0x7bd9e4], 0xbff00000
    m.w32((0x007bd9e4u), 0xbff00000u);
  }
  L004708c7: { // 0x4708c7: c705f8d97b0000000000 MOV dword ptr [0x7bd9f8], 0
    m.w32((0x007bd9f8u), 0u);
  }
  L004708d1: { // 0x4708d1: c705fcd97b0000000000 MOV dword ptr [0x7bd9fc], 0
    m.w32((0x007bd9fcu), 0u);
  }
  L004708db: { // 0x4708db: c70500da7b0000000000 MOV dword ptr [0x7bda00], 0
    m.w32((0x007bda00u), 0u);
  }
  L004708e5: { // 0x4708e5: c70504da7b0000000000 MOV dword ptr [0x7bda04], 0
    m.w32((0x007bda04u), 0u);
  }
  L004708ef: { // 0x4708ef: c70508da7b0000000000 MOV dword ptr [0x7bda08], 0
    m.w32((0x007bda08u), 0u);
  }
  L004708f9: { // 0x4708f9: c7050cda7b0000000000 MOV dword ptr [0x7bda0c], 0
    m.w32((0x007bda0cu), 0u);
  }
  L00470903: { // 0x470903: c70510da7b0000000000 MOV dword ptr [0x7bda10], 0
    m.w32((0x007bda10u), 0u);
  }
  L0047090d: { // 0x47090d: c70514da7b0000000000 MOV dword ptr [0x7bda14], 0
    m.w32((0x007bda14u), 0u);
  }
  L00470917: { // 0x470917: c70528da7b0000000000 MOV dword ptr [0x7bda28], 0
    m.w32((0x007bda28u), 0u);
  }
  L00470921: { // 0x470921: c7052cda7b0000000000 MOV dword ptr [0x7bda2c], 0
    m.w32((0x007bda2cu), 0u);
  }
  L0047092b: { // 0x47092b: c70530da7b0000000000 MOV dword ptr [0x7bda30], 0
    m.w32((0x007bda30u), 0u);
  }
  L00470935: { // 0x470935: c70534da7b0000000000 MOV dword ptr [0x7bda34], 0
    m.w32((0x007bda34u), 0u);
  }
  L0047093f: { // 0x47093f: c70550da7b0000000000 MOV dword ptr [0x7bda50], 0
    m.w32((0x007bda50u), 0u);
  }
  L00470949: { // 0x470949: c70554da7b0000000000 MOV dword ptr [0x7bda54], 0
    m.w32((0x007bda54u), 0u);
  }
  L00470953: { // 0x470953: c70558da7b0000000000 MOV dword ptr [0x7bda58], 0
    m.w32((0x007bda58u), 0u);
  }
  L0047095d: { // 0x47095d: c7055cda7b0000000000 MOV dword ptr [0x7bda5c], 0
    m.w32((0x007bda5cu), 0u);
  }
  L00470967: { // 0x470967: c70560da7b0000000000 MOV dword ptr [0x7bda60], 0
    m.w32((0x007bda60u), 0u);
  }
  L00470971: { // 0x470971: c70564da7b0000000000 MOV dword ptr [0x7bda64], 0
    m.w32((0x007bda64u), 0u);
  }
  L0047097b: { // 0x47097b: c70578da7b0000000000 MOV dword ptr [0x7bda78], 0
    m.w32((0x007bda78u), 0u);
  }
  L00470985: { // 0x470985: c7057cda7b0000000000 MOV dword ptr [0x7bda7c], 0
    m.w32((0x007bda7cu), 0u);
  }
  L0047098f: { // 0x47098f: c70580da7b0000000000 MOV dword ptr [0x7bda80], 0
    m.w32((0x007bda80u), 0u);
  }
  L00470999: { // 0x470999: c70584da7b0000000000 MOV dword ptr [0x7bda84], 0
    m.w32((0x007bda84u), 0u);
  }
  L004709a3: { // 0x4709a3: 89158cda7b00 MOV dword ptr [0x7bda8c], EDX
    m.w32((0x007bda8cu), s.dx);
  }
  L004709a9: { // 0x4709a9: a398da7b00 MOV dword ptr [0x7bda98], EAX
    m.w32((0x007bda98u), s.ax);
  }
  L004709ae: { // 0x4709ae: 890d9cda7b00 MOV dword ptr [0x7bda9c], ECX
    m.w32((0x007bda9cu), s.cx);
  }
  L004709b4: { // 0x4709b4: 0fbe961b010000 MOVSX EDX, byte ptr [ESI + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L004709bb: { // 0x4709bb: 0faf15808f8300 IMUL EDX, dword ptr [0x838f80]
    s.dx = integer::imul(s.dx,m.r32((0x00838f80u)),32,flags);
  }
  L004709c2: { // 0x4709c2: 89542404 MOV dword ptr [ESP + 4], EDX
    m.w32((f.sp+4u), s.dx);
  }
  L004709c6: { // 0x4709c6: db442404 FILD dword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.load_integer32(m.r32(address));
  }
  L004709ca: { // 0x4709ca: dc0528577800 FADD qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L004709d0: { // 0x4709d0: e87ba02f00 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4655573u); flags=s.arithmetic_flags;
  }
  L004709d5: { // 0x4709d5: 8a8e1c010000 MOV CL, byte ptr [ESI + 0x11c]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000011cu)));
  }
  L004709db: { // 0x4709db: 89442408 MOV dword ptr [ESP + 8], EAX
    m.w32((f.sp+8u), s.ax);
  }
  L004709df: { // 0x4709df: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004709e1: { // 0x4709e1: 0f868d000000 JBE 0x470a74
    if(integer::condition("JBE",flags)) goto L00470a74;
  }
  L004709e7: { // 0x4709e7: 8b4508 MOV EAX, dword ptr [EBP + 8]
    s.ax = m.r32((s.bp+8u));
  }
  L004709ea: { // 0x4709ea: 81e1ff000000 AND ECX, 0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L004709f0: { // 0x4709f0: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004709f1: { // 0x4709f1: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L004709f4: { // 0x4709f4: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L004709f6: { // 0x4709f6: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004709fc: { // 0x4709fc: 8d0c89 LEA ECX, [ECX + ECX*4]
    s.cx = (s.cx+(s.cx * 4u));
  }
  L004709ff: { // 0x4709ff: 89542404 MOV dword ptr [ESP + 4], EDX
    m.w32((f.sp+4u), s.dx);
  }
  L00470a03: { // 0x470a03: 25ff000000 AND EAX, 0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L00470a08: { // 0x470a08: db442404 FILD dword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a0c: { // 0x470a0c: c1e103 SHL ECX, 3
    s.cx = integer::shift(s.cx,3u,32,flags,integer::Shift::left);
  }
  L00470a0f: { // 0x470a0f: 89442404 MOV dword ptr [ESP + 4], EAX
    m.w32((f.sp+4u), s.ax);
  }
  L00470a13: { // 0x470a13: dc8988d77b00 FMUL qword ptr [ECX + 0x7bd788]
    const auto address=(s.cx+0x007bd788u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a19: { // 0x470a19: dc0d108f8300 FMUL qword ptr [0x838f10]
    const auto address=(0x00838f10u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a1f: { // 0x470a1f: db442404 FILD dword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a23: { // 0x470a23: dc8980d77b00 FMUL qword ptr [ECX + 0x7bd780]
    const auto address=(s.cx+0x007bd780u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a29: { // 0x470a29: dc0d108f8300 FMUL qword ptr [0x838f10]
    const auto address=(0x00838f10u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a2f: { // 0x470a2f: dec1 FADDP st(1)
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00470a31: { // 0x470a31: dc8190d77b00 FADD qword ptr [ECX + 0x7bd790]
    const auto address=(s.cx+0x007bd790u);
    s.fp.add64(read64(m,address));
  }
  L00470a37: { // 0x470a37: dc81a0d77b00 FADD qword ptr [ECX + 0x7bd7a0]
    const auto address=(s.cx+0x007bd7a0u);
    s.fp.add64(read64(m,address));
  }
  L00470a3d: { // 0x470a3d: dc1510667800 FCOM qword ptr [0x786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00470a43: { // 0x470a43: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00470a45: { // 0x470a45: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00470a48: { // 0x470a48: 7408 JZ 0x470a52
    if(integer::condition("JZ",flags)) goto L00470a52;
  }
  L00470a4a: { // 0x470a4a: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a4c: { // 0x470a4c: dd0510667800 FLD qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.load64(read64(m,address));
  }
  L00470a52: { // 0x470a52: dc9198d77b00 FCOM qword ptr [ECX + 0x7bd798]
    const auto address=(s.cx+0x007bd798u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00470a58: { // 0x470a58: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00470a5a: { // 0x470a5a: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00470a5d: { // 0x470a5d: 7508 JNZ 0x470a67
    if(integer::condition("JNZ",flags)) goto L00470a67;
  }
  L00470a5f: { // 0x470a5f: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a61: { // 0x470a61: dd8198d77b00 FLD qword ptr [ECX + 0x7bd798]
    const auto address=(s.cx+0x007bd798u);
    s.fp.load64(read64(m,address));
  }
  L00470a67: { // 0x470a67: db442408 FILD dword ptr [ESP + 8]
    const auto address=(f.sp+8u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a6b: { // 0x470a6b: d8c1 FADD st(1)
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
  L00470a6d: { // 0x470a6d: e8de9f2f00 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4655730u); flags=s.arithmetic_flags;
  }
  L00470a72: { // 0x470a72: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a74: { // 0x470a74: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00470a75: { // 0x470a75: 8be5 MOV ESP, EBP
    f.sp = s.bp;
  }
  L00470a77: { // 0x470a77: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00470a78: { // 0x470a78: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076aa50: { // 0x76aa50: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0076aa53: { // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  L0076aa56: { // 0x76aa56: 8d442404 LEA EAX, [ESP + 4]
    s.ax = (f.sp+4u);
  }
  L0076aa5a: { // 0x76aa5a: 8b1424 MOV EDX, dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0076aa5d: { // 0x76aa5d: 81e2ffff0000 AND EDX, 0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076aa63: { // 0x76aa63: 3b15043a7c00 CMP EDX, dword ptr [0x7c3a04]
    (void)integer::sub(s.dx,m.r32((0x007c3a04u)),32,flags);
  }
  L0076aa69: { // 0x76aa69: 750b JNZ 0x76aa76
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
  L0076aa6b: { // 0x76aa6b: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa6d: { // 0x76aa6d: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0076aa70: { // 0x76aa70: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa72: { // 0x76aa72: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa75: { // 0x76aa75: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { // 0x76aa76: 8b15043a7c00 MOV EDX, dword ptr [0x7c3a04]
    s.dx = m.r32((0x007c3a04u));
  }
  L0076aa7c: { // 0x76aa7c: 891424 MOV dword ptr [ESP], EDX
    m.w32((f.sp), s.dx);
  }
  L0076aa7f: { // 0x76aa7f: d92c24 FLDCW word ptr [ESP]
    const auto address=(f.sp);
    s.fp.load_control(m.r16(address));
  }
  L0076aa82: { // 0x76aa82: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa84: { // 0x76aa84: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0076aa87: { // 0x76aa87: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa89: { // 0x76aa89: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa8c: { // 0x76aa8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4300928u:f_0001a080(m,s,child,{});break;
case 7162736u:f_002d4b70(m,s,child,{});break;
case 6082208u:f_001ccea0(m,s,child,{});break;
case 5599344u:f_00157070(m,s,child,{});break;
case 4653760u:f_000702c0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery1551 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ throw std::domain_error("B1551 unreviewed tail"); } }

std::uint32_t fun_0041a080(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041a080: { // 0x41a080: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041a081: { // 0x41a081: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L0041a083: { // 0x41a083: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0041a084: { // 0x41a084: 8b8eac050000 MOV ECX, dword ptr [ESI + 0x5ac]
    s.cx = m.r32((s.si+0x000005acu));
  }
  L0041a08a: { // 0x41a08a: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0041a08c: { // 0x41a08c: ff90bc000000 CALL dword ptr [EAX + 0xbc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000bcu)),4300946u); flags=s.arithmetic_flags;
  }
  L0041a092: { // 0x41a092: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0041a094: { // 0x41a094: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0041a096: { // 0x41a096: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0041a098: { // 0x41a098: ff92b0010000 CALL dword ptr [EDX + 0x1b0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001b0u)),4300958u); flags=s.arithmetic_flags;
  }
  L0041a09e: { // 0x41a09e: 3bc7 CMP EAX, EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0041a0a0: { // 0x41a0a0: 7520 JNZ 0x41a0c2
    if(integer::condition("JNZ",flags)) goto L0041a0c2;
  }
  L0041a0a2: { // 0x41a0a2: 8b86c4040000 MOV EAX, dword ptr [ESI + 0x4c4]
    s.ax = m.r32((s.si+0x000004c4u));
  }
  L0041a0a8: { // 0x41a0a8: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041a0aa: { // 0x41a0aa: 750e JNZ 0x41a0ba
    if(integer::condition("JNZ",flags)) goto L0041a0ba;
  }
  L0041a0ac: { // 0x41a0ac: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0041a0ae: { // 0x41a0ae: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0041a0b0: { // 0x41a0b0: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0041a0b2: { // 0x41a0b2: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0041a0b4: { // 0x41a0b4: ff9014040000 CALL dword ptr [EAX + 0x414]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000414u)),4300986u); flags=s.arithmetic_flags;
  }
  L0041a0ba: { // 0x41a0ba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041a0bb: { // 0x41a0bb: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L0041a0c0: { // 0x41a0c0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041a0c1: { // 0x41a0c1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0041a0c2: { // 0x41a0c2: 8b8654020000 MOV EAX, dword ptr [ESI + 0x254]
    s.ax = m.r32((s.si+0x00000254u));
  }
  L0041a0c8: { // 0x41a0c8: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041a0ca: { // 0x41a0ca: 7527 JNZ 0x41a0f3
    if(integer::condition("JNZ",flags)) goto L0041a0f3;
  }
  L0041a0cc: { // 0x41a0cc: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0041a0ce: { // 0x41a0ce: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0041a0d0: { // 0x41a0d0: ff928c020000 CALL dword ptr [EDX + 0x28c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000028cu)),4301014u); flags=s.arithmetic_flags;
  }
  L0041a0d6: { // 0x41a0d6: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041a0d8: { // 0x41a0d8: 7419 JZ 0x41a0f3
    if(integer::condition("JZ",flags)) goto L0041a0f3;
  }
  L0041a0da: { // 0x41a0da: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0041a0dc: { // 0x41a0dc: e8cf432100 CALL 0x62e4b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062e4b0u,4301025u); flags=s.arithmetic_flags;
  }
  L0041a0e1: { // 0x41a0e1: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041a0e3: { // 0x41a0e3: 750e JNZ 0x41a0f3
    if(integer::condition("JNZ",flags)) goto L0041a0f3;
  }
  L0041a0e5: { // 0x41a0e5: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0041a0e7: { // 0x41a0e7: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0041a0e9: { // 0x41a0e9: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0041a0eb: { // 0x41a0eb: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0041a0ed: { // 0x41a0ed: ff9014040000 CALL dword ptr [EAX + 0x414]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000414u)),4301043u); flags=s.arithmetic_flags;
  }
  L0041a0f3: { // 0x41a0f3: 8b8628020000 MOV EAX, dword ptr [ESI + 0x228]
    s.ax = m.r32((s.si+0x00000228u));
  }
  L0041a0f9: { // 0x41a0f9: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041a0fb: { // 0x41a0fb: 7416 JZ 0x41a113
    if(integer::condition("JZ",flags)) goto L0041a113;
  }
  L0041a0fd: { // 0x41a0fd: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0041a0ff: { // 0x41a0ff: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0041a101: { // 0x41a101: 6a01 PUSH 1
    f.push(m,1u);
  }
  L0041a103: { // 0x41a103: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0041a105: { // 0x41a105: ff92d0010000 CALL dword ptr [EDX + 0x1d0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001d0u)),4301067u); flags=s.arithmetic_flags;
  }
  L0041a10b: { // 0x41a10b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041a10c: { // 0x41a10c: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L0041a111: { // 0x41a111: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041a112: { // 0x41a112: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0041a113: { // 0x41a113: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0041a115: { // 0x41a115: e846b40a00 CALL 0x4c5560
    s.arithmetic_flags=flags; invoke(m,s,f,0x004c5560u,4301082u); flags=s.arithmetic_flags;
  }
  L0041a11a: { // 0x41a11a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041a11b: { // 0x41a11b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041a11c: { // 0x41a11c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
