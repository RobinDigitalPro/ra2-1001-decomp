#include "recovered/direct_b33_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::direct_b33 {
namespace {
void f_000015c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4015c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4015c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4015c3: 6860d87600 PUSH 0x76d860
    f.push(m,0x0076d860u);
  }
  { // 0x4015c8: 6a24 PUSH 0x24
    f.push(m,0x00000024u);
  }
  { // 0x4015ca: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x4015cd: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x4015cf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4015d0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4015d1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4015d2: e88ec33600 CALL 0x0076d965
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4015d7: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x4015d9: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x4015dc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4015de: 7412 JZ 0x004015f2
    if(integer::condition("JZ",flags)) goto L004015f2;
  }
  { // 0x4015e0: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4015e2: b8398ee338 MOV EAX,0x38e38e39
    s.ax = 0x38e38e39u;
  }
  { // 0x4015e7: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x4015e9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4015ea: f7e1 MUL ECX
    const auto product=std::uint64_t(s.ax)*std::uint64_t(s.cx);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(product>>32);
    flags=(flags&~(integer::CF|integer::OF))|(s.dx?integer::CF|integer::OF:0);
  }
  { // 0x4015ec: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x4015ee: c1e803 SHR EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::right);
  }
  { // 0x4015f1: c3 RET
    finish(m,s,f,0u); return;
  }
  L004015f2: { // 0x4015f2: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x4015f5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4015f6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00002790(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x402790: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x402791: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x402792: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x402794: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x402796: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x402798: 89be68010000 MOV dword ptr [ESI + 0x168],EDI
    m.w32((s.si+0x00000168u), s.di);
  }
  { // 0x40279e: 744f JZ 0x004027ef
    if(integer::condition("JZ",flags)) goto L004027ef;
  }
  { // 0x4027a0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4027a2: e8995c0000 CALL 0x00408440
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4027a7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4027a9: 89866c010000 MOV dword ptr [ESI + 0x16c],EAX
    m.w32((s.si+0x0000016cu), s.ax);
  }
  { // 0x4027af: 7421 JZ 0x004027d2
    if(integer::condition("JZ",flags)) goto L004027d2;
  }
  { // 0x4027b1: 8b480c MOV ECX,dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  { // 0x4027b4: 898e70010000 MOV dword ptr [ESI + 0x170],ECX
    m.w32((s.si+0x00000170u), s.cx);
  }
  { // 0x4027ba: 8b4010 MOV EAX,dword ptr [EAX + 0x10]
    s.ax = m.r32((s.ax+0x00000010u));
  }
  { // 0x4027bd: 898674010000 MOV dword ptr [ESI + 0x174],EAX
    m.w32((s.si+0x00000174u), s.ax);
  }
  { // 0x4027c3: 898678010000 MOV dword ptr [ESI + 0x178],EAX
    m.w32((s.si+0x00000178u), s.ax);
  }
  { // 0x4027c9: c70700000000 MOV dword ptr [EDI],0x0
    m.w32((s.di), 0x00000000u);
  }
  { // 0x4027cf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4027d0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4027d1: c3 RET
    finish(m,s,f,0u); return;
  }
  L004027d2: { // 0x4027d2: 8b8668010000 MOV EAX,dword ptr [ESI + 0x168]
    s.ax = m.r32((s.si+0x00000168u));
  }
  { // 0x4027d8: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x4027da: 899670010000 MOV dword ptr [ESI + 0x170],EDX
    m.w32((s.si+0x00000170u), s.dx);
  }
  { // 0x4027e0: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  { // 0x4027e3: 898674010000 MOV dword ptr [ESI + 0x174],EAX
    m.w32((s.si+0x00000174u), s.ax);
  }
  { // 0x4027e9: 898678010000 MOV dword ptr [ESI + 0x178],EAX
    m.w32((s.si+0x00000178u), s.ax);
  }
  L004027ef: { // 0x4027ef: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4027f0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4027f1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00002860(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x402860: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x402861: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x402863: 89b2ac000000 MOV dword ptr [EDX + 0xac],ESI
    m.w32((s.dx+0x000000acu), s.si);
  }
  { // 0x402869: 8b86f0000000 MOV EAX,dword ptr [ESI + 0xf0]
    s.ax = m.r32((s.si+0x000000f0u));
  }
  { // 0x40286f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x402870: 8986f0000000 MOV dword ptr [ESI + 0xf0],EAX
    m.w32((s.si+0x000000f0u), s.ax);
  }
  { // 0x402876: 8b8604010000 MOV EAX,dword ptr [ESI + 0x104]
    s.ax = m.r32((s.si+0x00000104u));
  }
  { // 0x40287c: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x40287d: 898604010000 MOV dword ptr [ESI + 0x104],EAX
    m.w32((s.si+0x00000104u), s.ax);
  }
  { // 0x402883: 8d8ef8000000 LEA ECX,[ESI + 0xf8]
    s.cx = (s.si+0x000000f8u);
  }
  { // 0x402889: e8c24a0000 CALL 0x00407350
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x40288e: 8b8604010000 MOV EAX,dword ptr [ESI + 0x104]
    s.ax = m.r32((s.si+0x00000104u));
  }
  { // 0x402894: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x402895: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x402897: 898604010000 MOV dword ptr [ESI + 0x104],EAX
    m.w32((s.si+0x00000104u), s.ax);
  }
  { // 0x40289d: 7d0a JGE 0x004028a9
    if(integer::condition("JGE",flags)) goto L004028a9;
  }
  { // 0x40289f: c7860401000000000000 MOV dword ptr [ESI + 0x104],0x0
    m.w32((s.si+0x00000104u), 0x00000000u);
  }
  L004028a9: { // 0x4028a9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4028aa: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00002c00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x402c00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x402c01: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x402c03: 8b0df8787b00 MOV ECX,dword ptr [0x007b78f8]
    s.cx = m.r32((0x007b78f8u));
  }
  { // 0x402c09: e8e2460000 CALL 0x004072f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x402c0e: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x402c10: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x402c11: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00002c20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x402c20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x402c21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x402c23: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x402c25: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x402c27: 7407 JZ 0x00402c30
    if(integer::condition("JZ",flags)) goto L00402c30;
  }
  { // 0x402c29: e8e2460000 CALL 0x00407310
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x402c2e: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00402c30: { // 0x402c30: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x402c32: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x402c33: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000031f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4031f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4031f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4031f3: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x4031f5: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4031f7: 7407 JZ 0x00403200
    if(integer::condition("JZ",flags)) goto L00403200;
  }
  { // 0x4031f9: e812410000 CALL 0x00407310
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4031fe: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00403200: { // 0x403200: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x403202: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x403203: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000035b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4035b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4035b1: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x4035b3: 81c1f8000000 ADD ECX,0xf8
    s.cx = integer::add(s.cx,0x000000f8u,32,flags);
  }
  { // 0x4035b9: e8323d0000 CALL 0x004072f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4035be: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x4035c0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4035c1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000035d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4035d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4035d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4035d3: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x4035d5: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4035d7: 7407 JZ 0x004035e0
    if(integer::condition("JZ",flags)) goto L004035e0;
  }
  { // 0x4035d9: e8323d0000 CALL 0x00407310
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4035de: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L004035e0: { // 0x4035e0: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4035e2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4035e3: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00003870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x403870: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x403874: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x403875: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x403877: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x403879: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x40387d: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  { // 0x403880: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x403883: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  { // 0x403886: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x403888: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x40388b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x40388d: 6a0a PUSH 0xa
    f.push(m,0x0000000au);
  }
  { // 0x40388f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x403890: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x403891: e86aa13600 CALL 0x0076da00
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x403896: 894620 MOV dword ptr [ESI + 0x20],EAX
    m.w32((s.si+0x00000020u), s.ax);
  }
  { // 0x403899: 895624 MOV dword ptr [ESI + 0x24],EDX
    m.w32((s.si+0x00000024u), s.dx);
  }
  { // 0x40389c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40389d: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000053f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4053f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4053f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4053f3: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    s.ax = m.r32((s.si+0x00000158u));
  }
  { // 0x4053f9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4053fb: 752b JNZ 0x00405428
    if(integer::condition("JNZ",flags)) goto L00405428;
  }
  { // 0x4053fd: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  { // 0x405400: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x405403: 7523 JNZ 0x00405428
    if(integer::condition("JNZ",flags)) goto L00405428;
  }
  { // 0x405405: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x405406: e8c53e0000 CALL 0x004092d0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x40540b: 8b8e40010000 MOV ECX,dword ptr [ESI + 0x140]
    s.cx = m.r32((s.si+0x00000140u));
  }
  { // 0x405411: 8bbe44010000 MOV EDI,dword ptr [ESI + 0x144]
    s.di = m.r32((s.si+0x00000144u));
  }
  { // 0x405417: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x405419: 1bfa SBB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags,flags&integer::CF);
  }
  { // 0x40541b: 898e40010000 MOV dword ptr [ESI + 0x140],ECX
    m.w32((s.si+0x00000140u), s.cx);
  }
  { // 0x405421: 89be44010000 MOV dword ptr [ESI + 0x144],EDI
    m.w32((s.si+0x00000144u), s.di);
  }
  { // 0x405427: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00405428: { // 0x405428: 8b9658010000 MOV EDX,dword ptr [ESI + 0x158]
    s.dx = m.r32((s.si+0x00000158u));
  }
  { // 0x40542e: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  { // 0x40542f: 899658010000 MOV dword ptr [ESI + 0x158],EDX
    m.w32((s.si+0x00000158u), s.dx);
  }
  { // 0x405435: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x405436: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00005440(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x405440: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x405441: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x405443: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    s.ax = m.r32((s.si+0x00000158u));
  }
  { // 0x405449: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x40544b: 7450 JZ 0x0040549d
    if(integer::condition("JZ",flags)) goto L0040549d;
  }
  { // 0x40544d: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    s.ax = m.r32((s.si+0x00000158u));
  }
  { // 0x405453: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x405454: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x405456: 898658010000 MOV dword ptr [ESI + 0x158],EAX
    m.w32((s.si+0x00000158u), s.ax);
  }
  { // 0x40545c: 7d0a JGE 0x00405468
    if(integer::condition("JGE",flags)) goto L00405468;
  }
  { // 0x40545e: c7865801000000000000 MOV dword ptr [ESI + 0x158],0x0
    m.w32((s.si+0x00000158u), 0x00000000u);
  }
  L00405468: { // 0x405468: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    s.ax = m.r32((s.si+0x00000158u));
  }
  { // 0x40546e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x405470: 752b JNZ 0x0040549d
    if(integer::condition("JNZ",flags)) goto L0040549d;
  }
  { // 0x405472: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  { // 0x405475: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x405478: 7523 JNZ 0x0040549d
    if(integer::condition("JNZ",flags)) goto L0040549d;
  }
  { // 0x40547a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x40547b: e8503e0000 CALL 0x004092d0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x405480: 8b8e40010000 MOV ECX,dword ptr [ESI + 0x140]
    s.cx = m.r32((s.si+0x00000140u));
  }
  { // 0x405486: 8bbe44010000 MOV EDI,dword ptr [ESI + 0x144]
    s.di = m.r32((s.si+0x00000144u));
  }
  { // 0x40548c: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x40548e: 13d7 ADC EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags,flags&integer::CF);
  }
  { // 0x405490: 898640010000 MOV dword ptr [ESI + 0x140],EAX
    m.w32((s.si+0x00000140u), s.ax);
  }
  { // 0x405496: 899644010000 MOV dword ptr [ESI + 0x144],EDX
    m.w32((s.si+0x00000144u), s.dx);
  }
  { // 0x40549c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0040549d: { // 0x40549d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40549e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00006f50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x406f50: a180978100 MOV EAX,[0x00819780]
    s.ax = m.r32((0x00819780u));
  }
  { // 0x406f55: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x406f57: 7505 JNZ 0x00406f5e
    if(integer::condition("JNZ",flags)) goto L00406f5e;
  }
  { // 0x406f59: e802390000 CALL 0x0040a860
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L00406f5e: { // 0x406f5e: ff0580978100 INC dword ptr [0x00819780]
    m.w32((0x00819780u), integer::increment(m.r32((0x00819780u)),32,flags));
  }
  { // 0x406f64: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000070a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4070a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4070a1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4070a2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4070a4: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x4070a6: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4070a8: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x4070ab: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x4070ae: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  { // 0x4070b1: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4070b3: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  { // 0x4070b5: 750b JNZ 0x004070c2
    if(integer::condition("JNZ",flags)) goto L004070c2;
  }
  { // 0x4070b7: e814220000 CALL 0x004092d0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4070bc: 894618 MOV dword ptr [ESI + 0x18],EAX
    m.w32((s.si+0x00000018u), s.ax);
  }
  { // 0x4070bf: 89561c MOV dword ptr [ESI + 0x1c],EDX
    m.w32((s.si+0x0000001cu), s.dx);
  }
  L004070c2: { // 0x4070c2: c1e710 SHL EDI,0x10
    s.di = integer::shift(s.di,0x00000010u,32,flags,integer::Shift::left);
  }
  { // 0x4070c5: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  { // 0x4070c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4070c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4070ca: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00007fa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x407fa0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x407fa1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x407fa3: 6a50 PUSH 0x50
    f.push(m,0x00000050u);
  }
  { // 0x407fa5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x407fa6: 8d86a4000000 LEA EAX,[ESI + 0xa4]
    s.ax = (s.si+0x000000a4u);
  }
  { // 0x407fac: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x407fad: e85e5d3600 CALL 0x0076dd10
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x407fb2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x407fb5: c686f300000000 MOV byte ptr [ESI + 0xf3],0x0
    m.w8((s.si+0x000000f3u), 0x00000000u);
  }
  { // 0x407fbc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x407fbd: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00008420(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x408420: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x408421: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x408423: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x408424: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x408426: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x408429: e822efffff CALL 0x00407350
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x40842e: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x408431: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x408434: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x408436: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  { // 0x408439: 897714 MOV dword ptr [EDI + 0x14],ESI
    m.w32((s.di+0x00000014u), s.si);
  }
  { // 0x40843c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x40843d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40843e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00008500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x408500: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x408504: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x408505: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x408507: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x40850a: 89560c MOV dword ptr [ESI + 0xc],EDX
    m.w32((s.si+0x0000000cu), s.dx);
  }
  { // 0x40850d: e8eeecffff CALL 0x00407200
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x408512: c7461400000000 MOV dword ptr [ESI + 0x14],0x0
    m.w32((s.si+0x00000014u), 0x00000000u);
  }
  { // 0x408519: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40851a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00008a30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x408a30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x408a31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x408a33: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x408a34: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x408a36: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x408a39: e832e9ffff CALL 0x00407370
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x408a3e: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x408a40: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x408a43: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  { // 0x408a44: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  { // 0x408a46: 8b471c MOV EAX,dword ptr [EDI + 0x1c]
    s.ax = m.r32((s.di+0x0000001cu));
  }
  { // 0x408a49: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x408a4b: 894e14 MOV dword ptr [ESI + 0x14],ECX
    m.w32((s.si+0x00000014u), s.cx);
  }
  { // 0x408a4e: 897730 MOV dword ptr [EDI + 0x30],ESI
    m.w32((s.di+0x00000030u), s.si);
  }
  { // 0x408a51: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x408a54: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x408a55: 24fd AND AL,0xfd
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fdu),8,flags));
  }
  { // 0x408a57: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x408a5a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x408a5b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00008d40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x408d40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x408d41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x408d43: e838e6ffff CALL 0x00407380
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x408d48: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  { // 0x408d4b: c7463000000000 MOV dword ptr [ESI + 0x30],0x0
    m.w32((s.si+0x00000030u), 0x00000000u);
  }
  { // 0x408d52: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x408d54: 8b5014 MOV EDX,dword ptr [EAX + 0x14]
    s.dx = m.r32((s.ax+0x00000014u));
  }
  { // 0x408d57: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x408d58: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x408d5a: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  { // 0x408d5d: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x408d5f: 8b4810 MOV ECX,dword ptr [EAX + 0x10]
    s.cx = m.r32((s.ax+0x00000010u));
  }
  { // 0x408d62: 83e1fd AND ECX,0xfffffffd
    s.cx = integer::logical((s.cx)&(0xfffffffdu),32,flags);
  }
  { // 0x408d65: 895014 MOV dword ptr [EAX + 0x14],EDX
    m.w32((s.ax+0x00000014u), s.dx);
  }
  { // 0x408d68: 894810 MOV dword ptr [EAX + 0x10],ECX
    m.w32((s.ax+0x00000010u), s.cx);
  }
  { // 0x408d6b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x408d6c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00009230(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x409230: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x409231: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x409233: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x409235: e8a6feffff CALL 0x004090e0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x40923a: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x40923d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40923e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0000ffd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x40ffd0: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  { // 0x40ffd6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x40ffd8: 750c JNZ 0x0040ffe6
    if(integer::condition("JNZ",flags)) goto L0040ffe6;
  }
  { // 0x40ffda: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x40ffde: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x40ffe0: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  { // 0x40ffe3: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0040ffe6: { // 0x40ffe6: e835a12400 CALL 0x0065a120
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x40ffeb: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x40ffef: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  { // 0x40fff2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000107c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4107c0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4107c4: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x4107c7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4107c8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4107c9: e892d03500 CALL 0x0076d860
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4107ce: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4107d1: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x4107d3: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x4107d5: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x4107d6: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0001b990(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41b990: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41b991: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x41b993: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x41b996: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x41b998: 7504 JNZ 0x0041b99e
    if(integer::condition("JNZ",flags)) goto L0041b99e;
  }
  { // 0x41b99a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41b99b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0041b99e: { // 0x41b99e: 8a4e0c MOV CL,byte ptr [ESI + 0xc]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000000cu)));
  }
  { // 0x41b9a1: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x41b9a3: 751e JNZ 0x0041b9c3
    if(integer::condition("JNZ",flags)) goto L0041b9c3;
  }
  { // 0x41b9a5: 6810ba4100 PUSH 0x41ba10
    f.push(m,0x0041ba10u);
  }
  { // 0x41b9aa: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x41b9ac: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x41b9ad: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x41b9af: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x41b9b0: e8d11c3500 CALL 0x0076d686
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x41b9b5: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x41b9b8: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  { // 0x41b9bf: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L0041b9c3: { // 0x41b9c3: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x41b9c7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x41b9c8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x41b9c9: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x41b9cb: 8b19 MOV EBX,dword ptr [ECX]
    s.bx = m.r32((s.cx));
  }
  { // 0x41b9cd: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x41b9d0: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x41b9d2: 7e25 JLE 0x0041b9f9
    if(integer::condition("JLE",flags)) goto L0041b9f9;
  }
  L0041b9d4: { // 0x41b9d4: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x41b9d6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x41b9d7: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x41b9d9: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x41b9db: 8b34c7 MOV ESI,dword ptr [EDI + EAX*0x8]
    s.si = m.r32((s.di+(s.ax * 0x00000008u)));
  }
  { // 0x41b9de: 8d14c7 LEA EDX,[EDI + EAX*0x8]
    s.dx = (s.di+(s.ax * 0x00000008u));
  }
  { // 0x41b9e1: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x41b9e3: 7e04 JLE 0x0041b9e9
    if(integer::condition("JLE",flags)) goto L0041b9e9;
  }
  { // 0x41b9e5: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x41b9e7: eb0c JMP 0x0041b9f5
    goto L0041b9f5;
  }
  L0041b9e9: { // 0x41b9e9: 7416 JZ 0x0041ba01
    if(integer::condition("JZ",flags)) goto L0041ba01;
  }
  { // 0x41b9eb: 8d7a08 LEA EDI,[EDX + 0x8]
    s.di = (s.dx+0x00000008u);
  }
  { // 0x41b9ee: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  { // 0x41b9f1: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x41b9f3: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0041b9f5: { // 0x41b9f5: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x41b9f7: 7fdb JG 0x0041b9d4
    if(integer::condition("JG",flags)) goto L0041b9d4;
  }
  L0041b9f9: { // 0x41b9f9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x41b9fa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x41b9fb: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x41b9fd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41b9fe: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0041ba01: { // 0x41ba01: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x41ba02: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x41ba03: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x41ba05: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41ba06: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00020d70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x420d70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x420d71: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x420d73: e868cd1a00 CALL 0x005cdae0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x420d78: 8b8eec000000 MOV ECX,dword ptr [ESI + 0xec]
    s.cx = m.r32((s.si+0x000000ecu));
  }
  { // 0x420d7e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x420d7f: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x420d81: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00026e00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x426e00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x426e01: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x426e05: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x426e07: 7509 JNZ 0x00426e12
    if(integer::condition("JNZ",flags)) goto L00426e12;
  }
  { // 0x426e09: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  { // 0x426e0e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x426e0f: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00426e12: { // 0x426e12: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x426e17: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x426e18: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x426e19: 8bb81c060000 MOV EDI,dword ptr [EAX + 0x61c]
    s.di = m.r32((s.ax+0x0000061cu));
  }
  { // 0x426e1f: 8db014060000 LEA ESI,[EAX + 0x614]
    s.si = (s.ax+0x00000614u);
  }
  { // 0x426e25: 8b8014060000 MOV EAX,dword ptr [EAX + 0x614]
    s.ax = m.r32((s.ax+0x00000614u));
  }
  { // 0x426e2b: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x426e2e: 740c JZ 0x00426e3c
    if(integer::condition("JZ",flags)) goto L00426e3c;
  }
  { // 0x426e30: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x426e33: e8988c2600 CALL 0x0068fad0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x426e38: 2b06 SUB EAX,dword ptr [ESI]
    s.ax = integer::sub(s.ax,m.r32((s.si)),32,flags);
  }
  { // 0x426e3a: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L00426e3c: { // 0x426e3c: 893b MOV dword ptr [EBX],EDI
    m.w32((s.bx), s.di);
  }
  { // 0x426e3e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x426e3f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x426e40: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x426e42: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x426e43: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0002ad50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42ad50: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x42ad54: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x42ad55: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  { // 0x42ad58: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x42ad5a: 7543 JNZ 0x0042ad9f
    if(integer::condition("JNZ",flags)) goto L0042ad9f;
  }
  { // 0x42ad5c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x42ad5d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x42ad62: e899a71100 CALL 0x00545500
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x42ad67: 0fbf8016010000 MOVSX EAX,word ptr [EAX + 0x116]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000116u)),16));
  }
  { // 0x42ad6e: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x42ad71: 7414 JZ 0x0042ad87
    if(integer::condition("JZ",flags)) goto L0042ad87;
  }
  { // 0x42ad73: 8b0dfce48400 MOV ECX,dword ptr [0x0084e4fc]
    s.cx = m.r32((0x0084e4fcu));
  }
  { // 0x42ad79: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x42ad7c: 8b4228 MOV EAX,dword ptr [EDX + 0x28]
    s.ax = m.r32((s.dx+0x00000028u));
  }
  { // 0x42ad7f: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x42ad81: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x42ad83: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42ad84: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0042ad87: { // 0x42ad87: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x42ad89: 6689442408 MOV word ptr [ESP + 0x8],AX
    m.w16((f.sp+0x00000008u), (s.ax & 0xffffu));
  }
  { // 0x42ad8e: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  { // 0x42ad93: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x42ad97: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x42ad99: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x42ad9b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42ad9c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0042ad9f: { // 0x42ad9f: 668b0a MOV CX,word ptr [EDX]
    s.cx = with_ax(s.cx, m.r16((s.dx)));
  }
  { // 0x42ada2: 66030c85a09d8300 ADD CX,word ptr [EAX*0x4 + 0x839da0]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16(((s.ax * 0x00000004u)+0x00839da0u)),16,flags));
  }
  { // 0x42adaa: 668b0485a29d8300 MOV AX,word ptr [EAX*0x4 + 0x839da2]
    s.ax = with_ax(s.ax, m.r16(((s.ax * 0x00000004u)+0x00839da2u)));
  }
  { // 0x42adb2: 66034202 ADD AX,word ptr [EDX + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.dx+0x00000002u)),16,flags));
  }
  { // 0x42adb6: 66894c2408 MOV word ptr [ESP + 0x8],CX
    m.w16((f.sp+0x00000008u), (s.cx & 0xffffu));
  }
  { // 0x42adbb: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  { // 0x42adc0: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x42adc4: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  { // 0x42adc6: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x42adc8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42adc9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0002c3a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42c3a0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x42c3a4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x42c3a5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x42c3a7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x42c3a8: e823000000 CALL 0x0042c3d0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x42c3ad: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x42c3b0: 740c JZ 0x0042c3be
    if(integer::condition("JZ",flags)) goto L0042c3be;
  }
  { // 0x42c3b2: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x42c3b5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42c3b6: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x42c3b9: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x42c3bb: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0042c3be: { // 0x42c3be: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x42c3c0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42c3c1: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0002f5e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42f5e0: 8a4125 MOV AL,byte ptr [ECX + 0x25]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000025u)));
  }
  { // 0x42f5e3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x42f5e5: 7405 JZ 0x0042f5ec
    if(integer::condition("JZ",flags)) goto L0042f5ec;
  }
  { // 0x42f5e7: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x42f5e9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0042f5ec: { // 0x42f5ec: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x42f5ee: e84d0c2000 CALL 0x00630240
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x42f5f3: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0002fd70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42fd70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x42fd71: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x42fd73: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x42fd75: 8806 MOV byte ptr [ESI],AL
    m.w8((s.si), (s.ax & 0xffu));
  }
  { // 0x42fd77: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x42fd7a: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  { // 0x42fd7d: 894620 MOV dword ptr [ESI + 0x20],EAX
    m.w32((s.si+0x00000020u), s.ax);
  }
  { // 0x42fd80: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x42fd84: c74628ffffffff MOV dword ptr [ESI + 0x28],0xffffffff
    m.w32((s.si+0x00000028u), 0xffffffffu);
  }
  { // 0x42fd8b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x42fd8c: c6462c01 MOV byte ptr [ESI + 0x2c],0x1
    m.w8((s.si+0x0000002cu), 0x00000001u);
  }
  { // 0x42fd90: e89b000000 CALL 0x0042fe30
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x42fd95: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x42fd97: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42fd98: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0002fda0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42fda0: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x42fda4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x42fda5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x42fda7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x42fda9: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x42fdad: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x42fdae: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  { // 0x42fdb1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x42fdb3: 8806 MOV byte ptr [ESI],AL
    m.w8((s.si), (s.ax & 0xffu));
  }
  { // 0x42fdb5: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x42fdb8: 894620 MOV dword ptr [ESI + 0x20],EAX
    m.w32((s.si+0x00000020u), s.ax);
  }
  { // 0x42fdbb: c74628ffffffff MOV dword ptr [ESI + 0x28],0xffffffff
    m.w32((s.si+0x00000028u), 0xffffffffu);
  }
  { // 0x42fdc2: c6462c01 MOV byte ptr [ESI + 0x2c],0x1
    m.w8((s.si+0x0000002cu), 0x00000001u);
  }
  { // 0x42fdc6: e865000000 CALL 0x0042fe30
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x42fdcb: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x42fdcd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42fdce: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000302e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4302e0: 8b4920 MOV ECX,dword ptr [ECX + 0x20]
    s.cx = m.r32((s.cx+0x00000020u));
  }
  { // 0x4302e3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4302e5: 740a JZ 0x004302f1
    if(integer::condition("JZ",flags)) goto L004302f1;
  }
  { // 0x4302e7: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4302eb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4302ec: e89f082600 CALL 0x00690b90
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L004302f1: { // 0x4302f1: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000306c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4306c0: 8b4114 MOV EAX,dword ptr [ECX + 0x14]
    s.ax = m.r32((s.cx+0x00000014u));
  }
  { // 0x4306c3: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  { // 0x4306c6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4306c7: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  { // 0x4306ca: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4306cb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4306cc: e82ffeffff CALL 0x00430500
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4306d1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00031550(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x431550: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x431554: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x431558: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x431559: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x43155d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x43155f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x431560: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x431561: e80afeffff CALL 0x00431370
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x431566: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x43156a: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00035e70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x435e70: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x435e71: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x435e72: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x435e74: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x435e76: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  { // 0x435e79: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x435e7b: 7409 JZ 0x00435e86
    if(integer::condition("JZ",flags)) goto L00435e86;
  }
  { // 0x435e7d: 895838 MOV dword ptr [EAX + 0x38],EBX
    m.w32((s.ax+0x00000038u), s.bx);
  }
  { // 0x435e80: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  { // 0x435e83: 885868 MOV byte ptr [EAX + 0x68],BL
    m.w8((s.ax+0x00000068u), (s.bx & 0xffu));
  }
  L00435e86: { // 0x435e86: 8d4e3c LEA ECX,[ESI + 0x3c]
    s.cx = (s.si+0x0000003cu);
  }
  { // 0x435e89: c6465801 MOV byte ptr [ESI + 0x58],0x1
    m.w8((s.si+0x00000058u), 0x00000001u);
  }
  { // 0x435e8d: 895e24 MOV dword ptr [ESI + 0x24],EBX
    m.w32((s.si+0x00000024u), s.bx);
  }
  { // 0x435e90: 895e2c MOV dword ptr [ESI + 0x2c],EBX
    m.w32((s.si+0x0000002cu), s.bx);
  }
  { // 0x435e93: 895e28 MOV dword ptr [ESI + 0x28],EBX
    m.w32((s.si+0x00000028u), s.bx);
  }
  { // 0x435e96: e84501fdff CALL 0x00405fe0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x435e9b: 895e54 MOV dword ptr [ESI + 0x54],EBX
    m.w32((s.si+0x00000054u), s.bx);
  }
  { // 0x435e9e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x435e9f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x435ea0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000450e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4450e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4450e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4450e3: e8f8891800 CALL 0x005cdae0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4450e8: 8bb618040000 MOV ESI,dword ptr [ESI + 0x418]
    s.si = m.r32((s.si+0x00000418u));
  }
  { // 0x4450ee: 8a8e5f130000 MOV CL,byte ptr [ESI + 0x135f]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000135fu)));
  }
  { // 0x4450f4: 8a9651130000 MOV DL,byte ptr [ESI + 0x1351]
    s.dx = with_al(s.dx, m.r8((s.si+0x00001351u)));
  }
  { // 0x4450fa: f6d9 NEG CL
    s.cx = with_al(s.cx, integer::sub(0u,(s.cx & 0xffu),8,flags));
  }
  { // 0x4450fc: 1bc9 SBB ECX,ECX
    s.cx = integer::sub(s.cx,s.cx,32,flags,flags&integer::CF);
  }
  { // 0x4450fe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4450ff: 83e120 AND ECX,0x20
    s.cx = integer::logical((s.cx)&(0x00000020u),32,flags);
  }
  { // 0x445102: f6da NEG DL
    s.dx = with_al(s.dx, integer::sub(0u,(s.dx & 0xffu),8,flags));
  }
  { // 0x445104: 1bd2 SBB EDX,EDX
    s.dx = integer::sub(s.dx,s.dx,32,flags,flags&integer::CF);
  }
  { // 0x445106: 83e210 AND EDX,0x10
    s.dx = integer::logical((s.dx)&(0x00000010u),32,flags);
  }
  { // 0x445109: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x44510b: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x44510d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0004a620(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x44a620: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x44a621: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x44a623: 8b86fc030000 MOV EAX,dword ptr [ESI + 0x3fc]
    s.ax = m.r32((s.si+0x000003fcu));
  }
  { // 0x44a629: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x44a62b: 7e04 JLE 0x0044a631
    if(integer::condition("JLE",flags)) goto L0044a631;
  }
  { // 0x44a62d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x44a62f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44a630: c3 RET
    finish(m,s,f,0u); return;
  }
  L0044a631: { // 0x44a631: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  { // 0x44a637: 8b88440c0000 MOV ECX,dword ptr [EAX + 0xc44]
    s.cx = m.r32((s.ax+0x00000c44u));
  }
  { // 0x44a63d: 83f928 CMP ECX,0x28
    (void)integer::sub(s.cx,0x00000028u,32,flags);
  }
  { // 0x44a640: 745a JZ 0x0044a69c
    if(integer::condition("JZ",flags)) goto L0044a69c;
  }
  { // 0x44a642: 83f910 CMP ECX,0x10
    (void)integer::sub(s.cx,0x00000010u,32,flags);
  }
  { // 0x44a645: 7455 JZ 0x0044a69c
    if(integer::condition("JZ",flags)) goto L0044a69c;
  }
  { // 0x44a647: 83f903 CMP ECX,0x3
    (void)integer::sub(s.cx,0x00000003u,32,flags);
  }
  { // 0x44a64a: 7450 JZ 0x0044a69c
    if(integer::condition("JZ",flags)) goto L0044a69c;
  }
  { // 0x44a64c: 8a884b130000 MOV CL,byte ptr [EAX + 0x134b]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000134bu)));
  }
  { // 0x44a652: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x44a654: 7546 JNZ 0x0044a69c
    if(integer::condition("JNZ",flags)) goto L0044a69c;
  }
  { // 0x44a656: 8a8853130000 MOV CL,byte ptr [EAX + 0x1353]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001353u)));
  }
  { // 0x44a65c: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x44a65e: 7425 JZ 0x0044a685
    if(integer::condition("JZ",flags)) goto L0044a685;
  }
  { // 0x44a660: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  { // 0x44a665: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x44a667: 7418 JZ 0x0044a681
    if(integer::condition("JZ",flags)) goto L0044a681;
  }
  { // 0x44a669: a07056a200 MOV AL,[0x00a25670]
    s.ax = with_al(s.ax, m.r8((0x00a25670u)));
  }
  { // 0x44a66e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44a670: 740f JZ 0x0044a681
    if(integer::condition("JZ",flags)) goto L0044a681;
  }
  { // 0x44a672: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x44a678: e873a10a00 CALL 0x004f47f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x44a67d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44a67f: 7504 JNZ 0x0044a685
    if(integer::condition("JNZ",flags)) goto L0044a685;
  }
  L0044a681: { // 0x44a681: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x44a683: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44a684: c3 RET
    finish(m,s,f,0u); return;
  }
  L0044a685: { // 0x44a685: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  { // 0x44a68b: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x44a68d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44a68e: 8b90cc030000 MOV EDX,dword ptr [EAX + 0x3cc]
    s.dx = m.r32((s.ax+0x000003ccu));
  }
  { // 0x44a694: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x44a696: 0f95c1 SETNZ CL
    s.cx = with_al(s.cx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x44a699: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  { // 0x44a69b: c3 RET
    finish(m,s,f,0u); return;
  }
  L0044a69c: { // 0x44a69c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x44a69e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44a69f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0004c610(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x44c610: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x44c611: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  { // 0x44c615: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x44c616: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x44c618: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x44c61c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x44c61d: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x44c61f: 741a JZ 0x0044c63b
    if(integer::condition("JZ",flags)) goto L0044c63b;
  }
  { // 0x44c621: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x44c625: 8bbe18040000 MOV EDI,dword ptr [ESI + 0x418]
    s.di = m.r32((s.si+0x00000418u));
  }
  { // 0x44c62b: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x44c62d: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x44c630: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x44c632: 8d9497e40c0000 LEA EDX,[EDI + EDX*0x4 + 0xce4]
    s.dx = (s.di+(s.dx * 0x00000004u)+0x00000ce4u);
  }
  { // 0x44c639: eb30 JMP 0x0044c66b
    goto L0044c66b;
  }
  L0044c63b: { // 0x44c63b: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x44c63f: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x44c641: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x44c643: 7414 JZ 0x0044c659
    if(integer::condition("JZ",flags)) goto L0044c659;
  }
  { // 0x44c645: 8bbe18040000 MOV EDI,dword ptr [ESI + 0x418]
    s.di = m.r32((s.si+0x00000418u));
  }
  { // 0x44c64b: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x44c64e: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x44c650: 8d9497f40c0000 LEA EDX,[EDI + EDX*0x4 + 0xcf4]
    s.dx = (s.di+(s.dx * 0x00000004u)+0x00000cf4u);
  }
  { // 0x44c657: eb12 JMP 0x0044c66b
    goto L0044c66b;
  }
  L0044c659: { // 0x44c659: 8bbe18040000 MOV EDI,dword ptr [ESI + 0x418]
    s.di = m.r32((s.si+0x00000418u));
  }
  { // 0x44c65f: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x44c662: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x44c664: 8d9497d40c0000 LEA EDX,[EDI + EDX*0x4 + 0xcd4]
    s.dx = (s.di+(s.dx * 0x00000004u)+0x00000cd4u);
  }
  L0044c66b: { // 0x44c66b: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x44c66d: 7415 JZ 0x0044c684
    if(integer::condition("JZ",flags)) goto L0044c684;
  }
  { // 0x44c66f: 803a00 CMP byte ptr [EDX],0x0
    (void)integer::sub(m.r8((s.dx)),0x00000000u,8,flags);
  }
  { // 0x44c672: 7410 JZ 0x0044c684
    if(integer::condition("JZ",flags)) goto L0044c684;
  }
  { // 0x44c674: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  { // 0x44c678: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x44c679: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x44c67a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x44c67b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x44c67c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x44c67d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x44c67f: e8cc000000 CALL 0x0044c750
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L0044c684: { // 0x44c684: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x44c685: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44c686: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x44c687: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_0004d5f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x44d5f0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x44d5f4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x44d5f5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x44d5f6: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x44d5f8: 3b87b4010000 CMP EAX,dword ptr [EDI + 0x1b4]
    (void)integer::sub(s.ax,m.r32((s.di+0x000001b4u)),32,flags);
  }
  { // 0x44d5fe: 7535 JNZ 0x0044d635
    if(integer::condition("JNZ",flags)) goto L0044d635;
  }
  { // 0x44d600: 8b8f18040000 MOV ECX,dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  { // 0x44d606: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x44d60a: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x44d60d: 8d96200c0000 LEA EDX,[ESI + 0xc20]
    s.dx = (s.si+0x00000c20u);
  }
  { // 0x44d613: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x44d614: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x44d615: e846023200 CALL 0x0076d860
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x44d61a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x44d61d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x44d61f: 7514 JNZ 0x0044d635
    if(integer::condition("JNZ",flags)) goto L0044d635;
  }
  { // 0x44d621: 8b8680130000 MOV EAX,dword ptr [ESI + 0x1380]
    s.ax = m.r32((s.si+0x00001380u));
  }
  { // 0x44d627: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x44d62a: 7410 JZ 0x0044d63c
    if(integer::condition("JZ",flags)) goto L0044d63c;
  }
  { // 0x44d62c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x44d62e: 7e05 JLE 0x0044d635
    if(integer::condition("JLE",flags)) goto L0044d635;
  }
  { // 0x44d630: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x44d633: 7e23 JLE 0x0044d658
    if(integer::condition("JLE",flags)) goto L0044d658;
  }
  L0044d635: { // 0x44d635: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x44d636: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x44d638: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44d639: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0044d63c: { // 0x44d63c: 8b8f18040000 MOV ECX,dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  { // 0x44d642: 0fbe87c6050000 MOVSX EAX,byte ptr [EDI + 0x5c6]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.di+0x000005c6u)),8));
  }
  { // 0x44d649: 3b819c110000 CMP EAX,dword ptr [ECX + 0x119c]
    (void)integer::sub(s.ax,m.r32((s.cx+0x0000119cu)),32,flags);
  }
  { // 0x44d64f: 7d07 JGE 0x0044d658
    if(integer::condition("JGE",flags)) goto L0044d658;
  }
  { // 0x44d651: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x44d652: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x44d654: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44d655: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0044d658: { // 0x44d658: 8a87c6050000 MOV AL,byte ptr [EDI + 0x5c6]
    s.ax = with_al(s.ax, m.r8((s.di+0x000005c6u)));
  }
  { // 0x44d65e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44d660: 75d3 JNZ 0x0044d635
    if(integer::condition("JNZ",flags)) goto L0044d635;
  }
  { // 0x44d662: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x44d663: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x44d665: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44d666: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00052470(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x452470: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x452471: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x452473: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  { // 0x452479: 8b8074130000 MOV EAX,dword ptr [EAX + 0x1374]
    s.ax = m.r32((s.ax+0x00001374u));
  }
  { // 0x45247f: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x452482: 7437 JZ 0x004524bb
    if(integer::condition("JZ",flags)) goto L004524bb;
  }
  { // 0x452484: 8b0d5ce0a100 MOV ECX,dword ptr [0x00a1e05c]
    s.cx = m.r32((0x00a1e05cu));
  }
  { // 0x45248a: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x45248d: 8b4224 MOV EAX,dword ptr [EDX + 0x24]
    s.ax = m.r32((s.dx+0x00000024u));
  }
  { // 0x452490: 8b80c0000000 MOV EAX,dword ptr [EAX + 0xc0]
    s.ax = m.r32((s.ax+0x000000c0u));
  }
  { // 0x452496: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x452498: 7421 JZ 0x004524bb
    if(integer::condition("JZ",flags)) goto L004524bb;
  }
  { // 0x45249a: 8b88900b0000 MOV ECX,dword ptr [EAX + 0xb90]
    s.cx = m.r32((s.ax+0x00000b90u));
  }
  { // 0x4524a0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4524a1: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x4524a7: 81c160540000 ADD ECX,0x5460
    s.cx = integer::add(s.cx,0x00005460u,32,flags);
  }
  { // 0x4524ad: e83ef60300 CALL 0x00491af0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4524b2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4524b4: 7505 JNZ 0x004524bb
    if(integer::condition("JNZ",flags)) goto L004524bb;
  }
  { // 0x4524b6: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x4524b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4524ba: c3 RET
    finish(m,s,f,0u); return;
  }
  L004524bb: { // 0x4524bb: 8b9618040000 MOV EDX,dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  { // 0x4524c1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4524c2: 8b8274130000 MOV EAX,dword ptr [EDX + 0x1374]
    s.ax = m.r32((s.dx+0x00001374u));
  }
  { // 0x4524c8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000524d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4524d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4524d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4524d3: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  { // 0x4524d9: 8b8078130000 MOV EAX,dword ptr [EAX + 0x1378]
    s.ax = m.r32((s.ax+0x00001378u));
  }
  { // 0x4524df: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x4524e2: 7437 JZ 0x0045251b
    if(integer::condition("JZ",flags)) goto L0045251b;
  }
  { // 0x4524e4: 8b0d5ce0a100 MOV ECX,dword ptr [0x00a1e05c]
    s.cx = m.r32((0x00a1e05cu));
  }
  { // 0x4524ea: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x4524ed: 8b4224 MOV EAX,dword ptr [EDX + 0x24]
    s.ax = m.r32((s.dx+0x00000024u));
  }
  { // 0x4524f0: 8b80c0000000 MOV EAX,dword ptr [EAX + 0xc0]
    s.ax = m.r32((s.ax+0x000000c0u));
  }
  { // 0x4524f6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4524f8: 7421 JZ 0x0045251b
    if(integer::condition("JZ",flags)) goto L0045251b;
  }
  { // 0x4524fa: 8b88900b0000 MOV ECX,dword ptr [EAX + 0xb90]
    s.cx = m.r32((s.ax+0x00000b90u));
  }
  { // 0x452500: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x452501: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x452507: 81c160540000 ADD ECX,0x5460
    s.cx = integer::add(s.cx,0x00005460u,32,flags);
  }
  { // 0x45250d: e8def50300 CALL 0x00491af0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x452512: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x452514: 7505 JNZ 0x0045251b
    if(integer::condition("JNZ",flags)) goto L0045251b;
  }
  { // 0x452516: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x452519: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x45251a: c3 RET
    finish(m,s,f,0u); return;
  }
  L0045251b: { // 0x45251b: 8b9618040000 MOV EDX,dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  { // 0x452521: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x452522: 8b8278130000 MOV EAX,dword ptr [EDX + 0x1378]
    s.ax = m.r32((s.dx+0x00001378u));
  }
  { // 0x452528: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000539d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4539d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4539d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4539d3: 833e00 CMP dword ptr [ESI],0x0
    (void)integer::sub(m.r32((s.si)),0x00000000u,32,flags);
  }
  { // 0x4539d6: 750a JNZ 0x004539e2
    if(integer::condition("JNZ",flags)) goto L004539e2;
  }
  { // 0x4539d8: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x4539dd: e88ed83200 CALL 0x00781270
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L004539e2: { // 0x4539e2: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4539e4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4539e5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00057de0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x457de0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x457de4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x457de5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x457de7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x457de8: e8637e2700 CALL 0x006cfc50
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x457ded: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x457def: 8986980b0000 MOV dword ptr [ESI + 0xb98],EAX
    m.w32((s.si+0x00000b98u), s.ax);
  }
  { // 0x457df5: 898608140000 MOV dword ptr [ESI + 0x1408],EAX
    m.w32((s.si+0x00001408u), s.ax);
  }
  { // 0x457dfb: 89860c140000 MOV dword ptr [ESI + 0x140c],EAX
    m.w32((s.si+0x0000140cu), s.ax);
  }
  { // 0x457e01: c6861014000001 MOV byte ptr [ESI + 0x1410],0x1
    m.w8((s.si+0x00001410u), 0x00000001u);
  }
  { // 0x457e08: 888611140000 MOV byte ptr [ESI + 0x1411],AL
    m.w8((s.si+0x00001411u), (s.ax & 0xffu));
  }
  { // 0x457e0e: c78604140000c0827800 MOV dword ptr [ESI + 0x1404],0x7882c0
    m.w32((s.si+0x00001404u), 0x007882c0u);
  }
  { // 0x457e18: c706f8817800 MOV dword ptr [ESI],0x7881f8
    m.w32((s.si), 0x007881f8u);
  }
  { // 0x457e1e: c74604dc817800 MOV dword ptr [ESI + 0x4],0x7881dc
    m.w32((s.si+0x00000004u), 0x007881dcu);
  }
  { // 0x457e25: c74608d4817800 MOV dword ptr [ESI + 0x8],0x7881d4
    m.w32((s.si+0x00000008u), 0x007881d4u);
  }
  { // 0x457e2c: c7460ccc817800 MOV dword ptr [ESI + 0xc],0x7881cc
    m.w32((s.si+0x0000000cu), 0x007881ccu);
  }
  { // 0x457e33: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x457e35: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x457e36: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00068d10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x468d10: 8b4154 MOV EAX,dword ptr [ECX + 0x54]
    s.ax = m.r32((s.cx+0x00000054u));
  }
  { // 0x468d13: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x468d15: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x468d19: 7442 JZ 0x00468d5d
    if(integer::condition("JZ",flags)) goto L00468d5d;
  }
  { // 0x468d1b: 83e800 SUB EAX,0x0
    s.ax = integer::sub(s.ax,0x00000000u,32,flags);
  }
  { // 0x468d1e: 740d JZ 0x00468d2d
    if(integer::condition("JZ",flags)) goto L00468d2d;
  }
  { // 0x468d20: 83e802 SUB EAX,0x2
    s.ax = integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x468d23: 750f JNZ 0x00468d34
    if(integer::condition("JNZ",flags)) goto L00468d34;
  }
  { // 0x468d25: 8b4158 MOV EAX,dword ptr [ECX + 0x58]
    s.ax = m.r32((s.cx+0x00000058u));
  }
  { // 0x468d28: 894160 MOV dword ptr [ECX + 0x60],EAX
    m.w32((s.cx+0x00000060u), s.ax);
  }
  { // 0x468d2b: eb07 JMP 0x00468d34
    goto L00468d34;
  }
  L00468d2d: { // 0x468d2d: c7416000000000 MOV dword ptr [ECX + 0x60],0x0
    m.w32((s.cx+0x00000060u), 0x00000000u);
  }
  L00468d34: { // 0x468d34: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x468d38: 8b4160 MOV EAX,dword ptr [ECX + 0x60]
    s.ax = m.r32((s.cx+0x00000060u));
  }
  { // 0x468d3b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x468d3d: ba00000000 MOV EDX,0x0
    s.dx = 0x00000000u;
  }
  { // 0x468d42: 0f98c2 SETS DL
    s.dx = with_al(s.dx, (integer::condition("SETS",flags)?1u:0u));
  }
  { // 0x468d45: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x468d46: 894160 MOV dword ptr [ECX + 0x60],EAX
    m.w32((s.cx+0x00000060u), s.ax);
  }
  { // 0x468d49: 23c2 AND EAX,EDX
    s.ax = integer::logical((s.ax)&(s.dx),32,flags);
  }
  { // 0x468d4b: 894160 MOV dword ptr [ECX + 0x60],EAX
    m.w32((s.cx+0x00000060u), s.ax);
  }
  { // 0x468d4e: 8b5158 MOV EDX,dword ptr [ECX + 0x58]
    s.dx = m.r32((s.cx+0x00000058u));
  }
  { // 0x468d51: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x468d53: 7e02 JLE 0x00468d57
    if(integer::condition("JLE",flags)) goto L00468d57;
  }
  { // 0x468d55: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00468d57: { // 0x468d57: 894160 MOV dword ptr [ECX + 0x60],EAX
    m.w32((s.cx+0x00000060u), s.ax);
  }
  { // 0x468d5a: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00468d5d: { // 0x468d5d: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x468d61: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x468d62: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x468d63: e8286efcff CALL 0x0042fb90
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x468d68: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000698f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4698f0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x4698f4: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x4698f8: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x4698fa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4698fb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4698fc: e83f330a00 CALL 0x0050cc40
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x469901: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x469904: 7507 JNZ 0x0046990d
    if(integer::condition("JNZ",flags)) goto L0046990d;
  }
  { // 0x469906: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46990a: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0046990d: { // 0x46990d: 83f864 CMP EAX,0x64
    (void)integer::sub(s.ax,0x00000064u,32,flags);
  }
  { // 0x469910: 7c05 JL 0x00469917
    if(integer::condition("JL",flags)) goto L00469917;
  }
  { // 0x469912: b864000000 MOV EAX,0x64
    s.ax = 0x00000064u;
  }
  L00469917: { // 0x469917: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x469919: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46991b: 0f9ec1 SETLE CL
    s.cx = with_al(s.cx, (integer::condition("SETLE",flags)?1u:0u));
  }
  { // 0x46991e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x46991f: 23c8 AND ECX,EAX
    s.cx = integer::logical((s.cx)&(s.ax),32,flags);
  }
  { // 0x469921: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  { // 0x469926: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  { // 0x469929: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  { // 0x46992b: c1fa05 SAR EDX,0x5
    s.dx = integer::shift(s.dx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x46992e: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x469930: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  { // 0x469933: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x469935: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x469937: 3dff000000 CMP EAX,0xff
    (void)integer::sub(s.ax,0x000000ffu,32,flags);
  }
  { // 0x46993c: 7c05 JL 0x00469943
    if(integer::condition("JL",flags)) goto L00469943;
  }
  { // 0x46993e: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  L00469943: { // 0x469943: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00069c00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x469c00: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x469c04: 8b1504eaa900 MOV EDX,dword ptr [0x00a9ea04]
    s.dx = m.r32((0x00a9ea04u));
  }
  { // 0x469c0a: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x469c0d: 8b9004030000 MOV EDX,dword ptr [EAX + 0x304]
    s.dx = m.r32((s.ax+0x00000304u));
  }
  { // 0x469c13: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x469c17: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x469c18: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x469c1c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469c1d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x469c1e: e81d3e0a00 CALL 0x0050da40
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x469c23: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a900(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a900: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46a904: 8d1440 LEA EDX,[EAX + EAX*0x2]
    s.dx = (s.ax+(s.ax * 0x00000002u));
  }
  { // 0x46a907: 8d0490 LEA EAX,[EAX + EDX*0x4]
    s.ax = (s.ax+(s.dx * 0x00000004u));
  }
  { // 0x46a90a: 8d14c5685b7800 LEA EDX,[EAX*0x8 + 0x785b68]
    s.dx = ((s.ax * 0x00000008u)+0x00785b68u);
  }
  { // 0x46a911: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a915: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a916: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a91a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a91b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a91c: e81f310a00 CALL 0x0050da40
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x46a921: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006aa10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46aa10: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x46aa14: 8b1485505b7800 MOV EDX,dword ptr [EAX*0x4 + 0x785b50]
    s.dx = m.r32(((s.ax * 0x00000004u)+0x00785b50u));
  }
  { // 0x46aa1b: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x46aa1f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46aa20: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46aa24: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46aa25: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46aa26: e815300a00 CALL 0x0050da40
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x46aa2b: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006e0f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46e0f0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x46e0f4: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  { // 0x46e0f7: 7505 JNZ 0x0046e0fe
    if(integer::condition("JNZ",flags)) goto L0046e0fe;
  }
  { // 0x46e0f9: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x46e0fb: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0046e0fe: { // 0x46e0fe: 803d708b830001 CMP byte ptr [0x00838b70],0x1
    (void)integer::sub(m.r8((0x00838b70u)),0x00000001u,8,flags);
  }
  { // 0x46e105: 7505 JNZ 0x0046e10c
    if(integer::condition("JNZ",flags)) goto L0046e10c;
  }
  { // 0x46e107: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x46e109: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0046e10c: { // 0x46e10c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46e10d: c74104ffffffff MOV dword ptr [ECX + 0x4],0xffffffff
    m.w32((s.cx+0x00000004u), 0xffffffffu);
  }
  { // 0x46e114: e887a20200 CALL 0x004983a0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x46e119: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0006f990(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46f990: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46f991: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x46f993: e858f8fbff CALL 0x0042f1f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x46f998: c6465000 MOV byte ptr [ESI + 0x50],0x0
    m.w8((s.si+0x00000050u), 0x00000000u);
  }
  { // 0x46f99c: c70658567800 MOV dword ptr [ESI],0x785658
    m.w32((s.si), 0x00785658u);
  }
  { // 0x46f9a2: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x46f9a4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46f9a5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0006fa10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46fa10: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x46fa14: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46fa15: e826fcfbff CALL 0x0042f640
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x46fa1a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00075040(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x475040: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x475043: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x475044: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x475046: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x47504a: 8b5644 MOV EDX,dword ptr [ESI + 0x44]
    s.dx = m.r32((s.si+0x00000044u));
  }
  { // 0x47504d: e87ef61500 CALL 0x005d46d0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x475052: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x475054: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x475057: 8a8640010000 MOV AL,byte ptr [ESI + 0x140]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000140u)));
  }
  { // 0x47505d: a880 TEST AL,0x80
    (void)integer::logical(((s.ax & 0xffu))&(0x00000080u),8,flags);
  }
  { // 0x47505f: 7413 JZ 0x00475074
    if(integer::condition("JZ",flags)) goto L00475074;
  }
  { // 0x475061: 8a861e010000 MOV AL,byte ptr [ESI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011eu)));
  }
  { // 0x475067: 83e910 SUB ECX,0x10
    s.cx = integer::sub(s.cx,0x00000010u,32,flags);
  }
  { // 0x47506a: 3c09 CMP AL,0x9
    (void)integer::sub((s.ax & 0xffu),0x00000009u,8,flags);
  }
  { // 0x47506c: 7212 JC 0x00475080
    if(integer::condition("JC",flags)) goto L00475080;
  }
  { // 0x47506e: 3c11 CMP AL,0x11
    (void)integer::sub((s.ax & 0xffu),0x00000011u,8,flags);
  }
  { // 0x475070: 770e JA 0x00475080
    if(integer::condition("JA",flags)) goto L00475080;
  }
  { // 0x475072: eb09 JMP 0x0047507d
    goto L0047507d;
  }
  L00475074: { // 0x475074: 817e44ef000000 CMP dword ptr [ESI + 0x44],0xef
    (void)integer::sub(m.r32((s.si+0x00000044u)),0x000000efu,32,flags);
  }
  { // 0x47507b: 7503 JNZ 0x00475080
    if(integer::condition("JNZ",flags)) goto L00475080;
  }
  L0047507d: { // 0x47507d: 83e90f SUB ECX,0xf
    s.cx = integer::sub(s.cx,0x0000000fu,32,flags);
  }
  L00475080: { // 0x475080: 0fbe861b010000 MOVSX EAX,byte ptr [ESI + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  { // 0x475087: 8b3574198200 MOV ESI,dword ptr [0x00821974]
    s.si = m.r32((0x00821974u));
  }
  { // 0x47508d: 83c21e ADD EDX,0x1e
    s.dx = integer::add(s.dx,0x0000001eu,32,flags);
  }
  { // 0x475090: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  { // 0x475093: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  { // 0x475096: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x475098: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x47509c: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  { // 0x47509e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47509f: 83c10f ADD ECX,0xf
    s.cx = integer::add(s.cx,0x0000000fu,32,flags);
  }
  { // 0x4750a2: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  { // 0x4750a4: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  { // 0x4750a7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4750aa: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000750b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4750b0: 0fbf810c010000 MOVSX EAX,word ptr [ECX + 0x10c]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x0000010cu)),16));
  }
  { // 0x4750b7: 0fbe891b010000 MOVSX ECX,byte ptr [ECX + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  { // 0x4750be: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4750c0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4750c2: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x4750c6: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4750c8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4750ca: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4750cc: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4750ce: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4750cf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4750d0: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  { // 0x4750d2: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x4750d5: 8bc4 MOV EAX,ESP
    s.ax = f.sp;
  }
  { // 0x4750d7: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x4750d9: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  { // 0x4750dc: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  { // 0x4750df: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  { // 0x4750e2: 8b520c MOV EDX,dword ptr [EDX + 0xc]
    s.dx = m.r32((s.dx+0x0000000cu));
  }
  { // 0x4750e5: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  { // 0x4750e8: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  { // 0x4750eb: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  { // 0x4750ef: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x4750f2: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x4750f4: a19c1c8200 MOV EAX,[0x00821c9c]
    s.ax = m.r32((0x00821c9cu));
  }
  { // 0x4750f9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4750fa: 8b0ddca68100 MOV ECX,dword ptr [0x0081a6dc]
    s.cx = m.r32((0x0081a6dcu));
  }
  { // 0x475100: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x475101: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x475102: a11489a200 MOV EAX,[0x00a28914]
    s.ax = m.r32((0x00a28914u));
  }
  { // 0x475107: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x475109: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x47510b: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x47510d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x47510e: e87d530b00 CALL 0x0052a490
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x475113: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00075960(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x475960: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x475963: 8b4124 MOV EAX,dword ptr [ECX + 0x24]
    s.ax = m.r32((s.cx+0x00000024u));
  }
  { // 0x475966: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x475967: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x475968: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  { // 0x47596c: 0fbf7c240a MOVSX EDI,word ptr [ESP + 0xa]
    s.di = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000000au)),16));
  }
  { // 0x475971: 0fbff0 MOVSX ESI,AX
    s.si = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  { // 0x475974: c1e608 SHL ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::left);
  }
  { // 0x475977: b880000000 MOV EAX,0x80
    s.ax = 0x00000080u;
  }
  { // 0x47597c: c1e708 SHL EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::left);
  }
  { // 0x47597f: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  { // 0x475981: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  { // 0x475983: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  { // 0x475987: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  { // 0x47598b: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  { // 0x47598f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x475990: e82ba9ffff CALL 0x004702c0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x475995: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x475999: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x47599b: 8932 MOV dword ptr [EDX],ESI
    m.w32((s.dx), s.si);
  }
  { // 0x47599d: 897a04 MOV dword ptr [EDX + 0x4],EDI
    m.w32((s.dx+0x00000004u), s.di);
  }
  { // 0x4759a0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4759a1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4759a2: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  { // 0x4759a5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x4759a7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4759aa: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000766c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4766c0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4766c1: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x4766c5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x4766c7: 83fa08 CMP EDX,0x8
    (void)integer::sub(s.dx,0x00000008u,32,flags);
  }
  { // 0x4766ca: 7346 JNC 0x00476712
    if(integer::condition("JNC",flags)) goto L00476712;
  }
  { // 0x4766cc: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  { // 0x4766cf: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  { // 0x4766d2: 894c2400 MOV dword ptr [ESP],ECX
    m.w32((f.sp), s.cx);
  }
  { // 0x4766d6: 8d0495a09d8300 LEA EAX,[EDX*0x4 + 0x839da0]
    s.ax = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  { // 0x4766dd: 668b1495a09d8300 MOV DX,word ptr [EDX*0x4 + 0x839da0]
    s.dx = with_ax(s.dx, m.r16(((s.dx * 0x00000004u)+0x00839da0u)));
  }
  { // 0x4766e5: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  { // 0x4766e9: 6603442402 ADD AX,word ptr [ESP + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000002u)),16,flags));
  }
  { // 0x4766ee: 6603d1 ADD DX,CX
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.cx & 0xffffu),16,flags));
  }
  { // 0x4766f1: 6689542408 MOV word ptr [ESP + 0x8],DX
    m.w16((f.sp+0x00000008u), (s.dx & 0xffffu));
  }
  { // 0x4766f6: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x4766fa: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  { // 0x4766ff: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x476703: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  { // 0x476707: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x476708: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x47670d: e8eeed0c00 CALL 0x00545500
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L00476712: { // 0x476712: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x476713: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000782d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4782d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4782d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4782d3: f6864001000010 TEST byte ptr [ESI + 0x140],0x10
    (void)integer::logical((m.r8((s.si+0x00000140u)))&(0x00000010u),8,flags);
  }
  { // 0x4782da: 7532 JNZ 0x0047830e
    if(integer::condition("JNZ",flags)) goto L0047830e;
  }
  { // 0x4782dc: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4782de: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x4782e0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4782e2: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x4782e4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4782e6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4782e8: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4782ea: e871000000 CALL 0x00478360
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4782ef: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4782f1: 741b JZ 0x0047830e
    if(integer::condition("JZ",flags)) goto L0047830e;
  }
  { // 0x4782f3: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  { // 0x4782f9: 0c10 OR AL,0x10
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000010u),8,flags));
  }
  { // 0x4782fb: 898640010000 MOV dword ptr [ESI + 0x140],EAX
    m.w32((s.si+0x00000140u), s.ax);
  }
  { // 0x478301: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x478305: 894650 MOV dword ptr [ESI + 0x50],EAX
    m.w32((s.si+0x00000050u), s.ax);
  }
  { // 0x478308: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x47830a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47830b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0047830e: { // 0x47830e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x478310: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x478311: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00079e00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x479e00: 8b4944 MOV ECX,dword ptr [ECX + 0x44]
    s.cx = m.r32((s.cx+0x00000044u));
  }
  { // 0x479e03: e828a91500 CALL 0x005d4730
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x479e08: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x479e0b: 740d JZ 0x00479e1a
    if(integer::condition("JZ",flags)) goto L00479e1a;
  }
  { // 0x479e0d: 8b0d3c86aa00 MOV ECX,dword ptr [0x00aa863c]
    s.cx = m.r32((0x00aa863cu));
  }
  { // 0x479e13: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x479e16: 8b4260 MOV EAX,dword ptr [EDX + 0x60]
    s.ax = m.r32((s.dx+0x00000060u));
  }
  { // 0x479e19: c3 RET
    finish(m,s,f,0u); return;
  }
  L00479e1a: { // 0x479e1a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x479e1c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00079e30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x479e30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x479e31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x479e33: 8b4e44 MOV ECX,dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  { // 0x479e36: e8f5a81500 CALL 0x005d4730
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x479e3b: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x479e3e: 7504 JNZ 0x00479e44
    if(integer::condition("JNZ",flags)) goto L00479e44;
  }
  { // 0x479e40: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x479e42: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x479e43: c3 RET
    finish(m,s,f,0u); return;
  }
  L00479e44: { // 0x479e44: 8b0d3c86aa00 MOV ECX,dword ptr [0x00aa863c]
    s.cx = m.r32((0x00aa863cu));
  }
  { // 0x479e4a: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x479e4d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x479e4f: 8a861e010000 MOV AL,byte ptr [ESI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011eu)));
  }
  { // 0x479e55: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x479e56: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x479e58: 8b82b8000000 MOV EAX,dword ptr [EDX + 0xb8]
    s.ax = m.r32((s.dx+0x000000b8u));
  }
  { // 0x479e5e: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x479e5f: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  { // 0x479e62: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0007d570(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47d570: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47d571: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x47d575: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  { // 0x47d578: 7439 JZ 0x0047d5b3
    if(integer::condition("JZ",flags)) goto L0047d5b3;
  }
  { // 0x47d57a: 8b8184010000 MOV EAX,dword ptr [ECX + 0x184]
    s.ax = m.r32((s.cx+0x00000184u));
  }
  { // 0x47d580: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x47d582: 7d29 JGE 0x0047d5ad
    if(integer::condition("JGE",flags)) goto L0047d5ad;
  }
  { // 0x47d584: 8d50ff LEA EDX,[EAX + -0x1]
    s.dx = (s.ax-0x00000001u);
  }
  { // 0x47d587: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x47d589: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  { // 0x47d58b: 899184010000 MOV dword ptr [ECX + 0x184],EDX
    m.w32((s.cx+0x00000184u), s.dx);
  }
  { // 0x47d591: 7d1a JGE 0x0047d5ad
    if(integer::condition("JGE",flags)) goto L0047d5ad;
  }
  { // 0x47d593: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047d594: { // 0x47d594: 8b9178010000 MOV EDX,dword ptr [ECX + 0x178]
    s.dx = m.r32((s.cx+0x00000178u));
  }
  { // 0x47d59a: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x47d59b: 8b3c82 MOV EDI,dword ptr [EDX + EAX*0x4]
    s.di = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x47d59e: 897c82fc MOV dword ptr [EDX + EAX*0x4 + -0x4],EDI
    m.w32((s.dx+(s.ax * 0x00000004u)-0x00000004u), s.di);
  }
  { // 0x47d5a2: 8b9184010000 MOV EDX,dword ptr [ECX + 0x184]
    s.dx = m.r32((s.cx+0x00000184u));
  }
  { // 0x47d5a8: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x47d5aa: 7ce8 JL 0x0047d594
    if(integer::condition("JL",flags)) goto L0047d594;
  }
  { // 0x47d5ac: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047d5ad: { // 0x47d5ad: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47d5ae: e81dad0b00 CALL 0x005382d0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L0047d5b3: { // 0x47d5b3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47d5b4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00082b80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x482b80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x482b81: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x482b83: e8485e0700 CALL 0x004f89d0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x482b88: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x482b8a: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  { // 0x482b8d: 7409 JZ 0x00482b98
    if(integer::condition("JZ",flags)) goto L00482b98;
  }
  { // 0x482b8f: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x482b94: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x482b95: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x482b97: c3 RET
    finish(m,s,f,0u); return;
  }
  L00482b98: { // 0x482b98: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x482b9a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x482b9b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00083210(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x483210: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x483214: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x483218: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x483219: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x48321b: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x48321f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x483220: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x483224: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x483225: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x483229: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x48322a: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  { // 0x48322e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x48322f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x483230: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x483231: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x483233: e888b90400 CALL 0x004cebc0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x483238: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x48323c: c7462800000000 MOV dword ptr [ESI + 0x28],0x0
    m.w32((s.si+0x00000028u), 0x00000000u);
  }
  { // 0x483243: 894624 MOV dword ptr [ESI + 0x24],EAX
    m.w32((s.si+0x00000024u), s.ax);
  }
  { // 0x483246: c706a48e7800 MOV dword ptr [ESI],0x788ea4
    m.w32((s.si), 0x00788ea4u);
  }
  { // 0x48324c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x48324e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x48324f: c21c00 RET 0x1c
    finish(m,s,f,28u); return;
  }
}
void f_00093710(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x493710: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x493711: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x493713: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x493714: 668b460c MOV AX,word ptr [ESI + 0xc]
    s.ax = with_ax(s.ax, m.r16((s.si+0x0000000cu)));
  }
  { // 0x493718: 8d7e0c LEA EDI,[ESI + 0xc]
    s.di = (s.si+0x0000000cu);
  }
  { // 0x49371b: 663b05009f8300 CMP AX,word ptr [0x00839f00]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x00839f00u)),16,flags);
  }
  { // 0x493722: 750d JNZ 0x00493731
    if(integer::condition("JNZ",flags)) goto L00493731;
  }
  { // 0x493724: 668b4f02 MOV CX,word ptr [EDI + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.di+0x00000002u)));
  }
  { // 0x493728: 663b0d029f8300 CMP CX,word ptr [0x00839f02]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00839f02u)),16,flags);
  }
  { // 0x49372f: 744a JZ 0x0049377b
    if(integer::condition("JZ",flags)) goto L0049377b;
  }
  L00493731: { // 0x493731: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x493733: e828030000 CALL 0x00493a60
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x493738: 8b15009f8300 MOV EDX,dword ptr [0x00839f00]
    s.dx = m.r32((0x00839f00u));
  }
  { // 0x49373e: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  { // 0x493740: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x493742: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  { // 0x493745: 742f JZ 0x00493776
    if(integer::condition("JZ",flags)) goto L00493776;
  }
  { // 0x493747: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x49374a: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  { // 0x49374d: 741e JZ 0x0049376d
    if(integer::condition("JZ",flags)) goto L0049376d;
  }
  { // 0x49374f: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x493755: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x493757: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x493759: 7d10 JGE 0x0049376b
    if(integer::condition("JGE",flags)) goto L0049376b;
  }
  { // 0x49375b: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x49375d: c706ffffffff MOV dword ptr [ESI],0xffffffff
    m.w32((s.si), 0xffffffffu);
  }
  { // 0x493763: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x493766: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x493767: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x493769: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49376a: c3 RET
    finish(m,s,f,0u); return;
  }
  L0049376b: { // 0x49376b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0049376d: { // 0x49376d: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x493770: c706ffffffff MOV dword ptr [ESI],0xffffffff
    m.w32((s.si), 0xffffffffu);
  }
  L00493776: { // 0x493776: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x493777: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x493779: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49377a: c3 RET
    finish(m,s,f,0u); return;
  }
  L0049377b: { // 0x49377b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x49377c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x49377e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49377f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00094fb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x494fb0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x494fb4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x494fb5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x494fb7: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x494fb9: 740a JZ 0x00494fc5
    if(integer::condition("JZ",flags)) goto L00494fc5;
  }
  { // 0x494fbb: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x494fc0: e8abc22e00 CALL 0x00781270
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L00494fc5: { // 0x494fc5: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x494fc7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x494fc9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x494fcb: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x494fce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x494fcf: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00097140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x497140: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x497141: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x497142: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x497143: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x497144: 8b3d306d8300 MOV EDI,dword ptr [0x00836d30]
    s.di = m.r32((0x00836d30u));
  }
  { // 0x49714a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x49714c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x49714e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x49714f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x497151: e8faa3f9ff CALL 0x00431550
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x497156: 8b7f1c MOV EDI,dword ptr [EDI + 0x1c]
    s.di = m.r32((s.di+0x0000001cu));
  }
  { // 0x497159: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x49715b: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x49715f: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x497163: f6c601 TEST DH,0x1
    (void)integer::logical((((s.dx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x497166: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x497168: 740b JZ 0x00497175
    if(integer::condition("JZ",flags)) goto L00497175;
  }
  { // 0x49716a: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x49716c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x49716d: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x49716f: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x497171: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x497173: eb07 JMP 0x0049717c
    goto L0049717c;
  }
  L00497175: { // 0x497175: f6c602 TEST DH,0x2
    (void)integer::logical((((s.dx >> 8) & 0xffu))&(0x00000002u),8,flags);
  }
  { // 0x497178: 7404 JZ 0x0049717e
    if(integer::condition("JZ",flags)) goto L0049717e;
  }
  { // 0x49717a: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0049717c: { // 0x49717c: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0049717e: { // 0x49717e: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  { // 0x497182: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x497186: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  { // 0x49718a: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x49718c: 8d1453 LEA EDX,[EBX + EDX*0x2]
    s.dx = (s.bx+(s.dx * 0x00000002u));
  }
  { // 0x49718f: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  { // 0x497191: 2bcd SUB ECX,EBP
    s.cx = integer::sub(s.cx,s.bp,32,flags);
  }
  { // 0x497193: 8d3c6f LEA EDI,[EDI + EBP*0x2]
    s.di = (s.di+(s.bp * 0x00000002u));
  }
  { // 0x497196: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  { // 0x497198: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x49719a: 894b04 MOV dword ptr [EBX + 0x4],ECX
    m.w32((s.bx+0x00000004u), s.cx);
  }
  { // 0x49719d: 895308 MOV dword ptr [EBX + 0x8],EDX
    m.w32((s.bx+0x00000008u), s.dx);
  }
  { // 0x4971a0: 897b0c MOV dword ptr [EBX + 0xc],EDI
    m.w32((s.bx+0x0000000cu), s.di);
  }
  { // 0x4971a3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4971a4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4971a5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4971a6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4971a7: c21400 RET 0x14
    finish(m,s,f,20u); return;
  }
}
void f_00099800(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x499800: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x499804: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x499808: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x499809: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x49980a: e8416f0400 CALL 0x004e0750
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x49980f: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000a5750(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a5750: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a5751: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4a5753: e8485a0900 CALL 0x0053b1a0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4a5758: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4a575a: 8d4e20 LEA ECX,[ESI + 0x20]
    s.cx = (s.si+0x00000020u);
  }
  { // 0x4a575d: 88461c MOV byte ptr [ESI + 0x1c],AL
    m.w8((s.si+0x0000001cu), (s.ax & 0xffu));
  }
  { // 0x4a5760: 8b1550ad8300 MOV EDX,dword ptr [0x0083ad50]
    s.dx = m.r32((0x0083ad50u));
  }
  { // 0x4a5766: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  { // 0x4a5768: 8b1554ad8300 MOV EDX,dword ptr [0x0083ad54]
    s.dx = m.r32((0x0083ad54u));
  }
  { // 0x4a576e: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  { // 0x4a5771: 8b1558ad8300 MOV EDX,dword ptr [0x0083ad58]
    s.dx = m.r32((0x0083ad58u));
  }
  { // 0x4a5777: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  { // 0x4a577a: 89462c MOV dword ptr [ESI + 0x2c],EAX
    m.w32((s.si+0x0000002cu), s.ax);
  }
  { // 0x4a577d: c70658b97800 MOV dword ptr [ESI],0x78b958
    m.w32((s.si), 0x0078b958u);
  }
  { // 0x4a5783: c7460490b87800 MOV dword ptr [ESI + 0x4],0x78b890
    m.w32((s.si+0x00000004u), 0x0078b890u);
  }
  { // 0x4a578a: c746186cb87800 MOV dword ptr [ESI + 0x18],0x78b86c
    m.w32((s.si+0x00000018u), 0x0078b86cu);
  }
  { // 0x4a5791: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4a5793: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a5794: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000b4610(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b4610: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  { // 0x4b4613: 8b09 MOV ECX,dword ptr [ECX]
    s.cx = m.r32((s.cx));
  }
  { // 0x4b4615: 83c024 ADD EAX,0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  { // 0x4b4618: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4b4619: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4b461a: 6840167c00 PUSH 0x7c1640
    f.push(m,0x007c1640u);
  }
  { // 0x4b461f: 6890dc8300 PUSH 0x83dc90
    f.push(m,0x0083dc90u);
  }
  { // 0x4b4624: e80b942b00 CALL 0x0076da34
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4b4629: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x4b462c: b890dc8300 MOV EAX,0x83dc90
    s.ax = 0x0083dc90u;
  }
  { // 0x4b4631: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000b49d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b49d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4b49d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4b49d3: e838b5f5ff CALL 0x0040ff10
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4b49d8: a120dd8300 MOV EAX,[0x0083dd20]
    s.ax = m.r32((0x0083dd20u));
  }
  { // 0x4b49dd: c706b8bd7800 MOV dword ptr [ESI],0x78bdb8
    m.w32((s.si), 0x0078bdb8u);
  }
  { // 0x4b49e3: 894624 MOV dword ptr [ESI + 0x24],EAX
    m.w32((s.si+0x00000024u), s.ax);
  }
  { // 0x4b49e6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4b49e8: 894628 MOV dword ptr [ESI + 0x28],EAX
    m.w32((s.si+0x00000028u), s.ax);
  }
  { // 0x4b49eb: 89462c MOV dword ptr [ESI + 0x2c],EAX
    m.w32((s.si+0x0000002cu), s.ax);
  }
  { // 0x4b49ee: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  { // 0x4b49f1: c746049cbd7800 MOV dword ptr [ESI + 0x4],0x78bd9c
    m.w32((s.si+0x00000004u), 0x0078bd9cu);
  }
  { // 0x4b49f8: c7460894bd7800 MOV dword ptr [ESI + 0x8],0x78bd94
    m.w32((s.si+0x00000008u), 0x0078bd94u);
  }
  { // 0x4b49ff: c7460c8cbd7800 MOV dword ptr [ESI + 0xc],0x78bd8c
    m.w32((s.si+0x0000000cu), 0x0078bd8cu);
  }
  { // 0x4b4a06: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b4a08: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b4a09: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000b5c00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b5c00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4b5c01: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4b5c05: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x4b5c07: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4b5c08: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x4b5c0d: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4b5c0f: 8b0c85fc167c00 MOV ECX,dword ptr [EAX*0x4 + 0x7c16fc]
    s.cx = m.r32(((s.ax * 0x00000004u)+0x007c16fcu));
  }
  { // 0x4b5c16: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4b5c17: 68c0197c00 PUSH 0x7c19c0
    f.push(m,0x007c19c0u);
  }
  { // 0x4b5c1c: e8cf0cf5ff CALL 0x004068f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4b5c21: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x4b5c25: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4b5c28: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b5c2a: 7c25 JL 0x004b5c51
    if(integer::condition("JL",flags)) goto L004b5c51;
  }
  { // 0x4b5c2c: 8a4c2418 MOV CL,byte ptr [ESP + 0x18]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000018u)));
  }
  { // 0x4b5c30: 884602 MOV byte ptr [ESI + 0x2],AL
    m.w8((s.si+0x00000002u), (s.ax & 0xffu));
  }
  { // 0x4b5c33: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x4b5c37: 8d5607 LEA EDX,[ESI + 0x7]
    s.dx = (s.si+0x00000007u);
  }
  { // 0x4b5c3a: 881e MOV byte ptr [ESI],BL
    m.w8((s.si), (s.bx & 0xffu));
  }
  { // 0x4b5c3c: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  { // 0x4b5c3e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b5c40: 884a04 MOV byte ptr [EDX + 0x4],CL
    m.w8((s.dx+0x00000004u), (s.cx & 0xffu));
  }
  { // 0x4b5c43: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  { // 0x4b5c49: 895603 MOV dword ptr [ESI + 0x3],EDX
    m.w32((s.si+0x00000003u), s.dx);
  }
  { // 0x4b5c4c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b5c4d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4b5c4e: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L004b5c51: { // 0x4b5c51: c64602ff MOV byte ptr [ESI + 0x2],0xff
    m.w8((s.si+0x00000002u), 0x000000ffu);
  }
  { // 0x4b5c55: c60600 MOV byte ptr [ESI],0x0
    m.w8((s.si), 0x00000000u);
  }
  { // 0x4b5c58: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  { // 0x4b5c5d: 894603 MOV dword ptr [ESI + 0x3],EAX
    m.w32((s.si+0x00000003u), s.ax);
  }
  { // 0x4b5c60: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b5c62: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b5c63: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4b5c64: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_000b5c70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b5c70: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4b5c71: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4b5c75: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x4b5c77: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4b5c78: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x4b5c7d: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4b5c7f: 8b0c85fc167c00 MOV ECX,dword ptr [EAX*0x4 + 0x7c16fc]
    s.cx = m.r32(((s.ax * 0x00000004u)+0x007c16fcu));
  }
  { // 0x4b5c86: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4b5c87: 68c0197c00 PUSH 0x7c19c0
    f.push(m,0x007c19c0u);
  }
  { // 0x4b5c8c: e85f0cf5ff CALL 0x004068f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4b5c91: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x4b5c95: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4b5c98: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b5c9a: 7c28 JL 0x004b5cc4
    if(integer::condition("JL",flags)) goto L004b5cc4;
  }
  { // 0x4b5c9c: 884602 MOV byte ptr [ESI + 0x2],AL
    m.w8((s.si+0x00000002u), (s.ax & 0xffu));
  }
  { // 0x4b5c9f: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x4b5ca3: 881e MOV byte ptr [ESI],BL
    m.w8((s.si), (s.bx & 0xffu));
  }
  { // 0x4b5ca5: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  { // 0x4b5ca8: 66895607 MOV word ptr [ESI + 0x7],DX
    m.w16((s.si+0x00000007u), (s.dx & 0xffffu));
  }
  { // 0x4b5cac: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  { // 0x4b5cb0: 66894609 MOV word ptr [ESI + 0x9],AX
    m.w16((s.si+0x00000009u), (s.ax & 0xffffu));
  }
  { // 0x4b5cb4: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x4b5cba: 894e03 MOV dword ptr [ESI + 0x3],ECX
    m.w32((s.si+0x00000003u), s.cx);
  }
  { // 0x4b5cbd: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b5cbf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b5cc0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4b5cc1: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L004b5cc4: { // 0x4b5cc4: c64602ff MOV byte ptr [ESI + 0x2],0xff
    m.w8((s.si+0x00000002u), 0x000000ffu);
  }
  { // 0x4b5cc8: c60600 MOV byte ptr [ESI],0x0
    m.w8((s.si), 0x00000000u);
  }
  { // 0x4b5ccb: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  { // 0x4b5cd1: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b5cd3: 895603 MOV dword ptr [ESI + 0x3],EDX
    m.w32((s.si+0x00000003u), s.dx);
  }
  { // 0x4b5cd6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b5cd7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4b5cd8: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_000b5ce0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b5ce0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4b5ce1: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4b5ce5: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x4b5ce7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4b5ce8: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x4b5ced: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4b5cef: 8b0c85fc167c00 MOV ECX,dword ptr [EAX*0x4 + 0x7c16fc]
    s.cx = m.r32(((s.ax * 0x00000004u)+0x007c16fcu));
  }
  { // 0x4b5cf6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4b5cf7: 68c0197c00 PUSH 0x7c19c0
    f.push(m,0x007c19c0u);
  }
  { // 0x4b5cfc: e8ef0bf5ff CALL 0x004068f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4b5d01: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x4b5d05: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4b5d08: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b5d0a: 7c15 JL 0x004b5d21
    if(integer::condition("JL",flags)) goto L004b5d21;
  }
  { // 0x4b5d0c: 884602 MOV byte ptr [ESI + 0x2],AL
    m.w8((s.si+0x00000002u), (s.ax & 0xffu));
  }
  { // 0x4b5d0f: 881e MOV byte ptr [ESI],BL
    m.w8((s.si), (s.bx & 0xffu));
  }
  { // 0x4b5d11: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  { // 0x4b5d17: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b5d19: 895603 MOV dword ptr [ESI + 0x3],EDX
    m.w32((s.si+0x00000003u), s.dx);
  }
  { // 0x4b5d1c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b5d1d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4b5d1e: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L004b5d21: { // 0x4b5d21: c64602ff MOV byte ptr [ESI + 0x2],0xff
    m.w8((s.si+0x00000002u), 0x000000ffu);
  }
  { // 0x4b5d25: c60600 MOV byte ptr [ESI],0x0
    m.w8((s.si), 0x00000000u);
  }
  { // 0x4b5d28: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  { // 0x4b5d2d: 894603 MOV dword ptr [ESI + 0x3],EAX
    m.w32((s.si+0x00000003u), s.ax);
  }
  { // 0x4b5d30: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b5d32: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b5d33: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4b5d34: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000b5d40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b5d40: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4b5d41: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4b5d45: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x4b5d47: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4b5d48: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x4b5d4d: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4b5d4f: 8b0c85fc167c00 MOV ECX,dword ptr [EAX*0x4 + 0x7c16fc]
    s.cx = m.r32(((s.ax * 0x00000004u)+0x007c16fcu));
  }
  { // 0x4b5d56: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4b5d57: 68c0197c00 PUSH 0x7c19c0
    f.push(m,0x007c19c0u);
  }
  { // 0x4b5d5c: e88f0bf5ff CALL 0x004068f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4b5d61: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x4b5d65: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4b5d68: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b5d6a: 7c1b JL 0x004b5d87
    if(integer::condition("JL",flags)) goto L004b5d87;
  }
  { // 0x4b5d6c: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x4b5d70: 884602 MOV byte ptr [ESI + 0x2],AL
    m.w8((s.si+0x00000002u), (s.ax & 0xffu));
  }
  { // 0x4b5d73: 881e MOV byte ptr [ESI],BL
    m.w8((s.si), (s.bx & 0xffu));
  }
  { // 0x4b5d75: 895607 MOV dword ptr [ESI + 0x7],EDX
    m.w32((s.si+0x00000007u), s.dx);
  }
  { // 0x4b5d78: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  { // 0x4b5d7d: 894603 MOV dword ptr [ESI + 0x3],EAX
    m.w32((s.si+0x00000003u), s.ax);
  }
  { // 0x4b5d80: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b5d82: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b5d83: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4b5d84: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L004b5d87: { // 0x4b5d87: c64602ff MOV byte ptr [ESI + 0x2],0xff
    m.w8((s.si+0x00000002u), 0x000000ffu);
  }
  { // 0x4b5d8b: c60600 MOV byte ptr [ESI],0x0
    m.w8((s.si), 0x00000000u);
  }
  { // 0x4b5d8e: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x4b5d94: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b5d96: 894e03 MOV dword ptr [ESI + 0x3],ECX
    m.w32((s.si+0x00000003u), s.cx);
  }
  { // 0x4b5d99: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b5d9a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4b5d9b: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_000b5da0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b5da0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4b5da1: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4b5da5: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x4b5da7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4b5da8: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x4b5dad: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4b5daf: 8b0c85fc167c00 MOV ECX,dword ptr [EAX*0x4 + 0x7c16fc]
    s.cx = m.r32(((s.ax * 0x00000004u)+0x007c16fcu));
  }
  { // 0x4b5db6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4b5db7: 68c0197c00 PUSH 0x7c19c0
    f.push(m,0x007c19c0u);
  }
  { // 0x4b5dbc: e82f0bf5ff CALL 0x004068f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4b5dc1: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x4b5dc5: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4b5dc8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b5dca: 7c36 JL 0x004b5e02
    if(integer::condition("JL",flags)) goto L004b5e02;
  }
  { // 0x4b5dcc: 8a4c2418 MOV CL,byte ptr [ESP + 0x18]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000018u)));
  }
  { // 0x4b5dd0: 884602 MOV byte ptr [ESI + 0x2],AL
    m.w8((s.si+0x00000002u), (s.ax & 0xffu));
  }
  { // 0x4b5dd3: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x4b5dd7: 8d5607 LEA EDX,[ESI + 0x7]
    s.dx = (s.si+0x00000007u);
  }
  { // 0x4b5dda: 881e MOV byte ptr [ESI],BL
    m.w8((s.si), (s.bx & 0xffu));
  }
  { // 0x4b5ddc: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  { // 0x4b5dde: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x4b5de2: 884a04 MOV byte ptr [EDX + 0x4],CL
    m.w8((s.dx+0x00000004u), (s.cx & 0xffu));
  }
  { // 0x4b5de5: 8a4c2420 MOV CL,byte ptr [ESP + 0x20]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000020u)));
  }
  { // 0x4b5de9: 8d560c LEA EDX,[ESI + 0xc]
    s.dx = (s.si+0x0000000cu);
  }
  { // 0x4b5dec: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  { // 0x4b5def: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b5df1: 884a04 MOV byte ptr [EDX + 0x4],CL
    m.w8((s.dx+0x00000004u), (s.cx & 0xffu));
  }
  { // 0x4b5df4: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  { // 0x4b5dfa: 895603 MOV dword ptr [ESI + 0x3],EDX
    m.w32((s.si+0x00000003u), s.dx);
  }
  { // 0x4b5dfd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b5dfe: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4b5dff: c21800 RET 0x18
    finish(m,s,f,24u); return;
  }
  L004b5e02: { // 0x4b5e02: c64602ff MOV byte ptr [ESI + 0x2],0xff
    m.w8((s.si+0x00000002u), 0x000000ffu);
  }
  { // 0x4b5e06: c60600 MOV byte ptr [ESI],0x0
    m.w8((s.si), 0x00000000u);
  }
  { // 0x4b5e09: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  { // 0x4b5e0e: 894603 MOV dword ptr [ESI + 0x3],EAX
    m.w32((s.si+0x00000003u), s.ax);
  }
  { // 0x4b5e11: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b5e13: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b5e14: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4b5e15: c21800 RET 0x18
    finish(m,s,f,24u); return;
  }
}
void f_000b5e20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b5e20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4b5e21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4b5e23: 68d4197c00 PUSH 0x7c19d4
    f.push(m,0x007c19d4u);
  }
  { // 0x4b5e28: e8c30af5ff CALL 0x004068f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4b5e2d: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4b5e31: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4b5e34: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b5e36: 7c32 JL 0x004b5e6a
    if(integer::condition("JL",flags)) goto L004b5e6a;
  }
  { // 0x4b5e38: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x4b5e3c: 884602 MOV byte ptr [ESI + 0x2],AL
    m.w8((s.si+0x00000002u), (s.ax & 0xffu));
  }
  { // 0x4b5e3f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4b5e43: c60614 MOV byte ptr [ESI],0x14
    m.w8((s.si), 0x00000014u);
  }
  { // 0x4b5e46: 894607 MOV dword ptr [ESI + 0x7],EAX
    m.w32((s.si+0x00000007u), s.ax);
  }
  { // 0x4b5e49: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x4b5e4d: 894e0b MOV dword ptr [ESI + 0xb],ECX
    m.w32((s.si+0x0000000bu), s.cx);
  }
  { // 0x4b5e50: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x4b5e52: 89560f MOV dword ptr [ESI + 0xf],EDX
    m.w32((s.si+0x0000000fu), s.dx);
  }
  { // 0x4b5e55: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  { // 0x4b5e58: 894613 MOV dword ptr [ESI + 0x13],EAX
    m.w32((s.si+0x00000013u), s.ax);
  }
  { // 0x4b5e5b: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x4b5e61: 894e03 MOV dword ptr [ESI + 0x3],ECX
    m.w32((s.si+0x00000003u), s.cx);
  }
  { // 0x4b5e64: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b5e66: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b5e67: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L004b5e6a: { // 0x4b5e6a: c64602ff MOV byte ptr [ESI + 0x2],0xff
    m.w8((s.si+0x00000002u), 0x000000ffu);
  }
  { // 0x4b5e6e: c60600 MOV byte ptr [ESI],0x0
    m.w8((s.si), 0x00000000u);
  }
  { // 0x4b5e71: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  { // 0x4b5e77: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b5e79: 895603 MOV dword ptr [ESI + 0x3],EDX
    m.w32((s.si+0x00000003u), s.dx);
  }
  { // 0x4b5e7c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b5e7d: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_000b6100(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b6100: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4b6101: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4b6105: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x4b6107: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4b6108: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x4b610d: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4b610f: 8b0c85fc167c00 MOV ECX,dword ptr [EAX*0x4 + 0x7c16fc]
    s.cx = m.r32(((s.ax * 0x00000004u)+0x007c16fcu));
  }
  { // 0x4b6116: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4b6117: 68c0197c00 PUSH 0x7c19c0
    f.push(m,0x007c19c0u);
  }
  { // 0x4b611c: e8cf07f5ff CALL 0x004068f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4b6121: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x4b6125: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4b6128: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b612a: 7c3d JL 0x004b6169
    if(integer::condition("JL",flags)) goto L004b6169;
  }
  { // 0x4b612c: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x4b6130: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x4b6134: 884602 MOV byte ptr [ESI + 0x2],AL
    m.w8((s.si+0x00000002u), (s.ax & 0xffu));
  }
  { // 0x4b6137: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x4b613b: 89460b MOV dword ptr [ESI + 0xb],EAX
    m.w32((s.si+0x0000000bu), s.ax);
  }
  { // 0x4b613e: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  { // 0x4b6142: 881e MOV byte ptr [ESI],BL
    m.w8((s.si), (s.bx & 0xffu));
  }
  { // 0x4b6144: 895607 MOV dword ptr [ESI + 0x7],EDX
    m.w32((s.si+0x00000007u), s.dx);
  }
  { // 0x4b6147: 894e0f MOV dword ptr [ESI + 0xf],ECX
    m.w32((s.si+0x0000000fu), s.cx);
  }
  { // 0x4b614a: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  { // 0x4b614d: 66895613 MOV word ptr [ESI + 0x13],DX
    m.w16((s.si+0x00000013u), (s.dx & 0xffffu));
  }
  { // 0x4b6151: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  { // 0x4b6155: 66894615 MOV word ptr [ESI + 0x15],AX
    m.w16((s.si+0x00000015u), (s.ax & 0xffffu));
  }
  { // 0x4b6159: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x4b615f: 894e03 MOV dword ptr [ESI + 0x3],ECX
    m.w32((s.si+0x00000003u), s.cx);
  }
  { // 0x4b6162: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b6164: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b6165: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4b6166: c21800 RET 0x18
    finish(m,s,f,24u); return;
  }
  L004b6169: { // 0x4b6169: c64602ff MOV byte ptr [ESI + 0x2],0xff
    m.w8((s.si+0x00000002u), 0x000000ffu);
  }
  { // 0x4b616d: c60600 MOV byte ptr [ESI],0x0
    m.w8((s.si), 0x00000000u);
  }
  { // 0x4b6170: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  { // 0x4b6176: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b6178: 895603 MOV dword ptr [ESI + 0x3],EDX
    m.w32((s.si+0x00000003u), s.dx);
  }
  { // 0x4b617b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b617c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4b617d: c21800 RET 0x18
    finish(m,s,f,24u); return;
  }
}
void f_000b6180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b6180: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4b6181: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4b6185: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x4b6187: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4b6188: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x4b618d: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4b618f: 8b0c85fc167c00 MOV ECX,dword ptr [EAX*0x4 + 0x7c16fc]
    s.cx = m.r32(((s.ax * 0x00000004u)+0x007c16fcu));
  }
  { // 0x4b6196: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4b6197: 68c0197c00 PUSH 0x7c19c0
    f.push(m,0x007c19c0u);
  }
  { // 0x4b619c: e84f07f5ff CALL 0x004068f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4b61a1: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x4b61a5: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4b61a8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b61aa: 7c2e JL 0x004b61da
    if(integer::condition("JL",flags)) goto L004b61da;
  }
  { // 0x4b61ac: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x4b61b0: 884602 MOV byte ptr [ESI + 0x2],AL
    m.w8((s.si+0x00000002u), (s.ax & 0xffu));
  }
  { // 0x4b61b3: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x4b61b7: 881e MOV byte ptr [ESI],BL
    m.w8((s.si), (s.bx & 0xffu));
  }
  { // 0x4b61b9: 895607 MOV dword ptr [ESI + 0x7],EDX
    m.w32((s.si+0x00000007u), s.dx);
  }
  { // 0x4b61bc: 668b08 MOV CX,word ptr [EAX]
    s.cx = with_ax(s.cx, m.r16((s.ax)));
  }
  { // 0x4b61bf: 66894e0b MOV word ptr [ESI + 0xb],CX
    m.w16((s.si+0x0000000bu), (s.cx & 0xffffu));
  }
  { // 0x4b61c3: 668b5002 MOV DX,word ptr [EAX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x00000002u)));
  }
  { // 0x4b61c7: 6689560d MOV word ptr [ESI + 0xd],DX
    m.w16((s.si+0x0000000du), (s.dx & 0xffffu));
  }
  { // 0x4b61cb: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  { // 0x4b61d0: 894603 MOV dword ptr [ESI + 0x3],EAX
    m.w32((s.si+0x00000003u), s.ax);
  }
  { // 0x4b61d3: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b61d5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b61d6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4b61d7: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L004b61da: { // 0x4b61da: c64602ff MOV byte ptr [ESI + 0x2],0xff
    m.w8((s.si+0x00000002u), 0x000000ffu);
  }
  { // 0x4b61de: c60600 MOV byte ptr [ESI],0x0
    m.w8((s.si), 0x00000000u);
  }
  { // 0x4b61e1: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x4b61e7: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b61e9: 894e03 MOV dword ptr [ESI + 0x3],ECX
    m.w32((s.si+0x00000003u), s.cx);
  }
  { // 0x4b61ec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b61ed: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4b61ee: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_000b6270(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b6270: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4b6274: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x4b6277: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4b6279: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4b627a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4b627c: 7c39 JL 0x004b62b7
    if(integer::condition("JL",flags)) goto L004b62b7;
  }
  { // 0x4b627e: 884602 MOV byte ptr [ESI + 0x2],AL
    m.w8((s.si+0x00000002u), (s.ax & 0xffu));
  }
  { // 0x4b6281: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x4b6285: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x4b6289: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4b628a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4b628b: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x4b628f: c60629 MOV byte ptr [ESI],0x29
    m.w8((s.si), 0x00000029u);
  }
  { // 0x4b6292: e8c9c70600 CALL 0x00522a60
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4b6297: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x4b629b: 8a442418 MOV AL,byte ptr [ESP + 0x18]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000018u)));
  }
  { // 0x4b629f: 895608 MOV dword ptr [ESI + 0x8],EDX
    m.w32((s.si+0x00000008u), s.dx);
  }
  { // 0x4b62a2: 884607 MOV byte ptr [ESI + 0x7],AL
    m.w8((s.si+0x00000007u), (s.ax & 0xffu));
  }
  { // 0x4b62a5: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x4b62ab: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b62ad: 894e03 MOV dword ptr [ESI + 0x3],ECX
    m.w32((s.si+0x00000003u), s.cx);
  }
  { // 0x4b62b0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b62b1: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4b62b4: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L004b62b7: { // 0x4b62b7: c64602ff MOV byte ptr [ESI + 0x2],0xff
    m.w8((s.si+0x00000002u), 0x000000ffu);
  }
  { // 0x4b62bb: c60600 MOV byte ptr [ESI],0x0
    m.w8((s.si), 0x00000000u);
  }
  { // 0x4b62be: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  { // 0x4b62c4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4b62c6: 895603 MOV dword ptr [ESI + 0x3],EDX
    m.w32((s.si+0x00000003u), s.dx);
  }
  { // 0x4b62c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4b62ca: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4b62cd: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_000b93f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4b93f0: 8b4954 MOV ECX,dword ptr [ECX + 0x54]
    s.cx = m.r32((s.cx+0x00000054u));
  }
  { // 0x4b93f3: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x4b93f5: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4b93f7: 7407 JZ 0x004b9400
    if(integer::condition("JZ",flags)) goto L004b9400;
  }
  { // 0x4b93f9: e812e51f00 CALL 0x006b7910
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4b93fe: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004b9400: { // 0x4b9400: b8f712da4b MOV EAX,0x4bda12f7
    s.ax = 0x4bda12f7u;
  }
  { // 0x4b9405: f7ea IMUL EDX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.dx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  { // 0x4b9407: c1fa04 SAR EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x4b940a: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x4b940c: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  { // 0x4b940f: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x4b9411: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x4b9413: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x4b9416: 7d06 JGE 0x004b941e
    if(integer::condition("JGE",flags)) goto L004b941e;
  }
  { // 0x4b9418: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x4b941d: c3 RET
    finish(m,s,f,0u); return;
  }
  L004b941e: { // 0x4b941e: 3dff000000 CMP EAX,0xff
    (void)integer::sub(s.ax,0x000000ffu,32,flags);
  }
  { // 0x4b9423: 7e05 JLE 0x004b942a
    if(integer::condition("JLE",flags)) goto L004b942a;
  }
  { // 0x4b9425: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  L004b942a: { // 0x4b942a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000bbd80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4bbd80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bbd81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4bbd83: e818f40700 CALL 0x0053b1a0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4bbd88: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4bbd8a: 8d4e1c LEA ECX,[ESI + 0x1c]
    s.cx = (s.si+0x0000001cu);
  }
  { // 0x4bbd8d: 884618 MOV byte ptr [ESI + 0x18],AL
    m.w8((s.si+0x00000018u), (s.ax & 0xffu));
  }
  { // 0x4bbd90: 8b1528e18400 MOV EDX,dword ptr [0x0084e128]
    s.dx = m.r32((0x0084e128u));
  }
  { // 0x4bbd96: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  { // 0x4bbd98: 8b152ce18400 MOV EDX,dword ptr [0x0084e12c]
    s.dx = m.r32((0x0084e12cu));
  }
  { // 0x4bbd9e: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  { // 0x4bbda1: 8b1530e18400 MOV EDX,dword ptr [0x0084e130]
    s.dx = m.r32((0x0084e130u));
  }
  { // 0x4bbda7: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  { // 0x4bbdaa: 8b1528e18400 MOV EDX,dword ptr [0x0084e128]
    s.dx = m.r32((0x0084e128u));
  }
  { // 0x4bbdb0: 8d4e28 LEA ECX,[ESI + 0x28]
    s.cx = (s.si+0x00000028u);
  }
  { // 0x4bbdb3: 895628 MOV dword ptr [ESI + 0x28],EDX
    m.w32((s.si+0x00000028u), s.dx);
  }
  { // 0x4bbdb6: 8b152ce18400 MOV EDX,dword ptr [0x0084e12c]
    s.dx = m.r32((0x0084e12cu));
  }
  { // 0x4bbdbc: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  { // 0x4bbdbf: 8b1530e18400 MOV EDX,dword ptr [0x0084e130]
    s.dx = m.r32((0x0084e130u));
  }
  { // 0x4bbdc5: 894640 MOV dword ptr [ESI + 0x40],EAX
    m.w32((s.si+0x00000040u), s.ax);
  }
  { // 0x4bbdc8: 894648 MOV dword ptr [ESI + 0x48],EAX
    m.w32((s.si+0x00000048u), s.ax);
  }
  { // 0x4bbdcb: 884634 MOV byte ptr [ESI + 0x34],AL
    m.w8((s.si+0x00000034u), (s.ax & 0xffu));
  }
  { // 0x4bbdce: 894638 MOV dword ptr [ESI + 0x38],EAX
    m.w32((s.si+0x00000038u), s.ax);
  }
  { // 0x4bbdd1: 894644 MOV dword ptr [ESI + 0x44],EAX
    m.w32((s.si+0x00000044u), s.ax);
  }
  { // 0x4bbdd4: 89464c MOV dword ptr [ESI + 0x4c],EAX
    m.w32((s.si+0x0000004cu), s.ax);
  }
  { // 0x4bbdd7: 884650 MOV byte ptr [ESI + 0x50],AL
    m.w8((s.si+0x00000050u), (s.ax & 0xffu));
  }
  { // 0x4bbdda: 884651 MOV byte ptr [ESI + 0x51],AL
    m.w8((s.si+0x00000051u), (s.ax & 0xffu));
  }
  { // 0x4bbddd: 884652 MOV byte ptr [ESI + 0x52],AL
    m.w8((s.si+0x00000052u), (s.ax & 0xffu));
  }
  { // 0x4bbde0: 884653 MOV byte ptr [ESI + 0x53],AL
    m.w8((s.si+0x00000053u), (s.ax & 0xffu));
  }
  { // 0x4bbde3: 894654 MOV dword ptr [ESI + 0x54],EAX
    m.w32((s.si+0x00000054u), s.ax);
  }
  { // 0x4bbde6: 894658 MOV dword ptr [ESI + 0x58],EAX
    m.w32((s.si+0x00000058u), s.ax);
  }
  { // 0x4bbde9: 88465c MOV byte ptr [ESI + 0x5c],AL
    m.w8((s.si+0x0000005cu), (s.ax & 0xffu));
  }
  { // 0x4bbdec: c706ccc07800 MOV dword ptr [ESI],0x78c0cc
    m.w32((s.si), 0x0078c0ccu);
  }
  { // 0x4bbdf2: c7460404c07800 MOV dword ptr [ESI + 0x4],0x78c004
    m.w32((s.si+0x00000004u), 0x0078c004u);
  }
  { // 0x4bbdf9: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4bbdfb: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  { // 0x4bbdfe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bbdff: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000bf800(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4bf800: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4bf804: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bf805: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4bf807: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4bf809: 740a JZ 0x004bf815
    if(integer::condition("JZ",flags)) goto L004bf815;
  }
  { // 0x4bf80b: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x4bf810: e85b1a2c00 CALL 0x00781270
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L004bf815: { // 0x4bf815: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x4bf817: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4bf819: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4bf81b: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x4bf81e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bf81f: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000c28d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c28d0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4c28d4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c28d5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4c28d7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4c28d8: e8a34c1f00 CALL 0x006b7580
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4c28dd: b87cc77800 MOV EAX,0x78c77c
    s.ax = 0x0078c77cu;
  }
  { // 0x4c28e2: 898678040000 MOV dword ptr [ESI + 0x478],EAX
    m.w32((s.si+0x00000478u), s.ax);
  }
  { // 0x4c28e8: 89869c040000 MOV dword ptr [ESI + 0x49c],EAX
    m.w32((s.si+0x0000049cu), s.ax);
  }
  { // 0x4c28ee: c7866405000000000000 MOV dword ptr [ESI + 0x564],0x0
    m.w32((s.si+0x00000564u), 0x00000000u);
  }
  { // 0x4c28f8: c706a0c27800 MOV dword ptr [ESI],0x78c2a0
    m.w32((s.si), 0x0078c2a0u);
  }
  { // 0x4c28fe: c7460484c27800 MOV dword ptr [ESI + 0x4],0x78c284
    m.w32((s.si+0x00000004u), 0x0078c284u);
  }
  { // 0x4c2905: c746087cc27800 MOV dword ptr [ESI + 0x8],0x78c27c
    m.w32((s.si+0x00000008u), 0x0078c27cu);
  }
  { // 0x4c290c: c7460c74c27800 MOV dword ptr [ESI + 0xc],0x78c274
    m.w32((s.si+0x0000000cu), 0x0078c274u);
  }
  { // 0x4c2913: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4c2915: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c2916: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000c8020(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c8020: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c8021: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4c8023: 8a8678050000 MOV AL,byte ptr [ESI + 0x578]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000578u)));
  }
  { // 0x4c8029: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4c802b: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x4c802f: 7404 JZ 0x004c8035
    if(integer::condition("JZ",flags)) goto L004c8035;
  }
  { // 0x4c8031: 24fd AND AL,0xfd
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fdu),8,flags));
  }
  { // 0x4c8033: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L004c8035: { // 0x4c8035: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x4c8039: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4c803d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4c803e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4c803f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4c8040: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c8042: e8193b1f00 CALL 0x006bbb60
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4c8047: 8a8e78050000 MOV CL,byte ptr [ESI + 0x578]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000578u)));
  }
  { // 0x4c804d: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x4c804f: 740a JZ 0x004c805b
    if(integer::condition("JZ",flags)) goto L004c805b;
  }
  { // 0x4c8051: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c8053: 7506 JNZ 0x004c805b
    if(integer::condition("JNZ",flags)) goto L004c805b;
  }
  { // 0x4c8055: 888678050000 MOV byte ptr [ESI + 0x578],AL
    m.w8((s.si+0x00000578u), (s.ax & 0xffu));
  }
  L004c805b: { // 0x4c805b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c805c: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_000ceba0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ceba0: 8b0da4347c00 MOV ECX,dword ptr [0x007c34a4]
    s.cx = m.r32((0x007c34a4u));
  }
  { // 0x4ceba6: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x4cebab: e830c11800 CALL 0x0065ace0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4cebb0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4cebb2: 7403 JZ 0x004cebb7
    if(integer::condition("JZ",flags)) goto L004cebb7;
  }
  { // 0x4cebb4: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x4cebb6: c3 RET
    finish(m,s,f,0u); return;
  }
  L004cebb7: { // 0x4cebb7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4cebb9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000d2250(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4d2250: e8dbfeffff CALL 0x004d2130
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4d2255: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x4d2258: 7e0d JLE 0x004d2267
    if(integer::condition("JLE",flags)) goto L004d2267;
  }
  { // 0x4d225a: 83f809 CMP EAX,0x9
    (void)integer::sub(s.ax,0x00000009u,32,flags);
  }
  { // 0x4d225d: 7d08 JGE 0x004d2267
    if(integer::condition("JGE",flags)) goto L004d2267;
  }
  { // 0x4d225f: 8b0485d8387c00 MOV EAX,dword ptr [EAX*0x4 + 0x7c38d8]
    s.ax = m.r32(((s.ax * 0x00000004u)+0x007c38d8u));
  }
  { // 0x4d2266: c3 RET
    finish(m,s,f,0u); return;
  }
  L004d2267: { // 0x4d2267: b86c397c00 MOV EAX,0x7c396c
    s.ax = 0x007c396cu;
  }
  { // 0x4d226c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000dd870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4dd870: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4dd871: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4dd873: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x4dd876: e855221b00 CALL 0x0068fad0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4dd87b: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x4dd87d: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x4dd881: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x4dd884: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4dd886: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4dd887: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000dd890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4dd890: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4dd891: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4dd893: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4dd894: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4dd896: 8b7e08 MOV EDI,dword ptr [ESI + 0x8]
    s.di = m.r32((s.si+0x00000008u));
  }
  { // 0x4dd899: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x4dd89c: 741e JZ 0x004dd8bc
    if(integer::condition("JZ",flags)) goto L004dd8bc;
  }
  { // 0x4dd89e: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x4dd8a1: e82a221b00 CALL 0x0068fad0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4dd8a6: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4dd8a8: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x4dd8aa: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x4dd8ac: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  { // 0x4dd8ae: 7d07 JGE 0x004dd8b7
    if(integer::condition("JGE",flags)) goto L004dd8b7;
  }
  { // 0x4dd8b0: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x4dd8b2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4dd8b3: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4dd8b5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4dd8b6: c3 RET
    finish(m,s,f,0u); return;
  }
  L004dd8b7: { // 0x4dd8b7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4dd8b8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4dd8ba: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4dd8bb: c3 RET
    finish(m,s,f,0u); return;
  }
  L004dd8bc: { // 0x4dd8bc: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x4dd8be: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4dd8bf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4dd8c0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000df870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4df870: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  { // 0x4df873: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4df875: 7405 JZ 0x004df87c
    if(integer::condition("JZ",flags)) goto L004df87c;
  }
  { // 0x4df877: e834ea0c00 CALL 0x005ae2b0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L004df87c: { // 0x4df87c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000e0030(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e0030: a1ac1c8200 MOV EAX,[0x00821cac]
    s.ax = m.r32((0x00821cacu));
  }
  { // 0x4e0035: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4e0037: 7407 JZ 0x004e0040
    if(integer::condition("JZ",flags)) goto L004e0040;
  }
  { // 0x4e0039: c6807d0d000001 MOV byte ptr [EAX + 0xd7d],0x1
    m.w8((s.ax+0x00000d7du), 0x00000001u);
  }
  L004e0040: { // 0x4e0040: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4e0044: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4e0046: 7413 JZ 0x004e005b
    if(integer::condition("JZ",flags)) goto L004e005b;
  }
  { // 0x4e0048: 83790c02 CMP dword ptr [ECX + 0xc],0x2
    (void)integer::sub(m.r32((s.cx+0x0000000cu)),0x00000002u,32,flags);
  }
  { // 0x4e004c: 7403 JZ 0x004e0051
    if(integer::condition("JZ",flags)) goto L004e0051;
  }
  { // 0x4e004e: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L004e0051: { // 0x4e0051: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x4e0056: e8557a0700 CALL 0x00557ab0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L004e005b: { // 0x4e005b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000e0930(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e0930: e8ebffffff CALL 0x004e0920
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4e0935: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  { // 0x4e0937: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x4e0939: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x4e093a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000e4ce0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e4ce0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x4e4ce4: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x4e4ce8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4e4ce9: a1cca5a100 MOV EAX,[0x00a1a5cc]
    s.ax = m.r32((0x00a1a5ccu));
  }
  { // 0x4e4cee: 8b1490 MOV EDX,dword ptr [EAX + EDX*0x4]
    s.dx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  { // 0x4e4cf1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4e4cf2: e809000000 CALL 0x004e4d00
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4e4cf7: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000e50f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e50f0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x4e50f4: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x4e50f8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4e50f9: a1cca5a100 MOV EAX,[0x00a1a5cc]
    s.ax = m.r32((0x00a1a5ccu));
  }
  { // 0x4e50fe: 8b1490 MOV EDX,dword ptr [EAX + EDX*0x4]
    s.dx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  { // 0x4e5101: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4e5102: e809000000 CALL 0x004e5110
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4e5107: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_000e7800(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e7800: 8a8140010000 MOV AL,byte ptr [ECX + 0x140]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000140u)));
  }
  { // 0x4e7806: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4e7808: 7512 JNZ 0x004e781c
    if(integer::condition("JNZ",flags)) goto L004e781c;
  }
  { // 0x4e780a: 8a813f010000 MOV AL,byte ptr [ECX + 0x13f]
    s.ax = with_al(s.ax, m.r8((s.cx+0x0000013fu)));
  }
  { // 0x4e7810: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4e7812: 7508 JNZ 0x004e781c
    if(integer::condition("JNZ",flags)) goto L004e781c;
  }
  { // 0x4e7814: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4e7816: e815fcffff CALL 0x004e7430
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4e781b: c3 RET
    finish(m,s,f,0u); return;
  }
  L004e781c: { // 0x4e781c: 83b9e0010000ff CMP dword ptr [ECX + 0x1e0],-0x1
    (void)integer::sub(m.r32((s.cx+0x000001e0u)),0xffffffffu,32,flags);
  }
  { // 0x4e7823: 750b JNZ 0x004e7830
    if(integer::condition("JNZ",flags)) goto L004e7830;
  }
  { // 0x4e7825: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  { // 0x4e782a: 8981e0010000 MOV dword ptr [ECX + 0x1e0],EAX
    m.w32((s.cx+0x000001e0u), s.ax);
  }
  L004e7830: { // 0x4e7830: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000eaa70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4eaa70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4eaa71: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4eaa73: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x4eaa75: 7d04 JGE 0x004eaa7b
    if(integer::condition("JGE",flags)) goto L004eaa7b;
  }
  { // 0x4eaa77: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4eaa79: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4eaa7a: c3 RET
    finish(m,s,f,0u); return;
  }
  L004eaa7b: { // 0x4eaa7b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4eaa7d: e81e7ff9ff CALL 0x004829a0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4eaa82: 83fe06 CMP ESI,0x6
    (void)integer::sub(s.si,0x00000006u,32,flags);
  }
  { // 0x4eaa85: 7409 JZ 0x004eaa90
    if(integer::condition("JZ",flags)) goto L004eaa90;
  }
  { // 0x4eaa87: 83fe07 CMP ESI,0x7
    (void)integer::sub(s.si,0x00000007u,32,flags);
  }
  { // 0x4eaa8a: 7404 JZ 0x004eaa90
    if(integer::condition("JZ",flags)) goto L004eaa90;
  }
  { // 0x4eaa8c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4eaa8e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4eaa8f: c3 RET
    finish(m,s,f,0u); return;
  }
  L004eaa90: { // 0x4eaa90: 8b80a00b0000 MOV EAX,dword ptr [EAX + 0xba0]
    s.ax = m.r32((s.ax+0x00000ba0u));
  }
  { // 0x4eaa96: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4eaa97: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000eebf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4eebf0: 8b4934 MOV ECX,dword ptr [ECX + 0x34]
    s.cx = m.r32((s.cx+0x00000034u));
  }
  { // 0x4eebf3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4eebf4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4eebf5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4eebf6: 81c198000000 ADD ECX,0x98
    s.cx = integer::add(s.cx,0x00000098u,32,flags);
  }
  { // 0x4eebfc: e8cf9d0000 CALL 0x004f89d0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4eec01: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  { // 0x4eec05: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x4eec0a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x4eec0c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4eec0e: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x4eec10: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x4eec13: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4eec15: 7e17 JLE 0x004eec2e
    if(integer::condition("JLE",flags)) goto L004eec2e;
  }
  { // 0x4eec17: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  { // 0x4eec1a: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L004eec1c: { // 0x4eec1c: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  { // 0x4eec1e: 8593e8050000 TEST dword ptr [EBX + 0x5e8],EDX
    (void)integer::logical((m.r32((s.bx+0x000005e8u)))&(s.dx),32,flags);
  }
  { // 0x4eec24: 7510 JNZ 0x004eec36
    if(integer::condition("JNZ",flags)) goto L004eec36;
  }
  { // 0x4eec26: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x4eec27: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x4eec2a: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4eec2c: 7cee JL 0x004eec1c
    if(integer::condition("JL",flags)) goto L004eec1c;
  }
  L004eec2e: { // 0x4eec2e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4eec2f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4eec30: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4eec32: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4eec33: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L004eec36: { // 0x4eec36: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  { // 0x4eec39: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4eec3a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4eec3b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4eec3c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000f8850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4f8850: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4f8854: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4f8855: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4f8857: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4f8858: e8837ef1ff CALL 0x004106e0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x4f885d: c7864c010000f8e07800 MOV dword ptr [ESI + 0x14c],0x78e0f8
    m.w32((s.si+0x0000014cu), 0x0078e0f8u);
  }
  { // 0x4f8867: c78668010000d8e07800 MOV dword ptr [ESI + 0x168],0x78e0d8
    m.w32((s.si+0x00000168u), 0x0078e0d8u);
  }
  { // 0x4f8871: c78684010000b8e07800 MOV dword ptr [ESI + 0x184],0x78e0b8
    m.w32((s.si+0x00000184u), 0x0078e0b8u);
  }
  { // 0x4f887b: c70648e07800 MOV dword ptr [ESI],0x78e048
    m.w32((s.si), 0x0078e048u);
  }
  { // 0x4f8881: c746042ce07800 MOV dword ptr [ESI + 0x4],0x78e02c
    m.w32((s.si+0x00000004u), 0x0078e02cu);
  }
  { // 0x4f8888: c7460824e07800 MOV dword ptr [ESI + 0x8],0x78e024
    m.w32((s.si+0x00000008u), 0x0078e024u);
  }
  { // 0x4f888f: c7460c1ce07800 MOV dword ptr [ESI + 0xc],0x78e01c
    m.w32((s.si+0x0000000cu), 0x0078e01cu);
  }
  { // 0x4f8896: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4f8898: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f8899: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00107c70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x507c70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x507c71: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x507c73: 8b86a8050000 MOV EAX,dword ptr [ESI + 0x5a8]
    s.ax = m.r32((s.si+0x000005a8u));
  }
  { // 0x507c79: 8a880a0c0000 MOV CL,byte ptr [EAX + 0xc0a]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000c0au)));
  }
  { // 0x507c7f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x507c81: 7517 JNZ 0x00507c9a
    if(integer::condition("JNZ",flags)) goto L00507c9a;
  }
  { // 0x507c83: 6a0d PUSH 0xd
    f.push(m,0x0000000du);
  }
  { // 0x507c85: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x507c87: e8f4511c00 CALL 0x006cce80
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x507c8c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x507c8e: 750a JNZ 0x00507c9a
    if(integer::condition("JNZ",flags)) goto L00507c9a;
  }
  { // 0x507c90: c786bc0500002c010000 MOV dword ptr [ESI + 0x5bc],0x12c
    m.w32((s.si+0x000005bcu), 0x0000012cu);
  }
  L00507c9a: { // 0x507c9a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x507c9b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00107dd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x507dd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x507dd1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x507dd3: e83819fcff CALL 0x004c9710
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x507dd8: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x507dda: 8a86c3050000 MOV AL,byte ptr [ESI + 0x5c3]
    s.ax = with_al(s.ax, m.r8((s.si+0x000005c3u)));
  }
  { // 0x507de0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x507de2: 7431 JZ 0x00507e15
    if(integer::condition("JZ",flags)) goto L00507e15;
  }
  { // 0x507de4: 8b86a8050000 MOV EAX,dword ptr [ESI + 0x5a8]
    s.ax = m.r32((s.si+0x000005a8u));
  }
  { // 0x507dea: 8a900b0c0000 MOV DL,byte ptr [EAX + 0xc0b]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000c0bu)));
  }
  { // 0x507df0: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x507df2: 7418 JZ 0x00507e0c
    if(integer::condition("JZ",flags)) goto L00507e0c;
  }
  { // 0x507df4: b855555555 MOV EAX,0x55555555
    s.ax = 0x55555555u;
  }
  { // 0x507df9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x507dfa: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  { // 0x507dfc: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x507dfe: d1fa SAR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x507e00: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x507e02: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  { // 0x507e05: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x507e07: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  { // 0x507e09: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x507e0b: c3 RET
    finish(m,s,f,0u); return;
  }
  L00507e0c: { // 0x507e0c: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x507e0e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x507e0f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x507e11: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x507e13: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00507e15: { // 0x507e15: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x507e17: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x507e18: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00124eb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x524eb0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x524eb4: 8b4c8128 MOV ECX,dword ptr [ECX + EAX*0x4 + 0x28]
    s.cx = m.r32((s.cx+(s.ax * 0x00000004u)+0x00000028u));
  }
  { // 0x524eb8: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  { // 0x524ebb: e810b7f5ff CALL 0x004805d0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x524ec0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001259d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5259d0: 8b4948 MOV ECX,dword ptr [ECX + 0x48]
    s.cx = m.r32((s.cx+0x00000048u));
  }
  { // 0x5259d3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5259d5: 740a JZ 0x005259e1
    if(integer::condition("JZ",flags)) goto L005259e1;
  }
  { // 0x5259d7: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x5259db: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5259dc: e8efdfffff CALL 0x005239d0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L005259e1: { // 0x5259e1: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00127600(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x527600: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x527601: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x527603: 8b86a4000000 MOV EAX,dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  { // 0x527609: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x52760b: 750f JNZ 0x0052761c
    if(integer::condition("JNZ",flags)) goto L0052761c;
  }
  { // 0x52760d: 8a86c4020000 MOV AL,byte ptr [ESI + 0x2c4]
    s.ax = with_al(s.ax, m.r8((s.si+0x000002c4u)));
  }
  { // 0x527613: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x527615: 7405 JZ 0x0052761c
    if(integer::condition("JZ",flags)) goto L0052761c;
  }
  { // 0x527617: e8a4210000 CALL 0x005297c0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L0052761c: { // 0x52761c: 8b8ea4000000 MOV ECX,dword ptr [ESI + 0xa4]
    s.cx = m.r32((s.si+0x000000a4u));
  }
  { // 0x527622: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x527624: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x527626: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x527629: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x52762a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00127630(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x527630: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x527631: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x527633: 8b86a4000000 MOV EAX,dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  { // 0x527639: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x52763b: 7517 JNZ 0x00527654
    if(integer::condition("JNZ",flags)) goto L00527654;
  }
  { // 0x52763d: 8a8ec4020000 MOV CL,byte ptr [ESI + 0x2c4]
    s.cx = with_al(s.cx, m.r8((s.si+0x000002c4u)));
  }
  { // 0x527643: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x527645: 740d JZ 0x00527654
    if(integer::condition("JZ",flags)) goto L00527654;
  }
  { // 0x527647: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x527649: e872210000 CALL 0x005297c0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x52764e: 8b86a4000000 MOV EAX,dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  L00527654: { // 0x527654: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x527655: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0012c5f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x52c5f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x52c5f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x52c5f3: 8b86a4000000 MOV EAX,dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  { // 0x52c5f9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x52c5fb: 750f JNZ 0x0052c60c
    if(integer::condition("JNZ",flags)) goto L0052c60c;
  }
  { // 0x52c5fd: 8a86c4020000 MOV AL,byte ptr [ESI + 0x2c4]
    s.ax = with_al(s.ax, m.r8((s.si+0x000002c4u)));
  }
  { // 0x52c603: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x52c605: 7405 JZ 0x0052c60c
    if(integer::condition("JZ",flags)) goto L0052c60c;
  }
  { // 0x52c607: e8b4d1ffff CALL 0x005297c0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L0052c60c: { // 0x52c60c: 8b8678020000 MOV EAX,dword ptr [ESI + 0x278]
    s.ax = m.r32((s.si+0x00000278u));
  }
  { // 0x52c612: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x52c616: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x52c61a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x52c61b: 8b0488 MOV EAX,dword ptr [EAX + ECX*0x4]
    s.ax = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  { // 0x52c61e: 8d0490 LEA EAX,[EAX + EDX*0x4]
    s.ax = (s.ax+(s.dx * 0x00000004u));
  }
  { // 0x52c621: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00130530(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x530530: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x530531: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x530533: 8b8618030000 MOV EAX,dword ptr [ESI + 0x318]
    s.ax = m.r32((s.si+0x00000318u));
  }
  { // 0x530539: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x53053a: 25ff000080 AND EAX,0x800000ff
    s.ax = integer::logical((s.ax)&(0x800000ffu),32,flags);
  }
  { // 0x53053f: 7907 JNS 0x00530548
    if(integer::condition("JNS",flags)) goto L00530548;
  }
  { // 0x530541: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x530542: 0d00ffffff OR EAX,0xffffff00
    s.ax = integer::logical((s.ax)|(0xffffff00u),32,flags);
  }
  { // 0x530547: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00530548: { // 0x530548: 3b8614030000 CMP EAX,dword ptr [ESI + 0x314]
    (void)integer::sub(s.ax,m.r32((s.si+0x00000314u)),32,flags);
  }
  { // 0x53054e: 7405 JZ 0x00530555
    if(integer::condition("JZ",flags)) goto L00530555;
  }
  { // 0x530550: e89b240800 CALL 0x005b29f0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L00530555: { // 0x530555: 8b8614030000 MOV EAX,dword ptr [ESI + 0x314]
    s.ax = m.r32((s.si+0x00000314u));
  }
  { // 0x53055b: 8b8e18030000 MOV ECX,dword ptr [ESI + 0x318]
    s.cx = m.r32((s.si+0x00000318u));
  }
  { // 0x530561: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x530563: 7505 JNZ 0x0053056a
    if(integer::condition("JNZ",flags)) goto L0053056a;
  }
  { // 0x530565: 6633c0 XOR AX,AX
    s.ax = with_ax(s.ax, integer::logical(((s.ax & 0xffffu))^((s.ax & 0xffffu)),16,flags));
  }
  { // 0x530568: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x530569: c3 RET
    finish(m,s,f,0u); return;
  }
  L0053056a: { // 0x53056a: 668b844614010000 MOV AX,word ptr [ESI + EAX*0x2 + 0x114]
    s.ax = with_ax(s.ax, m.r16((s.si+(s.ax * 0x00000002u)+0x00000114u)));
  }
  { // 0x530572: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x530573: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00135720(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x535720: 8a4148 MOV AL,byte ptr [ECX + 0x48]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000048u)));
  }
  { // 0x535723: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x535725: 750e JNZ 0x00535735
    if(integer::condition("JNZ",flags)) goto L00535735;
  }
  { // 0x535727: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x53572b: c6414801 MOV byte ptr [ECX + 0x48],0x1
    m.w8((s.cx+0x00000048u), 0x00000001u);
  }
  { // 0x53572f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x535730: e87b000000 CALL 0x005357b0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L00535735: { // 0x535735: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00135740(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x535740: 8a4148 MOV AL,byte ptr [ECX + 0x48]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000048u)));
  }
  { // 0x535743: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x535745: 740e JZ 0x00535755
    if(integer::condition("JZ",flags)) goto L00535755;
  }
  { // 0x535747: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x53574b: c6414800 MOV byte ptr [ECX + 0x48],0x0
    m.w8((s.cx+0x00000048u), 0x00000000u);
  }
  { // 0x53574f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x535750: e85b000000 CALL 0x005357b0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L00535755: { // 0x535755: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00135760(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x535760: 8b4124 MOV EAX,dword ptr [ECX + 0x24]
    s.ax = m.r32((s.cx+0x00000024u));
  }
  { // 0x535763: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x535767: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x535768: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x53576c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x53576d: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  { // 0x535771: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x535773: 750b JNZ 0x00535780
    if(integer::condition("JNZ",flags)) goto L00535780;
  }
  { // 0x535775: 8b4128 MOV EAX,dword ptr [ECX + 0x28]
    s.ax = m.r32((s.cx+0x00000028u));
  }
  { // 0x535778: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x53577a: 7504 JNZ 0x00535780
    if(integer::condition("JNZ",flags)) goto L00535780;
  }
  { // 0x53577c: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x53577e: 7421 JZ 0x005357a1
    if(integer::condition("JZ",flags)) goto L005357a1;
  }
  L00535780: { // 0x535780: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x535784: 897124 MOV dword ptr [ECX + 0x24],ESI
    m.w32((s.cx+0x00000024u), s.si);
  }
  { // 0x535787: 89412c MOV dword ptr [ECX + 0x2c],EAX
    m.w32((s.cx+0x0000002cu), s.ax);
  }
  { // 0x53578a: 8a4148 MOV AL,byte ptr [ECX + 0x48]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000048u)));
  }
  { // 0x53578d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x53578f: 895128 MOV dword ptr [ECX + 0x28],EDX
    m.w32((s.cx+0x00000028u), s.dx);
  }
  { // 0x535792: 897930 MOV dword ptr [ECX + 0x30],EDI
    m.w32((s.cx+0x00000030u), s.di);
  }
  { // 0x535795: 740a JZ 0x005357a1
    if(integer::condition("JZ",flags)) goto L005357a1;
  }
  { // 0x535797: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x53579b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x53579c: e80f000000 CALL 0x005357b0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  L005357a1: { // 0x5357a1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5357a2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5357a3: c21400 RET 0x14
    finish(m,s,f,20u); return;
  }
}
void f_00139390(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x539390: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x539394: c7410402000000 MOV dword ptr [ECX + 0x4],0x2
    m.w32((s.cx+0x00000004u), 0x00000002u);
  }
  { // 0x53939b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x53939d: 750a JNZ 0x005393a9
    if(integer::condition("JNZ",flags)) goto L005393a9;
  }
  { // 0x53939f: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x5393a4: 0540090000 ADD EAX,0x940
    s.ax = integer::add(s.ax,0x00000940u,32,flags);
  }
  L005393a9: { // 0x5393a9: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  { // 0x5393ac: e89f050000 CALL 0x00539950
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5393b1: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0013c510(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x53c510: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53c511: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x53c515: 8a8684000000 MOV AL,byte ptr [ESI + 0x84]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000084u)));
  }
  { // 0x53c51b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x53c51d: 7406 JZ 0x0053c525
    if(integer::condition("JZ",flags)) goto L0053c525;
  }
  { // 0x53c51f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x53c521: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53c522: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0053c525: { // 0x53c525: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x53c529: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x53c52a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53c52b: e8d065ffff CALL 0x00532b00
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x53c530: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x53c532: 740c JZ 0x0053c540
    if(integer::condition("JZ",flags)) goto L0053c540;
  }
  { // 0x53c534: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x53c536: 888684000000 MOV byte ptr [ESI + 0x84],AL
    m.w8((s.si+0x00000084u), (s.ax & 0xffu));
  }
  { // 0x53c53c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53c53d: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0053c540: { // 0x53c540: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x53c542: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53c543: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0013c600(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x53c600: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x53c602: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x53c603: 8b6c2408 MOV EBP,dword ptr [ESP + 0x8]
    s.bp = m.r32((f.sp+0x00000008u));
  }
  { // 0x53c607: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53c608: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x53c60a: 7708 JA 0x0053c614
    if(integer::condition("JA",flags)) goto L0053c614;
  }
  { // 0x53c60c: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  { // 0x53c610: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x53c612: eb3b JMP 0x0053c64f
    goto L0053c64f;
  }
  L0053c614: { // 0x53c614: 83fa0d CMP EDX,0xd
    (void)integer::sub(s.dx,0x0000000du,32,flags);
  }
  { // 0x53c617: 7722 JA 0x0053c63b
    if(integer::condition("JA",flags)) goto L0053c63b;
  }
  { // 0x53c619: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x53c61a: 8ada MOV BL,DL
    s.bx = with_al(s.bx, (s.dx & 0xffu));
  }
  { // 0x53c61c: 80c311 ADD BL,0x11
    s.bx = with_al(s.bx, integer::add((s.bx & 0xffu),0x00000011u,8,flags));
  }
  { // 0x53c61f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x53c620: 885d00 MOV byte ptr [EBP],BL
    m.w8((s.bp), (s.bx & 0xffu));
  }
  { // 0x53c623: 8d7d01 LEA EDI,[EBP + 0x1]
    s.di = (s.bp+0x00000001u);
  }
  L0053c626: { // 0x53c626: 8a19 MOV BL,byte ptr [ECX]
    s.bx = with_al(s.bx, m.r8((s.cx)));
  }
  { // 0x53c628: 881f MOV byte ptr [EDI],BL
    m.w8((s.di), (s.bx & 0xffu));
  }
  { // 0x53c62a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x53c62b: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x53c62c: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x53c62d: 75f7 JNZ 0x0053c626
    if(integer::condition("JNZ",flags)) goto L0053c626;
  }
  { // 0x53c62f: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  { // 0x53c633: 2bfd SUB EDI,EBP
    s.di = integer::sub(s.di,s.bp,32,flags);
  }
  { // 0x53c635: 893e MOV dword ptr [ESI],EDI
    m.w32((s.si), s.di);
  }
  { // 0x53c637: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x53c638: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x53c639: eb14 JMP 0x0053c64f
    goto L0053c64f;
  }
  L0053c63b: { // 0x53c63b: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x53c63f: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  { // 0x53c643: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x53c644: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53c645: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x53c646: e825000000 CALL 0x0053c670
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x53c64b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x53c64d: 7513 JNZ 0x0053c662
    if(integer::condition("JNZ",flags)) goto L0053c662;
  }
  L0053c64f: { // 0x53c64f: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x53c651: c6042911 MOV byte ptr [ECX + EBP*0x1],0x11
    m.w8((s.cx+(s.bp * 0x00000001u)), 0x00000011u);
  }
  { // 0x53c655: 03cd ADD ECX,EBP
    s.cx = integer::add(s.cx,s.bp,32,flags);
  }
  { // 0x53c657: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x53c658: c60100 MOV byte ptr [ECX],0x0
    m.w8((s.cx), 0x00000000u);
  }
  { // 0x53c65b: c6410100 MOV byte ptr [ECX + 0x1],0x0
    m.w8((s.cx+0x00000001u), 0x00000000u);
  }
  { // 0x53c65f: 830603 ADD dword ptr [ESI],0x3
    m.w32((s.si), integer::add(m.r32((s.si)),0x00000003u,32,flags));
  }
  L0053c662: { // 0x53c662: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53c663: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x53c664: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0013f600(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x53f600: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53f601: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x53f603: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x53f606: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x53f608: 7504 JNZ 0x0053f60e
    if(integer::condition("JNZ",flags)) goto L0053f60e;
  }
  { // 0x53f60a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53f60b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0053f60e: { // 0x53f60e: 8a4e0c MOV CL,byte ptr [ESI + 0xc]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000000cu)));
  }
  { // 0x53f611: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x53f613: 751e JNZ 0x0053f633
    if(integer::condition("JNZ",flags)) goto L0053f633;
  }
  { // 0x53f615: 68a00e4800 PUSH 0x480ea0
    f.push(m,0x00480ea0u);
  }
  { // 0x53f61a: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x53f61c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x53f61d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x53f61f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x53f620: e861e02200 CALL 0x0076d686
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x53f625: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x53f628: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  { // 0x53f62f: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L0053f633: { // 0x53f633: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x53f637: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x53f638: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x53f639: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x53f63b: 8b19 MOV EBX,dword ptr [ECX]
    s.bx = m.r32((s.cx));
  }
  { // 0x53f63d: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x53f640: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x53f642: 7e25 JLE 0x0053f669
    if(integer::condition("JLE",flags)) goto L0053f669;
  }
  L0053f644: { // 0x53f644: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x53f646: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x53f647: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x53f649: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x53f64b: 8b34c7 MOV ESI,dword ptr [EDI + EAX*0x8]
    s.si = m.r32((s.di+(s.ax * 0x00000008u)));
  }
  { // 0x53f64e: 8d14c7 LEA EDX,[EDI + EAX*0x8]
    s.dx = (s.di+(s.ax * 0x00000008u));
  }
  { // 0x53f651: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x53f653: 7e04 JLE 0x0053f659
    if(integer::condition("JLE",flags)) goto L0053f659;
  }
  { // 0x53f655: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x53f657: eb0c JMP 0x0053f665
    goto L0053f665;
  }
  L0053f659: { // 0x53f659: 7416 JZ 0x0053f671
    if(integer::condition("JZ",flags)) goto L0053f671;
  }
  { // 0x53f65b: 8d7a08 LEA EDI,[EDX + 0x8]
    s.di = (s.dx+0x00000008u);
  }
  { // 0x53f65e: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  { // 0x53f661: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x53f663: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0053f665: { // 0x53f665: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x53f667: 7fdb JG 0x0053f644
    if(integer::condition("JG",flags)) goto L0053f644;
  }
  L0053f669: { // 0x53f669: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x53f66a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x53f66b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x53f66d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53f66e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0053f671: { // 0x53f671: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x53f672: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x53f673: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x53f675: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53f676: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00157070(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x557070: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x557073: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x557077: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x557078: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x55707a: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  { // 0x55707d: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  { // 0x557081: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
  { // 0x557085: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x557086: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x55708c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x55708e: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x557090: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  { // 0x557093: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x557094: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x55709a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x55709c: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x55709f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5570a1: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x5570a4: c1e109 SHL ECX,0x9
    s.cx = integer::shift(s.cx,0x00000009u,32,flags,integer::Shift::left);
  }
  { // 0x5570a7: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  { // 0x5570a9: 7815 JS 0x005570c0
    if(integer::condition("JS",flags)) goto L005570c0;
  }
  { // 0x5570ab: 3b0d5ca98100 CMP ECX,dword ptr [0x0081a95c]
    (void)integer::sub(s.cx,m.r32((0x0081a95cu)),32,flags);
  }
  { // 0x5570b1: 7d0d JGE 0x005570c0
    if(integer::condition("JGE",flags)) goto L005570c0;
  }
  { // 0x5570b3: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  { // 0x5570b9: 8b0c8a MOV ECX,dword ptr [EDX + ECX*0x4]
    s.cx = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  { // 0x5570bc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5570be: 7518 JNZ 0x005570d8
    if(integer::condition("JNZ",flags)) goto L005570d8;
  }
  L005570c0: { // 0x5570c0: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  { // 0x5570c5: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  { // 0x5570ca: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x5570ce: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  { // 0x5570d3: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L005570d8: { // 0x5570d8: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  { // 0x5570dc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5570dd: e8de91f1ff CALL 0x004702c0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5570e2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5570e3: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5570e6: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001575e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5575e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5575e1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x5575e5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5575e7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5575e9: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x5575ea: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x5575f0: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x5575f2: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x5575f5: 668944240c MOV word ptr [ESP + 0xc],AX
    m.w16((f.sp+0x0000000cu), (s.ax & 0xffffu));
  }
  { // 0x5575fa: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x5575fd: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x5575fe: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x557604: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x557606: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x55760a: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x55760d: 668944240e MOV word ptr [ESP + 0xe],AX
    m.w16((f.sp+0x0000000eu), (s.ax & 0xffffu));
  }
  { // 0x557612: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x557616: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x557617: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  { // 0x55761b: e830feffff CALL 0x00557450
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x557620: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x557621: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0018e4d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58e4d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x58e4d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x58e4d3: e8c8ccfaff CALL 0x0053b1a0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x58e4d8: 8b0d3087a500 MOV ECX,dword ptr [0x00a58730]
    s.cx = m.r32((0x00a58730u));
  }
  { // 0x58e4de: 8d4618 LEA EAX,[ESI + 0x18]
    s.ax = (s.si+0x00000018u);
  }
  { // 0x58e4e1: 894e18 MOV dword ptr [ESI + 0x18],ECX
    m.w32((s.si+0x00000018u), s.cx);
  }
  { // 0x58e4e4: 8b153487a500 MOV EDX,dword ptr [0x00a58734]
    s.dx = m.r32((0x00a58734u));
  }
  { // 0x58e4ea: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  { // 0x58e4ed: 8b0d3887a500 MOV ECX,dword ptr [0x00a58738]
    s.cx = m.r32((0x00a58738u));
  }
  { // 0x58e4f3: 8d5624 LEA EDX,[ESI + 0x24]
    s.dx = (s.si+0x00000024u);
  }
  { // 0x58e4f6: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  { // 0x58e4f9: a13087a500 MOV EAX,[0x00a58730]
    s.ax = m.r32((0x00a58730u));
  }
  { // 0x58e4fe: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  { // 0x58e500: 8b0d3487a500 MOV ECX,dword ptr [0x00a58734]
    s.cx = m.r32((0x00a58734u));
  }
  { // 0x58e506: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  { // 0x58e509: a13887a500 MOV EAX,[0x00a58738]
    s.ax = m.r32((0x00a58738u));
  }
  { // 0x58e50e: c6463000 MOV byte ptr [ESI + 0x30],0x0
    m.w8((s.si+0x00000030u), 0x00000000u);
  }
  { // 0x58e512: c7065c117900 MOV dword ptr [ESI],0x79115c
    m.w32((s.si), 0x0079115cu);
  }
  { // 0x58e518: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  { // 0x58e51b: c7460494107900 MOV dword ptr [ESI + 0x4],0x791094
    m.w32((s.si+0x00000004u), 0x00791094u);
  }
  { // 0x58e522: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x58e524: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x58e525: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00191300(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x591300: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x591301: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x591303: e868960300 CALL 0x005ca970
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x591308: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x59130b: 898698000000 MOV dword ptr [ESI + 0x98],EAX
    m.w32((s.si+0x00000098u), s.ax);
  }
  { // 0x591311: 89869c000000 MOV dword ptr [ESI + 0x9c],EAX
    m.w32((s.si+0x0000009cu), s.ax);
  }
  { // 0x591317: 8986a0000000 MOV dword ptr [ESI + 0xa0],EAX
    m.w32((s.si+0x000000a0u), s.ax);
  }
  { // 0x59131d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x59131f: 8886a4000000 MOV byte ptr [ESI + 0xa4],AL
    m.w8((s.si+0x000000a4u), (s.ax & 0xffu));
  }
  { // 0x591325: 8986a8000000 MOV dword ptr [ESI + 0xa8],EAX
    m.w32((s.si+0x000000a8u), s.ax);
  }
  { // 0x59132b: 8986ac000000 MOV dword ptr [ESI + 0xac],EAX
    m.w32((s.si+0x000000acu), s.ax);
  }
  { // 0x591331: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x591337: 898eb0000000 MOV dword ptr [ESI + 0xb0],ECX
    m.w32((s.si+0x000000b0u), s.cx);
  }
  { // 0x59133d: 8986b8000000 MOV dword ptr [ESI + 0xb8],EAX
    m.w32((s.si+0x000000b8u), s.ax);
  }
  { // 0x591343: c706e8117900 MOV dword ptr [ESI],0x7911e8
    m.w32((s.si), 0x007911e8u);
  }
  { // 0x591349: c74604cc117900 MOV dword ptr [ESI + 0x4],0x7911cc
    m.w32((s.si+0x00000004u), 0x007911ccu);
  }
  { // 0x591350: c74608c4117900 MOV dword ptr [ESI + 0x8],0x7911c4
    m.w32((s.si+0x00000008u), 0x007911c4u);
  }
  { // 0x591357: c7460cbc117900 MOV dword ptr [ESI + 0xc],0x7911bc
    m.w32((s.si+0x0000000cu), 0x007911bcu);
  }
  { // 0x59135e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x591360: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x591361: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001924c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5924c0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5924c1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5924c3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5924c5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5924c7: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x5924cb: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x5924d3: e8c8030000 CALL 0x005928a0
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x5924d8: 8b442400 MOV EAX,dword ptr [ESP]
    s.ax = m.r32((f.sp));
  }
  { // 0x5924dc: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x5924dd: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0019b080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59b080: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x59b081: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x59b082: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x59b083: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x59b085: 8d99d0070000 LEA EBX,[ECX + 0x7d0]
    s.bx = (s.cx+0x000007d0u);
  }
  L0059b08b: { // 0x59b08b: 8d140f LEA EDX,[EDI + ECX*0x1]
    s.dx = (s.di+(s.cx * 0x00000001u));
  }
  { // 0x59b08e: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x59b090: be50000000 MOV ESI,0x50
    s.si = 0x00000050u;
  }
  L0059b095: { // 0x59b095: c60220 MOV byte ptr [EDX],0x20
    m.w8((s.dx), 0x00000020u);
  }
  { // 0x59b098: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  { // 0x59b09e: 83c064 ADD EAX,0x64
    s.ax = integer::add(s.ax,0x00000064u,32,flags);
  }
  { // 0x59b0a1: 83c219 ADD EDX,0x19
    s.dx = integer::add(s.dx,0x00000019u,32,flags);
  }
  { // 0x59b0a4: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x59b0a5: 75ee JNZ 0x0059b095
    if(integer::condition("JNZ",flags)) goto L0059b095;
  }
  { // 0x59b0a7: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x59b0a8: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  { // 0x59b0ab: 83ff19 CMP EDI,0x19
    (void)integer::sub(s.di,0x00000019u,32,flags);
  }
  { // 0x59b0ae: 7cdb JL 0x0059b08b
    if(integer::condition("JL",flags)) goto L0059b08b;
  }
  { // 0x59b0b0: 6a19 PUSH 0x19
    f.push(m,0x00000019u);
  }
  { // 0x59b0b2: 6a50 PUSH 0x50
    f.push(m,0x00000050u);
  }
  { // 0x59b0b4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x59b0b6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x59b0b8: c6813427000001 MOV byte ptr [ECX + 0x2734],0x1
    m.w8((s.cx+0x00002734u), 0x00000001u);
  }
  { // 0x59b0bf: e8bc070000 CALL 0x0059b880
    invoke(m,s,f,op,f.direct_target); flags=0x202u;
  }
  { // 0x59b0c4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x59b0c5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x59b0c6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x59b0c7: c3 RET
    finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,114>& entries_a() {
  static const std::array<Entry,114> entries{{
    {0x15c0u,f_000015c0},
    {0x2790u,f_00002790},
    {0x2860u,f_00002860},
    {0x2c00u,f_00002c00},
    {0x2c20u,f_00002c20},
    {0x31f0u,f_000031f0},
    {0x35b0u,f_000035b0},
    {0x35d0u,f_000035d0},
    {0x3870u,f_00003870},
    {0x53f0u,f_000053f0},
    {0x5440u,f_00005440},
    {0x6f50u,f_00006f50},
    {0x70a0u,f_000070a0},
    {0x7fa0u,f_00007fa0},
    {0x8420u,f_00008420},
    {0x8500u,f_00008500},
    {0x8a30u,f_00008a30},
    {0x8d40u,f_00008d40},
    {0x9230u,f_00009230},
    {0xffd0u,f_0000ffd0},
    {0x107c0u,f_000107c0},
    {0x1b990u,f_0001b990},
    {0x20d70u,f_00020d70},
    {0x26e00u,f_00026e00},
    {0x2ad50u,f_0002ad50},
    {0x2c3a0u,f_0002c3a0},
    {0x2f5e0u,f_0002f5e0},
    {0x2fd70u,f_0002fd70},
    {0x2fda0u,f_0002fda0},
    {0x302e0u,f_000302e0},
    {0x306c0u,f_000306c0},
    {0x31550u,f_00031550},
    {0x35e70u,f_00035e70},
    {0x450e0u,f_000450e0},
    {0x4a620u,f_0004a620},
    {0x4c610u,f_0004c610},
    {0x4d5f0u,f_0004d5f0},
    {0x52470u,f_00052470},
    {0x524d0u,f_000524d0},
    {0x539d0u,f_000539d0},
    {0x57de0u,f_00057de0},
    {0x68d10u,f_00068d10},
    {0x698f0u,f_000698f0},
    {0x69c00u,f_00069c00},
    {0x6a900u,f_0006a900},
    {0x6aa10u,f_0006aa10},
    {0x6e0f0u,f_0006e0f0},
    {0x6f990u,f_0006f990},
    {0x6fa10u,f_0006fa10},
    {0x75040u,f_00075040},
    {0x750b0u,f_000750b0},
    {0x75960u,f_00075960},
    {0x766c0u,f_000766c0},
    {0x782d0u,f_000782d0},
    {0x79e00u,f_00079e00},
    {0x79e30u,f_00079e30},
    {0x7d570u,f_0007d570},
    {0x82b80u,f_00082b80},
    {0x83210u,f_00083210},
    {0x93710u,f_00093710},
    {0x94fb0u,f_00094fb0},
    {0x97140u,f_00097140},
    {0x99800u,f_00099800},
    {0xa5750u,f_000a5750},
    {0xb4610u,f_000b4610},
    {0xb49d0u,f_000b49d0},
    {0xb5c00u,f_000b5c00},
    {0xb5c70u,f_000b5c70},
    {0xb5ce0u,f_000b5ce0},
    {0xb5d40u,f_000b5d40},
    {0xb5da0u,f_000b5da0},
    {0xb5e20u,f_000b5e20},
    {0xb6100u,f_000b6100},
    {0xb6180u,f_000b6180},
    {0xb6270u,f_000b6270},
    {0xb93f0u,f_000b93f0},
    {0xbbd80u,f_000bbd80},
    {0xbf800u,f_000bf800},
    {0xc28d0u,f_000c28d0},
    {0xc8020u,f_000c8020},
    {0xceba0u,f_000ceba0},
    {0xd2250u,f_000d2250},
    {0xdd870u,f_000dd870},
    {0xdd890u,f_000dd890},
    {0xdf870u,f_000df870},
    {0xe0030u,f_000e0030},
    {0xe0930u,f_000e0930},
    {0xe4ce0u,f_000e4ce0},
    {0xe50f0u,f_000e50f0},
    {0xe7800u,f_000e7800},
    {0xeaa70u,f_000eaa70},
    {0xeebf0u,f_000eebf0},
    {0xf8850u,f_000f8850},
    {0x107c70u,f_00107c70},
    {0x107dd0u,f_00107dd0},
    {0x124eb0u,f_00124eb0},
    {0x1259d0u,f_001259d0},
    {0x127600u,f_00127600},
    {0x127630u,f_00127630},
    {0x12c5f0u,f_0012c5f0},
    {0x130530u,f_00130530},
    {0x135720u,f_00135720},
    {0x135740u,f_00135740},
    {0x135760u,f_00135760},
    {0x139390u,f_00139390},
    {0x13c510u,f_0013c510},
    {0x13c600u,f_0013c600},
    {0x13f600u,f_0013f600},
    {0x157070u,f_00157070},
    {0x1575e0u,f_001575e0},
    {0x18e4d0u,f_0018e4d0},
    {0x191300u,f_00191300},
    {0x1924c0u,f_001924c0},
    {0x19b080u,f_0019b080},
  }}; return entries;
}
} // namespace ra2::recovered::direct_b33
