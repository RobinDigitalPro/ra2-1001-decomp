#include "recovered/direct_b34_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::direct_b34 {
namespace {
void f_00303f20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x703f20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x703f21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x703f23: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x703f24: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x703f28: 3b3e CMP EDI,dword ptr [ESI]
    (void)integer::sub(s.di,m.r32((s.si)),32,flags);
  }
  { // 0x703f2a: 7203 JC 0x00703f2f
    if(integer::condition("JC",flags)) goto L00703f2f;
  }
  { // 0x703f2c: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L00703f2f: { // 0x703f2f: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  { // 0x703f32: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  { // 0x703f34: 7428 JZ 0x00703f5e
    if(integer::condition("JZ",flags)) goto L00703f5e;
  }
  { // 0x703f36: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  { // 0x703f39: 740e JZ 0x00703f49
    if(integer::condition("JZ",flags)) goto L00703f49;
  }
  { // 0x703f3b: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x703f3e: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x703f40: 8a4604 MOV AL,byte ptr [ESI + 0x4]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000004u)));
  }
  { // 0x703f43: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x703f44: e85791e2ff CALL 0x0052d0a0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  L00703f49: { // 0x703f49: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  { // 0x703f4c: 740d JZ 0x00703f5b
    if(integer::condition("JZ",flags)) goto L00703f5b;
  }
  { // 0x703f4e: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  { // 0x703f51: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  { // 0x703f53: e89891e2ff CALL 0x0052d0f0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x703f58: 884604 MOV byte ptr [ESI + 0x4],AL
    m.w8((s.si+0x00000004u), (s.ax & 0xffu));
  }
  L00703f5b: { // 0x703f5b: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L00703f5e: { // 0x703f5e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x703f5f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x703f60: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00305400(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x705400: 8d0449 LEA EAX,[ECX + ECX*0x2]
    s.ax = (s.cx+(s.cx * 0x00000002u));
  }
  { // 0x705403: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x705406: 8d0c81 LEA ECX,[ECX + EAX*0x4]
    s.cx = (s.cx+(s.ax * 0x00000004u));
  }
  { // 0x705409: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x70540d: 8d14cdac5b7800 LEA EDX,[ECX*0x8 + 0x785bac]
    s.dx = ((s.cx * 0x00000008u)+0x00785bacu);
  }
  { // 0x705414: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x705415: 68402f7e00 PUSH 0x7e2f40
    f.push(m,0x007e2f40u);
  }
  { // 0x70541a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x70541b: e814860600 CALL 0x0076da34
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x705420: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x705423: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x705427: e894d0e8ff CALL 0x005924c0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x70542c: a31c82ab00 MOV [0x00ab821c],EAX
    m.w32((0x00ab821cu), s.ax);
  }
  { // 0x705431: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x705434: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030a340(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70a340: e82b000000 CALL 0x0070a370
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x70a345: 8b0ddc83ab00 MOV ECX,dword ptr [0x00ab83dc]
    s.cx = m.r32((0x00ab83dcu));
  }
  { // 0x70a34b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x70a34d: 741a JZ 0x0070a369
    if(integer::condition("JZ",flags)) goto L0070a369;
  }
  { // 0x70a34f: e80cdbcfff CALL 0x00407e60
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x70a354: 8b0ddc83ab00 MOV ECX,dword ptr [0x00ab83dc]
    s.cx = m.r32((0x00ab83dcu));
  }
  { // 0x70a35a: e861d6cfff CALL 0x004079c0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x70a35f: c705dc83ab0000000000 MOV dword ptr [0x00ab83dc],0x0
    m.w32((0x00ab83dcu), 0x00000000u);
  }
  L0070a369: { // 0x70a369: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030a9e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70a9e0: e87bfdffff CALL 0x0070a760
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x70a9e5: 8b0ddc83ab00 MOV ECX,dword ptr [0x00ab83dc]
    s.cx = m.r32((0x00ab83dcu));
  }
  { // 0x70a9eb: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x70a9ed: 743e JZ 0x0070aa2d
    if(integer::condition("JZ",flags)) goto L0070aa2d;
  }
  { // 0x70a9ef: e89cd5cfff CALL 0x00407f90
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x70a9f4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70a9f6: 7538 JNZ 0x0070aa30
    if(integer::condition("JNZ",flags)) goto L0070aa30;
  }
  { // 0x70a9f8: 813dec82ab00e882ab00 CMP dword ptr [0x00ab82ec],0xab82e8
    (void)integer::sub(m.r32((0x00ab82ecu)),0x00ab82e8u,32,flags);
  }
  { // 0x70aa02: 752c JNZ 0x0070aa30
    if(integer::condition("JNZ",flags)) goto L0070aa30;
  }
  { // 0x70aa04: 813d1483ab001083ab00 CMP dword ptr [0x00ab8314],0xab8310
    (void)integer::sub(m.r32((0x00ab8314u)),0x00ab8310u,32,flags);
  }
  { // 0x70aa0e: 7520 JNZ 0x0070aa30
    if(integer::condition("JNZ",flags)) goto L0070aa30;
  }
  { // 0x70aa10: a1c883ab00 MOV EAX,[0x00ab83c8]
    s.ax = m.r32((0x00ab83c8u));
  }
  { // 0x70aa15: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70aa17: 7517 JNZ 0x0070aa30
    if(integer::condition("JNZ",flags)) goto L0070aa30;
  }
  { // 0x70aa19: b86083ab00 MOV EAX,0xab8360
    s.ax = 0x00ab8360u;
  }
  L0070aa1e: { // 0x70aa1e: 394004 CMP dword ptr [EAX + 0x4],EAX
    (void)integer::sub(m.r32((s.ax+0x00000004u)),s.ax,32,flags);
  }
  { // 0x70aa21: 750d JNZ 0x0070aa30
    if(integer::condition("JNZ",flags)) goto L0070aa30;
  }
  { // 0x70aa23: 83c00c ADD EAX,0xc
    s.ax = integer::add(s.ax,0x0000000cu,32,flags);
  }
  { // 0x70aa26: 3d9083ab00 CMP EAX,0xab8390
    (void)integer::sub(s.ax,0x00ab8390u,32,flags);
  }
  { // 0x70aa2b: 72f1 JC 0x0070aa1e
    if(integer::condition("JC",flags)) goto L0070aa1e;
  }
  L0070aa2d: { // 0x70aa2d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x70aa2f: c3 RET
    finish(m,s,f,0u); return;
  }
  L0070aa30: { // 0x70aa30: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x70aa35: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030aad0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70aad0: a1e883ab00 MOV EAX,[0x00ab83e8]
    s.ax = m.r32((0x00ab83e8u));
  }
  { // 0x70aad5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70aad7: 751c JNZ 0x0070aaf5
    if(integer::condition("JNZ",flags)) goto L0070aaf5;
  }
  { // 0x70aad9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x70aada: 68b80b0000 PUSH 0xbb8
    f.push(m,0x00000bb8u);
  }
  { // 0x70aadf: e85cc4cfff CALL 0x00406f40
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x70aae4: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x70aae6: e8a5cccfff CALL 0x00407790
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x70aaeb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70aaed: a3e883ab00 MOV [0x00ab83e8],EAX
    m.w32((0x00ab83e8u), s.ax);
  }
  { // 0x70aaf2: 7501 JNZ 0x0070aaf5
    if(integer::condition("JNZ",flags)) goto L0070aaf5;
  }
  { // 0x70aaf4: c3 RET
    finish(m,s,f,0u); return;
  }
  L0070aaf5: { // 0x70aaf5: bab0347e00 MOV EDX,0x7e34b0
    s.dx = 0x007e34b0u;
  }
  { // 0x70aafa: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x70aafc: e89fd4cfff CALL 0x00407fa0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x70ab01: 8b1590978100 MOV EDX,dword ptr [0x00819790]
    s.dx = m.r32((0x00819790u));
  }
  { // 0x70ab07: 8b0ddc83ab00 MOV ECX,dword ptr [0x00ab83dc]
    s.cx = m.r32((0x00ab83dcu));
  }
  { // 0x70ab0d: e85ecfcfff CALL 0x00407a70
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x70ab12: 8b15a0978100 MOV EDX,dword ptr [0x008197a0]
    s.dx = m.r32((0x008197a0u));
  }
  { // 0x70ab18: 8b0ddc83ab00 MOV ECX,dword ptr [0x00ab83dc]
    s.cx = m.r32((0x00ab83dcu));
  }
  { // 0x70ab1e: e85dcfcfff CALL 0x00407a80
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x70ab23: c7059083ab0000000000 MOV dword ptr [0x00ab8390],0x0
    m.w32((0x00ab8390u), 0x00000000u);
  }
  { // 0x70ab2d: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x70ab32: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030ab40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70ab40: 8b0de883ab00 MOV ECX,dword ptr [0x00ab83e8]
    s.cx = m.r32((0x00ab83e8u));
  }
  { // 0x70ab46: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x70ab48: 741a JZ 0x0070ab64
    if(integer::condition("JZ",flags)) goto L0070ab64;
  }
  { // 0x70ab4a: e811d3cfff CALL 0x00407e60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x70ab4f: 8b0de883ab00 MOV ECX,dword ptr [0x00ab83e8]
    s.cx = m.r32((0x00ab83e8u));
  }
  { // 0x70ab55: e866cecfff CALL 0x004079c0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x70ab5a: c705e883ab0000000000 MOV dword ptr [0x00ab83e8],0x0
    m.w32((0x00ab83e8u), 0x00000000u);
  }
  L0070ab64: { // 0x70ab64: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030b560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70b560: a1d483ab00 MOV EAX,[0x00ab83d4]
    s.ax = m.r32((0x00ab83d4u));
  }
  { // 0x70b565: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70b567: 7411 JZ 0x0070b57a
    if(integer::condition("JZ",flags)) goto L0070b57a;
  }
  { // 0x70b569: c7404802000000 MOV dword ptr [EAX + 0x48],0x2
    m.w32((s.ax+0x00000048u), 0x00000002u);
  }
  { // 0x70b570: c705d483ab0000000000 MOV dword ptr [0x00ab83d4],0x0
    m.w32((0x00ab83d4u), 0x00000000u);
  }
  L0070b57a: { // 0x70b57a: 8b0ddc83ab00 MOV ECX,dword ptr [0x00ab83dc]
    s.cx = m.r32((0x00ab83dcu));
  }
  { // 0x70b580: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x70b582: 7405 JZ 0x0070b589
    if(integer::condition("JZ",flags)) goto L0070b589;
  }
  { // 0x70b584: e8d7c8cfff CALL 0x00407e60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  L0070b589: { // 0x70b589: e8e2edffff CALL 0x0070a370
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x70b58e: c7054883ab0000000000 MOV dword ptr [0x00ab8348],0x0
    m.w32((0x00ab8348u), 0x00000000u);
  }
  { // 0x70b598: c705f882ab0000000000 MOV dword ptr [0x00ab82f8],0x0
    m.w32((0x00ab82f8u), 0x00000000u);
  }
  { // 0x70b5a2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030bb00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70bb00: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x70bb03: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x70bb04: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x70bb06: 6888c0ad00 PUSH 0xadc088
    f.push(m,0x00adc088u);
  }
  { // 0x70bb0b: 6888aaac00 PUSH 0xacaa88
    f.push(m,0x00acaa88u);
  }
  { // 0x70bb10: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x70bb14: e8a74d0000 CALL 0x007108c0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x70bb19: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x70bb1d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x70bb1e: e87d4e0000 CALL 0x007109a0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x70bb23: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x70bb25: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x70bb29: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x70bb2d: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x70bb31: a384aaac00 MOV [0x00acaa84],EAX
    m.w32((0x00acaa84u), s.ax);
  }
  { // 0x70bb36: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x70bb3a: 890d8ce0ad00 MOV dword ptr [0x00ade08c],ECX
    m.w32((0x00ade08cu), s.cx);
  }
  { // 0x70bb40: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x70bb44: 891568aaac00 MOV dword ptr [0x00acaa68],EDX
    m.w32((0x00acaa68u), s.dx);
  }
  { // 0x70bb4a: a388e0ad00 MOV [0x00ade088],EAX
    m.w32((0x00ade088u), s.ax);
  }
  { // 0x70bb4f: e8dc4d0000 CALL 0x00710930
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x70bb54: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x70bb56: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70bb57: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x70bb5a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00311460(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x711460: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x711461: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x711463: e828effeff CALL 0x00700390
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x711468: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x71146b: 8d4e54 LEA ECX,[ESI + 0x54]
    s.cx = (s.si+0x00000054u);
  }
  { // 0x71146e: c706a0567800 MOV dword ptr [ESI],0x7856a0
    m.w32((s.si), 0x007856a0u);
  }
  { // 0x711474: c7466000000000 MOV dword ptr [ESI + 0x60],0x0
    m.w32((s.si+0x00000060u), 0x00000000u);
  }
  { // 0x71147b: e8106ed2ff CALL 0x00438290
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x711480: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x711482: c70658567800 MOV dword ptr [ESI],0x785658
    m.w32((s.si), 0x00785658u);
  }
  { // 0x711488: e8c3ddd1ff CALL 0x0042f250
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x71148d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71148e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00319630(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x719630: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x719631: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x719632: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x719634: 83ceff OR ESI,0xffffffff
    s.si = integer::logical((s.si)|(0xffffffffu),32,flags);
  }
  { // 0x719637: 0fbe07 MOVSX EAX,byte ptr [EDI]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.di)),8));
  }
  { // 0x71963a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x71963b: e80e4e0500 CALL 0x0076e44e
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x719640: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x719643: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x719645: 7439 JZ 0x00719680
    if(integer::condition("JZ",flags)) goto L00719680;
  }
  { // 0x719647: 0fbe0f MOVSX ECX,byte ptr [EDI]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.di)),8));
  }
  { // 0x71964a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x71964b: e8c34c0500 CALL 0x0076e313
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x719650: 0fbe5701 MOVSX EDX,byte ptr [EDI + 0x1]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.di+0x00000001u)),8));
  }
  { // 0x719654: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x719656: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x719657: 83ee41 SUB ESI,0x41
    s.si = integer::sub(s.si,0x00000041u,32,flags);
  }
  { // 0x71965a: e8ef4d0500 CALL 0x0076e44e
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x71965f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x719662: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x719664: 741a JZ 0x00719680
    if(integer::condition("JZ",flags)) goto L00719680;
  }
  { // 0x719666: 0fbe4701 MOVSX EAX,byte ptr [EDI + 0x1]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.di+0x00000001u)),8));
  }
  { // 0x71966a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x71966b: e8a34c0500 CALL 0x0076e313
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x719670: 8d0c76 LEA ECX,[ESI + ESI*0x2]
    s.cx = (s.si+(s.si * 0x00000002u));
  }
  { // 0x719673: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x719676: 8d148e LEA EDX,[ESI + ECX*0x4]
    s.dx = (s.si+(s.cx * 0x00000004u));
  }
  { // 0x719679: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x71967a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71967b: 8d4450d9 LEA EAX,[EAX + EDX*0x2 + -0x27]
    s.ax = (s.ax+(s.dx * 0x00000002u)-0x00000027u);
  }
  { // 0x71967f: c3 RET
    finish(m,s,f,0u); return;
  }
  L00719680: { // 0x719680: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x719682: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x719683: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x719684: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0031aaa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71aaa0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x71aaa1: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x71aaa5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71aaa6: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x71aaa7: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  { // 0x71aaaa: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x71aaac: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x71aaae: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71aab0: 7513 JNZ 0x0071aac5
    if(integer::condition("JNZ",flags)) goto L0071aac5;
  }
  { // 0x71aab2: e8c95ff1ff CALL 0x00630a80
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71aab7: c7066c9e7900 MOV dword ptr [ESI],0x799e6c
    m.w32((s.si), 0x00799e6cu);
  }
  { // 0x71aabd: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71aabf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x71aac0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71aac1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x71aac2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0071aac5: { // 0x71aac5: 6a4c PUSH 0x4c
    f.push(m,0x0000004cu);
  }
  { // 0x71aac7: e88b2e0500 CALL 0x0076d957
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71aacc: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x71aacf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x71aad1: 740d JZ 0x0071aae0
    if(integer::condition("JZ",flags)) goto L0071aae0;
  }
  { // 0x71aad3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x71aad4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x71aad5: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x71aad7: e824000000 CALL 0x0071ab00
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x71aadc: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x71aade: eb02 JMP 0x0071aae2
    goto L0071aae2;
  }
  L0071aae0: { // 0x71aae0: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0071aae2: { // 0x71aae2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71aae4: e8975ff1ff CALL 0x00630a80
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x71aae9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71aaeb: c7066c9e7900 MOV dword ptr [ESI],0x799e6c
    m.w32((s.si), 0x00799e6cu);
  }
  { // 0x71aaf1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x71aaf2: e8d95ff1ff CALL 0x00630ad0
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x71aaf7: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71aaf9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x71aafa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71aafb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x71aafc: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0031af30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71af30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71af31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71af33: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x71af36: e8156f0000 CALL 0x00721e50
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71af3b: 394630 CMP dword ptr [ESI + 0x30],EAX
    (void)integer::sub(m.r32((s.si+0x00000030u)),s.ax,32,flags);
  }
  { // 0x71af3e: 7406 JZ 0x0071af46
    if(integer::condition("JZ",flags)) goto L0071af46;
  }
  { // 0x71af40: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x71af42: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71af43: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0071af46: { // 0x71af46: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  { // 0x71af49: e8426f0000 CALL 0x00721e90
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71af4e: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x71af52: 8b548e34 MOV EDX,dword ptr [ESI + ECX*0x4 + 0x34]
    s.dx = m.r32((s.si+(s.cx * 0x00000004u)+0x00000034u));
  }
  { // 0x71af56: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71af57: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x71af59: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x71af5c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0031beb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71beb0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x71beb1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x71beb2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71beb3: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x71beb5: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  { // 0x71beb7: 6a10 PUSH 0x10
    f.push(m,0x00000010u);
  }
  { // 0x71beb9: e8991a0500 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71bebe: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x71bec0: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x71bec3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x71bec5: 7432 JZ 0x0071bef9
    if(integer::condition("JZ",flags)) goto L0071bef9;
  }
  { // 0x71bec7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x71bec8: 8d7e08 LEA EDI,[ESI + 0x8]
    s.di = (s.si+0x00000008u);
  }
  { // 0x71becb: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x71becd: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x71bed4: c706d43c7900 MOV dword ptr [ESI],0x793cd4
    m.w32((s.si), 0x00793cd4u);
  }
  { // 0x71beda: e8a14bf1ff CALL 0x00630a80
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71bedf: c7072cf57800 MOV dword ptr [EDI],0x78f52c
    m.w32((s.di), 0x0078f52cu);
  }
  { // 0x71bee5: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  { // 0x71bee8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x71bee9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x71beeb: e8e04bf1ff CALL 0x00630ad0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x71bef0: c7060c9f7900 MOV dword ptr [ESI],0x799f0c
    m.w32((s.si), 0x00799f0cu);
  }
  { // 0x71bef6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x71bef7: eb02 JMP 0x0071befb
    goto L0071befb;
  }
  L0071bef9: { // 0x71bef9: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0071befb: { // 0x71befb: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  { // 0x71befd: e87e4bf1ff CALL 0x00630a80
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x71bf02: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  { // 0x71bf04: c745007c9e7900 MOV dword ptr [EBP],0x799e7c
    m.w32((s.bp), 0x00799e7cu);
  }
  { // 0x71bf0b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71bf0c: e8bf4bf1ff CALL 0x00630ad0
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x71bf11: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  { // 0x71bf13: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71bf14: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x71bf15: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x71bf16: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0031bf20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71bf20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71bf21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71bf23: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x71bf24: 8d7e08 LEA EDI,[ESI + 0x8]
    s.di = (s.si+0x00000008u);
  }
  { // 0x71bf27: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x71bf2e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x71bf30: c706d43c7900 MOV dword ptr [ESI],0x793cd4
    m.w32((s.si), 0x00793cd4u);
  }
  { // 0x71bf36: e8454bf1ff CALL 0x00630a80
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71bf3b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x71bf3f: c7072cf57800 MOV dword ptr [EDI],0x78f52c
    m.w32((s.di), 0x0078f52cu);
  }
  { // 0x71bf45: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x71bf48: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x71bf49: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x71bf4b: e8804bf1ff CALL 0x00630ad0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71bf50: c7060c9f7900 MOV dword ptr [ESI],0x799f0c
    m.w32((s.si), 0x00799f0cu);
  }
  { // 0x71bf56: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71bf58: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x71bf59: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71bf5a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0031bf80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71bf80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71bf81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71bf83: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x71bf86: c7060c9f7900 MOV dword ptr [ESI],0x799f0c
    m.w32((s.si), 0x00799f0cu);
  }
  { // 0x71bf8c: c7012cf57800 MOV dword ptr [ECX],0x78f52c
    m.w32((s.cx), 0x0078f52cu);
  }
  { // 0x71bf92: e8194bf1ff CALL 0x00630ab0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71bf97: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71bf99: e8124df1ff CALL 0x00630cb0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71bf9e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71bf9f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0031c6f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71c6f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71c6f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71c6f3: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x71c6f6: c7060c9f7900 MOV dword ptr [ESI],0x799f0c
    m.w32((s.si), 0x00799f0cu);
  }
  { // 0x71c6fc: c7012cf57800 MOV dword ptr [ECX],0x78f52c
    m.w32((s.cx), 0x0078f52cu);
  }
  { // 0x71c702: e8a943f1ff CALL 0x00630ab0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71c707: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71c709: e8a245f1ff CALL 0x00630cb0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71c70e: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x71c713: 7409 JZ 0x0071c71e
    if(integer::condition("JZ",flags)) goto L0071c71e;
  }
  { // 0x71c715: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71c716: e8600f0500 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x71c71b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0071c71e: { // 0x71c71e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71c720: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71c721: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0031c7d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71c7d0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x71c7d1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71c7d2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x71c7d3: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x71c7d5: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x71c7d7: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  { // 0x71c7d9: e879110500 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71c7de: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x71c7e0: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x71c7e3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x71c7e5: 7423 JZ 0x0071c80a
    if(integer::condition("JZ",flags)) goto L0071c80a;
  }
  { // 0x71c7e7: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x71c7eb: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x71c7ef: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x71c7f0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x71c7f1: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  { // 0x71c7f3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x71c7f4: e8c7ca0300 CALL 0x007592c0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71c7f9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71c7fb: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x71c7ff: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x71c800: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x71c801: e85a010000 CALL 0x0071c960
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x71c806: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x71c808: eb02 JMP 0x0071c80c
    goto L0071c80c;
  }
  L0071c80a: { // 0x71c80a: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0071c80c: { // 0x71c80c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x71c80e: e86d42f1ff CALL 0x00630a80
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x71c813: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x71c815: c707649f7900 MOV dword ptr [EDI],0x799f64
    m.w32((s.di), 0x00799f64u);
  }
  { // 0x71c81b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71c81c: e8af42f1ff CALL 0x00630ad0
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x71c821: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  { // 0x71c825: e8f6ca0300 CALL 0x00759320
    invoke(m,s,f,op,5u); flags=0x202u;
  }
  { // 0x71c82a: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x71c82c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x71c82d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71c82e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x71c82f: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0031c960(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71c960: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x71c964: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x71c968: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71c969: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71c96b: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x71c96f: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x71c972: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  { // 0x71c976: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  { // 0x71c979: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x71c97a: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x71c97d: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x71c984: c706a89f7900 MOV dword ptr [ESI],0x799fa8
    m.w32((s.si), 0x00799fa8u);
  }
  { // 0x71c98a: 895610 MOV dword ptr [ESI + 0x10],EDX
    m.w32((s.si+0x00000010u), s.dx);
  }
  { // 0x71c98d: e82ec90300 CALL 0x007592c0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71c992: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x71c996: c706909f7900 MOV dword ptr [ESI],0x799f90
    m.w32((s.si), 0x00799f90u);
  }
  { // 0x71c99c: e87fc90300 CALL 0x00759320
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71c9a1: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71c9a3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71c9a4: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_0031cae0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71cae0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71cae1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71cae3: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x71cae6: e835c80300 CALL 0x00759320
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71caeb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71caed: e83e070000 CALL 0x0071d230
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71caf2: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x71caf7: 7409 JZ 0x0071cb02
    if(integer::condition("JZ",flags)) goto L0071cb02;
  }
  { // 0x71caf9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71cafa: e87c0b0500 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x71caff: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0071cb02: { // 0x71cb02: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71cb04: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71cb05: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0031cec0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71cec0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71cec1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71cec3: e8b83bf1ff CALL 0x00630a80
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71cec8: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x71cecc: c7066c9f7900 MOV dword ptr [ESI],0x799f6c
    m.w32((s.si), 0x00799f6cu);
  }
  { // 0x71ced2: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x71ced5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x71ced6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71ced8: e8f33bf1ff CALL 0x00630ad0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71cedd: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71cedf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71cee0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0031d390(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71d390: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x71d391: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71d392: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x71d393: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x71d395: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x71d397: 6a1c PUSH 0x1c
    f.push(m,0x0000001cu);
  }
  { // 0x71d399: e8b9050500 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71d39e: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x71d3a0: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x71d3a3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x71d3a5: 7430 JZ 0x0071d3d7
    if(integer::condition("JZ",flags)) goto L0071d3d7;
  }
  { // 0x71d3a7: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x71d3ab: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  { // 0x71d3af: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x71d3b0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x71d3b1: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  { // 0x71d3b3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x71d3b4: e807bf0300 CALL 0x007592c0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71d3b9: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  { // 0x71d3bd: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x71d3c1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x71d3c2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x71d3c3: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  { // 0x71d3c5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x71d3c6: e8f5be0300 CALL 0x007592c0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x71d3cb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71d3cd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x71d3ce: e87d030000 CALL 0x0071d750
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x71d3d3: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x71d3d5: eb02 JMP 0x0071d3d9
    goto L0071d3d9;
  }
  L0071d3d7: { // 0x71d3d7: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0071d3d9: { // 0x71d3d9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x71d3db: e8a036f1ff CALL 0x00630a80
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x71d3e0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x71d3e2: c7075c9f7900 MOV dword ptr [EDI],0x799f5c
    m.w32((s.di), 0x00799f5cu);
  }
  { // 0x71d3e8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71d3e9: e8e236f1ff CALL 0x00630ad0
    invoke(m,s,f,op,5u); flags=0x202u;
  }
  { // 0x71d3ee: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x71d3f2: e829bf0300 CALL 0x00759320
    invoke(m,s,f,op,6u); flags=0x202u;
  }
  { // 0x71d3f7: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  { // 0x71d3fb: e820bf0300 CALL 0x00759320
    invoke(m,s,f,op,7u); flags=0x202u;
  }
  { // 0x71d400: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x71d402: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x71d403: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71d404: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x71d405: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_0031d620(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71d620: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71d621: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x71d622: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x71d624: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71d626: 6a0c PUSH 0xc
    f.push(m,0x0000000cu);
  }
  { // 0x71d628: e82a030500 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71d62d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x71d630: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x71d632: 7414 JZ 0x0071d648
    if(integer::condition("JZ",flags)) goto L0071d648;
  }
  { // 0x71d634: 897808 MOV dword ptr [EAX + 0x8],EDI
    m.w32((s.ax+0x00000008u), s.di);
  }
  { // 0x71d637: c7400400000000 MOV dword ptr [EAX + 0x4],0x0
    m.w32((s.ax+0x00000004u), 0x00000000u);
  }
  { // 0x71d63e: c700fc9f7900 MOV dword ptr [EAX],0x799ffc
    m.w32((s.ax), 0x00799ffcu);
  }
  { // 0x71d644: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x71d646: eb02 JMP 0x0071d64a
    goto L0071d64a;
  }
  L0071d648: { // 0x71d648: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0071d64a: { // 0x71d64a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71d64c: e82f34f1ff CALL 0x00630a80
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71d651: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71d653: c706889f7900 MOV dword ptr [ESI],0x799f88
    m.w32((s.si), 0x00799f88u);
  }
  { // 0x71d659: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x71d65a: e87134f1ff CALL 0x00630ad0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x71d65f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71d661: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x71d662: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71d663: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0031d750(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71d750: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x71d754: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x71d758: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71d759: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71d75b: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x71d75f: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x71d762: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  { // 0x71d766: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  { // 0x71d769: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x71d76a: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x71d76d: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x71d774: c706a89f7900 MOV dword ptr [ESI],0x799fa8
    m.w32((s.si), 0x00799fa8u);
  }
  { // 0x71d77a: 895610 MOV dword ptr [ESI + 0x10],EDX
    m.w32((s.si+0x00000010u), s.dx);
  }
  { // 0x71d77d: e83ebb0300 CALL 0x007592c0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71d782: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x71d786: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x71d787: 8d4e18 LEA ECX,[ESI + 0x18]
    s.cx = (s.si+0x00000018u);
  }
  { // 0x71d78a: e831bb0300 CALL 0x007592c0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71d78f: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x71d793: c706e49f7900 MOV dword ptr [ESI],0x799fe4
    m.w32((s.si), 0x00799fe4u);
  }
  { // 0x71d799: e882bb0300 CALL 0x00759320
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x71d79e: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  { // 0x71d7a2: e879bb0300 CALL 0x00759320
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x71d7a7: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71d7a9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71d7aa: c21400 RET 0x14
    finish(m,s,f,20u); return;
  }
}
void f_0031d7b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71d7b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71d7b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71d7b3: 8d4e18 LEA ECX,[ESI + 0x18]
    s.cx = (s.si+0x00000018u);
  }
  { // 0x71d7b6: e865bb0300 CALL 0x00759320
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71d7bb: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x71d7be: e85dbb0300 CALL 0x00759320
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71d7c3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71d7c5: c706a89f7900 MOV dword ptr [ESI],0x799fa8
    m.w32((s.si), 0x00799fa8u);
  }
  { // 0x71d7cb: e8e034f1ff CALL 0x00630cb0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x71d7d0: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x71d7d5: 7409 JZ 0x0071d7e0
    if(integer::condition("JZ",flags)) goto L0071d7e0;
  }
  { // 0x71d7d7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71d7d8: e89efe0400 CALL 0x0076d67b
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x71d7dd: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0071d7e0: { // 0x71d7e0: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71d7e2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71d7e3: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0031da10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71da10: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x71da11: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x71da12: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71da13: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x71da15: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  { // 0x71da17: 6a10 PUSH 0x10
    f.push(m,0x00000010u);
  }
  { // 0x71da19: e839ff0400 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71da1e: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x71da20: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x71da23: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x71da25: 7432 JZ 0x0071da59
    if(integer::condition("JZ",flags)) goto L0071da59;
  }
  { // 0x71da27: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x71da28: 8d7e08 LEA EDI,[ESI + 0x8]
    s.di = (s.si+0x00000008u);
  }
  { // 0x71da2b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x71da2d: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x71da34: c706d43c7900 MOV dword ptr [ESI],0x793cd4
    m.w32((s.si), 0x00793cd4u);
  }
  { // 0x71da3a: e84130f1ff CALL 0x00630a80
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71da3f: c70734a07900 MOV dword ptr [EDI],0x79a034
    m.w32((s.di), 0x0079a034u);
  }
  { // 0x71da45: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  { // 0x71da48: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x71da49: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x71da4b: e88030f1ff CALL 0x00630ad0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x71da50: c70624a07900 MOV dword ptr [ESI],0x79a024
    m.w32((s.si), 0x0079a024u);
  }
  { // 0x71da56: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x71da57: eb02 JMP 0x0071da5b
    goto L0071da5b;
  }
  L0071da59: { // 0x71da59: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0071da5b: { // 0x71da5b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  { // 0x71da5d: e81e30f1ff CALL 0x00630a80
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x71da62: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  { // 0x71da64: c74500bc9e7900 MOV dword ptr [EBP],0x799ebc
    m.w32((s.bp), 0x00799ebcu);
  }
  { // 0x71da6b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71da6c: e85f30f1ff CALL 0x00630ad0
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x71da71: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  { // 0x71da73: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71da74: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x71da75: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x71da76: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0031da80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71da80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71da81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71da83: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x71da84: 8d7e08 LEA EDI,[ESI + 0x8]
    s.di = (s.si+0x00000008u);
  }
  { // 0x71da87: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x71da8e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x71da90: c706d43c7900 MOV dword ptr [ESI],0x793cd4
    m.w32((s.si), 0x00793cd4u);
  }
  { // 0x71da96: e8e52ff1ff CALL 0x00630a80
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71da9b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x71da9f: c70734a07900 MOV dword ptr [EDI],0x79a034
    m.w32((s.di), 0x0079a034u);
  }
  { // 0x71daa5: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x71daa8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x71daa9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x71daab: e82030f1ff CALL 0x00630ad0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71dab0: c70624a07900 MOV dword ptr [ESI],0x79a024
    m.w32((s.si), 0x0079a024u);
  }
  { // 0x71dab6: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71dab8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x71dab9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71daba: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0031db00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71db00: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71db01: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71db03: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x71db06: c70624a07900 MOV dword ptr [ESI],0x79a024
    m.w32((s.si), 0x0079a024u);
  }
  { // 0x71db0c: c70134a07900 MOV dword ptr [ECX],0x79a034
    m.w32((s.cx), 0x0079a034u);
  }
  { // 0x71db12: e8992ff1ff CALL 0x00630ab0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71db17: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71db19: e89231f1ff CALL 0x00630cb0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71db1e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71db1f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0031db20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71db20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71db21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71db23: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x71db26: c70624a07900 MOV dword ptr [ESI],0x79a024
    m.w32((s.si), 0x0079a024u);
  }
  { // 0x71db2c: c70134a07900 MOV dword ptr [ECX],0x79a034
    m.w32((s.cx), 0x0079a034u);
  }
  { // 0x71db32: e8792ff1ff CALL 0x00630ab0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71db37: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71db39: e87231f1ff CALL 0x00630cb0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71db3e: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x71db43: 7409 JZ 0x0071db4e
    if(integer::condition("JZ",flags)) goto L0071db4e;
  }
  { // 0x71db45: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71db46: e830fb0400 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x71db4b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0071db4e: { // 0x71db4e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71db50: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71db51: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0031dea0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71dea0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71dea1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x71dea2: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x71dea4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71dea6: 68d4000000 PUSH 0xd4
    f.push(m,0x000000d4u);
  }
  { // 0x71deab: e8a7fa0400 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71deb0: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x71deb3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x71deb5: 7416 JZ 0x0071decd
    if(integer::condition("JZ",flags)) goto L0071decd;
  }
  { // 0x71deb7: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x71debb: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x71debf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x71dec0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x71dec1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x71dec2: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x71dec4: e827000000 CALL 0x0071def0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71dec9: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x71decb: eb02 JMP 0x0071decf
    goto L0071decf;
  }
  L0071decd: { // 0x71decd: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0071decf: { // 0x71decf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71ded1: e8aa2bf1ff CALL 0x00630a80
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x71ded6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71ded8: c70674a07900 MOV dword ptr [ESI],0x79a074
    m.w32((s.si), 0x0079a074u);
  }
  { // 0x71dede: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x71dedf: e8ec2bf1ff CALL 0x00630ad0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x71dee4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x71dee6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x71dee7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71dee8: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0031f290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71f290: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x71f294: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71f295: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71f297: 384674 CMP byte ptr [ESI + 0x74],AL
    (void)integer::sub(m.r8((s.si+0x00000074u)),(s.ax & 0xffu),8,flags);
  }
  { // 0x71f29a: 7435 JZ 0x0071f2d1
    if(integer::condition("JZ",flags)) goto L0071f2d1;
  }
  { // 0x71f29c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x71f29e: 884674 MOV byte ptr [ESI + 0x74],AL
    m.w8((s.si+0x00000074u), (s.ax & 0xffu));
  }
  { // 0x71f2a1: 740c JZ 0x0071f2af
    if(integer::condition("JZ",flags)) goto L0071f2af;
  }
  { // 0x71f2a3: 8a4668 MOV AL,byte ptr [ESI + 0x68]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000068u)));
  }
  { // 0x71f2a6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x71f2a8: 7405 JZ 0x0071f2af
    if(integer::condition("JZ",flags)) goto L0071f2af;
  }
  { // 0x71f2aa: 8b4670 MOV EAX,dword ptr [ESI + 0x70]
    s.ax = m.r32((s.si+0x00000070u));
  }
  { // 0x71f2ad: eb03 JMP 0x0071f2b2
    goto L0071f2b2;
  }
  L0071f2af: { // 0x71f2af: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L0071f2b2: { // 0x71f2b2: 8b4e64 MOV ECX,dword ptr [ESI + 0x64]
    s.cx = m.r32((s.si+0x00000064u));
  }
  { // 0x71f2b5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x71f2b6: e845b1e8ff CALL 0x005aa400
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71f2bb: 83c654 ADD ESI,0x54
    s.si = integer::add(s.si,0x00000054u,32,flags);
  }
  { // 0x71f2be: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71f2bf: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x71f2c3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71f2c5: e81611e9ff CALL 0x005b03e0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71f2ca: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71f2cc: e89f08e9ff CALL 0x005afb70
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  L0071f2d1: { // 0x71f2d1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71f2d2: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0031f2e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x71f2e0: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x71f2e4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71f2e5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x71f2e7: 384668 CMP byte ptr [ESI + 0x68],AL
    (void)integer::sub(m.r8((s.si+0x00000068u)),(s.ax & 0xffu),8,flags);
  }
  { // 0x71f2ea: 7435 JZ 0x0071f321
    if(integer::condition("JZ",flags)) goto L0071f321;
  }
  { // 0x71f2ec: 8a4e74 MOV CL,byte ptr [ESI + 0x74]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000074u)));
  }
  { // 0x71f2ef: 884668 MOV byte ptr [ESI + 0x68],AL
    m.w8((s.si+0x00000068u), (s.ax & 0xffu));
  }
  { // 0x71f2f2: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x71f2f4: 7409 JZ 0x0071f2ff
    if(integer::condition("JZ",flags)) goto L0071f2ff;
  }
  { // 0x71f2f6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x71f2f8: 7405 JZ 0x0071f2ff
    if(integer::condition("JZ",flags)) goto L0071f2ff;
  }
  { // 0x71f2fa: 8b4670 MOV EAX,dword ptr [ESI + 0x70]
    s.ax = m.r32((s.si+0x00000070u));
  }
  { // 0x71f2fd: eb03 JMP 0x0071f302
    goto L0071f302;
  }
  L0071f2ff: { // 0x71f2ff: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L0071f302: { // 0x71f302: 8b4e64 MOV ECX,dword ptr [ESI + 0x64]
    s.cx = m.r32((s.si+0x00000064u));
  }
  { // 0x71f305: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x71f306: e8f5b0e8ff CALL 0x005aa400
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x71f30b: 83c654 ADD ESI,0x54
    s.si = integer::add(s.si,0x00000054u,32,flags);
  }
  { // 0x71f30e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x71f30f: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x71f313: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71f315: e8c610e9ff CALL 0x005b03e0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x71f31a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x71f31c: e84f08e9ff CALL 0x005afb70
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  L0071f321: { // 0x71f321: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x71f322: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00320980(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x720980: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x720981: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x720982: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x720984: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  { // 0x720986: e8cccf0400 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x72098b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x72098e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x720990: 740b JZ 0x0072099d
    if(integer::condition("JZ",flags)) goto L0072099d;
  }
  { // 0x720992: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x720994: e827000000 CALL 0x007209c0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x720999: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x72099b: eb02 JMP 0x0072099f
    goto L0072099f;
  }
  L0072099d: { // 0x72099d: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0072099f: { // 0x72099f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x7209a1: e8da00f1ff CALL 0x00630a80
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x7209a6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x7209a8: c7062cf57800 MOV dword ptr [ESI],0x78f52c
    m.w32((s.si), 0x0078f52cu);
  }
  { // 0x7209ae: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7209af: e81c01f1ff CALL 0x00630ad0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x7209b4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x7209b6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7209b7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7209b8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00320a70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x720a70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x720a71: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x720a72: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x720a74: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x720a76: 6a4c PUSH 0x4c
    f.push(m,0x0000004cu);
  }
  { // 0x720a78: e8dace0400 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x720a7d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x720a80: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x720a82: 740c JZ 0x00720a90
    if(integer::condition("JZ",flags)) goto L00720a90;
  }
  { // 0x720a84: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x720a85: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x720a87: e8d4000000 CALL 0x00720b60
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x720a8c: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x720a8e: eb02 JMP 0x00720a92
    goto L00720a92;
  }
  L00720a90: { // 0x720a90: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00720a92: { // 0x720a92: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x720a94: e8e7fff0ff CALL 0x00630a80
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x720a99: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x720a9b: c70634a07900 MOV dword ptr [ESI],0x79a034
    m.w32((s.si), 0x0079a034u);
  }
  { // 0x720aa1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x720aa2: e82900f1ff CALL 0x00630ad0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x720aa7: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x720aa9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x720aaa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x720aab: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00321660(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x721660: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x721661: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x721663: e818f4f0ff CALL 0x00630a80
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x721668: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x72166c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x72166e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72166f: c7062cf57800 MOV dword ptr [ESI],0x78f52c
    m.w32((s.si), 0x0078f52cu);
  }
  { // 0x721675: e856f4f0ff CALL 0x00630ad0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x72167a: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x72167c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72167d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00321d40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x721d40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x721d41: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x721d42: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x721d44: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x721d46: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  { // 0x721d48: e80abc0400 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x721d4d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x721d50: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x721d52: 740c JZ 0x00721d60
    if(integer::condition("JZ",flags)) goto L00721d60;
  }
  { // 0x721d54: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x721d55: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x721d57: e854000000 CALL 0x00721db0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x721d5c: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x721d5e: eb02 JMP 0x00721d62
    goto L00721d62;
  }
  L00721d60: { // 0x721d60: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00721d62: { // 0x721d62: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x721d64: e817edf0ff CALL 0x00630a80
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x721d69: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x721d6b: c706b49e7900 MOV dword ptr [ESI],0x799eb4
    m.w32((s.si), 0x00799eb4u);
  }
  { // 0x721d71: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x721d72: e859edf0ff CALL 0x00630ad0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x721d77: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x721d79: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x721d7a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x721d7b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00321d80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x721d80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x721d81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x721d83: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x721d86: c706dca17900 MOV dword ptr [ESI],0x79a1dc
    m.w32((s.si), 0x0079a1dcu);
  }
  { // 0x721d8c: e8ff950300 CALL 0x0075b390
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x721d91: 8d4e10 LEA ECX,[ESI + 0x10]
    s.cx = (s.si+0x00000010u);
  }
  { // 0x721d94: e8f7950300 CALL 0x0075b390
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x721d99: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x721d9c: c70134a07900 MOV dword ptr [ECX],0x79a034
    m.w32((s.cx), 0x0079a034u);
  }
  { // 0x721da2: e809edf0ff CALL 0x00630ab0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x721da7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x721da9: e802eff0ff CALL 0x00630cb0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x721dae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x721daf: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00321ee0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x721ee0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x721ee1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x721ee3: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x721ee6: c706dca17900 MOV dword ptr [ESI],0x79a1dc
    m.w32((s.si), 0x0079a1dcu);
  }
  { // 0x721eec: e89f940300 CALL 0x0075b390
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x721ef1: 8d4e10 LEA ECX,[ESI + 0x10]
    s.cx = (s.si+0x00000010u);
  }
  { // 0x721ef4: e897940300 CALL 0x0075b390
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x721ef9: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x721efc: c70134a07900 MOV dword ptr [ECX],0x79a034
    m.w32((s.cx), 0x0079a034u);
  }
  { // 0x721f02: e8a9ebf0ff CALL 0x00630ab0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x721f07: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x721f09: e8a2edf0ff CALL 0x00630cb0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x721f0e: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x721f13: 7409 JZ 0x00721f1e
    if(integer::condition("JZ",flags)) goto L00721f1e;
  }
  { // 0x721f15: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x721f16: e860b70400 CALL 0x0076d67b
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x721f1b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00721f1e: { // 0x721f1e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x721f20: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x721f21: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00324b40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x724b40: 81ecb0040000 SUB ESP,0x4b0
    f.sp = integer::sub(f.sp,0x000004b0u,32,flags);
  }
  { // 0x724b46: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x724b47: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x724b48: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x724b4a: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x724b4c: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  { // 0x724b52: e8f9c0e0ff CALL 0x00530c50
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x724b57: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x724b5b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x724b5c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x724b5d: e8bed5ffff CALL 0x00722120
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x724b62: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x724b66: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x724b67: e854faffff CALL 0x007245c0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x724b6c: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x724b70: e8dbd9ffff CALL 0x00722550
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x724b75: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x724b76: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x724b77: 81c4b0040000 ADD ESP,0x4b0
    f.sp = integer::add(f.sp,0x000004b0u,32,flags);
  }
  { // 0x724b7d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00324ea0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x724ea0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x724ea1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x724ea3: e8d8bbf0ff CALL 0x00630a80
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x724ea8: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x724eac: c7060ca17900 MOV dword ptr [ESI],0x79a10c
    m.w32((s.si), 0x0079a10cu);
  }
  { // 0x724eb2: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x724eb5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x724eb6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x724eb8: e813bcf0ff CALL 0x00630ad0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x724ebd: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x724ebf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x724ec0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00325350(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x725350: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x725351: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x725352: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x725354: 6a14 PUSH 0x14
    f.push(m,0x00000014u);
  }
  { // 0x725356: e8fc850400 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x72535b: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x72535d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x725360: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x725362: 742e JZ 0x00725392
    if(integer::condition("JZ",flags)) goto L00725392;
  }
  { // 0x725364: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x725365: 8d7e08 LEA EDI,[ESI + 0x8]
    s.di = (s.si+0x00000008u);
  }
  { // 0x725368: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x72536a: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x725371: c706d43c7900 MOV dword ptr [ESI],0x793cd4
    m.w32((s.si), 0x00793cd4u);
  }
  { // 0x725377: e804b7f0ff CALL 0x00630a80
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x72537c: c70734a07900 MOV dword ptr [EDI],0x79a034
    m.w32((s.di), 0x0079a034u);
  }
  { // 0x725382: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  { // 0x725389: c7065ca27900 MOV dword ptr [ESI],0x79a25c
    m.w32((s.si), 0x0079a25cu);
  }
  { // 0x72538f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x725390: eb02 JMP 0x00725394
    goto L00725394;
  }
  L00725392: { // 0x725392: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00725394: { // 0x725394: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x725396: e8e5b6f0ff CALL 0x00630a80
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x72539b: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x72539d: c703749e7900 MOV dword ptr [EBX],0x799e74
    m.w32((s.bx), 0x00799e74u);
  }
  { // 0x7253a3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7253a4: e827b7f0ff CALL 0x00630ad0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x7253a9: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x7253ab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7253ac: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x7253ad: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003253f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7253f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7253f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x7253f3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7253f4: 8d7e08 LEA EDI,[ESI + 0x8]
    s.di = (s.si+0x00000008u);
  }
  { // 0x7253f7: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x7253fe: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x725400: c706d43c7900 MOV dword ptr [ESI],0x793cd4
    m.w32((s.si), 0x00793cd4u);
  }
  { // 0x725406: e875b6f0ff CALL 0x00630a80
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x72540b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x72540f: c70734a07900 MOV dword ptr [EDI],0x79a034
    m.w32((s.di), 0x0079a034u);
  }
  { // 0x725415: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x725418: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x725419: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x72541b: e8b0b6f0ff CALL 0x00630ad0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x725420: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  { // 0x725427: c7065ca27900 MOV dword ptr [ESI],0x79a25c
    m.w32((s.si), 0x0079a25cu);
  }
  { // 0x72542d: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x725430: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x725432: 7414 JZ 0x00725448
    if(integer::condition("JZ",flags)) goto L00725448;
  }
  { // 0x725434: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x725438: 8b5024 MOV EDX,dword ptr [EAX + 0x24]
    s.dx = m.r32((s.ax+0x00000024u));
  }
  { // 0x72543b: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x72543d: 7309 JNC 0x00725448
    if(integer::condition("JNC",flags)) goto L00725448;
  }
  { // 0x72543f: 8b5044 MOV EDX,dword ptr [EAX + 0x44]
    s.dx = m.r32((s.ax+0x00000044u));
  }
  { // 0x725442: 8b048a MOV EAX,dword ptr [EDX + ECX*0x4]
    s.ax = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  { // 0x725445: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L00725448: { // 0x725448: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x72544a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x72544b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72544c: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_003254a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7254a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7254a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x7254a3: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x7254a6: c7065ca27900 MOV dword ptr [ESI],0x79a25c
    m.w32((s.si), 0x0079a25cu);
  }
  { // 0x7254ac: c70134a07900 MOV dword ptr [ECX],0x79a034
    m.w32((s.cx), 0x0079a034u);
  }
  { // 0x7254b2: e8f9b5f0ff CALL 0x00630ab0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x7254b7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x7254b9: e8f2b7f0ff CALL 0x00630cb0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x7254be: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7254bf: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00325510(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x725510: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x725511: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x725513: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x725516: c7065ca27900 MOV dword ptr [ESI],0x79a25c
    m.w32((s.si), 0x0079a25cu);
  }
  { // 0x72551c: c70134a07900 MOV dword ptr [ECX],0x79a034
    m.w32((s.cx), 0x0079a034u);
  }
  { // 0x725522: e889b5f0ff CALL 0x00630ab0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x725527: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x725529: e882b7f0ff CALL 0x00630cb0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x72552e: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x725533: 7409 JZ 0x0072553e
    if(integer::condition("JZ",flags)) goto L0072553e;
  }
  { // 0x725535: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x725536: e840810400 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x72553b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0072553e: { // 0x72553e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x725540: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x725541: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00325740(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x725740: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x725741: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x725742: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x725744: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x725746: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  { // 0x725748: e80a820400 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x72574d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x725750: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x725752: 7420 JZ 0x00725774
    if(integer::condition("JZ",flags)) goto L00725774;
  }
  { // 0x725754: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x725758: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x72575c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x72575d: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x725761: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x725762: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x725766: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x725767: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x725768: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x725769: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x72576b: e830000000 CALL 0x007257a0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x725770: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x725772: eb02 JMP 0x00725776
    goto L00725776;
  }
  L00725774: { // 0x725774: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00725776: { // 0x725776: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x725778: e803b3f0ff CALL 0x00630a80
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x72577d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x72577f: c7060ca17900 MOV dword ptr [ESI],0x79a10c
    m.w32((s.si), 0x0079a10cu);
  }
  { // 0x725785: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x725786: e845b3f0ff CALL 0x00630ad0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x72578b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x72578d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x72578e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72578f: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_00325b40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x725b40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x725b41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x725b43: 8d4e20 LEA ECX,[ESI + 0x20]
    s.cx = (s.si+0x00000020u);
  }
  { // 0x725b46: c7067ca27900 MOV dword ptr [ESI],0x79a27c
    m.w32((s.si), 0x0079a27cu);
  }
  { // 0x725b4c: e8cf370300 CALL 0x00759320
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x725b51: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x725b54: e837580300 CALL 0x0075b390
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x725b59: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x725b5b: e850b1f0ff CALL 0x00630cb0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x725b60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x725b61: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00325e50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x725e50: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x725e51: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x725e53: 8d4e20 LEA ECX,[ESI + 0x20]
    s.cx = (s.si+0x00000020u);
  }
  { // 0x725e56: c7067ca27900 MOV dword ptr [ESI],0x79a27c
    m.w32((s.si), 0x0079a27cu);
  }
  { // 0x725e5c: e8bf340300 CALL 0x00759320
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x725e61: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x725e64: e827550300 CALL 0x0075b390
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x725e69: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x725e6b: e840aef0ff CALL 0x00630cb0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x725e70: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x725e75: 7409 JZ 0x00725e80
    if(integer::condition("JZ",flags)) goto L00725e80;
  }
  { // 0x725e77: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x725e78: e8fe770400 CALL 0x0076d67b
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x725e7d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00725e80: { // 0x725e80: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x725e82: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x725e83: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00327610(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x727610: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x727611: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x727612: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x727613: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x727615: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x727617: e83b630400 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x72761c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x72761e: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x727620: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x727623: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x727625: 7426 JZ 0x0072764d
    if(integer::condition("JZ",flags)) goto L0072764d;
  }
  { // 0x727627: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x72762a: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  { // 0x72762d: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  { // 0x727630: 885e0c MOV byte ptr [ESI + 0xc],BL
    m.w8((s.si+0x0000000cu), (s.bx & 0xffu));
  }
  { // 0x727633: e89884f6ff CALL 0x0068fad0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x727638: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x72763b: 895e18 MOV dword ptr [ESI + 0x18],EBX
    m.w32((s.si+0x00000018u), s.bx);
  }
  { // 0x72763e: 897e1c MOV dword ptr [ESI + 0x1c],EDI
    m.w32((s.si+0x0000001cu), s.di);
  }
  { // 0x727641: c7069ca27900 MOV dword ptr [ESI],0x79a29c
    m.w32((s.si), 0x0079a29cu);
  }
  { // 0x727647: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x727649: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x72764a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72764b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x72764c: c3 RET
    finish(m,s,f,0u); return;
  }
  L0072764d: { // 0x72764d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x72764e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72764f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x727651: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x727652: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0032e170(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72e170: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72e171: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x72e173: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x72e176: c706e4a37900 MOV dword ptr [ESI],0x79a3e4
    m.w32((s.si), 0x0079a3e4u);
  }
  { // 0x72e17c: e89fb10200 CALL 0x00759320
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x72e181: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x72e183: e8282bf0ff CALL 0x00630cb0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x72e188: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72e189: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0032e4e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72e4e0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x72e4e1: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x72e4e5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72e4e6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x72e4e8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x72e4e9: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x72e4eb: 8d7e0c LEA EDI,[ESI + 0xc]
    s.di = (s.si+0x0000000cu);
  }
  { // 0x72e4ee: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x72e4ef: e8bcae0200 CALL 0x007593b0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x72e4f4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x72e4f6: 750c JNZ 0x0072e504
    if(integer::condition("JNZ",flags)) goto L0072e504;
  }
  { // 0x72e4f8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x72e4f9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x72e4fb: e870b00200 CALL 0x00759570
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x72e500: c6460801 MOV byte ptr [ESI + 0x8],0x1
    m.w8((s.si+0x00000008u), 0x00000001u);
  }
  L0072e504: { // 0x72e504: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x72e505: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72e506: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x72e507: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0032ec50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72ec50: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72ec51: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x72ec53: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x72ec56: c706e4a37900 MOV dword ptr [ESI],0x79a3e4
    m.w32((s.si), 0x0079a3e4u);
  }
  { // 0x72ec5c: e8bfa60200 CALL 0x00759320
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x72ec61: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x72ec63: e84820f0ff CALL 0x00630cb0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x72ec68: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x72ec6d: 7409 JZ 0x0072ec78
    if(integer::condition("JZ",flags)) goto L0072ec78;
  }
  { // 0x72ec6f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x72ec70: e806ea0300 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x72ec75: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0072ec78: { // 0x72ec78: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x72ec7a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x72ec7b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_003398a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7398a0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x7398a3: 83c218 ADD EDX,0x18
    s.dx = integer::add(s.dx,0x00000018u,32,flags);
  }
  { // 0x7398a6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7398a7: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x7398a9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x7398aa: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x7398ae: e8adf90100 CALL 0x00759260
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x7398b3: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x7398b7: e894f90100 CALL 0x00759250
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x7398bc: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  { // 0x7398c0: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x7398c4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7398c5: 6808137d00 PUSH 0x7d1308
    f.push(m,0x007d1308u);
  }
  { // 0x7398ca: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x7398cc: e86f120200 CALL 0x0075ab40
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x7398d1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7398d3: 7c0d JL 0x007398e2
    if(integer::condition("JL",flags)) goto L007398e2;
  }
  { // 0x7398d5: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x7398d6: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x7398da: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7398db: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x7398dd: e86e030200 CALL 0x00759c50
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  L007398e2: { // 0x7398e2: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x7398e6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7398e7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x7398e9: e8d2f90100 CALL 0x007592c0
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x7398ee: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x7398f2: e829fa0100 CALL 0x00759320
    invoke(m,s,f,op,5u); flags=0x202u;
  }
  { // 0x7398f7: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x7398fb: e820fa0100 CALL 0x00759320
    invoke(m,s,f,op,6u); flags=0x202u;
  }
  { // 0x739900: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x739902: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x739903: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x739906: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0034a380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x74a380: a0a200b100 MOV AL,[0x00b100a2]
    s.ax = with_al(s.ax, m.r8((0x00b100a2u)));
  }
  { // 0x74a385: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x74a388: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x74a38a: c605a100b10000 MOV byte ptr [0x00b100a1],0x0
    m.w8((0x00b100a1u), 0x00000000u);
  }
  { // 0x74a391: 754d JNZ 0x0074a3e0
    if(integer::condition("JNZ",flags)) goto L0074a3e0;
  }
  { // 0x74a393: e8d836feff CALL 0x0072da70
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x74a398: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x74a39a: 7444 JZ 0x0074a3e0
    if(integer::condition("JZ",flags)) goto L0074a3e0;
  }
  { // 0x74a39c: b958eeb000 MOV ECX,0xb0ee58
    s.cx = 0x00b0ee58u;
  }
  { // 0x74a3a1: e8baa5ffff CALL 0x00744960
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x74a3a6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x74a3a8: 7436 JZ 0x0074a3e0
    if(integer::condition("JZ",flags)) goto L0074a3e0;
  }
  { // 0x74a3aa: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x74a3ae: e8bde9eaff CALL 0x005f8d70
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x74a3b3: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x74a3b7: baf0a37400 MOV EDX,0x74a3f0
    s.dx = 0x0074a3f0u;
  }
  { // 0x74a3bc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x74a3bd: b922010000 MOV ECX,0x122
    s.cx = 0x00000122u;
  }
  { // 0x74a3c2: c744240484a57900 MOV dword ptr [ESP + 0x4],0x79a584
    m.w32((f.sp+0x00000004u), 0x0079a584u);
  }
  { // 0x74a3ca: e881eaeaff CALL 0x005f8e50
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x74a3cf: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x74a3d3: c744240084a57900 MOV dword ptr [ESP],0x79a584
    m.w32((f.sp), 0x0079a584u);
  }
  { // 0x74a3db: e8b0e9eaff CALL 0x005f8d90
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  L0074a3e0: { // 0x74a3e0: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x74a3e3: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00351f70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x751f70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x751f71: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x751f73: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x751f76: c706aca77900 MOV dword ptr [ESI],0x79a7ac
    m.w32((s.si), 0x0079a7acu);
  }
  { // 0x751f7c: e89f730000 CALL 0x00759320
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x751f81: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x751f83: c70684a57900 MOV dword ptr [ESI],0x79a584
    m.w32((s.si), 0x0079a584u);
  }
  { // 0x751f89: e8026eeaff CALL 0x005f8d90
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x751f8e: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x751f93: 7409 JZ 0x00751f9e
    if(integer::condition("JZ",flags)) goto L00751f9e;
  }
  { // 0x751f95: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x751f96: e8e0b60100 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x751f9b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00751f9e: { // 0x751f9e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x751fa0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x751fa1: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00351fb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x751fb0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x751fb1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x751fb3: e8b86deaff CALL 0x005f8d70
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x751fb8: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x751fbb: c70684a57900 MOV dword ptr [ESI],0x79a584
    m.w32((s.si), 0x0079a584u);
  }
  { // 0x751fc1: e88a720000 CALL 0x00759250
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x751fc6: c706aca77900 MOV dword ptr [ESI],0x79a7ac
    m.w32((s.si), 0x0079a7acu);
  }
  { // 0x751fcc: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x751fce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x751fcf: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00351fd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x751fd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x751fd1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x751fd3: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x751fd6: c706aca77900 MOV dword ptr [ESI],0x79a7ac
    m.w32((s.si), 0x0079a7acu);
  }
  { // 0x751fdc: e83f730000 CALL 0x00759320
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x751fe1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x751fe3: c70684a57900 MOV dword ptr [ESI],0x79a584
    m.w32((s.si), 0x0079a584u);
  }
  { // 0x751fe9: e8a26deaff CALL 0x005f8d90
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x751fee: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x751ff3: 7409 JZ 0x00751ffe
    if(integer::condition("JZ",flags)) goto L00751ffe;
  }
  { // 0x751ff5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x751ff6: e880b60100 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x751ffb: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00751ffe: { // 0x751ffe: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x752000: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x752001: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_003556c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7556c0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x7556c3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7556c4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x7556c6: b90002b100 MOV ECX,0xb10200
    s.cx = 0x00b10200u;
  }
  { // 0x7556cb: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x7556ce: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7556cf: e8fcb3edff CALL 0x00630ad0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x7556d4: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x7556d6: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x7556da: e861c6fcff CALL 0x00721d40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x7556df: baf0e5b000 MOV EDX,0xb0e5f0
    s.dx = 0x00b0e5f0u;
  }
  { // 0x7556e4: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x7556e8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7556e9: e8b253fcff CALL 0x0071aaa0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x7556ee: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x7556f1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7556f2: b91002b100 MOV ECX,0xb10210
    s.cx = 0x00b10210u;
  }
  { // 0x7556f7: e8d4b3edff CALL 0x00630ad0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x7556fc: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x755700: c74424046c9e7900 MOV dword ptr [ESP + 0x4],0x799e6c
    m.w32((f.sp+0x00000004u), 0x00799e6cu);
  }
  { // 0x755708: e8a3b3edff CALL 0x00630ab0
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x75570d: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x755711: c744240cb49e7900 MOV dword ptr [ESP + 0xc],0x799eb4
    m.w32((f.sp+0x0000000cu), 0x00799eb4u);
  }
  { // 0x755719: e892b3edff CALL 0x00630ab0
    invoke(m,s,f,op,5u); flags=0x202u;
  }
  { // 0x75571e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75571f: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x755722: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00355740(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x755740: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x755743: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x755744: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x755746: b91802b100 MOV ECX,0xb10218
    s.cx = 0x00b10218u;
  }
  { // 0x75574b: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x75574e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75574f: e87cb3edff CALL 0x00630ad0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x755754: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x755756: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x75575a: e8e1c5fcff CALL 0x00721d40
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x75575f: baf0e5b000 MOV EDX,0xb0e5f0
    s.dx = 0x00b0e5f0u;
  }
  { // 0x755764: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x755768: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x755769: e83253fcff CALL 0x0071aaa0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x75576e: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x755771: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x755772: b92002b100 MOV ECX,0xb10220
    s.cx = 0x00b10220u;
  }
  { // 0x755777: e854b3edff CALL 0x00630ad0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x75577c: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x755780: c74424046c9e7900 MOV dword ptr [ESP + 0x4],0x799e6c
    m.w32((f.sp+0x00000004u), 0x00799e6cu);
  }
  { // 0x755788: e823b3edff CALL 0x00630ab0
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x75578d: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x755791: c744240cb49e7900 MOV dword ptr [ESP + 0xc],0x799eb4
    m.w32((f.sp+0x0000000cu), 0x00799eb4u);
  }
  { // 0x755799: e812b3edff CALL 0x00630ab0
    invoke(m,s,f,op,5u); flags=0x202u;
  }
  { // 0x75579e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75579f: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x7557a2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00356f70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x756f70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x756f71: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x756f73: 8b866c380400 MOV EAX,dword ptr [ESI + 0x4386c]
    s.ax = m.r32((s.si+0x0004386cu));
  }
  { // 0x756f79: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x756f7c: 7410 JZ 0x00756f8e
    if(integer::condition("JZ",flags)) goto L00756f8e;
  }
  { // 0x756f7e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x756f7f: e84c650100 CALL 0x0076d4d0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x756f84: c7866c380400ffffffff MOV dword ptr [ESI + 0x4386c],0xffffffff
    m.w32((s.si+0x0004386cu), 0xffffffffu);
  }
  L00756f8e: { // 0x756f8e: 8b8670380400 MOV EAX,dword ptr [ESI + 0x43870]
    s.ax = m.r32((s.si+0x00043870u));
  }
  { // 0x756f94: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x756f97: 7410 JZ 0x00756fa9
    if(integer::condition("JZ",flags)) goto L00756fa9;
  }
  { // 0x756f99: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x756f9a: e831650100 CALL 0x0076d4d0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x756f9f: c78670380400ffffffff MOV dword ptr [ESI + 0x43870],0xffffffff
    m.w32((s.si+0x00043870u), 0xffffffffu);
  }
  L00756fa9: { // 0x756fa9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x756faa: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00357030(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x757030: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x757031: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x757033: 8b0d50deb000 MOV ECX,dword ptr [0x00b0de50]
    s.cx = m.r32((0x00b0de50u));
  }
  { // 0x757039: 8b866c380400 MOV EAX,dword ptr [ESI + 0x4386c]
    s.ax = m.r32((s.si+0x0004386cu));
  }
  { // 0x75703f: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x757042: 7415 JZ 0x00757059
    if(integer::condition("JZ",flags)) goto L00757059;
  }
  { // 0x757044: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x757046: 7411 JZ 0x00757059
    if(integer::condition("JZ",flags)) goto L00757059;
  }
  { // 0x757048: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x75704a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x75704c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75704d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75704e: e8a7640100 CALL 0x0076d4fa
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x757053: 8b0d50deb000 MOV ECX,dword ptr [0x00b0de50]
    s.cx = m.r32((0x00b0de50u));
  }
  L00757059: { // 0x757059: 8b8670380400 MOV EAX,dword ptr [ESI + 0x43870]
    s.ax = m.r32((s.si+0x00043870u));
  }
  { // 0x75705f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x757060: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x757063: 740f JZ 0x00757074
    if(integer::condition("JZ",flags)) goto L00757074;
  }
  { // 0x757065: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x757067: 740b JZ 0x00757074
    if(integer::condition("JZ",flags)) goto L00757074;
  }
  { // 0x757069: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x75706b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x75706d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75706e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75706f: e886640100 CALL 0x0076d4fa
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L00757074: { // 0x757074: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00359de0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x759de0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x759de1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x759de3: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x759de5: e836ffffff CALL 0x00759d20
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x759dea: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  { // 0x759dec: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x759dee: e82dffffff CALL 0x00759d20
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x759df3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x759df4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0035a710(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75a710: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75a711: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75a713: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75a714: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x75a716: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75a718: 7409 JZ 0x0075a723
    if(integer::condition("JZ",flags)) goto L0075a723;
  }
  { // 0x75a71a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75a71b: e85b2f0100 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x75a720: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0075a723: { // 0x75a723: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x75a727: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x75a72d: 8d4701 LEA EAX,[EDI + 0x1]
    s.ax = (s.di+0x00000001u);
  }
  { // 0x75a730: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75a731: e821320100 CALL 0x0076d957
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x75a736: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x75a738: c60000 MOV byte ptr [EAX],0x0
    m.w8((s.ax), 0x00000000u);
  }
  { // 0x75a73b: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x75a73f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75a742: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75a744: 740d JZ 0x0075a753
    if(integer::condition("JZ",flags)) goto L0075a753;
  }
  { // 0x75a746: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x75a748: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75a749: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75a74a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75a74b: e8c0350100 CALL 0x0076dd10
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x75a750: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0075a753: { // 0x75a753: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x75a755: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x75a757: c6043a00 MOV byte ptr [EDX + EDI*0x1],0x0
    m.w8((s.dx+(s.di * 0x00000001u)), 0x00000000u);
  }
  { // 0x75a75b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75a75c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75a75d: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0035b300(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75b300: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75b301: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75b302: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x75b306: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75b308: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x75b30a: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x75b310: 740c JZ 0x0075b31e
    if(integer::condition("JZ",flags)) goto L0075b31e;
  }
  { // 0x75b312: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75b313: e82d3c0100 CALL 0x0076ef45
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x75b318: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75b31b: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x75b31c: eb05 JMP 0x0075b323
    goto L0075b323;
  }
  L0075b31e: { // 0x75b31e: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0075b323: { // 0x75b323: 03c0 ADD EAX,EAX
    s.ax = integer::add(s.ax,s.ax,32,flags);
  }
  { // 0x75b325: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75b326: e82c260100 CALL 0x0076d957
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x75b32b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75b32e: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x75b330: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x75b332: 66c7000000 MOV word ptr [EAX],0x0
    m.w16((s.ax), 0x00000000u);
  }
  { // 0x75b337: 740c JZ 0x0075b345
    if(integer::condition("JZ",flags)) goto L0075b345;
  }
  { // 0x75b339: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x75b33b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75b33c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75b33d: e8873c0100 CALL 0x0076efc9
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x75b342: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0075b345: { // 0x75b345: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x75b347: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75b348: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75b349: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035b350(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75b350: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75b351: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75b352: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x75b356: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75b358: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x75b35e: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x75b360: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75b362: 741e JZ 0x0075b382
    if(integer::condition("JZ",flags)) goto L0075b382;
  }
  { // 0x75b364: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75b365: e8db3b0100 CALL 0x0076ef45
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x75b36a: 8d440002 LEA EAX,[EAX + EAX*0x1 + 0x2]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x00000002u);
  }
  { // 0x75b36e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75b36f: e8e3250100 CALL 0x0076d957
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x75b374: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x75b376: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x75b378: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75b379: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75b37a: e84a3c0100 CALL 0x0076efc9
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x75b37f: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0075b382: { // 0x75b382: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x75b384: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75b385: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75b386: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035b4b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75b4b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75b4b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75b4b3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75b4b4: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x75b4b6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75b4b8: 7409 JZ 0x0075b4c3
    if(integer::condition("JZ",flags)) goto L0075b4c3;
  }
  { // 0x75b4ba: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75b4bb: e8bb210100 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x75b4c0: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0075b4c3: { // 0x75b4c3: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x75b4c7: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x75b4cd: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x75b4cf: 740c JZ 0x0075b4dd
    if(integer::condition("JZ",flags)) goto L0075b4dd;
  }
  { // 0x75b4d1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75b4d2: e86e3a0100 CALL 0x0076ef45
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x75b4d7: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75b4da: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x75b4db: eb05 JMP 0x0075b4e2
    goto L0075b4e2;
  }
  L0075b4dd: { // 0x75b4dd: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0075b4e2: { // 0x75b4e2: 03c0 ADD EAX,EAX
    s.ax = integer::add(s.ax,s.ax,32,flags);
  }
  { // 0x75b4e4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75b4e5: e86d240100 CALL 0x0076d957
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x75b4ea: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75b4ed: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x75b4ef: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x75b4f1: 66c7000000 MOV word ptr [EAX],0x0
    m.w16((s.ax), 0x00000000u);
  }
  { // 0x75b4f6: 740c JZ 0x0075b504
    if(integer::condition("JZ",flags)) goto L0075b504;
  }
  { // 0x75b4f8: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x75b4fa: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75b4fb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75b4fc: e8c83a0100 CALL 0x0076efc9
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x75b501: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0075b504: { // 0x75b504: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x75b506: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75b507: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75b508: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035b5a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75b5a0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75b5a1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x75b5a2: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  { // 0x75b5a6: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x75b5a8: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  { // 0x75b5aa: 7507 JNZ 0x0075b5b3
    if(integer::condition("JNZ",flags)) goto L0075b5b3;
  }
  { // 0x75b5ac: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x75b5ad: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x75b5af: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75b5b0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0075b5b3: { // 0x75b5b3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75b5b4: 8b33 MOV ESI,dword ptr [EBX]
    s.si = m.r32((s.bx));
  }
  { // 0x75b5b6: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75b5b7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x75b5b8: e888390100 CALL 0x0076ef45
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x75b5bd: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x75b5bf: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75b5c2: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x75b5c3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x75b5c5: 740b JZ 0x0075b5d2
    if(integer::condition("JZ",flags)) goto L0075b5d2;
  }
  { // 0x75b5c7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75b5c8: e878390100 CALL 0x0076ef45
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x75b5cd: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75b5d0: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0075b5d2: { // 0x75b5d2: 8d04bd00000000 LEA EAX,[EDI*0x4 + 0x0]
    s.ax = ((s.di * 0x00000004u)+0x00000000u);
  }
  { // 0x75b5d9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75b5da: e878230100 CALL 0x0076d957
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x75b5df: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75b5e2: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  { // 0x75b5e4: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x75b5e6: 740c JZ 0x0075b5f4
    if(integer::condition("JZ",flags)) goto L0075b5f4;
  }
  { // 0x75b5e8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75b5e9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75b5ea: e8da390100 CALL 0x0076efc9
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x75b5ef: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x75b5f2: eb05 JMP 0x0075b5f9
    goto L0075b5f9;
  }
  L0075b5f4: { // 0x75b5f4: 66c7000000 MOV word ptr [EAX],0x0
    m.w16((s.ax), 0x00000000u);
  }
  L0075b5f9: { // 0x75b5f9: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x75b5fb: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x75b5fc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75b5fd: e89d390100 CALL 0x0076ef9f
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x75b602: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x75b605: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x75b607: 7409 JZ 0x0075b612
    if(integer::condition("JZ",flags)) goto L0075b612;
  }
  { // 0x75b609: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75b60a: e86c200100 CALL 0x0076d67b
    invoke(m,s,f,op,5u); flags=0x202u;
  }
  { // 0x75b60f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0075b612: { // 0x75b612: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75b613: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75b614: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x75b615: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x75b617: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75b618: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035b710(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75b710: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75b711: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x75b712: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  { // 0x75b716: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75b717: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  { // 0x75b719: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x75b71b: 745f JZ 0x0075b77c
    if(integer::condition("JZ",flags)) goto L0075b77c;
  }
  { // 0x75b71d: 8b33 MOV ESI,dword ptr [EBX]
    s.si = m.r32((s.bx));
  }
  { // 0x75b71f: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75b720: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x75b721: e81f380100 CALL 0x0076ef45
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x75b726: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x75b728: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75b72b: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x75b72c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x75b72e: 740b JZ 0x0075b73b
    if(integer::condition("JZ",flags)) goto L0075b73b;
  }
  { // 0x75b730: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75b731: e80f380100 CALL 0x0076ef45
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x75b736: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75b739: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0075b73b: { // 0x75b73b: 8d04bd00000000 LEA EAX,[EDI*0x4 + 0x0]
    s.ax = ((s.di * 0x00000004u)+0x00000000u);
  }
  { // 0x75b742: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75b743: e80f220100 CALL 0x0076d957
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x75b748: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75b74b: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  { // 0x75b74d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x75b74f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75b750: 740c JZ 0x0075b75e
    if(integer::condition("JZ",flags)) goto L0075b75e;
  }
  { // 0x75b752: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75b753: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75b754: e870380100 CALL 0x0076efc9
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x75b759: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x75b75c: eb05 JMP 0x0075b763
    goto L0075b763;
  }
  L0075b75e: { // 0x75b75e: 66c7000000 MOV word ptr [EAX],0x0
    m.w16((s.ax), 0x00000000u);
  }
  L0075b763: { // 0x75b763: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x75b765: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x75b766: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75b767: e833380100 CALL 0x0076ef9f
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x75b76c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x75b76f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x75b771: 7409 JZ 0x0075b77c
    if(integer::condition("JZ",flags)) goto L0075b77c;
  }
  { // 0x75b773: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75b774: e8021f0100 CALL 0x0076d67b
    invoke(m,s,f,op,5u); flags=0x202u;
  }
  { // 0x75b779: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0075b77c: { // 0x75b77c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75b77d: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x75b77f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x75b780: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75b781: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035b790(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75b790: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x75b794: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75b795: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x75b796: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75b797: 8b28 MOV EBP,dword ptr [EAX]
    s.bp = m.r32((s.ax));
  }
  { // 0x75b799: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x75b79b: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  { // 0x75b79d: 7509 JNZ 0x0075b7a8
    if(integer::condition("JNZ",flags)) goto L0075b7a8;
  }
  { // 0x75b79f: bd8c208200 MOV EBP,0x82208c
    s.bp = 0x0082208cu;
  }
  { // 0x75b7a4: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  { // 0x75b7a6: 745f JZ 0x0075b807
    if(integer::condition("JZ",flags)) goto L0075b807;
  }
  L0075b7a8: { // 0x75b7a8: 8b33 MOV ESI,dword ptr [EBX]
    s.si = m.r32((s.bx));
  }
  { // 0x75b7aa: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75b7ab: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x75b7ac: e894370100 CALL 0x0076ef45
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x75b7b1: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x75b7b3: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75b7b6: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x75b7b7: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x75b7b9: 740b JZ 0x0075b7c6
    if(integer::condition("JZ",flags)) goto L0075b7c6;
  }
  { // 0x75b7bb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75b7bc: e884370100 CALL 0x0076ef45
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x75b7c1: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75b7c4: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0075b7c6: { // 0x75b7c6: 8d0cbd00000000 LEA ECX,[EDI*0x4 + 0x0]
    s.cx = ((s.di * 0x00000004u)+0x00000000u);
  }
  { // 0x75b7cd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75b7ce: e884210100 CALL 0x0076d957
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x75b7d3: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75b7d6: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  { // 0x75b7d8: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x75b7da: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75b7db: 740c JZ 0x0075b7e9
    if(integer::condition("JZ",flags)) goto L0075b7e9;
  }
  { // 0x75b7dd: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75b7de: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75b7df: e8e5370100 CALL 0x0076efc9
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x75b7e4: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x75b7e7: eb05 JMP 0x0075b7ee
    goto L0075b7ee;
  }
  L0075b7e9: { // 0x75b7e9: 66c7000000 MOV word ptr [EAX],0x0
    m.w16((s.ax), 0x00000000u);
  }
  L0075b7ee: { // 0x75b7ee: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  { // 0x75b7f0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x75b7f1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x75b7f2: e8a8370100 CALL 0x0076ef9f
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x75b7f7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x75b7fa: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x75b7fc: 7409 JZ 0x0075b807
    if(integer::condition("JZ",flags)) goto L0075b807;
  }
  { // 0x75b7fe: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75b7ff: e8771e0100 CALL 0x0076d67b
    invoke(m,s,f,op,5u); flags=0x202u;
  }
  { // 0x75b804: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0075b807: { // 0x75b807: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75b808: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x75b80a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x75b80b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75b80c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035baf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75baf0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75baf1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75baf3: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x75baf5: e856ffffff CALL 0x0075ba50
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x75bafa: 6a09 PUSH 0x9
    f.push(m,0x00000009u);
  }
  { // 0x75bafc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x75bafe: e84dffffff CALL 0x0075ba50
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x75bb03: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75bb04: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0035c230(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75c230: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75c231: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75c233: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75c234: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x75c236: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75c238: 7409 JZ 0x0075c243
    if(integer::condition("JZ",flags)) goto L0075c243;
  }
  { // 0x75c23a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75c23b: e83b140100 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x75c240: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0075c243: { // 0x75c243: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x75c247: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x75c24d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x75c24f: 740c JZ 0x0075c25d
    if(integer::condition("JZ",flags)) goto L0075c25d;
  }
  { // 0x75c251: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75c252: e8ee2c0100 CALL 0x0076ef45
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x75c257: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75c25a: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x75c25b: eb05 JMP 0x0075c262
    goto L0075c262;
  }
  L0075c25d: { // 0x75c25d: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0075c262: { // 0x75c262: 03c0 ADD EAX,EAX
    s.ax = integer::add(s.ax,s.ax,32,flags);
  }
  { // 0x75c264: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75c265: e8ed160100 CALL 0x0076d957
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x75c26a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75c26d: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x75c26f: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x75c271: 66c7000000 MOV word ptr [EAX],0x0
    m.w16((s.ax), 0x00000000u);
  }
  { // 0x75c276: 740c JZ 0x0075c284
    if(integer::condition("JZ",flags)) goto L0075c284;
  }
  { // 0x75c278: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x75c27a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75c27b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75c27c: e8482d0100 CALL 0x0076efc9
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x75c281: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0075c284: { // 0x75c284: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75c285: 66b80100 MOV AX,0x1
    s.ax = with_ax(s.ax, 0x00000001u);
  }
  { // 0x75c289: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75c28a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035c2c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75c2c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75c2c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75c2c3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75c2c4: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x75c2c6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75c2c8: 7409 JZ 0x0075c2d3
    if(integer::condition("JZ",flags)) goto L0075c2d3;
  }
  { // 0x75c2ca: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75c2cb: e8ab130100 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x75c2d0: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0075c2d3: { // 0x75c2d3: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x75c2d7: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x75c2dd: 8d443f02 LEA EAX,[EDI + EDI*0x1 + 0x2]
    s.ax = (s.di+(s.di * 0x00000001u)+0x00000002u);
  }
  { // 0x75c2e1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75c2e2: e870160100 CALL 0x0076d957
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x75c2e7: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x75c2e9: 66c7000000 MOV word ptr [EAX],0x0
    m.w16((s.ax), 0x00000000u);
  }
  { // 0x75c2ee: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x75c2f2: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75c2f5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75c2f7: 740d JZ 0x0075c306
    if(integer::condition("JZ",flags)) goto L0075c306;
  }
  { // 0x75c2f9: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x75c2fb: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75c2fc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75c2fd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75c2fe: e85f2c0100 CALL 0x0076ef62
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x75c303: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0075c306: { // 0x75c306: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x75c308: 66b80100 MOV AX,0x1
    s.ax = with_ax(s.ax, 0x00000001u);
  }
  { // 0x75c30c: 66c7047a0000 MOV word ptr [EDX + EDI*0x2],0x0
    m.w16((s.dx+(s.di * 0x00000002u)), 0x00000000u);
  }
  { // 0x75c312: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75c313: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75c314: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0035ca00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75ca00: 83ec40 SUB ESP,0x40
    f.sp = integer::sub(f.sp,0x00000040u,32,flags);
  }
  { // 0x75ca03: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x75ca07: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75ca08: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x75ca09: 6830c57b00 PUSH 0x7bc530
    f.push(m,0x007bc530u);
  }
  { // 0x75ca0e: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75ca10: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75ca11: e88e260100 CALL 0x0076f0a4
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x75ca16: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x75ca1a: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x75ca1d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x75ca1f: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x75ca25: 7410 JZ 0x0075ca37
    if(integer::condition("JZ",flags)) goto L0075ca37;
  }
  { // 0x75ca27: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  { // 0x75ca2b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x75ca2c: e814250100 CALL 0x0076ef45
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x75ca31: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75ca34: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x75ca35: eb05 JMP 0x0075ca3c
    goto L0075ca3c;
  }
  L0075ca37: { // 0x75ca37: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0075ca3c: { // 0x75ca3c: 03c0 ADD EAX,EAX
    s.ax = integer::add(s.ax,s.ax,32,flags);
  }
  { // 0x75ca3e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75ca3f: e8130f0100 CALL 0x0076d957
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x75ca44: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x75ca48: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75ca4b: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x75ca4d: 66c7000000 MOV word ptr [EAX],0x0
    m.w16((s.ax), 0x00000000u);
  }
  { // 0x75ca52: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x75ca54: 7410 JZ 0x0075ca66
    if(integer::condition("JZ",flags)) goto L0075ca66;
  }
  { // 0x75ca56: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x75ca58: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  { // 0x75ca5c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x75ca5d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75ca5e: e866250100 CALL 0x0076efc9
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x75ca63: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0075ca66: { // 0x75ca66: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x75ca68: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75ca69: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  { // 0x75ca6c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00363590(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x763590: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x763591: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x763593: e838000000 CALL 0x007635d0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x763598: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x76359b: 752a JNZ 0x007635c7
    if(integer::condition("JNZ",flags)) goto L007635c7;
  }
  { // 0x76359d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x76359f: e88c050000 CALL 0x00763b30
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x7635a4: 8b86a0010000 MOV EAX,dword ptr [ESI + 0x1a0]
    s.ax = m.r32((s.si+0x000001a0u));
  }
  { // 0x7635aa: 8986dc060000 MOV dword ptr [ESI + 0x6dc],EAX
    m.w32((s.si+0x000006dcu), s.ax);
  }
  { // 0x7635b0: 8a8ea4010000 MOV CL,byte ptr [ESI + 0x1a4]
    s.cx = with_al(s.cx, m.r8((s.si+0x000001a4u)));
  }
  { // 0x7635b6: f6c108 TEST CL,0x8
    (void)integer::logical(((s.cx & 0xffu))&(0x00000008u),8,flags);
  }
  { // 0x7635b9: 7509 JNZ 0x007635c4
    if(integer::condition("JNZ",flags)) goto L007635c4;
  }
  { // 0x7635bb: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  { // 0x7635be: 8986a0010000 MOV dword ptr [ESI + 0x1a0],EAX
    m.w32((s.si+0x000001a0u), s.ax);
  }
  L007635c4: { // 0x7635c4: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L007635c7: { // 0x7635c7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7635c8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00363c90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x763c90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x763c91: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x763c93: e838f9ffff CALL 0x007635d0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x763c98: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x763c9b: 7534 JNZ 0x00763cd1
    if(integer::condition("JNZ",flags)) goto L00763cd1;
  }
  { // 0x763c9d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x763c9e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x763ca0: e88bfeffff CALL 0x00763b30
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x763ca5: 8bbea0010000 MOV EDI,dword ptr [ESI + 0x1a0]
    s.di = m.r32((s.si+0x000001a0u));
  }
  { // 0x763cab: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x763cad: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  { // 0x763caf: e8dcf7ffff CALL 0x00763490
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x763cb4: 89bedc060000 MOV dword ptr [ESI + 0x6dc],EDI
    m.w32((s.si+0x000006dcu), s.di);
  }
  { // 0x763cba: 8a86a4010000 MOV AL,byte ptr [ESI + 0x1a4]
    s.ax = with_al(s.ax, m.r8((s.si+0x000001a4u)));
  }
  { // 0x763cc0: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  { // 0x763cc2: 7509 JNZ 0x00763ccd
    if(integer::condition("JNZ",flags)) goto L00763ccd;
  }
  { // 0x763cc4: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  { // 0x763cc7: 8986a0010000 MOV dword ptr [ESI + 0x1a0],EAX
    m.w32((s.si+0x000001a0u), s.ax);
  }
  L00763ccd: { // 0x763ccd: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x763cd0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763cd1: { // 0x763cd1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x763cd2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036d5cc(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76d5cc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76d5cd: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x76d5cf: 6a1b PUSH 0x1b
    f.push(m,0x0000001bu);
  }
  { // 0x76d5d1: c706ccc57900 MOV dword ptr [ESI],0x79c5cc
    m.w32((s.si), 0x0079c5ccu);
  }
  { // 0x76d5d7: e8da3f0000 CALL 0x007715b6
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76d5dc: 8b7604 MOV ESI,dword ptr [ESI + 0x4]
    s.si = m.r32((s.si+0x00000004u));
  }
  { // 0x76d5df: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76d5e0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x76d5e2: 7407 JZ 0x0076d5eb
    if(integer::condition("JZ",flags)) goto L0076d5eb;
  }
  { // 0x76d5e4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76d5e5: e83e090000 CALL 0x0076df28
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76d5ea: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076d5eb: { // 0x76d5eb: 6a1b PUSH 0x1b
    f.push(m,0x0000001bu);
  }
  { // 0x76d5ed: e825400000 CALL 0x00771617
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x76d5f2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76d5f3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76d5f4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036d5f5(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76d5f5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76d5f6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x76d5f8: e8cfffffff CALL 0x0076d5cc
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76d5fd: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x76d602: 7407 JZ 0x0076d60b
    if(integer::condition("JZ",flags)) goto L0076d60b;
  }
  { // 0x76d604: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76d605: e871000000 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76d60a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076d60b: { // 0x76d60b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76d60d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76d60e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0036da34(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76da34: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x76da35: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x76da37: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x76da3a: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x76da3d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76da3e: 8945e8 MOV dword ptr [EBP + -0x18],EAX
    m.w32((s.bp-0x00000018u), s.ax);
  }
  { // 0x76da41: 8945e0 MOV dword ptr [EBP + -0x20],EAX
    m.w32((s.bp-0x00000020u), s.ax);
  }
  { // 0x76da44: 8d4510 LEA EAX,[EBP + 0x10]
    s.ax = (s.bp+0x00000010u);
  }
  { // 0x76da47: c745ec42000000 MOV dword ptr [EBP + -0x14],0x42
    m.w32((s.bp-0x00000014u), 0x00000042u);
  }
  { // 0x76da4e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76da4f: 8d45e0 LEA EAX,[EBP + -0x20]
    s.ax = (s.bp-0x00000020u);
  }
  { // 0x76da52: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x76da55: c745e4ffffff7f MOV dword ptr [EBP + -0x1c],0x7fffffff
    m.w32((s.bp-0x0000001cu), 0x7fffffffu);
  }
  { // 0x76da5c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76da5d: e803440000 CALL 0x00771e65
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76da62: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x76da65: ff4de4 DEC dword ptr [EBP + -0x1c]
    m.w32((s.bp-0x0000001cu), integer::decrement(m.r32((s.bp-0x0000001cu)),32,flags));
  }
  { // 0x76da68: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x76da6a: 7808 JS 0x0076da74
    if(integer::condition("JS",flags)) goto L0076da74;
  }
  { // 0x76da6c: 8b45e0 MOV EAX,dword ptr [EBP + -0x20]
    s.ax = m.r32((s.bp-0x00000020u));
  }
  { // 0x76da6f: 802000 AND byte ptr [EAX],0x0
    m.w8((s.ax), integer::logical((m.r8((s.ax)))&(0x00000000u),8,flags));
  }
  { // 0x76da72: eb0d JMP 0x0076da81
    goto L0076da81;
  }
  L0076da74: { // 0x76da74: 8d45e0 LEA EAX,[EBP + -0x20]
    s.ax = (s.bp-0x00000020u);
  }
  { // 0x76da77: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76da78: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x76da7a: e8ce420000 CALL 0x00771d4d
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76da7f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76da80: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076da81: { // 0x76da81: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76da83: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76da84: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x76da85: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036dffc(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76dffc: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x76dffd: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x76dfff: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76e000: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x76e003: e8311f0000 CALL 0x0076ff39
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76e008: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x76e00b: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x76e00e: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x76e011: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x76e014: e812000000 CALL 0x0076e02b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76e019: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x76e01c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x76e01e: e8681f0000 CALL 0x0076ff8b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x76e023: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  { // 0x76e026: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76e028: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76e029: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x76e02a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036e113(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76e113: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x76e114: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x76e116: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76e117: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x76e11a: e81a1e0000 CALL 0x0076ff39
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76e11f: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x76e122: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x76e125: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x76e128: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x76e12b: e812000000 CALL 0x0076e142
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76e130: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x76e133: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x76e135: e8511e0000 CALL 0x0076ff8b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x76e13a: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  { // 0x76e13d: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76e13f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76e140: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x76e141: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036e24c(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76e24c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76e24d: e86f260000 CALL 0x007708c1
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76e252: ff35380eb100 PUSH dword ptr [0x00b10e38]
    f.push(m,m.r32((0x00b10e38u)));
  }
  { // 0x76e258: e8e0690000 CALL 0x00774c3d
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76e25d: 8b15380eb100 MOV EDX,dword ptr [0x00b10e38]
    s.dx = m.r32((0x00b10e38u));
  }
  { // 0x76e263: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76e264: 8b0d340eb100 MOV ECX,dword ptr [0x00b10e34]
    s.cx = m.r32((0x00b10e34u));
  }
  { // 0x76e26a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x76e26c: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  { // 0x76e26e: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x76e271: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x76e273: 733d JNC 0x0076e2b2
    if(integer::condition("JNC",flags)) goto L0076e2b2;
  }
  { // 0x76e275: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x76e276: e8c2690000 CALL 0x00774c3d
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x76e27b: 83c010 ADD EAX,0x10
    s.ax = integer::add(s.ax,0x00000010u,32,flags);
  }
  { // 0x76e27e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76e27f: ff35380eb100 PUSH dword ptr [0x00b10e38]
    f.push(m,m.r32((0x00b10e38u)));
  }
  { // 0x76e285: e87b680000 CALL 0x00774b05
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x76e28a: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x76e28d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x76e28f: 7504 JNZ 0x0076e295
    if(integer::condition("JNZ",flags)) goto L0076e295;
  }
  { // 0x76e291: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x76e293: eb2c JMP 0x0076e2c1
    goto L0076e2c1;
  }
  L0076e295: { // 0x76e295: 8b0d340eb100 MOV ECX,dword ptr [0x00b10e34]
    s.cx = m.r32((0x00b10e34u));
  }
  { // 0x76e29b: 2b0d380eb100 SUB ECX,dword ptr [0x00b10e38]
    s.cx = integer::sub(s.cx,m.r32((0x00b10e38u)),32,flags);
  }
  { // 0x76e2a1: a3380eb100 MOV [0x00b10e38],EAX
    m.w32((0x00b10e38u), s.ax);
  }
  { // 0x76e2a6: c1f902 SAR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x76e2a9: 8d0c88 LEA ECX,[EAX + ECX*0x4]
    s.cx = (s.ax+(s.cx * 0x00000004u));
  }
  { // 0x76e2ac: 890d340eb100 MOV dword ptr [0x00b10e34],ECX
    m.w32((0x00b10e34u), s.cx);
  }
  L0076e2b2: { // 0x76e2b2: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x76e2b6: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  { // 0x76e2b8: 8305340eb10004 ADD dword ptr [0x00b10e34],0x4
    m.w32((0x00b10e34u), integer::add(m.r32((0x00b10e34u)),0x00000004u,32,flags));
  }
  { // 0x76e2bf: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0076e2c1: { // 0x76e2c1: e804260000 CALL 0x007708ca
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x76e2c6: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76e2c8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76e2c9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036f0a4(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f0a4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x76f0a5: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x76f0a7: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x76f0aa: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x76f0ad: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f0ae: 8945e8 MOV dword ptr [EBP + -0x18],EAX
    m.w32((s.bp-0x00000018u), s.ax);
  }
  { // 0x76f0b1: 8945e0 MOV dword ptr [EBP + -0x20],EAX
    m.w32((s.bp-0x00000020u), s.ax);
  }
  { // 0x76f0b4: 8d4510 LEA EAX,[EBP + 0x10]
    s.ax = (s.bp+0x00000010u);
  }
  { // 0x76f0b7: c745ec42000000 MOV dword ptr [EBP + -0x14],0x42
    m.w32((s.bp-0x00000014u), 0x00000042u);
  }
  { // 0x76f0be: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76f0bf: 8d45e0 LEA EAX,[EBP + -0x20]
    s.ax = (s.bp-0x00000020u);
  }
  { // 0x76f0c2: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x76f0c5: c745e4ffffff7f MOV dword ptr [EBP + -0x1c],0x7fffffff
    m.w32((s.bp-0x0000001cu), 0x7fffffffu);
  }
  { // 0x76f0cc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76f0cd: e8ac6c0000 CALL 0x00775d7e
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76f0d2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x76f0d5: ff4de4 DEC dword ptr [EBP + -0x1c]
    m.w32((s.bp-0x0000001cu), integer::decrement(m.r32((s.bp-0x0000001cu)),32,flags));
  }
  { // 0x76f0d8: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x76f0da: 780b JS 0x0076f0e7
    if(integer::condition("JS",flags)) goto L0076f0e7;
  }
  { // 0x76f0dc: 8b45e0 MOV EAX,dword ptr [EBP + -0x20]
    s.ax = m.r32((s.bp-0x00000020u));
  }
  { // 0x76f0df: 802000 AND byte ptr [EAX],0x0
    m.w8((s.ax), integer::logical((m.r8((s.ax)))&(0x00000000u),8,flags));
  }
  { // 0x76f0e2: ff45e0 INC dword ptr [EBP + -0x20]
    m.w32((s.bp-0x00000020u), integer::increment(m.r32((s.bp-0x00000020u)),32,flags));
  }
  { // 0x76f0e5: eb0d JMP 0x0076f0f4
    goto L0076f0f4;
  }
  L0076f0e7: { // 0x76f0e7: 8d45e0 LEA EAX,[EBP + -0x20]
    s.ax = (s.bp-0x00000020u);
  }
  { // 0x76f0ea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76f0eb: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x76f0ed: e85b2c0000 CALL 0x00771d4d
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76f0f2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76f0f3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076f0f4: { // 0x76f0f4: ff4de4 DEC dword ptr [EBP + -0x1c]
    m.w32((s.bp-0x0000001cu), integer::decrement(m.r32((s.bp-0x0000001cu)),32,flags));
  }
  { // 0x76f0f7: 7808 JS 0x0076f101
    if(integer::condition("JS",flags)) goto L0076f101;
  }
  { // 0x76f0f9: 8b45e0 MOV EAX,dword ptr [EBP + -0x20]
    s.ax = m.r32((s.bp-0x00000020u));
  }
  { // 0x76f0fc: 802000 AND byte ptr [EAX],0x0
    m.w8((s.ax), integer::logical((m.r8((s.ax)))&(0x00000000u),8,flags));
  }
  { // 0x76f0ff: eb0d JMP 0x0076f10e
    goto L0076f10e;
  }
  L0076f101: { // 0x76f101: 8d45e0 LEA EAX,[EBP + -0x20]
    s.ax = (s.bp-0x00000020u);
  }
  { // 0x76f104: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76f105: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x76f107: e8412c0000 CALL 0x00771d4d
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x76f10c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76f10d: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076f10e: { // 0x76f10e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76f110: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f111: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x76f112: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036f29b(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f29b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f29c: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x76f2a0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76f2a1: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  { // 0x76f2a4: f6460c40 TEST byte ptr [ESI + 0xc],0x40
    (void)integer::logical((m.r8((s.si+0x0000000cu)))&(0x00000040u),8,flags);
  }
  { // 0x76f2a8: 7406 JZ 0x0076f2b0
    if(integer::condition("JZ",flags)) goto L0076f2b0;
  }
  { // 0x76f2aa: 83660c00 AND dword ptr [ESI + 0xc],0x0
    m.w32((s.si+0x0000000cu), integer::logical((m.r32((s.si+0x0000000cu)))&(0x00000000u),32,flags));
  }
  { // 0x76f2ae: eb17 JMP 0x0076f2c7
    goto L0076f2c7;
  }
  L0076f2b0: { // 0x76f2b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f2b1: e8830c0000 CALL 0x0076ff39
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76f2b6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f2b7: e810000000 CALL 0x0076f2cc
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76f2bc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f2bd: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x76f2bf: e8c70c0000 CALL 0x0076ff8b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x76f2c4: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076f2c7: { // 0x76f2c7: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x76f2c9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x76f2ca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f2cb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036f2cc(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f2cc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f2cd: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x76f2d1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76f2d2: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  { // 0x76f2d5: f6460c83 TEST byte ptr [ESI + 0xc],0x83
    (void)integer::logical((m.r8((s.si+0x0000000cu)))&(0x00000083u),8,flags);
  }
  { // 0x76f2d9: 7434 JZ 0x0076f30f
    if(integer::condition("JZ",flags)) goto L0076f30f;
  }
  { // 0x76f2db: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f2dc: e8580a0000 CALL 0x0076fd39
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76f2e1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f2e2: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x76f2e4: e82b740000 CALL 0x00776714
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76f2e9: ff7610 PUSH dword ptr [ESI + 0x10]
    f.push(m,m.r32((s.si+0x00000010u)));
  }
  { // 0x76f2ec: e843730000 CALL 0x00776634
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x76f2f1: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x76f2f4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x76f2f6: 7d05 JGE 0x0076f2fd
    if(integer::condition("JGE",flags)) goto L0076f2fd;
  }
  { // 0x76f2f8: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  { // 0x76f2fb: eb12 JMP 0x0076f30f
    goto L0076f30f;
  }
  L0076f2fd: { // 0x76f2fd: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  { // 0x76f300: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x76f302: 740b JZ 0x0076f30f
    if(integer::condition("JZ",flags)) goto L0076f30f;
  }
  { // 0x76f304: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76f305: e81eecffff CALL 0x0076df28
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x76f30a: 83661c00 AND dword ptr [ESI + 0x1c],0x0
    m.w32((s.si+0x0000001cu), integer::logical((m.r32((s.si+0x0000001cu)))&(0x00000000u),32,flags));
  }
  { // 0x76f30e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076f30f: { // 0x76f30f: 83660c00 AND dword ptr [ESI + 0xc],0x0
    m.w32((s.si+0x0000000cu), integer::logical((m.r32((s.si+0x0000000cu)))&(0x00000000u),32,flags));
  }
  { // 0x76f313: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x76f315: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x76f316: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f317: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036f318(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f318: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x76f319: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f31a: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x76f31e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76f31f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f320: e8140c0000 CALL 0x0076ff39
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76f325: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f326: e814740000 CALL 0x0077673f
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76f32b: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x76f32d: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  { // 0x76f331: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76f332: ff742420 PUSH dword ptr [ESP + 0x20]
    f.push(m,m.r32((f.sp+0x00000020u)));
  }
  { // 0x76f336: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f337: e8292b0000 CALL 0x00771e65
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x76f33c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f33d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76f33e: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x76f340: e887740000 CALL 0x007767cc
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x76f345: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f346: e8400c0000 CALL 0x0076ff8b
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x76f34b: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x76f34e: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x76f350: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x76f351: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f352: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x76f353: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036f354(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f354: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f355: e80c760000 CALL 0x00776966
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76f35a: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x76f35c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x76f35e: 7502 JNZ 0x0076f362
    if(integer::condition("JNZ",flags)) goto L0076f362;
  }
  { // 0x76f360: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f361: c3 RET
    finish(m,s,f,0u); return;
  }
  L0076f362: { // 0x76f362: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76f363: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f364: ff742418 PUSH dword ptr [ESP + 0x18]
    f.push(m,m.r32((f.sp+0x00000018u)));
  }
  { // 0x76f368: ff742418 PUSH dword ptr [ESP + 0x18]
    f.push(m,m.r32((f.sp+0x00000018u)));
  }
  { // 0x76f36c: ff742418 PUSH dword ptr [ESP + 0x18]
    f.push(m,m.r32((f.sp+0x00000018u)));
  }
  { // 0x76f370: e881740000 CALL 0x007767f6
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76f375: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f376: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x76f378: e80e0c0000 CALL 0x0076ff8b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x76f37d: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x76f380: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x76f382: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x76f383: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f384: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036f398(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f398: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x76f399: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x76f39b: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x76f39e: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x76f3a1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f3a2: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x76f3a5: 8945e8 MOV dword ptr [EBP + -0x18],EAX
    m.w32((s.bp-0x00000018u), s.ax);
  }
  { // 0x76f3a8: 8945e0 MOV dword ptr [EBP + -0x20],EAX
    m.w32((s.bp-0x00000020u), s.ax);
  }
  { // 0x76f3ab: 8d45e0 LEA EAX,[EBP + -0x20]
    s.ax = (s.bp-0x00000020u);
  }
  { // 0x76f3ae: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x76f3b1: c745ec42000000 MOV dword ptr [EBP + -0x14],0x42
    m.w32((s.bp-0x00000014u), 0x00000042u);
  }
  { // 0x76f3b8: c745e4ffffff7f MOV dword ptr [EBP + -0x1c],0x7fffffff
    m.w32((s.bp-0x0000001cu), 0x7fffffffu);
  }
  { // 0x76f3bf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76f3c0: e8b9690000 CALL 0x00775d7e
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76f3c5: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x76f3c8: ff4de4 DEC dword ptr [EBP + -0x1c]
    m.w32((s.bp-0x0000001cu), integer::decrement(m.r32((s.bp-0x0000001cu)),32,flags));
  }
  { // 0x76f3cb: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x76f3cd: 780b JS 0x0076f3da
    if(integer::condition("JS",flags)) goto L0076f3da;
  }
  { // 0x76f3cf: 8b45e0 MOV EAX,dword ptr [EBP + -0x20]
    s.ax = m.r32((s.bp-0x00000020u));
  }
  { // 0x76f3d2: 802000 AND byte ptr [EAX],0x0
    m.w8((s.ax), integer::logical((m.r8((s.ax)))&(0x00000000u),8,flags));
  }
  { // 0x76f3d5: ff45e0 INC dword ptr [EBP + -0x20]
    m.w32((s.bp-0x00000020u), integer::increment(m.r32((s.bp-0x00000020u)),32,flags));
  }
  { // 0x76f3d8: eb0d JMP 0x0076f3e7
    goto L0076f3e7;
  }
  L0076f3da: { // 0x76f3da: 8d45e0 LEA EAX,[EBP + -0x20]
    s.ax = (s.bp-0x00000020u);
  }
  { // 0x76f3dd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76f3de: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x76f3e0: e868290000 CALL 0x00771d4d
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76f3e5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76f3e6: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076f3e7: { // 0x76f3e7: ff4de4 DEC dword ptr [EBP + -0x1c]
    m.w32((s.bp-0x0000001cu), integer::decrement(m.r32((s.bp-0x0000001cu)),32,flags));
  }
  { // 0x76f3ea: 7808 JS 0x0076f3f4
    if(integer::condition("JS",flags)) goto L0076f3f4;
  }
  { // 0x76f3ec: 8b45e0 MOV EAX,dword ptr [EBP + -0x20]
    s.ax = m.r32((s.bp-0x00000020u));
  }
  { // 0x76f3ef: 802000 AND byte ptr [EAX],0x0
    m.w8((s.ax), integer::logical((m.r8((s.ax)))&(0x00000000u),8,flags));
  }
  { // 0x76f3f2: eb0d JMP 0x0076f401
    goto L0076f401;
  }
  L0076f3f4: { // 0x76f3f4: 8d45e0 LEA EAX,[EBP + -0x20]
    s.ax = (s.bp-0x00000020u);
  }
  { // 0x76f3f7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76f3f8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x76f3fa: e84e290000 CALL 0x00771d4d
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x76f3ff: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76f400: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076f401: { // 0x76f401: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76f403: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f404: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x76f405: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036f4d3(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f4d3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f4d4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x76f4d6: e814000000 CALL 0x0076f4ef
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76f4db: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x76f4e0: 7407 JZ 0x0076f4e9
    if(integer::condition("JZ",flags)) goto L0076f4e9;
  }
  { // 0x76f4e2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f4e3: e893e1ffff CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76f4e8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076f4e9: { // 0x76f4e9: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76f4eb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f4ec: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0036f524(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f524: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f525: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x76f527: e814000000 CALL 0x0076f540
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76f52c: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x76f531: 7407 JZ 0x0076f53a
    if(integer::condition("JZ",flags)) goto L0076f53a;
  }
  { // 0x76f533: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f534: e842e1ffff CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76f539: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076f53a: { // 0x76f53a: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76f53c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f53d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0036f753(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f753: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f754: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x76f756: e814000000 CALL 0x0076f76f
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76f75b: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x76f760: 7407 JZ 0x0076f769
    if(integer::condition("JZ",flags)) goto L0076f769;
  }
  { // 0x76f762: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f763: e813dfffff CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76f768: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076f769: { // 0x76f769: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76f76b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f76c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0036fcdc(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76fcdc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fcdd: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x76fce1: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x76fce3: 7509 JNZ 0x0076fcee
    if(integer::condition("JNZ",flags)) goto L0076fcee;
  }
  { // 0x76fce5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fce6: e8b3000000 CALL 0x0076fd9e
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76fceb: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76fcec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76fced: c3 RET
    finish(m,s,f,0u); return;
  }
  L0076fcee: { // 0x76fcee: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76fcef: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fcf0: e844020000 CALL 0x0076ff39
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76fcf5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fcf6: e810000000 CALL 0x0076fd0b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x76fcfb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fcfc: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x76fcfe: e888020000 CALL 0x0076ff8b
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x76fd03: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x76fd06: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x76fd08: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x76fd09: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76fd0a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036fd0b(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76fd0b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fd0c: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x76fd10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76fd11: e823000000 CALL 0x0076fd39
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x76fd16: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x76fd18: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76fd19: 7405 JZ 0x0076fd20
    if(integer::condition("JZ",flags)) goto L0076fd20;
  }
  { // 0x76fd1b: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x76fd1e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76fd1f: c3 RET
    finish(m,s,f,0u); return;
  }
  L0076fd20: { // 0x76fd20: f6460d40 TEST byte ptr [ESI + 0xd],0x40
    (void)integer::logical((m.r8((s.si+0x0000000du)))&(0x00000040u),8,flags);
  }
  { // 0x76fd24: 740f JZ 0x0076fd35
    if(integer::condition("JZ",flags)) goto L0076fd35;
  }
  { // 0x76fd26: ff7610 PUSH dword ptr [ESI + 0x10]
    f.push(m,m.r32((s.si+0x00000010u)));
  }
  { // 0x76fd29: e8636f0000 CALL 0x00776c91
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x76fd2e: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x76fd30: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76fd31: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76fd32: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x76fd34: c3 RET
    finish(m,s,f,0u); return;
  }
  L0076fd35: { // 0x76fd35: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x76fd37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76fd38: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003702ba(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7702ba: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7702bb: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7702bd: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x7702c0: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x7702c3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7702c4: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x7702c7: 8945e8 MOV dword ptr [EBP + -0x18],EAX
    m.w32((s.bp-0x00000018u), s.ax);
  }
  { // 0x7702ca: 8945e0 MOV dword ptr [EBP + -0x20],EAX
    m.w32((s.bp-0x00000020u), s.ax);
  }
  { // 0x7702cd: 8d45e0 LEA EAX,[EBP + -0x20]
    s.ax = (s.bp-0x00000020u);
  }
  { // 0x7702d0: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x7702d3: c745ec42000000 MOV dword ptr [EBP + -0x14],0x42
    m.w32((s.bp-0x00000014u), 0x00000042u);
  }
  { // 0x7702da: c745e4ffffff7f MOV dword ptr [EBP + -0x1c],0x7fffffff
    m.w32((s.bp-0x0000001cu), 0x7fffffffu);
  }
  { // 0x7702e1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7702e2: e87e1b0000 CALL 0x00771e65
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x7702e7: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x7702ea: ff4de4 DEC dword ptr [EBP + -0x1c]
    m.w32((s.bp-0x0000001cu), integer::decrement(m.r32((s.bp-0x0000001cu)),32,flags));
  }
  { // 0x7702ed: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x7702ef: 7808 JS 0x007702f9
    if(integer::condition("JS",flags)) goto L007702f9;
  }
  { // 0x7702f1: 8b45e0 MOV EAX,dword ptr [EBP + -0x20]
    s.ax = m.r32((s.bp-0x00000020u));
  }
  { // 0x7702f4: 802000 AND byte ptr [EAX],0x0
    m.w8((s.ax), integer::logical((m.r8((s.ax)))&(0x00000000u),8,flags));
  }
  { // 0x7702f7: eb0d JMP 0x00770306
    goto L00770306;
  }
  L007702f9: { // 0x7702f9: 8d45e0 LEA EAX,[EBP + -0x20]
    s.ax = (s.bp-0x00000020u);
  }
  { // 0x7702fc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7702fd: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x7702ff: e8491a0000 CALL 0x00771d4d
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x770304: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770305: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00770306: { // 0x770306: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x770308: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x770309: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77030a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037030b(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77030b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77030c: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x770310: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x770311: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770312: e822fcffff CALL 0x0076ff39
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x770317: ff4e04 DEC dword ptr [ESI + 0x4]
    m.w32((s.si+0x00000004u), integer::decrement(m.r32((s.si+0x00000004u)),32,flags));
  }
  { // 0x77031a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77031b: 780a JS 0x00770327
    if(integer::condition("JS",flags)) goto L00770327;
  }
  { // 0x77031d: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x77031f: 0fb638 MOVZX EDI,byte ptr [EAX]
    s.di = (m.r8((s.ax))&integer::mask(8));
  }
  { // 0x770322: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x770323: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x770325: eb09 JMP 0x00770330
    goto L00770330;
  }
  L00770327: { // 0x770327: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770328: e8963f0000 CALL 0x007742c3
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77032d: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77032e: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00770330: { // 0x770330: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770331: e855fcffff CALL 0x0076ff8b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x770336: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770337: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x770339: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77033a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77033b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037068d(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77068d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77068e: 6a19 PUSH 0x19
    f.push(m,0x00000019u);
  }
  { // 0x770690: e8210f0000 CALL 0x007715b6
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x770695: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x770699: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x77069b: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x77069d: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x77069e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7706a0: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7706a1: 742c JZ 0x007706cf
    if(integer::condition("JZ",flags)) goto L007706cf;
  }
  { // 0x7706a3: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L007706a7: { // 0x7706a7: 8a08 MOV CL,byte ptr [EAX]
    s.cx = with_al(s.cx, m.r8((s.ax)));
  }
  { // 0x7706a9: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x7706ab: 7422 JZ 0x007706cf
    if(integer::condition("JZ",flags)) goto L007706cf;
  }
  { // 0x7706ad: 0fb6c9 MOVZX ECX,CL
    s.cx = ((s.cx & 0xffu)&integer::mask(8));
  }
  { // 0x7706b0: f681e10bb10004 TEST byte ptr [ECX + 0xb10be1],0x4
    (void)integer::logical((m.r8((s.cx+0x00b10be1u)))&(0x00000004u),8,flags);
  }
  { // 0x7706b7: 740d JZ 0x007706c6
    if(integer::condition("JZ",flags)) goto L007706c6;
  }
  { // 0x7706b9: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  { // 0x7706bb: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x7706bc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x7706be: 740f JZ 0x007706cf
    if(integer::condition("JZ",flags)) goto L007706cf;
  }
  { // 0x7706c0: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x7706c1: 803800 CMP byte ptr [EAX],0x0
    (void)integer::sub(m.r8((s.ax)),0x00000000u,8,flags);
  }
  { // 0x7706c4: 7409 JZ 0x007706cf
    if(integer::condition("JZ",flags)) goto L007706cf;
  }
  L007706c6: { // 0x7706c6: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x7706c7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x7706c8: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  { // 0x7706ca: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x7706cb: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x7706cd: 75d8 JNZ 0x007706a7
    if(integer::condition("JNZ",flags)) goto L007706a7;
  }
  L007706cf: { // 0x7706cf: 6a19 PUSH 0x19
    f.push(m,0x00000019u);
  }
  { // 0x7706d1: e8410f0000 CALL 0x00771617
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x7706d6: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7706d7: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x7706d9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7706da: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003706db(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7706db: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7706dc: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7706de: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x7706e1: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x7706e4: c745ec49000000 MOV dword ptr [EBP + -0x14],0x49
    m.w32((s.bp-0x00000014u), 0x00000049u);
  }
  { // 0x7706eb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7706ec: 8945e8 MOV dword ptr [EBP + -0x18],EAX
    m.w32((s.bp-0x00000018u), s.ax);
  }
  { // 0x7706ef: 8945e0 MOV dword ptr [EBP + -0x20],EAX
    m.w32((s.bp-0x00000020u), s.ax);
  }
  { // 0x7706f2: e84ee8ffff CALL 0x0076ef45
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x7706f7: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  { // 0x7706f9: 8945e4 MOV dword ptr [EBP + -0x1c],EAX
    m.w32((s.bp-0x0000001cu), s.ax);
  }
  { // 0x7706fc: 8d4510 LEA EAX,[EBP + 0x10]
    s.ax = (s.bp+0x00000010u);
  }
  { // 0x7706ff: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x770700: 8d45e0 LEA EAX,[EBP + -0x20]
    s.ax = (s.bp-0x00000020u);
  }
  { // 0x770703: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x770706: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x770707: e8216f0000 CALL 0x0077762d
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77070c: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x77070f: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x770710: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00370711(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x770711: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770712: 6a0c PUSH 0xc
    f.push(m,0x0000000cu);
  }
  { // 0x770714: e89d0e0000 CALL 0x007715b6
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x770719: ff74240c PUSH dword ptr [ESP + 0xc]
    f.push(m,m.r32((f.sp+0x0000000cu)));
  }
  { // 0x77071d: e810000000 CALL 0x00770732
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x770722: 6a0c PUSH 0xc
    f.push(m,0x0000000cu);
  }
  { // 0x770724: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x770726: e8ec0e0000 CALL 0x00771617
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x77072b: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77072e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x770730: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x770731: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00371101(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x771101: 837c240400 CMP dword ptr [ESP + 0x4],0x0
    (void)integer::sub(m.r32((f.sp+0x00000004u)),0x00000000u,32,flags);
  }
  { // 0x771106: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x771107: be9804b100 MOV ESI,0xb10498
    s.si = 0x00b10498u;
  }
  { // 0x77110c: 7405 JZ 0x00771113
    if(integer::condition("JZ",flags)) goto L00771113;
  }
  { // 0x77110e: bea804b100 MOV ESI,0xb104a8
    s.si = 0x00b104a8u;
  }
  L00771113: { // 0x771113: 68d4787b00 PUSH 0x7b78d4
    f.push(m,0x007b78d4u);
  }
  { // 0x771118: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x771119: e8f27e0000 CALL 0x00779010
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x77111e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77111f: 8d4601 LEA EAX,[ESI + 0x1]
    s.ax = (s.si+0x00000001u);
  }
  { // 0x771122: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x771123: 8a48ff MOV CL,byte ptr [EAX + -0x1]
    s.cx = with_al(s.cx, m.r8((s.ax-0x00000001u)));
  }
  { // 0x771126: 80f95c CMP CL,0x5c
    (void)integer::sub((s.cx & 0xffu),0x0000005cu,8,flags);
  }
  { // 0x771129: 7409 JZ 0x00771134
    if(integer::condition("JZ",flags)) goto L00771134;
  }
  { // 0x77112b: 80f92f CMP CL,0x2f
    (void)integer::sub((s.cx & 0xffu),0x0000002fu,8,flags);
  }
  { // 0x77112e: 7404 JZ 0x00771134
    if(integer::condition("JZ",flags)) goto L00771134;
  }
  { // 0x771130: c6005c MOV byte ptr [EAX],0x5c
    m.w8((s.ax), 0x0000005cu);
  }
  { // 0x771133: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00771134: { // 0x771134: 837c240800 CMP dword ptr [ESP + 0x8],0x0
    (void)integer::sub(m.r32((f.sp+0x00000008u)),0x00000000u,32,flags);
  }
  { // 0x771139: 7405 JZ 0x00771140
    if(integer::condition("JZ",flags)) goto L00771140;
  }
  { // 0x77113b: c60074 MOV byte ptr [EAX],0x74
    m.w8((s.ax), 0x00000074u);
  }
  { // 0x77113e: eb03 JMP 0x00771143
    goto L00771143;
  }
  L00771140: { // 0x771140: c60073 MOV byte ptr [EAX],0x73
    m.w8((s.ax), 0x00000073u);
  }
  L00771143: { // 0x771143: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x771144: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x771146: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x771147: e8ab840000 CALL 0x007795f7
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77114c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77114d: e8b8830000 CALL 0x0077950a
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x771152: 688c6c7c00 PUSH 0x7c6c8c
    f.push(m,0x007c6c8cu);
  }
  { // 0x771157: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x771158: e8c37e0000 CALL 0x00779020
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x77115d: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x771160: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x771161: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00371162(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x771162: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x771163: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x771165: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x771166: 6a2e PUSH 0x2e
    f.push(m,0x0000002eu);
  }
  { // 0x771168: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x77116b: e88d840000 CALL 0x007795fd
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x771170: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x771172: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x771174: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x771175: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x771177: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x771178: e89cd9ffff CALL 0x0076eb19
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77117d: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x771180: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x771181: 3dff7f0000 CMP EAX,0x7fff
    (void)integer::sub(s.ax,0x00007fffu,32,flags);
  }
  { // 0x771186: 7205 JC 0x0077118d
    if(integer::condition("JC",flags)) goto L0077118d;
  }
  { // 0x771188: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x77118b: eb18 JMP 0x007711a5
    goto L007711a5;
  }
  L0077118d: { // 0x77118d: 8d4d08 LEA ECX,[EBP + 0x8]
    s.cx = (s.bp+0x00000008u);
  }
  { // 0x771190: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x771192: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x771193: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x771194: e871830000 CALL 0x0077950a
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x771199: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77119a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77119b: e8707e0000 CALL 0x00779010
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x7711a0: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x7711a3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L007711a5: { // 0x7711a5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7711a6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x7711a7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003711af(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7711af: ff742404 PUSH dword ptr [ESP + 0x4]
    f.push(m,m.r32((f.sp+0x00000004u)));
  }
  { // 0x7711b3: e816860000 CALL 0x007797ce
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x7711b8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7711ba: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7711bb: 7408 JZ 0x007711c5
    if(integer::condition("JZ",flags)) goto L007711c5;
  }
  { // 0x7711bd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7711be: e819850000 CALL 0x007796dc
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x7711c3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7711c4: c3 RET
    finish(m,s,f,0u); return;
  }
  L007711c5: { // 0x7711c5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x7711c7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00371cfa(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x771cfa: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x771cfb: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x771cff: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x771d00: ff74240c PUSH dword ptr [ESP + 0xc]
    f.push(m,m.r32((f.sp+0x0000000cu)));
  }
  { // 0x771d04: e807730000 CALL 0x00779010
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x771d09: 807e4000 CMP byte ptr [ESI + 0x40],0x0
    (void)integer::sub(m.r8((s.si+0x00000040u)),0x00000000u,8,flags);
  }
  { // 0x771d0d: 8d4640 LEA EAX,[ESI + 0x40]
    s.ax = (s.si+0x00000040u);
  }
  { // 0x771d10: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x771d11: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x771d12: 7414 JZ 0x00771d28
    if(integer::condition("JZ",flags)) goto L00771d28;
  }
  { // 0x771d14: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x771d15: 68c0a67b00 PUSH 0x7ba6c0
    f.push(m,0x007ba6c0u);
  }
  { // 0x771d1a: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x771d1c: ff742414 PUSH dword ptr [ESP + 0x14]
    f.push(m,m.r32((f.sp+0x00000014u)));
  }
  { // 0x771d20: e8e4feffff CALL 0x00771c09
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x771d25: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00771d28: { // 0x771d28: 80be8000000000 CMP byte ptr [ESI + 0x80],0x0
    (void)integer::sub(m.r8((s.si+0x00000080u)),0x00000000u,8,flags);
  }
  { // 0x771d2f: 8d8680000000 LEA EAX,[ESI + 0x80]
    s.ax = (s.si+0x00000080u);
  }
  { // 0x771d35: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x771d36: 7414 JZ 0x00771d4c
    if(integer::condition("JZ",flags)) goto L00771d4c;
  }
  { // 0x771d38: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x771d39: 688c6c7c00 PUSH 0x7c6c8c
    f.push(m,0x007c6c8cu);
  }
  { // 0x771d3e: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x771d40: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x771d44: e8c0feffff CALL 0x00771c09
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x771d49: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00771d4c: { // 0x771d4c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003727a8(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7727a8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7727a9: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7727ab: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7727ac: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7727ad: 837d0800 CMP dword ptr [EBP + 0x8],0x0
    (void)integer::sub(m.r32((s.bp+0x00000008u)),0x00000000u,32,flags);
  }
  { // 0x7727b1: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x7727b4: 741b JZ 0x007727d1
    if(integer::condition("JZ",flags)) goto L007727d1;
  }
  { // 0x7727b6: 8d45f8 LEA EAX,[EBP + -0x8]
    s.ax = (s.bp-0x00000008u);
  }
  { // 0x7727b9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7727ba: e842950000 CALL 0x0077bd01
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x7727bf: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x7727c2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7727c3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7727c4: 8b4df8 MOV ECX,dword ptr [EBP + -0x8]
    s.cx = m.r32((s.bp-0x00000008u));
  }
  { // 0x7727c7: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x7727c9: 8b4dfc MOV ECX,dword ptr [EBP + -0x4]
    s.cx = m.r32((s.bp-0x00000004u));
  }
  { // 0x7727cc: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  { // 0x7727cf: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x7727d0: c3 RET
    finish(m,s,f,0u); return;
  }
  L007727d1: { // 0x7727d1: 8d4510 LEA EAX,[EBP + 0x10]
    s.ax = (s.bp+0x00000010u);
  }
  { // 0x7727d4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7727d5: e882950000 CALL 0x0077bd5c
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x7727da: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x7727dd: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7727de: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7727df: 8b4d10 MOV ECX,dword ptr [EBP + 0x10]
    s.cx = m.r32((s.bp+0x00000010u));
  }
  { // 0x7727e2: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x7727e4: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x7727e5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00372a98(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x772a98: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x772a99: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x772a9b: 837d1065 CMP dword ptr [EBP + 0x10],0x65
    (void)integer::sub(m.r32((s.bp+0x00000010u)),0x00000065u,32,flags);
  }
  { // 0x772a9f: 7432 JZ 0x00772ad3
    if(integer::condition("JZ",flags)) goto L00772ad3;
  }
  { // 0x772aa1: 837d1045 CMP dword ptr [EBP + 0x10],0x45
    (void)integer::sub(m.r32((s.bp+0x00000010u)),0x00000045u,32,flags);
  }
  { // 0x772aa5: 742c JZ 0x00772ad3
    if(integer::condition("JZ",flags)) goto L00772ad3;
  }
  { // 0x772aa7: 837d1066 CMP dword ptr [EBP + 0x10],0x66
    (void)integer::sub(m.r32((s.bp+0x00000010u)),0x00000066u,32,flags);
  }
  { // 0x772aab: 7513 JNZ 0x00772ac0
    if(integer::condition("JNZ",flags)) goto L00772ac0;
  }
  { // 0x772aad: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x772ab0: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x772ab3: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x772ab6: e84efeffff CALL 0x00772909
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x772abb: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x772abe: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x772abf: c3 RET
    finish(m,s,f,0u); return;
  }
  L00772ac0: { // 0x772ac0: ff7518 PUSH dword ptr [EBP + 0x18]
    f.push(m,m.r32((s.bp+0x00000018u)));
  }
  { // 0x772ac3: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x772ac6: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x772ac9: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x772acc: e834ffffff CALL 0x00772a05
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x772ad1: eb11 JMP 0x00772ae4
    goto L00772ae4;
  }
  L00772ad3: { // 0x772ad3: ff7518 PUSH dword ptr [EBP + 0x18]
    f.push(m,m.r32((s.bp+0x00000018u)));
  }
  { // 0x772ad6: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x772ad9: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x772adc: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x772adf: e802fdffff CALL 0x007727e6
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  L00772ae4: { // 0x772ae4: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x772ae7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x772ae8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00372ae9(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x772ae9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x772aea: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x772aee: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x772af0: 741a JZ 0x00772b0c
    if(integer::condition("JZ",flags)) goto L00772b0c;
  }
  { // 0x772af2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x772af3: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x772af7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x772af8: e863260000 CALL 0x00775160
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x772afd: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x772afe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x772aff: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x772b00: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  { // 0x772b02: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x772b03: e8c8c0ffff CALL 0x0076ebd0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x772b08: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x772b0b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00772b0c: { // 0x772b0c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x772b0d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037439f(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77439f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7743a0: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x7743a4: 3b35000eb100 CMP ESI,dword ptr [0x00b10e00]
    (void)integer::sub(s.si,m.r32((0x00b10e00u)),32,flags);
  }
  { // 0x7743aa: 7340 JNC 0x007743ec
    if(integer::condition("JNC",flags)) goto L007743ec;
  }
  { // 0x7743ac: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x7743ae: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x7743b0: c1f905 SAR ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x7743b3: 83e01f AND EAX,0x1f
    s.ax = integer::logical((s.ax)&(0x0000001fu),32,flags);
  }
  { // 0x7743b6: 8b0c8d000db100 MOV ECX,dword ptr [ECX*0x4 + 0xb10d00]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x00b10d00u));
  }
  { // 0x7743bd: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x7743c0: f644810401 TEST byte ptr [ECX + EAX*0x4 + 0x4],0x1
    (void)integer::logical((m.r8((s.cx+(s.ax * 0x00000004u)+0x00000004u)))&(0x00000001u),8,flags);
  }
  { // 0x7743c5: 7425 JZ 0x007743ec
    if(integer::condition("JZ",flags)) goto L007743ec;
  }
  { // 0x7743c7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7743c8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7743c9: e860910000 CALL 0x0077d52e
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x7743ce: ff742418 PUSH dword ptr [ESP + 0x18]
    f.push(m,m.r32((f.sp+0x00000018u)));
  }
  { // 0x7743d2: ff742418 PUSH dword ptr [ESP + 0x18]
    f.push(m,m.r32((f.sp+0x00000018u)));
  }
  { // 0x7743d6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7743d7: e828000000 CALL 0x00774404
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x7743dc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7743dd: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x7743df: e8a9910000 CALL 0x0077d58d
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x7743e4: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x7743e7: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x7743e9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7743ea: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7743eb: c3 RET
    finish(m,s,f,0u); return;
  }
  L007743ec: { // 0x7743ec: e85d0e0000 CALL 0x0077524e
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x7743f1: c70009000000 MOV dword ptr [EAX],0x9
    m.w32((s.ax), 0x00000009u);
  }
  { // 0x7743f7: e85b0e0000 CALL 0x00775257
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x7743fc: 832000 AND dword ptr [EAX],0x0
    m.w32((s.ax), integer::logical((m.r32((s.ax)))&(0x00000000u),32,flags));
  }
  { // 0x7743ff: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x774402: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x774403: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00374915(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x774915: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x774916: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x77491a: 3b35000eb100 CMP ESI,dword ptr [0x00b10e00]
    (void)integer::sub(s.si,m.r32((0x00b10e00u)),32,flags);
  }
  { // 0x774920: 7340 JNC 0x00774962
    if(integer::condition("JNC",flags)) goto L00774962;
  }
  { // 0x774922: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x774924: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x774926: c1f905 SAR ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x774929: 83e01f AND EAX,0x1f
    s.ax = integer::logical((s.ax)&(0x0000001fu),32,flags);
  }
  { // 0x77492c: 8b0c8d000db100 MOV ECX,dword ptr [ECX*0x4 + 0xb10d00]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x00b10d00u));
  }
  { // 0x774933: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x774936: f644810401 TEST byte ptr [ECX + EAX*0x4 + 0x4],0x1
    (void)integer::logical((m.r8((s.cx+(s.ax * 0x00000004u)+0x00000004u)))&(0x00000001u),8,flags);
  }
  { // 0x77493b: 7425 JZ 0x00774962
    if(integer::condition("JZ",flags)) goto L00774962;
  }
  { // 0x77493d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77493e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77493f: e8ea8b0000 CALL 0x0077d52e
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x774944: ff742418 PUSH dword ptr [ESP + 0x18]
    f.push(m,m.r32((f.sp+0x00000018u)));
  }
  { // 0x774948: ff742418 PUSH dword ptr [ESP + 0x18]
    f.push(m,m.r32((f.sp+0x00000018u)));
  }
  { // 0x77494c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77494d: e828000000 CALL 0x0077497a
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x774952: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x774953: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x774955: e8338c0000 CALL 0x0077d58d
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x77495a: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x77495d: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x77495f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x774960: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x774961: c3 RET
    finish(m,s,f,0u); return;
  }
  L00774962: { // 0x774962: e8e7080000 CALL 0x0077524e
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x774967: c70009000000 MOV dword ptr [EAX],0x9
    m.w32((s.ax), 0x00000009u);
  }
  { // 0x77496d: e8e5080000 CALL 0x00775257
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x774972: 832000 AND dword ptr [EAX],0x0
    m.w32((s.ax), integer::logical((m.r32((s.ax)))&(0x00000000u),32,flags));
  }
  { // 0x774975: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x774978: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x774979: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003751db(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7751db: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7751dc: e876000000 CALL 0x00775257
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x7751e1: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x7751e5: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x7751e7: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x7751e9: b880778100 MOV EAX,0x817780
    s.ax = 0x00817780u;
  }
  L007751ee: { // 0x7751ee: 3b08 CMP ECX,dword ptr [EAX]
    (void)integer::sub(s.cx,m.r32((s.ax)),32,flags);
  }
  { // 0x7751f0: 7422 JZ 0x00775214
    if(integer::condition("JZ",flags)) goto L00775214;
  }
  { // 0x7751f2: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  { // 0x7751f5: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x7751f6: 3de8788100 CMP EAX,0x8178e8
    (void)integer::sub(s.ax,0x008178e8u,32,flags);
  }
  { // 0x7751fb: 7cf1 JL 0x007751ee
    if(integer::condition("JL",flags)) goto L007751ee;
  }
  { // 0x7751fd: 83f913 CMP ECX,0x13
    (void)integer::sub(s.cx,0x00000013u,32,flags);
  }
  { // 0x775200: 7222 JC 0x00775224
    if(integer::condition("JC",flags)) goto L00775224;
  }
  { // 0x775202: 83f924 CMP ECX,0x24
    (void)integer::sub(s.cx,0x00000024u,32,flags);
  }
  { // 0x775205: 771d JA 0x00775224
    if(integer::condition("JA",flags)) goto L00775224;
  }
  { // 0x775207: e842000000 CALL 0x0077524e
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77520c: c7000d000000 MOV dword ptr [EAX],0xd
    m.w32((s.ax), 0x0000000du);
  }
  { // 0x775212: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x775213: c3 RET
    finish(m,s,f,0u); return;
  }
  L00775214: { // 0x775214: e835000000 CALL 0x0077524e
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x775219: 8b0cf584778100 MOV ECX,dword ptr [ESI*0x8 + 0x817784]
    s.cx = m.r32(((s.si * 0x00000008u)+0x00817784u));
  }
  { // 0x775220: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x775221: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x775223: c3 RET
    finish(m,s,f,0u); return;
  }
  L00775224: { // 0x775224: 81f9bc000000 CMP ECX,0xbc
    (void)integer::sub(s.cx,0x000000bcu,32,flags);
  }
  { // 0x77522a: 7215 JC 0x00775241
    if(integer::condition("JC",flags)) goto L00775241;
  }
  { // 0x77522c: 81f9ca000000 CMP ECX,0xca
    (void)integer::sub(s.cx,0x000000cau,32,flags);
  }
  { // 0x775232: 770d JA 0x00775241
    if(integer::condition("JA",flags)) goto L00775241;
  }
  { // 0x775234: e815000000 CALL 0x0077524e
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x775239: c70008000000 MOV dword ptr [EAX],0x8
    m.w32((s.ax), 0x00000008u);
  }
  { // 0x77523f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x775240: c3 RET
    finish(m,s,f,0u); return;
  }
  L00775241: { // 0x775241: e808000000 CALL 0x0077524e
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x775246: c70016000000 MOV dword ptr [EAX],0x16
    m.w32((s.ax), 0x00000016u);
  }
  { // 0x77524c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77524d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00375260(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x775260: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x775261: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x775262: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x775266: 397c240c CMP dword ptr [ESP + 0xc],EDI
    (void)integer::sub(m.r32((f.sp+0x0000000cu)),s.di,32,flags);
  }
  { // 0x77526a: 7204 JC 0x00775270
    if(integer::condition("JC",flags)) goto L00775270;
  }
  { // 0x77526c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x77526e: eb5a JMP 0x007752ca
    goto L007752ca;
  }
  L00775270: { // 0x775270: 833ddc0ab10000 CMP dword ptr [0x00b10adc],0x0
    (void)integer::sub(m.r32((0x00b10adcu)),0x00000000u,32,flags);
  }
  { // 0x775277: 7505 JNZ 0x0077527e
    if(integer::condition("JNZ",flags)) goto L0077527e;
  }
  { // 0x775279: 8d47ff LEA EAX,[EDI + -0x1]
    s.ax = (s.di-0x00000001u);
  }
  { // 0x77527c: eb4c JMP 0x007752ca
    goto L007752ca;
  }
  L0077527e: { // 0x77527e: 6a19 PUSH 0x19
    f.push(m,0x00000019u);
  }
  { // 0x775280: e831c3ffff CALL 0x007715b6
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x775285: 0fb647ff MOVZX EAX,byte ptr [EDI + -0x1]
    s.ax = (m.r8((s.di-0x00000001u))&integer::mask(8));
  }
  { // 0x775289: 8d77ff LEA ESI,[EDI + -0x1]
    s.si = (s.di-0x00000001u);
  }
  { // 0x77528c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77528d: f680e10bb10004 TEST byte ptr [EAX + 0xb10be1],0x4
    (void)integer::logical((m.r8((s.ax+0x00b10be1u)))&(0x00000004u),8,flags);
  }
  { // 0x775294: 740d JZ 0x007752a3
    if(integer::condition("JZ",flags)) goto L007752a3;
  }
  { // 0x775296: 6a19 PUSH 0x19
    f.push(m,0x00000019u);
  }
  { // 0x775298: e87ac3ffff CALL 0x00771617
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77529d: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77529e: 8d46ff LEA EAX,[ESI + -0x1]
    s.ax = (s.si-0x00000001u);
  }
  { // 0x7752a1: eb27 JMP 0x007752ca
    goto L007752ca;
  }
  L007752a3: { // 0x7752a3: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x7752a4: 3974240c CMP dword ptr [ESP + 0xc],ESI
    (void)integer::sub(m.r32((f.sp+0x0000000cu)),s.si,32,flags);
  }
  { // 0x7752a8: 770c JA 0x007752b6
    if(integer::condition("JA",flags)) goto L007752b6;
  }
  { // 0x7752aa: 0fb606 MOVZX EAX,byte ptr [ESI]
    s.ax = (m.r8((s.si))&integer::mask(8));
  }
  { // 0x7752ad: f680e10bb10004 TEST byte ptr [EAX + 0xb10be1],0x4
    (void)integer::logical((m.r8((s.ax+0x00b10be1u)))&(0x00000004u),8,flags);
  }
  { // 0x7752b4: 75ed JNZ 0x007752a3
    if(integer::condition("JNZ",flags)) goto L007752a3;
  }
  L007752b6: { // 0x7752b6: 6a19 PUSH 0x19
    f.push(m,0x00000019u);
  }
  { // 0x7752b8: e85ac3ffff CALL 0x00771617
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x7752bd: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7752be: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x7752c0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x7752c2: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  { // 0x7752c4: 83e101 AND ECX,0x1
    s.cx = integer::logical((s.cx)&(0x00000001u),32,flags);
  }
  { // 0x7752c7: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x7752c9: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L007752ca: { // 0x7752ca: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7752cb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7752cc: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00376634(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x776634: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x776635: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x776639: 3b35000eb100 CMP ESI,dword ptr [0x00b10e00]
    (void)integer::sub(s.si,m.r32((0x00b10e00u)),32,flags);
  }
  { // 0x77663f: 7338 JNC 0x00776679
    if(integer::condition("JNC",flags)) goto L00776679;
  }
  { // 0x776641: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x776643: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x776645: c1f905 SAR ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x776648: 83e01f AND EAX,0x1f
    s.ax = integer::logical((s.ax)&(0x0000001fu),32,flags);
  }
  { // 0x77664b: 8b0c8d000db100 MOV ECX,dword ptr [ECX*0x4 + 0xb10d00]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x00b10d00u));
  }
  { // 0x776652: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x776655: f644810401 TEST byte ptr [ECX + EAX*0x4 + 0x4],0x1
    (void)integer::logical((m.r8((s.cx+(s.ax * 0x00000004u)+0x00000004u)))&(0x00000001u),8,flags);
  }
  { // 0x77665a: 741d JZ 0x00776679
    if(integer::condition("JZ",flags)) goto L00776679;
  }
  { // 0x77665c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77665d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77665e: e8cb6e0000 CALL 0x0077d52e
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x776663: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x776664: e828000000 CALL 0x00776691
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x776669: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77666a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x77666c: e81c6f0000 CALL 0x0077d58d
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x776671: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x776674: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x776676: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x776677: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x776678: c3 RET
    finish(m,s,f,0u); return;
  }
  L00776679: { // 0x776679: e8d0ebffff CALL 0x0077524e
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x77667e: c70009000000 MOV dword ptr [EAX],0x9
    m.w32((s.ax), 0x00000009u);
  }
  { // 0x776684: e8ceebffff CALL 0x00775257
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x776689: 832000 AND dword ptr [EAX],0x0
    m.w32((s.ax), integer::logical((m.r32((s.ax)))&(0x00000000u),32,flags));
  }
  { // 0x77668c: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x77668f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x776690: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00376a3f(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x776a3f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x776a40: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x776a42: e8ba000000 CALL 0x00776b01
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x776a47: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x776a4c: 7407 JZ 0x00776a55
    if(integer::condition("JZ",flags)) goto L00776a55;
  }
  { // 0x776a4e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x776a4f: e8276cffff CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x776a54: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00776a55: { // 0x776a55: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x776a57: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x776a58: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00376a5b(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x776a5b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x776a5c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x776a5d: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x776a61: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x776a63: c7061cc87900 MOV dword ptr [ESI],0x79c81c
    m.w32((s.si), 0x0079c81cu);
  }
  { // 0x776a69: ff37 PUSH dword ptr [EDI]
    f.push(m,m.r32((s.di)));
  }
  { // 0x776a6b: e8f0e6ffff CALL 0x00775160
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x776a70: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x776a71: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x776a72: e8e06effff CALL 0x0076d957
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x776a77: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x776a78: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x776a7b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x776a7d: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x776a7e: 740a JZ 0x00776a8a
    if(integer::condition("JZ",flags)) goto L00776a8a;
  }
  { // 0x776a80: ff37 PUSH dword ptr [EDI]
    f.push(m,m.r32((s.di)));
  }
  { // 0x776a82: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x776a83: e888250000 CALL 0x00779010
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x776a88: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x776a89: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00776a8a: { // 0x776a8a: c7460801000000 MOV dword ptr [ESI + 0x8],0x1
    m.w32((s.si+0x00000008u), 0x00000001u);
  }
  { // 0x776a91: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x776a93: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x776a94: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x776a95: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00376a98(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x776a98: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x776a99: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x776a9a: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x776a9e: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x776aa0: c7061cc87900 MOV dword ptr [ESI],0x79c81c
    m.w32((s.si), 0x0079c81cu);
  }
  { // 0x776aa6: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  { // 0x776aa9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x776aab: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x776aae: 7425 JZ 0x00776ad5
    if(integer::condition("JZ",flags)) goto L00776ad5;
  }
  { // 0x776ab0: ff7704 PUSH dword ptr [EDI + 0x4]
    f.push(m,m.r32((s.di+0x00000004u)));
  }
  { // 0x776ab3: e8a8e6ffff CALL 0x00775160
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x776ab8: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x776ab9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x776aba: e8986effff CALL 0x0076d957
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x776abf: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x776ac0: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x776ac3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x776ac5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x776ac6: 7413 JZ 0x00776adb
    if(integer::condition("JZ",flags)) goto L00776adb;
  }
  { // 0x776ac8: ff7704 PUSH dword ptr [EDI + 0x4]
    f.push(m,m.r32((s.di+0x00000004u)));
  }
  { // 0x776acb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x776acc: e83f250000 CALL 0x00779010
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x776ad1: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x776ad2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x776ad3: eb06 JMP 0x00776adb
    goto L00776adb;
  }
  L00776ad5: { // 0x776ad5: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x776ad8: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L00776adb: { // 0x776adb: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x776add: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x776ade: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x776adf: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00376ae2(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x776ae2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x776ae3: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x776ae5: 3b742408 CMP ESI,dword ptr [ESP + 0x8]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000008u)),32,flags);
  }
  { // 0x776ae9: 7410 JZ 0x00776afb
    if(integer::condition("JZ",flags)) goto L00776afb;
  }
  { // 0x776aeb: e811000000 CALL 0x00776b01
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x776af0: ff742408 PUSH dword ptr [ESP + 0x8]
    f.push(m,m.r32((f.sp+0x00000008u)));
  }
  { // 0x776af4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x776af6: e89dffffff CALL 0x00776a98
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L00776afb: { // 0x776afb: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x776afd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x776afe: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_003775b6(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7775b6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7775b7: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7775b9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7775ba: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x7775bd: 663dffff CMP AX,0xffff
    (void)integer::sub((s.ax & 0xffffu),0x0000ffffu,16,flags);
  }
  { // 0x7775c1: 7505 JNZ 0x007775c8
    if(integer::condition("JNZ",flags)) goto L007775c8;
  }
  { // 0x7775c3: 660bc0 OR AX,AX
    s.ax = with_ax(s.ax, integer::logical(((s.ax & 0xffffu))|((s.ax & 0xffffu)),16,flags));
  }
  { // 0x7775c6: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x7775c7: c3 RET
    finish(m,s,f,0u); return;
  }
  L007775c8: { // 0x7775c8: 833d3005b10000 CMP dword ptr [0x00b10530],0x0
    (void)integer::sub(m.r32((0x00b10530u)),0x00000000u,32,flags);
  }
  { // 0x7775cf: 7513 JNZ 0x007775e4
    if(integer::condition("JNZ",flags)) goto L007775e4;
  }
  { // 0x7775d1: 663d6100 CMP AX,0x61
    (void)integer::sub((s.ax & 0xffffu),0x00000061u,16,flags);
  }
  { // 0x7775d5: 7254 JC 0x0077762b
    if(integer::condition("JC",flags)) goto L0077762b;
  }
  { // 0x7775d7: 663d7a00 CMP AX,0x7a
    (void)integer::sub((s.ax & 0xffffu),0x0000007au,16,flags);
  }
  { // 0x7775db: 774e JA 0x0077762b
    if(integer::condition("JA",flags)) goto L0077762b;
  }
  { // 0x7775dd: 05e0ff0000 ADD EAX,0xffe0
    s.ax = integer::add(s.ax,0x0000ffe0u,32,flags);
  }
  { // 0x7775e2: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x7775e3: c3 RET
    finish(m,s,f,0u); return;
  }
  L007775e4: { // 0x7775e4: 663d0001 CMP AX,0x100
    (void)integer::sub((s.ax & 0xffffu),0x00000100u,16,flags);
  }
  { // 0x7775e8: 7314 JNC 0x007775fe
    if(integer::condition("JNC",flags)) goto L007775fe;
  }
  { // 0x7775ea: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x7775ec: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7775ed: e8eefeffff CALL 0x007774e0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x7775f2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7775f3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7775f5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7775f6: 7506 JNZ 0x007775fe
    if(integer::condition("JNZ",flags)) goto L007775fe;
  }
  { // 0x7775f8: 668b4508 MOV AX,word ptr [EBP + 0x8]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000008u)));
  }
  { // 0x7775fc: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x7775fd: c3 RET
    finish(m,s,f,0u); return;
  }
  L007775fe: { // 0x7775fe: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x777600: 8d45fe LEA EAX,[EBP + -0x2]
    s.ax = (s.bp-0x00000002u);
  }
  { // 0x777603: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x777605: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x777606: 8d4508 LEA EAX,[EBP + 0x8]
    s.ax = (s.bp+0x00000008u);
  }
  { // 0x777609: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77760b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77760c: 6800020000 PUSH 0x200
    f.push(m,0x00000200u);
  }
  { // 0x777611: ff353005b100 PUSH dword ptr [0x00b10530]
    f.push(m,m.r32((0x00b10530u)));
  }
  { // 0x777617: e8f2700000 CALL 0x0077e70e
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77761c: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  { // 0x77761f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x777621: 668b4508 MOV AX,word ptr [EBP + 0x8]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000008u)));
  }
  { // 0x777625: 7404 JZ 0x0077762b
    if(integer::condition("JZ",flags)) goto L0077762b;
  }
  { // 0x777627: 668b45fe MOV AX,word ptr [EBP + -0x2]
    s.ax = with_ax(s.ax, m.r16((s.bp-0x00000002u)));
  }
  L0077762b: { // 0x77762b: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77762c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003780fc(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7780fc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7780fd: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x778101: 66f7c600ff TEST SI,0xff00
    (void)integer::logical(((s.si & 0xffffu))&(0x0000ff00u),16,flags);
  }
  { // 0x778106: 7538 JNZ 0x00778140
    if(integer::condition("JNZ",flags)) goto L00778140;
  }
  { // 0x778108: 833d6c77810001 CMP dword ptr [0x0081776c],0x1
    (void)integer::sub(m.r32((0x0081776cu)),0x00000001u,32,flags);
  }
  { // 0x77810f: 7e13 JLE 0x00778124
    if(integer::condition("JLE",flags)) goto L00778124;
  }
  { // 0x778111: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x778113: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x778115: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x77811a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77811b: e8b1cdffff CALL 0x00774ed1
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x778120: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x778121: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x778122: eb13 JMP 0x00778137
    goto L00778137;
  }
  L00778124: { // 0x778124: 8b0d60758100 MOV ECX,dword ptr [0x00817560]
    s.cx = m.r32((0x00817560u));
  }
  { // 0x77812a: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x77812c: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x778131: 8a0441 MOV AL,byte ptr [ECX + EAX*0x2]
    s.ax = with_al(s.ax, m.r8((s.cx+(s.ax * 0x00000002u))));
  }
  { // 0x778134: 83e004 AND EAX,0x4
    s.ax = integer::logical((s.ax)&(0x00000004u),32,flags);
  }
  L00778137: { // 0x778137: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x778139: 7405 JZ 0x00778140
    if(integer::condition("JZ",flags)) goto L00778140;
  }
  { // 0x77813b: 668bc6 MOV AX,SI
    s.ax = with_ax(s.ax, (s.si & 0xffffu));
  }
  { // 0x77813e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77813f: c3 RET
    finish(m,s,f,0u); return;
  }
  L00778140: { // 0x778140: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x778142: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x778143: e898f3ffff CALL 0x007774e0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x778148: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x778149: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77814b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77814c: 8d46d9 LEA EAX,[ESI + -0x27]
    s.ax = (s.si-0x00000027u);
  }
  { // 0x77814f: 7503 JNZ 0x00778154
    if(integer::condition("JNZ",flags)) goto L00778154;
  }
  { // 0x778151: 8d46f9 LEA EAX,[ESI + -0x7]
    s.ax = (s.si-0x00000007u);
  }
  L00778154: { // 0x778154: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x778155: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00378d44(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x778d44: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x778d48: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x778d4b: 7413 JZ 0x00778d60
    if(integer::condition("JZ",flags)) goto L00778d60;
  }
  { // 0x778d4d: 7e1c JLE 0x00778d6b
    if(integer::condition("JLE",flags)) goto L00778d6b;
  }
  { // 0x778d4f: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x778d52: 7f17 JG 0x00778d6b
    if(integer::condition("JG",flags)) goto L00778d6b;
  }
  { // 0x778d54: e8f5c4ffff CALL 0x0077524e
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x778d59: c70022000000 MOV dword ptr [EAX],0x22
    m.w32((s.ax), 0x00000022u);
  }
  { // 0x778d5f: c3 RET
    finish(m,s,f,0u); return;
  }
  L00778d60: { // 0x778d60: e8e9c4ffff CALL 0x0077524e
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x778d65: c70021000000 MOV dword ptr [EAX],0x21
    m.w32((s.ax), 0x00000021u);
  }
  L00778d6b: { // 0x778d6b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00379146(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x779146: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x779147: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x77914b: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x77914d: 741e JZ 0x0077916d
    if(integer::condition("JZ",flags)) goto L0077916d;
  }
  { // 0x77914f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x779150: e80bc0ffff CALL 0x00775160
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x779155: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x779156: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x779157: e8144effff CALL 0x0076df70
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77915c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77915d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77915f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x779160: 740b JZ 0x0077916d
    if(integer::condition("JZ",flags)) goto L0077916d;
  }
  { // 0x779162: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x779163: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x779164: e8a7feffff CALL 0x00779010
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x779169: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77916a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77916b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77916c: c3 RET
    finish(m,s,f,0u); return;
  }
  L0077916d: { // 0x77916d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x77916f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x779170: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003795fd(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7795fd: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7795fe: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x779600: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x779601: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x779603: 3935dc0ab100 CMP dword ptr [0x00b10adc],ESI
    (void)integer::sub(m.r32((0x00b10adcu)),s.si,32,flags);
  }
  { // 0x779609: 750f JNZ 0x0077961a
    if(integer::condition("JNZ",flags)) goto L0077961a;
  }
  { // 0x77960b: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x77960e: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x779611: e81a43ffff CALL 0x0076d930
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x779616: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x779617: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x779618: eb52 JMP 0x0077966c
    goto L0077966c;
  }
  L0077961a: { // 0x77961a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77961b: 6a19 PUSH 0x19
    f.push(m,0x00000019u);
  }
  { // 0x77961d: e8947fffff CALL 0x007715b6
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x779622: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x779623: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L00779626: { // 0x779626: 8a11 MOV DL,byte ptr [ECX]
    s.dx = with_al(s.dx, m.r8((s.cx)));
  }
  { // 0x779628: 0fb6c2 MOVZX EAX,DL
    s.ax = ((s.dx & 0xffu)&integer::mask(8));
  }
  { // 0x77962b: 0fb6f8 MOVZX EDI,AL
    s.di = ((s.ax & 0xffu)&integer::mask(8));
  }
  { // 0x77962e: f687e10bb10004 TEST byte ptr [EDI + 0xb10be1],0x4
    (void)integer::logical((m.r8((s.di+0x00b10be1u)))&(0x00000004u),8,flags);
  }
  { // 0x779635: 741e JZ 0x00779655
    if(integer::condition("JZ",flags)) goto L00779655;
  }
  { // 0x779637: 8a5101 MOV DL,byte ptr [ECX + 0x1]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000001u)));
  }
  { // 0x77963a: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x77963b: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x77963d: 7412 JZ 0x00779651
    if(integer::condition("JZ",flags)) goto L00779651;
  }
  { // 0x77963f: 0fb6fa MOVZX EDI,DL
    s.di = ((s.dx & 0xffu)&integer::mask(8));
  }
  { // 0x779642: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  { // 0x779645: 0bc7 OR EAX,EDI
    s.ax = integer::logical((s.ax)|(s.di),32,flags);
  }
  { // 0x779647: 39450c CMP dword ptr [EBP + 0xc],EAX
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),s.ax,32,flags);
  }
  { // 0x77964a: 7510 JNZ 0x0077965c
    if(integer::condition("JNZ",flags)) goto L0077965c;
  }
  { // 0x77964c: 8d71ff LEA ESI,[ECX + -0x1]
    s.si = (s.cx-0x00000001u);
  }
  { // 0x77964f: eb0b JMP 0x0077965c
    goto L0077965c;
  }
  L00779651: { // 0x779651: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x779653: eb03 JMP 0x00779658
    goto L00779658;
  }
  L00779655: { // 0x779655: 39450c CMP dword ptr [EBP + 0xc],EAX
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),s.ax,32,flags);
  }
  L00779658: { // 0x779658: 7502 JNZ 0x0077965c
    if(integer::condition("JNZ",flags)) goto L0077965c;
  }
  { // 0x77965a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0077965c: { // 0x77965c: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x77965d: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x77965f: 75c5 JNZ 0x00779626
    if(integer::condition("JNZ",flags)) goto L00779626;
  }
  { // 0x779661: 6a19 PUSH 0x19
    f.push(m,0x00000019u);
  }
  { // 0x779663: e8af7fffff CALL 0x00771617
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x779668: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x779669: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x77966b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0077966c: { // 0x77966c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77966d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x77966e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037aa92(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77aa92: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77aa93: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x77aa97: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x77aa99: 7443 JZ 0x0077aade
    if(integer::condition("JZ",flags)) goto L0077aade;
  }
  { // 0x77aa9b: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  { // 0x77aa9e: 3d2008b100 CMP EAX,0xb10820
    (void)integer::sub(s.ax,0x00b10820u,32,flags);
  }
  { // 0x77aaa3: 7439 JZ 0x0077aade
    if(integer::condition("JZ",flags)) goto L0077aade;
  }
  { // 0x77aaa5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77aaa6: e87d34ffff CALL 0x0076df28
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x77aaab: ff7610 PUSH dword ptr [ESI + 0x10]
    f.push(m,m.r32((s.si+0x00000010u)));
  }
  { // 0x77aaae: e87534ffff CALL 0x0076df28
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77aab3: ff7614 PUSH dword ptr [ESI + 0x14]
    f.push(m,m.r32((s.si+0x00000014u)));
  }
  { // 0x77aab6: e86d34ffff CALL 0x0076df28
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x77aabb: ff7618 PUSH dword ptr [ESI + 0x18]
    f.push(m,m.r32((s.si+0x00000018u)));
  }
  { // 0x77aabe: e86534ffff CALL 0x0076df28
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x77aac3: ff761c PUSH dword ptr [ESI + 0x1c]
    f.push(m,m.r32((s.si+0x0000001cu)));
  }
  { // 0x77aac6: e85d34ffff CALL 0x0076df28
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x77aacb: ff7620 PUSH dword ptr [ESI + 0x20]
    f.push(m,m.r32((s.si+0x00000020u)));
  }
  { // 0x77aace: e85534ffff CALL 0x0076df28
    invoke(m,s,f,op,5u); flags=0x202u;
  }
  { // 0x77aad3: ff7624 PUSH dword ptr [ESI + 0x24]
    f.push(m,m.r32((s.si+0x00000024u)));
  }
  { // 0x77aad6: e84d34ffff CALL 0x0076df28
    invoke(m,s,f,op,6u); flags=0x202u;
  }
  { // 0x77aadb: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L0077aade: { // 0x77aade: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77aadf: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037b678(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77b678: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77b679: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x77b67d: 3b35000eb100 CMP ESI,dword ptr [0x00b10e00]
    (void)integer::sub(s.si,m.r32((0x00b10e00u)),32,flags);
  }
  { // 0x77b683: 7340 JNC 0x0077b6c5
    if(integer::condition("JNC",flags)) goto L0077b6c5;
  }
  { // 0x77b685: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x77b687: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x77b689: c1f905 SAR ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x77b68c: 83e01f AND EAX,0x1f
    s.ax = integer::logical((s.ax)&(0x0000001fu),32,flags);
  }
  { // 0x77b68f: 8b0c8d000db100 MOV ECX,dword ptr [ECX*0x4 + 0xb10d00]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x00b10d00u));
  }
  { // 0x77b696: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x77b699: f644810401 TEST byte ptr [ECX + EAX*0x4 + 0x4],0x1
    (void)integer::logical((m.r8((s.cx+(s.ax * 0x00000004u)+0x00000004u)))&(0x00000001u),8,flags);
  }
  { // 0x77b69e: 7425 JZ 0x0077b6c5
    if(integer::condition("JZ",flags)) goto L0077b6c5;
  }
  { // 0x77b6a0: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77b6a1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77b6a2: e8871e0000 CALL 0x0077d52e
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x77b6a7: ff742418 PUSH dword ptr [ESP + 0x18]
    f.push(m,m.r32((f.sp+0x00000018u)));
  }
  { // 0x77b6ab: ff742418 PUSH dword ptr [ESP + 0x18]
    f.push(m,m.r32((f.sp+0x00000018u)));
  }
  { // 0x77b6af: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77b6b0: e828000000 CALL 0x0077b6dd
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77b6b5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77b6b6: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x77b6b8: e8d01e0000 CALL 0x0077d58d
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x77b6bd: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x77b6c0: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x77b6c2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77b6c3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77b6c4: c3 RET
    finish(m,s,f,0u); return;
  }
  L0077b6c5: { // 0x77b6c5: e8849bffff CALL 0x0077524e
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x77b6ca: c70009000000 MOV dword ptr [EAX],0x9
    m.w32((s.ax), 0x00000009u);
  }
  { // 0x77b6d0: e8829bffff CALL 0x00775257
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x77b6d5: 832000 AND dword ptr [EAX],0x0
    m.w32((s.ax), integer::logical((m.r32((s.ax)))&(0x00000000u),32,flags));
  }
  { // 0x77b6d8: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x77b6db: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77b6dc: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037bd01(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77bd01: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77bd02: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77bd04: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77bd07: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x77bd09: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd0a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd0b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd0c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd0d: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x77bd10: 8d450c LEA EAX,[EBP + 0xc]
    s.ax = (s.bp+0x0000000cu);
  }
  { // 0x77bd13: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd14: 8d45f4 LEA EAX,[EBP + -0xc]
    s.ax = (s.bp-0x0000000cu);
  }
  { // 0x77bd17: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd18: e8db190000 CALL 0x0077d6f8
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x77bd1d: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x77bd20: 8d45f4 LEA EAX,[EBP + -0xc]
    s.ax = (s.bp-0x0000000cu);
  }
  { // 0x77bd23: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd24: e832ffffff CALL 0x0077bc5b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77bd29: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  { // 0x77bd2c: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77bd2d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037bd2e(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77bd2e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77bd2f: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77bd31: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77bd34: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x77bd36: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd37: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd38: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd39: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77bd3b: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x77bd3e: 8d450c LEA EAX,[EBP + 0xc]
    s.ax = (s.bp+0x0000000cu);
  }
  { // 0x77bd41: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd42: 8d45f4 LEA EAX,[EBP + -0xc]
    s.ax = (s.bp-0x0000000cu);
  }
  { // 0x77bd45: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd46: e8ad190000 CALL 0x0077d6f8
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x77bd4b: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x77bd4e: 8d45f4 LEA EAX,[EBP + -0xc]
    s.ax = (s.bp-0x0000000cu);
  }
  { // 0x77bd51: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd52: e830ffffff CALL 0x0077bc87
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77bd57: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  { // 0x77bd5a: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77bd5b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037bd5c(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77bd5c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77bd5d: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77bd5f: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77bd62: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x77bd64: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd65: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd66: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd67: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd68: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x77bd6b: 8d450c LEA EAX,[EBP + 0xc]
    s.ax = (s.bp+0x0000000cu);
  }
  { // 0x77bd6e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd6f: 8d45f4 LEA EAX,[EBP + -0xc]
    s.ax = (s.bp-0x0000000cu);
  }
  { // 0x77bd72: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd73: e880190000 CALL 0x0077d6f8
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x77bd78: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x77bd7b: 8d45f4 LEA EAX,[EBP + -0xc]
    s.ax = (s.bp-0x0000000cu);
  }
  { // 0x77bd7e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bd7f: e8edfeffff CALL 0x0077bc71
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77bd84: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  { // 0x77bd87: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77bd88: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037bd89(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77bd89: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77bd8a: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77bd8c: 8b5510 MOV EDX,dword ptr [EBP + 0x10]
    s.dx = m.r32((s.bp+0x00000010u));
  }
  { // 0x77bd8f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77bd90: 8b5d0c MOV EBX,dword ptr [EBP + 0xc]
    s.bx = m.r32((s.bp+0x0000000cu));
  }
  { // 0x77bd93: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77bd94: 8b7508 MOV ESI,dword ptr [EBP + 0x8]
    s.si = m.r32((s.bp+0x00000008u));
  }
  { // 0x77bd97: 8b4a0c MOV ECX,dword ptr [EDX + 0xc]
    s.cx = m.r32((s.dx+0x0000000cu));
  }
  { // 0x77bd9a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77bd9b: 8d7e01 LEA EDI,[ESI + 0x1]
    s.di = (s.si+0x00000001u);
  }
  { // 0x77bd9e: c60630 MOV byte ptr [ESI],0x30
    m.w8((s.si), 0x00000030u);
  }
  { // 0x77bda1: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x77bda3: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x77bda5: 7e1f JLE 0x0077bdc6
    if(integer::condition("JLE",flags)) goto L0077bdc6;
  }
  { // 0x77bda7: 895d08 MOV dword ptr [EBP + 0x8],EBX
    m.w32((s.bp+0x00000008u), s.bx);
  }
  { // 0x77bdaa: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0077bdac: { // 0x77bdac: 8a11 MOV DL,byte ptr [ECX]
    s.dx = with_al(s.dx, m.r8((s.cx)));
  }
  { // 0x77bdae: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x77bdb0: 7406 JZ 0x0077bdb8
    if(integer::condition("JZ",flags)) goto L0077bdb8;
  }
  { // 0x77bdb2: 0fbed2 MOVSX EDX,DL
    s.dx = std::uint32_t(integer::sign_extend((s.dx & 0xffu),8));
  }
  { // 0x77bdb5: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x77bdb6: eb03 JMP 0x0077bdbb
    goto L0077bdbb;
  }
  L0077bdb8: { // 0x77bdb8: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  { // 0x77bdba: 5a POP EDX
    const auto value=f.pop(m); s.dx = value;
  }
  L0077bdbb: { // 0x77bdbb: 8810 MOV byte ptr [EAX],DL
    m.w8((s.ax), (s.dx & 0xffu));
  }
  { // 0x77bdbd: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x77bdbe: ff4d08 DEC dword ptr [EBP + 0x8]
    m.w32((s.bp+0x00000008u), integer::decrement(m.r32((s.bp+0x00000008u)),32,flags));
  }
  { // 0x77bdc1: 75e9 JNZ 0x0077bdac
    if(integer::condition("JNZ",flags)) goto L0077bdac;
  }
  { // 0x77bdc3: 8b5510 MOV EDX,dword ptr [EBP + 0x10]
    s.dx = m.r32((s.bp+0x00000010u));
  }
  L0077bdc6: { // 0x77bdc6: 802000 AND byte ptr [EAX],0x0
    m.w8((s.ax), integer::logical((m.r8((s.ax)))&(0x00000000u),8,flags));
  }
  { // 0x77bdc9: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x77bdcb: 7c12 JL 0x0077bddf
    if(integer::condition("JL",flags)) goto L0077bddf;
  }
  { // 0x77bdcd: 803935 CMP byte ptr [ECX],0x35
    (void)integer::sub(m.r8((s.cx)),0x00000035u,8,flags);
  }
  { // 0x77bdd0: 7c0d JL 0x0077bddf
    if(integer::condition("JL",flags)) goto L0077bddf;
  }
  L0077bdd2: { // 0x77bdd2: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x77bdd3: 803839 CMP byte ptr [EAX],0x39
    (void)integer::sub(m.r8((s.ax)),0x00000039u,8,flags);
  }
  { // 0x77bdd6: 7505 JNZ 0x0077bddd
    if(integer::condition("JNZ",flags)) goto L0077bddd;
  }
  { // 0x77bdd8: c60030 MOV byte ptr [EAX],0x30
    m.w8((s.ax), 0x00000030u);
  }
  { // 0x77bddb: ebf5 JMP 0x0077bdd2
    goto L0077bdd2;
  }
  L0077bddd: { // 0x77bddd: fe00 INC byte ptr [EAX]
    m.w8((s.ax), integer::increment(m.r8((s.ax)),8,flags));
  }
  L0077bddf: { // 0x77bddf: 803e31 CMP byte ptr [ESI],0x31
    (void)integer::sub(m.r8((s.si)),0x00000031u,8,flags);
  }
  { // 0x77bde2: 7505 JNZ 0x0077bde9
    if(integer::condition("JNZ",flags)) goto L0077bde9;
  }
  { // 0x77bde4: ff4204 INC dword ptr [EDX + 0x4]
    m.w32((s.dx+0x00000004u), integer::increment(m.r32((s.dx+0x00000004u)),32,flags));
  }
  { // 0x77bde7: eb12 JMP 0x0077bdfb
    goto L0077bdfb;
  }
  L0077bde9: { // 0x77bde9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77bdea: e87193ffff CALL 0x00775160
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x77bdef: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x77bdf0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77bdf1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77bdf2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77bdf3: e8d82dffff CALL 0x0076ebd0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77bdf8: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0077bdfb: { // 0x77bdfb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77bdfc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77bdfd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x77bdfe: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x77bdff: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037d445(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77d445: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x77d449: 3b05000eb100 CMP EAX,dword ptr [0x00b10e00]
    (void)integer::sub(s.ax,m.r32((0x00b10e00u)),32,flags);
  }
  { // 0x77d44f: 731f JNC 0x0077d470
    if(integer::condition("JNC",flags)) goto L0077d470;
  }
  { // 0x77d451: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x77d453: 83e01f AND EAX,0x1f
    s.ax = integer::logical((s.ax)&(0x0000001fu),32,flags);
  }
  { // 0x77d456: c1f905 SAR ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x77d459: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x77d45c: 8b0c8d000db100 MOV ECX,dword ptr [ECX*0x4 + 0xb10d00]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x00b10d00u));
  }
  { // 0x77d463: f644810401 TEST byte ptr [ECX + EAX*0x4 + 0x4],0x1
    (void)integer::logical((m.r8((s.cx+(s.ax * 0x00000004u)+0x00000004u)))&(0x00000001u),8,flags);
  }
  { // 0x77d468: 8d0481 LEA EAX,[ECX + EAX*0x4]
    s.ax = (s.cx+(s.ax * 0x00000004u));
  }
  { // 0x77d46b: 7403 JZ 0x0077d470
    if(integer::condition("JZ",flags)) goto L0077d470;
  }
  { // 0x77d46d: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x77d46f: c3 RET
    finish(m,s,f,0u); return;
  }
  L0077d470: { // 0x77d470: e8d97dffff CALL 0x0077524e
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x77d475: c70009000000 MOV dword ptr [EAX],0x9
    m.w32((s.ax), 0x00000009u);
  }
  { // 0x77d47b: e8d77dffff CALL 0x00775257
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77d480: 832000 AND dword ptr [EAX],0x0
    m.w32((s.ax), integer::logical((m.r32((s.ax)))&(0x00000000u),32,flags));
  }
  { // 0x77d483: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x77d486: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037dbc9(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77dbc9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77dbca: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77dbcc: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77dbcf: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x77dbd1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77dbd2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77dbd3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77dbd4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77dbd5: 8d45f4 LEA EAX,[EBP + -0xc]
    s.ax = (s.bp-0x0000000cu);
  }
  { // 0x77dbd8: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x77dbdb: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x77dbde: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x77dbe1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77dbe2: e811fbffff CALL 0x0077d6f8
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x77dbe7: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x77dbea: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x77dbec: 8d45f4 LEA EAX,[EBP + -0xc]
    s.ax = (s.bp-0x0000000cu);
  }
  { // 0x77dbef: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77dbf0: e892e0ffff CALL 0x0077bc87
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77dbf5: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  { // 0x77dbf8: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x77dbfb: 7503 JNZ 0x0077dc00
    if(integer::condition("JNZ",flags)) goto L0077dc00;
  }
  { // 0x77dbfd: 83ce02 OR ESI,0x2
    s.si = integer::logical((s.si)|(0x00000002u),32,flags);
  }
  L0077dc00: { // 0x77dc00: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x77dc02: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77dc03: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77dc04: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037dd4f(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77dd4f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77dd50: ff74240c PUSH dword ptr [ESP + 0xc]
    f.push(m,m.r32((f.sp+0x0000000cu)));
  }
  { // 0x77dd54: e8e021ffff CALL 0x0076ff39
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x77dd59: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x77dd5d: ff742410 PUSH dword ptr [ESP + 0x10]
    f.push(m,m.r32((f.sp+0x00000010u)));
  }
  { // 0x77dd61: e812000000 CALL 0x0077dd78
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77dd66: ff742418 PUSH dword ptr [ESP + 0x18]
    f.push(m,m.r32((f.sp+0x00000018u)));
  }
  { // 0x77dd6a: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x77dd6c: e81a22ffff CALL 0x0076ff8b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x77dd71: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x77dd74: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x77dd76: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77dd77: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037dde6(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77dde6: 833dd007b10000 CMP dword ptr [0x00b107d0],0x0
    (void)integer::sub(m.r32((0x00b107d0u)),0x00000000u,32,flags);
  }
  { // 0x77dded: 7524 JNZ 0x0077de13
    if(integer::condition("JNZ",flags)) goto L0077de13;
  }
  { // 0x77ddef: 6a0b PUSH 0xb
    f.push(m,0x0000000bu);
  }
  { // 0x77ddf1: e8c037ffff CALL 0x007715b6
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x77ddf6: 833dd007b10000 CMP dword ptr [0x00b107d0],0x0
    (void)integer::sub(m.r32((0x00b107d0u)),0x00000000u,32,flags);
  }
  { // 0x77ddfd: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77ddfe: 750b JNZ 0x0077de0b
    if(integer::condition("JNZ",flags)) goto L0077de0b;
  }
  { // 0x77de00: e825000000 CALL 0x0077de2a
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77de05: ff05d007b100 INC dword ptr [0x00b107d0]
    m.w32((0x00b107d0u), integer::increment(m.r32((0x00b107d0u)),32,flags));
  }
  L0077de0b: { // 0x77de0b: 6a0b PUSH 0xb
    f.push(m,0x0000000bu);
  }
  { // 0x77de0d: e80538ffff CALL 0x00771617
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x77de12: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077de13: { // 0x77de13: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037e0b1(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77e0b1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77e0b2: 6a0b PUSH 0xb
    f.push(m,0x0000000bu);
  }
  { // 0x77e0b4: e8fd34ffff CALL 0x007715b6
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x77e0b9: ff74240c PUSH dword ptr [ESP + 0xc]
    f.push(m,m.r32((f.sp+0x0000000cu)));
  }
  { // 0x77e0bd: e810000000 CALL 0x0077e0d2
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77e0c2: 6a0b PUSH 0xb
    f.push(m,0x0000000bu);
  }
  { // 0x77e0c4: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x77e0c6: e84c35ffff CALL 0x00771617
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x77e0cb: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77e0ce: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x77e0d0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77e0d1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037eb82(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77eb82: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77eb83: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x77eb87: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77eb88: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77eb89: e8ab13ffff CALL 0x0076ff39
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x77eb8e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77eb8f: e811000000 CALL 0x0077eba5
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77eb94: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77eb95: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x77eb97: e8ef13ffff CALL 0x0076ff8b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x77eb9c: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77eb9f: 668bc7 MOV AX,DI
    s.ax = with_ax(s.ax, (s.di & 0xffffu));
  }
  { // 0x77eba2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77eba3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77eba4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037f2a9(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77f2a9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77f2aa: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x77f2ae: 3b35000eb100 CMP ESI,dword ptr [0x00b10e00]
    (void)integer::sub(s.si,m.r32((0x00b10e00u)),32,flags);
  }
  { // 0x77f2b4: 733c JNC 0x0077f2f2
    if(integer::condition("JNC",flags)) goto L0077f2f2;
  }
  { // 0x77f2b6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x77f2b8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x77f2ba: c1f905 SAR ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x77f2bd: 83e01f AND EAX,0x1f
    s.ax = integer::logical((s.ax)&(0x0000001fu),32,flags);
  }
  { // 0x77f2c0: 8b0c8d000db100 MOV ECX,dword ptr [ECX*0x4 + 0xb10d00]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x00b10d00u));
  }
  { // 0x77f2c7: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x77f2ca: f644810401 TEST byte ptr [ECX + EAX*0x4 + 0x4],0x1
    (void)integer::logical((m.r8((s.cx+(s.ax * 0x00000004u)+0x00000004u)))&(0x00000001u),8,flags);
  }
  { // 0x77f2cf: 7421 JZ 0x0077f2f2
    if(integer::condition("JZ",flags)) goto L0077f2f2;
  }
  { // 0x77f2d1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77f2d2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77f2d3: e856e2ffff CALL 0x0077d52e
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x77f2d8: ff742414 PUSH dword ptr [ESP + 0x14]
    f.push(m,m.r32((f.sp+0x00000014u)));
  }
  { // 0x77f2dc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77f2dd: e820000000 CALL 0x0077f302
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x77f2e2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77f2e3: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x77f2e5: e8a3e2ffff CALL 0x0077d58d
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x77f2ea: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x77f2ed: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x77f2ef: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77f2f0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77f2f1: c3 RET
    finish(m,s,f,0u); return;
  }
  L0077f2f2: { // 0x77f2f2: e8575fffff CALL 0x0077524e
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x77f2f7: c70009000000 MOV dword ptr [EAX],0x9
    m.w32((s.ax), 0x00000009u);
  }
  { // 0x77f2fd: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x77f300: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77f301: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0038042f(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x78042f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x780430: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x780434: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x780435: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x780439: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x78043a: ff37 PUSH dword ptr [EDI]
    f.push(m,m.r32((s.di)));
  }
  { // 0x78043c: ff36 PUSH dword ptr [ESI]
    f.push(m,m.r32((s.si)));
  }
  { // 0x78043e: e8cbffffff CALL 0x0078040e
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x780443: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x780446: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x780448: 7417 JZ 0x00780461
    if(integer::condition("JZ",flags)) goto L00780461;
  }
  { // 0x78044a: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  { // 0x78044d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x78044e: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x780450: ff30 PUSH dword ptr [EAX]
    f.push(m,m.r32((s.ax)));
  }
  { // 0x780452: e8b7ffffff CALL 0x0078040e
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x780457: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x78045a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x78045c: 7403 JZ 0x00780461
    if(integer::condition("JZ",flags)) goto L00780461;
  }
  { // 0x78045e: ff4608 INC dword ptr [ESI + 0x8]
    m.w32((s.si+0x00000008u), integer::increment(m.r32((s.si+0x00000008u)),32,flags));
  }
  L00780461: { // 0x780461: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  { // 0x780464: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x780465: ff7704 PUSH dword ptr [EDI + 0x4]
    f.push(m,m.r32((s.di+0x00000004u)));
  }
  { // 0x780468: ff30 PUSH dword ptr [EAX]
    f.push(m,m.r32((s.ax)));
  }
  { // 0x78046a: e89fffffff CALL 0x0078040e
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x78046f: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x780472: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x780474: 7403 JZ 0x00780479
    if(integer::condition("JZ",flags)) goto L00780479;
  }
  { // 0x780476: ff4608 INC dword ptr [ESI + 0x8]
    m.w32((s.si+0x00000008u), integer::increment(m.r32((s.si+0x00000008u)),32,flags));
  }
  L00780479: { // 0x780479: 8d4608 LEA EAX,[ESI + 0x8]
    s.ax = (s.si+0x00000008u);
  }
  { // 0x78047c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x78047d: ff7708 PUSH dword ptr [EDI + 0x8]
    f.push(m,m.r32((s.di+0x00000008u)));
  }
  { // 0x780480: ff30 PUSH dword ptr [EAX]
    f.push(m,m.r32((s.ax)));
  }
  { // 0x780482: e887ffffff CALL 0x0078040e
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x780487: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x78048a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x78048b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x78048c: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00380f61(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x780f61: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x780f62: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x780f66: 3b35000eb100 CMP ESI,dword ptr [0x00b10e00]
    (void)integer::sub(s.si,m.r32((0x00b10e00u)),32,flags);
  }
  { // 0x780f6c: 733c JNC 0x00780faa
    if(integer::condition("JNC",flags)) goto L00780faa;
  }
  { // 0x780f6e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x780f70: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x780f72: c1f905 SAR ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x780f75: 83e01f AND EAX,0x1f
    s.ax = integer::logical((s.ax)&(0x0000001fu),32,flags);
  }
  { // 0x780f78: 8b0c8d000db100 MOV ECX,dword ptr [ECX*0x4 + 0xb10d00]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x00b10d00u));
  }
  { // 0x780f7f: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x780f82: f644810401 TEST byte ptr [ECX + EAX*0x4 + 0x4],0x1
    (void)integer::logical((m.r8((s.cx+(s.ax * 0x00000004u)+0x00000004u)))&(0x00000001u),8,flags);
  }
  { // 0x780f87: 7421 JZ 0x00780faa
    if(integer::condition("JZ",flags)) goto L00780faa;
  }
  { // 0x780f89: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x780f8a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x780f8b: e89ec5ffff CALL 0x0077d52e
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x780f90: ff742414 PUSH dword ptr [ESP + 0x14]
    f.push(m,m.r32((f.sp+0x00000014u)));
  }
  { // 0x780f94: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x780f95: e820000000 CALL 0x00780fba
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x780f9a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x780f9b: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x780f9d: e8ebc5ffff CALL 0x0077d58d
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x780fa2: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x780fa5: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x780fa7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x780fa8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x780fa9: c3 RET
    finish(m,s,f,0u); return;
  }
  L00780faa: { // 0x780faa: e89f42ffff CALL 0x0077524e
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x780faf: c70009000000 MOV dword ptr [EAX],0x9
    m.w32((s.ax), 0x00000009u);
  }
  { // 0x780fb5: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x780fb8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x780fb9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003817c4(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7817c4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7817c5: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7817c7: 8d4518 LEA EAX,[EBP + 0x18]
    s.ax = (s.bp+0x00000018u);
  }
  { // 0x7817ca: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7817cb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7817cc: 8d4520 LEA EAX,[EBP + 0x20]
    s.ax = (s.bp+0x00000020u);
  }
  { // 0x7817cf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7817d0: ff751c PUSH dword ptr [EBP + 0x1c]
    f.push(m,m.r32((s.bp+0x0000001cu)));
  }
  { // 0x7817d3: ff7518 PUSH dword ptr [EBP + 0x18]
    f.push(m,m.r32((s.bp+0x00000018u)));
  }
  { // 0x7817d6: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x7817d9: ff7510 PUSH dword ptr [EBP + 0x10]
    f.push(m,m.r32((s.bp+0x00000010u)));
  }
  { // 0x7817dc: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x7817df: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x7817e2: e834fbffff CALL 0x0078131b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x7817e7: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x7817e9: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x7817ec: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x7817ee: 7d09 JGE 0x007817f9
    if(integer::condition("JGE",flags)) goto L007817f9;
  }
  { // 0x7817f0: ff7518 PUSH dword ptr [EBP + 0x18]
    f.push(m,m.r32((s.bp+0x00000018u)));
  }
  { // 0x7817f3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7817f4: e8f3000000 CALL 0x007818ec
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L007817f9: { // 0x7817f9: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x7817fb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7817fc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x7817fd: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00381895(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x781895: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x781896: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x781898: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x781899: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  { // 0x78189c: 668365fe00 AND word ptr [EBP + -0x2],0x0
    m.w16((s.bp-0x00000002u), integer::logical((m.r16((s.bp-0x00000002u)))&(0x00000000u),16,flags));
  }
  { // 0x7818a1: 663d0900 CMP AX,0x9
    (void)integer::sub((s.ax & 0xffffu),0x00000009u,16,flags);
  }
  { // 0x7818a5: 668945fc MOV word ptr [EBP + -0x4],AX
    m.w16((s.bp-0x00000004u), (s.ax & 0xffffu));
  }
  { // 0x7818a9: 740a JZ 0x007818b5
    if(integer::condition("JZ",flags)) goto L007818b5;
  }
  { // 0x7818ab: 663d0d00 CMP AX,0xd
    (void)integer::sub((s.ax & 0xffffu),0x0000000du,16,flags);
  }
  { // 0x7818af: 7404 JZ 0x007818b5
    if(integer::condition("JZ",flags)) goto L007818b5;
  }
  { // 0x7818b1: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x7818b3: eb02 JMP 0x007818b7
    goto L007818b7;
  }
  L007818b5: { // 0x7818b5: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L007818b7: { // 0x7818b7: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  { // 0x7818b8: 8d4d0c LEA ECX,[EBP + 0xc]
    s.cx = (s.bp+0x0000000cu);
  }
  { // 0x7818bb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7818bc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7818bd: 8d4d14 LEA ECX,[EBP + 0x14]
    s.cx = (s.bp+0x00000014u);
  }
  { // 0x7818c0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7818c1: 8d4dfc LEA ECX,[EBP + -0x4]
    s.cx = (s.bp-0x00000004u);
  }
  { // 0x7818c4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7818c5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x7818c7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x7818c9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7818ca: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x7818cd: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x7818d0: e846faffff CALL 0x0078131b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x7818d5: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x7818d7: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x7818da: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x7818dc: 7d09 JGE 0x007818e7
    if(integer::condition("JGE",flags)) goto L007818e7;
  }
  { // 0x7818de: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x7818e1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7818e2: e805000000 CALL 0x007818ec
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L007818e7: { // 0x7818e7: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x7818e9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7818ea: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x7818eb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00381942(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x781942: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x781943: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x781945: e841000000 CALL 0x0078198b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x78194a: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x78194f: 7407 JZ 0x00781958
    if(integer::condition("JZ",flags)) goto L00781958;
  }
  { // 0x781951: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x781952: e824bdfeff CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x781957: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00781958: { // 0x781958: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x78195a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x78195b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00381d27(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x781d27: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x781d28: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x781d2a: e887f8feff CALL 0x007715b6
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x781d2f: e82b000000 CALL 0x00781d5f
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x781d34: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x781d36: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x781d38: e8daf8feff CALL 0x00771617
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x781d3d: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x781d3e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x781d40: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x781d41: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x781d42: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00382963(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x782963: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x782964: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x782968: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x78296a: 7421 JZ 0x0078298d
    if(integer::condition("JZ",flags)) goto L0078298d;
  }
  { // 0x78296c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x78296d: e8d3c5feff CALL 0x0076ef45
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x782972: 8d440002 LEA EAX,[EAX + EAX*0x1 + 0x2]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x00000002u);
  }
  { // 0x782976: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x782977: e8f4b5feff CALL 0x0076df70
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x78297c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x78297d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x78297f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x782980: 740b JZ 0x0078298d
    if(integer::condition("JZ",flags)) goto L0078298d;
  }
  { // 0x782982: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x782983: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x782984: e840c6feff CALL 0x0076efc9
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x782989: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x78298a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x78298b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x78298c: c3 RET
    finish(m,s,f,0u); return;
  }
  L0078298d: { // 0x78298d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x78298f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x782990: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00382bcc(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x782bcc: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x782bcd: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x782bcf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x782bd0: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x782bd3: 663dffff CMP AX,0xffff
    (void)integer::sub((s.ax & 0xffffu),0x0000ffffu,16,flags);
  }
  { // 0x782bd7: 7505 JNZ 0x00782bde
    if(integer::condition("JNZ",flags)) goto L00782bde;
  }
  { // 0x782bd9: 660bc0 OR AX,AX
    s.ax = with_ax(s.ax, integer::logical(((s.ax & 0xffffu))|((s.ax & 0xffffu)),16,flags));
  }
  { // 0x782bdc: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x782bdd: c3 RET
    finish(m,s,f,0u); return;
  }
  L00782bde: { // 0x782bde: 833d3005b10000 CMP dword ptr [0x00b10530],0x0
    (void)integer::sub(m.r32((0x00b10530u)),0x00000000u,32,flags);
  }
  { // 0x782be5: 7511 JNZ 0x00782bf8
    if(integer::condition("JNZ",flags)) goto L00782bf8;
  }
  { // 0x782be7: 663d4100 CMP AX,0x41
    (void)integer::sub((s.ax & 0xffffu),0x00000041u,16,flags);
  }
  { // 0x782beb: 7252 JC 0x00782c3f
    if(integer::condition("JC",flags)) goto L00782c3f;
  }
  { // 0x782bed: 663d5a00 CMP AX,0x5a
    (void)integer::sub((s.ax & 0xffffu),0x0000005au,16,flags);
  }
  { // 0x782bf1: 774c JA 0x00782c3f
    if(integer::condition("JA",flags)) goto L00782c3f;
  }
  { // 0x782bf3: 83c020 ADD EAX,0x20
    s.ax = integer::add(s.ax,0x00000020u,32,flags);
  }
  { // 0x782bf6: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x782bf7: c3 RET
    finish(m,s,f,0u); return;
  }
  L00782bf8: { // 0x782bf8: 663d0001 CMP AX,0x100
    (void)integer::sub((s.ax & 0xffffu),0x00000100u,16,flags);
  }
  { // 0x782bfc: 7314 JNC 0x00782c12
    if(integer::condition("JNC",flags)) goto L00782c12;
  }
  { // 0x782bfe: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x782c00: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x782c01: e8da48ffff CALL 0x007774e0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x782c06: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x782c07: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x782c09: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x782c0a: 7506 JNZ 0x00782c12
    if(integer::condition("JNZ",flags)) goto L00782c12;
  }
  { // 0x782c0c: 668b4508 MOV AX,word ptr [EBP + 0x8]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000008u)));
  }
  { // 0x782c10: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x782c11: c3 RET
    finish(m,s,f,0u); return;
  }
  L00782c12: { // 0x782c12: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x782c14: 8d45fe LEA EAX,[EBP + -0x2]
    s.ax = (s.bp-0x00000002u);
  }
  { // 0x782c17: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x782c19: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x782c1a: 8d4508 LEA EAX,[EBP + 0x8]
    s.ax = (s.bp+0x00000008u);
  }
  { // 0x782c1d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x782c1f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x782c20: 6800010000 PUSH 0x100
    f.push(m,0x00000100u);
  }
  { // 0x782c25: ff353005b100 PUSH dword ptr [0x00b10530]
    f.push(m,m.r32((0x00b10530u)));
  }
  { // 0x782c2b: e8debaffff CALL 0x0077e70e
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x782c30: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  { // 0x782c33: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x782c35: 668b4508 MOV AX,word ptr [EBP + 0x8]
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000008u)));
  }
  { // 0x782c39: 7404 JZ 0x00782c3f
    if(integer::condition("JZ",flags)) goto L00782c3f;
  }
  { // 0x782c3b: 668b45fe MOV AX,word ptr [EBP + -0x2]
    s.ax = with_ax(s.ax, m.r16((s.bp-0x00000002u)));
  }
  L00782c3f: { // 0x782c3f: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x782c40: c3 RET
    finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,137>& entries_c() {
  static const std::array<Entry,137> entries{{
    {0x303f20u,f_00303f20},
    {0x305400u,f_00305400},
    {0x30a340u,f_0030a340},
    {0x30a9e0u,f_0030a9e0},
    {0x30aad0u,f_0030aad0},
    {0x30ab40u,f_0030ab40},
    {0x30b560u,f_0030b560},
    {0x30bb00u,f_0030bb00},
    {0x311460u,f_00311460},
    {0x319630u,f_00319630},
    {0x31aaa0u,f_0031aaa0},
    {0x31af30u,f_0031af30},
    {0x31beb0u,f_0031beb0},
    {0x31bf20u,f_0031bf20},
    {0x31bf80u,f_0031bf80},
    {0x31c6f0u,f_0031c6f0},
    {0x31c7d0u,f_0031c7d0},
    {0x31c960u,f_0031c960},
    {0x31cae0u,f_0031cae0},
    {0x31cec0u,f_0031cec0},
    {0x31d390u,f_0031d390},
    {0x31d620u,f_0031d620},
    {0x31d750u,f_0031d750},
    {0x31d7b0u,f_0031d7b0},
    {0x31da10u,f_0031da10},
    {0x31da80u,f_0031da80},
    {0x31db00u,f_0031db00},
    {0x31db20u,f_0031db20},
    {0x31dea0u,f_0031dea0},
    {0x31f290u,f_0031f290},
    {0x31f2e0u,f_0031f2e0},
    {0x320980u,f_00320980},
    {0x320a70u,f_00320a70},
    {0x321660u,f_00321660},
    {0x321d40u,f_00321d40},
    {0x321d80u,f_00321d80},
    {0x321ee0u,f_00321ee0},
    {0x324b40u,f_00324b40},
    {0x324ea0u,f_00324ea0},
    {0x325350u,f_00325350},
    {0x3253f0u,f_003253f0},
    {0x3254a0u,f_003254a0},
    {0x325510u,f_00325510},
    {0x325740u,f_00325740},
    {0x325b40u,f_00325b40},
    {0x325e50u,f_00325e50},
    {0x327610u,f_00327610},
    {0x32e170u,f_0032e170},
    {0x32e4e0u,f_0032e4e0},
    {0x32ec50u,f_0032ec50},
    {0x3398a0u,f_003398a0},
    {0x34a380u,f_0034a380},
    {0x351f70u,f_00351f70},
    {0x351fb0u,f_00351fb0},
    {0x351fd0u,f_00351fd0},
    {0x3556c0u,f_003556c0},
    {0x355740u,f_00355740},
    {0x356f70u,f_00356f70},
    {0x357030u,f_00357030},
    {0x359de0u,f_00359de0},
    {0x35a710u,f_0035a710},
    {0x35b300u,f_0035b300},
    {0x35b350u,f_0035b350},
    {0x35b4b0u,f_0035b4b0},
    {0x35b5a0u,f_0035b5a0},
    {0x35b710u,f_0035b710},
    {0x35b790u,f_0035b790},
    {0x35baf0u,f_0035baf0},
    {0x35c230u,f_0035c230},
    {0x35c2c0u,f_0035c2c0},
    {0x35ca00u,f_0035ca00},
    {0x363590u,f_00363590},
    {0x363c90u,f_00363c90},
    {0x36d5ccu,f_0036d5cc},
    {0x36d5f5u,f_0036d5f5},
    {0x36da34u,f_0036da34},
    {0x36dffcu,f_0036dffc},
    {0x36e113u,f_0036e113},
    {0x36e24cu,f_0036e24c},
    {0x36f0a4u,f_0036f0a4},
    {0x36f29bu,f_0036f29b},
    {0x36f2ccu,f_0036f2cc},
    {0x36f318u,f_0036f318},
    {0x36f354u,f_0036f354},
    {0x36f398u,f_0036f398},
    {0x36f4d3u,f_0036f4d3},
    {0x36f524u,f_0036f524},
    {0x36f753u,f_0036f753},
    {0x36fcdcu,f_0036fcdc},
    {0x36fd0bu,f_0036fd0b},
    {0x3702bau,f_003702ba},
    {0x37030bu,f_0037030b},
    {0x37068du,f_0037068d},
    {0x3706dbu,f_003706db},
    {0x370711u,f_00370711},
    {0x371101u,f_00371101},
    {0x371162u,f_00371162},
    {0x3711afu,f_003711af},
    {0x371cfau,f_00371cfa},
    {0x3727a8u,f_003727a8},
    {0x372a98u,f_00372a98},
    {0x372ae9u,f_00372ae9},
    {0x37439fu,f_0037439f},
    {0x374915u,f_00374915},
    {0x3751dbu,f_003751db},
    {0x375260u,f_00375260},
    {0x376634u,f_00376634},
    {0x376a3fu,f_00376a3f},
    {0x376a5bu,f_00376a5b},
    {0x376a98u,f_00376a98},
    {0x376ae2u,f_00376ae2},
    {0x3775b6u,f_003775b6},
    {0x3780fcu,f_003780fc},
    {0x378d44u,f_00378d44},
    {0x379146u,f_00379146},
    {0x3795fdu,f_003795fd},
    {0x37aa92u,f_0037aa92},
    {0x37b678u,f_0037b678},
    {0x37bd01u,f_0037bd01},
    {0x37bd2eu,f_0037bd2e},
    {0x37bd5cu,f_0037bd5c},
    {0x37bd89u,f_0037bd89},
    {0x37d445u,f_0037d445},
    {0x37dbc9u,f_0037dbc9},
    {0x37dd4fu,f_0037dd4f},
    {0x37dde6u,f_0037dde6},
    {0x37e0b1u,f_0037e0b1},
    {0x37eb82u,f_0037eb82},
    {0x37f2a9u,f_0037f2a9},
    {0x38042fu,f_0038042f},
    {0x380f61u,f_00380f61},
    {0x3817c4u,f_003817c4},
    {0x381895u,f_00381895},
    {0x381942u,f_00381942},
    {0x381d27u,f_00381d27},
    {0x382963u,f_00382963},
    {0x382bccu,f_00382bcc},
  }}; return entries;
}
} // namespace ra2::recovered::direct_b34
