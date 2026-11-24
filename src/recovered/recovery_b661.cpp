#include "recovered/recovery_b661_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b661 {
namespace {
void f_0001b320(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_00058540(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

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
void f_00058540(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00458540: { // 0x458540: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00458541: { // 0x458541: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00458542: { // 0x458542: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00458544: { // 0x458544: 8a0df0708300 MOV CL, byte ptr [0x8370f0]
    s.cx = with_al(s.cx, m.r8((0x008370f0u)));
  }
  L0045854a: { // 0x45854a: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0045854c: { // 0x45854c: 84c8 TEST AL, CL
    (void)integer::logical(((s.ax & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0045854e: { // 0x45854e: 752f JNZ 0x45857f
    if(integer::condition("JNZ",flags)) goto L0045857f;
  }
  L00458550: { // 0x458550: 8ad1 MOV DL, CL
    s.dx = with_al(s.dx, (s.cx & 0xffu));
  }
  L00458552: { // 0x458552: 68a0854500 PUSH 0x4585a0
    f.push(m,0x004585a0u);
  }
  L00458557: { // 0x458557: 0ad0 OR DL, AL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))|((s.ax & 0xffu)),8,flags));
  }
  L00458559: { // 0x458559: b8ff7f0000 MOV EAX, 0x7fff
    s.ax = 0x00007fffu;
  }
  L0045855e: { // 0x45855e: 6689442408 MOV word ptr [ESP + 8], AX
    m.w16((f.sp+8u), (s.ax & 0xffffu));
  }
  L00458563: { // 0x458563: 668944240a MOV word ptr [ESP + 0xa], AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  L00458568: { // 0x458568: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L0045856c: { // 0x45856c: 8815f0708300 MOV byte ptr [0x8370f0], DL
    m.w8((0x008370f0u), (s.dx & 0xffu));
  }
  L00458572: { // 0x458572: a318718300 MOV dword ptr [0x837118], EAX
    m.w32((0x00837118u), s.ax);
  }
  L00458577: { // 0x458577: e84e5d3100 CALL 0x76e2ca
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076e2cau,4556156u); flags=s.arithmetic_flags;
  }
  L0045857c: { // 0x45857c: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L0045857f: { // 0x45857f: 8b86940b0000 MOV EAX, dword ptr [ESI + 0xb94]
    s.ax = m.r32((s.si+0x00000b94u));
  }
  L00458585: { // 0x458585: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00458586: { // 0x458586: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00458588: { // 0x458588: 7505 JNZ 0x45858f
    if(integer::condition("JNZ",flags)) goto L0045858f;
  }
  L0045858a: { // 0x45858a: b818718300 MOV EAX, 0x837118
    s.ax = 0x00837118u;
  }
  L0045858f: { // 0x45858f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00458590: { // 0x458590: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4305696u:f_0001b320(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4556096u:f_00058540(m,s,child,{});break;
default:throw std::domain_error("recovery661 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00452850(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00452850: { // 0x452850: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00452853: { // 0x452853: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00452854: { // 0x452854: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00452855: { // 0x452855: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00452857: { // 0x452857: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00452858: { // 0x452858: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0045285c: { // 0x45285c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0045285e: { // 0x45285e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0045285f: { // 0x45285f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00452861: { // 0x452861: ff90a0010000 CALL dword ptr [EAX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a0u)),4532327u); flags=s.arithmetic_flags;
  }
  L00452867: { // 0x452867: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0045286d: { // 0x45286d: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L0045286f: { // 0x45286f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00452871: { // 0x452871: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L00452875: { // 0x452875: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00452877: { // 0x452877: ff9290000000 CALL dword ptr [EDX + 0x90]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000090u)),4532349u); flags=s.arithmetic_flags;
  }
  L0045287d: { // 0x45287d: 668b5c240e MOV BX,word ptr [ESP + 0xe]
    s.bx = with_ax(s.bx, m.r16((f.sp+0x0000000eu)));
  }
  L00452882: { // 0x452882: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00452884: { // 0x452884: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L00452887: { // 0x452887: 663dff7f CMP AX,0x7fff
    (void)integer::sub((s.ax & 0xffffu),0x00007fffu,16,flags);
  }
  L0045288b: { // 0x45288b: 7506 JNZ 0x00452893
    if(integer::condition("JNZ",flags)) goto L00452893;
  }
  L0045288d: { // 0x45288d: 66394602 CMP word ptr [ESI + 0x2],AX
    (void)integer::sub(m.r16((s.si+0x00000002u)),(s.ax & 0xffffu),16,flags);
  }
  L00452891: { // 0x452891: 7444 JZ 0x004528d7
    if(integer::condition("JZ",flags)) goto L004528d7;
  }
  L00452893: { // 0x452893: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00452895: { // 0x452895: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L00452899: { // 0x452899: 668944240c MOV word ptr [ESP + 0xc],AX
    m.w16((f.sp+0x0000000cu), (s.ax & 0xffffu));
  }
  L0045289e: { // 0x45289e: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L004528a2: { // 0x4528a2: 6603c3 ADD AX,BX
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L004528a5: { // 0x4528a5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004528a6: { // 0x4528a6: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L004528ab: { // 0x4528ab: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L004528af: { // 0x4528af: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L004528b3: { // 0x4528b3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004528b8: { // 0x4528b8: e8432c0f00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4532413u); flags=s.arithmetic_flags;
  }
  L004528bd: { // 0x4528bd: f7804001000000004000 TEST dword ptr [EAX + 0x140],0x400000
    (void)integer::logical((m.r32((s.ax+0x00000140u)))&(0x00400000u),32,flags);
  }
  L004528c7: { // 0x4528c7: 7405 JZ 0x004528ce
    if(integer::condition("JZ",flags)) goto L004528ce;
  }
  L004528c9: { // 0x4528c9: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L004528cc: { // 0x4528cc: ebb6 JMP 0x00452884
    goto L00452884;
  }
  L004528ce: { // 0x4528ce: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004528cf: { // 0x4528cf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004528d0: { // 0x4528d0: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004528d2: { // 0x4528d2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004528d3: { // 0x4528d3: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004528d6: { // 0x4528d6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004528d7: { // 0x4528d7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004528d8: { // 0x4528d8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004528d9: { // 0x4528d9: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004528db: { // 0x4528db: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004528dc: { // 0x4528dc: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004528df: { // 0x4528df: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
