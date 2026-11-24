#include "recovered/recovery_b619_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b619 {
namespace {
void f_0000ff60(Memory&,State&,Frame&,const Operations&);
void f_000f7f40(Memory&,State&,Frame&,const Operations&);
void f_000f7f90(Memory&,State&,Frame&,const Operations&);
void f_000f7e50(Memory&,State&,Frame&,const Operations&);
void f_000919e0(Memory&,State&,Frame&,const Operations&);
void f_000f7fe0(Memory&,State&,Frame&,const Operations&);
void f_000f8080(Memory&,State&,Frame&,const Operations&);
void f_000a6620(Memory&,State&,Frame&,const Operations&);
void f_0002ca50(Memory&,State&,Frame&,const Operations&);
void f_0002d430(Memory&,State&,Frame&,const Operations&);
void f_0002d4a0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0000ff60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ff60: { // 0x40ff60: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0040ff62: { // 0x40ff62: c74008445e7800 MOV dword ptr [EAX + 0x8],0x785e44
    m.w32((s.ax+0x00000008u), 0x00785e44u);
  }
  L0040ff69: { // 0x40ff69: c7400c3c5e7800 MOV dword ptr [EAX + 0xc],0x785e3c
    m.w32((s.ax+0x0000000cu), 0x00785e3cu);
  }
  L0040ff70: { // 0x40ff70: c700d85d7800 MOV dword ptr [EAX],0x785dd8
    m.w32((s.ax), 0x00785dd8u);
  }
  L0040ff76: { // 0x40ff76: c74004bc5d7800 MOV dword ptr [EAX + 0x4],0x785dbc
    m.w32((s.ax+0x00000004u), 0x00785dbcu);
  }
  L0040ff7d: { // 0x40ff7d: c74008b45d7800 MOV dword ptr [EAX + 0x8],0x785db4
    m.w32((s.ax+0x00000008u), 0x00785db4u);
  }
  L0040ff84: { // 0x40ff84: c7400cac5d7800 MOV dword ptr [EAX + 0xc],0x785dac
    m.w32((s.ax+0x0000000cu), 0x00785dacu);
  }
  L0040ff8b: { // 0x40ff8b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000f7f40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f7f40: { // 0x4f7f40: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L004f7f44: { // 0x4f7f44: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f7f45: { // 0x4f7f45: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004f7f47: { // 0x4f7f47: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004f7f49: { // 0x4f7f49: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004f7f4b: { // 0x4f7f4b: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L004f7f4e: { // 0x4f7f4e: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L004f7f51: { // 0x4f7f51: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L004f7f55: { // 0x4f7f55: 88560d MOV byte ptr [ESI + 0xd],DL
    m.w8((s.si+0x0000000du), (s.dx & 0xffu));
  }
  L004f7f58: { // 0x4f7f58: c70604db7800 MOV dword ptr [ESI],0x78db04
    m.w32((s.si), 0x0078db04u);
  }
  L004f7f5e: { // 0x4f7f5e: 7424 JZ 0x004f7f84
    if(integer::condition("JZ",flags)) goto L004f7f84;
  }
  L004f7f60: { // 0x4f7f60: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L004f7f64: { // 0x4f7f64: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004f7f66: { // 0x4f7f66: 7409 JZ 0x004f7f71
    if(integer::condition("JZ",flags)) goto L004f7f71;
  }
  L004f7f68: { // 0x4f7f68: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L004f7f6b: { // 0x4f7f6b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004f7f6d: { // 0x4f7f6d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f7f6e: { // 0x4f7f6e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004f7f71: { // 0x4f7f71: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L004f7f74: { // 0x4f7f74: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f7f75: { // 0x4f7f75: e8dd592700 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5209978u); flags=s.arithmetic_flags;
  }
  L004f7f7a: { // 0x4f7f7a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004f7f7d: { // 0x4f7f7d: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L004f7f80: { // 0x4f7f80: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L004f7f84: { // 0x4f7f84: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004f7f86: { // 0x4f7f86: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f7f87: { // 0x4f7f87: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000f7f90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f7f90: { // 0x4f7f90: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L004f7f94: { // 0x4f7f94: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f7f95: { // 0x4f7f95: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004f7f97: { // 0x4f7f97: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004f7f99: { // 0x4f7f99: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004f7f9b: { // 0x4f7f9b: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L004f7f9e: { // 0x4f7f9e: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L004f7fa1: { // 0x4f7fa1: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L004f7fa5: { // 0x4f7fa5: 88560d MOV byte ptr [ESI + 0xd],DL
    m.w8((s.si+0x0000000du), (s.dx & 0xffu));
  }
  L004f7fa8: { // 0x4f7fa8: c70684d37800 MOV dword ptr [ESI],0x78d384
    m.w32((s.si), 0x0078d384u);
  }
  L004f7fae: { // 0x4f7fae: 7424 JZ 0x004f7fd4
    if(integer::condition("JZ",flags)) goto L004f7fd4;
  }
  L004f7fb0: { // 0x4f7fb0: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L004f7fb4: { // 0x4f7fb4: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004f7fb6: { // 0x4f7fb6: 7409 JZ 0x004f7fc1
    if(integer::condition("JZ",flags)) goto L004f7fc1;
  }
  L004f7fb8: { // 0x4f7fb8: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L004f7fbb: { // 0x4f7fbb: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004f7fbd: { // 0x4f7fbd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f7fbe: { // 0x4f7fbe: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004f7fc1: { // 0x4f7fc1: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L004f7fc4: { // 0x4f7fc4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f7fc5: { // 0x4f7fc5: e88d592700 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5210058u); flags=s.arithmetic_flags;
  }
  L004f7fca: { // 0x4f7fca: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004f7fcd: { // 0x4f7fcd: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L004f7fd0: { // 0x4f7fd0: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L004f7fd4: { // 0x4f7fd4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004f7fd6: { // 0x4f7fd6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f7fd7: { // 0x4f7fd7: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000f7e50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f7e50: { // 0x4f7e50: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L004f7e54: { // 0x4f7e54: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f7e55: { // 0x4f7e55: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004f7e57: { // 0x4f7e57: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004f7e59: { // 0x4f7e59: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004f7e5b: { // 0x4f7e5b: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L004f7e5e: { // 0x4f7e5e: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L004f7e61: { // 0x4f7e61: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L004f7e65: { // 0x4f7e65: 88560d MOV byte ptr [ESI + 0xd],DL
    m.w8((s.si+0x0000000du), (s.dx & 0xffu));
  }
  L004f7e68: { // 0x4f7e68: c70644da7800 MOV dword ptr [ESI],0x78da44
    m.w32((s.si), 0x0078da44u);
  }
  L004f7e6e: { // 0x4f7e6e: 7424 JZ 0x004f7e94
    if(integer::condition("JZ",flags)) goto L004f7e94;
  }
  L004f7e70: { // 0x4f7e70: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L004f7e74: { // 0x4f7e74: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004f7e76: { // 0x4f7e76: 7409 JZ 0x004f7e81
    if(integer::condition("JZ",flags)) goto L004f7e81;
  }
  L004f7e78: { // 0x4f7e78: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L004f7e7b: { // 0x4f7e7b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004f7e7d: { // 0x4f7e7d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f7e7e: { // 0x4f7e7e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004f7e81: { // 0x4f7e81: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L004f7e84: { // 0x4f7e84: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f7e85: { // 0x4f7e85: e8cd5a2700 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5209738u); flags=s.arithmetic_flags;
  }
  L004f7e8a: { // 0x4f7e8a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004f7e8d: { // 0x4f7e8d: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L004f7e90: { // 0x4f7e90: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L004f7e94: { // 0x4f7e94: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004f7e96: { // 0x4f7e96: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f7e97: { // 0x4f7e97: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000919e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004919e0: { // 0x4919e0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004919e2: { // 0x4919e2: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004919e4: { // 0x4919e4: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L004919e7: { // 0x4919e7: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L004919ea: { // 0x4919ea: c6400c01 MOV byte ptr [EAX + 0xc],0x1
    m.w8((s.ax+0x0000000cu), 0x00000001u);
  }
  L004919ee: { // 0x4919ee: 88480d MOV byte ptr [EAX + 0xd],CL
    m.w8((s.ax+0x0000000du), (s.cx & 0xffu));
  }
  L004919f1: { // 0x4919f1: c700ac957800 MOV dword ptr [EAX],0x7895ac
    m.w32((s.ax), 0x007895acu);
  }
  L004919f7: { // 0x4919f7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000f7fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f7fe0: { // 0x4f7fe0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004f7fe1: { // 0x4f7fe1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f7fe2: { // 0x4f7fe2: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  L004f7fe6: { // 0x4f7fe6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f7fe7: { // 0x4f7fe7: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L004f7fe9: { // 0x4f7fe9: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004f7feb: { // 0x4f7feb: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L004f7fed: { // 0x4f7fed: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L004f7ff0: { // 0x4f7ff0: 897708 MOV dword ptr [EDI + 0x8],ESI
    m.w32((s.di+0x00000008u), s.si);
  }
  L004f7ff3: { // 0x4f7ff3: c6470c01 MOV byte ptr [EDI + 0xc],0x1
    m.w8((s.di+0x0000000cu), 0x00000001u);
  }
  L004f7ff7: { // 0x4f7ff7: 885f0d MOV byte ptr [EDI + 0xd],BL
    m.w8((s.di+0x0000000du), (s.bx & 0xffu));
  }
  L004f7ffa: { // 0x4f7ffa: c70784de7800 MOV dword ptr [EDI],0x78de84
    m.w32((s.di), 0x0078de84u);
  }
  L004f8000: { // 0x4f8000: 7469 JZ 0x004f806b
    if(integer::condition("JZ",flags)) goto L004f806b;
  }
  L004f8002: { // 0x4f8002: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L004f8006: { // 0x4f8006: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L004f8008: { // 0x4f8008: 7420 JZ 0x004f802a
    if(integer::condition("JZ",flags)) goto L004f802a;
  }
  L004f800a: { // 0x4f800a: 8d4eff LEA ECX,[ESI + -0x1]
    s.cx = (s.si-0x00000001u);
  }
  L004f800d: { // 0x4f800d: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L004f800f: { // 0x4f800f: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L004f8011: { // 0x4f8011: 7c0c JL 0x004f801f
    if(integer::condition("JL",flags)) goto L004f801f;
  }
  L004f8013: { // 0x4f8013: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L004f8014: { // 0x4f8014: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L004f8016: { // 0x4f8016: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
  L004f8019: { // 0x4f8019: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L004f801c: { // 0x4f801c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004f801d: { // 0x4f801d: 75f5 JNZ 0x004f8014
    if(integer::condition("JNZ",flags)) goto L004f8014;
  }
  L004f801f: { // 0x4f801f: 895704 MOV dword ptr [EDI + 0x4],EDX
    m.w32((s.di+0x00000004u), s.dx);
  }
  L004f8022: { // 0x4f8022: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004f8024: { // 0x4f8024: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f8025: { // 0x4f8025: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f8026: { // 0x4f8026: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f8027: { // 0x4f8027: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004f802a: { // 0x4f802a: 8d04f500000000 LEA EAX,[ESI*0x8 + 0x0]
    s.ax = ((s.si * 0x00000008u)+0x00000000u);
  }
  L004f8031: { // 0x4f8031: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f8032: { // 0x4f8032: e820592700 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5210167u); flags=s.arithmetic_flags;
  }
  L004f8037: { // 0x4f8037: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004f803a: { // 0x4f803a: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004f803c: { // 0x4f803c: 7424 JZ 0x004f8062
    if(integer::condition("JZ",flags)) goto L004f8062;
  }
  L004f803e: { // 0x4f803e: 8d56ff LEA EDX,[ESI + -0x1]
    s.dx = (s.si-0x00000001u);
  }
  L004f8041: { // 0x4f8041: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004f8043: { // 0x4f8043: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L004f8045: { // 0x4f8045: 7c1d JL 0x004f8064
    if(integer::condition("JL",flags)) goto L004f8064;
  }
  L004f8047: { // 0x4f8047: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L004f8048: { // 0x4f8048: 8919 MOV dword ptr [ECX],EBX
    m.w32((s.cx), s.bx);
  }
  L004f804a: { // 0x4f804a: 895904 MOV dword ptr [ECX + 0x4],EBX
    m.w32((s.cx+0x00000004u), s.bx);
  }
  L004f804d: { // 0x4f804d: 83c108 ADD ECX,0x8
    s.cx = integer::add(s.cx,0x00000008u,32,flags);
  }
  L004f8050: { // 0x4f8050: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L004f8051: { // 0x4f8051: 75f5 JNZ 0x004f8048
    if(integer::condition("JNZ",flags)) goto L004f8048;
  }
  L004f8053: { // 0x4f8053: 894704 MOV dword ptr [EDI + 0x4],EAX
    m.w32((s.di+0x00000004u), s.ax);
  }
  L004f8056: { // 0x4f8056: c6470d01 MOV byte ptr [EDI + 0xd],0x1
    m.w8((s.di+0x0000000du), 0x00000001u);
  }
  L004f805a: { // 0x4f805a: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004f805c: { // 0x4f805c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f805d: { // 0x4f805d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f805e: { // 0x4f805e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f805f: { // 0x4f805f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004f8062: { // 0x4f8062: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f8064: { // 0x4f8064: 894704 MOV dword ptr [EDI + 0x4],EAX
    m.w32((s.di+0x00000004u), s.ax);
  }
  L004f8067: { // 0x4f8067: c6470d01 MOV byte ptr [EDI + 0xd],0x1
    m.w8((s.di+0x0000000du), 0x00000001u);
  }
  L004f806b: { // 0x4f806b: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004f806d: { // 0x4f806d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f806e: { // 0x4f806e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f806f: { // 0x4f806f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f8070: { // 0x4f8070: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000f8080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f8080: { // 0x4f8080: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004f8081: { // 0x4f8081: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f8082: { // 0x4f8082: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  L004f8086: { // 0x4f8086: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f8087: { // 0x4f8087: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L004f8089: { // 0x4f8089: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004f808b: { // 0x4f808b: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L004f808d: { // 0x4f808d: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L004f8090: { // 0x4f8090: 897708 MOV dword ptr [EDI + 0x8],ESI
    m.w32((s.di+0x00000008u), s.si);
  }
  L004f8093: { // 0x4f8093: c6470c01 MOV byte ptr [EDI + 0xc],0x1
    m.w8((s.di+0x0000000cu), 0x00000001u);
  }
  L004f8097: { // 0x4f8097: 885f0d MOV byte ptr [EDI + 0xd],BL
    m.w8((s.di+0x0000000du), (s.bx & 0xffu));
  }
  L004f809a: { // 0x4f809a: c707a4de7800 MOV dword ptr [EDI],0x78dea4
    m.w32((s.di), 0x0078dea4u);
  }
  L004f80a0: { // 0x4f80a0: 7469 JZ 0x004f810b
    if(integer::condition("JZ",flags)) goto L004f810b;
  }
  L004f80a2: { // 0x4f80a2: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L004f80a6: { // 0x4f80a6: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L004f80a8: { // 0x4f80a8: 7420 JZ 0x004f80ca
    if(integer::condition("JZ",flags)) goto L004f80ca;
  }
  L004f80aa: { // 0x4f80aa: 8d4eff LEA ECX,[ESI + -0x1]
    s.cx = (s.si-0x00000001u);
  }
  L004f80ad: { // 0x4f80ad: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L004f80af: { // 0x4f80af: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L004f80b1: { // 0x4f80b1: 7c0c JL 0x004f80bf
    if(integer::condition("JL",flags)) goto L004f80bf;
  }
  L004f80b3: { // 0x4f80b3: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L004f80b4: { // 0x4f80b4: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L004f80b6: { // 0x4f80b6: 885804 MOV byte ptr [EAX + 0x4],BL
    m.w8((s.ax+0x00000004u), (s.bx & 0xffu));
  }
  L004f80b9: { // 0x4f80b9: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L004f80bc: { // 0x4f80bc: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004f80bd: { // 0x4f80bd: 75f5 JNZ 0x004f80b4
    if(integer::condition("JNZ",flags)) goto L004f80b4;
  }
  L004f80bf: { // 0x4f80bf: 895704 MOV dword ptr [EDI + 0x4],EDX
    m.w32((s.di+0x00000004u), s.dx);
  }
  L004f80c2: { // 0x4f80c2: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004f80c4: { // 0x4f80c4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f80c5: { // 0x4f80c5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f80c6: { // 0x4f80c6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f80c7: { // 0x4f80c7: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004f80ca: { // 0x4f80ca: 8d04f500000000 LEA EAX,[ESI*0x8 + 0x0]
    s.ax = ((s.si * 0x00000008u)+0x00000000u);
  }
  L004f80d1: { // 0x4f80d1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004f80d2: { // 0x4f80d2: e880582700 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5210327u); flags=s.arithmetic_flags;
  }
  L004f80d7: { // 0x4f80d7: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004f80da: { // 0x4f80da: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004f80dc: { // 0x4f80dc: 7424 JZ 0x004f8102
    if(integer::condition("JZ",flags)) goto L004f8102;
  }
  L004f80de: { // 0x4f80de: 8d56ff LEA EDX,[ESI + -0x1]
    s.dx = (s.si-0x00000001u);
  }
  L004f80e1: { // 0x4f80e1: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004f80e3: { // 0x4f80e3: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L004f80e5: { // 0x4f80e5: 7c1d JL 0x004f8104
    if(integer::condition("JL",flags)) goto L004f8104;
  }
  L004f80e7: { // 0x4f80e7: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L004f80e8: { // 0x4f80e8: 8919 MOV dword ptr [ECX],EBX
    m.w32((s.cx), s.bx);
  }
  L004f80ea: { // 0x4f80ea: 885904 MOV byte ptr [ECX + 0x4],BL
    m.w8((s.cx+0x00000004u), (s.bx & 0xffu));
  }
  L004f80ed: { // 0x4f80ed: 83c108 ADD ECX,0x8
    s.cx = integer::add(s.cx,0x00000008u,32,flags);
  }
  L004f80f0: { // 0x4f80f0: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L004f80f1: { // 0x4f80f1: 75f5 JNZ 0x004f80e8
    if(integer::condition("JNZ",flags)) goto L004f80e8;
  }
  L004f80f3: { // 0x4f80f3: 894704 MOV dword ptr [EDI + 0x4],EAX
    m.w32((s.di+0x00000004u), s.ax);
  }
  L004f80f6: { // 0x4f80f6: c6470d01 MOV byte ptr [EDI + 0xd],0x1
    m.w8((s.di+0x0000000du), 0x00000001u);
  }
  L004f80fa: { // 0x4f80fa: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004f80fc: { // 0x4f80fc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f80fd: { // 0x4f80fd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f80fe: { // 0x4f80fe: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f80ff: { // 0x4f80ff: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004f8102: { // 0x4f8102: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f8104: { // 0x4f8104: 894704 MOV dword ptr [EDI + 0x4],EAX
    m.w32((s.di+0x00000004u), s.ax);
  }
  L004f8107: { // 0x4f8107: c6470d01 MOV byte ptr [EDI + 0xd],0x1
    m.w8((s.di+0x0000000du), 0x00000001u);
  }
  L004f810b: { // 0x4f810b: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004f810d: { // 0x4f810d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f810e: { // 0x4f810e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f810f: { // 0x4f810f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004f8110: { // 0x4f8110: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000a6620(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004a6620: { // 0x4a6620: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004a6622: { // 0x4a6622: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L004a6628: { // 0x4a6628: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L004a662a: { // 0x4a662a: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004a662c: { // 0x4a662c: c74008ffffff7f MOV dword ptr [EAX + 0x8],0x7fffffff
    m.w32((s.ax+0x00000008u), 0x7fffffffu);
  }
  L004a6633: { // 0x4a6633: 88480c MOV byte ptr [EAX + 0xc],CL
    m.w8((s.ax+0x0000000cu), (s.cx & 0xffu));
  }
  L004a6636: { // 0x4a6636: 894810 MOV dword ptr [EAX + 0x10],ECX
    m.w32((s.ax+0x00000010u), s.cx);
  }
  L004a6639: { // 0x4a6639: 894828 MOV dword ptr [EAX + 0x28],ECX
    m.w32((s.ax+0x00000028u), s.cx);
  }
  L004a663c: { // 0x4a663c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0002ca50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042ca50: { // 0x42ca50: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042ca51: { // 0x42ca51: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0042ca53: { // 0x42ca53: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042ca54: { // 0x42ca54: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042ca56: { // 0x42ca56: 8d7e04 LEA EDI,[ESI + 0x4]
    s.di = (s.si+0x00000004u);
  }
  L0042ca59: { // 0x42ca59: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042ca5b: { // 0x42ca5b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0042ca5d: { // 0x42ca5d: e8ce090000 CALL 0x0042d430
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042d430u,4377186u); flags=s.arithmetic_flags;
  }
  L0042ca62: { // 0x42ca62: c707c0757800 MOV dword ptr [EDI],0x7875c0
    m.w32((s.di), 0x007875c0u);
  }
  L0042ca68: { // 0x42ca68: c747140a000000 MOV dword ptr [EDI + 0x14],0xa
    m.w32((s.di+0x00000014u), 0x0000000au);
  }
  L0042ca6f: { // 0x42ca6f: c7471000000000 MOV dword ptr [EDI + 0x10],0x0
    m.w32((s.di+0x00000010u), 0x00000000u);
  }
  L0042ca76: { // 0x42ca76: 8d7e20 LEA EDI,[ESI + 0x20]
    s.di = (s.si+0x00000020u);
  }
  L0042ca79: { // 0x42ca79: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042ca7b: { // 0x42ca7b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042ca7d: { // 0x42ca7d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0042ca7f: { // 0x42ca7f: e81c0a0000 CALL 0x0042d4a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042d4a0u,4377220u); flags=s.arithmetic_flags;
  }
  L0042ca84: { // 0x42ca84: c707a0757800 MOV dword ptr [EDI],0x7875a0
    m.w32((s.di), 0x007875a0u);
  }
  L0042ca8a: { // 0x42ca8a: c747140a000000 MOV dword ptr [EDI + 0x14],0xa
    m.w32((s.di+0x00000014u), 0x0000000au);
  }
  L0042ca91: { // 0x42ca91: c7471000000000 MOV dword ptr [EDI + 0x10],0x0
    m.w32((s.di+0x00000010u), 0x00000000u);
  }
  L0042ca98: { // 0x42ca98: 8d7e38 LEA EDI,[ESI + 0x38]
    s.di = (s.si+0x00000038u);
  }
  L0042ca9b: { // 0x42ca9b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042ca9d: { // 0x42ca9d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0042ca9f: { // 0x42ca9f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0042caa1: { // 0x42caa1: e8fa090000 CALL 0x0042d4a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042d4a0u,4377254u); flags=s.arithmetic_flags;
  }
  L0042caa6: { // 0x42caa6: c707a0757800 MOV dword ptr [EDI],0x7875a0
    m.w32((s.di), 0x007875a0u);
  }
  L0042caac: { // 0x42caac: c747140a000000 MOV dword ptr [EDI + 0x14],0xa
    m.w32((s.di+0x00000014u), 0x0000000au);
  }
  L0042cab3: { // 0x42cab3: c7471000000000 MOV dword ptr [EDI + 0x10],0x0
    m.w32((s.di+0x00000010u), 0x00000000u);
  }
  L0042caba: { // 0x42caba: c70690757800 MOV dword ptr [ESI],0x787590
    m.w32((s.si), 0x00787590u);
  }
  L0042cac0: { // 0x42cac0: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042cac2: { // 0x42cac2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042cac3: { // 0x42cac3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042cac4: { // 0x42cac4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0002d430(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042d430: { // 0x42d430: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042d431: { // 0x42d431: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042d432: { // 0x42d432: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L0042d436: { // 0x42d436: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0042d438: { // 0x42d438: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0042d43a: { // 0x42d43a: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L0042d441: { // 0x42d441: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L0042d444: { // 0x42d444: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L0042d448: { // 0x42d448: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L0042d44c: { // 0x42d44c: c70600767800 MOV dword ptr [ESI],0x787600
    m.w32((s.si), 0x00787600u);
  }
  L0042d452: { // 0x42d452: 7445 JZ 0x0042d499
    if(integer::condition("JZ",flags)) goto L0042d499;
  }
  L0042d454: { // 0x42d454: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0042d458: { // 0x42d458: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042d45a: { // 0x42d45a: 740f JZ 0x0042d46b
    if(integer::condition("JZ",flags)) goto L0042d46b;
  }
  L0042d45c: { // 0x42d45c: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0042d45d: { // 0x42d45d: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0042d460: { // 0x42d460: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L0042d464: { // 0x42d464: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042d466: { // 0x42d466: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042d467: { // 0x42d467: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042d468: { // 0x42d468: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0042d46b: { // 0x42d46b: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0042d46d: { // 0x42d46d: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0042d470: { // 0x42d470: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042d471: { // 0x42d471: e8e1043400 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4379766u); flags=s.arithmetic_flags;
  }
  L0042d476: { // 0x42d476: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0042d479: { // 0x42d479: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042d47b: { // 0x42d47b: 7413 JZ 0x0042d490
    if(integer::condition("JZ",flags)) goto L0042d490;
  }
  L0042d47d: { // 0x42d47d: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0042d47e: { // 0x42d47e: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0042d481: { // 0x42d481: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L0042d485: { // 0x42d485: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L0042d489: { // 0x42d489: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042d48b: { // 0x42d48b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042d48c: { // 0x42d48c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042d48d: { // 0x42d48d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0042d490: { // 0x42d490: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0042d492: { // 0x42d492: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L0042d496: { // 0x42d496: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0042d499: { // 0x42d499: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042d49b: { // 0x42d49b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042d49c: { // 0x42d49c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042d49d: { // 0x42d49d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0002d4a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042d4a0: { // 0x42d4a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042d4a1: { // 0x42d4a1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042d4a2: { // 0x42d4a2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L0042d4a6: { // 0x42d4a6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0042d4a8: { // 0x42d4a8: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0042d4aa: { // 0x42d4aa: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L0042d4b1: { // 0x42d4b1: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L0042d4b4: { // 0x42d4b4: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L0042d4b8: { // 0x42d4b8: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L0042d4bc: { // 0x42d4bc: c706e0757800 MOV dword ptr [ESI],0x7875e0
    m.w32((s.si), 0x007875e0u);
  }
  L0042d4c2: { // 0x42d4c2: 7447 JZ 0x0042d50b
    if(integer::condition("JZ",flags)) goto L0042d50b;
  }
  L0042d4c4: { // 0x42d4c4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0042d4c8: { // 0x42d4c8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042d4ca: { // 0x42d4ca: 740f JZ 0x0042d4db
    if(integer::condition("JZ",flags)) goto L0042d4db;
  }
  L0042d4cc: { // 0x42d4cc: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0042d4cd: { // 0x42d4cd: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0042d4d0: { // 0x42d4d0: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L0042d4d4: { // 0x42d4d4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042d4d6: { // 0x42d4d6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042d4d7: { // 0x42d4d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042d4d8: { // 0x42d4d8: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0042d4db: { // 0x42d4db: 8d04bd00000000 LEA EAX,[EDI*0x4 + 0x0]
    s.ax = ((s.di * 0x00000004u)+0x00000000u);
  }
  L0042d4e2: { // 0x42d4e2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042d4e3: { // 0x42d4e3: e86f043400 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4379880u); flags=s.arithmetic_flags;
  }
  L0042d4e8: { // 0x42d4e8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0042d4eb: { // 0x42d4eb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042d4ed: { // 0x42d4ed: 7413 JZ 0x0042d502
    if(integer::condition("JZ",flags)) goto L0042d502;
  }
  L0042d4ef: { // 0x42d4ef: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0042d4f0: { // 0x42d4f0: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0042d4f3: { // 0x42d4f3: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L0042d4f7: { // 0x42d4f7: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L0042d4fb: { // 0x42d4fb: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042d4fd: { // 0x42d4fd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042d4fe: { // 0x42d4fe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042d4ff: { // 0x42d4ff: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0042d502: { // 0x42d502: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0042d504: { // 0x42d504: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L0042d508: { // 0x42d508: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0042d50b: { // 0x42d50b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042d50d: { // 0x42d50d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042d50e: { // 0x42d50e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042d50f: { // 0x42d50f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4259680u:f_0000ff60(m,s,child,{});break;
case 5209920u:f_000f7f40(m,s,child,{});break;
case 5210000u:f_000f7f90(m,s,child,{});break;
case 5209680u:f_000f7e50(m,s,child,{});break;
case 4790752u:f_000919e0(m,s,child,{});break;
case 5210080u:f_000f7fe0(m,s,child,{});break;
case 5210240u:f_000f8080(m,s,child,{});break;
case 4875808u:f_000a6620(m,s,child,{});break;
case 4377168u:f_0002ca50(m,s,child,{});break;
case 4379696u:f_0002d430(m,s,child,{});break;
case 4379808u:f_0002d4a0(m,s,child,{});break;
default:throw std::domain_error("recovery619 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004e0d10(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e0d10: { // 0x4e0d10: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004e0d11: { // 0x4e0d11: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L004e0d15: { // 0x4e0d15: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0d16: { // 0x4e0d16: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004e0d17: { // 0x4e0d17: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e0d18: { // 0x4e0d18: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e0d19: { // 0x4e0d19: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004e0d1b: { // 0x4e0d1b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e0d1c: { // 0x4e0d1c: e83ff2f2ff CALL 0x0040ff60
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ff60u,5115169u); flags=s.arithmetic_flags;
  }
  L004e0d21: { // 0x4e0d21: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004e0d23: { // 0x4e0d23: 8d7e38 LEA EDI,[ESI + 0x38]
    s.di = (s.si+0x00000038u);
  }
  L004e0d26: { // 0x4e0d26: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0d27: { // 0x4e0d27: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0d28: { // 0x4e0d28: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004e0d2a: { // 0x4e0d2a: e811720100 CALL 0x004f7f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f7f40u,5115183u); flags=s.arithmetic_flags;
  }
  L004e0d2f: { // 0x4e0d2f: bd0a000000 MOV EBP,0xa
    s.bp = 0x0000000au;
  }
  L004e0d34: { // 0x4e0d34: c707e4da7800 MOV dword ptr [EDI],0x78dae4
    m.w32((s.di), 0x0078dae4u);
  }
  L004e0d3a: { // 0x4e0d3a: 896f14 MOV dword ptr [EDI + 0x14],EBP
    m.w32((s.di+0x00000014u), s.bp);
  }
  L004e0d3d: { // 0x4e0d3d: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L004e0d40: { // 0x4e0d40: 8d7e50 LEA EDI,[ESI + 0x50]
    s.di = (s.si+0x00000050u);
  }
  L004e0d43: { // 0x4e0d43: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0d44: { // 0x4e0d44: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0d45: { // 0x4e0d45: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004e0d47: { // 0x4e0d47: e844720100 CALL 0x004f7f90
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f7f90u,5115212u); flags=s.arithmetic_flags;
  }
  L004e0d4c: { // 0x4e0d4c: c70764d37800 MOV dword ptr [EDI],0x78d364
    m.w32((s.di), 0x0078d364u);
  }
  L004e0d52: { // 0x4e0d52: 896f14 MOV dword ptr [EDI + 0x14],EBP
    m.w32((s.di+0x00000014u), s.bp);
  }
  L004e0d55: { // 0x4e0d55: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L004e0d58: { // 0x4e0d58: 8d7e68 LEA EDI,[ESI + 0x68]
    s.di = (s.si+0x00000068u);
  }
  L004e0d5b: { // 0x4e0d5b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0d5c: { // 0x4e0d5c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0d5d: { // 0x4e0d5d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004e0d5f: { // 0x4e0d5f: e82c720100 CALL 0x004f7f90
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f7f90u,5115236u); flags=s.arithmetic_flags;
  }
  L004e0d64: { // 0x4e0d64: c70764d37800 MOV dword ptr [EDI],0x78d364
    m.w32((s.di), 0x0078d364u);
  }
  L004e0d6a: { // 0x4e0d6a: 896f14 MOV dword ptr [EDI + 0x14],EBP
    m.w32((s.di+0x00000014u), s.bp);
  }
  L004e0d6d: { // 0x4e0d6d: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L004e0d70: { // 0x4e0d70: 8dbe80000000 LEA EDI,[ESI + 0x80]
    s.di = (s.si+0x00000080u);
  }
  L004e0d76: { // 0x4e0d76: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0d77: { // 0x4e0d77: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0d78: { // 0x4e0d78: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004e0d7a: { // 0x4e0d7a: e811720100 CALL 0x004f7f90
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f7f90u,5115263u); flags=s.arithmetic_flags;
  }
  L004e0d7f: { // 0x4e0d7f: c70764d37800 MOV dword ptr [EDI],0x78d364
    m.w32((s.di), 0x0078d364u);
  }
  L004e0d85: { // 0x4e0d85: 896f14 MOV dword ptr [EDI + 0x14],EBP
    m.w32((s.di+0x00000014u), s.bp);
  }
  L004e0d88: { // 0x4e0d88: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L004e0d8b: { // 0x4e0d8b: 8dbe98000000 LEA EDI,[ESI + 0x98]
    s.di = (s.si+0x00000098u);
  }
  L004e0d91: { // 0x4e0d91: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0d92: { // 0x4e0d92: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0d93: { // 0x4e0d93: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004e0d95: { // 0x4e0d95: e8f6710100 CALL 0x004f7f90
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f7f90u,5115290u); flags=s.arithmetic_flags;
  }
  L004e0d9a: { // 0x4e0d9a: c70764d37800 MOV dword ptr [EDI],0x78d364
    m.w32((s.di), 0x0078d364u);
  }
  L004e0da0: { // 0x4e0da0: 896f14 MOV dword ptr [EDI + 0x14],EBP
    m.w32((s.di+0x00000014u), s.bp);
  }
  L004e0da3: { // 0x4e0da3: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L004e0da6: { // 0x4e0da6: 8dbeb0000000 LEA EDI,[ESI + 0xb0]
    s.di = (s.si+0x000000b0u);
  }
  L004e0dac: { // 0x4e0dac: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0dad: { // 0x4e0dad: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0dae: { // 0x4e0dae: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004e0db0: { // 0x4e0db0: e8db710100 CALL 0x004f7f90
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f7f90u,5115317u); flags=s.arithmetic_flags;
  }
  L004e0db5: { // 0x4e0db5: c70764d37800 MOV dword ptr [EDI],0x78d364
    m.w32((s.di), 0x0078d364u);
  }
  L004e0dbb: { // 0x4e0dbb: 896f14 MOV dword ptr [EDI + 0x14],EBP
    m.w32((s.di+0x00000014u), s.bp);
  }
  L004e0dbe: { // 0x4e0dbe: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L004e0dc1: { // 0x4e0dc1: 8dbe9c010000 LEA EDI,[ESI + 0x19c]
    s.di = (s.si+0x0000019cu);
  }
  L004e0dc7: { // 0x4e0dc7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0dc8: { // 0x4e0dc8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0dc9: { // 0x4e0dc9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004e0dcb: { // 0x4e0dcb: e880700100 CALL 0x004f7e50
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f7e50u,5115344u); flags=s.arithmetic_flags;
  }
  L004e0dd0: { // 0x4e0dd0: c70724da7800 MOV dword ptr [EDI],0x78da24
    m.w32((s.di), 0x0078da24u);
  }
  L004e0dd6: { // 0x4e0dd6: 896f14 MOV dword ptr [EDI + 0x14],EBP
    m.w32((s.di+0x00000014u), s.bp);
  }
  L004e0dd9: { // 0x4e0dd9: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L004e0ddc: { // 0x4e0ddc: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L004e0de2: { // 0x4e0de2: 898ec8010000 MOV dword ptr [ESI + 0x1c8],ECX
    m.w32((s.si+0x000001c8u), s.cx);
  }
  L004e0de8: { // 0x4e0de8: 8d8e20540000 LEA ECX,[ESI + 0x5420]
    s.cx = (s.si+0x00005420u);
  }
  L004e0dee: { // 0x4e0dee: 899ed0010000 MOV dword ptr [ESI + 0x1d0],EBX
    m.w32((s.si+0x000001d0u), s.bx);
  }
  L004e0df4: { // 0x4e0df4: e8e70bfbff CALL 0x004919e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004919e0u,5115385u); flags=s.arithmetic_flags;
  }
  L004e0df9: { // 0x4e0df9: 8d8e30540000 LEA ECX,[ESI + 0x5430]
    s.cx = (s.si+0x00005430u);
  }
  L004e0dff: { // 0x4e0dff: e8dc0bfbff CALL 0x004919e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004919e0u,5115396u); flags=s.arithmetic_flags;
  }
  L004e0e04: { // 0x4e0e04: 8d8e40540000 LEA ECX,[ESI + 0x5440]
    s.cx = (s.si+0x00005440u);
  }
  L004e0e0a: { // 0x4e0e0a: e8d10bfbff CALL 0x004919e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004919e0u,5115407u); flags=s.arithmetic_flags;
  }
  L004e0e0f: { // 0x4e0e0f: 8d8e50540000 LEA ECX,[ESI + 0x5450]
    s.cx = (s.si+0x00005450u);
  }
  L004e0e15: { // 0x4e0e15: e8c60bfbff CALL 0x004919e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004919e0u,5115418u); flags=s.arithmetic_flags;
  }
  L004e0e1a: { // 0x4e0e1a: 8d8e60540000 LEA ECX,[ESI + 0x5460]
    s.cx = (s.si+0x00005460u);
  }
  L004e0e20: { // 0x4e0e20: e8bb0bfbff CALL 0x004919e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004919e0u,5115429u); flags=s.arithmetic_flags;
  }
  L004e0e25: { // 0x4e0e25: 8d8e70540000 LEA ECX,[ESI + 0x5470]
    s.cx = (s.si+0x00005470u);
  }
  L004e0e2b: { // 0x4e0e2b: e8b00bfbff CALL 0x004919e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004919e0u,5115440u); flags=s.arithmetic_flags;
  }
  L004e0e30: { // 0x4e0e30: 8d8e80540000 LEA ECX,[ESI + 0x5480]
    s.cx = (s.si+0x00005480u);
  }
  L004e0e36: { // 0x4e0e36: e8a50bfbff CALL 0x004919e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004919e0u,5115451u); flags=s.arithmetic_flags;
  }
  L004e0e3b: { // 0x4e0e3b: 8d8e90540000 LEA ECX,[ESI + 0x5490]
    s.cx = (s.si+0x00005490u);
  }
  L004e0e41: { // 0x4e0e41: e89a0bfbff CALL 0x004919e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004919e0u,5115462u); flags=s.arithmetic_flags;
  }
  L004e0e46: { // 0x4e0e46: 8d8ea0540000 LEA ECX,[ESI + 0x54a0]
    s.cx = (s.si+0x000054a0u);
  }
  L004e0e4c: { // 0x4e0e4c: e88f0bfbff CALL 0x004919e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004919e0u,5115473u); flags=s.arithmetic_flags;
  }
  L004e0e51: { // 0x4e0e51: 8d8eb0540000 LEA ECX,[ESI + 0x54b0]
    s.cx = (s.si+0x000054b0u);
  }
  L004e0e57: { // 0x4e0e57: e8840bfbff CALL 0x004919e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004919e0u,5115484u); flags=s.arithmetic_flags;
  }
  L004e0e5c: { // 0x4e0e5c: 8d8ec0540000 LEA ECX,[ESI + 0x54c0]
    s.cx = (s.si+0x000054c0u);
  }
  L004e0e62: { // 0x4e0e62: e8790bfbff CALL 0x004919e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004919e0u,5115495u); flags=s.arithmetic_flags;
  }
  L004e0e67: { // 0x4e0e67: 8d8ed0540000 LEA ECX,[ESI + 0x54d0]
    s.cx = (s.si+0x000054d0u);
  }
  L004e0e6d: { // 0x4e0e6d: e86e0bfbff CALL 0x004919e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004919e0u,5115506u); flags=s.arithmetic_flags;
  }
  L004e0e72: { // 0x4e0e72: 8dbef4540000 LEA EDI,[ESI + 0x54f4]
    s.di = (s.si+0x000054f4u);
  }
  L004e0e78: { // 0x4e0e78: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0e79: { // 0x4e0e79: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0e7a: { // 0x4e0e7a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004e0e7c: { // 0x4e0e7c: e85f710100 CALL 0x004f7fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f7fe0u,5115521u); flags=s.arithmetic_flags;
  }
  L004e0e81: { // 0x4e0e81: c70764de7800 MOV dword ptr [EDI],0x78de64
    m.w32((s.di), 0x0078de64u);
  }
  L004e0e87: { // 0x4e0e87: 896f14 MOV dword ptr [EDI + 0x14],EBP
    m.w32((s.di+0x00000014u), s.bp);
  }
  L004e0e8a: { // 0x4e0e8a: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L004e0e8d: { // 0x4e0e8d: 8dbe0c550000 LEA EDI,[ESI + 0x550c]
    s.di = (s.si+0x0000550cu);
  }
  L004e0e93: { // 0x4e0e93: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0e94: { // 0x4e0e94: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e0e95: { // 0x4e0e95: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004e0e97: { // 0x4e0e97: e8e4710100 CALL 0x004f8080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f8080u,5115548u); flags=s.arithmetic_flags;
  }
  L004e0e9c: { // 0x4e0e9c: c70744de7800 MOV dword ptr [EDI],0x78de44
    m.w32((s.di), 0x0078de44u);
  }
  L004e0ea2: { // 0x4e0ea2: 896f14 MOV dword ptr [EDI + 0x14],EBP
    m.w32((s.di+0x00000014u), s.bp);
  }
  L004e0ea5: { // 0x4e0ea5: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L004e0ea8: { // 0x4e0ea8: 8dbe60550000 LEA EDI,[ESI + 0x5560]
    s.di = (s.si+0x00005560u);
  }
  L004e0eae: { // 0x4e0eae: c744241003000000 MOV dword ptr [ESP + 0x10],0x3
    m.w32((f.sp+0x00000010u), 0x00000003u);
  }
  L004e0eb6: { // 0x4e0eb6: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004e0eb8: { // 0x4e0eb8: e86357fcff CALL 0x004a6620
    s.arithmetic_flags=flags; invoke(m,s,f,0x004a6620u,5115581u); flags=s.arithmetic_flags;
  }
  L004e0ebd: { // 0x4e0ebd: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004e0ec1: { // 0x4e0ec1: 83c72c ADD EDI,0x2c
    s.di = integer::add(s.di,0x0000002cu,32,flags);
  }
  L004e0ec4: { // 0x4e0ec4: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004e0ec5: { // 0x4e0ec5: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004e0ec9: { // 0x4e0ec9: 75eb JNZ 0x004e0eb6
    if(integer::condition("JNZ",flags)) goto L004e0eb6;
  }
  L004e0ecb: { // 0x4e0ecb: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L004e0ecf: { // 0x4e0ecf: 8d8ef0550000 LEA ECX,[ESI + 0x55f0]
    s.cx = (s.si+0x000055f0u);
  }
  L004e0ed5: { // 0x4e0ed5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004e0ed6: { // 0x4e0ed6: e875bbf4ff CALL 0x0042ca50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ca50u,5115611u); flags=s.arithmetic_flags;
  }
  L004e0edb: { // 0x4e0edb: 899e4c5f0100 MOV dword ptr [ESI + 0x15f4c],EBX
    m.w32((s.si+0x00015f4cu), s.bx);
  }
  L004e0ee1: { // 0x4e0ee1: 899e505f0100 MOV dword ptr [ESI + 0x15f50],EBX
    m.w32((s.si+0x00015f50u), s.bx);
  }
  L004e0ee7: { // 0x4e0ee7: c686545f010001 MOV byte ptr [ESI + 0x15f54],0x1
    m.w8((s.si+0x00015f54u), 0x00000001u);
  }
  L004e0eee: { // 0x4e0eee: 889e555f0100 MOV byte ptr [ESI + 0x15f55],BL
    m.w8((s.si+0x00015f55u), (s.bx & 0xffu));
  }
  L004e0ef4: { // 0x4e0ef4: c786485f0100a0967800 MOV dword ptr [ESI + 0x15f48],0x7896a0
    m.w32((s.si+0x00015f48u), 0x007896a0u);
  }
  L004e0efe: { // 0x4e0efe: 89ae5c5f0100 MOV dword ptr [ESI + 0x15f5c],EBP
    m.w32((s.si+0x00015f5cu), s.bp);
  }
  L004e0f04: { // 0x4e0f04: 899e585f0100 MOV dword ptr [ESI + 0x15f58],EBX
    m.w32((s.si+0x00015f58u), s.bx);
  }
  L004e0f0a: { // 0x4e0f0a: c706e0dd7800 MOV dword ptr [ESI],0x78dde0
    m.w32((s.si), 0x0078dde0u);
  }
  L004e0f10: { // 0x4e0f10: c74604c4dd7800 MOV dword ptr [ESI + 0x4],0x78ddc4
    m.w32((s.si+0x00000004u), 0x0078ddc4u);
  }
  L004e0f17: { // 0x4e0f17: c74608bcdd7800 MOV dword ptr [ESI + 0x8],0x78ddbc
    m.w32((s.si+0x00000008u), 0x0078ddbcu);
  }
  L004e0f1e: { // 0x4e0f1e: c7460cb4dd7800 MOV dword ptr [ESI + 0xc],0x78ddb4
    m.w32((s.si+0x0000000cu), 0x0078ddb4u);
  }
  L004e0f25: { // 0x4e0f25: c7462474dd7800 MOV dword ptr [ESI + 0x24],0x78dd74
    m.w32((s.si+0x00000024u), 0x0078dd74u);
  }
  L004e0f2c: { // 0x4e0f2c: c746284cdd7800 MOV dword ptr [ESI + 0x28],0x78dd4c
    m.w32((s.si+0x00000028u), 0x0078dd4cu);
  }
  L004e0f33: { // 0x4e0f33: c7462c34dd7800 MOV dword ptr [ESI + 0x2c],0x78dd34
    m.w32((s.si+0x0000002cu), 0x0078dd34u);
  }
  L004e0f3a: { // 0x4e0f3a: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004e0f3c: { // 0x4e0f3c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e0f3d: { // 0x4e0f3d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e0f3e: { // 0x4e0f3e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004e0f3f: { // 0x4e0f3f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004e0f40: { // 0x4e0f40: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004e0f41: { // 0x4e0f41: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
