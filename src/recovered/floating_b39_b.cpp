#include "recovered/floating_b39_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Structural translations; per-RVA native proof remains the acceptance criterion.
namespace ra2::recovered::floating_b39 {
namespace {
void f_00290510(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x690510: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x690514: d90491 FLD float ptr [ECX + EDX*0x4]
    const auto address=(s.cx+(s.dx * 0x00000004u));
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x690517: d85c2404 FCOMP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.compare_pop32(operand);
  }
  { // 0x69051b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x69051d: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x690520: 740e JZ 0x00690530
    if(integer::condition("JZ",flags)) goto L00690530;
  }
  { // 0x690522: d90491 FLD float ptr [ECX + EDX*0x4]
    const auto address=(s.cx+(s.dx * 0x00000004u));
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x690525: d90491 FLD float ptr [ECX + EDX*0x4]
    const auto address=(s.cx+(s.dx * 0x00000004u));
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x690528: d8e1 FSUB ST0,ST1
    s.fp.subtract_st0_st1();
  }
  { // 0x69052a: d91c91 FSTP float ptr [ECX + EDX*0x4]
    const auto address=(s.cx+(s.dx * 0x00000004u));
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x69052d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00690530: { // 0x690530: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x690534: d90491 FLD float ptr [ECX + EDX*0x4]
    const auto address=(s.cx+(s.dx * 0x00000004u));
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x690537: d8e1 FSUB ST0,ST1
    s.fp.subtract_st0_st1();
  }
  { // 0x690539: d91c91 FSTP float ptr [ECX + EDX*0x4]
    const auto address=(s.cx+(s.dx * 0x00000004u));
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x69053c: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_002905a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6905a0: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x6905a4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6905a5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x6905a7: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x6905a9: be04000000 MOV ESI,0x4
    s.si = 0x00000004u;
  }
  L006905ae: { // 0x6905ae: d90402 FLD float ptr [EDX + EAX*0x1]
    const auto address=(s.dx+(s.ax * 0x00000001u));
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x6905b1: d800 FADD float ptr [EAX]
    const auto address=(s.ax);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x6905b3: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  { // 0x6905b6: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x6905b7: d958fc FSTP float ptr [EAX + -0x4]
    const auto address=(s.ax-0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x6905ba: 75f2 JNZ 0x006905ae
    if(integer::condition("JNZ",flags)) goto L006905ae;
  }
  { // 0x6905bc: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x6905c0: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  { // 0x6905c2: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x6905c4: 8932 MOV dword ptr [EDX],ESI
    m.w32((s.dx), s.si);
  }
  { // 0x6905c6: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  { // 0x6905c9: 897204 MOV dword ptr [EDX + 0x4],ESI
    m.w32((s.dx+0x00000004u), s.si);
  }
  { // 0x6905cc: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  { // 0x6905cf: 897208 MOV dword ptr [EDX + 0x8],ESI
    m.w32((s.dx+0x00000008u), s.si);
  }
  { // 0x6905d2: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  { // 0x6905d5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6905d6: 894a0c MOV dword ptr [EDX + 0xc],ECX
    m.w32((s.dx+0x0000000cu), s.cx);
  }
  { // 0x6905d9: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00290640(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x690640: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x690644: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x690645: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x690647: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x690649: be04000000 MOV ESI,0x4
    s.si = 0x00000004u;
  }
  L0069064e: { // 0x69064e: d900 FLD float ptr [EAX]
    const auto address=(s.ax);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x690650: d82402 FSUB float ptr [EDX + EAX*0x1]
    const auto address=(s.dx+(s.ax * 0x00000001u));
    const auto operand=m.r32(address);
    s.fp.subtract32(operand);
  }
  { // 0x690653: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  { // 0x690656: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x690657: d958fc FSTP float ptr [EAX + -0x4]
    const auto address=(s.ax-0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x69065a: 75f2 JNZ 0x0069064e
    if(integer::condition("JNZ",flags)) goto L0069064e;
  }
  { // 0x69065c: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x690660: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  { // 0x690662: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x690664: 8932 MOV dword ptr [EDX],ESI
    m.w32((s.dx), s.si);
  }
  { // 0x690666: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  { // 0x690669: 897204 MOV dword ptr [EDX + 0x4],ESI
    m.w32((s.dx+0x00000004u), s.si);
  }
  { // 0x69066c: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  { // 0x69066f: 897208 MOV dword ptr [EDX + 0x8],ESI
    m.w32((s.dx+0x00000008u), s.si);
  }
  { // 0x690672: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  { // 0x690675: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x690676: 894a0c MOV dword ptr [EDX + 0xc],ECX
    m.w32((s.dx+0x0000000cu), s.cx);
  }
  { // 0x690679: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00290680(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x690680: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00690682: { // 0x690682: d901 FLD float ptr [ECX]
    const auto address=(s.cx);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x690684: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    const auto operand=m.r32(address);
    s.fp.compare_pop32(operand);
  }
  { // 0x69068a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x69068c: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  { // 0x69068f: 740d JZ 0x0069069e
    if(integer::condition("JZ",flags)) goto L0069069e;
  }
  { // 0x690691: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  { // 0x690692: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  { // 0x690695: 83fa04 CMP EDX,0x4
    (void)integer::sub(s.dx,0x00000004u,32,flags);
  }
  { // 0x690698: 7ce8 JL 0x00690682
    if(integer::condition("JL",flags)) goto L00690682;
  }
  { // 0x69069a: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x69069d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0069069e: { // 0x69069e: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x6906a0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002ce100(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ce100: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6ce101: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x6ce103: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6ce105: 89442400 MOV dword ptr [ESP],EAX
    m.w32((f.sp), s.ax);
  }
  { // 0x6ce109: 741f JZ 0x006ce12a
    if(integer::condition("JZ",flags)) goto L006ce12a;
  }
  { // 0x6ce10b: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  { // 0x6ce10e: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x6ce113: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x6ce115: 895118 MOV dword ptr [ECX + 0x18],EDX
    m.w32((s.cx+0x00000018u), s.dx);
  }
  { // 0x6ce118: 89411c MOV dword ptr [ECX + 0x1c],EAX
    m.w32((s.cx+0x0000001cu), s.ax);
  }
  { // 0x6ce11b: 7d03 JGE 0x006ce120
    if(integer::condition("JGE",flags)) goto L006ce120;
  }
  { // 0x6ce11d: 89511c MOV dword ptr [ECX + 0x1c],EDX
    m.w32((s.cx+0x0000001cu), s.dx);
  }
  L006ce120: { // 0x6ce120: db442400 FILD dword ptr [ESP]
    const auto address=(f.sp);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x6ce124: da711c FIDIV dword ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    const auto operand=m.r32(address);
    s.fp.divide_integer32(operand);
  }
  { // 0x6ce127: d95910 FSTP float ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006ce12a: { // 0x6ce12a: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6ce12b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002ce130(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ce130: 8b4118 MOV EAX,dword ptr [ECX + 0x18]
    s.ax = m.r32((s.cx+0x00000018u));
  }
  { // 0x6ce133: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x6ce135: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x6ce137: 745e JZ 0x006ce197
    if(integer::condition("JZ",flags)) goto L006ce197;
  }
  { // 0x6ce139: d94110 FLD float ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x6ce13c: d84114 FADD float ptr [ECX + 0x14]
    const auto address=(s.cx+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x6ce13f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ce140: 8b711c MOV ESI,dword ptr [ECX + 0x1c]
    s.si = m.r32((s.cx+0x0000001cu));
  }
  { // 0x6ce143: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x6ce144: 89711c MOV dword ptr [ECX + 0x1c],ESI
    m.w32((s.cx+0x0000001cu), s.si);
  }
  { // 0x6ce147: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  { // 0x6ce149: d95914 FSTP float ptr [ECX + 0x14]
    const auto address=(s.cx+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x6ce14c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ce14d: 7f48 JG 0x006ce197
    if(integer::condition("JG",flags)) goto L006ce197;
  }
  { // 0x6ce14f: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x6ce150: 740d JZ 0x006ce15f
    if(integer::condition("JZ",flags)) goto L006ce15f;
  }
  { // 0x6ce152: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x6ce153: 741f JZ 0x006ce174
    if(integer::condition("JZ",flags)) goto L006ce174;
  }
  { // 0x6ce155: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x6ce156: 753f JNZ 0x006ce197
    if(integer::condition("JNZ",flags)) goto L006ce197;
  }
  { // 0x6ce158: 895118 MOV dword ptr [ECX + 0x18],EDX
    m.w32((s.cx+0x00000018u), s.dx);
  }
  { // 0x6ce15b: 895114 MOV dword ptr [ECX + 0x14],EDX
    m.w32((s.cx+0x00000014u), s.dx);
  }
  { // 0x6ce15e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006ce15f: { // 0x6ce15f: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  { // 0x6ce162: c7411802000000 MOV dword ptr [ECX + 0x18],0x2
    m.w32((s.cx+0x00000018u), 0x00000002u);
  }
  { // 0x6ce169: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x6ce16c: 89411c MOV dword ptr [ECX + 0x1c],EAX
    m.w32((s.cx+0x0000001cu), s.ax);
  }
  { // 0x6ce16f: 895110 MOV dword ptr [ECX + 0x10],EDX
    m.w32((s.cx+0x00000010u), s.dx);
  }
  { // 0x6ce172: 7f23 JG 0x006ce197
    if(integer::condition("JG",flags)) goto L006ce197;
  }
  L006ce174: { // 0x6ce174: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  { // 0x6ce177: c7411803000000 MOV dword ptr [ECX + 0x18],0x3
    m.w32((s.cx+0x00000018u), 0x00000003u);
  }
  { // 0x6ce17e: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x6ce181: 89411c MOV dword ptr [ECX + 0x1c],EAX
    m.w32((s.cx+0x0000001cu), s.ax);
  }
  { // 0x6ce184: 7d07 JGE 0x006ce18d
    if(integer::condition("JGE",flags)) goto L006ce18d;
  }
  { // 0x6ce186: c7411c01000000 MOV dword ptr [ECX + 0x1c],0x1
    m.w32((s.cx+0x0000001cu), 0x00000001u);
  }
  L006ce18d: { // 0x6ce18d: db01 FILD dword ptr [ECX]
    const auto address=(s.cx);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x6ce18f: da711c FIDIV dword ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    const auto operand=m.r32(address);
    s.fp.divide_integer32(operand);
  }
  { // 0x6ce192: d9e0 FCHS
    s.fp.change_sign();
  }
  { // 0x6ce194: d95910 FSTP float ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006ce197: { // 0x6ce197: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00307f20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x707f20: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x707f24: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x707f28: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  { // 0x707f2d: dc8888050000 FMUL double ptr [EAX + 0x588]
    const auto address=(s.ax+0x00000588u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x707f33: def9 FDIVP
    s.fp.divide_pop();
  }
  { // 0x707f35: dc01 FADD double ptr [ECX]
    const auto address=(s.cx);
    const auto operand=read64(m,address);
    s.fp.add64(operand);
  }
  { // 0x707f37: dd11 FST double ptr [ECX]
    const auto address=(s.cx);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  { // 0x707f39: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  { // 0x707f3f: dd82b8050000 FLD double ptr [EDX + 0x5b8]
    const auto address=(s.dx+0x000005b8u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x707f45: d9c1 FLD ST1
    s.fp.load_st1();
  }
  { // 0x707f47: ded9 FCOMPP
    s.fp.compare_pop_twice();
  }
  { // 0x707f49: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x707f4b: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x707f4e: 7508 JNZ 0x00707f58
    if(integer::condition("JNZ",flags)) goto L00707f58;
  }
  { // 0x707f50: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x707f52: dd82b8050000 FLD double ptr [EDX + 0x5b8]
    const auto address=(s.dx+0x000005b8u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  L00707f58: { // 0x707f58: dd19 FSTP double ptr [ECX]
    const auto address=(s.cx);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x707f5a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00307f60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x707f60: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x707f62: dc1d08577800 FCOMP double ptr [0x00785708]
    const auto address=(0x00785708u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x707f68: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x707f6a: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x707f6d: 7515 JNZ 0x00707f84
    if(integer::condition("JNZ",flags)) goto L00707f84;
  }
  { // 0x707f6f: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x707f71: dc1df8567800 FCOMP double ptr [0x007856f8]
    const auto address=(0x007856f8u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x707f77: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x707f79: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x707f7c: 7406 JZ 0x00707f84
    if(integer::condition("JZ",flags)) goto L00707f84;
  }
  { // 0x707f7e: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x707f83: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707f84: { // 0x707f84: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x707f86: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00307f90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x707f90: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x707f92: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x707f98: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x707f9a: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x707f9d: 7515 JNZ 0x00707fb4
    if(integer::condition("JNZ",flags)) goto L00707fb4;
  }
  { // 0x707f9f: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x707fa1: dc1d08577800 FCOMP double ptr [0x00785708]
    const auto address=(0x00785708u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x707fa7: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x707fa9: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x707fac: 7406 JZ 0x00707fb4
    if(integer::condition("JZ",flags)) goto L00707fb4;
  }
  { // 0x707fae: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x707fb3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707fb4: { // 0x707fb4: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x707fb6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00307fc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x707fc0: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x707fc2: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x707fc8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x707fca: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x707fcd: 7406 JZ 0x00707fd5
    if(integer::condition("JZ",flags)) goto L00707fd5;
  }
  { // 0x707fcf: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x707fd4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707fd5: { // 0x707fd5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x707fd7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00307fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x707fe0: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x707fe2: dc1df8567800 FCOMP double ptr [0x007856f8]
    const auto address=(0x007856f8u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x707fe8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x707fea: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x707fed: 7506 JNZ 0x00707ff5
    if(integer::condition("JNZ",flags)) goto L00707ff5;
  }
  { // 0x707fef: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x707ff4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707ff5: { // 0x707ff5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x707ff7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00308000(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x708000: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x708002: dc1df8567800 FCOMP double ptr [0x007856f8]
    const auto address=(0x007856f8u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x708008: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x70800a: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x70800d: 7503 JNZ 0x00708012
    if(integer::condition("JNZ",flags)) goto L00708012;
  }
  { // 0x70800f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x708011: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00708012: { // 0x708012: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x708014: dc1d08577800 FCOMP double ptr [0x00785708]
    const auto address=(0x00785708u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x70801a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x70801c: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x70801f: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x708024: 7405 JZ 0x0070802b
    if(integer::condition("JZ",flags)) goto L0070802b;
  }
  { // 0x708026: b802000000 MOV EAX,0x2
    s.ax = 0x00000002u;
  }
  L0070802b: { // 0x70802b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00308150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x708150: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x708154: dc0d18757800 FMUL double ptr [0x00787518]
    const auto address=(0x00787518u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x70815a: dd19 FSTP double ptr [ECX]
    const auto address=(s.cx);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x70815c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0036aa34(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76aa34: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x76aa35: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x76aa37: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x76aa3a: 9b WAIT
    s.fp.wait();
  }
  { // 0x76aa3b: 9bd97dfe FSTCW word ptr [EBP + -0x2]
    const auto address=(s.bp-0x00000002u);
    const auto value=s.fp.waiting_control();
    m.w16(address,value);
  }
  { // 0x76aa3f: 9b WAIT
    s.fp.wait();
  }
  { // 0x76aa40: 668b45fe MOV AX,word ptr [EBP + -0x2]
    s.ax = with_ax(s.ax, m.r16((s.bp-0x00000002u)));
  }
  { // 0x76aa44: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  { // 0x76aa49: a3043a7c00 MOV [0x007c3a04],EAX
    m.w32((0x007c3a04u), s.ax);
  }
  { // 0x76aa4e: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x76aa4f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
    const auto operand=m.r16(address);
    s.fp.load_control(operand);
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
void f_0036dce5(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x76dce5: d9c0 FLD ST0
    s.fp.load_st0();
  }
  { // 0x76dce7: d9fc FRNDINT
    s.fp.round_integer();
  }
  { // 0x76dce9: d8d9 FCOMP
    s.fp.compare_pop_st1();
  }
  { // 0x76dceb: b100 MOV CL,0x0
    s.cx = with_al(s.cx, 0x00000000u);
  }
  { // 0x76dced: 9bdfe0 FSTSW AX
    s.ax=with_ax(s.ax,s.fp.waiting_status());
  }
  { // 0x76dcf0: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  { // 0x76dcf1: 7517 JNZ 0x0076dd0a
    if(integer::condition("JNZ",flags)) goto L0076dd0a;
  }
  { // 0x76dcf3: dc0d506f8100 FMUL double ptr [0x00816f50]
    const auto address=(0x00816f50u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x76dcf9: fec1 INC CL
    s.cx = with_al(s.cx, integer::increment((s.cx & 0xffu),8,flags));
  }
  { // 0x76dcfb: d9c0 FLD ST0
    s.fp.load_st0();
  }
  { // 0x76dcfd: d9fc FRNDINT
    s.fp.round_integer();
  }
  { // 0x76dcff: ded9 FCOMPP
    s.fp.compare_pop_twice();
  }
  { // 0x76dd01: 9bdfe0 FSTSW AX
    s.ax=with_ax(s.ax,s.fp.waiting_status());
  }
  { // 0x76dd04: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  { // 0x76dd05: 7502 JNZ 0x0076dd09
    if(integer::condition("JNZ",flags)) goto L0076dd09;
  }
  { // 0x76dd07: fec1 INC CL
    s.cx = with_al(s.cx, integer::increment((s.cx & 0xffu),8,flags));
  }
  L0076dd09: { // 0x76dd09: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076dd0a: { // 0x76dd0a: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x76dd0c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00372681(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x772681: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x772682: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x772684: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  { // 0x772687: dd0570c77900 FLD double ptr [0x0079c770]
    const auto address=(0x0079c770u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x77268d: dd5df8 FSTP double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x772690: dd0568c77900 FLD double ptr [0x0079c768]
    const auto address=(0x0079c768u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x772696: dd5df0 FSTP double ptr [EBP + -0x10]
    const auto address=(s.bp-0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x772699: dd45f0 FLD double ptr [EBP + -0x10]
    const auto address=(s.bp-0x00000010u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x77269c: dc75f8 FDIV double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto operand=read64(m,address);
    s.fp.divide64(operand);
  }
  { // 0x77269f: dc4df8 FMUL double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x7726a2: dc6df0 FSUBR double ptr [EBP + -0x10]
    const auto address=(s.bp-0x00000010u);
    const auto operand=read64(m,address);
    s.fp.reverse_subtract64(operand);
  }
  { // 0x7726a5: dd5de8 FSTP double ptr [EBP + -0x18]
    const auto address=(s.bp-0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x7726a8: dd45e8 FLD double ptr [EBP + -0x18]
    const auto address=(s.bp-0x00000018u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x7726ab: dc1d08577800 FCOMP double ptr [0x00785708]
    const auto address=(0x00785708u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x7726b1: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x7726b3: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  { // 0x7726b4: 7605 JBE 0x007726bb
    if(integer::condition("JBE",flags)) goto L007726bb;
  }
  { // 0x7726b6: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x7726b8: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  { // 0x7726b9: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x7726ba: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L007726bb: { // 0x7726bb: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x7726bd: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x7726be: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00372f50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x772f50: d9c0 FLD ST0
    s.fp.load_st0();
  }
  { // 0x772f52: d9fc FRNDINT
    s.fp.round_integer();
  }
  { // 0x772f54: dce1 FSUBR ST1,ST0
    s.fp.reverse_subtract_st1_st0();
  }
  { // 0x772f56: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x772f58: d9e0 FCHS
    s.fp.change_sign();
  }
  { // 0x772f5a: d9f0 F2XM1
    s.fp.two_to_x_minus_one();
  }
  { // 0x772f5c: d9e8 FLD1
    s.fp.load_one();
  }
  { // 0x772f5e: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x772f60: d9fd FSCALE
    s.fp.scale();
  }
  { // 0x772f62: ddd9 FSTP ST1
    s.fp.pop_st1();
  }
  { // 0x772f64: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00372f65(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x772f65: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x772f69: 81e200030000 AND EDX,0x300
    s.dx = integer::logical((s.dx)&(0x00000300u),32,flags);
  }
  { // 0x772f6f: 83ca7f OR EDX,0x7f
    s.dx = integer::logical((s.dx)|(0x0000007fu),32,flags);
  }
  { // 0x772f72: 6689542406 MOV word ptr [ESP + 0x6],DX
    m.w16((f.sp+0x00000006u), (s.dx & 0xffffu));
  }
  { // 0x772f77: d96c2406 FLDCW word ptr [ESP + 0x6]
    const auto address=(f.sp+0x00000006u);
    const auto operand=m.r16(address);
    s.fp.load_control(operand);
  }
  { // 0x772f7b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00372f95(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x772f95: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  { // 0x772f98: 250000f07f AND EAX,0x7ff00000
    s.ax = integer::logical((s.ax)&(0x7ff00000u),32,flags);
  }
  { // 0x772f9d: 3d0000f07f CMP EAX,0x7ff00000
    (void)integer::sub(s.ax,0x7ff00000u,32,flags);
  }
  { // 0x772fa2: 7403 JZ 0x00772fa7
    if(integer::condition("JZ",flags)) goto L00772fa7;
  }
  { // 0x772fa4: dd02 FLD double ptr [EDX]
    const auto address=(s.dx);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x772fa6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00772fa7: { // 0x772fa7: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  { // 0x772faa: 83ec0a SUB ESP,0xa
    f.sp = integer::sub(f.sp,0x0000000au,32,flags);
  }
  { // 0x772fad: 0d0000ff7f OR EAX,0x7fff0000
    s.ax = integer::logical((s.ax)|(0x7fff0000u),32,flags);
  }
  { // 0x772fb2: 89442406 MOV dword ptr [ESP + 0x6],EAX
    m.w32((f.sp+0x00000006u), s.ax);
  }
  { // 0x772fb6: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  { // 0x772fb9: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  { // 0x772fbb: 0fa4c80b SHLD EAX,ECX,0xb
    s.ax=shld11(s.ax,s.cx,flags);
  }
  { // 0x772fbf: c1e10b SHL ECX,0xb
    s.cx = integer::shift(s.cx,0x0000000bu,32,flags,integer::Shift::left);
  }
  { // 0x772fc2: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  { // 0x772fc6: 890c24 MOV dword ptr [ESP],ECX
    m.w32((f.sp), s.cx);
  }
  { // 0x772fc9: db2c24 FLD extended double ptr [ESP]
    const auto address=(f.sp);
    const auto operand=read80(m,address);
    s.fp.load80(operand);
  }
  { // 0x772fcc: 83c40a ADD ESP,0xa
    f.sp = integer::add(f.sp,0x0000000au,32,flags);
  }
  { // 0x772fcf: a900000000 TEST EAX,0x0
    (void)integer::logical((s.ax)&(0x00000000u),32,flags);
  }
  { // 0x772fd4: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  { // 0x772fd7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00372fee(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x772fee: 66813c247f02 CMP word ptr [ESP],0x27f
    (void)integer::sub(m.r16((f.sp)),0x0000027fu,16,flags);
  }
  { // 0x772ff4: 7403 JZ 0x00772ff9
    if(integer::condition("JZ",flags)) goto L00772ff9;
  }
  { // 0x772ff6: d92c24 FLDCW word ptr [ESP]
    const auto address=(f.sp);
    const auto operand=m.r16(address);
    s.fp.load_control(operand);
  }
  L00772ff9: { // 0x772ff9: 5a POP EDX
    const auto value=f.pop(m); s.dx = value;
  }
  { // 0x772ffa: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00378dbe(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x778dbe: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x778dbf: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x778dc1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778dc2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778dc3: dd4508 FLD double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x778dc6: d9fc FRNDINT
    s.fp.round_integer();
  }
  { // 0x778dc8: dd5df8 FSTP double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x778dcb: dd45f8 FLD double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x778dce: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x778dcf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00378dd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x778dd0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x778dd1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x778dd3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778dd4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778dd5: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  { // 0x778dd8: 8b4d0e MOV ECX,dword ptr [EBP + 0xe]
    s.cx = m.r32((s.bp+0x0000000eu));
  }
  { // 0x778ddb: dd4508 FLD double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x778dde: 05fe030000 ADD EAX,0x3fe
    s.ax = integer::add(s.ax,0x000003feu,32,flags);
  }
  { // 0x778de3: 6681e10f80 AND CX,0x800f
    s.cx = with_ax(s.cx, integer::logical(((s.cx & 0xffffu))&(0x0000800fu),16,flags));
  }
  { // 0x778de8: dd5df8 FSTP double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x778deb: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x778dee: 0bc1 OR EAX,ECX
    s.ax = integer::logical((s.ax)|(s.cx),32,flags);
  }
  { // 0x778df0: 668945fe MOV word ptr [EBP + -0x2],AX
    m.w16((s.bp-0x00000002u), (s.ax & 0xffffu));
  }
  { // 0x778df4: dd45f8 FLD double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x778df7: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x778df8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00378e39(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x778e39: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x778e3a: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x778e3c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778e3d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778e3e: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  { // 0x778e41: 8b4d0e MOV ECX,dword ptr [EBP + 0xe]
    s.cx = m.r32((s.bp+0x0000000eu));
  }
  { // 0x778e44: dd4508 FLD double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x778e47: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x778e4a: dd5df8 FSTP double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x778e4d: 6681e10f80 AND CX,0x800f
    s.cx = with_ax(s.cx, integer::logical(((s.cx & 0xffffu))&(0x0000800fu),16,flags));
  }
  { // 0x778e52: 0bc1 OR EAX,ECX
    s.ax = integer::logical((s.ax)|(s.cx),32,flags);
  }
  { // 0x778e54: 668945fe MOV word ptr [EBP + -0x2],AX
    m.w16((s.bp-0x00000002u), (s.ax & 0xffffu));
  }
  { // 0x778e58: dd45f8 FLD double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x778e5b: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x778e5c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00378f78(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x778f78: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x778f79: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x778f7b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778f7c: 9bdd7dfe FSTSW word ptr [EBP + -0x2]
    const auto address=(s.bp-0x00000002u);
    const auto value=s.fp.waiting_status();
    m.w16(address,value);
  }
  { // 0x778f80: 0fbf45fe MOVSX EAX,word ptr [EBP + -0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp-0x00000002u)),16));
  }
  { // 0x778f84: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x778f85: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00378f86(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x778f86: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x778f87: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x778f89: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778f8a: dd7dfe FNSTSW word ptr [EBP + -0x2]
    const auto address=(s.bp-0x00000002u);
    const auto value=s.fp.status();
    m.w16(address,value);
  }
  { // 0x778f8d: dbe2 FNCLEX
    s.fp.clear_exceptions();
  }
  { // 0x778f8f: 0fbf45fe MOVSX EAX,word ptr [EBP + -0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp-0x00000002u)),16));
  }
  { // 0x778f93: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x778f94: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00378f95(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x778f95: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x778f96: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x778f98: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778f99: 9bd97dfc FSTCW word ptr [EBP + -0x4]
    const auto address=(s.bp-0x00000004u);
    const auto value=s.fp.waiting_control();
    m.w16(address,value);
  }
  { // 0x778f9d: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x778fa0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x778fa2: 234508 AND EAX,dword ptr [EBP + 0x8]
    s.ax = integer::logical((s.ax)&(m.r32((s.bp+0x00000008u))),32,flags);
  }
  { // 0x778fa5: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x778fa7: 234dfc AND ECX,dword ptr [EBP + -0x4]
    s.cx = integer::logical((s.cx)&(m.r32((s.bp-0x00000004u))),32,flags);
  }
  { // 0x778faa: 0bc8 OR ECX,EAX
    s.cx = integer::logical((s.cx)|(s.ax),32,flags);
  }
  { // 0x778fac: 894d0c MOV dword ptr [EBP + 0xc],ECX
    m.w32((s.bp+0x0000000cu), s.cx);
  }
  { // 0x778faf: d96d0c FLDCW word ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    const auto operand=m.r16(address);
    s.fp.load_control(operand);
  }
  { // 0x778fb2: 0fbf45fc MOVSX EAX,word ptr [EBP + -0x4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp-0x00000004u)),16));
  }
  { // 0x778fb6: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x778fb7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00378fb8(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x778fb8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x778fb9: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x778fbb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778fbc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x778fbd: 8a4d08 MOV CL,byte ptr [EBP + 0x8]
    s.cx = with_al(s.cx, m.r8((s.bp+0x00000008u)));
  }
  { // 0x778fc0: f6c101 TEST CL,0x1
    (void)integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x778fc3: 740a JZ 0x00778fcf
    if(integer::condition("JZ",flags)) goto L00778fcf;
  }
  { // 0x778fc5: db2d287b8100 FLD extended double ptr [0x00817b28]
    const auto address=(0x00817b28u);
    const auto operand=read80(m,address);
    s.fp.load80(operand);
  }
  { // 0x778fcb: db5d08 FISTP dword ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    const auto value=s.fp.pop_integer32();
    m.w32(address,value);
  }
  { // 0x778fce: 9b WAIT
    s.fp.wait();
  }
  L00778fcf: { // 0x778fcf: f6c108 TEST CL,0x8
    (void)integer::logical(((s.cx & 0xffu))&(0x00000008u),8,flags);
  }
  { // 0x778fd2: 7410 JZ 0x00778fe4
    if(integer::condition("JZ",flags)) goto L00778fe4;
  }
  { // 0x778fd4: 9bdfe0 FSTSW AX
    s.ax=with_ax(s.ax,s.fp.waiting_status());
  }
  { // 0x778fd7: db2d287b8100 FLD extended double ptr [0x00817b28]
    const auto address=(0x00817b28u);
    const auto operand=read80(m,address);
    s.fp.load80(operand);
  }
  { // 0x778fdd: dd5df8 FSTP double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x778fe0: 9b WAIT
    s.fp.wait();
  }
  { // 0x778fe1: 9bdfe0 FSTSW AX
    s.ax=with_ax(s.ax,s.fp.waiting_status());
  }
  L00778fe4: { // 0x778fe4: f6c110 TEST CL,0x10
    (void)integer::logical(((s.cx & 0xffu))&(0x00000010u),8,flags);
  }
  { // 0x778fe7: 740a JZ 0x00778ff3
    if(integer::condition("JZ",flags)) goto L00778ff3;
  }
  { // 0x778fe9: db2d347b8100 FLD extended double ptr [0x00817b34]
    const auto address=(0x00817b34u);
    const auto operand=read80(m,address);
    s.fp.load80(operand);
  }
  { // 0x778fef: dd5df8 FSTP double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x778ff2: 9b WAIT
    s.fp.wait();
  }
  L00778ff3: { // 0x778ff3: f6c104 TEST CL,0x4
    (void)integer::logical(((s.cx & 0xffu))&(0x00000004u),8,flags);
  }
  { // 0x778ff6: 7409 JZ 0x00779001
    if(integer::condition("JZ",flags)) goto L00779001;
  }
  { // 0x778ff8: d9ee FLDZ
    s.fp.load_zero();
  }
  { // 0x778ffa: d9e8 FLD1
    s.fp.load_one();
  }
  { // 0x778ffc: def1 FDIVRP
    s.fp.reverse_divide_pop();
  }
  { // 0x778ffe: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x779000: 9b WAIT
    s.fp.wait();
  }
  L00779001: { // 0x779001: f6c120 TEST CL,0x20
    (void)integer::logical(((s.cx & 0xffu))&(0x00000020u),8,flags);
  }
  { // 0x779004: 7406 JZ 0x0077900c
    if(integer::condition("JZ",flags)) goto L0077900c;
  }
  { // 0x779006: d9eb FLDPI
    s.fp.load_pi();
  }
  { // 0x779008: dd5df8 FSTP double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x77900b: 9b WAIT
    s.fp.wait();
  }
  L0077900c: { // 0x77900c: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77900d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0037cd7b(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77cd7b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77cd7c: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77cd7e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x77cd7f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x77cd80: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x77cd83: 8945f8 MOV dword ptr [EBP + -0x8],EAX
    m.w32((s.bp-0x00000008u), s.ax);
  }
  { // 0x77cd86: 8b4514 MOV EAX,dword ptr [EBP + 0x14]
    s.ax = m.r32((s.bp+0x00000014u));
  }
  { // 0x77cd89: 33450c XOR EAX,dword ptr [EBP + 0xc]
    s.ax = integer::logical((s.ax)^(m.r32((s.bp+0x0000000cu))),32,flags);
  }
  { // 0x77cd8c: 25ffffff7f AND EAX,0x7fffffff
    s.ax = integer::logical((s.ax)&(0x7fffffffu),32,flags);
  }
  { // 0x77cd91: 334514 XOR EAX,dword ptr [EBP + 0x14]
    s.ax = integer::logical((s.ax)^(m.r32((s.bp+0x00000014u))),32,flags);
  }
  { // 0x77cd94: 8945fc MOV dword ptr [EBP + -0x4],EAX
    m.w32((s.bp-0x00000004u), s.ax);
  }
  { // 0x77cd97: dd45f8 FLD double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x77cd9a: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77cd9b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0037cd9c(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77cd9c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77cd9d: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77cd9f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x77cda0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x77cda1: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x77cda4: 8945f8 MOV dword ptr [EBP + -0x8],EAX
    m.w32((s.bp-0x00000008u), s.ax);
  }
  { // 0x77cda7: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x77cdaa: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  { // 0x77cdac: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x77cdae: 334d0c XOR ECX,dword ptr [EBP + 0xc]
    s.cx = integer::logical((s.cx)^(m.r32((s.bp+0x0000000cu))),32,flags);
  }
  { // 0x77cdb1: 81e1ffffff7f AND ECX,0x7fffffff
    s.cx = integer::logical((s.cx)&(0x7fffffffu),32,flags);
  }
  { // 0x77cdb7: 33c8 XOR ECX,EAX
    s.cx = integer::logical((s.cx)^(s.ax),32,flags);
  }
  { // 0x77cdb9: 894dfc MOV dword ptr [EBP + -0x4],ECX
    m.w32((s.bp-0x00000004u), s.cx);
  }
  { // 0x77cdbc: dd45f8 FLD double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x77cdbf: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77cdc0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,30>& entries_b() {
  static const std::array<Entry,30> entries{{
    {0x290510u,f_00290510},
    {0x2905a0u,f_002905a0},
    {0x290640u,f_00290640},
    {0x290680u,f_00290680},
    {0x2ce100u,f_002ce100},
    {0x2ce130u,f_002ce130},
    {0x307f20u,f_00307f20},
    {0x307f60u,f_00307f60},
    {0x307f90u,f_00307f90},
    {0x307fc0u,f_00307fc0},
    {0x307fe0u,f_00307fe0},
    {0x308000u,f_00308000},
    {0x308150u,f_00308150},
    {0x36aa34u,f_0036aa34},
    {0x36aa50u,f_0036aa50},
    {0x36dce5u,f_0036dce5},
    {0x372681u,f_00372681},
    {0x372f50u,f_00372f50},
    {0x372f65u,f_00372f65},
    {0x372f95u,f_00372f95},
    {0x372feeu,f_00372fee},
    {0x378dbeu,f_00378dbe},
    {0x378dd0u,f_00378dd0},
    {0x378e39u,f_00378e39},
    {0x378f78u,f_00378f78},
    {0x378f86u,f_00378f86},
    {0x378f95u,f_00378f95},
    {0x378fb8u,f_00378fb8},
    {0x37cd7bu,f_0037cd7b},
    {0x37cd9cu,f_0037cd9c},
  }}; return entries;
}
} // namespace ra2::recovered::floating_b39
