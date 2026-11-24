#include "recovered/floating_b39_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Structural translations; per-RVA native proof remains the acceptance criterion.
namespace ra2::recovered::floating_b39 {
namespace {
void f_00005120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x405120: a1f8928100 MOV EAX,[0x008192f8]
    s.ax = m.r32((0x008192f8u));
  }
  { // 0x405125: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x405127: 7507 JNZ 0x00405130
    if(integer::condition("JNZ",flags)) goto L00405130;
  }
  { // 0x405129: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x40512f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00405130: { // 0x405130: d94154 FLD float ptr [ECX + 0x54]
    const auto address=(s.cx+0x00000054u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x405133: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0001b7f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41b7f0: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x41b7f2: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x41b7f8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x41b7fa: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  { // 0x41b7fd: 742d JZ 0x0041b82c
    if(integer::condition("JZ",flags)) goto L0041b82c;
  }
  { // 0x41b7ff: dd4108 FLD double ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x41b802: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x41b808: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x41b80a: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  { // 0x41b80d: 741d JZ 0x0041b82c
    if(integer::condition("JZ",flags)) goto L0041b82c;
  }
  { // 0x41b80f: dd4110 FLD double ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x41b812: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x41b818: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x41b81a: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  { // 0x41b81d: 740d JZ 0x0041b82c
    if(integer::condition("JZ",flags)) goto L0041b82c;
  }
  { // 0x41b81f: c70100000000 MOV dword ptr [ECX],0x0
    m.w32((s.cx), 0x00000000u);
  }
  { // 0x41b825: c7410400005940 MOV dword ptr [ECX + 0x4],0x40590000
    m.w32((s.cx+0x00000004u), 0x40590000u);
  }
  L0041b82c: { // 0x41b82c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0001b860(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x41b860: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x41b862: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x41b868: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x41b86a: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  { // 0x41b86d: 741d JZ 0x0041b88c
    if(integer::condition("JZ",flags)) goto L0041b88c;
  }
  { // 0x41b86f: dd4108 FLD double ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x41b872: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x41b878: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x41b87a: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  { // 0x41b87d: 740d JZ 0x0041b88c
    if(integer::condition("JZ",flags)) goto L0041b88c;
  }
  { // 0x41b87f: c70100000000 MOV dword ptr [ECX],0x0
    m.w32((s.cx), 0x00000000u);
  }
  { // 0x41b885: c7410400005940 MOV dword ptr [ECX + 0x4],0x40590000
    m.w32((s.cx+0x00000004u), 0x40590000u);
  }
  L0041b88c: { // 0x41b88c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00037530(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x437530: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x437534: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x437536: d808 FMUL float ptr [EAX]
    const auto address=(s.ax);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x437538: d918 FSTP float ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x43753a: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x43753e: d84804 FMUL float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x437541: d95804 FSTP float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x437544: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x437548: d84808 FMUL float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x43754b: d95808 FSTP float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x43754e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00037560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x437560: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x437562: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x437566: d901 FLD float ptr [ECX]
    const auto address=(s.cx);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x437568: d800 FADD float ptr [EAX]
    const auto address=(s.ax);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x43756a: d918 FSTP float ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x43756c: d94104 FLD float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x43756f: d84004 FADD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x437572: d95804 FSTP float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x437575: d94108 FLD float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x437578: d84008 FADD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x43757b: d95808 FSTP float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x43757e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00063ed0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x463ed0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x463ed2: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x463ed6: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x463ed8: dc00 FADD double ptr [EAX]
    const auto address=(s.ax);
    const auto operand=read64(m,address);
    s.fp.add64(operand);
  }
  { // 0x463eda: dd18 FSTP double ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x463edc: dd4108 FLD double ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x463edf: dc4008 FADD double ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    const auto operand=read64(m,address);
    s.fp.add64(operand);
  }
  { // 0x463ee2: dd5808 FSTP double ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x463ee5: dd4110 FLD double ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x463ee8: dc4010 FADD double ptr [EAX + 0x10]
    const auto address=(s.ax+0x00000010u);
    const auto operand=read64(m,address);
    s.fp.add64(operand);
  }
  { // 0x463eeb: dd5810 FSTP double ptr [EAX + 0x10]
    const auto address=(s.ax+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x463eee: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0007caa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47caa0: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x47caa4: dc81f0000000 FADD double ptr [ECX + 0xf0]
    const auto address=(s.cx+0x000000f0u);
    const auto operand=read64(m,address);
    s.fp.add64(operand);
  }
  { // 0x47caaa: dd99f0000000 FSTP double ptr [ECX + 0xf0]
    const auto address=(s.cx+0x000000f0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x47cab0: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0007cac0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47cac0: dd81f0000000 FLD double ptr [ECX + 0xf0]
    const auto address=(s.cx+0x000000f0u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x47cac6: dc642404 FSUB double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=read64(m,address);
    s.fp.subtract64(operand);
  }
  { // 0x47caca: dd91f0000000 FST double ptr [ECX + 0xf0]
    const auto address=(s.cx+0x000000f0u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  { // 0x47cad0: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x47cad6: d8d9 FCOMP
    s.fp.compare_pop_st1();
  }
  { // 0x47cad8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x47cada: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  { // 0x47cadd: 7519 JNZ 0x0047caf8
    if(integer::condition("JNZ",flags)) goto L0047caf8;
  }
  { // 0x47cadf: c781f000000000000000 MOV dword ptr [ECX + 0xf0],0x0
    m.w32((s.cx+0x000000f0u), 0x00000000u);
  }
  { // 0x47cae9: c781f400000000000000 MOV dword ptr [ECX + 0xf4],0x0
    m.w32((s.cx+0x000000f4u), 0x00000000u);
  }
  { // 0x47caf3: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x47caf5: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0047caf8: { // 0x47caf8: dd99f0000000 FSTP double ptr [ECX + 0xf0]
    const auto address=(s.cx+0x000000f0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x47cafe: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0007f8f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x47f8f0: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  { // 0x47f8f5: db8020130000 FILD dword ptr [EAX + 0x1320]
    const auto address=(s.ax+0x00001320u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x47f8fb: dc0d28577800 FMUL double ptr [0x00785728]
    const auto address=(0x00785728u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x47f901: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000968b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4968b0: 8a4118 MOV AL,byte ptr [ECX + 0x18]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000018u)));
  }
  { // 0x4968b3: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x4968b6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4968b8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4968b9: 744a JZ 0x00496905
    if(integer::condition("JZ",flags)) goto L00496905;
  }
  { // 0x4968bb: 8b7114 MOV ESI,dword ptr [ECX + 0x14]
    s.si = m.r32((s.cx+0x00000014u));
  }
  { // 0x4968be: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4968c0: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  { // 0x4968c4: 743f JZ 0x00496905
    if(integer::condition("JZ",flags)) goto L00496905;
  }
  { // 0x4968c6: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  { // 0x4968c9: 8b4110 MOV EAX,dword ptr [ECX + 0x10]
    s.ax = m.r32((s.cx+0x00000010u));
  }
  { // 0x4968cc: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  { // 0x4968cf: 7412 JZ 0x004968e3
    if(integer::condition("JZ",flags)) goto L004968e3;
  }
  { // 0x4968d1: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x4968d7: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x4968d9: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x4968db: 7d04 JGE 0x004968e1
    if(integer::condition("JGE",flags)) goto L004968e1;
  }
  { // 0x4968dd: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4968df: eb02 JMP 0x004968e3
    goto L004968e3;
  }
  L004968e1: { // 0x4968e1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004968e3: { // 0x4968e3: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x4968e5: 89742404 MOV dword ptr [ESP + 0x4],ESI
    m.w32((f.sp+0x00000004u), s.si);
  }
  { // 0x4968e9: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x4968ed: da742408 FIDIV dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.divide_integer32(operand);
  }
  { // 0x4968f1: dc1d08577800 FCOMP double ptr [0x00785708]
    const auto address=(0x00785708u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x4968f7: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x4968f9: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  { // 0x4968fc: 7507 JNZ 0x00496905
    if(integer::condition("JNZ",flags)) goto L00496905;
  }
  { // 0x4968fe: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x496900: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x496901: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x496904: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00496905: { // 0x496905: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x496907: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x496908: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x49690b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00096a50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x496a50: 8a4118 MOV AL,byte ptr [ECX + 0x18]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000018u)));
  }
  { // 0x496a53: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x496a56: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x496a58: 7458 JZ 0x00496ab2
    if(integer::condition("JZ",flags)) goto L00496ab2;
  }
  { // 0x496a5a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x496a5b: 8b7114 MOV ESI,dword ptr [ECX + 0x14]
    s.si = m.r32((s.cx+0x00000014u));
  }
  { // 0x496a5e: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x496a60: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  { // 0x496a64: 750b JNZ 0x00496a71
    if(integer::condition("JNZ",flags)) goto L00496a71;
  }
  { // 0x496a66: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x496a6c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x496a6d: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x496a70: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00496a71: { // 0x496a71: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  { // 0x496a74: 8b4110 MOV EAX,dword ptr [ECX + 0x10]
    s.ax = m.r32((s.cx+0x00000010u));
  }
  { // 0x496a77: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  { // 0x496a7a: 7423 JZ 0x00496a9f
    if(integer::condition("JZ",flags)) goto L00496a9f;
  }
  { // 0x496a7c: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  { // 0x496a82: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x496a84: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x496a86: 7d15 JGE 0x00496a9d
    if(integer::condition("JGE",flags)) goto L00496a9d;
  }
  { // 0x496a88: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x496a8a: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x496a8c: 89742404 MOV dword ptr [ESP + 0x4],ESI
    m.w32((f.sp+0x00000004u), s.si);
  }
  { // 0x496a90: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x496a91: db442400 FILD dword ptr [ESP]
    const auto address=(f.sp);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x496a95: da742404 FIDIV dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.divide_integer32(operand);
  }
  { // 0x496a99: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x496a9c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00496a9d: { // 0x496a9d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00496a9f: { // 0x496a9f: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x496aa1: 89742404 MOV dword ptr [ESP + 0x4],ESI
    m.w32((f.sp+0x00000004u), s.si);
  }
  { // 0x496aa5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x496aa6: db442400 FILD dword ptr [ESP]
    const auto address=(f.sp);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x496aaa: da742404 FIDIV dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.divide_integer32(operand);
  }
  { // 0x496aae: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x496ab1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00496ab2: { // 0x496ab2: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x496ab8: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x496abb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ba080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4ba080: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4ba084: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    const auto operand=m.r32(address);
    s.fp.compare32(operand);
  }
  { // 0x4ba08a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x4ba08c: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  { // 0x4ba08f: 7409 JZ 0x004ba09a
    if(integer::condition("JZ",flags)) goto L004ba09a;
  }
  { // 0x4ba091: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x4ba093: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba099: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba09a: { // 0x4ba09a: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    const auto operand=m.r32(address);
    s.fp.compare32(operand);
  }
  { // 0x4ba0a0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x4ba0a2: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  { // 0x4ba0a5: 7406 JZ 0x004ba0ad
    if(integer::condition("JZ",flags)) goto L004ba0ad;
  }
  { // 0x4ba0a7: dc0d78857800 FMUL double ptr [0x00788578]
    const auto address=(0x00788578u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  L004ba0ad: { // 0x4ba0ad: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x4ba0b1: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x4ba0b5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x4ba0b7: 81e1ffff7f00 AND ECX,0x7fffff
    s.cx = integer::logical((s.cx)&(0x007fffffu),32,flags);
  }
  { // 0x4ba0bd: c1e817 SHR EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::right);
  }
  { // 0x4ba0c0: 83e87f SUB EAX,0x7f
    s.ax = integer::sub(s.ax,0x0000007fu,32,flags);
  }
  { // 0x4ba0c3: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x4ba0c5: 7406 JZ 0x004ba0cd
    if(integer::condition("JZ",flags)) goto L004ba0cd;
  }
  { // 0x4ba0c7: 81c900008000 OR ECX,0x800000
    s.cx = integer::logical((s.cx)|(0x00800000u),32,flags);
  }
  L004ba0cd: { // 0x4ba0cd: 66d1f8 SAR AX,0x1
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),0x00000001u,16,flags,integer::Shift::arithmetic_right));
  }
  { // 0x4ba0d0: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  { // 0x4ba0d3: c1e90a SHR ECX,0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  { // 0x4ba0d6: 83c07f ADD EAX,0x7f
    s.ax = integer::add(s.ax,0x0000007fu,32,flags);
  }
  { // 0x4ba0d9: 8b0c8d3c018000 MOV ECX,dword ptr [ECX*0x4 + 0x80013c]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x0080013cu));
  }
  { // 0x4ba0e0: c1e017 SHL EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::left);
  }
  { // 0x4ba0e3: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x4ba0e5: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  { // 0x4ba0e9: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4ba0ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000cabb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4cabb0: 8b81c4040000 MOV EAX,dword ptr [ECX + 0x4c4]
    s.ax = m.r32((s.cx+0x000004c4u));
  }
  { // 0x4cabb6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4cabb8: 7414 JZ 0x004cabce
    if(integer::condition("JZ",flags)) goto L004cabce;
  }
  { // 0x4cabba: 8b4024 MOV EAX,dword ptr [EAX + 0x24]
    s.ax = m.r32((s.ax+0x00000024u));
  }
  { // 0x4cabbd: 8a90ea000000 MOV DL,byte ptr [EAX + 0xea]
    s.dx = with_al(s.dx, m.r8((s.ax+0x000000eau)));
  }
  { // 0x4cabc3: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x4cabc5: 7407 JZ 0x004cabce
    if(integer::condition("JZ",flags)) goto L004cabce;
  }
  { // 0x4cabc7: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4cabcd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004cabce: { // 0x4cabce: dd8128040000 FLD double ptr [ECX + 0x428]
    const auto address=(s.cx+0x00000428u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4cabd4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000e7870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4e7870: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x4e7873: 8b81d0520000 MOV EAX,dword ptr [ECX + 0x52d0]
    s.ax = m.r32((s.cx+0x000052d0u));
  }
  { // 0x4e7879: 8b89d4520000 MOV ECX,dword ptr [ECX + 0x52d4]
    s.cx = m.r32((s.cx+0x000052d4u));
  }
  { // 0x4e787f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4e7881: 89442400 MOV dword ptr [ESP],EAX
    m.w32((f.sp), s.ax);
  }
  { // 0x4e7885: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  { // 0x4e7889: 7d1e JGE 0x004e78a9
    if(integer::condition("JGE",flags)) goto L004e78a9;
  }
  { // 0x4e788b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4e788d: 741a JZ 0x004e78a9
    if(integer::condition("JZ",flags)) goto L004e78a9;
  }
  { // 0x4e788f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4e7891: 740c JZ 0x004e789f
    if(integer::condition("JZ",flags)) goto L004e789f;
  }
  { // 0x4e7893: db442400 FILD dword ptr [ESP]
    const auto address=(f.sp);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x4e7897: da742404 FIDIV dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.divide_integer32(operand);
  }
  { // 0x4e789b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4e789e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004e789f: { // 0x4e789f: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4e78a5: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4e78a8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004e78a9: { // 0x4e78a9: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4e78af: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4e78b2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0018ce90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58ce90: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58ce94: d84904 FMUL float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58ce97: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58ce9b: d84908 FMUL float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58ce9e: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58cea0: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58cea4: d809 FMUL float ptr [ECX]
    const auto address=(s.cx);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58cea6: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58cea8: d8410c FADD float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x58ceab: d9590c FSTP float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58ceae: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58ceb2: d84910 FMUL float ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58ceb5: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58ceb9: d84914 FMUL float ptr [ECX + 0x14]
    const auto address=(s.cx+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58cebc: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58cebe: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58cec2: d84918 FMUL float ptr [ECX + 0x18]
    const auto address=(s.cx+0x00000018u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58cec5: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58cec7: d8411c FADD float ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x58ceca: d9591c FSTP float ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58cecd: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58ced1: d84920 FMUL float ptr [ECX + 0x20]
    const auto address=(s.cx+0x00000020u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58ced4: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58ced8: d84924 FMUL float ptr [ECX + 0x24]
    const auto address=(s.cx+0x00000024u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58cedb: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58cedd: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58cee1: d84928 FMUL float ptr [ECX + 0x28]
    const auto address=(s.cx+0x00000028u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58cee4: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58cee6: d8412c FADD float ptr [ECX + 0x2c]
    const auto address=(s.cx+0x0000002cu);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x58cee9: d9592c FSTP float ptr [ECX + 0x2c]
    const auto address=(s.cx+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58ceec: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0018cf80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58cf80: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58cf84: d809 FMUL float ptr [ECX]
    const auto address=(s.cx);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58cf86: d8410c FADD float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x58cf89: d9590c FSTP float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58cf8c: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58cf90: d84910 FMUL float ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58cf93: d8411c FADD float ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x58cf96: d9591c FSTP float ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58cf99: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58cf9d: d84920 FMUL float ptr [ECX + 0x20]
    const auto address=(s.cx+0x00000020u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58cfa0: d8412c FADD float ptr [ECX + 0x2c]
    const auto address=(s.cx+0x0000002cu);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x58cfa3: d9592c FSTP float ptr [ECX + 0x2c]
    const auto address=(s.cx+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58cfa6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018cfb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58cfb0: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58cfb4: d84904 FMUL float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58cfb7: d8410c FADD float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x58cfba: d9590c FSTP float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58cfbd: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58cfc1: d84914 FMUL float ptr [ECX + 0x14]
    const auto address=(s.cx+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58cfc4: d8411c FADD float ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x58cfc7: d9591c FSTP float ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58cfca: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58cfce: d84924 FMUL float ptr [ECX + 0x24]
    const auto address=(s.cx+0x00000024u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58cfd1: d8412c FADD float ptr [ECX + 0x2c]
    const auto address=(s.cx+0x0000002cu);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x58cfd4: d9592c FSTP float ptr [ECX + 0x2c]
    const auto address=(s.cx+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58cfd7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018cfe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58cfe0: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58cfe4: d84908 FMUL float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58cfe7: d8410c FADD float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x58cfea: d9590c FSTP float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58cfed: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58cff1: d84918 FMUL float ptr [ECX + 0x18]
    const auto address=(s.cx+0x00000018u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58cff4: d8411c FADD float ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x58cff7: d9591c FSTP float ptr [ECX + 0x1c]
    const auto address=(s.cx+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58cffa: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58cffe: d84928 FMUL float ptr [ECX + 0x28]
    const auto address=(s.cx+0x00000028u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d001: d8412c FADD float ptr [ECX + 0x2c]
    const auto address=(s.cx+0x0000002cu);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x58d004: d9592c FSTP float ptr [ECX + 0x2c]
    const auto address=(s.cx+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d007: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018d010(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58d010: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d014: d809 FMUL float ptr [ECX]
    const auto address=(s.cx);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d016: d919 FSTP float ptr [ECX]
    const auto address=(s.cx);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d018: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d01c: d84910 FMUL float ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d01f: d95910 FSTP float ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d022: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d026: d84920 FMUL float ptr [ECX + 0x20]
    const auto address=(s.cx+0x00000020u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d029: d95920 FSTP float ptr [ECX + 0x20]
    const auto address=(s.cx+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d02c: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d030: d84904 FMUL float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d033: d95904 FSTP float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d036: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d03a: d84914 FMUL float ptr [ECX + 0x14]
    const auto address=(s.cx+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d03d: d95914 FSTP float ptr [ECX + 0x14]
    const auto address=(s.cx+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d040: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d044: d84924 FMUL float ptr [ECX + 0x24]
    const auto address=(s.cx+0x00000024u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d047: d95924 FSTP float ptr [ECX + 0x24]
    const auto address=(s.cx+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d04a: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d04e: d84908 FMUL float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d051: d95908 FSTP float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d054: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d058: d84918 FMUL float ptr [ECX + 0x18]
    const auto address=(s.cx+0x00000018u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d05b: d95918 FSTP float ptr [ECX + 0x18]
    const auto address=(s.cx+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d05e: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d062: d84928 FMUL float ptr [ECX + 0x28]
    const auto address=(s.cx+0x00000028u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d065: d95928 FSTP float ptr [ECX + 0x28]
    const auto address=(s.cx+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d068: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018d0d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58d0d0: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d0d4: d809 FMUL float ptr [ECX]
    const auto address=(s.cx);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d0d6: d919 FSTP float ptr [ECX]
    const auto address=(s.cx);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d0d8: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d0dc: d84910 FMUL float ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d0df: d95910 FSTP float ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d0e2: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d0e6: d84920 FMUL float ptr [ECX + 0x20]
    const auto address=(s.cx+0x00000020u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d0e9: d95920 FSTP float ptr [ECX + 0x20]
    const auto address=(s.cx+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d0ec: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018d0f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58d0f0: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d0f4: d84904 FMUL float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d0f7: d95904 FSTP float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d0fa: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d0fe: d84914 FMUL float ptr [ECX + 0x14]
    const auto address=(s.cx+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d101: d95914 FSTP float ptr [ECX + 0x14]
    const auto address=(s.cx+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d104: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d108: d84924 FMUL float ptr [ECX + 0x24]
    const auto address=(s.cx+0x00000024u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d10b: d95924 FSTP float ptr [ECX + 0x24]
    const auto address=(s.cx+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d10e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018d120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58d120: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d124: d84908 FMUL float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d127: d95908 FSTP float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d12a: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d12e: d84918 FMUL float ptr [ECX + 0x18]
    const auto address=(s.cx+0x00000018u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d131: d95918 FSTP float ptr [ECX + 0x18]
    const auto address=(s.cx+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d134: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d138: d84928 FMUL float ptr [ECX + 0x28]
    const auto address=(s.cx+0x00000028u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d13b: d95928 FSTP float ptr [ECX + 0x28]
    const auto address=(s.cx+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d13e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0018d600(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58d600: d94104 FLD float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d603: d94108 FLD float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d606: d9c0 FLD ST0
    s.fp.load_st0();
  }
  { // 0x58d608: d84c2404 FMUL float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d60c: d9c2 FLD ST2
    s.fp.load_st2();
  }
  { // 0x58d60e: d84c2408 FMUL float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d612: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58d614: d95904 FSTP float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d617: d84c2408 FMUL float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d61b: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x58d61d: d84c2404 FMUL float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d621: dee9 FSUBP
    s.fp.subtract_pop();
  }
  { // 0x58d623: d95908 FSTP float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d626: d94114 FLD float ptr [ECX + 0x14]
    const auto address=(s.cx+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d629: d94118 FLD float ptr [ECX + 0x18]
    const auto address=(s.cx+0x00000018u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d62c: d9c0 FLD ST0
    s.fp.load_st0();
  }
  { // 0x58d62e: d84c2404 FMUL float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d632: d9c2 FLD ST2
    s.fp.load_st2();
  }
  { // 0x58d634: d84c2408 FMUL float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d638: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58d63a: d95914 FSTP float ptr [ECX + 0x14]
    const auto address=(s.cx+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d63d: d84c2408 FMUL float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d641: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x58d643: d84c2404 FMUL float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d647: dee9 FSUBP
    s.fp.subtract_pop();
  }
  { // 0x58d649: d95918 FSTP float ptr [ECX + 0x18]
    const auto address=(s.cx+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d64c: d94124 FLD float ptr [ECX + 0x24]
    const auto address=(s.cx+0x00000024u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d64f: d94128 FLD float ptr [ECX + 0x28]
    const auto address=(s.cx+0x00000028u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58d652: d9c0 FLD ST0
    s.fp.load_st0();
  }
  { // 0x58d654: d84c2404 FMUL float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d658: d9c2 FLD ST2
    s.fp.load_st2();
  }
  { // 0x58d65a: d84c2408 FMUL float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d65e: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58d660: d95924 FSTP float ptr [ECX + 0x24]
    const auto address=(s.cx+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d663: d84c2408 FMUL float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d667: d9c9 FXCH
    s.fp.exchange_st1();
  }
  { // 0x58d669: d84c2404 FMUL float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58d66d: dee9 FSUBP
    s.fp.subtract_pop();
  }
  { // 0x58d66f: d95928 FSTP float ptr [ECX + 0x28]
    const auto address=(s.cx+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58d672: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0018dad0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58dad0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x58dad3: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x58dad7: d94104 FLD float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58dada: d84804 FMUL float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58dadd: d94108 FLD float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58dae0: d84808 FMUL float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58dae3: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58dae5: d900 FLD float ptr [EAX]
    const auto address=(s.ax);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58dae7: d809 FMUL float ptr [ECX]
    const auto address=(s.cx);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58dae9: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58daeb: d95c2400 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58daef: d94114 FLD float ptr [ECX + 0x14]
    const auto address=(s.cx+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58daf2: d84804 FMUL float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58daf5: d94110 FLD float ptr [ECX + 0x10]
    const auto address=(s.cx+0x00000010u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58daf8: d808 FMUL float ptr [EAX]
    const auto address=(s.ax);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58dafa: 8b542400 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  { // 0x58dafe: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58db00: d94118 FLD float ptr [ECX + 0x18]
    const auto address=(s.cx+0x00000018u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58db03: d84808 FMUL float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58db06: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58db08: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58db0c: d94124 FLD float ptr [ECX + 0x24]
    const auto address=(s.cx+0x00000024u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58db0f: d84804 FMUL float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58db12: d94120 FLD float ptr [ECX + 0x20]
    const auto address=(s.cx+0x00000020u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58db15: d808 FMUL float ptr [EAX]
    const auto address=(s.ax);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58db17: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58db19: d94128 FLD float ptr [ECX + 0x28]
    const auto address=(s.cx+0x00000028u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58db1c: d84808 FMUL float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58db1f: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x58db23: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x58db25: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58db27: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  { // 0x58db29: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x58db2d: d95c2408 FSTP float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58db31: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  { // 0x58db34: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x58db38: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  { // 0x58db3b: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x58db3e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0018e180(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58e180: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x58e183: d94208 FLD float ptr [EDX + 0x8]
    const auto address=(s.dx+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58e186: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x58e187: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  { // 0x58e18b: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58e18e: d94204 FLD float ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58e191: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58e194: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x58e196: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58e198: d902 FLD float ptr [EDX]
    const auto address=(s.dx);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58e19a: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58e19c: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58e19e: d8420c FADD float ptr [EDX + 0xc]
    const auto address=(s.dx+0x0000000cu);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x58e1a1: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58e1a5: d94210 FLD float ptr [EDX + 0x10]
    const auto address=(s.dx+0x00000010u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58e1a8: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58e1aa: d94218 FLD float ptr [EDX + 0x18]
    const auto address=(s.dx+0x00000018u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58e1ad: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58e1b0: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58e1b2: d94214 FLD float ptr [EDX + 0x14]
    const auto address=(s.dx+0x00000014u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58e1b5: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58e1b8: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58e1ba: d8421c FADD float ptr [EDX + 0x1c]
    const auto address=(s.dx+0x0000001cu);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x58e1bd: d95c2408 FSTP float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x58e1c1: d94220 FLD float ptr [EDX + 0x20]
    const auto address=(s.dx+0x00000020u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58e1c4: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58e1c6: d94228 FLD float ptr [EDX + 0x28]
    const auto address=(s.dx+0x00000028u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58e1c9: d84e08 FMUL float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58e1cc: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58e1ce: d94224 FLD float ptr [EDX + 0x24]
    const auto address=(s.dx+0x00000024u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x58e1d1: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x58e1d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x58e1d5: dec1 FADDP
    s.fp.add_pop();
  }
  { // 0x58e1d7: d8422c FADD float ptr [EDX + 0x2c]
    const auto address=(s.dx+0x0000002cu);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
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
void f_001f5e10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f5e10: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  { // 0x5f5e13: d905f8677800 FLD float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x5f5e19: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f5e1a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f5e1b: c744240c2b000000 MOV dword ptr [ESP + 0xc],0x2b
    m.w32((f.sp+0x0000000cu), 0x0000002bu);
  }
  { // 0x5f5e23: c744241080000000 MOV dword ptr [ESP + 0x10],0x80
    m.w32((f.sp+0x00000010u), 0x00000080u);
  }
  { // 0x5f5e2b: c7442414d5000000 MOV dword ptr [ESP + 0x14],0xd5
    m.w32((f.sp+0x00000014u), 0x000000d5u);
  }
  { // 0x5f5e33: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x5f5e37: be03000000 MOV ESI,0x3
    s.si = 0x00000003u;
  }
  L005f5e3c: { // 0x5f5e3c: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  { // 0x5f5e3e: 8d78f0 LEA EDI,[EAX + -0x10]
    s.di = (s.ax-0x00000010u);
  }
  { // 0x5f5e41: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  { // 0x5f5e43: 7e12 JLE 0x005f5e57
    if(integer::condition("JLE",flags)) goto L005f5e57;
  }
  { // 0x5f5e45: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x5f5e47: 7f12 JG 0x005f5e5b
    if(integer::condition("JG",flags)) goto L005f5e5b;
  }
  { // 0x5f5e49: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5f5e4b: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x5f5e4d: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  { // 0x5f5e51: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x5f5e55: eb19 JMP 0x005f5e70
    goto L005f5e70;
  }
  L005f5e57: { // 0x5f5e57: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x5f5e59: 7e27 JLE 0x005f5e82
    if(integer::condition("JLE",flags)) goto L005f5e82;
  }
  L005f5e5b: { // 0x5f5e5b: 8d7810 LEA EDI,[EAX + 0x10]
    s.di = (s.ax+0x00000010u);
  }
  { // 0x5f5e5e: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  { // 0x5f5e60: 7f20 JG 0x005f5e82
    if(integer::condition("JG",flags)) goto L005f5e82;
  }
  { // 0x5f5e62: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x5f5e64: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x5f5e66: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x5f5e68: 897c2408 MOV dword ptr [ESP + 0x8],EDI
    m.w32((f.sp+0x00000008u), s.di);
  }
  { // 0x5f5e6c: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  L005f5e70: { // 0x5f5e70: d80de02a7900 FMUL float ptr [0x00792ae0]
    const auto address=(0x00792ae0u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x5f5e76: d80ddc2a7900 FMUL float ptr [0x00792adc]
    const auto address=(0x00792adcu);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x5f5e7c: d805d82a7900 FADD float ptr [0x00792ad8]
    const auto address=(0x00792ad8u);
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  L005f5e82: { // 0x5f5e82: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  { // 0x5f5e85: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  { // 0x5f5e86: 75b4 JNZ 0x005f5e3c
    if(integer::condition("JNZ",flags)) goto L005f5e3c;
  }
  { // 0x5f5e88: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f5e89: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f5e8a: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x5f5e8d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00217460(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x617460: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x617461: 0fbe5161 MOVSX EDX,byte ptr [ECX + 0x61]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x00000061u)),8));
  }
  { // 0x617465: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x61746b: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x61746d: 89542400 MOV dword ptr [ESP],EDX
    m.w32((f.sp), s.dx);
  }
  { // 0x617471: 7e0b JLE 0x0061747e
    if(integer::condition("JLE",flags)) goto L0061747e;
  }
  { // 0x617473: 8d4108 LEA EAX,[ECX + 0x8]
    s.ax = (s.cx+0x00000008u);
  }
  L00617476: { // 0x617476: dc00 FADD double ptr [EAX]
    const auto address=(s.ax);
    const auto operand=read64(m,address);
    s.fp.add64(operand);
  }
  { // 0x617478: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  { // 0x61747b: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x61747c: 75f8 JNZ 0x00617476
    if(integer::condition("JNZ",flags)) goto L00617476;
  }
  L0061747e: { // 0x61747e: da742400 FIDIV dword ptr [ESP]
    const auto address=(f.sp);
    const auto operand=m.r32(address);
    s.fp.divide_integer32(operand);
  }
  { // 0x617482: dc7148 FDIV double ptr [ECX + 0x48]
    const auto address=(s.cx+0x00000048u);
    const auto operand=read64(m,address);
    s.fp.divide64(operand);
  }
  { // 0x617485: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x617486: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00219d90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x619d90: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x619d94: d809 FMUL float ptr [ECX]
    const auto address=(s.cx);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x619d96: d919 FSTP float ptr [ECX]
    const auto address=(s.cx);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x619d98: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x619d9c: d84904 FMUL float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x619d9f: d95904 FSTP float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x619da2: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x619da6: d84908 FMUL float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x619da9: d95908 FSTP float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x619dac: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x619db0: d8490c FMUL float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    const auto operand=m.r32(address);
    s.fp.multiply32(operand);
  }
  { // 0x619db3: d9590c FSTP float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x619db6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00219de0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x619de0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x619de4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x619de5: d900 FLD float ptr [EAX]
    const auto address=(s.ax);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x619de7: d919 FSTP float ptr [ECX]
    const auto address=(s.cx);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x619de9: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x619dec: d95904 FSTP float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x619def: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x619df2: d95908 FSTP float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x619df5: d9400c FLD float ptr [EAX + 0xc]
    const auto address=(s.ax+0x0000000cu);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x619df8: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x619dfc: d9590c FSTP float ptr [ECX + 0xc]
    const auto address=(s.cx+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  { // 0x619dff: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  { // 0x619e01: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x619e03: 8932 MOV dword ptr [EDX],ESI
    m.w32((s.dx), s.si);
  }
  { // 0x619e05: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  { // 0x619e08: 897204 MOV dword ptr [EDX + 0x4],ESI
    m.w32((s.dx+0x00000004u), s.si);
  }
  { // 0x619e0b: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  { // 0x619e0e: 897208 MOV dword ptr [EDX + 0x8],ESI
    m.w32((s.dx+0x00000008u), s.si);
  }
  { // 0x619e11: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  { // 0x619e14: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x619e15: 894a0c MOV dword ptr [EDX + 0xc],ECX
    m.w32((s.dx+0x0000000cu), s.cx);
  }
  { // 0x619e18: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_002904e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6904e0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x6904e4: d90481 FLD float ptr [ECX + EAX*0x4]
    const auto address=(s.cx+(s.ax * 0x00000004u));
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x6904e7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002904f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6904f0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x6904f4: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x6904f8: d80481 FADD float ptr [ECX + EAX*0x4]
    const auto address=(s.cx+(s.ax * 0x00000004u));
    const auto operand=m.r32(address);
    s.fp.add32(operand);
  }
  { // 0x6904fb: d91481 FST float ptr [ECX + EAX*0x4]
    const auto address=(s.cx+(s.ax * 0x00000004u));
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  { // 0x6904fe: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
const std::array<Entry,31>& entries_a() {
  static const std::array<Entry,31> entries{{
    {0x5120u,f_00005120},
    {0x1b7f0u,f_0001b7f0},
    {0x1b860u,f_0001b860},
    {0x37530u,f_00037530},
    {0x37560u,f_00037560},
    {0x63ed0u,f_00063ed0},
    {0x7caa0u,f_0007caa0},
    {0x7cac0u,f_0007cac0},
    {0x7f8f0u,f_0007f8f0},
    {0x968b0u,f_000968b0},
    {0x96a50u,f_00096a50},
    {0xba080u,f_000ba080},
    {0xcabb0u,f_000cabb0},
    {0xe7870u,f_000e7870},
    {0x18ce90u,f_0018ce90},
    {0x18cf80u,f_0018cf80},
    {0x18cfb0u,f_0018cfb0},
    {0x18cfe0u,f_0018cfe0},
    {0x18d010u,f_0018d010},
    {0x18d0d0u,f_0018d0d0},
    {0x18d0f0u,f_0018d0f0},
    {0x18d120u,f_0018d120},
    {0x18d600u,f_0018d600},
    {0x18dad0u,f_0018dad0},
    {0x18e180u,f_0018e180},
    {0x1f5e10u,f_001f5e10},
    {0x217460u,f_00217460},
    {0x219d90u,f_00219d90},
    {0x219de0u,f_00219de0},
    {0x2904e0u,f_002904e0},
    {0x2904f0u,f_002904f0},
  }}; return entries;
}
} // namespace ra2::recovered::floating_b39
