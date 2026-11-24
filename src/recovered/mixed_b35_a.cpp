#include "recovered/mixed_b35_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::mixed_b35 {
namespace {
void f_00001580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x401580: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x401581: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x401583: 8b8e0c010000 MOV ECX,dword ptr [ESI + 0x10c]
    s.cx = m.r32((s.si+0x0000010cu));
  }
  { // 0x401589: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x40158b: 7406 JZ 0x00401593
    if(integer::condition("JZ",flags)) goto L00401593;
  }
  { // 0x40158d: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x40158f: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x401591: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00401593: { // 0x401593: 8b8e10010000 MOV ECX,dword ptr [ESI + 0x110]
    s.cx = m.r32((s.si+0x00000110u));
  }
  { // 0x401599: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x40159b: 7406 JZ 0x004015a3
    if(integer::condition("JZ",flags)) goto L004015a3;
  }
  { // 0x40159d: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x40159f: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4015a1: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L004015a3: { // 0x4015a3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4015a5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4015a7: 7409 JZ 0x004015b2
    if(integer::condition("JZ",flags)) goto L004015b2;
  }
  { // 0x4015a9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4015aa: e8ccc03600 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4015af: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004015b2: { // 0x4015b2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4015b3: e8c3c03600 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4015b8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4015bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4015bc: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00001980(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x401980: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x401981: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x401983: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x401987: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x401989: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x40198a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40198c: ff5008 CALL dword ptr [EAX + 0x8]
    const std::uint32_t call_target=m.r32((s.ax+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40198f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x401993: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x401995: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x401996: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x401998: ff521c CALL dword ptr [EDX + 0x1c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000001cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x40199b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40199c: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00002170(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x402170: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x402171: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x402173: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  { // 0x402179: ff5008 CALL dword ptr [EAX + 0x8]
    const std::uint32_t call_target=m.r32((s.ax+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40217c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x40217d: e8f9b43600 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x402182: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x402185: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x402186: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000022c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4022c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4022c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4022c3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4022c4: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x4022c6: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  { // 0x4022cc: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x4022ce: 741b JZ 0x004022eb
    if(integer::condition("JZ",flags)) goto L004022eb;
  }
  { // 0x4022d0: ffd0 CALL EAX
    const std::uint32_t call_target=s.ax;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4022d2: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x4022d4: 7451 JZ 0x00402327
    if(integer::condition("JZ",flags)) goto L00402327;
  }
  { // 0x4022d6: 89be74010000 MOV dword ptr [ESI + 0x174],EDI
    m.w32((s.si+0x00000174u), s.di);
  }
  { // 0x4022dc: 89be78010000 MOV dword ptr [ESI + 0x178],EDI
    m.w32((s.si+0x00000178u), s.di);
  }
  { // 0x4022e2: 89be70010000 MOV dword ptr [ESI + 0x170],EDI
    m.w32((s.si+0x00000170u), s.di);
  }
  { // 0x4022e8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4022e9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4022ea: c3 RET
    finish(m,s,f,0u); return;
  }
  L004022eb: { // 0x4022eb: 8b8e6c010000 MOV ECX,dword ptr [ESI + 0x16c]
    s.cx = m.r32((s.si+0x0000016cu));
  }
  { // 0x4022f1: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  { // 0x4022f3: 742c JZ 0x00402321
    if(integer::condition("JZ",flags)) goto L00402321;
  }
  { // 0x4022f5: e8a6500000 CALL 0x004073a0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4022fa: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x4022fc: 89866c010000 MOV dword ptr [ESI + 0x16c],EAX
    m.w32((s.si+0x0000016cu), s.ax);
  }
  { // 0x402302: 741d JZ 0x00402321
    if(integer::condition("JZ",flags)) goto L00402321;
  }
  { // 0x402304: 8b480c MOV ECX,dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  { // 0x402307: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x402308: 898e70010000 MOV dword ptr [ESI + 0x170],ECX
    m.w32((s.si+0x00000170u), s.cx);
  }
  { // 0x40230e: 8b4010 MOV EAX,dword ptr [EAX + 0x10]
    s.ax = m.r32((s.ax+0x00000010u));
  }
  { // 0x402311: 898674010000 MOV dword ptr [ESI + 0x174],EAX
    m.w32((s.si+0x00000174u), s.ax);
  }
  { // 0x402317: 898678010000 MOV dword ptr [ESI + 0x178],EAX
    m.w32((s.si+0x00000178u), s.ax);
  }
  { // 0x40231d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x40231f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x402320: c3 RET
    finish(m,s,f,0u); return;
  }
  L00402321: { // 0x402321: 89be74010000 MOV dword ptr [ESI + 0x174],EDI
    m.w32((s.si+0x00000174u), s.di);
  }
  L00402327: { // 0x402327: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x402328: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x40232a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40232b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00002440(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x402440: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x402441: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x402443: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  { // 0x402449: 89560c MOV dword ptr [ESI + 0xc],EDX
    m.w32((s.si+0x0000000cu), s.dx);
  }
  { // 0x40244c: ff5028 CALL dword ptr [EAX + 0x28]
    const std::uint32_t call_target=m.r32((s.ax+0x00000028u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40244f: f686a400000005 TEST byte ptr [ESI + 0xa4],0x5
    (void)integer::logical((m.r8((s.si+0x000000a4u)))&(0x00000005u),8,flags);
  }
  { // 0x402456: 740b JZ 0x00402463
    if(integer::condition("JZ",flags)) goto L00402463;
  }
  { // 0x402458: 8b96d4000000 MOV EDX,dword ptr [ESI + 0xd4]
    s.dx = m.r32((s.si+0x000000d4u));
  }
  { // 0x40245e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x402460: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00402463: { // 0x402463: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  { // 0x402469: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40246b: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x40246e: 8b86bc000000 MOV EAX,dword ptr [ESI + 0xbc]
    s.ax = m.r32((s.si+0x000000bcu));
  }
  { // 0x402474: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x402476: 7404 JZ 0x0040247c
    if(integer::condition("JZ",flags)) goto L0040247c;
  }
  { // 0x402478: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40247a: ffd0 CALL EAX
    const std::uint32_t call_target=s.ax;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L0040247c: { // 0x40247c: c7866801000000000000 MOV dword ptr [ESI + 0x168],0x0
    m.w32((s.si+0x00000168u), 0x00000000u);
  }
  { // 0x402486: 8b8ea4000000 MOV ECX,dword ptr [ESI + 0xa4]
    s.cx = m.r32((s.si+0x000000a4u));
  }
  { // 0x40248c: 83c908 OR ECX,0x8
    s.cx = integer::logical((s.cx)|(0x00000008u),32,flags);
  }
  { // 0x40248f: 898ea4000000 MOV dword ptr [ESI + 0xa4],ECX
    m.w32((s.si+0x000000a4u), s.cx);
  }
  { // 0x402495: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x402496: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00002550(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x402550: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x402551: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x402553: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  { // 0x402559: ff5028 CALL dword ptr [EAX + 0x28]
    const std::uint32_t call_target=m.r32((s.ax+0x00000028u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40255c: f686a400000005 TEST byte ptr [ESI + 0xa4],0x5
    (void)integer::logical((m.r8((s.si+0x000000a4u)))&(0x00000005u),8,flags);
  }
  { // 0x402563: 740b JZ 0x00402570
    if(integer::condition("JZ",flags)) goto L00402570;
  }
  { // 0x402565: 8b96d4000000 MOV EDX,dword ptr [ESI + 0xd4]
    s.dx = m.r32((s.si+0x000000d4u));
  }
  { // 0x40256b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40256d: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00402570: { // 0x402570: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  { // 0x402576: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x402578: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x40257b: 8b86bc000000 MOV EAX,dword ptr [ESI + 0xbc]
    s.ax = m.r32((s.si+0x000000bcu));
  }
  { // 0x402581: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x402583: 7404 JZ 0x00402589
    if(integer::condition("JZ",flags)) goto L00402589;
  }
  { // 0x402585: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x402587: ffd0 CALL EAX
    const std::uint32_t call_target=s.ax;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00402589: { // 0x402589: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40258b: c7866801000000000000 MOV dword ptr [ESI + 0x168],0x0
    m.w32((s.si+0x00000168u), 0x00000000u);
  }
  { // 0x402595: e816030000 CALL 0x004028b0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x40259a: 8b96d4000000 MOV EDX,dword ptr [ESI + 0xd4]
    s.dx = m.r32((s.si+0x000000d4u));
  }
  { // 0x4025a0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4025a2: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x4025a5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4025a6: e8d0b03600 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[6u].target;
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  { // 0x4025ab: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4025ae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4025af: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000025b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4025b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4025b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4025b3: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  { // 0x4025b9: ff5028 CALL dword ptr [EAX + 0x28]
    const std::uint32_t call_target=m.r32((s.ax+0x00000028u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4025bc: f686a400000005 TEST byte ptr [ESI + 0xa4],0x5
    (void)integer::logical((m.r8((s.si+0x000000a4u)))&(0x00000005u),8,flags);
  }
  { // 0x4025c3: 740b JZ 0x004025d0
    if(integer::condition("JZ",flags)) goto L004025d0;
  }
  { // 0x4025c5: 8b96d4000000 MOV EDX,dword ptr [ESI + 0xd4]
    s.dx = m.r32((s.si+0x000000d4u));
  }
  { // 0x4025cb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4025cd: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L004025d0: { // 0x4025d0: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  { // 0x4025d6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4025d8: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4025db: 8b86bc000000 MOV EAX,dword ptr [ESI + 0xbc]
    s.ax = m.r32((s.si+0x000000bcu));
  }
  { // 0x4025e1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4025e3: 7404 JZ 0x004025e9
    if(integer::condition("JZ",flags)) goto L004025e9;
  }
  { // 0x4025e5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4025e7: ffd0 CALL EAX
    const std::uint32_t call_target=s.ax;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L004025e9: { // 0x4025e9: c7866801000000000000 MOV dword ptr [ESI + 0x168],0x0
    m.w32((s.si+0x00000168u), 0x00000000u);
  }
  { // 0x4025f3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4025f4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00002720(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x402720: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x402721: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x402723: f686a400000005 TEST byte ptr [ESI + 0xa4],0x5
    (void)integer::logical((m.r8((s.si+0x000000a4u)))&(0x00000005u),8,flags);
  }
  { // 0x40272a: 7407 JZ 0x00402733
    if(integer::condition("JZ",flags)) goto L00402733;
  }
  { // 0x40272c: b800000f80 MOV EAX,0x800f0000
    s.ax = 0x800f0000u;
  }
  { // 0x402731: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x402732: c3 RET
    finish(m,s,f,0u); return;
  }
  L00402733: { // 0x402733: 8b8668010000 MOV EAX,dword ptr [ESI + 0x168]
    s.ax = m.r32((s.si+0x00000168u));
  }
  { // 0x402739: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x40273b: 7507 JNZ 0x00402744
    if(integer::condition("JNZ",flags)) goto L00402744;
  }
  { // 0x40273d: b800000780 MOV EAX,0x80070000
    s.ax = 0x80070000u;
  }
  { // 0x402742: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x402743: c3 RET
    finish(m,s,f,0u); return;
  }
  L00402744: { // 0x402744: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x402745: 8d4e10 LEA ECX,[ESI + 0x10]
    s.cx = (s.si+0x00000010u);
  }
  { // 0x402748: e833e9ffff CALL 0x00401080
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40274d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40274f: e8ccfaffff CALL 0x00402220
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x402754: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  { // 0x40275a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40275c: ff5028 CALL dword ptr [EAX + 0x28]
    const std::uint32_t call_target=m.r32((s.ax+0x00000028u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x40275f: 8b96d4000000 MOV EDX,dword ptr [ESI + 0xd4]
    s.dx = m.r32((s.si+0x000000d4u));
  }
  { // 0x402765: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x402767: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x40276a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x40276c: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x40276e: 750e JNZ 0x0040277e
    if(integer::condition("JNZ",flags)) goto L0040277e;
  }
  { // 0x402770: 8b86a4000000 MOV EAX,dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  { // 0x402776: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  { // 0x402778: 8986a4000000 MOV dword ptr [ESI + 0xa4],EAX
    m.w32((s.si+0x000000a4u), s.ax);
  }
  L0040277e: { // 0x40277e: 8b96d4000000 MOV EDX,dword ptr [ESI + 0xd4]
    s.dx = m.r32((s.si+0x000000d4u));
  }
  { // 0x402784: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x402786: ff522c CALL dword ptr [EDX + 0x2c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000002cu));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x402789: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x40278b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x40278c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40278d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00002b80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x402b80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x402b81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x402b83: e8f8470000 CALL 0x00407380
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x402b88: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x402b8b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x402b8d: ff5018 CALL dword ptr [EAX + 0x18]
    const std::uint32_t call_target=m.r32((s.ax+0x00000018u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x402b90: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x402b93: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x402b94: 83600cfe AND dword ptr [EAX + 0xc],0xfffffffe
    m.w32((s.ax+0x0000000cu), integer::logical((m.r32((s.ax+0x0000000cu)))&(0xfffffffeu),32,flags));
  }
  { // 0x402b98: e8deaa3600 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x402b9d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x402ba0: c705888e810000000000 MOV dword ptr [0x00818e88],0x0
    m.w32((0x00818e88u), 0x00000000u);
  }
  { // 0x402baa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x402bab: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00007e60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x407e60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x407e61: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x407e63: 8b8688000000 MOV EAX,dword ptr [ESI + 0x88]
    s.ax = m.r32((s.si+0x00000088u));
  }
  { // 0x407e69: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x407e6b: 7525 JNZ 0x00407e92
    if(integer::condition("JNZ",flags)) goto L00407e92;
  }
  { // 0x407e6d: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x407e70: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x407e72: 741e JZ 0x00407e92
    if(integer::condition("JZ",flags)) goto L00407e92;
  }
  { // 0x407e74: 6848988100 PUSH 0x819848
    f.push(m,0x00819848u);
  }
  { // 0x407e79: ff15dc517800 CALL dword ptr [0x007851dc]
    const std::uint32_t call_target=m.r32((0x007851dcu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x407e7f: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x407e82: e829a7ffff CALL 0x004025b0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x407e87: 6848988100 PUSH 0x819848
    f.push(m,0x00819848u);
  }
  { // 0x407e8c: ff15e0517800 CALL dword ptr [0x007851e0]
    const std::uint32_t call_target=m.r32((0x007851e0u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00407e92: { // 0x407e92: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x407e93: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00007ed0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x407ed0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x407ed1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x407ed3: 8b8680000000 MOV EAX,dword ptr [ESI + 0x80]
    s.ax = m.r32((s.si+0x00000080u));
  }
  { // 0x407ed9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x407edb: 7533 JNZ 0x00407f10
    if(integer::condition("JNZ",flags)) goto L00407f10;
  }
  { // 0x407edd: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x407ee0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x407ee2: 742c JZ 0x00407f10
    if(integer::condition("JZ",flags)) goto L00407f10;
  }
  { // 0x407ee4: 6848988100 PUSH 0x819848
    f.push(m,0x00819848u);
  }
  { // 0x407ee9: ff15dc517800 CALL dword ptr [0x007851dc]
    const std::uint32_t call_target=m.r32((0x007851dcu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x407eef: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x407ef2: e809a7ffff CALL 0x00402600
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x407ef7: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x407efa: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x407efc: 7407 JZ 0x00407f05
    if(integer::condition("JZ",flags)) goto L00407f05;
  }
  { // 0x407efe: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  { // 0x407f00: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  { // 0x407f02: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00407f05: { // 0x407f05: 6848988100 PUSH 0x819848
    f.push(m,0x00819848u);
  }
  { // 0x407f0a: ff15e0517800 CALL dword ptr [0x007851e0]
    const std::uint32_t call_target=m.r32((0x007851e0u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00407f10: { // 0x407f10: 8b8680000000 MOV EAX,dword ptr [ESI + 0x80]
    s.ax = m.r32((s.si+0x00000080u));
  }
  { // 0x407f16: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x407f17: 898680000000 MOV dword ptr [ESI + 0x80],EAX
    m.w32((s.si+0x00000080u), s.ax);
  }
  { // 0x407f1d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x407f1e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00007f20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x407f20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x407f21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x407f23: 8b8680000000 MOV EAX,dword ptr [ESI + 0x80]
    s.ax = m.r32((s.si+0x00000080u));
  }
  { // 0x407f29: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x407f2b: 7458 JZ 0x00407f85
    if(integer::condition("JZ",flags)) goto L00407f85;
  }
  { // 0x407f2d: 8b8680000000 MOV EAX,dword ptr [ESI + 0x80]
    s.ax = m.r32((s.si+0x00000080u));
  }
  { // 0x407f33: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x407f34: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x407f36: 898680000000 MOV dword ptr [ESI + 0x80],EAX
    m.w32((s.si+0x00000080u), s.ax);
  }
  { // 0x407f3c: 7d0a JGE 0x00407f48
    if(integer::condition("JGE",flags)) goto L00407f48;
  }
  { // 0x407f3e: c7868000000000000000 MOV dword ptr [ESI + 0x80],0x0
    m.w32((s.si+0x00000080u), 0x00000000u);
  }
  L00407f48: { // 0x407f48: 8b8680000000 MOV EAX,dword ptr [ESI + 0x80]
    s.ax = m.r32((s.si+0x00000080u));
  }
  { // 0x407f4e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x407f50: 7533 JNZ 0x00407f85
    if(integer::condition("JNZ",flags)) goto L00407f85;
  }
  { // 0x407f52: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x407f55: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x407f57: 742c JZ 0x00407f85
    if(integer::condition("JZ",flags)) goto L00407f85;
  }
  { // 0x407f59: 6848988100 PUSH 0x819848
    f.push(m,0x00819848u);
  }
  { // 0x407f5e: ff15dc517800 CALL dword ptr [0x007851dc]
    const std::uint32_t call_target=m.r32((0x007851dcu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x407f64: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x407f67: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  { // 0x407f69: 7407 JZ 0x00407f72
    if(integer::condition("JZ",flags)) goto L00407f72;
  }
  { // 0x407f6b: 24fd AND AL,0xfd
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fdu),8,flags));
  }
  { // 0x407f6d: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  { // 0x407f6f: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00407f72: { // 0x407f72: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x407f75: e8d6a6ffff CALL 0x00402650
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x407f7a: 6848988100 PUSH 0x819848
    f.push(m,0x00819848u);
  }
  { // 0x407f7f: ff15e0517800 CALL dword ptr [0x007851e0]
    const std::uint32_t call_target=m.r32((0x007851e0u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00407f85: { // 0x407f85: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x407f86: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00009280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x409280: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x409283: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x409287: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x409288: ff15cc517800 CALL dword ptr [0x007851cc]
    const std::uint32_t call_target=m.r32((0x007851ccu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40928e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x409290: 742f JZ 0x004092c1
    if(integer::condition("JZ",flags)) goto L004092c1;
  }
  { // 0x409292: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x409296: 8b542400 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  { // 0x40929a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x40929c: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  { // 0x4092a1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4092a2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4092a3: e8684b3600 CALL 0x0076de10
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4092a8: a378988100 MOV [0x00819878],EAX
    m.w32((0x00819878u), s.ax);
  }
  { // 0x4092ad: 89157c988100 MOV dword ptr [0x0081987c],EDX
    m.w32((0x0081987cu), s.dx);
  }
  { // 0x4092b3: c70598988100e0924000 MOV dword ptr [0x00819898],0x4092e0
    m.w32((0x00819898u), 0x004092e0u);
  }
  { // 0x4092bd: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4092c0: c3 RET
    finish(m,s,f,0u); return;
  }
  L004092c1: { // 0x4092c1: c7059898810010934000 MOV dword ptr [0x00819898],0x409310
    m.w32((0x00819898u), 0x00409310u);
  }
  { // 0x4092cb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4092ce: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0000a530(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x40a530: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x40a531: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x40a533: f686a400000005 TEST byte ptr [ESI + 0xa4],0x5
    (void)integer::logical((m.r8((s.si+0x000000a4u)))&(0x00000005u),8,flags);
  }
  { // 0x40a53a: 7421 JZ 0x0040a55d
    if(integer::condition("JZ",flags)) goto L0040a55d;
  }
  { // 0x40a53c: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    s.ax = m.r32((s.si+0x00000158u));
  }
  { // 0x40a542: 8b4064 MOV EAX,dword ptr [EAX + 0x64]
    s.ax = m.r32((s.ax+0x00000064u));
  }
  { // 0x40a545: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x40a547: 7406 JZ 0x0040a54f
    if(integer::condition("JZ",flags)) goto L0040a54f;
  }
  { // 0x40a549: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x40a54b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x40a54c: ff5148 CALL dword ptr [ECX + 0x48]
    const std::uint32_t call_target=m.r32((s.cx+0x00000048u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0040a54f: { // 0x40a54f: 8b8664010000 MOV EAX,dword ptr [ESI + 0x164]
    s.ax = m.r32((s.si+0x00000164u));
  }
  { // 0x40a555: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x40a557: 7404 JZ 0x0040a55d
    if(integer::condition("JZ",flags)) goto L0040a55d;
  }
  { // 0x40a559: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40a55b: ffd0 CALL EAX
    const std::uint32_t call_target=s.ax;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0040a55d: { // 0x40a55d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x40a55f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40a560: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0000a870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x40a870: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x40a871: a1f0988100 MOV EAX,[0x008198f0]
    s.ax = m.r32((0x008198f0u));
  }
  { // 0x40a876: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x40a878: 7435 JZ 0x0040a8af
    if(integer::condition("JZ",flags)) goto L0040a8af;
  }
  { // 0x40a87a: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x40a87c: 8d542400 LEA EDX,[ESP]
    s.dx = (f.sp);
  }
  { // 0x40a880: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x40a881: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x40a882: ff5124 CALL dword ptr [ECX + 0x24]
    const std::uint32_t call_target=m.r32((s.cx+0x00000024u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40a885: f644240002 TEST byte ptr [ESP],0x2
    (void)integer::logical((m.r8((f.sp)))&(0x00000002u),8,flags);
  }
  { // 0x40a88a: 740b JZ 0x0040a897
    if(integer::condition("JZ",flags)) goto L0040a897;
  }
  { // 0x40a88c: a1f0988100 MOV EAX,[0x008198f0]
    s.ax = m.r32((0x008198f0u));
  }
  { // 0x40a891: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x40a892: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x40a894: ff5150 CALL dword ptr [ECX + 0x50]
    const std::uint32_t call_target=m.r32((s.cx+0x00000050u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0040a897: { // 0x40a897: f644240001 TEST byte ptr [ESP],0x1
    (void)integer::logical((m.r8((f.sp)))&(0x00000001u),8,flags);
  }
  { // 0x40a89c: 7511 JNZ 0x0040a8af
    if(integer::condition("JNZ",flags)) goto L0040a8af;
  }
  { // 0x40a89e: a1f0988100 MOV EAX,[0x008198f0]
    s.ax = m.r32((0x008198f0u));
  }
  { // 0x40a8a3: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x40a8a5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x40a8a7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x40a8a9: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x40a8ab: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x40a8ac: ff5230 CALL dword ptr [EDX + 0x30]
    const std::uint32_t call_target=m.r32((s.dx+0x00000030u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L0040a8af: { // 0x40a8af: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x40a8b0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000100c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4100c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4100c1: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4100c5: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4100c7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4100c8: 750a JNZ 0x004100d4
    if(integer::condition("JNZ",flags)) goto L004100d4;
  }
  { // 0x4100ca: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4100cb: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  { // 0x4100d0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4100d1: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L004100d4: { // 0x4100d4: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4100d8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4100da: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4100dc: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  { // 0x4100e0: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x4100e2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4100e3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4100e4: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  { // 0x4100e8: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4100eb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4100ed: 7c23 JL 0x00410112
    if(integer::condition("JL",flags)) goto L00410112;
  }
  { // 0x4100ef: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  { // 0x4100f1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4100f2: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  { // 0x4100f4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4100f6: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4100f8: ff5230 CALL dword ptr [EDX + 0x30]
    const std::uint32_t call_target=m.r32((s.dx+0x00000030u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4100fb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4100fc: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4100fd: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4100fe: ff5310 CALL dword ptr [EBX + 0x10]
    const std::uint32_t call_target=m.r32((s.bx+0x00000010u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x410101: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x410103: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x410104: 7c0c JL 0x00410112
    if(integer::condition("JL",flags)) goto L00410112;
  }
  { // 0x410106: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x41010a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x41010c: 7404 JZ 0x00410112
    if(integer::condition("JZ",flags)) goto L00410112;
  }
  { // 0x41010e: c6472000 MOV byte ptr [EDI + 0x20],0x0
    m.w8((s.di+0x00000020u), 0x00000000u);
  }
  L00410112: { // 0x410112: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x410113: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x410114: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00010120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x410120: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x410121: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x410125: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x410127: 7509 JNZ 0x00410132
    if(integer::condition("JNZ",flags)) goto L00410132;
  }
  { // 0x410129: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  { // 0x41012e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x41012f: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00410132: { // 0x410132: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x410134: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x410136: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x41013a: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x41013c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x41013d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x41013e: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x410141: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x410143: 7c31 JL 0x00410176
    if(integer::condition("JL",flags)) goto L00410176;
  }
  { // 0x410145: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x410149: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x41014a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x41014b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41014c: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  { // 0x410150: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x410151: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x410152: 687053aa00 PUSH 0xaa5370
    f.push(m,0x00aa5370u);
  }
  { // 0x410157: e894502800 CALL 0x006951f0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x41015c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x41015e: 8b5e1c MOV EBX,dword ptr [ESI + 0x1c]
    s.bx = m.r32((s.si+0x0000001cu));
  }
  { // 0x410161: 8b2f MOV EBP,dword ptr [EDI]
    s.bp = m.r32((s.di));
  }
  { // 0x410163: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x410165: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x410167: ff5030 CALL dword ptr [EAX + 0x30]
    const std::uint32_t call_target=m.r32((s.ax+0x00000030u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x41016a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x41016b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41016c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x41016d: ff550c CALL dword ptr [EBP + 0xc]
    const std::uint32_t call_target=m.r32((s.bp+0x0000000cu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x410170: 895e1c MOV dword ptr [ESI + 0x1c],EBX
    m.w32((s.si+0x0000001cu), s.bx);
  }
  { // 0x410173: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x410174: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x410175: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00410176: { // 0x410176: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x410177: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00010740(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x410740: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x410741: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x410742: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x410744: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x410748: b97885a200 MOV ECX,0xa28578
    s.cx = 0x00a28578u;
  }
  { // 0x41074d: c706885e7800 MOV dword ptr [ESI],0x785e88
    m.w32((s.si), 0x00785e88u);
  }
  { // 0x410753: c746046c5e7800 MOV dword ptr [ESI + 0x4],0x785e6c
    m.w32((s.si+0x00000004u), 0x00785e6cu);
  }
  { // 0x41075a: c74608645e7800 MOV dword ptr [ESI + 0x8],0x785e64
    m.w32((s.si+0x00000008u), 0x00785e64u);
  }
  { // 0x410761: c7460c5c5e7800 MOV dword ptr [ESI + 0xc],0x785e5c
    m.w32((s.si+0x0000000cu), 0x00785e5cu);
  }
  { // 0x410768: 8b157885a200 MOV EDX,dword ptr [0x00a28578]
    s.dx = m.r32((0x00a28578u));
  }
  { // 0x41076e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x41076f: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  { // 0x410773: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x410776: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x410779: 742d JZ 0x004107a8
    if(integer::condition("JZ",flags)) goto L004107a8;
  }
  { // 0x41077b: 8b0d8885a200 MOV ECX,dword ptr [0x00a28588]
    s.cx = m.r32((0x00a28588u));
  }
  { // 0x410781: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x410783: 7d23 JGE 0x004107a8
    if(integer::condition("JGE",flags)) goto L004107a8;
  }
  { // 0x410785: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x410786: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x410788: 890d8885a200 MOV dword ptr [0x00a28588],ECX
    m.w32((0x00a28588u), s.cx);
  }
  { // 0x41078e: 7d18 JGE 0x004107a8
    if(integer::condition("JGE",flags)) goto L004107a8;
  }
  L00410790: { // 0x410790: 8b0d7c85a200 MOV ECX,dword ptr [0x00a2857c]
    s.cx = m.r32((0x00a2857cu));
  }
  { // 0x410796: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x410797: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x41079a: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  { // 0x41079e: 8b0d8885a200 MOV ECX,dword ptr [0x00a28588]
    s.cx = m.r32((0x00a28588u));
  }
  { // 0x4107a4: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4107a6: 7ce8 JL 0x00410790
    if(integer::condition("JL",flags)) goto L00410790;
  }
  L004107a8: { // 0x4107a8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4107aa: e8e1f7ffff CALL 0x0040ff90
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4107af: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4107b0: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x4107b1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00011230(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x411230: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x411234: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x411235: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x411237: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x411238: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x411239: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x41123d: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x411240: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x411241: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x411243: ff505c CALL dword ptr [EAX + 0x5c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000005cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x411246: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x411249: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x41124b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x41124d: ff5060 CALL dword ptr [EAX + 0x60]
    const std::uint32_t call_target=m.r32((s.ax+0x00000060u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x411250: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x411253: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  { // 0x411256: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x411258: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x41125a: 7203 JC 0x0041125f
    if(integer::condition("JC",flags)) goto L0041125f;
  }
  { // 0x41125c: 2b4620 SUB EAX,dword ptr [ESI + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x00000020u)),32,flags);
  }
  L0041125f: { // 0x41125f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x411260: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x411261: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00011370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x411370: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x411371: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x411372: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x411374: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x411375: 8b7e0c MOV EDI,dword ptr [ESI + 0xc]
    s.di = m.r32((s.si+0x0000000cu));
  }
  { // 0x411378: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x41137a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x41137b: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  { // 0x41137e: 8b7e14 MOV EDI,dword ptr [ESI + 0x14]
    s.di = m.r32((s.si+0x00000014u));
  }
  { // 0x411381: ff5070 CALL dword ptr [EAX + 0x70]
    const std::uint32_t call_target=m.r32((s.ax+0x00000070u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x411384: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x411386: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x411388: 0faf5c2410 IMUL EBX,dword ptr [ESP + 0x10]
    s.bx = integer::imul(s.bx,m.r32((f.sp+0x00000010u)),32,flags);
  }
  { // 0x41138d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x41138f: ff5274 CALL dword ptr [EDX + 0x74]
    const std::uint32_t call_target=m.r32((s.dx+0x00000074u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x411392: 0faf442414 IMUL EAX,dword ptr [ESP + 0x14]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000014u)),32,flags);
  }
  { // 0x411397: 03fb ADD EDI,EBX
    s.di = integer::add(s.di,s.bx,32,flags);
  }
  { // 0x411399: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x41139b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x41139c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41139d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x41139e: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00017840(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x417840: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x417841: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x417843: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x417849: e862cf0d00 CALL 0x004f47b0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x41784e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x417850: 7506 JNZ 0x00417858
    if(integer::condition("JNZ",flags)) goto L00417858;
  }
  { // 0x417852: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x417854: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x417855: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00417858: { // 0x417858: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x41785c: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x417860: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x417864: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x417865: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x417866: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x417867: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x417868: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x41786a: e8e1490b00 CALL 0x004cc250
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x41786f: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x417871: 83ff05 CMP EDI,0x5
    (void)integer::sub(s.di,0x00000005u,32,flags);
  }
  { // 0x417874: 7513 JNZ 0x00417889
    if(integer::condition("JNZ",flags)) goto L00417889;
  }
  { // 0x417876: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x417878: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x41787a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x41787c: ff909c030000 CALL dword ptr [EAX + 0x39c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000039cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x417882: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  { // 0x417885: 7502 JNZ 0x00417889
    if(integer::condition("JNZ",flags)) goto L00417889;
  }
  { // 0x417887: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00417889: { // 0x417889: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x41788b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x41788c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41788d: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00019cd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x419cd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x419cd1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x419cd3: e8f8811700 CALL 0x00591ed0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x419cd8: 8a4809 MOV CL,byte ptr [EAX + 0x9]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000009u)));
  }
  { // 0x419cdb: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x419cdd: 740e JZ 0x00419ced
    if(integer::condition("JZ",flags)) goto L00419ced;
  }
  { // 0x419cdf: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x419ce1: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x419ce3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x419ce5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x419ce7: ff9014040000 CALL dword ptr [EAX + 0x414]
    const std::uint32_t call_target=m.r32((s.ax+0x00000414u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00419ced: { // 0x419ced: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x419cee: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0001a500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41a500: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41a501: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x41a503: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x41a509: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x41a50b: 750a JNZ 0x0041a517
    if(integer::condition("JNZ",flags)) goto L0041a517;
  }
  { // 0x41a50d: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x41a512: e8596d3600 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0041a517: { // 0x41a517: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x41a51d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x41a51e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x41a520: ff5174 CALL dword ptr [ECX + 0x74]
    const std::uint32_t call_target=m.r32((s.cx+0x00000074u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x41a523: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41a524: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0001afd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41afd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41afd1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x41afd3: 8b8628020000 MOV EAX,dword ptr [ESI + 0x228]
    s.ax = m.r32((s.si+0x00000228u));
  }
  { // 0x41afd9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x41afdb: 754b JNZ 0x0041b028
    if(integer::condition("JNZ",flags)) goto L0041b028;
  }
  { // 0x41afdd: 8a862d030000 MOV AL,byte ptr [ESI + 0x32d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000032du)));
  }
  { // 0x41afe3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x41afe5: 7441 JZ 0x0041b028
    if(integer::condition("JZ",flags)) goto L0041b028;
  }
  { // 0x41afe7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x41afe9: ff906c010000 CALL dword ptr [EAX + 0x16c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000016cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x41afef: 83f81a CMP EAX,0x1a
    (void)integer::sub(s.ax,0x0000001au,32,flags);
  }
  { // 0x41aff2: 7434 JZ 0x0041b028
    if(integer::condition("JZ",flags)) goto L0041b028;
  }
  { // 0x41aff4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x41aff6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x41aff8: ff926c010000 CALL dword ptr [EDX + 0x16c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000016cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x41affe: 83f81b CMP EAX,0x1b
    (void)integer::sub(s.ax,0x0000001bu,32,flags);
  }
  { // 0x41b001: 7425 JZ 0x0041b028
    if(integer::condition("JZ",flags)) goto L0041b028;
  }
  { // 0x41b003: 8b8ec4040000 MOV ECX,dword ptr [ESI + 0x4c4]
    s.cx = m.r32((s.si+0x000004c4u));
  }
  { // 0x41b009: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x41b00b: 750e JNZ 0x0041b01b
    if(integer::condition("JNZ",flags)) goto L0041b01b;
  }
  { // 0x41b00d: 8a862c030000 MOV AL,byte ptr [ESI + 0x32c]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000032cu)));
  }
  { // 0x41b013: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x41b015: 750d JNZ 0x0041b024
    if(integer::condition("JNZ",flags)) goto L0041b024;
  }
  { // 0x41b017: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x41b019: 740d JZ 0x0041b028
    if(integer::condition("JZ",flags)) goto L0041b028;
  }
  L0041b01b: { // 0x41b01b: e8c04f2900 CALL 0x006affe0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x41b020: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x41b022: 7404 JZ 0x0041b028
    if(integer::condition("JZ",flags)) goto L0041b028;
  }
  L0041b024: { // 0x41b024: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x41b026: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41b027: c3 RET
    finish(m,s,f,0u); return;
  }
  L0041b028: { // 0x41b028: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x41b02a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41b02b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0001b050(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41b050: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41b051: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x41b053: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  { // 0x41b059: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  { // 0x41b05f: 3b8134040000 CMP EAX,dword ptr [ECX + 0x434]
    (void)integer::sub(s.ax,m.r32((s.cx+0x00000434u)),32,flags);
  }
  { // 0x41b065: 7411 JZ 0x0041b078
    if(integer::condition("JZ",flags)) goto L0041b078;
  }
  { // 0x41b067: 3b8164040000 CMP EAX,dword ptr [ECX + 0x464]
    (void)integer::sub(s.ax,m.r32((s.cx+0x00000464u)),32,flags);
  }
  { // 0x41b06d: 7409 JZ 0x0041b078
    if(integer::condition("JZ",flags)) goto L0041b078;
  }
  { // 0x41b06f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x41b071: e8fa190b00 CALL 0x004cca70
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x41b076: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41b077: c3 RET
    finish(m,s,f,0u); return;
  }
  L0041b078: { // 0x41b078: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x41b07e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x41b080: 750a JNZ 0x0041b08c
    if(integer::condition("JNZ",flags)) goto L0041b08c;
  }
  { // 0x41b082: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x41b087: e8e4613600 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0041b08c: { // 0x41b08c: 8bb664050000 MOV ESI,dword ptr [ESI + 0x564]
    s.si = m.r32((s.si+0x00000564u));
  }
  { // 0x41b092: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41b093: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x41b095: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x41b09b: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  { // 0x41b09d: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x41b09f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41b0a0: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x41b0a2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0001b0b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41b0b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41b0b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x41b0b3: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  { // 0x41b0b9: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  { // 0x41b0bf: 3b8134040000 CMP EAX,dword ptr [ECX + 0x434]
    (void)integer::sub(s.ax,m.r32((s.cx+0x00000434u)),32,flags);
  }
  { // 0x41b0c5: 7411 JZ 0x0041b0d8
    if(integer::condition("JZ",flags)) goto L0041b0d8;
  }
  { // 0x41b0c7: 3b8164040000 CMP EAX,dword ptr [ECX + 0x464]
    (void)integer::sub(s.ax,m.r32((s.cx+0x00000464u)),32,flags);
  }
  { // 0x41b0cd: 7409 JZ 0x0041b0d8
    if(integer::condition("JZ",flags)) goto L0041b0d8;
  }
  { // 0x41b0cf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x41b0d1: e89a291b00 CALL 0x005cda70
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x41b0d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41b0d7: c3 RET
    finish(m,s,f,0u); return;
  }
  L0041b0d8: { // 0x41b0d8: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x41b0de: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x41b0e0: 750a JNZ 0x0041b0ec
    if(integer::condition("JNZ",flags)) goto L0041b0ec;
  }
  { // 0x41b0e2: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x41b0e7: e884613600 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0041b0ec: { // 0x41b0ec: 8bb664050000 MOV ESI,dword ptr [ESI + 0x564]
    s.si = m.r32((s.si+0x00000564u));
  }
  { // 0x41b0f2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41b0f3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x41b0f5: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x41b0fb: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  { // 0x41b0fd: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x41b0ff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41b100: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x41b101: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0001b1e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41b1e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41b1e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x41b1e3: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  { // 0x41b1e9: 8a88a30b0000 MOV CL,byte ptr [EAX + 0xba3]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000ba3u)));
  }
  { // 0x41b1ef: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x41b1f1: 7426 JZ 0x0041b219
    if(integer::condition("JZ",flags)) goto L0041b219;
  }
  { // 0x41b1f3: 8b86b4050000 MOV EAX,dword ptr [ESI + 0x5b4]
    s.ax = m.r32((s.si+0x000005b4u));
  }
  { // 0x41b1f9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x41b1fb: 741c JZ 0x0041b219
    if(integer::condition("JZ",flags)) goto L0041b219;
  }
  { // 0x41b1fd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x41b1ff: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x41b200: 6a0f PUSH 0xf
    f.push(m,0x0000000fu);
  }
  { // 0x41b202: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x41b204: ff9258020000 CALL dword ptr [EDX + 0x258]
    const std::uint32_t call_target=m.r32((s.dx+0x00000258u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x41b20a: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x41b20d: 7427 JZ 0x0041b236
    if(integer::condition("JZ",flags)) goto L0041b236;
  }
  { // 0x41b20f: c786b405000000000000 MOV dword ptr [ESI + 0x5b4],0x0
    m.w32((s.si+0x000005b4u), 0x00000000u);
  }
  L0041b219: { // 0x41b219: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x41b21d: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x41b221: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x41b222: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x41b224: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x41b225: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x41b227: e8f4220b00 CALL 0x004cd520
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x41b22c: 8986b4050000 MOV dword ptr [ESI + 0x5b4],EAX
    m.w32((s.si+0x000005b4u), s.ax);
  }
  { // 0x41b232: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41b233: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0041b236: { // 0x41b236: 8b86b4050000 MOV EAX,dword ptr [ESI + 0x5b4]
    s.ax = m.r32((s.si+0x000005b4u));
  }
  { // 0x41b23c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41b23d: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0001e510(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41e510: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x41e514: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x41e516: 7473 JZ 0x0041e58b
    if(integer::condition("JZ",flags)) goto L0041e58b;
  }
  { // 0x41e518: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  { // 0x41e51c: 8b9004000200 MOV EDX,dword ptr [EAX + 0x20004]
    s.dx = m.r32((s.ax+0x00020004u));
  }
  { // 0x41e522: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x41e523: 899004000200 MOV dword ptr [EAX + 0x20004],EDX
    m.w32((s.ax+0x00020004u), s.dx);
  }
  { // 0x41e529: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x41e52d: 8b8804000200 MOV ECX,dword ptr [EAX + 0x20004]
    s.cx = m.r32((s.ax+0x00020004u));
  }
  { // 0x41e533: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x41e535: 7554 JNZ 0x0041e58b
    if(integer::condition("JNZ",flags)) goto L0041e58b;
  }
  { // 0x41e537: 8b1520498200 MOV EDX,dword ptr [0x00824920]
    s.dx = m.r32((0x00824920u));
  }
  { // 0x41e53d: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x41e541: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x41e542: b920498200 MOV ECX,0x824920
    s.cx = 0x00824920u;
  }
  { // 0x41e547: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x41e54a: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x41e54d: 742d JZ 0x0041e57c
    if(integer::condition("JZ",flags)) goto L0041e57c;
  }
  { // 0x41e54f: 8b0d30498200 MOV ECX,dword ptr [0x00824930]
    s.cx = m.r32((0x00824930u));
  }
  { // 0x41e555: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x41e557: 7d23 JGE 0x0041e57c
    if(integer::condition("JGE",flags)) goto L0041e57c;
  }
  { // 0x41e559: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x41e55a: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x41e55c: 890d30498200 MOV dword ptr [0x00824930],ECX
    m.w32((0x00824930u), s.cx);
  }
  { // 0x41e562: 7d18 JGE 0x0041e57c
    if(integer::condition("JGE",flags)) goto L0041e57c;
  }
  L0041e564: { // 0x41e564: 8b0d24498200 MOV ECX,dword ptr [0x00824924]
    s.cx = m.r32((0x00824924u));
  }
  { // 0x41e56a: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x41e56b: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x41e56e: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  { // 0x41e572: 8b0d30498200 MOV ECX,dword ptr [0x00824930]
    s.cx = m.r32((0x00824930u));
  }
  { // 0x41e578: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x41e57a: 7ce8 JL 0x0041e564
    if(integer::condition("JL",flags)) goto L0041e564;
  }
  L0041e57c: { // 0x41e57c: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x41e580: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x41e582: 7407 JZ 0x0041e58b
    if(integer::condition("JZ",flags)) goto L0041e58b;
  }
  { // 0x41e584: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x41e585: e8f1f03400 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x41e58a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0041e58b: { // 0x41e58b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00023ff0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x423ff0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x423ff1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x423ff2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x423ff4: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x423ff6: 8a8689000000 MOV AL,byte ptr [ESI + 0x89]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000089u)));
  }
  { // 0x423ffc: c70694727800 MOV dword ptr [ESI],0x787294
    m.w32((s.si), 0x00787294u);
  }
  { // 0x424002: 3ac3 CMP AL,BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  { // 0x424004: 7411 JZ 0x00424017
    if(integer::condition("JZ",flags)) goto L00424017;
  }
  { // 0x424006: 8b8e84000000 MOV ECX,dword ptr [ESI + 0x84]
    s.cx = m.r32((s.si+0x00000084u));
  }
  { // 0x42400c: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x42400e: ff5034 CALL dword ptr [EAX + 0x34]
    const std::uint32_t call_target=m.r32((s.ax+0x00000034u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x424011: 889e89000000 MOV byte ptr [ESI + 0x89],BL
    m.w8((s.si+0x00000089u), (s.bx & 0xffu));
  }
  L00424017: { // 0x424017: 8b8e0c0e0000 MOV ECX,dword ptr [ESI + 0xe0c]
    s.cx = m.r32((s.si+0x00000e0cu));
  }
  { // 0x42401d: 899e84000000 MOV dword ptr [ESI + 0x84],EBX
    m.w32((s.si+0x00000084u), s.bx);
  }
  { // 0x424023: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  { // 0x424025: 740c JZ 0x00424033
    if(integer::condition("JZ",flags)) goto L00424033;
  }
  { // 0x424027: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x424029: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x42402b: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x42402d: 899e0c0e0000 MOV dword ptr [ESI + 0xe0c],EBX
    m.w32((s.si+0x00000e0cu), s.bx);
  }
  L00424033: { // 0x424033: 8b86100e0000 MOV EAX,dword ptr [ESI + 0xe10]
    s.ax = m.r32((s.si+0x00000e10u));
  }
  { // 0x424039: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x42403b: 740f JZ 0x0042404c
    if(integer::condition("JZ",flags)) goto L0042404c;
  }
  { // 0x42403d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x42403e: e838963400 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x424043: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x424046: 899e100e0000 MOV dword ptr [ESI + 0xe10],EBX
    m.w32((s.si+0x00000e10u), s.bx);
  }
  L0042404c: { // 0x42404c: 889e88000000 MOV byte ptr [ESI + 0x88],BL
    m.w8((s.si+0x00000088u), (s.bx & 0xffu));
  }
  { // 0x424052: c706b8727800 MOV dword ptr [ESI],0x7872b8
    m.w32((s.si), 0x007872b8u);
  }
  { // 0x424058: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x424059: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x42405a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00024070(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x424070: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x424071: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x424073: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x424077: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x424079: 898e84000000 MOV dword ptr [ESI + 0x84],ECX
    m.w32((s.si+0x00000084u), s.cx);
  }
  { // 0x42407f: 7428 JZ 0x004240a9
    if(integer::condition("JZ",flags)) goto L004240a9;
  }
  { // 0x424081: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x424083: ff5018 CALL dword ptr [EAX + 0x18]
    const std::uint32_t call_target=m.r32((s.ax+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x424086: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x424088: 7514 JNZ 0x0042409e
    if(integer::condition("JNZ",flags)) goto L0042409e;
  }
  { // 0x42408a: 8b8e84000000 MOV ECX,dword ptr [ESI + 0x84]
    s.cx = m.r32((s.si+0x00000084u));
  }
  { // 0x424090: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x424092: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x424094: ff521c CALL dword ptr [EDX + 0x1c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000001cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x424097: c6868900000001 MOV byte ptr [ESI + 0x89],0x1
    m.w8((s.si+0x00000089u), 0x00000001u);
  }
  L0042409e: { // 0x42409e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4240a0: e86b000000 CALL 0x00424110
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4240a5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4240a6: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004240a9: { // 0x4240a9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4240ab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4240ac: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000240b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4240b0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4240b1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4240b2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4240b4: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x4240b6: 389e89000000 CMP byte ptr [ESI + 0x89],BL
    (void)integer::sub(m.r8((s.si+0x00000089u)),(s.bx & 0xffu),8,flags);
  }
  { // 0x4240bc: 7411 JZ 0x004240cf
    if(integer::condition("JZ",flags)) goto L004240cf;
  }
  { // 0x4240be: 8b8e84000000 MOV ECX,dword ptr [ESI + 0x84]
    s.cx = m.r32((s.si+0x00000084u));
  }
  { // 0x4240c4: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x4240c6: ff5034 CALL dword ptr [EAX + 0x34]
    const std::uint32_t call_target=m.r32((s.ax+0x00000034u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4240c9: 889e89000000 MOV byte ptr [ESI + 0x89],BL
    m.w8((s.si+0x00000089u), (s.bx & 0xffu));
  }
  L004240cf: { // 0x4240cf: 8b8e0c0e0000 MOV ECX,dword ptr [ESI + 0xe0c]
    s.cx = m.r32((s.si+0x00000e0cu));
  }
  { // 0x4240d5: 899e84000000 MOV dword ptr [ESI + 0x84],EBX
    m.w32((s.si+0x00000084u), s.bx);
  }
  { // 0x4240db: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  { // 0x4240dd: 740c JZ 0x004240eb
    if(integer::condition("JZ",flags)) goto L004240eb;
  }
  { // 0x4240df: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x4240e1: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4240e3: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4240e5: 899e0c0e0000 MOV dword ptr [ESI + 0xe0c],EBX
    m.w32((s.si+0x00000e0cu), s.bx);
  }
  L004240eb: { // 0x4240eb: 8b86100e0000 MOV EAX,dword ptr [ESI + 0xe10]
    s.ax = m.r32((s.si+0x00000e10u));
  }
  { // 0x4240f1: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x4240f3: 740f JZ 0x00424104
    if(integer::condition("JZ",flags)) goto L00424104;
  }
  { // 0x4240f5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4240f6: e880953400 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4240fb: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4240fe: 899e100e0000 MOV dword ptr [ESI + 0xe10],EBX
    m.w32((s.si+0x00000e10u), s.bx);
  }
  L00424104: { // 0x424104: 889e88000000 MOV byte ptr [ESI + 0x88],BL
    m.w8((s.si+0x00000088u), (s.bx & 0xffu));
  }
  { // 0x42410a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42410b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x42410c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00024720(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x424720: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x424721: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x424723: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x424724: 8a8688000000 MOV AL,byte ptr [ESI + 0x88]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000088u)));
  }
  { // 0x42472a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x42472c: 7469 JZ 0x00424797
    if(integer::condition("JZ",flags)) goto L00424797;
  }
  { // 0x42472e: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x424732: 8b86180e0000 MOV EAX,dword ptr [ESI + 0xe18]
    s.ax = m.r32((s.si+0x00000e18u));
  }
  { // 0x424738: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x42473a: 7454 JZ 0x00424790
    if(integer::condition("JZ",flags)) goto L00424790;
  }
  { // 0x42473c: 8b8e84000000 MOV ECX,dword ptr [ESI + 0x84]
    s.cx = m.r32((s.si+0x00000084u));
  }
  { // 0x424742: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  { // 0x424744: c1e210 SHL EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::left);
  }
  { // 0x424747: 89be180e0000 MOV dword ptr [ESI + 0xe18],EDI
    m.w32((s.si+0x00000e18u), s.di);
  }
  { // 0x42474d: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x42474f: 81c2000b0000 ADD EDX,0xb00
    s.dx = integer::add(s.dx,0x00000b00u,32,flags);
  }
  { // 0x424755: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x424757: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x424758: ff5028 CALL dword ptr [EAX + 0x28]
    const std::uint32_t call_target=m.r32((s.ax+0x00000028u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x42475b: 8d047f LEA EAX,[EDI + EDI*0x2]
    s.ax = (s.di+(s.di * 0x00000002u));
  }
  { // 0x42475e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x424760: 8d947f08040000 LEA EDX,[EDI + EDI*0x2 + 0x408]
    s.dx = (s.di+(s.di * 0x00000002u)+0x00000408u);
  }
  { // 0x424767: 668b8c460e080000 MOV CX,word ptr [ESI + EAX*0x2 + 0x80e]
    s.cx = with_ax(s.cx, m.r16((s.si+(s.ax * 0x00000002u)+0x0000080eu)));
  }
  { // 0x42476f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x424771: 668b0456 MOV AX,word ptr [ESI + EDX*0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+(s.dx * 0x00000002u))));
  }
  { // 0x424775: 8d7c4808 LEA EDI,[EAX + ECX*0x2 + 0x8]
    s.di = (s.ax+(s.cx * 0x00000002u)+0x00000008u);
  }
  { // 0x424779: 8b8e84000000 MOV ECX,dword ptr [ESI + 0x84]
    s.cx = m.r32((s.si+0x00000084u));
  }
  { // 0x42477f: 8b86100e0000 MOV EAX,dword ptr [ESI + 0xe10]
    s.ax = m.r32((s.si+0x00000e10u));
  }
  { // 0x424785: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x424786: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x424788: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x424789: ff5224 CALL dword ptr [EDX + 0x24]
    const std::uint32_t call_target=m.r32((s.dx+0x00000024u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x42478c: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x42478e: 7507 JNZ 0x00424797
    if(integer::condition("JNZ",flags)) goto L00424797;
  }
  L00424790: { // 0x424790: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x424791: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x424793: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x424794: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00424797: { // 0x424797: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x424798: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x42479a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42479b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00024bc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x424bc0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x424bc1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x424bc2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x424bc4: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x424bc6: 8a8689000000 MOV AL,byte ptr [ESI + 0x89]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000089u)));
  }
  { // 0x424bcc: c70694727800 MOV dword ptr [ESI],0x787294
    m.w32((s.si), 0x00787294u);
  }
  { // 0x424bd2: 3ac3 CMP AL,BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  { // 0x424bd4: 7411 JZ 0x00424be7
    if(integer::condition("JZ",flags)) goto L00424be7;
  }
  { // 0x424bd6: 8b8e84000000 MOV ECX,dword ptr [ESI + 0x84]
    s.cx = m.r32((s.si+0x00000084u));
  }
  { // 0x424bdc: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x424bde: ff5034 CALL dword ptr [EAX + 0x34]
    const std::uint32_t call_target=m.r32((s.ax+0x00000034u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x424be1: 889e89000000 MOV byte ptr [ESI + 0x89],BL
    m.w8((s.si+0x00000089u), (s.bx & 0xffu));
  }
  L00424be7: { // 0x424be7: 8b8e0c0e0000 MOV ECX,dword ptr [ESI + 0xe0c]
    s.cx = m.r32((s.si+0x00000e0cu));
  }
  { // 0x424bed: 899e84000000 MOV dword ptr [ESI + 0x84],EBX
    m.w32((s.si+0x00000084u), s.bx);
  }
  { // 0x424bf3: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  { // 0x424bf5: 740c JZ 0x00424c03
    if(integer::condition("JZ",flags)) goto L00424c03;
  }
  { // 0x424bf7: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x424bf9: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x424bfb: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x424bfd: 899e0c0e0000 MOV dword ptr [ESI + 0xe0c],EBX
    m.w32((s.si+0x00000e0cu), s.bx);
  }
  L00424c03: { // 0x424c03: 8b86100e0000 MOV EAX,dword ptr [ESI + 0xe10]
    s.ax = m.r32((s.si+0x00000e10u));
  }
  { // 0x424c09: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x424c0b: 740f JZ 0x00424c1c
    if(integer::condition("JZ",flags)) goto L00424c1c;
  }
  { // 0x424c0d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x424c0e: e8688a3400 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x424c13: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x424c16: 899e100e0000 MOV dword ptr [ESI + 0xe10],EBX
    m.w32((s.si+0x00000e10u), s.bx);
  }
  L00424c1c: { // 0x424c1c: 8a44240c MOV AL,byte ptr [ESP + 0xc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000cu)));
  }
  { // 0x424c20: 889e88000000 MOV byte ptr [ESI + 0x88],BL
    m.w8((s.si+0x00000088u), (s.bx & 0xffu));
  }
  { // 0x424c26: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x424c28: c706b8727800 MOV dword ptr [ESI],0x7872b8
    m.w32((s.si), 0x007872b8u);
  }
  { // 0x424c2e: 7409 JZ 0x00424c39
    if(integer::condition("JZ",flags)) goto L00424c39;
  }
  { // 0x424c30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x424c31: e8458a3400 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x424c36: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00424c39: { // 0x424c39: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x424c3b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x424c3c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x424c3d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0002f620(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42f620: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x42f621: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x42f623: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x42f627: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x42f629: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x42f62a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x42f62c: ff5008 CALL dword ptr [EAX + 0x8]
    const std::uint32_t call_target=m.r32((s.ax+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x42f62f: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x42f633: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x42f635: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x42f636: e805000000 CALL 0x0042f640
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x42f63b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42f63c: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0002fca0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42fca0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x42fca1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x42fca3: 8a4625 MOV AL,byte ptr [ESI + 0x25]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000025u)));
  }
  { // 0x42fca6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x42fca8: 743d JZ 0x0042fce7
    if(integer::condition("JZ",flags)) goto L0042fce7;
  }
  { // 0x42fcaa: e8f1f7ffff CALL 0x0042f4a0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x42fcaf: 8a4622 MOV AL,byte ptr [ESI + 0x22]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000022u)));
  }
  { // 0x42fcb2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x42fcb4: 742b JZ 0x0042fce1
    if(integer::condition("JZ",flags)) goto L0042fce1;
  }
  { // 0x42fcb6: 8b464c MOV EAX,dword ptr [ESI + 0x4c]
    s.ax = m.r32((s.si+0x0000004cu));
  }
  { // 0x42fcb9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x42fcbb: 7419 JZ 0x0042fcd6
    if(integer::condition("JZ",flags)) goto L0042fcd6;
  }
  { // 0x42fcbd: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x42fcbf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x42fcc1: c6462500 MOV byte ptr [ESI + 0x25],0x0
    m.w8((s.si+0x00000025u), 0x00000000u);
  }
  { // 0x42fcc5: ff5034 CALL dword ptr [EAX + 0x34]
    const std::uint32_t call_target=m.r32((s.ax+0x00000034u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x42fcc8: c6462501 MOV byte ptr [ESI + 0x25],0x1
    m.w8((s.si+0x00000025u), 0x00000001u);
  }
  { // 0x42fccc: c6462200 MOV byte ptr [ESI + 0x22],0x0
    m.w8((s.si+0x00000022u), 0x00000000u);
  }
  { // 0x42fcd0: c6462100 MOV byte ptr [ESI + 0x21],0x0
    m.w8((s.si+0x00000021u), 0x00000000u);
  }
  { // 0x42fcd4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42fcd5: c3 RET
    finish(m,s,f,0u); return;
  }
  L0042fcd6: { // 0x42fcd6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x42fcd8: e813062000 CALL 0x006302f0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x42fcdd: c6462200 MOV byte ptr [ESI + 0x22],0x0
    m.w8((s.si+0x00000022u), 0x00000000u);
  }
  L0042fce1: { // 0x42fce1: c6462100 MOV byte ptr [ESI + 0x21],0x0
    m.w8((s.si+0x00000021u), 0x00000000u);
  }
  { // 0x42fce5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42fce6: c3 RET
    finish(m,s,f,0u); return;
  }
  L0042fce7: { // 0x42fce7: e804062000 CALL 0x006302f0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x42fcec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42fced: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0002fde0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42fde0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x42fde1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x42fde3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x42fde4: 8b7e20 MOV EDI,dword ptr [ESI + 0x20]
    s.di = m.r32((s.si+0x00000020u));
  }
  { // 0x42fde7: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x42fde9: 7417 JZ 0x0042fe02
    if(integer::condition("JZ",flags)) goto L0042fe02;
  }
  { // 0x42fdeb: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x42fded: e84e0b2600 CALL 0x00690940
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x42fdf2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x42fdf3: e883d83300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x42fdf8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x42fdfb: c7462000000000 MOV dword ptr [ESI + 0x20],0x0
    m.w32((s.si+0x00000020u), 0x00000000u);
  }
  L0042fe02: { // 0x42fe02: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x42fe05: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x42fe07: 740e JZ 0x0042fe17
    if(integer::condition("JZ",flags)) goto L0042fe17;
  }
  { // 0x42fe09: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x42fe0a: ff1598557800 CALL dword ptr [0x00785598]
    const std::uint32_t call_target=m.r32((0x00785598u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x42fe10: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L0042fe17: { // 0x42fe17: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x42fe1a: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x42fe1d: 740e JZ 0x0042fe2d
    if(integer::condition("JZ",flags)) goto L0042fe2d;
  }
  { // 0x42fe1f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x42fe20: ff15d4517800 CALL dword ptr [0x007851d4]
    const std::uint32_t call_target=m.r32((0x007851d4u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x42fe26: c74628ffffffff MOV dword ptr [ESI + 0x28],0xffffffff
    m.w32((s.si+0x00000028u), 0xffffffffu);
  }
  L0042fe2d: { // 0x42fe2d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x42fe2e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42fe2f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00030130(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x430130: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x430131: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x430133: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x430134: 8b7e20 MOV EDI,dword ptr [ESI + 0x20]
    s.di = m.r32((s.si+0x00000020u));
  }
  { // 0x430137: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x430139: 7417 JZ 0x00430152
    if(integer::condition("JZ",flags)) goto L00430152;
  }
  { // 0x43013b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x43013d: e8fe072600 CALL 0x00690940
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x430142: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x430143: e833d53300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x430148: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x43014b: c7462000000000 MOV dword ptr [ESI + 0x20],0x0
    m.w32((s.si+0x00000020u), 0x00000000u);
  }
  L00430152: { // 0x430152: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x430155: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x430157: 740e JZ 0x00430167
    if(integer::condition("JZ",flags)) goto L00430167;
  }
  { // 0x430159: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x43015a: ff1598557800 CALL dword ptr [0x00785598]
    const std::uint32_t call_target=m.r32((0x00785598u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x430160: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L00430167: { // 0x430167: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x43016a: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x43016d: 740e JZ 0x0043017d
    if(integer::condition("JZ",flags)) goto L0043017d;
  }
  { // 0x43016f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x430170: ff15d4517800 CALL dword ptr [0x007851d4]
    const std::uint32_t call_target=m.r32((0x007851d4u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x430176: c74628ffffffff MOV dword ptr [ESI + 0x28],0xffffffff
    m.w32((s.si+0x00000028u), 0xffffffffu);
  }
  L0043017d: { // 0x43017d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x43017e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x43017f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00030870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x430870: 8a442410 MOV AL,byte ptr [ESP + 0x10]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000010u)));
  }
  { // 0x430874: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x430875: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x430876: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x43087a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x43087b: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x43087d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x43087f: 7406 JZ 0x00430887
    if(integer::condition("JZ",flags)) goto L00430887;
  }
  { // 0x430881: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x430882: e829010000 CALL 0x004309b0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00430887: { // 0x430887: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x430889: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x43088b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x43088d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x43088e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x43088f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x430891: ff525c CALL dword ptr [EDX + 0x5c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000005cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x430894: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x430896: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x430898: 7445 JZ 0x004308df
    if(integer::condition("JZ",flags)) goto L004308df;
  }
  { // 0x43089a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x43089c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x43089d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x43089f: ff5074 CALL dword ptr [EAX + 0x74]
    const std::uint32_t call_target=m.r32((s.ax+0x00000074u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4308a2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4308a4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4308a6: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  { // 0x4308a8: ff9280000000 CALL dword ptr [EDX + 0x80]
    const std::uint32_t call_target=m.r32((s.dx+0x00000080u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4308ae: 8a542420 MOV DL,byte ptr [ESP + 0x20]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000020u)));
  }
  { // 0x4308b2: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  { // 0x4308b5: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x4308b7: 7406 JZ 0x004308bf
    if(integer::condition("JZ",flags)) goto L004308bf;
  }
  { // 0x4308b9: 81c900000080 OR ECX,0x80000000
    s.cx = integer::logical((s.cx)|(0x80000000u),32,flags);
  }
  L004308bf: { // 0x4308bf: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  { // 0x4308c3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4308c4: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  { // 0x4308c8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4308c9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4308ca: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4308cb: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x4308ce: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x4308cf: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4308d0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4308d1: ff15ac557800 CALL dword ptr [0x007855ac]
    const std::uint32_t call_target=m.r32((0x007855acu));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x4308d7: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4308d9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4308db: ff5260 CALL dword ptr [EDX + 0x60]
    const std::uint32_t call_target=m.r32((s.dx+0x00000060u));
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x4308de: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004308df: { // 0x4308df: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4308e0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4308e2: e809000000 CALL 0x004308f0
    const std::uint32_t call_target=f.boundaries[6u].target;
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  { // 0x4308e7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4308e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4308e9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4308ea: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_00032be0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x432be0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x432be1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x432be2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x432be4: c70790777800 MOV dword ptr [EDI],0x787790
    m.w32((s.di), 0x00787790u);
  }
  { // 0x432bea: 8b35306d8300 MOV ESI,dword ptr [0x00836d30]
    s.si = m.r32((0x00836d30u));
  }
  { // 0x432bf0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x432bf2: 7408 JZ 0x00432bfc
    if(integer::condition("JZ",flags)) goto L00432bfc;
  }
  { // 0x432bf4: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x432bf6: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x432bf8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x432bfa: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00432bfc: { // 0x432bfc: 3b35306d8300 CMP ESI,dword ptr [0x00836d30]
    (void)integer::sub(s.si,m.r32((0x00836d30u)),32,flags);
  }
  { // 0x432c02: 750a JNZ 0x00432c0e
    if(integer::condition("JNZ",flags)) goto L00432c0e;
  }
  { // 0x432c04: c705306d830000000000 MOV dword ptr [0x00836d30],0x0
    m.w32((0x00836d30u), 0x00000000u);
  }
  L00432c0e: { // 0x432c0e: f644240c01 TEST byte ptr [ESP + 0xc],0x1
    (void)integer::logical((m.r8((f.sp+0x0000000cu)))&(0x00000001u),8,flags);
  }
  { // 0x432c13: 7409 JZ 0x00432c1e
    if(integer::condition("JZ",flags)) goto L00432c1e;
  }
  { // 0x432c15: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x432c16: e860aa3300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x432c1b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00432c1e: { // 0x432c1e: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x432c20: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x432c21: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x432c22: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000349a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4349a0: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x4349a4: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x4349a7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4349a8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4349a9: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4349ab: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x4349ad: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  { // 0x4349b1: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  { // 0x4349b5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4349b6: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  { // 0x4349ba: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4349bb: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  { // 0x4349bf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4349c0: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  { // 0x4349c4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4349c5: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  { // 0x4349c9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4349ca: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x4349cc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4349cd: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  { // 0x4349d1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4349d2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4349d3: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4349d5: ff5078 CALL dword ptr [EAX + 0x78]
    const std::uint32_t call_target=m.r32((s.ax+0x00000078u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4349d8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4349da: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4349dc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4349dd: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4349de: 8d44243c LEA EAX,[ESP + 0x3c]
    s.ax = (f.sp+0x0000003cu);
  }
  { // 0x4349e2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4349e3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4349e4: ff5278 CALL dword ptr [EDX + 0x78]
    const std::uint32_t call_target=m.r32((s.dx+0x00000078u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4349e7: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x4349e9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4349eb: e810000000 CALL 0x00434a00
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4349f0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4349f1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4349f2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4349f3: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x4349f6: c21c00 RET 0x1c
    finish(m,s,f,28u); return;
  }
}
void f_00035440(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x435440: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x435441: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x435442: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x435446: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x435447: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x435448: 68a0957b00 PUSH 0x7b95a0
    f.push(m,0x007b95a0u);
  }
  { // 0x43544d: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x43544f: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  { // 0x435451: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x435453: 6870ca7800 PUSH 0x78ca70
    f.push(m,0x0078ca70u);
  }
  { // 0x435458: c70700000000 MOV dword ptr [EDI],0x0
    m.w32((s.di), 0x00000000u);
  }
  { // 0x43545e: ff15f0557800 CALL dword ptr [0x007855f0]
    const std::uint32_t call_target=m.r32((0x007855f0u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x435464: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x435466: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x435468: 7c30 JL 0x0043549a
    if(integer::condition("JL",flags)) goto L0043549a;
  }
  { // 0x43546a: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x43546e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x43546f: ff15f4557800 CALL dword ptr [0x007855f4]
    const std::uint32_t call_target=m.r32((0x007855f4u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x435475: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x435477: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x435479: 7c11 JL 0x0043548c
    if(integer::condition("JL",flags)) goto L0043548c;
  }
  { // 0x43547b: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x43547f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x435480: 6840a57b00 PUSH 0x7ba540
    f.push(m,0x007ba540u);
  }
  { // 0x435485: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x435486: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x435488: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x43548a: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0043548c: { // 0x43548c: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x435490: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x435491: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x435493: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x435496: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x435498: 7d0e JGE 0x004354a8
    if(integer::condition("JGE",flags)) goto L004354a8;
  }
  L0043549a: { // 0x43549a: 81fe02400080 CMP ESI,0x80004002
    (void)integer::sub(s.si,0x80004002u,32,flags);
  }
  { // 0x4354a0: 7406 JZ 0x004354a8
    if(integer::condition("JZ",flags)) goto L004354a8;
  }
  { // 0x4354a2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4354a3: e8c8bd3400 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L004354a8: { // 0x4354a8: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x4354aa: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4354ab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4354ac: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x4354ad: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000354c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4354c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4354c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4354c3: 833e00 CMP dword ptr [ESI],0x0
    (void)integer::sub(m.r32((s.si)),0x00000000u,32,flags);
  }
  { // 0x4354c6: 750a JNZ 0x004354d2
    if(integer::condition("JNZ",flags)) goto L004354d2;
  }
  { // 0x4354c8: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x4354cd: e89ebd3400 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004354d2: { // 0x4354d2: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x4354d6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4354d8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4354d9: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x4354dd: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4354df: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4354e0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4354e1: ff510c CALL dword ptr [ECX + 0xc]
    const std::uint32_t call_target=m.r32((s.cx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4354e4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4354e5: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000354f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4354f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4354f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4354f3: 833e00 CMP dword ptr [ESI],0x0
    (void)integer::sub(m.r32((s.si)),0x00000000u,32,flags);
  }
  { // 0x4354f6: 750a JNZ 0x00435502
    if(integer::condition("JNZ",flags)) goto L00435502;
  }
  { // 0x4354f8: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x4354fd: e86ebd3400 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00435502: { // 0x435502: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x435506: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x435508: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x43550c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x43550d: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x435511: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x435513: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x435514: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x435515: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x435516: ff5118 CALL dword ptr [ECX + 0x18]
    const std::uint32_t call_target=m.r32((s.cx+0x00000018u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x435519: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x43551b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x43551c: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00035520(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x435520: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x435521: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x435523: 833e00 CMP dword ptr [ESI],0x0
    (void)integer::sub(m.r32((s.si)),0x00000000u,32,flags);
  }
  { // 0x435526: 750a JNZ 0x00435532
    if(integer::condition("JNZ",flags)) goto L00435532;
  }
  { // 0x435528: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x43552d: e83ebd3400 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00435532: { // 0x435532: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x435536: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x435538: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x43553c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x43553d: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x435541: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x435543: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x435544: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x435545: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x435546: ff511c CALL dword ptr [ECX + 0x1c]
    const std::uint32_t call_target=m.r32((s.cx+0x0000001cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x435549: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x43554b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x43554c: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00036550(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x436550: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x436551: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x436553: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x436554: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x436556: 8b7e08 MOV EDI,dword ptr [ESI + 0x8]
    s.di = m.r32((s.si+0x00000008u));
  }
  { // 0x436559: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x43655c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x43655e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x436560: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x436561: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x436563: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x436566: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  { // 0x436569: 8b7e20 MOV EDI,dword ptr [ESI + 0x20]
    s.di = m.r32((s.si+0x00000020u));
  }
  { // 0x43656c: 83c618 ADD ESI,0x18
    s.si = integer::add(s.si,0x00000018u,32,flags);
  }
  { // 0x43656f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x436571: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x436574: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x436576: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x436578: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x436579: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x43657b: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x43657e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x43657f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x436580: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0003b620(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x43b620: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x43b621: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x43b623: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x43b625: ff90b8010000 CALL dword ptr [EAX + 0x1b8]
    const std::uint32_t call_target=m.r32((s.ax+0x000001b8u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x43b62b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x43b62d: e87ec92500 CALL 0x00697fb0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x43b632: 8bb618040000 MOV ESI,dword ptr [ESI + 0x418]
    s.si = m.r32((s.si+0x00000418u));
  }
  { // 0x43b638: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x43b63a: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  { // 0x43b63c: 8a865f130000 MOV AL,byte ptr [ESI + 0x135f]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000135fu)));
  }
  { // 0x43b642: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x43b644: 740a JZ 0x0043b650
    if(integer::condition("JZ",flags)) goto L0043b650;
  }
  { // 0x43b646: 8b86700f0000 MOV EAX,dword ptr [ESI + 0xf70]
    s.ax = m.r32((s.si+0x00000f70u));
  }
  { // 0x43b64c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x43b64d: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x43b64f: c3 RET
    finish(m,s,f,0u); return;
  }
  L0043b650: { // 0x43b650: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x43b652: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x43b653: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000423d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4423d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4423d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4423d3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4423d4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4423d6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4423d8: ff909c030000 CALL dword ptr [EAX + 0x39c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000039cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4423de: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  { // 0x4423e1: 741b JZ 0x004423fe
    if(integer::condition("JZ",flags)) goto L004423fe;
  }
  { // 0x4423e3: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4423e5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4423e7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4423e9: ff929c030000 CALL dword ptr [EDX + 0x39c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000039cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4423ef: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4423f1: e82a622e00 CALL 0x00728620
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4423f6: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4423fa: 0bf8 OR EDI,EAX
    s.di = integer::logical((s.di)|(s.ax),32,flags);
  }
  { // 0x4423fc: eb04 JMP 0x00442402
    goto L00442402;
  }
  L004423fe: { // 0x4423fe: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00442402: { // 0x442402: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x442404: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x442406: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x442408: ff909c030000 CALL dword ptr [EAX + 0x39c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000039cu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x44240e: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  { // 0x442411: 7415 JZ 0x00442428
    if(integer::condition("JZ",flags)) goto L00442428;
  }
  { // 0x442413: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x442415: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x442417: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x442419: ff929c030000 CALL dword ptr [EDX + 0x39c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000039cu));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x44241f: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x442421: e8fa612e00 CALL 0x00728620
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x442426: 0bf8 OR EDI,EAX
    s.di = integer::logical((s.di)|(s.ax),32,flags);
  }
  L00442428: { // 0x442428: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x44242c: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x442430: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x442431: 83cf01 OR EDI,0x1
    s.di = integer::logical((s.di)|(0x00000001u),32,flags);
  }
  { // 0x442434: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x442435: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x442436: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x442438: e823972700 CALL 0x006bbb60
    const std::uint32_t call_target=f.boundaries[6u].target;
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  { // 0x44243d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x44243e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44243f: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00045190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x445190: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x445191: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x445193: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  { // 0x445199: 8a881c120000 MOV CL,byte ptr [EAX + 0x121c]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000121cu)));
  }
  { // 0x44519f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x4451a1: 755a JNZ 0x004451fd
    if(integer::condition("JNZ",flags)) goto L004451fd;
  }
  { // 0x4451a3: 8a86b9050000 MOV AL,byte ptr [ESI + 0x5b9]
    s.ax = with_al(s.ax, m.r8((s.si+0x000005b9u)));
  }
  { // 0x4451a9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4451ab: 742c JZ 0x004451d9
    if(integer::condition("JZ",flags)) goto L004451d9;
  }
  { // 0x4451ad: 8b862c040000 MOV EAX,dword ptr [ESI + 0x42c]
    s.ax = m.r32((s.si+0x0000042cu));
  }
  { // 0x4451b3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4451b5: 7422 JZ 0x004451d9
    if(integer::condition("JZ",flags)) goto L004451d9;
  }
  { // 0x4451b7: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4451b9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4451bb: ff926c010000 CALL dword ptr [EDX + 0x16c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000016cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4451c1: 83f813 CMP EAX,0x13
    (void)integer::sub(s.ax,0x00000013u,32,flags);
  }
  { // 0x4451c4: 7413 JZ 0x004451d9
    if(integer::condition("JZ",flags)) goto L004451d9;
  }
  { // 0x4451c6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4451c8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4451ca: ff906c010000 CALL dword ptr [EAX + 0x16c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000016cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4451d0: 83f812 CMP EAX,0x12
    (void)integer::sub(s.ax,0x00000012u,32,flags);
  }
  { // 0x4451d3: 7404 JZ 0x004451d9
    if(integer::condition("JZ",flags)) goto L004451d9;
  }
  { // 0x4451d5: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4451d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4451d8: c3 RET
    finish(m,s,f,0u); return;
  }
  L004451d9: { // 0x4451d9: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  { // 0x4451df: 8a815a130000 MOV AL,byte ptr [ECX + 0x135a]
    s.ax = with_al(s.ax, m.r8((s.cx+0x0000135au)));
  }
  { // 0x4451e5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4451e7: 7414 JZ 0x004451fd
    if(integer::condition("JZ",flags)) goto L004451fd;
  }
  { // 0x4451e9: 8b96b4010000 MOV EDX,dword ptr [ESI + 0x1b4]
    s.dx = m.r32((s.si+0x000001b4u));
  }
  { // 0x4451ef: 8a8242010000 MOV AL,byte ptr [EDX + 0x142]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000142u)));
  }
  { // 0x4451f5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4451f7: 7504 JNZ 0x004451fd
    if(integer::condition("JNZ",flags)) goto L004451fd;
  }
  { // 0x4451f9: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4451fb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4451fc: c3 RET
    finish(m,s,f,0u); return;
  }
  L004451fd: { // 0x4451fd: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4451ff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x445200: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0004d570(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x44d570: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x44d571: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x44d573: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  { // 0x44d579: 8a8851130000 MOV CL,byte ptr [EAX + 0x1351]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001351u)));
  }
  { // 0x44d57f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x44d581: 7504 JNZ 0x0044d587
    if(integer::condition("JNZ",flags)) goto L0044d587;
  }
  { // 0x44d583: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x44d585: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44d586: c3 RET
    finish(m,s,f,0u); return;
  }
  L0044d587: { // 0x44d587: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x44d589: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x44d58b: ff926c010000 CALL dword ptr [EDX + 0x16c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000016cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x44d591: 83f818 CMP EAX,0x18
    (void)integer::sub(s.ax,0x00000018u,32,flags);
  }
  { // 0x44d594: 7513 JNZ 0x0044d5a9
    if(integer::condition("JNZ",flags)) goto L0044d5a9;
  }
  { // 0x44d596: 8d8ea8020000 LEA ECX,[ESI + 0x2a8]
    s.cx = (s.si+0x000002a8u);
  }
  { // 0x44d59c: e86f930400 CALL 0x00496910
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x44d5a1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44d5a3: 7404 JZ 0x0044d5a9
    if(integer::condition("JZ",flags)) goto L0044d5a9;
  }
  { // 0x44d5a5: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x44d5a7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44d5a8: c3 RET
    finish(m,s,f,0u); return;
  }
  L0044d5a9: { // 0x44d5a9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x44d5ab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44d5ac: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0004d5b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x44d5b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x44d5b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x44d5b3: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  { // 0x44d5b6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x44d5b8: 7504 JNZ 0x0044d5be
    if(integer::condition("JNZ",flags)) goto L0044d5be;
  }
  { // 0x44d5ba: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x44d5bc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44d5bd: c3 RET
    finish(m,s,f,0u); return;
  }
  L0044d5be: { // 0x44d5be: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  { // 0x44d5c4: 8a881d120000 MOV CL,byte ptr [EAX + 0x121d]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000121du)));
  }
  { // 0x44d5ca: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x44d5cc: 7504 JNZ 0x0044d5d2
    if(integer::condition("JNZ",flags)) goto L0044d5d2;
  }
  { // 0x44d5ce: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x44d5d0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44d5d1: c3 RET
    finish(m,s,f,0u); return;
  }
  L0044d5d2: { // 0x44d5d2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x44d5d4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x44d5d6: ff527c CALL dword ptr [EDX + 0x7c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000007cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x44d5d9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44d5db: 7404 JZ 0x0044d5e1
    if(integer::condition("JZ",flags)) goto L0044d5e1;
  }
  { // 0x44d5dd: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x44d5df: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44d5e0: c3 RET
    finish(m,s,f,0u); return;
  }
  L0044d5e1: { // 0x44d5e1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x44d5e3: e818562700 CALL 0x006c2c00
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x44d5e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44d5e9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0004d710(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x44d710: 8b813c050000 MOV EAX,dword ptr [ECX + 0x53c]
    s.ax = m.r32((s.cx+0x0000053cu));
  }
  { // 0x44d716: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x44d717: 8db13c050000 LEA ESI,[ECX + 0x53c]
    s.si = (s.cx+0x0000053cu);
  }
  { // 0x44d71d: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x44d721: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x44d722: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x44d724: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x44d727: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x44d72a: 7421 JZ 0x0044d74d
    if(integer::condition("JZ",flags)) goto L0044d74d;
  }
  { // 0x44d72c: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x44d72f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x44d731: 7d1a JGE 0x0044d74d
    if(integer::condition("JGE",flags)) goto L0044d74d;
  }
  { // 0x44d733: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x44d734: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x44d736: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x44d739: 7d12 JGE 0x0044d74d
    if(integer::condition("JGE",flags)) goto L0044d74d;
  }
  L0044d73b: { // 0x44d73b: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x44d73e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x44d73f: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x44d742: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  { // 0x44d746: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x44d749: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x44d74b: 7cee JL 0x0044d73b
    if(integer::condition("JL",flags)) goto L0044d73b;
  }
  L0044d74d: { // 0x44d74d: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x44d750: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x44d753: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x44d755: 7c22 JL 0x0044d779
    if(integer::condition("JL",flags)) goto L0044d779;
  }
  { // 0x44d757: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x44d75a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44d75c: 7504 JNZ 0x0044d762
    if(integer::condition("JNZ",flags)) goto L0044d762;
  }
  { // 0x44d75e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x44d760: 752a JNZ 0x0044d78c
    if(integer::condition("JNZ",flags)) goto L0044d78c;
  }
  L0044d762: { // 0x44d762: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x44d765: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x44d767: 7e23 JLE 0x0044d78c
    if(integer::condition("JLE",flags)) goto L0044d78c;
  }
  { // 0x44d769: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x44d76b: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x44d76d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x44d76f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x44d770: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x44d772: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x44d775: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44d777: 7413 JZ 0x0044d78c
    if(integer::condition("JZ",flags)) goto L0044d78c;
  }
  L0044d779: { // 0x44d779: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x44d77c: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x44d77f: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  { // 0x44d782: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x44d785: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x44d789: 890c82 MOV dword ptr [EDX + EAX*0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.cx);
  }
  L0044d78c: { // 0x44d78c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44d78d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00050bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x450bf0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x450bf1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x450bf3: 83be9800000013 CMP dword ptr [ESI + 0x98],0x13
    (void)integer::sub(m.r32((s.si+0x00000098u)),0x00000013u,32,flags);
  }
  { // 0x450bfa: 7437 JZ 0x00450c33
    if(integer::condition("JZ",flags)) goto L00450c33;
  }
  { // 0x450bfc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x450bfe: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x450bff: ff9064020000 CALL dword ptr [EAX + 0x264]
    const std::uint32_t call_target=m.r32((s.ax+0x00000264u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x450c05: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x450c09: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x450c0b: 7510 JNZ 0x00450c1d
    if(integer::condition("JNZ",flags)) goto L00450c1d;
  }
  { // 0x450c0d: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  { // 0x450c13: 8a8153130000 MOV AL,byte ptr [ECX + 0x1353]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001353u)));
  }
  { // 0x450c19: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x450c1b: 7408 JZ 0x00450c25
    if(integer::condition("JZ",flags)) goto L00450c25;
  }
  L00450c1d: { // 0x450c1d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x450c1e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x450c20: e89bb72700 CALL 0x006cc3c0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00450c25: { // 0x450c25: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x450c29: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x450c2b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x450c2c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x450c2d: e81e922700 CALL 0x006c9e50
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x450c32: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00450c33: { // 0x450c33: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x450c34: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00051ec0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x451ec0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x451ec1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x451ec3: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x451ec7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x451ec8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x451eca: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x451ecb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x451ecd: ff90f8030000 CALL dword ptr [EAX + 0x3f8]
    const std::uint32_t call_target=m.r32((s.ax+0x000003f8u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x451ed3: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x451ed5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x451ed7: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x451ed9: ff922c030000 CALL dword ptr [EDX + 0x32c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000032cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x451edf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x451ee1: 740d JZ 0x00451ef0
    if(integer::condition("JZ",flags)) goto L00451ef0;
  }
  { // 0x451ee3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x451ee4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x451ee6: e875bd2700 CALL 0x006cdc60
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x451eeb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x451eec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x451eed: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00451ef0: { // 0x451ef0: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x451ef2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x451ef3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x451ef4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00053520(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x453520: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x453521: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x453523: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x453527: 8b96b4010000 MOV EDX,dword ptr [ESI + 0x1b4]
    s.dx = m.r32((s.si+0x000001b4u));
  }
  { // 0x45352d: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x45352f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x453530: ff908c000000 CALL dword ptr [EAX + 0x8c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000008cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x453536: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x453538: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x453539: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x45353b: ff92f8000000 CALL dword ptr [EDX + 0xf8]
    const std::uint32_t call_target=m.r32((s.dx+0x000000f8u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x453541: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x453543: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x453546: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x453547: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00053af0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x453af0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x453af4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x453af5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x453af7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x453af8: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x453afa: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x453afc: 7416 JZ 0x00453b14
    if(integer::condition("JZ",flags)) goto L00453b14;
  }
  { // 0x453afe: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x453b00: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x453b02: 7406 JZ 0x00453b0a
    if(integer::condition("JZ",flags)) goto L00453b0a;
  }
  { // 0x453b04: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x453b06: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x453b07: ff5104 CALL dword ptr [ECX + 0x4]
    const std::uint32_t call_target=m.r32((s.cx+0x00000004u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00453b0a: { // 0x453b0a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x453b0c: 7406 JZ 0x00453b14
    if(integer::condition("JZ",flags)) goto L00453b14;
  }
  { // 0x453b0e: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  { // 0x453b10: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x453b11: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00453b14: { // 0x453b14: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x453b16: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x453b17: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x453b18: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00054870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x454870: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x454874: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x454875: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x454876: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x454878: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x45487a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x45487c: 7449 JZ 0x004548c7
    if(integer::condition("JZ",flags)) goto L004548c7;
  }
  { // 0x45487e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x454880: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x454884: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x454885: 6898a17b00 PUSH 0x7ba198
    f.push(m,0x007ba198u);
  }
  { // 0x45488a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x45488b: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x45488d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x45488f: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x454891: 7d19 JGE 0x004548ac
    if(integer::condition("JGE",flags)) goto L004548ac;
  }
  { // 0x454893: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x454895: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x454897: 7406 JZ 0x0045489f
    if(integer::condition("JZ",flags)) goto L0045489f;
  }
  { // 0x454899: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x45489b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x45489c: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0045489f: { // 0x45489f: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x4548a1: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x4548a7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4548a8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4548a9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004548ac: { // 0x4548ac: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4548ae: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4548af: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  { // 0x4548b3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4548b5: 7406 JZ 0x004548bd
    if(integer::condition("JZ",flags)) goto L004548bd;
  }
  { // 0x4548b7: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x4548b9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4548ba: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L004548bd: { // 0x4548bd: 891e MOV dword ptr [ESI],EBX
    m.w32((s.si), s.bx);
  }
  { // 0x4548bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4548c0: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x4548c2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4548c3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4548c4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004548c7: { // 0x4548c7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4548c9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4548cb: 740c JZ 0x004548d9
    if(integer::condition("JZ",flags)) goto L004548d9;
  }
  { // 0x4548cd: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x4548d3: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4548d5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4548d6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L004548d9: { // 0x4548d9: bf02400080 MOV EDI,0x80004002
    s.di = 0x80004002u;
  }
  { // 0x4548de: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x4548e0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4548e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4548e2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000548f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4548f0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4548f4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4548f5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4548f6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4548f8: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x4548fa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4548fc: 7449 JZ 0x00454947
    if(integer::condition("JZ",flags)) goto L00454947;
  }
  { // 0x4548fe: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x454900: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x454904: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x454905: 68c8ab7b00 PUSH 0x7babc8
    f.push(m,0x007babc8u);
  }
  { // 0x45490a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x45490b: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x45490d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x45490f: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x454911: 7d19 JGE 0x0045492c
    if(integer::condition("JGE",flags)) goto L0045492c;
  }
  { // 0x454913: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x454915: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x454917: 7406 JZ 0x0045491f
    if(integer::condition("JZ",flags)) goto L0045491f;
  }
  { // 0x454919: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x45491b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x45491c: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0045491f: { // 0x45491f: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x454921: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x454927: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x454928: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x454929: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0045492c: { // 0x45492c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x45492e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x45492f: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  { // 0x454933: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x454935: 7406 JZ 0x0045493d
    if(integer::condition("JZ",flags)) goto L0045493d;
  }
  { // 0x454937: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x454939: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x45493a: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L0045493d: { // 0x45493d: 891e MOV dword ptr [ESI],EBX
    m.w32((s.si), s.bx);
  }
  { // 0x45493f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x454940: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x454942: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x454943: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x454944: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00454947: { // 0x454947: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x454949: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x45494b: 740c JZ 0x00454959
    if(integer::condition("JZ",flags)) goto L00454959;
  }
  { // 0x45494d: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x454953: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x454955: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x454956: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00454959: { // 0x454959: bf02400080 MOV EDI,0x80004002
    s.di = 0x80004002u;
  }
  { // 0x45495e: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x454960: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x454961: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x454962: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00058670(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x458670: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x458671: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x458672: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x458673: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x458674: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x458676: e8d57b2700 CALL 0x006d0250
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x45867b: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  { // 0x458681: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x458683: 8b810c0a0000 MOV EAX,dword ptr [ECX + 0xa0c]
    s.ax = m.r32((s.cx+0x00000a0cu));
  }
  { // 0x458689: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  { // 0x45868b: 8b97b0030000 MOV EDX,dword ptr [EDI + 0x3b0]
    s.dx = m.r32((s.di+0x000003b0u));
  }
  { // 0x458691: 3b1a CMP EBX,dword ptr [EDX]
    (void)integer::sub(s.bx,m.r32((s.dx)),32,flags);
  }
  { // 0x458693: 752e JNZ 0x004586c3
    if(integer::condition("JNZ",flags)) goto L004586c3;
  }
  { // 0x458695: 8a912c140000 MOV DL,byte ptr [ECX + 0x142c]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000142cu)));
  }
  { // 0x45869b: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x45869d: 7524 JNZ 0x004586c3
    if(integer::condition("JNZ",flags)) goto L004586c3;
  }
  { // 0x45869f: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  { // 0x4586a2: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x4586a4: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x4586a6: ff92ac000000 CALL dword ptr [EDX + 0xac]
    const std::uint32_t call_target=m.r32((s.dx+0x000000acu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4586ac: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  { // 0x4586ae: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x4586b0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4586b2: ff90ac000000 CALL dword ptr [EAX + 0xac]
    const std::uint32_t call_target=m.r32((s.ax+0x000000acu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4586b8: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  { // 0x4586ba: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x4586bb: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x4586bd: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x4586bf: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x4586c1: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L004586c3: { // 0x4586c3: 8b9b380c0000 MOV EBX,dword ptr [EBX + 0xc38]
    s.bx = m.r32((s.bx+0x00000c38u));
  }
  { // 0x4586c9: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x4586cb: 741b JZ 0x004586e8
    if(integer::condition("JZ",flags)) goto L004586e8;
  }
  { // 0x4586cd: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  { // 0x4586cf: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x4586d1: ff92ac000000 CALL dword ptr [EDX + 0xac]
    const std::uint32_t call_target=m.r32((s.dx+0x000000acu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4586d7: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x4586d9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4586db: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4586dd: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  { // 0x4586e0: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x4586e1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4586e2: 23c6 AND EAX,ESI
    s.ax = integer::logical((s.ax)&(s.si),32,flags);
  }
  { // 0x4586e4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4586e5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4586e6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4586e7: c3 RET
    finish(m,s,f,0u); return;
  }
  L004586e8: { // 0x4586e8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4586ea: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4586eb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4586ec: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4586ed: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4586ee: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00058a80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x458a80: 8a81e9130000 MOV AL,byte ptr [ECX + 0x13e9]
    s.ax = with_al(s.ax, m.r8((s.cx+0x000013e9u)));
  }
  { // 0x458a86: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x458a87: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x458a89: 7434 JZ 0x00458abf
    if(integer::condition("JZ",flags)) goto L00458abf;
  }
  { // 0x458a8b: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x458a8f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x458a91: 742c JZ 0x00458abf
    if(integer::condition("JZ",flags)) goto L00458abf;
  }
  { // 0x458a93: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x458a95: ff909c000000 CALL dword ptr [EAX + 0x9c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000009cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x458a9b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x458a9d: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x458a9f: 741e JZ 0x00458abf
    if(integer::condition("JZ",flags)) goto L00458abf;
  }
  { // 0x458aa1: 0fbf4006 MOVSX EAX,word ptr [EAX + 0x6]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  { // 0x458aa5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x458aa6: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x458aa8: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x458aaa: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x458aad: 7e10 JLE 0x00458abf
    if(integer::condition("JLE",flags)) goto L00458abf;
  }
  { // 0x458aaf: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x458ab3: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x458ab5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x458ab6: c70103000000 MOV dword ptr [ECX],0x3
    m.w32((s.cx), 0x00000003u);
  }
  { // 0x458abc: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00458abf: { // 0x458abf: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x458ac1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x458ac2: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00058ad0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x458ad0: 8a81e9130000 MOV AL,byte ptr [ECX + 0x13e9]
    s.ax = with_al(s.ax, m.r8((s.cx+0x000013e9u)));
  }
  { // 0x458ad6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x458ad7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x458ad9: 7433 JZ 0x00458b0e
    if(integer::condition("JZ",flags)) goto L00458b0e;
  }
  { // 0x458adb: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x458adf: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x458ae1: 742b JZ 0x00458b0e
    if(integer::condition("JZ",flags)) goto L00458b0e;
  }
  { // 0x458ae3: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x458ae5: ff909c000000 CALL dword ptr [EAX + 0x9c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000009cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x458aeb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x458aed: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x458aef: 741d JZ 0x00458b0e
    if(integer::condition("JZ",flags)) goto L00458b0e;
  }
  { // 0x458af1: 0fbf4006 MOVSX EAX,word ptr [EAX + 0x6]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  { // 0x458af5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x458af6: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x458af8: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x458afa: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x458afd: 7e0f JLE 0x00458b0e
    if(integer::condition("JLE",flags)) goto L00458b0e;
  }
  { // 0x458aff: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x458b03: 83c003 ADD EAX,0x3
    s.ax = integer::add(s.ax,0x00000003u,32,flags);
  }
  { // 0x458b06: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x458b07: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  { // 0x458b09: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x458b0b: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00458b0e: { // 0x458b0e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x458b10: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x458b11: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000635c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4635c0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4635c1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4635c2: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x4635c6: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4635c7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4635c8: 68f8aa7900 PUSH 0x79aaf8
    f.push(m,0x0079aaf8u);
  }
  { // 0x4635cd: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  { // 0x4635cf: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4635d1: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x4635d3: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x4635d5: 6850cc7800 PUSH 0x78cc50
    f.push(m,0x0078cc50u);
  }
  { // 0x4635da: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  { // 0x4635e2: ff15f0557800 CALL dword ptr [0x007855f0]
    const std::uint32_t call_target=m.r32((0x007855f0u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4635e8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4635ea: 7d08 JGE 0x004635f4
    if(integer::condition("JGE",flags)) goto L004635f4;
  }
  { // 0x4635ec: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4635ed: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4635ef: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4635f0: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x4635f1: c21400 RET 0x14
    finish(m,s,f,20u); return;
  }
  L004635f4: { // 0x4635f4: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  { // 0x4635f8: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x4635fc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4635fd: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x463601: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x463602: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  { // 0x463606: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x463607: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  { // 0x46360b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46360c: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  { // 0x463610: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x463611: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x463612: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x463613: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x463614: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x463616: e845bbffff CALL 0x0045f160
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x46361b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x46361d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46361e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46361f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x463620: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x463621: c21400 RET 0x14
    finish(m,s,f,20u); return;
  }
}
void f_00067bb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x467bb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x467bb1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x467bb5: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x467bb7: 7506 JNZ 0x00467bbf
    if(integer::condition("JNZ",flags)) goto L00467bbf;
  }
  { // 0x467bb9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x467bbb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x467bbc: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00467bbf: { // 0x467bbf: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x467bc1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x467bc2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x467bc3: 8b792c MOV EDI,dword ptr [ECX + 0x2c]
    s.di = m.r32((s.cx+0x0000002cu));
  }
  { // 0x467bc6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x467bc8: ff503c CALL dword ptr [EAX + 0x3c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000003cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x467bcb: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  { // 0x467bcd: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x467bcf: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x467bd1: ff523c CALL dword ptr [EDX + 0x3c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000003cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x467bd4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x467bd5: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x467bd7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x467bd8: 7506 JNZ 0x00467be0
    if(integer::condition("JNZ",flags)) goto L00467be0;
  }
  { // 0x467bda: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x467bdc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x467bdd: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00467be0: { // 0x467be0: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x467be2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x467be4: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x467bea: 8a88fd0a0000 MOV CL,byte ptr [EAX + 0xafd]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000afdu)));
  }
  { // 0x467bf0: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x467bf2: 7406 JZ 0x00467bfa
    if(integer::condition("JZ",flags)) goto L00467bfa;
  }
  { // 0x467bf4: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x467bf6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x467bf7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00467bfa: { // 0x467bfa: 8b8634020000 MOV EAX,dword ptr [ESI + 0x234]
    s.ax = m.r32((s.si+0x00000234u));
  }
  { // 0x467c00: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x467c02: 7406 JZ 0x00467c0a
    if(integer::condition("JZ",flags)) goto L00467c0a;
  }
  { // 0x467c04: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x467c06: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x467c07: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00467c0a: { // 0x467c0a: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x467c0c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x467c0e: ff922c030000 CALL dword ptr [EDX + 0x32c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000032cu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x467c14: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x467c16: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x467c19: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x467c1a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00068c50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x468c50: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x468c51: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x468c53: 8b4654 MOV EAX,dword ptr [ESI + 0x54]
    s.ax = m.r32((s.si+0x00000054u));
  }
  { // 0x468c56: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x468c58: 7411 JZ 0x00468c6b
    if(integer::condition("JZ",flags)) goto L00468c6b;
  }
  { // 0x468c5a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x468c5b: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x468c5d: ff5704 CALL dword ptr [EDI + 0x4]
    const std::uint32_t call_target=m.r32((s.di+0x00000004u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x468c60: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x468c61: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x468c63: 6a0d PUSH 0xd
    f.push(m,0x0000000du);
  }
  { // 0x468c65: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x468c67: ff5740 CALL dword ptr [EDI + 0x40]
    const std::uint32_t call_target=m.r32((s.di+0x00000040u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x468c6a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00468c6b: { // 0x468c6b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x468c6f: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x468c73: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x468c74: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x468c75: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x468c77: e8b46afcff CALL 0x0042f730
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x468c7c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x468c7d: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00068d70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x468d70: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x468d71: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x468d72: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x468d74: 8b4654 MOV EAX,dword ptr [ESI + 0x54]
    s.ax = m.r32((s.si+0x00000054u));
  }
  { // 0x468d77: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x468d79: 7406 JZ 0x00468d81
    if(integer::condition("JZ",flags)) goto L00468d81;
  }
  { // 0x468d7b: 8b4658 MOV EAX,dword ptr [ESI + 0x58]
    s.ax = m.r32((s.si+0x00000058u));
  }
  { // 0x468d7e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x468d7f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x468d80: c3 RET
    finish(m,s,f,0u); return;
  }
  L00468d81: { // 0x468d81: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x468d83: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x468d85: e85668fcff CALL 0x0042f5e0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x468d8a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x468d8c: 7528 JNZ 0x00468db6
    if(integer::condition("JNZ",flags)) goto L00468db6;
  }
  { // 0x468d8e: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x468d90: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x468d94: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x468d95: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x468d97: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x468d99: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x468d9b: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  { // 0x468da3: ff5204 CALL dword ptr [EDX + 0x4]
    const std::uint32_t call_target=m.r32((s.dx+0x00000004u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x468da6: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x468da8: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x468daa: e8f19a1200 CALL 0x005928a0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x468daf: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x468db3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x468db4: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x468db5: c3 RET
    finish(m,s,f,0u); return;
  }
  L00468db6: { // 0x468db6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x468db8: e8c36efcff CALL 0x0042fc80
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x468dbd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x468dbe: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x468dbf: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00068dc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x468dc0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x468dc1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x468dc3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x468dc5: ff5018 CALL dword ptr [EAX + 0x18]
    const std::uint32_t call_target=m.r32((s.ax+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x468dc8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x468dca: 7406 JZ 0x00468dd2
    if(integer::condition("JZ",flags)) goto L00468dd2;
  }
  { // 0x468dcc: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x468dce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x468dcf: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00468dd2: { // 0x468dd2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x468dd4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x468dd6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x468dd8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x468dda: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x468ddc: ff5204 CALL dword ptr [EDX + 0x4]
    const std::uint32_t call_target=m.r32((s.dx+0x00000004u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x468ddf: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x468de1: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x468de3: e8b89a1200 CALL 0x005928a0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x468de8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x468dea: 7406 JZ 0x00468df2
    if(integer::condition("JZ",flags)) goto L00468df2;
  }
  { // 0x468dec: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x468dee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x468def: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00468df2: { // 0x468df2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x468df4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x468df6: e8e567fcff CALL 0x0042f5e0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x468dfb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x468dfc: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0006cba0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46cba0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x46cba1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46cba2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x46cba3: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x46cba7: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46cba9: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x46cbab: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x46cbad: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  { // 0x46cbb0: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  { // 0x46cbb3: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  { // 0x46cbb7: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  { // 0x46cbba: c706d4897800 MOV dword ptr [ESI],0x7889d4
    m.w32((s.si), 0x007889d4u);
  }
  { // 0x46cbc0: 7452 JZ 0x0046cc14
    if(integer::condition("JZ",flags)) goto L0046cc14;
  }
  { // 0x46cbc2: ff15e0897800 CALL dword ptr [0x007889e0]
    const std::uint32_t call_target=m.r32((0x007889e0u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x46cbc8: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x46cbcb: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x46cbcd: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x46cbd0: 743c JZ 0x0046cc0e
    if(integer::condition("JZ",flags)) goto L0046cc0e;
  }
  { // 0x46cbd2: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  { // 0x46cbd5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46cbd6: e87c0d3000 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x46cbdb: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x46cbde: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x46cbe0: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x46cbe3: 742f JZ 0x0046cc14
    if(integer::condition("JZ",flags)) goto L0046cc14;
  }
  { // 0x46cbe5: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x46cbe8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x46cbea: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  { // 0x46cbec: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x46cbf0: 7e22 JLE 0x0046cc14
    if(integer::condition("JLE",flags)) goto L0046cc14;
  }
  L0046cbf2: { // 0x46cbf2: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  { // 0x46cbf5: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x46cbf8: 8b0c81 MOV ECX,dword ptr [ECX + EAX*0x4]
    s.cx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x46cbfb: 890c82 MOV dword ptr [EDX + EAX*0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.cx);
  }
  { // 0x46cbfe: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x46cc01: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x46cc02: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x46cc04: 7cec JL 0x0046cbf2
    if(integer::condition("JL",flags)) goto L0046cbf2;
  }
  { // 0x46cc06: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x46cc08: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46cc09: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46cc0a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x46cc0b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0046cc0e: { // 0x46cc0e: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  { // 0x46cc11: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  L0046cc14: { // 0x46cc14: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x46cc16: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46cc17: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46cc18: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x46cc19: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0006cf80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46cf80: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x46cf81: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46cf82: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x46cf83: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x46cf87: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46cf89: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x46cf8b: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x46cf8d: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  { // 0x46cf90: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  { // 0x46cf93: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  { // 0x46cf97: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  { // 0x46cf9a: c706148a7800 MOV dword ptr [ESI],0x788a14
    m.w32((s.si), 0x00788a14u);
  }
  { // 0x46cfa0: 7452 JZ 0x0046cff4
    if(integer::condition("JZ",flags)) goto L0046cff4;
  }
  { // 0x46cfa2: ff15208a7800 CALL dword ptr [0x00788a20]
    const std::uint32_t call_target=m.r32((0x00788a20u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x46cfa8: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x46cfab: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x46cfad: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x46cfb0: 743c JZ 0x0046cfee
    if(integer::condition("JZ",flags)) goto L0046cfee;
  }
  { // 0x46cfb2: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  { // 0x46cfb5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46cfb6: e89c093000 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x46cfbb: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x46cfbe: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x46cfc0: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x46cfc3: 742f JZ 0x0046cff4
    if(integer::condition("JZ",flags)) goto L0046cff4;
  }
  { // 0x46cfc5: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x46cfc8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x46cfca: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  { // 0x46cfcc: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x46cfd0: 7e22 JLE 0x0046cff4
    if(integer::condition("JLE",flags)) goto L0046cff4;
  }
  L0046cfd2: { // 0x46cfd2: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  { // 0x46cfd5: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x46cfd8: 8b0c81 MOV ECX,dword ptr [ECX + EAX*0x4]
    s.cx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x46cfdb: 890c82 MOV dword ptr [EDX + EAX*0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.cx);
  }
  { // 0x46cfde: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x46cfe1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x46cfe2: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x46cfe4: 7cec JL 0x0046cfd2
    if(integer::condition("JL",flags)) goto L0046cfd2;
  }
  { // 0x46cfe6: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x46cfe8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46cfe9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46cfea: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x46cfeb: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0046cfee: { // 0x46cfee: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  { // 0x46cff1: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  L0046cff4: { // 0x46cff4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x46cff6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46cff7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46cff8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x46cff9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0006d760(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46d760: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46d761: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x46d762: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46d766: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46d768: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x46d76a: 7459 JZ 0x0046d7c5
    if(integer::condition("JZ",flags)) goto L0046d7c5;
  }
  { // 0x46d76c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x46d76e: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x46d771: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x46d774: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46d776: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x46d779: 743f JZ 0x0046d7ba
    if(integer::condition("JZ",flags)) goto L0046d7ba;
  }
  { // 0x46d77b: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  { // 0x46d782: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46d783: e8cf013000 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x46d788: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x46d78b: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x46d78e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46d790: 7433 JZ 0x0046d7c5
    if(integer::condition("JZ",flags)) goto L0046d7c5;
  }
  { // 0x46d792: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x46d795: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x46d797: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x46d799: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x46d79d: 7e26 JLE 0x0046d7c5
    if(integer::condition("JLE",flags)) goto L0046d7c5;
  }
  L0046d79f: { // 0x46d79f: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x46d7a2: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x46d7a5: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x46d7a8: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  { // 0x46d7ab: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x46d7ae: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x46d7af: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x46d7b1: 7cec JL 0x0046d79f
    if(integer::condition("JL",flags)) goto L0046d79f;
  }
  { // 0x46d7b3: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x46d7b5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46d7b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46d7b7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0046d7ba: { // 0x46d7ba: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x46d7c1: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L0046d7c5: { // 0x46d7c5: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x46d7c7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46d7c8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46d7c9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0006d820(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46d820: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46d821: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x46d822: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46d826: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46d828: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x46d82a: 7459 JZ 0x0046d885
    if(integer::condition("JZ",flags)) goto L0046d885;
  }
  { // 0x46d82c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x46d82e: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x46d831: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x46d834: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46d836: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x46d839: 743f JZ 0x0046d87a
    if(integer::condition("JZ",flags)) goto L0046d87a;
  }
  { // 0x46d83b: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
  { // 0x46d842: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46d843: e80f013000 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x46d848: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x46d84b: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x46d84e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46d850: 7433 JZ 0x0046d885
    if(integer::condition("JZ",flags)) goto L0046d885;
  }
  { // 0x46d852: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x46d855: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x46d857: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x46d859: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  { // 0x46d85d: 7e26 JLE 0x0046d885
    if(integer::condition("JLE",flags)) goto L0046d885;
  }
  L0046d85f: { // 0x46d85f: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x46d862: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x46d865: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x46d868: 891481 MOV dword ptr [ECX + EAX*0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.dx);
  }
  { // 0x46d86b: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x46d86e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x46d86f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x46d871: 7cec JL 0x0046d85f
    if(integer::condition("JL",flags)) goto L0046d85f;
  }
  { // 0x46d873: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x46d875: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46d876: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46d877: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0046d87a: { // 0x46d87a: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x46d881: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L0046d885: { // 0x46d885: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x46d887: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46d888: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46d889: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0006fe50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46fe50: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x46fe51: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46fe52: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x46fe53: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46fe55: e846fefbff CALL 0x0042fca0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x46fe5a: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  { // 0x46fe5e: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x46fe60: 750b JNZ 0x0046fe6d
    if(integer::condition("JNZ",flags)) goto L0046fe6d;
  }
  { // 0x46fe62: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x46fe64: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x46fe65: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x46fe66: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x46fe68: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46fe6a: ff5040 CALL dword ptr [EAX + 0x40]
    const std::uint32_t call_target=m.r32((s.ax+0x00000040u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0046fe6d: { // 0x46fe6d: 8a4650 MOV AL,byte ptr [ESI + 0x50]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000050u)));
  }
  { // 0x46fe70: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x46fe74: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x46fe76: 751b JNZ 0x0046fe93
    if(integer::condition("JNZ",flags)) goto L0046fe93;
  }
  { // 0x46fe78: 83ff02 CMP EDI,0x2
    (void)integer::sub(s.di,0x00000002u,32,flags);
  }
  { // 0x46fe7b: 7416 JZ 0x0046fe93
    if(integer::condition("JZ",flags)) goto L0046fe93;
  }
  { // 0x46fe7d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x46fe7f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x46fe80: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46fe82: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x46fe85: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x46fe86: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46fe88: e8b3f7fbff CALL 0x0042f640
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x46fe8d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46fe8e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46fe8f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x46fe90: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0046fe93: { // 0x46fe93: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x46fe94: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46fe96: e8b5f6fbff CALL 0x0042f550
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x46fe9b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x46fe9c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x46fe9e: e89df7fbff CALL 0x0042f640
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x46fea3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46fea4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46fea5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x46fea6: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0007d100(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47d100: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47d101: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x47d103: 8a8674010000 MOV AL,byte ptr [ESI + 0x174]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000174u)));
  }
  { // 0x47d109: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x47d10b: 7406 JZ 0x0047d113
    if(integer::condition("JZ",flags)) goto L0047d113;
  }
  { // 0x47d10d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x47d10f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47d110: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0047d113: { // 0x47d113: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x47d117: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x47d118: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x47d11c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47d11d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x47d11e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x47d11f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47d121: e8aab20b00 CALL 0x005383d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x47d126: f6c301 TEST BL,0x1
    (void)integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x47d129: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x47d12b: 743f JZ 0x0047d16c
    if(integer::condition("JZ",flags)) goto L0047d16c;
  }
  { // 0x47d12d: 8b866c010000 MOV EAX,dword ptr [ESI + 0x16c]
    s.ax = m.r32((s.si+0x0000016cu));
  }
  { // 0x47d133: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47d135: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x47d136: e825b50b00 CALL 0x00538660
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x47d13b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x47d13d: 7405 JZ 0x0047d144
    if(integer::condition("JZ",flags)) goto L0047d144;
  }
  { // 0x47d13f: 8a4004 MOV AL,byte ptr [EAX + 0x4]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000004u)));
  }
  { // 0x47d142: eb02 JMP 0x0047d146
    goto L0047d146;
  }
  L0047d144: { // 0x47d144: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047d146: { // 0x47d146: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x47d148: 8b866c010000 MOV EAX,dword ptr [ESI + 0x16c]
    s.ax = m.r32((s.si+0x0000016cu));
  }
  { // 0x47d14e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47d150: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x47d151: 0f94c3 SETZ BL
    s.bx = with_al(s.bx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x47d154: e807b50b00 CALL 0x00538660
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x47d159: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x47d15b: 740f JZ 0x0047d16c
    if(integer::condition("JZ",flags)) goto L0047d16c;
  }
  { // 0x47d15d: 385804 CMP byte ptr [EAX + 0x4],BL
    (void)integer::sub(m.r8((s.ax+0x00000004u)),(s.bx & 0xffu),8,flags);
  }
  { // 0x47d160: 740a JZ 0x0047d16c
    if(integer::condition("JZ",flags)) goto L0047d16c;
  }
  { // 0x47d162: 885804 MOV byte ptr [EAX + 0x4],BL
    m.w8((s.ax+0x00000004u), (s.bx & 0xffu));
  }
  { // 0x47d165: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x47d167: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47d169: ff5248 CALL dword ptr [EDX + 0x48]
    const std::uint32_t call_target=m.r32((s.dx+0x00000048u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L0047d16c: { // 0x47d16c: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x47d16e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47d16f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x47d170: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47d171: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0007d450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47d450: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x47d451: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47d452: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47d453: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x47d455: 8b8774010000 MOV EAX,dword ptr [EDI + 0x174]
    s.ax = m.r32((s.di+0x00000174u));
  }
  { // 0x47d45b: 8db774010000 LEA ESI,[EDI + 0x174]
    s.si = (s.di+0x00000174u);
  }
  { // 0x47d461: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47d463: c7076c8c7800 MOV dword ptr [EDI],0x788c6c
    m.w32((s.di), 0x00788c6cu);
  }
  { // 0x47d469: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x47d46c: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x47d46e: 899f90010000 MOV dword ptr [EDI + 0x190],EBX
    m.w32((s.di+0x00000190u), s.bx);
  }
  { // 0x47d474: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x47d477: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x47d479: c706d4897800 MOV dword ptr [ESI],0x7889d4
    m.w32((s.si), 0x007889d4u);
  }
  { // 0x47d47f: 7411 JZ 0x0047d492
    if(integer::condition("JZ",flags)) goto L0047d492;
  }
  { // 0x47d481: 385e0d CMP byte ptr [ESI + 0xd],BL
    (void)integer::sub(m.r8((s.si+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  { // 0x47d484: 740c JZ 0x0047d492
    if(integer::condition("JZ",flags)) goto L0047d492;
  }
  { // 0x47d486: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x47d487: e8ef012f00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x47d48c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x47d48f: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L0047d492: { // 0x47d492: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x47d494: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  { // 0x47d497: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  { // 0x47d49a: e801ad0b00 CALL 0x005381a0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x47d49f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47d4a0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47d4a1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x47d4a2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0007d4b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47d4b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47d4b1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47d4b2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x47d4b4: 8b8f7c010000 MOV ECX,dword ptr [EDI + 0x17c]
    s.cx = m.r32((s.di+0x0000017cu));
  }
  { // 0x47d4ba: 8b8784010000 MOV EAX,dword ptr [EDI + 0x184]
    s.ax = m.r32((s.di+0x00000184u));
  }
  { // 0x47d4c0: 8db774010000 LEA ESI,[EDI + 0x174]
    s.si = (s.di+0x00000174u);
  }
  { // 0x47d4c6: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47d4c8: 7c22 JL 0x0047d4ec
    if(integer::condition("JL",flags)) goto L0047d4ec;
  }
  { // 0x47d4ca: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  { // 0x47d4cd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x47d4cf: 7504 JNZ 0x0047d4d5
    if(integer::condition("JNZ",flags)) goto L0047d4d5;
  }
  { // 0x47d4d1: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x47d4d3: 752a JNZ 0x0047d4ff
    if(integer::condition("JNZ",flags)) goto L0047d4ff;
  }
  L0047d4d5: { // 0x47d4d5: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x47d4d8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x47d4da: 7e23 JLE 0x0047d4ff
    if(integer::condition("JLE",flags)) goto L0047d4ff;
  }
  { // 0x47d4dc: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x47d4de: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x47d4e0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x47d4e2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x47d4e3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47d4e5: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x47d4e8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x47d4ea: 7413 JZ 0x0047d4ff
    if(integer::condition("JZ",flags)) goto L0047d4ff;
  }
  L0047d4ec: { // 0x47d4ec: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x47d4ef: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x47d4f2: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  { // 0x47d4f5: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x47d4f8: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x47d4fc: 890c82 MOV dword ptr [EDX + EAX*0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.cx);
  }
  L0047d4ff: { // 0x47d4ff: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x47d503: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x47d505: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x47d506: e835ad0b00 CALL 0x00538240
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x47d50b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47d50c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47d50d: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0007d510(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47d510: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47d511: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x47d513: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x47d517: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  { // 0x47d51a: 8d4e34 LEA ECX,[ESI + 0x34]
    s.cx = (s.si+0x00000034u);
  }
  { // 0x47d51d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x47d51e: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x47d521: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x47d524: 7439 JZ 0x0047d55f
    if(integer::condition("JZ",flags)) goto L0047d55f;
  }
  { // 0x47d526: 8b8e84010000 MOV ECX,dword ptr [ESI + 0x184]
    s.cx = m.r32((s.si+0x00000184u));
  }
  { // 0x47d52c: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47d52e: 7d23 JGE 0x0047d553
    if(integer::condition("JGE",flags)) goto L0047d553;
  }
  { // 0x47d530: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x47d531: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47d533: 898e84010000 MOV dword ptr [ESI + 0x184],ECX
    m.w32((s.si+0x00000184u), s.cx);
  }
  { // 0x47d539: 7d18 JGE 0x0047d553
    if(integer::condition("JGE",flags)) goto L0047d553;
  }
  L0047d53b: { // 0x47d53b: 8b8e78010000 MOV ECX,dword ptr [ESI + 0x178]
    s.cx = m.r32((s.si+0x00000178u));
  }
  { // 0x47d541: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x47d542: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x47d545: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  { // 0x47d549: 8b8e84010000 MOV ECX,dword ptr [ESI + 0x184]
    s.cx = m.r32((s.si+0x00000184u));
  }
  { // 0x47d54f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x47d551: 7ce8 JL 0x0047d53b
    if(integer::condition("JL",flags)) goto L0047d53b;
  }
  L0047d553: { // 0x47d553: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x47d557: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47d559: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x47d55a: e841ae0b00 CALL 0x005383a0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0047d55f: { // 0x47d55f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47d560: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0007db60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47db60: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x47db61: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47db62: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47db63: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x47db65: 8b8774010000 MOV EAX,dword ptr [EDI + 0x174]
    s.ax = m.r32((s.di+0x00000174u));
  }
  { // 0x47db6b: 8db774010000 LEA ESI,[EDI + 0x174]
    s.si = (s.di+0x00000174u);
  }
  { // 0x47db71: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47db73: c7076c8c7800 MOV dword ptr [EDI],0x788c6c
    m.w32((s.di), 0x00788c6cu);
  }
  { // 0x47db79: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x47db7c: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x47db7e: 899f90010000 MOV dword ptr [EDI + 0x190],EBX
    m.w32((s.di+0x00000190u), s.bx);
  }
  { // 0x47db84: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x47db87: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x47db89: c706d4897800 MOV dword ptr [ESI],0x7889d4
    m.w32((s.si), 0x007889d4u);
  }
  { // 0x47db8f: 7411 JZ 0x0047dba2
    if(integer::condition("JZ",flags)) goto L0047dba2;
  }
  { // 0x47db91: 385e0d CMP byte ptr [ESI + 0xd],BL
    (void)integer::sub(m.r8((s.si+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  { // 0x47db94: 740c JZ 0x0047dba2
    if(integer::condition("JZ",flags)) goto L0047dba2;
  }
  { // 0x47db96: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x47db97: e8dffa2e00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x47db9c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x47db9f: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L0047dba2: { // 0x47dba2: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x47dba4: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  { // 0x47dba7: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  { // 0x47dbaa: e8f1a50b00 CALL 0x005381a0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x47dbaf: f644241001 TEST byte ptr [ESP + 0x10],0x1
    (void)integer::logical((m.r8((f.sp+0x00000010u)))&(0x00000001u),8,flags);
  }
  { // 0x47dbb4: 7409 JZ 0x0047dbbf
    if(integer::condition("JZ",flags)) goto L0047dbbf;
  }
  { // 0x47dbb6: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47dbb7: e8bffa2e00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x47dbbc: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0047dbbf: { // 0x47dbbf: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x47dbc1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47dbc2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47dbc3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x47dbc4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00081140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x481140: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x481141: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x481143: 8b4620 MOV EAX,dword ptr [ESI + 0x20]
    s.ax = m.r32((s.si+0x00000020u));
  }
  { // 0x481146: c706cc8d7800 MOV dword ptr [ESI],0x788dcc
    m.w32((s.si), 0x00788dccu);
  }
  { // 0x48114c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x48114d: e829c52e00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x481152: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x481155: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x481158: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x48115a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x48115b: 7406 JZ 0x00481163
    if(integer::condition("JZ",flags)) goto L00481163;
  }
  { // 0x48115d: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x48115f: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x481161: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00481163: { // 0x481163: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000815c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4815c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4815c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4815c3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4815c5: ff501c CALL dword ptr [EAX + 0x1c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000001cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4815c8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4815ca: 7412 JZ 0x004815de
    if(integer::condition("JZ",flags)) goto L004815de;
  }
  { // 0x4815cc: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4815ce: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4815d0: ff5220 CALL dword ptr [EDX + 0x20]
    const std::uint32_t call_target=m.r32((s.dx+0x00000020u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4815d3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4815d5: 7407 JZ 0x004815de
    if(integer::condition("JZ",flags)) goto L004815de;
  }
  { // 0x4815d7: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x4815dc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4815dd: c3 RET
    finish(m,s,f,0u); return;
  }
  L004815de: { // 0x4815de: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4815e0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4815e1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00081850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x481850: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x481851: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x481853: 8b4620 MOV EAX,dword ptr [ESI + 0x20]
    s.ax = m.r32((s.si+0x00000020u));
  }
  { // 0x481856: c706cc8d7800 MOV dword ptr [ESI],0x788dcc
    m.w32((s.si), 0x00788dccu);
  }
  { // 0x48185c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x48185d: e819be2e00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x481862: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x481865: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x481868: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x48186a: 7406 JZ 0x00481872
    if(integer::condition("JZ",flags)) goto L00481872;
  }
  { // 0x48186c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x48186e: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x481870: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00481872: { // 0x481872: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x481877: 7409 JZ 0x00481882
    if(integer::condition("JZ",flags)) goto L00481882;
  }
  { // 0x481879: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x48187a: e8fcbd2e00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x48187f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00481882: { // 0x481882: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x481884: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x481885: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00083290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x483290: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x483291: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x483295: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x483296: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x483297: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x48329b: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x48329d: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x48329f: 7424 JZ 0x004832c5
    if(integer::condition("JZ",flags)) goto L004832c5;
  }
  { // 0x4832a1: 8b4624 MOV EAX,dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  { // 0x4832a4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4832a6: 7417 JZ 0x004832bf
    if(integer::condition("JZ",flags)) goto L004832bf;
  }
  { // 0x4832a8: 80cc80 OR AH,0x80
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))|(0x00000080u),8,flags)) & 0xffu) << 8);
  }
  { // 0x4832ab: f6c340 TEST BL,0x40
    (void)integer::logical(((s.bx & 0xffu))&(0x00000040u),8,flags);
  }
  { // 0x4832ae: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  { // 0x4832b0: 7413 JZ 0x004832c5
    if(integer::condition("JZ",flags)) goto L004832c5;
  }
  { // 0x4832b2: f6462010 TEST byte ptr [ESI + 0x20],0x10
    (void)integer::logical((m.r8((s.si+0x00000020u)))&(0x00000010u),8,flags);
  }
  { // 0x4832b6: 740d JZ 0x004832c5
    if(integer::condition("JZ",flags)) goto L004832c5;
  }
  { // 0x4832b8: 80cc40 OR AH,0x40
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))|(0x00000040u),8,flags)) & 0xffu) << 8);
  }
  { // 0x4832bb: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  { // 0x4832bd: eb06 JMP 0x004832c5
    goto L004832c5;
  }
  L004832bf: { // 0x4832bf: c70700000000 MOV dword ptr [EDI],0x0
    m.w32((s.di), 0x00000000u);
  }
  L004832c5: { // 0x4832c5: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  { // 0x4832c8: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4832ca: 7408 JZ 0x004832d4
    if(integer::condition("JZ",flags)) goto L004832d4;
  }
  { // 0x4832cc: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x4832ce: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4832cf: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4832d0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4832d1: ff504c CALL dword ptr [EAX + 0x4c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000004cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004832d4: { // 0x4832d4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4832d5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4832d6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4832d8: e823bb0400 CALL 0x004cee00
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4832dd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4832de: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4832df: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4832e0: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00083310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x483310: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x483311: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x483313: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  { // 0x483316: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x483318: 7407 JZ 0x00483321
    if(integer::condition("JZ",flags)) goto L00483321;
  }
  { // 0x48331a: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x48331c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x48331e: ff506c CALL dword ptr [EAX + 0x6c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000006cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00483321: { // 0x483321: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x483325: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x483326: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x483328: e8f3ba0400 CALL 0x004cee20
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x48332d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x48332e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000916d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4916d0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4916d1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4916d2: 68b4027c00 PUSH 0x7c02b4
    f.push(m,0x007c02b4u);
  }
  { // 0x4916d7: e81452f7ff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4916dc: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4916df: 688c027c00 PUSH 0x7c028c
    f.push(m,0x007c028cu);
  }
  { // 0x4916e4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4916e6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4916e8: ff1538527800 CALL dword ptr [0x00785238]
    const std::uint32_t call_target=m.r32((0x00785238u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4916ee: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4916f0: ff15f4517800 CALL dword ptr [0x007851f4]
    const std::uint32_t call_target=m.r32((0x007851f4u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4916f6: 3db7000000 CMP EAX,0xb7
    (void)integer::sub(s.ax,0x000000b7u,32,flags);
  }
  { // 0x4916fb: 0f94c3 SETZ BL
    s.bx = with_al(s.bx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x4916fe: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x491700: 7407 JZ 0x00491709
    if(integer::condition("JZ",flags)) goto L00491709;
  }
  { // 0x491702: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x491703: ff15d4517800 CALL dword ptr [0x007851d4]
    const std::uint32_t call_target=m.r32((0x007851d4u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00491709: { // 0x491709: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  { // 0x49170b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49170c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x49170d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00091710(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x491710: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  { // 0x491713: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x491714: 6848037c00 PUSH 0x7c0348
    f.push(m,0x007c0348u);
  }
  { // 0x491719: e8d251f7ff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x49171e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x491721: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x491725: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x491727: 6800040000 PUSH 0x400
    f.push(m,0x00000400u);
  }
  { // 0x49172c: 6800040000 PUSH 0x400
    f.push(m,0x00000400u);
  }
  { // 0x491731: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x491733: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x491734: ff1564547800 CALL dword ptr [0x00785464]
    const std::uint32_t call_target=m.r32((0x00785464u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x49173a: 6820037c00 PUSH 0x7c0320
    f.push(m,0x007c0320u);
  }
  { // 0x49173f: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x491741: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x491743: ff1524527800 CALL dword ptr [0x00785224]
    const std::uint32_t call_target=m.r32((0x00785224u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x491749: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x49174b: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x49174d: 7422 JZ 0x00491771
    if(integer::condition("JZ",flags)) goto L00491771;
  }
  { // 0x49174f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x491750: ff1534527800 CALL dword ptr [0x00785234]
    const std::uint32_t call_target=m.r32((0x00785234u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x491756: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x491757: ff15d4517800 CALL dword ptr [0x007851d4]
    const std::uint32_t call_target=m.r32((0x007851d4u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x49175d: 680c037c00 PUSH 0x7c030c
    f.push(m,0x007c030cu);
  }
  { // 0x491762: e88951f7ff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x491767: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x49176a: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x49176c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49176d: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  { // 0x491770: c3 RET
    finish(m,s,f,0u); return;
  }
  L00491771: { // 0x491771: 68e8027c00 PUSH 0x7c02e8
    f.push(m,0x007c02e8u);
  }
  { // 0x491776: e87551f7ff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[6u].target;
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  { // 0x49177b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x49177e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x491780: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x491781: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  { // 0x491784: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00091790(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x491790: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x491791: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x491793: 817e04efbe0000 CMP dword ptr [ESI + 0x4],0xbeef
    (void)integer::sub(m.r32((s.si+0x00000004u)),0x0000beefu,32,flags);
  }
  { // 0x49179a: 754a JNZ 0x004917e6
    if(integer::condition("JNZ",flags)) goto L004917e6;
  }
  { // 0x49179c: 68a4037c00 PUSH 0x7c03a4
    f.push(m,0x007c03a4u);
  }
  { // 0x4917a1: e84a51f7ff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4917a6: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x4917a9: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4917ac: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4917ae: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4917b0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4917b2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4917b4: 681f000f00 PUSH 0xf001f
    f.push(m,0x000f001fu);
  }
  { // 0x4917b9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4917ba: ff152c527800 CALL dword ptr [0x0078522c]
    const std::uint32_t call_target=m.r32((0x0078522cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4917c0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4917c2: a36c9e8300 MOV [0x00839e6c],EAX
    m.w32((0x00839e6cu), s.ax);
  }
  { // 0x4917c7: 750f JNZ 0x004917d8
    if(integer::condition("JNZ",flags)) goto L004917d8;
  }
  { // 0x4917c9: 6884037c00 PUSH 0x7c0384
    f.push(m,0x007c0384u);
  }
  { // 0x4917ce: e81d51f7ff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4917d3: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4917d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4917d7: c3 RET
    finish(m,s,f,0u); return;
  }
  L004917d8: { // 0x4917d8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4917d9: 686c037c00 PUSH 0x7c036c
    f.push(m,0x007c036cu);
  }
  { // 0x4917de: e80d51f7ff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4917e3: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004917e6: { // 0x4917e6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4917e7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000918e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4918e0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4918e1: 683c047c00 PUSH 0x7c043c
    f.push(m,0x007c043cu);
  }
  { // 0x4918e6: e80550f7ff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4918eb: a16c9e8300 MOV EAX,[0x00839e6c]
    s.ax = m.r32((0x00839e6cu));
  }
  { // 0x4918f0: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4918f3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4918f5: 7411 JZ 0x00491908
    if(integer::condition("JZ",flags)) goto L00491908;
  }
  { // 0x4918f7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4918f8: ff1528527800 CALL dword ptr [0x00785228]
    const std::uint32_t call_target=m.r32((0x00785228u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4918fe: c7056c9e830000000000 MOV dword ptr [0x00839e6c],0x0
    m.w32((0x00839e6cu), 0x00000000u);
  }
  L00491908: { // 0x491908: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x49190c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x49190d: 683f000f00 PUSH 0xf003f
    f.push(m,0x000f003fu);
  }
  { // 0x491912: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x491914: 68dc037c00 PUSH 0x7c03dc
    f.push(m,0x007c03dcu);
  }
  { // 0x491919: 6800000080 PUSH 0x80000000
    f.push(m,0x80000000u);
  }
  { // 0x49191e: ff150c507800 CALL dword ptr [0x0078500c]
    const std::uint32_t call_target=m.r32((0x0078500cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x491924: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x491926: 751b JNZ 0x00491943
    if(integer::condition("JNZ",flags)) goto L00491943;
  }
  { // 0x491928: 8b4c2400 MOV ECX,dword ptr [ESP]
    s.cx = m.r32((f.sp));
  }
  { // 0x49192c: 68d8037c00 PUSH 0x7c03d8
    f.push(m,0x007c03d8u);
  }
  { // 0x491931: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x491932: ff1510507800 CALL dword ptr [0x00785010]
    const std::uint32_t call_target=m.r32((0x00785010u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x491938: 8b542400 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  { // 0x49193c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x49193d: ff1504507800 CALL dword ptr [0x00785004]
    const std::uint32_t call_target=m.r32((0x00785004u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L00491943: { // 0x491943: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x491944: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000928b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4928b0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4928b1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4928b2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4928b4: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  { // 0x4928b7: c7063c967800 MOV dword ptr [ESI],0x78963c
    m.w32((s.si), 0x0078963cu);
  }
  { // 0x4928bd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4928be: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4928c0: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4928c3: 8b561c MOV EDX,dword ptr [ESI + 0x1c]
    s.dx = m.r32((s.si+0x0000001cu));
  }
  { // 0x4928c6: 83c61c ADD ESI,0x1c
    s.si = integer::add(s.si,0x0000001cu,32,flags);
  }
  { // 0x4928c9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4928cb: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4928ce: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x4928d1: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x4928d3: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x4928d5: c706dc957800 MOV dword ptr [ESI],0x7895dc
    m.w32((s.si), 0x007895dcu);
  }
  { // 0x4928db: 7411 JZ 0x004928ee
    if(integer::condition("JZ",flags)) goto L004928ee;
  }
  { // 0x4928dd: 385e0d CMP byte ptr [ESI + 0xd],BL
    (void)integer::sub(m.r8((s.si+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  { // 0x4928e0: 740c JZ 0x004928ee
    if(integer::condition("JZ",flags)) goto L004928ee;
  }
  { // 0x4928e2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4928e3: e893ad2d00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4928e8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4928eb: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L004928ee: { // 0x4928ee: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  { // 0x4928f1: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  { // 0x4928f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4928f5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4928f6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00094bc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x494bc0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x494bc1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x494bc5: 8a4610 MOV AL,byte ptr [ESI + 0x10]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000010u)));
  }
  { // 0x494bc8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x494bca: 7539 JNZ 0x00494c05
    if(integer::condition("JNZ",flags)) goto L00494c05;
  }
  { // 0x494bcc: 8a4611 MOV AL,byte ptr [ESI + 0x11]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000011u)));
  }
  { // 0x494bcf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x494bd1: 7532 JNZ 0x00494c05
    if(integer::condition("JNZ",flags)) goto L00494c05;
  }
  { // 0x494bd3: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x494bd6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x494bd8: 750a JNZ 0x00494be4
    if(integer::condition("JNZ",flags)) goto L00494be4;
  }
  { // 0x494bda: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x494bdf: e88cc62e00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00494be4: { // 0x494be4: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x494be8: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x494bec: 8b7608 MOV ESI,dword ptr [ESI + 0x8]
    s.si = m.r32((s.si+0x00000008u));
  }
  { // 0x494bef: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x494bf0: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x494bf4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494bf5: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x494bf9: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x494bfb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x494bfc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494bfd: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x494bfe: ff5014 CALL dword ptr [EAX + 0x14]
    const std::uint32_t call_target=m.r32((s.ax+0x00000014u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x494c01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x494c02: c21400 RET 0x14
    finish(m,s,f,20u); return;
  }
  L00494c05: { // 0x494c05: b805400080 MOV EAX,0x80004005
    s.ax = 0x80004005u;
  }
  { // 0x494c0a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x494c0b: c21400 RET 0x14
    finish(m,s,f,20u); return;
  }
}
void f_00094c10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x494c10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x494c11: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x494c15: 8a4610 MOV AL,byte ptr [ESI + 0x10]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000010u)));
  }
  { // 0x494c18: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x494c1a: 752f JNZ 0x00494c4b
    if(integer::condition("JNZ",flags)) goto L00494c4b;
  }
  { // 0x494c1c: 8a4611 MOV AL,byte ptr [ESI + 0x11]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000011u)));
  }
  { // 0x494c1f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x494c21: 7528 JNZ 0x00494c4b
    if(integer::condition("JNZ",flags)) goto L00494c4b;
  }
  { // 0x494c23: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x494c26: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x494c28: 750a JNZ 0x00494c34
    if(integer::condition("JNZ",flags)) goto L00494c34;
  }
  { // 0x494c2a: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x494c2f: e83cc62e00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00494c34: { // 0x494c34: 8b7608 MOV ESI,dword ptr [ESI + 0x8]
    s.si = m.r32((s.si+0x00000008u));
  }
  { // 0x494c37: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x494c3b: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x494c3f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x494c40: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x494c42: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494c43: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x494c44: ff5018 CALL dword ptr [EAX + 0x18]
    const std::uint32_t call_target=m.r32((s.ax+0x00000018u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x494c47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x494c48: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00494c4b: { // 0x494c4b: b805400080 MOV EAX,0x80004005
    s.ax = 0x80004005u;
  }
  { // 0x494c50: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x494c51: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00094c60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x494c60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x494c61: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x494c65: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x494c68: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x494c6a: 750a JNZ 0x00494c76
    if(integer::condition("JNZ",flags)) goto L00494c76;
  }
  { // 0x494c6c: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x494c71: e8fac52e00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00494c76: { // 0x494c76: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x494c7a: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x494c7d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494c7e: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x494c82: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494c83: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x494c87: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x494c89: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494c8a: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x494c8e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494c8f: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x494c93: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494c94: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x494c95: ff511c CALL dword ptr [ECX + 0x1c]
    const std::uint32_t call_target=m.r32((s.cx+0x0000001cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x494c98: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x494c99: c21800 RET 0x18
    finish(m,s,f,24u); return;
  }
}
void f_00094ca0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x494ca0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x494ca1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x494ca5: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x494ca8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x494caa: 750a JNZ 0x00494cb6
    if(integer::condition("JNZ",flags)) goto L00494cb6;
  }
  { // 0x494cac: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x494cb1: e8bac52e00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00494cb6: { // 0x494cb6: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x494cb9: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x494cbd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494cbe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x494cbf: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x494cc1: ff5120 CALL dword ptr [ECX + 0x20]
    const std::uint32_t call_target=m.r32((s.cx+0x00000020u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x494cc4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x494cc5: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00094cd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x494cd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x494cd1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x494cd5: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x494cd8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x494cda: 750a JNZ 0x00494ce6
    if(integer::condition("JNZ",flags)) goto L00494ce6;
  }
  { // 0x494cdc: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x494ce1: e88ac52e00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00494ce6: { // 0x494ce6: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x494ce9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x494cea: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x494cec: ff5124 CALL dword ptr [ECX + 0x24]
    const std::uint32_t call_target=m.r32((s.cx+0x00000024u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x494cef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x494cf0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00094d00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x494d00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x494d01: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x494d05: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x494d08: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x494d0a: 750a JNZ 0x00494d16
    if(integer::condition("JNZ",flags)) goto L00494d16;
  }
  { // 0x494d0c: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x494d11: e85ac52e00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00494d16: { // 0x494d16: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x494d1a: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x494d1d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494d1e: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x494d22: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494d23: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x494d27: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x494d29: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494d2a: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x494d2e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494d2f: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x494d33: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494d34: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x494d35: ff5128 CALL dword ptr [ECX + 0x28]
    const std::uint32_t call_target=m.r32((s.cx+0x00000028u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x494d38: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x494d39: c21800 RET 0x18
    finish(m,s,f,24u); return;
  }
}
void f_00094d40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x494d40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x494d41: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x494d45: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x494d48: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x494d4a: 750a JNZ 0x00494d56
    if(integer::condition("JNZ",flags)) goto L00494d56;
  }
  { // 0x494d4c: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x494d51: e81ac52e00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00494d56: { // 0x494d56: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x494d5a: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x494d5d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494d5e: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x494d62: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494d63: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x494d67: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x494d69: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494d6a: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x494d6e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494d6f: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x494d73: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494d74: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x494d75: ff512c CALL dword ptr [ECX + 0x2c]
    const std::uint32_t call_target=m.r32((s.cx+0x0000002cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x494d78: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x494d79: c21800 RET 0x18
    finish(m,s,f,24u); return;
  }
}
void f_00094d80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x494d80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x494d81: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x494d85: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x494d88: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x494d8a: 750a JNZ 0x00494d96
    if(integer::condition("JNZ",flags)) goto L00494d96;
  }
  { // 0x494d8c: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x494d91: e8dac42e00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00494d96: { // 0x494d96: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x494d9a: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x494d9d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494d9e: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x494da2: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x494da4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494da5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x494da6: ff5130 CALL dword ptr [ECX + 0x30]
    const std::uint32_t call_target=m.r32((s.cx+0x00000030u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x494da9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x494daa: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00094db0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x494db0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x494db1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x494db5: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x494db8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x494dba: 750a JNZ 0x00494dc6
    if(integer::condition("JNZ",flags)) goto L00494dc6;
  }
  { // 0x494dbc: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x494dc1: e8aac42e00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00494dc6: { // 0x494dc6: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x494dc9: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x494dcd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x494dce: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x494dcf: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x494dd1: ff5134 CALL dword ptr [ECX + 0x34]
    const std::uint32_t call_target=m.r32((s.cx+0x00000034u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x494dd4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x494dd5: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00095010(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x495010: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x495011: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x495012: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x495014: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x495015: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x495017: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x495019: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x49501a: ff5014 CALL dword ptr [EAX + 0x14]
    const std::uint32_t call_target=m.r32((s.ax+0x00000014u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x49501d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x49501f: 7421 JZ 0x00495042
    if(integer::condition("JZ",flags)) goto L00495042;
  }
  { // 0x495021: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x495023: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x495025: ff522c CALL dword ptr [EDX + 0x2c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000002cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x495028: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x49502a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x49502b: e827892d00 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x495030: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x495032: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x495035: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x495037: 7409 JZ 0x00495042
    if(integer::condition("JZ",flags)) goto L00495042;
  }
  { // 0x495039: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x49503b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x49503c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x49503d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x49503f: ff5024 CALL dword ptr [EAX + 0x24]
    const std::uint32_t call_target=m.r32((s.ax+0x00000024u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00495042: { // 0x495042: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x495044: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x495045: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x495046: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x495047: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000952c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4952c0: a1d89f8300 MOV EAX,[0x00839fd8]
    s.ax = m.r32((0x00839fd8u));
  }
  { // 0x4952c5: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  { // 0x4952cb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4952cc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4952cd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4952ce: ff151c527800 CALL dword ptr [0x0078521c]
    const std::uint32_t call_target=m.r32((0x0078521cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4952d4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4952d6: 7501 JNZ 0x004952d9
    if(integer::condition("JNZ",flags)) goto L004952d9;
  }
  { // 0x4952d8: c3 RET
    finish(m,s,f,0u); return;
  }
  L004952d9: { // 0x4952d9: 8b0dd89f8300 MOV ECX,dword ptr [0x00839fd8]
    s.cx = m.r32((0x00839fd8u));
  }
  { // 0x4952df: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4952e0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4952e1: ff1520527800 CALL dword ptr [0x00785220]
    const std::uint32_t call_target=m.r32((0x00785220u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4952e7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4952e9: 7501 JNZ 0x004952ec
    if(integer::condition("JNZ",flags)) goto L004952ec;
  }
  { // 0x4952eb: c3 RET
    finish(m,s,f,0u); return;
  }
  L004952ec: { // 0x4952ec: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4952ed: ff1518527800 CALL dword ptr [0x00785218]
    const std::uint32_t call_target=m.r32((0x00785218u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4952f3: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00095330(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x495330: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x495331: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x495333: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x495335: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x495337: ff5014 CALL dword ptr [EAX + 0x14]
    const std::uint32_t call_target=m.r32((s.ax+0x00000014u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x49533a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x49533c: 7425 JZ 0x00495363
    if(integer::condition("JZ",flags)) goto L00495363;
  }
  { // 0x49533e: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x495340: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x495341: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x495342: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x495344: ff522c CALL dword ptr [EDX + 0x2c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000002cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x495347: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x495349: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x49534a: e808862d00 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x49534f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x495352: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x495354: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x495356: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x495358: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x495359: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x49535a: ff5024 CALL dword ptr [EAX + 0x24]
    const std::uint32_t call_target=m.r32((s.ax+0x00000024u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x49535d: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x49535f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x495360: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x495361: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x495362: c3 RET
    finish(m,s,f,0u); return;
  }
  L00495363: { // 0x495363: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x495365: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x495366: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00095550(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x495550: 83ec50 SUB ESP,0x50
    f.sp = integer::sub(f.sp,0x00000050u,32,flags);
  }
  { // 0x495553: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x495555: 751f JNZ 0x00495576
    if(integer::condition("JNZ",flags)) goto L00495576;
  }
  { // 0x495557: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x495559: 7455 JZ 0x004955b0
    if(integer::condition("JZ",flags)) goto L004955b0;
  }
  { // 0x49555b: a150deb000 MOV EAX,[0x00b0de50]
    s.ax = m.r32((0x00b0de50u));
  }
  { // 0x495560: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x495561: 68240b7c00 PUSH 0x7c0b24
    f.push(m,0x007c0b24u);
  }
  { // 0x495566: 68f40a7c00 PUSH 0x7c0af4
    f.push(m,0x007c0af4u);
  }
  { // 0x49556b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x49556c: ff157c547800 CALL dword ptr [0x0078547c]
    const std::uint32_t call_target=m.r32((0x0078547cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x495572: 83c450 ADD ESP,0x50
    f.sp = integer::add(f.sp,0x00000050u,32,flags);
  }
  { // 0x495575: c3 RET
    finish(m,s,f,0u); return;
  }
  L00495576: { // 0x495576: a11ca78300 MOV EAX,[0x0083a71c]
    s.ax = m.r32((0x0083a71cu));
  }
  { // 0x49557b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x49557d: 7406 JZ 0x00495585
    if(integer::condition("JZ",flags)) goto L00495585;
  }
  { // 0x49557f: ffd0 CALL EAX
    const std::uint32_t call_target=s.ax;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x495581: 83c450 ADD ESP,0x50
    f.sp = integer::add(f.sp,0x00000050u,32,flags);
  }
  { // 0x495584: c3 RET
    finish(m,s,f,0u); return;
  }
  L00495585: { // 0x495585: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x495586: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x49558a: 68d80a7c00 PUSH 0x7c0ad8
    f.push(m,0x007c0ad8u);
  }
  { // 0x49558f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x495590: e89f842d00 CALL 0x0076da34
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x495595: a150deb000 MOV EAX,[0x00b0de50]
    s.ax = m.r32((0x00b0de50u));
  }
  { // 0x49559a: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x49559d: 8d542400 LEA EDX,[ESP]
    s.dx = (f.sp);
  }
  { // 0x4955a1: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  { // 0x4955a3: 68cc0a7c00 PUSH 0x7c0acc
    f.push(m,0x007c0accu);
  }
  { // 0x4955a8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4955a9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4955aa: ff157c547800 CALL dword ptr [0x0078547c]
    const std::uint32_t call_target=m.r32((0x0078547cu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L004955b0: { // 0x4955b0: 83c450 ADD ESP,0x50
    f.sp = integer::add(f.sp,0x00000050u,32,flags);
  }
  { // 0x4955b3: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00095840(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x495840: a1fca68300 MOV EAX,[0x0083a6fc]
    s.ax = m.r32((0x0083a6fcu));
  }
  { // 0x495845: 83ec50 SUB ESP,0x50
    f.sp = integer::sub(f.sp,0x00000050u,32,flags);
  }
  { // 0x495848: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x49584a: 745c JZ 0x004958a8
    if(integer::condition("JZ",flags)) goto L004958a8;
  }
  { // 0x49584c: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x49584e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x49584f: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x495852: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x495854: 7448 JZ 0x0049589e
    if(integer::condition("JZ",flags)) goto L0049589e;
  }
  { // 0x495856: 8b151ca78300 MOV EDX,dword ptr [0x0083a71c]
    s.dx = m.r32((0x0083a71cu));
  }
  { // 0x49585c: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x49585e: 7412 JZ 0x00495872
    if(integer::condition("JZ",flags)) goto L00495872;
  }
  { // 0x495860: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x495862: ffd2 CALL EDX
    const std::uint32_t call_target=s.dx;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x495864: c705fca6830000000000 MOV dword ptr [0x0083a6fc],0x0
    m.w32((0x0083a6fcu), 0x00000000u);
  }
  { // 0x49586e: 83c450 ADD ESP,0x50
    f.sp = integer::add(f.sp,0x00000050u,32,flags);
  }
  { // 0x495871: c3 RET
    finish(m,s,f,0u); return;
  }
  L00495872: { // 0x495872: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x495873: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  { // 0x495877: 68d80a7c00 PUSH 0x7c0ad8
    f.push(m,0x007c0ad8u);
  }
  { // 0x49587c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x49587d: e8b2812d00 CALL 0x0076da34
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x495882: 8b0d50deb000 MOV ECX,dword ptr [0x00b0de50]
    s.cx = m.r32((0x00b0de50u));
  }
  { // 0x495888: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x49588b: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x49588f: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  { // 0x495891: 68cc0a7c00 PUSH 0x7c0acc
    f.push(m,0x007c0accu);
  }
  { // 0x495896: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x495897: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x495898: ff157c547800 CALL dword ptr [0x0078547c]
    const std::uint32_t call_target=m.r32((0x0078547cu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L0049589e: { // 0x49589e: c705fca6830000000000 MOV dword ptr [0x0083a6fc],0x0
    m.w32((0x0083a6fcu), 0x00000000u);
  }
  L004958a8: { // 0x4958a8: 83c450 ADD ESP,0x50
    f.sp = integer::add(f.sp,0x00000050u,32,flags);
  }
  { // 0x4958ab: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00098150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x498150: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x498151: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x498153: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x498156: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x498158: 7409 JZ 0x00498163
    if(integer::condition("JZ",flags)) goto L00498163;
  }
  { // 0x49815a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x49815b: e81b552d00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x498160: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00498163: { // 0x498163: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x498166: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x498168: 7407 JZ 0x00498171
    if(integer::condition("JZ",flags)) goto L00498171;
  }
  { // 0x49816a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x49816b: ff1558507800 CALL dword ptr [0x00785058]
    const std::uint32_t call_target=m.r32((0x00785058u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00498171: { // 0x498171: 8b4e20 MOV ECX,dword ptr [ESI + 0x20]
    s.cx = m.r32((s.si+0x00000020u));
  }
  { // 0x498174: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x498175: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x498177: 7406 JZ 0x0049817f
    if(integer::condition("JZ",flags)) goto L0049817f;
  }
  { // 0x498179: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x49817b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x49817d: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L0049817f: { // 0x49817f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00098950(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x498950: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x498953: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x498954: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x498956: e805cc0a00 CALL 0x00545560
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x49895b: b9600e7c00 MOV ECX,0x7c0e60
    s.cx = 0x007c0e60u;
  }
  { // 0x498960: e85b9b0f00 CALL 0x005924c0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x498965: b9540e7c00 MOV ECX,0x7c0e54
    s.cx = 0x007c0e54u;
  }
  { // 0x49896a: a344a98300 MOV [0x0083a944],EAX
    m.w32((0x0083a944u), s.ax);
  }
  { // 0x49896f: e84c9b0f00 CALL 0x005924c0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x498974: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  { // 0x498978: a368ac8300 MOV [0x0083ac68],EAX
    m.w32((0x0083ac68u), s.ax);
  }
  { // 0x49897d: e88ee62400 CALL 0x006e7010
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x498982: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x498984: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  { // 0x498988: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x49898b: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
  { // 0x49898f: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  { // 0x498992: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  { // 0x498996: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x49899a: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  { // 0x49899d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x49899f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4989a0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4989a2: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  { // 0x4989a6: ff90a8000000 CALL dword ptr [EAX + 0xa8]
    const std::uint32_t call_target=m.r32((s.ax+0x000000a8u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x4989ac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4989ad: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x4989b0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00098a30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x498a30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x498a31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x498a33: e8e8750400 CALL 0x004e0020
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x498a38: a05389a200 MOV AL,[0x00a28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  { // 0x498a3d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x498a3f: 7516 JNZ 0x00498a57
    if(integer::condition("JNZ",flags)) goto L00498a57;
  }
  { // 0x498a41: b940ac8300 MOV ECX,0x83ac40
    s.cx = 0x0083ac40u;
  }
  { // 0x498a46: e885e70900 CALL 0x005371d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x498a4b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x498a4d: 6840ac8300 PUSH 0x83ac40
    f.push(m,0x0083ac40u);
  }
  { // 0x498a52: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x498a54: ff5030 CALL dword ptr [EAX + 0x30]
    const std::uint32_t call_target=m.r32((s.ax+0x00000030u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00498a57: { // 0x498a57: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x498a58: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00099820(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x499820: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x499821: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x499825: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x499827: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x499828: 743e JZ 0x00499868
    if(integer::condition("JZ",flags)) goto L00499868;
  }
  { // 0x49982a: 83be80000000ff CMP dword ptr [ESI + 0x80],-0x1
    (void)integer::sub(m.r32((s.si+0x00000080u)),0xffffffffu,32,flags);
  }
  { // 0x499831: 7406 JZ 0x00499839
    if(integer::condition("JZ",flags)) goto L00499839;
  }
  { // 0x499833: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x499834: e837000000 CALL 0x00499870
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00499839: { // 0x499839: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x49983b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x49983d: ff5074 CALL dword ptr [EAX + 0x74]
    const std::uint32_t call_target=m.r32((s.ax+0x00000074u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x499840: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x499842: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  { // 0x499845: 7421 JZ 0x00499868
    if(integer::condition("JZ",flags)) goto L00499868;
  }
  { // 0x499847: 83ff02 CMP EDI,0x2
    (void)integer::sub(s.di,0x00000002u,32,flags);
  }
  { // 0x49984a: 8d147f LEA EDX,[EDI + EDI*0x2]
    s.dx = (s.di+(s.di * 0x00000002u));
  }
  { // 0x49984d: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x499850: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x499851: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x499852: 8d0cd5a8a88300 LEA ECX,[EDX*0x8 + 0x83a8a8]
    s.cx = ((s.dx * 0x00000008u)+0x0083a8a8u);
  }
  { // 0x499859: e8a2920900 CALL 0x00532b00
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x49985e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x499860: 7406 JZ 0x00499868
    if(integer::condition("JZ",flags)) goto L00499868;
  }
  { // 0x499862: 89be80000000 MOV dword ptr [ESI + 0x80],EDI
    m.w32((s.si+0x00000080u), s.di);
  }
  L00499868: { // 0x499868: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x499869: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49986a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0009e920(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x49e920: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x49e921: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x49e923: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  { // 0x49e929: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x49e92b: 7405 JZ 0x0049e932
    if(integer::condition("JZ",flags)) goto L0049e932;
  }
  { // 0x49e92d: e87e142000 CALL 0x0069fdb0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0049e932: { // 0x49e932: c686cb11000000 MOV byte ptr [ESI + 0x11cb],0x0
    m.w8((s.si+0x000011cbu), 0x00000000u);
  }
  { // 0x49e939: c686cc11000000 MOV byte ptr [ESI + 0x11cc],0x0
    m.w8((s.si+0x000011ccu), 0x00000000u);
  }
  { // 0x49e940: c6058589a20001 MOV byte ptr [0x00a28985],0x1
    m.w8((0x00a28985u), 0x00000001u);
  }
  { // 0x49e947: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x49e949: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x49e94b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x49e94d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x49e94f: ff5048 CALL dword ptr [EAX + 0x48]
    const std::uint32_t call_target=m.r32((s.ax+0x00000048u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x49e952: 68ac0f7c00 PUSH 0x7c0fac
    f.push(m,0x007c0facu);
  }
  { // 0x49e957: e8947ff6ff CALL 0x004068f0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x49e95c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x49e95f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49e960: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0009eb30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x49eb30: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  { // 0x49eb33: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x49eb34: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x49eb35: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x49eb36: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x49eb38: ff1510527800 CALL dword ptr [0x00785210]
    const std::uint32_t call_target=m.r32((0x00785210u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x49eb3e: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x49eb40: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x49eb42: 7458 JZ 0x0049eb9c
    if(integer::condition("JZ",flags)) goto L0049eb9c;
  }
  { // 0x49eb44: 68cc0f7c00 PUSH 0x7c0fcc
    f.push(m,0x007c0fccu);
  }
  { // 0x49eb49: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x49eb4a: ff1540527800 CALL dword ptr [0x00785240]
    const std::uint32_t call_target=m.r32((0x00785240u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x49eb50: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x49eb52: 7441 JZ 0x0049eb95
    if(integer::condition("JZ",flags)) goto L0049eb95;
  }
  { // 0x49eb54: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x49eb56: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x49eb5a: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  { // 0x49eb5e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x49eb5f: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  { // 0x49eb63: c744240c14000000 MOV dword ptr [ESP + 0xc],0x14
    m.w32((f.sp+0x0000000cu), 0x00000014u);
  }
  { // 0x49eb6b: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  { // 0x49eb6f: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  { // 0x49eb73: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  { // 0x49eb77: ffd0 CALL EAX
    const std::uint32_t call_target=s.ax;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x49eb79: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x49eb7b: 7c18 JL 0x0049eb95
    if(integer::condition("JL",flags)) goto L0049eb95;
  }
  { // 0x49eb7d: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x49eb81: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x49eb85: 81e6ffff0000 AND ESI,0xffff
    s.si = integer::logical((s.si)&(0x0000ffffu),32,flags);
  }
  { // 0x49eb8b: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  { // 0x49eb90: c1e610 SHL ESI,0x10
    s.si = integer::shift(s.si,0x00000010u,32,flags,integer::Shift::left);
  }
  { // 0x49eb93: 0bf0 OR ESI,EAX
    s.si = integer::logical((s.si)|(s.ax),32,flags);
  }
  L0049eb95: { // 0x49eb95: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x49eb96: ff1514527800 CALL dword ptr [0x00785214]
    const std::uint32_t call_target=m.r32((0x00785214u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L0049eb9c: { // 0x49eb9c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x49eb9e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x49eb9f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49eba0: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x49eba3: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0009f400(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x49f400: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x49f401: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x49f403: c70694b57800 MOV dword ptr [ESI],0x78b594
    m.w32((s.si), 0x0078b594u);
  }
  { // 0x49f409: c74604ccb47800 MOV dword ptr [ESI + 0x4],0x78b4cc
    m.w32((s.si+0x00000004u), 0x0078b4ccu);
  }
  { // 0x49f410: c74618a8b47800 MOV dword ptr [ESI + 0x18],0x78b4a8
    m.w32((s.si+0x00000018u), 0x0078b4a8u);
  }
  { // 0x49f417: 8b4668 MOV EAX,dword ptr [ESI + 0x68]
    s.ax = m.r32((s.si+0x00000068u));
  }
  { // 0x49f41a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x49f41c: 7406 JZ 0x0049f424
    if(integer::condition("JZ",flags)) goto L0049f424;
  }
  { // 0x49f41e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x49f420: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x49f421: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0049f424: { // 0x49f424: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x49f426: e8a5bd0900 CALL 0x0053b1d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x49f42b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49f42c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0009fa30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x49fa30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x49fa31: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x49fa35: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x49fa38: 81c1e0020000 ADD ECX,0x2e0
    s.cx = integer::add(s.cx,0x000002e0u,32,flags);
  }
  { // 0x49fa3e: e8bd8e0100 CALL 0x004b8900
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x49fa43: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x49fa45: 7406 JZ 0x0049fa4d
    if(integer::condition("JZ",flags)) goto L0049fa4d;
  }
  { // 0x49fa47: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x49fa49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49fa4a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0049fa4d: { // 0x49fa4d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x49fa4f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x49fa50: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x49fa53: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x49fa55: 743a JZ 0x0049fa91
    if(integer::condition("JZ",flags)) goto L0049fa91;
  }
  { // 0x49fa57: 8b4e3c MOV ECX,dword ptr [ESI + 0x3c]
    s.cx = m.r32((s.si+0x0000003cu));
  }
  { // 0x49fa5a: a1c8ac8300 MOV EAX,[0x0083acc8]
    s.ax = m.r32((0x0083acc8u));
  }
  { // 0x49fa5f: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x49fa61: 7519 JNZ 0x0049fa7c
    if(integer::condition("JNZ",flags)) goto L0049fa7c;
  }
  { // 0x49fa63: 8b5640 MOV EDX,dword ptr [ESI + 0x40]
    s.dx = m.r32((s.si+0x00000040u));
  }
  { // 0x49fa66: a1ccac8300 MOV EAX,[0x0083accc]
    s.ax = m.r32((0x0083acccu));
  }
  { // 0x49fa6b: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x49fa6d: 750d JNZ 0x0049fa7c
    if(integer::condition("JNZ",flags)) goto L0049fa7c;
  }
  { // 0x49fa6f: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  { // 0x49fa72: 8b0dd0ac8300 MOV ECX,dword ptr [0x0083acd0]
    s.cx = m.r32((0x0083acd0u));
  }
  { // 0x49fa78: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x49fa7a: 7415 JZ 0x0049fa91
    if(integer::condition("JZ",flags)) goto L0049fa91;
  }
  L0049fa7c: { // 0x49fa7c: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x49fa7f: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x49fa81: ff92bc040000 CALL dword ptr [EDX + 0x4bc]
    const std::uint32_t call_target=m.r32((s.dx+0x000004bcu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x49fa87: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x49fa89: 7e06 JLE 0x0049fa91
    if(integer::condition("JLE",flags)) goto L0049fa91;
  }
  { // 0x49fa8b: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x49fa8d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49fa8e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0049fa91: { // 0x49fa91: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x49fa93: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49fa94: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000a02e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a02e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a02e1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x4a02e5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a02e6: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x4a02e9: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x4a02eb: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x4a02ed: ff90a4010000 CALL dword ptr [EAX + 0x1a4]
    const std::uint32_t call_target=m.r32((s.ax+0x000001a4u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4a02f3: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x4a02f5: 8a881c010000 MOV CL,byte ptr [EAX + 0x11c]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000011cu)));
  }
  { // 0x4a02fb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4a02fc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a02fd: ff577c CALL dword ptr [EDI + 0x7c]
    const std::uint32_t call_target=m.r32((s.di+0x0000007cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4a0300: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4a0301: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a0302: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000a4570(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a4570: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a4571: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4a4573: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x4a4576: 8b8188040000 MOV EAX,dword ptr [ECX + 0x488]
    s.ax = m.r32((s.cx+0x00000488u));
  }
  { // 0x4a457c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4a457e: 7510 JNZ 0x004a4590
    if(integer::condition("JNZ",flags)) goto L004a4590;
  }
  { // 0x4a4580: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x4a4582: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4a4584: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4a4586: ff9010040000 CALL dword ptr [EAX + 0x410]
    const std::uint32_t call_target=m.r32((s.ax+0x00000410u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4a458c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4a458e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a458f: c3 RET
    finish(m,s,f,0u); return;
  }
  L004a4590: { // 0x4a4590: e81b900200 CALL 0x004cd5b0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4a4595: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x4a4598: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4a459a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4a459c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x4a459e: ff9214040000 CALL dword ptr [EDX + 0x414]
    const std::uint32_t call_target=m.r32((s.dx+0x00000414u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4a45a4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a45a5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000a49d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a49d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a49d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4a49d3: c70694b57800 MOV dword ptr [ESI],0x78b594
    m.w32((s.si), 0x0078b594u);
  }
  { // 0x4a49d9: c74604ccb47800 MOV dword ptr [ESI + 0x4],0x78b4cc
    m.w32((s.si+0x00000004u), 0x0078b4ccu);
  }
  { // 0x4a49e0: c74618a8b47800 MOV dword ptr [ESI + 0x18],0x78b4a8
    m.w32((s.si+0x00000018u), 0x0078b4a8u);
  }
  { // 0x4a49e7: 8b4668 MOV EAX,dword ptr [ESI + 0x68]
    s.ax = m.r32((s.si+0x00000068u));
  }
  { // 0x4a49ea: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4a49ec: 7406 JZ 0x004a49f4
    if(integer::condition("JZ",flags)) goto L004a49f4;
  }
  { // 0x4a49ee: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4a49f0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4a49f1: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004a49f4: { // 0x4a49f4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4a49f6: e8d5670900 CALL 0x0053b1d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4a49fb: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x4a4a00: 7409 JZ 0x004a4a0b
    if(integer::condition("JZ",flags)) goto L004a4a0b;
  }
  { // 0x4a4a02: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a4a03: e8738c2c00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4a4a08: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004a4a0b: { // 0x4a4a0b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4a4a0d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a4a0e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000a4ba0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a4ba0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a4ba1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4a4ba3: 8a4648 MOV AL,byte ptr [ESI + 0x48]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000048u)));
  }
  { // 0x4a4ba6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4a4ba8: 7413 JZ 0x004a4bbd
    if(integer::condition("JZ",flags)) goto L004a4bbd;
  }
  { // 0x4a4baa: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  { // 0x4a4bb0: 8d8eb0000000 LEA ECX,[ESI + 0xb0]
    s.cx = (s.si+0x000000b0u);
  }
  { // 0x4a4bb6: ff5024 CALL dword ptr [EAX + 0x24]
    const std::uint32_t call_target=m.r32((s.ax+0x00000024u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4a4bb9: c6464800 MOV byte ptr [ESI + 0x48],0x0
    m.w8((s.si+0x00000048u), 0x00000000u);
  }
  L004a4bbd: { // 0x4a4bbd: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  { // 0x4a4bc3: 8d8eb0000000 LEA ECX,[ESI + 0xb0]
    s.cx = (s.si+0x000000b0u);
  }
  { // 0x4a4bc9: ff5220 CALL dword ptr [EDX + 0x20]
    const std::uint32_t call_target=m.r32((s.dx+0x00000020u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4a4bcc: 8b4650 MOV EAX,dword ptr [ESI + 0x50]
    s.ax = m.r32((s.si+0x00000050u));
  }
  { // 0x4a4bcf: 8d4e50 LEA ECX,[ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  { // 0x4a4bd2: ff5020 CALL dword ptr [EAX + 0x20]
    const std::uint32_t call_target=m.r32((s.ax+0x00000020u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4a4bd5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4a4bd7: e8f4250900 CALL 0x005371d0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4a4bdc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a4bdd: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000a4be0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a4be0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a4be1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4a4be3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a4be4: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4a4be8: 8b4650 MOV EAX,dword ptr [ESI + 0x50]
    s.ax = m.r32((s.si+0x00000050u));
  }
  { // 0x4a4beb: 8d4e50 LEA ECX,[ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  { // 0x4a4bee: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a4bef: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4a4bf2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a4bf3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4a4bf5: e886260900 CALL 0x00537280
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4a4bfa: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4a4bfb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a4bfc: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000a4c00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a4c00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a4c01: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4a4c03: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a4c04: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4a4c08: 8b4650 MOV EAX,dword ptr [ESI + 0x50]
    s.ax = m.r32((s.si+0x00000050u));
  }
  { // 0x4a4c0b: 8d4e50 LEA ECX,[ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  { // 0x4a4c0e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a4c0f: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4a4c12: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a4c13: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4a4c15: e8a6260900 CALL 0x005372c0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4a4c1a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4a4c1b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a4c1c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000a4c20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a4c20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a4c21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4a4c23: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a4c24: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4a4c28: 8b4650 MOV EAX,dword ptr [ESI + 0x50]
    s.ax = m.r32((s.si+0x00000050u));
  }
  { // 0x4a4c2b: 8d4e50 LEA ECX,[ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  { // 0x4a4c2e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a4c2f: ff5014 CALL dword ptr [EAX + 0x14]
    const std::uint32_t call_target=m.r32((s.ax+0x00000014u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4a4c32: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a4c33: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4a4c35: e866260900 CALL 0x005372a0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4a4c3a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4a4c3b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a4c3c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000a4c40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a4c40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a4c41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4a4c43: 8a4648 MOV AL,byte ptr [ESI + 0x48]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000048u)));
  }
  { // 0x4a4c46: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4a4c48: 7413 JZ 0x004a4c5d
    if(integer::condition("JZ",flags)) goto L004a4c5d;
  }
  { // 0x4a4c4a: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  { // 0x4a4c50: 8d8eb0000000 LEA ECX,[ESI + 0xb0]
    s.cx = (s.si+0x000000b0u);
  }
  { // 0x4a4c56: ff5024 CALL dword ptr [EAX + 0x24]
    const std::uint32_t call_target=m.r32((s.ax+0x00000024u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4a4c59: c6464800 MOV byte ptr [ESI + 0x48],0x0
    m.w8((s.si+0x00000048u), 0x00000000u);
  }
  L004a4c5d: { // 0x4a4c5d: 8b5650 MOV EDX,dword ptr [ESI + 0x50]
    s.dx = m.r32((s.si+0x00000050u));
  }
  { // 0x4a4c60: 8d4e50 LEA ECX,[ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  { // 0x4a4c63: ff5224 CALL dword ptr [EDX + 0x24]
    const std::uint32_t call_target=m.r32((s.dx+0x00000024u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4a4c66: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4a4c68: e8e3a00200 CALL 0x004ced50
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4a4c6d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a4c6e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000a4c70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a4c70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a4c71: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4a4c73: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a4c74: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4a4c78: 8b4638 MOV EAX,dword ptr [ESI + 0x38]
    s.ax = m.r32((s.si+0x00000038u));
  }
  { // 0x4a4c7b: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  { // 0x4a4c7e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4a4c7f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a4c80: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4a4c81: e8dca22c00 CALL 0x0076ef62
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4a4c86: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4a4c88: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x4a4c8b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4a4c8d: ff5248 CALL dword ptr [EDX + 0x48]
    const std::uint32_t call_target=m.r32((s.dx+0x00000048u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4a4c90: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  { // 0x4a4c96: 8d8eb0000000 LEA ECX,[ESI + 0xb0]
    s.cx = (s.si+0x000000b0u);
  }
  { // 0x4a4c9c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a4c9d: ff9088000000 CALL dword ptr [EAX + 0x88]
    const std::uint32_t call_target=m.r32((s.ax+0x00000088u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4a4ca3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4a4ca4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a4ca5: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000a4cf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a4cf0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a4cf1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a4cf2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x4a4cf4: 8b87b0000000 MOV EAX,dword ptr [EDI + 0xb0]
    s.ax = m.r32((s.di+0x000000b0u));
  }
  { // 0x4a4cfa: 8db7b0000000 LEA ESI,[EDI + 0xb0]
    s.si = (s.di+0x000000b0u);
  }
  { // 0x4a4d00: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4a4d02: ff9094000000 CALL dword ptr [EAX + 0x94]
    const std::uint32_t call_target=m.r32((s.ax+0x00000094u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4a4d08: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4a4d0c: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x4a4d0e: 7334 JNC 0x004a4d44
    if(integer::condition("JNC",flags)) goto L004a4d44;
  }
  { // 0x4a4d10: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4a4d12: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4a4d13: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4a4d14: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4a4d16: ff92b8000000 CALL dword ptr [EDX + 0xb8]
    const std::uint32_t call_target=m.r32((s.dx+0x000000b8u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4a4d1c: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x4a4d1e: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  { // 0x4a4d20: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4a4d22: ff90a4000000 CALL dword ptr [EAX + 0xa4]
    const std::uint32_t call_target=m.r32((s.ax+0x000000a4u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4a4d28: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4a4d29: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4a4d2b: ff93a0000000 CALL dword ptr [EBX + 0xa0]
    const std::uint32_t call_target=m.r32((s.bx+0x000000a0u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4a4d31: 8b4f34 MOV ECX,dword ptr [EDI + 0x34]
    s.cx = m.r32((s.di+0x00000034u));
  }
  { // 0x4a4d34: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4a4d35: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4a4d36: e88ea22c00 CALL 0x0076efc9
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x4a4d3b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4a4d3e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4a4d3f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4a4d40: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a4d41: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004a4d44: { // 0x4a4d44: 8b5734 MOV EDX,dword ptr [EDI + 0x34]
    s.dx = m.r32((s.di+0x00000034u));
  }
  { // 0x4a4d47: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4a4d48: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a4d49: 66c7020000 MOV word ptr [EDX],0x0
    m.w16((s.dx), 0x00000000u);
  }
  { // 0x4a4d4e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000a4e50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a4e50: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a4e51: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4a4e53: 8a4648 MOV AL,byte ptr [ESI + 0x48]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000048u)));
  }
  { // 0x4a4e56: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4a4e58: 754f JNZ 0x004a4ea9
    if(integer::condition("JNZ",flags)) goto L004a4ea9;
  }
  { // 0x4a4e5a: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x4a4e5d: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x4a4e60: 8b5614 MOV EDX,dword ptr [ESI + 0x14]
    s.dx = m.r32((s.si+0x00000014u));
  }
  { // 0x4a4e63: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4a4e64: 8b9eb0000000 MOV EBX,dword ptr [ESI + 0xb0]
    s.bx = m.r32((s.si+0x000000b0u));
  }
  { // 0x4a4e6a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a4e6b: 83c112 ADD ECX,0x12
    s.cx = integer::add(s.cx,0x00000012u,32,flags);
  }
  { // 0x4a4e6e: 8986bc000000 MOV dword ptr [ESI + 0xbc],EAX
    m.w32((s.si+0x000000bcu), s.ax);
  }
  { // 0x4a4e74: 8b464c MOV EAX,dword ptr [ESI + 0x4c]
    s.ax = m.r32((s.si+0x0000004cu));
  }
  { // 0x4a4e77: 8996c4000000 MOV dword ptr [ESI + 0xc4],EDX
    m.w32((s.si+0x000000c4u), s.dx);
  }
  { // 0x4a4e7d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4a4e7f: 8dbeb0000000 LEA EDI,[ESI + 0xb0]
    s.di = (s.si+0x000000b0u);
  }
  { // 0x4a4e85: 898ec0000000 MOV dword ptr [ESI + 0xc0],ECX
    m.w32((s.si+0x000000c0u), s.cx);
  }
  { // 0x4a4e8b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4a4e8d: 8986c8000000 MOV dword ptr [ESI + 0xc8],EAX
    m.w32((s.si+0x000000c8u), s.ax);
  }
  { // 0x4a4e93: ff5218 CALL dword ptr [EDX + 0x18]
    const std::uint32_t call_target=m.r32((s.dx+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4a4e96: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4a4e97: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4a4e99: ff530c CALL dword ptr [EBX + 0xc]
    const std::uint32_t call_target=m.r32((s.bx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4a4e9c: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x4a4e9e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4a4ea0: ff5048 CALL dword ptr [EAX + 0x48]
    const std::uint32_t call_target=m.r32((s.ax+0x00000048u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4a4ea3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4a4ea4: c6464801 MOV byte ptr [ESI + 0x48],0x1
    m.w8((s.si+0x00000048u), 0x00000001u);
  }
  { // 0x4a4ea8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004a4ea9: { // 0x4a4ea9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a4eaa: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000a51a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a51a0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4a51a1: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x4a51a5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a51a6: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a51a7: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x4a51ab: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4a51ad: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a51ae: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4a51af: e88ca00200 CALL 0x004cf240
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4a51b4: 8b96a8000000 MOV EDX,dword ptr [ESI + 0xa8]
    s.dx = m.r32((s.si+0x000000a8u));
  }
  { // 0x4a51ba: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  { // 0x4a51c0: 8d8eb0000000 LEA ECX,[ESI + 0xb0]
    s.cx = (s.si+0x000000b0u);
  }
  { // 0x4a51c6: 0fbf5204 MOVSX EDX,word ptr [EDX + 0x4]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000004u)),16));
  }
  { // 0x4a51ca: 03d7 ADD EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
  { // 0x4a51cc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4a51cd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4a51ce: ff5064 CALL dword ptr [EAX + 0x64]
    const std::uint32_t call_target=m.r32((s.ax+0x00000064u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4a51d1: 8b5614 MOV EDX,dword ptr [ESI + 0x14]
    s.dx = m.r32((s.si+0x00000014u));
  }
  { // 0x4a51d4: 8b4650 MOV EAX,dword ptr [ESI + 0x50]
    s.ax = m.r32((s.si+0x00000050u));
  }
  { // 0x4a51d7: 8d4e50 LEA ECX,[ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  { // 0x4a51da: 03d3 ADD EDX,EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  { // 0x4a51dc: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a51dd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4a51de: ff5064 CALL dword ptr [EAX + 0x64]
    const std::uint32_t call_target=m.r32((s.ax+0x00000064u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4a51e1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4a51e2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a51e3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4a51e4: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000a57a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a57a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a57a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4a57a3: c70658b97800 MOV dword ptr [ESI],0x78b958
    m.w32((s.si), 0x0078b958u);
  }
  { // 0x4a57a9: c7460490b87800 MOV dword ptr [ESI + 0x4],0x78b890
    m.w32((s.si+0x00000004u), 0x0078b890u);
  }
  { // 0x4a57b0: c746186cb87800 MOV dword ptr [ESI + 0x18],0x78b86c
    m.w32((s.si+0x00000018u), 0x0078b86cu);
  }
  { // 0x4a57b7: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  { // 0x4a57ba: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4a57bc: 7406 JZ 0x004a57c4
    if(integer::condition("JZ",flags)) goto L004a57c4;
  }
  { // 0x4a57be: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4a57c0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4a57c1: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004a57c4: { // 0x4a57c4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4a57c6: e8055a0900 CALL 0x0053b1d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4a57cb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a57cc: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000a6380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a6380: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a6381: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4a6383: c70658b97800 MOV dword ptr [ESI],0x78b958
    m.w32((s.si), 0x0078b958u);
  }
  { // 0x4a6389: c7460490b87800 MOV dword ptr [ESI + 0x4],0x78b890
    m.w32((s.si+0x00000004u), 0x0078b890u);
  }
  { // 0x4a6390: c746186cb87800 MOV dword ptr [ESI + 0x18],0x78b86c
    m.w32((s.si+0x00000018u), 0x0078b86cu);
  }
  { // 0x4a6397: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  { // 0x4a639a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4a639c: 7406 JZ 0x004a63a4
    if(integer::condition("JZ",flags)) goto L004a63a4;
  }
  { // 0x4a639e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4a63a0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4a63a1: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004a63a4: { // 0x4a63a4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4a63a6: e8254e0900 CALL 0x0053b1d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4a63ab: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x4a63b0: 7409 JZ 0x004a63bb
    if(integer::condition("JZ",flags)) goto L004a63bb;
  }
  { // 0x4a63b2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a63b3: e8c3722c00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4a63b8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004a63bb: { // 0x4a63bb: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4a63bd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a63be: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000aa2b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4aa2b0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4aa2b1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4aa2b2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4aa2b4: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x4aa2b6: 8a4618 MOV AL,byte ptr [ESI + 0x18]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000018u)));
  }
  { // 0x4aa2b9: c706e4bb7800 MOV dword ptr [ESI],0x78bbe4
    m.w32((s.si), 0x0078bbe4u);
  }
  { // 0x4aa2bf: 3ac3 CMP AL,BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  { // 0x4aa2c1: 7427 JZ 0x004aa2ea
    if(integer::condition("JZ",flags)) goto L004aa2ea;
  }
  { // 0x4aa2c3: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  { // 0x4aa2c6: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x4aa2c8: 7420 JZ 0x004aa2ea
    if(integer::condition("JZ",flags)) goto L004aa2ea;
  }
  { // 0x4aa2ca: 391de4b28300 CMP dword ptr [0x0083b2e4],EBX
    (void)integer::sub(m.r32((0x0083b2e4u)),s.bx,32,flags);
  }
  { // 0x4aa2d0: 7418 JZ 0x004aa2ea
    if(integer::condition("JZ",flags)) goto L004aa2ea;
  }
  { // 0x4aa2d2: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4aa2d4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4aa2d5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4aa2d6: ff5170 CALL dword ptr [ECX + 0x70]
    const std::uint32_t call_target=m.r32((s.cx+0x00000070u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4aa2d9: a1e4b28300 MOV EAX,[0x0083b2e4]
    s.ax = m.r32((0x0083b2e4u));
  }
  { // 0x4aa2de: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4aa2df: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x4aa2e1: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4aa2e4: 891de4b28300 MOV dword ptr [0x0083b2e4],EBX
    m.w32((0x0083b2e4u), s.bx);
  }
  L004aa2ea: { // 0x4aa2ea: 8b4620 MOV EAX,dword ptr [ESI + 0x20]
    s.ax = m.r32((s.si+0x00000020u));
  }
  { // 0x4aa2ed: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4aa2ee: e888332c00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4aa2f3: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  { // 0x4aa2f6: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4aa2f9: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x4aa2fb: 895e20 MOV dword ptr [ESI + 0x20],EBX
    m.w32((s.si+0x00000020u), s.bx);
  }
  { // 0x4aa2fe: 7406 JZ 0x004aa306
    if(integer::condition("JZ",flags)) goto L004aa306;
  }
  { // 0x4aa300: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4aa302: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4aa303: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L004aa306: { // 0x4aa306: 895e1c MOV dword ptr [ESI + 0x1c],EBX
    m.w32((s.si+0x0000001cu), s.bx);
  }
  { // 0x4aa309: c70620607800 MOV dword ptr [ESI],0x786020
    m.w32((s.si), 0x00786020u);
  }
  { // 0x4aa30f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4aa310: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4aa311: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000aac10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4aac10: a0e09f8300 MOV AL,[0x00839fe0]
    s.ax = with_al(s.ax, m.r8((0x00839fe0u)));
  }
  { // 0x4aac15: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4aac16: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4aac18: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4aac19: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4aac1b: 750e JNZ 0x004aac2b
    if(integer::condition("JNZ",flags)) goto L004aac2b;
  }
  { // 0x4aac1d: a06889a200 MOV AL,[0x00a28968]
    s.ax = with_al(s.ax, m.r8((0x00a28968u)));
  }
  { // 0x4aac22: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4aac24: 7505 JNZ 0x004aac2b
    if(integer::condition("JNZ",flags)) goto L004aac2b;
  }
  L004aac26: { // 0x4aac26: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4aac27: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4aac29: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4aac2a: c3 RET
    finish(m,s,f,0u); return;
  }
  L004aac2b: { // 0x4aac2b: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  { // 0x4aac2e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4aac30: 744d JZ 0x004aac7f
    if(integer::condition("JZ",flags)) goto L004aac7f;
  }
  { // 0x4aac32: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4aac34: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4aac35: ff5160 CALL dword ptr [ECX + 0x60]
    const std::uint32_t call_target=m.r32((s.cx+0x00000060u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4aac38: 3dc2017688 CMP EAX,0x887601c2
    (void)integer::sub(s.ax,0x887601c2u,32,flags);
  }
  { // 0x4aac3d: 7540 JNZ 0x004aac7f
    if(integer::condition("JNZ",flags)) goto L004aac7f;
  }
  { // 0x4aac3f: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  { // 0x4aac42: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4aac43: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x4aac45: ff526c CALL dword ptr [EDX + 0x6c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000006cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4aac48: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4aac4a: 75da JNZ 0x004aac26
    if(integer::condition("JNZ",flags)) goto L004aac26;
  }
  { // 0x4aac4c: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  { // 0x4aac4f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4aac50: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4aac52: ff5160 CALL dword ptr [ECX + 0x60]
    const std::uint32_t call_target=m.r32((s.cx+0x00000060u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4aac55: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4aac57: 75cd JNZ 0x004aac26
    if(integer::condition("JNZ",flags)) goto L004aac26;
  }
  { // 0x4aac59: 8b7e0c MOV EDI,dword ptr [ESI + 0xc]
    s.di = m.r32((s.si+0x0000000cu));
  }
  { // 0x4aac5c: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x4aac5e: 7e1f JLE 0x004aac7f
    if(integer::condition("JLE",flags)) goto L004aac7f;
  }
  { // 0x4aac60: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4aac62: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x4aac64: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4aac65: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4aac66: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4aac68: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  { // 0x4aac6b: ff525c CALL dword ptr [EDX + 0x5c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000005cu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4aac6e: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x4aac71: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4aac73: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x4aac74: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  { // 0x4aac77: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4aac79: ff5060 CALL dword ptr [EAX + 0x60]
    const std::uint32_t call_target=m.r32((s.ax+0x00000060u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x4aac7c: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L004aac7f: { // 0x4aac7f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4aac80: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4aac82: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4aac83: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000aac90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4aac90: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x4aac94: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x4aac97: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  { // 0x4aac9b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4aac9c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4aac9d: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4aac9f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4aaca0: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  { // 0x4aaca4: 8b7c2434 MOV EDI,dword ptr [ESP + 0x34]
    s.di = m.r32((f.sp+0x00000034u));
  }
  { // 0x4aaca8: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  { // 0x4aacaa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4aacab: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x4aacad: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4aacae: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  { // 0x4aacb2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4aacb3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4aacb4: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4aacb6: ff5078 CALL dword ptr [EAX + 0x78]
    const std::uint32_t call_target=m.r32((s.ax+0x00000078u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4aacb9: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  { // 0x4aacbd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4aacbe: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4aacc0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4aacc1: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  { // 0x4aacc5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4aacc6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4aacc7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4aacc9: ff5078 CALL dword ptr [EAX + 0x78]
    const std::uint32_t call_target=m.r32((s.ax+0x00000078u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4aaccc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4aaccd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4aaccf: ff530c CALL dword ptr [EBX + 0xc]
    const std::uint32_t call_target=m.r32((s.bx+0x0000000cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4aacd2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4aacd3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4aacd4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4aacd5: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x4aacd8: c21400 RET 0x14
    finish(m,s,f,20u); return;
  }
}
void f_000b1180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b1180: a114b38300 MOV EAX,[0x0083b314]
    s.ax = m.r32((0x0083b314u));
  }
  { // 0x4b1185: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b1187: 7410 JZ 0x004b1199
    if(integer::condition("JZ",flags)) goto L004b1199;
  }
  { // 0x4b1189: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4b118b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4b118c: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4b118f: c70514b3830000000000 MOV dword ptr [0x0083b314],0x0
    m.w32((0x0083b314u), 0x00000000u);
  }
  L004b1199: { // 0x4b1199: a110b38300 MOV EAX,[0x0083b310]
    s.ax = m.r32((0x0083b310u));
  }
  { // 0x4b119e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b11a0: 7410 JZ 0x004b11b2
    if(integer::condition("JZ",flags)) goto L004b11b2;
  }
  { // 0x4b11a2: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x4b11a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4b11a5: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4b11a8: c70510b3830000000000 MOV dword ptr [0x0083b310],0x0
    m.w32((0x0083b310u), 0x00000000u);
  }
  L004b11b2: { // 0x4b11b2: a10cb38300 MOV EAX,[0x0083b30c]
    s.ax = m.r32((0x0083b30cu));
  }
  { // 0x4b11b7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b11b9: 7410 JZ 0x004b11cb
    if(integer::condition("JZ",flags)) goto L004b11cb;
  }
  { // 0x4b11bb: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4b11bd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4b11be: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4b11c1: c7050cb3830000000000 MOV dword ptr [0x0083b30c],0x0
    m.w32((0x0083b30cu), 0x00000000u);
  }
  L004b11cb: { // 0x4b11cb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000b4640(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b4640: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4b4641: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4b4643: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4b4644: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4b4648: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4b464a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4b464c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4b464d: e8bef6fdff CALL 0x00493d10
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4b4652: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x4b4655: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4b4657: 7422 JZ 0x004b467b
    if(integer::condition("JZ",flags)) goto L004b467b;
  }
  { // 0x4b4659: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x4b465b: ff522c CALL dword ptr [EDX + 0x2c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000002cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4b465e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4b465f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4b4661: e8aaf6fdff CALL 0x00493d10
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4b4666: 8b7604 MOV ESI,dword ptr [ESI + 0x4]
    s.si = m.r32((s.si+0x00000004u));
  }
  { // 0x4b4669: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x4b466c: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  { // 0x4b466f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4b4670: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4b4673: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4b4674: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4b4676: e895f6fdff CALL 0x00493d10
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L004b467b: { // 0x4b467b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4b467c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b467d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000b99e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b99e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4b99e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4b99e3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4b99e4: 8b464c MOV EAX,dword ptr [ESI + 0x4c]
    s.ax = m.r32((s.si+0x0000004cu));
  }
  { // 0x4b99e7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b99e9: 7464 JZ 0x004b9a4f
    if(integer::condition("JZ",flags)) goto L004b9a4f;
  }
  { // 0x4b99eb: 8b4654 MOV EAX,dword ptr [ESI + 0x54]
    s.ax = m.r32((s.si+0x00000054u));
  }
  { // 0x4b99ee: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b99f0: 755d JNZ 0x004b9a4f
    if(integer::condition("JNZ",flags)) goto L004b9a4f;
  }
  { // 0x4b99f2: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  { // 0x4b99f5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b99f7: 7407 JZ 0x004b9a00
    if(integer::condition("JZ",flags)) goto L004b9a00;
  }
  { // 0x4b99f9: 8a466c MOV AL,byte ptr [ESI + 0x6c]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000006cu)));
  }
  { // 0x4b99fc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4b99fe: 744f JZ 0x004b9a4f
    if(integer::condition("JZ",flags)) goto L004b9a4f;
  }
  L004b9a00: { // 0x4b9a00: 8b4640 MOV EAX,dword ptr [ESI + 0x40]
    s.ax = m.r32((s.si+0x00000040u));
  }
  { // 0x4b9a03: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  { // 0x4b9a05: 8b464c MOV EAX,dword ptr [ESI + 0x4c]
    s.ax = m.r32((s.si+0x0000004cu));
  }
  { // 0x4b9a08: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b9a0a: 7e1e JLE 0x004b9a2a
    if(integer::condition("JLE",flags)) goto L004b9a2a;
  }
  { // 0x4b9a0c: 8d48ff LEA ECX,[EAX + -0x1]
    s.cx = (s.ax-0x00000001u);
  }
  { // 0x4b9a0f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4b9a11: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4b9a13: 894e4c MOV dword ptr [ESI + 0x4c],ECX
    m.w32((s.si+0x0000004cu), s.cx);
  }
  { // 0x4b9a16: 7e12 JLE 0x004b9a2a
    if(integer::condition("JLE",flags)) goto L004b9a2a;
  }
  L004b9a18: { // 0x4b9a18: 8b4e40 MOV ECX,dword ptr [ESI + 0x40]
    s.cx = m.r32((s.si+0x00000040u));
  }
  { // 0x4b9a1b: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x4b9a1c: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x4b9a1f: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  { // 0x4b9a23: 8b4e4c MOV ECX,dword ptr [ESI + 0x4c]
    s.cx = m.r32((s.si+0x0000004cu));
  }
  { // 0x4b9a26: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4b9a28: 7cee JL 0x004b9a18
    if(integer::condition("JL",flags)) goto L004b9a18;
  }
  L004b9a2a: { // 0x4b9a2a: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x4b9a2c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4b9a2e: ff5040 CALL dword ptr [EAX + 0x40]
    const std::uint32_t call_target=m.r32((s.ax+0x00000040u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4b9a31: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b9a33: 7c1a JL 0x004b9a4f
    if(integer::condition("JL",flags)) goto L004b9a4f;
  }
  { // 0x4b9a35: 8a8fda0a0000 MOV CL,byte ptr [EDI + 0xada]
    s.cx = with_al(s.cx, m.r8((s.di+0x00000adau)));
  }
  { // 0x4b9a3b: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  { // 0x4b9a3d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4b9a3f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4b9a40: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4b9a41: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4b9a43: ff522c CALL dword ptr [EDX + 0x2c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000002cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4b9a46: 8b4e68 MOV ECX,dword ptr [ESI + 0x68]
    s.cx = m.r32((s.si+0x00000068u));
  }
  { // 0x4b9a49: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4b9a4a: e881ba0200 CALL 0x004e54d0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L004b9a4f: { // 0x4b9a4f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4b9a50: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b9a51: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000bbe00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4bbe00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4bbe01: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x4bbe05: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bbe06: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4bbe07: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x4bbe0b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4bbe0c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4bbe0d: e8def30700 CALL 0x0053b1f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4bbe12: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4bbe14: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4bbe16: 7530 JNZ 0x004bbe48
    if(integer::condition("JNZ",flags)) goto L004bbe48;
  }
  { // 0x4bbe18: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x4bbe1a: 7428 JZ 0x004bbe44
    if(integer::condition("JZ",flags)) goto L004bbe44;
  }
  { // 0x4bbe1c: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x4bbe1e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4bbe20: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4bbe23: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x4bbe26: 751c JNZ 0x004bbe44
    if(integer::condition("JNZ",flags)) goto L004bbe44;
  }
  { // 0x4bbe28: 8b8fac050000 MOV ECX,dword ptr [EDI + 0x5ac]
    s.cx = m.r32((s.di+0x000005acu));
  }
  { // 0x4bbe2e: 8a81a30b0000 MOV AL,byte ptr [ECX + 0xba3]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000ba3u)));
  }
  { // 0x4bbe34: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4bbe36: 740c JZ 0x004bbe44
    if(integer::condition("JZ",flags)) goto L004bbe44;
  }
  { // 0x4bbe38: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4bbe3a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4bbe3b: c6431401 MOV byte ptr [EBX + 0x14],0x1
    m.w8((s.bx+0x00000014u), 0x00000001u);
  }
  { // 0x4bbe3f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bbe40: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4bbe41: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L004bbe44: { // 0x4bbe44: c6431400 MOV byte ptr [EBX + 0x14],0x0
    m.w8((s.bx+0x00000014u), 0x00000000u);
  }
  L004bbe48: { // 0x4bbe48: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4bbe4a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4bbe4b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bbe4c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4bbe4d: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000bf110(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4bf110: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bf111: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x4bf115: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bf116: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4bf118: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4bf11b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4bf11d: 744b JZ 0x004bf16a
    if(integer::condition("JZ",flags)) goto L004bf16a;
  }
  { // 0x4bf11f: c6464f01 MOV byte ptr [ESI + 0x4f],0x1
    m.w8((s.si+0x0000004fu), 0x00000001u);
  }
  { // 0x4bf123: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  { // 0x4bf129: 6a1e PUSH 0x1e
    f.push(m,0x0000001eu);
  }
  { // 0x4bf12b: 6a14 PUSH 0x14
    f.push(m,0x00000014u);
  }
  { // 0x4bf12d: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  { // 0x4bf133: e8080d1700 CALL 0x0062fe40
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4bf138: 894650 MOV dword ptr [ESI + 0x50],EAX
    m.w32((s.si+0x00000050u), s.ax);
  }
  { // 0x4bf13b: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  { // 0x4bf141: 6a63 PUSH 0x63
    f.push(m,0x00000063u);
  }
  { // 0x4bf143: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4bf145: 8d8a18020000 LEA ECX,[EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  { // 0x4bf14b: e8f00c1700 CALL 0x0062fe40
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4bf150: 83f832 CMP EAX,0x32
    (void)integer::sub(s.ax,0x00000032u,32,flags);
  }
  { // 0x4bf153: 7d08 JGE 0x004bf15d
    if(integer::condition("JGE",flags)) goto L004bf15d;
  }
  { // 0x4bf155: 8b4650 MOV EAX,dword ptr [ESI + 0x50]
    s.ax = m.r32((s.si+0x00000050u));
  }
  { // 0x4bf158: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x4bf15a: 894650 MOV dword ptr [ESI + 0x50],EAX
    m.w32((s.si+0x00000050u), s.ax);
  }
  L004bf15d: { // 0x4bf15d: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x4bf15f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bf160: ff5148 CALL dword ptr [ECX + 0x48]
    const std::uint32_t call_target=m.r32((s.cx+0x00000048u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4bf163: c7465400000000 MOV dword ptr [ESI + 0x54],0x0
    m.w32((s.si+0x00000054u), 0x00000000u);
  }
  L004bf16a: { // 0x4bf16a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bf16b: e880c20700 CALL 0x0053b3f0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x4bf170: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bf171: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000bf890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4bf890: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4bf894: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bf895: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4bf896: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4bf898: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x4bf89a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4bf89c: 7449 JZ 0x004bf8e7
    if(integer::condition("JZ",flags)) goto L004bf8e7;
  }
  { // 0x4bf89e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4bf8a0: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x4bf8a4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4bf8a5: 6898317c00 PUSH 0x7c3198
    f.push(m,0x007c3198u);
  }
  { // 0x4bf8aa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4bf8ab: ff11 CALL dword ptr [ECX]
    const std::uint32_t call_target=m.r32((s.cx));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4bf8ad: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x4bf8af: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x4bf8b1: 7d19 JGE 0x004bf8cc
    if(integer::condition("JGE",flags)) goto L004bf8cc;
  }
  { // 0x4bf8b3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4bf8b5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4bf8b7: 7406 JZ 0x004bf8bf
    if(integer::condition("JZ",flags)) goto L004bf8bf;
  }
  { // 0x4bf8b9: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4bf8bb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4bf8bc: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L004bf8bf: { // 0x4bf8bf: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x4bf8c1: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x4bf8c7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4bf8c8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bf8c9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004bf8cc: { // 0x4bf8cc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4bf8ce: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4bf8cf: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  { // 0x4bf8d3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4bf8d5: 7406 JZ 0x004bf8dd
    if(integer::condition("JZ",flags)) goto L004bf8dd;
  }
  { // 0x4bf8d7: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x4bf8d9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4bf8da: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L004bf8dd: { // 0x4bf8dd: 891e MOV dword ptr [ESI],EBX
    m.w32((s.si), s.bx);
  }
  { // 0x4bf8df: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4bf8e0: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x4bf8e2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4bf8e3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bf8e4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004bf8e7: { // 0x4bf8e7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4bf8e9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4bf8eb: 740c JZ 0x004bf8f9
    if(integer::condition("JZ",flags)) goto L004bf8f9;
  }
  { // 0x4bf8ed: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x4bf8f3: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4bf8f5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4bf8f6: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L004bf8f9: { // 0x4bf8f9: bf02400080 MOV EDI,0x80004002
    s.di = 0x80004002u;
  }
  { // 0x4bf8fe: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x4bf900: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4bf901: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bf902: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000c47d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c47d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c47d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4c47d3: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x4c47d9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c47db: 750a JNZ 0x004c47e7
    if(integer::condition("JNZ",flags)) goto L004c47e7;
  }
  { // 0x4c47dd: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x4c47e2: e889ca2b00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004c47e7: { // 0x4c47e7: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x4c47ed: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4c47ee: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4c47f0: ff5148 CALL dword ptr [ECX + 0x48]
    const std::uint32_t call_target=m.r32((s.cx+0x00000048u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4c47f3: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4c47f5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c47f6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000c4800(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c4800: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4c4804: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4c4805: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x4c4806: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c4807: 8b5804 MOV EBX,dword ptr [EAX + 0x4]
    s.bx = m.r32((s.ax+0x00000004u));
  }
  { // 0x4c480a: 8b6808 MOV EBP,dword ptr [EAX + 0x8]
    s.bp = m.r32((s.ax+0x00000008u));
  }
  { // 0x4c480d: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4c480f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4c4810: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  { // 0x4c4812: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x4c4818: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c481a: 750a JNZ 0x004c4826
    if(integer::condition("JNZ",flags)) goto L004c4826;
  }
  { // 0x4c481c: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x4c4821: e84aca2b00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004c4826: { // 0x4c4826: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x4c482c: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x4c482f: 8bd4 MOV EDX,ESP
    s.dx = f.sp;
  }
  { // 0x4c4831: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4c4833: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4c4834: 893a MOV dword ptr [EDX],EDI
    m.w32((s.dx), s.di);
  }
  { // 0x4c4836: 895a04 MOV dword ptr [EDX + 0x4],EBX
    m.w32((s.dx+0x00000004u), s.bx);
  }
  { // 0x4c4839: 896a08 MOV dword ptr [EDX + 0x8],EBP
    m.w32((s.dx+0x00000008u), s.bp);
  }
  { // 0x4c483c: ff5144 CALL dword ptr [ECX + 0x44]
    const std::uint32_t call_target=m.r32((s.cx+0x00000044u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4c483f: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x4c4845: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c4847: 750a JNZ 0x004c4853
    if(integer::condition("JNZ",flags)) goto L004c4853;
  }
  { // 0x4c4849: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x4c484e: e81dca2b00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L004c4853: { // 0x4c4853: 8bb664050000 MOV ESI,dword ptr [ESI + 0x564]
    s.si = m.r32((s.si+0x00000564u));
  }
  { // 0x4c4859: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c485a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4c485c: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4c485f: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  { // 0x4c4861: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4c4862: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c4863: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x4c4865: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4c4866: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x4c4868: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4c4869: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000c4870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c4870: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c4871: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4c4873: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4c4875: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4c4877: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4c4879: ff9010040000 CALL dword ptr [EAX + 0x410]
    const std::uint32_t call_target=m.r32((s.ax+0x00000410u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4c487f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4c4881: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c4883: c786d0040000ffffffff MOV dword ptr [ESI + 0x4d0],0xffffffff
    m.w32((s.si+0x000004d0u), 0xffffffffu);
  }
  { // 0x4c488d: ff928c040000 CALL dword ptr [EDX + 0x48c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000048cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4c4893: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c4895: e8c6a71f00 CALL 0x006bf060
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4c489a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c489b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000c76a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c76a0: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x4c76a4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c76a5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4c76a6: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x4c76aa: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4c76ac: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4c76ad: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x4c76b1: 8b8694040000 MOV EAX,dword ptr [ESI + 0x494]
    s.ax = m.r32((s.si+0x00000494u));
  }
  { // 0x4c76b7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4c76b8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4c76b9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c76bb: 898698040000 MOV dword ptr [ESI + 0x498],EAX
    m.w32((s.si+0x00000498u), s.ax);
  }
  { // 0x4c76c1: e8eab61f00 CALL 0x006c2db0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4c76c6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4c76c8: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4c76ca: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4c76cb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c76cd: ff9010040000 CALL dword ptr [EAX + 0x410]
    const std::uint32_t call_target=m.r32((s.ax+0x00000410u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4c76d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4c76d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c76d5: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_000c76e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c76e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c76e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4c76e3: e808b71f00 CALL 0x006c2df0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4c76e8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4c76ea: 7417 JZ 0x004c7703
    if(integer::condition("JZ",flags)) goto L004c7703;
  }
  { // 0x4c76ec: 8b8e98040000 MOV ECX,dword ptr [ESI + 0x498]
    s.cx = m.r32((s.si+0x00000498u));
  }
  { // 0x4c76f2: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4c76f4: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4c76f6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4c76f7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c76f9: ff9010040000 CALL dword ptr [EAX + 0x410]
    const std::uint32_t call_target=m.r32((s.ax+0x00000410u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4c76ff: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4c7701: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c7702: c3 RET
    finish(m,s,f,0u); return;
  }
  L004c7703: { // 0x4c7703: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4c7705: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c7706: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000c7e00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c7e00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4c7e01: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x4c7e05: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c7e06: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4c7e08: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x4c7e0a: 7436 JZ 0x004c7e42
    if(integer::condition("JZ",flags)) goto L004c7e42;
  }
  { // 0x4c7e0c: 8b8ec4040000 MOV ECX,dword ptr [ESI + 0x4c4]
    s.cx = m.r32((s.si+0x000004c4u));
  }
  { // 0x4c7e12: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4c7e14: 7413 JZ 0x004c7e29
    if(integer::condition("JZ",flags)) goto L004c7e29;
  }
  { // 0x4c7e16: a1c483a200 MOV EAX,[0x00a283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  { // 0x4c7e1b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c7e1d: 750a JNZ 0x004c7e29
    if(integer::condition("JNZ",flags)) goto L004c7e29;
  }
  { // 0x4c7e1f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4c7e21: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x4c7e23: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c7e24: e8d7671e00 CALL 0x006ae600
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004c7e29: { // 0x4c7e29: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4c7e2b: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x4c7e2d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c7e2f: ff9254020000 CALL dword ptr [EDX + 0x254]
    const std::uint32_t call_target=m.r32((s.dx+0x00000254u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L004c7e35: { // 0x4c7e35: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4c7e36: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c7e38: e863441000 CALL 0x005cc2a0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4c7e3d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c7e3e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4c7e3f: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004c7e42: { // 0x4c7e42: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4c7e44: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c7e46: e865651600 CALL 0x0062e3b0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4c7e4b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c7e4d: 74e6 JZ 0x004c7e35
    if(integer::condition("JZ",flags)) goto L004c7e35;
  }
  { // 0x4c7e4f: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x4c7e55: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4c7e56: e8c5cd0100 CALL 0x004e4c20
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x4c7e5b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4c7e5d: 75d6 JNZ 0x004c7e35
    if(integer::condition("JNZ",flags)) goto L004c7e35;
  }
  { // 0x4c7e5f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4c7e61: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  { // 0x4c7e63: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c7e65: ff9054020000 CALL dword ptr [EAX + 0x254]
    const std::uint32_t call_target=m.r32((s.ax+0x00000254u));
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x4c7e6b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4c7e6c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c7e6e: e82d441000 CALL 0x005cc2a0
    const std::uint32_t call_target=f.boundaries[6u].target;
    invoke(m,s,f,op,6u,call_target); flags=0x202u;
  }
  { // 0x4c7e73: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c7e74: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4c7e75: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000c82e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c82e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c82e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4c82e3: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x4c82e9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c82eb: 7436 JZ 0x004c8323
    if(integer::condition("JZ",flags)) goto L004c8323;
  }
  { // 0x4c82ed: 8a442418 MOV AL,byte ptr [ESP + 0x18]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000018u)));
  }
  { // 0x4c82f1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4c82f3: 742e JZ 0x004c8323
    if(integer::condition("JZ",flags)) goto L004c8323;
  }
  { // 0x4c82f5: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x4c82f9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4c82fa: 8b7824 MOV EDI,dword ptr [EAX + 0x24]
    s.di = m.r32((s.ax+0x00000024u));
  }
  { // 0x4c82fd: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x4c8303: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c8305: 750a JNZ 0x004c8311
    if(integer::condition("JNZ",flags)) goto L004c8311;
  }
  { // 0x4c8307: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x4c830c: e85f8f2b00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004c8311: { // 0x4c8311: 8bb664050000 MOV ESI,dword ptr [ESI + 0x564]
    s.si = m.r32((s.si+0x00000564u));
  }
  { // 0x4c8317: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4c8318: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c8319: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x4c831b: ff511c CALL dword ptr [ECX + 0x1c]
    const std::uint32_t call_target=m.r32((s.cx+0x0000001cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4c831e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4c831f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c8320: c21400 RET 0x14
    finish(m,s,f,20u); return;
  }
  L004c8323: { // 0x4c8323: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4c8325: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c8326: c21400 RET 0x14
    finish(m,s,f,20u); return;
  }
}
void f_000c88a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c88a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c88a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4c88a3: 8a862d030000 MOV AL,byte ptr [ESI + 0x32d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000032du)));
  }
  { // 0x4c88a9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4c88ab: 7504 JNZ 0x004c88b1
    if(integer::condition("JNZ",flags)) goto L004c88b1;
  }
  { // 0x4c88ad: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4c88af: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c88b0: c3 RET
    finish(m,s,f,0u); return;
  }
  L004c88b1: { // 0x4c88b1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4c88b3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c88b5: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4c88bb: 8a88a00a0000 MOV CL,byte ptr [EAX + 0xaa0]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000aa0u)));
  }
  { // 0x4c88c1: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x4c88c3: 7530 JNZ 0x004c88f5
    if(integer::condition("JNZ",flags)) goto L004c88f5;
  }
  { // 0x4c88c5: 8a862c030000 MOV AL,byte ptr [ESI + 0x32c]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000032cu)));
  }
  { // 0x4c88cb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4c88cd: 7526 JNZ 0x004c88f5
    if(integer::condition("JNZ",flags)) goto L004c88f5;
  }
  { // 0x4c88cf: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4c88d1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c88d3: ff926c010000 CALL dword ptr [EDX + 0x16c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000016cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4c88d9: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  { // 0x4c88dc: 7417 JZ 0x004c88f5
    if(integer::condition("JZ",flags)) goto L004c88f5;
  }
  { // 0x4c88de: 8b8ec4040000 MOV ECX,dword ptr [ESI + 0x4c4]
    s.cx = m.r32((s.si+0x000004c4u));
  }
  { // 0x4c88e4: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4c88e6: 7409 JZ 0x004c88f1
    if(integer::condition("JZ",flags)) goto L004c88f1;
  }
  { // 0x4c88e8: e8f3761e00 CALL 0x006affe0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4c88ed: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4c88ef: 7504 JNZ 0x004c88f5
    if(integer::condition("JNZ",flags)) goto L004c88f5;
  }
  L004c88f1: { // 0x4c88f1: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4c88f3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c88f4: c3 RET
    finish(m,s,f,0u); return;
  }
  L004c88f5: { // 0x4c88f5: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4c88f7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c88f8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000c8900(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c8900: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4c8904: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c8905: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c8907: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4c8909: 740e JZ 0x004c8919
    if(integer::condition("JZ",flags)) goto L004c8919;
  }
  { // 0x4c890b: 3b86b4010000 CMP EAX,dword ptr [ESI + 0x1b4]
    (void)integer::sub(s.ax,m.r32((s.si+0x000001b4u)),32,flags);
  }
  { // 0x4c8911: 7406 JZ 0x004c8919
    if(integer::condition("JZ",flags)) goto L004c8919;
  }
  { // 0x4c8913: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4c8915: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c8916: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004c8919: { // 0x4c8919: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  { // 0x4c891c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4c891e: 7406 JZ 0x004c8926
    if(integer::condition("JZ",flags)) goto L004c8926;
  }
  { // 0x4c8920: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4c8922: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c8923: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004c8926: { // 0x4c8926: 8b86c4040000 MOV EAX,dword ptr [ESI + 0x4c4]
    s.ax = m.r32((s.si+0x000004c4u));
  }
  { // 0x4c892c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c892e: 7406 JZ 0x004c8936
    if(integer::condition("JZ",flags)) goto L004c8936;
  }
  { // 0x4c8930: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4c8932: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c8933: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004c8936: { // 0x4c8936: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4c8938: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c893a: ff906c010000 CALL dword ptr [EAX + 0x16c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000016cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4c8940: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x4c8942: e869920c00 CALL 0x00591bb0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4c8947: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4c8949: 7504 JNZ 0x004c894f
    if(integer::condition("JNZ",flags)) goto L004c894f;
  }
  { // 0x4c894b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c894c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004c894f: { // 0x4c894f: 8a8679030000 MOV AL,byte ptr [ESI + 0x379]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000379u)));
  }
  { // 0x4c8955: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c8956: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4c8958: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x4c895b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000c8ba0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c8ba0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c8ba1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4c8ba3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4c8ba4: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4c8ba8: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x4c8bae: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c8bb0: 741f JZ 0x004c8bd1
    if(integer::condition("JZ",flags)) goto L004c8bd1;
  }
  { // 0x4c8bb2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c8bb4: 750a JNZ 0x004c8bc0
    if(integer::condition("JNZ",flags)) goto L004c8bc0;
  }
  { // 0x4c8bb6: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x4c8bbb: e8b0862b00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004c8bc0: { // 0x4c8bc0: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x4c8bc6: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4c8bc7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4c8bc8: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4c8bca: ff5134 CALL dword ptr [ECX + 0x34]
    const std::uint32_t call_target=m.r32((s.cx+0x00000034u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4c8bcd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c8bcf: 750d JNZ 0x004c8bde
    if(integer::condition("JNZ",flags)) goto L004c8bde;
  }
  L004c8bd1: { // 0x4c8bd1: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x4c8bd5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c8bd7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4c8bd8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4c8bd9: e852bd1f00 CALL 0x006c4930
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L004c8bde: { // 0x4c8bde: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4c8bdf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c8be0: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000c9610(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c9610: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c9611: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4c9613: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x4c9619: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c961b: 741c JZ 0x004c9639
    if(integer::condition("JZ",flags)) goto L004c9639;
  }
  { // 0x4c961d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c961f: 750a JNZ 0x004c962b
    if(integer::condition("JNZ",flags)) goto L004c962b;
  }
  { // 0x4c9621: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x4c9626: e8457c2b00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004c962b: { // 0x4c962b: 8bb664050000 MOV ESI,dword ptr [ESI + 0x564]
    s.si = m.r32((s.si+0x00000564u));
  }
  { // 0x4c9631: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c9632: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4c9634: ff503c CALL dword ptr [EAX + 0x3c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000003cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4c9637: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c9638: c3 RET
    finish(m,s,f,0u); return;
  }
  L004c9639: { // 0x4c9639: b802000000 MOV EAX,0x2
    s.ax = 0x00000002u;
  }
  { // 0x4c963e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c963f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000c9d30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c9d30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c9d31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4c9d33: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x4c9d39: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c9d3b: 750a JNZ 0x004c9d47
    if(integer::condition("JNZ",flags)) goto L004c9d47;
  }
  { // 0x4c9d3d: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x4c9d42: e829752b00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004c9d47: { // 0x4c9d47: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x4c9d4d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4c9d4e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4c9d50: ff5174 CALL dword ptr [ECX + 0x74]
    const std::uint32_t call_target=m.r32((s.cx+0x00000074u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4c9d53: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c9d54: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000c9d60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c9d60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c9d61: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4c9d63: 8a4674 MOV AL,byte ptr [ESI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000074u)));
  }
  { // 0x4c9d66: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4c9d68: 7426 JZ 0x004c9d90
    if(integer::condition("JZ",flags)) goto L004c9d90;
  }
  { // 0x4c9d6a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4c9d6c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4c9d6e: ff901c010000 CALL dword ptr [EAX + 0x11c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000011cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4c9d74: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x4c9d78: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4c9d79: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c9d7b: e8d03a1000 CALL 0x005cd850
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4c9d80: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4c9d82: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4c9d84: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c9d86: ff921c010000 CALL dword ptr [EDX + 0x11c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000011cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4c9d8c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c9d8d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004c9d90: { // 0x4c9d90: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x4c9d94: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c9d96: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4c9d97: e8b43a1000 CALL 0x005cd850
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4c9d9c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c9d9d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000ca2a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ca2a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4ca2a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4ca2a3: e8a8202000 CALL 0x006cc350
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4ca2a8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4ca2aa: 743f JZ 0x004ca2eb
    if(integer::condition("JZ",flags)) goto L004ca2eb;
  }
  { // 0x4ca2ac: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4ca2ae: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4ca2b0: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4ca2b6: 8a889f0a0000 MOV CL,byte ptr [EAX + 0xa9f]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000a9fu)));
  }
  { // 0x4ca2bc: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x4ca2be: 7427 JZ 0x004ca2e7
    if(integer::condition("JZ",flags)) goto L004ca2e7;
  }
  { // 0x4ca2c0: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x4ca2c6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4ca2c8: 750a JNZ 0x004ca2d4
    if(integer::condition("JNZ",flags)) goto L004ca2d4;
  }
  { // 0x4ca2ca: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x4ca2cf: e89c6f2b00 CALL 0x00781270
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L004ca2d4: { // 0x4ca2d4: 8bb664050000 MOV ESI,dword ptr [ESI + 0x564]
    s.si = m.r32((s.si+0x00000564u));
  }
  { // 0x4ca2da: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4ca2db: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x4ca2dd: ff9180000000 CALL dword ptr [ECX + 0x80]
    const std::uint32_t call_target=m.r32((s.cx+0x00000080u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4ca2e3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4ca2e5: 7504 JNZ 0x004ca2eb
    if(integer::condition("JNZ",flags)) goto L004ca2eb;
  }
  L004ca2e7: { // 0x4ca2e7: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4ca2e9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4ca2ea: c3 RET
    finish(m,s,f,0u); return;
  }
  L004ca2eb: { // 0x4ca2eb: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4ca2ed: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4ca2ee: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000ca3d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ca3d0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4ca3d4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4ca3d5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4ca3d7: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4ca3d9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4ca3da: e8d18a1f00 CALL 0x006c2eb0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4ca3df: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4ca3e1: 7428 JZ 0x004ca40b
    if(integer::condition("JZ",flags)) goto L004ca40b;
  }
  { // 0x4ca3e3: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4ca3e5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4ca3e7: ff5254 CALL dword ptr [EDX + 0x54]
    const std::uint32_t call_target=m.r32((s.dx+0x00000054u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4ca3ea: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4ca3ec: 7517 JNZ 0x004ca405
    if(integer::condition("JNZ",flags)) goto L004ca405;
  }
  { // 0x4ca3ee: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4ca3f0: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x4ca3f4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4ca3f5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4ca3f7: ff90a0010000 CALL dword ptr [EAX + 0x1a0]
    const std::uint32_t call_target=m.r32((s.ax+0x000001a0u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4ca3fd: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x4ca3ff: 899654040000 MOV dword ptr [ESI + 0x454],EDX
    m.w32((s.si+0x00000454u), s.dx);
  }
  L004ca405: { // 0x4ca405: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4ca407: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4ca408: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L004ca40b: { // 0x4ca40b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4ca40d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4ca40e: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000ca420(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ca420: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4ca421: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4ca423: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4ca425: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4ca427: ff909c030000 CALL dword ptr [EAX + 0x39c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000039cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4ca42d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4ca42f: 7504 JNZ 0x004ca435
    if(integer::condition("JNZ",flags)) goto L004ca435;
  }
  { // 0x4ca431: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4ca433: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4ca434: c3 RET
    finish(m,s,f,0u); return;
  }
  L004ca435: { // 0x4ca435: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4ca437: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4ca439: ff9280000000 CALL dword ptr [EDX + 0x80]
    const std::uint32_t call_target=m.r32((s.dx+0x00000080u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4ca43f: 83b85c050000ff CMP dword ptr [EAX + 0x55c],-0x1
    (void)integer::sub(m.r32((s.ax+0x0000055cu)),0xffffffffu,32,flags);
  }
  { // 0x4ca446: 7504 JNZ 0x004ca44c
    if(integer::condition("JNZ",flags)) goto L004ca44c;
  }
  { // 0x4ca448: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4ca44a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4ca44b: c3 RET
    finish(m,s,f,0u); return;
  }
  L004ca44c: { // 0x4ca44c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4ca44e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4ca450: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4ca456: 8b88c8030000 MOV ECX,dword ptr [EAX + 0x3c8]
    s.cx = m.r32((s.ax+0x000003c8u));
  }
  { // 0x4ca45c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4ca45e: 7404 JZ 0x004ca464
    if(integer::condition("JZ",flags)) goto L004ca464;
  }
  { // 0x4ca460: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4ca462: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4ca463: c3 RET
    finish(m,s,f,0u); return;
  }
  L004ca464: { // 0x4ca464: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4ca466: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4ca468: ff9280000000 CALL dword ptr [EDX + 0x80]
    const std::uint32_t call_target=m.r32((s.dx+0x00000080u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4ca46e: 8b88a0050000 MOV ECX,dword ptr [EAX + 0x5a0]
    s.cx = m.r32((s.ax+0x000005a0u));
  }
  { // 0x4ca474: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4ca475: 83f90d CMP ECX,0xd
    (void)integer::sub(s.cx,0x0000000du,32,flags);
  }
  { // 0x4ca478: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  { // 0x4ca47b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000ca480(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ca480: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4ca481: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4ca483: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4ca485: ff906c010000 CALL dword ptr [EAX + 0x16c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000016cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4ca48b: 83f80f CMP EAX,0xf
    (void)integer::sub(s.ax,0x0000000fu,32,flags);
  }
  { // 0x4ca48e: 751a JNZ 0x004ca4aa
    if(integer::condition("JNZ",flags)) goto L004ca4aa;
  }
  { // 0x4ca490: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4ca492: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4ca494: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4ca496: ff9270030000 CALL dword ptr [EDX + 0x370]
    const std::uint32_t call_target=m.r32((s.dx+0x00000370u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4ca49c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4ca49e: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4ca4a0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4ca4a2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4ca4a4: ff9010040000 CALL dword ptr [EAX + 0x410]
    const std::uint32_t call_target=m.r32((s.ax+0x00000410u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L004ca4aa: { // 0x4ca4aa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4ca4ab: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000cd7e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4cd7e0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4cd7e1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4cd7e2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4cd7e4: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  { // 0x4cd7e6: 8b86b8040000 MOV EAX,dword ptr [ESI + 0x4b8]
    s.ax = m.r32((s.si+0x000004b8u));
  }
  { // 0x4cd7ec: c686c104000000 MOV byte ptr [ESI + 0x4c1],0x0
    m.w8((s.si+0x000004c1u), 0x00000000u);
  }
  { // 0x4cd7f3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4cd7f5: 7424 JZ 0x004cd81b
    if(integer::condition("JZ",flags)) goto L004cd81b;
  }
  { // 0x4cd7f7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4cd7f9: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4cd7fb: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x4cd7fd: ff90d0010000 CALL dword ptr [EAX + 0x1d0]
    const std::uint32_t call_target=m.r32((s.ax+0x000001d0u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4cd803: 8b86b8040000 MOV EAX,dword ptr [ESI + 0x4b8]
    s.ax = m.r32((s.si+0x000004b8u));
  }
  { // 0x4cd809: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4cd80b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4cd80d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4cd80e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4cd810: ff9210040000 CALL dword ptr [EDX + 0x410]
    const std::uint32_t call_target=m.r32((s.dx+0x00000410u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4cd816: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  { // 0x4cd818: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4cd819: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4cd81a: c3 RET
    finish(m,s,f,0u); return;
  }
  L004cd81b: { // 0x4cd81b: 8b86bc040000 MOV EAX,dword ptr [ESI + 0x4bc]
    s.ax = m.r32((s.si+0x000004bcu));
  }
  { // 0x4cd821: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4cd823: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4cd825: 7422 JZ 0x004cd849
    if(integer::condition("JZ",flags)) goto L004cd849;
  }
  { // 0x4cd827: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4cd829: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4cd82b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4cd82d: ff92d0010000 CALL dword ptr [EDX + 0x1d0]
    const std::uint32_t call_target=m.r32((s.dx+0x000001d0u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4cd833: 8b8ebc040000 MOV ECX,dword ptr [ESI + 0x4bc]
    s.cx = m.r32((s.si+0x000004bcu));
  }
  { // 0x4cd839: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4cd83b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4cd83c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4cd83e: ff9070030000 CALL dword ptr [EAX + 0x370]
    const std::uint32_t call_target=m.r32((s.ax+0x00000370u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4cd844: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  { // 0x4cd846: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4cd847: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4cd848: c3 RET
    finish(m,s,f,0u); return;
  }
  L004cd849: { // 0x4cd849: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4cd84b: ff9234040000 CALL dword ptr [EDX + 0x434]
    const std::uint32_t call_target=m.r32((s.dx+0x00000434u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x4cd851: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4cd852: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4cd854: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4cd855: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000cd970(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4cd970: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4cd971: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4cd973: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4cd975: 83beb40400001d CMP dword ptr [ESI + 0x4b4],0x1d
    (void)integer::sub(m.r32((s.si+0x000004b4u)),0x0000001du,32,flags);
  }
  { // 0x4cd97c: 751b JNZ 0x004cd999
    if(integer::condition("JNZ",flags)) goto L004cd999;
  }
  { // 0x4cd97e: 8a86c1040000 MOV AL,byte ptr [ESI + 0x4c1]
    s.ax = with_al(s.ax, m.r8((s.si+0x000004c1u)));
  }
  { // 0x4cd984: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4cd986: 7413 JZ 0x004cd99b
    if(integer::condition("JZ",flags)) goto L004cd99b;
  }
  { // 0x4cd988: c686c104000000 MOV byte ptr [ESI + 0x4c1],0x0
    m.w8((s.si+0x000004c1u), 0x00000000u);
  }
  L004cd98f: { // 0x4cd98f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4cd991: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4cd993: ff9054040000 CALL dword ptr [EAX + 0x454]
    const std::uint32_t call_target=m.r32((s.ax+0x00000454u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004cd999: { // 0x4cd999: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4cd99a: c3 RET
    finish(m,s,f,0u); return;
  }
  L004cd99b: { // 0x4cd99b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4cd99d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4cd99f: ff926c010000 CALL dword ptr [EDX + 0x16c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000016cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4cd9a5: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  { // 0x4cd9a8: 74e5 JZ 0x004cd98f
    if(integer::condition("JZ",flags)) goto L004cd98f;
  }
  { // 0x4cd9aa: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4cd9ac: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4cd9ae: ff906c010000 CALL dword ptr [EAX + 0x16c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000016cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4cd9b4: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  { // 0x4cd9b7: 74d6 JZ 0x004cd98f
    if(integer::condition("JZ",flags)) goto L004cd98f;
  }
  { // 0x4cd9b9: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4cd9bb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4cd9bd: ff9234040000 CALL dword ptr [EDX + 0x434]
    const std::uint32_t call_target=m.r32((s.dx+0x00000434u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4cd9c3: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4cd9c5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4cd9c6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000ced50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ced50: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4ced51: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4ced53: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4ced55: ff5054 CALL dword ptr [EAX + 0x54]
    const std::uint32_t call_target=m.r32((s.ax+0x00000054u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4ced58: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4ced5a: e891850600 CALL 0x005372f0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4ced5f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4ced60: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000cf1c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4cf1c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4cf1c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4cf1c3: 8b0d28e38400 MOV ECX,dword ptr [0x0084e328]
    s.cx = m.r32((0x0084e328u));
  }
  { // 0x4cf1c9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4cf1cb: 7410 JZ 0x004cf1dd
    if(integer::condition("JZ",flags)) goto L004cf1dd;
  }
  { // 0x4cf1cd: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x4cf1cf: ff5048 CALL dword ptr [EAX + 0x48]
    const std::uint32_t call_target=m.r32((s.ax+0x00000048u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4cf1d2: 8b0d28e38400 MOV ECX,dword ptr [0x0084e328]
    s.cx = m.r32((0x0084e328u));
  }
  { // 0x4cf1d8: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x4cf1da: ff5254 CALL dword ptr [EDX + 0x54]
    const std::uint32_t call_target=m.r32((s.dx+0x00000054u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L004cf1dd: { // 0x4cf1dd: 8b4620 MOV EAX,dword ptr [ESI + 0x20]
    s.ax = m.r32((s.si+0x00000020u));
  }
  { // 0x4cf1e0: 80cc01 OR AH,0x1
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))|(0x00000001u),8,flags)) & 0xffu) << 8);
  }
  { // 0x4cf1e3: 894620 MOV dword ptr [ESI + 0x20],EAX
    m.w32((s.si+0x00000020u), s.ax);
  }
  { // 0x4cf1e6: 893528e38400 MOV dword ptr [0x0084e328],ESI
    m.w32((0x0084e328u), s.si);
  }
  { // 0x4cf1ec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4cf1ed: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000d14f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4d14f0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4d14f4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4d14f5: 8b1d84547800 MOV EBX,dword ptr [0x00785484]
    s.bx = m.r32((0x00785484u));
  }
  { // 0x4d14fb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4d14fc: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4d14fd: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x4d1500: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x4d1502: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x4d1504: 750d JNZ 0x004d1513
    if(integer::condition("JNZ",flags)) goto L004d1513;
  }
  { // 0x4d1506: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4d1508: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4d150a: 6847010000 PUSH 0x147
    f.push(m,0x00000147u);
  }
  { // 0x4d150f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4d1510: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4d1511: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004d1513: { // 0x4d1513: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4d1515: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4d1516: 6850010000 PUSH 0x150
    f.push(m,0x00000150u);
  }
  { // 0x4d151b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4d151c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4d151d: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4d151f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4d1520: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4d1521: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4d1522: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000d1fd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4d1fd0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4d1fd4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4d1fd5: 8b1d84547800 MOV EBX,dword ptr [0x00785484]
    s.bx = m.r32((0x00785484u));
  }
  { // 0x4d1fdb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4d1fdc: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4d1fdd: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x4d1fe0: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x4d1fe2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x4d1fe4: 750d JNZ 0x004d1ff3
    if(integer::condition("JNZ",flags)) goto L004d1ff3;
  }
  { // 0x4d1fe6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4d1fe8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4d1fea: 6847010000 PUSH 0x147
    f.push(m,0x00000147u);
  }
  { // 0x4d1fef: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4d1ff0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4d1ff1: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004d1ff3: { // 0x4d1ff3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4d1ff5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4d1ff6: 6850010000 PUSH 0x150
    f.push(m,0x00000150u);
  }
  { // 0x4d1ffb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4d1ffc: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4d1ffd: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4d1fff: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4d2000: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4d2001: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4d2002: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000dedd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4dedd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4dedd1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4dedd3: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x4dedd6: c70698db7800 MOV dword ptr [ESI],0x78db98
    m.w32((s.si), 0x0078db98u);
  }
  { // 0x4deddc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4dedde: 7406 JZ 0x004dede6
    if(integer::condition("JZ",flags)) goto L004dede6;
  }
  { // 0x4dede0: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x4dede2: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4dede4: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004dede6: { // 0x4dede6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4dede8: e8e3090000 CALL 0x004df7d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4deded: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4dedee: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000dee40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4dee40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4dee41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4dee43: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x4dee46: c70698db7800 MOV dword ptr [ESI],0x78db98
    m.w32((s.si), 0x0078db98u);
  }
  { // 0x4dee4c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4dee4e: 7406 JZ 0x004dee56
    if(integer::condition("JZ",flags)) goto L004dee56;
  }
  { // 0x4dee50: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x4dee52: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4dee54: ff10 CALL dword ptr [EAX]
    const std::uint32_t call_target=m.r32((s.ax));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004dee56: { // 0x4dee56: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4dee58: e873090000 CALL 0x004df7d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4dee5d: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x4dee62: 7409 JZ 0x004dee6d
    if(integer::condition("JZ",flags)) goto L004dee6d;
  }
  { // 0x4dee64: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4dee65: e811e82800 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4dee6a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004dee6d: { // 0x4dee6d: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4dee6f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4dee70: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000dfff0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4dfff0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4dfff1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4dfff3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4dfff5: ff501c CALL dword ptr [EAX + 0x1c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000001cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4dfff8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4dfffa: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4dfffc: ff5220 CALL dword ptr [EDX + 0x20]
    const std::uint32_t call_target=m.r32((s.dx+0x00000020u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4dffff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e0000: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000e0150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e0150: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x4e0152: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4e0153: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x4e0157: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4e0158: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4e015b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4e015d: 7406 JZ 0x004e0165
    if(integer::condition("JZ",flags)) goto L004e0165;
  }
  { // 0x4e015f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4e0161: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e0162: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004e0165: { // 0x4e0165: a1348ba200 MOV EAX,[0x00a28b34]
    s.ax = m.r32((0x00a28b34u));
  }
  { // 0x4e016a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4e016c: 740e JZ 0x004e017c
    if(integer::condition("JZ",flags)) goto L004e017c;
  }
  { // 0x4e016e: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4e0170: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4e0171: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4e0173: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4e0176: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4e0178: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e0179: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004e017c: { // 0x4e017c: 8935348ba200 MOV dword ptr [0x00a28b34],ESI
    m.w32((0x00a28b34u), s.si);
  }
  { // 0x4e0182: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4e0184: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e0185: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000e0190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e0190: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x4e0192: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4e0193: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x4e0197: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4e0198: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4e019b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4e019d: 7504 JNZ 0x004e01a3
    if(integer::condition("JNZ",flags)) goto L004e01a3;
  }
  { // 0x4e019f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e01a0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004e01a3: { // 0x4e01a3: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4e01a5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4e01a7: ff5224 CALL dword ptr [EDX + 0x24]
    const std::uint32_t call_target=m.r32((s.dx+0x00000024u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4e01aa: a3348ba200 MOV [0x00a28b34],EAX
    m.w32((0x00a28b34u), s.ax);
  }
  { // 0x4e01af: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4e01b1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e01b2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000ec450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ec450: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4ec451: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4ec453: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x4ec457: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4ec459: 7412 JZ 0x004ec46d
    if(integer::condition("JZ",flags)) goto L004ec46d;
  }
  { // 0x4ec45b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4ec45f: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x4ec461: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4ec462: ff523c CALL dword ptr [EDX + 0x3c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000003cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4ec465: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4ec466: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4ec468: e89388ffff CALL 0x004e4d00
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L004ec46d: { // 0x4ec46d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4ec46e: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000ec480(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ec480: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4ec481: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4ec483: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x4ec487: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4ec489: 7412 JZ 0x004ec49d
    if(integer::condition("JZ",flags)) goto L004ec49d;
  }
  { // 0x4ec48b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4ec48f: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x4ec491: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4ec492: ff523c CALL dword ptr [EDX + 0x3c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000003cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4ec495: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4ec496: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4ec498: e8738cffff CALL 0x004e5110
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L004ec49d: { // 0x4ec49d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4ec49e: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000f3070(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4f3070: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4f3071: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4f3073: 83bef0540000ff CMP dword ptr [ESI + 0x54f0],-0x1
    (void)integer::sub(m.r32((s.si+0x000054f0u)),0xffffffffu,32,flags);
  }
  { // 0x4f307a: 7421 JZ 0x004f309d
    if(integer::condition("JZ",flags)) goto L004f309d;
  }
  { // 0x4f307c: 8b869c010000 MOV EAX,dword ptr [ESI + 0x19c]
    s.ax = m.r32((s.si+0x0000019cu));
  }
  { // 0x4f3082: 8d8e9c010000 LEA ECX,[ESI + 0x19c]
    s.cx = (s.si+0x0000019cu);
  }
  { // 0x4f3088: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x4f308c: 685c8ba200 PUSH 0xa28b5c
    f.push(m,0x00a28b5cu);
  }
  { // 0x4f3091: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4f3092: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4f3095: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4f3096: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4f3098: e8d32effff CALL 0x004e5f70
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L004f309d: { // 0x4f309d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f309e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
} // namespace
const std::array<Entry,161>& entries_a() {
  static const std::array<Entry,161> entries{{
    {0x1580u,f_00001580},
    {0x1980u,f_00001980},
    {0x2170u,f_00002170},
    {0x22c0u,f_000022c0},
    {0x2440u,f_00002440},
    {0x2550u,f_00002550},
    {0x25b0u,f_000025b0},
    {0x2720u,f_00002720},
    {0x2b80u,f_00002b80},
    {0x7e60u,f_00007e60},
    {0x7ed0u,f_00007ed0},
    {0x7f20u,f_00007f20},
    {0x9280u,f_00009280},
    {0xa530u,f_0000a530},
    {0xa870u,f_0000a870},
    {0x100c0u,f_000100c0},
    {0x10120u,f_00010120},
    {0x10740u,f_00010740},
    {0x11230u,f_00011230},
    {0x11370u,f_00011370},
    {0x17840u,f_00017840},
    {0x19cd0u,f_00019cd0},
    {0x1a500u,f_0001a500},
    {0x1afd0u,f_0001afd0},
    {0x1b050u,f_0001b050},
    {0x1b0b0u,f_0001b0b0},
    {0x1b1e0u,f_0001b1e0},
    {0x1e510u,f_0001e510},
    {0x23ff0u,f_00023ff0},
    {0x24070u,f_00024070},
    {0x240b0u,f_000240b0},
    {0x24720u,f_00024720},
    {0x24bc0u,f_00024bc0},
    {0x2f620u,f_0002f620},
    {0x2fca0u,f_0002fca0},
    {0x2fde0u,f_0002fde0},
    {0x30130u,f_00030130},
    {0x30870u,f_00030870},
    {0x32be0u,f_00032be0},
    {0x349a0u,f_000349a0},
    {0x35440u,f_00035440},
    {0x354c0u,f_000354c0},
    {0x354f0u,f_000354f0},
    {0x35520u,f_00035520},
    {0x36550u,f_00036550},
    {0x3b620u,f_0003b620},
    {0x423d0u,f_000423d0},
    {0x45190u,f_00045190},
    {0x4d570u,f_0004d570},
    {0x4d5b0u,f_0004d5b0},
    {0x4d710u,f_0004d710},
    {0x50bf0u,f_00050bf0},
    {0x51ec0u,f_00051ec0},
    {0x53520u,f_00053520},
    {0x53af0u,f_00053af0},
    {0x54870u,f_00054870},
    {0x548f0u,f_000548f0},
    {0x58670u,f_00058670},
    {0x58a80u,f_00058a80},
    {0x58ad0u,f_00058ad0},
    {0x635c0u,f_000635c0},
    {0x67bb0u,f_00067bb0},
    {0x68c50u,f_00068c50},
    {0x68d70u,f_00068d70},
    {0x68dc0u,f_00068dc0},
    {0x6cba0u,f_0006cba0},
    {0x6cf80u,f_0006cf80},
    {0x6d760u,f_0006d760},
    {0x6d820u,f_0006d820},
    {0x6fe50u,f_0006fe50},
    {0x7d100u,f_0007d100},
    {0x7d450u,f_0007d450},
    {0x7d4b0u,f_0007d4b0},
    {0x7d510u,f_0007d510},
    {0x7db60u,f_0007db60},
    {0x81140u,f_00081140},
    {0x815c0u,f_000815c0},
    {0x81850u,f_00081850},
    {0x83290u,f_00083290},
    {0x83310u,f_00083310},
    {0x916d0u,f_000916d0},
    {0x91710u,f_00091710},
    {0x91790u,f_00091790},
    {0x918e0u,f_000918e0},
    {0x928b0u,f_000928b0},
    {0x94bc0u,f_00094bc0},
    {0x94c10u,f_00094c10},
    {0x94c60u,f_00094c60},
    {0x94ca0u,f_00094ca0},
    {0x94cd0u,f_00094cd0},
    {0x94d00u,f_00094d00},
    {0x94d40u,f_00094d40},
    {0x94d80u,f_00094d80},
    {0x94db0u,f_00094db0},
    {0x95010u,f_00095010},
    {0x952c0u,f_000952c0},
    {0x95330u,f_00095330},
    {0x95550u,f_00095550},
    {0x95840u,f_00095840},
    {0x98150u,f_00098150},
    {0x98950u,f_00098950},
    {0x98a30u,f_00098a30},
    {0x99820u,f_00099820},
    {0x9e920u,f_0009e920},
    {0x9eb30u,f_0009eb30},
    {0x9f400u,f_0009f400},
    {0x9fa30u,f_0009fa30},
    {0xa02e0u,f_000a02e0},
    {0xa4570u,f_000a4570},
    {0xa49d0u,f_000a49d0},
    {0xa4ba0u,f_000a4ba0},
    {0xa4be0u,f_000a4be0},
    {0xa4c00u,f_000a4c00},
    {0xa4c20u,f_000a4c20},
    {0xa4c40u,f_000a4c40},
    {0xa4c70u,f_000a4c70},
    {0xa4cf0u,f_000a4cf0},
    {0xa4e50u,f_000a4e50},
    {0xa51a0u,f_000a51a0},
    {0xa57a0u,f_000a57a0},
    {0xa6380u,f_000a6380},
    {0xaa2b0u,f_000aa2b0},
    {0xaac10u,f_000aac10},
    {0xaac90u,f_000aac90},
    {0xb1180u,f_000b1180},
    {0xb4640u,f_000b4640},
    {0xb99e0u,f_000b99e0},
    {0xbbe00u,f_000bbe00},
    {0xbf110u,f_000bf110},
    {0xbf890u,f_000bf890},
    {0xc47d0u,f_000c47d0},
    {0xc4800u,f_000c4800},
    {0xc4870u,f_000c4870},
    {0xc76a0u,f_000c76a0},
    {0xc76e0u,f_000c76e0},
    {0xc7e00u,f_000c7e00},
    {0xc82e0u,f_000c82e0},
    {0xc88a0u,f_000c88a0},
    {0xc8900u,f_000c8900},
    {0xc8ba0u,f_000c8ba0},
    {0xc9610u,f_000c9610},
    {0xc9d30u,f_000c9d30},
    {0xc9d60u,f_000c9d60},
    {0xca2a0u,f_000ca2a0},
    {0xca3d0u,f_000ca3d0},
    {0xca420u,f_000ca420},
    {0xca480u,f_000ca480},
    {0xcd7e0u,f_000cd7e0},
    {0xcd970u,f_000cd970},
    {0xced50u,f_000ced50},
    {0xcf1c0u,f_000cf1c0},
    {0xd14f0u,f_000d14f0},
    {0xd1fd0u,f_000d1fd0},
    {0xdedd0u,f_000dedd0},
    {0xdee40u,f_000dee40},
    {0xdfff0u,f_000dfff0},
    {0xe0150u,f_000e0150},
    {0xe0190u,f_000e0190},
    {0xec450u,f_000ec450},
    {0xec480u,f_000ec480},
    {0xf3070u,f_000f3070},
  }}; return entries;
}
} // namespace ra2::recovered::mixed_b35
