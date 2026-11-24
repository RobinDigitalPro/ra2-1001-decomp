#include "recovered/recovery_b598_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b598 {
namespace {
void f_002b6970(Memory&,State&,Frame&,const Operations&);
void f_000f47b0(Memory&,State&,Frame&,const Operations&);
void f_0001b580(Memory&,State&,Frame&,const Operations&);
void f_0001b600(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002b6970(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6970: { // 0x6b6970: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b6971: { // 0x6b6971: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006b6973: { // 0x6b6973: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L006b6976: { // 0x6b6976: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b6978: { // 0x6b6978: 7e4b JLE 0x006b69c5
    if(integer::condition("JLE",flags)) goto L006b69c5;
  }
  L006b697a: { // 0x6b697a: 8a4676 MOV AL,byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L006b697d: { // 0x6b697d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b697f: { // 0x6b697f: 7544 JNZ 0x006b69c5
    if(integer::condition("JNZ",flags)) goto L006b69c5;
  }
  L006b6981: { // 0x6b6981: 8a862d030000 MOV AL,byte ptr [ESI + 0x32d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000032du)));
  }
  L006b6987: { // 0x6b6987: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6989: { // 0x6b6989: 743a JZ 0x006b69c5
    if(integer::condition("JZ",flags)) goto L006b69c5;
  }
  L006b698b: { // 0x6b698b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b698d: { // 0x6b698d: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),7039376u); flags=s.arithmetic_flags;
  }
  L006b6990: { // 0x6b6990: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L006b6993: { // 0x6b6993: 7430 JZ 0x006b69c5
    if(integer::condition("JZ",flags)) goto L006b69c5;
  }
  L006b6995: { // 0x6b6995: 8a8673030000 MOV AL,byte ptr [ESI + 0x373]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000373u)));
  }
  L006b699b: { // 0x6b699b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b699d: { // 0x6b699d: 7426 JZ 0x006b69c5
    if(integer::condition("JZ",flags)) goto L006b69c5;
  }
  L006b699f: { // 0x6b699f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b69a1: { // 0x6b69a1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b69a3: { // 0x6b69a3: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7039401u); flags=s.arithmetic_flags;
  }
  L006b69a9: { // 0x6b69a9: 8a8800020000 MOV CL,byte ptr [EAX + 0x200]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000200u)));
  }
  L006b69af: { // 0x6b69af: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006b69b1: { // 0x6b69b1: 7412 JZ 0x006b69c5
    if(integer::condition("JZ",flags)) goto L006b69c5;
  }
  L006b69b3: { // 0x6b69b3: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006b69b9: { // 0x6b69b9: e8f2dde3ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,7039422u); flags=s.arithmetic_flags;
  }
  L006b69be: { // 0x6b69be: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b69c0: { // 0x6b69c0: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L006b69c3: { // 0x6b69c3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b69c4: { // 0x6b69c4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006b69c5: { // 0x6b69c5: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006b69c7: { // 0x6b69c7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b69c8: { // 0x6b69c8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000f47b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f47b0: { // 0x4f47b0: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004f47b5: { // 0x4f47b5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f47b7: { // 0x4f47b7: 751d JNZ 0x004f47d6
    if(integer::condition("JNZ",flags)) goto L004f47d6;
  }
  L004f47b9: { // 0x4f47b9: 8a8134010000 MOV AL,byte ptr [ECX + 0x134]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000134u)));
  }
  L004f47bf: { // 0x4f47bf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f47c1: { // 0x4f47c1: 750d JNZ 0x004f47d0
    if(integer::condition("JNZ",flags)) goto L004f47d0;
  }
  L004f47c3: { // 0x4f47c3: 8a8135010000 MOV AL,byte ptr [ECX + 0x135]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000135u)));
  }
  L004f47c9: { // 0x4f47c9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f47cb: { // 0x4f47cb: 7503 JNZ 0x004f47d0
    if(integer::condition("JNZ",flags)) goto L004f47d0;
  }
  L004f47cd: { // 0x4f47cd: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f47cf: { // 0x4f47cf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004f47d0: { // 0x4f47d0: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L004f47d5: { // 0x4f47d5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004f47d6: { // 0x4f47d6: 8b15e4e0a100 MOV EDX,dword ptr [0x00a1e0e4]
    s.dx = m.r32((0x00a1e0e4u));
  }
  L004f47dc: { // 0x4f47dc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f47de: { // 0x4f47de: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004f47e0: { // 0x4f47e0: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004f47e3: { // 0x4f47e3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0001b580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b580: { // 0x41b580: b802000000 MOV EAX, 2
    s.ax = 2u;
  }
  L0041b585: { // 0x41b585: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0001b600(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b600: { // 0x41b600: 8b81ac050000 MOV EAX, dword ptr [ECX + 0x5ac]
    s.ax = m.r32((s.cx+0x000005acu));
  }
  L0041b606: { // 0x41b606: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
 // RVA2B6910: MOV EAX,[ECX]; JMP [EAX+84], preserving the current return frame.
 s.ax=m.r32(s.cx);
 if(m.r32(s.ax+0x84)!=0x41b600)throw std::runtime_error("598unprovedtailtarget");
 f_0001b600(m,s,f,op);
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7039344u:f_002b6970(m,s,child,{});break;
case 5195696u:f_000f47b0(m,s,child,{});break;
case 4306304u:f_0001b580(m,s,child,{});break;
case 4306432u:f_0001b600(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
default:throw std::domain_error("recovery598 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0049a3b0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049a3b0: { // 0x49a3b0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049a3b1: { // 0x49a3b1: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0049a3b5: { // 0x49a3b5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049a3b6: { // 0x49a3b6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049a3b7: { // 0x49a3b7: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L0049a3b9: { // 0x49a3b9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049a3ba: { // 0x49a3ba: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049a3bb: { // 0x49a3bb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049a3bd: { // 0x49a3bd: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L0049a3c5: { // 0x49a3c5: 7502 JNZ 0x0049a3c9
    if(integer::condition("JNZ",flags)) goto L0049a3c9;
  }
  L0049a3c7: { // 0x49a3c7: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L0049a3c9: { // 0x49a3c9: bd0c0e7c00 MOV EBP,0x7c0e0c
    s.bp = 0x007c0e0cu;
  }
  L0049a3ce: { // 0x49a3ce: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L0049a3d1: { // 0x49a3d1: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0049a3d3: { // 0x49a3d3: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0049a3d6: { // 0x49a3d6: c1e003 SHL EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::left);
  }
  L0049a3d9: { // 0x49a3d9: 8b88b8a88300 MOV ECX,dword ptr [EAX + 0x83a8b8]
    s.cx = m.r32((s.ax+0x0083a8b8u));
  }
  L0049a3df: { // 0x49a3df: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049a3e1: { // 0x49a3e1: 7e42 JLE 0x0049a425
    if(integer::condition("JLE",flags)) goto L0049a425;
  }
  L0049a3e3: { // 0x49a3e3: 8b80aca88300 MOV EAX,dword ptr [EAX + 0x83a8ac]
    s.ax = m.r32((s.ax+0x0083a8acu));
  }
  L0049a3e9: { // 0x49a3e9: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L0049a3ec: { // 0x49a3ec: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0049a3ee: { // 0x49a3ee: 7423 JZ 0x0049a413
    if(integer::condition("JZ",flags)) goto L0049a413;
  }
  L0049a3f0: { // 0x49a3f0: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0049a3f2: { // 0x49a3f2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049a3f4: { // 0x49a3f4: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),4826103u); flags=s.arithmetic_flags;
  }
  L0049a3f7: { // 0x49a3f7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049a3f9: { // 0x49a3f9: 7418 JZ 0x0049a413
    if(integer::condition("JZ",flags)) goto L0049a413;
  }
  L0049a3fb: { // 0x49a3fb: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0049a3ff: { // 0x49a3ff: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049a401: { // 0x49a401: 7504 JNZ 0x0049a407
    if(integer::condition("JNZ",flags)) goto L0049a407;
  }
  L0049a403: { // 0x49a403: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L0049a407: { // 0x49a407: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0049a409: { // 0x49a409: 7531 JNZ 0x0049a43c
    if(integer::condition("JNZ",flags)) goto L0049a43c;
  }
  L0049a40b: { // 0x49a40b: 39742418 CMP dword ptr [ESP + 0x18],ESI
    (void)integer::sub(m.r32((f.sp+0x00000018u)),s.si,32,flags);
  }
  L0049a40f: { // 0x49a40f: 7502 JNZ 0x0049a413
    if(integer::condition("JNZ",flags)) goto L0049a413;
  }
  L0049a411: { // 0x49a411: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L0049a413: { // 0x49a413: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L0049a416: { // 0x49a416: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0049a417: { // 0x49a417: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0049a41a: { // 0x49a41a: c1e003 SHL EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::left);
  }
  L0049a41d: { // 0x49a41d: 3bb8b8a88300 CMP EDI,dword ptr [EAX + 0x83a8b8]
    (void)integer::sub(s.di,m.r32((s.ax+0x0083a8b8u)),32,flags);
  }
  L0049a423: { // 0x49a423: 7cbe JL 0x0049a3e3
    if(integer::condition("JL",flags)) goto L0049a3e3;
  }
  L0049a425: { // 0x49a425: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L0049a428: { // 0x49a428: 81fd180e7c00 CMP EBP,0x7c0e18
    (void)integer::sub(s.bp,0x007c0e18u,32,flags);
  }
  L0049a42e: { // 0x49a42e: 7c9e JL 0x0049a3ce
    if(integer::condition("JL",flags)) goto L0049a3ce;
  }
  L0049a430: { // 0x49a430: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0049a434: { // 0x49a434: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049a435: { // 0x49a435: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049a436: { // 0x49a436: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049a437: { // 0x49a437: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049a438: { // 0x49a438: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0049a439: { // 0x49a439: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0049a43c: { // 0x49a43c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0049a43e: { // 0x49a43e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049a43f: { // 0x49a43f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049a440: { // 0x49a440: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049a441: { // 0x49a441: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049a442: { // 0x49a442: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0049a443: { // 0x49a443: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
