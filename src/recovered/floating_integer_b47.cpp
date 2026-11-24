#include "recovered/floating_integer_b47_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::floating_integer_b47 {
namespace {
void f_001cadc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cadc0: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  { // 0x5cadc3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cadc4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5cadc6: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  { // 0x5cadca: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x5cadce: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5cadcf: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5cadd0: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5cadd2: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x00000048u));
    invoke_external(m,s,f,op,0u,target,0x005cadd5u);
    flags=s.arithmetic_flags;
  }
  { // 0x5cadd5: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  { // 0x5cadd9: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5caddb: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5caddd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5cadde: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5cade0: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x00000048u));
    invoke_external(m,s,f,op,1u,target,0x005cade3u);
    flags=s.arithmetic_flags;
  }
  { // 0x5cade3: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x5cade5: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x5cade7: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  { // 0x5cadeb: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
  { // 0x5cadef: db44242c FILD dword ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x5cadf3: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x5cadf6: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x5cadf9: da642418 FISUB dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto operand=m.r32(address);
    ra2::platform::x87_integer_b47::subtract_integer32(s.fp,operand);
  }
  { // 0x5cadfd: dd5c2408 FSTP double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x5cae01: db4004 FILD dword ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x5cae04: da6704 FISUB dword ptr [EDI + 0x4]
    const auto address=(s.di+0x00000004u);
    const auto operand=m.r32(address);
    ra2::platform::x87_integer_b47::subtract_integer32(s.fp,operand);
  }
  { // 0x5cae07: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x5cae0a: e861f4eeff CALL 0x004ba270
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x004ba270u;
    invoke_external(m,s,f,op,2u,target,0x005cae0fu);
    flags=s.arithmetic_flags;
  }
  { // 0x5cae0f: dc2530667800 FSUB double ptr [0x00786630]
    const auto address=(0x00786630u);
    const auto operand=read64(m,address);
    s.fp.subtract64(operand);
  }
  { // 0x5cae15: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x5cae18: dc0d28667800 FMUL double ptr [0x00786628]
    const auto address=(0x00786628u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x5cae1e: e82dfc1900 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_conversion(m,s,f,0x005cae23u);
    flags=s.arithmetic_flags;
  }
  { // 0x5cae23: 668944242c MOV word ptr [ESP + 0x2c],AX
    m.w16((f.sp+0x0000002cu), (s.ax & 0xffffu));
  }
  { // 0x5cae28: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  { // 0x5cae2c: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  { // 0x5cae30: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5cae31: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  { // 0x5cae33: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cae34: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  { // 0x5cae37: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_002cd4a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6cd4a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6cd4a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6cd4a3: e828f7efff CALL 0x005ccbd0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x005ccbd0u;
    invoke_external(m,s,f,op,0u,target,0x006cd4a8u);
    flags=s.arithmetic_flags;
  }
  { // 0x6cd4a8: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  { // 0x6cd4ad: dc9868130000 FCOMP double ptr [EAX + 0x1368]
    const auto address=(s.ax+0x00001368u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x6cd4b3: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x6cd4b5: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  { // 0x6cd4b8: 740f JZ 0x006cd4c9
    if(integer::condition("JZ",flags)) goto L006cd4c9;
  }
  { // 0x6cd4ba: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6cd4bc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6cd4be: ff92b0010000 CALL dword ptr [EDX + 0x1b0]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.dx+0x000001b0u));
    invoke_external(m,s,f,op,1u,target,0x006cd4c4u);
    flags=s.arithmetic_flags;
  }
  { // 0x6cd4c4: 83f8f6 CMP EAX,-0xa
    (void)integer::sub(s.ax,0xfffffff6u,32,flags);
  }
  { // 0x6cd4c7: 7d12 JGE 0x006cd4db
    if(integer::condition("JGE",flags)) goto L006cd4db;
  }
  L006cd4c9: { // 0x6cd4c9: 8b8e68020000 MOV ECX,dword ptr [ESI + 0x268]
    s.cx = m.r32((s.si+0x00000268u));
  }
  { // 0x6cd4cf: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6cd4d1: 7408 JZ 0x006cd4db
    if(integer::condition("JZ",flags)) goto L006cd4db;
  }
  { // 0x6cd4d3: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x6cd4d5: ff90f0000000 CALL dword ptr [EAX + 0xf0]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x000000f0u));
    invoke_external(m,s,f,op,2u,target,0x006cd4dbu);
    flags=s.arithmetic_flags;
  }
  L006cd4db: { // 0x6cd4db: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cd4dc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002d02a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6d02a0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6d02a1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6d02a2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6d02a4: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6d02a8: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6d02aa: 742a JZ 0x006d02d6
    if(integer::condition("JZ",flags)) goto L006d02d6;
  }
  { // 0x6d02ac: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6d02ad: e8ae4be2ff CALL 0x004f4e60
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x004f4e60u;
    invoke_external(m,s,f,op,0u,target,0x006d02b2u);
    flags=s.arithmetic_flags;
  }
  { // 0x6d02b2: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6d02b4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6d02b6: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x6d02ba: ff90ac000000 CALL dword ptr [EAX + 0xac]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x000000acu));
    invoke_external(m,s,f,op,1u,target,0x006d02c0u);
    flags=s.arithmetic_flags;
  }
  { // 0x6d02c0: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  { // 0x6d02c4: db44240c FILD dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x6d02c8: d84c2404 FMUL float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x6d02cc: e87fa70900 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_conversion(m,s,f,0x006d02d1u);
    flags=s.arithmetic_flags;
  }
  { // 0x6d02d1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6d02d2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6d02d3: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006d02d6: { // 0x6d02d6: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6d02d8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6d02da: ff92ac000000 CALL dword ptr [EDX + 0xac]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.dx+0x000000acu));
    invoke_external(m,s,f,op,3u,target,0x006d02e0u);
    flags=s.arithmetic_flags;
  }
  { // 0x6d02e0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6d02e1: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6d02e2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0037c4e9(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77c4e9: 83ec2c SUB ESP,0x2c
    f.sp = integer::sub(f.sp,0x0000002cu,32,flags);
  }
  { // 0x77c4ec: db7c240c FSTP extended double ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto output=ra2::platform::x87_integer_b47::pop80(s.fp);
    for(unsigned n=0;n<10;++n)m.w8(address+n,output.bytes[n]);
  }
  { // 0x77c4f0: db3c24 FSTP extended double ptr [ESP]
    const auto address=(f.sp);
    const auto output=ra2::platform::x87_integer_b47::pop80(s.fp);
    for(unsigned n=0;n<10;++n)m.w8(address+n,output.bytes[n]);
  }
  { // 0x77c4f3: e828faffff CALL 0x0077bf20
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0077bf20u;
    invoke_external(m,s,f,op,0u,target,0x0077c4f8u);
    flags=s.arithmetic_flags;
  }
  { // 0x77c4f8: 83c42c ADD ESP,0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  { // 0x77c4fb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,4>& entries_a() {
  static const std::array<Entry,4> entries{{
    {0x1cadc0u,f_001cadc0},
    {0x2cd4a0u,f_002cd4a0},
    {0x2d02a0u,f_002d02a0},
    {0x37c4e9u,f_0037c4e9},
  }}; return entries;
}
} // namespace ra2::recovered::floating_integer_b47
