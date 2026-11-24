#include "recovered/recovery_b509_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::matrix509 {
namespace {
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_000ba270(Memory&,State&,Frame&,const Operations&);
void f_000ba0f0(Memory&,State&,Frame&,const Operations&);
void f_000ba140(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000ba080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba080: { // 0x4ba080: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  L004ba084: { // 0x4ba084: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba08a: { // 0x4ba08a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba08c: { // 0x4ba08c: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004ba08f: { // 0x4ba08f: 7409 JZ 0x004ba09a
    if(integer::condition("JZ",flags)) goto L004ba09a;
  }
  L004ba091: { // 0x4ba091: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004ba093: { // 0x4ba093: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L004ba099: { // 0x4ba099: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba09a: { // 0x4ba09a: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba0a0: { // 0x4ba0a0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba0a2: { // 0x4ba0a2: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004ba0a5: { // 0x4ba0a5: 7406 JZ 0x004ba0ad
    if(integer::condition("JZ",flags)) goto L004ba0ad;
  }
  L004ba0a7: { // 0x4ba0a7: dc0d78857800 FMUL double ptr [0x00788578]
    const auto address=(0x00788578u);
    s.fp.multiply64(read64(m,address));
  }
  L004ba0ad: { // 0x4ba0ad: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004ba0b1: { // 0x4ba0b1: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L004ba0b5: { // 0x4ba0b5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004ba0b7: { // 0x4ba0b7: 81e1ffff7f00 AND ECX,0x7fffff
    s.cx = integer::logical((s.cx)&(0x007fffffu),32,flags);
  }
  L004ba0bd: { // 0x4ba0bd: c1e817 SHR EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::right);
  }
  L004ba0c0: { // 0x4ba0c0: 83e87f SUB EAX,0x7f
    s.ax = integer::sub(s.ax,0x0000007fu,32,flags);
  }
  L004ba0c3: { // 0x4ba0c3: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L004ba0c5: { // 0x4ba0c5: 7406 JZ 0x004ba0cd
    if(integer::condition("JZ",flags)) goto L004ba0cd;
  }
  L004ba0c7: { // 0x4ba0c7: 81c900008000 OR ECX,0x800000
    s.cx = integer::logical((s.cx)|(0x00800000u),32,flags);
  }
  L004ba0cd: { // 0x4ba0cd: 66d1f8 SAR AX,0x1
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),0x00000001u,16,flags,integer::Shift::arithmetic_right));
  }
  L004ba0d0: { // 0x4ba0d0: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004ba0d3: { // 0x4ba0d3: c1e90a SHR ECX,0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  L004ba0d6: { // 0x4ba0d6: 83c07f ADD EAX,0x7f
    s.ax = integer::add(s.ax,0x0000007fu,32,flags);
  }
  L004ba0d9: { // 0x4ba0d9: 8b0c8d3c018000 MOV ECX,dword ptr [ECX*0x4 + 0x80013c]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x0080013cu));
  }
  L004ba0e0: { // 0x4ba0e0: c1e017 SHL EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::left);
  }
  L004ba0e3: { // 0x4ba0e3: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004ba0e5: { // 0x4ba0e5: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L004ba0e9: { // 0x4ba0e9: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L004ba0ed: { // 0x4ba0ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ba270(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba270: { // 0x4ba270: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ba271: { // 0x4ba271: dd442410 FLD double ptr [ESP+0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L004ba275: { // 0x4ba275: d95c2400 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004ba279: { // 0x4ba279: dd442408 FLD double ptr [ESP+8]
    const auto address=(f.sp+8u);
    s.fp.load64(read64(m,address));
  }
  L004ba27d: { // 0x4ba27d: d95c2410 FSTP float ptr [ESP+0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004ba281: { // 0x4ba281: d9442400 FLD float ptr [ESP]
    const auto address=(f.sp);
    s.fp.load32(m.r32(address));
  }
  L004ba285: { // 0x4ba285: d81d38577800 FCOMP float ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L004ba28b: { // 0x4ba28b: d9442410 FLD float ptr [ESP+0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L004ba28f: { // 0x4ba28f: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba291: { // 0x4ba291: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004ba294: { // 0x4ba294: 7436 JZ 0x4ba2cc
    if(integer::condition("JZ",flags)) goto L004ba2cc;
  }
  L004ba296: { // 0x4ba296: d81d38577800 FCOMP float ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L004ba29c: { // 0x4ba29c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba29e: { // 0x4ba29e: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004ba2a1: { // 0x4ba2a1: 7408 JZ 0x4ba2ab
    if(integer::condition("JZ",flags)) goto L004ba2ab;
  }
  L004ba2a3: { // 0x4ba2a3: d90538577800 FLD float ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L004ba2a9: { // 0x4ba2a9: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004ba2aa: { // 0x4ba2aa: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba2ab: { // 0x4ba2ab: d9442410 FLD float ptr [ESP+0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L004ba2af: { // 0x4ba2af: d81d38577800 FCOMP float ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L004ba2b5: { // 0x4ba2b5: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba2b7: { // 0x4ba2b7: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004ba2ba: { // 0x4ba2ba: 7508 JNZ 0x4ba2c4
    if(integer::condition("JNZ",flags)) goto L004ba2c4;
  }
  L004ba2bc: { // 0x4ba2bc: d9058cbf7800 FLD float ptr [0x78bf8c]
    const auto address=(0x0078bf8cu);
    s.fp.load32(m.r32(address));
  }
  L004ba2c2: { // 0x4ba2c2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004ba2c3: { // 0x4ba2c3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba2c4: { // 0x4ba2c4: d90590bf7800 FLD float ptr [0x78bf90]
    const auto address=(0x0078bf90u);
    s.fp.load32(m.r32(address));
  }
  L004ba2ca: { // 0x4ba2ca: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004ba2cb: { // 0x4ba2cb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba2cc: { // 0x4ba2cc: d8742400 FDIV float ptr [ESP]
    const auto address=(f.sp);
    floating_b61::fp_extended::divide32(s.fp,m.r32(address));
  }
  L004ba2d0: { // 0x4ba2d0: d83538018000 FDIV float ptr [0x800138]
    const auto address=(0x00800138u);
    floating_b61::fp_extended::divide32(s.fp,m.r32(address));
  }
  L004ba2d6: { // 0x4ba2d6: e875072b00 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4956891u); flags=s.arithmetic_flags;
  }
  L004ba2db: { // 0x4ba2db: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004ba2dc: { // 0x4ba2dc: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004ba2de: { // 0x4ba2de: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004ba2e0: { // 0x4ba2e0: 3d01100000 CMP EAX,0x1001
    (void)integer::sub(s.ax,0x00001001u,32,flags);
  }
  L004ba2e5: { // 0x4ba2e5: 7d09 JGE 0x4ba2f0
    if(integer::condition("JGE",flags)) goto L004ba2f0;
  }
  L004ba2e7: { // 0x4ba2e7: d9048534c17f00 FLD float ptr [EAX*4+0x7fc134]
    const auto address=((s.ax * 4u)+0x007fc134u);
    s.fp.load32(m.r32(address));
  }
  L004ba2ee: { // 0x4ba2ee: eb06 JMP 0x4ba2f6
    goto L004ba2f6;
  }
  L004ba2f0: { // 0x4ba2f0: d9058cbf7800 FLD float ptr [0x78bf8c]
    const auto address=(0x0078bf8cu);
    s.fp.load32(m.r32(address));
  }
  L004ba2f6: { // 0x4ba2f6: d9442400 FLD float ptr [ESP]
    const auto address=(f.sp);
    s.fp.load32(m.r32(address));
  }
  L004ba2fa: { // 0x4ba2fa: d81d38577800 FCOMP float ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L004ba300: { // 0x4ba300: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba302: { // 0x4ba302: f6c401 TEST AH,1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L004ba305: { // 0x4ba305: 7406 JZ 0x4ba30d
    if(integer::condition("JZ",flags)) goto L004ba30d;
  }
  L004ba307: { // 0x4ba307: dc2d58817800 FSUBR double ptr [0x788158]
    const auto address=(0x00788158u);
    s.fp.reverse_subtract64(read64(m,address));
  }
  L004ba30d: { // 0x4ba30d: d9442410 FLD float ptr [ESP+0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L004ba311: { // 0x4ba311: d81d38577800 FCOMP float ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L004ba317: { // 0x4ba317: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba319: { // 0x4ba319: f6c401 TEST AH,1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L004ba31c: { // 0x4ba31c: 7402 JZ 0x4ba320
    if(integer::condition("JZ",flags)) goto L004ba320;
  }
  L004ba31e: { // 0x4ba31e: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L004ba320: { // 0x4ba320: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004ba321: { // 0x4ba321: c3 RET
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
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4956288u:f_000ba080(m,s,child,{});break;
case 4956784u:f_000ba270(m,s,child,{});break;
case 4956400u:f_000ba0f0(m,s,child,{});break;
case 4956480u:f_000ba140(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery223 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0058dd10(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058dd10: { // 0x58dd10: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0058dd11: { // 0x58dd11: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0058dd13: { // 0x58dd13: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L0058dd16: { // 0x58dd16: 83ec54 SUB ESP,0x54
    f.sp = integer::sub(f.sp,0x00000054u,32,flags);
  }
  L0058dd19: { // 0x58dd19: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L0058dd1c: { // 0x58dd1c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058dd1d: { // 0x58dd1d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058dd1e: { // 0x58dd1e: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0058dd20: { // 0x58dd20: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L0058dd23: { // 0x58dd23: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058dd24: { // 0x58dd24: d900 FLD float ptr [EAX]
    const auto address=(s.ax);
    s.fp.load32(m.r32(address));
  }
  L0058dd26: { // 0x58dd26: d821 FSUB float ptr [ECX]
    const auto address=(s.cx);
    s.fp.subtract32(m.r32(address));
  }
  L0058dd28: { // 0x58dd28: d95c2448 FSTP float ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058dd2c: { // 0x58dd2c: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058dd2f: { // 0x58dd2f: d86104 FSUB float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    s.fp.subtract32(m.r32(address));
  }
  L0058dd32: { // 0x58dd32: d95c244c FSTP float ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058dd36: { // 0x58dd36: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0058dd39: { // 0x58dd39: d86108 FSUB float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    s.fp.subtract32(m.r32(address));
  }
  L0058dd3c: { // 0x58dd3c: d95c2450 FSTP float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058dd40: { // 0x58dd40: d944244c FLD float ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    s.fp.load32(m.r32(address));
  }
  L0058dd44: { // 0x58dd44: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L0058dd4a: { // 0x58dd4a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058dd4c: { // 0x58dd4c: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0058dd4f: { // 0x58dd4f: 741b JZ 0x0058dd6c
    if(integer::condition("JZ",flags)) goto L0058dd6c;
  }
  L0058dd51: { // 0x58dd51: d9442448 FLD float ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load32(m.r32(address));
  }
  L0058dd55: { // 0x58dd55: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  L0058dd5b: { // 0x58dd5b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058dd5d: { // 0x58dd5d: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0058dd60: { // 0x58dd60: 740a JZ 0x0058dd6c
    if(integer::condition("JZ",flags)) goto L0058dd6c;
  }
  L0058dd62: { // 0x58dd62: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L0058dd6a: { // 0x58dd6a: eb20 JMP 0x0058dd8c
    goto L0058dd8c;
  }
  L0058dd6c: { // 0x58dd6c: d9442448 FLD float ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load32(m.r32(address));
  }
  L0058dd70: { // 0x58dd70: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0058dd73: { // 0x58dd73: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058dd76: { // 0x58dd76: d9442454 FLD float ptr [ESP + 0x54]
    const auto address=(f.sp+0x00000054u);
    s.fp.load32(m.r32(address));
  }
  L0058dd7a: { // 0x58dd7a: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0058dd7d: { // 0x58dd7d: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058dd80: { // 0x58dd80: e8ebc4f2ff CALL 0x004ba270
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba270u,5823877u); flags=s.arithmetic_flags;
  }
  L0058dd85: { // 0x58dd85: d95c2420 FSTP float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058dd89: { // 0x58dd89: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0058dd8c: { // 0x58dd8c: d944244c FLD float ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    s.fp.load32(m.r32(address));
  }
  L0058dd90: { // 0x58dd90: d84c244c FMUL float ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    s.fp.multiply32(m.r32(address));
  }
  L0058dd94: { // 0x58dd94: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0058dd97: { // 0x58dd97: d95c2438 FSTP float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058dd9b: { // 0x58dd9b: d9442450 FLD float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.load32(m.r32(address));
  }
  L0058dd9f: { // 0x58dd9f: d84c2450 FMUL float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.multiply32(m.r32(address));
  }
  L0058dda3: { // 0x58dda3: d9542434 FST float ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  L0058dda7: { // 0x58dda7: d8442438 FADD float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.add32(m.r32(address));
  }
  L0058ddab: { // 0x58ddab: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058ddae: { // 0x58ddae: e8cdc2f2ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5823923u); flags=s.arithmetic_flags;
  }
  L0058ddb3: { // 0x58ddb3: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058ddb6: { // 0x58ddb6: d9442458 FLD float ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.load32(m.r32(address));
  }
  L0058ddba: { // 0x58ddba: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0058ddbd: { // 0x58ddbd: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L0058ddbf: { // 0x58ddbf: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058ddc2: { // 0x58ddc2: e8a9c4f2ff CALL 0x004ba270
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba270u,5823943u); flags=s.arithmetic_flags;
  }
  L0058ddc7: { // 0x58ddc7: d95c2428 FSTP float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058ddcb: { // 0x58ddcb: d9442420 FLD float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L0058ddcf: { // 0x58ddcf: dd5c2448 FSTP double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058ddd3: { // 0x58ddd3: 8b7c244c MOV EDI,dword ptr [ESP + 0x4c]
    s.di = m.r32((f.sp+0x0000004cu));
  }
  L0058ddd7: { // 0x58ddd7: 8b5c2448 MOV EBX,dword ptr [ESP + 0x48]
    s.bx = m.r32((f.sp+0x00000048u));
  }
  L0058dddb: { // 0x58dddb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058dddc: { // 0x58dddc: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058dddd: { // 0x58dddd: e85ec3f2ff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,5823970u); flags=s.arithmetic_flags;
  }
  L0058dde2: { // 0x58dde2: d95c242c FSTP float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058dde6: { // 0x58dde6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058dde7: { // 0x58dde7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058dde8: { // 0x58dde8: e803c3f2ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,5823981u); flags=s.arithmetic_flags;
  }
  L0058dded: { // 0x58dded: d95c2430 FSTP float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058ddf1: { // 0x58ddf1: d9442438 FLD float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load32(m.r32(address));
  }
  L0058ddf5: { // 0x58ddf5: dd5c2458 FSTP double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058ddf9: { // 0x58ddf9: 8b7c245c MOV EDI,dword ptr [ESP + 0x5c]
    s.di = m.r32((f.sp+0x0000005cu));
  }
  L0058ddfd: { // 0x58ddfd: 8b5c2458 MOV EBX,dword ptr [ESP + 0x58]
    s.bx = m.r32((f.sp+0x00000058u));
  }
  L0058de01: { // 0x58de01: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058de02: { // 0x58de02: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058de03: { // 0x58de03: e838c3f2ff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,5824008u); flags=s.arithmetic_flags;
  }
  L0058de08: { // 0x58de08: d95c2460 FSTP float ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058de0c: { // 0x58de0c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058de0d: { // 0x58de0d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058de0e: { // 0x58de0e: e8ddc2f2ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,5824019u); flags=s.arithmetic_flags;
  }
  L0058de13: { // 0x58de13: d95c2464 FSTP float ptr [ESP + 0x64]
    const auto address=(f.sp+0x00000064u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058de17: { // 0x58de17: d94510 FLD float ptr [EBP + 0x10]
    const auto address=(s.bp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L0058de1a: { // 0x58de1a: dd5c2448 FSTP double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058de1e: { // 0x58de1e: 8b7c244c MOV EDI,dword ptr [ESP + 0x4c]
    s.di = m.r32((f.sp+0x0000004cu));
  }
  L0058de22: { // 0x58de22: 8b5c2448 MOV EBX,dword ptr [ESP + 0x48]
    s.bx = m.r32((f.sp+0x00000048u));
  }
  L0058de26: { // 0x58de26: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058de27: { // 0x58de27: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058de28: { // 0x58de28: e813c3f2ff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,5824045u); flags=s.arithmetic_flags;
  }
  L0058de2d: { // 0x58de2d: d95c2450 FSTP float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058de31: { // 0x58de31: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058de32: { // 0x58de32: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058de33: { // 0x58de33: e8b8c2f2ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,5824056u); flags=s.arithmetic_flags;
  }
  L0058de38: { // 0x58de38: d9442458 FLD float ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.load32(m.r32(address));
  }
  L0058de3c: { // 0x58de3c: d84c2474 FMUL float ptr [ESP + 0x74]
    const auto address=(f.sp+0x00000074u);
    s.fp.multiply32(m.r32(address));
  }
  L0058de40: { // 0x58de40: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L0058de43: { // 0x58de43: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0058de46: { // 0x58de46: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0058de48: { // 0x58de48: d84c241c FMUL float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.multiply32(m.r32(address));
  }
  L0058de4c: { // 0x58de4c: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0058de4e: { // 0x58de4e: d84c2418 FMUL float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply32(m.r32(address));
  }
  L0058de52: { // 0x58de52: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0058de54: { // 0x58de54: d95c245c FSTP float ptr [ESP + 0x5c]
    const auto address=(f.sp+0x0000005cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058de58: { // 0x58de58: d84c2418 FMUL float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply32(m.r32(address));
  }
  L0058de5c: { // 0x58de5c: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0058de5e: { // 0x58de5e: d84c241c FMUL float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.multiply32(m.r32(address));
  }
  L0058de62: { // 0x58de62: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0058de64: { // 0x58de64: d95c2460 FSTP float ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058de68: { // 0x58de68: d9442420 FLD float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L0058de6c: { // 0x58de6c: d84c2440 FMUL float ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.multiply32(m.r32(address));
  }
  L0058de70: { // 0x58de70: d95c2464 FSTP float ptr [ESP + 0x64]
    const auto address=(f.sp+0x00000064u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058de74: { // 0x58de74: d9442458 FLD float ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.load32(m.r32(address));
  }
  L0058de78: { // 0x58de78: d84c2458 FMUL float ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.multiply32(m.r32(address));
  }
  L0058de7c: { // 0x58de7c: d8442434 FADD float ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    s.fp.add32(m.r32(address));
  }
  L0058de80: { // 0x58de80: d8442438 FADD float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.add32(m.r32(address));
  }
  L0058de84: { // 0x58de84: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058de87: { // 0x58de87: e8f4c1f2ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5824140u); flags=s.arithmetic_flags;
  }
  L0058de8c: { // 0x58de8c: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0058de92: { // 0x58de92: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0058de95: { // 0x58de95: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058de97: { // 0x58de97: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0058de9a: { // 0x58de9a: 7532 JNZ 0x0058dece
    if(integer::condition("JNZ",flags)) goto L0058dece;
  }
  L0058de9c: { // 0x58de9c: d9442448 FLD float ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load32(m.r32(address));
  }
  L0058dea0: { // 0x58dea0: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L0058dea2: { // 0x58dea2: d95c2418 FSTP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058dea6: { // 0x58dea6: d944244c FLD float ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    s.fp.load32(m.r32(address));
  }
  L0058deaa: { // 0x58deaa: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L0058deac: { // 0x58deac: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0058deb0: { // 0x58deb0: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L0058deb4: { // 0x58deb4: d95c241c FSTP float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058deb8: { // 0x58deb8: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0058debc: { // 0x58debc: d87c2450 FDIVR float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    reverse_divide32(s.fp,m.r32(address));
  }
  L0058dec0: { // 0x58dec0: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L0058dec4: { // 0x58dec4: d95c2420 FSTP float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058dec8: { // 0x58dec8: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0058decc: { // 0x58decc: eb16 JMP 0x0058dee4
    goto L0058dee4;
  }
  L0058dece: { // 0x58dece: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L0058ded2: { // 0x58ded2: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0058ded6: { // 0x58ded6: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L0058deda: { // 0x58deda: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L0058dede: { // 0x58dede: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0058dee0: { // 0x58dee0: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L0058dee4: { // 0x58dee4: d944243c FLD float ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    s.fp.load32(m.r32(address));
  }
  L0058dee8: { // 0x58dee8: d84c245c FMUL float ptr [ESP + 0x5c]
    const auto address=(f.sp+0x0000005cu);
    s.fp.multiply32(m.r32(address));
  }
  L0058deec: { // 0x58deec: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L0058def0: { // 0x58def0: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L0058def4: { // 0x58def4: d9442440 FLD float ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load32(m.r32(address));
  }
  L0058def8: { // 0x58def8: d84c2458 FMUL float ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.multiply32(m.r32(address));
  }
  L0058defc: { // 0x58defc: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L0058df00: { // 0x58df00: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0058df03: { // 0x58df03: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0058df06: { // 0x58df06: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L0058df09: { // 0x58df09: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0058df0b: { // 0x58df0b: d9442440 FLD float ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load32(m.r32(address));
  }
  L0058df0f: { // 0x58df0f: d84c2454 FMUL float ptr [ESP + 0x54]
    const auto address=(f.sp+0x00000054u);
    s.fp.multiply32(m.r32(address));
  }
  L0058df13: { // 0x58df13: d9442438 FLD float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load32(m.r32(address));
  }
  L0058df17: { // 0x58df17: d84c245c FMUL float ptr [ESP + 0x5c]
    const auto address=(f.sp+0x0000005cu);
    s.fp.multiply32(m.r32(address));
  }
  L0058df1b: { // 0x58df1b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058df1c: { // 0x58df1c: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0058df1e: { // 0x58df1e: d95c2448 FSTP float ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058df22: { // 0x58df22: d9442434 FLD float ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    s.fp.load32(m.r32(address));
  }
  L0058df26: { // 0x58df26: d84c2454 FMUL float ptr [ESP + 0x54]
    const auto address=(f.sp+0x00000054u);
    s.fp.multiply32(m.r32(address));
  }
  L0058df2a: { // 0x58df2a: d9442438 FLD float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load32(m.r32(address));
  }
  L0058df2e: { // 0x58df2e: d84c2450 FMUL float ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.multiply32(m.r32(address));
  }
  L0058df32: { // 0x58df32: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L0058df36: { // 0x58df36: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L0058df38: { // 0x58df38: d95c244c FSTP float ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058df3c: { // 0x58df3c: d91e FSTP float ptr [ESI]
    const auto address=(s.si);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0058df3e: { // 0x58df3e: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0058df40: { // 0x58df40: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L0058df43: { // 0x58df43: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L0058df47: { // 0x58df47: 89560c MOV dword ptr [ESI + 0xc],EDX
    m.w32((s.si+0x0000000cu), s.dx);
  }
  L0058df4a: { // 0x58df4a: 8b542454 MOV EDX,dword ptr [ESP + 0x54]
    s.dx = m.r32((f.sp+0x00000054u));
  }
  L0058df4e: { // 0x58df4e: 894e18 MOV dword ptr [ESI + 0x18],ECX
    m.w32((s.si+0x00000018u), s.cx);
  }
  L0058df51: { // 0x58df51: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0058df55: { // 0x58df55: 895614 MOV dword ptr [ESI + 0x14],EDX
    m.w32((s.si+0x00000014u), s.dx);
  }
  L0058df58: { // 0x58df58: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0058df5b: { // 0x58df5b: 894e20 MOV dword ptr [ESI + 0x20],ECX
    m.w32((s.si+0x00000020u), s.cx);
  }
  L0058df5e: { // 0x58df5e: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L0058df62: { // 0x58df62: 89561c MOV dword ptr [ESI + 0x1c],EDX
    m.w32((s.si+0x0000001cu), s.dx);
  }
  L0058df65: { // 0x58df65: 8b542458 MOV EDX,dword ptr [ESP + 0x58]
    s.dx = m.r32((f.sp+0x00000058u));
  }
  L0058df69: { // 0x58df69: 894e28 MOV dword ptr [ESI + 0x28],ECX
    m.w32((s.si+0x00000028u), s.cx);
  }
  L0058df6c: { // 0x58df6c: 895624 MOV dword ptr [ESI + 0x24],EDX
    m.w32((s.si+0x00000024u), s.dx);
  }
  L0058df6f: { // 0x58df6f: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L0058df72: { // 0x58df72: 89562c MOV dword ptr [ESI + 0x2c],EDX
    m.w32((s.si+0x0000002cu), s.dx);
  }
  L0058df75: { // 0x58df75: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058df76: { // 0x58df76: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0058df77: { // 0x58df77: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0058df79: { // 0x58df79: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0058df7a: { // 0x58df7a: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
