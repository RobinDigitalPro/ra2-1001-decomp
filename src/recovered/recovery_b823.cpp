#include "recovered/recovery_b823_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b823 {
namespace {
void f_00363ef0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00363ef0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00763ef0: { // 0x763ef0: 8b4c2408 MOV ECX, dword ptr [ESP + 8]
    s.cx = m.r32((f.sp+8u));
  }
  L00763ef4: { // 0x763ef4: 8b542404 MOV EDX, dword ptr [ESP + 4]
    s.dx = m.r32((f.sp+4u));
  }
  L00763ef8: { // 0x763ef8: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00763efa: { // 0x763efa: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00763efb: { // 0x763efb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00763efc: { // 0x763efc: 83f908 CMP ECX, 8
    (void)integer::sub(s.cx,8u,32,flags);
  }
  L00763eff: { // 0x763eff: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00763f00: { // 0x763f00: 0f8790000000 JA 0x763f96
    if(integer::condition("JA",flags)) goto L00763f96;
  }
  L00763f06: { // 0x763f06: ff248d9c3f7600 JMP dword ptr [ECX*4 + 0x763f9c]
    switch((std::array<std::uint32_t,9>{0x763f73u,0x763f73u,0x763f73u,0x763f73u,0x763f0du,0x763f91u,0x763f55u,0x763f55u,0x763f73u}[s.cx])){
    case 0x00763ef0u: goto L00763ef0;
    case 0x00763ef4u: goto L00763ef4;
    case 0x00763ef8u: goto L00763ef8;
    case 0x00763efau: goto L00763efa;
    case 0x00763efbu: goto L00763efb;
    case 0x00763efcu: goto L00763efc;
    case 0x00763effu: goto L00763eff;
    case 0x00763f00u: goto L00763f00;
    case 0x00763f06u: goto L00763f06;
    case 0x00763f0du: goto L00763f0d;
    case 0x00763f13u: goto L00763f13;
    case 0x00763f17u: goto L00763f17;
    case 0x00763f1du: goto L00763f1d;
    case 0x00763f20u: goto L00763f20;
    case 0x00763f22u: goto L00763f22;
    case 0x00763f24u: goto L00763f24;
    case 0x00763f2au: goto L00763f2a;
    case 0x00763f2cu: goto L00763f2c;
    case 0x00763f2du: goto L00763f2d;
    case 0x00763f2fu: goto L00763f2f;
    case 0x00763f31u: goto L00763f31;
    case 0x00763f35u: goto L00763f35;
    case 0x00763f38u: goto L00763f38;
    case 0x00763f3au: goto L00763f3a;
    case 0x00763f3cu: goto L00763f3c;
    case 0x00763f3du: goto L00763f3d;
    case 0x00763f40u: goto L00763f40;
    case 0x00763f42u: goto L00763f42;
    case 0x00763f48u: goto L00763f48;
    case 0x00763f49u: goto L00763f49;
    case 0x00763f4bu: goto L00763f4b;
    case 0x00763f4du: goto L00763f4d;
    case 0x00763f53u: goto L00763f53;
    case 0x00763f54u: goto L00763f54;
    case 0x00763f55u: goto L00763f55;
    case 0x00763f59u: goto L00763f59;
    case 0x00763f5cu: goto L00763f5c;
    case 0x00763f5eu: goto L00763f5e;
    case 0x00763f5fu: goto L00763f5f;
    case 0x00763f61u: goto L00763f61;
    case 0x00763f65u: goto L00763f65;
    case 0x00763f6bu: goto L00763f6b;
    case 0x00763f6du: goto L00763f6d;
    case 0x00763f73u: goto L00763f73;
    case 0x00763f74u: goto L00763f74;
    case 0x00763f76u: goto L00763f76;
    case 0x00763f77u: goto L00763f77;
    case 0x00763f78u: goto L00763f78;
    case 0x00763f7eu: goto L00763f7e;
    case 0x00763f82u: goto L00763f82;
    case 0x00763f84u: goto L00763f84;
    case 0x00763f86u: goto L00763f86;
    case 0x00763f88u: goto L00763f88;
    case 0x00763f89u: goto L00763f89;
    case 0x00763f8fu: goto L00763f8f;
    case 0x00763f90u: goto L00763f90;
    case 0x00763f91u: goto L00763f91;
    case 0x00763f96u: goto L00763f96;
    case 0x00763f97u: goto L00763f97;
    case 0x00763f98u: goto L00763f98;
    default:throw std::domain_error("recovery823 unsupported switch destination");}
  }
  L00763f0d: { // 0x763f0d: 8bba04070000 MOV EDI, dword ptr [EDX + 0x704]
    s.di = m.r32((s.dx+0x00000704u));
  }
  L00763f13: { // 0x763f13: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00763f17: { // 0x763f17: 8bb200070000 MOV ESI, dword ptr [EDX + 0x700]
    s.si = m.r32((s.dx+0x00000700u));
  }
  L00763f1d: { // 0x763f1d: 8d0c07 LEA ECX, [EDI + EAX]
    s.cx = (s.di+s.ax);
  }
  L00763f20: { // 0x763f20: 3bce CMP ECX, ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00763f22: { // 0x763f22: 7f6d JG 0x763f91
    if(integer::condition("JG",flags)) goto L00763f91;
  }
  L00763f24: { // 0x763f24: 8bb2f4060000 MOV ESI, dword ptr [EDX + 0x6f4]
    s.si = m.r32((s.dx+0x000006f4u));
  }
  L00763f2a: { // 0x763f2a: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00763f2c: { // 0x763f2c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00763f2d: { // 0x763f2d: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L00763f2f: { // 0x763f2f: 03f7 ADD ESI, EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L00763f31: { // 0x763f31: 8b7c2418 MOV EDI, dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L00763f35: { // 0x763f35: c1e902 SHR ECX, 2
    s.cx = integer::shift(s.cx,2u,32,flags,integer::Shift::right);
  }
  L00763f38: { // 0x763f38: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00763f3a: { // 0x763f3a: 8bcb MOV ECX, EBX
    s.cx = s.bx;
  }
  L00763f3c: { // 0x763f3c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00763f3d: { // 0x763f3d: 83e103 AND ECX, 3
    s.cx = integer::logical((s.cx)&(3u),32,flags);
  }
  L00763f40: { // 0x763f40: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L00763f42: { // 0x763f42: 8b8a04070000 MOV ECX, dword ptr [EDX + 0x704]
    s.cx = m.r32((s.dx+0x00000704u));
  }
  L00763f48: { // 0x763f48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763f49: { // 0x763f49: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00763f4b: { // 0x763f4b: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00763f4d: { // 0x763f4d: 898a04070000 MOV dword ptr [EDX + 0x704], ECX
    m.w32((s.dx+0x00000704u), s.cx);
  }
  L00763f53: { // 0x763f53: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763f54: { // 0x763f54: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00763f55: { // 0x763f55: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00763f59: { // 0x763f59: 83e900 SUB ECX, 0
    s.cx = integer::sub(s.cx,0u,32,flags);
  }
  L00763f5c: { // 0x763f5c: 741a JZ 0x763f78
    if(integer::condition("JZ",flags)) goto L00763f78;
  }
  L00763f5e: { // 0x763f5e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00763f5f: { // 0x763f5f: 7530 JNZ 0x763f91
    if(integer::condition("JNZ",flags)) goto L00763f91;
  }
  L00763f61: { // 0x763f61: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00763f65: { // 0x763f65: 8b8a04070000 MOV ECX, dword ptr [EDX + 0x704]
    s.cx = m.r32((s.dx+0x00000704u));
  }
  L00763f6b: { // 0x763f6b: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00763f6d: { // 0x763f6d: 898a04070000 MOV dword ptr [EDX + 0x704], ECX
    m.w32((s.dx+0x00000704u), s.cx);
  }
  L00763f73: { // 0x763f73: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763f74: { // 0x763f74: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00763f76: { // 0x763f76: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763f77: { // 0x763f77: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00763f78: { // 0x763f78: 8bb2fc060000 MOV ESI, dword ptr [EDX + 0x6fc]
    s.si = m.r32((s.dx+0x000006fcu));
  }
  L00763f7e: { // 0x763f7e: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00763f82: { // 0x763f82: 3bce CMP ECX, ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00763f84: { // 0x763f84: 7c0b JL 0x763f91
    if(integer::condition("JL",flags)) goto L00763f91;
  }
  L00763f86: { // 0x763f86: 2bce SUB ECX, ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L00763f88: { // 0x763f88: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763f89: { // 0x763f89: 898a04070000 MOV dword ptr [EDX + 0x704], ECX
    m.w32((s.dx+0x00000704u), s.cx);
  }
  L00763f8f: { // 0x763f8f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763f90: { // 0x763f90: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00763f91: { // 0x763f91: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L00763f96: { // 0x763f96: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763f97: { // 0x763f97: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763f98: { // 0x763f98: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7749360u:f_00363ef0(m,s,child,{});break;
default:throw std::domain_error("recovery823 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00766960(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00766960: { // 0x766960: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00766961: { // 0x766961: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00766962: { // 0x766962: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00766963: { // 0x766963: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766964: { // 0x766964: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00766966: { // 0x766966: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L00766968: { // 0x766968: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766969: { // 0x766969: 8a86f5000000 MOV AL,byte ptr [ESI + 0xf5]
    s.ax = with_al(s.ax, m.r8((s.si+0x000000f5u)));
  }
  L0076696f: { // 0x76696f: 8bbe64010000 MOV EDI,dword ptr [ESI + 0x164]
    s.di = m.r32((s.si+0x00000164u));
  }
  L00766975: { // 0x766975: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00766977: { // 0x766977: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0076697b: { // 0x76697b: 7551 JNZ 0x007669ce
    if(integer::condition("JNZ",flags)) goto L007669ce;
  }
  L0076697d: { // 0x76697d: 8b8678010000 MOV EAX,dword ptr [ESI + 0x178]
    s.ax = m.r32((s.si+0x00000178u));
  }
  L00766983: { // 0x766983: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766985: { // 0x766985: 7547 JNZ 0x007669ce
    if(integer::condition("JNZ",flags)) goto L007669ce;
  }
  L00766987: { // 0x766987: 8b9654070000 MOV EDX,dword ptr [ESI + 0x754]
    s.dx = m.r32((s.si+0x00000754u));
  }
  L0076698d: { // 0x76698d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076698f: { // 0x76698f: 668b864c070000 MOV AX,word ptr [ESI + 0x74c]
    s.ax = with_ax(s.ax, m.r16((s.si+0x0000074cu)));
  }
  L00766996: { // 0x766996: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00766998: { // 0x766998: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076699a: { // 0x76699a: 7e17 JLE 0x007669b3
    if(integer::condition("JLE",flags)) goto L007669b3;
  }
  L0076699c: { // 0x76699c: 8b9e80010000 MOV EBX,dword ptr [ESI + 0x180]
    s.bx = m.r32((s.si+0x00000180u));
  }
  L007669a2: { // 0x7669a2: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L007669a4: { // 0x7669a4: 668b2a MOV BP,word ptr [EDX]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((s.dx))) & 0xffffu);
  }
  L007669a7: { // 0x7669a7: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L007669a9: { // 0x7669a9: 7f0c JG 0x007669b7
    if(integer::condition("JG",flags)) goto L007669b7;
  }
  L007669ab: { // 0x7669ab: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L007669ac: { // 0x7669ac: 83c206 ADD EDX,0x6
    s.dx = integer::add(s.dx,0x00000006u,32,flags);
  }
  L007669af: { // 0x7669af: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L007669b1: { // 0x7669b1: 7cef JL 0x007669a2
    if(integer::condition("JL",flags)) goto L007669a2;
  }
  L007669b3: { // 0x7669b3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L007669b5: { // 0x7669b5: eb0d JMP 0x007669c4
    goto L007669c4;
  }
  L007669b7: { // 0x7669b7: 8b8654070000 MOV EAX,dword ptr [ESI + 0x754]
    s.ax = m.r32((s.si+0x00000754u));
  }
  L007669bd: { // 0x7669bd: 8d0c49 LEA ECX,[ECX + ECX*0x2]
    s.cx = (s.cx+(s.cx * 0x00000002u));
  }
  L007669c0: { // 0x7669c0: 8b444802 MOV EAX,dword ptr [EAX + ECX*0x2 + 0x2]
    s.ax = m.r32((s.ax+(s.cx * 0x00000002u)+0x00000002u));
  }
  L007669c4: { // 0x7669c4: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L007669c8: { // 0x7669c8: 89867c010000 MOV dword ptr [ESI + 0x17c],EAX
    m.w32((s.si+0x0000017cu), s.ax);
  }
  L007669ce: { // 0x7669ce: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L007669d0: { // 0x7669d0: 8b9678010000 MOV EDX,dword ptr [ESI + 0x178]
    s.dx = m.r32((s.si+0x00000178u));
  }
  L007669d6: { // 0x7669d6: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L007669d8: { // 0x7669d8: 8d5301 LEA EDX,[EBX + 0x1]
    s.dx = (s.bx+0x00000001u);
  }
  L007669db: { // 0x7669db: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L007669de: { // 0x7669de: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L007669df: { // 0x7669df: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007669e0: { // 0x7669e0: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L007669e2: { // 0x7669e2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007669e3: { // 0x7669e3: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7760358u); flags=s.arithmetic_flags;
  }
  L007669e6: { // 0x7669e6: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007669e9: { // 0x7669e9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007669eb: { // 0x7669eb: 740b JZ 0x007669f8
    if(integer::condition("JZ",flags)) goto L007669f8;
  }
  L007669ed: { // 0x7669ed: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007669ee: { // 0x7669ee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007669ef: { // 0x7669ef: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007669f0: { // 0x7669f0: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L007669f5: { // 0x7669f5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007669f6: { // 0x7669f6: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007669f7: { // 0x7669f7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007669f8: { // 0x7669f8: 8bae78010000 MOV EBP,dword ptr [ESI + 0x178]
    s.bp = m.r32((s.si+0x00000178u));
  }
  L007669fe: { // 0x7669fe: 03eb ADD EBP,EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L00766a00: { // 0x766a00: 8b9e74010000 MOV EBX,dword ptr [ESI + 0x174]
    s.bx = m.r32((s.si+0x00000174u));
  }
  L00766a06: { // 0x766a06: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00766a07: { // 0x766a07: 89ae78010000 MOV dword ptr [ESI + 0x178],EBP
    m.w32((s.si+0x00000178u), s.bp);
  }
  L00766a0d: { // 0x766a0d: 899e74010000 MOV dword ptr [ESI + 0x174],EBX
    m.w32((s.si+0x00000174u), s.bx);
  }
  L00766a13: { // 0x766a13: 8a96f5000000 MOV DL,byte ptr [ESI + 0xf5]
    s.dx = with_al(s.dx, m.r8((s.si+0x000000f5u)));
  }
  L00766a19: { // 0x766a19: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00766a1b: { // 0x766a1b: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00766a1d: { // 0x766a1d: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00766a1f: { // 0x766a1f: 743f JZ 0x00766a60
    if(integer::condition("JZ",flags)) goto L00766a60;
  }
  L00766a21: { // 0x766a21: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00766a23: { // 0x766a23: 8a96f5000000 MOV DL,byte ptr [ESI + 0xf5]
    s.dx = with_al(s.dx, m.r8((s.si+0x000000f5u)));
  }
  L00766a29: { // 0x766a29: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00766a2b: { // 0x766a2b: 752a JNZ 0x00766a57
    if(integer::condition("JNZ",flags)) goto L00766a57;
  }
  L00766a2d: { // 0x766a2d: 894714 MOV dword ptr [EDI + 0x14],EAX
    m.w32((s.di+0x00000014u), s.ax);
  }
  L00766a30: { // 0x766a30: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00766a32: { // 0x766a32: 898674010000 MOV dword ptr [ESI + 0x174],EAX
    m.w32((s.si+0x00000174u), s.ax);
  }
  L00766a38: { // 0x766a38: 898678010000 MOV dword ptr [ESI + 0x178],EAX
    m.w32((s.si+0x00000178u), s.ax);
  }
  L00766a3e: { // 0x766a3e: 894710 MOV dword ptr [EDI + 0x10],EAX
    m.w32((s.di+0x00000010u), s.ax);
  }
  L00766a41: { // 0x766a41: c7470c08000000 MOV dword ptr [EDI + 0xc],0x8
    m.w32((s.di+0x0000000cu), 0x00000008u);
  }
  L00766a48: { // 0x766a48: 89be68010000 MOV dword ptr [ESI + 0x168],EDI
    m.w32((s.si+0x00000168u), s.di);
  }
  L00766a4e: { // 0x766a4e: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00766a51: { // 0x766a51: 898664010000 MOV dword ptr [ESI + 0x164],EAX
    m.w32((s.si+0x00000164u), s.ax);
  }
  L00766a57: { // 0x766a57: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766a58: { // 0x766a58: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766a59: { // 0x766a59: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766a5a: { // 0x766a5a: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00766a5d: { // 0x766a5d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766a5e: { // 0x766a5e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00766a5f: { // 0x766a5f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766a60: { // 0x766a60: 8b8e7c010000 MOV ECX,dword ptr [ESI + 0x17c]
    s.cx = m.r32((s.si+0x0000017cu));
  }
  L00766a66: { // 0x766a66: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00766a68: { // 0x766a68: 74c3 JZ 0x00766a2d
    if(integer::condition("JZ",flags)) goto L00766a2d;
  }
  L00766a6a: { // 0x766a6a: 7eeb JLE 0x00766a57
    if(integer::condition("JLE",flags)) goto L00766a57;
  }
  L00766a6c: { // 0x766a6c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766a6d: { // 0x766a6d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766a6e: { // 0x766a6e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766a6f: { // 0x766a6f: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766a74: { // 0x766a74: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766a75: { // 0x766a75: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00766a76: { // 0x766a76: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00766a80(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00766a80: { // 0x766a80: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00766a83: { // 0x766a83: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00766a84: { // 0x766a84: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00766a85: { // 0x766a85: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766a86: { // 0x766a86: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00766a88: { // 0x766a88: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00766a8a: { // 0x766a8a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766a8b: { // 0x766a8b: 8a86f5000000 MOV AL,byte ptr [ESI + 0xf5]
    s.ax = with_al(s.ax, m.r8((s.si+0x000000f5u)));
  }
  L00766a91: { // 0x766a91: 8b9e64010000 MOV EBX,dword ptr [ESI + 0x164]
    s.bx = m.r32((s.si+0x00000164u));
  }
  L00766a97: { // 0x766a97: 8d7a01 LEA EDI,[EDX + 0x1]
    s.di = (s.dx+0x00000001u);
  }
  L00766a9a: { // 0x766a9a: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00766a9c: { // 0x766a9c: 8b8678010000 MOV EAX,dword ptr [ESI + 0x178]
    s.ax = m.r32((s.si+0x00000178u));
  }
  L00766aa2: { // 0x766aa2: 83e7fe AND EDI,0xfffffffe
    s.di = integer::logical((s.di)&(0xfffffffeu),32,flags);
  }
  L00766aa5: { // 0x766aa5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766aa7: { // 0x766aa7: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00766aab: { // 0x766aab: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L00766aaf: { // 0x766aaf: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L00766ab3: { // 0x766ab3: 0f858f000000 JNZ 0x00766b48
    if(integer::condition("JNZ",flags)) goto L00766b48;
  }
  L00766ab9: { // 0x766ab9: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00766abb: { // 0x766abb: 7415 JZ 0x00766ad2
    if(integer::condition("JZ",flags)) goto L00766ad2;
  }
  L00766abd: { // 0x766abd: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00766abf: { // 0x766abf: 8d5501 LEA EDX,[EBP + 0x1]
    s.dx = (s.bp+0x00000001u);
  }
  L00766ac2: { // 0x766ac2: 0fafcf IMUL ECX,EDI
    s.cx = integer::imul(s.cx,s.di,32,flags);
  }
  L00766ac5: { // 0x766ac5: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L00766ac8: { // 0x766ac8: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00766aca: { // 0x766aca: 898e7c010000 MOV dword ptr [ESI + 0x17c],ECX
    m.w32((s.si+0x0000017cu), s.cx);
  }
  L00766ad0: { // 0x766ad0: eb53 JMP 0x00766b25
    goto L00766b25;
  }
  L00766ad2: { // 0x766ad2: 8b9654070000 MOV EDX,dword ptr [ESI + 0x754]
    s.dx = m.r32((s.si+0x00000754u));
  }
  L00766ad8: { // 0x766ad8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00766ada: { // 0x766ada: 668b864c070000 MOV AX,word ptr [ESI + 0x74c]
    s.ax = with_ax(s.ax, m.r16((s.si+0x0000074cu)));
  }
  L00766ae1: { // 0x766ae1: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00766ae3: { // 0x766ae3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766ae5: { // 0x766ae5: 7e1f JLE 0x00766b06
    if(integer::condition("JLE",flags)) goto L00766b06;
  }
  L00766ae7: { // 0x766ae7: 8b9e80010000 MOV EBX,dword ptr [ESI + 0x180]
    s.bx = m.r32((s.si+0x00000180u));
  }
  L00766aed: { // 0x766aed: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00766aef: { // 0x766aef: 668b2a MOV BP,word ptr [EDX]
    s.bp = (s.bp & 0xffff0000u) | ((m.r16((s.dx))) & 0xffffu);
  }
  L00766af2: { // 0x766af2: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L00766af4: { // 0x766af4: 7f14 JG 0x00766b0a
    if(integer::condition("JG",flags)) goto L00766b0a;
  }
  L00766af6: { // 0x766af6: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00766af7: { // 0x766af7: 83c206 ADD EDX,0x6
    s.dx = integer::add(s.dx,0x00000006u,32,flags);
  }
  L00766afa: { // 0x766afa: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00766afc: { // 0x766afc: 7cef JL 0x00766aed
    if(integer::condition("JL",flags)) goto L00766aed;
  }
  L00766afe: { // 0x766afe: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00766b02: { // 0x766b02: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L00766b06: { // 0x766b06: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00766b08: { // 0x766b08: eb15 JMP 0x00766b1f
    goto L00766b1f;
  }
  L00766b0a: { // 0x766b0a: 8b8654070000 MOV EAX,dword ptr [ESI + 0x754]
    s.ax = m.r32((s.si+0x00000754u));
  }
  L00766b10: { // 0x766b10: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00766b14: { // 0x766b14: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L00766b18: { // 0x766b18: 8d0c49 LEA ECX,[ECX + ECX*0x2]
    s.cx = (s.cx+(s.cx * 0x00000002u));
  }
  L00766b1b: { // 0x766b1b: 8b444802 MOV EAX,dword ptr [EAX + ECX*0x2 + 0x2]
    s.ax = m.r32((s.ax+(s.cx * 0x00000002u)+0x00000002u));
  }
  L00766b1f: { // 0x766b1f: 89867c010000 MOV dword ptr [ESI + 0x17c],EAX
    m.w32((s.si+0x0000017cu), s.ax);
  }
  L00766b25: { // 0x766b25: f6865401000001 TEST byte ptr [ESI + 0x154],0x1
    (void)integer::logical((m.r8((s.si+0x00000154u)))&(0x00000001u),8,flags);
  }
  L00766b2c: { // 0x766b2c: 7513 JNZ 0x00766b41
    if(integer::condition("JNZ",flags)) goto L00766b41;
  }
  L00766b2e: { // 0x766b2e: 8b9668070000 MOV EDX,dword ptr [ESI + 0x768]
    s.dx = m.r32((s.si+0x00000768u));
  }
  L00766b34: { // 0x766b34: 8b867c010000 MOV EAX,dword ptr [ESI + 0x17c]
    s.ax = m.r32((s.si+0x0000017cu));
  }
  L00766b3a: { // 0x766b3a: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00766b3c: { // 0x766b3c: 895310 MOV dword ptr [EBX + 0x10],EDX
    m.w32((s.bx+0x00000010u), s.dx);
  }
  L00766b3f: { // 0x766b3f: eb07 JMP 0x00766b48
    goto L00766b48;
  }
  L00766b41: { // 0x766b41: c7431000000000 MOV dword ptr [EBX + 0x10],0x0
    m.w32((s.bx+0x00000010u), 0x00000000u);
  }
  L00766b48: { // 0x766b48: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  L00766b4b: { // 0x766b4b: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00766b4d: { // 0x766b4d: 8b8e78010000 MOV ECX,dword ptr [ESI + 0x178]
    s.cx = m.r32((s.si+0x00000178u));
  }
  L00766b53: { // 0x766b53: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00766b55: { // 0x766b55: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00766b57: { // 0x766b57: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766b58: { // 0x766b58: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766b59: { // 0x766b59: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766b5b: { // 0x766b5b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766b5c: { // 0x766b5c: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7760735u); flags=s.arithmetic_flags;
  }
  L00766b5f: { // 0x766b5f: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766b62: { // 0x766b62: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766b64: { // 0x766b64: 740d JZ 0x00766b73
    if(integer::condition("JZ",flags)) goto L00766b73;
  }
  L00766b66: { // 0x766b66: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766b67: { // 0x766b67: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766b68: { // 0x766b68: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766b69: { // 0x766b69: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766b6e: { // 0x766b6e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766b6f: { // 0x766b6f: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00766b72: { // 0x766b72: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766b73: { // 0x766b73: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00766b77: { // 0x766b77: 8b9678010000 MOV EDX,dword ptr [ESI + 0x178]
    s.dx = m.r32((s.si+0x00000178u));
  }
  L00766b7d: { // 0x766b7d: 8b8e74010000 MOV ECX,dword ptr [ESI + 0x174]
    s.cx = m.r32((s.si+0x00000174u));
  }
  L00766b83: { // 0x766b83: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00766b85: { // 0x766b85: 899678010000 MOV dword ptr [ESI + 0x178],EDX
    m.w32((s.si+0x00000178u), s.dx);
  }
  L00766b8b: { // 0x766b8b: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00766b8d: { // 0x766b8d: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00766b8f: { // 0x766b8f: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00766b90: { // 0x766b90: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00766b92: { // 0x766b92: 898e74010000 MOV dword ptr [ESI + 0x174],ECX
    m.w32((s.si+0x00000174u), s.cx);
  }
  L00766b98: { // 0x766b98: 744d JZ 0x00766be7
    if(integer::condition("JZ",flags)) goto L00766be7;
  }
  L00766b9a: { // 0x766b9a: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00766b9c: { // 0x766b9c: 753e JNZ 0x00766bdc
    if(integer::condition("JNZ",flags)) goto L00766bdc;
  }
  L00766b9e: { // 0x766b9e: 899674010000 MOV dword ptr [ESI + 0x174],EDX
    m.w32((s.si+0x00000174u), s.dx);
  }
  L00766ba4: { // 0x766ba4: 899678010000 MOV dword ptr [ESI + 0x178],EDX
    m.w32((s.si+0x00000178u), s.dx);
  }
  L00766baa: { // 0x766baa: c7430c0a000000 MOV dword ptr [EBX + 0xc],0xa
    m.w32((s.bx+0x0000000cu), 0x0000000au);
  }
  L00766bb1: { // 0x766bb1: 899e68010000 MOV dword ptr [ESI + 0x168],EBX
    m.w32((s.si+0x00000168u), s.bx);
  }
  L00766bb7: { // 0x766bb7: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L00766bba: { // 0x766bba: 898e64010000 MOV dword ptr [ESI + 0x164],ECX
    m.w32((s.si+0x00000164u), s.cx);
  }
  L00766bc0: { // 0x766bc0: 6683bee800000003 CMP word ptr [ESI + 0xe8],0x3
    (void)integer::sub(m.r16((s.si+0x000000e8u)),0x00000003u,16,flags);
  }
  L00766bc8: { // 0x766bc8: 7312 JNC 0x00766bdc
    if(integer::condition("JNC",flags)) goto L00766bdc;
  }
  L00766bca: { // 0x766bca: 8b967c010000 MOV EDX,dword ptr [ESI + 0x17c]
    s.dx = m.r32((s.si+0x0000017cu));
  }
  L00766bd0: { // 0x766bd0: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  L00766bd3: { // 0x766bd3: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00766bd5: { // 0x766bd5: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00766bd7: { // 0x766bd7: c644020180 MOV byte ptr [EDX + EAX*0x1 + 0x1],0x80
    m.w8((s.dx+(s.ax * 0x00000001u)+0x00000001u), 0x00000080u);
  }
  L00766bdc: { // 0x766bdc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766bdd: { // 0x766bdd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766bde: { // 0x766bde: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766bdf: { // 0x766bdf: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00766be2: { // 0x766be2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766be3: { // 0x766be3: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00766be6: { // 0x766be6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766be7: { // 0x766be7: 8b8e7c010000 MOV ECX,dword ptr [ESI + 0x17c]
    s.cx = m.r32((s.si+0x0000017cu));
  }
  L00766bed: { // 0x766bed: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00766bef: { // 0x766bef: 74ad JZ 0x00766b9e
    if(integer::condition("JZ",flags)) goto L00766b9e;
  }
  L00766bf1: { // 0x766bf1: 7ee9 JLE 0x00766bdc
    if(integer::condition("JLE",flags)) goto L00766bdc;
  }
  L00766bf3: { // 0x766bf3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766bf4: { // 0x766bf4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766bf5: { // 0x766bf5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766bf6: { // 0x766bf6: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766bfb: { // 0x766bfb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766bfc: { // 0x766bfc: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00766bff: { // 0x766bff: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
