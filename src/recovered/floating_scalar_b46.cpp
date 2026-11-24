#include "recovered/floating_scalar_b46_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::floating_scalar_b46 {
namespace {
void f_00176590(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x576590: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  { // 0x576593: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x576594: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x576596: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x576598: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x576599: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x57659b: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x57659c: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x57659e: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  { // 0x5765a2: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  { // 0x5765a6: df6c2408 FILD qword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=read64(m,address);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,operand);
  }
  { // 0x5765aa: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  { // 0x5765ae: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  { // 0x5765b2: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x5765b6: df6c2408 FILD qword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=read64(m,address);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,operand);
  }
  { // 0x5765ba: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005765be: { // 0x5765be: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  { // 0x5765c3: e818980b00 CALL 0x0062fde0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0062fde0u;
    invoke_external(m,s,f,op,0u,target,0x005765c8u);
    flags=s.arithmetic_flags;
  }
  { // 0x5765c8: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  { // 0x5765cc: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  { // 0x5765d0: df6c2408 FILD qword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=read64(m,address);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,operand);
  }
  { // 0x5765d4: dc4c2410 FMUL double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x5765d8: dc0db00d7900 FMUL double ptr [0x00790db0]
    const auto address=(0x00790db0u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x5765de: dc442418 FADD double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto operand=read64(m,address);
    s.fp.add64(operand);
  }
  { // 0x5765e2: e869441f00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_conversion(m,s,f,0x005765e7u);
    flags=s.arithmetic_flags;
  }
  { // 0x5765e7: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x5765e9: 77d3 JA 0x005765be
    if(integer::condition("JA",flags)) goto L005765be;
  }
  { // 0x5765eb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5765ec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5765ed: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  { // 0x5765f0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001cc340(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cc340: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x5cc344: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x5cc347: 83f80d CMP EAX,0xd
    (void)integer::sub(s.ax,0x0000000du,32,flags);
  }
  { // 0x5cc34a: 7444 JZ 0x005cc390
    if(integer::condition("JZ",flags)) goto L005cc390;
  }
  { // 0x5cc34c: 83f822 CMP EAX,0x22
    (void)integer::sub(s.ax,0x00000022u,32,flags);
  }
  { // 0x5cc34f: 7408 JZ 0x005cc359
    if(integer::condition("JZ",flags)) goto L005cc359;
  }
  { // 0x5cc351: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5cc353: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5cc356: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L005cc359: { // 0x5cc359: db416c FILD dword ptr [ECX + 0x6c]
    const auto address=(s.cx+0x0000006cu);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x5cc35c: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5cc35e: dd5c2400 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x5cc362: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x00000084u));
    invoke_external(m,s,f,op,0u,target,0x005cc368u);
    flags=s.arithmetic_flags;
  }
  { // 0x5cc368: db80a0000000 FILD dword ptr [EAX + 0xa0]
    const auto address=(s.ax+0x000000a0u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x5cc36e: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  { // 0x5cc374: dc7c2400 FDIVR double ptr [ESP]
    const auto address=(f.sp);
    const auto operand=read64(m,address);
    ra2::platform::x87_scalar_b46::reverse_divide64(s.fp,operand);
  }
  { // 0x5cc378: dc9960130000 FCOMP double ptr [ECX + 0x1360]
    const auto address=(s.cx+0x00001360u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x5cc37e: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x5cc380: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x5cc383: 7515 JNZ 0x005cc39a
    if(integer::condition("JNZ",flags)) goto L005cc39a;
  }
  { // 0x5cc385: b80a000000 MOV EAX,0xa
    s.ax = 0x0000000au;
  }
  { // 0x5cc38a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5cc38d: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L005cc390: { // 0x5cc390: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x5cc392: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x5cc394: ff921c010000 CALL dword ptr [EDX + 0x11c]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.dx+0x0000011cu));
    invoke_external(m,s,f,op,1u,target,0x005cc39au);
    flags=s.arithmetic_flags;
  }
  L005cc39a: { // 0x5cc39a: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x5cc39f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5cc3a2: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_001ccbd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5ccbd0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x5ccbd3: db416c FILD dword ptr [ECX + 0x6c]
    const auto address=(s.cx+0x0000006cu);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x5ccbd6: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x5ccbd8: dd5c2400 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x5ccbdc: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x00000084u));
    invoke_external(m,s,f,op,0u,target,0x005ccbe2u);
    flags=s.arithmetic_flags;
  }
  { // 0x5ccbe2: db80a0000000 FILD dword ptr [EAX + 0xa0]
    const auto address=(s.ax+0x000000a0u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x5ccbe8: dc7c2400 FDIVR double ptr [ESP]
    const auto address=(f.sp);
    const auto operand=read64(m,address);
    ra2::platform::x87_scalar_b46::reverse_divide64(s.fp,operand);
  }
  { // 0x5ccbec: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5ccbef: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001ccc40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5ccc40: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x5ccc43: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ccc44: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5ccc46: db466c FILD dword ptr [ESI + 0x6c]
    const auto address=(s.si+0x0000006cu);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x5ccc49: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5ccc4b: dd5c2404 FSTP double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x5ccc4f: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x00000084u));
    invoke_external(m,s,f,op,0u,target,0x005ccc55u);
    flags=s.arithmetic_flags;
  }
  { // 0x5ccc55: db80a0000000 FILD dword ptr [EAX + 0xa0]
    const auto address=(s.ax+0x000000a0u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x5ccc5b: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  { // 0x5ccc61: dc7c2404 FDIVR double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=read64(m,address);
    ra2::platform::x87_scalar_b46::reverse_divide64(s.fp,operand);
  }
  { // 0x5ccc65: dc9970130000 FCOMP double ptr [ECX + 0x1370]
    const auto address=(s.cx+0x00001370u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x5ccc6b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x5ccc6d: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  { // 0x5ccc70: 7411 JZ 0x005ccc83
    if(integer::condition("JZ",flags)) goto L005ccc83;
  }
  { // 0x5ccc72: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  { // 0x5ccc75: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5ccc77: 7e0a JLE 0x005ccc83
    if(integer::condition("JLE",flags)) goto L005ccc83;
  }
  { // 0x5ccc79: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x5ccc7e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5ccc7f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5ccc82: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005ccc83: { // 0x5ccc83: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5ccc85: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5ccc86: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5ccc89: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001ccc90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5ccc90: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x5ccc93: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ccc94: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5ccc96: db466c FILD dword ptr [ESI + 0x6c]
    const auto address=(s.si+0x0000006cu);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x5ccc99: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x5ccc9b: dd5c2404 FSTP double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x5ccc9f: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x00000084u));
    invoke_external(m,s,f,op,0u,target,0x005ccca5u);
    flags=s.arithmetic_flags;
  }
  { // 0x5ccca5: db80a0000000 FILD dword ptr [EAX + 0xa0]
    const auto address=(s.ax+0x000000a0u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x5cccab: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  { // 0x5cccb1: dc7c2404 FDIVR double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=read64(m,address);
    ra2::platform::x87_scalar_b46::reverse_divide64(s.fp,operand);
  }
  { // 0x5cccb5: dc9970130000 FCOMP double ptr [ECX + 0x1370]
    const auto address=(s.cx+0x00001370u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x5cccbb: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x5cccbd: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  { // 0x5cccc0: 7537 JNZ 0x005cccf9
    if(integer::condition("JNZ",flags)) goto L005cccf9;
  }
  { // 0x5cccc2: db466c FILD dword ptr [ESI + 0x6c]
    const auto address=(s.si+0x0000006cu);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x5cccc5: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x5cccc7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5cccc9: dd5c2404 FSTP double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x5ccccd: ff9284000000 CALL dword ptr [EDX + 0x84]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.dx+0x00000084u));
    invoke_external(m,s,f,op,1u,target,0x005cccd3u);
    flags=s.arithmetic_flags;
  }
  { // 0x5cccd3: db80a0000000 FILD dword ptr [EAX + 0xa0]
    const auto address=(s.ax+0x000000a0u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x5cccd9: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  { // 0x5cccde: dc7c2404 FDIVR double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=read64(m,address);
    ra2::platform::x87_scalar_b46::reverse_divide64(s.fp,operand);
  }
  { // 0x5ccce2: dc9868130000 FCOMP double ptr [EAX + 0x1368]
    const auto address=(s.ax+0x00001368u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x5ccce8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x5cccea: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  { // 0x5ccced: 740a JZ 0x005cccf9
    if(integer::condition("JZ",flags)) goto L005cccf9;
  }
  { // 0x5cccef: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x5cccf4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cccf5: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5cccf8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005cccf9: { // 0x5cccf9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5cccfb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cccfc: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5cccff: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0022eb90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x62eb90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x62eb91: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x62eb93: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x62eb94: db464c FILD dword ptr [ESI + 0x4c]
    const auto address=(s.si+0x0000004cu);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x62eb97: db4670 FILD dword ptr [ESI + 0x70]
    const auto address=(s.si+0x00000070u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x62eb9a: dec9 FMULP
    ra2::platform::x87_scalar_b46::multiply_pop(s.fp);
  }
  { // 0x62eb9c: db466c FILD dword ptr [ESI + 0x6c]
    const auto address=(s.si+0x0000006cu);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x62eb9f: def9 FDIVP
    s.fp.divide_pop();
  }
  { // 0x62eba1: e8aabe1300 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_conversion(m,s,f,0x0062eba6u);
    flags=s.arithmetic_flags;
  }
  { // 0x62eba6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x62eba8: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x62ebaa: e801060000 CALL 0x0062f1b0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0062f1b0u;
    invoke_external(m,s,f,op,1u,target,0x0062ebafu);
    flags=s.arithmetic_flags;
  }
  { // 0x62ebaf: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x62ebb3: 8d0c07 LEA ECX,[EDI + EAX*0x1]
    s.cx = (s.di+(s.ax * 0x00000001u));
  }
  { // 0x62ebb6: 894e4c MOV dword ptr [ESI + 0x4c],ECX
    m.w32((s.si+0x0000004cu), s.cx);
  }
  { // 0x62ebb9: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  { // 0x62ebbf: 8b8248140000 MOV EAX,dword ptr [EDX + 0x1448]
    s.ax = m.r32((s.dx+0x00001448u));
  }
  { // 0x62ebc5: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  { // 0x62ebc8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x62ebca: 89466c MOV dword ptr [ESI + 0x6c],EAX
    m.w32((s.si+0x0000006cu), s.ax);
  }
  { // 0x62ebcd: 894670 MOV dword ptr [ESI + 0x70],EAX
    m.w32((s.si+0x00000070u), s.ax);
  }
  { // 0x62ebd0: e80b000000 CALL 0x0062ebe0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0062ebe0u;
    invoke_external(m,s,f,op,2u,target,0x0062ebd5u);
    flags=s.arithmetic_flags;
  }
  { // 0x62ebd5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x62ebd6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x62ebd7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_003708ed(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7708ed: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7708ee: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7708f0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7708f1: 9bdd7dfc FSTSW word ptr [EBP + -0x4]
    const auto address=(s.bp-0x00000004u);
    const auto value=s.fp.waiting_status();
    m.w16(address,value);
  }
  { // 0x7708f5: ff75fc PUSH dword ptr [EBP + -0x4]
    f.push(m,m.r32((s.bp-0x00000004u)));
  }
  { // 0x7708f8: e8a8010000 CALL 0x00770aa5
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00770aa5u;
    invoke_external(m,s,f,op,0u,target,0x007708fdu);
    flags=s.arithmetic_flags;
  }
  { // 0x7708fd: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7708fe: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x7708ff: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00370900(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x770900: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x770901: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x770903: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x770904: dd7dfc FNSTSW word ptr [EBP + -0x4]
    const auto address=(s.bp-0x00000004u);
    const auto value=s.fp.status();
    m.w16(address,value);
  }
  { // 0x770907: dbe2 FNCLEX
    s.fp.clear_exceptions();
  }
  { // 0x770909: ff75fc PUSH dword ptr [EBP + -0x4]
    f.push(m,m.r32((s.bp-0x00000004u)));
  }
  { // 0x77090c: e894010000 CALL 0x00770aa5
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00770aa5u;
    invoke_external(m,s,f,op,0u,target,0x00770911u);
    flags=s.arithmetic_flags;
  }
  { // 0x770911: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770912: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x770913: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,8>& entries_a() {
  static const std::array<Entry,8> entries{{
    {0x176590u,f_00176590},
    {0x1cc340u,f_001cc340},
    {0x1ccbd0u,f_001ccbd0},
    {0x1ccc40u,f_001ccc40},
    {0x1ccc90u,f_001ccc90},
    {0x22eb90u,f_0022eb90},
    {0x3708edu,f_003708ed},
    {0x370900u,f_00370900},
  }}; return entries;
}
} // namespace ra2::recovered::floating_scalar_b46
