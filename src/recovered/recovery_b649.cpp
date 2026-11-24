#include "recovered/recovery_b649_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b649 {
namespace {
void f_0022c4f0(Memory&,State&,Frame&,const Operations&);
void f_00229ca0(Memory&,State&,Frame&,const Operations&);
void f_000112c0(Memory&,State&,Frame&,const Operations&);
void f_000112d0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0022c4f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062c4f0: { // 0x62c4f0: 8b5110 MOV EDX, dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L0062c4f3: { // 0x62c4f3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062c4f4: { // 0x62c4f4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062c4f5: { // 0x62c4f5: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062c4f7: { // 0x62c4f7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062c4f8: { // 0x62c4f8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062c4f9: { // 0x62c4f9: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0062c4fb: { // 0x62c4fb: 7e29 JLE 0x62c526
    if(integer::condition("JLE",flags)) goto L0062c526;
  }
  L0062c4fd: { // 0x62c4fd: 8b742414 MOV ESI, dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0062c501: { // 0x62c501: 8b4904 MOV ECX, dword ptr [ECX + 4]
    s.cx = m.r32((s.cx+4u));
  }
  L0062c504: { // 0x62c504: 8b3e MOV EDI, dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  L0062c506: { // 0x62c506: 3939 CMP dword ptr [ECX], EDI
    (void)integer::sub(m.r32((s.cx)),s.di,32,flags);
  }
  L0062c508: { // 0x62c508: 7514 JNZ 0x62c51e
    if(integer::condition("JNZ",flags)) goto L0062c51e;
  }
  L0062c50a: { // 0x62c50a: 8b5904 MOV EBX, dword ptr [ECX + 4]
    s.bx = m.r32((s.cx+4u));
  }
  L0062c50d: { // 0x62c50d: 8b6e04 MOV EBP, dword ptr [ESI + 4]
    s.bp = m.r32((s.si+4u));
  }
  L0062c510: { // 0x62c510: 3bdd CMP EBX, EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L0062c512: { // 0x62c512: 750a JNZ 0x62c51e
    if(integer::condition("JNZ",flags)) goto L0062c51e;
  }
  L0062c514: { // 0x62c514: 8b5908 MOV EBX, dword ptr [ECX + 8]
    s.bx = m.r32((s.cx+8u));
  }
  L0062c517: { // 0x62c517: 8b6e08 MOV EBP, dword ptr [ESI + 8]
    s.bp = m.r32((s.si+8u));
  }
  L0062c51a: { // 0x62c51a: 3bdd CMP EBX, EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L0062c51c: { // 0x62c51c: 740b JZ 0x62c529
    if(integer::condition("JZ",flags)) goto L0062c529;
  }
  L0062c51e: { // 0x62c51e: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062c51f: { // 0x62c51f: 83c110 ADD ECX, 0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L0062c522: { // 0x62c522: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0062c524: { // 0x62c524: 7ce0 JL 0x62c506
    if(integer::condition("JL",flags)) goto L0062c506;
  }
  L0062c526: { // 0x62c526: 83c8ff OR EAX, 0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0062c529: { // 0x62c529: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062c52a: { // 0x62c52a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062c52b: { // 0x62c52b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062c52c: { // 0x62c52c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062c52d: { // 0x62c52d: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00229ca0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00629ca0: { // 0x629ca0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00629ca1: { // 0x629ca1: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  L00629ca5: { // 0x629ca5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00629ca6: { // 0x629ca6: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00629ca8: { // 0x629ca8: 833b00 CMP dword ptr [EBX],0x0
    (void)integer::sub(m.r32((s.bx)),0x00000000u,32,flags);
  }
  L00629cab: { // 0x629cab: 0f8cbc000000 JL 0x00629d6d
    if(integer::condition("JL",flags)) goto L00629d6d;
  }
  L00629cb1: { // 0x629cb1: 8b8f18120000 MOV ECX,dword ptr [EDI + 0x1218]
    s.cx = m.r32((s.di+0x00001218u));
  }
  L00629cb7: { // 0x629cb7: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00629cb9: { // 0x629cb9: ff507c CALL dword ptr [EAX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000007cu)),6462652u); flags=s.arithmetic_flags;
  }
  L00629cbc: { // 0x629cbc: 3903 CMP dword ptr [EBX],EAX
    (void)integer::sub(m.r32((s.bx)),s.ax,32,flags);
  }
  L00629cbe: { // 0x629cbe: 0f8da9000000 JGE 0x00629d6d
    if(integer::condition("JGE",flags)) goto L00629d6d;
  }
  L00629cc4: { // 0x629cc4: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L00629cc7: { // 0x629cc7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00629cc9: { // 0x629cc9: 0f8c9e000000 JL 0x00629d6d
    if(integer::condition("JL",flags)) goto L00629d6d;
  }
  L00629ccf: { // 0x629ccf: 8b8f18120000 MOV ECX,dword ptr [EDI + 0x1218]
    s.cx = m.r32((s.di+0x00001218u));
  }
  L00629cd5: { // 0x629cd5: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00629cd7: { // 0x629cd7: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),6462685u); flags=s.arithmetic_flags;
  }
  L00629cdd: { // 0x629cdd: 394304 CMP dword ptr [EBX + 0x4],EAX
    (void)integer::sub(m.r32((s.bx+0x00000004u)),s.ax,32,flags);
  }
  L00629ce0: { // 0x629ce0: 0f8d87000000 JGE 0x00629d6d
    if(integer::condition("JGE",flags)) goto L00629d6d;
  }
  L00629ce6: { // 0x629ce6: 8b8f18120000 MOV ECX,dword ptr [EDI + 0x1218]
    s.cx = m.r32((s.di+0x00001218u));
  }
  L00629cec: { // 0x629cec: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00629cee: { // 0x629cee: ff507c CALL dword ptr [EAX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000007cu)),6462705u); flags=s.arithmetic_flags;
  }
  L00629cf1: { // 0x629cf1: 0faf4304 IMUL EAX,dword ptr [EBX + 0x4]
    s.ax = integer::imul(s.ax,m.r32((s.bx+0x00000004u)),32,flags);
  }
  L00629cf5: { // 0x629cf5: 0303 ADD EAX,dword ptr [EBX]
    s.ax = integer::add(s.ax,m.r32((s.bx)),32,flags);
  }
  L00629cf7: { // 0x629cf7: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00629cf9: { // 0x629cf9: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00629cfb: { // 0x629cfb: 83e107 AND ECX,0x7
    s.cx = integer::logical((s.cx)&(0x00000007u),32,flags);
  }
  L00629cfe: { // 0x629cfe: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00629d03: { // 0x629d03: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00629d05: { // 0x629d05: 8b8f70120000 MOV ECX,dword ptr [EDI + 0x1270]
    s.cx = m.r32((s.di+0x00001270u));
  }
  L00629d0b: { // 0x629d0b: c1fa03 SAR EDX,0x3
    s.dx = integer::shift(s.dx,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  L00629d0e: { // 0x629d0e: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00629d10: { // 0x629d10: 8a0a MOV CL,byte ptr [EDX]
    s.cx = with_al(s.cx, m.r8((s.dx)));
  }
  L00629d12: { // 0x629d12: 84c8 TEST AL,CL
    (void)integer::logical(((s.ax & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00629d14: { // 0x629d14: 7557 JNZ 0x00629d6d
    if(integer::condition("JNZ",flags)) goto L00629d6d;
  }
  L00629d16: { // 0x629d16: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00629d17: { // 0x629d17: 0ac8 OR CL,AL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))|((s.ax & 0xffu)),8,flags));
  }
  L00629d19: { // 0x629d19: 8db758120000 LEA ESI,[EDI + 0x1258]
    s.si = (s.di+0x00001258u);
  }
  L00629d1f: { // 0x629d1f: 880a MOV byte ptr [EDX],CL
    m.w8((s.dx), (s.cx & 0xffu));
  }
  L00629d21: { // 0x629d21: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00629d24: { // 0x629d24: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L00629d27: { // 0x629d27: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00629d29: { // 0x629d29: 7c22 JL 0x00629d4d
    if(integer::condition("JL",flags)) goto L00629d4d;
  }
  L00629d2b: { // 0x629d2b: 8a4e0d MOV CL,byte ptr [ESI + 0xd]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000000du)));
  }
  L00629d2e: { // 0x629d2e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00629d30: { // 0x629d30: 7504 JNZ 0x00629d36
    if(integer::condition("JNZ",flags)) goto L00629d36;
  }
  L00629d32: { // 0x629d32: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00629d34: { // 0x629d34: 752f JNZ 0x00629d65
    if(integer::condition("JNZ",flags)) goto L00629d65;
  }
  L00629d36: { // 0x629d36: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00629d39: { // 0x629d39: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00629d3b: { // 0x629d3b: 7e28 JLE 0x00629d65
    if(integer::condition("JLE",flags)) goto L00629d65;
  }
  L00629d3d: { // 0x629d3d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00629d3f: { // 0x629d3f: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00629d41: { // 0x629d41: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00629d43: { // 0x629d43: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00629d44: { // 0x629d44: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00629d46: { // 0x629d46: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6462793u); flags=s.arithmetic_flags;
  }
  L00629d49: { // 0x629d49: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00629d4b: { // 0x629d4b: 7418 JZ 0x00629d65
    if(integer::condition("JZ",flags)) goto L00629d65;
  }
  L00629d4d: { // 0x629d4d: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00629d50: { // 0x629d50: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L00629d53: { // 0x629d53: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L00629d56: { // 0x629d56: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L00629d59: { // 0x629d59: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L00629d5b: { // 0x629d5b: 890cc2 MOV dword ptr [EDX + EAX*0x8],ECX
    m.w32((s.dx+(s.ax * 0x00000008u)), s.cx);
  }
  L00629d5e: { // 0x629d5e: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L00629d61: { // 0x629d61: 894cc204 MOV dword ptr [EDX + EAX*0x8 + 0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000008u)+0x00000004u), s.cx);
  }
  L00629d65: { // 0x629d65: c687d514000001 MOV byte ptr [EDI + 0x14d5],0x1
    m.w8((s.di+0x000014d5u), 0x00000001u);
  }
  L00629d6c: { // 0x629d6c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00629d6d: { // 0x629d6d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00629d6e: { // 0x629d6e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00629d6f: { // 0x629d6f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000112c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112c0: { // 0x4112c0: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L004112c3: { // 0x4112c3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000112d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112d0: { // 0x4112d0: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L004112d3: { // 0x4112d3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6472944u:f_0022c4f0(m,s,child,{});break;
case 6462624u:f_00229ca0(m,s,child,{});break;
case 4264640u:f_000112c0(m,s,child,{});break;
case 4264656u:f_000112d0(m,s,child,{});break;
default:throw std::domain_error("recovery649 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00629170(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00629170: { // 0x629170: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00629173: { // 0x629173: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00629174: { // 0x629174: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00629178: { // 0x629178: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00629179: { // 0x629179: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0062917b: { // 0x62917b: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0062917f: { // 0x62917f: 8d0489 LEA EAX,[ECX + ECX*0x4]
    s.ax = (s.cx+(s.cx * 0x00000004u));
  }
  L00629182: { // 0x629182: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00629184: { // 0x629184: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00629186: { // 0x629186: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L00629188: { // 0x629188: 8bb754120000 MOV ESI,dword ptr [EDI + 0x1254]
    s.si = m.r32((s.di+0x00001254u));
  }
  L0062918e: { // 0x62918e: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L00629193: { // 0x629193: 8b36 MOV ESI,dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L00629195: { // 0x629195: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L00629199: { // 0x629199: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0062919c: { // 0x62919c: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L006291a0: { // 0x6291a0: 8d34c6 LEA ESI,[ESI + EAX*0x8]
    s.si = (s.si+(s.ax * 0x00000008u));
  }
  L006291a3: { // 0x6291a3: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L006291a7: { // 0x6291a7: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L006291ab: { // 0x6291ab: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006291af: { // 0x6291af: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006291b1: { // 0x6291b1: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L006291b5: { // 0x6291b5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006291b6: { // 0x6291b6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006291b8: { // 0x6291b8: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6459835u); flags=s.arithmetic_flags;
  }
  L006291bb: { // 0x6291bb: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006291be: { // 0x6291be: 7455 JZ 0x00629215
    if(integer::condition("JZ",flags)) goto L00629215;
  }
  L006291c0: { // 0x6291c0: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L006291c3: { // 0x6291c3: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006291c5: { // 0x6291c5: 7d4e JGE 0x00629215
    if(integer::condition("JGE",flags)) goto L00629215;
  }
  L006291c7: { // 0x6291c7: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L006291c8: { // 0x6291c8: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L006291ca: { // 0x6291ca: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006291cc: { // 0x6291cc: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L006291cf: { // 0x6291cf: 7d31 JGE 0x00629202
    if(integer::condition("JGE",flags)) goto L00629202;
  }
  L006291d1: { // 0x6291d1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006291d2: { // 0x6291d2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006291d3: { // 0x6291d3: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L006291d6: { // 0x6291d6: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L006291d9: { // 0x6291d9: 8d5c0810 LEA EBX,[EAX + ECX*0x1 + 0x10]
    s.bx = (s.ax+(s.cx * 0x00000001u)+0x00000010u);
  }
  L006291dd: { // 0x6291dd: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006291df: { // 0x6291df: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L006291e0: { // 0x6291e0: 83c010 ADD EAX,0x10
    s.ax = integer::add(s.ax,0x00000010u,32,flags);
  }
  L006291e3: { // 0x6291e3: 8b2b MOV EBP,dword ptr [EBX]
    s.bp = m.r32((s.bx));
  }
  L006291e5: { // 0x6291e5: 8929 MOV dword ptr [ECX],EBP
    m.w32((s.cx), s.bp);
  }
  L006291e7: { // 0x6291e7: 8b6b04 MOV EBP,dword ptr [EBX + 0x4]
    s.bp = m.r32((s.bx+0x00000004u));
  }
  L006291ea: { // 0x6291ea: 896904 MOV dword ptr [ECX + 0x4],EBP
    m.w32((s.cx+0x00000004u), s.bp);
  }
  L006291ed: { // 0x6291ed: 8b6b08 MOV EBP,dword ptr [EBX + 0x8]
    s.bp = m.r32((s.bx+0x00000008u));
  }
  L006291f0: { // 0x6291f0: 896908 MOV dword ptr [ECX + 0x8],EBP
    m.w32((s.cx+0x00000008u), s.bp);
  }
  L006291f3: { // 0x6291f3: 8b5b0c MOV EBX,dword ptr [EBX + 0xc]
    s.bx = m.r32((s.bx+0x0000000cu));
  }
  L006291f6: { // 0x6291f6: 89590c MOV dword ptr [ECX + 0xc],EBX
    m.w32((s.cx+0x0000000cu), s.bx);
  }
  L006291f9: { // 0x6291f9: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L006291fc: { // 0x6291fc: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L006291fe: { // 0x6291fe: 7cd6 JL 0x006291d6
    if(integer::condition("JL",flags)) goto L006291d6;
  }
  L00629200: { // 0x629200: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00629201: { // 0x629201: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00629202: { // 0x629202: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L00629206: { // 0x629206: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00629208: { // 0x629208: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00629209: { // 0x629209: e8920a0000 CALL 0x00629ca0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00629ca0u,6459918u); flags=s.arithmetic_flags;
  }
  L0062920e: { // 0x62920e: c687d514000001 MOV byte ptr [EDI + 0x14d5],0x1
    m.w8((s.di+0x000014d5u), 0x00000001u);
  }
  L00629215: { // 0x629215: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00629216: { // 0x629216: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00629217: { // 0x629217: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0062921a: { // 0x62921a: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
