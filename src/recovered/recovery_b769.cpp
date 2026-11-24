#include "recovered/recovery_b769_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b769 {
namespace {
void f_00093d10(Memory&,State&,Frame&,const Operations&);
void f_00093d30(Memory&,State&,Frame&,const Operations&);
void f_00093d50(Memory&,State&,Frame&,const Operations&);
void f_00093bd0(Memory&,State&,Frame&,const Operations&);
void f_00093c60(Memory&,State&,Frame&,const Operations&);
void f_00093da0(Memory&,State&,Frame&,const Operations&);
void f_00093f70(Memory&,State&,Frame&,const Operations&);
void f_0022e190(Memory&,State&,Frame&,const Operations&);
void f_00191e40(Memory&,State&,Frame&,const Operations&);
void f_001cd1a0(Memory&,State&,Frame&,const Operations&);
void f_000101b0(Memory&,State&,Frame&,const Operations&);
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
void f_00093d30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00493d30: { // 0x493d30: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L00493d34: { // 0x493d34: 8d542404 LEA EDX, [ESP + 4]
    s.dx = (f.sp+4u);
  }
  L00493d38: { // 0x493d38: 6a04 PUSH 4
    f.push(m,4u);
  }
  L00493d3a: { // 0x493d3a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00493d3b: { // 0x493d3b: 8944240c MOV dword ptr [ESP + 0xc], EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L00493d3f: { // 0x493d3f: e85c000000 CALL 0x493da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493da0u,4799812u); flags=s.arithmetic_flags;
  }
  L00493d44: { // 0x493d44: c20400 RET 4
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
void f_00093bd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00493bd0: { // 0x493bd0: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L00493bd3: { // 0x493bd3: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00493bd5: { // 0x493bd5: 7503 JNZ 0x493bda
    if(integer::condition("JNZ",flags)) goto L00493bda;
  }
  L00493bd7: { // 0x493bd7: 894108 MOV dword ptr [ECX + 8], EAX
    m.w32((s.cx+8u), s.ax);
  }
  L00493bda: { // 0x493bda: 8a542404 MOV DL, byte ptr [ESP + 4]
    s.dx = with_al(s.dx, m.r8((f.sp+4u)));
  }
  L00493bde: { // 0x493bde: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00493bdf: { // 0x493bdf: 88540808 MOV byte ptr [EAX + ECX + 8], DL
    m.w8((s.ax+s.cx+8u), (s.dx & 0xffu));
  }
  L00493be3: { // 0x493be3: 8b7104 MOV ESI, dword ptr [ECX + 4]
    s.si = m.r32((s.cx+4u));
  }
  L00493be6: { // 0x493be6: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00493be7: { // 0x493be7: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L00493be9: { // 0x493be9: 897104 MOV dword ptr [ECX + 4], ESI
    m.w32((s.cx+4u), s.si);
  }
  L00493bec: { // 0x493bec: 83f804 CMP EAX, 4
    (void)integer::sub(s.ax,4u,32,flags);
  }
  L00493bef: { // 0x493bef: 755c JNZ 0x493c4d
    if(integer::condition("JNZ",flags)) goto L00493c4d;
  }
  L00493bf1: { // 0x493bf1: 8a4104 MOV AL, byte ptr [ECX + 4]
    s.ax = with_al(s.ax, m.r8((s.cx+4u)));
  }
  L00493bf4: { // 0x493bf4: 88410c MOV byte ptr [ECX + 0xc], AL
    m.w8((s.cx+0x0000000cu), (s.ax & 0xffu));
  }
  L00493bf7: { // 0x493bf7: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L00493bfa: { // 0x493bfa: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493bfb: { // 0x493bfb: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00493bfd: { // 0x493bfd: 730d JAE 0x493c0c
    if(integer::condition("JNC",flags)) goto L00493c0c;
  }
  L00493bff: { // 0x493bff: 8a5108 MOV DL, byte ptr [ECX + 8]
    s.dx = with_al(s.dx, m.r8((s.cx+8u)));
  }
  L00493c02: { // 0x493c02: 88540108 MOV byte ptr [ECX + EAX + 8], DL
    m.w8((s.cx+s.ax+8u), (s.dx & 0xffu));
  }
  L00493c06: { // 0x493c06: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493c07: { // 0x493c07: 83f804 CMP EAX, 4
    (void)integer::sub(s.ax,4u,32,flags);
  }
  L00493c0a: { // 0x493c0a: 72f3 JB 0x493bff
    if(integer::condition("JC",flags)) goto L00493bff;
  }
  L00493c0c: { // 0x493c0c: 8b4108 MOV EAX, dword ptr [ECX + 8]
    s.ax = m.r32((s.cx+8u));
  }
  L00493c0f: { // 0x493c0f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00493c10: { // 0x493c10: 8944240c MOV dword ptr [ESP + 0xc], EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L00493c14: { // 0x493c14: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00493c16: { // 0x493c16: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00493c17: { // 0x493c17: 8d742410 LEA ESI, [ESP + 0x10]
    s.si = (f.sp+0x00000010u);
  }
  L00493c1b: { // 0x493c1b: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493c1d: { // 0x493c1d: bf04000000 MOV EDI, 4
    s.di = 4u;
  }
  L00493c22: { // 0x493c22: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00493c24: { // 0x493c24: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493c26: { // 0x493c26: 8a1e MOV BL, byte ptr [ESI]
    s.bx = with_al(s.bx, m.r8((s.si)));
  }
  L00493c28: { // 0x493c28: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00493c2e: { // 0x493c2e: 33d3 XOR EDX, EBX
    s.dx = integer::logical((s.dx)^(s.bx),32,flags);
  }
  L00493c30: { // 0x493c30: c1e808 SHR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::right);
  }
  L00493c33: { // 0x493c33: 8b149534067c00 MOV EDX, dword ptr [EDX*4 + 0x7c0634]
    s.dx = m.r32(((s.dx * 4u)+0x007c0634u));
  }
  L00493c3a: { // 0x493c3a: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00493c3c: { // 0x493c3c: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00493c3d: { // 0x493c3d: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00493c3e: { // 0x493c3e: 75e2 JNZ 0x493c22
    if(integer::condition("JNZ",flags)) goto L00493c22;
  }
  L00493c40: { // 0x493c40: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493c42: { // 0x493c42: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00493c43: { // 0x493c43: 8901 MOV dword ptr [ECX], EAX
    m.w32((s.cx), s.ax);
  }
  L00493c45: { // 0x493c45: c7410400000000 MOV dword ptr [ECX + 4], 0
    m.w32((s.cx+4u), 0u);
  }
  L00493c4c: { // 0x493c4c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00493c4d: { // 0x493c4d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00493c4e: { // 0x493c4e: c20400 RET 4
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
void f_0022e190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062e190: { // 0x62e190: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062e191: { // 0x62e191: 8b5c2408 MOV EBX, dword ptr [ESP + 8]
    s.bx = m.r32((f.sp+8u));
  }
  L0062e195: { // 0x62e195: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062e196: { // 0x62e196: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062e197: { // 0x62e197: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L0062e199: { // 0x62e199: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062e19a: { // 0x62e19a: e8a13cf6ff CALL 0x591e40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00591e40u,6480287u); flags=s.arithmetic_flags;
  }
  L0062e19f: { // 0x62e19f: 8b86d0000000 MOV EAX, dword ptr [ESI + 0xd0]
    s.ax = m.r32((s.si+0x000000d0u));
  }
  L0062e1a5: { // 0x62e1a5: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0062e1a7: { // 0x62e1a7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062e1a8: { // 0x62e1a8: e8635be6ff CALL 0x493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6480301u); flags=s.arithmetic_flags;
  }
  L0062e1ad: { // 0x62e1ad: 8b86d0000000 MOV EAX, dword ptr [ESI + 0xd0]
    s.ax = m.r32((s.si+0x000000d0u));
  }
  L0062e1b3: { // 0x62e1b3: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0062e1b5: { // 0x62e1b5: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0062e1b7: { // 0x62e1b7: 7e40 JLE 0x62e1f9
    if(integer::condition("JLE",flags)) goto L0062e1f9;
  }
  L0062e1b9: { // 0x62e1b9: 8b8ecc000000 MOV ECX, dword ptr [ESI + 0xcc]
    s.cx = m.r32((s.si+0x000000ccu));
  }
  L0062e1bf: { // 0x62e1bf: 8b04b9 MOV EAX, dword ptr [ECX + EDI*4]
    s.ax = m.r32((s.cx+(s.di * 4u)));
  }
  L0062e1c2: { // 0x62e1c2: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0062e1c4: { // 0x62e1c4: 7428 JZ 0x62e1ee
    if(integer::condition("JZ",flags)) goto L0062e1ee;
  }
  L0062e1c6: { // 0x62e1c6: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0062e1c9: { // 0x62e1c9: 83c004 ADD EAX, 4
    s.ax = integer::add(s.ax,4u,32,flags);
  }
  L0062e1cc: { // 0x62e1cc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062e1cd: { // 0x62e1cd: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6480336u); flags=s.arithmetic_flags;
  }
  L0062e1d0: { // 0x62e1d0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062e1d1: { // 0x62e1d1: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0062e1d3: { // 0x62e1d3: e8385be6ff CALL 0x493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6480344u); flags=s.arithmetic_flags;
  }
  L0062e1d8: { // 0x62e1d8: 8b86cc000000 MOV EAX, dword ptr [ESI + 0xcc]
    s.ax = m.r32((s.si+0x000000ccu));
  }
  L0062e1de: { // 0x62e1de: 8b0cb8 MOV ECX, dword ptr [EAX + EDI*4]
    s.cx = m.r32((s.ax+(s.di * 4u)));
  }
  L0062e1e1: { // 0x62e1e1: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0062e1e3: { // 0x62e1e3: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),6480358u); flags=s.arithmetic_flags;
  }
  L0062e1e6: { // 0x62e1e6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062e1e7: { // 0x62e1e7: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L0062e1e9: { // 0x62e1e9: e8225be6ff CALL 0x493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6480366u); flags=s.arithmetic_flags;
  }
  L0062e1ee: { // 0x62e1ee: 8b86d0000000 MOV EAX, dword ptr [ESI + 0xd0]
    s.ax = m.r32((s.si+0x000000d0u));
  }
  L0062e1f4: { // 0x62e1f4: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0062e1f5: { // 0x62e1f5: 3bf8 CMP EDI, EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0062e1f7: { // 0x62e1f7: 7cc0 JL 0x62e1b9
    if(integer::condition("JL",flags)) goto L0062e1b9;
  }
  L0062e1f9: { // 0x62e1f9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062e1fa: { // 0x62e1fa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062e1fb: { // 0x62e1fb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062e1fc: { // 0x62e1fc: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00191e40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00591e40: { // 0x591e40: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00591e41: { // 0x591e41: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00591e42: { // 0x591e42: 8b7c240c MOV EDI, dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00591e46: { // 0x591e46: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00591e48: { // 0x591e48: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00591e49: { // 0x591e49: e852b30300 CALL 0x5cd1a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cd1a0u,5840462u); flags=s.arithmetic_flags;
  }
  L00591e4e: { // 0x591e4e: 8b8698000000 MOV EAX, dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L00591e54: { // 0x591e54: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00591e56: { // 0x591e56: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00591e57: { // 0x591e57: e8b41ef0ff CALL 0x493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,5840476u); flags=s.arithmetic_flags;
  }
  L00591e5c: { // 0x591e5c: 8b8e9c000000 MOV ECX, dword ptr [ESI + 0x9c]
    s.cx = m.r32((s.si+0x0000009cu));
  }
  L00591e62: { // 0x591e62: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00591e63: { // 0x591e63: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00591e65: { // 0x591e65: e8a61ef0ff CALL 0x493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,5840490u); flags=s.arithmetic_flags;
  }
  L00591e6a: { // 0x591e6a: 8b96a0000000 MOV EDX, dword ptr [ESI + 0xa0]
    s.dx = m.r32((s.si+0x000000a0u));
  }
  L00591e70: { // 0x591e70: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00591e72: { // 0x591e72: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00591e73: { // 0x591e73: e8981ef0ff CALL 0x493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,5840504u); flags=s.arithmetic_flags;
  }
  L00591e78: { // 0x591e78: 8b86a8000000 MOV EAX, dword ptr [ESI + 0xa8]
    s.ax = m.r32((s.si+0x000000a8u));
  }
  L00591e7e: { // 0x591e7e: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00591e80: { // 0x591e80: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00591e81: { // 0x591e81: e88a1ef0ff CALL 0x493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,5840518u); flags=s.arithmetic_flags;
  }
  L00591e86: { // 0x591e86: 8b96b0000000 MOV EDX, dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00591e8c: { // 0x591e8c: 8b86b8000000 MOV EAX, dword ptr [ESI + 0xb8]
    s.ax = m.r32((s.si+0x000000b8u));
  }
  L00591e92: { // 0x591e92: 83faff CMP EDX, -1
    (void)integer::sub(s.dx,4294967295u,32,flags);
  }
  L00591e95: { // 0x591e95: 7412 JZ 0x591ea9
    if(integer::condition("JZ",flags)) goto L00591ea9;
  }
  L00591e97: { // 0x591e97: 8b0d6c89a200 MOV ECX, dword ptr [0xa2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L00591e9d: { // 0x591e9d: 2bca SUB ECX, EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00591e9f: { // 0x591e9f: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00591ea1: { // 0x591ea1: 7d04 JGE 0x591ea7
    if(integer::condition("JGE",flags)) goto L00591ea7;
  }
  L00591ea3: { // 0x591ea3: 2bc1 SUB EAX, ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00591ea5: { // 0x591ea5: eb02 JMP 0x591ea9
    goto L00591ea9;
  }
  L00591ea7: { // 0x591ea7: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00591ea9: { // 0x591ea9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00591eaa: { // 0x591eaa: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00591eac: { // 0x591eac: e85f1ef0ff CALL 0x493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,5840561u); flags=s.arithmetic_flags;
  }
  L00591eb1: { // 0x591eb1: 8b8eac000000 MOV ECX, dword ptr [ESI + 0xac]
    s.cx = m.r32((s.si+0x000000acu));
  }
  L00591eb7: { // 0x591eb7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00591eb8: { // 0x591eb8: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00591eba: { // 0x591eba: e8511ef0ff CALL 0x493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,5840575u); flags=s.arithmetic_flags;
  }
  L00591ebf: { // 0x591ebf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00591ec0: { // 0x591ec0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00591ec1: { // 0x591ec1: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001cd1a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cd1a0: { // 0x5cd1a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cd1a1: { // 0x5cd1a1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cd1a2: { // 0x5cd1a2: 8b7c240c MOV EDI, dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L005cd1a6: { // 0x5cd1a6: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L005cd1a8: { // 0x5cd1a8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cd1a9: { // 0x5cd1a9: e80230e4ff CALL 0x4101b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004101b0u,6082990u); flags=s.arithmetic_flags;
  }
  L005cd1ae: { // 0x5cd1ae: 8b4630 MOV EAX, dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L005cd1b1: { // 0x5cd1b1: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cd1b3: { // 0x5cd1b3: 7412 JZ 0x5cd1c7
    if(integer::condition("JZ",flags)) goto L005cd1c7;
  }
  L005cd1b5: { // 0x5cd1b5: 8b4804 MOV ECX, dword ptr [EAX + 4]
    s.cx = m.r32((s.ax+4u));
  }
  L005cd1b8: { // 0x5cd1b8: 83c004 ADD EAX, 4
    s.ax = integer::add(s.ax,4u,32,flags);
  }
  L005cd1bb: { // 0x5cd1bb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cd1bc: { // 0x5cd1bc: ff5110 CALL dword ptr [ECX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000010u)),6083007u); flags=s.arithmetic_flags;
  }
  L005cd1bf: { // 0x5cd1bf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cd1c0: { // 0x5cd1c0: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005cd1c2: { // 0x5cd1c2: e8496becff CALL 0x493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6083015u); flags=s.arithmetic_flags;
  }
  L005cd1c7: { // 0x5cd1c7: 8b4634 MOV EAX, dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  L005cd1ca: { // 0x5cd1ca: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cd1cc: { // 0x5cd1cc: 7412 JZ 0x5cd1e0
    if(integer::condition("JZ",flags)) goto L005cd1e0;
  }
  L005cd1ce: { // 0x5cd1ce: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L005cd1d1: { // 0x5cd1d1: 83c004 ADD EAX, 4
    s.ax = integer::add(s.ax,4u,32,flags);
  }
  L005cd1d4: { // 0x5cd1d4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cd1d5: { // 0x5cd1d5: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6083032u); flags=s.arithmetic_flags;
  }
  L005cd1d8: { // 0x5cd1d8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cd1d9: { // 0x5cd1d9: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005cd1db: { // 0x5cd1db: e8306becff CALL 0x493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6083040u); flags=s.arithmetic_flags;
  }
  L005cd1e0: { // 0x5cd1e0: 8b466c MOV EAX, dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L005cd1e3: { // 0x5cd1e3: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005cd1e5: { // 0x5cd1e5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cd1e6: { // 0x5cd1e6: e8256becff CALL 0x493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6083051u); flags=s.arithmetic_flags;
  }
  L005cd1eb: { // 0x5cd1eb: 8a4e74 MOV CL, byte ptr [ESI + 0x74]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000074u)));
  }
  L005cd1ee: { // 0x5cd1ee: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cd1ef: { // 0x5cd1ef: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005cd1f1: { // 0x5cd1f1: e86a6aecff CALL 0x493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6083062u); flags=s.arithmetic_flags;
  }
  L005cd1f6: { // 0x5cd1f6: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L005cd1fb: { // 0x5cd1fb: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cd1fd: { // 0x5cd1fd: 7405 JZ 0x5cd204
    if(integer::condition("JZ",flags)) goto L005cd204;
  }
  L005cd1ff: { // 0x5cd1ff: 83f805 CMP EAX, 5
    (void)integer::sub(s.ax,5u,32,flags);
  }
  L005cd202: { // 0x5cd202: 7516 JNZ 0x5cd21a
    if(integer::condition("JNZ",flags)) goto L005cd21a;
  }
  L005cd204: { // 0x5cd204: 8a5675 MOV DL, byte ptr [ESI + 0x75]
    s.dx = with_al(s.dx, m.r8((s.si+0x00000075u)));
  }
  L005cd207: { // 0x5cd207: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005cd209: { // 0x5cd209: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005cd20a: { // 0x5cd20a: e8516aecff CALL 0x493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6083087u); flags=s.arithmetic_flags;
  }
  L005cd20f: { // 0x5cd20f: 8a4677 MOV AL, byte ptr [ESI + 0x77]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000077u)));
  }
  L005cd212: { // 0x5cd212: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005cd214: { // 0x5cd214: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cd215: { // 0x5cd215: e8466aecff CALL 0x493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6083098u); flags=s.arithmetic_flags;
  }
  L005cd21a: { // 0x5cd21a: 8a4e76 MOV CL, byte ptr [ESI + 0x76]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000076u)));
  }
  L005cd21d: { // 0x5cd21d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cd21e: { // 0x5cd21e: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005cd220: { // 0x5cd220: e83b6aecff CALL 0x493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6083109u); flags=s.arithmetic_flags;
  }
  L005cd225: { // 0x5cd225: 8a5678 MOV DL, byte ptr [ESI + 0x78]
    s.dx = with_al(s.dx, m.r8((s.si+0x00000078u)));
  }
  L005cd228: { // 0x5cd228: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005cd22a: { // 0x5cd22a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005cd22b: { // 0x5cd22b: e8306aecff CALL 0x493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6083120u); flags=s.arithmetic_flags;
  }
  L005cd230: { // 0x5cd230: 8a4679 MOV AL, byte ptr [ESI + 0x79]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000079u)));
  }
  L005cd233: { // 0x5cd233: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005cd235: { // 0x5cd235: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cd236: { // 0x5cd236: e8256aecff CALL 0x493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6083131u); flags=s.arithmetic_flags;
  }
  L005cd23b: { // 0x5cd23b: 8a4e7a MOV CL, byte ptr [ESI + 0x7a]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000007au)));
  }
  L005cd23e: { // 0x5cd23e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cd23f: { // 0x5cd23f: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005cd241: { // 0x5cd241: e81a6aecff CALL 0x493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6083142u); flags=s.arithmetic_flags;
  }
  L005cd246: { // 0x5cd246: 8a567c MOV DL, byte ptr [ESI + 0x7c]
    s.dx = with_al(s.dx, m.r8((s.si+0x0000007cu)));
  }
  L005cd249: { // 0x5cd249: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005cd24b: { // 0x5cd24b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005cd24c: { // 0x5cd24c: e80f6aecff CALL 0x493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6083153u); flags=s.arithmetic_flags;
  }
  L005cd251: { // 0x5cd251: 8a467d MOV AL, byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  L005cd254: { // 0x5cd254: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005cd256: { // 0x5cd256: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cd257: { // 0x5cd257: e8046aecff CALL 0x493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,6083164u); flags=s.arithmetic_flags;
  }
  L005cd25c: { // 0x5cd25c: 8b8e88000000 MOV ECX, dword ptr [ESI + 0x88]
    s.cx = m.r32((s.si+0x00000088u));
  }
  L005cd262: { // 0x5cd262: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cd263: { // 0x5cd263: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005cd265: { // 0x5cd265: e8a66aecff CALL 0x493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6083178u); flags=s.arithmetic_flags;
  }
  L005cd26a: { // 0x5cd26a: 8b968c000000 MOV EDX, dword ptr [ESI + 0x8c]
    s.dx = m.r32((s.si+0x0000008cu));
  }
  L005cd270: { // 0x5cd270: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005cd272: { // 0x5cd272: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005cd273: { // 0x5cd273: e8986aecff CALL 0x493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6083192u); flags=s.arithmetic_flags;
  }
  L005cd278: { // 0x5cd278: 8b8690000000 MOV EAX, dword ptr [ESI + 0x90]
    s.ax = m.r32((s.si+0x00000090u));
  }
  L005cd27e: { // 0x5cd27e: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005cd280: { // 0x5cd280: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cd281: { // 0x5cd281: e88a6aecff CALL 0x493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,6083206u); flags=s.arithmetic_flags;
  }
  L005cd286: { // 0x5cd286: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cd287: { // 0x5cd287: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cd288: { // 0x5cd288: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000101b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004101b0: { // 0x4101b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004101b1: { // 0x4101b1: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004101b3: { // 0x4101b3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004101b4: { // 0x4101b4: 8b7c240c MOV EDI, dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L004101b8: { // 0x4101b8: 8b4610 MOV EAX, dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L004101bb: { // 0x4101bb: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004101bd: { // 0x4101bd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004101be: { // 0x4101be: e84d3b0800 CALL 0x493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,4260291u); flags=s.arithmetic_flags;
  }
  L004101c3: { // 0x4101c3: 8a4e20 MOV CL, byte ptr [ESI + 0x20]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000020u)));
  }
  L004101c6: { // 0x4101c6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004101c7: { // 0x4101c7: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004101c9: { // 0x4101c9: e8923a0800 CALL 0x493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,4260302u); flags=s.arithmetic_flags;
  }
  L004101ce: { // 0x4101ce: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004101cf: { // 0x4101cf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004101d0: { // 0x4101d0: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4799760u:f_00093d10(m,s,child,{});break;
case 4799792u:f_00093d30(m,s,child,{});break;
case 4799824u:f_00093d50(m,s,child,{});break;
case 4799440u:f_00093bd0(m,s,child,{});break;
case 4799584u:f_00093c60(m,s,child,{});break;
case 4799904u:f_00093da0(m,s,child,{});break;
case 4800368u:f_00093f70(m,s,child,{});break;
case 6480272u:f_0022e190(m,s,child,{});break;
case 5840448u:f_00191e40(m,s,child,{});break;
case 6082976u:f_001cd1a0(m,s,child,{});break;
case 4260272u:f_000101b0(m,s,child,{});break;
default:throw std::domain_error("recovery769 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006cc010(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cc010: { // 0x6cc010: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cc011: { // 0x6cc011: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006cc012: { // 0x6cc012: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cc013: { // 0x6cc013: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cc014: { // 0x6cc014: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L006cc018: { // 0x6cc018: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006cc01a: { // 0x6cc01a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cc01b: { // 0x6cc01b: e87021f6ff CALL 0x0062e190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062e190u,7127072u); flags=s.arithmetic_flags;
  }
  L006cc020: { // 0x6cc020: 8b86ac010000 MOV EAX,dword ptr [ESI + 0x1ac]
    s.ax = m.r32((s.si+0x000001acu));
  }
  L006cc026: { // 0x6cc026: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc028: { // 0x6cc028: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc029: { // 0x6cc029: e8e27cdcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127086u); flags=s.arithmetic_flags;
  }
  L006cc02e: { // 0x6cc02e: 8b8e14010000 MOV ECX,dword ptr [ESI + 0x114]
    s.cx = m.r32((s.si+0x00000114u));
  }
  L006cc034: { // 0x6cc034: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cc035: { // 0x6cc035: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc037: { // 0x6cc037: e8d47cdcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127100u); flags=s.arithmetic_flags;
  }
  L006cc03c: { // 0x6cc03c: 8b9624010000 MOV EDX,dword ptr [ESI + 0x124]
    s.dx = m.r32((s.si+0x00000124u));
  }
  L006cc042: { // 0x6cc042: 8b8620010000 MOV EAX,dword ptr [ESI + 0x120]
    s.ax = m.r32((s.si+0x00000120u));
  }
  L006cc048: { // 0x6cc048: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006cc049: { // 0x6cc049: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc04a: { // 0x6cc04a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc04c: { // 0x6cc04c: e8ff7cdcff CALL 0x00493d50
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d50u,7127121u); flags=s.arithmetic_flags;
  }
  L006cc051: { // 0x6cc051: 8b8e2c010000 MOV ECX,dword ptr [ESI + 0x12c]
    s.cx = m.r32((s.si+0x0000012cu));
  }
  L006cc057: { // 0x6cc057: 8b9628010000 MOV EDX,dword ptr [ESI + 0x128]
    s.dx = m.r32((s.si+0x00000128u));
  }
  L006cc05d: { // 0x6cc05d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cc05e: { // 0x6cc05e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006cc05f: { // 0x6cc05f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc061: { // 0x6cc061: e8ea7cdcff CALL 0x00493d50
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d50u,7127142u); flags=s.arithmetic_flags;
  }
  L006cc066: { // 0x6cc066: 8b9630010000 MOV EDX,dword ptr [ESI + 0x130]
    s.dx = m.r32((s.si+0x00000130u));
  }
  L006cc06c: { // 0x6cc06c: 8b8638010000 MOV EAX,dword ptr [ESI + 0x138]
    s.ax = m.r32((s.si+0x00000138u));
  }
  L006cc072: { // 0x6cc072: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L006cc075: { // 0x6cc075: 7412 JZ 0x006cc089
    if(integer::condition("JZ",flags)) goto L006cc089;
  }
  L006cc077: { // 0x6cc077: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006cc07d: { // 0x6cc07d: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L006cc07f: { // 0x6cc07f: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006cc081: { // 0x6cc081: 7d04 JGE 0x006cc087
    if(integer::condition("JGE",flags)) goto L006cc087;
  }
  L006cc083: { // 0x6cc083: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006cc085: { // 0x6cc085: eb02 JMP 0x006cc089
    goto L006cc089;
  }
  L006cc087: { // 0x6cc087: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cc089: { // 0x6cc089: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc08a: { // 0x6cc08a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc08c: { // 0x6cc08c: e87f7cdcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127185u); flags=s.arithmetic_flags;
  }
  L006cc091: { // 0x6cc091: 8b86a8010000 MOV EAX,dword ptr [ESI + 0x1a8]
    s.ax = m.r32((s.si+0x000001a8u));
  }
  L006cc097: { // 0x6cc097: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc099: { // 0x6cc099: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc09a: { // 0x6cc09a: e8717cdcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127199u); flags=s.arithmetic_flags;
  }
  L006cc09f: { // 0x6cc09f: 8b8eb8010000 MOV ECX,dword ptr [ESI + 0x1b8]
    s.cx = m.r32((s.si+0x000001b8u));
  }
  L006cc0a5: { // 0x6cc0a5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cc0a6: { // 0x6cc0a6: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc0a8: { // 0x6cc0a8: e8637cdcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127213u); flags=s.arithmetic_flags;
  }
  L006cc0ad: { // 0x6cc0ad: 8b96d4010000 MOV EDX,dword ptr [ESI + 0x1d4]
    s.dx = m.r32((s.si+0x000001d4u));
  }
  L006cc0b3: { // 0x6cc0b3: 8b86dc010000 MOV EAX,dword ptr [ESI + 0x1dc]
    s.ax = m.r32((s.si+0x000001dcu));
  }
  L006cc0b9: { // 0x6cc0b9: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L006cc0bc: { // 0x6cc0bc: 7412 JZ 0x006cc0d0
    if(integer::condition("JZ",flags)) goto L006cc0d0;
  }
  L006cc0be: { // 0x6cc0be: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006cc0c4: { // 0x6cc0c4: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L006cc0c6: { // 0x6cc0c6: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006cc0c8: { // 0x6cc0c8: 7d04 JGE 0x006cc0ce
    if(integer::condition("JGE",flags)) goto L006cc0ce;
  }
  L006cc0ca: { // 0x6cc0ca: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006cc0cc: { // 0x6cc0cc: eb02 JMP 0x006cc0d0
    goto L006cc0d0;
  }
  L006cc0ce: { // 0x6cc0ce: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cc0d0: { // 0x6cc0d0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc0d1: { // 0x6cc0d1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc0d3: { // 0x6cc0d3: e8387cdcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127256u); flags=s.arithmetic_flags;
  }
  L006cc0d8: { // 0x6cc0d8: 8b96e0010000 MOV EDX,dword ptr [ESI + 0x1e0]
    s.dx = m.r32((s.si+0x000001e0u));
  }
  L006cc0de: { // 0x6cc0de: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc0e0: { // 0x6cc0e0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006cc0e1: { // 0x6cc0e1: e84a7cdcff CALL 0x00493d30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d30u,7127270u); flags=s.arithmetic_flags;
  }
  L006cc0e6: { // 0x6cc0e6: 8a86e4010000 MOV AL,byte ptr [ESI + 0x1e4]
    s.ax = with_al(s.ax, m.r8((s.si+0x000001e4u)));
  }
  L006cc0ec: { // 0x6cc0ec: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc0ee: { // 0x6cc0ee: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc0ef: { // 0x6cc0ef: e86c7bdcff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,7127284u); flags=s.arithmetic_flags;
  }
  L006cc0f4: { // 0x6cc0f4: 8b8ef4010000 MOV ECX,dword ptr [ESI + 0x1f4]
    s.cx = m.r32((s.si+0x000001f4u));
  }
  L006cc0fa: { // 0x6cc0fa: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cc0fb: { // 0x6cc0fb: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc0fd: { // 0x6cc0fd: e80e7cdcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127298u); flags=s.arithmetic_flags;
  }
  L006cc102: { // 0x6cc102: 8b9640020000 MOV EDX,dword ptr [ESI + 0x240]
    s.dx = m.r32((s.si+0x00000240u));
  }
  L006cc108: { // 0x6cc108: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc10a: { // 0x6cc10a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006cc10b: { // 0x6cc10b: e8207cdcff CALL 0x00493d30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d30u,7127312u); flags=s.arithmetic_flags;
  }
  L006cc110: { // 0x6cc110: 8b9644020000 MOV EDX,dword ptr [ESI + 0x244]
    s.dx = m.r32((s.si+0x00000244u));
  }
  L006cc116: { // 0x6cc116: 8b864c020000 MOV EAX,dword ptr [ESI + 0x24c]
    s.ax = m.r32((s.si+0x0000024cu));
  }
  L006cc11c: { // 0x6cc11c: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L006cc11f: { // 0x6cc11f: 7412 JZ 0x006cc133
    if(integer::condition("JZ",flags)) goto L006cc133;
  }
  L006cc121: { // 0x6cc121: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006cc127: { // 0x6cc127: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L006cc129: { // 0x6cc129: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006cc12b: { // 0x6cc12b: 7d04 JGE 0x006cc131
    if(integer::condition("JGE",flags)) goto L006cc131;
  }
  L006cc12d: { // 0x6cc12d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006cc12f: { // 0x6cc12f: eb02 JMP 0x006cc133
    goto L006cc133;
  }
  L006cc131: { // 0x6cc131: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cc133: { // 0x6cc133: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc134: { // 0x6cc134: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc136: { // 0x6cc136: e8d57bdcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127355u); flags=s.arithmetic_flags;
  }
  L006cc13b: { // 0x6cc13b: 8b8654020000 MOV EAX,dword ptr [ESI + 0x254]
    s.ax = m.r32((s.si+0x00000254u));
  }
  L006cc141: { // 0x6cc141: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc143: { // 0x6cc143: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc144: { // 0x6cc144: e8c77bdcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127369u); flags=s.arithmetic_flags;
  }
  L006cc149: { // 0x6cc149: 8b9694010000 MOV EDX,dword ptr [ESI + 0x194]
    s.dx = m.r32((s.si+0x00000194u));
  }
  L006cc14f: { // 0x6cc14f: 8b869c010000 MOV EAX,dword ptr [ESI + 0x19c]
    s.ax = m.r32((s.si+0x0000019cu));
  }
  L006cc155: { // 0x6cc155: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L006cc158: { // 0x6cc158: 7412 JZ 0x006cc16c
    if(integer::condition("JZ",flags)) goto L006cc16c;
  }
  L006cc15a: { // 0x6cc15a: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006cc160: { // 0x6cc160: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L006cc162: { // 0x6cc162: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006cc164: { // 0x6cc164: 7d04 JGE 0x006cc16a
    if(integer::condition("JGE",flags)) goto L006cc16a;
  }
  L006cc166: { // 0x6cc166: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006cc168: { // 0x6cc168: eb02 JMP 0x006cc16c
    goto L006cc16c;
  }
  L006cc16a: { // 0x6cc16a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cc16c: { // 0x6cc16c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc16d: { // 0x6cc16d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc16f: { // 0x6cc16f: e89c7bdcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127412u); flags=s.arithmetic_flags;
  }
  L006cc174: { // 0x6cc174: 8b8e58020000 MOV ECX,dword ptr [ESI + 0x258]
    s.cx = m.r32((s.si+0x00000258u));
  }
  L006cc17a: { // 0x6cc17a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cc17b: { // 0x6cc17b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc17d: { // 0x6cc17d: e88e7bdcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127426u); flags=s.arithmetic_flags;
  }
  L006cc182: { // 0x6cc182: 8b9680020000 MOV EDX,dword ptr [ESI + 0x280]
    s.dx = m.r32((s.si+0x00000280u));
  }
  L006cc188: { // 0x6cc188: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc18a: { // 0x6cc18a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006cc18b: { // 0x6cc18b: e8a07bdcff CALL 0x00493d30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d30u,7127440u); flags=s.arithmetic_flags;
  }
  L006cc190: { // 0x6cc190: 8b8684020000 MOV EAX,dword ptr [ESI + 0x284]
    s.ax = m.r32((s.si+0x00000284u));
  }
  L006cc196: { // 0x6cc196: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc198: { // 0x6cc198: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc199: { // 0x6cc199: e8927bdcff CALL 0x00493d30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d30u,7127454u); flags=s.arithmetic_flags;
  }
  L006cc19e: { // 0x6cc19e: 8b8e88020000 MOV ECX,dword ptr [ESI + 0x288]
    s.cx = m.r32((s.si+0x00000288u));
  }
  L006cc1a4: { // 0x6cc1a4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cc1a5: { // 0x6cc1a5: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc1a7: { // 0x6cc1a7: e8847bdcff CALL 0x00493d30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d30u,7127468u); flags=s.arithmetic_flags;
  }
  L006cc1ac: { // 0x6cc1ac: 8b968c020000 MOV EDX,dword ptr [ESI + 0x28c]
    s.dx = m.r32((s.si+0x0000028cu));
  }
  L006cc1b2: { // 0x6cc1b2: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc1b4: { // 0x6cc1b4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006cc1b5: { // 0x6cc1b5: e8767bdcff CALL 0x00493d30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d30u,7127482u); flags=s.arithmetic_flags;
  }
  L006cc1ba: { // 0x6cc1ba: 8a8625030000 MOV AL,byte ptr [ESI + 0x325]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000325u)));
  }
  L006cc1c0: { // 0x6cc1c0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc1c2: { // 0x6cc1c2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc1c3: { // 0x6cc1c3: e8987adcff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,7127496u); flags=s.arithmetic_flags;
  }
  L006cc1c8: { // 0x6cc1c8: 8a8e27030000 MOV CL,byte ptr [ESI + 0x327]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000327u)));
  }
  L006cc1ce: { // 0x6cc1ce: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cc1cf: { // 0x6cc1cf: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc1d1: { // 0x6cc1d1: e88a7adcff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,7127510u); flags=s.arithmetic_flags;
  }
  L006cc1d6: { // 0x6cc1d6: 8a9628030000 MOV DL,byte ptr [ESI + 0x328]
    s.dx = with_al(s.dx, m.r8((s.si+0x00000328u)));
  }
  L006cc1dc: { // 0x6cc1dc: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc1de: { // 0x6cc1de: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006cc1df: { // 0x6cc1df: e87c7adcff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,7127524u); flags=s.arithmetic_flags;
  }
  L006cc1e4: { // 0x6cc1e4: 8a8629030000 MOV AL,byte ptr [ESI + 0x329]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000329u)));
  }
  L006cc1ea: { // 0x6cc1ea: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc1ec: { // 0x6cc1ec: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc1ed: { // 0x6cc1ed: e86e7adcff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,7127538u); flags=s.arithmetic_flags;
  }
  L006cc1f2: { // 0x6cc1f2: 8a8e2a030000 MOV CL,byte ptr [ESI + 0x32a]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000032au)));
  }
  L006cc1f8: { // 0x6cc1f8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cc1f9: { // 0x6cc1f9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc1fb: { // 0x6cc1fb: e8607adcff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,7127552u); flags=s.arithmetic_flags;
  }
  L006cc200: { // 0x6cc200: 8a962b030000 MOV DL,byte ptr [ESI + 0x32b]
    s.dx = with_al(s.dx, m.r8((s.si+0x0000032bu)));
  }
  L006cc206: { // 0x6cc206: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc208: { // 0x6cc208: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006cc209: { // 0x6cc209: e8527adcff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,7127566u); flags=s.arithmetic_flags;
  }
  L006cc20e: { // 0x6cc20e: 8a862c030000 MOV AL,byte ptr [ESI + 0x32c]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000032cu)));
  }
  L006cc214: { // 0x6cc214: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc216: { // 0x6cc216: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc217: { // 0x6cc217: e8447adcff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,7127580u); flags=s.arithmetic_flags;
  }
  L006cc21c: { // 0x6cc21c: 8a8e2d030000 MOV CL,byte ptr [ESI + 0x32d]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000032du)));
  }
  L006cc222: { // 0x6cc222: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cc223: { // 0x6cc223: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc225: { // 0x6cc225: e8367adcff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,7127594u); flags=s.arithmetic_flags;
  }
  L006cc22a: { // 0x6cc22a: 8a9670030000 MOV DL,byte ptr [ESI + 0x370]
    s.dx = with_al(s.dx, m.r8((s.si+0x00000370u)));
  }
  L006cc230: { // 0x6cc230: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc232: { // 0x6cc232: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006cc233: { // 0x6cc233: e8287adcff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,7127608u); flags=s.arithmetic_flags;
  }
  L006cc238: { // 0x6cc238: 8a8671030000 MOV AL,byte ptr [ESI + 0x371]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000371u)));
  }
  L006cc23e: { // 0x6cc23e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc240: { // 0x6cc240: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc241: { // 0x6cc241: e81a7adcff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,7127622u); flags=s.arithmetic_flags;
  }
  L006cc246: { // 0x6cc246: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L006cc24b: { // 0x6cc24b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006cc24d: { // 0x6cc24d: 7405 JZ 0x006cc254
    if(integer::condition("JZ",flags)) goto L006cc254;
  }
  L006cc24f: { // 0x6cc24f: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L006cc252: { // 0x6cc252: 752a JNZ 0x006cc27e
    if(integer::condition("JNZ",flags)) goto L006cc27e;
  }
  L006cc254: { // 0x6cc254: 8a8e72030000 MOV CL,byte ptr [ESI + 0x372]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000372u)));
  }
  L006cc25a: { // 0x6cc25a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cc25b: { // 0x6cc25b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc25d: { // 0x6cc25d: e8fe79dcff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,7127650u); flags=s.arithmetic_flags;
  }
  L006cc262: { // 0x6cc262: 8a9673030000 MOV DL,byte ptr [ESI + 0x373]
    s.dx = with_al(s.dx, m.r8((s.si+0x00000373u)));
  }
  L006cc268: { // 0x6cc268: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc26a: { // 0x6cc26a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006cc26b: { // 0x6cc26b: e8f079dcff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,7127664u); flags=s.arithmetic_flags;
  }
  L006cc270: { // 0x6cc270: 8a8674030000 MOV AL,byte ptr [ESI + 0x374]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000374u)));
  }
  L006cc276: { // 0x6cc276: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc278: { // 0x6cc278: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc279: { // 0x6cc279: e8e279dcff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,7127678u); flags=s.arithmetic_flags;
  }
  L006cc27e: { // 0x6cc27e: 8a8e75030000 MOV CL,byte ptr [ESI + 0x375]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000375u)));
  }
  L006cc284: { // 0x6cc284: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cc285: { // 0x6cc285: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc287: { // 0x6cc287: e8d479dcff CALL 0x00493c60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493c60u,7127692u); flags=s.arithmetic_flags;
  }
  L006cc28c: { // 0x6cc28c: 8b96fc030000 MOV EDX,dword ptr [ESI + 0x3fc]
    s.dx = m.r32((s.si+0x000003fcu));
  }
  L006cc292: { // 0x6cc292: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc294: { // 0x6cc294: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006cc295: { // 0x6cc295: e8767adcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127706u); flags=s.arithmetic_flags;
  }
  L006cc29a: { // 0x6cc29a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cc29c: { // 0x6cc29c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc29e: { // 0x6cc29e: 8a8676030000 MOV AL,byte ptr [ESI + 0x376]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000376u)));
  }
  L006cc2a4: { // 0x6cc2a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc2a5: { // 0x6cc2a5: e8667adcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127722u); flags=s.arithmetic_flags;
  }
  L006cc2aa: { // 0x6cc2aa: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006cc2ac: { // 0x6cc2ac: 8a8e77030000 MOV CL,byte ptr [ESI + 0x377]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000377u)));
  }
  L006cc2b2: { // 0x6cc2b2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cc2b3: { // 0x6cc2b3: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc2b5: { // 0x6cc2b5: e8567adcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127738u); flags=s.arithmetic_flags;
  }
  L006cc2ba: { // 0x6cc2ba: 8a9678030000 MOV DL,byte ptr [ESI + 0x378]
    s.dx = with_al(s.dx, m.r8((s.si+0x00000378u)));
  }
  L006cc2c0: { // 0x6cc2c0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc2c2: { // 0x6cc2c2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006cc2c3: { // 0x6cc2c3: e80879dcff CALL 0x00493bd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493bd0u,7127752u); flags=s.arithmetic_flags;
  }
  L006cc2c8: { // 0x6cc2c8: 8baeb8030000 MOV EBP,dword ptr [ESI + 0x3b8]
    s.bp = m.r32((s.si+0x000003b8u));
  }
  L006cc2ce: { // 0x6cc2ce: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc2d0: { // 0x6cc2d0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006cc2d1: { // 0x6cc2d1: e83a7adcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127766u); flags=s.arithmetic_flags;
  }
  L006cc2d6: { // 0x6cc2d6: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006cc2d8: { // 0x6cc2d8: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L006cc2da: { // 0x6cc2da: 7e38 JLE 0x006cc314
    if(integer::condition("JLE",flags)) goto L006cc314;
  }
  L006cc2dc: { // 0x6cc2dc: 8b86ac030000 MOV EAX,dword ptr [ESI + 0x3ac]
    s.ax = m.r32((s.si+0x000003acu));
  }
  L006cc2e2: { // 0x6cc2e2: 8b8e94030000 MOV ECX,dword ptr [ESI + 0x394]
    s.cx = m.r32((s.si+0x00000394u));
  }
  L006cc2e8: { // 0x6cc2e8: 8b0498 MOV EAX,dword ptr [EAX + EBX*0x4]
    s.ax = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L006cc2eb: { // 0x6cc2eb: 8b1499 MOV EDX,dword ptr [ECX + EBX*0x4]
    s.dx = m.r32((s.cx+(s.bx * 0x00000004u)));
  }
  L006cc2ee: { // 0x6cc2ee: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L006cc2f1: { // 0x6cc2f1: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L006cc2f5: { // 0x6cc2f5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc2f6: { // 0x6cc2f6: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006cc2f8: { // 0x6cc2f8: ff5110 CALL dword ptr [ECX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000010u)),7127803u); flags=s.arithmetic_flags;
  }
  L006cc2fb: { // 0x6cc2fb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc2fc: { // 0x6cc2fc: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc2fe: { // 0x6cc2fe: e80d7adcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127811u); flags=s.arithmetic_flags;
  }
  L006cc303: { // 0x6cc303: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L006cc307: { // 0x6cc307: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc309: { // 0x6cc309: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006cc30a: { // 0x6cc30a: e8017adcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127823u); flags=s.arithmetic_flags;
  }
  L006cc30f: { // 0x6cc30f: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006cc310: { // 0x6cc310: 3bdd CMP EBX,EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L006cc312: { // 0x6cc312: 7cc8 JL 0x006cc2dc
    if(integer::condition("JL",flags)) goto L006cc2dc;
  }
  L006cc314: { // 0x6cc314: 8baed0030000 MOV EBP,dword ptr [ESI + 0x3d0]
    s.bp = m.r32((s.si+0x000003d0u));
  }
  L006cc31a: { // 0x6cc31a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc31c: { // 0x6cc31c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006cc31d: { // 0x6cc31d: e8ee79dcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127842u); flags=s.arithmetic_flags;
  }
  L006cc322: { // 0x6cc322: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006cc324: { // 0x6cc324: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L006cc326: { // 0x6cc326: 7e1f JLE 0x006cc347
    if(integer::condition("JLE",flags)) goto L006cc347;
  }
  L006cc328: { // 0x6cc328: 8b86c4030000 MOV EAX,dword ptr [ESI + 0x3c4]
    s.ax = m.r32((s.si+0x000003c4u));
  }
  L006cc32e: { // 0x6cc32e: 8b0498 MOV EAX,dword ptr [EAX + EBX*0x4]
    s.ax = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L006cc331: { // 0x6cc331: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L006cc334: { // 0x6cc334: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc335: { // 0x6cc335: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006cc337: { // 0x6cc337: ff5110 CALL dword ptr [ECX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000010u)),7127866u); flags=s.arithmetic_flags;
  }
  L006cc33a: { // 0x6cc33a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cc33b: { // 0x6cc33b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cc33d: { // 0x6cc33d: e8ce79dcff CALL 0x00493d10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493d10u,7127874u); flags=s.arithmetic_flags;
  }
  L006cc342: { // 0x6cc342: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006cc343: { // 0x6cc343: 3bdd CMP EBX,EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L006cc345: { // 0x6cc345: 7ce1 JL 0x006cc328
    if(integer::condition("JL",flags)) goto L006cc328;
  }
  L006cc347: { // 0x6cc347: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cc348: { // 0x6cc348: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cc349: { // 0x6cc349: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006cc34a: { // 0x6cc34a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006cc34b: { // 0x6cc34b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
