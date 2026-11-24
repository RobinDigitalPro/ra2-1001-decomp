#include "recovered/recovery_b747_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b747 {
namespace {
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
default:throw std::domain_error("recovery747 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004f50e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f50e0: { // 0x4f50e0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L004f50e3: { // 0x4f50e3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004f50e4: { // 0x4f50e4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004f50e5: { // 0x4f50e5: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L004f50e7: { // 0x4f50e7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f50e8: { // 0x4f50e8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f50e9: { // 0x4f50e9: 8b4d78 MOV ECX,dword ptr [EBP + 0x78]
    s.cx = m.r32((s.bp+0x00000078u));
  }
  L004f50ec: { // 0x4f50ec: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004f50ed: { // 0x4f50ed: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L004f50f1: { // 0x4f50f1: 0f8829010000 JS 0x004f5220
    if(integer::condition("JS",flags)) goto L004f5220;
  }
  L004f50f7: { // 0x4f50f7: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004f50fc: { // 0x4f50fc: 8b556c MOV EDX,dword ptr [EBP + 0x6c]
    s.dx = m.r32((s.bp+0x0000006cu));
  }
  L004f50ff: { // 0x4f50ff: 8bb0d8070000 MOV ESI,dword ptr [EAX + 0x7d8]
    s.si = m.r32((s.ax+0x000007d8u));
  }
  L004f5105: { // 0x4f5105: 8d1c8a LEA EBX,[EDX + ECX*0x4]
    s.bx = (s.dx+(s.cx * 0x00000004u));
  }
  L004f5108: { // 0x4f5108: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L004f510a: { // 0x4f510a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f510c: { // 0x4f510c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004f510e: { // 0x4f510e: 7e2b JLE 0x004f513b
    if(integer::condition("JLE",flags)) goto L004f513b;
  }
  L004f5110: { // 0x4f5110: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L004f5116: { // 0x4f5116: 8bba18040000 MOV EDI,dword ptr [EDX + 0x418]
    s.di = m.r32((s.dx+0x00000418u));
  }
  L004f511c: { // 0x4f511c: 8b89cc070000 MOV ECX,dword ptr [ECX + 0x7cc]
    s.cx = m.r32((s.cx+0x000007ccu));
  }
  L004f5122: { // 0x4f5122: 3939 CMP dword ptr [ECX],EDI
    (void)integer::sub(m.r32((s.cx)),s.di,32,flags);
  }
  L004f5124: { // 0x4f5124: 740a JZ 0x004f5130
    if(integer::condition("JZ",flags)) goto L004f5130;
  }
  L004f5126: { // 0x4f5126: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004f5127: { // 0x4f5127: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L004f512a: { // 0x4f512a: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L004f512c: { // 0x4f512c: 7cf4 JL 0x004f5122
    if(integer::condition("JL",flags)) goto L004f5122;
  }
  L004f512e: { // 0x4f512e: eb07 JMP 0x004f5137
    goto L004f5137;
  }
  L004f5130: { // 0x4f5130: 8a4276 MOV AL,byte ptr [EDX + 0x76]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000076u)));
  }
  L004f5133: { // 0x4f5133: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f5135: { // 0x4f5135: 7418 JZ 0x004f514f
    if(integer::condition("JZ",flags)) goto L004f514f;
  }
  L004f5137: { // 0x4f5137: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L004f513b: { // 0x4f513b: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004f513c: { // 0x4f513c: 83eb04 SUB EBX,0x4
    s.bx = integer::sub(s.bx,0x00000004u,32,flags);
  }
  L004f513f: { // 0x4f513f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004f5141: { // 0x4f5141: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L004f5145: { // 0x4f5145: 7dc1 JGE 0x004f5108
    if(integer::condition("JGE",flags)) goto L004f5108;
  }
  L004f5147: { // 0x4f5147: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f5148: { // 0x4f5148: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f5149: { // 0x4f5149: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004f514a: { // 0x4f514a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f514b: { // 0x4f514b: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004f514e: { // 0x4f514e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004f514f: { // 0x4f514f: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004f5151: { // 0x4f5151: 0f84c9000000 JZ 0x004f5220
    if(integer::condition("JZ",flags)) goto L004f5220;
  }
  L004f5157: { // 0x4f5157: 81c288000000 ADD EDX,0x88
    s.dx = integer::add(s.dx,0x00000088u,32,flags);
  }
  L004f515d: { // 0x4f515d: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L004f515f: { // 0x4f515f: 8b7204 MOV ESI,dword ptr [EDX + 0x4]
    s.si = m.r32((s.dx+0x00000004u));
  }
  L004f5162: { // 0x4f5162: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L004f5165: { // 0x4f5165: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L004f5169: { // 0x4f5169: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004f516a: { // 0x4f516a: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004f5170: { // 0x4f5170: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004f5172: { // 0x4f5172: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004f5174: { // 0x4f5174: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004f5176: { // 0x4f5176: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004f5177: { // 0x4f5177: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004f517d: { // 0x4f517d: 8db5bc530000 LEA ESI,[EBP + 0x53bc]
    s.si = (s.bp+0x000053bcu);
  }
  L004f5183: { // 0x4f5183: c1f908 SAR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004f5186: { // 0x4f5186: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004f5188: { // 0x4f5188: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L004f518d: { // 0x4f518d: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004f5190: { // 0x4f5190: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L004f5193: { // 0x4f5193: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L004f5198: { // 0x4f5198: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004f519a: { // 0x4f519a: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004f519d: { // 0x4f519d: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L004f51a0: { // 0x4f51a0: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L004f51a6: { // 0x4f51a6: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L004f51a9: { // 0x4f51a9: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L004f51ab: { // 0x4f51ab: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L004f51b0: { // 0x4f51b0: 8a8d34010000 MOV CL,byte ptr [EBP + 0x134]
    s.cx = with_al(s.cx, m.r8((s.bp+0x00000134u)));
  }
  L004f51b6: { // 0x4f51b6: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L004f51b9: { // 0x4f51b9: 895608 MOV dword ptr [ESI + 0x8],EDX
    m.w32((s.si+0x00000008u), s.dx);
  }
  L004f51bc: { // 0x4f51bc: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004f51c1: { // 0x4f51c1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f51c3: { // 0x4f51c3: 7514 JNZ 0x004f51d9
    if(integer::condition("JNZ",flags)) goto L004f51d9;
  }
  L004f51c5: { // 0x4f51c5: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f51c7: { // 0x4f51c7: 750e JNZ 0x004f51d7
    if(integer::condition("JNZ",flags)) goto L004f51d7;
  }
  L004f51c9: { // 0x4f51c9: 8a8d35010000 MOV CL,byte ptr [EBP + 0x135]
    s.cx = with_al(s.cx, m.r8((s.bp+0x00000135u)));
  }
  L004f51cf: { // 0x4f51cf: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f51d1: { // 0x4f51d1: 7504 JNZ 0x004f51d7
    if(integer::condition("JNZ",flags)) goto L004f51d7;
  }
  L004f51d3: { // 0x4f51d3: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  L004f51d5: { // 0x4f51d5: eb02 JMP 0x004f51d9
    goto L004f51d9;
  }
  L004f51d7: { // 0x4f51d7: b101 MOV CL,0x1
    s.cx = with_al(s.cx, 0x00000001u);
  }
  L004f51d9: { // 0x4f51d9: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004f51db: { // 0x4f51db: 7509 JNZ 0x004f51e6
    if(integer::condition("JNZ",flags)) goto L004f51e6;
  }
  L004f51dd: { // 0x4f51dd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f51df: { // 0x4f51df: 7405 JZ 0x004f51e6
    if(integer::condition("JZ",flags)) goto L004f51e6;
  }
  L004f51e1: { // 0x4f51e1: e81a69ffff CALL 0x004ebb00
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ebb00u,5198310u); flags=s.arithmetic_flags;
  }
  L004f51e6: { // 0x4f51e6: 8b8504560000 MOV EAX,dword ptr [EBP + 0x5604]
    s.ax = m.r32((s.bp+0x00005604u));
  }
  L004f51ec: { // 0x4f51ec: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f51ee: { // 0x4f51ee: 751d JNZ 0x004f520d
    if(integer::condition("JNZ",flags)) goto L004f520d;
  }
  L004f51f0: { // 0x4f51f0: 8b35c483a200 MOV ESI,dword ptr [0x00a283c4]
    s.si = m.r32((0x00a283c4u));
  }
  L004f51f6: { // 0x4f51f6: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004f51f8: { // 0x4f51f8: c705c483a20000000000 MOV dword ptr [0x00a283c4],0x0
    m.w32((0x00a283c4u), 0x00000000u);
  }
  L004f5202: { // 0x4f5202: e8899bffff CALL 0x004eed90
    s.arithmetic_flags=flags; invoke(m,s,f,0x004eed90u,5198343u); flags=s.arithmetic_flags;
  }
  L004f5207: { // 0x4f5207: 8935c483a200 MOV dword ptr [0x00a283c4],ESI
    m.w32((0x00a283c4u), s.si);
  }
  L004f520d: { // 0x4f520d: 8b8df8550000 MOV ECX,dword ptr [EBP + 0x55f8]
    s.cx = m.r32((s.bp+0x000055f8u));
  }
  L004f5213: { // 0x4f5213: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004f5217: { // 0x4f5217: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L004f521a: { // 0x4f521a: 898540560000 MOV dword ptr [EBP + 0x5640],EAX
    m.w32((s.bp+0x00005640u), s.ax);
  }
  L004f5220: { // 0x4f5220: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f5221: { // 0x4f5221: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f5222: { // 0x4f5222: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004f5223: { // 0x4f5223: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f5224: { // 0x4f5224: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004f5227: { // 0x4f5227: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
