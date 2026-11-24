#include "recovered/recovery_b837_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b837 {
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
    default:throw std::domain_error("recovery837 unsupported switch destination");}
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
default:throw std::domain_error("recovery837 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_007635d0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L007635d0: { // 0x7635d0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L007635d3: { // 0x7635d3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007635d4: { // 0x7635d4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007635d5: { // 0x7635d5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007635d6: { // 0x7635d6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L007635d8: { // 0x7635d8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007635d9: { // 0x7635d9: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L007635dd: { // 0x7635dd: 8baea0010000 MOV EBP,dword ptr [ESI + 0x1a0]
    s.bp = m.r32((s.si+0x000001a0u));
  }
  L007635e3: { // 0x7635e3: 8d9ea0010000 LEA EBX,[ESI + 0x1a0]
    s.bx = (s.si+0x000001a0u);
  }
  L007635e9: { // 0x7635e9: 8d7e40 LEA EDI,[ESI + 0x40]
    s.di = (s.si+0x00000040u);
  }
  L007635ec: { // 0x7635ec: f6451401 TEST byte ptr [EBP + 0x14],0x1
    (void)integer::logical((m.r8((s.bp+0x00000014u)))&(0x00000001u),8,flags);
  }
  L007635f0: { // 0x7635f0: 7555 JNZ 0x00763647
    if(integer::condition("JNZ",flags)) goto L00763647;
  }
  L007635f2: { // 0x7635f2: 8b8b38050000 MOV ECX,dword ptr [EBX + 0x538]
    s.cx = m.r32((s.bx+0x00000538u));
  }
  L007635f8: { // 0x7635f8: 8a4304 MOV AL,byte ptr [EBX + 0x4]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000004u)));
  }
  L007635fb: { // 0x7635fb: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L007635fc: { // 0x7635fc: a804 TEST AL,0x4
    (void)integer::logical(((s.ax & 0xffu))&(0x00000004u),8,flags);
  }
  L007635fe: { // 0x7635fe: 898b38050000 MOV dword ptr [EBX + 0x538],ECX
    m.w32((s.bx+0x00000538u), s.cx);
  }
  L00763604: { // 0x763604: 0f8452030000 JZ 0x0076395c
    if(integer::condition("JZ",flags)) goto L0076395c;
  }
  L0076360a: { // 0x76360a: f6865001000004 TEST byte ptr [ESI + 0x150],0x4
    (void)integer::logical((m.r8((s.si+0x00000150u)))&(0x00000004u),8,flags);
  }
  L00763611: { // 0x763611: 0f8545030000 JNZ 0x0076395c
    if(integer::condition("JNZ",flags)) goto L0076395c;
  }
  L00763617: { // 0x763617: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00763619: { // 0x763619: 8b4010 MOV EAX,dword ptr [EAX + 0x10]
    s.ax = m.r32((s.ax+0x00000010u));
  }
  L0076361c: { // 0x76361c: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L0076361e: { // 0x76361e: 8b4818 MOV ECX,dword ptr [EAX + 0x18]
    s.cx = m.r32((s.ax+0x00000018u));
  }
  L00763621: { // 0x763621: 894814 MOV dword ptr [EAX + 0x14],ECX
    m.w32((s.ax+0x00000014u), s.cx);
  }
  L00763624: { // 0x763624: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L00763627: { // 0x763627: a810 TEST AL,0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L00763629: { // 0x763629: 0f84e0020000 JZ 0x0076390f
    if(integer::condition("JZ",flags)) goto L0076390f;
  }
  L0076362f: { // 0x76362f: 0c08 OR AL,0x8
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000008u),8,flags));
  }
  L00763631: { // 0x763631: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763632: { // 0x763632: 894304 MOV dword ptr [EBX + 0x4],EAX
    m.w32((s.bx+0x00000004u), s.ax);
  }
  L00763635: { // 0x763635: 8b4514 MOV EAX,dword ptr [EBP + 0x14]
    s.ax = m.r32((s.bp+0x00000014u));
  }
  L00763638: { // 0x763638: 0c80 OR AL,0x80
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000080u),8,flags));
  }
  L0076363a: { // 0x76363a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076363b: { // 0x76363b: 894514 MOV dword ptr [EBP + 0x14],EAX
    m.w32((s.bp+0x00000014u), s.ax);
  }
  L0076363e: { // 0x76363e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076363f: { // 0x76363f: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00763642: { // 0x763642: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00763643: { // 0x763643: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00763646: { // 0x763646: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00763647: { // 0x763647: f6430410 TEST byte ptr [EBX + 0x4],0x10
    (void)integer::logical((m.r8((s.bx+0x00000004u)))&(0x00000010u),8,flags);
  }
  L0076364b: { // 0x76364b: 7427 JZ 0x00763674
    if(integer::condition("JZ",flags)) goto L00763674;
  }
  L0076364d: { // 0x76364d: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0076364f: { // 0x76364f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763650: { // 0x763650: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763651: { // 0x763651: 8b421c MOV EAX,dword ptr [EDX + 0x1c]
    s.ax = m.r32((s.dx+0x0000001cu));
  }
  L00763654: { // 0x763654: 898330050000 MOV dword ptr [EBX + 0x530],EAX
    m.w32((s.bx+0x00000530u), s.ax);
  }
  L0076365a: { // 0x76365a: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L0076365d: { // 0x76365d: 83c908 OR ECX,0x8
    s.cx = integer::logical((s.cx)|(0x00000008u),32,flags);
  }
  L00763660: { // 0x763660: 894b04 MOV dword ptr [EBX + 0x4],ECX
    m.w32((s.bx+0x00000004u), s.cx);
  }
  L00763663: { // 0x763663: 8b4514 MOV EAX,dword ptr [EBP + 0x14]
    s.ax = m.r32((s.bp+0x00000014u));
  }
  L00763666: { // 0x763666: 0c80 OR AL,0x80
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000080u),8,flags));
  }
  L00763668: { // 0x763668: 894514 MOV dword ptr [EBP + 0x14],EAX
    m.w32((s.bp+0x00000014u), s.ax);
  }
  L0076366b: { // 0x76366b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076366c: { // 0x76366c: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0076366f: { // 0x76366f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00763670: { // 0x763670: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00763673: { // 0x763673: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00763674: { // 0x763674: f6474402 TEST byte ptr [EDI + 0x44],0x2
    (void)integer::logical((m.r8((s.di+0x00000044u)))&(0x00000002u),8,flags);
  }
  L00763678: { // 0x763678: 742e JZ 0x007636a8
    if(integer::condition("JZ",flags)) goto L007636a8;
  }
  L0076367a: { // 0x76367a: 8b4d1c MOV ECX,dword ptr [EBP + 0x1c]
    s.cx = m.r32((s.bp+0x0000001cu));
  }
  L0076367d: { // 0x76367d: 898b30050000 MOV dword ptr [EBX + 0x530],ECX
    m.w32((s.bx+0x00000530u), s.cx);
  }
  L00763683: { // 0x763683: 8b6d1c MOV EBP,dword ptr [EBP + 0x1c]
    s.bp = m.r32((s.bp+0x0000001cu));
  }
  L00763686: { // 0x763686: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00763688: { // 0x763688: 8d446d00 LEA EAX,[EBP + EBP*0x2]
    s.ax = (s.bp+(s.bp * 0x00000002u));
  }
  L0076368c: { // 0x76368c: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0076368f: { // 0x76368f: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L00763692: { // 0x763692: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00763693: { // 0x763693: f77f34 IDIV dword ptr [EDI + 0x34]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.di+0x00000034u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00763696: { // 0x763696: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00763698: { // 0x763698: e8c34d0000 CALL 0x00768460
    s.arithmetic_flags=flags; invoke(m,s,f,0x00768460u,7747229u); flags=s.arithmetic_flags;
  }
  L0076369d: { // 0x76369d: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L007636a0: { // 0x7636a0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007636a1: { // 0x7636a1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007636a2: { // 0x7636a2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007636a3: { // 0x7636a3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007636a4: { // 0x7636a4: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L007636a7: { // 0x7636a7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007636a8: { // 0x7636a8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L007636aa: { // 0x7636aa: e8014e0000 CALL 0x007684b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007684b0u,7747247u); flags=s.arithmetic_flags;
  }
  L007636af: { // 0x7636af: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L007636b1: { // 0x7636b1: 8a4304 MOV AL,byte ptr [EBX + 0x4]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000004u)));
  }
  L007636b4: { // 0x7636b4: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L007636b6: { // 0x7636b6: 8b8330050000 MOV EAX,dword ptr [EBX + 0x530]
    s.ax = m.r32((s.bx+0x00000530u));
  }
  L007636bc: { // 0x7636bc: 7503 JNZ 0x007636c1
    if(integer::condition("JNZ",flags)) goto L007636c1;
  }
  L007636be: { // 0x7636be: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L007636bf: { // 0x7636bf: eb03 JMP 0x007636c4
    goto L007636c4;
  }
  L007636c1: { // 0x7636c1: 83c002 ADD EAX,0x2
    s.ax = integer::add(s.ax,0x00000002u,32,flags);
  }
  L007636c4: { // 0x7636c4: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L007636c7: { // 0x7636c7: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L007636ca: { // 0x7636ca: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L007636cd: { // 0x7636cd: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L007636ce: { // 0x7636ce: f77f34 IDIV dword ptr [EDI + 0x34]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.di+0x00000034u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L007636d1: { // 0x7636d1: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L007636d3: { // 0x7636d3: 7d6c JGE 0x00763741
    if(integer::condition("JGE",flags)) goto L00763741;
  }
  L007636d5: { // 0x7636d5: f6430404 TEST byte ptr [EBX + 0x4],0x4
    (void)integer::logical((m.r8((s.bx+0x00000004u)))&(0x00000004u),8,flags);
  }
  L007636d9: { // 0x7636d9: 7459 JZ 0x00763734
    if(integer::condition("JZ",flags)) goto L00763734;
  }
  L007636db: { // 0x7636db: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007636dc: { // 0x7636dc: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007636dd: { // 0x7636dd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007636de: { // 0x7636de: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L007636e0: { // 0x7636e0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L007636e2: { // 0x7636e2: e889020000 CALL 0x00763970
    s.arithmetic_flags=flags; invoke(m,s,f,0x00763970u,7747303u); flags=s.arithmetic_flags;
  }
  L007636e7: { // 0x7636e7: 8b9330050000 MOV EDX,dword ptr [EBX + 0x530]
    s.dx = m.r32((s.bx+0x00000530u));
  }
  L007636ed: { // 0x7636ed: b980000000 MOV ECX,0x80
    s.cx = 0x00000080u;
  }
  L007636f2: { // 0x7636f2: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L007636f4: { // 0x7636f4: 7519 JNZ 0x0076370f
    if(integer::condition("JNZ",flags)) goto L0076370f;
  }
  L007636f6: { // 0x7636f6: 844d14 TEST byte ptr [EBP + 0x14],CL
    (void)integer::logical((m.r8((s.bp+0x00000014u)))&((s.cx & 0xffu)),8,flags);
  }
  L007636f9: { // 0x7636f9: 7414 JZ 0x0076370f
    if(integer::condition("JZ",flags)) goto L0076370f;
  }
  L007636fb: { // 0x7636fb: 8b551c MOV EDX,dword ptr [EBP + 0x1c]
    s.dx = m.r32((s.bp+0x0000001cu));
  }
  L007636fe: { // 0x7636fe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007636ff: { // 0x7636ff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763700: { // 0x763700: 899330050000 MOV dword ptr [EBX + 0x530],EDX
    m.w32((s.bx+0x00000530u), s.dx);
  }
  L00763706: { // 0x763706: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00763707: { // 0x763707: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0076370a: { // 0x76370a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076370b: { // 0x76370b: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076370e: { // 0x76370e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0076370f: { // 0x76370f: 8b5304 MOV EDX,dword ptr [EBX + 0x4]
    s.dx = m.r32((s.bx+0x00000004u));
  }
  L00763712: { // 0x763712: 8b451c MOV EAX,dword ptr [EBP + 0x1c]
    s.ax = m.r32((s.bp+0x0000001cu));
  }
  L00763715: { // 0x763715: 83ca08 OR EDX,0x8
    s.dx = integer::logical((s.dx)|(0x00000008u),32,flags);
  }
  L00763718: { // 0x763718: 898330050000 MOV dword ptr [EBX + 0x530],EAX
    m.w32((s.bx+0x00000530u), s.ax);
  }
  L0076371e: { // 0x76371e: 895304 MOV dword ptr [EBX + 0x4],EDX
    m.w32((s.bx+0x00000004u), s.dx);
  }
  L00763721: { // 0x763721: 8b4514 MOV EAX,dword ptr [EBP + 0x14]
    s.ax = m.r32((s.bp+0x00000014u));
  }
  L00763724: { // 0x763724: 0bc1 OR EAX,ECX
    s.ax = integer::logical((s.ax)|(s.cx),32,flags);
  }
  L00763726: { // 0x763726: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763727: { // 0x763727: 894514 MOV dword ptr [EBP + 0x14],EAX
    m.w32((s.bp+0x00000014u), s.ax);
  }
  L0076372a: { // 0x76372a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076372b: { // 0x76372b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076372c: { // 0x76372c: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0076372f: { // 0x76372f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00763730: { // 0x763730: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00763733: { // 0x763733: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00763734: { // 0x763734: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763735: { // 0x763735: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763736: { // 0x763736: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00763737: { // 0x763737: b8f6ffffff MOV EAX,0xfffffff6
    s.ax = 0xfffffff6u;
  }
  L0076373c: { // 0x76373c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076373d: { // 0x76373d: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00763740: { // 0x763740: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00763741: { // 0x763741: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00763742: { // 0x763742: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00763743: { // 0x763743: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00763744: { // 0x763744: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00763746: { // 0x763746: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00763748: { // 0x763748: e823020000 CALL 0x00763970
    s.arithmetic_flags=flags; invoke(m,s,f,0x00763970u,7747405u); flags=s.arithmetic_flags;
  }
  L0076374d: { // 0x76374d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0076374f: { // 0x76374f: 8a4740 MOV AL,byte ptr [EDI + 0x40]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000040u)));
  }
  L00763752: { // 0x763752: a804 TEST AL,0x4
    (void)integer::logical(((s.ax & 0xffu))&(0x00000004u),8,flags);
  }
  L00763754: { // 0x763754: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00763758: { // 0x763758: 7416 JZ 0x00763770
    if(integer::condition("JZ",flags)) goto L00763770;
  }
  L0076375a: { // 0x76375a: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L0076375c: { // 0x76375c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076375d: { // 0x76375d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076375e: { // 0x76375e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076375f: { // 0x76375f: 8b511c MOV EDX,dword ptr [ECX + 0x1c]
    s.dx = m.r32((s.cx+0x0000001cu));
  }
  L00763762: { // 0x763762: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00763765: { // 0x763765: 899330050000 MOV dword ptr [EBX + 0x530],EDX
    m.w32((s.bx+0x00000530u), s.dx);
  }
  L0076376b: { // 0x76376b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076376c: { // 0x76376c: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076376f: { // 0x76376f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00763770: { // 0x763770: 8b7f30 MOV EDI,dword ptr [EDI + 0x30]
    s.di = m.r32((s.di+0x00000030u));
  }
  L00763773: { // 0x763773: b856555555 MOV EAX,0x55555556
    s.ax = 0x55555556u;
  }
  L00763778: { // 0x763778: f7ef IMUL EDI
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.di,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0076377a: { // 0x76377a: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0076377c: { // 0x76377c: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0076377f: { // 0x76377f: 8d5402ff LEA EDX,[EDX + EAX*0x1 + -0x1]
    s.dx = (s.dx+(s.ax * 0x00000001u)-0x00000001u);
  }
  L00763783: { // 0x763783: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00763785: { // 0x763785: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00763789: { // 0x763789: 7d08 JGE 0x00763793
    if(integer::condition("JGE",flags)) goto L00763793;
  }
  L0076378b: { // 0x76378b: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L00763793: { // 0x763793: 394d1c CMP dword ptr [EBP + 0x1c],ECX
    (void)integer::sub(m.r32((s.bp+0x0000001cu)),s.cx,32,flags);
  }
  L00763796: { // 0x763796: 0f8468010000 JZ 0x00763904
    if(integer::condition("JZ",flags)) goto L00763904;
  }
  L0076379c: { // 0x76379c: f6451402 TEST byte ptr [EBP + 0x14],0x2
    (void)integer::logical((m.r8((s.bp+0x00000014u)))&(0x00000002u),8,flags);
  }
  L007637a0: { // 0x7637a0: 0f855e010000 JNZ 0x00763904
    if(integer::condition("JNZ",flags)) goto L00763904;
  }
  L007637a6: { // 0x7637a6: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L007637a8: { // 0x7637a8: 8b8e40010000 MOV ECX,dword ptr [ESI + 0x140]
    s.cx = m.r32((s.si+0x00000140u));
  }
  L007637ae: { // 0x7637ae: 8b781c MOV EDI,dword ptr [EAX + 0x1c]
    s.di = m.r32((s.ax+0x0000001cu));
  }
  L007637b1: { // 0x7637b1: 8b8330050000 MOV EAX,dword ptr [EBX + 0x530]
    s.ax = m.r32((s.bx+0x00000530u));
  }
  L007637b7: { // 0x7637b7: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L007637b9: { // 0x7637b9: 7c08 JL 0x007637c3
    if(integer::condition("JL",flags)) goto L007637c3;
  }
  L007637bb: { // 0x7637bb: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L007637bd: { // 0x7637bd: 7f04 JG 0x007637c3
    if(integer::condition("JG",flags)) goto L007637c3;
  }
  L007637bf: { // 0x7637bf: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L007637c1: { // 0x7637c1: eb2f JMP 0x007637f2
    goto L007637f2;
  }
  L007637c3: { // 0x7637c3: 8b5670 MOV EDX,dword ptr [ESI + 0x70]
    s.dx = m.r32((s.si+0x00000070u));
  }
  L007637c6: { // 0x7637c6: b856555555 MOV EAX,0x55555556
    s.ax = 0x55555556u;
  }
  L007637cb: { // 0x7637cb: f7ea IMUL EDX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.dx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L007637cd: { // 0x7637cd: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L007637cf: { // 0x7637cf: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L007637d2: { // 0x7637d2: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L007637d4: { // 0x7637d4: 8b8330050000 MOV EAX,dword ptr [EBX + 0x530]
    s.ax = m.r32((s.bx+0x00000530u));
  }
  L007637da: { // 0x7637da: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L007637dc: { // 0x7637dc: 7904 JNS 0x007637e2
    if(integer::condition("JNS",flags)) goto L007637e2;
  }
  L007637de: { // 0x7637de: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L007637e0: { // 0x7637e0: eb10 JMP 0x007637f2
    goto L007637f2;
  }
  L007637e2: { // 0x7637e2: 2bbe28010000 SUB EDI,dword ptr [ESI + 0x128]
    s.di = integer::sub(s.di,m.r32((s.si+0x00000128u)),32,flags);
  }
  L007637e8: { // 0x7637e8: 7904 JNS 0x007637ee
    if(integer::condition("JNS",flags)) goto L007637ee;
  }
  L007637ea: { // 0x7637ea: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L007637ec: { // 0x7637ec: eb04 JMP 0x007637f2
    goto L007637f2;
  }
  L007637ee: { // 0x7637ee: 8d7c0f01 LEA EDI,[EDI + ECX*0x1 + 0x1]
    s.di = (s.di+(s.cx * 0x00000001u)+0x00000001u);
  }
  L007637f2: { // 0x7637f2: 3b7c2410 CMP EDI,dword ptr [ESP + 0x10]
    (void)integer::sub(s.di,m.r32((f.sp+0x00000010u)),32,flags);
  }
  L007637f6: { // 0x7637f6: 0f8f08010000 JG 0x00763904
    if(integer::condition("JG",flags)) goto L00763904;
  }
  L007637fc: { // 0x7637fc: 8b4514 MOV EAX,dword ptr [EBP + 0x14]
    s.ax = m.r32((s.bp+0x00000014u));
  }
  L007637ff: { // 0x7637ff: a804 TEST AL,0x4
    (void)integer::logical(((s.ax & 0xffu))&(0x00000004u),8,flags);
  }
  L00763801: { // 0x763801: 7451 JZ 0x00763854
    if(integer::condition("JZ",flags)) goto L00763854;
  }
  L00763803: { // 0x763803: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00763805: { // 0x763805: 7424 JZ 0x0076382b
    if(integer::condition("JZ",flags)) goto L0076382b;
  }
  L00763807: { // 0x763807: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0076380a: { // 0x76380a: 8b8e70070000 MOV ECX,dword ptr [ESI + 0x770]
    s.cx = m.r32((s.si+0x00000770u));
  }
  L00763810: { // 0x763810: 8b5524 MOV EDX,dword ptr [EBP + 0x24]
    s.dx = m.r32((s.bp+0x00000024u));
  }
  L00763813: { // 0x763813: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00763814: { // 0x763814: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00763816: { // 0x763816: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00763817: { // 0x763817: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00763818: { // 0x763818: e80e950000 CALL 0x0076cd2b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076cd2bu,7747613u); flags=s.arithmetic_flags;
  }
  L0076381d: { // 0x76381d: 894528 MOV dword ptr [EBP + 0x28],EAX
    m.w32((s.bp+0x00000028u), s.ax);
  }
  L00763820: { // 0x763820: 8b4514 MOV EAX,dword ptr [EBP + 0x14]
    s.ax = m.r32((s.bp+0x00000014u));
  }
  L00763823: { // 0x763823: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00763826: { // 0x763826: 24f7 AND AL,0xf7
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000f7u),8,flags));
  }
  L00763828: { // 0x763828: 894514 MOV dword ptr [EBP + 0x14],EAX
    m.w32((s.bp+0x00000014u), s.ax);
  }
  L0076382b: { // 0x76382b: 8b4d28 MOV ECX,dword ptr [EBP + 0x28]
    s.cx = m.r32((s.bp+0x00000028u));
  }
  L0076382e: { // 0x76382e: 8b7508 MOV ESI,dword ptr [EBP + 0x8]
    s.si = m.r32((s.bp+0x00000008u));
  }
  L00763831: { // 0x763831: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00763833: { // 0x763833: 8d7b24 LEA EDI,[EBX + 0x24]
    s.di = (s.bx+0x00000024u);
  }
  L00763836: { // 0x763836: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L00763839: { // 0x763839: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0076383b: { // 0x76383b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0076383d: { // 0x76383d: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L00763840: { // 0x763840: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L00763842: { // 0x763842: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L00763845: { // 0x763845: 8b4d28 MOV ECX,dword ptr [EBP + 0x28]
    s.cx = m.r32((s.bp+0x00000028u));
  }
  L00763848: { // 0x763848: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0076384c: { // 0x76384c: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L0076384e: { // 0x76384e: 894b20 MOV dword ptr [EBX + 0x20],ECX
    m.w32((s.bx+0x00000020u), s.cx);
  }
  L00763851: { // 0x763851: 894304 MOV dword ptr [EBX + 0x4],EAX
    m.w32((s.bx+0x00000004u), s.ax);
  }
  L00763854: { // 0x763854: 8b4648 MOV EAX,dword ptr [ESI + 0x48]
    s.ax = m.r32((s.si+0x00000048u));
  }
  L00763857: { // 0x763857: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00763859: { // 0x763859: 7464 JZ 0x007638bf
    if(integer::condition("JZ",flags)) goto L007638bf;
  }
  L0076385b: { // 0x76385b: 8b4d14 MOV ECX,dword ptr [EBP + 0x14]
    s.cx = m.r32((s.bp+0x00000014u));
  }
  L0076385e: { // 0x76385e: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00763861: { // 0x763861: 741c JZ 0x0076387f
    if(integer::condition("JZ",flags)) goto L0076387f;
  }
  L00763863: { // 0x763863: 8b9620010000 MOV EDX,dword ptr [ESI + 0x120]
    s.dx = m.r32((s.si+0x00000120u));
  }
  L00763869: { // 0x763869: 8b4d1c MOV ECX,dword ptr [EBP + 0x1c]
    s.cx = m.r32((s.bp+0x0000001cu));
  }
  L0076386c: { // 0x76386c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0076386d: { // 0x76386d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0076386e: { // 0x76386e: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00763870: { // 0x763870: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00763871: { // 0x763871: ffd0 CALL EAX
    s.arithmetic_flags=flags; invoke(m,s,f,s.ax,7747699u); flags=s.arithmetic_flags;
  }
  L00763873: { // 0x763873: 8b4514 MOV EAX,dword ptr [EBP + 0x14]
    s.ax = m.r32((s.bp+0x00000014u));
  }
  L00763876: { // 0x763876: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00763879: { // 0x763879: 80e4fe AND AH,0xfe
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))&(0x000000feu),8,flags)) & 0xffu) << 8);
  }
  L0076387c: { // 0x76387c: 894514 MOV dword ptr [EBP + 0x14],EAX
    m.w32((s.bp+0x00000014u), s.ax);
  }
  L0076387f: { // 0x76387f: 8b4514 MOV EAX,dword ptr [EBP + 0x14]
    s.ax = m.r32((s.bp+0x00000014u));
  }
  L00763882: { // 0x763882: f6c402 TEST AH,0x2
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000002u),8,flags);
  }
  L00763885: { // 0x763885: 741d JZ 0x007638a4
    if(integer::condition("JZ",flags)) goto L007638a4;
  }
  L00763887: { // 0x763887: 8b9620010000 MOV EDX,dword ptr [ESI + 0x120]
    s.dx = m.r32((s.si+0x00000120u));
  }
  L0076388d: { // 0x76388d: 8b451c MOV EAX,dword ptr [EBP + 0x1c]
    s.ax = m.r32((s.bp+0x0000001cu));
  }
  L00763890: { // 0x763890: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00763891: { // 0x763891: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00763892: { // 0x763892: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00763894: { // 0x763894: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00763895: { // 0x763895: ff5648 CALL dword ptr [ESI + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000048u)),7747736u); flags=s.arithmetic_flags;
  }
  L00763898: { // 0x763898: 8b4514 MOV EAX,dword ptr [EBP + 0x14]
    s.ax = m.r32((s.bp+0x00000014u));
  }
  L0076389b: { // 0x76389b: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0076389e: { // 0x76389e: 80e4fd AND AH,0xfd
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))&(0x000000fdu),8,flags)) & 0xffu) << 8);
  }
  L007638a1: { // 0x7638a1: 894514 MOV dword ptr [EBP + 0x14],EAX
    m.w32((s.bp+0x00000014u), s.ax);
  }
  L007638a4: { // 0x7638a4: 8b4514 MOV EAX,dword ptr [EBP + 0x14]
    s.ax = m.r32((s.bp+0x00000014u));
  }
  L007638a7: { // 0x7638a7: f6c404 TEST AH,0x4
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000004u),8,flags);
  }
  L007638aa: { // 0x7638aa: 7413 JZ 0x007638bf
    if(integer::condition("JZ",flags)) goto L007638bf;
  }
  L007638ac: { // 0x7638ac: 8b551c MOV EDX,dword ptr [EBP + 0x1c]
    s.dx = m.r32((s.bp+0x0000001cu));
  }
  L007638af: { // 0x7638af: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L007638b1: { // 0x7638b1: e8cafaffff CALL 0x00763380
    s.arithmetic_flags=flags; invoke(m,s,f,0x00763380u,7747766u); flags=s.arithmetic_flags;
  }
  L007638b6: { // 0x7638b6: 8b4514 MOV EAX,dword ptr [EBP + 0x14]
    s.ax = m.r32((s.bp+0x00000014u));
  }
  L007638b9: { // 0x7638b9: 80e4fb AND AH,0xfb
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))&(0x000000fbu),8,flags)) & 0xffu) << 8);
  }
  L007638bc: { // 0x7638bc: 894514 MOV dword ptr [EBP + 0x14],EAX
    m.w32((s.bp+0x00000014u), s.ax);
  }
  L007638bf: { // 0x7638bf: 8b464c MOV EAX,dword ptr [ESI + 0x4c]
    s.ax = m.r32((s.si+0x0000004cu));
  }
  L007638c2: { // 0x7638c2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007638c4: { // 0x7638c4: 740f JZ 0x007638d5
    if(integer::condition("JZ",flags)) goto L007638d5;
  }
  L007638c6: { // 0x7638c6: 8b4d1c MOV ECX,dword ptr [EBP + 0x1c]
    s.cx = m.r32((s.bp+0x0000001cu));
  }
  L007638c9: { // 0x7638c9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007638ca: { // 0x7638ca: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L007638cc: { // 0x7638cc: ffd0 CALL EAX
    s.arithmetic_flags=flags; invoke(m,s,f,s.ax,7747790u); flags=s.arithmetic_flags;
  }
  L007638ce: { // 0x7638ce: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L007638d1: { // 0x7638d1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007638d3: { // 0x7638d3: 7545 JNZ 0x0076391a
    if(integer::condition("JNZ",flags)) goto L0076391a;
  }
  L007638d5: { // 0x7638d5: 8b5514 MOV EDX,dword ptr [EBP + 0x14]
    s.dx = m.r32((s.bp+0x00000014u));
  }
  L007638d8: { // 0x7638d8: c7451400000000 MOV dword ptr [EBP + 0x14],0x0
    m.w32((s.bp+0x00000014u), 0x00000000u);
  }
  L007638df: { // 0x7638df: 895518 MOV dword ptr [EBP + 0x18],EDX
    m.w32((s.bp+0x00000018u), s.dx);
  }
  L007638e2: { // 0x7638e2: 8b6d0c MOV EBP,dword ptr [EBP + 0xc]
    s.bp = m.r32((s.bp+0x0000000cu));
  }
  L007638e5: { // 0x7638e5: 892b MOV dword ptr [EBX],EBP
    m.w32((s.bx), s.bp);
  }
  L007638e7: { // 0x7638e7: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  L007638ea: { // 0x7638ea: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L007638eb: { // 0x7638eb: 894e1c MOV dword ptr [ESI + 0x1c],ECX
    m.w32((s.si+0x0000001cu), s.cx);
  }
  L007638ee: { // 0x7638ee: 8a4514 MOV AL,byte ptr [EBP + 0x14]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000014u)));
  }
  L007638f1: { // 0x7638f1: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L007638f3: { // 0x7638f3: 7432 JZ 0x00763927
    if(integer::condition("JZ",flags)) goto L00763927;
  }
  L007638f5: { // 0x7638f5: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L007638f9: { // 0x7638f9: 8b4d1c MOV ECX,dword ptr [EBP + 0x1c]
    s.cx = m.r32((s.bp+0x0000001cu));
  }
  L007638fc: { // 0x7638fc: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L007638fe: { // 0x7638fe: 0f8598feffff JNZ 0x0076379c
    if(integer::condition("JNZ",flags)) goto L0076379c;
  }
  L00763904: { // 0x763904: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00763906: { // 0x763906: 8b481c MOV ECX,dword ptr [EAX + 0x1c]
    s.cx = m.r32((s.ax+0x0000001cu));
  }
  L00763909: { // 0x763909: 898b30050000 MOV dword ptr [EBX + 0x530],ECX
    m.w32((s.bx+0x00000530u), s.cx);
  }
  L0076390f: { // 0x76390f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763910: { // 0x763910: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763911: { // 0x763911: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00763912: { // 0x763912: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00763915: { // 0x763915: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00763916: { // 0x763916: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00763919: { // 0x763919: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0076391a: { // 0x76391a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076391b: { // 0x76391b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076391c: { // 0x76391c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076391d: { // 0x76391d: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L00763922: { // 0x763922: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00763923: { // 0x763923: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00763926: { // 0x763926: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00763927: { // 0x763927: 8b8b38050000 MOV ECX,dword ptr [EBX + 0x538]
    s.cx = m.r32((s.bx+0x00000538u));
  }
  L0076392d: { // 0x76392d: 8a4304 MOV AL,byte ptr [EBX + 0x4]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000004u)));
  }
  L00763930: { // 0x763930: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00763931: { // 0x763931: a804 TEST AL,0x4
    (void)integer::logical(((s.ax & 0xffu))&(0x00000004u),8,flags);
  }
  L00763933: { // 0x763933: 898b38050000 MOV dword ptr [EBX + 0x538],ECX
    m.w32((s.bx+0x00000538u), s.cx);
  }
  L00763939: { // 0x763939: 7421 JZ 0x0076395c
    if(integer::condition("JZ",flags)) goto L0076395c;
  }
  L0076393b: { // 0x76393b: f6865001000004 TEST byte ptr [ESI + 0x150],0x4
    (void)integer::logical((m.r8((s.si+0x00000150u)))&(0x00000004u),8,flags);
  }
  L00763942: { // 0x763942: 7518 JNZ 0x0076395c
    if(integer::condition("JNZ",flags)) goto L0076395c;
  }
  L00763944: { // 0x763944: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L00763946: { // 0x763946: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00763947: { // 0x763947: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00763948: { // 0x763948: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00763949: { // 0x763949: 8b4110 MOV EAX,dword ptr [ECX + 0x10]
    s.ax = m.r32((s.cx+0x00000010u));
  }
  L0076394c: { // 0x76394c: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L0076394e: { // 0x76394e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076394f: { // 0x76394f: 8b5018 MOV EDX,dword ptr [EAX + 0x18]
    s.dx = m.r32((s.ax+0x00000018u));
  }
  L00763952: { // 0x763952: 895014 MOV dword ptr [EAX + 0x14],EDX
    m.w32((s.ax+0x00000014u), s.dx);
  }
  L00763955: { // 0x763955: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00763958: { // 0x763958: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076395b: { // 0x76395b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0076395c: { // 0x76395c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076395d: { // 0x76395d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076395e: { // 0x76395e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076395f: { // 0x76395f: b8f7ffffff MOV EAX,0xfffffff7
    s.ax = 0xfffffff7u;
  }
  L00763964: { // 0x763964: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00763965: { // 0x763965: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00763968: { // 0x763968: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00765e00(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00765e00: { // 0x765e00: 83ec40 SUB ESP,0x40
    f.sp = integer::sub(f.sp,0x00000040u,32,flags);
  }
  L00765e03: { // 0x765e03: 8d442438 LEA EAX,[ESP + 0x38]
    s.ax = (f.sp+0x00000038u);
  }
  L00765e07: { // 0x765e07: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00765e08: { // 0x765e08: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765e09: { // 0x765e09: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765e0a: { // 0x765e0a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00765e0b: { // 0x765e0b: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L00765e0d: { // 0x765e0d: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00765e0f: { // 0x765e0f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765e10: { // 0x765e10: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765e12: { // 0x765e12: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765e13: { // 0x765e13: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7757334u); flags=s.arithmetic_flags;
  }
  L00765e16: { // 0x765e16: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765e19: { // 0x765e19: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765e1b: { // 0x765e1b: 740d JZ 0x00765e2a
    if(integer::condition("JZ",flags)) goto L00765e2a;
  }
  L00765e1d: { // 0x765e1d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765e1e: { // 0x765e1e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765e1f: { // 0x765e1f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765e20: { // 0x765e20: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L00765e25: { // 0x765e25: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765e26: { // 0x765e26: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L00765e29: { // 0x765e29: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765e2a: { // 0x765e2a: 817c24484d464348 CMP dword ptr [ESP + 0x48],0x4843464d
    (void)integer::sub(m.r32((f.sp+0x00000048u)),0x4843464du,32,flags);
  }
  L00765e32: { // 0x765e32: 740d JZ 0x00765e41
    if(integer::condition("JZ",flags)) goto L00765e41;
  }
  L00765e34: { // 0x765e34: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765e35: { // 0x765e35: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765e36: { // 0x765e36: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765e37: { // 0x765e37: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00765e3c: { // 0x765e3c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765e3d: { // 0x765e3d: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L00765e40: { // 0x765e40: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765e41: { // 0x765e41: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L00765e45: { // 0x765e45: 8dbe20070000 LEA EDI,[ESI + 0x720]
    s.di = (s.si+0x00000720u);
  }
  L00765e4b: { // 0x765e4b: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00765e4d: { // 0x765e4d: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00765e4f: { // 0x765e4f: 250000ff00 AND EAX,0xff0000
    s.ax = integer::logical((s.ax)&(0x00ff0000u),32,flags);
  }
  L00765e54: { // 0x765e54: c1ea10 SHR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::right);
  }
  L00765e57: { // 0x765e57: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00765e59: { // 0x765e59: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00765e5b: { // 0x765e5b: 81e200ff0000 AND EDX,0xff00
    s.dx = integer::logical((s.dx)&(0x0000ff00u),32,flags);
  }
  L00765e61: { // 0x765e61: c1e110 SHL ECX,0x10
    s.cx = integer::shift(s.cx,0x00000010u,32,flags,integer::Shift::left);
  }
  L00765e64: { // 0x765e64: 0bd1 OR EDX,ECX
    s.dx = integer::logical((s.dx)|(s.cx),32,flags);
  }
  L00765e66: { // 0x765e66: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L00765e69: { // 0x765e69: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00765e6c: { // 0x765e6c: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00765e6e: { // 0x765e6e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00765e6f: { // 0x765e6f: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00765e71: { // 0x765e71: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765e72: { // 0x765e72: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00765e73: { // 0x765e73: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765e75: { // 0x765e75: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765e76: { // 0x765e76: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7757433u); flags=s.arithmetic_flags;
  }
  L00765e79: { // 0x765e79: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765e7c: { // 0x765e7c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765e7e: { // 0x765e7e: 740d JZ 0x00765e8d
    if(integer::condition("JZ",flags)) goto L00765e8d;
  }
  L00765e80: { // 0x765e80: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765e81: { // 0x765e81: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765e82: { // 0x765e82: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765e83: { // 0x765e83: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00765e88: { // 0x765e88: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765e89: { // 0x765e89: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L00765e8c: { // 0x765e8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765e8d: { // 0x765e8d: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00765e8f: { // 0x765e8f: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00765e91: { // 0x765e91: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00765e93: { // 0x765e93: 0f86bc000000 JBE 0x00765f55
    if(integer::condition("JBE",flags)) goto L00765f55;
  }
  L00765e99: { // 0x765e99: 8d3c40 LEA EDI,[EAX + EAX*0x2]
    s.di = (s.ax+(s.ax * 0x00000002u));
  }
  L00765e9c: { // 0x765e9c: c1e703 SHL EDI,0x3
    s.di = integer::shift(s.di,0x00000003u,32,flags,integer::Shift::left);
  }
  L00765e9f: { // 0x765e9f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00765ea0: { // 0x765ea0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765ea1: { // 0x765ea1: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L00765ea3: { // 0x765ea3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765ea4: { // 0x765ea4: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7757479u); flags=s.arithmetic_flags;
  }
  L00765ea7: { // 0x765ea7: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765eaa: { // 0x765eaa: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00765eac: { // 0x765eac: 898630070000 MOV dword ptr [ESI + 0x730],EAX
    m.w32((s.si+0x00000730u), s.ax);
  }
  L00765eb2: { // 0x765eb2: 750d JNZ 0x00765ec1
    if(integer::condition("JNZ",flags)) goto L00765ec1;
  }
  L00765eb4: { // 0x765eb4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765eb5: { // 0x765eb5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765eb6: { // 0x765eb6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765eb7: { // 0x765eb7: b8f8ffffff MOV EAX,0xfffffff8
    s.ax = 0xfffffff8u;
  }
  L00765ebc: { // 0x765ebc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765ebd: { // 0x765ebd: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L00765ec0: { // 0x765ec0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765ec1: { // 0x765ec1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00765ec2: { // 0x765ec2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765ec3: { // 0x765ec3: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00765ec5: { // 0x765ec5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765ec6: { // 0x765ec6: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7757513u); flags=s.arithmetic_flags;
  }
  L00765ec9: { // 0x765ec9: 8b5e30 MOV EBX,dword ptr [ESI + 0x30]
    s.bx = m.r32((s.si+0x00000030u));
  }
  L00765ecc: { // 0x765ecc: 8d442458 LEA EAX,[ESP + 0x58]
    s.ax = (f.sp+0x00000058u);
  }
  L00765ed0: { // 0x765ed0: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L00765ed2: { // 0x765ed2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765ed3: { // 0x765ed3: 03df ADD EBX,EDI
    s.bx = integer::add(s.bx,s.di,32,flags);
  }
  L00765ed5: { // 0x765ed5: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765ed7: { // 0x765ed7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765ed8: { // 0x765ed8: 895e30 MOV dword ptr [ESI + 0x30],EBX
    m.w32((s.si+0x00000030u), s.bx);
  }
  L00765edb: { // 0x765edb: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7757534u); flags=s.arithmetic_flags;
  }
  L00765ede: { // 0x765ede: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00765ee1: { // 0x765ee1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765ee3: { // 0x765ee3: 740d JZ 0x00765ef2
    if(integer::condition("JZ",flags)) goto L00765ef2;
  }
  L00765ee5: { // 0x765ee5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765ee6: { // 0x765ee6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765ee7: { // 0x765ee7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765ee8: { // 0x765ee8: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L00765eed: { // 0x765eed: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765eee: { // 0x765eee: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L00765ef1: { // 0x765ef1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765ef2: { // 0x765ef2: 817c24484d464344 CMP dword ptr [ESP + 0x48],0x4443464d
    (void)integer::sub(m.r32((f.sp+0x00000048u)),0x4443464du,32,flags);
  }
  L00765efa: { // 0x765efa: 740d JZ 0x00765f09
    if(integer::condition("JZ",flags)) goto L00765f09;
  }
  L00765efc: { // 0x765efc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765efd: { // 0x765efd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765efe: { // 0x765efe: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765eff: { // 0x765eff: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00765f04: { // 0x765f04: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765f05: { // 0x765f05: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L00765f08: { // 0x765f08: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765f09: { // 0x765f09: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L00765f0d: { // 0x765f0d: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00765f0f: { // 0x765f0f: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00765f11: { // 0x765f11: 250000ff00 AND EAX,0xff0000
    s.ax = integer::logical((s.ax)&(0x00ff0000u),32,flags);
  }
  L00765f16: { // 0x765f16: c1ea10 SHR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::right);
  }
  L00765f19: { // 0x765f19: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00765f1b: { // 0x765f1b: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00765f1d: { // 0x765f1d: 81e200ff0000 AND EDX,0xff00
    s.dx = integer::logical((s.dx)&(0x0000ff00u),32,flags);
  }
  L00765f23: { // 0x765f23: c1e110 SHL ECX,0x10
    s.cx = integer::shift(s.cx,0x00000010u,32,flags,integer::Shift::left);
  }
  L00765f26: { // 0x765f26: 0bd1 OR EDX,ECX
    s.dx = integer::logical((s.dx)|(s.cx),32,flags);
  }
  L00765f28: { // 0x765f28: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L00765f2b: { // 0x765f2b: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00765f2e: { // 0x765f2e: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00765f30: { // 0x765f30: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00765f31: { // 0x765f31: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00765f33: { // 0x765f33: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765f34: { // 0x765f34: 8b8630070000 MOV EAX,dword ptr [ESI + 0x730]
    s.ax = m.r32((s.si+0x00000730u));
  }
  L00765f3a: { // 0x765f3a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765f3b: { // 0x765f3b: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765f3d: { // 0x765f3d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765f3e: { // 0x765f3e: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7757633u); flags=s.arithmetic_flags;
  }
  L00765f41: { // 0x765f41: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765f44: { // 0x765f44: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765f46: { // 0x765f46: 740d JZ 0x00765f55
    if(integer::condition("JZ",flags)) goto L00765f55;
  }
  L00765f48: { // 0x765f48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765f49: { // 0x765f49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765f4a: { // 0x765f4a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765f4b: { // 0x765f4b: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00765f50: { // 0x765f50: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765f51: { // 0x765f51: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L00765f54: { // 0x765f54: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765f55: { // 0x765f55: 8bbe24070000 MOV EDI,dword ptr [ESI + 0x724]
    s.di = m.r32((s.si+0x00000724u));
  }
  L00765f5b: { // 0x765f5b: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L00765f5d: { // 0x765f5d: 0f86b9000000 JBE 0x0076601c
    if(integer::condition("JBE",flags)) goto L0076601c;
  }
  L00765f63: { // 0x765f63: c1e704 SHL EDI,0x4
    s.di = integer::shift(s.di,0x00000004u,32,flags,integer::Shift::left);
  }
  L00765f66: { // 0x765f66: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00765f67: { // 0x765f67: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00765f68: { // 0x765f68: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L00765f6a: { // 0x765f6a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765f6b: { // 0x765f6b: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7757678u); flags=s.arithmetic_flags;
  }
  L00765f6e: { // 0x765f6e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00765f71: { // 0x765f71: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00765f73: { // 0x765f73: 898634070000 MOV dword ptr [ESI + 0x734],EAX
    m.w32((s.si+0x00000734u), s.ax);
  }
  L00765f79: { // 0x765f79: 750d JNZ 0x00765f88
    if(integer::condition("JNZ",flags)) goto L00765f88;
  }
  L00765f7b: { // 0x765f7b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765f7c: { // 0x765f7c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765f7d: { // 0x765f7d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765f7e: { // 0x765f7e: b8f8ffffff MOV EAX,0xfffffff8
    s.ax = 0xfffffff8u;
  }
  L00765f83: { // 0x765f83: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765f84: { // 0x765f84: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L00765f87: { // 0x765f87: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765f88: { // 0x765f88: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00765f89: { // 0x765f89: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765f8a: { // 0x765f8a: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00765f8c: { // 0x765f8c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765f8d: { // 0x765f8d: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7757712u); flags=s.arithmetic_flags;
  }
  L00765f90: { // 0x765f90: 8b5630 MOV EDX,dword ptr [ESI + 0x30]
    s.dx = m.r32((s.si+0x00000030u));
  }
  L00765f93: { // 0x765f93: 8d4c2458 LEA ECX,[ESP + 0x58]
    s.cx = (f.sp+0x00000058u);
  }
  L00765f97: { // 0x765f97: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L00765f99: { // 0x765f99: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00765f9a: { // 0x765f9a: 03d7 ADD EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
  L00765f9c: { // 0x765f9c: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00765f9e: { // 0x765f9e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00765f9f: { // 0x765f9f: 895630 MOV dword ptr [ESI + 0x30],EDX
    m.w32((s.si+0x00000030u), s.dx);
  }
  L00765fa2: { // 0x765fa2: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7757733u); flags=s.arithmetic_flags;
  }
  L00765fa5: { // 0x765fa5: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00765fa8: { // 0x765fa8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00765faa: { // 0x765faa: 740d JZ 0x00765fb9
    if(integer::condition("JZ",flags)) goto L00765fb9;
  }
  L00765fac: { // 0x765fac: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765fad: { // 0x765fad: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765fae: { // 0x765fae: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765faf: { // 0x765faf: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L00765fb4: { // 0x765fb4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765fb5: { // 0x765fb5: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L00765fb8: { // 0x765fb8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765fb9: { // 0x765fb9: 817c24484d464354 CMP dword ptr [ESP + 0x48],0x5443464d
    (void)integer::sub(m.r32((f.sp+0x00000048u)),0x5443464du,32,flags);
  }
  L00765fc1: { // 0x765fc1: 740d JZ 0x00765fd0
    if(integer::condition("JZ",flags)) goto L00765fd0;
  }
  L00765fc3: { // 0x765fc3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00765fc4: { // 0x765fc4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00765fc5: { // 0x765fc5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00765fc6: { // 0x765fc6: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00765fcb: { // 0x765fcb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00765fcc: { // 0x765fcc: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L00765fcf: { // 0x765fcf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00765fd0: { // 0x765fd0: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L00765fd4: { // 0x765fd4: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00765fd6: { // 0x765fd6: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00765fd8: { // 0x765fd8: 250000ff00 AND EAX,0xff0000
    s.ax = integer::logical((s.ax)&(0x00ff0000u),32,flags);
  }
  L00765fdd: { // 0x765fdd: c1ea10 SHR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::right);
  }
  L00765fe0: { // 0x765fe0: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00765fe2: { // 0x765fe2: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00765fe4: { // 0x765fe4: 81e200ff0000 AND EDX,0xff00
    s.dx = integer::logical((s.dx)&(0x0000ff00u),32,flags);
  }
  L00765fea: { // 0x765fea: c1e110 SHL ECX,0x10
    s.cx = integer::shift(s.cx,0x00000010u,32,flags,integer::Shift::left);
  }
  L00765fed: { // 0x765fed: 0bd1 OR EDX,ECX
    s.dx = integer::logical((s.dx)|(s.cx),32,flags);
  }
  L00765fef: { // 0x765fef: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L00765ff2: { // 0x765ff2: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00765ff5: { // 0x765ff5: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00765ff7: { // 0x765ff7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00765ff8: { // 0x765ff8: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L00765ffa: { // 0x765ffa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00765ffb: { // 0x765ffb: 8b8634070000 MOV EAX,dword ptr [ESI + 0x734]
    s.ax = m.r32((s.si+0x00000734u));
  }
  L00766001: { // 0x766001: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766002: { // 0x766002: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766004: { // 0x766004: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766005: { // 0x766005: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7757832u); flags=s.arithmetic_flags;
  }
  L00766008: { // 0x766008: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0076600b: { // 0x76600b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076600d: { // 0x76600d: 740d JZ 0x0076601c
    if(integer::condition("JZ",flags)) goto L0076601c;
  }
  L0076600f: { // 0x76600f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766010: { // 0x766010: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766011: { // 0x766011: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766012: { // 0x766012: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766017: { // 0x766017: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766018: { // 0x766018: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L0076601b: { // 0x76601b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0076601c: { // 0x76601c: 8b9e24070000 MOV EBX,dword ptr [ESI + 0x724]
    s.bx = m.r32((s.si+0x00000724u));
  }
  L00766022: { // 0x766022: 3bdd CMP EBX,EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L00766024: { // 0x766024: 895c2444 MOV dword ptr [ESP + 0x44],EBX
    m.w32((f.sp+0x00000044u), s.bx);
  }
  L00766028: { // 0x766028: 0f8647020000 JBE 0x00766275
    if(integer::condition("JBE",flags)) goto L00766275;
  }
  L0076602e: { // 0x76602e: 8d3c5b LEA EDI,[EBX + EBX*0x2]
    s.di = (s.bx+(s.bx * 0x00000002u));
  }
  L00766031: { // 0x766031: c1e702 SHL EDI,0x2
    s.di = integer::shift(s.di,0x00000002u,32,flags,integer::Shift::left);
  }
  L00766034: { // 0x766034: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766035: { // 0x766035: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00766036: { // 0x766036: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L00766038: { // 0x766038: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766039: { // 0x766039: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7757884u); flags=s.arithmetic_flags;
  }
  L0076603c: { // 0x76603c: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0076603f: { // 0x76603f: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00766041: { // 0x766041: 898638070000 MOV dword ptr [ESI + 0x738],EAX
    m.w32((s.si+0x00000738u), s.ax);
  }
  L00766047: { // 0x766047: 750d JNZ 0x00766056
    if(integer::condition("JNZ",flags)) goto L00766056;
  }
  L00766049: { // 0x766049: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076604a: { // 0x76604a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076604b: { // 0x76604b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076604c: { // 0x76604c: b8f8ffffff MOV EAX,0xfffffff8
    s.ax = 0xfffffff8u;
  }
  L00766051: { // 0x766051: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766052: { // 0x766052: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L00766055: { // 0x766055: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766056: { // 0x766056: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766057: { // 0x766057: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766058: { // 0x766058: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L0076605a: { // 0x76605a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076605b: { // 0x76605b: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7757918u); flags=s.arithmetic_flags;
  }
  L0076605e: { // 0x76605e: 8b4e30 MOV ECX,dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L00766061: { // 0x766061: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766064: { // 0x766064: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L00766066: { // 0x766066: 3bdd CMP EBX,EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L00766068: { // 0x766068: 894e30 MOV dword ptr [ESI + 0x30],ECX
    m.w32((s.si+0x00000030u), s.cx);
  }
  L0076606b: { // 0x76606b: 896c2434 MOV dword ptr [ESP + 0x34],EBP
    m.w32((f.sp+0x00000034u), s.bp);
  }
  L0076606f: { // 0x76606f: 0f8600020000 JBE 0x00766275
    if(integer::condition("JBE",flags)) goto L00766275;
  }
  L00766075: { // 0x766075: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00766077: { // 0x766077: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L0076607b: { // 0x76607b: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L0076607f: { // 0x76607f: 8b8634070000 MOV EAX,dword ptr [ESI + 0x734]
    s.ax = m.r32((s.si+0x00000734u));
  }
  L00766085: { // 0x766085: 8b8e38070000 MOV ECX,dword ptr [ESI + 0x738]
    s.cx = m.r32((s.si+0x00000738u));
  }
  L0076608b: { // 0x76608b: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0076608f: { // 0x76608f: 8b4c0304 MOV ECX,dword ptr [EBX + EAX*0x1 + 0x4]
    s.cx = m.r32((s.bx+(s.ax * 0x00000001u)+0x00000004u));
  }
  L00766093: { // 0x766093: 8b540308 MOV EDX,dword ptr [EBX + EAX*0x1 + 0x8]
    s.dx = m.r32((s.bx+(s.ax * 0x00000001u)+0x00000008u));
  }
  L00766097: { // 0x766097: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00766099: { // 0x766099: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L0076609d: { // 0x76609d: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L007660a1: { // 0x7660a1: 0f84a0010000 JZ 0x00766247
    if(integer::condition("JZ",flags)) goto L00766247;
  }
  L007660a7: { // 0x7660a7: 8b8688000000 MOV EAX,dword ptr [ESI + 0x88]
    s.ax = m.r32((s.si+0x00000088u));
  }
  L007660ad: { // 0x7660ad: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L007660af: { // 0x7660af: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L007660b0: { // 0x7660b0: 8bbe20070000 MOV EDI,dword ptr [ESI + 0x720]
    s.di = m.r32((s.si+0x00000720u));
  }
  L007660b6: { // 0x7660b6: f7f1 DIV ECX
    const auto divisor=s.cx;const std::uint64_t dividend=(std::uint64_t(s.dx)<<32)|s.ax;if(!divisor||dividend/divisor>0xffffffffull)throw std::domain_error("835 DIV overflow");s.ax=std::uint32_t(dividend/divisor);s.dx=std::uint32_t(dividend%divisor);
  }
  L007660b8: { // 0x7660b8: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L007660ba: { // 0x7660ba: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L007660be: { // 0x7660be: 668b9614070000 MOV DX,word ptr [ESI + 0x714]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000714u)));
  }
  L007660c5: { // 0x7660c5: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L007660c9: { // 0x7660c9: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L007660cd: { // 0x7660cd: 896c2428 MOV dword ptr [ESP + 0x28],EBP
    m.w32((f.sp+0x00000028u), s.bp);
  }
  L007660d1: { // 0x7660d1: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L007660d3: { // 0x7660d3: 8b861c070000 MOV EAX,dword ptr [ESI + 0x71c]
    s.ax = m.r32((s.si+0x0000071cu));
  }
  L007660d9: { // 0x7660d9: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L007660da: { // 0x7660da: 3bd5 CMP EDX,EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  L007660dc: { // 0x7660dc: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L007660e0: { // 0x7660e0: 0f86ab000000 JBE 0x00766191
    if(integer::condition("JBE",flags)) goto L00766191;
  }
  L007660e6: { // 0x7660e6: 8d6802 LEA EBP,[EAX + 0x2]
    s.bp = (s.ax+0x00000002u);
  }
  L007660e9: { // 0x7660e9: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L007660ed: { // 0x7660ed: 83cfff OR EDI,0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  L007660f0: { // 0x7660f0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007660f2: { // 0x7660f2: c744242000000000 MOV dword ptr [ESP + 0x20],0x0
    m.w32((f.sp+0x00000020u), 0x00000000u);
  }
  L007660fa: { // 0x7660fa: 7676 JBE 0x00766172
    if(integer::condition("JBE",flags)) goto L00766172;
  }
  L007660fc: { // 0x7660fc: 8b8634070000 MOV EAX,dword ptr [ESI + 0x734]
    s.ax = m.r32((s.si+0x00000734u));
  }
  L00766102: { // 0x766102: 8b0403 MOV EAX,dword ptr [EBX + EAX*0x1]
    s.ax = m.r32((s.bx+(s.ax * 0x00000001u)));
  }
  L00766105: { // 0x766105: 8b9e30070000 MOV EBX,dword ptr [ESI + 0x730]
    s.bx = m.r32((s.si+0x00000730u));
  }
  L0076610b: { // 0x76610b: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L0076610f: { // 0x76610f: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L00766113: { // 0x766113: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L00766116: { // 0x766116: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00766118: { // 0x766118: 7524 JNZ 0x0076613e
    if(integer::condition("JNZ",flags)) goto L0076613e;
  }
  L0076611a: { // 0x76611a: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L0076611c: { // 0x76611c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0076611e: { // 0x76611e: 668b55fe MOV DX,word ptr [EBP + -0x2]
    s.dx = with_ax(s.dx, m.r16((s.bp-0x00000002u)));
  }
  L00766122: { // 0x766122: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00766124: { // 0x766124: 7218 JC 0x0076613e
    if(integer::condition("JC",flags)) goto L0076613e;
  }
  L00766126: { // 0x766126: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00766128: { // 0x766128: 668b4500 MOV AX,word ptr [EBP]
    s.ax = with_ax(s.ax, m.r16((s.bp)));
  }
  L0076612c: { // 0x76612c: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0076612e: { // 0x76612e: 7722 JA 0x00766152
    if(integer::condition("JA",flags)) goto L00766152;
  }
  L00766130: { // 0x766130: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00766132: { // 0x766132: 7d04 JGE 0x00766138
    if(integer::condition("JGE",flags)) goto L00766138;
  }
  L00766134: { // 0x766134: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00766136: { // 0x766136: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L00766138: { // 0x766138: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0076613a: { // 0x76613a: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0076613e: { // 0x76613e: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00766142: { // 0x766142: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00766146: { // 0x766146: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00766147: { // 0x766147: 83c318 ADD EBX,0x18
    s.bx = integer::add(s.bx,0x00000018u,32,flags);
  }
  L0076614a: { // 0x76614a: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0076614c: { // 0x76614c: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00766150: { // 0x766150: 72bd JC 0x0076610f
    if(integer::condition("JC",flags)) goto L0076610f;
  }
  L00766152: { // 0x766152: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00766154: { // 0x766154: 7e10 JLE 0x00766166
    if(integer::condition("JLE",flags)) goto L00766166;
  }
  L00766156: { // 0x766156: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0076615a: { // 0x76615a: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L0076615e: { // 0x76615e: 8d441701 LEA EAX,[EDI + EDX*0x1 + 0x1]
    s.ax = (s.di+(s.dx * 0x00000001u)+0x00000001u);
  }
  L00766162: { // 0x766162: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00766164: { // 0x766164: 7222 JC 0x00766188
    if(integer::condition("JC",flags)) goto L00766188;
  }
  L00766166: { // 0x766166: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L0076616a: { // 0x76616a: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0076616e: { // 0x76616e: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L00766172: { // 0x766172: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00766176: { // 0x766176: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L00766179: { // 0x766179: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0076617a: { // 0x76617a: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0076617c: { // 0x76617c: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00766180: { // 0x766180: 0f8263ffffff JC 0x007660e9
    if(integer::condition("JC",flags)) goto L007660e9;
  }
  L00766186: { // 0x766186: eb09 JMP 0x00766191
    goto L00766191;
  }
  L00766188: { // 0x766188: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0076618c: { // 0x76618c: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0076618d: { // 0x76618d: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00766191: { // 0x766191: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00766193: { // 0x766193: 0f8eae000000 JLE 0x00766247
    if(integer::condition("JLE",flags)) goto L00766247;
  }
  L00766199: { // 0x766199: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0076619d: { // 0x76619d: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L007661a1: { // 0x7661a1: 8d3c49 LEA EDI,[ECX + ECX*0x2]
    s.di = (s.cx+(s.cx * 0x00000002u));
  }
  L007661a4: { // 0x7661a4: c1e702 SHL EDI,0x2
    s.di = integer::shift(s.di,0x00000002u,32,flags,integer::Shift::left);
  }
  L007661a7: { // 0x7661a7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007661a8: { // 0x7661a8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L007661aa: { // 0x7661aa: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L007661ac: { // 0x7661ac: 890c10 MOV dword ptr [EAX + EDX*0x1],ECX
    m.w32((s.ax+(s.dx * 0x00000001u)), s.cx);
  }
  L007661af: { // 0x7661af: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007661b0: { // 0x7661b0: c744100400000000 MOV dword ptr [EAX + EDX*0x1 + 0x4],0x0
    m.w32((s.ax+(s.dx * 0x00000001u)+0x00000004u), 0x00000000u);
  }
  L007661b8: { // 0x7661b8: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7758267u); flags=s.arithmetic_flags;
  }
  L007661bb: { // 0x7661bb: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L007661bd: { // 0x7661bd: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007661c0: { // 0x7661c0: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L007661c2: { // 0x7661c2: 0f8481feffff JZ 0x00766049
    if(integer::condition("JZ",flags)) goto L00766049;
  }
  L007661c8: { // 0x7661c8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007661c9: { // 0x7661c9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007661ca: { // 0x7661ca: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L007661cc: { // 0x7661cc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007661cd: { // 0x7661cd: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7758288u); flags=s.arithmetic_flags;
  }
  L007661d0: { // 0x7661d0: 8b6e30 MOV EBP,dword ptr [ESI + 0x30]
    s.bp = m.r32((s.si+0x00000030u));
  }
  L007661d3: { // 0x7661d3: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L007661d7: { // 0x7661d7: 03ef ADD EBP,EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
  L007661d9: { // 0x7661d9: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L007661dd: { // 0x7661dd: 8d7801 LEA EDI,[EAX + 0x1]
    s.di = (s.ax+0x00000001u);
  }
  L007661e0: { // 0x7661e0: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L007661e4: { // 0x7661e4: 83e7fe AND EDI,0xfffffffe
    s.di = integer::logical((s.di)&(0xfffffffeu),32,flags);
  }
  L007661e7: { // 0x7661e7: 896e30 MOV dword ptr [ESI + 0x30],EBP
    m.w32((s.si+0x00000030u), s.bp);
  }
  L007661ea: { // 0x7661ea: 0faf7c2420 IMUL EDI,dword ptr [ESP + 0x20]
    s.di = integer::imul(s.di,m.r32((f.sp+0x00000020u)),32,flags);
  }
  L007661ef: { // 0x7661ef: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007661f0: { // 0x7661f0: 8d6c1108 LEA EBP,[ECX + EDX*0x1 + 0x8]
    s.bp = (s.cx+(s.dx * 0x00000001u)+0x00000008u);
  }
  L007661f4: { // 0x7661f4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L007661f6: { // 0x7661f6: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L007661f8: { // 0x7661f8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007661f9: { // 0x7661f9: 895d00 MOV dword ptr [EBP],EBX
    m.w32((s.bp), s.bx);
  }
  L007661fc: { // 0x7661fc: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7758335u); flags=s.arithmetic_flags;
  }
  L007661ff: { // 0x7661ff: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00766201: { // 0x766201: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00766204: { // 0x766204: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00766206: { // 0x766206: 0f843dfeffff JZ 0x00766049
    if(integer::condition("JZ",flags)) goto L00766049;
  }
  L0076620c: { // 0x76620c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076620d: { // 0x76620d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076620e: { // 0x76620e: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00766210: { // 0x766210: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766211: { // 0x766211: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7758356u); flags=s.arithmetic_flags;
  }
  L00766214: { // 0x766214: 8b4e30 MOV ECX,dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L00766217: { // 0x766217: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0076621a: { // 0x76621a: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L0076621c: { // 0x76621c: 894e30 MOV dword ptr [ESI + 0x30],ECX
    m.w32((s.si+0x00000030u), s.cx);
  }
  L0076621f: { // 0x76621f: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00766223: { // 0x766223: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00766225: { // 0x766225: 7e20 JLE 0x00766247
    if(integer::condition("JLE",flags)) goto L00766247;
  }
  L00766227: { // 0x766227: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00766229: { // 0x766229: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L0076622c: { // 0x76622c: 83c00c ADD EAX,0xc
    s.ax = integer::add(s.ax,0x0000000cu,32,flags);
  }
  L0076622f: { // 0x76622f: 895c10f4 MOV dword ptr [EAX + EDX*0x1 + -0xc],EBX
    m.w32((s.ax+(s.dx * 0x00000001u)-0x0000000cu), s.bx);
  }
  L00766233: { // 0x766233: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00766236: { // 0x766236: c74410fcffffffff MOV dword ptr [EAX + EDX*0x1 + -0x4],0xffffffff
    m.w32((s.ax+(s.dx * 0x00000001u)-0x00000004u), 0xffffffffu);
  }
  L0076623e: { // 0x76623e: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L00766242: { // 0x766242: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L00766244: { // 0x766244: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00766245: { // 0x766245: 75e2 JNZ 0x00766229
    if(integer::condition("JNZ",flags)) goto L00766229;
  }
  L00766247: { // 0x766247: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L0076624b: { // 0x76624b: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L0076624f: { // 0x76624f: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00766253: { // 0x766253: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00766257: { // 0x766257: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00766258: { // 0x766258: 83c310 ADD EBX,0x10
    s.bx = integer::add(s.bx,0x00000010u,32,flags);
  }
  L0076625b: { // 0x76625b: 83c20c ADD EDX,0xc
    s.dx = integer::add(s.dx,0x0000000cu,32,flags);
  }
  L0076625e: { // 0x76625e: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00766260: { // 0x766260: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L00766264: { // 0x766264: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L00766268: { // 0x766268: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0076626c: { // 0x76626c: 7307 JNC 0x00766275
    if(integer::condition("JNC",flags)) goto L00766275;
  }
  L0076626e: { // 0x76626e: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00766270: { // 0x766270: e90afeffff JMP 0x0076607f
    goto L0076607f;
  }
  L00766275: { // 0x766275: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766276: { // 0x766276: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766277: { // 0x766277: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766278: { // 0x766278: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0076627b: { // 0x76627b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076627c: { // 0x76627c: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L0076627f: { // 0x76627f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00766280(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00766280: { // 0x766280: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L00766283: { // 0x766283: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L00766287: { // 0x766287: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00766288: { // 0x766288: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00766289: { // 0x766289: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076628a: { // 0x76628a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076628b: { // 0x76628b: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L0076628d: { // 0x76628d: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0076628f: { // 0x76628f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766290: { // 0x766290: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766292: { // 0x766292: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766293: { // 0x766293: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7758486u); flags=s.arithmetic_flags;
  }
  L00766296: { // 0x766296: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766299: { // 0x766299: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0076629b: { // 0x76629b: 740d JZ 0x007662aa
    if(integer::condition("JZ",flags)) goto L007662aa;
  }
  L0076629d: { // 0x76629d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076629e: { // 0x76629e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076629f: { // 0x76629f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007662a0: { // 0x7662a0: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L007662a5: { // 0x7662a5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007662a6: { // 0x7662a6: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L007662a9: { // 0x7662a9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007662aa: { // 0x7662aa: 817c24284d534348 CMP dword ptr [ESP + 0x28],0x4843534d
    (void)integer::sub(m.r32((f.sp+0x00000028u)),0x4843534du,32,flags);
  }
  L007662b2: { // 0x7662b2: 740d JZ 0x007662c1
    if(integer::condition("JZ",flags)) goto L007662c1;
  }
  L007662b4: { // 0x7662b4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007662b5: { // 0x7662b5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007662b6: { // 0x7662b6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007662b7: { // 0x7662b7: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L007662bc: { // 0x7662bc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007662bd: { // 0x7662bd: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L007662c0: { // 0x7662c0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007662c1: { // 0x7662c1: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L007662c5: { // 0x7662c5: 8d9e3c070000 LEA EBX,[ESI + 0x73c]
    s.bx = (s.si+0x0000073cu);
  }
  L007662cb: { // 0x7662cb: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L007662cd: { // 0x7662cd: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L007662cf: { // 0x7662cf: 250000ff00 AND EAX,0xff0000
    s.ax = integer::logical((s.ax)&(0x00ff0000u),32,flags);
  }
  L007662d4: { // 0x7662d4: c1ea10 SHR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::right);
  }
  L007662d7: { // 0x7662d7: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L007662d9: { // 0x7662d9: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L007662db: { // 0x7662db: 81e200ff0000 AND EDX,0xff00
    s.dx = integer::logical((s.dx)&(0x0000ff00u),32,flags);
  }
  L007662e1: { // 0x7662e1: c1e110 SHL ECX,0x10
    s.cx = integer::shift(s.cx,0x00000010u,32,flags,integer::Shift::left);
  }
  L007662e4: { // 0x7662e4: 0bd1 OR EDX,ECX
    s.dx = integer::logical((s.dx)|(s.cx),32,flags);
  }
  L007662e6: { // 0x7662e6: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L007662e9: { // 0x7662e9: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L007662ec: { // 0x7662ec: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L007662ee: { // 0x7662ee: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L007662ef: { // 0x7662ef: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L007662f1: { // 0x7662f1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007662f2: { // 0x7662f2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007662f3: { // 0x7662f3: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L007662f5: { // 0x7662f5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007662f6: { // 0x7662f6: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7758585u); flags=s.arithmetic_flags;
  }
  L007662f9: { // 0x7662f9: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007662fc: { // 0x7662fc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007662fe: { // 0x7662fe: 740d JZ 0x0076630d
    if(integer::condition("JZ",flags)) goto L0076630d;
  }
  L00766300: { // 0x766300: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766301: { // 0x766301: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766302: { // 0x766302: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766303: { // 0x766303: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766308: { // 0x766308: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766309: { // 0x766309: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0076630c: { // 0x76630c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0076630d: { // 0x76630d: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0076630f: { // 0x76630f: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00766311: { // 0x766311: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00766313: { // 0x766313: 0f86bb000000 JBE 0x007663d4
    if(integer::condition("JBE",flags)) goto L007663d4;
  }
  L00766319: { // 0x766319: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0076631c: { // 0x76631c: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0076631e: { // 0x76631e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076631f: { // 0x76631f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00766320: { // 0x766320: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L00766322: { // 0x766322: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766323: { // 0x766323: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7758630u); flags=s.arithmetic_flags;
  }
  L00766326: { // 0x766326: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766329: { // 0x766329: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0076632b: { // 0x76632b: 898644070000 MOV dword ptr [ESI + 0x744],EAX
    m.w32((s.si+0x00000744u), s.ax);
  }
  L00766331: { // 0x766331: 750d JNZ 0x00766340
    if(integer::condition("JNZ",flags)) goto L00766340;
  }
  L00766333: { // 0x766333: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766334: { // 0x766334: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766335: { // 0x766335: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766336: { // 0x766336: b8f8ffffff MOV EAX,0xfffffff8
    s.ax = 0xfffffff8u;
  }
  L0076633b: { // 0x76633b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076633c: { // 0x76633c: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0076633f: { // 0x76633f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766340: { // 0x766340: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766341: { // 0x766341: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766342: { // 0x766342: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00766344: { // 0x766344: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00766345: { // 0x766345: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7758664u); flags=s.arithmetic_flags;
  }
  L00766348: { // 0x766348: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L0076634b: { // 0x76634b: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L0076634d: { // 0x76634d: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0076634f: { // 0x76634f: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  L00766352: { // 0x766352: 8d44243c LEA EAX,[ESP + 0x3c]
    s.ax = (f.sp+0x0000003cu);
  }
  L00766356: { // 0x766356: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00766357: { // 0x766357: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L00766359: { // 0x766359: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076635a: { // 0x76635a: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7758685u); flags=s.arithmetic_flags;
  }
  L0076635d: { // 0x76635d: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00766360: { // 0x766360: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00766362: { // 0x766362: 740d JZ 0x00766371
    if(integer::condition("JZ",flags)) goto L00766371;
  }
  L00766364: { // 0x766364: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00766365: { // 0x766365: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766366: { // 0x766366: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766367: { // 0x766367: b8feffffff MOV EAX,0xfffffffe
    s.ax = 0xfffffffeu;
  }
  L0076636c: { // 0x76636c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076636d: { // 0x76636d: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00766370: { // 0x766370: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766371: { // 0x766371: 817c24284d534354 CMP dword ptr [ESP + 0x28],0x5443534d
    (void)integer::sub(m.r32((f.sp+0x00000028u)),0x5443534du,32,flags);
  }
  L00766379: { // 0x766379: 740d JZ 0x00766388
    if(integer::condition("JZ",flags)) goto L00766388;
  }
  L0076637b: { // 0x76637b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076637c: { // 0x76637c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076637d: { // 0x76637d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076637e: { // 0x76637e: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L00766383: { // 0x766383: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766384: { // 0x766384: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00766387: { // 0x766387: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00766388: { // 0x766388: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0076638c: { // 0x76638c: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0076638e: { // 0x76638e: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00766390: { // 0x766390: 250000ff00 AND EAX,0xff0000
    s.ax = integer::logical((s.ax)&(0x00ff0000u),32,flags);
  }
  L00766395: { // 0x766395: c1ea10 SHR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::right);
  }
  L00766398: { // 0x766398: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L0076639a: { // 0x76639a: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0076639c: { // 0x76639c: 81e200ff0000 AND EDX,0xff00
    s.dx = integer::logical((s.dx)&(0x0000ff00u),32,flags);
  }
  L007663a2: { // 0x7663a2: c1e110 SHL ECX,0x10
    s.cx = integer::shift(s.cx,0x00000010u,32,flags,integer::Shift::left);
  }
  L007663a5: { // 0x7663a5: 0bd1 OR EDX,ECX
    s.dx = integer::logical((s.dx)|(s.cx),32,flags);
  }
  L007663a7: { // 0x7663a7: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L007663aa: { // 0x7663aa: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L007663ad: { // 0x7663ad: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L007663af: { // 0x7663af: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L007663b0: { // 0x7663b0: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L007663b2: { // 0x7663b2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007663b3: { // 0x7663b3: 8b8644070000 MOV EAX,dword ptr [ESI + 0x744]
    s.ax = m.r32((s.si+0x00000744u));
  }
  L007663b9: { // 0x7663b9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L007663ba: { // 0x7663ba: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  L007663bc: { // 0x7663bc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007663bd: { // 0x7663bd: ff5640 CALL dword ptr [ESI + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000040u)),7758784u); flags=s.arithmetic_flags;
  }
  L007663c0: { // 0x7663c0: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007663c3: { // 0x7663c3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L007663c5: { // 0x7663c5: 740d JZ 0x007663d4
    if(integer::condition("JZ",flags)) goto L007663d4;
  }
  L007663c7: { // 0x7663c7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007663c8: { // 0x7663c8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007663c9: { // 0x7663c9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L007663ca: { // 0x7663ca: b8fcffffff MOV EAX,0xfffffffc
    s.ax = 0xfffffffcu;
  }
  L007663cf: { // 0x7663cf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007663d0: { // 0x7663d0: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L007663d3: { // 0x7663d3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007663d4: { // 0x7663d4: 8b1b MOV EBX,dword ptr [EBX]
    s.bx = m.r32((s.bx));
  }
  L007663d6: { // 0x7663d6: 3bdd CMP EBX,EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L007663d8: { // 0x7663d8: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L007663dc: { // 0x7663dc: 0f864c010000 JBE 0x0076652e
    if(integer::condition("JBE",flags)) goto L0076652e;
  }
  L007663e2: { // 0x7663e2: 8d3c5b LEA EDI,[EBX + EBX*0x2]
    s.di = (s.bx+(s.bx * 0x00000002u));
  }
  L007663e5: { // 0x7663e5: c1e702 SHL EDI,0x2
    s.di = integer::shift(s.di,0x00000002u,32,flags,integer::Shift::left);
  }
  L007663e8: { // 0x7663e8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007663e9: { // 0x7663e9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007663ea: { // 0x7663ea: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L007663ec: { // 0x7663ec: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007663ed: { // 0x7663ed: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7758832u); flags=s.arithmetic_flags;
  }
  L007663f0: { // 0x7663f0: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007663f3: { // 0x7663f3: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L007663f5: { // 0x7663f5: 898648070000 MOV dword ptr [ESI + 0x748],EAX
    m.w32((s.si+0x00000748u), s.ax);
  }
  L007663fb: { // 0x7663fb: 750d JNZ 0x0076640a
    if(integer::condition("JNZ",flags)) goto L0076640a;
  }
  L007663fd: { // 0x7663fd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007663fe: { // 0x7663fe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007663ff: { // 0x7663ff: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766400: { // 0x766400: b8f8ffffff MOV EAX,0xfffffff8
    s.ax = 0xfffffff8u;
  }
  L00766405: { // 0x766405: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766406: { // 0x766406: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00766409: { // 0x766409: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0076640a: { // 0x76640a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076640b: { // 0x76640b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076640c: { // 0x76640c: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L0076640e: { // 0x76640e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076640f: { // 0x76640f: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7758866u); flags=s.arithmetic_flags;
  }
  L00766412: { // 0x766412: 8b4e30 MOV ECX,dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L00766415: { // 0x766415: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00766418: { // 0x766418: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L0076641a: { // 0x76641a: 3bdd CMP EBX,EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L0076641c: { // 0x76641c: 894e30 MOV dword ptr [ESI + 0x30],ECX
    m.w32((s.si+0x00000030u), s.cx);
  }
  L0076641f: { // 0x76641f: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L00766423: { // 0x766423: 0f8605010000 JBE 0x0076652e
    if(integer::condition("JBE",flags)) goto L0076652e;
  }
  L00766429: { // 0x766429: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0076642b: { // 0x76642b: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L0076642f: { // 0x76642f: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00766433: { // 0x766433: 8b9644070000 MOV EDX,dword ptr [ESI + 0x744]
    s.dx = m.r32((s.si+0x00000744u));
  }
  L00766439: { // 0x766439: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0076643d: { // 0x76643d: 8bae88000000 MOV EBP,dword ptr [ESI + 0x88]
    s.bp = m.r32((s.si+0x00000088u));
  }
  L00766443: { // 0x766443: 8b8648070000 MOV EAX,dword ptr [ESI + 0x748]
    s.ax = m.r32((s.si+0x00000748u));
  }
  L00766449: { // 0x766449: 8b541704 MOV EDX,dword ptr [EDI + EDX*0x1 + 0x4]
    s.dx = m.r32((s.di+(s.dx * 0x00000001u)+0x00000004u));
  }
  L0076644d: { // 0x76644d: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00766451: { // 0x766451: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00766453: { // 0x766453: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00766457: { // 0x766457: 0f8eae000000 JLE 0x0076650b
    if(integer::condition("JLE",flags)) goto L0076650b;
  }
  L0076645d: { // 0x76645d: 8d7c6d00 LEA EDI,[EBP + EBP*0x2]
    s.di = (s.bp+(s.bp * 0x00000002u));
  }
  L00766461: { // 0x766461: 892c01 MOV dword ptr [ECX + EAX*0x1],EBP
    m.w32((s.cx+(s.ax * 0x00000001u)), s.bp);
  }
  L00766464: { // 0x766464: c1e702 SHL EDI,0x2
    s.di = integer::shift(s.di,0x00000002u,32,flags,integer::Shift::left);
  }
  L00766467: { // 0x766467: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766468: { // 0x766468: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0076646a: { // 0x76646a: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L0076646c: { // 0x76646c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076646d: { // 0x76646d: c744010400000000 MOV dword ptr [ECX + EAX*0x1 + 0x4],0x0
    m.w32((s.cx+(s.ax * 0x00000001u)+0x00000004u), 0x00000000u);
  }
  L00766475: { // 0x766475: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7758968u); flags=s.arithmetic_flags;
  }
  L00766478: { // 0x766478: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0076647a: { // 0x76647a: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0076647d: { // 0x76647d: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0076647f: { // 0x76647f: 0f8478ffffff JZ 0x007663fd
    if(integer::condition("JZ",flags)) goto L007663fd;
  }
  L00766485: { // 0x766485: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00766486: { // 0x766486: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00766487: { // 0x766487: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L00766489: { // 0x766489: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076648a: { // 0x76648a: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7758989u); flags=s.arithmetic_flags;
  }
  L0076648d: { // 0x76648d: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L00766490: { // 0x766490: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00766494: { // 0x766494: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00766496: { // 0x766496: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L0076649a: { // 0x76649a: 8d7a01 LEA EDI,[EDX + 0x1]
    s.di = (s.dx+0x00000001u);
  }
  L0076649d: { // 0x76649d: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  L007664a0: { // 0x7664a0: 83e7fe AND EDI,0xfffffffe
    s.di = integer::logical((s.di)&(0xfffffffeu),32,flags);
  }
  L007664a3: { // 0x7664a3: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L007664a7: { // 0x7664a7: 0faffd IMUL EDI,EBP
    s.di = integer::imul(s.di,s.bp,32,flags);
  }
  L007664aa: { // 0x7664aa: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007664ab: { // 0x7664ab: 8d440808 LEA EAX,[EAX + ECX*0x1 + 0x8]
    s.ax = (s.ax+(s.cx * 0x00000001u)+0x00000008u);
  }
  L007664af: { // 0x7664af: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L007664b1: { // 0x7664b1: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L007664b3: { // 0x7664b3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007664b4: { // 0x7664b4: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L007664b8: { // 0x7664b8: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L007664ba: { // 0x7664ba: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7759037u); flags=s.arithmetic_flags;
  }
  L007664bd: { // 0x7664bd: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L007664bf: { // 0x7664bf: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L007664c2: { // 0x7664c2: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L007664c4: { // 0x7664c4: 0f8433ffffff JZ 0x007663fd
    if(integer::condition("JZ",flags)) goto L007663fd;
  }
  L007664ca: { // 0x7664ca: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007664cb: { // 0x7664cb: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007664cc: { // 0x7664cc: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L007664ce: { // 0x7664ce: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007664cf: { // 0x7664cf: ff5644 CALL dword ptr [ESI + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000044u)),7759058u); flags=s.arithmetic_flags;
  }
  L007664d2: { // 0x7664d2: 8b4e30 MOV ECX,dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L007664d5: { // 0x7664d5: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L007664d8: { // 0x7664d8: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L007664da: { // 0x7664da: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L007664dc: { // 0x7664dc: 894e30 MOV dword ptr [ESI + 0x30],ECX
    m.w32((s.si+0x00000030u), s.cx);
  }
  L007664df: { // 0x7664df: 7e22 JLE 0x00766503
    if(integer::condition("JLE",flags)) goto L00766503;
  }
  L007664e1: { // 0x7664e1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L007664e3: { // 0x7664e3: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L007664e7: { // 0x7664e7: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L007664eb: { // 0x7664eb: 83c00c ADD EAX,0xc
    s.ax = integer::add(s.ax,0x0000000cu,32,flags);
  }
  L007664ee: { // 0x7664ee: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L007664f0: { // 0x7664f0: 895c02f4 MOV dword ptr [EDX + EAX*0x1 + -0xc],EBX
    m.w32((s.dx+(s.ax * 0x00000001u)-0x0000000cu), s.bx);
  }
  L007664f4: { // 0x7664f4: 8b09 MOV ECX,dword ptr [ECX]
    s.cx = m.r32((s.cx));
  }
  L007664f6: { // 0x7664f6: 03df ADD EBX,EDI
    s.bx = integer::add(s.bx,s.di,32,flags);
  }
  L007664f8: { // 0x7664f8: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L007664f9: { // 0x7664f9: c74401fcffffffff MOV dword ptr [ECX + EAX*0x1 + -0x4],0xffffffff
    m.w32((s.cx+(s.ax * 0x00000001u)-0x00000004u), 0xffffffffu);
  }
  L00766501: { // 0x766501: 75e0 JNZ 0x007664e3
    if(integer::condition("JNZ",flags)) goto L007664e3;
  }
  L00766503: { // 0x766503: 8b5c2424 MOV EBX,dword ptr [ESP + 0x24]
    s.bx = m.r32((f.sp+0x00000024u));
  }
  L00766507: { // 0x766507: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0076650b: { // 0x76650b: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0076650f: { // 0x76650f: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00766513: { // 0x766513: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00766514: { // 0x766514: 83c510 ADD EBP,0x10
    s.bp = integer::add(s.bp,0x00000010u,32,flags);
  }
  L00766517: { // 0x766517: 83c10c ADD ECX,0xc
    s.cx = integer::add(s.cx,0x0000000cu,32,flags);
  }
  L0076651a: { // 0x76651a: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0076651c: { // 0x76651c: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00766520: { // 0x766520: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L00766524: { // 0x766524: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00766528: { // 0x766528: 0f8205ffffff JC 0x00766433
    if(integer::condition("JC",flags)) goto L00766433;
  }
  L0076652e: { // 0x76652e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076652f: { // 0x76652f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00766530: { // 0x766530: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00766531: { // 0x766531: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00766534: { // 0x766534: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00766535: { // 0x766535: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00766538: { // 0x766538: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
