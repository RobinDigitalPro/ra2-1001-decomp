#include "recovered/mixed_b35_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::mixed_b35 {
namespace {
void f_000f9da0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4f9da0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4f9da1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4f9da2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4f9da6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4f9da8: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x4f9daa: 7459 JZ 0x004f9e05
    if(integer::condition("JZ",flags)) goto L004f9e05;
  }
  { // 0x4f9dac: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4f9dae: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4f9db1: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x4f9db4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4f9db6: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x4f9db9: 743f JZ 0x004f9dfa
    if(integer::condition("JZ",flags)) goto L004f9dfa;
  }
  { // 0x4f9dbb: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  { // 0x4f9dc2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4f9dc3: e88f3b2700 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4f9dc8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4f9dcb: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x4f9dce: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4f9dd0: 7433 JZ 0x004f9e05
    if(integer::condition("JZ",flags)) goto L004f9e05;
  }
  { // 0x4f9dd2: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x4f9dd5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4f9dd7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4f9dd9: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x4f9ddd: 7e26 JLE 0x004f9e05
    if(integer::condition("JLE",flags)) goto L004f9e05;
  }
  L004f9ddf: { // 0x4f9ddf: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x4f9de2: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x4f9de5: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x4f9de8: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  { // 0x4f9deb: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x4f9dee: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x4f9def: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4f9df1: 7cec JL 0x004f9ddf
    if(integer::condition("JL",flags)) goto L004f9ddf;
  }
  { // 0x4f9df3: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4f9df5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f9df6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f9df7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004f9dfa: { // 0x4f9dfa: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x4f9e01: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L004f9e05: { // 0x4f9e05: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4f9e07: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f9e08: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f9e09: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000fa170(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4fa170: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4fa171: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4fa172: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4fa176: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4fa178: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x4fa17a: 7459 JZ 0x004fa1d5
    if(integer::condition("JZ",flags)) goto L004fa1d5;
  }
  { // 0x4fa17c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4fa17e: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4fa181: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x4fa184: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4fa186: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x4fa189: 743f JZ 0x004fa1ca
    if(integer::condition("JZ",flags)) goto L004fa1ca;
  }
  { // 0x4fa18b: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  { // 0x4fa192: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4fa193: e8bf372700 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4fa198: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4fa19b: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x4fa19e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4fa1a0: 7433 JZ 0x004fa1d5
    if(integer::condition("JZ",flags)) goto L004fa1d5;
  }
  { // 0x4fa1a2: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x4fa1a5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4fa1a7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4fa1a9: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x4fa1ad: 7e26 JLE 0x004fa1d5
    if(integer::condition("JLE",flags)) goto L004fa1d5;
  }
  L004fa1af: { // 0x4fa1af: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x4fa1b2: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x4fa1b5: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x4fa1b8: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  { // 0x4fa1bb: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x4fa1be: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x4fa1bf: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4fa1c1: 7cec JL 0x004fa1af
    if(integer::condition("JL",flags)) goto L004fa1af;
  }
  { // 0x4fa1c3: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4fa1c5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4fa1c6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4fa1c7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004fa1ca: { // 0x4fa1ca: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x4fa1d1: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L004fa1d5: { // 0x4fa1d5: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4fa1d7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4fa1d8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4fa1d9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000fa540(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4fa540: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4fa541: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4fa542: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4fa546: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4fa548: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x4fa54a: 7459 JZ 0x004fa5a5
    if(integer::condition("JZ",flags)) goto L004fa5a5;
  }
  { // 0x4fa54c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4fa54e: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4fa551: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x4fa554: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4fa556: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x4fa559: 743f JZ 0x004fa59a
    if(integer::condition("JZ",flags)) goto L004fa59a;
  }
  { // 0x4fa55b: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  { // 0x4fa562: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4fa563: e8ef332700 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4fa568: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4fa56b: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x4fa56e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4fa570: 7433 JZ 0x004fa5a5
    if(integer::condition("JZ",flags)) goto L004fa5a5;
  }
  { // 0x4fa572: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x4fa575: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4fa577: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4fa579: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x4fa57d: 7e26 JLE 0x004fa5a5
    if(integer::condition("JLE",flags)) goto L004fa5a5;
  }
  L004fa57f: { // 0x4fa57f: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x4fa582: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x4fa585: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x4fa588: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  { // 0x4fa58b: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x4fa58e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x4fa58f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4fa591: 7cec JL 0x004fa57f
    if(integer::condition("JL",flags)) goto L004fa57f;
  }
  { // 0x4fa593: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4fa595: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4fa596: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4fa597: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004fa59a: { // 0x4fa59a: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x4fa5a1: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L004fa5a5: { // 0x4fa5a5: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4fa5a7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4fa5a8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4fa5a9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000fcf80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4fcf80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4fcf81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4fcf83: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4fcf85: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4fcf86: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x4fcf89: 894650 MOV dword ptr [ESI + 0x50],EAX
    m.w32((s.si+0x00000050u), s.ax);
  }
  { // 0x4fcf8c: 894648 MOV dword ptr [ESI + 0x48],EAX
    m.w32((s.si+0x00000048u), s.ax);
  }
  { // 0x4fcf8f: 894654 MOV dword ptr [ESI + 0x54],EAX
    m.w32((s.si+0x00000054u), s.ax);
  }
  { // 0x4fcf92: 89464c MOV dword ptr [ESI + 0x4c],EAX
    m.w32((s.si+0x0000004cu), s.ax);
  }
  { // 0x4fcf95: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x4fcf97: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4fcf98: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4fcf99: ff92c8040000 CALL dword ptr [EDX + 0x4c8]
    const std::uint32_t call_target=m.r32((s.dx+0x000004c8u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4fcf9f: 8b4624 MOV EAX,dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  { // 0x4fcfa2: 8b0dc08ca200 MOV ECX,dword ptr [0x00a28cc0]
    s.cx = m.r32((0x00a28cc0u));
  }
  { // 0x4fcfa8: 8d7e24 LEA EDI,[ESI + 0x24]
    s.di = (s.si+0x00000024u);
  }
  { // 0x4fcfab: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4fcfad: 7518 JNZ 0x004fcfc7
    if(integer::condition("JNZ",flags)) goto L004fcfc7;
  }
  { // 0x4fcfaf: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  { // 0x4fcfb2: a1c48ca200 MOV EAX,[0x00a28cc4]
    s.ax = m.r32((0x00a28cc4u));
  }
  { // 0x4fcfb7: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x4fcfb9: 750c JNZ 0x004fcfc7
    if(integer::condition("JNZ",flags)) goto L004fcfc7;
  }
  { // 0x4fcfbb: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  { // 0x4fcfbe: a1c88ca200 MOV EAX,[0x00a28cc8]
    s.ax = m.r32((0x00a28cc8u));
  }
  { // 0x4fcfc3: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x4fcfc5: 7425 JZ 0x004fcfec
    if(integer::condition("JZ",flags)) goto L004fcfec;
  }
  L004fcfc7: { // 0x4fcfc7: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x4fcfca: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4fcfcb: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x4fcfcd: ff90ec000000 CALL dword ptr [EAX + 0xec]
    const std::uint32_t call_target=m.r32((s.ax+0x000000ecu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4fcfd3: 8b0dc08ca200 MOV ECX,dword ptr [0x00a28cc0]
    s.cx = m.r32((0x00a28cc0u));
  }
  { // 0x4fcfd9: 890f MOV dword ptr [EDI],ECX
    m.w32((s.di), s.cx);
  }
  { // 0x4fcfdb: 8b15c48ca200 MOV EDX,dword ptr [0x00a28cc4]
    s.dx = m.r32((0x00a28cc4u));
  }
  { // 0x4fcfe1: 895704 MOV dword ptr [EDI + 0x4],EDX
    m.w32((s.di+0x00000004u), s.dx);
  }
  { // 0x4fcfe4: a1c88ca200 MOV EAX,[0x00a28cc8]
    s.ax = m.r32((0x00a28cc8u));
  }
  { // 0x4fcfe9: 894708 MOV dword ptr [EDI + 0x8],EAX
    m.w32((s.di+0x00000008u), s.ax);
  }
  L004fcfec: { // 0x4fcfec: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4fcfed: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4fcfee: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000fdd00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4fdd00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4fdd01: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x4fdd05: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4fdd06: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4fdd08: ff5060 CALL dword ptr [EAX + 0x60]
    const std::uint32_t call_target=m.r32((s.ax+0x00000060u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4fdd0b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4fdd0d: 744f JZ 0x004fdd5e
    if(integer::condition("JZ",flags)) goto L004fdd5e;
  }
  { // 0x4fdd0f: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x4fdd12: 8b8198000000 MOV EAX,dword ptr [ECX + 0x98]
    s.ax = m.r32((s.cx+0x00000098u));
  }
  { // 0x4fdd18: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4fdd1a: 7442 JZ 0x004fdd5e
    if(integer::condition("JZ",flags)) goto L004fdd5e;
  }
  { // 0x4fdd1c: 83f807 CMP EAX,0x7
    (void)integer::sub(s.ax,0x00000007u,32,flags);
  }
  { // 0x4fdd1f: 743d JZ 0x004fdd5e
    if(integer::condition("JZ",flags)) goto L004fdd5e;
  }
  { // 0x4fdd21: c6466401 MOV byte ptr [ESI + 0x64],0x1
    m.w8((s.si+0x00000064u), 0x00000001u);
  }
  { // 0x4fdd25: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  { // 0x4fdd2b: 6a1e PUSH 0x1e
    f.push(m,0x0000001eu);
  }
  { // 0x4fdd2d: 6a14 PUSH 0x14
    f.push(m,0x00000014u);
  }
  { // 0x4fdd2f: 8d8a18020000 LEA ECX,[EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  { // 0x4fdd35: e806211300 CALL 0x0062fe40
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4fdd3a: 894668 MOV dword ptr [ESI + 0x68],EAX
    m.w32((s.si+0x00000068u), s.ax);
  }
  { // 0x4fdd3d: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x4fdd42: 6a63 PUSH 0x63
    f.push(m,0x00000063u);
  }
  { // 0x4fdd44: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4fdd46: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  { // 0x4fdd4c: e8ef201300 CALL 0x0062fe40
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4fdd51: 83f832 CMP EAX,0x32
    (void)integer::sub(s.ax,0x00000032u,32,flags);
  }
  { // 0x4fdd54: 7d08 JGE 0x004fdd5e
    if(integer::condition("JGE",flags)) goto L004fdd5e;
  }
  { // 0x4fdd56: 8b4e68 MOV ECX,dword ptr [ESI + 0x68]
    s.cx = m.r32((s.si+0x00000068u));
  }
  { // 0x4fdd59: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  { // 0x4fdd5b: 894e68 MOV dword ptr [ESI + 0x68],ECX
    m.w32((s.si+0x00000068u), s.cx);
  }
  L004fdd5e: { // 0x4fdd5e: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4fdd60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4fdd61: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4fdd64: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4fdd66: 7406 JZ 0x004fdd6e
    if(integer::condition("JZ",flags)) goto L004fdd6e;
  }
  { // 0x4fdd68: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4fdd6a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4fdd6b: ff5048 CALL dword ptr [EAX + 0x48]
    const std::uint32_t call_target=m.r32((s.ax+0x00000048u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L004fdd6e: { // 0x4fdd6e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4fdd6f: e87cd60300 CALL 0x0053b3f0
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x4fdd74: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4fdd75: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000fdd80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4fdd80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4fdd81: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x4fdd85: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4fdd86: e885d60300 CALL 0x0053b410
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4fdd8b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4fdd8d: 7515 JNZ 0x004fdda4
    if(integer::condition("JNZ",flags)) goto L004fdda4;
  }
  { // 0x4fdd8f: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x4fdd92: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x4fdd94: ff90b0010000 CALL dword ptr [EAX + 0x1b0]
    const std::uint32_t call_target=m.r32((s.ax+0x000001b0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4fdd9a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4fdd9c: 7f06 JG 0x004fdda4
    if(integer::condition("JG",flags)) goto L004fdda4;
  }
  { // 0x4fdd9e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4fdda0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4fdda1: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004fdda4: { // 0x4fdda4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4fdda6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4fdda7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00104390(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x504390: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x504391: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x504393: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x504399: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x50439b: 750a JNZ 0x005043a7
    if(integer::condition("JNZ",flags)) goto L005043a7;
  }
  { // 0x50439d: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x5043a2: e8c9ce2700 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L005043a7: { // 0x5043a7: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x5043ad: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5043ae: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x5043b0: ff91ac000000 CALL dword ptr [ECX + 0xac]
    const std::uint32_t call_target=m.r32((s.cx+0x000000acu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5043b6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5043b8: c786d005000002000000 MOV dword ptr [ESI + 0x5d0],0x2
    m.w32((s.si+0x000005d0u), 0x00000002u);
  }
  { // 0x5043c2: c686c305000000 MOV byte ptr [ESI + 0x5c3],0x0
    m.w8((s.si+0x000005c3u), 0x00000000u);
  }
  { // 0x5043c9: c786ac05000000000000 MOV dword ptr [ESI + 0x5ac],0x0
    m.w32((s.si+0x000005acu), 0x00000000u);
  }
  { // 0x5043d3: e8f853fcff CALL 0x004c97d0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5043d8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5043d9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00105550(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x505550: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x505551: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  { // 0x505555: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x505556: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x505558: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x505559: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x50555d: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  { // 0x505563: 83f81b CMP EAX,0x1b
    (void)integer::sub(s.ax,0x0000001bu,32,flags);
  }
  { // 0x505566: 740f JZ 0x00505577
    if(integer::condition("JZ",flags)) goto L00505577;
  }
  { // 0x505568: 83f81c CMP EAX,0x1c
    (void)integer::sub(s.ax,0x0000001cu,32,flags);
  }
  { // 0x50556b: 740a JZ 0x00505577
    if(integer::condition("JZ",flags)) goto L00505577;
  }
  { // 0x50556d: 83f81d CMP EAX,0x1d
    (void)integer::sub(s.ax,0x0000001du,32,flags);
  }
  { // 0x505570: 7405 JZ 0x00505577
    if(integer::condition("JZ",flags)) goto L00505577;
  }
  { // 0x505572: 83f81e CMP EAX,0x1e
    (void)integer::sub(s.ax,0x0000001eu,32,flags);
  }
  { // 0x505575: 7518 JNZ 0x0050558f
    if(integer::condition("JNZ",flags)) goto L0050558f;
  }
  L00505577: { // 0x505577: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x505579: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x50557a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x50557c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x50557d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x50557f: ff506c CALL dword ptr [EAX + 0x6c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000006cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x505582: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x505585: 7508 JNZ 0x0050558f
    if(integer::condition("JNZ",flags)) goto L0050558f;
  }
  { // 0x505587: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x505588: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x505589: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x50558b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x50558c: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L0050558f: { // 0x50558f: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x505593: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x505597: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x505598: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x505599: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x50559a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x50559b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x50559d: e82e10fcff CALL 0x004c65d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5055a2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5055a3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5055a4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5055a5: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_001055b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5055b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5055b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5055b3: 8a86c1050000 MOV AL,byte ptr [ESI + 0x5c1]
    s.ax = with_al(s.ax, m.r8((s.si+0x000005c1u)));
  }
  { // 0x5055b9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5055bb: 7418 JZ 0x005055d5
    if(integer::condition("JZ",flags)) goto L005055d5;
  }
  { // 0x5055bd: 6868100000 PUSH 0x1068
    f.push(m,0x00001068u);
  }
  { // 0x5055c2: 68a05f7c00 PUSH 0x7c5fa0
    f.push(m,0x007c5fa0u);
  }
  { // 0x5055c7: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x5055c9: b9905f7c00 MOV ECX,0x7c5f90
    s.cx = 0x007c5f90u;
  }
  { // 0x5055ce: e88d951e00 CALL 0x006eeb60
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5055d3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5055d4: c3 RET
    finish(m,s,f,0u); return;
  }
  L005055d5: { // 0x5055d5: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5055d7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5055d9: ff90c0000000 CALL dword ptr [EAX + 0xc0]
    const std::uint32_t call_target=m.r32((s.ax+0x000000c0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5055df: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5055e1: 7427 JZ 0x0050560a
    if(integer::condition("JZ",flags)) goto L0050560a;
  }
  { // 0x5055e3: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  { // 0x5055e9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5055ea: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x5055f0: e8ebf5fdff CALL 0x004e4be0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5055f5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5055f7: 7511 JNZ 0x0050560a
    if(integer::condition("JNZ",flags)) goto L0050560a;
  }
  { // 0x5055f9: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5055fb: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5055fd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5055ff: ff92c8000000 CALL dword ptr [EDX + 0xc8]
    const std::uint32_t call_target=m.r32((s.dx+0x000000c8u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x505605: 8b4060 MOV EAX,dword ptr [EAX + 0x60]
    s.ax = m.r32((s.ax+0x00000060u));
  }
  { // 0x505608: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x505609: c3 RET
    finish(m,s,f,0u); return;
  }
  L0050560a: { // 0x50560a: 8b86a8050000 MOV EAX,dword ptr [ESI + 0x5a8]
    s.ax = m.r32((s.si+0x000005a8u));
  }
  { // 0x505610: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x505611: 8b4060 MOV EAX,dword ptr [EAX + 0x60]
    s.ax = m.r32((s.ax+0x00000060u));
  }
  { // 0x505614: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00105900(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x505900: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x505901: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x505903: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  { // 0x505909: 83f81b CMP EAX,0x1b
    (void)integer::sub(s.ax,0x0000001bu,32,flags);
  }
  { // 0x50590c: 740f JZ 0x0050591d
    if(integer::condition("JZ",flags)) goto L0050591d;
  }
  { // 0x50590e: 83f81c CMP EAX,0x1c
    (void)integer::sub(s.ax,0x0000001cu,32,flags);
  }
  { // 0x505911: 740a JZ 0x0050591d
    if(integer::condition("JZ",flags)) goto L0050591d;
  }
  { // 0x505913: 83f81d CMP EAX,0x1d
    (void)integer::sub(s.ax,0x0000001du,32,flags);
  }
  { // 0x505916: 7405 JZ 0x0050591d
    if(integer::condition("JZ",flags)) goto L0050591d;
  }
  { // 0x505918: 83f81e CMP EAX,0x1e
    (void)integer::sub(s.ax,0x0000001eu,32,flags);
  }
  { // 0x50591b: 755a JNZ 0x00505977
    if(integer::condition("JNZ",flags)) goto L00505977;
  }
  L0050591d: { // 0x50591d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x50591f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x505921: ff503c CALL dword ptr [EAX + 0x3c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000003cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x505924: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x505926: e8c5eefeff CALL 0x004f47f0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x50592b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x50592d: 7415 JZ 0x00505944
    if(integer::condition("JZ",flags)) goto L00505944;
  }
  { // 0x50592f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x505931: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x505933: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x505935: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x505937: ff9210040000 CALL dword ptr [EDX + 0x410]
    const std::uint32_t call_target=m.r32((s.dx+0x00000410u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x50593d: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x505942: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x505943: c3 RET
    finish(m,s,f,0u); return;
  }
  L00505944: { // 0x505944: 8b86a8050000 MOV EAX,dword ptr [ESI + 0x5a8]
    s.ax = m.r32((s.si+0x000005a8u));
  }
  { // 0x50594a: 83b8e0050000ff CMP dword ptr [EAX + 0x5e0],-0x1
    (void)integer::sub(m.r32((s.ax+0x000005e0u)),0xffffffffu,32,flags);
  }
  { // 0x505951: 7f24 JG 0x00505977
    if(integer::condition("JG",flags)) goto L00505977;
  }
  { // 0x505953: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x505955: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x505957: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x505959: 6a1f PUSH 0x1f
    f.push(m,0x0000001fu);
  }
  { // 0x50595b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x50595d: ff92dc040000 CALL dword ptr [EDX + 0x4dc]
    const std::uint32_t call_target=m.r32((s.dx+0x000004dcu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x505963: 8b86a8050000 MOV EAX,dword ptr [ESI + 0x5a8]
    s.ax = m.r32((s.si+0x000005a8u));
  }
  { // 0x505969: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x50596a: 8b88980b0000 MOV ECX,dword ptr [EAX + 0xb98]
    s.cx = m.r32((s.ax+0x00000b98u));
  }
  { // 0x505970: 8b81f4010000 MOV EAX,dword ptr [ECX + 0x1f4]
    s.ax = m.r32((s.cx+0x000001f4u));
  }
  { // 0x505976: c3 RET
    finish(m,s,f,0u); return;
  }
  L00505977: { // 0x505977: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x505979: e8c2dbfbff CALL 0x004c3540
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x50597e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x50597f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00108700(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x508700: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x508701: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x508705: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x508706: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x508708: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x50870a: 7466 JZ 0x00508772
    if(integer::condition("JZ",flags)) goto L00508772;
  }
  { // 0x50870c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x50870e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x508710: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x508713: 83f80f CMP EAX,0xf
    (void)integer::sub(s.ax,0x0000000fu,32,flags);
  }
  { // 0x508716: 755a JNZ 0x00508772
    if(integer::condition("JNZ",flags)) goto L00508772;
  }
  { // 0x508718: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x508719: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x50871b: e8d0541c00 CALL 0x006cdbf0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x508720: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x508722: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x508724: ff92c0000000 CALL dword ptr [EDX + 0xc0]
    const std::uint32_t call_target=m.r32((s.dx+0x000000c0u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x50872a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x50872c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x50872e: 7427 JZ 0x00508757
    if(integer::condition("JZ",flags)) goto L00508757;
  }
  { // 0x508730: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x508732: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x508734: ff90c8000000 CALL dword ptr [EAX + 0xc8]
    const std::uint32_t call_target=m.r32((s.ax+0x000000c8u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x50873a: 89870c040000 MOV dword ptr [EDI + 0x40c],EAX
    m.w32((s.di+0x0000040cu), s.ax);
  }
  { // 0x508740: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x508742: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x508744: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x508746: ff92cc000000 CALL dword ptr [EDX + 0xcc]
    const std::uint32_t call_target=m.r32((s.dx+0x000000ccu));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x50874c: 898710040000 MOV dword ptr [EDI + 0x410],EAX
    m.w32((s.di+0x00000410u), s.ax);
  }
  { // 0x508752: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x508753: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x508754: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00508757: { // 0x508757: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x508759: ff9084000000 CALL dword ptr [EAX + 0x84]
    const std::uint32_t call_target=m.r32((s.ax+0x00000084u));
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x50875f: 89870c040000 MOV dword ptr [EDI + 0x40c],EAX
    m.w32((s.di+0x0000040cu), s.ax);
  }
  { // 0x508765: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x508767: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x508769: ff523c CALL dword ptr [EDX + 0x3c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000003cu));
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  { // 0x50876c: 898710040000 MOV dword ptr [EDI + 0x410],EAX
    m.w32((s.di+0x00000410u), s.ax);
  }
  L00508772: { // 0x508772: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x508773: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x508774: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00108ac0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x508ac0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x508ac1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x508ac3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x508ac5: ff906c010000 CALL dword ptr [EAX + 0x16c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000016cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x508acb: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  { // 0x508ace: 740f JZ 0x00508adf
    if(integer::condition("JZ",flags)) goto L00508adf;
  }
  { // 0x508ad0: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x508ad2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x508ad4: ff926c010000 CALL dword ptr [EDX + 0x16c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000016cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x508ada: 83f80b CMP EAX,0xb
    (void)integer::sub(s.ax,0x0000000bu,32,flags);
  }
  { // 0x508add: 7519 JNZ 0x00508af8
    if(integer::condition("JNZ",flags)) goto L00508af8;
  }
  L00508adf: { // 0x508adf: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  { // 0x508ae5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x508ae7: 7413 JZ 0x00508afc
    if(integer::condition("JZ",flags)) goto L00508afc;
  }
  { // 0x508ae9: 83f809 CMP EAX,0x9
    (void)integer::sub(s.ax,0x00000009u,32,flags);
  }
  { // 0x508aec: 740e JZ 0x00508afc
    if(integer::condition("JZ",flags)) goto L00508afc;
  }
  { // 0x508aee: 83f80a CMP EAX,0xa
    (void)integer::sub(s.ax,0x0000000au,32,flags);
  }
  { // 0x508af1: 7409 JZ 0x00508afc
    if(integer::condition("JZ",flags)) goto L00508afc;
  }
  { // 0x508af3: 83f820 CMP EAX,0x20
    (void)integer::sub(s.ax,0x00000020u,32,flags);
  }
  { // 0x508af6: 7404 JZ 0x00508afc
    if(integer::condition("JZ",flags)) goto L00508afc;
  }
  L00508af8: { // 0x508af8: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x508afa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x508afb: c3 RET
    finish(m,s,f,0u); return;
  }
  L00508afc: { // 0x508afc: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x508afe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x508aff: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00108b00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x508b00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x508b01: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x508b03: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x508b05: ff9030030000 CALL dword ptr [EAX + 0x330]
    const std::uint32_t call_target=m.r32((s.ax+0x00000330u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x508b0b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x508b0d: 7410 JZ 0x00508b1f
    if(integer::condition("JZ",flags)) goto L00508b1f;
  }
  { // 0x508b0f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x508b11: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x508b13: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x508b15: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x508b17: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x508b19: ff92dc040000 CALL dword ptr [EDX + 0x4dc]
    const std::uint32_t call_target=m.r32((s.dx+0x000004dcu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00508b1f: { // 0x508b1f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x508b20: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00108c80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x508c80: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x508c84: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x508c85: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x508c87: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x508c88: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x508c8a: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x508c8c: 7416 JZ 0x00508ca4
    if(integer::condition("JZ",flags)) goto L00508ca4;
  }
  { // 0x508c8e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x508c90: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x508c92: 7406 JZ 0x00508c9a
    if(integer::condition("JZ",flags)) goto L00508c9a;
  }
  { // 0x508c94: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x508c96: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x508c97: ff5104 CALL dword ptr [ECX + 0x4]
    const std::uint32_t call_target=m.r32((s.cx+0x00000004u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00508c9a: { // 0x508c9a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x508c9c: 7406 JZ 0x00508ca4
    if(integer::condition("JZ",flags)) goto L00508ca4;
  }
  { // 0x508c9e: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  { // 0x508ca0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x508ca1: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00508ca4: { // 0x508ca4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x508ca6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x508ca7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x508ca8: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00108cc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x508cc0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x508cc4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x508cc5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x508cc6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x508cc8: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x508cce: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x508cd0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x508cd2: 744f JZ 0x00508d23
    if(integer::condition("JZ",flags)) goto L00508d23;
  }
  { // 0x508cd4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x508cd6: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x508cda: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x508cdb: 6898a17b00 PUSH 0x7ba198
    f.push(m,0x007ba198u);
  }
  { // 0x508ce0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x508ce1: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x508ce3: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x508ce5: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x508ce7: 7d14 JGE 0x00508cfd
    if(integer::condition("JGE",flags)) goto L00508cfd;
  }
  { // 0x508ce9: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x508ceb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x508ced: 7406 JZ 0x00508cf5
    if(integer::condition("JZ",flags)) goto L00508cf5;
  }
  { // 0x508cef: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x508cf1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x508cf2: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00508cf5: { // 0x508cf5: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x508cfb: eb14 JMP 0x00508d11
    goto L00508d11;
  }
  L00508cfd: { // 0x508cfd: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x508cff: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x508d00: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x508d04: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x508d06: 7406 JZ 0x00508d0e
    if(integer::condition("JZ",flags)) goto L00508d0e;
  }
  { // 0x508d08: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x508d0a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x508d0b: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00508d0e: { // 0x508d0e: 893e MOV dword ptr [ESI],EDI
    m.w32((s.si), s.di);
  }
  { // 0x508d10: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00508d11: { // 0x508d11: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x508d13: 7d0e JGE 0x00508d23
    if(integer::condition("JGE",flags)) goto L00508d23;
  }
  { // 0x508d15: 81fb02400080 CMP EBX,0x80004002
    (void)integer::sub(s.bx,0x80004002u,32,flags);
  }
  { // 0x508d1b: 7406 JZ 0x00508d23
    if(integer::condition("JZ",flags)) goto L00508d23;
  }
  { // 0x508d1d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x508d1e: e84d852700 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00508d23: { // 0x508d23: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x508d25: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x508d26: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x508d27: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00115020(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x515020: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x515021: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x515022: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x515024: 8ada MOV BL,DL
    s.bx = with_al(s.bx, (s.dx & 0xffu));
  }
  { // 0x515026: 8b0d941c8200 MOV ECX,dword ptr [0x00821c94]
    s.cx = m.r32((0x00821c94u));
  }
  { // 0x51502c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x51502e: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x515030: ff5018 CALL dword ptr [EAX + 0x18]
    const std::uint32_t call_target=m.r32((s.ax+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x515033: 8b15941c8200 MOV EDX,dword ptr [0x00821c94]
    s.dx = m.r32((0x00821c94u));
  }
  { // 0x515039: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x51503b: 68500a8200 PUSH 0x820a50
    f.push(m,0x00820a50u);
  }
  { // 0x515040: e80b7d2100 CALL 0x0072cd50
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x515045: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x515047: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x515048: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x515049: 740f JZ 0x0051505a
    if(integer::condition("JZ",flags)) goto L0051505a;
  }
  { // 0x51504b: 8b15941c8200 MOV EDX,dword ptr [0x00821c94]
    s.dx = m.r32((0x00821c94u));
  }
  { // 0x515051: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x515053: b101 MOV CL,0x1
    s.cx = with_al(s.cx, 0x00000001u);
  }
  { // 0x515055: e8c6b2fcff CALL 0x004e0320
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L0051505a: { // 0x51505a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001197e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5197e0: a130f88100 MOV EAX,[0x0081f830]
    s.ax = m.r32((0x0081f830u));
  }
  { // 0x5197e5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5197e7: 742b JZ 0x00519814
    if(integer::condition("JZ",flags)) goto L00519814;
  }
  { // 0x5197e9: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  { // 0x5197ec: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5197ed: 68a0d17b00 PUSH 0x7bd1a0
    f.push(m,0x007bd1a0u);
  }
  { // 0x5197f2: e8f9d0eeff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5197f7: 8b0d30f88100 MOV ECX,dword ptr [0x0081f830]
    s.cx = m.r32((0x0081f830u));
  }
  { // 0x5197fd: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x519800: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x519802: 7406 JZ 0x0051980a
    if(integer::condition("JZ",flags)) goto L0051980a;
  }
  { // 0x519804: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x519806: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x519808: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0051980a: { // 0x51980a: c70530f8810000000000 MOV dword ptr [0x0081f830],0x0
    m.w32((0x0081f830u), 0x00000000u);
  }
  L00519814: { // 0x519814: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x519816: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00119820(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x519820: a130f88100 MOV EAX,[0x0081f830]
    s.ax = m.r32((0x0081f830u));
  }
  { // 0x519825: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x519827: 742b JZ 0x00519854
    if(integer::condition("JZ",flags)) goto L00519854;
  }
  { // 0x519829: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  { // 0x51982c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x51982d: 68a0d17b00 PUSH 0x7bd1a0
    f.push(m,0x007bd1a0u);
  }
  { // 0x519832: e8b9d0eeff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x519837: 8b0d30f88100 MOV ECX,dword ptr [0x0081f830]
    s.cx = m.r32((0x0081f830u));
  }
  { // 0x51983d: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x519840: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x519842: 7406 JZ 0x0051984a
    if(integer::condition("JZ",flags)) goto L0051984a;
  }
  { // 0x519844: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x519846: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x519848: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0051984a: { // 0x51984a: c70530f8810000000000 MOV dword ptr [0x0081f830],0x0
    m.w32((0x0081f830u), 0x00000000u);
  }
  L00519854: { // 0x519854: 6a28 PUSH 0x28
    f.push(m,0x00000028u);
  }
  { // 0x519856: e8fc402500 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x51985b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x51985e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x519860: 741d JZ 0x0051987f
    if(integer::condition("JZ",flags)) goto L0051987f;
  }
  { // 0x519862: 6850138200 PUSH 0x821350
    f.push(m,0x00821350u);
  }
  { // 0x519867: 68c8897c00 PUSH 0x7c89c8
    f.push(m,0x007c89c8u);
  }
  { // 0x51986c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x51986e: e87d880700 CALL 0x005920f0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x519873: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x519875: a330f88100 MOV [0x0081f830],EAX
    m.w32((0x0081f830u), s.ax);
  }
  { // 0x51987a: 7510 JNZ 0x0051988c
    if(integer::condition("JNZ",flags)) goto L0051988c;
  }
  { // 0x51987c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x51987e: c3 RET
    finish(m,s,f,0u); return;
  }
  L0051987f: { // 0x51987f: c70530f8810000000000 MOV dword ptr [0x0081f830],0x0
    m.w32((0x0081f830u), 0x00000000u);
  }
  { // 0x519889: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x51988b: c3 RET
    finish(m,s,f,0u); return;
  }
  L0051988c: { // 0x51988c: 68b4897c00 PUSH 0x7c89b4
    f.push(m,0x007c89b4u);
  }
  { // 0x519891: e8aac9f7ff CALL 0x00496240
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x519896: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x519899: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x51989b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00122190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x522190: a1f09ea300 MOV EAX,[0x00a39ef0]
    s.ax = m.r32((0x00a39ef0u));
  }
  { // 0x522195: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x522196: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x522198: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x52219a: 744f JZ 0x005221eb
    if(integer::condition("JZ",flags)) goto L005221eb;
  }
  { // 0x52219c: a1109fa300 MOV EAX,[0x00a39f10]
    s.ax = m.r32((0x00a39f10u));
  }
  { // 0x5221a1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5221a3: 7546 JNZ 0x005221eb
    if(integer::condition("JNZ",flags)) goto L005221eb;
  }
  { // 0x5221a5: 68c09ea300 PUSH 0xa39ec0
    f.push(m,0x00a39ec0u);
  }
  { // 0x5221aa: ff15dc517800 CALL dword ptr [0x007851dc]
    const std::uint32_t call_target=m.r32((0x007851dcu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5221b0: 68288d7c00 PUSH 0x7c8d28
    f.push(m,0x007c8d28u);
  }
  { // 0x5221b5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5221b6: e8cad12400 CALL 0x0076f385
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5221bb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5221be: a3109fa300 MOV [0x00a39f10],EAX
    m.w32((0x00a39f10u), s.ax);
  }
  { // 0x5221c3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5221c5: 740a JZ 0x005221d1
    if(integer::condition("JZ",flags)) goto L005221d1;
  }
  { // 0x5221c7: c705ec9ea30001000000 MOV dword ptr [0x00a39eec],0x1
    m.w32((0x00a39eecu), 0x00000001u);
  }
  L005221d1: { // 0x5221d1: 68c09ea300 PUSH 0xa39ec0
    f.push(m,0x00a39ec0u);
  }
  { // 0x5221d6: ff15e0517800 CALL dword ptr [0x007851e0]
    const std::uint32_t call_target=m.r32((0x007851e0u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5221dc: 8b0d109fa300 MOV ECX,dword ptr [0x00a39f10]
    s.cx = m.r32((0x00a39f10u));
  }
  { // 0x5221e2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5221e4: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5221e6: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x5221e9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5221ea: c3 RET
    finish(m,s,f,0u); return;
  }
  L005221eb: { // 0x5221eb: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5221ed: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5221ee: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00122350(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x522350: a1f09ea300 MOV EAX,[0x00a39ef0]
    s.ax = m.r32((0x00a39ef0u));
  }
  { // 0x522355: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x522357: 7462 JZ 0x005223bb
    if(integer::condition("JZ",flags)) goto L005223bb;
  }
  { // 0x522359: 68c09ea300 PUSH 0xa39ec0
    f.push(m,0x00a39ec0u);
  }
  { // 0x52235e: ff15dc517800 CALL dword ptr [0x007851dc]
    const std::uint32_t call_target=m.r32((0x007851dcu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x522364: a1109fa300 MOV EAX,[0x00a39f10]
    s.ax = m.r32((0x00a39f10u));
  }
  { // 0x522369: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x52236b: 7443 JZ 0x005223b0
    if(integer::condition("JZ",flags)) goto L005223b0;
  }
  { // 0x52236d: a1049fa300 MOV EAX,[0x00a39f04]
    s.ax = m.r32((0x00a39f04u));
  }
  { // 0x522372: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x522374: 743a JZ 0x005223b0
    if(integer::condition("JZ",flags)) goto L005223b0;
  }
  { // 0x522376: 833dec9ea30001 CMP dword ptr [0x00a39eec],0x1
    (void)integer::sub(m.r32((0x00a39eecu)),0x00000001u,32,flags);
  }
  { // 0x52237d: 7531 JNZ 0x005223b0
    if(integer::condition("JNZ",flags)) goto L005223b0;
  }
  { // 0x52237f: 8b0d0c9fa300 MOV ECX,dword ptr [0x00a39f0c]
    s.cx = m.r32((0x00a39f0cu));
  }
  { // 0x522385: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x522387: 7427 JZ 0x005223b0
    if(integer::condition("JZ",flags)) goto L005223b0;
  }
  { // 0x522389: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x52238b: e8b06eeeff CALL 0x00409240
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x522390: 8b15109fa300 MOV EDX,dword ptr [0x00a39f10]
    s.dx = m.r32((0x00a39f10u));
  }
  { // 0x522396: 8b0d0c9fa300 MOV ECX,dword ptr [0x00a39f0c]
    s.cx = m.r32((0x00a39f0cu));
  }
  { // 0x52239c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x52239d: e8ae6beeff CALL 0x00408f50
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5223a2: a1109fa300 MOV EAX,[0x00a39f10]
    s.ax = m.r32((0x00a39f10u));
  }
  { // 0x5223a7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5223a8: e82fd92400 CALL 0x0076fcdc
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5223ad: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005223b0: { // 0x5223b0: 68c09ea300 PUSH 0xa39ec0
    f.push(m,0x00a39ec0u);
  }
  { // 0x5223b5: ff15e0517800 CALL dword ptr [0x007851e0]
    const std::uint32_t call_target=m.r32((0x007851e0u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L005223bb: { // 0x5223bb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00123040(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x523040: 8b0d901f8200 MOV ECX,dword ptr [0x00821f90]
    s.cx = m.r32((0x00821f90u));
  }
  { // 0x523046: 8b15a087a200 MOV EDX,dword ptr [0x00a287a0]
    s.dx = m.r32((0x00a287a0u));
  }
  { // 0x52304c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x52304d: 8b3510a0a300 MOV ESI,dword ptr [0x00a3a010]
    s.si = m.r32((0x00a3a010u));
  }
  { // 0x523053: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x523055: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x523056: ff5050 CALL dword ptr [EAX + 0x50]
    const std::uint32_t call_target=m.r32((s.ax+0x00000050u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x523059: 8b0d901f8200 MOV ECX,dword ptr [0x00821f90]
    s.cx = m.r32((0x00821f90u));
  }
  { // 0x52305f: 81e6ffff0000 AND ESI,0xffff
    s.si = integer::logical((s.si)&(0x0000ffffu),32,flags);
  }
  { // 0x523065: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x523066: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x523068: ff503c CALL dword ptr [EAX + 0x3c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000003cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x52306b: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x523070: a348a0a300 MOV [0x00a3a048],EAX
    m.w32((0x00a3a048u), s.ax);
  }
  { // 0x523075: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x523076: 742f JZ 0x005230a7
    if(integer::condition("JZ",flags)) goto L005230a7;
  }
  { // 0x523078: 8b0d901f8200 MOV ECX,dword ptr [0x00821f90]
    s.cx = m.r32((0x00821f90u));
  }
  { // 0x52307e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x523080: ff521c CALL dword ptr [EDX + 0x1c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000001cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x523083: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x523085: 740b JZ 0x00523092
    if(integer::condition("JZ",flags)) goto L00523092;
  }
  { // 0x523087: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x52308c: a34ca0a300 MOV [0x00a3a04c],EAX
    m.w32((0x00a3a04cu), s.ax);
  }
  { // 0x523091: c3 RET
    finish(m,s,f,0u); return;
  }
  L00523092: { // 0x523092: 8b0d901f8200 MOV ECX,dword ptr [0x00821f90]
    s.cx = m.r32((0x00821f90u));
  }
  { // 0x523098: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x52309a: ff5004 CALL dword ptr [EAX + 0x4]
    const std::uint32_t call_target=m.r32((s.ax+0x00000004u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x52309d: c70548a0a30000000000 MOV dword ptr [0x00a3a048],0x0
    m.w32((0x00a3a048u), 0x00000000u);
  }
  L005230a7: { // 0x5230a7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5230a9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00124560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x524560: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x524561: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x524563: 8a4604 MOV AL,byte ptr [ESI + 0x4]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000004u)));
  }
  { // 0x524566: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x524568: 7465 JZ 0x005245cf
    if(integer::condition("JZ",flags)) goto L005245cf;
  }
  { // 0x52456a: 8a4605 MOV AL,byte ptr [ESI + 0x5]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000005u)));
  }
  { // 0x52456d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x52456f: 745e JZ 0x005245cf
    if(integer::condition("JZ",flags)) goto L005245cf;
  }
  { // 0x524571: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x524572: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  { // 0x524576: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x524577: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  { // 0x52457b: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x52457d: 7411 JZ 0x00524590
    if(integer::condition("JZ",flags)) goto L00524590;
  }
  { // 0x52457f: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x524581: 740b JZ 0x0052458e
    if(integer::condition("JZ",flags)) goto L0052458e;
  }
  { // 0x524583: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x524585: e816e5ffff CALL 0x00522aa0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x52458a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x52458c: 7402 JZ 0x00524590
    if(integer::condition("JZ",flags)) goto L00524590;
  }
  L0052458e: { // 0x52458e: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00524590: { // 0x524590: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x524594: 8b4e48 MOV ECX,dword ptr [ESI + 0x48]
    s.cx = m.r32((s.si+0x00000048u));
  }
  { // 0x524597: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x524598: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x524599: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x52459b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x52459c: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x5245a0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5245a1: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5245a4: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5245a6: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x5245a8: 751d JNZ 0x005245c7
    if(integer::condition("JNZ",flags)) goto L005245c7;
  }
  { // 0x5245aa: 8b9e94000000 MOV EBX,dword ptr [ESI + 0x94]
    s.bx = m.r32((s.si+0x00000094u));
  }
  { // 0x5245b0: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x5245b1: 899e94000000 MOV dword ptr [ESI + 0x94],EBX
    m.w32((s.si+0x00000094u), s.bx);
  }
  { // 0x5245b7: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  { // 0x5245b9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5245ba: 687c8e7c00 PUSH 0x7c8e7c
    f.push(m,0x007c8e7cu);
  }
  { // 0x5245bf: e82c23eeff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5245c4: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005245c7: { // 0x5245c7: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x5245c9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5245ca: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5245cb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5245cc: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L005245cf: { // 0x5245cf: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5245d1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5245d2: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_00124620(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x524620: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x524621: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x524623: 8a4604 MOV AL,byte ptr [ESI + 0x4]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000004u)));
  }
  { // 0x524626: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x524628: 7457 JZ 0x00524681
    if(integer::condition("JZ",flags)) goto L00524681;
  }
  { // 0x52462a: 8a4605 MOV AL,byte ptr [ESI + 0x5]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000005u)));
  }
  { // 0x52462d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x52462f: 7450 JZ 0x00524681
    if(integer::condition("JZ",flags)) goto L00524681;
  }
  { // 0x524631: 8b4e4c MOV ECX,dword ptr [ESI + 0x4c]
    s.cx = m.r32((s.si+0x0000004cu));
  }
  { // 0x524634: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x524636: 7449 JZ 0x00524681
    if(integer::condition("JZ",flags)) goto L00524681;
  }
  { // 0x524638: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x52463c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x52463d: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x524643: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x524645: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x524646: 8d514c LEA EDX,[ECX + 0x4c]
    s.dx = (s.cx+0x0000004cu);
  }
  { // 0x524649: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x52464a: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  { // 0x52464e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x52464f: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  { // 0x524653: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x524654: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x524657: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x524659: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x52465b: 751d JNZ 0x0052467a
    if(integer::condition("JNZ",flags)) goto L0052467a;
  }
  { // 0x52465d: 8b8694000000 MOV EAX,dword ptr [ESI + 0x94]
    s.ax = m.r32((s.si+0x00000094u));
  }
  { // 0x524663: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x524664: 898694000000 MOV dword ptr [ESI + 0x94],EAX
    m.w32((s.si+0x00000094u), s.ax);
  }
  { // 0x52466a: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x52466c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x52466d: 687c8e7c00 PUSH 0x7c8e7c
    f.push(m,0x007c8e7cu);
  }
  { // 0x524672: e87922eeff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x524677: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0052467a: { // 0x52467a: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x52467c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x52467d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x52467e: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00524681: { // 0x524681: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x524683: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x524684: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_001263c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5263c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5263c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5263c3: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x5263c7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5263c9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5263ca: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5263cc: c6467600 MOV byte ptr [ESI + 0x76],0x0
    m.w8((s.si+0x00000076u), 0x00000000u);
  }
  { // 0x5263d0: ff909c010000 CALL dword ptr [EAX + 0x19c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000019cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5263d6: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5263d8: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5263da: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5263dc: ff921c010000 CALL dword ptr [EDX + 0x11c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000011cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5263e2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5263e3: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00127560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x527560: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x527562: ff909c000000 CALL dword ptr [EAX + 0x9c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000009cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x527568: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x52756a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x52756c: 7425 JZ 0x00527593
    if(integer::condition("JZ",flags)) goto L00527593;
  }
  { // 0x52756e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x52756f: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  { // 0x527572: 0faf31 IMUL ESI,dword ptr [ECX]
    s.si = integer::imul(s.si,m.r32((s.cx)),32,flags);
  }
  { // 0x527575: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x527579: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x52757a: f7fe IDIV ESI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.si,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  { // 0x52757c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x52757d: 8b4c9110 MOV ECX,dword ptr [ECX + EDX*0x4 + 0x10]
    s.cx = m.r32((s.cx+(s.dx * 0x00000004u)+0x00000010u));
  }
  { // 0x527581: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x527583: 740e JZ 0x00527593
    if(integer::condition("JZ",flags)) goto L00527593;
  }
  { // 0x527585: 0fbe4929 MOVSX ECX,byte ptr [ECX + 0x29]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x00000029u)),8));
  }
  { // 0x527589: 8b048d44917c00 MOV EAX,dword ptr [ECX*0x4 + 0x7c9144]
    s.ax = m.r32(((s.cx * 0x00000004u)+0x007c9144u));
  }
  { // 0x527590: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00527593: { // 0x527593: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x527595: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001275a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5275a0: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x5275a4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5275a5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5275a7: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5275a9: 7419 JZ 0x005275c4
    if(integer::condition("JZ",flags)) goto L005275c4;
  }
  { // 0x5275ab: 8b86a4000000 MOV EAX,dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  { // 0x5275b1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5275b3: 750f JNZ 0x005275c4
    if(integer::condition("JNZ",flags)) goto L005275c4;
  }
  { // 0x5275b5: 8a86c4020000 MOV AL,byte ptr [ESI + 0x2c4]
    s.ax = with_al(s.ax, m.r8((s.si+0x000002c4u)));
  }
  { // 0x5275bb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5275bd: 7405 JZ 0x005275c4
    if(integer::condition("JZ",flags)) goto L005275c4;
  }
  { // 0x5275bf: e8fc210000 CALL 0x005297c0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L005275c4: { // 0x5275c4: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5275c6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5275c8: ff909c000000 CALL dword ptr [EAX + 0x9c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000009cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5275ce: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5275d0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5275d1: 741b JZ 0x005275ee
    if(integer::condition("JZ",flags)) goto L005275ee;
  }
  { // 0x5275d3: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x5275d6: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x5275da: 0faf10 IMUL EDX,dword ptr [EAX]
    s.dx = integer::imul(s.dx,m.r32((s.ax)),32,flags);
  }
  { // 0x5275dd: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x5275df: 7d0d JGE 0x005275ee
    if(integer::condition("JGE",flags)) goto L005275ee;
  }
  { // 0x5275e1: 8b548810 MOV EDX,dword ptr [EAX + ECX*0x4 + 0x10]
    s.dx = m.r32((s.ax+(s.cx * 0x00000004u)+0x00000010u));
  }
  { // 0x5275e5: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x5275e7: 7405 JZ 0x005275ee
    if(integer::condition("JZ",flags)) goto L005275ee;
  }
  { // 0x5275e9: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x5275eb: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L005275ee: { // 0x5275ee: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x5275f0: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00129950(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x529950: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x529952: ff909c000000 CALL dword ptr [EAX + 0x9c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000009cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x529958: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x52995a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x52995c: 741e JZ 0x0052997c
    if(integer::condition("JZ",flags)) goto L0052997c;
  }
  { // 0x52995e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x52995f: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  { // 0x529962: 0faf31 IMUL ESI,dword ptr [ECX]
    s.si = integer::imul(s.si,m.r32((s.cx)),32,flags);
  }
  { // 0x529965: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x529969: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x52996a: f7fe IDIV ESI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.si,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  { // 0x52996c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x52996d: 8b4c9110 MOV ECX,dword ptr [ECX + EDX*0x4 + 0x10]
    s.cx = m.r32((s.cx+(s.dx * 0x00000004u)+0x00000010u));
  }
  { // 0x529971: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x529973: 7407 JZ 0x0052997c
    if(integer::condition("JZ",flags)) goto L0052997c;
  }
  { // 0x529975: 0fbe412a MOVSX EAX,byte ptr [ECX + 0x2a]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000002au)),8));
  }
  { // 0x529979: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0052997c: { // 0x52997c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x52997e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00130af0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x530af0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x530af1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x530af5: 81e6ff000000 AND ESI,0xff
    s.si = integer::logical((s.si)&(0x000000ffu),32,flags);
  }
  { // 0x530afb: 6683fe01 CMP SI,0x1
    (void)integer::sub((s.si & 0xffffu),0x00000001u,16,flags);
  }
  { // 0x530aff: 7406 JZ 0x00530b07
    if(integer::condition("JZ",flags)) goto L00530b07;
  }
  { // 0x530b01: 6683fe02 CMP SI,0x2
    (void)integer::sub((s.si & 0xffffu),0x00000002u,16,flags);
  }
  { // 0x530b05: 7517 JNZ 0x00530b1e
    if(integer::condition("JNZ",flags)) goto L00530b1e;
  }
  L00530b07: { // 0x530b07: 6a17 PUSH 0x17
    f.push(m,0x00000017u);
  }
  { // 0x530b09: ff15dc537800 CALL dword ptr [0x007853dc]
    const std::uint32_t call_target=m.r32((0x007853dcu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x530b0f: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x530b12: 750a JNZ 0x00530b1e
    if(integer::condition("JNZ",flags)) goto L00530b1e;
  }
  { // 0x530b14: 664e DEC SI
    s.si = (s.si & 0xffff0000u) | ((integer::decrement((s.si & 0xffffu),16,flags)) & 0xffffu);
  }
  { // 0x530b16: 66f7de NEG SI
    s.si = (s.si & 0xffff0000u) | ((integer::sub(0u,(s.si & 0xffffu),16,flags)) & 0xffffu);
  }
  { // 0x530b19: 1bf6 SBB ESI,ESI
    s.si = integer::sub(s.si,s.si,32,flags,flags&integer::CF);
  }
  { // 0x530b1b: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L00530b1e: { // 0x530b1e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x530b20: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  { // 0x530b26: e8051effff CALL 0x00522930
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x530b2b: 66f7d8 NEG AX
    s.ax = with_ax(s.ax, integer::sub(0u,(s.ax & 0xffffu),16,flags));
  }
  { // 0x530b2e: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x530b30: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x530b31: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x530b33: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00132b00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x532b00: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x532b04: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x532b05: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x532b07: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x532b09: 7414 JZ 0x00532b1f
    if(integer::condition("JZ",flags)) goto L00532b1f;
  }
  { // 0x532b0b: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x532b0f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x532b10: e8cb000000 CALL 0x00532be0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x532b15: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x532b17: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x532b19: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x532b1a: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x532b1c: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00532b1f: { // 0x532b1f: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x532b22: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x532b25: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x532b27: 7c31 JL 0x00532b5a
    if(integer::condition("JL",flags)) goto L00532b5a;
  }
  { // 0x532b29: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x532b2c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x532b2e: 7504 JNZ 0x00532b34
    if(integer::condition("JNZ",flags)) goto L00532b34;
  }
  { // 0x532b30: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x532b32: 7517 JNZ 0x00532b4b
    if(integer::condition("JNZ",flags)) goto L00532b4b;
  }
  L00532b34: { // 0x532b34: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x532b37: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x532b39: 7e10 JLE 0x00532b4b
    if(integer::condition("JLE",flags)) goto L00532b4b;
  }
  { // 0x532b3b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x532b3d: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x532b3f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x532b41: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x532b42: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x532b44: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x532b47: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x532b49: 750f JNZ 0x00532b5a
    if(integer::condition("JNZ",flags)) goto L00532b5a;
  }
  L00532b4b: { // 0x532b4b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x532b4d: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x532b4f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x532b51: 0f95c2 SETNZ DL
    s.dx = with_al(s.dx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x532b54: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  { // 0x532b56: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x532b57: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00532b5a: { // 0x532b5a: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x532b5d: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x532b60: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  { // 0x532b63: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x532b66: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x532b6a: 890c82 MOV dword ptr [EDX + EAX*0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.cx);
  }
  { // 0x532b6d: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x532b6f: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x532b71: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x532b72: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x532b74: 0f95c2 SETNZ DL
    s.dx = with_al(s.dx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x532b77: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  { // 0x532b79: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00135000(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x535000: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x535001: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x535002: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x535004: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x535006: 385e4c CMP byte ptr [ESI + 0x4c],BL
    (void)integer::sub(m.r8((s.si+0x0000004cu)),(s.bx & 0xffu),8,flags);
  }
  { // 0x535009: 7410 JZ 0x0053501b
    if(integer::condition("JZ",flags)) goto L0053501b;
  }
  { // 0x53500b: 8b4640 MOV EAX,dword ptr [ESI + 0x40]
    s.ax = m.r32((s.si+0x00000040u));
  }
  { // 0x53500e: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x535010: 7409 JZ 0x0053501b
    if(integer::condition("JZ",flags)) goto L0053501b;
  }
  { // 0x535012: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x535013: e863862300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x535018: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0053501b: { // 0x53501b: 8a464d MOV AL,byte ptr [ESI + 0x4d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000004du)));
  }
  { // 0x53501e: 895e40 MOV dword ptr [ESI + 0x40],EBX
    m.w32((s.si+0x00000040u), s.bx);
  }
  { // 0x535021: 3ac3 CMP AL,BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  { // 0x535023: 7410 JZ 0x00535035
    if(integer::condition("JZ",flags)) goto L00535035;
  }
  { // 0x535025: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  { // 0x535028: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x53502a: 7409 JZ 0x00535035
    if(integer::condition("JZ",flags)) goto L00535035;
  }
  { // 0x53502c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x53502d: e849862300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x535032: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00535035: { // 0x535035: 8a464e MOV AL,byte ptr [ESI + 0x4e]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000004eu)));
  }
  { // 0x535038: 895e44 MOV dword ptr [ESI + 0x44],EBX
    m.w32((s.si+0x00000044u), s.bx);
  }
  { // 0x53503b: 3ac3 CMP AL,BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  { // 0x53503d: 7410 JZ 0x0053504f
    if(integer::condition("JZ",flags)) goto L0053504f;
  }
  { // 0x53503f: 8b4648 MOV EAX,dword ptr [ESI + 0x48]
    s.ax = m.r32((s.si+0x00000048u));
  }
  { // 0x535042: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x535044: 7409 JZ 0x0053504f
    if(integer::condition("JZ",flags)) goto L0053504f;
  }
  { // 0x535046: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x535047: e82f862300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x53504c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0053504f: { // 0x53504f: 895e48 MOV dword ptr [ESI + 0x48],EBX
    m.w32((s.si+0x00000048u), s.bx);
  }
  { // 0x535052: e899251b00 CALL 0x006e75f0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x535057: e864261b00 CALL 0x006e76c0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x53505c: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x53505f: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  { // 0x535061: 7409 JZ 0x0053506c
    if(integer::condition("JZ",flags)) goto L0053506c;
  }
  { // 0x535063: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x535065: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x535067: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x535069: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L0053506c: { // 0x53506c: 8b4e5c MOV ECX,dword ptr [ESI + 0x5c]
    s.cx = m.r32((s.si+0x0000005cu));
  }
  { // 0x53506f: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  { // 0x535071: 7406 JZ 0x00535079
    if(integer::condition("JZ",flags)) goto L00535079;
  }
  { // 0x535073: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x535075: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x535077: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  L00535079: { // 0x535079: 895e5c MOV dword ptr [ESI + 0x5c],EBX
    m.w32((s.si+0x0000005cu), s.bx);
  }
  { // 0x53507c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53507d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x53507e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00137180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x537180: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x537181: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x537182: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x537184: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x537185: c706b4c87800 MOV dword ptr [ESI],0x78c8b4
    m.w32((s.si), 0x0078c8b4u);
  }
  { // 0x53718b: ff15ccc87800 CALL dword ptr [0x0078c8cc]
    const std::uint32_t call_target=m.r32((0x0078c8ccu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x537191: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x537193: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x537195: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x537197: ff501c CALL dword ptr [EAX + 0x1c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000001cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x53719a: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  { // 0x53719d: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x53719f: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x5371a1: 7406 JZ 0x005371a9
    if(integer::condition("JZ",flags)) goto L005371a9;
  }
  { // 0x5371a3: 8b5e04 MOV EBX,dword ptr [ESI + 0x4]
    s.bx = m.r32((s.si+0x00000004u));
  }
  { // 0x5371a6: 895a04 MOV dword ptr [EDX + 0x4],EBX
    m.w32((s.dx+0x00000004u), s.bx);
  }
  L005371a9: { // 0x5371a9: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x5371ac: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x5371ae: 7406 JZ 0x005371b6
    if(integer::condition("JZ",flags)) goto L005371b6;
  }
  { // 0x5371b0: 8b5e08 MOV EBX,dword ptr [ESI + 0x8]
    s.bx = m.r32((s.si+0x00000008u));
  }
  { // 0x5371b3: 895a08 MOV dword ptr [EDX + 0x8],EBX
    m.w32((s.dx+0x00000008u), s.bx);
  }
  L005371b6: { // 0x5371b6: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  { // 0x5371b8: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  { // 0x5371bb: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  { // 0x5371be: 750b JNZ 0x005371cb
    if(integer::condition("JNZ",flags)) goto L005371cb;
  }
  { // 0x5371c0: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x5371c2: 7407 JZ 0x005371cb
    if(integer::condition("JZ",flags)) goto L005371cb;
  }
  { // 0x5371c4: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x5371c6: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5371c8: ff5218 CALL dword ptr [EDX + 0x18]
    const std::uint32_t call_target=m.r32((s.dx+0x00000018u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L005371cb: { // 0x5371cb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5371cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5371cd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5371ce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001372c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5372c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5372c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5372c3: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x5372c7: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5372c9: ff501c CALL dword ptr [EAX + 0x1c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000001cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5372cc: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  { // 0x5372cf: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5372d1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5372d3: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x5372d6: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x5372dd: ff5218 CALL dword ptr [EDX + 0x18]
    const std::uint32_t call_target=m.r32((s.dx+0x00000018u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5372e0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5372e1: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001372f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5372f0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5372f1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5372f2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5372f4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5372f5: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5372f7: ff5018 CALL dword ptr [EAX + 0x18]
    const std::uint32_t call_target=m.r32((s.ax+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5372fa: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5372fc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5372fe: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x537300: ff521c CALL dword ptr [EDX + 0x1c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000001cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x537303: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  { // 0x537306: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x537308: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x53730a: 7406 JZ 0x00537312
    if(integer::condition("JZ",flags)) goto L00537312;
  }
  { // 0x53730c: 8b5e04 MOV EBX,dword ptr [ESI + 0x4]
    s.bx = m.r32((s.si+0x00000004u));
  }
  { // 0x53730f: 895a04 MOV dword ptr [EDX + 0x4],EBX
    m.w32((s.dx+0x00000004u), s.bx);
  }
  L00537312: { // 0x537312: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x537315: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x537317: 7406 JZ 0x0053731f
    if(integer::condition("JZ",flags)) goto L0053731f;
  }
  { // 0x537319: 8b5e08 MOV EBX,dword ptr [ESI + 0x8]
    s.bx = m.r32((s.si+0x00000008u));
  }
  { // 0x53731c: 895a08 MOV dword ptr [EDX + 0x8],EBX
    m.w32((s.dx+0x00000008u), s.bx);
  }
  L0053731f: { // 0x53731f: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  { // 0x537321: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  { // 0x537324: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  { // 0x537327: 7515 JNZ 0x0053733e
    if(integer::condition("JNZ",flags)) goto L0053733e;
  }
  { // 0x537329: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x53732b: 7506 JNZ 0x00537333
    if(integer::condition("JNZ",flags)) goto L00537333;
  }
  { // 0x53732d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x53732e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53732f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x537331: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x537332: c3 RET
    finish(m,s,f,0u); return;
  }
  L00537333: { // 0x537333: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x537335: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x537337: ff5218 CALL dword ptr [EDX + 0x18]
    const std::uint32_t call_target=m.r32((s.dx+0x00000018u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x53733a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x53733b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53733c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x53733d: c3 RET
    finish(m,s,f,0u); return;
  }
  L0053733e: { // 0x53733e: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x537340: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x537341: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x537342: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x537343: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001383a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5383a0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x5383a4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5383a5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5383a7: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5383a9: 741b JZ 0x005383c6
    if(integer::condition("JZ",flags)) goto L005383c6;
  }
  { // 0x5383ab: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  { // 0x5383ae: 8d4e34 LEA ECX,[ESI + 0x34]
    s.cx = (s.si+0x00000034u);
  }
  { // 0x5383b1: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x5383b5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5383b6: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x5383b8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5383b9: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5383bc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5383bd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5383bf: ff97a8000000 CALL dword ptr [EDI + 0xa8]
    const std::uint32_t call_target=m.r32((s.di+0x000000a8u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5383c5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005383c6: { // 0x5383c6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5383c7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001385c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5385c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5385c1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5385c2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x5385c4: 8a4754 MOV AL,byte ptr [EDI + 0x54]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000054u)));
  }
  { // 0x5385c7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5385c9: 7434 JZ 0x005385ff
    if(integer::condition("JZ",flags)) goto L005385ff;
  }
  { // 0x5385cb: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x5385cf: 8b8718010000 MOV EAX,dword ptr [EDI + 0x118]
    s.ax = m.r32((s.di+0x00000118u));
  }
  { // 0x5385d5: 8db718010000 LEA ESI,[EDI + 0x118]
    s.si = (s.di+0x00000118u);
  }
  { // 0x5385db: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5385dc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5385de: ff90b0000000 CALL dword ptr [EAX + 0xb0]
    const std::uint32_t call_target=m.r32((s.ax+0x000000b0u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5385e4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5385e6: 7417 JZ 0x005385ff
    if(integer::condition("JZ",flags)) goto L005385ff;
  }
  { // 0x5385e8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5385ea: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5385ec: ff9290000000 CALL dword ptr [EDX + 0x90]
    const std::uint32_t call_target=m.r32((s.dx+0x00000090u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5385f2: 898770010000 MOV dword ptr [EDI + 0x170],EAX
    m.w32((s.di+0x00000170u), s.ax);
  }
  { // 0x5385f8: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x5385fa: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5385fc: ff5048 CALL dword ptr [EAX + 0x48]
    const std::uint32_t call_target=m.r32((s.ax+0x00000048u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L005385ff: { // 0x5385ff: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x538600: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x538601: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00138610(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x538610: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x538611: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x538612: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x538614: 8a4754 MOV AL,byte ptr [EDI + 0x54]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000054u)));
  }
  { // 0x538617: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x538619: 7434 JZ 0x0053864f
    if(integer::condition("JZ",flags)) goto L0053864f;
  }
  { // 0x53861b: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x53861f: 8b8718010000 MOV EAX,dword ptr [EDI + 0x118]
    s.ax = m.r32((s.di+0x00000118u));
  }
  { // 0x538625: 8db718010000 LEA ESI,[EDI + 0x118]
    s.si = (s.di+0x00000118u);
  }
  { // 0x53862b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x53862c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x53862e: ff90b0000000 CALL dword ptr [EAX + 0xb0]
    const std::uint32_t call_target=m.r32((s.ax+0x000000b0u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x538634: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x538636: 7417 JZ 0x0053864f
    if(integer::condition("JZ",flags)) goto L0053864f;
  }
  { // 0x538638: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x53863a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x53863c: ff9290000000 CALL dword ptr [EDX + 0x90]
    const std::uint32_t call_target=m.r32((s.dx+0x00000090u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x538642: 898770010000 MOV dword ptr [EDI + 0x170],EAX
    m.w32((s.di+0x00000170u), s.ax);
  }
  { // 0x538648: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x53864a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x53864c: ff5048 CALL dword ptr [EAX + 0x48]
    const std::uint32_t call_target=m.r32((s.ax+0x00000048u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L0053864f: { // 0x53864f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x538650: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x538651: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00138710(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x538710: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x538711: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x538713: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  { // 0x538716: 8b4e50 MOV ECX,dword ptr [ESI + 0x50]
    s.cx = m.r32((s.si+0x00000050u));
  }
  { // 0x538719: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x53871b: b900000000 MOV ECX,0x0
    s.cx = 0x00000000u;
  }
  { // 0x538720: 0f98c1 SETS CL
    s.cx = with_al(s.cx, (integer::condition("SETS",flags)?1u:0u));
  }
  { // 0x538723: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x538724: 23c8 AND ECX,EAX
    s.cx = integer::logical((s.cx)&(s.ax),32,flags);
  }
  { // 0x538726: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x53872a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x53872c: 7d04 JGE 0x00538732
    if(integer::condition("JGE",flags)) goto L00538732;
  }
  { // 0x53872e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x538730: eb06 JMP 0x00538738
    goto L00538738;
  }
  L00538732: { // 0x538732: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x538734: 7e02 JLE 0x00538738
    if(integer::condition("JLE",flags)) goto L00538738;
  }
  { // 0x538736: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00538738: { // 0x538738: 3b8670010000 CMP EAX,dword ptr [ESI + 0x170]
    (void)integer::sub(s.ax,m.r32((s.si+0x00000170u)),32,flags);
  }
  { // 0x53873e: 7436 JZ 0x00538776
    if(integer::condition("JZ",flags)) goto L00538776;
  }
  { // 0x538740: 898670010000 MOV dword ptr [ESI + 0x170],EAX
    m.w32((s.si+0x00000170u), s.ax);
  }
  { // 0x538746: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x538748: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x53874a: ff5048 CALL dword ptr [EAX + 0x48]
    const std::uint32_t call_target=m.r32((s.ax+0x00000048u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x53874d: 8a4654 MOV AL,byte ptr [ESI + 0x54]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000054u)));
  }
  { // 0x538750: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x538752: 7419 JZ 0x0053876d
    if(integer::condition("JZ",flags)) goto L0053876d;
  }
  { // 0x538754: 8b8670010000 MOV EAX,dword ptr [ESI + 0x170]
    s.ax = m.r32((s.si+0x00000170u));
  }
  { // 0x53875a: 8b9618010000 MOV EDX,dword ptr [ESI + 0x118]
    s.dx = m.r32((s.si+0x00000118u));
  }
  { // 0x538760: 8d8e18010000 LEA ECX,[ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  { // 0x538766: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x538767: ff928c000000 CALL dword ptr [EDX + 0x8c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000008cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0053876d: { // 0x53876d: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x538772: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x538773: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00538776: { // 0x538776: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x538778: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x538779: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00138850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x538850: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x538851: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x538853: 8a4654 MOV AL,byte ptr [ESI + 0x54]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000054u)));
  }
  { // 0x538856: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x538858: 7447 JZ 0x005388a1
    if(integer::condition("JZ",flags)) goto L005388a1;
  }
  { // 0x53885a: 8b862c010000 MOV EAX,dword ptr [ESI + 0x12c]
    s.ax = m.r32((s.si+0x0000012cu));
  }
  { // 0x538860: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x538863: 8b9618010000 MOV EDX,dword ptr [ESI + 0x118]
    s.dx = m.r32((s.si+0x00000118u));
  }
  { // 0x538869: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x53886b: 894e14 MOV dword ptr [ESI + 0x14],ECX
    m.w32((s.si+0x00000014u), s.cx);
  }
  { // 0x53886e: 8d8e18010000 LEA ECX,[ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  { // 0x538874: c6465400 MOV byte ptr [ESI + 0x54],0x0
    m.w8((s.si+0x00000054u), 0x00000000u);
  }
  { // 0x538878: ff5224 CALL dword ptr [EDX + 0x24]
    const std::uint32_t call_target=m.r32((s.dx+0x00000024u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x53887b: 8b4658 MOV EAX,dword ptr [ESI + 0x58]
    s.ax = m.r32((s.si+0x00000058u));
  }
  { // 0x53887e: 8d4e58 LEA ECX,[ESI + 0x58]
    s.cx = (s.si+0x00000058u);
  }
  { // 0x538881: ff5024 CALL dword ptr [EAX + 0x24]
    const std::uint32_t call_target=m.r32((s.ax+0x00000024u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x538884: 8b96b8000000 MOV EDX,dword ptr [ESI + 0xb8]
    s.dx = m.r32((s.si+0x000000b8u));
  }
  { // 0x53888a: 8d8eb8000000 LEA ECX,[ESI + 0xb8]
    s.cx = (s.si+0x000000b8u);
  }
  { // 0x538890: ff5224 CALL dword ptr [EDX + 0x24]
    const std::uint32_t call_target=m.r32((s.dx+0x00000024u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x538893: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x538895: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x538897: ff5048 CALL dword ptr [EAX + 0x48]
    const std::uint32_t call_target=m.r32((s.ax+0x00000048u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x53889a: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x53889f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5388a0: c3 RET
    finish(m,s,f,0u); return;
  }
  L005388a1: { // 0x5388a1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5388a3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5388a4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001389b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5389b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5389b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5389b3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5389b4: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x5389b8: 8a4654 MOV AL,byte ptr [ESI + 0x54]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000054u)));
  }
  { // 0x5389bb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5389bd: 742a JZ 0x005389e9
    if(integer::condition("JZ",flags)) goto L005389e9;
  }
  { // 0x5389bf: 8b8618010000 MOV EAX,dword ptr [ESI + 0x118]
    s.ax = m.r32((s.si+0x00000118u));
  }
  { // 0x5389c5: 8d8e18010000 LEA ECX,[ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  { // 0x5389cb: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5389cc: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5389cf: 8b96b8000000 MOV EDX,dword ptr [ESI + 0xb8]
    s.dx = m.r32((s.si+0x000000b8u));
  }
  { // 0x5389d5: 8d8eb8000000 LEA ECX,[ESI + 0xb8]
    s.cx = (s.si+0x000000b8u);
  }
  { // 0x5389db: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5389dc: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5389df: 8b4658 MOV EAX,dword ptr [ESI + 0x58]
    s.ax = m.r32((s.si+0x00000058u));
  }
  { // 0x5389e2: 8d4e58 LEA ECX,[ESI + 0x58]
    s.cx = (s.si+0x00000058u);
  }
  { // 0x5389e5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5389e6: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L005389e9: { // 0x5389e9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5389ea: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5389ec: e88fe8ffff CALL 0x00537280
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5389f1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5389f2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5389f3: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00138a00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x538a00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x538a01: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x538a03: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x538a04: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x538a08: 8a4654 MOV AL,byte ptr [ESI + 0x54]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000054u)));
  }
  { // 0x538a0b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x538a0d: 742a JZ 0x00538a39
    if(integer::condition("JZ",flags)) goto L00538a39;
  }
  { // 0x538a0f: 8b8618010000 MOV EAX,dword ptr [ESI + 0x118]
    s.ax = m.r32((s.si+0x00000118u));
  }
  { // 0x538a15: 8d8e18010000 LEA ECX,[ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  { // 0x538a1b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x538a1c: ff5014 CALL dword ptr [EAX + 0x14]
    const std::uint32_t call_target=m.r32((s.ax+0x00000014u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x538a1f: 8b96b8000000 MOV EDX,dword ptr [ESI + 0xb8]
    s.dx = m.r32((s.si+0x000000b8u));
  }
  { // 0x538a25: 8d8eb8000000 LEA ECX,[ESI + 0xb8]
    s.cx = (s.si+0x000000b8u);
  }
  { // 0x538a2b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x538a2c: ff5214 CALL dword ptr [EDX + 0x14]
    const std::uint32_t call_target=m.r32((s.dx+0x00000014u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x538a2f: 8b4658 MOV EAX,dword ptr [ESI + 0x58]
    s.ax = m.r32((s.si+0x00000058u));
  }
  { // 0x538a32: 8d4e58 LEA ECX,[ESI + 0x58]
    s.cx = (s.si+0x00000058u);
  }
  { // 0x538a35: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x538a36: ff5014 CALL dword ptr [EAX + 0x14]
    const std::uint32_t call_target=m.r32((s.ax+0x00000014u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00538a39: { // 0x538a39: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x538a3a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x538a3c: e85fe8ffff CALL 0x005372a0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x538a41: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x538a42: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x538a43: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00138aa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x538aa0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x538aa1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x538aa3: 8a4654 MOV AL,byte ptr [ESI + 0x54]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000054u)));
  }
  { // 0x538aa6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x538aa8: 7427 JZ 0x00538ad1
    if(integer::condition("JZ",flags)) goto L00538ad1;
  }
  { // 0x538aaa: 8b8618010000 MOV EAX,dword ptr [ESI + 0x118]
    s.ax = m.r32((s.si+0x00000118u));
  }
  { // 0x538ab0: 8d8e18010000 LEA ECX,[ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  { // 0x538ab6: ff5024 CALL dword ptr [EAX + 0x24]
    const std::uint32_t call_target=m.r32((s.ax+0x00000024u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x538ab9: 8b96b8000000 MOV EDX,dword ptr [ESI + 0xb8]
    s.dx = m.r32((s.si+0x000000b8u));
  }
  { // 0x538abf: 8d8eb8000000 LEA ECX,[ESI + 0xb8]
    s.cx = (s.si+0x000000b8u);
  }
  { // 0x538ac5: ff5224 CALL dword ptr [EDX + 0x24]
    const std::uint32_t call_target=m.r32((s.dx+0x00000024u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x538ac8: 8b4658 MOV EAX,dword ptr [ESI + 0x58]
    s.ax = m.r32((s.si+0x00000058u));
  }
  { // 0x538acb: 8d4e58 LEA ECX,[ESI + 0x58]
    s.cx = (s.si+0x00000058u);
  }
  { // 0x538ace: ff5024 CALL dword ptr [EAX + 0x24]
    const std::uint32_t call_target=m.r32((s.ax+0x00000024u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00538ad1: { // 0x538ad1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x538ad3: e87862f9ff CALL 0x004ced50
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x538ad8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x538ad9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00138ae0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x538ae0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x538ae4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x538ae5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x538ae7: 3b4644 CMP EAX,dword ptr [ESI + 0x44]
    (void)integer::sub(s.ax,m.r32((s.si+0x00000044u)),32,flags);
  }
  { // 0x538aea: 734f JNC 0x00538b3b
    if(integer::condition("JNC",flags)) goto L00538b3b;
  }
  { // 0x538aec: 89866c010000 MOV dword ptr [ESI + 0x16c],EAX
    m.w32((s.si+0x0000016cu), s.ax);
  }
  { // 0x538af2: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x538af4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x538af6: ff5048 CALL dword ptr [EAX + 0x48]
    const std::uint32_t call_target=m.r32((s.ax+0x00000048u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x538af9: 8b866c010000 MOV EAX,dword ptr [ESI + 0x16c]
    s.ax = m.r32((s.si+0x0000016cu));
  }
  { // 0x538aff: 8b8e70010000 MOV ECX,dword ptr [ESI + 0x170]
    s.cx = m.r32((s.si+0x00000170u));
  }
  { // 0x538b05: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x538b07: 7d0b JGE 0x00538b14
    if(integer::condition("JGE",flags)) goto L00538b14;
  }
  { // 0x538b09: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x538b0b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x538b0c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x538b0e: ff92c0000000 CALL dword ptr [EDX + 0xc0]
    const std::uint32_t call_target=m.r32((s.dx+0x000000c0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00538b14: { // 0x538b14: 8b4e50 MOV ECX,dword ptr [ESI + 0x50]
    s.cx = m.r32((s.si+0x00000050u));
  }
  { // 0x538b17: 8b9670010000 MOV EDX,dword ptr [ESI + 0x170]
    s.dx = m.r32((s.si+0x00000170u));
  }
  { // 0x538b1d: 8b866c010000 MOV EAX,dword ptr [ESI + 0x16c]
    s.ax = m.r32((s.si+0x0000016cu));
  }
  { // 0x538b23: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  { // 0x538b25: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x538b27: 7c1c JL 0x00538b45
    if(integer::condition("JL",flags)) goto L00538b45;
  }
  { // 0x538b29: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x538b2b: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x538b2d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x538b2e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x538b30: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x538b31: ff92c0000000 CALL dword ptr [EDX + 0xc0]
    const std::uint32_t call_target=m.r32((s.dx+0x000000c0u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x538b37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x538b38: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00538b3b: { // 0x538b3b: c7866c01000000000000 MOV dword ptr [ESI + 0x16c],0x0
    m.w32((s.si+0x0000016cu), 0x00000000u);
  }
  L00538b45: { // 0x538b45: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x538b46: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00138b70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x538b70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x538b71: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x538b73: 8a4654 MOV AL,byte ptr [ESI + 0x54]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000054u)));
  }
  { // 0x538b76: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x538b78: 7427 JZ 0x00538ba1
    if(integer::condition("JZ",flags)) goto L00538ba1;
  }
  { // 0x538b7a: 8b4658 MOV EAX,dword ptr [ESI + 0x58]
    s.ax = m.r32((s.si+0x00000058u));
  }
  { // 0x538b7d: 8d4e58 LEA ECX,[ESI + 0x58]
    s.cx = (s.si+0x00000058u);
  }
  { // 0x538b80: ff5048 CALL dword ptr [EAX + 0x48]
    const std::uint32_t call_target=m.r32((s.ax+0x00000048u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x538b83: 8b96b8000000 MOV EDX,dword ptr [ESI + 0xb8]
    s.dx = m.r32((s.si+0x000000b8u));
  }
  { // 0x538b89: 8d8eb8000000 LEA ECX,[ESI + 0xb8]
    s.cx = (s.si+0x000000b8u);
  }
  { // 0x538b8f: ff5248 CALL dword ptr [EDX + 0x48]
    const std::uint32_t call_target=m.r32((s.dx+0x00000048u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x538b92: 8b8618010000 MOV EAX,dword ptr [ESI + 0x118]
    s.ax = m.r32((s.si+0x00000118u));
  }
  { // 0x538b98: 8d8e18010000 LEA ECX,[ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  { // 0x538b9e: ff5048 CALL dword ptr [EAX + 0x48]
    const std::uint32_t call_target=m.r32((s.ax+0x00000048u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00538ba1: { // 0x538ba1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x538ba3: e8d865f9ff CALL 0x004cf180
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x538ba8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x538ba9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0013b450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x53b450: 8b154467a500 MOV EDX,dword ptr [0x00a56744]
    s.dx = m.r32((0x00a56744u));
  }
  { // 0x53b456: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53b457: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x53b458: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x53b45c: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x53b45d: 8d4714 LEA EAX,[EDI + 0x14]
    s.ax = (s.di+0x00000014u);
  }
  { // 0x53b460: 89154467a500 MOV dword ptr [0x00a56744],EDX
    m.w32((0x00a56744u), s.dx);
  }
  { // 0x53b466: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x53b467: ff15c0517800 CALL dword ptr [0x007851c0]
    const std::uint32_t call_target=m.r32((0x007851c0u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x53b46d: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x53b46f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x53b471: 750d JNZ 0x0053b480
    if(integer::condition("JNZ",flags)) goto L0053b480;
  }
  { // 0x53b473: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x53b475: 7409 JZ 0x0053b480
    if(integer::condition("JZ",flags)) goto L0053b480;
  }
  { // 0x53b477: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  { // 0x53b479: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x53b47b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x53b47d: ff5220 CALL dword ptr [EDX + 0x20]
    const std::uint32_t call_target=m.r32((s.dx+0x00000020u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0053b480: { // 0x53b480: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x53b482: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x53b483: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53b484: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0013b540(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x53b540: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53b541: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x53b545: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x53b547: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x53b548: 750a JNZ 0x0053b554
    if(integer::condition("JNZ",flags)) goto L0053b554;
  }
  { // 0x53b54a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x53b54b: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  { // 0x53b550: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53b551: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0053b554: { // 0x53b554: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x53b558: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x53b55a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x53b55c: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  { // 0x53b560: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x53b562: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x53b563: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53b564: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  { // 0x53b568: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x53b56b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x53b56d: 7c23 JL 0x0053b592
    if(integer::condition("JL",flags)) goto L0053b592;
  }
  { // 0x53b56f: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  { // 0x53b571: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x53b572: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  { // 0x53b574: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x53b576: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x53b578: ff5224 CALL dword ptr [EDX + 0x24]
    const std::uint32_t call_target=m.r32((s.dx+0x00000024u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x53b57b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x53b57c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x53b57d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53b57e: ff5310 CALL dword ptr [EBX + 0x10]
    const std::uint32_t call_target=m.r32((s.bx+0x00000010u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x53b581: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x53b583: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x53b584: 7c0c JL 0x0053b592
    if(integer::condition("JL",flags)) goto L0053b592;
  }
  { // 0x53b586: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x53b58a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x53b58c: 7404 JZ 0x0053b592
    if(integer::condition("JZ",flags)) goto L0053b592;
  }
  { // 0x53b58e: c6471100 MOV byte ptr [EDI + 0x11],0x0
    m.w8((s.di+0x00000011u), 0x00000000u);
  }
  L0053b592: { // 0x53b592: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x53b593: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53b594: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0013b5a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x53b5a0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x53b5a1: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x53b5a5: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x53b5a7: 7509 JNZ 0x0053b5b2
    if(integer::condition("JNZ",flags)) goto L0053b5b2;
  }
  { // 0x53b5a9: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  { // 0x53b5ae: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x53b5af: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0053b5b2: { // 0x53b5b2: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x53b5b4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x53b5b6: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x53b5ba: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x53b5bc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x53b5bd: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x53b5be: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x53b5c1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x53b5c3: 7c51 JL 0x0053b616
    if(integer::condition("JL",flags)) goto L0053b616;
  }
  { // 0x53b5c5: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x53b5c9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x53b5ca: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x53b5cb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53b5cc: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  { // 0x53b5d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53b5d1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x53b5d2: 687053aa00 PUSH 0xaa5370
    f.push(m,0x00aa5370u);
  }
  { // 0x53b5d7: e8149c1500 CALL 0x006951f0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x53b5dc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x53b5de: 8b5e14 MOV EBX,dword ptr [ESI + 0x14]
    s.bx = m.r32((s.si+0x00000014u));
  }
  { // 0x53b5e1: 8b2f MOV EBP,dword ptr [EDI]
    s.bp = m.r32((s.di));
  }
  { // 0x53b5e3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x53b5e5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x53b5e7: ff5024 CALL dword ptr [EAX + 0x24]
    const std::uint32_t call_target=m.r32((s.ax+0x00000024u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x53b5ea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x53b5eb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53b5ec: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x53b5ed: ff550c CALL dword ptr [EBP + 0xc]
    const std::uint32_t call_target=m.r32((s.bp+0x0000000cu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x53b5f0: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x53b5f3: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x53b5f5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x53b5f6: 687053aa00 PUSH 0xaa5370
    f.push(m,0x00aa5370u);
  }
  { // 0x53b5fb: 895e14 MOV dword ptr [ESI + 0x14],EBX
    m.w32((s.si+0x00000014u), s.bx);
  }
  { // 0x53b5fe: e86d9b1500 CALL 0x00695170
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x53b603: 83c608 ADD ESI,0x8
    s.si = integer::add(s.si,0x00000008u,32,flags);
  }
  { // 0x53b606: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53b607: 687053aa00 PUSH 0xaa5370
    f.push(m,0x00aa5370u);
  }
  { // 0x53b60c: e85f9b1500 CALL 0x00695170
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x53b611: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53b612: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x53b613: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x53b615: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0053b616: { // 0x53b616: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x53b617: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00175cc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x575cc0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x575cc4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x575cc6: 740f JZ 0x00575cd7
    if(integer::condition("JZ",flags)) goto L00575cd7;
  }
  { // 0x575cc8: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x575cca: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x575ccb: 8d7178 LEA ESI,[ECX + 0x78]
    s.si = (s.cx+0x00000078u);
  }
  { // 0x575cce: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x575ccf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x575cd0: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x575cd3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x575cd4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00575cd7: { // 0x575cd7: 8d4178 LEA EAX,[ECX + 0x78]
    s.ax = (s.cx+0x00000078u);
  }
  { // 0x575cda: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x575cdb: e8b036fcff CALL 0x00539390
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x575ce0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x575ce2: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x575ce5: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00175f90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x575f90: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x575f94: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x575f96: 7409 JZ 0x00575fa1
    if(integer::condition("JZ",flags)) goto L00575fa1;
  }
  { // 0x575f98: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x575f9a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x575f9b: ff5204 CALL dword ptr [EDX + 0x4]
    const std::uint32_t call_target=m.r32((s.dx+0x00000004u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x575f9e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00575fa1: { // 0x575fa1: e8ca33fcff CALL 0x00539370
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x575fa6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x575fa8: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x575fab: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0018ca60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58ca60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x58ca61: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x58ca63: 8b8eb4000000 MOV ECX,dword ptr [ESI + 0xb4]
    s.cx = m.r32((s.si+0x000000b4u));
  }
  { // 0x58ca69: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x58ca6b: 7410 JZ 0x0058ca7d
    if(integer::condition("JZ",flags)) goto L0058ca7d;
  }
  { // 0x58ca6d: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x58ca6f: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x58ca71: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x58ca73: c786b400000000000000 MOV dword ptr [ESI + 0xb4],0x0
    m.w32((s.si+0x000000b4u), 0x00000000u);
  }
  L0058ca7d: { // 0x58ca7d: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  { // 0x58ca83: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x58ca85: 7410 JZ 0x0058ca97
    if(integer::condition("JZ",flags)) goto L0058ca97;
  }
  { // 0x58ca87: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x58ca89: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x58ca8b: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x58ca8d: c786b000000000000000 MOV dword ptr [ESI + 0xb0],0x0
    m.w32((s.si+0x000000b0u), 0x00000000u);
  }
  L0058ca97: { // 0x58ca97: 8b8eac000000 MOV ECX,dword ptr [ESI + 0xac]
    s.cx = m.r32((s.si+0x000000acu));
  }
  { // 0x58ca9d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x58ca9f: 7410 JZ 0x0058cab1
    if(integer::condition("JZ",flags)) goto L0058cab1;
  }
  { // 0x58caa1: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x58caa3: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x58caa5: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x58caa7: c786ac00000000000000 MOV dword ptr [ESI + 0xac],0x0
    m.w32((s.si+0x000000acu), 0x00000000u);
  }
  L0058cab1: { // 0x58cab1: 8d4e50 LEA ECX,[ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  { // 0x58cab4: e857080200 CALL 0x005ad310
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x58cab9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x58caba: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0018e640(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58e640: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x58e641: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x58e645: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x58e647: 8d4efc LEA ECX,[ESI + -0x4]
    s.cx = (s.si-0x00000004u);
  }
  { // 0x58e64a: e851010000 CALL 0x0058e7a0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x58e64f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x58e651: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x58e652: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x58e655: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x58e656: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0018ffa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58ffa0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x58ffa1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x58ffa5: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x58ffa8: 81c1e0020000 ADD ECX,0x2e0
    s.cx = integer::add(s.cx,0x000002e0u,32,flags);
  }
  { // 0x58ffae: e84d89f2ff CALL 0x004b8900
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x58ffb3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x58ffb5: 7406 JZ 0x0058ffbd
    if(integer::condition("JZ",flags)) goto L0058ffbd;
  }
  { // 0x58ffb7: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x58ffb9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x58ffba: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0058ffbd: { // 0x58ffbd: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x58ffbf: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x58ffc0: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x58ffc3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x58ffc5: 743a JZ 0x00590001
    if(integer::condition("JZ",flags)) goto L00590001;
  }
  { // 0x58ffc7: 8b4e20 MOV ECX,dword ptr [ESI + 0x20]
    s.cx = m.r32((s.si+0x00000020u));
  }
  { // 0x58ffca: a13087a500 MOV EAX,[0x00a58730]
    s.ax = m.r32((0x00a58730u));
  }
  { // 0x58ffcf: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x58ffd1: 7519 JNZ 0x0058ffec
    if(integer::condition("JNZ",flags)) goto L0058ffec;
  }
  { // 0x58ffd3: 8b5624 MOV EDX,dword ptr [ESI + 0x24]
    s.dx = m.r32((s.si+0x00000024u));
  }
  { // 0x58ffd6: a13487a500 MOV EAX,[0x00a58734]
    s.ax = m.r32((0x00a58734u));
  }
  { // 0x58ffdb: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x58ffdd: 750d JNZ 0x0058ffec
    if(integer::condition("JNZ",flags)) goto L0058ffec;
  }
  { // 0x58ffdf: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x58ffe2: 8b0d3887a500 MOV ECX,dword ptr [0x00a58738]
    s.cx = m.r32((0x00a58738u));
  }
  { // 0x58ffe8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x58ffea: 7415 JZ 0x00590001
    if(integer::condition("JZ",flags)) goto L00590001;
  }
  L0058ffec: { // 0x58ffec: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x58ffef: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x58fff1: ff92bc040000 CALL dword ptr [EDX + 0x4bc]
    const std::uint32_t call_target=m.r32((s.dx+0x000004bcu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x58fff7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x58fff9: 7e06 JLE 0x00590001
    if(integer::condition("JLE",flags)) goto L00590001;
  }
  { // 0x58fffb: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x58fffd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x58fffe: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00590001: { // 0x590001: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x590003: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x590004: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00191ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x591ab0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x591ab4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x591ab5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x591ab7: 8b8e98000000 MOV ECX,dword ptr [ESI + 0x98]
    s.cx = m.r32((s.si+0x00000098u));
  }
  { // 0x591abd: 83f91c CMP ECX,0x1c
    (void)integer::sub(s.cx,0x0000001cu,32,flags);
  }
  { // 0x591ac0: 7505 JNZ 0x00591ac7
    if(integer::condition("JNZ",flags)) goto L00591ac7;
  }
  { // 0x591ac2: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  { // 0x591ac5: 744a JZ 0x00591b11
    if(integer::condition("JZ",flags)) goto L00591b11;
  }
  L00591ac7: { // 0x591ac7: 83f913 CMP ECX,0x13
    (void)integer::sub(s.cx,0x00000013u,32,flags);
  }
  { // 0x591aca: 7445 JZ 0x00591b11
    if(integer::condition("JZ",flags)) goto L00591b11;
  }
  { // 0x591acc: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x591acf: 7420 JZ 0x00591af1
    if(integer::condition("JZ",flags)) goto L00591af1;
  }
  { // 0x591ad1: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x591ad3: 750f JNZ 0x00591ae4
    if(integer::condition("JNZ",flags)) goto L00591ae4;
  }
  { // 0x591ad5: 8b8ea0000000 MOV ECX,dword ptr [ESI + 0xa0]
    s.cx = m.r32((s.si+0x000000a0u));
  }
  { // 0x591adb: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x591add: 7412 JZ 0x00591af1
    if(integer::condition("JZ",flags)) goto L00591af1;
  }
  { // 0x591adf: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  { // 0x591ae2: 740d JZ 0x00591af1
    if(integer::condition("JZ",flags)) goto L00591af1;
  }
  L00591ae4: { // 0x591ae4: 8986a0000000 MOV dword ptr [ESI + 0xa0],EAX
    m.w32((s.si+0x000000a0u), s.ax);
  }
  { // 0x591aea: c686a400000000 MOV byte ptr [ESI + 0xa4],0x0
    m.w8((s.si+0x000000a4u), 0x00000000u);
  }
  L00591af1: { // 0x591af1: 8a44240c MOV AL,byte ptr [ESP + 0xc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000cu)));
  }
  { // 0x591af5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x591af7: 7418 JZ 0x00591b11
    if(integer::condition("JZ",flags)) goto L00591b11;
  }
  { // 0x591af9: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x591afb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x591afd: ff90e8010000 CALL dword ptr [EAX + 0x1e8]
    const std::uint32_t call_target=m.r32((s.ax+0x000001e8u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x591b03: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x591b05: 740a JZ 0x00591b11
    if(integer::condition("JZ",flags)) goto L00591b11;
  }
  { // 0x591b07: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x591b09: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x591b0b: ff92d4010000 CALL dword ptr [EDX + 0x1d4]
    const std::uint32_t call_target=m.r32((s.dx+0x000001d4u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00591b11: { // 0x591b11: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x591b12: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00193dc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x593dc0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x593dc1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x593dc2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x593dc4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x593dc5: 6867060000 PUSH 0x667
    f.push(m,0x00000667u);
  }
  { // 0x593dca: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x593dcc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x593dcd: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x593dd3: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x593dd5: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x593dd7: 742f JZ 0x00593e08
    if(integer::condition("JZ",flags)) goto L00593e08;
  }
  { // 0x593dd9: 8b1da0547800 MOV EBX,dword ptr [0x007854a0]
    s.bx = m.r32((0x007854a0u));
  }
  { // 0x593ddf: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x593de1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x593de3: 6847010000 PUSH 0x147
    f.push(m,0x00000147u);
  }
  { // 0x593de8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x593de9: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x593deb: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x593dee: 7418 JZ 0x00593e08
    if(integer::condition("JZ",flags)) goto L00593e08;
  }
  { // 0x593df0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x593df2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x593df3: 6850010000 PUSH 0x150
    f.push(m,0x00000150u);
  }
  { // 0x593df8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x593df9: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x593dfb: a3ec56a200 MOV [0x00a256ec],EAX
    m.w32((0x00a256ecu), s.ax);
  }
  { // 0x593e00: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x593e02: 884609 MOV byte ptr [ESI + 0x9],AL
    m.w8((s.si+0x00000009u), (s.ax & 0xffu));
  }
  { // 0x593e05: 884608 MOV byte ptr [ESI + 0x8],AL
    m.w8((s.si+0x00000008u), (s.ax & 0xffu));
  }
  L00593e08: { // 0x593e08: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x593e09: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x593e0a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x593e0b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00195310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x595310: 81ec00020000 SUB ESP,0x200
    f.sp = integer::sub(f.sp,0x00000200u,32,flags);
  }
  { // 0x595316: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x595317: 8b9c2410020000 MOV EBX,dword ptr [ESP + 0x210]
    s.bx = m.r32((f.sp+0x00000210u));
  }
  { // 0x59531e: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x595320: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x595321: 745c JZ 0x0059537f
    if(integer::condition("JZ",flags)) goto L0059537f;
  }
  { // 0x595323: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x595325: 683f050000 PUSH 0x53f
    f.push(m,0x0000053fu);
  }
  { // 0x59532a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x59532b: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x595331: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x595333: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x595335: 7448 JZ 0x0059537f
    if(integer::condition("JZ",flags)) goto L0059537f;
  }
  { // 0x595337: 8b842410020000 MOV EAX,dword ptr [ESP + 0x210]
    s.ax = m.r32((f.sp+0x00000210u));
  }
  { // 0x59533e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x59533f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x595341: 7c0e JL 0x00595351
    if(integer::condition("JL",flags)) goto L00595351;
  }
  { // 0x595343: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  { // 0x595346: 7d09 JGE 0x00595351
    if(integer::condition("JGE",flags)) goto L00595351;
  }
  { // 0x595348: 8b348578117d00 MOV ESI,dword ptr [EAX*0x4 + 0x7d1178]
    s.si = m.r32(((s.ax * 0x00000004u)+0x007d1178u));
  }
  { // 0x59534f: eb06 JMP 0x00595357
    goto L00595357;
  }
  L00595351: { // 0x595351: 8b353c237900 MOV ESI,dword ptr [0x0079233c]
    s.si = m.r32((0x0079233cu));
  }
  L00595357: { // 0x595357: 8b8c2410020000 MOV ECX,dword ptr [ESP + 0x210]
    s.cx = m.r32((f.sp+0x00000210u));
  }
  { // 0x59535e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x59535f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x595360: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x595364: 6850c97c00 PUSH 0x7cc950
    f.push(m,0x007cc950u);
  }
  { // 0x595369: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x59536a: e8359d1d00 CALL 0x0076f0a4
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x59536f: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x595372: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x595376: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x595378: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x595379: e8b2850200 CALL 0x005bd930
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x59537e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0059537f: { // 0x59537f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x595380: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x595381: 81c400020000 ADD ESP,0x200
    f.sp = integer::add(f.sp,0x00000200u,32,flags);
  }
  { // 0x595387: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00197880(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597880: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x597881: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597882: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597884: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x597885: 6805040000 PUSH 0x405
    f.push(m,0x00000405u);
  }
  { // 0x59788a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x59788c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x59788d: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597893: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x597895: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x597897: 7453 JZ 0x005978ec
    if(integer::condition("JZ",flags)) goto L005978ec;
  }
  { // 0x597899: 8b1da0547800 MOV EBX,dword ptr [0x007854a0]
    s.bx = m.r32((0x007854a0u));
  }
  { // 0x59789f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5978a1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5978a3: 6847010000 PUSH 0x147
    f.push(m,0x00000147u);
  }
  { // 0x5978a8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5978a9: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5978ab: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x5978ae: 743c JZ 0x005978ec
    if(integer::condition("JZ",flags)) goto L005978ec;
  }
  { // 0x5978b0: b101 MOV CL,0x1
    s.cx = with_al(s.cx, 0x00000001u);
  }
  { // 0x5978b2: a3e456a200 MOV [0x00a256e4],EAX
    m.w32((0x00a256e4u), s.ax);
  }
  { // 0x5978b7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5978b9: 884e09 MOV byte ptr [ESI + 0x9],CL
    m.w8((s.si+0x00000009u), (s.cx & 0xffu));
  }
  { // 0x5978bc: 884e08 MOV byte ptr [ESI + 0x8],CL
    m.w8((s.si+0x00000008u), (s.cx & 0xffu));
  }
  { // 0x5978bf: 7c1b JL 0x005978dc
    if(integer::condition("JL",flags)) goto L005978dc;
  }
  { // 0x5978c1: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  { // 0x5978c4: 7d16 JGE 0x005978dc
    if(integer::condition("JGE",flags)) goto L005978dc;
  }
  { // 0x5978c6: 8b048578117d00 MOV EAX,dword ptr [EAX*0x4 + 0x7d1178]
    s.ax = m.r32(((s.ax * 0x00000004u)+0x007d1178u));
  }
  { // 0x5978cd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5978ce: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5978d0: 6898040000 PUSH 0x498
    f.push(m,0x00000498u);
  }
  { // 0x5978d5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5978d6: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5978d8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5978d9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5978da: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5978db: c3 RET
    finish(m,s,f,0u); return;
  }
  L005978dc: { // 0x5978dc: a13c237900 MOV EAX,[0x0079233c]
    s.ax = m.r32((0x0079233cu));
  }
  { // 0x5978e1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5978e2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5978e4: 6898040000 PUSH 0x498
    f.push(m,0x00000498u);
  }
  { // 0x5978e9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5978ea: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L005978ec: { // 0x5978ec: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5978ed: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5978ee: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5978ef: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00197a80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597a80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597a81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597a83: 6869060000 PUSH 0x669
    f.push(m,0x00000669u);
  }
  { // 0x597a88: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597a8a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597a8b: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597a91: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597a93: 7419 JZ 0x00597aae
    if(integer::condition("JZ",flags)) goto L00597aae;
  }
  { // 0x597a95: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597a97: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597a99: 6800040000 PUSH 0x400
    f.push(m,0x00000400u);
  }
  { // 0x597a9e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597a9f: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x597aa5: a30056a200 MOV [0x00a25600],EAX
    m.w32((0x00a25600u), s.ax);
  }
  { // 0x597aaa: c6460901 MOV byte ptr [ESI + 0x9],0x1
    m.w8((s.si+0x00000009u), 0x00000001u);
  }
  L00597aae: { // 0x597aae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x597aaf: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00197ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597ab0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597ab1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597ab3: 6850050000 PUSH 0x550
    f.push(m,0x00000550u);
  }
  { // 0x597ab8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597aba: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597abb: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597ac1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597ac3: 7419 JZ 0x00597ade
    if(integer::condition("JZ",flags)) goto L00597ade;
  }
  { // 0x597ac5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597ac7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597ac9: 6800040000 PUSH 0x400
    f.push(m,0x00000400u);
  }
  { // 0x597ace: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597acf: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x597ad5: a378397c00 MOV [0x007c3978],EAX
    m.w32((0x007c3978u), s.ax);
  }
  { // 0x597ada: c6460901 MOV byte ptr [ESI + 0x9],0x1
    m.w8((s.si+0x00000009u), 0x00000001u);
  }
  L00597ade: { // 0x597ade: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x597adf: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00197ae0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597ae0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597ae1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597ae3: 6802040000 PUSH 0x402
    f.push(m,0x00000402u);
  }
  { // 0x597ae8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597aea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597aeb: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597af1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597af3: 7419 JZ 0x00597b0e
    if(integer::condition("JZ",flags)) goto L00597b0e;
  }
  { // 0x597af5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597af7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597af9: 6800040000 PUSH 0x400
    f.push(m,0x00000400u);
  }
  { // 0x597afe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597aff: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x597b05: a3ec55a200 MOV [0x00a255ec],EAX
    m.w32((0x00a255ecu), s.ax);
  }
  { // 0x597b0a: c6460901 MOV byte ptr [ESI + 0x9],0x1
    m.w8((s.si+0x00000009u), 0x00000001u);
  }
  L00597b0e: { // 0x597b0e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x597b0f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00197b10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597b10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597b11: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597b13: 6852050000 PUSH 0x552
    f.push(m,0x00000552u);
  }
  { // 0x597b18: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597b1a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597b1b: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597b21: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597b23: 7419 JZ 0x00597b3e
    if(integer::condition("JZ",flags)) goto L00597b3e;
  }
  { // 0x597b25: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597b27: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597b29: 6800040000 PUSH 0x400
    f.push(m,0x00000400u);
  }
  { // 0x597b2e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597b2f: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x597b35: a30456a200 MOV [0x00a25604],EAX
    m.w32((0x00a25604u), s.ax);
  }
  { // 0x597b3a: c6460901 MOV byte ptr [ESI + 0x9],0x1
    m.w8((s.si+0x00000009u), 0x00000001u);
  }
  L00597b3e: { // 0x597b3e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x597b3f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00197b40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597b40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597b41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597b43: 6829050000 PUSH 0x529
    f.push(m,0x00000529u);
  }
  { // 0x597b48: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597b4a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597b4b: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597b51: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597b53: 7421 JZ 0x00597b76
    if(integer::condition("JZ",flags)) goto L00597b76;
  }
  { // 0x597b55: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597b57: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597b59: 6800040000 PUSH 0x400
    f.push(m,0x00000400u);
  }
  { // 0x597b5e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597b5f: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x597b65: b906000000 MOV ECX,0x6
    s.cx = 0x00000006u;
  }
  { // 0x597b6a: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x597b6c: 890df855a200 MOV dword ptr [0x00a255f8],ECX
    m.w32((0x00a255f8u), s.cx);
  }
  { // 0x597b72: c6460901 MOV byte ptr [ESI + 0x9],0x1
    m.w8((s.si+0x00000009u), 0x00000001u);
  }
  L00597b76: { // 0x597b76: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x597b77: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00197b80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597b80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597b81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597b83: 6853050000 PUSH 0x553
    f.push(m,0x00000553u);
  }
  { // 0x597b88: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597b8a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597b8b: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597b91: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597b93: 7419 JZ 0x00597bae
    if(integer::condition("JZ",flags)) goto L00597bae;
  }
  { // 0x597b95: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597b97: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597b99: 6800040000 PUSH 0x400
    f.push(m,0x00000400u);
  }
  { // 0x597b9e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597b9f: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x597ba5: a30856a200 MOV [0x00a25608],EAX
    m.w32((0x00a25608u), s.ax);
  }
  { // 0x597baa: c6460901 MOV byte ptr [ESI + 0x9],0x1
    m.w8((s.si+0x00000009u), 0x00000001u);
  }
  L00597bae: { // 0x597bae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x597baf: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00197bb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597bb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597bb1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597bb3: 686b060000 PUSH 0x66b
    f.push(m,0x0000066bu);
  }
  { // 0x597bb8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597bba: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597bbb: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597bc1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597bc3: 7420 JZ 0x00597be5
    if(integer::condition("JZ",flags)) goto L00597be5;
  }
  { // 0x597bc5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597bc7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597bc9: 68f0000000 PUSH 0xf0
    f.push(m,0x000000f0u);
  }
  { // 0x597bce: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597bcf: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x597bd5: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x597bd8: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x597bdb: 880d7056a200 MOV byte ptr [0x00a25670],CL
    m.w8((0x00a25670u), (s.cx & 0xffu));
  }
  { // 0x597be1: c6460901 MOV byte ptr [ESI + 0x9],0x1
    m.w8((s.si+0x00000009u), 0x00000001u);
  }
  L00597be5: { // 0x597be5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x597be6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00197bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597bf0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597bf1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597bf3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x597bf4: 8b3d9c547800 MOV EDI,dword ptr [0x0078549c]
    s.di = m.r32((0x0078549cu));
  }
  { // 0x597bfa: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597bfc: 686a060000 PUSH 0x66a
    f.push(m,0x0000066au);
  }
  { // 0x597c01: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597c02: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597c04: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597c06: 744f JZ 0x00597c57
    if(integer::condition("JZ",flags)) goto L00597c57;
  }
  { // 0x597c08: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597c0a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597c0c: 68f0000000 PUSH 0xf0
    f.push(m,0x000000f0u);
  }
  { // 0x597c11: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597c12: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x597c18: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x597c1b: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x597c1e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x597c20: a2e855a200 MOV [0x00a255e8],AL
    m.w8((0x00a255e8u), (s.ax & 0xffu));
  }
  { // 0x597c25: 752c JNZ 0x00597c53
    if(integer::condition("JNZ",flags)) goto L00597c53;
  }
  { // 0x597c27: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x597c29: 684e050000 PUSH 0x54e
    f.push(m,0x0000054eu);
  }
  { // 0x597c2e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x597c2f: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x597c31: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597c33: 741e JZ 0x00597c53
    if(integer::condition("JZ",flags)) goto L00597c53;
  }
  { // 0x597c35: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597c37: c605f255a20000 MOV byte ptr [0x00a255f2],0x0
    m.w8((0x00a255f2u), 0x00000000u);
  }
  { // 0x597c3e: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x597c40: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597c42: 68f1000000 PUSH 0xf1
    f.push(m,0x000000f1u);
  }
  { // 0x597c47: 684e050000 PUSH 0x54e
    f.push(m,0x0000054eu);
  }
  { // 0x597c4c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x597c4d: ff1584547800 CALL dword ptr [0x00785484]
    const std::uint32_t call_target=m.r32((0x00785484u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00597c53: { // 0x597c53: c6460901 MOV byte ptr [ESI + 0x9],0x1
    m.w8((s.si+0x00000009u), 0x00000001u);
  }
  L00597c57: { // 0x597c57: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x597c58: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x597c59: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00197c60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597c60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597c61: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597c63: 684c050000 PUSH 0x54c
    f.push(m,0x0000054cu);
  }
  { // 0x597c68: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597c6a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597c6b: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597c71: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597c73: 7420 JZ 0x00597c95
    if(integer::condition("JZ",flags)) goto L00597c95;
  }
  { // 0x597c75: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597c77: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597c79: 68f0000000 PUSH 0xf0
    f.push(m,0x000000f0u);
  }
  { // 0x597c7e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597c7f: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x597c85: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x597c88: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x597c8b: 880df155a200 MOV byte ptr [0x00a255f1],CL
    m.w8((0x00a255f1u), (s.cx & 0xffu));
  }
  { // 0x597c91: c6460901 MOV byte ptr [ESI + 0x9],0x1
    m.w8((s.si+0x00000009u), 0x00000001u);
  }
  L00597c95: { // 0x597c95: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x597c96: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00197ca0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597ca0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597ca1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597ca3: 684d050000 PUSH 0x54d
    f.push(m,0x0000054du);
  }
  { // 0x597ca8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597caa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597cab: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597cb1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597cb3: 7420 JZ 0x00597cd5
    if(integer::condition("JZ",flags)) goto L00597cd5;
  }
  { // 0x597cb5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597cb7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597cb9: 68f0000000 PUSH 0xf0
    f.push(m,0x000000f0u);
  }
  { // 0x597cbe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597cbf: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x597cc5: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x597cc8: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x597ccb: 880d6f56a200 MOV byte ptr [0x00a2566f],CL
    m.w8((0x00a2566fu), (s.cx & 0xffu));
  }
  { // 0x597cd1: c6460901 MOV byte ptr [ESI + 0x9],0x1
    m.w8((s.si+0x00000009u), 0x00000001u);
  }
  L00597cd5: { // 0x597cd5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x597cd6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00197ce0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597ce0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597ce1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597ce3: 6824060000 PUSH 0x624
    f.push(m,0x00000624u);
  }
  { // 0x597ce8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597cea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597ceb: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597cf1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597cf3: 7420 JZ 0x00597d15
    if(integer::condition("JZ",flags)) goto L00597d15;
  }
  { // 0x597cf5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597cf7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597cf9: 68f0000000 PUSH 0xf0
    f.push(m,0x000000f0u);
  }
  { // 0x597cfe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597cff: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x597d05: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x597d08: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x597d0b: 880df055a200 MOV byte ptr [0x00a255f0],CL
    m.w8((0x00a255f0u), (s.cx & 0xffu));
  }
  { // 0x597d11: c6460901 MOV byte ptr [ESI + 0x9],0x1
    m.w8((s.si+0x00000009u), 0x00000001u);
  }
  L00597d15: { // 0x597d15: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x597d16: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00197d20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597d20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597d21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597d23: 6896050000 PUSH 0x596
    f.push(m,0x00000596u);
  }
  { // 0x597d28: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597d2a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597d2b: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597d31: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597d33: 7420 JZ 0x00597d55
    if(integer::condition("JZ",flags)) goto L00597d55;
  }
  { // 0x597d35: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597d37: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597d39: 68f0000000 PUSH 0xf0
    f.push(m,0x000000f0u);
  }
  { // 0x597d3e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597d3f: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x597d45: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x597d48: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x597d4b: 880d6d56a200 MOV byte ptr [0x00a2566d],CL
    m.w8((0x00a2566du), (s.cx & 0xffu));
  }
  { // 0x597d51: c6460901 MOV byte ptr [ESI + 0x9],0x1
    m.w8((s.si+0x00000009u), 0x00000001u);
  }
  L00597d55: { // 0x597d55: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x597d56: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00197d60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597d60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597d61: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597d63: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x597d64: 8b3d9c547800 MOV EDI,dword ptr [0x0078549c]
    s.di = m.r32((0x0078549cu));
  }
  { // 0x597d6a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597d6c: 684e050000 PUSH 0x54e
    f.push(m,0x0000054eu);
  }
  { // 0x597d71: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597d72: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597d74: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597d76: 7455 JZ 0x00597dcd
    if(integer::condition("JZ",flags)) goto L00597dcd;
  }
  { // 0x597d78: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597d7a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597d7c: 68f0000000 PUSH 0xf0
    f.push(m,0x000000f0u);
  }
  { // 0x597d81: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597d82: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x597d88: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x597d8b: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x597d8e: 880df255a200 MOV byte ptr [0x00a255f2],CL
    m.w8((0x00a255f2u), (s.cx & 0xffu));
  }
  { // 0x597d94: c6460901 MOV byte ptr [ESI + 0x9],0x1
    m.w8((s.si+0x00000009u), 0x00000001u);
  }
  { // 0x597d98: a0f255a200 MOV AL,[0x00a255f2]
    s.ax = with_al(s.ax, m.r8((0x00a255f2u)));
  }
  { // 0x597d9d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x597d9f: 742c JZ 0x00597dcd
    if(integer::condition("JZ",flags)) goto L00597dcd;
  }
  { // 0x597da1: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x597da3: 686a060000 PUSH 0x66a
    f.push(m,0x0000066au);
  }
  { // 0x597da8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x597da9: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x597dab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597dad: 741e JZ 0x00597dcd
    if(integer::condition("JZ",flags)) goto L00597dcd;
  }
  { // 0x597daf: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597db1: c605e855a20001 MOV byte ptr [0x00a255e8],0x1
    m.w8((0x00a255e8u), 0x00000001u);
  }
  { // 0x597db8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597dba: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x597dbc: 68f1000000 PUSH 0xf1
    f.push(m,0x000000f1u);
  }
  { // 0x597dc1: 686a060000 PUSH 0x66a
    f.push(m,0x0000066au);
  }
  { // 0x597dc6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597dc7: ff1584547800 CALL dword ptr [0x00785484]
    const std::uint32_t call_target=m.r32((0x00785484u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00597dcd: { // 0x597dcd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x597dce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x597dcf: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00197dd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597dd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597dd1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597dd3: 689a060000 PUSH 0x69a
    f.push(m,0x0000069au);
  }
  { // 0x597dd8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597dda: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597ddb: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597de1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597de3: 7420 JZ 0x00597e05
    if(integer::condition("JZ",flags)) goto L00597e05;
  }
  { // 0x597de5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597de7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597de9: 68f0000000 PUSH 0xf0
    f.push(m,0x000000f0u);
  }
  { // 0x597dee: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597def: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x597df5: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x597df8: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x597dfb: 880df355a200 MOV byte ptr [0x00a255f3],CL
    m.w8((0x00a255f3u), (s.cx & 0xffu));
  }
  { // 0x597e01: c6460901 MOV byte ptr [ESI + 0x9],0x1
    m.w8((s.si+0x00000009u), 0x00000001u);
  }
  L00597e05: { // 0x597e05: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x597e06: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00197e10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597e10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597e11: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597e13: 689d060000 PUSH 0x69d
    f.push(m,0x0000069du);
  }
  { // 0x597e18: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597e1a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597e1b: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597e21: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597e23: 7420 JZ 0x00597e45
    if(integer::condition("JZ",flags)) goto L00597e45;
  }
  { // 0x597e25: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597e27: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597e29: 68f0000000 PUSH 0xf0
    f.push(m,0x000000f0u);
  }
  { // 0x597e2e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597e2f: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x597e35: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x597e38: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x597e3b: 880df255a200 MOV byte ptr [0x00a255f2],CL
    m.w8((0x00a255f2u), (s.cx & 0xffu));
  }
  { // 0x597e41: c6460901 MOV byte ptr [ESI + 0x9],0x1
    m.w8((s.si+0x00000009u), 0x00000001u);
  }
  L00597e45: { // 0x597e45: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x597e46: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00197e50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x597e50: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x597e51: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x597e53: 6851050000 PUSH 0x551
    f.push(m,0x00000551u);
  }
  { // 0x597e58: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x597e5a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597e5b: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x597e61: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x597e63: 7420 JZ 0x00597e85
    if(integer::condition("JZ",flags)) goto L00597e85;
  }
  { // 0x597e65: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597e67: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x597e69: 68f0000000 PUSH 0xf0
    f.push(m,0x000000f0u);
  }
  { // 0x597e6e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x597e6f: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x597e75: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x597e78: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x597e7b: 880dfc55a200 MOV byte ptr [0x00a255fc],CL
    m.w8((0x00a255fcu), (s.cx & 0xffu));
  }
  { // 0x597e81: c6460901 MOV byte ptr [ESI + 0x9],0x1
    m.w8((s.si+0x00000009u), 0x00000001u);
  }
  L00597e85: { // 0x597e85: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x597e86: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0019a7b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59a7b0: a0208ba500 MOV AL,[0x00a58b20]
    s.ax = with_al(s.ax, m.r8((0x00a58b20u)));
  }
  { // 0x59a7b5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x59a7b7: 7430 JZ 0x0059a7e9
    if(integer::condition("JZ",flags)) goto L0059a7e9;
  }
  { // 0x59a7b9: a1288ba500 MOV EAX,[0x00a58b28]
    s.ax = m.r32((0x00a58b28u));
  }
  { // 0x59a7be: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x59a7c0: 7505 JNZ 0x0059a7c7
    if(integer::condition("JNZ",flags)) goto L0059a7c7;
  }
  { // 0x59a7c2: e859010000 CALL 0x0059a920
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0059a7c7: { // 0x59a7c7: a1288ba500 MOV EAX,[0x00a58b28]
    s.ax = m.r32((0x00a58b28u));
  }
  { // 0x59a7cc: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x59a7ce: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x59a7cf: c605228ba50001 MOV byte ptr [0x00a58b22],0x1
    m.w8((0x00a58b22u), 0x00000001u);
  }
  { // 0x59a7d6: ff1598547800 CALL dword ptr [0x00785498]
    const std::uint32_t call_target=m.r32((0x00785498u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x59a7dc: 8b0d1c8ba500 MOV ECX,dword ptr [0x00a58b1c]
    s.cx = m.r32((0x00a58b1cu));
  }
  { // 0x59a7e2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x59a7e3: ff158c537800 CALL dword ptr [0x0078538c]
    const std::uint32_t call_target=m.r32((0x0078538cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L0059a7e9: { // 0x59a7e9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001aab70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5aab70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5aab71: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5aab73: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5aab74: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  { // 0x5aab77: c706d81d7900 MOV dword ptr [ESI],0x791dd8
    m.w32((s.si), 0x00791dd8u);
  }
  { // 0x5aab7d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5aab7f: 7406 JZ 0x005aab87
    if(integer::condition("JZ",flags)) goto L005aab87;
  }
  { // 0x5aab81: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5aab83: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5aab85: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L005aab87: { // 0x5aab87: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  { // 0x5aab8a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5aab8c: 741c JZ 0x005aabaa
    if(integer::condition("JZ",flags)) goto L005aabaa;
  }
  { // 0x5aab8e: e8cd36ffff CALL 0x0059e260
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5aab93: 8b7e1c MOV EDI,dword ptr [ESI + 0x1c]
    s.di = m.r32((s.si+0x0000001cu));
  }
  { // 0x5aab96: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x5aab98: 7410 JZ 0x005aabaa
    if(integer::condition("JZ",flags)) goto L005aabaa;
  }
  { // 0x5aab9a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5aab9c: e8af39ffff CALL 0x0059e550
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5aaba1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5aaba2: e8d42a1c00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5aaba7: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005aabaa: { // 0x5aabaa: c706101d7900 MOV dword ptr [ESI],0x791d10
    m.w32((s.si), 0x00791d10u);
  }
  { // 0x5aabb0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5aabb1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5aabb2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001ac9d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5ac9d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ac9d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5ac9d3: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  { // 0x5ac9d6: c706d81d7900 MOV dword ptr [ESI],0x791dd8
    m.w32((s.si), 0x00791dd8u);
  }
  { // 0x5ac9dc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5ac9de: 7406 JZ 0x005ac9e6
    if(integer::condition("JZ",flags)) goto L005ac9e6;
  }
  { // 0x5ac9e0: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5ac9e2: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5ac9e4: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L005ac9e6: { // 0x5ac9e6: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  { // 0x5ac9e9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5ac9ea: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5ac9ec: 741c JZ 0x005aca0a
    if(integer::condition("JZ",flags)) goto L005aca0a;
  }
  { // 0x5ac9ee: e86d18ffff CALL 0x0059e260
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5ac9f3: 8b7e1c MOV EDI,dword ptr [ESI + 0x1c]
    s.di = m.r32((s.si+0x0000001cu));
  }
  { // 0x5ac9f6: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x5ac9f8: 7410 JZ 0x005aca0a
    if(integer::condition("JZ",flags)) goto L005aca0a;
  }
  { // 0x5ac9fa: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5ac9fc: e84f1bffff CALL 0x0059e550
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5aca01: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5aca02: e8740c1c00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5aca07: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005aca0a: { // 0x5aca0a: 8a44240c MOV AL,byte ptr [ESP + 0xc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000cu)));
  }
  { // 0x5aca0e: c706101d7900 MOV dword ptr [ESI],0x791d10
    m.w32((s.si), 0x00791d10u);
  }
  { // 0x5aca14: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x5aca16: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5aca17: 7409 JZ 0x005aca22
    if(integer::condition("JZ",flags)) goto L005aca22;
  }
  { // 0x5aca19: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5aca1a: e85c0c1c00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x5aca1f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005aca22: { // 0x5aca22: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5aca24: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5aca25: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001aca90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5aca90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5aca91: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5aca93: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x5aca96: c706541e7900 MOV dword ptr [ESI],0x791e54
    m.w32((s.si), 0x00791e54u);
  }
  { // 0x5aca9c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5aca9e: 7406 JZ 0x005acaa6
    if(integer::condition("JZ",flags)) goto L005acaa6;
  }
  { // 0x5acaa0: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5acaa2: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5acaa4: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L005acaa6: { // 0x5acaa6: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x5acaaa: c706101d7900 MOV dword ptr [ESI],0x791d10
    m.w32((s.si), 0x00791d10u);
  }
  { // 0x5acab0: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x5acab2: 7409 JZ 0x005acabd
    if(integer::condition("JZ",flags)) goto L005acabd;
  }
  { // 0x5acab4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5acab5: e8c10b1c00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5acaba: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005acabd: { // 0x5acabd: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5acabf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5acac0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001af940(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5af940: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x5af944: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5af945: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5af947: 7452 JZ 0x005af99b
    if(integer::condition("JZ",flags)) goto L005af99b;
  }
  { // 0x5af949: 8b4128 MOV EAX,dword ptr [ECX + 0x28]
    s.ax = m.r32((s.cx+0x00000028u));
  }
  { // 0x5af94c: 8d7118 LEA ESI,[ECX + 0x18]
    s.si = (s.cx+0x00000018u);
  }
  { // 0x5af94f: 8b4920 MOV ECX,dword ptr [ECX + 0x20]
    s.cx = m.r32((s.cx+0x00000020u));
  }
  { // 0x5af952: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5af954: 7c22 JL 0x005af978
    if(integer::condition("JL",flags)) goto L005af978;
  }
  { // 0x5af956: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x5af959: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5af95b: 7504 JNZ 0x005af961
    if(integer::condition("JNZ",flags)) goto L005af961;
  }
  { // 0x5af95d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5af95f: 753a JNZ 0x005af99b
    if(integer::condition("JNZ",flags)) goto L005af99b;
  }
  L005af961: { // 0x5af961: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x5af964: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5af966: 7e33 JLE 0x005af99b
    if(integer::condition("JLE",flags)) goto L005af99b;
  }
  { // 0x5af968: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5af96a: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x5af96c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5af96e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5af96f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5af971: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5af974: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5af976: 7423 JZ 0x005af99b
    if(integer::condition("JZ",flags)) goto L005af99b;
  }
  L005af978: { // 0x5af978: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x5af97b: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x5af97e: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  { // 0x5af981: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x5af984: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x5af988: 890c82 MOV dword ptr [EDX + EAX*0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.cx);
  }
  { // 0x5af98b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5af98d: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  { // 0x5af991: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5af993: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5af994: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5af997: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5af998: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L005af99b: { // 0x5af99b: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x5af99e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5af99f: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001afaa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5afaa0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x5afaa4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5afaa5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5afaa7: 7455 JZ 0x005afafe
    if(integer::condition("JZ",flags)) goto L005afafe;
  }
  { // 0x5afaa9: 8b4118 MOV EAX,dword ptr [ECX + 0x18]
    s.ax = m.r32((s.cx+0x00000018u));
  }
  { // 0x5afaac: 8d7118 LEA ESI,[ECX + 0x18]
    s.si = (s.cx+0x00000018u);
  }
  { // 0x5afaaf: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x5afab3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5afab4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5afab6: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5afab9: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x5afabc: 7440 JZ 0x005afafe
    if(integer::condition("JZ",flags)) goto L005afafe;
  }
  { // 0x5afabe: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5afac0: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  { // 0x5afac4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5afac5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5afac7: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5afaca: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x5afacd: 7421 JZ 0x005afaf0
    if(integer::condition("JZ",flags)) goto L005afaf0;
  }
  { // 0x5afacf: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x5afad2: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5afad4: 7d1a JGE 0x005afaf0
    if(integer::condition("JGE",flags)) goto L005afaf0;
  }
  { // 0x5afad6: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x5afad7: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5afad9: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x5afadc: 7d12 JGE 0x005afaf0
    if(integer::condition("JGE",flags)) goto L005afaf0;
  }
  L005afade: { // 0x5afade: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x5afae1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x5afae2: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x5afae5: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  { // 0x5afae9: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x5afaec: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5afaee: 7cee JL 0x005afade
    if(integer::condition("JL",flags)) goto L005afade;
  }
  L005afaf0: { // 0x5afaf0: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x5afaf4: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5afaf6: 7406 JZ 0x005afafe
    if(integer::condition("JZ",flags)) goto L005afafe;
  }
  { // 0x5afaf8: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5afafa: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5afafc: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L005afafe: { // 0x5afafe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5afaff: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001b02f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b02f0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5b02f1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b02f2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5b02f3: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x5b02f7: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x5b02f9: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x5b02fb: 746b JZ 0x005b0368
    if(integer::condition("JZ",flags)) goto L005b0368;
  }
  { // 0x5b02fd: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  { // 0x5b0301: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5b0303: 7463 JZ 0x005b0368
    if(integer::condition("JZ",flags)) goto L005b0368;
  }
  { // 0x5b0305: 6a0c PUSH 0xc
    f.push(m,0x0000000cu);
  }
  { // 0x5b0307: e84bd61b00 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5b030c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5b030f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b0311: 740d JZ 0x005b0320
    if(integer::condition("JZ",flags)) goto L005b0320;
  }
  { // 0x5b0313: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b0314: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5b0315: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5b0317: e8a4310000 CALL 0x005b34c0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5b031c: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5b031e: eb02 JMP 0x005b0322
    goto L005b0322;
  }
  L005b0320: { // 0x5b0320: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L005b0322: { // 0x5b0322: 8b4b38 MOV ECX,dword ptr [EBX + 0x38]
    s.cx = m.r32((s.bx+0x00000038u));
  }
  { // 0x5b0325: 8b4340 MOV EAX,dword ptr [EBX + 0x40]
    s.ax = m.r32((s.bx+0x00000040u));
  }
  { // 0x5b0328: 8d7330 LEA ESI,[EBX + 0x30]
    s.si = (s.bx+0x00000030u);
  }
  { // 0x5b032b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5b032d: 7c22 JL 0x005b0351
    if(integer::condition("JL",flags)) goto L005b0351;
  }
  { // 0x5b032f: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x5b0332: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5b0334: 7504 JNZ 0x005b033a
    if(integer::condition("JNZ",flags)) goto L005b033a;
  }
  { // 0x5b0336: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5b0338: 752e JNZ 0x005b0368
    if(integer::condition("JNZ",flags)) goto L005b0368;
  }
  L005b033a: { // 0x5b033a: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x5b033d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b033f: 7e27 JLE 0x005b0368
    if(integer::condition("JLE",flags)) goto L005b0368;
  }
  { // 0x5b0341: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5b0343: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x5b0345: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5b0347: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5b0348: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5b034a: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5b034d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5b034f: 7417 JZ 0x005b0368
    if(integer::condition("JZ",flags)) goto L005b0368;
  }
  L005b0351: { // 0x5b0351: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x5b0354: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x5b0357: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  { // 0x5b035a: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x5b035d: 893c82 MOV dword ptr [EDX + EAX*0x4],EDI
    m.w32((s.dx+(s.ax * 0x00000004u)), s.di);
  }
  { // 0x5b0360: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5b0361: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b0362: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x5b0364: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5b0365: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L005b0368: { // 0x5b0368: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5b0369: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b036a: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x5b036c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5b036d: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_001b0b50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b0b50: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b0b51: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5b0b53: c7068c207900 MOV dword ptr [ESI],0x79208c
    m.w32((s.si), 0x0079208cu);
  }
  { // 0x5b0b59: a17094a500 MOV EAX,[0x00a59470]
    s.ax = m.r32((0x00a59470u));
  }
  { // 0x5b0b5e: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x5b0b5f: a37094a500 MOV [0x00a59470],EAX
    m.w32((0x00a59470u), s.ax);
  }
  { // 0x5b0b64: 7545 JNZ 0x005b0bab
    if(integer::condition("JNZ",flags)) goto L005b0bab;
  }
  { // 0x5b0b66: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5b0b67: b87894a500 MOV EAX,0xa59478
    s.ax = 0x00a59478u;
  }
  { // 0x5b0b6c: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005b0b6e: { // 0x5b0b6e: 3918 CMP dword ptr [EAX],EBX
    (void)integer::sub(m.r32((s.ax)),s.bx,32,flags);
  }
  { // 0x5b0b70: 7405 JZ 0x005b0b77
    if(integer::condition("JZ",flags)) goto L005b0b77;
  }
  { // 0x5b0b72: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  { // 0x5b0b74: 885804 MOV byte ptr [EAX + 0x4],BL
    m.w8((s.ax+0x00000004u), (s.bx & 0xffu));
  }
  L005b0b77: { // 0x5b0b77: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  { // 0x5b0b7a: 3d9094a500 CMP EAX,0xa59490
    (void)integer::sub(s.ax,0x00a59490u,32,flags);
  }
  { // 0x5b0b7f: 7ced JL 0x005b0b6e
    if(integer::condition("JL",flags)) goto L005b0b6e;
  }
  { // 0x5b0b81: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  { // 0x5b0b84: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  { // 0x5b0b86: 7406 JZ 0x005b0b8e
    if(integer::condition("JZ",flags)) goto L005b0b8e;
  }
  { // 0x5b0b88: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5b0b8a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5b0b8c: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L005b0b8e: { // 0x5b0b8e: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x5b0b91: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x5b0b93: 740f JZ 0x005b0ba4
    if(integer::condition("JZ",flags)) goto L005b0ba4;
  }
  { // 0x5b0b95: 807e1c01 CMP byte ptr [ESI + 0x1c],0x1
    (void)integer::sub(m.r8((s.si+0x0000001cu)),0x00000001u,8,flags);
  }
  { // 0x5b0b99: 7509 JNZ 0x005b0ba4
    if(integer::condition("JNZ",flags)) goto L005b0ba4;
  }
  { // 0x5b0b9b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5b0b9c: e8daca1b00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5b0ba1: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005b0ba4: { // 0x5b0ba4: 895e14 MOV dword ptr [ESI + 0x14],EBX
    m.w32((s.si+0x00000014u), s.bx);
  }
  { // 0x5b0ba7: 885e1c MOV byte ptr [ESI + 0x1c],BL
    m.w8((s.si+0x0000001cu), (s.bx & 0xffu));
  }
  { // 0x5b0baa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005b0bab: { // 0x5b0bab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b0bac: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001b3f30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b3f30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b3f31: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5b3f32: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x5b3f36: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5b3f38: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5b3f3a: e831440b00 CALL 0x00668370
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5b3f3f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5b3f41: 740c JZ 0x005b3f4f
    if(integer::condition("JZ",flags)) goto L005b3f4f;
  }
  { // 0x5b3f43: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5b3f45: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5b3f47: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5b3f4a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5b3f4b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b3f4c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L005b3f4f: { // 0x5b3f4f: 83c630 ADD ESI,0x30
    s.si = integer::add(s.si,0x00000030u,32,flags);
  }
  { // 0x5b3f52: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5b3f54: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b3f55: e836440b00 CALL 0x00668390
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5b3f5a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5b3f5b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b3f5c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001b6470(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b6470: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5b6471: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5b6472: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b6473: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5b6475: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5b6476: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x5b6479: e8f2581a00 CALL 0x0075bd70
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5b647e: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5b6482: 8b2da0547800 MOV EBP,dword ptr [0x007854a0]
    s.bp = m.r32((0x007854a0u));
  }
  { // 0x5b6488: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5b6489: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5b648b: 6843010000 PUSH 0x143
    f.push(m,0x00000143u);
  }
  { // 0x5b6490: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5b6491: ffd5 CALL EBP
    const std::uint32_t call_target=s.bp;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5b6493: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5b6495: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x5b6498: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5b6499: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5b649a: 6851010000 PUSH 0x151
    f.push(m,0x00000151u);
  }
  { // 0x5b649f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5b64a0: ffd5 CALL EBP
    const std::uint32_t call_target=s.bp;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5b64a2: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x5b64a4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5b64a5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b64a6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5b64a7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5b64a8: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001b76a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b76a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b76a1: e81ab10000 CALL 0x005c27c0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5b76a6: 8b0d901f8200 MOV ECX,dword ptr [0x00821f90]
    s.cx = m.r32((0x00821f90u));
  }
  { // 0x5b76ac: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x5b76ae: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  { // 0x5b76b0: 6689353e79a200 MOV word ptr [0x00a2793e],SI
    m.w16((0x00a2793eu), (s.si & 0xffffu));
  }
  { // 0x5b76b7: 7406 JZ 0x005b76bf
    if(integer::condition("JZ",flags)) goto L005b76bf;
  }
  { // 0x5b76b9: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5b76bb: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5b76bd: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L005b76bf: { // 0x5b76bf: 8935901f8200 MOV dword ptr [0x00821f90],ESI
    m.w32((0x00821f90u), s.si);
  }
  { // 0x5b76c5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b76c6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001bd470(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5bd470: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5bd471: e85ad21600 CALL 0x0072a6d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5bd476: 689f050000 PUSH 0x59f
    f.push(m,0x0000059fu);
  }
  { // 0x5bd47b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5bd47c: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5bd482: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x5bd484: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5bd486: e895a9ffff CALL 0x005b7e20
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5bd48b: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x5bd48e: 7431 JZ 0x005bd4c1
    if(integer::condition("JZ",flags)) goto L005bd4c1;
  }
  { // 0x5bd490: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5bd492: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5bd494: 68dc040000 PUSH 0x4dc
    f.push(m,0x000004dcu);
  }
  { // 0x5bd499: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5bd49a: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5bd4a0: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x5bd4a2: b960117d00 MOV ECX,0x7d1160
    s.cx = 0x007d1160u;
  }
  { // 0x5bd4a7: 682f120000 PUSH 0x122f
    f.push(m,0x0000122fu);
  }
  { // 0x5bd4ac: 68dc0d7d00 PUSH 0x7d0ddc
    f.push(m,0x007d0ddcu);
  }
  { // 0x5bd4b1: e8aa161300 CALL 0x006eeb60
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x5bd4b6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5bd4b7: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x5bd4b9: e852030000 CALL 0x005bd810
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x5bd4be: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005bd4c1: { // 0x5bd4c1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5bd4c2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001bd4d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5bd4d0: e8fbd11600 CALL 0x0072a6d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5bd4d5: 689f050000 PUSH 0x59f
    f.push(m,0x0000059fu);
  }
  { // 0x5bd4da: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5bd4db: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5bd4e1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5bd4e3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5bd4e5: 68dc040000 PUSH 0x4dc
    f.push(m,0x000004dcu);
  }
  { // 0x5bd4ea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5bd4eb: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5bd4f1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001bdf90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5bdf90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5bdf91: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5bdf92: 68ec060000 PUSH 0x6ec
    f.push(m,0x000006ecu);
  }
  { // 0x5bdf97: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x5bdf99: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5bdf9a: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5bdfa0: 8d4e20 LEA ECX,[ESI + 0x20]
    s.cx = (s.si+0x00000020u);
  }
  { // 0x5bdfa3: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5bdfa5: e8c6dd1900 CALL 0x0075bd70
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5bdfaa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5bdfab: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5bdfad: 68b2040000 PUSH 0x4b2
    f.push(m,0x000004b2u);
  }
  { // 0x5bdfb2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5bdfb3: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5bdfb9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5bdfba: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5bdfbb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001bdff0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5bdff0: 68a8050000 PUSH 0x5a8
    f.push(m,0x000005a8u);
  }
  { // 0x5bdff5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5bdff6: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5bdffc: 687256a200 PUSH 0xa25672
    f.push(m,0x00a25672u);
  }
  { // 0x5be001: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5be003: 68b2040000 PUSH 0x4b2
    f.push(m,0x000004b2u);
  }
  { // 0x5be008: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5be009: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5be00f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001be030(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5be030: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5be031: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5be032: e8a9c61600 CALL 0x0072a6e0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5be037: 83f86b CMP EAX,0x6b
    (void)integer::sub(s.ax,0x0000006bu,32,flags);
  }
  { // 0x5be03a: 7541 JNZ 0x005be07d
    if(integer::condition("JNZ",flags)) goto L005be07d;
  }
  { // 0x5be03c: e88fc61600 CALL 0x0072a6d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5be041: 8b3d84547800 MOV EDI,dword ptr [0x00785484]
    s.di = m.r32((0x00785484u));
  }
  { // 0x5be047: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5be049: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5be04b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5be04d: 6888010000 PUSH 0x188
    f.push(m,0x00000188u);
  }
  { // 0x5be052: 68eb060000 PUSH 0x6eb
    f.push(m,0x000006ebu);
  }
  { // 0x5be057: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5be058: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5be05a: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x5be05d: 742d JZ 0x005be08c
    if(integer::condition("JZ",flags)) goto L005be08c;
  }
  { // 0x5be05f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5be061: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5be062: 6899010000 PUSH 0x199
    f.push(m,0x00000199u);
  }
  { // 0x5be067: 68eb060000 PUSH 0x6eb
    f.push(m,0x000006ebu);
  }
  { // 0x5be06c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5be06d: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5be06f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5be071: 7419 JZ 0x005be08c
    if(integer::condition("JZ",flags)) goto L005be08c;
  }
  { // 0x5be073: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x5be075: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5be077: ff527c CALL dword ptr [EDX + 0x7c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000007cu));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x5be07a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5be07b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5be07c: c3 RET
    finish(m,s,f,0u); return;
  }
  L005be07d: { // 0x5be07d: 8b0dcc55a200 MOV ECX,dword ptr [0x00a255cc]
    s.cx = m.r32((0x00a255ccu));
  }
  { // 0x5be083: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5be085: 7405 JZ 0x005be08c
    if(integer::condition("JZ",flags)) goto L005be08c;
  }
  { // 0x5be087: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5be089: ff507c CALL dword ptr [EAX + 0x7c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000007cu));
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  L005be08c: { // 0x5be08c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5be08d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5be08e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c0630(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c0630: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  { // 0x5c0633: 7506 JNZ 0x005c063b
    if(integer::condition("JNZ",flags)) goto L005c063b;
  }
  { // 0x5c0635: b808000000 MOV EAX,0x8
    s.ax = 0x00000008u;
  }
  { // 0x5c063a: c3 RET
    finish(m,s,f,0u); return;
  }
  L005c063b: { // 0x5c063b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c063c: e84f000000 CALL 0x005c0690
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5c0641: 8b0dcc55a200 MOV ECX,dword ptr [0x00a255cc]
    s.cx = m.r32((0x00a255ccu));
  }
  { // 0x5c0647: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5c0649: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5c064b: 7413 JZ 0x005c0660
    if(integer::condition("JZ",flags)) goto L005c0660;
  }
  { // 0x5c064d: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5c064f: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5c0655: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x5c0658: 7406 JZ 0x005c0660
    if(integer::condition("JZ",flags)) goto L005c0660;
  }
  { // 0x5c065a: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x5c065c: 7d02 JGE 0x005c0660
    if(integer::condition("JGE",flags)) goto L005c0660;
  }
  { // 0x5c065e: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005c0660: { // 0x5c0660: 833dc855a20004 CMP dword ptr [0x00a255c8],0x4
    (void)integer::sub(m.r32((0x00a255c8u)),0x00000004u,32,flags);
  }
  { // 0x5c0667: 751e JNZ 0x005c0687
    if(integer::condition("JNZ",flags)) goto L005c0687;
  }
  { // 0x5c0669: e802081700 CALL 0x00730e70
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5c066e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5c0670: 7407 JZ 0x005c0679
    if(integer::condition("JZ",flags)) goto L005c0679;
  }
  { // 0x5c0672: 83e6fe AND ESI,0xfffffffe
    s.si = integer::logical((s.si)&(0xfffffffeu),32,flags);
  }
  { // 0x5c0675: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5c0677: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c0678: c3 RET
    finish(m,s,f,0u); return;
  }
  L005c0679: { // 0x5c0679: e8c2071700 CALL 0x00730e40
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5c067e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5c0680: 7405 JZ 0x005c0687
    if(integer::condition("JZ",flags)) goto L005c0687;
  }
  { // 0x5c0682: be02000000 MOV ESI,0x2
    s.si = 0x00000002u;
  }
  L005c0687: { // 0x5c0687: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5c0689: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c068a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c09f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c09f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c09f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5c09f3: b201 MOV DL,0x1
    s.dx = with_al(s.dx, 0x00000001u);
  }
  { // 0x5c09f5: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x5c09f7: e85445f5ff CALL 0x00514f50
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5c09fc: 8b0df8dbb000 MOV ECX,dword ptr [0x00b0dbf8]
    s.cx = m.r32((0x00b0dbf8u));
  }
  { // 0x5c0a02: ba6b000000 MOV EDX,0x6b
    s.dx = 0x0000006bu;
  }
  { // 0x5c0a07: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5c0a09: 68700a5c00 PUSH 0x5c0a70
    f.push(m,0x005c0a70u);
  }
  { // 0x5c0a0e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c0a0f: e8ac981600 CALL 0x0072a2c0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5c0a14: ba6b000000 MOV EDX,0x6b
    s.dx = 0x0000006bu;
  }
  { // 0x5c0a19: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5c0a1b: a360a4a500 MOV [0x00a5a460],EAX
    m.w32((0x00a5a460u), s.ax);
  }
  { // 0x5c0a20: e87b6a0300 CALL 0x005f74a0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5c0a25: a160a4a500 MOV EAX,[0x00a5a460]
    s.ax = m.r32((0x00a5a460u));
  }
  { // 0x5c0a2a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5c0a2c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5c0a2e: 68a9040000 PUSH 0x4a9
    f.push(m,0x000004a9u);
  }
  { // 0x5c0a33: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c0a34: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5c0a3a: 8b0d60a4a500 MOV ECX,dword ptr [0x00a5a460]
    s.cx = m.r32((0x00a5a460u));
  }
  { // 0x5c0a40: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5c0a42: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5c0a43: ff1598547800 CALL dword ptr [0x00785498]
    const std::uint32_t call_target=m.r32((0x00785498u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x5c0a49: 8b0d60a4a500 MOV ECX,dword ptr [0x00a5a460]
    s.cx = m.r32((0x00a5a460u));
  }
  { // 0x5c0a4f: ba50085c00 MOV EDX,0x5c0850
    s.dx = 0x005c0850u;
  }
  { // 0x5c0a54: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5c0a56: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5c0a58: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5c0a5a: e8419b1600 CALL 0x0072a5a0
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x5c0a5f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c0a60: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c32d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c32d0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x5c32d4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5c32d5: 8b1d84547800 MOV EBX,dword ptr [0x00785484]
    s.bx = m.r32((0x00785484u));
  }
  { // 0x5c32db: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c32dc: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c32dd: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x5c32e0: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x5c32e2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x5c32e4: 750d JNZ 0x005c32f3
    if(integer::condition("JNZ",flags)) goto L005c32f3;
  }
  { // 0x5c32e6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5c32e8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5c32ea: 6847010000 PUSH 0x147
    f.push(m,0x00000147u);
  }
  { // 0x5c32ef: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c32f0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c32f1: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L005c32f3: { // 0x5c32f3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5c32f5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c32f6: 6850010000 PUSH 0x150
    f.push(m,0x00000150u);
  }
  { // 0x5c32fb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c32fc: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c32fd: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5c32ff: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c3300: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c3301: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5c3302: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001c3430(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c3430: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5c3431: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5c3432: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5c3433: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c3434: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c3435: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x5c3437: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x5c3439: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x5c343b: e830d9f0ff CALL 0x004d0d70
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5c3440: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x5c3442: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5c3444: e8e7e0f0ff CALL 0x004d1530
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5c3449: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  { // 0x5c344d: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  { // 0x5c344f: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x5c3451: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  { // 0x5c3455: 7516 JNZ 0x005c346d
    if(integer::condition("JNZ",flags)) goto L005c346d;
  }
  { // 0x5c3457: 6afe PUSH -0x2
    f.push(m,0xfffffffeu);
  }
  { // 0x5c3459: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x5c345b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5c345d: e8aedef0ff CALL 0x004d1310
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5c3462: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  { // 0x5c3464: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5c3466: 6afe PUSH -0x2
    f.push(m,0xfffffffeu);
  }
  { // 0x5c3468: e843e7f0ff CALL 0x004d1bb0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L005c346d: { // 0x5c346d: 8b2d9c547800 MOV EBP,dword ptr [0x0078549c]
    s.bp = m.r32((0x0078549cu));
  }
  { // 0x5c3473: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c3474: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c3475: ffd5 CALL EBP
    const std::uint32_t call_target=s.bp;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x5c3477: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  { // 0x5c3479: 8b1d90547800 MOV EBX,dword ptr [0x00785490]
    s.bx = m.r32((0x00785490u));
  }
  { // 0x5c347f: 81e6ff000000 AND ESI,0xff
    s.si = integer::logical((s.si)&(0x000000ffu),32,flags);
  }
  { // 0x5c3485: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c3486: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c3487: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x5c3489: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x5c348d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c348e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c348f: ffd5 CALL EBP
    const std::uint32_t call_target=s.bp;
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  { // 0x5c3491: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c3492: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c3493: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,7u,call_target); flags=0x202u;
  }
  { // 0x5c3495: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c3496: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c3497: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5c3498: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5c3499: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x5c349a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001c3c90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c3c90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c3c91: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c3c92: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x5c3c94: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  { // 0x5c3c99: 8b0dcc55a200 MOV ECX,dword ptr [0x00a255cc]
    s.cx = m.r32((0x00a255ccu));
  }
  { // 0x5c3c9f: 8b34bdc47da200 MOV ESI,dword ptr [EDI*0x4 + 0xa27dc4]
    s.si = m.r32(((s.di * 0x00000004u)+0x00a27dc4u));
  }
  { // 0x5c3ca6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5c3ca8: 7415 JZ 0x005c3cbf
    if(integer::condition("JZ",flags)) goto L005c3cbf;
  }
  { // 0x5c3caa: 8b15c855a200 MOV EDX,dword ptr [0x00a255c8]
    s.dx = m.r32((0x00a255c8u));
  }
  { // 0x5c3cb0: 83fa03 CMP EDX,0x3
    (void)integer::sub(s.dx,0x00000003u,32,flags);
  }
  { // 0x5c3cb3: 7405 JZ 0x005c3cba
    if(integer::condition("JZ",flags)) goto L005c3cba;
  }
  { // 0x5c3cb5: 83fa04 CMP EDX,0x4
    (void)integer::sub(s.dx,0x00000004u,32,flags);
  }
  { // 0x5c3cb8: 7505 JNZ 0x005c3cbf
    if(integer::condition("JNZ",flags)) goto L005c3cbf;
  }
  L005c3cba: { // 0x5c3cba: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5c3cbc: ff5028 CALL dword ptr [EAX + 0x28]
    const std::uint32_t call_target=m.r32((s.ax+0x00000028u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L005c3cbf: { // 0x5c3cbf: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5c3cc1: 7422 JZ 0x005c3ce5
    if(integer::condition("JZ",flags)) goto L005c3ce5;
  }
  { // 0x5c3cc3: 3b35a4a8a500 CMP ESI,dword ptr [0x00a5a8a4]
    (void)integer::sub(s.si,m.r32((0x00a5a8a4u)),32,flags);
  }
  { // 0x5c3cc9: 7410 JZ 0x005c3cdb
    if(integer::condition("JZ",flags)) goto L005c3cdb;
  }
  { // 0x5c3ccb: 3b35a8a8a500 CMP ESI,dword ptr [0x00a5a8a8]
    (void)integer::sub(s.si,m.r32((0x00a5a8a8u)),32,flags);
  }
  { // 0x5c3cd1: 7408 JZ 0x005c3cdb
    if(integer::condition("JZ",flags)) goto L005c3cdb;
  }
  { // 0x5c3cd3: 3b35aca8a500 CMP ESI,dword ptr [0x00a5a8ac]
    (void)integer::sub(s.si,m.r32((0x00a5a8acu)),32,flags);
  }
  { // 0x5c3cd9: 750a JNZ 0x005c3ce5
    if(integer::condition("JNZ",flags)) goto L005c3ce5;
  }
  L005c3cdb: { // 0x5c3cdb: 8b04bd2c56a200 MOV EAX,dword ptr [EDI*0x4 + 0xa2562c]
    s.ax = m.r32(((s.di * 0x00000004u)+0x00a2562cu));
  }
  { // 0x5c3ce2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c3ce3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c3ce4: c3 RET
    finish(m,s,f,0u); return;
  }
  L005c3ce5: { // 0x5c3ce5: 3b359ca8a500 CMP ESI,dword ptr [0x00a5a89c]
    (void)integer::sub(s.si,m.r32((0x00a5a89cu)),32,flags);
  }
  { // 0x5c3ceb: 7417 JZ 0x005c3d04
    if(integer::condition("JZ",flags)) goto L005c3d04;
  }
  { // 0x5c3ced: 3b35a0a8a500 CMP ESI,dword ptr [0x00a5a8a0]
    (void)integer::sub(s.si,m.r32((0x00a5a8a0u)),32,flags);
  }
  { // 0x5c3cf3: 740f JZ 0x005c3d04
    if(integer::condition("JZ",flags)) goto L005c3d04;
  }
  { // 0x5c3cf5: 3b35b0a8a500 CMP ESI,dword ptr [0x00a5a8b0]
    (void)integer::sub(s.si,m.r32((0x00a5a8b0u)),32,flags);
  }
  { // 0x5c3cfb: 7407 JZ 0x005c3d04
    if(integer::condition("JZ",flags)) goto L005c3d04;
  }
  { // 0x5c3cfd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5c3cff: e87c110a00 CALL 0x00664e80
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L005c3d04: { // 0x5c3d04: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c3d05: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c3d06: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c89f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c89f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c89f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5c89f3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c89f4: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5c89f6: 8b4e38 MOV ECX,dword ptr [ESI + 0x38]
    s.cx = m.r32((s.si+0x00000038u));
  }
  { // 0x5c89f9: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  { // 0x5c89fb: 7409 JZ 0x005c8a06
    if(integer::condition("JZ",flags)) goto L005c8a06;
  }
  { // 0x5c89fd: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5c89ff: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5c8a01: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5c8a03: 897e38 MOV dword ptr [ESI + 0x38],EDI
    m.w32((s.si+0x00000038u), s.di);
  }
  L005c8a06: { // 0x5c8a06: 8b4650 MOV EAX,dword ptr [ESI + 0x50]
    s.ax = m.r32((s.si+0x00000050u));
  }
  { // 0x5c8a09: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x5c8a0b: 740c JZ 0x005c8a19
    if(integer::condition("JZ",flags)) goto L005c8a19;
  }
  { // 0x5c8a0d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c8a0e: e8684c1a00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5c8a13: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5c8a16: 897e50 MOV dword ptr [ESI + 0x50],EDI
    m.w32((s.si+0x00000050u), s.di);
  }
  L005c8a19: { // 0x5c8a19: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x5c8a1c: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x5c8a1e: 740c JZ 0x005c8a2c
    if(integer::condition("JZ",flags)) goto L005c8a2c;
  }
  { // 0x5c8a20: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c8a21: e8554c1a00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5c8a26: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5c8a29: 897e04 MOV dword ptr [ESI + 0x4],EDI
    m.w32((s.si+0x00000004u), s.di);
  }
  L005c8a2c: { // 0x5c8a2c: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x5c8a2f: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x5c8a31: 740c JZ 0x005c8a3f
    if(integer::condition("JZ",flags)) goto L005c8a3f;
  }
  { // 0x5c8a33: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c8a34: e8424c1a00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5c8a39: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5c8a3c: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L005c8a3f: { // 0x5c8a3f: 897e3c MOV dword ptr [ESI + 0x3c],EDI
    m.w32((s.si+0x0000003cu), s.di);
  }
  { // 0x5c8a42: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c8a43: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x5c8a48: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c8a49: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c8c00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c8c00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c8c01: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5c8c03: 837e40ff CMP dword ptr [ESI + 0x40],-0x1
    (void)integer::sub(m.r32((s.si+0x00000040u)),0xffffffffu,32,flags);
  }
  { // 0x5c8c07: 7437 JZ 0x005c8c40
    if(integer::condition("JZ",flags)) goto L005c8c40;
  }
  { // 0x5c8c09: 8b0d28d6b000 MOV ECX,dword ptr [0x00b0d628]
    s.cx = m.r32((0x00b0d628u));
  }
  { // 0x5c8c0f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5c8c11: 742d JZ 0x005c8c40
    if(integer::condition("JZ",flags)) goto L005c8c40;
  }
  { // 0x5c8c13: e8f8081600 CALL 0x00729510
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5c8c18: 8b0d28d6b000 MOV ECX,dword ptr [0x00b0d628]
    s.cx = m.r32((0x00b0d628u));
  }
  { // 0x5c8c1e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5c8c20: 7406 JZ 0x005c8c28
    if(integer::condition("JZ",flags)) goto L005c8c28;
  }
  { // 0x5c8c22: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5c8c24: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5c8c26: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L005c8c28: { // 0x5c8c28: c70528d6b00000000000 MOV dword ptr [0x00b0d628],0x0
    m.w32((0x00b0d628u), 0x00000000u);
  }
  { // 0x5c8c32: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5c8c34: c74640ffffffff MOV dword ptr [ESI + 0x40],0xffffffff
    m.w32((s.si+0x00000040u), 0xffffffffu);
  }
  { // 0x5c8c3b: e8b0fdffff CALL 0x005c89f0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L005c8c40: { // 0x5c8c40: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c8c41: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001ca4e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5ca4e0: 8b0d28d6b000 MOV ECX,dword ptr [0x00b0d628]
    s.cx = m.r32((0x00b0d628u));
  }
  { // 0x5ca4e6: 83ec54 SUB ESP,0x54
    f.sp = integer::sub(f.sp,0x00000054u,32,flags);
  }
  { // 0x5ca4e9: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5ca4eb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ca4ec: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5ca4ef: 8b0d28d6b000 MOV ECX,dword ptr [0x00b0d628]
    s.cx = m.r32((0x00b0d628u));
  }
  { // 0x5ca4f5: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x5ca4f7: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5ca4f9: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5ca4fb: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x5ca4fd: 6a5a PUSH 0x5a
    f.push(m,0x0000005au);
  }
  { // 0x5ca4ff: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  { // 0x5ca503: 6a51 PUSH 0x51
    f.push(m,0x00000051u);
  }
  { // 0x5ca505: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5ca506: 6a0d PUSH 0xd
    f.push(m,0x0000000du);
  }
  { // 0x5ca508: 68101e7d00 PUSH 0x7d1e10
    f.push(m,0x007d1e10u);
  }
  { // 0x5ca50d: ff521c CALL dword ptr [EDX + 0x1c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000001cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5ca510: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x5ca513: 7506 JNZ 0x005ca51b
    if(integer::condition("JNZ",flags)) goto L005ca51b;
  }
  { // 0x5ca515: 81e67fffffff AND ESI,0xffffff7f
    s.si = integer::logical((s.si)&(0xffffff7fu),32,flags);
  }
  L005ca51b: { // 0x5ca51b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5ca51d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5ca51e: 83c454 ADD ESP,0x54
    f.sp = integer::add(f.sp,0x00000054u,32,flags);
  }
  { // 0x5ca521: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001cae60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cae60: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x5cae64: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x5cae66: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5cae67: ff9284000000 CALL dword ptr [EDX + 0x84]
    const std::uint32_t call_target=m.r32((s.dx+0x00000084u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5cae6d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5cae6f: e84c59e4ff CALL 0x004107c0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5cae74: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001cb480(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cb480: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5cb481: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cb482: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5cb484: 8a4677 MOV AL,byte ptr [ESI + 0x77]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000077u)));
  }
  { // 0x5cb487: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5cb489: 7467 JZ 0x005cb4f2
    if(integer::condition("JZ",flags)) goto L005cb4f2;
  }
  { // 0x5cb48b: 8b15a088a200 MOV EDX,dword ptr [0x00a288a0]
    s.dx = m.r32((0x00a288a0u));
  }
  { // 0x5cb491: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x5cb495: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5cb496: b9a088a200 MOV ECX,0xa288a0
    s.cx = 0x00a288a0u;
  }
  { // 0x5cb49b: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  { // 0x5cb49f: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5cb4a2: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x5cb4a5: 742d JZ 0x005cb4d4
    if(integer::condition("JZ",flags)) goto L005cb4d4;
  }
  { // 0x5cb4a7: 8b0db088a200 MOV ECX,dword ptr [0x00a288b0]
    s.cx = m.r32((0x00a288b0u));
  }
  { // 0x5cb4ad: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5cb4af: 7d23 JGE 0x005cb4d4
    if(integer::condition("JGE",flags)) goto L005cb4d4;
  }
  { // 0x5cb4b1: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x5cb4b2: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5cb4b4: 890db088a200 MOV dword ptr [0x00a288b0],ECX
    m.w32((0x00a288b0u), s.cx);
  }
  { // 0x5cb4ba: 7d18 JGE 0x005cb4d4
    if(integer::condition("JGE",flags)) goto L005cb4d4;
  }
  L005cb4bc: { // 0x5cb4bc: 8b0da488a200 MOV ECX,dword ptr [0x00a288a4]
    s.cx = m.r32((0x00a288a4u));
  }
  { // 0x5cb4c2: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x5cb4c3: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x5cb4c6: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  { // 0x5cb4ca: 8b0db088a200 MOV ECX,dword ptr [0x00a288b0]
    s.cx = m.r32((0x00a288b0u));
  }
  { // 0x5cb4d0: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5cb4d2: 7ce8 JL 0x005cb4bc
    if(integer::condition("JL",flags)) goto L005cb4bc;
  }
  L005cb4d4: { // 0x5cb4d4: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x5cb4d9: c6467700 MOV byte ptr [ESI + 0x77],0x0
    m.w8((s.si+0x00000077u), 0x00000000u);
  }
  { // 0x5cb4dd: e88e34edff CALL 0x0049e970
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5cb4e2: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x5cb4e4: 750c JNZ 0x005cb4f2
    if(integer::condition("JNZ",flags)) goto L005cb4f2;
  }
  { // 0x5cb4e6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5cb4e8: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x5cb4ed: e89e34edff CALL 0x0049e990
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L005cb4f2: { // 0x5cb4f2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cb4f3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x5cb4f4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001ccb90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5ccb90: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5ccb91: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ccb92: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5ccb94: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5ccb95: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5ccb97: ff9084000000 CALL dword ptr [EAX + 0x84]
    const std::uint32_t call_target=m.r32((s.ax+0x00000084u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5ccb9d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5ccb9f: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5ccba1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5ccba3: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  { // 0x5ccba5: ff523c CALL dword ptr [EDX + 0x3c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000003cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5ccba8: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x5ccbac: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5ccbad: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x5ccbb1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5ccbb3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5ccbb4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5ccbb5: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5ccbb7: ff9394000000 CALL dword ptr [EBX + 0x94]
    const std::uint32_t call_target=m.r32((s.bx+0x00000094u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5ccbbd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5ccbbe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5ccbbf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5ccbc0: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_001cce60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cce60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cce61: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5cce63: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5cce65: ff90a4010000 CALL dword ptr [EAX + 0x1a4]
    const std::uint32_t call_target=m.r32((s.ax+0x000001a4u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5cce6b: 8a4e79 MOV CL,byte ptr [ESI + 0x79]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000079u)));
  }
  { // 0x5cce6e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cce6f: 0fbe901b010000 MOVSX EDX,byte ptr [EAX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  { // 0x5cce76: f6d9 NEG CL
    s.cx = with_al(s.cx, integer::sub(0u,(s.cx & 0xffu),8,flags));
  }
  { // 0x5cce78: 1bc9 SBB ECX,ECX
    s.cx = integer::sub(s.cx,s.cx,32,flags,flags&integer::CF);
  }
  { // 0x5cce7a: 83e104 AND ECX,0x4
    s.cx = integer::logical((s.cx)&(0x00000004u),32,flags);
  }
  { // 0x5cce7d: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  { // 0x5cce7f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x5cce81: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001ccfb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5ccfb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ccfb1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5ccfb3: 8a4674 MOV AL,byte ptr [ESI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000074u)));
  }
  { // 0x5ccfb6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5ccfb8: 7424 JZ 0x005ccfde
    if(integer::condition("JZ",flags)) goto L005ccfde;
  }
  { // 0x5ccfba: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5ccfbc: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5ccfbe: ff901c010000 CALL dword ptr [EAX + 0x11c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000011cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5ccfc4: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x5ccfc8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5ccfca: 898e90000000 MOV dword ptr [ESI + 0x90],ECX
    m.w32((s.si+0x00000090u), s.cx);
  }
  { // 0x5ccfd0: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5ccfd2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5ccfd4: ff921c010000 CALL dword ptr [EDX + 0x11c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000011cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5ccfda: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5ccfdb: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L005ccfde: { // 0x5ccfde: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x5ccfe2: 898690000000 MOV dword ptr [ESI + 0x90],EAX
    m.w32((s.si+0x00000090u), s.ax);
  }
  { // 0x5ccfe8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5ccfe9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001cd430(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cd430: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5cd433: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5cd434: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5cd438: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x5cd43a: 7509 JNZ 0x005cd445
    if(integer::condition("JNZ",flags)) goto L005cd445;
  }
  { // 0x5cd43c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5cd43e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5cd43f: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5cd442: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L005cd445: { // 0x5cd445: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5cd447: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cd448: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x5cd44c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5cd44d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5cd44e: ff5048 CALL dword ptr [EAX + 0x48]
    const std::uint32_t call_target=m.r32((s.ax+0x00000048u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5cd451: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  { // 0x5cd453: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  { // 0x5cd455: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x5cd457: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  { // 0x5cd45a: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  { // 0x5cd45d: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  { // 0x5cd461: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  { // 0x5cd465: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5cd466: ff5248 CALL dword ptr [EDX + 0x48]
    const std::uint32_t call_target=m.r32((s.dx+0x00000048u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5cd469: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x5cd46b: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  { // 0x5cd46d: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x5cd46f: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  { // 0x5cd472: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x5cd474: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5cd476: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x5cd478: 0fafce IMUL ECX,ESI
    s.cx = integer::imul(s.cx,s.si,32,flags);
  }
  { // 0x5cd47b: 0fafc0 IMUL EAX,EAX
    s.ax = integer::imul(s.ax,s.ax,32,flags);
  }
  { // 0x5cd47e: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  { // 0x5cd481: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5cd482: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cd483: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  { // 0x5cd487: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x5cd489: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5cd48a: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5cd48d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001cd520(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cd520: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cd521: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5cd523: 8b4e38 MOV ECX,dword ptr [ESI + 0x38]
    s.cx = m.r32((s.si+0x00000038u));
  }
  { // 0x5cd526: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5cd528: 7405 JZ 0x005cd52f
    if(integer::condition("JZ",flags)) goto L005cd52f;
  }
  { // 0x5cd52a: e84189e6ff CALL 0x00435e70
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L005cd52f: { // 0x5cd52f: b201 MOV DL,0x1
    s.dx = with_al(s.dx, 0x00000001u);
  }
  { // 0x5cd531: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5cd533: e818491100 CALL 0x006e1e50
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5cd538: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5cd53a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5cd53c: ff90d0000000 CALL dword ptr [EAX + 0xd0]
    const std::uint32_t call_target=m.r32((s.ax+0x000000d0u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5cd542: c6467d00 MOV byte ptr [ESI + 0x7d],0x0
    m.w8((s.si+0x0000007du), 0x00000000u);
  }
  { // 0x5cd546: a1e887aa00 MOV EAX,[0x00aa87e8]
    s.ax = m.r32((0x00aa87e8u));
  }
  { // 0x5cd54b: 3905f087aa00 CMP dword ptr [0x00aa87f0],EAX
    (void)integer::sub(m.r32((0x00aa87f0u)),s.ax,32,flags);
  }
  { // 0x5cd551: 7c2f JL 0x005cd582
    if(integer::condition("JL",flags)) goto L005cd582;
  }
  { // 0x5cd553: 8a0ded87aa00 MOV CL,byte ptr [0x00aa87ed]
    s.cx = with_al(s.cx, m.r8((0x00aa87edu)));
  }
  { // 0x5cd559: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x5cd55b: 7504 JNZ 0x005cd561
    if(integer::condition("JNZ",flags)) goto L005cd561;
  }
  { // 0x5cd55d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5cd55f: 7539 JNZ 0x005cd59a
    if(integer::condition("JNZ",flags)) goto L005cd59a;
  }
  L005cd561: { // 0x5cd561: 8b0df487aa00 MOV ECX,dword ptr [0x00aa87f4]
    s.cx = m.r32((0x00aa87f4u));
  }
  { // 0x5cd567: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5cd569: 7e2f JLE 0x005cd59a
    if(integer::condition("JLE",flags)) goto L005cd59a;
  }
  { // 0x5cd56b: 8b15e087aa00 MOV EDX,dword ptr [0x00aa87e0]
    s.dx = m.r32((0x00aa87e0u));
  }
  { // 0x5cd571: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x5cd573: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5cd575: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5cd576: b9e087aa00 MOV ECX,0xaa87e0
    s.cx = 0x00aa87e0u;
  }
  { // 0x5cd57b: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5cd57e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5cd580: 7418 JZ 0x005cd59a
    if(integer::condition("JZ",flags)) goto L005cd59a;
  }
  L005cd582: { // 0x5cd582: 8b0df087aa00 MOV ECX,dword ptr [0x00aa87f0]
    s.cx = m.r32((0x00aa87f0u));
  }
  { // 0x5cd588: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x5cd58a: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x5cd58b: 890df087aa00 MOV dword ptr [0x00aa87f0],ECX
    m.w32((0x00aa87f0u), s.cx);
  }
  { // 0x5cd591: 8b0de487aa00 MOV ECX,dword ptr [0x00aa87e4]
    s.cx = m.r32((0x00aa87e4u));
  }
  { // 0x5cd597: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005cd59a: { // 0x5cd59a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cd59b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001cdae0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cdae0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  { // 0x5cdae3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cdae4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5cdae6: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x5cdaea: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5cdaeb: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5cdaed: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5cdaee: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5cdaf0: ff90a8000000 CALL dword ptr [EAX + 0xa8]
    const std::uint32_t call_target=m.r32((s.ax+0x000000a8u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5cdaf6: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5cdaf8: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5cdafa: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  { // 0x5cdafe: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5cdb00: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5cdb01: ff92a8000000 CALL dword ptr [EDX + 0xa8]
    const std::uint32_t call_target=m.r32((s.dx+0x000000a8u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5cdb07: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  { // 0x5cdb0a: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x5cdb0c: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  { // 0x5cdb0e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5cdb0f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x5cdb11: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cdb12: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  { // 0x5cdb15: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001cdb40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cdb40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cdb41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5cdb43: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  { // 0x5cdb49: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5cdb4b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5cdb4c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5cdb4e: ff90c4000000 CALL dword ptr [EAX + 0xc4]
    const std::uint32_t call_target=m.r32((s.ax+0x000000c4u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5cdb54: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5cdb56: 7414 JZ 0x005cdb6c
    if(integer::condition("JZ",flags)) goto L005cdb6c;
  }
  { // 0x5cdb58: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5cdb5a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5cdb5c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5cdb5e: ff92cc000000 CALL dword ptr [EDX + 0xcc]
    const std::uint32_t call_target=m.r32((s.dx+0x000000ccu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5cdb64: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5cdb66: 7504 JNZ 0x005cdb6c
    if(integer::condition("JNZ",flags)) goto L005cdb6c;
  }
  { // 0x5cdb68: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x5cdb6a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cdb6b: c3 RET
    finish(m,s,f,0u); return;
  }
  L005cdb6c: { // 0x5cdb6c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5cdb6e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5cdb70: ff9084000000 CALL dword ptr [EAX + 0x84]
    const std::uint32_t call_target=m.r32((s.ax+0x00000084u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5cdb76: 8a8000020000 MOV AL,byte ptr [EAX + 0x200]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000200u)));
  }
  { // 0x5cdb7c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cdb7d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001d75d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5d75d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5d75d1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5d75d2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x5d75d4: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x5d75d6: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5d75d7: ff1500557800 CALL dword ptr [0x00785500]
    const std::uint32_t call_target=m.r32((0x00785500u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5d75dd: 81e6ff000000 AND ESI,0xff
    s.si = integer::logical((s.si)&(0x000000ffu),32,flags);
  }
  { // 0x5d75e3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5d75e4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5d75e5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5d75e6: ff15fc547800 CALL dword ptr [0x007854fc]
    const std::uint32_t call_target=m.r32((0x007854fcu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5d75ec: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x5d75ee: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5d75ef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5d75f0: 740a JZ 0x005d75fc
    if(integer::condition("JZ",flags)) goto L005d75fc;
  }
  { // 0x5d75f2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5d75f3: ff158c537800 CALL dword ptr [0x0078538c]
    const std::uint32_t call_target=m.r32((0x0078538cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5d75f9: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x5d75fb: c3 RET
    finish(m,s,f,0u); return;
  }
  L005d75fc: { // 0x5d75fc: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x5d75fe: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001da440(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5da440: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5da441: a1a4b1a500 MOV EAX,[0x00a5b1a4]
    s.ax = m.r32((0x00a5b1a4u));
  }
  { // 0x5da446: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5da447: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5da449: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5da44a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5da44c: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x5da44e: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  { // 0x5da452: 745c JZ 0x005da4b0
    if(integer::condition("JZ",flags)) goto L005da4b0;
  }
  { // 0x5da454: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x5da458: ff15b8b1a500 CALL dword ptr [0x00a5b1b8]
    const std::uint32_t call_target=m.r32((0x00a5b1b8u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5da45e: 8b0dacb1a500 MOV ECX,dword ptr [0x00a5b1ac]
    s.cx = m.r32((0x00a5b1acu));
  }
  { // 0x5da464: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x5da469: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x5da46b: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x5da46c: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  { // 0x5da46e: a1a0b1a500 MOV EAX,[0x00a5b1a0]
    s.ax = m.r32((0x00a5b1a0u));
  }
  { // 0x5da473: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  { // 0x5da476: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5da478: 7436 JZ 0x005da4b0
    if(integer::condition("JZ",flags)) goto L005da4b0;
  }
  { // 0x5da47a: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L005da47e: { // 0x5da47e: 3908 CMP dword ptr [EAX],ECX
    (void)integer::sub(m.r32((s.ax)),s.cx,32,flags);
  }
  { // 0x5da480: 740e JZ 0x005da490
    if(integer::condition("JZ",flags)) goto L005da490;
  }
  { // 0x5da482: 8b8004020000 MOV EAX,dword ptr [EAX + 0x204]
    s.ax = m.r32((s.ax+0x00000204u));
  }
  { // 0x5da488: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5da48a: 75f2 JNZ 0x005da47e
    if(integer::condition("JNZ",flags)) goto L005da47e;
  }
  { // 0x5da48c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5da48d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5da48e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x5da48f: c3 RET
    finish(m,s,f,0u); return;
  }
  L005da490: { // 0x5da490: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5da492: 741c JZ 0x005da4b0
    if(integer::condition("JZ",flags)) goto L005da4b0;
  }
  { // 0x5da494: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  { // 0x5da497: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5da499: 7415 JZ 0x005da4b0
    if(integer::condition("JZ",flags)) goto L005da4b0;
  }
  { // 0x5da49b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5da49d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5da49f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5da4a0: c7407002000000 MOV dword ptr [EAX + 0x70],0x2
    m.w32((s.ax+0x00000070u), 0x00000002u);
  }
  { // 0x5da4a7: 897814 MOV dword ptr [EAX + 0x14],EDI
    m.w32((s.ax+0x00000014u), s.di);
  }
  { // 0x5da4aa: ff1594547800 CALL dword ptr [0x00785494]
    const std::uint32_t call_target=m.r32((0x00785494u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L005da4b0: { // 0x5da4b0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5da4b1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5da4b2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x5da4b3: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001da610(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5da610: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5da613: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5da614: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5da616: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5da617: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x5da619: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x5da61d: e8ce0c1800 CALL 0x0075b2f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5da622: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x5da626: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x5da62a: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x5da62e: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  { // 0x5da632: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5da633: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5da635: 68e9040000 PUSH 0x4e9
    f.push(m,0x000004e9u);
  }
  { // 0x5da63a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5da63b: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  { // 0x5da63f: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5da645: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  { // 0x5da649: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5da64b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5da64c: e8ff0c1800 CALL 0x0075b350
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5da651: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x5da655: e8360d1800 CALL 0x0075b390
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5da65a: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5da65c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5da65d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5da65e: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5da661: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_001e0a10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5e0a10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5e0a11: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x5e0a15: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5e0a16: ff1500557800 CALL dword ptr [0x00785500]
    const std::uint32_t call_target=m.r32((0x00785500u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5e0a1c: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x5e0a1e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5e0a20: e85b83ffff CALL 0x005d8d80
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5e0a25: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5e0a27: 7410 JZ 0x005e0a39
    if(integer::condition("JZ",flags)) goto L005e0a39;
  }
  { // 0x5e0a29: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5e0a2b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5e0a2d: 68ee040000 PUSH 0x4ee
    f.push(m,0x000004eeu);
  }
  { // 0x5e0a32: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5e0a33: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L005e0a39: { // 0x5e0a39: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x5e0a3e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5e0a3f: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_001e16e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5e16e0: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x5e16e3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5e16e4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5e16e5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5e16e7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5e16e8: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x5e16ea: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5e16eb: ff1500557800 CALL dword ptr [0x00785500]
    const std::uint32_t call_target=m.r32((0x00785500u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5e16f1: 8b1d98537800 MOV EBX,dword ptr [0x00785398]
    s.bx = m.r32((0x00785398u));
  }
  { // 0x5e16f7: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  { // 0x5e16fb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5e16fc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5e16fd: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5e16ff: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x5e1703: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5e1704: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5e1705: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5e1707: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x5e170b: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x5e170f: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5e1713: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x5e1717: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5e1719: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5e171b: 2bd3 SUB EDX,EBX
    s.dx = integer::sub(s.dx,s.bx,32,flags);
  }
  { // 0x5e171d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5e171e: a114a78300 MOV EAX,[0x0083a714]
    s.ax = m.r32((0x0083a714u));
  }
  { // 0x5e1723: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5e1724: 2b4704 SUB EAX,dword ptr [EDI + 0x4]
    s.ax = integer::sub(s.ax,m.r32((s.di+0x00000004u)),32,flags);
  }
  { // 0x5e1727: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x5e1728: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x5e172a: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  { // 0x5e172e: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x5e1730: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x5e1732: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x5e1734: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x5e1736: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5e1737: a110a78300 MOV EAX,[0x0083a710]
    s.ax = m.r32((0x0083a710u));
  }
  { // 0x5e173c: 8b7c242c MOV EDI,dword ptr [ESP + 0x2c]
    s.di = m.r32((f.sp+0x0000002cu));
  }
  { // 0x5e1740: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5e1742: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x5e1743: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x5e1745: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x5e1747: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x5e1749: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  { // 0x5e174b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5e174c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5e174d: ff15e0537800 CALL dword ptr [0x007853e0]
    const std::uint32_t call_target=m.r32((0x007853e0u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5e1753: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5e1754: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5e1755: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5e1756: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x5e1759: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001e21f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5e21f0: a114a78300 MOV EAX,[0x0083a714]
    s.ax = m.r32((0x0083a714u));
  }
  { // 0x5e21f5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5e21f6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5e21f8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5e21f9: 8b0d10a78300 MOV ECX,dword ptr [0x0083a710]
    s.cx = m.r32((0x0083a710u));
  }
  { // 0x5e21ff: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5e2201: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5e2202: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5e2203: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5e2205: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5e2207: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x5e2209: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5e220a: ff15e0537800 CALL dword ptr [0x007853e0]
    const std::uint32_t call_target=m.r32((0x007853e0u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5e2210: 893520dfa500 MOV dword ptr [0x00a5df20],ESI
    m.w32((0x00a5df20u), s.si);
  }
  { // 0x5e2216: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5e2217: 68e01e5e00 PUSH 0x5e1ee0
    f.push(m,0x005e1ee0u);
  }
  { // 0x5e221c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5e221d: ff15dc547800 CALL dword ptr [0x007854dc]
    const std::uint32_t call_target=m.r32((0x007854dcu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5e2223: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5e2224: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5e2225: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001f7040(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f7040: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5f7041: a1a4b1a500 MOV EAX,[0x00a5b1a4]
    s.ax = m.r32((0x00a5b1a4u));
  }
  { // 0x5f7046: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f7047: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5f7049: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  { // 0x5f704d: 7465 JZ 0x005f70b4
    if(integer::condition("JZ",flags)) goto L005f70b4;
  }
  { // 0x5f704f: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x5f7053: ff15b8b1a500 CALL dword ptr [0x00a5b1b8]
    const std::uint32_t call_target=m.r32((0x00a5b1b8u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5f7059: 8b0dacb1a500 MOV ECX,dword ptr [0x00a5b1ac]
    s.cx = m.r32((0x00a5b1acu));
  }
  { // 0x5f705f: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x5f7064: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x5f7066: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x5f7067: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  { // 0x5f7069: a1a0b1a500 MOV EAX,[0x00a5b1a0]
    s.ax = m.r32((0x00a5b1a0u));
  }
  { // 0x5f706e: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  { // 0x5f7071: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5f7073: 743f JZ 0x005f70b4
    if(integer::condition("JZ",flags)) goto L005f70b4;
  }
  { // 0x5f7075: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L005f7079: { // 0x5f7079: 3908 CMP dword ptr [EAX],ECX
    (void)integer::sub(m.r32((s.ax)),s.cx,32,flags);
  }
  { // 0x5f707b: 740d JZ 0x005f708a
    if(integer::condition("JZ",flags)) goto L005f708a;
  }
  { // 0x5f707d: 8b8004020000 MOV EAX,dword ptr [EAX + 0x204]
    s.ax = m.r32((s.ax+0x00000204u));
  }
  { // 0x5f7083: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5f7085: 75f2 JNZ 0x005f7079
    if(integer::condition("JNZ",flags)) goto L005f7079;
  }
  { // 0x5f7087: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f7088: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x5f7089: c3 RET
    finish(m,s,f,0u); return;
  }
  L005f708a: { // 0x5f708a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5f708c: 7426 JZ 0x005f70b4
    if(integer::condition("JZ",flags)) goto L005f70b4;
  }
  { // 0x5f708e: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  { // 0x5f7091: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5f7093: 741f JZ 0x005f70b4
    if(integer::condition("JZ",flags)) goto L005f70b4;
  }
  { // 0x5f7095: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x5f7098: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5f709a: 7418 JZ 0x005f70b4
    if(integer::condition("JZ",flags)) goto L005f70b4;
  }
  { // 0x5f709c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x5f709e: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5f70a0: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5f70a2: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  { // 0x5f70a9: a12cdfa500 MOV EAX,[0x00a5df2c]
    s.ax = m.r32((0x00a5df2cu));
  }
  { // 0x5f70ae: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x5f70af: a32cdfa500 MOV [0x00a5df2c],EAX
    m.w32((0x00a5df2cu), s.ax);
  }
  L005f70b4: { // 0x5f70b4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f70b5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x5f70b6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001f7290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f7290: a164dfa500 MOV EAX,[0x00a5df64]
    s.ax = m.r32((0x00a5df64u));
  }
  { // 0x5f7295: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5f7297: 7e08 JLE 0x005f72a1
    if(integer::condition("JLE",flags)) goto L005f72a1;
  }
  { // 0x5f7299: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x5f729a: a364dfa500 MOV [0x00a5df64],EAX
    m.w32((0x00a5df64u), s.ax);
  }
  { // 0x5f729f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005f72a1: { // 0x5f72a1: 7523 JNZ 0x005f72c6
    if(integer::condition("JNZ",flags)) goto L005f72c6;
  }
  { // 0x5f72a3: 8b0da81f8200 MOV ECX,dword ptr [0x00821fa8]
    s.cx = m.r32((0x00821fa8u));
  }
  { // 0x5f72a9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5f72ab: 7419 JZ 0x005f72c6
    if(integer::condition("JZ",flags)) goto L005f72c6;
  }
  { // 0x5f72ad: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5f72af: ff501c CALL dword ptr [EAX + 0x1c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000001cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5f72b2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5f72b4: 750b JNZ 0x005f72c1
    if(integer::condition("JNZ",flags)) goto L005f72c1;
  }
  { // 0x5f72b6: 8b0da81f8200 MOV ECX,dword ptr [0x00821fa8]
    s.cx = m.r32((0x00821fa8u));
  }
  { // 0x5f72bc: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x5f72be: ff5218 CALL dword ptr [EDX + 0x18]
    const std::uint32_t call_target=m.r32((s.dx+0x00000018u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L005f72c1: { // 0x5f72c1: a164dfa500 MOV EAX,[0x00a5df64]
    s.ax = m.r32((0x00a5df64u));
  }
  L005f72c6: { // 0x5f72c6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001f7480(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f7480: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f7481: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5f7483: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5f7485: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f7486: ff1598547800 CALL dword ptr [0x00785498]
    const std::uint32_t call_target=m.r32((0x00785498u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5f748c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f748d: ff15d0547800 CALL dword ptr [0x007854d0]
    const std::uint32_t call_target=m.r32((0x007854d0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5f7493: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  { // 0x5f7499: e8b297f3ff CALL 0x00530c50
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5f749e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f749f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001f7e80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f7e80: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f7e81: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5f7e82: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f7e83: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x5f7e85: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  { // 0x5f7e87: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f7e88: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f7e8a: ba007f5f00 MOV EDX,0x5f7f00
    s.dx = 0x005f7f00u;
  }
  { // 0x5f7e8f: b9f0000000 MOV ECX,0xf0
    s.cx = 0x000000f0u;
  }
  { // 0x5f7e94: e837f4ffff CALL 0x005f72d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5f7e99: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5f7e9b: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5f7e9d: 7458 JZ 0x005f7ef7
    if(integer::condition("JZ",flags)) goto L005f7ef7;
  }
  { // 0x5f7e9f: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x5f7ea3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f7ea4: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x5f7ea6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f7ea7: ff1588547800 CALL dword ptr [0x00785488]
    const std::uint32_t call_target=m.r32((0x00785488u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5f7ead: 8b3d9c547800 MOV EDI,dword ptr [0x0078549c]
    s.di = m.r32((0x0078549cu));
  }
  { // 0x5f7eb3: 68b0050000 PUSH 0x5b0
    f.push(m,0x000005b0u);
  }
  { // 0x5f7eb8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f7eb9: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5f7ebb: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5f7ebc: 8b2da0547800 MOV EBP,dword ptr [0x007854a0]
    s.bp = m.r32((0x007854a0u));
  }
  { // 0x5f7ec2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f7ec4: 68b2040000 PUSH 0x4b2
    f.push(m,0x000004b2u);
  }
  { // 0x5f7ec9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f7eca: ffd5 CALL EBP
    const std::uint32_t call_target=s.bp;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5f7ecc: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x5f7ece: 7427 JZ 0x005f7ef7
    if(integer::condition("JZ",flags)) goto L005f7ef7;
  }
  { // 0x5f7ed0: 68c0050000 PUSH 0x5c0
    f.push(m,0x000005c0u);
  }
  { // 0x5f7ed5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f7ed6: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x5f7ed8: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5f7eda: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f7edb: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f7edd: 68b2040000 PUSH 0x4b2
    f.push(m,0x000004b2u);
  }
  { // 0x5f7ee2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f7ee3: ffd5 CALL EBP
    const std::uint32_t call_target=s.bp;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x5f7ee5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5f7ee7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f7ee8: ff1590547800 CALL dword ptr [0x00785490]
    const std::uint32_t call_target=m.r32((0x00785490u));
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  { // 0x5f7eee: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  { // 0x5f7ef0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f7ef1: ff1598547800 CALL dword ptr [0x00785498]
    const std::uint32_t call_target=m.r32((0x00785498u));
    invoke(m,s,f,op,7u,call_target); flags=0x202u;
  }
  L005f7ef7: { // 0x5f7ef7: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5f7ef9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f7efa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f7efb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5f7efc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5f7efd: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001f7f60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f7f60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f7f61: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f7f62: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5f7f64: 68b0050000 PUSH 0x5b0
    f.push(m,0x000005b0u);
  }
  { // 0x5f7f69: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x5f7f6b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f7f6c: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5f7f72: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f7f73: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f7f75: 68b2040000 PUSH 0x4b2
    f.push(m,0x000004b2u);
  }
  { // 0x5f7f7a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f7f7b: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5f7f81: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f7f82: ff156c547800 CALL dword ptr [0x0078546c]
    const std::uint32_t call_target=m.r32((0x0078546cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5f7f88: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f7f89: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f7f8a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001f8a90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f8a90: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8a91: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5f8a92: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8a93: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f8a95: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x5f8a97: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f8a99: 6a0e PUSH 0xe
    f.push(m,0x0000000eu);
  }
  { // 0x5f8a9b: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  { // 0x5f8a9d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8a9e: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5f8aa4: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5f8aa6: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x5f8aa8: 7f0d JG 0x005f8ab7
    if(integer::condition("JG",flags)) goto L005f8ab7;
  }
  { // 0x5f8aaa: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  { // 0x5f8aac: e8bf141600 CALL 0x00759f70
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5f8ab1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5f8ab3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f8ab4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5f8ab5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5f8ab6: c3 RET
    finish(m,s,f,0u); return;
  }
  L005f8ab7: { // 0x5f8ab7: 8d4702 LEA EAX,[EDI + 0x2]
    s.ax = (s.di+0x00000002u);
  }
  { // 0x5f8aba: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8abb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f8abc: e8964e1700 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5f8ac1: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5f8ac4: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5f8ac6: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5f8ac7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8ac8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8ac9: 68b5040000 PUSH 0x4b5
    f.push(m,0x000004b5u);
  }
  { // 0x5f8ace: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8acf: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5f8ad5: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  { // 0x5f8ad7: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5f8ad9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8ada: e8210a1600 CALL 0x00759500
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x5f8adf: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8ae0: e8964b1700 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x5f8ae5: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5f8ae8: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x5f8aea: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f8aeb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f8aec: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5f8aed: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5f8aee: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001f8af0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f8af0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8af1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5f8af2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8af3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f8af5: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x5f8af7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f8af9: 6a0e PUSH 0xe
    f.push(m,0x0000000eu);
  }
  { // 0x5f8afb: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  { // 0x5f8afd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8afe: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5f8b04: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5f8b06: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x5f8b08: 7f0d JG 0x005f8b17
    if(integer::condition("JG",flags)) goto L005f8b17;
  }
  { // 0x5f8b0a: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  { // 0x5f8b0c: e85f311600 CALL 0x0075bc70
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5f8b11: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5f8b13: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f8b14: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5f8b15: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5f8b16: c3 RET
    finish(m,s,f,0u); return;
  }
  L005f8b17: { // 0x5f8b17: 8d443f04 LEA EAX,[EDI + EDI*0x1 + 0x4]
    s.ax = (s.di+(s.di * 0x00000001u)+0x00000004u);
  }
  { // 0x5f8b1b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8b1c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f8b1d: e8354e1700 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5f8b22: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5f8b25: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5f8b27: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5f8b28: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8b29: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8b2a: 68b3040000 PUSH 0x4b3
    f.push(m,0x000004b3u);
  }
  { // 0x5f8b2f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8b30: ff15a0547800 CALL dword ptr [0x007854a0]
    const std::uint32_t call_target=m.r32((0x007854a0u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5f8b36: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  { // 0x5f8b38: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5f8b3a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8b3b: e870291600 CALL 0x0075b4b0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x5f8b40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8b41: e8354b1700 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x5f8b46: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5f8b49: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x5f8b4b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f8b4c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f8b4d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5f8b4e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5f8b4f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001f8b50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f8b50: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8b51: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5f8b52: 8b2da0547800 MOV EBP,dword ptr [0x007854a0]
    s.bp = m.r32((0x007854a0u));
  }
  { // 0x5f8b58: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8b59: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8b5a: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x5f8b5c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f8b5e: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x5f8b60: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8b61: 688a010000 PUSH 0x18a
    f.push(m,0x0000018au);
  }
  { // 0x5f8b66: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8b67: ffd5 CALL EBP
    const std::uint32_t call_target=s.bp;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5f8b69: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5f8b6b: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5f8b6d: 7f09 JG 0x005f8b78
    if(integer::condition("JG",flags)) goto L005f8b78;
  }
  { // 0x5f8b6f: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5f8b73: e8f8131600 CALL 0x00759f70
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L005f8b78: { // 0x5f8b78: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  { // 0x5f8b7b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8b7c: e8d64d1700 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5f8b81: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5f8b84: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5f8b86: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8b87: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8b88: 68b7040000 PUSH 0x4b7
    f.push(m,0x000004b7u);
  }
  { // 0x5f8b8d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8b8e: ffd5 CALL EBP
    const std::uint32_t call_target=s.bp;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5f8b90: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5f8b92: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5f8b96: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8b97: e864091600 CALL 0x00759500
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x5f8b9c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8b9d: e8d94a1700 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x5f8ba2: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5f8ba5: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x5f8ba7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f8ba8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f8ba9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5f8baa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5f8bab: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001f8bb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f8bb0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8bb1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5f8bb2: 8b2da0547800 MOV EBP,dword ptr [0x007854a0]
    s.bp = m.r32((0x007854a0u));
  }
  { // 0x5f8bb8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8bb9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8bba: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x5f8bbc: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f8bbe: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x5f8bc0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8bc1: 688a010000 PUSH 0x18a
    f.push(m,0x0000018au);
  }
  { // 0x5f8bc6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8bc7: ffd5 CALL EBP
    const std::uint32_t call_target=s.bp;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5f8bc9: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5f8bcb: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5f8bcd: 7f09 JG 0x005f8bd8
    if(integer::condition("JG",flags)) goto L005f8bd8;
  }
  { // 0x5f8bcf: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5f8bd3: e898301600 CALL 0x0075bc70
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L005f8bd8: { // 0x5f8bd8: 8d443604 LEA EAX,[ESI + ESI*0x1 + 0x4]
    s.ax = (s.si+(s.si * 0x00000001u)+0x00000004u);
  }
  { // 0x5f8bdc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f8bdd: e8754d1700 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5f8be2: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5f8be5: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5f8be7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8be8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8be9: 68b6040000 PUSH 0x4b6
    f.push(m,0x000004b6u);
  }
  { // 0x5f8bee: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8bef: ffd5 CALL EBP
    const std::uint32_t call_target=s.bp;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5f8bf1: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5f8bf3: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5f8bf7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8bf8: e8b3281600 CALL 0x0075b4b0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x5f8bfd: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8bfe: e8784a1700 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x5f8c03: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5f8c06: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x5f8c08: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f8c09: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f8c0a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5f8c0b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5f8c0c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001f8c10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f8c10: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8c11: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5f8c12: 8b2da0547800 MOV EBP,dword ptr [0x007854a0]
    s.bp = m.r32((0x007854a0u));
  }
  { // 0x5f8c18: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8c19: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8c1a: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x5f8c1c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f8c1e: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x5f8c20: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8c21: 6849010000 PUSH 0x149
    f.push(m,0x00000149u);
  }
  { // 0x5f8c26: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8c27: ffd5 CALL EBP
    const std::uint32_t call_target=s.bp;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5f8c29: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5f8c2b: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5f8c2d: 7f09 JG 0x005f8c38
    if(integer::condition("JG",flags)) goto L005f8c38;
  }
  { // 0x5f8c2f: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5f8c33: e838131600 CALL 0x00759f70
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L005f8c38: { // 0x5f8c38: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  { // 0x5f8c3b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8c3c: e8164d1700 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5f8c41: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5f8c44: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5f8c46: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8c47: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8c48: 68bd040000 PUSH 0x4bd
    f.push(m,0x000004bdu);
  }
  { // 0x5f8c4d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8c4e: ffd5 CALL EBP
    const std::uint32_t call_target=s.bp;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5f8c50: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5f8c52: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5f8c56: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8c57: e8a4081600 CALL 0x00759500
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x5f8c5c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8c5d: e8194a1700 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x5f8c62: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5f8c65: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x5f8c67: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f8c68: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f8c69: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5f8c6a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5f8c6b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001f8c70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f8c70: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8c71: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5f8c72: 8b2da0547800 MOV EBP,dword ptr [0x007854a0]
    s.bp = m.r32((0x007854a0u));
  }
  { // 0x5f8c78: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8c79: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8c7a: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x5f8c7c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5f8c7e: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x5f8c80: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8c81: 6849010000 PUSH 0x149
    f.push(m,0x00000149u);
  }
  { // 0x5f8c86: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8c87: ffd5 CALL EBP
    const std::uint32_t call_target=s.bp;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5f8c89: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5f8c8b: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5f8c8d: 7f09 JG 0x005f8c98
    if(integer::condition("JG",flags)) goto L005f8c98;
  }
  { // 0x5f8c8f: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5f8c93: e8d82f1600 CALL 0x0075bc70
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L005f8c98: { // 0x5f8c98: 8d443604 LEA EAX,[ESI + ESI*0x1 + 0x4]
    s.ax = (s.si+(s.si * 0x00000001u)+0x00000004u);
  }
  { // 0x5f8c9c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f8c9d: e8b54c1700 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5f8ca2: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5f8ca5: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x5f8ca7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8ca8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f8ca9: 68c3040000 PUSH 0x4c3
    f.push(m,0x000004c3u);
  }
  { // 0x5f8cae: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5f8caf: ffd5 CALL EBP
    const std::uint32_t call_target=s.bp;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5f8cb1: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5f8cb3: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5f8cb7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8cb8: e8f3271600 CALL 0x0075b4b0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x5f8cbd: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f8cbe: e8b8491700 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x5f8cc3: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5f8cc6: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x5f8cc8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f8cc9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f8cca: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5f8ccb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5f8ccc: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001fd8a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5fd8a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fd8a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5fd8a3: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x5fd8a6: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x5fd8a9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5fd8ab: 7c28 JL 0x005fd8d5
    if(integer::condition("JL",flags)) goto L005fd8d5;
  }
  { // 0x5fd8ad: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x5fd8b0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5fd8b2: 7504 JNZ 0x005fd8b8
    if(integer::condition("JNZ",flags)) goto L005fd8b8;
  }
  { // 0x5fd8b4: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5fd8b6: 7517 JNZ 0x005fd8cf
    if(integer::condition("JNZ",flags)) goto L005fd8cf;
  }
  L005fd8b8: { // 0x5fd8b8: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x5fd8bb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5fd8bd: 7e10 JLE 0x005fd8cf
    if(integer::condition("JLE",flags)) goto L005fd8cf;
  }
  { // 0x5fd8bf: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5fd8c1: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x5fd8c3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5fd8c5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5fd8c6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5fd8c8: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5fd8cb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5fd8cd: 7506 JNZ 0x005fd8d5
    if(integer::condition("JNZ",flags)) goto L005fd8d5;
  }
  L005fd8cf: { // 0x5fd8cf: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x5fd8d1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fd8d2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L005fd8d5: { // 0x5fd8d5: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x5fd8d8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5fd8d9: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x5fd8db: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x5fd8df: c1e206 SHL EDX,0x6
    s.dx = integer::shift(s.dx,0x00000006u,32,flags,integer::Shift::left);
  }
  { // 0x5fd8e2: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  { // 0x5fd8e5: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x5fd8e7: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x5fd8ea: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x5fd8ed: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5fd8ee: 8d3490 LEA ESI,[EAX + EDX*0x4]
    s.si = (s.ax+(s.dx * 0x00000004u));
  }
  { // 0x5fd8f1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5fd8f3: e8582feeff CALL 0x004e0850
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5fd8f8: 8b8f00010000 MOV ECX,dword ptr [EDI + 0x100]
    s.cx = m.r32((s.di+0x00000100u));
  }
  { // 0x5fd8fe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fd8ff: 898e00010000 MOV dword ptr [ESI + 0x100],ECX
    m.w32((s.si+0x00000100u), s.cx);
  }
  { // 0x5fd905: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x5fd907: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fd908: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00206680(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x606680: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x606681: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x606685: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x606686: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x606688: 397704 CMP dword ptr [EDI + 0x4],ESI
    (void)integer::sub(m.r32((s.di+0x00000004u)),s.si,32,flags);
  }
  { // 0x60668b: 7439 JZ 0x006066c6
    if(integer::condition("JZ",flags)) goto L006066c6;
  }
  { // 0x60668d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x60668f: 7415 JZ 0x006066a6
    if(integer::condition("JZ",flags)) goto L006066a6;
  }
  { // 0x606691: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x606694: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x606696: 740e JZ 0x006066a6
    if(integer::condition("JZ",flags)) goto L006066a6;
  }
  { // 0x606698: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x60669a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x60669c: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x60669f: c7460800000000 MOV dword ptr [ESI + 0x8],0x0
    m.w32((s.si+0x00000008u), 0x00000000u);
  }
  L006066a6: { // 0x6066a6: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x6066a9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6066ab: 740f JZ 0x006066bc
    if(integer::condition("JZ",flags)) goto L006066bc;
  }
  { // 0x6066ad: c7400800000000 MOV dword ptr [EAX + 0x8],0x0
    m.w32((s.ax+0x00000008u), 0x00000000u);
  }
  { // 0x6066b4: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  { // 0x6066b7: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x6066b9: ff5204 CALL dword ptr [EDX + 0x4]
    const std::uint32_t call_target=m.r32((s.dx+0x00000004u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L006066bc: { // 0x6066bc: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6066be: 897704 MOV dword ptr [EDI + 0x4],ESI
    m.w32((s.di+0x00000004u), s.si);
  }
  { // 0x6066c1: 7403 JZ 0x006066c6
    if(integer::condition("JZ",flags)) goto L006066c6;
  }
  { // 0x6066c3: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L006066c6: { // 0x6066c6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6066c7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6066c8: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00208810(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x608810: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x608811: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x608813: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x608817: e884e10b00 CALL 0x006c69a0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x60881c: 8d4804 LEA ECX,[EAX + 0x4]
    s.cx = (s.ax+0x00000004u);
  }
  { // 0x60881f: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x608823: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x608824: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  { // 0x608828: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x60882a: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x60882d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x60882e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00209b40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x609b40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x609b41: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x609b42: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x609b44: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x609b48: e853ce0b00 CALL 0x006c69a0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x609b4d: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x609b4f: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x609b52: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x609b56: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  { // 0x609b5a: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x609b5d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x609b5e: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x609b61: 8b9694000000 MOV EDX,dword ptr [ESI + 0x94]
    s.dx = m.r32((s.si+0x00000094u));
  }
  { // 0x609b67: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x609b69: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x609b6b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x609b6c: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x609b6f: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  { // 0x609b71: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x609b72: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0020c340(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x60c340: a0fce2a500 MOV AL,[0x00a5e2fc]
    s.ax = with_al(s.ax, m.r8((0x00a5e2fcu)));
  }
  { // 0x60c345: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x60c347: 7538 JNZ 0x0060c381
    if(integer::condition("JNZ",flags)) goto L0060c381;
  }
  { // 0x60c349: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  { // 0x60c34e: c605fce2a50001 MOV byte ptr [0x00a5e2fc],0x1
    m.w8((0x00a5e2fcu), 0x00000001u);
  }
  { // 0x60c355: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x60c357: ba00200000 MOV EDX,0x2000
    s.dx = 0x00002000u;
  }
  { // 0x60c35c: 8b88cc010000 MOV ECX,dword ptr [EAX + 0x1cc]
    s.cx = m.r32((s.ax+0x000001ccu));
  }
  { // 0x60c362: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  { // 0x60c367: e804c60f00 CALL 0x00708970
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x60c36c: 8b0dd8e1a500 MOV ECX,dword ptr [0x00a5e1d8]
    s.cx = m.r32((0x00a5e1d8u));
  }
  { // 0x60c372: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x60c374: 740b JZ 0x0060c381
    if(integer::condition("JZ",flags)) goto L0060c381;
  }
  { // 0x60c376: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x60c378: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x60c37a: 68c7110000 PUSH 0x11c7
    f.push(m,0x000011c7u);
  }
  { // 0x60c37f: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0060c381: { // 0x60c381: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0020d5f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x60d5f0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x60d5f3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x60d5f4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x60d5f6: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x60d5f8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x60d5f9: 744f JZ 0x0060d64a
    if(integer::condition("JZ",flags)) goto L0060d64a;
  }
  { // 0x60d5fb: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x60d5fd: ff906c010000 CALL dword ptr [EAX + 0x16c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000016cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x60d603: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x60d605: 83ff05 CMP EDI,0x5
    (void)integer::sub(s.di,0x00000005u,32,flags);
  }
  { // 0x60d608: 7508 JNZ 0x0060d612
    if(integer::condition("JNZ",flags)) goto L0060d612;
  }
  { // 0x60d60a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x60d60b: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x60d60d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x60d60e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x60d611: c3 RET
    finish(m,s,f,0u); return;
  }
  L0060d612: { // 0x60d612: 8b8e28020000 MOV ECX,dword ptr [ESI + 0x228]
    s.cx = m.r32((s.si+0x00000228u));
  }
  { // 0x60d618: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x60d619: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x60d61d: e8ced40900 CALL 0x006aaaf0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x60d622: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x60d624: 83ff01 CMP EDI,0x1
    (void)integer::sub(s.di,0x00000001u,32,flags);
  }
  { // 0x60d627: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  { // 0x60d62b: 8a4004 MOV AL,byte ptr [EAX + 0x4]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000004u)));
  }
  { // 0x60d62e: 7405 JZ 0x0060d635
    if(integer::condition("JZ",flags)) goto L0060d635;
  }
  { // 0x60d630: 83ff0b CMP EDI,0xb
    (void)integer::sub(s.di,0x0000000bu,32,flags);
  }
  { // 0x60d633: 7515 JNZ 0x0060d64a
    if(integer::condition("JNZ",flags)) goto L0060d64a;
  }
  L0060d635: { // 0x60d635: 3c0b CMP AL,0xb
    (void)integer::sub((s.ax & 0xffu),0x0000000bu,8,flags);
  }
  { // 0x60d637: 7409 JZ 0x0060d642
    if(integer::condition("JZ",flags)) goto L0060d642;
  }
  { // 0x60d639: 83ff0b CMP EDI,0xb
    (void)integer::sub(s.di,0x0000000bu,32,flags);
  }
  { // 0x60d63c: 750c JNZ 0x0060d64a
    if(integer::condition("JNZ",flags)) goto L0060d64a;
  }
  { // 0x60d63e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x60d640: 7508 JNZ 0x0060d64a
    if(integer::condition("JNZ",flags)) goto L0060d64a;
  }
  L0060d642: { // 0x60d642: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x60d643: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x60d645: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x60d646: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x60d649: c3 RET
    finish(m,s,f,0u); return;
  }
  L0060d64a: { // 0x60d64a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x60d64b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x60d64d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x60d64e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x60d651: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002113f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6113f0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x6113f3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6113f4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6113f5: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6113f7: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x6113fb: e86071ffff CALL 0x00608560
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x611400: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x611402: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x611404: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x611407: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  { // 0x61140a: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  { // 0x61140d: 7524 JNZ 0x00611433
    if(integer::condition("JNZ",flags)) goto L00611433;
  }
  { // 0x61140f: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x611411: 7520 JNZ 0x00611433
    if(integer::condition("JNZ",flags)) goto L00611433;
  }
  { // 0x611413: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x611415: 751c JNZ 0x00611433
    if(integer::condition("JNZ",flags)) goto L00611433;
  }
  { // 0x611417: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x61141b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x61141d: 7414 JZ 0x00611433
    if(integer::condition("JZ",flags)) goto L00611433;
  }
  { // 0x61141f: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x611421: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  { // 0x611425: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x611426: ff5258 CALL dword ptr [EDX + 0x58]
    const std::uint32_t call_target=m.r32((s.dx+0x00000058u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x611429: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x61142b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x61142d: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  { // 0x611430: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L00611433: { // 0x611433: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x611435: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  { // 0x611437: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x611439: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x61143a: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  { // 0x61143d: 897108 MOV dword ptr [ECX + 0x8],ESI
    m.w32((s.cx+0x00000008u), s.si);
  }
  { // 0x611440: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x611441: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x611444: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00211d70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x611d70: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  { // 0x611d73: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x611d74: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x611d76: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x611d77: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x611d7b: e890520d00 CALL 0x006e7010
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x611d80: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x611d82: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  { // 0x611d86: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x611d87: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x611d8a: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  { // 0x611d8e: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  { // 0x611d91: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  { // 0x611d95: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  { // 0x611d99: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  { // 0x611d9c: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  { // 0x611da0: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  { // 0x611da4: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  { // 0x611da8: ba06000000 MOV EDX,0x6
    s.dx = 0x00000006u;
  }
  { // 0x611dad: 83c1fd ADD ECX,-0x3
    s.cx = integer::add(s.cx,0xfffffffdu,32,flags);
  }
  { // 0x611db0: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x611db2: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  { // 0x611db6: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  { // 0x611dba: 8b0da41c8200 MOV ECX,dword ptr [0x00821ca4]
    s.cx = m.r32((0x00821ca4u));
  }
  { // 0x611dc0: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  { // 0x611dc4: 83e803 SUB EAX,0x3
    s.ax = integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x611dc7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x611dc8: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  { // 0x611dcc: 897c242c MOV dword ptr [ESP + 0x2c],EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  { // 0x611dd0: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x611dd2: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  { // 0x611dd6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x611dd7: ff5054 CALL dword ptr [EAX + 0x54]
    const std::uint32_t call_target=m.r32((s.ax+0x00000054u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x611dda: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x611ddb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x611ddc: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  { // 0x611ddf: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00211df0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x611df0: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  { // 0x611df3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x611df4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x611df6: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x611df7: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x611dfb: e810520d00 CALL 0x006e7010
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x611e00: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x611e02: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  { // 0x611e06: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x611e07: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x611e0a: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  { // 0x611e0e: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  { // 0x611e11: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  { // 0x611e15: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  { // 0x611e19: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  { // 0x611e1c: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  { // 0x611e20: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  { // 0x611e24: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  { // 0x611e28: ba06000000 MOV EDX,0x6
    s.dx = 0x00000006u;
  }
  { // 0x611e2d: 83c1fd ADD ECX,-0x3
    s.cx = integer::add(s.cx,0xfffffffdu,32,flags);
  }
  { // 0x611e30: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x611e32: 83e803 SUB EAX,0x3
    s.ax = integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x611e35: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  { // 0x611e39: 83ea02 SUB EDX,0x2
    s.dx = integer::sub(s.dx,0x00000002u,32,flags);
  }
  { // 0x611e3c: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x611e3d: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  { // 0x611e41: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  { // 0x611e45: 8b0da41c8200 MOV ECX,dword ptr [0x00821ca4]
    s.cx = m.r32((0x00821ca4u));
  }
  { // 0x611e4b: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  { // 0x611e4f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x611e50: 83ef02 SUB EDI,0x2
    s.di = integer::sub(s.di,0x00000002u,32,flags);
  }
  { // 0x611e53: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x611e54: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  { // 0x611e58: 897c242c MOV dword ptr [ESP + 0x2c],EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  { // 0x611e5c: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x611e5e: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  { // 0x611e62: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x611e63: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x611e66: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x611e67: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x611e68: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  { // 0x611e6b: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00216960(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x616960: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x616964: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x616965: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x616966: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x616968: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x61696c: 894648 MOV dword ptr [ESI + 0x48],EAX
    m.w32((s.si+0x00000048u), s.ax);
  }
  { // 0x61696f: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x616973: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x616976: 894e4c MOV dword ptr [ESI + 0x4c],ECX
    m.w32((s.si+0x0000004cu), s.cx);
  }
  { // 0x616979: 7f05 JG 0x00616980
    if(integer::condition("JG",flags)) goto L00616980;
  }
  { // 0x61697b: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00616980: { // 0x616980: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x616982: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x616984: 3ac3 CMP AL,BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  { // 0x616986: 884661 MOV byte ptr [ESI + 0x61],AL
    m.w8((s.si+0x00000061u), (s.ax & 0xffu));
  }
  { // 0x616989: 7e14 JLE 0x0061699f
    if(integer::condition("JLE",flags)) goto L0061699f;
  }
  { // 0x61698b: 8d4608 LEA EAX,[ESI + 0x8]
    s.ax = (s.si+0x00000008u);
  }
  L0061698e: { // 0x61698e: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  { // 0x616990: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
  { // 0x616993: 0fbe5661 MOVSX EDX,byte ptr [ESI + 0x61]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x00000061u)),8));
  }
  { // 0x616997: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x616998: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  { // 0x61699b: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x61699d: 7cef JL 0x0061698e
    if(integer::condition("JL",flags)) goto L0061698e;
  }
  L0061699f: { // 0x61699f: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x6169a3: c6466001 MOV byte ptr [ESI + 0x60],0x1
    m.w8((s.si+0x00000060u), 0x00000001u);
  }
  { // 0x6169a7: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x6169a9: 7412 JZ 0x006169bd
    if(integer::condition("JZ",flags)) goto L006169bd;
  }
  { // 0x6169ab: 894664 MOV dword ptr [ESI + 0x64],EAX
    m.w32((s.si+0x00000064u), s.ax);
  }
  { // 0x6169ae: 895e50 MOV dword ptr [ESI + 0x50],EBX
    m.w32((s.si+0x00000050u), s.bx);
  }
  { // 0x6169b1: c7467cffffffff MOV dword ptr [ESI + 0x7c],0xffffffff
    m.w32((s.si+0x0000007cu), 0xffffffffu);
  }
  { // 0x6169b8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6169b9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6169ba: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L006169bd: { // 0x6169bd: 8b0d941c8200 MOV ECX,dword ptr [0x00821c94]
    s.cx = m.r32((0x00821c94u));
  }
  { // 0x6169c3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6169c4: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x6169c6: ff5018 CALL dword ptr [EAX + 0x18]
    const std::uint32_t call_target=m.r32((s.ax+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6169c9: 895e50 MOV dword ptr [ESI + 0x50],EBX
    m.w32((s.si+0x00000050u), s.bx);
  }
  { // 0x6169cc: c7467cffffffff MOV dword ptr [ESI + 0x7c],0xffffffff
    m.w32((s.si+0x0000007cu), 0xffffffffu);
  }
  { // 0x6169d3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6169d4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6169d5: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_00216d70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x616d70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x616d71: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x616d73: e8d89debff CALL 0x004d0b50
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x616d78: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x616d7a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x616d7c: 7510 JNZ 0x00616d8e
    if(integer::condition("JNZ",flags)) goto L00616d8e;
  }
  { // 0x616d7e: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x616d82: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x616d86: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  { // 0x616d88: 8931 MOV dword ptr [ECX],ESI
    m.w32((s.cx), s.si);
  }
  { // 0x616d8a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x616d8b: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00616d8e: { // 0x616d8e: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x616d90: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x616d92: ff527c CALL dword ptr [EDX + 0x7c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000007cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x616d95: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x616d99: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  { // 0x616d9b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x616d9d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x616d9f: ff9280000000 CALL dword ptr [EDX + 0x80]
    const std::uint32_t call_target=m.r32((s.dx+0x00000080u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x616da5: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x616da9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x616daa: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  { // 0x616dac: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002268f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6268f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6268f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6268f3: e8c820e7ff CALL 0x004989c0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6268f8: 680c7f7d00 PUSH 0x7d7f0c
    f.push(m,0x007d7f0cu);
  }
  { // 0x6268fd: e8eeffddff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x626902: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x626904: 8d8e20120000 LEA ECX,[ESI + 0x1220]
    s.cx = (s.si+0x00001220u);
  }
  { // 0x62690a: 8986a8140000 MOV dword ptr [ESI + 0x14a8],EAX
    m.w32((s.si+0x000014a8u), s.ax);
  }
  { // 0x626910: 8986ac140000 MOV dword ptr [ESI + 0x14ac],EAX
    m.w32((s.si+0x000014acu), s.ax);
  }
  { // 0x626916: 8886b9140000 MOV byte ptr [ESI + 0x14b9],AL
    m.w8((s.si+0x000014b9u), (s.ax & 0xffu));
  }
  { // 0x62691c: 8886b8140000 MOV byte ptr [ESI + 0x14b8],AL
    m.w8((s.si+0x000014b8u), (s.ax & 0xffu));
  }
  { // 0x626922: 8986f8140000 MOV dword ptr [ESI + 0x14f8],EAX
    m.w32((s.si+0x000014f8u), s.ax);
  }
  { // 0x626928: 8886d4140000 MOV byte ptr [ESI + 0x14d4],AL
    m.w8((s.si+0x000014d4u), (s.ax & 0xffu));
  }
  { // 0x62692e: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x626930: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x626933: c686d514000001 MOV byte ptr [ESI + 0x14d5],0x1
    m.w8((s.si+0x000014d5u), 0x00000001u);
  }
  { // 0x62693a: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x62693d: 8b9658120000 MOV EDX,dword ptr [ESI + 0x1258]
    s.dx = m.r32((s.si+0x00001258u));
  }
  { // 0x626943: 8d8e58120000 LEA ECX,[ESI + 0x1258]
    s.cx = (s.si+0x00001258u);
  }
  { // 0x626949: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x62694c: 68ec7e7d00 PUSH 0x7d7eec
    f.push(m,0x007d7eecu);
  }
  { // 0x626951: e89affddff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x626956: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x626959: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x62695a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00226960(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x626960: 8a442404 MOV AL,byte ptr [ESP + 0x4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000004u)));
  }
  { // 0x626964: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x626965: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x626967: 6830dfa900 PUSH 0xa9df30
    f.push(m,0x00a9df30u);
  }
  { // 0x62696c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x62696e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x626970: 7413 JZ 0x00626985
    if(integer::condition("JZ",flags)) goto L00626985;
  }
  { // 0x626972: ff5030 CALL dword ptr [EAX + 0x30]
    const std::uint32_t call_target=m.r32((s.ax+0x00000030u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x626975: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x626977: 68c8dea900 PUSH 0xa9dec8
    f.push(m,0x00a9dec8u);
  }
  { // 0x62697c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x62697e: ff5230 CALL dword ptr [EDX + 0x30]
    const std::uint32_t call_target=m.r32((s.dx+0x00000030u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x626981: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x626982: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00626985: { // 0x626985: ff5034 CALL dword ptr [EAX + 0x34]
    const std::uint32_t call_target=m.r32((s.ax+0x00000034u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x626988: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x62698a: 68c8dea900 PUSH 0xa9dec8
    f.push(m,0x00a9dec8u);
  }
  { // 0x62698f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x626991: ff5234 CALL dword ptr [EDX + 0x34]
    const std::uint32_t call_target=m.r32((s.dx+0x00000034u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x626994: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x626995: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0022e100(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x62e100: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x62e101: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x62e103: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  { // 0x62e106: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x62e108: 750a JNZ 0x0062e114
    if(integer::condition("JNZ",flags)) goto L0062e114;
  }
  { // 0x62e10a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x62e10c: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x62e10e: ff9060020000 CALL dword ptr [EAX + 0x260]
    const std::uint32_t call_target=m.r32((s.ax+0x00000260u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0062e114: { // 0x62e114: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x62e116: e875dcf9ff CALL 0x005cbd90
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x62e11b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x62e11c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0022f9b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x62f9b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x62f9b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x62f9b3: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x62f9b6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x62f9b8: 7437 JZ 0x0062f9f1
    if(integer::condition("JZ",flags)) goto L0062f9f1;
  }
  { // 0x62f9ba: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x62f9bc: ff5018 CALL dword ptr [EAX + 0x18]
    const std::uint32_t call_target=m.r32((s.ax+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x62f9bf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x62f9c1: 752e JNZ 0x0062f9f1
    if(integer::condition("JNZ",flags)) goto L0062f9f1;
  }
  { // 0x62f9c3: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x62f9c7: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  { // 0x62f9ce: 894614 MOV dword ptr [ESI + 0x14],EAX
    m.w32((s.si+0x00000014u), s.ax);
  }
  { // 0x62f9d1: 83e802 SUB EAX,0x2
    s.ax = integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x62f9d4: c6461801 MOV byte ptr [ESI + 0x18],0x1
    m.w8((s.si+0x00000018u), 0x00000001u);
  }
  { // 0x62f9d8: 7507 JNZ 0x0062f9e1
    if(integer::condition("JNZ",flags)) goto L0062f9e1;
  }
  { // 0x62f9da: c7460c00000000 MOV dword ptr [ESI + 0xc],0x0
    m.w32((s.si+0x0000000cu), 0x00000000u);
  }
  L0062f9e1: { // 0x62f9e1: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x62f9e3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x62f9e5: ff5218 CALL dword ptr [EDX + 0x18]
    const std::uint32_t call_target=m.r32((s.dx+0x00000018u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x62f9e8: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x62f9ed: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x62f9ee: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0062f9f1: { // 0x62f9f1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x62f9f3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x62f9f4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0022fa00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x62fa00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x62fa01: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x62fa02: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x62fa03: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x62fa05: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x62fa06: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x62fa09: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x62fa0b: 7468 JZ 0x0062fa75
    if(integer::condition("JZ",flags)) goto L0062fa75;
  }
  { // 0x62fa0d: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  { // 0x62fa11: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  { // 0x62fa13: 7460 JZ 0x0062fa75
    if(integer::condition("JZ",flags)) goto L0062fa75;
  }
  { // 0x62fa15: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  { // 0x62fa19: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x62fa1b: 7458 JZ 0x0062fa75
    if(integer::condition("JZ",flags)) goto L0062fa75;
  }
  { // 0x62fa1d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x62fa1f: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  { // 0x62fa21: ff5018 CALL dword ptr [EAX + 0x18]
    const std::uint32_t call_target=m.r32((s.ax+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x62fa24: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x62fa26: 750d JNZ 0x0062fa35
    if(integer::condition("JNZ",flags)) goto L0062fa35;
  }
  { // 0x62fa28: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x62fa2a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x62fa2c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x62fa2e: ff521c CALL dword ptr [EDX + 0x1c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000001cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x62fa31: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  { // 0x62fa33: eb06 JMP 0x0062fa3b
    goto L0062fa3b;
  }
  L0062fa35: { // 0x62fa35: f6461401 TEST byte ptr [ESI + 0x14],0x1
    (void)integer::logical((m.r8((s.si+0x00000014u)))&(0x00000001u),8,flags);
  }
  { // 0x62fa39: 743a JZ 0x0062fa75
    if(integer::condition("JZ",flags)) goto L0062fa75;
  }
  L0062fa3b: { // 0x62fa3b: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x62fa3e: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x62fa41: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x62fa43: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x62fa45: 7c02 JL 0x0062fa49
    if(integer::condition("JL",flags)) goto L0062fa49;
  }
  { // 0x62fa47: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0062fa49: { // 0x62fa49: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x62fa4c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x62fa4d: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x62fa4f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x62fa50: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x62fa51: e87af11300 CALL 0x0076ebd0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x62fa56: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x62fa59: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x62fa5c: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  { // 0x62fa5e: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x62fa60: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x62fa63: 7407 JZ 0x0062fa6c
    if(integer::condition("JZ",flags)) goto L0062fa6c;
  }
  { // 0x62fa65: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x62fa67: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x62fa69: ff5034 CALL dword ptr [EAX + 0x34]
    const std::uint32_t call_target=m.r32((s.ax+0x00000034u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L0062fa6c: { // 0x62fa6c: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x62fa6e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x62fa6f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x62fa70: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x62fa71: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x62fa72: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0062fa75: { // 0x62fa75: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x62fa76: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x62fa77: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x62fa78: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x62fa7a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x62fa7b: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00230060(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x630060: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x630061: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x630063: c706843c7900 MOV dword ptr [ESI],0x793c84
    m.w32((s.si), 0x00793c84u);
  }
  { // 0x630069: ff159c3c7900 CALL dword ptr [0x00793c9c]
    const std::uint32_t call_target=m.r32((0x00793c9cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x63006f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x630071: 742a JZ 0x0063009d
    if(integer::condition("JZ",flags)) goto L0063009d;
  }
  { // 0x630073: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x630076: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x630077: ff15d4517800 CALL dword ptr [0x007851d4]
    const std::uint32_t call_target=m.r32((0x007851d4u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x63007d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x63007f: 7515 JNZ 0x00630096
    if(integer::condition("JNZ",flags)) goto L00630096;
  }
  { // 0x630081: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x630084: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x630085: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x630087: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x630088: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x630089: ff15f4517800 CALL dword ptr [0x007851f4]
    const std::uint32_t call_target=m.r32((0x007851f4u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x63008f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x630090: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x630092: ff5740 CALL dword ptr [EDI + 0x40]
    const std::uint32_t call_target=m.r32((s.di+0x00000040u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x630095: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00630096: { // 0x630096: c74610ffffffff MOV dword ptr [ESI + 0x10],0xffffffff
    m.w32((s.si+0x00000010u), 0xffffffffu);
  }
  L0063009d: { // 0x63009d: 8a461c MOV AL,byte ptr [ESI + 0x1c]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000001cu)));
  }
  { // 0x6300a0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6300a2: 741b JZ 0x006300bf
    if(integer::condition("JZ",flags)) goto L006300bf;
  }
  { // 0x6300a4: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x6300a7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6300a9: 7414 JZ 0x006300bf
    if(integer::condition("JZ",flags)) goto L006300bf;
  }
  { // 0x6300ab: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6300ac: e877de1300 CALL 0x0076df28
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x6300b1: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6300b4: c7461400000000 MOV dword ptr [ESI + 0x14],0x0
    m.w32((s.si+0x00000014u), 0x00000000u);
  }
  { // 0x6300bb: c6461c00 MOV byte ptr [ESI + 0x1c],0x0
    m.w8((s.si+0x0000001cu), 0x00000000u);
  }
  L006300bf: { // 0x6300bf: c7063c3c7900 MOV dword ptr [ESI],0x793c3c
    m.w32((s.si), 0x00793c3cu);
  }
  { // 0x6300c5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6300c6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00230110(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x630110: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x630111: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x630113: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x630114: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x630117: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x630119: 741b JZ 0x00630136
    if(integer::condition("JZ",flags)) goto L00630136;
  }
  { // 0x63011b: 8a4e1c MOV CL,byte ptr [ESI + 0x1c]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000001cu)));
  }
  { // 0x63011e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x630120: 7414 JZ 0x00630136
    if(integer::condition("JZ",flags)) goto L00630136;
  }
  { // 0x630122: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x630123: e800de1300 CALL 0x0076df28
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x630128: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x63012b: c7461400000000 MOV dword ptr [ESI + 0x14],0x0
    m.w32((s.si+0x00000014u), 0x00000000u);
  }
  { // 0x630132: c6461c00 MOV byte ptr [ESI + 0x1c],0x0
    m.w8((s.si+0x0000001cu), 0x00000000u);
  }
  L00630136: { // 0x630136: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x63013a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x63013c: 7507 JNZ 0x00630145
    if(integer::condition("JNZ",flags)) goto L00630145;
  }
  { // 0x63013e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x63013f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x630141: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x630142: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00630145: { // 0x630145: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x630146: c7460800000000 MOV dword ptr [ESI + 0x8],0x0
    m.w32((s.si+0x00000008u), 0x00000000u);
  }
  { // 0x63014d: c7460cffffffff MOV dword ptr [ESI + 0xc],0xffffffff
    m.w32((s.si+0x0000000cu), 0xffffffffu);
  }
  { // 0x630154: e8ed8f1400 CALL 0x00779146
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x630159: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x63015c: 894614 MOV dword ptr [ESI + 0x14],EAX
    m.w32((s.si+0x00000014u), s.ax);
  }
  { // 0x63015f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x630161: 7513 JNZ 0x00630176
    if(integer::condition("JNZ",flags)) goto L00630176;
  }
  { // 0x630163: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x630165: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x630166: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x630168: 6a0c PUSH 0xc
    f.push(m,0x0000000cu);
  }
  { // 0x63016a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x63016c: ff5040 CALL dword ptr [EAX + 0x40]
    const std::uint32_t call_target=m.r32((s.ax+0x00000040u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x63016f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x630170: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x630172: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x630173: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00630176: { // 0x630176: c6461c01 MOV byte ptr [ESI + 0x1c],0x1
    m.w8((s.si+0x0000001cu), 0x00000001u);
  }
  { // 0x63017a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x63017b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x63017c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00230180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x630180: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x630181: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x630183: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x630187: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x630189: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x63018a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x63018c: ff5008 CALL dword ptr [EAX + 0x8]
    const std::uint32_t call_target=m.r32((s.ax+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x63018f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x630193: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x630195: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x630196: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x630198: ff521c CALL dword ptr [EDX + 0x1c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000001cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x63019b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x63019c: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002302f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6302f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6302f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6302f3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6302f5: ff5018 CALL dword ptr [EAX + 0x18]
    const std::uint32_t call_target=m.r32((s.ax+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6302f8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6302fa: 742a JZ 0x00630326
    if(integer::condition("JZ",flags)) goto L00630326;
  }
  { // 0x6302fc: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x6302ff: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x630300: ff15d4517800 CALL dword ptr [0x007851d4]
    const std::uint32_t call_target=m.r32((0x007851d4u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x630306: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x630308: 7515 JNZ 0x0063031f
    if(integer::condition("JNZ",flags)) goto L0063031f;
  }
  { // 0x63030a: 8b5614 MOV EDX,dword ptr [ESI + 0x14]
    s.dx = m.r32((s.si+0x00000014u));
  }
  { // 0x63030d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x63030e: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x630310: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x630311: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x630312: ff15f4517800 CALL dword ptr [0x007851f4]
    const std::uint32_t call_target=m.r32((0x007851f4u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x630318: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x630319: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x63031b: ff5740 CALL dword ptr [EDI + 0x40]
    const std::uint32_t call_target=m.r32((s.di+0x00000040u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x63031e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0063031f: { // 0x63031f: c74610ffffffff MOV dword ptr [ESI + 0x10],0xffffffff
    m.w32((s.si+0x00000010u), 0xffffffffu);
  }
  L00630326: { // 0x630326: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x630327: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00230720(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x630720: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x630721: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x630723: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x630724: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x630726: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x630729: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x63072c: 7565 JNZ 0x00630793
    if(integer::condition("JNZ",flags)) goto L00630793;
  }
  { // 0x63072e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x630730: ff5018 CALL dword ptr [EAX + 0x18]
    const std::uint32_t call_target=m.r32((s.ax+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x630733: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x630735: 7435 JZ 0x0063076c
    if(integer::condition("JZ",flags)) goto L0063076c;
  }
  { // 0x630737: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x63073a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x63073b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x63073c: ff1514517800 CALL dword ptr [0x00785114]
    const std::uint32_t call_target=m.r32((0x00785114u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x630742: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x630744: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  { // 0x630747: 7540 JNZ 0x00630789
    if(integer::condition("JNZ",flags)) goto L00630789;
  }
  { // 0x630749: 8b5614 MOV EDX,dword ptr [ESI + 0x14]
    s.dx = m.r32((s.si+0x00000014u));
  }
  { // 0x63074c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x63074d: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  { // 0x63074f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x630750: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x630752: ff15f4517800 CALL dword ptr [0x007851f4]
    const std::uint32_t call_target=m.r32((0x007851f4u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x630758: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x630759: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x63075b: ff5340 CALL dword ptr [EBX + 0x40]
    const std::uint32_t call_target=m.r32((s.bx+0x00000040u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x63075e: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x630761: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x630763: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x630765: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x630766: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  { // 0x630769: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x63076a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x63076b: c3 RET
    finish(m,s,f,0u); return;
  }
  L0063076c: { // 0x63076c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x63076e: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x630770: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x630772: ff501c CALL dword ptr [EAX + 0x1c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000001cu));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x630775: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x630777: 7410 JZ 0x00630789
    if(integer::condition("JZ",flags)) goto L00630789;
  }
  { // 0x630779: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x63077b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x63077d: ff522c CALL dword ptr [EDX + 0x2c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000002cu));
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x630780: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x630782: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x630784: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x630786: ff5034 CALL dword ptr [EAX + 0x34]
    const std::uint32_t call_target=m.r32((s.ax+0x00000034u));
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  L00630789: { // 0x630789: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x63078c: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x63078e: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x630790: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00630793: { // 0x630793: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x630794: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x630795: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002307a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6307a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6307a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6307a3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6307a5: ff5034 CALL dword ptr [EAX + 0x34]
    const std::uint32_t call_target=m.r32((s.ax+0x00000034u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6307a8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6307aa: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x6307ac: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6307ae: ff521c CALL dword ptr [EDX + 0x1c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000001cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6307b1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6307b3: 741f JZ 0x006307d4
    if(integer::condition("JZ",flags)) goto L006307d4;
  }
  { // 0x6307b5: 837e0cff CMP dword ptr [ESI + 0xc],-0x1
    (void)integer::sub(m.r32((s.si+0x0000000cu)),0xffffffffu,32,flags);
  }
  { // 0x6307b9: 740b JZ 0x006307c6
    if(integer::condition("JZ",flags)) goto L006307c6;
  }
  { // 0x6307bb: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6307bd: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6307bf: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6307c1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6307c3: ff5028 CALL dword ptr [EAX + 0x28]
    const std::uint32_t call_target=m.r32((s.ax+0x00000028u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L006307c6: { // 0x6307c6: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6307c8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6307ca: ff5234 CALL dword ptr [EDX + 0x34]
    const std::uint32_t call_target=m.r32((s.dx+0x00000034u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6307cd: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x6307d2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6307d3: c3 RET
    finish(m,s,f,0u); return;
  }
  L006307d4: { // 0x6307d4: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6307d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6307d7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002307e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6307e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6307e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6307e3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6307e5: ff5034 CALL dword ptr [EAX + 0x34]
    const std::uint32_t call_target=m.r32((s.ax+0x00000034u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6307e8: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x6307eb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6307ed: 7511 JNZ 0x00630800
    if(integer::condition("JNZ",flags)) goto L00630800;
  }
  { // 0x6307ef: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6307f1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6307f3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6307f5: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x6307f7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6307f9: ff5240 CALL dword ptr [EDX + 0x40]
    const std::uint32_t call_target=m.r32((s.dx+0x00000040u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6307fc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6307fe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6307ff: c3 RET
    finish(m,s,f,0u); return;
  }
  L00630800: { // 0x630800: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x630802: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x630804: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x630806: ff5014 CALL dword ptr [EAX + 0x14]
    const std::uint32_t call_target=m.r32((s.ax+0x00000014u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x630809: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x63080b: 7504 JNZ 0x00630811
    if(integer::condition("JNZ",flags)) goto L00630811;
  }
  { // 0x63080d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x63080f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x630810: c3 RET
    finish(m,s,f,0u); return;
  }
  L00630811: { // 0x630811: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x630814: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x630815: ff15cc507800 CALL dword ptr [0x007850cc]
    const std::uint32_t call_target=m.r32((0x007850ccu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x63081b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x63081d: 7519 JNZ 0x00630838
    if(integer::condition("JNZ",flags)) goto L00630838;
  }
  { // 0x63081f: 8b5614 MOV EDX,dword ptr [ESI + 0x14]
    s.dx = m.r32((s.si+0x00000014u));
  }
  { // 0x630822: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x630823: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x630825: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x630826: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x630827: ff15f4517800 CALL dword ptr [0x007851f4]
    const std::uint32_t call_target=m.r32((0x007851f4u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x63082d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x63082e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x630830: ff5740 CALL dword ptr [EDI + 0x40]
    const std::uint32_t call_target=m.r32((s.di+0x00000040u));
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x630833: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x630834: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x630836: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x630837: c3 RET
    finish(m,s,f,0u); return;
  }
  L00630838: { // 0x630838: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x63083d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x63083e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00230840(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x630840: 8b4910 MOV ECX,dword ptr [ECX + 0x10]
    s.cx = m.r32((s.cx+0x00000010u));
  }
  { // 0x630843: 83ec3c SUB ESP,0x3c
    f.sp = integer::sub(f.sp,0x0000003cu,32,flags);
  }
  { // 0x630846: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  { // 0x63084a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x63084b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x63084c: ff151c517800 CALL dword ptr [0x0078511c]
    const std::uint32_t call_target=m.r32((0x0078511cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x630852: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x630854: 7431 JZ 0x00630887
    if(integer::condition("JZ",flags)) goto L00630887;
  }
  { // 0x630856: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  { // 0x63085a: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x63085e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x63085f: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  { // 0x630863: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x630864: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x630865: ff1518517800 CALL dword ptr [0x00785118]
    const std::uint32_t call_target=m.r32((0x00785118u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x63086b: 8b442400 MOV EAX,dword ptr [ESP]
    s.ax = m.r32((f.sp));
  }
  { // 0x63086f: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x630873: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  { // 0x630878: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  { // 0x63087e: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  { // 0x630881: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  { // 0x630883: 83c43c ADD ESP,0x3c
    f.sp = integer::add(f.sp,0x0000003cu,32,flags);
  }
  { // 0x630886: c3 RET
    finish(m,s,f,0u); return;
  }
  L00630887: { // 0x630887: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x630889: 83c43c ADD ESP,0x3c
    f.sp = integer::add(f.sp,0x0000003cu,32,flags);
  }
  { // 0x63088c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00230890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x630890: 83ec3c SUB ESP,0x3c
    f.sp = integer::sub(f.sp,0x0000003cu,32,flags);
  }
  { // 0x630893: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x630894: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x630896: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x630899: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x63089c: 744e JZ 0x006308ec
    if(integer::condition("JZ",flags)) goto L006308ec;
  }
  { // 0x63089e: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x6308a2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6308a3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6308a4: ff151c517800 CALL dword ptr [0x0078511c]
    const std::uint32_t call_target=m.r32((0x0078511cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6308aa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6308ac: 743e JZ 0x006308ec
    if(integer::condition("JZ",flags)) goto L006308ec;
  }
  { // 0x6308ae: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  { // 0x6308b2: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  { // 0x6308b6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6308b7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6308b8: c1e810 SHR EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::right);
  }
  { // 0x6308bb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6308bc: ff15a0517800 CALL dword ptr [0x007851a0]
    const std::uint32_t call_target=m.r32((0x007851a0u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6308c2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6308c4: 7426 JZ 0x006308ec
    if(integer::condition("JZ",flags)) goto L006308ec;
  }
  { // 0x6308c6: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x6308ca: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x6308ce: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6308cf: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x6308d2: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x6308d6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6308d7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6308d8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6308d9: ff1520517800 CALL dword ptr [0x00785120]
    const std::uint32_t call_target=m.r32((0x00785120u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6308df: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x6308e1: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x6308e3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6308e4: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x6308e6: 83c43c ADD ESP,0x3c
    f.sp = integer::add(f.sp,0x0000003cu,32,flags);
  }
  { // 0x6308e9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006308ec: { // 0x6308ec: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6308ee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6308ef: 83c43c ADD ESP,0x3c
    f.sp = integer::add(f.sp,0x0000003cu,32,flags);
  }
  { // 0x6308f2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00230900(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x630900: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x630901: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x630902: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x630906: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x630908: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x63090a: 750f JNZ 0x0063091b
    if(integer::condition("JNZ",flags)) goto L0063091b;
  }
  { // 0x63090c: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  { // 0x63090f: c7460cffffffff MOV dword ptr [ESI + 0xc],0xffffffff
    m.w32((s.si+0x0000000cu), 0xffffffffu);
  }
  { // 0x630916: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x630917: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x630918: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0063091b: { // 0x63091b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x63091d: e8fefdffff CALL 0x00630720
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x630922: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x630925: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  { // 0x630928: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  { // 0x63092a: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  { // 0x63092d: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x630931: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  { // 0x630934: 7409 JZ 0x0063093f
    if(integer::condition("JZ",flags)) goto L0063093f;
  }
  { // 0x630936: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x630938: 7c02 JL 0x0063093c
    if(integer::condition("JL",flags)) goto L0063093c;
  }
  { // 0x63093a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0063093c: { // 0x63093c: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L0063093f: { // 0x63093f: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x630942: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x630944: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x630946: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x630948: 0f9ec1 SETLE CL
    s.cx = with_al(s.cx, (integer::condition("SETLE",flags)?1u:0u));
  }
  { // 0x63094b: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x63094c: 23c1 AND EAX,ECX
    s.ax = integer::logical((s.ax)&(s.cx),32,flags);
  }
  { // 0x63094e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x630950: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  { // 0x630953: ff5218 CALL dword ptr [EDX + 0x18]
    const std::uint32_t call_target=m.r32((s.dx+0x00000018u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x630956: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x630958: 740b JZ 0x00630965
    if(integer::condition("JZ",flags)) goto L00630965;
  }
  { // 0x63095a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x63095c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x63095e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x630960: e8ebfbffff CALL 0x00630550
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00630965: { // 0x630965: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x630966: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x630967: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00230970(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x630970: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x630971: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x630973: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x630975: ff5018 CALL dword ptr [EAX + 0x18]
    const std::uint32_t call_target=m.r32((s.ax+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x630978: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x63097a: 7515 JNZ 0x00630991
    if(integer::condition("JNZ",flags)) goto L00630991;
  }
  { // 0x63097c: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x63097f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x630981: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x630982: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x630984: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  { // 0x630986: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x630988: ff5240 CALL dword ptr [EDX + 0x40]
    const std::uint32_t call_target=m.r32((s.dx+0x00000040u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x63098b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x63098d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x63098e: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00630991: { // 0x630991: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x630995: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x630997: 83e900 SUB ECX,0x0
    s.cx = integer::sub(s.cx,0x00000000u,32,flags);
  }
  { // 0x63099a: 7414 JZ 0x006309b0
    if(integer::condition("JZ",flags)) goto L006309b0;
  }
  { // 0x63099c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x63099d: 740a JZ 0x006309a9
    if(integer::condition("JZ",flags)) goto L006309a9;
  }
  { // 0x63099f: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x6309a0: 7510 JNZ 0x006309b2
    if(integer::condition("JNZ",flags)) goto L006309b2;
  }
  { // 0x6309a2: b802000000 MOV EAX,0x2
    s.ax = 0x00000002u;
  }
  { // 0x6309a7: eb09 JMP 0x006309b2
    goto L006309b2;
  }
  L006309a9: { // 0x6309a9: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x6309ae: eb02 JMP 0x006309b2
    goto L006309b2;
  }
  L006309b0: { // 0x6309b0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006309b2: { // 0x6309b2: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x6309b6: 8b5610 MOV EDX,dword ptr [ESI + 0x10]
    s.dx = m.r32((s.si+0x00000010u));
  }
  { // 0x6309b9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6309ba: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6309bc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6309bd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6309be: ff15b4517800 CALL dword ptr [0x007851b4]
    const std::uint32_t call_target=m.r32((0x007851b4u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6309c4: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x6309c7: 7518 JNZ 0x006309e1
    if(integer::condition("JNZ",flags)) goto L006309e1;
  }
  { // 0x6309c9: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x6309cc: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6309cd: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x6309cf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6309d0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6309d2: ff15f4517800 CALL dword ptr [0x007851f4]
    const std::uint32_t call_target=m.r32((0x007851f4u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6309d8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6309d9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6309db: ff5740 CALL dword ptr [EDI + 0x40]
    const std::uint32_t call_target=m.r32((s.di+0x00000040u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x6309de: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6309e0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006309e1: { // 0x6309e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6309e2: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002309f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6309f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6309f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6309f3: c706843c7900 MOV dword ptr [ESI],0x793c84
    m.w32((s.si), 0x00793c84u);
  }
  { // 0x6309f9: ff159c3c7900 CALL dword ptr [0x00793c9c]
    const std::uint32_t call_target=m.r32((0x00793c9cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6309ff: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x630a01: 742a JZ 0x00630a2d
    if(integer::condition("JZ",flags)) goto L00630a2d;
  }
  { // 0x630a03: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x630a06: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x630a07: ff15d4517800 CALL dword ptr [0x007851d4]
    const std::uint32_t call_target=m.r32((0x007851d4u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x630a0d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x630a0f: 7515 JNZ 0x00630a26
    if(integer::condition("JNZ",flags)) goto L00630a26;
  }
  { // 0x630a11: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x630a14: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x630a15: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x630a17: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x630a18: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x630a19: ff15f4517800 CALL dword ptr [0x007851f4]
    const std::uint32_t call_target=m.r32((0x007851f4u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x630a1f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x630a20: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x630a22: ff5740 CALL dword ptr [EDI + 0x40]
    const std::uint32_t call_target=m.r32((s.di+0x00000040u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x630a25: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00630a26: { // 0x630a26: c74610ffffffff MOV dword ptr [ESI + 0x10],0xffffffff
    m.w32((s.si+0x00000010u), 0xffffffffu);
  }
  L00630a2d: { // 0x630a2d: 8a461c MOV AL,byte ptr [ESI + 0x1c]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000001cu)));
  }
  { // 0x630a30: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x630a32: 741b JZ 0x00630a4f
    if(integer::condition("JZ",flags)) goto L00630a4f;
  }
  { // 0x630a34: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x630a37: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x630a39: 7414 JZ 0x00630a4f
    if(integer::condition("JZ",flags)) goto L00630a4f;
  }
  { // 0x630a3b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x630a3c: e8e7d41300 CALL 0x0076df28
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x630a41: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x630a44: c7461400000000 MOV dword ptr [ESI + 0x14],0x0
    m.w32((s.si+0x00000014u), 0x00000000u);
  }
  { // 0x630a4b: c6461c00 MOV byte ptr [ESI + 0x1c],0x0
    m.w8((s.si+0x0000001cu), 0x00000000u);
  }
  L00630a4f: { // 0x630a4f: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x630a53: c7063c3c7900 MOV dword ptr [ESI],0x793c3c
    m.w32((s.si), 0x00793c3cu);
  }
  { // 0x630a59: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x630a5b: 7409 JZ 0x00630a66
    if(integer::condition("JZ",flags)) goto L00630a66;
  }
  { // 0x630a5d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x630a5e: e818cc1300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x630a63: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00630a66: { // 0x630a66: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x630a68: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x630a69: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00230b20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x630b20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x630b21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x630b23: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x630b26: c706cc3c7900 MOV dword ptr [ESI],0x793ccc
    m.w32((s.si), 0x00793cccu);
  }
  { // 0x630b2c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x630b2e: 740c JZ 0x00630b3c
    if(integer::condition("JZ",flags)) goto L00630b3c;
  }
  { // 0x630b30: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x630b37: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x630b39: ff5008 CALL dword ptr [EAX + 0x8]
    const std::uint32_t call_target=m.r32((s.ax+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00630b3c: { // 0x630b3c: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x630b41: 7409 JZ 0x00630b4c
    if(integer::condition("JZ",flags)) goto L00630b4c;
  }
  { // 0x630b43: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x630b44: e832cb1300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x630b49: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00630b4c: { // 0x630b4c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x630b4e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x630b4f: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00249830(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x649830: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x649831: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649832: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649836: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x649838: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x64983a: 7454 JZ 0x00649890
    if(integer::condition("JZ",flags)) goto L00649890;
  }
  { // 0x64983c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x64983e: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x649841: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x649844: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x649846: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x649849: 743a JZ 0x00649885
    if(integer::condition("JZ",flags)) goto L00649885;
  }
  { // 0x64984b: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  { // 0x649852: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x649853: e8ff401200 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x649858: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x64985b: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x64985e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x649860: 742e JZ 0x00649890
    if(integer::condition("JZ",flags)) goto L00649890;
  }
  { // 0x649862: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x649865: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x649867: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x649869: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x64986d: 7e21 JLE 0x00649890
    if(integer::condition("JLE",flags)) goto L00649890;
  }
  L0064986f: { // 0x64986f: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x649872: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x649875: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x649878: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  { // 0x64987b: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x64987e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x64987f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x649881: 7cec JL 0x0064986f
    if(integer::condition("JL",flags)) goto L0064986f;
  }
  { // 0x649883: eb0b JMP 0x00649890
    goto L00649890;
  }
  L00649885: { // 0x649885: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x64988c: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L00649890: { // 0x649890: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x649893: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x649896: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  { // 0x649899: 894e14 MOV dword ptr [ESI + 0x14],ECX
    m.w32((s.si+0x00000014u), s.cx);
  }
  { // 0x64989c: 8b5718 MOV EDX,dword ptr [EDI + 0x18]
    s.dx = m.r32((s.di+0x00000018u));
  }
  { // 0x64989f: 895618 MOV dword ptr [ESI + 0x18],EDX
    m.w32((s.si+0x00000018u), s.dx);
  }
  { // 0x6498a2: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6498a4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6498a5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6498a6: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00249940(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x649940: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x649941: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649942: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649946: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x649948: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x64994a: 7454 JZ 0x006499a0
    if(integer::condition("JZ",flags)) goto L006499a0;
  }
  { // 0x64994c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x64994e: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x649951: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x649954: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x649956: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x649959: 743a JZ 0x00649995
    if(integer::condition("JZ",flags)) goto L00649995;
  }
  { // 0x64995b: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  { // 0x649962: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x649963: e8ef3f1200 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x649968: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x64996b: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x64996e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x649970: 742e JZ 0x006499a0
    if(integer::condition("JZ",flags)) goto L006499a0;
  }
  { // 0x649972: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x649975: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x649977: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x649979: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x64997d: 7e21 JLE 0x006499a0
    if(integer::condition("JLE",flags)) goto L006499a0;
  }
  L0064997f: { // 0x64997f: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x649982: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x649985: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x649988: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  { // 0x64998b: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x64998e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x64998f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x649991: 7cec JL 0x0064997f
    if(integer::condition("JL",flags)) goto L0064997f;
  }
  { // 0x649993: eb0b JMP 0x006499a0
    goto L006499a0;
  }
  L00649995: { // 0x649995: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x64999c: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L006499a0: { // 0x6499a0: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x6499a3: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x6499a6: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  { // 0x6499a9: 894e14 MOV dword ptr [ESI + 0x14],ECX
    m.w32((s.si+0x00000014u), s.cx);
  }
  { // 0x6499ac: 8b5718 MOV EDX,dword ptr [EDI + 0x18]
    s.dx = m.r32((s.di+0x00000018u));
  }
  { // 0x6499af: 895618 MOV dword ptr [ESI + 0x18],EDX
    m.w32((s.si+0x00000018u), s.dx);
  }
  { // 0x6499b2: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6499b4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6499b5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6499b6: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002499c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6499c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6499c1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6499c2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6499c6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6499c8: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x6499ca: 7454 JZ 0x00649a20
    if(integer::condition("JZ",flags)) goto L00649a20;
  }
  { // 0x6499cc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6499ce: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6499d1: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x6499d4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6499d6: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x6499d9: 743a JZ 0x00649a15
    if(integer::condition("JZ",flags)) goto L00649a15;
  }
  { // 0x6499db: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  { // 0x6499e2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6499e3: e86f3f1200 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6499e8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6499eb: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x6499ee: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6499f0: 742e JZ 0x00649a20
    if(integer::condition("JZ",flags)) goto L00649a20;
  }
  { // 0x6499f2: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x6499f5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6499f7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6499f9: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x6499fd: 7e21 JLE 0x00649a20
    if(integer::condition("JLE",flags)) goto L00649a20;
  }
  L006499ff: { // 0x6499ff: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x649a02: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x649a05: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x649a08: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  { // 0x649a0b: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x649a0e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x649a0f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x649a11: 7cec JL 0x006499ff
    if(integer::condition("JL",flags)) goto L006499ff;
  }
  { // 0x649a13: eb0b JMP 0x00649a20
    goto L00649a20;
  }
  L00649a15: { // 0x649a15: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x649a1c: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L00649a20: { // 0x649a20: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x649a23: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x649a26: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  { // 0x649a29: 894e14 MOV dword ptr [ESI + 0x14],ECX
    m.w32((s.si+0x00000014u), s.cx);
  }
  { // 0x649a2c: 8b5718 MOV EDX,dword ptr [EDI + 0x18]
    s.dx = m.r32((s.di+0x00000018u));
  }
  { // 0x649a2f: 895618 MOV dword ptr [ESI + 0x18],EDX
    m.w32((s.si+0x00000018u), s.dx);
  }
  { // 0x649a32: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x649a34: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x649a35: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x649a36: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00249a40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x649a40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x649a41: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x649a42: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x649a46: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x649a48: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x649a4a: 7454 JZ 0x00649aa0
    if(integer::condition("JZ",flags)) goto L00649aa0;
  }
  { // 0x649a4c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x649a4e: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x649a51: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x649a54: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x649a56: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x649a59: 743a JZ 0x00649a95
    if(integer::condition("JZ",flags)) goto L00649a95;
  }
  { // 0x649a5b: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  { // 0x649a62: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x649a63: e8ef3e1200 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x649a68: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x649a6b: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x649a6e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x649a70: 742e JZ 0x00649aa0
    if(integer::condition("JZ",flags)) goto L00649aa0;
  }
  { // 0x649a72: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x649a75: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x649a77: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x649a79: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x649a7d: 7e21 JLE 0x00649aa0
    if(integer::condition("JLE",flags)) goto L00649aa0;
  }
  L00649a7f: { // 0x649a7f: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x649a82: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x649a85: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x649a88: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  { // 0x649a8b: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x649a8e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x649a8f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x649a91: 7cec JL 0x00649a7f
    if(integer::condition("JL",flags)) goto L00649a7f;
  }
  { // 0x649a93: eb0b JMP 0x00649aa0
    goto L00649aa0;
  }
  L00649a95: { // 0x649a95: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x649a9c: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L00649aa0: { // 0x649aa0: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x649aa3: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x649aa6: 8b4f14 MOV ECX,dword ptr [EDI + 0x14]
    s.cx = m.r32((s.di+0x00000014u));
  }
  { // 0x649aa9: 894e14 MOV dword ptr [ESI + 0x14],ECX
    m.w32((s.si+0x00000014u), s.cx);
  }
  { // 0x649aac: 8b5718 MOV EDX,dword ptr [EDI + 0x18]
    s.dx = m.r32((s.di+0x00000018u));
  }
  { // 0x649aaf: 895618 MOV dword ptr [ESI + 0x18],EDX
    m.w32((s.si+0x00000018u), s.dx);
  }
  { // 0x649ab2: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x649ab4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x649ab5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x649ab6: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0024a180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64a180: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64a181: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64a182: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64a186: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x64a188: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x64a18a: 7459 JZ 0x0064a1e5
    if(integer::condition("JZ",flags)) goto L0064a1e5;
  }
  { // 0x64a18c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x64a18e: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64a191: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x64a194: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64a196: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x64a199: 743f JZ 0x0064a1da
    if(integer::condition("JZ",flags)) goto L0064a1da;
  }
  { // 0x64a19b: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  { // 0x64a1a2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x64a1a3: e8af371200 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64a1a8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x64a1ab: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x64a1ae: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64a1b0: 7433 JZ 0x0064a1e5
    if(integer::condition("JZ",flags)) goto L0064a1e5;
  }
  { // 0x64a1b2: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x64a1b5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x64a1b7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x64a1b9: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x64a1bd: 7e26 JLE 0x0064a1e5
    if(integer::condition("JLE",flags)) goto L0064a1e5;
  }
  L0064a1bf: { // 0x64a1bf: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x64a1c2: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x64a1c5: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x64a1c8: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  { // 0x64a1cb: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x64a1ce: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x64a1cf: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x64a1d1: 7cec JL 0x0064a1bf
    if(integer::condition("JL",flags)) goto L0064a1bf;
  }
  { // 0x64a1d3: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x64a1d5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64a1d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64a1d7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0064a1da: { // 0x64a1da: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x64a1e1: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L0064a1e5: { // 0x64a1e5: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x64a1e7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64a1e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64a1e9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0024a1f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64a1f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64a1f1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64a1f2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64a1f6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x64a1f8: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x64a1fa: 7459 JZ 0x0064a255
    if(integer::condition("JZ",flags)) goto L0064a255;
  }
  { // 0x64a1fc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x64a1fe: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64a201: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x64a204: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64a206: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x64a209: 743f JZ 0x0064a24a
    if(integer::condition("JZ",flags)) goto L0064a24a;
  }
  { // 0x64a20b: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  { // 0x64a212: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x64a213: e83f371200 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64a218: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x64a21b: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x64a21e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64a220: 7433 JZ 0x0064a255
    if(integer::condition("JZ",flags)) goto L0064a255;
  }
  { // 0x64a222: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x64a225: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x64a227: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x64a229: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x64a22d: 7e26 JLE 0x0064a255
    if(integer::condition("JLE",flags)) goto L0064a255;
  }
  L0064a22f: { // 0x64a22f: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x64a232: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x64a235: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x64a238: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  { // 0x64a23b: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x64a23e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x64a23f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x64a241: 7cec JL 0x0064a22f
    if(integer::condition("JL",flags)) goto L0064a22f;
  }
  { // 0x64a243: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x64a245: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64a246: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64a247: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0064a24a: { // 0x64a24a: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x64a251: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L0064a255: { // 0x64a255: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x64a257: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64a258: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64a259: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0024a570(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64a570: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64a571: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64a572: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64a576: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x64a578: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x64a57a: 7459 JZ 0x0064a5d5
    if(integer::condition("JZ",flags)) goto L0064a5d5;
  }
  { // 0x64a57c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x64a57e: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64a581: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x64a584: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64a586: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x64a589: 743f JZ 0x0064a5ca
    if(integer::condition("JZ",flags)) goto L0064a5ca;
  }
  { // 0x64a58b: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  { // 0x64a592: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x64a593: e8bf331200 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64a598: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x64a59b: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x64a59e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64a5a0: 7433 JZ 0x0064a5d5
    if(integer::condition("JZ",flags)) goto L0064a5d5;
  }
  { // 0x64a5a2: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x64a5a5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x64a5a7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x64a5a9: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x64a5ad: 7e26 JLE 0x0064a5d5
    if(integer::condition("JLE",flags)) goto L0064a5d5;
  }
  L0064a5af: { // 0x64a5af: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x64a5b2: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x64a5b5: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x64a5b8: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  { // 0x64a5bb: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x64a5be: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x64a5bf: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x64a5c1: 7cec JL 0x0064a5af
    if(integer::condition("JL",flags)) goto L0064a5af;
  }
  { // 0x64a5c3: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x64a5c5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64a5c6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64a5c7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0064a5ca: { // 0x64a5ca: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x64a5d1: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L0064a5d5: { // 0x64a5d5: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x64a5d7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64a5d8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64a5d9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0024a5e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64a5e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64a5e1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64a5e2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64a5e6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x64a5e8: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x64a5ea: 7459 JZ 0x0064a645
    if(integer::condition("JZ",flags)) goto L0064a645;
  }
  { // 0x64a5ec: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x64a5ee: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64a5f1: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x64a5f4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64a5f6: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x64a5f9: 743f JZ 0x0064a63a
    if(integer::condition("JZ",flags)) goto L0064a63a;
  }
  { // 0x64a5fb: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  { // 0x64a602: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x64a603: e84f331200 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64a608: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x64a60b: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x64a60e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64a610: 7433 JZ 0x0064a645
    if(integer::condition("JZ",flags)) goto L0064a645;
  }
  { // 0x64a612: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x64a615: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x64a617: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x64a619: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x64a61d: 7e26 JLE 0x0064a645
    if(integer::condition("JLE",flags)) goto L0064a645;
  }
  L0064a61f: { // 0x64a61f: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x64a622: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x64a625: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x64a628: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  { // 0x64a62b: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x64a62e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x64a62f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x64a631: 7cec JL 0x0064a61f
    if(integer::condition("JL",flags)) goto L0064a61f;
  }
  { // 0x64a633: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x64a635: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64a636: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64a637: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0064a63a: { // 0x64a63a: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x64a641: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L0064a645: { // 0x64a645: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x64a647: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64a648: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64a649: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0024b3c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64b3c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64b3c1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x64b3c2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x64b3c6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x64b3c8: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x64b3ca: 7459 JZ 0x0064b425
    if(integer::condition("JZ",flags)) goto L0064b425;
  }
  { // 0x64b3cc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x64b3ce: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x64b3d1: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x64b3d4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64b3d6: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x64b3d9: 743f JZ 0x0064b41a
    if(integer::condition("JZ",flags)) goto L0064b41a;
  }
  { // 0x64b3db: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  { // 0x64b3e2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x64b3e3: e86f251200 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x64b3e8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x64b3eb: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x64b3ee: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64b3f0: 7433 JZ 0x0064b425
    if(integer::condition("JZ",flags)) goto L0064b425;
  }
  { // 0x64b3f2: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x64b3f5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x64b3f7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x64b3f9: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x64b3fd: 7e26 JLE 0x0064b425
    if(integer::condition("JLE",flags)) goto L0064b425;
  }
  L0064b3ff: { // 0x64b3ff: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x64b402: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x64b405: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x64b408: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  { // 0x64b40b: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x64b40e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x64b40f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x64b411: 7cec JL 0x0064b3ff
    if(integer::condition("JL",flags)) goto L0064b3ff;
  }
  { // 0x64b413: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x64b415: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64b416: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64b417: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0064b41a: { // 0x64b41a: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x64b421: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L0064b425: { // 0x64b425: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x64b427: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x64b428: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64b429: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00250250(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x650250: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x650254: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x650255: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x650256: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x650258: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x65025a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65025c: 7449 JZ 0x006502a7
    if(integer::condition("JZ",flags)) goto L006502a7;
  }
  { // 0x65025e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x650260: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x650264: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x650265: 68b80a7c00 PUSH 0x7c0ab8
    f.push(m,0x007c0ab8u);
  }
  { // 0x65026a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x65026b: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x65026d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x65026f: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x650271: 7d19 JGE 0x0065028c
    if(integer::condition("JGE",flags)) goto L0065028c;
  }
  { // 0x650273: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x650275: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x650277: 7406 JZ 0x0065027f
    if(integer::condition("JZ",flags)) goto L0065027f;
  }
  { // 0x650279: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x65027b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x65027c: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0065027f: { // 0x65027f: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x650281: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x650287: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x650288: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x650289: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0065028c: { // 0x65028c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x65028e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x65028f: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  { // 0x650293: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x650295: 7406 JZ 0x0065029d
    if(integer::condition("JZ",flags)) goto L0065029d;
  }
  { // 0x650297: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x650299: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x65029a: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L0065029d: { // 0x65029d: 891e MOV dword ptr [ESI],EBX
    m.w32((s.si), s.bx);
  }
  { // 0x65029f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6502a0: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x6502a2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6502a3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6502a4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006502a7: { // 0x6502a7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6502a9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6502ab: 740c JZ 0x006502b9
    if(integer::condition("JZ",flags)) goto L006502b9;
  }
  { // 0x6502ad: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x6502b3: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x6502b5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6502b6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L006502b9: { // 0x6502b9: bf02400080 MOV EDI,0x80004002
    s.di = 0x80004002u;
  }
  { // 0x6502be: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x6502c0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6502c1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6502c2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00253440(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x653440: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x653445: e886e70000 CALL 0x00661bd0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x65344a: 8b0da81f8200 MOV ECX,dword ptr [0x00821fa8]
    s.cx = m.r32((0x00821fa8u));
  }
  { // 0x653450: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x653452: ff5028 CALL dword ptr [EAX + 0x28]
    const std::uint32_t call_target=m.r32((s.ax+0x00000028u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x653455: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x653457: 750b JNZ 0x00653464
    if(integer::condition("JNZ",flags)) goto L00653464;
  }
  { // 0x653459: 8b0da81f8200 MOV ECX,dword ptr [0x00821fa8]
    s.cx = m.r32((0x00821fa8u));
  }
  { // 0x65345f: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x653461: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00653464: { // 0x653464: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  { // 0x65346a: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x65346c: 888106230000 MOV byte ptr [ECX + 0x2306],AL
    m.w8((s.cx+0x00002306u), (s.ax & 0xffu));
  }
  { // 0x653472: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  { // 0x653478: a28489a200 MOV [0x00a28984],AL
    m.w8((0x00a28984u), (s.ax & 0xffu));
  }
  { // 0x65347d: e8ced7edff CALL 0x00530c50
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x653482: c7057c0caa0000000000 MOV dword ptr [0x00aa0c7c],0x0
    m.w32((0x00aa0c7cu), 0x00000000u);
  }
  { // 0x65348c: c3 RET
    finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,161>& entries_b() {
  static const std::array<Entry,161> entries{{
    {0xf9da0u,f_000f9da0},
    {0xfa170u,f_000fa170},
    {0xfa540u,f_000fa540},
    {0xfcf80u,f_000fcf80},
    {0xfdd00u,f_000fdd00},
    {0xfdd80u,f_000fdd80},
    {0x104390u,f_00104390},
    {0x105550u,f_00105550},
    {0x1055b0u,f_001055b0},
    {0x105900u,f_00105900},
    {0x108700u,f_00108700},
    {0x108ac0u,f_00108ac0},
    {0x108b00u,f_00108b00},
    {0x108c80u,f_00108c80},
    {0x108cc0u,f_00108cc0},
    {0x115020u,f_00115020},
    {0x1197e0u,f_001197e0},
    {0x119820u,f_00119820},
    {0x122190u,f_00122190},
    {0x122350u,f_00122350},
    {0x123040u,f_00123040},
    {0x124560u,f_00124560},
    {0x124620u,f_00124620},
    {0x1263c0u,f_001263c0},
    {0x127560u,f_00127560},
    {0x1275a0u,f_001275a0},
    {0x129950u,f_00129950},
    {0x130af0u,f_00130af0},
    {0x132b00u,f_00132b00},
    {0x135000u,f_00135000},
    {0x137180u,f_00137180},
    {0x1372c0u,f_001372c0},
    {0x1372f0u,f_001372f0},
    {0x1383a0u,f_001383a0},
    {0x1385c0u,f_001385c0},
    {0x138610u,f_00138610},
    {0x138710u,f_00138710},
    {0x138850u,f_00138850},
    {0x1389b0u,f_001389b0},
    {0x138a00u,f_00138a00},
    {0x138aa0u,f_00138aa0},
    {0x138ae0u,f_00138ae0},
    {0x138b70u,f_00138b70},
    {0x13b450u,f_0013b450},
    {0x13b540u,f_0013b540},
    {0x13b5a0u,f_0013b5a0},
    {0x175cc0u,f_00175cc0},
    {0x175f90u,f_00175f90},
    {0x18ca60u,f_0018ca60},
    {0x18e640u,f_0018e640},
    {0x18ffa0u,f_0018ffa0},
    {0x191ab0u,f_00191ab0},
    {0x193dc0u,f_00193dc0},
    {0x195310u,f_00195310},
    {0x197880u,f_00197880},
    {0x197a80u,f_00197a80},
    {0x197ab0u,f_00197ab0},
    {0x197ae0u,f_00197ae0},
    {0x197b10u,f_00197b10},
    {0x197b40u,f_00197b40},
    {0x197b80u,f_00197b80},
    {0x197bb0u,f_00197bb0},
    {0x197bf0u,f_00197bf0},
    {0x197c60u,f_00197c60},
    {0x197ca0u,f_00197ca0},
    {0x197ce0u,f_00197ce0},
    {0x197d20u,f_00197d20},
    {0x197d60u,f_00197d60},
    {0x197dd0u,f_00197dd0},
    {0x197e10u,f_00197e10},
    {0x197e50u,f_00197e50},
    {0x19a7b0u,f_0019a7b0},
    {0x1aab70u,f_001aab70},
    {0x1ac9d0u,f_001ac9d0},
    {0x1aca90u,f_001aca90},
    {0x1af940u,f_001af940},
    {0x1afaa0u,f_001afaa0},
    {0x1b02f0u,f_001b02f0},
    {0x1b0b50u,f_001b0b50},
    {0x1b3f30u,f_001b3f30},
    {0x1b6470u,f_001b6470},
    {0x1b76a0u,f_001b76a0},
    {0x1bd470u,f_001bd470},
    {0x1bd4d0u,f_001bd4d0},
    {0x1bdf90u,f_001bdf90},
    {0x1bdff0u,f_001bdff0},
    {0x1be030u,f_001be030},
    {0x1c0630u,f_001c0630},
    {0x1c09f0u,f_001c09f0},
    {0x1c32d0u,f_001c32d0},
    {0x1c3430u,f_001c3430},
    {0x1c3c90u,f_001c3c90},
    {0x1c89f0u,f_001c89f0},
    {0x1c8c00u,f_001c8c00},
    {0x1ca4e0u,f_001ca4e0},
    {0x1cae60u,f_001cae60},
    {0x1cb480u,f_001cb480},
    {0x1ccb90u,f_001ccb90},
    {0x1cce60u,f_001cce60},
    {0x1ccfb0u,f_001ccfb0},
    {0x1cd430u,f_001cd430},
    {0x1cd520u,f_001cd520},
    {0x1cdae0u,f_001cdae0},
    {0x1cdb40u,f_001cdb40},
    {0x1d75d0u,f_001d75d0},
    {0x1da440u,f_001da440},
    {0x1da610u,f_001da610},
    {0x1e0a10u,f_001e0a10},
    {0x1e16e0u,f_001e16e0},
    {0x1e21f0u,f_001e21f0},
    {0x1f7040u,f_001f7040},
    {0x1f7290u,f_001f7290},
    {0x1f7480u,f_001f7480},
    {0x1f7e80u,f_001f7e80},
    {0x1f7f60u,f_001f7f60},
    {0x1f8a90u,f_001f8a90},
    {0x1f8af0u,f_001f8af0},
    {0x1f8b50u,f_001f8b50},
    {0x1f8bb0u,f_001f8bb0},
    {0x1f8c10u,f_001f8c10},
    {0x1f8c70u,f_001f8c70},
    {0x1fd8a0u,f_001fd8a0},
    {0x206680u,f_00206680},
    {0x208810u,f_00208810},
    {0x209b40u,f_00209b40},
    {0x20c340u,f_0020c340},
    {0x20d5f0u,f_0020d5f0},
    {0x2113f0u,f_002113f0},
    {0x211d70u,f_00211d70},
    {0x211df0u,f_00211df0},
    {0x216960u,f_00216960},
    {0x216d70u,f_00216d70},
    {0x2268f0u,f_002268f0},
    {0x226960u,f_00226960},
    {0x22e100u,f_0022e100},
    {0x22f9b0u,f_0022f9b0},
    {0x22fa00u,f_0022fa00},
    {0x230060u,f_00230060},
    {0x230110u,f_00230110},
    {0x230180u,f_00230180},
    {0x2302f0u,f_002302f0},
    {0x230720u,f_00230720},
    {0x2307a0u,f_002307a0},
    {0x2307e0u,f_002307e0},
    {0x230840u,f_00230840},
    {0x230890u,f_00230890},
    {0x230900u,f_00230900},
    {0x230970u,f_00230970},
    {0x2309f0u,f_002309f0},
    {0x230b20u,f_00230b20},
    {0x249830u,f_00249830},
    {0x249940u,f_00249940},
    {0x2499c0u,f_002499c0},
    {0x249a40u,f_00249a40},
    {0x24a180u,f_0024a180},
    {0x24a1f0u,f_0024a1f0},
    {0x24a570u,f_0024a570},
    {0x24a5e0u,f_0024a5e0},
    {0x24b3c0u,f_0024b3c0},
    {0x250250u,f_00250250},
    {0x253440u,f_00253440},
  }}; return entries;
}
} // namespace ra2::recovered::mixed_b35
