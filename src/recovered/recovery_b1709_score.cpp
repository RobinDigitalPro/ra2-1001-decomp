// Private selected score projection. No compiler/runtime qualification.
#include "recovery_b1709_child.hpp"
#include "recovery_b1707.hpp"
#include <stdexcept>
#include <type_traits>
namespace ra2::recovered::recovery_b1709 {
namespace {
using namespace recovery_b566;
namespace integer=direct_b33::integer;
static_assert(std::is_same_v<State,recovery_b1707::State>);
static_assert(std::is_same_v<Frame,recovery_b1707::Frame>);
static_assert(std::is_same_v<Memory,recovery_b1707::Memory>);
void finite(bool actual,bool expected,const char*pc){if(actual!=expected)throw std::domain_error(pc);}
void invoke(Memory&,State&,Frame&,U,U);
void f_002c4be0(Memory&,State&,Frame&);
void f_002c4f40(Memory&,State&,Frame&);
void f_002c50d0(Memory&,State&,Frame&);
void f_002c5310(Memory&,State&,Frame&);
void f_0001b320(Memory&,State&,Frame&);
void f_00145500(Memory&,State&,Frame&);
void f_000798c0(Memory&,State&,Frame&);

void f_002c4be0(Memory& m,State& s,Frame& f) {
  U flags=s.arithmetic_flags;
  L006c4be0: { // 0x6c4be0: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L006c4be3: { // 0x6c4be3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c4be4: { // 0x6c4be4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006c4be5: { // 0x6c4be5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c4be6: { // 0x6c4be6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c4be7: { // 0x6c4be7: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L006c4be9: { // 0x6c4be9: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L006c4bed: { // 0x6c4bed: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006c4bef: { // 0x6c4bef: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006c4bf0: { // 0x6c4bf0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006c4bf2: { // 0x6c4bf2: ff90a0010000 CALL dword ptr [EAX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a0u)),7097336u); flags=s.arithmetic_flags;
  }
  L006c4bf8: { // 0x6c4bf8: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006c4bfa: { // 0x6c4bfa: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L006c4bfe: { // 0x6c4bfe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c4bff: { // 0x6c4bff: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c4c04: { // 0x6c4c04: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L006c4c08: { // 0x6c4c08: e8f308e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7097357u); flags=s.arithmetic_flags;
  }
  L006c4c0d: { // 0x6c4c0d: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006c4c0f: { // 0x6c4c0f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006c4c11: { // 0x6c4c11: 0f8463010000 JZ 0x006c4d7a
    finite(integer::condition("JZ",flags),false,"score finite branch 006C4C11");
  }
  L006c4c17: { // 0x6c4c17: 8a4779 MOV AL,byte ptr [EDI + 0x79]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000079u)));
  }
  L006c4c1a: { // 0x6c4c1a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c4c1c: { // 0x6c4c1c: 0f8558010000 JNZ 0x006c4d7a
    finite(integer::condition("JNZ",flags),false,"score finite branch 006C4C1C");
  }
  L006c4c22: { // 0x6c4c22: 66a1b29d8300 MOV AX,[0x00839db2]
    s.ax = with_ax(s.ax, m.r16((0x00839db2u)));
  }
  L006c4c28: { // 0x6c4c28: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L006c4c2c: { // 0x6c4c2c: 8b15b09d8300 MOV EDX,dword ptr [0x00839db0]
    s.dx = m.r32((0x00839db0u));
  }
  L006c4c32: { // 0x6c4c32: 6603442412 ADD AX,word ptr [ESP + 0x12]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L006c4c37: { // 0x6c4c37: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L006c4c39: { // 0x6c4c39: 6689542414 MOV word ptr [ESP + 0x14],DX
    m.w16((f.sp+0x00000014u), (s.dx & 0xffffu));
  }
  L006c4c3e: { // 0x6c4c3e: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L006c4c43: { // 0x6c4c43: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L006c4c47: { // 0x6c4c47: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L006c4c4b: { // 0x6c4c4b: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L006c4c4f: { // 0x6c4c4f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006c4c50: { // 0x6c4c50: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c4c55: { // 0x6c4c55: e8a608e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7097434u); flags=s.arithmetic_flags;
  }
  L006c4c5a: { // 0x6c4c5a: 8b0da09d8300 MOV ECX,dword ptr [0x00839da0]
    s.cx = m.r32((0x00839da0u));
  }
  L006c4c60: { // 0x6c4c60: 668b15a29d8300 MOV DX,word ptr [0x00839da2]
    s.dx = with_ax(s.dx, m.r16((0x00839da2u)));
  }
  L006c4c67: { // 0x6c4c67: 6603542412 ADD DX,word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L006c4c6c: { // 0x6c4c6c: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006c4c6e: { // 0x6c4c6e: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L006c4c72: { // 0x6c4c72: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006c4c74: { // 0x6c4c74: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L006c4c79: { // 0x6c4c79: 66894c2414 MOV word ptr [ESP + 0x14],CX
    m.w16((f.sp+0x00000014u), (s.cx & 0xffffu));
  }
  L006c4c7e: { // 0x6c4c7e: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006c4c82: { // 0x6c4c82: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L006c4c86: { // 0x6c4c86: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L006c4c8a: { // 0x6c4c8a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006c4c8b: { // 0x6c4c8b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c4c90: { // 0x6c4c90: e86b08e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7097493u); flags=s.arithmetic_flags;
  }
  L006c4c95: { // 0x6c4c95: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L006c4c99: { // 0x6c4c99: 668b0daa9d8300 MOV CX,word ptr [0x00839daa]
    s.cx = with_ax(s.cx, m.r16((0x00839daau)));
  }
  L006c4ca0: { // 0x6c4ca0: 66034c2412 ADD CX,word ptr [ESP + 0x12]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L006c4ca5: { // 0x6c4ca5: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L006c4ca7: { // 0x6c4ca7: a1a89d8300 MOV EAX,[0x00839da8]
    s.ax = m.r32((0x00839da8u));
  }
  L006c4cac: { // 0x6c4cac: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006c4cae: { // 0x6c4cae: 66894c2416 MOV word ptr [ESP + 0x16],CX
    m.w16((f.sp+0x00000016u), (s.cx & 0xffffu));
  }
  L006c4cb3: { // 0x6c4cb3: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L006c4cb8: { // 0x6c4cb8: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L006c4cbc: { // 0x6c4cbc: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L006c4cc0: { // 0x6c4cc0: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c4cc5: { // 0x6c4cc5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c4cc6: { // 0x6c4cc6: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L006c4cca: { // 0x6c4cca: e83108e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7097551u); flags=s.arithmetic_flags;
  }
  L006c4ccf: { // 0x6c4ccf: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L006c4cd3: { // 0x6c4cd3: 8b15b89d8300 MOV EDX,dword ptr [0x00839db8]
    s.dx = m.r32((0x00839db8u));
  }
  L006c4cd9: { // 0x6c4cd9: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L006c4cdb: { // 0x6c4cdb: 66a1ba9d8300 MOV AX,[0x00839dba]
    s.ax = with_ax(s.ax, m.r16((0x00839dbau)));
  }
  L006c4ce1: { // 0x6c4ce1: 6603442412 ADD AX,word ptr [ESP + 0x12]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L006c4ce6: { // 0x6c4ce6: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L006c4ce8: { // 0x6c4ce8: 6689542414 MOV word ptr [ESP + 0x14],DX
    m.w16((f.sp+0x00000014u), (s.dx & 0xffffu));
  }
  L006c4ced: { // 0x6c4ced: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L006c4cf1: { // 0x6c4cf1: 6689442416 MOV word ptr [ESP + 0x16],AX
    m.w16((f.sp+0x00000016u), (s.ax & 0xffffu));
  }
  L006c4cf6: { // 0x6c4cf6: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L006c4cfa: { // 0x6c4cfa: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L006c4cfe: { // 0x6c4cfe: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006c4cff: { // 0x6c4cff: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c4d04: { // 0x6c4d04: e8f707e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7097609u); flags=s.arithmetic_flags;
  }
  L006c4d09: { // 0x6c4d09: 8b8e40010000 MOV ECX,dword ptr [ESI + 0x140]
    s.cx = m.r32((s.si+0x00000140u));
  }
  L006c4d0f: { // 0x6c4d0f: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L006c4d12: { // 0x6c4d12: 755c JNZ 0x006c4d70
    finite(integer::condition("JNZ",flags),true,"score finite branch 006C4D12"); goto L006c4d70;
  }
  L006c4d70: { // 0x6c4d70: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c4d71: { // 0x6c4d71: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c4d72: { // 0x6c4d72: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c4d73: { // 0x6c4d73: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006c4d75: { // 0x6c4d75: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c4d76: { // 0x6c4d76: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006c4d79: { // 0x6c4d79: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_002c4f40(Memory& m,State& s,Frame& f) {
  U flags=s.arithmetic_flags;
  L006c4f40: { // 0x6c4f40: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L006c4f43: { // 0x6c4f43: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c4f44: { // 0x6c4f44: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c4f45: { // 0x6c4f45: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006c4f47: { // 0x6c4f47: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c4f48: { // 0x6c4f48: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L006c4f4c: { // 0x6c4f4c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c4f4e: { // 0x6c4f4e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006c4f4f: { // 0x6c4f4f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c4f51: { // 0x6c4f51: ff90a0010000 CALL dword ptr [EAX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a0u)),7098199u); flags=s.arithmetic_flags;
  }
  L006c4f57: { // 0x6c4f57: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006c4f59: { // 0x6c4f59: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L006c4f5d: { // 0x6c4f5d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c4f5e: { // 0x6c4f5e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c4f63: { // 0x6c4f63: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L006c4f67: { // 0x6c4f67: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006c4f69: { // 0x6c4f69: e89205e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7098222u); flags=s.arithmetic_flags;
  }
  L006c4f6e: { // 0x6c4f6e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c4f70: { // 0x6c4f70: 0f8442010000 JZ 0x006c50b8
    finite(integer::condition("JZ",flags),false,"score finite branch 006C4F70");
  }
  L006c4f76: { // 0x6c4f76: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c4f78: { // 0x6c4f78: e863fcffff CALL 0x006c4be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006c4be0u,7098237u); flags=s.arithmetic_flags;
  }
  L006c4f7d: { // 0x6c4f7d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c4f7f: { // 0x6c4f7f: 750f JNZ 0x006c4f90
    finite(integer::condition("JNZ",flags),true,"score finite branch 006C4F7F"); goto L006c4f90;
  }
  L006c4f90: { // 0x6c4f90: 66a1b29d8300 MOV AX,[0x00839db2]
    s.ax = with_ax(s.ax, m.r16((0x00839db2u)));
  }
  L006c4f96: { // 0x6c4f96: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L006c4f9a: { // 0x6c4f9a: 8b15b09d8300 MOV EDX,dword ptr [0x00839db0]
    s.dx = m.r32((0x00839db0u));
  }
  L006c4fa0: { // 0x6c4fa0: 660344240e ADD AX,word ptr [ESP + 0xe]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x0000000eu)),16,flags));
  }
  L006c4fa5: { // 0x6c4fa5: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L006c4fa7: { // 0x6c4fa7: 6689542410 MOV word ptr [ESP + 0x10],DX
    m.w16((f.sp+0x00000010u), (s.dx & 0xffffu));
  }
  L006c4fac: { // 0x6c4fac: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L006c4fb1: { // 0x6c4fb1: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L006c4fb5: { // 0x6c4fb5: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L006c4fb9: { // 0x6c4fb9: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L006c4fbd: { // 0x6c4fbd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006c4fbe: { // 0x6c4fbe: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c4fc3: { // 0x6c4fc3: e83805e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7098312u); flags=s.arithmetic_flags;
  }
  L006c4fc8: { // 0x6c4fc8: 8b0da89d8300 MOV ECX,dword ptr [0x00839da8]
    s.cx = m.r32((0x00839da8u));
  }
  L006c4fce: { // 0x6c4fce: 668b15aa9d8300 MOV DX,word ptr [0x00839daa]
    s.dx = with_ax(s.dx, m.r16((0x00839daau)));
  }
  L006c4fd5: { // 0x6c4fd5: 660354240e ADD DX,word ptr [ESP + 0xe]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x0000000eu)),16,flags));
  }
  L006c4fda: { // 0x6c4fda: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006c4fdc: { // 0x6c4fdc: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L006c4fe0: { // 0x6c4fe0: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006c4fe2: { // 0x6c4fe2: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L006c4fe7: { // 0x6c4fe7: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L006c4fec: { // 0x6c4fec: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L006c4ff0: { // 0x6c4ff0: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L006c4ff4: { // 0x6c4ff4: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006c4ff8: { // 0x6c4ff8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006c4ff9: { // 0x6c4ff9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c4ffe: { // 0x6c4ffe: e8fd04e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7098371u); flags=s.arithmetic_flags;
  }
  L006c5003: { // 0x6c5003: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L006c5007: { // 0x6c5007: 668b0dae9d8300 MOV CX,word ptr [0x00839dae]
    s.cx = with_ax(s.cx, m.r16((0x00839daeu)));
  }
  L006c500e: { // 0x6c500e: 66034c240e ADD CX,word ptr [ESP + 0xe]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x0000000eu)),16,flags));
  }
  L006c5013: { // 0x6c5013: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006c5015: { // 0x6c5015: a1ac9d8300 MOV EAX,[0x00839dac]
    s.ax = m.r32((0x00839dacu));
  }
  L006c501a: { // 0x6c501a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006c501c: { // 0x6c501c: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L006c5021: { // 0x6c5021: 6689442410 MOV word ptr [ESP + 0x10],AX
    m.w16((f.sp+0x00000010u), (s.ax & 0xffffu));
  }
  L006c5026: { // 0x6c5026: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L006c502a: { // 0x6c502a: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L006c502e: { // 0x6c502e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c5033: { // 0x6c5033: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c5034: { // 0x6c5034: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L006c5038: { // 0x6c5038: e8c304e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7098429u); flags=s.arithmetic_flags;
  }
  L006c503d: { // 0x6c503d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006c503f: { // 0x6c503f: 7477 JZ 0x006c50b8
    finite(integer::condition("JZ",flags),false,"score finite branch 006C503F");
  }
  L006c5041: { // 0x6c5041: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006c5043: { // 0x6c5043: 7473 JZ 0x006c50b8
    finite(integer::condition("JZ",flags),false,"score finite branch 006C5043");
  }
  L006c5045: { // 0x6c5045: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c5047: { // 0x6c5047: 746f JZ 0x006c50b8
    finite(integer::condition("JZ",flags),false,"score finite branch 006C5047");
  }
  L006c5049: { // 0x6c5049: 8b4e38 MOV ECX,dword ptr [ESI + 0x38]
    s.cx = m.r32((s.si+0x00000038u));
  }
  L006c504c: { // 0x6c504c: 8b15b0a8a300 MOV EDX,dword ptr [0x00a3a8b0]
    s.dx = m.r32((0x00a3a8b0u));
  }
  L006c5052: { // 0x6c5052: 81f9ffff0000 CMP ECX,0xffff
    (void)integer::sub(s.cx,0x0000ffffu,32,flags);
  }
  L006c5058: { // 0x6c5058: 741a JZ 0x006c5074
    finite(integer::condition("JZ",flags),false,"score finite branch 006C5058");
  }
  L006c505a: { // 0x6c505a: 81f9ff000000 CMP ECX,0xff
    (void)integer::sub(s.cx,0x000000ffu,32,flags);
  }
  L006c5060: { // 0x6c5060: 7412 JZ 0x006c5074
    finite(integer::condition("JZ",flags),false,"score finite branch 006C5060");
  }
  L006c5062: { // 0x6c5062: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L006c5064: { // 0x6c5064: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006c5065: { // 0x6c5065: 83f907 CMP ECX,0x7
    (void)integer::sub(s.cx,0x00000007u,32,flags);
  }
  L006c5068: { // 0x6c5068: 7c0a JL 0x006c5074
    finite(integer::condition("JL",flags),false,"score finite branch 006C5068");
  }
  L006c506a: { // 0x6c506a: 83f910 CMP ECX,0x10
    (void)integer::sub(s.cx,0x00000010u,32,flags);
  }
  L006c506d: { // 0x6c506d: 7f05 JG 0x006c5074
    finite(integer::condition("JG",flags),false,"score finite branch 006C506D");
  }
  L006c506f: { // 0x6c506f: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L006c5074: { // 0x6c5074: 8b4f38 MOV ECX,dword ptr [EDI + 0x38]
    s.cx = m.r32((s.di+0x00000038u));
  }
  L006c5077: { // 0x6c5077: 81f9ffff0000 CMP ECX,0xffff
    (void)integer::sub(s.cx,0x0000ffffu,32,flags);
  }
  L006c507d: { // 0x6c507d: 741a JZ 0x006c5099
    finite(integer::condition("JZ",flags),false,"score finite branch 006C507D");
  }
  L006c507f: { // 0x6c507f: 81f9ff000000 CMP ECX,0xff
    (void)integer::sub(s.cx,0x000000ffu,32,flags);
  }
  L006c5085: { // 0x6c5085: 7412 JZ 0x006c5099
    finite(integer::condition("JZ",flags),false,"score finite branch 006C5085");
  }
  L006c5087: { // 0x6c5087: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L006c5089: { // 0x6c5089: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006c508a: { // 0x6c508a: 83f907 CMP ECX,0x7
    (void)integer::sub(s.cx,0x00000007u,32,flags);
  }
  L006c508d: { // 0x6c508d: 7c0a JL 0x006c5099
    finite(integer::condition("JL",flags),false,"score finite branch 006C508D");
  }
  L006c508f: { // 0x6c508f: 83f910 CMP ECX,0x10
    (void)integer::sub(s.cx,0x00000010u,32,flags);
  }
  L006c5092: { // 0x6c5092: 7f05 JG 0x006c5099
    finite(integer::condition("JG",flags),false,"score finite branch 006C5092");
  }
  L006c5094: { // 0x6c5094: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L006c5099: { // 0x6c5099: 8b4038 MOV EAX,dword ptr [EAX + 0x38]
    s.ax = m.r32((s.ax+0x00000038u));
  }
  L006c509c: { // 0x6c509c: 3dffff0000 CMP EAX,0xffff
    (void)integer::sub(s.ax,0x0000ffffu,32,flags);
  }
  L006c50a1: { // 0x6c50a1: 7415 JZ 0x006c50b8
    finite(integer::condition("JZ",flags),false,"score finite branch 006C50A1");
  }
  L006c50a3: { // 0x6c50a3: 3dff000000 CMP EAX,0xff
    (void)integer::sub(s.ax,0x000000ffu,32,flags);
  }
  L006c50a8: { // 0x6c50a8: 740e JZ 0x006c50b8
    finite(integer::condition("JZ",flags),false,"score finite branch 006C50A8");
  }
  L006c50aa: { // 0x6c50aa: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006c50ac: { // 0x6c50ac: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006c50ad: { // 0x6c50ad: 83f807 CMP EAX,0x7
    (void)integer::sub(s.ax,0x00000007u,32,flags);
  }
  L006c50b0: { // 0x6c50b0: 7c06 JL 0x006c50b8
    finite(integer::condition("JL",flags),false,"score finite branch 006C50B0");
  }
  L006c50b2: { // 0x6c50b2: 83f810 CMP EAX,0x10
    (void)integer::sub(s.ax,0x00000010u,32,flags);
  }
  L006c50b5: { // 0x6c50b5: 7f01 JG 0x006c50b8
    finite(integer::condition("JG",flags),false,"score finite branch 006C50B5");
  }
  L006c50b7: { // 0x6c50b7: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006c50b8: { // 0x6c50b8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c50b9: { // 0x6c50b9: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L006c50bb: { // 0x6c50bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c50bc: { // 0x6c50bc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c50bd: { // 0x6c50bd: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L006c50c0: { // 0x6c50c0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_002c50d0(Memory& m,State& s,Frame& f) {
  U flags=s.arithmetic_flags;
  L006c50d0: { // 0x6c50d0: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L006c50d3: { // 0x6c50d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c50d4: { // 0x6c50d4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006c50d5: { // 0x6c50d5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c50d6: { // 0x6c50d6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006c50d8: { // 0x6c50d8: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L006c50dc: { // 0x6c50dc: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c50dd: { // 0x6c50dd: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c50df: { // 0x6c50df: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006c50e0: { // 0x6c50e0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c50e2: { // 0x6c50e2: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L006c50ea: { // 0x6c50ea: ff90a0010000 CALL dword ptr [EAX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a0u)),7098608u); flags=s.arithmetic_flags;
  }
  L006c50f0: { // 0x6c50f0: 8a4e79 MOV CL,byte ptr [ESI + 0x79]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000079u)));
  }
  L006c50f3: { // 0x6c50f3: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006c50f5: { // 0x6c50f5: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c50f7: { // 0x6c50f7: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006c50fb: { // 0x6c50fb: 0f85ff010000 JNZ 0x006c5300
    finite(integer::condition("JNZ",flags),false,"score finite branch 006C50FB");
  }
  L006c5101: { // 0x6c5101: 8b15a09d8300 MOV EDX,dword ptr [0x00839da0]
    s.dx = m.r32((0x00839da0u));
  }
  L006c5107: { // 0x6c5107: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006c5109: { // 0x6c5109: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L006c510d: { // 0x6c510d: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L006c5112: { // 0x6c5112: 66a1a29d8300 MOV AX,[0x00839da2]
    s.ax = with_ax(s.ax, m.r16((0x00839da2u)));
  }
  L006c5118: { // 0x6c5118: 6603442412 ADD AX,word ptr [ESP + 0x12]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L006c511d: { // 0x6c511d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006c511e: { // 0x6c511e: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L006c5123: { // 0x6c5123: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L006c5127: { // 0x6c5127: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L006c512b: { // 0x6c512b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c5130: { // 0x6c5130: e8cb03e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7098677u); flags=s.arithmetic_flags;
  }
  L006c5135: { // 0x6c5135: 668b15ba9d8300 MOV DX,word ptr [0x00839dba]
    s.dx = with_ax(s.dx, m.r16((0x00839dbau)));
  }
  L006c513c: { // 0x6c513c: 8b0db89d8300 MOV ECX,dword ptr [0x00839db8]
    s.cx = m.r32((0x00839db8u));
  }
  L006c5142: { // 0x6c5142: 6603542412 ADD DX,word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L006c5147: { // 0x6c5147: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006c5149: { // 0x6c5149: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L006c514d: { // 0x6c514d: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006c514f: { // 0x6c514f: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L006c5153: { // 0x6c5153: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L006c5158: { // 0x6c5158: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L006c515d: { // 0x6c515d: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006c5161: { // 0x6c5161: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006c5162: { // 0x6c5162: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c5167: { // 0x6c5167: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L006c516b: { // 0x6c516b: e89003e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7098736u); flags=s.arithmetic_flags;
  }
  L006c5170: { // 0x6c5170: 8b35507caa00 MOV ESI,dword ptr [0x00aa7c50]
    s.si = m.r32((0x00aa7c50u));
  }
  L006c5176: { // 0x6c5176: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L006c517a: { // 0x6c517a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006c517b: { // 0x6c517b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c5180: { // 0x6c5180: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L006c5182: { // 0x6c5182: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L006c5186: { // 0x6c5186: e87503e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7098763u); flags=s.arithmetic_flags;
  }
  L006c518b: { // 0x6c518b: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006c518d: { // 0x6c518d: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L006c518f: { // 0x6c518f: 0f846b010000 JZ 0x006c5300
    finite(integer::condition("JZ",flags),false,"score finite branch 006C518F");
  }
  L006c5195: { // 0x6c5195: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006c5197: { // 0x6c5197: 0f8463010000 JZ 0x006c5300
    finite(integer::condition("JZ",flags),false,"score finite branch 006C5197");
  }
  L006c519d: { // 0x6c519d: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006c519f: { // 0x6c519f: e81c47dbff CALL 0x004798c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004798c0u,7098788u); flags=s.arithmetic_flags;
  }
  L006c51a4: { // 0x6c51a4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c51a6: { // 0x6c51a6: 7405 JZ 0x006c51ad
    finite(integer::condition("JZ",flags),false,"score finite branch 006C51A6");
  }
  L006c51a8: { // 0x6c51a8: 8b7524 MOV ESI,dword ptr [EBP + 0x24]
    s.si = m.r32((s.bp+0x00000024u));
  }
  L006c51ab: { // 0x6c51ab: eb1e JMP 0x006c51cb
    goto L006c51cb;
  }
  L006c51cb: { // 0x6c51cb: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L006c51cf: { // 0x6c51cf: 663b35507caa00 CMP SI,word ptr [0x00aa7c50]
    (void)integer::sub((s.si & 0xffffu),m.r16((0x00aa7c50u)),16,flags);
  }
  L006c51d6: { // 0x6c51d6: 668b7c2416 MOV DI,word ptr [ESP + 0x16]
    s.di = (s.di & 0xffff0000u) | ((m.r16((f.sp+0x00000016u))) & 0xffffu);
  }
  L006c51db: { // 0x6c51db: 750d JNZ 0x006c51ea
    finite(integer::condition("JNZ",flags),true,"score finite branch 006C51DB"); goto L006c51ea;
  }
  L006c51ea: { // 0x6c51ea: a1a09d8300 MOV EAX,[0x00839da0]
    s.ax = m.r32((0x00839da0u));
  }
  L006c51ef: { // 0x6c51ef: 668bcf MOV CX,DI
    s.cx = with_ax(s.cx, (s.di & 0xffffu));
  }
  L006c51f2: { // 0x6c51f2: 66030da29d8300 ADD CX,word ptr [0x00839da2]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((0x00839da2u)),16,flags));
  }
  L006c51f9: { // 0x6c51f9: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L006c51fb: { // 0x6c51fb: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L006c5200: { // 0x6c5200: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L006c5204: { // 0x6c5204: 66894c2416 MOV word ptr [ESP + 0x16],CX
    m.w16((f.sp+0x00000016u), (s.cx & 0xffffu));
  }
  L006c5209: { // 0x6c5209: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L006c520d: { // 0x6c520d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c520e: { // 0x6c520e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c5213: { // 0x6c5213: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L006c5217: { // 0x6c5217: e8e402e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7098908u); flags=s.arithmetic_flags;
  }
  L006c521c: { // 0x6c521c: 8b0db89d8300 MOV ECX,dword ptr [0x00839db8]
    s.cx = m.r32((0x00839db8u));
  }
  L006c5222: { // 0x6c5222: 66033dba9d8300 ADD DI,word ptr [0x00839dba]
    s.di = (s.di & 0xffff0000u) | ((integer::add((s.di & 0xffffu),m.r16((0x00839dbau)),16,flags)) & 0xffffu);
  }
  L006c5229: { // 0x6c5229: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L006c522b: { // 0x6c522b: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L006c522d: { // 0x6c522d: 66894c2414 MOV word ptr [ESP + 0x14],CX
    m.w16((f.sp+0x00000014u), (s.cx & 0xffffu));
  }
  L006c5232: { // 0x6c5232: 66897c2416 MOV word ptr [ESP + 0x16],DI
    m.w16((f.sp+0x00000016u), (s.di & 0xffffu));
  }
  L006c5237: { // 0x6c5237: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L006c523b: { // 0x6c523b: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L006c523f: { // 0x6c523f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c5240: { // 0x6c5240: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c5245: { // 0x6c5245: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L006c5249: { // 0x6c5249: e8b202e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7098958u); flags=s.arithmetic_flags;
  }
  L006c524e: { // 0x6c524e: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006c5250: { // 0x6c5250: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006c5252: { // 0x6c5252: 0f84a8000000 JZ 0x006c5300
    finite(integer::condition("JZ",flags),false,"score finite branch 006C5252");
  }
  L006c5258: { // 0x6c5258: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006c525a: { // 0x6c525a: 0f84a0000000 JZ 0x006c5300
    finite(integer::condition("JZ",flags),false,"score finite branch 006C525A");
  }
  L006c5260: { // 0x6c5260: 8b5b24 MOV EBX,dword ptr [EBX + 0x24]
    s.bx = m.r32((s.bx+0x00000024u));
  }
  L006c5263: { // 0x6c5263: 8b0da09d8300 MOV ECX,dword ptr [0x00839da0]
    s.cx = m.r32((0x00839da0u));
  }
  L006c5269: { // 0x6c5269: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L006c526d: { // 0x6c526d: 668b542422 MOV DX,word ptr [ESP + 0x22]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000022u)));
  }
  L006c5272: { // 0x6c5272: 660315a29d8300 ADD DX,word ptr [0x00839da2]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((0x00839da2u)),16,flags));
  }
  L006c5279: { // 0x6c5279: 03d9 ADD EBX,ECX
    s.bx = integer::add(s.bx,s.cx,32,flags);
  }
  L006c527b: { // 0x6c527b: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L006c527f: { // 0x6c527f: 66895c2414 MOV word ptr [ESP + 0x14],BX
    m.w16((f.sp+0x00000014u), (s.bx & 0xffffu));
  }
  L006c5284: { // 0x6c5284: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L006c5289: { // 0x6c5289: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006c528d: { // 0x6c528d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006c528e: { // 0x6c528e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c5293: { // 0x6c5293: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L006c5297: { // 0x6c5297: e86402e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7099036u); flags=s.arithmetic_flags;
  }
  L006c529c: { // 0x6c529c: 8b15b89d8300 MOV EDX,dword ptr [0x00839db8]
    s.dx = m.r32((0x00839db8u));
  }
  L006c52a2: { // 0x6c52a2: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006c52a4: { // 0x6c52a4: 8b4624 MOV EAX,dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  L006c52a7: { // 0x6c52a7: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L006c52ab: { // 0x6c52ab: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006c52ad: { // 0x6c52ad: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L006c52b2: { // 0x6c52b2: 668b442422 MOV AX,word ptr [ESP + 0x22]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000022u)));
  }
  L006c52b7: { // 0x6c52b7: 660305ba9d8300 ADD AX,word ptr [0x00839dba]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((0x00839dbau)),16,flags));
  }
  L006c52be: { // 0x6c52be: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L006c52c2: { // 0x6c52c2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006c52c3: { // 0x6c52c3: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L006c52c8: { // 0x6c52c8: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L006c52cc: { // 0x6c52cc: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L006c52d0: { // 0x6c52d0: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c52d5: { // 0x6c52d5: e82602e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7099098u); flags=s.arithmetic_flags;
  }
  L006c52da: { // 0x6c52da: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006c52dc: { // 0x6c52dc: 7422 JZ 0x006c5300
    finite(integer::condition("JZ",flags),false,"score finite branch 006C52DC");
  }
  L006c52de: { // 0x6c52de: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c52e0: { // 0x6c52e0: 741e JZ 0x006c5300
    finite(integer::condition("JZ",flags),false,"score finite branch 006C52E0");
  }
  L006c52e2: { // 0x6c52e2: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006c52e4: { // 0x6c52e4: e8d745dbff CALL 0x004798c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004798c0u,7099113u); flags=s.arithmetic_flags;
  }
  L006c52e9: { // 0x6c52e9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c52eb: { // 0x6c52eb: 750b JNZ 0x006c52f8
    finite(integer::condition("JNZ",flags),true,"score finite branch 006C52EB"); goto L006c52f8;
  }
  L006c52f8: { // 0x6c52f8: c744241801000000 MOV dword ptr [ESP + 0x18],0x1
    m.w32((f.sp+0x00000018u), 0x00000001u);
  }
  L006c5300: { // 0x6c5300: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L006c5304: { // 0x6c5304: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c5305: { // 0x6c5305: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c5306: { // 0x6c5306: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006c5307: { // 0x6c5307: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c5308: { // 0x6c5308: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006c530b: { // 0x6c530b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_002c5310(Memory& m,State& s,Frame& f) {
  U flags=s.arithmetic_flags;
  L006c5310: { // 0x6c5310: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L006c5313: { // 0x6c5313: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c5314: { // 0x6c5314: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c5315: { // 0x6c5315: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006c5317: { // 0x6c5317: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c5318: { // 0x6c5318: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L006c531c: { // 0x6c531c: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006c531e: { // 0x6c531e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c5320: { // 0x6c5320: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006c5321: { // 0x6c5321: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c5323: { // 0x6c5323: ff90a0010000 CALL dword ptr [EAX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a0u)),7099177u); flags=s.arithmetic_flags;
  }
  L006c5329: { // 0x6c5329: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006c532b: { // 0x6c532b: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L006c532f: { // 0x6c532f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c5330: { // 0x6c5330: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c5335: { // 0x6c5335: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L006c5339: { // 0x6c5339: e8c201e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7099198u); flags=s.arithmetic_flags;
  }
  L006c533e: { // 0x6c533e: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006c5340: { // 0x6c5340: 8a4679 MOV AL,byte ptr [ESI + 0x79]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000079u)));
  }
  L006c5343: { // 0x6c5343: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c5345: { // 0x6c5345: 0f85bc000000 JNZ 0x006c5407
    finite(integer::condition("JNZ",flags),false,"score finite branch 006C5345");
  }
  L006c534b: { // 0x6c534b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c534d: { // 0x6c534d: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L006c5351: { // 0x6c5351: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006c5352: { // 0x6c5352: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c5354: { // 0x6c5354: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),7099226u); flags=s.arithmetic_flags;
  }
  L006c535a: { // 0x6c535a: 668b08 MOV CX,word ptr [EAX]
    s.cx = with_ax(s.cx, m.r16((s.ax)));
  }
  L006c535d: { // 0x6c535d: 668b5002 MOV DX,word ptr [EAX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x00000002u)));
  }
  L006c5361: { // 0x6c5361: 66030dac9d8300 ADD CX,word ptr [0x00839dac]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((0x00839dacu)),16,flags));
  }
  L006c5368: { // 0x6c5368: 660315ae9d8300 ADD DX,word ptr [0x00839dae]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((0x00839daeu)),16,flags));
  }
  L006c536f: { // 0x6c536f: 66894c240c MOV word ptr [ESP + 0xc],CX
    m.w16((f.sp+0x0000000cu), (s.cx & 0xffffu));
  }
  L006c5374: { // 0x6c5374: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L006c5378: { // 0x6c5378: 668954240e MOV word ptr [ESP + 0xe],DX
    m.w16((f.sp+0x0000000eu), (s.dx & 0xffffu));
  }
  L006c537d: { // 0x6c537d: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L006c5381: { // 0x6c5381: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006c5382: { // 0x6c5382: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c5387: { // 0x6c5387: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006c538b: { // 0x6c538b: e87001e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7099280u); flags=s.arithmetic_flags;
  }
  L006c5390: { // 0x6c5390: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c5392: { // 0x6c5392: 7473 JZ 0x006c5407
    finite(integer::condition("JZ",flags),false,"score finite branch 006C5392");
  }
  L006c5394: { // 0x6c5394: 0fbe901b010000 MOVSX EDX,byte ptr [EAX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L006c539b: { // 0x6c539b: 0fbe8f1b010000 MOVSX ECX,byte ptr [EDI + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.di+0x0000011bu)),8));
  }
  L006c53a2: { // 0x6c53a2: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L006c53a4: { // 0x6c53a4: 83fa04 CMP EDX,0x4
    (void)integer::sub(s.dx,0x00000004u,32,flags);
  }
  L006c53a7: { // 0x6c53a7: 7c05 JL 0x006c53ae
    finite(integer::condition("JL",flags),false,"score finite branch 006C53A7");
  }
  L006c53a9: { // 0x6c53a9: bb02000000 MOV EBX,0x2
    s.bx = 0x00000002u;
  }
  L006c53ae: { // 0x6c53ae: 8b4024 MOV EAX,dword ptr [EAX + 0x24]
    s.ax = m.r32((s.ax+0x00000024u));
  }
  L006c53b1: { // 0x6c53b1: 8b15ac9d8300 MOV EDX,dword ptr [0x00839dac]
    s.dx = m.r32((0x00839dacu));
  }
  L006c53b7: { // 0x6c53b7: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006c53bb: { // 0x6c53bb: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L006c53bd: { // 0x6c53bd: 66a1ae9d8300 MOV AX,[0x00839dae]
    s.ax = with_ax(s.ax, m.r16((0x00839daeu)));
  }
  L006c53c3: { // 0x6c53c3: 668954240c MOV word ptr [ESP + 0xc],DX
    m.w16((f.sp+0x0000000cu), (s.dx & 0xffffu));
  }
  L006c53c8: { // 0x6c53c8: 6603442416 ADD AX,word ptr [ESP + 0x16]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000016u)),16,flags));
  }
  L006c53cd: { // 0x6c53cd: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L006c53d1: { // 0x6c53d1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006c53d2: { // 0x6c53d2: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L006c53d7: { // 0x6c53d7: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L006c53db: { // 0x6c53db: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L006c53df: { // 0x6c53df: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006c53e4: { // 0x6c53e4: e81701e8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7099369u); flags=s.arithmetic_flags;
  }
  L006c53e9: { // 0x6c53e9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c53eb: { // 0x6c53eb: 741a JZ 0x006c5407
    finite(integer::condition("JZ",flags),false,"score finite branch 006C53EB");
  }
  L006c53ed: { // 0x6c53ed: 0fbe801b010000 MOVSX EAX,byte ptr [EAX + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L006c53f4: { // 0x6c53f4: 0fbe8f1b010000 MOVSX ECX,byte ptr [EDI + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.di+0x0000011bu)),8));
  }
  L006c53fb: { // 0x6c53fb: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006c53fd: { // 0x6c53fd: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L006c5400: { // 0x6c5400: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L006c5405: { // 0x6c5405: 7d02 JGE 0x006c5409
    finite(integer::condition("JGE",flags),false,"score finite branch 006C5405");
  }
  L006c5407: { // 0x6c5407: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L006c5409: { // 0x6c5409: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c540a: { // 0x6c540a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c540b: { // 0x6c540b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c540c: { // 0x6c540c: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L006c540f: { // 0x6c540f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0001b320(Memory& m,State& s,Frame& f) {
  U flags=s.arithmetic_flags;
  L0041b320: { // 0x41b320: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0041b321: { // 0x41b321: 8b8188000000 MOV EAX,dword ptr [ECX + 0x88]
    s.ax = m.r32((s.cx+0x00000088u));
  }
  L0041b327: { // 0x41b327: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041b328: { // 0x41b328: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041b32e: { // 0x41b32e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041b330: { // 0x41b330: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041b333: { // 0x41b333: 6689442400 MOV word ptr [ESP],AX
    m.w16((f.sp), (s.ax & 0xffffu));
  }
  L0041b338: { // 0x41b338: 8b818c000000 MOV EAX,dword ptr [ECX + 0x8c]
    s.ax = m.r32((s.cx+0x0000008cu));
  }
  L0041b33e: { // 0x41b33e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041b33f: { // 0x41b33f: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041b345: { // 0x41b345: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041b347: { // 0x41b347: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041b34a: { // 0x41b34a: 6689442402 MOV word ptr [ESP + 0x2],AX
    m.w16((f.sp+0x00000002u), (s.ax & 0xffffu));
  }
  L0041b34f: { // 0x41b34f: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0041b353: { // 0x41b353: 8b4c2400 MOV ECX,dword ptr [ESP]
    s.cx = m.r32((f.sp));
  }
  L0041b357: { // 0x41b357: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0041b359: { // 0x41b359: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0041b35a: { // 0x41b35a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00145500(Memory& m,State& s,Frame& f) {
  U flags=s.arithmetic_flags;
  L00545500: { // 0x545500: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI,word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x00545528
    finite(integer::condition("JS",flags),false,"score finite branch 00545512");
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x00545528
    finite(integer::condition("JGE",flags),false,"score finite branch 00545519");
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x00545535
    finite(integer::condition("JNZ",flags),true,"score finite branch 00545526"); goto L00545535;
  }
  L00545535: { // 0x545535: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_000798c0(Memory& m,State& s,Frame& f) {
  U flags=s.arithmetic_flags;
  L004798c0: { // 0x4798c0: 668b8116010000 MOV AX,word ptr [ECX + 0x116]
    s.ax = with_ax(s.ax, m.r16((s.cx+0x00000116u)));
  }
  L004798c7: { // 0x4798c7: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L004798ca: { // 0x4798ca: 7c1c JL 0x004798e8
    finite(integer::condition("JL",flags),false,"score finite branch 004798CA");
  }
  L004798cc: { // 0x4798cc: 8b1508e58400 MOV EDX,dword ptr [0x0084e508]
    s.dx = m.r32((0x0084e508u));
  }
  L004798d2: { // 0x4798d2: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004798d5: { // 0x4798d5: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004798d7: { // 0x4798d7: 7d0f JGE 0x004798e8
    finite(integer::condition("JGE",flags),false,"score finite branch 004798D7");
  }
  L004798d9: { // 0x4798d9: 83b9ec0000000a CMP dword ptr [ECX + 0xec],0xa
    (void)integer::sub(m.r32((s.cx+0x000000ecu)),0x0000000au,32,flags);
  }
  L004798e0: { // 0x4798e0: 7506 JNZ 0x004798e8
    finite(integer::condition("JNZ",flags),false,"score finite branch 004798E0");
  }
  L004798e2: { // 0x4798e2: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L004798e7: { // 0x4798e7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void type_getter(Memory&m,State&s,Frame&f){
 // 6B6910 8B01 MOV EAX,[ECX]
 s.ax=m.r32(s.cx);
 // 6B6912 FFA084000000 JMP DWORD[EAX+84]
 if(m.r32(s.ax+0x84u)!=0x006f9c70u)throw std::domain_error("score normal Unit84 target");
 // 6F9C70 8B81AC050000 MOV EAX,[ECX+5AC]
 s.ax=m.r32(s.cx+0x5acu);
 // 6F9C76 C3 RET0
 recovery_b566::finish(m,s,f,0);
}
void invoke(Memory&m,State&s,Frame&caller,U target,U continuation){
 caller.push(m,continuation);Frame child{caller.sp,caller.sp,continuation};
 switch(target){
 case 0x006b6910u:type_getter(m,s,child);break;
 case 0x0041b320u:f_0001b320(m,s,child);break;
 case 0x00545500u:f_00145500(m,s,child);break;
 case 0x004798c0u:f_000798c0(m,s,child);break;
 case 0x006c4be0u:f_002c4be0(m,s,child);break;
 case 0x006c4f40u:f_002c4f40(m,s,child);break;
 case 0x006c50d0u:f_002c50d0(m,s,child);break;
 case 0x006c5310u:f_002c5310(m,s,child);break;
 case 0x006c5410u:recovery_b1707::execute_selected(m,s,child);break;
 default:throw std::domain_error("score unsupported actual target");
 }
 caller.sp=child.sp;
}
} // private
void execute_score(Memory&m,State&s,Frame&f){
 U flags=s.arithmetic_flags;

 L004c9530: { // 0x4c9530: 83ec08 SUB esp, 8
  f.sp=integer::sub(f.sp,8u,32,flags);
 }

 L004c9533: { // 0x4c9533: 56 PUSH esi
  f.push(m,s.si);
 }

 L004c9534: { // 0x4c9534: 8bf1 MOV esi, ecx
  s.si=s.cx;
 }

 L004c9536: { // 0x4c9536: 57 PUSH edi
  f.push(m,s.di);
 }

 L004c9537: { // 0x4c9537: c744240800000000 MOV dword ptr [esp + 8], 0
  m.w32(f.sp+8u,0u);
 }

 L004c953f: { // 0x4c953f: 8b8664050000 MOV eax, dword ptr [esi + 0x564]
  s.ax=m.r32(s.si+0x564u);
 }

 L004c9545: { // 0x4c9545: 85c0 TEST eax, eax
  (void)integer::logical(s.ax&s.ax,32,flags);
 }

 L004c9547: { // 0x4c9547: 741e JE 0x4c9567
  finite(integer::condition("JZ",flags),true,"score Unit564zero"); goto L004c9567;
 }

 L004c9567: { // 0x4c9567: 8b16 MOV edx, dword ptr [esi]
  s.dx=m.r32(s.si);
 }

 L004c9569: { // 0x4c9569: 53 PUSH ebx
  f.push(m,s.bx);
 }

 L004c956a: { // 0x4c956a: 55 PUSH ebp
  f.push(m,s.bp);
 }

 L004c956b: { // 0x4c956b: 8bce MOV ecx, esi
  s.cx=s.si;
 }

 L004c956d: { // 0x4c956d: ff9280000000 CALL dword ptr [edx + 0x80]
  s.arithmetic_flags=flags;invoke(m,s,f,m.r32(s.dx+0x80u),0x4c9573u);flags=s.arithmetic_flags;
 }

 L004c9573: { // 0x4c9573: 8bce MOV ecx, esi
  s.cx=s.si;
 }

 L004c9575: { // 0x4c9575: 8bf8 MOV edi, eax
  s.di=s.ax;
 }

 L004c9577: { // 0x4c9577: e8c4b91f00 CALL 0x6c4f40
  s.arithmetic_flags=flags;invoke(m,s,f,0x6c4f40u,0x4c957cu);flags=s.arithmetic_flags;
 }

 L004c957c: { // 0x4c957c: 8bbf600b0000 MOV edi, dword ptr [edi + 0xb60]
  s.di=m.r32(s.di+0xb60u);
 }

 L004c9582: { // 0x4c9582: 8bce MOV ecx, esi
  s.cx=s.si;
 }

 L004c9584: { // 0x4c9584: 0faff8 IMUL edi, eax
  s.di=integer::imul(s.di,s.ax,32,flags);
 }

 L004c9587: { // 0x4c9587: 8b06 MOV eax, dword ptr [esi]
  s.ax=m.r32(s.si);
 }

 L004c9589: { // 0x4c9589: ff9080000000 CALL dword ptr [eax + 0x80]
  s.arithmetic_flags=flags;invoke(m,s,f,m.r32(s.ax+0x80u),0x4c958fu);flags=s.arithmetic_flags;
 }

 L004c958f: { // 0x4c958f: 8bce MOV ecx, esi
  s.cx=s.si;
 }

 L004c9591: { // 0x4c9591: 8bd8 MOV ebx, eax
  s.bx=s.ax;
 }

 L004c9593: { // 0x4c9593: e838bb1f00 CALL 0x6c50d0
  s.arithmetic_flags=flags;invoke(m,s,f,0x6c50d0u,0x4c9598u);flags=s.arithmetic_flags;
 }

 L004c9598: { // 0x4c9598: 8b9b640b0000 MOV ebx, dword ptr [ebx + 0xb64]
  s.bx=m.r32(s.bx+0xb64u);
 }

 L004c959e: { // 0x4c959e: 8b16 MOV edx, dword ptr [esi]
  s.dx=m.r32(s.si);
 }

 L004c95a0: { // 0x4c95a0: 8bce MOV ecx, esi
  s.cx=s.si;
 }

 L004c95a2: { // 0x4c95a2: 0fafd8 IMUL ebx, eax
  s.bx=integer::imul(s.bx,s.ax,32,flags);
 }

 L004c95a5: { // 0x4c95a5: ff9280000000 CALL dword ptr [edx + 0x80]
  s.arithmetic_flags=flags;invoke(m,s,f,m.r32(s.dx+0x80u),0x4c95abu);flags=s.arithmetic_flags;
 }

 L004c95ab: { // 0x4c95ab: 8bce MOV ecx, esi
  s.cx=s.si;
 }

 L004c95ad: { // 0x4c95ad: 8be8 MOV ebp, eax
  s.bp=s.ax;
 }

 L004c95af: { // 0x4c95af: e85cbd1f00 CALL 0x6c5310
  s.arithmetic_flags=flags;invoke(m,s,f,0x6c5310u,0x4c95b4u);flags=s.arithmetic_flags;
 }

 L004c95b4: { // 0x4c95b4: 8bad5c0b0000 MOV ebp, dword ptr [ebp + 0xb5c]
  s.bp=m.r32(s.bp+0xb5cu);
 }

 L004c95ba: { // 0x4c95ba: 8bce MOV ecx, esi
  s.cx=s.si;
 }

 L004c95bc: { // 0x4c95bc: 0fafe8 IMUL ebp, eax
  s.bp=integer::imul(s.bp,s.ax,32,flags);
 }

 L004c95bf: { // 0x4c95bf: c744241400000000 MOV dword ptr [esp + 0x14], 0
  m.w32(f.sp+0x14u,0u);
 }

 L004c95c7: { // 0x4c95c7: e814b61f00 CALL 0x6c4be0
  s.arithmetic_flags=flags;invoke(m,s,f,0x6c4be0u,0x4c95ccu);flags=s.arithmetic_flags;
 }

 L004c95cc: { // 0x4c95cc: 84c0 TEST al, al
  (void)integer::logical((s.ax&255u)&(s.ax&255u),8,flags);
 }

 L004c95ce: { // 0x4c95ce: 7412 JE 0x4c95e2
  finite(integer::condition("JZ",flags),false,"score genuine eligibility AL");
 }

 L004c95d0: { // 0x4c95d0: 8b06 MOV eax, dword ptr [esi]
  s.ax=m.r32(s.si);
 }

 L004c95d2: { // 0x4c95d2: 8bce MOV ecx, esi
  s.cx=s.si;
 }

 L004c95d4: { // 0x4c95d4: ff9080000000 CALL dword ptr [eax + 0x80]
  s.arithmetic_flags=flags;invoke(m,s,f,m.r32(s.ax+0x80u),0x4c95dau);flags=s.arithmetic_flags;
 }

 L004c95da: { // 0x4c95da: 8b80680b0000 MOV eax, dword ptr [eax + 0xb68]
  s.ax=m.r32(s.ax+0xb68u);
 }

 L004c95e0: { // 0x4c95e0: eb04 JMP 0x4c95e6
  goto L004c95e6;
 }

 L004c95e6: { // 0x4c95e6: 3bfb CMP edi, ebx
  (void)integer::sub(s.di,s.bx,32,flags);
 }

 L004c95e8: { // 0x4c95e8: 7f02 JG 0x4c95ec
  finite(integer::condition("JG",flags),false,"score signed max first");
 }

 L004c95ea: { // 0x4c95ea: 8bfb MOV edi, ebx
  s.di=s.bx;
 }

 L004c95ec: { // 0x4c95ec: 3bfd CMP edi, ebp
  (void)integer::sub(s.di,s.bp,32,flags);
 }

 L004c95ee: { // 0x4c95ee: 7f02 JG 0x4c95f2
  finite(integer::condition("JG",flags),false,"score signed max second");
 }

 L004c95f0: { // 0x4c95f0: 8bfd MOV edi, ebp
  s.di=s.bp;
 }

 L004c95f2: { // 0x4c95f2: 5d POP ebp
  s.bp=f.pop(m);
 }

 L004c95f3: { // 0x4c95f3: 3bf8 CMP edi, eax
  (void)integer::sub(s.di,s.ax,32,flags);
 }

 L004c95f5: { // 0x4c95f5: 5b POP ebx
  s.bx=f.pop(m);
 }

 L004c95f6: { // 0x4c95f6: 7f02 JG 0x4c95fa
  finite(integer::condition("JG",flags),false,"score signed max third");
 }

 L004c95f8: { // 0x4c95f8: 8bf8 MOV edi, eax
  s.di=s.ax;
 }

 L004c95fa: { // 0x4c95fa: 8bce MOV ecx, esi
  s.cx=s.si;
 }

 L004c95fc: { // 0x4c95fc: e80fbe1f00 CALL 0x6c5410
  s.arithmetic_flags=flags;invoke(m,s,f,0x6c5410u,0x4c9601u);flags=s.arithmetic_flags;
 }

 L004c9601: { // 0x4c9601: 8b4c2408 MOV ecx, dword ptr [esp + 8]
  s.cx=m.r32(f.sp+8u);
 }

 L004c9605: { // 0x4c9605: 03c7 ADD eax, edi
  s.ax=integer::add(s.ax,s.di,32,flags);
 }

 L004c9607: { // 0x4c9607: 5f POP edi
  s.di=f.pop(m);
 }

 L004c9608: { // 0x4c9608: 03c1 ADD eax, ecx
  s.ax=integer::add(s.ax,s.cx,32,flags);
 }

 L004c960a: { // 0x4c960a: 5e POP esi
  s.si=f.pop(m);
 }

 L004c960b: { // 0x4c960b: 83c408 ADD esp, 8
  f.sp=integer::add(f.sp,8u,32,flags);
 }

 L004c960e: { // 0x4c960e: c3 RET 
  s.arithmetic_flags=flags;recovery_b566::finish(m,s,f,0u);return;
 }

}
} // ra2::recovered::recovery_b1709
