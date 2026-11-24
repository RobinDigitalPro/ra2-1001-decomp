#include "recovered/recovery_b581_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b581 {
namespace {
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_000713b0(Memory&,State&,Frame&,const Operations&);
void f_0001b320(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
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
void f_000713b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004713b0: { // 0x004713b0: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L004713b5: { // 0x004713b5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004713b6: { // 0x004713b6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004713b8: { // 0x004713b8: 741d JZ 0x004713d7
    if(integer::condition("JZ",flags)) goto L004713d7;
  }
  L004713ba: { // 0x004713ba: 8bb1e4000000 MOV ESI,dword ptr [ECX + 0xe4]
    s.si = m.r32((s.cx+0x000000e4u));
  }
  L004713c0: { // 0x004713c0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004713c2: { // 0x004713c2: 7413 JZ 0x004713d7
    if(integer::condition("JZ",flags)) goto L004713d7;
  }
  L004713c4: { // 0x004713c4: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004713c6: { // 0x004713c6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004713c8: { // 0x004713c8: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4658123u); flags=s.arithmetic_flags;
  }
  L004713cb: { // 0x004713cb: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L004713ce: { // 0x004713ce: 740b JZ 0x004713db
    if(integer::condition("JZ",flags)) goto L004713db;
  }
  L004713d0: { // 0x004713d0: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L004713d3: { // 0x004713d3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004713d5: { // 0x004713d5: 75ed JNZ 0x004713c4
    if(integer::condition("JNZ",flags)) goto L004713c4;
  }
  L004713d7: { // 0x004713d7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004713d9: { // 0x004713d9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004713da: { // 0x004713da: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004713db: { // 0x004713db: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004713dd: { // 0x004713dd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004713de: { // 0x004713de: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0001b320(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b320: { // 0x41b320: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0041b321: { // 0x41b321: 8b8188000000 MOV EAX,dword ptr [ECX + 0x88]
    s.ax = m.r32((s.cx+0x00000088u));
  }
  L0041b327: { // 0x41b327: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041b328: { // 0x41b328: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041b32e: { // 0x41b32e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041b330: { // 0x41b330: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041b333: { // 0x41b333: 6689442400 MOV word ptr [ESP],AX
    m.w16((f.sp), (s.ax & 0xffffu));
  }
  L0041b338: { // 0x41b338: 8b818c000000 MOV EAX,dword ptr [ECX + 0x8c]
    s.ax = m.r32((s.cx+0x0000008cu));
  }
  L0041b33e: { // 0x41b33e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041b33f: { // 0x41b33f: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041b345: { // 0x41b345: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041b347: { // 0x41b347: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041b34a: { // 0x41b34a: 6689442402 MOV word ptr [ESP + 0x2],AX
    m.w16((f.sp+0x00000002u), (s.ax & 0xffffu));
  }
  L0041b34f: { // 0x41b34f: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0041b353: { // 0x41b353: 8b4c2400 MOV ECX,dword ptr [ESP]
    s.cx = m.r32((f.sp));
  }
  L0041b357: { // 0x41b357: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0041b359: { // 0x41b359: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0041b35a: { // 0x41b35a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
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
case 5526784u:f_00145500(m,s,child,{});break;
case 4658096u:f_000713b0(m,s,child,{});break;
case 4305696u:f_0001b320(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
default:throw std::domain_error("recovery581 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0042c0a0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042c0a0: { // 0x42c0a0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0042c0a3: { // 0x42c0a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042c0a4: { // 0x42c0a4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0042c0a5: { // 0x42c0a5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042c0a6: { // 0x42c0a6: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    s.si = m.r32((f.sp+0x00000028u));
  }
  L0042c0aa: { // 0x42c0aa: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042c0ab: { // 0x42c0ab: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0042c0ad: { // 0x42c0ad: c1e604 SHL ESI,0x4
    s.si = integer::shift(s.si,0x00000004u,32,flags,integer::Shift::left);
  }
  L0042c0b0: { // 0x42c0b0: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L0042c0b3: { // 0x42c0b3: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0042c0b5: { // 0x42c0b5: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L0042c0b8: { // 0x42c0b8: 6685c9 TEST CX,CX
    (void)integer::logical(((s.cx & 0xffffu))&((s.cx & 0xffffu)),16,flags);
  }
  L0042c0bb: { // 0x42c0bb: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0042c0bf: { // 0x42c0bf: 750b JNZ 0x0042c0cc
    if(integer::condition("JNZ",flags)) goto L0042c0cc;
  }
  L0042c0c1: { // 0x42c0c1: 66394c2416 CMP word ptr [ESP + 0x16],CX
    (void)integer::sub(m.r16((f.sp+0x00000016u)),(s.cx & 0xffffu),16,flags);
  }
  L0042c0c6: { // 0x42c0c6: 0f8438010000 JZ 0x0042c204
    if(integer::condition("JZ",flags)) goto L0042c204;
  }
  L0042c0cc: { // 0x42c0cc: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0042c0ce: { // 0x42c0ce: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042c0d0: { // 0x42c0d0: 0f8c2e010000 JL 0x0042c204
    if(integer::condition("JL",flags)) goto L0042c204;
  }
  L0042c0d6: { // 0x42c0d6: 8b0d0ce0a100 MOV ECX,dword ptr [0x00a1e00c]
    s.cx = m.r32((0x00a1e00cu));
  }
  L0042c0dc: { // 0x42c0dc: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0042c0e0: { // 0x42c0e0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0042c0e1: { // 0x42c0e1: 8b2c81 MOV EBP,dword ptr [ECX + EAX*0x4]
    s.bp = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0042c0e4: { // 0x42c0e4: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0042c0e9: { // 0x42c0e9: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L0042c0ed: { // 0x42c0ed: e80e941100 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4374770u); flags=s.arithmetic_flags;
  }
  L0042c0f2: { // 0x42c0f2: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0042c0f4: { // 0x42c0f4: e8b7520400 CALL 0x004713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,4374777u); flags=s.arithmetic_flags;
  }
  L0042c0f9: { // 0x42c0f9: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0042c0fb: { // 0x42c0fb: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0042c0fd: { // 0x42c0fd: 0f8401010000 JZ 0x0042c204
    if(integer::condition("JZ",flags)) goto L0042c204;
  }
  L0042c103: { // 0x42c103: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L0042c106: { // 0x42c106: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0042c108: { // 0x42c108: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0042c10a: { // 0x42c10a: 8d740604 LEA ESI,[ESI + EAX*0x1 + 0x4]
    s.si = (s.si+(s.ax * 0x00000001u)+0x00000004u);
  }
  L0042c10e: { // 0x42c10e: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0042c112: { // 0x42c112: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042c113: { // 0x42c113: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),4374809u); flags=s.arithmetic_flags;
  }
  L0042c119: { // 0x42c119: 668b08 MOV CX,word ptr [EAX]
    s.cx = with_ax(s.cx, m.r16((s.ax)));
  }
  L0042c11c: { // 0x42c11c: 663b0e CMP CX,word ptr [ESI]
    (void)integer::sub((s.cx & 0xffffu),m.r16((s.si)),16,flags);
  }
  L0042c11f: { // 0x42c11f: 0f85df000000 JNZ 0x0042c204
    if(integer::condition("JNZ",flags)) goto L0042c204;
  }
  L0042c125: { // 0x42c125: 668b5002 MOV DX,word ptr [EAX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x00000002u)));
  }
  L0042c129: { // 0x42c129: 663b5602 CMP DX,word ptr [ESI + 0x2]
    (void)integer::sub((s.dx & 0xffffu),m.r16((s.si+0x00000002u)),16,flags);
  }
  L0042c12d: { // 0x42c12d: 0f85d1000000 JNZ 0x0042c204
    if(integer::condition("JNZ",flags)) goto L0042c204;
  }
  L0042c133: { // 0x42c133: 8b83b4010000 MOV EAX,dword ptr [EBX + 0x1b4]
    s.ax = m.r32((s.bx+0x000001b4u));
  }
  L0042c139: { // 0x42c139: 8b4f74 MOV ECX,dword ptr [EDI + 0x74]
    s.cx = m.r32((s.di+0x00000074u));
  }
  L0042c13c: { // 0x42c13c: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0042c13e: { // 0x42c13e: 0f85c0000000 JNZ 0x0042c204
    if(integer::condition("JNZ",flags)) goto L0042c204;
  }
  L0042c144: { // 0x42c144: 39ab18040000 CMP dword ptr [EBX + 0x418],EBP
    (void)integer::sub(m.r32((s.bx+0x00000418u)),s.bp,32,flags);
  }
  L0042c14a: { // 0x42c14a: 750c JNZ 0x0042c158
    if(integer::condition("JNZ",flags)) goto L0042c158;
  }
  L0042c14c: { // 0x42c14c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042c14d: { // 0x42c14d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042c14e: { // 0x42c14e: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0042c150: { // 0x42c150: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042c151: { // 0x42c151: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042c152: { // 0x42c152: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0042c155: { // 0x42c155: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0042c158: { // 0x42c158: 8a85200c0000 MOV AL,byte ptr [EBP + 0xc20]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000c20u)));
  }
  L0042c15e: { // 0x42c15e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042c160: { // 0x42c160: 0f849e000000 JZ 0x0042c204
    if(integer::condition("JZ",flags)) goto L0042c204;
  }
  L0042c166: { // 0x42c166: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0042c168: { // 0x42c168: 8d83c0040000 LEA EAX,[EBX + 0x4c0]
    s.ax = (s.bx+0x000004c0u);
  }
  L0042c16e: { // 0x42c16e: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0042c172: { // 0x42c172: b903000000 MOV ECX,0x3
    s.cx = 0x00000003u;
  }
  L0042c177: { // 0x42c177: 3928 CMP dword ptr [EAX],EBP
    (void)integer::sub(m.r32((s.ax)),s.bp,32,flags);
  }
  L0042c179: { // 0x42c179: 7501 JNZ 0x0042c17c
    if(integer::condition("JNZ",flags)) goto L0042c17c;
  }
  L0042c17b: { // 0x42c17b: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0042c17c: { // 0x42c17c: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L0042c17f: { // 0x42c17f: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0042c180: { // 0x42c180: 75f5 JNZ 0x0042c177
    if(integer::condition("JNZ",flags)) goto L0042c177;
  }
  L0042c182: { // 0x42c182: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0042c186: { // 0x42c186: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0042c18a: { // 0x42c18a: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0042c18c: { // 0x42c18c: 7e62 JLE 0x0042c1f0
    if(integer::condition("JLE",flags)) goto L0042c1f0;
  }
  L0042c18e: { // 0x42c18e: 8b7708 MOV ESI,dword ptr [EDI + 0x8]
    s.si = m.r32((s.di+0x00000008u));
  }
  L0042c191: { // 0x42c191: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0042c193: { // 0x42c193: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042c195: { // 0x42c195: 7c4f JL 0x0042c1e6
    if(integer::condition("JL",flags)) goto L0042c1e6;
  }
  L0042c197: { // 0x42c197: 8b150ce0a100 MOV EDX,dword ptr [0x00a1e00c]
    s.dx = m.r32((0x00a1e00cu));
  }
  L0042c19d: { // 0x42c19d: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0042c1a1: { // 0x42c1a1: 390c82 CMP dword ptr [EDX + EAX*0x4],ECX
    (void)integer::sub(m.r32((s.dx+(s.ax * 0x00000004u))),s.cx,32,flags);
  }
  L0042c1a4: { // 0x42c1a4: 7540 JNZ 0x0042c1e6
    if(integer::condition("JNZ",flags)) goto L0042c1e6;
  }
  L0042c1a6: { // 0x42c1a6: 8d8388000000 LEA EAX,[EBX + 0x88]
    s.ax = (s.bx+0x00000088u);
  }
  L0042c1ac: { // 0x42c1ac: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0042c1ae: { // 0x42c1ae: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0042c1b0: { // 0x42c1b0: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L0042c1b3: { // 0x42c1b3: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L0042c1b6: { // 0x42c1b6: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0042c1ba: { // 0x42c1ba: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042c1bb: { // 0x42c1bb: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0042c1c1: { // 0x42c1c1: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0042c1c3: { // 0x42c1c3: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0042c1c5: { // 0x42c1c5: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0042c1c7: { // 0x42c1c7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0042c1c8: { // 0x42c1c8: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0042c1ce: { // 0x42c1ce: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0042c1d0: { // 0x42c1d0: c1f908 SAR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0042c1d3: { // 0x42c1d3: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0042c1d6: { // 0x42c1d6: 66394e04 CMP word ptr [ESI + 0x4],CX
    (void)integer::sub(m.r16((s.si+0x00000004u)),(s.cx & 0xffffu),16,flags);
  }
  L0042c1da: { // 0x42c1da: 750a JNZ 0x0042c1e6
    if(integer::condition("JNZ",flags)) goto L0042c1e6;
  }
  L0042c1dc: { // 0x42c1dc: 66394606 CMP word ptr [ESI + 0x6],AX
    (void)integer::sub(m.r16((s.si+0x00000006u)),(s.ax & 0xffffu),16,flags);
  }
  L0042c1e0: { // 0x42c1e0: 7504 JNZ 0x0042c1e6
    if(integer::condition("JNZ",flags)) goto L0042c1e6;
  }
  L0042c1e2: { // 0x42c1e2: ff4c2410 DEC dword ptr [ESP + 0x10]
    m.w32((f.sp+0x00000010u), integer::decrement(m.r32((f.sp+0x00000010u)),32,flags));
  }
  L0042c1e6: { // 0x42c1e6: 83c610 ADD ESI,0x10
    s.si = integer::add(s.si,0x00000010u,32,flags);
  }
  L0042c1e9: { // 0x42c1e9: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L0042c1ea: { // 0x42c1ea: 75a5 JNZ 0x0042c191
    if(integer::condition("JNZ",flags)) goto L0042c191;
  }
  L0042c1ec: { // 0x42c1ec: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0042c1f0: { // 0x42c1f0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0042c1f2: { // 0x42c1f2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042c1f3: { // 0x42c1f3: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0042c1f5: { // 0x42c1f5: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  L0042c1f8: { // 0x42c1f8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0042c1f9: { // 0x42c1f9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042c1fa: { // 0x42c1fa: 23c3 AND EAX,EBX
    s.ax = integer::logical((s.ax)&(s.bx),32,flags);
  }
  L0042c1fc: { // 0x42c1fc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042c1fd: { // 0x42c1fd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042c1fe: { // 0x42c1fe: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0042c201: { // 0x42c201: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0042c204: { // 0x42c204: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042c205: { // 0x42c205: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042c206: { // 0x42c206: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042c207: { // 0x42c207: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0042c209: { // 0x42c209: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042c20a: { // 0x42c20a: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0042c20d: { // 0x42c20d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
