#include "recovered/direct_b33_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::direct_b33 {
namespace {
void f_002e76a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e76a0: a1ec8baa00 MOV EAX,[0x00aa8bec]
    s.ax = m.r32((0x00aa8becu));
  }
  { // 0x6e76a5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e76a7: 7515 JNZ 0x006e76be
    if(integer::condition("JNZ",flags)) goto L006e76be;
  }
  { // 0x6e76a9: 8b0d681f7e00 MOV ECX,dword ptr [0x007e1f68]
    s.cx = m.r32((0x007e1f68u));
  }
  { // 0x6e76af: 68ec8baa00 PUSH 0xaa8bec
    f.push(m,0x00aa8becu);
  }
  { // 0x6e76b4: bae88baa00 MOV EDX,0xaa8be8
    s.dx = 0x00aa8be8u;
  }
  { // 0x6e76b9: e8c2f9ffff CALL 0x006e7080
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L006e76be: { // 0x6e76be: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e8a50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e8a50: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x6e8a53: a1488caa00 MOV EAX,[0x00aa8c48]
    s.ax = m.r32((0x00aa8c48u));
  }
  { // 0x6e8a58: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8a59: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6e8a5b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e8a5c: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  { // 0x6e8a60: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  { // 0x6e8a64: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  { // 0x6e8a66: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8a67: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  { // 0x6e8a6b: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  { // 0x6e8a6e: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  { // 0x6e8a72: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e8a74: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e8a75: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8a76: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8a77: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  { // 0x6e8a7c: a1f48aaa00 MOV EAX,[0x00aa8af4]
    s.ax = m.r32((0x00aa8af4u));
  }
  { // 0x6e8a81: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8a82: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8a83: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8a84: 6800040000 PUSH 0x400
    f.push(m,0x00000400u);
  }
  { // 0x6e8a89: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6e8a8a: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  { // 0x6e8a8e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6e8a8f: 8b15188caa00 MOV EDX,dword ptr [0x00aa8c18]
    s.dx = m.r32((0x00aa8c18u));
  }
  { // 0x6e8a95: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8a96: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e8a97: e83461dbff CALL 0x0049ebd0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6e8a9c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e8a9d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e8a9e: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6e8aa1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e8ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e8ab0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x6e8ab3: a1548caa00 MOV EAX,[0x00aa8c54]
    s.ax = m.r32((0x00aa8c54u));
  }
  { // 0x6e8ab8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8ab9: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6e8abb: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e8abc: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  { // 0x6e8ac0: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  { // 0x6e8ac4: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  { // 0x6e8ac6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8ac7: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  { // 0x6e8acb: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  { // 0x6e8ace: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  { // 0x6e8ad2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e8ad4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e8ad5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8ad6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8ad7: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  { // 0x6e8adc: a18c8baa00 MOV EAX,[0x00aa8b8c]
    s.ax = m.r32((0x00aa8b8cu));
  }
  { // 0x6e8ae1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8ae2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8ae3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8ae4: 6800040000 PUSH 0x400
    f.push(m,0x00000400u);
  }
  { // 0x6e8ae9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6e8aea: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  { // 0x6e8aee: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6e8aef: 8b15188caa00 MOV EDX,dword ptr [0x00aa8c18]
    s.dx = m.r32((0x00aa8c18u));
  }
  { // 0x6e8af5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6e8af7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e8af8: e8d360dbff CALL 0x0049ebd0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6e8afd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e8afe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e8aff: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6e8b02: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e8b10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e8b10: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x6e8b13: a1508caa00 MOV EAX,[0x00aa8c50]
    s.ax = m.r32((0x00aa8c50u));
  }
  { // 0x6e8b18: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8b19: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6e8b1b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e8b1c: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  { // 0x6e8b20: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  { // 0x6e8b24: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  { // 0x6e8b26: 897c2408 MOV dword ptr [ESP + 0x8],EDI
    m.w32((f.sp+0x00000008u), s.di);
  }
  { // 0x6e8b2a: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  { // 0x6e8b2d: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  { // 0x6e8b31: a110a78300 MOV EAX,[0x0083a710]
    s.ax = m.r32((0x0083a710u));
  }
  { // 0x6e8b36: 3d20030000 CMP EAX,0x320
    (void)integer::sub(s.ax,0x00000320u,32,flags);
  }
  { // 0x6e8b3b: 7c09 JL 0x006e8b46
    if(integer::condition("JL",flags)) goto L006e8b46;
  }
  { // 0x6e8b3d: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x6e8b3f: 83c050 ADD EAX,0x50
    s.ax = integer::add(s.ax,0x00000050u,32,flags);
  }
  { // 0x6e8b42: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L006e8b46: { // 0x6e8b46: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e8b48: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8b49: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e8b4a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8b4b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8b4c: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  { // 0x6e8b51: a1948baa00 MOV EAX,[0x00aa8b94]
    s.ax = m.r32((0x00aa8b94u));
  }
  { // 0x6e8b56: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8b57: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8b58: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8b59: 6800040000 PUSH 0x400
    f.push(m,0x00000400u);
  }
  { // 0x6e8b5e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6e8b5f: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  { // 0x6e8b63: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6e8b64: 8b15f48baa00 MOV EDX,dword ptr [0x00aa8bf4]
    s.dx = m.r32((0x00aa8bf4u));
  }
  { // 0x6e8b6a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8b6b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e8b6c: e85f60dbff CALL 0x0049ebd0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6e8b71: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e8b72: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e8b73: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6e8b76: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002ea8d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ea8d0: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  { // 0x6ea8d3: 7505 JNZ 0x006ea8da
    if(integer::condition("JNZ",flags)) goto L006ea8da;
  }
  { // 0x6ea8d5: baf0000000 MOV EDX,0xf0
    s.dx = 0x000000f0u;
  }
  L006ea8da: { // 0x6ea8da: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ea8db: 8b35e4e0a100 MOV ESI,dword ptr [0x00a1e0e4]
    s.si = m.r32((0x00a1e0e4u));
  }
  { // 0x6ea8e1: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6ea8e3: b803000000 MOV EAX,0x3
    s.ax = 0x00000003u;
  }
  { // 0x6ea8e8: 7406 JZ 0x006ea8f0
    if(integer::condition("JZ",flags)) goto L006ea8f0;
  }
  { // 0x6ea8ea: 8b86405f0100 MOV EAX,dword ptr [ESI + 0x15f40]
    s.ax = m.r32((s.si+0x00015f40u));
  }
  L006ea8f0: { // 0x6ea8f0: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6ea8f2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6ea8f3: 6846400000 PUSH 0x4046
    f.push(m,0x00004046u);
  }
  { // 0x6ea8f8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6ea8f9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6ea8fa: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6ea8fc: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6ea8fe: b9a05fa200 MOV ECX,0xa25fa0
    s.cx = 0x00a25fa0u;
  }
  { // 0x6ea903: e87870ecff CALL 0x005b1980
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6ea908: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ea909: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002eb320(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6eb320: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x6eb322: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6eb327: e83415dbff CALL 0x0049c860
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6eb32c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002eb5b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6eb5b0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6eb5b2: 6a4d PUSH 0x4d
    f.push(m,0x0000004du);
  }
  { // 0x6eb5b4: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6eb5b9: e8a209ebff CALL 0x0059bf60
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6eb5be: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002eb5c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6eb5c0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6eb5c2: 6a4c PUSH 0x4c
    f.push(m,0x0000004cu);
  }
  { // 0x6eb5c4: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6eb5c9: e89209ebff CALL 0x0059bf60
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6eb5ce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002ebe30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ebe30: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6ebe32: 7433 JZ 0x006ebe67
    if(integer::condition("JZ",flags)) goto L006ebe67;
  }
  { // 0x6ebe34: 8a417d MOV AL,byte ptr [ECX + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.cx+0x0000007du)));
  }
  { // 0x6ebe37: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ebe39: 742c JZ 0x006ebe67
    if(integer::condition("JZ",flags)) goto L006ebe67;
  }
  { // 0x6ebe3b: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  { // 0x6ebe40: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6ebe42: 750e JNZ 0x006ebe52
    if(integer::condition("JNZ",flags)) goto L006ebe52;
  }
  { // 0x6ebe44: 8b81b4010000 MOV EAX,dword ptr [ECX + 0x1b4]
    s.ax = m.r32((s.cx+0x000001b4u));
  }
  { // 0x6ebe4a: 8a8035010000 MOV AL,byte ptr [EAX + 0x135]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000135u)));
  }
  { // 0x6ebe50: eb0b JMP 0x006ebe5d
    goto L006ebe5d;
  }
  L006ebe52: { // 0x6ebe52: 8b89b4010000 MOV ECX,dword ptr [ECX + 0x1b4]
    s.cx = m.r32((s.cx+0x000001b4u));
  }
  { // 0x6ebe58: e85389e0ff CALL 0x004f47b0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L006ebe5d: { // 0x6ebe5d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ebe5f: 7406 JZ 0x006ebe67
    if(integer::condition("JZ",flags)) goto L006ebe67;
  }
  { // 0x6ebe61: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x6ebe66: c3 RET
    finish(m,s,f,0u); return;
  }
  L006ebe67: { // 0x6ebe67: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6ebe69: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030b540(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70b540: 8b0ddc83ab00 MOV ECX,dword ptr [0x00ab83dc]
    s.cx = m.r32((0x00ab83dcu));
  }
  { // 0x70b546: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x70b548: 7405 JZ 0x0070b54f
    if(integer::condition("JZ",flags)) goto L0070b54f;
  }
  { // 0x70b54a: e881c9cfff CALL 0x00407ed0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L0070b54f: { // 0x70b54f: a14883ab00 MOV EAX,[0x00ab8348]
    s.ax = m.r32((0x00ab8348u));
  }
  { // 0x70b554: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x70b555: a34883ab00 MOV [0x00ab8348],EAX
    m.w32((0x00ab8348u), s.ax);
  }
  { // 0x70b55a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030b5b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70b5b0: 8b0ddc83ab00 MOV ECX,dword ptr [0x00ab83dc]
    s.cx = m.r32((0x00ab83dcu));
  }
  { // 0x70b5b6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x70b5b8: 7405 JZ 0x0070b5bf
    if(integer::condition("JZ",flags)) goto L0070b5bf;
  }
  { // 0x70b5ba: e861c9cfff CALL 0x00407f20
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L0070b5bf: { // 0x70b5bf: a14883ab00 MOV EAX,[0x00ab8348]
    s.ax = m.r32((0x00ab8348u));
  }
  { // 0x70b5c4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70b5c6: 7417 JZ 0x0070b5df
    if(integer::condition("JZ",flags)) goto L0070b5df;
  }
  { // 0x70b5c8: a14883ab00 MOV EAX,[0x00ab8348]
    s.ax = m.r32((0x00ab8348u));
  }
  { // 0x70b5cd: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x70b5ce: a34883ab00 MOV [0x00ab8348],EAX
    m.w32((0x00ab8348u), s.ax);
  }
  { // 0x70b5d3: 790a JNS 0x0070b5df
    if(integer::condition("JNS",flags)) goto L0070b5df;
  }
  { // 0x70b5d5: c7054883ab0000000000 MOV dword ptr [0x00ab8348],0x0
    m.w32((0x00ab8348u), 0x00000000u);
  }
  L0070b5df: { // 0x70b5df: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030dc40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70dc40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x70dc41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x70dc43: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x70dc47: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x70dc49: 8806 MOV byte ptr [ESI],AL
    m.w8((s.si), (s.ax & 0xffu));
  }
  { // 0x70dc4b: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x70dc4e: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x70dc51: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  { // 0x70dc54: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x70dc57: 894614 MOV dword ptr [ESI + 0x14],EAX
    m.w32((s.si+0x00000014u), s.ax);
  }
  { // 0x70dc5a: 894618 MOV dword ptr [ESI + 0x18],EAX
    m.w32((s.si+0x00000018u), s.ax);
  }
  { // 0x70dc5d: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x70dc61: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x70dc62: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x70dc63: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x70dc65: e8b6000000 CALL 0x0070dd20
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x70dc6a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70dc6c: 7503 JNZ 0x0070dc71
    if(integer::condition("JNZ",flags)) goto L0070dc71;
  }
  { // 0x70dc6e: c60601 MOV byte ptr [ESI],0x1
    m.w8((s.si), 0x00000001u);
  }
  L0070dc71: { // 0x70dc71: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x70dc73: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70dc74: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_003116f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7116f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7116f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x7116f3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7116f4: 8dbef8010000 LEA EDI,[ESI + 0x1f8]
    s.di = (s.si+0x000001f8u);
  }
  { // 0x7116fa: 8d9670010000 LEA EDX,[ESI + 0x170]
    s.dx = (s.si+0x00000170u);
  }
  { // 0x711700: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x711701: 8d4e69 LEA ECX,[ESI + 0x69]
    s.cx = (s.si+0x00000069u);
  }
  { // 0x711704: e8d7590500 CALL 0x007670e0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x711709: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x71170c: 740c JZ 0x0071171a
    if(integer::condition("JZ",flags)) goto L0071171a;
  }
  { // 0x71170e: c6860c05000000 MOV byte ptr [ESI + 0x50c],0x0
    m.w8((s.si+0x0000050cu), 0x00000000u);
  }
  { // 0x711715: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x711716: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x711718: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x711719: c3 RET
    finish(m,s,f,0u); return;
  }
  L0071171a: { // 0x71171a: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x71171c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x71171e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x71171f: 8b4810 MOV ECX,dword ptr [EAX + 0x10]
    s.cx = m.r32((s.ax+0x00000010u));
  }
  { // 0x711722: 898e00050000 MOV dword ptr [ESI + 0x500],ECX
    m.w32((s.si+0x00000500u), s.cx);
  }
  { // 0x711728: 668b500c MOV DX,word ptr [EAX + 0xc]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x0000000cu)));
  }
  { // 0x71172c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x71172e: 899604050000 MOV dword ptr [ESI + 0x504],EDX
    m.w32((s.si+0x00000504u), s.dx);
  }
  { // 0x711734: 668b4802 MOV CX,word ptr [EAX + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.ax+0x00000002u)));
  }
  { // 0x711738: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x71173a: 898e10050000 MOV dword ptr [ESI + 0x510],ECX
    m.w32((s.si+0x00000510u), s.cx);
  }
  { // 0x711740: 668b5004 MOV DX,word ptr [EAX + 0x4]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x00000004u)));
  }
  { // 0x711744: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x711746: 899614050000 MOV dword ptr [ESI + 0x514],EDX
    m.w32((s.si+0x00000514u), s.dx);
  }
  { // 0x71174c: 88860c050000 MOV byte ptr [ESI + 0x50c],AL
    m.w8((s.si+0x0000050cu), (s.ax & 0xffu));
  }
  { // 0x711752: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x711753: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003117a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7117a0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x7117a4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7117a6: 7d03 JGE 0x007117ab
    if(integer::condition("JGE",flags)) goto L007117ab;
  }
  { // 0x7117a8: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L007117ab: { // 0x7117ab: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x7117af: 8b89f8010000 MOV ECX,dword ptr [ECX + 0x1f8]
    s.cx = m.r32((s.cx+0x000001f8u));
  }
  { // 0x7117b5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x7117b7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7117b8: e8c3670500 CALL 0x00767f80
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x7117bd: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x7117c0: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x7117c3: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_003117d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7117d0: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x7117d4: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x7117d6: 7c08 JL 0x007117e0
    if(integer::condition("JL",flags)) goto L007117e0;
  }
  { // 0x7117d8: 3b9100050000 CMP EDX,dword ptr [ECX + 0x500]
    (void)integer::sub(s.dx,m.r32((s.cx+0x00000500u)),32,flags);
  }
  { // 0x7117de: 7c02 JL 0x007117e2
    if(integer::condition("JL",flags)) goto L007117e2;
  }
  L007117e0: { // 0x7117e0: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L007117e2: { // 0x7117e2: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x7117e6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7117e7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7117e9: 7c08 JL 0x007117f3
    if(integer::condition("JL",flags)) goto L007117f3;
  }
  { // 0x7117eb: 3b8100050000 CMP EAX,dword ptr [ECX + 0x500]
    (void)integer::sub(s.ax,m.r32((s.cx+0x00000500u)),32,flags);
  }
  { // 0x7117f1: 7c07 JL 0x007117fa
    if(integer::condition("JL",flags)) goto L007117fa;
  }
  L007117f3: { // 0x7117f3: 8b8100050000 MOV EAX,dword ptr [ECX + 0x500]
    s.ax = m.r32((s.cx+0x00000500u));
  }
  { // 0x7117f9: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L007117fa: { // 0x7117fa: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  { // 0x7117fe: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x711800: 7d03 JGE 0x00711805
    if(integer::condition("JGE",flags)) goto L00711805;
  }
  { // 0x711802: 83ceff OR ESI,0xffffffff
    s.si = integer::logical((s.si)|(0xffffffffu),32,flags);
  }
  L00711805: { // 0x711805: 8b89f8010000 MOV ECX,dword ptr [ECX + 0x1f8]
    s.cx = m.r32((s.cx+0x000001f8u));
  }
  { // 0x71180b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x71180d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71180e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x71180f: e8ec670500 CALL 0x00768000
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x711814: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x711817: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x711818: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x71181b: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00311820(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x711820: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x711821: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x711823: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x711824: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x711828: 3bbefc040000 CMP EDI,dword ptr [ESI + 0x4fc]
    (void)integer::sub(s.di,m.r32((s.si+0x000004fcu)),32,flags);
  }
  { // 0x71182e: 741a JZ 0x0071184a
    if(integer::condition("JZ",flags)) goto L0071184a;
  }
  { // 0x711830: 8b8ef8010000 MOV ECX,dword ptr [ESI + 0x1f8]
    s.cx = m.r32((s.si+0x000001f8u));
  }
  { // 0x711836: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x711838: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  { // 0x71183a: e8e1630500 CALL 0x00767c20
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x71183f: 83f8fa CMP EAX,-0x6
    (void)integer::sub(s.ax,0xfffffffau,32,flags);
  }
  { // 0x711842: 7406 JZ 0x0071184a
    if(integer::condition("JZ",flags)) goto L0071184a;
  }
  { // 0x711844: 89befc040000 MOV dword ptr [ESI + 0x4fc],EDI
    m.w32((s.si+0x000004fcu), s.di);
  }
  L0071184a: { // 0x71184a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x71184b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71184c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00311850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x711850: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x711851: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x711853: 8a860c050000 MOV AL,byte ptr [ESI + 0x50c]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000050cu)));
  }
  { // 0x711859: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x71185b: 7424 JZ 0x00711881
    if(integer::condition("JZ",flags)) goto L00711881;
  }
  { // 0x71185d: 8b9644050000 MOV EDX,dword ptr [ESI + 0x544]
    s.dx = m.r32((s.si+0x00000544u));
  }
  { // 0x711863: 8b8ef8010000 MOV ECX,dword ptr [ESI + 0x1f8]
    s.cx = m.r32((s.si+0x000001f8u));
  }
  { // 0x711869: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x71186b: e8b0630500 CALL 0x00767c20
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x711870: 83f8fa CMP EAX,-0x6
    (void)integer::sub(s.ax,0xfffffffau,32,flags);
  }
  { // 0x711873: 7410 JZ 0x00711885
    if(integer::condition("JZ",flags)) goto L00711885;
  }
  { // 0x711875: 8b8644050000 MOV EAX,dword ptr [ESI + 0x544]
    s.ax = m.r32((s.si+0x00000544u));
  }
  { // 0x71187b: 8986fc040000 MOV dword ptr [ESI + 0x4fc],EAX
    m.w32((s.si+0x000004fcu), s.ax);
  }
  L00711881: { // 0x711881: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x711883: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x711884: c3 RET
    finish(m,s,f,0u); return;
  }
  L00711885: { // 0x711885: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x711887: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x711888: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00311d60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x711d60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x711d61: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x711d63: 8a860c050000 MOV AL,byte ptr [ESI + 0x50c]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000050cu)));
  }
  { // 0x711d69: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x711d6b: 741c JZ 0x00711d89
    if(integer::condition("JZ",flags)) goto L00711d89;
  }
  { // 0x711d6d: 8a8648050000 MOV AL,byte ptr [ESI + 0x548]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000548u)));
  }
  { // 0x711d73: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x711d75: 7512 JNZ 0x00711d89
    if(integer::condition("JNZ",flags)) goto L00711d89;
  }
  { // 0x711d77: 8b8ef8010000 MOV ECX,dword ptr [ESI + 0x1f8]
    s.cx = m.r32((s.si+0x000001f8u));
  }
  { // 0x711d7d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x711d7f: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  { // 0x711d84: e8c75a0500 CALL 0x00767850
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L00711d89: { // 0x711d89: c6864805000001 MOV byte ptr [ESI + 0x548],0x1
    m.w8((s.si+0x00000548u), 0x00000001u);
  }
  { // 0x711d90: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x711d91: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00311e00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x711e00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x711e01: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x711e02: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x711e06: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  { // 0x711e09: 7508 JNZ 0x00711e13
    if(integer::condition("JNZ",flags)) goto L00711e13;
  }
  { // 0x711e0b: 8bb918050000 MOV EDI,dword ptr [ECX + 0x518]
    s.di = m.r32((s.cx+0x00000518u));
  }
  { // 0x711e11: eb06 JMP 0x00711e19
    goto L00711e19;
  }
  L00711e13: { // 0x711e13: 89b918050000 MOV dword ptr [ECX + 0x518],EDI
    m.w32((s.cx+0x00000518u), s.di);
  }
  L00711e19: { // 0x711e19: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  { // 0x711e1d: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  { // 0x711e20: 7508 JNZ 0x00711e2a
    if(integer::condition("JNZ",flags)) goto L00711e2a;
  }
  { // 0x711e22: 8bb11c050000 MOV ESI,dword ptr [ECX + 0x51c]
    s.si = m.r32((s.cx+0x0000051cu));
  }
  { // 0x711e28: eb06 JMP 0x00711e30
    goto L00711e30;
  }
  L00711e2a: { // 0x711e2a: 89b11c050000 MOV dword ptr [ECX + 0x51c],ESI
    m.w32((s.cx+0x0000051cu), s.si);
  }
  L00711e30: { // 0x711e30: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  { // 0x711e34: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  { // 0x711e37: 7502 JNZ 0x00711e3b
    if(integer::condition("JNZ",flags)) goto L00711e3b;
  }
  { // 0x711e39: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00711e3b: { // 0x711e3b: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x711e3f: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x711e42: 7502 JNZ 0x00711e46
    if(integer::condition("JNZ",flags)) goto L00711e46;
  }
  { // 0x711e44: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00711e46: { // 0x711e46: 8b89f8010000 MOV ECX,dword ptr [ECX + 0x1f8]
    s.cx = m.r32((s.cx+0x000001f8u));
  }
  { // 0x711e4c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x711e4d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x711e4e: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x711e52: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x711e53: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x711e54: e8675f0500 CALL 0x00767dc0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x711e59: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x711e5c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x711e5d: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x711e60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x711e61: c21400 RET 0x14
    finish(m,s,f,20u); return;
  }
}
void f_00311e80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x711e80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x711e81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x711e83: 83be08050000ff CMP dword ptr [ESI + 0x508],-0x1
    (void)integer::sub(m.r32((s.si+0x00000508u)),0xffffffffu,32,flags);
  }
  { // 0x711e8a: 741f JZ 0x00711eab
    if(integer::condition("JZ",flags)) goto L00711eab;
  }
  { // 0x711e8c: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x711e90: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x711e94: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  { // 0x711e96: e815e5feff CALL 0x007003b0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x711e9b: 8b86fc040000 MOV EAX,dword ptr [ESI + 0x4fc]
    s.ax = m.r32((s.si+0x000004fcu));
  }
  { // 0x711ea1: 898644050000 MOV dword ptr [ESI + 0x544],EAX
    m.w32((s.si+0x00000544u), s.ax);
  }
  { // 0x711ea7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x711ea8: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00711eab: { // 0x711eab: 8b8efc040000 MOV ECX,dword ptr [ESI + 0x4fc]
    s.cx = m.r32((s.si+0x000004fcu));
  }
  { // 0x711eb1: 898e44050000 MOV dword ptr [ESI + 0x544],ECX
    m.w32((s.si+0x00000544u), s.cx);
  }
  { // 0x711eb7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x711eb8: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_003129c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7129c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7129c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x7129c3: e8d887e2ff CALL 0x0053b1a0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x7129c8: 8b0de00aae00 MOV ECX,dword ptr [0x00ae0ae0]
    s.cx = m.r32((0x00ae0ae0u));
  }
  { // 0x7129ce: 8d461c LEA EAX,[ESI + 0x1c]
    s.ax = (s.si+0x0000001cu);
  }
  { // 0x7129d1: 894e1c MOV dword ptr [ESI + 0x1c],ECX
    m.w32((s.si+0x0000001cu), s.cx);
  }
  { // 0x7129d4: 8b15e40aae00 MOV EDX,dword ptr [0x00ae0ae4]
    s.dx = m.r32((0x00ae0ae4u));
  }
  { // 0x7129da: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  { // 0x7129dd: 8b0de80aae00 MOV ECX,dword ptr [0x00ae0ae8]
    s.cx = m.r32((0x00ae0ae8u));
  }
  { // 0x7129e3: 8d5628 LEA EDX,[ESI + 0x28]
    s.dx = (s.si+0x00000028u);
  }
  { // 0x7129e6: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  { // 0x7129e9: a1e00aae00 MOV EAX,[0x00ae0ae0]
    s.ax = m.r32((0x00ae0ae0u));
  }
  { // 0x7129ee: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  { // 0x7129f0: 8b0de40aae00 MOV ECX,dword ptr [0x00ae0ae4]
    s.cx = m.r32((0x00ae0ae4u));
  }
  { // 0x7129f6: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  { // 0x7129f9: a1e80aae00 MOV EAX,[0x00ae0ae8]
    s.ax = m.r32((0x00ae0ae8u));
  }
  { // 0x7129fe: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  { // 0x712a01: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x712a03: 884634 MOV byte ptr [ESI + 0x34],AL
    m.w8((s.si+0x00000034u), (s.ax & 0xffu));
  }
  { // 0x712a06: 884635 MOV byte ptr [ESI + 0x35],AL
    m.w8((s.si+0x00000035u), (s.ax & 0xffu));
  }
  { // 0x712a09: 884636 MOV byte ptr [ESI + 0x36],AL
    m.w8((s.si+0x00000036u), (s.ax & 0xffu));
  }
  { // 0x712a0c: 894638 MOV dword ptr [ESI + 0x38],EAX
    m.w32((s.si+0x00000038u), s.ax);
  }
  { // 0x712a0f: c706309a7900 MOV dword ptr [ESI],0x799a30
    m.w32((s.si), 0x00799a30u);
  }
  { // 0x712a15: c7460468997900 MOV dword ptr [ESI + 0x4],0x799968
    m.w32((s.si+0x00000004u), 0x00799968u);
  }
  { // 0x712a1c: c7461844997900 MOV dword ptr [ESI + 0x18],0x799944
    m.w32((s.si+0x00000018u), 0x00799944u);
  }
  { // 0x712a23: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x712a25: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x712a26: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0031af10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71af10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71af11: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71af13: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x71af16: e8356f0000 CALL 0x00721e50
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x71af1b: 8b5630 MOV EDX,dword ptr [ESI + 0x30]
    s.dx = m.r32((s.si+0x00000030u));
  }
  { // 0x71af1e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x71af20: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x71af22: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71af23: 0f95c1 SETNZ CL
    s.cx = with_al(s.cx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x71af26: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  { // 0x71af28: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0031bbe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71bbe0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71bbe1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71bbe3: e8984ef1ff CALL 0x00630a80
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x71bbe8: c7067c9e7900 MOV dword ptr [ESI],0x799e7c
    m.w32((s.si), 0x00799e7cu);
  }
  { // 0x71bbee: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71bbf0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71bbf1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0031d020(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71d020: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71d021: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71d023: e8583af1ff CALL 0x00630a80
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x71d028: c7066c9f7900 MOV dword ptr [ESI],0x799f6c
    m.w32((s.si), 0x00799f6cu);
  }
  { // 0x71d02e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71d030: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71d031: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0031dac0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71dac0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x71dac4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71dac5: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x71dac9: 8d5108 LEA EDX,[ECX + 0x8]
    s.dx = (s.cx+0x00000008u);
  }
  { // 0x71dacc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x71dacd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71dacf: e8ec770000 CALL 0x007252c0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x71dad4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71dad6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71dad7: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0031dd80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71dd80: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x71dd81: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71dd82: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71dd84: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x71dd86: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x71dd89: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  { // 0x71dd8c: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  { // 0x71dd8f: 885e0c MOV byte ptr [ESI + 0xc],BL
    m.w8((s.si+0x0000000cu), (s.bx & 0xffu));
  }
  { // 0x71dd92: e8391df7ff CALL 0x0068fad0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x71dd97: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x71dd9a: 895e18 MOV dword ptr [ESI + 0x18],EBX
    m.w32((s.si+0x00000018u), s.bx);
  }
  { // 0x71dd9d: c7064ca07900 MOV dword ptr [ESI],0x79a04c
    m.w32((s.si), 0x0079a04cu);
  }
  { // 0x71dda3: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71dda5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71dda6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x71dda7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003206b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7206b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7206b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x7206b3: e8c803f1ff CALL 0x00630a80
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x7206b8: c7060ca17900 MOV dword ptr [ESI],0x79a10c
    m.w32((s.si), 0x0079a10cu);
  }
  { // 0x7206be: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x7206c0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7206c1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00321b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x721b30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x721b31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x721b33: e848eff0ff CALL 0x00630a80
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x721b38: c7062cf57800 MOV dword ptr [ESI],0x78f52c
    m.w32((s.si), 0x0078f52cu);
  }
  { // 0x721b3e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x721b40: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x721b41: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00324e70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x724e70: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x724e74: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x724e75: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x724e79: 8d512c LEA EDX,[ECX + 0x2c]
    s.dx = (s.cx+0x0000002cu);
  }
  { // 0x724e7c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x724e7d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x724e7f: e8ec0e0000 CALL 0x00725d70
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x724e84: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x724e86: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x724e87: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_003253b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7253b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7253b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x7253b3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7253b4: 8d7e08 LEA EDI,[ESI + 0x8]
    s.di = (s.si+0x00000008u);
  }
  { // 0x7253b7: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x7253be: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x7253c0: c706d43c7900 MOV dword ptr [ESI],0x793cd4
    m.w32((s.si), 0x00793cd4u);
  }
  { // 0x7253c6: e8b5b6f0ff CALL 0x00630a80
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x7253cb: c70734a07900 MOV dword ptr [EDI],0x79a034
    m.w32((s.di), 0x0079a034u);
  }
  { // 0x7253d1: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  { // 0x7253d8: c7065ca27900 MOV dword ptr [ESI],0x79a25c
    m.w32((s.si), 0x0079a25cu);
  }
  { // 0x7253de: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x7253e0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7253e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7253e2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00327660(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x727660: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x727661: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x727662: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x727664: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x727666: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x727669: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  { // 0x72766c: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  { // 0x72766f: 885e0c MOV byte ptr [ESI + 0xc],BL
    m.w8((s.si+0x0000000cu), (s.bx & 0xffu));
  }
  { // 0x727672: e85984f6ff CALL 0x0068fad0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x727677: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x72767a: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x72767e: 895e18 MOV dword ptr [ESI + 0x18],EBX
    m.w32((s.si+0x00000018u), s.bx);
  }
  { // 0x727681: 89461c MOV dword ptr [ESI + 0x1c],EAX
    m.w32((s.si+0x0000001cu), s.ax);
  }
  { // 0x727684: c7069ca27900 MOV dword ptr [ESI],0x79a29c
    m.w32((s.si), 0x0079a29cu);
  }
  { // 0x72768a: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x72768c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72768d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x72768e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00327710(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x727710: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x727711: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x727713: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x727716: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x727719: 7434 JZ 0x0072774f
    if(integer::condition("JZ",flags)) goto L0072774f;
  }
  { // 0x72771b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x72771c: 8b7e18 MOV EDI,dword ptr [ESI + 0x18]
    s.di = m.r32((s.si+0x00000018u));
  }
  { // 0x72771f: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x727722: 7420 JZ 0x00727744
    if(integer::condition("JZ",flags)) goto L00727744;
  }
  { // 0x727724: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x727727: e8a483f6ff CALL 0x0068fad0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x72772c: 2b4610 SUB EAX,dword ptr [ESI + 0x10]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x00000010u)),32,flags);
  }
  { // 0x72772f: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x727731: 7d0f JGE 0x00727742
    if(integer::condition("JGE",flags)) goto L00727742;
  }
  { // 0x727733: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x727735: c74610ffffffff MOV dword ptr [ESI + 0x10],0xffffffff
    m.w32((s.si+0x00000010u), 0xffffffffu);
  }
  { // 0x72773c: 897e18 MOV dword ptr [ESI + 0x18],EDI
    m.w32((s.si+0x00000018u), s.di);
  }
  { // 0x72773f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x727740: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x727741: c3 RET
    finish(m,s,f,0u); return;
  }
  L00727742: { // 0x727742: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00727744: { // 0x727744: 897e18 MOV dword ptr [ESI + 0x18],EDI
    m.w32((s.si+0x00000018u), s.di);
  }
  { // 0x727747: c74610ffffffff MOV dword ptr [ESI + 0x10],0xffffffff
    m.w32((s.si+0x00000010u), 0xffffffffu);
  }
  { // 0x72774e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0072774f: { // 0x72774f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x727750: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00327760(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x727760: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x727761: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x727763: 837e10ff CMP dword ptr [ESI + 0x10],-0x1
    (void)integer::sub(m.r32((s.si+0x00000010u)),0xffffffffu,32,flags);
  }
  { // 0x727767: 750b JNZ 0x00727774
    if(integer::condition("JNZ",flags)) goto L00727774;
  }
  { // 0x727769: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x72776c: e85f83f6ff CALL 0x0068fad0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x727771: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L00727774: { // 0x727774: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x727775: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00327c90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x727c90: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x727c94: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x727c95: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x727c97: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x727c98: e8438aceff CALL 0x004106e0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x727c9d: c786bc000000f4897800 MOV dword ptr [ESI + 0xbc],0x7889f4
    m.w32((s.si+0x000000bcu), 0x007889f4u);
  }
  { // 0x727ca7: c786d80000003ceb7800 MOV dword ptr [ESI + 0xd8],0x78eb3c
    m.w32((s.si+0x000000d8u), 0x0078eb3cu);
  }
  { // 0x727cb1: c70600a37900 MOV dword ptr [ESI],0x79a300
    m.w32((s.si), 0x0079a300u);
  }
  { // 0x727cb7: c74604d4a27900 MOV dword ptr [ESI + 0x4],0x79a2d4
    m.w32((s.si+0x00000004u), 0x0079a2d4u);
  }
  { // 0x727cbe: c74608f8a27900 MOV dword ptr [ESI + 0x8],0x79a2f8
    m.w32((s.si+0x00000008u), 0x0079a2f8u);
  }
  { // 0x727cc5: c7460cf0a27900 MOV dword ptr [ESI + 0xc],0x79a2f0
    m.w32((s.si+0x0000000cu), 0x0079a2f0u);
  }
  { // 0x727ccc: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x727cce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x727ccf: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0032c690(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72c690: a1a0397c00 MOV EAX,[0x007c39a0]
    s.ax = m.r32((0x007c39a0u));
  }
  { // 0x72c695: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72c696: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x72c698: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72c699: 684c997b00 PUSH 0x7b994c
    f.push(m,0x007b994cu);
  }
  { // 0x72c69e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72c69f: e890130400 CALL 0x0076da34
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x72c6a4: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x72c6a7: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x72c6a9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72c6aa: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0032c6c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72c6c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72c6c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x72c6c3: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x72c6c5: 68a4397c00 PUSH 0x7c39a4
    f.push(m,0x007c39a4u);
  }
  { // 0x72c6ca: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72c6cb: e840160400 CALL 0x0076dd10
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x72c6d0: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x72c6d3: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x72c6d5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72c6d6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0032c950(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72c950: 8b0d5cdeb000 MOV ECX,dword ptr [0x00b0de5c]
    s.cx = m.r32((0x00b0de5cu));
  }
  { // 0x72c956: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x72c958: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x72c95a: 66a320dcb000 MOV [0x00b0dc20],AX
    m.w16((0x00b0dc20u), (s.ax & 0xffffu));
  }
  { // 0x72c960: a364deb000 MOV [0x00b0de64],EAX
    m.w32((0x00b0de64u), s.ax);
  }
  { // 0x72c965: a368deb000 MOV [0x00b0de68],EAX
    m.w32((0x00b0de68u), s.ax);
  }
  { // 0x72c96a: a36cdeb000 MOV [0x00b0de6c],EAX
    m.w32((0x00b0de6cu), s.ax);
  }
  { // 0x72c96f: 66a3f4d9b000 MOV [0x00b0d9f4],AX
    m.w16((0x00b0d9f4u), (s.ax & 0xffffu));
  }
  { // 0x72c975: 740b JZ 0x0072c982
    if(integer::condition("JZ",flags)) goto L0072c982;
  }
  { // 0x72c977: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72c978: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x72c97a: 6a15 PUSH 0x15
    f.push(m,0x00000015u);
  }
  { // 0x72c97c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x72c97d: e8e40b0400 CALL 0x0076d566
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L0072c982: { // 0x72c982: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0032d800(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72d800: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72d801: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x72d803: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x72d805: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x72d808: 884608 MOV byte ptr [ESI + 0x8],AL
    m.w8((s.si+0x00000008u), (s.ax & 0xffu));
  }
  { // 0x72d80b: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x72d80f: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x72d812: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72d813: c706d43c7900 MOV dword ptr [ESI],0x793cd4
    m.w32((s.si), 0x00793cd4u);
  }
  { // 0x72d819: e8a2ba0200 CALL 0x007592c0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x72d81e: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x72d822: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x72d826: 8a542410 MOV DL,byte ptr [ESP + 0x10]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000010u)));
  }
  { // 0x72d82a: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x72d82d: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x72d831: 894618 MOV dword ptr [ESI + 0x18],EAX
    m.w32((s.si+0x00000018u), s.ax);
  }
  { // 0x72d834: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  { // 0x72d838: 885614 MOV byte ptr [ESI + 0x14],DL
    m.w8((s.si+0x00000014u), (s.dx & 0xffu));
  }
  { // 0x72d83b: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x72d83f: 894e1c MOV dword ptr [ESI + 0x1c],ECX
    m.w32((s.si+0x0000001cu), s.cx);
  }
  { // 0x72d842: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  { // 0x72d846: 894624 MOV dword ptr [ESI + 0x24],EAX
    m.w32((s.si+0x00000024u), s.ax);
  }
  { // 0x72d849: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  { // 0x72d84d: 895620 MOV dword ptr [ESI + 0x20],EDX
    m.w32((s.si+0x00000020u), s.dx);
  }
  { // 0x72d850: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  { // 0x72d854: 894e28 MOV dword ptr [ESI + 0x28],ECX
    m.w32((s.si+0x00000028u), s.cx);
  }
  { // 0x72d857: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  { // 0x72d85b: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  { // 0x72d85e: 89562c MOV dword ptr [ESI + 0x2c],EDX
    m.w32((s.si+0x0000002cu), s.dx);
  }
  { // 0x72d861: 894e34 MOV dword ptr [ESI + 0x34],ECX
    m.w32((s.si+0x00000034u), s.cx);
  }
  { // 0x72d864: c706e4a37900 MOV dword ptr [ESI],0x79a3e4
    m.w32((s.si), 0x0079a3e4u);
  }
  { // 0x72d86a: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x72d86c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72d86d: c22c00 RET 0x2c
    finish(m,s,f,44u); return;
  }
}
void f_00330b80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x730b80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x730b81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x730b83: e8e881ecff CALL 0x005f8d70
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x730b88: c70684a57900 MOV dword ptr [ESI],0x79a584
    m.w32((s.si), 0x0079a584u);
  }
  { // 0x730b8e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x730b90: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x730b91: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00352730(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x752730: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x752734: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x752736: 7c19 JL 0x00752751
    if(integer::condition("JL",flags)) goto L00752751;
  }
  { // 0x752738: 3b01 CMP EAX,dword ptr [ECX]
    (void)integer::sub(s.ax,m.r32((s.cx)),32,flags);
  }
  { // 0x75273a: 7d15 JGE 0x00752751
    if(integer::condition("JGE",flags)) goto L00752751;
  }
  { // 0x75273c: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  { // 0x75273f: 8d1481 LEA EDX,[ECX + EAX*0x4]
    s.dx = (s.cx+(s.ax * 0x00000004u));
  }
  { // 0x752742: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x752746: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x752747: e8246e0000 CALL 0x00759570
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x75274c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x75274e: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00752751: { // 0x752751: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x752753: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00356210(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x756210: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x756211: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x756213: e8980b0000 CALL 0x00756db0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x756218: 8d86fc3a0400 LEA EAX,[ESI + 0x43afc]
    s.ax = (s.si+0x00043afcu);
  }
  { // 0x75621e: 8d96003b0400 LEA EDX,[ESI + 0x43b00]
    s.dx = (s.si+0x00043b00u);
  }
  { // 0x756224: c70644a87900 MOV dword ptr [ESI],0x79a844
    m.w32((s.si), 0x0079a844u);
  }
  { // 0x75622a: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x75622d: c700ffffffff MOV dword ptr [EAX],0xffffffff
    m.w32((s.ax), 0xffffffffu);
  }
  { // 0x756233: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  { // 0x756235: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x756238: 66894a04 MOV word ptr [EDX + 0x4],CX
    m.w16((s.dx+0x00000004u), (s.cx & 0xffffu));
  }
  { // 0x75623c: 8d8e063b0400 LEA ECX,[ESI + 0x43b06]
    s.cx = (s.si+0x00043b06u);
  }
  { // 0x756242: 8986063b0400 MOV dword ptr [ESI + 0x43b06],EAX
    m.w32((s.si+0x00043b06u), s.ax);
  }
  { // 0x756248: 66894104 MOV word ptr [ECX + 0x4],AX
    m.w16((s.cx+0x00000004u), (s.ax & 0xffffu));
  }
  { // 0x75624c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x75624e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75624f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00358120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x758120: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x758121: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x758123: e888ecffff CALL 0x00756db0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x758128: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x75812a: bac4a97900 MOV EDX,0x79a9c4
    s.dx = 0x0079a9c4u;
  }
  { // 0x75812f: b90a000000 MOV ECX,0xa
    s.cx = 0x0000000au;
  }
  { // 0x758134: 8986003b0400 MOV dword ptr [ESI + 0x43b00],EAX
    m.w32((s.si+0x00043b00u), s.ax);
  }
  { // 0x75813a: 8986043b0400 MOV dword ptr [ESI + 0x43b04],EAX
    m.w32((s.si+0x00043b04u), s.ax);
  }
  { // 0x758140: c686083b040001 MOV byte ptr [ESI + 0x43b08],0x1
    m.w8((s.si+0x00043b08u), 0x00000001u);
  }
  { // 0x758147: 8886093b0400 MOV byte ptr [ESI + 0x43b09],AL
    m.w8((s.si+0x00043b09u), (s.ax & 0xffu));
  }
  { // 0x75814d: 8996fc3a0400 MOV dword ptr [ESI + 0x43afc],EDX
    m.w32((s.si+0x00043afcu), s.dx);
  }
  { // 0x758153: 898e103b0400 MOV dword ptr [ESI + 0x43b10],ECX
    m.w32((s.si+0x00043b10u), s.cx);
  }
  { // 0x758159: 89860c3b0400 MOV dword ptr [ESI + 0x43b0c],EAX
    m.w32((s.si+0x00043b0cu), s.ax);
  }
  { // 0x75815f: 8986183b0400 MOV dword ptr [ESI + 0x43b18],EAX
    m.w32((s.si+0x00043b18u), s.ax);
  }
  { // 0x758165: 89861c3b0400 MOV dword ptr [ESI + 0x43b1c],EAX
    m.w32((s.si+0x00043b1cu), s.ax);
  }
  { // 0x75816b: c686203b040001 MOV byte ptr [ESI + 0x43b20],0x1
    m.w8((s.si+0x00043b20u), 0x00000001u);
  }
  { // 0x758172: 8886213b0400 MOV byte ptr [ESI + 0x43b21],AL
    m.w8((s.si+0x00043b21u), (s.ax & 0xffu));
  }
  { // 0x758178: 8996143b0400 MOV dword ptr [ESI + 0x43b14],EDX
    m.w32((s.si+0x00043b14u), s.dx);
  }
  { // 0x75817e: 898e283b0400 MOV dword ptr [ESI + 0x43b28],ECX
    m.w32((s.si+0x00043b28u), s.cx);
  }
  { // 0x758184: 8986243b0400 MOV dword ptr [ESI + 0x43b24],EAX
    m.w32((s.si+0x00043b24u), s.ax);
  }
  { // 0x75818a: c70664a97900 MOV dword ptr [ESI],0x79a964
    m.w32((s.si), 0x0079a964u);
  }
  { // 0x758190: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x758192: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x758193: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0035aeb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75aeb0: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x75aeb2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75aeb3: e885380100 CALL 0x0076e73d
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x75aeb8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75aebb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0035b3b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75b3b0: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x75b3b2: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x75b3b6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75b3b8: 7509 JNZ 0x0075b3c3
    if(integer::condition("JNZ",flags)) goto L0075b3c3;
  }
  { // 0x75b3ba: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x75b3bc: 7505 JNZ 0x0075b3c3
    if(integer::condition("JNZ",flags)) goto L0075b3c3;
  }
  { // 0x75b3be: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x75b3c0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0075b3c3: { // 0x75b3c3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75b3c5: 7416 JZ 0x0075b3dd
    if(integer::condition("JZ",flags)) goto L0075b3dd;
  }
  { // 0x75b3c7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x75b3c9: 7412 JZ 0x0075b3dd
    if(integer::condition("JZ",flags)) goto L0075b3dd;
  }
  { // 0x75b3cb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75b3cc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75b3cd: e8413d0100 CALL 0x0076f113
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x75b3d2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x75b3d5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75b3d7: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x75b3da: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0075b3dd: { // 0x75b3dd: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x75b3df: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035b3f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75b3f0: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x75b3f2: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x75b3f6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75b3f8: 750a JNZ 0x0075b404
    if(integer::condition("JNZ",flags)) goto L0075b404;
  }
  { // 0x75b3fa: 833900 CMP dword ptr [ECX],0x0
    (void)integer::sub(m.r32((s.cx)),0x00000000u,32,flags);
  }
  { // 0x75b3fd: 7505 JNZ 0x0075b404
    if(integer::condition("JNZ",flags)) goto L0075b404;
  }
  { // 0x75b3ff: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x75b401: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0075b404: { // 0x75b404: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75b406: 7418 JZ 0x0075b420
    if(integer::condition("JZ",flags)) goto L0075b420;
  }
  { // 0x75b408: 8b09 MOV ECX,dword ptr [ECX]
    s.cx = m.r32((s.cx));
  }
  { // 0x75b40a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x75b40c: 7412 JZ 0x0075b420
    if(integer::condition("JZ",flags)) goto L0075b420;
  }
  { // 0x75b40e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75b40f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75b410: e8fe3c0100 CALL 0x0076f113
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x75b415: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x75b418: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75b41a: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x75b41d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0075b420: { // 0x75b420: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x75b422: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035bd40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75bd40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75bd41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75bd43: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x75bd45: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75bd46: e8fa310100 CALL 0x0076ef45
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x75bd4b: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x75bd4f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75bd52: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x75bd54: 730a JNC 0x0075bd60
    if(integer::condition("JNC",flags)) goto L0075bd60;
  }
  { // 0x75bd56: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x75bd58: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75bd59: 668b044a MOV AX,word ptr [EDX + ECX*0x2]
    s.ax = with_ax(s.ax, m.r16((s.dx+(s.cx * 0x00000002u))));
  }
  { // 0x75bd5d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0075bd60: { // 0x75bd60: 6633c0 XOR AX,AX
    s.ax = with_ax(s.ax, integer::logical(((s.ax & 0xffffu))^((s.ax & 0xffffu)),16,flags));
  }
  { // 0x75bd63: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75bd64: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035bd80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75bd80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75bd81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75bd83: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x75bd85: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75bd86: e8ba310100 CALL 0x0076ef45
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x75bd8b: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x75bd8f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75bd92: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x75bd94: 730a JNC 0x0075bda0
    if(integer::condition("JNC",flags)) goto L0075bda0;
  }
  { // 0x75bd96: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x75bd98: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75bd99: 668b044a MOV AX,word ptr [EDX + ECX*0x2]
    s.ax = with_ax(s.ax, m.r16((s.dx+(s.cx * 0x00000002u))));
  }
  { // 0x75bd9d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0075bda0: { // 0x75bda0: 6633c0 XOR AX,AX
    s.ax = with_ax(s.ax, integer::logical(((s.ax & 0xffffu))^((s.ax & 0xffffu)),16,flags));
  }
  { // 0x75bda3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75bda4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035bdb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75bdb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75bdb1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75bdb3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x75bdb5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75bdb6: e88a310100 CALL 0x0076ef45
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x75bdbb: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x75bdbf: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75bdc2: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x75bdc4: 730a JNC 0x0075bdd0
    if(integer::condition("JNC",flags)) goto L0075bdd0;
  }
  { // 0x75bdc6: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x75bdc8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75bdc9: 668b044a MOV AX,word ptr [EDX + ECX*0x2]
    s.ax = with_ax(s.ax, m.r16((s.dx+(s.cx * 0x00000002u))));
  }
  { // 0x75bdcd: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0075bdd0: { // 0x75bdd0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x75bdd2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75bdd3: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035bde0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75bde0: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x75bde2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75bde4: 7501 JNZ 0x0075bde7
    if(integer::condition("JNZ",flags)) goto L0075bde7;
  }
  { // 0x75bde6: c3 RET
    finish(m,s,f,0u); return;
  }
  L0075bde7: { // 0x75bde7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75bde8: e858310100 CALL 0x0076ef45
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x75bded: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75bdf0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0035c290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75c290: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75c291: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75c293: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x75c295: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75c296: e8aa2c0100 CALL 0x0076ef45
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x75c29b: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x75c29f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75c2a2: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x75c2a4: 7206 JC 0x0075c2ac
    if(integer::condition("JC",flags)) goto L0075c2ac;
  }
  { // 0x75c2a6: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x75c2a8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75c2a9: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0075c2ac: { // 0x75c2ac: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x75c2ae: 668b442408 MOV AX,word ptr [ESP + 0x8]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000008u)));
  }
  { // 0x75c2b3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75c2b4: 6689044a MOV word ptr [EDX + ECX*0x2],AX
    m.w16((s.dx+(s.cx * 0x00000002u)), (s.ax & 0xffffu));
  }
  { // 0x75c2b8: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x75c2ba: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0035c9b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75c9b0: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x75c9b2: 6a0a PUSH 0xa
    f.push(m,0x0000000au);
  }
  { // 0x75c9b4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x75c9b6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75c9b7: e8fc3a0100 CALL 0x007704b8
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x75c9bc: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x75c9bf: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0035c9c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75c9c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75c9c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75c9c3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x75c9c5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75c9c7: 7420 JZ 0x0075c9e9
    if(integer::condition("JZ",flags)) goto L0075c9e9;
  }
  { // 0x75c9c9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75c9ca: e876250100 CALL 0x0076ef45
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x75c9cf: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75c9d2: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x75c9d4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75c9d6: 7e11 JLE 0x0075c9e9
    if(integer::condition("JLE",flags)) goto L0075c9e9;
  }
  { // 0x75c9d8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0075c9da: { // 0x75c9da: 66813a0001 CMP word ptr [EDX],0x100
    (void)integer::sub(m.r16((s.dx)),0x00000100u,16,flags);
  }
  { // 0x75c9df: 730c JNC 0x0075c9ed
    if(integer::condition("JNC",flags)) goto L0075c9ed;
  }
  { // 0x75c9e1: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x75c9e2: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  { // 0x75c9e5: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x75c9e7: 7cf1 JL 0x0075c9da
    if(integer::condition("JL",flags)) goto L0075c9da;
  }
  L0075c9e9: { // 0x75c9e9: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x75c9eb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75c9ec: c3 RET
    finish(m,s,f,0u); return;
  }
  L0075c9ed: { // 0x75c9ed: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x75c9ef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75c9f0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0035f070(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75f070: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75f071: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75f072: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75f074: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x75f076: 8b560c MOV EDX,dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  { // 0x75f079: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x75f07b: 7446 JZ 0x0075f0c3
    if(integer::condition("JZ",flags)) goto L0075f0c3;
  }
  { // 0x75f07d: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x75f081: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x75f083: 743e JZ 0x0075f0c3
    if(integer::condition("JZ",flags)) goto L0075f0c3;
  }
  { // 0x75f085: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x75f089: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x75f08b: 7e36 JLE 0x0075f0c3
    if(integer::condition("JLE",flags)) goto L0075f0c3;
  }
  { // 0x75f08d: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x75f090: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75f091: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75f093: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x75f095: 740d JZ 0x0075f0a4
    if(integer::condition("JZ",flags)) goto L0075f0a4;
  }
  { // 0x75f097: 8b7e18 MOV EDI,dword ptr [ESI + 0x18]
    s.di = m.r32((s.si+0x00000018u));
  }
  { // 0x75f09a: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x75f09c: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x75f09e: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x75f0a0: 7c02 JL 0x0075f0a4
    if(integer::condition("JL",flags)) goto L0075f0a4;
  }
  { // 0x75f0a2: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0075f0a4: { // 0x75f0a4: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x75f0a6: 7e10 JLE 0x0075f0b8
    if(integer::condition("JLE",flags)) goto L0075f0b8;
  }
  { // 0x75f0a8: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  { // 0x75f0ab: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75f0ac: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x75f0ae: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75f0af: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75f0b0: e81bfb0000 CALL 0x0076ebd0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x75f0b5: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0075f0b8: { // 0x75f0b8: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  { // 0x75f0bb: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x75f0bd: 894618 MOV dword ptr [ESI + 0x18],EAX
    m.w32((s.si+0x00000018u), s.ax);
  }
  { // 0x75f0c0: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x75f0c2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f0c3: { // 0x75f0c3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75f0c4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75f0c5: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0035f180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75f180: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75f181: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75f182: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75f184: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x75f186: 8b560c MOV EDX,dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  { // 0x75f189: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x75f18b: 7446 JZ 0x0075f1d3
    if(integer::condition("JZ",flags)) goto L0075f1d3;
  }
  { // 0x75f18d: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x75f191: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x75f193: 743e JZ 0x0075f1d3
    if(integer::condition("JZ",flags)) goto L0075f1d3;
  }
  { // 0x75f195: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x75f199: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x75f19b: 7e36 JLE 0x0075f1d3
    if(integer::condition("JLE",flags)) goto L0075f1d3;
  }
  { // 0x75f19d: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x75f1a0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75f1a1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75f1a3: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x75f1a5: 740d JZ 0x0075f1b4
    if(integer::condition("JZ",flags)) goto L0075f1b4;
  }
  { // 0x75f1a7: 8b7e18 MOV EDI,dword ptr [ESI + 0x18]
    s.di = m.r32((s.si+0x00000018u));
  }
  { // 0x75f1aa: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x75f1ac: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x75f1ae: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x75f1b0: 7c02 JL 0x0075f1b4
    if(integer::condition("JL",flags)) goto L0075f1b4;
  }
  { // 0x75f1b2: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0075f1b4: { // 0x75f1b4: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x75f1b6: 7e10 JLE 0x0075f1c8
    if(integer::condition("JLE",flags)) goto L0075f1c8;
  }
  { // 0x75f1b8: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  { // 0x75f1bb: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75f1bc: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x75f1be: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75f1bf: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75f1c0: e80bfa0000 CALL 0x0076ebd0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x75f1c5: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0075f1c8: { // 0x75f1c8: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  { // 0x75f1cb: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x75f1cd: 894618 MOV dword ptr [ESI + 0x18],EAX
    m.w32((s.si+0x00000018u), s.ax);
  }
  { // 0x75f1d0: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x75f1d2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f1d3: { // 0x75f1d3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75f1d4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75f1d5: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00367f80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x767f80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x767f81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x767f83: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x767f84: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x767f86: 668b8614070000 MOV AX,word ptr [ESI + 0x714]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000714u)));
  }
  { // 0x767f8d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x767f8f: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  { // 0x767f95: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x767f97: 7d4f JGE 0x00767fe8
    if(integer::condition("JGE",flags)) goto L00767fe8;
  }
  { // 0x767f99: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x767f9b: 7c4b JL 0x00767fe8
    if(integer::condition("JL",flags)) goto L00767fe8;
  }
  { // 0x767f9d: f6868400000001 TEST byte ptr [ESI + 0x84],0x1
    (void)integer::logical((m.r8((s.si+0x00000084u)))&(0x00000001u),8,flags);
  }
  { // 0x767fa4: 7405 JZ 0x00767fab
    if(integer::condition("JZ",flags)) goto L00767fab;
  }
  { // 0x767fa6: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  { // 0x767fa9: 743d JZ 0x00767fe8
    if(integer::condition("JZ",flags)) goto L00767fe8;
  }
  L00767fab: { // 0x767fab: 8b961c070000 MOV EDX,dword ptr [ESI + 0x71c]
    s.dx = m.r32((s.si+0x0000071cu));
  }
  { // 0x767fb1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x767fb3: 668b44ba02 MOV AX,word ptr [EDX + EDI*0x4 + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.dx+(s.di * 0x00000004u)+0x00000002u)));
  }
  { // 0x767fb8: 8d0cba LEA ECX,[EDX + EDI*0x4]
    s.cx = (s.dx+(s.di * 0x00000004u));
  }
  { // 0x767fbb: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x767fbd: 668b11 MOV DX,word ptr [ECX]
    s.dx = with_ax(s.dx, m.r16((s.cx)));
  }
  { // 0x767fc0: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x767fc4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x767fc5: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x767fc9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x767fca: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x767fcb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x767fcd: 89be20010000 MOV dword ptr [ESI + 0x120],EDI
    m.w32((s.si+0x00000120u), s.di);
  }
  { // 0x767fd3: e828000000 CALL 0x00768000
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x767fd8: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x767fdb: 7510 JNZ 0x00767fed
    if(integer::condition("JNZ",flags)) goto L00767fed;
  }
  { // 0x767fdd: 89be20010000 MOV dword ptr [ESI + 0x120],EDI
    m.w32((s.si+0x00000120u), s.di);
  }
  { // 0x767fe3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x767fe4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x767fe5: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00767fe8: { // 0x767fe8: b8e9ffffff MOV EAX,0xffffffe9
    s.ax = 0xffffffe9u;
  }
  L00767fed: { // 0x767fed: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x767fee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x767fef: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0036d611(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76d611: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x76d615: 83c109 ADD ECX,0x9
    s.cx = integer::add(s.cx,0x00000009u,32,flags);
  }
  { // 0x76d618: 83c009 ADD EAX,0x9
    s.ax = integer::add(s.ax,0x00000009u,32,flags);
  }
  { // 0x76d61b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x76d61c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76d61d: e82e400000 CALL 0x00771650
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x76d622: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x76d624: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76d625: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x76d627: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76d628: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x76d629: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0036df70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76df70: ff355405b100 PUSH dword ptr [0x00b10554]
    f.push(m,m.r32((0x00b10554u)));
  }
  { // 0x76df76: ff742408 PUSH dword ptr [ESP + 0x8]
    f.push(m,m.r32((f.sp+0x00000008u)));
  }
  { // 0x76df7a: e803000000 CALL 0x0076df82
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x76df7f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76df80: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76df81: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036e2ca(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76e2ca: ff742404 PUSH dword ptr [ESP + 0x4]
    f.push(m,m.r32((f.sp+0x00000004u)));
  }
  { // 0x76e2ce: e879ffffff CALL 0x0076e24c
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x76e2d3: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x76e2d5: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x76e2d7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76e2d8: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x76e2da: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x76e2db: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036e8fd(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76e8fd: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x76e8ff: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x76e903: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x76e907: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x76e90b: e804000000 CALL 0x0076e914
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x76e910: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x76e913: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036eb19(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76eb19: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x76eb1b: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x76eb1f: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x76eb23: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x76eb27: e8e8fdffff CALL 0x0076e914
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x76eb2c: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x76eb2f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036f385(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f385: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  { // 0x76f387: ff74240c PUSH dword ptr [ESP + 0xc]
    f.push(m,m.r32((f.sp+0x0000000cu)));
  }
  { // 0x76f38b: ff74240c PUSH dword ptr [ESP + 0xc]
    f.push(m,m.r32((f.sp+0x0000000cu)));
  }
  { // 0x76f38f: e8c0ffffff CALL 0x0076f354
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x76f394: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x76f397: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036f4b1(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f4b1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x76f4b2: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x76f4b4: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x76f4b7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f4b8: 894508 MOV dword ptr [EBP + 0x8],EAX
    m.w32((s.bp+0x00000008u), s.ax);
  }
  { // 0x76f4bb: 8d4508 LEA EAX,[EBP + 0x8]
    s.ax = (s.bp+0x00000008u);
  }
  { // 0x76f4be: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x76f4c0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76f4c1: e895750000 CALL 0x00776a5b
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x76f4c6: c70608c67900 MOV dword ptr [ESI],0x79c608
    m.w32((s.si), 0x0079c608u);
  }
  { // 0x76f4cc: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76f4ce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f4cf: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x76f4d0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0036f4f4(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f4f4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f4f5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x76f4f7: ff742408 PUSH dword ptr [ESP + 0x8]
    f.push(m,m.r32((f.sp+0x00000008u)));
  }
  { // 0x76f4fb: e898750000 CALL 0x00776a98
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x76f500: c70608c67900 MOV dword ptr [ESI],0x79c608
    m.w32((s.si), 0x0079c608u);
  }
  { // 0x76f506: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76f508: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f509: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0036f50c(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f50c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f50d: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x76f50f: ff742408 PUSH dword ptr [ESP + 0x8]
    f.push(m,m.r32((f.sp+0x00000008u)));
  }
  { // 0x76f513: e880750000 CALL 0x00776a98
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x76f518: c70614c67900 MOV dword ptr [ESI],0x79c614
    m.w32((s.si), 0x0079c614u);
  }
  { // 0x76f51e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76f520: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f521: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0036f60b(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f60b: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x76f60f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f610: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x76f612: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76f613: e843740000 CALL 0x00776a5b
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x76f618: c70614c67900 MOV dword ptr [ESI],0x79c614
    m.w32((s.si), 0x0079c614u);
  }
  { // 0x76f61e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76f620: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f621: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0036f73b(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f73b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f73c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x76f73e: ff742408 PUSH dword ptr [ESP + 0x8]
    f.push(m,m.r32((f.sp+0x00000008u)));
  }
  { // 0x76f742: e814730000 CALL 0x00776a5b
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x76f747: c70698c67900 MOV dword ptr [ESI],0x79c698
    m.w32((s.si), 0x0079c698u);
  }
  { // 0x76f74d: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76f74f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f750: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0036f774(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f774: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f775: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x76f777: ff742408 PUSH dword ptr [ESP + 0x8]
    f.push(m,m.r32((f.sp+0x00000008u)));
  }
  { // 0x76f77b: e818730000 CALL 0x00776a98
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x76f780: c70698c67900 MOV dword ptr [ESI],0x79c698
    m.w32((s.si), 0x0079c698u);
  }
  { // 0x76f786: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76f788: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f789: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0036fd39(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76fd39: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x76fd3a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fd3b: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x76fd3f: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x76fd41: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76fd42: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x76fd45: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x76fd47: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x76fd4a: 80f902 CMP CL,0x2
    (void)integer::sub((s.cx & 0xffu),0x00000002u,8,flags);
  }
  { // 0x76fd4d: 7537 JNZ 0x0076fd86
    if(integer::condition("JNZ",flags)) goto L0076fd86;
  }
  { // 0x76fd4f: 66a90801 TEST AX,0x108
    (void)integer::logical(((s.ax & 0xffffu))&(0x00000108u),16,flags);
  }
  { // 0x76fd53: 7431 JZ 0x0076fd86
    if(integer::condition("JZ",flags)) goto L0076fd86;
  }
  { // 0x76fd55: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x76fd58: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x76fd5a: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x76fd5c: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x76fd5e: 7e26 JLE 0x0076fd86
    if(integer::condition("JLE",flags)) goto L0076fd86;
  }
  { // 0x76fd60: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76fd61: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76fd62: ff7610 PUSH dword ptr [ESI + 0x10]
    f.push(m,m.r32((s.si+0x00000010u)));
  }
  { // 0x76fd65: e8ab4b0000 CALL 0x00774915
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x76fd6a: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x76fd6d: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x76fd6f: 750e JNZ 0x0076fd7f
    if(integer::condition("JNZ",flags)) goto L0076fd7f;
  }
  { // 0x76fd71: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x76fd74: a880 TEST AL,0x80
    (void)integer::logical(((s.ax & 0xffu))&(0x00000080u),8,flags);
  }
  { // 0x76fd76: 740e JZ 0x0076fd86
    if(integer::condition("JZ",flags)) goto L0076fd86;
  }
  { // 0x76fd78: 24fd AND AL,0xfd
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fdu),8,flags));
  }
  { // 0x76fd7a: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  { // 0x76fd7d: eb07 JMP 0x0076fd86
    goto L0076fd86;
  }
  L0076fd7f: { // 0x76fd7f: 834e0c20 OR dword ptr [ESI + 0xc],0x20
    m.w32((s.si+0x0000000cu), integer::logical((m.r32((s.si+0x0000000cu)))|(0x00000020u),32,flags));
  }
  { // 0x76fd83: 83cbff OR EBX,0xffffffff
    s.bx = integer::logical((s.bx)|(0xffffffffu),32,flags);
  }
  L0076fd86: { // 0x76fd86: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x76fd89: 83660400 AND dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), integer::logical((m.r32((s.si+0x00000004u)))&(0x00000000u),32,flags));
  }
  { // 0x76fd8d: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x76fd8f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x76fd90: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x76fd92: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76fd93: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x76fd94: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036ffdd(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76ffdd: e8e94f0000 CALL 0x00774fcb
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x76ffe2: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x76ffe6: 894814 MOV dword ptr [EAX + 0x14],ECX
    m.w32((s.ax+0x00000014u), s.cx);
  }
  { // 0x76ffe9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036ffea(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76ffea: e8dc4f0000 CALL 0x00774fcb
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x76ffef: 8b4814 MOV ECX,dword ptr [EAX + 0x14]
    s.cx = m.r32((s.ax+0x00000014u));
  }
  { // 0x76fff2: 69c9fd430300 IMUL ECX,ECX,0x343fd
    s.cx = integer::imul(s.cx,0x000343fdu,32,flags);
  }
  { // 0x76fff8: 81c1c39e2600 ADD ECX,0x269ec3
    s.cx = integer::add(s.cx,0x00269ec3u,32,flags);
  }
  { // 0x76fffe: 894814 MOV dword ptr [EAX + 0x14],ECX
    m.w32((s.ax+0x00000014u), s.cx);
  }
  { // 0x770001: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x770003: c1e810 SHR EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::right);
  }
  { // 0x770006: 25ff7f0000 AND EAX,0x7fff
    s.ax = integer::logical((s.ax)&(0x00007fffu),32,flags);
  }
  { // 0x77000b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037033c(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77033c: ff742404 PUSH dword ptr [ESP + 0x4]
    f.push(m,m.r32((f.sp+0x00000004u)));
  }
  { // 0x770340: e8c6ffffff CALL 0x0077030b
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x770345: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770346: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003703a8(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7703a8: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x7703aa: ff742408 PUSH dword ptr [ESP + 0x8]
    f.push(m,m.r32((f.sp+0x00000008u)));
  }
  { // 0x7703ae: e82d710000 CALL 0x007774e0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x7703b3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7703b4: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7703b5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003703e6(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7703e6: 6817010000 PUSH 0x117
    f.push(m,0x00000117u);
  }
  { // 0x7703eb: ff742408 PUSH dword ptr [ESP + 0x8]
    f.push(m,m.r32((f.sp+0x00000008u)));
  }
  { // 0x7703ef: e8ec700000 CALL 0x007774e0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x7703f4: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7703f5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7703f6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003704b8(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7704b8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x7704ba: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x7704be: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x7704c2: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x7704c6: e804000000 CALL 0x007704cf
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x7704cb: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x7704ce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00370676(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x770676: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x770678: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x77067c: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x770680: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x770684: e846feffff CALL 0x007704cf
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x770689: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x77068c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003707dc(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7707dc: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x7707de: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x7707e0: ff74240c PUSH dword ptr [ESP + 0xc]
    f.push(m,m.r32((f.sp+0x0000000cu)));
  }
  { // 0x7707e4: e833000000 CALL 0x0077081c
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x7707e9: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x7707ec: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003707ed(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7707ed: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x7707ef: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x7707f1: ff74240c PUSH dword ptr [ESP + 0xc]
    f.push(m,m.r32((f.sp+0x0000000cu)));
  }
  { // 0x7707f5: e822000000 CALL 0x0077081c
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x7707fa: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x7707fd: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003708c1(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7708c1: 6a0d PUSH 0xd
    f.push(m,0x0000000du);
  }
  { // 0x7708c3: e8ee0c0000 CALL 0x007715b6
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x7708c8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7708c9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003708ca(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7708ca: 6a0d PUSH 0xd
    f.push(m,0x0000000du);
  }
  { // 0x7708cc: e8460d0000 CALL 0x00771617
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x7708d1: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7708d2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00370949(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x770949: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x77094d: 25fffff7ff AND EAX,0xfff7ffff
    s.ax = integer::logical((s.ax)&(0xfff7ffffu),32,flags);
  }
  { // 0x770952: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x770953: ff742408 PUSH dword ptr [ESP + 0x8]
    f.push(m,m.r32((f.sp+0x00000008u)));
  }
  { // 0x770957: e8b8ffffff CALL 0x00770914
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x77095c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77095d: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77095e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00370adc(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x770adc: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x770add: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x770adf: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x770ae0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770ae1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x770ae2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x770ae3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x770ae5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x770ae7: 68f40a7700 PUSH 0x770af4
    f.push(m,0x00770af4u);
  }
  { // 0x770aec: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x770aef: e8d60e0100 CALL 0x007819ca
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x770af4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x770af5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x770af6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x770af7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x770af8: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  { // 0x770afa: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x770afb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00370c91(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x770c91: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x770c92: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x770c96: 8b29 MOV EBP,dword ptr [ECX]
    s.bp = m.r32((s.cx));
  }
  { // 0x770c98: 8b411c MOV EAX,dword ptr [ECX + 0x1c]
    s.ax = m.r32((s.cx+0x0000001cu));
  }
  { // 0x770c9b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x770c9c: 8b4118 MOV EAX,dword ptr [ECX + 0x18]
    s.ax = m.r32((s.cx+0x00000018u));
  }
  { // 0x770c9f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x770ca0: e879feffff CALL 0x00770b1e
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x770ca5: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x770ca8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x770ca9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00370fa2(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x770fa2: ff742404 PUSH dword ptr [ESP + 0x4]
    f.push(m,m.r32((f.sp+0x00000004u)));
  }
  { // 0x770fa6: e8cdffffff CALL 0x00770f78
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x770fab: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770fac: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003725a6(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7725a6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7725a7: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7725a9: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  { // 0x7725ac: ff4904 DEC dword ptr [ECX + 0x4]
    m.w32((s.cx+0x00000004u), integer::decrement(m.r32((s.cx+0x00000004u)),32,flags));
  }
  { // 0x7725af: 780e JS 0x007725bf
    if(integer::condition("JS",flags)) goto L007725bf;
  }
  { // 0x7725b1: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x7725b3: 8a4508 MOV AL,byte ptr [EBP + 0x8]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000008u)));
  }
  { // 0x7725b6: 8802 MOV byte ptr [EDX],AL
    m.w8((s.dx), (s.ax & 0xffu));
  }
  { // 0x7725b8: ff01 INC dword ptr [ECX]
    m.w32((s.cx), integer::increment(m.r32((s.cx)),32,flags));
  }
  { // 0x7725ba: 0fb6c0 MOVZX EAX,AL
    s.ax = ((s.ax & 0xffu)&integer::mask(8));
  }
  { // 0x7725bd: eb0b JMP 0x007725ca
    goto L007725ca;
  }
  L007725bf: { // 0x7725bf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7725c0: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x7725c3: e885f7ffff CALL 0x00771d4d
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x7725c8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7725c9: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007725ca: { // 0x7725ca: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x7725cd: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  { // 0x7725d0: 7505 JNZ 0x007725d7
    if(integer::condition("JNZ",flags)) goto L007725d7;
  }
  { // 0x7725d2: 8308ff OR dword ptr [EAX],0xffffffff
    m.w32((s.ax), integer::logical((m.r32((s.ax)))|(0xffffffffu),32,flags));
  }
  { // 0x7725d5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x7725d6: c3 RET
    finish(m,s,f,0u); return;
  }
  L007725d7: { // 0x7725d7: ff00 INC dword ptr [EAX]
    m.w32((s.ax), integer::increment(m.r32((s.ax)),32,flags));
  }
  { // 0x7725d9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x7725da: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037266f(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77266f: 6800000300 PUSH 0x30000
    f.push(m,0x00030000u);
  }
  { // 0x772674: 6800000100 PUSH 0x10000
    f.push(m,0x00010000u);
  }
  { // 0x772679: e8cbe2ffff CALL 0x00770949
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x77267e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77267f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x772680: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00374ed1(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x774ed1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x774ed2: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x774ed4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x774ed5: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x774ed8: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  { // 0x774edb: 81f900010000 CMP ECX,0x100
    (void)integer::sub(s.cx,0x00000100u,32,flags);
  }
  { // 0x774ee1: 770c JA 0x00774eef
    if(integer::condition("JA",flags)) goto L00774eef;
  }
  { // 0x774ee3: 8b0d60758100 MOV ECX,dword ptr [0x00817560]
    s.cx = m.r32((0x00817560u));
  }
  { // 0x774ee9: 0fb70441 MOVZX EAX,word ptr [ECX + EAX*0x2]
    s.ax = (m.r16((s.cx+(s.ax * 0x00000002u)))&integer::mask(16));
  }
  { // 0x774eed: eb52 JMP 0x00774f41
    goto L00774f41;
  }
  L00774eef: { // 0x774eef: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x774ef1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x774ef2: 8b3560758100 MOV ESI,dword ptr [0x00817560]
    s.si = m.r32((0x00817560u));
  }
  { // 0x774ef8: c1f908 SAR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x774efb: 0fb6d1 MOVZX EDX,CL
    s.dx = ((s.cx & 0xffu)&integer::mask(8));
  }
  { // 0x774efe: f644560180 TEST byte ptr [ESI + EDX*0x2 + 0x1],0x80
    (void)integer::logical((m.r8((s.si+(s.dx * 0x00000002u)+0x00000001u)))&(0x00000080u),8,flags);
  }
  { // 0x774f03: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x774f04: 740e JZ 0x00774f14
    if(integer::condition("JZ",flags)) goto L00774f14;
  }
  { // 0x774f06: 8065fe00 AND byte ptr [EBP + -0x2],0x0
    m.w8((s.bp-0x00000002u), integer::logical((m.r8((s.bp-0x00000002u)))&(0x00000000u),8,flags));
  }
  { // 0x774f0a: 884dfc MOV byte ptr [EBP + -0x4],CL
    m.w8((s.bp-0x00000004u), (s.cx & 0xffu));
  }
  { // 0x774f0d: 8845fd MOV byte ptr [EBP + -0x3],AL
    m.w8((s.bp-0x00000003u), (s.ax & 0xffu));
  }
  { // 0x774f10: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x774f12: eb09 JMP 0x00774f1d
    goto L00774f1d;
  }
  L00774f14: { // 0x774f14: 8065fd00 AND byte ptr [EBP + -0x3],0x0
    m.w8((s.bp-0x00000003u), integer::logical((m.r8((s.bp-0x00000003u)))&(0x00000000u),8,flags));
  }
  { // 0x774f18: 8845fc MOV byte ptr [EBP + -0x4],AL
    m.w8((s.bp-0x00000004u), (s.ax & 0xffu));
  }
  { // 0x774f1b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00774f1d: { // 0x774f1d: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  { // 0x774f1e: 8d4d0a LEA ECX,[EBP + 0xa]
    s.cx = (s.bp+0x0000000au);
  }
  { // 0x774f21: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x774f23: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x774f25: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x774f27: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x774f28: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x774f29: 8d45fc LEA EAX,[EBP + -0x4]
    s.ax = (s.bp-0x00000004u);
  }
  { // 0x774f2c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x774f2d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x774f2f: e87b860000 CALL 0x0077d5af
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x774f34: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  { // 0x774f37: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x774f39: 7502 JNZ 0x00774f3d
    if(integer::condition("JNZ",flags)) goto L00774f3d;
  }
  { // 0x774f3b: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x774f3c: c3 RET
    finish(m,s,f,0u); return;
  }
  L00774f3d: { // 0x774f3d: 0fb7450a MOVZX EAX,word ptr [EBP + 0xa]
    s.ax = (m.r16((s.bp+0x0000000au))&integer::mask(16));
  }
  L00774f41: { // 0x774f41: 23450c AND EAX,dword ptr [EBP + 0xc]
    s.ax = integer::logical((s.ax)&(m.r32((s.bp+0x0000000cu))),32,flags);
  }
  { // 0x774f44: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x774f45: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037524e(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77524e: e878fdffff CALL 0x00774fcb
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x775253: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  { // 0x775256: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00375257(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x775257: e86ffdffff CALL 0x00774fcb
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x77525c: 83c00c ADD EAX,0xc
    s.ax = integer::add(s.ax,0x0000000cu,32,flags);
  }
  { // 0x77525f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003764cb(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7764cb: ff742408 PUSH dword ptr [ESP + 0x8]
    f.push(m,m.r32((f.sp+0x00000008u)));
  }
  { // 0x7764cf: ff742408 PUSH dword ptr [ESP + 0x8]
    f.push(m,m.r32((f.sp+0x00000008u)));
  }
  { // 0x7764d3: e8b0060000 CALL 0x00776b88
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x7764d8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7764d9: 663dffff CMP AX,0xffff
    (void)integer::sub((s.ax & 0xffffu),0x0000ffffu,16,flags);
  }
  { // 0x7764dd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x7764e1: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7764e2: 7504 JNZ 0x007764e8
    if(integer::condition("JNZ",flags)) goto L007764e8;
  }
  { // 0x7764e4: 8308ff OR dword ptr [EAX],0xffffffff
    m.w32((s.ax), integer::logical((m.r32((s.ax)))|(0xffffffffu),32,flags));
  }
  { // 0x7764e7: c3 RET
    finish(m,s,f,0u); return;
  }
  L007764e8: { // 0x7764e8: ff00 INC dword ptr [EAX]
    m.w32((s.ax), integer::increment(m.r32((s.ax)),32,flags));
  }
  { // 0x7764ea: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00376714(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x776714: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x776715: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x776719: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x77671c: a883 TEST AL,0x83
    (void)integer::logical(((s.ax & 0xffu))&(0x00000083u),8,flags);
  }
  { // 0x77671e: 741d JZ 0x0077673d
    if(integer::condition("JZ",flags)) goto L0077673d;
  }
  { // 0x776720: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  { // 0x776722: 7419 JZ 0x0077673d
    if(integer::condition("JZ",flags)) goto L0077673d;
  }
  { // 0x776724: ff7608 PUSH dword ptr [ESI + 0x8]
    f.push(m,m.r32((s.si+0x00000008u)));
  }
  { // 0x776727: e8fc77ffff CALL 0x0076df28
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x77672c: 6681660cf7fb AND word ptr [ESI + 0xc],0xfbf7
    m.w16((s.si+0x0000000cu), integer::logical((m.r16((s.si+0x0000000cu)))&(0x0000fbf7u),16,flags));
  }
  { // 0x776732: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x776734: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x776735: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x776737: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x77673a: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0077673d: { // 0x77673d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77673e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003767cc(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7767cc: 837c240400 CMP dword ptr [ESP + 0x4],0x0
    (void)integer::sub(m.r32((f.sp+0x00000004u)),0x00000000u,32,flags);
  }
  { // 0x7767d1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7767d2: 7420 JZ 0x007767f4
    if(integer::condition("JZ",flags)) goto L007767f4;
  }
  { // 0x7767d4: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x7767d8: f6460d10 TEST byte ptr [ESI + 0xd],0x10
    (void)integer::logical((m.r8((s.si+0x0000000du)))&(0x00000010u),8,flags);
  }
  { // 0x7767dc: 7416 JZ 0x007767f4
    if(integer::condition("JZ",flags)) goto L007767f4;
  }
  { // 0x7767de: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7767df: e85595ffff CALL 0x0076fd39
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x7767e4: 80660dee AND byte ptr [ESI + 0xd],0xee
    m.w8((s.si+0x0000000du), integer::logical((m.r8((s.si+0x0000000du)))&(0x000000eeu),8,flags));
  }
  { // 0x7767e8: 83661800 AND dword ptr [ESI + 0x18],0x0
    m.w32((s.si+0x00000018u), integer::logical((m.r32((s.si+0x00000018u)))&(0x00000000u),32,flags));
  }
  { // 0x7767ec: 832600 AND dword ptr [ESI],0x0
    m.w32((s.si), integer::logical((m.r32((s.si)))&(0x00000000u),32,flags));
  }
  { // 0x7767ef: 83660800 AND dword ptr [ESI + 0x8],0x0
    m.w32((s.si+0x00000008u), integer::logical((m.r32((s.si+0x00000008u)))&(0x00000000u),32,flags));
  }
  { // 0x7767f3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007767f4: { // 0x7767f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7767f5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037742a(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77742a: 833d300eb10000 CMP dword ptr [0x00b10e30],0x0
    (void)integer::sub(m.r32((0x00b10e30u)),0x00000000u,32,flags);
  }
  { // 0x777431: 7512 JNZ 0x00777445
    if(integer::condition("JNZ",flags)) goto L00777445;
  }
  { // 0x777433: 6afd PUSH -0x3
    f.push(m,0xfffffffdu);
  }
  { // 0x777435: e808fcffff CALL 0x00777042
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x77743a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77743b: c705300eb10001000000 MOV dword ptr [0x00b10e30],0x1
    m.w32((0x00b10e30u), 0x00000001u);
  }
  L00777445: { // 0x777445: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003774e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7774e0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7774e1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7774e3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7774e4: 66817d08ffff CMP word ptr [EBP + 0x8],0xffff
    (void)integer::sub(m.r16((s.bp+0x00000008u)),0x0000ffffu,16,flags);
  }
  { // 0x7774ea: 7434 JZ 0x00777520
    if(integer::condition("JZ",flags)) goto L00777520;
  }
  { // 0x7774ec: 66817d080001 CMP word ptr [EBP + 0x8],0x100
    (void)integer::sub(m.r16((s.bp+0x00000008u)),0x00000100u,16,flags);
  }
  { // 0x7774f2: 7310 JNC 0x00777504
    if(integer::condition("JNC",flags)) goto L00777504;
  }
  { // 0x7774f4: 0fb74508 MOVZX EAX,word ptr [EBP + 0x8]
    s.ax = (m.r16((s.bp+0x00000008u))&integer::mask(16));
  }
  { // 0x7774f8: 8b0d64758100 MOV ECX,dword ptr [0x00817564]
    s.cx = m.r32((0x00817564u));
  }
  { // 0x7774fe: 668b0441 MOV AX,word ptr [ECX + EAX*0x2]
    s.ax = with_ax(s.ax, m.r16((s.cx+(s.ax * 0x00000002u))));
  }
  { // 0x777502: eb23 JMP 0x00777527
    goto L00777527;
  }
  L00777504: { // 0x777504: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x777506: 8d45fc LEA EAX,[EBP + -0x4]
    s.ax = (s.bp-0x00000004u);
  }
  { // 0x777509: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x77750b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77750c: 8d4508 LEA EAX,[EBP + 0x8]
    s.ax = (s.bp+0x00000008u);
  }
  { // 0x77750f: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x777511: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x777512: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x777514: e830700000 CALL 0x0077e549
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x777519: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  { // 0x77751c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77751e: 7504 JNZ 0x00777524
    if(integer::condition("JNZ",flags)) goto L00777524;
  }
  L00777520: { // 0x777520: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x777522: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x777523: c3 RET
    finish(m,s,f,0u); return;
  }
  L00777524: { // 0x777524: 8b45fc MOV EAX,dword ptr [EBP + -0x4]
    s.ax = m.r32((s.bp-0x00000004u));
  }
  L00777527: { // 0x777527: 0fb74d0c MOVZX ECX,word ptr [EBP + 0xc]
    s.cx = (m.r16((s.bp+0x0000000cu))&integer::mask(16));
  }
  { // 0x77752b: 0fb7c0 MOVZX EAX,AX
    s.ax = ((s.ax & 0xffffu)&integer::mask(16));
  }
  { // 0x77752e: 23c1 AND EAX,ECX
    s.ax = integer::logical((s.ax)&(s.cx),32,flags);
  }
  { // 0x777530: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x777531: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00378156(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x778156: ff742404 PUSH dword ptr [ESP + 0x4]
    f.push(m,m.r32((f.sp+0x00000004u)));
  }
  { // 0x77815a: e8466a0000 CALL 0x0077eba5
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x77815f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x778160: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00378161(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x778161: 66817c2404ffff CMP word ptr [ESP + 0x4],0xffff
    (void)integer::sub(m.r16((f.sp+0x00000004u)),0x0000ffffu,16,flags);
  }
  { // 0x778168: 740f JZ 0x00778179
    if(integer::condition("JZ",flags)) goto L00778179;
  }
  { // 0x77816a: ff742408 PUSH dword ptr [ESP + 0x8]
    f.push(m,m.r32((f.sp+0x00000008u)));
  }
  { // 0x77816e: ff742408 PUSH dword ptr [ESP + 0x8]
    f.push(m,m.r32((f.sp+0x00000008u)));
  }
  { // 0x778172: e8546b0000 CALL 0x0077eccb
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x778177: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x778178: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00778179: { // 0x778179: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037819f(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77819f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7781a0: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7781a2: 837d1000 CMP dword ptr [EBP + 0x10],0x0
    (void)integer::sub(m.r32((s.bp+0x00000010u)),0x00000000u,32,flags);
  }
  { // 0x7781a6: 7504 JNZ 0x007781ac
    if(integer::condition("JNZ",flags)) goto L007781ac;
  }
  { // 0x7781a8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x7781aa: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x7781ab: c3 RET
    finish(m,s,f,0u); return;
  }
  L007781ac: { // 0x7781ac: ff35c80ab100 PUSH dword ptr [0x00b10ac8]
    f.push(m,m.r32((0x00b10ac8u)));
  }
  { // 0x7781b2: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x7781b5: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x7781b8: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x7781bb: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x7781be: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x7781c0: ff35e40cb100 PUSH dword ptr [0x00b10ce4]
    f.push(m,m.r32((0x00b10ce4u)));
  }
  { // 0x7781c6: e8ed6b0000 CALL 0x0077edb8
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x7781cb: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  { // 0x7781ce: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7781d0: 7507 JNZ 0x007781d9
    if(integer::condition("JNZ",flags)) goto L007781d9;
  }
  { // 0x7781d2: b8ffffff7f MOV EAX,0x7fffffff
    s.ax = 0x7fffffffu;
  }
  { // 0x7781d7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x7781d8: c3 RET
    finish(m,s,f,0u); return;
  }
  L007781d9: { // 0x7781d9: 83c0fe ADD EAX,-0x2
    s.ax = integer::add(s.ax,0xfffffffeu,32,flags);
  }
  { // 0x7781dc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x7781dd: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00379171(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x779171: ff74240c PUSH dword ptr [ESP + 0xc]
    f.push(m,m.r32((f.sp+0x0000000cu)));
  }
  { // 0x779175: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  { // 0x779177: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x77917b: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x77917f: e804000000 CALL 0x00779188
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x779184: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x779187: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00379457(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x779457: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x779458: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77945a: 837d100a CMP dword ptr [EBP + 0x10],0xa
    (void)integer::sub(m.r32((s.bp+0x00000010u)),0x0000000au,32,flags);
  }
  { // 0x77945e: 750c JNZ 0x0077946c
    if(integer::condition("JNZ",flags)) goto L0077946c;
  }
  { // 0x779460: 837d0800 CMP dword ptr [EBP + 0x8],0x0
    (void)integer::sub(m.r32((s.bp+0x00000008u)),0x00000000u,32,flags);
  }
  { // 0x779464: 7d06 JGE 0x0077946c
    if(integer::condition("JGE",flags)) goto L0077946c;
  }
  { // 0x779466: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x779468: 6a0a PUSH 0xa
    f.push(m,0x0000000au);
  }
  { // 0x77946a: eb05 JMP 0x00779471
    goto L00779471;
  }
  L0077946c: { // 0x77946c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x77946e: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  L00779471: { // 0x779471: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x779474: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x779477: e808000000 CALL 0x00779484
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x77947c: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x77947f: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x779482: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x779483: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003794e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7794e0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7794e1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7794e3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x7794e5: 837d100a CMP dword ptr [EBP + 0x10],0xa
    (void)integer::sub(m.r32((s.bp+0x00000010u)),0x0000000au,32,flags);
  }
  { // 0x7794e9: 7508 JNZ 0x007794f3
    if(integer::condition("JNZ",flags)) goto L007794f3;
  }
  { // 0x7794eb: 394508 CMP dword ptr [EBP + 0x8],EAX
    (void)integer::sub(m.r32((s.bp+0x00000008u)),s.ax,32,flags);
  }
  { // 0x7794ee: 7d03 JGE 0x007794f3
    if(integer::condition("JGE",flags)) goto L007794f3;
  }
  { // 0x7794f0: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x7794f2: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L007794f3: { // 0x7794f3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7794f4: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x7794f7: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x7794fa: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x7794fd: e882ffffff CALL 0x00779484
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x779502: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x779505: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x779508: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x779509: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037950a(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77950a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x77950c: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x779510: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x779514: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x779518: e867ffffff CALL 0x00779484
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x77951d: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x779521: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x779524: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00379525(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x779525: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x779526: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x779528: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x77952a: 837d140a CMP dword ptr [EBP + 0x14],0xa
    (void)integer::sub(m.r32((s.bp+0x00000014u)),0x0000000au,32,flags);
  }
  { // 0x77952e: 750f JNZ 0x0077953f
    if(integer::condition("JNZ",flags)) goto L0077953f;
  }
  { // 0x779530: 39450c CMP dword ptr [EBP + 0xc],EAX
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),s.ax,32,flags);
  }
  { // 0x779533: 7f0a JG 0x0077953f
    if(integer::condition("JG",flags)) goto L0077953f;
  }
  { // 0x779535: 7c05 JL 0x0077953c
    if(integer::condition("JL",flags)) goto L0077953c;
  }
  { // 0x779537: 394508 CMP dword ptr [EBP + 0x8],EAX
    (void)integer::sub(m.r32((s.bp+0x00000008u)),s.ax,32,flags);
  }
  { // 0x77953a: 7303 JNC 0x0077953f
    if(integer::condition("JNC",flags)) goto L0077953f;
  }
  L0077953c: { // 0x77953c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77953e: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L0077953f: { // 0x77953f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x779540: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x779543: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x779546: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x779549: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x77954c: e805000000 CALL 0x00779556
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x779551: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  { // 0x779554: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x779555: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003795dc(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7795dc: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7795dd: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7795df: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x7795e1: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x7795e4: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x7795e7: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x7795ea: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x7795ed: e864ffffff CALL 0x00779556
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x7795f2: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  { // 0x7795f5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x7795f6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037b750(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77b750: ff055004b100 INC dword ptr [0x00b10450]
    m.w32((0x00b10450u), integer::increment(m.r32((0x00b10450u)),32,flags));
  }
  { // 0x77b756: 6800100000 PUSH 0x1000
    f.push(m,0x00001000u);
  }
  { // 0x77b75b: e81028ffff CALL 0x0076df70
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x77b760: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77b761: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x77b765: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77b767: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  { // 0x77b76a: 740d JZ 0x0077b779
    if(integer::condition("JZ",flags)) goto L0077b779;
  }
  { // 0x77b76c: 83490c08 OR dword ptr [ECX + 0xc],0x8
    m.w32((s.cx+0x0000000cu), integer::logical((m.r32((s.cx+0x0000000cu)))|(0x00000008u),32,flags));
  }
  { // 0x77b770: c7411800100000 MOV dword ptr [ECX + 0x18],0x1000
    m.w32((s.cx+0x00000018u), 0x00001000u);
  }
  { // 0x77b777: eb11 JMP 0x0077b78a
    goto L0077b78a;
  }
  L0077b779: { // 0x77b779: 83490c04 OR dword ptr [ECX + 0xc],0x4
    m.w32((s.cx+0x0000000cu), integer::logical((m.r32((s.cx+0x0000000cu)))|(0x00000004u),32,flags));
  }
  { // 0x77b77d: 8d4114 LEA EAX,[ECX + 0x14]
    s.ax = (s.cx+0x00000014u);
  }
  { // 0x77b780: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  { // 0x77b783: c7411802000000 MOV dword ptr [ECX + 0x18],0x2
    m.w32((s.cx+0x00000018u), 0x00000002u);
  }
  L0077b78a: { // 0x77b78a: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  { // 0x77b78d: 83610400 AND dword ptr [ECX + 0x4],0x0
    m.w32((s.cx+0x00000004u), integer::logical((m.r32((s.cx+0x00000004u)))&(0x00000000u),32,flags));
  }
  { // 0x77b791: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  { // 0x77b793: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037bc5b(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77bc5b: 68e0838100 PUSH 0x8183e0
    f.push(m,0x008183e0u);
  }
  { // 0x77bc60: ff74240c PUSH dword ptr [ESP + 0xc]
    f.push(m,m.r32((f.sp+0x0000000cu)));
  }
  { // 0x77bc64: ff74240c PUSH dword ptr [ESP + 0xc]
    f.push(m,m.r32((f.sp+0x0000000cu)));
  }
  { // 0x77bc68: e882feffff CALL 0x0077baef
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x77bc6d: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77bc70: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037bc71(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77bc71: 68f8838100 PUSH 0x8183f8
    f.push(m,0x008183f8u);
  }
  { // 0x77bc76: ff74240c PUSH dword ptr [ESP + 0xc]
    f.push(m,m.r32((f.sp+0x0000000cu)));
  }
  { // 0x77bc7a: ff74240c PUSH dword ptr [ESP + 0xc]
    f.push(m,m.r32((f.sp+0x0000000cu)));
  }
  { // 0x77bc7e: e86cfeffff CALL 0x0077baef
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x77bc83: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77bc86: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037bc87(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77bc87: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77bc88: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77bc8a: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x77bc8d: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x77bc90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77bc91: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77bc92: 8365fc00 AND dword ptr [EBP + -0x4],0x0
    m.w32((s.bp-0x00000004u), integer::logical((m.r32((s.bp-0x00000004u)))&(0x00000000u),32,flags));
  }
  { // 0x77bc96: 668b480a MOV CX,word ptr [EAX + 0xa]
    s.cx = with_ax(s.cx, m.r16((s.ax+0x0000000au)));
  }
  { // 0x77bc9a: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  { // 0x77bc9c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x77bc9e: 81e100800000 AND ECX,0x8000
    s.cx = integer::logical((s.cx)&(0x00008000u),32,flags);
  }
  { // 0x77bca4: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x77bca6: 8b4806 MOV ECX,dword ptr [EAX + 0x6]
    s.cx = m.r32((s.ax+0x00000006u));
  }
  { // 0x77bca9: 894df0 MOV dword ptr [EBP + -0x10],ECX
    m.w32((s.bp-0x00000010u), s.cx);
  }
  { // 0x77bcac: 8b4802 MOV ECX,dword ptr [EAX + 0x2]
    s.cx = m.r32((s.ax+0x00000002u));
  }
  { // 0x77bcaf: 0fb700 MOVZX EAX,word ptr [EAX]
    s.ax = (m.r16((s.ax))&integer::mask(16));
  }
  { // 0x77bcb2: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  { // 0x77bcb5: 8945f8 MOV dword ptr [EBP + -0x8],EAX
    m.w32((s.bp-0x00000008u), s.ax);
  }
  { // 0x77bcb8: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  { // 0x77bcbb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bcbc: 81e6ff7f0000 AND ESI,0x7fff
    s.si = integer::logical((s.si)&(0x00007fffu),32,flags);
  }
  { // 0x77bcc2: 894df4 MOV dword ptr [EBP + -0xc],ECX
    m.w32((s.bp-0x0000000cu), s.cx);
  }
  { // 0x77bcc5: e8cafcffff CALL 0x0077b994
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x77bcca: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77bccb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77bccd: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77bcce: 7408 JZ 0x0077bcd8
    if(integer::condition("JZ",flags)) goto L0077bcd8;
  }
  { // 0x77bcd0: b900000080 MOV ECX,0x80000000
    s.cx = 0x80000000u;
  }
  { // 0x77bcd5: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x77bcd6: eb03 JMP 0x0077bcdb
    goto L0077bcdb;
  }
  L0077bcd8: { // 0x77bcd8: 8b4df0 MOV ECX,dword ptr [EBP + -0x10]
    s.cx = m.r32((s.bp-0x00000010u));
  }
  L0077bcdb: { // 0x77bcdb: 6681feff7f CMP SI,0x7fff
    (void)integer::sub((s.si & 0xffffu),0x00007fffu,16,flags);
  }
  { // 0x77bce0: 7507 JNZ 0x0077bce9
    if(integer::condition("JNZ",flags)) goto L0077bce9;
  }
  { // 0x77bce2: c745fc01000000 MOV dword ptr [EBP + -0x4],0x1
    m.w32((s.bp-0x00000004u), 0x00000001u);
  }
  L0077bce9: { // 0x77bce9: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x77bcec: 0bfe OR EDI,ESI
    s.di = integer::logical((s.di)|(s.si),32,flags);
  }
  { // 0x77bcee: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  { // 0x77bcf1: 8b4df4 MOV ECX,dword ptr [EBP + -0xc]
    s.cx = m.r32((s.bp-0x0000000cu));
  }
  { // 0x77bcf4: 66897808 MOV word ptr [EAX + 0x8],DI
    m.w16((s.ax+0x00000008u), (s.di & 0xffffu));
  }
  { // 0x77bcf8: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x77bcfa: 8b45fc MOV EAX,dword ptr [EBP + -0x4]
    s.ax = m.r32((s.bp-0x00000004u));
  }
  { // 0x77bcfd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77bcfe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77bcff: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77bd00: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037bf12(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77bf12: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x77bf14: e8bf55ffff CALL 0x007714d8
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x77bf19: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77bf1a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037f5c5(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77f5c5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x77f5c7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x77f5c9: ff74240c PUSH dword ptr [ESP + 0xc]
    f.push(m,m.r32((f.sp+0x0000000cu)));
  }
  { // 0x77f5cd: e83c000000 CALL 0x0077f60e
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x77f5d2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77f5d5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037ff49(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77ff49: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77ff4a: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77ff4c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x77ff4d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x77ff4f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77ff50: 3905c40ab100 CMP dword ptr [0x00b10ac4],EAX
    (void)integer::sub(m.r32((0x00b10ac4u)),s.ax,32,flags);
  }
  { // 0x77ff56: 8945fc MOV dword ptr [EBP + -0x4],EAX
    m.w32((s.bp-0x00000004u), s.ax);
  }
  { // 0x77ff59: 7413 JZ 0x0077ff6e
    if(integer::condition("JZ",flags)) goto L0077ff6e;
  }
  { // 0x77ff5b: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x77ff5e: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x77ff61: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x77ff64: e84f000000 CALL 0x0077ffb8
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x77ff69: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77ff6c: eb47 JMP 0x0077ffb5
    goto L0077ffb5;
  }
  L0077ff6e: { // 0x77ff6e: 8b7d14 MOV EDI,dword ptr [EBP + 0x14]
    s.di = m.r32((s.bp+0x00000014u));
  }
  { // 0x77ff71: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  { // 0x77ff74: 3b0f CMP ECX,dword ptr [EDI]
    (void)integer::sub(s.cx,m.r32((s.di)),32,flags);
  }
  { // 0x77ff76: 733b JNC 0x0077ffb3
    if(integer::condition("JNC",flags)) goto L0077ffb3;
  }
  { // 0x77ff78: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x77ff79: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77ff7a: 8b7510 MOV ESI,dword ptr [EBP + 0x10]
    s.si = m.r32((s.bp+0x00000010u));
  }
  { // 0x77ff7d: 8d4101 LEA EAX,[ECX + 0x1]
    s.ax = (s.cx+0x00000001u);
  }
  { // 0x77ff80: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77ff82: 7425 JZ 0x0077ffa9
    if(integer::condition("JZ",flags)) goto L0077ffa9;
  }
  { // 0x77ff84: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0077ff85: { // 0x77ff85: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x77ff88: 6a0a PUSH 0xa
    f.push(m,0x0000000au);
  }
  { // 0x77ff8a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x77ff8b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x77ff8c: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  { // 0x77ff8e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x77ff90: 80c230 ADD DL,0x30
    s.dx = with_al(s.dx, integer::add((s.dx & 0xffu),0x00000030u,8,flags));
  }
  { // 0x77ff93: 881408 MOV byte ptr [EAX + ECX*0x1],DL
    m.w8((s.ax+(s.cx * 0x00000001u)), (s.dx & 0xffu));
  }
  { // 0x77ff96: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x77ff99: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x77ff9a: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  { // 0x77ff9c: ff45fc INC dword ptr [EBP + -0x4]
    m.w32((s.bp-0x00000004u), integer::increment(m.r32((s.bp-0x00000004u)),32,flags));
  }
  { // 0x77ff9f: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x77ffa0: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  { // 0x77ffa3: 894508 MOV dword ptr [EBP + 0x8],EAX
    m.w32((s.bp+0x00000008u), s.ax);
  }
  { // 0x77ffa6: 75dd JNZ 0x0077ff85
    if(integer::condition("JNZ",flags)) goto L0077ff85;
  }
  { // 0x77ffa8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0077ffa9: { // 0x77ffa9: 8b45fc MOV EAX,dword ptr [EBP + -0x4]
    s.ax = m.r32((s.bp-0x00000004u));
  }
  { // 0x77ffac: 0106 ADD dword ptr [ESI],EAX
    m.w32((s.si), integer::add(m.r32((s.si)),s.ax,32,flags));
  }
  { // 0x77ffae: 2907 SUB dword ptr [EDI],EAX
    m.w32((s.di), integer::sub(m.r32((s.di)),s.ax,32,flags));
  }
  { // 0x77ffb0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77ffb1: eb02 JMP 0x0077ffb5
    goto L0077ffb5;
  }
  L0077ffb3: { // 0x77ffb3: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L0077ffb5: { // 0x77ffb5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77ffb6: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77ffb7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00380fba(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x780fba: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x780fbe: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x780fbf: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x780fc1: 83e01f AND EAX,0x1f
    s.ax = integer::logical((s.ax)&(0x0000001fu),32,flags);
  }
  { // 0x780fc4: c1f905 SAR ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x780fc7: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x780fca: be00800000 MOV ESI,0x8000
    s.si = 0x00008000u;
  }
  { // 0x780fcf: 8b0c8d000db100 MOV ECX,dword ptr [ECX*0x4 + 0xb10d00]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x00b10d00u));
  }
  { // 0x780fd6: 8d548104 LEA EDX,[ECX + EAX*0x4 + 0x4]
    s.dx = (s.cx+(s.ax * 0x00000004u)+0x00000004u);
  }
  { // 0x780fda: 8a4c8104 MOV CL,byte ptr [ECX + EAX*0x4 + 0x4]
    s.cx = with_al(s.cx, m.r8((s.cx+(s.ax * 0x00000004u)+0x00000004u)));
  }
  { // 0x780fde: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  { // 0x780fe0: 2580000000 AND EAX,0x80
    s.ax = integer::logical((s.ax)&(0x00000080u),32,flags);
  }
  { // 0x780fe5: 3974240c CMP dword ptr [ESP + 0xc],ESI
    (void)integer::sub(m.r32((f.sp+0x0000000cu)),s.si,32,flags);
  }
  { // 0x780fe9: 7505 JNZ 0x00780ff0
    if(integer::condition("JNZ",flags)) goto L00780ff0;
  }
  { // 0x780feb: 80e17f AND CL,0x7f
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x0000007fu),8,flags));
  }
  { // 0x780fee: eb0d JMP 0x00780ffd
    goto L00780ffd;
  }
  L00780ff0: { // 0x780ff0: 817c240c00400000 CMP dword ptr [ESP + 0xc],0x4000
    (void)integer::sub(m.r32((f.sp+0x0000000cu)),0x00004000u,32,flags);
  }
  { // 0x780ff8: 7511 JNZ 0x0078100b
    if(integer::condition("JNZ",flags)) goto L0078100b;
  }
  { // 0x780ffa: 80c980 OR CL,0x80
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))|(0x00000080u),8,flags));
  }
  L00780ffd: { // 0x780ffd: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x780fff: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x781001: 880a MOV byte ptr [EDX],CL
    m.w8((s.dx), (s.cx & 0xffu));
  }
  { // 0x781003: 662500c0 AND AX,0xc000
    s.ax = with_ax(s.ax, integer::logical(((s.ax & 0xffffu))&(0x0000c000u),16,flags));
  }
  { // 0x781007: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  { // 0x781009: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x78100a: c3 RET
    finish(m,s,f,0u); return;
  }
  L0078100b: { // 0x78100b: e83e42ffff CALL 0x0077524e
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x781010: c70016000000 MOV dword ptr [EAX],0x16
    m.w32((s.ax), 0x00000016u);
  }
  { // 0x781016: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x781019: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x78101a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00381270(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x781270: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x781272: ff742408 PUSH dword ptr [ESP + 0x8]
    f.push(m,m.r32((f.sp+0x00000008u)));
  }
  { // 0x781276: e871060000 CALL 0x007818ec
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x78127b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00382044(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x782044: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  { // 0x782048: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x782049: ff742408 PUSH dword ptr [ESP + 0x8]
    f.push(m,m.r32((f.sp+0x00000008u)));
  }
  { // 0x78204d: e803000000 CALL 0x00782055
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x782052: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x782053: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x782054: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00382782(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x782782: ff742404 PUSH dword ptr [ESP + 0x4]
    f.push(m,m.r32((f.sp+0x00000004u)));
  }
  { // 0x782786: e842050000 CALL 0x00782ccd
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x78278b: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x78278e: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x782792: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x782793: 7504 JNZ 0x00782799
    if(integer::condition("JNZ",flags)) goto L00782799;
  }
  { // 0x782795: 8308ff OR dword ptr [EAX],0xffffffff
    m.w32((s.ax), integer::logical((m.r32((s.ax)))|(0xffffffffu),32,flags));
  }
  { // 0x782798: c3 RET
    finish(m,s,f,0u); return;
  }
  L00782799: { // 0x782799: ff00 INC dword ptr [EAX]
    m.w32((s.ax), integer::increment(m.r32((s.ax)),32,flags));
  }
  { // 0x78279b: c3 RET
    finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,113>& entries_c() {
  static const std::array<Entry,113> entries{{
    {0x2e76a0u,f_002e76a0},
    {0x2e8a50u,f_002e8a50},
    {0x2e8ab0u,f_002e8ab0},
    {0x2e8b10u,f_002e8b10},
    {0x2ea8d0u,f_002ea8d0},
    {0x2eb320u,f_002eb320},
    {0x2eb5b0u,f_002eb5b0},
    {0x2eb5c0u,f_002eb5c0},
    {0x2ebe30u,f_002ebe30},
    {0x30b540u,f_0030b540},
    {0x30b5b0u,f_0030b5b0},
    {0x30dc40u,f_0030dc40},
    {0x3116f0u,f_003116f0},
    {0x3117a0u,f_003117a0},
    {0x3117d0u,f_003117d0},
    {0x311820u,f_00311820},
    {0x311850u,f_00311850},
    {0x311d60u,f_00311d60},
    {0x311e00u,f_00311e00},
    {0x311e80u,f_00311e80},
    {0x3129c0u,f_003129c0},
    {0x31af10u,f_0031af10},
    {0x31bbe0u,f_0031bbe0},
    {0x31d020u,f_0031d020},
    {0x31dac0u,f_0031dac0},
    {0x31dd80u,f_0031dd80},
    {0x3206b0u,f_003206b0},
    {0x321b30u,f_00321b30},
    {0x324e70u,f_00324e70},
    {0x3253b0u,f_003253b0},
    {0x327660u,f_00327660},
    {0x327710u,f_00327710},
    {0x327760u,f_00327760},
    {0x327c90u,f_00327c90},
    {0x32c690u,f_0032c690},
    {0x32c6c0u,f_0032c6c0},
    {0x32c950u,f_0032c950},
    {0x32d800u,f_0032d800},
    {0x330b80u,f_00330b80},
    {0x352730u,f_00352730},
    {0x356210u,f_00356210},
    {0x358120u,f_00358120},
    {0x35aeb0u,f_0035aeb0},
    {0x35b3b0u,f_0035b3b0},
    {0x35b3f0u,f_0035b3f0},
    {0x35bd40u,f_0035bd40},
    {0x35bd80u,f_0035bd80},
    {0x35bdb0u,f_0035bdb0},
    {0x35bde0u,f_0035bde0},
    {0x35c290u,f_0035c290},
    {0x35c9b0u,f_0035c9b0},
    {0x35c9c0u,f_0035c9c0},
    {0x35f070u,f_0035f070},
    {0x35f180u,f_0035f180},
    {0x367f80u,f_00367f80},
    {0x36d611u,f_0036d611},
    {0x36df70u,f_0036df70},
    {0x36e2cau,f_0036e2ca},
    {0x36e8fdu,f_0036e8fd},
    {0x36eb19u,f_0036eb19},
    {0x36f385u,f_0036f385},
    {0x36f4b1u,f_0036f4b1},
    {0x36f4f4u,f_0036f4f4},
    {0x36f50cu,f_0036f50c},
    {0x36f60bu,f_0036f60b},
    {0x36f73bu,f_0036f73b},
    {0x36f774u,f_0036f774},
    {0x36fd39u,f_0036fd39},
    {0x36ffddu,f_0036ffdd},
    {0x36ffeau,f_0036ffea},
    {0x37033cu,f_0037033c},
    {0x3703a8u,f_003703a8},
    {0x3703e6u,f_003703e6},
    {0x3704b8u,f_003704b8},
    {0x370676u,f_00370676},
    {0x3707dcu,f_003707dc},
    {0x3707edu,f_003707ed},
    {0x3708c1u,f_003708c1},
    {0x3708cau,f_003708ca},
    {0x370949u,f_00370949},
    {0x370adcu,f_00370adc},
    {0x370c91u,f_00370c91},
    {0x370fa2u,f_00370fa2},
    {0x3725a6u,f_003725a6},
    {0x37266fu,f_0037266f},
    {0x374ed1u,f_00374ed1},
    {0x37524eu,f_0037524e},
    {0x375257u,f_00375257},
    {0x3764cbu,f_003764cb},
    {0x376714u,f_00376714},
    {0x3767ccu,f_003767cc},
    {0x37742au,f_0037742a},
    {0x3774e0u,f_003774e0},
    {0x378156u,f_00378156},
    {0x378161u,f_00378161},
    {0x37819fu,f_0037819f},
    {0x379171u,f_00379171},
    {0x379457u,f_00379457},
    {0x3794e0u,f_003794e0},
    {0x37950au,f_0037950a},
    {0x379525u,f_00379525},
    {0x3795dcu,f_003795dc},
    {0x37b750u,f_0037b750},
    {0x37bc5bu,f_0037bc5b},
    {0x37bc71u,f_0037bc71},
    {0x37bc87u,f_0037bc87},
    {0x37bf12u,f_0037bf12},
    {0x37f5c5u,f_0037f5c5},
    {0x37ff49u,f_0037ff49},
    {0x380fbau,f_00380fba},
    {0x381270u,f_00381270},
    {0x382044u,f_00382044},
    {0x382782u,f_00382782},
  }}; return entries;
}
} // namespace ra2::recovered::direct_b33
