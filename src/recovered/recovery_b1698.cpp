// B1698 proposal: mechanically assembled qualified private fragments.
#include "recovered/recovery_b1698.hpp"
#include "recovered/numeric_b88.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include <stdexcept>
#include <type_traits>
#include <cstdint>

// BEGIN original fragment: root_source_v2/source.cpp
namespace ra2::recovered::b1698 {
namespace ix=direct_b33::integer;
void execute_selected(Context&context,Memory&m,State&s,Frame&f){
helpers::require_selected_basis(context,m,s,f);
L6c5a80: // SUB ESP,0x80
f.sp = ix::sub(f.sp,0x80u,32,s.arithmetic_flags);
L6c5a86: // PUSH EBX
f.push(m,s.bx);
L6c5a87: // PUSH ESI
f.push(m,s.si);
L6c5a88: // LEA EAX,[ESP + 0x10]
s.ax = f.sp + 0x10;
L6c5a8c: // PUSH EDI
f.push(m,s.di);
L6c5a8d: // LEA ECX,[ESP + 0x90]
s.cx = f.sp + 0x90;
L6c5a94: // PUSH EAX
f.push(m,s.ax);
L6c5a95: // PUSH ECX
f.push(m,s.cx);
L6c5a96: // MOV ECX,dword ptr [0x00821cac]
s.cx = m.r32(0x00821cac);
L6c5a9c: // CALL 0x00698010
helpers::project_00698010(context,m,s,f,0x6c5aa1u);
L6c5aa1: // MOV ECX,dword ptr [0x00821cac]
s.cx = m.r32(0x00821cac);
L6c5aa7: // LEA EDX,[ESP + 0xc]
s.dx = f.sp + 0xc;
L6c5aab: // LEA EAX,[ESP + 0x9c]
s.ax = f.sp + 0x9c;
L6c5ab2: // PUSH EDX
f.push(m,s.dx);
L6c5ab3: // PUSH EAX
f.push(m,s.ax);
L6c5ab4: // CALL 0x00698010
helpers::project_00698010(context,m,s,f,0x6c5ab9u);
L6c5ab9: // MOV EAX,dword ptr [ESP + 0x18]
s.ax = m.r32(f.sp + 0x18);
L6c5abd: // MOV EDX,dword ptr [0x00821974]
s.dx = m.r32(0x00821974);
L6c5ac3: // MOV ECX,dword ptr [ESP + 0x10]
s.cx = m.r32(f.sp + 0x10);
L6c5ac7: // MOV BL,byte ptr [ESP + 0xb0]
s.bx = (s.bx&0xffffff00u)|(m.r8(f.sp + 0xb0)&255u);
L6c5ace: // MOV ESI,dword ptr [ESP + 0x14]
s.si = m.r32(f.sp + 0x14);
L6c5ad2: // ADD EAX,EDX
s.ax = ix::add(s.ax,s.dx,32,s.arithmetic_flags);
L6c5ad4: // MOV dword ptr [ESP + 0x18],EAX
m.w32(f.sp + 0x18,s.ax);
L6c5ad8: // ADD ECX,EDX
s.cx = ix::add(s.cx,s.dx,32,s.arithmetic_flags);
L6c5ada: // MOV dword ptr [ESP + 0x28],EAX
m.w32(f.sp + 0x28,s.ax);
L6c5ade: // INC EAX
s.ax = ix::increment(s.ax,32,s.arithmetic_flags);
L6c5adf: // MOV dword ptr [ESP + 0x10],ECX
m.w32(f.sp + 0x10,s.cx);
L6c5ae3: // MOV dword ptr [ESP + 0x28],EAX
m.w32(f.sp + 0x28,s.ax);
L6c5ae7: // MOV EAX,dword ptr [ESP + 0xc]
s.ax = m.r32(f.sp + 0xc);
L6c5aeb: // MOV dword ptr [ESP + 0x20],ECX
m.w32(f.sp + 0x20,s.cx);
L6c5aef: // INC ECX
s.cx = ix::increment(s.cx,32,s.arithmetic_flags);
L6c5af0: // MOV dword ptr [ESP + 0x24],ESI
m.w32(f.sp + 0x24,s.si);
L6c5af4: // TEST BL,BL
(void)ix::logical((s.bx&255u)&(s.bx&255u),8,s.arithmetic_flags);
L6c5af6: // MOV dword ptr [ESP + 0x1c],EAX
m.w32(f.sp + 0x1c,s.ax);
L6c5afa: // MOV dword ptr [ESP + 0x20],ECX
m.w32(f.sp + 0x20,s.cx);
L6c5afe: // MOV EDI,0x1
s.di = 0x1u;
L6c5b03: // JZ 0x006c5c77
if(ix::condition("JZ",s.arithmetic_flags)) goto L6c5c77; throw std::runtime_error("2c5a80 selected-path branch escaped");
L6c5c77: // MOV ECX,dword ptr [0x00821970]
s.cx = m.r32(0x00821970);
L6c5c7d: // MOV EAX,[0x0082197c]
s.ax = m.r32(0x0082197c);
L6c5c82: // MOV dword ptr [ESP + 0x40],EDX
m.w32(f.sp + 0x40,s.dx);
L6c5c86: // MOV EDX,dword ptr [0x00821978]
s.dx = m.r32(0x00821978);
L6c5c8c: // TEST BL,BL
(void)ix::logical((s.bx&255u)&(s.bx&255u),8,s.arithmetic_flags);
L6c5c8e: // MOV dword ptr [ESP + 0x3c],ECX
m.w32(f.sp + 0x3c,s.cx);
L6c5c92: // MOV dword ptr [ESP + 0x44],EDX
m.w32(f.sp + 0x44,s.dx);
L6c5c96: // MOV dword ptr [ESP + 0x48],EAX
m.w32(f.sp + 0x48,s.ax);
L6c5c9a: // JZ 0x006c5ce9
if(ix::condition("JZ",s.arithmetic_flags)) goto L6c5ce9; throw std::runtime_error("2c5a80 selected-path branch escaped");
L6c5ce9: // MOV ESI,dword ptr [ESP + 0xa9]
s.si = m.r32(f.sp + 0xa9);
L6c5cf0: // MOV CL,byte ptr [0x0083b2fc]
s.cx = (s.cx&0xffffff00u)|(m.r8(0x0083b2fc)&255u);
L6c5cf6: // MOV EDX,dword ptr [ESP + 0xaa]
s.dx = m.r32(f.sp + 0xaa);
L6c5cfd: // AND ESI,0xff
s.si = ix::logical(s.si & 0xffu,32,s.arithmetic_flags);
L6c5d03: // SHR ESI,CL
s.si = ix::shift(s.si,(s.cx&255u),32,s.arithmetic_flags,ix::Shift::right);
L6c5d05: // MOV ECX,dword ptr [0x0083b2f8]
s.cx = m.r32(0x0083b2f8);
L6c5d0b: // MOV EAX,dword ptr [ESP + 0xa8]
s.ax = m.r32(f.sp + 0xa8);
L6c5d12: // AND EDX,0xff
s.dx = ix::logical(s.dx & 0xffu,32,s.arithmetic_flags);
L6c5d18: // AND EAX,0xff
s.ax = ix::logical(s.ax & 0xffu,32,s.arithmetic_flags);
L6c5d1d: // PUSH 0x3
f.push(m,0x3u);
L6c5d1f: // PUSH 0x3
f.push(m,0x3u);
L6c5d21: // SHL ESI,CL
s.si = ix::shift(s.si,(s.cx&255u),32,s.arithmetic_flags,ix::Shift::left);
L6c5d23: // MOV CL,byte ptr [0x0083b2f4]
s.cx = (s.cx&0xffffff00u)|(m.r8(0x0083b2f4)&255u);
L6c5d29: // SHR EDX,CL
s.dx = ix::shift(s.dx,(s.cx&255u),32,s.arithmetic_flags,ix::Shift::right);
L6c5d2b: // MOV ECX,dword ptr [0x0083b2f0]
s.cx = m.r32(0x0083b2f0);
L6c5d31: // SHL EDX,CL
s.dx = ix::shift(s.dx,(s.cx&255u),32,s.arithmetic_flags,ix::Shift::left);
L6c5d33: // MOV CL,byte ptr [0x0083b2ec]
s.cx = (s.cx&0xffffff00u)|(m.r8(0x0083b2ec)&255u);
L6c5d39: // SHR EAX,CL
s.ax = ix::shift(s.ax,(s.cx&255u),32,s.arithmetic_flags,ix::Shift::right);
L6c5d3b: // MOV ECX,dword ptr [0x0083b2e8]
s.cx = m.r32(0x0083b2e8);
L6c5d41: // OR ESI,EDX
s.si = ix::logical(s.si | s.dx,32,s.arithmetic_flags);
L6c5d43: // LEA EDX,[ESP + 0x3c]
s.dx = f.sp + 0x3c;
L6c5d47: // SHL EAX,CL
s.ax = ix::shift(s.ax,(s.cx&255u),32,s.arithmetic_flags,ix::Shift::left);
L6c5d49: // OR ESI,EAX
s.si = ix::logical(s.si | s.ax,32,s.arithmetic_flags);
L6c5d4b: // MOV EAX,0xfffffffe
s.ax = 0xfffffffeu;
L6c5d50: // MOV ECX,EAX
s.cx = s.ax;
L6c5d52: // MOV dword ptr [ESP + 0x34],EAX
m.w32(f.sp + 0x34,s.ax);
L6c5d56: // MOV dword ptr [ESP + 0x38],ECX
m.w32(f.sp + 0x38,s.cx);
L6c5d5a: // LEA ECX,[ESP + 0x1c]
s.cx = f.sp + 0x1c;
L6c5d5e: // PUSH ECX
f.push(m,s.cx);
L6c5d5f: // PUSH EDX
f.push(m,s.dx);
L6c5d60: // LEA ECX,[ESP + 0x3c]
s.cx = f.sp + 0x3c;
L6c5d64: // CALL 0x00435400
helpers::point_00435400(context,m,s,f,0x6c5d69u);
L6c5d69: // PUSH EAX
f.push(m,s.ax);
L6c5d6a: // LEA ECX,[ESP + 0x88]
s.cx = f.sp + 0x88;
L6c5d71: // CALL 0x00453ab0
helpers::rectangle_00453ab0(context,m,s,f,0x6c5d76u);
L6c5d76: // MOV ECX,dword ptr [EAX]
s.cx = m.r32(s.ax);
L6c5d78: // PUSH 0x0
f.push(m,0x0u);
L6c5d7a: // MOV dword ptr [ESP + 0x60],ECX
m.w32(f.sp + 0x60,s.cx);
L6c5d7e: // PUSH 0x0
f.push(m,0x0u);
L6c5d80: // MOV EDX,dword ptr [EAX + 0x4]
s.dx = m.r32(s.ax + 0x4);
L6c5d83: // MOV dword ptr [ESP + 0x68],EDX
m.w32(f.sp + 0x68,s.dx);
L6c5d87: // MOV ECX,dword ptr [EAX + 0x8]
s.cx = m.r32(s.ax + 0x8);
L6c5d8a: // MOV dword ptr [ESP + 0x6c],ECX
m.w32(f.sp + 0x6c,s.cx);
L6c5d8e: // LEA ECX,[ESP + 0x74]
s.cx = f.sp + 0x74;
L6c5d92: // MOV EDX,dword ptr [EAX + 0xc]
s.dx = m.r32(s.ax + 0xc);
L6c5d95: // LEA EAX,[ESP + 0x64]
s.ax = f.sp + 0x64;
L6c5d99: // MOV dword ptr [ESP + 0x70],EDX
m.w32(f.sp + 0x70,s.dx);
L6c5d9d: // PUSH EAX
f.push(m,s.ax);
L6c5d9e: // MOV EDX,0x821970
s.dx = 0x821970u;
L6c5da3: // CALL 0x0041fdf0
helpers::intersect_0041fdf0(context,m,s,f,0x6c5da8u);
L6c5da8: // MOV ECX,dword ptr [EAX]
s.cx = m.r32(s.ax);
L6c5daa: // PUSH ESI
f.push(m,s.si);
L6c5dab: // MOV dword ptr [ESP + 0x50],ECX
m.w32(f.sp + 0x50,s.cx);
L6c5daf: // MOV EDX,dword ptr [EAX + 0x4]
s.dx = m.r32(s.ax + 0x4);
L6c5db2: // MOV dword ptr [ESP + 0x54],EDX
m.w32(f.sp + 0x54,s.dx);
L6c5db6: // MOV ECX,dword ptr [EAX + 0x8]
s.cx = m.r32(s.ax + 0x8);
L6c5db9: // MOV dword ptr [ESP + 0x58],ECX
m.w32(f.sp + 0x58,s.cx);
L6c5dbd: // MOV ECX,dword ptr [0x00821ca4]
s.cx = m.r32(0x00821ca4);
L6c5dc3: // MOV EDX,dword ptr [EAX + 0xc]
s.dx = m.r32(s.ax + 0xc);
L6c5dc6: // MOV dword ptr [ESP + 0x5c],EDX
m.w32(f.sp + 0x5c,s.dx);
L6c5dca: // MOV EAX,dword ptr [ECX]
s.ax = m.r32(s.cx);
L6c5dcc: // LEA EDX,[ESP + 0x50]
s.dx = f.sp + 0x50;
L6c5dd0: // PUSH EDX
f.push(m,s.dx);
L6c5dd1: // CALL dword ptr [EAX + 0x14]
helpers::actual_main_slot14(context,m,s,f,0x6c5dd4u,m.r32(s.ax + 0x14));
L6c5dd4: // MOV EAX,0xfffffffe
s.ax = 0xfffffffeu;
L6c5dd9: // PUSH 0x3
f.push(m,0x3u);
L6c5ddb: // MOV ECX,EAX
s.cx = s.ax;
L6c5ddd: // MOV dword ptr [ESP + 0x30],EAX
m.w32(f.sp + 0x30,s.ax);
L6c5de1: // MOV dword ptr [ESP + 0x34],ECX
m.w32(f.sp + 0x34,s.cx);
L6c5de5: // LEA EAX,[ESP + 0x10]
s.ax = f.sp + 0x10;
L6c5de9: // PUSH 0x3
f.push(m,0x3u);
L6c5deb: // LEA ECX,[ESP + 0x3c]
s.cx = f.sp + 0x3c;
L6c5def: // PUSH EAX
f.push(m,s.ax);
L6c5df0: // PUSH ECX
f.push(m,s.cx);
L6c5df1: // LEA ECX,[ESP + 0x3c]
s.cx = f.sp + 0x3c;
L6c5df5: // CALL 0x00435400
helpers::point_00435400(context,m,s,f,0x6c5dfau);
L6c5dfa: // PUSH EAX
f.push(m,s.ax);
L6c5dfb: // LEA ECX,[ESP + 0x88]
s.cx = f.sp + 0x88;
L6c5e02: // CALL 0x00453ab0
helpers::rectangle_00453ab0(context,m,s,f,0x6c5e07u);
L6c5e07: // MOV EDX,dword ptr [EAX]
s.dx = m.r32(s.ax);
L6c5e09: // MOV dword ptr [ESP + 0x5c],EDX
m.w32(f.sp + 0x5c,s.dx);
L6c5e0d: // MOV ECX,dword ptr [EAX + 0x4]
s.cx = m.r32(s.ax + 0x4);
L6c5e10: // PUSH 0x0
f.push(m,0x0u);
L6c5e12: // MOV dword ptr [ESP + 0x64],ECX
m.w32(f.sp + 0x64,s.cx);
L6c5e16: // LEA ECX,[ESP + 0x60]
s.cx = f.sp + 0x60;
L6c5e1a: // MOV EDX,dword ptr [EAX + 0x8]
s.dx = m.r32(s.ax + 0x8);
L6c5e1d: // PUSH 0x0
f.push(m,0x0u);
L6c5e1f: // MOV dword ptr [ESP + 0x6c],EDX
m.w32(f.sp + 0x6c,s.dx);
L6c5e23: // PUSH ECX
f.push(m,s.cx);
L6c5e24: // MOV EAX,dword ptr [EAX + 0xc]
s.ax = m.r32(s.ax + 0xc);
L6c5e27: // MOV EDX,0x821970
s.dx = 0x821970u;
L6c5e2c: // LEA ECX,[ESP + 0x78]
s.cx = f.sp + 0x78;
L6c5e30: // MOV dword ptr [ESP + 0x74],EAX
m.w32(f.sp + 0x74,s.ax);
L6c5e34: // CALL 0x0041fdf0
helpers::intersect_0041fdf0(context,m,s,f,0x6c5e39u);
L6c5e39: // MOV EDX,dword ptr [EAX]
s.dx = m.r32(s.ax);
L6c5e3b: // PUSH ESI
f.push(m,s.si);
L6c5e3c: // MOV dword ptr [ESP + 0x50],EDX
m.w32(f.sp + 0x50,s.dx);
L6c5e40: // MOV ECX,dword ptr [EAX + 0x4]
s.cx = m.r32(s.ax + 0x4);
L6c5e43: // MOV dword ptr [ESP + 0x54],ECX
m.w32(f.sp + 0x54,s.cx);
L6c5e47: // MOV ECX,dword ptr [0x00821ca4]
s.cx = m.r32(0x00821ca4);
L6c5e4d: // MOV EDX,dword ptr [EAX + 0x8]
s.dx = m.r32(s.ax + 0x8);
L6c5e50: // MOV dword ptr [ESP + 0x58],EDX
m.w32(f.sp + 0x58,s.dx);
L6c5e54: // MOV EAX,dword ptr [EAX + 0xc]
s.ax = m.r32(s.ax + 0xc);
L6c5e57: // MOV dword ptr [ESP + 0x5c],EAX
m.w32(f.sp + 0x5c,s.ax);
L6c5e5b: // MOV EDX,dword ptr [ECX]
s.dx = m.r32(s.cx);
L6c5e5d: // LEA EAX,[ESP + 0x50]
s.ax = f.sp + 0x50;
L6c5e61: // PUSH EAX
f.push(m,s.ax);
L6c5e62: // CALL dword ptr [EDX + 0x14]
helpers::actual_main_slot14(context,m,s,f,0x6c5e65u,m.r32(s.dx + 0x14));
L6c5e65: // MOV AL,byte ptr [ESP + 0xac]
s.ax = (s.ax&0xffffff00u)|(m.r8(f.sp + 0xac)&255u);
L6c5e6c: // TEST AL,AL
(void)ix::logical((s.ax&255u)&(s.ax&255u),8,s.arithmetic_flags);
L6c5e6e: // JZ 0x006c5ec7
if(ix::condition("JZ",s.arithmetic_flags)) goto L6c5ec7; throw std::runtime_error("2c5a80 selected-path branch escaped");
L6c5ec7: // LEA EAX,[ESP + 0x3c]
s.ax = f.sp + 0x3c;
L6c5ecb: // LEA EDX,[ESP + 0xc]
s.dx = f.sp + 0xc;
L6c5ecf: // PUSH EAX
f.push(m,s.ax);
L6c5ed0: // LEA ECX,[ESP + 0x18]
s.cx = f.sp + 0x18;
L6c5ed4: // CALL 0x00760f60
helpers::reject_00760f60(context,m,s,f,0x6c5ed9u);
L6c5ed9: // TEST AL,AL
(void)ix::logical((s.ax&255u)&(s.ax&255u),8,s.arithmetic_flags);
L6c5edb: // JZ 0x006c5ef3
if(ix::condition("JZ",s.arithmetic_flags)) goto L6c5ef3; throw std::runtime_error("2c5a80 selected-path branch escaped");
L6c5ef3: // POP EDI
s.di = f.pop(m);
L6c5ef4: // POP ESI
s.si = f.pop(m);
L6c5ef5: // POP EBX
s.bx = f.pop(m);
L6c5ef6: // ADD ESP,0x80
f.sp = ix::add(f.sp,0x80u,32,s.arithmetic_flags);
L6c5efc: // RET 0x24
recovery_b566::finish(m,s,f,0x24u); return;
}
}

