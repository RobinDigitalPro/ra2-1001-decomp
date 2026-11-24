#include "recovered/recovery_b534_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b534 {
namespace {
void f_0036e2ca(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0036e2ca(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076e2ca: { // 0x0076e2ca: ff742404 PUSH dword ptr [ESP + 0x4]
    f.push(m,m.r32((f.sp+0x00000004u)));
  }
  L0076e2ce: { // 0x0076e2ce: e879ffffff CALL 0x0076e24c
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076e24cu,7791315u); flags=s.arithmetic_flags;
  }
  L0076e2d3: { // 0x0076e2d3: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0076e2d5: { // 0x0076e2d5: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L0076e2d7: { // 0x0076e2d7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076e2d8: { // 0x0076e2d8: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0076e2da: { // 0x0076e2da: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0076e2db: { // 0x0076e2db: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7791306u:f_0036e2ca(m,s,child,{});break;
default:throw std::domain_error("recovery534 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00529b10(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00529b10: { // 0x529b10: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00529b13: { // 0x529b13: 8a81b1020000 MOV AL,byte ptr [ECX + 0x2b1]
    s.ax = with_al(s.ax, m.r8((s.cx+0x000002b1u)));
  }
  L00529b19: { // 0x529b19: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00529b1a: { // 0x529b1a: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00529b1c: { // 0x529b1c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00529b1d: { // 0x529b1d: 3ac3 CMP AL,BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  L00529b1f: { // 0x529b1f: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L00529b23: { // 0x529b23: 0f8432090000 JZ 0x0052a45b
    if(integer::condition("JZ",flags)) goto L0052a45b;
  }
  L00529b29: { // 0x529b29: a0a8a8a300 MOV AL,[0x00a3a8a8]
    s.ax = with_al(s.ax, m.r8((0x00a3a8a8u)));
  }
  L00529b2e: { // 0x529b2e: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00529b30: { // 0x529b30: 0f8502090000 JNZ 0x0052a438
    if(integer::condition("JNZ",flags)) goto L0052a438;
  }
  L00529b36: { // 0x529b36: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  L00529b38: { // 0x529b38: b9ff7f0000 MOV ECX,0x7fff
    s.cx = 0x00007fffu;
  }
  L00529b3d: { // 0x529b3d: 80ca01 OR DL,0x1
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))|(0x00000001u),8,flags));
  }
  L00529b40: { // 0x529b40: 66894c2408 MOV word ptr [ESP + 0x8],CX
    m.w16((f.sp+0x00000008u), (s.cx & 0xffffu));
  }
  L00529b45: { // 0x529b45: 8815a8a8a300 MOV byte ptr [0x00a3a8a8],DL
    m.w8((0x00a3a8a8u), (s.dx & 0xffu));
  }
  L00529b4b: { // 0x529b4b: 66894c240a MOV word ptr [ESP + 0xa],CX
    m.w16((f.sp+0x0000000au), (s.cx & 0xffffu));
  }
  L00529b50: { // 0x529b50: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00529b54: { // 0x529b54: 66894c2408 MOV word ptr [ESP + 0x8],CX
    m.w16((f.sp+0x00000008u), (s.cx & 0xffffu));
  }
  L00529b59: { // 0x529b59: 8915cc47a500 MOV dword ptr [0x00a547cc],EDX
    m.w32((0x00a547ccu), s.dx);
  }
  L00529b5f: { // 0x529b5f: 66894c240a MOV word ptr [ESP + 0xa],CX
    m.w16((f.sp+0x0000000au), (s.cx & 0xffffu));
  }
  L00529b64: { // 0x529b64: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00529b68: { // 0x529b68: 66894c2408 MOV word ptr [ESP + 0x8],CX
    m.w16((f.sp+0x00000008u), (s.cx & 0xffffu));
  }
  L00529b6d: { // 0x529b6d: 8915e447a500 MOV dword ptr [0x00a547e4],EDX
    m.w32((0x00a547e4u), s.dx);
  }
  L00529b73: { // 0x529b73: 66894c240a MOV word ptr [ESP + 0xa],CX
    m.w16((f.sp+0x0000000au), (s.cx & 0xffffu));
  }
  L00529b78: { // 0x529b78: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00529b7c: { // 0x529b7c: 66894c2408 MOV word ptr [ESP + 0x8],CX
    m.w16((f.sp+0x00000008u), (s.cx & 0xffffu));
  }
  L00529b81: { // 0x529b81: 8915fc47a500 MOV dword ptr [0x00a547fc],EDX
    m.w32((0x00a547fcu), s.dx);
  }
  L00529b87: { // 0x529b87: 66894c240a MOV word ptr [ESP + 0xa],CX
    m.w16((f.sp+0x0000000au), (s.cx & 0xffffu));
  }
  L00529b8c: { // 0x529b8c: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00529b90: { // 0x529b90: 66894c2408 MOV word ptr [ESP + 0x8],CX
    m.w16((f.sp+0x00000008u), (s.cx & 0xffffu));
  }
  L00529b95: { // 0x529b95: 89151448a500 MOV dword ptr [0x00a54814],EDX
    m.w32((0x00a54814u), s.dx);
  }
  L00529b9b: { // 0x529b9b: 66894c240a MOV word ptr [ESP + 0xa],CX
    m.w16((f.sp+0x0000000au), (s.cx & 0xffffu));
  }
  L00529ba0: { // 0x529ba0: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00529ba4: { // 0x529ba4: a1e4aaa300 MOV EAX,[0x00a3aae4]
    s.ax = m.r32((0x00a3aae4u));
  }
  L00529ba9: { // 0x529ba9: 89152c48a500 MOV dword ptr [0x00a5482c],EDX
    m.w32((0x00a5482cu), s.dx);
  }
  L00529baf: { // 0x529baf: 66894c2408 MOV word ptr [ESP + 0x8],CX
    m.w16((f.sp+0x00000008u), (s.cx & 0xffffu));
  }
  L00529bb4: { // 0x529bb4: 66894c240a MOV word ptr [ESP + 0xa],CX
    m.w16((f.sp+0x0000000au), (s.cx & 0xffffu));
  }
  L00529bb9: { // 0x529bb9: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00529bbd: { // 0x529bbd: 89154448a500 MOV dword ptr [0x00a54844],EDX
    m.w32((0x00a54844u), s.dx);
  }
  L00529bc3: { // 0x529bc3: 66894c2408 MOV word ptr [ESP + 0x8],CX
    m.w16((f.sp+0x00000008u), (s.cx & 0xffffu));
  }
  L00529bc8: { // 0x529bc8: 66894c240a MOV word ptr [ESP + 0xa],CX
    m.w16((f.sp+0x0000000au), (s.cx & 0xffffu));
  }
  L00529bcd: { // 0x529bcd: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00529bd1: { // 0x529bd1: 89155c48a500 MOV dword ptr [0x00a5485c],EDX
    m.w32((0x00a5485cu), s.dx);
  }
  L00529bd7: { // 0x529bd7: 66894c2408 MOV word ptr [ESP + 0x8],CX
    m.w16((f.sp+0x00000008u), (s.cx & 0xffffu));
  }
  L00529bdc: { // 0x529bdc: 66894c240a MOV word ptr [ESP + 0xa],CX
    m.w16((f.sp+0x0000000au), (s.cx & 0xffffu));
  }
  L00529be1: { // 0x529be1: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00529be5: { // 0x529be5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00529be6: { // 0x529be6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00529be7: { // 0x529be7: a3b847a500 MOV [0x00a547b8],EAX
    m.w32((0x00a547b8u), s.ax);
  }
  L00529bec: { // 0x529bec: a3bc47a500 MOV [0x00a547bc],EAX
    m.w32((0x00a547bcu), s.ax);
  }
  L00529bf1: { // 0x529bf1: a3c047a500 MOV [0x00a547c0],EAX
    m.w32((0x00a547c0u), s.ax);
  }
  L00529bf6: { // 0x529bf6: a3c447a500 MOV [0x00a547c4],EAX
    m.w32((0x00a547c4u), s.ax);
  }
  L00529bfb: { // 0x529bfb: a3c847a500 MOV [0x00a547c8],EAX
    m.w32((0x00a547c8u), s.ax);
  }
  L00529c00: { // 0x529c00: a3d047a500 MOV [0x00a547d0],EAX
    m.w32((0x00a547d0u), s.ax);
  }
  L00529c05: { // 0x529c05: a3d447a500 MOV [0x00a547d4],EAX
    m.w32((0x00a547d4u), s.ax);
  }
  L00529c0a: { // 0x529c0a: a3d847a500 MOV [0x00a547d8],EAX
    m.w32((0x00a547d8u), s.ax);
  }
  L00529c0f: { // 0x529c0f: a3dc47a500 MOV [0x00a547dc],EAX
    m.w32((0x00a547dcu), s.ax);
  }
  L00529c14: { // 0x529c14: a3e047a500 MOV [0x00a547e0],EAX
    m.w32((0x00a547e0u), s.ax);
  }
  L00529c19: { // 0x529c19: a3e847a500 MOV [0x00a547e8],EAX
    m.w32((0x00a547e8u), s.ax);
  }
  L00529c1e: { // 0x529c1e: a3ec47a500 MOV [0x00a547ec],EAX
    m.w32((0x00a547ecu), s.ax);
  }
  L00529c23: { // 0x529c23: a3f047a500 MOV [0x00a547f0],EAX
    m.w32((0x00a547f0u), s.ax);
  }
  L00529c28: { // 0x529c28: a3f447a500 MOV [0x00a547f4],EAX
    m.w32((0x00a547f4u), s.ax);
  }
  L00529c2d: { // 0x529c2d: a3f847a500 MOV [0x00a547f8],EAX
    m.w32((0x00a547f8u), s.ax);
  }
  L00529c32: { // 0x529c32: a30048a500 MOV [0x00a54800],EAX
    m.w32((0x00a54800u), s.ax);
  }
  L00529c37: { // 0x529c37: a30448a500 MOV [0x00a54804],EAX
    m.w32((0x00a54804u), s.ax);
  }
  L00529c3c: { // 0x529c3c: a30848a500 MOV [0x00a54808],EAX
    m.w32((0x00a54808u), s.ax);
  }
  L00529c41: { // 0x529c41: a30c48a500 MOV [0x00a5480c],EAX
    m.w32((0x00a5480cu), s.ax);
  }
  L00529c46: { // 0x529c46: a31048a500 MOV [0x00a54810],EAX
    m.w32((0x00a54810u), s.ax);
  }
  L00529c4b: { // 0x529c4b: a31848a500 MOV [0x00a54818],EAX
    m.w32((0x00a54818u), s.ax);
  }
  L00529c50: { // 0x529c50: a31c48a500 MOV [0x00a5481c],EAX
    m.w32((0x00a5481cu), s.ax);
  }
  L00529c55: { // 0x529c55: a32048a500 MOV [0x00a54820],EAX
    m.w32((0x00a54820u), s.ax);
  }
  L00529c5a: { // 0x529c5a: a32448a500 MOV [0x00a54824],EAX
    m.w32((0x00a54824u), s.ax);
  }
  L00529c5f: { // 0x529c5f: a32848a500 MOV [0x00a54828],EAX
    m.w32((0x00a54828u), s.ax);
  }
  L00529c64: { // 0x529c64: a33048a500 MOV [0x00a54830],EAX
    m.w32((0x00a54830u), s.ax);
  }
  L00529c69: { // 0x529c69: a33448a500 MOV [0x00a54834],EAX
    m.w32((0x00a54834u), s.ax);
  }
  L00529c6e: { // 0x529c6e: a33848a500 MOV [0x00a54838],EAX
    m.w32((0x00a54838u), s.ax);
  }
  L00529c73: { // 0x529c73: a33c48a500 MOV [0x00a5483c],EAX
    m.w32((0x00a5483cu), s.ax);
  }
  L00529c78: { // 0x529c78: a34048a500 MOV [0x00a54840],EAX
    m.w32((0x00a54840u), s.ax);
  }
  L00529c7d: { // 0x529c7d: a34848a500 MOV [0x00a54848],EAX
    m.w32((0x00a54848u), s.ax);
  }
  L00529c82: { // 0x529c82: a34c48a500 MOV [0x00a5484c],EAX
    m.w32((0x00a5484cu), s.ax);
  }
  L00529c87: { // 0x529c87: a35048a500 MOV [0x00a54850],EAX
    m.w32((0x00a54850u), s.ax);
  }
  L00529c8c: { // 0x529c8c: a35448a500 MOV [0x00a54854],EAX
    m.w32((0x00a54854u), s.ax);
  }
  L00529c91: { // 0x529c91: a35848a500 MOV [0x00a54858],EAX
    m.w32((0x00a54858u), s.ax);
  }
  L00529c96: { // 0x529c96: a36048a500 MOV [0x00a54860],EAX
    m.w32((0x00a54860u), s.ax);
  }
  L00529c9b: { // 0x529c9b: a36448a500 MOV [0x00a54864],EAX
    m.w32((0x00a54864u), s.ax);
  }
  L00529ca0: { // 0x529ca0: a36848a500 MOV [0x00a54868],EAX
    m.w32((0x00a54868u), s.ax);
  }
  L00529ca5: { // 0x529ca5: a36c48a500 MOV [0x00a5486c],EAX
    m.w32((0x00a5486cu), s.ax);
  }
  L00529caa: { // 0x529caa: a37048a500 MOV [0x00a54870],EAX
    m.w32((0x00a54870u), s.ax);
  }
  L00529caf: { // 0x529caf: 89157448a500 MOV dword ptr [0x00a54874],EDX
    m.w32((0x00a54874u), s.dx);
  }
  L00529cb5: { // 0x529cb5: a37848a500 MOV [0x00a54878],EAX
    m.w32((0x00a54878u), s.ax);
  }
  L00529cba: { // 0x529cba: a37c48a500 MOV [0x00a5487c],EAX
    m.w32((0x00a5487cu), s.ax);
  }
  L00529cbf: { // 0x529cbf: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00529cc4: { // 0x529cc4: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L00529cc9: { // 0x529cc9: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529ccd: { // 0x529ccd: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00529cd2: { // 0x529cd2: 89158c48a500 MOV dword ptr [0x00a5488c],EDX
    m.w32((0x00a5488cu), s.dx);
  }
  L00529cd8: { // 0x529cd8: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L00529cdd: { // 0x529cdd: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529ce1: { // 0x529ce1: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00529ce6: { // 0x529ce6: 8915a448a500 MOV dword ptr [0x00a548a4],EDX
    m.w32((0x00a548a4u), s.dx);
  }
  L00529cec: { // 0x529cec: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L00529cf1: { // 0x529cf1: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529cf5: { // 0x529cf5: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00529cfa: { // 0x529cfa: 8915bc48a500 MOV dword ptr [0x00a548bc],EDX
    m.w32((0x00a548bcu), s.dx);
  }
  L00529d00: { // 0x529d00: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L00529d05: { // 0x529d05: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529d09: { // 0x529d09: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00529d0e: { // 0x529d0e: 8915d448a500 MOV dword ptr [0x00a548d4],EDX
    m.w32((0x00a548d4u), s.dx);
  }
  L00529d14: { // 0x529d14: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L00529d19: { // 0x529d19: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529d1d: { // 0x529d1d: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00529d22: { // 0x529d22: 8915ec48a500 MOV dword ptr [0x00a548ec],EDX
    m.w32((0x00a548ecu), s.dx);
  }
  L00529d28: { // 0x529d28: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L00529d2d: { // 0x529d2d: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529d31: { // 0x529d31: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00529d36: { // 0x529d36: 89150449a500 MOV dword ptr [0x00a54904],EDX
    m.w32((0x00a54904u), s.dx);
  }
  L00529d3c: { // 0x529d3c: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L00529d41: { // 0x529d41: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529d45: { // 0x529d45: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00529d4a: { // 0x529d4a: 89151c49a500 MOV dword ptr [0x00a5491c],EDX
    m.w32((0x00a5491cu), s.dx);
  }
  L00529d50: { // 0x529d50: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L00529d55: { // 0x529d55: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529d59: { // 0x529d59: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00529d5e: { // 0x529d5e: 89153449a500 MOV dword ptr [0x00a54934],EDX
    m.w32((0x00a54934u), s.dx);
  }
  L00529d64: { // 0x529d64: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L00529d69: { // 0x529d69: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529d6d: { // 0x529d6d: a38048a500 MOV [0x00a54880],EAX
    m.w32((0x00a54880u), s.ax);
  }
  L00529d72: { // 0x529d72: a38448a500 MOV [0x00a54884],EAX
    m.w32((0x00a54884u), s.ax);
  }
  L00529d77: { // 0x529d77: a38848a500 MOV [0x00a54888],EAX
    m.w32((0x00a54888u), s.ax);
  }
  L00529d7c: { // 0x529d7c: a39048a500 MOV [0x00a54890],EAX
    m.w32((0x00a54890u), s.ax);
  }
  L00529d81: { // 0x529d81: a39448a500 MOV [0x00a54894],EAX
    m.w32((0x00a54894u), s.ax);
  }
  L00529d86: { // 0x529d86: a39848a500 MOV [0x00a54898],EAX
    m.w32((0x00a54898u), s.ax);
  }
  L00529d8b: { // 0x529d8b: a39c48a500 MOV [0x00a5489c],EAX
    m.w32((0x00a5489cu), s.ax);
  }
  L00529d90: { // 0x529d90: a3a048a500 MOV [0x00a548a0],EAX
    m.w32((0x00a548a0u), s.ax);
  }
  L00529d95: { // 0x529d95: a3a848a500 MOV [0x00a548a8],EAX
    m.w32((0x00a548a8u), s.ax);
  }
  L00529d9a: { // 0x529d9a: a3ac48a500 MOV [0x00a548ac],EAX
    m.w32((0x00a548acu), s.ax);
  }
  L00529d9f: { // 0x529d9f: a3b048a500 MOV [0x00a548b0],EAX
    m.w32((0x00a548b0u), s.ax);
  }
  L00529da4: { // 0x529da4: a3b448a500 MOV [0x00a548b4],EAX
    m.w32((0x00a548b4u), s.ax);
  }
  L00529da9: { // 0x529da9: a3b848a500 MOV [0x00a548b8],EAX
    m.w32((0x00a548b8u), s.ax);
  }
  L00529dae: { // 0x529dae: a3c048a500 MOV [0x00a548c0],EAX
    m.w32((0x00a548c0u), s.ax);
  }
  L00529db3: { // 0x529db3: a3c448a500 MOV [0x00a548c4],EAX
    m.w32((0x00a548c4u), s.ax);
  }
  L00529db8: { // 0x529db8: a3c848a500 MOV [0x00a548c8],EAX
    m.w32((0x00a548c8u), s.ax);
  }
  L00529dbd: { // 0x529dbd: a3cc48a500 MOV [0x00a548cc],EAX
    m.w32((0x00a548ccu), s.ax);
  }
  L00529dc2: { // 0x529dc2: a3d048a500 MOV [0x00a548d0],EAX
    m.w32((0x00a548d0u), s.ax);
  }
  L00529dc7: { // 0x529dc7: a3d848a500 MOV [0x00a548d8],EAX
    m.w32((0x00a548d8u), s.ax);
  }
  L00529dcc: { // 0x529dcc: a3dc48a500 MOV [0x00a548dc],EAX
    m.w32((0x00a548dcu), s.ax);
  }
  L00529dd1: { // 0x529dd1: a3e048a500 MOV [0x00a548e0],EAX
    m.w32((0x00a548e0u), s.ax);
  }
  L00529dd6: { // 0x529dd6: a3e448a500 MOV [0x00a548e4],EAX
    m.w32((0x00a548e4u), s.ax);
  }
  L00529ddb: { // 0x529ddb: a3e848a500 MOV [0x00a548e8],EAX
    m.w32((0x00a548e8u), s.ax);
  }
  L00529de0: { // 0x529de0: a3f048a500 MOV [0x00a548f0],EAX
    m.w32((0x00a548f0u), s.ax);
  }
  L00529de5: { // 0x529de5: a3f448a500 MOV [0x00a548f4],EAX
    m.w32((0x00a548f4u), s.ax);
  }
  L00529dea: { // 0x529dea: a3f848a500 MOV [0x00a548f8],EAX
    m.w32((0x00a548f8u), s.ax);
  }
  L00529def: { // 0x529def: a3fc48a500 MOV [0x00a548fc],EAX
    m.w32((0x00a548fcu), s.ax);
  }
  L00529df4: { // 0x529df4: a30049a500 MOV [0x00a54900],EAX
    m.w32((0x00a54900u), s.ax);
  }
  L00529df9: { // 0x529df9: a30849a500 MOV [0x00a54908],EAX
    m.w32((0x00a54908u), s.ax);
  }
  L00529dfe: { // 0x529dfe: a30c49a500 MOV [0x00a5490c],EAX
    m.w32((0x00a5490cu), s.ax);
  }
  L00529e03: { // 0x529e03: a31049a500 MOV [0x00a54910],EAX
    m.w32((0x00a54910u), s.ax);
  }
  L00529e08: { // 0x529e08: a31449a500 MOV [0x00a54914],EAX
    m.w32((0x00a54914u), s.ax);
  }
  L00529e0d: { // 0x529e0d: a31849a500 MOV [0x00a54918],EAX
    m.w32((0x00a54918u), s.ax);
  }
  L00529e12: { // 0x529e12: a32049a500 MOV [0x00a54920],EAX
    m.w32((0x00a54920u), s.ax);
  }
  L00529e17: { // 0x529e17: a32449a500 MOV [0x00a54924],EAX
    m.w32((0x00a54924u), s.ax);
  }
  L00529e1c: { // 0x529e1c: a32849a500 MOV [0x00a54928],EAX
    m.w32((0x00a54928u), s.ax);
  }
  L00529e21: { // 0x529e21: a32c49a500 MOV [0x00a5492c],EAX
    m.w32((0x00a5492cu), s.ax);
  }
  L00529e26: { // 0x529e26: a33049a500 MOV [0x00a54930],EAX
    m.w32((0x00a54930u), s.ax);
  }
  L00529e2b: { // 0x529e2b: a33849a500 MOV [0x00a54938],EAX
    m.w32((0x00a54938u), s.ax);
  }
  L00529e30: { // 0x529e30: a33c49a500 MOV [0x00a5493c],EAX
    m.w32((0x00a5493cu), s.ax);
  }
  L00529e35: { // 0x529e35: a34049a500 MOV [0x00a54940],EAX
    m.w32((0x00a54940u), s.ax);
  }
  L00529e3a: { // 0x529e3a: a34449a500 MOV [0x00a54944],EAX
    m.w32((0x00a54944u), s.ax);
  }
  L00529e3f: { // 0x529e3f: a34849a500 MOV [0x00a54948],EAX
    m.w32((0x00a54948u), s.ax);
  }
  L00529e44: { // 0x529e44: 89154c49a500 MOV dword ptr [0x00a5494c],EDX
    m.w32((0x00a5494cu), s.dx);
  }
  L00529e4a: { // 0x529e4a: a35049a500 MOV [0x00a54950],EAX
    m.w32((0x00a54950u), s.ax);
  }
  L00529e4f: { // 0x529e4f: a35449a500 MOV [0x00a54954],EAX
    m.w32((0x00a54954u), s.ax);
  }
  L00529e54: { // 0x529e54: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00529e59: { // 0x529e59: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L00529e5e: { // 0x529e5e: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529e62: { // 0x529e62: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00529e67: { // 0x529e67: 89156449a500 MOV dword ptr [0x00a54964],EDX
    m.w32((0x00a54964u), s.dx);
  }
  L00529e6d: { // 0x529e6d: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L00529e72: { // 0x529e72: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529e76: { // 0x529e76: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00529e7b: { // 0x529e7b: 89157c49a500 MOV dword ptr [0x00a5497c],EDX
    m.w32((0x00a5497cu), s.dx);
  }
  L00529e81: { // 0x529e81: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L00529e86: { // 0x529e86: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529e8a: { // 0x529e8a: 83ceff OR ESI,0xffffffff
    s.si = integer::logical((s.si)|(0xffffffffu),32,flags);
  }
  L00529e8d: { // 0x529e8d: 89159449a500 MOV dword ptr [0x00a54994],EDX
    m.w32((0x00a54994u), s.dx);
  }
  L00529e93: { // 0x529e93: 66895c2410 MOV word ptr [ESP + 0x10],BX
    m.w16((f.sp+0x00000010u), (s.bx & 0xffffu));
  }
  L00529e98: { // 0x529e98: 6689742412 MOV word ptr [ESP + 0x12],SI
    m.w16((f.sp+0x00000012u), (s.si & 0xffffu));
  }
  L00529e9d: { // 0x529e9d: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529ea1: { // 0x529ea1: 89159849a500 MOV dword ptr [0x00a54998],EDX
    m.w32((0x00a54998u), s.dx);
  }
  L00529ea7: { // 0x529ea7: 66895c2410 MOV word ptr [ESP + 0x10],BX
    m.w16((f.sp+0x00000010u), (s.bx & 0xffffu));
  }
  L00529eac: { // 0x529eac: 6689742412 MOV word ptr [ESP + 0x12],SI
    m.w16((f.sp+0x00000012u), (s.si & 0xffffu));
  }
  L00529eb1: { // 0x529eb1: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529eb5: { // 0x529eb5: bffeffffff MOV EDI,0xfffffffe
    s.di = 0xfffffffeu;
  }
  L00529eba: { // 0x529eba: 89159c49a500 MOV dword ptr [0x00a5499c],EDX
    m.w32((0x00a5499cu), s.dx);
  }
  L00529ec0: { // 0x529ec0: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L00529ec5: { // 0x529ec5: 66897c2412 MOV word ptr [ESP + 0x12],DI
    m.w16((f.sp+0x00000012u), (s.di & 0xffffu));
  }
  L00529eca: { // 0x529eca: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529ece: { // 0x529ece: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00529ed3: { // 0x529ed3: 8915a049a500 MOV dword ptr [0x00a549a0],EDX
    m.w32((0x00a549a0u), s.dx);
  }
  L00529ed9: { // 0x529ed9: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L00529ede: { // 0x529ede: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529ee2: { // 0x529ee2: 66895c2410 MOV word ptr [ESP + 0x10],BX
    m.w16((f.sp+0x00000010u), (s.bx & 0xffffu));
  }
  L00529ee7: { // 0x529ee7: 8915ac49a500 MOV dword ptr [0x00a549ac],EDX
    m.w32((0x00a549acu), s.dx);
  }
  L00529eed: { // 0x529eed: 6689742412 MOV word ptr [ESP + 0x12],SI
    m.w16((f.sp+0x00000012u), (s.si & 0xffffu));
  }
  L00529ef2: { // 0x529ef2: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529ef6: { // 0x529ef6: 66895c2410 MOV word ptr [ESP + 0x10],BX
    m.w16((f.sp+0x00000010u), (s.bx & 0xffffu));
  }
  L00529efb: { // 0x529efb: 8915b049a500 MOV dword ptr [0x00a549b0],EDX
    m.w32((0x00a549b0u), s.dx);
  }
  L00529f01: { // 0x529f01: 6689742412 MOV word ptr [ESP + 0x12],SI
    m.w16((f.sp+0x00000012u), (s.si & 0xffffu));
  }
  L00529f06: { // 0x529f06: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529f0a: { // 0x529f0a: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L00529f0f: { // 0x529f0f: 8915b449a500 MOV dword ptr [0x00a549b4],EDX
    m.w32((0x00a549b4u), s.dx);
  }
  L00529f15: { // 0x529f15: 66897c2412 MOV word ptr [ESP + 0x12],DI
    m.w16((f.sp+0x00000012u), (s.di & 0xffffu));
  }
  L00529f1a: { // 0x529f1a: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529f1e: { // 0x529f1e: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00529f23: { // 0x529f23: 8915b849a500 MOV dword ptr [0x00a549b8],EDX
    m.w32((0x00a549b8u), s.dx);
  }
  L00529f29: { // 0x529f29: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L00529f2e: { // 0x529f2e: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00529f32: { // 0x529f32: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L00529f37: { // 0x529f37: 8915c449a500 MOV dword ptr [0x00a549c4],EDX
    m.w32((0x00a549c4u), s.dx);
  }
  L00529f3d: { // 0x529f3d: bafdffffff MOV EDX,0xfffffffd
    s.dx = 0xfffffffdu;
  }
  L00529f42: { // 0x529f42: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L00529f47: { // 0x529f47: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00529f4b: { // 0x529f4b: 892dc849a500 MOV dword ptr [0x00a549c8],EBP
    m.w32((0x00a549c8u), s.bp);
  }
  L00529f51: { // 0x529f51: 66895c2410 MOV word ptr [ESP + 0x10],BX
    m.w16((f.sp+0x00000010u), (s.bx & 0xffffu));
  }
  L00529f56: { // 0x529f56: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L00529f5b: { // 0x529f5b: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00529f5f: { // 0x529f5f: 892dcc49a500 MOV dword ptr [0x00a549cc],EBP
    m.w32((0x00a549ccu), s.bp);
  }
  L00529f65: { // 0x529f65: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L00529f6a: { // 0x529f6a: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L00529f6f: { // 0x529f6f: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00529f73: { // 0x529f73: a35849a500 MOV [0x00a54958],EAX
    m.w32((0x00a54958u), s.ax);
  }
  L00529f78: { // 0x529f78: a35c49a500 MOV [0x00a5495c],EAX
    m.w32((0x00a5495cu), s.ax);
  }
  L00529f7d: { // 0x529f7d: a36049a500 MOV [0x00a54960],EAX
    m.w32((0x00a54960u), s.ax);
  }
  L00529f82: { // 0x529f82: a36849a500 MOV [0x00a54968],EAX
    m.w32((0x00a54968u), s.ax);
  }
  L00529f87: { // 0x529f87: a36c49a500 MOV [0x00a5496c],EAX
    m.w32((0x00a5496cu), s.ax);
  }
  L00529f8c: { // 0x529f8c: a37049a500 MOV [0x00a54970],EAX
    m.w32((0x00a54970u), s.ax);
  }
  L00529f91: { // 0x529f91: a37449a500 MOV [0x00a54974],EAX
    m.w32((0x00a54974u), s.ax);
  }
  L00529f96: { // 0x529f96: a37849a500 MOV [0x00a54978],EAX
    m.w32((0x00a54978u), s.ax);
  }
  L00529f9b: { // 0x529f9b: a38049a500 MOV [0x00a54980],EAX
    m.w32((0x00a54980u), s.ax);
  }
  L00529fa0: { // 0x529fa0: a38449a500 MOV [0x00a54984],EAX
    m.w32((0x00a54984u), s.ax);
  }
  L00529fa5: { // 0x529fa5: a38849a500 MOV [0x00a54988],EAX
    m.w32((0x00a54988u), s.ax);
  }
  L00529faa: { // 0x529faa: a38c49a500 MOV [0x00a5498c],EAX
    m.w32((0x00a5498cu), s.ax);
  }
  L00529faf: { // 0x529faf: a39049a500 MOV [0x00a54990],EAX
    m.w32((0x00a54990u), s.ax);
  }
  L00529fb4: { // 0x529fb4: a3a449a500 MOV [0x00a549a4],EAX
    m.w32((0x00a549a4u), s.ax);
  }
  L00529fb9: { // 0x529fb9: a3a849a500 MOV [0x00a549a8],EAX
    m.w32((0x00a549a8u), s.ax);
  }
  L00529fbe: { // 0x529fbe: a3bc49a500 MOV [0x00a549bc],EAX
    m.w32((0x00a549bcu), s.ax);
  }
  L00529fc3: { // 0x529fc3: a3c049a500 MOV [0x00a549c0],EAX
    m.w32((0x00a549c0u), s.ax);
  }
  L00529fc8: { // 0x529fc8: a3d049a500 MOV [0x00a549d0],EAX
    m.w32((0x00a549d0u), s.ax);
  }
  L00529fcd: { // 0x529fcd: a3d449a500 MOV [0x00a549d4],EAX
    m.w32((0x00a549d4u), s.ax);
  }
  L00529fd2: { // 0x529fd2: a3d849a500 MOV [0x00a549d8],EAX
    m.w32((0x00a549d8u), s.ax);
  }
  L00529fd7: { // 0x529fd7: 892ddc49a500 MOV dword ptr [0x00a549dc],EBP
    m.w32((0x00a549dcu), s.bp);
  }
  L00529fdd: { // 0x529fdd: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L00529fe2: { // 0x529fe2: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L00529fe7: { // 0x529fe7: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00529feb: { // 0x529feb: 66895c2410 MOV word ptr [ESP + 0x10],BX
    m.w16((f.sp+0x00000010u), (s.bx & 0xffffu));
  }
  L00529ff0: { // 0x529ff0: 892de049a500 MOV dword ptr [0x00a549e0],EBP
    m.w32((0x00a549e0u), s.bp);
  }
  L00529ff6: { // 0x529ff6: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L00529ffb: { // 0x529ffb: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00529fff: { // 0x529fff: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a004: { // 0x52a004: 892de449a500 MOV dword ptr [0x00a549e4],EBP
    m.w32((0x00a549e4u), s.bp);
  }
  L0052a00a: { // 0x52a00a: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a00f: { // 0x52a00f: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a013: { // 0x52a013: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L0052a018: { // 0x52a018: 892df449a500 MOV dword ptr [0x00a549f4],EBP
    m.w32((0x00a549f4u), s.bp);
  }
  L0052a01e: { // 0x52a01e: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a023: { // 0x52a023: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a027: { // 0x52a027: 66895c2410 MOV word ptr [ESP + 0x10],BX
    m.w16((f.sp+0x00000010u), (s.bx & 0xffffu));
  }
  L0052a02c: { // 0x52a02c: 892df849a500 MOV dword ptr [0x00a549f8],EBP
    m.w32((0x00a549f8u), s.bp);
  }
  L0052a032: { // 0x52a032: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a037: { // 0x52a037: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a03b: { // 0x52a03b: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a040: { // 0x52a040: 892dfc49a500 MOV dword ptr [0x00a549fc],EBP
    m.w32((0x00a549fcu), s.bp);
  }
  L0052a046: { // 0x52a046: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a04b: { // 0x52a04b: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a04f: { // 0x52a04f: 66895c2410 MOV word ptr [ESP + 0x10],BX
    m.w16((f.sp+0x00000010u), (s.bx & 0xffffu));
  }
  L0052a054: { // 0x52a054: 892d0c4aa500 MOV dword ptr [0x00a54a0c],EBP
    m.w32((0x00a54a0cu), s.bp);
  }
  L0052a05a: { // 0x52a05a: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a05f: { // 0x52a05f: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a063: { // 0x52a063: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a068: { // 0x52a068: 892d104aa500 MOV dword ptr [0x00a54a10],EBP
    m.w32((0x00a54a10u), s.bp);
  }
  L0052a06e: { // 0x52a06e: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a073: { // 0x52a073: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a077: { // 0x52a077: 66895c2410 MOV word ptr [ESP + 0x10],BX
    m.w16((f.sp+0x00000010u), (s.bx & 0xffffu));
  }
  L0052a07c: { // 0x52a07c: 892d244aa500 MOV dword ptr [0x00a54a24],EBP
    m.w32((0x00a54a24u), s.bp);
  }
  L0052a082: { // 0x52a082: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a087: { // 0x52a087: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a08b: { // 0x52a08b: 66c74424100100 MOV word ptr [ESP + 0x10],0x1
    m.w16((f.sp+0x00000010u), 0x00000001u);
  }
  L0052a092: { // 0x52a092: 892d284aa500 MOV dword ptr [0x00a54a28],EBP
    m.w32((0x00a54a28u), s.bp);
  }
  L0052a098: { // 0x52a098: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a09d: { // 0x52a09d: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a0a1: { // 0x52a0a1: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L0052a0a6: { // 0x52a0a6: 892d2c4aa500 MOV dword ptr [0x00a54a2c],EBP
    m.w32((0x00a54a2cu), s.bp);
  }
  L0052a0ac: { // 0x52a0ac: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a0b1: { // 0x52a0b1: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a0b5: { // 0x52a0b5: 66897c2410 MOV word ptr [ESP + 0x10],DI
    m.w16((f.sp+0x00000010u), (s.di & 0xffffu));
  }
  L0052a0ba: { // 0x52a0ba: 892d304aa500 MOV dword ptr [0x00a54a30],EBP
    m.w32((0x00a54a30u), s.bp);
  }
  L0052a0c0: { // 0x52a0c0: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a0c5: { // 0x52a0c5: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a0c9: { // 0x52a0c9: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a0ce: { // 0x52a0ce: 892d344aa500 MOV dword ptr [0x00a54a34],EBP
    m.w32((0x00a54a34u), s.bp);
  }
  L0052a0d4: { // 0x52a0d4: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a0d9: { // 0x52a0d9: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a0dd: { // 0x52a0dd: 66895c2410 MOV word ptr [ESP + 0x10],BX
    m.w16((f.sp+0x00000010u), (s.bx & 0xffffu));
  }
  L0052a0e2: { // 0x52a0e2: 892d3c4aa500 MOV dword ptr [0x00a54a3c],EBP
    m.w32((0x00a54a3cu), s.bp);
  }
  L0052a0e8: { // 0x52a0e8: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a0ed: { // 0x52a0ed: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a0f1: { // 0x52a0f1: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L0052a0f6: { // 0x52a0f6: 892d404aa500 MOV dword ptr [0x00a54a40],EBP
    m.w32((0x00a54a40u), s.bp);
  }
  L0052a0fc: { // 0x52a0fc: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a101: { // 0x52a101: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a105: { // 0x52a105: 66897c2410 MOV word ptr [ESP + 0x10],DI
    m.w16((f.sp+0x00000010u), (s.di & 0xffffu));
  }
  L0052a10a: { // 0x52a10a: 892d444aa500 MOV dword ptr [0x00a54a44],EBP
    m.w32((0x00a54a44u), s.bp);
  }
  L0052a110: { // 0x52a110: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a115: { // 0x52a115: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a119: { // 0x52a119: 6689542410 MOV word ptr [ESP + 0x10],DX
    m.w16((f.sp+0x00000010u), (s.dx & 0xffffu));
  }
  L0052a11e: { // 0x52a11e: 892d484aa500 MOV dword ptr [0x00a54a48],EBP
    m.w32((0x00a54a48u), s.bp);
  }
  L0052a124: { // 0x52a124: 66897c2412 MOV word ptr [ESP + 0x12],DI
    m.w16((f.sp+0x00000012u), (s.di & 0xffffu));
  }
  L0052a129: { // 0x52a129: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a12d: { // 0x52a12d: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a132: { // 0x52a132: 892d4c4aa500 MOV dword ptr [0x00a54a4c],EBP
    m.w32((0x00a54a4cu), s.bp);
  }
  L0052a138: { // 0x52a138: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a13d: { // 0x52a13d: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a141: { // 0x52a141: a3e849a500 MOV [0x00a549e8],EAX
    m.w32((0x00a549e8u), s.ax);
  }
  L0052a146: { // 0x52a146: a3ec49a500 MOV [0x00a549ec],EAX
    m.w32((0x00a549ecu), s.ax);
  }
  L0052a14b: { // 0x52a14b: a3f049a500 MOV [0x00a549f0],EAX
    m.w32((0x00a549f0u), s.ax);
  }
  L0052a150: { // 0x52a150: a3004aa500 MOV [0x00a54a00],EAX
    m.w32((0x00a54a00u), s.ax);
  }
  L0052a155: { // 0x52a155: a3044aa500 MOV [0x00a54a04],EAX
    m.w32((0x00a54a04u), s.ax);
  }
  L0052a15a: { // 0x52a15a: a3084aa500 MOV [0x00a54a08],EAX
    m.w32((0x00a54a08u), s.ax);
  }
  L0052a15f: { // 0x52a15f: a3144aa500 MOV [0x00a54a14],EAX
    m.w32((0x00a54a14u), s.ax);
  }
  L0052a164: { // 0x52a164: a3184aa500 MOV [0x00a54a18],EAX
    m.w32((0x00a54a18u), s.ax);
  }
  L0052a169: { // 0x52a169: a31c4aa500 MOV [0x00a54a1c],EAX
    m.w32((0x00a54a1cu), s.ax);
  }
  L0052a16e: { // 0x52a16e: a3204aa500 MOV [0x00a54a20],EAX
    m.w32((0x00a54a20u), s.ax);
  }
  L0052a173: { // 0x52a173: a3384aa500 MOV [0x00a54a38],EAX
    m.w32((0x00a54a38u), s.ax);
  }
  L0052a178: { // 0x52a178: a3504aa500 MOV [0x00a54a50],EAX
    m.w32((0x00a54a50u), s.ax);
  }
  L0052a17d: { // 0x52a17d: 892d544aa500 MOV dword ptr [0x00a54a54],EBP
    m.w32((0x00a54a54u), s.bp);
  }
  L0052a183: { // 0x52a183: 66895c2410 MOV word ptr [ESP + 0x10],BX
    m.w16((f.sp+0x00000010u), (s.bx & 0xffffu));
  }
  L0052a188: { // 0x52a188: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a18d: { // 0x52a18d: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a191: { // 0x52a191: 892d584aa500 MOV dword ptr [0x00a54a58],EBP
    m.w32((0x00a54a58u), s.bp);
  }
  L0052a197: { // 0x52a197: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L0052a19c: { // 0x52a19c: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a1a1: { // 0x52a1a1: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a1a5: { // 0x52a1a5: 892d5c4aa500 MOV dword ptr [0x00a54a5c],EBP
    m.w32((0x00a54a5cu), s.bp);
  }
  L0052a1ab: { // 0x52a1ab: 66897c2410 MOV word ptr [ESP + 0x10],DI
    m.w16((f.sp+0x00000010u), (s.di & 0xffffu));
  }
  L0052a1b0: { // 0x52a1b0: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a1b5: { // 0x52a1b5: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a1b9: { // 0x52a1b9: 892d604aa500 MOV dword ptr [0x00a54a60],EBP
    m.w32((0x00a54a60u), s.bp);
  }
  L0052a1bf: { // 0x52a1bf: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a1c4: { // 0x52a1c4: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a1c9: { // 0x52a1c9: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a1cd: { // 0x52a1cd: 892d6c4aa500 MOV dword ptr [0x00a54a6c],EBP
    m.w32((0x00a54a6cu), s.bp);
  }
  L0052a1d3: { // 0x52a1d3: 66895c2410 MOV word ptr [ESP + 0x10],BX
    m.w16((f.sp+0x00000010u), (s.bx & 0xffffu));
  }
  L0052a1d8: { // 0x52a1d8: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a1dd: { // 0x52a1dd: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0052a1e1: { // 0x52a1e1: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L0052a1e6: { // 0x52a1e6: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a1eb: { // 0x52a1eb: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0052a1ef: { // 0x52a1ef: 66897c2410 MOV word ptr [ESP + 0x10],DI
    m.w16((f.sp+0x00000010u), (s.di & 0xffffu));
  }
  L0052a1f4: { // 0x52a1f4: 8935744aa500 MOV dword ptr [0x00a54a74],ESI
    m.w32((0x00a54a74u), s.si);
  }
  L0052a1fa: { // 0x52a1fa: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a1ff: { // 0x52a1ff: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0052a203: { // 0x52a203: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a208: { // 0x52a208: 8935784aa500 MOV dword ptr [0x00a54a78],ESI
    m.w32((0x00a54a78u), s.si);
  }
  L0052a20e: { // 0x52a20e: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a213: { // 0x52a213: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0052a217: { // 0x52a217: 66897c2410 MOV word ptr [ESP + 0x10],DI
    m.w16((f.sp+0x00000010u), (s.di & 0xffffu));
  }
  L0052a21c: { // 0x52a21c: 8935844aa500 MOV dword ptr [0x00a54a84],ESI
    m.w32((0x00a54a84u), s.si);
  }
  L0052a222: { // 0x52a222: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a227: { // 0x52a227: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0052a22b: { // 0x52a22b: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a230: { // 0x52a230: 8935884aa500 MOV dword ptr [0x00a54a88],ESI
    m.w32((0x00a54a88u), s.si);
  }
  L0052a236: { // 0x52a236: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a23b: { // 0x52a23b: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0052a23f: { // 0x52a23f: 66897c2410 MOV word ptr [ESP + 0x10],DI
    m.w16((f.sp+0x00000010u), (s.di & 0xffffu));
  }
  L0052a244: { // 0x52a244: 89359c4aa500 MOV dword ptr [0x00a54a9c],ESI
    m.w32((0x00a54a9cu), s.si);
  }
  L0052a24a: { // 0x52a24a: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a24f: { // 0x52a24f: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0052a253: { // 0x52a253: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a258: { // 0x52a258: 8935a04aa500 MOV dword ptr [0x00a54aa0],ESI
    m.w32((0x00a54aa0u), s.si);
  }
  L0052a25e: { // 0x52a25e: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a263: { // 0x52a263: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0052a267: { // 0x52a267: 66895c2410 MOV word ptr [ESP + 0x10],BX
    m.w16((f.sp+0x00000010u), (s.bx & 0xffffu));
  }
  L0052a26c: { // 0x52a26c: 6689542412 MOV word ptr [ESP + 0x12],DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L0052a271: { // 0x52a271: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0052a275: { // 0x52a275: 8915b84aa500 MOV dword ptr [0x00a54ab8],EDX
    m.w32((0x00a54ab8u), s.dx);
  }
  L0052a27b: { // 0x52a27b: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a280: { // 0x52a280: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a285: { // 0x52a285: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0052a289: { // 0x52a289: 8915cc4aa500 MOV dword ptr [0x00a54acc],EDX
    m.w32((0x00a54accu), s.dx);
  }
  L0052a28f: { // 0x52a28f: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a294: { // 0x52a294: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a299: { // 0x52a299: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0052a29d: { // 0x52a29d: a3644aa500 MOV [0x00a54a64],EAX
    m.w32((0x00a54a64u), s.ax);
  }
  L0052a2a2: { // 0x52a2a2: a3684aa500 MOV [0x00a54a68],EAX
    m.w32((0x00a54a68u), s.ax);
  }
  L0052a2a7: { // 0x52a2a7: 892d704aa500 MOV dword ptr [0x00a54a70],EBP
    m.w32((0x00a54a70u), s.bp);
  }
  L0052a2ad: { // 0x52a2ad: a37c4aa500 MOV [0x00a54a7c],EAX
    m.w32((0x00a54a7cu), s.ax);
  }
  L0052a2b2: { // 0x52a2b2: a3804aa500 MOV [0x00a54a80],EAX
    m.w32((0x00a54a80u), s.ax);
  }
  L0052a2b7: { // 0x52a2b7: a38c4aa500 MOV [0x00a54a8c],EAX
    m.w32((0x00a54a8cu), s.ax);
  }
  L0052a2bc: { // 0x52a2bc: a3904aa500 MOV [0x00a54a90],EAX
    m.w32((0x00a54a90u), s.ax);
  }
  L0052a2c1: { // 0x52a2c1: a3944aa500 MOV [0x00a54a94],EAX
    m.w32((0x00a54a94u), s.ax);
  }
  L0052a2c6: { // 0x52a2c6: a3984aa500 MOV [0x00a54a98],EAX
    m.w32((0x00a54a98u), s.ax);
  }
  L0052a2cb: { // 0x52a2cb: a3a44aa500 MOV [0x00a54aa4],EAX
    m.w32((0x00a54aa4u), s.ax);
  }
  L0052a2d0: { // 0x52a2d0: a3a84aa500 MOV [0x00a54aa8],EAX
    m.w32((0x00a54aa8u), s.ax);
  }
  L0052a2d5: { // 0x52a2d5: a3ac4aa500 MOV [0x00a54aac],EAX
    m.w32((0x00a54aacu), s.ax);
  }
  L0052a2da: { // 0x52a2da: a3b04aa500 MOV [0x00a54ab0],EAX
    m.w32((0x00a54ab0u), s.ax);
  }
  L0052a2df: { // 0x52a2df: 8935b44aa500 MOV dword ptr [0x00a54ab4],ESI
    m.w32((0x00a54ab4u), s.si);
  }
  L0052a2e5: { // 0x52a2e5: a3bc4aa500 MOV [0x00a54abc],EAX
    m.w32((0x00a54abcu), s.ax);
  }
  L0052a2ea: { // 0x52a2ea: a3c04aa500 MOV [0x00a54ac0],EAX
    m.w32((0x00a54ac0u), s.ax);
  }
  L0052a2ef: { // 0x52a2ef: a3c44aa500 MOV [0x00a54ac4],EAX
    m.w32((0x00a54ac4u), s.ax);
  }
  L0052a2f4: { // 0x52a2f4: a3c84aa500 MOV [0x00a54ac8],EAX
    m.w32((0x00a54ac8u), s.ax);
  }
  L0052a2f9: { // 0x52a2f9: a3d04aa500 MOV [0x00a54ad0],EAX
    m.w32((0x00a54ad0u), s.ax);
  }
  L0052a2fe: { // 0x52a2fe: a3d44aa500 MOV [0x00a54ad4],EAX
    m.w32((0x00a54ad4u), s.ax);
  }
  L0052a303: { // 0x52a303: a3d84aa500 MOV [0x00a54ad8],EAX
    m.w32((0x00a54ad8u), s.ax);
  }
  L0052a308: { // 0x52a308: a3dc4aa500 MOV [0x00a54adc],EAX
    m.w32((0x00a54adcu), s.ax);
  }
  L0052a30d: { // 0x52a30d: a3e04aa500 MOV [0x00a54ae0],EAX
    m.w32((0x00a54ae0u), s.ax);
  }
  L0052a312: { // 0x52a312: 8915e44aa500 MOV dword ptr [0x00a54ae4],EDX
    m.w32((0x00a54ae4u), s.dx);
  }
  L0052a318: { // 0x52a318: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a31d: { // 0x52a31d: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a322: { // 0x52a322: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0052a326: { // 0x52a326: 8915fc4aa500 MOV dword ptr [0x00a54afc],EDX
    m.w32((0x00a54afcu), s.dx);
  }
  L0052a32c: { // 0x52a32c: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a331: { // 0x52a331: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a336: { // 0x52a336: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0052a33a: { // 0x52a33a: 8915144ba500 MOV dword ptr [0x00a54b14],EDX
    m.w32((0x00a54b14u), s.dx);
  }
  L0052a340: { // 0x52a340: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a345: { // 0x52a345: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a34a: { // 0x52a34a: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0052a34e: { // 0x52a34e: 89152c4ba500 MOV dword ptr [0x00a54b2c],EDX
    m.w32((0x00a54b2cu), s.dx);
  }
  L0052a354: { // 0x52a354: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a359: { // 0x52a359: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a35e: { // 0x52a35e: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0052a362: { // 0x52a362: 8915444ba500 MOV dword ptr [0x00a54b44],EDX
    m.w32((0x00a54b44u), s.dx);
  }
  L0052a368: { // 0x52a368: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a36d: { // 0x52a36d: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a372: { // 0x52a372: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0052a376: { // 0x52a376: a3e84aa500 MOV [0x00a54ae8],EAX
    m.w32((0x00a54ae8u), s.ax);
  }
  L0052a37b: { // 0x52a37b: a3ec4aa500 MOV [0x00a54aec],EAX
    m.w32((0x00a54aecu), s.ax);
  }
  L0052a380: { // 0x52a380: a3f04aa500 MOV [0x00a54af0],EAX
    m.w32((0x00a54af0u), s.ax);
  }
  L0052a385: { // 0x52a385: a3f44aa500 MOV [0x00a54af4],EAX
    m.w32((0x00a54af4u), s.ax);
  }
  L0052a38a: { // 0x52a38a: a3f84aa500 MOV [0x00a54af8],EAX
    m.w32((0x00a54af8u), s.ax);
  }
  L0052a38f: { // 0x52a38f: a3004ba500 MOV [0x00a54b00],EAX
    m.w32((0x00a54b00u), s.ax);
  }
  L0052a394: { // 0x52a394: a3044ba500 MOV [0x00a54b04],EAX
    m.w32((0x00a54b04u), s.ax);
  }
  L0052a399: { // 0x52a399: a3084ba500 MOV [0x00a54b08],EAX
    m.w32((0x00a54b08u), s.ax);
  }
  L0052a39e: { // 0x52a39e: a30c4ba500 MOV [0x00a54b0c],EAX
    m.w32((0x00a54b0cu), s.ax);
  }
  L0052a3a3: { // 0x52a3a3: a3104ba500 MOV [0x00a54b10],EAX
    m.w32((0x00a54b10u), s.ax);
  }
  L0052a3a8: { // 0x52a3a8: a3184ba500 MOV [0x00a54b18],EAX
    m.w32((0x00a54b18u), s.ax);
  }
  L0052a3ad: { // 0x52a3ad: a31c4ba500 MOV [0x00a54b1c],EAX
    m.w32((0x00a54b1cu), s.ax);
  }
  L0052a3b2: { // 0x52a3b2: a3204ba500 MOV [0x00a54b20],EAX
    m.w32((0x00a54b20u), s.ax);
  }
  L0052a3b7: { // 0x52a3b7: a3244ba500 MOV [0x00a54b24],EAX
    m.w32((0x00a54b24u), s.ax);
  }
  L0052a3bc: { // 0x52a3bc: a3284ba500 MOV [0x00a54b28],EAX
    m.w32((0x00a54b28u), s.ax);
  }
  L0052a3c1: { // 0x52a3c1: a3304ba500 MOV [0x00a54b30],EAX
    m.w32((0x00a54b30u), s.ax);
  }
  L0052a3c6: { // 0x52a3c6: a3344ba500 MOV [0x00a54b34],EAX
    m.w32((0x00a54b34u), s.ax);
  }
  L0052a3cb: { // 0x52a3cb: a3384ba500 MOV [0x00a54b38],EAX
    m.w32((0x00a54b38u), s.ax);
  }
  L0052a3d0: { // 0x52a3d0: a33c4ba500 MOV [0x00a54b3c],EAX
    m.w32((0x00a54b3cu), s.ax);
  }
  L0052a3d5: { // 0x52a3d5: a3404ba500 MOV [0x00a54b40],EAX
    m.w32((0x00a54b40u), s.ax);
  }
  L0052a3da: { // 0x52a3da: a3484ba500 MOV [0x00a54b48],EAX
    m.w32((0x00a54b48u), s.ax);
  }
  L0052a3df: { // 0x52a3df: a34c4ba500 MOV [0x00a54b4c],EAX
    m.w32((0x00a54b4cu), s.ax);
  }
  L0052a3e4: { // 0x52a3e4: a3504ba500 MOV [0x00a54b50],EAX
    m.w32((0x00a54b50u), s.ax);
  }
  L0052a3e9: { // 0x52a3e9: a3544ba500 MOV [0x00a54b54],EAX
    m.w32((0x00a54b54u), s.ax);
  }
  L0052a3ee: { // 0x52a3ee: a3584ba500 MOV [0x00a54b58],EAX
    m.w32((0x00a54b58u), s.ax);
  }
  L0052a3f3: { // 0x52a3f3: a3604ba500 MOV [0x00a54b60],EAX
    m.w32((0x00a54b60u), s.ax);
  }
  L0052a3f8: { // 0x52a3f8: a3644ba500 MOV [0x00a54b64],EAX
    m.w32((0x00a54b64u), s.ax);
  }
  L0052a3fd: { // 0x52a3fd: a3684ba500 MOV [0x00a54b68],EAX
    m.w32((0x00a54b68u), s.ax);
  }
  L0052a402: { // 0x52a402: a36c4ba500 MOV [0x00a54b6c],EAX
    m.w32((0x00a54b6cu), s.ax);
  }
  L0052a407: { // 0x52a407: a3704ba500 MOV [0x00a54b70],EAX
    m.w32((0x00a54b70u), s.ax);
  }
  L0052a40c: { // 0x52a40c: 66894c2410 MOV word ptr [ESP + 0x10],CX
    m.w16((f.sp+0x00000010u), (s.cx & 0xffffu));
  }
  L0052a411: { // 0x52a411: 66894c2412 MOV word ptr [ESP + 0x12],CX
    m.w16((f.sp+0x00000012u), (s.cx & 0xffffu));
  }
  L0052a416: { // 0x52a416: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0052a41a: { // 0x52a41a: 6880a45200 PUSH 0x52a480
    f.push(m,0x0052a480u);
  }
  L0052a41f: { // 0x52a41f: 89155c4ba500 MOV dword ptr [0x00a54b5c],EDX
    m.w32((0x00a54b5cu), s.dx);
  }
  L0052a425: { // 0x52a425: a3744ba500 MOV [0x00a54b74],EAX
    m.w32((0x00a54b74u), s.ax);
  }
  L0052a42a: { // 0x52a42a: e89b3e2400 CALL 0x0076e2ca
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076e2cau,5415983u); flags=s.arithmetic_flags;
  }
  L0052a42f: { // 0x52a42f: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0052a433: { // 0x52a433: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0052a436: { // 0x52a436: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0052a437: { // 0x52a437: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0052a438: { // 0x52a438: 8b9164020000 MOV EDX,dword ptr [ECX + 0x264]
    s.dx = m.r32((s.cx+0x00000264u));
  }
  L0052a43e: { // 0x52a43e: b9b4aaa300 MOV ECX,0xa3aab4
    s.cx = 0x00a3aab4u;
  }
  L0052a443: { // 0x52a443: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L0052a445: { // 0x52a445: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0052a447: { // 0x52a447: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L0052a449: { // 0x52a449: 7805 JS 0x0052a450
    if(integer::condition("JS",flags)) goto L0052a450;
  }
  L0052a44b: { // 0x52a44b: 83f828 CMP EAX,0x28
    (void)integer::sub(s.ax,0x00000028u,32,flags);
  }
  L0052a44e: { // 0x52a44e: 7c13 JL 0x0052a463
    if(integer::condition("JL",flags)) goto L0052a463;
  }
  L0052a450: { // 0x52a450: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L0052a453: { // 0x52a453: 81f9c8aaa300 CMP ECX,0xa3aac8
    (void)integer::sub(s.cx,0x00a3aac8u,32,flags);
  }
  L0052a459: { // 0x52a459: 7ce8 JL 0x0052a443
    if(integer::condition("JL",flags)) goto L0052a443;
  }
  L0052a45b: { // 0x52a45b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0052a45c: { // 0x52a45c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0052a45e: { // 0x52a45e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0052a45f: { // 0x52a45f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0052a462: { // 0x52a462: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0052a463: { // 0x52a463: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L0052a466: { // 0x52a466: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0052a467: { // 0x52a467: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0052a468: { // 0x52a468: 8d04cdb847a500 LEA EAX,[ECX*0x8 + 0xa547b8]
    s.ax = ((s.cx * 0x00000008u)+0x00a547b8u);
  }
  L0052a46f: { // 0x52a46f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0052a472: { // 0x52a472: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
