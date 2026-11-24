#include "recovered/transfers_b38_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::transfers_b38 {
namespace {
void f_001bd7d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5bd7d0: b9c2000000 MOV ECX,0xc2
    s.cx = 0x000000c2u;
  }
  { // 0x5bd7d5: e826cd1600 CALL 0x0072a500
    const std::uint32_t call_target=0x0072a500u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5bd7da: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5bd7dc: 7526 JNZ 0x005bd804
    if(integer::condition("JNZ",flags)) goto L005bd804;
  }
  L005bd7de: { // 0x5bd7de: b9c9000000 MOV ECX,0xc9
    s.cx = 0x000000c9u;
  }
  { // 0x5bd7e3: e818cd1600 CALL 0x0072a500
    const std::uint32_t call_target=0x0072a500u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x5bd7e8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5bd7ea: 7518 JNZ 0x005bd804
    if(integer::condition("JNZ",flags)) goto L005bd804;
  }
  L005bd7ec: { // 0x5bd7ec: b9bc000000 MOV ECX,0xbc
    s.cx = 0x000000bcu;
  }
  { // 0x5bd7f1: e80acd1600 CALL 0x0072a500
    const std::uint32_t call_target=0x0072a500u;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x5bd7f6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5bd7f8: 750a JNZ 0x005bd804
    if(integer::condition("JNZ",flags)) goto L005bd804;
  }
  L005bd7fa: { // 0x5bd7fa: b9bd000000 MOV ECX,0xbd
    s.cx = 0x000000bdu;
  }
  { // 0x5bd7ff: e9fccc1600 JMP 0x0072a500
    const std::uint32_t target=0x0072a500u;
    transfer(m,s,f,op,3u,target); return;
  }
  L005bd804: { // 0x5bd804: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001be010(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5be010: 8b0de055a200 MOV ECX,dword ptr [0x00a255e0]
    s.cx = m.r32((0x00a255e0u));
  }
  { // 0x5be016: e8d55affff CALL 0x005b3af0
    const std::uint32_t call_target=0x005b3af0u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5be01b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5be01d: 7505 JNZ 0x005be024
    if(integer::condition("JNZ",flags)) goto L005be024;
  }
  L005be01f: { // 0x5be01f: e9ac59ffff JMP 0x005b39d0
    const std::uint32_t target=0x005b39d0u;
    transfer(m,s,f,op,1u,target); return;
  }
  L005be024: { // 0x5be024: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001be760(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5be760: a174a8a500 MOV EAX,[0x00a5a874]
    s.ax = m.r32((0x00a5a874u));
  }
  { // 0x5be765: c605e47da20001 MOV byte ptr [0x00a27de4],0x1
    m.w8((0x00a27de4u), 0x00000001u);
  }
  { // 0x5be76c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5be76e: 7405 JZ 0x005be775
    if(integer::condition("JZ",flags)) goto L005be775;
  }
  L005be770: { // 0x5be770: e9fbb91800 JMP 0x0074a170
    const std::uint32_t target=0x0074a170u;
    transfer(m,s,f,op,0u,target); return;
  }
  L005be775: { // 0x5be775: e9f6ecffff JMP 0x005bd470
    const std::uint32_t target=0x005bd470u;
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_001c1550(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c1550: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x5c1555: 8b0de455a200 MOV ECX,dword ptr [0x00a255e4]
    s.cx = m.r32((0x00a255e4u));
  }
  { // 0x5c155b: 898834080000 MOV dword ptr [EAX + 0x834],ECX
    m.w32((s.ax+0x00000834u), s.cx);
  }
  { // 0x5c1561: a1b87da200 MOV EAX,[0x00a27db8]
    s.ax = m.r32((0x00a27db8u));
  }
  { // 0x5c1566: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c1567: 6840147d00 PUSH 0x7d1440
    f.push(m,0x007d1440u);
  }
  { // 0x5c156c: c7056c89a20000000000 MOV dword ptr [0x00a2896c],0x0
    m.w32((0x00a2896cu), 0x00000000u);
  }
  { // 0x5c1576: a38c58a200 MOV [0x00a2588c],EAX
    m.w32((0x00a2588cu), s.ax);
  }
  { // 0x5c157b: e87053e4ff CALL 0x004068f0
    const std::uint32_t call_target=0x004068f0u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5c1580: a0f055a200 MOV AL,[0x00a255f0]
    s.ax = with_al(s.ax, m.r8((0x00a255f0u)));
  }
  { // 0x5c1585: 8a0d6d56a200 MOV CL,byte ptr [0x00a2566d]
    s.cx = with_al(s.cx, m.r8((0x00a2566du)));
  }
  { // 0x5c158b: 8b15f855a200 MOV EDX,dword ptr [0x00a255f8]
    s.dx = m.r32((0x00a255f8u));
  }
  { // 0x5c1591: 83e001 AND EAX,0x1
    s.ax = integer::logical((s.ax)&(0x00000001u),32,flags);
  }
  { // 0x5c1594: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x5c1597: 83e101 AND ECX,0x1
    s.cx = integer::logical((s.cx)&(0x00000001u),32,flags);
  }
  { // 0x5c159a: 89155887a200 MOV dword ptr [0x00a28758],EDX
    m.w32((0x00a28758u), s.dx);
  }
  { // 0x5c15a0: 8b157085a200 MOV EDX,dword ptr [0x00a28570]
    s.dx = m.r32((0x00a28570u));
  }
  { // 0x5c15a6: 0bc1 OR EAX,ECX
    s.ax = integer::logical((s.ax)|(s.cx),32,flags);
  }
  { // 0x5c15a8: c1e00b SHL EAX,0xb
    s.ax = integer::shift(s.ax,0x0000000bu,32,flags,integer::Shift::left);
  }
  { // 0x5c15ab: 80e677 AND DH,0x77
    s.dx = (s.dx & 0xffff00ffu) | (((integer::logical((((s.dx >> 8) & 0xffu))&(0x00000077u),8,flags)) & 0xffu) << 8);
  }
  { // 0x5c15ae: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5c15b1: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  { // 0x5c15b3: c705dc55a20002000000 MOV dword ptr [0x00a255dc],0x2
    m.w32((0x00a255dcu), 0x00000002u);
  }
  { // 0x5c15bd: 0cc0 OR AL,0xc0
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x000000c0u),8,flags));
  }
  { // 0x5c15bf: b97085a200 MOV ECX,0xa28570
    s.cx = 0x00a28570u;
  }
  { // 0x5c15c4: a37085a200 MOV [0x00a28570],EAX
    m.w32((0x00a28570u), s.ax);
  }
  { // 0x5c15c9: e942f50b00 JMP 0x00680b10
    const std::uint32_t target=0x00680b10u;
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_001c3d10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c3d10: 8b048dc47da200 MOV EAX,dword ptr [ECX*0x4 + 0xa27dc4]
    s.ax = m.r32(((s.cx * 0x00000004u)+0x00a27dc4u));
  }
  { // 0x5c3d17: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5c3d19: 7420 JZ 0x005c3d3b
    if(integer::condition("JZ",flags)) goto L005c3d3b;
  }
  L005c3d1b: { // 0x5c3d1b: 3b05a4a8a500 CMP EAX,dword ptr [0x00a5a8a4]
    (void)integer::sub(s.ax,m.r32((0x00a5a8a4u)),32,flags);
  }
  { // 0x5c3d21: 7410 JZ 0x005c3d33
    if(integer::condition("JZ",flags)) goto L005c3d33;
  }
  L005c3d23: { // 0x5c3d23: 3b05a8a8a500 CMP EAX,dword ptr [0x00a5a8a8]
    (void)integer::sub(s.ax,m.r32((0x00a5a8a8u)),32,flags);
  }
  { // 0x5c3d29: 7408 JZ 0x005c3d33
    if(integer::condition("JZ",flags)) goto L005c3d33;
  }
  L005c3d2b: { // 0x5c3d2b: 3b05aca8a500 CMP EAX,dword ptr [0x00a5a8ac]
    (void)integer::sub(s.ax,m.r32((0x00a5a8acu)),32,flags);
  }
  { // 0x5c3d31: 7508 JNZ 0x005c3d3b
    if(integer::condition("JNZ",flags)) goto L005c3d3b;
  }
  L005c3d33: { // 0x5c3d33: 8b048d4c56a200 MOV EAX,dword ptr [ECX*0x4 + 0xa2564c]
    s.ax = m.r32(((s.cx * 0x00000004u)+0x00a2564cu));
  }
  { // 0x5c3d3a: c3 RET
    finish(m,s,f,0u); return;
  }
  L005c3d3b: { // 0x5c3d3b: 3b059ca8a500 CMP EAX,dword ptr [0x00a5a89c]
    (void)integer::sub(s.ax,m.r32((0x00a5a89cu)),32,flags);
  }
  { // 0x5c3d41: 7417 JZ 0x005c3d5a
    if(integer::condition("JZ",flags)) goto L005c3d5a;
  }
  L005c3d43: { // 0x5c3d43: 3b05a0a8a500 CMP EAX,dword ptr [0x00a5a8a0]
    (void)integer::sub(s.ax,m.r32((0x00a5a8a0u)),32,flags);
  }
  { // 0x5c3d49: 740f JZ 0x005c3d5a
    if(integer::condition("JZ",flags)) goto L005c3d5a;
  }
  L005c3d4b: { // 0x5c3d4b: 3b05b0a8a500 CMP EAX,dword ptr [0x00a5a8b0]
    (void)integer::sub(s.ax,m.r32((0x00a5a8b0u)),32,flags);
  }
  { // 0x5c3d51: 7407 JZ 0x005c3d5a
    if(integer::condition("JZ",flags)) goto L005c3d5a;
  }
  L005c3d53: { // 0x5c3d53: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5c3d55: e936110a00 JMP 0x00664e90
    const std::uint32_t target=0x00664e90u;
    transfer(m,s,f,op,0u,target); return;
  }
  L005c3d5a: { // 0x5c3d5a: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  { // 0x5c3d5f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c70f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c70f0: f6052879a20002 TEST byte ptr [0x00a27928],0x2
    (void)integer::logical((m.r8((0x00a27928u)))&(0x00000002u),8,flags);
  }
  { // 0x5c70f7: 7513 JNZ 0x005c710c
    if(integer::condition("JNZ",flags)) goto L005c710c;
  }
  L005c70f9: { // 0x5c70f9: 833dc855a20001 CMP dword ptr [0x00a255c8],0x1
    (void)integer::sub(m.r32((0x00a255c8u)),0x00000001u,32,flags);
  }
  { // 0x5c7100: 750a JNZ 0x005c710c
    if(integer::condition("JNZ",flags)) goto L005c710c;
  }
  L005c7102: { // 0x5c7102: b96886a200 MOV ECX,0xa28668
    s.cx = 0x00a28668u;
  }
  { // 0x5c7107: e8f4300000 CALL 0x005ca200
    const std::uint32_t call_target=0x005ca200u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L005c710c: { // 0x5c710c: b96886a200 MOV ECX,0xa28668
    s.cx = 0x00a28668u;
  }
  { // 0x5c7111: e9ea1a0000 JMP 0x005c8c00
    const std::uint32_t target=0x005c8c00u;
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_001c71d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c71d0: 8b0d647ea200 MOV ECX,dword ptr [0x00a27e64]
    s.cx = m.r32((0x00a27e64u));
  }
  { // 0x5c71d6: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x5c71d8: 83f903 CMP ECX,0x3
    (void)integer::sub(s.cx,0x00000003u,32,flags);
  }
  { // 0x5c71db: 7742 JA 0x005c721f
    if(integer::condition("JA",flags)) goto L005c721f;
  }
  L005c71dd: { // 0x5c71dd: ff248d20725c00 JMP dword ptr [ECX*0x4 + 0x5c7220]
    const std::uint32_t destination=m.r32(((s.cx * 0x00000004u)+0x005c7220u));
    switch(destination) {
      case 0x5c71e4u: goto L005c71e4;
      case 0x5c71f2u: goto L005c71f2;
      case 0x5c7204u: goto L005c7204;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L005c71e4: { // 0x5c71e4: b96886a200 MOV ECX,0xa28668
    s.cx = 0x00a28668u;
  }
  { // 0x5c71e9: e8f2320000 CALL 0x005ca4e0
    const std::uint32_t call_target=0x005ca4e0u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5c71ee: a880 TEST AL,0x80
    (void)integer::logical(((s.ax & 0xffu))&(0x00000080u),8,flags);
  }
  { // 0x5c71f0: 7405 JZ 0x005c71f7
    if(integer::condition("JZ",flags)) goto L005c71f7;
  }
  L005c71f2: { // 0x5c71f2: e969020000 JMP 0x005c7460
    const std::uint32_t target=0x005c7460u;
    transfer(m,s,f,op,1u,target); return;
  }
  L005c71f7: { // 0x5c71f7: 8b0d2ca9a500 MOV ECX,dword ptr [0x00a5a92c]
    s.cx = m.r32((0x00a5a92cu));
  }
  { // 0x5c71fd: b201 MOV DL,0x1
    s.dx = with_al(s.dx, 0x00000001u);
  }
  { // 0x5c71ff: e93c050000 JMP 0x005c7740
    const std::uint32_t target=0x005c7740u;
    transfer(m,s,f,op,2u,target); return;
  }
  L005c7204: { // 0x5c7204: b96886a200 MOV ECX,0xa28668
    s.cx = 0x00a28668u;
  }
  { // 0x5c7209: e8d2320000 CALL 0x005ca4e0
    const std::uint32_t call_target=0x005ca4e0u;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x5c720e: a880 TEST AL,0x80
    (void)integer::logical(((s.ax & 0xffu))&(0x00000080u),8,flags);
  }
  { // 0x5c7210: 75e0 JNZ 0x005c71f2
    if(integer::condition("JNZ",flags)) goto L005c71f2;
  }
  L005c7212: { // 0x5c7212: 8b0d2ca9a500 MOV ECX,dword ptr [0x00a5a92c]
    s.cx = m.r32((0x00a5a92cu));
  }
  { // 0x5c7218: b201 MOV DL,0x1
    s.dx = with_al(s.dx, 0x00000001u);
  }
  { // 0x5c721a: e8f10b0000 CALL 0x005c7e10
    const std::uint32_t call_target=0x005c7e10u;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L005c721f: { // 0x5c721f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c8f70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c8f70: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  { // 0x5c8f73: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5c8f75: 7408 JZ 0x005c8f7f
    if(integer::condition("JZ",flags)) goto L005c8f7f;
  }
  L005c8f77: { // 0x5c8f77: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x5c8f7a: e95176ebff JMP 0x004805d0
    const std::uint32_t target=0x004805d0u;
    transfer(m,s,f,op,0u,target); return;
  }
  L005c8f7f: { // 0x5c8f7f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5c8f81: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001cae40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cae40: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5cae42: ff9084000000 CALL dword ptr [EAX + 0x84]
    const std::uint32_t call_target=m.r32((s.ax+0x00000084u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5cae48: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x5cae4a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5cae4c: ffa29c000000 JMP dword ptr [EDX + 0x9c]
    const std::uint32_t target=m.r32((s.dx+0x0000009cu));
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_00201870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x601870: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x601871: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x601873: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  { // 0x601879: 8b80e4020000 MOV EAX,dword ptr [EAX + 0x2e4]
    s.ax = m.r32((s.ax+0x000002e4u));
  }
  { // 0x60187f: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  { // 0x601882: 7732 JA 0x006018b6
    if(integer::condition("JA",flags)) goto L006018b6;
  }
  L00601884: { // 0x601884: ff2485d0186000 JMP dword ptr [EAX*0x4 + 0x6018d0]
    const std::uint32_t destination=m.r32(((s.ax * 0x00000004u)+0x006018d0u));
    switch(destination) {
      case 0x60188bu: goto L0060188b;
      case 0x601894u: goto L00601894;
      case 0x60189du: goto L0060189d;
      case 0x6018a6u: goto L006018a6;
      case 0x6018afu: goto L006018af;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L0060188b: { // 0x60188b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x60188d: e8feeeffff CALL 0x00600790
    const std::uint32_t call_target=0x00600790u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x601892: eb22 JMP 0x006018b6
    goto L006018b6;
  }
  L00601894: { // 0x601894: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x601896: e8e5f6ffff CALL 0x00600f80
    const std::uint32_t call_target=0x00600f80u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x60189b: eb19 JMP 0x006018b6
    goto L006018b6;
  }
  L0060189d: { // 0x60189d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x60189f: e8acfcffff CALL 0x00601550
    const std::uint32_t call_target=0x00601550u;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6018a4: eb10 JMP 0x006018b6
    goto L006018b6;
  }
  L006018a6: { // 0x6018a6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6018a8: e873f8ffff CALL 0x00601120
    const std::uint32_t call_target=0x00601120u;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x6018ad: eb07 JMP 0x006018b6
    goto L006018b6;
  }
  L006018af: { // 0x6018af: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6018b1: e82af5ffff CALL 0x00600de0
    const std::uint32_t call_target=0x00600de0u;
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L006018b6: { // 0x6018b6: 66ff8e18010000 DEC word ptr [ESI + 0x118]
    m.w16((s.si+0x00000118u), integer::decrement(m.r16((s.si+0x00000118u)),16,flags));
  }
  { // 0x6018bd: 6683be1801000000 CMP word ptr [ESI + 0x118],0x0
    (void)integer::sub(m.r16((s.si+0x00000118u)),0x00000000u,16,flags);
  }
  { // 0x6018c5: 7507 JNZ 0x006018ce
    if(integer::condition("JNZ",flags)) goto L006018ce;
  }
  L006018c7: { // 0x6018c7: c6862101000001 MOV byte ptr [ESI + 0x121],0x1
    m.w8((s.si+0x00000121u), 0x00000001u);
  }
  L006018ce: { // 0x6018ce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6018cf: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002066f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6066f0: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  { // 0x6066f3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6066f5: 7405 JZ 0x006066fc
    if(integer::condition("JZ",flags)) goto L006066fc;
  }
  L006066f7: { // 0x6066f7: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x6066f9: ff6004 JMP dword ptr [EAX + 0x4]
    const std::uint32_t target=m.r32((s.ax+0x00000004u));
    transfer(m,s,f,op,0u,target); return;
  }
  L006066fc: { // 0x6066fc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6066fe: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0020f9d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x60f9d0: 8a5112 MOV DL,byte ptr [ECX + 0x12]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000012u)));
  }
  { // 0x60f9d3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x60f9d5: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x60f9d7: 7408 JZ 0x0060f9e1
    if(integer::condition("JZ",flags)) goto L0060f9e1;
  }
  L0060f9d9: { // 0x60f9d9: 83c10e ADD ECX,0xe
    s.cx = integer::add(s.cx,0x0000000eu,32,flags);
  }
  { // 0x60f9dc: e97fb40900 JMP 0x006aae60
    const std::uint32_t target=0x006aae60u;
    transfer(m,s,f,op,0u,target); return;
  }
  L0060f9e1: { // 0x60f9e1: 8a511c MOV DL,byte ptr [ECX + 0x1c]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000001cu)));
  }
  { // 0x60f9e4: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x60f9e6: 7408 JZ 0x0060f9f0
    if(integer::condition("JZ",flags)) goto L0060f9f0;
  }
  L0060f9e8: { // 0x60f9e8: 83c118 ADD ECX,0x18
    s.cx = integer::add(s.cx,0x00000018u,32,flags);
  }
  { // 0x60f9eb: e970b40900 JMP 0x006aae60
    const std::uint32_t target=0x006aae60u;
    transfer(m,s,f,op,1u,target); return;
  }
  L0060f9f0: { // 0x60f9f0: 8a5117 MOV DL,byte ptr [ECX + 0x17]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000017u)));
  }
  { // 0x60f9f3: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x60f9f5: 7408 JZ 0x0060f9ff
    if(integer::condition("JZ",flags)) goto L0060f9ff;
  }
  L0060f9f7: { // 0x60f9f7: 83c113 ADD ECX,0x13
    s.cx = integer::add(s.cx,0x00000013u,32,flags);
  }
  { // 0x60f9fa: e961b40900 JMP 0x006aae60
    const std::uint32_t target=0x006aae60u;
    transfer(m,s,f,op,2u,target); return;
  }
  L0060f9ff: { // 0x60f9ff: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00211eb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x611eb0: 0fbe410c MOVSX EAX,byte ptr [ECX + 0xc]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000000cu)),8));
  }
  { // 0x611eb4: 83f80b CMP EAX,0xb
    (void)integer::sub(s.ax,0x0000000bu,32,flags);
  }
  { // 0x611eb7: 7505 JNZ 0x00611ebe
    if(integer::condition("JNZ",flags)) goto L00611ebe;
  }
  L00611eb9: { // 0x611eb9: e902970d00 JMP 0x006eb5c0
    const std::uint32_t target=0x006eb5c0u;
    transfer(m,s,f,op,0u,target); return;
  }
  L00611ebe: { // 0x611ebe: 83f81d CMP EAX,0x1d
    (void)integer::sub(s.ax,0x0000001du,32,flags);
  }
  { // 0x611ec1: 7505 JNZ 0x00611ec8
    if(integer::condition("JNZ",flags)) goto L00611ec8;
  }
  L00611ec3: { // 0x611ec3: e9e8960d00 JMP 0x006eb5b0
    const std::uint32_t target=0x006eb5b0u;
    transfer(m,s,f,op,1u,target); return;
  }
  L00611ec8: { // 0x611ec8: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x611ecb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00216a40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x616a40: 8b8180000000 MOV EAX,dword ptr [ECX + 0x80]
    s.ax = m.r32((s.cx+0x00000080u));
  }
  { // 0x616a46: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x616a4b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x616a4d: 750a JNZ 0x00616a59
    if(integer::condition("JNZ",flags)) goto L00616a59;
  }
  L00616a4f: { // 0x616a4f: b9d05f7d00 MOV ECX,0x7d5fd0
    s.cx = 0x007d5fd0u;
  }
  { // 0x616a54: e987420400 JMP 0x0065ace0
    const std::uint32_t target=0x0065ace0u;
    transfer(m,s,f,op,0u,target); return;
  }
  L00616a59: { // 0x616a59: b9c45f7d00 MOV ECX,0x7d5fc4
    s.cx = 0x007d5fc4u;
  }
  { // 0x616a5e: e97d420400 JMP 0x0065ace0
    const std::uint32_t target=0x0065ace0u;
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_00216a70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x616a70: 8b8180000000 MOV EAX,dword ptr [ECX + 0x80]
    s.ax = m.r32((s.cx+0x00000080u));
  }
  { // 0x616a76: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x616a7b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x616a7d: 750a JNZ 0x00616a89
    if(integer::condition("JNZ",flags)) goto L00616a89;
  }
  L00616a7f: { // 0x616a7f: b9d05f7d00 MOV ECX,0x7d5fd0
    s.cx = 0x007d5fd0u;
  }
  { // 0x616a84: e957420400 JMP 0x0065ace0
    const std::uint32_t target=0x0065ace0u;
    transfer(m,s,f,op,0u,target); return;
  }
  L00616a89: { // 0x616a89: b9c45f7d00 MOV ECX,0x7d5fc4
    s.cx = 0x007d5fc4u;
  }
  { // 0x616a8e: e94d420400 JMP 0x0065ace0
    const std::uint32_t target=0x0065ace0u;
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_00219c70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x619c70: 8d41ff LEA EAX,[ECX + -0x1]
    s.ax = (s.cx-0x00000001u);
  }
  { // 0x619c73: 83f80a CMP EAX,0xa
    (void)integer::sub(s.ax,0x0000000au,32,flags);
  }
  { // 0x619c76: 773d JA 0x00619cb5
    if(integer::condition("JA",flags)) goto L00619cb5;
  }
  L00619c78: { // 0x619c78: ff2485b89c6100 JMP dword ptr [EAX*0x4 + 0x619cb8]
    const std::uint32_t destination=m.r32(((s.ax * 0x00000004u)+0x00619cb8u));
    switch(destination) {
      case 0x619c7fu: goto L00619c7f;
      case 0x619c85u: goto L00619c85;
      case 0x619c8bu: goto L00619c8b;
      case 0x619c91u: goto L00619c91;
      case 0x619c97u: goto L00619c97;
      case 0x619c9du: goto L00619c9d;
      case 0x619ca3u: goto L00619ca3;
      case 0x619ca9u: goto L00619ca9;
      case 0x619cafu: goto L00619caf;
      case 0x619cb5u: goto L00619cb5;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L00619c7f: { // 0x619c7f: b820000000 MOV EAX,0x20
    s.ax = 0x00000020u;
  }
  { // 0x619c84: c3 RET
    finish(m,s,f,0u); return;
  }
  L00619c85: { // 0x619c85: b840000000 MOV EAX,0x40
    s.ax = 0x00000040u;
  }
  { // 0x619c8a: c3 RET
    finish(m,s,f,0u); return;
  }
  L00619c8b: { // 0x619c8b: b808000000 MOV EAX,0x8
    s.ax = 0x00000008u;
  }
  { // 0x619c90: c3 RET
    finish(m,s,f,0u); return;
  }
  L00619c91: { // 0x619c91: b810000000 MOV EAX,0x10
    s.ax = 0x00000010u;
  }
  { // 0x619c96: c3 RET
    finish(m,s,f,0u); return;
  }
  L00619c97: { // 0x619c97: b800100000 MOV EAX,0x1000
    s.ax = 0x00001000u;
  }
  { // 0x619c9c: c3 RET
    finish(m,s,f,0u); return;
  }
  L00619c9d: { // 0x619c9d: b800200000 MOV EAX,0x2000
    s.ax = 0x00002000u;
  }
  { // 0x619ca2: c3 RET
    finish(m,s,f,0u); return;
  }
  L00619ca3: { // 0x619ca3: b800080000 MOV EAX,0x800
    s.ax = 0x00000800u;
  }
  { // 0x619ca8: c3 RET
    finish(m,s,f,0u); return;
  }
  L00619ca9: { // 0x619ca9: b800800000 MOV EAX,0x8000
    s.ax = 0x00008000u;
  }
  { // 0x619cae: c3 RET
    finish(m,s,f,0u); return;
  }
  L00619caf: { // 0x619caf: b800000100 MOV EAX,0x10000
    s.ax = 0x00010000u;
  }
  { // 0x619cb4: c3 RET
    finish(m,s,f,0u); return;
  }
  L00619cb5: { // 0x619cb5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x619cb7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00230ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x630ab0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x630ab2: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x630ab5: c700cc3c7900 MOV dword ptr [EAX],0x793ccc
    m.w32((s.ax), 0x00793cccu);
  }
  { // 0x630abb: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x630abd: 740c JZ 0x00630acb
    if(integer::condition("JZ",flags)) goto L00630acb;
  }
  L00630abf: { // 0x630abf: c7400400000000 MOV dword ptr [EAX + 0x4],0x0
    m.w32((s.ax+0x00000004u), 0x00000000u);
  }
  { // 0x630ac6: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x630ac8: ff6008 JMP dword ptr [EAX + 0x8]
    const std::uint32_t target=m.r32((s.ax+0x00000008u));
    transfer(m,s,f,op,0u,target); return;
  }
  L00630acb: { // 0x630acb: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002a0380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a0380: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  { // 0x6a0385: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a0387: 7418 JZ 0x006a03a1
    if(integer::condition("JZ",flags)) goto L006a03a1;
  }
  L006a0389: { // 0x6a0389: a1a488a200 MOV EAX,[0x00a288a4]
    s.ax = m.r32((0x00a288a4u));
  }
  { // 0x6a038e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x6a0390: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x6a0392: ff9244010000 CALL dword ptr [EDX + 0x144]
    const std::uint32_t call_target=m.r32((s.dx+0x00000144u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6a0398: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  { // 0x6a039d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a039f: 75e8 JNZ 0x006a0389
    if(integer::condition("JNZ",flags)) goto L006a0389;
  }
  L006a03a1: { // 0x6a03a1: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x6a03a3: e938b20400 JMP 0x006eb5e0
    const std::uint32_t target=0x006eb5e0u;
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_002a8440(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a8440: 83c1f2 ADD ECX,-0xe
    s.cx = integer::add(s.cx,0xfffffff2u,32,flags);
  }
  { // 0x6a8443: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6a8445: 83f961 CMP ECX,0x61
    (void)integer::sub(s.cx,0x00000061u,32,flags);
  }
  { // 0x6a8448: 7714 JA 0x006a845e
    if(integer::condition("JA",flags)) goto L006a845e;
  }
  L006a844a: { // 0x6a844a: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x6a844c: 8a9168846a00 MOV DL,byte ptr [ECX + 0x6a8468]
    s.dx = with_al(s.dx, m.r8((s.cx+0x006a8468u)));
  }
  { // 0x6a8452: ff249560846a00 JMP dword ptr [EDX*0x4 + 0x6a8460]
    const std::uint32_t destination=m.r32(((s.dx * 0x00000004u)+0x006a8460u));
    switch(destination) {
      case 0x6a8459u: goto L006a8459;
      case 0x6a845eu: goto L006a845e;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L006a8459: { // 0x6a8459: b802000000 MOV EAX,0x2
    s.ax = 0x00000002u;
  }
  L006a845e: { // 0x6a845e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002cd950(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6cd950: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x6cd952: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6cd958: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6cd95a: e991720000 JMP 0x006d4bf0
    const std::uint32_t target=0x006d4bf0u;
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_002ce490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ce490: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x6ce492: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6ce498: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x6ce49a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6ce49c: ffa2a0000000 JMP dword ptr [EDX + 0xa0]
    const std::uint32_t target=m.r32((s.dx+0x000000a0u));
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_002ce4b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ce4b0: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x6ce4b2: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6ce4b8: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x6ce4ba: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6ce4bc: ffa2a4000000 JMP dword ptr [EDX + 0xa4]
    const std::uint32_t target=m.r32((s.dx+0x000000a4u));
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_002dbcf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6dbcf0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6dbcf1: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6dbcf3: 83f936 CMP ECX,0x36
    (void)integer::sub(s.cx,0x00000036u,32,flags);
  }
  { // 0x6dbcf6: 7714 JA 0x006dbd0c
    if(integer::condition("JA",flags)) goto L006dbd0c;
  }
  L006dbcf8: { // 0x6dbcf8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6dbcfa: 8a8170bd6d00 MOV AL,byte ptr [ECX + 0x6dbd70]
    s.ax = with_al(s.ax, m.r8((s.cx+0x006dbd70u)));
  }
  { // 0x6dbd00: ff248568bd6d00 JMP dword ptr [EAX*0x4 + 0x6dbd68]
    const std::uint32_t destination=m.r32(((s.ax * 0x00000004u)+0x006dbd68u));
    switch(destination) {
      case 0x6dbd07u: goto L006dbd07;
      case 0x6dbd0cu: goto L006dbd0c;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L006dbd07: { // 0x6dbd07: be01000000 MOV ESI,0x1
    s.si = 0x00000001u;
  }
  L006dbd0c: { // 0x6dbd0c: 83f931 CMP ECX,0x31
    (void)integer::sub(s.cx,0x00000031u,32,flags);
  }
  { // 0x6dbd0f: 7712 JA 0x006dbd23
    if(integer::condition("JA",flags)) goto L006dbd23;
  }
  L006dbd11: { // 0x6dbd11: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x6dbd13: 8a91b0bd6d00 MOV DL,byte ptr [ECX + 0x6dbdb0]
    s.dx = with_al(s.dx, m.r8((s.cx+0x006dbdb0u)));
  }
  { // 0x6dbd19: ff2495a8bd6d00 JMP dword ptr [EDX*0x4 + 0x6dbda8]
    const std::uint32_t destination=m.r32(((s.dx * 0x00000004u)+0x006dbda8u));
    switch(destination) {
      case 0x6dbd20u: goto L006dbd20;
      case 0x6dbd23u: goto L006dbd23;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L006dbd20: { // 0x6dbd20: 83ce02 OR ESI,0x2
    s.si = integer::logical((s.si)|(0x00000002u),32,flags);
  }
  L006dbd23: { // 0x6dbd23: 83f908 CMP ECX,0x8
    (void)integer::sub(s.cx,0x00000008u,32,flags);
  }
  { // 0x6dbd26: 7405 JZ 0x006dbd2d
    if(integer::condition("JZ",flags)) goto L006dbd2d;
  }
  L006dbd28: { // 0x6dbd28: 83f918 CMP ECX,0x18
    (void)integer::sub(s.cx,0x00000018u,32,flags);
  }
  { // 0x6dbd2b: 7503 JNZ 0x006dbd30
    if(integer::condition("JNZ",flags)) goto L006dbd30;
  }
  L006dbd2d: { // 0x6dbd2d: 83ce04 OR ESI,0x4
    s.si = integer::logical((s.si)|(0x00000004u),32,flags);
  }
  L006dbd30: { // 0x6dbd30: 8d51fd LEA EDX,[ECX + -0x3]
    s.dx = (s.cx-0x00000003u);
  }
  { // 0x6dbd33: 83fa36 CMP EDX,0x36
    (void)integer::sub(s.dx,0x00000036u,32,flags);
  }
  { // 0x6dbd36: 7712 JA 0x006dbd4a
    if(integer::condition("JA",flags)) goto L006dbd4a;
  }
  L006dbd38: { // 0x6dbd38: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6dbd3a: 8a82ecbd6d00 MOV AL,byte ptr [EDX + 0x6dbdec]
    s.ax = with_al(s.ax, m.r8((s.dx+0x006dbdecu)));
  }
  { // 0x6dbd40: ff2485e4bd6d00 JMP dword ptr [EAX*0x4 + 0x6dbde4]
    const std::uint32_t destination=m.r32(((s.ax * 0x00000004u)+0x006dbde4u));
    switch(destination) {
      case 0x6dbd47u: goto L006dbd47;
      case 0x6dbd4au: goto L006dbd4a;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L006dbd47: { // 0x6dbd47: 83ce08 OR ESI,0x8
    s.si = integer::logical((s.si)|(0x00000008u),32,flags);
  }
  L006dbd4a: { // 0x6dbd4a: 83c1f8 ADD ECX,-0x8
    s.cx = integer::add(s.cx,0xfffffff8u,32,flags);
  }
  { // 0x6dbd4d: 83f92b CMP ECX,0x2b
    (void)integer::sub(s.cx,0x0000002bu,32,flags);
  }
  { // 0x6dbd50: 7712 JA 0x006dbd64
    if(integer::condition("JA",flags)) goto L006dbd64;
  }
  L006dbd52: { // 0x6dbd52: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x6dbd54: 8a912cbe6d00 MOV DL,byte ptr [ECX + 0x6dbe2c]
    s.dx = with_al(s.dx, m.r8((s.cx+0x006dbe2cu)));
  }
  { // 0x6dbd5a: ff249524be6d00 JMP dword ptr [EDX*0x4 + 0x6dbe24]
    const std::uint32_t destination=m.r32(((s.dx * 0x00000004u)+0x006dbe24u));
    switch(destination) {
      case 0x6dbd61u: goto L006dbd61;
      case 0x6dbd64u: goto L006dbd64;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L006dbd61: { // 0x6dbd61: 83ce10 OR ESI,0x10
    s.si = integer::logical((s.si)|(0x00000010u),32,flags);
  }
  L006dbd64: { // 0x6dbd64: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6dbd66: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6dbd67: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002dbfb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6dbfb0: 8b492c MOV ECX,dword ptr [ECX + 0x2c]
    s.cx = m.r32((s.cx+0x0000002cu));
  }
  { // 0x6dbfb3: 8d41ff LEA EAX,[ECX + -0x1]
    s.ax = (s.cx-0x00000001u);
  }
  { // 0x6dbfb6: 83f835 CMP EAX,0x35
    (void)integer::sub(s.ax,0x00000035u,32,flags);
  }
  { // 0x6dbfb9: 7712 JA 0x006dbfcd
    if(integer::condition("JA",flags)) goto L006dbfcd;
  }
  L006dbfbb: { // 0x6dbfbb: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x6dbfbd: 8a88d8bf6d00 MOV CL,byte ptr [EAX + 0x6dbfd8]
    s.cx = with_al(s.cx, m.r8((s.ax+0x006dbfd8u)));
  }
  { // 0x6dbfc3: ff248dd0bf6d00 JMP dword ptr [ECX*0x4 + 0x6dbfd0]
    const std::uint32_t destination=m.r32(((s.cx * 0x00000004u)+0x006dbfd0u));
    switch(destination) {
      case 0x6dbfcau: goto L006dbfca;
      case 0x6dbfcdu: goto L006dbfcd;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L006dbfca: { // 0x6dbfca: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6dbfcc: c3 RET
    finish(m,s,f,0u); return;
  }
  L006dbfcd: { // 0x6dbfcd: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6dbfcf: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e7a20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e7a20: a0048caa00 MOV AL,[0x00aa8c04]
    s.ax = with_al(s.ax, m.r8((0x00aa8c04u)));
  }
  { // 0x6e7a25: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e7a27: 756d JNZ 0x006e7a96
    if(integer::condition("JNZ",flags)) goto L006e7a96;
  }
  L006e7a29: { // 0x6e7a29: a110a78300 MOV EAX,[0x0083a710]
    s.ax = m.r32((0x0083a710u));
  }
  { // 0x6e7a2e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6e7a30: 752c JNZ 0x006e7a5e
    if(integer::condition("JNZ",flags)) goto L006e7a5e;
  }
  L006e7a32: { // 0x6e7a32: 3d80020000 CMP EAX,0x280
    (void)integer::sub(s.ax,0x00000280u,32,flags);
  }
  { // 0x6e7a37: baa78caa00 MOV EDX,0xaa8ca7
    s.dx = 0x00aa8ca7u;
  }
  { // 0x6e7a3c: 7518 JNZ 0x006e7a56
    if(integer::condition("JNZ",flags)) goto L006e7a56;
  }
  L006e7a3e: { // 0x6e7a3e: 8b0de41f7e00 MOV ECX,dword ptr [0x007e1fe4]
    s.cx = m.r32((0x007e1fe4u));
  }
  L006e7a44: { // 0x6e7a44: e807d6daff CALL 0x00495050
    const std::uint32_t call_target=0x00495050u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6e7a49: 8b0d741f7e00 MOV ECX,dword ptr [0x007e1f74]
    s.cx = m.r32((0x007e1f74u));
  }
  { // 0x6e7a4f: a3a88baa00 MOV [0x00aa8ba8],EAX
    m.w32((0x00aa8ba8u), s.ax);
  }
  { // 0x6e7a54: eb2a JMP 0x006e7a80
    goto L006e7a80;
  }
  L006e7a56: { // 0x6e7a56: 8b0de81f7e00 MOV ECX,dword ptr [0x007e1fe8]
    s.cx = m.r32((0x007e1fe8u));
  }
  { // 0x6e7a5c: ebe6 JMP 0x006e7a44
    goto L006e7a44;
  }
  L006e7a5e: { // 0x6e7a5e: 3d80020000 CMP EAX,0x280
    (void)integer::sub(s.ax,0x00000280u,32,flags);
  }
  { // 0x6e7a63: baa78caa00 MOV EDX,0xaa8ca7
    s.dx = 0x00aa8ca7u;
  }
  { // 0x6e7a68: 752d JNZ 0x006e7a97
    if(integer::condition("JNZ",flags)) goto L006e7a97;
  }
  L006e7a6a: { // 0x6e7a6a: 8b0dec1f7e00 MOV ECX,dword ptr [0x007e1fec]
    s.cx = m.r32((0x007e1fecu));
  }
  L006e7a70: { // 0x6e7a70: e8dbd5daff CALL 0x00495050
    const std::uint32_t call_target=0x00495050u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6e7a75: 8b0d781f7e00 MOV ECX,dword ptr [0x007e1f78]
    s.cx = m.r32((0x007e1f78u));
  }
  { // 0x6e7a7b: a3a88baa00 MOV [0x00aa8ba8],EAX
    m.w32((0x00aa8ba8u), s.ax);
  }
  L006e7a80: { // 0x6e7a80: 68008caa00 PUSH 0xaa8c00
    f.push(m,0x00aa8c00u);
  }
  { // 0x6e7a85: bafc8baa00 MOV EDX,0xaa8bfc
    s.dx = 0x00aa8bfcu;
  }
  { // 0x6e7a8a: e8f1f5ffff CALL 0x006e7080
    const std::uint32_t call_target=0x006e7080u;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6e7a8f: c605048caa0001 MOV byte ptr [0x00aa8c04],0x1
    m.w8((0x00aa8c04u), 0x00000001u);
  }
  L006e7a96: { // 0x6e7a96: c3 RET
    finish(m,s,f,0u); return;
  }
  L006e7a97: { // 0x6e7a97: 8b0df01f7e00 MOV ECX,dword ptr [0x007e1ff0]
    s.cx = m.r32((0x007e1ff0u));
  }
  { // 0x6e7a9d: ebd1 JMP 0x006e7a70
    goto L006e7a70;
  }
}
void f_002eb300(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6eb300: e8db42f2ff CALL 0x0060f5e0
    const std::uint32_t call_target=0x0060f5e0u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6eb305: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6eb307: 7407 JZ 0x006eb310
    if(integer::condition("JZ",flags)) goto L006eb310;
  }
  L006eb309: { // 0x6eb309: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6eb30b: e97013f2ff JMP 0x0060c680
    const std::uint32_t target=0x0060c680u;
    transfer(m,s,f,op,1u,target); return;
  }
  L006eb310: { // 0x6eb310: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x6eb312: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x6eb314: b9186c8300 MOV ECX,0x836c18
    s.cx = 0x00836c18u;
  }
  { // 0x6eb319: e82236d4ff CALL 0x0042e940
    const std::uint32_t call_target=0x0042e940u;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6eb31e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002eb330(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6eb330: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6eb331: 8ad9 MOV BL,CL
    s.bx = with_al(s.bx, (s.cx & 0xffu));
  }
  { // 0x6eb333: e80810f2ff CALL 0x0060c340
    const std::uint32_t call_target=0x0060c340u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6eb338: 8acb MOV CL,BL
    s.cx = with_al(s.cx, (s.bx & 0xffu));
  }
  { // 0x6eb33a: b201 MOV DL,0x1
    s.dx = with_al(s.dx, 0x00000001u);
  }
  { // 0x6eb33c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6eb33d: e95e37f2ff JMP 0x0060eaa0
    const std::uint32_t target=0x0060eaa0u;
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_002eb350(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6eb350: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6eb351: 8ad9 MOV BL,CL
    s.bx = with_al(s.bx, (s.cx & 0xffu));
  }
  { // 0x6eb353: e83810f2ff CALL 0x0060c390
    const std::uint32_t call_target=0x0060c390u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6eb358: 8acb MOV CL,BL
    s.cx = with_al(s.cx, (s.bx & 0xffu));
  }
  { // 0x6eb35a: 32d2 XOR DL,DL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))^((s.dx & 0xffu)),8,flags));
  }
  { // 0x6eb35c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6eb35d: e93e37f2ff JMP 0x0060eaa0
    const std::uint32_t target=0x0060eaa0u;
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_003095c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7095c0: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x7095c2: 7c21 JL 0x007095e5
    if(integer::condition("JL",flags)) goto L007095e5;
  }
  L007095c4: { // 0x7095c4: 3b0da882ab00 CMP ECX,dword ptr [0x00ab82a8]
    (void)integer::sub(s.cx,m.r32((0x00ab82a8u)),32,flags);
  }
  { // 0x7095ca: 7d19 JGE 0x007095e5
    if(integer::condition("JGE",flags)) goto L007095e5;
  }
  L007095cc: { // 0x7095cc: a19c82ab00 MOV EAX,[0x00ab829c]
    s.ax = m.r32((0x00ab829cu));
  }
  { // 0x7095d1: 8b0c88 MOV ECX,dword ptr [EAX + ECX*0x4]
    s.cx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  { // 0x7095d4: 8b09 MOV ECX,dword ptr [ECX]
    s.cx = m.r32((s.cx));
  }
  { // 0x7095d6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x7095d8: 7405 JZ 0x007095df
    if(integer::condition("JZ",flags)) goto L007095df;
  }
  L007095da: { // 0x7095da: e971bbcfff JMP 0x00405150
    const std::uint32_t target=0x00405150u;
    transfer(m,s,f,op,0u,target); return;
  }
  L007095df: { // 0x7095df: b8a4337e00 MOV EAX,0x7e33a4
    s.ax = 0x007e33a4u;
  }
  { // 0x7095e4: c3 RET
    finish(m,s,f,0u); return;
  }
  L007095e5: { // 0x7095e5: b85c8e7b00 MOV EAX,0x7b8e5c
    s.ax = 0x007b8e5cu;
  }
  { // 0x7095ea: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030a9a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70a9a0: a1d483ab00 MOV EAX,[0x00ab83d4]
    s.ax = m.r32((0x00ab83d4u));
  }
  { // 0x70a9a5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x70a9a6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x70a9a8: 8ad9 MOV BL,CL
    s.bx = with_al(s.bx, (s.cx & 0xffu));
  }
  { // 0x70a9aa: 7411 JZ 0x0070a9bd
    if(integer::condition("JZ",flags)) goto L0070a9bd;
  }
  L0070a9ac: { // 0x70a9ac: c7404802000000 MOV dword ptr [EAX + 0x48],0x2
    m.w32((s.ax+0x00000048u), 0x00000002u);
  }
  { // 0x70a9b3: c705d483ab0000000000 MOV dword ptr [0x00ab83d4],0x0
    m.w32((0x00ab83d4u), 0x00000000u);
  }
  L0070a9bd: { // 0x70a9bd: 8b0ddc83ab00 MOV ECX,dword ptr [0x00ab83dc]
    s.cx = m.r32((0x00ab83dcu));
  }
  { // 0x70a9c3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x70a9c5: 7405 JZ 0x0070a9cc
    if(integer::condition("JZ",flags)) goto L0070a9cc;
  }
  L0070a9c7: { // 0x70a9c7: e894d4cfff CALL 0x00407e60
    const std::uint32_t call_target=0x00407e60u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0070a9cc: { // 0x70a9cc: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x70a9ce: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x70a9cf: 7405 JZ 0x0070a9d6
    if(integer::condition("JZ",flags)) goto L0070a9d6;
  }
  L0070a9d1: { // 0x70a9d1: e99af9ffff JMP 0x0070a370
    const std::uint32_t target=0x0070a370u;
    transfer(m,s,f,op,1u,target); return;
  }
  L0070a9d6: { // 0x70a9d6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030ac90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70ac90: 8b0de883ab00 MOV ECX,dword ptr [0x00ab83e8]
    s.cx = m.r32((0x00ab83e8u));
  }
  { // 0x70ac96: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x70ac98: 7405 JZ 0x0070ac9f
    if(integer::condition("JZ",flags)) goto L0070ac9f;
  }
  L0070ac9a: { // 0x70ac9a: e9c1d1cfff JMP 0x00407e60
    const std::uint32_t target=0x00407e60u;
    transfer(m,s,f,op,0u,target); return;
  }
  L0070ac9f: { // 0x70ac9f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030b490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70b490: 8b0de883ab00 MOV ECX,dword ptr [0x00ab83e8]
    s.cx = m.r32((0x00ab83e8u));
  }
  { // 0x70b496: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x70b498: 7405 JZ 0x0070b49f
    if(integer::condition("JZ",flags)) goto L0070b49f;
  }
  L0070b49a: { // 0x70b49a: e931cacfff JMP 0x00407ed0
    const std::uint32_t target=0x00407ed0u;
    transfer(m,s,f,op,0u,target); return;
  }
  L0070b49f: { // 0x70b49f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0030b4a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70b4a0: 8b0de883ab00 MOV ECX,dword ptr [0x00ab83e8]
    s.cx = m.r32((0x00ab83e8u));
  }
  { // 0x70b4a6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x70b4a8: 7405 JZ 0x0070b4af
    if(integer::condition("JZ",flags)) goto L0070b4af;
  }
  L0070b4aa: { // 0x70b4aa: e971cacfff JMP 0x00407f20
    const std::uint32_t target=0x00407f20u;
    transfer(m,s,f,op,0u,target); return;
  }
  L0070b4af: { // 0x70b4af: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00311db0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x711db0: 8a810c050000 MOV AL,byte ptr [ECX + 0x50c]
    s.ax = with_al(s.ax, m.r8((s.cx+0x0000050cu)));
  }
  { // 0x711db6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x711db8: 740b JZ 0x00711dc5
    if(integer::condition("JZ",flags)) goto L00711dc5;
  }
  L00711dba: { // 0x711dba: 8b89f8010000 MOV ECX,dword ptr [ECX + 0x1f8]
    s.cx = m.r32((s.cx+0x000001f8u));
  }
  { // 0x711dc0: e9eb590500 JMP 0x007677b0
    const std::uint32_t target=0x007677b0u;
    transfer(m,s,f,op,0u,target); return;
  }
  L00711dc5: { // 0x711dc5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00311dd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x711dd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x711dd1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x711dd3: 8b8ef8010000 MOV ECX,dword ptr [ESI + 0x1f8]
    s.cx = m.r32((s.si+0x000001f8u));
  }
  { // 0x711dd9: e832630500 CALL 0x00768110
    const std::uint32_t call_target=0x00768110u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x711dde: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x711de0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x711de1: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x711de3: 7405 JZ 0x00711dea
    if(integer::condition("JZ",flags)) goto L00711dea;
  }
  L00711de5: { // 0x711de5: e996edf7ff JMP 0x00690b80
    const std::uint32_t target=0x00690b80u;
    transfer(m,s,f,op,1u,target); return;
  }
  L00711dea: { // 0x711dea: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0034a220(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x74a220: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x74a221: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x74a223: b9c2000000 MOV ECX,0xc2
    s.cx = 0x000000c2u;
  }
  { // 0x74a228: e8d302feff CALL 0x0072a500
    const std::uint32_t call_target=0x0072a500u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x74a22d: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x74a22f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x74a231: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x74a232: e929aae7ff JMP 0x005c4c60
    const std::uint32_t target=0x005c4c60u;
    transfer(m,s,f,op,1u,target); return;
  }
}
void f_0035d100(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75d100: a1fc03b100 MOV EAX,[0x00b103fc]
    s.ax = m.r32((0x00b103fcu));
  }
  { // 0x75d105: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75d107: 750f JNZ 0x0075d118
    if(integer::condition("JNZ",flags)) goto L0075d118;
  }
  L0075d109: { // 0x75d109: 8b0df403b100 MOV ECX,dword ptr [0x00b103f4]
    s.cx = m.r32((0x00b103f4u));
  }
  { // 0x75d10f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x75d111: 7405 JZ 0x0075d118
    if(integer::condition("JZ",flags)) goto L0075d118;
  }
  L0075d113: { // 0x75d113: e9281c0000 JMP 0x0075ed40
    const std::uint32_t target=0x0075ed40u;
    transfer(m,s,f,op,0u,target); return;
  }
  L0075d118: { // 0x75d118: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00363120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x763120: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x763124: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x763125: 83c0fe ADD EAX,-0x2
    s.ax = integer::add(s.ax,0xfffffffeu,32,flags);
  }
  { // 0x763128: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x76312a: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  { // 0x76312d: 773b JA 0x0076316a
    if(integer::condition("JA",flags)) goto L0076316a;
  }
  L0076312f: { // 0x76312f: ff248570317600 JMP dword ptr [EAX*0x4 + 0x763170]
    const std::uint32_t destination=m.r32(((s.ax * 0x00000004u)+0x00763170u));
    switch(destination) {
      case 0x763136u: goto L00763136;
      case 0x763147u: goto L00763147;
      case 0x763158u: goto L00763158;
      case 0x763160u: goto L00763160;
      default: throw std::invalid_argument("T38 immutable switch target differs");
    }
  }
  L00763136: { // 0x763136: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x76313a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x76313b: e830ae0000 CALL 0x0076df70
    const std::uint32_t call_target=0x0076df70u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x763140: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x763143: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x763145: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x763146: c3 RET
    finish(m,s,f,0u); return;
  }
  L00763147: { // 0x763147: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x76314b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x76314c: e8d7ad0000 CALL 0x0076df28
    const std::uint32_t call_target=0x0076df28u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x763151: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x763154: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x763156: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x763157: c3 RET
    finish(m,s,f,0u); return;
  }
  L00763158: { // 0x763158: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  { // 0x76315c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76315e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76315f: c3 RET
    finish(m,s,f,0u); return;
  }
  L00763160: { // 0x763160: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x763164: c700ffffffff MOV dword ptr [EAX],0xffffffff
    m.w32((s.ax), 0xffffffffu);
  }
  L0076316a: { // 0x76316a: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x76316c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76316d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0036f7a6(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76f7a6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x76f7a7: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x76f7a9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x76f7aa: 8365fc00 AND dword ptr [EBP + -0x4],0x0
    m.w32((s.bp-0x00000004u), integer::logical((m.r32((s.bp-0x00000004u)))&(0x00000000u),32,flags));
  }
  { // 0x76f7ae: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x76f7af: 8b5d0c MOV EBX,dword ptr [EBP + 0xc]
    s.bx = m.r32((s.bp+0x0000000cu));
  }
  { // 0x76f7b2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x76f7b3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x76f7b4: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x76f7b7: 83780800 CMP dword ptr [EAX + 0x8],0x0
    (void)integer::sub(m.r32((s.ax+0x00000008u)),0x00000000u,32,flags);
  }
  { // 0x76f7bb: 8b700c MOV ESI,dword ptr [EAX + 0xc]
    s.si = m.r32((s.ax+0x0000000cu));
  }
  { // 0x76f7be: 7635 JBE 0x0076f7f5
    if(integer::condition("JBE",flags)) goto L0076f7f5;
  }
  L0076f7c0: { // 0x76f7c0: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x76f7c2: 8b4d18 MOV ECX,dword ptr [EBP + 0x18]
    s.cx = m.r32((s.bp+0x00000018u));
  }
  { // 0x76f7c5: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x76f7c7: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x76f7c9: 7413 JZ 0x0076f7de
    if(integer::condition("JZ",flags)) goto L0076f7de;
  }
  L0076f7cb: { // 0x76f7cb: 83c108 ADD ECX,0x8
    s.cx = integer::add(s.cx,0x00000008u,32,flags);
  }
  { // 0x76f7ce: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  { // 0x76f7d1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x76f7d2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x76f7d3: e8781e0000 CALL 0x00771650
    const std::uint32_t call_target=0x00771650u;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x76f7d8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76f7d9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x76f7db: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x76f7dc: 7506 JNZ 0x0076f7e4
    if(integer::condition("JNZ",flags)) goto L0076f7e4;
  }
  L0076f7de: { // 0x76f7de: f6471401 TEST byte ptr [EDI + 0x14],0x1
    (void)integer::logical((m.r8((s.di+0x00000014u)))&(0x00000001u),8,flags);
  }
  { // 0x76f7e2: 7418 JZ 0x0076f7fc
    if(integer::condition("JZ",flags)) goto L0076f7fc;
  }
  L0076f7e4: { // 0x76f7e4: ff45fc INC dword ptr [EBP + -0x4]
    m.w32((s.bp-0x00000004u), integer::increment(m.r32((s.bp-0x00000004u)),32,flags));
  }
  { // 0x76f7e7: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  { // 0x76f7ea: 8b4dfc MOV ECX,dword ptr [EBP + -0x4]
    s.cx = m.r32((s.bp-0x00000004u));
  }
  { // 0x76f7ed: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x76f7f0: 3b4808 CMP ECX,dword ptr [EAX + 0x8]
    (void)integer::sub(s.cx,m.r32((s.ax+0x00000008u)),32,flags);
  }
  { // 0x76f7f3: 72cb JC 0x0076f7c0
    if(integer::condition("JC",flags)) goto L0076f7c0;
  }
  L0076f7f5: { // 0x76f7f5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076f7f7: { // 0x76f7f7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x76f7f8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x76f7f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x76f7fa: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x76f7fb: c3 RET
    finish(m,s,f,0u); return;
  }
  L0076f7fc: { // 0x76f7fc: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x76f7fe: ebf7 JMP 0x0076f7f7
    goto L0076f7f7;
  }
}
void f_003726bf(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7726bf: 6894c77900 PUSH 0x79c794
    f.push(m,0x0079c794u);
  }
  { // 0x7726c4: ff1530527800 CALL dword ptr [0x00785230]
    const std::uint32_t call_target=m.r32((0x00785230u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x7726ca: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7726cc: 7415 JZ 0x007726e3
    if(integer::condition("JZ",flags)) goto L007726e3;
  }
  L007726ce: { // 0x7726ce: 6878c77900 PUSH 0x79c778
    f.push(m,0x0079c778u);
  }
  { // 0x7726d3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7726d4: ff1540527800 CALL dword ptr [0x00785240]
    const std::uint32_t call_target=m.r32((0x00785240u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x7726da: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x7726dc: 7405 JZ 0x007726e3
    if(integer::condition("JZ",flags)) goto L007726e3;
  }
  L007726de: { // 0x7726de: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x7726e0: ffd0 CALL EAX
    const std::uint32_t call_target=s.ax;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x7726e2: c3 RET
    finish(m,s,f,0u); return;
  }
  L007726e3: { // 0x7726e3: e999ffffff JMP 0x00772681
    const std::uint32_t target=0x00772681u;
    transfer(m,s,f,op,3u,target); return;
  }
}
void f_003771ef(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7771ef: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x7771f3: 83256805b10000 AND dword ptr [0x00b10568],0x0
    m.w32((0x00b10568u), integer::logical((m.r32((0x00b10568u)))&(0x00000000u),32,flags));
  }
  { // 0x7771fa: 83f8fe CMP EAX,-0x2
    (void)integer::sub(s.ax,0xfffffffeu,32,flags);
  }
  { // 0x7771fd: 7510 JNZ 0x0077720f
    if(integer::condition("JNZ",flags)) goto L0077720f;
  }
  L007771ff: { // 0x7771ff: c7056805b10001000000 MOV dword ptr [0x00b10568],0x1
    m.w32((0x00b10568u), 0x00000001u);
  }
  { // 0x777209: ff25d4527800 JMP dword ptr [0x007852d4]
    const std::uint32_t target=m.r32((0x007852d4u));
    transfer(m,s,f,op,0u,target); return;
  }
  L0077720f: { // 0x77720f: 83f8fd CMP EAX,-0x3
    (void)integer::sub(s.ax,0xfffffffdu,32,flags);
  }
  { // 0x777212: 7510 JNZ 0x00777224
    if(integer::condition("JNZ",flags)) goto L00777224;
  }
  L00777214: { // 0x777214: c7056805b10001000000 MOV dword ptr [0x00b10568],0x1
    m.w32((0x00b10568u), 0x00000001u);
  }
  { // 0x77721e: ff25d0527800 JMP dword ptr [0x007852d0]
    const std::uint32_t target=m.r32((0x007852d0u));
    transfer(m,s,f,op,1u,target); return;
  }
  L00777224: { // 0x777224: 83f8fc CMP EAX,-0x4
    (void)integer::sub(s.ax,0xfffffffcu,32,flags);
  }
  { // 0x777227: 750f JNZ 0x00777238
    if(integer::condition("JNZ",flags)) goto L00777238;
  }
  L00777229: { // 0x777229: a14005b100 MOV EAX,[0x00b10540]
    s.ax = m.r32((0x00b10540u));
  }
  { // 0x77722e: c7056805b10001000000 MOV dword ptr [0x00b10568],0x1
    m.w32((0x00b10568u), 0x00000001u);
  }
  L00777238: { // 0x777238: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003781de(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7781de: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7781df: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x7781e0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7781e1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7781e2: 8b357c04b100 MOV ESI,dword ptr [0x00b1047c]
    s.si = m.r32((0x00b1047cu));
  }
  { // 0x7781e8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7781e9: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x7781eb: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x7781ed: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x7781ef: 744e JZ 0x0077823f
    if(integer::condition("JZ",flags)) goto L0077823f;
  }
  L007781f1: { // 0x7781f1: 8b1d3c527800 MOV EBX,dword ptr [0x0078523c]
    s.bx = m.r32((0x0078523cu));
  }
  L007781f7: { // 0x7781f7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7781f8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7781f9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7781fa: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7781fb: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x7781fd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7781fe: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7781ff: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x778201: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x778203: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  { // 0x778205: 3bef CMP EBP,EDI
    (void)integer::sub(s.bp,s.di,32,flags);
  }
  { // 0x778207: 743e JZ 0x00778247
    if(integer::condition("JZ",flags)) goto L00778247;
  }
  L00778209: { // 0x778209: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77820a: e8615dffff CALL 0x0076df70
    const std::uint32_t call_target=0x0076df70u;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x77820f: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x778211: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x778212: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  { // 0x778216: 742f JZ 0x00778247
    if(integer::condition("JZ",flags)) goto L00778247;
  }
  L00778218: { // 0x778218: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x778219: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77821a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77821b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77821c: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x77821e: ff36 PUSH dword ptr [ESI]
    f.push(m,m.r32((s.si)));
  }
  { // 0x778220: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x778221: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x778223: ffd3 CALL EBX
    const std::uint32_t call_target=s.bx;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x778225: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x778227: 741e JZ 0x00778247
    if(integer::condition("JZ",flags)) goto L00778247;
  }
  L00778229: { // 0x778229: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77822a: ff742414 PUSH dword ptr [ESP + 0x14]
    f.push(m,m.r32((f.sp+0x00000014u)));
  }
  { // 0x77822e: e82d6e0000 CALL 0x0077f060
    const std::uint32_t call_target=0x0077f060u;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x778233: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x778236: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x778239: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77823a: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x77823c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77823d: 75b8 JNZ 0x007781f7
    if(integer::condition("JNZ",flags)) goto L007781f7;
  }
  L0077823f: { // 0x77823f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00778241: { // 0x778241: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x778242: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x778243: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x778244: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x778245: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x778246: c3 RET
    finish(m,s,f,0u); return;
  }
  L00778247: { // 0x778247: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x77824a: ebf5 JMP 0x00778241
    goto L00778241;
  }
}
void f_0037f1e7(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77f1e7: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77f1e8: 8b357404b100 MOV ESI,dword ptr [0x00b10474]
    s.si = m.r32((0x00b10474u));
  }
  { // 0x77f1ee: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77f1ef: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x77f1f1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77f1f3: 742d JZ 0x0077f222
    if(integer::condition("JZ",flags)) goto L0077f222;
  }
  L0077f1f5: { // 0x77f1f5: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0077f1f9: { // 0x77f1f9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77f1fa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77f1fb: ff742414 PUSH dword ptr [ESP + 0x14]
    f.push(m,m.r32((f.sp+0x00000014u)));
  }
  { // 0x77f1ff: e89b8fffff CALL 0x0077819f
    const std::uint32_t call_target=0x0077819fu;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77f204: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77f207: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77f209: 750d JNZ 0x0077f218
    if(integer::condition("JNZ",flags)) goto L0077f218;
  }
  L0077f20b: { // 0x77f20b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x77f20d: 8a0438 MOV AL,byte ptr [EAX + EDI*0x1]
    s.ax = with_al(s.ax, m.r8((s.ax+(s.di * 0x00000001u))));
  }
  { // 0x77f210: 3c3d CMP AL,0x3d
    (void)integer::sub((s.ax & 0xffu),0x0000003du,8,flags);
  }
  { // 0x77f212: 741e JZ 0x0077f232
    if(integer::condition("JZ",flags)) goto L0077f232;
  }
  L0077f214: { // 0x77f214: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x77f216: 741a JZ 0x0077f232
    if(integer::condition("JZ",flags)) goto L0077f232;
  }
  L0077f218: { // 0x77f218: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  { // 0x77f21b: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  { // 0x77f21e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x77f220: 75d7 JNZ 0x0077f1f9
    if(integer::condition("JNZ",flags)) goto L0077f1f9;
  }
  L0077f222: { // 0x77f222: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x77f224: 2b057404b100 SUB EAX,dword ptr [0x00b10474]
    s.ax = integer::sub(s.ax,m.r32((0x00b10474u)),32,flags);
  }
  { // 0x77f22a: c1f802 SAR EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x77f22d: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0077f22f: { // 0x77f22f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77f230: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77f231: c3 RET
    finish(m,s,f,0u); return;
  }
  L0077f232: { // 0x77f232: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x77f234: 2b057404b100 SUB EAX,dword ptr [0x00b10474]
    s.ax = integer::sub(s.ax,m.r32((0x00b10474u)),32,flags);
  }
  { // 0x77f23a: c1f802 SAR EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x77f23d: ebf0 JMP 0x0077f22f
    goto L0077f22f;
  }
}
} // namespace
const std::array<Entry,43>& entries_b() {
  static const std::array<Entry,43> entries{{
    {0x1bd7d0u,f_001bd7d0},
    {0x1be010u,f_001be010},
    {0x1be760u,f_001be760},
    {0x1c1550u,f_001c1550},
    {0x1c3d10u,f_001c3d10},
    {0x1c70f0u,f_001c70f0},
    {0x1c71d0u,f_001c71d0},
    {0x1c8f70u,f_001c8f70},
    {0x1cae40u,f_001cae40},
    {0x201870u,f_00201870},
    {0x2066f0u,f_002066f0},
    {0x20f9d0u,f_0020f9d0},
    {0x211eb0u,f_00211eb0},
    {0x216a40u,f_00216a40},
    {0x216a70u,f_00216a70},
    {0x219c70u,f_00219c70},
    {0x230ab0u,f_00230ab0},
    {0x2a0380u,f_002a0380},
    {0x2a8440u,f_002a8440},
    {0x2cd950u,f_002cd950},
    {0x2ce490u,f_002ce490},
    {0x2ce4b0u,f_002ce4b0},
    {0x2dbcf0u,f_002dbcf0},
    {0x2dbfb0u,f_002dbfb0},
    {0x2e7a20u,f_002e7a20},
    {0x2eb300u,f_002eb300},
    {0x2eb330u,f_002eb330},
    {0x2eb350u,f_002eb350},
    {0x3095c0u,f_003095c0},
    {0x30a9a0u,f_0030a9a0},
    {0x30ac90u,f_0030ac90},
    {0x30b490u,f_0030b490},
    {0x30b4a0u,f_0030b4a0},
    {0x311db0u,f_00311db0},
    {0x311dd0u,f_00311dd0},
    {0x34a220u,f_0034a220},
    {0x35d100u,f_0035d100},
    {0x363120u,f_00363120},
    {0x36f7a6u,f_0036f7a6},
    {0x3726bfu,f_003726bf},
    {0x3771efu,f_003771ef},
    {0x3781deu,f_003781de},
    {0x37f1e7u,f_0037f1e7},
  }}; return entries;
}
} // namespace ra2::recovered::transfers_b38
