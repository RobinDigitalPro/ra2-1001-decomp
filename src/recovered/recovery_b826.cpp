#include "recovered/recovery_b826_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b826 {
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
    default:throw std::domain_error("recovery826 unsupported switch destination");}
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
default:throw std::domain_error("recovery826 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00766c00(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00766c00: { // 0x766c00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00766c01: { // 0x766c01: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00766c02: { // 0x766c02: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00766c03: { // 0x766c03: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00766c05: { // 0x766c05: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00766c07: { // 0x766c07: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L00766c0b: { // 0x766c0b: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00766c0c: { // 0x766c0c: 8b9d70010000 MOV EBX,dword ptr [EBP + 0x170]
    s.bx = m.r32((s.bp+0x00000170u));
  }
  L00766c12: { // 0x766c12: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766c13: { // 0x766c13: 8bb570070000 MOV ESI,dword ptr [EBP + 0x770]
    s.si = m.r32((s.bp+0x00000770u));
  }
  L00766c19: { // 0x766c19: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00766c1b: { // 0x766c1b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766c1c: { // 0x766c1c: 8b7b08 MOV EDI,dword ptr [EBX + 0x8]
    s.di = m.r32((s.bx+0x00000008u));
  }
  L00766c1f: { // 0x766c1f: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L00766c21: { // 0x766c21: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766c22: { // 0x766c22: 03fe ADD EDI,ESI
    s.di = integer::add(s.di,s.si,32,flags);
  }
  L00766c24: { // 0x766c24: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766c25: { // 0x766c25: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766c27: { // 0x766c27: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00766c28: { // 0x766c28: ff5540 CALL dword ptr [EBP + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x00000040u)),7760939u); flags=s.arithmetic_flags;
  }
  L00766c2b: { // 0x766c2b: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766c2e: { // 0x766c2e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766c30: { // 0x766c30: 740b JZ 0x00766c3d
    if(integer::condition("JZ",flags)) goto L00766c3d;
  }
  L00766c32: { // 0x766c32: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766c33: { // 0x766c33: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766c34: { // 0x766c34: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766c35: { // 0x766c35: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766c3a: { // 0x766c3a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766c3b: { // 0x766c3b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00766c3c: { // 0x766c3c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766c3d: { // 0x766c3d: 8b5314 MOV EDX,dword ptr [EBX + 0x14]
    s.dx = m.r32((s.bx+0x00000014u));
  }
  L00766c40: { // 0x766c40: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00766c44: { // 0x766c44: 83ca08 OR EDX,0x8
    s.dx = integer::logical((s.dx)|(0x00000008u),32,flags);
  }
  L00766c47: { // 0x766c47: 897324 MOV dword ptr [EBX + 0x24],ESI
    m.w32((s.bx+0x00000024u), s.si);
  }
  L00766c4a: { // 0x766c4a: 895314 MOV dword ptr [EBX + 0x14],EDX
    m.w32((s.bx+0x00000014u), s.dx);
  }
  L00766c4d: { // 0x766c4d: 894328 MOV dword ptr [EBX + 0x28],EAX
    m.w32((s.bx+0x00000028u), s.ax);
  }
  L00766c50: { // 0x766c50: 6683bde800000003 CMP word ptr [EBP + 0xe8],0x3
    (void)integer::sub(m.r16((s.bp+0x000000e8u)),0x00000003u,16,flags);
  }
  L00766c58: { // 0x766c58: 7305 JNC 0x00766c5f
    if(integer::condition("JNC",flags)) goto L00766c5f;
  }
  L00766c5a: { // 0x766c5a: c644070180 MOV byte ptr [EDI + EAX*0x1 + 0x1],0x80
    m.w8((s.di+(s.ax * 0x00000001u)+0x00000001u), 0x00000080u);
  }
  L00766c5f: { // 0x766c5f: 6683bd5807000001 CMP word ptr [EBP + 0x758],0x1
    (void)integer::sub(m.r16((s.bp+0x00000758u)),0x00000001u,16,flags);
  }
  L00766c67: { // 0x766c67: 7553 JNZ 0x00766cbc
    if(integer::condition("JNZ",flags)) goto L00766cbc;
  }
  L00766c69: { // 0x766c69: 8b4308 MOV EAX,dword ptr [EBX + 0x8]
    s.ax = m.r32((s.bx+0x00000008u));
  }
  L00766c6c: { // 0x766c6c: 8b8d70070000 MOV ECX,dword ptr [EBP + 0x770]
    s.cx = m.r32((s.bp+0x00000770u));
  }
  L00766c72: { // 0x766c72: 8b5324 MOV EDX,dword ptr [EBX + 0x24]
    s.dx = m.r32((s.bx+0x00000024u));
  }
  L00766c75: { // 0x766c75: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00766c76: { // 0x766c76: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00766c78: { // 0x766c78: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766c79: { // 0x766c79: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00766c7a: { // 0x766c7a: e8ac600000 CALL 0x0076cd2b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076cd2bu,7761023u); flags=s.arithmetic_flags;
  }
  L00766c7f: { // 0x766c7f: 8b7314 MOV ESI,dword ptr [EBX + 0x14]
    s.si = m.r32((s.bx+0x00000014u));
  }
  L00766c82: { // 0x766c82: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00766c84: { // 0x766c84: 83e6f7 AND ESI,0xfffffff7
    s.si = integer::logical((s.si)&(0xfffffff7u),32,flags);
  }
  L00766c87: { // 0x766c87: 8dbdc4010000 LEA EDI,[EBP + 0x1c4]
    s.di = (s.bp+0x000001c4u);
  }
  L00766c8d: { // 0x766c8d: 897314 MOV dword ptr [EBX + 0x14],ESI
    m.w32((s.bx+0x00000014u), s.si);
  }
  L00766c90: { // 0x766c90: 8b7308 MOV ESI,dword ptr [EBX + 0x8]
    s.si = m.r32((s.bx+0x00000008u));
  }
  L00766c93: { // 0x766c93: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L00766c96: { // 0x766c96: 894328 MOV dword ptr [EBX + 0x28],EAX
    m.w32((s.bx+0x00000028u), s.ax);
  }
  L00766c99: { // 0x766c99: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00766c9c: { // 0x766c9c: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00766c9e: { // 0x766c9e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00766ca0: { // 0x766ca0: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L00766ca3: { // 0x766ca3: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L00766ca5: { // 0x766ca5: 8b85a4010000 MOV EAX,dword ptr [EBP + 0x1a4]
    s.ax = m.r32((s.bp+0x000001a4u));
  }
  L00766cab: { // 0x766cab: 8b4b28 MOV ECX,dword ptr [EBX + 0x28]
    s.cx = m.r32((s.bx+0x00000028u));
  }
  L00766cae: { // 0x766cae: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L00766cb0: { // 0x766cb0: 898dc0010000 MOV dword ptr [EBP + 0x1c0],ECX
    m.w32((s.bp+0x000001c0u), s.cx);
  }
  L00766cb6: { // 0x766cb6: 8985a4010000 MOV dword ptr [EBP + 0x1a4],EAX
    m.w32((s.bp+0x000001a4u), s.ax);
  }
  L00766cbc: { // 0x766cbc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766cbd: { // 0x766cbd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766cbe: { // 0x766cbe: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766cbf: { // 0x766cbf: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00766cc2: { // 0x766cc2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766cc3: { // 0x766cc3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00766cc4: { // 0x766cc4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00766cd0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00766cd0: { // 0x766cd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766cd1: { // 0x766cd1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766cd2: { // 0x766cd2: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00766cd4: { // 0x766cd4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00766cd6: { // 0x766cd6: 8a8e84000000 MOV CL,byte ptr [ESI + 0x84]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000084u)));
  }
  L00766cdc: { // 0x766cdc: 8d4701 LEA EAX,[EDI + 0x1]
    s.ax = (s.di+0x00000001u);
  }
  L00766cdf: { // 0x766cdf: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00766ce1: { // 0x766ce1: f6c101 TEST CL,0x1
    (void)integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags);
  }
  L00766ce4: { // 0x766ce4: 0f849d000000 JZ 0x00766d87
    if(integer::condition("JZ",flags)) goto L00766d87;
  }
  L00766cea: { // 0x766cea: 8b8e8c070000 MOV ECX,dword ptr [ESI + 0x78c]
    s.cx = m.r32((s.si+0x0000078cu));
  }
  L00766cf0: { // 0x766cf0: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00766cf2: { // 0x766cf2: 0f848f000000 JZ 0x00766d87
    if(integer::condition("JZ",flags)) goto L00766d87;
  }
  L00766cf8: { // 0x766cf8: 3b86b4070000 CMP EAX,dword ptr [ESI + 0x7b4]
    (void)integer::sub(s.ax,m.r32((s.si+0x000007b4u)),32,flags);
  }
  L00766cfe: { // 0x766cfe: 765e JBE 0x00766d5e
    if(integer::condition("JBE",flags)) goto L00766d5e;
  }
  L00766d00: { // 0x766d00: 8b9690070000 MOV EDX,dword ptr [ESI + 0x790]
    s.dx = m.r32((s.si+0x00000790u));
  }
  L00766d06: { // 0x766d06: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00766d08: { // 0x766d08: 7554 JNZ 0x00766d5e
    if(integer::condition("JNZ",flags)) goto L00766d5e;
  }
  L00766d0a: { // 0x766d0a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766d0b: { // 0x766d0b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00766d0c: { // 0x766d0c: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766d0e: { // 0x766d0e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766d0f: { // 0x766d0f: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7761170u); flags=s.arithmetic_flags;
  }
  L00766d12: { // 0x766d12: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766d15: { // 0x766d15: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766d17: { // 0x766d17: 7408 JZ 0x00766d21
    if(integer::condition("JZ",flags)) goto L00766d21;
  }
  L00766d19: { // 0x766d19: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766d1a: { // 0x766d1a: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766d1f: { // 0x766d1f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766d20: { // 0x766d20: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766d21: { // 0x766d21: 8b8690070000 MOV EAX,dword ptr [ESI + 0x790]
    s.ax = m.r32((s.si+0x00000790u));
  }
  L00766d27: { // 0x766d27: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00766d29: { // 0x766d29: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00766d2b: { // 0x766d2b: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00766d2d: { // 0x766d2d: 898690070000 MOV dword ptr [ESI + 0x790],EAX
    m.w32((s.si+0x00000790u), s.ax);
  }
  L00766d33: { // 0x766d33: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00766d35: { // 0x766d35: f7b69c000000 DIV dword ptr [ESI + 0x9c]
    const auto divisor=m.r32((s.si+0x0000009cu));const std::uint64_t dividend=(std::uint64_t(s.dx)<<32)|s.ax;if(!divisor||dividend/divisor>0xffffffffull)throw std::domain_error("826 DIV overflow");s.ax=std::uint32_t(dividend/divisor);s.dx=std::uint32_t(dividend%divisor);
  }
  L00766d3b: { // 0x766d3b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766d3d: { // 0x766d3d: 7619 JBE 0x00766d58
    if(integer::condition("JBE",flags)) goto L00766d58;
  }
  L00766d3f: { // 0x766d3f: 8b8694070000 MOV EAX,dword ptr [ESI + 0x794]
    s.ax = m.r32((s.si+0x00000794u));
  }
  L00766d45: { // 0x766d45: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00766d47: { // 0x766d47: c6040801 MOV byte ptr [EAX + ECX*0x1],0x1
    m.w8((s.ax+(s.cx * 0x00000001u)), 0x00000001u);
  }
  L00766d4b: { // 0x766d4b: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00766d4d: { // 0x766d4d: f7b69c000000 DIV dword ptr [ESI + 0x9c]
    const auto divisor=m.r32((s.si+0x0000009cu));const std::uint64_t dividend=(std::uint64_t(s.dx)<<32)|s.ax;if(!divisor||dividend/divisor>0xffffffffull)throw std::domain_error("826 DIV overflow");s.ax=std::uint32_t(dividend/divisor);s.dx=std::uint32_t(dividend%divisor);
  }
  L00766d53: { // 0x766d53: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00766d54: { // 0x766d54: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00766d56: { // 0x766d56: 72e7 JC 0x00766d3f
    if(integer::condition("JC",flags)) goto L00766d3f;
  }
  L00766d58: { // 0x766d58: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766d59: { // 0x766d59: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00766d5c: { // 0x766d5c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766d5d: { // 0x766d5d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766d5e: { // 0x766d5e: 8b8ea8070000 MOV ECX,dword ptr [ESI + 0x7a8]
    s.cx = m.r32((s.si+0x000007a8u));
  }
  L00766d64: { // 0x766d64: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766d65: { // 0x766d65: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00766d66: { // 0x766d66: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766d68: { // 0x766d68: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766d69: { // 0x766d69: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7761260u); flags=s.arithmetic_flags;
  }
  L00766d6c: { // 0x766d6c: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766d6f: { // 0x766d6f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766d71: { // 0x766d71: 7408 JZ 0x00766d7b
    if(integer::condition("JZ",flags)) goto L00766d7b;
  }
  L00766d73: { // 0x766d73: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766d74: { // 0x766d74: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766d79: { // 0x766d79: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766d7a: { // 0x766d7a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766d7b: { // 0x766d7b: 89beb0070000 MOV dword ptr [ESI + 0x7b0],EDI
    m.w32((s.si+0x000007b0u), s.di);
  }
  L00766d81: { // 0x766d81: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766d82: { // 0x766d82: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00766d85: { // 0x766d85: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766d86: { // 0x766d86: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766d87: { // 0x766d87: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766d88: { // 0x766d88: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00766d8a: { // 0x766d8a: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  L00766d8c: { // 0x766d8c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766d8d: { // 0x766d8d: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7761296u); flags=s.arithmetic_flags;
  }
  L00766d90: { // 0x766d90: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766d93: { // 0x766d93: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00766d95: { // 0x766d95: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L00766d97: { // 0x766d97: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766d98: { // 0x766d98: 24fb AND AL,0xfb
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fbu),8,flags));
  }
  L00766d9a: { // 0x766d9a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766d9b: { // 0x766d9b: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00766d9c: { // 0x766d9c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00766da0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00766da0: { // 0x766da0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00766da1: { // 0x766da1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00766da2: { // 0x766da2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766da3: { // 0x766da3: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00766da5: { // 0x766da5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766da6: { // 0x766da6: 8d7a01 LEA EDI,[EDX + 0x1]
    s.di = (s.dx+0x00000001u);
  }
  L00766da9: { // 0x766da9: 8a8684000000 MOV AL,byte ptr [ESI + 0x84]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000084u)));
  }
  L00766daf: { // 0x766daf: 83e7fe AND EDI,0xfffffffe
    s.di = integer::logical((s.di)&(0xfffffffeu),32,flags);
  }
  L00766db2: { // 0x766db2: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00766db4: { // 0x766db4: 0f8489010000 JZ 0x00766f43
    if(integer::condition("JZ",flags)) goto L00766f43;
  }
  L00766dba: { // 0x766dba: 8b868c070000 MOV EAX,dword ptr [ESI + 0x78c]
    s.ax = m.r32((s.si+0x0000078cu));
  }
  L00766dc0: { // 0x766dc0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766dc2: { // 0x766dc2: 0f847b010000 JZ 0x00766f43
    if(integer::condition("JZ",flags)) goto L00766f43;
  }
  L00766dc8: { // 0x766dc8: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L00766dcc: { // 0x766dcc: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00766dce: { // 0x766dce: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766dcf: { // 0x766dcf: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766dd1: { // 0x766dd1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766dd2: { // 0x766dd2: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7761365u); flags=s.arithmetic_flags;
  }
  L00766dd5: { // 0x766dd5: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766dd8: { // 0x766dd8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766dda: { // 0x766dda: 740a JZ 0x00766de6
    if(integer::condition("JZ",flags)) goto L00766de6;
  }
  L00766ddc: { // 0x766ddc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766ddd: { // 0x766ddd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766dde: { // 0x766dde: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766de3: { // 0x766de3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766de4: { // 0x766de4: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00766de5: { // 0x766de5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766de6: { // 0x766de6: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00766dea: { // 0x766dea: 8b86b4070000 MOV EAX,dword ptr [ESI + 0x7b4]
    s.ax = m.r32((s.si+0x000007b4u));
  }
  L00766df0: { // 0x766df0: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00766df2: { // 0x766df2: 83ef04 SUB EDI,0x4
    s.di = integer::sub(s.di,0x00000004u,32,flags);
  }
  L00766df5: { // 0x766df5: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L00766dfb: { // 0x766dfb: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00766dfd: { // 0x766dfd: 0f86c4000000 JBE 0x00766ec7
    if(integer::condition("JBE",flags)) goto L00766ec7;
  }
  L00766e03: { // 0x766e03: 8b9690070000 MOV EDX,dword ptr [ESI + 0x790]
    s.dx = m.r32((s.si+0x00000790u));
  }
  L00766e09: { // 0x766e09: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00766e0b: { // 0x766e0b: 0f85b6000000 JNZ 0x00766ec7
    if(integer::condition("JNZ",flags)) goto L00766ec7;
  }
  L00766e11: { // 0x766e11: 663b4c240e CMP CX,word ptr [ESP + 0xe]
    (void)integer::sub((s.cx & 0xffffu),m.r16((f.sp+0x0000000eu)),16,flags);
  }
  L00766e16: { // 0x766e16: 751f JNZ 0x00766e37
    if(integer::condition("JNZ",flags)) goto L00766e37;
  }
  L00766e18: { // 0x766e18: 8b868c070000 MOV EAX,dword ptr [ESI + 0x78c]
    s.ax = m.r32((s.si+0x0000078cu));
  }
  L00766e1e: { // 0x766e1e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766e1f: { // 0x766e1f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766e20: { // 0x766e20: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766e22: { // 0x766e22: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766e23: { // 0x766e23: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7761446u); flags=s.arithmetic_flags;
  }
  L00766e26: { // 0x766e26: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766e29: { // 0x766e29: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766e2b: { // 0x766e2b: 744e JZ 0x00766e7b
    if(integer::condition("JZ",flags)) goto L00766e7b;
  }
  L00766e2d: { // 0x766e2d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766e2e: { // 0x766e2e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766e2f: { // 0x766e2f: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766e34: { // 0x766e34: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766e35: { // 0x766e35: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00766e36: { // 0x766e36: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766e37: { // 0x766e37: 8b9e98000000 MOV EBX,dword ptr [ESI + 0x98]
    s.bx = m.r32((s.si+0x00000098u));
  }
  L00766e3d: { // 0x766e3d: 8b868c070000 MOV EAX,dword ptr [ESI + 0x78c]
    s.ax = m.r32((s.si+0x0000078cu));
  }
  L00766e43: { // 0x766e43: 2bdf SUB EBX,EDI
    s.bx = integer::sub(s.bx,s.di,32,flags);
  }
  L00766e45: { // 0x766e45: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766e46: { // 0x766e46: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L00766e48: { // 0x766e48: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00766e49: { // 0x766e49: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766e4b: { // 0x766e4b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766e4c: { // 0x766e4c: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7761487u); flags=s.arithmetic_flags;
  }
  L00766e4f: { // 0x766e4f: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766e52: { // 0x766e52: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766e54: { // 0x766e54: 740a JZ 0x00766e60
    if(integer::condition("JZ",flags)) goto L00766e60;
  }
  L00766e56: { // 0x766e56: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766e57: { // 0x766e57: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766e58: { // 0x766e58: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766e5d: { // 0x766e5d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766e5e: { // 0x766e5e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00766e5f: { // 0x766e5f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766e60: { // 0x766e60: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00766e64: { // 0x766e64: 8b968c070000 MOV EDX,dword ptr [ESI + 0x78c]
    s.dx = m.r32((s.si+0x0000078cu));
  }
  L00766e6a: { // 0x766e6a: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  L00766e70: { // 0x766e70: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00766e71: { // 0x766e71: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00766e72: { // 0x766e72: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00766e73: { // 0x766e73: e8f85b0000 CALL 0x0076ca70
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ca70u,7761528u); flags=s.arithmetic_flags;
  }
  L00766e78: { // 0x766e78: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00766e7b: { // 0x766e7b: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00766e7f: { // 0x766e7f: 8bbe90070000 MOV EDI,dword ptr [ESI + 0x790]
    s.di = m.r32((s.si+0x00000790u));
  }
  L00766e85: { // 0x766e85: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L00766e8a: { // 0x766e8a: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00766e8c: { // 0x766e8c: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L00766e8e: { // 0x766e8e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00766e8f: { // 0x766e8f: 89be90070000 MOV dword ptr [ESI + 0x790],EDI
    m.w32((s.si+0x00000790u), s.di);
  }
  L00766e95: { // 0x766e95: f7be9c000000 IDIV dword ptr [ESI + 0x9c]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.si+0x0000009cu)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00766e9b: { // 0x766e9b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766e9d: { // 0x766e9d: 7e20 JLE 0x00766ebf
    if(integer::condition("JLE",flags)) goto L00766ebf;
  }
  L00766e9f: { // 0x766e9f: 8b8694070000 MOV EAX,dword ptr [ESI + 0x794]
    s.ax = m.r32((s.si+0x00000794u));
  }
  L00766ea5: { // 0x766ea5: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00766ea6: { // 0x766ea6: c64408ff01 MOV byte ptr [EAX + ECX*0x1 + -0x1],0x1
    m.w8((s.ax+(s.cx * 0x00000001u)-0x00000001u), 0x00000001u);
  }
  L00766eab: { // 0x766eab: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00766eaf: { // 0x766eaf: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L00766eb4: { // 0x766eb4: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00766eb5: { // 0x766eb5: f7be9c000000 IDIV dword ptr [ESI + 0x9c]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.si+0x0000009cu)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00766ebb: { // 0x766ebb: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00766ebd: { // 0x766ebd: 7ce0 JL 0x00766e9f
    if(integer::condition("JL",flags)) goto L00766e9f;
  }
  L00766ebf: { // 0x766ebf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766ec0: { // 0x766ec0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766ec1: { // 0x766ec1: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00766ec4: { // 0x766ec4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766ec5: { // 0x766ec5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00766ec6: { // 0x766ec6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766ec7: { // 0x766ec7: 663b4c240e CMP CX,word ptr [ESP + 0xe]
    (void)integer::sub((s.cx & 0xffffu),m.r16((f.sp+0x0000000eu)),16,flags);
  }
  L00766ecc: { // 0x766ecc: 751f JNZ 0x00766eed
    if(integer::condition("JNZ",flags)) goto L00766eed;
  }
  L00766ece: { // 0x766ece: 8b8ea8070000 MOV ECX,dword ptr [ESI + 0x7a8]
    s.cx = m.r32((s.si+0x000007a8u));
  }
  L00766ed4: { // 0x766ed4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766ed5: { // 0x766ed5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00766ed6: { // 0x766ed6: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766ed8: { // 0x766ed8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766ed9: { // 0x766ed9: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7761628u); flags=s.arithmetic_flags;
  }
  L00766edc: { // 0x766edc: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766edf: { // 0x766edf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766ee1: { // 0x766ee1: 7448 JZ 0x00766f2b
    if(integer::condition("JZ",flags)) goto L00766f2b;
  }
  L00766ee3: { // 0x766ee3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766ee4: { // 0x766ee4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766ee5: { // 0x766ee5: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766eea: { // 0x766eea: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766eeb: { // 0x766eeb: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00766eec: { // 0x766eec: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766eed: { // 0x766eed: 8b9ea8070000 MOV EBX,dword ptr [ESI + 0x7a8]
    s.bx = m.r32((s.si+0x000007a8u));
  }
  L00766ef3: { // 0x766ef3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766ef4: { // 0x766ef4: 2bdf SUB EBX,EDI
    s.bx = integer::sub(s.bx,s.di,32,flags);
  }
  L00766ef6: { // 0x766ef6: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L00766ef8: { // 0x766ef8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00766ef9: { // 0x766ef9: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766efb: { // 0x766efb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766efc: { // 0x766efc: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7761663u); flags=s.arithmetic_flags;
  }
  L00766eff: { // 0x766eff: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766f02: { // 0x766f02: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766f04: { // 0x766f04: 740a JZ 0x00766f10
    if(integer::condition("JZ",flags)) goto L00766f10;
  }
  L00766f06: { // 0x766f06: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766f07: { // 0x766f07: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766f08: { // 0x766f08: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766f0d: { // 0x766f0d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766f0e: { // 0x766f0e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00766f0f: { // 0x766f0f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766f10: { // 0x766f10: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L00766f14: { // 0x766f14: 8b86a8070000 MOV EAX,dword ptr [ESI + 0x7a8]
    s.ax = m.r32((s.si+0x000007a8u));
  }
  L00766f1a: { // 0x766f1a: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L00766f20: { // 0x766f20: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00766f21: { // 0x766f21: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766f22: { // 0x766f22: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00766f23: { // 0x766f23: e8485b0000 CALL 0x0076ca70
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ca70u,7761704u); flags=s.arithmetic_flags;
  }
  L00766f28: { // 0x766f28: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00766f2b: { // 0x766f2b: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00766f2f: { // 0x766f2f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766f30: { // 0x766f30: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  L00766f36: { // 0x766f36: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00766f39: { // 0x766f39: 898eb0070000 MOV dword ptr [ESI + 0x7b0],ECX
    m.w32((s.si+0x000007b0u), s.cx);
  }
  L00766f3f: { // 0x766f3f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766f40: { // 0x766f40: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766f41: { // 0x766f41: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00766f42: { // 0x766f42: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766f43: { // 0x766f43: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766f44: { // 0x766f44: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00766f46: { // 0x766f46: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  L00766f48: { // 0x766f48: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766f49: { // 0x766f49: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7761740u); flags=s.arithmetic_flags;
  }
  L00766f4c: { // 0x766f4c: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766f4f: { // 0x766f4f: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00766f51: { // 0x766f51: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L00766f53: { // 0x766f53: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766f54: { // 0x766f54: 24fb AND AL,0xfb
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fbu),8,flags));
  }
  L00766f56: { // 0x766f56: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766f57: { // 0x766f57: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00766f58: { // 0x766f58: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766f59: { // 0x766f59: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00766f5a: { // 0x766f5a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
