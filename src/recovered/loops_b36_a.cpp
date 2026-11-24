#include "recovered/loops_b36_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::loops_b36 {
namespace {
void f_00002ef0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x402ef0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x402ef1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x402ef2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x402ef3: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x402ef5: 8d8ff8000000 LEA ECX,[EDI + 0xf8]
    s.cx = (s.di+0x000000f8u);
  }
  { // 0x402efb: e8f0430000 CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x402f00: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x402f02: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x402f04: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  { // 0x402f06: 7416 JZ 0x00402f1e
    if(integer::condition("JZ",flags)) goto L00402f1e;
  }
  L00402f08: { // 0x402f08: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x402f0a: e801440000 CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x402f0f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x402f11: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x402f13: e838f6ffff CALL 0x00402550
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x402f18: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x402f1a: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  { // 0x402f1c: 75ea JNZ 0x00402f08
    if(integer::condition("JNZ",flags)) goto L00402f08;
  }
  L00402f1e: { // 0x402f1e: 8b4718 MOV EAX,dword ptr [EDI + 0x18]
    s.ax = m.r32((s.di+0x00000018u));
  }
  { // 0x402f21: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x402f23: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  { // 0x402f26: ff5220 CALL dword ptr [EDX + 0x20]
    const std::uint32_t call_target=m.r32((s.dx+0x00000020u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x402f29: 8b471c MOV EAX,dword ptr [EDI + 0x1c]
    s.ax = m.r32((s.di+0x0000001cu));
  }
  { // 0x402f2c: 8b4f18 MOV ECX,dword ptr [EDI + 0x18]
    s.cx = m.r32((s.di+0x00000018u));
  }
  { // 0x402f2f: c744811c00000000 MOV dword ptr [ECX + EAX*0x4 + 0x1c],0x0
    m.w32((s.cx+(s.ax * 0x00000004u)+0x0000001cu), 0x00000000u);
  }
  { // 0x402f37: 8b4718 MOV EAX,dword ptr [EDI + 0x18]
    s.ax = m.r32((s.di+0x00000018u));
  }
  { // 0x402f3a: 8b4810 MOV ECX,dword ptr [EAX + 0x10]
    s.cx = m.r32((s.ax+0x00000010u));
  }
  { // 0x402f3d: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x402f3e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x402f40: 894810 MOV dword ptr [EAX + 0x10],ECX
    m.w32((s.ax+0x00000010u), s.cx);
  }
  { // 0x402f43: 7d0a JGE 0x00402f4f
    if(integer::condition("JGE",flags)) goto L00402f4f;
  }
  { // 0x402f45: 8b5718 MOV EDX,dword ptr [EDI + 0x18]
    s.dx = m.r32((s.di+0x00000018u));
  }
  { // 0x402f48: c7421000000000 MOV dword ptr [EDX + 0x10],0x0
    m.w32((s.dx+0x00000010u), 0x00000000u);
  }
  L00402f4f: { // 0x402f4f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x402f50: e826a73600 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x402f55: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x402f58: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x402f59: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x402f5a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x402f5b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00003530(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x403530: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x403531: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x403532: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x403533: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  { // 0x403535: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x403537: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00403539: { // 0x403539: 8b86f0000000 MOV EAX,dword ptr [ESI + 0xf0]
    s.ax = m.r32((s.si+0x000000f0u));
  }
  { // 0x40353f: 8b8ef4000000 MOV ECX,dword ptr [ESI + 0xf4]
    s.cx = m.r32((s.si+0x000000f4u));
  }
  { // 0x403545: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x403547: 7d57 JGE 0x004035a0
    if(integer::condition("JGE",flags)) goto L004035a0;
  }
  { // 0x403549: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40354b: e8f0eaffff CALL 0x00402040
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x403550: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x403552: 744c JZ 0x004035a0
    if(integer::condition("JZ",flags)) goto L004035a0;
  }
  { // 0x403554: 89b0ac000000 MOV dword ptr [EAX + 0xac],ESI
    m.w32((s.ax+0x000000acu), s.si);
  }
  { // 0x40355a: 8b8ef0000000 MOV ECX,dword ptr [ESI + 0xf0]
    s.cx = m.r32((s.si+0x000000f0u));
  }
  { // 0x403560: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x403561: 898ef0000000 MOV dword ptr [ESI + 0xf0],ECX
    m.w32((s.si+0x000000f0u), s.cx);
  }
  { // 0x403567: 8b8e04010000 MOV ECX,dword ptr [ESI + 0x104]
    s.cx = m.r32((s.si+0x00000104u));
  }
  { // 0x40356d: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x40356e: 898e04010000 MOV dword ptr [ESI + 0x104],ECX
    m.w32((s.si+0x00000104u), s.cx);
  }
  { // 0x403574: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x403576: 8d8ef8000000 LEA ECX,[ESI + 0xf8]
    s.cx = (s.si+0x000000f8u);
  }
  { // 0x40357c: e8cf3d0000 CALL 0x00407350
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x403581: 8b8604010000 MOV EAX,dword ptr [ESI + 0x104]
    s.ax = m.r32((s.si+0x00000104u));
  }
  { // 0x403587: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x403588: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x40358a: 898604010000 MOV dword ptr [ESI + 0x104],EAX
    m.w32((s.si+0x00000104u), s.ax);
  }
  { // 0x403590: 7d0a JGE 0x0040359c
    if(integer::condition("JGE",flags)) goto L0040359c;
  }
  { // 0x403592: c7860401000000000000 MOV dword ptr [ESI + 0x104],0x0
    m.w32((s.si+0x00000104u), 0x00000000u);
  }
  L0040359c: { // 0x40359c: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x40359d: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  { // 0x40359e: 7599 JNZ 0x00403539
    if(integer::condition("JNZ",flags)) goto L00403539;
  }
  L004035a0: { // 0x4035a0: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x4035a2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4035a3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4035a4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4035a5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000036f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4036f0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4036f1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4036f2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4036f3: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x4036f5: 81c1f8000000 ADD ECX,0xf8
    s.cx = integer::add(s.cx,0x000000f8u,32,flags);
  }
  { // 0x4036fb: e8f03b0000 CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x403700: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x403702: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x403704: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x403706: 7420 JZ 0x00403728
    if(integer::condition("JZ",flags)) goto L00403728;
  }
  L00403708: { // 0x403708: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40370a: e8013c0000 CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x40370f: 83fbff CMP EBX,-0x1
    (void)integer::sub(s.bx,0xffffffffu,32,flags);
  }
  { // 0x403712: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x403714: 7405 JZ 0x0040371b
    if(integer::condition("JZ",flags)) goto L0040371b;
  }
  { // 0x403716: 395f0c CMP dword ptr [EDI + 0xc],EBX
    (void)integer::sub(m.r32((s.di+0x0000000cu)),s.bx,32,flags);
  }
  { // 0x403719: 7507 JNZ 0x00403722
    if(integer::condition("JNZ",flags)) goto L00403722;
  }
  L0040371b: { // 0x40371b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x40371d: e82eeeffff CALL 0x00402550
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00403722: { // 0x403722: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x403724: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x403726: 75e0 JNZ 0x00403708
    if(integer::condition("JNZ",flags)) goto L00403708;
  }
  L00403728: { // 0x403728: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x403729: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40372a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x40372c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x40372d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00003730(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x403730: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x403731: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x403732: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x403733: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x403735: 81c1f8000000 ADD ECX,0xf8
    s.cx = integer::add(s.cx,0x000000f8u,32,flags);
  }
  { // 0x40373b: e8b03b0000 CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x403740: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x403742: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x403744: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x403746: 7420 JZ 0x00403768
    if(integer::condition("JZ",flags)) goto L00403768;
  }
  L00403748: { // 0x403748: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40374a: e8c13b0000 CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x40374f: 83fbff CMP EBX,-0x1
    (void)integer::sub(s.bx,0xffffffffu,32,flags);
  }
  { // 0x403752: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x403754: 7405 JZ 0x0040375b
    if(integer::condition("JZ",flags)) goto L0040375b;
  }
  { // 0x403756: 395f0c CMP dword ptr [EDI + 0xc],EBX
    (void)integer::sub(m.r32((s.di+0x0000000cu)),s.bx,32,flags);
  }
  { // 0x403759: 7507 JNZ 0x00403762
    if(integer::condition("JNZ",flags)) goto L00403762;
  }
  L0040375b: { // 0x40375b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x40375d: e84eeeffff CALL 0x004025b0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00403762: { // 0x403762: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x403764: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x403766: 75e0 JNZ 0x00403748
    if(integer::condition("JNZ",flags)) goto L00403748;
  }
  L00403768: { // 0x403768: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x403769: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40376a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x40376b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00003770(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x403770: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x403771: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x403772: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x403774: 81c1f8000000 ADD ECX,0xf8
    s.cx = integer::add(s.cx,0x000000f8u,32,flags);
  }
  { // 0x40377a: e8713b0000 CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40377f: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x403781: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x403783: 742b JZ 0x004037b0
    if(integer::condition("JZ",flags)) goto L004037b0;
  }
  L00403785: { // 0x403785: f686a400000001 TEST byte ptr [ESI + 0xa4],0x1
    (void)integer::logical((m.r8((s.si+0x000000a4u)))&(0x00000001u),8,flags);
  }
  { // 0x40378c: 7411 JZ 0x0040379f
    if(integer::condition("JZ",flags)) goto L0040379f;
  }
  { // 0x40378e: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  { // 0x403791: 7405 JZ 0x00403798
    if(integer::condition("JZ",flags)) goto L00403798;
  }
  { // 0x403793: 397e0c CMP dword ptr [ESI + 0xc],EDI
    (void)integer::sub(m.r32((s.si+0x0000000cu)),s.di,32,flags);
  }
  { // 0x403796: 7507 JNZ 0x0040379f
    if(integer::condition("JNZ",flags)) goto L0040379f;
  }
  L00403798: { // 0x403798: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40379a: e861eeffff CALL 0x00402600
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0040379f: { // 0x40379f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4037a1: 740d JZ 0x004037b0
    if(integer::condition("JZ",flags)) goto L004037b0;
  }
  { // 0x4037a3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4037a5: e8663b0000 CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4037aa: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4037ac: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4037ae: 75d5 JNZ 0x00403785
    if(integer::condition("JNZ",flags)) goto L00403785;
  }
  L004037b0: { // 0x4037b0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4037b1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4037b2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000037c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4037c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4037c1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4037c2: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x4037c4: 81c1f8000000 ADD ECX,0xf8
    s.cx = integer::add(s.cx,0x000000f8u,32,flags);
  }
  { // 0x4037ca: e8213b0000 CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4037cf: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4037d1: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4037d3: 742b JZ 0x00403800
    if(integer::condition("JZ",flags)) goto L00403800;
  }
  L004037d5: { // 0x4037d5: f686a400000004 TEST byte ptr [ESI + 0xa4],0x4
    (void)integer::logical((m.r8((s.si+0x000000a4u)))&(0x00000004u),8,flags);
  }
  { // 0x4037dc: 7411 JZ 0x004037ef
    if(integer::condition("JZ",flags)) goto L004037ef;
  }
  { // 0x4037de: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  { // 0x4037e1: 7405 JZ 0x004037e8
    if(integer::condition("JZ",flags)) goto L004037e8;
  }
  { // 0x4037e3: 397e0c CMP dword ptr [ESI + 0xc],EDI
    (void)integer::sub(m.r32((s.si+0x0000000cu)),s.di,32,flags);
  }
  { // 0x4037e6: 7507 JNZ 0x004037ef
    if(integer::condition("JNZ",flags)) goto L004037ef;
  }
  L004037e8: { // 0x4037e8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4037ea: e861eeffff CALL 0x00402650
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L004037ef: { // 0x4037ef: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4037f1: 740d JZ 0x00403800
    if(integer::condition("JZ",flags)) goto L00403800;
  }
  { // 0x4037f3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4037f5: e8163b0000 CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4037fa: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4037fc: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4037fe: 75d5 JNZ 0x004037d5
    if(integer::condition("JNZ",flags)) goto L004037d5;
  }
  L00403800: { // 0x403800: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x403801: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x403802: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00004d60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x404d60: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x404d61: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x404d62: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x404d64: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x404d66: 8b87a8000000 MOV EAX,dword ptr [EDI + 0xa8]
    s.ax = m.r32((s.di+0x000000a8u));
  }
  { // 0x404d6c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x404d6e: 7e2d JLE 0x00404d9d
    if(integer::condition("JLE",flags)) goto L00404d9d;
  }
  { // 0x404d70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x404d71: 8d7728 LEA ESI,[EDI + 0x28]
    s.si = (s.di+0x00000028u);
  }
  L00404d74: { // 0x404d74: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x404d76: e815d2ffff CALL 0x00401f90
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x404d7b: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x404d81: 8b87a8000000 MOV EAX,dword ptr [EDI + 0xa8]
    s.ax = m.r32((s.di+0x000000a8u));
  }
  { // 0x404d87: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x404d88: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x404d8b: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x404d8d: 7ce5 JL 0x00404d74
    if(integer::condition("JL",flags)) goto L00404d74;
  }
  { // 0x404d8f: c787a800000000000000 MOV dword ptr [EDI + 0xa8],0x0
    m.w32((s.di+0x000000a8u), 0x00000000u);
  }
  { // 0x404d99: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x404d9a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x404d9b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x404d9c: c3 RET
    finish(m,s,f,0u); return;
  }
  L00404d9d: { // 0x404d9d: c787a800000000000000 MOV dword ptr [EDI + 0xa8],0x0
    m.w32((s.di+0x000000a8u), 0x00000000u);
  }
  { // 0x404da7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x404da8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x404da9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00004e00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x404e00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x404e01: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x404e02: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x404e03: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  { // 0x404e05: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x404e06: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x404e08: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x404e09: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  { // 0x404e0d: bb988e8100 MOV EBX,0x818e98
    s.bx = 0x00818e98u;
  }
  { // 0x404e12: 7e24 JLE 0x00404e38
    if(integer::condition("JLE",flags)) goto L00404e38;
  }
  L00404e14: { // 0x404e14: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x404e16: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L00404e18: { // 0x404e18: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x404e1a: e8d1240000 CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x404e1f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x404e21: 751d JNZ 0x00404e40
    if(integer::condition("JNZ",flags)) goto L00404e40;
  }
  { // 0x404e23: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x404e24: 83c60c ADD ESI,0xc
    s.si = integer::add(s.si,0x0000000cu,32,flags);
  }
  { // 0x404e27: 83ff0a CMP EDI,0xa
    (void)integer::sub(s.di,0x0000000au,32,flags);
  }
  { // 0x404e2a: 7cec JL 0x00404e18
    if(integer::condition("JL",flags)) goto L00404e18;
  }
  { // 0x404e2c: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x404e30: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  { // 0x404e31: 83c378 ADD EBX,0x78
    s.bx = integer::add(s.bx,0x00000078u,32,flags);
  }
  { // 0x404e34: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x404e36: 7cdc JL 0x00404e14
    if(integer::condition("JL",flags)) goto L00404e14;
  }
  L00404e38: { // 0x404e38: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x404e39: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x404e3a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x404e3b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x404e3d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x404e3e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x404e3f: c3 RET
    finish(m,s,f,0u); return;
  }
  L00404e40: { // 0x404e40: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x404e41: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x404e42: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x404e43: 055cffffff ADD EAX,0xffffff5c
    s.ax = integer::add(s.ax,0xffffff5cu,32,flags);
  }
  { // 0x404e48: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x404e49: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x404e4a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00004fb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x404fb0: a1f8928100 MOV EAX,[0x008192f8]
    s.ax = m.r32((0x008192f8u));
  }
  { // 0x404fb5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x404fb6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x404fb8: 745a JZ 0x00405014
    if(integer::condition("JZ",flags)) goto L00405014;
  }
  { // 0x404fba: 8b35e0918100 MOV ESI,dword ptr [0x008191e0]
    s.si = m.r32((0x008191e0u));
  }
  { // 0x404fc0: 81fee0918100 CMP ESI,0x8191e0
    (void)integer::sub(s.si,0x008191e0u,32,flags);
  }
  { // 0x404fc6: 744c JZ 0x00405014
    if(integer::condition("JZ",flags)) goto L00405014;
  }
  { // 0x404fc8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00404fc9: { // 0x404fc9: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    s.ax = m.r32((s.si+0x00000158u));
  }
  { // 0x404fcf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x404fd1: 7529 JNZ 0x00404ffc
    if(integer::condition("JNZ",flags)) goto L00404ffc;
  }
  { // 0x404fd3: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  { // 0x404fd6: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x404fd9: 7521 JNZ 0x00404ffc
    if(integer::condition("JNZ",flags)) goto L00404ffc;
  }
  { // 0x404fdb: e8f0420000 CALL 0x004092d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x404fe0: 8b8e40010000 MOV ECX,dword ptr [ESI + 0x140]
    s.cx = m.r32((s.si+0x00000140u));
  }
  { // 0x404fe6: 8b9e44010000 MOV EBX,dword ptr [ESI + 0x144]
    s.bx = m.r32((s.si+0x00000144u));
  }
  { // 0x404fec: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x404fee: 1bda SBB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags,flags&integer::CF);
  }
  { // 0x404ff0: 898e40010000 MOV dword ptr [ESI + 0x140],ECX
    m.w32((s.si+0x00000140u), s.cx);
  }
  { // 0x404ff6: 899e44010000 MOV dword ptr [ESI + 0x144],EBX
    m.w32((s.si+0x00000144u), s.bx);
  }
  L00404ffc: { // 0x404ffc: 8b9658010000 MOV EDX,dword ptr [ESI + 0x158]
    s.dx = m.r32((s.si+0x00000158u));
  }
  { // 0x405002: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  { // 0x405003: 899658010000 MOV dword ptr [ESI + 0x158],EDX
    m.w32((s.si+0x00000158u), s.dx);
  }
  { // 0x405009: 8b36 MOV ESI,dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  { // 0x40500b: 81fee0918100 CMP ESI,0x8191e0
    (void)integer::sub(s.si,0x008191e0u,32,flags);
  }
  { // 0x405011: 75b6 JNZ 0x00404fc9
    if(integer::condition("JNZ",flags)) goto L00404fc9;
  }
  { // 0x405013: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00405014: { // 0x405014: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x405015: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00005020(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x405020: a1f8928100 MOV EAX,[0x008192f8]
    s.ax = m.r32((0x008192f8u));
  }
  { // 0x405025: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x405026: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x405028: 7472 JZ 0x0040509c
    if(integer::condition("JZ",flags)) goto L0040509c;
  }
  { // 0x40502a: 8b35e0918100 MOV ESI,dword ptr [0x008191e0]
    s.si = m.r32((0x008191e0u));
  }
  { // 0x405030: 81fee0918100 CMP ESI,0x8191e0
    (void)integer::sub(s.si,0x008191e0u,32,flags);
  }
  { // 0x405036: 7464 JZ 0x0040509c
    if(integer::condition("JZ",flags)) goto L0040509c;
  }
  { // 0x405038: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00405039: { // 0x405039: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    s.ax = m.r32((s.si+0x00000158u));
  }
  { // 0x40503f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x405041: 744e JZ 0x00405091
    if(integer::condition("JZ",flags)) goto L00405091;
  }
  { // 0x405043: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    s.ax = m.r32((s.si+0x00000158u));
  }
  { // 0x405049: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x40504a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x40504c: 898658010000 MOV dword ptr [ESI + 0x158],EAX
    m.w32((s.si+0x00000158u), s.ax);
  }
  { // 0x405052: 7d0a JGE 0x0040505e
    if(integer::condition("JGE",flags)) goto L0040505e;
  }
  { // 0x405054: c7865801000000000000 MOV dword ptr [ESI + 0x158],0x0
    m.w32((s.si+0x00000158u), 0x00000000u);
  }
  L0040505e: { // 0x40505e: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    s.ax = m.r32((s.si+0x00000158u));
  }
  { // 0x405064: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x405066: 7529 JNZ 0x00405091
    if(integer::condition("JNZ",flags)) goto L00405091;
  }
  { // 0x405068: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  { // 0x40506b: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x40506e: 7521 JNZ 0x00405091
    if(integer::condition("JNZ",flags)) goto L00405091;
  }
  { // 0x405070: e85b420000 CALL 0x004092d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x405075: 8b8e40010000 MOV ECX,dword ptr [ESI + 0x140]
    s.cx = m.r32((s.si+0x00000140u));
  }
  { // 0x40507b: 8bae44010000 MOV EBP,dword ptr [ESI + 0x144]
    s.bp = m.r32((s.si+0x00000144u));
  }
  { // 0x405081: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x405083: 13d5 ADC EDX,EBP
    s.dx = integer::add(s.dx,s.bp,32,flags,flags&integer::CF);
  }
  { // 0x405085: 898640010000 MOV dword ptr [ESI + 0x140],EAX
    m.w32((s.si+0x00000140u), s.ax);
  }
  { // 0x40508b: 899644010000 MOV dword ptr [ESI + 0x144],EDX
    m.w32((s.si+0x00000144u), s.dx);
  }
  L00405091: { // 0x405091: 8b36 MOV ESI,dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  { // 0x405093: 81fee0918100 CMP ESI,0x8191e0
    (void)integer::sub(s.si,0x008191e0u,32,flags);
  }
  { // 0x405099: 759e JNZ 0x00405039
    if(integer::condition("JNZ",flags)) goto L00405039;
  }
  { // 0x40509b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0040509c: { // 0x40509c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40509d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000067e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4067e0: a1787a7b00 MOV EAX,[0x007b7a78]
    s.ax = m.r32((0x007b7a78u));
  }
  { // 0x4067e5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4067e6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4067e7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4067e8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4067ea: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x4067ec: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x4067ee: be787a7b00 MOV ESI,0x7b7a78
    s.si = 0x007b7a78u;
  }
  { // 0x4067f3: 741a JZ 0x0040680f
    if(integer::condition("JZ",flags)) goto L0040680f;
  }
  L004067f5: { // 0x4067f5: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4067f7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4067f8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4067f9: e862703600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4067fe: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x406801: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x406803: 740a JZ 0x0040680f
    if(integer::condition("JZ",flags)) goto L0040680f;
  }
  { // 0x406805: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x406808: 83c608 ADD ESI,0x8
    s.si = integer::add(s.si,0x00000008u,32,flags);
  }
  { // 0x40680b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x40680d: 75e6 JNZ 0x004067f5
    if(integer::condition("JNZ",flags)) goto L004067f5;
  }
  L0040680f: { // 0x40680f: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x406811: 7405 JZ 0x00406818
    if(integer::condition("JZ",flags)) goto L00406818;
  }
  { // 0x406813: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x406816: 890b MOV dword ptr [EBX],ECX
    m.w32((s.bx), s.cx);
  }
  L00406818: { // 0x406818: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x40681a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x40681c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x40681e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x40681f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x406820: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x406823: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x406824: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00006830(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x406830: a1207b7b00 MOV EAX,[0x007b7b20]
    s.ax = m.r32((0x007b7b20u));
  }
  { // 0x406835: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x406836: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x406837: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x406838: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x40683a: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x40683c: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x40683e: be207b7b00 MOV ESI,0x7b7b20
    s.si = 0x007b7b20u;
  }
  { // 0x406843: 741a JZ 0x0040685f
    if(integer::condition("JZ",flags)) goto L0040685f;
  }
  L00406845: { // 0x406845: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x406847: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x406848: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x406849: e812703600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40684e: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x406851: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x406853: 740a JZ 0x0040685f
    if(integer::condition("JZ",flags)) goto L0040685f;
  }
  { // 0x406855: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x406858: 83c608 ADD ESI,0x8
    s.si = integer::add(s.si,0x00000008u,32,flags);
  }
  { // 0x40685b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x40685d: 75e6 JNZ 0x00406845
    if(integer::condition("JNZ",flags)) goto L00406845;
  }
  L0040685f: { // 0x40685f: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x406861: 7409 JZ 0x0040686c
    if(integer::condition("JZ",flags)) goto L0040686c;
  }
  { // 0x406863: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x406866: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  { // 0x406868: 0bc1 OR EAX,ECX
    s.ax = integer::logical((s.ax)|(s.cx),32,flags);
  }
  { // 0x40686a: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L0040686c: { // 0x40686c: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x40686e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x406870: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x406872: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x406873: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x406874: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x406877: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x406878: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00006880(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x406880: a1a87a7b00 MOV EAX,[0x007b7aa8]
    s.ax = m.r32((0x007b7aa8u));
  }
  { // 0x406885: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x406886: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x406887: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x406888: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x40688a: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x40688c: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x40688e: bea87a7b00 MOV ESI,0x7b7aa8
    s.si = 0x007b7aa8u;
  }
  { // 0x406893: 741a JZ 0x004068af
    if(integer::condition("JZ",flags)) goto L004068af;
  }
  L00406895: { // 0x406895: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x406897: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x406898: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x406899: e8c26f3600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40689e: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4068a1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4068a3: 740a JZ 0x004068af
    if(integer::condition("JZ",flags)) goto L004068af;
  }
  { // 0x4068a5: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x4068a8: 83c608 ADD ESI,0x8
    s.si = integer::add(s.si,0x00000008u,32,flags);
  }
  { // 0x4068ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4068ad: 75e6 JNZ 0x00406895
    if(integer::condition("JNZ",flags)) goto L00406895;
  }
  L004068af: { // 0x4068af: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x4068b1: 7422 JZ 0x004068d5
    if(integer::condition("JZ",flags)) goto L004068d5;
  }
  { // 0x4068b3: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x4068b6: a860 TEST AL,0x60
    (void)integer::logical(((s.ax & 0xffu))&(0x00000060u),8,flags);
  }
  { // 0x4068b8: 7406 JZ 0x004068c0
    if(integer::condition("JZ",flags)) goto L004068c0;
  }
  { // 0x4068ba: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x4068bc: 249f AND AL,0x9f
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x0000009fu),8,flags));
  }
  { // 0x4068be: eb0a JMP 0x004068ca
    goto L004068ca;
  }
  L004068c0: { // 0x4068c0: f6c40c TEST AH,0xc
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x0000000cu),8,flags);
  }
  { // 0x4068c3: 7407 JZ 0x004068cc
    if(integer::condition("JZ",flags)) goto L004068cc;
  }
  { // 0x4068c5: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x4068c7: 80e4f3 AND AH,0xf3
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))&(0x000000f3u),8,flags)) & 0xffu) << 8);
  }
  L004068ca: { // 0x4068ca: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L004068cc: { // 0x4068cc: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x4068cf: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x4068d1: 0bc1 OR EAX,ECX
    s.ax = integer::logical((s.ax)|(s.cx),32,flags);
  }
  { // 0x4068d3: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L004068d5: { // 0x4068d5: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x4068d7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4068d9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4068db: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4068dc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4068dd: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x4068e0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4068e1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00006fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x406fe0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x406fe1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x406fe2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x406fe3: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x406fe5: e8e6220000 CALL 0x004092d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x406fea: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x406fed: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x406fef: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x406ff2: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x406ff4: 8b5614 MOV EDX,dword ptr [ESI + 0x14]
    s.dx = m.r32((s.si+0x00000014u));
  }
  { // 0x406ff7: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  { // 0x406ff9: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x406ffc: 13fa ADC EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags,flags&integer::CF);
  }
  { // 0x406ffe: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x407000: 741e JZ 0x00407020
    if(integer::condition("JZ",flags)) goto L00407020;
  }
  L00407002: { // 0x407002: e8c9220000 CALL 0x004092d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x407007: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  { // 0x407009: 7715 JA 0x00407020
    if(integer::condition("JA",flags)) goto L00407020;
  }
  { // 0x40700b: 7204 JC 0x00407011
    if(integer::condition("JC",flags)) goto L00407011;
  }
  { // 0x40700d: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x40700f: 730f JNC 0x00407020
    if(integer::condition("JNC",flags)) goto L00407020;
  }
  L00407011: { // 0x407011: e8cab10700 CALL 0x004821e0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x407016: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x407019: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x40701c: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x40701e: 75e2 JNZ 0x00407002
    if(integer::condition("JNZ",flags)) goto L00407002;
  }
  L00407020: { // 0x407020: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x407021: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x407022: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x407023: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00008010(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x408010: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x408011: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x408012: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x408013: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x408015: e8b6120000 CALL 0x004092d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40801a: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  { // 0x40801c: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x40801f: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x408021: 036820 ADD EBP,dword ptr [EAX + 0x20]
    s.bp = integer::add(s.bp,m.r32((s.ax+0x00000020u)),32,flags);
  }
  { // 0x408024: 137824 ADC EDI,dword ptr [EAX + 0x24]
    s.di = integer::add(s.di,m.r32((s.ax+0x00000024u)),32,flags,flags&integer::CF);
  }
  L00408027: { // 0x408027: f6460c01 TEST byte ptr [ESI + 0xc],0x1
    (void)integer::logical((m.r8((s.si+0x0000000cu)))&(0x00000001u),8,flags);
  }
  { // 0x40802b: 7423 JZ 0x00408050
    if(integer::condition("JZ",flags)) goto L00408050;
  }
  { // 0x40802d: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x408030: 8b4814 MOV ECX,dword ptr [EAX + 0x14]
    s.cx = m.r32((s.ax+0x00000014u));
  }
  { // 0x408033: 8b5018 MOV EDX,dword ptr [EAX + 0x18]
    s.dx = m.r32((s.ax+0x00000018u));
  }
  { // 0x408036: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x408038: 7416 JZ 0x00408050
    if(integer::condition("JZ",flags)) goto L00408050;
  }
  { // 0x40803a: e891120000 CALL 0x004092d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x40803f: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  { // 0x408041: 770d JA 0x00408050
    if(integer::condition("JA",flags)) goto L00408050;
  }
  { // 0x408043: 7204 JC 0x00408049
    if(integer::condition("JC",flags)) goto L00408049;
  }
  { // 0x408045: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x408047: 7307 JNC 0x00408050
    if(integer::condition("JNC",flags)) goto L00408050;
  }
  L00408049: { // 0x408049: e892a10700 CALL 0x004821e0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x40804e: ebd7 JMP 0x00408027
    goto L00408027;
  }
  L00408050: { // 0x408050: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x408051: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x408052: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x408053: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000080c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4080c0: a16c988100 MOV EAX,[0x0081986c]
    s.ax = m.r32((0x0081986cu));
  }
  { // 0x4080c5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4080c6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4080c8: 7454 JZ 0x0040811e
    if(integer::condition("JZ",flags)) goto L0040811e;
  }
  { // 0x4080ca: b960988100 MOV ECX,0x819860
    s.cx = 0x00819860u;
  }
  { // 0x4080cf: e81cf2ffff CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4080d4: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4080d6: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4080d8: 7444 JZ 0x0040811e
    if(integer::condition("JZ",flags)) goto L0040811e;
  }
  { // 0x4080da: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4080db: 8b1de0517800 MOV EBX,dword ptr [0x007851e0]
    s.bx = m.r32((0x007851e0u));
  }
  { // 0x4080e1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4080e2: 8b3ddc517800 MOV EDI,dword ptr [0x007851dc]
    s.di = m.r32((0x007851dcu));
  }
  L004080e8: { // 0x4080e8: 8b8688000000 MOV EAX,dword ptr [ESI + 0x88]
    s.ax = m.r32((s.si+0x00000088u));
  }
  { // 0x4080ee: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4080f0: 751d JNZ 0x0040810f
    if(integer::condition("JNZ",flags)) goto L0040810f;
  }
  { // 0x4080f2: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x4080f5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4080f7: 7416 JZ 0x0040810f
    if(integer::condition("JZ",flags)) goto L0040810f;
  }
  { // 0x4080f9: 6848988100 PUSH 0x819848
    f.push(m,0x00819848u);
  }
  { // 0x4080fe: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x408100: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x408103: e8a8a4ffff CALL 0x004025b0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x408108: 6848988100 PUSH 0x819848
    f.push(m,0x00819848u);
  }
  { // 0x40810d: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L0040810f: { // 0x40810f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x408111: e8faf1ffff CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x408116: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x408118: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x40811a: 75cc JNZ 0x004080e8
    if(integer::condition("JNZ",flags)) goto L004080e8;
  }
  { // 0x40811c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x40811d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0040811e: { // 0x40811e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40811f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00008120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x408120: a16c988100 MOV EAX,[0x0081986c]
    s.ax = m.r32((0x0081986cu));
  }
  { // 0x408125: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x408127: 7426 JZ 0x0040814f
    if(integer::condition("JZ",flags)) goto L0040814f;
  }
  { // 0x408129: b960988100 MOV ECX,0x819860
    s.cx = 0x00819860u;
  }
  { // 0x40812e: e8bdf1ffff CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x408133: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x408135: 7418 JZ 0x0040814f
    if(integer::condition("JZ",flags)) goto L0040814f;
  }
  L00408137: { // 0x408137: 8b8888000000 MOV ECX,dword ptr [EAX + 0x88]
    s.cx = m.r32((s.ax+0x00000088u));
  }
  { // 0x40813d: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x40813e: 898888000000 MOV dword ptr [EAX + 0x88],ECX
    m.w32((s.ax+0x00000088u), s.cx);
  }
  { // 0x408144: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x408146: e8c5f1ffff CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x40814b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x40814d: 75e8 JNZ 0x00408137
    if(integer::condition("JNZ",flags)) goto L00408137;
  }
  L0040814f: { // 0x40814f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00008150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x408150: a16c988100 MOV EAX,[0x0081986c]
    s.ax = m.r32((0x0081986cu));
  }
  { // 0x408155: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x408157: 7434 JZ 0x0040818d
    if(integer::condition("JZ",flags)) goto L0040818d;
  }
  { // 0x408159: b960988100 MOV ECX,0x819860
    s.cx = 0x00819860u;
  }
  { // 0x40815e: e88df1ffff CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x408163: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x408165: 7426 JZ 0x0040818d
    if(integer::condition("JZ",flags)) goto L0040818d;
  }
  L00408167: { // 0x408167: 8b8888000000 MOV ECX,dword ptr [EAX + 0x88]
    s.cx = m.r32((s.ax+0x00000088u));
  }
  { // 0x40816d: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x40816e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x408170: 898888000000 MOV dword ptr [EAX + 0x88],ECX
    m.w32((s.ax+0x00000088u), s.cx);
  }
  { // 0x408176: 7d0a JGE 0x00408182
    if(integer::condition("JGE",flags)) goto L00408182;
  }
  { // 0x408178: c7808800000000000000 MOV dword ptr [EAX + 0x88],0x0
    m.w32((s.ax+0x00000088u), 0x00000000u);
  }
  L00408182: { // 0x408182: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x408184: e887f1ffff CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x408189: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x40818b: 75da JNZ 0x00408167
    if(integer::condition("JNZ",flags)) goto L00408167;
  }
  L0040818d: { // 0x40818d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00008190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x408190: a16c988100 MOV EAX,[0x0081986c]
    s.ax = m.r32((0x0081986cu));
  }
  { // 0x408195: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x408196: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x408198: 746f JZ 0x00408209
    if(integer::condition("JZ",flags)) goto L00408209;
  }
  { // 0x40819a: b960988100 MOV ECX,0x819860
    s.cx = 0x00819860u;
  }
  { // 0x40819f: e84cf1ffff CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4081a4: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4081a6: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4081a8: 745f JZ 0x00408209
    if(integer::condition("JZ",flags)) goto L00408209;
  }
  { // 0x4081aa: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4081ab: 8b1de0517800 MOV EBX,dword ptr [0x007851e0]
    s.bx = m.r32((0x007851e0u));
  }
  { // 0x4081b1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4081b2: 8b3ddc517800 MOV EDI,dword ptr [0x007851dc]
    s.di = m.r32((0x007851dcu));
  }
  L004081b8: { // 0x4081b8: 8b8680000000 MOV EAX,dword ptr [ESI + 0x80]
    s.ax = m.r32((s.si+0x00000080u));
  }
  { // 0x4081be: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4081c0: 752b JNZ 0x004081ed
    if(integer::condition("JNZ",flags)) goto L004081ed;
  }
  { // 0x4081c2: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x4081c5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4081c7: 7424 JZ 0x004081ed
    if(integer::condition("JZ",flags)) goto L004081ed;
  }
  { // 0x4081c9: 6848988100 PUSH 0x819848
    f.push(m,0x00819848u);
  }
  { // 0x4081ce: ffd7 CALL EDI
    const std::uint32_t call_target=s.di;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4081d0: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x4081d3: e828a4ffff CALL 0x00402600
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4081d8: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x4081db: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x4081dd: 7407 JZ 0x004081e6
    if(integer::condition("JZ",flags)) goto L004081e6;
  }
  { // 0x4081df: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  { // 0x4081e1: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  { // 0x4081e3: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L004081e6: { // 0x4081e6: 6848988100 PUSH 0x819848
    f.push(m,0x00819848u);
  }
  { // 0x4081eb: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L004081ed: { // 0x4081ed: 8b8680000000 MOV EAX,dword ptr [ESI + 0x80]
    s.ax = m.r32((s.si+0x00000080u));
  }
  { // 0x4081f3: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x4081f4: 898680000000 MOV dword ptr [ESI + 0x80],EAX
    m.w32((s.si+0x00000080u), s.ax);
  }
  { // 0x4081fa: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4081fc: e80ff1ffff CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x408201: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x408203: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x408205: 75b1 JNZ 0x004081b8
    if(integer::condition("JNZ",flags)) goto L004081b8;
  }
  { // 0x408207: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x408208: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00408209: { // 0x408209: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40820a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000082b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4082b0: a16c988100 MOV EAX,[0x0081986c]
    s.ax = m.r32((0x0081986cu));
  }
  { // 0x4082b5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4082b6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4082b8: 742a JZ 0x004082e4
    if(integer::condition("JZ",flags)) goto L004082e4;
  }
  { // 0x4082ba: b960988100 MOV ECX,0x819860
    s.cx = 0x00819860u;
  }
  { // 0x4082bf: e82cf0ffff CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4082c4: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4082c6: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4082c8: 741a JZ 0x004082e4
    if(integer::condition("JZ",flags)) goto L004082e4;
  }
  L004082ca: { // 0x4082ca: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x4082cd: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x4082cf: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  { // 0x4082d2: e8c9edffff CALL 0x004070a0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4082d7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4082d9: e832f0ffff CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4082de: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4082e0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4082e2: 75e6 JNZ 0x004082ca
    if(integer::condition("JNZ",flags)) goto L004082ca;
  }
  L004082e4: { // 0x4082e4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4082e5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000082f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4082f0: a16c988100 MOV EAX,[0x0081986c]
    s.ax = m.r32((0x0081986cu));
  }
  { // 0x4082f5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4082f6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4082f8: 742d JZ 0x00408327
    if(integer::condition("JZ",flags)) goto L00408327;
  }
  { // 0x4082fa: b960988100 MOV ECX,0x819860
    s.cx = 0x00819860u;
  }
  { // 0x4082ff: e8ecefffff CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x408304: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x408306: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x408308: 741d JZ 0x00408327
    if(integer::condition("JZ",flags)) goto L00408327;
  }
  L0040830a: { // 0x40830a: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x40830d: ba00400000 MOV EDX,0x4000
    s.dx = 0x00004000u;
  }
  { // 0x408312: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  { // 0x408315: e886edffff CALL 0x004070a0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x40831a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x40831c: e8efefffff CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x408321: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x408323: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x408325: 75e3 JNZ 0x0040830a
    if(integer::condition("JNZ",flags)) goto L0040830a;
  }
  L00408327: { // 0x408327: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x408328: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00008330(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x408330: a16c988100 MOV EAX,[0x0081986c]
    s.ax = m.r32((0x0081986cu));
  }
  { // 0x408335: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x408336: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x408338: 7432 JZ 0x0040836c
    if(integer::condition("JZ",flags)) goto L0040836c;
  }
  { // 0x40833a: b960988100 MOV ECX,0x819860
    s.cx = 0x00819860u;
  }
  { // 0x40833f: e8acefffff CALL 0x004072f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x408344: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x408346: 7424 JZ 0x0040836c
    if(integer::condition("JZ",flags)) goto L0040836c;
  }
  L00408348: { // 0x408348: f6400c01 TEST byte ptr [EAX + 0xc],0x1
    (void)integer::logical((m.r8((s.ax+0x0000000cu)))&(0x00000001u),8,flags);
  }
  { // 0x40834c: 740d JZ 0x0040835b
    if(integer::condition("JZ",flags)) goto L0040835b;
  }
  { // 0x40834e: 8b4814 MOV ECX,dword ptr [EAX + 0x14]
    s.cx = m.r32((s.ax+0x00000014u));
  }
  { // 0x408351: 8b5114 MOV EDX,dword ptr [ECX + 0x14]
    s.dx = m.r32((s.cx+0x00000014u));
  }
  { // 0x408354: 8b7118 MOV ESI,dword ptr [ECX + 0x18]
    s.si = m.r32((s.cx+0x00000018u));
  }
  { // 0x408357: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  { // 0x408359: 750d JNZ 0x00408368
    if(integer::condition("JNZ",flags)) goto L00408368;
  }
  L0040835b: { // 0x40835b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x40835d: e8aeefffff CALL 0x00407310
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x408362: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x408364: 7406 JZ 0x0040836c
    if(integer::condition("JZ",flags)) goto L0040836c;
  }
  { // 0x408366: ebe0 JMP 0x00408348
    goto L00408348;
  }
  L00408368: { // 0x408368: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x40836a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40836b: c3 RET
    finish(m,s,f,0u); return;
  }
  L0040836c: { // 0x40836c: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x408371: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x408372: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0000db90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x40db90: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x40db91: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x40db92: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x40db93: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x40db95: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x40db97: be08897b00 MOV ESI,0x7b8908
    s.si = 0x007b8908u;
  }
  L0040db9c: { // 0x40db9c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x40db9e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x40db9f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x40dba0: e8bbfc3500 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x40dba5: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x40dba8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x40dbaa: 7412 JZ 0x0040dbbe
    if(integer::condition("JZ",flags)) goto L0040dbbe;
  }
  { // 0x40dbac: 83c608 ADD ESI,0x8
    s.si = integer::add(s.si,0x00000008u,32,flags);
  }
  { // 0x40dbaf: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x40dbb0: 81fe408b7b00 CMP ESI,0x7b8b40
    (void)integer::sub(s.si,0x007b8b40u,32,flags);
  }
  { // 0x40dbb6: 7ce4 JL 0x0040db9c
    if(integer::condition("JL",flags)) goto L0040db9c;
  }
  { // 0x40dbb8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x40dbb9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40dbba: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x40dbbc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x40dbbd: c3 RET
    finish(m,s,f,0u); return;
  }
  L0040dbbe: { // 0x40dbbe: 8b04fd0c897b00 MOV EAX,dword ptr [EDI*0x8 + 0x7b890c]
    s.ax = m.r32(((s.di * 0x00000008u)+0x007b890cu));
  }
  { // 0x40dbc5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x40dbc6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x40dbc7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x40dbc8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000125d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4125d0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4125d1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4125d2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4125d3: bee0218200 MOV ESI,0x8221e0
    s.si = 0x008221e0u;
  }
  { // 0x4125d8: bf90010000 MOV EDI,0x190
    s.di = 0x00000190u;
  }
  { // 0x4125dd: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004125df: { // 0x4125df: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4125e0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4125e1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4125e3: e82896ffff CALL 0x0040bc10
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4125e8: c7069c577800 MOV dword ptr [ESI],0x78579c
    m.w32((s.si), 0x0078579cu);
  }
  { // 0x4125ee: c746140a000000 MOV dword ptr [ESI + 0x14],0xa
    m.w32((s.si+0x00000014u), 0x0000000au);
  }
  { // 0x4125f5: 895e10 MOV dword ptr [ESI + 0x10],EBX
    m.w32((s.si+0x00000010u), s.bx);
  }
  { // 0x4125f8: 83c618 ADD ESI,0x18
    s.si = integer::add(s.si,0x00000018u,32,flags);
  }
  { // 0x4125fb: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x4125fc: 75e1 JNZ 0x004125df
    if(integer::condition("JNZ",flags)) goto L004125df;
  }
  { // 0x4125fe: 6850264100 PUSH 0x412650
    f.push(m,0x00412650u);
  }
  { // 0x412603: 891d64478200 MOV dword ptr [0x00824764],EBX
    m.w32((0x00824764u), s.bx);
  }
  { // 0x412609: 891d68478200 MOV dword ptr [0x00824768],EBX
    m.w32((0x00824768u), s.bx);
  }
  { // 0x41260f: c6056c47820001 MOV byte ptr [0x0082476c],0x1
    m.w8((0x0082476cu), 0x00000001u);
  }
  { // 0x412616: 881d6d478200 MOV byte ptr [0x0082476d],BL
    m.w8((0x0082476du), (s.bx & 0xffu));
  }
  { // 0x41261c: c705604782009c577800 MOV dword ptr [0x00824760],0x78579c
    m.w32((0x00824760u), 0x0078579cu);
  }
  { // 0x412626: c705744782000a000000 MOV dword ptr [0x00824774],0xa
    m.w32((0x00824774u), 0x0000000au);
  }
  { // 0x412630: 891d70478200 MOV dword ptr [0x00824770],EBX
    m.w32((0x00824770u), s.bx);
  }
  { // 0x412636: e88fbc3500 CALL 0x0076e2ca
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x41263b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x41263e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x41263f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x412640: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x412641: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00012720(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x412720: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x412724: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x412725: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x412726: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x412728: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  { // 0x41272b: 8d3cc1 LEA EDI,[ECX + EAX*0x8]
    s.di = (s.cx+(s.ax * 0x00000008u));
  }
  { // 0x41272e: 8b44c110 MOV EAX,dword ptr [ECX + EAX*0x8 + 0x10]
    s.ax = m.r32((s.cx+(s.ax * 0x00000008u)+0x00000010u));
  }
  { // 0x412732: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x412734: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  { // 0x412738: 7e58 JLE 0x00412792
    if(integer::condition("JLE",flags)) goto L00412792;
  }
  { // 0x41273a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x41273b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41273c: 8db180250000 LEA ESI,[ECX + 0x2580]
    s.si = (s.cx+0x00002580u);
  }
  L00412742: { // 0x412742: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  { // 0x412744: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x412745: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x412747: ff5218 CALL dword ptr [EDX + 0x18]
    const std::uint32_t call_target=m.r32((s.dx+0x00000018u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x41274a: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x41274d: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  { // 0x41274f: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x412752: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x412754: 7c22 JL 0x00412778
    if(integer::condition("JL",flags)) goto L00412778;
  }
  { // 0x412756: 8a4e0d MOV CL,byte ptr [ESI + 0xd]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000000du)));
  }
  { // 0x412759: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x41275b: 7504 JNZ 0x00412761
    if(integer::condition("JNZ",flags)) goto L00412761;
  }
  { // 0x41275d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x41275f: 7526 JNZ 0x00412787
    if(integer::condition("JNZ",flags)) goto L00412787;
  }
  L00412761: { // 0x412761: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x412764: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x412766: 7e1f JLE 0x00412787
    if(integer::condition("JLE",flags)) goto L00412787;
  }
  { // 0x412768: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x41276a: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x41276c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x41276e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x41276f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x412771: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x412774: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x412776: 740f JZ 0x00412787
    if(integer::condition("JZ",flags)) goto L00412787;
  }
  L00412778: { // 0x412778: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x41277b: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x41277e: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  { // 0x412781: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x412784: 892c82 MOV dword ptr [EDX + EAX*0x4],EBP
    m.w32((s.dx+(s.ax * 0x00000004u)), s.bp);
  }
  L00412787: { // 0x412787: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x41278b: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x41278c: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x41278e: 7cb2 JL 0x00412742
    if(integer::condition("JL",flags)) goto L00412742;
  }
  { // 0x412790: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x412791: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00412792: { // 0x412792: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x412793: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x412794: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00013540(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x413540: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x413541: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x413542: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  { // 0x413544: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x413545: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x413546: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  { // 0x413548: bb90010000 MOV EBX,0x190
    s.bx = 0x00000190u;
  }
  L0041354d: { // 0x41354d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x41354f: 8b7e08 MOV EDI,dword ptr [ESI + 0x8]
    s.di = m.r32((s.si+0x00000008u));
  }
  { // 0x413552: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x413554: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x413557: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x413559: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x41355b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x41355c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x41355e: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x413561: 83c618 ADD ESI,0x18
    s.si = integer::add(s.si,0x00000018u,32,flags);
  }
  { // 0x413564: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x413565: 75e6 JNZ 0x0041354d
    if(integer::condition("JNZ",flags)) goto L0041354d;
  }
  { // 0x413567: 8b8580250000 MOV EAX,dword ptr [EBP + 0x2580]
    s.ax = m.r32((s.bp+0x00002580u));
  }
  { // 0x41356d: 8bbd88250000 MOV EDI,dword ptr [EBP + 0x2588]
    s.di = m.r32((s.bp+0x00002588u));
  }
  { // 0x413573: 8db580250000 LEA ESI,[EBP + 0x2580]
    s.si = (s.bp+0x00002580u);
  }
  { // 0x413579: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x41357b: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x41357e: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x413580: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x413582: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x413583: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x413585: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x413588: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x413589: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41358a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x41358b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x41358c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00013590(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x413590: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x413591: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x413592: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x413593: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  { // 0x413597: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x413598: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  { // 0x41359a: 8d7904 LEA EDI,[ECX + 0x4]
    s.di = (s.cx+0x00000004u);
  }
  L0041359d: { // 0x41359d: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  { // 0x4135a0: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x4135a2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4135a4: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  { // 0x4135a8: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x4135aa: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4135ab: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4135ac: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  { // 0x4135b0: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4135b3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4135b5: 7c35 JL 0x004135ec
    if(integer::condition("JL",flags)) goto L004135ec;
  }
  { // 0x4135b7: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x4135bb: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x4135bd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4135bf: 7e1d JLE 0x004135de
    if(integer::condition("JLE",flags)) goto L004135de;
  }
  L004135c1: { // 0x4135c1: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x4135c3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4135c5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4135c7: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x4135c9: 8d1499 LEA EDX,[ECX + EBX*0x4]
    s.dx = (s.cx+(s.bx * 0x00000004u));
  }
  { // 0x4135cc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4135cd: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4135ce: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4135d1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4135d3: 7c17 JL 0x004135ec
    if(integer::condition("JL",flags)) goto L004135ec;
  }
  { // 0x4135d5: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x4135d9: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x4135da: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x4135dc: 7ce3 JL 0x004135c1
    if(integer::condition("JL",flags)) goto L004135c1;
  }
  L004135de: { // 0x4135de: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  { // 0x4135df: 83c718 ADD EDI,0x18
    s.di = integer::add(s.di,0x00000018u,32,flags);
  }
  { // 0x4135e2: 81fd90010000 CMP EBP,0x190
    (void)integer::sub(s.bp,0x00000190u,32,flags);
  }
  { // 0x4135e8: 7cb3 JL 0x0041359d
    if(integer::condition("JL",flags)) goto L0041359d;
  }
  { // 0x4135ea: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004135ec: { // 0x4135ec: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4135ed: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4135ee: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4135ef: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4135f0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0001b890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41b890: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x41b891: 8a5c2408 MOV BL,byte ptr [ESP + 0x8]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000008u)));
  }
  { // 0x41b895: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41b896: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x41b898: f6c302 TEST BL,0x2
    (void)integer::logical(((s.bx & 0xffu))&(0x00000002u),8,flags);
  }
  { // 0x41b89b: 7438 JZ 0x0041b8d5
    if(integer::condition("JZ",flags)) goto L0041b8d5;
  }
  { // 0x41b89d: 8b46fc MOV EAX,dword ptr [ESI + -0x4]
    s.ax = m.r32((s.si-0x00000004u));
  }
  { // 0x41b8a0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x41b8a1: 8d6efc LEA EBP,[ESI + -0x4]
    s.bp = (s.si-0x00000004u);
  }
  { // 0x41b8a4: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  { // 0x41b8a7: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x41b8a8: 8d348e LEA ESI,[ESI + ECX*0x4]
    s.si = (s.si+(s.cx * 0x00000004u));
  }
  { // 0x41b8ab: 7812 JS 0x0041b8bf
    if(integer::condition("JS",flags)) goto L0041b8bf;
  }
  { // 0x41b8ad: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x41b8ae: 8d7801 LEA EDI,[EAX + 0x1]
    s.di = (s.ax+0x00000001u);
  }
  L0041b8b1: { // 0x41b8b1: 83ee0c SUB ESI,0xc
    s.si = integer::sub(s.si,0x0000000cu,32,flags);
  }
  { // 0x41b8b4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x41b8b6: e805de2f00 CALL 0x007196c0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x41b8bb: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x41b8bc: 75f3 JNZ 0x0041b8b1
    if(integer::condition("JNZ",flags)) goto L0041b8b1;
  }
  { // 0x41b8be: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041b8bf: { // 0x41b8bf: f6c301 TEST BL,0x1
    (void)integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x41b8c2: 7409 JZ 0x0041b8cd
    if(integer::condition("JZ",flags)) goto L0041b8cd;
  }
  { // 0x41b8c4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x41b8c5: e8b11d3500 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x41b8ca: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0041b8cd: { // 0x41b8cd: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  { // 0x41b8cf: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x41b8d0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41b8d1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x41b8d2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0041b8d5: { // 0x41b8d5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x41b8d7: e8e4dd2f00 CALL 0x007196c0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x41b8dc: f6c301 TEST BL,0x1
    (void)integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x41b8df: 7409 JZ 0x0041b8ea
    if(integer::condition("JZ",flags)) goto L0041b8ea;
  }
  { // 0x41b8e1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41b8e2: e8941d3500 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x41b8e7: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0041b8ea: { // 0x41b8ea: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x41b8ec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41b8ed: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x41b8ee: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0001be60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41be60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41be61: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x41be62: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x41be64: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x41be66: 742e JZ 0x0041be96
    if(integer::condition("JZ",flags)) goto L0041be96;
  }
  { // 0x41be68: a1b855a200 MOV EAX,[0x00a255b8]
    s.ax = m.r32((0x00a255b8u));
  }
  { // 0x41be6d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x41be6f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x41be71: 7e23 JLE 0x0041be96
    if(integer::condition("JLE",flags)) goto L0041be96;
  }
  L0041be73: { // 0x41be73: a1ac55a200 MOV EAX,[0x00a255ac]
    s.ax = m.r32((0x00a255acu));
  }
  { // 0x41be78: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x41be79: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x41be7c: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x41be7f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x41be80: e8db193500 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x41be85: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x41be88: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x41be8a: 7410 JZ 0x0041be9c
    if(integer::condition("JZ",flags)) goto L0041be9c;
  }
  { // 0x41be8c: a1b855a200 MOV EAX,[0x00a255b8]
    s.ax = m.r32((0x00a255b8u));
  }
  { // 0x41be91: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x41be92: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x41be94: 7cdd JL 0x0041be73
    if(integer::condition("JL",flags)) goto L0041be73;
  }
  L0041be96: { // 0x41be96: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x41be97: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x41be9a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41be9b: c3 RET
    finish(m,s,f,0u); return;
  }
  L0041be9c: { // 0x41be9c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x41be9e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x41be9f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41bea0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00020cd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x420cd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x420cd1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x420cd2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x420cd4: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x420cd6: 7440 JZ 0x00420d18
    if(integer::condition("JZ",flags)) goto L00420d18;
  }
  { // 0x420cd8: 685c8e7b00 PUSH 0x7b8e5c
    f.push(m,0x007b8e5cu);
  }
  { // 0x420cdd: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x420cde: e87dcb3400 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x420ce3: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x420ce6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x420ce8: 742e JZ 0x00420d18
    if(integer::condition("JZ",flags)) goto L00420d18;
  }
  { // 0x420cea: a120e58400 MOV EAX,[0x0084e520]
    s.ax = m.r32((0x0084e520u));
  }
  { // 0x420cef: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x420cf1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x420cf3: 7e23 JLE 0x00420d18
    if(integer::condition("JLE",flags)) goto L00420d18;
  }
  L00420cf5: { // 0x420cf5: a114e58400 MOV EAX,[0x0084e514]
    s.ax = m.r32((0x0084e514u));
  }
  { // 0x420cfa: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x420cfb: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x420cfe: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x420d01: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x420d02: e859cb3400 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x420d07: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x420d0a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x420d0c: 7410 JZ 0x00420d1e
    if(integer::condition("JZ",flags)) goto L00420d1e;
  }
  { // 0x420d0e: a120e58400 MOV EAX,[0x0084e520]
    s.ax = m.r32((0x0084e520u));
  }
  { // 0x420d13: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x420d14: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x420d16: 7cdd JL 0x00420cf5
    if(integer::condition("JL",flags)) goto L00420cf5;
  }
  L00420d18: { // 0x420d18: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x420d19: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x420d1c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x420d1d: c3 RET
    finish(m,s,f,0u); return;
  }
  L00420d1e: { // 0x420d1e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x420d20: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x420d21: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x420d22: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00025640(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x425640: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x425641: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x425642: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x425644: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x425646: 742e JZ 0x00425676
    if(integer::condition("JZ",flags)) goto L00425676;
  }
  { // 0x425648: a120e58400 MOV EAX,[0x0084e520]
    s.ax = m.r32((0x0084e520u));
  }
  { // 0x42564d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x42564f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x425651: 7e23 JLE 0x00425676
    if(integer::condition("JLE",flags)) goto L00425676;
  }
  L00425653: { // 0x425653: a114e58400 MOV EAX,[0x0084e514]
    s.ax = m.r32((0x0084e514u));
  }
  { // 0x425658: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x425659: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x42565c: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x42565f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x425660: e8fb813400 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x425665: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x425668: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x42566a: 7410 JZ 0x0042567c
    if(integer::condition("JZ",flags)) goto L0042567c;
  }
  { // 0x42566c: a120e58400 MOV EAX,[0x0084e520]
    s.ax = m.r32((0x0084e520u));
  }
  { // 0x425671: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x425672: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x425674: 7cdd JL 0x00425653
    if(integer::condition("JL",flags)) goto L00425653;
  }
  L00425676: { // 0x425676: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x425677: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x42567a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42567b: c3 RET
    finish(m,s,f,0u); return;
  }
  L0042567c: { // 0x42567c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x42567e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x42567f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x425680: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00026890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x426890: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x426891: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x426892: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x426894: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x426895: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x426896: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x426898: 685c8e7b00 PUSH 0x7b8e5c
    f.push(m,0x007b8e5cu);
  }
  { // 0x42689d: e8be6f3400 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4268a2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4268a5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4268a7: 7461 JZ 0x0042690a
    if(integer::condition("JZ",flags)) goto L0042690a;
  }
  { // 0x4268a9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4268aa: 687c907b00 PUSH 0x7b907c
    f.push(m,0x007b907cu);
  }
  { // 0x4268af: e8ac6f3400 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4268b4: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4268b7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4268b9: 744f JZ 0x0042690a
    if(integer::condition("JZ",flags)) goto L0042690a;
  }
  { // 0x4268bb: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x4268be: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x4268c0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4268c2: 7e1f JLE 0x004268e3
    if(integer::condition("JLE",flags)) goto L004268e3;
  }
  L004268c4: { // 0x4268c4: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x4268c7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4268c8: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x4268cb: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x4268ce: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4268cf: e88c6f3400 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4268d4: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4268d7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4268d9: 7425 JZ 0x00426900
    if(integer::condition("JZ",flags)) goto L00426900;
  }
  { // 0x4268db: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x4268de: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x4268df: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x4268e1: 7ce1 JL 0x004268c4
    if(integer::condition("JL",flags)) goto L004268c4;
  }
  L004268e3: { // 0x4268e3: 6830030000 PUSH 0x330
    f.push(m,0x00000330u);
  }
  { // 0x4268e8: e86a703400 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4268ed: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4268f0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4268f2: 7416 JZ 0x0042690a
    if(integer::condition("JZ",flags)) goto L0042690a;
  }
  { // 0x4268f4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4268f5: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x4268f7: e834e5ffff CALL 0x00424e30
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x4268fc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4268fd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4268fe: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4268ff: c3 RET
    finish(m,s,f,0u); return;
  }
  L00426900: { // 0x426900: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x426903: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x426904: 8b04b2 MOV EAX,dword ptr [EDX + ESI*0x4]
    s.ax = m.r32((s.dx+(s.si * 0x00000004u)));
  }
  { // 0x426907: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x426908: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x426909: c3 RET
    finish(m,s,f,0u); return;
  }
  L0042690a: { // 0x42690a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x42690b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42690c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x42690e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x42690f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0002c9f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x42c9f0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x42c9f1: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x42c9f5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x42c9f6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x42c9f7: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x42c9f9: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x42c9fb: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x42c9fe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x42c9ff: e80c730600 CALL 0x00493d10
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x42ca04: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x42ca07: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  { // 0x42ca09: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x42ca0b: 7e3d JLE 0x0042ca4a
    if(integer::condition("JLE",flags)) goto L0042ca4a;
  }
  { // 0x42ca0d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x42ca0e: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0042ca10: { // 0x42ca10: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x42ca13: 8b1439 MOV EDX,dword ptr [ECX + EDI*0x1]
    s.dx = m.r32((s.cx+(s.di * 0x00000001u)));
  }
  { // 0x42ca16: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x42ca18: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x42ca19: e8f2720600 CALL 0x00493d10
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x42ca1e: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x42ca21: 668b4c3804 MOV CX,word ptr [EAX + EDI*0x1 + 0x4]
    s.cx = with_ax(s.cx, m.r16((s.ax+(s.di * 0x00000001u)+0x00000004u)));
  }
  { // 0x42ca26: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x42ca27: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x42ca29: e8c2720600 CALL 0x00493cf0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x42ca2e: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  { // 0x42ca31: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x42ca33: 668b443a06 MOV AX,word ptr [EDX + EDI*0x1 + 0x6]
    s.ax = with_ax(s.ax, m.r16((s.dx+(s.di * 0x00000001u)+0x00000006u)));
  }
  { // 0x42ca38: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x42ca39: e8b2720600 CALL 0x00493cf0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x42ca3e: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x42ca41: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  { // 0x42ca42: 83c710 ADD EDI,0x10
    s.di = integer::add(s.di,0x00000010u,32,flags);
  }
  { // 0x42ca45: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x42ca47: 7cc7 JL 0x0042ca10
    if(integer::condition("JL",flags)) goto L0042ca10;
  }
  { // 0x42ca49: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042ca4a: { // 0x42ca4a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x42ca4b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x42ca4c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x42ca4d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00037a40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x437a40: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x437a41: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x437a42: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x437a43: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x437a44: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x437a46: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x437a48: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x437a4a: c707747b7800 MOV dword ptr [EDI],0x787b74
    m.w32((s.di), 0x00787b74u);
  }
  { // 0x437a50: 8b6f14 MOV EBP,dword ptr [EDI + 0x14]
    s.bp = m.r32((s.di+0x00000014u));
  }
  { // 0x437a53: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  { // 0x437a55: 7e1d JLE 0x00437a74
    if(integer::condition("JLE",flags)) goto L00437a74;
  }
  L00437a57: { // 0x437a57: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x437a5a: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x437a5d: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  { // 0x437a5f: 7407 JZ 0x00437a68
    if(integer::condition("JZ",flags)) goto L00437a68;
  }
  { // 0x437a61: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x437a63: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x437a65: ff5220 CALL dword ptr [EDX + 0x20]
    const std::uint32_t call_target=m.r32((s.dx+0x00000020u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00437a68: { // 0x437a68: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x437a6b: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x437a6c: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x437a6e: 895cb0fc MOV dword ptr [EAX + ESI*0x4 + -0x4],EBX
    m.w32((s.ax+(s.si * 0x00000004u)-0x00000004u), s.bx);
  }
  { // 0x437a72: 7ce3 JL 0x00437a57
    if(integer::condition("JL",flags)) goto L00437a57;
  }
  L00437a74: { // 0x437a74: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x437a77: 8d7704 LEA ESI,[EDI + 0x4]
    s.si = (s.di+0x00000004u);
  }
  { // 0x437a7a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x437a7c: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x437a7f: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x437a82: c706547b7800 MOV dword ptr [ESI],0x787b54
    m.w32((s.si), 0x00787b54u);
  }
  { // 0x437a88: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x437a8a: 7411 JZ 0x00437a9d
    if(integer::condition("JZ",flags)) goto L00437a9d;
  }
  { // 0x437a8c: 385e0d CMP byte ptr [ESI + 0xd],BL
    (void)integer::sub(m.r8((s.si+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  { // 0x437a8f: 740c JZ 0x00437a9d
    if(integer::condition("JZ",flags)) goto L00437a9d;
  }
  { // 0x437a91: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x437a92: e8e45b3300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x437a97: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x437a9a: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00437a9d: { // 0x437a9d: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  { // 0x437aa0: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  { // 0x437aa3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x437aa4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x437aa5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x437aa6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x437aa7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00037ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x437ab0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x437ab1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x437ab2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x437ab3: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x437ab5: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x437ab7: 8b5f14 MOV EBX,dword ptr [EDI + 0x14]
    s.bx = m.r32((s.di+0x00000014u));
  }
  { // 0x437aba: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x437abc: 7e21 JLE 0x00437adf
    if(integer::condition("JLE",flags)) goto L00437adf;
  }
  L00437abe: { // 0x437abe: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x437ac1: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x437ac4: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x437ac6: 7407 JZ 0x00437acf
    if(integer::condition("JZ",flags)) goto L00437acf;
  }
  { // 0x437ac8: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x437aca: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x437acc: ff5220 CALL dword ptr [EDX + 0x20]
    const std::uint32_t call_target=m.r32((s.dx+0x00000020u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00437acf: { // 0x437acf: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x437ad2: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x437ad3: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x437ad5: c744b0fc00000000 MOV dword ptr [EAX + ESI*0x4 + -0x4],0x0
    m.w32((s.ax+(s.si * 0x00000004u)-0x00000004u), 0x00000000u);
  }
  { // 0x437add: 7cdf JL 0x00437abe
    if(integer::condition("JL",flags)) goto L00437abe;
  }
  L00437adf: { // 0x437adf: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x437ae2: 8d4f04 LEA ECX,[EDI + 0x4]
    s.cx = (s.di+0x00000004u);
  }
  { // 0x437ae5: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x437ae8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x437ae9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x437aea: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x437aeb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00037af0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x437af0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x437af1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x437af2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x437af3: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x437af5: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x437af7: 8b5f14 MOV EBX,dword ptr [EDI + 0x14]
    s.bx = m.r32((s.di+0x00000014u));
  }
  { // 0x437afa: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x437afc: 7e21 JLE 0x00437b1f
    if(integer::condition("JLE",flags)) goto L00437b1f;
  }
  L00437afe: { // 0x437afe: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x437b01: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x437b04: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x437b06: 7407 JZ 0x00437b0f
    if(integer::condition("JZ",flags)) goto L00437b0f;
  }
  { // 0x437b08: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x437b0a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x437b0c: ff5220 CALL dword ptr [EDX + 0x20]
    const std::uint32_t call_target=m.r32((s.dx+0x00000020u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00437b0f: { // 0x437b0f: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x437b12: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x437b13: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x437b15: c744b0fc00000000 MOV dword ptr [EAX + ESI*0x4 + -0x4],0x0
    m.w32((s.ax+(s.si * 0x00000004u)-0x00000004u), 0x00000000u);
  }
  { // 0x437b1d: 7cdf JL 0x00437afe
    if(integer::condition("JL",flags)) goto L00437afe;
  }
  L00437b1f: { // 0x437b1f: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x437b22: 8d4f04 LEA ECX,[EDI + 0x4]
    s.cx = (s.di+0x00000004u);
  }
  { // 0x437b25: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x437b28: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x437b2c: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x437b30: 89471c MOV dword ptr [EDI + 0x1c],EAX
    m.w32((s.di+0x0000001cu), s.ax);
  }
  { // 0x437b33: 894f20 MOV dword ptr [EDI + 0x20],ECX
    m.w32((s.di+0x00000020u), s.cx);
  }
  { // 0x437b36: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x437b37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x437b38: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x437b39: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00037bb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x437bb0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x437bb1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x437bb2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x437bb3: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  { // 0x437bb7: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x437bb9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x437bba: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x437bbc: 750c JNZ 0x00437bca
    if(integer::condition("JNZ",flags)) goto L00437bca;
  }
  { // 0x437bbe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x437bbf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x437bc0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x437bc1: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  { // 0x437bc6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x437bc7: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L00437bca: { // 0x437bca: 8b4314 MOV EAX,dword ptr [EBX + 0x14]
    s.ax = m.r32((s.bx+0x00000014u));
  }
  { // 0x437bcd: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x437bcf: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x437bd1: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  { // 0x437bd5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x437bd7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x437bd8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x437bd9: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  { // 0x437bdd: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x437be0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x437be2: 7c2b JL 0x00437c0f
    if(integer::condition("JL",flags)) goto L00437c0f;
  }
  { // 0x437be4: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x437be8: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x437bea: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x437bec: 7e1f JLE 0x00437c0d
    if(integer::condition("JLE",flags)) goto L00437c0d;
  }
  { // 0x437bee: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L00437bf2: { // 0x437bf2: 8b4308 MOV EAX,dword ptr [EBX + 0x8]
    s.ax = m.r32((s.bx+0x00000008u));
  }
  { // 0x437bf5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x437bf6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x437bf7: 8b04b8 MOV EAX,dword ptr [EAX + EDI*0x4]
    s.ax = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x437bfa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x437bfb: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x437bfd: ff5118 CALL dword ptr [ECX + 0x18]
    const std::uint32_t call_target=m.r32((s.cx+0x00000018u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x437c00: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x437c02: 7c0b JL 0x00437c0f
    if(integer::condition("JL",flags)) goto L00437c0f;
  }
  { // 0x437c04: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x437c08: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x437c09: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x437c0b: 7ce5 JL 0x00437bf2
    if(integer::condition("JL",flags)) goto L00437bf2;
  }
  L00437c0d: { // 0x437c0d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00437c0f: { // 0x437c0f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x437c10: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x437c11: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x437c12: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x437c13: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0004af00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x44af00: a1887b7800 MOV EAX,[0x00787b88]
    s.ax = m.r32((0x00787b88u));
  }
  { // 0x44af05: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x44af06: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x44af07: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x44af09: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x44af0b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x44af0c: e8dffe0b00 CALL 0x0050adf0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x44af11: a14887a200 MOV EAX,[0x00a28748]
    s.ax = m.r32((0x00a28748u));
  }
  { // 0x44af16: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x44af18: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x44af1a: 7e30 JLE 0x0044af4c
    if(integer::condition("JLE",flags)) goto L0044af4c;
  }
  L0044af1c: { // 0x44af1c: 8b0d3c87a200 MOV ECX,dword ptr [0x00a2873c]
    s.cx = m.r32((0x00a2873cu));
  }
  { // 0x44af22: 8b0cb1 MOV ECX,dword ptr [ECX + ESI*0x4]
    s.cx = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  { // 0x44af25: 8a4176 MOV AL,byte ptr [ECX + 0x76]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000076u)));
  }
  { // 0x44af28: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44af2a: 7516 JNZ 0x0044af42
    if(integer::condition("JNZ",flags)) goto L0044af42;
  }
  { // 0x44af2c: 8b9118040000 MOV EDX,dword ptr [ECX + 0x418]
    s.dx = m.r32((s.cx+0x00000418u));
  }
  { // 0x44af32: 8a8259130000 MOV AL,byte ptr [EDX + 0x1359]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00001359u)));
  }
  { // 0x44af38: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44af3a: 7506 JNZ 0x0044af42
    if(integer::condition("JNZ",flags)) goto L0044af42;
  }
  { // 0x44af3c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x44af3d: e80e000000 CALL 0x0044af50
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0044af42: { // 0x44af42: a14887a200 MOV EAX,[0x00a28748]
    s.ax = m.r32((0x00a28748u));
  }
  { // 0x44af47: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x44af48: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x44af4a: 7cd0 JL 0x0044af1c
    if(integer::condition("JL",flags)) goto L0044af1c;
  }
  L0044af4c: { // 0x44af4c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x44af4d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44af4e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0004ccc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x44ccc0: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x44ccc4: 83fafe CMP EDX,-0x2
    (void)integer::sub(s.dx,0xfffffffeu,32,flags);
  }
  { // 0x44ccc7: 752b JNZ 0x0044ccf4
    if(integer::condition("JNZ",flags)) goto L0044ccf4;
  }
  { // 0x44ccc9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x44ccca: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x44cccb: 8db154040000 LEA ESI,[ECX + 0x454]
    s.si = (s.cx+0x00000454u);
  }
  { // 0x44ccd1: bf12000000 MOV EDI,0x12
    s.di = 0x00000012u;
  }
  L0044ccd6: { // 0x44ccd6: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x44ccd8: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x44ccda: 740d JZ 0x0044cce9
    if(integer::condition("JZ",flags)) goto L0044cce9;
  }
  { // 0x44ccdc: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x44cce2: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x44cce4: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x44cce6: ff5020 CALL dword ptr [EAX + 0x20]
    const std::uint32_t call_target=m.r32((s.ax+0x00000020u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0044cce9: { // 0x44cce9: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x44ccec: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x44cced: 75e7 JNZ 0x0044ccd6
    if(integer::condition("JNZ",flags)) goto L0044ccd6;
  }
  { // 0x44ccef: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x44ccf0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44ccf1: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0044ccf4: { // 0x44ccf4: 8b849154040000 MOV EAX,dword ptr [ECX + EDX*0x4 + 0x454]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)+0x00000454u));
  }
  { // 0x44ccfb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x44ccfd: 7414 JZ 0x0044cd13
    if(integer::condition("JZ",flags)) goto L0044cd13;
  }
  { // 0x44ccff: c784915404000000000000 MOV dword ptr [ECX + EDX*0x4 + 0x454],0x0
    m.w32((s.cx+(s.dx * 0x00000004u)+0x00000454u), 0x00000000u);
  }
  { // 0x44cd0a: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x44cd0c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x44cd0e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x44cd10: ff5220 CALL dword ptr [EDX + 0x20]
    const std::uint32_t call_target=m.r32((s.dx+0x00000020u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0044cd13: { // 0x44cd13: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0004cd60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x44cd60: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x44cd61: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x44cd63: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x44cd67: 388fb6050000 CMP byte ptr [EDI + 0x5b6],CL
    (void)integer::sub(m.r8((s.di+0x000005b6u)),(s.cx & 0xffu),8,flags);
  }
  { // 0x44cd6d: 7465 JZ 0x0044cdd4
    if(integer::condition("JZ",flags)) goto L0044cdd4;
  }
  { // 0x44cd6f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x44cd70: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x44cd71: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x44cd72: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  { // 0x44cd74: 888fb6050000 MOV byte ptr [EDI + 0x5b6],CL
    m.w8((s.di+0x000005b6u), (s.cx & 0xffu));
  }
  { // 0x44cd7a: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x44cd7c: 8d9f54040000 LEA EBX,[EDI + 0x454]
    s.bx = (s.di+0x00000454u);
  }
  L0044cd82: { // 0x44cd82: 833b00 CMP dword ptr [EBX],0x0
    (void)integer::sub(m.r32((s.bx)),0x00000000u,32,flags);
  }
  { // 0x44cd85: 743b JZ 0x0044cdc2
    if(integer::condition("JZ",flags)) goto L0044cdc2;
  }
  { // 0x44cd87: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x44cd89: 740f JZ 0x0044cd9a
    if(integer::condition("JZ",flags)) goto L0044cd9a;
  }
  { // 0x44cd8b: 8b8718040000 MOV EAX,dword ptr [EDI + 0x418]
    s.ax = m.r32((s.di+0x00000418u));
  }
  { // 0x44cd91: 8d8430e40c0000 LEA EAX,[EAX + ESI*0x1 + 0xce4]
    s.ax = (s.ax+(s.si * 0x00000001u)+0x00000ce4u);
  }
  { // 0x44cd98: eb0d JMP 0x0044cda7
    goto L0044cda7;
  }
  L0044cd9a: { // 0x44cd9a: 8b9718040000 MOV EDX,dword ptr [EDI + 0x418]
    s.dx = m.r32((s.di+0x00000418u));
  }
  { // 0x44cda0: 8d8432d40c0000 LEA EAX,[EDX + ESI*0x1 + 0xcd4]
    s.ax = (s.dx+(s.si * 0x00000001u)+0x00000cd4u);
  }
  L0044cda7: { // 0x44cda7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x44cda9: 7417 JZ 0x0044cdc2
    if(integer::condition("JZ",flags)) goto L0044cdc2;
  }
  { // 0x44cdab: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  { // 0x44cdae: 7412 JZ 0x0044cdc2
    if(integer::condition("JZ",flags)) goto L0044cdc2;
  }
  { // 0x44cdb0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x44cdb2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x44cdb4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x44cdb5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x44cdb6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x44cdb7: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x44cdb9: e892f9ffff CALL 0x0044c750
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x44cdbe: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0044cdc2: { // 0x44cdc2: 83c644 ADD ESI,0x44
    s.si = integer::add(s.si,0x00000044u,32,flags);
  }
  { // 0x44cdc5: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  { // 0x44cdc6: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  { // 0x44cdc9: 81fec8040000 CMP ESI,0x4c8
    (void)integer::sub(s.si,0x000004c8u,32,flags);
  }
  { // 0x44cdcf: 7cb1 JL 0x0044cd82
    if(integer::condition("JL",flags)) goto L0044cd82;
  }
  { // 0x44cdd1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44cdd2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x44cdd3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044cdd4: { // 0x44cdd4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x44cdd5: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0004d670(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x44d670: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x44d671: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x44d672: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x44d673: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  { // 0x44d677: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x44d678: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x44d67a: 8a87c6050000 MOV AL,byte ptr [EDI + 0x5c6]
    s.ax = with_al(s.ax, m.r8((s.di+0x000005c6u)));
  }
  { // 0x44d680: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44d682: 742c JZ 0x0044d6b0
    if(integer::condition("JZ",flags)) goto L0044d6b0;
  }
  { // 0x44d684: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x44d686: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44d688: 7e26 JLE 0x0044d6b0
    if(integer::condition("JLE",flags)) goto L0044d6b0;
  }
  { // 0x44d68a: 8db7c0040000 LEA ESI,[EDI + 0x4c0]
    s.si = (s.di+0x000004c0u);
  }
  L0044d690: { // 0x44d690: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x44d692: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x44d694: 740b JZ 0x0044d6a1
    if(integer::condition("JZ",flags)) goto L0044d6a1;
  }
  { // 0x44d696: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x44d697: e894742800 CALL 0x006d4b30
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x44d69c: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  { // 0x44d69f: 7517 JNZ 0x0044d6b8
    if(integer::condition("JNZ",flags)) goto L0044d6b8;
  }
  L0044d6a1: { // 0x44d6a1: 0fbe87c6050000 MOVSX EAX,byte ptr [EDI + 0x5c6]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.di+0x000005c6u)),8));
  }
  { // 0x44d6a8: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x44d6a9: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x44d6ac: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x44d6ae: 7ce0 JL 0x0044d690
    if(integer::condition("JL",flags)) goto L0044d690;
  }
  L0044d6b0: { // 0x44d6b0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x44d6b1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x44d6b3: e8f8032800 CALL 0x006cdab0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0044d6b8: { // 0x44d6b8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x44d6b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x44d6ba: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x44d6bb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x44d6bc: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0004dc30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x44dc30: a14887a200 MOV EAX,[0x00a28748]
    s.ax = m.r32((0x00a28748u));
  }
  { // 0x44dc35: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x44dc36: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x44dc38: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x44dc3a: 7e6c JLE 0x0044dca8
    if(integer::condition("JLE",flags)) goto L0044dca8;
  }
  { // 0x44dc3c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044dc3d: { // 0x44dc3d: a13c87a200 MOV EAX,[0x00a2873c]
    s.ax = m.r32((0x00a2873cu));
  }
  { // 0x44dc42: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x44dc45: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x44dc47: 7454 JZ 0x0044dc9d
    if(integer::condition("JZ",flags)) goto L0044dc9d;
  }
  { // 0x44dc49: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  { // 0x44dc4f: 8a8158130000 MOV AL,byte ptr [ECX + 0x1358]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001358u)));
  }
  { // 0x44dc55: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44dc57: 7444 JZ 0x0044dc9d
    if(integer::condition("JZ",flags)) goto L0044dc9d;
  }
  { // 0x44dc59: a1c483a200 MOV EAX,[0x00a283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  { // 0x44dc5e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x44dc60: 753b JNZ 0x0044dc9d
    if(integer::condition("JNZ",flags)) goto L0044dc9d;
  }
  { // 0x44dc62: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  { // 0x44dc65: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44dc67: 7434 JZ 0x0044dc9d
    if(integer::condition("JZ",flags)) goto L0044dc9d;
  }
  { // 0x44dc69: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  { // 0x44dc6c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44dc6e: 752d JNZ 0x0044dc9d
    if(integer::condition("JNZ",flags)) goto L0044dc9d;
  }
  { // 0x44dc70: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x44dc72: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x44dc74: e837000000 CALL 0x0044dcb0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x44dc79: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x44dc7b: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x44dc7d: e82e000000 CALL 0x0044dcb0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x44dc82: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x44dc84: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x44dc86: e825000000 CALL 0x0044dcb0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x44dc8b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x44dc8d: 6a06 PUSH 0x6
    f.push(m,0x00000006u);
  }
  { // 0x44dc8f: e81c000000 CALL 0x0044dcb0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x44dc94: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x44dc96: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x44dc98: e8f3050000 CALL 0x0044e290
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L0044dc9d: { // 0x44dc9d: a14887a200 MOV EAX,[0x00a28748]
    s.ax = m.r32((0x00a28748u));
  }
  { // 0x44dca2: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x44dca3: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x44dca5: 7c96 JL 0x0044dc3d
    if(integer::condition("JL",flags)) goto L0044dc3d;
  }
  { // 0x44dca7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044dca8: { // 0x44dca8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x44dca9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0004f730(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x44f730: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x44f731: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x44f733: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x44f734: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x44f735: 8b6b78 MOV EBP,dword ptr [EBX + 0x78]
    s.bp = m.r32((s.bx+0x00000078u));
  }
  { // 0x44f738: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x44f73a: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  { // 0x44f73c: 7e3b JLE 0x0044f779
    if(integer::condition("JLE",flags)) goto L0044f779;
  }
  { // 0x44f73e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044f73f: { // 0x44f73f: 8b436c MOV EAX,dword ptr [EBX + 0x6c]
    s.ax = m.r32((s.bx+0x0000006cu));
  }
  { // 0x44f742: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x44f745: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  { // 0x44f748: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44f74a: 7427 JZ 0x0044f773
    if(integer::condition("JZ",flags)) goto L0044f773;
  }
  { // 0x44f74c: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  { // 0x44f74f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44f751: 7520 JNZ 0x0044f773
    if(integer::condition("JNZ",flags)) goto L0044f773;
  }
  { // 0x44f753: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  { // 0x44f759: 8a8158130000 MOV AL,byte ptr [ECX + 0x1358]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001358u)));
  }
  { // 0x44f75f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x44f761: 7409 JZ 0x0044f76c
    if(integer::condition("JZ",flags)) goto L0044f76c;
  }
  { // 0x44f763: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x44f765: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x44f767: e824ebffff CALL 0x0044e290
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0044f76c: { // 0x44f76c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x44f76e: e85dfeffff CALL 0x0044f5d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0044f773: { // 0x44f773: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x44f774: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  { // 0x44f776: 7cc7 JL 0x0044f73f
    if(integer::condition("JL",flags)) goto L0044f73f;
  }
  { // 0x44f778: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044f779: { // 0x44f779: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x44f77a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x44f77b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x44f77c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000514e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4514e0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4514e1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4514e2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4514e4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4514e5: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x4514ea: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  { // 0x4514f0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4514f1: e85a8a1d00 CALL 0x00629f50
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4514f6: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x4514f8: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x4514fa: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x4514fd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4514ff: 7e31 JLE 0x00451532
    if(integer::condition("JLE",flags)) goto L00451532;
  }
  L00451501: { // 0x451501: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  { // 0x451504: 8b86a0010000 MOV EAX,dword ptr [ESI + 0x1a0]
    s.ax = m.r32((s.si+0x000001a0u));
  }
  { // 0x45150a: 8b14f9 MOV EDX,dword ptr [ECX + EDI*0x8]
    s.dx = m.r32((s.cx+(s.di * 0x00000008u)));
  }
  { // 0x45150d: 8d0cf9 LEA ECX,[ECX + EDI*0x8]
    s.cx = (s.cx+(s.di * 0x00000008u));
  }
  { // 0x451510: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x451512: 8b96a4010000 MOV EDX,dword ptr [ESI + 0x1a4]
    s.dx = m.r32((s.si+0x000001a4u));
  }
  { // 0x451518: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  { // 0x45151b: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  { // 0x45151d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x45151e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x45151f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x451520: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x451525: e8667a1d00 CALL 0x00628f90
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x45152a: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x45152d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x45152e: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x451530: 7ccf JL 0x00451501
    if(integer::condition("JL",flags)) goto L00451501;
  }
  L00451532: { // 0x451532: c6867b03000001 MOV byte ptr [ESI + 0x37b],0x1
    m.w8((s.si+0x0000037bu), 0x00000001u);
  }
  { // 0x451539: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x45153a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x45153b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x45153c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00057700(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x457700: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x457701: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x457702: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x457703: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x457705: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x457707: bed8ab7b00 MOV ESI,0x7babd8
    s.si = 0x007babd8u;
  }
  L0045770c: { // 0x45770c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x45770e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x45770f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x457710: e84b613100 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x457715: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x457718: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x45771a: 7412 JZ 0x0045772e
    if(integer::condition("JZ",flags)) goto L0045772e;
  }
  { // 0x45771c: 83c608 ADD ESI,0x8
    s.si = integer::add(s.si,0x00000008u,32,flags);
  }
  { // 0x45771f: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x457720: 81fe08ac7b00 CMP ESI,0x7bac08
    (void)integer::sub(s.si,0x007bac08u,32,flags);
  }
  { // 0x457726: 7ce4 JL 0x0045770c
    if(integer::condition("JL",flags)) goto L0045770c;
  }
  { // 0x457728: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x457729: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x45772a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x45772c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x45772d: c3 RET
    finish(m,s,f,0u); return;
  }
  L0045772e: { // 0x45772e: 8b04fddcab7b00 MOV EAX,dword ptr [EDI*0x8 + 0x7babdc]
    s.ax = m.r32(((s.di * 0x00000008u)+0x007babdcu));
  }
  { // 0x457735: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x457736: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x457737: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x457738: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00058000(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x458000: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x458001: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x458002: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x458004: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x458006: 742e JZ 0x00458036
    if(integer::condition("JZ",flags)) goto L00458036;
  }
  { // 0x458008: a118e0a100 MOV EAX,[0x00a1e018]
    s.ax = m.r32((0x00a1e018u));
  }
  { // 0x45800d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x45800f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x458011: 7e23 JLE 0x00458036
    if(integer::condition("JLE",flags)) goto L00458036;
  }
  L00458013: { // 0x458013: a10ce0a100 MOV EAX,[0x00a1e00c]
    s.ax = m.r32((0x00a1e00cu));
  }
  { // 0x458018: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x458019: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x45801c: 83c164 ADD ECX,0x64
    s.cx = integer::add(s.cx,0x00000064u,32,flags);
  }
  { // 0x45801f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x458020: e83b583100 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x458025: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x458028: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x45802a: 7410 JZ 0x0045803c
    if(integer::condition("JZ",flags)) goto L0045803c;
  }
  { // 0x45802c: a118e0a100 MOV EAX,[0x00a1e018]
    s.ax = m.r32((0x00a1e018u));
  }
  { // 0x458031: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x458032: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x458034: 7cdd JL 0x00458013
    if(integer::condition("JL",flags)) goto L00458013;
  }
  L00458036: { // 0x458036: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x458037: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x45803a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x45803b: c3 RET
    finish(m,s,f,0u); return;
  }
  L0045803c: { // 0x45803c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x45803e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x45803f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x458040: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00058050(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x458050: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x458051: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x458052: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x458054: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x458056: 742e JZ 0x00458086
    if(integer::condition("JZ",flags)) goto L00458086;
  }
  { // 0x458058: a118e0a100 MOV EAX,[0x00a1e018]
    s.ax = m.r32((0x00a1e018u));
  }
  { // 0x45805d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x45805f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x458061: 7e23 JLE 0x00458086
    if(integer::condition("JLE",flags)) goto L00458086;
  }
  L00458063: { // 0x458063: a10ce0a100 MOV EAX,[0x00a1e00c]
    s.ax = m.r32((0x00a1e00cu));
  }
  { // 0x458068: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x458069: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x45806c: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x45806f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x458070: e8eb573100 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x458075: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x458078: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x45807a: 7410 JZ 0x0045808c
    if(integer::condition("JZ",flags)) goto L0045808c;
  }
  { // 0x45807c: a118e0a100 MOV EAX,[0x00a1e018]
    s.ax = m.r32((0x00a1e018u));
  }
  { // 0x458081: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x458082: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x458084: 7cdd JL 0x00458063
    if(integer::condition("JL",flags)) goto L00458063;
  }
  L00458086: { // 0x458086: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x458087: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x45808a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x45808b: c3 RET
    finish(m,s,f,0u); return;
  }
  L0045808c: { // 0x45808c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x45808e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x45808f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x458090: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0005e840(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x45e840: a118e0a100 MOV EAX,[0x00a1e018]
    s.ax = m.r32((0x00a1e018u));
  }
  { // 0x45e845: 83ec3c SUB ESP,0x3c
    f.sp = integer::sub(f.sp,0x0000003cu,32,flags);
  }
  { // 0x45e848: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x45e849: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x45e84b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x45e84d: 7e5a JLE 0x0045e8a9
    if(integer::condition("JLE",flags)) goto L0045e8a9;
  }
  { // 0x45e84f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0045e850: { // 0x45e850: a10ce0a100 MOV EAX,[0x00a1e00c]
    s.ax = m.r32((0x00a1e00cu));
  }
  { // 0x45e855: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x45e859: 6a3c PUSH 0x3c
    f.push(m,0x0000003cu);
  }
  { // 0x45e85b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x45e85c: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x45e85f: 8b0d101a8200 MOV ECX,dword ptr [0x00821a10]
    s.cx = m.r32((0x00821a10u));
  }
  { // 0x45e865: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x45e867: 6834c17b00 PUSH 0x7bc134
    f.push(m,0x007bc134u);
  }
  { // 0x45e86c: 8d5624 LEA EDX,[ESI + 0x24]
    s.dx = (s.si+0x00000024u);
  }
  { // 0x45e86f: c644241800 MOV byte ptr [ESP + 0x18],0x0
    m.w8((f.sp+0x00000018u), 0x00000000u);
  }
  { // 0x45e874: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x45e875: e876f50a00 CALL 0x0050ddf0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x45e87a: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x45e87e: e8dd8d0c00 CALL 0x00527660
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x45e883: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x45e885: 7c17 JL 0x0045e89e
    if(integer::condition("JL",flags)) goto L0045e89e;
  }
  { // 0x45e887: 3b052089a200 CMP EAX,dword ptr [0x00a28920]
    (void)integer::sub(s.ax,m.r32((0x00a28920u)),32,flags);
  }
  { // 0x45e88d: 7d0f JGE 0x0045e89e
    if(integer::condition("JGE",flags)) goto L0045e89e;
  }
  { // 0x45e88f: 8b0d1489a200 MOV ECX,dword ptr [0x00a28914]
    s.cx = m.r32((0x00a28914u));
  }
  { // 0x45e895: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x45e898: 8996f00b0000 MOV dword ptr [ESI + 0xbf0],EDX
    m.w32((s.si+0x00000bf0u), s.dx);
  }
  L0045e89e: { // 0x45e89e: a118e0a100 MOV EAX,[0x00a1e018]
    s.ax = m.r32((0x00a1e018u));
  }
  { // 0x45e8a3: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x45e8a4: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x45e8a6: 7ca8 JL 0x0045e850
    if(integer::condition("JL",flags)) goto L0045e850;
  }
  { // 0x45e8a8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0045e8a9: { // 0x45e8a9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x45e8aa: 83c43c ADD ESP,0x3c
    f.sp = integer::add(f.sp,0x0000003cu,32,flags);
  }
  { // 0x45e8ad: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000651b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4651b0: a1a0e0a100 MOV EAX,[0x00a1e0a0]
    s.ax = m.r32((0x00a1e0a0u));
  }
  { // 0x4651b5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4651b6: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x4651b8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4651b9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4651bb: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x4651bd: 7e23 JLE 0x004651e2
    if(integer::condition("JLE",flags)) goto L004651e2;
  }
  L004651bf: { // 0x4651bf: a194e0a100 MOV EAX,[0x00a1e094]
    s.ax = m.r32((0x00a1e094u));
  }
  { // 0x4651c4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4651c5: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x4651c8: 83c024 ADD EAX,0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  { // 0x4651cb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4651cc: e88f863000 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4651d1: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4651d4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4651d6: 7410 JZ 0x004651e8
    if(integer::condition("JZ",flags)) goto L004651e8;
  }
  { // 0x4651d8: a1a0e0a100 MOV EAX,[0x00a1e0a0]
    s.ax = m.r32((0x00a1e0a0u));
  }
  { // 0x4651dd: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x4651de: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x4651e0: 7cdd JL 0x004651bf
    if(integer::condition("JL",flags)) goto L004651bf;
  }
  L004651e2: { // 0x4651e2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4651e3: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x4651e6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4651e7: c3 RET
    finish(m,s,f,0u); return;
  }
  L004651e8: { // 0x4651e8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4651ea: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4651eb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4651ec: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00068b00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x468b00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x468b01: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x468b03: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x468b04: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x468b05: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x468b07: 7434 JZ 0x00468b3d
    if(integer::condition("JZ",flags)) goto L00468b3d;
  }
  { // 0x468b09: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x468b0b: be78c77b00 MOV ESI,0x7bc778
    s.si = 0x007bc778u;
  }
  L00468b10: { // 0x468b10: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x468b13: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x468b14: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x468b15: e8464d3000 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x468b1a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x468b1d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x468b1f: 7423 JZ 0x00468b44
    if(integer::condition("JZ",flags)) goto L00468b44;
  }
  { // 0x468b21: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x468b23: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x468b24: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x468b25: e8364d3000 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x468b2a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x468b2d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x468b2f: 7413 JZ 0x00468b44
    if(integer::condition("JZ",flags)) goto L00468b44;
  }
  { // 0x468b31: 83c608 ADD ESI,0x8
    s.si = integer::add(s.si,0x00000008u,32,flags);
  }
  { // 0x468b34: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x468b35: 81fed0c77b00 CMP ESI,0x7bc7d0
    (void)integer::sub(s.si,0x007bc7d0u,32,flags);
  }
  { // 0x468b3b: 7cd3 JL 0x00468b10
    if(integer::condition("JL",flags)) goto L00468b10;
  }
  L00468b3d: { // 0x468b3d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x468b3e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x468b3f: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x468b42: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x468b43: c3 RET
    finish(m,s,f,0u); return;
  }
  L00468b44: { // 0x468b44: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x468b46: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x468b47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x468b48: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x468b49: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00069980(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x469980: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x469984: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x469987: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x46998b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46998c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x46998d: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x46998f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469990: 8b04d508c97b00 MOV EAX,dword ptr [EDX*0x8 + 0x7bc908]
    s.ax = m.r32(((s.dx * 0x00000008u)+0x007bc908u));
  }
  { // 0x469997: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  { // 0x46999b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46999c: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  { // 0x4699a0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4699a1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4699a2: e849440a00 CALL 0x0050ddf0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4699a7: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x4699a9: be08c97b00 MOV ESI,0x7bc908
    s.si = 0x007bc908u;
  }
  L004699ae: { // 0x4699ae: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x4699b0: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x4699b4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4699b5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4699b6: e8a53e3000 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4699bb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4699be: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4699c0: 7419 JZ 0x004699db
    if(integer::condition("JZ",flags)) goto L004699db;
  }
  { // 0x4699c2: 83c608 ADD ESI,0x8
    s.si = integer::add(s.si,0x00000008u,32,flags);
  }
  { // 0x4699c5: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x4699c6: 81fe30c97b00 CMP ESI,0x7bc930
    (void)integer::sub(s.si,0x007bc930u,32,flags);
  }
  { // 0x4699cc: 7ce0 JL 0x004699ae
    if(integer::condition("JL",flags)) goto L004699ae;
  }
  { // 0x4699ce: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4699cf: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x4699d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4699d5: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x4699d8: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L004699db: { // 0x4699db: 8b04fd0cc97b00 MOV EAX,dword ptr [EDI*0x8 + 0x7bc90c]
    s.ax = m.r32(((s.di * 0x00000008u)+0x007bc90cu));
  }
  { // 0x4699e2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4699e3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4699e4: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x4699e7: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00069a20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x469a20: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x469a24: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x469a27: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x469a2b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x469a2c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x469a2d: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x469a2f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469a30: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  { // 0x469a34: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x469a39: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x469a3a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469a3b: e8b0430a00 CALL 0x0050ddf0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x469a40: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x469a42: 7e40 JLE 0x00469a84
    if(integer::condition("JLE",flags)) goto L00469a84;
  }
  { // 0x469a44: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x469a46: be30c97b00 MOV ESI,0x7bc930
    s.si = 0x007bc930u;
  }
  L00469a4b: { // 0x469a4b: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x469a4d: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x469a51: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x469a52: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x469a53: e8083e3000 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x469a58: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x469a5b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x469a5d: 7416 JZ 0x00469a75
    if(integer::condition("JZ",flags)) goto L00469a75;
  }
  { // 0x469a5f: 83c608 ADD ESI,0x8
    s.si = integer::add(s.si,0x00000008u,32,flags);
  }
  { // 0x469a62: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x469a63: 81fe50c97b00 CMP ESI,0x7bc950
    (void)integer::sub(s.si,0x007bc950u,32,flags);
  }
  { // 0x469a69: 7ce0 JL 0x00469a4b
    if(integer::condition("JL",flags)) goto L00469a4b;
  }
  { // 0x469a6b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x469a6c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x469a6e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x469a6f: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x469a72: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00469a75: { // 0x469a75: 8b04fd34c97b00 MOV EAX,dword ptr [EDI*0x8 + 0x7bc934]
    s.ax = m.r32(((s.di * 0x00000008u)+0x007bc934u));
  }
  { // 0x469a7c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x469a7d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x469a7e: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x469a81: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00469a84: { // 0x469a84: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  { // 0x469a88: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x469a89: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x469a8a: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x469a8d: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00069e80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x469e80: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x469e84: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x469e87: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x469e8b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x469e8c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x469e8d: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x469e8f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469e90: 8b04d550c97b00 MOV EAX,dword ptr [EDX*0x8 + 0x7bc950]
    s.ax = m.r32(((s.dx * 0x00000008u)+0x007bc950u));
  }
  { // 0x469e97: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  { // 0x469e9b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469e9c: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  { // 0x469ea0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x469ea1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469ea2: e8493f0a00 CALL 0x0050ddf0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x469ea7: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x469ea9: be50c97b00 MOV ESI,0x7bc950
    s.si = 0x007bc950u;
  }
  L00469eae: { // 0x469eae: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x469eb0: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x469eb4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x469eb5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x469eb6: e8a5393000 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x469ebb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x469ebe: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x469ec0: 7416 JZ 0x00469ed8
    if(integer::condition("JZ",flags)) goto L00469ed8;
  }
  { // 0x469ec2: 83c608 ADD ESI,0x8
    s.si = integer::add(s.si,0x00000008u,32,flags);
  }
  { // 0x469ec5: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x469ec6: 81fe00ca7b00 CMP ESI,0x7bca00
    (void)integer::sub(s.si,0x007bca00u,32,flags);
  }
  { // 0x469ecc: 7ce0 JL 0x00469eae
    if(integer::condition("JL",flags)) goto L00469eae;
  }
  { // 0x469ece: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x469ecf: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x469ed1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x469ed2: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x469ed5: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00469ed8: { // 0x469ed8: 8b04fd54c97b00 MOV EAX,dword ptr [EDI*0x8 + 0x7bc954]
    s.ax = m.r32(((s.di * 0x00000008u)+0x007bc954u));
  }
  { // 0x469edf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x469ee0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x469ee1: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x469ee4: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00069f20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x469f20: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x469f24: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x469f27: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x469f2b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x469f2c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x469f2d: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x469f2f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469f30: 8b049500ca7b00 MOV EAX,dword ptr [EDX*0x4 + 0x7bca00]
    s.ax = m.r32(((s.dx * 0x00000004u)+0x007bca00u));
  }
  { // 0x469f37: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  { // 0x469f3b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469f3c: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  { // 0x469f40: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x469f41: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469f42: e8a93e0a00 CALL 0x0050ddf0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x469f47: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x469f49: be00ca7b00 MOV ESI,0x7bca00
    s.si = 0x007bca00u;
  }
  L00469f4e: { // 0x469f4e: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x469f50: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x469f54: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x469f55: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x469f56: e805393000 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x469f5b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x469f5e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x469f60: 7417 JZ 0x00469f79
    if(integer::condition("JZ",flags)) goto L00469f79;
  }
  { // 0x469f62: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x469f65: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x469f66: 81fe30ca7b00 CMP ESI,0x7bca30
    (void)integer::sub(s.si,0x007bca30u,32,flags);
  }
  { // 0x469f6c: 7ce0 JL 0x00469f4e
    if(integer::condition("JL",flags)) goto L00469f4e;
  }
  { // 0x469f6e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x469f6f: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x469f72: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x469f73: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x469f76: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00469f79: { // 0x469f79: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x469f7b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x469f7c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x469f7d: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x469f80: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00069fc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x469fc0: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x469fc4: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x469fc7: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x469fcb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x469fcc: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x469fcd: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x469fcf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469fd0: 8b049588887800 MOV EAX,dword ptr [EDX*0x4 + 0x788888]
    s.ax = m.r32(((s.dx * 0x00000004u)+0x00788888u));
  }
  { // 0x469fd7: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  { // 0x469fdb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469fdc: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  { // 0x469fe0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x469fe1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469fe2: e8093e0a00 CALL 0x0050ddf0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x469fe7: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x469fe9: be88887800 MOV ESI,0x788888
    s.si = 0x00788888u;
  }
  L00469fee: { // 0x469fee: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x469ff0: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x469ff4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x469ff5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x469ff6: e865383000 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x469ffb: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x469ffe: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46a000: 7416 JZ 0x0046a018
    if(integer::condition("JZ",flags)) goto L0046a018;
  }
  { // 0x46a002: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x46a005: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x46a006: 81fe90897800 CMP ESI,0x788990
    (void)integer::sub(s.si,0x00788990u,32,flags);
  }
  { // 0x46a00c: 7ce0 JL 0x00469fee
    if(integer::condition("JL",flags)) goto L00469fee;
  }
  { // 0x46a00e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46a00f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x46a011: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46a012: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x46a015: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L0046a018: { // 0x46a018: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x46a01a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46a01b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46a01c: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x46a01f: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a1b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a1b0: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a1b4: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a1ba: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x46a1be: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46a1bf: 8bb42490000000 MOV ESI,dword ptr [ESP + 0x90]
    s.si = m.r32((f.sp+0x00000090u));
  }
  { // 0x46a1c6: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x46a1cb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a1cc: 8b842490000000 MOV EAX,dword ptr [ESP + 0x90]
    s.ax = m.r32((f.sp+0x00000090u));
  }
  { // 0x46a1d3: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x46a1d8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a1d9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a1da: e8113c0a00 CALL 0x0050ddf0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x46a1df: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46a1e1: 7434 JZ 0x0046a217
    if(integer::condition("JZ",flags)) goto L0046a217;
  }
  { // 0x46a1e3: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x46a1e7: 6850997b00 PUSH 0x7b9950
    f.push(m,0x007b9950u);
  }
  { // 0x46a1ec: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46a1ed: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x46a1ef: e80e463000 CALL 0x0076e802
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x46a1f4: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x46a1f7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46a1f9: 741c JZ 0x0046a217
    if(integer::condition("JZ",flags)) goto L0046a217;
  }
  L0046a1fb: { // 0x46a1fb: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x46a1fd: e87e890100 CALL 0x00482b80
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x46a202: 6850997b00 PUSH 0x7b9950
    f.push(m,0x007b9950u);
  }
  { // 0x46a207: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x46a209: 0bf0 OR ESI,EAX
    s.si = integer::logical((s.si)|(s.ax),32,flags);
  }
  { // 0x46a20b: e8f2453000 CALL 0x0076e802
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x46a210: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x46a213: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46a215: 75e4 JNZ 0x0046a1fb
    if(integer::condition("JNZ",flags)) goto L0046a1fb;
  }
  L0046a217: { // 0x46a217: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x46a219: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46a21a: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a220: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006a340(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46a340: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x46a344: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a34a: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x46a34e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46a34f: 8bb42490000000 MOV ESI,dword ptr [ESP + 0x90]
    s.si = m.r32((f.sp+0x00000090u));
  }
  { // 0x46a356: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x46a35b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a35c: 8b842490000000 MOV EAX,dword ptr [ESP + 0x90]
    s.ax = m.r32((f.sp+0x00000090u));
  }
  { // 0x46a363: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x46a368: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x46a369: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46a36a: e8813a0a00 CALL 0x0050ddf0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x46a36f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46a371: 743d JZ 0x0046a3b0
    if(integer::condition("JZ",flags)) goto L0046a3b0;
  }
  { // 0x46a373: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x46a377: 6850997b00 PUSH 0x7b9950
    f.push(m,0x007b9950u);
  }
  { // 0x46a37c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x46a37d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x46a37f: e87e443000 CALL 0x0076e802
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x46a384: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x46a387: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46a389: 7425 JZ 0x0046a3b0
    if(integer::condition("JZ",flags)) goto L0046a3b0;
  }
  L0046a38b: { // 0x46a38b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x46a38d: e8aeac0800 CALL 0x004f5040
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x46a392: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x46a397: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x46a399: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x46a39b: 6850997b00 PUSH 0x7b9950
    f.push(m,0x007b9950u);
  }
  { // 0x46a3a0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x46a3a2: 0bf2 OR ESI,EDX
    s.si = integer::logical((s.si)|(s.dx),32,flags);
  }
  { // 0x46a3a4: e859443000 CALL 0x0076e802
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x46a3a9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x46a3ac: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46a3ae: 75db JNZ 0x0046a38b
    if(integer::condition("JNZ",flags)) goto L0046a38b;
  }
  L0046a3b0: { // 0x46a3b0: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x46a3b2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46a3b3: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x46a3b9: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0006fd00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x46fd00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46fd01: 8b35e08b8300 MOV ESI,dword ptr [0x00838be0]
    s.si = m.r32((0x00838be0u));
  }
  { // 0x46fd07: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x46fd09: 742b JZ 0x0046fd36
    if(integer::condition("JZ",flags)) goto L0046fd36;
  }
  { // 0x46fd0b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0046fd0c: { // 0x46fd0c: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x46fd0f: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x46fd11: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x46fd13: 7409 JZ 0x0046fd1e
    if(integer::condition("JZ",flags)) goto L0046fd1e;
  }
  { // 0x46fd15: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x46fd16: e80de22f00 CALL 0x0076df28
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x46fd1b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0046fd1e: { // 0x46fd1e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46fd1f: e857d92f00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x46fd24: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x46fd27: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x46fd29: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x46fd2b: 75df JNZ 0x0046fd0c
    if(integer::condition("JNZ",flags)) goto L0046fd0c;
  }
  { // 0x46fd2d: 893de08b8300 MOV dword ptr [0x00838be0],EDI
    m.w32((0x00838be0u), s.di);
  }
  { // 0x46fd33: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x46fd34: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46fd35: c3 RET
    finish(m,s,f,0u); return;
  }
  L0046fd36: { // 0x46fd36: c705e08b830000000000 MOV dword ptr [0x00838be0],0x0
    m.w32((0x00838be0u), 0x00000000u);
  }
  { // 0x46fd40: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46fd41: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00071430(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x471430: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  { // 0x471435: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x471436: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x471437: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x471439: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x47143b: 741d JZ 0x0047145a
    if(integer::condition("JZ",flags)) goto L0047145a;
  }
  { // 0x47143d: 8bb7e4000000 MOV ESI,dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  { // 0x471443: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x471445: 7413 JZ 0x0047145a
    if(integer::condition("JZ",flags)) goto L0047145a;
  }
  L00471447: { // 0x471447: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x471449: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47144b: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x47144e: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x471451: 744b JZ 0x0047149e
    if(integer::condition("JZ",flags)) goto L0047149e;
  }
  { // 0x471453: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  { // 0x471456: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x471458: 75ed JNZ 0x00471447
    if(integer::condition("JNZ",flags)) goto L00471447;
  }
  L0047145a: { // 0x47145a: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x47145e: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x471462: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x471464: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x471465: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x471466: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x471468: e8f3fdffff CALL 0x00471260
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x47146d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x47146f: 7528 JNZ 0x00471499
    if(integer::condition("JNZ",flags)) goto L00471499;
  }
  { // 0x471471: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  { // 0x471476: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x471478: 741d JZ 0x00471497
    if(integer::condition("JZ",flags)) goto L00471497;
  }
  { // 0x47147a: 8bb7e4000000 MOV ESI,dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  { // 0x471480: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x471482: 7413 JZ 0x00471497
    if(integer::condition("JZ",flags)) goto L00471497;
  }
  L00471484: { // 0x471484: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x471486: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x471488: ff502c CALL dword ptr [EAX + 0x2c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000002cu));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x47148b: 83f824 CMP EAX,0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  { // 0x47148e: 7412 JZ 0x004714a2
    if(integer::condition("JZ",flags)) goto L004714a2;
  }
  { // 0x471490: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  { // 0x471493: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x471495: 75ed JNZ 0x00471484
    if(integer::condition("JNZ",flags)) goto L00471484;
  }
  L00471497: { // 0x471497: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00471499: { // 0x471499: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47149a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47149b: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0047149e: { // 0x47149e: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4714a0: 74b8 JZ 0x0047145a
    if(integer::condition("JZ",flags)) goto L0047145a;
  }
  L004714a2: { // 0x4714a2: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4714a4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4714a5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4714a6: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00076720(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x476720: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x476721: 8b4124 MOV EAX,dword ptr [ECX + 0x24]
    s.ax = m.r32((s.cx+0x00000024u));
  }
  { // 0x476724: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x476725: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x476729: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47672a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x47672b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x476730: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  { // 0x476734: e8c7500d00 CALL 0x0054b800
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x476739: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x47673b: a1d8a5a100 MOV EAX,[0x00a1a5d8]
    s.ax = m.r32((0x00a1a5d8u));
  }
  { // 0x476740: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x476742: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x476744: 7e4e JLE 0x00476794
    if(integer::condition("JLE",flags)) goto L00476794;
  }
  { // 0x476746: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x476747: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  { // 0x47674b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047674c: { // 0x47674c: 8b15cca5a100 MOV EDX,dword ptr [0x00a1a5cc]
    s.dx = m.r32((0x00a1a5ccu));
  }
  { // 0x476752: 8b34ba MOV ESI,dword ptr [EDX + EDI*0x4]
    s.si = m.r32((s.dx+(s.di * 0x00000004u)));
  }
  { // 0x476755: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x476757: 742f JZ 0x00476788
    if(integer::condition("JZ",flags)) goto L00476788;
  }
  { // 0x476759: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x47675d: 8b4e30 MOV ECX,dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  { // 0x476760: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x476762: 7424 JZ 0x00476788
    if(integer::condition("JZ",flags)) goto L00476788;
  }
  { // 0x476764: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x476766: e885e00700 CALL 0x004f47f0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x47676b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x47676d: 7410 JZ 0x0047677f
    if(integer::condition("JZ",flags)) goto L0047677f;
  }
  { // 0x47676f: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x476773: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x476774: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x476776: e825e40600 CALL 0x004e4ba0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x47677b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x47677d: 7509 JNZ 0x00476788
    if(integer::condition("JNZ",flags)) goto L00476788;
  }
  L0047677f: { // 0x47677f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x476780: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x476781: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x476783: e8d8ec0600 CALL 0x004e5460
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00476788: { // 0x476788: a1d8a5a100 MOV EAX,[0x00a1a5d8]
    s.ax = m.r32((0x00a1a5d8u));
  }
  { // 0x47678d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x47678e: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x476790: 7cba JL 0x0047674c
    if(integer::condition("JL",flags)) goto L0047674c;
  }
  { // 0x476792: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x476793: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00476794: { // 0x476794: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x476795: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x476796: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x476797: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0007ba00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47ba00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x47ba01: 8b4124 MOV EAX,dword ptr [ECX + 0x24]
    s.ax = m.r32((s.cx+0x00000024u));
  }
  { // 0x47ba04: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47ba05: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  { // 0x47ba09: be01000000 MOV ESI,0x1
    s.si = 0x00000001u;
  }
  L0047ba0e: { // 0x47ba0e: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x47ba12: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x47ba13: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x47ba18: e8e39a0c00 CALL 0x00545500
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x47ba1d: 0fbe881b010000 MOVSX ECX,byte ptr [EAX + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  { // 0x47ba24: 8d56fe LEA EDX,[ESI + -0x2]
    s.dx = (s.si-0x00000002u);
  }
  { // 0x47ba27: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x47ba29: 7c1d JL 0x0047ba48
    if(integer::condition("JL",flags)) goto L0047ba48;
  }
  { // 0x47ba2b: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  { // 0x47ba2d: 7f19 JG 0x0047ba48
    if(integer::condition("JG",flags)) goto L0047ba48;
  }
  { // 0x47ba2f: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  { // 0x47ba35: 81e1ffffbfff AND ECX,0xffbfffff
    s.cx = integer::logical((s.cx)&(0xffbfffffu),32,flags);
  }
  { // 0x47ba3b: 898840010000 MOV dword ptr [EAX + 0x140],ECX
    m.w32((s.ax+0x00000140u), s.cx);
  }
  { // 0x47ba41: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x47ba43: e818000000 CALL 0x0047ba60
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0047ba48: { // 0x47ba48: 66ff442404 INC word ptr [ESP + 0x4]
    m.w16((f.sp+0x00000004u), integer::increment(m.r16((f.sp+0x00000004u)),16,flags));
  }
  { // 0x47ba4d: 66ff442406 INC word ptr [ESP + 0x6]
    m.w16((f.sp+0x00000006u), integer::increment(m.r16((f.sp+0x00000006u)),16,flags));
  }
  { // 0x47ba52: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  { // 0x47ba55: 83fe0f CMP ESI,0xf
    (void)integer::sub(s.si,0x0000000fu,32,flags);
  }
  { // 0x47ba58: 7cb4 JL 0x0047ba0e
    if(integer::condition("JL",flags)) goto L0047ba0e;
  }
  { // 0x47ba5a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47ba5b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x47ba5c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0007cf30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47cf30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47cf31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x47cf33: c7069c8b7800 MOV dword ptr [ESI],0x788b9c
    m.w32((s.si), 0x00788b9cu);
  }
  { // 0x47cf39: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  { // 0x47cf3c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x47cf3e: 7426 JZ 0x0047cf66
    if(integer::condition("JZ",flags)) goto L0047cf66;
  }
  { // 0x47cf40: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047cf41: { // 0x47cf41: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x47cf43: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47cf45: e816b70b00 CALL 0x00538660
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x47cf4a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x47cf4c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47cf4e: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x47cf50: e87bb30b00 CALL 0x005382d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x47cf55: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47cf56: e820072f00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x47cf5b: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  { // 0x47cf5e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x47cf61: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x47cf63: 75dc JNZ 0x0047cf41
    if(integer::condition("JNZ",flags)) goto L0047cf41;
  }
  { // 0x47cf65: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047cf66: { // 0x47cf66: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47cf68: e833b20b00 CALL 0x005381a0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x47cf6d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47cf6e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0007cfe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47cfe0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x47cfe1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x47cfe2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47cfe3: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x47cfe5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47cfe6: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x47cfe8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x47cfea: ff9094000000 CALL dword ptr [EAX + 0x94]
    const std::uint32_t call_target=m.r32((s.ax+0x00000094u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x47cff0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x47cff2: 7e49 JLE 0x0047d03d
    if(integer::condition("JLE",flags)) goto L0047d03d;
  }
  { // 0x47cff4: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L0047cff8: { // 0x47cff8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x47cff9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47cffb: e860b60b00 CALL 0x00538660
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x47d000: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x47d002: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x47d004: 7410 JZ 0x0047d016
    if(integer::condition("JZ",flags)) goto L0047d016;
  }
  { // 0x47d006: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x47d008: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x47d009: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x47d00a: e8394c3000 CALL 0x00781c48
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x47d00f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x47d012: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x47d014: 7416 JZ 0x0047d02c
    if(integer::condition("JZ",flags)) goto L0047d02c;
  }
  L0047d016: { // 0x47d016: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x47d018: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47d01a: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x47d01b: ff9294000000 CALL dword ptr [EDX + 0x94]
    const std::uint32_t call_target=m.r32((s.dx+0x00000094u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x47d021: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x47d023: 7cd3 JL 0x0047cff8
    if(integer::condition("JL",flags)) goto L0047cff8;
  }
  { // 0x47d025: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47d026: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47d027: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x47d028: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x47d029: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0047d02c: { // 0x47d02c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x47d02d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47d02f: e89cb20b00 CALL 0x005382d0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x47d034: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47d035: e841062f00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[5u].target;
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x47d03a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0047d03d: { // 0x47d03d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47d03e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47d03f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x47d040: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x47d041: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0007d050(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47d050: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x47d051: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47d052: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x47d054: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47d055: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x47d057: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x47d059: ff9094000000 CALL dword ptr [EAX + 0x94]
    const std::uint32_t call_target=m.r32((s.ax+0x00000094u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x47d05f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x47d061: 7e40 JLE 0x0047d0a3
    if(integer::condition("JLE",flags)) goto L0047d0a3;
  }
  { // 0x47d063: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L0047d067: { // 0x47d067: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47d068: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47d06a: e8f1b50b00 CALL 0x00538660
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x47d06f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x47d071: 7410 JZ 0x0047d083
    if(integer::condition("JZ",flags)) goto L0047d083;
  }
  { // 0x47d073: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x47d075: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x47d076: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x47d077: e8cc4b3000 CALL 0x00781c48
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x47d07c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x47d07f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x47d081: 7415 JZ 0x0047d098
    if(integer::condition("JZ",flags)) goto L0047d098;
  }
  L0047d083: { // 0x47d083: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x47d085: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47d087: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x47d088: ff9294000000 CALL dword ptr [EDX + 0x94]
    const std::uint32_t call_target=m.r32((s.dx+0x00000094u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x47d08e: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x47d090: 7cd5 JL 0x0047d067
    if(integer::condition("JL",flags)) goto L0047d067;
  }
  { // 0x47d092: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47d093: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47d094: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x47d095: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0047d098: { // 0x47d098: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x47d09a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47d09b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47d09d: ff90b8000000 CALL dword ptr [EAX + 0xb8]
    const std::uint32_t call_target=m.r32((s.ax+0x000000b8u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L0047d0a3: { // 0x47d0a3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47d0a4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47d0a5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x47d0a6: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0007d340(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47d340: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47d341: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x47d343: c7069c8b7800 MOV dword ptr [ESI],0x788b9c
    m.w32((s.si), 0x00788b9cu);
  }
  { // 0x47d349: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  { // 0x47d34c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x47d34e: 7426 JZ 0x0047d376
    if(integer::condition("JZ",flags)) goto L0047d376;
  }
  { // 0x47d350: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047d351: { // 0x47d351: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x47d353: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47d355: e806b30b00 CALL 0x00538660
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x47d35a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x47d35c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47d35e: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x47d360: e86baf0b00 CALL 0x005382d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x47d365: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47d366: e810032f00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x47d36b: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  { // 0x47d36e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x47d371: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x47d373: 75dc JNZ 0x0047d351
    if(integer::condition("JNZ",flags)) goto L0047d351;
  }
  { // 0x47d375: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047d376: { // 0x47d376: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x47d378: e823ae0b00 CALL 0x005381a0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x47d37d: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x47d382: 7409 JZ 0x0047d38d
    if(integer::condition("JZ",flags)) goto L0047d38d;
  }
  { // 0x47d384: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47d385: e8f1022f00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x47d38a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0047d38d: { // 0x47d38d: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x47d38f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47d390: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000817a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4817a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4817a1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4817a2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x4817a4: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x4817a6: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  { // 0x4817a9: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  { // 0x4817ac: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4817ae: 7e39 JLE 0x004817e9
    if(integer::condition("JLE",flags)) goto L004817e9;
  }
  L004817b0: { // 0x4817b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4817b1: e87aedffff CALL 0x00480530
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4817b6: f60002 TEST byte ptr [EAX],0x2
    (void)integer::logical((m.r8((s.ax)))&(0x00000002u),8,flags);
  }
  { // 0x4817b9: 7425 JZ 0x004817e0
    if(integer::condition("JZ",flags)) goto L004817e0;
  }
  { // 0x4817bb: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  { // 0x4817be: 80780201 CMP byte ptr [EAX + 0x2],0x1
    (void)integer::sub(m.r8((s.ax+0x00000002u)),0x00000001u,8,flags);
  }
  { // 0x4817c2: 740a JZ 0x004817ce
    if(integer::condition("JZ",flags)) goto L004817ce;
  }
  { // 0x4817c4: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  { // 0x4817c7: 8b4f44 MOV ECX,dword ptr [EDI + 0x44]
    s.cx = m.r32((s.di+0x00000044u));
  }
  { // 0x4817ca: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4817cc: 7312 JNC 0x004817e0
    if(integer::condition("JNC",flags)) goto L004817e0;
  }
  L004817ce: { // 0x4817ce: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  { // 0x4817d1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4817d3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4817d5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4817d6: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4817d8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4817da: e801ecffff CALL 0x004803e0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4817df: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L004817e0: { // 0x4817e0: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  { // 0x4817e3: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x4817e4: 3b7138 CMP ESI,dword ptr [ECX + 0x38]
    (void)integer::sub(s.si,m.r32((s.cx+0x00000038u)),32,flags);
  }
  { // 0x4817e7: 7cc7 JL 0x004817b0
    if(integer::condition("JL",flags)) goto L004817b0;
  }
  L004817e9: { // 0x4817e9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4817ea: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x4817ef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4817f0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00082850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x482850: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x482851: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x482853: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x482854: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x482855: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x482857: 7423 JZ 0x0048287c
    if(integer::condition("JZ",flags)) goto L0048287c;
  }
  { // 0x482859: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x48285b: be505b7800 MOV ESI,0x785b50
    s.si = 0x00785b50u;
  }
  L00482860: { // 0x482860: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x482862: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x482863: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x482864: e8f7af2e00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x482869: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x48286c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x48286e: 7413 JZ 0x00482883
    if(integer::condition("JZ",flags)) goto L00482883;
  }
  { // 0x482870: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x482873: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x482874: 81fe645b7800 CMP ESI,0x785b64
    (void)integer::sub(s.si,0x00785b64u,32,flags);
  }
  { // 0x48287a: 7ce4 JL 0x00482860
    if(integer::condition("JL",flags)) goto L00482860;
  }
  L0048287c: { // 0x48287c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x48287d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x48287e: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x482881: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x482882: c3 RET
    finish(m,s,f,0u); return;
  }
  L00482883: { // 0x482883: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x482885: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x482886: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x482887: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x482888: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000828b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4828b0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4828b1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4828b2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4828b3: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x4828b5: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x4828b7: be685b7800 MOV ESI,0x785b68
    s.si = 0x00785b68u;
  }
  L004828bc: { // 0x4828bc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4828bd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4828be: e89daf2e00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4828c3: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4828c6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4828c8: 7413 JZ 0x004828dd
    if(integer::condition("JZ",flags)) goto L004828dd;
  }
  { // 0x4828ca: 83c668 ADD ESI,0x68
    s.si = integer::add(s.si,0x00000068u,32,flags);
  }
  { // 0x4828cd: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x4828ce: 81fea05c7800 CMP ESI,0x785ca0
    (void)integer::sub(s.si,0x00785ca0u,32,flags);
  }
  { // 0x4828d4: 7ce6 JL 0x004828bc
    if(integer::condition("JL",flags)) goto L004828bc;
  }
  { // 0x4828d6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4828d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4828d8: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x4828db: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4828dc: c3 RET
    finish(m,s,f,0u); return;
  }
  L004828dd: { // 0x4828dd: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x4828df: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4828e0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4828e1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4828e2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00082b40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x482b40: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x482b41: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x482b43: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x482b44: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x482b45: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x482b47: 7423 JZ 0x00482b6c
    if(integer::condition("JZ",flags)) goto L00482b6c;
  }
  { // 0x482b49: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x482b4b: be548e7800 MOV ESI,0x788e54
    s.si = 0x00788e54u;
  }
  L00482b50: { // 0x482b50: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x482b52: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x482b53: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x482b54: e807ad2e00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x482b59: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x482b5c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x482b5e: 7412 JZ 0x00482b72
    if(integer::condition("JZ",flags)) goto L00482b72;
  }
  { // 0x482b60: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x482b63: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x482b64: 81fea08e7800 CMP ESI,0x788ea0
    (void)integer::sub(s.si,0x00788ea0u,32,flags);
  }
  { // 0x482b6a: 7ce4 JL 0x00482b50
    if(integer::condition("JL",flags)) goto L00482b50;
  }
  L00482b6c: { // 0x482b6c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x482b6d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x482b6e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x482b70: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x482b71: c3 RET
    finish(m,s,f,0u); return;
  }
  L00482b72: { // 0x482b72: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x482b74: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x482b75: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x482b76: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x482b77: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00082c00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x482c00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x482c01: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x482c02: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x482c04: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x482c06: 743d JZ 0x00482c45
    if(integer::condition("JZ",flags)) goto L00482c45;
  }
  { // 0x482c08: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x482c09: 685c8e7b00 PUSH 0x7b8e5c
    f.push(m,0x007b8e5cu);
  }
  { // 0x482c0e: e84dac2e00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x482c13: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x482c16: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x482c18: 742b JZ 0x00482c45
    if(integer::condition("JZ",flags)) goto L00482c45;
  }
  { // 0x482c1a: a1788ca500 MOV EAX,[0x00a58c78]
    s.ax = m.r32((0x00a58c78u));
  }
  { // 0x482c1f: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x482c21: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x482c23: 7e20 JLE 0x00482c45
    if(integer::condition("JLE",flags)) goto L00482c45;
  }
  L00482c25: { // 0x482c25: a16c8ca500 MOV EAX,[0x00a58c6c]
    s.ax = m.r32((0x00a58c6cu));
  }
  { // 0x482c2a: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x482c2d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x482c2e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x482c2f: e82cac2e00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x482c34: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x482c37: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x482c39: 7410 JZ 0x00482c4b
    if(integer::condition("JZ",flags)) goto L00482c4b;
  }
  { // 0x482c3b: a1788ca500 MOV EAX,[0x00a58c78]
    s.ax = m.r32((0x00a58c78u));
  }
  { // 0x482c40: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x482c41: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x482c43: 7ce0 JL 0x00482c25
    if(integer::condition("JL",flags)) goto L00482c25;
  }
  L00482c45: { // 0x482c45: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x482c46: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x482c49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x482c4a: c3 RET
    finish(m,s,f,0u); return;
  }
  L00482c4b: { // 0x482c4b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x482c4d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x482c4e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x482c4f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00082c50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x482c50: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x482c51: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x482c52: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x482c54: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x482c55: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x482c56: 685c8e7b00 PUSH 0x7b8e5c
    f.push(m,0x007b8e5cu);
  }
  { // 0x482c5b: e800ac2e00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x482c60: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x482c63: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x482c65: 7427 JZ 0x00482c8e
    if(integer::condition("JZ",flags)) goto L00482c8e;
  }
  { // 0x482c67: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x482c69: 7423 JZ 0x00482c8e
    if(integer::condition("JZ",flags)) goto L00482c8e;
  }
  { // 0x482c6b: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x482c6d: beace97b00 MOV ESI,0x7be9ac
    s.si = 0x007be9acu;
  }
  L00482c72: { // 0x482c72: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x482c74: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x482c75: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x482c76: e8e5ab2e00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x482c7b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x482c7e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x482c80: 7413 JZ 0x00482c95
    if(integer::condition("JZ",flags)) goto L00482c95;
  }
  { // 0x482c82: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x482c85: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x482c86: 81fedce97b00 CMP ESI,0x7be9dc
    (void)integer::sub(s.si,0x007be9dcu,32,flags);
  }
  { // 0x482c8c: 7ce4 JL 0x00482c72
    if(integer::condition("JL",flags)) goto L00482c72;
  }
  L00482c8e: { // 0x482c8e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x482c8f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x482c90: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x482c93: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x482c94: c3 RET
    finish(m,s,f,0u); return;
  }
  L00482c95: { // 0x482c95: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x482c97: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x482c98: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x482c99: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x482c9a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00082cc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x482cc0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x482cc1: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x482cc3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x482cc4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x482cc5: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x482cc7: 7423 JZ 0x00482cec
    if(integer::condition("JZ",flags)) goto L00482cec;
  }
  { // 0x482cc9: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x482ccb: bedce97b00 MOV ESI,0x7be9dc
    s.si = 0x007be9dcu;
  }
  L00482cd0: { // 0x482cd0: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x482cd2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x482cd3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x482cd4: e887ab2e00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x482cd9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x482cdc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x482cde: 7413 JZ 0x00482cf3
    if(integer::condition("JZ",flags)) goto L00482cf3;
  }
  { // 0x482ce0: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x482ce3: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x482ce4: 81fefce97b00 CMP ESI,0x7be9fc
    (void)integer::sub(s.si,0x007be9fcu,32,flags);
  }
  { // 0x482cea: 7ce4 JL 0x00482cd0
    if(integer::condition("JL",flags)) goto L00482cd0;
  }
  L00482cec: { // 0x482cec: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x482ced: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x482cee: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x482cf1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x482cf2: c3 RET
    finish(m,s,f,0u); return;
  }
  L00482cf3: { // 0x482cf3: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x482cf5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x482cf6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x482cf7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x482cf8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00082d20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x482d20: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x482d21: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x482d23: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x482d24: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x482d25: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x482d27: 7423 JZ 0x00482d4c
    if(integer::condition("JZ",flags)) goto L00482d4c;
  }
  { // 0x482d29: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x482d2b: befce97b00 MOV ESI,0x7be9fc
    s.si = 0x007be9fcu;
  }
  L00482d30: { // 0x482d30: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x482d32: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x482d33: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x482d34: e827ab2e00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x482d39: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x482d3c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x482d3e: 7413 JZ 0x00482d53
    if(integer::condition("JZ",flags)) goto L00482d53;
  }
  { // 0x482d40: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x482d43: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x482d44: 81fe10ea7b00 CMP ESI,0x7bea10
    (void)integer::sub(s.si,0x007bea10u,32,flags);
  }
  { // 0x482d4a: 7ce4 JL 0x00482d30
    if(integer::condition("JL",flags)) goto L00482d30;
  }
  L00482d4c: { // 0x482d4c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x482d4d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x482d4e: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x482d51: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x482d52: c3 RET
    finish(m,s,f,0u); return;
  }
  L00482d53: { // 0x482d53: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x482d55: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x482d56: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x482d57: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x482d58: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00090280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x490280: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x490281: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x490282: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x490283: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x490285: 68b0ce7b00 PUSH 0x7bceb0
    f.push(m,0x007bceb0u);
  }
  { // 0x49028a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x49028b: e8d0d52d00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x490290: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x490293: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x490295: 7509 JNZ 0x004902a0
    if(integer::condition("JNZ",flags)) goto L004902a0;
  }
  { // 0x490297: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x490298: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x490299: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  { // 0x49029e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x49029f: c3 RET
    finish(m,s,f,0u); return;
  }
  L004902a0: { // 0x4902a0: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x4902a2: 743f JZ 0x004902e3
    if(integer::condition("JZ",flags)) goto L004902e3;
  }
  { // 0x4902a4: a148e0a100 MOV EAX,[0x00a1e048]
    s.ax = m.r32((0x00a1e048u));
  }
  { // 0x4902a9: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x4902ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4902ad: 7e34 JLE 0x004902e3
    if(integer::condition("JLE",flags)) goto L004902e3;
  }
  L004902af: { // 0x4902af: a13ce0a100 MOV EAX,[0x00a1e03c]
    s.ax = m.r32((0x00a1e03cu));
  }
  { // 0x4902b4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4902b5: 8b3498 MOV ESI,dword ptr [EAX + EBX*0x4]
    s.si = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  { // 0x4902b8: 8d4e64 LEA ECX,[ESI + 0x64]
    s.cx = (s.si+0x00000064u);
  }
  { // 0x4902bb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4902bc: e89fd52d00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4902c1: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4902c4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4902c6: 7422 JZ 0x004902ea
    if(integer::condition("JZ",flags)) goto L004902ea;
  }
  { // 0x4902c8: 83c624 ADD ESI,0x24
    s.si = integer::add(s.si,0x00000024u,32,flags);
  }
  { // 0x4902cb: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4902cc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4902cd: e88ed52d00 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4902d2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4902d5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4902d7: 7411 JZ 0x004902ea
    if(integer::condition("JZ",flags)) goto L004902ea;
  }
  { // 0x4902d9: a148e0a100 MOV EAX,[0x00a1e048]
    s.ax = m.r32((0x00a1e048u));
  }
  { // 0x4902de: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x4902df: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x4902e1: 7ccc JL 0x004902af
    if(integer::condition("JL",flags)) goto L004902af;
  }
  L004902e3: { // 0x4902e3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4902e4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4902e5: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x4902e8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4902e9: c3 RET
    finish(m,s,f,0u); return;
  }
  L004902ea: { // 0x4902ea: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4902eb: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x4902ed: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4902ee: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4902ef: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00090be0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x490be0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x490be1: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x490be3: 8a4358 MOV AL,byte ptr [EBX + 0x58]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000058u)));
  }
  { // 0x490be6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x490be8: 7461 JZ 0x00490c4b
    if(integer::condition("JZ",flags)) goto L00490c4b;
  }
  { // 0x490bea: 8b4b54 MOV ECX,dword ptr [EBX + 0x54]
    s.cx = m.r32((s.bx+0x00000054u));
  }
  { // 0x490bed: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x490bee: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x490bef: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x490bf3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x490bf5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x490bf6: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x490bf8: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x490bfa: ff5008 CALL dword ptr [EAX + 0x8]
    const std::uint32_t call_target=m.r32((s.ax+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x490bfd: 8b4354 MOV EAX,dword ptr [EBX + 0x54]
    s.ax = m.r32((s.bx+0x00000054u));
  }
  { // 0x490c00: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x490c02: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x490c04: 7e3d JLE 0x00490c43
    if(integer::condition("JLE",flags)) goto L00490c43;
  }
  { // 0x490c06: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x490c07: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00490c09: { // 0x490c09: 6802010000 PUSH 0x102
    f.push(m,0x00000102u);
  }
  { // 0x490c0e: e844cd2d00 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x490c13: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x490c16: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x490c19: 8904b2 MOV dword ptr [EDX + ESI*0x4],EAX
    m.w32((s.dx+(s.si * 0x00000004u)), s.ax);
  }
  { // 0x490c1c: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x490c1f: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x490c22: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x490c24: 7411 JZ 0x00490c37
    if(integer::condition("JZ",flags)) goto L00490c37;
  }
  { // 0x490c26: 8b4b50 MOV ECX,dword ptr [EBX + 0x50]
    s.cx = m.r32((s.bx+0x00000050u));
  }
  { // 0x490c29: 8b542904 MOV EDX,dword ptr [ECX + EBP*0x1 + 0x4]
    s.dx = m.r32((s.cx+(s.bp * 0x00000001u)+0x00000004u));
  }
  { // 0x490c2d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x490c2e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x490c2f: e895e32d00 CALL 0x0076efc9
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x490c34: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00490c37: { // 0x490c37: 8b4354 MOV EAX,dword ptr [EBX + 0x54]
    s.ax = m.r32((s.bx+0x00000054u));
  }
  { // 0x490c3a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x490c3b: 83c544 ADD EBP,0x44
    s.bp = integer::add(s.bp,0x00000044u,32,flags);
  }
  { // 0x490c3e: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x490c40: 7cc7 JL 0x00490c09
    if(integer::condition("JL",flags)) goto L00490c09;
  }
  { // 0x490c42: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00490c43: { // 0x490c43: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x490c44: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x490c45: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x490c47: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x490c48: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00490c4b: { // 0x490c4b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x490c4d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x490c4e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00091b90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x491b90: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x491b91: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x491b92: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x491b93: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  { // 0x491b97: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x491b98: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x491b9a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x491b9c: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x491b9e: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  { // 0x491ba2: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x491ba5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x491ba7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x491ba8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x491ba9: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x491bad: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x491bb0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x491bb2: 7c2a JL 0x00491bde
    if(integer::condition("JL",flags)) goto L00491bde;
  }
  { // 0x491bb4: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x491bb8: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x491bba: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x491bbc: 7e1e JLE 0x00491bdc
    if(integer::condition("JLE",flags)) goto L00491bdc;
  }
  L00491bbe: { // 0x491bbe: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  { // 0x491bc1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x491bc3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x491bc5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x491bc7: 8d1499 LEA EDX,[ECX + EBX*0x4]
    s.dx = (s.cx+(s.bx * 0x00000004u));
  }
  { // 0x491bca: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x491bcb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x491bcc: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x491bcf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x491bd1: 7c0b JL 0x00491bde
    if(integer::condition("JL",flags)) goto L00491bde;
  }
  { // 0x491bd3: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x491bd7: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x491bd8: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x491bda: 7ce2 JL 0x00491bbe
    if(integer::condition("JL",flags)) goto L00491bbe;
  }
  L00491bdc: { // 0x491bdc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00491bde: { // 0x491bde: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x491bdf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x491be0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x491be1: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x491be2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00092430(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x492430: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x492431: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x492432: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x492434: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x492435: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x492437: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x492439: c706fc957800 MOV dword ptr [ESI],0x7895fc
    m.w32((s.si), 0x007895fcu);
  }
  { // 0x49243f: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x492442: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x492444: 7e14 JLE 0x0049245a
    if(integer::condition("JLE",flags)) goto L0049245a;
  }
  L00492446: { // 0x492446: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x492449: 8b04f8 MOV EAX,dword ptr [EAX + EDI*0x8]
    s.ax = m.r32((s.ax+(s.di * 0x00000008u)));
  }
  { // 0x49244c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x49244d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x49244f: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x492452: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x492455: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x492456: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x492458: 7cec JL 0x00492446
    if(integer::condition("JL",flags)) goto L00492446;
  }
  L0049245a: { // 0x49245a: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  { // 0x49245d: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x492460: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x492462: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x492465: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x492468: c706dc957800 MOV dword ptr [ESI],0x7895dc
    m.w32((s.si), 0x007895dcu);
  }
  { // 0x49246e: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x492470: 7411 JZ 0x00492483
    if(integer::condition("JZ",flags)) goto L00492483;
  }
  { // 0x492472: 385e0d CMP byte ptr [ESI + 0xd],BL
    (void)integer::sub(m.r8((s.si+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  { // 0x492475: 740c JZ 0x00492483
    if(integer::condition("JZ",flags)) goto L00492483;
  }
  { // 0x492477: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x492478: e8feb12d00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x49247d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x492480: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00492483: { // 0x492483: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  { // 0x492486: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  { // 0x492489: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x49248a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49248b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x49248c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00092d90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x492d90: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x492d91: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x492d92: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x492d94: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x492d95: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x492d97: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x492d99: c70680967800 MOV dword ptr [ESI],0x789680
    m.w32((s.si), 0x00789680u);
  }
  { // 0x492d9f: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  { // 0x492da2: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x492da4: 7e14 JLE 0x00492dba
    if(integer::condition("JLE",flags)) goto L00492dba;
  }
  L00492da6: { // 0x492da6: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x492da9: 8b04b8 MOV EAX,dword ptr [EAX + EDI*0x4]
    s.ax = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x492dac: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x492dad: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x492daf: ff5108 CALL dword ptr [ECX + 0x8]
    const std::uint32_t call_target=m.r32((s.cx+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x492db2: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  { // 0x492db5: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x492db6: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x492db8: 7cec JL 0x00492da6
    if(integer::condition("JL",flags)) goto L00492da6;
  }
  L00492dba: { // 0x492dba: 8b560c MOV EDX,dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  { // 0x492dbd: 83c60c ADD ESI,0xc
    s.si = integer::add(s.si,0x0000000cu,32,flags);
  }
  { // 0x492dc0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x492dc2: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x492dc5: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x492dc8: c70660967800 MOV dword ptr [ESI],0x789660
    m.w32((s.si), 0x00789660u);
  }
  { // 0x492dce: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x492dd0: 7411 JZ 0x00492de3
    if(integer::condition("JZ",flags)) goto L00492de3;
  }
  { // 0x492dd2: 385e0d CMP byte ptr [ESI + 0xd],BL
    (void)integer::sub(m.r8((s.si+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  { // 0x492dd5: 740c JZ 0x00492de3
    if(integer::condition("JZ",flags)) goto L00492de3;
  }
  { // 0x492dd7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x492dd8: e89ea82d00 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x492ddd: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x492de0: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00492de3: { // 0x492de3: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  { // 0x492de6: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  { // 0x492de9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x492dea: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x492deb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x492dec: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00096800(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x496800: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x496803: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x496804: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x496806: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x49680a: e8c1921f00 CALL 0x0068fad0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x49680f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x496811: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  { // 0x496815: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L00496819: { // 0x496819: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  { // 0x49681c: 741d JZ 0x0049683b
    if(integer::condition("JZ",flags)) goto L0049683b;
  }
  { // 0x49681e: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x496822: e8a9921f00 CALL 0x0068fad0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x496827: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x49682b: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x49682d: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x49682f: 7d10 JGE 0x00496841
    if(integer::condition("JGE",flags)) goto L00496841;
  }
  { // 0x496831: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x496833: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x496835: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x496839: eb02 JMP 0x0049683d
    goto L0049683d;
  }
  L0049683b: { // 0x49683b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0049683d: { // 0x49683d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x49683f: 75d8 JNZ 0x00496819
    if(integer::condition("JNZ",flags)) goto L00496819;
  }
  L00496841: { // 0x496841: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x496842: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x496845: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000989c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4989c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4989c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4989c3: e888cd0a00 CALL 0x00545750
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4989c8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4989ca: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x4989cd: 8986a0110000 MOV dword ptr [ESI + 0x11a0],EAX
    m.w32((s.si+0x000011a0u), s.ax);
  }
  { // 0x4989d3: 8986a4110000 MOV dword ptr [ESI + 0x11a4],EAX
    m.w32((s.si+0x000011a4u), s.ax);
  }
  { // 0x4989d9: 898ea8110000 MOV dword ptr [ESI + 0x11a8],ECX
    m.w32((s.si+0x000011a8u), s.cx);
  }
  { // 0x4989df: 898678110000 MOV dword ptr [ESI + 0x1178],EAX
    m.w32((s.si+0x00001178u), s.ax);
  }
  { // 0x4989e5: 898eb4110000 MOV dword ptr [ESI + 0x11b4],ECX
    m.w32((s.si+0x000011b4u), s.cx);
  }
  { // 0x4989eb: 8886ac110000 MOV byte ptr [ESI + 0x11ac],AL
    m.w8((s.si+0x000011acu), (s.ax & 0xffu));
  }
  { // 0x4989f1: 8886cb110000 MOV byte ptr [ESI + 0x11cb],AL
    m.w8((s.si+0x000011cbu), (s.ax & 0xffu));
  }
  { // 0x4989f7: 8886cc110000 MOV byte ptr [ESI + 0x11cc],AL
    m.w8((s.si+0x000011ccu), (s.ax & 0xffu));
  }
  { // 0x4989fd: 8886ad110000 MOV byte ptr [ESI + 0x11ad],AL
    m.w8((s.si+0x000011adu), (s.ax & 0xffu));
  }
  { // 0x498a03: 8886ae110000 MOV byte ptr [ESI + 0x11ae],AL
    m.w8((s.si+0x000011aeu), (s.ax & 0xffu));
  }
  { // 0x498a09: bea8a88300 MOV ESI,0x83a8a8
    s.si = 0x0083a8a8u;
  }
  L00498a0e: { // 0x498a0e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x498a10: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x498a12: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x498a15: 83c618 ADD ESI,0x18
    s.si = integer::add(s.si,0x00000018u,32,flags);
  }
  { // 0x498a18: 81fe20a98300 CMP ESI,0x83a920
    (void)integer::sub(s.si,0x0083a920u,32,flags);
  }
  { // 0x498a1e: 7cee JL 0x00498a0e
    if(integer::condition("JL",flags)) goto L00498a0e;
  }
  { // 0x498a20: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x498a21: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0009e2a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x49e2a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x49e2a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x49e2a3: e8d8960800 CALL 0x00527980
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x49e2a8: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x49e2ad: e88e900b00 CALL 0x00557340
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x49e2b2: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x49e2b7: e8c48f0b00 CALL 0x00557280
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x49e2bc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x49e2be: c7054476a50000000000 MOV dword ptr [0x00a57644],0x0
    m.w32((0x00a57644u), 0x00000000u);
  }
  { // 0x49e2c8: 742d JZ 0x0049e2f7
    if(integer::condition("JZ",flags)) goto L0049e2f7;
  }
  L0049e2ca: { // 0x49e2ca: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  { // 0x49e2cf: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  { // 0x49e2d4: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  { // 0x49e2d9: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x49e2db: 6800000100 PUSH 0x10000
    f.push(m,0x00010000u);
  }
  { // 0x49e2e0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x49e2e2: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x49e2e4: e807aafdff CALL 0x00478cf0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x49e2e9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x49e2ee: e88d8f0b00 CALL 0x00557280
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x49e2f3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x49e2f5: 75d3 JNZ 0x0049e2ca
    if(integer::condition("JNZ",flags)) goto L0049e2ca;
  }
  L0049e2f7: { // 0x49e2f7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x49e2f9: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x49e2fb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x49e2fd: ff5038 CALL dword ptr [EAX + 0x38]
    const std::uint32_t call_target=m.r32((s.ax+0x00000038u));
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  { // 0x49e300: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49e301: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0009e310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x49e310: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x49e315: e826900b00 CALL 0x00557340
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x49e31a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x49e31f: e85c8f0b00 CALL 0x00557280
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x49e324: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x49e326: 7415 JZ 0x0049e33d
    if(integer::condition("JZ",flags)) goto L0049e33d;
  }
  L0049e328: { // 0x49e328: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x49e32a: e8c1b1fdff CALL 0x004794f0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x49e32f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x49e334: e8478f0b00 CALL 0x00557280
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x49e339: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x49e33b: 75eb JNZ 0x0049e328
    if(integer::condition("JNZ",flags)) goto L0049e328;
  }
  L0049e33d: { // 0x49e33d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0009e540(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x49e540: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x49e541: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x49e542: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x49e546: bea8a88300 MOV ESI,0x83a8a8
    s.si = 0x0083a8a8u;
  }
  L0049e54b: { // 0x49e54b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x49e54c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x49e54e: e88d470900 CALL 0x00532ce0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x49e553: 83c618 ADD ESI,0x18
    s.si = integer::add(s.si,0x00000018u,32,flags);
  }
  { // 0x49e556: 81fe20a98300 CMP ESI,0x83a920
    (void)integer::sub(s.si,0x0083a920u,32,flags);
  }
  { // 0x49e55c: 7ced JL 0x0049e54b
    if(integer::condition("JL",flags)) goto L0049e54b;
  }
  { // 0x49e55e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x49e55f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49e560: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0009e570(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x49e570: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x49e571: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x49e572: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x49e576: bea8a88300 MOV ESI,0x83a8a8
    s.si = 0x0083a8a8u;
  }
  L0049e57b: { // 0x49e57b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x49e57c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x49e57e: e8ed460900 CALL 0x00532c70
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x49e583: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x49e585: 7c0b JL 0x0049e592
    if(integer::condition("JL",flags)) goto L0049e592;
  }
  { // 0x49e587: 83c618 ADD ESI,0x18
    s.si = integer::add(s.si,0x00000018u,32,flags);
  }
  { // 0x49e58a: 81fe20a98300 CMP ESI,0x83a920
    (void)integer::sub(s.si,0x0083a920u,32,flags);
  }
  { // 0x49e590: 7ce9 JL 0x0049e57b
    if(integer::condition("JL",flags)) goto L0049e57b;
  }
  L0049e592: { // 0x49e592: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x49e593: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x49e594: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000a67f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a67f0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4a67f1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a67f2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4a67f4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a67f5: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x4a67f7: 8b7e10 MOV EDI,dword ptr [ESI + 0x10]
    s.di = m.r32((s.si+0x00000010u));
  }
  { // 0x4a67fa: 885e0c MOV byte ptr [ESI + 0xc],BL
    m.w8((s.si+0x0000000cu), (s.bx & 0xffu));
  }
  { // 0x4a67fd: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  { // 0x4a67ff: 7e0b JLE 0x004a680c
    if(integer::condition("JLE",flags)) goto L004a680c;
  }
  L004a6801: { // 0x4a6801: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4a6802: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4a6804: e817ffffff CALL 0x004a6720
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4a6809: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x4a680a: 75f5 JNZ 0x004a6801
    if(integer::condition("JNZ",flags)) goto L004a6801;
  }
  L004a680c: { // 0x4a680c: 895e10 MOV dword ptr [ESI + 0x10],EBX
    m.w32((s.si+0x00000010u), s.bx);
  }
  { // 0x4a680f: 895e28 MOV dword ptr [ESI + 0x28],EBX
    m.w32((s.si+0x00000028u), s.bx);
  }
  { // 0x4a6812: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4a6813: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a6814: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4a6815: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000a6820(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4a6820: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4a6821: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x4a6823: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4a6824: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x4a6826: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x4a6829: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4a682b: 7e1b JLE 0x004a6848
    if(integer::condition("JLE",flags)) goto L004a6848;
  }
  { // 0x4a682d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a682e: 8d7b14 LEA EDI,[EBX + 0x14]
    s.di = (s.bx+0x00000014u);
  }
  L004a6831: { // 0x4a6831: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4a6832: 687053aa00 PUSH 0xaa5370
    f.push(m,0x00aa5370u);
  }
  { // 0x4a6837: e834e91e00 CALL 0x00695170
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4a683c: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x4a683f: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x4a6840: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  { // 0x4a6843: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x4a6845: 7cea JL 0x004a6831
    if(integer::condition("JL",flags)) goto L004a6831;
  }
  { // 0x4a6847: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004a6848: { // 0x4a6848: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4a6849: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4a684a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000ced90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ced90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4ced91: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4ced93: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4ced95: ff5008 CALL dword ptr [EAX + 0x8]
    const std::uint32_t call_target=m.r32((s.ax+0x00000008u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4ced98: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4ced9a: 7414 JZ 0x004cedb0
    if(integer::condition("JZ",flags)) goto L004cedb0;
  }
  L004ced9c: { // 0x4ced9c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4ced9e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4ceda0: ff5208 CALL dword ptr [EDX + 0x8]
    const std::uint32_t call_target=m.r32((s.dx+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4ceda3: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4ceda5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4ceda7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4ceda9: ff5008 CALL dword ptr [EAX + 0x8]
    const std::uint32_t call_target=m.r32((s.ax+0x00000008u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4cedac: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4cedae: 75ec JNZ 0x004ced9c
    if(integer::condition("JNZ",flags)) goto L004ced9c;
  }
  L004cedb0: { // 0x4cedb0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4cedb2: 7424 JZ 0x004cedd8
    if(integer::condition("JZ",flags)) goto L004cedd8;
  }
  { // 0x4cedb4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004cedb5: { // 0x4cedb5: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4cedb7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4cedb9: ff5254 CALL dword ptr [EDX + 0x54]
    const std::uint32_t call_target=m.r32((s.dx+0x00000054u));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4cedbc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4cedbe: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4cedc0: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x4cedc2: ff5004 CALL dword ptr [EAX + 0x4]
    const std::uint32_t call_target=m.r32((s.ax+0x00000004u));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  { // 0x4cedc5: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x4cedc7: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4cedc9: 7408 JZ 0x004cedd3
    if(integer::condition("JZ",flags)) goto L004cedd3;
  }
  { // 0x4cedcb: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  { // 0x4cedcd: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4cedcf: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4cedd1: ff12 CALL dword ptr [EDX]
    const std::uint32_t call_target=m.r32((s.dx));
    invoke(m,s,f,op,5u,call_target); flags=0x202u;
  }
  L004cedd3: { // 0x4cedd3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4cedd5: 75de JNZ 0x004cedb5
    if(integer::condition("JNZ",flags)) goto L004cedb5;
  }
  { // 0x4cedd7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004cedd8: { // 0x4cedd8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4cedd9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000cee40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4cee40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4cee41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4cee43: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4cee45: 7421 JZ 0x004cee68
    if(integer::condition("JZ",flags)) goto L004cee68;
  }
  { // 0x4cee47: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4cee48: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4cee4c: 81e7ff000000 AND EDI,0xff
    s.di = integer::logical((s.di)&(0x000000ffu),32,flags);
  }
  L004cee52: { // 0x4cee52: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4cee54: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4cee55: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4cee57: ff506c CALL dword ptr [EAX + 0x6c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000006cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4cee5a: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4cee5c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4cee5e: ff5204 CALL dword ptr [EDX + 0x4]
    const std::uint32_t call_target=m.r32((s.dx+0x00000004u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4cee61: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4cee63: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4cee65: 75eb JNZ 0x004cee52
    if(integer::condition("JNZ",flags)) goto L004cee52;
  }
  { // 0x4cee67: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004cee68: { // 0x4cee68: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4cee69: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_000d1030(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4d1030: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4d1031: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4d1032: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x4d1034: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004d1036: { // 0x4d1036: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4d1038: 7507 JNZ 0x004d1041
    if(integer::condition("JNZ",flags)) goto L004d1041;
  }
  { // 0x4d103a: baa1060000 MOV EDX,0x6a1
    s.dx = 0x000006a1u;
  }
  { // 0x4d103f: eb5d JMP 0x004d109e
    goto L004d109e;
  }
  L004d1041: { // 0x4d1041: 83fe01 CMP ESI,0x1
    (void)integer::sub(s.si,0x00000001u,32,flags);
  }
  { // 0x4d1044: 7507 JNZ 0x004d104d
    if(integer::condition("JNZ",flags)) goto L004d104d;
  }
  { // 0x4d1046: ba10050000 MOV EDX,0x510
    s.dx = 0x00000510u;
  }
  { // 0x4d104b: eb51 JMP 0x004d109e
    goto L004d109e;
  }
  L004d104d: { // 0x4d104d: 83fe02 CMP ESI,0x2
    (void)integer::sub(s.si,0x00000002u,32,flags);
  }
  { // 0x4d1050: 7507 JNZ 0x004d1059
    if(integer::condition("JNZ",flags)) goto L004d1059;
  }
  { // 0x4d1052: ba13050000 MOV EDX,0x513
    s.dx = 0x00000513u;
  }
  { // 0x4d1057: eb45 JMP 0x004d109e
    goto L004d109e;
  }
  L004d1059: { // 0x4d1059: 83fe03 CMP ESI,0x3
    (void)integer::sub(s.si,0x00000003u,32,flags);
  }
  { // 0x4d105c: 7507 JNZ 0x004d1065
    if(integer::condition("JNZ",flags)) goto L004d1065;
  }
  { // 0x4d105e: ba1e050000 MOV EDX,0x51e
    s.dx = 0x0000051eu;
  }
  { // 0x4d1063: eb39 JMP 0x004d109e
    goto L004d109e;
  }
  L004d1065: { // 0x4d1065: 83fe04 CMP ESI,0x4
    (void)integer::sub(s.si,0x00000004u,32,flags);
  }
  { // 0x4d1068: 7507 JNZ 0x004d1071
    if(integer::condition("JNZ",flags)) goto L004d1071;
  }
  { // 0x4d106a: ba14050000 MOV EDX,0x514
    s.dx = 0x00000514u;
  }
  { // 0x4d106f: eb2d JMP 0x004d109e
    goto L004d109e;
  }
  L004d1071: { // 0x4d1071: 83fe05 CMP ESI,0x5
    (void)integer::sub(s.si,0x00000005u,32,flags);
  }
  { // 0x4d1074: 7507 JNZ 0x004d107d
    if(integer::condition("JNZ",flags)) goto L004d107d;
  }
  { // 0x4d1076: ba1f050000 MOV EDX,0x51f
    s.dx = 0x0000051fu;
  }
  { // 0x4d107b: eb21 JMP 0x004d109e
    goto L004d109e;
  }
  L004d107d: { // 0x4d107d: 83fe06 CMP ESI,0x6
    (void)integer::sub(s.si,0x00000006u,32,flags);
  }
  { // 0x4d1080: 7507 JNZ 0x004d1089
    if(integer::condition("JNZ",flags)) goto L004d1089;
  }
  { // 0x4d1082: ba20050000 MOV EDX,0x520
    s.dx = 0x00000520u;
  }
  { // 0x4d1087: eb15 JMP 0x004d109e
    goto L004d109e;
  }
  L004d1089: { // 0x4d1089: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x4d108b: 83ea07 SUB EDX,0x7
    s.dx = integer::sub(s.dx,0x00000007u,32,flags);
  }
  { // 0x4d108e: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  { // 0x4d1090: 1bd2 SBB EDX,EDX
    s.dx = integer::sub(s.dx,s.dx,32,flags,flags&integer::CF);
  }
  { // 0x4d1092: 81e2defaffff AND EDX,0xfffffade
    s.dx = integer::logical((s.dx)&(0xfffffadeu),32,flags);
  }
  { // 0x4d1098: 81c221050000 ADD EDX,0x521
    s.dx = integer::add(s.dx,0x00000521u,32,flags);
  }
  L004d109e: { // 0x4d109e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4d10a0: e8bbfeffff CALL 0x004d0f60
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4d10a5: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x4d10a6: 83fe08 CMP ESI,0x8
    (void)integer::sub(s.si,0x00000008u,32,flags);
  }
  { // 0x4d10a9: 7c8b JL 0x004d1036
    if(integer::condition("JL",flags)) goto L004d1036;
  }
  { // 0x4d10ab: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4d10ac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4d10ad: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000d1a80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4d1a80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4d1a81: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4d1a82: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x4d1a84: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004d1a86: { // 0x4d1a86: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4d1a88: 7507 JNZ 0x004d1a91
    if(integer::condition("JNZ",flags)) goto L004d1a91;
  }
  { // 0x4d1a8a: baa2060000 MOV EDX,0x6a2
    s.dx = 0x000006a2u;
  }
  { // 0x4d1a8f: eb5d JMP 0x004d1aee
    goto L004d1aee;
  }
  L004d1a91: { // 0x4d1a91: 83fe01 CMP ESI,0x1
    (void)integer::sub(s.si,0x00000001u,32,flags);
  }
  { // 0x4d1a94: 7507 JNZ 0x004d1a9d
    if(integer::condition("JNZ",flags)) goto L004d1a9d;
  }
  { // 0x4d1a96: ba22050000 MOV EDX,0x522
    s.dx = 0x00000522u;
  }
  { // 0x4d1a9b: eb51 JMP 0x004d1aee
    goto L004d1aee;
  }
  L004d1a9d: { // 0x4d1a9d: 83fe02 CMP ESI,0x2
    (void)integer::sub(s.si,0x00000002u,32,flags);
  }
  { // 0x4d1aa0: 7507 JNZ 0x004d1aa9
    if(integer::condition("JNZ",flags)) goto L004d1aa9;
  }
  { // 0x4d1aa2: ba23050000 MOV EDX,0x523
    s.dx = 0x00000523u;
  }
  { // 0x4d1aa7: eb45 JMP 0x004d1aee
    goto L004d1aee;
  }
  L004d1aa9: { // 0x4d1aa9: 83fe03 CMP ESI,0x3
    (void)integer::sub(s.si,0x00000003u,32,flags);
  }
  { // 0x4d1aac: 7507 JNZ 0x004d1ab5
    if(integer::condition("JNZ",flags)) goto L004d1ab5;
  }
  { // 0x4d1aae: ba24050000 MOV EDX,0x524
    s.dx = 0x00000524u;
  }
  { // 0x4d1ab3: eb39 JMP 0x004d1aee
    goto L004d1aee;
  }
  L004d1ab5: { // 0x4d1ab5: 83fe04 CMP ESI,0x4
    (void)integer::sub(s.si,0x00000004u,32,flags);
  }
  { // 0x4d1ab8: 7507 JNZ 0x004d1ac1
    if(integer::condition("JNZ",flags)) goto L004d1ac1;
  }
  { // 0x4d1aba: ba25050000 MOV EDX,0x525
    s.dx = 0x00000525u;
  }
  { // 0x4d1abf: eb2d JMP 0x004d1aee
    goto L004d1aee;
  }
  L004d1ac1: { // 0x4d1ac1: 83fe05 CMP ESI,0x5
    (void)integer::sub(s.si,0x00000005u,32,flags);
  }
  { // 0x4d1ac4: 7507 JNZ 0x004d1acd
    if(integer::condition("JNZ",flags)) goto L004d1acd;
  }
  { // 0x4d1ac6: ba26050000 MOV EDX,0x526
    s.dx = 0x00000526u;
  }
  { // 0x4d1acb: eb21 JMP 0x004d1aee
    goto L004d1aee;
  }
  L004d1acd: { // 0x4d1acd: 83fe06 CMP ESI,0x6
    (void)integer::sub(s.si,0x00000006u,32,flags);
  }
  { // 0x4d1ad0: 7507 JNZ 0x004d1ad9
    if(integer::condition("JNZ",flags)) goto L004d1ad9;
  }
  { // 0x4d1ad2: ba27050000 MOV EDX,0x527
    s.dx = 0x00000527u;
  }
  { // 0x4d1ad7: eb15 JMP 0x004d1aee
    goto L004d1aee;
  }
  L004d1ad9: { // 0x4d1ad9: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x4d1adb: 83ea07 SUB EDX,0x7
    s.dx = integer::sub(s.dx,0x00000007u,32,flags);
  }
  { // 0x4d1ade: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  { // 0x4d1ae0: 1bd2 SBB EDX,EDX
    s.dx = integer::sub(s.dx,s.dx,32,flags,flags&integer::CF);
  }
  { // 0x4d1ae2: 81e2d7faffff AND EDX,0xfffffad7
    s.dx = integer::logical((s.dx)&(0xfffffad7u),32,flags);
  }
  { // 0x4d1ae8: 81c228050000 ADD EDX,0x528
    s.dx = integer::add(s.dx,0x00000528u,32,flags);
  }
  L004d1aee: { // 0x4d1aee: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4d1af0: e8cbfdffff CALL 0x004d18c0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4d1af5: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x4d1af6: 83fe08 CMP ESI,0x8
    (void)integer::sub(s.si,0x00000008u,32,flags);
  }
  { // 0x4d1af9: 7c8b JL 0x004d1a86
    if(integer::condition("JL",flags)) goto L004d1a86;
  }
  { // 0x4d1afb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4d1afc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4d1afd: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000dd5b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4dd5b0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4dd5b1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4dd5b2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4dd5b4: ba20d64d00 MOV EDX,0x4dd620
    s.dx = 0x004dd620u;
  }
  { // 0x4dd5b9: b9b6000000 MOV ECX,0xb6
    s.cx = 0x000000b6u;
  }
  { // 0x4dd5be: c744240800000000 MOV dword ptr [ESP + 0x8],0x0
    m.w32((f.sp+0x00000008u), 0x00000000u);
  }
  { // 0x4dd5c6: e8059d1100 CALL 0x005f72d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4dd5cb: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4dd5cd: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4dd5cf: 743f JZ 0x004dd610
    if(integer::condition("JZ",flags)) goto L004dd610;
  }
  { // 0x4dd5d1: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x4dd5d5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4dd5d6: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x4dd5d8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4dd5d9: ff1588547800 CALL dword ptr [0x00785488]
    const std::uint32_t call_target=m.r32((0x00785488u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4dd5df: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4dd5e1: e89a9e1100 CALL 0x005f7480
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4dd5e6: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4dd5ea: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4dd5ec: 751b JNZ 0x004dd609
    if(integer::condition("JNZ",flags)) goto L004dd609;
  }
  L004dd5ee: { // 0x4dd5ee: e87da71100 CALL 0x005f7d70
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x4dd5f3: 3c01 CMP AL,0x1
    (void)integer::sub((s.ax & 0xffu),0x00000001u,8,flags);
  }
  { // 0x4dd5f5: 740a JZ 0x004dd601
    if(integer::condition("JZ",flags)) goto L004dd601;
  }
  { // 0x4dd5f7: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4dd5fb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4dd5fd: 750a JNZ 0x004dd609
    if(integer::condition("JNZ",flags)) goto L004dd609;
  }
  { // 0x4dd5ff: ebed JMP 0x004dd5ee
    goto L004dd5ee;
  }
  L004dd601: { // 0x4dd601: c744240401000000 MOV dword ptr [ESP + 0x4],0x1
    m.w32((f.sp+0x00000004u), 0x00000001u);
  }
  L004dd609: { // 0x4dd609: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4dd60b: e8909d1100 CALL 0x005f73a0
    const std::uint32_t call_target=f.boundaries[4u].target;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L004dd610: { // 0x4dd610: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x4dd614: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4dd615: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x4dd616: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000ebeb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ebeb0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4ebeb1: 8b1db088a200 MOV EBX,dword ptr [0x00a288b0]
    s.bx = m.r32((0x00a288b0u));
  }
  { // 0x4ebeb7: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x4ebeb9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4ebeba: 7469 JZ 0x004ebf25
    if(integer::condition("JZ",flags)) goto L004ebf25;
  }
  { // 0x4ebebc: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x4ebebe: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x4ebec0: 7e63 JLE 0x004ebf25
    if(integer::condition("JLE",flags)) goto L004ebf25;
  }
  { // 0x4ebec2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ebec3: { // 0x4ebec3: a1a488a200 MOV EAX,[0x00a288a4]
    s.ax = m.r32((0x00a288a4u));
  }
  { // 0x4ebec8: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x4ebecb: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4ebecd: 7450 JZ 0x004ebf1f
    if(integer::condition("JZ",flags)) goto L004ebf1f;
  }
  { // 0x4ebecf: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4ebed1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4ebed3: ff522c CALL dword ptr [EDX + 0x2c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000002cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4ebed6: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  { // 0x4ebed9: 7544 JNZ 0x004ebf1f
    if(integer::condition("JNZ",flags)) goto L004ebf1f;
  }
  { // 0x4ebedb: 8a8672030000 MOV AL,byte ptr [ESI + 0x372]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000372u)));
  }
  { // 0x4ebee1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4ebee3: 753a JNZ 0x004ebf1f
    if(integer::condition("JNZ",flags)) goto L004ebf1f;
  }
  { // 0x4ebee5: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  { // 0x4ebeeb: 8b88680c0000 MOV ECX,dword ptr [EAX + 0xc68]
    s.cx = m.r32((s.ax+0x00000c68u));
  }
  { // 0x4ebef1: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4ebef3: 7e2a JLE 0x004ebf1f
    if(integer::condition("JLE",flags)) goto L004ebf1f;
  }
  { // 0x4ebef5: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  { // 0x4ebefb: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x4ebf00: 8b5134 MOV EDX,dword ptr [ECX + 0x34]
    s.dx = m.r32((s.cx+0x00000034u));
  }
  { // 0x4ebf03: 8b8ab8000000 MOV ECX,dword ptr [EDX + 0xb8]
    s.cx = m.r32((s.dx+0x000000b8u));
  }
  { // 0x4ebf09: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x4ebf0b: 8586a8010000 TEST dword ptr [ESI + 0x1a8],EAX
    (void)integer::logical((m.r32((s.si+0x000001a8u)))&(s.ax),32,flags);
  }
  { // 0x4ebf11: 740c JZ 0x004ebf1f
    if(integer::condition("JZ",flags)) goto L004ebf1f;
  }
  { // 0x4ebf13: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4ebf15: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x4ebf17: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4ebf19: ff921c010000 CALL dword ptr [EDX + 0x11c]
    const std::uint32_t call_target=m.r32((s.dx+0x0000011cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L004ebf1f: { // 0x4ebf1f: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x4ebf20: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  { // 0x4ebf22: 7c9f JL 0x004ebec3
    if(integer::condition("JL",flags)) goto L004ebec3;
  }
  { // 0x4ebf24: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ebf25: { // 0x4ebf25: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4ebf26: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4ebf27: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000f25d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4f25d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4f25d1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4f25d2: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x4f25d4: 8db958010000 LEA EDI,[ECX + 0x158]
    s.di = (s.cx+0x00000158u);
  }
  L004f25da: { // 0x4f25da: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x4f25dc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4f25de: 7519 JNZ 0x004f25f9
    if(integer::condition("JNZ",flags)) goto L004f25f9;
  }
  { // 0x4f25e0: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  { // 0x4f25e2: e870b32700 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4f25e7: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x4f25ea: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4f25ec: 7409 JZ 0x004f25f7
    if(integer::condition("JZ",flags)) goto L004f25f7;
  }
  { // 0x4f25ee: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x4f25f0: e8db702200 CALL 0x007196d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4f25f5: eb02 JMP 0x004f25f9
    goto L004f25f9;
  }
  L004f25f7: { // 0x4f25f7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f25f9: { // 0x4f25f9: 8b4838 MOV ECX,dword ptr [EAX + 0x38]
    s.cx = m.r32((s.ax+0x00000038u));
  }
  { // 0x4f25fc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4f25fe: 740f JZ 0x004f260f
    if(integer::condition("JZ",flags)) goto L004f260f;
  }
  { // 0x4f2600: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x4f2601: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  { // 0x4f2604: 83fe0c CMP ESI,0xc
    (void)integer::sub(s.si,0x0000000cu,32,flags);
  }
  { // 0x4f2607: 7cd1 JL 0x004f25da
    if(integer::condition("JL",flags)) goto L004f25da;
  }
  { // 0x4f2609: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f260a: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x4f260d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f260e: c3 RET
    finish(m,s,f,0u); return;
  }
  L004f260f: { // 0x4f260f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4f2611: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f2612: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f2613: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000f57b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4f57b0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4f57b1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4f57b2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4f57b3: 8b3d7088a200 MOV EDI,dword ptr [0x00a28870]
    s.di = m.r32((0x00a28870u));
  }
  { // 0x4f57b9: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x4f57bb: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x4f57bd: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x4f57bf: 7e21 JLE 0x004f57e2
    if(integer::condition("JLE",flags)) goto L004f57e2;
  }
  L004f57c1: { // 0x4f57c1: a16488a200 MOV EAX,[0x00a28864]
    s.ax = m.r32((0x00a28864u));
  }
  { // 0x4f57c6: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x4f57c9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4f57cb: 7410 JZ 0x004f57dd
    if(integer::condition("JZ",flags)) goto L004f57dd;
  }
  { // 0x4f57cd: 3999b4010000 CMP dword ptr [ECX + 0x1b4],EBX
    (void)integer::sub(m.r32((s.cx+0x000001b4u)),s.bx,32,flags);
  }
  { // 0x4f57d3: 7508 JNZ 0x004f57dd
    if(integer::condition("JNZ",flags)) goto L004f57dd;
  }
  { // 0x4f57d5: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x4f57d7: ff9234030000 CALL dword ptr [EDX + 0x334]
    const std::uint32_t call_target=m.r32((s.dx+0x00000334u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L004f57dd: { // 0x4f57dd: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x4f57de: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x4f57e0: 7cdf JL 0x004f57c1
    if(integer::condition("JL",flags)) goto L004f57c1;
  }
  L004f57e2: { // 0x4f57e2: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  { // 0x4f57e7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4f57e9: ba00200000 MOV EDX,0x2000
    s.dx = 0x00002000u;
  }
  { // 0x4f57ee: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  { // 0x4f57f3: 8b88c0010000 MOV ECX,dword ptr [EAX + 0x1c0]
    s.cx = m.r32((s.ax+0x000001c0u));
  }
  { // 0x4f57f9: e872312100 CALL 0x00708970
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4f57fe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f57ff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f5800: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4f5801: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_000f89d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4f89d0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4f89d1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4f89d2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4f89d3: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x4f89d5: 68b0ce7b00 PUSH 0x7bceb0
    f.push(m,0x007bceb0u);
  }
  { // 0x4f89da: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4f89db: e8804e2700 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x4f89e0: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4f89e3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4f89e5: 7509 JNZ 0x004f89f0
    if(integer::condition("JNZ",flags)) goto L004f89f0;
  }
  { // 0x4f89e7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f89e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f89e9: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  { // 0x4f89ee: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4f89ef: c3 RET
    finish(m,s,f,0u); return;
  }
  L004f89f0: { // 0x4f89f0: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x4f89f2: 743f JZ 0x004f8a33
    if(integer::condition("JZ",flags)) goto L004f8a33;
  }
  { // 0x4f89f4: a148e0a100 MOV EAX,[0x00a1e048]
    s.ax = m.r32((0x00a1e048u));
  }
  { // 0x4f89f9: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x4f89fb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4f89fd: 7e34 JLE 0x004f8a33
    if(integer::condition("JLE",flags)) goto L004f8a33;
  }
  L004f89ff: { // 0x4f89ff: a13ce0a100 MOV EAX,[0x00a1e03c]
    s.ax = m.r32((0x00a1e03cu));
  }
  { // 0x4f8a04: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4f8a05: 8b3498 MOV ESI,dword ptr [EAX + EBX*0x4]
    s.si = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  { // 0x4f8a08: 8d4e64 LEA ECX,[ESI + 0x64]
    s.cx = (s.si+0x00000064u);
  }
  { // 0x4f8a0b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4f8a0c: e84f4e2700 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x4f8a11: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4f8a14: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4f8a16: 7422 JZ 0x004f8a3a
    if(integer::condition("JZ",flags)) goto L004f8a3a;
  }
  { // 0x4f8a18: 8d5624 LEA EDX,[ESI + 0x24]
    s.dx = (s.si+0x00000024u);
  }
  { // 0x4f8a1b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4f8a1c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4f8a1d: e83e4e2700 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x4f8a22: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4f8a25: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4f8a27: 7411 JZ 0x004f8a3a
    if(integer::condition("JZ",flags)) goto L004f8a3a;
  }
  { // 0x4f8a29: a148e0a100 MOV EAX,[0x00a1e048]
    s.ax = m.r32((0x00a1e048u));
  }
  { // 0x4f8a2e: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x4f8a2f: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x4f8a31: 7ccc JL 0x004f89ff
    if(integer::condition("JL",flags)) goto L004f89ff;
  }
  L004f8a33: { // 0x4f8a33: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f8a34: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f8a35: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x4f8a38: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4f8a39: c3 RET
    finish(m,s,f,0u); return;
  }
  L004f8a3a: { // 0x4f8a3a: 8b86b8000000 MOV EAX,dword ptr [ESI + 0xb8]
    s.ax = m.r32((s.si+0x000000b8u));
  }
  { // 0x4f8a40: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f8a41: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f8a42: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4f8a43: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001094c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5094c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5094c1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5094c2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x5094c4: 685c8e7b00 PUSH 0x7b8e5c
    f.push(m,0x007b8e5cu);
  }
  { // 0x5094c9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5094ca: e891432600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5094cf: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5094d2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5094d4: 7440 JZ 0x00509516
    if(integer::condition("JZ",flags)) goto L00509516;
  }
  { // 0x5094d6: 687c907b00 PUSH 0x7b907c
    f.push(m,0x007b907cu);
  }
  { // 0x5094db: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5094dc: e87f432600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5094e1: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5094e4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5094e6: 742e JZ 0x00509516
    if(integer::condition("JZ",flags)) goto L00509516;
  }
  { // 0x5094e8: a1b07fa200 MOV EAX,[0x00a27fb0]
    s.ax = m.r32((0x00a27fb0u));
  }
  { // 0x5094ed: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x5094ef: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5094f1: 7e23 JLE 0x00509516
    if(integer::condition("JLE",flags)) goto L00509516;
  }
  L005094f3: { // 0x5094f3: a1a47fa200 MOV EAX,[0x00a27fa4]
    s.ax = m.r32((0x00a27fa4u));
  }
  { // 0x5094f8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5094f9: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x5094fc: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x5094ff: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x509500: e85b432600 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x509505: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x509508: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x50950a: 7410 JZ 0x0050951c
    if(integer::condition("JZ",flags)) goto L0050951c;
  }
  { // 0x50950c: a1b07fa200 MOV EAX,[0x00a27fb0]
    s.ax = m.r32((0x00a27fb0u));
  }
  { // 0x509511: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x509512: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x509514: 7cdd JL 0x005094f3
    if(integer::condition("JL",flags)) goto L005094f3;
  }
  L00509516: { // 0x509516: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x509517: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x50951a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x50951b: c3 RET
    finish(m,s,f,0u); return;
  }
  L0050951c: { // 0x50951c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x50951e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x50951f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x509520: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001189f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5189f0: a1a8a68100 MOV EAX,[0x0081a6a8]
    s.ax = m.r32((0x0081a6a8u));
  }
  { // 0x5189f5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5189f6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5189f7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5189f8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5189f9: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5189fb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5189fd: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  { // 0x5189ff: 7e5e JLE 0x00518a5f
    if(integer::condition("JLE",flags)) goto L00518a5f;
  }
  L00518a01: { // 0x518a01: a19ca68100 MOV EAX,[0x0081a69c]
    s.ax = m.r32((0x0081a69cu));
  }
  { // 0x518a06: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  { // 0x518a08: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x518a0b: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x518a0d: ff5204 CALL dword ptr [EDX + 0x4]
    const std::uint32_t call_target=m.r32((s.dx+0x00000004u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L00518a10: { // 0x518a10: 8a10 MOV DL,byte ptr [EAX]
    s.dx = with_al(s.dx, m.r8((s.ax)));
  }
  { // 0x518a12: 8a1e MOV BL,byte ptr [ESI]
    s.bx = with_al(s.bx, m.r8((s.si)));
  }
  { // 0x518a14: 8aca MOV CL,DL
    s.cx = with_al(s.cx, (s.dx & 0xffu));
  }
  { // 0x518a16: 3ad3 CMP DL,BL
    (void)integer::sub((s.dx & 0xffu),(s.bx & 0xffu),8,flags);
  }
  { // 0x518a18: 751e JNZ 0x00518a38
    if(integer::condition("JNZ",flags)) goto L00518a38;
  }
  { // 0x518a1a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x518a1c: 7416 JZ 0x00518a34
    if(integer::condition("JZ",flags)) goto L00518a34;
  }
  { // 0x518a1e: 8a5001 MOV DL,byte ptr [EAX + 0x1]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000001u)));
  }
  { // 0x518a21: 8a5e01 MOV BL,byte ptr [ESI + 0x1]
    s.bx = with_al(s.bx, m.r8((s.si+0x00000001u)));
  }
  { // 0x518a24: 8aca MOV CL,DL
    s.cx = with_al(s.cx, (s.dx & 0xffu));
  }
  { // 0x518a26: 3ad3 CMP DL,BL
    (void)integer::sub((s.dx & 0xffu),(s.bx & 0xffu),8,flags);
  }
  { // 0x518a28: 750e JNZ 0x00518a38
    if(integer::condition("JNZ",flags)) goto L00518a38;
  }
  { // 0x518a2a: 83c002 ADD EAX,0x2
    s.ax = integer::add(s.ax,0x00000002u,32,flags);
  }
  { // 0x518a2d: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  { // 0x518a30: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x518a32: 75dc JNZ 0x00518a10
    if(integer::condition("JNZ",flags)) goto L00518a10;
  }
  L00518a34: { // 0x518a34: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x518a36: eb05 JMP 0x00518a3d
    goto L00518a3d;
  }
  L00518a38: { // 0x518a38: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x518a3a: 83d8ff SBB EAX,-0x1
    s.ax = integer::sub(s.ax,0xffffffffu,32,flags,flags&integer::CF);
  }
  L00518a3d: { // 0x518a3d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x518a3f: 740f JZ 0x00518a50
    if(integer::condition("JZ",flags)) goto L00518a50;
  }
  { // 0x518a41: a1a8a68100 MOV EAX,[0x0081a6a8]
    s.ax = m.r32((0x0081a6a8u));
  }
  { // 0x518a46: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x518a47: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x518a49: 7cb6 JL 0x00518a01
    if(integer::condition("JL",flags)) goto L00518a01;
  }
  { // 0x518a4b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x518a4c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x518a4d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x518a4e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x518a4f: c3 RET
    finish(m,s,f,0u); return;
  }
  L00518a50: { // 0x518a50: a19ca68100 MOV EAX,[0x0081a69c]
    s.ax = m.r32((0x0081a69cu));
  }
  { // 0x518a55: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x518a57: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x518a5a: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x518a5c: ff5220 CALL dword ptr [EDX + 0x20]
    const std::uint32_t call_target=m.r32((s.dx+0x00000020u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00518a5f: { // 0x518a5f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x518a60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x518a61: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x518a62: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x518a63: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00120fb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x520fb0: a1d89ba300 MOV EAX,[0x00a39bd8]
    s.ax = m.r32((0x00a39bd8u));
  }
  { // 0x520fb5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x520fb6: 8d70ff LEA ESI,[EAX + -0x1]
    s.si = (s.ax-0x00000001u);
  }
  { // 0x520fb9: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x520fbb: 7c11 JL 0x00520fce
    if(integer::condition("JL",flags)) goto L00520fce;
  }
  L00520fbd: { // 0x520fbd: 8b0dcc9ba300 MOV ECX,dword ptr [0x00a39bcc]
    s.cx = m.r32((0x00a39bccu));
  }
  { // 0x520fc3: 8b0cb1 MOV ECX,dword ptr [ECX + ESI*0x4]
    s.cx = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  { // 0x520fc6: e8b5f8ffff CALL 0x00520880
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x520fcb: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x520fcc: 79ef JNS 0x00520fbd
    if(integer::condition("JNS",flags)) goto L00520fbd;
  }
  L00520fce: { // 0x520fce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x520fcf: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001223d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5223d0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5223d1: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x5223d5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5223d6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5223d7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5223d8: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  { // 0x5223dc: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  { // 0x5223de: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005223e0: { // 0x5223e0: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5223e2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5223e3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5223e4: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  { // 0x5223e6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5223e8: e823000000 CALL 0x00522410
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5223ed: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5223ef: 74ef JZ 0x005223e0
    if(integer::condition("JZ",flags)) goto L005223e0;
  }
  { // 0x5223f1: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x5223f4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5223f5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5223f6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5223f7: 83f912 CMP ECX,0x12
    (void)integer::sub(s.cx,0x00000012u,32,flags);
  }
  { // 0x5223fa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5223fb: 7502 JNZ 0x005223ff
    if(integer::condition("JNZ",flags)) goto L005223ff;
  }
  { // 0x5223fd: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005223ff: { // 0x5223ff: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00123990(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x523990: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x523991: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x523992: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x523994: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x523996: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  { // 0x523999: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  { // 0x52399c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x52399e: 7e26 JLE 0x005239c6
    if(integer::condition("JLE",flags)) goto L005239c6;
  }
  L005239a0: { // 0x5239a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5239a1: e88acbf5ff CALL 0x00480530
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5239a6: f60002 TEST byte ptr [EAX],0x2
    (void)integer::logical((m.r8((s.ax)))&(0x00000002u),8,flags);
  }
  { // 0x5239a9: 7412 JZ 0x005239bd
    if(integer::condition("JZ",flags)) goto L005239bd;
  }
  { // 0x5239ab: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  { // 0x5239ae: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5239b0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5239b2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5239b3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5239b5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5239b7: e824caf5ff CALL 0x004803e0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5239bc: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L005239bd: { // 0x5239bd: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  { // 0x5239c0: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x5239c1: 3b7138 CMP ESI,dword ptr [ECX + 0x38]
    (void)integer::sub(s.si,m.r32((s.cx+0x00000038u)),32,flags);
  }
  { // 0x5239c4: 7cda JL 0x005239a0
    if(integer::condition("JL",flags)) goto L005239a0;
  }
  L005239c6: { // 0x5239c6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5239c7: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x5239cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5239cd: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00124e60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x524e60: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x524e61: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x524e62: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x524e64: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x524e65: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  { // 0x524e67: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x524e69: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  { // 0x524e6c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x524e6e: 7e20 JLE 0x00524e90
    if(integer::condition("JLE",flags)) goto L00524e90;
  }
  { // 0x524e70: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x524e71: 8d5e28 LEA EBX,[ESI + 0x28]
    s.bx = (s.si+0x00000028u);
  }
  L00524e74: { // 0x524e74: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  { // 0x524e76: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x524e79: e852b7f5ff CALL 0x004805d0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x524e7e: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x524e80: 7602 JBE 0x00524e84
    if(integer::condition("JBE",flags)) goto L00524e84;
  }
  { // 0x524e82: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00524e84: { // 0x524e84: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  { // 0x524e87: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x524e88: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  { // 0x524e8b: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x524e8d: 7ce5 JL 0x00524e74
    if(integer::condition("JL",flags)) goto L00524e74;
  }
  { // 0x524e8f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00524e90: { // 0x524e90: 8b7650 MOV ESI,dword ptr [ESI + 0x50]
    s.si = m.r32((s.si+0x00000050u));
  }
  { // 0x524e93: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x524e95: 740c JZ 0x00524ea3
    if(integer::condition("JZ",flags)) goto L00524ea3;
  }
  { // 0x524e97: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x524e9a: e831b7f5ff CALL 0x004805d0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x524e9f: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x524ea1: 7702 JA 0x00524ea5
    if(integer::condition("JA",flags)) goto L00524ea5;
  }
  L00524ea3: { // 0x524ea3: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00524ea5: { // 0x524ea5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x524ea6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x524ea7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x524ea8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001258d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5258d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5258d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5258d3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5258d4: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x5258d6: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  { // 0x5258d9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5258db: 7e21 JLE 0x005258fe
    if(integer::condition("JLE",flags)) goto L005258fe;
  }
  { // 0x5258dd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5258de: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5258df: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  { // 0x5258e3: 8d5e28 LEA EBX,[ESI + 0x28]
    s.bx = (s.si+0x00000028u);
  }
  L005258e6: { // 0x5258e6: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  { // 0x5258e8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x5258e9: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x5258ec: e8ffacf5ff CALL 0x004805f0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5258f1: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  { // 0x5258f4: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x5258f5: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  { // 0x5258f8: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x5258fa: 7cea JL 0x005258e6
    if(integer::condition("JL",flags)) goto L005258e6;
  }
  { // 0x5258fc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5258fd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005258fe: { // 0x5258fe: 8b4648 MOV EAX,dword ptr [ESI + 0x48]
    s.ax = m.r32((s.si+0x00000048u));
  }
  { // 0x525901: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x525903: 740a JZ 0x0052590f
    if(integer::condition("JZ",flags)) goto L0052590f;
  }
  { // 0x525905: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x525908: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x52590a: e8e1acf5ff CALL 0x004805f0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0052590f: { // 0x52590f: 8b464c MOV EAX,dword ptr [ESI + 0x4c]
    s.ax = m.r32((s.si+0x0000004cu));
  }
  { // 0x525912: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x525914: 740a JZ 0x00525920
    if(integer::condition("JZ",flags)) goto L00525920;
  }
  { // 0x525916: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x525919: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x52591b: e8d0acf5ff CALL 0x004805f0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  L00525920: { // 0x525920: 8b7650 MOV ESI,dword ptr [ESI + 0x50]
    s.si = m.r32((s.si+0x00000050u));
  }
  { // 0x525923: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x525925: 740a JZ 0x00525931
    if(integer::condition("JZ",flags)) goto L00525931;
  }
  { // 0x525927: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x52592a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x52592c: e8bfacf5ff CALL 0x004805f0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00525931: { // 0x525931: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x525932: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x525933: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00127660(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x527660: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x527661: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x527662: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x527664: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x527666: 742e JZ 0x00527696
    if(integer::condition("JZ",flags)) goto L00527696;
  }
  { // 0x527668: a12089a200 MOV EAX,[0x00a28920]
    s.ax = m.r32((0x00a28920u));
  }
  { // 0x52766d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x52766f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x527671: 7e23 JLE 0x00527696
    if(integer::condition("JLE",flags)) goto L00527696;
  }
  L00527673: { // 0x527673: a11489a200 MOV EAX,[0x00a28914]
    s.ax = m.r32((0x00a28914u));
  }
  { // 0x527678: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x527679: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x52767c: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  { // 0x52767f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x527680: e8db612400 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x527685: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x527688: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x52768a: 7412 JZ 0x0052769e
    if(integer::condition("JZ",flags)) goto L0052769e;
  }
  { // 0x52768c: a12089a200 MOV EAX,[0x00a28920]
    s.ax = m.r32((0x00a28920u));
  }
  { // 0x527691: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x527692: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x527694: 7cdd JL 0x00527673
    if(integer::condition("JL",flags)) goto L00527673;
  }
  L00527696: { // 0x527696: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x527697: b8ffff0000 MOV EAX,0xffff
    s.ax = 0x0000ffffu;
  }
  { // 0x52769c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x52769d: c3 RET
    finish(m,s,f,0u); return;
  }
  L0052769e: { // 0x52769e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5276a0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5276a1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5276a2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0012fbe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x52fbe0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x52fbe1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x52fbe2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x52fbe3: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x52fbe5: 8b771c MOV ESI,dword ptr [EDI + 0x1c]
    s.si = m.r32((s.di+0x0000001cu));
  }
  { // 0x52fbe8: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x52fbe9: 7812 JS 0x0052fbfd
    if(integer::condition("JS",flags)) goto L0052fbfd;
  }
  L0052fbeb: { // 0x52fbeb: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x52fbee: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x52fbf1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x52fbf2: e884da2300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x52fbf7: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x52fbfa: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x52fbfb: 79ee JNS 0x0052fbeb
    if(integer::condition("JNS",flags)) goto L0052fbeb;
  }
  L0052fbfd: { // 0x52fbfd: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  { // 0x52fc00: 8d770c LEA ESI,[EDI + 0xc]
    s.si = (s.di+0x0000000cu);
  }
  { // 0x52fc03: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x52fc05: 8b7e08 MOV EDI,dword ptr [ESI + 0x8]
    s.di = m.r32((s.si+0x00000008u));
  }
  { // 0x52fc08: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x52fc0b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x52fc0d: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x52fc0f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x52fc10: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x52fc11: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x52fc13: ff5008 CALL dword ptr [EAX + 0x8]
    const std::uint32_t call_target=m.r32((s.ax+0x00000008u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x52fc16: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x52fc19: c706b4037900 MOV dword ptr [ESI],0x7903b4
    m.w32((s.si), 0x007903b4u);
  }
  { // 0x52fc1f: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x52fc21: 7411 JZ 0x0052fc34
    if(integer::condition("JZ",flags)) goto L0052fc34;
  }
  { // 0x52fc23: 385e0d CMP byte ptr [ESI + 0xd],BL
    (void)integer::sub(m.r8((s.si+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  { // 0x52fc26: 740c JZ 0x0052fc34
    if(integer::condition("JZ",flags)) goto L0052fc34;
  }
  { // 0x52fc28: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x52fc29: e84dda2300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x52fc2e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x52fc31: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L0052fc34: { // 0x52fc34: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  { // 0x52fc37: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  { // 0x52fc3a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x52fc3b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x52fc3c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x52fc3d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0012fc40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x52fc40: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x52fc43: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x52fc44: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x52fc45: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x52fc46: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x52fc48: 8b771c MOV ESI,dword ptr [EDI + 0x1c]
    s.si = m.r32((s.di+0x0000001cu));
  }
  { // 0x52fc4b: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x52fc4c: 7812 JS 0x0052fc60
    if(integer::condition("JS",flags)) goto L0052fc60;
  }
  L0052fc4e: { // 0x52fc4e: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  { // 0x52fc51: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x52fc54: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x52fc55: e821da2300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x52fc5a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x52fc5d: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x52fc5e: 79ee JNS 0x0052fc4e
    if(integer::condition("JNS",flags)) goto L0052fc4e;
  }
  L0052fc60: { // 0x52fc60: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  { // 0x52fc63: 8b5f14 MOV EBX,dword ptr [EDI + 0x14]
    s.bx = m.r32((s.di+0x00000014u));
  }
  { // 0x52fc66: 8d770c LEA ESI,[EDI + 0xc]
    s.si = (s.di+0x0000000cu);
  }
  { // 0x52fc69: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x52fc6b: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x52fc6e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x52fc70: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x52fc72: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x52fc73: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x52fc75: ff5008 CALL dword ptr [EAX + 0x8]
    const std::uint32_t call_target=m.r32((s.ax+0x00000008u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x52fc78: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  { // 0x52fc7d: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x52fc81: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  { // 0x52fc86: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  { // 0x52fc88: 895704 MOV dword ptr [EDI + 0x4],EDX
    m.w32((s.di+0x00000004u), s.dx);
  }
  { // 0x52fc8b: 894f08 MOV dword ptr [EDI + 0x8],ECX
    m.w32((s.di+0x00000008u), s.cx);
  }
  { // 0x52fc8e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x52fc8f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x52fc90: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x52fc91: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x52fc94: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0012fca0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x52fca0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x52fca1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x52fca2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x52fca3: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  { // 0x52fca7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x52fca8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x52fcaa: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x52fcac: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x52fcae: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  { // 0x52fcb2: 8b431c MOV EAX,dword ptr [EBX + 0x1c]
    s.ax = m.r32((s.bx+0x0000001cu));
  }
  { // 0x52fcb5: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x52fcb7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x52fcb8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x52fcb9: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x52fcbd: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x52fcc0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x52fcc2: 7c28 JL 0x0052fcec
    if(integer::condition("JL",flags)) goto L0052fcec;
  }
  { // 0x52fcc4: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x52fcc8: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x52fcca: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x52fccc: 7e1e JLE 0x0052fcec
    if(integer::condition("JLE",flags)) goto L0052fcec;
  }
  L0052fcce: { // 0x52fcce: 8b4b10 MOV ECX,dword ptr [EBX + 0x10]
    s.cx = m.r32((s.bx+0x00000010u));
  }
  { // 0x52fcd1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x52fcd3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x52fcd5: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x52fcd7: 8b14b9 MOV EDX,dword ptr [ECX + EDI*0x4]
    s.dx = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  { // 0x52fcda: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x52fcdb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x52fcdc: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x52fcdf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x52fce1: 7c09 JL 0x0052fcec
    if(integer::condition("JL",flags)) goto L0052fcec;
  }
  { // 0x52fce3: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x52fce7: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x52fce8: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x52fcea: 7ce2 JL 0x0052fcce
    if(integer::condition("JL",flags)) goto L0052fcce;
  }
  L0052fcec: { // 0x52fcec: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x52fced: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x52fcee: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x52fcef: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x52fcf0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00131510(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x531510: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x531511: a1d862a500 MOV EAX,[0x00a562d8]
    s.ax = m.r32((0x00a562d8u));
  }
  { // 0x531516: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x531518: 7468 JZ 0x00531582
    if(integer::condition("JZ",flags)) goto L00531582;
  }
  { // 0x53151a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0053151b: { // 0x53151b: a1cc62a500 MOV EAX,[0x00a562cc]
    s.ax = m.r32((0x00a562ccu));
  }
  { // 0x531520: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  { // 0x531522: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x531524: 7452 JZ 0x00531578
    if(integer::condition("JZ",flags)) goto L00531578;
  }
  { // 0x531526: 8b15c862a500 MOV EDX,dword ptr [0x00a562c8]
    s.dx = m.r32((0x00a562c8u));
  }
  { // 0x53152c: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x531530: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x531531: b9c862a500 MOV ECX,0xa562c8
    s.cx = 0x00a562c8u;
  }
  { // 0x531536: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  { // 0x53153a: ff5210 CALL dword ptr [EDX + 0x10]
    const std::uint32_t call_target=m.r32((s.dx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x53153d: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x531540: 742d JZ 0x0053156f
    if(integer::condition("JZ",flags)) goto L0053156f;
  }
  { // 0x531542: 8b0dd862a500 MOV ECX,dword ptr [0x00a562d8]
    s.cx = m.r32((0x00a562d8u));
  }
  { // 0x531548: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x53154a: 7d23 JGE 0x0053156f
    if(integer::condition("JGE",flags)) goto L0053156f;
  }
  { // 0x53154c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x53154d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x53154f: 890dd862a500 MOV dword ptr [0x00a562d8],ECX
    m.w32((0x00a562d8u), s.cx);
  }
  { // 0x531555: 7d18 JGE 0x0053156f
    if(integer::condition("JGE",flags)) goto L0053156f;
  }
  L00531557: { // 0x531557: 8b0dcc62a500 MOV ECX,dword ptr [0x00a562cc]
    s.cx = m.r32((0x00a562ccu));
  }
  { // 0x53155d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x53155e: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x531561: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  { // 0x531565: 8b0dd862a500 MOV ECX,dword ptr [0x00a562d8]
    s.cx = m.r32((0x00a562d8u));
  }
  { // 0x53156b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x53156d: 7ce8 JL 0x00531557
    if(integer::condition("JL",flags)) goto L00531557;
  }
  L0053156f: { // 0x53156f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x531570: e806c12300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x531575: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00531578: { // 0x531578: a1d862a500 MOV EAX,[0x00a562d8]
    s.ax = m.r32((0x00a562d8u));
  }
  { // 0x53157d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x53157f: 759a JNZ 0x0053151b
    if(integer::condition("JNZ",flags)) goto L0053151b;
  }
  { // 0x531581: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00531582: { // 0x531582: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x531583: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00131730(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x531730: a1d862a500 MOV EAX,[0x00a562d8]
    s.ax = m.r32((0x00a562d8u));
  }
  { // 0x531735: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x531736: 8d70ff LEA ESI,[EAX + -0x1]
    s.si = (s.ax-0x00000001u);
  }
  { // 0x531739: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x53173b: 7c11 JL 0x0053174e
    if(integer::condition("JL",flags)) goto L0053174e;
  }
  L0053173d: { // 0x53173d: 8b0dcc62a500 MOV ECX,dword ptr [0x00a562cc]
    s.cx = m.r32((0x00a562ccu));
  }
  { // 0x531743: 8b0cb1 MOV ECX,dword ptr [ECX + ESI*0x4]
    s.cx = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  { // 0x531746: e805000000 CALL 0x00531750
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x53174b: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x53174c: 79ef JNS 0x0053173d
    if(integer::condition("JNS",flags)) goto L0053173d;
  }
  L0053174e: { // 0x53174e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53174f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00132b80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x532b80: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x532b81: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x532b82: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x532b83: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  { // 0x532b85: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x532b87: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  { // 0x532b8a: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x532b8b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x532b8d: 7e42 JLE 0x00532bd1
    if(integer::condition("JLE",flags)) goto L00532bd1;
  }
  { // 0x532b8f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x532b90: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00532b91: { // 0x532b91: 8b4504 MOV EAX,dword ptr [EBP + 0x4]
    s.ax = m.r32((s.bp+0x00000004u));
  }
  { // 0x532b94: 8b749804 MOV ESI,dword ptr [EAX + EBX*0x4 + 0x4]
    s.si = m.r32((s.ax+(s.bx * 0x00000004u)+0x00000004u));
  }
  { // 0x532b98: 8b3c98 MOV EDI,dword ptr [EAX + EBX*0x4]
    s.di = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  { // 0x532b9b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x532b9d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x532b9f: ff92b4000000 CALL dword ptr [EDX + 0xb4]
    const std::uint32_t call_target=m.r32((s.dx+0x000000b4u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x532ba5: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  { // 0x532ba9: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x532bab: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x532bad: ff90b4000000 CALL dword ptr [EAX + 0xb4]
    const std::uint32_t call_target=m.r32((s.ax+0x000000b4u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x532bb3: 39442410 CMP dword ptr [ESP + 0x10],EAX
    (void)integer::sub(m.r32((f.sp+0x00000010u)),s.ax,32,flags);
  }
  { // 0x532bb7: 7d0d JGE 0x00532bc6
    if(integer::condition("JGE",flags)) goto L00532bc6;
  }
  { // 0x532bb9: 8b4d04 MOV ECX,dword ptr [EBP + 0x4]
    s.cx = m.r32((s.bp+0x00000004u));
  }
  { // 0x532bbc: 897c9904 MOV dword ptr [ECX + EBX*0x4 + 0x4],EDI
    m.w32((s.cx+(s.bx * 0x00000004u)+0x00000004u), s.di);
  }
  { // 0x532bc0: 8b5504 MOV EDX,dword ptr [EBP + 0x4]
    s.dx = m.r32((s.bp+0x00000004u));
  }
  { // 0x532bc3: 89349a MOV dword ptr [EDX + EBX*0x4],ESI
    m.w32((s.dx+(s.bx * 0x00000004u)), s.si);
  }
  L00532bc6: { // 0x532bc6: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  { // 0x532bc9: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x532bca: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x532bcb: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x532bcd: 7cc2 JL 0x00532b91
    if(integer::condition("JL",flags)) goto L00532b91;
  }
  { // 0x532bcf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x532bd0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00532bd1: { // 0x532bd1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x532bd2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x532bd3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x532bd4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00132c70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x532c70: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x532c71: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x532c72: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x532c76: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x532c77: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x532c79: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x532c7b: 750b JNZ 0x00532c88
    if(integer::condition("JNZ",flags)) goto L00532c88;
  }
  { // 0x532c7d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x532c7e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x532c7f: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  { // 0x532c84: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x532c85: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00532c88: { // 0x532c88: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x532c8b: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x532c8d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x532c8f: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x532c93: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x532c95: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x532c96: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x532c97: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  { // 0x532c9b: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x532c9e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x532ca0: 7c2a JL 0x00532ccc
    if(integer::condition("JL",flags)) goto L00532ccc;
  }
  { // 0x532ca2: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x532ca6: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x532ca8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x532caa: 7e1e JLE 0x00532cca
    if(integer::condition("JLE",flags)) goto L00532cca;
  }
  L00532cac: { // 0x532cac: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  { // 0x532caf: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x532cb1: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x532cb3: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x532cb5: 8d14b9 LEA EDX,[ECX + EDI*0x4]
    s.dx = (s.cx+(s.di * 0x00000004u));
  }
  { // 0x532cb8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x532cb9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x532cba: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x532cbd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x532cbf: 7c0b JL 0x00532ccc
    if(integer::condition("JL",flags)) goto L00532ccc;
  }
  { // 0x532cc1: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x532cc5: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x532cc6: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x532cc8: 7ce2 JL 0x00532cac
    if(integer::condition("JL",flags)) goto L00532cac;
  }
  L00532cca: { // 0x532cca: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00532ccc: { // 0x532ccc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x532ccd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x532cce: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x532ccf: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00138bb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x538bb0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x538bb1: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x538bb5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x538bb6: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x538bb7: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x538bb9: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x538bbb: 743a JZ 0x00538bf7
    if(integer::condition("JZ",flags)) goto L00538bf7;
  }
  { // 0x538bbd: 8b4744 MOV EAX,dword ptr [EDI + 0x44]
    s.ax = m.r32((s.di+0x00000044u));
  }
  { // 0x538bc0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x538bc2: 7e33 JLE 0x00538bf7
    if(integer::condition("JLE",flags)) goto L00538bf7;
  }
  { // 0x538bc4: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x538bc6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x538bc8: 7e2d JLE 0x00538bf7
    if(integer::condition("JLE",flags)) goto L00538bf7;
  }
  L00538bca: { // 0x538bca: 8b4738 MOV EAX,dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  { // 0x538bcd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x538bce: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x538bd1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x538bd2: e871902400 CALL 0x00781c48
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x538bd7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x538bda: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x538bdc: 740e JZ 0x00538bec
    if(integer::condition("JZ",flags)) goto L00538bec;
  }
  { // 0x538bde: 8b4744 MOV EAX,dword ptr [EDI + 0x44]
    s.ax = m.r32((s.di+0x00000044u));
  }
  { // 0x538be1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x538be2: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x538be4: 7ce4 JL 0x00538bca
    if(integer::condition("JL",flags)) goto L00538bca;
  }
  { // 0x538be6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x538be7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x538be8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x538be9: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00538bec: { // 0x538bec: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  { // 0x538bee: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x538bef: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x538bf1: ff92b8000000 CALL dword ptr [EDX + 0xb8]
    const std::uint32_t call_target=m.r32((s.dx+0x000000b8u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00538bf7: { // 0x538bf7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x538bf8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x538bf9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x538bfa: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00139310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x539310: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x539311: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x539312: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x539314: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x539315: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x539317: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x539319: c706fc077900 MOV dword ptr [ESI],0x7907fc
    m.w32((s.si), 0x007907fcu);
  }
  { // 0x53931f: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  { // 0x539322: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x539324: 7e17 JLE 0x0053933d
    if(integer::condition("JLE",flags)) goto L0053933d;
  }
  L00539326: { // 0x539326: 8b4624 MOV EAX,dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  { // 0x539329: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x53932c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x53932d: e849432300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x539332: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  { // 0x539335: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x539338: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x539339: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x53933b: 7ce9 JL 0x00539326
    if(integer::condition("JL",flags)) goto L00539326;
  }
  L0053933d: { // 0x53933d: 8b5620 MOV EDX,dword ptr [ESI + 0x20]
    s.dx = m.r32((s.si+0x00000020u));
  }
  { // 0x539340: 83c620 ADD ESI,0x20
    s.si = integer::add(s.si,0x00000020u,32,flags);
  }
  { // 0x539343: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x539345: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x539348: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x53934b: c70644087900 MOV dword ptr [ESI],0x790844
    m.w32((s.si), 0x00790844u);
  }
  { // 0x539351: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x539353: 7411 JZ 0x00539366
    if(integer::condition("JZ",flags)) goto L00539366;
  }
  { // 0x539355: 385e0d CMP byte ptr [ESI + 0xd],BL
    (void)integer::sub(m.r8((s.si+0x0000000du)),(s.bx & 0xffu),8,flags);
  }
  { // 0x539358: 740c JZ 0x00539366
    if(integer::condition("JZ",flags)) goto L00539366;
  }
  { // 0x53935a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x53935b: e81b432300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x539360: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x539363: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00539366: { // 0x539366: 885e0d MOV byte ptr [ESI + 0xd],BL
    m.w8((s.si+0x0000000du), (s.bx & 0xffu));
  }
  { // 0x539369: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  { // 0x53936c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x53936d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53936e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x53936f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0013a1f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x53a1f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53a1f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x53a1f3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x53a1f4: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x53a1f6: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  { // 0x53a1f9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x53a1fb: 7e17 JLE 0x0053a214
    if(integer::condition("JLE",flags)) goto L0053a214;
  }
  L0053a1fd: { // 0x53a1fd: 8b4624 MOV EAX,dword ptr [ESI + 0x24]
    s.ax = m.r32((s.si+0x00000024u));
  }
  { // 0x53a200: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  { // 0x53a203: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x53a204: e872342300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x53a209: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  { // 0x53a20c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x53a20f: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x53a210: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x53a212: 7ce9 JL 0x0053a1fd
    if(integer::condition("JL",flags)) goto L0053a1fd;
  }
  L0053a214: { // 0x53a214: 8b5620 MOV EDX,dword ptr [ESI + 0x20]
    s.dx = m.r32((s.si+0x00000020u));
  }
  { // 0x53a217: 8d4e20 LEA ECX,[ESI + 0x20]
    s.cx = (s.si+0x00000020u);
  }
  { // 0x53a21a: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x53a21d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x53a21e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53a21f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0013abd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x53abd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53abd1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x53abd2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x53abd4: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x53abd6: c707fc077900 MOV dword ptr [EDI],0x7907fc
    m.w32((s.di), 0x007907fcu);
  }
  { // 0x53abdc: 8b4730 MOV EAX,dword ptr [EDI + 0x30]
    s.ax = m.r32((s.di+0x00000030u));
  }
  { // 0x53abdf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x53abe1: 7e17 JLE 0x0053abfa
    if(integer::condition("JLE",flags)) goto L0053abfa;
  }
  L0053abe3: { // 0x53abe3: 8b4724 MOV EAX,dword ptr [EDI + 0x24]
    s.ax = m.r32((s.di+0x00000024u));
  }
  { // 0x53abe6: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x53abe9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x53abea: e88c2a2300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x53abef: 8b4730 MOV EAX,dword ptr [EDI + 0x30]
    s.ax = m.r32((s.di+0x00000030u));
  }
  { // 0x53abf2: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x53abf5: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x53abf6: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x53abf8: 7ce9 JL 0x0053abe3
    if(integer::condition("JL",flags)) goto L0053abe3;
  }
  L0053abfa: { // 0x53abfa: 8b5720 MOV EDX,dword ptr [EDI + 0x20]
    s.dx = m.r32((s.di+0x00000020u));
  }
  { // 0x53abfd: 8d7720 LEA ESI,[EDI + 0x20]
    s.si = (s.di+0x00000020u);
  }
  { // 0x53ac00: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x53ac02: ff520c CALL dword ptr [EDX + 0xc]
    const std::uint32_t call_target=m.r32((s.dx+0x0000000cu));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x53ac05: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x53ac08: c70644087900 MOV dword ptr [ESI],0x790844
    m.w32((s.si), 0x00790844u);
  }
  { // 0x53ac0e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x53ac10: 7417 JZ 0x0053ac29
    if(integer::condition("JZ",flags)) goto L0053ac29;
  }
  { // 0x53ac12: 8a4e0d MOV CL,byte ptr [ESI + 0xd]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000000du)));
  }
  { // 0x53ac15: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x53ac17: 7410 JZ 0x0053ac29
    if(integer::condition("JZ",flags)) goto L0053ac29;
  }
  { // 0x53ac19: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x53ac1a: e85c2a2300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x53ac1f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x53ac22: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L0053ac29: { // 0x53ac29: 8a44240c MOV AL,byte ptr [ESP + 0xc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000cu)));
  }
  { // 0x53ac2d: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  { // 0x53ac31: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x53ac33: c7460800000000 MOV dword ptr [ESI + 0x8],0x0
    m.w32((s.si+0x00000008u), 0x00000000u);
  }
  { // 0x53ac3a: 7409 JZ 0x0053ac45
    if(integer::condition("JZ",flags)) goto L0053ac45;
  }
  { // 0x53ac3c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x53ac3d: e8392a2300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x53ac42: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0053ac45: { // 0x53ac45: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x53ac47: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x53ac48: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53ac49: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00145920(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x545920: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x545921: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x545922: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x545923: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x545924: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  { // 0x545926: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x545928: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x54592a: 89bd30010000 MOV dword ptr [EBP + 0x130],EDI
    m.w32((s.bp+0x00000130u), s.di);
  }
  L00545930: { // 0x545930: bb00020000 MOV EBX,0x200
    s.bx = 0x00000200u;
  }
  L00545935: { // 0x545935: 3bbd3c010000 CMP EDI,dword ptr [EBP + 0x13c]
    (void)integer::sub(s.di,m.r32((s.bp+0x0000013cu)),32,flags);
  }
  { // 0x54593b: 7d12 JGE 0x0054594f
    if(integer::condition("JGE",flags)) goto L0054594f;
  }
  { // 0x54593d: 8b8538010000 MOV EAX,dword ptr [EBP + 0x138]
    s.ax = m.r32((s.bp+0x00000138u));
  }
  { // 0x545943: 8b0c30 MOV ECX,dword ptr [EAX + ESI*0x1]
    s.cx = m.r32((s.ax+(s.si * 0x00000001u)));
  }
  { // 0x545946: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x545948: 7405 JZ 0x0054594f
    if(integer::condition("JZ",flags)) goto L0054594f;
  }
  { // 0x54594a: e8c1b1f2ff CALL 0x00470b10
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0054594f: { // 0x54594f: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x545952: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x545953: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x545954: 75df JNZ 0x00545935
    if(integer::condition("JNZ",flags)) goto L00545935;
  }
  { // 0x545956: 81ff00000400 CMP EDI,0x40000
    (void)integer::sub(s.di,0x00040000u,32,flags);
  }
  { // 0x54595c: 7cd2 JL 0x00545930
    if(integer::condition("JL",flags)) goto L00545930;
  }
  { // 0x54595e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x54595f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x545960: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x545961: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x545962: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0014b790(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x54b790: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  { // 0x54b795: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x54b796: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x54b798: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x54b79a: 7461 JZ 0x0054b7fd
    if(integer::condition("JZ",flags)) goto L0054b7fd;
  }
  { // 0x54b79c: a0f155a200 MOV AL,[0x00a255f1]
    s.ax = with_al(s.ax, m.r8((0x00a255f1u)));
  }
  { // 0x54b7a1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x54b7a3: 7458 JZ 0x0054b7fd
    if(integer::condition("JZ",flags)) goto L0054b7fd;
  }
  { // 0x54b7a5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x54b7a6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x54b7a7: 8db754010000 LEA ESI,[EDI + 0x154]
    s.si = (s.di+0x00000154u);
  }
  { // 0x54b7ad: bb00010000 MOV EBX,0x100
    s.bx = 0x00000100u;
  }
  L0054b7b2: { // 0x54b7b2: 668b460c MOV AX,word ptr [ESI + 0xc]
    s.ax = with_ax(s.ax, m.r16((s.si+0x0000000cu)));
  }
  { // 0x54b7b6: 663b055c6ea500 CMP AX,word ptr [0x00a56e5c]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x00a56e5cu)),16,flags);
  }
  { // 0x54b7bd: 750d JNZ 0x0054b7cc
    if(integer::condition("JNZ",flags)) goto L0054b7cc;
  }
  { // 0x54b7bf: 668b4e0e MOV CX,word ptr [ESI + 0xe]
    s.cx = with_ax(s.cx, m.r16((s.si+0x0000000eu)));
  }
  { // 0x54b7c3: 663b0d5e6ea500 CMP CX,word ptr [0x00a56e5e]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00a56e5eu)),16,flags);
  }
  { // 0x54b7ca: 7429 JZ 0x0054b7f5
    if(integer::condition("JZ",flags)) goto L0054b7f5;
  }
  L0054b7cc: { // 0x54b7cc: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x54b7ce: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x54b7d1: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  { // 0x54b7d4: 740d JZ 0x0054b7e3
    if(integer::condition("JZ",flags)) goto L0054b7e3;
  }
  { // 0x54b7d6: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  { // 0x54b7db: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x54b7dd: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x54b7df: 7d06 JGE 0x0054b7e7
    if(integer::condition("JGE",flags)) goto L0054b7e7;
  }
  { // 0x54b7e1: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0054b7e3: { // 0x54b7e3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x54b7e5: 750e JNZ 0x0054b7f5
    if(integer::condition("JNZ",flags)) goto L0054b7f5;
  }
  L0054b7e7: { // 0x54b7e7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x54b7e9: e8227ff4ff CALL 0x00493710
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x54b7ee: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x54b7f0: e8ab000000 CALL 0x0054b8a0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0054b7f5: { // 0x54b7f5: 83c610 ADD ESI,0x10
    s.si = integer::add(s.si,0x00000010u,32,flags);
  }
  { // 0x54b7f8: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x54b7f9: 75b7 JNZ 0x0054b7b2
    if(integer::condition("JNZ",flags)) goto L0054b7b2;
  }
  { // 0x54b7fb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x54b7fc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054b7fd: { // 0x54b7fd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x54b7fe: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00160b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x560b30: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x560b31: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x560b33: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x560b34: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x560b35: be02000000 MOV ESI,0x2
    s.si = 0x00000002u;
  }
  { // 0x560b3a: 8dbbb8000000 LEA EDI,[EBX + 0xb8]
    s.di = (s.bx+0x000000b8u);
  }
  L00560b40: { // 0x560b40: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x560b42: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x560b44: ff500c CALL dword ptr [EAX + 0xc]
    const std::uint32_t call_target=m.r32((s.ax+0x0000000cu));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x560b47: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x560b48: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x560b4a: e821000000 CALL 0x00560b70
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x560b4f: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x560b50: 83ef18 SUB EDI,0x18
    s.di = integer::sub(s.di,0x00000018u,32,flags);
  }
  { // 0x560b53: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x560b55: 7de9 JGE 0x00560b40
    if(integer::condition("JGE",flags)) goto L00560b40;
  }
  { // 0x560b57: b908998100 MOV ECX,0x819908
    s.cx = 0x00819908u;
  }
  { // 0x560b5c: e82f8fecff CALL 0x00429a90
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x560b61: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x560b62: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x560b63: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x560b64: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00161910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x561910: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x561911: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x561912: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x561914: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x561916: 8b465c MOV EAX,dword ptr [ESI + 0x5c]
    s.ax = m.r32((s.si+0x0000005cu));
  }
  { // 0x561919: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x56191b: 7e2c JLE 0x00561949
    if(integer::condition("JLE",flags)) goto L00561949;
  }
  { // 0x56191d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x56191e: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  { // 0x561922: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x561923: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00561925: { // 0x561925: 8b5650 MOV EDX,dword ptr [ESI + 0x50]
    s.dx = m.r32((s.si+0x00000050u));
  }
  { // 0x561928: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x56192a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x56192c: 8a4808 MOV CL,byte ptr [EAX + 0x8]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000008u)));
  }
  { // 0x56192f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x561931: 7409 JZ 0x0056193c
    if(integer::condition("JZ",flags)) goto L0056193c;
  }
  { // 0x561933: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x561934: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x561935: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x561937: e814000000 CALL 0x00561950
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0056193c: { // 0x56193c: 8b465c MOV EAX,dword ptr [ESI + 0x5c]
    s.ax = m.r32((s.si+0x0000005cu));
  }
  { // 0x56193f: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x561940: 83c710 ADD EDI,0x10
    s.di = integer::add(s.di,0x00000010u,32,flags);
  }
  { // 0x561943: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x561945: 7cde JL 0x00561925
    if(integer::condition("JL",flags)) goto L00561925;
  }
  { // 0x561947: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x561948: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00561949: { // 0x561949: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x56194a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x56194b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001653e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5653e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5653e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5653e3: 8b86f0000000 MOV EAX,dword ptr [ESI + 0xf0]
    s.ax = m.r32((s.si+0x000000f0u));
  }
  { // 0x5653e9: c7860801000001000000 MOV dword ptr [ESI + 0x108],0x1
    m.w32((s.si+0x00000108u), 0x00000001u);
  }
  { // 0x5653f3: 89860c010000 MOV dword ptr [ESI + 0x10c],EAX
    m.w32((s.si+0x0000010cu), s.ax);
  }
  { // 0x5653f9: 8d48ff LEA ECX,[EAX + -0x1]
    s.cx = (s.ax-0x00000001u);
  }
  { // 0x5653fc: 898e10010000 MOV dword ptr [ESI + 0x110],ECX
    m.w32((s.si+0x00000110u), s.cx);
  }
  { // 0x565402: 8b9638010000 MOV EDX,dword ptr [ESI + 0x138]
    s.dx = m.r32((s.si+0x00000138u));
  }
  { // 0x565408: c1e00b SHL EAX,0xb
    s.ax = integer::shift(s.ax,0x0000000bu,32,flags,integer::Shift::left);
  }
  { // 0x56540b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x56540d: 8d441004 LEA EAX,[EAX + EDX*0x1 + 0x4]
    s.ax = (s.ax+(s.dx * 0x00000001u)+0x00000004u);
  }
  { // 0x565411: 898614010000 MOV dword ptr [ESI + 0x114],EAX
    m.w32((s.si+0x00000114u), s.ax);
  }
  { // 0x565417: e8641effff CALL 0x00557280
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x56541c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x56541e: 741b JZ 0x0056543b
    if(integer::condition("JZ",flags)) goto L0056543b;
  }
  L00565420: { // 0x565420: f6804001000002 TEST byte ptr [EAX + 0x140],0x2
    (void)integer::logical((m.r8((s.ax+0x00000140u)))&(0x00000002u),8,flags);
  }
  { // 0x565427: 7507 JNZ 0x00565430
    if(integer::condition("JNZ",flags)) goto L00565430;
  }
  { // 0x565429: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x56542b: e85064f1ff CALL 0x0047b880
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00565430: { // 0x565430: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x565432: e8491effff CALL 0x00557280
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x565437: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x565439: 75e5 JNZ 0x00565420
    if(integer::condition("JNZ",flags)) goto L00565420;
  }
  L0056543b: { // 0x56543b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x56543c: c3 RET
    finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,119>& entries_a() {
  static const std::array<Entry,119> entries{{
    {0x2ef0u,f_00002ef0},
    {0x3530u,f_00003530},
    {0x36f0u,f_000036f0},
    {0x3730u,f_00003730},
    {0x3770u,f_00003770},
    {0x37c0u,f_000037c0},
    {0x4d60u,f_00004d60},
    {0x4e00u,f_00004e00},
    {0x4fb0u,f_00004fb0},
    {0x5020u,f_00005020},
    {0x67e0u,f_000067e0},
    {0x6830u,f_00006830},
    {0x6880u,f_00006880},
    {0x6fe0u,f_00006fe0},
    {0x8010u,f_00008010},
    {0x80c0u,f_000080c0},
    {0x8120u,f_00008120},
    {0x8150u,f_00008150},
    {0x8190u,f_00008190},
    {0x82b0u,f_000082b0},
    {0x82f0u,f_000082f0},
    {0x8330u,f_00008330},
    {0xdb90u,f_0000db90},
    {0x125d0u,f_000125d0},
    {0x12720u,f_00012720},
    {0x13540u,f_00013540},
    {0x13590u,f_00013590},
    {0x1b890u,f_0001b890},
    {0x1be60u,f_0001be60},
    {0x20cd0u,f_00020cd0},
    {0x25640u,f_00025640},
    {0x26890u,f_00026890},
    {0x2c9f0u,f_0002c9f0},
    {0x37a40u,f_00037a40},
    {0x37ab0u,f_00037ab0},
    {0x37af0u,f_00037af0},
    {0x37bb0u,f_00037bb0},
    {0x4af00u,f_0004af00},
    {0x4ccc0u,f_0004ccc0},
    {0x4cd60u,f_0004cd60},
    {0x4d670u,f_0004d670},
    {0x4dc30u,f_0004dc30},
    {0x4f730u,f_0004f730},
    {0x514e0u,f_000514e0},
    {0x57700u,f_00057700},
    {0x58000u,f_00058000},
    {0x58050u,f_00058050},
    {0x5e840u,f_0005e840},
    {0x651b0u,f_000651b0},
    {0x68b00u,f_00068b00},
    {0x69980u,f_00069980},
    {0x69a20u,f_00069a20},
    {0x69e80u,f_00069e80},
    {0x69f20u,f_00069f20},
    {0x69fc0u,f_00069fc0},
    {0x6a1b0u,f_0006a1b0},
    {0x6a340u,f_0006a340},
    {0x6fd00u,f_0006fd00},
    {0x71430u,f_00071430},
    {0x76720u,f_00076720},
    {0x7ba00u,f_0007ba00},
    {0x7cf30u,f_0007cf30},
    {0x7cfe0u,f_0007cfe0},
    {0x7d050u,f_0007d050},
    {0x7d340u,f_0007d340},
    {0x817a0u,f_000817a0},
    {0x82850u,f_00082850},
    {0x828b0u,f_000828b0},
    {0x82b40u,f_00082b40},
    {0x82c00u,f_00082c00},
    {0x82c50u,f_00082c50},
    {0x82cc0u,f_00082cc0},
    {0x82d20u,f_00082d20},
    {0x90280u,f_00090280},
    {0x90be0u,f_00090be0},
    {0x91b90u,f_00091b90},
    {0x92430u,f_00092430},
    {0x92d90u,f_00092d90},
    {0x96800u,f_00096800},
    {0x989c0u,f_000989c0},
    {0x9e2a0u,f_0009e2a0},
    {0x9e310u,f_0009e310},
    {0x9e540u,f_0009e540},
    {0x9e570u,f_0009e570},
    {0xa67f0u,f_000a67f0},
    {0xa6820u,f_000a6820},
    {0xced90u,f_000ced90},
    {0xcee40u,f_000cee40},
    {0xd1030u,f_000d1030},
    {0xd1a80u,f_000d1a80},
    {0xdd5b0u,f_000dd5b0},
    {0xebeb0u,f_000ebeb0},
    {0xf25d0u,f_000f25d0},
    {0xf57b0u,f_000f57b0},
    {0xf89d0u,f_000f89d0},
    {0x1094c0u,f_001094c0},
    {0x1189f0u,f_001189f0},
    {0x120fb0u,f_00120fb0},
    {0x1223d0u,f_001223d0},
    {0x123990u,f_00123990},
    {0x124e60u,f_00124e60},
    {0x1258d0u,f_001258d0},
    {0x127660u,f_00127660},
    {0x12fbe0u,f_0012fbe0},
    {0x12fc40u,f_0012fc40},
    {0x12fca0u,f_0012fca0},
    {0x131510u,f_00131510},
    {0x131730u,f_00131730},
    {0x132b80u,f_00132b80},
    {0x132c70u,f_00132c70},
    {0x138bb0u,f_00138bb0},
    {0x139310u,f_00139310},
    {0x13a1f0u,f_0013a1f0},
    {0x13abd0u,f_0013abd0},
    {0x145920u,f_00145920},
    {0x14b790u,f_0014b790},
    {0x160b30u,f_00160b30},
    {0x161910u,f_00161910},
    {0x1653e0u,f_001653e0},
  }}; return entries;
}
} // namespace ra2::recovered::loops_b36
