#include "floating_closure_b42_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Original instruction annotations are retained; acceptance requires current native proof.
namespace ra2::recovered::floating_closure_b42 {
namespace {
void f_0001b6e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41b6e0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x41b6e3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x41b6e4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x41b6e6: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x41b6e9: dd4608 FLD double ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x41b6ec: dd06 FLD double ptr [ESI]
    const auto address=(s.si);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x41b6ee: d9c0 FLD ST0
    s.fp.load_st0();
  }
  { // 0x41b6f0: d8c9 FMUL ST1
    extended::multiply_st1(s.fp);
  }
  { // 0x41b6f2: d9c2 FLD ST2
    s.fp.load_st2();
  }
  { // 0x41b6f4: d8cb FMUL ST3
    extended::multiply_st3(s.fp);
  }
  { // 0x41b6f6: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x41b6f8: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x41b6fb: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x41b6fd: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x41b6ff: e87ce90900 CALL 0x004ba080
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba080u,0x0041b704u);
    flags=s.arithmetic_flags;
  }
  { // 0x41b704: 8b5614 MOV EDX,dword ptr [ESI + 0x14]
    s.dx = m.r32((s.si+0x00000014u));
  }
  { // 0x41b707: dd5c240c FSTP double ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x41b70b: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x41b70f: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x41b713: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x41b714: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x41b717: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x41b718: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x41b719: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x41b71a: e851eb0900 CALL 0x004ba270
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba270u,0x0041b71fu);
    flags=s.arithmetic_flags;
  }
  { // 0x41b71f: dc2530667800 FSUB double ptr [0x00786630]
    const auto address=(0x00786630u);
    const auto operand=read64(m,address);
    s.fp.subtract64(operand);
  }
  { // 0x41b725: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  { // 0x41b728: dc0d28667800 FMUL double ptr [0x00786628]
    const auto address=(0x00786628u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x41b72e: e81df33400 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x0041b733u);
    flags=s.arithmetic_flags;
  }
  { // 0x41b733: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x41b737: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x41b738: 668901 MOV word ptr [ECX],AX
    m.w16((s.cx), (s.ax & 0xffffu));
  }
  { // 0x41b73b: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x41b73d: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x41b740: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00023ef0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x423ef0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x423ef4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x423ef5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x423ef7: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x423ef8: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x423efc: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x423efe: 3b11 CMP EDX,dword ptr [ECX]
    (void)integer::sub(s.dx,m.r32((s.cx)),32,flags);
  }
  { // 0x423f00: 750f JNZ 0x00423f11
    if(integer::condition("JNZ",flags)) goto L00423f11;
  }
  { // 0x423f02: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x423f05: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  { // 0x423f08: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  { // 0x423f0a: 7505 JNZ 0x00423f11
    if(integer::condition("JNZ",flags)) goto L00423f11;
  }
  { // 0x423f0c: 66c7060000 MOV word ptr [ESI],0x0
    m.w16((s.si), 0x00000000u);
  }
  L00423f11: { // 0x423f11: db01 FILD dword ptr [ECX]
    const auto address=(s.cx);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x423f13: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x423f16: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x423f19: da20 FISUB dword ptr [EAX]
    const auto address=(s.ax);
    const auto operand=m.r32(address);
    extra42::subtract_integer32(s.fp,operand);
  }
  { // 0x423f1b: dd5c2408 FSTP double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x423f1f: db4004 FILD dword ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x423f22: da6104 FISUB dword ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto operand=m.r32(address);
    extra42::subtract_integer32(s.fp,operand);
  }
  { // 0x423f25: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x423f28: e843630900 CALL 0x004ba270
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba270u,0x00423f2du);
    flags=s.arithmetic_flags;
  }
  { // 0x423f2d: dc2530667800 FSUB double ptr [0x00786630]
    const auto address=(0x00786630u);
    const auto operand=read64(m,address);
    s.fp.subtract64(operand);
  }
  { // 0x423f33: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x423f36: dc0d28667800 FMUL double ptr [0x00786628]
    const auto address=(0x00786628u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x423f3c: e80f6b3400 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x00423f41u);
    flags=s.arithmetic_flags;
  }
  { // 0x423f41: 668944240c MOV word ptr [ESP + 0xc],AX
    m.w16((f.sp+0x0000000cu), (s.ax & 0xffffu));
  }
  { // 0x423f46: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x423f4a: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x423f4c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x423f4e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x423f4f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x423f50: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000ba270(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ba270: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4ba271: dd442410 FLD double ptr [ESP+0x10]
    const auto address=(f.sp+0x00000010u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4ba275: d95c2400 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x4ba279: dd442408 FLD double ptr [ESP+8]
    const auto address=(f.sp+8u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4ba27d: d95c2410 FSTP float ptr [ESP+0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x4ba281: d9442400 FLD float ptr [ESP]
    const auto address=(f.sp);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba285: d81d38577800 FCOMP float ptr [0x785738]
    const auto address=(0x00785738u);
    const auto operand=m.r32(address);
    s.fp.compare_pop32(operand);
  }
  { // 0x4ba28b: d9442410 FLD float ptr [ESP+0x10]
    const auto address=(f.sp+0x00000010u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba28f: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x4ba291: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  { // 0x4ba294: 7436 JZ 0x4ba2cc
    if(integer::condition("JZ",flags)) goto L004ba2cc;
  }
  { // 0x4ba296: d81d38577800 FCOMP float ptr [0x785738]
    const auto address=(0x00785738u);
    const auto operand=m.r32(address);
    s.fp.compare_pop32(operand);
  }
  { // 0x4ba29c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x4ba29e: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  { // 0x4ba2a1: 7408 JZ 0x4ba2ab
    if(integer::condition("JZ",flags)) goto L004ba2ab;
  }
  { // 0x4ba2a3: d90538577800 FLD float ptr [0x785738]
    const auto address=(0x00785738u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba2a9: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x4ba2aa: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba2ab: { // 0x4ba2ab: d9442410 FLD float ptr [ESP+0x10]
    const auto address=(f.sp+0x00000010u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba2af: d81d38577800 FCOMP float ptr [0x785738]
    const auto address=(0x00785738u);
    const auto operand=m.r32(address);
    s.fp.compare_pop32(operand);
  }
  { // 0x4ba2b5: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x4ba2b7: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  { // 0x4ba2ba: 7508 JNZ 0x4ba2c4
    if(integer::condition("JNZ",flags)) goto L004ba2c4;
  }
  { // 0x4ba2bc: d9058cbf7800 FLD float ptr [0x78bf8c]
    const auto address=(0x0078bf8cu);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba2c2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x4ba2c3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba2c4: { // 0x4ba2c4: d90590bf7800 FLD float ptr [0x78bf90]
    const auto address=(0x0078bf90u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba2ca: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x4ba2cb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba2cc: { // 0x4ba2cc: d8742400 FDIV float ptr [ESP]
    const auto address=(f.sp);
    const auto operand=m.r32(address);
    extended::divide32(s.fp,operand);
  }
  { // 0x4ba2d0: d83538018000 FDIV float ptr [0x800138]
    const auto address=(0x00800138u);
    const auto operand=m.r32(address);
    extended::divide32(s.fp,operand);
  }
  { // 0x4ba2d6: e875072b00 CALL 0x76aa50
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0036aa50u,0x004ba2dbu);
    flags=s.arithmetic_flags;
  }
  { // 0x4ba2db: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x4ba2dc: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  { // 0x4ba2de: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x4ba2e0: 3d01100000 CMP EAX,0x1001
    (void)integer::sub(s.ax,0x00001001u,32,flags);
  }
  { // 0x4ba2e5: 7d09 JGE 0x4ba2f0
    if(integer::condition("JGE",flags)) goto L004ba2f0;
  }
  { // 0x4ba2e7: d9048534c17f00 FLD float ptr [EAX*4+0x7fc134]
    const auto address=((s.ax * 4u)+0x007fc134u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba2ee: eb06 JMP 0x4ba2f6
    goto L004ba2f6;
  }
  L004ba2f0: { // 0x4ba2f0: d9058cbf7800 FLD float ptr [0x78bf8c]
    const auto address=(0x0078bf8cu);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  L004ba2f6: { // 0x4ba2f6: d9442400 FLD float ptr [ESP]
    const auto address=(f.sp);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba2fa: d81d38577800 FCOMP float ptr [0x785738]
    const auto address=(0x00785738u);
    const auto operand=m.r32(address);
    s.fp.compare_pop32(operand);
  }
  { // 0x4ba300: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x4ba302: f6c401 TEST AH,1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  { // 0x4ba305: 7406 JZ 0x4ba30d
    if(integer::condition("JZ",flags)) goto L004ba30d;
  }
  { // 0x4ba307: dc2d58817800 FSUBR double ptr [0x788158]
    const auto address=(0x00788158u);
    const auto operand=read64(m,address);
    s.fp.reverse_subtract64(operand);
  }
  L004ba30d: { // 0x4ba30d: d9442410 FLD float ptr [ESP+0x10]
    const auto address=(f.sp+0x00000010u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba311: d81d38577800 FCOMP float ptr [0x785738]
    const auto address=(0x00785738u);
    const auto operand=m.r32(address);
    s.fp.compare_pop32(operand);
  }
  { // 0x4ba317: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x4ba319: f6c401 TEST AH,1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  { // 0x4ba31c: 7402 JZ 0x4ba320
    if(integer::condition("JZ",flags)) goto L004ba320;
  }
  { // 0x4ba31e: d9e0 FCHS
    s.fp.change_sign();
  }
  L004ba320: { // 0x4ba320: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x4ba321: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0018d720(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58d720: d901 FLD float ptr [ECX]
    const auto address=(s.cx);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d722: d94108 FLD float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d725: d9c1 FLD ST1
    s.fp.load_st1();
  }
  { // 0x58d727: d84c2408 FMUL float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d72b: d9c1 FLD ST1
    s.fp.load_st1();
  }
  { // 0x58d72d: d84c2404 FMUL float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d731: dee9 FSUBP
    s.fp.subtract_pop();
  }
  { // 0x58d733: d919 FSTP float ptr [ECX]
    const auto address=(s.cx);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d735: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x58d737: d84c2404 FMUL float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d73b: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x58d73d: d84c2408 FMUL float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d741: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58d743: d95908 FSTP float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d746: d94110 FLD float ptr [ECX+0x10]
    const auto address=(s.cx+0x00000010u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d749: d94118 FLD float ptr [ECX+0x18]
    const auto address=(s.cx+0x00000018u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d74c: d9c1 FLD ST1
    s.fp.load_st1();
  }
  { // 0x58d74e: d84c2408 FMUL float ptr [ESP+8]
    const auto address=(f.sp+8u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d752: d9c1 FLD ST1
    s.fp.load_st1();
  }
  { // 0x58d754: d84c2404 FMUL float ptr [ESP+4]
    const auto address=(f.sp+4u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d758: dee9 FSUBP
    s.fp.subtract_pop();
  }
  { // 0x58d75a: d95910 FSTP float ptr [ECX+0x10]
    const auto address=(s.cx+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d75d: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x58d75f: d84c2404 FMUL float ptr [ESP+4]
    const auto address=(f.sp+4u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d763: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x58d765: d84c2408 FMUL float ptr [ESP+8]
    const auto address=(f.sp+8u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d769: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58d76b: d95918 FSTP float ptr [ECX+0x18]
    const auto address=(s.cx+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d76e: d94120 FLD float ptr [ECX+0x20]
    const auto address=(s.cx+0x00000020u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d771: d94128 FLD float ptr [ECX+0x28]
    const auto address=(s.cx+0x00000028u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d774: d9c1 FLD ST1
    s.fp.load_st1();
  }
  { // 0x58d776: d84c2408 FMUL float ptr [ESP+8]
    const auto address=(f.sp+8u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d77a: d9c1 FLD ST1
    s.fp.load_st1();
  }
  { // 0x58d77c: d84c2404 FMUL float ptr [ESP+4]
    const auto address=(f.sp+4u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d780: dee9 FSUBP
    s.fp.subtract_pop();
  }
  { // 0x58d782: d95920 FSTP float ptr [ECX+0x20]
    const auto address=(s.cx+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d785: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x58d787: d84c2404 FMUL float ptr [ESP+4]
    const auto address=(f.sp+4u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d78b: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x58d78d: d84c2408 FMUL float ptr [ESP+8]
    const auto address=(f.sp+8u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d791: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58d793: d95928 FSTP float ptr [ECX+0x28]
    const auto address=(s.cx+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d796: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0018da10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58da10: 83ec24 SUB ESP,0x24
    f.sp = integer::sub(f.sp,0x00000024u,32,flags);
  }
  { // 0x58da13: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  { // 0x58da17: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x58da19: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x58da1a: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  { // 0x58da1e: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  { // 0x58da26: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  { // 0x58da2e: c74424180000803f MOV dword ptr [ESP + 0x18],0x3f800000
    m.w32((f.sp+0x00000018u), 0x3f800000u);
  }
  { // 0x58da36: e845070000 CALL 0x0058e180
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x0018e180u,0x0058da3bu);
    flags=s.arithmetic_flags;
  }
  { // 0x58da3b: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x58da3d: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x58da40: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  { // 0x58da44: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x58da47: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x58da4a: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  { // 0x58da4e: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  { // 0x58da51: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  { // 0x58da55: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58da59: dd5c2408 FSTP double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x58da5d: d9442410 FLD float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58da61: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x58da64: e807c8f2ff CALL 0x004ba270
    s.arithmetic_flags=flags;
    invoke_closed(m,s,f,0x000ba270u,0x0058da69u);
    flags=s.arithmetic_flags;
  }
  { // 0x58da69: 83c434 ADD ESP,0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  { // 0x58da6c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,5>& entries_a() {
  static const std::array<Entry,5> entries{{
    {0x1b6e0u,f_0001b6e0},
    {0x23ef0u,f_00023ef0},
    {0xba270u,f_000ba270},
    {0x18d720u,f_0018d720},
    {0x18da10u,f_0018da10},
  }}; return entries;
}
} // namespace ra2::recovered::floating_closure_b42
