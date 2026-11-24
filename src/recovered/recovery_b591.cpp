#include "recovered/recovery_b591_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b591 {
namespace {
void f_0012d0a0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0012d0a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0052d0a0: { // 0x52d0a0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0052d0a1: { // 0x52d0a1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0052d0a2: { // 0x52d0a2: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0052d0a4: { // 0x52d0a4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0052d0a6: { // 0x52d0a6: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0052d0a8: { // 0x52d0a8: 81e107000080 AND ECX,0x80000007
    s.cx = integer::logical((s.cx)&(0x80000007u),32,flags);
  }
  L0052d0ae: { // 0x52d0ae: 7905 JNS 0x0052d0b5
    if(integer::condition("JNS",flags)) goto L0052d0b5;
  }
  L0052d0b0: { // 0x52d0b0: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0052d0b1: { // 0x52d0b1: 83c9f8 OR ECX,0xfffffff8
    s.cx = integer::logical((s.cx)|(0xfffffff8u),32,flags);
  }
  L0052d0b4: { // 0x52d0b4: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0052d0b5: { // 0x52d0b5: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L0052d0b7: { // 0x52d0b7: d2e3 SHL BL,CL
    s.bx = with_al(s.bx, integer::shift((s.bx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L0052d0b9: { // 0x52d0b9: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0052d0bd: { // 0x52d0bd: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0052d0bf: { // 0x52d0bf: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0052d0c0: { // 0x52d0c0: 7415 JZ 0x0052d0d7
    if(integer::condition("JZ",flags)) goto L0052d0d7;
  }
  L0052d0c2: { // 0x52d0c2: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L0052d0c5: { // 0x52d0c5: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0052d0c7: { // 0x52d0c7: c1f803 SAR EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  L0052d0ca: { // 0x52d0ca: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0052d0cc: { // 0x52d0cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0052d0cd: { // 0x52d0cd: 8a08 MOV CL,byte ptr [EAX]
    s.cx = with_al(s.cx, m.r8((s.ax)));
  }
  L0052d0cf: { // 0x52d0cf: 0acb OR CL,BL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))|((s.bx & 0xffu)),8,flags));
  }
  L0052d0d1: { // 0x52d0d1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0052d0d2: { // 0x52d0d2: 8808 MOV byte ptr [EAX],CL
    m.w8((s.ax), (s.cx & 0xffu));
  }
  L0052d0d4: { // 0x52d0d4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0052d0d7: { // 0x52d0d7: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L0052d0da: { // 0x52d0da: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0052d0dc: { // 0x52d0dc: c1f803 SAR EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  L0052d0df: { // 0x52d0df: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0052d0e1: { // 0x52d0e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0052d0e2: { // 0x52d0e2: f6d3 NOT BL
    s.bx = with_al(s.bx, (~((s.bx & 0xffu))&integer::mask(8)));
  }
  L0052d0e4: { // 0x52d0e4: 8a08 MOV CL,byte ptr [EAX]
    s.cx = with_al(s.cx, m.r8((s.ax)));
  }
  L0052d0e6: { // 0x52d0e6: 22cb AND CL,BL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&((s.bx & 0xffu)),8,flags));
  }
  L0052d0e8: { // 0x52d0e8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0052d0e9: { // 0x52d0e9: 8808 MOV byte ptr [EAX],CL
    m.w8((s.ax), (s.cx & 0xffu));
  }
  L0052d0eb: { // 0x52d0eb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5427360u:f_0012d0a0(m,s,child,{});break;
default:throw std::domain_error("recovery591 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00703c80(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00703c80: { // 0x703c80: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00703c81: { // 0x703c81: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00703c82: { // 0x703c82: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00703c83: { // 0x703c83: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00703c84: { // 0x703c84: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00703c86: { // 0x703c86: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  L00703c89: { // 0x703c89: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L00703c8c: { // 0x703c8c: 7415 JZ 0x00703ca3
    if(integer::condition("JZ",flags)) goto L00703ca3;
  }
  L00703c8e: { // 0x703c8e: 8b4f10 MOV ECX,dword ptr [EDI + 0x10]
    s.cx = m.r32((s.di+0x00000010u));
  }
  L00703c91: { // 0x703c91: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00703c93: { // 0x703c93: 8a4704 MOV AL,byte ptr [EDI + 0x4]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000004u)));
  }
  L00703c96: { // 0x703c96: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00703c97: { // 0x703c97: e80494e2ff CALL 0x0052d0a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0052d0a0u,7355548u); flags=s.arithmetic_flags;
  }
  L00703c9c: { // 0x703c9c: c74708ffffffff MOV dword ptr [EDI + 0x8],0xffffffff
    m.w32((s.di+0x00000008u), 0xffffffffu);
  }
  L00703ca3: { // 0x703ca3: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L00703ca7: { // 0x703ca7: 8d770c LEA ESI,[EDI + 0xc]
    s.si = (s.di+0x0000000cu);
  }
  L00703caa: { // 0x703caa: 8a4b04 MOV CL,byte ptr [EBX + 0x4]
    s.cx = with_al(s.cx, m.r8((s.bx+0x00000004u)));
  }
  L00703cad: { // 0x703cad: 8d6b0c LEA EBP,[EBX + 0xc]
    s.bp = (s.bx+0x0000000cu);
  }
  L00703cb0: { // 0x703cb0: 884f04 MOV byte ptr [EDI + 0x4],CL
    m.w8((s.di+0x00000004u), (s.cx & 0xffu));
  }
  L00703cb3: { // 0x703cb3: 8b5308 MOV EDX,dword ptr [EBX + 0x8]
    s.dx = m.r32((s.bx+0x00000008u));
  }
  L00703cb6: { // 0x703cb6: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L00703cb8: { // 0x703cb8: 895708 MOV dword ptr [EDI + 0x8],EDX
    m.w32((s.di+0x00000008u), s.dx);
  }
  L00703cbb: { // 0x703cbb: 745a JZ 0x00703d17
    if(integer::condition("JZ",flags)) goto L00703d17;
  }
  L00703cbd: { // 0x703cbd: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00703cbf: { // 0x703cbf: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00703cc1: { // 0x703cc1: ff500c CALL dword ptr [EAX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000000cu)),7355588u); flags=s.arithmetic_flags;
  }
  L00703cc4: { // 0x703cc4: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00703cc7: { // 0x703cc7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00703cc9: { // 0x703cc9: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L00703ccc: { // 0x703ccc: 743e JZ 0x00703d0c
    if(integer::condition("JZ",flags)) goto L00703d0c;
  }
  L00703cce: { // 0x703cce: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00703ccf: { // 0x703ccf: e8839c0600 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7355604u); flags=s.arithmetic_flags;
  }
  L00703cd4: { // 0x703cd4: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00703cd7: { // 0x703cd7: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L00703cda: { // 0x703cda: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00703cdc: { // 0x703cdc: 7439 JZ 0x00703d17
    if(integer::condition("JZ",flags)) goto L00703d17;
  }
  L00703cde: { // 0x703cde: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00703ce1: { // 0x703ce1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00703ce3: { // 0x703ce3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00703ce5: { // 0x703ce5: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L00703ce9: { // 0x703ce9: 7e2c JLE 0x00703d17
    if(integer::condition("JLE",flags)) goto L00703d17;
  }
  L00703ceb: { // 0x703ceb: 8b4d04 MOV ECX,dword ptr [EBP + 0x4]
    s.cx = m.r32((s.bp+0x00000004u));
  }
  L00703cee: { // 0x703cee: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L00703cf1: { // 0x703cf1: 8a0c08 MOV CL,byte ptr [EAX + ECX*0x1]
    s.cx = with_al(s.cx, m.r8((s.ax+(s.cx * 0x00000001u))));
  }
  L00703cf4: { // 0x703cf4: 880c02 MOV byte ptr [EDX + EAX*0x1],CL
    m.w8((s.dx+(s.ax * 0x00000001u)), (s.cx & 0xffu));
  }
  L00703cf7: { // 0x703cf7: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00703cfa: { // 0x703cfa: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00703cfb: { // 0x703cfb: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00703cfd: { // 0x703cfd: 7cec JL 0x00703ceb
    if(integer::condition("JL",flags)) goto L00703ceb;
  }
  L00703cff: { // 0x703cff: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00703d01: { // 0x703d01: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00703d03: { // 0x703d03: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L00703d05: { // 0x703d05: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00703d06: { // 0x703d06: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00703d07: { // 0x703d07: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00703d08: { // 0x703d08: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00703d09: { // 0x703d09: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00703d0c: { // 0x703d0c: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L00703d13: { // 0x703d13: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L00703d17: { // 0x703d17: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00703d19: { // 0x703d19: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00703d1b: { // 0x703d1b: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L00703d1d: { // 0x703d1d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00703d1e: { // 0x703d1e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00703d1f: { // 0x703d1f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00703d20: { // 0x703d20: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00703d21: { // 0x703d21: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
