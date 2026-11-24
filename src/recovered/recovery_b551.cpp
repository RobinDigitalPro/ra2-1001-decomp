#include "recovered/recovery_b551_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b551 {
namespace {
void f_0000dc20(Memory&,State&,Frame&,const Operations&);
void f_002eb5e0(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0000dc20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040dc20: { // 0x40dc20: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0040dc21: { // 0x40dc21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0040dc23: { // 0x40dc23: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0040dc25: { // 0x40dc25: 741e JZ 0x0040dc45
    if(integer::condition("JZ",flags)) goto L0040dc45;
  }
  L0040dc27: { // 0x40dc27: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0040dc29: { // 0x40dc29: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4250668u); flags=s.arithmetic_flags;
  }
  L0040dc2c: { // 0x40dc2c: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0040dc2d: { // 0x40dc2d: 83f80e CMP EAX,0xe
    (void)integer::sub(s.ax,0x0000000eu,32,flags);
  }
  L0040dc30: { // 0x40dc30: 7713 JA 0x0040dc45
    if(integer::condition("JA",flags)) goto L0040dc45;
  }
  L0040dc32: { // 0x40dc32: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0040dc34: { // 0x40dc34: 8a8854dc4000 MOV CL,byte ptr [EAX + 0x40dc54]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0040dc54u)));
  }
  L0040dc3a: { // 0x40dc3a: ff248d4cdc4000 JMP dword ptr [ECX*0x4 + 0x40dc4c]
    switch(m.r32(((s.cx * 0x00000004u)+0x0040dc4cu))){
    case 0x0040dc20u: goto L0040dc20;
    case 0x0040dc21u: goto L0040dc21;
    case 0x0040dc23u: goto L0040dc23;
    case 0x0040dc25u: goto L0040dc25;
    case 0x0040dc27u: goto L0040dc27;
    case 0x0040dc29u: goto L0040dc29;
    case 0x0040dc2cu: goto L0040dc2c;
    case 0x0040dc2du: goto L0040dc2d;
    case 0x0040dc30u: goto L0040dc30;
    case 0x0040dc32u: goto L0040dc32;
    case 0x0040dc34u: goto L0040dc34;
    case 0x0040dc3au: goto L0040dc3a;
    case 0x0040dc41u: goto L0040dc41;
    case 0x0040dc43u: goto L0040dc43;
    case 0x0040dc44u: goto L0040dc44;
    case 0x0040dc45u: goto L0040dc45;
    case 0x0040dc47u: goto L0040dc47;
    case 0x0040dc48u: goto L0040dc48;
    default:throw std::domain_error("recovery551 unsupported switch destination");}
  }
  L0040dc41: { // 0x40dc41: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0040dc43: { // 0x40dc43: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0040dc44: { // 0x40dc44: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0040dc45: { // 0x40dc45: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040dc47: { // 0x40dc47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0040dc48: { // 0x40dc48: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002eb5e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006eb5e0: { // 0x6eb5e0: 890db48daa00 MOV dword ptr [0x00aa8db4],ECX
    m.w32((0x00aa8db4u), s.cx);
  }
  L006eb5e6: { // 0x6eb5e6: c605b88daa0000 MOV byte ptr [0x00aa8db8],0x0
    m.w8((0x00aa8db8u), 0x00000000u);
  }
  L006eb5ed: { // 0x6eb5ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX,0x6
    s.ax = 0x00000006u;
  }
  L00453895: { // 0x453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4250656u:f_0000dc20(m,s,child,{});break;
case 7255520u:f_002eb5e0(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
default:throw std::domain_error("recovery551 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_005cb500(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 std::array<std::uint8_t,23> table{0x41,0xdc,0x40,0x0,0x45,0xdc,0x40,0x0,0x0,0x0,0x1,0x1,0x1,0x0,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x0};leaf::Memory ro(table.data(),0x40dc4c,23);m.add(ro);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cb500: { // 0x5cb500: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cb501: { // 0x5cb501: a05389a200 MOV AL,[0x00a28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  L005cb506: { // 0x5cb506: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cb507: { // 0x5cb507: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb509: { // 0x5cb509: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cb50a: { // 0x5cb50a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005cb50c: { // 0x5cb50c: 7520 JNZ 0x005cb52e
    if(integer::condition("JNZ",flags)) goto L005cb52e;
  }
  L005cb50e: { // 0x5cb50e: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L005cb511: { // 0x5cb511: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb513: { // 0x5cb513: 7513 JNZ 0x005cb528
    if(integer::condition("JNZ",flags)) goto L005cb528;
  }
  L005cb515: { // 0x5cb515: 8a4677 MOV AL,byte ptr [ESI + 0x77]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000077u)));
  }
  L005cb518: { // 0x5cb518: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb51a: { // 0x5cb51a: 750c JNZ 0x005cb528
    if(integer::condition("JNZ",flags)) goto L005cb528;
  }
  L005cb51c: { // 0x5cb51c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cb51e: { // 0x5cb51e: ff9030010000 CALL dword ptr [EAX + 0x130]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000130u)),6075684u); flags=s.arithmetic_flags;
  }
  L005cb524: { // 0x5cb524: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb526: { // 0x5cb526: 7506 JNZ 0x005cb52e
    if(integer::condition("JNZ",flags)) goto L005cb52e;
  }
  L005cb528: { // 0x5cb528: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cb529: { // 0x5cb529: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005cb52b: { // 0x5cb52b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cb52c: { // 0x5cb52c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005cb52d: { // 0x5cb52d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005cb52e: { // 0x5cb52e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cb530: { // 0x5cb530: e8eb26e4ff CALL 0x0040dc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040dc20u,6075701u); flags=s.arithmetic_flags;
  }
  L005cb535: { // 0x5cb535: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L005cb537: { // 0x5cb537: a05389a200 MOV AL,[0x00a28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  L005cb53c: { // 0x5cb53c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb53e: { // 0x5cb53e: 7522 JNZ 0x005cb562
    if(integer::condition("JNZ",flags)) goto L005cb562;
  }
  L005cb540: { // 0x5cb540: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005cb542: { // 0x5cb542: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cb544: { // 0x5cb544: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),6075722u); flags=s.arithmetic_flags;
  }
  L005cb54a: { // 0x5cb54a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb54c: { // 0x5cb54c: 7414 JZ 0x005cb562
    if(integer::condition("JZ",flags)) goto L005cb562;
  }
  L005cb54e: { // 0x5cb54e: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005cb550: { // 0x5cb550: 7410 JZ 0x005cb562
    if(integer::condition("JZ",flags)) goto L005cb562;
  }
  L005cb552: { // 0x5cb552: 8a872c030000 MOV AL,byte ptr [EDI + 0x32c]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000032cu)));
  }
  L005cb558: { // 0x5cb558: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb55a: { // 0x5cb55a: 7406 JZ 0x005cb562
    if(integer::condition("JZ",flags)) goto L005cb562;
  }
  L005cb55c: { // 0x5cb55c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cb55d: { // 0x5cb55d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005cb55f: { // 0x5cb55f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cb560: { // 0x5cb560: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005cb561: { // 0x5cb561: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005cb562: { // 0x5cb562: a1c4b98100 MOV EAX,[0x0081b9c4]
    s.ax = m.r32((0x0081b9c4u));
  }
  L005cb567: { // 0x5cb567: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cb569: { // 0x5cb569: 7406 JZ 0x005cb571
    if(integer::condition("JZ",flags)) goto L005cb571;
  }
  L005cb56b: { // 0x5cb56b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cb56c: { // 0x5cb56c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005cb56e: { // 0x5cb56e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cb56f: { // 0x5cb56f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005cb570: { // 0x5cb570: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005cb571: { // 0x5cb571: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  L005cb576: { // 0x5cb576: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cb578: { // 0x5cb578: 7e46 JLE 0x005cb5c0
    if(integer::condition("JLE",flags)) goto L005cb5c0;
  }
  L005cb57a: { // 0x5cb57a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cb57c: { // 0x5cb57c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005cb57d: { // 0x5cb57d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cb57f: { // 0x5cb57f: ff503c CALL dword ptr [EAX + 0x3c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000003cu)),6075778u); flags=s.arithmetic_flags;
  }
  L005cb582: { // 0x5cb582: 8b0da488a200 MOV ECX,dword ptr [0x00a288a4]
    s.cx = m.r32((0x00a288a4u));
  }
  L005cb588: { // 0x5cb588: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L005cb58a: { // 0x5cb58a: 8b09 MOV ECX,dword ptr [ECX]
    s.cx = m.r32((s.cx));
  }
  L005cb58c: { // 0x5cb58c: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L005cb58e: { // 0x5cb58e: ff523c CALL dword ptr [EDX + 0x3c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000003cu)),6075793u); flags=s.arithmetic_flags;
  }
  L005cb591: { // 0x5cb591: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L005cb593: { // 0x5cb593: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005cb595: { // 0x5cb595: e81692f2ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,6075802u); flags=s.arithmetic_flags;
  }
  L005cb59a: { // 0x5cb59a: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  L005cb59c: { // 0x5cb59c: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L005cb59e: { // 0x5cb59e: 8854240f MOV byte ptr [ESP + 0xf],DL
    m.w8((f.sp+0x0000000fu), (s.dx & 0xffu));
  }
  L005cb5a2: { // 0x5cb5a2: e80992f2ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,6075815u); flags=s.arithmetic_flags;
  }
  L005cb5a7: { // 0x5cb5a7: 8a4c240f MOV CL,byte ptr [ESP + 0xf]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000000fu)));
  }
  L005cb5ab: { // 0x5cb5ab: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005cb5ac: { // 0x5cb5ac: 3ac8 CMP CL,AL
    (void)integer::sub((s.cx & 0xffu),(s.ax & 0xffu),8,flags);
  }
  L005cb5ae: { // 0x5cb5ae: 750b JNZ 0x005cb5bb
    if(integer::condition("JNZ",flags)) goto L005cb5bb;
  }
  L005cb5b0: { // 0x5cb5b0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005cb5b2: { // 0x5cb5b2: e8f991f2ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,6075831u); flags=s.arithmetic_flags;
  }
  L005cb5b7: { // 0x5cb5b7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb5b9: { // 0x5cb5b9: 7505 JNZ 0x005cb5c0
    if(integer::condition("JNZ",flags)) goto L005cb5c0;
  }
  L005cb5bb: { // 0x5cb5bb: e8a073ebff CALL 0x00482960
    s.arithmetic_flags=flags; invoke(m,s,f,0x00482960u,6075840u); flags=s.arithmetic_flags;
  }
  L005cb5c0: { // 0x5cb5c0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005cb5c2: { // 0x5cb5c2: 0f84b3000000 JZ 0x005cb67b
    if(integer::condition("JZ",flags)) goto L005cb67b;
  }
  L005cb5c8: { // 0x5cb5c8: 8a5614 MOV DL,byte ptr [ESI + 0x14]
    s.dx = with_al(s.dx, m.r8((s.si+0x00000014u)));
  }
  L005cb5cb: { // 0x5cb5cb: 80e201 AND DL,0x1
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags));
  }
  L005cb5ce: { // 0x5cb5ce: 8854240b MOV byte ptr [ESP + 0xb],DL
    m.w8((f.sp+0x0000000bu), (s.dx & 0xffu));
  }
  L005cb5d2: { // 0x5cb5d2: 0f84a3000000 JZ 0x005cb67b
    if(integer::condition("JZ",flags)) goto L005cb67b;
  }
  L005cb5d8: { // 0x5cb5d8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005cb5da: { // 0x5cb5da: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cb5dc: { // 0x5cb5dc: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6075874u); flags=s.arithmetic_flags;
  }
  L005cb5e2: { // 0x5cb5e2: 8a88a80a0000 MOV CL,byte ptr [EAX + 0xaa8]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000aa8u)));
  }
  L005cb5e8: { // 0x5cb5e8: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005cb5ea: { // 0x5cb5ea: 0f848b000000 JZ 0x005cb67b
    if(integer::condition("JZ",flags)) goto L005cb67b;
  }
  L005cb5f0: { // 0x5cb5f0: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  L005cb5f5: { // 0x5cb5f5: 8b0da888a200 MOV ECX,dword ptr [0x00a288a8]
    s.cx = m.r32((0x00a288a8u));
  }
  L005cb5fb: { // 0x5cb5fb: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cb5fd: { // 0x5cb5fd: 7c3e JL 0x005cb63d
    if(integer::condition("JL",flags)) goto L005cb63d;
  }
  L005cb5ff: { // 0x5cb5ff: a0ad88a200 MOV AL,[0x00a288ad]
    s.ax = with_al(s.ax, m.r8((0x00a288adu)));
  }
  L005cb604: { // 0x5cb604: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb606: { // 0x5cb606: 7508 JNZ 0x005cb610
    if(integer::condition("JNZ",flags)) goto L005cb610;
  }
  L005cb608: { // 0x5cb608: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005cb60a: { // 0x5cb60a: 0f85c1000000 JNZ 0x005cb6d1
    if(integer::condition("JNZ",flags)) goto L005cb6d1;
  }
  L005cb610: { // 0x5cb610: a1b488a200 MOV EAX,[0x00a288b4]
    s.ax = m.r32((0x00a288b4u));
  }
  L005cb615: { // 0x5cb615: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cb617: { // 0x5cb617: 0f8eb4000000 JLE 0x005cb6d1
    if(integer::condition("JLE",flags)) goto L005cb6d1;
  }
  L005cb61d: { // 0x5cb61d: 8b15a088a200 MOV EDX,dword ptr [0x00a288a0]
    s.dx = m.r32((0x00a288a0u));
  }
  L005cb623: { // 0x5cb623: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005cb625: { // 0x5cb625: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005cb627: { // 0x5cb627: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cb628: { // 0x5cb628: b9a088a200 MOV ECX,0xa288a0
    s.cx = 0x00a288a0u;
  }
  L005cb62d: { // 0x5cb62d: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6075952u); flags=s.arithmetic_flags;
  }
  L005cb630: { // 0x5cb630: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb632: { // 0x5cb632: 0f8499000000 JZ 0x005cb6d1
    if(integer::condition("JZ",flags)) goto L005cb6d1;
  }
  L005cb638: { // 0x5cb638: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  L005cb63d: { // 0x5cb63d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cb63f: { // 0x5cb63f: 7416 JZ 0x005cb657
    if(integer::condition("JZ",flags)) goto L005cb657;
  }
  L005cb641: { // 0x5cb641: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L005cb644: { // 0x5cb644: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cb645: { // 0x5cb645: a1a488a200 MOV EAX,[0x00a288a4]
    s.ax = m.r32((0x00a288a4u));
  }
  L005cb64a: { // 0x5cb64a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cb64b: { // 0x5cb64b: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L005cb64e: { // 0x5cb64e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cb64f: { // 0x5cb64f: e87c351a00 CALL 0x0076ebd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ebd0u,6075988u); flags=s.arithmetic_flags;
  }
  L005cb654: { // 0x5cb654: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005cb657: { // 0x5cb657: 8b0da488a200 MOV ECX,dword ptr [0x00a288a4]
    s.cx = m.r32((0x00a288a4u));
  }
  L005cb65d: { // 0x5cb65d: 8931 MOV dword ptr [ECX],ESI
    m.w32((s.cx), s.si);
  }
  L005cb65f: { // 0x5cb65f: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  L005cb664: { // 0x5cb664: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005cb665: { // 0x5cb665: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005cb667: { // 0x5cb667: a3b088a200 MOV [0x00a288b0],EAX
    m.w32((0x00a288b0u), s.ax);
  }
  L005cb66c: { // 0x5cb66c: e86fff1100 CALL 0x006eb5e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006eb5e0u,6076017u); flags=s.arithmetic_flags;
  }
  L005cb671: { // 0x5cb671: c6467701 MOV byte ptr [ESI + 0x77],0x1
    m.w8((s.si+0x00000077u), 0x00000001u);
  }
  L005cb675: { // 0x5cb675: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cb676: { // 0x5cb676: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cb678: { // 0x5cb678: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cb679: { // 0x5cb679: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005cb67a: { // 0x5cb67a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005cb67b: { // 0x5cb67b: a1a888a200 MOV EAX,[0x00a288a8]
    s.ax = m.r32((0x00a288a8u));
  }
  L005cb680: { // 0x5cb680: 8b0db088a200 MOV ECX,dword ptr [0x00a288b0]
    s.cx = m.r32((0x00a288b0u));
  }
  L005cb686: { // 0x5cb686: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005cb688: { // 0x5cb688: 7c2f JL 0x005cb6b9
    if(integer::condition("JL",flags)) goto L005cb6b9;
  }
  L005cb68a: { // 0x5cb68a: 8a0dad88a200 MOV CL,byte ptr [0x00a288ad]
    s.cx = with_al(s.cx, m.r8((0x00a288adu)));
  }
  L005cb690: { // 0x5cb690: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005cb692: { // 0x5cb692: 7504 JNZ 0x005cb698
    if(integer::condition("JNZ",flags)) goto L005cb698;
  }
  L005cb694: { // 0x5cb694: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005cb696: { // 0x5cb696: 7539 JNZ 0x005cb6d1
    if(integer::condition("JNZ",flags)) goto L005cb6d1;
  }
  L005cb698: { // 0x5cb698: 8b0db488a200 MOV ECX,dword ptr [0x00a288b4]
    s.cx = m.r32((0x00a288b4u));
  }
  L005cb69e: { // 0x5cb69e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005cb6a0: { // 0x5cb6a0: 7e2f JLE 0x005cb6d1
    if(integer::condition("JLE",flags)) goto L005cb6d1;
  }
  L005cb6a2: { // 0x5cb6a2: 8b15a088a200 MOV EDX,dword ptr [0x00a288a0]
    s.dx = m.r32((0x00a288a0u));
  }
  L005cb6a8: { // 0x5cb6a8: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L005cb6aa: { // 0x5cb6aa: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L005cb6ac: { // 0x5cb6ac: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cb6ad: { // 0x5cb6ad: b9a088a200 MOV ECX,0xa288a0
    s.cx = 0x00a288a0u;
  }
  L005cb6b2: { // 0x5cb6b2: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6076085u); flags=s.arithmetic_flags;
  }
  L005cb6b5: { // 0x5cb6b5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cb6b7: { // 0x5cb6b7: 7418 JZ 0x005cb6d1
    if(integer::condition("JZ",flags)) goto L005cb6d1;
  }
  L005cb6b9: { // 0x5cb6b9: 8b0db088a200 MOV ECX,dword ptr [0x00a288b0]
    s.cx = m.r32((0x00a288b0u));
  }
  L005cb6bf: { // 0x5cb6bf: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005cb6c1: { // 0x5cb6c1: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005cb6c2: { // 0x5cb6c2: 890db088a200 MOV dword ptr [0x00a288b0],ECX
    m.w32((0x00a288b0u), s.cx);
  }
  L005cb6c8: { // 0x5cb6c8: 8b0da488a200 MOV ECX,dword ptr [0x00a288a4]
    s.cx = m.r32((0x00a288a4u));
  }
  L005cb6ce: { // 0x5cb6ce: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005cb6d1: { // 0x5cb6d1: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005cb6d3: { // 0x5cb6d3: e808ff1100 CALL 0x006eb5e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006eb5e0u,6076120u); flags=s.arithmetic_flags;
  }
  L005cb6d8: { // 0x5cb6d8: c6467701 MOV byte ptr [ESI + 0x77],0x1
    m.w8((s.si+0x00000077u), 0x00000001u);
  }
  L005cb6dc: { // 0x5cb6dc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cb6dd: { // 0x5cb6dd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cb6df: { // 0x5cb6df: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cb6e0: { // 0x5cb6e0: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005cb6e1: { // 0x5cb6e1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
