#include "recovered/recovery_b796_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b796 {
namespace {
void f_000f47b0(Memory&,State&,Frame&,const Operations&);
void f_0004d3b0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000f47b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f47b0: { // 0x4f47b0: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004f47b5: { // 0x4f47b5: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f47b7: { // 0x4f47b7: 751d JNZ 0x4f47d6
    if(integer::condition("JNZ",flags)) goto L004f47d6;
  }
  L004f47b9: { // 0x4f47b9: 8a8134010000 MOV AL, byte ptr [ECX + 0x134]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000134u)));
  }
  L004f47bf: { // 0x4f47bf: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f47c1: { // 0x4f47c1: 750d JNZ 0x4f47d0
    if(integer::condition("JNZ",flags)) goto L004f47d0;
  }
  L004f47c3: { // 0x4f47c3: 8a8135010000 MOV AL, byte ptr [ECX + 0x135]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000135u)));
  }
  L004f47c9: { // 0x4f47c9: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f47cb: { // 0x4f47cb: 7503 JNZ 0x4f47d0
    if(integer::condition("JNZ",flags)) goto L004f47d0;
  }
  L004f47cd: { // 0x4f47cd: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f47cf: { // 0x4f47cf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004f47d0: { // 0x4f47d0: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004f47d5: { // 0x4f47d5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004f47d6: { // 0x4f47d6: 8b15e4e0a100 MOV EDX, dword ptr [0xa1e0e4]
    s.dx = m.r32((0x00a1e0e4u));
  }
  L004f47dc: { // 0x4f47dc: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f47de: { // 0x4f47de: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004f47e0: { // 0x4f47e0: 0f94c0 SETE AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004f47e3: { // 0x4f47e3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0004d3b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044d3b0: { // 0x44d3b0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044d3b1: { // 0x44d3b1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044d3b2: { // 0x44d3b2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d3b3: { // 0x44d3b3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044d3b4: { // 0x44d3b4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044d3b5: { // 0x44d3b5: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L0044d3b7: { // 0x44d3b7: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0044d3b9: { // 0x44d3b9: 8bafb4010000 MOV EBP, dword ptr [EDI + 0x1b4]
    s.bp = m.r32((s.di+0x000001b4u));
  }
  L0044d3bf: { // 0x44d3bf: c687ba05000000 MOV byte ptr [EDI + 0x5ba], 0
    m.w8((s.di+0x000005bau), 0u);
  }
  L0044d3c6: { // 0x44d3c6: 8b4578 MOV EAX, dword ptr [EBP + 0x78]
    s.ax = m.r32((s.bp+0x00000078u));
  }
  L0044d3c9: { // 0x44d3c9: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044d3cb: { // 0x44d3cb: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0044d3cf: { // 0x44d3cf: 7e3d JLE 0x44d40e
    if(integer::condition("JLE",flags)) goto L0044d40e;
  }
  L0044d3d1: { // 0x44d3d1: 8b4d6c MOV ECX, dword ptr [EBP + 0x6c]
    s.cx = m.r32((s.bp+0x0000006cu));
  }
  L0044d3d4: { // 0x44d3d4: 8b3499 MOV ESI, dword ptr [ECX + EBX*4]
    s.si = m.r32((s.cx+(s.bx * 4u)));
  }
  L0044d3d7: { // 0x44d3d7: 8a4e7d MOV CL, byte ptr [ESI + 0x7d]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000007du)));
  }
  L0044d3da: { // 0x44d3da: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d3dc: { // 0x44d3dc: 742b JZ 0x44d409
    if(integer::condition("JZ",flags)) goto L0044d409;
  }
  L0044d3de: { // 0x44d3de: 8a4e76 MOV CL, byte ptr [ESI + 0x76]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000076u)));
  }
  L0044d3e1: { // 0x44d3e1: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d3e3: { // 0x44d3e3: 7524 JNZ 0x44d409
    if(integer::condition("JNZ",flags)) goto L0044d409;
  }
  L0044d3e5: { // 0x44d3e5: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L0044d3eb: { // 0x44d3eb: 8a8258130000 MOV AL, byte ptr [EDX + 0x1358]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00001358u)));
  }
  L0044d3f1: { // 0x44d3f1: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d3f3: { // 0x44d3f3: 7409 JZ 0x44d3fe
    if(integer::condition("JZ",flags)) goto L0044d3fe;
  }
  L0044d3f5: { // 0x44d3f5: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044d3f7: { // 0x44d3f7: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044d3f9: { // 0x44d3f9: e8920e0000 CALL 0x44e290
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044e290u,4510718u); flags=s.arithmetic_flags;
  }
  L0044d3fe: { // 0x44d3fe: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044d400: { // 0x44d400: e8cb210000 CALL 0x44f5d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044f5d0u,4510725u); flags=s.arithmetic_flags;
  }
  L0044d405: { // 0x44d405: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0044d409: { // 0x44d409: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0044d40a: { // 0x44d40a: 3bd8 CMP EBX, EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0044d40c: { // 0x44d40c: 7cc3 JL 0x44d3d1
    if(integer::condition("JL",flags)) goto L0044d3d1;
  }
  L0044d40e: { // 0x44d40e: 8b8fe8040000 MOV ECX, dword ptr [EDI + 0x4e8]
    s.cx = m.r32((s.di+0x000004e8u));
  }
  L0044d414: { // 0x44d414: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044d416: { // 0x44d416: 7407 JZ 0x44d41f
    if(integer::condition("JZ",flags)) goto L0044d41f;
  }
  L0044d418: { // 0x44d418: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044d41a: { // 0x44d41a: e821830e00 CALL 0x535740
    s.arithmetic_flags=flags; invoke(m,s,f,0x00535740u,4510751u); flags=s.arithmetic_flags;
  }
  L0044d41f: { // 0x44d41f: 8b8718040000 MOV EAX, dword ptr [EDI + 0x418]
    s.ax = m.r32((s.di+0x00000418u));
  }
  L0044d425: { // 0x44d425: 8a8861130000 MOV CL, byte ptr [EAX + 0x1361]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001361u)));
  }
  L0044d42b: { // 0x44d42b: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d42d: { // 0x44d42d: 7421 JZ 0x44d450
    if(integer::condition("JZ",flags)) goto L0044d450;
  }
  L0044d42f: { // 0x44d42f: 8a8fbc050000 MOV CL, byte ptr [EDI + 0x5bc]
    s.cx = with_al(s.cx, m.r8((s.di+0x000005bcu)));
  }
  L0044d435: { // 0x44d435: c687bb050000ff MOV byte ptr [EDI + 0x5bb], 0xff
    m.w8((s.di+0x000005bbu), 0x000000ffu);
  }
  L0044d43c: { // 0x44d43c: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d43e: { // 0x44d43e: 750c JNZ 0x44d44c
    if(integer::condition("JNZ",flags)) goto L0044d44c;
  }
  L0044d440: { // 0x44d440: 8a888b130000 MOV CL, byte ptr [EAX + 0x138b]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000138bu)));
  }
  L0044d446: { // 0x44d446: 888fbc050000 MOV byte ptr [EDI + 0x5bc], CL
    m.w8((s.di+0x000005bcu), (s.cx & 0xffu));
  }
  L0044d44c: { // 0x44d44c: c6477501 MOV byte ptr [EDI + 0x75], 1
    m.w8((s.di+0x00000075u), 1u);
  }
  L0044d450: { // 0x44d450: 8a88dd0a0000 MOV CL, byte ptr [EAX + 0xadd]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000addu)));
  }
  L0044d456: { // 0x44d456: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d458: { // 0x44d458: 7414 JZ 0x44d46e
    if(integer::condition("JZ",flags)) goto L0044d46e;
  }
  L0044d45a: { // 0x44d45a: 8a87fd010000 MOV AL, byte ptr [EDI + 0x1fd]
    s.ax = with_al(s.ax, m.r8((s.di+0x000001fdu)));
  }
  L0044d460: { // 0x44d460: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d462: { // 0x44d462: 740a JZ 0x44d46e
    if(integer::condition("JZ",flags)) goto L0044d46e;
  }
  L0044d464: { // 0x44d464: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0044d466: { // 0x44d466: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0044d468: { // 0x44d468: ff92b0030000 CALL dword ptr [EDX + 0x3b0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000003b0u)),4510830u); flags=s.arithmetic_flags;
  }
  L0044d46e: { // 0x44d46e: 8b8718040000 MOV EAX, dword ptr [EDI + 0x418]
    s.ax = m.r32((s.di+0x00000418u));
  }
  L0044d474: { // 0x44d474: 8a8858130000 MOV CL, byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  L0044d47a: { // 0x44d47a: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d47c: { // 0x44d47c: 7409 JZ 0x44d487
    if(integer::condition("JZ",flags)) goto L0044d487;
  }
  L0044d47e: { // 0x44d47e: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044d480: { // 0x44d480: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0044d482: { // 0x44d482: e8090e0000 CALL 0x44e290
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044e290u,4510855u); flags=s.arithmetic_flags;
  }
  L0044d487: { // 0x44d487: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0044d489: { // 0x44d489: 8d9f54040000 LEA EBX, [EDI + 0x454]
    s.bx = (s.di+0x00000454u);
  }
  L0044d48f: { // 0x44d48f: 8b8f18040000 MOV ECX, dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L0044d495: { // 0x44d495: 8a840e140d0000 MOV AL, byte ptr [ESI + ECX + 0xd14]
    s.ax = with_al(s.ax, m.r8((s.si+s.cx+0x00000d14u)));
  }
  L0044d49c: { // 0x44d49c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d49e: { // 0x44d49e: 740b JZ 0x44d4ab
    if(integer::condition("JZ",flags)) goto L0044d4ab;
  }
  L0044d4a0: { // 0x44d4a0: 8b0b MOV ECX, dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L0044d4a2: { // 0x44d4a2: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044d4a4: { // 0x44d4a4: 7405 JZ 0x44d4ab
    if(integer::condition("JZ",flags)) goto L0044d4ab;
  }
  L0044d4a6: { // 0x44d4a6: e86557fdff CALL 0x422c10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00422c10u,4510891u); flags=s.arithmetic_flags;
  }
  L0044d4ab: { // 0x44d4ab: 83c644 ADD ESI, 0x44
    s.si = integer::add(s.si,0x00000044u,32,flags);
  }
  L0044d4ae: { // 0x44d4ae: 83c304 ADD EBX, 4
    s.bx = integer::add(s.bx,4u,32,flags);
  }
  L0044d4b1: { // 0x44d4b1: 81fec8040000 CMP ESI, 0x4c8
    (void)integer::sub(s.si,0x000004c8u,32,flags);
  }
  L0044d4b7: { // 0x44d4b7: 7cd6 JL 0x44d48f
    if(integer::condition("JL",flags)) goto L0044d48f;
  }
  L0044d4b9: { // 0x44d4b9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d4ba: { // 0x44d4ba: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d4bb: { // 0x44d4bb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044d4bc: { // 0x44d4bc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044d4bd: { // 0x44d4bd: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0044d4be: { // 0x44d4be: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5195696u:f_000f47b0(m,s,child,{});break;
case 4510640u:f_0004d3b0(m,s,child,{});break;
default:throw std::domain_error("recovery796 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0044d220(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044d220: { // 0x44d220: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044d221: { // 0x44d221: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0044d223: { // 0x44d223: 8a8630050000 MOV AL,byte ptr [ESI + 0x530]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000530u)));
  }
  L0044d229: { // 0x44d229: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d22b: { // 0x44d22b: 0f84b7000000 JZ 0x0044d2e8
    if(integer::condition("JZ",flags)) goto L0044d2e8;
  }
  L0044d231: { // 0x44d231: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0044d237: { // 0x44d237: 8b886c0c0000 MOV ECX,dword ptr [EAX + 0xc6c]
    s.cx = m.r32((s.ax+0x00000c6cu));
  }
  L0044d23d: { // 0x44d23d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044d23f: { // 0x44d23f: 7f0e JG 0x0044d24f
    if(integer::condition("JG",flags)) goto L0044d24f;
  }
  L0044d241: { // 0x44d241: 8a8817120000 MOV CL,byte ptr [EAX + 0x1217]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001217u)));
  }
  L0044d247: { // 0x44d247: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d249: { // 0x44d249: 0f8499000000 JZ 0x0044d2e8
    if(integer::condition("JZ",flags)) goto L0044d2e8;
  }
  L0044d24f: { // 0x44d24f: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0044d255: { // 0x44d255: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0044d257: { // 0x44d257: c6863005000000 MOV byte ptr [ESI + 0x530],0x0
    m.w8((s.si+0x00000530u), 0x00000000u);
  }
  L0044d25e: { // 0x44d25e: 884675 MOV byte ptr [ESI + 0x75],AL
    m.w8((s.si+0x00000075u), (s.ax & 0xffu));
  }
  L0044d261: { // 0x44d261: 888168560000 MOV byte ptr [ECX + 0x5668],AL
    m.w8((s.cx+0x00005668u), (s.ax & 0xffu));
  }
  L0044d267: { // 0x44d267: 8b96b4010000 MOV EDX,dword ptr [ESI + 0x1b4]
    s.dx = m.r32((s.si+0x000001b4u));
  }
  L0044d26d: { // 0x44d26d: 888269560000 MOV byte ptr [EDX + 0x5669],AL
    m.w8((s.dx+0x00005669u), (s.ax & 0xffu));
  }
  L0044d273: { // 0x44d273: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0044d279: { // 0x44d279: 888144010000 MOV byte ptr [ECX + 0x144],AL
    m.w8((s.cx+0x00000144u), (s.ax & 0xffu));
  }
  L0044d27f: { // 0x44d27f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044d281: { // 0x44d281: e82a010000 CALL 0x0044d3b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044d3b0u,4510342u); flags=s.arithmetic_flags;
  }
  L0044d286: { // 0x44d286: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0044d28c: { // 0x44d28c: e81f750a00 CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,4510353u); flags=s.arithmetic_flags;
  }
  L0044d291: { // 0x44d291: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d293: { // 0x44d293: 740f JZ 0x0044d2a4
    if(integer::condition("JZ",flags)) goto L0044d2a4;
  }
  L0044d295: { // 0x44d295: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0044d297: { // 0x44d297: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L0044d29a: { // 0x44d29a: b92caa7b00 MOV ECX,0x7baa2c
    s.cx = 0x007baa2cu;
  }
  L0044d29f: { // 0x44d29f: e85cd42b00 CALL 0x0070a700
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070a700u,4510372u); flags=s.arithmetic_flags;
  }
  L0044d2a4: { // 0x44d2a4: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0044d2aa: { // 0x44d2aa: 8b88440c0000 MOV ECX,dword ptr [EAX + 0xc44]
    s.cx = m.r32((s.ax+0x00000c44u));
  }
  L0044d2b0: { // 0x44d2b0: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044d2b2: { // 0x44d2b2: 7415 JZ 0x0044d2c9
    if(integer::condition("JZ",flags)) goto L0044d2c9;
  }
  L0044d2b4: { // 0x44d2b4: 8a90da0a0000 MOV DL,byte ptr [EAX + 0xada]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000adau)));
  }
  L0044d2ba: { // 0x44d2ba: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0044d2bc: { // 0x44d2bc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0044d2bd: { // 0x44d2bd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044d2be: { // 0x44d2be: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0044d2c4: { // 0x44d2c4: e8a7530a00 CALL 0x004f2670
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f2670u,4510409u); flags=s.arithmetic_flags;
  }
  L0044d2c9: { // 0x44d2c9: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L0044d2cf: { // 0x44d2cf: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0044d2d5: { // 0x44d2d5: 3b81bc070000 CMP EAX,dword ptr [ECX + 0x7bc]
    (void)integer::sub(s.ax,m.r32((s.cx+0x000007bcu)),32,flags);
  }
  L0044d2db: { // 0x44d2db: 750b JNZ 0x0044d2e8
    if(integer::condition("JNZ",flags)) goto L0044d2e8;
  }
  L0044d2dd: { // 0x44d2dd: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0044d2e3: { // 0x44d2e3: e8a80d0a00 CALL 0x004ee090
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ee090u,4510440u); flags=s.arithmetic_flags;
  }
  L0044d2e8: { // 0x44d2e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d2e9: { // 0x44d2e9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0044d3b0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044d3b0: { // 0x44d3b0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044d3b1: { // 0x44d3b1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044d3b2: { // 0x44d3b2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d3b3: { // 0x44d3b3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044d3b4: { // 0x44d3b4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044d3b5: { // 0x44d3b5: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L0044d3b7: { // 0x44d3b7: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0044d3b9: { // 0x44d3b9: 8bafb4010000 MOV EBP, dword ptr [EDI + 0x1b4]
    s.bp = m.r32((s.di+0x000001b4u));
  }
  L0044d3bf: { // 0x44d3bf: c687ba05000000 MOV byte ptr [EDI + 0x5ba], 0
    m.w8((s.di+0x000005bau), 0u);
  }
  L0044d3c6: { // 0x44d3c6: 8b4578 MOV EAX, dword ptr [EBP + 0x78]
    s.ax = m.r32((s.bp+0x00000078u));
  }
  L0044d3c9: { // 0x44d3c9: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044d3cb: { // 0x44d3cb: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0044d3cf: { // 0x44d3cf: 7e3d JLE 0x44d40e
    if(integer::condition("JLE",flags)) goto L0044d40e;
  }
  L0044d3d1: { // 0x44d3d1: 8b4d6c MOV ECX, dword ptr [EBP + 0x6c]
    s.cx = m.r32((s.bp+0x0000006cu));
  }
  L0044d3d4: { // 0x44d3d4: 8b3499 MOV ESI, dword ptr [ECX + EBX*4]
    s.si = m.r32((s.cx+(s.bx * 4u)));
  }
  L0044d3d7: { // 0x44d3d7: 8a4e7d MOV CL, byte ptr [ESI + 0x7d]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000007du)));
  }
  L0044d3da: { // 0x44d3da: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d3dc: { // 0x44d3dc: 742b JZ 0x44d409
    if(integer::condition("JZ",flags)) goto L0044d409;
  }
  L0044d3de: { // 0x44d3de: 8a4e76 MOV CL, byte ptr [ESI + 0x76]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000076u)));
  }
  L0044d3e1: { // 0x44d3e1: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d3e3: { // 0x44d3e3: 7524 JNZ 0x44d409
    if(integer::condition("JNZ",flags)) goto L0044d409;
  }
  L0044d3e5: { // 0x44d3e5: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L0044d3eb: { // 0x44d3eb: 8a8258130000 MOV AL, byte ptr [EDX + 0x1358]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00001358u)));
  }
  L0044d3f1: { // 0x44d3f1: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d3f3: { // 0x44d3f3: 7409 JZ 0x44d3fe
    if(integer::condition("JZ",flags)) goto L0044d3fe;
  }
  L0044d3f5: { // 0x44d3f5: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044d3f7: { // 0x44d3f7: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044d3f9: { // 0x44d3f9: e8920e0000 CALL 0x44e290
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044e290u,4510718u); flags=s.arithmetic_flags;
  }
  L0044d3fe: { // 0x44d3fe: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0044d400: { // 0x44d400: e8cb210000 CALL 0x44f5d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044f5d0u,4510725u); flags=s.arithmetic_flags;
  }
  L0044d405: { // 0x44d405: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0044d409: { // 0x44d409: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0044d40a: { // 0x44d40a: 3bd8 CMP EBX, EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0044d40c: { // 0x44d40c: 7cc3 JL 0x44d3d1
    if(integer::condition("JL",flags)) goto L0044d3d1;
  }
  L0044d40e: { // 0x44d40e: 8b8fe8040000 MOV ECX, dword ptr [EDI + 0x4e8]
    s.cx = m.r32((s.di+0x000004e8u));
  }
  L0044d414: { // 0x44d414: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044d416: { // 0x44d416: 7407 JZ 0x44d41f
    if(integer::condition("JZ",flags)) goto L0044d41f;
  }
  L0044d418: { // 0x44d418: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044d41a: { // 0x44d41a: e821830e00 CALL 0x535740
    s.arithmetic_flags=flags; invoke(m,s,f,0x00535740u,4510751u); flags=s.arithmetic_flags;
  }
  L0044d41f: { // 0x44d41f: 8b8718040000 MOV EAX, dword ptr [EDI + 0x418]
    s.ax = m.r32((s.di+0x00000418u));
  }
  L0044d425: { // 0x44d425: 8a8861130000 MOV CL, byte ptr [EAX + 0x1361]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001361u)));
  }
  L0044d42b: { // 0x44d42b: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d42d: { // 0x44d42d: 7421 JZ 0x44d450
    if(integer::condition("JZ",flags)) goto L0044d450;
  }
  L0044d42f: { // 0x44d42f: 8a8fbc050000 MOV CL, byte ptr [EDI + 0x5bc]
    s.cx = with_al(s.cx, m.r8((s.di+0x000005bcu)));
  }
  L0044d435: { // 0x44d435: c687bb050000ff MOV byte ptr [EDI + 0x5bb], 0xff
    m.w8((s.di+0x000005bbu), 0x000000ffu);
  }
  L0044d43c: { // 0x44d43c: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d43e: { // 0x44d43e: 750c JNZ 0x44d44c
    if(integer::condition("JNZ",flags)) goto L0044d44c;
  }
  L0044d440: { // 0x44d440: 8a888b130000 MOV CL, byte ptr [EAX + 0x138b]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000138bu)));
  }
  L0044d446: { // 0x44d446: 888fbc050000 MOV byte ptr [EDI + 0x5bc], CL
    m.w8((s.di+0x000005bcu), (s.cx & 0xffu));
  }
  L0044d44c: { // 0x44d44c: c6477501 MOV byte ptr [EDI + 0x75], 1
    m.w8((s.di+0x00000075u), 1u);
  }
  L0044d450: { // 0x44d450: 8a88dd0a0000 MOV CL, byte ptr [EAX + 0xadd]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000addu)));
  }
  L0044d456: { // 0x44d456: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d458: { // 0x44d458: 7414 JZ 0x44d46e
    if(integer::condition("JZ",flags)) goto L0044d46e;
  }
  L0044d45a: { // 0x44d45a: 8a87fd010000 MOV AL, byte ptr [EDI + 0x1fd]
    s.ax = with_al(s.ax, m.r8((s.di+0x000001fdu)));
  }
  L0044d460: { // 0x44d460: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d462: { // 0x44d462: 740a JZ 0x44d46e
    if(integer::condition("JZ",flags)) goto L0044d46e;
  }
  L0044d464: { // 0x44d464: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0044d466: { // 0x44d466: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0044d468: { // 0x44d468: ff92b0030000 CALL dword ptr [EDX + 0x3b0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000003b0u)),4510830u); flags=s.arithmetic_flags;
  }
  L0044d46e: { // 0x44d46e: 8b8718040000 MOV EAX, dword ptr [EDI + 0x418]
    s.ax = m.r32((s.di+0x00000418u));
  }
  L0044d474: { // 0x44d474: 8a8858130000 MOV CL, byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  L0044d47a: { // 0x44d47a: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d47c: { // 0x44d47c: 7409 JZ 0x44d487
    if(integer::condition("JZ",flags)) goto L0044d487;
  }
  L0044d47e: { // 0x44d47e: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0044d480: { // 0x44d480: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0044d482: { // 0x44d482: e8090e0000 CALL 0x44e290
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044e290u,4510855u); flags=s.arithmetic_flags;
  }
  L0044d487: { // 0x44d487: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0044d489: { // 0x44d489: 8d9f54040000 LEA EBX, [EDI + 0x454]
    s.bx = (s.di+0x00000454u);
  }
  L0044d48f: { // 0x44d48f: 8b8f18040000 MOV ECX, dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L0044d495: { // 0x44d495: 8a840e140d0000 MOV AL, byte ptr [ESI + ECX + 0xd14]
    s.ax = with_al(s.ax, m.r8((s.si+s.cx+0x00000d14u)));
  }
  L0044d49c: { // 0x44d49c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d49e: { // 0x44d49e: 740b JZ 0x44d4ab
    if(integer::condition("JZ",flags)) goto L0044d4ab;
  }
  L0044d4a0: { // 0x44d4a0: 8b0b MOV ECX, dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L0044d4a2: { // 0x44d4a2: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044d4a4: { // 0x44d4a4: 7405 JZ 0x44d4ab
    if(integer::condition("JZ",flags)) goto L0044d4ab;
  }
  L0044d4a6: { // 0x44d4a6: e86557fdff CALL 0x422c10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00422c10u,4510891u); flags=s.arithmetic_flags;
  }
  L0044d4ab: { // 0x44d4ab: 83c644 ADD ESI, 0x44
    s.si = integer::add(s.si,0x00000044u,32,flags);
  }
  L0044d4ae: { // 0x44d4ae: 83c304 ADD EBX, 4
    s.bx = integer::add(s.bx,4u,32,flags);
  }
  L0044d4b1: { // 0x44d4b1: 81fec8040000 CMP ESI, 0x4c8
    (void)integer::sub(s.si,0x000004c8u,32,flags);
  }
  L0044d4b7: { // 0x44d4b7: 7cd6 JL 0x44d48f
    if(integer::condition("JL",flags)) goto L0044d48f;
  }
  L0044d4b9: { // 0x44d4b9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d4ba: { // 0x44d4ba: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d4bb: { // 0x44d4bb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044d4bc: { // 0x44d4bc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044d4bd: { // 0x44d4bd: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0044d4be: { // 0x44d4be: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
