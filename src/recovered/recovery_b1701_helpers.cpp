// PRIVATE exact-instruction projections for one reviewed B543n1 first hit.
// No fake stack, seeds, copied output oracle, callbacks or accepted-source edits.
#include "recovery_b1701_helpers.hpp"
#include "recovery_b1701_ftol.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1701::helpers {
namespace {
namespace integer=ra2::recovered::direct_b33::integer;
using namespace ra2::recovered::floating_b61;
using ra2::recovered::recovery_b566::reverse_divide64;
using ra2::recovered::recovery_b566::reverse_divide32;
struct Operations {};
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_0018e180(Memory&,State&,Frame&,const Operations&);
void f_00297de0(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
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
    s.arithmetic_flags=flags; ra2::recovered::recovery_b566::finish(m,s,f,4u); return;
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
    s.arithmetic_flags=flags; ra2::recovered::recovery_b566::finish(m,s,f,8u); return;
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
    s.arithmetic_flags=flags; ra2::recovered::recovery_b566::finish(m,s,f,4u); return;
  }
}

void picker_body(Memory& m,State& s,Frame& f,const Operations& op) {
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
  throw std::domain_error("22A890 picker finite bridge-zero route required");
  L0069c644: { // 0x69c644: 395c2418 CMP dword ptr [ESP + 0x18],EBX
    (void)integer::sub(m.r32((f.sp+0x00000018u)),s.bx,32,flags);
  }
  L0069c648: { // 0x69c648: 0f8e9c000000 JLE 0x0069c6ea
    if(integer::condition("JLE",flags)) goto L0069c6ea;
  }
  throw std::domain_error("22A890 picker finite first-hit route required");
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
    s.arithmetic_flags=flags; ra2::recovered::recovery_b566::finish(m,s,f,8u); return;
  }

}

void invoke(Memory& m,State& s,Frame& caller,U target,U continuation) {
 if(target==0x76aa50u){helpers::ftol(m,s,caller,continuation);return;}
 caller.push(m,continuation);Frame child{caller.sp,caller.sp,continuation};
 switch(target){
 case 0x58e180u:f_0018e180(m,s,child,{});break;
 case 0x697de0u:f_00297de0(m,s,child,{});break;
 case 0x545500u:f_00145500(m,s,child,{});break;
 default:throw std::domain_error("22A890 unreviewed picker child target");
 }
 caller.sp=child.sp;
}
} // private instruction projections
void pick(Memory& m,State& s,Frame& caller,U continuation) {
 if(continuation!=0x62a923u)throw std::domain_error("22A890 actual picker continuation required");
 caller.push(m,continuation);Frame child{caller.sp,caller.sp,continuation};
 picker_body(m,s,child,{});caller.sp=child.sp;
}
void map_cell(Memory& m,State& s,Frame& caller,U continuation) {
 if(continuation!=0x62a92eu)throw std::domain_error("22A890 actual map continuation required");
 invoke(m,s,caller,0x545500u,continuation);
}
} // namespace ra2::recovered::recovery_b1701::helpers
