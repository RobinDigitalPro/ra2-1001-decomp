#include "recovered/recovery_b543_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b543 {
namespace {
void f_0018e180(Memory&,State&,Frame&,const Operations&);
void f_00297de0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_000766c0(Memory&,State&,Frame&,const Operations&);
void f_0007b560(Memory&,State&,Frame&,const Operations&);
void f_0007b580(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0018e180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058e180: { // 0x58e180: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0058e183: { // 0x58e183: d94208 FLD float ptr [EDX + 0x8]
    const auto address=(s.dx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0058e186: { // 0x58e186: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058e187: { // 0x58e187: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0058e18b: { // 0x58e18b: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e18e: { // 0x58e18e: d94204 FLD float ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058e191: { // 0x58e191: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e194: { // 0x58e194: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0058e196: { // 0x58e196: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e198: { // 0x58e198: d902 FLD float ptr [EDX]
    const auto address=(s.dx);
    s.fp.load32(m.r32(address));
  }
  L0058e19a: { // 0x58e19a: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
  L0058e19c: { // 0x58e19c: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e19e: { // 0x58e19e: d8420c FADD float ptr [EDX + 0xc]
    const auto address=(s.dx+0x0000000cu);
    s.fp.add32(m.r32(address));
  }
  L0058e1a1: { // 0x58e1a1: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058e1a5: { // 0x58e1a5: d94210 FLD float ptr [EDX + 0x10]
    const auto address=(s.dx+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L0058e1a8: { // 0x58e1a8: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1aa: { // 0x58e1aa: d94218 FLD float ptr [EDX + 0x18]
    const auto address=(s.dx+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L0058e1ad: { // 0x58e1ad: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1b0: { // 0x58e1b0: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e1b2: { // 0x58e1b2: d94214 FLD float ptr [EDX + 0x14]
    const auto address=(s.dx+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L0058e1b5: { // 0x58e1b5: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1b8: { // 0x58e1b8: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e1ba: { // 0x58e1ba: d8421c FADD float ptr [EDX + 0x1c]
    const auto address=(s.dx+0x0000001cu);
    s.fp.add32(m.r32(address));
  }
  L0058e1bd: { // 0x58e1bd: d95c2408 FSTP float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058e1c1: { // 0x58e1c1: d94220 FLD float ptr [EDX + 0x20]
    const auto address=(s.dx+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L0058e1c4: { // 0x58e1c4: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1c6: { // 0x58e1c6: d94228 FLD float ptr [EDX + 0x28]
    const auto address=(s.dx+0x00000028u);
    s.fp.load32(m.r32(address));
  }
  L0058e1c9: { // 0x58e1c9: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1cc: { // 0x58e1cc: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e1ce: { // 0x58e1ce: d94224 FLD float ptr [EDX + 0x24]
    const auto address=(s.dx+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L0058e1d1: { // 0x58e1d1: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058e1d4: { // 0x58e1d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058e1d5: { // 0x58e1d5: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058e1d7: { // 0x58e1d7: d8422c FADD float ptr [EDX + 0x2c]
    const auto address=(s.dx+0x0000002cu);
    s.fp.add32(m.r32(address));
  }
  L0058e1da: { // 0x58e1da: 8b542400 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0058e1de: { // 0x58e1de: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0058e1e0: { // 0x58e1e0: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0058e1e4: { // 0x58e1e4: d95c2408 FSTP float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058e1e8: { // 0x58e1e8: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0058e1eb: { // 0x58e1eb: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0058e1ef: { // 0x58e1ef: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L0058e1f2: { // 0x58e1f2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0058e1f5: { // 0x58e1f5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00297de0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00697de0: { // 0x697de0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00697de3: { // 0x697de3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00697de4: { // 0x697de4: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L00697de8: { // 0x697de8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00697de9: { // 0x697de9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00697dea: { // 0x697dea: 8b33 MOV ESI,dword ptr [EBX]
    s.si = m.r32((s.bx));
  }
  L00697dec: { // 0x697dec: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L00697def: { // 0x697def: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00697df3: { // 0x697df3: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00697df7: { // 0x697df7: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00697dfa: { // 0x697dfa: 8b5b08 MOV EBX,dword ptr [EBX + 0x8]
    s.bx = m.r32((s.bx+0x00000008u));
  }
  L00697dfd: { // 0x697dfd: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L00697e05: { // 0x697e05: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00697e08: { // 0x697e08: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L00697e0b: { // 0x697e0b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00697e0c: { // 0x697e0c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00697e0e: { // 0x697e0e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00697e10: { // 0x697e10: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00697e13: { // 0x697e13: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00697e15: { // 0x697e15: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00697e18: { // 0x697e18: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L00697e1a: { // 0x697e1a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00697e1b: { // 0x697e1b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00697e1d: { // 0x697e1d: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00697e1f: { // 0x697e1f: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00697e21: { // 0x697e21: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00697e24: { // 0x697e24: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00697e26: { // 0x697e26: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00697e28: { // 0x697e28: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L00697e2b: { // 0x697e2b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00697e2c: { // 0x697e2c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00697e2e: { // 0x697e2e: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00697e30: { // 0x697e30: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00697e32: { // 0x697e32: 8d047f LEA EAX,[EDI + EDI*0x2]
    s.ax = (s.di+(s.di * 0x00000002u));
  }
  L00697e35: { // 0x697e35: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00697e37: { // 0x697e37: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00697e3a: { // 0x697e3a: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L00697e3e: { // 0x697e3e: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L00697e40: { // 0x697e40: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00697e41: { // 0x697e41: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00697e43: { // 0x697e43: 895c240c MOV dword ptr [ESP + 0xc],EBX
    m.w32((f.sp+0x0000000cu), s.bx);
  }
  L00697e47: { // 0x697e47: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00697e49: { // 0x697e49: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00697e4b: { // 0x697e4b: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00697e4d: { // 0x697e4d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00697e4e: { // 0x697e4e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00697e54: { // 0x697e54: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00697e56: { // 0x697e56: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00697e58: { // 0x697e58: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00697e5a: { // 0x697e5a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00697e5b: { // 0x697e5b: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00697e61: { // 0x697e61: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00697e63: { // 0x697e63: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00697e65: { // 0x697e65: c1ff08 SAR EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00697e68: { // 0x697e68: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00697e6b: { // 0x697e6b: 81fbd8020000 CMP EBX,0x2d8
    (void)integer::sub(s.bx,0x000002d8u,32,flags);
  }
  L00697e71: { // 0x697e71: 7c08 JL 0x00697e7b
    if(integer::condition("JL",flags)) goto L00697e7b;
  }
  L00697e73: { // 0x697e73: c744241c01000000 MOV dword ptr [ESP + 0x1c],0x1
    m.w32((f.sp+0x0000001cu), 0x00000001u);
  }
  L00697e7b: { // 0x697e7b: db44240c FILD dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load_integer32(m.r32(address));
  }
  L00697e7f: { // 0x697e7f: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
  L00697e85: { // 0x697e85: da44241c FIADD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L00697e89: { // 0x697e89: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L00697e8f: { // 0x697e8f: e8bc2b0d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6913684u); flags=s.arithmetic_flags;
  }
  L00697e94: { // 0x697e94: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L00697e96: { // 0x697e96: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00697e9a: { // 0x697e9a: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L00697e9c: { // 0x697e9c: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L00697e9f: { // 0x697e9f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00697ea0: { // 0x697ea0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00697ea1: { // 0x697ea1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00697ea2: { // 0x697ea2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00697ea5: { // 0x697ea5: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076aa50: { // 0x76aa50: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0076aa53: { // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  L0076aa56: { // 0x76aa56: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L0076aa5a: { // 0x76aa5a: 8b1424 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0076aa5d: { // 0x76aa5d: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076aa63: { // 0x76aa63: 3b15043a7c00 CMP EDX,dword ptr [0x007c3a04]
    (void)integer::sub(s.dx,m.r32((0x007c3a04u)),32,flags);
  }
  L0076aa69: { // 0x76aa69: 750b JNZ 0x0076aa76
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
  L0076aa6b: { // 0x76aa6b: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa6d: { // 0x76aa6d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0076aa70: { // 0x76aa70: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa72: { // 0x76aa72: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa75: { // 0x76aa75: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { // 0x76aa76: 8b15043a7c00 MOV EDX,dword ptr [0x007c3a04]
    s.dx = m.r32((0x007c3a04u));
  }
  L0076aa7c: { // 0x76aa7c: 891424 MOV dword ptr [ESP],EDX
    m.w32((f.sp), s.dx);
  }
  L0076aa7f: { // 0x76aa7f: d92c24 FLDCW word ptr [ESP]
    const auto address=(f.sp);
    s.fp.load_control(m.r16(address));
  }
  L0076aa82: { // 0x76aa82: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa84: { // 0x76aa84: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0076aa87: { // 0x76aa87: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa89: { // 0x76aa89: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa8c: { // 0x76aa8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI,word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x00545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x00545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x00545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX,dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000766c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004766c0: { // 0x004766c0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004766c1: { // 0x004766c1: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L004766c5: { // 0x004766c5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004766c7: { // 0x004766c7: 83fa08 CMP EDX,0x8
    (void)integer::sub(s.dx,0x00000008u,32,flags);
  }
  L004766ca: { // 0x004766ca: 7346 JNC 0x00476712
    if(integer::condition("JNC",flags)) goto L00476712;
  }
  L004766cc: { // 0x004766cc: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L004766cf: { // 0x004766cf: 83e207 AND EDX,0x7
    s.dx = integer::logical((s.dx)&(0x00000007u),32,flags);
  }
  L004766d2: { // 0x004766d2: 894c2400 MOV dword ptr [ESP],ECX
    m.w32((f.sp), s.cx);
  }
  L004766d6: { // 0x004766d6: 8d0495a09d8300 LEA EAX,[EDX*0x4 + 0x839da0]
    s.ax = ((s.dx * 0x00000004u)+0x00839da0u);
  }
  L004766dd: { // 0x004766dd: 668b1495a09d8300 MOV DX,word ptr [EDX*0x4 + 0x839da0]
    s.dx = with_ax(s.dx, m.r16(((s.dx * 0x00000004u)+0x00839da0u)));
  }
  L004766e5: { // 0x004766e5: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  L004766e9: { // 0x004766e9: 6603442402 ADD AX,word ptr [ESP + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000002u)),16,flags));
  }
  L004766ee: { // 0x004766ee: 6603d1 ADD DX,CX
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.cx & 0xffffu),16,flags));
  }
  L004766f1: { // 0x004766f1: 6689542408 MOV word ptr [ESP + 0x8],DX
    m.w16((f.sp+0x00000008u), (s.dx & 0xffffu));
  }
  L004766f6: { // 0x004766f6: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  L004766fa: { // 0x004766fa: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  L004766ff: { // 0x004766ff: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00476703: { // 0x00476703: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L00476707: { // 0x00476707: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00476708: { // 0x00476708: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0047670d: { // 0x0047670d: e8eeed0c00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4679442u); flags=s.arithmetic_flags;
  }
  L00476712: { // 0x00476712: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00476713: { // 0x00476713: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0007b560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b560: { // 0x47b560: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b563: { // 0x47b563: 8b0db0a8a300 MOV ECX,dword ptr [0x00a3a8b0]
    s.cx = m.r32((0x00a3a8b0u));
  }
  L0047b569: { // 0x47b569: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b56b: { // 0x47b56b: 7c0a JL 0x0047b577
    if(integer::condition("JL",flags)) goto L0047b577;
  }
  L0047b56d: { // 0x47b56d: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L0047b570: { // 0x47b570: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b572: { // 0x47b572: 7d03 JGE 0x0047b577
    if(integer::condition("JGE",flags)) goto L0047b577;
  }
  L0047b574: { // 0x47b574: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b576: { // 0x47b576: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b577: { // 0x47b577: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b579: { // 0x47b579: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007b580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b580: { // 0x47b580: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b583: { // 0x47b583: 8b0da047a500 MOV ECX,dword ptr [0x00a547a0]
    s.cx = m.r32((0x00a547a0u));
  }
  L0047b589: { // 0x47b589: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b58b: { // 0x47b58b: 7c0a JL 0x0047b597
    if(integer::condition("JL",flags)) goto L0047b597;
  }
  L0047b58d: { // 0x47b58d: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L0047b590: { // 0x47b590: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047b592: { // 0x47b592: 7d03 JGE 0x0047b597
    if(integer::condition("JGE",flags)) goto L0047b597;
  }
  L0047b594: { // 0x47b594: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b596: { // 0x47b596: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b597: { // 0x47b597: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b599: { // 0x47b599: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5824896u:f_0018e180(m,s,child,{});break;
case 6913504u:f_00297de0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4679360u:f_000766c0(m,s,child,{});break;
case 4699488u:f_0007b560(m,s,child,{});break;
case 4699520u:f_0007b580(m,s,child,{});break;
default:throw std::domain_error("recovery543 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0069c210(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069c210: { // 0x69c210: 83ec6c SUB ESP,0x6c
    f.sp = integer::sub(f.sp,0x0000006cu,32,flags);
  }
  L0069c213: { // 0x69c213: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069c214: { // 0x69c214: 8b5c2478 MOV EBX,dword ptr [ESP + 0x78]
    s.bx = m.r32((f.sp+0x00000078u));
  }
  L0069c218: { // 0x69c218: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069c219: { // 0x69c219: 8b1570198200 MOV EDX,dword ptr [0x00821970]
    s.dx = m.r32((0x00821970u));
  }
  L0069c21f: { // 0x69c21f: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0069c221: { // 0x69c221: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069c222: { // 0x69c222: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069c223: { // 0x69c223: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0069c225: { // 0x69c225: 8b3574198200 MOV ESI,dword ptr [0x00821974]
    s.si = m.r32((0x00821974u));
  }
  L0069c22b: { // 0x69c22b: c744245400000000 MOV dword ptr [ESP + 0x54],0x0
    m.w32((f.sp+0x00000054u), 0x00000000u);
  }
  L0069c233: { // 0x69c233: 8bafb0000000 MOV EBP,dword ptr [EDI + 0xb0]
    s.bp = m.r32((s.di+0x000000b0u));
  }
  L0069c239: { // 0x69c239: 8b8fb4000000 MOV ECX,dword ptr [EDI + 0xb4]
    s.cx = m.r32((s.di+0x000000b4u));
  }
  L0069c23f: { // 0x69c23f: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L0069c241: { // 0x69c241: 8b6b04 MOV EBP,dword ptr [EBX + 0x4]
    s.bp = m.r32((s.bx+0x00000004u));
  }
  L0069c244: { // 0x69c244: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c246: { // 0x69c246: 03cd ADD ECX,EBP
    s.cx = integer::add(s.cx,s.bp,32,flags);
  }
  L0069c248: { // 0x69c248: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L0069c24c: { // 0x69c24c: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L0069c24e: { // 0x69c24e: db44243c FILD dword ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0069c252: { // 0x69c252: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L0069c256: { // 0x69c256: 8d44244c LEA EAX,[ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L0069c25a: { // 0x69c25a: 8d97e40d0000 LEA EDX,[EDI + 0xde4]
    s.dx = (s.di+0x00000de4u);
  }
  L0069c260: { // 0x69c260: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069c261: { // 0x69c261: d95c2450 FSTP float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0069c265: { // 0x69c265: db442444 FILD dword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.load_integer32(m.r32(address));
  }
  L0069c269: { // 0x69c269: 8d4c2468 LEA ECX,[ESP + 0x68]
    s.cx = (f.sp+0x00000068u);
  }
  L0069c26d: { // 0x69c26d: d95c2454 FSTP float ptr [ESP + 0x54]
    const auto address=(f.sp+0x00000054u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0069c271: { // 0x69c271: e80a1fefff CALL 0x0058e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e180u,6931062u); flags=s.arithmetic_flags;
  }
  L0069c276: { // 0x69c276: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0069c278: { // 0x69c278: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L0069c27c: { // 0x69c27c: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0069c27f: { // 0x69c27f: d944244c FLD float ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    s.fp.load32(m.r32(address));
  }
  L0069c283: { // 0x69c283: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0069c287: { // 0x69c287: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0069c28a: { // 0x69c28a: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L0069c28e: { // 0x69c28e: e8bde70c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6931091u); flags=s.arithmetic_flags;
  }
  L0069c293: { // 0x69c293: d9442450 FLD float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.load32(m.r32(address));
  }
  L0069c297: { // 0x69c297: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0069c299: { // 0x69c299: e8b2e70c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6931102u); flags=s.arithmetic_flags;
  }
  L0069c29e: { // 0x69c29e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069c2a0: { // 0x69c2a0: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0069c2a2: { // 0x69c2a2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c2a3: { // 0x69c2a3: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c2a9: { // 0x69c2a9: 81e6ff000000 AND ESI,0xff
    s.si = integer::logical((s.si)&(0x000000ffu),32,flags);
  }
  L0069c2af: { // 0x69c2af: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c2b1: { // 0x69c2b1: 89742458 MOV dword ptr [ESP + 0x58],ESI
    m.w32((f.sp+0x00000058u), s.si);
  }
  L0069c2b5: { // 0x69c2b5: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c2b8: { // 0x69c2b8: 6689442428 MOV word ptr [ESP + 0x28],AX
    m.w16((f.sp+0x00000028u), (s.ax & 0xffffu));
  }
  L0069c2bd: { // 0x69c2bd: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0069c2bf: { // 0x69c2bf: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c2c0: { // 0x69c2c0: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L0069c2c6: { // 0x69c2c6: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c2cc: { // 0x69c2cc: 894c245c MOV dword ptr [ESP + 0x5c],ECX
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L0069c2d0: { // 0x69c2d0: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c2d2: { // 0x69c2d2: 8d4c2458 LEA ECX,[ESP + 0x58]
    s.cx = (f.sp+0x00000058u);
  }
  L0069c2d6: { // 0x69c2d6: 8d542444 LEA EDX,[ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L0069c2da: { // 0x69c2da: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c2dd: { // 0x69c2dd: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0069c2df: { // 0x69c2df: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069c2e0: { // 0x69c2e0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069c2e1: { // 0x69c2e1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0069c2e3: { // 0x69c2e3: 6689442432 MOV word ptr [ESP + 0x32],AX
    m.w16((f.sp+0x00000032u), (s.ax & 0xffffu));
  }
  L0069c2e8: { // 0x69c2e8: 89742468 MOV dword ptr [ESP + 0x68],ESI
    m.w32((f.sp+0x00000068u), s.si);
  }
  L0069c2ec: { // 0x69c2ec: e8efbaffff CALL 0x00697de0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697de0u,6931185u); flags=s.arithmetic_flags;
  }
  L0069c2f1: { // 0x69c2f1: 8b0d70198200 MOV ECX,dword ptr [0x00821970]
    s.cx = m.r32((0x00821970u));
  }
  L0069c2f7: { // 0x69c2f7: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0069c2f9: { // 0x69c2f9: 8b1574198200 MOV EDX,dword ptr [0x00821974]
    s.dx = m.r32((0x00821974u));
  }
  L0069c2ff: { // 0x69c2ff: 8b5b04 MOV EBX,dword ptr [EBX + 0x4]
    s.bx = m.r32((s.bx+0x00000004u));
  }
  L0069c302: { // 0x69c302: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0069c304: { // 0x69c304: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L0069c306: { // 0x69c306: 895c2438 MOV dword ptr [ESP + 0x38],EBX
    m.w32((f.sp+0x00000038u), s.bx);
  }
  L0069c30a: { // 0x69c30a: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L0069c30e: { // 0x69c30e: 8dabb4000000 LEA EBP,[EBX + 0xb4]
    s.bp = (s.bx+0x000000b4u);
  }
  L0069c314: { // 0x69c314: 895c2440 MOV dword ptr [ESP + 0x40],EBX
    m.w32((f.sp+0x00000040u), s.bx);
  }
  L0069c318: { // 0x69c318: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L0069c31c: { // 0x69c31c: 896c2438 MOV dword ptr [ESP + 0x38],EBP
    m.w32((f.sp+0x00000038u), s.bp);
  }
  L0069c320: { // 0x69c320: 89742424 MOV dword ptr [ESP + 0x24],ESI
    m.w32((f.sp+0x00000024u), s.si);
  }
  L0069c324: { // 0x69c324: eb04 JMP 0x0069c32a
    goto L0069c32a;
  }
  L0069c326: { // 0x69c326: 8b6c2438 MOV EBP,dword ptr [ESP + 0x38]
    s.bp = m.r32((f.sp+0x00000038u));
  }
  L0069c32a: { // 0x69c32a: 8b87b0000000 MOV EAX,dword ptr [EDI + 0xb0]
    s.ax = m.r32((s.di+0x000000b0u));
  }
  L0069c330: { // 0x69c330: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L0069c334: { // 0x69c334: 8b8fb4000000 MOV ECX,dword ptr [EDI + 0xb4]
    s.cx = m.r32((s.di+0x000000b4u));
  }
  L0069c33a: { // 0x69c33a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c33c: { // 0x69c33c: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L0069c340: { // 0x69c340: 03cd ADD ECX,EBP
    s.cx = integer::add(s.cx,s.bp,32,flags);
  }
  L0069c342: { // 0x69c342: db442444 FILD dword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.load_integer32(m.r32(address));
  }
  L0069c346: { // 0x69c346: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L0069c34a: { // 0x69c34a: 8d442458 LEA EAX,[ESP + 0x58]
    s.ax = (f.sp+0x00000058u);
  }
  L0069c34e: { // 0x69c34e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069c34f: { // 0x69c34f: 8d97e40d0000 LEA EDX,[EDI + 0xde4]
    s.dx = (s.di+0x00000de4u);
  }
  L0069c355: { // 0x69c355: d95c245c FSTP float ptr [ESP + 0x5c]
    const auto address=(f.sp+0x0000005cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0069c359: { // 0x69c359: db44244c FILD dword ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0069c35d: { // 0x69c35d: 8d4c2474 LEA ECX,[ESP + 0x74]
    s.cx = (f.sp+0x00000074u);
  }
  L0069c361: { // 0x69c361: c744246400000000 MOV dword ptr [ESP + 0x64],0x0
    m.w32((f.sp+0x00000064u), 0x00000000u);
  }
  L0069c369: { // 0x69c369: d95c2460 FSTP float ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0069c36d: { // 0x69c36d: e80e1eefff CALL 0x0058e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e180u,6931314u); flags=s.arithmetic_flags;
  }
  L0069c372: { // 0x69c372: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0069c374: { // 0x69c374: 894c2458 MOV dword ptr [ESP + 0x58],ECX
    m.w32((f.sp+0x00000058u), s.cx);
  }
  L0069c378: { // 0x69c378: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0069c37b: { // 0x69c37b: d9442458 FLD float ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.load32(m.r32(address));
  }
  L0069c37f: { // 0x69c37f: 8954245c MOV dword ptr [ESP + 0x5c],EDX
    m.w32((f.sp+0x0000005cu), s.dx);
  }
  L0069c383: { // 0x69c383: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0069c386: { // 0x69c386: 89442460 MOV dword ptr [ESP + 0x60],EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L0069c38a: { // 0x69c38a: e8c1e60c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6931343u); flags=s.arithmetic_flags;
  }
  L0069c38f: { // 0x69c38f: d944245c FLD float ptr [ESP + 0x5c]
    const auto address=(f.sp+0x0000005cu);
    s.fp.load32(m.r32(address));
  }
  L0069c393: { // 0x69c393: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0069c395: { // 0x69c395: e8b6e60c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6931354u); flags=s.arithmetic_flags;
  }
  L0069c39a: { // 0x69c39a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0069c39c: { // 0x69c39c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0069c39e: { // 0x69c39e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c39f: { // 0x69c39f: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c3a5: { // 0x69c3a5: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c3a7: { // 0x69c3a7: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c3aa: { // 0x69c3aa: 668944242c MOV word ptr [ESP + 0x2c],AX
    m.w16((f.sp+0x0000002cu), (s.ax & 0xffffu));
  }
  L0069c3af: { // 0x69c3af: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0069c3b1: { // 0x69c3b1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c3b2: { // 0x69c3b2: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0069c3b8: { // 0x69c3b8: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L0069c3bc: { // 0x69c3bc: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069c3be: { // 0x69c3be: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069c3bf: { // 0x69c3bf: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c3c2: { // 0x69c3c2: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0069c3c7: { // 0x69c3c7: 6689442432 MOV word ptr [ESP + 0x32],AX
    m.w16((f.sp+0x00000032u), (s.ax & 0xffffu));
  }
  L0069c3cc: { // 0x69c3cc: e82f91eaff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6931409u); flags=s.arithmetic_flags;
  }
  L0069c3d1: { // 0x69c3d1: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0069c3d3: { // 0x69c3d3: 0fbe861b010000 MOVSX EAX,byte ptr [ESI + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L0069c3da: { // 0x69c3da: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0069c3dd: { // 0x69c3dd: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L0069c3e0: { // 0x69c3e0: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0069c3e6: { // 0x69c3e6: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  L0069c3e8: { // 0x69c3e8: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L0069c3ec: { // 0x69c3ec: bd00010000 MOV EBP,0x100
    s.bp = 0x00000100u;
  }
  L0069c3f1: { // 0x69c3f1: 85c5 TEST EBP,EAX
    (void)integer::logical((s.bp)&(s.ax),32,flags);
  }
  L0069c3f3: { // 0x69c3f3: 0f844b020000 JZ 0x0069c644
    if(integer::condition("JZ",flags)) goto L0069c644;
  }
  L0069c3f9: { // 0x69c3f9: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L0069c3fb: { // 0x69c3fb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0069c3fd: { // 0x69c3fd: e8bea2ddff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,6931458u); flags=s.arithmetic_flags;
  }
  L0069c402: { // 0x69c402: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L0069c404: { // 0x69c404: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0069c406: { // 0x69c406: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0069c40a: { // 0x69c40a: e8b1a2ddff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,6931471u); flags=s.arithmetic_flags;
  }
  L0069c40f: { // 0x69c40f: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0069c413: { // 0x69c413: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0069c419: { // 0x69c419: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L0069c41c: { // 0x69c41c: 741b JZ 0x0069c439
    if(integer::condition("JZ",flags)) goto L0069c439;
  }
  L0069c41e: { // 0x69c41e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0069c420: { // 0x69c420: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0069c422: { // 0x69c422: e899a2ddff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,6931495u); flags=s.arithmetic_flags;
  }
  L0069c427: { // 0x69c427: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L0069c42d: { // 0x69c42d: c684248400000001 MOV byte ptr [ESP + 0x84],0x1
    m.w8((f.sp+0x00000084u), 0x00000001u);
  }
  L0069c435: { // 0x69c435: 85cd TEST EBP,ECX
    (void)integer::logical((s.bp)&(s.cx),32,flags);
  }
  L0069c437: { // 0x69c437: 7408 JZ 0x0069c441
    if(integer::condition("JZ",flags)) goto L0069c441;
  }
  L0069c439: { // 0x69c439: c684248400000000 MOV byte ptr [ESP + 0x84],0x0
    m.w8((f.sp+0x00000084u), 0x00000000u);
  }
  L0069c441: { // 0x69c441: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0069c447: { // 0x69c447: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L0069c44a: { // 0x69c44a: 7518 JNZ 0x0069c464
    if(integer::condition("JNZ",flags)) goto L0069c464;
  }
  L0069c44c: { // 0x69c44c: 6a06 PUSH 0x6
    f.push(m,0x00000006u);
  }
  L0069c44e: { // 0x69c44e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0069c450: { // 0x69c450: e86ba2ddff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,6931541u); flags=s.arithmetic_flags;
  }
  L0069c455: { // 0x69c455: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L0069c45b: { // 0x69c45b: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L0069c460: { // 0x69c460: 85cd TEST EBP,ECX
    (void)integer::logical((s.bp)&(s.cx),32,flags);
  }
  L0069c462: { // 0x69c462: 7405 JZ 0x0069c469
    if(integer::condition("JZ",flags)) goto L0069c469;
  }
  L0069c464: { // 0x69c464: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L0069c469: { // 0x69c469: 8b8e40010000 MOV ECX,dword ptr [ESI + 0x140]
    s.cx = m.r32((s.si+0x00000140u));
  }
  L0069c46f: { // 0x69c46f: 81e100080000 AND ECX,0x800
    s.cx = integer::logical((s.cx)&(0x00000800u),32,flags);
  }
  L0069c475: { // 0x69c475: 7411 JZ 0x0069c488
    if(integer::condition("JZ",flags)) goto L0069c488;
  }
  L0069c477: { // 0x69c477: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0069c47b: { // 0x69c47b: c644241401 MOV byte ptr [ESP + 0x14],0x1
    m.w8((f.sp+0x00000014u), 0x00000001u);
  }
  L0069c480: { // 0x69c480: 85a840010000 TEST dword ptr [EAX + 0x140],EBP
    (void)integer::logical((m.r32((s.ax+0x00000140u)))&(s.bp),32,flags);
  }
  L0069c486: { // 0x69c486: 7405 JZ 0x0069c48d
    if(integer::condition("JZ",flags)) goto L0069c48d;
  }
  L0069c488: { // 0x69c488: c644241400 MOV byte ptr [ESP + 0x14],0x0
    m.w8((f.sp+0x00000014u), 0x00000000u);
  }
  L0069c48d: { // 0x69c48d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0069c48f: { // 0x69c48f: 7511 JNZ 0x0069c4a2
    if(integer::condition("JNZ",flags)) goto L0069c4a2;
  }
  L0069c491: { // 0x69c491: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0069c495: { // 0x69c495: c644241601 MOV byte ptr [ESP + 0x16],0x1
    m.w8((f.sp+0x00000016u), 0x00000001u);
  }
  L0069c49a: { // 0x69c49a: 85aa40010000 TEST dword ptr [EDX + 0x140],EBP
    (void)integer::logical((m.r32((s.dx+0x00000140u)))&(s.bp),32,flags);
  }
  L0069c4a0: { // 0x69c4a0: 7405 JZ 0x0069c4a7
    if(integer::condition("JZ",flags)) goto L0069c4a7;
  }
  L0069c4a2: { // 0x69c4a2: c644241600 MOV byte ptr [ESP + 0x16],0x0
    m.w8((f.sp+0x00000016u), 0x00000000u);
  }
  L0069c4a7: { // 0x69c4a7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0069c4a9: { // 0x69c4a9: 742f JZ 0x0069c4da
    if(integer::condition("JZ",flags)) goto L0069c4da;
  }
  L0069c4ab: { // 0x69c4ab: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0069c4af: { // 0x69c4af: 0fbe901b010000 MOVSX EDX,byte ptr [EAX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L0069c4b6: { // 0x69c4b6: 0fbe861b010000 MOVSX EAX,byte ptr [ESI + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L0069c4bd: { // 0x69c4bd: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c4bf: { // 0x69c4bf: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c4c0: { // 0x69c4c0: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0069c4c2: { // 0x69c4c2: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c4c4: { // 0x69c4c4: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0069c4c7: { // 0x69c4c7: 7f11 JG 0x0069c4da
    if(integer::condition("JG",flags)) goto L0069c4da;
  }
  L0069c4c9: { // 0x69c4c9: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0069c4cd: { // 0x69c4cd: c644241701 MOV byte ptr [ESP + 0x17],0x1
    m.w8((f.sp+0x00000017u), 0x00000001u);
  }
  L0069c4d2: { // 0x69c4d2: 85a840010000 TEST dword ptr [EAX + 0x140],EBP
    (void)integer::logical((m.r32((s.ax+0x00000140u)))&(s.bp),32,flags);
  }
  L0069c4d8: { // 0x69c4d8: 7405 JZ 0x0069c4df
    if(integer::condition("JZ",flags)) goto L0069c4df;
  }
  L0069c4da: { // 0x69c4da: c644241700 MOV byte ptr [ESP + 0x17],0x0
    m.w8((f.sp+0x00000017u), 0x00000000u);
  }
  L0069c4df: { // 0x69c4df: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0069c4e1: { // 0x69c4e1: 752d JNZ 0x0069c510
    if(integer::condition("JNZ",flags)) goto L0069c510;
  }
  L0069c4e3: { // 0x69c4e3: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0069c4e7: { // 0x69c4e7: 0fbe861b010000 MOVSX EAX,byte ptr [ESI + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L0069c4ee: { // 0x69c4ee: 0fbe911b010000 MOVSX EDX,byte ptr [ECX + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L0069c4f5: { // 0x69c4f5: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c4f7: { // 0x69c4f7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c4f8: { // 0x69c4f8: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0069c4fa: { // 0x69c4fa: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c4fc: { // 0x69c4fc: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0069c4ff: { // 0x69c4ff: 7f0f JG 0x0069c510
    if(integer::condition("JG",flags)) goto L0069c510;
  }
  L0069c501: { // 0x69c501: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0069c503: { // 0x69c503: c644241501 MOV byte ptr [ESP + 0x15],0x1
    m.w8((f.sp+0x00000015u), 0x00000001u);
  }
  L0069c508: { // 0x69c508: 85a840010000 TEST dword ptr [EAX + 0x140],EBP
    (void)integer::logical((m.r32((s.ax+0x00000140u)))&(s.bp),32,flags);
  }
  L0069c50e: { // 0x69c50e: 7405 JZ 0x0069c515
    if(integer::condition("JZ",flags)) goto L0069c515;
  }
  L0069c510: { // 0x69c510: c644241500 MOV byte ptr [ESP + 0x15],0x0
    m.w8((f.sp+0x00000015u), 0x00000000u);
  }
  L0069c515: { // 0x69c515: 0fbf4e26 MOVSX ECX,word ptr [ESI + 0x26]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L0069c519: { // 0x69c519: 0fbf4624 MOVSX EAX,word ptr [ESI + 0x24]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L0069c51d: { // 0x69c51d: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0069c520: { // 0x69c520: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0069c526: { // 0x69c526: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0069c528: { // 0x69c528: 83c180 ADD ECX,-0x80
    s.cx = integer::add(s.cx,0xffffff80u,32,flags);
  }
  L0069c52b: { // 0x69c52b: 8954246c MOV dword ptr [ESP + 0x6c],EDX
    m.w32((f.sp+0x0000006cu), s.dx);
  }
  L0069c52f: { // 0x69c52f: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L0069c532: { // 0x69c532: 894c2468 MOV dword ptr [ESP + 0x68],ECX
    m.w32((f.sp+0x00000068u), s.cx);
  }
  L0069c536: { // 0x69c536: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L0069c53b: { // 0x69c53b: 8d4c2464 LEA ECX,[ESP + 0x64]
    s.cx = (f.sp+0x00000064u);
  }
  L0069c53f: { // 0x69c53f: 8d54244c LEA EDX,[ESP + 0x4c]
    s.dx = (f.sp+0x0000004cu);
  }
  L0069c543: { // 0x69c543: 83c080 ADD EAX,-0x80
    s.ax = integer::add(s.ax,0xffffff80u,32,flags);
  }
  L0069c546: { // 0x69c546: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069c547: { // 0x69c547: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0069c548: { // 0x69c548: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0069c54a: { // 0x69c54a: 8944246c MOV dword ptr [ESP + 0x6c],EAX
    m.w32((f.sp+0x0000006cu), s.ax);
  }
  L0069c54e: { // 0x69c54e: e88db8ffff CALL 0x00697de0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697de0u,6931795u); flags=s.arithmetic_flags;
  }
  L0069c553: { // 0x69c553: 8b28 MOV EBP,dword ptr [EAX]
    s.bp = m.r32((s.ax));
  }
  L0069c555: { // 0x69c555: 8b97b4000000 MOV EDX,dword ptr [EDI + 0xb4]
    s.dx = m.r32((s.di+0x000000b4u));
  }
  L0069c55b: { // 0x69c55b: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L0069c55e: { // 0x69c55e: 8b87b0000000 MOV EAX,dword ptr [EDI + 0xb0]
    s.ax = m.r32((s.di+0x000000b0u));
  }
  L0069c564: { // 0x69c564: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0069c566: { // 0x69c566: 2be8 SUB EBP,EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  L0069c568: { // 0x69c568: 0fbe961b010000 MOVSX EDX,byte ptr [ESI + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L0069c56f: { // 0x69c56f: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0069c571: { // 0x69c571: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0069c574: { // 0x69c574: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c576: { // 0x69c576: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0069c578: { // 0x69c578: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0069c57a: { // 0x69c57a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c57b: { // 0x69c57b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c57d: { // 0x69c57d: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c57f: { // 0x69c57f: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0069c581: { // 0x69c581: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0069c583: { // 0x69c583: 7f30 JG 0x0069c5b5
    if(integer::condition("JG",flags)) goto L0069c5b5;
  }
  L0069c585: { // 0x69c585: 8a442414 MOV AL,byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L0069c589: { // 0x69c589: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069c58b: { // 0x69c58b: 0f8525010000 JNZ 0x0069c6b6
    if(integer::condition("JNZ",flags)) goto L0069c6b6;
  }
  L0069c591: { // 0x69c591: 8a442415 MOV AL,byte ptr [ESP + 0x15]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000015u)));
  }
  L0069c595: { // 0x69c595: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069c597: { // 0x69c597: 0f8519010000 JNZ 0x0069c6b6
    if(integer::condition("JNZ",flags)) goto L0069c6b6;
  }
  L0069c59d: { // 0x69c59d: 8a442416 MOV AL,byte ptr [ESP + 0x16]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000016u)));
  }
  L0069c5a1: { // 0x69c5a1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069c5a3: { // 0x69c5a3: 0f85d9000000 JNZ 0x0069c682
    if(integer::condition("JNZ",flags)) goto L0069c682;
  }
  L0069c5a9: { // 0x69c5a9: 8a442417 MOV AL,byte ptr [ESP + 0x17]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000017u)));
  }
  L0069c5ad: { // 0x69c5ad: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069c5af: { // 0x69c5af: 0f85cd000000 JNZ 0x0069c682
    if(integer::condition("JNZ",flags)) goto L0069c682;
  }
  L0069c5b5: { // 0x69c5b5: 8a842484000000 MOV AL,byte ptr [ESP + 0x84]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000084u)));
  }
  L0069c5bc: { // 0x69c5bc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069c5be: { // 0x69c5be: 7526 JNZ 0x0069c5e6
    if(integer::condition("JNZ",flags)) goto L0069c5e6;
  }
  L0069c5c0: { // 0x69c5c0: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L0069c5c4: { // 0x69c5c4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069c5c6: { // 0x69c5c6: 751e JNZ 0x0069c5e6
    if(integer::condition("JNZ",flags)) goto L0069c5e6;
  }
  L0069c5c8: { // 0x69c5c8: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L0069c5ce: { // 0x69c5ce: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0069c5d2: { // 0x69c5d2: 2500010000 AND EAX,0x100
    s.ax = integer::logical((s.ax)&(0x00000100u),32,flags);
  }
  L0069c5d7: { // 0x69c5d7: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0069c5d9: { // 0x69c5d9: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L0069c5db: { // 0x69c5db: 83e03c AND EAX,0x3c
    s.ax = integer::logical((s.ax)&(0x0000003cu),32,flags);
  }
  L0069c5de: { // 0x69c5de: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0069c5e0: { // 0x69c5e0: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0069c5e4: { // 0x69c5e4: eb5e JMP 0x0069c644
    goto L0069c644;
  }
  L0069c5e6: { // 0x69c5e6: 8b5c243c MOV EBX,dword ptr [ESP + 0x3c]
    s.bx = m.r32((f.sp+0x0000003cu));
  }
  L0069c5ea: { // 0x69c5ea: 8a842484000000 MOV AL,byte ptr [ESP + 0x84]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000084u)));
  }
  L0069c5f1: { // 0x69c5f1: 2bdd SUB EBX,EBP
    s.bx = integer::sub(s.bx,s.bp,32,flags);
  }
  L0069c5f3: { // 0x69c5f3: 8b6c2440 MOV EBP,dword ptr [ESP + 0x40]
    s.bp = m.r32((f.sp+0x00000040u));
  }
  L0069c5f7: { // 0x69c5f7: 2be9 SUB EBP,ECX
    s.bp = integer::sub(s.bp,s.cx,32,flags);
  }
  L0069c5f9: { // 0x69c5f9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069c5fb: { // 0x69c5fb: 7410 JZ 0x0069c60d
    if(integer::condition("JZ",flags)) goto L0069c60d;
  }
  L0069c5fd: { // 0x69c5fd: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0069c5ff: { // 0x69c5ff: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0069c601: { // 0x69c601: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c602: { // 0x69c602: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c604: { // 0x69c604: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c606: { // 0x69c606: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0069c608: { // 0x69c608: 83f90f CMP ECX,0xf
    (void)integer::sub(s.cx,0x0000000fu,32,flags);
  }
  L0069c60b: { // 0x69c60b: 7f16 JG 0x0069c623
    if(integer::condition("JG",flags)) goto L0069c623;
  }
  L0069c60d: { // 0x69c60d: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L0069c611: { // 0x69c611: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069c613: { // 0x69c613: 742b JZ 0x0069c640
    if(integer::condition("JZ",flags)) goto L0069c640;
  }
  L0069c615: { // 0x69c615: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0069c617: { // 0x69c617: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069c618: { // 0x69c618: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c61a: { // 0x69c61a: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069c61c: { // 0x69c61c: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L0069c61e: { // 0x69c61e: 83f80f CMP EAX,0xf
    (void)integer::sub(s.ax,0x0000000fu,32,flags);
  }
  L0069c621: { // 0x69c621: 7e1d JLE 0x0069c640
    if(integer::condition("JLE",flags)) goto L0069c640;
  }
  L0069c623: { // 0x69c623: 8b9640010000 MOV EDX,dword ptr [ESI + 0x140]
    s.dx = m.r32((s.si+0x00000140u));
  }
  L0069c629: { // 0x69c629: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0069c62d: { // 0x69c62d: 81e200010000 AND EDX,0x100
    s.dx = integer::logical((s.dx)&(0x00000100u),32,flags);
  }
  L0069c633: { // 0x69c633: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L0069c635: { // 0x69c635: 1bd2 SBB EDX,EDX
    s.dx = integer::sub(s.dx,s.dx,32,flags,flags&integer::CF);
  }
  L0069c637: { // 0x69c637: 83e23c AND EDX,0x3c
    s.dx = integer::logical((s.dx)&(0x0000003cu),32,flags);
  }
  L0069c63a: { // 0x69c63a: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069c63c: { // 0x69c63c: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0069c640: { // 0x69c640: 8b5c2440 MOV EBX,dword ptr [ESP + 0x40]
    s.bx = m.r32((f.sp+0x00000040u));
  }
  L0069c644: { // 0x69c644: 395c2418 CMP dword ptr [ESP + 0x18],EBX
    (void)integer::sub(m.r32((f.sp+0x00000018u)),s.bx,32,flags);
  }
  L0069c648: { // 0x69c648: 0f8e9c000000 JLE 0x0069c6ea
    if(integer::condition("JLE",flags)) goto L0069c6ea;
  }
  L0069c64e: { // 0x69c64e: 8b742438 MOV ESI,dword ptr [ESP + 0x38]
    s.si = m.r32((f.sp+0x00000038u));
  }
  L0069c652: { // 0x69c652: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0069c656: { // 0x69c656: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L0069c657: { // 0x69c657: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0069c658: { // 0x69c658: 3db4000000 CMP EAX,0xb4
    (void)integer::sub(s.ax,0x000000b4u,32,flags);
  }
  L0069c65d: { // 0x69c65d: 89742438 MOV dword ptr [ESP + 0x38],ESI
    m.w32((f.sp+0x00000038u), s.si);
  }
  L0069c661: { // 0x69c661: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0069c665: { // 0x69c665: 0f8cbbfcffff JL 0x0069c326
    if(integer::condition("JL",flags)) goto L0069c326;
  }
  L0069c66b: { // 0x69c66b: 8b842480000000 MOV EAX,dword ptr [ESP + 0x80]
    s.ax = m.r32((f.sp+0x00000080u));
  }
  L0069c672: { // 0x69c672: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0069c676: { // 0x69c676: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069c677: { // 0x69c677: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069c678: { // 0x69c678: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069c679: { // 0x69c679: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0069c67b: { // 0x69c67b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069c67c: { // 0x69c67c: 83c46c ADD ESP,0x6c
    f.sp = integer::add(f.sp,0x0000006cu,32,flags);
  }
  L0069c67f: { // 0x69c67f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0069c682: { // 0x69c682: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L0069c686: { // 0x69c686: 668b44242e MOV AX,word ptr [ESP + 0x2e]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x0000002eu)));
  }
  L0069c68b: { // 0x69c68b: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0069c68c: { // 0x69c68c: 6689842486000000 MOV word ptr [ESP + 0x86],AX
    m.w16((f.sp+0x00000086u), (s.ax & 0xffffu));
  }
  L0069c694: { // 0x69c694: 8b842480000000 MOV EAX,dword ptr [ESP + 0x80]
    s.ax = m.r32((f.sp+0x00000080u));
  }
  L0069c69b: { // 0x69c69b: 6689942484000000 MOV word ptr [ESP + 0x84],DX
    m.w16((f.sp+0x00000084u), (s.dx & 0xffffu));
  }
  L0069c6a3: { // 0x69c6a3: 8b8c2484000000 MOV ECX,dword ptr [ESP + 0x84]
    s.cx = m.r32((f.sp+0x00000084u));
  }
  L0069c6aa: { // 0x69c6aa: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069c6ab: { // 0x69c6ab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069c6ac: { // 0x69c6ac: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069c6ad: { // 0x69c6ad: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0069c6af: { // 0x69c6af: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069c6b0: { // 0x69c6b0: 83c46c ADD ESP,0x6c
    f.sp = integer::add(f.sp,0x0000006cu,32,flags);
  }
  L0069c6b3: { // 0x69c6b3: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0069c6b6: { // 0x69c6b6: 8b54242e MOV EDX,dword ptr [ESP + 0x2e]
    s.dx = m.r32((f.sp+0x0000002eu));
  }
  L0069c6ba: { // 0x69c6ba: 668b4c242c MOV CX,word ptr [ESP + 0x2c]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x0000002cu)));
  }
  L0069c6bf: { // 0x69c6bf: 8b842480000000 MOV EAX,dword ptr [ESP + 0x80]
    s.ax = m.r32((f.sp+0x00000080u));
  }
  L0069c6c6: { // 0x69c6c6: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0069c6c7: { // 0x69c6c7: 66898c2484000000 MOV word ptr [ESP + 0x84],CX
    m.w16((f.sp+0x00000084u), (s.cx & 0xffffu));
  }
  L0069c6cf: { // 0x69c6cf: 6689942486000000 MOV word ptr [ESP + 0x86],DX
    m.w16((f.sp+0x00000086u), (s.dx & 0xffffu));
  }
  L0069c6d7: { // 0x69c6d7: 8b8c2484000000 MOV ECX,dword ptr [ESP + 0x84]
    s.cx = m.r32((f.sp+0x00000084u));
  }
  L0069c6de: { // 0x69c6de: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069c6df: { // 0x69c6df: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069c6e0: { // 0x69c6e0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069c6e1: { // 0x69c6e1: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0069c6e3: { // 0x69c6e3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069c6e4: { // 0x69c6e4: 83c46c ADD ESP,0x6c
    f.sp = integer::add(f.sp,0x0000006cu,32,flags);
  }
  L0069c6e7: { // 0x69c6e7: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0069c6ea: { // 0x69c6ea: 8b842480000000 MOV EAX,dword ptr [ESP + 0x80]
    s.ax = m.r32((f.sp+0x00000080u));
  }
  L0069c6f1: { // 0x69c6f1: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0069c6f5: { // 0x69c6f5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069c6f6: { // 0x69c6f6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069c6f7: { // 0x69c6f7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069c6f8: { // 0x69c6f8: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0069c6fa: { // 0x69c6fa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069c6fb: { // 0x69c6fb: 83c46c ADD ESP,0x6c
    f.sp = integer::add(f.sp,0x0000006cu,32,flags);
  }
  L0069c6fe: { // 0x69c6fe: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
