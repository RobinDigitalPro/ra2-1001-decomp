#include "floating_chain_b41_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Original instruction annotations are retained; acceptance requires current native proof.
namespace ra2::recovered::floating_chain_b41 {
namespace {
void f_0007ca70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47ca70: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  { // 0x47ca75: db8050140000 FILD dword ptr [EAX + 0x1450]
    const auto address=(s.ax+0x00001450u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x47ca7b: dd81f0000000 FLD double ptr [ECX + 0xf0]
    const auto address=(s.cx+0x000000f0u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x47ca81: d8d9 FCOMP
    s.fp.compare_pop_st1();
  }
  { // 0x47ca83: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x47ca85: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x47ca88: 7408 JZ 0x0047ca92
    if(integer::condition("JZ",flags)) goto L0047ca92;
  }
  { // 0x47ca8a: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x47ca8c: dd81f0000000 FLD double ptr [ECX + 0xf0]
    const auto address=(s.cx+0x000000f0u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  L0047ca92: { // 0x47ca92: e9b9df2e00 JMP 0x0076aa50
    s.arithmetic_flags=flags; invoke_closed_tail(m,s,f,0x36aa50u); return;
  }
}
void f_000e2480(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e2480: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4e2481: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4e2483: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4e2484: 8dbe3c020000 LEA EDI,[ESI + 0x23c]
    s.di = (s.si+0x0000023cu);
  }
  { // 0x4e248a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4e248c: e81fe01a00 CALL 0x006904b0
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x002904b0u,0x004e2491u);
    flags=s.arithmetic_flags;
  }
  { // 0x4e2491: e8ba852800 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x004e2496u);
    flags=s.arithmetic_flags;
  }
  { // 0x4e2496: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4e2498: 7509 JNZ 0x004e24a3
    if(integer::condition("JNZ",flags)) goto L004e24a3;
  }
  { // 0x4e249a: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4e24a0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4e24a1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e24a2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004e24a3: { // 0x4e24a3: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4e24a5: e806e01a00 CALL 0x006904b0
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x002904b0u,0x004e24aau);
    flags=s.arithmetic_flags;
  }
  { // 0x4e24aa: dab650020000 FIDIV dword ptr [ESI + 0x250]
    const auto address=(s.si+0x00000250u);
    const auto operand=m.r32(address);
    s.fp.divide_integer32(operand);
  }
  { // 0x4e24b0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4e24b1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e24b2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000e4890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e4890: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4e4891: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4e4892: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4e4896: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4e4897: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4e4899: 7e3f JLE 0x004e48da
    if(integer::condition("JLE",flags)) goto L004e48da;
  }
  { // 0x4e489b: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  { // 0x4e489f: 8db954020000 LEA EDI,[ECX + 0x254]
    s.di = (s.cx+0x00000254u);
  }
  L004e48a5: { // 0x4e48a5: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  { // 0x4e48aa: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4e48ac: db8010140000 FILD dword ptr [EAX + 0x1410]
    const auto address=(s.ax+0x00001410u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x4e48b2: d95c2410 FSTP float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x4e48b6: e8f5bb1a00 CALL 0x006904b0
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x002904b0u,0x004e48bbu);
    flags=s.arithmetic_flags;
  }
  { // 0x4e48bb: d85c2410 FCOMP float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto operand=m.r32(address);
    s.fp.compare_pop32(operand);
  }
  { // 0x4e48bf: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x4e48c1: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x4e48c4: 7414 JZ 0x004e48da
    if(integer::condition("JZ",flags)) goto L004e48da;
  }
  { // 0x4e48c6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4e48c7: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  { // 0x4e48cc: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4e48ce: e81dbc1a00 CALL 0x006904f0
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x002904f0u,0x004e48d3u);
    flags=s.arithmetic_flags;
  }
  { // 0x4e48d3: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x4e48d4: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4e48d6: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x4e48d8: 7fcb JG 0x004e48a5
    if(integer::condition("JG",flags)) goto L004e48a5;
  }
  L004e48da: { // 0x4e48da: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4e48db: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e48dc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4e48dd: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000e48e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e48e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4e48e1: 8db154020000 LEA ESI,[ECX + 0x254]
    s.si = (s.cx+0x00000254u);
  }
  { // 0x4e48e7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4e48e9: e8c2bb1a00 CALL 0x006904b0
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x002904b0u,0x004e48eeu);
    flags=s.arithmetic_flags;
  }
  { // 0x4e48ee: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    const auto operand=m.r32(address);
    s.fp.compare_pop32(operand);
  }
  { // 0x4e48f4: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x4e48f6: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  { // 0x4e48f9: 7408 JZ 0x004e4903
    if(integer::condition("JZ",flags)) goto L004e4903;
  }
  { // 0x4e48fb: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4e4901: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e4902: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004e4903: { // 0x4e4903: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4e4905: e8a6bb1a00 CALL 0x006904b0
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x002904b0u,0x004e490au);
    flags=s.arithmetic_flags;
  }
  { // 0x4e490a: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  { // 0x4e490f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4e4910: dab010140000 FIDIV dword ptr [EAX + 0x1410]
    const auto address=(s.ax+0x00001410u);
    const auto operand=m.r32(address);
    s.fp.divide_integer32(operand);
  }
  { // 0x4e4916: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00235200(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x635200: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x635203: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  { // 0x635206: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x635207: 0588000000 ADD EAX,0x88
    s.ax = integer::add(s.ax,0x00000088u,32,flags);
  }
  { // 0x63520c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x63520d: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x635210: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x635212: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  { // 0x635215: 8b7808 MOV EDI,dword ptr [EAX + 0x8]
    s.di = m.r32((s.ax+0x00000008u));
  }
  { // 0x635218: 8b4118 MOV EAX,dword ptr [ECX + 0x18]
    s.ax = m.r32((s.cx+0x00000018u));
  }
  { // 0x63521b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x63521d: 8b511c MOV EDX,dword ptr [ECX + 0x1c]
    s.dx = m.r32((s.cx+0x0000001cu));
  }
  { // 0x635220: 8b4920 MOV ECX,dword ptr [ECX + 0x20]
    s.cx = m.r32((s.cx+0x00000020u));
  }
  { // 0x635223: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  { // 0x635225: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  { // 0x635227: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  { // 0x63522b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x63522d: 0fafc8 IMUL ECX,EAX
    s.cx = integer::imul(s.cx,s.ax,32,flags);
  }
  { // 0x635230: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x635232: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  { // 0x635235: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x635237: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  { // 0x63523b: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x63523f: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x635242: e8394ee8ff CALL 0x004ba080
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba080u,0x00635247u);
    flags=s.arithmetic_flags;
  }
  { // 0x635247: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    extended::compare64(s.fp,operand);
  }
  { // 0x63524d: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x635250: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x635251: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x635252: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x635254: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  { // 0x635257: 751a JNZ 0x00635273
    if(integer::condition("JNZ",flags)) goto L00635273;
  }
  { // 0x635259: db44240c FILD dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x63525d: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x635260: d8f1 FDIV ST0,ST1
    extra41::divide_st0_st1(s.fp);
  }
  { // 0x635262: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x635265: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x635267: e8b44fe8ff CALL 0x004ba220
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba220u,0x0063526cu);
    flags=s.arithmetic_flags;
  }
  { // 0x63526c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x63526f: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x635272: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00635273: { // 0x635273: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x635275: dd05783e7900 FLD double ptr [0x00793e78]
    const auto address=(0x00793e78u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x63527b: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x63527e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002f9c80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6f9c80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6f9c81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6f9c83: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  { // 0x6f9c89: 8a88a60b0000 MOV CL,byte ptr [EAX + 0xba6]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000ba6u)));
  }
  { // 0x6f9c8f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x6f9c91: 7512 JNZ 0x006f9ca5
    if(integer::condition("JNZ",flags)) goto L006f9ca5;
  }
  { // 0x6f9c93: 8a88a70b0000 MOV CL,byte ptr [EAX + 0xba7]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000ba7u)));
  }
  { // 0x6f9c99: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x6f9c9b: 7508 JNZ 0x006f9ca5
    if(integer::condition("JNZ",flags)) goto L006f9ca5;
  }
  { // 0x6f9c9d: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x6f9ca3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6f9ca4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006f9ca5: { // 0x6f9ca5: 8d8e94020000 LEA ECX,[ESI + 0x294]
    s.cx = (s.si+0x00000294u);
  }
  { // 0x6f9cab: e80068f9ff CALL 0x006904b0
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x002904b0u,0x006f9cb0u);
    flags=s.arithmetic_flags;
  }
  { // 0x6f9cb0: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  { // 0x6f9cb6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6f9cb7: dab0fc060000 FIDIV dword ptr [EAX + 0x6fc]
    const auto address=(s.ax+0x000006fcu);
    const auto operand=m.r32(address);
    s.fp.divide_integer32(operand);
  }
  { // 0x6f9cbd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00308140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x708140: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x708142: dc0df0677800 FMUL double ptr [0x007867f0]
    const auto address=(0x007867f0u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x708148: e903290600 JMP 0x0076aa50
    s.arithmetic_flags=flags; invoke_closed_tail(m,s,f,0x36aa50u); return;
  }
}
void f_00328580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x728580: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x728583: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x728584: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x728586: 8b86a0000000 MOV EAX,dword ptr [ESI + 0xa0]
    s.ax = m.r32((s.si+0x000000a0u));
  }
  { // 0x72858c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x72858e: 7448 JZ 0x007285d8
    if(integer::condition("JZ",flags)) goto L007285d8;
  }
  { // 0x728590: 8b88ac020000 MOV ECX,dword ptr [EAX + 0x2ac]
    s.cx = m.r32((s.ax+0x000002acu));
  }
  { // 0x728596: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x728598: 753e JNZ 0x007285d8
    if(integer::condition("JNZ",flags)) goto L007285d8;
  }
  { // 0x72859a: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  { // 0x7285a0: db8120130000 FILD dword ptr [ECX + 0x1320]
    const auto address=(s.cx+0x00001320u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x7285a6: 8a8865020000 MOV CL,byte ptr [EAX + 0x265]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000265u)));
  }
  { // 0x7285ac: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x7285ae: dd5c2404 FSTP double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x7285b2: 7409 JZ 0x007285bd
    if(integer::condition("JZ",flags)) goto L007285bd;
  }
  { // 0x7285b4: e83773d5ff CALL 0x0047f8f0
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0007f8f0u,0x007285b9u);
    flags=s.arithmetic_flags;
  }
  { // 0x7285b9: dd5c2404 FSTP double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L007285bd: { // 0x7285bd: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x7285c1: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x7285c5: 8b8eb4000000 MOV ECX,dword ptr [ESI + 0xb4]
    s.cx = m.r32((s.si+0x000000b4u));
  }
  { // 0x7285cb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x7285cc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x7285cd: e8be71d5ff CALL 0x0047f790
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0007f790u,0x007285d2u);
    flags=s.arithmetic_flags;
  }
  { // 0x7285d2: 8986a8000000 MOV dword ptr [ESI + 0xa8],EAX
    m.w32((s.si+0x000000a8u), s.ax);
  }
  L007285d8: { // 0x7285d8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7285d9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x7285dc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00328b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x728b30: 8b81a0000000 MOV EAX,dword ptr [ECX + 0xa0]
    s.ax = m.r32((s.cx+0x000000a0u));
  }
  { // 0x728b36: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x728b39: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x728b3b: 7443 JZ 0x00728b80
    if(integer::condition("JZ",flags)) goto L00728b80;
  }
  { // 0x728b3d: 8b90ac020000 MOV EDX,dword ptr [EAX + 0x2ac]
    s.dx = m.r32((s.ax+0x000002acu));
  }
  { // 0x728b43: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x728b45: 7539 JNZ 0x00728b80
    if(integer::condition("JNZ",flags)) goto L00728b80;
  }
  { // 0x728b47: 8a8865020000 MOV CL,byte ptr [EAX + 0x265]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000265u)));
  }
  { // 0x728b4d: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x728b4f: 7407 JZ 0x00728b58
    if(integer::condition("JZ",flags)) goto L00728b58;
  }
  { // 0x728b51: e89a6dd5ff CALL 0x0047f8f0
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0007f8f0u,0x00728b56u);
    flags=s.arithmetic_flags;
  }
  { // 0x728b56: eb0b JMP 0x00728b63
    goto L00728b63;
  }
  L00728b58: { // 0x728b58: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  { // 0x728b5d: db8020130000 FILD dword ptr [EAX + 0x1320]
    const auto address=(s.ax+0x00001320u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  L00728b63: { // 0x728b63: dd5c2400 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x728b67: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x728b6b: 8b542400 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  { // 0x728b6f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x728b70: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x728b74: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x728b75: e8166cd5ff CALL 0x0047f790
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0007f790u,0x00728b7au);
    flags=s.arithmetic_flags;
  }
  { // 0x728b7a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x728b7d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00728b80: { // 0x728b80: 8b81a8000000 MOV EAX,dword ptr [ECX + 0xa8]
    s.ax = m.r32((s.cx+0x000000a8u));
  }
  { // 0x728b86: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x728b89: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
const std::array<Entry,9>& entries_a() {
  static const std::array<Entry,9> entries{{
    {0x7ca70u,f_0007ca70},
    {0xe2480u,f_000e2480},
    {0xe4890u,f_000e4890},
    {0xe48e0u,f_000e48e0},
    {0x235200u,f_00235200},
    {0x2f9c80u,f_002f9c80},
    {0x308140u,f_00308140},
    {0x328580u,f_00328580},
    {0x328b30u,f_00328b30},
  }}; return entries;
}
} // namespace ra2::recovered::floating_chain_b41