// END original fragment

// BEGIN original fragment: numeric_source_bridge_plan/source_bridge.cpp
namespace ra2::recovered::b1698::numeric_core {
void project(Memory& m,State& s,Frame& f,U continuation){
  if(continuation!=0x6c5aa1u && continuation!=0x6c5ab9u)
    throw std::runtime_error("2c5a80 projection continuation outside selected callers");
  f.push(m,continuation);
  const U entry=f.sp;
  // Only two actual callee arguments are read. Never read/copy sixteen
  // unproduced Root-local words merely to populate unused descriptor entries.
  numeric_b88::Inputs child{};
  child.ax=s.ax; child.cx=s.cx; child.dx=s.dx;
  child.arithmetic_flags=s.arithmetic_flags;
  child.arg[0]=m.r32(entry+4u);
  child.arg[1]=m.r32(entry+8u);
  child.fp=s.fp;
  const U result=numeric_b88::fun_00698010(m,child);
  // B88 writes its *own* raw caller arg0. This outgoing copy is not the
  // Root's by-value world-coordinate word addressed through the old pointer.
  m.w32(entry+4u,child.arg[0]);
  s.ax=result;
  s.fp=child.fp;
  Frame callee{entry,entry,continuation};
  recovery_b566::finish(m,s,callee,8u);
  f.sp=callee.sp;
  // The public B88 API does not expose CX/DX/arithmetic-flags poststate.
  // Both exact Root callsites kill those volatile values before any use.
  // Do not invent values here or claim a general full-register B88 ABI.
}
}

