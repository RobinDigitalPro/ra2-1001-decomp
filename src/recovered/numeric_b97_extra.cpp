#include "recovered/numeric_b97_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::numeric_b97 {
namespace {
void f_001a46f0(Memory&,State&,Frame&,const Operations&);
void f_0018e180(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_000ba0f0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
enum class Kind {move,store,compare,scan}; enum class Repeat {single,count,equal,not_equal};
inline void string_instruction(Memory& m,State& s,std::uint32_t& flags,Kind kind,unsigned width,Repeat repeat){
 const std::uint32_t bytes=width/8u,step=(flags&0x400u)?0u-bytes:bytes,count=s.cx;
 if(kind!=Kind::store||repeat!=Repeat::count||(width!=8u&&width!=32u))throw std::domain_error("numeric97 extra unsupported string form");
 for(std::uint32_t k=0;k<count;++k){if(width==8u)m.w8(s.di+k*step,s.ax);else m.w32(s.di+k*step,s.ax);}
 s.di+=count*step;s.cx=0;
}
}

namespace {








void f_001a46f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x5a46f0: 51 PUSH ECX
    f.push(m,s.cx);
  }
   { // 0x5a46f1: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x5a46f2: 55 PUSH EBP
    f.push(m,s.bp);
  }
   { // 0x5a46f3: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x5a46f4: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x5a46f5: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
   { // 0x5a46f7: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
   { // 0x5a46f9: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
   { // 0x5a46fb: 7421 JZ 0x005a471e
    if(integer::condition("JZ",flags)) goto L005a471e;
  }
   { // 0x5a46fd: 83ff20 CMP EDI,0x20
    (void)integer::sub(s.di,0x00000020u,32,flags);
  }
   { // 0x5a4700: 7524 JNZ 0x005a4726
    if(integer::condition("JNZ",flags)) goto L005a4726;
  }
   { // 0x5a4702: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
   { // 0x5a4706: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
   { // 0x5a4708: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
   { // 0x5a470a: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
   { // 0x5a470b: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
   { // 0x5a470d: 740f JZ 0x005a471e
    if(integer::condition("JZ",flags)) goto L005a471e;
  }
   { // 0x5a470f: 8d5101 LEA EDX,[ECX + 0x1]
    s.dx = (s.cx+0x00000001u);
  }
  L005a4712: { // 0x5a4712: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
   { // 0x5a4714: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
   { // 0x5a4716: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
   { // 0x5a4719: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
   { // 0x5a471a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
   { // 0x5a471c: 75f4 JNZ 0x005a4712
    if(integer::condition("JNZ",flags)) goto L005a4712;
  }
  L005a471e: { // 0x5a471e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x5a471f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x5a4720: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
   { // 0x5a4721: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
   { // 0x5a4722: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
   { // 0x5a4723: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005a4726: { // 0x5a4726: 7d53 JGE 0x005a477b
    if(integer::condition("JGE",flags)) goto L005a477b;
  }
   { // 0x5a4728: b820000000 MOV EAX,0x20
    s.ax = 0x00000020u;
  }
   { // 0x5a472d: 83cbff OR EBX,0xffffffff
    s.bx = integer::logical((s.bx)|(0xffffffffu),32,flags);
  }
   { // 0x5a4730: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
   { // 0x5a4732: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
   { // 0x5a4734: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
   { // 0x5a4738: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
   { // 0x5a473c: d3eb SHR EBX,CL
    s.bx = integer::shift(s.bx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
   { // 0x5a473e: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
   { // 0x5a4740: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
   { // 0x5a4742: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
   { // 0x5a4743: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
   { // 0x5a4745: f7d3 NOT EBX
    s.bx = (~(s.bx)&integer::mask(32));
  }
   { // 0x5a4747: 74d5 JZ 0x005a471e
    if(integer::condition("JZ",flags)) goto L005a471e;
  }
   { // 0x5a4749: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
   { // 0x5a474a: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L005a474e: { // 0x5a474e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
   { // 0x5a4750: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
   { // 0x5a4752: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
   { // 0x5a4754: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
   { // 0x5a4757: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
   { // 0x5a4759: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
   { // 0x5a475d: 23d3 AND EDX,EBX
    s.dx = integer::logical((s.dx)&(s.bx),32,flags);
  }
   { // 0x5a475f: d3ed SHR EBP,CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
   { // 0x5a4761: 0bc5 OR EAX,EBP
    s.ax = integer::logical((s.ax)|(s.bp),32,flags);
  }
   { // 0x5a4763: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
   { // 0x5a4765: 8946fc MOV dword ptr [ESI + -0x4],EAX
    m.w32((s.si-0x00000004u), s.ax);
  }
   { // 0x5a4768: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
   { // 0x5a476c: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
   { // 0x5a476d: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
   { // 0x5a4771: 75db JNZ 0x005a474e
    if(integer::condition("JNZ",flags)) goto L005a474e;
  }
   { // 0x5a4773: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x5a4774: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x5a4775: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
   { // 0x5a4776: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
   { // 0x5a4777: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
   { // 0x5a4778: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005a477b: { // 0x5a477b: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
   { // 0x5a477d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x5a477e: 83e21f AND EDX,0x1f
    s.dx = integer::logical((s.dx)&(0x0000001fu),32,flags);
  }
   { // 0x5a4781: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x5a4783: c1f805 SAR EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x5a4786: 81e71f000080 AND EDI,0x8000001f
    s.di = integer::logical((s.di)&(0x8000001fu),32,flags);
  }
   { // 0x5a478c: 7905 JNS 0x005a4793
    if(integer::condition("JNS",flags)) goto L005a4793;
  }
   { // 0x5a478e: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
   { // 0x5a478f: 83cfe0 OR EDI,0xffffffe0
    s.di = integer::logical((s.di)|(0xffffffe0u),32,flags);
  }
   { // 0x5a4792: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005a4793: { // 0x5a4793: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
   { // 0x5a4797: 8d4bff LEA ECX,[EBX + -0x1]
    s.cx = (s.bx-0x00000001u);
  }
   { // 0x5a479a: 8d549efc LEA EDX,[ESI + EBX*0x4 + -0x4]
    s.dx = (s.si+(s.bx * 0x00000004u)-0x00000004u);
  }
   { // 0x5a479e: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
   { // 0x5a47a0: 7d47 JGE 0x005a47e9
    if(integer::condition("JGE",flags)) goto L005a47e9;
  }
   { // 0x5a47a2: be20000000 MOV ESI,0x20
    s.si = 0x00000020u;
  }
   { // 0x5a47a7: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
   { // 0x5a47a9: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
   { // 0x5a47ab: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005a47af: { // 0x5a47af: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
   { // 0x5a47b1: 8d0c8504000000 LEA ECX,[EAX*0x4 + 0x4]
    s.cx = ((s.ax * 0x00000004u)+0x00000004u);
  }
   { // 0x5a47b8: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
   { // 0x5a47ba: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
   { // 0x5a47bc: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
   { // 0x5a47be: 83ea04 SUB EDX,0x4
    s.dx = integer::sub(s.dx,0x00000004u,32,flags);
  }
   { // 0x5a47c1: 8b1b MOV EBX,dword ptr [EBX]
    s.bx = m.r32((s.bx));
  }
   { // 0x5a47c3: d3eb SHR EBX,CL
    s.bx = integer::shift(s.bx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
   { // 0x5a47c5: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
   { // 0x5a47cc: 2be9 SUB EBP,ECX
    s.bp = integer::sub(s.bp,s.cx,32,flags);
  }
   { // 0x5a47ce: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
   { // 0x5a47d0: 8b6d00 MOV EBP,dword ptr [EBP]
    s.bp = m.r32((s.bp));
  }
   { // 0x5a47d3: d3e5 SHL EBP,CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
   { // 0x5a47d5: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
   { // 0x5a47d9: 0bdd OR EBX,EBP
    s.bx = integer::logical((s.bx)|(s.bp),32,flags);
  }
   { // 0x5a47db: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
   { // 0x5a47dc: 895a04 MOV dword ptr [EDX + 0x4],EBX
    m.w32((s.dx+0x00000004u), s.bx);
  }
   { // 0x5a47df: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
   { // 0x5a47e3: 75ca JNZ 0x005a47af
    if(integer::condition("JNZ",flags)) goto L005a47af;
  }
   { // 0x5a47e5: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L005a47e9: { // 0x5a47e9: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
   { // 0x5a47eb: 7d17 JGE 0x005a4804
    if(integer::condition("JGE",flags)) goto L005a4804;
  }
   { // 0x5a47ed: 8d0c8500000000 LEA ECX,[EAX*0x4 + 0x0]
    s.cx = ((s.ax * 0x00000004u)+0x00000000u);
  }
   { // 0x5a47f4: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
   { // 0x5a47f6: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
   { // 0x5a47f8: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
   { // 0x5a47fa: 8b36 MOV ESI,dword ptr [ESI]
    s.si = m.r32((s.si));
  }
   { // 0x5a47fc: d3e6 SHL ESI,CL
    s.si = integer::shift(s.si,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
   { // 0x5a47fe: 83ea04 SUB EDX,0x4
    s.dx = integer::sub(s.dx,0x00000004u,32,flags);
  }
   { // 0x5a4801: 897204 MOV dword ptr [EDX + 0x4],ESI
    m.w32((s.dx+0x00000004u), s.si);
  }
  L005a4804: { // 0x5a4804: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005a4806: { // 0x5a4806: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
   { // 0x5a4808: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
   { // 0x5a480a: 7c02 JL 0x005a480e
    if(integer::condition("JL",flags)) goto L005a480e;
  }
   { // 0x5a480c: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L005a480e: { // 0x5a480e: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
   { // 0x5a4810: 0f8d08ffffff JGE 0x005a471e
    if(integer::condition("JGE",flags)) goto L005a471e;
  }
   { // 0x5a4816: c70200000000 MOV dword ptr [EDX],0x0
    m.w32((s.dx), 0x00000000u);
  }
   { // 0x5a481c: 83ea04 SUB EDX,0x4
    s.dx = integer::sub(s.dx,0x00000004u,32,flags);
  }
   { // 0x5a481f: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
   { // 0x5a4820: ebe4 JMP 0x005a4806
    goto L005a4806;
  }
}
void f_0018e180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x58e180: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
   { // 0x58e183: d94208 FLD float ptr [EDX + 0x8]
    const auto address=(s.dx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58e186: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x58e187: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
   { // 0x58e18b: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58e18e: d94204 FLD float ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58e191: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58e194: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
   { // 0x58e196: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x58e198: d902 FLD float ptr [EDX]
    const auto address=(s.dx);
    s.fp.load32(m.r32(address));
  }
   { // 0x58e19a: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58e19c: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x58e19e: d8420c FADD float ptr [EDX + 0xc]
    const auto address=(s.dx+0x0000000cu);
    s.fp.add32(m.r32(address));
  }
   { // 0x58e1a1: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58e1a5: d94210 FLD float ptr [EDX + 0x10]
    const auto address=(s.dx+0x00000010u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58e1a8: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58e1aa: d94218 FLD float ptr [EDX + 0x18]
    const auto address=(s.dx+0x00000018u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58e1ad: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58e1b0: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x58e1b2: d94214 FLD float ptr [EDX + 0x14]
    const auto address=(s.dx+0x00000014u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58e1b5: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58e1b8: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x58e1ba: d8421c FADD float ptr [EDX + 0x1c]
    const auto address=(s.dx+0x0000001cu);
    s.fp.add32(m.r32(address));
  }
   { // 0x58e1bd: d95c2408 FSTP float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58e1c1: d94220 FLD float ptr [EDX + 0x20]
    const auto address=(s.dx+0x00000020u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58e1c4: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58e1c6: d94228 FLD float ptr [EDX + 0x28]
    const auto address=(s.dx+0x00000028u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58e1c9: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58e1cc: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x58e1ce: d94224 FLD float ptr [EDX + 0x24]
    const auto address=(s.dx+0x00000024u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58e1d1: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58e1d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x58e1d5: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x58e1d7: d8422c FADD float ptr [EDX + 0x2c]
    const auto address=(s.dx+0x0000002cu);
    s.fp.add32(m.r32(address));
  }
   { // 0x58e1da: 8b542400 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
   { // 0x58e1de: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
   { // 0x58e1e0: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
   { // 0x58e1e4: d95c2408 FSTP float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58e1e8: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
   { // 0x58e1eb: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
   { // 0x58e1ef: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
   { // 0x58e1f2: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
   { // 0x58e1f5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x76aa50: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
   { // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
   { // 0x76aa56: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
   { // 0x76aa5a: 8b1424 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
   { // 0x76aa5d: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
   { // 0x76aa63: 3b15043a7c00 CMP EDX,dword ptr [0x007c3a04]
    (void)integer::sub(s.dx,m.r32((0x007c3a04u)),32,flags);
  }
   { // 0x76aa69: 750b JNZ 0x0076aa76
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
   { // 0x76aa6b: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
   { // 0x76aa6d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
   { // 0x76aa70: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
   { // 0x76aa72: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
   { // 0x76aa75: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { // 0x76aa76: 8b15043a7c00 MOV EDX,dword ptr [0x007c3a04]
    s.dx = m.r32((0x007c3a04u));
  }
   { // 0x76aa7c: 891424 MOV dword ptr [ESP],EDX
    m.w32((f.sp), s.dx);
  }
   { // 0x76aa7f: d92c24 FLDCW word ptr [ESP]
    const auto address=(f.sp);
    s.fp.load_control(m.r16(address));
  }
   { // 0x76aa82: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
   { // 0x76aa84: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
   { // 0x76aa87: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
   { // 0x76aa89: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
   { // 0x76aa8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ba0f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x4ba0f0: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
   { // 0x4ba0f4: d80d38317c00 FMUL float ptr [0x007c3138]
    const auto address=(0x007c3138u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x4ba0fa: e851092b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4956415u); flags=s.arithmetic_flags;
  }
   { // 0x4ba0ff: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
   { // 0x4ba101: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x4ba102: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x4ba104: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
   { // 0x4ba107: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x4ba109: 25ff1f0080 AND EAX,0x80001fff
    s.ax = integer::logical((s.ax)&(0x80001fffu),32,flags);
  }
   { // 0x4ba10e: 790e JNS 0x004ba11e
    if(integer::condition("JNS",flags)) goto L004ba11e;
  }
   { // 0x4ba110: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
   { // 0x4ba111: 0d00e0ffff OR EAX,0xffffe000
    s.ax = integer::logical((s.ax)|(0xffffe000u),32,flags);
  }
   { // 0x4ba116: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
   { // 0x4ba117: 7905 JNS 0x004ba11e
    if(integer::condition("JNS",flags)) goto L004ba11e;
  }
   { // 0x4ba119: 0500200000 ADD EAX,0x2000
    s.ax = integer::add(s.ax,0x00002000u,32,flags);
  }
  L004ba11e: { // 0x4ba11e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
   { // 0x4ba120: 7408 JZ 0x004ba12a
    if(integer::condition("JZ",flags)) goto L004ba12a;
  }
   { // 0x4ba122: 3dff1f0000 CMP EAX,0x1fff
    (void)integer::sub(s.ax,0x00001fffu,32,flags);
  }
   { // 0x4ba127: 7d01 JGE 0x004ba12a
    if(integer::condition("JGE",flags)) goto L004ba12a;
  }
   { // 0x4ba129: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba12a: { // 0x4ba12a: d9048504a17e00 FLD float ptr [EAX*0x4 + 0x7ea104]
    const auto address=((s.ax * 0x00000004u)+0x007ea104u);
    s.fp.load32(m.r32(address));
  }
   { // 0x4ba131: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5916400u:f_001a46f0(m,s,child,{});break;
case 5824896u:f_0018e180(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 4956400u:f_000ba0f0(m,s,child,{});break;
default:throw std::domain_error("numeric97 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_005a4b10(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x5a4b10: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
   { // 0x5a4b13: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x5a4b14: 55 PUSH EBP
    f.push(m,s.bp);
  }
   { // 0x5a4b15: 8b6c2428 MOV EBP,dword ptr [ESP + 0x28]
    s.bp = m.r32((f.sp+0x00000028u));
  }
   { // 0x5a4b19: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x5a4b1a: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
   { // 0x5a4b1c: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x5a4b1d: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
   { // 0x5a4b1f: 8d14ad00000000 LEA EDX,[EBP*0x4 + 0x0]
    s.dx = ((s.bp * 0x00000004u)+0x00000000u);
  }
   { // 0x5a4b26: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
   { // 0x5a4b28: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
   { // 0x5a4b2a: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
   { // 0x5a4b2c: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
   { // 0x5a4b30: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
   { // 0x5a4b33: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
   { // 0x5a4b35: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
   { // 0x5a4b37: 89742424 MOV dword ptr [ESP + 0x24],ESI
    m.w32((f.sp+0x00000024u), s.si);
  }
   { // 0x5a4b3b: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
   { // 0x5a4b3e: f3aa STOSB.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::count);
  }
   { // 0x5a4b40: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
   { // 0x5a4b44: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
   { // 0x5a4b4a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
   { // 0x5a4b4c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
   { // 0x5a4b4e: 7521 JNZ 0x005a4b71
    if(integer::condition("JNZ",flags)) goto L005a4b71;
  }
   { // 0x5a4b50: 8d4432fc LEA EAX,[EDX + ESI*0x1 + -0x4]
    s.ax = (s.dx+(s.si * 0x00000001u)-0x00000004u);
  }
   { // 0x5a4b54: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
   { // 0x5a4b56: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
   { // 0x5a4b59: 750d JNZ 0x005a4b68
    if(integer::condition("JNZ",flags)) goto L005a4b68;
  }
  L005a4b5b: { // 0x5a4b5b: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
   { // 0x5a4b5c: 740a JZ 0x005a4b68
    if(integer::condition("JZ",flags)) goto L005a4b68;
  }
   { // 0x5a4b5e: 8b70fc MOV ESI,dword ptr [EAX + -0x4]
    s.si = m.r32((s.ax-0x00000004u));
  }
   { // 0x5a4b61: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
   { // 0x5a4b64: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
   { // 0x5a4b66: 74f3 JZ 0x005a4b5b
    if(integer::condition("JZ",flags)) goto L005a4b5b;
  }
  L005a4b68: { // 0x5a4b68: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
   { // 0x5a4b6b: 0f8e60010000 JLE 0x005a4cd1
    if(integer::condition("JLE",flags)) goto L005a4cd1;
  }
  L005a4b71: { // 0x5a4b71: 8b7c242c MOV EDI,dword ptr [ESP + 0x2c]
    s.di = m.r32((f.sp+0x0000002cu));
  }
   { // 0x5a4b75: 833f00 CMP dword ptr [EDI],0x0
    (void)integer::sub(m.r32((s.di)),0x00000000u,32,flags);
  }
   { // 0x5a4b78: 7524 JNZ 0x005a4b9e
    if(integer::condition("JNZ",flags)) goto L005a4b9e;
  }
   { // 0x5a4b7a: 8b743afc MOV ESI,dword ptr [EDX + EDI*0x1 + -0x4]
    s.si = m.r32((s.dx+(s.di * 0x00000001u)-0x00000004u));
  }
   { // 0x5a4b7e: 8d443afc LEA EAX,[EDX + EDI*0x1 + -0x4]
    s.ax = (s.dx+(s.di * 0x00000001u)-0x00000004u);
  }
   { // 0x5a4b82: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
   { // 0x5a4b84: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
   { // 0x5a4b86: 750d JNZ 0x005a4b95
    if(integer::condition("JNZ",flags)) goto L005a4b95;
  }
  L005a4b88: { // 0x5a4b88: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
   { // 0x5a4b89: 740a JZ 0x005a4b95
    if(integer::condition("JZ",flags)) goto L005a4b95;
  }
   { // 0x5a4b8b: 8b70fc MOV ESI,dword ptr [EAX + -0x4]
    s.si = m.r32((s.ax-0x00000004u));
  }
   { // 0x5a4b8e: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
   { // 0x5a4b91: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
   { // 0x5a4b93: 74f3 JZ 0x005a4b88
    if(integer::condition("JZ",flags)) goto L005a4b88;
  }
  L005a4b95: { // 0x5a4b95: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
   { // 0x5a4b98: 0f8e33010000 JLE 0x005a4cd1
    if(integer::condition("JLE",flags)) goto L005a4cd1;
  }
  L005a4b9e: { // 0x5a4b9e: 8d443afc LEA EAX,[EDX + EDI*0x1 + -0x4]
    s.ax = (s.dx+(s.di * 0x00000001u)-0x00000004u);
  }
   { // 0x5a4ba2: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
   { // 0x5a4ba4: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
   { // 0x5a4ba7: 750d JNZ 0x005a4bb6
    if(integer::condition("JNZ",flags)) goto L005a4bb6;
  }
  L005a4ba9: { // 0x5a4ba9: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
   { // 0x5a4baa: 740e JZ 0x005a4bba
    if(integer::condition("JZ",flags)) goto L005a4bba;
  }
   { // 0x5a4bac: 8b50fc MOV EDX,dword ptr [EAX + -0x4]
    s.dx = m.r32((s.ax-0x00000004u));
  }
   { // 0x5a4baf: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
   { // 0x5a4bb2: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
   { // 0x5a4bb4: 74f3 JZ 0x005a4ba9
    if(integer::condition("JZ",flags)) goto L005a4ba9;
  }
  L005a4bb6: { // 0x5a4bb6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
   { // 0x5a4bb8: 7508 JNZ 0x005a4bc2
    if(integer::condition("JNZ",flags)) goto L005a4bc2;
  }
  L005a4bba: { // 0x5a4bba: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
   { // 0x5a4bbc: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    m.w32((f.sp+0x0000002cu), s.si);
  }
   { // 0x5a4bc0: eb40 JMP 0x005a4c02
    goto L005a4c02;
  }
  L005a4bc2: { // 0x5a4bc2: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
   { // 0x5a4bc4: 8b4c8ffc MOV ECX,dword ptr [EDI + ECX*0x4 + -0x4]
    s.cx = m.r32((s.di+(s.cx * 0x00000004u)-0x00000004u));
  }
   { // 0x5a4bc8: ba00000080 MOV EDX,0x80000000
    s.dx = 0x80000000u;
  }
   { // 0x5a4bcd: c1e005 SHL EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::left);
  }
   { // 0x5a4bd0: 85ca TEST EDX,ECX
    (void)integer::logical((s.dx)&(s.cx),32,flags);
  }
   { // 0x5a4bd2: 7507 JNZ 0x005a4bdb
    if(integer::condition("JNZ",flags)) goto L005a4bdb;
  }
  L005a4bd4: { // 0x5a4bd4: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
   { // 0x5a4bd6: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
   { // 0x5a4bd7: 85ca TEST EDX,ECX
    (void)integer::logical((s.dx)&(s.cx),32,flags);
  }
   { // 0x5a4bd9: 74f9 JZ 0x005a4bd4
    if(integer::condition("JZ",flags)) goto L005a4bd4;
  }
  L005a4bdb: { // 0x5a4bdb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
   { // 0x5a4bdd: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
   { // 0x5a4bdf: 7506 JNZ 0x005a4be7
    if(integer::condition("JNZ",flags)) goto L005a4be7;
  }
   { // 0x5a4be1: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
   { // 0x5a4be5: eb1b JMP 0x005a4c02
    goto L005a4c02;
  }
  L005a4be7: { // 0x5a4be7: 8d48ff LEA ECX,[EAX + -0x1]
    s.cx = (s.ax-0x00000001u);
  }
   { // 0x5a4bea: 81e11f000080 AND ECX,0x8000001f
    s.cx = integer::logical((s.cx)&(0x8000001fu),32,flags);
  }
   { // 0x5a4bf0: 7905 JNS 0x005a4bf7
    if(integer::condition("JNS",flags)) goto L005a4bf7;
  }
   { // 0x5a4bf2: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
   { // 0x5a4bf3: 83c9e0 OR ECX,0xffffffe0
    s.cx = integer::logical((s.cx)|(0xffffffe0u),32,flags);
  }
   { // 0x5a4bf6: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005a4bf7: { // 0x5a4bf7: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
   { // 0x5a4bfc: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
   { // 0x5a4bfe: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L005a4c02: { // 0x5a4c02: 8d461f LEA EAX,[ESI + 0x1f]
    s.ax = (s.si+0x0000001fu);
  }
   { // 0x5a4c05: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x5a4c06: 83e21f AND EDX,0x1f
    s.dx = integer::logical((s.dx)&(0x0000001fu),32,flags);
  }
   { // 0x5a4c09: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x5a4c0b: c1f805 SAR EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x5a4c0e: 0f84bd000000 JZ 0x005a4cd1
    if(integer::condition("JZ",flags)) goto L005a4cd1;
  }
   { // 0x5a4c14: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
   { // 0x5a4c16: 0f84b5000000 JZ 0x005a4cd1
    if(integer::condition("JZ",flags)) goto L005a4cd1;
  }
   { // 0x5a4c1c: 8d4c87fc LEA ECX,[EDI + EAX*0x4 + -0x4]
    s.cx = (s.di+(s.ax * 0x00000004u)-0x00000004u);
  }
   { // 0x5a4c20: 89742420 MOV dword ptr [ESP + 0x20],ESI
    m.w32((f.sp+0x00000020u), s.si);
  }
   { // 0x5a4c24: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L005a4c28: { // 0x5a4c28: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
   { // 0x5a4c2c: 55 PUSH EBP
    f.push(m,s.bp);
  }
   { // 0x5a4c2d: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
   { // 0x5a4c32: e8b9faffff CALL 0x005a46f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005a46f0u,5917751u); flags=s.arithmetic_flags;
  }
   { // 0x5a4c37: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
   { // 0x5a4c3b: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
   { // 0x5a4c3f: 8510 TEST dword ptr [EAX],EDX
    (void)integer::logical((m.r32((s.ax)))&(s.dx),32,flags);
  }
   { // 0x5a4c41: 7460 JZ 0x005a4ca3
    if(integer::condition("JZ",flags)) goto L005a4ca3;
  }
   { // 0x5a4c43: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
   { // 0x5a4c47: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
   { // 0x5a4c49: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
   { // 0x5a4c4b: 885c2414 MOV byte ptr [ESP + 0x14],BL
    m.w8((f.sp+0x00000014u), (s.bx & 0xffu));
  }
   { // 0x5a4c4f: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
   { // 0x5a4c51: 7450 JZ 0x005a4ca3
    if(integer::condition("JZ",flags)) goto L005a4ca3;
  }
   { // 0x5a4c53: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
   { // 0x5a4c57: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
   { // 0x5a4c5b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
   { // 0x5a4c5d: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
   { // 0x5a4c61: 2be8 SUB EBP,EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  L005a4c63: { // 0x5a4c63: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
   { // 0x5a4c65: 8b042e MOV EAX,dword ptr [ESI + EBP*0x1]
    s.ax = m.r32((s.si+(s.bp * 0x00000001u)));
  }
   { // 0x5a4c68: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
   { // 0x5a4c6c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x5a4c6e: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
   { // 0x5a4c74: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
   { // 0x5a4c76: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x5a4c78: 720c JC 0x005a4c86
    if(integer::condition("JC",flags)) goto L005a4c86;
  }
   { // 0x5a4c7a: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
   { // 0x5a4c7c: 7404 JZ 0x005a4c82
    if(integer::condition("JZ",flags)) goto L005a4c82;
  }
   { // 0x5a4c7e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
   { // 0x5a4c80: 7404 JZ 0x005a4c86
    if(integer::condition("JZ",flags)) goto L005a4c86;
  }
  L005a4c82: { // 0x5a4c82: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
   { // 0x5a4c84: eb02 JMP 0x005a4c88
    goto L005a4c88;
  }
  L005a4c86: { // 0x5a4c86: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L005a4c88: { // 0x5a4c88: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
   { // 0x5a4c8c: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
   { // 0x5a4c8e: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
   { // 0x5a4c91: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
   { // 0x5a4c94: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
   { // 0x5a4c95: 885c2414 MOV byte ptr [ESP + 0x14],BL
    m.w8((f.sp+0x00000014u), (s.bx & 0xffu));
  }
   { // 0x5a4c99: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
   { // 0x5a4c9d: 75c4 JNZ 0x005a4c63
    if(integer::condition("JNZ",flags)) goto L005a4c63;
  }
   { // 0x5a4c9f: 8b6c2430 MOV EBP,dword ptr [ESP + 0x30]
    s.bp = m.r32((f.sp+0x00000030u));
  }
  L005a4ca3: { // 0x5a4ca3: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
   { // 0x5a4ca7: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
   { // 0x5a4ca9: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
   { // 0x5a4cad: 7513 JNZ 0x005a4cc2
    if(integer::condition("JNZ",flags)) goto L005a4cc2;
  }
   { // 0x5a4caf: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
   { // 0x5a4cb3: c744242c00000080 MOV dword ptr [ESP + 0x2c],0x80000000
    m.w32((f.sp+0x0000002cu), 0x80000000u);
  }
   { // 0x5a4cbb: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
   { // 0x5a4cbe: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L005a4cc2: { // 0x5a4cc2: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
   { // 0x5a4cc6: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
   { // 0x5a4cc7: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
   { // 0x5a4ccb: 0f8557ffffff JNZ 0x005a4c28
    if(integer::condition("JNZ",flags)) goto L005a4c28;
  }
  L005a4cd1: { // 0x5a4cd1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x5a4cd2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x5a4cd3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
   { // 0x5a4cd4: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
   { // 0x5a4cd6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
   { // 0x5a4cd7: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
   { // 0x5a4cda: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00600f80(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x600f80: 51 PUSH ECX
    f.push(m,s.cx);
  }
   { // 0x600f81: a06c89a200 MOV AL,[0x00a2896c]
    s.ax = with_al(s.ax, m.r8((0x00a2896cu)));
  }
   { // 0x600f86: 55 PUSH EBP
    f.push(m,s.bp);
  }
   { // 0x600f87: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x600f88: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x600f89: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x600f8b: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
   { // 0x600f8d: 0f84d5000000 JZ 0x00601068
    if(integer::condition("JZ",flags)) goto L00601068;
  }
   { // 0x600f93: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
   { // 0x600f98: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
   { // 0x600f9e: e83dee0200 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6295459u); flags=s.arithmetic_flags;
  }
   { // 0x600fa3: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x600fa4: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
   { // 0x600fa6: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x600fa8: a803 TEST AL,0x3
    (void)integer::logical(((s.ax & 0xffu))&(0x00000003u),8,flags);
  }
   { // 0x600faa: 0f85ae000000 JNZ 0x0060105e
    if(integer::condition("JNZ",flags)) goto L0060105e;
  }
   { // 0x600fb0: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
   { // 0x600fb6: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
   { // 0x600fb8: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
   { // 0x600fbe: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
   { // 0x600fc0: e81bee0200 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6295493u); flags=s.arithmetic_flags;
  }
   { // 0x600fc5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x600fc6: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
   { // 0x600fc8: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x600fca: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
   { // 0x600fd0: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x600fd2: 8d8a18020000 LEA ECX,[EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
   { // 0x600fd8: 7517 JNZ 0x00600ff1
    if(integer::condition("JNZ",flags)) goto L00600ff1;
  }
   { // 0x600fda: e801ee0200 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6295519u); flags=s.arithmetic_flags;
  }
   { // 0x600fdf: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x600fe0: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
   { // 0x600fe2: b903000000 MOV ECX,0x3
    s.cx = 0x00000003u;
  }
   { // 0x600fe7: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x600fe9: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x600fea: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
   { // 0x600fec: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
   { // 0x600fee: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
   { // 0x600fef: eb15 JMP 0x00601006
    goto L00601006;
  }
  L00600ff1: { // 0x600ff1: e8eaed0200 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6295542u); flags=s.arithmetic_flags;
  }
   { // 0x600ff6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x600ff7: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
   { // 0x600ff9: b903000000 MOV ECX,0x3
    s.cx = 0x00000003u;
  }
   { // 0x600ffe: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x601000: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x601001: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
   { // 0x601003: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
   { // 0x601005: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00601006: { // 0x601006: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
   { // 0x60100c: b9fbffffff MOV ECX,0xfffffffb
    s.cx = 0xfffffffbu;
  }
   { // 0x601011: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
   { // 0x601013: 8baeb4000000 MOV EBP,dword ptr [ESI + 0xb4]
    s.bp = m.r32((s.si+0x000000b4u));
  }
   { // 0x601019: 03ef ADD EBP,EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
   { // 0x60101b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
   { // 0x60101d: 8986b0000000 MOV dword ptr [ESI + 0xb0],EAX
    m.w32((s.si+0x000000b0u), s.ax);
  }
   { // 0x601023: 89aeb4000000 MOV dword ptr [ESI + 0xb4],EBP
    m.w32((s.si+0x000000b4u), s.bp);
  }
   { // 0x601029: ba05000000 MOV EDX,0x5
    s.dx = 0x00000005u;
  }
   { // 0x60102e: 7d08 JGE 0x00601038
    if(integer::condition("JGE",flags)) goto L00601038;
  }
   { // 0x601030: 898eb0000000 MOV dword ptr [ESI + 0xb0],ECX
    m.w32((s.si+0x000000b0u), s.cx);
  }
   { // 0x601036: eb0a JMP 0x00601042
    goto L00601042;
  }
  L00601038: { // 0x601038: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x60103a: 7e06 JLE 0x00601042
    if(integer::condition("JLE",flags)) goto L00601042;
  }
   { // 0x60103c: 8996b0000000 MOV dword ptr [ESI + 0xb0],EDX
    m.w32((s.si+0x000000b0u), s.dx);
  }
  L00601042: { // 0x601042: 8b86b4000000 MOV EAX,dword ptr [ESI + 0xb4]
    s.ax = m.r32((s.si+0x000000b4u));
  }
   { // 0x601048: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
   { // 0x60104a: 7d08 JGE 0x00601054
    if(integer::condition("JGE",flags)) goto L00601054;
  }
   { // 0x60104c: 898eb4000000 MOV dword ptr [ESI + 0xb4],ECX
    m.w32((s.si+0x000000b4u), s.cx);
  }
   { // 0x601052: eb0a JMP 0x0060105e
    goto L0060105e;
  }
  L00601054: { // 0x601054: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x601056: 7e06 JLE 0x0060105e
    if(integer::condition("JLE",flags)) goto L0060105e;
  }
   { // 0x601058: 8996b4000000 MOV dword ptr [ESI + 0xb4],EDX
    m.w32((s.si+0x000000b4u), s.dx);
  }
  L0060105e: { // 0x60105e: c786b800000000000000 MOV dword ptr [ESI + 0xb8],0x0
    m.w32((s.si+0x000000b8u), 0x00000000u);
  }
  L00601068: { // 0x601068: 8bae98000000 MOV EBP,dword ptr [ESI + 0x98]
    s.bp = m.r32((s.si+0x00000098u));
  }
   { // 0x60106e: 8a961e010000 MOV DL,byte ptr [ESI + 0x11e]
    s.dx = with_al(s.dx, m.r8((s.si+0x0000011eu)));
  }
   { // 0x601074: 3a95d9020000 CMP DL,byte ptr [EBP + 0x2d9]
    (void)integer::sub((s.dx & 0xffu),m.r8((s.bp+0x000002d9u)),8,flags);
  }
   { // 0x60107a: 7d6f JGE 0x006010eb
    if(integer::condition("JGE",flags)) goto L006010eb;
  }
   { // 0x60107c: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
   { // 0x60107f: 8d7e04 LEA EDI,[ESI + 0x4]
    s.di = (s.si+0x00000004u);
  }
   { // 0x601082: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x601083: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),6295686u); flags=s.arithmetic_flags;
  }
   { // 0x601086: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
   { // 0x601088: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
   { // 0x60108e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
   { // 0x601090: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x601091: 668b8e18010000 MOV CX,word ptr [ESI + 0x118]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000118u)));
  }
   { // 0x601098: 8b80b0020000 MOV EAX,dword ptr [EAX + 0x2b0]
    s.ax = m.r32((s.ax+0x000002b0u));
  }
   { // 0x60109e: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
   { // 0x6010a0: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
   { // 0x6010a2: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
   { // 0x6010a4: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
   { // 0x6010a8: ff5110 CALL dword ptr [ECX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000010u)),6295723u); flags=s.arithmetic_flags;
  }
   { // 0x6010ab: 0fbe95db020000 MOVSX EDX,byte ptr [EBP + 0x2db]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.bp+0x000002dbu)),8));
  }
   { // 0x6010b2: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
   { // 0x6010b4: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
   { // 0x6010b8: 83e101 AND ECX,0x1
    s.cx = integer::logical((s.cx)&(0x00000001u),32,flags);
  }
   { // 0x6010bb: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
   { // 0x6010bd: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x6010be: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
   { // 0x6010c0: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
   { // 0x6010c2: 7506 JNZ 0x006010ca
    if(integer::condition("JNZ",flags)) goto L006010ca;
  }
   { // 0x6010c4: fe861e010000 INC byte ptr [ESI + 0x11e]
    m.w8((s.si+0x0000011eu), integer::increment(m.r8((s.si+0x0000011eu)),8,flags));
  }
  L006010ca: { // 0x6010ca: 8a8e1e010000 MOV CL,byte ptr [ESI + 0x11e]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000011eu)));
  }
   { // 0x6010d0: 8a85d9020000 MOV AL,byte ptr [EBP + 0x2d9]
    s.ax = with_al(s.ax, m.r8((s.bp+0x000002d9u)));
  }
   { // 0x6010d6: 3ac8 CMP CL,AL
    (void)integer::sub((s.cx & 0xffu),(s.ax & 0xffu),8,flags);
  }
   { // 0x6010d8: 7511 JNZ 0x006010eb
    if(integer::condition("JNZ",flags)) goto L006010eb;
  }
   { // 0x6010da: 8a85d8020000 MOV AL,byte ptr [EBP + 0x2d8]
    s.ax = with_al(s.ax, m.r8((s.bp+0x000002d8u)));
  }
   { // 0x6010e0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
   { // 0x6010e2: 7407 JZ 0x006010eb
    if(integer::condition("JZ",flags)) goto L006010eb;
  }
   { // 0x6010e4: c6862101000001 MOV byte ptr [ESI + 0x121],0x1
    m.w8((s.si+0x00000121u), 0x00000001u);
  }
  L006010eb: { // 0x6010eb: d986d4000000 FLD float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    s.fp.load32(m.r32(address));
  }
   { // 0x6010f1: dc1d887a7800 FCOMP double ptr [0x00787a88]
    const auto address=(0x00787a88u);
    s.fp.compare_pop64(read64(m,address));
  }
   { // 0x6010f7: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x6010f9: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
   { // 0x6010fc: 7512 JNZ 0x00601110
    if(integer::condition("JNZ",flags)) goto L00601110;
  }
   { // 0x6010fe: d986d4000000 FLD float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    s.fp.load32(m.r32(address));
  }
   { // 0x601104: d8a5d0020000 FSUB float ptr [EBP + 0x2d0]
    const auto address=(s.bp+0x000002d0u);
    s.fp.subtract32(m.r32(address));
  }
   { // 0x60110a: d99ed4000000 FSTP float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00601110: { // 0x601110: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x601111: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x601112: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
   { // 0x601113: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
   { // 0x601114: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0062d140(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x62d140: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x62d141: 55 PUSH EBP
    f.push(m,s.bp);
  }
   { // 0x62d142: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x62d143: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
   { // 0x62d145: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x62d146: dd4658 FLD double ptr [ESI + 0x58]
    const auto address=(s.si+0x00000058u);
    s.fp.load64(read64(m,address));
  }
   { // 0x62d149: dc7610 FDIV double ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    s.fp.divide64(read64(m,address));
  }
   { // 0x62d14c: e8ffd81300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6476113u); flags=s.arithmetic_flags;
  }
   { // 0x62d151: 8b7e4c MOV EDI,dword ptr [ESI + 0x4c]
    s.di = m.r32((s.si+0x0000004cu));
  }
   { // 0x62d154: 8b5e50 MOV EBX,dword ptr [ESI + 0x50]
    s.bx = m.r32((s.si+0x00000050u));
  }
   { // 0x62d157: 8b6e54 MOV EBP,dword ptr [ESI + 0x54]
    s.bp = m.r32((s.si+0x00000054u));
  }
   { // 0x62d15a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
   { // 0x62d15c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
   { // 0x62d15e: 894e7c MOV dword ptr [ESI + 0x7c],ECX
    m.w32((s.si+0x0000007cu), s.cx);
  }
   { // 0x62d161: 7415 JZ 0x0062d178
    if(integer::condition("JZ",flags)) goto L0062d178;
  }
   { // 0x62d163: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
   { // 0x62d165: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x62d166: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
   { // 0x62d168: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
   { // 0x62d16a: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
   { // 0x62d16c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x62d16d: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
   { // 0x62d16f: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
   { // 0x62d171: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
   { // 0x62d173: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x62d174: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
   { // 0x62d176: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0062d178: { // 0x62d178: db466c FILD dword ptr [ESI + 0x6c]
    const auto address=(s.si+0x0000006cu);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d17b: da7634 FIDIV dword ptr [ESI + 0x34]
    const auto address=(s.si+0x00000034u);
    s.fp.divide_integer32(m.r32(address));
  }
   { // 0x62d17e: 8d8680000000 LEA EAX,[ESI + 0x80]
    s.ax = (s.si+0x00000080u);
  }
   { // 0x62d184: 8d4e1c LEA ECX,[ESI + 0x1c]
    s.cx = (s.si+0x0000001cu);
  }
   { // 0x62d187: 8d968c000000 LEA EDX,[ESI + 0x8c]
    s.dx = (s.si+0x0000008cu);
  }
   { // 0x62d18d: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
   { // 0x62d18f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x62d190: 895804 MOV dword ptr [EAX + 0x4],EBX
    m.w32((s.ax+0x00000004u), s.bx);
  }
   { // 0x62d193: 896808 MOV dword ptr [EAX + 0x8],EBP
    m.w32((s.ax+0x00000008u), s.bp);
  }
   { // 0x62d196: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
   { // 0x62d198: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
   { // 0x62d19a: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
   { // 0x62d19d: 894204 MOV dword ptr [EDX + 0x4],EAX
    m.w32((s.dx+0x00000004u), s.ax);
  }
   { // 0x62d1a0: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
   { // 0x62d1a3: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
   { // 0x62d1a6: 8d5618 LEA EDX,[ESI + 0x18]
    s.dx = (s.si+0x00000018u);
  }
   { // 0x62d1a9: 81c6b0000000 ADD ESI,0xb0
    s.si = integer::add(s.si,0x000000b0u,32,flags);
  }
   { // 0x62d1af: 668b02 MOV AX,word ptr [EDX]
    s.ax = with_ax(s.ax, m.r16((s.dx)));
  }
   { // 0x62d1b2: 8a4a02 MOV CL,byte ptr [EDX + 0x2]
    s.cx = with_al(s.cx, m.r8((s.dx+0x00000002u)));
  }
   { // 0x62d1b5: dc4e88 FMUL double ptr [ESI + -0x78]
    const auto address=(s.si-0x00000078u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x62d1b8: dd5ec0 FSTP double ptr [ESI + -0x40]
    const auto address=(s.si-0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x62d1bb: 668906 MOV word ptr [ESI],AX
    m.w16((s.si), (s.ax & 0xffffu));
  }
   { // 0x62d1be: 884e02 MOV byte ptr [ESI + 0x2],CL
    m.w8((s.si+0x00000002u), (s.cx & 0xffu));
  }
   { // 0x62d1c1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x62d1c2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
   { // 0x62d1c3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
   { // 0x62d1c4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0062d1d0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x62d1d0: 55 PUSH EBP
    f.push(m,s.bp);
  }
   { // 0x62d1d1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
   { // 0x62d1d3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
   { // 0x62d1d6: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
   { // 0x62d1d9: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x62d1da: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
   { // 0x62d1dc: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x62d1dd: dd4658 FLD double ptr [ESI + 0x58]
    const auto address=(s.si+0x00000058u);
    s.fp.load64(read64(m,address));
  }
   { // 0x62d1e0: dc1d58387900 FCOMP double ptr [0x00793858]
    const auto address=(0x00793858u);
    s.fp.compare_pop64(read64(m,address));
  }
   { // 0x62d1e6: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x62d1e8: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x62d1eb: 7408 JZ 0x0062d1f5
    if(integer::condition("JZ",flags)) goto L0062d1f5;
  }
   { // 0x62d1ed: dd0558387900 FLD double ptr [0x00793858]
    const auto address=(0x00793858u);
    s.fp.load64(read64(m,address));
  }
   { // 0x62d1f3: eb03 JMP 0x0062d1f8
    goto L0062d1f8;
  }
  L0062d1f5: { // 0x62d1f5: dd4658 FLD double ptr [ESI + 0x58]
    const auto address=(s.si+0x00000058u);
    s.fp.load64(read64(m,address));
  }
  L0062d1f8: { // 0x62d1f8: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
   { // 0x62d1fa: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
   { // 0x62d1fd: dd542418 FST double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
   { // 0x62d201: db4678 FILD dword ptr [ESI + 0x78]
    const auto address=(s.si+0x00000078u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d204: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x62d208: db467c FILD dword ptr [ESI + 0x7c]
    const auto address=(s.si+0x0000007cu);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d20b: dc7c2410 FDIVR double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    reverse_divide64(s.fp,read64(m,address));
  }
   { // 0x62d20f: dec9 FMULP
    numeric_b88::detail::reg<0xdec9>(s.fp);
  }
   { // 0x62d211: dd0530817d00 FLD double ptr [0x007d8130]
    const auto address=(0x007d8130u);
    s.fp.load64(read64(m,address));
  }
   { // 0x62d217: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x62d219: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x62d21c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x62d21e: e8cdcee8ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,6476323u); flags=s.arithmetic_flags;
  }
   { // 0x62d223: dc4e70 FMUL double ptr [ESI + 0x70]
    const auto address=(s.si+0x00000070u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x62d226: dd442410 FLD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
   { // 0x62d22a: e821d81300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6476335u); flags=s.arithmetic_flags;
  }
   { // 0x62d22f: 8b8e80000000 MOV ECX,dword ptr [ESI + 0x80]
    s.cx = m.r32((s.si+0x00000080u));
  }
   { // 0x62d235: 8b9684000000 MOV EDX,dword ptr [ESI + 0x84]
    s.dx = m.r32((s.si+0x00000084u));
  }
   { // 0x62d23b: 8bbe88000000 MOV EDI,dword ptr [ESI + 0x88]
    s.di = m.r32((s.si+0x00000088u));
  }
   { // 0x62d241: 0fafc8 IMUL ECX,EAX
    s.cx = integer::imul(s.cx,s.ax,32,flags);
  }
   { // 0x62d244: 0fafd0 IMUL EDX,EAX
    s.dx = integer::imul(s.dx,s.ax,32,flags);
  }
   { // 0x62d247: 0faff8 IMUL EDI,EAX
    s.di = integer::imul(s.di,s.ax,32,flags);
  }
   { // 0x62d24a: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
   { // 0x62d24d: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
   { // 0x62d24f: 8b4e20 MOV ECX,dword ptr [ESI + 0x20]
    s.cx = m.r32((s.si+0x00000020u));
  }
   { // 0x62d252: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
   { // 0x62d254: 8b5624 MOV EDX,dword ptr [ESI + 0x24]
    s.dx = m.r32((s.si+0x00000024u));
  }
   { // 0x62d257: 03d7 ADD EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
   { // 0x62d259: 8dbe8c000000 LEA EDI,[ESI + 0x8c]
    s.di = (s.si+0x0000008cu);
  }
   { // 0x62d25f: 89868c000000 MOV dword ptr [ESI + 0x8c],EAX
    m.w32((s.si+0x0000008cu), s.ax);
  }
   { // 0x62d265: 894f04 MOV dword ptr [EDI + 0x4],ECX
    m.w32((s.di+0x00000004u), s.cx);
  }
   { // 0x62d268: 895708 MOV dword ptr [EDI + 0x8],EDX
    m.w32((s.di+0x00000008u), s.dx);
  }
   { // 0x62d26b: db8694000000 FILD dword ptr [ESI + 0x94]
    const auto address=(s.si+0x00000094u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d271: d8c1 FADD ST0,ST1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
   { // 0x62d273: e8d8d71300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6476408u); flags=s.arithmetic_flags;
  }
   { // 0x62d278: 898694000000 MOV dword ptr [ESI + 0x94],EAX
    m.w32((s.si+0x00000094u), s.ax);
  }
   { // 0x62d27e: 8b4678 MOV EAX,dword ptr [ESI + 0x78]
    s.ax = m.r32((s.si+0x00000078u));
  }
   { // 0x62d281: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
   { // 0x62d282: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x62d284: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
   { // 0x62d288: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d28c: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x62d290: db467c FILD dword ptr [ESI + 0x7c]
    const auto address=(s.si+0x0000007cu);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d293: dc7c2410 FDIVR double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    reverse_divide64(s.fp,read64(m,address));
  }
   { // 0x62d297: dc4c2418 FMUL double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x62d29b: dd0530817d00 FLD double ptr [0x007d8130]
    const auto address=(0x007d8130u);
    s.fp.load64(read64(m,address));
  }
   { // 0x62d2a1: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x62d2a3: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x62d2a6: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x62d2a8: e843cee8ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,6476461u); flags=s.arithmetic_flags;
  }
   { // 0x62d2ad: dc4e70 FMUL double ptr [ESI + 0x70]
    const auto address=(s.si+0x00000070u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x62d2b0: dd442410 FLD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
   { // 0x62d2b4: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
   { // 0x62d2b7: e894d71300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6476476u); flags=s.arithmetic_flags;
  }
   { // 0x62d2bc: 8b8e80000000 MOV ECX,dword ptr [ESI + 0x80]
    s.cx = m.r32((s.si+0x00000080u));
  }
   { // 0x62d2c2: 8b9684000000 MOV EDX,dword ptr [ESI + 0x84]
    s.dx = m.r32((s.si+0x00000084u));
  }
   { // 0x62d2c8: 8bbe88000000 MOV EDI,dword ptr [ESI + 0x88]
    s.di = m.r32((s.si+0x00000088u));
  }
   { // 0x62d2ce: 0fafc8 IMUL ECX,EAX
    s.cx = integer::imul(s.cx,s.ax,32,flags);
  }
   { // 0x62d2d1: 0fafd0 IMUL EDX,EAX
    s.dx = integer::imul(s.dx,s.ax,32,flags);
  }
   { // 0x62d2d4: 0faff8 IMUL EDI,EAX
    s.di = integer::imul(s.di,s.ax,32,flags);
  }
   { // 0x62d2d7: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
   { // 0x62d2da: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
   { // 0x62d2dc: 8b4620 MOV EAX,dword ptr [ESI + 0x20]
    s.ax = m.r32((s.si+0x00000020u));
  }
   { // 0x62d2df: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x62d2e1: 8b5624 MOV EDX,dword ptr [ESI + 0x24]
    s.dx = m.r32((s.si+0x00000024u));
  }
   { // 0x62d2e4: 03d7 ADD EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
   { // 0x62d2e6: 8dbe98000000 LEA EDI,[ESI + 0x98]
    s.di = (s.si+0x00000098u);
  }
   { // 0x62d2ec: 898e98000000 MOV dword ptr [ESI + 0x98],ECX
    m.w32((s.si+0x00000098u), s.cx);
  }
   { // 0x62d2f2: 894704 MOV dword ptr [EDI + 0x4],EAX
    m.w32((s.di+0x00000004u), s.ax);
  }
   { // 0x62d2f5: 895708 MOV dword ptr [EDI + 0x8],EDX
    m.w32((s.di+0x00000008u), s.dx);
  }
   { // 0x62d2f8: db86a0000000 FILD dword ptr [ESI + 0xa0]
    const auto address=(s.si+0x000000a0u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d2fe: d8c1 FADD ST0,ST1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
   { // 0x62d300: e84bd71300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6476549u); flags=s.arithmetic_flags;
  }
   { // 0x62d305: 8986a0000000 MOV dword ptr [ESI + 0xa0],EAX
    m.w32((s.si+0x000000a0u), s.ax);
  }
   { // 0x62d30b: e840d71300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6476560u); flags=s.arithmetic_flags;
  }
   { // 0x62d310: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x62d311: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
   { // 0x62d313: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x62d315: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
   { // 0x62d317: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
   { // 0x62d31b: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
   { // 0x62d31d: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d321: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
   { // 0x62d323: 8a4618 MOV AL,byte ptr [ESI + 0x18]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000018u)));
  }
   { // 0x62d326: dc0d28577800 FMUL double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x62d32c: dc7638 FDIV double ptr [ESI + 0x38]
    const auto address=(s.si+0x00000038u);
    s.fp.divide64(read64(m,address));
  }
   { // 0x62d32f: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
   { // 0x62d335: dd96a8000000 FST double ptr [ESI + 0xa8]
    const auto address=(s.si+0x000000a8u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
   { // 0x62d33b: 8a4e19 MOV CL,byte ptr [ESI + 0x19]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000019u)));
  }
   { // 0x62d33e: 8a561a MOV DL,byte ptr [ESI + 0x1a]
    s.dx = with_al(s.dx, m.r8((s.si+0x0000001au)));
  }
   { // 0x62d341: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
   { // 0x62d345: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d349: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
   { // 0x62d34d: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x62d34f: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x62d353: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d357: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
   { // 0x62d35b: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x62d35d: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x62d361: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d365: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x62d367: e8e4d61300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6476652u); flags=s.arithmetic_flags;
  }
   { // 0x62d36c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x62d36e: dd442410 FLD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
   { // 0x62d372: 8886b0000000 MOV byte ptr [ESI + 0xb0],AL
    m.w8((s.si+0x000000b0u), (s.ax & 0xffu));
  }
   { // 0x62d378: e8d3d61300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6476669u); flags=s.arithmetic_flags;
  }
   { // 0x62d37d: dd442418 FLD double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load64(read64(m,address));
  }
   { // 0x62d381: 8886b1000000 MOV byte ptr [ESI + 0xb1],AL
    m.w8((s.si+0x000000b1u), (s.ax & 0xffu));
  }
   { // 0x62d387: e8c4d61300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6476684u); flags=s.arithmetic_flags;
  }
   { // 0x62d38c: 8886b2000000 MOV byte ptr [ESI + 0xb2],AL
    m.w8((s.si+0x000000b2u), (s.ax & 0xffu));
  }
   { // 0x62d392: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x62d393: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x62d394: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
   { // 0x62d396: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
   { // 0x62d397: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0062d6d0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x62d6d0: 55 PUSH EBP
    f.push(m,s.bp);
  }
   { // 0x62d6d1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
   { // 0x62d6d3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
   { // 0x62d6d6: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
   { // 0x62d6d9: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x62d6da: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
   { // 0x62d6dc: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x62d6dd: db4678 FILD dword ptr [ESI + 0x78]
    const auto address=(s.si+0x00000078u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d6e0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
   { // 0x62d6e3: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x62d6e7: db467c FILD dword ptr [ESI + 0x7c]
    const auto address=(s.si+0x0000007cu);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d6ea: dc7c2410 FDIVR double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    reverse_divide64(s.fp,read64(m,address));
  }
   { // 0x62d6ee: dc0d60387900 FMUL double ptr [0x00793860]
    const auto address=(0x00793860u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x62d6f4: dd0530817d00 FLD double ptr [0x007d8130]
    const auto address=(0x007d8130u);
    s.fp.load64(read64(m,address));
  }
   { // 0x62d6fa: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x62d6fc: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x62d6ff: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x62d701: e8eac9e8ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,6477574u); flags=s.arithmetic_flags;
  }
   { // 0x62d706: dc4e70 FMUL double ptr [ESI + 0x70]
    const auto address=(s.si+0x00000070u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x62d709: dd442410 FLD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
   { // 0x62d70d: e83ed31300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6477586u); flags=s.arithmetic_flags;
  }
   { // 0x62d712: 8b8e80000000 MOV ECX,dword ptr [ESI + 0x80]
    s.cx = m.r32((s.si+0x00000080u));
  }
   { // 0x62d718: 8b9684000000 MOV EDX,dword ptr [ESI + 0x84]
    s.dx = m.r32((s.si+0x00000084u));
  }
   { // 0x62d71e: 8bbe88000000 MOV EDI,dword ptr [ESI + 0x88]
    s.di = m.r32((s.si+0x00000088u));
  }
   { // 0x62d724: 0fafc8 IMUL ECX,EAX
    s.cx = integer::imul(s.cx,s.ax,32,flags);
  }
   { // 0x62d727: 0fafd0 IMUL EDX,EAX
    s.dx = integer::imul(s.dx,s.ax,32,flags);
  }
   { // 0x62d72a: 0faff8 IMUL EDI,EAX
    s.di = integer::imul(s.di,s.ax,32,flags);
  }
   { // 0x62d72d: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
   { // 0x62d730: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
   { // 0x62d732: 8b4e20 MOV ECX,dword ptr [ESI + 0x20]
    s.cx = m.r32((s.si+0x00000020u));
  }
   { // 0x62d735: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
   { // 0x62d737: 8b5624 MOV EDX,dword ptr [ESI + 0x24]
    s.dx = m.r32((s.si+0x00000024u));
  }
   { // 0x62d73a: 03d7 ADD EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
   { // 0x62d73c: 8dbe8c000000 LEA EDI,[ESI + 0x8c]
    s.di = (s.si+0x0000008cu);
  }
   { // 0x62d742: 89868c000000 MOV dword ptr [ESI + 0x8c],EAX
    m.w32((s.si+0x0000008cu), s.ax);
  }
   { // 0x62d748: 894f04 MOV dword ptr [EDI + 0x4],ECX
    m.w32((s.di+0x00000004u), s.cx);
  }
   { // 0x62d74b: 895708 MOV dword ptr [EDI + 0x8],EDX
    m.w32((s.di+0x00000008u), s.dx);
  }
   { // 0x62d74e: db8694000000 FILD dword ptr [ESI + 0x94]
    const auto address=(s.si+0x00000094u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d754: d8c1 FADD ST0,ST1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
   { // 0x62d756: e8f5d21300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6477659u); flags=s.arithmetic_flags;
  }
   { // 0x62d75b: 898694000000 MOV dword ptr [ESI + 0x94],EAX
    m.w32((s.si+0x00000094u), s.ax);
  }
   { // 0x62d761: 8b4678 MOV EAX,dword ptr [ESI + 0x78]
    s.ax = m.r32((s.si+0x00000078u));
  }
   { // 0x62d764: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
   { // 0x62d765: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x62d767: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
   { // 0x62d76b: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d76f: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x62d773: db467c FILD dword ptr [ESI + 0x7c]
    const auto address=(s.si+0x0000007cu);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d776: dc7c2410 FDIVR double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    reverse_divide64(s.fp,read64(m,address));
  }
   { // 0x62d77a: dc0d60387900 FMUL double ptr [0x00793860]
    const auto address=(0x00793860u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x62d780: dd0530817d00 FLD double ptr [0x007d8130]
    const auto address=(0x007d8130u);
    s.fp.load64(read64(m,address));
  }
   { // 0x62d786: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x62d788: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x62d78b: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x62d78d: e85ec9e8ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,6477714u); flags=s.arithmetic_flags;
  }
   { // 0x62d792: dc4e70 FMUL double ptr [ESI + 0x70]
    const auto address=(s.si+0x00000070u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x62d795: dd442410 FLD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
   { // 0x62d799: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
   { // 0x62d79c: e8afd21300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6477729u); flags=s.arithmetic_flags;
  }
   { // 0x62d7a1: 8b8e80000000 MOV ECX,dword ptr [ESI + 0x80]
    s.cx = m.r32((s.si+0x00000080u));
  }
   { // 0x62d7a7: 8b9684000000 MOV EDX,dword ptr [ESI + 0x84]
    s.dx = m.r32((s.si+0x00000084u));
  }
   { // 0x62d7ad: 8bbe88000000 MOV EDI,dword ptr [ESI + 0x88]
    s.di = m.r32((s.si+0x00000088u));
  }
   { // 0x62d7b3: 0fafc8 IMUL ECX,EAX
    s.cx = integer::imul(s.cx,s.ax,32,flags);
  }
   { // 0x62d7b6: 0fafd0 IMUL EDX,EAX
    s.dx = integer::imul(s.dx,s.ax,32,flags);
  }
   { // 0x62d7b9: 0faff8 IMUL EDI,EAX
    s.di = integer::imul(s.di,s.ax,32,flags);
  }
   { // 0x62d7bc: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
   { // 0x62d7bf: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
   { // 0x62d7c1: 8b4e20 MOV ECX,dword ptr [ESI + 0x20]
    s.cx = m.r32((s.si+0x00000020u));
  }
   { // 0x62d7c4: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
   { // 0x62d7c6: 8b5624 MOV EDX,dword ptr [ESI + 0x24]
    s.dx = m.r32((s.si+0x00000024u));
  }
   { // 0x62d7c9: 03d7 ADD EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
   { // 0x62d7cb: 8dbe98000000 LEA EDI,[ESI + 0x98]
    s.di = (s.si+0x00000098u);
  }
   { // 0x62d7d1: 898698000000 MOV dword ptr [ESI + 0x98],EAX
    m.w32((s.si+0x00000098u), s.ax);
  }
   { // 0x62d7d7: 894f04 MOV dword ptr [EDI + 0x4],ECX
    m.w32((s.di+0x00000004u), s.cx);
  }
   { // 0x62d7da: 895708 MOV dword ptr [EDI + 0x8],EDX
    m.w32((s.di+0x00000008u), s.dx);
  }
   { // 0x62d7dd: db86a0000000 FILD dword ptr [ESI + 0xa0]
    const auto address=(s.si+0x000000a0u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d7e3: d8c1 FADD ST0,ST1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
   { // 0x62d7e5: e866d21300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6477802u); flags=s.arithmetic_flags;
  }
   { // 0x62d7ea: 8986a0000000 MOV dword ptr [ESI + 0xa0],EAX
    m.w32((s.si+0x000000a0u), s.ax);
  }
   { // 0x62d7f0: e85bd21300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6477813u); flags=s.arithmetic_flags;
  }
   { // 0x62d7f5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x62d7f6: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
   { // 0x62d7f8: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
   { // 0x62d7fa: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x62d7fc: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
   { // 0x62d7fe: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
   { // 0x62d802: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
   { // 0x62d804: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d808: 8a4618 MOV AL,byte ptr [ESI + 0x18]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000018u)));
  }
   { // 0x62d80b: dc0d28577800 FMUL double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x62d811: dc7638 FDIV double ptr [ESI + 0x38]
    const auto address=(s.si+0x00000038u);
    s.fp.divide64(read64(m,address));
  }
   { // 0x62d814: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
   { // 0x62d81a: dd96a8000000 FST double ptr [ESI + 0xa8]
    const auto address=(s.si+0x000000a8u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
   { // 0x62d820: 8a4e19 MOV CL,byte ptr [ESI + 0x19]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000019u)));
  }
   { // 0x62d823: 8a561a MOV DL,byte ptr [ESI + 0x1a]
    s.dx = with_al(s.dx, m.r8((s.si+0x0000001au)));
  }
   { // 0x62d826: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
   { // 0x62d82a: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d82e: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
   { // 0x62d832: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x62d834: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x62d838: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d83c: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
   { // 0x62d840: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x62d842: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x62d846: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x62d84a: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x62d84c: e8ffd11300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6477905u); flags=s.arithmetic_flags;
  }
   { // 0x62d851: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x62d853: dd442410 FLD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
   { // 0x62d857: 8886b0000000 MOV byte ptr [ESI + 0xb0],AL
    m.w8((s.si+0x000000b0u), (s.ax & 0xffu));
  }
   { // 0x62d85d: e8eed11300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6477922u); flags=s.arithmetic_flags;
  }
   { // 0x62d862: dd442418 FLD double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load64(read64(m,address));
  }
   { // 0x62d866: 8886b1000000 MOV byte ptr [ESI + 0xb1],AL
    m.w8((s.si+0x000000b1u), (s.ax & 0xffu));
  }
   { // 0x62d86c: e8dfd11300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6477937u); flags=s.arithmetic_flags;
  }
   { // 0x62d871: 8886b2000000 MOV byte ptr [ESI + 0xb2],AL
    m.w8((s.si+0x000000b2u), (s.ax & 0xffu));
  }
   { // 0x62d877: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x62d878: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x62d879: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
   { // 0x62d87b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
   { // 0x62d87c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00698150(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x698150: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
   { // 0x698154: 8b157060aa00 MOV EDX,dword ptr [0x00aa6070]
    s.dx = m.r32((0x00aa6070u));
  }
   { // 0x69815a: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
   { // 0x69815d: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x69815e: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x69815f: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
   { // 0x698161: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
   { // 0x698163: 0f8d9e000000 JGE 0x00698207
    if(integer::condition("JGE",flags)) goto L00698207;
  }
   { // 0x698169: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
   { // 0x69816c: a17460aa00 MOV EAX,[0x00aa6074]
    s.ax = m.r32((0x00aa6074u));
  }
   { // 0x698171: 8b156c60aa00 MOV EDX,dword ptr [0x00aa606c]
    s.dx = m.r32((0x00aa606cu));
  }
   { // 0x698177: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
   { // 0x698179: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
   { // 0x69817b: 0f8d86000000 JGE 0x00698207
    if(integer::condition("JGE",flags)) goto L00698207;
  }
   { // 0x698181: 8b81b0000000 MOV EAX,dword ptr [ECX + 0xb0]
    s.ax = m.r32((s.cx+0x000000b0u));
  }
   { // 0x698187: 8b91b4000000 MOV EDX,dword ptr [ECX + 0xb4]
    s.dx = m.r32((s.cx+0x000000b4u));
  }
   { // 0x69818d: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
   { // 0x69818f: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
   { // 0x698191: 897c2408 MOV dword ptr [ESP + 0x8],EDI
    m.w32((f.sp+0x00000008u), s.di);
  }
   { // 0x698195: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
   { // 0x698199: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x69819d: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
   { // 0x6981a1: 8d91e40d0000 LEA EDX,[ECX + 0xde4]
    s.dx = (s.cx+0x00000de4u);
  }
   { // 0x6981a7: 50 PUSH EAX
    f.push(m,s.ax);
  }
   { // 0x6981a8: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
   { // 0x6981ac: d95c2418 FSTP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x6981b0: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x6981b4: c744242000000000 MOV dword ptr [ESP + 0x20],0x0
    m.w32((f.sp+0x00000020u), 0x00000000u);
  }
   { // 0x6981bc: d95c241c FSTP float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x6981c0: e8bb5fefff CALL 0x0058e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e180u,6914501u); flags=s.arithmetic_flags;
  }
   { // 0x6981c5: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
   { // 0x6981c7: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
   { // 0x6981cb: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
   { // 0x6981ce: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
   { // 0x6981d2: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
   { // 0x6981d6: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
   { // 0x6981d9: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
   { // 0x6981dd: e86e280d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914530u); flags=s.arithmetic_flags;
  }
   { // 0x6981e2: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
   { // 0x6981e6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
   { // 0x6981e8: e863280d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914541u); flags=s.arithmetic_flags;
  }
   { // 0x6981ed: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
   { // 0x6981f1: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
   { // 0x6981f3: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
   { // 0x6981f5: 8937 MOV dword ptr [EDI],ESI
    m.w32((s.di), s.si);
  }
   { // 0x6981f7: 894704 MOV dword ptr [EDI + 0x4],EAX
    m.w32((s.di+0x00000004u), s.ax);
  }
   { // 0x6981fa: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
   { // 0x6981fc: 894f08 MOV dword ptr [EDI + 0x8],ECX
    m.w32((s.di+0x00000008u), s.cx);
  }
   { // 0x6981ff: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x698200: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x698201: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
   { // 0x698204: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00698207: { // 0x698207: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
   { // 0x69820b: 8b154860aa00 MOV EDX,dword ptr [0x00aa6048]
    s.dx = m.r32((0x00aa6048u));
  }
   { // 0x698211: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
   { // 0x698213: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x698214: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x698215: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
   { // 0x698217: 8b154c60aa00 MOV EDX,dword ptr [0x00aa604c]
    s.dx = m.r32((0x00aa604cu));
  }
   { // 0x69821d: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
   { // 0x698220: 8b155060aa00 MOV EDX,dword ptr [0x00aa6050]
    s.dx = m.r32((0x00aa6050u));
  }
   { // 0x698226: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
   { // 0x698229: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
   { // 0x69822c: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006982f0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x6982f0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
   { // 0x6982f3: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
   { // 0x6982f7: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x6982f8: 55 PUSH EBP
    f.push(m,s.bp);
  }
   { // 0x6982f9: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
   { // 0x6982fd: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x6982fe: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
   { // 0x698300: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x698301: c744242000000000 MOV dword ptr [ESP + 0x20],0x0
    m.w32((f.sp+0x00000020u), 0x00000000u);
  }
   { // 0x698309: c786dc00000000000000 MOV dword ptr [ESI + 0xdc],0x0
    m.w32((s.si+0x000000dcu), 0x00000000u);
  }
   { // 0x698313: 8b0c85a4017e00 MOV ECX,dword ptr [EAX*0x4 + 0x7e01a4]
    s.cx = m.r32(((s.ax * 0x00000004u)+0x007e01a4u));
  }
   { // 0x69831a: 898ed8000000 MOV dword ptr [ESI + 0xd8],ECX
    m.w32((s.si+0x000000d8u), s.cx);
  }
   { // 0x698320: 8b7d00 MOV EDI,dword ptr [EBP]
    s.di = m.r32((s.bp));
  }
   { // 0x698323: 8b5504 MOV EDX,dword ptr [EBP + 0x4]
    s.dx = m.r32((s.bp+0x00000004u));
  }
   { // 0x698326: 8b6d08 MOV EBP,dword ptr [EBP + 0x8]
    s.bp = m.r32((s.bp+0x00000008u));
  }
   { // 0x698329: 8d047f LEA EAX,[EDI + EDI*0x2]
    s.ax = (s.di+(s.di * 0x00000002u));
  }
   { // 0x69832c: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
   { // 0x698330: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
   { // 0x698334: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
   { // 0x698338: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
   { // 0x69833b: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
   { // 0x69833e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x69833f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x698341: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
   { // 0x698343: 8d047f LEA EAX,[EDI + EDI*0x2]
    s.ax = (s.di+(s.di * 0x00000002u));
  }
   { // 0x698346: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x698348: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
   { // 0x69834b: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
   { // 0x69834d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x69834e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x698350: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
   { // 0x698352: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
   { // 0x698354: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
   { // 0x698357: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
   { // 0x698359: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
   { // 0x69835b: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
   { // 0x69835e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x69835f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x698361: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x698363: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
   { // 0x698365: 8d045b LEA EAX,[EBX + EBX*0x2]
    s.ax = (s.bx+(s.bx * 0x00000002u));
  }
   { // 0x698368: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x69836a: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
   { // 0x69836d: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
   { // 0x698371: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
   { // 0x698373: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x698374: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x698376: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x698378: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
   { // 0x69837a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
   { // 0x69837c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x69837d: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
   { // 0x698383: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x698385: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
   { // 0x698387: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
   { // 0x698389: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x69838a: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
   { // 0x698390: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x698392: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
   { // 0x698394: c1fb08 SAR EBX,0x8
    s.bx = integer::shift(s.bx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x698397: c1ff08 SAR EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x69839a: 81fdd8020000 CMP EBP,0x2d8
    (void)integer::sub(s.bp,0x000002d8u,32,flags);
  }
   { // 0x6983a0: 7c08 JL 0x006983aa
    if(integer::condition("JL",flags)) goto L006983aa;
  }
   { // 0x6983a2: c744242001000000 MOV dword ptr [ESP + 0x20],0x1
    m.w32((f.sp+0x00000020u), 0x00000001u);
  }
  L006983aa: { // 0x6983aa: db44241c FILD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x6983ae: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x6983b4: da442420 FIADD dword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
   { // 0x6983b8: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
   { // 0x6983be: e88d260d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6915011u); flags=s.arithmetic_flags;
  }
   { // 0x6983c3: 8b8eb4000000 MOV ECX,dword ptr [ESI + 0xb4]
    s.cx = m.r32((s.si+0x000000b4u));
  }
   { // 0x6983c9: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
   { // 0x6983cb: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
   { // 0x6983d1: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
   { // 0x6983d5: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
   { // 0x6983d7: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
   { // 0x6983d9: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
   { // 0x6983db: 8b86640d0000 MOV EAX,dword ptr [ESI + 0xd64]
    s.ax = m.r32((s.si+0x00000d64u));
  }
   { // 0x6983e1: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
   { // 0x6983e3: 8b8e680d0000 MOV ECX,dword ptr [ESI + 0xd68]
    s.cx = m.r32((s.si+0x00000d68u));
  }
   { // 0x6983e9: 899ed0000000 MOV dword ptr [ESI + 0xd0],EBX
    m.w32((s.si+0x000000d0u), s.bx);
  }
   { // 0x6983ef: 89bed4000000 MOV dword ptr [ESI + 0xd4],EDI
    m.w32((s.si+0x000000d4u), s.di);
  }
   { // 0x6983f5: 8986c8000000 MOV dword ptr [ESI + 0xc8],EAX
    m.w32((s.si+0x000000c8u), s.ax);
  }
   { // 0x6983fb: 898ecc000000 MOV dword ptr [ESI + 0xcc],ECX
    m.w32((s.si+0x000000ccu), s.cx);
  }
   { // 0x698401: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x698402: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x698403: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
   { // 0x698404: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
   { // 0x698405: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
   { // 0x698408: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0069e7b0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x69e7b0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
   { // 0x69e7b3: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x69e7b4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
   { // 0x69e7b6: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x69e7b7: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
   { // 0x69e7bf: 8b8e640d0000 MOV ECX,dword ptr [ESI + 0xd64]
    s.cx = m.r32((s.si+0x00000d64u));
  }
   { // 0x69e7c5: 8bbe680d0000 MOV EDI,dword ptr [ESI + 0xd68]
    s.di = m.r32((s.si+0x00000d68u));
  }
   { // 0x69e7cb: 898eb0000000 MOV dword ptr [ESI + 0xb0],ECX
    m.w32((s.si+0x000000b0u), s.cx);
  }
   { // 0x69e7d1: 89beb4000000 MOV dword ptr [ESI + 0xb4],EDI
    m.w32((s.si+0x000000b4u), s.di);
  }
   { // 0x69e7d7: a17060aa00 MOV EAX,[0x00aa6070]
    s.ax = m.r32((0x00aa6070u));
  }
   { // 0x69e7dc: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x69e7dd: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x69e7df: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x69e7e1: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
   { // 0x69e7e3: 898eb0000000 MOV dword ptr [ESI + 0xb0],ECX
    m.w32((s.si+0x000000b0u), s.cx);
  }
   { // 0x69e7e9: a17460aa00 MOV EAX,[0x00aa6074]
    s.ax = m.r32((0x00aa6074u));
  }
   { // 0x69e7ee: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x69e7ef: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x69e7f1: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
   { // 0x69e7f7: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
   { // 0x69e7f9: 83ea3c SUB EDX,0x3c
    s.dx = integer::sub(s.dx,0x0000003cu,32,flags);
  }
   { // 0x69e7fc: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x69e7fe: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
   { // 0x69e800: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
   { // 0x69e804: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x69e808: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
   { // 0x69e80a: 8d96e40d0000 LEA EDX,[ESI + 0xde4]
    s.dx = (s.si+0x00000de4u);
  }
   { // 0x69e810: 8986b4000000 MOV dword ptr [ESI + 0xb4],EAX
    m.w32((s.si+0x000000b4u), s.ax);
  }
   { // 0x69e816: 83c0e2 ADD EAX,-0x1e
    s.ax = integer::add(s.ax,0xffffffe2u,32,flags);
  }
   { // 0x69e819: d95c2414 FSTP float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x69e81d: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
   { // 0x69e821: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
   { // 0x69e825: db44240c FILD dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x69e829: 50 PUSH EAX
    f.push(m,s.ax);
  }
   { // 0x69e82a: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
   { // 0x69e82e: d95c241c FSTP float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x69e832: e849f9eeff CALL 0x0058e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e180u,6940727u); flags=s.arithmetic_flags;
  }
   { // 0x69e837: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
   { // 0x69e839: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
   { // 0x69e83d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
   { // 0x69e840: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
   { // 0x69e844: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
   { // 0x69e848: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
   { // 0x69e84b: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
   { // 0x69e84f: e8fcc10c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6940756u); flags=s.arithmetic_flags;
  }
   { // 0x69e854: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
   { // 0x69e858: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
   { // 0x69e85a: e8f1c10c00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6940767u); flags=s.arithmetic_flags;
  }
   { // 0x69e85f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
   { // 0x69e861: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
   { // 0x69e863: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x69e864: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
   { // 0x69e86a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x69e86b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x69e86d: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x69e870: 8986800d0000 MOV dword ptr [ESI + 0xd80],EAX
    m.w32((s.si+0x00000d80u), s.ax);
  }
   { // 0x69e876: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
   { // 0x69e878: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x69e879: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
   { // 0x69e87f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x69e881: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x69e884: 8986840d0000 MOV dword ptr [ESI + 0xd84],EAX
    m.w32((s.si+0x00000d84u), s.ax);
  }
   { // 0x69e88a: 8b0d7060aa00 MOV ECX,dword ptr [0x00aa6070]
    s.cx = m.r32((0x00aa6070u));
  }
   { // 0x69e890: b889888888 MOV EAX,0x88888889
    s.ax = 0x88888889u;
  }
   { // 0x69e895: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
   { // 0x69e897: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
   { // 0x69e899: b889888888 MOV EAX,0x88888889
    s.ax = 0x88888889u;
  }
   { // 0x69e89e: c1fa05 SAR EDX,0x5
    s.dx = integer::shift(s.dx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x69e8a1: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
   { // 0x69e8a3: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
   { // 0x69e8a6: 8d540a02 LEA EDX,[EDX + ECX*0x1 + 0x2]
    s.dx = (s.dx+(s.cx * 0x00000001u)+0x00000002u);
  }
   { // 0x69e8aa: 8996880d0000 MOV dword ptr [ESI + 0xd88],EDX
    m.w32((s.si+0x00000d88u), s.dx);
  }
   { // 0x69e8b0: 8b0d7460aa00 MOV ECX,dword ptr [0x00aa6074]
    s.cx = m.r32((0x00aa6074u));
  }
   { // 0x69e8b6: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
   { // 0x69e8b8: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
   { // 0x69e8ba: c1fa03 SAR EDX,0x3
    s.dx = integer::shift(s.dx,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x69e8bd: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
   { // 0x69e8bf: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
   { // 0x69e8c2: 8d4c0204 LEA ECX,[EDX + EAX*0x1 + 0x4]
    s.cx = (s.dx+(s.ax * 0x00000001u)+0x00000004u);
  }
   { // 0x69e8c6: 898e8c0d0000 MOV dword ptr [ESI + 0xd8c],ECX
    m.w32((s.si+0x00000d8cu), s.cx);
  }
   { // 0x69e8cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x69e8cd: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
   { // 0x69e8d0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
