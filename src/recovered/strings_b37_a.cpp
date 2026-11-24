#include "recovered/strings_b37_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include "recovered/strings_b37_primitives.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::strings_b37 {
namespace {
void f_00002800(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x402800: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x402802: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x402803: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x402804: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x402805: 8d987c010000 LEA EBX,[EAX + 0x17c]
    s.bx = (s.ax+0x0000017cu);
  }
  { // 0x40280b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x40280c: b908000000 MOV ECX,0x8
    s.cx = 0x00000008u;
  }
  { // 0x402811: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  { // 0x402813: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x402815: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  { // 0x402817: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  { // 0x402819: 750d JNZ 0x00402828
    if(integer::condition("JNZ",flags)) goto L00402828;
  }
  { // 0x40281b: 89a89c010000 MOV dword ptr [EAX + 0x19c],EBP
    m.w32((s.ax+0x0000019cu), s.bp);
  }
  { // 0x402821: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x402822: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  { // 0x402824: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x402825: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x402826: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x402827: c3 RET
    finish(m,s,f,0u); return;
  }
  L00402828: { // 0x402828: b908000000 MOV ECX,0x8
    s.cx = 0x00000008u;
  }
  { // 0x40282d: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x40282f: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  { // 0x402831: c7809c01000001000000 MOV dword ptr [EAX + 0x19c],0x1
    m.w32((s.ax+0x0000019cu), 0x00000001u);
  }
  { // 0x40283b: 8b809c010000 MOV EAX,dword ptr [EAX + 0x19c]
    s.ax = m.r32((s.ax+0x0000019cu));
  }
  { // 0x402841: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x402843: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x402844: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x402845: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x402846: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x402847: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00008380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x408380: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x408381: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x408382: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x408383: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x408385: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x408387: e8cb553600 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40838c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x40838e: b908000000 MOV ECX,0x8
    s.cx = 0x00000008u;
  }
  { // 0x408393: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x408395: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x408397: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  { // 0x408399: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x40839b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x40839e: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x4083a1: 893e MOV dword ptr [ESI],EDI
    m.w32((s.si), s.di);
  }
  { // 0x4083a3: 897e04 MOV dword ptr [ESI + 0x4],EDI
    m.w32((s.si+0x00000004u), s.di);
  }
  { // 0x4083a6: 897e14 MOV dword ptr [ESI + 0x14],EDI
    m.w32((s.si+0x00000014u), s.di);
  }
  { // 0x4083a9: 897e18 MOV dword ptr [ESI + 0x18],EDI
    m.w32((s.si+0x00000018u), s.di);
  }
  { // 0x4083ac: e83feeffff CALL 0x004071f0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4083b1: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  { // 0x4083b4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4083b5: e89d553600 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4083ba: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4083bd: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x4083bf: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x4083c1: 7513 JNZ 0x004083d6
    if(integer::condition("JNZ",flags)) goto L004083d6;
  }
  { // 0x4083c3: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x4083c5: 7409 JZ 0x004083d0
    if(integer::condition("JZ",flags)) goto L004083d0;
  }
  { // 0x4083c7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4083c8: e8ae523600 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4083cd: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004083d0: { // 0x4083d0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4083d1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4083d2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4083d4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4083d5: c3 RET
    finish(m,s,f,0u); return;
  }
  L004083d6: { // 0x4083d6: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4083d8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4083d9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4083da: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4083db: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00008710(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x408710: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x408711: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x408712: 68a4000000 PUSH 0xa4
    f.push(m,0x000000a4u);
  }
  { // 0x408717: e83b523600 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40871c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x40871e: b929000000 MOV ECX,0x29
    s.cx = 0x00000029u;
  }
  { // 0x408723: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x408725: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x408727: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  { // 0x408729: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x40872c: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x40872f: e8bceaffff CALL 0x004071f0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x408734: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x408736: 899698000000 MOV dword ptr [ESI + 0x98],EDX
    m.w32((s.si+0x00000098u), s.dx);
  }
  { // 0x40873c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x40873e: 8d463c LEA EAX,[ESI + 0x3c]
    s.ax = (s.si+0x0000003cu);
  }
  L00408741: { // 0x408741: 8970dc MOV dword ptr [EAX + -0x24],ESI
    m.w32((s.ax-0x00000024u), s.si);
  }
  { // 0x408744: 8950f8 MOV dword ptr [EAX + -0x8],EDX
    m.w32((s.ax-0x00000008u), s.dx);
  }
  { // 0x408747: 8948f0 MOV dword ptr [EAX + -0x10],ECX
    m.w32((s.ax-0x00000010u), s.cx);
  }
  { // 0x40874a: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  { // 0x40874c: 8950f4 MOV dword ptr [EAX + -0xc],EDX
    m.w32((s.ax-0x0000000cu), s.dx);
  }
  { // 0x40874f: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x408750: 83c040 ADD EAX,0x40
    s.ax = integer::add(s.ax,0x00000040u,32,flags);
  }
  { // 0x408753: 83f902 CMP ECX,0x2
    (void)integer::sub(s.cx,0x00000002u,32,flags);
  }
  { // 0x408756: 7ce9 JL 0x00408741
    if(integer::condition("JL",flags)) goto L00408741;
  }
  { // 0x408758: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x40875a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x40875b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40875c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00008ca0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x408ca0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x408ca1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x408ca2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x408ca3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x408ca4: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x408ca6: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  { // 0x408ca8: 6a3c PUSH 0x3c
    f.push(m,0x0000003cu);
  }
  { // 0x408caa: e8a84c3600 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x408caf: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x408cb1: b90f000000 MOV ECX,0xf
    s.cx = 0x0000000fu;
  }
  { // 0x408cb6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x408cb8: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x408cba: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  { // 0x408cbc: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x408cbf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x408cc1: e83ae5ffff CALL 0x00407200
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x408cc6: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  { // 0x408ccb: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x408ccd: d3e7 SHL EDI,CL
    s.di = integer::shift(s.di,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x408ccf: 8d042f LEA EAX,[EDI + EBP*0x1]
    s.ax = (s.di+(s.bp * 0x00000001u));
  }
  { // 0x408cd2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x408cd3: e87f4c3600 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x408cd8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x408cdb: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x408cde: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x408ce0: 7514 JNZ 0x00408cf6
    if(integer::condition("JNZ",flags)) goto L00408cf6;
  }
  { // 0x408ce2: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x408ce4: 7409 JZ 0x00408cef
    if(integer::condition("JZ",flags)) goto L00408cef;
  }
  { // 0x408ce6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x408ce7: e88f493600 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x408cec: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00408cef: { // 0x408cef: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x408cf0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x408cf1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x408cf2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x408cf4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x408cf5: c3 RET
    finish(m,s,f,0u); return;
  }
  L00408cf6: { // 0x408cf6: 8d5407ff LEA EDX,[EDI + EAX*0x1 + -0x1]
    s.dx = (s.di+(s.ax * 0x00000001u)-0x00000001u);
  }
  { // 0x408cfa: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x408cfd: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x408cff: 895e14 MOV dword ptr [ESI + 0x14],EBX
    m.w32((s.si+0x00000014u), s.bx);
  }
  { // 0x408d02: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x408d04: 896e1c MOV dword ptr [ESI + 0x1c],EBP
    m.w32((s.si+0x0000001cu), s.bp);
  }
  { // 0x408d07: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x408d08: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  { // 0x408d0a: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x408d0c: 895618 MOV dword ptr [ESI + 0x18],EDX
    m.w32((s.si+0x00000018u), s.dx);
  }
  { // 0x408d0f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x408d10: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x408d11: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x408d12: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0000a180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x40a180: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x40a181: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x40a182: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x40a184: 68e0000000 PUSH 0xe0
    f.push(m,0x000000e0u);
  }
  { // 0x40a189: e8c9373600 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40a18e: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x40a190: b938000000 MOV ECX,0x38
    s.cx = 0x00000038u;
  }
  { // 0x40a195: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x40a197: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x40a199: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  { // 0x40a19b: 899658010000 MOV dword ptr [ESI + 0x158],EDX
    m.w32((s.si+0x00000158u), s.dx);
  }
  { // 0x40a1a1: 8932 MOV dword ptr [EDX],ESI
    m.w32((s.dx), s.si);
  }
  { // 0x40a1a3: c786a801000008010000 MOV dword ptr [ESI + 0x1a8],0x108
    m.w32((s.si+0x000001a8u), 0x00000108u);
  }
  { // 0x40a1ad: c786b001000020040000 MOV dword ptr [ESI + 0x1b0],0x420
    m.w32((s.si+0x000001b0u), 0x00000420u);
  }
  { // 0x40a1b7: 8986ac010000 MOV dword ptr [ESI + 0x1ac],EAX
    m.w32((s.si+0x000001acu), s.ax);
  }
  { // 0x40a1bd: 8986b4010000 MOV dword ptr [ESI + 0x1b4],EAX
    m.w32((s.si+0x000001b4u), s.ax);
  }
  { // 0x40a1c3: 8982b0000000 MOV dword ptr [EDX + 0xb0],EAX
    m.w32((s.dx+0x000000b0u), s.ax);
  }
  { // 0x40a1c9: 89427c MOV dword ptr [EDX + 0x7c],EAX
    m.w32((s.dx+0x0000007cu), s.ax);
  }
  { // 0x40a1cc: 898290000000 MOV dword ptr [EDX + 0x90],EAX
    m.w32((s.dx+0x00000090u), s.ax);
  }
  { // 0x40a1d2: 8982a8000000 MOV dword ptr [EDX + 0xa8],EAX
    m.w32((s.dx+0x000000a8u), s.ax);
  }
  { // 0x40a1d8: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  { // 0x40a1da: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x40a1dd: 8b91ac000000 MOV EDX,dword ptr [ECX + 0xac]
    s.dx = m.r32((s.cx+0x000000acu));
  }
  { // 0x40a1e3: 83c244 ADD EDX,0x44
    s.dx = integer::add(s.dx,0x00000044u,32,flags);
  }
  { // 0x40a1e6: e81586ffff CALL 0x00402800
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x40a1eb: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x40a1ed: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x40a1ee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40a1ef: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00026c60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x426c60: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x426c64: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x426c65: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x426c66: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x426c67: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x426c69: 750b JNZ 0x00426c76
    if(integer::condition("JNZ",flags)) goto L00426c76;
  }
  { // 0x426c6b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x426c6c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x426c6d: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  { // 0x426c72: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x426c73: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00426c76: { // 0x426c76: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x426c7a: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  { // 0x426c7f: bfd0737800 MOV EDI,0x7873d0
    s.di = 0x007873d0u;
  }
  { // 0x426c84: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x426c86: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x426c88: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  { // 0x426c8a: 743b JZ 0x00426cc7
    if(integer::condition("JZ",flags)) goto L00426cc7;
  }
  { // 0x426c8c: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  { // 0x426c91: bff8aa7900 MOV EDI,0x79aaf8
    s.di = 0x0079aaf8u;
  }
  { // 0x426c96: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x426c98: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x426c9a: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  { // 0x426c9c: 7429 JZ 0x00426cc7
    if(integer::condition("JZ",flags)) goto L00426cc7;
  }
  { // 0x426c9e: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x426ca0: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  { // 0x426ca5: bf28dc7800 MOV EDI,0x78dc28
    s.di = 0x0078dc28u;
  }
  { // 0x426caa: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x426cac: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  { // 0x426cae: 750c JNZ 0x00426cbc
    if(integer::condition("JNZ",flags)) goto L00426cbc;
  }
  { // 0x426cb0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x426cb1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x426cb2: c70220a88100 MOV dword ptr [EDX],0x81a820
    m.w32((s.dx), 0x0081a820u);
  }
  { // 0x426cb8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x426cb9: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00426cbc: { // 0x426cbc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x426cbd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x426cbe: b802400080 MOV EAX,0x80004002
    s.ax = 0x80004002u;
  }
  { // 0x426cc3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x426cc4: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00426cc7: { // 0x426cc7: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x426ccb: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  { // 0x426ccd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x426cce: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x426cd0: ff5104 CALL dword ptr [ECX + 0x4]
    const std::uint32_t call_target=m.r32((s.cx+0x00000004u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x426cd3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x426cd4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x426cd5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x426cd7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x426cd8: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00036e40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x436e40: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  { // 0x436e43: 8d5130 LEA EDX,[ECX + 0x30]
    s.dx = (s.cx+0x00000030u);
  }
  { // 0x436e46: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x436e4a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x436e4b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x436e4c: e8ef3b1e00 CALL 0x0061aa40
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x436e51: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x436e53: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  { // 0x436e57: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  { // 0x436e5c: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x436e5e: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x436e60: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x436e61: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x436e62: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  { // 0x436e65: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00053740(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x453740: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x453741: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x453742: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x453746: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x453748: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x45374a: e861dc0100 CALL 0x004713b0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x45374f: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x453751: 7407 JZ 0x0045375a
    if(integer::condition("JZ",flags)) goto L0045375a;
  }
  { // 0x453753: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x453754: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x453756: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x453757: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0045375a: { // 0x45375a: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  { // 0x453760: 83b8c0120000ff CMP dword ptr [EAX + 0x12c0],-0x1
    (void)integer::sub(m.r32((s.ax+0x000012c0u)),0xffffffffu,32,flags);
  }
  { // 0x453767: 7507 JNZ 0x00453770
    if(integer::condition("JNZ",flags)) goto L00453770;
  }
  { // 0x453769: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x45376a: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x45376c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x45376d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00453770: { // 0x453770: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x453772: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  { // 0x453776: 0fbf7f24 MOVSX EDI,word ptr [EDI + 0x24]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000024u)),16));
  }
  { // 0x45377a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x45377b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x45377d: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    const std::uint32_t call_target=m.r32((s.dx+0x000001a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x453783: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  { // 0x453789: 0fbf00 MOVSX EAX,word ptr [EAX]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  { // 0x45378c: 8b91c0120000 MOV EDX,dword ptr [ECX + 0x12c0]
    s.dx = m.r32((s.cx+0x000012c0u));
  }
  { // 0x453792: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x453794: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  { // 0x453796: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x453797: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  { // 0x45379a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x45379b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0006c550(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46c550: 81ec00020000 SUB ESP,0x200
    f.sp = integer::sub(f.sp,0x00000200u,32,flags);
  }
  { // 0x46c556: a0a4488200 MOV AL,[0x008248a4]
    s.ax = with_al(s.ax, m.r8((0x008248a4u)));
  }
  { // 0x46c55b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46c55c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46c55e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x46c55f: 88442408 MOV byte ptr [ESP + 0x8],AL
    m.w8((f.sp+0x00000008u), (s.ax & 0xffu));
  }
  { // 0x46c563: b97f000000 MOV ECX,0x7f
    s.cx = 0x0000007fu;
  }
  { // 0x46c568: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x46c56a: 8d7c2409 LEA EDI,[ESP + 0x9]
    s.di = (f.sp+0x00000009u);
  }
  { // 0x46c56e: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  { // 0x46c570: 8b8c241c020000 MOV ECX,dword ptr [ESP + 0x21c]
    s.cx = m.r32((f.sp+0x0000021cu));
  }
  { // 0x46c577: 8b942418020000 MOV EDX,dword ptr [ESP + 0x218]
    s.dx = m.r32((f.sp+0x00000218u));
  }
  { // 0x46c57e: 66ab STOSW ES:EDI
    string_instruction(m,s,flags,Kind::store,16u,Repeat::single);
  }
  { // 0x46c580: aa STOSB ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::single);
  }
  { // 0x46c581: 8b842414020000 MOV EAX,dword ptr [ESP + 0x214]
    s.ax = m.r32((f.sp+0x00000214u));
  }
  { // 0x46c588: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46c589: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46c58a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46c58b: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  { // 0x46c58f: 68f0a27b00 PUSH 0x7ba2f0
    f.push(m,0x007ba2f0u);
  }
  { // 0x46c594: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46c595: e89a143000 CALL 0x0076da34
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x46c59a: 8b842424020000 MOV EAX,dword ptr [ESP + 0x224]
    s.ax = m.r32((f.sp+0x00000224u));
  }
  { // 0x46c5a1: 8b8c2420020000 MOV ECX,dword ptr [ESP + 0x220]
    s.cx = m.r32((f.sp+0x00000220u));
  }
  { // 0x46c5a8: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x46c5ab: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x46c5af: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46c5b0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46c5b1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46c5b2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46c5b4: e887140a00 CALL 0x0050da40
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x46c5b9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46c5ba: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46c5bb: 81c400020000 ADD ESP,0x200
    f.sp = integer::add(f.sp,0x00000200u,32,flags);
  }
  { // 0x46c5c1: c21400 RET 0x14
    finish(m,s,f,20u); return;
  }
}
void f_00070000(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x470000: 81ec40010000 SUB ESP,0x140
    f.sp = integer::sub(f.sp,0x00000140u,32,flags);
  }
  { // 0x470006: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x470007: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x470009: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x47000b: 744d JZ 0x0047005a
    if(integer::condition("JZ",flags)) goto L0047005a;
  }
  { // 0x47000d: a16cd77b00 MOV EAX,[0x007bd76c]
    s.ax = m.r32((0x007bd76cu));
  }
  { // 0x470012: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x470015: 7440 JZ 0x00470057
    if(integer::condition("JZ",flags)) goto L00470057;
  }
  { // 0x470017: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x47001b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x47001c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x47001d: ff1500527800 CALL dword ptr [0x00785200]
    const std::uint32_t call_target=m.r32((0x00785200u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x470023: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x470026: 752f JNZ 0x00470057
    if(integer::condition("JNZ",flags)) goto L00470057;
  }
  { // 0x470028: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x470029: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47002a: 8d7c2438 LEA EDI,[ESP + 0x38]
    s.di = (f.sp+0x00000038u);
  }
  { // 0x47002e: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x470031: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x470033: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x470035: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x470037: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x470039: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x47003b: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x47003d: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x47003f: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  { // 0x470041: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x470044: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x470046: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  { // 0x470048: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x47004b: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  { // 0x47004d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47004e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47004f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x470050: 81c440010000 ADD ESP,0x140
    f.sp = integer::add(f.sp,0x00000140u,32,flags);
  }
  { // 0x470056: c3 RET
    finish(m,s,f,0u); return;
  }
  L00470057: { // 0x470057: c60300 MOV byte ptr [EBX],0x0
    m.w8((s.bx), 0x00000000u);
  }
  L0047005a: { // 0x47005a: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x47005c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x47005d: 81c440010000 ADD ESP,0x140
    f.sp = integer::add(f.sp,0x00000140u,32,flags);
  }
  { // 0x470063: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0008df70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x48df70: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x48df71: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x48df73: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x48df77: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x48df78: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x48df7a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x48df7b: 7426 JZ 0x0048dfa3
    if(integer::condition("JZ",flags)) goto L0048dfa3;
  }
  { // 0x48df7d: e83e0e2600 CALL 0x006eedc0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x48df82: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x48df84: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x48df87: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x48df89: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x48df8b: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x48df8d: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x48df8f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x48df91: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x48df93: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  { // 0x48df95: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x48df98: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x48df9a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x48df9c: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x48df9f: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  { // 0x48dfa1: eb03 JMP 0x0048dfa6
    goto L0048dfa6;
  }
  L0048dfa3: { // 0x48dfa3: c60300 MOV byte ptr [EBX],0x0
    m.w8((s.bx), 0x00000000u);
  }
  L0048dfa6: { // 0x48dfa6: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x48dfaa: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x48dfac: 742d JZ 0x0048dfdb
    if(integer::condition("JZ",flags)) goto L0048dfdb;
  }
  { // 0x48dfae: e80d0e2600 CALL 0x006eedc0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x48dfb3: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x48dfb5: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x48dfb8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x48dfba: 8d531c LEA EDX,[EBX + 0x1c]
    s.dx = (s.bx+0x0000001cu);
  }
  { // 0x48dfbd: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x48dfbf: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x48dfc1: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x48dfc3: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x48dfc5: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x48dfc7: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x48dfc9: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x48dfcc: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x48dfce: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x48dfd0: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x48dfd3: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  { // 0x48dfd5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x48dfd6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x48dfd7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x48dfd8: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0048dfdb: { // 0x48dfdb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x48dfdc: c6431c00 MOV byte ptr [EBX + 0x1c],0x0
    m.w8((s.bx+0x0000001cu), 0x00000000u);
  }
  { // 0x48dfe0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x48dfe1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x48dfe2: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00091f60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x491f60: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x491f64: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x491f65: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x491f67: 7509 JNZ 0x00491f72
    if(integer::condition("JNZ",flags)) goto L00491f72;
  }
  { // 0x491f69: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  { // 0x491f6e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x491f6f: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00491f72: { // 0x491f72: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x491f76: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x491f77: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x491f78: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  { // 0x491f7d: bff8aa7900 MOV EDI,0x79aaf8
    s.di = 0x0079aaf8u;
  }
  { // 0x491f82: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x491f84: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x491f86: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  { // 0x491f8c: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  { // 0x491f90: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  { // 0x491f92: 7502 JNZ 0x00491f96
    if(integer::condition("JNZ",flags)) goto L00491f96;
  }
  { // 0x491f94: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L00491f96: { // 0x491f96: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x491f98: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  { // 0x491f9d: bf18ab7900 MOV EDI,0x79ab18
    s.di = 0x0079ab18u;
  }
  { // 0x491fa2: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x491fa4: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  { // 0x491fa6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x491fa7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x491fa8: 7502 JNZ 0x00491fac
    if(integer::condition("JNZ",flags)) goto L00491fac;
  }
  { // 0x491faa: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L00491fac: { // 0x491fac: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  { // 0x491faf: 740c JZ 0x00491fbd
    if(integer::condition("JZ",flags)) goto L00491fbd;
  }
  { // 0x491fb1: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  { // 0x491fb3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x491fb4: ff5004 CALL dword ptr [EAX + 0x4]
    const std::uint32_t call_target=m.r32((s.ax+0x00000004u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x491fb7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x491fb9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x491fba: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00491fbd: { // 0x491fbd: b802400080 MOV EAX,0x80004002
    s.ax = 0x80004002u;
  }
  { // 0x491fc2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x491fc3: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00092490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x492490: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x492491: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  { // 0x492495: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x492497: 7509 JNZ 0x004924a2
    if(integer::condition("JNZ",flags)) goto L004924a2;
  }
  { // 0x492499: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  { // 0x49249e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x49249f: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L004924a2: { // 0x4924a2: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4924a6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x4924a7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4924a8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4924a9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4924ab: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  { // 0x4924b0: bf28ab7900 MOV EDI,0x79ab28
    s.di = 0x0079ab28u;
  }
  { // 0x4924b5: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x4924b7: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  { // 0x4924b9: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  { // 0x4924bb: 7412 JZ 0x004924cf
    if(integer::condition("JZ",flags)) goto L004924cf;
  }
  { // 0x4924bd: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x4924bf: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  { // 0x4924c4: bff8aa7900 MOV EDI,0x79aaf8
    s.di = 0x0079aaf8u;
  }
  { // 0x4924c9: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x4924cb: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  { // 0x4924cd: 7504 JNZ 0x004924d3
    if(integer::condition("JNZ",flags)) goto L004924d3;
  }
  L004924cf: { // 0x4924cf: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004924d3: { // 0x4924d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4924d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4924d5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4924d7: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  { // 0x4924d9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4924da: 740c JZ 0x004924e8
    if(integer::condition("JZ",flags)) goto L004924e8;
  }
  { // 0x4924dc: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4924de: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4924df: ff5104 CALL dword ptr [ECX + 0x4]
    const std::uint32_t call_target=m.r32((s.cx+0x00000004u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4924e2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4924e4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4924e5: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L004924e8: { // 0x4924e8: b802400080 MOV EAX,0x80004002
    s.ax = 0x80004002u;
  }
  { // 0x4924ed: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4924ee: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00095fd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x495fd0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x495fd1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x495fd2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x495fd3: 6a6c PUSH 0x6c
    f.push(m,0x0000006cu);
  }
  { // 0x495fd5: e87d792d00 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x495fda: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  { // 0x495fde: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x495fe0: b91b000000 MOV ECX,0x1b
    s.cx = 0x0000001bu;
  }
  { // 0x495fe5: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  { // 0x495fe7: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x495fe9: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  { // 0x495fed: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x495ff0: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x495ff3: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x495ff6: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x495ff8: 7c22 JL 0x0049601c
    if(integer::condition("JL",flags)) goto L0049601c;
  }
  { // 0x495ffa: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x495ffd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x495fff: 7504 JNZ 0x00496005
    if(integer::condition("JNZ",flags)) goto L00496005;
  }
  { // 0x496001: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x496003: 7526 JNZ 0x0049602b
    if(integer::condition("JNZ",flags)) goto L0049602b;
  }
  L00496005: { // 0x496005: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x496008: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x49600a: 7e1f JLE 0x0049602b
    if(integer::condition("JLE",flags)) goto L0049602b;
  }
  { // 0x49600c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x49600e: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x496010: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x496012: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x496013: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x496015: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x496018: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x49601a: 740f JZ 0x0049602b
    if(integer::condition("JZ",flags)) goto L0049602b;
  }
  L0049601c: { // 0x49601c: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x49601f: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x496022: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  { // 0x496025: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x496028: 891c82 MOV dword ptr [EDX + EAX*0x4],EBX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.bx);
  }
  L0049602b: { // 0x49602b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x49602c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49602d: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x496032: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x496033: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000aa320(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4aa320: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4aa321: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4aa323: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4aa324: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4aa326: 6a6c PUSH 0x6c
    f.push(m,0x0000006cu);
  }
  { // 0x4aa328: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x4aa32b: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x4aa32e: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  { // 0x4aa331: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x4aa334: 894614 MOV dword ptr [ESI + 0x14],EAX
    m.w32((s.si+0x00000014u), s.ax);
  }
  { // 0x4aa337: 884618 MOV byte ptr [ESI + 0x18],AL
    m.w8((s.si+0x00000018u), (s.ax & 0xffu));
  }
  { // 0x4aa33a: 884619 MOV byte ptr [ESI + 0x19],AL
    m.w8((s.si+0x00000019u), (s.ax & 0xffu));
  }
  { // 0x4aa33d: 89461c MOV dword ptr [ESI + 0x1c],EAX
    m.w32((s.si+0x0000001cu), s.ax);
  }
  { // 0x4aa340: c706e4bb7800 MOV dword ptr [ESI],0x78bbe4
    m.w32((s.si), 0x0078bbe4u);
  }
  { // 0x4aa346: e80c362c00 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4aa34b: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x4aa34d: b91b000000 MOV ECX,0x1b
    s.cx = 0x0000001bu;
  }
  { // 0x4aa352: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4aa354: 897e20 MOV dword ptr [ESI + 0x20],EDI
    m.w32((s.si+0x00000020u), s.di);
  }
  { // 0x4aa357: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  { // 0x4aa359: 8b4620 MOV EAX,dword ptr [ESI + 0x20]
    s.ax = m.r32((s.si+0x00000020u));
  }
  { // 0x4aa35c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4aa35f: c7006c000000 MOV dword ptr [EAX],0x6c
    m.w32((s.ax), 0x0000006cu);
  }
  { // 0x4aa365: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4aa367: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4aa368: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4aa369: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000ba9c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ba9c0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4ba9c4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4ba9c5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4ba9c6: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4ba9c7: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x4ba9c9: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x4ba9cb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4ba9cc: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4ba9cd: e83e332b00 CALL 0x0076dd10
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4ba9d2: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x4ba9d7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4ba9d8: 66894304 MOV word ptr [EBX + 0x4],AX
    m.w16((s.bx+0x00000004u), (s.ax & 0xffffu));
  }
  { // 0x4ba9dc: 66894306 MOV word ptr [EBX + 0x6],AX
    m.w16((s.bx+0x00000006u), (s.ax & 0xffffu));
  }
  { // 0x4ba9e0: e8722f2b00 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4ba9e5: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x4ba9e7: 8d742424 LEA ESI,[ESP + 0x24]
    s.si = (f.sp+0x00000024u);
  }
  { // 0x4ba9eb: 668b4b06 MOV CX,word ptr [EBX + 0x6]
    s.cx = with_ax(s.cx, m.r16((s.bx+0x00000006u)));
  }
  { // 0x4ba9ef: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x4ba9f1: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x4ba9f3: 894308 MOV dword ptr [EBX + 0x8],EAX
    m.w32((s.bx+0x00000008u), s.ax);
  }
  { // 0x4ba9f6: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x4ba9f9: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x4ba9fb: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  { // 0x4ba9fd: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x4baa00: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x4baa03: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x4baa05: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  { // 0x4baa07: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4baa08: c7430c00000000 MOV dword ptr [EBX + 0xc],0x0
    m.w32((s.bx+0x0000000cu), 0x00000000u);
  }
  { // 0x4baa0f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4baa10: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4baa11: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000baa20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4baa20: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4baa24: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4baa25: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4baa26: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4baa27: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x4baa29: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x4baa2b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4baa2c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4baa2d: e8de322b00 CALL 0x0076dd10
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4baa32: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4baa34: 66c743040200 MOV word ptr [EBX + 0x4],0x2
    m.w16((s.bx+0x00000004u), 0x00000002u);
  }
  { // 0x4baa3a: 66c743060100 MOV word ptr [EBX + 0x6],0x1
    m.w16((s.bx+0x00000006u), 0x00000001u);
  }
  { // 0x4baa40: e8122f2b00 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4baa45: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x4baa47: 8d742424 LEA ESI,[ESP + 0x24]
    s.si = (f.sp+0x00000024u);
  }
  { // 0x4baa4b: 668b4b06 MOV CX,word ptr [EBX + 0x6]
    s.cx = with_ax(s.cx, m.r16((s.bx+0x00000006u)));
  }
  { // 0x4baa4f: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x4baa51: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x4baa53: 894308 MOV dword ptr [EBX + 0x8],EAX
    m.w32((s.bx+0x00000008u), s.ax);
  }
  { // 0x4baa56: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x4baa59: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x4baa5b: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  { // 0x4baa5d: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x4baa60: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x4baa63: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x4baa65: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  { // 0x4baa67: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4baa68: c7430c00000000 MOV dword ptr [EBX + 0xc],0x0
    m.w32((s.bx+0x0000000cu), 0x00000000u);
  }
  { // 0x4baa6f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4baa70: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4baa71: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000bab40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4bab40: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4bab44: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4bab45: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bab46: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4bab47: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x4bab49: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x4bab4b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4bab4c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4bab4d: e8be312b00 CALL 0x0076dd10
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4bab52: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x4bab54: 66c743040500 MOV word ptr [EBX + 0x4],0x5
    m.w16((s.bx+0x00000004u), 0x00000005u);
  }
  { // 0x4bab5a: 66c743060400 MOV word ptr [EBX + 0x6],0x4
    m.w16((s.bx+0x00000006u), 0x00000004u);
  }
  { // 0x4bab60: e8f22d2b00 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4bab65: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x4bab67: 8d742424 LEA ESI,[ESP + 0x24]
    s.si = (f.sp+0x00000024u);
  }
  { // 0x4bab6b: 668b4b06 MOV CX,word ptr [EBX + 0x6]
    s.cx = with_ax(s.cx, m.r16((s.bx+0x00000006u)));
  }
  { // 0x4bab6f: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x4bab71: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x4bab73: 894308 MOV dword ptr [EBX + 0x8],EAX
    m.w32((s.bx+0x00000008u), s.ax);
  }
  { // 0x4bab76: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x4bab79: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x4bab7b: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  { // 0x4bab7d: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x4bab80: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x4bab83: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x4bab85: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  { // 0x4bab87: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4bab88: c7430c00000000 MOV dword ptr [EBX + 0xc],0x0
    m.w32((s.bx+0x0000000cu), 0x00000000u);
  }
  { // 0x4bab8f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bab90: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4bab91: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000baba0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4baba0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4baba4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4baba5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4baba6: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4baba7: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x4baba9: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x4babab: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4babac: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4babad: e85e312b00 CALL 0x0076dd10
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4babb2: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x4babb4: 66c743040600 MOV word ptr [EBX + 0x4],0x6
    m.w16((s.bx+0x00000004u), 0x00000006u);
  }
  { // 0x4babba: 66c743060400 MOV word ptr [EBX + 0x6],0x4
    m.w16((s.bx+0x00000006u), 0x00000004u);
  }
  { // 0x4babc0: e8922d2b00 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4babc5: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x4babc7: 8d742424 LEA ESI,[ESP + 0x24]
    s.si = (f.sp+0x00000024u);
  }
  { // 0x4babcb: 668b4b06 MOV CX,word ptr [EBX + 0x6]
    s.cx = with_ax(s.cx, m.r16((s.bx+0x00000006u)));
  }
  { // 0x4babcf: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x4babd1: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x4babd3: 894308 MOV dword ptr [EBX + 0x8],EAX
    m.w32((s.bx+0x00000008u), s.ax);
  }
  { // 0x4babd6: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x4babd9: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x4babdb: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  { // 0x4babdd: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x4babe0: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x4babe3: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x4babe5: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  { // 0x4babe7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4babe8: c7430c00000000 MOV dword ptr [EBX + 0xc],0x0
    m.w32((s.bx+0x0000000cu), 0x00000000u);
  }
  { // 0x4babef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4babf0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4babf1: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000bac00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4bac00: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4bac04: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4bac05: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bac06: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4bac07: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x4bac09: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x4bac0b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4bac0c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4bac0d: e8fe302b00 CALL 0x0076dd10
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4bac12: 8b742420 MOV ESI,dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  { // 0x4bac16: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x4bac19: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x4bac1b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4bac1d: 66c743040700 MOV word ptr [EBX + 0x4],0x7
    m.w16((s.bx+0x00000004u), 0x00000007u);
  }
  { // 0x4bac23: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x4bac25: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x4bac27: 8d01 LEA EAX,[ECX]
    s.ax = (s.cx);
  }
  { // 0x4bac29: 66894306 MOV word ptr [EBX + 0x6],AX
    m.w16((s.bx+0x00000006u), (s.ax & 0xffffu));
  }
  { // 0x4bac2d: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  { // 0x4bac32: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4bac33: e81f2d2b00 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4bac38: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x4bac3a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x4bac3c: 668b4b06 MOV CX,word ptr [EBX + 0x6]
    s.cx = with_ax(s.cx, m.r16((s.bx+0x00000006u)));
  }
  { // 0x4bac40: 894308 MOV dword ptr [EBX + 0x8],EAX
    m.w32((s.bx+0x00000008u), s.ax);
  }
  { // 0x4bac43: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x4bac45: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x4bac48: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x4bac4b: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x4bac4d: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  { // 0x4bac4f: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x4bac51: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x4bac54: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  { // 0x4bac56: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4bac57: c7430c00000000 MOV dword ptr [EBX + 0xc],0x0
    m.w32((s.bx+0x0000000cu), 0x00000000u);
  }
  { // 0x4bac5e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bac5f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4bac60: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000bac70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4bac70: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4bac74: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4bac75: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bac76: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4bac77: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x4bac79: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x4bac7b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4bac7c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4bac7d: e88e302b00 CALL 0x0076dd10
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4bac82: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  { // 0x4bac86: 66c743041400 MOV word ptr [EBX + 0x4],0x14
    m.w16((s.bx+0x00000004u), 0x00000014u);
  }
  { // 0x4bac8c: 66894306 MOV word ptr [EBX + 0x6],AX
    m.w16((s.bx+0x00000006u), (s.ax & 0xffffu));
  }
  { // 0x4bac90: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  { // 0x4bac95: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4bac96: e8bc2c2b00 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4bac9b: 8b742424 MOV ESI,dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  { // 0x4bac9f: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x4baca1: 668b4b06 MOV CX,word ptr [EBX + 0x6]
    s.cx = with_ax(s.cx, m.r16((s.bx+0x00000006u)));
  }
  { // 0x4baca5: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x4baca7: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x4baca9: 894308 MOV dword ptr [EBX + 0x8],EAX
    m.w32((s.bx+0x00000008u), s.ax);
  }
  { // 0x4bacac: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x4bacaf: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x4bacb1: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  { // 0x4bacb3: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x4bacb6: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x4bacb9: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x4bacbb: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  { // 0x4bacbd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4bacbe: c7430c00000000 MOV dword ptr [EBX + 0xc],0x0
    m.w32((s.bx+0x0000000cu), 0x00000000u);
  }
  { // 0x4bacc5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bacc6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4bacc7: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_000dd810(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4dd810: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4dd811: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x4dd813: 813b80000000 CMP dword ptr [EBX],0x80
    (void)integer::sub(m.r32((s.bx)),0x00000080u,32,flags);
  }
  { // 0x4dd819: 7d4a JGE 0x004dd865
    if(integer::condition("JGE",flags)) goto L004dd865;
  }
  { // 0x4dd81b: 8b4308 MOV EAX,dword ptr [EBX + 0x8]
    s.ax = m.r32((s.bx+0x00000008u));
  }
  { // 0x4dd81e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4dd81f: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4dd823: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4dd824: 8d0cc0 LEA ECX,[EAX + EAX*0x8]
    s.cx = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x4dd827: 8d0488 LEA EAX,[EAX + ECX*0x4]
    s.ax = (s.ax+(s.cx * 0x00000004u));
  }
  { // 0x4dd82a: b91b000000 MOV ECX,0x1b
    s.cx = 0x0000001bu;
  }
  { // 0x4dd82f: 8d1443 LEA EDX,[EBX + EAX*0x2]
    s.dx = (s.bx+(s.ax * 0x00000002u));
  }
  { // 0x4dd832: 8d7c100c LEA EDI,[EAX + EDX*0x1 + 0xc]
    s.di = (s.ax+(s.dx * 0x00000001u)+0x0000000cu);
  }
  { // 0x4dd836: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x4dd838: 66a5 MOVSW ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,16u,Repeat::single);
  }
  { // 0x4dd83a: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  { // 0x4dd83b: ff1524557800 CALL dword ptr [0x00785524]
    const std::uint32_t call_target=m.r32((0x00785524u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4dd841: 8b4b08 MOV ECX,dword ptr [EBX + 0x8]
    s.cx = m.r32((s.bx+0x00000008u));
  }
  { // 0x4dd844: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4dd845: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4dd846: 89848b8c370000 MOV dword ptr [EBX + ECX*0x4 + 0x378c],EAX
    m.w32((s.bx+(s.cx * 0x00000004u)+0x0000378cu), s.ax);
  }
  { // 0x4dd84d: 8b5308 MOV EDX,dword ptr [EBX + 0x8]
    s.dx = m.r32((s.bx+0x00000008u));
  }
  { // 0x4dd850: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  { // 0x4dd852: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  { // 0x4dd853: 83e27f AND EDX,0x7f
    s.dx = integer::logical((s.dx)&(0x0000007fu),32,flags);
  }
  { // 0x4dd856: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x4dd857: 895308 MOV dword ptr [EBX + 0x8],EDX
    m.w32((s.bx+0x00000008u), s.dx);
  }
  { // 0x4dd85a: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  { // 0x4dd85c: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x4dd861: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4dd862: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004dd865: { // 0x4dd865: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4dd867: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4dd868: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000e07d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e07d0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4e07d1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4e07d2: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x4e07d4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4e07d5: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x4e07d9: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x4e07dc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4e07de: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4e07df: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x4e07e1: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x4e07e3: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x4e07e5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x4e07e7: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x4e07e9: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  { // 0x4e07eb: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x4e07ee: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x4e07f0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x4e07f2: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x4e07f5: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  { // 0x4e07f7: e818132a00 CALL 0x00781b14
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4e07fc: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4e07ff: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x4e0801: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4e0802: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e0803: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4e0804: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000e0810(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e0810: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4e0811: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x4e0813: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4e0814: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4e0818: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x4e081b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4e081d: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x4e081f: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x4e0821: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x4e0823: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x4e0825: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x4e0827: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x4e0829: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x4e082c: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x4e082e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x4e0830: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x4e0832: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x4e0835: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  { // 0x4e0837: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4e0838: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e0839: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000e0850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e0850: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4e0851: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x4e0853: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4e0854: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4e0858: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x4e085b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4e085d: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x4e085f: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x4e0861: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x4e0863: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x4e0865: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x4e0867: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x4e0869: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x4e086c: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x4e086e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x4e0870: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x4e0872: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x4e0875: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  { // 0x4e0877: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4e0878: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e0879: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00122ae0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x522ae0: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x522ae4: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x522ae6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x522ae7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x522ae8: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  { // 0x522aeb: 7515 JNZ 0x00522b02
    if(integer::condition("JNZ",flags)) goto L00522b02;
  }
  { // 0x522aed: 8a4801 MOV CL,byte ptr [EAX + 0x1]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000001u)));
  }
  { // 0x522af0: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x522af2: 750e JNZ 0x00522b02
    if(integer::condition("JNZ",flags)) goto L00522b02;
  }
  { // 0x522af4: 8a4802 MOV CL,byte ptr [EAX + 0x2]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000002u)));
  }
  { // 0x522af7: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x522af9: 7507 JNZ 0x00522b02
    if(integer::condition("JNZ",flags)) goto L00522b02;
  }
  { // 0x522afb: 8a4803 MOV CL,byte ptr [EAX + 0x3]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000003u)));
  }
  { // 0x522afe: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x522b00: 741a JZ 0x00522b1c
    if(integer::condition("JZ",flags)) goto L00522b1c;
  }
  L00522b02: { // 0x522b02: 803a00 CMP byte ptr [EDX],0x0
    (void)integer::sub(m.r8((s.dx)),0x00000000u,8,flags);
  }
  { // 0x522b05: 752d JNZ 0x00522b34
    if(integer::condition("JNZ",flags)) goto L00522b34;
  }
  { // 0x522b07: 8a4a01 MOV CL,byte ptr [EDX + 0x1]
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000001u)));
  }
  { // 0x522b0a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x522b0c: 7526 JNZ 0x00522b34
    if(integer::condition("JNZ",flags)) goto L00522b34;
  }
  { // 0x522b0e: 8a4a02 MOV CL,byte ptr [EDX + 0x2]
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000002u)));
  }
  { // 0x522b11: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x522b13: 751f JNZ 0x00522b34
    if(integer::condition("JNZ",flags)) goto L00522b34;
  }
  { // 0x522b15: 8a4a03 MOV CL,byte ptr [EDX + 0x3]
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000003u)));
  }
  { // 0x522b18: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x522b1a: 7518 JNZ 0x00522b34
    if(integer::condition("JNZ",flags)) goto L00522b34;
  }
  L00522b1c: { // 0x522b1c: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  { // 0x522b1f: b903000000 MOV ECX,0x3
    s.cx = 0x00000003u;
  }
  { // 0x522b24: 8d7a04 LEA EDI,[EDX + 0x4]
    s.di = (s.dx+0x00000004u);
  }
  { // 0x522b27: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x522b29: 66f3a7 CMPSW.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,16u,Repeat::equal);
  }
  { // 0x522b2c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x522b2d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x522b2e: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x522b31: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00522b34: { // 0x522b34: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x522b35: b903000000 MOV ECX,0x3
    s.cx = 0x00000003u;
  }
  { // 0x522b3a: 8d7a04 LEA EDI,[EDX + 0x4]
    s.di = (s.dx+0x00000004u);
  }
  { // 0x522b3d: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  { // 0x522b40: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x522b42: 66f3a7 CMPSW.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,16u,Repeat::equal);
  }
  { // 0x522b45: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x522b46: 750f JNZ 0x00522b57
    if(integer::condition("JNZ",flags)) goto L00522b57;
  }
  { // 0x522b48: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x522b4a: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  { // 0x522b4c: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x522b4e: 7507 JNZ 0x00522b57
    if(integer::condition("JNZ",flags)) goto L00522b57;
  }
  { // 0x522b50: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x522b51: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x522b53: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x522b54: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00522b57: { // 0x522b57: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x522b58: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x522b5a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x522b5b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00122b60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x522b60: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x522b64: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x522b66: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x522b67: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x522b68: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  { // 0x522b6b: 7515 JNZ 0x00522b82
    if(integer::condition("JNZ",flags)) goto L00522b82;
  }
  { // 0x522b6d: 8a4801 MOV CL,byte ptr [EAX + 0x1]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000001u)));
  }
  { // 0x522b70: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x522b72: 750e JNZ 0x00522b82
    if(integer::condition("JNZ",flags)) goto L00522b82;
  }
  { // 0x522b74: 8a4802 MOV CL,byte ptr [EAX + 0x2]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000002u)));
  }
  { // 0x522b77: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x522b79: 7507 JNZ 0x00522b82
    if(integer::condition("JNZ",flags)) goto L00522b82;
  }
  { // 0x522b7b: 8a4803 MOV CL,byte ptr [EAX + 0x3]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000003u)));
  }
  { // 0x522b7e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x522b80: 741a JZ 0x00522b9c
    if(integer::condition("JZ",flags)) goto L00522b9c;
  }
  L00522b82: { // 0x522b82: 803a00 CMP byte ptr [EDX],0x0
    (void)integer::sub(m.r8((s.dx)),0x00000000u,8,flags);
  }
  { // 0x522b85: 752d JNZ 0x00522bb4
    if(integer::condition("JNZ",flags)) goto L00522bb4;
  }
  { // 0x522b87: 8a4a01 MOV CL,byte ptr [EDX + 0x1]
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000001u)));
  }
  { // 0x522b8a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x522b8c: 7526 JNZ 0x00522bb4
    if(integer::condition("JNZ",flags)) goto L00522bb4;
  }
  { // 0x522b8e: 8a4a02 MOV CL,byte ptr [EDX + 0x2]
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000002u)));
  }
  { // 0x522b91: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x522b93: 751f JNZ 0x00522bb4
    if(integer::condition("JNZ",flags)) goto L00522bb4;
  }
  { // 0x522b95: 8a4a03 MOV CL,byte ptr [EDX + 0x3]
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000003u)));
  }
  { // 0x522b98: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x522b9a: 7518 JNZ 0x00522bb4
    if(integer::condition("JNZ",flags)) goto L00522bb4;
  }
  L00522b9c: { // 0x522b9c: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  { // 0x522b9f: b903000000 MOV ECX,0x3
    s.cx = 0x00000003u;
  }
  { // 0x522ba4: 8d7a04 LEA EDI,[EDX + 0x4]
    s.di = (s.dx+0x00000004u);
  }
  { // 0x522ba7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x522ba9: 66f3a7 CMPSW.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,16u,Repeat::equal);
  }
  { // 0x522bac: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x522bad: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x522bae: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x522bb1: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00522bb4: { // 0x522bb4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x522bb5: b903000000 MOV ECX,0x3
    s.cx = 0x00000003u;
  }
  { // 0x522bba: 8d7a04 LEA EDI,[EDX + 0x4]
    s.di = (s.dx+0x00000004u);
  }
  { // 0x522bbd: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  { // 0x522bc0: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x522bc2: 66f3a7 CMPSW.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,16u,Repeat::equal);
  }
  { // 0x522bc5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x522bc6: 750f JNZ 0x00522bd7
    if(integer::condition("JNZ",flags)) goto L00522bd7;
  }
  { // 0x522bc8: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x522bca: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  { // 0x522bcc: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x522bce: 7507 JNZ 0x00522bd7
    if(integer::condition("JNZ",flags)) goto L00522bd7;
  }
  { // 0x522bd0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x522bd1: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x522bd3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x522bd4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00522bd7: { // 0x522bd7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x522bd8: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x522bda: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x522bdb: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00122be0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x522be0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x522be1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x522be3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x522be4: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x522be8: b90a000000 MOV ECX,0xa
    s.cx = 0x0000000au;
  }
  { // 0x522bed: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x522bef: f3a6 CMPSB.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,8u,Repeat::equal);
  }
  { // 0x522bf1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x522bf2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x522bf3: 7405 JZ 0x00522bfa
    if(integer::condition("JZ",flags)) goto L00522bfa;
  }
  { // 0x522bf5: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x522bf7: 83d8ff SBB EAX,-0x1
    s.ax = integer::sub(s.ax,0xffffffffu,32,flags,flags&integer::CF);
  }
  L00522bfa: { // 0x522bfa: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x522bfc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x522bfe: 0f9fc1 SETG CL
    s.cx = with_al(s.cx, (integer::condition("JG",flags)?1u:0u));
  }
  { // 0x522c01: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  { // 0x522c03: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00122c10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x522c10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x522c11: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x522c13: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x522c14: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x522c18: b90a000000 MOV ECX,0xa
    s.cx = 0x0000000au;
  }
  { // 0x522c1d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x522c1f: f3a6 CMPSB.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,8u,Repeat::equal);
  }
  { // 0x522c21: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x522c22: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x522c23: 7405 JZ 0x00522c2a
    if(integer::condition("JZ",flags)) goto L00522c2a;
  }
  { // 0x522c25: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x522c27: 83d8ff SBB EAX,-0x1
    s.ax = integer::sub(s.ax,0xffffffffu,32,flags,flags&integer::CF);
  }
  L00522c2a: { // 0x522c2a: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x522c2c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x522c2e: 0f9cc1 SETL CL
    s.cx = with_al(s.cx, (integer::condition("JL",flags)?1u:0u));
  }
  { // 0x522c31: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  { // 0x522c33: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00122c40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x522c40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x522c41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x522c43: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x522c44: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x522c48: b90a000000 MOV ECX,0xa
    s.cx = 0x0000000au;
  }
  { // 0x522c4d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x522c4f: f3a6 CMPSB.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,8u,Repeat::equal);
  }
  { // 0x522c51: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x522c52: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x522c53: 7405 JZ 0x00522c5a
    if(integer::condition("JZ",flags)) goto L00522c5a;
  }
  { // 0x522c55: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x522c57: 83d8ff SBB EAX,-0x1
    s.ax = integer::sub(s.ax,0xffffffffu,32,flags,flags&integer::CF);
  }
  L00522c5a: { // 0x522c5a: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x522c5c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x522c5e: 0f9dc1 SETGE CL
    s.cx = with_al(s.cx, (integer::condition("JGE",flags)?1u:0u));
  }
  { // 0x522c61: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  { // 0x522c63: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00122c70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x522c70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x522c71: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x522c73: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x522c74: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x522c78: b90a000000 MOV ECX,0xa
    s.cx = 0x0000000au;
  }
  { // 0x522c7d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x522c7f: f3a6 CMPSB.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,8u,Repeat::equal);
  }
  { // 0x522c81: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x522c82: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x522c83: 7405 JZ 0x00522c8a
    if(integer::condition("JZ",flags)) goto L00522c8a;
  }
  { // 0x522c85: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x522c87: 83d8ff SBB EAX,-0x1
    s.ax = integer::sub(s.ax,0xffffffffu,32,flags,flags&integer::CF);
  }
  L00522c8a: { // 0x522c8a: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x522c8c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x522c8e: 0f9ec1 SETLE CL
    s.cx = with_al(s.cx, (integer::condition("SETLE",flags)?1u:0u));
  }
  { // 0x522c91: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  { // 0x522c93: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001b75c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b75c0: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x5b75c2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5b75c3: b971000000 MOV ECX,0x71
    s.cx = 0x00000071u;
  }
  { // 0x5b75c8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5b75ca: bf6679a200 MOV EDI,0xa27966
    s.di = 0x00a27966u;
  }
  { // 0x5b75cf: 83c228 ADD EDX,0x28
    s.dx = integer::add(s.dx,0x00000028u,32,flags);
  }
  { // 0x5b75d2: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  { // 0x5b75d4: 66ab STOSW ES:EDI
    string_instruction(m,s,flags,Kind::store,16u,Repeat::single);
  }
  { // 0x5b75d6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5b75d7: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5b75d9: 68c7010000 PUSH 0x1c7
    f.push(m,0x000001c7u);
  }
  { // 0x5b75de: 686679a200 PUSH 0xa27966
    f.push(m,0x00a27966u);
  }
  { // 0x5b75e3: aa STOSB ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::single);
  }
  { // 0x5b75e4: b9c885a200 MOV ECX,0xa285c8
    s.cx = 0x00a285c8u;
  }
  { // 0x5b75e9: c7056679a20008000000 MOV dword ptr [0x00a27966],0x8
    m.w32((0x00a27966u), 0x00000008u);
  }
  { // 0x5b75f3: c7059579a20004000000 MOV dword ptr [0x00a27995],0x4
    m.w32((0x00a27995u), 0x00000004u);
  }
  { // 0x5b75fd: e85ecff6ff CALL 0x00524560
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5b7602: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5b7603: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c2860(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c2860: 833dc855a20004 CMP dword ptr [0x00a255c8],0x4
    (void)integer::sub(m.r32((0x00a255c8u)),0x00000004u,32,flags);
  }
  { // 0x5c2867: 7520 JNZ 0x005c2889
    if(integer::condition("JNZ",flags)) goto L005c2889;
  }
  { // 0x5c2869: e8d2e51600 CALL 0x00730e40
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5c286e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5c2870: 7410 JZ 0x005c2882
    if(integer::condition("JZ",flags)) goto L005c2882;
  }
  { // 0x5c2872: e8f9e51600 CALL 0x00730e70
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5c2877: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5c2879: 7507 JNZ 0x005c2882
    if(integer::condition("JNZ",flags)) goto L005c2882;
  }
  { // 0x5c287b: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  { // 0x5c2880: eb0c JMP 0x005c288e
    goto L005c288e;
  }
  L005c2882: { // 0x5c2882: ba04000000 MOV EDX,0x4
    s.dx = 0x00000004u;
  }
  { // 0x5c2887: eb05 JMP 0x005c288e
    goto L005c288e;
  }
  L005c2889: { // 0x5c2889: ba08000000 MOV EDX,0x8
    s.dx = 0x00000008u;
  }
  L005c288e: { // 0x5c288e: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x5c2890: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c2891: 7e0e JLE 0x005c28a1
    if(integer::condition("JLE",flags)) goto L005c28a1;
  }
  { // 0x5c2893: a19ca8a500 MOV EAX,[0x00a5a89c]
    s.ax = m.r32((0x00a5a89cu));
  }
  { // 0x5c2898: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  { // 0x5c289a: bfc47da200 MOV EDI,0xa27dc4
    s.di = 0x00a27dc4u;
  }
  { // 0x5c289f: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L005c28a1: { // 0x5c28a1: 83fa08 CMP EDX,0x8
    (void)integer::sub(s.dx,0x00000008u,32,flags);
  }
  { // 0x5c28a4: 7d15 JGE 0x005c28bb
    if(integer::condition("JGE",flags)) goto L005c28bb;
  }
  { // 0x5c28a6: a1a0a8a500 MOV EAX,[0x00a5a8a0]
    s.ax = m.r32((0x00a5a8a0u));
  }
  { // 0x5c28ab: b908000000 MOV ECX,0x8
    s.cx = 0x00000008u;
  }
  { // 0x5c28b0: 8d3c95c47da200 LEA EDI,[EDX*0x4 + 0xa27dc4]
    s.di = ((s.dx * 0x00000004u)+0x00a27dc4u);
  }
  { // 0x5c28b7: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x5c28b9: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L005c28bb: { // 0x5c28bb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c28bc: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001ca3e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5ca3e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ca3e1: 8b357486a200 MOV ESI,dword ptr [0x00a28674]
    s.si = m.r32((0x00a28674u));
  }
  { // 0x5ca3e7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5ca3e8: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x5ca3ea: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x5ca3ed: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5ca3ef: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x5ca3f1: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x5ca3f3: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x5ca3f5: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x5ca3f6: 742c JZ 0x005ca424
    if(integer::condition("JZ",flags)) goto L005ca424;
  }
  L005ca3f8: { // 0x5ca3f8: 8a0416 MOV AL,byte ptr [ESI + EDX*0x1]
    s.ax = with_al(s.ax, m.r8((s.si+(s.dx * 0x00000001u))));
  }
  { // 0x5ca3fb: 3c0d CMP AL,0xd
    (void)integer::sub((s.ax & 0xffu),0x0000000du,8,flags);
  }
  { // 0x5ca3fd: 7506 JNZ 0x005ca405
    if(integer::condition("JNZ",flags)) goto L005ca405;
  }
  { // 0x5ca3ff: c6041601 MOV byte ptr [ESI + EDX*0x1],0x1
    m.w8((s.si+(s.dx * 0x00000001u)), 0x00000001u);
  }
  { // 0x5ca403: eb08 JMP 0x005ca40d
    goto L005ca40d;
  }
  L005ca405: { // 0x5ca405: 3c0a CMP AL,0xa
    (void)integer::sub((s.ax & 0xffu),0x0000000au,8,flags);
  }
  { // 0x5ca407: 750a JNZ 0x005ca413
    if(integer::condition("JNZ",flags)) goto L005ca413;
  }
  { // 0x5ca409: c6041602 MOV byte ptr [ESI + EDX*0x1],0x2
    m.w8((s.si+(s.dx * 0x00000001u)), 0x00000002u);
  }
  L005ca40d: { // 0x5ca40d: 8b357486a200 MOV ESI,dword ptr [0x00a28674]
    s.si = m.r32((0x00a28674u));
  }
  L005ca413: { // 0x5ca413: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x5ca415: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x5ca418: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5ca41a: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  { // 0x5ca41b: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x5ca41d: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x5ca41f: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x5ca420: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x5ca422: 72d4 JC 0x005ca3f8
    if(integer::condition("JC",flags)) goto L005ca3f8;
  }
  L005ca424: { // 0x5ca424: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5ca425: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5ca426: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001cb250(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cb250: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cb251: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5cb253: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5cb255: ff5054 CALL dword ptr [EAX + 0x54]
    const std::uint32_t call_target=m.r32((s.ax+0x00000054u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5cb258: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5cb25a: 7507 JNZ 0x005cb263
    if(integer::condition("JNZ",flags)) goto L005cb263;
  }
  { // 0x5cb25c: b802000000 MOV EAX,0x2
    s.ax = 0x00000002u;
  }
  { // 0x5cb261: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cb262: c3 RET
    finish(m,s,f,0u); return;
  }
  L005cb263: { // 0x5cb263: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5cb265: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5cb267: ff92b0010000 CALL dword ptr [EDX + 0x1b0]
    const std::uint32_t call_target=m.r32((s.dx+0x000001b0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5cb26d: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  { // 0x5cb273: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x5cb275: 8bb278030000 MOV ESI,dword ptr [EDX + 0x378]
    s.si = m.r32((s.dx+0x00000378u));
  }
  { // 0x5cb27b: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x5cb27d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cb27e: 0f9dc1 SETGE CL
    s.cx = with_al(s.cx, (integer::condition("JGE",flags)?1u:0u));
  }
  { // 0x5cb281: 83c103 ADD ECX,0x3
    s.cx = integer::add(s.cx,0x00000003u,32,flags);
  }
  { // 0x5cb284: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x5cb286: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001cd140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cd140: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cd141: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5cd143: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x5cd147: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5cd148: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5cd14a: ff90b4000000 CALL dword ptr [EAX + 0xb4]
    const std::uint32_t call_target=m.r32((s.ax+0x000000b4u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5cd150: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5cd152: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5cd154: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5cd156: ff92b4000000 CALL dword ptr [EDX + 0xb4]
    const std::uint32_t call_target=m.r32((s.dx+0x000000b4u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5cd15c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x5cd15e: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x5cd160: 0f9cc1 SETL CL
    s.cx = with_al(s.cx, (integer::condition("JL",flags)?1u:0u));
  }
  { // 0x5cd163: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5cd164: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  { // 0x5cd166: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cd167: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001cd170(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cd170: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cd171: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5cd173: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x5cd177: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5cd178: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5cd17a: ff90b4000000 CALL dword ptr [EAX + 0xb4]
    const std::uint32_t call_target=m.r32((s.ax+0x000000b4u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5cd180: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5cd182: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5cd184: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5cd186: ff92b4000000 CALL dword ptr [EDX + 0xb4]
    const std::uint32_t call_target=m.r32((s.dx+0x000000b4u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5cd18c: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x5cd18e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5cd18f: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  { // 0x5cd192: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cd193: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001f7f90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f7f90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f7f91: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5f7f93: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f7f94: b980000000 MOV ECX,0x80
    s.cx = 0x00000080u;
  }
  { // 0x5f7f99: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5f7f9b: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x5f7f9d: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  { // 0x5f7f9f: c746680b000000 MOV dword ptr [ESI + 0x68],0xb
    m.w32((s.si+0x00000068u), 0x0000000bu);
  }
  { // 0x5f7fa6: a1306d8300 MOV EAX,[0x00836d30]
    s.ax = m.r32((0x00836d30u));
  }
  { // 0x5f7fab: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x5f7fad: 894664 MOV dword ptr [ESI + 0x64],EAX
    m.w32((s.si+0x00000064u), s.ax);
  }
  { // 0x5f7fb0: e8a2591700 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5f7fb5: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5f7fb7: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5f7fba: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x5f7fbc: 7409 JZ 0x005f7fc7
    if(integer::condition("JZ",flags)) goto L005f7fc7;
  }
  { // 0x5f7fbe: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5f7fc0: e82b331600 CALL 0x0075b2f0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5f7fc5: eb02 JMP 0x005f7fc9
    goto L005f7fc9;
  }
  L005f7fc7: { // 0x5f7fc7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005f7fc9: { // 0x5f7fc9: 89463c MOV dword ptr [ESI + 0x3c],EAX
    m.w32((s.si+0x0000003cu), s.ax);
  }
  { // 0x5f7fcc: 897e40 MOV dword ptr [ESI + 0x40],EDI
    m.w32((s.si+0x00000040u), s.di);
  }
  { // 0x5f7fcf: 897e5c MOV dword ptr [ESI + 0x5c],EDI
    m.w32((s.si+0x0000005cu), s.di);
  }
  { // 0x5f7fd2: c78690000000ffffffff MOV dword ptr [ESI + 0x90],0xffffffff
    m.w32((s.si+0x00000090u), 0xffffffffu);
  }
  { // 0x5f7fdc: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5f7fde: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f7fdf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f7fe0: c3 RET
    finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,38>& entries_a() {
  static const std::array<Entry,38> entries{{
    {0x2800u,f_00002800},
    {0x8380u,f_00008380},
    {0x8710u,f_00008710},
    {0x8ca0u,f_00008ca0},
    {0xa180u,f_0000a180},
    {0x26c60u,f_00026c60},
    {0x36e40u,f_00036e40},
    {0x53740u,f_00053740},
    {0x6c550u,f_0006c550},
    {0x70000u,f_00070000},
    {0x8df70u,f_0008df70},
    {0x91f60u,f_00091f60},
    {0x92490u,f_00092490},
    {0x95fd0u,f_00095fd0},
    {0xaa320u,f_000aa320},
    {0xba9c0u,f_000ba9c0},
    {0xbaa20u,f_000baa20},
    {0xbab40u,f_000bab40},
    {0xbaba0u,f_000baba0},
    {0xbac00u,f_000bac00},
    {0xbac70u,f_000bac70},
    {0xdd810u,f_000dd810},
    {0xe07d0u,f_000e07d0},
    {0xe0810u,f_000e0810},
    {0xe0850u,f_000e0850},
    {0x122ae0u,f_00122ae0},
    {0x122b60u,f_00122b60},
    {0x122be0u,f_00122be0},
    {0x122c10u,f_00122c10},
    {0x122c40u,f_00122c40},
    {0x122c70u,f_00122c70},
    {0x1b75c0u,f_001b75c0},
    {0x1c2860u,f_001c2860},
    {0x1ca3e0u,f_001ca3e0},
    {0x1cb250u,f_001cb250},
    {0x1cd140u,f_001cd140},
    {0x1cd170u,f_001cd170},
    {0x1f7f90u,f_001f7f90},
  }}; return entries;
}
} // namespace ra2::recovered::strings_b37
