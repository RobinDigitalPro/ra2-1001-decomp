#include "recovered/recovery_b242_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b242 {
namespace {
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_00190060(Memory&,State&,Frame&,const Operations&);
void f_0018e5c0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI,word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x00545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x00545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x00545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX,dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00190060(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00590060: { // 0x590060: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L00590064: { // 0x590064: 83ec0c SUB ESP, 0xC
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00590067: { // 0x590067: 8d542400 LEA EDX, [ESP]
    s.dx = (f.sp);
  }
  L0059006b: { // 0x59006b: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0059006d: { // 0x59006d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0059006e: { // 0x59006e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0059006f: { // 0x59006f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00590070: { // 0x590070: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00590071: { // 0x590071: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00590072: { // 0x590072: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00590073: { // 0x590073: ff5118 CALL dword ptr [ECX + 0x18]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000018u)),5832822u); flags=s.arithmetic_flags;
  }
  L00590076: { // 0x590076: 8b30 MOV ESI, dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L00590078: { // 0x590078: 8b5804 MOV EBX, dword ptr [EAX + 4]
    s.bx = m.r32((s.ax+4u));
  }
  L0059007b: { // 0x59007b: 8b6808 MOV EBP, dword ptr [EAX + 8]
    s.bp = m.r32((s.ax+8u));
  }
  L0059007e: { // 0x59007e: 8b442424 MOV EAX, dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00590082: { // 0x590082: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00590083: { // 0x590083: 81e2ff000000 AND EDX, 0xFF
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00590089: { // 0x590089: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0059008b: { // 0x59008b: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0059008d: { // 0x59008d: 8b442428 MOV EAX, dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00590091: { // 0x590091: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00590092: { // 0x590092: 81e2ff000000 AND EDX, 0xFF
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00590098: { // 0x590098: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0059009a: { // 0x59009a: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0059009c: { // 0x59009c: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L0059009e: { // 0x59009e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0059009f: { // 0x59009f: 81e2ff000000 AND EDX, 0xFF
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L005900a5: { // 0x5900a5: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005900a7: { // 0x5900a7: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L005900a9: { // 0x5900a9: 8bc3 MOV EAX, EBX
    s.ax = s.bx;
  }
  L005900ab: { // 0x5900ab: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005900ac: { // 0x5900ac: 81e2ff000000 AND EDX, 0xFF
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L005900b2: { // 0x5900b2: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005900b4: { // 0x5900b4: c1f908 SAR ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005900b7: { // 0x5900b7: c1fe08 SAR ESI, 8
    s.si = integer::shift(s.si,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005900ba: { // 0x5900ba: c1ff08 SAR EDI, 8
    s.di = integer::shift(s.di,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005900bd: { // 0x5900bd: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005900c0: { // 0x5900c0: 663bf1 CMP SI, CX
    (void)integer::sub((s.si & 0xffffu),(s.cx & 0xffffu),16,flags);
  }
  L005900c3: { // 0x5900c3: 7528 JNZ 0x5900ED
    if(integer::condition("JNZ",flags)) goto L005900ed;
  }
  L005900c5: { // 0x5900c5: 663bc7 CMP AX, DI
    (void)integer::sub((s.ax & 0xffffu),(s.di & 0xffffu),16,flags);
  }
  L005900c8: { // 0x5900c8: 7523 JNZ 0x5900ED
    if(integer::condition("JNZ",flags)) goto L005900ed;
  }
  L005900ca: { // 0x5900ca: 8b5c242c MOV EBX, dword ptr [ESP + 0x2C]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L005900ce: { // 0x5900ce: 8bc5 MOV EAX, EBP
    s.ax = s.bp;
  }
  L005900d0: { // 0x5900d0: 8b0d6887a500 MOV ECX, dword ptr [0xA58768]
    s.cx = m.r32((0x00a58768u));
  }
  L005900d6: { // 0x5900d6: 2bc3 SUB EAX, EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L005900d8: { // 0x5900d8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005900d9: { // 0x5900d9: 33c2 XOR EAX, EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L005900db: { // 0x5900db: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005900dd: { // 0x5900dd: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005900df: { // 0x5900df: 7f0c JG 0x5900ED
    if(integer::condition("JG",flags)) goto L005900ed;
  }
  L005900e1: { // 0x5900e1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005900e2: { // 0x5900e2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005900e3: { // 0x5900e3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005900e4: { // 0x5900e4: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L005900e6: { // 0x5900e6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005900e7: { // 0x5900e7: 83c40c ADD ESP, 0xC
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005900ea: { // 0x5900ea: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L005900ed: { // 0x5900ed: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005900ee: { // 0x5900ee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005900ef: { // 0x5900ef: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005900f0: { // 0x5900f0: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005900f2: { // 0x5900f2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005900f3: { // 0x5900f3: 83c40c ADD ESP, 0xC
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005900f6: { // 0x5900f6: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}
void f_0018e5c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058e5c0: { // 0x58e5c0: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L0058e5c4: { // 0x58e5c4: 8b153087a500 MOV EDX, dword ptr [0xA58730]
    s.dx = m.r32((0x00a58730u));
  }
  L0058e5ca: { // 0x58e5ca: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058e5cb: { // 0x58e5cb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058e5cc: { // 0x58e5cc: 8b4820 MOV ECX, dword ptr [EAX + 0x20]
    s.cx = m.r32((s.ax+0x00000020u));
  }
  L0058e5cf: { // 0x58e5cf: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0058e5d1: { // 0x58e5d1: 751a JNZ 0x58E5ED
    if(integer::condition("JNZ",flags)) goto L0058e5ed;
  }
  L0058e5d3: { // 0x58e5d3: 8b5024 MOV EDX, dword ptr [EAX + 0x24]
    s.dx = m.r32((s.ax+0x00000024u));
  }
  L0058e5d6: { // 0x58e5d6: 8b0d3487a500 MOV ECX, dword ptr [0xA58734]
    s.cx = m.r32((0x00a58734u));
  }
  L0058e5dc: { // 0x58e5dc: 3bd1 CMP EDX, ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0058e5de: { // 0x58e5de: 750d JNZ 0x58E5ED
    if(integer::condition("JNZ",flags)) goto L0058e5ed;
  }
  L0058e5e0: { // 0x58e5e0: 8b4828 MOV ECX, dword ptr [EAX + 0x28]
    s.cx = m.r32((s.ax+0x00000028u));
  }
  L0058e5e3: { // 0x58e5e3: 8b153887a500 MOV EDX, dword ptr [0xA58738]
    s.dx = m.r32((0x00a58738u));
  }
  L0058e5e9: { // 0x58e5e9: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0058e5eb: { // 0x58e5eb: 741e JZ 0x58E60B
    if(integer::condition("JZ",flags)) goto L0058e60b;
  }
  L0058e5ed: { // 0x58e5ed: 8b742410 MOV ESI, dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0058e5f1: { // 0x58e5f1: 8b4820 MOV ECX, dword ptr [EAX + 0x20]
    s.cx = m.r32((s.ax+0x00000020u));
  }
  L0058e5f4: { // 0x58e5f4: 8b5024 MOV EDX, dword ptr [EAX + 0x24]
    s.dx = m.r32((s.ax+0x00000024u));
  }
  L0058e5f7: { // 0x58e5f7: 8b4028 MOV EAX, dword ptr [EAX + 0x28]
    s.ax = m.r32((s.ax+0x00000028u));
  }
  L0058e5fa: { // 0x58e5fa: 8bfe MOV EDI, ESI
    s.di = s.si;
  }
  L0058e5fc: { // 0x58e5fc: 890f MOV dword ptr [EDI], ECX
    m.w32((s.di), s.cx);
  }
  L0058e5fe: { // 0x58e5fe: 895704 MOV dword ptr [EDI + 4], EDX
    m.w32((s.di+4u), s.dx);
  }
  L0058e601: { // 0x58e601: 894708 MOV dword ptr [EDI + 8], EAX
    m.w32((s.di+8u), s.ax);
  }
  L0058e604: { // 0x58e604: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L0058e606: { // 0x58e606: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058e607: { // 0x58e607: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058e608: { // 0x58e608: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0058e60b: { // 0x58e60b: 8b5008 MOV EDX, dword ptr [EAX + 8]
    s.dx = m.r32((s.ax+8u));
  }
  L0058e60e: { // 0x58e60e: 81c288000000 ADD EDX, 0x88
    s.dx = integer::add(s.dx,0x00000088u,32,flags);
  }
  L0058e614: { // 0x58e614: 8bc2 MOV EAX, EDX
    s.ax = s.dx;
  }
  L0058e616: { // 0x58e616: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0058e618: { // 0x58e618: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0058e61b: { // 0x58e61b: 8b7008 MOV ESI, dword ptr [EAX + 8]
    s.si = m.r32((s.ax+8u));
  }
  L0058e61e: { // 0x58e61e: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0058e622: { // 0x58e622: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L0058e624: { // 0x58e624: 890f MOV dword ptr [EDI], ECX
    m.w32((s.di), s.cx);
  }
  L0058e626: { // 0x58e626: 895704 MOV dword ptr [EDI + 4], EDX
    m.w32((s.di+4u), s.dx);
  }
  L0058e629: { // 0x58e629: 897708 MOV dword ptr [EDI + 8], ESI
    m.w32((s.di+8u), s.si);
  }
  L0058e62c: { // 0x58e62c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058e62d: { // 0x58e62d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058e62e: { // 0x58e62e: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5526784u:f_00145500(m,s,child,{});break;
case 5832800u:f_00190060(m,s,child,{});break;
case 5825984u:f_0018e5c0(m,s,child,{});break;
default:throw std::domain_error("recovery242 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00428950(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00428950: { // 0x428950: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L00428953: { // 0x428953: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00428954: { // 0x428954: 8b5c2420 MOV EBX,dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  L00428958: { // 0x428958: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00428959: { // 0x428959: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042895a: { // 0x42895a: 0fbf03 MOVSX EAX,word ptr [EBX]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L0042895d: { // 0x42895d: 0fbf4b02 MOVSX ECX,word ptr [EBX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L00428961: { // 0x428961: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00428964: { // 0x428964: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00428967: { // 0x428967: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00428968: { // 0x428968: 8b3d486b8300 MOV EDI,dword ptr [0x00836b48]
    s.di = m.r32((0x00836b48u));
  }
  L0042896e: { // 0x42896e: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L00428973: { // 0x428973: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L00428979: { // 0x428979: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0042897b: { // 0x42897b: 0faf7c2430 IMUL EDI,dword ptr [ESP + 0x30]
    s.di = integer::imul(s.di,m.r32((f.sp+0x00000030u)),32,flags);
  }
  L00428980: { // 0x428980: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00428984: { // 0x428984: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00428988: { // 0x428988: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0042898c: { // 0x42898c: c7442410feffffff MOV dword ptr [ESP + 0x10],0xfffffffe
    m.w32((f.sp+0x00000010u), 0xfffffffeu);
  }
  L00428994: { // 0x428994: bdfeffffff MOV EBP,0xfffffffe
    s.bp = 0xfffffffeu;
  }
  L00428999: { // 0x428999: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L0042899d: { // 0x42899d: 668b03 MOV AX,word ptr [EBX]
    s.ax = with_ax(s.ax, m.r16((s.bx)));
  }
  L004289a0: { // 0x4289a0: 668b4b02 MOV CX,word ptr [EBX + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.bx+0x00000002u)));
  }
  L004289a4: { // 0x4289a4: 66034c2410 ADD CX,word ptr [ESP + 0x10]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000010u)),16,flags));
  }
  L004289a9: { // 0x4289a9: 6603c5 ADD AX,BP
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L004289ac: { // 0x4289ac: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L004289b1: { // 0x4289b1: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  L004289b5: { // 0x4289b5: 66894c2416 MOV word ptr [ESP + 0x16],CX
    m.w16((f.sp+0x00000016u), (s.cx & 0xffffu));
  }
  L004289ba: { // 0x4289ba: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L004289be: { // 0x4289be: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004289bf: { // 0x4289bf: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004289c4: { // 0x4289c4: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L004289c8: { // 0x4289c8: e833cb1100 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4360653u); flags=s.arithmetic_flags;
  }
  L004289cd: { // 0x4289cd: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004289cf: { // 0x4289cf: 8b8140010000 MOV EAX,dword ptr [ECX + 0x140]
    s.ax = m.r32((s.cx+0x00000140u));
  }
  L004289d5: { // 0x4289d5: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L004289d8: { // 0x4289d8: 741d JZ 0x004289f7
    if(integer::condition("JZ",flags)) goto L004289f7;
  }
  L004289da: { // 0x4289da: 0fbe811b010000 MOVSX EAX,byte ptr [ECX + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L004289e1: { // 0x4289e1: 2b442430 SUB EAX,dword ptr [ESP + 0x30]
    s.ax = integer::sub(s.ax,m.r32((f.sp+0x00000030u)),32,flags);
  }
  L004289e5: { // 0x4289e5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004289e6: { // 0x4289e6: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004289e8: { // 0x4289e8: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004289ea: { // 0x4289ea: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L004289ed: { // 0x4289ed: 7e08 JLE 0x004289f7
    if(integer::condition("JLE",flags)) goto L004289f7;
  }
  L004289ef: { // 0x4289ef: 8bb1e8000000 MOV ESI,dword ptr [ECX + 0xe8]
    s.si = m.r32((s.cx+0x000000e8u));
  }
  L004289f5: { // 0x4289f5: eb06 JMP 0x004289fd
    goto L004289fd;
  }
  L004289f7: { // 0x4289f7: 8bb1e4000000 MOV ESI,dword ptr [ECX + 0xe4]
    s.si = m.r32((s.cx+0x000000e4u));
  }
  L004289fd: { // 0x4289fd: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004289ff: { // 0x4289ff: 7456 JZ 0x00428a57
    if(integer::condition("JZ",flags)) goto L00428a57;
  }
  L00428a01: { // 0x428a01: 8a4e14 MOV CL,byte ptr [ESI + 0x14]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000014u)));
  }
  L00428a04: { // 0x428a04: c0e902 SHR CL,0x2
    s.cx = with_al(s.cx, integer::shift((s.cx & 0xffu),0x00000002u,8,flags,integer::Shift::right));
  }
  L00428a07: { // 0x428a07: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
  L00428a0a: { // 0x428a0a: 884c242c MOV byte ptr [ESP + 0x2c],CL
    m.w8((f.sp+0x0000002cu), (s.cx & 0xffu));
  }
  L00428a0e: { // 0x428a0e: 743c JZ 0x00428a4c
    if(integer::condition("JZ",flags)) goto L00428a4c;
  }
  L00428a10: { // 0x428a10: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L00428a16: { // 0x428a16: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00428a18: { // 0x428a18: 750a JNZ 0x00428a24
    if(integer::condition("JNZ",flags)) goto L00428a24;
  }
  L00428a1a: { // 0x428a1a: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  L00428a1f: { // 0x428a1f: e84c883500 CALL 0x00781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,4360740u); flags=s.arithmetic_flags;
  }
  L00428a24: { // 0x428a24: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L00428a28: { // 0x428a28: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L00428a2e: { // 0x428a2e: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00428a31: { // 0x428a31: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00428a33: { // 0x428a33: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  L00428a35: { // 0x428a35: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00428a36: { // 0x428a36: 8929 MOV dword ptr [ECX],EBP
    m.w32((s.cx), s.bp);
  }
  L00428a38: { // 0x428a38: 8b6c2430 MOV EBP,dword ptr [ESP + 0x30]
    s.bp = m.r32((f.sp+0x00000030u));
  }
  L00428a3c: { // 0x428a3c: 896904 MOV dword ptr [ECX + 0x4],EBP
    m.w32((s.cx+0x00000004u), s.bp);
  }
  L00428a3f: { // 0x428a3f: 897908 MOV dword ptr [ECX + 0x8],EDI
    m.w32((s.cx+0x00000008u), s.di);
  }
  L00428a42: { // 0x428a42: ff92a0000000 CALL dword ptr [EDX + 0xa0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000a0u)),4360776u); flags=s.arithmetic_flags;
  }
  L00428a48: { // 0x428a48: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00428a4a: { // 0x428a4a: 7537 JNZ 0x00428a83
    if(integer::condition("JNZ",flags)) goto L00428a83;
  }
  L00428a4c: { // 0x428a4c: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L00428a4f: { // 0x428a4f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00428a51: { // 0x428a51: 75ae JNZ 0x00428a01
    if(integer::condition("JNZ",flags)) goto L00428a01;
  }
  L00428a53: { // 0x428a53: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L00428a57: { // 0x428a57: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00428a58: { // 0x428a58: 83fd03 CMP EBP,0x3
    (void)integer::sub(s.bp,0x00000003u,32,flags);
  }
  L00428a5b: { // 0x428a5b: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L00428a5f: { // 0x428a5f: 0f8c38ffffff JL 0x0042899d
    if(integer::condition("JL",flags)) goto L0042899d;
  }
  L00428a65: { // 0x428a65: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00428a69: { // 0x428a69: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00428a6a: { // 0x428a6a: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  L00428a6d: { // 0x428a6d: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00428a71: { // 0x428a71: 0f8c1dffffff JL 0x00428994
    if(integer::condition("JL",flags)) goto L00428994;
  }
  L00428a77: { // 0x428a77: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00428a79: { // 0x428a79: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00428a7a: { // 0x428a7a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00428a7b: { // 0x428a7b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00428a7c: { // 0x428a7c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00428a7d: { // 0x428a7d: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00428a80: { // 0x428a80: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00428a83: { // 0x428a83: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00428a85: { // 0x428a85: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00428a86: { // 0x428a86: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00428a87: { // 0x428a87: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00428a88: { // 0x428a88: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00428a89: { // 0x428a89: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00428a8c: { // 0x428a8c: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
