#include "recovered/recovery_b230_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b230 {
namespace {
void f_002b6e80(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_00105da0(Memory&,State&,Frame&,const Operations&);
void f_002cdab0(Memory&,State&,Frame&,const Operations&);
void f_00307fe0(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void f_000cd9f0(Memory&,State&,Frame&,const Operations&);
void f_000b8850(Memory&,State&,Frame&,const Operations&);
void f_0001b270(Memory&,State&,Frame&,const Operations&);
void f_001cd4d0(Memory&,State&,Frame&,const Operations&);
void f_0018ce60(Memory&,State&,Frame&,const Operations&);
void f_0018ce90(Memory&,State&,Frame&,const Operations&);
void f_0018d7a0(Memory&,State&,Frame&,const Operations&);
void f_0018e180(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_000ba140(Memory&,State&,Frame&,const Operations&);
void f_000ba0f0(Memory&,State&,Frame&,const Operations&);
void f_00131370(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_002b6e80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6e80: { // 0x6b6e80: 81ecc8000000 SUB ESP,0xc8
    f.sp = integer::sub(f.sp,0x000000c8u,32,flags);
  }
  L006b6e86: { // 0x6b6e86: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b6e87: { // 0x6b6e87: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L006b6e89: { // 0x6b6e89: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006b6e8a: { // 0x6b6e8a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b6e8b: { // 0x6b6e8b: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L006b6e8d: { // 0x6b6e8d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b6e8e: { // 0x6b6e8e: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7040660u); flags=s.arithmetic_flags;
  }
  L006b6e94: { // 0x6b6e94: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L006b6e96: { // 0x6b6e96: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L006b6e98: { // 0x6b6e98: 8b8424e0000000 MOV EAX,dword ptr [ESP + 0xe0]
    s.ax = m.r32((f.sp+0x000000e0u));
  }
  L006b6e9f: { // 0x6b6e9f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006b6ea1: { // 0x6b6ea1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b6ea2: { // 0x6b6ea2: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7040680u); flags=s.arithmetic_flags;
  }
  L006b6ea8: { // 0x6b6ea8: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L006b6eab: { // 0x6b6eab: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L006b6eae: { // 0x6b6eae: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L006b6eb1: { // 0x6b6eb1: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L006b6eb5: { // 0x6b6eb5: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006b6eb7: { // 0x6b6eb7: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L006b6ebb: { // 0x6b6ebb: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L006b6ebf: { // 0x6b6ebf: 0f84b8000000 JZ 0x006b6f7d
    if(integer::condition("JZ",flags)) goto L006b6f7d;
  }
  L006b6ec5: { // 0x6b6ec5: f6431404 TEST byte ptr [EBX + 0x14],0x4
    (void)integer::logical((m.r8((s.bx+0x00000014u)))&(0x00000004u),8,flags);
  }
  L006b6ec9: { // 0x6b6ec9: 0f84ae000000 JZ 0x006b6f7d
    if(integer::condition("JZ",flags)) goto L006b6f7d;
  }
  L006b6ecf: { // 0x6b6ecf: 8b8364050000 MOV EAX,dword ptr [EBX + 0x564]
    s.ax = m.r32((s.bx+0x00000564u));
  }
  L006b6ed5: { // 0x6b6ed5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b6ed7: { // 0x6b6ed7: 0f84a0000000 JZ 0x006b6f7d
    if(integer::condition("JZ",flags)) goto L006b6f7d;
  }
  L006b6edd: { // 0x6b6edd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b6edf: { // 0x6b6edf: 750a JNZ 0x006b6eeb
    if(integer::condition("JNZ",flags)) goto L006b6eeb;
  }
  L006b6ee1: { // 0x6b6ee1: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  L006b6ee6: { // 0x6b6ee6: e885a30c00 CALL 0x00781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,7040747u); flags=s.arithmetic_flags;
  }
  L006b6eeb: { // 0x6b6eeb: 8b8364050000 MOV EAX,dword ptr [EBX + 0x564]
    s.ax = m.r32((s.bx+0x00000564u));
  }
  L006b6ef1: { // 0x6b6ef1: 8d9424a8000000 LEA EDX,[ESP + 0xa8]
    s.dx = (f.sp+0x000000a8u);
  }
  L006b6ef8: { // 0x6b6ef8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b6efa: { // 0x6b6efa: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006b6efb: { // 0x6b6efb: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b6efd: { // 0x6b6efd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b6efe: { // 0x6b6efe: ff5124 CALL dword ptr [ECX + 0x24]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000024u)),7040769u); flags=s.arithmetic_flags;
  }
  L006b6f01: { // 0x6b6f01: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b6f02: { // 0x6b6f02: 8d4c247c LEA ECX,[ESP + 0x7c]
    s.cx = (f.sp+0x0000007cu);
  }
  L006b6f06: { // 0x6b6f06: e8055dedff CALL 0x0058cc10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058cc10u,7040779u); flags=s.arithmetic_flags;
  }
  L006b6f0b: { // 0x6b6f0b: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L006b6f0d: { // 0x6b6f0d: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L006b6f12: { // 0x6b6f12: 8d742478 LEA ESI,[ESP + 0x78]
    s.si = (f.sp+0x00000078u);
  }
  L006b6f16: { // 0x6b6f16: 8d7c2448 LEA EDI,[ESP + 0x48]
    s.di = (f.sp+0x00000048u);
  }
  L006b6f1a: { // 0x6b6f1a: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L006b6f1c: { // 0x6b6f1c: 8d4c2438 LEA ECX,[ESP + 0x38]
    s.cx = (f.sp+0x00000038u);
  }
  L006b6f20: { // 0x6b6f20: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b6f21: { // 0x6b6f21: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006b6f23: { // 0x6b6f23: ff9088020000 CALL dword ptr [EAX + 0x288]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000288u)),7040809u); flags=s.arithmetic_flags;
  }
  L006b6f29: { // 0x6b6f29: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L006b6f2d: { // 0x6b6f2d: 8d8be0020000 LEA ECX,[EBX + 0x2e0]
    s.cx = (s.bx+0x000002e0u);
  }
  L006b6f33: { // 0x6b6f33: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006b6f34: { // 0x6b6f34: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006b6f36: { // 0x6b6f36: e81519e0ff CALL 0x004b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,7040827u); flags=s.arithmetic_flags;
  }
  L006b6f3b: { // 0x6b6f3b: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006b6f3d: { // 0x6b6f3d: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L006b6f3f: { // 0x6b6f3f: c1e80a SHR EAX,0xa
    s.ax = integer::shift(s.ax,0x0000000au,32,flags,integer::Shift::right);
  }
  L006b6f42: { // 0x6b6f42: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006b6f43: { // 0x6b6f43: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L006b6f45: { // 0x6b6f45: 83e01f AND EAX,0x1f
    s.ax = integer::logical((s.ax)&(0x0000001fu),32,flags);
  }
  L006b6f48: { // 0x6b6f48: c1e90a SHR ECX,0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  L006b6f4b: { // 0x6b6f4b: 83e808 SUB EAX,0x8
    s.ax = integer::sub(s.ax,0x00000008u,32,flags);
  }
  L006b6f4e: { // 0x6b6f4e: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006b6f4f: { // 0x6b6f4f: d1e9 SHR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::right);
  }
  L006b6f51: { // 0x6b6f51: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006b6f55: { // 0x6b6f55: 83e11f AND ECX,0x1f
    s.cx = integer::logical((s.cx)&(0x0000001fu),32,flags);
  }
  L006b6f58: { // 0x6b6f58: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006b6f5c: { // 0x6b6f5c: 83e908 SUB ECX,0x8
    s.cx = integer::sub(s.cx,0x00000008u,32,flags);
  }
  L006b6f5f: { // 0x6b6f5f: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L006b6f63: { // 0x6b6f63: dc0d90807800 FMUL double ptr [0x00788090]
    const auto address=(0x00788090u);
    s.fp.multiply64(read64(m,address));
  }
  L006b6f69: { // 0x6b6f69: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006b6f6d: { // 0x6b6f6d: dc0d90807800 FMUL double ptr [0x00788090]
    const auto address=(0x00788090u);
    s.fp.multiply64(read64(m,address));
  }
  L006b6f73: { // 0x6b6f73: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L006b6f75: { // 0x6b6f75: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006b6f79: { // 0x6b6f79: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L006b6f7b: { // 0x6b6f7b: eb38 JMP 0x006b6fb5
    goto L006b6fb5;
  }
  L006b6f7d: { // 0x6b6f7d: 8d4c2448 LEA ECX,[ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L006b6f81: { // 0x6b6f81: e8da5eedff CALL 0x0058ce60
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058ce60u,7040902u); flags=s.arithmetic_flags;
  }
  L006b6f86: { // 0x6b6f86: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L006b6f88: { // 0x6b6f88: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L006b6f8c: { // 0x6b6f8c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b6f8d: { // 0x6b6f8d: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006b6f8f: { // 0x6b6f8f: ff9288020000 CALL dword ptr [EDX + 0x288]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000288u)),7040917u); flags=s.arithmetic_flags;
  }
  L006b6f95: { // 0x6b6f95: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b6f97: { // 0x6b6f97: c1e90a SHR ECX,0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  L006b6f9a: { // 0x6b6f9a: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006b6f9b: { // 0x6b6f9b: d1e9 SHR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::right);
  }
  L006b6f9d: { // 0x6b6f9d: 83e11f AND ECX,0x1f
    s.cx = integer::logical((s.cx)&(0x0000001fu),32,flags);
  }
  L006b6fa0: { // 0x6b6fa0: 83e908 SUB ECX,0x8
    s.cx = integer::sub(s.cx,0x00000008u,32,flags);
  }
  L006b6fa3: { // 0x6b6fa3: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L006b6fa7: { // 0x6b6fa7: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006b6fab: { // 0x6b6fab: dc0d90807800 FMUL double ptr [0x00788090]
    const auto address=(0x00788090u);
    s.fp.multiply64(read64(m,address));
  }
  L006b6fb1: { // 0x6b6fb1: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006b6fb5: { // 0x6b6fb5: db853c060000 FILD dword ptr [EBP + 0x63c]
    const auto address=(s.bp+0x0000063cu);
    s.fp.load_integer32(m.r32(address));
  }
  L006b6fbb: { // 0x6b6fbb: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b6fbd: { // 0x6b6fbd: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b6fbf: { // 0x6b6fbf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b6fc0: { // 0x6b6fc0: 8d4c2454 LEA ECX,[ESP + 0x54]
    s.cx = (f.sp+0x00000054u);
  }
  L006b6fc4: { // 0x6b6fc4: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006b6fc7: { // 0x6b6fc7: e8c45eedff CALL 0x0058ce90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058ce90u,7040972u); flags=s.arithmetic_flags;
  }
  L006b6fcc: { // 0x6b6fcc: dd442418 FLD double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load64(read64(m,address));
  }
  L006b6fd0: { // 0x6b6fd0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b6fd1: { // 0x6b6fd1: 8d4c244c LEA ECX,[ESP + 0x4c]
    s.cx = (f.sp+0x0000004cu);
  }
  L006b6fd5: { // 0x6b6fd5: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006b6fd8: { // 0x6b6fd8: e8c367edff CALL 0x0058d7a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058d7a0u,7040989u); flags=s.arithmetic_flags;
  }
  L006b6fdd: { // 0x6b6fdd: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L006b6fe1: { // 0x6b6fe1: 8b9310030000 MOV EDX,dword ptr [EBX + 0x310]
    s.dx = m.r32((s.bx+0x00000310u));
  }
  L006b6fe7: { // 0x6b6fe7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b6fe8: { // 0x6b6fe8: 81e201000080 AND EDX,0x80000001
    s.dx = integer::logical((s.dx)&(0x80000001u),32,flags);
  }
  L006b6fee: { // 0x6b6fee: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006b6ff1: { // 0x6b6ff1: 7905 JNS 0x006b6ff8
    if(integer::condition("JNS",flags)) goto L006b6ff8;
  }
  L006b6ff3: { // 0x6b6ff3: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L006b6ff4: { // 0x6b6ff4: 83cafe OR EDX,0xfffffffe
    s.dx = integer::logical((s.dx)|(0xfffffffeu),32,flags);
  }
  L006b6ff7: { // 0x6b6ff7: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L006b6ff8: { // 0x6b6ff8: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L006b6ffa: { // 0x6b6ffa: 1bd2 SBB EDX,EDX
    s.dx = integer::sub(s.dx,s.dx,32,flags,flags&integer::CF);
  }
  L006b6ffc: { // 0x6b6ffc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b6ffd: { // 0x6b6ffd: 83e2fe AND EDX,0xfffffffe
    s.dx = integer::logical((s.dx)&(0xfffffffeu),32,flags);
  }
  L006b7000: { // 0x6b7000: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L006b7001: { // 0x6b7001: 0faf54241c IMUL EDX,dword ptr [ESP + 0x1c]
    s.dx = integer::imul(s.dx,m.r32((f.sp+0x0000001cu)),32,flags);
  }
  L006b7006: { // 0x6b7006: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L006b700a: { // 0x6b700a: db44241c FILD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load_integer32(m.r32(address));
  }
  L006b700e: { // 0x6b700e: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006b7011: { // 0x6b7011: db44242c FILD dword ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load_integer32(m.r32(address));
  }
  L006b7015: { // 0x6b7015: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b7016: { // 0x6b7016: 8d4c2454 LEA ECX,[ESP + 0x54]
    s.cx = (f.sp+0x00000054u);
  }
  L006b701a: { // 0x6b701a: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006b701d: { // 0x6b701d: e86e5eedff CALL 0x0058ce90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058ce90u,7041058u); flags=s.arithmetic_flags;
  }
  L006b7022: { // 0x6b7022: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  L006b7026: { // 0x6b7026: 8d542448 LEA EDX,[ESP + 0x48]
    s.dx = (f.sp+0x00000048u);
  }
  L006b702a: { // 0x6b702a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b702b: { // 0x6b702b: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L006b702f: { // 0x6b702f: c744243000000000 MOV dword ptr [ESP + 0x30],0x0
    m.w32((f.sp+0x00000030u), 0x00000000u);
  }
  L006b7037: { // 0x6b7037: c744243400000000 MOV dword ptr [ESP + 0x34],0x0
    m.w32((f.sp+0x00000034u), 0x00000000u);
  }
  L006b703f: { // 0x6b703f: c744243800000000 MOV dword ptr [ESP + 0x38],0x0
    m.w32((f.sp+0x00000038u), 0x00000000u);
  }
  L006b7047: { // 0x6b7047: e83471edff CALL 0x0058e180
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e180u,7041100u); flags=s.arithmetic_flags;
  }
  L006b704c: { // 0x6b704c: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b704e: { // 0x6b704e: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L006b7052: { // 0x6b7052: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006b7055: { // 0x6b7055: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L006b7059: { // 0x6b7059: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L006b705c: { // 0x6b705c: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L006b7060: { // 0x6b7060: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L006b7064: { // 0x6b7064: e8e7390b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7041129u); flags=s.arithmetic_flags;
  }
  L006b7069: { // 0x6b7069: d944241c FLD float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load32(m.r32(address));
  }
  L006b706d: { // 0x6b706d: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L006b706f: { // 0x6b706f: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006b7071: { // 0x6b7071: e8da390b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7041142u); flags=s.arithmetic_flags;
  }
  L006b7076: { // 0x6b7076: d9442420 FLD float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L006b707a: { // 0x6b707a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006b707c: { // 0x6b707c: e8cf390b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7041153u); flags=s.arithmetic_flags;
  }
  L006b7081: { // 0x6b7081: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L006b7083: { // 0x6b7083: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L006b7085: { // 0x6b7085: 8d44243c LEA EAX,[ESP + 0x3c]
    s.ax = (f.sp+0x0000003cu);
  }
  L006b7089: { // 0x6b7089: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006b708b: { // 0x6b708b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b708c: { // 0x6b708c: ff92a8000000 CALL dword ptr [EDX + 0xa8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000a8u)),7041170u); flags=s.arithmetic_flags;
  }
  L006b7092: { // 0x6b7092: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b7094: { // 0x6b7094: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006b7097: { // 0x6b7097: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L006b709a: { // 0x6b709a: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L006b709c: { // 0x6b709c: 8bb424dc000000 MOV ESI,dword ptr [ESP + 0xdc]
    s.si = m.r32((f.sp+0x000000dcu));
  }
  L006b70a3: { // 0x6b70a3: 03d7 ADD EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
  L006b70a5: { // 0x6b70a5: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L006b70a7: { // 0x6b70a7: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L006b70a9: { // 0x6b70a9: 890f MOV dword ptr [EDI],ECX
    m.w32((s.di), s.cx);
  }
  L006b70ab: { // 0x6b70ab: 895704 MOV dword ptr [EDI + 0x4],EDX
    m.w32((s.di+0x00000004u), s.dx);
  }
  L006b70ae: { // 0x6b70ae: 894708 MOV dword ptr [EDI + 0x8],EAX
    m.w32((s.di+0x00000008u), s.ax);
  }
  L006b70b1: { // 0x6b70b1: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006b70b3: { // 0x6b70b3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b70b4: { // 0x6b70b4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b70b5: { // 0x6b70b5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b70b6: { // 0x6b70b6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b70b7: { // 0x6b70b7: 81c4c8000000 ADD ESP,0xc8
    f.sp = integer::add(f.sp,0x000000c8u,32,flags);
  }
  L006b70bd: { // 0x6b70bd: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {s.ax=m.r32(s.cx);if(m.r32(s.ax+0x84)!=0x505da0)throw std::domain_error("230 actual tail getter");f_00105da0(m,s,f,op);return;}
void f_00105da0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00505da0: { // 0x505da0: 8b81a8050000 MOV EAX, dword ptr [ECX + 0x5a8]
    s.ax = m.r32((s.cx+0x000005a8u));
  }
  L00505da6: { // 0x505da6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002cdab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cdab0: { // 0x6cdab0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cdab1: { // 0x6cdab1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdab2: { // 0x6cdab2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L006cdab6: { // 0x6cdab6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006cdab8: { // 0x6cdab8: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L006cdabb: { // 0x6cdabb: 7507 JNZ 0x006cdac4
    if(integer::condition("JNZ",flags)) goto L006cdac4;
  }
  L006cdabd: { // 0x6cdabd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cdabe: { // 0x6cdabe: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cdac0: { // 0x6cdac0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdac1: { // 0x6cdac1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006cdac4: { // 0x6cdac4: 8d8e18010000 LEA ECX,[ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  L006cdaca: { // 0x6cdaca: e811a50300 CALL 0x00707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7133903u); flags=s.arithmetic_flags;
  }
  L006cdacf: { // 0x6cdacf: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cdad1: { // 0x6cdad1: 741b JZ 0x006cdaee
    if(integer::condition("JZ",flags)) goto L006cdaee;
  }
  L006cdad3: { // 0x6cdad3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cdad5: { // 0x6cdad5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdad6: { // 0x6cdad6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cdad8: { // 0x6cdad8: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7133918u); flags=s.arithmetic_flags;
  }
  L006cdade: { // 0x6cdade: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006cdae0: { // 0x6cdae0: e86b700000 CALL 0x006d4b50
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b50u,7133925u); flags=s.arithmetic_flags;
  }
  L006cdae5: { // 0x6cdae5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006cdae7: { // 0x6cdae7: 7405 JZ 0x006cdaee
    if(integer::condition("JZ",flags)) goto L006cdaee;
  }
  L006cdae9: { // 0x6cdae9: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006cdaec: { // 0x6cdaec: 7512 JNZ 0x006cdb00
    if(integer::condition("JNZ",flags)) goto L006cdb00;
  }
  L006cdaee: { // 0x6cdaee: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cdaf0: { // 0x6cdaf0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdaf1: { // 0x6cdaf1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006cdaf3: { // 0x6cdaf3: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7133945u); flags=s.arithmetic_flags;
  }
  L006cdaf9: { // 0x6cdaf9: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006cdafb: { // 0x6cdafb: e830700000 CALL 0x006d4b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b30u,7133952u); flags=s.arithmetic_flags;
  }
  L006cdb00: { // 0x6cdb00: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cdb01: { // 0x6cdb01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdb02: { // 0x6cdb02: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00307fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00707fe0: { // 0x707fe0: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707fe2: { // 0x707fe2: dc1df8567800 FCOMP double ptr [0x007856f8]
    const auto address=(0x007856f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707fe8: { // 0x707fe8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707fea: { // 0x707fea: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00707fed: { // 0x707fed: 7506 JNZ 0x00707ff5
    if(integer::condition("JNZ",flags)) goto L00707ff5;
  }
  L00707fef: { // 0x707fef: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00707ff4: { // 0x707ff4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707ff5: { // 0x707ff5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00707ff7: { // 0x707ff7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002d4b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4b30: { // 0x6d4b30: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L006d4b34: { // 0x6d4b34: 8d14c500000000 LEA EDX,[EAX*0x8 + 0x0]
    s.dx = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L006d4b3b: { // 0x6d4b3b: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006d4b3d: { // 0x6d4b3d: 8d84914c070000 LEA EAX,[ECX + EDX*0x4 + 0x74c]
    s.ax = (s.cx+(s.dx * 0x00000004u)+0x0000074cu);
  }
  L006d4b44: { // 0x6d4b44: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000cd9f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004cd9f0: { // 0x4cd9f0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004cd9f1: { // 0x4cd9f1: 8d442400 LEA EAX, [ESP]
    s.ax = (f.sp);
  }
  L004cd9f5: { // 0x4cd9f5: 81c1e0020000 ADD ECX, 0x2E0
    s.cx = integer::add(s.cx,0x000002e0u,32,flags);
  }
  L004cd9fb: { // 0x4cd9fb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004cd9fc: { // 0x4cd9fc: e84faefeff CALL 0x4B8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,5036545u); flags=s.arithmetic_flags;
  }
  L004cda01: { // 0x4cda01: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004cda03: { // 0x4cda03: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L004cda07: { // 0x4cda07: 8908 MOV dword ptr [EAX], ECX
    m.w32((s.ax), s.cx);
  }
  L004cda09: { // 0x4cda09: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004cda0a: { // 0x4cda0a: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000b8850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004b8850: { // 0x4b8850: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004b8851: { // 0x4b8851: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004b8852: { // 0x4b8852: 668b5914 MOV BX,word ptr [ECX + 0x14]
    s.bx = with_ax(s.bx, m.r16((s.cx+0x00000014u)));
  }
  L004b8856: { // 0x4b8856: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004b8857: { // 0x4b8857: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004b8858: { // 0x4b8858: 6685db TEST BX,BX
    (void)integer::logical(((s.bx & 0xffffu))&((s.bx & 0xffffu)),16,flags);
  }
  L004b885b: { // 0x4b885b: 7e7d JLE 0x004b88da
    if(integer::condition("JLE",flags)) goto L004b88da;
  }
  L004b885d: { // 0x4b885d: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L004b8860: { // 0x4b8860: 8b4110 MOV EAX,dword ptr [ECX + 0x10]
    s.ax = m.r32((s.cx+0x00000010u));
  }
  L004b8863: { // 0x4b8863: 8b3d6c89a200 MOV EDI,dword ptr [0x00a2896c]
    s.di = m.r32((0x00a2896cu));
  }
  L004b8869: { // 0x4b8869: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  L004b886c: { // 0x4b886c: 740a JZ 0x004b8878
    if(integer::condition("JZ",flags)) goto L004b8878;
  }
  L004b886e: { // 0x4b886e: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L004b8870: { // 0x4b8870: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L004b8872: { // 0x4b8872: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L004b8874: { // 0x4b8874: 7d64 JGE 0x004b88da
    if(integer::condition("JGE",flags)) goto L004b88da;
  }
  L004b8876: { // 0x4b8876: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004b8878: { // 0x4b8878: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004b887a: { // 0x4b887a: 745e JZ 0x004b88da
    if(integer::condition("JZ",flags)) goto L004b88da;
  }
  L004b887c: { // 0x4b887c: 668b01 MOV AX,word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L004b887f: { // 0x4b887f: 662b4104 SUB AX,word ptr [ECX + 0x4]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.cx+0x00000004u)),16,flags));
  }
  L004b8883: { // 0x4b8883: 0fbfdb MOVSX EBX,BX
    s.bx = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L004b8886: { // 0x4b8886: 0fbff0 MOVSX ESI,AX
    s.si = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004b8889: { // 0x4b8889: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004b888b: { // 0x4b888b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b888c: { // 0x4b888c: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004b888e: { // 0x4b888e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004b8890: { // 0x4b8890: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b8891: { // 0x4b8891: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004b8893: { // 0x4b8893: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004b8895: { // 0x4b8895: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L004b8899: { // 0x4b8899: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L004b889c: { // 0x4b889c: 7e27 JLE 0x004b88c5
    if(integer::condition("JLE",flags)) goto L004b88c5;
  }
  L004b889e: { // 0x4b889e: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L004b88a1: { // 0x4b88a1: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L004b88a4: { // 0x4b88a4: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L004b88a7: { // 0x4b88a7: 740a JZ 0x004b88b3
    if(integer::condition("JZ",flags)) goto L004b88b3;
  }
  L004b88a9: { // 0x4b88a9: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L004b88ab: { // 0x4b88ab: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004b88ad: { // 0x4b88ad: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004b88af: { // 0x4b88af: 7d25 JGE 0x004b88d6
    if(integer::condition("JGE",flags)) goto L004b88d6;
  }
  L004b88b1: { // 0x4b88b1: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L004b88b3: { // 0x4b88b3: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004b88b5: { // 0x4b88b5: 0fbff8 MOVSX EDI,AX
    s.di = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004b88b8: { // 0x4b88b8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004b88ba: { // 0x4b88ba: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b88bb: { // 0x4b88bb: f7ff IDIV EDI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.di,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004b88bd: { // 0x4b88bd: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L004b88c0: { // 0x4b88c0: 662944240c SUB word ptr [ESP + 0xc],AX
    m.w16((f.sp+0x0000000cu), integer::sub(m.r16((f.sp+0x0000000cu)),(s.ax & 0xffffu),16,flags));
  }
  L004b88c5: { // 0x4b88c5: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004b88c9: { // 0x4b88c9: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L004b88cd: { // 0x4b88cd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004b88ce: { // 0x4b88ce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004b88cf: { // 0x4b88cf: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L004b88d1: { // 0x4b88d1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004b88d2: { // 0x4b88d2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004b88d3: { // 0x4b88d3: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004b88d6: { // 0x4b88d6: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004b88d8: { // 0x4b88d8: ebdb JMP 0x004b88b5
    goto L004b88b5;
  }
  L004b88da: { // 0x4b88da: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004b88de: { // 0x4b88de: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004b88e0: { // 0x4b88e0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004b88e1: { // 0x4b88e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004b88e2: { // 0x4b88e2: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L004b88e4: { // 0x4b88e4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004b88e5: { // 0x4b88e5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004b88e6: { // 0x4b88e6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0001b270(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b270: { // 0x41b270: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0041b272: { // 0x41b272: 83ec0c SUB ESP, 0xC
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0041b275: { // 0x41b275: 8d542400 LEA EDX, [ESP]
    s.dx = (f.sp);
  }
  L0041b279: { // 0x41b279: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041b27a: { // 0x41b27a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0041b27b: { // 0x41b27b: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4305534u); flags=s.arithmetic_flags;
  }
  L0041b27e: { // 0x41b27e: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0041b280: { // 0x41b280: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0041b284: { // 0x41b284: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L0041b286: { // 0x41b286: 8b31 MOV ESI, dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L0041b288: { // 0x41b288: 8932 MOV dword ptr [EDX], ESI
    m.w32((s.dx), s.si);
  }
  L0041b28a: { // 0x41b28a: 8b7104 MOV ESI, dword ptr [ECX + 4]
    s.si = m.r32((s.cx+4u));
  }
  L0041b28d: { // 0x41b28d: 897204 MOV dword ptr [EDX + 4], ESI
    m.w32((s.dx+4u), s.si);
  }
  L0041b290: { // 0x41b290: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041b291: { // 0x41b291: 8b4908 MOV ECX, dword ptr [ECX + 8]
    s.cx = m.r32((s.cx+8u));
  }
  L0041b294: { // 0x41b294: 894a08 MOV dword ptr [EDX + 8], ECX
    m.w32((s.dx+8u), s.cx);
  }
  L0041b297: { // 0x41b297: 83c40c ADD ESP, 0xC
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0041b29a: { // 0x41b29a: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001cd4d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cd4d0: { // 0x5cd4d0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L005cd4d4: { // 0x5cd4d4: 81c188000000 ADD ECX,0x88
    s.cx = integer::add(s.cx,0x00000088u,32,flags);
  }
  L005cd4da: { // 0x5cd4da: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cd4db: { // 0x5cd4db: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L005cd4dd: { // 0x5cd4dd: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L005cd4df: { // 0x5cd4df: 8932 MOV dword ptr [EDX],ESI
    m.w32((s.dx), s.si);
  }
  L005cd4e1: { // 0x5cd4e1: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  L005cd4e4: { // 0x5cd4e4: 897204 MOV dword ptr [EDX + 0x4],ESI
    m.w32((s.dx+0x00000004u), s.si);
  }
  L005cd4e7: { // 0x5cd4e7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cd4e8: { // 0x5cd4e8: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L005cd4eb: { // 0x5cd4eb: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L005cd4ee: { // 0x5cd4ee: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018ce60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058ce60: { // 0x58ce60: ba0000803f MOV EDX,0x3f800000
    s.dx = 0x3f800000u;
  }
  L0058ce65: { // 0x58ce65: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0058ce67: { // 0x58ce67: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0058ce69: { // 0x58ce69: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L0058ce6c: { // 0x58ce6c: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L0058ce6f: { // 0x58ce6f: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L0058ce72: { // 0x58ce72: 894110 MOV dword ptr [ECX + 0x10],EAX
    m.w32((s.cx+0x00000010u), s.ax);
  }
  L0058ce75: { // 0x58ce75: 895114 MOV dword ptr [ECX + 0x14],EDX
    m.w32((s.cx+0x00000014u), s.dx);
  }
  L0058ce78: { // 0x58ce78: 894118 MOV dword ptr [ECX + 0x18],EAX
    m.w32((s.cx+0x00000018u), s.ax);
  }
  L0058ce7b: { // 0x58ce7b: 89411c MOV dword ptr [ECX + 0x1c],EAX
    m.w32((s.cx+0x0000001cu), s.ax);
  }
  L0058ce7e: { // 0x58ce7e: 894120 MOV dword ptr [ECX + 0x20],EAX
    m.w32((s.cx+0x00000020u), s.ax);
  }
  L0058ce81: { // 0x58ce81: 894124 MOV dword ptr [ECX + 0x24],EAX
    m.w32((s.cx+0x00000024u), s.ax);
  }
  L0058ce84: { // 0x58ce84: 895128 MOV dword ptr [ECX + 0x28],EDX
    m.w32((s.cx+0x00000028u), s.dx);
  }
  L0058ce87: { // 0x58ce87: 89412c MOV dword ptr [ECX + 0x2c],EAX
    m.w32((s.cx+0x0000002cu), s.ax);
  }
  L0058ce8a: { // 0x58ce8a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0018ce90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058ce90: { // 0x58ce90: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0058ce94: { // 0x58ce94: d84904 FMUL float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
  L0058ce97: { // 0x58ce97: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L0058ce9b: { // 0x58ce9b: d84908 FMUL float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
  L0058ce9e: { // 0x58ce9e: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058cea0: { // 0x58cea0: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058cea4: { // 0x58cea4: d809 FMUL float ptr [ECX]
    const auto address=(s.cx);
    s.fp.multiply32(m.r32(address));
  }
  L0058cea6: { // 0x58cea6: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058cea8: { // 0x58cea8: d8410c FADD float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    s.fp.add32(m.r32(address));
  }
  L0058ceab: { // 0x58ceab: d9590c FSTP float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058ceae: { // 0x58ceae: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058ceb2: { // 0x58ceb2: d84910 FMUL float ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    s.fp.multiply32(m.r32(address));
  }
  L0058ceb5: { // 0x58ceb5: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0058ceb9: { // 0x58ceb9: d84914 FMUL float ptr [ECX + 0x14]
    const auto address=(s.cx+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058cebc: { // 0x58cebc: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058cebe: { // 0x58cebe: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L0058cec2: { // 0x58cec2: d84918 FMUL float ptr [ECX + 0x18]
    const auto address=(s.cx+0x00000018u);
    s.fp.multiply32(m.r32(address));
  }
  L0058cec5: { // 0x58cec5: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058cec7: { // 0x58cec7: d8411c FADD float ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    s.fp.add32(m.r32(address));
  }
  L0058ceca: { // 0x58ceca: d9591c FSTP float ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058cecd: { // 0x58cecd: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058ced1: { // 0x58ced1: d84920 FMUL float ptr [ECX + 0x20]
    const auto address=(s.cx+0x00000020u);
    s.fp.multiply32(m.r32(address));
  }
  L0058ced4: { // 0x58ced4: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0058ced8: { // 0x58ced8: d84924 FMUL float ptr [ECX + 0x24]
    const auto address=(s.cx+0x00000024u);
    s.fp.multiply32(m.r32(address));
  }
  L0058cedb: { // 0x58cedb: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058cedd: { // 0x58cedd: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L0058cee1: { // 0x58cee1: d84928 FMUL float ptr [ECX + 0x28]
    const auto address=(s.cx+0x00000028u);
    s.fp.multiply32(m.r32(address));
  }
  L0058cee4: { // 0x58cee4: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058cee6: { // 0x58cee6: d8412c FADD float ptr [ECX + 0x2c]
    const auto address=(s.cx+0x0000002cu);
    s.fp.add32(m.r32(address));
  }
  L0058cee9: { // 0x58cee9: d9592c FSTP float ptr [ECX + 0x2c]
    const auto address=(s.cx+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058ceec: { // 0x58ceec: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0018d7a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058d7a0: { // 0x58d7a0: 83ec08 SUB ESP,8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L0058d7a3: { // 0x58d7a3: d944240c FLD float ptr [ESP+0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L0058d7a7: { // 0x58d7a7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058d7a8: { // 0x58d7a8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058d7a9: { // 0x58d7a9: dd5c2408 FSTP double ptr [ESP+8]
    const auto address=(f.sp+8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058d7ad: { // 0x58d7ad: 8b5c2408 MOV EBX,dword ptr [ESP+8]
    s.bx = m.r32((f.sp+8u));
  }
  L0058d7b1: { // 0x58d7b1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058d7b2: { // 0x58d7b2: 8b7c2410 MOV EDI,dword ptr [ESP+0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0058d7b6: { // 0x58d7b6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0058d7b8: { // 0x58d7b8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058d7b9: { // 0x58d7b9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058d7ba: { // 0x58d7ba: e881c9f2ff CALL 0x4ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,5822399u); flags=s.arithmetic_flags;
  }
  L0058d7bf: { // 0x58d7bf: d95c2420 FSTP float ptr [ESP+0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d7c3: { // 0x58d7c3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058d7c4: { // 0x58d7c4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058d7c5: { // 0x58d7c5: e826c9f2ff CALL 0x4ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,5822410u); flags=s.arithmetic_flags;
  }
  L0058d7ca: { // 0x58d7ca: d906 FLD float ptr [ESI]
    const auto address=(s.si);
    s.fp.load32(m.r32(address));
  }
  L0058d7cc: { // 0x58d7cc: d94604 FLD float ptr [ESI+4]
    const auto address=(s.si+4u);
    s.fp.load32(m.r32(address));
  }
  L0058d7cf: { // 0x58d7cf: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0058d7d1: { // 0x58d7d1: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0058d7d3: { // 0x58d7d3: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0058d7d5: { // 0x58d7d5: d84c2428 FMUL float ptr [ESP+0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d7d9: { // 0x58d7d9: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0058d7dc: { // 0x58d7dc: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058d7de: { // 0x58d7de: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058d7df: { // 0x58d7df: d91e FSTP float ptr [ESI]
    const auto address=(s.si);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d7e1: { // 0x58d7e1: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d7e5: { // 0x58d7e5: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0058d7e7: { // 0x58d7e7: d8ca FMUL ST2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0058d7e9: { // 0x58d7e9: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0058d7eb: { // 0x58d7eb: d95e04 FSTP float ptr [ESI+4]
    const auto address=(s.si+4u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d7ee: { // 0x58d7ee: d94610 FLD float ptr [ESI+0x10]
    const auto address=(s.si+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L0058d7f1: { // 0x58d7f1: d94614 FLD float ptr [ESI+0x14]
    const auto address=(s.si+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L0058d7f4: { // 0x58d7f4: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0058d7f6: { // 0x58d7f6: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0058d7f8: { // 0x58d7f8: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0058d7fa: { // 0x58d7fa: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d7fe: { // 0x58d7fe: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058d800: { // 0x58d800: d95e10 FSTP float ptr [ESI+0x10]
    const auto address=(s.si+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d803: { // 0x58d803: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d807: { // 0x58d807: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0058d809: { // 0x58d809: d8ca FMUL ST2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0058d80b: { // 0x58d80b: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0058d80d: { // 0x58d80d: d95e14 FSTP float ptr [ESI+0x14]
    const auto address=(s.si+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d810: { // 0x58d810: d94620 FLD float ptr [ESI+0x20]
    const auto address=(s.si+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L0058d813: { // 0x58d813: d94624 FLD float ptr [ESI+0x24]
    const auto address=(s.si+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L0058d816: { // 0x58d816: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0058d818: { // 0x58d818: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0058d81a: { // 0x58d81a: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0058d81c: { // 0x58d81c: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d820: { // 0x58d820: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058d822: { // 0x58d822: d95e20 FSTP float ptr [ESI+0x20]
    const auto address=(s.si+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d825: { // 0x58d825: d84c2414 FMUL float ptr [ESP+0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
  L0058d829: { // 0x58d829: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0058d82b: { // 0x58d82b: d8ca FMUL ST2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
  L0058d82d: { // 0x58d82d: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0058d82f: { // 0x58d82f: d95e24 FSTP float ptr [ESI+0x24]
    const auto address=(s.si+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058d832: { // 0x58d832: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058d833: { // 0x58d833: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0058d834: { // 0x58d834: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0058d836: { // 0x58d836: 83c408 ADD ESP,8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L0058d839: { // 0x58d839: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
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
void f_000ba140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba140: { // 0x4ba140: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  L004ba144: { // 0x4ba144: d80d3c317c00 FMUL float ptr [0x007c313c]
    const auto address=(0x007c313cu);
    s.fp.multiply32(m.r32(address));
  }
  L004ba14a: { // 0x4ba14a: e801092b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4956495u); flags=s.arithmetic_flags;
  }
  L004ba14f: { // 0x4ba14f: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L004ba151: { // 0x4ba151: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004ba152: { // 0x4ba152: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004ba154: { // 0x4ba154: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
  L004ba157: { // 0x4ba157: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ba159: { // 0x4ba159: 25ff1f0080 AND EAX,0x80001fff
    s.ax = integer::logical((s.ax)&(0x80001fffu),32,flags);
  }
  L004ba15e: { // 0x4ba15e: 7910 JNS 0x004ba170
    if(integer::condition("JNS",flags)) goto L004ba170;
  }
  L004ba160: { // 0x4ba160: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004ba161: { // 0x4ba161: 0d00e0ffff OR EAX,0xffffe000
    s.ax = integer::logical((s.ax)|(0xffffe000u),32,flags);
  }
  L004ba166: { // 0x4ba166: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba167: { // 0x4ba167: 7907 JNS 0x004ba170
    if(integer::condition("JNS",flags)) goto L004ba170;
  }
  L004ba169: { // 0x4ba169: 0500280000 ADD EAX,0x2800
    s.ax = integer::add(s.ax,0x00002800u,32,flags);
  }
  L004ba16e: { // 0x4ba16e: eb05 JMP 0x004ba175
    goto L004ba175;
  }
  L004ba170: { // 0x4ba170: 0500080000 ADD EAX,0x800
    s.ax = integer::add(s.ax,0x00000800u,32,flags);
  }
  L004ba175: { // 0x4ba175: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004ba177: { // 0x4ba177: 7408 JZ 0x004ba181
    if(integer::condition("JZ",flags)) goto L004ba181;
  }
  L004ba179: { // 0x4ba179: 3dff270000 CMP EAX,0x27ff
    (void)integer::sub(s.ax,0x000027ffu,32,flags);
  }
  L004ba17e: { // 0x4ba17e: 7d01 JGE 0x004ba181
    if(integer::condition("JGE",flags)) goto L004ba181;
  }
  L004ba180: { // 0x4ba180: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba181: { // 0x4ba181: d9048504a17e00 FLD float ptr [EAX*0x4 + 0x7ea104]
    const auto address=((s.ax * 0x00000004u)+0x007ea104u);
    s.fp.load32(m.r32(address));
  }
  L004ba188: { // 0x4ba188: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ba0f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba0f0: { // 0x4ba0f0: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  L004ba0f4: { // 0x4ba0f4: d80d38317c00 FMUL float ptr [0x007c3138]
    const auto address=(0x007c3138u);
    s.fp.multiply32(m.r32(address));
  }
  L004ba0fa: { // 0x4ba0fa: e851092b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4956415u); flags=s.arithmetic_flags;
  }
  L004ba0ff: { // 0x4ba0ff: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L004ba101: { // 0x4ba101: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004ba102: { // 0x4ba102: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004ba104: { // 0x4ba104: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
  L004ba107: { // 0x4ba107: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ba109: { // 0x4ba109: 25ff1f0080 AND EAX,0x80001fff
    s.ax = integer::logical((s.ax)&(0x80001fffu),32,flags);
  }
  L004ba10e: { // 0x4ba10e: 790e JNS 0x004ba11e
    if(integer::condition("JNS",flags)) goto L004ba11e;
  }
  L004ba110: { // 0x4ba110: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004ba111: { // 0x4ba111: 0d00e0ffff OR EAX,0xffffe000
    s.ax = integer::logical((s.ax)|(0xffffe000u),32,flags);
  }
  L004ba116: { // 0x4ba116: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba117: { // 0x4ba117: 7905 JNS 0x004ba11e
    if(integer::condition("JNS",flags)) goto L004ba11e;
  }
  L004ba119: { // 0x4ba119: 0500200000 ADD EAX,0x2000
    s.ax = integer::add(s.ax,0x00002000u,32,flags);
  }
  L004ba11e: { // 0x4ba11e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004ba120: { // 0x4ba120: 7408 JZ 0x004ba12a
    if(integer::condition("JZ",flags)) goto L004ba12a;
  }
  L004ba122: { // 0x4ba122: 3dff1f0000 CMP EAX,0x1fff
    (void)integer::sub(s.ax,0x00001fffu,32,flags);
  }
  L004ba127: { // 0x4ba127: 7d01 JGE 0x004ba12a
    if(integer::condition("JGE",flags)) goto L004ba12a;
  }
  L004ba129: { // 0x4ba129: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba12a: { // 0x4ba12a: d9048504a17e00 FLD float ptr [EAX*0x4 + 0x7ea104]
    const auto address=((s.ax * 0x00000004u)+0x007ea104u);
    s.fp.load32(m.r32(address));
  }
  L004ba131: { // 0x4ba131: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00131370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00531370: { // 0x531370: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00531371: { // 0x531371: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00531373: { // 0x531373: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00531375: { // 0x531375: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00531376: { // 0x531376: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L0053137a: { // 0x53137a: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L0053137c: { // 0x53137c: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L00531382: { // 0x531382: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00531385: { // 0x531385: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L00531388: { // 0x531388: 8d4e20 LEA ECX,[ESI + 0x20]
    s.cx = (s.si+0x00000020u);
  }
  L0053138b: { // 0x53138b: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L00531390: { // 0x531390: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L00531393: { // 0x531393: 8939 MOV dword ptr [ECX],EDI
    m.w32((s.cx), s.di);
  }
  L00531395: { // 0x531395: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00531399: { // 0x531399: 895614 MOV dword ptr [ESI + 0x14],EDX
    m.w32((s.si+0x00000014u), s.dx);
  }
  L0053139c: { // 0x53139c: 895618 MOV dword ptr [ESI + 0x18],EDX
    m.w32((s.si+0x00000018u), s.dx);
  }
  L0053139f: { // 0x53139f: 897904 MOV dword ptr [ECX + 0x4],EDI
    m.w32((s.cx+0x00000004u), s.di);
  }
  L005313a2: { // 0x5313a2: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L005313a6: { // 0x5313a6: 88461c MOV byte ptr [ESI + 0x1c],AL
    m.w8((s.si+0x0000001cu), (s.ax & 0xffu));
  }
  L005313a9: { // 0x5313a9: 88461d MOV byte ptr [ESI + 0x1d],AL
    m.w8((s.si+0x0000001du), (s.ax & 0xffu));
  }
  L005313ac: { // 0x5313ac: 897908 MOV dword ptr [ECX + 0x8],EDI
    m.w32((s.cx+0x00000008u), s.di);
  }
  L005313af: { // 0x5313af: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L005313b3: { // 0x5313b3: 8d4e2c LEA ECX,[ESI + 0x2c]
    s.cx = (s.si+0x0000002cu);
  }
  L005313b6: { // 0x5313b6: 897e2c MOV dword ptr [ESI + 0x2c],EDI
    m.w32((s.si+0x0000002cu), s.di);
  }
  L005313b9: { // 0x5313b9: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L005313bd: { // 0x5313bd: 897904 MOV dword ptr [ECX + 0x4],EDI
    m.w32((s.cx+0x00000004u), s.di);
  }
  L005313c0: { // 0x5313c0: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L005313c4: { // 0x5313c4: 897908 MOV dword ptr [ECX + 0x8],EDI
    m.w32((s.cx+0x00000008u), s.di);
  }
  L005313c7: { // 0x5313c7: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L005313cb: { // 0x5313cb: 894e38 MOV dword ptr [ESI + 0x38],ECX
    m.w32((s.si+0x00000038u), s.cx);
  }
  L005313ce: { // 0x5313ce: 8a4c2428 MOV CL,byte ptr [ESP + 0x28]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000028u)));
  }
  L005313d2: { // 0x5313d2: 884e3c MOV byte ptr [ESI + 0x3c],CL
    m.w8((s.si+0x0000003cu), (s.cx & 0xffu));
  }
  L005313d5: { // 0x5313d5: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L005313d9: { // 0x5313d9: 88463d MOV byte ptr [ESI + 0x3d],AL
    m.w8((s.si+0x0000003du), (s.ax & 0xffu));
  }
  L005313dc: { // 0x5313dc: 88463e MOV byte ptr [ESI + 0x3e],AL
    m.w8((s.si+0x0000003eu), (s.ax & 0xffu));
  }
  L005313df: { // 0x5313df: 88463f MOV byte ptr [ESI + 0x3f],AL
    m.w8((s.si+0x0000003fu), (s.ax & 0xffu));
  }
  L005313e2: { // 0x5313e2: 884640 MOV byte ptr [ESI + 0x40],AL
    m.w8((s.si+0x00000040u), (s.ax & 0xffu));
  }
  L005313e5: { // 0x5313e5: 884641 MOV byte ptr [ESI + 0x41],AL
    m.w8((s.si+0x00000041u), (s.ax & 0xffu));
  }
  L005313e8: { // 0x5313e8: 884642 MOV byte ptr [ESI + 0x42],AL
    m.w8((s.si+0x00000042u), (s.ax & 0xffu));
  }
  L005313eb: { // 0x5313eb: 884643 MOV byte ptr [ESI + 0x43],AL
    m.w8((s.si+0x00000043u), (s.ax & 0xffu));
  }
  L005313ee: { // 0x5313ee: 884644 MOV byte ptr [ESI + 0x44],AL
    m.w8((s.si+0x00000044u), (s.ax & 0xffu));
  }
  L005313f1: { // 0x5313f1: 884645 MOV byte ptr [ESI + 0x45],AL
    m.w8((s.si+0x00000045u), (s.ax & 0xffu));
  }
  L005313f4: { // 0x5313f4: 894e48 MOV dword ptr [ESI + 0x48],ECX
    m.w32((s.si+0x00000048u), s.cx);
  }
  L005313f7: { // 0x5313f7: 8a4c243c MOV CL,byte ptr [ESP + 0x3c]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000003cu)));
  }
  L005313fb: { // 0x5313fb: 88464d MOV byte ptr [ESI + 0x4d],AL
    m.w8((s.si+0x0000004du), (s.ax & 0xffu));
  }
  L005313fe: { // 0x5313fe: 884e4c MOV byte ptr [ESI + 0x4c],CL
    m.w8((s.si+0x0000004cu), (s.cx & 0xffu));
  }
  L00531401: { // 0x531401: 8a4c2440 MOV CL,byte ptr [ESP + 0x40]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000040u)));
  }
  L00531405: { // 0x531405: 884e4e MOV byte ptr [ESI + 0x4e],CL
    m.w8((s.si+0x0000004eu), (s.cx & 0xffu));
  }
  L00531408: { // 0x531408: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L0053140c: { // 0x53140c: 894e50 MOV dword ptr [ESI + 0x50],ECX
    m.w32((s.si+0x00000050u), s.cx);
  }
  L0053140f: { // 0x53140f: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L00531413: { // 0x531413: 894e54 MOV dword ptr [ESI + 0x54],ECX
    m.w32((s.si+0x00000054u), s.cx);
  }
  L00531416: { // 0x531416: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00531418: { // 0x531418: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L0053141e: { // 0x53141e: 895610 MOV dword ptr [ESI + 0x10],EDX
    m.w32((s.si+0x00000010u), s.dx);
  }
  L00531421: { // 0x531421: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L00531424: { // 0x531424: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00531428: { // 0x531428: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L0053142b: { // 0x53142b: 8a4c242e MOV CL,byte ptr [ESP + 0x2e]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000002eu)));
  }
  L0053142f: { // 0x53142f: 89560c MOV dword ptr [ESI + 0xc],EDX
    m.w32((s.si+0x0000000cu), s.dx);
  }
  L00531432: { // 0x531432: 668b54242c MOV DX,word ptr [ESP + 0x2c]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x0000002cu)));
  }
  L00531437: { // 0x531437: 6689563d MOV word ptr [ESI + 0x3d],DX
    m.w16((s.si+0x0000003du), (s.dx & 0xffffu));
  }
  L0053143b: { // 0x53143b: 668b542430 MOV DX,word ptr [ESP + 0x30]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000030u)));
  }
  L00531440: { // 0x531440: 884e3f MOV byte ptr [ESI + 0x3f],CL
    m.w8((s.si+0x0000003fu), (s.cx & 0xffu));
  }
  L00531443: { // 0x531443: 8a4c2432 MOV CL,byte ptr [ESP + 0x32]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000032u)));
  }
  L00531447: { // 0x531447: 66895640 MOV word ptr [ESI + 0x40],DX
    m.w16((s.si+0x00000040u), (s.dx & 0xffffu));
  }
  L0053144b: { // 0x53144b: 668b542434 MOV DX,word ptr [ESP + 0x34]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000034u)));
  }
  L00531450: { // 0x531450: 884e42 MOV byte ptr [ESI + 0x42],CL
    m.w8((s.si+0x00000042u), (s.cx & 0xffu));
  }
  L00531453: { // 0x531453: 8a4c2436 MOV CL,byte ptr [ESP + 0x36]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000036u)));
  }
  L00531457: { // 0x531457: 66895643 MOV word ptr [ESI + 0x43],DX
    m.w16((s.si+0x00000043u), (s.dx & 0xffffu));
  }
  L0053145b: { // 0x53145b: 884e45 MOV byte ptr [ESI + 0x45],CL
    m.w8((s.si+0x00000045u), (s.cx & 0xffu));
  }
  L0053145e: { // 0x53145e: 8b0dd062a500 MOV ECX,dword ptr [0x00a562d0]
    s.cx = m.r32((0x00a562d0u));
  }
  L00531464: { // 0x531464: 8b15d862a500 MOV EDX,dword ptr [0x00a562d8]
    s.dx = m.r32((0x00a562d8u));
  }
  L0053146a: { // 0x53146a: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0053146c: { // 0x53146c: 7c2c JL 0x0053149a
    if(integer::condition("JL",flags)) goto L0053149a;
  }
  L0053146e: { // 0x53146e: 3805d562a500 CMP byte ptr [0x00a562d5],AL
    (void)integer::sub(m.r8((0x00a562d5u)),(s.ax & 0xffu),8,flags);
  }
  L00531474: { // 0x531474: 7504 JNZ 0x0053147a
    if(integer::condition("JNZ",flags)) goto L0053147a;
  }
  L00531476: { // 0x531476: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00531478: { // 0x531478: 7538 JNZ 0x005314b2
    if(integer::condition("JNZ",flags)) goto L005314b2;
  }
  L0053147a: { // 0x53147a: 8b15dc62a500 MOV EDX,dword ptr [0x00a562dc]
    s.dx = m.r32((0x00a562dcu));
  }
  L00531480: { // 0x531480: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00531482: { // 0x531482: 7e2e JLE 0x005314b2
    if(integer::condition("JLE",flags)) goto L005314b2;
  }
  L00531484: { // 0x531484: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00531486: { // 0x531486: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00531487: { // 0x531487: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00531488: { // 0x531488: 8b15c862a500 MOV EDX,dword ptr [0x00a562c8]
    s.dx = m.r32((0x00a562c8u));
  }
  L0053148e: { // 0x53148e: b9c862a500 MOV ECX,0xa562c8
    s.cx = 0x00a562c8u;
  }
  L00531493: { // 0x531493: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5444758u); flags=s.arithmetic_flags;
  }
  L00531496: { // 0x531496: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00531498: { // 0x531498: 7418 JZ 0x005314b2
    if(integer::condition("JZ",flags)) goto L005314b2;
  }
  L0053149a: { // 0x53149a: 8b0dd862a500 MOV ECX,dword ptr [0x00a562d8]
    s.cx = m.r32((0x00a562d8u));
  }
  L005314a0: { // 0x5314a0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005314a2: { // 0x5314a2: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005314a3: { // 0x5314a3: 890dd862a500 MOV dword ptr [0x00a562d8],ECX
    m.w32((0x00a562d8u), s.cx);
  }
  L005314a9: { // 0x5314a9: 8b0dcc62a500 MOV ECX,dword ptr [0x00a562cc]
    s.cx = m.r32((0x00a562ccu));
  }
  L005314af: { // 0x5314af: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L005314b2: { // 0x5314b2: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L005314b4: { // 0x5314b4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005314b5: { // 0x5314b5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005314b6: { // 0x5314b6: c24000 RET 0x40
    s.arithmetic_flags=flags; finish(m,s,f,64u); return;
  }
}

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7040640u:f_002b6e80(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 5266848u:f_00105da0(m,s,child,{});break;
case 7133872u:f_002cdab0(m,s,child,{});break;
case 7372768u:f_00307fe0(m,s,child,{});break;
case 7162672u:f_002d4b30(m,s,child,{});break;
case 5036528u:f_000cd9f0(m,s,child,{});break;
case 4950096u:f_000b8850(m,s,child,{});break;
case 4305520u:f_0001b270(m,s,child,{});break;
case 6083792u:f_001cd4d0(m,s,child,{});break;
case 5820000u:f_0018ce60(m,s,child,{});break;
case 5820048u:f_0018ce90(m,s,child,{});break;
case 5822368u:f_0018d7a0(m,s,child,{});break;
case 5824896u:f_0018e180(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 4956480u:f_000ba140(m,s,child,{});break;
case 4956400u:f_000ba0f0(m,s,child,{});break;
case 5444464u:f_00131370(m,s,child,{});break;
case 0x76d957u:{const auto request=m.r32(child.entry_sp+4);if(request!=88)throw std::domain_error("230 exact allocation");s.ax=s.heap->allocate(request);s.allocation.reset(new leaf::Memory(reinterpret_cast<unsigned char*>(std::uintptr_t(s.ax)),s.ax,88));m.add(*s.allocation);finish(m,s,child,0);break;}
default:throw std::domain_error("recovery230 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00446580(Memory& original,const Inputs& i,Heap& heap){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.heap=&heap;s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00446580: { // 0x446580: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00446583: { // 0x446583: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00446584: { // 0x446584: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00446585: { // 0x446585: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00446586: { // 0x446586: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00446588: { // 0x446588: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0044658a: { // 0x44658a: 6a58 PUSH 0x58
    f.push(m,0x00000058u);
  }
  L0044658c: { // 0x44658c: 885c2410 MOV byte ptr [ESP + 0x10],BL
    m.w8((f.sp+0x00000010u), (s.bx & 0xffu));
  }
  L00446590: { // 0x446590: 885c2411 MOV byte ptr [ESP + 0x11],BL
    m.w8((f.sp+0x00000011u), (s.bx & 0xffu));
  }
  L00446594: { // 0x446594: e8be733200 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4482457u); flags=s.arithmetic_flags;
  }
  L00446599: { // 0x446599: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0044659b: { // 0x44659b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0044659e: { // 0x44659e: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L004465a0: { // 0x4465a0: 0f849e000000 JZ 0x00446644
    if(integer::condition("JZ",flags)) goto L00446644;
  }
  L004465a6: { // 0x4465a6: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004465ab: { // 0x4465ab: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004465ac: { // 0x4465ac: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  L004465b1: { // 0x4465b1: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004465b3: { // 0x4465b3: 8b8800040000 MOV ECX,dword ptr [EAX + 0x400]
    s.cx = m.r32((s.ax+0x00000400u));
  }
  L004465b9: { // 0x4465b9: 668b442418 MOV AX,word ptr [ESP + 0x18]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000018u)));
  }
  L004465be: { // 0x4465be: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004465bf: { // 0x4465bf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004465c0: { // 0x4465c0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004465c1: { // 0x4465c1: 8bd4 MOV EDX,ESP
    s.dx = f.sp;
  }
  L004465c3: { // 0x4465c3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004465c4: { // 0x4465c4: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  L004465c6: { // 0x4465c6: 668902 MOV word ptr [EDX],AX
    m.w16((s.dx), (s.ax & 0xffffu));
  }
  L004465c9: { // 0x4465c9: 885a02 MOV byte ptr [EDX + 0x2],BL
    m.w8((s.dx+0x00000002u), (s.bx & 0xffu));
  }
  L004465cc: { // 0x4465cc: 8b96b4010000 MOV EDX,dword ptr [ESI + 0x1b4]
    s.dx = m.r32((s.si+0x000001b4u));
  }
  L004465d2: { // 0x4465d2: 668901 MOV word ptr [ECX],AX
    m.w16((s.cx), (s.ax & 0xffffu));
  }
  L004465d5: { // 0x4465d5: 81c2ec550000 ADD EDX,0x55ec
    s.dx = integer::add(s.dx,0x000055ecu,32,flags);
  }
  L004465db: { // 0x4465db: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004465dc: { // 0x4465dc: 885902 MOV byte ptr [ECX + 0x2],BL
    m.w8((s.cx+0x00000002u), (s.bx & 0xffu));
  }
  L004465df: { // 0x4465df: 668b0a MOV CX,word ptr [EDX]
    s.cx = with_ax(s.cx, m.r16((s.dx)));
  }
  L004465e2: { // 0x4465e2: 8bc4 MOV EAX,ESP
    s.ax = f.sp;
  }
  L004465e4: { // 0x4465e4: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004465e6: { // 0x4465e6: 8a5202 MOV DL,byte ptr [EDX + 0x2]
    s.dx = with_al(s.dx, m.r8((s.dx+0x00000002u)));
  }
  L004465e9: { // 0x4465e9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004465ea: { // 0x4465ea: 668908 MOV word ptr [EAX],CX
    m.w16((s.ax), (s.cx & 0xffffu));
  }
  L004465ed: { // 0x4465ed: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L004465f1: { // 0x4465f1: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004465f4: { // 0x4465f4: 885002 MOV byte ptr [EAX + 0x2],DL
    m.w8((s.ax+0x00000002u), (s.dx & 0xffu));
  }
  L004465f7: { // 0x4465f7: 8b542458 MOV EDX,dword ptr [ESP + 0x58]
    s.dx = m.r32((f.sp+0x00000058u));
  }
  L004465fb: { // 0x4465fb: 8bc4 MOV EAX,ESP
    s.ax = f.sp;
  }
  L004465fd: { // 0x4465fd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004465fe: { // 0x4465fe: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00446600: { // 0x446600: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00446604: { // 0x446604: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L00446607: { // 0x446607: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00446609: { // 0x446609: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0044660c: { // 0x44660c: 8d442448 LEA EAX,[ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L00446610: { // 0x446610: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00446611: { // 0x446611: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00446613: { // 0x446613: ff92ac000000 CALL dword ptr [EDX + 0xac]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000acu)),4482585u); flags=s.arithmetic_flags;
  }
  L00446619: { // 0x446619: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0044661b: { // 0x44661b: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0044661e: { // 0x44661e: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  L00446620: { // 0x446620: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00446622: { // 0x446622: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00446625: { // 0x446625: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L00446628: { // 0x446628: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0044662b: { // 0x44662b: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L0044662e: { // 0x44662e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00446630: { // 0x446630: e83bad0e00 CALL 0x00531370
    s.arithmetic_flags=flags; invoke(m,s,f,0x00531370u,4482613u); flags=s.arithmetic_flags;
  }
  L00446635: { // 0x446635: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00446637: { // 0x446637: 740b JZ 0x00446644
    if(integer::condition("JZ",flags)) goto L00446644;
  }
  L00446639: { // 0x446639: c6401c01 MOV byte ptr [EAX + 0x1c],0x1
    m.w8((s.ax+0x0000001cu), 0x00000001u);
  }
  L0044663d: { // 0x44663d: c7401803000000 MOV dword ptr [EAX + 0x18],0x3
    m.w32((s.ax+0x00000018u), 0x00000003u);
  }
  L00446644: { // 0x446644: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L0044664a: { // 0x44664a: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L0044664f: { // 0x44664f: 8d9644020000 LEA EDX,[ESI + 0x244]
    s.dx = (s.si+0x00000244u);
  }
  L00446655: { // 0x446655: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00446656: { // 0x446656: 8b89fc030000 MOV ECX,dword ptr [ECX + 0x3fc]
    s.cx = m.r32((s.cx+0x000003fcu));
  }
  L0044665c: { // 0x44665c: 899e34050000 MOV dword ptr [ESI + 0x534],EBX
    m.w32((s.si+0x00000534u), s.bx);
  }
  L00446662: { // 0x446662: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L00446664: { // 0x446664: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00446668: { // 0x446668: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00446669: { // 0x446669: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044666a: { // 0x44666a: 894204 MOV dword ptr [EDX + 0x4],EAX
    m.w32((s.dx+0x00000004u), s.ax);
  }
  L0044666d: { // 0x44666d: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00446670: { // 0x446670: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00446673: { // 0x446673: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
