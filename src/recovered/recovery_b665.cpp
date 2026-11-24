#include "recovered/recovery_b665_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b665 {
namespace {
void f_0000ff90(Memory&,State&,Frame&,const Operations&);
void f_000d56d0(Memory&,State&,Frame&,const Operations&);
void f_000cde40(Memory&,State&,Frame&,const Operations&);
void f_000547a0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0000ff90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ff90: { // 0x40ff90: c701d85d7800 MOV dword ptr [ECX], 0x785dd8
    m.w32((s.cx), 0x00785dd8u);
  }
  L0040ff96: { // 0x40ff96: c74104bc5d7800 MOV dword ptr [ECX + 4], 0x785dbc
    m.w32((s.cx+4u), 0x00785dbcu);
  }
  L0040ff9d: { // 0x40ff9d: c74108b45d7800 MOV dword ptr [ECX + 8], 0x785db4
    m.w32((s.cx+8u), 0x00785db4u);
  }
  L0040ffa4: { // 0x40ffa4: c7410cac5d7800 MOV dword ptr [ECX + 0xc], 0x785dac
    m.w32((s.cx+0x0000000cu), 0x00785dacu);
  }
  L0040ffab: { // 0x40ffab: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000d56d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004d56d0: { // 0x4d56d0: 8b5110 MOV EDX, dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L004d56d3: { // 0x4d56d3: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004d56d5: { // 0x4d56d5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004d56d6: { // 0x4d56d6: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004d56d8: { // 0x4d56d8: 7e15 JLE 0x4d56ef
    if(integer::condition("JLE",flags)) goto L004d56ef;
  }
  L004d56da: { // 0x4d56da: 8b742408 MOV ESI, dword ptr [ESP + 8]
    s.si = m.r32((f.sp+8u));
  }
  L004d56de: { // 0x4d56de: 8b4904 MOV ECX, dword ptr [ECX + 4]
    s.cx = m.r32((s.cx+4u));
  }
  L004d56e1: { // 0x4d56e1: 8b36 MOV ESI, dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L004d56e3: { // 0x4d56e3: 3931 CMP dword ptr [ECX], ESI
    (void)integer::sub(m.r32((s.cx)),s.si,32,flags);
  }
  L004d56e5: { // 0x4d56e5: 740b JZ 0x4d56f2
    if(integer::condition("JZ",flags)) goto L004d56f2;
  }
  L004d56e7: { // 0x4d56e7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004d56e8: { // 0x4d56e8: 83c104 ADD ECX, 4
    s.cx = integer::add(s.cx,4u,32,flags);
  }
  L004d56eb: { // 0x4d56eb: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004d56ed: { // 0x4d56ed: 7cf4 JL 0x4d56e3
    if(integer::condition("JL",flags)) goto L004d56e3;
  }
  L004d56ef: { // 0x4d56ef: 83c8ff OR EAX, 0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L004d56f2: { // 0x4d56f2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004d56f3: { // 0x4d56f3: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000cde40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004cde40: { // 0x4cde40: 8b5110 MOV EDX, dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L004cde43: { // 0x4cde43: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004cde45: { // 0x4cde45: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004cde46: { // 0x4cde46: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004cde48: { // 0x4cde48: 7e15 JLE 0x4cde5f
    if(integer::condition("JLE",flags)) goto L004cde5f;
  }
  L004cde4a: { // 0x4cde4a: 8b742408 MOV ESI, dword ptr [ESP + 8]
    s.si = m.r32((f.sp+8u));
  }
  L004cde4e: { // 0x4cde4e: 8b4904 MOV ECX, dword ptr [ECX + 4]
    s.cx = m.r32((s.cx+4u));
  }
  L004cde51: { // 0x4cde51: 8b36 MOV ESI, dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L004cde53: { // 0x4cde53: 3931 CMP dword ptr [ECX], ESI
    (void)integer::sub(m.r32((s.cx)),s.si,32,flags);
  }
  L004cde55: { // 0x4cde55: 740b JZ 0x4cde62
    if(integer::condition("JZ",flags)) goto L004cde62;
  }
  L004cde57: { // 0x4cde57: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004cde58: { // 0x4cde58: 83c104 ADD ECX, 4
    s.cx = integer::add(s.cx,4u,32,flags);
  }
  L004cde5b: { // 0x4cde5b: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004cde5d: { // 0x4cde5d: 7cf4 JL 0x4cde53
    if(integer::condition("JL",flags)) goto L004cde53;
  }
  L004cde5f: { // 0x4cde5f: 83c8ff OR EAX, 0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L004cde62: { // 0x4cde62: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004cde63: { // 0x4cde63: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000547a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004547a0: { // 0x4547a0: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L004547a3: { // 0x4547a3: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L004547a7: { // 0x4547a7: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004547a9: { // 0x4547a9: 7d21 JGE 0x004547cc
    if(integer::condition("JGE",flags)) goto L004547cc;
  }
  L004547ab: { // 0x4547ab: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L004547ac: { // 0x4547ac: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004547ae: { // 0x4547ae: 895110 MOV dword ptr [ECX + 0x10],EDX
    m.w32((s.cx+0x00000010u), s.dx);
  }
  L004547b1: { // 0x4547b1: 7d14 JGE 0x004547c7
    if(integer::condition("JGE",flags)) goto L004547c7;
  }
  L004547b3: { // 0x4547b3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004547b4: { // 0x4547b4: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L004547b7: { // 0x4547b7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004547b8: { // 0x4547b8: 8b3482 MOV ESI,dword ptr [EDX + EAX*0x4]
    s.si = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L004547bb: { // 0x4547bb: 897482fc MOV dword ptr [EDX + EAX*0x4 + -0x4],ESI
    m.w32((s.dx+(s.ax * 0x00000004u)-0x00000004u), s.si);
  }
  L004547bf: { // 0x4547bf: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L004547c2: { // 0x4547c2: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004547c4: { // 0x4547c4: 7cee JL 0x004547b4
    if(integer::condition("JL",flags)) goto L004547b4;
  }
  L004547c6: { // 0x4547c6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004547c7: { // 0x4547c7: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004547c9: { // 0x4547c9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004547cc: { // 0x4547cc: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004547ce: { // 0x4547ce: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4259728u:f_0000ff90(m,s,child,{});break;
case 5068496u:f_000d56d0(m,s,child,{});break;
case 5037632u:f_000cde40(m,s,child,{});break;
case 4540320u:f_000547a0(m,s,child,{});break;
default:throw std::domain_error("recovery665 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00470a80(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00470a80: { // 0x470a80: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00470a81: { // 0x470a81: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00470a82: { // 0x470a82: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00470a84: { // 0x470a84: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00470a86: { // 0x470a86: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  L00470a89: { // 0x470a89: c706048b7800 MOV dword ptr [ESI],0x788b04
    m.w32((s.si), 0x00788b04u);
  }
  L00470a8f: { // 0x470a8f: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00470a91: { // 0x470a91: c74604e88a7800 MOV dword ptr [ESI + 0x4],0x788ae8
    m.w32((s.si+0x00000004u), 0x00788ae8u);
  }
  L00470a98: { // 0x470a98: c74608e08a7800 MOV dword ptr [ESI + 0x8],0x788ae0
    m.w32((s.si+0x00000008u), 0x00788ae0u);
  }
  L00470a9f: { // 0x470a9f: c7460cd88a7800 MOV dword ptr [ESI + 0xc],0x788ad8
    m.w32((s.si+0x0000000cu), 0x00788ad8u);
  }
  L00470aa6: { // 0x470aa6: 7409 JZ 0x00470ab1
    if(integer::condition("JZ",flags)) goto L00470ab1;
  }
  L00470aa8: { // 0x470aa8: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00470aaa: { // 0x470aaa: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00470aac: { // 0x470aac: ff10 CALL dword ptr [EAX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax)),4655790u); flags=s.arithmetic_flags;
  }
  L00470aae: { // 0x470aae: 895e28 MOV dword ptr [ESI + 0x28],EBX
    m.w32((s.si+0x00000028u), s.bx);
  }
  L00470ab1: { // 0x470ab1: 8b8efc000000 MOV ECX,dword ptr [ESI + 0xfc]
    s.cx = m.r32((s.si+0x000000fcu));
  }
  L00470ab7: { // 0x470ab7: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00470ab9: { // 0x470ab9: 740c JZ 0x00470ac7
    if(integer::condition("JZ",flags)) goto L00470ac7;
  }
  L00470abb: { // 0x470abb: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00470abd: { // 0x470abd: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00470abf: { // 0x470abf: ff12 CALL dword ptr [EDX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx)),4655809u); flags=s.arithmetic_flags;
  }
  L00470ac1: { // 0x470ac1: 899efc000000 MOV dword ptr [ESI + 0xfc],EBX
    m.w32((s.si+0x000000fcu), s.bx);
  }
  L00470ac7: { // 0x470ac7: 899ee4000000 MOV dword ptr [ESI + 0xe4],EBX
    m.w32((s.si+0x000000e4u), s.bx);
  }
  L00470acd: { // 0x470acd: 668b4624 MOV AX,word ptr [ESI + 0x24]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000024u)));
  }
  L00470ad1: { // 0x470ad1: 663b05188f8300 CMP AX,word ptr [0x00838f18]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x00838f18u)),16,flags);
  }
  L00470ad8: { // 0x470ad8: 750d JNZ 0x00470ae7
    if(integer::condition("JNZ",flags)) goto L00470ae7;
  }
  L00470ada: { // 0x470ada: 668b4e26 MOV CX,word ptr [ESI + 0x26]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000026u)));
  }
  L00470ade: { // 0x470ade: 663b0d1a8f8300 CMP CX,word ptr [0x00838f1a]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00838f1au)),16,flags);
  }
  L00470ae5: { // 0x470ae5: 7418 JZ 0x00470aff
    if(integer::condition("JZ",flags)) goto L00470aff;
  }
  L00470ae7: { // 0x470ae7: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  L00470aea: { // 0x470aea: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00470aec: { // 0x470aec: 7411 JZ 0x00470aff
    if(integer::condition("JZ",flags)) goto L00470aff;
  }
  L00470aee: { // 0x470aee: 381da885a200 CMP byte ptr [0x00a285a8],BL
    (void)integer::sub(m.r8((0x00a285a8u)),(s.bx & 0xffu),8,flags);
  }
  L00470af4: { // 0x470af4: 7406 JZ 0x00470afc
    if(integer::condition("JZ",flags)) goto L00470afc;
  }
  L00470af6: { // 0x470af6: ff8894010000 DEC dword ptr [EAX + 0x194]
    m.w32((s.ax+0x00000194u), integer::decrement(m.r32((s.ax+0x00000194u)),32,flags));
  }
  L00470afc: { // 0x470afc: 895e34 MOV dword ptr [ESI + 0x34],EBX
    m.w32((s.si+0x00000034u), s.bx);
  }
  L00470aff: { // 0x470aff: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00470b01: { // 0x470b01: e88af4f9ff CALL 0x0040ff90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ff90u,4655878u); flags=s.arithmetic_flags;
  }
  L00470b06: { // 0x470b06: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00470b07: { // 0x470b07: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00470b08: { // 0x470b08: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00691f50(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00691f50: { // 0x691f50: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00691f51: { // 0x691f51: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00691f52: { // 0x691f52: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00691f54: { // 0x691f54: 8b4650 MOV EAX,dword ptr [ESI + 0x50]
    s.ax = m.r32((s.si+0x00000050u));
  }
  L00691f57: { // 0x691f57: c706b8707900 MOV dword ptr [ESI],0x7970b8
    m.w32((s.si), 0x007970b8u);
  }
  L00691f5d: { // 0x691f5d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00691f5f: { // 0x691f5f: c746049c707900 MOV dword ptr [ESI + 0x4],0x79709c
    m.w32((s.si+0x00000004u), 0x0079709cu);
  }
  L00691f66: { // 0x691f66: c7460894707900 MOV dword ptr [ESI + 0x8],0x797094
    m.w32((s.si+0x00000008u), 0x00797094u);
  }
  L00691f6d: { // 0x691f6d: c7460c8c707900 MOV dword ptr [ESI + 0xc],0x79708c
    m.w32((s.si+0x0000000cu), 0x0079708cu);
  }
  L00691f74: { // 0x691f74: 7435 JZ 0x00691fab
    if(integer::condition("JZ",flags)) goto L00691fab;
  }
  L00691f76: { // 0x691f76: c6807501000000 MOV byte ptr [EAX + 0x175],0x0
    m.w8((s.ax+0x00000175u), 0x00000000u);
  }
  L00691f7d: { // 0x691f7d: c7465000000000 MOV dword ptr [ESI + 0x50],0x0
    m.w32((s.si+0x00000050u), 0x00000000u);
  }
  L00691f84: { // 0x691f84: 8b150087aa00 MOV EDX,dword ptr [0x00aa8700]
    s.dx = m.r32((0x00aa8700u));
  }
  L00691f8a: { // 0x691f8a: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L00691f8e: { // 0x691f8e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00691f8f: { // 0x691f8f: b90087aa00 MOV ECX,0xaa8700
    s.cx = 0x00aa8700u;
  }
  L00691f94: { // 0x691f94: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L00691f98: { // 0x691f98: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6889371u); flags=s.arithmetic_flags;
  }
  L00691f9b: { // 0x691f9b: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00691f9e: { // 0x691f9e: 740b JZ 0x00691fab
    if(integer::condition("JZ",flags)) goto L00691fab;
  }
  L00691fa0: { // 0x691fa0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00691fa1: { // 0x691fa1: b90087aa00 MOV ECX,0xaa8700
    s.cx = 0x00aa8700u;
  }
  L00691fa6: { // 0x691fa6: e8f527dcff CALL 0x004547a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004547a0u,6889387u); flags=s.arithmetic_flags;
  }
  L00691fab: { // 0x691fab: 8a4654 MOV AL,byte ptr [ESI + 0x54]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000054u)));
  }
  L00691fae: { // 0x691fae: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00691fb0: { // 0x691fb0: 742b JZ 0x00691fdd
    if(integer::condition("JZ",flags)) goto L00691fdd;
  }
  L00691fb2: { // 0x691fb2: 8b150087aa00 MOV EDX,dword ptr [0x00aa8700]
    s.dx = m.r32((0x00aa8700u));
  }
  L00691fb8: { // 0x691fb8: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L00691fbc: { // 0x691fbc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00691fbd: { // 0x691fbd: b90087aa00 MOV ECX,0xaa8700
    s.cx = 0x00aa8700u;
  }
  L00691fc2: { // 0x691fc2: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L00691fc6: { // 0x691fc6: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6889417u); flags=s.arithmetic_flags;
  }
  L00691fc9: { // 0x691fc9: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00691fcc: { // 0x691fcc: 740b JZ 0x00691fd9
    if(integer::condition("JZ",flags)) goto L00691fd9;
  }
  L00691fce: { // 0x691fce: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00691fcf: { // 0x691fcf: b90087aa00 MOV ECX,0xaa8700
    s.cx = 0x00aa8700u;
  }
  L00691fd4: { // 0x691fd4: e8c727dcff CALL 0x004547a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004547a0u,6889433u); flags=s.arithmetic_flags;
  }
  L00691fd9: { // 0x691fd9: c6465400 MOV byte ptr [ESI + 0x54],0x0
    m.w8((s.si+0x00000054u), 0x00000000u);
  }
  L00691fdd: { // 0x691fdd: 8b15e8e0a100 MOV EDX,dword ptr [0x00a1e0e8]
    s.dx = m.r32((0x00a1e0e8u));
  }
  L00691fe3: { // 0x691fe3: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L00691fe7: { // 0x691fe7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00691fe8: { // 0x691fe8: b9e8e0a100 MOV ECX,0xa1e0e8
    s.cx = 0x00a1e0e8u;
  }
  L00691fed: { // 0x691fed: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L00691ff1: { // 0x691ff1: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6889460u); flags=s.arithmetic_flags;
  }
  L00691ff4: { // 0x691ff4: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00691ff7: { // 0x691ff7: 742d JZ 0x00692026
    if(integer::condition("JZ",flags)) goto L00692026;
  }
  L00691ff9: { // 0x691ff9: 8b0df8e0a100 MOV ECX,dword ptr [0x00a1e0f8]
    s.cx = m.r32((0x00a1e0f8u));
  }
  L00691fff: { // 0x691fff: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00692001: { // 0x692001: 7d23 JGE 0x00692026
    if(integer::condition("JGE",flags)) goto L00692026;
  }
  L00692003: { // 0x692003: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00692004: { // 0x692004: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00692006: { // 0x692006: 890df8e0a100 MOV dword ptr [0x00a1e0f8],ECX
    m.w32((0x00a1e0f8u), s.cx);
  }
  L0069200c: { // 0x69200c: 7d18 JGE 0x00692026
    if(integer::condition("JGE",flags)) goto L00692026;
  }
  L0069200e: { // 0x69200e: 8b0dece0a100 MOV ECX,dword ptr [0x00a1e0ec]
    s.cx = m.r32((0x00a1e0ecu));
  }
  L00692014: { // 0x692014: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00692015: { // 0x692015: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00692018: { // 0x692018: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L0069201c: { // 0x69201c: 8b0df8e0a100 MOV ECX,dword ptr [0x00a1e0f8]
    s.cx = m.r32((0x00a1e0f8u));
  }
  L00692022: { // 0x692022: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00692024: { // 0x692024: 7ce8 JL 0x0069200e
    if(integer::condition("JL",flags)) goto L0069200e;
  }
  L00692026: { // 0x692026: 8b1558e0a100 MOV EDX,dword ptr [0x00a1e058]
    s.dx = m.r32((0x00a1e058u));
  }
  L0069202c: { // 0x69202c: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L00692030: { // 0x692030: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00692031: { // 0x692031: b958e0a100 MOV ECX,0xa1e058
    s.cx = 0x00a1e058u;
  }
  L00692036: { // 0x692036: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0069203a: { // 0x69203a: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6889533u); flags=s.arithmetic_flags;
  }
  L0069203d: { // 0x69203d: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00692040: { // 0x692040: 742d JZ 0x0069206f
    if(integer::condition("JZ",flags)) goto L0069206f;
  }
  L00692042: { // 0x692042: 8b0d68e0a100 MOV ECX,dword ptr [0x00a1e068]
    s.cx = m.r32((0x00a1e068u));
  }
  L00692048: { // 0x692048: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0069204a: { // 0x69204a: 7d23 JGE 0x0069206f
    if(integer::condition("JGE",flags)) goto L0069206f;
  }
  L0069204c: { // 0x69204c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0069204d: { // 0x69204d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0069204f: { // 0x69204f: 890d68e0a100 MOV dword ptr [0x00a1e068],ECX
    m.w32((0x00a1e068u), s.cx);
  }
  L00692055: { // 0x692055: 7d18 JGE 0x0069206f
    if(integer::condition("JGE",flags)) goto L0069206f;
  }
  L00692057: { // 0x692057: 8b0d5ce0a100 MOV ECX,dword ptr [0x00a1e05c]
    s.cx = m.r32((0x00a1e05cu));
  }
  L0069205d: { // 0x69205d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0069205e: { // 0x69205e: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00692061: { // 0x692061: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L00692065: { // 0x692065: 8b0d68e0a100 MOV ECX,dword ptr [0x00a1e068]
    s.cx = m.r32((0x00a1e068u));
  }
  L0069206b: { // 0x69206b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0069206d: { // 0x69206d: 7ce8 JL 0x00692057
    if(integer::condition("JL",flags)) goto L00692057;
  }
  L0069206f: { // 0x69206f: 8b15b887aa00 MOV EDX,dword ptr [0x00aa87b8]
    s.dx = m.r32((0x00aa87b8u));
  }
  L00692075: { // 0x692075: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L00692079: { // 0x692079: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069207a: { // 0x69207a: b9b887aa00 MOV ECX,0xaa87b8
    s.cx = 0x00aa87b8u;
  }
  L0069207f: { // 0x69207f: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L00692083: { // 0x692083: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6889606u); flags=s.arithmetic_flags;
  }
  L00692086: { // 0x692086: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00692089: { // 0x692089: 742d JZ 0x006920b8
    if(integer::condition("JZ",flags)) goto L006920b8;
  }
  L0069208b: { // 0x69208b: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L00692091: { // 0x692091: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00692093: { // 0x692093: 7d23 JGE 0x006920b8
    if(integer::condition("JGE",flags)) goto L006920b8;
  }
  L00692095: { // 0x692095: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00692096: { // 0x692096: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00692098: { // 0x692098: 890dc887aa00 MOV dword ptr [0x00aa87c8],ECX
    m.w32((0x00aa87c8u), s.cx);
  }
  L0069209e: { // 0x69209e: 7d18 JGE 0x006920b8
    if(integer::condition("JGE",flags)) goto L006920b8;
  }
  L006920a0: { // 0x6920a0: 8b0dbc87aa00 MOV ECX,dword ptr [0x00aa87bc]
    s.cx = m.r32((0x00aa87bcu));
  }
  L006920a6: { // 0x6920a6: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006920a7: { // 0x6920a7: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L006920aa: { // 0x6920aa: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L006920ae: { // 0x6920ae: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L006920b4: { // 0x6920b4: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006920b6: { // 0x6920b6: 7ce8 JL 0x006920a0
    if(integer::condition("JL",flags)) goto L006920a0;
  }
  L006920b8: { // 0x6920b8: 8b151088aa00 MOV EDX,dword ptr [0x00aa8810]
    s.dx = m.r32((0x00aa8810u));
  }
  L006920be: { // 0x6920be: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L006920c2: { // 0x6920c2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006920c3: { // 0x6920c3: b91088aa00 MOV ECX,0xaa8810
    s.cx = 0x00aa8810u;
  }
  L006920c8: { // 0x6920c8: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L006920cc: { // 0x6920cc: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6889679u); flags=s.arithmetic_flags;
  }
  L006920cf: { // 0x6920cf: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006920d2: { // 0x6920d2: 742d JZ 0x00692101
    if(integer::condition("JZ",flags)) goto L00692101;
  }
  L006920d4: { // 0x6920d4: 8b0d2088aa00 MOV ECX,dword ptr [0x00aa8820]
    s.cx = m.r32((0x00aa8820u));
  }
  L006920da: { // 0x6920da: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006920dc: { // 0x6920dc: 7d23 JGE 0x00692101
    if(integer::condition("JGE",flags)) goto L00692101;
  }
  L006920de: { // 0x6920de: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L006920df: { // 0x6920df: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006920e1: { // 0x6920e1: 890d2088aa00 MOV dword ptr [0x00aa8820],ECX
    m.w32((0x00aa8820u), s.cx);
  }
  L006920e7: { // 0x6920e7: 7d18 JGE 0x00692101
    if(integer::condition("JGE",flags)) goto L00692101;
  }
  L006920e9: { // 0x6920e9: 8b0d1488aa00 MOV ECX,dword ptr [0x00aa8814]
    s.cx = m.r32((0x00aa8814u));
  }
  L006920ef: { // 0x6920ef: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006920f0: { // 0x6920f0: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L006920f3: { // 0x6920f3: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L006920f7: { // 0x6920f7: 8b0d2088aa00 MOV ECX,dword ptr [0x00aa8820]
    s.cx = m.r32((0x00aa8820u));
  }
  L006920fd: { // 0x6920fd: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006920ff: { // 0x6920ff: 7ce8 JL 0x006920e9
    if(integer::condition("JL",flags)) goto L006920e9;
  }
  L00692101: { // 0x692101: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00692103: { // 0x692103: e888ded7ff CALL 0x0040ff90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ff90u,6889736u); flags=s.arithmetic_flags;
  }
  L00692108: { // 0x692108: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00692109: { // 0x692109: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0069210a: { // 0x69210a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