// END original fragment

// BEGIN original fragment: numeric_source_bridge_plan/derived_reject.cpp
namespace ra2::recovered::b1698::numeric_core {
namespace {
namespace integer=direct_b33::integer;
using floating_b61::read64;
using floating_b61::write64;
using floating_b61::with_ax;
using floating_b61::with_al;
void execute_existing_reject_model(Memory& m,State& s,Frame& f){
  std::uint32_t flags=s.arithmetic_flags;
  L00760f60: { // 0x760f60: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00760f61: { // 0x760f61: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00760f63: { // 0x760f63: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00760f66: { // 0x760f66: 83ec64 SUB ESP,0x64
    f.sp = integer::sub(f.sp,0x00000064u,32,flags);
  }
  L00760f69: { // 0x760f69: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00760f6a: { // 0x760f6a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00760f6b: { // 0x760f6b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760f6c: { // 0x760f6c: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00760f6e: { // 0x760f6e: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00760f70: { // 0x760f70: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L00760f73: { // 0x760f73: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00760f77: { // 0x760f77: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00760f79: { // 0x760f79: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  L00760f7c: { // 0x760f7c: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00760f80: { // 0x760f80: 8b5908 MOV EBX,dword ptr [ECX + 0x8]
    s.bx = m.r32((s.cx+0x00000008u));
  }
  L00760f83: { // 0x760f83: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f87: { // 0x760f87: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00760f8b: { // 0x760f8b: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L00760f8d: { // 0x760f8d: dd542430 FST double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00760f91: { // 0x760f91: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f95: { // 0x760f95: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00760f99: { // 0x760f99: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00760f9b: { // 0x760f9b: db02 FILD dword ptr [EDX]
    const auto address=(s.dx);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f9d: { // 0x760f9d: dd5c2438 FSTP double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fa1: { // 0x760fa1: db4204 FILD dword ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fa4: { // 0x760fa4: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00760fa6: { // 0x760fa6: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760faa: { // 0x760faa: db07 FILD dword ptr [EDI]
    const auto address=(s.di);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fac: { // 0x760fac: dd542468 FST double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00760fb0: { // 0x760fb0: db4704 FILD dword ptr [EDI + 0x4]
    const auto address=(s.di+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fb3: { // 0x760fb3: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fb7: { // 0x760fb7: dd442438 FLD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L00760fbb: { // 0x760fbb: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00760fbd: { // 0x760fbd: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L00760fbf: { // 0x760fbf: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00760fc3: { // 0x760fc3: dc642428 FSUB double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract64(read64(m,address));
  }
  L00760fc7: { // 0x760fc7: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00760fc9: { // 0x760fc9: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00760fcb: { // 0x760fcb: dd5c2458 FSTP double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fcf: { // 0x760fcf: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00760fd1: { // 0x760fd1: dd5c2460 FSTP double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fd5: { // 0x760fd5: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00760fd7: { // 0x760fd7: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fdb: { // 0x760fdb: dd5c2448 FSTP double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fdf: { // 0x760fdf: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00760fe3: { // 0x760fe3: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00760fe5: { // 0x760fe5: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00760fe8: { // 0x760fe8: 7509 JNZ 0x00760ff3
    if(integer::condition("JNZ",flags)) goto L00760ff3;
  }
  L00760fea: { // 0x760fea: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00760fec: { // 0x760fec: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L00760ff1: { // 0x760ff1: eb0e JMP 0x00761001
    goto L00761001;
  }
  L00760ff3: { // 0x760ff3: d8dc FCOMP ST4
    numeric_b88::detail::reg<0xd8dc>(s.fp);
  }
  L00760ff5: { // 0x760ff5: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00760ff7: { // 0x760ff7: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00760ffa: { // 0x760ffa: 7405 JZ 0x00761001
    if(integer::condition("JZ",flags)) goto L00761001;
  }
  L00760ffc: { // 0x760ffc: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L00761001: { // 0x761001: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L00761004: { // 0x761004: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00761006: { // 0x761006: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0076100a: { // 0x76100a: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L0076100e: { // 0x76100e: dd5c2450 FSTP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00761012: { // 0x761012: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L00761016: { // 0x761016: dc5c2450 FCOMP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0076101a: { // 0x76101a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076101c: { // 0x76101c: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0076101f: { // 0x76101f: 7505 JNZ 0x00761026
    if(integer::condition("JNZ",flags)) goto L00761026;
  }
  L00761021: { // 0x761021: 83ca04 OR EDX,0x4
    s.dx = integer::logical((s.dx)|(0x00000004u),32,flags);
  }
  L00761024: { // 0x761024: eb10 JMP 0x00761036
    goto L00761036;
  }
  L00761026: { // 0x761026: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L0076102a: { // 0x76102a: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L0076102c: { // 0x76102c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076102e: { // 0x76102e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761031: { // 0x761031: 7403 JZ 0x00761036
    if(integer::condition("JZ",flags)) goto L00761036;
  }
  L00761033: { // 0x761033: 83ca08 OR EDX,0x8
    s.dx = integer::logical((s.dx)|(0x00000008u),32,flags);
  }
  L00761036: { // 0x761036: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0076103a: { // 0x76103a: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0076103c: { // 0x76103c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076103e: { // 0x76103e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761041: { // 0x761041: 7509 JNZ 0x0076104c
    if(integer::condition("JNZ",flags)) goto L0076104c;
  }
  L00761043: { // 0x761043: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761045: { // 0x761045: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L0076104a: { // 0x76104a: eb0e JMP 0x0076105a
    goto L0076105a;
  }
  L0076104c: { // 0x76104c: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L0076104e: { // 0x76104e: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761050: { // 0x761050: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761053: { // 0x761053: 7405 JZ 0x0076105a
    if(integer::condition("JZ",flags)) goto L0076105a;
  }
  L00761055: { // 0x761055: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L0076105a: { // 0x76105a: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L0076105e: { // 0x76105e: dc5c2450 FCOMP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00761062: { // 0x761062: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761064: { // 0x761064: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761067: { // 0x761067: 7505 JNZ 0x0076106e
    if(integer::condition("JNZ",flags)) goto L0076106e;
  }
  L00761069: { // 0x761069: 83c904 OR ECX,0x4
    s.cx = integer::logical((s.cx)|(0x00000004u),32,flags);
  }
  L0076106c: { // 0x76106c: eb10 JMP 0x0076107e
    goto L0076107e;
  }
  L0076106e: { // 0x76106e: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00761072: { // 0x761072: d8da FCOMP ST2
    numeric_b88::detail::reg<0xd8da>(s.fp);
  }
  L00761074: { // 0x761074: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761076: { // 0x761076: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761079: { // 0x761079: 7403 JZ 0x0076107e
    if(integer::condition("JZ",flags)) goto L0076107e;
  }
  L0076107b: { // 0x76107b: 83c908 OR ECX,0x8
    s.cx = integer::logical((s.cx)|(0x00000008u),32,flags);
  }
  L0076107e: { // 0x76107e: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00761080: { // 0x761080: 7508 JNZ 0x0076108a
    if(integer::condition("JNZ",flags)) goto L0076108a;
  }
  L00761082: { // 0x761082: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00761084: { // 0x761084: 0f844f010000 JZ 0x007611d9
    if(integer::condition("JZ",flags)) goto L007611d9;
  }
  L0076108a: { // 0x76108a: 85ca TEST EDX,ECX
    (void)integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076108c: { // 0x76108c: 0f858a010000 JNZ 0x0076121c
    if(integer::condition("JNZ",flags)) goto L0076121c;
  }
  // Original 761092 begins the unselected clipping/FTOL route.
  throw std::runtime_error("2c5a80 clipping left selected common-reject route");
L007611d9:
  // Original 7611D9 is the unselected both-inside/success route.
  throw std::runtime_error("2c5a80 clipping selected an unsupported success route");
  L0076121c: { // 0x76121c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0076121e: { // 0x76121e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761220: { // 0x761220: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00761221: { // 0x761221: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761222: { // 0x761222: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761224: { // 0x761224: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00761226: { // 0x761226: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00761227: { // 0x761227: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00761229: { // 0x761229: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076122a: { // 0x76122a: c20400 RET 0x4
    s.arithmetic_flags=flags; recovery_b566::finish(m,s,f,4u); return;
  }
}
}
void reject(Memory& m,State& s,Frame& f,U continuation){
  if(continuation!=0x6c5ed9u)
    throw std::runtime_error("2c5a80 tail continuation outside selected caller");
  const U clip=m.r32(f.sp);
  if(m.r32(s.cx)!=0xffffffffu || m.r32(s.cx+4u)!=9u ||
     m.r32(s.dx)!=1u || m.r32(s.dx+4u)!=9u ||
     m.r32(clip)!=0u || m.r32(clip+4u)!=8u ||
     m.r32(clip+8u)!=32u || m.r32(clip+12u)!=1u)
    throw std::runtime_error("2c5a80 tail input outside exact finite basis");
  f.push(m,continuation);
  Frame child{f.sp,f.sp,continuation};
  // Child identity uses the actual outgoing guest stack, not a new stack array.
  // The same State/FP and every actual local write pass through this model.
  execute_existing_reject_model(m,s,child);
  f.sp=child.sp;
}
}

// END original fragment

// BEGIN original fragment: numeric_source_bridge_plan/context_forward.cpp
namespace ra2::recovered::b1698::helpers {
void project_00698010(Context&,Memory& m,State& s,Frame& f,U continuation){
  numeric_core::project(m,s,f,continuation);
}
void reject_00760f60(Context&,Memory& m,State& s,Frame& f,U continuation){
  numeric_core::reject(m,s,f,continuation);
}
}

// END original fragment

// BEGIN original fragment: source_bridge/bridge.cpp

namespace ra2::recovered::b1698::helpers {
namespace {
using Primitive = void (*)(b1647::Memory&, b1647::State&,
                           recovery_b566::Frame&, b1647::Api&,
                           unsigned, unsigned);
static_assert(sizeof(void*) == 4 && sizeof(U) == 4);
static_assert(std::is_same_v<U, unsigned>);
static_assert(std::is_same_v<Memory, b1647::Memory>);
static_assert(std::is_same_v<State, b1647::State>);
static_assert(std::is_same_v<Frame, recovery_b566::Frame>);
static_assert(std::is_same_v<decltype(Context::api), b1647::Api&>);
static_assert(std::is_same_v<decltype(Context::main), U>);
static_assert(std::is_same_v<decltype(&b1647::primitive_point), Primitive>);
static_assert(std::is_same_v<decltype(&b1647::primitive_rect), Primitive>);
static_assert(std::is_same_v<decltype(&b1647::primitive_intersect), Primitive>);
static_assert(std::is_same_v<decltype(&b1647::primitive_main14), Primitive>);
}

void point_00435400(Context& context, Memory& world, State& state,
                    Frame& caller, U continuation) {
    b1647::primitive_point(world, state, caller, context.api, context.main,
                          continuation);
}

void rectangle_00453ab0(Context& context, Memory& world, State& state,
                        Frame& caller, U continuation) {
    b1647::primitive_rect(world, state, caller, context.api, context.main,
                         continuation);
}

void intersect_0041fdf0(Context& context, Memory& world, State& state,
                       Frame& caller, U continuation) {
    b1647::primitive_intersect(world, state, caller, context.api, context.main,
                              continuation);
}

void actual_main_slot14(Context& context, Memory& world, State& state,
                        Frame& caller, U continuation, U actual_target) {
    if (actual_target != 0x004ab200u)
        throw std::domain_error("2C5A80 requires actual Main slot14 target 4AB200");
    b1647::primitive_main14(world, state, caller, context.api, context.main,
                           continuation);
}
}

// END original fragment

// BEGIN original fragment: finite_preflight/preflight.cpp

namespace ra2::recovered::b1698::helpers {
namespace {
using U = std::uint32_t;
using Wide = std::uint64_t;
constexpr Wide kAddressLimit = Wide{1} << 32;
constexpr U kNestedClipLow = 0x10cu; // deepest declared nested clip entry relative to Root entry.
constexpr U kMainVtable = 0x78bbe4u;

void need(bool condition, const char* message) {
    if (!condition) throw std::domain_error(message);
}

void mapped(const Memory& memory, U base, Wide bytes, const char* message) {
    const Wide end = Wide{base} + bytes;
    need(bytes != 0 && end <= kAddressLimit, message);
    try {
        for (Wide at = base; at < end; ++at)
            (void)memory.r8(static_cast<U>(at));
    } catch (const std::out_of_range&) {
        throw std::domain_error(message);
    }
}

void disjoint(U a, Wide a_bytes, U b, Wide b_bytes, const char* message) {
    const Wide ae = Wide{a} + a_bytes;
    const Wide be = Wide{b} + b_bytes;
    need(ae <= kAddressLimit && be <= kAddressLimit &&
         (ae <= b || be <= a), message);
}

void equal32(const Memory& memory, U address, U expected, const char* message) {
    need(memory.r32(address) == expected, message);
}
void equal8(const Memory& memory, U address, U expected, const char* message) {
    need(memory.r8(address) == expected, message);
}
} // namespace

void require_selected_basis(Context& context, const Memory& memory,
                            const State& state, const Frame& frame) {
    // The entry frame must be intact. Map the complete caller16 window, Root/save
    // locals, nested clip entry and aligned guard before reading its inputs.
    const Wide entry = frame.entry_sp;
    need(frame.sp == frame.entry_sp, "Root entry ESP must equal frame entry_sp");
    need(entry >= Wide{kNestedClipLow} + 16u && entry + 0x44u <= kAddressLimit,
         "Root stack range wraps guest32 address space");
    const Wide nested_low = entry - kNestedClipLow;
    const Wide aligned_guard = (nested_low & ~Wide{0x0fu}) - 16u;
    need(aligned_guard != 0u && aligned_guard < nested_low, "aligned nested-helper guard invalid");
    const U stack_base = static_cast<U>(aligned_guard);
    const Wide stack_bytes = entry + 0x44u - aligned_guard;
    mapped(memory, stack_base, stack_bytes, "incomplete Root/nested-helper frame/caller16 mapping");
    need(memory.r32(frame.entry_sp) == frame.outer_return,
         "modeled Root return word does not match frame.outer_return");

    constexpr U expected[9] = {4u, 16u, 0u, 16u, 4u, 0u, 0x800u, 0u, 0u};
    for (U i = 0; i < 16u; ++i) {
        const U value = memory.r32(frame.entry_sp + 4u + 4u * i);
        if (i < 9u)
            need(value == expected[i], "Root words0..8 differ from frozen basis");
        // Words9..15 are intentionally opaque, explicit caller-owned input.
        // Their extents are required and later compared unchanged only within
        // the independently qualified helper/provider stack domain.
    }

    // The physically established x87 basis is numeric-only at entry: CW/SW/TW
    // and all80 bytes are fixed. FIP/FDP/opcode/reserved bytes stay opaque.
    const auto& fp = state.fp.image;
    need(fp.word(0) == 0x037fu && fp.word(4) == 0u && fp.word(8) == 0xffffu,
         "x87 entry must match CW037F/SW0000/TWFFFF/TOP0 basis");
    for (U i = 28u; i < 108u; ++i)
        need(fp.bytes[i] == 0u, "x87 entry raw80 must be all zero");

    // Coordinate camera and read-only numeric inputs used by the two B88
    // projections. These are value checks only; Memory exposes no page-protection
    // query, and this function performs no writes.
    const U camera = memory.r32(0x821cacu);
    need(camera != 0u, "camera pointer is null");
    mapped(memory, camera, 0xb8u, "camera B0/B4 input extent is not mapped");
    equal32(memory, camera + 0xb0u, 0u, "camera+B0 differs from selected basis");
    equal32(memory, camera + 0xb4u, 0u, "camera+B4 differs from selected basis");

    equal32(memory, 0x821970u, 0u, "clip left input mismatch");
    equal32(memory, 0x821974u, 8u, "clip top input mismatch");
    equal32(memory, 0x821978u, 32u, "clip right input mismatch");
    equal32(memory, 0x82197cu, 1u, "clip bottom input mismatch");
    equal32(memory, 0xaa5f90u, 0u, "scale low DWORD mismatch");
    equal32(memory, 0xaa5f94u, 0x3fc00000u, "scale high DWORD is not 0.125");
    equal32(memory, 0x785728u, 0u, "readonly 0.5 operand low DWORD mismatch");
    equal32(memory, 0x78572cu, 0x3fe00000u, "readonly operand is not 0.5");
    equal32(memory, 0xaa6070u, 640u, "B88 projection width input mismatch");
    equal32(memory, 0xaa6074u, 480u, "B88 projection height input mismatch");
    equal32(memory, 0x7c3a04u, 0x0f7fu, "cached-CW input mismatch");

    // Main32 RGB input is 0x800 and uses the declared 32-bit component masks.
    equal32(memory, 0x83b2ecu, 0u, "red right-shift DWORD mismatch");
    equal32(memory, 0x83b2e8u, 0u, "red left-shift input mismatch");
    equal32(memory, 0x83b2fcu, 0u, "green right-shift DWORD mismatch");
    equal32(memory, 0x83b2f8u, 8u, "green left-shift input mismatch");
    equal32(memory, 0x83b2f4u, 0u, "blue right-shift DWORD mismatch");
    equal32(memory, 0x83b2f0u, 16u, "blue left-shift input mismatch");

    // Bind the actual normal Main addresspoint and the exact reusable slots.
    // Context::api is deliberately not invoked here: provider lifecycle and SDK
    // identity are external gates, not preflight side effects.
    need(context.main != 0u, "Main receiver pointer is null");
    mapped(memory, context.main, 36u, "Main header extent is not mapped");
    equal32(memory, 0x821ca4u, context.main, "821CA4 does not identify Context Main");
    equal32(memory, context.main, kMainVtable, "Main is not normal primary 78BBE4");
    equal32(memory, context.main + 4u, 32u, "Main width differs from 32");
    equal32(memory, context.main + 8u, 24u, "Main height differs from 24");
    equal32(memory, context.main + 0x0cu, 1u, "Main is not C1");
    equal32(memory, context.main + 0x10u, 4u, "Main address stride is not four bytes");
    equal8(memory, context.main + 0x18u, 1u, "Main software/construction byte differs from 1");
    equal8(memory, 0x7c13c4u, 1u, "software renderer flag is not 1");
    equal8(memory, 0x839fe0u, 1u, "software-rendered surface flag is not 1");

    const U expected_slots[][2] = {
        {0x14u, 0x004ab200u}, {0x78u, 0x00411290u},
        {0x6cu, 0x00411300u}, {0x5cu, 0x004aa990u},
        {0x60u, 0x004aab50u}, {0x70u, 0x004aa970u},
        {0x74u, 0x004aa980u}
    };
    for (const auto& slot : expected_slots)
        equal32(memory, kMainVtable + slot[0], slot[1],
                "normal Main vtable slot differs from pinned contract");

    const U backing = memory.r32(context.main + 0x14u);
    const U provider = memory.r32(context.main + 0x1cu);
    const U descriptor = memory.r32(context.main + 0x20u);
    need(provider != 0u, "Main provider pointer is null (identity still external)");
    need(backing != 0u && descriptor != 0u, "Main backing/descriptor pointer is null");
    mapped(memory, backing, 128u * 24u, "full Main 3072-byte backing is not mapped");
    mapped(memory, descriptor, 112u, "full Main 112-byte descriptor is not mapped");
    equal32(memory, descriptor + 8u, 24u, "descriptor height mismatch");
    equal32(memory, descriptor + 12u, 32u, "descriptor width mismatch");
    equal32(memory, descriptor + 16u, 128u, "descriptor pitch is not 128");
    equal32(memory, descriptor + 84u, 32u, "descriptor bit-depth mismatch");
    need((memory.r32(descriptor + 104u) & 0x2040u) == 0x2040u,
         "descriptor is not in declared software C1 state");

    // The selected write is an independent input-difference requirement, never
    // a result seed. Only four bytes are read; the full backing above is merely
    // proven present, not rewritten or normalized.
    constexpr U patch[4] = {0x00u, 0x08u, 0x00u, 0x08u};
    bool differs = false;
    for (U i = 0; i < 4u; ++i)
        differs = differs || memory.r8(backing + 1024u + i) != patch[i];
    need(differs, "selected four-byte WORD pattern would be a no-op");

    // The camera and public Main objects/backing may not alias Root-owned stack
    // or each other; all interval arithmetic stays guest32-bounded.
    disjoint(stack_base, stack_bytes, camera, 0xb8u, "camera overlaps Root stack/caller16");
    disjoint(stack_base, stack_bytes, context.main, 36u, "Main header overlaps Root stack");
    disjoint(stack_base, stack_bytes, descriptor, 112u, "Main descriptor overlaps Root stack");
    disjoint(stack_base, stack_bytes, backing, 3072u, "Main backing overlaps Root stack");
    disjoint(camera, 0xb8u, context.main, 36u, "camera overlaps Main header");
    disjoint(camera, 0xb8u, descriptor, 112u, "camera overlaps Main descriptor");
    disjoint(camera, 0xb8u, backing, 3072u, "camera overlaps Main backing");
    disjoint(context.main, 36u, descriptor, 112u, "Main header overlaps descriptor");
    disjoint(context.main, 36u, backing, 3072u, "Main header overlaps backing");
    disjoint(descriptor, 112u, backing, 3072u, "descriptor overlaps backing");
}
} // namespace ra2::recovered::b1698::helpers
// END original fragment

