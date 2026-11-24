#include "recovered/direct_b33_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::direct_b33 {
namespace {
void f_0019b960(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59b960: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x59b961: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x59b963: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x59b965: 8806 MOV byte ptr [ESI],AL
    m.w8((s.si), (s.ax & 0xffu));
  }
  { // 0x59b967: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x59b96a: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x59b96d: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  { // 0x59b970: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x59b974: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x59b975: e836000000 CALL 0x0059b9b0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x59b97a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x59b97c: 7503 JNZ 0x0059b981
    if(integer::condition("JNZ",flags)) goto L0059b981;
  }
  { // 0x59b97e: c60601 MOV byte ptr [ESI],0x1
    m.w8((s.si), 0x00000001u);
  }
  L0059b981: { // 0x59b981: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x59b983: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x59b984: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0019be10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59be10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x59be11: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x59be13: e878470c00 CALL 0x00660590
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x59be18: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x59be1a: c70654597800 MOV dword ptr [ESI],0x785954
    m.w32((s.si), 0x00785954u);
  }
  { // 0x59be20: 88862c4f0000 MOV byte ptr [ESI + 0x4f2c],AL
    m.w8((s.si+0x00004f2cu), (s.ax & 0xffu));
  }
  { // 0x59be26: 8986304f0000 MOV dword ptr [ESI + 0x4f30],EAX
    m.w32((s.si+0x00004f30u), s.ax);
  }
  { // 0x59be2c: 8986344f0000 MOV dword ptr [ESI + 0x4f34],EAX
    m.w32((s.si+0x00004f34u), s.ax);
  }
  { // 0x59be32: 8986384f0000 MOV dword ptr [ESI + 0x4f38],EAX
    m.w32((s.si+0x00004f38u), s.ax);
  }
  { // 0x59be38: c786e84e00004c597800 MOV dword ptr [ESI + 0x4ee8],0x78594c
    m.w32((s.si+0x00004ee8u), 0x0078594cu);
  }
  { // 0x59be42: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x59be44: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x59be45: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0019c300(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59c300: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x59c301: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x59c303: e8284f0d00 CALL 0x00671230
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x59c308: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x59c30a: 88862c4f0000 MOV byte ptr [ESI + 0x4f2c],AL
    m.w8((s.si+0x00004f2cu), (s.ax & 0xffu));
  }
  { // 0x59c310: 8986344f0000 MOV dword ptr [ESI + 0x4f34],EAX
    m.w32((s.si+0x00004f34u), s.ax);
  }
  { // 0x59c316: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x59c317: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0019cd50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59cd50: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x59cd54: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x59cd55: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x59cd57: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x59cd58: e8d3430d00 CALL 0x00671130
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x59cd5d: c786e84e0000445e7800 MOV dword ptr [ESI + 0x4ee8],0x785e44
    m.w32((s.si+0x00004ee8u), 0x00785e44u);
  }
  { // 0x59cd67: c706cc147900 MOV dword ptr [ESI],0x7914cc
    m.w32((s.si), 0x007914ccu);
  }
  { // 0x59cd6d: c786e84e0000c4147900 MOV dword ptr [ESI + 0x4ee8],0x7914c4
    m.w32((s.si+0x00004ee8u), 0x007914c4u);
  }
  { // 0x59cd77: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x59cd79: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x59cd7a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0019d0a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59d0a0: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x59d0a4: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x59d0a6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x59d0a7: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x59d0ab: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x59d0ac: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x59d0b0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x59d0b1: e80a000000 CALL 0x0059d0c0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x59d0b6: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0019d5e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59d5e0: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x59d5e2: 7c3e JL 0x0059d622
    if(integer::condition("JL",flags)) goto L0059d622;
  }
  { // 0x59d5e4: 3b0d788ca500 CMP ECX,dword ptr [0x00a58c78]
    (void)integer::sub(s.cx,m.r32((0x00a58c78u)),32,flags);
  }
  { // 0x59d5ea: 7d36 JGE 0x0059d622
    if(integer::condition("JGE",flags)) goto L0059d622;
  }
  { // 0x59d5ec: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x59d5f0: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x59d5f4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x59d5f5: 8a1dd07fa200 MOV BL,byte ptr [0x00a27fd0]
    s.bx = with_al(s.bx, m.r8((0x00a27fd0u)));
  }
  { // 0x59d5fb: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x59d5fd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x59d5fe: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x59d602: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x59d603: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x59d604: a16c8ca500 MOV EAX,[0x00a58c6c]
    s.ax = m.r32((0x00a58c6cu));
  }
  { // 0x59d609: c605d07fa20000 MOV byte ptr [0x00a27fd0],0x0
    m.w8((0x00a27fd0u), 0x00000000u);
  }
  { // 0x59d610: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  { // 0x59d613: 8b0c88 MOV ECX,dword ptr [EAX + ECX*0x4]
    s.cx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  { // 0x59d616: e8a5faffff CALL 0x0059d0c0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x59d61b: 881dd07fa200 MOV byte ptr [0x00a27fd0],BL
    m.w8((0x00a27fd0u), (s.bx & 0xffu));
  }
  { // 0x59d621: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0059d622: { // 0x59d622: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0019e3e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59e3e0: a1c48ca500 MOV EAX,[0x00a58cc4]
    s.ax = m.r32((0x00a58cc4u));
  }
  { // 0x59e3e5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x59e3e7: 7403 JZ 0x0059e3ec
    if(integer::condition("JZ",flags)) goto L0059e3ec;
  }
  { // 0x59e3e9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x59e3eb: c3 RET
    finish(m,s,f,0u); return;
  }
  L0059e3ec: { // 0x59e3ec: 890dc48ca500 MOV dword ptr [0x00a58cc4],ECX
    m.w32((0x00a58cc4u), s.cx);
  }
  { // 0x59e3f2: 8b09 MOV ECX,dword ptr [ECX]
    s.cx = m.r32((s.cx));
  }
  { // 0x59e3f4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x59e3f5: e886371700 CALL 0x00711b80
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x59e3fa: c705c48ca50000000000 MOV dword ptr [0x00a58cc4],0x0
    m.w32((0x00a58cc4u), 0x00000000u);
  }
  { // 0x59e404: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001aafc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5aafc0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5aafc1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5aafc2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x5aafc4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x5aafc6: 8a0d1894a500 MOV CL,byte ptr [0x00a59418]
    s.cx = with_al(s.cx, m.r8((0x00a59418u)));
  }
  { // 0x5aafcc: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x5aafce: 84c8 TEST AL,CL
    (void)integer::logical(((s.ax & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x5aafd0: 752f JNZ 0x005ab001
    if(integer::condition("JNZ",flags)) goto L005ab001;
  }
  { // 0x5aafd2: 8ad1 MOV DL,CL
    s.dx = with_al(s.dx, (s.cx & 0xffu));
  }
  { // 0x5aafd4: 6840b05a00 PUSH 0x5ab040
    f.push(m,0x005ab040u);
  }
  { // 0x5aafd9: 0ad0 OR DL,AL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))|((s.ax & 0xffu)),8,flags));
  }
  { // 0x5aafdb: 89353094a500 MOV dword ptr [0x00a59430],ESI
    m.w32((0x00a59430u), s.si);
  }
  { // 0x5aafe1: 88151894a500 MOV byte ptr [0x00a59418],DL
    m.w8((0x00a59418u), (s.dx & 0xffu));
  }
  { // 0x5aafe7: 89353494a500 MOV dword ptr [0x00a59434],ESI
    m.w32((0x00a59434u), s.si);
  }
  { // 0x5aafed: 89353894a500 MOV dword ptr [0x00a59438],ESI
    m.w32((0x00a59438u), s.si);
  }
  { // 0x5aaff3: 89353c94a500 MOV dword ptr [0x00a5943c],ESI
    m.w32((0x00a5943cu), s.si);
  }
  { // 0x5aaff9: e8cc321c00 CALL 0x0076e2ca
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5aaffe: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005ab001: { // 0x5ab001: 8b471c MOV EAX,dword ptr [EDI + 0x1c]
    s.ax = m.r32((s.di+0x0000001cu));
  }
  { // 0x5ab004: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x5ab006: 8d4834 LEA ECX,[EAX + 0x34]
    s.cx = (s.ax+0x00000034u);
  }
  { // 0x5ab009: 7505 JNZ 0x005ab010
    if(integer::condition("JNZ",flags)) goto L005ab010;
  }
  { // 0x5ab00b: b93094a500 MOV ECX,0xa59430
    s.cx = 0x00a59430u;
  }
  L005ab010: { // 0x5ab010: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x5ab014: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  { // 0x5ab016: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x5ab018: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5ab019: 8932 MOV dword ptr [EDX],ESI
    m.w32((s.dx), s.si);
  }
  { // 0x5ab01b: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  { // 0x5ab01e: 897204 MOV dword ptr [EDX + 0x4],ESI
    m.w32((s.dx+0x00000004u), s.si);
  }
  { // 0x5ab021: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  { // 0x5ab024: 897208 MOV dword ptr [EDX + 0x8],ESI
    m.w32((s.dx+0x00000008u), s.si);
  }
  { // 0x5ab027: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  { // 0x5ab02a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5ab02b: 894a0c MOV dword ptr [EDX + 0xc],ECX
    m.w32((s.dx+0x0000000cu), s.cx);
  }
  { // 0x5ab02e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001ab0d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5ab0d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ab0d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5ab0d3: 8d4e1c LEA ECX,[ESI + 0x1c]
    s.cx = (s.si+0x0000001cu);
  }
  { // 0x5ab0d6: c706001e7900 MOV dword ptr [ESI],0x791e00
    m.w32((s.si), 0x00791e00u);
  }
  { // 0x5ab0dc: e8af021b00 CALL 0x0075b390
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5ab0e1: c706101d7900 MOV dword ptr [ESI],0x791d10
    m.w32((s.si), 0x00791d10u);
  }
  { // 0x5ab0e7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5ab0e8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001ac030(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5ac030: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ac031: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5ac033: 8a4648 MOV AL,byte ptr [ESI + 0x48]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000048u)));
  }
  { // 0x5ac036: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5ac038: 741a JZ 0x005ac054
    if(integer::condition("JZ",flags)) goto L005ac054;
  }
  { // 0x5ac03a: 8d4e1c LEA ECX,[ESI + 0x1c]
    s.cx = (s.si+0x0000001cu);
  }
  { // 0x5ac03d: e89efd1a00 CALL 0x0075bde0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5ac042: 394624 CMP dword ptr [ESI + 0x24],EAX
    (void)integer::sub(m.r32((s.si+0x00000024u)),s.ax,32,flags);
  }
  { // 0x5ac045: 760d JBE 0x005ac054
    if(integer::condition("JBE",flags)) goto L005ac054;
  }
  { // 0x5ac047: 837e2802 CMP dword ptr [ESI + 0x28],0x2
    (void)integer::sub(m.r32((s.si+0x00000028u)),0x00000002u,32,flags);
  }
  { // 0x5ac04b: 7607 JBE 0x005ac054
    if(integer::condition("JBE",flags)) goto L005ac054;
  }
  { // 0x5ac04d: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x5ac052: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5ac053: c3 RET
    finish(m,s,f,0u); return;
  }
  L005ac054: { // 0x5ac054: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5ac056: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5ac057: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001ac7f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5ac7f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ac7f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5ac7f3: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x5ac7f6: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x5ac7f9: 7434 JZ 0x005ac82f
    if(integer::condition("JZ",flags)) goto L005ac82f;
  }
  { // 0x5ac7fb: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5ac7fc: 8b7e18 MOV EDI,dword ptr [ESI + 0x18]
    s.di = m.r32((s.si+0x00000018u));
  }
  { // 0x5ac7ff: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x5ac802: 7420 JZ 0x005ac824
    if(integer::condition("JZ",flags)) goto L005ac824;
  }
  { // 0x5ac804: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x5ac807: e8c4320e00 CALL 0x0068fad0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5ac80c: 2b4610 SUB EAX,dword ptr [ESI + 0x10]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x00000010u)),32,flags);
  }
  { // 0x5ac80f: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x5ac811: 7d0f JGE 0x005ac822
    if(integer::condition("JGE",flags)) goto L005ac822;
  }
  { // 0x5ac813: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x5ac815: c74610ffffffff MOV dword ptr [ESI + 0x10],0xffffffff
    m.w32((s.si+0x00000010u), 0xffffffffu);
  }
  { // 0x5ac81c: 897e18 MOV dword ptr [ESI + 0x18],EDI
    m.w32((s.si+0x00000018u), s.di);
  }
  { // 0x5ac81f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5ac820: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5ac821: c3 RET
    finish(m,s,f,0u); return;
  }
  L005ac822: { // 0x5ac822: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L005ac824: { // 0x5ac824: 897e18 MOV dword ptr [ESI + 0x18],EDI
    m.w32((s.si+0x00000018u), s.di);
  }
  { // 0x5ac827: c74610ffffffff MOV dword ptr [ESI + 0x10],0xffffffff
    m.w32((s.si+0x00000010u), 0xffffffffu);
  }
  { // 0x5ac82e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005ac82f: { // 0x5ac82f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5ac830: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001ac840(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5ac840: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ac841: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5ac843: 837e10ff CMP dword ptr [ESI + 0x10],-0x1
    (void)integer::sub(m.r32((s.si+0x00000010u)),0xffffffffu,32,flags);
  }
  { // 0x5ac847: 750b JNZ 0x005ac854
    if(integer::condition("JNZ",flags)) goto L005ac854;
  }
  { // 0x5ac849: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x5ac84c: e87f320e00 CALL 0x0068fad0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5ac851: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L005ac854: { // 0x5ac854: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5ac855: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001afb70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5afb70: a1941c8200 MOV EAX,[0x00821c94]
    s.ax = m.r32((0x00821c94u));
  }
  { // 0x5afb75: c6050ca7830001 MOV byte ptr [0x0083a70c],0x1
    m.w8((0x0083a70cu), 0x00000001u);
  }
  { // 0x5afb7c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5afb7d: e80e000000 CALL 0x005afb90
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5afb82: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001b0b20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b0b20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b0b21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5b0b23: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x5b0b25: 88460c MOV byte ptr [ESI + 0xc],AL
    m.w8((s.si+0x0000000cu), (s.ax & 0xffu));
  }
  { // 0x5b0b28: 88460d MOV byte ptr [ESI + 0xd],AL
    m.w8((s.si+0x0000000du), (s.ax & 0xffu));
  }
  { // 0x5b0b2b: 88460e MOV byte ptr [ESI + 0xe],AL
    m.w8((s.si+0x0000000eu), (s.ax & 0xffu));
  }
  { // 0x5b0b2e: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x5b0b32: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5b0b33: c7068c207900 MOV dword ptr [ESI],0x79208c
    m.w32((s.si), 0x0079208cu);
  }
  { // 0x5b0b39: e872000000 CALL 0x005b0bb0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5b0b3e: a17094a500 MOV EAX,[0x00a59470]
    s.ax = m.r32((0x00a59470u));
  }
  { // 0x5b0b43: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x5b0b44: a37094a500 MOV [0x00a59470],EAX
    m.w32((0x00a59470u), s.ax);
  }
  { // 0x5b0b49: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5b0b4b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b0b4c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001b1820(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b1820: 6880020000 PUSH 0x280
    f.push(m,0x00000280u);
  }
  { // 0x5b1825: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5b1827: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5b1829: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5b182b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5b182d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5b182f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5b1831: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5b1833: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5b1835: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5b1837: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5b1839: e802000000 CALL 0x005b1840
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5b183e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001b34f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b34f0: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5b34f2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b34f4: 7407 JZ 0x005b34fd
    if(integer::condition("JZ",flags)) goto L005b34fd;
  }
  { // 0x5b34f6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5b34f7: e82caa1b00 CALL 0x0076df28
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5b34fc: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005b34fd: { // 0x5b34fd: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001b3740(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b3740: a03896a500 MOV AL,[0x00a59638]
    s.ax = with_al(s.ax, m.r8((0x00a59638u)));
  }
  { // 0x5b3745: b101 MOV CL,0x1
    s.cx = with_al(s.cx, 0x00000001u);
  }
  { // 0x5b3747: 84c1 TEST CL,AL
    (void)integer::logical(((s.cx & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5b3749: 7547 JNZ 0x005b3792
    if(integer::condition("JNZ",flags)) goto L005b3792;
  }
  { // 0x5b374b: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  { // 0x5b374d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5b374f: 0ad1 OR DL,CL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))|((s.cx & 0xffu)),8,flags));
  }
  { // 0x5b3751: 68a0375b00 PUSH 0x5b37a0
    f.push(m,0x005b37a0u);
  }
  { // 0x5b3756: 88153896a500 MOV byte ptr [0x00a59638],DL
    m.w8((0x00a59638u), (s.dx & 0xffu));
  }
  { // 0x5b375c: a32496a500 MOV [0x00a59624],EAX
    m.w32((0x00a59624u), s.ax);
  }
  { // 0x5b3761: a32896a500 MOV [0x00a59628],EAX
    m.w32((0x00a59628u), s.ax);
  }
  { // 0x5b3766: 880d2c96a500 MOV byte ptr [0x00a5962c],CL
    m.w8((0x00a5962cu), (s.cx & 0xffu));
  }
  { // 0x5b376c: a22d96a500 MOV [0x00a5962d],AL
    m.w8((0x00a5962du), (s.ax & 0xffu));
  }
  { // 0x5b3771: c7052096a50048217900 MOV dword ptr [0x00a59620],0x792148
    m.w32((0x00a59620u), 0x00792148u);
  }
  { // 0x5b377b: c7053496a5000a000000 MOV dword ptr [0x00a59634],0xa
    m.w32((0x00a59634u), 0x0000000au);
  }
  { // 0x5b3785: a33096a500 MOV [0x00a59630],EAX
    m.w32((0x00a59630u), s.ax);
  }
  { // 0x5b378a: e83bab1b00 CALL 0x0076e2ca
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5b378f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005b3792: { // 0x5b3792: b82096a500 MOV EAX,0xa59620
    s.ax = 0x00a59620u;
  }
  { // 0x5b3797: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001b3a90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b3a90: a03896a500 MOV AL,[0x00a59638]
    s.ax = with_al(s.ax, m.r8((0x00a59638u)));
  }
  { // 0x5b3a95: b101 MOV CL,0x1
    s.cx = with_al(s.cx, 0x00000001u);
  }
  { // 0x5b3a97: 84c1 TEST CL,AL
    (void)integer::logical(((s.cx & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5b3a99: 7547 JNZ 0x005b3ae2
    if(integer::condition("JNZ",flags)) goto L005b3ae2;
  }
  { // 0x5b3a9b: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  { // 0x5b3a9d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5b3a9f: 0ad1 OR DL,CL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))|((s.cx & 0xffu)),8,flags));
  }
  { // 0x5b3aa1: 68a0375b00 PUSH 0x5b37a0
    f.push(m,0x005b37a0u);
  }
  { // 0x5b3aa6: 88153896a500 MOV byte ptr [0x00a59638],DL
    m.w8((0x00a59638u), (s.dx & 0xffu));
  }
  { // 0x5b3aac: a32496a500 MOV [0x00a59624],EAX
    m.w32((0x00a59624u), s.ax);
  }
  { // 0x5b3ab1: a32896a500 MOV [0x00a59628],EAX
    m.w32((0x00a59628u), s.ax);
  }
  { // 0x5b3ab6: 880d2c96a500 MOV byte ptr [0x00a5962c],CL
    m.w8((0x00a5962cu), (s.cx & 0xffu));
  }
  { // 0x5b3abc: a22d96a500 MOV [0x00a5962d],AL
    m.w8((0x00a5962du), (s.ax & 0xffu));
  }
  { // 0x5b3ac1: c7052096a50048217900 MOV dword ptr [0x00a59620],0x792148
    m.w32((0x00a59620u), 0x00792148u);
  }
  { // 0x5b3acb: c7053496a5000a000000 MOV dword ptr [0x00a59634],0xa
    m.w32((0x00a59634u), 0x0000000au);
  }
  { // 0x5b3ad5: a33096a500 MOV [0x00a59630],EAX
    m.w32((0x00a59630u), s.ax);
  }
  { // 0x5b3ada: e8eba71b00 CALL 0x0076e2ca
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5b3adf: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005b3ae2: { // 0x5b3ae2: a13096a500 MOV EAX,[0x00a59630]
    s.ax = m.r32((0x00a59630u));
  }
  { // 0x5b3ae7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001b63b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b63b0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x5b63b4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b63b5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5b63b7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5b63b8: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x5b63bb: e8904f1a00 CALL 0x0075b350
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5b63c0: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x5b63c4: c706e4227900 MOV dword ptr [ESI],0x7922e4
    m.w32((s.si), 0x007922e4u);
  }
  { // 0x5b63ca: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  { // 0x5b63cd: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5b63cf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b63d0: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_001c2540(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c2540: a1ac7da200 MOV EAX,[0x00a27dac]
    s.ax = m.r32((0x00a27dacu));
  }
  { // 0x5c2545: 683e79a200 PUSH 0xa2793e
    f.push(m,0x00a2793eu);
  }
  { // 0x5c254a: 8b0c88 MOV ECX,dword ptr [EAX + ECX*0x4]
    s.cx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  { // 0x5c254d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5c254e: e8c0cb1a00 CALL 0x0076f113
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5c2553: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5c2556: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x5c2558: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x5c255a: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x5c255b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c6240(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c6240: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c6241: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5c6243: e828afebff CALL 0x00481170
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5c6248: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x5c624c: 89464c MOV dword ptr [ESI + 0x4c],EAX
    m.w32((s.si+0x0000004cu), s.ax);
  }
  { // 0x5c624f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c6250: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001c8440(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c8440: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c8441: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5c8443: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c8444: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5c8446: 8b7e08 MOV EDI,dword ptr [ESI + 0x8]
    s.di = m.r32((s.si+0x00000008u));
  }
  { // 0x5c8449: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x5c844c: 740c JZ 0x005c845a
    if(integer::condition("JZ",flags)) goto L005c845a;
  }
  { // 0x5c844e: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x5c8451: e87a760c00 CALL 0x0068fad0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5c8456: 2b06 SUB EAX,dword ptr [ESI]
    s.ax = integer::sub(s.ax,m.r32((s.si)),32,flags);
  }
  { // 0x5c8458: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L005c845a: { // 0x5c845a: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x5c845c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c845d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c845e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c8a50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c8a50: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  { // 0x5c8a53: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5c8a55: 7408 JZ 0x005c8a5f
    if(integer::condition("JZ",flags)) goto L005c8a5f;
  }
  { // 0x5c8a57: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x5c8a5a: e82175ebff CALL 0x0047ff80
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L005c8a5f: { // 0x5c8a5f: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x5c8a64: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c8f90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c8f90: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  { // 0x5c8f93: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5c8f95: 740a JZ 0x005c8fa1
    if(integer::condition("JZ",flags)) goto L005c8fa1;
  }
  { // 0x5c8f97: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x5c8f9a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5c8f9c: e84f76ebff CALL 0x004805f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L005c8fa1: { // 0x5c8fa1: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001cab90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cab90: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x5cab94: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cab95: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5cab97: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5cab98: e8c353e4ff CALL 0x0040ff60
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5cab9d: c70658247900 MOV dword ptr [ESI],0x792458
    m.w32((s.si), 0x00792458u);
  }
  { // 0x5caba3: c746043c247900 MOV dword ptr [ESI + 0x4],0x79243c
    m.w32((s.si+0x00000004u), 0x0079243cu);
  }
  { // 0x5cabaa: c7460834247900 MOV dword ptr [ESI + 0x8],0x792434
    m.w32((s.si+0x00000008u), 0x00792434u);
  }
  { // 0x5cabb1: c7460c2c247900 MOV dword ptr [ESI + 0xc],0x79242c
    m.w32((s.si+0x0000000cu), 0x0079242cu);
  }
  { // 0x5cabb8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5cabba: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cabbb: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001cada0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cada0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cada1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5cada3: 8b8e94000000 MOV ECX,dword ptr [ESI + 0x94]
    s.cx = m.r32((s.si+0x00000094u));
  }
  { // 0x5cada9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5cadab: 740f JZ 0x005cadbc
    if(integer::condition("JZ",flags)) goto L005cadbc;
  }
  { // 0x5cadad: e81ec9f6ff CALL 0x005376d0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5cadb2: c7869400000000000000 MOV dword ptr [ESI + 0x94],0x0
    m.w32((s.si+0x00000094u), 0x00000000u);
  }
  L005cadbc: { // 0x5cadbc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cadbd: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001cdbb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cdbb0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x5cdbb4: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x5cdbb7: 894164 MOV dword ptr [ECX + 0x64],EAX
    m.w32((s.cx+0x00000064u), s.ax);
  }
  { // 0x5cdbba: 7508 JNZ 0x005cdbc4
    if(integer::condition("JNZ",flags)) goto L005cdbc4;
  }
  { // 0x5cdbbc: 83c150 ADD ECX,0x50
    s.cx = integer::add(s.cx,0x00000050u,32,flags);
  }
  { // 0x5cdbbf: e81c84e3ff CALL 0x00405fe0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L005cdbc4: { // 0x5cdbc4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001d04f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5d04f0: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x5d04f4: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x5d04f8: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x5d04fc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5d04fd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5d04fe: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5d04ff: e8bcfbe3ff CALL 0x004100c0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5d0504: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5d0506: 7c02 JL 0x005d050a
    if(integer::condition("JL",flags)) goto L005d050a;
  }
  { // 0x5d0508: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005d050a: { // 0x5d050a: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_001d0510(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5d0510: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x5d0514: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x5d0518: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5d0519: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5d051a: e861fce3ff CALL 0x00410180
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5d051f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5d0521: 7c02 JL 0x005d0525
    if(integer::condition("JL",flags)) goto L005d0525;
  }
  { // 0x5d0523: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005d0525: { // 0x5d0525: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_001d0fb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5d0fb0: 8a442404 MOV AL,byte ptr [ESP + 0x4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000004u)));
  }
  { // 0x5d0fb4: 88413a MOV byte ptr [ECX + 0x3a],AL
    m.w8((s.cx+0x0000003au), (s.ax & 0xffu));
  }
  { // 0x5d0fb7: a2bae0a100 MOV [0x00a1e0ba],AL
    m.w8((0x00a1e0bau), (s.ax & 0xffu));
  }
  { // 0x5d0fbc: 8a413a MOV AL,byte ptr [ECX + 0x3a]
    s.ax = with_al(s.ax, m.r8((s.cx+0x0000003au)));
  }
  { // 0x5d0fbf: 3c01 CMP AL,0x1
    (void)integer::sub((s.ax & 0xffu),0x00000001u,8,flags);
  }
  { // 0x5d0fc1: b818ca7c00 MOV EAX,0x7cca18
    s.ax = 0x007cca18u;
  }
  { // 0x5d0fc6: 7405 JZ 0x005d0fcd
    if(integer::condition("JZ",flags)) goto L005d0fcd;
  }
  { // 0x5d0fc8: b814ca7c00 MOV EAX,0x7cca14
    s.ax = 0x007cca14u;
  }
  L005d0fcd: { // 0x5d0fcd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5d0fce: 68dc277d00 PUSH 0x7d27dc
    f.push(m,0x007d27dcu);
  }
  { // 0x5d0fd3: e81859e3ff CALL 0x004068f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5d0fd8: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5d0fdb: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001d0fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5d0fe0: 8a442404 MOV AL,byte ptr [ESP + 0x4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000004u)));
  }
  { // 0x5d0fe4: 884138 MOV byte ptr [ECX + 0x38],AL
    m.w8((s.cx+0x00000038u), (s.ax & 0xffu));
  }
  { // 0x5d0fe7: a2b8e0a100 MOV [0x00a1e0b8],AL
    m.w8((0x00a1e0b8u), (s.ax & 0xffu));
  }
  { // 0x5d0fec: 8a4138 MOV AL,byte ptr [ECX + 0x38]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000038u)));
  }
  { // 0x5d0fef: 3c01 CMP AL,0x1
    (void)integer::sub((s.ax & 0xffu),0x00000001u,8,flags);
  }
  { // 0x5d0ff1: b818ca7c00 MOV EAX,0x7cca18
    s.ax = 0x007cca18u;
  }
  { // 0x5d0ff6: 7405 JZ 0x005d0ffd
    if(integer::condition("JZ",flags)) goto L005d0ffd;
  }
  { // 0x5d0ff8: b814ca7c00 MOV EAX,0x7cca14
    s.ax = 0x007cca14u;
  }
  L005d0ffd: { // 0x5d0ffd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5d0ffe: 68f0277d00 PUSH 0x7d27f0
    f.push(m,0x007d27f0u);
  }
  { // 0x5d1003: e8e858e3ff CALL 0x004068f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5d1008: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5d100b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001fd960(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5fd960: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x5fd964: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fd965: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5fd967: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5fd968: e8a32eeeff CALL 0x004e0810
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5fd96d: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x5fd971: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5fd973: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x5fd975: 899600010000 MOV dword ptr [ESI + 0x100],EDX
    m.w32((s.si+0x00000100u), s.dx);
  }
  { // 0x5fd97b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fd97c: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002067d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6067d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6067d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6067d3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6067d5: c7063c317900 MOV dword ptr [ESI],0x79313c
    m.w32((s.si), 0x0079313cu);
  }
  { // 0x6067db: e820ffffff CALL 0x00606700
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6067e0: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6067e2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6067e3: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002067f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6067f0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x6067f4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6067f5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6067f7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6067f8: c7063c317900 MOV dword ptr [ESI],0x79313c
    m.w32((s.si), 0x0079313cu);
  }
  { // 0x6067fe: e8fdfeffff CALL 0x00606700
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x606803: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x606805: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x606806: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002069f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6069f0: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x6069f4: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  { // 0x6069f6: 81c100010000 ADD ECX,0x100
    s.cx = integer::add(s.cx,0x00000100u,32,flags);
  }
  { // 0x6069fc: e8bfd8f9ff CALL 0x005a42c0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x606a01: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00208350(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x608350: 8b89b4010000 MOV ECX,dword ptr [ECX + 0x1b4]
    s.cx = m.r32((s.cx+0x000001b4u));
  }
  { // 0x608356: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x608357: 8b7130 MOV ESI,dword ptr [ECX + 0x30]
    s.si = m.r32((s.cx+0x00000030u));
  }
  { // 0x60835a: e851c4eeff CALL 0x004f47b0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x60835f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x608361: 740e JZ 0x00608371
    if(integer::condition("JZ",flags)) goto L00608371;
  }
  { // 0x608363: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  { // 0x608368: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x60836a: 7405 JZ 0x00608371
    if(integer::condition("JZ",flags)) goto L00608371;
  }
  { // 0x60836c: 8b4030 MOV EAX,dword ptr [EAX + 0x30]
    s.ax = m.r32((s.ax+0x00000030u));
  }
  { // 0x60836f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x608370: c3 RET
    finish(m,s,f,0u); return;
  }
  L00608371: { // 0x608371: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x608373: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x608374: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00208380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x608380: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x608383: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x608387: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x608388: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x60838a: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  { // 0x608390: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x608391: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x608392: e879fc0800 CALL 0x00698010
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x608397: 8b0d70198200 MOV ECX,dword ptr [0x00821970]
    s.cx = m.r32((0x00821970u));
  }
  { // 0x60839d: 8b1574198200 MOV EDX,dword ptr [0x00821974]
    s.dx = m.r32((0x00821974u));
  }
  { // 0x6083a3: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x6083a7: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x6083a9: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x6083ad: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  { // 0x6083af: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x6083b1: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  { // 0x6083b4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6083b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6083b7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6083ba: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00208530(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x608530: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x608533: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x608535: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x608539: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x60853a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x60853b: e820000000 CALL 0x00608560
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x608540: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x608542: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x608545: 8b7008 MOV ESI,dword ptr [EAX + 0x8]
    s.si = m.r32((s.ax+0x00000008u));
  }
  { // 0x608548: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x60854c: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x60854e: 890f MOV dword ptr [EDI],ECX
    m.w32((s.di), s.cx);
  }
  { // 0x608550: 895704 MOV dword ptr [EDI + 0x4],EDX
    m.w32((s.di+0x00000004u), s.dx);
  }
  { // 0x608553: 897708 MOV dword ptr [EDI + 0x8],ESI
    m.w32((s.di+0x00000008u), s.si);
  }
  { // 0x608556: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x608557: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x608558: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x60855b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00208d60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x608d60: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  { // 0x608d63: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x608d66: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x608d68: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x608d69: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x608d6a: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  { // 0x608d6d: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x608d71: e8eaf7ffff CALL 0x00608560
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x608d76: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x608d78: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x608d7b: 8b7008 MOV ESI,dword ptr [EAX + 0x8]
    s.si = m.r32((s.ax+0x00000008u));
  }
  { // 0x608d7e: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x608d82: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x608d84: 890f MOV dword ptr [EDI],ECX
    m.w32((s.di), s.cx);
  }
  { // 0x608d86: 895704 MOV dword ptr [EDI + 0x4],EDX
    m.w32((s.di+0x00000004u), s.dx);
  }
  { // 0x608d89: 897708 MOV dword ptr [EDI + 0x8],ESI
    m.w32((s.di+0x00000008u), s.si);
  }
  { // 0x608d8c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x608d8d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x608d8e: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x608d91: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00208ef0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x608ef0: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  { // 0x608ef3: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x608ef6: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x608ef8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x608ef9: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  { // 0x608efc: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x608f00: e85bf6ffff CALL 0x00608560
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x608f05: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  { // 0x608f09: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x608f0b: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  { // 0x608f0d: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x608f0f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x608f10: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  { // 0x608f13: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  { // 0x608f16: 7517 JNZ 0x00608f2f
    if(integer::condition("JNZ",flags)) goto L00608f2f;
  }
  { // 0x608f18: 3b4c2414 CMP ECX,dword ptr [ESP + 0x14]
    (void)integer::sub(s.cx,m.r32((f.sp+0x00000014u)),32,flags);
  }
  { // 0x608f1c: 7511 JNZ 0x00608f2f
    if(integer::condition("JNZ",flags)) goto L00608f2f;
  }
  { // 0x608f1e: 3b542418 CMP EDX,dword ptr [ESP + 0x18]
    (void)integer::sub(s.dx,m.r32((f.sp+0x00000018u)),32,flags);
  }
  { // 0x608f22: 750b JNZ 0x00608f2f
    if(integer::condition("JNZ",flags)) goto L00608f2f;
  }
  { // 0x608f24: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x608f29: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x608f2c: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00608f2f: { // 0x608f2f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x608f31: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x608f34: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_002119e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6119e0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x6119e3: 668b01 MOV AX,word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  { // 0x6119e6: 8a4902 MOV CL,byte ptr [ECX + 0x2]
    s.cx = with_al(s.cx, m.r8((s.cx+0x00000002u)));
  }
  { // 0x6119e9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6119ea: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x6119ee: 884c2406 MOV byte ptr [ESP + 0x6],CL
    m.w8((f.sp+0x00000006u), (s.cx & 0xffu));
  }
  { // 0x6119f2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6119f3: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x6119f7: 6689442408 MOV word ptr [ESP + 0x8],AX
    m.w16((f.sp+0x00000008u), (s.ax & 0xffffu));
  }
  { // 0x6119fc: e80f290200 CALL 0x00634310
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x611a01: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  { // 0x611a07: 8b442402 MOV EAX,dword ptr [ESP + 0x2]
    s.ax = m.r32((f.sp+0x00000002u));
  }
  { // 0x611a0b: 8b542401 MOV EDX,dword ptr [ESP + 0x1]
    s.dx = m.r32((f.sp+0x00000001u));
  }
  { // 0x611a0f: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x611a14: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x611a1a: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x611a1c: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  { // 0x611a22: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x611a24: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  { // 0x611a2a: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x611a2c: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  { // 0x611a32: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x611a34: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  { // 0x611a3a: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  { // 0x611a3c: 8b542400 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  { // 0x611a40: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x611a46: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x611a48: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  { // 0x611a4e: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x611a50: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  { // 0x611a52: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x611a55: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00227310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x627310: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x627314: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x627318: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x627319: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x62731a: e87126e7ff CALL 0x00499990
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x62731f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x627321: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x627324: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00227330(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x627330: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x627334: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x627338: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x627339: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x62733d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x62733e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x62733f: e85c2ae7ff CALL 0x00499da0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x627344: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x627346: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x627349: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00227980(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x627980: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x627984: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x627988: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x627989: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x62798d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x62798e: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x627992: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x627993: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x627994: e8d7dff1ff CALL 0x00545970
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x627999: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002279a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6279a0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x6279a4: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  { // 0x6279aa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6279ab: e840430700 CALL 0x0069bcf0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6279b0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0022c040(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x62c040: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x62c044: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x62c045: e8f622e7ff CALL 0x0049e340
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x62c04a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0022de60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x62de60: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x62de64: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x62de65: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x62de67: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x62de68: e823cdf9ff CALL 0x005cab90
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x62de6d: c786c8000000fc577800 MOV dword ptr [ESI + 0xc8],0x7857fc
    m.w32((s.si+0x000000c8u), 0x007857fcu);
  }
  { // 0x62de77: c706a8387900 MOV dword ptr [ESI],0x7938a8
    m.w32((s.si), 0x007938a8u);
  }
  { // 0x62de7d: c746048c387900 MOV dword ptr [ESI + 0x4],0x79388c
    m.w32((s.si+0x00000004u), 0x0079388cu);
  }
  { // 0x62de84: c7460884387900 MOV dword ptr [ESI + 0x8],0x793884
    m.w32((s.si+0x00000008u), 0x00793884u);
  }
  { // 0x62de8b: c7460c7c387900 MOV dword ptr [ESI + 0xc],0x79387c
    m.w32((s.si+0x0000000cu), 0x0079387cu);
  }
  { // 0x62de92: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x62de94: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x62de95: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0022e140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x62e140: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x62e141: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x62e145: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x62e146: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x62e147: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x62e14b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x62e14c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x62e14e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x62e14f: e80ce1f9ff CALL 0x005cc260
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x62e154: 8b86d0000000 MOV EAX,dword ptr [ESI + 0xd0]
    s.ax = m.r32((s.si+0x000000d0u));
  }
  { // 0x62e15a: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x62e15c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x62e15e: 7e25 JLE 0x0062e185
    if(integer::condition("JLE",flags)) goto L0062e185;
  }
  L0062e160: { // 0x62e160: 8b86cc000000 MOV EAX,dword ptr [ESI + 0xcc]
    s.ax = m.r32((s.si+0x000000ccu));
  }
  { // 0x62e166: 8b1488 MOV EDX,dword ptr [EAX + ECX*0x4]
    s.dx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  { // 0x62e169: 8d0488 LEA EAX,[EAX + ECX*0x4]
    s.ax = (s.ax+(s.cx * 0x00000004u));
  }
  { // 0x62e16c: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  { // 0x62e16e: 750a JNZ 0x0062e17a
    if(integer::condition("JNZ",flags)) goto L0062e17a;
  }
  { // 0x62e170: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x62e172: 7406 JZ 0x0062e17a
    if(integer::condition("JZ",flags)) goto L0062e17a;
  }
  { // 0x62e174: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  L0062e17a: { // 0x62e17a: 8b86d0000000 MOV EAX,dword ptr [ESI + 0xd0]
    s.ax = m.r32((s.si+0x000000d0u));
  }
  { // 0x62e180: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x62e181: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x62e183: 7cdb JL 0x0062e160
    if(integer::condition("JL",flags)) goto L0062e160;
  }
  L0062e185: { // 0x62e185: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x62e186: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x62e187: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x62e188: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00234eb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x634eb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x634eb1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x634eb3: e8e862f0ff CALL 0x0053b1a0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x634eb8: 8b0da8e3a900 MOV ECX,dword ptr [0x00a9e3a8]
    s.cx = m.r32((0x00a9e3a8u));
  }
  { // 0x634ebe: 8d4618 LEA EAX,[ESI + 0x18]
    s.ax = (s.si+0x00000018u);
  }
  { // 0x634ec1: 894e18 MOV dword ptr [ESI + 0x18],ECX
    m.w32((s.si+0x00000018u), s.cx);
  }
  { // 0x634ec4: 8b15ace3a900 MOV EDX,dword ptr [0x00a9e3ac]
    s.dx = m.r32((0x00a9e3acu));
  }
  { // 0x634eca: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  { // 0x634ecd: 8b0db0e3a900 MOV ECX,dword ptr [0x00a9e3b0]
    s.cx = m.r32((0x00a9e3b0u));
  }
  { // 0x634ed3: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  { // 0x634ed6: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  { // 0x634edc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x634ede: 895624 MOV dword ptr [ESI + 0x24],EDX
    m.w32((s.si+0x00000024u), s.dx);
  }
  { // 0x634ee1: 89462c MOV dword ptr [ESI + 0x2c],EAX
    m.w32((s.si+0x0000002cu), s.ax);
  }
  { // 0x634ee4: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  { // 0x634ee7: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x634eed: 89463c MOV dword ptr [ESI + 0x3c],EAX
    m.w32((s.si+0x0000003cu), s.ax);
  }
  { // 0x634ef0: 894e34 MOV dword ptr [ESI + 0x34],ECX
    m.w32((s.si+0x00000034u), s.cx);
  }
  { // 0x634ef3: 894648 MOV dword ptr [ESI + 0x48],EAX
    m.w32((s.si+0x00000048u), s.ax);
  }
  { // 0x634ef6: 894640 MOV dword ptr [ESI + 0x40],EAX
    m.w32((s.si+0x00000040u), s.ax);
  }
  { // 0x634ef9: 89464c MOV dword ptr [ESI + 0x4c],EAX
    m.w32((s.si+0x0000004cu), s.ax);
  }
  { // 0x634efc: 894650 MOV dword ptr [ESI + 0x50],EAX
    m.w32((s.si+0x00000050u), s.ax);
  }
  { // 0x634eff: 894654 MOV dword ptr [ESI + 0x54],EAX
    m.w32((s.si+0x00000054u), s.ax);
  }
  { // 0x634f02: c7064c3e7900 MOV dword ptr [ESI],0x793e4c
    m.w32((s.si), 0x00793e4cu);
  }
  { // 0x634f08: c74604843d7900 MOV dword ptr [ESI + 0x4],0x793d84
    m.w32((s.si+0x00000004u), 0x00793d84u);
  }
  { // 0x634f0f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x634f11: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x634f12: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00236c90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x636c90: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x636c93: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x636c97: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x636c98: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x636c99: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x636c9b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x636c9c: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  { // 0x636ca0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x636ca1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x636ca2: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  { // 0x636ca6: e8b5bdeeff CALL 0x00522a60
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x636cab: 8b5610 MOV EDX,dword ptr [ESI + 0x10]
    s.dx = m.r32((s.si+0x00000010u));
  }
  { // 0x636cae: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x636cb0: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x636cb2: 7e2d JLE 0x00636ce1
    if(integer::condition("JLE",flags)) goto L00636ce1;
  }
  { // 0x636cb4: 8b7604 MOV ESI,dword ptr [ESI + 0x4]
    s.si = m.r32((s.si+0x00000004u));
  }
  { // 0x636cb7: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  { // 0x636cbb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00636cbd: { // 0x636cbd: 8b19 MOV EBX,dword ptr [ECX]
    s.bx = m.r32((s.cx));
  }
  { // 0x636cbf: 0fbe1b MOVSX EBX,byte ptr [EBX]
    s.bx = std::uint32_t(integer::sign_extend(m.r8((s.bx)),8));
  }
  { // 0x636cc2: 3bdf CMP EBX,EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  { // 0x636cc4: 7411 JZ 0x00636cd7
    if(integer::condition("JZ",flags)) goto L00636cd7;
  }
  { // 0x636cc6: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x636cc7: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  { // 0x636cca: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x636ccc: 7cef JL 0x00636cbd
    if(integer::condition("JL",flags)) goto L00636cbd;
  }
  { // 0x636cce: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x636ccf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x636cd0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x636cd1: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x636cd4: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00636cd7: { // 0x636cd7: 8b1486 MOV EDX,dword ptr [ESI + EAX*0x4]
    s.dx = m.r32((s.si+(s.ax * 0x00000004u)));
  }
  { // 0x636cda: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x636cde: 894221 MOV dword ptr [EDX + 0x21],EAX
    m.w32((s.dx+0x00000021u), s.ax);
  }
  L00636ce1: { // 0x636ce1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x636ce2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x636ce3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x636ce4: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x636ce7: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00250380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x650380: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x650384: 66c781060100000000 MOV word ptr [ECX + 0x106],0x0
    m.w16((s.cx+0x00000106u), 0x00000000u);
  }
  { // 0x65038d: 6a7f PUSH 0x7f
    f.push(m,0x0000007fu);
  }
  { // 0x65038f: 83c108 ADD ECX,0x8
    s.cx = integer::add(s.cx,0x00000008u,32,flags);
  }
  { // 0x650392: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x650393: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x650394: e8c9eb1100 CALL 0x0076ef62
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x650399: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x65039c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002503b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6503b0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x6503b4: 66c781860100000000 MOV word ptr [ECX + 0x186],0x0
    m.w16((s.cx+0x00000186u), 0x00000000u);
  }
  { // 0x6503bd: 6a3f PUSH 0x3f
    f.push(m,0x0000003fu);
  }
  { // 0x6503bf: 81c108010000 ADD ECX,0x108
    s.cx = integer::add(s.cx,0x00000108u,32,flags);
  }
  { // 0x6503c5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6503c6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6503c7: e896eb1100 CALL 0x0076ef62
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6503cc: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x6503cf: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002504a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6504a0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x6504a4: c681d703000000 MOV byte ptr [ECX + 0x3d7],0x0
    m.w8((s.cx+0x000003d7u), 0x00000000u);
  }
  { // 0x6504ab: 6803010000 PUSH 0x103
    f.push(m,0x00000103u);
  }
  { // 0x6504b0: 81c1d4020000 ADD ECX,0x2d4
    s.cx = integer::add(s.cx,0x000002d4u,32,flags);
  }
  { // 0x6504b6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6504b7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6504b8: e853d81100 CALL 0x0076dd10
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6504bd: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x6504c0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00252310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x652310: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x652311: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x652313: 833e00 CMP dword ptr [ESI],0x0
    (void)integer::sub(m.r32((s.si)),0x00000000u,32,flags);
  }
  { // 0x652316: 750a JNZ 0x00652322
    if(integer::condition("JNZ",flags)) goto L00652322;
  }
  { // 0x652318: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x65231d: e84eef1200 CALL 0x00781270
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L00652322: { // 0x652322: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x652324: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x652325: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00255760(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x655760: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x655764: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x655765: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x655767: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x655769: 741c JZ 0x00655787
    if(integer::condition("JZ",flags)) goto L00655787;
  }
  { // 0x65576b: 6804010000 PUSH 0x104
    f.push(m,0x00000104u);
  }
  { // 0x655770: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x655771: 8d863c080000 LEA EAX,[ESI + 0x83c]
    s.ax = (s.si+0x0000083cu);
  }
  { // 0x655777: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x655778: e893851100 CALL 0x0076dd10
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x65577d: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x655780: c6863f09000000 MOV byte ptr [ESI + 0x93f],0x0
    m.w8((s.si+0x0000093fu), 0x00000000u);
  }
  L00655787: { // 0x655787: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x655788: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00258270(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x658270: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x658274: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x658275: 83f832 CMP EAX,0x32
    (void)integer::sub(s.ax,0x00000032u,32,flags);
  }
  { // 0x658278: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x65827a: 7336 JNC 0x006582b2
    if(integer::condition("JNC",flags)) goto L006582b2;
  }
  { // 0x65827c: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  { // 0x65827f: 8d1407 LEA EDX,[EDI + EAX*0x1]
    s.dx = (s.di+(s.ax * 0x00000001u));
  }
  { // 0x658282: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x658283: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x658284: 8a9cca38120000 MOV BL,byte ptr [EDX + ECX*0x8 + 0x1238]
    s.bx = with_al(s.bx, m.r8((s.dx+(s.cx * 0x00000008u)+0x00001238u)));
  }
  { // 0x65828b: 8db4ca38120000 LEA ESI,[EDX + ECX*0x8 + 0x1238]
    s.si = (s.dx+(s.cx * 0x00000008u)+0x00001238u);
  }
  { // 0x658292: 8a4c2414 MOV CL,byte ptr [ESP + 0x14]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000014u)));
  }
  { // 0x658296: 3ad9 CMP BL,CL
    (void)integer::sub((s.bx & 0xffu),(s.cx & 0xffu),8,flags);
  }
  { // 0x658298: 7410 JZ 0x006582aa
    if(integer::condition("JZ",flags)) goto L006582aa;
  }
  { // 0x65829a: 880e MOV byte ptr [ESI],CL
    m.w8((s.si), (s.cx & 0xffu));
  }
  { // 0x65829c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x65829e: c6872e22000001 MOV byte ptr [EDI + 0x222e],0x1
    m.w8((s.di+0x0000222eu), 0x00000001u);
  }
  { // 0x6582a5: e8c6150500 CALL 0x006a9870
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L006582aa: { // 0x6582aa: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  { // 0x6582ac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6582ad: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6582ae: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6582af: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L006582b2: { // 0x6582b2: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6582b4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6582b5: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00258510(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x658510: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x658514: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x658515: 83f832 CMP EAX,0x32
    (void)integer::sub(s.ax,0x00000032u,32,flags);
  }
  { // 0x658518: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x65851a: 7336 JNC 0x00658552
    if(integer::condition("JNC",flags)) goto L00658552;
  }
  { // 0x65851c: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  { // 0x65851f: 8d1407 LEA EDX,[EDI + EAX*0x1]
    s.dx = (s.di+(s.ax * 0x00000001u));
  }
  { // 0x658522: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x658523: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x658524: 8a9cca3a1a0000 MOV BL,byte ptr [EDX + ECX*0x8 + 0x1a3a]
    s.bx = with_al(s.bx, m.r8((s.dx+(s.cx * 0x00000008u)+0x00001a3au)));
  }
  { // 0x65852b: 8db4ca3a1a0000 LEA ESI,[EDX + ECX*0x8 + 0x1a3a]
    s.si = (s.dx+(s.cx * 0x00000008u)+0x00001a3au);
  }
  { // 0x658532: 8a4c2414 MOV CL,byte ptr [ESP + 0x14]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000014u)));
  }
  { // 0x658536: 3ad9 CMP BL,CL
    (void)integer::sub((s.bx & 0xffu),(s.cx & 0xffu),8,flags);
  }
  { // 0x658538: 7410 JZ 0x0065854a
    if(integer::condition("JZ",flags)) goto L0065854a;
  }
  { // 0x65853a: 880e MOV byte ptr [ESI],CL
    m.w8((s.si), (s.cx & 0xffu));
  }
  { // 0x65853c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x65853e: c6872e22000001 MOV byte ptr [EDI + 0x222e],0x1
    m.w8((s.di+0x0000222eu), 0x00000001u);
  }
  { // 0x658545: e856130500 CALL 0x006a98a0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L0065854a: { // 0x65854a: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  { // 0x65854c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65854d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x65854e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x65854f: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00658552: { // 0x658552: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x658554: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x658555: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0025a150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x65a150: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x65a154: 8d8c8132060000 LEA ECX,[ECX + EAX*0x4 + 0x632]
    s.cx = (s.cx+(s.ax * 0x00000004u)+0x00000632u);
  }
  { // 0x65a15b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x65a15c: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x65a161: e89ab3eeff CALL 0x00545500
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x65a166: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0025e7f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x65e7f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x65e7f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x65e7f3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x65e7f5: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x65e7f8: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x65e7fb: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  { // 0x65e7fe: 894614 MOV dword ptr [ESI + 0x14],EAX
    m.w32((s.si+0x00000014u), s.ax);
  }
  { // 0x65e801: c70648417900 MOV dword ptr [ESI],0x794148
    m.w32((s.si), 0x00794148u);
  }
  { // 0x65e807: e8a4000000 CALL 0x0065e8b0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x65e80c: a1a8eaa900 MOV EAX,[0x00a9eaa8]
    s.ax = m.r32((0x00a9eaa8u));
  }
  { // 0x65e811: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x65e812: a3a8eaa900 MOV [0x00a9eaa8],EAX
    m.w32((0x00a9eaa8u), s.ax);
  }
  { // 0x65e817: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x65e819: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65e81a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0025f2b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x65f2b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x65f2b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x65f2b3: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x65f2b6: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x65f2b9: 7434 JZ 0x0065f2ef
    if(integer::condition("JZ",flags)) goto L0065f2ef;
  }
  { // 0x65f2bb: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x65f2bc: 8b7e14 MOV EDI,dword ptr [ESI + 0x14]
    s.di = m.r32((s.si+0x00000014u));
  }
  { // 0x65f2bf: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x65f2c2: 7420 JZ 0x0065f2e4
    if(integer::condition("JZ",flags)) goto L0065f2e4;
  }
  { // 0x65f2c4: 8d4e10 LEA ECX,[ESI + 0x10]
    s.cx = (s.si+0x00000010u);
  }
  { // 0x65f2c7: e804080300 CALL 0x0068fad0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x65f2cc: 2b460c SUB EAX,dword ptr [ESI + 0xc]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x0000000cu)),32,flags);
  }
  { // 0x65f2cf: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x65f2d1: 7d0f JGE 0x0065f2e2
    if(integer::condition("JGE",flags)) goto L0065f2e2;
  }
  { // 0x65f2d3: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x65f2d5: c7460cffffffff MOV dword ptr [ESI + 0xc],0xffffffff
    m.w32((s.si+0x0000000cu), 0xffffffffu);
  }
  { // 0x65f2dc: 897e14 MOV dword ptr [ESI + 0x14],EDI
    m.w32((s.si+0x00000014u), s.di);
  }
  { // 0x65f2df: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x65f2e0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65f2e1: c3 RET
    finish(m,s,f,0u); return;
  }
  L0065f2e2: { // 0x65f2e2: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0065f2e4: { // 0x65f2e4: 897e14 MOV dword ptr [ESI + 0x14],EDI
    m.w32((s.si+0x00000014u), s.di);
  }
  { // 0x65f2e7: c7460cffffffff MOV dword ptr [ESI + 0xc],0xffffffff
    m.w32((s.si+0x0000000cu), 0xffffffffu);
  }
  { // 0x65f2ee: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0065f2ef: { // 0x65f2ef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65f2f0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0025f300(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x65f300: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x65f301: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x65f303: 837e0cff CMP dword ptr [ESI + 0xc],-0x1
    (void)integer::sub(m.r32((s.si+0x0000000cu)),0xffffffffu,32,flags);
  }
  { // 0x65f307: 750b JNZ 0x0065f314
    if(integer::condition("JNZ",flags)) goto L0065f314;
  }
  { // 0x65f309: 8d4e10 LEA ECX,[ESI + 0x10]
    s.cx = (s.si+0x00000010u);
  }
  { // 0x65f30c: e8bf070300 CALL 0x0068fad0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x65f311: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L0065f314: { // 0x65f314: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65f315: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00260590(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x660590: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x660591: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x660593: e898570300 CALL 0x00695d30
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x660598: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x66059a: 8986184f0000 MOV dword ptr [ESI + 0x4f18],EAX
    m.w32((s.si+0x00004f18u), s.ax);
  }
  { // 0x6605a0: 88861c4f0000 MOV byte ptr [ESI + 0x4f1c],AL
    m.w8((s.si+0x00004f1cu), (s.ax & 0xffu));
  }
  { // 0x6605a6: 8986204f0000 MOV dword ptr [ESI + 0x4f20],EAX
    m.w32((s.si+0x00004f20u), s.ax);
  }
  { // 0x6605ac: 8986244f0000 MOV dword ptr [ESI + 0x4f24],EAX
    m.w32((s.si+0x00004f24u), s.ax);
  }
  { // 0x6605b2: 8886284f0000 MOV byte ptr [ESI + 0x4f28],AL
    m.w8((s.si+0x00004f28u), (s.ax & 0xffu));
  }
  { // 0x6605b8: 88862a4f0000 MOV byte ptr [ESI + 0x4f2a],AL
    m.w8((s.si+0x00004f2au), (s.ax & 0xffu));
  }
  { // 0x6605be: c686294f000001 MOV byte ptr [ESI + 0x4f29],0x1
    m.w8((s.si+0x00004f29u), 0x00000001u);
  }
  { // 0x6605c5: c706ec427900 MOV dword ptr [ESI],0x7942ec
    m.w32((s.si), 0x007942ecu);
  }
  { // 0x6605cb: c786e84e0000e4427900 MOV dword ptr [ESI + 0x4ee8],0x7942e4
    m.w32((s.si+0x00004ee8u), 0x007942e4u);
  }
  { // 0x6605d5: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6605d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6605d8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00268370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x668370: 83c158 ADD ECX,0x58
    s.cx = integer::add(s.cx,0x00000058u,32,flags);
  }
  { // 0x668373: 68c0c17c00 PUSH 0x7cc1c0
    f.push(m,0x007cc1c0u);
  }
  { // 0x668378: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x668379: e8e2541000 CALL 0x0076d860
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x66837e: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x668381: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x668383: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x668385: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x668386: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002683f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6683f0: 81c158060000 ADD ECX,0x658
    s.cx = integer::add(s.cx,0x00000658u,32,flags);
  }
  { // 0x6683f6: 68c0c17c00 PUSH 0x7cc1c0
    f.push(m,0x007cc1c0u);
  }
  { // 0x6683fb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6683fc: e85f541000 CALL 0x0076d860
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x668401: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x668404: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x668406: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x668408: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x668409: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0026a9a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x66a9a0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x66a9a1: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x66a9a3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x66a9a4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x66a9a5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x66a9a6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x66a9a7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x66a9a8: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x66a9aa: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x66a9ab: e8305a0700 CALL 0x006e03e0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x66a9b0: 885e34 MOV byte ptr [ESI + 0x34],BL
    m.w8((s.si+0x00000034u), (s.bx & 0xffu));
  }
  { // 0x66a9b3: 895e38 MOV dword ptr [ESI + 0x38],EBX
    m.w32((s.si+0x00000038u), s.bx);
  }
  { // 0x66a9b6: 895e3c MOV dword ptr [ESI + 0x3c],EBX
    m.w32((s.si+0x0000003cu), s.bx);
  }
  { // 0x66a9b9: 885e40 MOV byte ptr [ESI + 0x40],BL
    m.w8((s.si+0x00000040u), (s.bx & 0xffu));
  }
  { // 0x66a9bc: 895e44 MOV dword ptr [ESI + 0x44],EBX
    m.w32((s.si+0x00000044u), s.bx);
  }
  { // 0x66a9bf: 895e48 MOV dword ptr [ESI + 0x48],EBX
    m.w32((s.si+0x00000048u), s.bx);
  }
  { // 0x66a9c2: 885e4c MOV byte ptr [ESI + 0x4c],BL
    m.w8((s.si+0x0000004cu), (s.bx & 0xffu));
  }
  { // 0x66a9c5: a104a78100 MOV EAX,[0x0081a704]
    s.ax = m.r32((0x0081a704u));
  }
  { // 0x66a9ca: 894650 MOV dword ptr [ESI + 0x50],EAX
    m.w32((s.si+0x00000050u), s.ax);
  }
  { // 0x66a9cd: 885e55 MOV byte ptr [ESI + 0x55],BL
    m.w8((s.si+0x00000055u), (s.bx & 0xffu));
  }
  { // 0x66a9d0: 885e5c MOV byte ptr [ESI + 0x5c],BL
    m.w8((s.si+0x0000005cu), (s.bx & 0xffu));
  }
  { // 0x66a9d3: c706a0b67800 MOV dword ptr [ESI],0x78b6a0
    m.w32((s.si), 0x0078b6a0u);
  }
  { // 0x66a9d9: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x66a9db: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x66a9dc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x66a9dd: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0026aab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x66aab0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x66aab1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x66aab2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x66aab4: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x66aab6: 385e5c CMP byte ptr [ESI + 0x5c],BL
    (void)integer::sub(m.r8((s.si+0x0000005cu)),(s.bx & 0xffu),8,flags);
  }
  { // 0x66aab9: 741c JZ 0x0066aad7
    if(integer::condition("JZ",flags)) goto L0066aad7;
  }
  { // 0x66aabb: 8b4658 MOV EAX,dword ptr [ESI + 0x58]
    s.ax = m.r32((s.si+0x00000058u));
  }
  { // 0x66aabe: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x66aac0: 7415 JZ 0x0066aad7
    if(integer::condition("JZ",flags)) goto L0066aad7;
  }
  { // 0x66aac2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x66aac3: e8b32b1000 CALL 0x0076d67b
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x66aac8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x66aacb: 895e58 MOV dword ptr [ESI + 0x58],EBX
    m.w32((s.si+0x00000058u), s.bx);
  }
  { // 0x66aace: 885e5c MOV byte ptr [ESI + 0x5c],BL
    m.w8((s.si+0x0000005cu), (s.bx & 0xffu));
  }
  { // 0x66aad1: 895e14 MOV dword ptr [ESI + 0x14],EBX
    m.w32((s.si+0x00000014u), s.bx);
  }
  { // 0x66aad4: 895e18 MOV dword ptr [ESI + 0x18],EBX
    m.w32((s.si+0x00000018u), s.bx);
  }
  L0066aad7: { // 0x66aad7: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x66aadb: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x66aadd: 894658 MOV dword ptr [ESI + 0x58],EAX
    m.w32((s.si+0x00000058u), s.ax);
  }
  { // 0x66aae0: 7410 JZ 0x0066aaf2
    if(integer::condition("JZ",flags)) goto L0066aaf2;
  }
  { // 0x66aae2: 0fbf4802 MOVSX ECX,word ptr [EAX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  { // 0x66aae6: 894e14 MOV dword ptr [ESI + 0x14],ECX
    m.w32((s.si+0x00000014u), s.cx);
  }
  { // 0x66aae9: 0fbf5004 MOVSX EDX,word ptr [EAX + 0x4]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000004u)),16));
  }
  { // 0x66aaed: 895618 MOV dword ptr [ESI + 0x18],EDX
    m.w32((s.si+0x00000018u), s.dx);
  }
  { // 0x66aaf0: eb06 JMP 0x0066aaf8
    goto L0066aaf8;
  }
  L0066aaf2: { // 0x66aaf2: 895e14 MOV dword ptr [ESI + 0x14],EBX
    m.w32((s.si+0x00000014u), s.bx);
  }
  { // 0x66aaf5: 895e18 MOV dword ptr [ESI + 0x18],EBX
    m.w32((s.si+0x00000018u), s.bx);
  }
  L0066aaf8: { // 0x66aaf8: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x66aafc: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x66aafe: 7403 JZ 0x0066ab03
    if(integer::condition("JZ",flags)) goto L0066ab03;
  }
  { // 0x66ab00: 894614 MOV dword ptr [ESI + 0x14],EAX
    m.w32((s.si+0x00000014u), s.ax);
  }
  L0066ab03: { // 0x66ab03: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x66ab07: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x66ab09: 7403 JZ 0x0066ab0e
    if(integer::condition("JZ",flags)) goto L0066ab0e;
  }
  { // 0x66ab0b: 894618 MOV dword ptr [ESI + 0x18],EAX
    m.w32((s.si+0x00000018u), s.ax);
  }
  L0066ab0e: { // 0x66ab0e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x66ab0f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x66ab10: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0026ad30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x66ad30: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x66ad34: 83c10c ADD ECX,0xc
    s.cx = integer::add(s.cx,0x0000000cu,32,flags);
  }
  { // 0x66ad37: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x66ad38: e853f9ffff CALL 0x0066a690
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x66ad3d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0026ad80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x66ad80: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x66ad84: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  { // 0x66ad87: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x66ad88: e803f9ffff CALL 0x0066a690
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x66ad8d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00271ba0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x671ba0: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x671ba4: 8b81d84e0000 MOV EAX,dword ptr [ECX + 0x4ed8]
    s.ax = m.r32((s.cx+0x00004ed8u));
  }
  { // 0x671baa: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x671bac: 752b JNZ 0x00671bd9
    if(integer::condition("JNZ",flags)) goto L00671bd9;
  }
  { // 0x671bae: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x671bb0: c681e24e000001 MOV byte ptr [ECX + 0x4ee2],0x1
    m.w8((s.cx+0x00004ee2u), 0x00000001u);
  }
  { // 0x671bb7: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x671bba: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x671bbc: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x671bbe: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x671bc1: 8d0442 LEA EAX,[EDX + EAX*0x2]
    s.ax = (s.dx+(s.ax * 0x00000002u));
  }
  { // 0x671bc4: 8d1440 LEA EDX,[EAX + EAX*0x2]
    s.dx = (s.ax+(s.ax * 0x00000002u));
  }
  { // 0x671bc7: c684917815000001 MOV byte ptr [ECX + EDX*0x4 + 0x1578],0x1
    m.w8((s.cx+(s.dx * 0x00000004u)+0x00001578u), 0x00000001u);
  }
  { // 0x671bcf: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x671bd4: e857e4e6ff CALL 0x004e0030
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L00671bd9: { // 0x671bd9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00277000(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x677000: 83f90f CMP ECX,0xf
    (void)integer::sub(s.cx,0x0000000fu,32,flags);
  }
  { // 0x677003: 745a JZ 0x0067705f
    if(integer::condition("JZ",flags)) goto L0067705f;
  }
  { // 0x677005: 83f910 CMP ECX,0x10
    (void)integer::sub(s.cx,0x00000010u,32,flags);
  }
  { // 0x677008: 7455 JZ 0x0067705f
    if(integer::condition("JZ",flags)) goto L0067705f;
  }
  { // 0x67700a: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  { // 0x67700d: 7448 JZ 0x00677057
    if(integer::condition("JZ",flags)) goto L00677057;
  }
  { // 0x67700f: 83f928 CMP ECX,0x28
    (void)integer::sub(s.cx,0x00000028u,32,flags);
  }
  { // 0x677012: 7443 JZ 0x00677057
    if(integer::condition("JZ",flags)) goto L00677057;
  }
  { // 0x677014: 83f902 CMP ECX,0x2
    (void)integer::sub(s.cx,0x00000002u,32,flags);
  }
  { // 0x677017: 743e JZ 0x00677057
    if(integer::condition("JZ",flags)) goto L00677057;
  }
  { // 0x677019: 83f903 CMP ECX,0x3
    (void)integer::sub(s.cx,0x00000003u,32,flags);
  }
  { // 0x67701c: 7439 JZ 0x00677057
    if(integer::condition("JZ",flags)) goto L00677057;
  }
  { // 0x67701e: 83f906 CMP ECX,0x6
    (void)integer::sub(s.cx,0x00000006u,32,flags);
  }
  { // 0x677021: 7422 JZ 0x00677045
    if(integer::condition("JZ",flags)) goto L00677045;
  }
  { // 0x677023: 83f907 CMP ECX,0x7
    (void)integer::sub(s.cx,0x00000007u,32,flags);
  }
  { // 0x677026: 741d JZ 0x00677045
    if(integer::condition("JZ",flags)) goto L00677045;
  }
  { // 0x677028: 83f939 CMP ECX,0x39
    (void)integer::sub(s.cx,0x00000039u,32,flags);
  }
  { // 0x67702b: 7410 JZ 0x0067703d
    if(integer::condition("JZ",flags)) goto L0067703d;
  }
  { // 0x67702d: 83f920 CMP ECX,0x20
    (void)integer::sub(s.cx,0x00000020u,32,flags);
  }
  { // 0x677030: 740b JZ 0x0067703d
    if(integer::condition("JZ",flags)) goto L0067703d;
  }
  { // 0x677032: 83f91f CMP ECX,0x1f
    (void)integer::sub(s.cx,0x0000001fu,32,flags);
  }
  { // 0x677035: 7406 JZ 0x0067703d
    if(integer::condition("JZ",flags)) goto L0067703d;
  }
  { // 0x677037: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x67703a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0067703d: { // 0x67703d: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x677042: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00677045: { // 0x677045: e8263ae7ff CALL 0x004eaa70
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x67704a: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x67704c: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  { // 0x67704f: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x677052: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x677054: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00677057: { // 0x677057: b803000000 MOV EAX,0x3
    s.ax = 0x00000003u;
  }
  { // 0x67705c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0067705f: { // 0x67705f: b802000000 MOV EAX,0x2
    s.ax = 0x00000002u;
  }
  { // 0x677064: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002779c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6779c0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x6779c4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6779c5: e8a628fbff CALL 0x0062a270
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6779ca: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002779d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6779d0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x6779d4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6779d5: e8b62afbff CALL 0x0062a490
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6779da: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00277c20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x677c20: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x677c24: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x677c25: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x677c27: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x677c28: e8c3d2ecff CALL 0x00544ef0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x677c2d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x677c2f: 8886c8110000 MOV byte ptr [ESI + 0x11c8],AL
    m.w8((s.si+0x000011c8u), (s.ax & 0xffu));
  }
  { // 0x677c35: 8886c9110000 MOV byte ptr [ESI + 0x11c9],AL
    m.w8((s.si+0x000011c9u), (s.ax & 0xffu));
  }
  { // 0x677c3b: 8886ca110000 MOV byte ptr [ESI + 0x11ca],AL
    m.w8((s.si+0x000011cau), (s.ax & 0xffu));
  }
  { // 0x677c41: c7061c997800 MOV dword ptr [ESI],0x78991c
    m.w32((s.si), 0x0078991cu);
  }
  { // 0x677c47: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x677c49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x677c4a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00282120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x682120: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x682124: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x682126: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x682128: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x682129: e8d2fbffff CALL 0x00681d00
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x68212e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0028f7d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x68f7d0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x68f7d3: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x68f7d7: e8f4020000 CALL 0x0068fad0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x68f7dc: a3c84faa00 MOV [0x00aa4fc8],EAX
    m.w32((0x00aa4fc8u), s.ax);
  }
  { // 0x68f7e1: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x68f7e5: a3cc4faa00 MOV [0x00aa4fcc],EAX
    m.w32((0x00aa4fccu), s.ax);
  }
  { // 0x68f7ea: c6053450aa0001 MOV byte ptr [0x00aa5034],0x1
    m.w8((0x00aa5034u), 0x00000001u);
  }
  { // 0x68f7f1: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x68f7f4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0028f800(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x68f800: b9cc4faa00 MOV ECX,0xaa4fcc
    s.cx = 0x00aa4fccu;
  }
  { // 0x68f805: e8c6020000 CALL 0x0068fad0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x68f80a: 8b0dc84faa00 MOV ECX,dword ptr [0x00aa4fc8]
    s.cx = m.r32((0x00aa4fc8u));
  }
  { // 0x68f810: c6053450aa0000 MOV byte ptr [0x00aa5034],0x0
    m.w8((0x00aa5034u), 0x00000000u);
  }
  { // 0x68f817: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x68f819: a3e84faa00 MOV [0x00aa4fe8],EAX
    m.w32((0x00aa4fe8u), s.ax);
  }
  { // 0x68f81e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002914d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6914d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6914d1: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x6914d3: e828ffffff CALL 0x00691400
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6914d8: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x6914da: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6914db: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00295160(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x695160: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x695164: e817010000 CALL 0x00695280
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x695169: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x69516b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002976f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6976f0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x6976f4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6976f5: e806fffdff CALL 0x00677600
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6976fa: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0029aa30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x69aa30: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x69aa34: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x69aa35: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x69aa37: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x69aa39: 751c JNZ 0x0069aa57
    if(integer::condition("JNZ",flags)) goto L0069aa57;
  }
  { // 0x69aa3b: 66894624 MOV word ptr [ESI + 0x24],AX
    m.w16((s.si+0x00000024u), (s.ax & 0xffffu));
  }
  { // 0x69aa3f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x69aa43: c786a4000000ffffffff MOV dword ptr [ESI + 0xa4],0xffffffff
    m.w32((s.si+0x000000a4u), 0xffffffffu);
  }
  { // 0x69aa4d: 8986a4000000 MOV dword ptr [ESI + 0xa4],EAX
    m.w32((s.si+0x000000a4u), s.ax);
  }
  { // 0x69aa53: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x69aa54: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0069aa57: { // 0x69aa57: 8d4e24 LEA ECX,[ESI + 0x24]
    s.cx = (s.si+0x00000024u);
  }
  { // 0x69aa5a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x69aa5b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x69aa5c: e868450d00 CALL 0x0076efc9
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x69aa61: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x69aa65: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x69aa68: 8996a4000000 MOV dword ptr [ESI + 0xa4],EDX
    m.w32((s.si+0x000000a4u), s.dx);
  }
  { // 0x69aa6e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x69aa6f: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0029c750(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x69c750: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x69c754: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x69c759: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x69c75a: e8318deaff CALL 0x00545490
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x69c75f: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x69c761: 8a881c010000 MOV CL,byte ptr [EAX + 0x11c]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000011cu)));
  }
  { // 0x69c767: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x69c769: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002a7900(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a7900: 8b4974 MOV ECX,dword ptr [ECX + 0x74]
    s.cx = m.r32((s.cx+0x00000074u));
  }
  { // 0x6a7903: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  { // 0x6a7906: 740c JZ 0x006a7914
    if(integer::condition("JZ",flags)) goto L006a7914;
  }
  { // 0x6a7908: e85353e4ff CALL 0x004ecc60
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6a790d: c6803a01000000 MOV byte ptr [EAX + 0x13a],0x0
    m.w8((s.ax+0x0000013au), 0x00000000u);
  }
  L006a7914: { // 0x6a7914: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a7916: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002a7e60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a7e60: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x6a7e62: 8b4830 MOV ECX,dword ptr [EAX + 0x30]
    s.cx = m.r32((s.ax+0x00000030u));
  }
  { // 0x6a7e65: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6a7e67: 7410 JZ 0x006a7e79
    if(integer::condition("JZ",flags)) goto L006a7e79;
  }
  { // 0x6a7e69: 8b5044 MOV EDX,dword ptr [EAX + 0x44]
    s.dx = m.r32((s.ax+0x00000044u));
  }
  { // 0x6a7e6c: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  { // 0x6a7e6f: 7408 JZ 0x006a7e79
    if(integer::condition("JZ",flags)) goto L006a7e79;
  }
  { // 0x6a7e71: e89a9ff8ff CALL 0x00631e10
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6a7e76: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L006a7e79: { // 0x6a7e79: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6a7e7b: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002a8580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a8580: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x6a8582: 8b4830 MOV ECX,dword ptr [EAX + 0x30]
    s.cx = m.r32((s.ax+0x00000030u));
  }
  { // 0x6a8585: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6a8587: 7409 JZ 0x006a8592
    if(integer::condition("JZ",flags)) goto L006a8592;
  }
  { // 0x6a8589: 8b4074 MOV EAX,dword ptr [EAX + 0x74]
    s.ax = m.r32((s.ax+0x00000074u));
  }
  { // 0x6a858c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6a858d: e8ced10000 CALL 0x006b5760
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L006a8592: { // 0x6a8592: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a8594: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002a86b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a86b0: 8b4174 MOV EAX,dword ptr [ECX + 0x74]
    s.ax = m.r32((s.cx+0x00000074u));
  }
  { // 0x6a86b3: 8b150887a200 MOV EDX,dword ptr [0x00a28708]
    s.dx = m.r32((0x00a28708u));
  }
  { // 0x6a86b9: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x6a86bb: 7d21 JGE 0x006a86de
    if(integer::condition("JGE",flags)) goto L006a86de;
  }
  { // 0x6a86bd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a86bf: 7c1d JL 0x006a86de
    if(integer::condition("JL",flags)) goto L006a86de;
  }
  { // 0x6a86c1: 8b15fc86a200 MOV EDX,dword ptr [0x00a286fc]
    s.dx = m.r32((0x00a286fcu));
  }
  { // 0x6a86c7: 8b4948 MOV ECX,dword ptr [ECX + 0x48]
    s.cx = m.r32((s.cx+0x00000048u));
  }
  { // 0x6a86ca: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6a86cb: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6a86d0: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x6a86d3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6a86d4: e807f3fcff CALL 0x006779e0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6a86d9: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a86db: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L006a86de: { // 0x6a86de: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6a86e0: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002a8850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a8850: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x6a8854: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a8855: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a8857: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6a8859: 7508 JNZ 0x006a8863
    if(integer::condition("JNZ",flags)) goto L006a8863;
  }
  { // 0x6a885b: 8806 MOV byte ptr [ESI],AL
    m.w8((s.si), (s.ax & 0xffu));
  }
  { // 0x6a885d: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6a885f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a8860: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006a8863: { // 0x6a8863: 6a1f PUSH 0x1f
    f.push(m,0x0000001fu);
  }
  { // 0x6a8865: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6a8866: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a8867: e8a4540c00 CALL 0x0076dd10
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6a886c: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x6a886f: c6461f00 MOV byte ptr [ESI + 0x1f],0x0
    m.w8((s.si+0x0000001fu), 0x00000000u);
  }
  { // 0x6a8873: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6a8875: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a8876: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002abc60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6abc60: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6abc61: 8079040b CMP byte ptr [ECX + 0x4],0xb
    (void)integer::sub(m.r8((s.cx+0x00000004u)),0x0000000bu,8,flags);
  }
  { // 0x6abc65: 753a JNZ 0x006abca1
    if(integer::condition("JNZ",flags)) goto L006abca1;
  }
  { // 0x6abc67: 8b09 MOV ECX,dword ptr [ECX]
    s.cx = m.r32((s.cx));
  }
  { // 0x6abc69: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6abc6a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x6abc6c: bee8030000 MOV ESI,0x3e8
    s.si = 0x000003e8u;
  }
  { // 0x6abc71: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x6abc72: f7fe IDIV ESI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.si,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  { // 0x6abc74: b8d34d6210 MOV EAX,0x10624dd3
    s.ax = 0x10624dd3u;
  }
  { // 0x6abc79: 6689542404 MOV word ptr [ESP + 0x4],DX
    m.w16((f.sp+0x00000004u), (s.dx & 0xffffu));
  }
  { // 0x6abc7e: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  { // 0x6abc80: c1fa06 SAR EDX,0x6
    s.dx = integer::shift(s.dx,0x00000006u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x6abc83: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x6abc85: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x6abc89: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  { // 0x6abc8c: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x6abc8e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6abc8f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6abc94: 668954240a MOV word ptr [ESP + 0xa],DX
    m.w16((f.sp+0x0000000au), (s.dx & 0xffffu));
  }
  { // 0x6abc99: e86298e9ff CALL 0x00545500
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6abc9e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6abc9f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6abca0: c3 RET
    finish(m,s,f,0u); return;
  }
  L006abca1: { // 0x6abca1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6abca3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6abca4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002adeb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6adeb0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6adeb1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6adeb2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6adeb4: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  { // 0x6adeb6: 8b4654 MOV EAX,dword ptr [ESI + 0x54]
    s.ax = m.r32((s.si+0x00000054u));
  }
  { // 0x6adeb9: 885e7f MOV byte ptr [ESI + 0x7f],BL
    m.w8((s.si+0x0000007fu), (s.bx & 0xffu));
  }
  { // 0x6adebc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6adebe: 885e78 MOV byte ptr [ESI + 0x78],BL
    m.w8((s.si+0x00000078u), (s.bx & 0xffu));
  }
  { // 0x6adec1: c6467a00 MOV byte ptr [ESI + 0x7a],0x0
    m.w8((s.si+0x0000007au), 0x00000000u);
  }
  { // 0x6adec5: 741e JZ 0x006adee5
    if(integer::condition("JZ",flags)) goto L006adee5;
  }
  L006adec7: { // 0x6adec7: 8a4e7b MOV CL,byte ptr [ESI + 0x7b]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000007bu)));
  }
  { // 0x6adeca: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x6adecc: 7507 JNZ 0x006aded5
    if(integer::condition("JNZ",flags)) goto L006aded5;
  }
  { // 0x6adece: 8a4e77 MOV CL,byte ptr [ESI + 0x77]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000077u)));
  }
  { // 0x6aded1: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x6aded3: 7406 JZ 0x006adedb
    if(integer::condition("JZ",flags)) goto L006adedb;
  }
  L006aded5: { // 0x6aded5: 889879050000 MOV byte ptr [EAX + 0x579],BL
    m.w8((s.ax+0x00000579u), (s.bx & 0xffu));
  }
  L006adedb: { // 0x6adedb: 8b80c8040000 MOV EAX,dword ptr [EAX + 0x4c8]
    s.ax = m.r32((s.ax+0x000004c8u));
  }
  { // 0x6adee1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6adee3: 75e2 JNZ 0x006adec7
    if(integer::condition("JNZ",flags)) goto L006adec7;
  }
  L006adee5: { // 0x6adee5: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  { // 0x6adee8: e8c319fbff CALL 0x0065f8b0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6adeed: 889e80000000 MOV byte ptr [ESI + 0x80],BL
    m.w8((s.si+0x00000080u), (s.bx & 0xffu));
  }
  { // 0x6adef3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6adef4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6adef5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002b1860(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b1860: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b1861: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6b1863: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  { // 0x6b1869: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6b186b: e8c05be3ff CALL 0x004e7430
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6b1870: c6868000000001 MOV byte ptr [ESI + 0x80],0x1
    m.w8((s.si+0x00000080u), 0x00000001u);
  }
  { // 0x6b1877: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b1878: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002b1880(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b1880: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b1881: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6b1883: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  { // 0x6b1889: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6b188b: e8905de3ff CALL 0x004e7620
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6b1890: c6868000000001 MOV byte ptr [ESI + 0x80],0x1
    m.w8((s.si+0x00000080u), 0x00000001u);
  }
  { // 0x6b1897: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b1898: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002b1bc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b1bc0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b1bc1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6b1bc3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6b1bc8: e8f351eaff CALL 0x00556dc0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6b1bcd: c6868000000001 MOV byte ptr [ESI + 0x80],0x1
    m.w8((s.si+0x00000080u), 0x00000001u);
  }
  { // 0x6b1bd4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b1bd5: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002b1be0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b1be0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b1be1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6b1be3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6b1be8: e8f353eaff CALL 0x00556fe0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6b1bed: c6868000000001 MOV byte ptr [ESI + 0x80],0x1
    m.w8((s.si+0x00000080u), 0x00000001u);
  }
  { // 0x6b1bf4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b1bf5: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002b3cf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b3cf0: 8b4928 MOV ECX,dword ptr [ECX + 0x28]
    s.cx = m.r32((s.cx+0x00000028u));
  }
  { // 0x6b3cf3: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x6b3cf6: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x6b3cfa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6b3cfb: e820bbfaff CALL 0x0065f820
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6b3d00: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x6b3d02: 83f836 CMP EAX,0x36
    (void)integer::sub(s.ax,0x00000036u,32,flags);
  }
  { // 0x6b3d05: 7415 JZ 0x006b3d1c
    if(integer::condition("JZ",flags)) goto L006b3d1c;
  }
  { // 0x6b3d07: 83f835 CMP EAX,0x35
    (void)integer::sub(s.ax,0x00000035u,32,flags);
  }
  { // 0x6b3d0a: 7410 JZ 0x006b3d1c
    if(integer::condition("JZ",flags)) goto L006b3d1c;
  }
  { // 0x6b3d0c: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  { // 0x6b3d12: 8b8184130000 MOV EAX,dword ptr [ECX + 0x1384]
    s.ax = m.r32((s.cx+0x00001384u));
  }
  { // 0x6b3d18: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6b3d1b: c3 RET
    finish(m,s,f,0u); return;
  }
  L006b3d1c: { // 0x6b3d1c: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  { // 0x6b3d22: 8b8288130000 MOV EAX,dword ptr [EDX + 0x1388]
    s.ax = m.r32((s.dx+0x00001388u));
  }
  { // 0x6b3d28: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6b3d2b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002b50e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b50e0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6b50e1: 8b81cc000000 MOV EAX,dword ptr [ECX + 0xcc]
    s.ax = m.r32((s.cx+0x000000ccu));
  }
  { // 0x6b50e7: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x6b50ea: 7510 JNZ 0x006b50fc
    if(integer::condition("JNZ",flags)) goto L006b50fc;
  }
  { // 0x6b50ec: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x6b50f0: 8b0dd07baa00 MOV ECX,dword ptr [0x00aa7bd0]
    s.cx = m.r32((0x00aa7bd0u));
  }
  { // 0x6b50f6: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x6b50f8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6b50f9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006b50fc: { // 0x6b50fc: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  { // 0x6b5102: 8d542400 LEA EDX,[ESP]
    s.dx = (f.sp);
  }
  { // 0x6b5106: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6b5107: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6b5108: e82350faff CALL 0x0065a130
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6b510d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x6b510f: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x6b5113: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x6b5115: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6b5116: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002b5120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b5120: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6b5121: 8b81d0000000 MOV EAX,dword ptr [ECX + 0xd0]
    s.ax = m.r32((s.cx+0x000000d0u));
  }
  { // 0x6b5127: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x6b512a: 7510 JNZ 0x006b513c
    if(integer::condition("JNZ",flags)) goto L006b513c;
  }
  { // 0x6b512c: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x6b5130: 8b0dd07baa00 MOV ECX,dword ptr [0x00aa7bd0]
    s.cx = m.r32((0x00aa7bd0u));
  }
  { // 0x6b5136: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x6b5138: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6b5139: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006b513c: { // 0x6b513c: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  { // 0x6b5142: 8d542400 LEA EDX,[ESP]
    s.dx = (f.sp);
  }
  { // 0x6b5146: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6b5147: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6b5148: e8e34ffaff CALL 0x0065a130
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6b514d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x6b514f: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x6b5153: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x6b5155: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6b5156: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002b7b90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b7b90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b7b91: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6b7b93: 8a8673030000 MOV AL,byte ptr [ESI + 0x373]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000373u)));
  }
  { // 0x6b7b99: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6b7b9b: 7415 JZ 0x006b7bb2
    if(integer::condition("JZ",flags)) goto L006b7bb2;
  }
  { // 0x6b7b9d: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x6b7ba3: e848cce3ff CALL 0x004f47f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6b7ba8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6b7baa: 7506 JNZ 0x006b7bb2
    if(integer::condition("JNZ",flags)) goto L006b7bb2;
  }
  { // 0x6b7bac: 888673030000 MOV byte ptr [ESI + 0x373],AL
    m.w8((s.si+0x00000373u), (s.ax & 0xffu));
  }
  L006b7bb2: { // 0x6b7bb2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b7bb3: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002cbff0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6cbff0: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6cbff4: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x6cbff8: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x6cbffc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6cbffd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6cbffe: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6cbfff: e8bc22f6ff CALL 0x0062e2c0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6cc004: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6cc006: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_002cca40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6cca40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6cca41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6cca43: 8b86a4010000 MOV EAX,dword ptr [ESI + 0x1a4]
    s.ax = m.r32((s.si+0x000001a4u));
  }
  { // 0x6cca49: 8b8ea0010000 MOV ECX,dword ptr [ESI + 0x1a0]
    s.cx = m.r32((s.si+0x000001a0u));
  }
  { // 0x6cca4f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6cca50: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6cca51: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6cca52: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6cca57: e834c5f5ff CALL 0x00628f90
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6cca5c: c6867b03000001 MOV byte ptr [ESI + 0x37b],0x1
    m.w8((s.si+0x0000037bu), 0x00000001u);
  }
  { // 0x6cca63: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cca64: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002cca70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6cca70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6cca71: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6cca73: 8b86a4010000 MOV EAX,dword ptr [ESI + 0x1a4]
    s.ax = m.r32((s.si+0x000001a4u));
  }
  { // 0x6cca79: 8b8ea0010000 MOV ECX,dword ptr [ESI + 0x1a0]
    s.cx = m.r32((s.si+0x000001a0u));
  }
  { // 0x6cca7f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6cca80: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6cca81: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6cca82: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6cca87: e8e4c6f5ff CALL 0x00629170
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6cca8c: c6867b03000000 MOV byte ptr [ESI + 0x37b],0x0
    m.w8((s.si+0x0000037bu), 0x00000000u);
  }
  { // 0x6cca93: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cca94: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002ce4d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ce4d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ce4d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6ce4d3: e8f8cf0100 CALL 0x006eb4d0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6ce4d8: 83fe01 CMP ESI,0x1
    (void)integer::sub(s.si,0x00000001u,32,flags);
  }
  { // 0x6ce4db: 750d JNZ 0x006ce4ea
    if(integer::condition("JNZ",flags)) goto L006ce4ea;
  }
  { // 0x6ce4dd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ce4df: 7417 JZ 0x006ce4f8
    if(integer::condition("JZ",flags)) goto L006ce4f8;
  }
  { // 0x6ce4e1: b83e000000 MOV EAX,0x3e
    s.ax = 0x0000003eu;
  }
  { // 0x6ce4e6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ce4e7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006ce4ea: { // 0x6ce4ea: 83fe05 CMP ESI,0x5
    (void)integer::sub(s.si,0x00000005u,32,flags);
  }
  { // 0x6ce4ed: 7509 JNZ 0x006ce4f8
    if(integer::condition("JNZ",flags)) goto L006ce4f8;
  }
  { // 0x6ce4ef: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ce4f1: b83f000000 MOV EAX,0x3f
    s.ax = 0x0000003fu;
  }
  { // 0x6ce4f6: 7502 JNZ 0x006ce4fa
    if(integer::condition("JNZ",flags)) goto L006ce4fa;
  }
  L006ce4f8: { // 0x6ce4f8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006ce4fa: { // 0x6ce4fa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ce4fb: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002cec10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6cec10: 8b9148010000 MOV EDX,dword ptr [ECX + 0x148]
    s.dx = m.r32((s.cx+0x00000148u));
  }
  { // 0x6cec16: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x6cec19: 8b8150010000 MOV EAX,dword ptr [ECX + 0x150]
    s.ax = m.r32((s.cx+0x00000150u));
  }
  { // 0x6cec1f: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  { // 0x6cec22: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6cec23: 8db148010000 LEA ESI,[ECX + 0x148]
    s.si = (s.cx+0x00000148u);
  }
  { // 0x6cec29: 740e JZ 0x006cec39
    if(integer::condition("JZ",flags)) goto L006cec39;
  }
  { // 0x6cec2b: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x6cec31: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x6cec33: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x6cec35: 7d36 JGE 0x006cec6d
    if(integer::condition("JGE",flags)) goto L006cec6d;
  }
  { // 0x6cec37: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006cec39: { // 0x6cec39: 83f80a CMP EAX,0xa
    (void)integer::sub(s.ax,0x0000000au,32,flags);
  }
  { // 0x6cec3c: 7e2f JLE 0x006cec6d
    if(integer::condition("JLE",flags)) goto L006cec6d;
  }
  { // 0x6cec3e: a1c483a200 MOV EAX,[0x00a283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  { // 0x6cec43: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6cec45: 7526 JNZ 0x006cec6d
    if(integer::condition("JNZ",flags)) goto L006cec6d;
  }
  { // 0x6cec47: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x6cec4c: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x6cec4e: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x6cec50: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  { // 0x6cec56: e8e511f6ff CALL 0x0062fe40
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6cec5b: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x6cec61: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  { // 0x6cec63: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x6cec67: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  { // 0x6cec6a: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L006cec6d: { // 0x6cec6d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cec6e: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x6cec71: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002cedc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6cedc0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6cedc1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6cedc3: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x6cedc6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6cedc8: 7504 JNZ 0x006cedce
    if(integer::condition("JNZ",flags)) goto L006cedce;
  }
  { // 0x6cedca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cedcb: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006cedce: { // 0x6cedce: 8a4e0c MOV CL,byte ptr [ESI + 0xc]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000000cu)));
  }
  { // 0x6cedd1: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x6cedd3: 751e JNZ 0x006cedf3
    if(integer::condition("JNZ",flags)) goto L006cedf3;
  }
  { // 0x6cedd5: 6840ee6c00 PUSH 0x6cee40
    f.push(m,0x006cee40u);
  }
  { // 0x6cedda: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x6ceddc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6ceddd: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6ceddf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6cede0: e8a1e80900 CALL 0x0076d686
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6cede5: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x6cede8: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  { // 0x6cedef: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L006cedf3: { // 0x6cedf3: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x6cedf7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6cedf8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6cedf9: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x6cedfb: 8b19 MOV EBX,dword ptr [ECX]
    s.bx = m.r32((s.cx));
  }
  { // 0x6cedfd: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x6cee00: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6cee02: 7e25 JLE 0x006cee29
    if(integer::condition("JLE",flags)) goto L006cee29;
  }
  L006cee04: { // 0x6cee04: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x6cee06: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x6cee07: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x6cee09: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x6cee0b: 8b34c7 MOV ESI,dword ptr [EDI + EAX*0x8]
    s.si = m.r32((s.di+(s.ax * 0x00000008u)));
  }
  { // 0x6cee0e: 8d14c7 LEA EDX,[EDI + EAX*0x8]
    s.dx = (s.di+(s.ax * 0x00000008u));
  }
  { // 0x6cee11: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x6cee13: 7e04 JLE 0x006cee19
    if(integer::condition("JLE",flags)) goto L006cee19;
  }
  { // 0x6cee15: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6cee17: eb0c JMP 0x006cee25
    goto L006cee25;
  }
  L006cee19: { // 0x6cee19: 7416 JZ 0x006cee31
    if(integer::condition("JZ",flags)) goto L006cee31;
  }
  { // 0x6cee1b: 8d7a08 LEA EDI,[EDX + 0x8]
    s.di = (s.dx+0x00000008u);
  }
  { // 0x6cee1e: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  { // 0x6cee21: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x6cee23: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L006cee25: { // 0x6cee25: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6cee27: 7fdb JG 0x006cee04
    if(integer::condition("JG",flags)) goto L006cee04;
  }
  L006cee29: { // 0x6cee29: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6cee2a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6cee2b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6cee2d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cee2e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006cee31: { // 0x6cee31: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6cee32: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6cee33: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x6cee35: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cee36: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002d4b90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6d4b90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6d4b91: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6d4b93: 8a866c0b0000 MOV AL,byte ptr [ESI + 0xb6c]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000b6cu)));
  }
  { // 0x6d4b99: 8d8e6c0b0000 LEA ECX,[ESI + 0xb6c]
    s.cx = (s.si+0x00000b6cu);
  }
  { // 0x6d4b9f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6d4ba1: 740b JZ 0x006d4bae
    if(integer::condition("JZ",flags)) goto L006d4bae;
  }
  { // 0x6d4ba3: e8b863f2ff CALL 0x005faf60
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6d4ba8: 89868c0b0000 MOV dword ptr [ESI + 0xb8c],EAX
    m.w32((s.si+0x00000b8cu), s.ax);
  }
  L006d4bae: { // 0x6d4bae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6d4baf: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002d5210(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6d5210: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6d5211: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6d5213: e8885fe6ff CALL 0x0053b1a0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6d5218: 8b0d887daa00 MOV ECX,dword ptr [0x00aa7d88]
    s.cx = m.r32((0x00aa7d88u));
  }
  { // 0x6d521e: 8d461c LEA EAX,[ESI + 0x1c]
    s.ax = (s.si+0x0000001cu);
  }
  { // 0x6d5221: 894e1c MOV dword ptr [ESI + 0x1c],ECX
    m.w32((s.si+0x0000001cu), s.cx);
  }
  { // 0x6d5224: 8b158c7daa00 MOV EDX,dword ptr [0x00aa7d8c]
    s.dx = m.r32((0x00aa7d8cu));
  }
  { // 0x6d522a: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  { // 0x6d522d: 8b0d907daa00 MOV ECX,dword ptr [0x00aa7d90]
    s.cx = m.r32((0x00aa7d90u));
  }
  { // 0x6d5233: 8d5628 LEA EDX,[ESI + 0x28]
    s.dx = (s.si+0x00000028u);
  }
  { // 0x6d5236: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  { // 0x6d5239: a1887daa00 MOV EAX,[0x00aa7d88]
    s.ax = m.r32((0x00aa7d88u));
  }
  { // 0x6d523e: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  { // 0x6d5240: 8b0d8c7daa00 MOV ECX,dword ptr [0x00aa7d8c]
    s.cx = m.r32((0x00aa7d8cu));
  }
  { // 0x6d5246: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  { // 0x6d5249: a1907daa00 MOV EAX,[0x00aa7d90]
    s.ax = m.r32((0x00aa7d90u));
  }
  { // 0x6d524e: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  { // 0x6d5251: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6d5253: 884634 MOV byte ptr [ESI + 0x34],AL
    m.w8((s.si+0x00000034u), (s.ax & 0xffu));
  }
  { // 0x6d5256: 884635 MOV byte ptr [ESI + 0x35],AL
    m.w8((s.si+0x00000035u), (s.ax & 0xffu));
  }
  { // 0x6d5259: 884636 MOV byte ptr [ESI + 0x36],AL
    m.w8((s.si+0x00000036u), (s.ax & 0xffu));
  }
  { // 0x6d525c: 894638 MOV dword ptr [ESI + 0x38],EAX
    m.w32((s.si+0x00000038u), s.ax);
  }
  { // 0x6d525f: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x6d5265: 894644 MOV dword ptr [ESI + 0x44],EAX
    m.w32((s.si+0x00000044u), s.ax);
  }
  { // 0x6d5268: 894e3c MOV dword ptr [ESI + 0x3c],ECX
    m.w32((s.si+0x0000003cu), s.cx);
  }
  { // 0x6d526b: 894648 MOV dword ptr [ESI + 0x48],EAX
    m.w32((s.si+0x00000048u), s.ax);
  }
  { // 0x6d526e: c70618817900 MOV dword ptr [ESI],0x798118
    m.w32((s.si), 0x00798118u);
  }
  { // 0x6d5274: c7460450807900 MOV dword ptr [ESI + 0x4],0x798050
    m.w32((s.si+0x00000004u), 0x00798050u);
  }
  { // 0x6d527b: c746182c807900 MOV dword ptr [ESI + 0x18],0x79802c
    m.w32((s.si+0x00000018u), 0x0079802cu);
  }
  { // 0x6d5282: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6d5284: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6d5285: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002d7890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6d7890: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x6d7894: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6d7895: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6d7897: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6d7898: 3b4624 CMP EAX,dword ptr [ESI + 0x24]
    (void)integer::sub(s.ax,m.r32((s.si+0x00000024u)),32,flags);
  }
  { // 0x6d789b: 7518 JNZ 0x006d78b5
    if(integer::condition("JNZ",flags)) goto L006d78b5;
  }
  { // 0x6d789d: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x6d78a0: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6d78a2: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x6d78a4: 7425 JZ 0x006d78cb
    if(integer::condition("JZ",flags)) goto L006d78cb;
  }
  { // 0x6d78a6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6d78a8: e823000000 CALL 0x006d78d0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6d78ad: 897e28 MOV dword ptr [ESI + 0x28],EDI
    m.w32((s.si+0x00000028u), s.di);
  }
  { // 0x6d78b0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6d78b1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6d78b2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006d78b5: { // 0x6d78b5: 3b4628 CMP EAX,dword ptr [ESI + 0x28]
    (void)integer::sub(s.ax,m.r32((s.si+0x00000028u)),32,flags);
  }
  { // 0x6d78b8: 7511 JNZ 0x006d78cb
    if(integer::condition("JNZ",flags)) goto L006d78cb;
  }
  { // 0x6d78ba: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6d78bc: 897e28 MOV dword ptr [ESI + 0x28],EDI
    m.w32((s.si+0x00000028u), s.di);
  }
  { // 0x6d78bf: 897e44 MOV dword ptr [ESI + 0x44],EDI
    m.w32((s.si+0x00000044u), s.di);
  }
  { // 0x6d78c2: 897e40 MOV dword ptr [ESI + 0x40],EDI
    m.w32((s.si+0x00000040u), s.di);
  }
  { // 0x6d78c5: 897e3c MOV dword ptr [ESI + 0x3c],EDI
    m.w32((s.si+0x0000003cu), s.di);
  }
  { // 0x6d78c8: 897e38 MOV dword ptr [ESI + 0x38],EDI
    m.w32((s.si+0x00000038u), s.di);
  }
  L006d78cb: { // 0x6d78cb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6d78cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6d78cd: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002dd440(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6dd440: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6dd441: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6dd443: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  { // 0x6dd446: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6dd448: 7405 JZ 0x006dd44f
    if(integer::condition("JZ",flags)) goto L006dd44f;
  }
  { // 0x6dd44a: e891abd2ff CALL 0x00407fe0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L006dd44f: { // 0x6dd44f: c6461101 MOV byte ptr [ESI + 0x11],0x1
    m.w8((s.si+0x00000011u), 0x00000001u);
  }
  { // 0x6dd453: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6dd454: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002de640(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6de640: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6de641: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6de645: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6de646: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6de64a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6de64b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6de64c: e82f1bd3ff CALL 0x00410180
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6de651: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6de653: 7c15 JL 0x006de66a
    if(integer::condition("JL",flags)) goto L006de66a;
  }
  { // 0x6de655: 8b87d4000000 MOV EAX,dword ptr [EDI + 0xd4]
    s.ax = m.r32((s.di+0x000000d4u));
  }
  { // 0x6de65b: 8d0c8504000000 LEA ECX,[EAX*0x4 + 0x4]
    s.cx = ((s.ax * 0x00000004u)+0x00000004u);
  }
  { // 0x6de662: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6de664: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x6de666: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x6de668: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006de66a: { // 0x6de66a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6de66b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6de66c: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002df050(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6df050: e83b9ad4ff CALL 0x00428a90
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6df055: 8b154886aa00 MOV EDX,dword ptr [0x00aa8648]
    s.dx = m.r32((0x00aa8648u));
  }
  { // 0x6df05b: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x6df05d: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x6df05f: 7e1f JLE 0x006df080
    if(integer::condition("JLE",flags)) goto L006df080;
  }
  L006df061: { // 0x6df061: 8b153c86aa00 MOV EDX,dword ptr [0x00aa863c]
    s.dx = m.r32((0x00aa863cu));
  }
  { // 0x6df067: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x6df068: 8b548afc MOV EDX,dword ptr [EDX + ECX*0x4 + -0x4]
    s.dx = m.r32((s.dx+(s.cx * 0x00000004u)-0x00000004u));
  }
  { // 0x6df06c: 8b92f8000000 MOV EDX,dword ptr [EDX + 0xf8]
    s.dx = m.r32((s.dx+0x000000f8u));
  }
  { // 0x6df072: c6040200 MOV byte ptr [EDX + EAX*0x1],0x0
    m.w8((s.dx+(s.ax * 0x00000001u)), 0x00000000u);
  }
  { // 0x6df076: 8b154886aa00 MOV EDX,dword ptr [0x00aa8648]
    s.dx = m.r32((0x00aa8648u));
  }
  { // 0x6df07c: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x6df07e: 7ce1 JL 0x006df061
    if(integer::condition("JL",flags)) goto L006df061;
  }
  L006df080: { // 0x6df080: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e0220(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e0220: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e0221: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x6e0225: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e0226: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e0228: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e022a: 7425 JZ 0x006e0251
    if(integer::condition("JZ",flags)) goto L006e0251;
  }
  { // 0x6e022c: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x6e0230: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x6e0234: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e0235: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6e0236: 68a8ce7b00 PUSH 0x7bcea8
    f.push(m,0x007bcea8u);
  }
  { // 0x6e023b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e023c: e82fee0800 CALL 0x0076f070
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6e0241: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x6e0245: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x6e0249: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x6e024c: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x6e024e: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L006e0251: { // 0x6e0251: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e0252: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6e0253: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002e03e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e03e0: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x6e03e4: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6e03e8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e03e9: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e03eb: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x6e03ef: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6e03f1: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  { // 0x6e03f3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e03f4: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x6e03f8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e03f9: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x6e03fd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6e03fe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e03ff: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e0400: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6e0402: e8092edaff CALL 0x00483210
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6e0407: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e0409: c70630b77800 MOV dword ptr [ESI],0x78b730
    m.w32((s.si), 0x0078b730u);
  }
  { // 0x6e040f: 88462c MOV byte ptr [ESI + 0x2c],AL
    m.w8((s.si+0x0000002cu), (s.ax & 0xffu));
  }
  { // 0x6e0412: 88462d MOV byte ptr [ESI + 0x2d],AL
    m.w8((s.si+0x0000002du), (s.ax & 0xffu));
  }
  { // 0x6e0415: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  { // 0x6e0418: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6e041a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e041b: c21400 RET 0x14
    finish(m,s,f,20u); return;
  }
}
void f_002e1560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e1560: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e1561: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e1563: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x6e1566: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e1568: 7504 JNZ 0x006e156e
    if(integer::condition("JNZ",flags)) goto L006e156e;
  }
  { // 0x6e156a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e156b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006e156e: { // 0x6e156e: 8a4e0c MOV CL,byte ptr [ESI + 0xc]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000000cu)));
  }
  { // 0x6e1571: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x6e1573: 751e JNZ 0x006e1593
    if(integer::condition("JNZ",flags)) goto L006e1593;
  }
  { // 0x6e1575: 68e0156e00 PUSH 0x6e15e0
    f.push(m,0x006e15e0u);
  }
  { // 0x6e157a: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x6e157c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e157d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6e157f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e1580: e801c10800 CALL 0x0076d686
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6e1585: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x6e1588: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  { // 0x6e158f: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L006e1593: { // 0x6e1593: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x6e1597: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6e1598: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e1599: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x6e159b: 8b19 MOV EBX,dword ptr [ECX]
    s.bx = m.r32((s.cx));
  }
  { // 0x6e159d: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x6e15a0: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6e15a2: 7e25 JLE 0x006e15c9
    if(integer::condition("JLE",flags)) goto L006e15c9;
  }
  L006e15a4: { // 0x6e15a4: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x6e15a6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x6e15a7: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x6e15a9: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x6e15ab: 8b34c7 MOV ESI,dword ptr [EDI + EAX*0x8]
    s.si = m.r32((s.di+(s.ax * 0x00000008u)));
  }
  { // 0x6e15ae: 8d14c7 LEA EDX,[EDI + EAX*0x8]
    s.dx = (s.di+(s.ax * 0x00000008u));
  }
  { // 0x6e15b1: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x6e15b3: 7604 JBE 0x006e15b9
    if(integer::condition("JBE",flags)) goto L006e15b9;
  }
  { // 0x6e15b5: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6e15b7: eb0c JMP 0x006e15c5
    goto L006e15c5;
  }
  L006e15b9: { // 0x6e15b9: 7416 JZ 0x006e15d1
    if(integer::condition("JZ",flags)) goto L006e15d1;
  }
  { // 0x6e15bb: 8d7a08 LEA EDI,[EDX + 0x8]
    s.di = (s.dx+0x00000008u);
  }
  { // 0x6e15be: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  { // 0x6e15c1: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x6e15c3: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L006e15c5: { // 0x6e15c5: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6e15c7: 7fdb JG 0x006e15a4
    if(integer::condition("JG",flags)) goto L006e15a4;
  }
  L006e15c9: { // 0x6e15c9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e15ca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6e15cb: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e15cd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e15ce: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006e15d1: { // 0x6e15d1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e15d2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6e15d3: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x6e15d5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e15d6: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002e4ea0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e4ea0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e4ea1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e4ea3: e8f862e5ff CALL 0x0053b1a0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6e4ea8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e4eaa: 8d4e1c LEA ECX,[ESI + 0x1c]
    s.cx = (s.si+0x0000001cu);
  }
  { // 0x6e4ead: 894618 MOV dword ptr [ESI + 0x18],EAX
    m.w32((s.si+0x00000018u), s.ax);
  }
  { // 0x6e4eb0: 8b15388aaa00 MOV EDX,dword ptr [0x00aa8a38]
    s.dx = m.r32((0x00aa8a38u));
  }
  { // 0x6e4eb6: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  { // 0x6e4eb8: 8b153c8aaa00 MOV EDX,dword ptr [0x00aa8a3c]
    s.dx = m.r32((0x00aa8a3cu));
  }
  { // 0x6e4ebe: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  { // 0x6e4ec1: 8b15408aaa00 MOV EDX,dword ptr [0x00aa8a40]
    s.dx = m.r32((0x00aa8a40u));
  }
  { // 0x6e4ec7: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  { // 0x6e4eca: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x6e4ed0: 894e28 MOV dword ptr [ESI + 0x28],ECX
    m.w32((s.si+0x00000028u), s.cx);
  }
  { // 0x6e4ed3: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  { // 0x6e4ed6: 894634 MOV dword ptr [ESI + 0x34],EAX
    m.w32((s.si+0x00000034u), s.ax);
  }
  { // 0x6e4ed9: 884638 MOV byte ptr [ESI + 0x38],AL
    m.w8((s.si+0x00000038u), (s.ax & 0xffu));
  }
  { // 0x6e4edc: c7061c8b7900 MOV dword ptr [ESI],0x798b1c
    m.w32((s.si), 0x00798b1cu);
  }
  { // 0x6e4ee2: c74604548a7900 MOV dword ptr [ESI + 0x4],0x798a54
    m.w32((s.si+0x00000004u), 0x00798a54u);
  }
  { // 0x6e4ee9: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6e4eeb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e4eec: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e6620(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e6620: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e6621: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x6e6625: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e6626: e8b551e5ff CALL 0x0053b7e0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6e662b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e662d: 750c JNZ 0x006e663b
    if(integer::condition("JNZ",flags)) goto L006e663b;
  }
  { // 0x6e662f: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x6e6632: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6e6634: 7405 JZ 0x006e663b
    if(integer::condition("JZ",flags)) goto L006e663b;
  }
  { // 0x6e6636: b807000000 MOV EAX,0x7
    s.ax = 0x00000007u;
  }
  L006e663b: { // 0x6e663b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e663c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002e6880(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e6880: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6e6884: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6e6885: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x6e6887: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e6888: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6e6889: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e688b: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x6e688f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6e6890: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6e6892: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6e6894: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e6895: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e6896: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6e6898: e82383deff CALL 0x004cebc0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x6e689d: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6e68a1: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x6e68a5: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x6e68a9: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  { // 0x6e68ac: 895e24 MOV dword ptr [ESI + 0x24],EBX
    m.w32((s.si+0x00000024u), s.bx);
  }
  { // 0x6e68af: 895e28 MOV dword ptr [ESI + 0x28],EBX
    m.w32((s.si+0x00000028u), s.bx);
  }
  { // 0x6e68b2: 89562c MOV dword ptr [ESI + 0x2c],EDX
    m.w32((s.si+0x0000002cu), s.dx);
  }
  { // 0x6e68b5: 894e34 MOV dword ptr [ESI + 0x34],ECX
    m.w32((s.si+0x00000034u), s.cx);
  }
  { // 0x6e68b8: c74638ffffffff MOV dword ptr [ESI + 0x38],0xffffffff
    m.w32((s.si+0x00000038u), 0xffffffffu);
  }
  { // 0x6e68bf: 895e3c MOV dword ptr [ESI + 0x3c],EBX
    m.w32((s.si+0x0000003cu), s.bx);
  }
  { // 0x6e68c2: 885e40 MOV byte ptr [ESI + 0x40],BL
    m.w8((s.si+0x00000040u), (s.bx & 0xffu));
  }
  { // 0x6e68c5: 885e41 MOV byte ptr [ESI + 0x41],BL
    m.w8((s.si+0x00000041u), (s.bx & 0xffu));
  }
  { // 0x6e68c8: 895e44 MOV dword ptr [ESI + 0x44],EBX
    m.w32((s.si+0x00000044u), s.bx);
  }
  { // 0x6e68cb: 895e48 MOV dword ptr [ESI + 0x48],EBX
    m.w32((s.si+0x00000048u), s.bx);
  }
  { // 0x6e68ce: c706748b7900 MOV dword ptr [ESI],0x798b74
    m.w32((s.si), 0x00798b74u);
  }
  { // 0x6e68d4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6e68d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e68d7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6e68d8: c21400 RET 0x14
    finish(m,s,f,20u); return;
  }
}
} // namespace
const std::array<Entry,114>& entries_b() {
  static const std::array<Entry,114> entries{{
    {0x19b960u,f_0019b960},
    {0x19be10u,f_0019be10},
    {0x19c300u,f_0019c300},
    {0x19cd50u,f_0019cd50},
    {0x19d0a0u,f_0019d0a0},
    {0x19d5e0u,f_0019d5e0},
    {0x19e3e0u,f_0019e3e0},
    {0x1aafc0u,f_001aafc0},
    {0x1ab0d0u,f_001ab0d0},
    {0x1ac030u,f_001ac030},
    {0x1ac7f0u,f_001ac7f0},
    {0x1ac840u,f_001ac840},
    {0x1afb70u,f_001afb70},
    {0x1b0b20u,f_001b0b20},
    {0x1b1820u,f_001b1820},
    {0x1b34f0u,f_001b34f0},
    {0x1b3740u,f_001b3740},
    {0x1b3a90u,f_001b3a90},
    {0x1b63b0u,f_001b63b0},
    {0x1c2540u,f_001c2540},
    {0x1c6240u,f_001c6240},
    {0x1c8440u,f_001c8440},
    {0x1c8a50u,f_001c8a50},
    {0x1c8f90u,f_001c8f90},
    {0x1cab90u,f_001cab90},
    {0x1cada0u,f_001cada0},
    {0x1cdbb0u,f_001cdbb0},
    {0x1d04f0u,f_001d04f0},
    {0x1d0510u,f_001d0510},
    {0x1d0fb0u,f_001d0fb0},
    {0x1d0fe0u,f_001d0fe0},
    {0x1fd960u,f_001fd960},
    {0x2067d0u,f_002067d0},
    {0x2067f0u,f_002067f0},
    {0x2069f0u,f_002069f0},
    {0x208350u,f_00208350},
    {0x208380u,f_00208380},
    {0x208530u,f_00208530},
    {0x208d60u,f_00208d60},
    {0x208ef0u,f_00208ef0},
    {0x2119e0u,f_002119e0},
    {0x227310u,f_00227310},
    {0x227330u,f_00227330},
    {0x227980u,f_00227980},
    {0x2279a0u,f_002279a0},
    {0x22c040u,f_0022c040},
    {0x22de60u,f_0022de60},
    {0x22e140u,f_0022e140},
    {0x234eb0u,f_00234eb0},
    {0x236c90u,f_00236c90},
    {0x250380u,f_00250380},
    {0x2503b0u,f_002503b0},
    {0x2504a0u,f_002504a0},
    {0x252310u,f_00252310},
    {0x255760u,f_00255760},
    {0x258270u,f_00258270},
    {0x258510u,f_00258510},
    {0x25a150u,f_0025a150},
    {0x25e7f0u,f_0025e7f0},
    {0x25f2b0u,f_0025f2b0},
    {0x25f300u,f_0025f300},
    {0x260590u,f_00260590},
    {0x268370u,f_00268370},
    {0x2683f0u,f_002683f0},
    {0x26a9a0u,f_0026a9a0},
    {0x26aab0u,f_0026aab0},
    {0x26ad30u,f_0026ad30},
    {0x26ad80u,f_0026ad80},
    {0x271ba0u,f_00271ba0},
    {0x277000u,f_00277000},
    {0x2779c0u,f_002779c0},
    {0x2779d0u,f_002779d0},
    {0x277c20u,f_00277c20},
    {0x282120u,f_00282120},
    {0x28f7d0u,f_0028f7d0},
    {0x28f800u,f_0028f800},
    {0x2914d0u,f_002914d0},
    {0x295160u,f_00295160},
    {0x2976f0u,f_002976f0},
    {0x29aa30u,f_0029aa30},
    {0x29c750u,f_0029c750},
    {0x2a7900u,f_002a7900},
    {0x2a7e60u,f_002a7e60},
    {0x2a8580u,f_002a8580},
    {0x2a86b0u,f_002a86b0},
    {0x2a8850u,f_002a8850},
    {0x2abc60u,f_002abc60},
    {0x2adeb0u,f_002adeb0},
    {0x2b1860u,f_002b1860},
    {0x2b1880u,f_002b1880},
    {0x2b1bc0u,f_002b1bc0},
    {0x2b1be0u,f_002b1be0},
    {0x2b3cf0u,f_002b3cf0},
    {0x2b50e0u,f_002b50e0},
    {0x2b5120u,f_002b5120},
    {0x2b7b90u,f_002b7b90},
    {0x2cbff0u,f_002cbff0},
    {0x2cca40u,f_002cca40},
    {0x2cca70u,f_002cca70},
    {0x2ce4d0u,f_002ce4d0},
    {0x2cec10u,f_002cec10},
    {0x2cedc0u,f_002cedc0},
    {0x2d4b90u,f_002d4b90},
    {0x2d5210u,f_002d5210},
    {0x2d7890u,f_002d7890},
    {0x2dd440u,f_002dd440},
    {0x2de640u,f_002de640},
    {0x2df050u,f_002df050},
    {0x2e0220u,f_002e0220},
    {0x2e03e0u,f_002e03e0},
    {0x2e1560u,f_002e1560},
    {0x2e4ea0u,f_002e4ea0},
    {0x2e6620u,f_002e6620},
    {0x2e6880u,f_002e6880},
  }}; return entries;
}
} // namespace ra2::recovered::direct_b33
