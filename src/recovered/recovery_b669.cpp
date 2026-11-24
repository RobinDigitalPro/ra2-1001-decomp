#include "recovered/recovery_b669_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b669 {
namespace {
void f_00068630(Memory&,State&,Frame&,const Operations&);
void f_002c93c0(Memory&,State&,Frame&,const Operations&);
void f_00052f60(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_002c86c0(Memory&,State&,Frame&,const Operations&);

void f_00068630(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00468630: { // 0x468630: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00468633: { // 0x468633: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002c93c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c93c0: { // 0x6c93c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c93c1: { // 0x6c93c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006c93c3: { // 0x6c93c3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c93c4: { // 0x6c93c4: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c93c6: { // 0x6c93c6: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7115724u); flags=s.arithmetic_flags;
  }
  L006c93cc: { // 0x6c93cc: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006c93ce: { // 0x6c93ce: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006c93d0: { // 0x6c93d0: 7438 JZ 0x006c940a
    if(integer::condition("JZ",flags)) goto L006c940a;
  }
  L006c93d2: { // 0x6c93d2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c93d4: { // 0x6c93d4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c93d6: { // 0x6c93d6: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7115737u); flags=s.arithmetic_flags;
  }
  L006c93d9: { // 0x6c93d9: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L006c93dc: { // 0x6c93dc: 7523 JNZ 0x006c9401
    if(integer::condition("JNZ",flags)) goto L006c9401;
  }
  L006c93de: { // 0x6c93de: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c93e0: { // 0x6c93e0: e87b9bd8ff CALL 0x00452f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00452f60u,7115749u); flags=s.arithmetic_flags;
  }
  L006c93e5: { // 0x6c93e5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c93e7: { // 0x6c93e7: 7e18 JLE 0x006c9401
    if(integer::condition("JLE",flags)) goto L006c9401;
  }
  L006c93e9: { // 0x6c93e9: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006c93ee: { // 0x6c93ee: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c93f0: { // 0x6c93f0: 8bb8e80b0000 MOV EDI,dword ptr [EAX + 0xbe8]
    s.di = m.r32((s.ax+0x00000be8u));
  }
  L006c93f6: { // 0x6c93f6: e8659bd8ff CALL 0x00452f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00452f60u,7115771u); flags=s.arithmetic_flags;
  }
  L006c93fb: { // 0x6c93fb: 0fafc7 IMUL EAX,EDI
    s.ax = integer::imul(s.ax,s.di,32,flags);
  }
  L006c93fe: { // 0x6c93fe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c93ff: { // 0x6c93ff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c9400: { // 0x6c9400: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006c9401: { // 0x6c9401: 8b8798050000 MOV EAX,dword ptr [EDI + 0x598]
    s.ax = m.r32((s.di+0x00000598u));
  }
  L006c9407: { // 0x6c9407: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c9408: { // 0x6c9408: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c9409: { // 0x6c9409: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006c940a: { // 0x6c940a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c940b: { // 0x6c940b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006c940d: { // 0x6c940d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c940e: { // 0x6c940e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00052f60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00452f60: { // 0x452f60: 8b8164050000 MOV EAX,dword ptr [ECX + 0x564]
    s.ax = m.r32((s.cx+0x00000564u));
  }
  L00452f66: { // 0x452f66: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: { // Original same-frame indirect tail
    if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("669 unproved tail target");
    s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
  }
}
void f_000538b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004538b0: { // 0x4538b0: 8b8118040000 MOV EAX, dword ptr [ECX + 0x418]
    s.ax = m.r32((s.cx+0x00000418u));
  }
  L004538b6: { // 0x4538b6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX, 6
    s.ax = 6u;
  }
  L00453895: { // 0x453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void f_002c86c0(Memory&m,State&s,Frame&f,const Operations&op){
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c86c0: { // 0x6c86c0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c86c1: { // 0x6c86c1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c86c2: { // 0x6c86c2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c86c3: { // 0x6c86c3: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L006c86c5: { // 0x6c86c5: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006c86c7: { // 0x6c86c7: 8b8fb4010000 MOV ECX,dword ptr [EDI + 0x1b4]
    s.cx = m.r32((s.di+0x000001b4u));
  }
  L006c86cd: { // 0x6c86cd: 8b81c8000000 MOV EAX,dword ptr [ECX + 0xc8]
    s.ax = m.r32((s.cx+0x000000c8u));
  }
  L006c86d3: { // 0x6c86d3: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L006c86d6: { // 0x6c86d6: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006c86db: { // 0x6c86db: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L006c86de: { // 0x6c86de: 389c02e2110000 CMP byte ptr [EDX + EAX*0x1 + 0x11e2],BL
    (void)integer::sub(m.r8((s.dx+(s.ax * 0x00000001u)+0x000011e2u)),(s.bx & 0xffu),8,flags);
  }
  L006c86e5: { // 0x6c86e5: 7510 JNZ 0x006c86f7
    if(integer::condition("JNZ",flags)) goto L006c86f7;
  }
  L006c86e7: { // 0x6c86e7: 8b8994010000 MOV ECX,dword ptr [ECX + 0x194]
    s.cx = m.r32((s.cx+0x00000194u));
  }
  L006c86ed: { // 0x6c86ed: 8b90b8100000 MOV EDX,dword ptr [EAX + 0x10b8]
    s.dx = m.r32((s.ax+0x000010b8u));
  }
  L006c86f3: { // 0x6c86f3: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L006c86f5: { // 0x6c86f5: 7c2e JL 0x006c8725
    if(integer::condition("JL",flags)) goto L006c8725;
  }
  L006c86f7: { // 0x6c86f7: 8b87fc000000 MOV EAX,dword ptr [EDI + 0xfc]
    s.ax = m.r32((s.di+0x000000fcu));
  }
  L006c86fd: { // 0x6c86fd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c86ff: { // 0x6c86ff: 7424 JZ 0x006c8725
    if(integer::condition("JZ",flags)) goto L006c8725;
  }
  L006c8701: { // 0x6c8701: 8d8ff8000000 LEA ECX,[EDI + 0xf8]
    s.cx = (s.di+0x000000f8u);
  }
  L006c8707: { // 0x6c8707: e824ffd9ff CALL 0x00468630
    s.arithmetic_flags=flags; invoke(m,s,f,0x00468630u,7112460u); flags=s.arithmetic_flags;
  }
  L006c870c: { // 0x6c870c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006c870e: { // 0x6c870e: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006c8710: { // 0x6c8710: 7413 JZ 0x006c8725
    if(integer::condition("JZ",flags)) goto L006c8725;
  }
  L006c8712: { // 0x6c8712: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c8714: { // 0x6c8714: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c8716: { // 0x6c8716: ff9268010000 CALL dword ptr [EDX + 0x168]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000168u)),7112476u); flags=s.arithmetic_flags;
  }
  L006c871c: { // 0x6c871c: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L006c871f: { // 0x6c871f: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L006c8721: { // 0x6c8721: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006c8723: { // 0x6c8723: 75ed JNZ 0x006c8712
    if(integer::condition("JNZ",flags)) goto L006c8712;
  }
  L006c8725: { // 0x6c8725: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006c8727: { // 0x6c8727: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006c8729: { // 0x6c8729: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7112495u); flags=s.arithmetic_flags;
  }
  L006c872f: { // 0x6c872f: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006c8731: { // 0x6c8731: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006c8733: { // 0x6c8733: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006c8735: { // 0x6c8735: ff92a0020000 CALL dword ptr [EDX + 0x2a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000002a0u)),7112507u); flags=s.arithmetic_flags;
  }
  L006c873b: { // 0x6c873b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006c873d: { // 0x6c873d: 8b869c050000 MOV EAX,dword ptr [ESI + 0x59c]
    s.ax = m.r32((s.si+0x0000059cu));
  }
  L006c8743: { // 0x6c8743: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006c8745: { // 0x6c8745: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c8746: { // 0x6c8746: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L006c8748: { // 0x6c8748: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c8749: { // 0x6c8749: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c874a: { // 0x6c874a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 0x6c86c0u:f_002c86c0(m,s,child,{});break;
case 4621872u:f_00068630(m,s,child,{});break;
case 7115712u:f_002c93c0(m,s,child,{});break;
case 4534112u:f_00052f60(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
default:throw std::domain_error("recovery669 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006c86c0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c86c0: { // 0x6c86c0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c86c1: { // 0x6c86c1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c86c2: { // 0x6c86c2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c86c3: { // 0x6c86c3: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L006c86c5: { // 0x6c86c5: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006c86c7: { // 0x6c86c7: 8b8fb4010000 MOV ECX,dword ptr [EDI + 0x1b4]
    s.cx = m.r32((s.di+0x000001b4u));
  }
  L006c86cd: { // 0x6c86cd: 8b81c8000000 MOV EAX,dword ptr [ECX + 0xc8]
    s.ax = m.r32((s.cx+0x000000c8u));
  }
  L006c86d3: { // 0x6c86d3: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L006c86d6: { // 0x6c86d6: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006c86db: { // 0x6c86db: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L006c86de: { // 0x6c86de: 389c02e2110000 CMP byte ptr [EDX + EAX*0x1 + 0x11e2],BL
    (void)integer::sub(m.r8((s.dx+(s.ax * 0x00000001u)+0x000011e2u)),(s.bx & 0xffu),8,flags);
  }
  L006c86e5: { // 0x6c86e5: 7510 JNZ 0x006c86f7
    if(integer::condition("JNZ",flags)) goto L006c86f7;
  }
  L006c86e7: { // 0x6c86e7: 8b8994010000 MOV ECX,dword ptr [ECX + 0x194]
    s.cx = m.r32((s.cx+0x00000194u));
  }
  L006c86ed: { // 0x6c86ed: 8b90b8100000 MOV EDX,dword ptr [EAX + 0x10b8]
    s.dx = m.r32((s.ax+0x000010b8u));
  }
  L006c86f3: { // 0x6c86f3: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L006c86f5: { // 0x6c86f5: 7c2e JL 0x006c8725
    if(integer::condition("JL",flags)) goto L006c8725;
  }
  L006c86f7: { // 0x6c86f7: 8b87fc000000 MOV EAX,dword ptr [EDI + 0xfc]
    s.ax = m.r32((s.di+0x000000fcu));
  }
  L006c86fd: { // 0x6c86fd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c86ff: { // 0x6c86ff: 7424 JZ 0x006c8725
    if(integer::condition("JZ",flags)) goto L006c8725;
  }
  L006c8701: { // 0x6c8701: 8d8ff8000000 LEA ECX,[EDI + 0xf8]
    s.cx = (s.di+0x000000f8u);
  }
  L006c8707: { // 0x6c8707: e824ffd9ff CALL 0x00468630
    s.arithmetic_flags=flags; invoke(m,s,f,0x00468630u,7112460u); flags=s.arithmetic_flags;
  }
  L006c870c: { // 0x6c870c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006c870e: { // 0x6c870e: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006c8710: { // 0x6c8710: 7413 JZ 0x006c8725
    if(integer::condition("JZ",flags)) goto L006c8725;
  }
  L006c8712: { // 0x6c8712: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c8714: { // 0x6c8714: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c8716: { // 0x6c8716: ff9268010000 CALL dword ptr [EDX + 0x168]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000168u)),7112476u); flags=s.arithmetic_flags;
  }
  L006c871c: { // 0x6c871c: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L006c871f: { // 0x6c871f: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L006c8721: { // 0x6c8721: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006c8723: { // 0x6c8723: 75ed JNZ 0x006c8712
    if(integer::condition("JNZ",flags)) goto L006c8712;
  }
  L006c8725: { // 0x6c8725: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006c8727: { // 0x6c8727: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006c8729: { // 0x6c8729: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7112495u); flags=s.arithmetic_flags;
  }
  L006c872f: { // 0x6c872f: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006c8731: { // 0x6c8731: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006c8733: { // 0x6c8733: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006c8735: { // 0x6c8735: ff92a0020000 CALL dword ptr [EDX + 0x2a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000002a0u)),7112507u); flags=s.arithmetic_flags;
  }
  L006c873b: { // 0x6c873b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006c873d: { // 0x6c873d: 8b869c050000 MOV EAX,dword ptr [ESI + 0x59c]
    s.ax = m.r32((s.si+0x0000059cu));
  }
  L006c8743: { // 0x6c8743: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006c8745: { // 0x6c8745: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c8746: { // 0x6c8746: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L006c8748: { // 0x6c8748: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c8749: { // 0x6c8749: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c874a: { // 0x6c874a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
