#include "recovered/floating_bridges_b45_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::floating_bridges_b45 {
namespace {
void f_000c3540(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4c3540: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4c3541: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4c3543: 8b8694040000 MOV EAX,dword ptr [ESI + 0x494]
    s.ax = m.r32((s.si+0x00000494u));
  }
  { // 0x4c3549: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c354b: 7542 JNZ 0x004c358f
    if(integer::condition("JNZ",flags)) goto L004c358f;
  }
  { // 0x4c354d: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x4c3553: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4c3555: 750a JNZ 0x004c3561
    if(integer::condition("JNZ",flags)) goto L004c3561;
  }
  { // 0x4c3557: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  { // 0x4c355c: e80fdd2b00 CALL 0x00781270
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00781270u;
    invoke_external(m,s,f,op,0u,target,0x004c3561u);
    flags=s.arithmetic_flags;
  }
  L004c3561: { // 0x4c3561: 8b8664050000 MOV EAX,dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  { // 0x4c3567: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4c3568: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x4c356a: ff5110 CALL dword ptr [ECX + 0x10]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.cx+0x00000010u));
    invoke_external(m,s,f,op,1u,target,0x004c356du);
    flags=s.arithmetic_flags;
  }
  { // 0x4c356d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4c356f: 751e JNZ 0x004c358f
    if(integer::condition("JNZ",flags)) goto L004c358f;
  }
  { // 0x4c3571: 83bea0000000ff CMP dword ptr [ESI + 0xa0],-0x1
    (void)integer::sub(m.r32((s.si+0x000000a0u)),0xffffffffu,32,flags);
  }
  { // 0x4c3578: 7515 JNZ 0x004c358f
    if(integer::condition("JNZ",flags)) goto L004c358f;
  }
  { // 0x4c357a: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4c357c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x4c357e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4c3580: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c3582: ff9214040000 CALL dword ptr [EDX + 0x414]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.dx+0x00000414u));
    invoke_external(m,s,f,op,2u,target,0x004c3588u);
    flags=s.arithmetic_flags;
  }
  { // 0x4c3588: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x4c358d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c358e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004c358f: { // 0x4c358f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4c3591: e83ae90c00 CALL 0x00591ed0
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x00191ed0u,0x004c3596u);
    flags=s.arithmetic_flags;
  }
  { // 0x4c3596: dd4010 FLD double ptr [EAX + 0x10]
    const auto address=(s.ax+0x00000010u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4c3599: dc0d08667800 FMUL double ptr [0x00786608]
    const auto address=(0x00786608u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x4c359f: e8ac742a00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x004c35a4u);
    flags=s.arithmetic_flags;
  }
  { // 0x4c35a4: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4c35a6: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x4c35ab: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x4c35ad: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x4c35af: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  { // 0x4c35b5: e886c81600 CALL 0x0062fe40
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0062fe40u;
    invoke_external(m,s,f,op,5u,target,0x004c35bau);
    flags=s.arithmetic_flags;
  }
  { // 0x4c35ba: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  { // 0x4c35bc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4c35bd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0010d990(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x50d990: dd44240c FLD double ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x50d994: 81ec00020000 SUB ESP,0x200
    f.sp = integer::sub(f.sp,0x00000200u,32,flags);
  }
  { // 0x50d99a: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x50d99e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x50d99f: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x50d9a1: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x50d9a4: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x50d9a7: 6848657c00 PUSH 0x7c6548
    f.push(m,0x007c6548u);
  }
  { // 0x50d9ac: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50d9ad: e882002600 CALL 0x0076da34
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0076da34u;
    invoke_external(m,s,f,op,0u,target,0x0050d9b2u);
    flags=s.arithmetic_flags;
  }
  { // 0x50d9b2: 8b94241c020000 MOV EDX,dword ptr [ESP + 0x21c]
    s.dx = m.r32((f.sp+0x0000021cu));
  }
  { // 0x50d9b9: 8b842418020000 MOV EAX,dword ptr [ESP + 0x218]
    s.ax = m.r32((f.sp+0x00000218u));
  }
  { // 0x50d9c0: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x50d9c3: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x50d9c7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x50d9c8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x50d9c9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x50d9ca: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x50d9cc: e86f000000 CALL 0x0050da40
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0050da40u;
    invoke_external(m,s,f,op,1u,target,0x0050d9d1u);
    flags=s.arithmetic_flags;
  }
  { // 0x50d9d1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x50d9d2: 81c400020000 ADD ESP,0x200
    f.sp = integer::add(f.sp,0x00000200u,32,flags);
  }
  { // 0x50d9d8: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}
void f_001d10a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5d10a0: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x5d10a4: dc1d08577800 FCOMP double ptr [0x00785708]
    const auto address=(0x00785708u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x5d10aa: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5d10ab: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5d10ad: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x5d10af: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x5d10b2: 7406 JZ 0x005d10ba
    if(integer::condition("JZ",flags)) goto L005d10ba;
  }
  { // 0x5d10b4: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x5d10b8: eb06 JMP 0x005d10c0
    goto L005d10c0;
  }
  L005d10ba: { // 0x5d10ba: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  L005d10c0: { // 0x5d10c0: d9562c FST float ptr [ESI + 0x2c]
    const auto address=(s.si+0x0000002cu);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  { // 0x5d10c3: d80d6c277900 FMUL float ptr [0x0079276c]
    const auto address=(0x0079276cu);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x5d10c9: e882991900 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x005d10ceu);
    flags=s.arithmetic_flags;
  }
  { // 0x5d10ce: 8b0d98978100 MOV ECX,dword ptr [0x00819798]
    s.cx = m.r32((0x00819798u));
  }
  { // 0x5d10d4: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x5d10d6: e8a55fe3ff CALL 0x00407080
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00407080u;
    invoke_external(m,s,f,op,1u,target,0x005d10dbu);
    flags=s.arithmetic_flags;
  }
  { // 0x5d10db: 8a44240c MOV AL,byte ptr [ESP + 0xc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000cu)));
  }
  { // 0x5d10df: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5d10e1: 741c JZ 0x005d10ff
    if(integer::condition("JZ",flags)) goto L005d10ff;
  }
  { // 0x5d10e3: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  { // 0x5d10e8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5d10ea: ba00200000 MOV EDX,0x2000
    s.dx = 0x00002000u;
  }
  { // 0x5d10ef: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  { // 0x5d10f4: 8b8830060000 MOV ECX,dword ptr [EAX + 0x630]
    s.cx = m.r32((s.ax+0x00000630u));
  }
  { // 0x5d10fa: e871781300 CALL 0x00708970
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00708970u;
    invoke_external(m,s,f,op,2u,target,0x005d10ffu);
    flags=s.arithmetic_flags;
  }
  L005d10ff: { // 0x5d10ff: d9462c FLD float ptr [ESI + 0x2c]
    const auto address=(s.si+0x0000002cu);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x5d1102: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x5d1105: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x5d1108: 6818287d00 PUSH 0x7d2818
    f.push(m,0x007d2818u);
  }
  { // 0x5d110d: e8de57e3ff CALL 0x004068f0
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000068f0u,0x005d1112u);
    flags=s.arithmetic_flags;
  }
  { // 0x5d1112: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5d1115: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5d1116: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0030d9b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70d9b0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x70d9b4: 83ec40 SUB ESP,0x40
    f.sp = integer::sub(f.sp,0x00000040u,32,flags);
  }
  { // 0x70d9b7: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x70d9b9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x70d9ba: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x70d9bb: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x70d9bc: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x70d9be: 7444 JZ 0x0070da04
    if(integer::condition("JZ",flags)) goto L0070da04;
  }
  { // 0x70d9c0: dd442454 FLD double ptr [ESP + 0x54]
    const auto address=(f.sp+0x00000054u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x70d9c4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x70d9c5: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x70d9c9: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x70d9cc: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x70d9cf: 0598e0ad00 ADD EAX,0xade098
    s.ax = integer::add(s.ax,0x00ade098u,32,flags);
  }
  { // 0x70d9d4: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x70d9d7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x70d9d8: 81c298e0ad00 ADD EDX,0xade098
    s.dx = integer::add(s.dx,0x00ade098u,32,flags);
  }
  { // 0x70d9de: e86dccf0ff CALL 0x0061a650
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0061a650u;
    invoke_external(m,s,f,op,0u,target,0x0070d9e3u);
    flags=s.arithmetic_flags;
  }
  { // 0x70d9e3: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x70d9e5: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  { // 0x70d9e9: e852d0f0ff CALL 0x0061aa40
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0061aa40u;
    invoke_external(m,s,f,op,1u,target,0x0070d9eeu);
    flags=s.arithmetic_flags;
  }
  { // 0x70d9ee: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  { // 0x70d9f3: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x70d9f5: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  { // 0x70d9f7: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x70d9f9: f3a5 MOVSD.REP ES:EDI,ESI
    strings_b37::string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x70d9fb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x70d9fc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70d9fd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x70d9fe: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  { // 0x70da01: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0070da04: { // 0x70da04: 8d3440 LEA ESI,[EAX + EAX*0x2]
    s.si = (s.ax+(s.ax * 0x00000002u));
  }
  { // 0x70da07: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  { // 0x70da0c: c1e604 SHL ESI,0x4
    s.si = integer::shift(s.si,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x70da0f: 81c68800ae00 ADD ESI,0xae0088
    s.si = integer::add(s.si,0x00ae0088u,32,flags);
  }
  { // 0x70da15: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  { // 0x70da17: f3a5 MOVSD.REP ES:EDI,ESI
    strings_b37::string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x70da19: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x70da1a: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x70da1c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70da1d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x70da1e: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  { // 0x70da21: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0036da86(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76da86: e813000000 CALL 0x0076da9e
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036da9eu,0x0076da8bu);
    flags=s.arithmetic_flags;
  }
  { // 0x76da8b: e82f4c0000 CALL 0x007726bf
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x007726bfu;
    invoke_external(m,s,f,op,1u,target,0x0076da90u);
    flags=s.arithmetic_flags;
  }
  { // 0x76da90: a33004b100 MOV [0x00b10430],EAX
    m.w32((0x00b10430u), s.ax);
  }
  { // 0x76da95: e8d54b0000 CALL 0x0077266f
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0077266fu;
    invoke_external(m,s,f,op,2u,target,0x0076da9au);
    flags=s.arithmetic_flags;
  }
  { // 0x76da9a: dbe2 FNCLEX
    s.fp.clear_exceptions();
  }
  { // 0x76da9c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0036daf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76daf0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x76daf3: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x76daf5: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x76daf8: dd542408 FST double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  { // 0x76dafc: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x76db00: e80d000000 CALL 0x0076db12
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0076db12u;
    invoke_external(m,s,f,op,0u,target,0x0076db05u);
    flags=s.arithmetic_flags;
  }
  { // 0x76db05: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x76db08: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_003727e6(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7727e6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7727e7: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7727e9: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  { // 0x7727ec: 8d45d8 LEA EAX,[EBP + -0x28]
    s.ax = (s.bp-0x00000028u);
  }
  { // 0x7727ef: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7727f0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7727f1: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  { // 0x7727f4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7727f5: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x7727f8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7727f9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7727fa: dd00 FLD double ptr [EAX]
    const auto address=(s.ax);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x7727fc: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x7727ff: e8fc950000 CALL 0x0077be00
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0077be00u;
    invoke_external(m,s,f,op,0u,target,0x00772804u);
    flags=s.arithmetic_flags;
  }
  { // 0x772804: 8b7510 MOV ESI,dword ptr [EBP + 0x10]
    s.si = m.r32((s.bp+0x00000010u));
  }
  { // 0x772807: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  { // 0x77280a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77280b: 8b550c MOV EDX,dword ptr [EBP + 0xc]
    s.dx = m.r32((s.bp+0x0000000cu));
  }
  { // 0x77280e: 8d4601 LEA EAX,[ESI + 0x1]
    s.ax = (s.si+0x00000001u);
  }
  { // 0x772811: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x772812: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x772814: 837df02d CMP dword ptr [EBP + -0x10],0x2d
    (void)integer::sub(m.r32((s.bp-0x00000010u)),0x0000002du,32,flags);
  }
  { // 0x772818: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x77281b: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x77281d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x77281f: 0f9fc1 SETG CL
    s.cx = with_al(s.cx, (integer::condition("JG",flags)?1u:0u));
  }
  { // 0x772822: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x772824: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  { // 0x772826: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x772827: e85d950000 CALL 0x0077bd89
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0077bd89u;
    invoke_external(m,s,f,op,1u,target,0x0077282cu);
    flags=s.arithmetic_flags;
  }
  { // 0x77282c: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  { // 0x77282f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x772831: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x772832: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x772835: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x772836: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x772839: e809000000 CALL 0x00772847
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00772847u;
    invoke_external(m,s,f,op,2u,target,0x0077283eu);
    flags=s.arithmetic_flags;
  }
  { // 0x77283e: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x772841: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  { // 0x772844: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x772845: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x772846: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00372909(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x772909: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77290a: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77290c: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  { // 0x77290f: 8d45d8 LEA EAX,[EBP + -0x28]
    s.ax = (s.bp-0x00000028u);
  }
  { // 0x772912: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x772913: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x772914: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  { // 0x772917: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x772918: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x77291b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x77291c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x77291d: dd00 FLD double ptr [EAX]
    const auto address=(s.ax);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x77291f: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x772922: e8d9940000 CALL 0x0077be00
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0077be00u;
    invoke_external(m,s,f,op,0u,target,0x00772927u);
    flags=s.arithmetic_flags;
  }
  { // 0x772927: 8b7510 MOV ESI,dword ptr [EBP + 0x10]
    s.si = m.r32((s.bp+0x00000010u));
  }
  { // 0x77292a: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  { // 0x77292d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77292e: 8b45f4 MOV EAX,dword ptr [EBP + -0xc]
    s.ax = m.r32((s.bp-0x0000000cu));
  }
  { // 0x772931: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  { // 0x772933: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x772934: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x772936: 837df02d CMP dword ptr [EBP + -0x10],0x2d
    (void)integer::sub(m.r32((s.bp-0x00000010u)),0x0000002du,32,flags);
  }
  { // 0x77293a: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x77293d: 03450c ADD EAX,dword ptr [EBP + 0xc]
    s.ax = integer::add(s.ax,m.r32((s.bp+0x0000000cu)),32,flags);
  }
  { // 0x772940: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x772941: e843940000 CALL 0x0077bd89
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0077bd89u;
    invoke_external(m,s,f,op,1u,target,0x00772946u);
    flags=s.arithmetic_flags;
  }
  { // 0x772946: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  { // 0x772949: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x77294b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77294c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77294d: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x772950: e809000000 CALL 0x0077295e
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0077295eu;
    invoke_external(m,s,f,op,2u,target,0x00772955u);
    flags=s.arithmetic_flags;
  }
  { // 0x772955: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x772958: 83c42c ADD ESP,0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  { // 0x77295b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77295c: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77295d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00372f07(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x772f07: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x772f08: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x772f0a: 83c4e0 ADD ESP,-0x20
    f.sp = integer::add(f.sp,0xffffffe0u,32,flags);
  }
  { // 0x772f0d: 8945e0 MOV dword ptr [EBP + -0x20],EAX
    m.w32((s.bp-0x00000020u), s.ax);
  }
  { // 0x772f10: dd5df8 FSTP double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x772f13: 894de4 MOV dword ptr [EBP + -0x1c],ECX
    m.w32((s.bp-0x0000001cu), s.cx);
  }
  { // 0x772f16: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  { // 0x772f19: 8b4d14 MOV ECX,dword ptr [EBP + 0x14]
    s.cx = m.r32((s.bp+0x00000014u));
  }
  { // 0x772f1c: 8945e8 MOV dword ptr [EBP + -0x18],EAX
    m.w32((s.bp-0x00000018u), s.ax);
  }
  { // 0x772f1f: 894dec MOV dword ptr [EBP + -0x14],ECX
    m.w32((s.bp-0x00000014u), s.cx);
  }
  { // 0x772f22: 8d4508 LEA EAX,[EBP + 0x8]
    s.ax = (s.bp+0x00000008u);
  }
  { // 0x772f25: 8d4de0 LEA ECX,[EBP + -0x20]
    s.cx = (s.bp-0x00000020u);
  }
  { // 0x772f28: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x772f29: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x772f2a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x772f2b: e87b9d0000 CALL 0x0077ccab
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0077ccabu;
    invoke_external(m,s,f,op,0u,target,0x00772f30u);
    flags=s.arithmetic_flags;
  }
  { // 0x772f30: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x772f33: dd45f8 FLD double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x772f36: 66817d087f02 CMP word ptr [EBP + 0x8],0x27f
    (void)integer::sub(m.r16((s.bp+0x00000008u)),0x0000027fu,16,flags);
  }
  { // 0x772f3c: 7403 JZ 0x00772f41
    if(integer::condition("JZ",flags)) goto L00772f41;
  }
  { // 0x772f3e: d96d08 FLDCW word ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    const auto operand=m.r16(address);
    s.fp.load_control(operand);
  }
  L00772f41: { // 0x772f41: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x772f42: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0037320c(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77320c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77320d: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77320f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x773210: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x773211: dd4508 FLD double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x773214: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x773215: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x773216: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x773219: e8779f0000 CALL 0x0077d195
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0077d195u;
    invoke_external(m,s,f,op,0u,target,0x0077321eu);
    flags=s.arithmetic_flags;
  }
  { // 0x77321e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77321f: a890 TEST AL,0x90
    (void)integer::logical(((s.ax & 0xffu))&(0x00000090u),8,flags);
  }
  { // 0x773221: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x773222: 7549 JNZ 0x0077326d
    if(integer::condition("JNZ",flags)) goto L0077326d;
  }
  { // 0x773224: dd4508 FLD double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x773227: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x773228: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x773229: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x77322c: e88d5b0000 CALL 0x00778dbe
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x00378dbeu,0x00773231u);
    flags=s.arithmetic_flags;
  }
  { // 0x773231: dd5df8 FSTP double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x773234: dd45f8 FLD double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x773237: dc5d08 FCOMP double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x77323a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77323b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77323c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x77323e: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  { // 0x77323f: 752c JNZ 0x0077326d
    if(integer::condition("JNZ",flags)) goto L0077326d;
  }
  { // 0x773241: dd4508 FLD double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x773244: dc35f8567800 FDIV double ptr [0x007856f8]
    const auto address=(0x007856f8u);
    const auto operand=read64(m,address);
    s.fp.divide64(operand);
  }
  { // 0x77324a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x77324b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x77324c: dd5d08 FSTP double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x77324f: dd4508 FLD double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x773252: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x773255: e8645b0000 CALL 0x00778dbe
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x00378dbeu,0x0077325au);
    flags=s.arithmetic_flags;
  }
  { // 0x77325a: dc5d08 FCOMP double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x77325d: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77325e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77325f: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x773261: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  { // 0x773262: 7504 JNZ 0x00773268
    if(integer::condition("JNZ",flags)) goto L00773268;
  }
  { // 0x773264: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  { // 0x773266: eb02 JMP 0x0077326a
    goto L0077326a;
  }
  L00773268: { // 0x773268: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0077326a: { // 0x77326a: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  { // 0x77326b: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77326c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0077326d: { // 0x77326d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x77326f: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x773270: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_003750de(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7750de: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7750df: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7750e1: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  { // 0x7750e4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x7750e5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7750e6: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x7750e8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7750e9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7750ea: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7750eb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7750ec: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7750ed: ff750c PUSH dword ptr [EBP + 0xc]
    f.push(m,m.r32((s.bp+0x0000000cu)));
  }
  { // 0x7750f0: 8d45fc LEA EAX,[EBP + -0x4]
    s.ax = (s.bp-0x00000004u);
  }
  { // 0x7750f3: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x7750f5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7750f6: 8d45e8 LEA EAX,[EBP + -0x18]
    s.ax = (s.bp-0x00000018u);
  }
  { // 0x7750f9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7750fa: e8f9850000 CALL 0x0077d6f8
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0077d6f8u;
    invoke_external(m,s,f,op,0u,target,0x007750ffu);
    flags=s.arithmetic_flags;
  }
  { // 0x7750ff: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x775101: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  { // 0x775104: f6c304 TEST BL,0x4
    (void)integer::logical(((s.bx & 0xffu))&(0x00000004u),8,flags);
  }
  { // 0x775107: 740d JZ 0x00775116
    if(integer::condition("JZ",flags)) goto L00775116;
  }
  { // 0x775109: bf00020000 MOV EDI,0x200
    s.di = 0x00000200u;
  }
  { // 0x77510e: 8975f4 MOV dword ptr [EBP + -0xc],ESI
    m.w32((s.bp-0x0000000cu), s.si);
  }
  { // 0x775111: 8975f8 MOV dword ptr [EBP + -0x8],ESI
    m.w32((s.bp-0x00000008u), s.si);
  }
  { // 0x775114: eb2e JMP 0x00775144
    goto L00775144;
  }
  L00775116: { // 0x775116: 8d45f4 LEA EAX,[EBP + -0xc]
    s.ax = (s.bp-0x0000000cu);
  }
  { // 0x775119: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77511a: 8d45e8 LEA EAX,[EBP + -0x18]
    s.ax = (s.bp-0x00000018u);
  }
  { // 0x77511d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77511e: e8386b0000 CALL 0x0077bc5b
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0077bc5bu;
    invoke_external(m,s,f,op,1u,target,0x00775123u);
    flags=s.arithmetic_flags;
  }
  { // 0x775123: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x775124: f6c302 TEST BL,0x2
    (void)integer::logical(((s.bx & 0xffu))&(0x00000002u),8,flags);
  }
  { // 0x775127: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x775128: 7505 JNZ 0x0077512f
    if(integer::condition("JNZ",flags)) goto L0077512f;
  }
  { // 0x77512a: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x77512d: 7505 JNZ 0x00775134
    if(integer::condition("JNZ",flags)) goto L00775134;
  }
  L0077512f: { // 0x77512f: bf80000000 MOV EDI,0x80
    s.di = 0x00000080u;
  }
  L00775134: { // 0x775134: f6c301 TEST BL,0x1
    (void)integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x775137: 7505 JNZ 0x0077513e
    if(integer::condition("JNZ",flags)) goto L0077513e;
  }
  { // 0x775139: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x77513c: 7506 JNZ 0x00775144
    if(integer::condition("JNZ",flags)) goto L00775144;
  }
  L0077513e: { // 0x77513e: 81cf00010000 OR EDI,0x100
    s.di = integer::logical((s.di)|(0x00000100u),32,flags);
  }
  L00775144: { // 0x775144: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x775147: 8b4dfc MOV ECX,dword ptr [EBP + -0x4]
    s.cx = m.r32((s.bp-0x00000004u));
  }
  { // 0x77514a: 2b4d0c SUB ECX,dword ptr [EBP + 0xc]
    s.cx = integer::sub(s.cx,m.r32((s.bp+0x0000000cu)),32,flags);
  }
  { // 0x77514d: dd45f4 FLD double ptr [EBP + -0xc]
    const auto address=(s.bp-0x0000000cu);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x775150: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  { // 0x775152: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x775153: dd5810 FSTP double ptr [EAX + 0x10]
    const auto address=(s.ax+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x775156: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x775157: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  { // 0x77515a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x77515b: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77515c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00378601(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x778601: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x778602: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x778604: 833d8c86810000 CMP dword ptr [0x0081868c],0x0
    (void)integer::sub(m.r32((0x0081868cu)),0x00000000u,32,flags);
  }
  { // 0x77860b: 7529 JNZ 0x00778636
    if(integer::condition("JNZ",flags)) goto L00778636;
  }
  { // 0x77860d: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x778610: dd450c FLD double ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x778613: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778614: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778615: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x778618: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778619: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x77861a: d9ee FLDZ
    s.fp.load_zero();
  }
  { // 0x77861c: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x77861f: dd450c FLD double ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x778622: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778623: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778624: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x778627: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x77862a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77862c: e88b060000 CALL 0x00778cbc
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00778cbcu;
    invoke_external(m,s,f,op,0u,target,0x00778631u);
    flags=s.arithmetic_flags;
  }
  { // 0x778631: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  { // 0x778634: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x778635: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00778636: { // 0x778636: e813ccffff CALL 0x0077524e
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0077524eu;
    invoke_external(m,s,f,op,1u,target,0x0077863bu);
    flags=s.arithmetic_flags;
  }
  { // 0x77863b: 68ffff0000 PUSH 0xffff
    f.push(m,0x0000ffffu);
  }
  { // 0x778640: c70021000000 MOV dword ptr [EAX],0x21
    m.w32((s.ax), 0x00000021u);
  }
  { // 0x778646: ff7514 PUSH dword ptr [EBP + 0x14]
    f.push(m,m.r32((s.bp+0x00000014u)));
  }
  { // 0x778649: e847090000 CALL 0x00778f95
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x00378f95u,0x0077864eu);
    flags=s.arithmetic_flags;
  }
  { // 0x77864e: dd450c FLD double ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x778651: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x778652: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x778653: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x778654: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00378655(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x778655: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x778656: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x778658: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778659: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x77865a: dd450c FLD double ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x77865d: dc4514 FADD double ptr [EBP + 0x14]
    const auto address=(s.bp+0x00000014u);
    const auto operand=read64(m,address);
    s.fp.add64(operand);
  }
  { // 0x778660: 833d8c86810000 CMP dword ptr [0x0081868c],0x0
    (void)integer::sub(m.r32((0x0081868cu)),0x00000000u,32,flags);
  }
  { // 0x778667: dd5df8 FSTP double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x77866a: 752a JNZ 0x00778696
    if(integer::condition("JNZ",flags)) goto L00778696;
  }
  { // 0x77866c: ff751c PUSH dword ptr [EBP + 0x1c]
    f.push(m,m.r32((s.bp+0x0000001cu)));
  }
  { // 0x77866f: dd45f8 FLD double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x778672: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778673: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778674: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x778677: dd4514 FLD double ptr [EBP + 0x14]
    const auto address=(s.bp+0x00000014u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x77867a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x77867b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x77867c: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x77867f: dd450c FLD double ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x778682: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778683: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778684: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x778687: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x77868a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x77868c: e82b060000 CALL 0x00778cbc
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x00778cbcu;
    invoke_external(m,s,f,op,0u,target,0x00778691u);
    flags=s.arithmetic_flags;
  }
  { // 0x778691: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  { // 0x778694: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x778695: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00778696: { // 0x778696: e8b3cbffff CALL 0x0077524e
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0077524eu;
    invoke_external(m,s,f,op,1u,target,0x0077869bu);
    flags=s.arithmetic_flags;
  }
  { // 0x77869b: 68ffff0000 PUSH 0xffff
    f.push(m,0x0000ffffu);
  }
  { // 0x7786a0: c70021000000 MOV dword ptr [EAX],0x21
    m.w32((s.ax), 0x00000021u);
  }
  { // 0x7786a6: ff751c PUSH dword ptr [EBP + 0x1c]
    f.push(m,m.r32((s.bp+0x0000001cu)));
  }
  { // 0x7786a9: e8e7080000 CALL 0x00778f95
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x00378f95u,0x007786aeu);
    flags=s.arithmetic_flags;
  }
  { // 0x7786ae: dd45f8 FLD double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x7786b1: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7786b2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x7786b3: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x7786b4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,13>& entries_a() {
  static const std::array<Entry,13> entries{{
    {0xc3540u,f_000c3540},
    {0x10d990u,f_0010d990},
    {0x1d10a0u,f_001d10a0},
    {0x30d9b0u,f_0030d9b0},
    {0x36da86u,f_0036da86},
    {0x36daf0u,f_0036daf0},
    {0x3727e6u,f_003727e6},
    {0x372909u,f_00372909},
    {0x372f07u,f_00372f07},
    {0x37320cu,f_0037320c},
    {0x3750deu,f_003750de},
    {0x378601u,f_00378601},
    {0x378655u,f_00378655},
  }}; return entries;
}
} // namespace ra2::recovered::floating_bridges_b45

#include "recovered/floating_bridges_b45_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::floating_bridges_b45 {
namespace {
void f_000068f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4068f0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00191ed0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x591ed0: 8b8198000000 MOV EAX,dword ptr [ECX + 0x98]
    s.ax = m.r32((s.cx+0x00000098u));
  }
  { // 0x591ed6: c1e005 SHL EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::left);
  }
  { // 0x591ed9: 050080a200 ADD EAX,0xa28000
    s.ax = integer::add(s.ax,0x00a28000u,32,flags);
  }
  { // 0x591ede: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0036da9e(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76da9e: b8982a7700 MOV EAX,0x772a98
    s.ax = 0x00772a98u;
  }
  { // 0x76daa3: c705a474810042277700 MOV dword ptr [0x008174a4],0x772742
    m.w32((0x008174a4u), 0x00772742u);
  }
  { // 0x76daad: a3a0748100 MOV [0x008174a0],EAX
    m.w32((0x008174a0u), s.ax);
  }
  { // 0x76dab2: c705a8748100a8277700 MOV dword ptr [0x008174a8],0x7727a8
    m.w32((0x008174a8u), 0x007727a8u);
  }
  { // 0x76dabc: c705ac748100e8267700 MOV dword ptr [0x008174ac],0x7726e8
    m.w32((0x008174acu), 0x007726e8u);
  }
  { // 0x76dac6: c705b074810090277700 MOV dword ptr [0x008174b0],0x772790
    m.w32((0x008174b0u), 0x00772790u);
  }
  { // 0x76dad0: a3b4748100 MOV [0x008174b4],EAX
    m.w32((0x008174b4u), s.ax);
  }
  { // 0x76dad5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,3>& entries_dependencies() {
  static const std::array<Entry,3> entries{{
    {0x68f0u,f_000068f0},
    {0x191ed0u,f_00191ed0},
    {0x36da9eu,f_0036da9e},
  }}; return entries;
}
} // namespace ra2::recovered::floating_bridges_b45
