#include "recovered/recovery_b768_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b768 {
namespace {
void f_00093d10(Memory&,State&,Frame&,const Operations&);
void f_00093d50(Memory&,State&,Frame&,const Operations&);
void f_00093d70(Memory&,State&,Frame&,const Operations&);
void f_00093c60(Memory&,State&,Frame&,const Operations&);
void f_00093da0(Memory&,State&,Frame&,const Operations&);
void f_00093f70(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00093d10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00493d10: { // 0x493d10: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L00493d14: { // 0x493d14: 8d542404 LEA EDX, [ESP + 4]
    s.dx = (f.sp+4u);
  }
  L00493d18: { // 0x493d18: 6a04 PUSH 4
    f.push(m,4u);
  }
  L00493d1a: { // 0x493d1a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00493d1b: { // 0x493d1b: 8944240c MOV dword ptr [ESP + 0xc], EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L00493d1f: { // 0x493d1f: e87c000000 CALL 0x493da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493da0u,4799780u); flags=s.arithmetic_flags;
  }
  L00493d24: { // 0x493d24: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00093d50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00493d50: { // 0x493d50: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L00493d54: { // 0x493d54: 8b542408 MOV EDX, dword ptr [ESP + 8]
    s.dx = m.r32((f.sp+8u));
  }
  L00493d58: { // 0x493d58: 89442404 MOV dword ptr [ESP + 4], EAX
    m.w32((f.sp+4u), s.ax);
  }
  L00493d5c: { // 0x493d5c: 8d442404 LEA EAX, [ESP + 4]
    s.ax = (f.sp+4u);
  }
  L00493d60: { // 0x493d60: 6a08 PUSH 8
    f.push(m,8u);
  }
  L00493d62: { // 0x493d62: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00493d63: { // 0x493d63: 89542410 MOV dword ptr [ESP + 0x10], EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00493d67: { // 0x493d67: e834000000 CALL 0x493da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493da0u,4799852u); flags=s.arithmetic_flags;
  }
  L00493d6c: { // 0x493d6c: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00093d70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00493d70: { // 0x493d70: 8b542404 MOV EDX, dword ptr [ESP + 4]
    s.dx = m.r32((f.sp+4u));
  }
  L00493d74: { // 0x493d74: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00493d75: { // 0x493d75: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00493d77: { // 0x493d77: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00493d79: { // 0x493d79: 7417 JZ 0x493d92
    if(integer::condition("JZ",flags)) goto L00493d92;
  }
  L00493d7b: { // 0x493d7b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00493d7c: { // 0x493d7c: 8bfa MOV EDI, EDX
    s.di = s.dx;
  }
  L00493d7e: { // 0x493d7e: 83c9ff OR ECX, 0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L00493d81: { // 0x493d81: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00493d83: { // 0x493d83: f2ae REPNE SCASB AL, byte ptr es:[EDI]
    while(s.cx){const auto byte=m.r8(s.di);++s.di;--s.cx;(void)integer::sub(s.ax&255u,byte,8,flags);if(flags&integer::ZF)break;}
  }
  L00493d85: { // 0x493d85: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  L00493d87: { // 0x493d87: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00493d88: { // 0x493d88: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00493d89: { // 0x493d89: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00493d8a: { // 0x493d8a: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00493d8c: { // 0x493d8c: e80f000000 CALL 0x493da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493da0u,4799889u); flags=s.arithmetic_flags;
  }
  L00493d91: { // 0x493d91: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00493d92: { // 0x493d92: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00493d93: { // 0x493d93: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00093c60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00493c60: { // 0x493c60: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L00493c63: { // 0x493c63: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00493c65: { // 0x493c65: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00493c67: { // 0x493c67: 7503 JNZ 0x493c6c
    if(integer::condition("JNZ",flags)) goto L00493c6c;
  }
  L00493c69: { // 0x493c69: 895108 MOV dword ptr [ECX + 8], EDX
    m.w32((s.cx+8u), s.dx);
  }
  L00493c6c: { // 0x493c6c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00493c6d: { // 0x493c6d: 8a5c2408 MOV BL, byte ptr [ESP + 8]
    s.bx = with_al(s.bx, m.r8((f.sp+8u)));
  }
  L00493c71: { // 0x493c71: 3ada CMP BL, DL
    (void)integer::sub((s.bx & 0xffu),(s.dx & 0xffu),8,flags);
  }
  L00493c73: { // 0x493c73: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00493c74: { // 0x493c74: 0f95c3 SETNE BL
    s.bx = with_al(s.bx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L00493c77: { // 0x493c77: 885c0808 MOV byte ptr [EAX + ECX + 8], BL
    m.w8((s.ax+s.cx+8u), (s.bx & 0xffu));
  }
  L00493c7b: { // 0x493c7b: 8b7904 MOV EDI, dword ptr [ECX + 4]
    s.di = m.r32((s.cx+4u));
  }
  L00493c7e: { // 0x493c7e: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00493c7f: { // 0x493c7f: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L00493c81: { // 0x493c81: 897904 MOV dword ptr [ECX + 4], EDI
    m.w32((s.cx+4u), s.di);
  }
  L00493c84: { // 0x493c84: 83f804 CMP EAX, 4
    (void)integer::sub(s.ax,4u,32,flags);
  }
  L00493c87: { // 0x493c87: 7558 JNZ 0x493ce1
    if(integer::condition("JNZ",flags)) goto L00493ce1;
  }
  L00493c89: { // 0x493c89: 8a4104 MOV AL, byte ptr [ECX + 4]
    s.ax = with_al(s.ax, m.r8((s.cx+4u)));
  }
  L00493c8c: { // 0x493c8c: 88410c MOV byte ptr [ECX + 0xc], AL
    m.w8((s.cx+0x0000000cu), (s.ax & 0xffu));
  }
  L00493c8f: { // 0x493c8f: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L00493c92: { // 0x493c92: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493c93: { // 0x493c93: 3bc7 CMP EAX, EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00493c95: { // 0x493c95: 730d JAE 0x493ca4
    if(integer::condition("JNC",flags)) goto L00493ca4;
  }
  L00493c97: { // 0x493c97: 8a5908 MOV BL, byte ptr [ECX + 8]
    s.bx = with_al(s.bx, m.r8((s.cx+8u)));
  }
  L00493c9a: { // 0x493c9a: 885c0108 MOV byte ptr [ECX + EAX + 8], BL
    m.w8((s.cx+s.ax+8u), (s.bx & 0xffu));
  }
  L00493c9e: { // 0x493c9e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493c9f: { // 0x493c9f: 83f804 CMP EAX, 4
    (void)integer::sub(s.ax,4u,32,flags);
  }
  L00493ca2: { // 0x493ca2: 72f3 JB 0x493c97
    if(integer::condition("JC",flags)) goto L00493c97;
  }
  L00493ca4: { // 0x493ca4: 8b4108 MOV EAX, dword ptr [ECX + 8]
    s.ax = m.r32((s.cx+8u));
  }
  L00493ca7: { // 0x493ca7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00493ca8: { // 0x493ca8: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00493cac: { // 0x493cac: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00493cae: { // 0x493cae: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00493caf: { // 0x493caf: 8d742414 LEA ESI, [ESP + 0x14]
    s.si = (f.sp+0x00000014u);
  }
  L00493cb3: { // 0x493cb3: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493cb5: { // 0x493cb5: bf04000000 MOV EDI, 4
    s.di = 4u;
  }
  L00493cba: { // 0x493cba: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L00493cbc: { // 0x493cbc: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493cbe: { // 0x493cbe: 8a1e MOV BL, byte ptr [ESI]
    s.bx = with_al(s.bx, m.r8((s.si)));
  }
  L00493cc0: { // 0x493cc0: 81e5ff000000 AND EBP, 0xff
    s.bp = integer::logical((s.bp)&(0x000000ffu),32,flags);
  }
  L00493cc6: { // 0x493cc6: 33eb XOR EBP, EBX
    s.bp = integer::logical((s.bp)^(s.bx),32,flags);
  }
  L00493cc8: { // 0x493cc8: c1e808 SHR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::right);
  }
  L00493ccb: { // 0x493ccb: 8b1cad34067c00 MOV EBX, dword ptr [EBP*4 + 0x7c0634]
    s.bx = m.r32(((s.bp * 4u)+0x007c0634u));
  }
  L00493cd2: { // 0x493cd2: 33c3 XOR EAX, EBX
    s.ax = integer::logical((s.ax)^(s.bx),32,flags);
  }
  L00493cd4: { // 0x493cd4: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00493cd5: { // 0x493cd5: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00493cd6: { // 0x493cd6: 75e2 JNZ 0x493cba
    if(integer::condition("JNZ",flags)) goto L00493cba;
  }
  L00493cd8: { // 0x493cd8: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493cda: { // 0x493cda: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00493cdb: { // 0x493cdb: 8901 MOV dword ptr [ECX], EAX
    m.w32((s.cx), s.ax);
  }
  L00493cdd: { // 0x493cdd: 895104 MOV dword ptr [ECX + 4], EDX
    m.w32((s.cx+4u), s.dx);
  }
  L00493ce0: { // 0x493ce0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00493ce1: { // 0x493ce1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00493ce2: { // 0x493ce2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00493ce3: { // 0x493ce3: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00093da0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00493da0: { // 0x493da0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00493da1: { // 0x493da1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00493da2: { // 0x493da2: 8b6c240c MOV EBP, dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  L00493da6: { // 0x493da6: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493da8: { // 0x493da8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00493da9: { // 0x493da9: 3beb CMP EBP, EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L00493dab: { // 0x493dab: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00493dac: { // 0x493dac: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00493dae: { // 0x493dae: 0f844c010000 JZ 0x493f00
    if(integer::condition("JZ",flags)) goto L00493f00;
  }
  L00493db4: { // 0x493db4: 8b7c2418 MOV EDI, dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L00493db8: { // 0x493db8: 3bfb CMP EDI, EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L00493dba: { // 0x493dba: 0f8e40010000 JLE 0x493f00
    if(integer::condition("JLE",flags)) goto L00493f00;
  }
  L00493dc0: { // 0x493dc0: 8b4604 MOV EAX, dword ptr [ESI + 4]
    s.ax = m.r32((s.si+4u));
  }
  L00493dc3: { // 0x493dc3: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00493dc5: { // 0x493dc5: 7454 JZ 0x493e1b
    if(integer::condition("JZ",flags)) goto L00493e1b;
  }
  L00493dc7: { // 0x493dc7: ba04000000 MOV EDX, 4
    s.dx = 4u;
  }
  L00493dcc: { // 0x493dcc: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00493dce: { // 0x493dce: 734b JAE 0x493e1b
    if(integer::condition("JNC",flags)) goto L00493e1b;
  }
  L00493dd0: { // 0x493dd0: 8a4d00 MOV CL, byte ptr [EBP]
    s.cx = with_al(s.cx, m.r8((s.bp)));
  }
  L00493dd3: { // 0x493dd3: 884c3008 MOV byte ptr [EAX + ESI + 8], CL
    m.w8((s.ax+s.si+8u), (s.cx & 0xffu));
  }
  L00493dd7: { // 0x493dd7: 8b4e04 MOV ECX, dword ptr [ESI + 4]
    s.cx = m.r32((s.si+4u));
  }
  L00493dda: { // 0x493dda: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00493ddb: { // 0x493ddb: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00493ddd: { // 0x493ddd: 894e04 MOV dword ptr [ESI + 4], ECX
    m.w32((s.si+4u), s.cx);
  }
  L00493de0: { // 0x493de0: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00493de2: { // 0x493de2: 7531 JNZ 0x493e15
    if(integer::condition("JNZ",flags)) goto L00493e15;
  }
  L00493de4: { // 0x493de4: 8ac1 MOV AL, CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L00493de6: { // 0x493de6: 88460c MOV byte ptr [ESI + 0xc], AL
    m.w8((s.si+0x0000000cu), (s.ax & 0xffu));
  }
  L00493de9: { // 0x493de9: 8b4604 MOV EAX, dword ptr [ESI + 4]
    s.ax = m.r32((s.si+4u));
  }
  L00493dec: { // 0x493dec: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493ded: { // 0x493ded: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00493def: { // 0x493def: 730c JAE 0x493dfd
    if(integer::condition("JNC",flags)) goto L00493dfd;
  }
  L00493df1: { // 0x493df1: 8a4e08 MOV CL, byte ptr [ESI + 8]
    s.cx = with_al(s.cx, m.r8((s.si+8u)));
  }
  L00493df4: { // 0x493df4: 884c0608 MOV byte ptr [ESI + EAX + 8], CL
    m.w8((s.si+s.ax+8u), (s.cx & 0xffu));
  }
  L00493df8: { // 0x493df8: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493df9: { // 0x493df9: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00493dfb: { // 0x493dfb: 72f4 JB 0x493df1
    if(integer::condition("JC",flags)) goto L00493df1;
  }
  L00493dfd: { // 0x493dfd: 8b0e MOV ECX, dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00493dff: { // 0x493dff: 8b4608 MOV EAX, dword ptr [ESI + 8]
    s.ax = m.r32((s.si+8u));
  }
  L00493e02: { // 0x493e02: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00493e03: { // 0x493e03: 8d4c2418 LEA ECX, [ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00493e07: { // 0x493e07: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00493e0b: { // 0x493e0b: e860010000 CALL 0x493f70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493f70u,4800016u); flags=s.arithmetic_flags;
  }
  L00493e10: { // 0x493e10: 8906 MOV dword ptr [ESI], EAX
    m.w32((s.si), s.ax);
  }
  L00493e12: { // 0x493e12: 895e04 MOV dword ptr [ESI + 4], EBX
    m.w32((s.si+4u), s.bx);
  }
  L00493e15: { // 0x493e15: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00493e16: { // 0x493e16: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00493e17: { // 0x493e17: 3bfb CMP EDI, EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L00493e19: { // 0x493e19: 7fa5 JG 0x493dc0
    if(integer::condition("JG",flags)) goto L00493dc0;
  }
  L00493e1b: { // 0x493e1b: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L00493e1d: { // 0x493e1d: c1e802 SHR EAX, 2
    s.ax = integer::shift(s.ax,2u,32,flags,integer::Shift::right);
  }
  L00493e20: { // 0x493e20: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00493e22: { // 0x493e22: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00493e23: { // 0x493e23: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00493e25: { // 0x493e25: 744f JZ 0x493e76
    if(integer::condition("JZ",flags)) goto L00493e76;
  }
  L00493e27: { // 0x493e27: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493e28: { // 0x493e28: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00493e2c: { // 0x493e2c: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00493e2e: { // 0x493e2e: 8d0487 LEA EAX, [EDI + EAX*4]
    s.ax = (s.di+(s.ax * 4u));
  }
  L00493e31: { // 0x493e31: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00493e35: { // 0x493e35: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00493e37: { // 0x493e37: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L00493e39: { // 0x493e39: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493e3b: { // 0x493e3b: bf04000000 MOV EDI, 4
    s.di = 4u;
  }
  L00493e40: { // 0x493e40: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00493e42: { // 0x493e42: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493e44: { // 0x493e44: 8a19 MOV BL, byte ptr [ECX]
    s.bx = with_al(s.bx, m.r8((s.cx)));
  }
  L00493e46: { // 0x493e46: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00493e4c: { // 0x493e4c: 33d3 XOR EDX, EBX
    s.dx = integer::logical((s.dx)^(s.bx),32,flags);
  }
  L00493e4e: { // 0x493e4e: c1e808 SHR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::right);
  }
  L00493e51: { // 0x493e51: 8b149534067c00 MOV EDX, dword ptr [EDX*4 + 0x7c0634]
    s.dx = m.r32(((s.dx * 4u)+0x007c0634u));
  }
  L00493e58: { // 0x493e58: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00493e5a: { // 0x493e5a: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00493e5b: { // 0x493e5b: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00493e5c: { // 0x493e5c: 75e2 JNZ 0x493e40
    if(integer::condition("JNZ",flags)) goto L00493e40;
  }
  L00493e5e: { // 0x493e5e: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493e60: { // 0x493e60: 8906 MOV dword ptr [ESI], EAX
    m.w32((s.si), s.ax);
  }
  L00493e62: { // 0x493e62: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00493e66: { // 0x493e66: 83c504 ADD EBP, 4
    s.bp = integer::add(s.bp,4u,32,flags);
  }
  L00493e69: { // 0x493e69: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00493e6a: { // 0x493e6a: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00493e6e: { // 0x493e6e: 75c5 JNZ 0x493e35
    if(integer::condition("JNZ",flags)) goto L00493e35;
  }
  L00493e70: { // 0x493e70: 8b7c2418 MOV EDI, dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L00493e74: { // 0x493e74: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493e76: { // 0x493e76: 3bfb CMP EDI, EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L00493e78: { // 0x493e78: 0f8e82000000 JLE 0x493f00
    if(integer::condition("JLE",flags)) goto L00493f00;
  }
  L00493e7e: { // 0x493e7e: 897c2414 MOV dword ptr [ESP + 0x14], EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L00493e82: { // 0x493e82: 8b4604 MOV EAX, dword ptr [ESI + 4]
    s.ax = m.r32((s.si+4u));
  }
  L00493e85: { // 0x493e85: 8a4d00 MOV CL, byte ptr [EBP]
    s.cx = with_al(s.cx, m.r8((s.bp)));
  }
  L00493e88: { // 0x493e88: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00493e8a: { // 0x493e8a: 7503 JNZ 0x493e8f
    if(integer::condition("JNZ",flags)) goto L00493e8f;
  }
  L00493e8c: { // 0x493e8c: 895e08 MOV dword ptr [ESI + 8], EBX
    m.w32((s.si+8u), s.bx);
  }
  L00493e8f: { // 0x493e8f: 884c3008 MOV byte ptr [EAX + ESI + 8], CL
    m.w8((s.ax+s.si+8u), (s.cx & 0xffu));
  }
  L00493e93: { // 0x493e93: 8b4e04 MOV ECX, dword ptr [ESI + 4]
    s.cx = m.r32((s.si+4u));
  }
  L00493e96: { // 0x493e96: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00493e97: { // 0x493e97: bf04000000 MOV EDI, 4
    s.di = 4u;
  }
  L00493e9c: { // 0x493e9c: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00493e9e: { // 0x493e9e: 894e04 MOV dword ptr [ESI + 4], ECX
    m.w32((s.si+4u), s.cx);
  }
  L00493ea1: { // 0x493ea1: 3bc7 CMP EAX, EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00493ea3: { // 0x493ea3: 754f JNZ 0x493ef4
    if(integer::condition("JNZ",flags)) goto L00493ef4;
  }
  L00493ea5: { // 0x493ea5: 8ac1 MOV AL, CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L00493ea7: { // 0x493ea7: 88460c MOV byte ptr [ESI + 0xc], AL
    m.w8((s.si+0x0000000cu), (s.ax & 0xffu));
  }
  L00493eaa: { // 0x493eaa: 8b4604 MOV EAX, dword ptr [ESI + 4]
    s.ax = m.r32((s.si+4u));
  }
  L00493ead: { // 0x493ead: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493eae: { // 0x493eae: 3bc7 CMP EAX, EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00493eb0: { // 0x493eb0: 730c JAE 0x493ebe
    if(integer::condition("JNC",flags)) goto L00493ebe;
  }
  L00493eb2: { // 0x493eb2: 8a4e08 MOV CL, byte ptr [ESI + 8]
    s.cx = with_al(s.cx, m.r8((s.si+8u)));
  }
  L00493eb5: { // 0x493eb5: 884c0608 MOV byte ptr [ESI + EAX + 8], CL
    m.w8((s.si+s.ax+8u), (s.cx & 0xffu));
  }
  L00493eb9: { // 0x493eb9: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493eba: { // 0x493eba: 3bc7 CMP EAX, EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00493ebc: { // 0x493ebc: 72f4 JB 0x493eb2
    if(integer::condition("JC",flags)) goto L00493eb2;
  }
  L00493ebe: { // 0x493ebe: 8b5608 MOV EDX, dword ptr [ESI + 8]
    s.dx = m.r32((s.si+8u));
  }
  L00493ec1: { // 0x493ec1: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00493ec3: { // 0x493ec3: 89542418 MOV dword ptr [ESP + 0x18], EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00493ec7: { // 0x493ec7: 8d4c2418 LEA ECX, [ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00493ecb: { // 0x493ecb: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493ecd: { // 0x493ecd: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00493ecf: { // 0x493ecf: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493ed1: { // 0x493ed1: 8a19 MOV BL, byte ptr [ECX]
    s.bx = with_al(s.bx, m.r8((s.cx)));
  }
  L00493ed3: { // 0x493ed3: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00493ed9: { // 0x493ed9: 33d3 XOR EDX, EBX
    s.dx = integer::logical((s.dx)^(s.bx),32,flags);
  }
  L00493edb: { // 0x493edb: c1e808 SHR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::right);
  }
  L00493ede: { // 0x493ede: 8b149534067c00 MOV EDX, dword ptr [EDX*4 + 0x7c0634]
    s.dx = m.r32(((s.dx * 4u)+0x007c0634u));
  }
  L00493ee5: { // 0x493ee5: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00493ee7: { // 0x493ee7: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00493ee8: { // 0x493ee8: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00493ee9: { // 0x493ee9: 75e2 JNZ 0x493ecd
    if(integer::condition("JNZ",flags)) goto L00493ecd;
  }
  L00493eeb: { // 0x493eeb: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493eed: { // 0x493eed: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493eef: { // 0x493eef: 8906 MOV dword ptr [ESI], EAX
    m.w32((s.si), s.ax);
  }
  L00493ef1: { // 0x493ef1: 895e04 MOV dword ptr [ESI + 4], EBX
    m.w32((s.si+4u), s.bx);
  }
  L00493ef4: { // 0x493ef4: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00493ef8: { // 0x493ef8: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00493ef9: { // 0x493ef9: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00493efa: { // 0x493efa: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00493efe: { // 0x493efe: 7582 JNZ 0x493e82
    if(integer::condition("JNZ",flags)) goto L00493e82;
  }
  L00493f00: { // 0x493f00: 8b4604 MOV EAX, dword ptr [ESI + 4]
    s.ax = m.r32((s.si+4u));
  }
  L00493f03: { // 0x493f03: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00493f05: { // 0x493f05: 7459 JZ 0x493f60
    if(integer::condition("JZ",flags)) goto L00493f60;
  }
  L00493f07: { // 0x493f07: 8ac8 MOV CL, AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L00493f09: { // 0x493f09: 884c3008 MOV byte ptr [EAX + ESI + 8], CL
    m.w8((s.ax+s.si+8u), (s.cx & 0xffu));
  }
  L00493f0d: { // 0x493f0d: 8b4604 MOV EAX, dword ptr [ESI + 4]
    s.ax = m.r32((s.si+4u));
  }
  L00493f10: { // 0x493f10: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493f11: { // 0x493f11: 83f804 CMP EAX, 4
    (void)integer::sub(s.ax,4u,32,flags);
  }
  L00493f14: { // 0x493f14: 730d JAE 0x493f23
    if(integer::condition("JNC",flags)) goto L00493f23;
  }
  L00493f16: { // 0x493f16: 8a5608 MOV DL, byte ptr [ESI + 8]
    s.dx = with_al(s.dx, m.r8((s.si+8u)));
  }
  L00493f19: { // 0x493f19: 88540608 MOV byte ptr [ESI + EAX + 8], DL
    m.w8((s.si+s.ax+8u), (s.dx & 0xffu));
  }
  L00493f1d: { // 0x493f1d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493f1e: { // 0x493f1e: 83f804 CMP EAX, 4
    (void)integer::sub(s.ax,4u,32,flags);
  }
  L00493f21: { // 0x493f21: 72f3 JB 0x493f16
    if(integer::condition("JC",flags)) goto L00493f16;
  }
  L00493f23: { // 0x493f23: 8b4608 MOV EAX, dword ptr [ESI + 8]
    s.ax = m.r32((s.si+8u));
  }
  L00493f26: { // 0x493f26: 8b36 MOV ESI, dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L00493f28: { // 0x493f28: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00493f2c: { // 0x493f2c: 8d442414 LEA EAX, [ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00493f30: { // 0x493f30: f7d6 NOT ESI
    s.si = (~(s.si)&integer::mask(32));
  }
  L00493f32: { // 0x493f32: b904000000 MOV ECX, 4
    s.cx = 4u;
  }
  L00493f37: { // 0x493f37: 8bd6 MOV EDX, ESI
    s.dx = s.si;
  }
  L00493f39: { // 0x493f39: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493f3b: { // 0x493f3b: 8a18 MOV BL, byte ptr [EAX]
    s.bx = with_al(s.bx, m.r8((s.ax)));
  }
  L00493f3d: { // 0x493f3d: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00493f43: { // 0x493f43: 33d3 XOR EDX, EBX
    s.dx = integer::logical((s.dx)^(s.bx),32,flags);
  }
  L00493f45: { // 0x493f45: c1ee08 SHR ESI, 8
    s.si = integer::shift(s.si,8u,32,flags,integer::Shift::right);
  }
  L00493f48: { // 0x493f48: 8b149534067c00 MOV EDX, dword ptr [EDX*4 + 0x7c0634]
    s.dx = m.r32(((s.dx * 4u)+0x007c0634u));
  }
  L00493f4f: { // 0x493f4f: 33f2 XOR ESI, EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L00493f51: { // 0x493f51: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493f52: { // 0x493f52: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00493f53: { // 0x493f53: 75e2 JNZ 0x493f37
    if(integer::condition("JNZ",flags)) goto L00493f37;
  }
  L00493f55: { // 0x493f55: f7d6 NOT ESI
    s.si = (~(s.si)&integer::mask(32));
  }
  L00493f57: { // 0x493f57: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L00493f59: { // 0x493f59: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00493f5a: { // 0x493f5a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00493f5b: { // 0x493f5b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00493f5c: { // 0x493f5c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00493f5d: { // 0x493f5d: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00493f60: { // 0x493f60: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00493f62: { // 0x493f62: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00493f63: { // 0x493f63: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00493f64: { // 0x493f64: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00493f65: { // 0x493f65: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00493f66: { // 0x493f66: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00093f70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00493f70: { // 0x493f70: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L00493f74: { // 0x493f74: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00493f75: { // 0x493f75: 8bf2 MOV ESI, EDX
    s.si = s.dx;
  }
  L00493f77: { // 0x493f77: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00493f78: { // 0x493f78: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00493f7a: { // 0x493f7a: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493f7c: { // 0x493f7c: 7423 JZ 0x493fa1
    if(integer::condition("JZ",flags)) goto L00493fa1;
  }
  L00493f7e: { // 0x493f7e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00493f7f: { // 0x493f7f: 8d7201 LEA ESI, [EDX + 1]
    s.si = (s.dx+1u);
  }
  L00493f82: { // 0x493f82: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00493f84: { // 0x493f84: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493f86: { // 0x493f86: 8a19 MOV BL, byte ptr [ECX]
    s.bx = with_al(s.bx, m.r8((s.cx)));
  }
  L00493f88: { // 0x493f88: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00493f8e: { // 0x493f8e: 33d3 XOR EDX, EBX
    s.dx = integer::logical((s.dx)^(s.bx),32,flags);
  }
  L00493f90: { // 0x493f90: c1e808 SHR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::right);
  }
  L00493f93: { // 0x493f93: 8b149534067c00 MOV EDX, dword ptr [EDX*4 + 0x7c0634]
    s.dx = m.r32(((s.dx * 4u)+0x007c0634u));
  }
  L00493f9a: { // 0x493f9a: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00493f9c: { // 0x493f9c: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00493f9d: { // 0x493f9d: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L00493f9e: { // 0x493f9e: 75e2 JNZ 0x493f82
    if(integer::condition("JNZ",flags)) goto L00493f82;
  }
  L00493fa0: { // 0x493fa0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00493fa1: { // 0x493fa1: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493fa3: { // 0x493fa3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00493fa4: { // 0x493fa4: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4799760u:f_00093d10(m,s,child,{});break;
case 4799824u:f_00093d50(m,s,child,{});break;
case 4799856u:f_00093d70(m,s,child,{});break;
case 4799584u:f_00093c60(m,s,child,{});break;
case 4799904u:f_00093da0(m,s,child,{});break;
case 4800368u:f_00093f70(m,s,child,{});break;
default:throw std::domain_error("recovery768 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00659db0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00659db0: { // 0x659db0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00659db1: { // 0x659db1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00659db2: { // 0x659db2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00659db4: { // 0x659db4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00659db5: { // 0x659db5: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00659db9: { // 0x659db9: 8d869a090000 LEA EAX,[ESI + 0x99a]
    s.ax = (s.si+0x0000099au);
  }
  L00659dbf: { // 0x659dbf: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659dc1: { // 0x659dc1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00659dc2: { // 0x659dc2: e8a99fe3ff CALL 0x00493d70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d70u,6659527u); flags=s.arithmetic_flags;
  }
  L00659dc7: { // 0x659dc7: 8b8ebc090000 MOV ECX,dword ptr [ESI + 0x9bc]
    s.cx = m.r32((s.si+0x000009bcu));
  }
  L00659dcd: { // 0x659dcd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00659dce: { // 0x659dce: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659dd0: { // 0x659dd0: e83b9fe3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659541u); flags=s.arithmetic_flags;
  }
  L00659dd5: { // 0x659dd5: 8b96c0090000 MOV EDX,dword ptr [ESI + 0x9c0]
    s.dx = m.r32((s.si+0x000009c0u));
  }
  L00659ddb: { // 0x659ddb: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659ddd: { // 0x659ddd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00659dde: { // 0x659dde: e82d9fe3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659555u); flags=s.arithmetic_flags;
  }
  L00659de3: { // 0x659de3: 8b86c4090000 MOV EAX,dword ptr [ESI + 0x9c4]
    s.ax = m.r32((s.si+0x000009c4u));
  }
  L00659de9: { // 0x659de9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659deb: { // 0x659deb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00659dec: { // 0x659dec: e81f9fe3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659569u); flags=s.arithmetic_flags;
  }
  L00659df1: { // 0x659df1: 8b8ec8090000 MOV ECX,dword ptr [ESI + 0x9c8]
    s.cx = m.r32((s.si+0x000009c8u));
  }
  L00659df7: { // 0x659df7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00659df8: { // 0x659df8: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659dfa: { // 0x659dfa: e8119fe3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659583u); flags=s.arithmetic_flags;
  }
  L00659dff: { // 0x659dff: 8b96cc090000 MOV EDX,dword ptr [ESI + 0x9cc]
    s.dx = m.r32((s.si+0x000009ccu));
  }
  L00659e05: { // 0x659e05: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659e07: { // 0x659e07: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00659e08: { // 0x659e08: e8039fe3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659597u); flags=s.arithmetic_flags;
  }
  L00659e0d: { // 0x659e0d: 8b86d0090000 MOV EAX,dword ptr [ESI + 0x9d0]
    s.ax = m.r32((s.si+0x000009d0u));
  }
  L00659e13: { // 0x659e13: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659e15: { // 0x659e15: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00659e16: { // 0x659e16: e8f59ee3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659611u); flags=s.arithmetic_flags;
  }
  L00659e1b: { // 0x659e1b: 8b8ed4090000 MOV ECX,dword ptr [ESI + 0x9d4]
    s.cx = m.r32((s.si+0x000009d4u));
  }
  L00659e21: { // 0x659e21: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00659e22: { // 0x659e22: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659e24: { // 0x659e24: e8e79ee3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659625u); flags=s.arithmetic_flags;
  }
  L00659e29: { // 0x659e29: 8b96fc110000 MOV EDX,dword ptr [ESI + 0x11fc]
    s.dx = m.r32((s.si+0x000011fcu));
  }
  L00659e2f: { // 0x659e2f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659e31: { // 0x659e31: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00659e32: { // 0x659e32: e8d99ee3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659639u); flags=s.arithmetic_flags;
  }
  L00659e37: { // 0x659e37: 8b860c120000 MOV EAX,dword ptr [ESI + 0x120c]
    s.ax = m.r32((s.si+0x0000120cu));
  }
  L00659e3d: { // 0x659e3d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659e3f: { // 0x659e3f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00659e40: { // 0x659e40: e8cb9ee3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659653u); flags=s.arithmetic_flags;
  }
  L00659e45: { // 0x659e45: 8b8ef8110000 MOV ECX,dword ptr [ESI + 0x11f8]
    s.cx = m.r32((s.si+0x000011f8u));
  }
  L00659e4b: { // 0x659e4b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00659e4c: { // 0x659e4c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659e4e: { // 0x659e4e: e8bd9ee3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659667u); flags=s.arithmetic_flags;
  }
  L00659e53: { // 0x659e53: 8b9604120000 MOV EDX,dword ptr [ESI + 0x1204]
    s.dx = m.r32((s.si+0x00001204u));
  }
  L00659e59: { // 0x659e59: 8b8600120000 MOV EAX,dword ptr [ESI + 0x1200]
    s.ax = m.r32((s.si+0x00001200u));
  }
  L00659e5f: { // 0x659e5f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00659e60: { // 0x659e60: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00659e61: { // 0x659e61: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659e63: { // 0x659e63: e8e89ee3ff CALL 0x00493d50
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d50u,6659688u); flags=s.arithmetic_flags;
  }
  L00659e68: { // 0x659e68: 8a8e3a220000 MOV CL,byte ptr [ESI + 0x223a]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000223au)));
  }
  L00659e6e: { // 0x659e6e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00659e6f: { // 0x659e6f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659e71: { // 0x659e71: e8ea9de3ff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6659702u); flags=s.arithmetic_flags;
  }
  L00659e76: { // 0x659e76: 8a9631220000 MOV DL,byte ptr [ESI + 0x2231]
    s.dx = with_al(s.dx, m.r8((s.si+0x00002231u)));
  }
  L00659e7c: { // 0x659e7c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659e7e: { // 0x659e7e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00659e7f: { // 0x659e7f: e8dc9de3ff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6659716u); flags=s.arithmetic_flags;
  }
  L00659e84: { // 0x659e84: 8b8e08120000 MOV ECX,dword ptr [ESI + 0x1208]
    s.cx = m.r32((s.si+0x00001208u));
  }
  L00659e8a: { // 0x659e8a: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L00659e8f: { // 0x659e8f: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L00659e91: { // 0x659e91: c1fa05 SAR EDX,0x5
    s.dx = integer::shift(s.dx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L00659e94: { // 0x659e94: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00659e96: { // 0x659e96: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659e98: { // 0x659e98: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L00659e9b: { // 0x659e9b: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00659e9d: { // 0x659e9d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00659e9e: { // 0x659e9e: e86d9ee3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659747u); flags=s.arithmetic_flags;
  }
  L00659ea3: { // 0x659ea3: 8b8e24220000 MOV ECX,dword ptr [ESI + 0x2224]
    s.cx = m.r32((s.si+0x00002224u));
  }
  L00659ea9: { // 0x659ea9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00659eaa: { // 0x659eaa: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659eac: { // 0x659eac: e85f9ee3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659761u); flags=s.arithmetic_flags;
  }
  L00659eb1: { // 0x659eb1: 8a9630220000 MOV DL,byte ptr [ESI + 0x2230]
    s.dx = with_al(s.dx, m.r8((s.si+0x00002230u)));
  }
  L00659eb7: { // 0x659eb7: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659eb9: { // 0x659eb9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00659eba: { // 0x659eba: e8a19de3ff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6659775u); flags=s.arithmetic_flags;
  }
  L00659ebf: { // 0x659ebf: 8b864c220000 MOV EAX,dword ptr [ESI + 0x224c]
    s.ax = m.r32((s.si+0x0000224cu));
  }
  L00659ec5: { // 0x659ec5: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659ec7: { // 0x659ec7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00659ec8: { // 0x659ec8: e8439ee3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659789u); flags=s.arithmetic_flags;
  }
  L00659ecd: { // 0x659ecd: 8a8e32220000 MOV CL,byte ptr [ESI + 0x2232]
    s.cx = with_al(s.cx, m.r8((s.si+0x00002232u)));
  }
  L00659ed3: { // 0x659ed3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00659ed4: { // 0x659ed4: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659ed6: { // 0x659ed6: e8859de3ff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6659803u); flags=s.arithmetic_flags;
  }
  L00659edb: { // 0x659edb: 8a9633220000 MOV DL,byte ptr [ESI + 0x2233]
    s.dx = with_al(s.dx, m.r8((s.si+0x00002233u)));
  }
  L00659ee1: { // 0x659ee1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659ee3: { // 0x659ee3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00659ee4: { // 0x659ee4: e8779de3ff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6659817u); flags=s.arithmetic_flags;
  }
  L00659ee9: { // 0x659ee9: 8a8634220000 MOV AL,byte ptr [ESI + 0x2234]
    s.ax = with_al(s.ax, m.r8((s.si+0x00002234u)));
  }
  L00659eef: { // 0x659eef: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659ef1: { // 0x659ef1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00659ef2: { // 0x659ef2: e8699de3ff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6659831u); flags=s.arithmetic_flags;
  }
  L00659ef7: { // 0x659ef7: 8a8e36220000 MOV CL,byte ptr [ESI + 0x2236]
    s.cx = with_al(s.cx, m.r8((s.si+0x00002236u)));
  }
  L00659efd: { // 0x659efd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00659efe: { // 0x659efe: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659f00: { // 0x659f00: e85b9de3ff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6659845u); flags=s.arithmetic_flags;
  }
  L00659f05: { // 0x659f05: 8a9638220000 MOV DL,byte ptr [ESI + 0x2238]
    s.dx = with_al(s.dx, m.r8((s.si+0x00002238u)));
  }
  L00659f0b: { // 0x659f0b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659f0d: { // 0x659f0d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00659f0e: { // 0x659f0e: e84d9de3ff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6659859u); flags=s.arithmetic_flags;
  }
  L00659f13: { // 0x659f13: 8a8635220000 MOV AL,byte ptr [ESI + 0x2235]
    s.ax = with_al(s.ax, m.r8((s.si+0x00002235u)));
  }
  L00659f19: { // 0x659f19: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659f1b: { // 0x659f1b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00659f1c: { // 0x659f1c: e83f9de3ff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6659873u); flags=s.arithmetic_flags;
  }
  L00659f21: { // 0x659f21: 8b8e0c120000 MOV ECX,dword ptr [ESI + 0x120c]
    s.cx = m.r32((s.si+0x0000120cu));
  }
  L00659f27: { // 0x659f27: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00659f28: { // 0x659f28: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659f2a: { // 0x659f2a: e8e19de3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659887u); flags=s.arithmetic_flags;
  }
  L00659f2f: { // 0x659f2f: 8b9650220000 MOV EDX,dword ptr [ESI + 0x2250]
    s.dx = m.r32((s.si+0x00002250u));
  }
  L00659f35: { // 0x659f35: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659f37: { // 0x659f37: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00659f38: { // 0x659f38: e8d39de3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659901u); flags=s.arithmetic_flags;
  }
  L00659f3d: { // 0x659f3d: 8b8ec8070000 MOV ECX,dword ptr [ESI + 0x7c8]
    s.cx = m.r32((s.si+0x000007c8u));
  }
  L00659f43: { // 0x659f43: 8b86d0070000 MOV EAX,dword ptr [ESI + 0x7d0]
    s.ax = m.r32((s.si+0x000007d0u));
  }
  L00659f49: { // 0x659f49: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L00659f4c: { // 0x659f4c: 7412 JZ 0x00659f60
    if(integer::condition("JZ",flags)) goto L00659f60;
  }
  L00659f4e: { // 0x659f4e: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L00659f54: { // 0x659f54: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00659f56: { // 0x659f56: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00659f58: { // 0x659f58: 7d04 JGE 0x00659f5e
    if(integer::condition("JGE",flags)) goto L00659f5e;
  }
  L00659f5a: { // 0x659f5a: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00659f5c: { // 0x659f5c: eb02 JMP 0x00659f60
    goto L00659f60;
  }
  L00659f5e: { // 0x659f5e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00659f60: { // 0x659f60: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00659f61: { // 0x659f61: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659f63: { // 0x659f63: e8a89de3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659944u); flags=s.arithmetic_flags;
  }
  L00659f68: { // 0x659f68: 8b96f8070000 MOV EDX,dword ptr [ESI + 0x7f8]
    s.dx = m.r32((s.si+0x000007f8u));
  }
  L00659f6e: { // 0x659f6e: 8b8600080000 MOV EAX,dword ptr [ESI + 0x800]
    s.ax = m.r32((s.si+0x00000800u));
  }
  L00659f74: { // 0x659f74: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L00659f77: { // 0x659f77: 7412 JZ 0x00659f8b
    if(integer::condition("JZ",flags)) goto L00659f8b;
  }
  L00659f79: { // 0x659f79: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L00659f7f: { // 0x659f7f: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00659f81: { // 0x659f81: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00659f83: { // 0x659f83: 7d04 JGE 0x00659f89
    if(integer::condition("JGE",flags)) goto L00659f89;
  }
  L00659f85: { // 0x659f85: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00659f87: { // 0x659f87: eb02 JMP 0x00659f8b
    goto L00659f8b;
  }
  L00659f89: { // 0x659f89: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00659f8b: { // 0x659f8b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00659f8c: { // 0x659f8c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659f8e: { // 0x659f8e: e87d9de3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6659987u); flags=s.arithmetic_flags;
  }
  L00659f93: { // 0x659f93: 8b9604080000 MOV EDX,dword ptr [ESI + 0x804]
    s.dx = m.r32((s.si+0x00000804u));
  }
  L00659f99: { // 0x659f99: 8b860c080000 MOV EAX,dword ptr [ESI + 0x80c]
    s.ax = m.r32((s.si+0x0000080cu));
  }
  L00659f9f: { // 0x659f9f: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L00659fa2: { // 0x659fa2: 7412 JZ 0x00659fb6
    if(integer::condition("JZ",flags)) goto L00659fb6;
  }
  L00659fa4: { // 0x659fa4: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L00659faa: { // 0x659faa: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00659fac: { // 0x659fac: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00659fae: { // 0x659fae: 7d04 JGE 0x00659fb4
    if(integer::condition("JGE",flags)) goto L00659fb4;
  }
  L00659fb0: { // 0x659fb0: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00659fb2: { // 0x659fb2: eb02 JMP 0x00659fb6
    goto L00659fb6;
  }
  L00659fb4: { // 0x659fb4: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00659fb6: { // 0x659fb6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00659fb7: { // 0x659fb7: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659fb9: { // 0x659fb9: e8529de3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660030u); flags=s.arithmetic_flags;
  }
  L00659fbe: { // 0x659fbe: 8b9610080000 MOV EDX,dword ptr [ESI + 0x810]
    s.dx = m.r32((s.si+0x00000810u));
  }
  L00659fc4: { // 0x659fc4: 8b8618080000 MOV EAX,dword ptr [ESI + 0x818]
    s.ax = m.r32((s.si+0x00000818u));
  }
  L00659fca: { // 0x659fca: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L00659fcd: { // 0x659fcd: 7412 JZ 0x00659fe1
    if(integer::condition("JZ",flags)) goto L00659fe1;
  }
  L00659fcf: { // 0x659fcf: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L00659fd5: { // 0x659fd5: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00659fd7: { // 0x659fd7: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00659fd9: { // 0x659fd9: 7d04 JGE 0x00659fdf
    if(integer::condition("JGE",flags)) goto L00659fdf;
  }
  L00659fdb: { // 0x659fdb: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00659fdd: { // 0x659fdd: eb02 JMP 0x00659fe1
    goto L00659fe1;
  }
  L00659fdf: { // 0x659fdf: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00659fe1: { // 0x659fe1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00659fe2: { // 0x659fe2: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00659fe4: { // 0x659fe4: e8279de3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660073u); flags=s.arithmetic_flags;
  }
  L00659fe9: { // 0x659fe9: 8b961c080000 MOV EDX,dword ptr [ESI + 0x81c]
    s.dx = m.r32((s.si+0x0000081cu));
  }
  L00659fef: { // 0x659fef: 8b8624080000 MOV EAX,dword ptr [ESI + 0x824]
    s.ax = m.r32((s.si+0x00000824u));
  }
  L00659ff5: { // 0x659ff5: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L00659ff8: { // 0x659ff8: 7412 JZ 0x0065a00c
    if(integer::condition("JZ",flags)) goto L0065a00c;
  }
  L00659ffa: { // 0x659ffa: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L0065a000: { // 0x65a000: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0065a002: { // 0x65a002: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0065a004: { // 0x65a004: 7d04 JGE 0x0065a00a
    if(integer::condition("JGE",flags)) goto L0065a00a;
  }
  L0065a006: { // 0x65a006: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0065a008: { // 0x65a008: eb02 JMP 0x0065a00c
    goto L0065a00c;
  }
  L0065a00a: { // 0x65a00a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0065a00c: { // 0x65a00c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0065a00d: { // 0x65a00d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a00f: { // 0x65a00f: e8fc9ce3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660116u); flags=s.arithmetic_flags;
  }
  L0065a014: { // 0x65a014: 8b8614060000 MOV EAX,dword ptr [ESI + 0x614]
    s.ax = m.r32((s.si+0x00000614u));
  }
  L0065a01a: { // 0x65a01a: 8b9e1c060000 MOV EBX,dword ptr [ESI + 0x61c]
    s.bx = m.r32((s.si+0x0000061cu));
  }
  L0065a020: { // 0x65a020: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0065a023: { // 0x65a023: 7413 JZ 0x0065a038
    if(integer::condition("JZ",flags)) goto L0065a038;
  }
  L0065a025: { // 0x65a025: 8d8e18060000 LEA ECX,[ESI + 0x618]
    s.cx = (s.si+0x00000618u);
  }
  L0065a02b: { // 0x65a02b: e8a05a0300 CALL 0x0068fad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0068fad0u,6660144u); flags=s.arithmetic_flags;
  }
  L0065a030: { // 0x65a030: 2b8614060000 SUB EAX,dword ptr [ESI + 0x614]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x00000614u)),32,flags);
  }
  L0065a036: { // 0x65a036: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L0065a038: { // 0x65a038: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0065a039: { // 0x65a039: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a03b: { // 0x65a03b: e8d09ce3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660160u); flags=s.arithmetic_flags;
  }
  L0065a040: { // 0x65a040: 8b860c060000 MOV EAX,dword ptr [ESI + 0x60c]
    s.ax = m.r32((s.si+0x0000060cu));
  }
  L0065a046: { // 0x65a046: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a048: { // 0x65a048: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0065a049: { // 0x65a049: e8c29ce3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660174u); flags=s.arithmetic_flags;
  }
  L0065a04e: { // 0x65a04e: 8b8e10060000 MOV ECX,dword ptr [ESI + 0x610]
    s.cx = m.r32((s.si+0x00000610u));
  }
  L0065a054: { // 0x65a054: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0065a055: { // 0x65a055: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a057: { // 0x65a057: e8b49ce3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660188u); flags=s.arithmetic_flags;
  }
  L0065a05c: { // 0x65a05c: 8b9638080000 MOV EDX,dword ptr [ESI + 0x838]
    s.dx = m.r32((s.si+0x00000838u));
  }
  L0065a062: { // 0x65a062: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a064: { // 0x65a064: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0065a065: { // 0x65a065: e8a69ce3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660202u); flags=s.arithmetic_flags;
  }
  L0065a06a: { // 0x65a06a: 8b86c0220000 MOV EAX,dword ptr [ESI + 0x22c0]
    s.ax = m.r32((s.si+0x000022c0u));
  }
  L0065a070: { // 0x65a070: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a072: { // 0x65a072: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0065a073: { // 0x65a073: e8989ce3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660216u); flags=s.arithmetic_flags;
  }
  L0065a078: { // 0x65a078: 8b8ec4220000 MOV ECX,dword ptr [ESI + 0x22c4]
    s.cx = m.r32((s.si+0x000022c4u));
  }
  L0065a07e: { // 0x65a07e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0065a07f: { // 0x65a07f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a081: { // 0x65a081: e88a9ce3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660230u); flags=s.arithmetic_flags;
  }
  L0065a086: { // 0x65a086: 8a9628220000 MOV DL,byte ptr [ESI + 0x2228]
    s.dx = with_al(s.dx, m.r8((s.si+0x00002228u)));
  }
  L0065a08c: { // 0x65a08c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a08e: { // 0x65a08e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0065a08f: { // 0x65a08f: e8cc9be3ff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6660244u); flags=s.arithmetic_flags;
  }
  L0065a094: { // 0x65a094: 8b86c8220000 MOV EAX,dword ptr [ESI + 0x22c8]
    s.ax = m.r32((s.si+0x000022c8u));
  }
  L0065a09a: { // 0x65a09a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a09c: { // 0x65a09c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0065a09d: { // 0x65a09d: e86e9ce3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660258u); flags=s.arithmetic_flags;
  }
  L0065a0a2: { // 0x65a0a2: 8b8ecc220000 MOV ECX,dword ptr [ESI + 0x22cc]
    s.cx = m.r32((s.si+0x000022ccu));
  }
  L0065a0a8: { // 0x65a0a8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0065a0a9: { // 0x65a0a9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a0ab: { // 0x65a0ab: e8609ce3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660272u); flags=s.arithmetic_flags;
  }
  L0065a0b0: { // 0x65a0b0: 8b96d0220000 MOV EDX,dword ptr [ESI + 0x22d0]
    s.dx = m.r32((s.si+0x000022d0u));
  }
  L0065a0b6: { // 0x65a0b6: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a0b8: { // 0x65a0b8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0065a0b9: { // 0x65a0b9: e8529ce3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660286u); flags=s.arithmetic_flags;
  }
  L0065a0be: { // 0x65a0be: 8b86d4220000 MOV EAX,dword ptr [ESI + 0x22d4]
    s.ax = m.r32((s.si+0x000022d4u));
  }
  L0065a0c4: { // 0x65a0c4: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a0c6: { // 0x65a0c6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0065a0c7: { // 0x65a0c7: e8449ce3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660300u); flags=s.arithmetic_flags;
  }
  L0065a0cc: { // 0x65a0cc: 8b8ed8220000 MOV ECX,dword ptr [ESI + 0x22d8]
    s.cx = m.r32((s.si+0x000022d8u));
  }
  L0065a0d2: { // 0x65a0d2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0065a0d3: { // 0x65a0d3: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a0d5: { // 0x65a0d5: e8369ce3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660314u); flags=s.arithmetic_flags;
  }
  L0065a0da: { // 0x65a0da: 8b96dc220000 MOV EDX,dword ptr [ESI + 0x22dc]
    s.dx = m.r32((s.si+0x000022dcu));
  }
  L0065a0e0: { // 0x65a0e0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a0e2: { // 0x65a0e2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0065a0e3: { // 0x65a0e3: e8289ce3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660328u); flags=s.arithmetic_flags;
  }
  L0065a0e8: { // 0x65a0e8: 8b86a8220000 MOV EAX,dword ptr [ESI + 0x22a8]
    s.ax = m.r32((s.si+0x000022a8u));
  }
  L0065a0ee: { // 0x65a0ee: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a0f0: { // 0x65a0f0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0065a0f1: { // 0x65a0f1: e81a9ce3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660342u); flags=s.arithmetic_flags;
  }
  L0065a0f6: { // 0x65a0f6: 8b8eac220000 MOV ECX,dword ptr [ESI + 0x22ac]
    s.cx = m.r32((s.si+0x000022acu));
  }
  L0065a0fc: { // 0x65a0fc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0065a0fd: { // 0x65a0fd: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a0ff: { // 0x65a0ff: e80c9ce3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660356u); flags=s.arithmetic_flags;
  }
  L0065a104: { // 0x65a104: 8b96b0220000 MOV EDX,dword ptr [ESI + 0x22b0]
    s.dx = m.r32((s.si+0x000022b0u));
  }
  L0065a10a: { // 0x65a10a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0065a10c: { // 0x65a10c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0065a10d: { // 0x65a10d: e8fe9be3ff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6660370u); flags=s.arithmetic_flags;
  }
  L0065a112: { // 0x65a112: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0065a113: { // 0x65a113: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0065a114: { // 0x65a114: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0065a115: { // 0x65a115: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
