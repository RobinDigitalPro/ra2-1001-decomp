#include "floating_composed_b43_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Original instruction annotations are retained; acceptance requires current native proof.
namespace ra2::recovered::floating_composed_b43 {
namespace {
void f_0018ccf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58ccf0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x58ccf1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x58ccf3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x58ccf5: b90000803f MOV ECX,0x3f800000
    s.cx = 0x3f800000u;
  }
  { // 0x58ccfa: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x58ccfd: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x58cd00: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  { // 0x58cd03: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x58cd06: 894618 MOV dword ptr [ESI + 0x18],EAX
    m.w32((s.si+0x00000018u), s.ax);
  }
  { // 0x58cd09: 89461c MOV dword ptr [ESI + 0x1c],EAX
    m.w32((s.si+0x0000001cu), s.ax);
  }
  { // 0x58cd0c: 894620 MOV dword ptr [ESI + 0x20],EAX
    m.w32((s.si+0x00000020u), s.ax);
  }
  { // 0x58cd0f: 894624 MOV dword ptr [ESI + 0x24],EAX
    m.w32((s.si+0x00000024u), s.ax);
  }
  { // 0x58cd12: 89462c MOV dword ptr [ESI + 0x2c],EAX
    m.w32((s.si+0x0000002cu), s.ax);
  }
  { // 0x58cd15: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x58cd19: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  { // 0x58cd1b: 894e14 MOV dword ptr [ESI + 0x14],ECX
    m.w32((s.si+0x00000014u), s.cx);
  }
  { // 0x58cd1e: 894e28 MOV dword ptr [ESI + 0x28],ECX
    m.w32((s.si+0x00000028u), s.cx);
  }
  { // 0x58cd21: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x58cd22: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x58cd24: e8770a0000 CALL 0x0058d7a0
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0018d7a0u,0x0058cd29u);
    flags=s.arithmetic_flags;
  }
  { // 0x58cd29: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x58cd2d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x58cd2e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x58cd30: e82b080000 CALL 0x0058d560
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0018d560u,0x0058cd35u);
    flags=s.arithmetic_flags;
  }
  { // 0x58cd35: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58cd39: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x58cd3a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x58cd3c: d9e0 FCHS
    s.fp.change_sign();
  }
  { // 0x58cd3e: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58cd41: e85a0a0000 CALL 0x0058d7a0
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0018d7a0u,0x0058cd46u);
    flags=s.arithmetic_flags;
  }
  { // 0x58cd46: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x58cd48: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x58cd49: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0018d560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58d560: 83ec08 SUB ESP,8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  { // 0x58d563: d944240c FLD float ptr [ESP+0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d567: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x58d568: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x58d569: dd5c2408 FSTP double ptr [ESP+8]
    const auto address=(f.sp+8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x58d56d: 8b5c2408 MOV EBX,dword ptr [ESP+8]
    s.bx = m.r32((f.sp+8u));
  }
  { // 0x58d571: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x58d572: 8b7c2410 MOV EDI,dword ptr [ESP+0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x58d576: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x58d578: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x58d579: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x58d57a: e871cbf2ff CALL 0x4ba0f0
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba0f0u,0x0058d57fu);
    flags=s.arithmetic_flags;
  }
  { // 0x58d57f: d95c2420 FSTP float ptr [ESP+0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d583: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x58d584: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x58d585: e8b6cbf2ff CALL 0x4ba140
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba140u,0x0058d58au);
    flags=s.arithmetic_flags;
  }
  { // 0x58d58a: d94604 FLD float ptr [ESI+4]
    const auto address=(s.si+4u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d58d: d94608 FLD float ptr [ESI+8]
    const auto address=(s.si+8u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d590: d9c1 FLD ST1
    s.fp.load_st1();
  }
  { // 0x58d592: d8cb FMUL ST3
    extended::multiply_st3(s.fp);
  }
  { // 0x58d594: d9c1 FLD ST1
    s.fp.load_st1();
  }
  { // 0x58d596: d84c2428 FMUL float ptr [ESP+0x28]
    const auto address=(f.sp+0x00000028u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d59a: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x58d59d: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58d59f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x58d5a0: d95e04 FSTP float ptr [ESI+4]
    const auto address=(s.si+4u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d5a3: d8ca FMUL ST2
    extended::multiply_st2(s.fp);
  }
  { // 0x58d5a5: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x58d5a7: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d5ab: dee9 FSUBP
    s.fp.subtract_pop();
  }
  { // 0x58d5ad: d95e08 FSTP float ptr [ESI+8]
    const auto address=(s.si+8u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d5b0: d94614 FLD float ptr [ESI+0x14]
    const auto address=(s.si+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d5b3: d94618 FLD float ptr [ESI+0x18]
    const auto address=(s.si+0x00000018u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d5b6: d9c1 FLD ST1
    s.fp.load_st1();
  }
  { // 0x58d5b8: d8cb FMUL ST3
    extended::multiply_st3(s.fp);
  }
  { // 0x58d5ba: d9c1 FLD ST1
    s.fp.load_st1();
  }
  { // 0x58d5bc: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d5c0: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58d5c2: d95e14 FSTP float ptr [ESI+0x14]
    const auto address=(s.si+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d5c5: d8ca FMUL ST2
    extended::multiply_st2(s.fp);
  }
  { // 0x58d5c7: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x58d5c9: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d5cd: dee9 FSUBP
    s.fp.subtract_pop();
  }
  { // 0x58d5cf: d95e18 FSTP float ptr [ESI+0x18]
    const auto address=(s.si+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d5d2: d94624 FLD float ptr [ESI+0x24]
    const auto address=(s.si+0x00000024u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d5d5: d94628 FLD float ptr [ESI+0x28]
    const auto address=(s.si+0x00000028u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d5d8: d9c1 FLD ST1
    s.fp.load_st1();
  }
  { // 0x58d5da: d8cb FMUL ST3
    extended::multiply_st3(s.fp);
  }
  { // 0x58d5dc: d9c1 FLD ST1
    s.fp.load_st1();
  }
  { // 0x58d5de: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d5e2: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58d5e4: d95e24 FSTP float ptr [ESI+0x24]
    const auto address=(s.si+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d5e7: d8ca FMUL ST2
    extended::multiply_st2(s.fp);
  }
  { // 0x58d5e9: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x58d5eb: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d5ef: dee9 FSUBP
    s.fp.subtract_pop();
  }
  { // 0x58d5f1: d95e28 FSTP float ptr [ESI+0x28]
    const auto address=(s.si+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d5f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x58d5f5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x58d5f6: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x58d5f8: 83c408 ADD ESP,8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  { // 0x58d5fb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018d7a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58d7a0: 83ec08 SUB ESP,8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  { // 0x58d7a3: d944240c FLD float ptr [ESP+0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d7a7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x58d7a8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x58d7a9: dd5c2408 FSTP double ptr [ESP+8]
    const auto address=(f.sp+8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x58d7ad: 8b5c2408 MOV EBX,dword ptr [ESP+8]
    s.bx = m.r32((f.sp+8u));
  }
  { // 0x58d7b1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x58d7b2: 8b7c2410 MOV EDI,dword ptr [ESP+0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x58d7b6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x58d7b8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x58d7b9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x58d7ba: e881c9f2ff CALL 0x4ba140
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba140u,0x0058d7bfu);
    flags=s.arithmetic_flags;
  }
  { // 0x58d7bf: d95c2420 FSTP float ptr [ESP+0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d7c3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x58d7c4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x58d7c5: e826c9f2ff CALL 0x4ba0f0
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba0f0u,0x0058d7cau);
    flags=s.arithmetic_flags;
  }
  { // 0x58d7ca: d906 FLD float ptr [ESI]
    const auto address=(s.si);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d7cc: d94604 FLD float ptr [ESI+4]
    const auto address=(s.si+4u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d7cf: d9c0 FLD ST0
    s.fp.load_st0();
  }
  { // 0x58d7d1: d8cb FMUL ST3
    extended::multiply_st3(s.fp);
  }
  { // 0x58d7d3: d9c2 FLD ST2
    s.fp.load_st2();
  }
  { // 0x58d7d5: d84c2428 FMUL float ptr [ESP+0x28]
    const auto address=(f.sp+0x00000028u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d7d9: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x58d7dc: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58d7de: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x58d7df: d91e FSTP float ptr [ESI]
    const auto address=(s.si);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d7e1: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d7e5: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x58d7e7: d8ca FMUL ST2
    extended::multiply_st2(s.fp);
  }
  { // 0x58d7e9: dee9 FSUBP
    s.fp.subtract_pop();
  }
  { // 0x58d7eb: d95e04 FSTP float ptr [ESI+4]
    const auto address=(s.si+4u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d7ee: d94610 FLD float ptr [ESI+0x10]
    const auto address=(s.si+0x00000010u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d7f1: d94614 FLD float ptr [ESI+0x14]
    const auto address=(s.si+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d7f4: d9c0 FLD ST0
    s.fp.load_st0();
  }
  { // 0x58d7f6: d8cb FMUL ST3
    extended::multiply_st3(s.fp);
  }
  { // 0x58d7f8: d9c2 FLD ST2
    s.fp.load_st2();
  }
  { // 0x58d7fa: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d7fe: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58d800: d95e10 FSTP float ptr [ESI+0x10]
    const auto address=(s.si+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d803: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d807: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x58d809: d8ca FMUL ST2
    extended::multiply_st2(s.fp);
  }
  { // 0x58d80b: dee9 FSUBP
    s.fp.subtract_pop();
  }
  { // 0x58d80d: d95e14 FSTP float ptr [ESI+0x14]
    const auto address=(s.si+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d810: d94620 FLD float ptr [ESI+0x20]
    const auto address=(s.si+0x00000020u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d813: d94624 FLD float ptr [ESI+0x24]
    const auto address=(s.si+0x00000024u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d816: d9c0 FLD ST0
    s.fp.load_st0();
  }
  { // 0x58d818: d8cb FMUL ST3
    extended::multiply_st3(s.fp);
  }
  { // 0x58d81a: d9c2 FLD ST2
    s.fp.load_st2();
  }
  { // 0x58d81c: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d820: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58d822: d95e20 FSTP float ptr [ESI+0x20]
    const auto address=(s.si+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d825: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d829: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x58d82b: d8ca FMUL ST2
    extended::multiply_st2(s.fp);
  }
  { // 0x58d82d: dee9 FSUBP
    s.fp.subtract_pop();
  }
  { // 0x58d82f: d95e24 FSTP float ptr [ESI+0x24]
    const auto address=(s.si+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d832: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x58d833: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x58d834: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x58d836: 83c408 ADD ESP,8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  { // 0x58d839: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00370914(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x770914: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x770915: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x770917: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x770918: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770919: 9bd97dfc FSTCW word ptr [EBP + -0x4]
    const auto address=(s.bp-0x00000004u);
    const auto value=s.fp.waiting_control();
    m.w16(address,value);
  }
  { // 0x77091d: ff75fc PUSH dword ptr [EBP + -0x4]
    f.push(m,m.r32((s.bp-0x00000004u)));
  }
  { // 0x770920: e865000000 CALL 0x0077098a
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0037098au,0x00770925u);
    flags=s.arithmetic_flags;
  }
  { // 0x770925: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x770927: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x77092a: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  { // 0x77092c: 23f0 AND ESI,EAX
    s.si = integer::logical((s.si)&(s.ax),32,flags);
  }
  { // 0x77092e: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x770931: 23450c AND EAX,dword ptr [EBP + 0xc]
    s.ax = integer::logical((s.ax)&(m.r32((s.bp+0x0000000cu))),32,flags);
  }
  { // 0x770934: 0bf0 OR ESI,EAX
    s.si = integer::logical((s.si)|(s.ax),32,flags);
  }
  { // 0x770936: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770937: e8e0000000 CALL 0x00770a1c
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x00370a1cu,0x0077093cu);
    flags=s.arithmetic_flags;
  }
  { // 0x77093c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77093d: 89450c MOV dword ptr [EBP + 0xc],EAX
    m.w32((s.bp+0x0000000cu), s.ax);
  }
  { // 0x770940: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x770941: d96d0c FLDCW word ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    const auto operand=m.r16(address);
    s.fp.load_control(operand);
  }
  { // 0x770944: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x770946: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x770947: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x770948: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0037098a(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77098a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x77098b: 8b5c2408 MOV EBX,dword ptr [ESP+8]
    s.bx = m.r32((f.sp+8u));
  }
  { // 0x77098f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x770991: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x770992: f6c301 TEST BL,1
    (void)integer::logical(((s.bx & 0xffu))&(1u),8,flags);
  }
  { // 0x770995: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x770996: 7403 JZ 0x77099b
    if(integer::condition("JZ",flags)) goto L0077099b;
  }
  { // 0x770998: 6a10 PUSH 0x10
    f.push(m,0x00000010u);
  }
  { // 0x77099a: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L0077099b: { // 0x77099b: f6c304 TEST BL,4
    (void)integer::logical(((s.bx & 0xffu))&(4u),8,flags);
  }
  { // 0x77099e: 7402 JZ 0x7709a2
    if(integer::condition("JZ",flags)) goto L007709a2;
  }
  { // 0x7709a0: 0c08 OR AL,8
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(8u),8,flags));
  }
  L007709a2: { // 0x7709a2: f6c308 TEST BL,8
    (void)integer::logical(((s.bx & 0xffu))&(8u),8,flags);
  }
  { // 0x7709a5: 7402 JZ 0x7709a9
    if(integer::condition("JZ",flags)) goto L007709a9;
  }
  { // 0x7709a7: 0c04 OR AL,4
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(4u),8,flags));
  }
  L007709a9: { // 0x7709a9: f6c310 TEST BL,0x10
    (void)integer::logical(((s.bx & 0xffu))&(0x00000010u),8,flags);
  }
  { // 0x7709ac: 7402 JZ 0x7709b0
    if(integer::condition("JZ",flags)) goto L007709b0;
  }
  { // 0x7709ae: 0c02 OR AL,2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(2u),8,flags));
  }
  L007709b0: { // 0x7709b0: f6c320 TEST BL,0x20
    (void)integer::logical(((s.bx & 0xffu))&(0x00000020u),8,flags);
  }
  { // 0x7709b3: 7402 JZ 0x7709b7
    if(integer::condition("JZ",flags)) goto L007709b7;
  }
  { // 0x7709b5: 0c01 OR AL,1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(1u),8,flags));
  }
  L007709b7: { // 0x7709b7: f6c302 TEST BL,2
    (void)integer::logical(((s.bx & 0xffu))&(2u),8,flags);
  }
  { // 0x7709ba: 7405 JZ 0x7709c1
    if(integer::condition("JZ",flags)) goto L007709c1;
  }
  { // 0x7709bc: 0d00000800 OR EAX,0x80000
    s.ax = integer::logical((s.ax)|(0x00080000u),32,flags);
  }
  L007709c1: { // 0x7709c1: 0fb7cb MOVZX ECX,BX
    s.cx = ((s.bx & 0xffffu)&integer::mask(16));
  }
  { // 0x7709c4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7709c5: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x7709c7: be000c0000 MOV ESI,0xc00
    s.si = 0x00000c00u;
  }
  { // 0x7709cc: bf00030000 MOV EDI,0x300
    s.di = 0x00000300u;
  }
  { // 0x7709d1: 23d6 AND EDX,ESI
    s.dx = integer::logical((s.dx)&(s.si),32,flags);
  }
  { // 0x7709d3: bd00020000 MOV EBP,0x200
    s.bp = 0x00000200u;
  }
  { // 0x7709d8: 741f JZ 0x7709f9
    if(integer::condition("JZ",flags)) goto L007709f9;
  }
  { // 0x7709da: 81fa00040000 CMP EDX,0x400
    (void)integer::sub(s.dx,0x00000400u,32,flags);
  }
  { // 0x7709e0: 7414 JZ 0x7709f6
    if(integer::condition("JZ",flags)) goto L007709f6;
  }
  { // 0x7709e2: 81fa00080000 CMP EDX,0x800
    (void)integer::sub(s.dx,0x00000800u,32,flags);
  }
  { // 0x7709e8: 7408 JZ 0x7709f2
    if(integer::condition("JZ",flags)) goto L007709f2;
  }
  { // 0x7709ea: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  { // 0x7709ec: 750b JNZ 0x7709f9
    if(integer::condition("JNZ",flags)) goto L007709f9;
  }
  { // 0x7709ee: 0bc7 OR EAX,EDI
    s.ax = integer::logical((s.ax)|(s.di),32,flags);
  }
  { // 0x7709f0: eb07 JMP 0x7709f9
    goto L007709f9;
  }
  L007709f2: { // 0x7709f2: 0bc5 OR EAX,EBP
    s.ax = integer::logical((s.ax)|(s.bp),32,flags);
  }
  { // 0x7709f4: eb03 JMP 0x7709f9
    goto L007709f9;
  }
  L007709f6: { // 0x7709f6: 80cc01 OR AH,1
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))|(1u),8,flags)) & 0xffu) << 8);
  }
  L007709f9: { // 0x7709f9: 23cf AND ECX,EDI
    s.cx = integer::logical((s.cx)&(s.di),32,flags);
  }
  { // 0x7709fb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7709fc: 740b JZ 0x770a09
    if(integer::condition("JZ",flags)) goto L00770a09;
  }
  { // 0x7709fe: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  { // 0x770a00: 750c JNZ 0x770a0e
    if(integer::condition("JNZ",flags)) goto L00770a0e;
  }
  { // 0x770a02: 0d00000100 OR EAX,0x10000
    s.ax = integer::logical((s.ax)|(0x00010000u),32,flags);
  }
  { // 0x770a07: eb05 JMP 0x770a0e
    goto L00770a0e;
  }
  L00770a09: { // 0x770a09: 0d00000200 OR EAX,0x20000
    s.ax = integer::logical((s.ax)|(0x00020000u),32,flags);
  }
  L00770a0e: { // 0x770a0e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x770a0f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x770a10: f6c710 TEST BH,0x10
    (void)integer::logical((((s.bx >> 8) & 0xffu))&(0x00000010u),8,flags);
  }
  { // 0x770a13: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x770a14: 7405 JZ 0x770a1b
    if(integer::condition("JZ",flags)) goto L00770a1b;
  }
  { // 0x770a16: 0d00000400 OR EAX,0x40000
    s.ax = integer::logical((s.ax)|(0x00040000u),32,flags);
  }
  L00770a1b: { // 0x770a1b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00370a1c(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x770a1c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x770a1d: 8b5c2408 MOV EBX,dword ptr [ESP+8]
    s.bx = m.r32((f.sp+8u));
  }
  { // 0x770a21: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x770a23: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x770a24: f6c310 TEST BL,0x10
    (void)integer::logical(((s.bx & 0xffu))&(0x00000010u),8,flags);
  }
  { // 0x770a27: 7403 JZ 0x770a2c
    if(integer::condition("JZ",flags)) goto L00770a2c;
  }
  { // 0x770a29: 6a01 PUSH 1
    f.push(m,1u);
  }
  { // 0x770a2b: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L00770a2c: { // 0x770a2c: f6c308 TEST BL,8
    (void)integer::logical(((s.bx & 0xffu))&(8u),8,flags);
  }
  { // 0x770a2f: 7402 JZ 0x770a33
    if(integer::condition("JZ",flags)) goto L00770a33;
  }
  { // 0x770a31: 0c04 OR AL,4
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(4u),8,flags));
  }
  L00770a33: { // 0x770a33: f6c304 TEST BL,4
    (void)integer::logical(((s.bx & 0xffu))&(4u),8,flags);
  }
  { // 0x770a36: 7402 JZ 0x770a3a
    if(integer::condition("JZ",flags)) goto L00770a3a;
  }
  { // 0x770a38: 0c08 OR AL,8
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(8u),8,flags));
  }
  L00770a3a: { // 0x770a3a: f6c302 TEST BL,2
    (void)integer::logical(((s.bx & 0xffu))&(2u),8,flags);
  }
  { // 0x770a3d: 7402 JZ 0x770a41
    if(integer::condition("JZ",flags)) goto L00770a41;
  }
  { // 0x770a3f: 0c10 OR AL,0x10
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000010u),8,flags));
  }
  L00770a41: { // 0x770a41: f6c301 TEST BL,1
    (void)integer::logical(((s.bx & 0xffu))&(1u),8,flags);
  }
  { // 0x770a44: 7402 JZ 0x770a48
    if(integer::condition("JZ",flags)) goto L00770a48;
  }
  { // 0x770a46: 0c20 OR AL,0x20
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000020u),8,flags));
  }
  L00770a48: { // 0x770a48: f7c300000800 TEST EBX,0x80000
    (void)integer::logical((s.bx)&(0x00080000u),32,flags);
  }
  { // 0x770a4e: 7402 JZ 0x770a52
    if(integer::condition("JZ",flags)) goto L00770a52;
  }
  { // 0x770a50: 0c02 OR AL,2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(2u),8,flags));
  }
  L00770a52: { // 0x770a52: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x770a54: ba00030000 MOV EDX,0x300
    s.dx = 0x00000300u;
  }
  { // 0x770a59: 23ca AND ECX,EDX
    s.cx = integer::logical((s.cx)&(s.dx),32,flags);
  }
  { // 0x770a5b: be00020000 MOV ESI,0x200
    s.si = 0x00000200u;
  }
  { // 0x770a60: 741d JZ 0x770a7f
    if(integer::condition("JZ",flags)) goto L00770a7f;
  }
  { // 0x770a62: 81f900010000 CMP ECX,0x100
    (void)integer::sub(s.cx,0x00000100u,32,flags);
  }
  { // 0x770a68: 7412 JZ 0x770a7c
    if(integer::condition("JZ",flags)) goto L00770a7c;
  }
  { // 0x770a6a: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  { // 0x770a6c: 7409 JZ 0x770a77
    if(integer::condition("JZ",flags)) goto L00770a77;
  }
  { // 0x770a6e: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x770a70: 750d JNZ 0x770a7f
    if(integer::condition("JNZ",flags)) goto L00770a7f;
  }
  { // 0x770a72: 80cc0c OR AH,0xc
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))|(0x0000000cu),8,flags)) & 0xffu) << 8);
  }
  { // 0x770a75: eb08 JMP 0x770a7f
    goto L00770a7f;
  }
  L00770a77: { // 0x770a77: 80cc08 OR AH,8
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))|(8u),8,flags)) & 0xffu) << 8);
  }
  { // 0x770a7a: eb03 JMP 0x770a7f
    goto L00770a7f;
  }
  L00770a7c: { // 0x770a7c: 80cc04 OR AH,4
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))|(4u),8,flags)) & 0xffu) << 8);
  }
  L00770a7f: { // 0x770a7f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x770a81: 81e100000300 AND ECX,0x30000
    s.cx = integer::logical((s.cx)&(0x00030000u),32,flags);
  }
  { // 0x770a87: 740c JZ 0x770a95
    if(integer::condition("JZ",flags)) goto L00770a95;
  }
  { // 0x770a89: 81f900000100 CMP ECX,0x10000
    (void)integer::sub(s.cx,0x00010000u,32,flags);
  }
  { // 0x770a8f: 7506 JNZ 0x770a97
    if(integer::condition("JNZ",flags)) goto L00770a97;
  }
  { // 0x770a91: 0bc6 OR EAX,ESI
    s.ax = integer::logical((s.ax)|(s.si),32,flags);
  }
  { // 0x770a93: eb02 JMP 0x770a97
    goto L00770a97;
  }
  L00770a95: { // 0x770a95: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00770a97: { // 0x770a97: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x770a98: f7c300000400 TEST EBX,0x40000
    (void)integer::logical((s.bx)&(0x00040000u),32,flags);
  }
  { // 0x770a9e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x770a9f: 7403 JZ 0x770aa4
    if(integer::condition("JZ",flags)) goto L00770aa4;
  }
  { // 0x770aa1: 80cc10 OR AH,0x10
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))|(0x00000010u),8,flags)) & 0xffu) << 8);
  }
  L00770aa4: { // 0x770aa4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,6>& entries_a() {
  static const std::array<Entry,6> entries{{
    {0x18ccf0u,f_0018ccf0},
    {0x18d560u,f_0018d560},
    {0x18d7a0u,f_0018d7a0},
    {0x370914u,f_00370914},
    {0x37098au,f_0037098a},
    {0x370a1cu,f_00370a1c},
  }}; return entries;
}
} // namespace ra2::recovered::floating_composed_b43
