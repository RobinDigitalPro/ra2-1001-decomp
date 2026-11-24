#include "recovered/recovery_b211_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b211 {
namespace {
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
default:throw std::domain_error("recovery211 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006b2ec0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b2ec0: { // 0x6b2ec0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006b2ec1: { // 0x6b2ec1: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L006b2ec3: { // 0x6b2ec3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b2ec4: { // 0x6b2ec4: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  L006b2ec8: { // 0x6b2ec8: 8b4524 MOV EAX,dword ptr [EBP + 0x24]
    s.ax = m.r32((s.bp+0x00000024u));
  }
  L006b2ecb: { // 0x6b2ecb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b2ecc: { // 0x6b2ecc: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L006b2ece: { // 0x6b2ece: 8b80dc000000 MOV EAX,dword ptr [EAX + 0xdc]
    s.ax = m.r32((s.ax+0x000000dcu));
  }
  L006b2ed4: { // 0x6b2ed4: 8b889c000000 MOV ECX,dword ptr [EAX + 0x9c]
    s.cx = m.r32((s.ax+0x0000009cu));
  }
  L006b2eda: { // 0x6b2eda: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006b2edc: { // 0x6b2edc: 7e70 JLE 0x006b2f4e
    if(integer::condition("JLE",flags)) goto L006b2f4e;
  }
  L006b2ede: { // 0x6b2ede: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b2edf: { // 0x6b2edf: 8b9cf8a8000000 MOV EBX,dword ptr [EAX + EDI*0x8 + 0xa8]
    s.bx = m.r32((s.ax+(s.di * 0x00000008u)+0x000000a8u));
  }
  L006b2ee6: { // 0x6b2ee6: 8b84f8a4000000 MOV EAX,dword ptr [EAX + EDI*0x8 + 0xa4]
    s.ax = m.r32((s.ax+(s.di * 0x00000008u)+0x000000a4u));
  }
  L006b2eed: { // 0x6b2eed: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b2eef: { // 0x6b2eef: 7e4a JLE 0x006b2f3b
    if(integer::condition("JLE",flags)) goto L006b2f3b;
  }
  L006b2ef1: { // 0x6b2ef1: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006b2ef5: { // 0x6b2ef5: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L006b2ef8: { // 0x6b2ef8: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L006b2efb: { // 0x6b2efb: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006b2efd: { // 0x6b2efd: 7c22 JL 0x006b2f21
    if(integer::condition("JL",flags)) goto L006b2f21;
  }
  L006b2eff: { // 0x6b2eff: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  L006b2f02: { // 0x6b2f02: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b2f04: { // 0x6b2f04: 7504 JNZ 0x006b2f0a
    if(integer::condition("JNZ",flags)) goto L006b2f0a;
  }
  L006b2f06: { // 0x6b2f06: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006b2f08: { // 0x6b2f08: 7526 JNZ 0x006b2f30
    if(integer::condition("JNZ",flags)) goto L006b2f30;
  }
  L006b2f0a: { // 0x6b2f0a: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L006b2f0d: { // 0x6b2f0d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b2f0f: { // 0x6b2f0f: 7e1f JLE 0x006b2f30
    if(integer::condition("JLE",flags)) goto L006b2f30;
  }
  L006b2f11: { // 0x6b2f11: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b2f13: { // 0x6b2f13: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006b2f15: { // 0x6b2f15: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b2f17: { // 0x6b2f17: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b2f18: { // 0x6b2f18: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b2f1a: { // 0x6b2f1a: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),7024413u); flags=s.arithmetic_flags;
  }
  L006b2f1d: { // 0x6b2f1d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b2f1f: { // 0x6b2f1f: 740f JZ 0x006b2f30
    if(integer::condition("JZ",flags)) goto L006b2f30;
  }
  L006b2f21: { // 0x6b2f21: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L006b2f24: { // 0x6b2f24: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L006b2f27: { // 0x6b2f27: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L006b2f2a: { // 0x6b2f2a: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L006b2f2d: { // 0x6b2f2d: 891c82 MOV dword ptr [EDX + EAX*0x4],EBX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.bx);
  }
  L006b2f30: { // 0x6b2f30: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006b2f34: { // 0x6b2f34: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L006b2f35: { // 0x6b2f35: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006b2f39: { // 0x6b2f39: 75ba JNZ 0x006b2ef5
    if(integer::condition("JNZ",flags)) goto L006b2ef5;
  }
  L006b2f3b: { // 0x6b2f3b: 8b4524 MOV EAX,dword ptr [EBP + 0x24]
    s.ax = m.r32((s.bp+0x00000024u));
  }
  L006b2f3e: { // 0x6b2f3e: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L006b2f3f: { // 0x6b2f3f: 8b80dc000000 MOV EAX,dword ptr [EAX + 0xdc]
    s.ax = m.r32((s.ax+0x000000dcu));
  }
  L006b2f45: { // 0x6b2f45: 3bb89c000000 CMP EDI,dword ptr [EAX + 0x9c]
    (void)integer::sub(s.di,m.r32((s.ax+0x0000009cu)),32,flags);
  }
  L006b2f4b: { // 0x6b2f4b: 7c92 JL 0x006b2edf
    if(integer::condition("JL",flags)) goto L006b2edf;
  }
  L006b2f4d: { // 0x6b2f4d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b2f4e: { // 0x6b2f4e: 8b7d54 MOV EDI,dword ptr [EBP + 0x54]
    s.di = m.r32((s.bp+0x00000054u));
  }
  L006b2f51: { // 0x6b2f51: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006b2f53: { // 0x6b2f53: 744a JZ 0x006b2f9f
    if(integer::condition("JZ",flags)) goto L006b2f9f;
  }
  L006b2f55: { // 0x6b2f55: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006b2f57: { // 0x6b2f57: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006b2f59: { // 0x6b2f59: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7024479u); flags=s.arithmetic_flags;
  }
  L006b2f5f: { // 0x6b2f5f: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L006b2f63: { // 0x6b2f63: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006b2f67: { // 0x6b2f67: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b2f69: { // 0x6b2f69: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b2f6a: { // 0x6b2f6a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b2f6c: { // 0x6b2f6c: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),7024495u); flags=s.arithmetic_flags;
  }
  L006b2f6f: { // 0x6b2f6f: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006b2f72: { // 0x6b2f72: 7421 JZ 0x006b2f95
    if(integer::condition("JZ",flags)) goto L006b2f95;
  }
  L006b2f74: { // 0x6b2f74: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L006b2f77: { // 0x6b2f77: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006b2f79: { // 0x6b2f79: 7d1a JGE 0x006b2f95
    if(integer::condition("JGE",flags)) goto L006b2f95;
  }
  L006b2f7b: { // 0x6b2f7b: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L006b2f7c: { // 0x6b2f7c: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006b2f7e: { // 0x6b2f7e: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L006b2f81: { // 0x6b2f81: 7d12 JGE 0x006b2f95
    if(integer::condition("JGE",flags)) goto L006b2f95;
  }
  L006b2f83: { // 0x6b2f83: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L006b2f86: { // 0x6b2f86: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006b2f87: { // 0x6b2f87: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L006b2f8a: { // 0x6b2f8a: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L006b2f8e: { // 0x6b2f8e: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L006b2f91: { // 0x6b2f91: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006b2f93: { // 0x6b2f93: 7cee JL 0x006b2f83
    if(integer::condition("JL",flags)) goto L006b2f83;
  }
  L006b2f95: { // 0x6b2f95: 8bbfc8040000 MOV EDI,dword ptr [EDI + 0x4c8]
    s.di = m.r32((s.di+0x000004c8u));
  }
  L006b2f9b: { // 0x6b2f9b: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006b2f9d: { // 0x6b2f9d: 75b6 JNZ 0x006b2f55
    if(integer::condition("JNZ",flags)) goto L006b2f55;
  }
  L006b2f9f: { // 0x6b2f9f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b2fa0: { // 0x6b2fa0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b2fa1: { // 0x6b2fa1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b2fa2: { // 0x6b2fa2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
